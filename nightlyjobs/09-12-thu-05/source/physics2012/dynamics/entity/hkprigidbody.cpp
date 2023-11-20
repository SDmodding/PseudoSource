// File Line: 51
// RVA: 0xD637D0
void __fastcall estimateAllowedPenetrationDepth(hkpCollidable *collidable, const float allowedPenetrationDepth, hkVector4f *extent)
{
  float v3; // xmm2_4

  v3 = fmin(
         COERCE_FLOAT(_mm_shuffle_ps(extent->m_quad, extent->m_quad, 170)),
         fmin(
           COERCE_FLOAT(_mm_shuffle_ps(extent->m_quad, extent->m_quad, 85)),
           COERCE_FLOAT(_mm_shuffle_ps(extent->m_quad, extent->m_quad, 0))));
  if ( v3 >= 0.5 )
    collidable->m_allowedPenetrationDepth = 0.1;
  else
    collidable->m_allowedPenetrationDepth = 0.2 * v3;
}

// File Line: 73
// RVA: 0xD62DD0
void __fastcall hkpRigidBody::updateCachedShapeInfo(hkpRigidBody *this, hkpShape *shape, hkVector4f *extentOut)
{
  hkpRigidBody *v3; // rdi
  hkVector4f *v4; // rbx
  __m128 v5; // xmm3
  __m128 v6; // xmm2
  __m128 v7; // xmm1
  __m128 v8; // xmm2
  __m128 v9; // xmm3
  __m128 v10; // xmm2
  __m128 v11; // xmm3
  __m128 v12; // xmm4
  __m128 v13; // xmm1
  __m128 v14; // [rsp+20h] [rbp-28h]
  __m128 v15; // [rsp+30h] [rbp-18h]

  v3 = this;
  v4 = extentOut;
  ((void (__fastcall *)(hkpShape *, hkVector4f *, hkVector4f *, __m128 *))shape->vfptr[2].__vecDelDtor)(
    shape,
    &transform,
    extentOut,
    &v14);
  v5 = v15;
  v6 = v14;
  v4->m_quad = _mm_sub_ps(v15, v14);
  v7 = v3->m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal.m_quad;
  v8 = _mm_sub_ps(v6, v7);
  v9 = _mm_sub_ps(v5, v7);
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
  LODWORD(v3->m_motion.m_motionState.m_objectRadius) = (unsigned __int128)_mm_andnot_ps(
                                                                            _mm_cmpleps(v12, (__m128)0i64),
                                                                            _mm_mul_ps(
                                                                              _mm_mul_ps(
                                                                                _mm_sub_ps(
                                                                                  (__m128)_xmm,
                                                                                  _mm_mul_ps(_mm_mul_ps(v12, v13), v13)),
                                                                                _mm_mul_ps(*(__m128 *)_xmm, v13)),
                                                                              v12));
}

// File Line: 100
// RVA: 0xD63470
void __fastcall hkpRigidBody::createDynamicRigidMotion(hkpMotion::MotionType motionType, hkVector4f *position, hkQuaternionf *rotation, float mass, hkMatrix3f *inertiaLocal, hkVector4f *centreOfMassLocal, float maxLinearVelocity, float maxAngularVelocity, hkpMaxSizeMotion *motionBufferOut)
{
  hkpMotion::MotionType v9; // edi
  hkpMaxSizeMotion *v10; // rbx
  hkpMaxSizeMotion *v11; // rax
  hkpMaxSizeMotion *v12; // rax
  __m128 v13; // xmm5
  float v14; // xmm3_4
  float v15; // xmm1_4
  hkpMaxSizeMotion *v16; // rax
  hkpMaxSizeMotion *v17; // rax

  v9 = motionType;
  switch ( motionType )
  {
    case 1:
      v13 = _mm_or_ps(
              _mm_andnot_ps(
                (__m128)xmmword_141A9A140,
                _mm_or_ps(
                  _mm_and_ps(inertiaLocal->m_col1.m_quad, (__m128)xmmword_141A9A120),
                  _mm_andnot_ps((__m128)xmmword_141A9A120, inertiaLocal->m_col0.m_quad))),
              _mm_and_ps(inertiaLocal->m_col2.m_quad, (__m128)xmmword_141A9A140));
      LODWORD(v14) = (unsigned __int128)_mm_shuffle_ps(v13, v13, 85);
      LODWORD(v15) = (unsigned __int128)_mm_shuffle_ps(v13, v13, 0);
      v13.m128_i32[0] = (unsigned __int128)_mm_shuffle_ps(v13, v13, 170);
      if ( fmin(v13.m128_f32[0], fmin(v14, v15)) <= (float)(fmax(v13.m128_f32[0], fmax(v14, v15))
                                                          * COERCE_FLOAT(
                                                              _mm_shuffle_ps(
                                                                (__m128)LODWORD(FLOAT_0_80000001),
                                                                (__m128)LODWORD(FLOAT_0_80000001),
                                                                0))) )
        goto $LN10_149;
      goto $LN11_128;
    case 2:
$LN11_128:
      v10 = motionBufferOut;
      if ( !motionBufferOut )
        goto LABEL_16;
      hkpMotion::hkpMotion((hkpMotion *)&motionBufferOut->vfptr, position, rotation, 0);
      v10->m_type.m_storage = 2;
      v10->vfptr = (hkBaseObjectVtbl *)&hkpSphereMotion::`vftable';
      break;
    case 3:
$LN10_149:
      if ( !motionBufferOut )
        goto LABEL_16;
      hkpBoxMotion::hkpBoxMotion((hkpBoxMotion *)motionBufferOut, position, rotation);
      v10 = v11;
      break;
    case 4:
      maxLinearVelocity = 1000000.0;
      maxAngularVelocity = 1000000.0;
      if ( !motionBufferOut )
        goto LABEL_16;
      hkpKeyframedRigidMotion::hkpKeyframedRigidMotion(
        (hkpKeyframedRigidMotion *)&motionBufferOut->vfptr,
        position,
        rotation);
      v10 = v16;
      break;
    case 6:
      if ( !motionBufferOut )
        goto LABEL_16;
      hkpThinBoxMotion::hkpThinBoxMotion((hkpThinBoxMotion *)motionBufferOut, position, rotation);
      v10 = v12;
      break;
    case 7:
      v10 = motionBufferOut;
      if ( !motionBufferOut )
        goto LABEL_16;
      hkpMotion::hkpMotion((hkpMotion *)&motionBufferOut->vfptr, position, rotation, 0);
      v10->m_type.m_storage = 7;
      v10->vfptr = (hkBaseObjectVtbl *)&hkpCharacterMotion::`vftable';
      break;
    default:
      if ( motionBufferOut )
      {
        hkpFixedRigidMotion::hkpFixedRigidMotion((hkpFixedRigidMotion *)motionBufferOut, position, rotation);
        v10 = v17;
      }
      else
      {
LABEL_16:
        v10 = 0i64;
      }
      break;
  }
  if ( v9 != 4 )
  {
    ((void (__fastcall *)(hkpMaxSizeMotion *, hkMatrix3f *))v10->vfptr[4].__first_virtual_table_function__)(
      v10,
      inertiaLocal);
    ((void (__fastcall *)(hkpMaxSizeMotion *, hkVector4f *))v10->vfptr[6].__first_virtual_table_function__)(
      v10,
      centreOfMassLocal);
    ((void (__fastcall *)(hkpMaxSizeMotion *))v10->vfptr[2].__vecDelDtor)(v10);
  }
  hkUFloat8::operator=(&v10->m_motionState.m_maxLinearVelocity, &maxLinearVelocity);
  hkUFloat8::operator=(&v10->m_motionState.m_maxAngularVelocity, &maxAngularVelocity);
  v10->m_savedQualityTypeIndex = 0;
}

