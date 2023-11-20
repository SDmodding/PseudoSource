// File Line: 106
// RVA: 0x4492E0
void __fastcall CharacterRigidBody::CharacterRigidBody(CharacterRigidBody *this, hkpCharacterRigidBodyCinfo *info)
{
  hkpCharacterRigidBodyCinfo *v2; // rsi
  CharacterRigidBody *v3; // rbx
  signed __int64 v4; // rdi
  char v5; // dl
  __int64 v6; // rax
  char v7; // cl
  _QWORD **v8; // rax
  hkpRigidBody *v9; // rax
  hkpRigidBody *v10; // rax
  char v11; // al
  __m128 v12; // xmm8
  __m128 v13; // xmm6
  __m128i v14; // xmm7
  __m128i v15; // xmm3
  __m128i v16; // xmm7
  __m128 v17; // xmm5
  unsigned int v18; // xmm1_4
  __m128 v19; // xmm7
  __m128 v20; // xmm2
  __m128 v21; // xmm3
  hkMatrix3f inertiaInv; // [rsp+30h] [rbp-168h]
  hkpRigidBodyCinfo infoa; // [rsp+60h] [rbp-138h]

  v2 = info;
  v3 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
  this->vfptr = (hkBaseObjectVtbl *)&hkReferencedObject::`vftable;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkpEntityListenerVtbl *)&hkpEntityListener::`vftable;
  this->vfptr = (hkpWorldPostSimulationListenerVtbl *)&hkpWorldPostSimulationListener::`vftable;
  this->vfptr = (hkBaseObjectVtbl *)&CharacterRigidBody::`vftable{for `hkReferencedObject};
  this->vfptr = (hkpEntityListenerVtbl *)&CharacterRigidBody::`vftable{for `hkpEntityListener};
  this->vfptr = (hkpWorldPostSimulationListenerVtbl *)&CharacterRigidBody::`vftable{for `hkpWorldPostSimulationListener};
  *(_DWORD *)&this->m_isPlayer = 256;
  this->m_superMassive = 0;
  this->m_verticalContactPoints.m_data = 0i64;
  this->m_verticalContactPoints.m_size = 0;
  this->m_verticalContactPoints.m_capacityAndFlags = 2147483648;
  hkpRigidBodyCinfo::hkpRigidBodyCinfo(&infoa);
  infoa.m_shape = v2->m_shape;
  infoa.m_mass = v2->m_mass;
  infoa.m_friction = v2->m_friction;
  infoa.m_position = v2->m_position;
  infoa.m_rotation = v2->m_rotation;
  infoa.m_collisionFilterInfo = v2->m_collisionFilterInfo;
  infoa.m_restitution = 0.0;
  infoa.m_maxLinearVelocity = v2->m_maxLinearVelocity;
  infoa.m_motionType.m_storage = 7;
  infoa.m_qualityType.m_storage = 8;
  v4 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v5 = ++*(_BYTE *)(v4 + 80);
  v6 = v5;
  *(_DWORD *)(v4 + 4 * v6) = 0;
  *(_QWORD *)(v4 + 8 * v6 + 16) = "hkpRigidBody";
  *(_QWORD *)(v4 + 8 * v6 + 48) = 0i64;
  v7 = *(_BYTE *)(v4 + 81);
  if ( v5 > v7 )
    v7 = v5;
  *(_BYTE *)(v4 + 81) = v7;
  v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkpRigidBody *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(v8[11], 720i64);
  if ( v9 )
    hkpRigidBody::hkpRigidBody(v9, &infoa);
  else
    v10 = 0i64;
  v3->m_character = v10;
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
  inertiaInv.m_col0 = 0i64;
  inertiaInv.m_col1 = 0i64;
  inertiaInv.m_col2 = 0i64;
  hkpRigidBody::setInertiaInvLocal(v3->m_character, &inertiaInv);
  hkpWorldObject::addProperty((hkpWorldObject *)&v3->m_character->vfptr, 0x1130u, (hkSimplePropertyValue)v2->m_vdbColor);
  v3->m_up = v2->m_up;
  v12 = _mm_add_ps((__m128)LODWORD(v2->m_maxSlope), *(__m128 *)_xmm);
  v13 = _mm_andnot_ps(*(__m128 *)_xmm, v12);
  v14 = _mm_load_si128((const __m128i *)_xmm);
  v15 = _mm_add_epi32(v14, v14);
  v16 = _mm_andnot_si128(v14, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v13, *(__m128 *)_xmm)), v14));
  v17 = _mm_cvtepi32_ps(v16);
  v18 = (unsigned int)*(_OWORD *)&_mm_and_si128(v16, _mm_add_epi32(v15, v15)) << 29;
  v19 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v16, v15), (__m128i)0i64);
  v20 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v17, *(__m128 *)DP1_0), v13), _mm_mul_ps(v17, *(__m128 *)DP2)),
          _mm_mul_ps(v17, *(__m128 *)DP3));
  v21 = _mm_mul_ps(v20, v20);
  *(_QWORD *)&v3->m_maxSlopeCosine = ((unsigned int)*(_OWORD *)&_mm_andnot_ps(
                                                                  v19,
                                                                  _mm_add_ps(
                                                                    _mm_sub_ps(
                                                                      _mm_mul_ps(
                                                                        _mm_mul_ps(
                                                                          _mm_add_ps(
                                                                            _mm_mul_ps(
                                                                              _mm_add_ps(
                                                                                _mm_mul_ps(v21, *(__m128 *)cosCoeff0_0),
                                                                                *(__m128 *)cosCoeff1),
                                                                              v21),
                                                                            *(__m128 *)cosCoeff2_0),
                                                                          v21),
                                                                        v21),
                                                                      _mm_mul_ps(*(__m128 *)_xmm, v21)),
                                                                    *(__m128 *)_xmm)) | COERCE_UNSIGNED_INT(
                                                                                          (float)((float)((float)((float)((float)((float)(-0.00019515296 * v21.m128_f32[0]) + 0.0083321612) * v21.m128_f32[0]) + -0.16666655) * v21.m128_f32[0])
                                                                                                * v20.m128_f32[0])
                                                                                        + v20.m128_f32[0]) & v19.m128_i32[0]) ^ v12.m128_i32[0] & _xmm[0] ^ v18;
  v3->m_penetrationRecoverySpeed = 0.1;
  v3->m_supportDistance = v2->m_supportDistance;
  v3->m_maxSpeedForSimplexSolver = v2->m_maxSpeedForSimplexSolver;
  v3->m_acceleration = 0i64;
  v3->m_maxForce = v2->m_maxForce;
  hkpEntity::addEntityListener((hkpEntity *)&v3->m_character->vfptr, (hkpEntityListener *)&v3->vfptr);
  v3->m_heightAboveGround = 0.0;
}

// File Line: 203
// RVA: 0x44FBC0
void __fastcall CharacterRigidBody::~CharacterRigidBody(CharacterRigidBody *this)
{
  CharacterRigidBody *v1; // rbx
  int v2; // eax
  hkSimplePropertyValue result; // [rsp+48h] [rbp+10h]

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&CharacterRigidBody::`vftable{for `hkReferencedObject};
  this->vfptr = (hkpEntityListenerVtbl *)&CharacterRigidBody::`vftable{for `hkpEntityListener};
  this->vfptr = (hkpWorldPostSimulationListenerVtbl *)&CharacterRigidBody::`vftable{for `hkpWorldPostSimulationListener};
  hkpEntity::removeEntityListener((hkpEntity *)&this->m_character->vfptr, (hkpEntityListener *)&this->vfptr);
  hkpWorldObject::removeProperty((hkpWorldObject *)&v1->m_character->vfptr, &result, 0x1130u);
  hkReferencedObject::removeReference((hkReferencedObject *)&v1->m_character->vfptr);
  v1->m_verticalContactPoints.m_size = 0;
  v2 = v1->m_verticalContactPoints.m_capacityAndFlags;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_verticalContactPoints.m_data,
      48 * (v2 & 0x3FFFFFFF));
  v1->m_verticalContactPoints.m_data = 0i64;
  v1->m_verticalContactPoints.m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkpWorldPostSimulationListenerVtbl *)&hkpWorldPostSimulationListener::`vftable;
  v1->vfptr = (hkpEntityListenerVtbl *)&hkpEntityListener::`vftable;
  v1->vfptr = (hkBaseObjectVtbl *)&hkReferencedObject::`vftable;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 222
// RVA: 0x485600
int CharacterRigidBody::checkSupportForPlayer(...)
{
  __m128 *v4; // rdi
  hkStepInfo *v5; // rsi
  CharacterRigidBody *v6; // r15
  _QWORD *v7; // r9
  unsigned __int64 v8; // rcx
  unsigned __int64 v9; // rax
  hkVector4f v10; // xmm12
  hkLifoAllocator *v11; // rax
  hkSurfaceConstraintInfo *v12; // rcx
  unsigned __int64 v13; // rdx
  hkArray<hkpLinkedCollidable::CollisionEntry,hkContainerHeapAllocator> *v14; // r12
  char v15; // r14
  float v16; // xmm6_4
  int v17; // edx
  __int64 v18; // r13
  hkpContactMgr *v19; // r14
  signed int v20; // ebx
  int v21; // edx
  __int64 i; // rcx
  signed __int64 v23; // rdi
  __int64 v24; // rsi
  __m128 v25; // xmm0
  float v26; // xmm0_4
  int v27; // ecx
  __int64 v28; // rdx
  signed int v29; // ecx
  __int64 v30; // rdx
  float v31; // xmm0_4
  hkpLinkedCollidable *v32; // r8
  __m128 *v33; // rcx
  char v34; // r8
  __m128 v35; // xmm1
  __m128 v36; // xmm2
  __m128 v37; // xmm2
  signed int v38; // eax
  __m128 v39; // xmm0
  __m128 v40; // xmm0
  int v41; // ecx
  int v42; // er8
  int v43; // edx
  int v44; // er9
  int v45; // ebx
  bool v46; // zf
  int v47; // ebx
  LPVOID v48; // rax
  hkLifoAllocator *v49; // r8
  int v50; // edx
  hkSurfaceConstraintInteraction *v51; // rax
  char *v52; // rcx
  int v53; // ebx
  hkLifoAllocator *v54; // rax
  int v55; // edx
  char *v56; // rcx
  char *v57; // r8
  int v58; // er8
  int v59; // edx
  int v60; // ebx
  int v61; // ebx
  int v62; // ebx
  hkResultEnum v63; // ecx
  int v64; // er9
  __int64 v65; // rdx
  __int64 v66; // r8
  __m128 v67; // xmm4
  __m128 v68; // xmm4
  __m128 v69; // xmm0
  __m128 v70; // xmm2
  signed int v71; // edx
  __int64 v72; // r8
  __m128 *v73; // rax
  __m128 *v74; // rcx
  unsigned __int64 v75; // r9
  __m128 v76; // xmm2
  __m128 v77; // xmm5
  __m128 v78; // xmm3
  __m128 v79; // xmm3
  __m128 v80; // xmm0
  __m128 v81; // xmm1
  _QWORD *v82; // r8
  unsigned __int64 v83; // rcx
  unsigned __int64 v84; // rax
  char *v85; // rdi
  int v86; // ecx
  int v87; // ebx
  hkLifoAllocator *v88; // rcx
  signed int v89; // ebx
  int v90; // er8
  char *v91; // rdi
  int v92; // ecx
  float v93; // ebx
  hkLifoAllocator *v94; // rcx
  signed int v95; // ebx
  int v96; // er8
  char *v97; // rdi
  int v98; // ecx
  int v99; // ebx
  hkLifoAllocator *v100; // rcx
  signed int v101; // ebx
  int v102; // er8
  hkSurfaceConstraintInfo *array; // [rsp+30h] [rbp-90h]
  int v104; // [rsp+38h] [rbp-88h]
  int v105; // [rsp+3Ch] [rbp-84h]
  void *p; // [rsp+40h] [rbp-80h]
  int v107; // [rsp+48h] [rbp-78h]
  hkSurfaceConstraintInteraction *v108; // [rsp+50h] [rbp-70h]
  int v109; // [rsp+58h] [rbp-68h]
  int v110; // [rsp+5Ch] [rbp-64h]
  hkSimplexSolverInput input; // [rsp+60h] [rbp-60h]
  __int64 v112; // [rsp+C0h] [rbp+0h]
  hkSurfaceConstraintInfo *v113; // [rsp+C8h] [rbp+8h]
  __int64 v114; // [rsp+D0h] [rbp+10h]
  hkSimplexSolverOutput output; // [rsp+E0h] [rbp+20h]
  hkSurfaceConstraintInfo *v116; // [rsp+1D0h] [rbp+110h]
  hkStepInfo *v117; // [rsp+1D8h] [rbp+118h]
  hkResult result[2]; // [rsp+1E0h] [rbp+120h]
  int v119; // [rsp+1E8h] [rbp+128h]

  v114 = -2i64;
  v4 = (__m128 *)ground;
  v5 = stepInfo;
  v6 = this;
  sPlayer = this;
  v7 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v8 = v7[1];
  if ( v8 < v7[3] )
  {
    *(_QWORD *)v8 = "TtcheckSupport";
    v9 = __rdtsc();
    *(_DWORD *)(v8 + 8) = v9;
    v7[1] = v8 + 16;
  }
  v10.m_quad = _mm_xor_ps(v6->m_up.m_quad, (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
  array = 0i64;
  v104 = 0;
  v105 = 2147483648;
  v107 = 20;
  v11 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v12 = (hkSurfaceConstraintInfo *)v11->m_cur;
  v13 = (unsigned __int64)&v12[20];
  if ( v11->m_slabSize < 1280 || (void *)v13 > v11->m_end )
    v12 = (hkSurfaceConstraintInfo *)hkLifoAllocator::allocateFromNewSlab(v11, 1280);
  else
    v11->m_cur = (void *)v13;
  array = v12;
  v105 = -2147483628;
  p = v12;
  v14 = &v6->m_character->m_collidable.m_collisionEntries;
  v15 = CharacterRigidBody::DoesBoundingBoxProvideSupport(v6, v14);
  LOBYTE(v116) = v15;
  v16 = FLOAT_3_4028235e38;
  v17 = 0;
  v119 = 0;
  if ( v14->m_size > 0 )
  {
    v18 = 0i64;
    do
    {
      v19 = v14->m_data[v18].m_agentEntry->m_contactMgr;
      if ( v19->m_type == TYPE_SIMPLE_CONSTRAINT_CONTACT_MGR )
      {
        v20 = 0;
        if ( *(_WORD *)(*(_QWORD *)&v19[4].m_memSizeAndFlags + 4i64) > 0u )
        {
          do
          {
            v21 = LODWORD(v19[3].vfptr) - 1;
            for ( i = v21; i >= 0; --i )
            {
              if ( *(unsigned __int8 *)(i + *(_QWORD *)&v19[2].m_type) == v20 )
                break;
              LOWORD(v21) = v21 - 1;
            }
            v23 = 32i64 * *(unsigned __int8 *)((unsigned __int16)v21 + *(_QWORD *)&v19[2].m_type);
            v24 = *(_QWORD *)&v19[4].m_memSizeAndFlags;
            v25 = _mm_sub_ps(
                    *(__m128 *)(v23 + v24 + 48),
                    v6->m_character->m_motion.m_motionState.m_transform.m_translation.m_quad);
            LODWORD(v26) = (unsigned __int128)_mm_shuffle_ps(v25, v25, 170);
            if ( v16 > v26 )
              v16 = v26;
            v27 = v104;
            if ( v104 == (v105 & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 64);
              v27 = v104;
            }
            v28 = (__int64)&array[(signed __int64)v27];
            v113 = &array[(signed __int64)v27];
            v29 = 0;
            LODWORD(v108) = 0;
            do
            {
              v112 = v28 + ((signed __int64)v29++ << 6);
              LODWORD(v108) = v29;
            }
            while ( v29 < 1 );
            v30 = (__int64)&array[(signed __int64)v104++];
            if ( v14->m_data[v18].m_agentEntry->m_collidable[0] == &v6->m_character->m_collidable )
              v31 = *(float *)&FLOAT_1_0;
            else
              v31 = FLOAT_N1_0;
            a4.m128_f32[0] = v31;
            a4 = _mm_shuffle_ps(a4, a4, 0);
            *(__m128 *)v30 = _mm_mul_ps(*(__m128 *)(v23 + v24 + 64), a4);
            *(_DWORD *)(v30 + 12) = *(_DWORD *)(v23 + v24 + 76);
            *(_QWORD *)(v30 + 44) = 0i64;
            *(_OWORD *)(v30 + 16) = 0i64;
            *(_QWORD *)(v30 + 32) = 0i64;
            *(_DWORD *)(v30 + 40) = 0;
            v32 = v14->m_data[v18].m_partner;
            if ( v32->m_broadPhaseHandle.m_type == 1 )
            {
              v33 = (__m128 *)((char *)v32 + v32->m_ownerOffset);
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
                  *(__m128 *)(v30 + 16) = v37;
                  *(__m128 *)(v30 + 16) = _mm_add_ps(v33[35], v37);
                }
                v38 = 0;
                if ( v33[22].m128_i8[0] == 5 )
                  v38 = 2;
                *(_DWORD *)(v30 + 48) = v38;
                if ( v33[22].m128_i8[0] == 4 )
                  v38 = 1;
                *(_DWORD *)(v30 + 48) = v38;
              }
            }
            v39 = (__m128)*(unsigned int *)(v30 + 12);
            if ( v39.m128_f32[0] < -0.00000011920929 )
            {
              v39.m128_f32[0] = v39.m128_f32[0] * v6->m_penetrationRecoverySpeed;
              v40 = _mm_xor_ps(v39, (__m128)(unsigned int)_xmm[0]);
              *(__m128 *)(v30 + 16) = _mm_add_ps(
                                        _mm_mul_ps(
                                          _mm_shuffle_ps(v40, v40, 0),
                                          _mm_mul_ps(*(__m128 *)(v23 + v24 + 64), a4)),
                                        *(__m128 *)(v30 + 16));
            }
            if ( v6->m_supportDistance > *(float *)(v30 + 12) )
              *(_DWORD *)(v30 + 12) = 0;
            ++v20;
          }
          while ( v20 < *(unsigned __int16 *)(*(_QWORD *)&v19[4].m_memSizeAndFlags + 4i64) );
          v17 = v119;
        }
      }
      v119 = ++v17;
      ++v18;
    }
    while ( v17 < v14->m_size );
    v4 = *(__m128 **)&result[0].m_enum;
    v5 = v117;
    v15 = (char)v116;
  }
  v41 = v105 & 0x3FFFFFFF;
  v42 = v6->m_userPlanes;
  v43 = v104;
  if ( (v105 & 0x3FFFFFFF) - v104 < v42 )
  {
    v44 = v42 + v104;
    if ( v41 < v42 + v104 )
    {
      if ( v44 < 2 * v41 )
        v44 = 2 * v41;
      hkArrayUtil::_reserve(result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v44, 64);
      v43 = v104;
    }
  }
  v45 = v6->m_userPlanes;
  v46 = v43 + v45 == 0;
  v47 = v43 + v45;
  v108 = 0i64;
  v109 = 0;
  v110 = 2147483648;
  input.m_position.m_quad.m128_i32[2] = v47;
  if ( v46 )
  {
    v51 = 0i64;
  }
  else
  {
    v48 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v49 = (hkLifoAllocator *)v48;
    v50 = (((16 * v47 + 127) & 0xFFFFFF80) + 15) & 0xFFFFFFF0;
    v51 = (hkSurfaceConstraintInteraction *)*((_QWORD *)v48 + 3);
    v52 = &v51->m_touched + v50;
    if ( v50 > v49->m_slabSize || v52 > v49->m_end )
      v51 = (hkSurfaceConstraintInteraction *)hkLifoAllocator::allocateFromNewSlab(v49, v50);
    else
      v49->m_cur = v52;
  }
  v108 = v51;
  v110 = v47 | 0x80000000;
  input.m_position.m_quad.m128_u64[0] = (unsigned __int64)v51;
  v46 = v6->m_userPlanes + v104 == 0;
  v53 = v6->m_userPlanes + v104;
  input.m_velocity.m_quad.m128_u64[0] = 0i64;
  input.m_velocity.m_quad.m128_u64[1] = 0x8000000000000000i64;
  v107 = v53;
  if ( v46 )
  {
    v56 = 0i64;
  }
  else
  {
    v54 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v55 = (((16 * v53 + 127) & 0xFFFFFF80) + 15) & 0xFFFFFFF0;
    v56 = (char *)v54->m_cur;
    v57 = &v56[v55];
    if ( v55 > v54->m_slabSize || v57 > v54->m_end )
      v56 = (char *)hkLifoAllocator::allocateFromNewSlab(v54, v55);
    else
      v54->m_cur = v57;
  }
  p = v56;
  input.m_position = 0i64;
  input.m_constraints = array;
  v58 = v104;
  v59 = v104;
  input.m_numConstraints = v104;
  input.m_velocity = (hkVector4f)v10.m_quad;
  input.m_deltaTime = v5->m_deltaTime.m_storage;
  input.m_minDeltaTime = input.m_deltaTime;
  input.m_upVector = v6->m_up;
  input.m_maxSurfaceVelocity.m_quad = _mm_shuffle_ps(
                                        (__m128)LODWORD(v6->m_maxSpeedForSimplexSolver),
                                        (__m128)LODWORD(v6->m_maxSpeedForSimplexSolver),
                                        0);
  output.m_planeInteractions = v108;
  v60 = v104;
  if ( (v10.m_quad.m128_i32[3] & 0x3FFFFFFF) < v104 )
  {
    if ( v104 < 2 * (v10.m_quad.m128_i32[3] & 0x3FFFFFFF) )
      v58 = 2 * (v10.m_quad.m128_i32[3] & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &input.m_velocity,
      v58,
      16);
    v58 = v104;
    v59 = input.m_numConstraints;
  }
  input.m_velocity.m_quad.m128_i32[2] = v60;
  v61 = v59;
  if ( (v110 & 0x3FFFFFFF) < v59 )
  {
    if ( v59 < 2 * (v110 & 0x3FFFFFFF) )
      v59 = 2 * (v110 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v108, v59, 16);
    v58 = v104;
    v59 = input.m_numConstraints;
  }
  v109 = v61;
  v62 = v59;
  if ( (v105 & 0x3FFFFFFF) < v59 )
  {
    if ( v59 < 2 * (v105 & 0x3FFFFFFF) )
      v59 = 2 * (v105 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v59, 64);
    v58 = v104;
    v59 = input.m_numConstraints;
  }
  v117 = (hkStepInfo *)&array[(signed __int64)v58];
  v63 = 0;
  result[0].m_enum = 0;
  if ( v62 - v58 > 0 )
  {
    do
    {
      v116 = &array[v58 + (signed __int64)(signed int)v63++];
      result[0].m_enum = v63;
    }
    while ( v63 < v62 - v104 );
    v59 = input.m_numConstraints;
  }
  v104 = v62;
  v64 = 0;
  if ( v59 > 0 )
  {
    v65 = 0i64;
    v66 = 0i64;
    do
    {
      *(hkVector4f *)(v66 + input.m_velocity.m_quad.m128_u64[0]) = array[v65].m_velocity;
      array[v65].m_velocity = 0i64;
      ++v64;
      v66 += 16i64;
      ++v65;
    }
    while ( v64 < input.m_numConstraints );
  }
  hkSimplexSolverSolve(&input, &output);
  v4[2] = 0i64;
  v4[1] = 0i64;
  if ( (_mm_movemask_ps(
          _mm_cmpleps(
            (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(output.m_velocity.m_quad, v10.m_quad), 1u), 1u),
            (__m128)_xmm)) & 7) == 7 )
    goto LABEL_124;
  v67 = _mm_mul_ps(output.m_velocity.m_quad, output.m_velocity.m_quad);
  if ( (float)(COERCE_FLOAT(_mm_shuffle_ps(v67, v67, 170))
             + (float)(COERCE_FLOAT(_mm_shuffle_ps(v67, v67, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v67, v67, 0)))) >= 0.001 )
  {
    v68 = _mm_add_ps(
            _mm_shuffle_ps(v67, v67, 170),
            _mm_add_ps(_mm_shuffle_ps(v67, v67, 85), _mm_shuffle_ps(v67, v67, 0)));
    v69 = _mm_rsqrt_ps(v68);
    output.m_velocity.m_quad = _mm_mul_ps(
                                 output.m_velocity.m_quad,
                                 _mm_andnot_ps(
                                   _mm_cmpleps(v68, (__m128)0i64),
                                   _mm_mul_ps(
                                     _mm_mul_ps(v69, *(__m128 *)_xmm),
                                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v69, v68), v69)))));
    v70 = _mm_mul_ps(v10.m_quad, output.m_velocity.m_quad);
    v70.m128_f32[0] = COERCE_FLOAT(_mm_shuffle_ps(v70, v70, 170))
                    + (float)(COERCE_FLOAT(_mm_shuffle_ps(v70, v70, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v70, v70, 0)));
    LODWORD(v4->m128_u64[0]) = ((float)(v6->m_maxSlopeCosine * v6->m_maxSlopeCosine) <= (float)(1.0
                                                                                              - (float)(v70.m128_f32[0] * v70.m128_f32[0])))
                             + 1;
  }
  else
  {
    LODWORD(v4->m128_u64[0]) = 2;
  }
  v71 = 0;
  v72 = (unsigned int)input.m_numConstraints;
  if ( input.m_numConstraints <= 0 )
    goto LABEL_124;
  v73 = (__m128 *)input.m_velocity.m_quad.m128_u64[0];
  v74 = &array->m_plane.m_quad;
  v75 = (unsigned __int64)v108 - input.m_velocity.m_quad.m128_u64[0];
  do
  {
    if ( *((_BYTE *)v73->m128_u64 + v75) )
    {
      v76 = _mm_mul_ps(*v74, v10.m_quad);
      if ( (float)(COERCE_FLOAT(_mm_shuffle_ps(v76, v76, 170))
                 + (float)(COERCE_FLOAT(_mm_shuffle_ps(v76, v76, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v76, v76, 0)))) < -0.079999998 )
      {
        v4[1] = _mm_add_ps(*v74, v4[1]);
        v4[2] = _mm_add_ps(*v73, v4[2]);
        ++v71;
      }
    }
    v74 += 4;
    ++v73;
    --v72;
  }
  while ( v72 );
  if ( v71 <= 0 )
  {
LABEL_124:
    LODWORD(v4->m128_u64[0]) = 0;
  }
  else
  {
    v77 = v4[1];
    v78 = _mm_mul_ps(v77, v77);
    v79 = _mm_add_ps(
            _mm_shuffle_ps(v78, v78, 170),
            _mm_add_ps(_mm_shuffle_ps(v78, v78, 85), _mm_shuffle_ps(v78, v78, 0)));
    v80 = _mm_rsqrt_ps(v79);
    v81 = _mm_mul_ps(_mm_mul_ps(v80, v79), v80);
    v4[1] = _mm_mul_ps(
              _mm_andnot_ps(
                _mm_cmpleps(v79, (__m128)0i64),
                _mm_mul_ps(_mm_mul_ps(v80, *(__m128 *)_xmm), _mm_sub_ps((__m128)_xmm, v81))),
              v77);
    v81.m128_f32[0] = 1.0 / (float)v71;
    v4[2] = _mm_mul_ps(_mm_shuffle_ps(v81, v81, 0), v4[2]);
    if ( LODWORD(v4->m128_u64[0]) && !v15 )
    {
      LODWORD(v4->m128_u64[0]) = 0;
      v6->m_supportedOffCentre = 1;
      goto LABEL_93;
    }
  }
  v6->m_supportedOffCentre = 0;
LABEL_93:
  v82 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v83 = v82[1];
  if ( v83 < v82[3] )
  {
    *(_QWORD *)v83 = "Et";
    v84 = __rdtsc();
    *(_DWORD *)(v83 + 8) = v84;
    v82[1] = v83 + 16;
  }
  v85 = (char *)p;
  v86 = input.m_velocity.m_quad.m128_i32[2];
  if ( p == (void *)input.m_velocity.m_quad.m128_u64[0] )
    v86 = 0;
  input.m_velocity.m_quad.m128_i32[2] = v86;
  v87 = v107;
  v88 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v89 = (16 * v87 + 127) & 0xFFFFFF80;
  v90 = (v89 + 15) & 0xFFFFFFF0;
  if ( v89 > v88->m_slabSize || &v85[v90] != v88->m_cur || v88->m_firstNonLifoEnd == v85 )
    hkLifoAllocator::slowBlockFree(v88, v85, v90);
  else
    v88->m_cur = v85;
  input.m_velocity.m_quad.m128_i32[2] = 0;
  if ( input.m_velocity.m_quad.m128_i32[3] >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      (void *)input.m_velocity.m_quad.m128_u64[0],
      16 * input.m_velocity.m_quad.m128_i32[3]);
  input.m_velocity.m_quad.m128_u64[0] = 0i64;
  input.m_velocity.m_quad.m128_i32[3] = 2147483648;
  v91 = (char *)input.m_position.m_quad.m128_u64[0];
  v92 = v109;
  if ( (hkSurfaceConstraintInteraction *)input.m_position.m_quad.m128_u64[0] == v108 )
    v92 = 0;
  v109 = v92;
  v93 = input.m_position.m_quad.m128_f32[2];
  v94 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v95 = (16 * LODWORD(v93) + 127) & 0xFFFFFF80;
  v96 = (v95 + 15) & 0xFFFFFFF0;
  if ( v95 > v94->m_slabSize || &v91[v96] != v94->m_cur || v94->m_firstNonLifoEnd == v91 )
    hkLifoAllocator::slowBlockFree(v94, v91, v96);
  else
    v94->m_cur = v91;
  v109 = 0;
  if ( v110 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v108,
      16 * v110);
  v108 = 0i64;
  v110 = 2147483648;
  v97 = (char *)p;
  v98 = v104;
  if ( p == array )
    v98 = 0;
  v104 = v98;
  v99 = v107;
  v100 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v101 = ((v99 << 6) + 127) & 0xFFFFFF80;
  v102 = (v101 + 15) & 0xFFFFFFF0;
  if ( v101 > v100->m_slabSize || &v97[v102] != v100->m_cur || v100->m_firstNonLifoEnd == v97 )
    hkLifoAllocator::slowBlockFree(v100, v97, v102);
  else
    v100->m_cur = v97;
  v104 = 0;
  if ( v105 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      v105 << 6);
}

// File Line: 505
// RVA: 0x484A90
int CharacterRigidBody::checkSupportForNonPlayer(...)
{
  __m128 *v4; // rdi
  hkStepInfo *v5; // rsi
  CharacterRigidBody *v6; // r15
  _QWORD *v7; // r9
  unsigned __int64 v8; // rcx
  unsigned __int64 v9; // rax
  hkVector4f v10; // xmm12
  hkLifoAllocator *v11; // rax
  hkSurfaceConstraintInfo *v12; // rcx
  unsigned __int64 v13; // rdx
  hkArray<hkpLinkedCollidable::CollisionEntry,hkContainerHeapAllocator> *v14; // r12
  char v15; // al
  float v16; // xmm6_4
  __int64 v17; // r13
  hkpContactMgr *v18; // r14
  signed int v19; // ebx
  int v20; // edx
  __int64 i; // rcx
  signed __int64 v22; // rdi
  __int64 v23; // rsi
  __m128 v24; // xmm0
  float v25; // xmm0_4
  int v26; // ecx
  __int64 v27; // rdx
  signed int v28; // ecx
  __int64 v29; // rdx
  float v30; // xmm0_4
  hkpLinkedCollidable *v31; // r8
  __m128 *v32; // rcx
  char v33; // r8
  __m128 v34; // xmm1
  __m128 v35; // xmm2
  __m128 v36; // xmm2
  signed int v37; // eax
  __m128 v38; // xmm1
  __m128 v39; // xmm1
  int v40; // eax
  bool v41; // sf
  unsigned __int8 v42; // of
  int v43; // ecx
  int v44; // er8
  int v45; // edx
  int v46; // er9
  int v47; // ebx
  bool v48; // zf
  int v49; // ebx
  LPVOID v50; // rax
  hkLifoAllocator *v51; // r8
  int v52; // edx
  hkSurfaceConstraintInteraction *v53; // rax
  char *v54; // rcx
  int v55; // ebx
  hkLifoAllocator *v56; // rax
  int v57; // edx
  char *v58; // rcx
  char *v59; // r8
  int v60; // er8
  int v61; // edx
  int v62; // ebx
  int v63; // ebx
  int v64; // ebx
  hkResultEnum v65; // ecx
  int v66; // er9
  __int64 v67; // rdx
  __int64 v68; // r8
  __m128 v69; // xmm4
  __m128 v70; // xmm4
  __m128 v71; // xmm0
  __m128 v72; // xmm2
  signed int v73; // edx
  __int64 v74; // r8
  __m128 *v75; // rax
  __m128 *v76; // rcx
  unsigned __int64 v77; // r9
  __m128 v78; // xmm2
  __m128 v79; // xmm5
  __m128 v80; // xmm3
  __m128 v81; // xmm3
  __m128 v82; // xmm0
  __m128 v83; // xmm1
  _QWORD *v84; // r8
  unsigned __int64 v85; // rcx
  unsigned __int64 v86; // rax
  char *v87; // rdi
  int v88; // ecx
  int v89; // ebx
  hkLifoAllocator *v90; // rcx
  signed int v91; // ebx
  int v92; // er8
  char *v93; // rdi
  int v94; // ecx
  float v95; // ebx
  hkLifoAllocator *v96; // rcx
  signed int v97; // ebx
  int v98; // er8
  char *v99; // rdi
  int v100; // ecx
  int v101; // ebx
  hkLifoAllocator *v102; // rcx
  signed int v103; // ebx
  int v104; // er8
  hkSurfaceConstraintInfo *array; // [rsp+30h] [rbp-90h]
  int v106; // [rsp+38h] [rbp-88h]
  int v107; // [rsp+3Ch] [rbp-84h]
  void *p; // [rsp+40h] [rbp-80h]
  int v109; // [rsp+48h] [rbp-78h]
  hkSurfaceConstraintInteraction *v110; // [rsp+50h] [rbp-70h]
  int v111; // [rsp+58h] [rbp-68h]
  int v112; // [rsp+5Ch] [rbp-64h]
  hkSimplexSolverInput input; // [rsp+60h] [rbp-60h]
  __int64 v114; // [rsp+C0h] [rbp+0h]
  hkSurfaceConstraintInfo *v115; // [rsp+C8h] [rbp+8h]
  __int64 v116; // [rsp+D0h] [rbp+10h]
  hkSimplexSolverOutput output; // [rsp+E0h] [rbp+20h]
  hkSurfaceConstraintInfo *v118; // [rsp+1D0h] [rbp+110h]
  hkStepInfo *v119; // [rsp+1D8h] [rbp+118h]
  hkResult result[2]; // [rsp+1E0h] [rbp+120h]
  int v121; // [rsp+1E8h] [rbp+128h]

  v116 = -2i64;
  v4 = (__m128 *)ground;
  v5 = stepInfo;
  v6 = this;
  v7 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v8 = v7[1];
  if ( v8 < v7[3] )
  {
    *(_QWORD *)v8 = "TtcheckSupport";
    v9 = __rdtsc();
    *(_DWORD *)(v8 + 8) = v9;
    v7[1] = v8 + 16;
  }
  v10.m_quad = _mm_xor_ps(v6->m_up.m_quad, (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
  array = 0i64;
  v106 = 0;
  v107 = 2147483648;
  v109 = 20;
  v11 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v12 = (hkSurfaceConstraintInfo *)v11->m_cur;
  v13 = (unsigned __int64)&v12[20];
  if ( v11->m_slabSize < 1280 || (void *)v13 > v11->m_end )
    v12 = (hkSurfaceConstraintInfo *)hkLifoAllocator::allocateFromNewSlab(v11, 1280);
  else
    v11->m_cur = (void *)v13;
  array = v12;
  v107 = -2147483628;
  p = v12;
  v14 = &v6->m_character->m_collidable.m_collisionEntries;
  v15 = CharacterRigidBody::DoesBoundingBoxProvideSupport(v6, v14) == 0;
  LOBYTE(v118) = v15;
  if ( v15 )
    LODWORD(v4->m128_u64[0]) = 0;
  v16 = FLOAT_3_4028235e38;
  v121 = 0;
  if ( v14->m_size > 0 )
  {
    v17 = 0i64;
    do
    {
      if ( v15 )
        break;
      v18 = v14->m_data[v17].m_agentEntry->m_contactMgr;
      if ( v18->m_type == TYPE_SIMPLE_CONSTRAINT_CONTACT_MGR )
      {
        v19 = 0;
        if ( *(_WORD *)(*(_QWORD *)&v18[4].m_memSizeAndFlags + 4i64) > 0u )
        {
          do
          {
            v20 = LODWORD(v18[3].vfptr) - 1;
            for ( i = v20; i >= 0; --i )
            {
              if ( *(unsigned __int8 *)(i + *(_QWORD *)&v18[2].m_type) == v19 )
                break;
              LOWORD(v20) = v20 - 1;
            }
            v22 = 32i64 * *(unsigned __int8 *)((unsigned __int16)v20 + *(_QWORD *)&v18[2].m_type);
            v23 = *(_QWORD *)&v18[4].m_memSizeAndFlags;
            v24 = _mm_sub_ps(
                    *(__m128 *)(v22 + v23 + 48),
                    v6->m_character->m_motion.m_motionState.m_transform.m_translation.m_quad);
            LODWORD(v25) = (unsigned __int128)_mm_shuffle_ps(v24, v24, 170);
            if ( v16 > v25 )
              v16 = v25;
            v26 = v106;
            if ( v106 == (v107 & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 64);
              v26 = v106;
            }
            v27 = (__int64)&array[(signed __int64)v26];
            v115 = &array[(signed __int64)v26];
            v28 = 0;
            LODWORD(v110) = 0;
            do
            {
              v114 = v27 + ((signed __int64)v28++ << 6);
              LODWORD(v110) = v28;
            }
            while ( v28 < 1 );
            v29 = (__int64)&array[(signed __int64)v106++];
            if ( v14->m_data[v17].m_agentEntry->m_collidable[0] == &v6->m_character->m_collidable )
              v30 = *(float *)&FLOAT_1_0;
            else
              v30 = FLOAT_N1_0;
            a4.m128_f32[0] = v30;
            a4 = _mm_shuffle_ps(a4, a4, 0);
            *(__m128 *)v29 = _mm_mul_ps(*(__m128 *)(v22 + v23 + 64), a4);
            *(_DWORD *)(v29 + 12) = *(_DWORD *)(v22 + v23 + 76);
            *(_QWORD *)(v29 + 44) = 0i64;
            *(_OWORD *)(v29 + 16) = 0i64;
            *(_QWORD *)(v29 + 32) = 0i64;
            *(_DWORD *)(v29 + 40) = 0;
            v31 = v14->m_data[v17].m_partner;
            if ( v31->m_broadPhaseHandle.m_type == 1 )
            {
              v32 = (__m128 *)((char *)v31 + v31->m_ownerOffset);
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
                  *(__m128 *)(v29 + 16) = v36;
                  *(__m128 *)(v29 + 16) = _mm_add_ps(v32[35], v36);
                }
                v37 = 0;
                if ( v32[22].m128_i8[0] == 5 )
                  v37 = 2;
                *(_DWORD *)(v29 + 48) = v37;
                if ( v32[22].m128_i8[0] == 4 )
                  v37 = 1;
                *(_DWORD *)(v29 + 48) = v37;
              }
            }
            v38 = (__m128)*(unsigned int *)(v29 + 12);
            if ( v38.m128_f32[0] < -0.00000011920929 )
            {
              v38.m128_f32[0] = v38.m128_f32[0] * v6->m_penetrationRecoverySpeed;
              v39 = _mm_xor_ps(v38, (__m128)(unsigned int)_xmm[0]);
              *(__m128 *)(v29 + 16) = _mm_add_ps(
                                        *(__m128 *)(v29 + 16),
                                        _mm_mul_ps(
                                          _mm_shuffle_ps(v39, v39, 0),
                                          _mm_mul_ps(*(__m128 *)(v22 + v23 + 64), a4)));
            }
            if ( v6->m_supportDistance > *(float *)(v29 + 12) )
              *(_DWORD *)(v29 + 12) = 0;
            ++v19;
          }
          while ( v19 < *(unsigned __int16 *)(*(_QWORD *)&v18[4].m_memSizeAndFlags + 4i64) );
        }
      }
      v40 = v121 + 1;
      v121 = v40;
      ++v17;
      v42 = __OFSUB__(v40, v14->m_size);
      v41 = v40 - v14->m_size < 0;
      v15 = (char)v118;
    }
    while ( v41 ^ v42 );
    v4 = *(__m128 **)&result[0].m_enum;
    v5 = v119;
  }
  v43 = v107 & 0x3FFFFFFF;
  v44 = v6->m_userPlanes;
  v45 = v106;
  if ( (v107 & 0x3FFFFFFF) - v106 < v44 )
  {
    v46 = v44 + v106;
    if ( v43 < v44 + v106 )
    {
      if ( v46 < 2 * v43 )
        v46 = 2 * v43;
      hkArrayUtil::_reserve(result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v46, 64);
      v45 = v106;
    }
  }
  v47 = v6->m_userPlanes;
  v48 = v45 + v47 == 0;
  v49 = v45 + v47;
  v110 = 0i64;
  v111 = 0;
  v112 = 2147483648;
  input.m_position.m_quad.m128_i32[2] = v49;
  if ( v48 )
  {
    v53 = 0i64;
  }
  else
  {
    v50 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v51 = (hkLifoAllocator *)v50;
    v52 = (((16 * v49 + 127) & 0xFFFFFF80) + 15) & 0xFFFFFFF0;
    v53 = (hkSurfaceConstraintInteraction *)*((_QWORD *)v50 + 3);
    v54 = &v53->m_touched + v52;
    if ( v52 > v51->m_slabSize || v54 > v51->m_end )
      v53 = (hkSurfaceConstraintInteraction *)hkLifoAllocator::allocateFromNewSlab(v51, v52);
    else
      v51->m_cur = v54;
  }
  v110 = v53;
  v112 = v49 | 0x80000000;
  input.m_position.m_quad.m128_u64[0] = (unsigned __int64)v53;
  v48 = v6->m_userPlanes + v106 == 0;
  v55 = v6->m_userPlanes + v106;
  input.m_velocity.m_quad.m128_u64[0] = 0i64;
  input.m_velocity.m_quad.m128_u64[1] = 0x8000000000000000i64;
  v109 = v55;
  if ( v48 )
  {
    v58 = 0i64;
  }
  else
  {
    v56 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v57 = (((16 * v55 + 127) & 0xFFFFFF80) + 15) & 0xFFFFFFF0;
    v58 = (char *)v56->m_cur;
    v59 = &v58[v57];
    if ( v57 > v56->m_slabSize || v59 > v56->m_end )
      v58 = (char *)hkLifoAllocator::allocateFromNewSlab(v56, v57);
    else
      v56->m_cur = v59;
  }
  p = v58;
  input.m_position = 0i64;
  input.m_constraints = array;
  v60 = v106;
  v61 = v106;
  input.m_numConstraints = v106;
  input.m_velocity = (hkVector4f)v10.m_quad;
  input.m_deltaTime = v5->m_deltaTime.m_storage;
  input.m_minDeltaTime = input.m_deltaTime;
  input.m_upVector = v6->m_up;
  input.m_maxSurfaceVelocity.m_quad = _mm_shuffle_ps(
                                        (__m128)LODWORD(v6->m_maxSpeedForSimplexSolver),
                                        (__m128)LODWORD(v6->m_maxSpeedForSimplexSolver),
                                        0);
  output.m_planeInteractions = v110;
  v62 = v106;
  if ( (v10.m_quad.m128_i32[3] & 0x3FFFFFFF) < v106 )
  {
    if ( v106 < 2 * (v10.m_quad.m128_i32[3] & 0x3FFFFFFF) )
      v60 = 2 * (v10.m_quad.m128_i32[3] & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &input.m_velocity,
      v60,
      16);
    v60 = v106;
    v61 = input.m_numConstraints;
  }
  input.m_velocity.m_quad.m128_i32[2] = v62;
  v63 = v61;
  if ( (v112 & 0x3FFFFFFF) < v61 )
  {
    if ( v61 < 2 * (v112 & 0x3FFFFFFF) )
      v61 = 2 * (v112 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v110, v61, 16);
    v60 = v106;
    v61 = input.m_numConstraints;
  }
  v111 = v63;
  v64 = v61;
  if ( (v107 & 0x3FFFFFFF) < v61 )
  {
    if ( v61 < 2 * (v107 & 0x3FFFFFFF) )
      v61 = 2 * (v107 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v61, 64);
    v60 = v106;
    v61 = input.m_numConstraints;
  }
  v119 = (hkStepInfo *)&array[(signed __int64)v60];
  v65 = 0;
  result[0].m_enum = 0;
  if ( v64 - v60 > 0 )
  {
    do
    {
      v118 = &array[v60 + (signed __int64)(signed int)v65++];
      result[0].m_enum = v65;
    }
    while ( v65 < v64 - v106 );
    v61 = input.m_numConstraints;
  }
  v106 = v64;
  v66 = 0;
  if ( v61 > 0 )
  {
    v67 = 0i64;
    v68 = 0i64;
    do
    {
      *(hkVector4f *)(v68 + input.m_velocity.m_quad.m128_u64[0]) = array[v67].m_velocity;
      array[v67].m_velocity = 0i64;
      ++v66;
      v68 += 16i64;
      ++v67;
    }
    while ( v66 < input.m_numConstraints );
  }
  hkSimplexSolverSolve(&input, &output);
  v4[2] = 0i64;
  v4[1] = 0i64;
  if ( (_mm_movemask_ps(
          _mm_cmpleps(
            (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(output.m_velocity.m_quad, v10.m_quad), 1u), 1u),
            (__m128)_xmm)) & 7) == 7 )
    goto LABEL_123;
  v69 = _mm_mul_ps(output.m_velocity.m_quad, output.m_velocity.m_quad);
  if ( (float)(COERCE_FLOAT(_mm_shuffle_ps(v69, v69, 170))
             + (float)(COERCE_FLOAT(_mm_shuffle_ps(v69, v69, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v69, v69, 0)))) >= 0.001 )
  {
    v70 = _mm_add_ps(
            _mm_shuffle_ps(v69, v69, 170),
            _mm_add_ps(_mm_shuffle_ps(v69, v69, 85), _mm_shuffle_ps(v69, v69, 0)));
    v71 = _mm_rsqrt_ps(v70);
    output.m_velocity.m_quad = _mm_mul_ps(
                                 output.m_velocity.m_quad,
                                 _mm_andnot_ps(
                                   _mm_cmpleps(v70, (__m128)0i64),
                                   _mm_mul_ps(
                                     _mm_mul_ps(v71, *(__m128 *)_xmm),
                                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v71, v70), v71)))));
    v72 = _mm_mul_ps(v10.m_quad, output.m_velocity.m_quad);
    v72.m128_f32[0] = COERCE_FLOAT(_mm_shuffle_ps(v72, v72, 170))
                    + (float)(COERCE_FLOAT(_mm_shuffle_ps(v72, v72, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v72, v72, 0)));
    LODWORD(v4->m128_u64[0]) = ((float)(v6->m_maxSlopeCosine * v6->m_maxSlopeCosine) <= (float)(1.0
                                                                                              - (float)(v72.m128_f32[0] * v72.m128_f32[0])))
                             + 1;
  }
  else
  {
    LODWORD(v4->m128_u64[0]) = 2;
  }
  v73 = 0;
  v74 = (unsigned int)input.m_numConstraints;
  if ( input.m_numConstraints <= 0 )
    goto LABEL_123;
  v75 = (__m128 *)input.m_velocity.m_quad.m128_u64[0];
  v76 = &array->m_plane.m_quad;
  v77 = (unsigned __int64)v110 - input.m_velocity.m_quad.m128_u64[0];
  do
  {
    if ( *((_BYTE *)v75->m128_u64 + v77) )
    {
      v78 = _mm_mul_ps(*v76, v10.m_quad);
      if ( (float)(COERCE_FLOAT(_mm_shuffle_ps(v78, v78, 170))
                 + (float)(COERCE_FLOAT(_mm_shuffle_ps(v78, v78, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v78, v78, 0)))) < -0.079999998 )
      {
        v4[1] = _mm_add_ps(*v76, v4[1]);
        v4[2] = _mm_add_ps(*v75, v4[2]);
        ++v73;
      }
    }
    v76 += 4;
    ++v75;
    --v74;
  }
  while ( v74 );
  if ( v73 <= 0 )
  {
LABEL_123:
    LODWORD(v4->m128_u64[0]) = 0;
  }
  else
  {
    v79 = v4[1];
    v80 = _mm_mul_ps(v79, v79);
    v81 = _mm_add_ps(
            _mm_shuffle_ps(v80, v80, 170),
            _mm_add_ps(_mm_shuffle_ps(v80, v80, 85), _mm_shuffle_ps(v80, v80, 0)));
    v82 = _mm_rsqrt_ps(v81);
    v83 = _mm_mul_ps(_mm_mul_ps(v82, v81), v82);
    v4[1] = _mm_mul_ps(
              _mm_andnot_ps(
                _mm_cmpleps(v81, (__m128)0i64),
                _mm_mul_ps(_mm_mul_ps(v82, *(__m128 *)_xmm), _mm_sub_ps((__m128)_xmm, v83))),
              v79);
    v83.m128_f32[0] = 1.0 / (float)v73;
    v4[2] = _mm_mul_ps(_mm_shuffle_ps(v83, v83, 0), v4[2]);
  }
  v84 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v85 = v84[1];
  if ( v85 < v84[3] )
  {
    *(_QWORD *)v85 = "Et";
    v86 = __rdtsc();
    *(_DWORD *)(v85 + 8) = v86;
    v84[1] = v85 + 16;
  }
  v87 = (char *)p;
  v88 = input.m_velocity.m_quad.m128_i32[2];
  if ( p == (void *)input.m_velocity.m_quad.m128_u64[0] )
    v88 = 0;
  input.m_velocity.m_quad.m128_i32[2] = v88;
  v89 = v109;
  v90 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v91 = (16 * v89 + 127) & 0xFFFFFF80;
  v92 = (v91 + 15) & 0xFFFFFFF0;
  if ( v91 > v90->m_slabSize || &v87[v92] != v90->m_cur || v90->m_firstNonLifoEnd == v87 )
    hkLifoAllocator::slowBlockFree(v90, v87, v92);
  else
    v90->m_cur = v87;
  input.m_velocity.m_quad.m128_i32[2] = 0;
  if ( input.m_velocity.m_quad.m128_i32[3] >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      (void *)input.m_velocity.m_quad.m128_u64[0],
      16 * input.m_velocity.m_quad.m128_i32[3]);
  input.m_velocity.m_quad.m128_u64[0] = 0i64;
  input.m_velocity.m_quad.m128_i32[3] = 2147483648;
  v93 = (char *)input.m_position.m_quad.m128_u64[0];
  v94 = v111;
  if ( (hkSurfaceConstraintInteraction *)input.m_position.m_quad.m128_u64[0] == v110 )
    v94 = 0;
  v111 = v94;
  v95 = input.m_position.m_quad.m128_f32[2];
  v96 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v97 = (16 * LODWORD(v95) + 127) & 0xFFFFFF80;
  v98 = (v97 + 15) & 0xFFFFFFF0;
  if ( v97 > v96->m_slabSize || &v93[v98] != v96->m_cur || v96->m_firstNonLifoEnd == v93 )
    hkLifoAllocator::slowBlockFree(v96, v93, v98);
  else
    v96->m_cur = v93;
  v111 = 0;
  if ( v112 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v110,
      16 * v112);
  v110 = 0i64;
  v112 = 2147483648;
  v99 = (char *)p;
  v100 = v106;
  if ( p == array )
    v100 = 0;
  v106 = v100;
  v101 = v109;
  v102 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v103 = ((v101 << 6) + 127) & 0xFFFFFF80;
  v104 = (v103 + 15) & 0xFFFFFFF0;
  if ( v103 > v102->m_slabSize || &v99[v104] != v102->m_cur || v102->m_firstNonLifoEnd == v99 )
    hkLifoAllocator::slowBlockFree(v102, v99, v104);
  else
    v102->m_cur = v99;
  v106 = 0;
  if ( v107 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      v107 << 6);
}

