// File Line: 106
// RVA: 0x4492E0
void __fastcall CharacterRigidBody::CharacterRigidBody(CharacterRigidBody *this, hkpCharacterRigidBodyCinfo *info)
{
  __int64 v4; // rdi
  char v5; // dl
  char v6; // cl
  _QWORD **Value; // rax
  hkpRigidBody *v8; // rax
  hkpRigidBody *v9; // rax
  char v10; // al
  __m128 v11; // xmm8
  __m128 v12; // xmm6
  __m128i si128; // xmm7
  __m128i v14; // xmm3
  __m128i v15; // xmm7
  __m128 v16; // xmm5
  unsigned int v17; // xmm1_4
  __m128 v18; // xmm7
  __m128 v19; // xmm2
  __m128 v20; // xmm3
  hkMatrix3f inertiaInv; // [rsp+30h] [rbp-168h] BYREF
  hkpRigidBodyCinfo infoa; // [rsp+60h] [rbp-138h] BYREF

  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkReferencedObject::`vftable;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->hkpEntityListener::vfptr = (hkpEntityListenerVtbl *)&hkpEntityListener::`vftable;
  this->hkpWorldPostSimulationListener::vfptr = (hkpWorldPostSimulationListenerVtbl *)&hkpWorldPostSimulationListener::`vftable;
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&CharacterRigidBody::`vftable{for `hkReferencedObject};
  this->hkpEntityListener::vfptr = (hkpEntityListenerVtbl *)&CharacterRigidBody::`vftable{for `hkpEntityListener};
  this->hkpWorldPostSimulationListener::vfptr = (hkpWorldPostSimulationListenerVtbl *)&CharacterRigidBody::`vftable{for `hkpWorldPostSimulationListener};
  *(_DWORD *)&this->m_isPlayer = 256;
  this->m_superMassive = 0;
  this->m_verticalContactPoints.m_data = 0i64;
  this->m_verticalContactPoints.m_size = 0;
  this->m_verticalContactPoints.m_capacityAndFlags = 0x80000000;
  hkpRigidBodyCinfo::hkpRigidBodyCinfo(&infoa);
  infoa.m_shape = info->m_shape;
  infoa.m_mass = info->m_mass;
  infoa.m_friction = info->m_friction;
  infoa.m_position = info->m_position;
  infoa.m_rotation = info->m_rotation;
  infoa.m_collisionFilterInfo = info->m_collisionFilterInfo;
  infoa.m_restitution = 0.0;
  infoa.m_maxLinearVelocity = info->m_maxLinearVelocity;
  infoa.m_motionType.m_storage = 7;
  infoa.m_qualityType.m_storage = 8;
  v4 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v5 = ++*(_BYTE *)(v4 + 80);
  *(_DWORD *)(v4 + 4i64 * v5) = 0;
  *(_QWORD *)(v4 + 8i64 * v5 + 16) = "hkpRigidBody";
  *(_QWORD *)(v4 + 8i64 * v5 + 48) = 0i64;
  v6 = *(_BYTE *)(v4 + 81);
  if ( v5 > v6 )
    v6 = v5;
  *(_BYTE *)(v4 + 81) = v6;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v8 = (hkpRigidBody *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 720i64);
  if ( v8 )
    hkpRigidBody::hkpRigidBody(v8, &infoa);
  else
    v9 = 0i64;
  this->m_character = v9;
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
  memset(&inertiaInv, 0, sizeof(inertiaInv));
  hkpRigidBody::setInertiaInvLocal(this->m_character, &inertiaInv);
  hkpWorldObject::addProperty(this->m_character, 0x1130u, (hkSimplePropertyValue)info->m_vdbColor);
  this->m_up = info->m_up;
  v11 = _mm_add_ps((__m128)LODWORD(info->m_maxSlope), *(__m128 *)_xmm);
  v12 = _mm_andnot_ps(*(__m128 *)_xmm, v11);
  si128 = _mm_load_si128((const __m128i *)_xmm);
  v14 = _mm_add_epi32(si128, si128);
  v15 = _mm_andnot_si128(si128, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v12, *(__m128 *)_xmm)), si128));
  v16 = _mm_cvtepi32_ps(v15);
  v17 = _mm_and_si128(v15, _mm_add_epi32(v14, v14)).m128i_u32[0] << 29;
  v18 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v15, v14), (__m128i)0i64);
  v19 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v16, *(__m128 *)DP1_0), v12), _mm_mul_ps(v16, *(__m128 *)DP2)),
          _mm_mul_ps(v16, *(__m128 *)DP3));
  v20 = _mm_mul_ps(v19, v19);
  *(_QWORD *)&this->m_maxSlopeCosine = (_mm_andnot_ps(
                                          v18,
                                          _mm_add_ps(
                                            _mm_sub_ps(
                                              _mm_mul_ps(
                                                _mm_mul_ps(
                                                  _mm_add_ps(
                                                    _mm_mul_ps(
                                                      _mm_add_ps(
                                                        _mm_mul_ps(v20, *(__m128 *)cosCoeff0_0),
                                                        *(__m128 *)cosCoeff1),
                                                      v20),
                                                    *(__m128 *)cosCoeff2_0),
                                                  v20),
                                                v20),
                                              _mm_mul_ps(*(__m128 *)_xmm, v20)),
                                            *(__m128 *)_xmm)).m128_u32[0] | COERCE_UNSIGNED_INT(
                                                                              (float)((float)((float)((float)((float)((float)(-0.00019515296 * v20.m128_f32[0]) + 0.0083321612) * v20.m128_f32[0]) + -0.16666655)
                                                                                            * v20.m128_f32[0])
                                                                                    * v19.m128_f32[0])
                                                                            + v19.m128_f32[0]) & v18.m128_i32[0]) ^ v11.m128_i32[0] & _xmm[0] ^ v17;
  this->m_penetrationRecoverySpeed = 0.1;
  this->m_supportDistance = info->m_supportDistance;
  this->m_maxSpeedForSimplexSolver = info->m_maxSpeedForSimplexSolver;
  this->m_acceleration = 0i64;
  this->m_maxForce = info->m_maxForce;
  hkpEntity::addEntityListener(this->m_character, &this->hkpEntityListener);
  this->m_heightAboveGround = 0.0;
}

// File Line: 203
// RVA: 0x44FBC0
void __fastcall CharacterRigidBody::~CharacterRigidBody(CharacterRigidBody *this)
{
  int m_capacityAndFlags; // eax
  hkSimplePropertyValue result; // [rsp+48h] [rbp+10h] BYREF

  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&CharacterRigidBody::`vftable{for `hkReferencedObject};
  this->hkpEntityListener::vfptr = (hkpEntityListenerVtbl *)&CharacterRigidBody::`vftable{for `hkpEntityListener};
  this->hkpWorldPostSimulationListener::vfptr = (hkpWorldPostSimulationListenerVtbl *)&CharacterRigidBody::`vftable{for `hkpWorldPostSimulationListener};
  hkpEntity::removeEntityListener(this->m_character, &this->hkpEntityListener);
  hkpWorldObject::removeProperty(this->m_character, &result, 0x1130u);
  hkReferencedObject::removeReference(this->m_character);
  this->m_verticalContactPoints.m_size = 0;
  m_capacityAndFlags = this->m_verticalContactPoints.m_capacityAndFlags;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_verticalContactPoints.m_data,
      48 * (m_capacityAndFlags & 0x3FFFFFFF));
  this->m_verticalContactPoints.m_data = 0i64;
  this->m_verticalContactPoints.m_capacityAndFlags = 0x80000000;
  this->hkpWorldPostSimulationListener::vfptr = (hkpWorldPostSimulationListenerVtbl *)&hkpWorldPostSimulationListener::`vftable;
  this->hkpEntityListener::vfptr = (hkpEntityListenerVtbl *)&hkpEntityListener::`vftable;
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkReferencedObject::`vftable;
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 222
// RVA: 0x485600
// local variable allocation has failed, the output may be wrong!
void __fastcall CharacterRigidBody::checkSupportForPlayer(
        CharacterRigidBody *this,
        hkStepInfo *stepInfo,
        hkpSurfaceInfo *ground,
        double a4)
{
  __m128 *v4; // rdi
  hkStepInfo *v5; // rsi
  _QWORD *Value; // r9
  unsigned __int64 v8; // rcx
  unsigned __int64 v9; // rax
  __m128 v10; // xmm12
  hkLifoAllocator *v11; // rax
  __m128 *m_cur; // rcx
  __m128 *v13; // rdx
  hkArray<hkpLinkedCollidable::CollisionEntry,hkContainerHeapAllocator> *p_m_collisionEntries; // r12
  bool DoesBoundingBoxProvideSupport; // r14
  float v16; // xmm6_4
  int v17; // edx
  __int64 v18; // r13
  hkpContactMgr *m_contactMgr; // r14
  int v20; // ebx
  int v21; // edx
  __int64 i; // rcx
  __int64 v23; // rdi
  __int64 v24; // rsi
  __m128 v25; // xmm0
  float v26; // xmm0_4
  int v27; // ecx
  hkSurfaceConstraintInteraction *v28; // rdx
  int v29; // ecx
  __m128 *v30; // rdx
  float v31; // xmm0_4
  hkpLinkedCollidable *m_partner; // r8
  __m128 *v33; // rcx
  char v34; // r8
  __m128 v35; // xmm1
  __m128 v36; // xmm2
  __m128 v37; // xmm2
  int v38; // eax
  __m128 v39; // xmm0
  __m128 v40; // xmm0
  int v41; // ecx
  int m_userPlanes; // r8d
  int v43; // edx
  int v44; // r9d
  int v45; // ebx
  bool v46; // zf
  int v47; // ebx
  hkLifoAllocator *v48; // r8
  int v49; // edx
  hkSurfaceConstraintInteraction *v50; // rax
  char *v51; // rcx
  int v52; // ebx
  hkLifoAllocator *v53; // rax
  int v54; // edx
  char *v55; // rcx
  char *v56; // r8
  int v57; // r8d
  int v58; // edx
  int v59; // ebx
  int v60; // ebx
  int v61; // ebx
  int v62; // ecx
  int v63; // r9d
  __int64 v64; // rdx
  __int64 v65; // r8
  __m128 v66; // xmm4
  __m128 v67; // xmm4
  __m128 v68; // xmm0
  __m128 v69; // xmm2
  int v70; // edx
  __int64 v71; // r8
  __m128 *v72; // rax
  __m128 *v73; // rcx
  char *v74; // r9
  __m128 v75; // xmm2
  __m128 v76; // xmm5
  __m128 v77; // xmm3
  __m128 v78; // xmm3
  __m128 v79; // xmm0
  __m128 v80; // xmm1
  _QWORD *v81; // r8
  unsigned __int64 v82; // rcx
  unsigned __int64 v83; // rax
  char *v84; // rdi
  int v85; // ecx
  int v86; // ebx
  hkLifoAllocator *v87; // rcx
  signed int v88; // ebx
  int v89; // r8d
  char *v90; // rdi
  int v91; // ecx
  int v92; // ebx
  hkLifoAllocator *v93; // rcx
  signed int v94; // ebx
  int v95; // r8d
  char *v96; // rdi
  int v97; // ecx
  int v98; // ebx
  hkLifoAllocator *v99; // rcx
  signed int v100; // ebx
  int v101; // r8d
  __m128 *array; // [rsp+30h] [rbp-D0h] BYREF
  int v103; // [rsp+38h] [rbp-C8h]
  int v104; // [rsp+3Ch] [rbp-C4h]
  void *p; // [rsp+40h] [rbp-C0h]
  int v106; // [rsp+48h] [rbp-B8h]
  hkSurfaceConstraintInteraction *v107; // [rsp+50h] [rbp-B0h] BYREF
  int v108; // [rsp+58h] [rbp-A8h]
  int v109; // [rsp+5Ch] [rbp-A4h]
  hkSimplexSolverInput input; // [rsp+60h] [rbp-A0h] BYREF
  __m128 v111; // [rsp+C0h] [rbp-40h]
  hkVector4f v112; // [rsp+D0h] [rbp-30h]
  hkSimplexSolverOutput output; // [rsp+E0h] [rbp-20h]
  __int64 v114; // [rsp+110h] [rbp+10h]
  hkSimplexSolverOutput v115; // [rsp+120h] [rbp+20h] BYREF
  bool v116; // [rsp+210h] [rbp+110h]
  hkpSurfaceInfo *v118; // [rsp+220h] [rbp+120h] BYREF
  int v119; // [rsp+228h] [rbp+128h]

  v118 = ground;
  v114 = -2i64;
  v4 = (__m128 *)ground;
  v5 = stepInfo;
  sPlayer = this;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v8 = Value[1];
  if ( v8 < Value[3] )
  {
    *(_QWORD *)v8 = "TtcheckSupport";
    v9 = __rdtsc();
    *(_DWORD *)(v8 + 8) = v9;
    Value[1] = v8 + 16;
  }
  v10 = _mm_xor_ps(this->m_up.m_quad, (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
  array = 0i64;
  v103 = 0;
  v104 = 0x80000000;
  v106 = 20;
  v11 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (__m128 *)v11->m_cur;
  v13 = m_cur + 80;
  if ( v11->m_slabSize < 1280 || v13 > v11->m_end )
    m_cur = (__m128 *)hkLifoAllocator::allocateFromNewSlab(v11, 1280);
  else
    v11->m_cur = v13;
  array = m_cur;
  v104 = -2147483628;
  p = m_cur;
  p_m_collisionEntries = &this->m_character->m_collidable.m_collisionEntries;
  DoesBoundingBoxProvideSupport = CharacterRigidBody::DoesBoundingBoxProvideSupport(this, p_m_collisionEntries);
  v116 = DoesBoundingBoxProvideSupport;
  v16 = FLOAT_3_4028235e38;
  v17 = 0;
  v119 = 0;
  if ( p_m_collisionEntries->m_size > 0 )
  {
    v18 = 0i64;
    do
    {
      m_contactMgr = p_m_collisionEntries->m_data[v18].m_agentEntry->m_contactMgr;
      if ( m_contactMgr->m_type == TYPE_SIMPLE_CONSTRAINT_CONTACT_MGR )
      {
        v20 = 0;
        if ( *(_WORD *)(*(_QWORD *)&m_contactMgr[4].m_memSizeAndFlags + 4i64) )
        {
          do
          {
            v21 = LODWORD(m_contactMgr[3].vfptr) - 1;
            for ( i = v21; i >= 0; --i )
            {
              if ( *(unsigned __int8 *)(i + *(_QWORD *)&m_contactMgr[2].m_type) == v20 )
                break;
              LOWORD(v21) = v21 - 1;
            }
            v23 = 32i64 * *(unsigned __int8 *)((unsigned __int16)v21 + *(_QWORD *)&m_contactMgr[2].m_type);
            v24 = *(_QWORD *)&m_contactMgr[4].m_memSizeAndFlags;
            v25 = _mm_sub_ps(
                    *(__m128 *)(v23 + v24 + 48),
                    this->m_character->m_motion.m_motionState.m_transform.m_translation.m_quad);
            v26 = _mm_shuffle_ps(v25, v25, 170).m128_f32[0];
            if ( v16 > v26 )
              v16 = v26;
            v27 = v103;
            if ( v103 == (v104 & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 64);
              v27 = v103;
            }
            v28 = (hkSurfaceConstraintInteraction *)&array[4 * (__int64)v27];
            output.m_planeInteractions = v28;
            v29 = 0;
            input.m_upVector.m_quad.m128_i32[0] = 0;
            do
            {
              *(_QWORD *)&output.m_deltaTime = &v28[4 * (__int64)v29++];
              input.m_upVector.m_quad.m128_i32[0] = v29;
            }
            while ( v29 < 1 );
            v30 = &array[4 * (__int64)v103++];
            if ( p_m_collisionEntries->m_data[v18].m_agentEntry->m_collidable[0] == &this->m_character->m_collidable )
              v31 = *(float *)&FLOAT_1_0;
            else
              v31 = FLOAT_N1_0;
            *(float *)&a4 = v31;
            *(__m128 *)&a4 = _mm_shuffle_ps(*(__m128 *)&a4, *(__m128 *)&a4, 0);
            *v30 = _mm_mul_ps(*(__m128 *)(v23 + v24 + 64), *(__m128 *)&a4);
            v30->m128_i32[3] = *(_DWORD *)(v23 + v24 + 76);
            *(unsigned __int64 *)((char *)&v30[2].m128_u64[1] + 4) = 0i64;
            v30[1] = 0i64;
            v30[2].m128_u64[0] = 0i64;
            v30[2].m128_i32[2] = 0;
            m_partner = p_m_collisionEntries->m_data[v18].m_partner;
            if ( m_partner->m_broadPhaseHandle.m_type == 1 )
            {
              v33 = (__m128 *)((char *)m_partner + m_partner->m_ownerOffset);
              if ( v33 )
              {
                v34 = v33[22].m128_i8[0];
                if ( v34 == 5 || v34 == 4 )
                {
                  v35 = _mm_sub_ps(*(__m128 *)(v23 + v24 + 48), v33[28]);
                  v36 = _mm_sub_ps(
                          _mm_mul_ps(_mm_shuffle_ps(v35, v35, 201), v33[36]),
                          _mm_mul_ps(_mm_shuffle_ps(v33[36], v33[36], 201), v35));
                  v37 = _mm_shuffle_ps(v36, v36, 201);
                  v30[1] = v37;
                  v30[1] = _mm_add_ps(v33[35], v37);
                }
                v38 = 0;
                if ( v33[22].m128_i8[0] == 5 )
                  v38 = 2;
                v30[3].m128_i32[0] = v38;
                if ( v33[22].m128_i8[0] == 4 )
                  v38 = 1;
                v30[3].m128_i32[0] = v38;
              }
            }
            v39 = (__m128)v30->m128_u32[3];
            if ( v39.m128_f32[0] < -0.00000011920929 )
            {
              v39.m128_f32[0] = v39.m128_f32[0] * this->m_penetrationRecoverySpeed;
              v40 = _mm_xor_ps(v39, (__m128)(unsigned int)_xmm[0]);
              v30[1] = _mm_add_ps(
                         _mm_mul_ps(
                           _mm_shuffle_ps(v40, v40, 0),
                           _mm_mul_ps(*(__m128 *)(v23 + v24 + 64), *(__m128 *)&a4)),
                         v30[1]);
            }
            if ( this->m_supportDistance > v30->m128_f32[3] )
              v30->m128_i32[3] = 0;
            ++v20;
          }
          while ( v20 < *(unsigned __int16 *)(*(_QWORD *)&m_contactMgr[4].m_memSizeAndFlags + 4i64) );
          v17 = v119;
        }
      }
      v119 = ++v17;
      ++v18;
    }
    while ( v17 < p_m_collisionEntries->m_size );
    v4 = (__m128 *)v118;
    v5 = stepInfo;
    DoesBoundingBoxProvideSupport = v116;
  }
  v41 = v104 & 0x3FFFFFFF;
  m_userPlanes = this->m_userPlanes;
  v43 = v103;
  if ( (v104 & 0x3FFFFFFF) - v103 < m_userPlanes )
  {
    v44 = m_userPlanes + v103;
    if ( v41 < m_userPlanes + v103 )
    {
      if ( v44 < 2 * v41 )
        v44 = 2 * v41;
      hkArrayUtil::_reserve((hkResult *)&v118, &hkContainerHeapAllocator::s_alloc, &array, v44, 64);
      v43 = v103;
    }
  }
  v45 = this->m_userPlanes;
  v46 = v43 + v45 == 0;
  v47 = v43 + v45;
  v107 = 0i64;
  v108 = 0;
  v109 = 0x80000000;
  input.m_position.m_quad.m128_i32[2] = v47;
  if ( v46 )
  {
    v50 = 0i64;
  }
  else
  {
    v48 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v49 = (((16 * v47 + 127) & 0xFFFFFF80) + 15) & 0xFFFFFFF0;
    v50 = (hkSurfaceConstraintInteraction *)v48->m_cur;
    v51 = &v50->m_touched + v49;
    if ( v49 > v48->m_slabSize || v51 > v48->m_end )
      v50 = (hkSurfaceConstraintInteraction *)hkLifoAllocator::allocateFromNewSlab(v48, v49);
    else
      v48->m_cur = v51;
  }
  v107 = v50;
  v109 = v47 | 0x80000000;
  input.m_position.m_quad.m128_u64[0] = (unsigned __int64)v50;
  v46 = this->m_userPlanes + v103 == 0;
  v52 = this->m_userPlanes + v103;
  input.m_velocity.m_quad.m128_u64[0] = 0i64;
  input.m_velocity.m_quad.m128_u64[1] = 0x8000000000000000ui64;
  input.m_maxSurfaceVelocity.m_quad.m128_i32[2] = v52;
  if ( v46 )
  {
    v55 = 0i64;
  }
  else
  {
    v53 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v54 = (((16 * v52 + 127) & 0xFFFFFF80) + 15) & 0xFFFFFFF0;
    v55 = (char *)v53->m_cur;
    v56 = &v55[v54];
    if ( v54 > v53->m_slabSize || v56 > v53->m_end )
      v55 = (char *)hkLifoAllocator::allocateFromNewSlab(v53, v54);
    else
      v53->m_cur = v56;
  }
  input.m_velocity.m_quad.m128_u64[0] = (unsigned __int64)v55;
  input.m_velocity.m_quad.m128_i32[3] = v52 | 0x80000000;
  input.m_maxSurfaceVelocity.m_quad.m128_u64[0] = (unsigned __int64)v55;
  *(_OWORD *)&input.m_deltaTime = 0i64;
  output.m_position.m_quad.m128_u64[1] = (unsigned __int64)array;
  v57 = v103;
  v58 = v103;
  output.m_velocity.m_quad.m128_i32[0] = v103;
  *(__m128 *)&input.m_numConstraints = v10;
  output.m_position.m_quad.m128_i32[0] = LODWORD(v5->m_deltaTime.m_storage);
  output.m_position.m_quad.m128_i32[1] = output.m_position.m_quad.m128_i32[0];
  v112.m_quad = (__m128)this->m_up;
  v111 = _mm_shuffle_ps(
           (__m128)LODWORD(this->m_maxSpeedForSimplexSolver),
           (__m128)LODWORD(this->m_maxSpeedForSimplexSolver),
           0);
  v115.m_planeInteractions = v107;
  v59 = v103;
  if ( (input.m_velocity.m_quad.m128_i32[3] & 0x3FFFFFFF) < v103 )
  {
    if ( v103 < 2 * (input.m_velocity.m_quad.m128_i32[3] & 0x3FFFFFFF) )
      v57 = 2 * (input.m_velocity.m_quad.m128_i32[3] & 0x3FFFFFFF);
    hkArrayUtil::_reserve((hkResult *)&v118, &hkContainerHeapAllocator::s_alloc, &input.m_velocity, v57, 16);
    v57 = v103;
    v58 = output.m_velocity.m_quad.m128_i32[0];
  }
  input.m_velocity.m_quad.m128_i32[2] = v59;
  v60 = v58;
  if ( (v109 & 0x3FFFFFFF) < v58 )
  {
    if ( v58 < 2 * (v109 & 0x3FFFFFFF) )
      v58 = 2 * (v109 & 0x3FFFFFFF);
    hkArrayUtil::_reserve((hkResult *)&v118, &hkContainerHeapAllocator::s_alloc, &v107, v58, 16);
    v57 = v103;
    v58 = output.m_velocity.m_quad.m128_i32[0];
  }
  v108 = v60;
  v61 = v58;
  if ( (v104 & 0x3FFFFFFF) < v58 )
  {
    if ( v58 < 2 * (v104 & 0x3FFFFFFF) )
      v58 = 2 * (v104 & 0x3FFFFFFF);
    hkArrayUtil::_reserve((hkResult *)&v118, &hkContainerHeapAllocator::s_alloc, &array, v58, 64);
    v57 = v103;
    v58 = output.m_velocity.m_quad.m128_i32[0];
  }
  v62 = 0;
  LODWORD(v118) = 0;
  if ( v61 - v57 > 0 )
  {
    do
      LODWORD(v118) = ++v62;
    while ( v62 < v61 - v103 );
    v58 = output.m_velocity.m_quad.m128_i32[0];
  }
  v103 = v61;
  v63 = 0;
  if ( v58 > 0 )
  {
    v64 = 0i64;
    v65 = 0i64;
    do
    {
      *(__m128 *)(v65 + input.m_velocity.m_quad.m128_u64[0]) = array[v64 + 1];
      array[v64 + 1] = 0i64;
      ++v63;
      v65 += 16i64;
      v64 += 4i64;
    }
    while ( v63 < output.m_velocity.m_quad.m128_i32[0] );
  }
  hkSimplexSolverSolve((hkSimplexSolverInput *)&input.m_deltaTime, &v115);
  v4[2] = 0i64;
  v4[1] = 0i64;
  if ( (_mm_movemask_ps(
          _mm_cmple_ps(
            (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(v115.m_velocity.m_quad, v10), 1u), 1u),
            (__m128)_xmm)) & 7) == 7 )
    goto LABEL_90;
  v66 = _mm_mul_ps(v115.m_velocity.m_quad, v115.m_velocity.m_quad);
  if ( (float)(_mm_shuffle_ps(v66, v66, 170).m128_f32[0]
             + (float)(_mm_shuffle_ps(v66, v66, 85).m128_f32[0] + _mm_shuffle_ps(v66, v66, 0).m128_f32[0])) >= 0.001 )
  {
    v67 = _mm_add_ps(
            _mm_shuffle_ps(v66, v66, 170),
            _mm_add_ps(_mm_shuffle_ps(v66, v66, 85), _mm_shuffle_ps(v66, v66, 0)));
    v68 = _mm_rsqrt_ps(v67);
    v115.m_velocity.m_quad = _mm_mul_ps(
                               v115.m_velocity.m_quad,
                               _mm_andnot_ps(
                                 _mm_cmple_ps(v67, (__m128)0i64),
                                 _mm_mul_ps(
                                   _mm_mul_ps(v68, *(__m128 *)_xmm),
                                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v68, v67), v68)))));
    v69 = _mm_mul_ps(v10, v115.m_velocity.m_quad);
    v69.m128_f32[0] = _mm_shuffle_ps(v69, v69, 170).m128_f32[0]
                    + (float)(_mm_shuffle_ps(v69, v69, 85).m128_f32[0] + _mm_shuffle_ps(v69, v69, 0).m128_f32[0]);
    v4->m128_i32[0] = ((float)(this->m_maxSlopeCosine * this->m_maxSlopeCosine) <= (float)(1.0
                                                                                         - (float)(v69.m128_f32[0]
                                                                                                 * v69.m128_f32[0])))
                    + 1;
  }
  else
  {
    v4->m128_i32[0] = 2;
  }
  v70 = 0;
  v71 = output.m_velocity.m_quad.m128_u32[0];
  if ( output.m_velocity.m_quad.m128_i32[0] <= 0 )
    goto LABEL_90;
  v72 = (__m128 *)input.m_velocity.m_quad.m128_u64[0];
  v73 = array;
  v74 = &v107->m_touched - input.m_velocity.m_quad.m128_u64[0];
  do
  {
    if ( v72->m128_i8[(_QWORD)v74] )
    {
      v75 = _mm_mul_ps(*v73, v10);
      if ( (float)(_mm_shuffle_ps(v75, v75, 170).m128_f32[0]
                 + (float)(_mm_shuffle_ps(v75, v75, 85).m128_f32[0] + _mm_shuffle_ps(v75, v75, 0).m128_f32[0])) < -0.079999998 )
      {
        v4[1] = _mm_add_ps(*v73, v4[1]);
        v4[2] = _mm_add_ps(*v72, v4[2]);
        ++v70;
      }
    }
    v73 += 4;
    ++v72;
    --v71;
  }
  while ( v71 );
  if ( v70 <= 0 )
  {
LABEL_90:
    v4->m128_i32[0] = 0;
  }
  else
  {
    v76 = v4[1];
    v77 = _mm_mul_ps(v76, v76);
    v78 = _mm_add_ps(
            _mm_shuffle_ps(v77, v77, 170),
            _mm_add_ps(_mm_shuffle_ps(v77, v77, 85), _mm_shuffle_ps(v77, v77, 0)));
    v79 = _mm_rsqrt_ps(v78);
    v80 = _mm_mul_ps(_mm_mul_ps(v79, v78), v79);
    v4[1] = _mm_mul_ps(
              _mm_andnot_ps(
                _mm_cmple_ps(v78, (__m128)0i64),
                _mm_mul_ps(_mm_mul_ps(v79, *(__m128 *)_xmm), _mm_sub_ps((__m128)_xmm, v80))),
              v76);
    v80.m128_f32[0] = 1.0 / (float)v70;
    v4[2] = _mm_mul_ps(_mm_shuffle_ps(v80, v80, 0), v4[2]);
    if ( v4->m128_i32[0] && !DoesBoundingBoxProvideSupport )
    {
      v4->m128_i32[0] = 0;
      this->m_supportedOffCentre = 1;
      goto LABEL_92;
    }
  }
  this->m_supportedOffCentre = 0;
LABEL_92:
  v81 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v82 = v81[1];
  if ( v82 < v81[3] )
  {
    *(_QWORD *)v82 = "Et";
    v83 = __rdtsc();
    *(_DWORD *)(v82 + 8) = v83;
    v81[1] = v82 + 16;
  }
  v84 = (char *)input.m_maxSurfaceVelocity.m_quad.m128_u64[0];
  v85 = input.m_velocity.m_quad.m128_i32[2];
  if ( input.m_maxSurfaceVelocity.m_quad.m128_u64[0] == input.m_velocity.m_quad.m128_u64[0] )
    v85 = 0;
  input.m_velocity.m_quad.m128_i32[2] = v85;
  v86 = input.m_maxSurfaceVelocity.m_quad.m128_i32[2];
  v87 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v88 = (16 * v86 + 127) & 0xFFFFFF80;
  v89 = (v88 + 15) & 0xFFFFFFF0;
  if ( v88 > v87->m_slabSize || &v84[v89] != v87->m_cur || v87->m_firstNonLifoEnd == v84 )
    hkLifoAllocator::slowBlockFree(v87, v84, v89);
  else
    v87->m_cur = v84;
  input.m_velocity.m_quad.m128_i32[2] = 0;
  if ( input.m_velocity.m_quad.m128_i32[3] >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      (void *)input.m_velocity.m_quad.m128_u64[0],
      16 * input.m_velocity.m_quad.m128_i32[3]);
  input.m_velocity.m_quad.m128_u64[0] = 0i64;
  input.m_velocity.m_quad.m128_i32[3] = 0x80000000;
  v90 = (char *)input.m_position.m_quad.m128_u64[0];
  v91 = v108;
  if ( (hkSurfaceConstraintInteraction *)input.m_position.m_quad.m128_u64[0] == v107 )
    v91 = 0;
  v108 = v91;
  v92 = input.m_position.m_quad.m128_i32[2];
  v93 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v94 = (16 * v92 + 127) & 0xFFFFFF80;
  v95 = (v94 + 15) & 0xFFFFFFF0;
  if ( v94 > v93->m_slabSize || &v90[v95] != v93->m_cur || v93->m_firstNonLifoEnd == v90 )
    hkLifoAllocator::slowBlockFree(v93, v90, v95);
  else
    v93->m_cur = v90;
  v108 = 0;
  if ( v109 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v107, 16 * v109);
  v107 = 0i64;
  v109 = 0x80000000;
  v96 = (char *)p;
  v97 = v103;
  if ( p == array )
    v97 = 0;
  v103 = v97;
  v98 = v106;
  v99 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v100 = ((v98 << 6) + 127) & 0xFFFFFF80;
  v101 = (v100 + 15) & 0xFFFFFFF0;
  if ( v100 > v99->m_slabSize || &v96[v101] != v99->m_cur || v99->m_firstNonLifoEnd == v96 )
    hkLifoAllocator::slowBlockFree(v99, v96, v101);
  else
    v99->m_cur = v96;
  v103 = 0;
  if ( v104 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, v104 << 6);
}

// File Line: 505
// RVA: 0x484A90
// local variable allocation has failed, the output may be wrong!
void __fastcall CharacterRigidBody::checkSupportForNonPlayer(
        CharacterRigidBody *this,
        hkStepInfo *stepInfo,
        hkpSurfaceInfo *ground,
        double a4)
{
  _QWORD *Value; // r9
  unsigned __int64 v8; // rcx
  unsigned __int64 v9; // rax
  hkVector4f v10; // xmm12
  hkLifoAllocator *v11; // rax
  hkSurfaceConstraintInfo *m_cur; // rcx
  hkSurfaceConstraintInfo *v13; // rdx
  hkArray<hkpLinkedCollidable::CollisionEntry,hkContainerHeapAllocator> *p_m_collisionEntries; // r12
  char v15; // al
  float v16; // xmm6_4
  __int64 v17; // r13
  hkpContactMgr *m_contactMgr; // r14
  int v19; // ebx
  int v20; // edx
  __int64 i; // rcx
  __int64 v22; // rdi
  __int64 v23; // rsi
  __m128 v24; // xmm0
  float v25; // xmm0_4
  int v26; // ecx
  __int64 v27; // rdx
  int v28; // ecx
  hkSurfaceConstraintInfo *v29; // rdx
  float v30; // xmm0_4
  hkpLinkedCollidable *m_partner; // r8
  __m128 *v32; // rcx
  char v33; // r8
  __m128 v34; // xmm1
  __m128 v35; // xmm2
  __m128 v36; // xmm2
  int v37; // eax
  __m128 v38; // xmm1
  __m128 v39; // xmm1
  int v40; // ecx
  int m_userPlanes; // r8d
  int v42; // edx
  int v43; // r9d
  int v44; // ebx
  bool v45; // zf
  int v46; // ebx
  hkLifoAllocator *v47; // r8
  int v48; // edx
  hkSurfaceConstraintInteraction *v49; // rax
  char *v50; // rcx
  int v51; // ebx
  hkLifoAllocator *v52; // rax
  int v53; // edx
  char *v54; // rcx
  char *v55; // r8
  int v56; // r8d
  int m_numConstraints; // edx
  int v58; // ebx
  int v59; // ebx
  int v60; // ebx
  hkResultEnum v61; // ecx
  int v62; // r9d
  __int64 v63; // rdx
  __int64 v64; // r8
  __m128 v65; // xmm4
  __m128 v66; // xmm4
  __m128 v67; // xmm0
  __m128 v68; // xmm2
  int v69; // edx
  __int64 v70; // r8
  __m128 *v71; // rax
  __m128 *p_m_quad; // rcx
  char *v73; // r9
  __m128 v74; // xmm2
  hkVector4f v75; // xmm5
  __m128 v76; // xmm3
  __m128 v77; // xmm3
  __m128 v78; // xmm0
  __m128 v79; // xmm1
  _QWORD *v80; // r8
  unsigned __int64 v81; // rcx
  unsigned __int64 v82; // rax
  char *v83; // rdi
  int v84; // ecx
  int v85; // ebx
  hkLifoAllocator *v86; // rcx
  signed int v87; // ebx
  int v88; // r8d
  char *v89; // rdi
  int v90; // ecx
  int v91; // ebx
  hkLifoAllocator *v92; // rcx
  signed int v93; // ebx
  int v94; // r8d
  char *v95; // rdi
  int v96; // ecx
  int v97; // ebx
  hkLifoAllocator *v98; // rcx
  signed int v99; // ebx
  int v100; // r8d
  hkSurfaceConstraintInfo *array; // [rsp+30h] [rbp-90h] BYREF
  int v102; // [rsp+38h] [rbp-88h]
  int v103; // [rsp+3Ch] [rbp-84h]
  void *p; // [rsp+40h] [rbp-80h]
  int v105; // [rsp+48h] [rbp-78h]
  hkSurfaceConstraintInteraction *v106; // [rsp+50h] [rbp-70h] BYREF
  int v107; // [rsp+58h] [rbp-68h]
  int v108; // [rsp+5Ch] [rbp-64h]
  hkSimplexSolverInput input; // [rsp+60h] [rbp-60h] BYREF
  __int64 v110; // [rsp+C0h] [rbp+0h]
  __int64 v111; // [rsp+C8h] [rbp+8h]
  __int64 v112; // [rsp+D0h] [rbp+10h]
  hkSimplexSolverOutput output; // [rsp+E0h] [rbp+20h] BYREF
  hkSurfaceConstraintInfo *v114; // [rsp+1D0h] [rbp+110h]
  hkStepInfo *v115; // [rsp+1D8h] [rbp+118h]
  hkResult result[2]; // [rsp+1E0h] [rbp+120h] BYREF
  int v117; // [rsp+1E8h] [rbp+128h]

  v112 = -2i64;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v8 = Value[1];
  if ( v8 < Value[3] )
  {
    *(_QWORD *)v8 = "TtcheckSupport";
    v9 = __rdtsc();
    *(_DWORD *)(v8 + 8) = v9;
    Value[1] = v8 + 16;
  }
  v10.m_quad = _mm_xor_ps(this->m_up.m_quad, (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
  array = 0i64;
  v102 = 0;
  v103 = 0x80000000;
  v105 = 20;
  v11 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (hkSurfaceConstraintInfo *)v11->m_cur;
  v13 = m_cur + 20;
  if ( v11->m_slabSize < 1280 || v13 > v11->m_end )
    m_cur = (hkSurfaceConstraintInfo *)hkLifoAllocator::allocateFromNewSlab(v11, 1280);
  else
    v11->m_cur = v13;
  array = m_cur;
  v103 = -2147483628;
  p = m_cur;
  p_m_collisionEntries = &this->m_character->m_collidable.m_collisionEntries;
  v15 = !CharacterRigidBody::DoesBoundingBoxProvideSupport(this, p_m_collisionEntries);
  LOBYTE(v114) = v15;
  if ( v15 )
    ground->m_supportedState = UNSUPPORTED;
  v16 = FLOAT_3_4028235e38;
  v117 = 0;
  if ( p_m_collisionEntries->m_size > 0 )
  {
    v17 = 0i64;
    do
    {
      if ( v15 )
        break;
      m_contactMgr = p_m_collisionEntries->m_data[v17].m_agentEntry->m_contactMgr;
      if ( m_contactMgr->m_type == TYPE_SIMPLE_CONSTRAINT_CONTACT_MGR )
      {
        v19 = 0;
        if ( *(_WORD *)(*(_QWORD *)&m_contactMgr[4].m_memSizeAndFlags + 4i64) )
        {
          do
          {
            v20 = LODWORD(m_contactMgr[3].vfptr) - 1;
            for ( i = v20; i >= 0; --i )
            {
              if ( *(unsigned __int8 *)(i + *(_QWORD *)&m_contactMgr[2].m_type) == v19 )
                break;
              LOWORD(v20) = v20 - 1;
            }
            v22 = 32i64 * *(unsigned __int8 *)((unsigned __int16)v20 + *(_QWORD *)&m_contactMgr[2].m_type);
            v23 = *(_QWORD *)&m_contactMgr[4].m_memSizeAndFlags;
            v24 = _mm_sub_ps(
                    *(__m128 *)(v22 + v23 + 48),
                    this->m_character->m_motion.m_motionState.m_transform.m_translation.m_quad);
            v25 = _mm_shuffle_ps(v24, v24, 170).m128_f32[0];
            if ( v16 > v25 )
              v16 = v25;
            v26 = v102;
            if ( v102 == (v103 & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 64);
              v26 = v102;
            }
            v27 = (__int64)&array[(__int64)v26];
            v111 = v27;
            v28 = 0;
            LODWORD(v106) = 0;
            do
            {
              v110 = v27 + ((__int64)v28++ << 6);
              LODWORD(v106) = v28;
            }
            while ( v28 < 1 );
            v29 = &array[(__int64)v102++];
            if ( p_m_collisionEntries->m_data[v17].m_agentEntry->m_collidable[0] == &this->m_character->m_collidable )
              v30 = *(float *)&FLOAT_1_0;
            else
              v30 = FLOAT_N1_0;
            *(float *)&a4 = v30;
            *(__m128 *)&a4 = _mm_shuffle_ps(*(__m128 *)&a4, *(__m128 *)&a4, 0);
            v29->m_plane.m_quad = _mm_mul_ps(*(__m128 *)(v22 + v23 + 64), *(__m128 *)&a4);
            v29->m_plane.m_quad.m128_i32[3] = *(_DWORD *)(v22 + v23 + 76);
            *(_QWORD *)&v29->m_dynamicFriction = 0i64;
            v29->m_velocity = 0i64;
            *(_QWORD *)&v29->m_staticFriction = 0i64;
            v29->m_extraDownStaticFriction = 0.0;
            m_partner = p_m_collisionEntries->m_data[v17].m_partner;
            if ( m_partner->m_broadPhaseHandle.m_type == 1 )
            {
              v32 = (__m128 *)((char *)m_partner + m_partner->m_ownerOffset);
              if ( v32 )
              {
                v33 = v32[22].m128_i8[0];
                if ( v33 == 5 || v33 == 4 )
                {
                  v34 = _mm_sub_ps(*(__m128 *)(v22 + v23 + 48), v32[28]);
                  v35 = _mm_sub_ps(
                          _mm_mul_ps(_mm_shuffle_ps(v34, v34, 201), v32[36]),
                          _mm_mul_ps(_mm_shuffle_ps(v32[36], v32[36], 201), v34));
                  v36 = _mm_shuffle_ps(v35, v35, 201);
                  v29->m_velocity.m_quad = v36;
                  v29->m_velocity.m_quad = _mm_add_ps(v32[35], v36);
                }
                v37 = 0;
                if ( v32[22].m128_i8[0] == 5 )
                  v37 = 2;
                v29->m_priority = v37;
                if ( v32[22].m128_i8[0] == 4 )
                  v37 = 1;
                v29->m_priority = v37;
              }
            }
            v38 = (__m128)v29->m_plane.m_quad.m128_u32[3];
            if ( v38.m128_f32[0] < -0.00000011920929 )
            {
              v38.m128_f32[0] = v38.m128_f32[0] * this->m_penetrationRecoverySpeed;
              v39 = _mm_xor_ps(v38, (__m128)(unsigned int)_xmm[0]);
              v29->m_velocity.m_quad = _mm_add_ps(
                                         v29->m_velocity.m_quad,
                                         _mm_mul_ps(
                                           _mm_shuffle_ps(v39, v39, 0),
                                           _mm_mul_ps(*(__m128 *)(v22 + v23 + 64), *(__m128 *)&a4)));
            }
            if ( this->m_supportDistance > v29->m_plane.m_quad.m128_f32[3] )
              v29->m_plane.m_quad.m128_i32[3] = 0;
            ++v19;
          }
          while ( v19 < *(unsigned __int16 *)(*(_QWORD *)&m_contactMgr[4].m_memSizeAndFlags + 4i64) );
        }
      }
      ++v117;
      ++v17;
      v15 = (char)v114;
    }
    while ( v117 < p_m_collisionEntries->m_size );
    ground = *(hkpSurfaceInfo **)&result[0].m_enum;
    stepInfo = v115;
  }
  v40 = v103 & 0x3FFFFFFF;
  m_userPlanes = this->m_userPlanes;
  v42 = v102;
  if ( (v103 & 0x3FFFFFFF) - v102 < m_userPlanes )
  {
    v43 = m_userPlanes + v102;
    if ( v40 < m_userPlanes + v102 )
    {
      if ( v43 < 2 * v40 )
        v43 = 2 * v40;
      hkArrayUtil::_reserve(result, &hkContainerHeapAllocator::s_alloc, &array, v43, 64);
      v42 = v102;
    }
  }
  v44 = this->m_userPlanes;
  v45 = v42 + v44 == 0;
  v46 = v42 + v44;
  v106 = 0i64;
  v107 = 0;
  v108 = 0x80000000;
  input.m_position.m_quad.m128_i32[2] = v46;
  if ( v45 )
  {
    v49 = 0i64;
  }
  else
  {
    v47 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v48 = (((16 * v46 + 127) & 0xFFFFFF80) + 15) & 0xFFFFFFF0;
    v49 = (hkSurfaceConstraintInteraction *)v47->m_cur;
    v50 = &v49->m_touched + v48;
    if ( v48 > v47->m_slabSize || v50 > v47->m_end )
      v49 = (hkSurfaceConstraintInteraction *)hkLifoAllocator::allocateFromNewSlab(v47, v48);
    else
      v47->m_cur = v50;
  }
  v106 = v49;
  v108 = v46 | 0x80000000;
  input.m_position.m_quad.m128_u64[0] = (unsigned __int64)v49;
  v45 = this->m_userPlanes + v102 == 0;
  v51 = this->m_userPlanes + v102;
  input.m_velocity.m_quad.m128_u64[0] = 0i64;
  input.m_velocity.m_quad.m128_u64[1] = 0x8000000000000000ui64;
  v105 = v51;
  if ( v45 )
  {
    v54 = 0i64;
  }
  else
  {
    v52 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v53 = (((16 * v51 + 127) & 0xFFFFFF80) + 15) & 0xFFFFFFF0;
    v54 = (char *)v52->m_cur;
    v55 = &v54[v53];
    if ( v53 > v52->m_slabSize || v55 > v52->m_end )
      v54 = (char *)hkLifoAllocator::allocateFromNewSlab(v52, v53);
    else
      v52->m_cur = v55;
  }
  p = v54;
  input.m_position = 0i64;
  input.m_constraints = array;
  v56 = v102;
  m_numConstraints = v102;
  input.m_numConstraints = v102;
  input.m_velocity = (hkVector4f)v10.m_quad;
  input.m_deltaTime = stepInfo->m_deltaTime.m_storage;
  input.m_minDeltaTime = input.m_deltaTime;
  input.m_upVector = this->m_up;
  input.m_maxSurfaceVelocity.m_quad = _mm_shuffle_ps(
                                        (__m128)LODWORD(this->m_maxSpeedForSimplexSolver),
                                        (__m128)LODWORD(this->m_maxSpeedForSimplexSolver),
                                        0);
  output.m_planeInteractions = v106;
  v58 = v102;
  if ( (v10.m_quad.m128_i32[3] & 0x3FFFFFFF) < v102 )
  {
    if ( v102 < 2 * (v10.m_quad.m128_i32[3] & 0x3FFFFFFF) )
      v56 = 2 * (v10.m_quad.m128_i32[3] & 0x3FFFFFFF);
    hkArrayUtil::_reserve(result, &hkContainerHeapAllocator::s_alloc, &input.m_velocity, v56, 16);
    v56 = v102;
    m_numConstraints = input.m_numConstraints;
  }
  input.m_velocity.m_quad.m128_i32[2] = v58;
  v59 = m_numConstraints;
  if ( (v108 & 0x3FFFFFFF) < m_numConstraints )
  {
    if ( m_numConstraints < 2 * (v108 & 0x3FFFFFFF) )
      m_numConstraints = 2 * (v108 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(result, &hkContainerHeapAllocator::s_alloc, &v106, m_numConstraints, 16);
    v56 = v102;
    m_numConstraints = input.m_numConstraints;
  }
  v107 = v59;
  v60 = m_numConstraints;
  if ( (v103 & 0x3FFFFFFF) < m_numConstraints )
  {
    if ( m_numConstraints < 2 * (v103 & 0x3FFFFFFF) )
      m_numConstraints = 2 * (v103 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(result, &hkContainerHeapAllocator::s_alloc, &array, m_numConstraints, 64);
    v56 = v102;
    m_numConstraints = input.m_numConstraints;
  }
  v115 = (hkStepInfo *)&array[(__int64)v56];
  v61 = HK_SUCCESS;
  result[0].m_enum = HK_SUCCESS;
  if ( v60 - v56 > 0 )
  {
    do
    {
      v114 = &array[v56 + (__int64)(int)v61++];
      result[0].m_enum = v61;
    }
    while ( v61 < v60 - v102 );
    m_numConstraints = input.m_numConstraints;
  }
  v102 = v60;
  v62 = 0;
  if ( m_numConstraints > 0 )
  {
    v63 = 0i64;
    v64 = 0i64;
    do
    {
      *(hkVector4f *)(v64 + input.m_velocity.m_quad.m128_u64[0]) = array[v63].m_velocity;
      array[v63].m_velocity = 0i64;
      ++v62;
      v64 += 16i64;
      ++v63;
    }
    while ( v62 < input.m_numConstraints );
  }
  hkSimplexSolverSolve(&input, &output);
  ground->m_surfaceVelocity = 0i64;
  ground->m_surfaceNormal = 0i64;
  if ( (_mm_movemask_ps(
          _mm_cmple_ps(
            (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(output.m_velocity.m_quad, v10.m_quad), 1u), 1u),
            (__m128)_xmm)) & 7) == 7 )
    goto LABEL_90;
  v65 = _mm_mul_ps(output.m_velocity.m_quad, output.m_velocity.m_quad);
  if ( (float)(_mm_shuffle_ps(v65, v65, 170).m128_f32[0]
             + (float)(_mm_shuffle_ps(v65, v65, 85).m128_f32[0] + _mm_shuffle_ps(v65, v65, 0).m128_f32[0])) >= 0.001 )
  {
    v66 = _mm_add_ps(
            _mm_shuffle_ps(v65, v65, 170),
            _mm_add_ps(_mm_shuffle_ps(v65, v65, 85), _mm_shuffle_ps(v65, v65, 0)));
    v67 = _mm_rsqrt_ps(v66);
    output.m_velocity.m_quad = _mm_mul_ps(
                                 output.m_velocity.m_quad,
                                 _mm_andnot_ps(
                                   _mm_cmple_ps(v66, (__m128)0i64),
                                   _mm_mul_ps(
                                     _mm_mul_ps(v67, *(__m128 *)_xmm),
                                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v67, v66), v67)))));
    v68 = _mm_mul_ps(v10.m_quad, output.m_velocity.m_quad);
    v68.m128_f32[0] = _mm_shuffle_ps(v68, v68, 170).m128_f32[0]
                    + (float)(_mm_shuffle_ps(v68, v68, 85).m128_f32[0] + _mm_shuffle_ps(v68, v68, 0).m128_f32[0]);
    ground->m_supportedState = ((float)(this->m_maxSlopeCosine * this->m_maxSlopeCosine) <= (float)(1.0
                                                                                                  - (float)(v68.m128_f32[0] * v68.m128_f32[0])))
                             + 1;
  }
  else
  {
    ground->m_supportedState = SUPPORTED;
  }
  v69 = 0;
  v70 = (unsigned int)input.m_numConstraints;
  if ( input.m_numConstraints <= 0 )
    goto LABEL_90;
  v71 = (__m128 *)input.m_velocity.m_quad.m128_u64[0];
  p_m_quad = &array->m_plane.m_quad;
  v73 = &v106->m_touched - input.m_velocity.m_quad.m128_u64[0];
  do
  {
    if ( v71->m128_i8[(_QWORD)v73] )
    {
      v74 = _mm_mul_ps(*p_m_quad, v10.m_quad);
      if ( (float)(_mm_shuffle_ps(v74, v74, 170).m128_f32[0]
                 + (float)(_mm_shuffle_ps(v74, v74, 85).m128_f32[0] + _mm_shuffle_ps(v74, v74, 0).m128_f32[0])) < -0.079999998 )
      {
        ground->m_surfaceNormal.m_quad = _mm_add_ps(*p_m_quad, ground->m_surfaceNormal.m_quad);
        ground->m_surfaceVelocity.m_quad = _mm_add_ps(*v71, ground->m_surfaceVelocity.m_quad);
        ++v69;
      }
    }
    p_m_quad += 4;
    ++v71;
    --v70;
  }
  while ( v70 );
  if ( v69 <= 0 )
  {
LABEL_90:
    ground->m_supportedState = UNSUPPORTED;
  }
  else
  {
    v75.m_quad = (__m128)ground->m_surfaceNormal;
    v76 = _mm_mul_ps(v75.m_quad, v75.m_quad);
    v77 = _mm_add_ps(
            _mm_shuffle_ps(v76, v76, 170),
            _mm_add_ps(_mm_shuffle_ps(v76, v76, 85), _mm_shuffle_ps(v76, v76, 0)));
    v78 = _mm_rsqrt_ps(v77);
    v79 = _mm_mul_ps(_mm_mul_ps(v78, v77), v78);
    ground->m_surfaceNormal.m_quad = _mm_mul_ps(
                                       _mm_andnot_ps(
                                         _mm_cmple_ps(v77, (__m128)0i64),
                                         _mm_mul_ps(_mm_mul_ps(v78, *(__m128 *)_xmm), _mm_sub_ps((__m128)_xmm, v79))),
                                       v75.m_quad);
    v79.m128_f32[0] = 1.0 / (float)v69;
    ground->m_surfaceVelocity.m_quad = _mm_mul_ps(_mm_shuffle_ps(v79, v79, 0), ground->m_surfaceVelocity.m_quad);
  }
  v80 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v81 = v80[1];
  if ( v81 < v80[3] )
  {
    *(_QWORD *)v81 = "Et";
    v82 = __rdtsc();
    *(_DWORD *)(v81 + 8) = v82;
    v80[1] = v81 + 16;
  }
  v83 = (char *)p;
  v84 = input.m_velocity.m_quad.m128_i32[2];
  if ( p == (void *)input.m_velocity.m_quad.m128_u64[0] )
    v84 = 0;
  input.m_velocity.m_quad.m128_i32[2] = v84;
  v85 = v105;
  v86 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v87 = (16 * v85 + 127) & 0xFFFFFF80;
  v88 = (v87 + 15) & 0xFFFFFFF0;
  if ( v87 > v86->m_slabSize || &v83[v88] != v86->m_cur || v86->m_firstNonLifoEnd == v83 )
    hkLifoAllocator::slowBlockFree(v86, v83, v88);
  else
    v86->m_cur = v83;
  input.m_velocity.m_quad.m128_i32[2] = 0;
  if ( input.m_velocity.m_quad.m128_i32[3] >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      (void *)input.m_velocity.m_quad.m128_u64[0],
      16 * input.m_velocity.m_quad.m128_i32[3]);
  input.m_velocity.m_quad.m128_u64[0] = 0i64;
  input.m_velocity.m_quad.m128_i32[3] = 0x80000000;
  v89 = (char *)input.m_position.m_quad.m128_u64[0];
  v90 = v107;
  if ( (hkSurfaceConstraintInteraction *)input.m_position.m_quad.m128_u64[0] == v106 )
    v90 = 0;
  v107 = v90;
  v91 = input.m_position.m_quad.m128_i32[2];
  v92 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v93 = (16 * v91 + 127) & 0xFFFFFF80;
  v94 = (v93 + 15) & 0xFFFFFFF0;
  if ( v93 > v92->m_slabSize || &v89[v94] != v92->m_cur || v92->m_firstNonLifoEnd == v89 )
    hkLifoAllocator::slowBlockFree(v92, v89, v94);
  else
    v92->m_cur = v89;
  v107 = 0;
  if ( v108 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v106, 16 * v108);
  v106 = 0i64;
  v108 = 0x80000000;
  v95 = (char *)p;
  v96 = v102;
  if ( p == array )
    v96 = 0;
  v102 = v96;
  v97 = v105;
  v98 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v99 = ((v97 << 6) + 127) & 0xFFFFFF80;
  v100 = (v99 + 15) & 0xFFFFFFF0;
  if ( v99 > v98->m_slabSize || &v95[v100] != v98->m_cur || v98->m_firstNonLifoEnd == v95 )
    hkLifoAllocator::slowBlockFree(v98, v95, v100);
  else
    v98->m_cur = v95;
  v102 = 0;
  if ( v103 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, v103 << 6);
}

// File Line: 781
// RVA: 0x463C30
bool __fastcall CharacterRigidBody::DoesBoundingBoxProvideSupport(
        CharacterRigidBody *this,
        hkArray<hkpLinkedCollidable::CollisionEntry,hkContainerHeapAllocator> *entries)
{
  hkVector4f v2; // xmm4
  __int64 m_size; // rbx
  hkVector4f v5; // xmm3
  hkpLinkedCollidable::CollisionEntry *m_data; // r11
  hkpContactMgr *m_contactMgr; // r10
  int v8; // r9d
  int v9; // edx
  __int64 i; // rcx
  __m128 v12; // [rsp+20h] [rbp-38h]
  hkVector4f v13; // [rsp+20h] [rbp-38h]
  hkAabb v14; // [rsp+30h] [rbp-28h] BYREF

  v2.m_quad = (__m128)xmmword_141A712A0;
  m_size = entries->m_size;
  v14.m_min = (hkVector4f)xmmword_141A712A0;
  v5.m_quad = _mm_xor_ps(
                (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                (__m128)xmmword_141A712A0);
  v14.m_max = (hkVector4f)v5.m_quad;
  if ( m_size > 0 )
  {
    m_data = entries->m_data;
    do
    {
      m_contactMgr = m_data->m_agentEntry->m_contactMgr;
      if ( m_contactMgr->m_type == TYPE_SIMPLE_CONSTRAINT_CONTACT_MGR )
      {
        v8 = 0;
        if ( *(_WORD *)(*(_QWORD *)&m_contactMgr[4].m_memSizeAndFlags + 4i64) )
        {
          do
          {
            v9 = LODWORD(m_contactMgr[3].vfptr) - 1;
            for ( i = v9; i >= 0; --i )
            {
              if ( *(unsigned __int8 *)(*(_QWORD *)&m_contactMgr[2].m_type + i) == v8 )
                break;
              LOWORD(v9) = v9 - 1;
            }
            ++v8;
            v12 = *(__m128 *)(32i64 * *(unsigned __int8 *)((unsigned __int16)v9 + *(_QWORD *)&m_contactMgr[2].m_type)
                            + *(_QWORD *)&m_contactMgr[4].m_memSizeAndFlags
                            + 48);
            v12.m128_i32[2] = 0;
            v5.m_quad = _mm_max_ps(v5.m_quad, _mm_add_ps((__m128)_xmm, v12));
            v14.m_max = (hkVector4f)v5.m_quad;
            v2.m_quad = _mm_min_ps(v2.m_quad, _mm_sub_ps(v12, (__m128)_xmm));
            v14.m_min = (hkVector4f)v2.m_quad;
          }
          while ( v8 < *(unsigned __int16 *)(*(_QWORD *)&m_contactMgr[4].m_memSizeAndFlags + 4i64) );
        }
      }
      ++m_data;
      --m_size;
    }
    while ( m_size );
  }
  v13.m_quad = (__m128)this->m_character->m_motion.m_motionState.m_transform.m_translation;
  v13.m_quad.m128_i32[2] = 0;
  return hkAabb::isValid(&v14)
      && (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v13.m_quad, v14.m_max.m_quad), _mm_cmple_ps(v14.m_min.m_quad, v13.m_quad))) & 7) == 7;
}

// File Line: 1199
// RVA: 0x4876B0
void __fastcall CharacterRigidBody::entityAddedCallback(CharacterRigidBody *this, hkpEntity *entity)
{
  char *p_m_maxForce; // rbx
  unsigned __int16 *p_m_memSizeAndFlags; // rdx

  p_m_maxForce = (char *)&this[-1].m_maxForce;
  hkReferencedObject::addReference((CharacterRigidBody *)((char *)this - 16));
  if ( p_m_maxForce )
    p_m_memSizeAndFlags = &this->m_memSizeAndFlags;
  else
    p_m_memSizeAndFlags = 0i64;
  hkpWorld::addWorldPostSimulationListener(entity->m_world, (hkpWorldPostSimulationListener *)p_m_memSizeAndFlags);
}

// File Line: 1208
// RVA: 0x487750
void __fastcall CharacterRigidBody::entityRemovedCallback(CharacterRigidBody *this, hkpEntity *entity)
{
  hkReferencedObject *v2; // rbx
  unsigned __int16 *p_m_memSizeAndFlags; // rdx

  v2 = (CharacterRigidBody *)((char *)this - 16);
  if ( this == (CharacterRigidBody *)16 )
    p_m_memSizeAndFlags = 0i64;
  else
    p_m_memSizeAndFlags = &this->m_memSizeAndFlags;
  hkpWorld::removeWorldPostSimulationListener(entity->m_world, (hkpWorldPostSimulationListener *)p_m_memSizeAndFlags);
  hkReferencedObject::removeReference(v2);
}

// File Line: 1215
// RVA: 0x4883B0
void __fastcall CharacterRigidBody::processActualPoints(CharacterRigidBody *this, hkpWorld *world)
{
  hkpRigidBody *m_character; // r15
  __int64 m_size; // rbp
  __int64 v6; // r14
  hkpLinkedCollidable::CollisionEntry *v7; // rsi
  float normalFactor; // xmm6_4
  hkpContactMgr *m_contactMgr; // rbx
  hkArray<unsigned short,hkContainerHeapAllocator> contactPointIds; // [rsp+40h] [rbp-A8h] BYREF
  char v11; // [rsp+50h] [rbp-98h] BYREF

  m_character = this->m_character;
  m_size = m_character->m_collidable.m_collisionEntries.m_size;
  if ( m_size > 0 )
  {
    v6 = 0i64;
    do
    {
      v7 = &m_character->m_collidable.m_collisionEntries.m_data[v6];
      if ( v7->m_agentEntry->m_collidable[0] == &this->m_character->m_collidable )
        normalFactor = *(float *)&FLOAT_1_0;
      else
        normalFactor = FLOAT_N1_0;
      m_contactMgr = v7->m_agentEntry->m_contactMgr;
      if ( m_contactMgr->m_type == TYPE_SIMPLE_CONSTRAINT_CONTACT_MGR )
      {
        contactPointIds.m_data = (unsigned __int16 *)&v11;
        contactPointIds.m_size = 0;
        contactPointIds.m_capacityAndFlags = 0x80000020;
        m_contactMgr->vfptr[6].__vecDelDtor(m_contactMgr, (unsigned int)&contactPointIds);
        if ( this->m_isPlayer )
          CharacterRigidBody::unweldContactPointsForPlayer(
            this,
            v7,
            (hkpSimpleConstraintContactMgr *)m_contactMgr,
            &contactPointIds,
            normalFactor);
        else
          CharacterRigidBody::unweldContactPointsForNonPlayer(
            this,
            v7,
            (hkpSimpleConstraintContactMgr *)m_contactMgr,
            &contactPointIds,
            normalFactor);
        CharacterRigidBody::considerCollisionEntryForSlope(
          this,
          world,
          v7,
          (hkpSimpleConstraintContactMgr *)m_contactMgr,
          &contactPointIds);
        CharacterRigidBody::considerCollisionEntryForMassModification(
          this,
          world,
          v7,
          (hkpSimpleConstraintContactMgr *)m_contactMgr,
          &contactPointIds);
        contactPointIds.m_size = 0;
        if ( contactPointIds.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            contactPointIds.m_data,
            2 * (contactPointIds.m_capacityAndFlags & 0x3FFFFFFF));
        contactPointIds.m_data = 0i64;
        contactPointIds.m_capacityAndFlags = 0x80000000;
      }
      ++v6;
      --m_size;
    }
    while ( m_size );
  }
}

// File Line: 1244
// RVA: 0x488330
void __fastcall CharacterRigidBody::postSimulationCallback(CharacterRigidBody *this, hkpWorld *world)
{
  CharacterRigidBody *v2; // rbx
  bool v4; // zf

  ++world->m_criticalOperationsLockCount;
  v2 = (CharacterRigidBody *)((char *)this - 24);
  CharacterRigidBody::discardVerticalPoints((CharacterRigidBody *)((char *)this - 24));
  CharacterRigidBody::processActualPoints(v2, world);
  v4 = world->m_criticalOperationsLockCount-- == 1;
  if ( v4 && !world->m_blockExecutingPendingOperations.m_bool )
  {
    if ( world->m_pendingOperationsCount )
      hkpWorld::internal_executePendingOperations(world);
    if ( world->m_pendingOperationQueueCount == 1 )
    {
      if ( world->m_pendingBodyOperationsCount )
        hkpWorld::internal_executePendingBodyOperations(world);
    }
  }
}

// File Line: 1268
// RVA: 0x4891B0
void __fastcall CharacterRigidBody::unweldContactPointsForPlayer(
        CharacterRigidBody *this,
        hkpLinkedCollidable::CollisionEntry *entry,
        hkpSimpleConstraintContactMgr *mgr,
        hkArray<unsigned short,hkContainerHeapAllocator> *contactPointIds,
        float normalFactor)
{
  hkVector4f v8; // xmm1
  hkMotionState *p_m_motionState; // rax
  int v10; // ebx
  hkVector4f v11; // xmm5
  __m128 v12; // xmm9
  hkVector4f v13; // xmm1
  __m128 v14; // xmm9
  hkpLinkedCollidable *v15; // r8
  hkpLinkedCollidable *v16; // rdx
  __m128 v17; // xmm11
  char *v18; // rcx
  char *v19; // rax
  char v20; // dl
  bool v21; // bp
  float v22; // xmm12_4
  bool v23; // r12
  __int64 v24; // rdi
  __m128 *v25; // rax
  __m128 v26; // xmm5
  __m128 v27; // xmm4
  __m128 v28; // xmm1
  float v29; // xmm2_4
  float v30; // xmm2_4
  __m128 v31; // xmm1
  float v32; // xmm3_4
  __m128 v33; // xmm5
  __m128 v34; // xmm7
  __m128 v35; // xmm5
  __m128 v36; // xmm1
  __m128 v37; // xmm3
  __m128 v38; // xmm2
  __m128 v39; // xmm4
  __m128 v40; // xmm6
  __m128 v41; // xmm0
  __m128 v42; // xmm5
  __m128 v43; // xmm1
  __m128 v44; // xmm3
  __m128 v45; // xmm2
  __m128 v46; // xmm4

  if ( contactPointIds->m_size > 0 )
  {
    v8.m_quad = (__m128)this->mBottomVertex;
    p_m_motionState = &this->m_character->m_motion.m_motionState;
    v10 = 0;
    v11.m_quad = (__m128)this->m_character->m_motion.m_motionState.m_transform.m_translation;
    v12 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v8.m_quad, v8.m_quad, 0), p_m_motionState->m_transform.m_rotation.m_col0.m_quad),
              _mm_mul_ps(
                _mm_shuffle_ps(v8.m_quad, v8.m_quad, 85),
                this->m_character->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad)),
            _mm_mul_ps(
              _mm_shuffle_ps(v8.m_quad, v8.m_quad, 170),
              this->m_character->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad));
    v13.m_quad = (__m128)this->mTopVertex;
    v14 = _mm_add_ps(v12, v11.m_quad);
    v15 = entry->m_agentEntry->m_collidable[0];
    v16 = entry->m_agentEntry->m_collidable[1];
    v17 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_shuffle_ps(v13.m_quad, v13.m_quad, 0),
                  p_m_motionState->m_transform.m_rotation.m_col0.m_quad),
                _mm_mul_ps(
                  _mm_shuffle_ps(v13.m_quad, v13.m_quad, 85),
                  this->m_character->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad)),
              _mm_mul_ps(
                _mm_shuffle_ps(v13.m_quad, v13.m_quad, 170),
                this->m_character->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad)),
            v11.m_quad);
    if ( v15->m_broadPhaseHandle.m_type == 1 )
      v18 = (char *)v15 + v15->m_ownerOffset;
    else
      v18 = 0i64;
    if ( v16->m_broadPhaseHandle.m_type == 1 )
      v19 = (char *)v16 + v16->m_ownerOffset;
    else
      v19 = 0i64;
    v21 = 0;
    if ( v18 && v19 )
    {
      if ( (v20 = v18[352], v20 == 7) && v19[352] == 5 || v20 == 5 && v19[352] == 7 )
        v21 = 1;
    }
    v22 = _mm_shuffle_ps(v14, v14, 170).m128_f32[0];
    v23 = (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(v22 - _mm_shuffle_ps(v17, v17, 170).m128_f32[0]) & _xmm) * 0.5) > CharacterRigidBody::mMaxCurbHeight;
    v24 = 0i64;
    do
    {
      v25 = (__m128 *)((__int64 (__fastcall *)(hkpSimpleConstraintContactMgr *, _QWORD))mgr->vfptr[5].__first_virtual_table_function__)(
                        mgr,
                        contactPointIds->m_data[v24]);
      if ( v25 )
      {
        v27 = _mm_sub_ps(v17, v14);
        v28 = _mm_mul_ps(_mm_sub_ps(*v25, v14), v27);
        v29 = (float)(_mm_shuffle_ps(v28, v28, 85).m128_f32[0] + _mm_shuffle_ps(v28, v28, 0).m128_f32[0])
            + _mm_shuffle_ps(v28, v28, 170).m128_f32[0];
        if ( v29 > 0.0 )
        {
          v31 = _mm_mul_ps(v27, v27);
          v32 = (float)(_mm_shuffle_ps(v31, v31, 85).m128_f32[0] + _mm_shuffle_ps(v31, v31, 0).m128_f32[0])
              + _mm_shuffle_ps(v31, v31, 170).m128_f32[0];
          if ( v29 <= v32 )
          {
            v30 = v29 / v32;
            if ( v30 < 0.0 || v30 > 1.0 )
              goto LABEL_36;
          }
          else
          {
            v30 = *(float *)&FLOAT_1_0;
          }
        }
        else
        {
          v30 = 0.0;
        }
        v26.m128_f32[0] = v30;
        v33 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v26, v26, 0), v27), v14);
        if ( this->m_fixCurbContacts
          && (float)(_mm_shuffle_ps(v33, v33, 170).m128_f32[0] - v22) <= CharacterRigidBody::mMaxCurbHeight )
        {
          if ( !v23 )
            goto LABEL_36;
          if ( CharacterRigidBody::mMaxCurbHeight <= 0.0 )
            goto LABEL_36;
          v34 = v25[1];
          if ( COERCE_FLOAT(_mm_shuffle_ps(v34, v34, 170).m128_u32[0] & _xmm) >= 0.89999998 )
            goto LABEL_36;
          v35 = _mm_mul_ps(_mm_add_ps(_xmm, v34), (__m128)xmmword_141A711B0);
          v36 = _mm_mul_ps(v35, v35);
          v37 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v36, v36, 85), _mm_shuffle_ps(v36, v36, 0)),
                  _mm_shuffle_ps(v36, v36, 170));
          v38 = _mm_rsqrt_ps(v37);
          v39 = _mm_cmplt_ps(_mm_sub_ps((__m128)0i64, v37), (__m128)0i64);
          v40 = _mm_or_ps(
                  _mm_and_ps(
                    _mm_mul_ps(
                      _mm_andnot_ps(
                        _mm_cmple_ps(v37, (__m128)0i64),
                        _mm_mul_ps(
                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v38, v37), v38)),
                          _mm_mul_ps(*(__m128 *)_xmm, v38))),
                      v35),
                    v39),
                  _mm_andnot_ps(v39, v35));
          if ( !_mm_movemask_ps(v39) )
            goto LABEL_36;
          v41 = _mm_unpackhi_ps(v40, v34);
        }
        else
        {
          if ( !v21 )
            goto LABEL_36;
          v42 = _mm_sub_ps(v33, *v25);
          v43 = _mm_mul_ps(v42, v42);
          v44 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v43, v43, 85), _mm_shuffle_ps(v43, v43, 0)),
                  _mm_shuffle_ps(v43, v43, 170));
          v45 = _mm_rsqrt_ps(v44);
          v46 = _mm_cmplt_ps(_mm_sub_ps((__m128)0i64, v44), (__m128)0i64);
          v40 = _mm_or_ps(
                  _mm_and_ps(
                    _mm_mul_ps(
                      _mm_andnot_ps(
                        _mm_cmple_ps(v44, (__m128)0i64),
                        _mm_mul_ps(
                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v45, v44), v45)),
                          _mm_mul_ps(*(__m128 *)_xmm, v45))),
                      v42),
                    v46),
                  _mm_andnot_ps(v46, v42));
          if ( !_mm_movemask_ps(v46) )
            goto LABEL_36;
          v41 = _mm_unpackhi_ps(v40, v25[1]);
        }
        v25[1] = _mm_shuffle_ps(v40, v41, 196);
      }
