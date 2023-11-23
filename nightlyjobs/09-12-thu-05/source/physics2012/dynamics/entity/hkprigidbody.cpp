// File Line: 51
// RVA: 0xD637D0
void __fastcall estimateAllowedPenetrationDepth(
        hkpCollidable *collidable,
        const float allowedPenetrationDepth,
        hkVector4f *extent)
{
  float v3; // xmm2_4

  v3 = fmin(
         _mm_shuffle_ps(extent->m_quad, extent->m_quad, 170).m128_f32[0],
         fmin(
           _mm_shuffle_ps(extent->m_quad, extent->m_quad, 85).m128_f32[0],
           _mm_shuffle_ps(extent->m_quad, extent->m_quad, 0).m128_f32[0]));
  if ( v3 >= 0.5 )
    collidable->m_allowedPenetrationDepth = 0.1;
  else
    collidable->m_allowedPenetrationDepth = 0.2 * v3;
}

// File Line: 73
// RVA: 0xD62DD0
void __fastcall hkpRigidBody::updateCachedShapeInfo(hkpRigidBody *this, hkpShape *shape, hkVector4f *extentOut)
{
  __m128 v5; // xmm3
  __m128 v6; // xmm2
  hkVector4f v7; // xmm1
  __m128 v8; // xmm2
  __m128 v9; // xmm3
  __m128 v10; // xmm2
  __m128 v11; // xmm3
  __m128 v12; // xmm4
  __m128 v13; // xmm1
  __m128 v14; // [rsp+20h] [rbp-28h] BYREF
  __m128 v15; // [rsp+30h] [rbp-18h]

  ((void (__fastcall *)(hkpShape *, hkVector4f *, hkVector4f *, __m128 *))shape->vfptr[2].__vecDelDtor)(
    shape,
    &transform,
    extentOut,
    &v14);
  v5 = v15;
  v6 = v14;
  extentOut->m_quad = _mm_sub_ps(v15, v14);
  v7.m_quad = (__m128)this->m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal;
  v8 = _mm_sub_ps(v6, v7.m_quad);
  v9 = _mm_sub_ps(v5, v7.m_quad);
  v10 = _mm_mul_ps(v8, v8);
  v11 = _mm_mul_ps(v9, v9);
  v12 = _mm_max_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
            _mm_shuffle_ps(v11, v11, 170)),
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)),
            _mm_shuffle_ps(v10, v10, 170)));
  v13 = _mm_rsqrt_ps(v12);
  LODWORD(this->m_motion.m_motionState.m_objectRadius) = _mm_andnot_ps(
                                                           _mm_cmple_ps(v12, (__m128)0i64),
                                                           _mm_mul_ps(
                                                             _mm_mul_ps(
                                                               _mm_sub_ps(
                                                                 (__m128)_xmm,
                                                                 _mm_mul_ps(_mm_mul_ps(v12, v13), v13)),
                                                               _mm_mul_ps(*(__m128 *)_xmm, v13)),
                                                             v12)).m128_u32[0];
}

// File Line: 100
// RVA: 0xD63470
void __fastcall hkpRigidBody::createDynamicRigidMotion(
        hkpMotion::MotionType motionType,
        hkVector4f *position,
        hkQuaternionf *rotation,
        float mass,
        hkMatrix3f *inertiaLocal,
        hkVector4f *centreOfMassLocal,
        float maxLinearVelocity,
        float maxAngularVelocity,
        hkpThinBoxMotion *motionBufferOut)
{
  hkpThinBoxMotion *v10; // rbx
  hkpThinBoxMotion *v11; // rax
  hkpThinBoxMotion *v12; // rax
  __m128 v13; // xmm5
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  hkpThinBoxMotion *v17; // rax
  hkpThinBoxMotion *v18; // rax

  switch ( motionType )
  {
    case MOTION_DYNAMIC:
      v13 = _mm_or_ps(
              _mm_andnot_ps(
                (__m128)xmmword_141A9A140,
                _mm_or_ps(
                  _mm_and_ps(inertiaLocal->m_col1.m_quad, (__m128)xmmword_141A9A120),
                  _mm_andnot_ps((__m128)xmmword_141A9A120, inertiaLocal->m_col0.m_quad))),
              _mm_and_ps(inertiaLocal->m_col2.m_quad, (__m128)xmmword_141A9A140));
      LODWORD(v14) = _mm_shuffle_ps(v13, v13, 0).m128_u32[0];
      LODWORD(v15) = _mm_shuffle_ps(v13, v13, 170).m128_u32[0];
      LODWORD(v16) = _mm_shuffle_ps(v13, v13, 85).m128_u32[0];
      if ( fmin(v15, fmin(v16, v14)) <= (float)(fmax(v15, fmax(v16, v14))
                                              * _mm_shuffle_ps(
                                                  (__m128)LODWORD(FLOAT_0_80000001),
                                                  (__m128)LODWORD(FLOAT_0_80000001),
                                                  0).m128_f32[0]) )
        goto $LN10_149;
      goto $LN11_128;
    case MOTION_SPHERE_INERTIA:
$LN11_128:
      v10 = motionBufferOut;
      if ( !motionBufferOut )
        goto LABEL_16;
      hkpMotion::hkpMotion(motionBufferOut, position, rotation, 0);
      v10->m_type.m_storage = 2;
      v10->vfptr = (hkBaseObjectVtbl *)&hkpSphereMotion::`vftable;
      break;
    case MOTION_BOX_INERTIA:
$LN10_149:
      if ( !motionBufferOut )
        goto LABEL_16;
      hkpBoxMotion::hkpBoxMotion(motionBufferOut, position, rotation);
      v10 = v11;
      break;
    case MOTION_KEYFRAMED:
      maxLinearVelocity = 1000000.0;
      maxAngularVelocity = 1000000.0;
      if ( !motionBufferOut )
        goto LABEL_16;
      hkpKeyframedRigidMotion::hkpKeyframedRigidMotion((hkpKeyframedRigidMotion *)motionBufferOut, position, rotation);
      v10 = v17;
      break;
    case MOTION_THIN_BOX_INERTIA:
      if ( !motionBufferOut )
        goto LABEL_16;
      hkpThinBoxMotion::hkpThinBoxMotion(motionBufferOut, position, rotation);
      v10 = v12;
      break;
    case MOTION_CHARACTER:
      v10 = motionBufferOut;
      if ( !motionBufferOut )
        goto LABEL_16;
      hkpMotion::hkpMotion(motionBufferOut, position, rotation, 0);
      v10->m_type.m_storage = 7;
      v10->vfptr = (hkBaseObjectVtbl *)&hkpCharacterMotion::`vftable;
      break;
    default:
      if ( motionBufferOut )
      {
        hkpFixedRigidMotion::hkpFixedRigidMotion((hkpFixedRigidMotion *)motionBufferOut, position, rotation);
        v10 = v18;
      }
      else
      {
LABEL_16:
        v10 = 0i64;
      }
      break;
  }
  if ( motionType != MOTION_KEYFRAMED )
  {
    ((void (__fastcall *)(hkpThinBoxMotion *, hkMatrix3f *))v10->vfptr[4].__first_virtual_table_function__)(
      v10,
      inertiaLocal);
    ((void (__fastcall *)(hkpThinBoxMotion *, hkVector4f *))v10->vfptr[6].__first_virtual_table_function__)(
      v10,
      centreOfMassLocal);
    ((void (__fastcall *)(hkpThinBoxMotion *))v10->vfptr[2].__vecDelDtor)(v10);
  }
  hkUFloat8::operator=(&v10->m_motionState.m_maxLinearVelocity, &maxLinearVelocity);
  hkUFloat8::operator=(&v10->m_motionState.m_maxAngularVelocity, &maxAngularVelocity);
  v10->m_savedQualityTypeIndex = 0;
}