// File Line: 781
// RVA: 0x463C30
bool __fastcall CharacterRigidBody::DoesBoundingBoxProvideSupport(CharacterRigidBody *this, hkArray<hkpLinkedCollidable::CollisionEntry,hkContainerHeapAllocator> *entries)
{
  hkVector4f v2; // xmm4
  __int64 v3; // rbx
  CharacterRigidBody *v4; // rdi
  hkVector4f v5; // xmm3
  hkpLinkedCollidable::CollisionEntry *v6; // r11
  hkpContactMgr *v7; // r10
  signed int v8; // er9
  int v9; // edx
  __int64 i; // rcx
  __m128 v11; // ST20_16
  __m128 v13; // [rsp+20h] [rbp-38h]
  hkAabb v14; // [rsp+30h] [rbp-28h]

  v2.m_quad = (__m128)xmmword_141A712A0;
  v3 = entries->m_size;
  v14.m_min = (hkVector4f)xmmword_141A712A0;
  v4 = this;
  v5.m_quad = _mm_xor_ps(
                (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                (__m128)xmmword_141A712A0);
  v14.m_max = (hkVector4f)v5.m_quad;
  if ( v3 > 0 )
  {
    v6 = entries->m_data;
    do
    {
      v7 = v6->m_agentEntry->m_contactMgr;
      if ( v7->m_type == TYPE_SIMPLE_CONSTRAINT_CONTACT_MGR )
      {
        v8 = 0;
        if ( *(_WORD *)(*(_QWORD *)&v7[4].m_memSizeAndFlags + 4i64) > 0u )
        {
          do
          {
            v9 = LODWORD(v7[3].vfptr) - 1;
            for ( i = v9; i >= 0; --i )
            {
              if ( *(unsigned __int8 *)(*(_QWORD *)&v7[2].m_type + i) == v8 )
                break;
              LOWORD(v9) = v9 - 1;
            }
            ++v8;
            v11 = *(__m128 *)(32i64 * *(unsigned __int8 *)((unsigned __int16)v9 + *(_QWORD *)&v7[2].m_type)
                            + *(_QWORD *)&v7[4].m_memSizeAndFlags
                            + 48);
            v11.m128_i32[2] = 0;
            v5.m_quad = _mm_max_ps(v5.m_quad, _mm_add_ps((__m128)_xmm, v11));
            v14.m_max = (hkVector4f)v5.m_quad;
            v2.m_quad = _mm_min_ps(v2.m_quad, _mm_sub_ps(v11, (__m128)_xmm));
            v14.m_min = (hkVector4f)v2.m_quad;
          }
          while ( v8 < *(unsigned __int16 *)(*(_QWORD *)&v7[4].m_memSizeAndFlags + 4i64) );
        }
      }
      ++v6;
      --v3;
    }
    while ( v3 );
  }
  v13 = v4->m_character->m_motion.m_motionState.m_transform.m_translation.m_quad;
  v13.m128_i32[2] = 0;
  return hkAabb::isValid(&v14)
      && (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(v13, v14.m_max.m_quad), _mm_cmpleps(v14.m_min.m_quad, v13))) & 7) == 7;
}

