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
  return atexit(dynamic_atexit_destructor_for__UFG::PhysicsCar::attachment_bones__);
}

// File Line: 268
// RVA: 0x44E150
void __fastcall UFG::VehicleAttachment::VehicleAttachment(UFG::VehicleAttachment *this, UFG::VehicleAttachmentID a)
{
  __int64 v2; // rsi
  UFG::VehicleAttachment *v3; // rbx
  UFG::AIVehicleAttachment *v4; // rdi
  UFG::allocator::free_link *v5; // rax
  UFG::AIVehicleAttachment *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::RigidBodyComponent> *v7; // [rsp+60h] [rbp+18h]

  v2 = a;
  v3 = this;
  this->mPrev = (UFG::qNode<UFG::VehicleAttachment,UFG::VehicleAttachment> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::VehicleAttachment,UFG::VehicleAttachment> *)&this->mPrev;
  v7 = &this->body;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v7->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v4 = 0i64;
  this->body.m_pPointer = 0i64;
  this->bulletCollider = 0i64;
  this->age = 0.0;
  *(_DWORD *)&this->boneIndex = 0xFFFF;
  this->id = a;
  v5 = UFG::qMemoryPool::Allocate(&gAIMemoryPool, 0x20ui64, "AIVehicleAttachment", 0i64, 1u);
  if ( v5 )
  {
    UFG::AIVehicleAttachment::AIVehicleAttachment((UFG::AIVehicleAttachment *)v5, v3, UFG::PhysicsCar::isDoor[v2]);
    v4 = v6;
  }
  v3->aiAttachment = v4;
}

// File Line: 275
// RVA: 0x4518A0
void __fastcall UFG::VehicleAttachment::~VehicleAttachment(UFG::VehicleAttachment *this)
{
  UFG::VehicleAttachment *v1; // rbx
  UFG::AIVehicleAttachment *v2; // rdi
  UFG::qSafePointer<UFG::SimComponent,UFG::RigidBodyComponent> *v3; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::VehicleAttachment,UFG::VehicleAttachment> *v8; // rcx
  UFG::qNode<UFG::VehicleAttachment,UFG::VehicleAttachment> *v9; // rax

  v1 = this;
  v2 = this->aiAttachment;
  if ( v2 )
  {
    UFG::AIVehicleAttachment::~AIVehicleAttachment(this->aiAttachment);
    UFG::qMemoryPool::Free(&gAIMemoryPool, v2);
  }
  v3 = &v1->body;
  if ( v1->body.m_pPointer )
  {
    v4 = v3->mPrev;
    v5 = v1->body.mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
    v1->body.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->body.mPrev;
  }
  v1->body.m_pPointer = 0i64;
  v6 = v3->mPrev;
  v7 = v1->body.mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v1->body.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->body.mPrev;
  v8 = v1->mPrev;
  v9 = v1->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v1->mPrev = (UFG::qNode<UFG::VehicleAttachment,UFG::VehicleAttachment> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<UFG::VehicleAttachment,UFG::VehicleAttachment> *)&v1->mPrev;
}