// File Line: 207
// RVA: 0xD62120
void __fastcall hkpRigidBody::hkpRigidBody(hkpRigidBody *this, hkpRigidBodyCinfo *info)
{
  hkpRigidBodyCinfo *v2; // rsi
  hkpRigidBody *v3; // rdi
  hkLocalFrame *v4; // rbx
  hkReferencedObject *v5; // rcx
  char v6; // cl
  hkpMotion *v7; // rax
  hkpMotion *v8; // rbx
  float v9; // xmm0_4
  hkpShape *v10; // rdx
  float v11; // xmm1_4
  char v12; // al
  char v13; // al
  hkVector4f extentOut; // [rsp+50h] [rbp-38h]
  float v15; // [rsp+90h] [rbp+8h]
  float v16; // [rsp+90h] [rbp+8h]
  float v17; // [rsp+90h] [rbp+8h]
  float v18; // [rsp+90h] [rbp+8h]
  float v19; // [rsp+90h] [rbp+8h]

  v2 = info;
  v3 = this;
  hkpEntity::hkpEntity((hkpEntity *)&this->vfptr, info->m_shape);
  v3->vfptr = (hkBaseObjectVtbl *)&hkpRigidBody::`vftable';
  v3->m_material.m_responseType.m_storage = v2->m_collisionResponse.m_storage;
  v3->m_contactPointCallbackDelay = v2->m_contactPointCallbackDelay;
  v3->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo = v2->m_collisionFilterInfo;
  v4 = v2->m_localFrame;
  if ( v4 )
    hkReferencedObject::addReference((hkReferencedObject *)&v2->m_localFrame->vfptr);
  v5 = (hkReferencedObject *)&v3->m_localFrame.m_pntr->vfptr;
  if ( v5 )
    hkReferencedObject::removeReference(v5);
  v3->m_localFrame.m_pntr = v4;
  v6 = v2->m_motionType.m_storage;
  if ( v6 == 5 )
  {
    if ( v3 == (hkpRigidBody *)-336i64 )
    {
      v8 = 0i64;
    }
    else
    {
      hkpFixedRigidMotion::hkpFixedRigidMotion((hkpFixedRigidMotion *)&v3->m_motion, &v2->m_position, &v2->m_rotation);
      v8 = v7;
    }
    hkUFloat8::operator=(&v8->m_motionState.m_maxLinearVelocity, &v2->m_maxLinearVelocity);
    hkUFloat8::operator=(&v8->m_motionState.m_maxAngularVelocity, &v2->m_maxAngularVelocity);
    hkpMotion::setDeactivationClass(v8, 1);
    v3->m_collidable.m_motion = &v3->m_motion.m_motionState;
    v9 = v2->m_allowedPenetrationDepth;
    if ( v9 > 0.0 )
      v3->m_collidable.m_allowedPenetrationDepth = v9;
    else
      v3->m_collidable.m_allowedPenetrationDepth = 3.40282e38;
  }
  else
  {
    hkpRigidBody::createDynamicRigidMotion(
      (hkpMotion::MotionType)v6,
      &v2->m_position,
      &v2->m_rotation,
      v2->m_mass,
      &v2->m_inertiaTensor,
      &v2->m_centerOfMass,
      v2->m_maxLinearVelocity,
      v2->m_maxAngularVelocity,
      &v3->m_motion);
    hkpMotion::setDeactivationClass((hkpMotion *)&v3->m_motion.vfptr, v2->m_solverDeactivation.m_storage);
    hkpEntity::activate((hkpEntity *)&v3->vfptr);
    v3->m_motion.vfptr[9].__vecDelDtor((hkBaseObject *)&v3->m_motion.vfptr, (unsigned int)&v2->m_linearVelocity);
    hkpEntity::activate((hkpEntity *)&v3->vfptr);
    ((void (__fastcall *)(hkpMaxSizeMotion *, hkVector4f *))v3->m_motion.vfptr[9].__first_virtual_table_function__)(
      &v3->m_motion,
      &v2->m_angularVelocity);
    v3->m_collidable.m_motion = &v3->m_motion.m_motionState;
    v3->m_collidable.m_allowedPenetrationDepth = v2->m_allowedPenetrationDepth;
  }
  hkpRigidBody::enableDeactivation(v3, v2->m_enableDeactivation.m_bool != 0);
  v10 = v3->m_collidable.m_shape;
  v15 = v2->m_linearDamping * 1.0039062;
  v3->m_motion.m_motionState.m_linearDamping.m_value = HIWORD(v15);
  v16 = v2->m_angularDamping * 1.0039062;
  v3->m_motion.m_motionState.m_angularDamping.m_value = HIWORD(v16);
  v17 = v2->m_timeFactor * 1.0039062;
  v3->m_motion.m_motionState.m_timeFactor.m_value = HIWORD(v17);
  if ( v10 )
  {
    hkpRigidBody::updateCachedShapeInfo(v3, v10, &extentOut);
    v11 = v3->m_collidable.m_allowedPenetrationDepth;
    if ( v11 <= 0.0 )
      estimateAllowedPenetrationDepth((hkpCollidable *)&v3->m_collidable.m_shape, v11, &extentOut);
  }
  v12 = v2->m_qualityType.m_storage;
  if ( v12 == -1 )
  {
    if ( v3->m_motion.m_type.m_storage == 5 )
    {
      v3->m_collidable.m_broadPhaseHandle.m_objectQualityType = 0;
      goto LABEL_21;
    }
    v12 = (v2->m_motionType.m_storage != 4) + 1;
  }
  v3->m_collidable.m_broadPhaseHandle.m_objectQualityType = v12;
LABEL_21:
  v3->m_autoRemoveLevel = v2->m_autoRemoveLevel;
  if ( v2->m_forceCollideOntoPpu.m_bool )
    v3->m_collidable.m_forceCollideOntoPpu |= 1u;
  v3->m_material.m_friction = v2->m_friction;
  v18 = v2->m_rollingFrictionMultiplier * 1.0039062;
  v3->m_material.m_rollingFrictionMultiplier.m_value = HIWORD(v18);
  v3->m_material.m_restitution = v2->m_restitution;
  v19 = v2->m_gravityFactor * 1.0039062;
  v3->m_motion.m_gravityFactor.m_value = HIWORD(v19);
  v13 = v2->m_numShapeKeysInContactPointProperties;
  if ( v13 < 0 )
    v13 = hkpShapeDepthUtil::getShapeDepth(v2->m_shape);
  v3->m_numShapeKeysInContactPointProperties = v13;
  v3->m_responseModifierFlags = v2->m_responseModifierFlags;
}

// File Line: 341
// RVA: 0xD626E0
void __fastcall hkpRigidBody::hkpRigidBody(hkpRigidBody *this, hkFinishLoadedObjectFlag flag)
{
  hkpRigidBody *v2; // rbx

  v2 = this;
  hkpEntity::hkpEntity((hkpEntity *)&this->vfptr, flag);
  v2->vfptr = (hkBaseObjectVtbl *)&hkpRigidBody::`vftable';
}