LABEL_36:
      ++v10;
      ++v24;
    }
    while ( v10 < contactPointIds->m_size );
  }
}

// File Line: 1364
// RVA: 0x488DA0
void __fastcall CharacterRigidBody::unweldContactPointsForNonPlayer(
        CharacterRigidBody *this,
        hkpLinkedCollidable::CollisionEntry *entry,
        hkpSimpleConstraintContactMgr *mgr,
        hkArray<unsigned short,hkContainerHeapAllocator> *contactPointIds,
        float normalFactor)
{
  hkVector4f v5; // xmm1
  hkMotionState *p_m_motionState; // rax
  int v8; // ebx
  hkVector4f v11; // xmm5
  __m128 v12; // xmm11
  hkVector4f v13; // xmm1
  __m128 v14; // xmm11
  hkpLinkedCollidable *v15; // r8
  hkpLinkedCollidable *v16; // rdx
  __m128 v17; // xmm14
  char *v18; // rcx
  char *v19; // rax
  char v20; // dl
  bool v21; // r15
  __int64 v22; // rdi
  __m128 *v23; // rax
  __m128 v24; // xmm5
  __m128 v25; // xmm4
  __m128 v26; // xmm1
  float v27; // xmm2_4
  float v28; // xmm2_4
  __m128 v29; // xmm1
  float v30; // xmm3_4
  float v31; // xmm6_4
  __m128 v32; // xmm5
  float v33; // xmm8_4
  __m128 v34; // xmm5
  __m128 v35; // xmm1
  __m128 v36; // xmm3
  __m128 v37; // xmm2
  __m128 v38; // xmm4
  __m128 v39; // xmm7
  __m128 v40; // xmm3
  __m128 v41; // xmm2
  __m128 v42; // [rsp+30h] [rbp-C8h]

  v5.m_quad = (__m128)this->mBottomVertex;
  p_m_motionState = &this->m_character->m_motion.m_motionState;
  v8 = 0;
  v11.m_quad = (__m128)this->m_character->m_motion.m_motionState.m_transform.m_translation;
  v12 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v5.m_quad, v5.m_quad, 0), p_m_motionState->m_transform.m_rotation.m_col0.m_quad),
            _mm_mul_ps(
              _mm_shuffle_ps(v5.m_quad, v5.m_quad, 85),
              this->m_character->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad)),
          _mm_mul_ps(
            _mm_shuffle_ps(v5.m_quad, v5.m_quad, 170),
            this->m_character->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad));
  v13.m_quad = (__m128)this->mTopVertex;
  v14 = _mm_add_ps(v12, v11.m_quad);
  v15 = entry->m_agentEntry->m_collidable[0];
  v16 = entry->m_agentEntry->m_collidable[1];
  v17 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_shuffle_ps(v13.m_quad, v13.m_quad, 0),
                p_m_motionState->m_transform.m_rotation.m_col0.m_quad),
              _mm_mul_ps(
                _mm_shuffle_ps(v13.m_quad, v13.m_quad, 85),
                this->m_character->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad)),
            _mm_mul_ps(
              _mm_shuffle_ps(v13.m_quad, v13.m_quad, 170),
              this->m_character->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad)),
          v11.m_quad);
  if ( v15->m_broadPhaseHandle.m_type == 1 )
    v18 = (char *)v15 + v15->m_ownerOffset;
  else
    v18 = 0i64;
  if ( v16->m_broadPhaseHandle.m_type == 1 )
    v19 = (char *)v16 + v16->m_ownerOffset;
  else
    v19 = 0i64;
  v21 = 0;
  if ( v18 && v19 )
  {
    if ( (v20 = v18[352], v20 == 7) && v19[352] == 5 || v20 == 5 && v19[352] == 7 )
      v21 = 1;
  }
  if ( contactPointIds->m_size > 0 )
  {
    v22 = 0i64;
    do
    {
      v23 = (__m128 *)((__int64 (__fastcall *)(hkpSimpleConstraintContactMgr *, _QWORD))mgr->vfptr[5].__first_virtual_table_function__)(
                        mgr,
                        contactPointIds->m_data[v22]);
      if ( v23 )
      {
        v25 = _mm_sub_ps(v17, v14);
        v26 = _mm_mul_ps(_mm_sub_ps(*v23, v14), v25);
        v27 = (float)(_mm_shuffle_ps(v26, v26, 85).m128_f32[0] + _mm_shuffle_ps(v26, v26, 0).m128_f32[0])
            + _mm_shuffle_ps(v26, v26, 170).m128_f32[0];
        if ( v27 <= 0.0 )
        {
          v28 = 0.0;
          goto LABEL_24;
        }
        v29 = _mm_mul_ps(v25, v25);
        v30 = (float)(_mm_shuffle_ps(v29, v29, 85).m128_f32[0] + _mm_shuffle_ps(v29, v29, 0).m128_f32[0])
            + _mm_shuffle_ps(v29, v29, 170).m128_f32[0];
        if ( v27 > v30 )
        {
          v28 = *(float *)&FLOAT_1_0;
LABEL_24:
          v31 = CharacterRigidBody::mMaxCurbHeight;
          v24.m128_f32[0] = v28;
          v32 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v24, v24, 0), v25), v14);
          v33 = v32.m128_f32[2];
          if ( v21 && (float)(v32.m128_f32[2] - v14.m128_f32[2]) > CharacterRigidBody::mMaxCurbHeight && v28 < 1.0 )
          {
            v34 = _mm_sub_ps(v32, *v23);
            v35 = _mm_mul_ps(v34, v34);
            v36 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v35, v35, 85), _mm_shuffle_ps(v35, v35, 0)),
                    _mm_shuffle_ps(v35, v35, 170));
            v37 = _mm_rsqrt_ps(v36);
            v38 = _mm_cmplt_ps(_mm_sub_ps((__m128)0i64, v36), (__m128)0i64);
            v39 = _mm_or_ps(
                    _mm_and_ps(
                      _mm_mul_ps(
                        _mm_andnot_ps(
                          _mm_cmple_ps(v36, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v37, v36), v37)),
                            _mm_mul_ps(*(__m128 *)_xmm, v37))),
                        v34),
                      v38),
                    _mm_andnot_ps(v38, v34));
            if ( _mm_movemask_ps(v38) )
            {
              v40 = v23[1];
              v41 = _mm_mul_ps(
                      _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(normalFactor), (__m128)LODWORD(normalFactor), 0), v40),
                      v39);
              if ( (float)((float)(_mm_shuffle_ps(v41, v41, 85).m128_f32[0] + _mm_shuffle_ps(v41, v41, 0).m128_f32[0])
                         + _mm_shuffle_ps(v41, v41, 170).m128_f32[0]) < 0.98000002 )
              {
                v23[1] = _mm_shuffle_ps(v39, _mm_unpackhi_ps(v39, v40), 196);
                v31 = CharacterRigidBody::mMaxCurbHeight;
              }
            }
          }
          if ( (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(this->mBottomVertex.m_quad.m128_f32[2] - this->mTopVertex.m_quad.m128_f32[2]) & _xmm)
                     * 0.5) > v31
            && v31 > 0.0
            && (float)(v33 - v14.m128_f32[2]) <= v31 )
          {
            v42 = v23[1];
            if ( COERCE_FLOAT(v42.m128_i32[2] & _xmm) < 0.89999998 )
              v23[1] = _mm_shuffle_ps(_xmm, _mm_unpackhi_ps(_xmm, v23[1]), 196);
          }
          goto LABEL_35;
        }
        v28 = v27 / v30;
        if ( v28 >= 0.0 && v28 <= 1.0 )
          goto LABEL_24;
      }