// File Line: 207
// RVA: 0xD62120
void __fastcall hkpRigidBody::hkpRigidBody(hkpRigidBody *this, hkpRigidBodyCinfo *info)
{
  hkLocalFrame *m_localFrame; // rbx
  hkLocalFrame *m_pntr; // rcx
  char m_storage; // cl
  hkpMotion *v7; // rax
  hkpMotion *v8; // rbx
  float m_allowedPenetrationDepth; // xmm0_4
  hkpShape *m_shape; // rdx
  float v11; // xmm1_4
  char v12; // al
  char m_numShapeKeysInContactPointProperties; // al
  hkVector4f extentOut; // [rsp+50h] [rbp-38h] BYREF
  float v15; // [rsp+90h] [rbp+8h]
  float v16; // [rsp+90h] [rbp+8h]
  float v17; // [rsp+90h] [rbp+8h]
  float v18; // [rsp+90h] [rbp+8h]
  float v19; // [rsp+90h] [rbp+8h]

  hkpEntity::hkpEntity(this, info->m_shape);
  this->vfptr = (hkBaseObjectVtbl *)&hkpRigidBody::`vftable;
  this->m_material.m_responseType.m_storage = info->m_collisionResponse.m_storage;
  this->m_contactPointCallbackDelay = info->m_contactPointCallbackDelay;
  this->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo = info->m_collisionFilterInfo;
  m_localFrame = info->m_localFrame;
  if ( m_localFrame )
    hkReferencedObject::addReference(info->m_localFrame);
  m_pntr = this->m_localFrame.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_localFrame.m_pntr = m_localFrame;
  m_storage = info->m_motionType.m_storage;
  if ( m_storage == 5 )
  {
    if ( this == (hkpRigidBody *)-336i64 )
    {
      v8 = 0i64;
    }
    else
    {
      hkpFixedRigidMotion::hkpFixedRigidMotion(
        (hkpFixedRigidMotion *)&this->m_motion,
        &info->m_position,
        &info->m_rotation);
      v8 = v7;
    }
    hkUFloat8::operator=(&v8->m_motionState.m_maxLinearVelocity, &info->m_maxLinearVelocity);
    hkUFloat8::operator=(&v8->m_motionState.m_maxAngularVelocity, &info->m_maxAngularVelocity);
    hkpMotion::setDeactivationClass(v8, 1);
    this->m_collidable.m_motion = &this->m_motion.m_motionState;
    m_allowedPenetrationDepth = info->m_allowedPenetrationDepth;
    if ( m_allowedPenetrationDepth > 0.0 )
      this->m_collidable.m_allowedPenetrationDepth = m_allowedPenetrationDepth;
    else
      this->m_collidable.m_allowedPenetrationDepth = 3.40282e38;
  }
  else
  {
    hkpRigidBody::createDynamicRigidMotion(
      (hkpMotion::MotionType)m_storage,
      &info->m_position,
      &info->m_rotation,
      info->m_mass,
      &info->m_inertiaTensor,
      &info->m_centerOfMass,
      info->m_maxLinearVelocity,
      info->m_maxAngularVelocity,
      &this->m_motion);
    hkpMotion::setDeactivationClass(&this->m_motion, info->m_solverDeactivation.m_storage);
    hkpEntity::activate(this);
    this->m_motion.hkpEntity::vfptr[9].__vecDelDtor(&this->m_motion, (unsigned int)&info->m_linearVelocity);
    hkpEntity::activate(this);
    ((void (__fastcall *)(hkpMaxSizeMotion *, hkVector4f *))this->m_motion.hkpEntity::vfptr[9].__first_virtual_table_function__)(
      &this->m_motion,
      &info->m_angularVelocity);
    this->m_collidable.m_motion = &this->m_motion.m_motionState;
    this->m_collidable.m_allowedPenetrationDepth = info->m_allowedPenetrationDepth;
  }
  hkpRigidBody::enableDeactivation(this, info->m_enableDeactivation.m_bool != 0);
  m_shape = this->m_collidable.m_shape;
  v15 = info->m_linearDamping * 1.0039062;
  this->m_motion.m_motionState.m_linearDamping.m_value = HIWORD(v15);
  v16 = info->m_angularDamping * 1.0039062;
  this->m_motion.m_motionState.m_angularDamping.m_value = HIWORD(v16);
  v17 = info->m_timeFactor * 1.0039062;
  this->m_motion.m_motionState.m_timeFactor.m_value = HIWORD(v17);
  if ( m_shape )
  {
    hkpRigidBody::updateCachedShapeInfo(this, m_shape, &extentOut);
    v11 = this->m_collidable.m_allowedPenetrationDepth;
    if ( v11 <= 0.0 )
      estimateAllowedPenetrationDepth(&this->m_collidable, v11, &extentOut);
  }
  v12 = info->m_qualityType.m_storage;
  if ( v12 == -1 )
  {
    if ( this->m_motion.m_type.m_storage == 5 )
    {
      this->m_collidable.m_broadPhaseHandle.m_objectQualityType = 0;
      goto LABEL_21;
    }
    v12 = (info->m_motionType.m_storage != 4) + 1;
  }
  this->m_collidable.m_broadPhaseHandle.m_objectQualityType = v12;
LABEL_21:
  this->m_autoRemoveLevel = info->m_autoRemoveLevel;
  if ( info->m_forceCollideOntoPpu.m_bool )
    this->m_collidable.m_forceCollideOntoPpu |= 1u;
  this->m_material.m_friction = info->m_friction;
  v18 = info->m_rollingFrictionMultiplier * 1.0039062;
  this->m_material.m_rollingFrictionMultiplier.m_value = HIWORD(v18);
  this->m_material.m_restitution = info->m_restitution;
  v19 = info->m_gravityFactor * 1.0039062;
  this->m_motion.m_gravityFactor.m_value = HIWORD(v19);
  m_numShapeKeysInContactPointProperties = info->m_numShapeKeysInContactPointProperties;
  if ( m_numShapeKeysInContactPointProperties < 0 )
    m_numShapeKeysInContactPointProperties = hkpShapeDepthUtil::getShapeDepth(info->m_shape);
  this->m_numShapeKeysInContactPointProperties = m_numShapeKeysInContactPointProperties;
  this->m_responseModifierFlags = info->m_responseModifierFlags;
}

// File Line: 341
// RVA: 0xD626E0
void __fastcall hkpRigidBody::hkpRigidBody(hkpRigidBody *this, hkFinishLoadedObjectFlag flag)
{
  hkpEntity::hkpEntity(this, flag);
  this->vfptr = (hkBaseObjectVtbl *)&hkpRigidBody::`vftable;
}