// File Line: 346
// RVA: 0xD624A0
void __fastcall hkpRigidBody::~hkpRigidBody(hkpRigidBody *this)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkpRigidBody::`vftable';
  hkpEntity::~hkpEntity((hkpEntity *)&this->vfptr);
}

// File Line: 351
// RVA: 0xD624C0
void __fastcall hkpRigidBody::getCinfo(hkpRigidBody *this, hkpRigidBodyCinfo *info)
{
  hkpRigidBodyCinfo *v2; // rdi
  hkpRigidBody *v3; // rsi
  unsigned __int16 v4; // ax
  int v5; // xmm6_4
  int v6; // xmm0_4
  unsigned __int16 v7; // ax

  v2 = info;
  v3 = this;
  info->m_forceCollideOntoPpu.m_bool = this->m_collidable.m_forceCollideOntoPpu & 1;
  info->m_autoRemoveLevel = this->m_autoRemoveLevel;
  info->m_numShapeKeysInContactPointProperties = this->m_numShapeKeysInContactPointProperties;
  info->m_contactPointCallbackDelay = this->m_contactPointCallbackDelay;
  info->m_enableDeactivation.m_bool = hkpRigidBody::isDeactivationEnabled(this);
  v2->m_localFrame = v3->m_localFrame.m_pntr;
  v2->m_friction = v3->m_material.m_friction;
  LODWORD(v2->m_rollingFrictionMultiplier) = v3->m_material.m_rollingFrictionMultiplier.m_value << 16;
  v2->m_collisionResponse.m_storage = v3->m_material.m_responseType.m_storage;
  v2->m_restitution = v3->m_material.m_restitution;
  LODWORD(v2->m_linearDamping) = v3->m_motion.m_motionState.m_linearDamping.m_value << 16;
  LODWORD(v2->m_angularDamping) = v3->m_motion.m_motionState.m_angularDamping.m_value << 16;
  v2->m_linearVelocity = v3->m_motion.m_linearVelocity;
  v2->m_angularVelocity = v3->m_motion.m_angularVelocity;
  v2->m_mass = hkpMotion::getMass((hkpMotion *)&v3->m_motion.vfptr);
  ((void (__fastcall *)(hkpMaxSizeMotion *, hkMatrix3f *))v3->m_motion.vfptr[3].__first_virtual_table_function__)(
    &v3->m_motion,
    &v2->m_inertiaTensor);
  v2->m_motionType.m_storage = v3->m_motion.m_type.m_storage;
  v2->m_solverDeactivation.m_storage = v3->m_motion.m_motionState.m_deactivationClass;
  v4 = hkUFloat8::getEncodedFloat(v3->m_motion.m_motionState.m_maxLinearVelocity.m_value);
  v5 = 0;
  if ( v4 )
    v6 = (v4 + 243712) << 12;
  else
    v6 = 0;
  LODWORD(v2->m_maxLinearVelocity) = v6;
  v7 = hkUFloat8::getEncodedFloat(v3->m_motion.m_motionState.m_maxAngularVelocity.m_value);
  if ( v7 )
    v5 = (v7 + 243712) << 12;
  LODWORD(v2->m_maxAngularVelocity) = v5;
  v2->m_position = v3->m_motion.m_motionState.m_transform.m_translation;
  v2->m_rotation = v3->m_motion.m_motionState.m_sweptTransform.m_rotation1;
  v2->m_centerOfMass = v3->m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal;
  v2->m_shape = v3->m_collidable.m_shape;
  v2->m_collisionFilterInfo = v3->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo;
  v2->m_allowedPenetrationDepth = v3->m_collidable.m_allowedPenetrationDepth;
  v2->m_qualityType.m_storage = v3->m_collidable.m_broadPhaseHandle.m_objectQualityType;
  LODWORD(v2->m_gravityFactor) = v3->m_motion.m_gravityFactor.m_value << 16;
}

// File Line: 417
// RVA: 0xD637C0
hkMotionState *__fastcall hkpRigidBody::getMotionState(hkpRigidBody *this)
{
  return &this->m_motion.m_motionState;
}

// File Line: 423
// RVA: 0xD631B0
hkpWorldObject *__fastcall hkpRigidBody::clone(hkpRigidBody *this)
{
  hkpRigidBody *v1; // rbp
  _QWORD **v2; // rax
  hkpRigidBody *v3; // rax
  hkpWorldObject *v4; // rax
  hkpWorldObject *v5; // rdi
  hkpMaxSizeMotion *v6; // rax
  signed int v7; // esi
  signed int v8; // ecx
  __int128 v9; // xmm0
  _QWORD **v10; // rax
  hkpMotion *v11; // rax
  hkpMotion *v12; // rbx
  unsigned __int16 v13; // cx
  __int16 v14; // dx
  hkpMaxSizeMotion *v15; // rax
  hkpBreakableBody *v16; // rcx
  hkpRigidBodyCinfo info; // [rsp+20h] [rbp-E8h]

  v1 = this;
  hkpRigidBodyCinfo::hkpRigidBodyCinfo(&info);
  hkpRigidBody::getCinfo(v1, &info);
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkpRigidBody *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(v2[11], 720i64);
  if ( v3 )
  {
    hkpRigidBody::hkpRigidBody(v3, &info);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  v6 = &v1->m_motion;
  v7 = 20;
  v8 = 20;
  do
  {
    v9 = *(_OWORD *)&v6->vfptr;
    --v8;
    v6 = (hkpMaxSizeMotion *)((char *)v6 + 16);
    *(_OWORD *)((char *)v6 + (char *)v5 - (char *)v1 - 16) = v9;
  }
  while ( v8 > 0 );
  if ( v1->m_motion.m_savedMotion )
  {
    v10 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v11 = (hkpMotion *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v10[11] + 8i64))(v10[11], 320i64);
    v12 = v11;
    if ( v11 )
    {
      hkpMotion::hkpMotion(v11);
      v12->m_savedMotion = 0i64;
      v12->vfptr = (hkBaseObjectVtbl *)&hkpMaxSizeMotion::`vftable';
    }
    else
    {
      v12 = 0i64;
    }
    v5[3].m_collidable.m_shape = (hkpShape *)v12;
    v13 = v12->m_memSizeAndFlags;
    v14 = v12->m_referenceCount;
    v15 = v1->m_motion.m_savedMotion;
    do
    {
      --v7;
      v12 = (hkpMotion *)((char *)v12 + 16);
      *(_OWORD *)&v12[-1].m_savedQualityTypeIndex = *(_OWORD *)&v15->vfptr;
      v15 = (hkpMaxSizeMotion *)((char *)v15 + 16);
    }
    while ( v7 > 0 );
    v5[3].m_collidable.m_shape->m_memSizeAndFlags = v13;
    v5[3].m_collidable.m_shape->m_referenceCount = v14;
  }
  v5->m_collidable.m_motion = (const void *)((__int64 (__fastcall *)(hkpWorldObject *))v5->vfptr[2].__first_virtual_table_function__)(v5);
  hkpWorldObject::copyProperties(v5, (hkpWorldObject *)&v1->vfptr);
  hkStringPtr::operator=(&v5->m_name, (const char *)((_QWORD)v1->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64));
  v5->m_userData = v1->m_userData;
  v16 = v1->m_breakableBody;
  if ( v16 )
    v5[1].m_collidable.m_shape = (hkpShape *)((__int64 (__fastcall *)(hkpBreakableBody *, hkpWorldObject *))v16->vfptr[1].__first_virtual_table_function__)(
                                               v16,
                                               v5);
  return v5;
}