// File Line: 1199
// RVA: 0x4876B0
void __fastcall CharacterRigidBody::entityAddedCallback(CharacterRigidBody *this, hkpEntity *entity)
{
  char *v2; // rbx
  CharacterRigidBody *v3; // rdi
  hkpEntity *v4; // rsi
  hkpWorldPostSimulationListener *v5; // rdx

  v2 = (char *)&this[-1].m_maxForce;
  v3 = this;
  v4 = entity;
  hkReferencedObject::addReference((hkReferencedObject *)&this[-1].m_maxForce);
  if ( v2 )
    v5 = (hkpWorldPostSimulationListener *)&v3->m_memSizeAndFlags;
  else
    v5 = 0i64;
  hkpWorld::addWorldPostSimulationListener(v4->m_world, v5);
}

// File Line: 1208
// RVA: 0x487750
void __fastcall CharacterRigidBody::entityRemovedCallback(CharacterRigidBody *this, hkpEntity *entity)
{
  hkReferencedObject *v2; // rbx
  hkpEntity *v3; // rax
  hkpWorldPostSimulationListener *v4; // rdx

  v2 = (hkReferencedObject *)&this[-1].m_maxForce;
  v3 = entity;
  if ( this == (CharacterRigidBody *)16 )
    v4 = 0i64;
  else
    v4 = (hkpWorldPostSimulationListener *)&this->m_memSizeAndFlags;
  hkpWorld::removeWorldPostSimulationListener(v3->m_world, v4);
  hkReferencedObject::removeReference(v2);
}