LABEL_35:
      ++v8;
      ++v22;
    }
    while ( v8 < contactPointIds->m_size );
  }
}

// File Line: 1468
// RVA: 0x4865E0
void __fastcall CharacterRigidBody::considerCollisionEntryForSlope(
        CharacterRigidBody *this,
        hkpWorld *world,
        hkpLinkedCollidable::CollisionEntry *entry,
        hkpSimpleConstraintContactMgr *mgr,
        hkArray<unsigned short,hkContainerHeapAllocator> *contactPointIds)
{
  hkpLinkedCollidable *v7; // r14
  hkpLinkedCollidable *v8; // r12
  hkpRigidBody *v9; // rax
  float v10; // xmm10_4
  __int64 v11; // rbp
  __int64 m_size; // r13
  __m128 *v13; // rbx
  __m128 v14; // xmm8
  hkVector4f v15; // xmm9
  __m128 v16; // xmm6
  float v17; // xmm6_4
  float v18; // xmm7_4
  hkpRigidBody *RigidBody; // rax
  hkpCollidable *v20; // rcx
  hkpRigidBody *v21; // rax
  _BYTE *m_userData; // rcx
  __m128 v23; // xmm0
  __m128 v24; // xmm8
  __m128 v25; // xmm4
  __m128 v26; // xmm4
  __m128 v27; // xmm1
  hkpSimulationIsland *m_simulationIsland; // rcx
  unsigned __int16 v29; // r12
  CharacterRigidBody::VertPointInfo *v30; // rcx
  __int128 v31; // [rsp+40h] [rbp-3198h]
  __int128 v32; // [rsp+50h] [rbp-3188h] BYREF
  __m128 v33; // [rsp+60h] [rbp-3178h]
  hkpSimpleConstraintContactMgr *v34; // [rsp+70h] [rbp-3168h]
  __int64 v35; // [rsp+80h] [rbp-3158h]
  char v36[8]; // [rsp+90h] [rbp-3148h] BYREF
  hkpSimulationIsland *v37; // [rsp+98h] [rbp-3140h]
  int v38; // [rsp+30C0h] [rbp-118h]
  __int64 v39; // [rsp+30E0h] [rbp-F8h]
  hkpLinkedCollidable *v40; // [rsp+31E0h] [rbp+8h]

  v35 = -2i64;
  v7 = entry->m_agentEntry->m_collidable[0];
  v8 = entry->m_agentEntry->m_collidable[1];
  v40 = v8;
  if ( v7->m_broadPhaseHandle.m_type == 1 )
    v9 = (hkpRigidBody *)((char *)v7 + v7->m_ownerOffset);
  else
    v9 = 0i64;
  if ( v9 == this->m_character )
    v10 = *(float *)&FLOAT_1_0;
  else
    v10 = FLOAT_N1_0;
  v11 = 0i64;
  m_size = contactPointIds->m_size;
  if ( m_size > 0 )
  {
    do
    {
      v13 = (__m128 *)((__int64 (__fastcall *)(hkpSimpleConstraintContactMgr *, _QWORD))mgr->vfptr[5].__first_virtual_table_function__)(
                        mgr,
                        contactPointIds->m_data[v11]);
      v14 = v13[1];
      v15.m_quad = (__m128)this->m_up;
      v16 = _mm_mul_ps(v15.m_quad, v14);
      v17 = _mm_shuffle_ps(v16, v16, 170).m128_f32[0]
          + (float)(_mm_shuffle_ps(v16, v16, 85).m128_f32[0] + _mm_shuffle_ps(v16, v16, 0).m128_f32[0]);
      v18 = v17 * v10;
      if ( this->m_isInWater )
      {
        RigidBody = hkpGetRigidBody(v7);
        v20 = v8;
        if ( RigidBody != this->m_character )
          v20 = v7;
        v21 = hkpGetRigidBody(v20);
        if ( v21 )
        {
          m_userData = (_BYTE *)v21->m_userData;
          if ( m_userData )
          {
            if ( *m_userData )
              goto LABEL_16;
          }
        }
      }
      if ( v18 > 0.0099999998 && v18 < this->m_maxSlopeCosine )
      {
LABEL_16:
        v34 = mgr;
        v31 = (__int128)*v13;
        v23 = *v13;
        HIDWORD(v31) = 1066267815;
        v32 = v31;
        v23.m128_i32[0] = LODWORD(v17) ^ _xmm[0];
        v24 = _mm_add_ps(v14, _mm_mul_ps(_mm_shuffle_ps(v23, v23, 0), v15.m_quad));
        v25 = _mm_mul_ps(v24, v24);
        v26 = _mm_add_ps(
                _mm_shuffle_ps(v25, v25, 170),
                _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)));
        v27 = _mm_rsqrt_ps(v26);
        v33 = _mm_mul_ps(
                _mm_andnot_ps(
                  _mm_cmple_ps(v26, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v27, v26), v27)),
                    _mm_mul_ps(*(__m128 *)_xmm, v27))),
                v24);
        v33.m128_i32[3] = 0;
        m_simulationIsland = this->m_character->m_simulationIsland;
        v38 = 2139095022;
        v39 = 0i64;
        v37 = m_simulationIsland;
        v29 = ((__int64 (__fastcall *)(hkpSimpleConstraintContactMgr *, hkpLinkedCollidable *, hkpLinkedCollidable *, hkpProcessCollisionInput *, char *, _QWORD, __int128 *))mgr->vfptr[1].__first_virtual_table_function__)(
                mgr,
                v7,
                v8,
                world->m_collisionInput,
                v36,
                0i64,
                &v32);
        if ( v29 != 0xFFFF )
        {
          if ( this->m_verticalContactPoints.m_size == (this->m_verticalContactPoints.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &this->m_verticalContactPoints, 48);
          v30 = &this->m_verticalContactPoints.m_data[this->m_verticalContactPoints.m_size];
          if ( v30 )
          {
            v30->m_vertPoint.m_position = (hkVector4f)v32;
            v30->m_vertPoint.m_separatingNormal.m_quad = v33;
            v30->m_mgr = v34;
          }
          ++this->m_verticalContactPoints.m_size;
          if ( contactPointIds->m_size == (contactPointIds->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, contactPointIds, 2);
          contactPointIds->m_data[contactPointIds->m_size++] = v29;
        }
        v8 = v40;
      }
      ++v11;
    }
    while ( v11 < m_size );
  }
}