// File Line: 346
// RVA: 0xD624A0
void __fastcall hkpRigidBody::~hkpRigidBody(hkpRigidBody *this)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkpRigidBody::`vftable;
  hkpEntity::~hkpEntity(this);
}

// File Line: 351
// RVA: 0xD624C0
void __fastcall hkpRigidBody::getCinfo(hkpRigidBody *this, hkpRigidBodyCinfo *info)
{
  unsigned __int16 EncodedFloat; // ax
  float v5; // xmm6_4
  float v6; // xmm0_4
  unsigned __int16 v7; // ax

  info->m_forceCollideOntoPpu.m_bool = this->m_collidable.m_forceCollideOntoPpu & 1;
  info->m_autoRemoveLevel = this->m_autoRemoveLevel;
  info->m_numShapeKeysInContactPointProperties = this->m_numShapeKeysInContactPointProperties;
  info->m_contactPointCallbackDelay = this->m_contactPointCallbackDelay;
  info->m_enableDeactivation.m_bool = hkpRigidBody::isDeactivationEnabled(this);
  info->m_localFrame = this->m_localFrame.m_pntr;
  info->m_friction = this->m_material.m_friction;
  LODWORD(info->m_rollingFrictionMultiplier) = this->m_material.m_rollingFrictionMultiplier.m_value << 16;
  info->m_collisionResponse.m_storage = this->m_material.m_responseType.m_storage;
  info->m_restitution = this->m_material.m_restitution;
  LODWORD(info->m_linearDamping) = this->m_motion.m_motionState.m_linearDamping.m_value << 16;
  LODWORD(info->m_angularDamping) = this->m_motion.m_motionState.m_angularDamping.m_value << 16;
  info->m_linearVelocity = this->m_motion.m_linearVelocity;
  info->m_angularVelocity = this->m_motion.m_angularVelocity;
  info->m_mass = hkpMotion::getMass(&this->m_motion);
  ((void (__fastcall *)(hkpMaxSizeMotion *, hkMatrix3f *))this->m_motion.hkpEntity::vfptr[3].__first_virtual_table_function__)(
    &this->m_motion,
    &info->m_inertiaTensor);
  info->m_motionType.m_storage = this->m_motion.m_type.m_storage;
  info->m_solverDeactivation.m_storage = this->m_motion.m_motionState.m_deactivationClass;
  EncodedFloat = hkUFloat8::getEncodedFloat(this->m_motion.m_motionState.m_maxLinearVelocity.m_value);
  v5 = 0.0;
  if ( EncodedFloat )
    LODWORD(v6) = (EncodedFloat + 243712) << 12;
  else
    v6 = 0.0;
  info->m_maxLinearVelocity = v6;
  v7 = hkUFloat8::getEncodedFloat(this->m_motion.m_motionState.m_maxAngularVelocity.m_value);
  if ( v7 )
    LODWORD(v5) = (v7 + 243712) << 12;
  info->m_maxAngularVelocity = v5;
  info->m_position = this->m_motion.m_motionState.m_transform.m_translation;
  info->m_rotation = this->m_motion.m_motionState.m_sweptTransform.m_rotation1;
  info->m_centerOfMass = this->m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal;
  info->m_shape = this->m_collidable.m_shape;
  info->m_collisionFilterInfo = this->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo;
  info->m_allowedPenetrationDepth = this->m_collidable.m_allowedPenetrationDepth;
  info->m_qualityType.m_storage = this->m_collidable.m_broadPhaseHandle.m_objectQualityType;
  LODWORD(info->m_gravityFactor) = this->m_motion.m_gravityFactor.m_value << 16;
}

// File Line: 417
// RVA: 0xD637C0
hkMotionState *__fastcall hkpRigidBody::getMotionState(hkpRigidBody *this)
{
  return &this->m_motion.m_motionState;
}

// File Line: 423
// RVA: 0xD631B0
hkpRigidBody *__fastcall hkpRigidBody::clone(hkpRigidBody *this)
{
  _QWORD **Value; // rax
  hkpRigidBody *v3; // rax
  hkpWorldObject *v4; // rax
  hkpWorldObject *v5; // rdi
  hkpMaxSizeMotion *p_m_motion; // rax
  int v7; // esi
  int i; // ecx
  hkReferencedObject v9; // xmm0
  _QWORD **v10; // rax
  hkpMotion *v11; // rax
  hkpMotion *v12; // rbx
  unsigned __int16 m_memSizeAndFlags; // cx
  __int16 m_referenceCount; // dx
  hkpMaxSizeMotion *m_savedMotion; // rax
  hkpBreakableBody *m_breakableBody; // rcx
  hkpRigidBodyCinfo info; // [rsp+20h] [rbp-E8h] BYREF

  hkpRigidBodyCinfo::hkpRigidBodyCinfo(&info);
  hkpRigidBody::getCinfo(this, &info);
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkpRigidBody *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 720i64);
  if ( v3 )
  {
    hkpRigidBody::hkpRigidBody(v3, &info);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  p_m_motion = &this->m_motion;
  v7 = 20;
  for ( i = 20; i > 0; --i )
  {
    v9 = p_m_motion->hkReferencedObject;
    p_m_motion = (hkpMaxSizeMotion *)((char *)p_m_motion + 16);
    *(hkReferencedObject *)((char *)p_m_motion + (char *)v5 - (char *)this - 16) = v9;
  }
  if ( this->m_motion.m_savedMotion )
  {
    v10 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v11 = (hkpMotion *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v10[11] + 8i64))(v10[11], 320i64);
    v12 = v11;
    if ( v11 )
    {
      hkpMotion::hkpMotion(v11);
      v12->m_savedMotion = 0i64;
      v12->vfptr = (hkBaseObjectVtbl *)&hkpMaxSizeMotion::`vftable;
    }
    else
    {
      v12 = 0i64;
    }
    v5[3].m_collidable.m_shape = (hkpShape *)v12;
    m_memSizeAndFlags = v12->m_memSizeAndFlags;
    m_referenceCount = v12->m_referenceCount;
    m_savedMotion = this->m_motion.m_savedMotion;
    do
    {
      --v7;
      v12 = (hkpMotion *)((char *)v12 + 16);
      *(hkReferencedObject *)&v12[-1].m_savedQualityTypeIndex = m_savedMotion->hkReferencedObject;
      m_savedMotion = (hkpMaxSizeMotion *)((char *)m_savedMotion + 16);
    }
    while ( v7 > 0 );
    v5[3].m_collidable.m_shape->m_memSizeAndFlags = m_memSizeAndFlags;
    v5[3].m_collidable.m_shape->m_referenceCount = m_referenceCount;
  }
  v5->m_collidable.m_motion = (const void *)((__int64 (__fastcall *)(hkpWorldObject *))v5->vfptr[2].__first_virtual_table_function__)(v5);
  hkpWorldObject::copyProperties(v5, this);
  hkStringPtr::operator=(
    &v5->m_name,
    (const char *)((unsigned __int64)this->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64));
  v5->m_userData = this->m_userData;
  m_breakableBody = this->m_breakableBody;
  if ( m_breakableBody )
    v5[1].m_collidable.m_shape = (hkpShape *)((__int64 (__fastcall *)(hkpBreakableBody *, hkpWorldObject *))m_breakableBody->vfptr[1].__first_virtual_table_function__)(
                                               m_breakableBody,
                                               v5);
  return (hkpRigidBody *)v5;
}