// File Line: 1215
// RVA: 0x4883B0
void __fastcall CharacterRigidBody::processActualPoints(CharacterRigidBody *this, hkpWorld *world)
{
  hkpWorld *v2; // r12
  CharacterRigidBody *v3; // rdi
  hkpRigidBody *v4; // r15
  __int64 v5; // rbp
  __int64 v6; // r14
  hkpLinkedCollidable::CollisionEntry *v7; // rsi
  float normalFactor; // xmm6_4
  hkpContactMgr *v9; // rbx
  hkArray<unsigned short,hkContainerHeapAllocator> contactPointIds; // [rsp+40h] [rbp-A8h]
  char v11; // [rsp+50h] [rbp-98h]

  v2 = world;
  v3 = this;
  v4 = this->m_character;
  v5 = v4->m_collidable.m_collisionEntries.m_size;
  if ( v5 > 0 )
  {
    v6 = 0i64;
    do
    {
      v7 = &v4->m_collidable.m_collisionEntries.m_data[v6];
      if ( v7->m_agentEntry->m_collidable[0] == &v3->m_character->m_collidable )
        normalFactor = *(float *)&FLOAT_1_0;
      else
        normalFactor = FLOAT_N1_0;
      v9 = v7->m_agentEntry->m_contactMgr;
      if ( v9->m_type == TYPE_SIMPLE_CONSTRAINT_CONTACT_MGR )
      {
        contactPointIds.m_data = (unsigned __int16 *)&v11;
        contactPointIds.m_size = 0;
        contactPointIds.m_capacityAndFlags = 0x80000020;
        v9->vfptr[6].__vecDelDtor((hkBaseObject *)&v9->vfptr, (unsigned int)&contactPointIds);
        if ( v3->m_isPlayer )
          CharacterRigidBody::unweldContactPointsForPlayer(
            v3,
            v7,
            (hkpSimpleConstraintContactMgr *)v9,
            &contactPointIds,
            normalFactor);
        else
          CharacterRigidBody::unweldContactPointsForNonPlayer(
            v3,
            v7,
            (hkpSimpleConstraintContactMgr *)v9,
            &contactPointIds,
            normalFactor);
        CharacterRigidBody::considerCollisionEntryForSlope(
          v3,
          v2,
          v7,
          (hkpSimpleConstraintContactMgr *)v9,
          &contactPointIds);
        CharacterRigidBody::considerCollisionEntryForMassModification(
          v3,
          v2,
          v7,
          (hkpSimpleConstraintContactMgr *)v9,
          &contactPointIds);
        contactPointIds.m_size = 0;
        if ( contactPointIds.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            contactPointIds.m_data,
            2 * (contactPointIds.m_capacityAndFlags & 0x3FFFFFFF));
        contactPointIds.m_data = 0i64;
        contactPointIds.m_capacityAndFlags = 2147483648;
      }
      ++v6;
      --v5;
    }
    while ( v5 );
  }
}