// File Line: 474
// RVA: 0xD62D20
void __fastcall hkpRigidBody::setMotionType(hkpRigidBody *this, hkpMotion::MotionType newState, hkpEntityActivation preferredActivationState, hkpUpdateCollisionFilterOnEntityMode collisionFilterUpdateMode)
{
  hkpRigidBody *v4; // rbx
  hkpWorld *v5; // rcx
  hkpWorld *v6; // rcx
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-28h]
  hkpRigidBody *v8; // [rsp+28h] [rbp-20h]
  char v9; // [rsp+30h] [rbp-18h]
  char v10; // [rsp+31h] [rbp-17h]
  char v11; // [rsp+32h] [rbp-16h]

  v4 = this;
  v5 = this->m_world;
  if ( v5 && v5->m_criticalOperationsLockCount )
  {
    v9 = newState;
    operation.m_type.m_storage = 4;
    v8 = v4;
    v10 = preferredActivationState;
    v11 = collisionFilterUpdateMode;
    hkpWorld::queueOperation(v5, &operation);
  }
  else
  {
    hkpWorldOperationUtil::setRigidBodyMotionType(v4, newState, preferredActivationState, collisionFilterUpdateMode);
    v6 = v4->m_world;
    if ( v6 )
      hkpWorldCallbackUtil::fireEntitySetMotionType(v6, (hkpEntity *)&v4->vfptr);
    hkpEntityCallbackUtil::fireEntitySetMotionType((hkpEntity *)&v4->vfptr);
  }
}