// File Line: 1549
// RVA: 0x486320
void __fastcall CharacterRigidBody::considerCollisionEntryForMassModification(
        CharacterRigidBody *this,
        hkpWorld *world,
        hkpLinkedCollidable::CollisionEntry *entry,
        hkpSimpleConstraintContactMgr *mgr,
        hkArray<unsigned short,hkContainerHeapAllocator> *contactPointIds)
{
  __int64 v6; // rbx
  hkpLinkedCollidable *v7; // rcx
  hkpLinkedCollidable *v8; // r8
  char m_type; // dl
  hkpRigidBody *v11; // rax
  hkpRigidBody *m_character; // r10
  __m128 v13; // xmm7
  hkpRigidBody *v14; // rdx
  char m_storage; // cl
  int v16; // eax
  char v17; // r12
  char v18; // r15
  __m128 v19; // xmm6
  __int64 m_size; // rbp
  __m128 *v21; // rax
  __m128 v22; // xmm6
  __m128 v23; // xmm2
  float Mass; // xmm5_4
  float v25; // xmm3_4
  __m128 v26; // xmm6
  float v27; // xmm5_4
  __m128 v28; // xmm1
  __m128 v29; // xmm4
  __m128 v30; // xmm1
  float m_maxForce; // xmm0_4
  hkVector4f *v32; // r9
  hkpConstraintOwner *m_simulationIsland; // r8
  __int128 v34; // [rsp+20h] [rbp-68h] BYREF

  v6 = 0i64;
  v7 = entry->m_agentEntry->m_collidable[0];
  v8 = entry->m_agentEntry->m_collidable[1];
  m_type = v7->m_broadPhaseHandle.m_type;
  if ( m_type == 1 )
    v11 = (hkpRigidBody *)((char *)v7 + v7->m_ownerOffset);
  else
    v11 = 0i64;
  m_character = this->m_character;
  if ( v11 == m_character )
  {
    v13 = *(__m128 *)_xmm_bf800000bf800000bf800000bf800000;
    if ( v8->m_broadPhaseHandle.m_type == 1 )
      v14 = (hkpRigidBody *)((char *)v8 + v8->m_ownerOffset);
    else
      v14 = 0i64;
  }
  else
  {
    if ( m_type == 1 )
      v14 = (hkpRigidBody *)((char *)v7 + v7->m_ownerOffset);
    else
      v14 = 0i64;
    v13 = *(__m128 *)_xmm;
  }
  m_storage = v14->m_motion.m_type.m_storage;
  if ( ((m_storage - 4) & 0xFC) != 0 || m_storage == 6 )
  {
    if ( this->m_maxForce <= 0.0 )
    {
      m_simulationIsland = m_character->m_simulationIsland;
      v32 = &aabbOut;
    }
    else
    {
      v16 = v14->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo & 0x1F;
      v17 = 0;
      v18 = 0;
      if ( v16 == 26 || v16 == 19 )
      {
        v17 = 1;
      }
      else if ( v16 == 22 )
      {
        v18 = 1;
      }
      v19 = 0i64;
      m_size = contactPointIds->m_size;
      if ( m_size > 0 )
      {
        do
        {
          v21 = (__m128 *)((__int64 (__fastcall *)(hkpSimpleConstraintContactMgr *, _QWORD))mgr->vfptr[5].__first_virtual_table_function__)(
                            mgr,
                            contactPointIds->m_data[v6++]);
          v19 = _mm_add_ps(v19, v21[1]);
        }
        while ( v6 < m_size );
      }
      v22 = _mm_mul_ps(v19, v13);
      v23 = _mm_mul_ps(v22, v22);
      Mass = hkpMotion::getMass(&this->m_character->m_motion);
      v25 = (float)(_mm_shuffle_ps(v23, v23, 85).m128_f32[0] + _mm_shuffle_ps(v23, v23, 0).m128_f32[0])
          + _mm_shuffle_ps(v23, v23, 170).m128_f32[0];
      if ( v25 <= 0.0 )
      {
        v28 = _mm_mul_ps(this->m_acceleration.m_quad, this->m_acceleration.m_quad);
        v29 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(v28, v28, 0)),
                _mm_shuffle_ps(v28, v28, 170));
        v30 = _mm_rsqrt_ps(v29);
        v27 = Mass
            * _mm_andnot_ps(
                _mm_cmple_ps(v29, (__m128)0i64),
                _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v30, v29), v30)),
                    _mm_mul_ps(*(__m128 *)_xmm, v30)),
                  v29)).m128_f32[0];
      }
      else
      {
        v26 = _mm_mul_ps(v22, this->m_acceleration.m_quad);
        v27 = (float)((float)((float)(_mm_shuffle_ps(v26, v26, 85).m128_f32[0] + _mm_shuffle_ps(v26, v26, 0).m128_f32[0])
                            + _mm_shuffle_ps(v26, v26, 170).m128_f32[0])
                    * Mass)
            / v25;
      }
      v34 = *(_OWORD *)_xmm;
      if ( v17 )
      {
        *((float *)&v34 + 3) = FLOAT_0_1;
      }
      else if ( v18 )
      {
        *((float *)&v34 + 3) = FLOAT_30_0;
      }
      else
      {
        m_maxForce = this->m_maxForce;
        if ( v27 > m_maxForce )
          *((float *)&v34 + 3) = v27 / m_maxForce;
      }
      if ( this->m_superMassive )
        *((float *)&v34 + 3) = FLOAT_0_0099999998;
      v14 = this->m_character;
      v32 = (hkVector4f *)&v34;
      m_simulationIsland = v14->m_simulationIsland;
    }
    hkpResponseModifier::setInvMassScalingForContact(mgr, v14, m_simulationIsland, v32);
  }
}