// File Line: 1244
// RVA: 0x488330
void __fastcall CharacterRigidBody::postSimulationCallback(CharacterRigidBody *this, hkpWorld *world)
{
  CharacterRigidBody *v2; // rbx
  hkpWorld *v3; // rdi
  bool v4; // zf

  ++world->m_criticalOperationsLockCount;
  v2 = (CharacterRigidBody *)((char *)this - 24);
  v3 = world;
  CharacterRigidBody::discardVerticalPoints((CharacterRigidBody *)((char *)this - 24));
  CharacterRigidBody::processActualPoints(v2, v3);
  v4 = v3->m_criticalOperationsLockCount-- == 1;
  if ( v4 && !v3->m_blockExecutingPendingOperations.m_bool )
  {
    if ( v3->m_pendingOperationsCount )
      hkpWorld::internal_executePendingOperations(v3);
    if ( v3->m_pendingOperationQueueCount == 1 )
    {
      if ( v3->m_pendingBodyOperationsCount )
        hkpWorld::internal_executePendingBodyOperations(v3);
    }
  }
}

// File Line: 1268
// RVA: 0x4891B0
void __fastcall CharacterRigidBody::unweldContactPointsForPlayer(CharacterRigidBody *this, hkpLinkedCollidable::CollisionEntry *entry, hkpSimpleConstraintContactMgr *mgr, hkArray<unsigned short,hkContainerHeapAllocator> *contactPointIds, float normalFactor)
{
  hkArray<unsigned short,hkContainerHeapAllocator> *v5; // rsi
  int v6; // er9
  hkpSimpleConstraintContactMgr *v7; // r14
  CharacterRigidBody *v8; // r15
  hkVector4f v9; // xmm1
  __m128 *v10; // rax
  int v11; // ebx
  hkVector4f v12; // xmm5
  __m128 v13; // xmm9
  hkVector4f v14; // xmm1
  __m128 v15; // xmm9
  hkpLinkedCollidable *v16; // r8
  hkpLinkedCollidable *v17; // rdx
  __m128 v18; // xmm11
  hkpLinkedCollidable *v19; // rcx
  hkpLinkedCollidable *v20; // rax
  char v21; // dl
  bool v22; // bp
  float v23; // xmm12_4
  bool v24; // r12
  __int64 v25; // rdi
  __m128 *v26; // rax
  __m128 v27; // xmm5
  __m128 v28; // xmm4
  __m128 v29; // xmm1
  float v30; // xmm2_4
  float v31; // xmm2_4
  __m128 v32; // xmm1
  float v33; // xmm3_4
  __m128 v34; // xmm5
  __m128 v35; // xmm7
  __m128 v36; // xmm5
  __m128 v37; // xmm1
  __m128 v38; // xmm3
  __m128 v39; // xmm2
  __m128 v40; // xmm4
  __m128 v41; // xmm6
  __m128 v42; // xmm0
  __m128 v43; // xmm5
  __m128 v44; // xmm1
  __m128 v45; // xmm3
  __m128 v46; // xmm2
  __m128 v47; // xmm4

  v5 = contactPointIds;
  v6 = contactPointIds->m_size;
  v7 = mgr;
  v8 = this;
  if ( v6 > 0 )
  {
    v9.m_quad = (__m128)this->mBottomVertex;
    v10 = &this->m_character->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad;
    v11 = 0;
    v12.m_quad = (__m128)this->m_character->m_motion.m_motionState.m_transform.m_translation;
    v13 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v9.m_quad, v9.m_quad, 0), *v10),
              _mm_mul_ps(
                _mm_shuffle_ps(v9.m_quad, v9.m_quad, 85),
                this->m_character->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad)),
            _mm_mul_ps(
              _mm_shuffle_ps(v9.m_quad, v9.m_quad, 170),
              this->m_character->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad));
    v14.m_quad = (__m128)this->mTopVertex;
    v15 = _mm_add_ps(v13, v12.m_quad);
    v16 = entry->m_agentEntry->m_collidable[0];
    v17 = entry->m_agentEntry->m_collidable[1];
    v18 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v14.m_quad, v14.m_quad, 0), *v10),
                _mm_mul_ps(
                  _mm_shuffle_ps(this->mTopVertex.m_quad, v14.m_quad, 85),
                  this->m_character->m_motion.m_motionState.m_transform.m_rotation.m_col1.m_quad)),
              _mm_mul_ps(
                _mm_shuffle_ps(v14.m_quad, v14.m_quad, 170),
                this->m_character->m_motion.m_motionState.m_transform.m_rotation.m_col2.m_quad)),
            v12.m_quad);
    v19 = v16->m_broadPhaseHandle.m_type == 1 ? (hkpLinkedCollidable *)((char *)v16 + v16->m_ownerOffset) : 0i64;
    v20 = v17->m_broadPhaseHandle.m_type == 1 ? (hkpLinkedCollidable *)((char *)v17 + v17->m_ownerOffset) : 0i64;
    v22 = 0;
    if ( v19 && v20 )
    {
      if ( (v21 = (char)v19[2].m_boundingVolumeData.m_childShapeKeys, v21 == 7)
        && LOBYTE(v20[2].m_boundingVolumeData.m_childShapeKeys) == 5
        || v21 == 5 && LOBYTE(v20[2].m_boundingVolumeData.m_childShapeKeys) == 7 )
      {
        v22 = 1;
      }
    }
    LODWORD(v23) = (unsigned __int128)_mm_shuffle_ps(v15, v15, 170);
    v24 = (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(v23 - COERCE_FLOAT(_mm_shuffle_ps(v18, v18, 170))) & _xmm) * 0.5) > CharacterRigidBody::mMaxCurbHeight;
    if ( v6 > 0 )
    {
      v25 = 0i64;
      do
      {
        v26 = (__m128 *)((__int64 (__fastcall *)(hkpSimpleConstraintContactMgr *, _QWORD))v7->vfptr[5].__first_virtual_table_function__)(
                          v7,
                          v5->m_data[v25]);
        if ( v26 )
        {
          v28 = _mm_sub_ps(v18, v15);
          v29 = _mm_mul_ps(_mm_sub_ps(*v26, v15), v28);
          v30 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 0)))
              + COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 170));
          if ( v30 > 0.0 )
          {
            v32 = _mm_mul_ps(v28, v28);
            v33 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v32, v32, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v32, v32, 0)))
                + COERCE_FLOAT(_mm_shuffle_ps(v32, v32, 170));
            if ( v30 <= v33 )
            {
              v31 = v30 / v33;
              if ( v31 < 0.0 || v31 > 1.0 )
                goto LABEL_36;
            }
            else
            {
              v31 = *(float *)&FLOAT_1_0;
            }
          }
          else
          {
            v31 = 0.0;
          }
          v27.m128_f32[0] = v31;
          v34 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v27, v27, 0), v28), v15);
          if ( v8->m_fixCurbContacts
            && (float)(COERCE_FLOAT(_mm_shuffle_ps(v34, v34, 170)) - v23) <= CharacterRigidBody::mMaxCurbHeight )
          {
            if ( !v24 )
              goto LABEL_36;
            if ( CharacterRigidBody::mMaxCurbHeight <= 0.0 )
              goto LABEL_36;
            v35 = v26[1];
            if ( COERCE_FLOAT(*(unsigned __int128 *)&_mm_shuffle_ps(v35, v35, 170) & _xmm) >= 0.89999998 )
              goto LABEL_36;
            v36 = _mm_mul_ps(_mm_add_ps(_xmm, v35), (__m128)xmmword_141A711B0);
            v37 = _mm_mul_ps(v36, v36);
            v38 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v37, v37, 85), _mm_shuffle_ps(v37, v37, 0)),
                    _mm_shuffle_ps(v37, v37, 170));
            v39 = _mm_rsqrt_ps(v38);
            v40 = _mm_cmpltps(_mm_sub_ps((__m128)0i64, v38), (__m128)0i64);
            v41 = _mm_or_ps(
                    _mm_and_ps(
                      _mm_mul_ps(
                        _mm_andnot_ps(
                          _mm_cmpleps(v38, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v39, v38), v39)),
                            _mm_mul_ps(*(__m128 *)_xmm, v39))),
                        v36),
                      v40),
                    _mm_andnot_ps(v40, v36));
            if ( !_mm_movemask_ps(v40) )
              goto LABEL_36;
            v42 = _mm_unpackhi_ps(v41, v35);
          }
          else
          {
            if ( !v22 )
              goto LABEL_36;
            v43 = _mm_sub_ps(v34, *v26);
            v44 = _mm_mul_ps(v43, v43);
            v45 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v44, v44, 85), _mm_shuffle_ps(v44, v44, 0)),
                    _mm_shuffle_ps(v44, v44, 170));
            v46 = _mm_rsqrt_ps(v45);
            v47 = _mm_cmpltps(_mm_sub_ps((__m128)0i64, v45), (__m128)0i64);
            v41 = _mm_or_ps(
                    _mm_and_ps(
                      _mm_mul_ps(
                        _mm_andnot_ps(
                          _mm_cmpleps(v45, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v46, v45), v46)),
                            _mm_mul_ps(*(__m128 *)_xmm, v46))),
                        v43),
                      v47),
                    _mm_andnot_ps(v47, v43));
            if ( !_mm_movemask_ps(v47) )
              goto LABEL_36;
            v42 = _mm_unpackhi_ps(v41, v26[1]);
          }
          v26[1] = _mm_shuffle_ps(v41, v42, 196);
        }