// File Line: 512
// RVA: 0xD62EF0
signed __int64 __fastcall hkpRigidBody::setShape(hkpRigidBody *this, hkpShape *shape)
{
  hkpWorld *v2; // rax
  hkpShape *v3; // rdi
  hkpRigidBody *v4; // rbx
  signed __int64 result; // rax
  hkReferencedObject *v6; // rsi
  float v7; // xmm1_4
  hkpWorld *v8; // rdx
  hkpWorld *v9; // rcx
  hkpWorld *v10; // rcx
  hkpWorld *v11; // rbx
  bool v12; // zf
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-28h]
  hkpRigidBody *v14; // [rsp+28h] [rbp-20h]
  hkpShape *v15; // [rsp+30h] [rbp-18h]

  v2 = this->m_world;
  v3 = shape;
  v4 = this;
  if ( v2 && v2->m_criticalOperationsLockCount )
  {
    v15 = shape;
    v14 = this;
    operation.m_type.m_storage = 5;
    hkpWorld::queueOperation(v2, &operation);
    result = 0i64;
  }
  else
  {
    if ( v2 )
    {
      ++v2->m_criticalOperationsLockCount;
      hkpWorldOperationUtil::removeEntityBP(this->m_world, (hkpEntity *)&this->vfptr);
    }
    v6 = (hkReferencedObject *)&v4->m_collidable.m_shape->vfptr;
    v4->m_collidable.m_shape = v3;
    hkReferencedObject::addReference((hkReferencedObject *)&v3->vfptr);
    if ( v6 )
      hkReferencedObject::removeReference(v6);
    hkpRigidBody::updateCachedShapeInfo(v4, v3, (hkVector4f *)&operation);
    if ( v6 && 3.40282e38 != v4->m_collidable.m_allowedPenetrationDepth )
      v4->m_collidable.m_allowedPenetrationDepth = -1.0;
    v7 = v4->m_collidable.m_allowedPenetrationDepth;
    if ( v7 <= 0.0 )
      estimateAllowedPenetrationDepth((hkpCollidable *)&v4->m_collidable.m_shape, v7, (hkVector4f *)&operation);
    v8 = v4->m_world;
    if ( v8 )
      hkpEntity::setCachedShapeData((hkpEntity *)&v4->vfptr, v8, v3);
    v9 = v4->m_world;
    if ( v9 )
      hkpWorldCallbackUtil::fireEntityShapeSet(v9, (hkpEntity *)&v4->vfptr);
    hkpEntityCallbackUtil::fireEntityShapeSet((hkpEntity *)&v4->vfptr);
    v10 = v4->m_world;
    if ( v10 )
    {
      hkpWorldOperationUtil::addEntityBP(v10, (hkpEntity *)&v4->vfptr);
      v11 = v4->m_world;
      v12 = v11->m_criticalOperationsLockCount-- == 1;
      if ( v12 && !v11->m_blockExecutingPendingOperations.m_bool )
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
    result = 1i64;
  }
  return result;
}

// File Line: 593
// RVA: 0xD63070
signed __int64 __fastcall hkpRigidBody::updateShape(hkpRigidBody *this, hkpShapeModifier *shapeModifier)
{
  hkpWorld *v2; // rax
  hkpRigidBody *v3; // rbx
  signed __int64 result; // rax
  hkpShape *v5; // rdi
  hkpWorld *v6; // r9
  hkpWorld *v7; // rdi
  bool v8; // zf
  hkWorldOperation::BaseOperation operation; // [rsp+30h] [rbp-28h]
  hkpRigidBody *v10; // [rsp+38h] [rbp-20h]
  hkpShapeModifier *v11; // [rsp+40h] [rbp-18h]
  hkpRigidBody *v12; // [rsp+60h] [rbp+8h]

  v2 = this->m_world;
  v3 = this;
  if ( v2 && v2->m_criticalOperationsLockCount )
  {
    v11 = shapeModifier;
    v10 = this;
    operation.m_type.m_storage = 6;
    hkpWorld::queueOperation(v2, &operation);
    result = 0i64;
  }
  else
  {
    if ( v2 )
      ++v2->m_criticalOperationsLockCount;
    v5 = this->m_collidable.m_shape;
    if ( shapeModifier )
      shapeModifier->vfptr->modifyShape(shapeModifier, v5);
    hkpRigidBody::updateCachedShapeInfo(v3, v5, (hkVector4f *)&operation);
    if ( v3->m_world )
    {
      v3->m_collidable.m_boundingVolumeData.m_min[0] = 1;
      v3->m_collidable.m_boundingVolumeData.m_max[0] = 0;
      if ( v3->m_motion.m_type.m_storage == 5 )
      {
        v6 = v3->m_world;
        v12 = v3;
        ((void (__fastcall *)(hkpSimulation *, hkpRigidBody **, signed __int64))v6->m_simulation->vfptr[6].__vecDelDtor)(
          v6->m_simulation,
          &v12,
          1i64);
        hkpWorldOperationUtil::updateEntityBP(v3->m_world, (hkpEntity *)&v3->vfptr);
      }
      v7 = v3->m_world;
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
      hkpWorldCallbackUtil::fireEntityShapeSet(v3->m_world, (hkpEntity *)&v3->vfptr);
    }
    hkpEntityCallbackUtil::fireEntityShapeSet((hkpEntity *)&v3->vfptr);
    result = 1i64;
  }
  return result;
}

// File Line: 656
// RVA: 0xD62790
void __fastcall hkpRigidBody::setCenterOfMassLocal(hkpRigidBody *this, hkVector4f *centerOfMass)
{
  hkpRigidBody *v2; // rbx
  hkVector4f extentOut; // [rsp+20h] [rbp-18h]

  v2 = this;
  ((void (__fastcall *)(hkpMaxSizeMotion *, hkVector4f *))this->m_motion.vfptr[6].__first_virtual_table_function__)(
    &this->m_motion,
    centerOfMass);
  hkpRigidBody::updateCachedShapeInfo(v2, v2->m_collidable.m_shape, &extentOut);
}