// File Line: 474
// RVA: 0xD62D20
void __fastcall hkpRigidBody::setMotionType(
        hkpRigidBody *this,
        hkpMotion::MotionType newState,
        hkpEntityActivation preferredActivationState,
        hkpUpdateCollisionFilterOnEntityMode collisionFilterUpdateMode)
{
  hkpWorld *m_world; // rcx
  hkpWorld *v6; // rcx
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-28h] BYREF
  hkpRigidBody *v8; // [rsp+28h] [rbp-20h]
  char v9; // [rsp+30h] [rbp-18h]
  char v10; // [rsp+31h] [rbp-17h]
  char v11; // [rsp+32h] [rbp-16h]

  m_world = this->m_world;
  if ( m_world && m_world->m_criticalOperationsLockCount )
  {
    v9 = newState;
    operation.m_type.m_storage = 4;
    v8 = this;
    v10 = preferredActivationState;
    v11 = collisionFilterUpdateMode;
    hkpWorld::queueOperation(m_world, &operation);
  }
  else
  {
    hkpWorldOperationUtil::setRigidBodyMotionType(this, newState, preferredActivationState, collisionFilterUpdateMode);
    v6 = this->m_world;
    if ( v6 )
      hkpWorldCallbackUtil::fireEntitySetMotionType(v6, this);
    hkpEntityCallbackUtil::fireEntitySetMotionType(this);
  }
}