LABEL_36:
        ++v11;
        ++v25;
      }
      while ( v11 < v5->m_size );
    }
  }
}

// File Line: 1364
// RVA: 0x488DA0
void __fastcall CharacterRigidBody::unweldContactPointsForNonPlayer(CharacterRigidBody *this, hkpLinkedCollidable::CollisionEntry *entry, hkpSimpleConstraintContactMgr *mgr, hkArray<unsigned short,hkContainerHeapAllocator> *contactPointIds, float normalFactor)
{
  hkVector4f v5; // xmm1
  __m128 *v6; // rax
  hkpSimpleConstraintContactMgr *v7; // r14
  int v8; // ebx
  hkArray<unsigned short,hkContainerHeapAllocator> *v9; // rsi
  CharacterRigidBody *v10; // rbp
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
  __m128 v42; // ST30_16

  v5.m_quad = (__m128)this->mBottomVertex;
  v6 = &this->m_character->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad;
  v7 = mgr;
  v8 = 0;
  v9 = contactPointIds;
  v10 = this;
  v11.m_quad = (__m128)this->m_character->m_motion.m_motionState.m_transform.m_translation;
  v12 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v5.m_quad, v5.m_quad, 0), *v6),
            _mm_mul_ps(
              _mm_shuffle_ps(this->mBottomVertex.m_quad, v5.m_quad, 85),
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
              _mm_mul_ps(_mm_shuffle_ps(v13.m_quad, v13.m_quad, 0), *v6),
              _mm_mul_ps(
                _mm_shuffle_ps(this->mTopVertex.m_quad, v13.m_quad, 85),
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
      v23 = (__m128 *)((__int64 (__fastcall *)(hkpSimpleConstraintContactMgr *, _QWORD))v7->vfptr[5].__first_virtual_table_function__)(
                        v7,
                        v9->m_data[v22]);
      if ( v23 )
      {
        v25 = _mm_sub_ps(v17, v14);
        v26 = _mm_mul_ps(_mm_sub_ps(*v23, v14), v25);
        v27 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v26, v26, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v26, v26, 0)))
            + COERCE_FLOAT(_mm_shuffle_ps(v26, v26, 170));
        if ( v27 <= 0.0 )
        {
          v28 = 0.0;
          goto LABEL_24;
        }
        v29 = _mm_mul_ps(v25, v25);
        v30 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 0)))
            + COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 170));
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
            v38 = _mm_cmpltps(_mm_sub_ps((__m128)0i64, v36), (__m128)0i64);
            v39 = _mm_or_ps(
                    _mm_and_ps(
                      _mm_mul_ps(
                        _mm_andnot_ps(
                          _mm_cmpleps(v36, (__m128)0i64),
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
              if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v41, v41, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v41, v41, 0)))
                         + COERCE_FLOAT(_mm_shuffle_ps(v41, v41, 170))) < 0.98000002 )
              {
                v23[1] = _mm_shuffle_ps(v39, _mm_unpackhi_ps(v39, v40), 196);
                v31 = CharacterRigidBody::mMaxCurbHeight;
              }
            }
          }
          if ( (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(v10->mBottomVertex.m_quad.m128_f32[2] - v10->mTopVertex.m_quad.m128_f32[2]) & _xmm)
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
    while ( v8 < v9->m_size );
  }
}