// File Line: 666
// RVA: 0xD62BF0
void __fastcall hkpRigidBody::enableDeactivation(hkpRigidBody *this, bool _enableDeactivation)
{
  hkpRigidBody *v2; // rbx
  unsigned __int8 *v3; // rax
  int v4; // er10
  __int16 v5; // dx
  __int16 v6; // r8
  int v7; // er9
  unsigned __int8 v8; // al
  __int16 v9; // r8
  signed __int16 v10; // dx
  __int64 v11; // rax
  char v12; // cl
  bool v13; // zf
  signed __int16 v14; // ax

  v2 = this;
  if ( _enableDeactivation )
  {
    if ( !hkpRigidBody::isDeactivationEnabled(this) )
    {
      v3 = (unsigned __int8 *)v2->m_world;
      if ( v3 )
      {
        v4 = v3[1007];
        v5 = v3[1006];
        v6 = v3[1005];
        v7 = v2->m_uid & 0xF;
        v8 = v3[1007] & 3;
        v2->m_motion.m_deactivationIntegrateCounter = v7;
        if ( v8 < (unsigned __int8)(v7 & 3) )
          v6 = ~v6;
        v9 = v6 << 14;
        if ( v4 < v7 )
          v5 = ~v5;
        v2->m_motion.m_deactivationNumInactiveFrames[0] &= 0x3FFFu;
        v2->m_motion.m_deactivationNumInactiveFrames[0] |= v9;
        v2->m_motion.m_deactivationNumInactiveFrames[1] &= 0x3FFFu;
        v2->m_motion.m_deactivationNumInactiveFrames[1] |= v5 << 14;
      }
      else
      {
        v10 = 0;
        v11 = v2->m_uid & 0xF;
        v2->m_motion.m_deactivationIntegrateCounter = v11;
        v12 = v11;
        v13 = (v11 & 3) == 0;
        v14 = 0;
        if ( !v13 )
          v14 = -16384;
        if ( v12 )
          v10 = -16384;
        v2->m_motion.m_deactivationNumInactiveFrames[0] &= 0x3FFFu;
        v2->m_motion.m_deactivationNumInactiveFrames[0] |= v14;
        v2->m_motion.m_deactivationNumInactiveFrames[1] &= 0x3FFFu;
        v2->m_motion.m_deactivationNumInactiveFrames[1] |= v10;
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
  hkpMaxSizeMotion *result; // rax

  if ( (unsigned __int8)(this->m_motion.m_type.m_storage - 4) <= 1u )
    result = this->m_motion.m_savedMotion;
  else
    result = 0i64;
  return result;
}

// File Line: 714
// RVA: 0xD62DB0
hkpMaxSizeMotion *__fastcall hkpRigidBody::getStoredDynamicMotion(hkpRigidBody *this)
{
  hkpMaxSizeMotion *result; // rax

  if ( (unsigned __int8)(this->m_motion.m_type.m_storage - 4) <= 1u )
    result = this->m_motion.m_savedMotion;
  else
    result = 0i64;
  return result;
}

// File Line: 736
// RVA: 0xD636A0
void __fastcall hkpRigidBody::updateBroadphaseAndResetCollisionInformationOfWarpedBody(hkpEntity *entity)
{
  hkpWorld *v1; // rbx
  hkpEntity *v2; // rdi
  hkpSimulation *v3; // rcx
  signed int v4; // ST20_4
  bool v5; // zf
  hkWorldOperation::BaseOperation operation; // [rsp+30h] [rbp-18h]
  hkpEntity *v7; // [rsp+38h] [rbp-10h]
  hkBool result; // [rsp+50h] [rbp+8h]
  hkpEntity *entities; // [rsp+58h] [rbp+10h]

  v1 = entity->m_world;
  v2 = entity;
  if ( v1 )
  {
    if ( v1->m_criticalOperationsLockCount )
    {
      v7 = entity;
      operation.m_type.m_storage = 23;
      hkpWorld::queueOperation(v1, &operation);
    }
    else
    {
      entities = entity;
      v3 = v1->m_simulation;
      v1->m_criticalOperationsLockCount = 1;
      v4 = 7;
      ((void (__fastcall *)(hkpSimulation *, hkpEntity **, signed __int64, hkpWorld *, signed int))v3->vfptr[6].__vecDelDtor)(
        v3,
        &entities,
        1i64,
        v1,
        v4);
      if ( v2->m_collidable.m_shape )
        hkpSimulation::collideEntitiesBroadPhaseDiscrete(&entities, 1, v1);
      if ( !hkpEntity::isActive(v2, &result)->m_bool )
      {
        if ( v1->m_shouldActivateOnRigidBodyTransformChange.m_bool && v2->m_motion.m_type.m_storage != 5 )
          hkpEntity::activate(v2);
        hkpWorldCallbackUtil::fireInactiveEntityMoved(v1, v2);
      }
      v5 = v1->m_criticalOperationsLockCount-- == 1;
      if ( v5 && !v1->m_blockExecutingPendingOperations.m_bool )
      {
        if ( v1->m_pendingOperationsCount )
          hkpWorld::internal_executePendingOperations(v1);
        if ( v1->m_pendingOperationQueueCount == 1 )
        {
          if ( v1->m_pendingBodyOperationsCount )
            hkpWorld::internal_executePendingBodyOperations(v1);
        }
      }
    }
  }
}

// File Line: 803
// RVA: 0xD627D0
void __fastcall hkpRigidBody::setPosition(hkpRigidBody *this, hkVector4f *position)
{
  hkpRigidBody *v2; // rbx

  v2 = this;
  this->m_motion.vfptr[7].__vecDelDtor((hkBaseObject *)&this->m_motion, (unsigned int)position);
  hkpRigidBody::updateBroadphaseAndResetCollisionInformationOfWarpedBody((hkpEntity *)&v2->vfptr);
}

// File Line: 814
// RVA: 0xD62800
void __fastcall hkpRigidBody::setRotation(hkpRigidBody *this, hkQuaternionf *rotation)
{
  hkpRigidBody *v2; // rbx

  v2 = this;
  ((void (__fastcall *)(hkpMaxSizeMotion *, hkQuaternionf *))this->m_motion.vfptr[7].__first_virtual_table_function__)(
    &this->m_motion,
    rotation);
  hkpRigidBody::updateBroadphaseAndResetCollisionInformationOfWarpedBody((hkpEntity *)&v2->vfptr);
}

// File Line: 827
// RVA: 0xD62830
void __fastcall hkpRigidBody::setPositionAndRotation(hkpRigidBody *this, hkVector4f *position, hkQuaternionf *rotation)
{
  hkpRigidBody *v3; // rbx

  v3 = this;
  ((void (__fastcall *)(hkpMaxSizeMotion *, hkVector4f *, hkQuaternionf *))this->m_motion.vfptr[8].__vecDelDtor)(
    &this->m_motion,
    position,
    rotation);
  hkpRigidBody::updateBroadphaseAndResetCollisionInformationOfWarpedBody((hkpEntity *)&v3->vfptr);
}

// File Line: 842
// RVA: 0xD62860
void __fastcall hkpRigidBody::setTransform(hkpRigidBody *this, hkTransformf *transform)
{
  hkpRigidBody *v2; // rbx

  v2 = this;
  ((void (__fastcall *)(hkpMaxSizeMotion *, hkTransformf *))this->m_motion.vfptr[8].__first_virtual_table_function__)(
    &this->m_motion,
    transform);
  hkpRigidBody::updateBroadphaseAndResetCollisionInformationOfWarpedBody((hkpEntity *)&v2->vfptr);
}

// File Line: 852
// RVA: 0xD62710
void __fastcall hkpRigidBody::setMass(hkpRigidBody *this, float m)
{
  ((void (*)(void))this->m_motion.vfptr[2].__vecDelDtor)();
}

// File Line: 860
// RVA: 0xD62730
void __fastcall hkpRigidBody::setMassInv(hkpRigidBody *this, float mInv)
{
  ((void (*)(void))this->m_motion.vfptr[3].__vecDelDtor)();
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
  ((void (__fastcall *)(hkpMaxSizeMotion *, hkMatrix3f *))this->m_motion.vfptr[4].__first_virtual_table_function__)(
    &this->m_motion,
    inertia);
}

// File Line: 908
// RVA: 0xD62770
void __fastcall hkpRigidBody::setInertiaInvLocal(hkpRigidBody *this, hkMatrix3f *inertiaInv)
{
  this->m_motion.vfptr[5].__vecDelDtor((hkBaseObject *)&this->m_motion, (unsigned int)inertiaInv);
}

// File Line: 915
// RVA: 0xD62890
void __fastcall hkpRigidBody::setPositionAndRotationAsCriticalOperation(hkpRigidBody *this, hkVector4f *position, hkQuaternionf *rotation)
{
  hkpWorld *v3; // rax
  hkQuaternionf *v4; // rdi
  hkVector4f *v5; // rsi
  hkpRigidBody *v6; // rbx
  _QWORD **v7; // rax
  hkQuaternionf *v8; // rax
  __m128 v9; // xmm0
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-28h]
  hkpRigidBody *v11; // [rsp+28h] [rbp-20h]
  hkQuaternionf *v12; // [rsp+30h] [rbp-18h]

  v3 = this->m_world;
  v4 = rotation;
  v5 = position;
  v6 = this;
  if ( v3 && v3->m_criticalOperationsLockCount )
  {
    v11 = this;
    operation.m_type.m_storage = 25;
    v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v8 = (hkQuaternionf *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v7[11] + 8i64))(v7[11], 32i64);
    v9 = v5->m_quad;
    v12 = v8;
    *v8 = (hkQuaternionf)v9;
    v12[1] = (hkQuaternionf)v4->m_vec.m_quad;
    hkpWorld::queueOperation(v6->m_world, &operation);
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
  hkpRigidBody *v2; // rbx
  hkpWorld *v3; // rcx
  hkVector4f *v4; // rdi
  __m128 v5; // xmm0
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-28h]
  hkpRigidBody *v7; // [rsp+28h] [rbp-20h]
  unsigned __int64 v8; // [rsp+30h] [rbp-18h]
  int v9; // [rsp+38h] [rbp-10h]

  v2 = this;
  v3 = this->m_world;
  v4 = newVel;
  if ( v3 && v3->m_criticalOperationsLockCount )
  {
    v5 = newVel->m_quad;
    operation.m_type.m_storage = 26;
    v7 = v2;
    v8 = v5.m128_u64[0];
    v9 = (unsigned __int128)_mm_movehl_ps(v5, v5);
    hkpWorld::queueOperation(v3, &operation);
  }
  else
  {
    hkpEntity::activate((hkpEntity *)&v2->vfptr);
    v2->m_motion.vfptr[9].__vecDelDtor((hkBaseObject *)&v2->m_motion.vfptr, (unsigned int)v4);
  }
}

// File Line: 952
// RVA: 0xD629B0
void __fastcall hkpRigidBody::setAngularVelocityAsCriticalOperation(hkpRigidBody *this, hkVector4f *newVel)
{
  hkpRigidBody *v2; // rbx
  hkpWorld *v3; // rcx
  hkVector4f *v4; // rdi
  __m128 v5; // xmm0
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-28h]
  hkpRigidBody *v7; // [rsp+28h] [rbp-20h]
  unsigned __int64 v8; // [rsp+30h] [rbp-18h]
  int v9; // [rsp+38h] [rbp-10h]

  v2 = this;
  v3 = this->m_world;
  v4 = newVel;
  if ( v3 && v3->m_criticalOperationsLockCount )
  {
    v5 = newVel->m_quad;
    operation.m_type.m_storage = 27;
    v7 = v2;
    v8 = v5.m128_u64[0];
    v9 = (unsigned __int128)_mm_movehl_ps(v5, v5);
    hkpWorld::queueOperation(v3, &operation);
  }
  else
  {
    hkpEntity::activate((hkpEntity *)&v2->vfptr);
    ((void (__fastcall *)(hkpMaxSizeMotion *, hkVector4f *))v2->m_motion.vfptr[9].__first_virtual_table_function__)(
      &v2->m_motion,
      v4);
  }
}