// File Line: 512
// RVA: 0xD62EF0
__int64 __fastcall hkpRigidBody::setShape(hkpRigidBody *this, hkpShape *shape)
{
  hkpWorld *m_world; // rax
  hkpShape *m_shape; // rsi
  float m_allowedPenetrationDepth; // xmm1_4
  hkpWorld *v8; // rdx
  hkpWorld *v9; // rcx
  hkpWorld *v10; // rcx
  hkpWorld *v11; // rbx
  hkVector4f operation; // [rsp+20h] [rbp-28h] BYREF
  hkpShape *v14; // [rsp+30h] [rbp-18h]

  m_world = this->m_world;
  if ( m_world && m_world->m_criticalOperationsLockCount )
  {
    v14 = shape;
    operation.m_quad.m128_u64[1] = (unsigned __int64)this;
    operation.m_quad.m128_i8[0] = 5;
    hkpWorld::queueOperation(m_world, (hkWorldOperation::BaseOperation *)&operation);
    return 0i64;
  }
  else
  {
    if ( m_world )
    {
      ++m_world->m_criticalOperationsLockCount;
      hkpWorldOperationUtil::removeEntityBP(this->m_world, this);
    }
    m_shape = this->m_collidable.m_shape;
    this->m_collidable.m_shape = shape;
    hkReferencedObject::addReference(shape);
    if ( m_shape )
      hkReferencedObject::removeReference(m_shape);
    hkpRigidBody::updateCachedShapeInfo(this, shape, &operation);
    if ( m_shape && 3.40282e38 != this->m_collidable.m_allowedPenetrationDepth )
      this->m_collidable.m_allowedPenetrationDepth = -1.0;
    m_allowedPenetrationDepth = this->m_collidable.m_allowedPenetrationDepth;
    if ( m_allowedPenetrationDepth <= 0.0 )
      estimateAllowedPenetrationDepth(&this->m_collidable, m_allowedPenetrationDepth, &operation);
    v8 = this->m_world;
    if ( v8 )
      hkpEntity::setCachedShapeData(this, v8, shape);
    v9 = this->m_world;
    if ( v9 )
      hkpWorldCallbackUtil::fireEntityShapeSet(v9, this);
    hkpEntityCallbackUtil::fireEntityShapeSet(this);
    v10 = this->m_world;
    if ( v10 )
    {
      hkpWorldOperationUtil::addEntityBP(v10, this);
      v11 = this->m_world;
      if ( v11->m_criticalOperationsLockCount-- == 1 && !v11->m_blockExecutingPendingOperations.m_bool )
      {
        if ( v11->m_pendingOperationsCount )
          hkpWorld::internal_executePendingOperations(v11);
        if ( v11->m_pendingOperationQueueCount == 1 )
        {
          if ( v11->m_pendingBodyOperationsCount )
            hkpWorld::internal_executePendingBodyOperations(v11);
        }
      }
    }
    return 1i64;
  }
}

// File Line: 593
// RVA: 0xD63070
__int64 __fastcall hkpRigidBody::updateShape(hkpRigidBody *this, hkpShapeModifier *shapeModifier)
{
  hkpWorld *m_world; // rax
  hkpShape *m_shape; // rdi
  hkpWorld *v6; // r9
  hkpWorld *v7; // rdi
  bool v8; // zf
  hkVector4f operation; // [rsp+30h] [rbp-28h] BYREF
  hkpShapeModifier *v10; // [rsp+40h] [rbp-18h]
  hkpRigidBody *v11; // [rsp+60h] [rbp+8h] BYREF

  m_world = this->m_world;
  if ( m_world && m_world->m_criticalOperationsLockCount )
  {
    v10 = shapeModifier;
    operation.m_quad.m128_u64[1] = (unsigned __int64)this;
    operation.m_quad.m128_i8[0] = 6;
    hkpWorld::queueOperation(m_world, (hkWorldOperation::BaseOperation *)&operation);
    return 0i64;
  }
  else
  {
    if ( m_world )
      ++m_world->m_criticalOperationsLockCount;
    m_shape = this->m_collidable.m_shape;
    if ( shapeModifier )
      shapeModifier->vfptr->modifyShape(shapeModifier, m_shape);
    hkpRigidBody::updateCachedShapeInfo(this, m_shape, &operation);
    if ( this->m_world )
    {
      this->m_collidable.m_boundingVolumeData.m_min[0] = 1;
      this->m_collidable.m_boundingVolumeData.m_max[0] = 0;
      if ( this->m_motion.m_type.m_storage == 5 )
      {
        v6 = this->m_world;
        v11 = this;
        ((void (__fastcall *)(hkpSimulation *, hkpRigidBody **, __int64))v6->m_simulation->vfptr[6].__vecDelDtor)(
          v6->m_simulation,
          &v11,
          1i64);
        hkpWorldOperationUtil::updateEntityBP(this->m_world, this);
      }
      v7 = this->m_world;
      v8 = v7->m_criticalOperationsLockCount-- == 1;
      if ( v8 && !v7->m_blockExecutingPendingOperations.m_bool )
      {
        if ( v7->m_pendingOperationsCount )
          hkpWorld::internal_executePendingOperations(v7);
        if ( v7->m_pendingOperationQueueCount == 1 )
        {
          if ( v7->m_pendingBodyOperationsCount )
            hkpWorld::internal_executePendingBodyOperations(v7);
        }
      }
      hkpWorldCallbackUtil::fireEntityShapeSet(this->m_world, this);
    }
    hkpEntityCallbackUtil::fireEntityShapeSet(this);
    return 1i64;
  }
}

// File Line: 656
// RVA: 0xD62790
void __fastcall hkpRigidBody::setCenterOfMassLocal(hkpRigidBody *this, hkVector4f *centerOfMass)
{
  hkVector4f extentOut; // [rsp+20h] [rbp-18h] BYREF

  ((void (__fastcall *)(hkpMaxSizeMotion *, hkVector4f *))this->m_motion.hkpEntity::vfptr[6].__first_virtual_table_function__)(
    &this->m_motion,
    centerOfMass);
  hkpRigidBody::updateCachedShapeInfo(this, this->m_collidable.m_shape, &extentOut);
}