// File Line: 1468
// RVA: 0x4865E0
void __fastcall CharacterRigidBody::considerCollisionEntryForSlope(CharacterRigidBody *this, hkpWorld *world, hkpLinkedCollidable::CollisionEntry *entry, hkpSimpleConstraintContactMgr *mgr, hkArray<unsigned short,hkContainerHeapAllocator> *contactPointIds)
{
  hkpSimpleConstraintContactMgr *v5; // r15
  CharacterRigidBody *v6; // rsi
  hkpLinkedCollidable *v7; // r14
  hkpLinkedCollidable *v8; // r12
  hkpRigidBody *v9; // rax
  float v10; // xmm10_4
  hkArray<unsigned short,hkContainerHeapAllocator> *v11; // rdi
  __int64 v12; // rbp
  __int64 v13; // r13
  __m128 *v14; // rbx
  __m128 v15; // xmm8
  __m128 v16; // xmm9
  __m128 v17; // xmm6
  float v18; // xmm6_4
  float v19; // xmm7_4
  hkpRigidBody *v20; // rax
  hkpCollidable *v21; // rcx
  hkpRigidBody *v22; // rax
  _BYTE *v23; // rcx
  __m128 v24; // xmm0
  __int128 v25; // ST40_16
  __m128 v26; // xmm8
  __m128 v27; // xmm4
  __m128 v28; // xmm4
  __m128 v29; // xmm1
  __int64 v30; // rcx
  unsigned __int16 v31; // r12
  hkArray<CharacterRigidBody::VertPointInfo,hkContainerHeapAllocator> *v32; // rbx
  __int64 v33; // rax
  signed __int64 v34; // rcx
  __int128 v35; // [rsp+50h] [rbp-3188h]
  __m128 v36; // [rsp+60h] [rbp-3178h]
  hkpSimpleConstraintContactMgr *v37; // [rsp+70h] [rbp-3168h]
  __int64 v38; // [rsp+80h] [rbp-3158h]
  char v39; // [rsp+90h] [rbp-3148h]
  __int64 v40; // [rsp+98h] [rbp-3140h]
  int v41; // [rsp+30C0h] [rbp-118h]
  __int64 v42; // [rsp+30E0h] [rbp-F8h]
  hkpLinkedCollidable *v43; // [rsp+31E0h] [rbp+8h]
  hkpWorld *v44; // [rsp+31E8h] [rbp+10h]
  signed __int64 v45; // [rsp+31F0h] [rbp+18h]
  CharacterRigidBody::VertPointInfo *array; // [rsp+3200h] [rbp+28h]

  v44 = world;
  v38 = -2i64;
  v5 = mgr;
  v6 = this;
  v7 = entry->m_agentEntry->m_collidable[0];
  v8 = entry->m_agentEntry->m_collidable[1];
  v43 = entry->m_agentEntry->m_collidable[1];
  if ( v7->m_broadPhaseHandle.m_type == 1 )
    v9 = (hkpRigidBody *)((char *)v7 + v7->m_ownerOffset);
  else
    v9 = 0i64;
  if ( v9 == this->m_character )
    v10 = *(float *)&FLOAT_1_0;
  else
    v10 = FLOAT_N1_0;
  v11 = contactPointIds;
  v12 = 0i64;
  v13 = contactPointIds->m_size;
  if ( v13 > 0 )
  {
    do
    {
      v14 = (__m128 *)((__int64 (__fastcall *)(hkpSimpleConstraintContactMgr *, _QWORD))v5->vfptr[5].__first_virtual_table_function__)(
                        v5,
                        v11->m_data[v12]);
      v15 = v14[1];
      v16 = v6->m_up.m_quad;
      v17 = _mm_mul_ps(v6->m_up.m_quad, v15);
      v18 = COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 170))
          + (float)(COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 0)));
      v19 = v18 * v10;
      if ( v6->m_isInWater )
      {
        v20 = hkpGetRigidBody((hkpCollidable *)&v7->m_shape);
        v21 = (hkpCollidable *)&v8->m_shape;
        if ( v20 != v6->m_character )
          v21 = (hkpCollidable *)&v7->m_shape;
        v22 = hkpGetRigidBody(v21);
        if ( v22 )
        {
          v23 = (_BYTE *)v22->m_userData;
          if ( v23 )
          {
            if ( *v23 )
              goto LABEL_28;
          }
        }
      }
      if ( v19 > 0.0099999998 && v19 < v6->m_maxSlopeCosine )
      {
LABEL_28:
        v37 = v5;
        v24 = *v14;
        v25 = (__int128)*v14;
        HIDWORD(v25) = 1066267815;
        v35 = v25;
        v24.m128_f32[0] = COERCE_FLOAT(LODWORD(v18) ^ _xmm[0]);
        v26 = _mm_add_ps(v15, _mm_mul_ps(_mm_shuffle_ps(v24, v24, 0), v16));
        v27 = _mm_mul_ps(v26, v26);
        v28 = _mm_add_ps(
                _mm_shuffle_ps(v27, v27, 170),
                _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)));
        v29 = _mm_rsqrt_ps(v28);
        v36 = _mm_mul_ps(
                _mm_andnot_ps(
                  _mm_cmpleps(v28, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v29, v28), v29)),
                    _mm_mul_ps(*(__m128 *)_xmm, v29))),
                v26);
        v36.m128_i32[3] = 0;
        v30 = (__int64)v6->m_character->m_simulationIsland;
        v41 = 2139095022;
        v42 = 0i64;
        v40 = v30;
        v31 = ((__int64 (__fastcall *)(hkpSimpleConstraintContactMgr *, hkpLinkedCollidable *, hkpLinkedCollidable *, hkpProcessCollisionInput *, char *, _QWORD, __int128 *))v5->vfptr[1].__first_virtual_table_function__)(
                v5,
                v7,
                v8,
                v44->m_collisionInput,
                &v39,
                0i64,
                &v35);
        if ( v31 != -1 )
        {
          v32 = &v6->m_verticalContactPoints;
          if ( v6->m_verticalContactPoints.m_size == (v6->m_verticalContactPoints.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              &v6->m_verticalContactPoints,
              48);
          v33 = v6->m_verticalContactPoints.m_size;
          v34 = (signed __int64)&v32->m_data[v33];
          array = &v32->m_data[v33];
          v45 = (signed __int64)&v32->m_data[v33];
          if ( v34 )
          {
            *(_OWORD *)v34 = v35;
            *(__m128 *)(v34 + 16) = v36;
            *(_QWORD *)(v34 + 32) = v37;
          }
          ++v6->m_verticalContactPoints.m_size;
          if ( v11->m_size == (v11->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v11, 2);
          v11->m_data[v11->m_size++] = v31;
        }
        v8 = v43;
      }
      ++v12;
    }
    while ( v12 < v13 );
  }
}