// File Line: 969
// RVA: 0xD62A30
void __fastcall hkpRigidBody::applyLinearImpulseAsCriticalOperation(hkpRigidBody *this, hkVector4f *imp)
{
  hkpRigidBody *v2; // rbx
  hkpWorld *v3; // rcx
  hkVector4f *v4; // rdi
  __m128 v5; // xmm0
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-28h]
  hkpRigidBody *v7; // [rsp+28h] [rbp-20h]
  unsigned __int64 v8; // [rsp+30h] [rbp-18h]
  int v9; // [rsp+38h] [rbp-10h]

  v2 = this;
  v3 = this->m_world;
  v4 = imp;
  if ( v3 && v3->m_criticalOperationsLockCount )
  {
    v5 = imp->m_quad;
    operation.m_type.m_storage = 28;
    v7 = v2;
    v8 = v5.m128_u64[0];
    v9 = (unsigned __int128)_mm_movehl_ps(v5, v5);
    hkpWorld::queueOperation(v3, &operation);
  }
  else
  {
    hkpEntity::activate((hkpEntity *)&v2->vfptr);
    v2->m_motion.vfptr[11].__vecDelDtor((hkBaseObject *)&v2->m_motion.vfptr, (unsigned int)v4);
  }
}

// File Line: 986
// RVA: 0xD62AB0
void __fastcall hkpRigidBody::applyPointImpulseAsCriticalOperation(hkpRigidBody *this, hkVector4f *imp, hkVector4f *p)
{
  hkpWorld *v3; // rax
  hkVector4f *v4; // rdi
  hkVector4f *v5; // rsi
  hkpRigidBody *v6; // rbx
  _QWORD **v7; // rax
  hkVector4f *v8; // rax
  __m128 v9; // xmm0
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-28h]
  hkpRigidBody *v11; // [rsp+28h] [rbp-20h]
  hkVector4f *v12; // [rsp+30h] [rbp-18h]

  v3 = this->m_world;
  v4 = p;
  v5 = imp;
  v6 = this;
  if ( v3 && v3->m_criticalOperationsLockCount )
  {
    v11 = this;
    operation.m_type.m_storage = 29;
    v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v8 = (hkVector4f *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v7[11] + 8i64))(v7[11], 32i64);
    v9 = v4->m_quad;
    v12 = v8;
    *v8 = (hkVector4f)v9;
    v12[1] = (hkVector4f)v5->m_quad;
    hkpWorld::queueOperation(v6->m_world, &operation);
  }
  else
  {
    hkpEntity::activate((hkpEntity *)&this->vfptr);
    ((void (__fastcall *)(hkpMaxSizeMotion *, hkVector4f *, hkVector4f *))v6->m_motion.vfptr[11].__first_virtual_table_function__)(
      &v6->m_motion,
      v5,
      v4);
  }
}