// File Line: 1674
// RVA: 0x487420
void __fastcall CharacterRigidBody::discardVerticalPoints(CharacterRigidBody *this)
{
  hkArray<hkpLinkedCollidable::CollisionEntry,hkContainerHeapAllocator> *p_m_collisionEntries; // rax
  __int64 m_size; // rdi
  __int64 v4; // rbx
  hkpSimpleConstraintContactMgr *m_contactMgr; // r14
  int v6; // eax
  __int64 v7; // r12
  int v8; // ecx
  CharacterRigidBody::VertPointInfo *m_data; // rbp
  int v10; // edi
  __int64 v11; // rbx
  __int64 v12; // rsi
  unsigned __int16 v13; // r15
  __m128 *v14; // rax
  __int64 v15; // rax
  CharacterRigidBody::VertPointInfo *v16; // rcx
  CharacterRigidBody::VertPointInfo *v17; // rdx
  __m128 *p_m_quad; // rax
  signed __int64 v19; // rdx
  __int64 v20; // r8
  hkArray<hkpLinkedCollidable::CollisionEntry,hkContainerHeapAllocator> *v21; // [rsp+20h] [rbp-78h]
  _WORD *v22; // [rsp+30h] [rbp-68h] BYREF
  int v23; // [rsp+38h] [rbp-60h]
  int v24; // [rsp+3Ch] [rbp-5Ch]
  __m128 v25; // [rsp+40h] [rbp-58h]
  int v26; // [rsp+A0h] [rbp+8h]
  __int64 v27; // [rsp+A8h] [rbp+10h]
  __int64 v28; // [rsp+B0h] [rbp+18h]
  __int64 v29; // [rsp+B8h] [rbp+20h]

  if ( this->m_verticalContactPoints.m_size )
  {
    p_m_collisionEntries = &this->m_character->m_collidable.m_collisionEntries;
    v21 = p_m_collisionEntries;
    m_size = this->m_character->m_collidable.m_collisionEntries.m_size;
    v29 = m_size;
    if ( m_size > 0 )
    {
      v4 = 0i64;
      v28 = 0i64;
      do
      {
        m_contactMgr = (hkpSimpleConstraintContactMgr *)(*(hkpAgentNnEntry **)((char *)&p_m_collisionEntries->m_data->m_agentEntry
                                                                             + v4))->m_contactMgr;
        if ( m_contactMgr->m_type == TYPE_SIMPLE_CONSTRAINT_CONTACT_MGR )
        {
          v22 = 0i64;
          v23 = 0;
          v24 = 0x80000000;
          m_contactMgr->vfptr[6].__vecDelDtor(m_contactMgr, (unsigned int)&v22);
          v6 = this->m_verticalContactPoints.m_size - 1;
          v26 = v6;
          v27 = v6;
          if ( v6 >= 0 )
          {
            v7 = v6;
            v8 = v23;
            do
            {
              m_data = this->m_verticalContactPoints.m_data;
              if ( m_data[v7].m_mgr == m_contactMgr )
              {
                v10 = 0;
                v11 = 0i64;
                v12 = v8;
                if ( v8 > 0 )
                {
                  while ( 1 )
                  {
                    v13 = v22[v11];
                    v14 = (__m128 *)((__int64 (__fastcall *)(hkpSimpleConstraintContactMgr *, _QWORD))m_contactMgr->vfptr[5].__first_virtual_table_function__)(
                                      m_contactMgr,
                                      v13);
                    if ( _mm_movemask_ps(
                           _mm_and_ps(
                             _mm_cmpeq_ps(*v14, m_data[v7].m_vertPoint.m_position.m_quad),
                             _mm_cmpeq_ps(v14[1], m_data[v7].m_vertPoint.m_separatingNormal.m_quad))) == 15 )
                      break;
                    ++v10;
                    if ( ++v11 >= v12 )
                      goto LABEL_17;
                  }
                  v25 = *v14;
                  v25.m128_i32[3] = 1073359795;
                  *v14 = v25;
                  ((void (__fastcall *)(hkpSimpleConstraintContactMgr *, _QWORD, hkpSimulationIsland *))m_contactMgr->vfptr[2].__first_virtual_table_function__)(
                    m_contactMgr,
                    v13,
                    this->m_character->m_simulationIsland);
                  v15 = --this->m_verticalContactPoints.m_size;
                  if ( (_DWORD)v15 != v26 )
                  {
                    v16 = this->m_verticalContactPoints.m_data;
                    v17 = &v16[v15];
                    p_m_quad = &v16[v7].m_vertPoint.m_position.m_quad;
                    v19 = (char *)v17 - (char *)&v16[v7];
                    v20 = 6i64;
                    do
                    {
                      p_m_quad->m128_u64[0] = *(unsigned __int64 *)((char *)p_m_quad->m128_u64 + v19);
                      p_m_quad = (__m128 *)((char *)p_m_quad + 8);
                      --v20;
                    }
                    while ( v20 );
                  }
                  v8 = v23 - 1;
                  v23 = v8;
                  if ( v8 != v10 )
                  {
                    v22[v11] = v22[v8];
LABEL_17:
                    v8 = v23;
                  }
                }
              }
              --v26;
              --v27;
              --v7;
            }
            while ( v27 >= 0 );
            v4 = v28;
            m_size = v29;
          }
          v23 = 0;
          if ( v24 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              v22,
              2 * (v24 & 0x3FFFFFFF));
          v22 = 0i64;
          v24 = 0x80000000;
        }
        v4 += 16i64;
        v28 = v4;
        v29 = --m_size;
        p_m_collisionEntries = v21;
      }
      while ( m_size );
    }
    this->m_verticalContactPoints.m_size = 0;
  }
}