// File Line: 666
// RVA: 0xD62BF0
void __fastcall hkpRigidBody::enableDeactivation(hkpRigidBody *this, bool _enableDeactivation)
{
  hkpWorld *m_world; // rax
  int m_deactivationIntegrateCounter; // r10d
  __int16 v5; // dx
  __int16 v6; // r8
  int v7; // r9d
  unsigned __int8 v8; // al
  __int16 v9; // r8
  __int16 v10; // dx
  __int64 v11; // rax
  char v12; // cl
  bool v13; // zf
  __int16 v14; // ax

  if ( _enableDeactivation )
  {
    if ( !hkpRigidBody::isDeactivationEnabled(this) )
    {
      m_world = this->m_world;
      if ( m_world )
      {
        m_deactivationIntegrateCounter = (unsigned __int8)m_world->m_dynamicsStepInfo.m_solverInfo.m_deactivationIntegrateCounter;
        v5 = (unsigned __int8)m_world->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag[1];
        v6 = (unsigned __int8)m_world->m_dynamicsStepInfo.m_solverInfo.m_deactivationNumInactiveFramesSelectFlag[0];
        v7 = this->m_uid & 0xF;
        v8 = m_world->m_dynamicsStepInfo.m_solverInfo.m_deactivationIntegrateCounter & 3;
        this->m_motion.m_deactivationIntegrateCounter = v7;
        if ( v8 < (unsigned __int8)(v7 & 3) )
          v6 = ~v6;
        v9 = v6 << 14;
        if ( m_deactivationIntegrateCounter < v7 )
          v5 = ~v5;
        this->m_motion.m_deactivationNumInactiveFrames[0] &= 0x3FFFu;
        this->m_motion.m_deactivationNumInactiveFrames[0] |= v9;
        this->m_motion.m_deactivationNumInactiveFrames[1] &= 0x3FFFu;
        this->m_motion.m_deactivationNumInactiveFrames[1] |= v5 << 14;
      }
      else
      {
        v10 = 0;
        v11 = this->m_uid & 0xF;
        this->m_motion.m_deactivationIntegrateCounter = v11;
        v12 = v11;
        v13 = (v11 & 3) == 0;
        v14 = 0;
        if ( !v13 )
          v14 = -16384;
        if ( v12 )
          v10 = -16384;
        this->m_motion.m_deactivationNumInactiveFrames[0] &= 0x3FFFu;
        this->m_motion.m_deactivationNumInactiveFrames[0] |= v14;
        this->m_motion.m_deactivationNumInactiveFrames[1] &= 0x3FFFu;
        this->m_motion.m_deactivationNumInactiveFrames[1] |= v10;
      }
    }
  }
  else
  {
    this->m_motion.m_deactivationIntegrateCounter = -1;
    *(_DWORD *)this->m_motion.m_deactivationNumInactiveFrames = 0;
  }
}

// File Line: 696
// RVA: 0xD62D00
bool __fastcall hkpRigidBody::isDeactivationEnabled(hkpRigidBody *this)
{
  return this->m_motion.m_deactivationIntegrateCounter != -1;
}

// File Line: 701
// RVA: 0xD62D90
hkpMaxSizeMotion *__fastcall hkpRigidBody::getStoredDynamicMotion(hkpRigidBody *this)
{
  if ( (unsigned __int8)(this->m_motion.m_type.m_storage - 4) <= 1u )
    return this->m_motion.m_savedMotion;
  else
    return 0i64;
}

// File Line: 714
// RVA: 0xD62DB0
hkpMaxSizeMotion *__fastcall hkpRigidBody::getStoredDynamicMotion(hkpRigidBody *this)
{
  if ( (unsigned __int8)(this->m_motion.m_type.m_storage - 4) <= 1u )
    return this->m_motion.m_savedMotion;
  else
    return 0i64;
}

// File Line: 736
// RVA: 0xD636A0
void __fastcall hkpRigidBody::updateBroadphaseAndResetCollisionInformationOfWarpedBody(hkpEntity *entity)
{
  hkpWorld *m_world; // rbx
  hkpSimulation *m_simulation; // rcx
  bool v4; // zf
  hkWorldOperation::BaseOperation operation; // [rsp+30h] [rbp-18h] BYREF
  hkpEntity *v6; // [rsp+38h] [rbp-10h]
  hkBool result; // [rsp+50h] [rbp+8h] BYREF
  hkpEntity *entities; // [rsp+58h] [rbp+10h] BYREF

  m_world = entity->m_world;
  if ( m_world )
  {
    if ( m_world->m_criticalOperationsLockCount )
    {
      v6 = entity;
      operation.m_type.m_storage = 23;
      hkpWorld::queueOperation(m_world, &operation);
    }
    else
    {
      entities = entity;
      m_simulation = m_world->m_simulation;
      m_world->m_criticalOperationsLockCount = 1;
      ((void (__fastcall *)(hkpSimulation *, hkpEntity **, __int64, hkpWorld *, int))m_simulation->vfptr[6].__vecDelDtor)(
        m_simulation,
        &entities,
        1i64,
        m_world,
        7);
      if ( entity->m_collidable.m_shape )
        hkpSimulation::collideEntitiesBroadPhaseDiscrete(&entities, 1, m_world);
      if ( !hkpEntity::isActive(entity, &result)->m_bool )
      {
        if ( m_world->m_shouldActivateOnRigidBodyTransformChange.m_bool && entity->m_motion.m_type.m_storage != 5 )
          hkpEntity::activate(entity);
        hkpWorldCallbackUtil::fireInactiveEntityMoved(m_world, entity);
      }
      v4 = m_world->m_criticalOperationsLockCount-- == 1;
      if ( v4 && !m_world->m_blockExecutingPendingOperations.m_bool )
      {
        if ( m_world->m_pendingOperationsCount )
          hkpWorld::internal_executePendingOperations(m_world);
        if ( m_world->m_pendingOperationQueueCount == 1 )
        {
          if ( m_world->m_pendingBodyOperationsCount )
            hkpWorld::internal_executePendingBodyOperations(m_world);
        }
      }
    }
  }
}

// File Line: 803
// RVA: 0xD627D0
void __fastcall hkpRigidBody::setPosition(hkpRigidBody *this, hkVector4f *position)
{
  this->m_motion.hkpEntity::vfptr[7].__vecDelDtor(&this->m_motion, (unsigned int)position);
  hkpRigidBody::updateBroadphaseAndResetCollisionInformationOfWarpedBody(this);
}

// File Line: 814
// RVA: 0xD62800
void __fastcall hkpRigidBody::setRotation(hkpRigidBody *this, hkQuaternionf *rotation)
{
  ((void (__fastcall *)(hkpMaxSizeMotion *, hkQuaternionf *))this->m_motion.hkpEntity::vfptr[7].__first_virtual_table_function__)(
    &this->m_motion,
    rotation);
  hkpRigidBody::updateBroadphaseAndResetCollisionInformationOfWarpedBody(this);
}