// File Line: 1006
// RVA: 0xD62B70
void __fastcall hkpRigidBody::applyAngularImpulseAsCriticalOperation(hkpRigidBody *this, hkVector4f *imp)
{
  hkpRigidBody *v2; // rbx
  hkpWorld *v3; // rcx
  hkVector4f *v4; // rdi
  __m128 v5; // xmm0
  hkWorldOperation::BaseOperation operation; // [rsp+20h] [rbp-28h]
  hkpRigidBody *v7; // [rsp+28h] [rbp-20h]
  unsigned __int64 v8; // [rsp+30h] [rbp-18h]
  int v9; // [rsp+38h] [rbp-10h]

  v2 = this;
  v3 = this->m_world;
  v4 = imp;
  if ( v3 && v3->m_criticalOperationsLockCount )
  {
    v5 = imp->m_quad;
    operation.m_type.m_storage = 30;
    v7 = v2;
    v8 = v5.m128_u64[0];
    v9 = (unsigned __int128)_mm_movehl_ps(v5, v5);
    hkpWorld::queueOperation(v3, &operation);
  }
  else
  {
    hkpEntity::activate((hkpEntity *)&v2->vfptr);
    v2->m_motion.vfptr[12].__vecDelDtor((hkBaseObject *)&v2->m_motion.vfptr, (unsigned int)v4);
  }
}

// File Line: 1023
// RVA: 0xD63360
hkBool *__fastcall hkpRigidBody::checkPerformance(hkpRigidBody *this, hkBool *result)
{
  hkpShape *v2; // r14
  hkBool *v3; // rsi
  hkpRigidBody *v4; // rbp
  unsigned int v6; // ebx
  char v7; // di
  signed int v8; // eax
  __int64 v9; // rax

  v2 = this->m_collidable.m_shape;
  v3 = result;
  v4 = this;
  if ( !v2 )
  {
    result->m_bool = 0;
    return result;
  }
  v6 = (unsigned __int8)v2->m_type.m_storage;
  v7 = 1;
  if ( (unsigned __int8)(this->m_motion.m_type.m_storage - 4) > 1u && v6 <= 0x16 )
  {
    v8 = 4391552;
    if ( _bittest(&v8, v6) )
    {
      v9 = ((__int64 (__fastcall *)(hkpShape *))v2->vfptr[7].__vecDelDtor)(this->m_collidable.m_shape);
      v7 = 1;
      if ( (*(signed int (__fastcall **)(__int64))(*(_QWORD *)v9 + 8i64))(v9) > 100 )
        v7 = 0;
    }
  }
  if ( v6 != 27 )
  {
    if ( (v6 == 18 || v6 == 6)
      && ((signed int (__fastcall *)(hkpShape *))v4->m_collidable.m_shape[1].vfptr->__first_virtual_table_function__)(&v4->m_collidable.m_shape[1]) > 100 )
    {
      v7 = 0;
    }
    if ( v6 != 14 )
    {
      if ( v6 == 8
        && ((signed int (__fastcall *)(hkpShape *))v2[1].vfptr->__first_virtual_table_function__)(&v2[1]) > 100 )
      {
        v7 = 0;
      }
      goto LABEL_19;
    }
    goto LABEL_10;
  }
  if ( ((signed int (__fastcall *)(hkpShape *))v4->m_collidable.m_shape[1].vfptr->__first_virtual_table_function__)(&v4->m_collidable.m_shape[1]) > 100 )
LABEL_10:
    v7 = 0;
LABEL_19:
  v3->m_bool = v7;
  return v3;
}