// File Line: 1549
// RVA: 0x486320
void __fastcall CharacterRigidBody::considerCollisionEntryForMassModification(CharacterRigidBody *this, hkpWorld *world, hkpLinkedCollidable::CollisionEntry *entry, hkpSimpleConstraintContactMgr *mgr, hkArray<unsigned short,hkContainerHeapAllocator> *contactPointIds)
{
  CharacterRigidBody *v5; // rsi
  __int64 v6; // rbx
  hkpLinkedCollidable *v7; // rcx
  hkpLinkedCollidable *v8; // r8
  hkpSimpleConstraintContactMgr *v9; // rdi
  char v10; // dl
  hkpRigidBody *v11; // rax
  hkpRigidBody *v12; // r10
  __m128 v13; // xmm7
  hkpRigidBody *v14; // rdx
  char v15; // cl
  int v16; // eax
  char v17; // r12
  char v18; // r15
  __m128 v19; // xmm6
  __int64 v20; // rbp
  __m128 *v21; // rax
  __m128 v22; // xmm6
  __m128 v23; // xmm2
  float v24; // xmm5_4
  float v25; // xmm3_4
  __m128 v26; // xmm6
  float v27; // xmm5_4
  __m128 v28; // xmm1
  __m128 v29; // xmm4
  __m128 v30; // xmm1
  float v31; // xmm0_4
  hkVector4f *v32; // r9
  hkpConstraintOwner *v33; // r8
  __int128 v34; // [rsp+20h] [rbp-68h]

  v5 = this;
  v6 = 0i64;
  v7 = entry->m_agentEntry->m_collidable[0];
  v8 = entry->m_agentEntry->m_collidable[1];
  v9 = mgr;
  v10 = v7->m_broadPhaseHandle.m_type;
  if ( v10 == 1 )
    v11 = (hkpRigidBody *)((char *)v7 + v7->m_ownerOffset);
  else
    v11 = 0i64;
  v12 = v5->m_character;
  if ( v11 == v12 )
  {
    if ( v8->m_broadPhaseHandle.m_type == 1 )
    {
      v13 = *(__m128 *)_xmm_bf800000bf800000bf800000bf800000;
      v14 = (hkpRigidBody *)((char *)v8 + v8->m_ownerOffset);
    }
    else
    {
      v13 = *(__m128 *)_xmm_bf800000bf800000bf800000bf800000;
      v14 = 0i64;
    }
  }
  else
  {
    if ( v10 == 1 )
      v14 = (hkpRigidBody *)((char *)v7 + v7->m_ownerOffset);
    else
      v14 = 0i64;
    v13 = *(__m128 *)_xmm;
  }
  v15 = v14->m_motion.m_type.m_storage;
  if ( (v15 - 4) & 0xFC || v15 == 6 )
  {
    if ( v5->m_maxForce <= 0.0 )
    {
      v33 = (hkpConstraintOwner *)&v12->m_simulationIsland->vfptr;
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
      v20 = contactPointIds->m_size;
      if ( v20 > 0 )
      {
        do
        {
          v21 = (__m128 *)((__int64 (__fastcall *)(hkpSimpleConstraintContactMgr *, _QWORD))v9->vfptr[5].__first_virtual_table_function__)(
                            v9,
                            contactPointIds->m_data[v6++]);
          v19 = _mm_add_ps(v19, v21[1]);
        }
        while ( v6 < v20 );
      }
      v22 = _mm_mul_ps(v19, v13);
      v23 = _mm_mul_ps(v22, v22);
      v24 = hkpMotion::getMass((hkpMotion *)&v5->m_character->m_motion.vfptr);
      v25 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v23, v23, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v23, v23, 0)))
          + COERCE_FLOAT(_mm_shuffle_ps(v23, v23, 170));
      if ( v25 <= 0.0 )
      {
        v28 = _mm_mul_ps(v5->m_acceleration.m_quad, v5->m_acceleration.m_quad);
        v29 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(v28, v28, 0)),
                _mm_shuffle_ps(v28, v28, 170));
        v30 = _mm_rsqrt_ps(v29);
        v27 = v24
            * COERCE_FLOAT(
                _mm_andnot_ps(
                  _mm_cmpleps(v29, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v30, v29), v30)),
                      _mm_mul_ps(*(__m128 *)_xmm, v30)),
                    v29)));
      }
      else
      {
        v26 = _mm_mul_ps(v22, v5->m_acceleration.m_quad);
        v27 = (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v26, v26, 85))
                                    + COERCE_FLOAT(_mm_shuffle_ps(v26, v26, 0)))
                            + COERCE_FLOAT(_mm_shuffle_ps(v26, v26, 170)))
                    * v24)
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
        v31 = v5->m_maxForce;
        if ( v27 > v31 )
          *((float *)&v34 + 3) = v27 / v31;
      }
      if ( v5->m_superMassive )
        *((float *)&v34 + 3) = FLOAT_0_0099999998;
      v14 = v5->m_character;
      v32 = (hkVector4f *)&v34;
      v33 = (hkpConstraintOwner *)&v14->m_simulationIsland->vfptr;
    }
    hkpResponseModifier::setInvMassScalingForContact((hkpDynamicsContactMgr *)&v9->vfptr, v14, v33, v32);
  }
}

// File Line: 1674
// RVA: 0x487420
void __fastcall CharacterRigidBody::discardVerticalPoints(CharacterRigidBody *this)
{
  CharacterRigidBody *v1; // r13
  hkArray<hkpLinkedCollidable::CollisionEntry,hkContainerHeapAllocator> *v2; // rax
  __int64 v3; // rdi
  __int64 v4; // rbx
  hkpSimpleConstraintContactMgr *v5; // r14
  int v6; // eax
  signed __int64 v7; // r12
  int v8; // ecx
  CharacterRigidBody::VertPointInfo *v9; // rbp
  int v10; // edi
  __int64 v11; // rbx
  __int64 v12; // rsi
  unsigned __int16 v13; // r15
  __m128 *v14; // rax
  __int64 v15; // rax
  CharacterRigidBody::VertPointInfo *v16; // rcx
  signed __int64 v17; // rdx
  __m128 *v18; // rax
  signed __int64 v19; // rdx
  signed __int64 v20; // r8
  hkArray<hkpLinkedCollidable::CollisionEntry,hkContainerHeapAllocator> *v21; // [rsp+20h] [rbp-78h]
  _WORD *v22; // [rsp+30h] [rbp-68h]
  int v23; // [rsp+38h] [rbp-60h]
  int v24; // [rsp+3Ch] [rbp-5Ch]
  __m128 v25; // [rsp+40h] [rbp-58h]
  int v26; // [rsp+A0h] [rbp+8h]
  __int64 v27; // [rsp+A8h] [rbp+10h]
  __int64 v28; // [rsp+B0h] [rbp+18h]
  __int64 v29; // [rsp+B8h] [rbp+20h]

  v1 = this;
  if ( this->m_verticalContactPoints.m_size )
  {
    v2 = &this->m_character->m_collidable.m_collisionEntries;
    v21 = &this->m_character->m_collidable.m_collisionEntries;
    v3 = this->m_character->m_collidable.m_collisionEntries.m_size;
    v29 = v3;
    if ( v3 > 0 )
    {
      v4 = 0i64;
      v28 = 0i64;
      do
      {
        v5 = (hkpSimpleConstraintContactMgr *)(*(hkpAgentNnEntry **)((char *)&v2->m_data->m_agentEntry + v4))->m_contactMgr;
        if ( v5->m_type == TYPE_SIMPLE_CONSTRAINT_CONTACT_MGR )
        {
          v22 = 0i64;
          v23 = 0;
          v24 = 2147483648;
          v5->vfptr[6].__vecDelDtor((hkBaseObject *)&v5->vfptr, (unsigned int)&v22);
          v6 = v1->m_verticalContactPoints.m_size - 1;
          v26 = v6;
          v27 = v6;
          if ( v6 >= 0 )
          {
            v7 = v6;
            v8 = v23;
            do
            {
              v9 = v1->m_verticalContactPoints.m_data;
              if ( v9[v7].m_mgr == v5 )
              {
                v10 = 0;
                v11 = 0i64;
                v12 = v8;
                if ( v8 > 0 )
                {
                  while ( 1 )
                  {
                    v13 = v22[v11];
                    v14 = (__m128 *)((__int64 (__fastcall *)(hkpSimpleConstraintContactMgr *, _QWORD))v5->vfptr[5].__first_virtual_table_function__)(
                                      v5,
                                      v13);
                    if ( _mm_movemask_ps(
                           _mm_and_ps(
                             _mm_cmpeqps(*v14, v9[v7].m_vertPoint.m_position.m_quad),
                             _mm_cmpeqps(v14[1], v9[v7].m_vertPoint.m_separatingNormal.m_quad))) == 15 )
                      break;
                    ++v10;
                    if ( ++v11 >= v12 )
                      goto LABEL_17;
                  }
                  v25 = *v14;
                  v25.m128_i32[3] = 1073359795;
                  *v14 = v25;
                  ((void (__fastcall *)(hkpSimpleConstraintContactMgr *, _QWORD, hkpSimulationIsland *))v5->vfptr[2].__first_virtual_table_function__)(
                    v5,
                    v13,
                    v1->m_character->m_simulationIsland);
                  v15 = --v1->m_verticalContactPoints.m_size;
                  if ( (_DWORD)v15 != v26 )
                  {
                    v16 = v1->m_verticalContactPoints.m_data;
                    v17 = (signed __int64)&v16[v15];
                    v18 = &v16[v7].m_vertPoint.m_position.m_quad;
                    v19 = v17 - (_QWORD)&v16[v7];
                    v20 = 6i64;
                    do
                    {
                      v18->m128_u64[0] = *(unsigned __int64 *)((char *)v18->m128_u64 + v19);
                      v18 = (__m128 *)((char *)v18 + 8);
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
                    goto LABEL_18;
                  }
                }
              }
LABEL_18:
              --v26;
              --v27;
              --v7;
            }
            while ( v27 >= 0 );
            v4 = v28;
            v3 = v29;
          }
          v23 = 0;
          if ( v24 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              v22,
              2 * (v24 & 0x3FFFFFFF));
          v22 = 0i64;
          v24 = 2147483648;
        }
        v4 += 16i64;
        v28 = v4;
        v29 = --v3;
        v2 = v21;
      }
      while ( v3 );
    }
    v1->m_verticalContactPoints.m_size = 0;
  }
}