// File Line: 827
// RVA: 0xD62830
void __fastcall hkpRigidBody::setPositionAndRotation(hkpRigidBody *this, hkVector4f *position, hkQuaternionf *rotation)
{
  ((void (__fastcall *)(hkpMaxSizeMotion *, hkVector4f *, hkQuaternionf *))this->m_motion.hkpEntity::vfptr[8].__vecDelDtor)(
    &this->m_motion,
    position,
    rotation);
  hkpRigidBody::updateBroadphaseAndResetCollisionInformationOfWarpedBody(this);
}

// File Line: 842
// RVA: 0xD62860
void __fastcall hkpRigidBody::setTransform(hkpRigidBody *this, hkTransformf *transform)
{
  ((void (__fastcall *)(hkpMaxSizeMotion *, hkTransformf *))this->m_motion.hkpEntity::vfptr[8].__first_virtual_table_function__)(
    &this->m_motion,
    transform);
  hkpRigidBody::updateBroadphaseAndResetCollisionInformationOfWarpedBody(this);
}

// File Line: 852
// RVA: 0xD62710
void __fastcall hkpRigidBody::setMass(hkpRigidBody *this, float m)
{
  ((void (__fastcall *)(hkpMaxSizeMotion *))this->m_motion.hkpEntity::vfptr[2].__vecDelDtor)(&this->m_motion);
}

// File Line: 860
// RVA: 0xD62730
void __fastcall hkpRigidBody::setMassInv(hkpRigidBody *this, float mInv)
{
  ((void (__fastcall *)(hkpMaxSizeMotion *))this->m_motion.hkpEntity::vfptr[3].__vecDelDtor)(&this->m_motion);
}

// File Line: 868
// RVA: 0xD62EA0
void __fastcall hkpRigidBody::setFriction(hkpRigidBody *this, float newFriction)
{
  this->m_material.m_friction = newFriction;
}

// File Line: 876
// RVA: 0xD62EB0
void __fastcall hkpRigidBody::setRollingFrictionMultiplier(hkpRigidBody *this, float multiplier)
{
  float v2; // [rsp+10h] [rbp+10h]

  v2 = multiplier * 1.0039062;
  this->m_material.m_rollingFrictionMultiplier.m_value = HIWORD(v2);
}

// File Line: 889
// RVA: 0xD62EE0
void __fastcall hkpRigidBody::setRestitution(hkpRigidBody *this, float newRestitution)
{
  this->m_material.m_restitution = newRestitution;
}

// File Line: 898
// RVA: 0xD62750
void __fastcall hkpRigidBody::setInertiaLocal(hkpRigidBody *this, hkMatrix3f *inertia)
{
  ((void (__fastcall *)(hkpMaxSizeMotion *, hkMatrix3f *))this->m_motion.hkpEntity::vfptr[4].__first_virtual_table_function__)(
    &this->m_motion,
    inertia);
}

// File Line: 908
// RVA: 0xD62770
void __fastcall hkpRigidBody::setInertiaInvLocal(hkpRigidBody *this, hkMatrix3f *inertiaInv)
{
  this->m_motion.hkpEntity::vfptr[5].__vecDelDtor(&this->m_motion, (unsigned int)inertiaInv);
}

// File Line: 915
// RVA: 0xD62890
void __fastcall hkpRigidBody::setPositionAndRotationAsCriticalOperation(
        hkpRigidBody *this,
        hkVector4f *position,
        hkQuaternionf *rotation)
{
  hkpWorld *m_world; // rax
  _QWORD **Value; // rax
  hkQuaternionf *v8; // rax
  __m128 m_quad; // xmm0
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-28h] BYREF
  hkpRigidBody *v11; // [rsp+28h] [rbp-20h]
  hkQuaternionf *v12; // [rsp+30h] [rbp-18h]

  m_world = this->m_world;
  if ( m_world && m_world->m_criticalOperationsLockCount )
  {
    v11 = this;
    operation.m_type.m_storage = 25;
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v8 = (hkQuaternionf *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 32i64);
    m_quad = position->m_quad;
    v12 = v8;
    *v8 = (hkQuaternionf)m_quad;
    v12[1] = (hkQuaternionf)rotation->m_vec.m_quad;
    hkpWorld::queueOperation(this->m_world, &operation);
  }
  else
  {
    hkpRigidBody::setPositionAndRotation(this, position, rotation);
  }
}

// File Line: 935
// RVA: 0xD62930
void __fastcall hkpRigidBody::setLinearVelocityAsCriticalOperation(hkpRigidBody *this, hkVector4f *newVel)
{
  hkpWorld *m_world; // rcx
  __m128 m_quad; // xmm0
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-28h] BYREF
  hkpRigidBody *v7; // [rsp+28h] [rbp-20h]
  unsigned __int64 v8; // [rsp+30h] [rbp-18h]
  unsigned int v9; // [rsp+38h] [rbp-10h]

  m_world = this->m_world;
  if ( m_world && m_world->m_criticalOperationsLockCount )
  {
    m_quad = newVel->m_quad;
    operation.m_type.m_storage = 26;
    v7 = this;
    v8 = m_quad.m128_u64[0];
    v9 = _mm_movehl_ps(m_quad, m_quad).m128_u32[0];
    hkpWorld::queueOperation(m_world, &operation);
  }
  else
  {
    hkpEntity::activate(this);
    this->m_motion.hkpEntity::vfptr[9].__vecDelDtor(&this->m_motion, (unsigned int)newVel);
  }
}

// File Line: 952
// RVA: 0xD629B0
void __fastcall hkpRigidBody::setAngularVelocityAsCriticalOperation(hkpRigidBody *this, hkVector4f *newVel)
{
  hkpWorld *m_world; // rcx
  __m128 m_quad; // xmm0
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-28h] BYREF
  hkpRigidBody *v7; // [rsp+28h] [rbp-20h]
  unsigned __int64 v8; // [rsp+30h] [rbp-18h]
  unsigned int v9; // [rsp+38h] [rbp-10h]

  m_world = this->m_world;
  if ( m_world && m_world->m_criticalOperationsLockCount )
  {
    m_quad = newVel->m_quad;
    operation.m_type.m_storage = 27;
    v7 = this;
    v8 = m_quad.m128_u64[0];
    v9 = _mm_movehl_ps(m_quad, m_quad).m128_u32[0];
    hkpWorld::queueOperation(m_world, &operation);
  }
  else
  {
    hkpEntity::activate(this);
    ((void (__fastcall *)(hkpMaxSizeMotion *, hkVector4f *))this->m_motion.hkpEntity::vfptr[9].__first_virtual_table_function__)(
      &this->m_motion,
      newVel);
  }
}