// File Line: 286
// RVA: 0x44A9C0
void __fastcall UFG::PhysicsCar::PhysicsCar(UFG::PhysicsCar *this, UFG::VehicleParams *param, UFG::qMatrix44 *transform, UFG::qVector3 *velocity, UFG::qVector3 *wheelPositions)
{
  UFG::PhysicsCar *v5; // rbx
  UFG::qList<UFG::VehicleAttachment,UFG::VehicleAttachment,1,0> *v6; // ST38_8
  UFG::qReflectObject *v7; // rcx
  UFG::qReflectHandleBase v8; // [rsp+40h] [rbp-38h]

  v5 = this;
  UFG::PhysicsWheeledVehicle::PhysicsWheeledVehicle(
    (UFG::PhysicsWheeledVehicle *)&this->vfptr,
    param,
    transform,
    velocity,
    wheelPositions);
  v5->vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::PhysicsCar::`vftable';
  v6 = &v5->mAttachments;
  v6->mNode.mPrev = &v6->mNode;
  v6->mNode.mNext = &v6->mNode;
  v5->mIsAttachmentSupported = -1;
  UFG::qReflectHandleBase::qReflectHandleBase(&v8);
  v8.mTypeUID = UFG::qStringHash64("UFG::CarPhysicsDef", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::Init(&v8, v8.mTypeUID, v5->mDnaDefinition.mData->mBaseNode.mUID);
  v7 = v8.mData;
  v5->mRollStability = *(float *)&v8.mData[1].mTypeUID;
  if ( LOBYTE(v7[8].mBaseNode.mNeighbours[0]) )
    v5->mIsAttachmentSupported &= 0xFFFFFFFD;
  if ( BYTE1(v7[8].mBaseNode.mNeighbours[0]) )
    v5->mIsAttachmentSupported &= 0xFFFFFFEF;
  if ( BYTE2(v7[8].mBaseNode.mNeighbours[0]) )
    v5->mIsAttachmentSupported &= 0xFFFFFFFB;
  if ( BYTE3(v7[8].mBaseNode.mNeighbours[0]) )
    v5->mIsAttachmentSupported &= 0xFFFFFFDF;
  if ( BYTE4(v7[8].mBaseNode.mNeighbours[0]) )
    v5->mIsAttachmentSupported &= 0xFFFFFF7F;
  UFG::qReflectHandleBase::~qReflectHandleBase(&v8);
}

// File Line: 302
// RVA: 0x450350
void __fastcall UFG::PhysicsCar::~PhysicsCar(UFG::PhysicsCar *this)
{
  UFG::PhysicsCar *v1; // rdi
  UFG::qNode<UFG::VehicleAttachment,UFG::VehicleAttachment> *v2; // rcx
  UFG::qNode<UFG::VehicleAttachment,UFG::VehicleAttachment> *v3; // rax

  v1 = this;
  this->vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::PhysicsCar::`vftable';
  UFG::PhysicsCar::DestroyAllAttachments(this);
  UFG::qList<UFG::VehicleAttachment,UFG::VehicleAttachment,1,0>::DeleteNodes(&v1->mAttachments);
  v2 = v1->mAttachments.mNode.mPrev;
  v3 = v1->mAttachments.mNode.mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v1->mAttachments.mNode.mPrev = &v1->mAttachments.mNode;
  v1->mAttachments.mNode.mNext = &v1->mAttachments.mNode;
  v1->vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::PhysicsWheeledVehicle::`vftable';
  UFG::PhysicsWheeledVehicle::DeleteWheeledVehicleComponents((UFG::PhysicsWheeledVehicle *)&v1->vfptr);
  UFG::PhysicsVehicle::~PhysicsVehicle((UFG::PhysicsVehicle *)&v1->vfptr);
}

// File Line: 309
// RVA: 0x474CF0
void __fastcall UFG::PhysicsCar::SetLevelOfDetailInternal(UFG::PhysicsCar *this, UFG::PhysicsVehicle::Lod lod)
{
  UFG::PhysicsVehicle::Lod v2; // edi
  UFG::PhysicsCar *v3; // rbx

  v2 = lod;
  v3 = this;
  if ( lod == 1 )
    UFG::PhysicsCar::DestroyAllAttachments(this);
  UFG::PhysicsWheeledVehicle::SetLevelOfDetailInternal((UFG::PhysicsWheeledVehicle *)&v3->vfptr, v2);
}

// File Line: 322
// RVA: 0x47E190
void __fastcall UFG::PhysicsCar::UpdateAttachmentState(UFG::PhysicsCar *this, UFG::VehicleAttachment *attachment)
{
  char v2; // al
  UFG::VehicleAttachment *v3; // rbx
  UFG::PhysicsCar *v4; // rdi
  UFG::RigidBody *v5; // rcx
  char v6; // al
  unsigned int v7; // edx

  v2 = attachment->desiredState;
  v3 = attachment;
  v4 = this;
  if ( v2 != attachment->currentState )
  {
    if ( !v2 )
    {
      UFG::PhysicsCar::DestroyAttachment(this, attachment);
      v3->currentState = v3->desiredState;
      return;
    }
    if ( !attachment->body.m_pPointer )
      UFG::PhysicsCar::CreateRigidBodyForAttachment(this, attachment);
    v5 = (UFG::RigidBody *)v3->body.m_pPointer;
    if ( !v5 )
      goto LABEL_17;
    v6 = v3->desiredState;
    if ( v6 != 2 )
    {
      if ( v6 == 3 )
      {
        UFG::RigidBody::DeleteAllConstraints(v5);
        UFG::PhysicsCar::CreateConstraintForAttachment(v4, v3, 0);
LABEL_13:
        v7 = 256;
        if ( v3->desiredState != 1 )
          v7 = 128;
        UFG::RigidBody::SetMotionType((UFG::RigidBody *)v3->body.m_pPointer, v7);
        if ( v3->desiredState == 4 )
        {
          LODWORD(v3->body.m_pPointer[4].m_SafePointerList.mNode.mPrev) |= 0x8000 | LODWORD(v3->body.m_pPointer[4].m_SafePointerList.mNode.mPrev);
          hkpRigidBody::setLinearVelocity(
            (hkpRigidBody *)v3->body.m_pPointer[2].m_pSimObject,
            &v4->mRigidBody->mBody->m_motion.m_linearVelocity);
        }
LABEL_17:
        v3->currentState = v3->desiredState;
        return;
      }
      if ( v6 != 4 )
      {
        UFG::RigidBody::DeleteAllConstraints(v5);
        goto LABEL_13;
      }
    }
    UFG::RigidBody::DeleteAllConstraints(v5);
    UFG::PhysicsCar::CreateConstraintForAttachment(v4, v3, 1);
    goto LABEL_13;
  }
}

// File Line: 389
// RVA: 0x47F610
void __fastcall UFG::PhysicsCar::UpdateMotorTarget(UFG::PhysicsCar *this, UFG::VehicleAttachment *attachment)
{
  UFG::VehicleAttachment *v2; // rdi
  UFG::PhysicsCar *v3; // rbx
  UFG::Constraint *v4; // rax
  hkpRigidBody *v5; // rbx
  hkpConstraintData *v6; // rsi
  __int64 v7; // rax
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
  hkQuaternionf nextOrientation; // [rsp+20h] [rbp-A8h]
  hkVector4f v22; // [rsp+30h] [rbp-98h]
  hkVector4f nextPosition; // [rsp+40h] [rbp-88h]
  __m128 v24; // [rsp+50h] [rbp-78h]
  __m128 v25; // [rsp+60h] [rbp-68h]
  __m128 v26; // [rsp+70h] [rbp-58h]
  unsigned int v27; // [rsp+D0h] [rbp+8h]

  v2 = attachment;
  v3 = this;
  UFG::RigidBodyComponent::GetKeyframe(
    (UFG::RigidBodyComponent *)attachment->body.m_pPointer,
    &nextPosition,
    &nextOrientation);
  v4 = UFG::RigidBody::GetConstraintByIndex((UFG::RigidBody *)v2->body.m_pPointer, 0);
  v5 = v3->mRigidBody->mBody;
  v6 = v4->mConstraintInstance->m_data;
  v7 = v2->id;
  v24 = transform.m_quad;
  v25 = direction.m_quad;
  v8 = UFG::PhysicsCar::perp_axis[v7];
  v26 = stru_141A71280.m_quad;
  hkVector4f::setRotatedDir(&v22, &nextOrientation, (hkVector4f *)&v24 + v8);
  v9 = v2->id;
  v10 = _mm_mul_ps(*(__m128 *)&(&v5->vfptr)[2 * (UFG::PhysicsCar::perp_axis[v9] + 23i64)], v22.m_quad);
  *(float *)&v11 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v10, v10, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v10, v10, 0)))
                 + COERCE_FLOAT(_mm_shuffle_ps(v10, v10, 170));
  v12 = _mm_mul_ps(*(__m128 *)&(&v5->vfptr)[2 * (UFG::perp_axis2[v9] + 23i64)], v22.m_quad);
  *(float *)&v27 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 0)))
                 + COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 170));
  v13 = _mm_rcp_ps((__m128)v11);
  v14 = _mm_mul_ps(v13, (__m128)v27);
  v15 = _mm_or_ps(_mm_cmpnleps(_mm_or_ps(*(__m128 *)_xmm, *(__m128 *)_xmm), v14), _mm_cmpltps(*(__m128 *)_xmm, v14));
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
  v19 = _mm_cmpleps((__m128)0i64, v13);
  v20 = _mm_or_ps(
          _mm_and_ps(_mm_sub_ps(_mm_or_ps(_mm_and_ps(v16, *(__m128 *)_xmm), *(__m128 *)_xmm), v18), v15),
          _mm_andnot_ps(v15, v18));
  *(_DWORD *)(&v6[8].m_referenceCount + 1) = (*(unsigned __int128 *)&_mm_andnot_ps(
                                                                       v19,
                                                                       _mm_add_ps(
                                                                         _mm_or_ps(
                                                                           _mm_and_ps(*(__m128 *)_xmm, (__m128)v27),
                                                                           *(__m128 *)_xmm),
                                                                         v20)) | v20.m128_i32[0] & v19.m128_i32[0]) ^ _xmm[0];
}

// File Line: 424
// RVA: 0x47F850
void __fastcall UFG::PhysicsCar::UpdateMotorTargets(UFG::PhysicsCar *this)
{
  UFG::VehicleAttachment *v1; // rdx
  UFG::qList<UFG::VehicleAttachment,UFG::VehicleAttachment,1,0> *v2; // rsi
  UFG::PhysicsCar *v3; // rdi
  UFG::VehicleAttachment *v4; // rbx

  v1 = (UFG::VehicleAttachment *)this->mAttachments.mNode.mNext;
  v2 = &this->mAttachments;
  v3 = this;
  if ( v1 != (UFG::VehicleAttachment *)&this->mAttachments )
  {
    do
    {
      v4 = (UFG::VehicleAttachment *)v1->mNext;
      if ( v1->currentState == 4 && v3->mCurrentLod != 1 )
      {
        if ( v1->body.m_pPointer )
          UFG::PhysicsCar::UpdateMotorTarget(v3, v1);
      }
      v1 = v4;
    }
    while ( v4 != (UFG::VehicleAttachment *)v2 );
  }
}

// File Line: 444
// RVA: 0x480210
void __fastcall UFG::PhysicsCar::UpdateTransforms(UFG::PhysicsCar *this, UFG::qMatrix44 *rootTransform)
{
  UFG::VehicleAttachment *v2; // rbx
  UFG::qList<UFG::VehicleAttachment,UFG::VehicleAttachment,1,0> *v3; // rbp
  UFG::qMatrix44 *v4; // r14
  UFG::PhysicsCar *v5; // rsi
  UFG::VehicleAttachment *v6; // rdi
  UFG::qNode<UFG::VehicleAttachment,UFG::VehicleAttachment> *v7; // rcx
  UFG::qNode<UFG::VehicleAttachment,UFG::VehicleAttachment> *v8; // rax

  v2 = (UFG::VehicleAttachment *)this->mAttachments.mNode.mNext;
  v3 = &this->mAttachments;
  v4 = rootTransform;
  v5 = this;
  if ( v2 != (UFG::VehicleAttachment *)&this->mAttachments )
  {
    do
    {
      v6 = (UFG::VehicleAttachment *)v2->mNext;
      if ( v5->mCurrentLod != 1 )
        UFG::PhysicsCar::UpdateAttachmentState(v5, v2);
      if ( !v2->currentState )
      {
        v7 = v2->mPrev;
        v8 = v2->mNext;
        v7->mNext = v8;
        v8->mPrev = v7;
        v2->mPrev = (UFG::qNode<UFG::VehicleAttachment,UFG::VehicleAttachment> *)&v2->mPrev;
        v2->mNext = (UFG::qNode<UFG::VehicleAttachment,UFG::VehicleAttachment> *)&v2->mPrev;
        UFG::VehicleAttachment::~VehicleAttachment(v2);
        UFG::qMemoryPool::Free(&gPhysicsMemoryPool, v2);
      }
      v2 = v6;
    }
    while ( v6 != (UFG::VehicleAttachment *)v3 );
  }
  UFG::PhysicsVehicle::UpdateTransforms((UFG::PhysicsVehicle *)&v5->vfptr, v4);
}

// File Line: 471
// RVA: 0x47A600
void __fastcall UFG::PhysicsCar::Update(UFG::PhysicsCar *this, UFG::qMatrix44 *targetTransform, UFG::VehicleInput *driverInput, float deltaTime)
{
  UFG::VehicleInput *v4; // r15
  UFG::qMatrix44 *v5; // r12
  UFG::PhysicsCar *v6; // rdi
  float v7; // xmm7_4
  UFG::VehicleAttachment *v8; // rbx
  UFG::qList<UFG::VehicleAttachment,UFG::VehicleAttachment,1,0> *v9; // r14
  hkpReorientAction *v10; // rbp
  UFG::VehicleAttachment *v11; // rsi
  float v12; // xmm0_4
  __int64 v13; // rdx
  UFG::RigidBody *v14; // rcx
  UFG::Constraint *v15; // rax
  hkpConstraintInstance *v16; // rax
  UFG::RigidBody *v17; // rcx
  UFG::RigidBody *v18; // rcx
  hkpRigidBody *v19; // rcx
  UFG::SimComponent *v20; // rax
  UFG::AIVehicleAttachment *v21; // rcx
  UFG::VehicleInstance *v22; // rbx
  hkpVehicleAerodynamics *v23; // rbx
  float v24; // xmm0_4
  UFG::BasePhysicsSystem *v25; // rbx
  UFG::VehicleInstance *v26; // rcx
  hkpVehicleInstance::WheelInfo *v27; // rdx
  hkpVehicleInstance::WheelInfo *v28; // rdx
  signed __int64 v29; // r8
  char v30; // dl
  __int64 v31; // rax
  char v32; // cl
  _QWORD **v33; // rax
  UFG::OneShot *v34; // rax
  hkJobType v35; // edx
  hkpReorientAction *v36; // rax
  hkpAction *v37; // rdx
  hkpAction *v38; // rdx
  hkpReorientAction *v39; // rcx
  hkVector4f upAxis; // [rsp+40h] [rbp-E8h]
  hkVector4f rotationAxis; // [rsp+50h] [rbp-D8h]
  UFG::qMatrix44 mat; // [rsp+60h] [rbp-C8h]
  UFG::OneShotHandle pHandle; // [rsp+130h] [rbp+8h]

  v4 = driverInput;
  v5 = targetTransform;
  v6 = this;
  v7 = 0.0;
  v8 = (UFG::VehicleAttachment *)this->mAttachments.mNode.mNext;
  v9 = &this->mAttachments;
  v10 = 0i64;
  if ( v8 != (UFG::VehicleAttachment *)&this->mAttachments )
  {
    do
    {
      v11 = (UFG::VehicleAttachment *)v8->mNext;
      v12 = deltaTime + v8->age;
      v8->age = v12;
      if ( v6->mCurrentLod == 1 )
      {
        v21 = v8->aiAttachment;
        if ( v21 )
          goto LABEL_27;
      }
      else
      {
        if ( v8->desiredState != 4 )
        {
          v13 = v8->id;
          if ( v12 > UFG::PhysicsCar::min_time_before_closing[v13] )
          {
            v14 = (UFG::RigidBody *)v8->body.m_pPointer;
            if ( v14 )
            {
              if ( (unsigned int)v13 <= 5 )
              {
                v15 = UFG::RigidBody::GetConstraintByIndex(v14, 0);
                if ( v15 )
                {
                  v16 = v15->mConstraintInstance;
                  if ( v16->m_owner )
                  {
                    LODWORD(v12) = COERCE_UNSIGNED_INT(*((float *)v16->m_internal->m_runtime + 9) * -1.0) & _xmm;
                    if ( v12 < 0.050000001 )
                    {
                      v8->desiredState = 0;
                      v17 = (UFG::RigidBody *)v8->body.m_pPointer;
                      if ( v17 )
                      {
                        UFG::RigidBody::GetTransform(v17, &mat);
                        pHandle.m_pOneShot = 0i64;
                        UFG::OneShotPool::GetOneShotHandle(&pHandle, &mat);
                        if ( UFG::OneShotHandle::IsValid(&pHandle) )
                        {
                          if ( !(_S10_7 & 1) )
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
        v18 = (UFG::RigidBody *)v8->body.m_pPointer;
        if ( v18 )
        {
          UFG::RigidBody::GetMass(v18);
          v7 = v7 + v12;
          v19 = v8->bulletCollider;
          if ( v19 )
            hkpRigidBody::setTransform(
              v19,
              (hkTransformf *)&v8->body.m_pPointer[2].m_pSimObject[2].m_UnboundComponentHandles);
          if ( v8->aiAttachment )
          {
            UFG::RigidBody::GetTransform((UFG::RigidBody *)v8->body.m_pPointer, &mat);
            UFG::AIVehicleAttachment::Update(v8->aiAttachment, &mat, deltaTime);
          }
        }
        v20 = v8->body.m_pPointer;
        if ( v20 )
          LODWORD(v20[4].m_SafePointerList.mNode.mPrev) |= 0x800u;
        v21 = v8->aiAttachment;
        if ( !v21 )
          goto LABEL_28;
        if ( !v8->desiredState )
        {
LABEL_27:
          UFG::AIVehicleAttachment::Disable(v21);
          goto LABEL_28;
        }
        UFG::AIVehicleAttachment::Enable(v21);
      }
LABEL_28:
      v8 = v11;
    }
    while ( v11 != (UFG::VehicleAttachment *)v9 );
  }
  v22 = v6->mHavokVehicle;
  if ( v22 )
  {
    v23 = v22->m_aerodynamics;
    v24 = hkpMotion::getMass((hkpMotion *)&v6->mRigidBody->mBody->m_motion.vfptr);
    *((float *)&v23[3].vfptr + 1) = v24 / (float)(v24 + v7);
  }
  UFG::PhysicsWheeledVehicle::Update((UFG::PhysicsWheeledVehicle *)&v6->vfptr, v5, v4, deltaTime);
  v25 = UFG::BasePhysicsSystem::mInstance;
  if ( v6->mCurrentLod != 3
    || (v26 = v6->mHavokVehicle) == 0i64
    || ((v27 = v26->m_wheelsInfo.m_data, v27->m_contactBody) || v27[1].m_contactBody)
    && (!v26 || (v28 = v26->m_wheelsInfo.m_data, v28[2].m_contactBody) || v28[3].m_contactBody)
    || v6->mSpeedKPH <= 10.0 )
  {
    v38 = (hkpAction *)&v6->mReorientActionRoll->vfptr;
    if ( v38 )
    {
      UFG::BasePhysicsSystem::RemoveAction(UFG::BasePhysicsSystem::mInstance, v38);
      v39 = v6->mReorientActionRoll;
      if ( v39 )
        v39->vfptr->__vecDelDtor((hkBaseObject *)&v39->vfptr, 1u);
      v6->mReorientActionRoll = 0i64;
    }
  }
  else
  {
    if ( !v6->mReorientActionRoll && v6->mRollStability > 0.0 )
    {
      rotationAxis.m_quad = (__m128)_xmm;
      upAxis.m_quad = _xmm;
      v29 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
      v30 = ++*(_BYTE *)(v29 + 80);
      v31 = v30;
      *(_DWORD *)(v29 + 4 * v31) = 3;
      *(_QWORD *)(v29 + 8 * v31 + 16) = "hkpReorientAction";
      *(_QWORD *)(v29 + 8 * v31 + 48) = 0i64;
      v32 = *(_BYTE *)(v29 + 81);
      if ( v30 > v32 )
        v32 = v30;
      *(_BYTE *)(v29 + 81) = v32;
      v33 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v34 = (UFG::OneShot *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v33[11] + 8i64))(v33[11], 112i64);
      pHandle.m_pOneShot = v34;
      if ( v34 )
      {
        hkpReorientAction::hkpReorientAction(
          (hkpReorientAction *)v34,
          v6->mRigidBody->mBody,
          &rotationAxis,
          &upAxis,
          v6->mRollStability,
          0.1);
        v10 = v36;
      }
      v6->mReorientActionRoll = v10;
      HavokJobMemoryPoolTagger::onEndJob((HavokJobMemoryPoolTagger *)CustomHavokMemorySystem::mInstance, v35);
    }
    v37 = (hkpAction *)&v6->mReorientActionRoll->vfptr;
    if ( v37 )
    {
      if ( !v37->m_world )
        UFG::BasePhysicsSystem::AddAction(v25, v37);
    }
  }
}

// File Line: 616
// RVA: 0x473420
void __fastcall UFG::PhysicsCar::Reset(UFG::PhysicsCar *this, UFG::VehicleResetOptions options)
{
  UFG::VehicleResetOptions v2; // ebx
  UFG::PhysicsCar *v3; // rdi

  v2 = options;
  v3 = this;
  UFG::PhysicsCar::DestroyAllAttachments(this);
  UFG::PhysicsVehicle::Reset((UFG::PhysicsVehicle *)&v3->vfptr, v2);
}

// File Line: 624
// RVA: 0x476740
void __fastcall UFG::PhysicsCar::Teleport(UFG::PhysicsCar *this, UFG::qMatrix44 *mat)
{
  UFG::qMatrix44 *v2; // rbx
  UFG::PhysicsCar *v3; // rdi
  UFG::qVector4 v4; // xmm3
  UFG::qVector4 v5; // xmm2
  UFG::qVector4 v6; // xmm1

  v2 = mat;
  v3 = this;
  UFG::PhysicsCar::DestroyAllAttachments(this);
  v4 = v2->v1;
  v5 = v2->v2;
  v6 = v2->v3;
  v3->mLastGoodPosition.v0 = v2->v0;
  v3->mLastGoodPosition.v1 = v4;
  v3->mLastGoodPosition.v2 = v5;
  v3->mLastGoodPosition.v3 = v6;
  ((void (__fastcall *)(UFG::PhysicsCar *, _QWORD))v3->vfptr[1].DebugDraw)(v3, 0i64);
}

// File Line: 632
// RVA: 0x476340
void __fastcall UFG::PhysicsCar::Suspend(UFG::PhysicsCar *this)
{
  UFG::PhysicsCar *v1; // rbx

  v1 = this;
  UFG::PhysicsCar::DestroyAllAttachments(this);
  UFG::PhysicsWheeledVehicle::Suspend((UFG::PhysicsWheeledVehicle *)&v1->vfptr);
}

// File Line: 640
// RVA: 0x473E90
void __fastcall UFG::PhysicsCar::Restore(UFG::PhysicsCar *this)
{
  UFG::PhysicsWheeledVehicle::Restore((UFG::PhysicsWheeledVehicle *)&this->vfptr);
}

// File Line: 647
// RVA: 0x4705D0
void __fastcall UFG::PhysicsCar::ProcessCollisonEvent(UFG::PhysicsCar *this, UFG::CollisionEvent *ev)
{
  UFG::VehicleAttachmentID v2; // esi
  bool *v3; // r13
  signed int v4; // er12
  UFG::PhysicsCar *v5; // rdi
  signed int v6; // er14
  bool *v7; // r10
  signed int v8; // er8
  signed int v9; // er9
  UFG::qNode<UFG::VehicleAttachment,UFG::VehicleAttachment> *v10; // rax
  UFG::SimComponent *v11; // rbx
  UFG::SimObjectVehicle *v12; // rbx
  unsigned __int16 v13; // cx
  UFG::SimComponent *v14; // rax
  UFG::SimComponent *v15; // rbp
  unsigned __int16 v16; // cx
  UFG::CharacterAnimationComponent *v17; // rax
  unsigned __int16 v18; // cx
  UFG::CharacterAnimationComponent *v19; // r15
  UFG::CarPhysicsMoverComponent *v20; // rax
  DamageRig *v21; // rbp
  float *v22; // rbx
  float v23; // xmm0_4
  int v24; // eax
  Creature *v25; // rcx
  hkQsTransformf *v26; // rax
  float v27; // xmm2_4
  float v28; // xmm1_4
  UFG::qVector3 pos; // [rsp+20h] [rbp-58h]
  UFG::CollisionEvent *v30; // [rsp+88h] [rbp+10h]

  v30 = ev;
  v2 = 0;
  v3 = UFG::PhysicsCar::isDoor;
  v4 = 1;
  v5 = this;
  v6 = 0;
  v7 = UFG::PhysicsCar::isDoor;
  v8 = 0;
  v9 = 1;
  do
  {
    if ( this->mIsAttachmentSupported & v9 )
    {
      if ( *v7 )
      {
        v10 = this->mAttachments.mNode.mNext;
        if ( v10 != (UFG::qNode<UFG::VehicleAttachment,UFG::VehicleAttachment> *)&this->mAttachments )
        {
          while ( LODWORD(v10[4].mPrev) != v8 )
          {
            v10 = v10->mNext;
            if ( v10 == (UFG::qNode<UFG::VehicleAttachment,UFG::VehicleAttachment> *)&this->mAttachments )
              goto LABEL_10;
          }
          if ( v10[2].mPrev != 0i64 )
            ++v6;
        }
      }
    }
LABEL_10:
    v9 = __ROL4__(v9, 1);
    ++v8;
    ++v7;
  }
  while ( v8 < 8 );
  if ( this->mCurrentLod != 1 )
  {
    v11 = this->mUserData.simComponent.m_pPointer;
    v12 = (UFG::SimObjectVehicle *)(v11 ? v11->m_pSimObject : 0i64);
    if ( v12 )
    {
      v13 = v12->m_Flags;
      if ( (v13 >> 14) & 1 )
      {
        v14 = UFG::SimObjectGame::GetComponentOfTypeHK(
                (UFG::SimObjectGame *)&v12->vfptr,
                UFG::VehicleEffectsComponent::_TypeUID);
      }
      else
      {
        if ( (v13 & 0x8000u) != 0 )
        {
          v15 = v12->m_Components.p[32].m_pComponent;
          goto LABEL_26;
        }
        if ( (v13 >> 13) & 1 )
        {
          v14 = UFG::SimObjectGame::GetComponentOfTypeHK(
                  (UFG::SimObjectGame *)&v12->vfptr,
                  UFG::VehicleEffectsComponent::_TypeUID);
        }
        else if ( (v13 >> 12) & 1 )
        {
          v14 = UFG::SimObjectGame::GetComponentOfTypeHK(
                  (UFG::SimObjectGame *)&v12->vfptr,
                  UFG::VehicleEffectsComponent::_TypeUID);
        }
        else
        {
          v14 = UFG::SimObject::GetComponentOfType(
                  (UFG::SimObject *)&v12->vfptr,
                  UFG::VehicleEffectsComponent::_TypeUID);
        }
      }
      v15 = v14;
LABEL_26:
      v16 = v12->m_Flags;
      if ( (v16 >> 14) & 1 )
      {
        v17 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectCVBase *)&v12->vfptr);
      }
      else if ( (v16 & 0x8000u) == 0 )
      {
        if ( (v16 >> 13) & 1 )
        {
          v17 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v12);
        }
        else if ( (v16 >> 12) & 1 )
        {
          v17 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      (UFG::SimObjectGame *)&v12->vfptr,
                                                      UFG::CharacterAnimationComponent::_TypeUID);
        }
        else
        {
          v17 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                      (UFG::SimObject *)&v12->vfptr,
                                                      UFG::CharacterAnimationComponent::_TypeUID);
        }
      }
      else
      {
        v17 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectCVBase *)&v12->vfptr);
      }
      v18 = v12->m_Flags;
      v19 = v17;
      if ( (v18 >> 14) & 1 )
      {
        v20 = 0i64;
      }
      else if ( (v18 & 0x8000u) == 0 )
      {
        if ( (v18 >> 13) & 1 )
        {
          v20 = (UFG::CarPhysicsMoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   (UFG::SimObjectGame *)&v12->vfptr,
                                                   UFG::CarPhysicsMoverComponent::_TypeUID);
        }
        else if ( (v18 >> 12) & 1 )
        {
          v20 = (UFG::CarPhysicsMoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   (UFG::SimObjectGame *)&v12->vfptr,
                                                   UFG::CarPhysicsMoverComponent::_TypeUID);
        }
        else
        {
          v20 = (UFG::CarPhysicsMoverComponent *)UFG::SimObject::GetComponentOfType(
                                                   (UFG::SimObject *)&v12->vfptr,
                                                   UFG::CarPhysicsMoverComponent::_TypeUID);
        }
      }
      else
      {
        v20 = UFG::SimObjectVehicle::GetComponent<UFG::CarPhysicsMoverComponent>(v12);
      }
      if ( v15 )
      {
        if ( v19 )
        {
          if ( v20 )
          {
            if ( v20->mSupportsAttachments )
            {
              v21 = (DamageRig *)v15[28].m_pSimObject;
              if ( v21 )
              {
                if ( v21->mAggregateDamage > 0.0 )
                {
                  v22 = 0i64;
                  do
                  {
                    if ( v4 & v5->mIsAttachmentSupported
                      && !UFG::PhysicsCar::IsAttachmentActive(v5, v2)
                      && (!*v3 || v6 < 1) )
                    {
                      v23 = v22[1350698538];
                      if ( v23 == 0.0 || v23 < v30->estimatedImpulseMagnitude )
                      {
                        v24 = UFG::PhysicsCar::GetBoneIndexForAttachment(v5, v19, v2);
                        if ( v24 != -1 )
                        {
                          v25 = v19->mCreature;
                          if ( v25 )
                          {
                            v26 = Creature::GetTranslationMS(v25, v24);
                            v27 = v26->m_translation.m_quad.m128_f32[2];
                            v28 = v26->m_translation.m_quad.m128_f32[1];
                            LODWORD(pos.x) = v26->m_translation.m_quad.m128_i32[0];
                            pos.z = v27;
                          }
                          else
                          {
                            v28 = UFG::qVector3::msZero.y;
                            pos.x = UFG::qVector3::msZero.x;
                            pos.z = UFG::qVector3::msZero.z;
                          }
                          pos.y = v28;
                          if ( DamageRig::GetDamageAtPosition(v21, &pos) >= v22[1350698530]
                            && UFG::qRandom(1.0, &UFG::qDefaultSeed) < v22[1350698546] )
                          {
                            UFG::PhysicsCar::SetDesiredAttachmentState(v5, v2, ATT_SIMULATED);
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
                  while ( (signed int)v2 < 8 );
                }
              }
            }
          }
        }
      }
      return;
    }
  }
}          }
              }
            }
          }
        }
      }
      return;
    }
  }
}

// File Line: 718
// RVA: 0x474AB0
void __fastcall UFG::PhysicsCar::SetDesiredAttachmentState(UFG::PhysicsCar *this, UFG::VehicleAttachmentID id, UFG::VehicleAttachmentState state)
{
  char v3; // si
  UFG::VehicleAttachmentID v4; // ebx
  UFG::PhysicsCar *v5; // rbp
  unsigned int v6; // eax
  char v7; // r9
  UFG::qNode<UFG::VehicleAttachment,UFG::VehicleAttachment> *v8; // rax
  UFG::qList<UFG::VehicleAttachment,UFG::VehicleAttachment,1,0> *v9; // rdi
  UFG::allocator::free_link *v10; // rax
  __int64 v11; // rax
  __int64 v12; // rbx
  UFG::SimObjectCVBase *v13; // rcx
  unsigned __int16 v14; // dx
  UFG::CharacterAnimationComponent *v15; // rax
  Creature *v16; // rcx
  signed __int16 v17; // ax
  UFG::qNode<UFG::VehicleAttachment,UFG::VehicleAttachment> *v18; // rax

  v3 = state;
  v4 = id;
  v5 = this;
  v6 = this->mIsAttachmentSupported;
  if ( _bittest((const signed int *)&v6, id) )
  {
    v7 = 0;
    v8 = this->mAttachments.mNode.mNext;
    v9 = &this->mAttachments;
    if ( v8 == (UFG::qNode<UFG::VehicleAttachment,UFG::VehicleAttachment> *)&this->mAttachments )
    {
LABEL_8:
      if ( state )
      {
        v10 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x48ui64, "VehicleAttachment", 0i64, 1u);
        if ( v10 )
        {
          UFG::VehicleAttachment::VehicleAttachment((UFG::VehicleAttachment *)v10, v4);
          v12 = v11;
        }
        else
        {
          v12 = 0i64;
        }
        *(_BYTE *)(v12 + 63) = v3;
        v13 = (UFG::SimObjectCVBase *)v5->mParams->mSimObject.m_pPointer;
        if ( v13 )
        {
          v14 = v13->m_Flags;
          if ( (v14 >> 14) & 1 )
          {
            v15 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v13);
          }
          else if ( (v14 & 0x8000u) == 0 )
          {
            if ( (v14 >> 13) & 1 )
              v15 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v13);
            else
              v15 = (UFG::CharacterAnimationComponent *)((v14 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                             (UFG::SimObjectGame *)&v13->vfptr,
                                                                             UFG::CharacterAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v13->vfptr, UFG::CharacterAnimationComponent::_TypeUID));
          }
          else
          {
            v15 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v13);
          }
          if ( v15 )
          {
            v16 = v15->mCreature;
            if ( v16 )
            {
              if ( v16->mPose.mRigHandle.mData )
                v17 = Skeleton::GetBoneID(
                        v16->mPose.mRigHandle.mUFGSkeleton,
                        UFG::PhysicsCar::attachment_bones[*(signed int *)(v12 + 64)].mUID);
              else
                v17 = -1;
              *(_WORD *)(v12 + 60) = v17;
            }
          }
        }
        v18 = v9->mNode.mPrev;
        v18->mNext = (UFG::qNode<UFG::VehicleAttachment,UFG::VehicleAttachment> *)v12;
        *(_QWORD *)v12 = v18;
        *(_QWORD *)(v12 + 8) = v9;
        v9->mNode.mPrev = (UFG::qNode<UFG::VehicleAttachment,UFG::VehicleAttachment> *)v12;
      }
    }
    else
    {
      while ( !v7 )
      {
        if ( LODWORD(v8[4].mPrev) == id )
        {
          HIBYTE(v8[3].mNext) = state;
          v7 = 1;
        }
        v8 = v8->mNext;
        if ( v8 == (UFG::qNode<UFG::VehicleAttachment,UFG::VehicleAttachment> *)v9 )
        {
          if ( v7 )
            return;
          goto LABEL_8;
        }
      }
    }
  }
}

// File Line: 761
// RVA: 0x4616E0
void __fastcall UFG::PhysicsCar::DestroyAllAttachments(UFG::PhysicsCar *this)
{
  char **v1; // rdi
  UFG::PhysicsCar *v2; // rsi
  UFG::qNode<UFG::VehicleAttachment,UFG::VehicleAttachment> *v3; // rbx
  UFG::qNode<UFG::VehicleAttachment,UFG::VehicleAttachment> *v4; // rcx
  UFG::qNode<UFG::VehicleAttachment,UFG::VehicleAttachment> *v5; // rax
  UFG::RigidBody *v6; // rcx
  hkpRigidBody *v7; // rdx
  UFG::AIVehicleAttachment *v8; // rcx

  v1 = (char **)&this->mAttachments;
  v2 = this;
  if ( (UFG::qList<UFG::VehicleAttachment,UFG::VehicleAttachment,1,0> *)this->mAttachments.mNode.mNext != &this->mAttachments )
  {
    do
    {
      v3 = v2->mAttachments.mNode.mNext;
      v4 = v3->mPrev;
      v5 = v3->mNext;
      v4->mNext = v5;
      v5->mPrev = v4;
      v3->mPrev = v3;
      v3->mNext = v3;
      v6 = (UFG::RigidBody *)v3[2].mPrev;
      HIWORD(v3[3].mNext) = 0;
      if ( v6 )
      {
        UFG::RigidBody::DeleteAllConstraints(v6);
        UFG::Simulation::DestroySimComponent(&UFG::gSim, (UFG::SimComponent *)v3[2].mPrev);
        v7 = (hkpRigidBody *)v3[2].mNext;
        if ( v7 )
        {
          UFG::BasePhysicsSystem::RemoveEntity(UFG::BasePhysicsSystem::mInstance, v7, 0);
          hkReferencedObject::removeReference((hkReferencedObject *)v3[2].mNext);
          v3[2].mNext = 0i64;
        }
      }
      v8 = (UFG::AIVehicleAttachment *)v3[3].mPrev;
      if ( v8 )
        UFG::AIVehicleAttachment::Disable(v8);
      UFG::VehicleAttachment::~VehicleAttachment((UFG::VehicleAttachment *)v3);
      UFG::qMemoryPool::Free(&gPhysicsMemoryPool, v3);
    }
    while ( v1[1] != (char *)v1 );
  }
}

// File Line: 773
// RVA: 0x4660F0
float __fastcall UFG::PhysicsCar::GetAttachmentAngle(UFG::PhysicsCar *this, UFG::VehicleAttachmentID id)
{
  UFG::VehicleAttachment *v2; // rbx
  UFG::VehicleAttachment *v3; // rdi
  __int64 v4; // rsi
  UFG::RigidBody *v5; // rcx
  UFG::Constraint *v6; // rax
  hkpConstraintInstance *v7; // rcx
  float result; // xmm0_4

  v2 = (UFG::VehicleAttachment *)this->mAttachments.mNode.mNext;
  v3 = (UFG::VehicleAttachment *)&this->mAttachments;
  v4 = id;
  if ( v2 == (UFG::VehicleAttachment *)&this->mAttachments )
    return FLOAT_N1_0;
  while ( 1 )
  {
    if ( v2->id == (_DWORD)v4 )
    {
      v5 = (UFG::RigidBody *)v2->body.m_pPointer;
      if ( v5 )
      {
        v6 = UFG::RigidBody::GetConstraintByIndex(v5, 0);
        if ( v6 )
        {
          v7 = v6->mConstraintInstance;
          if ( v7->m_owner )
            break;
        }
      }
    }
    v2 = (UFG::VehicleAttachment *)v2->mNext;
    if ( v2 == v3 )
      return FLOAT_N1_0;
  }
  result = (float)((float)(*((float *)v7->m_internal->m_runtime + 9) * -1.0) - UFG::PhysicsCar::min_angle[v4])
         / (float)(UFG::PhysicsCar::max_angle[v4] - UFG::PhysicsCar::min_angle[v4]);
  if ( *(_BYTE *)(v4 + 0x142081860i64) )
    result = 1.0 - result;
  return result;
}

// File Line: 845
// RVA: 0x46AA80
bool __fastcall UFG::PhysicsCar::IsAttachmentActive(UFG::PhysicsCar *this, UFG::VehicleAttachmentID id)
{
  UFG::VehicleAttachment *v2; // rax
  UFG::VehicleAttachment *v3; // rcx

  v2 = (UFG::VehicleAttachment *)this->mAttachments.mNode.mNext;
  v3 = (UFG::VehicleAttachment *)&this->mAttachments;
  if ( v2 == v3 )
    return 0;
  while ( v2->id != id )
  {
    v2 = (UFG::VehicleAttachment *)v2->mNext;
    if ( v2 == v3 )
      return 0;
  }
  return v2->body.m_pPointer != 0i64;
}

// File Line: 871
// RVA: 0x45F8C0
void __fastcall UFG::PhysicsCar::CreateRigidBodyForAttachment(UFG::PhysicsCar *this, UFG::VehicleAttachment *attachment)
{
  UFG::VehicleAttachment *v2; // rdi
  UFG::PhysicsCar *v3; // r14
  UFG::SimObjectCVBase *v4; // rcx
  unsigned __int16 v5; // dx
  UFG::CharacterAnimationComponent *v6; // rax
  UFG::CharacterAnimationComponent *v7; // rsi
  unsigned int v8; // er15
  UFG::CollisionMeshData *v9; // r13
  UFG::TransformNodeComponent *v10; // rbx
  hkaPose *v11; // r8
  __int64 v12; // rdx
  hkQsTransformf *v13; // rax
  __m128 v14; // xmm6
  __m128 v15; // xmm7
  __m128 v16; // xmm2
  __m128 v17; // xmm4
  __m128 v18; // xmm1
  __m128 v19; // xmm6
  __m128 v20; // xmm9
  __m128 v21; // xmm3
  __m128 v22; // xmm6
  __m128 v23; // xmm6
  __m128 v24; // xmm8
  __m128 v25; // xmm6
  UFG::allocator::free_link *v26; // rax
  hkpRigidBody *v27; // rsi
  UFG::CollisionInstanceData *v28; // rax
  UFG::CollisionInstanceData *v29; // rbx
  UFG::allocator::free_link *v30; // rax
  UFG::RigidBody *v31; // rax
  UFG::RigidBody *v32; // rbx
  __int64 v33; // rdx
  int v34; // edx
  unsigned int v35; // eax
  UFG::qBaseTreeRB *v36; // rbx
  UFG::SimObject *v37; // rax
  signed __int64 v38; // r8
  char v39; // dl
  __int64 v40; // rax
  char v41; // cl
  _QWORD **v42; // rax
  hkpRigidBody *v43; // rax
  hkJobType v44; // edx
  hkpRigidBody *v45; // rax
  unsigned int v46; // ebx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v47; // rcx
  const char *v48; // rax
  UFG::SimObjectModifier v49; // [rsp+30h] [rbp-A8h]
  hkVector4f direction; // [rsp+50h] [rbp-88h]
  char *str[2]; // [rsp+60h] [rbp-78h]
  unsigned int guid[2]; // [rsp+70h] [rbp-68h]
  UFG::qString v53; // [rsp+78h] [rbp-60h]
  hkTransformf transform; // [rsp+A8h] [rbp-30h]
  __m128 v55; // [rsp+E8h] [rbp+10h]
  hkQuaternionf quat; // [rsp+F8h] [rbp+20h]
  hkVector4f v57; // [rsp+108h] [rbp+30h]
  hkQsTransformf v58; // [rsp+118h] [rbp+40h]
  hkpRigidBodyCinfo info; // [rsp+148h] [rbp+70h]
  void *v60; // [rsp+298h] [rbp+1C0h]

  *(_QWORD *)guid = -2i64;
  v2 = attachment;
  v3 = this;
  v4 = (UFG::SimObjectCVBase *)this->mParams->mSimObject.m_pPointer;
  if ( v4 )
  {
    v5 = v4->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v4);
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
        v6 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v4);
      else
        v6 = (UFG::CharacterAnimationComponent *)((v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                     (UFG::SimObjectGame *)&v4->vfptr,
                                                                     UFG::CharacterAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::CharacterAnimationComponent::_TypeUID));
    }
    else
    {
      v6 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v4);
    }
    v7 = v6;
    if ( v6 )
    {
      if ( v6->mCreature && v2->boneIndex != -1 )
      {
        UFG::qString::qString(&v53, UFG::PhysicsCar::attachment_geo_format[v2->id], v3->mParams->modelName.mData);
        v8 = guid[1];
        if ( guid[1] == -1 )
        {
          v8 = UFG::qStringHashUpper32(str[1], 0xFFFFFFFF);
          guid[1] = v8;
        }
        v9 = (UFG::CollisionMeshData *)UFG::BasePhysicsSystem::GetCollisionModel(UFG::BasePhysicsSystem::mInstance, v8);
        if ( v9 )
        {
          v10 = v3->mParams->mSimObject.m_pPointer->m_pTransformNodeComponent;
          UFG::TransformNodeComponent::UpdateWorldTransform(v10);
          hkTransformf::set4x4ColumnMajor(&transform, &v10->mWorldTransform.v0.x);
          hkQsTransformf::setFromTransformNoScale(&v58, &transform);
          v11 = v7->mCreature->mPose.mHavokPose;
          v12 = v2->boneIndex;
          if ( v11->m_boneFlags.m_data[v12] & 2 )
            v13 = hkaPose::calculateBoneModelSpace(v7->mCreature->mPose.mHavokPose, v12);
          else
            v13 = &v11->m_modelPose.m_data[v12];
          v55 = v13->m_translation.m_quad;
          quat.m_vec.m_quad = (__m128)v13->m_rotation;
          v57.m_quad = (__m128)v13->m_scale;
          direction.m_quad = v55;
          hkVector4f::setRotatedDir((hkVector4f *)str, &quat, &direction);
          v14 = _mm_sub_ps(direction.m_quad, *(__m128 *)str);
          v15 = _mm_shuffle_ps(v58.m_rotation.m_vec.m_quad, v58.m_rotation.m_vec.m_quad, 255);
          v16 = _mm_mul_ps(v58.m_rotation.m_vec.m_quad, v14);
          v17 = _mm_shuffle_ps(v58.m_rotation.m_vec.m_quad, v58.m_rotation.m_vec.m_quad, 201);
          v18 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v58.m_rotation.m_vec.m_quad), _mm_mul_ps(v14, v17));
          v19 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(v14, _mm_sub_ps(_mm_mul_ps(v15, v15), (__m128)xmmword_141A711B0)),
                    _mm_mul_ps(
                      v58.m_rotation.m_vec.m_quad,
                      _mm_add_ps(
                        _mm_shuffle_ps(v16, v16, 170),
                        _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0))))),
                  _mm_mul_ps(_mm_shuffle_ps(v18, v18, 201), v15));
          v20 = _mm_add_ps(v58.m_translation.m_quad, _mm_add_ps(v19, v19));
          v21 = _mm_shuffle_ps(quat.m_vec.m_quad, quat.m_vec.m_quad, 255);
          v22 = _mm_sub_ps(
                  _mm_mul_ps(v58.m_rotation.m_vec.m_quad, _mm_shuffle_ps(quat.m_vec.m_quad, quat.m_vec.m_quad, 201)),
                  _mm_mul_ps(quat.m_vec.m_quad, v17));
          v23 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v22, v22, 201), _mm_mul_ps(quat.m_vec.m_quad, v15)),
                  _mm_mul_ps(v58.m_rotation.m_vec.m_quad, v21));
          v24 = _mm_mul_ps(v58.m_rotation.m_vec.m_quad, quat.m_vec.m_quad);
          v25 = _mm_shuffle_ps(
                  v23,
                  _mm_unpackhi_ps(
                    v23,
                    _mm_sub_ps(
                      _mm_mul_ps(v21, v15),
                      _mm_add_ps(
                        _mm_shuffle_ps(v24, v24, 170),
                        _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0))))),
                  196);
          v26 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x70ui64, "CollisionInstanceData", 0i64, 1u);
          v60 = v26;
          v27 = 0i64;
          if ( v26 )
          {
            UFG::CollisionInstanceData::CollisionInstanceData((UFG::CollisionInstanceData *)v26);
            v29 = v28;
          }
          else
          {
            v29 = 0i64;
          }
          v29->mCollisionModelGuid = v8;
          v29->mInstanceGuid = v9->mName.mUID;
          v29->mSimObjectName.mUID = v9->mName.mUID;
          v29->mFlags = 0;
          v29->mPosition.m_quad = v20;
          v29->mOrientation.m_vec.m_quad = v25;
          v30 = UFG::RigidBodyComponent::operator new(0x1D8ui64);
          v60 = v30;
          if ( v30 )
          {
            UFG::RigidBodyComponent::RigidBodyComponent((UFG::RigidBodyComponent *)v30, v9, v29, 0x3000u, v2->boneIndex);
            v32 = v31;
          }
          else
          {
            v32 = 0i64;
          }
          UFG::qSafePointer<Creature,Creature>::operator=(
            (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)&v2->body,
            (UFG::SimComponent *)&v32->vfptr);
          LOBYTE(v33) = 1;
          v32->vfptr[15].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v32->vfptr, v33);
          UFG::RigidBody::SetCollisionLayer(
            v32,
            UFG::PhysicsCar::collisionLayer[v2->id],
            (unsigned __int16)v3->mSystemId,
            1,
            1);
          UFG::SimObjectModifier::SimObjectModifier(&v49, v3->mParams->mSimObject.m_pPointer, 1);
          UFG::SimObjectModifier::AttachComponent(&v49, (UFG::SimComponent *)&v32->vfptr, 0xFFFFFFFFi64);
          UFG::SimObjectModifier::Close(&v49);
          UFG::SimObjectModifier::~SimObjectModifier(&v49);
          UFG::qString::qString(&v53, UFG::PhysicsCar::bullet_geo_format[v2->id], v3->mParams->modelName.mData);
          v35 = v53.mStringHashUpper32;
          if ( v53.mStringHashUpper32 == -1 )
          {
            v35 = UFG::qStringHashUpper32(v53.mData, v53.mStringHashUpper32 | v34);
            v53.mStringHashUpper32 = v35;
          }
          v36 = UFG::BasePhysicsSystem::GetCollisionModel(UFG::BasePhysicsSystem::mInstance, v35);
          if ( v36 )
          {
            hkpRigidBodyCinfo::hkpRigidBodyCinfo(&info);
            info.m_collisionFilterInfo = 27;
            info.m_shape = (hkpShape *)v36[2].mNULL.mChild[1];
            v37 = v2->body.m_pPointer[2].m_pSimObject;
            info.m_position = *(hkVector4f *)&v37[3].m_SafePointerWithCallbackList.mNode.mNext;
            hkQuaternionf::set((hkQuaternionf *)&v49, (hkRotationf *)&v37[2].m_UnboundComponentHandles);
            info.m_rotation = *(hkQuaternionf *)&v49.mbOpen;
            info.m_motionType.m_storage = 5;
            v38 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
            v39 = ++*(_BYTE *)(v38 + 80);
            v40 = v39;
            *(_DWORD *)(v38 + 4 * v40) = 0;
            *(_QWORD *)(v38 + 8 * v40 + 16) = "hkpRigidBody";
            *(_QWORD *)(v38 + 8 * v40 + 48) = 0i64;
            v41 = *(_BYTE *)(v38 + 81);
            if ( v39 > v41 )
              v41 = v39;
            *(_BYTE *)(v38 + 81) = v41;
            v42 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
            v43 = (hkpRigidBody *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v42[11] + 8i64))(
                                    v42[11],
                                    720i64);
            v60 = v43;
            if ( v43 )
            {
              hkpRigidBody::hkpRigidBody(v43, &info);
              v27 = v45;
            }
            v2->bulletCollider = v27;
            HavokJobMemoryPoolTagger::onEndJob((HavokJobMemoryPoolTagger *)CustomHavokMemorySystem::mInstance, v44);
            v46 = UFG::qStringHashUpper32("BulletMopp", 0xFFFFFFFF);
            UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&transform);
            v48 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v47);
            transform.m_rotation.m_col1.m_quad.m128_u64[0] = UFG::qStringHash64(v48, 0xFFFFFFFFFFFFFFFFui64);
            UFG::PhysicsPropertyManager::GetObjectProperties(
              (UFG::qReflectHandle<UFG::PhysicsObjectProperties> *)&transform,
              v46,
              0);
            UFG::PhysicsPropertyManager::SetObjectPropertiesHandleUid(
              *(_QWORD *)(transform.m_rotation.m_col2.m_quad.m128_u64[0] + 8),
              (hkpWorldObject *)&v2->bulletCollider->vfptr);
            v2->bulletCollider->m_userData = (unsigned __int64)&v3->mUserData;
            UFG::BasePhysicsSystem::AddEntity(UFG::BasePhysicsSystem::mInstance, v2->bulletCollider, 1);
            UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&transform);
          }
          UFG::qString::~qString(&v53);
        }
        UFG::qString::~qString(&v53);
      }
    }
  }
}

// File Line: 963
// RVA: 0x454F20
hkpConstraintInstance *__fastcall UFG::PhysicsCar::AddMotorConstraint(UFG::PhysicsCar *this, hkpConstraintInstance *constraint, bool followingStrength)
{
  bool v3; // bp
  hkpConstraintInstance *v4; // rsi
  signed __int64 v5; // rbx
  char v6; // r9
  __int64 v7; // rax
  char v8; // cl
  _QWORD **v9; // rax
  hkpPositionConstraintMotor *v10; // rax
  __int64 v11; // rax
  __int64 v12; // rdi
  char v13; // al
  hkpConstraintInstance *v14; // rbx

  v3 = followingStrength;
  v4 = constraint;
  v5 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v6 = ++*(_BYTE *)(v5 + 80);
  v7 = v6;
  *(_DWORD *)(v5 + 4 * v7) = 3;
  *(_QWORD *)(v5 + 8 * v7 + 16) = "hkpPositionConstraintMotor";
  *(_QWORD *)(v5 + 8 * v7 + 48) = 0i64;
  v8 = *(_BYTE *)(v5 + 81);
  if ( v6 > v8 )
    v8 = v6;
  *(_BYTE *)(v5 + 81) = v8;
  v9 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v10 = (hkpPositionConstraintMotor *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v9[11] + 8i64))(
                                        v9[11],
                                        48i64);
  if ( v10 )
  {
    hkpPositionConstraintMotor::hkpPositionConstraintMotor(v10, 0.0);
    v12 = v11;
  }
  else
  {
    v12 = 0i64;
  }
  v13 = *(_BYTE *)(v5 + 80);
  if ( v13 > 0 )
  {
    *(_BYTE *)(v5 + 80) = v13 - 1;
  }
  else
  {
    *(_BYTE *)(v5 + 80) = 0;
    *(_DWORD *)v5 = 3;
    *(_QWORD *)(v5 + 16) = 0i64;
    *(_QWORD *)(v5 + 48) = 0i64;
  }
  if ( v3 )
  {
    *(_DWORD *)(v12 + 28) = 1176256512;
  }
  else
  {
    *(_DWORD *)(v12 + 28) = 1142292480;
    *(_DWORD *)(v12 + 32) = 1061997773;
    *(_DWORD *)(v12 + 40) = 0x40000000;
    *(_DWORD *)(v12 + 44) = 0x40000000;
    *(_DWORD *)(v12 + 36) = 1065353216;
  }
  v14 = hkpConstraintUtils::convertToPowered(v4, (hkpConstraintMotor *)v12, (hkBool)1);
  hkReferencedObject::removeReference((hkReferencedObject *)&v4->vfptr);
  hkReferencedObject::removeReference((hkReferencedObject *)v12);
  return v14;
}

// File Line: 991
// RVA: 0x45C0A0
void __fastcall UFG::PhysicsCar::CreateConstraintForAttachment(UFG::PhysicsCar *this, UFG::VehicleAttachment *attachment, bool motorize)
{
  bool v3; // r12
  UFG::VehicleAttachment *v4; // rdi
  UFG::PhysicsCar *v5; // r13
  UFG::SimObjectCVBase *v6; // rcx
  unsigned __int16 v7; // dx
  UFG::CharacterAnimationComponent *v8; // rax
  UFG::CharacterAnimationComponent *v9; // rsi
  UFG::TransformNodeComponent *v10; // rbx
  hkaPose *v11; // r8
  __int64 v12; // rdx
  hkQsTransformf *v13; // rax
  __m128 v14; // xmm6
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
  hkpRigidBody *v26; // r15
  signed __int64 v27; // rbx
  char v28; // dl
  __int64 v29; // rax
  hkpConstraintInstance *v30; // r14
  char v31; // cl
  _QWORD **v32; // rax
  hkpLimitedHingeConstraintData *v33; // rax
  hkJobType v34; // edx
  hkpLimitedHingeConstraintData *v35; // rax
  hkpLimitedHingeConstraintData *v36; // rsi
  __int64 v37; // rcx
  hkVector4f v38; // xmm2
  hkVector4f v39; // xmm1
  hkVector4f v40; // xmm0
  hkVector4f v41; // xmm2
  hkVector4f v42; // xmm0
  hkVector4f v43; // xmm3
  char v44; // dl
  __int64 v45; // rax
  char v46; // cl
  UFG::allocator::free_link *v47; // rax
  UFG::Constraint *v48; // rax
  UFG::Constraint *v49; // rbx
  _QWORD **v50; // rax
  hkpConstraintInstance *v51; // rax
  hkJobType v52; // edx
  hkpConstraintInstance *v53; // rax
  hkpEntity *entityA; // [rsp+40h] [rbp-88h]
  char axisB[24]; // [rsp+48h] [rbp-80h]
  __int128 v56; // [rsp+60h] [rbp-68h]
  hkVector4f pivotB; // [rsp+70h] [rbp-58h]
  hkVector4f axisA; // [rsp+88h] [rbp-40h]
  __int64 v59; // [rsp+98h] [rbp-30h]
  hkVector4f axisAPerp; // [rsp+A8h] [rbp-20h]
  hkVector4f axisBPerp; // [rsp+B8h] [rbp-10h]
  hkTransformf v62; // [rsp+C8h] [rbp+0h]
  hkTransformf a; // [rsp+108h] [rbp+40h]
  hkQsTransformf v64; // [rsp+148h] [rbp+80h]
  hkQsTransformf v65; // [rsp+178h] [rbp+B0h]
  hkTransformf transformOut; // [rsp+1A8h] [rbp+E0h]
  hkTransformf transform; // [rsp+1E8h] [rbp+120h]
  UFG::qSymbol _name[2]; // [rsp+2A8h] [rbp+1E0h]
  UFG::qSymbol result; // [rsp+2C0h] [rbp+1F8h]

  v59 = -2i64;
  v3 = motorize;
  v4 = attachment;
  v5 = this;
  v6 = (UFG::SimObjectCVBase *)this->mParams->mSimObject.m_pPointer;
  if ( v6 )
  {
    v7 = v6->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v8 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v6);
    }
    else if ( (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
        v8 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v6);
      else
        v8 = (UFG::CharacterAnimationComponent *)((v7 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                     (UFG::SimObjectGame *)&v6->vfptr,
                                                                     UFG::CharacterAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::CharacterAnimationComponent::_TypeUID));
    }
    else
    {
      v8 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v6);
    }
    v9 = v8;
    if ( v8 )
    {
      if ( v8->mCreature && v4->boneIndex != -1 && v4->body.m_pPointer )
      {
        v10 = v5->mParams->mSimObject.m_pPointer->m_pTransformNodeComponent;
        UFG::TransformNodeComponent::UpdateWorldTransform(v10);
        hkTransformf::set4x4ColumnMajor(&transform, &v10->mWorldTransform.v0.x);
        hkQsTransformf::setFromTransformNoScale(&v65, &transform);
        v11 = v9->mCreature->mPose.mHavokPose;
        v12 = v4->boneIndex;
        if ( v11->m_boneFlags.m_data[v12] & 2 )
          v13 = hkaPose::calculateBoneModelSpace(v9->mCreature->mPose.mHavokPose, v12);
        else
          v13 = &v11->m_modelPose.m_data[v12];
        v14 = v13->m_rotation.m_vec.m_quad;
        v15 = v13->m_scale.m_quad;
        v16 = _mm_shuffle_ps(v65.m_rotation.m_vec.m_quad, v65.m_rotation.m_vec.m_quad, 255);
        v17 = _mm_mul_ps(v65.m_rotation.m_vec.m_quad, v13->m_translation.m_quad);
        v18 = _mm_mul_ps(
                v65.m_rotation.m_vec.m_quad,
                _mm_add_ps(
                  _mm_shuffle_ps(v17, v17, 170),
                  _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0))));
        v19 = _mm_shuffle_ps(v65.m_rotation.m_vec.m_quad, v65.m_rotation.m_vec.m_quad, 201);
        v20 = _mm_sub_ps(
                _mm_mul_ps(
                  v65.m_rotation.m_vec.m_quad,
                  _mm_shuffle_ps(v13->m_translation.m_quad, v13->m_translation.m_quad, 201)),
                _mm_mul_ps(v13->m_translation.m_quad, v19));
        v21 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(v13->m_translation.m_quad, _mm_sub_ps(_mm_mul_ps(v16, v16), (__m128)xmmword_141A711B0)),
                  v18),
                _mm_mul_ps(_mm_shuffle_ps(v20, v20, 201), v16));
        v64.m_translation.m_quad = _mm_add_ps(v65.m_translation.m_quad, _mm_add_ps(v21, v21));
        v22 = _mm_shuffle_ps(v14, v14, 255);
        v23 = _mm_sub_ps(_mm_mul_ps(v65.m_rotation.m_vec.m_quad, _mm_shuffle_ps(v14, v14, 201)), _mm_mul_ps(v14, v19));
        v24 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v23, v23, 201), _mm_mul_ps(v14, v16)),
                _mm_mul_ps(v65.m_rotation.m_vec.m_quad, v22));
        v25 = _mm_mul_ps(v65.m_rotation.m_vec.m_quad, v14);
        v64.m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                        v24,
                                        _mm_unpackhi_ps(
                                          v24,
                                          _mm_sub_ps(
                                            _mm_mul_ps(v22, v16),
                                            _mm_add_ps(
                                              _mm_shuffle_ps(v25, v25, 170),
                                              _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0))))),
                                        196);
        v64.m_scale.m_quad = _mm_mul_ps(v65.m_scale.m_quad, v15);
        entityA = (hkpEntity *)v4->body.m_pPointer[2].m_pSimObject;
        v26 = v5->mRigidBody->mBody;
        v27 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
        v28 = ++*(_BYTE *)(v27 + 80);
        v29 = v28;
        *(_DWORD *)(v27 + 4 * v29) = 3;
        *(_QWORD *)(v27 + 8 * v29 + 16) = "hkpLimitedHingeConstraintData";
        v30 = 0i64;
        *(_QWORD *)(v27 + 8 * v29 + 48) = 0i64;
        v31 = *(_BYTE *)(v27 + 81);
        if ( v28 > v31 )
          v31 = v28;
        *(_BYTE *)(v27 + 81) = v31;
        v32 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v33 = (hkpLimitedHingeConstraintData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v32[11] + 8i64))(
                                                 v32[11],
                                                 304i64);
        *(_QWORD *)&_name[0].mUID = v33;
        if ( v33 )
        {
          hkpLimitedHingeConstraintData::hkpLimitedHingeConstraintData(v33);
          v36 = v35;
        }
        else
        {
          v36 = 0i64;
        }
        HavokJobMemoryPoolTagger::onEndJob((HavokJobMemoryPoolTagger *)CustomHavokMemorySystem::mInstance, v34);
        *(hkVector4f *)&axisB[8] = v64.m_translation;
        hkQsTransformf::copyToTransform(&v64, &transformOut);
        v37 = v4->id;
        v56 = *((_OWORD *)&transformOut.m_rotation.m_col0 + UFG::PhysicsCar::hinge_axis[v37]);
        pivotB.m_quad = (__m128)*((_OWORD *)&transformOut.m_rotation.m_col0 + UFG::PhysicsCar::perp_axis[v37]);
        v38.m_quad = (__m128)v26->m_motion.m_motionState.m_transform.m_rotation.m_col1;
        v39.m_quad = (__m128)v26->m_motion.m_motionState.m_transform.m_rotation.m_col2;
        v40.m_quad = (__m128)v26->m_motion.m_motionState.m_transform.m_translation;
        a.m_rotation.m_col0 = v26->m_motion.m_motionState.m_transform.m_rotation.m_col0;
        a.m_rotation.m_col1 = (hkVector4f)v38.m_quad;
        a.m_rotation.m_col2 = (hkVector4f)v39.m_quad;
        a.m_translation = (hkVector4f)v40.m_quad;
        v41.m_quad = (__m128)v26->m_motion.m_motionState.m_transform.m_rotation.m_col1;
        v42.m_quad = (__m128)v26->m_motion.m_motionState.m_transform.m_rotation.m_col2;
        v43.m_quad = (__m128)v26->m_motion.m_motionState.m_transform.m_translation;
        v62.m_rotation.m_col0 = v26->m_motion.m_motionState.m_transform.m_rotation.m_col0;
        v62.m_rotation.m_col1 = (hkVector4f)v41.m_quad;
        v62.m_rotation.m_col2 = (hkVector4f)v42.m_quad;
        v62.m_translation = (hkVector4f)v43.m_quad;
        hkVector4f::setTransformedInversePos((hkVector4f *)&axisB[16], &a, (hkVector4f *)&axisB[8]);
        hkVector4f::setRotatedInverseDir(&axisA, (hkMatrix3f *)&a.m_rotation.m_col0, (hkVector4f *)&v56);
        hkVector4f::setRotatedInverseDir(&axisAPerp, (hkMatrix3f *)&a.m_rotation.m_col0, &pivotB);
        hkVector4f::setTransformedInversePos((hkVector4f *)((char *)&pivotB + 8), &v62, (hkVector4f *)&axisB[8]);
        hkVector4f::setRotatedInverseDir((hkVector4f *)axisB, (hkMatrix3f *)&v62.m_rotation.m_col0, (hkVector4f *)&v56);
        hkVector4f::setRotatedInverseDir(&axisBPerp, (hkMatrix3f *)&v62.m_rotation.m_col0, &pivotB);
        hkpLimitedHingeConstraintData::setInBodySpace(
          v36,
          (hkVector4f *)&axisB[16],
          (hkVector4f *)((char *)&pivotB + 8),
          &axisA,
          (hkVector4f *)axisB,
          &axisAPerp,
          &axisBPerp);
        v36->m_atoms.m_angLimit.m_minAngle = UFG::PhysicsCar::min_angle[v4->id];
        v36->m_atoms.m_angLimit.m_maxAngle = UFG::PhysicsCar::max_angle[v4->id];
        v36->m_atoms.m_angFriction.m_maxFrictionTorque = UFG::PhysicsCar::max_friction_torque[v4->id];
        v44 = ++*(_BYTE *)(v27 + 80);
        v45 = v44;
        *(_DWORD *)(v27 + 4 * v45) = 3;
        *(_QWORD *)(v27 + 8 * v45 + 16) = "hkpConstraintInstance";
        *(_QWORD *)(v27 + 8 * v45 + 48) = 0i64;
        v46 = *(_BYTE *)(v27 + 81);
        if ( v44 > v46 )
          v46 = v44;
        *(_BYTE *)(v27 + 81) = v46;
        UFG::qSymbol::create_from_string(&result, "carAttachment");
        v47 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x60ui64, "Constraint", 0i64, 1u);
        *((_QWORD *)&v56 + 1) = v47;
        if ( v47 )
        {
          *(_QWORD *)axisB = _name;
          _name[0] = result;
          UFG::Constraint::Constraint((UFG::Constraint *)v47, (__int64)_name);
          v49 = v48;
        }
        else
        {
          v49 = 0i64;
        }
        v50 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v51 = (hkpConstraintInstance *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v50[11] + 8i64))(
                                         v50[11],
                                         112i64);
        *(_QWORD *)axisB = v51;
        if ( v51 )
        {
          hkpConstraintInstance::hkpConstraintInstance(
            v51,
            entityA,
            (hkpEntity *)&v26->vfptr,
            (hkpConstraintData *)&v36->vfptr,
            PRIORITY_PSI);
          v30 = v53;
        }
        v49->mConstraintInstance = v30;
        HavokJobMemoryPoolTagger::onEndJob((HavokJobMemoryPoolTagger *)CustomHavokMemorySystem::mInstance, v52);
        if ( v3 && UFG::PhysicsCar::hasMotor[v4->id] )
          v49->mConstraintInstance = UFG::PhysicsCar::AddMotorConstraint(
                                       v5,
                                       v49->mConstraintInstance,
                                       v4->desiredState == 4);
        hkReferencedObject::removeReference((hkReferencedObject *)&v36->vfptr);
        UFG::RigidBody::AddConstraint((UFG::RigidBody *)v4->body.m_pPointer, v49);
        UFG::BasePhysicsSystem::AddConstraint(UFG::BasePhysicsSystem::mInstance, v49->mConstraintInstance);
      }
    }
  }
}eReference((hkReferencedObject *)&v36->vfptr);
        UFG::RigidBody::AddConstraint((UFG::RigidBody *)v4->body.m_pPointer, v49);
        UFG::BasePhysicsSystem::AddConstrai

// File Line: 1075
// RVA: 0x4617C0
void __fastcall UFG::PhysicsCar::DestroyAttachment(UFG::PhysicsCar *this, UFG::VehicleAttachment *attachment)
{
  UFG::RigidBody *v2; // rcx
  UFG::VehicleAttachment *v3; // rbx
  hkpRigidBody *v4; // rdx
  UFG::AIVehicleAttachment *v5; // rcx

  v2 = (UFG::RigidBody *)attachment->body.m_pPointer;
  v3 = attachment;
  *(_WORD *)&attachment->currentState = 0;
  if ( v2 )
  {
    UFG::RigidBody::DeleteAllConstraints(v2);
    UFG::Simulation::DestroySimComponent(&UFG::gSim, v3->body.m_pPointer);
    v4 = v3->bulletCollider;
    if ( v4 )
    {
      UFG::BasePhysicsSystem::RemoveEntity(UFG::BasePhysicsSystem::mInstance, v4, 0);
      hkReferencedObject::removeReference((hkReferencedObject *)&v3->bulletCollider->vfptr);
      v3->bulletCollider = 0i64;
    }
  }
  v5 = v3->aiAttachment;
  if ( v5 )
    UFG::AIVehicleAttachment::Disable(v5);
}

// File Line: 1102
// RVA: 0x466220
signed __int64 __fastcall UFG::PhysicsCar::GetBoneIndexForAttachment(UFG::PhysicsCar *this, UFG::CharacterAnimationComponent *cac, UFG::VehicleAttachmentID id)
{
  Creature *v3; // rcx

  if ( !cac )
    return 0xFFFFFFFFi64;
  v3 = cac->mCreature;
  if ( !v3 )
    return 0xFFFFFFFFi64;
  if ( v3->mPose.mRigHandle.mData )
    return Skeleton::GetBoneID(v3->mPose.mRigHandle.mUFGSkeleton, UFG::PhysicsCar::attachment_bones[id].mUID);
  return 0xFFFFFFFFi64;
}

// File Line: 1129
// RVA: 0x468930
char __fastcall UFG::PhysicsCar::HasActiveAttachments(UFG::PhysicsCar *this)
{
  UFG::qNode<UFG::VehicleAttachment,UFG::VehicleAttachment> *v1; // rax
  UFG::qList<UFG::VehicleAttachment,UFG::VehicleAttachment,1,0> *v2; // rcx

  v1 = this->mAttachments.mNode.mNext;
  v2 = &this->mAttachments;
  if ( v1 == (UFG::qNode<UFG::VehicleAttachment,UFG::VehicleAttachment> *)v2 )
    return 0;
  while ( !BYTE6(v1[3].mNext) )
  {
    v1 = v1->mNext;
    if ( v1 == (UFG::qNode<UFG::VehicleAttachment,UFG::VehicleAttachment> *)v2 )
      return 0;
  }
  return 1;
}