// File Line: 969
// RVA: 0xD62A30
void __fastcall hkpRigidBody::applyLinearImpulseAsCriticalOperation(hkpRigidBody *this, hkVector4f *imp)
{
  hkpWorld *m_world; // rcx
  __m128 m_quad; // xmm0
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-28h] BYREF
  hkpRigidBody *v7; // [rsp+28h] [rbp-20h]
  unsigned __int64 v8; // [rsp+30h] [rbp-18h]
  unsigned int v9; // [rsp+38h] [rbp-10h]

  m_world = this->m_world;
  if ( m_world && m_world->m_criticalOperationsLockCount )
  {
    m_quad = imp->m_quad;
    operation.m_type.m_storage = 28;
    v7 = this;
    v8 = m_quad.m128_u64[0];
    v9 = _mm_movehl_ps(m_quad, m_quad).m128_u32[0];
    hkpWorld::queueOperation(m_world, &operation);
  }
  else
  {
    hkpEntity::activate(this);
    this->m_motion.hkpEntity::vfptr[11].__vecDelDtor(&this->m_motion, (unsigned int)imp);
  }
}

// File Line: 986
// RVA: 0xD62AB0
void __fastcall hkpRigidBody::applyPointImpulseAsCriticalOperation(hkpRigidBody *this, hkVector4f *imp, hkVector4f *p)
{
  hkpWorld *m_world; // rax
  _QWORD **Value; // rax
  hkVector4f *v8; // rax
  __m128 m_quad; // xmm0
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-28h] BYREF
  hkpRigidBody *v11; // [rsp+28h] [rbp-20h]
  hkVector4f *v12; // [rsp+30h] [rbp-18h]

  m_world = this->m_world;
  if ( m_world && m_world->m_criticalOperationsLockCount )
  {
    v11 = this;
    operation.m_type.m_storage = 29;
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v8 = (hkVector4f *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 32i64);
    m_quad = p->m_quad;
    v12 = v8;
    *v8 = (hkVector4f)m_quad;
    v12[1] = (hkVector4f)imp->m_quad;
    hkpWorld::queueOperation(this->m_world, &operation);
  }
  else
  {
    hkpEntity::activate(this);
    ((void (__fastcall *)(hkpMaxSizeMotion *, hkVector4f *, hkVector4f *))this->m_motion.hkpEntity::vfptr[11].__first_virtual_table_function__)(
      &this->m_motion,
      imp,
      p);
  }
}

// File Line: 1006
// RVA: 0xD62B70
void __fastcall hkpRigidBody::applyAngularImpulseAsCriticalOperation(hkpRigidBody *this, hkVector4f *imp)
{
  hkpWorld *m_world; // rcx
  __m128 m_quad; // xmm0
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-28h] BYREF
  hkpRigidBody *v7; // [rsp+28h] [rbp-20h]
  unsigned __int64 v8; // [rsp+30h] [rbp-18h]
  unsigned int v9; // [rsp+38h] [rbp-10h]

  m_world = this->m_world;
  if ( m_world && m_world->m_criticalOperationsLockCount )
  {
    m_quad = imp->m_quad;
    operation.m_type.m_storage = 30;
    v7 = this;
    v8 = m_quad.m128_u64[0];
    v9 = _mm_movehl_ps(m_quad, m_quad).m128_u32[0];
    hkpWorld::queueOperation(m_world, &operation);
  }
  else
  {
    hkpEntity::activate(this);
    this->m_motion.hkpEntity::vfptr[12].__vecDelDtor(&this->m_motion, (unsigned int)imp);
  }
}

// File Line: 1023
// RVA: 0xD63360
hkBool *__fastcall hkpRigidBody::checkPerformance(hkpRigidBody *this, hkBool *result)
{
  hkpShape *m_shape; // r14
  unsigned int m_storage; // ebx
  bool v7; // di
  int v8; // eax
  __int64 v9; // rax

  m_shape = this->m_collidable.m_shape;
  if ( !m_shape )
  {
    result->m_bool = 0;
    return result;
  }
  m_storage = (unsigned __int8)m_shape->m_type.m_storage;
  v7 = 1;
  if ( (unsigned __int8)(this->m_motion.m_type.m_storage - 4) > 1u && m_storage <= 0x16 )
  {
    v8 = 4391552;
    if ( _bittest(&v8, m_storage) )
    {
      v9 = ((__int64 (__fastcall *)(hkpShape *))m_shape->vfptr[7].__vecDelDtor)(this->m_collidable.m_shape);
      v7 = (*(int (__fastcall **)(__int64))(*(_QWORD *)v9 + 8i64))(v9) <= 100;
    }
  }
  if ( m_storage != 27 )
  {
    if ( (m_storage == 18 || m_storage == 6)
      && ((int (__fastcall *)(hkpShape *))this->m_collidable.m_shape[1].vfptr->__first_virtual_table_function__)(&this->m_collidable.m_shape[1]) > 100 )
    {
      v7 = 0;
    }
    if ( m_storage != 14 )
    {
      if ( m_storage == 8
        && ((int (__fastcall *)(hkpShape *))m_shape[1].vfptr->__first_virtual_table_function__)(&m_shape[1]) > 100 )
      {
        v7 = 0;
      }
      goto LABEL_18;
    }
    goto LABEL_9;
  }
  if ( ((int (__fastcall *)(hkpShape *))this->m_collidable.m_shape[1].vfptr->__first_virtual_table_function__)(&this->m_collidable.m_shape[1]) > 100 )
LABEL_9:
    v7 = 0;
LABEL_18:
  result->m_bool = v7;
  return result;
}

