// File Line: 20
// RVA: 0x15CC8B0
void dynamic_initializer_for__hkOptionalComponent_hkpHeightFieldAgent__()
{
  hkOptionalComponent::hkOptionalComponent(
    &hkOptionalComponent_hkpHeightFieldAgent,
    "hkpHeightFieldAgent",
    (void **)&hkpCollisionAgent::registerHeightFieldAgent,
    hkpHeightFieldAgent::registerAgent);
}

// File Line: 24
// RVA: 0xCFB6C0
void __fastcall hkpHeightFieldAgent::hkpHeightFieldAgent(
        hkpHeightFieldAgent *this,
        hkpCdBody *A,
        hkpCdBody *B,
        hkpCollisionInput *input,
        hkpContactMgr *mgr)
{
  hkpContactMgr *v5; // rax
  int v7; // eax
  int v8; // ecx
  int v9; // ebp
  int v10; // ecx
  int v11; // r9d
  int v12; // edx
  unsigned __int16 *v13; // rdi
  __int64 v14; // rcx

  v5 = mgr;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_contactMgr = v5;
  this->vfptr = (hkBaseObjectVtbl *)&hkpHeightFieldAgent::`vftable;
  this->m_contactPointId.m_capacityAndFlags = 0x80000000;
  this->m_contactPointId.m_data = 0i64;
  this->m_contactPointId.m_size = 0;
  if ( v5 )
  {
    v7 = ((__int64 (__fastcall *)(hkpShape *, hkpCdBody *, hkpCdBody *, hkpCollisionInput *))A->m_shape->vfptr[5].__first_virtual_table_function__)(
           A->m_shape,
           A,
           B,
           input);
    v8 = this->m_contactPointId.m_capacityAndFlags & 0x3FFFFFFF;
    v9 = v7;
    if ( v8 < v7 )
    {
      v10 = 2 * v8;
      v11 = v7;
      if ( v7 < v10 )
        v11 = v10;
      hkArrayUtil::_reserve(
        (hkResult *)&mgr,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&this->m_contactPointId.m_data,
        v11,
        2);
    }
    v12 = v9 - this->m_contactPointId.m_size;
    v13 = &this->m_contactPointId.m_data[this->m_contactPointId.m_size];
    v14 = v12;
    if ( v12 > 0 )
    {
      while ( v14 )
      {
        *v13++ = -1;
        --v14;
      }
    }
    this->m_contactPointId.m_size = v9;
  }
}

// File Line: 37
// RVA: 0xCFA930
void __fastcall hkpHeightFieldAgent::registerAgent(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h] BYREF

  f.m_createFunc = hkpHeightFieldAgent::createHeightFieldAAgent;
  f.m_getPenetrationsFunc = hkpSymmetricAgentLinearCast<hkpHeightFieldAgent>::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpSymmetricAgentLinearCast<hkpHeightFieldAgent>::staticGetClosestPoints;
  hkOptionalComponent_hkpHeightFieldAgent.m_isUsed.m_bool = 1;
  f.m_linearCastFunc = hkpSymmetricAgentLinearCast<hkpHeightFieldAgent>::staticLinearCast;
  *(_WORD *)&f.m_isFlipped.m_bool = 257;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, HEIGHT_FIELD, SPHERE_REP);
  f.m_createFunc = hkpHeightFieldAgent::createHeightFieldBAgent;
  f.m_getPenetrationsFunc = hkpHeightFieldAgent::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpHeightFieldAgent::staticGetClosestPoints;
  *(_WORD *)&f.m_isFlipped.m_bool = 256;
  f.m_linearCastFunc = hkpHeightFieldAgent::staticLinearCast;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, SPHERE_REP, HEIGHT_FIELD);
}

// File Line: 66
// RVA: 0xCFB830
void __fastcall hkpHeightFieldAgent::createHeightFieldBAgent(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *mgr)
{
  _QWORD **Value; // rax
  hkpHeightFieldAgent *v9; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkpHeightFieldAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 40i64);
  if ( v9 )
    hkpHeightFieldAgent::hkpHeightFieldAgent(v9, bodyA, bodyB, input, mgr);
}

// File Line: 74
// RVA: 0xCFB7A0
hkpHeightFieldAgent *__fastcall hkpHeightFieldAgent::createHeightFieldAAgent(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *mgr)
{
  _QWORD **Value; // rax
  hkpHeightFieldAgent *result; // rax
  hkpHeightFieldAgent *v10; // rbx

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkpHeightFieldAgent *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 40i64);
  v10 = result;
  if ( result )
  {
    hkpHeightFieldAgent::hkpHeightFieldAgent(result, bodyB, bodyA, input, mgr);
    v10->vfptr = (hkBaseObjectVtbl *)&hkpSymmetricAgent<hkpHeightFieldAgent>::`vftable;
    return v10;
  }
  return result;
}

// File Line: 81
// RVA: 0xCFB620
void __fastcall hkpHeightFieldAgent::cleanup(hkpHeightFieldAgent *this, hkpConstraintOwner *constraintOwner)
{
  int v4; // edi
  __int64 v5; // rsi
  __int64 v6; // rdx

  if ( this->m_contactMgr )
  {
    v4 = 0;
    if ( this->m_contactPointId.m_size > 0 )
    {
      v5 = 0i64;
      do
      {
        v6 = this->m_contactPointId.m_data[v5];
        if ( (_WORD)v6 != 0xFFFF )
          ((void (__fastcall *)(hkpContactMgr *, __int64, hkpConstraintOwner *))this->m_contactMgr->hkpCollisionAgent::vfptr[2].__first_virtual_table_function__)(
            this->m_contactMgr,
            v6,
            constraintOwner);
        ++v4;
        ++v5;
      }
      while ( v4 < this->m_contactPointId.m_size );
    }
  }
  this->vfptr->__vecDelDtor(this, 1i64);
}

// File Line: 98
// RVA: 0xCFBCC0
void __fastcall hkpHeightFieldAgent::processCollision(
        hkpHeightFieldAgent *this,
        hkpCdBody *csBody,
        hkpCdBody *hfBody,
        hkpProcessCollisionInput *input,
        hkpProcessCollisionOutput *processOutput)
{
  hkpHeightFieldAgent *v5; // r13
  _QWORD *Value; // rax
  _QWORD *v10; // rcx
  _QWORD *v11; // r8
  unsigned __int64 v12; // rax
  _QWORD *v13; // rcx
  hkpShape *m_shape; // r15
  int m_size; // ebx
  hkLifoAllocator *v16; // rax
  char *m_cur; // r14
  int v18; // esi
  char *v19; // rcx
  unsigned __int16 *m_data; // rdi
  __int64 v21; // rax
  int v22; // r12d
  hkVector4f v23; // xmm4
  hkVector4f v24; // xmm5
  hkVector4f v25; // xmm6
  __int64 v26; // rdx
  __m128 *v27; // rcx
  hkVector4f v28; // xmm7
  __m128 v29; // xmm2
  __m128 v30; // xmm3
  hkLifoAllocator *v31; // rax
  char *v32; // r15
  char *v33; // rcx
  hkBaseObjectVtbl *vfptr; // r9
  __m128 *v35; // rbp
  float v36; // xmm6_4
  signed __int64 v37; // rax
  __m128 v38; // xmm3
  __int64 v39; // rdx
  hkpProcessCdPoint *v40; // r13
  __m128 v41; // xmm2
  __m128 v42; // xmm3
  unsigned __int16 v43; // ax
  hkLifoAllocator *v44; // rax
  int v45; // ebx
  hkLifoAllocator *v46; // rax
  _QWORD *v47; // r8
  _QWORD *v48; // rcx
  unsigned __int64 v49; // rax
  _QWORD *v50; // rcx
  hkpShape *v51; // [rsp+40h] [rbp-D8h]
  char *v52; // [rsp+50h] [rbp-C8h]
  char *v53; // [rsp+58h] [rbp-C0h]
  char *v54; // [rsp+60h] [rbp-B8h] BYREF
  int v55; // [rsp+68h] [rbp-B0h]
  float m_storage; // [rsp+6Ch] [rbp-ACh]
  hkTransformf v57; // [rsp+70h] [rbp-A8h] BYREF

  v5 = this;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)Value[1];
  v11 = Value;
  if ( (unsigned __int64)v10 < Value[3] )
  {
    *v10 = "TtHeightField";
    v12 = __rdtsc();
    v13 = v10 + 2;
    *((_DWORD *)v13 - 2) = v12;
    v11[1] = v13;
  }
  m_shape = csBody->m_shape;
  v51 = hfBody->m_shape;
  hkTransformf::setMulInverseMul(&v57, (hkTransformf *)hfBody->m_motion, (hkTransformf *)csBody->m_motion);
  m_size = v5->m_contactPointId.m_size;
  v16 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (char *)v16->m_cur;
  v52 = m_cur;
  v18 = (16 * m_size + 127) & 0xFFFFFF80;
  v19 = &m_cur[v18];
  if ( v18 > v16->m_slabSize || v19 > v16->m_end )
  {
    m_cur = (char *)hkLifoAllocator::allocateFromNewSlab(v16, v18);
    v52 = m_cur;
  }
  else
  {
    v16->m_cur = v19;
  }
  m_data = v5->m_contactPointId.m_data;
  v21 = (__int64)m_shape->vfptr[6].__vecDelDtor(m_shape, (unsigned int)m_cur);
  v22 = m_size - 1;
  v23.m_quad = (__m128)v57.m_rotation.m_col0;
  v24.m_quad = (__m128)v57.m_rotation.m_col1;
  v25.m_quad = (__m128)v57.m_rotation.m_col2;
  v26 = m_size - 1;
  v27 = (__m128 *)(v21 + 16 * v26);
  v28.m_quad = (__m128)v57.m_translation;
  do
  {
    v29 = *v27--;
    --v26;
    v30 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v29, v29, 85), v24.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v29, v29, 0), v23.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v29, v29, 170), v25.m_quad)),
            v28.m_quad);
    *(__m128 *)&m_cur[(_QWORD)v27 - v21 + 16] = _mm_shuffle_ps(v30, _mm_unpackhi_ps(v30, v29), 196);
  }
  while ( v26 >= 0 );
  v31 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v32 = (char *)v31->m_cur;
  v33 = &v32[v18];
  v53 = v32;
  if ( v18 > v31->m_slabSize || v33 > v31->m_end )
  {
    v32 = (char *)hkLifoAllocator::allocateFromNewSlab(v31, v18);
    v53 = v32;
  }
  else
  {
    v31->m_cur = v33;
  }
  vfptr = v51->vfptr;
  m_storage = input->m_tolerance.m_storage;
  v54 = m_cur;
  v55 = m_size;
  ((void (__fastcall *)(hkpShape *, char **, char *))vfptr[8].__first_virtual_table_function__)(v51, &v54, v32);
  v35 = (__m128 *)v32;
  LODWORD(v36) = _mm_shuffle_ps(
                   (__m128)LODWORD(input->m_tolerance.m_storage),
                   (__m128)LODWORD(input->m_tolerance.m_storage),
                   0).m128_u32[0];
  if ( v22 >= 0 )
  {
    v37 = m_cur - v32;
    while ( 1 )
    {
      v38 = *v35;
      if ( _mm_shuffle_ps(v38, v38, 255).m128_f32[0] <= v36 )
        break;
      v39 = *m_data;
      if ( (_WORD)v39 != 0xFFFF )
      {
        ((void (__fastcall *)(hkpContactMgr *, __int64, hkpConstraintOwner *))v5->m_contactMgr->hkpCollisionAgent::vfptr[2].__first_virtual_table_function__)(
          v5->m_contactMgr,
          v39,
          processOutput->m_constraintOwner.m_storage);
        *m_data = -1;
LABEL_22:
        v37 = m_cur - v32;
      }
      ++v35;
      ++m_data;
      if ( --v22 < 0 )
      {
        v18 = (16 * m_size + 127) & 0xFFFFFF80;
        m_cur = v52;
        v32 = v53;
        goto LABEL_25;
      }
    }
    v40 = processOutput->m_firstFreeContactPoint.m_storage;
    v41 = _mm_add_ps(
            _mm_mul_ps(
              _mm_sub_ps(
                (__m128)0i64,
                _mm_shuffle_ps(*(__m128 *)((char *)v35 + v37), *(__m128 *)((char *)v35 + v37), 255)),
              v38),
            *(__m128 *)((char *)v35 + v37));
    v40->m_contact.m_position.m_quad = _mm_add_ps(
                                         _mm_add_ps(
                                           _mm_add_ps(
                                             _mm_mul_ps(_mm_shuffle_ps(v41, v41, 85), *((__m128 *)hfBody->m_motion + 1)),
                                             _mm_mul_ps(_mm_shuffle_ps(v41, v41, 0), *(__m128 *)hfBody->m_motion)),
                                           _mm_mul_ps(_mm_shuffle_ps(v41, v41, 170), *((__m128 *)hfBody->m_motion + 2))),
                                         *((__m128 *)hfBody->m_motion + 3));
    v42 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(*v35, *v35, 85), *((__m128 *)hfBody->m_motion + 1)),
              _mm_mul_ps(_mm_shuffle_ps(*v35, *v35, 0), *(__m128 *)hfBody->m_motion)),
            _mm_mul_ps(_mm_shuffle_ps(*v35, *v35, 170), *((__m128 *)hfBody->m_motion + 2)));
    v40->m_contact.m_separatingNormal.m_quad = _mm_shuffle_ps(
                                                 v42,
                                                 _mm_unpackhi_ps(v42, _mm_shuffle_ps(*v35, *v35, 255)),
                                                 196);
    if ( *m_data != 0xFFFF
      || (v43 = ((__int64 (__fastcall *)(hkpContactMgr *, hkpCdBody *, hkpCdBody *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *, _QWORD, hkpProcessCdPoint *))this->m_contactMgr->hkpCollisionAgent::vfptr[1].__first_virtual_table_function__)(
                  this->m_contactMgr,
                  csBody,
                  hfBody,
                  input,
                  processOutput,
                  0i64,
                  v40),
          *m_data = v43,
          v43 != 0xFFFF) )
    {
      ++processOutput->m_firstFreeContactPoint.m_storage;
    }
    v40->m_contactPointId = *m_data;
    v5 = this;
    goto LABEL_22;
  }
LABEL_25:
  v44 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v45 = (v18 + 15) & 0xFFFFFFF0;
  if ( v18 > v44->m_slabSize || &v32[v45] != v44->m_cur || v44->m_firstNonLifoEnd == v32 )
    hkLifoAllocator::slowBlockFree(v44, v32, v45);
  else
    v44->m_cur = v32;
  v46 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( v18 > v46->m_slabSize || &m_cur[v45] != v46->m_cur || v46->m_firstNonLifoEnd == m_cur )
    hkLifoAllocator::slowBlockFree(v46, m_cur, v45);
  else
    v46->m_cur = m_cur;
  v47 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v48 = (_QWORD *)v47[1];
  if ( (unsigned __int64)v48 < v47[3] )
  {
    *v48 = "Et";
    v49 = __rdtsc();
    v50 = v48 + 2;
    *((_DWORD *)v50 - 2) = v49;
    v47[1] = v50;
  }
}

// File Line: 202
// RVA: 0xCFA9F0
void __fastcall hkpHeightFieldAgent::getPenetrations(
        hkpHeightFieldAgent *this,
        hkpCdBody *csBody,
        hkpCdBody *hfBody,
        hkpCollisionInput *input,
        hkpCdBodyPairCollector *collector)
{
  hkpHeightFieldAgent::staticGetPenetrations(csBody, hfBody, input, collector);
}

// File Line: 208
// RVA: 0xCFAA10
void __fastcall hkpHeightFieldAgent::staticGetPenetrations(
        hkpCdBody *csBody,
        hkpCdBody *hfBody,
        hkpCollisionInput *input,
        hkpCdBodyPairCollector *collector)
{
  _QWORD *Value; // r11
  unsigned __int64 v8; // r10
  unsigned __int64 v9; // rax
  hkpShape *m_shape; // rdi
  int v11; // r13d
  hkLifoAllocator *v12; // rax
  char *m_cur; // rbp
  int v14; // ebx
  char *v15; // rcx
  __int64 v16; // rax
  int v17; // edi
  hkVector4f v18; // xmm4
  hkVector4f v19; // xmm5
  hkVector4f v20; // xmm6
  __int64 v21; // rdx
  __m128 *v22; // rcx
  hkVector4f v23; // xmm7
  __m128 v24; // xmm2
  __m128 v25; // xmm3
  _QWORD *v26; // r8
  _QWORD *v27; // rcx
  unsigned __int64 v28; // rax
  _QWORD *v29; // rcx
  hkLifoAllocator *v30; // rax
  char *v31; // rsi
  char *v32; // rcx
  _QWORD *v33; // r8
  _QWORD *v34; // rcx
  unsigned __int64 v35; // rax
  _QWORD *v36; // rcx
  float *v37; // rax
  hkLifoAllocator *v38; // rax
  int v39; // edi
  hkLifoAllocator *v40; // rax
  _QWORD *v41; // r8
  _QWORD *v42; // rcx
  unsigned __int64 v43; // rax
  _QWORD *v44; // rcx
  char *v45; // [rsp+20h] [rbp-A8h] BYREF
  int v46; // [rsp+28h] [rbp-A0h]
  float m_storage; // [rsp+2Ch] [rbp-9Ch]
  hkTransformf v48; // [rsp+30h] [rbp-98h] BYREF
  hkpShape *v49; // [rsp+D0h] [rbp+8h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v8 = Value[1];
  if ( v8 < Value[3] )
  {
    *(_QWORD *)v8 = "LtHeightField";
    *(_QWORD *)(v8 + 16) = "StGetSpheres";
    v9 = __rdtsc();
    *(_DWORD *)(v8 + 8) = v9;
    Value[1] = v8 + 24;
  }
  m_shape = csBody->m_shape;
  v49 = hfBody->m_shape;
  hkTransformf::setMulInverseMul(&v48, (hkTransformf *)hfBody->m_motion, (hkTransformf *)csBody->m_motion);
  v11 = ((__int64 (__fastcall *)(hkpShape *))m_shape->vfptr[5].__first_virtual_table_function__)(m_shape);
  v12 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (char *)v12->m_cur;
  v14 = (16 * v11 + 127) & 0xFFFFFF80;
  v15 = &m_cur[v14];
  if ( v14 > v12->m_slabSize || v15 > v12->m_end )
    m_cur = (char *)hkLifoAllocator::allocateFromNewSlab(v12, v14);
  else
    v12->m_cur = v15;
  v16 = (__int64)m_shape->vfptr[6].__vecDelDtor(m_shape, (unsigned int)m_cur);
  v17 = v11 - 1;
  v18.m_quad = (__m128)v48.m_rotation.m_col0;
  v19.m_quad = (__m128)v48.m_rotation.m_col1;
  v20.m_quad = (__m128)v48.m_rotation.m_col2;
  v21 = v11 - 1;
  v22 = (__m128 *)(v16 + 16 * v21);
  v23.m_quad = (__m128)v48.m_translation;
  do
  {
    v24 = *v22--;
    --v21;
    v25 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v24, v24, 85), v19.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v24, v24, 0), v18.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v24, v24, 170), v20.m_quad)),
            v23.m_quad);
    *(__m128 *)&m_cur[(_QWORD)v22 - v16 + 16] = _mm_shuffle_ps(v25, _mm_unpackhi_ps(v25, v24), 196);
  }
  while ( v21 >= 0 );
  v26 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v27 = (_QWORD *)v26[1];
  if ( (unsigned __int64)v27 < v26[3] )
  {
    *v27 = "StCollide";
    v28 = __rdtsc();
    v29 = v27 + 2;
    *((_DWORD *)v29 - 2) = v28;
    v26[1] = v29;
  }
  v30 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v31 = (char *)v30->m_cur;
  v32 = &v31[v14];
  if ( v14 > v30->m_slabSize || v32 > v30->m_end )
    v31 = (char *)hkLifoAllocator::allocateFromNewSlab(v30, v14);
  else
    v30->m_cur = v32;
  v45 = m_cur;
  v46 = v11;
  m_storage = input->m_tolerance.m_storage;
  ((void (__fastcall *)(hkpShape *, char **, char *))v49->vfptr[8].__first_virtual_table_function__)(v49, &v45, v31);
  v33 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v34 = (_QWORD *)v33[1];
  if ( (unsigned __int64)v34 < v33[3] )
  {
    *v34 = "StExamine";
    v35 = __rdtsc();
    v36 = v34 + 2;
    *((_DWORD *)v36 - 2) = v35;
    v33[1] = v36;
  }
  if ( v17 >= 0 )
  {
    v37 = (float *)(v31 + 12);
    while ( *v37 >= 0.0 )
    {
      v37 += 4;
      if ( --v17 < 0 )
        goto LABEL_23;
    }
    collector->vfptr->addCdBodyPair(collector, csBody, hfBody);
  }
LABEL_23:
  v38 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v39 = (v14 + 15) & 0xFFFFFFF0;
  if ( v14 > v38->m_slabSize || &v31[v39] != v38->m_cur || v38->m_firstNonLifoEnd == v31 )
    hkLifoAllocator::slowBlockFree(v38, v31, v39);
  else
    v38->m_cur = v31;
  v40 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( v14 > v40->m_slabSize || &m_cur[v39] != v40->m_cur || v40->m_firstNonLifoEnd == m_cur )
    hkLifoAllocator::slowBlockFree(v40, m_cur, v39);
  else
    v40->m_cur = m_cur;
  v41 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v42 = (_QWORD *)v41[1];
  if ( (unsigned __int64)v42 < v41[3] )
  {
    *v42 = "lt";
    v43 = __rdtsc();
    v44 = v42 + 2;
    *((_DWORD *)v44 - 2) = v43;
    v41[1] = v44;
  }
}

// File Line: 269
// RVA: 0xCFAD60
void __fastcall hkpHeightFieldAgent::getClosestPoints(
        hkpHeightFieldAgent *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdPointCollector *collector)
{
  hkpHeightFieldAgent::staticGetClosestPoints(bodyA, bodyB, input, collector);
}

// File Line: 275
// RVA: 0xCFAD80
void __fastcall hkpHeightFieldAgent::staticGetClosestPoints(
        hkpCdBody *csBody,
        hkpCdBody *hfBody,
        hkpCollisionInput *input,
        hkpCdPointCollector *collector)
{
  _QWORD *Value; // r11
  unsigned __int64 v8; // r10
  unsigned __int64 v9; // rax
  hkpShape *m_shape; // rbx
  int v11; // r15d
  hkLifoAllocator *v12; // rax
  char *m_cur; // r14
  int v14; // edi
  char *v15; // rcx
  _QWORD *v16; // rcx
  unsigned __int64 v17; // r8
  unsigned __int64 v18; // rax
  __int64 v19; // rbx
  _QWORD *v20; // rax
  _QWORD *v21; // rcx
  _QWORD *v22; // r8
  unsigned __int64 v23; // rax
  _QWORD *v24; // rcx
  hkVector4f v25; // xmm4
  hkVector4f v26; // xmm5
  hkVector4f v27; // xmm6
  int v28; // esi
  __int64 v29; // rcx
  __m128 *v30; // rax
  hkVector4f v31; // xmm7
  __m128 v32; // xmm2
  __m128 v33; // xmm3
  _QWORD *v34; // r8
  _QWORD *v35; // rcx
  unsigned __int64 v36; // rax
  _QWORD *v37; // rcx
  hkLifoAllocator *v38; // rax
  char *v39; // rbp
  char *v40; // rcx
  hkBaseObjectVtbl *vfptr; // r9
  _QWORD *v42; // r8
  _QWORD *v43; // rcx
  unsigned __int64 v44; // rax
  _QWORD *v45; // rcx
  __m128 *v46; // rbx
  float v47; // xmm6_4
  __m128 v48; // xmm5
  __m128 v49; // xmm4
  __m128 *m_motion; // rax
  __m128 v51; // xmm2
  __m128 v52; // xmm1
  __m128 v53; // xmm3
  __m128 v54; // xmm0
  __m128 v55; // xmm5
  hkpCdPointCollectorVtbl *v56; // rax
  __m128 v57; // xmm1
  hkLifoAllocator *v58; // rax
  int v59; // ebx
  hkLifoAllocator *v60; // rax
  _QWORD *v61; // r8
  _QWORD *v62; // rcx
  unsigned __int64 v63; // rax
  _QWORD *v64; // rcx
  char *v65; // [rsp+20h] [rbp-F8h] BYREF
  int v66; // [rsp+28h] [rbp-F0h]
  float m_storage; // [rsp+2Ch] [rbp-ECh]
  __m128 v68; // [rsp+30h] [rbp-E8h] BYREF
  __m128 v69; // [rsp+40h] [rbp-D8h]
  __m128 v70; // [rsp+50h] [rbp-C8h]
  hkpCdBody *v71; // [rsp+60h] [rbp-B8h]
  hkpCdBody *v72; // [rsp+68h] [rbp-B0h]
  hkTransformf v73; // [rsp+70h] [rbp-A8h] BYREF
  hkpShape *v75; // [rsp+130h] [rbp+18h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v8 = Value[1];
  if ( v8 < Value[3] )
  {
    *(_QWORD *)v8 = "LtHeightField";
    *(_QWORD *)(v8 + 16) = "StbTA";
    v9 = __rdtsc();
    *(_DWORD *)(v8 + 8) = v9;
    Value[1] = v8 + 24;
  }
  m_shape = csBody->m_shape;
  v75 = hfBody->m_shape;
  hkTransformf::setMulInverseMul(&v73, (hkTransformf *)hfBody->m_motion, (hkTransformf *)csBody->m_motion);
  v11 = ((__int64 (__fastcall *)(hkpShape *))m_shape->vfptr[5].__first_virtual_table_function__)(m_shape);
  v12 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (char *)v12->m_cur;
  v14 = (16 * v11 + 127) & 0xFFFFFF80;
  v15 = &m_cur[v14];
  if ( v14 > v12->m_slabSize || v15 > v12->m_end )
    m_cur = (char *)hkLifoAllocator::allocateFromNewSlab(v12, v14);
  else
    v12->m_cur = v15;
  v16 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v17 = v16[1];
  if ( v17 < v16[3] )
  {
    *(_QWORD *)v17 = "StgetSpheres";
    v18 = __rdtsc();
    *(_DWORD *)(v17 + 8) = v18;
    v16[1] = v17 + 16;
  }
  v19 = (__int64)m_shape->vfptr[6].__vecDelDtor(m_shape, (unsigned int)m_cur);
  v20 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v21 = (_QWORD *)v20[1];
  v22 = v20;
  if ( (unsigned __int64)v21 < v20[3] )
  {
    *v21 = "Sttransform";
    v23 = __rdtsc();
    v24 = v21 + 2;
    *((_DWORD *)v24 - 2) = v23;
    v22[1] = v24;
  }
  v25.m_quad = (__m128)v73.m_rotation.m_col0;
  v26.m_quad = (__m128)v73.m_rotation.m_col1;
  v27.m_quad = (__m128)v73.m_rotation.m_col2;
  v28 = v11 - 1;
  v29 = v11 - 1;
  v30 = (__m128 *)(v19 + 16 * v29);
  v31.m_quad = (__m128)v73.m_translation;
  do
  {
    v32 = *v30--;
    --v29;
    v33 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v32, v32, 85), v26.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v32, v32, 0), v25.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v32, v32, 170), v27.m_quad)),
            v31.m_quad);
    *(__m128 *)&m_cur[(_QWORD)v30 - v19 + 16] = _mm_shuffle_ps(v33, _mm_unpackhi_ps(v33, v32), 196);
  }
  while ( v29 >= 0 );
  v34 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v35 = (_QWORD *)v34[1];
  if ( (unsigned __int64)v35 < v34[3] )
  {
    *v35 = "Stcollide";
    v36 = __rdtsc();
    v37 = v35 + 2;
    *((_DWORD *)v37 - 2) = v36;
    v34[1] = v37;
  }
  v38 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v39 = (char *)v38->m_cur;
  v40 = &v39[v14];
  if ( v14 > v38->m_slabSize || v40 > v38->m_end )
    v39 = (char *)hkLifoAllocator::allocateFromNewSlab(v38, v14);
  else
    v38->m_cur = v40;
  vfptr = v75->vfptr;
  m_storage = input->m_tolerance.m_storage;
  v65 = m_cur;
  v66 = v11;
  ((void (__fastcall *)(hkpShape *, char **, char *))vfptr[8].__first_virtual_table_function__)(v75, &v65, v39);
  v42 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v43 = (_QWORD *)v42[1];
  if ( (unsigned __int64)v43 < v42[3] )
  {
    *v43 = "Stexamine";
    v44 = __rdtsc();
    v45 = v43 + 2;
    *((_DWORD *)v45 - 2) = v44;
    v42[1] = v45;
  }
  v46 = (__m128 *)v39;
  LODWORD(v47) = _mm_shuffle_ps(
                   (__m128)LODWORD(input->m_tolerance.m_storage),
                   (__m128)LODWORD(input->m_tolerance.m_storage),
                   0).m128_u32[0];
  if ( v28 >= 0 )
  {
    do
    {
      v48 = *v46;
      v49 = _mm_shuffle_ps(v48, v48, 255);
      if ( v49.m128_f32[0] <= v47 )
      {
        m_motion = (__m128 *)hfBody->m_motion;
        v51 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_sub_ps(
                    _mm_sub_ps(
                      (__m128)0i64,
                      _mm_shuffle_ps(
                        *(__m128 *)((char *)v46 + m_cur - v39),
                        *(__m128 *)((char *)v46 + m_cur - v39),
                        255)),
                    v49),
                  v48),
                *(__m128 *)((char *)v46 + m_cur - v39));
        v52 = _mm_mul_ps(_mm_shuffle_ps(v48, v48, 85), m_motion[1]);
        v53 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v51, v51, 85), m_motion[1]),
                    _mm_mul_ps(_mm_shuffle_ps(v51, v51, 0), *m_motion)),
                  _mm_mul_ps(_mm_shuffle_ps(v51, v51, 170), m_motion[2])),
                m_motion[3]);
        v54 = _mm_mul_ps(_mm_shuffle_ps(v48, v48, 0), *m_motion);
        v55 = _mm_mul_ps(_mm_shuffle_ps(v48, v48, 170), m_motion[2]);
        v56 = collector->vfptr;
        v68 = v53;
        v71 = csBody;
        v72 = hfBody;
        v57 = _mm_add_ps(_mm_add_ps(v52, v54), v55);
        v69 = _mm_shuffle_ps(v57, _mm_unpackhi_ps(v57, v49), 196);
        v70 = v69;
        ((void (__fastcall *)(hkpCdPointCollector *, __m128 *, _QWORD *))v56->addCdPoint)(collector, &v68, v42);
      }
      ++v46;
      --v28;
    }
    while ( v28 >= 0 );
    v14 = (16 * v11 + 127) & 0xFFFFFF80;
  }
  v58 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v59 = (v14 + 15) & 0xFFFFFFF0;
  if ( v14 > v58->m_slabSize || &v39[v59] != v58->m_cur || v58->m_firstNonLifoEnd == v39 )
    hkLifoAllocator::slowBlockFree(v58, v39, v59);
  else
    v58->m_cur = v39;
  v60 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( v14 > v60->m_slabSize || &m_cur[v59] != v60->m_cur || v60->m_firstNonLifoEnd == m_cur )
    hkLifoAllocator::slowBlockFree(v60, m_cur, v59);
  else
    v60->m_cur = m_cur;
  v61 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v62 = (_QWORD *)v61[1];
  if ( (unsigned __int64)v62 < v61[3] )
  {
    *v62 = "lt";
    v63 = __rdtsc();
    v64 = v62 + 2;
    *((_DWORD *)v64 - 2) = v63;
    v61[1] = v64;
  }
}

// File Line: 351
// RVA: 0xCFB980
void __fastcall hkHeightFieldRayForwardingCollector::addRayHit(
        hkHeightFieldRayForwardingCollector *this,
        hkpCdBody *cdBody,
        hkpShapeRayCastCollectorOutput *hitInfo)
{
  hkVector4f v3; // xmm1
  __m128 *m_motion; // rax
  __m128 v6; // xmm3
  __m128 v7; // xmm2
  __m128 v8; // xmm1
  unsigned int v9; // xmm0_4
  hkpCdBody *m_csBody; // rax
  hkpCdPointCollector *m_collector; // rcx
  __m128 v12; // xmm2
  __int128 v13; // [rsp+30h] [rbp-58h]
  __int128 v14[3]; // [rsp+40h] [rbp-48h] BYREF
  hkpCdBody *v15; // [rsp+70h] [rbp-18h]
  hkpCdBody *v16; // [rsp+78h] [rbp-10h]

  v3.m_quad = (__m128)hitInfo->m_normal;
  m_motion = (__m128 *)cdBody->m_motion;
  v6 = _mm_add_ps(
         _mm_mul_ps(
           _mm_shuffle_ps((__m128)LODWORD(hitInfo->m_hitFraction), (__m128)LODWORD(hitInfo->m_hitFraction), 0),
           this->m_path.m_quad),
         this->m_currentFrom.m_quad);
  v7 = _mm_add_ps(
         _mm_mul_ps(_mm_shuffle_ps(v3.m_quad, v3.m_quad, 85), m_motion[1]),
         _mm_mul_ps(_mm_shuffle_ps(hitInfo->m_normal.m_quad, hitInfo->m_normal.m_quad, 0), *m_motion));
  v8 = _mm_mul_ps(_mm_shuffle_ps(v3.m_quad, v3.m_quad, 170), m_motion[2]);
  v9 = LODWORD(this->m_currentRadius) ^ _xmm[0];
  m_csBody = this->m_csBody;
  m_collector = this->m_collector;
  v12 = _mm_add_ps(v7, v8);
  v13 = (__int128)v12;
  HIDWORD(v13) = LODWORD(hitInfo->m_hitFraction);
  v14[1] = v13;
  v14[0] = (__int128)_mm_add_ps(v6, _mm_mul_ps(_mm_shuffle_ps((__m128)v9, (__m128)v9, 0), v12));
  v16 = cdBody;
  v15 = m_csBody;
  v14[2] = v13;
  m_collector->vfptr->addCdPoint(m_collector, (hkpCdPoint *)v14);
  this->m_earlyOutHitFraction = fminf(this->m_collector->m_earlyOutDistance, this->m_earlyOutHitFraction);
}

// File Line: 383
// RVA: 0xCFB250
void __fastcall hkpHeightFieldAgent::staticLinearCast(
        hkpCdBody *csBody,
        hkpCdBody *hfBody,
        hkpLinearCastCollisionInput *input,
        hkpCdPointCollector *collector,
        hkpCdPointCollector *startCollector)
{
  _QWORD *Value; // rcx
  unsigned __int64 v9; // r10
  unsigned __int64 v10; // rax
  _QWORD *v11; // r8
  _QWORD *v12; // rcx
  unsigned __int64 v13; // rax
  _QWORD *v14; // rcx
  hkpShape *m_shape; // r15
  hkpShape *v16; // r13
  __int64 v17; // r12
  hkLifoAllocator *v18; // rax
  char *m_cur; // rdi
  int v20; // ebx
  char *v21; // rcx
  __m128 *m_motion; // rcx
  __m128 v23; // xmm3
  __m128 v24; // xmm1
  __m128 v25; // xmm2
  __m128 v26; // xmm7
  __int64 v27; // r15
  _QWORD *v28; // rax
  _QWORD *v29; // rcx
  _QWORD *v30; // r8
  unsigned __int64 v31; // rax
  _QWORD *v32; // rcx
  float m_maxExtraPenetration; // xmm0_4
  __int64 v34; // rbp
  __m128 v35; // xmm6
  __m128 *v36; // rax
  __m128 v37; // xmm4
  __m128 v38; // xmm5
  __m128 v39; // xmm6
  __m128 v40; // xmm2
  hkBaseObjectVtbl *vfptr; // rax
  hkLifoAllocator *v42; // rax
  int v43; // r8d
  _QWORD *v44; // rax
  _QWORD *v45; // rcx
  _QWORD *v46; // r8
  unsigned __int64 v47; // rax
  _QWORD *v48; // rcx
  __m128 v49[2]; // [rsp+20h] [rbp-128h] BYREF
  int v50; // [rsp+40h] [rbp-108h]
  __int64 v51; // [rsp+48h] [rbp-100h]
  __int64 v52; // [rsp+50h] [rbp-F8h]
  __int64 v53; // [rsp+58h] [rbp-F0h]
  int v54; // [rsp+60h] [rbp-E8h]
  float v55; // [rsp+64h] [rbp-E4h]
  void **v56; // [rsp+70h] [rbp-D8h] BYREF
  int v57; // [rsp+78h] [rbp-D0h]
  __m128 v58; // [rsp+80h] [rbp-C8h]
  int v59; // [rsp+90h] [rbp-B8h]
  hkVector4f v60; // [rsp+A0h] [rbp-A8h]
  hkpCdBody *v61; // [rsp+B0h] [rbp-98h]
  hkpCdPointCollector *v62; // [rsp+B8h] [rbp-90h]
  hkTransformf v63; // [rsp+C0h] [rbp-88h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = Value[1];
  if ( v9 < Value[3] )
  {
    *(_QWORD *)v9 = "LtHeightField";
    *(_QWORD *)(v9 + 16) = "StClosestPoints";
    v10 = __rdtsc();
    *(_DWORD *)(v9 + 8) = v10;
    Value[1] = v9 + 24;
  }
  if ( startCollector )
    hkpHeightFieldAgent::staticGetClosestPoints(csBody, hfBody, input, startCollector);
  v11 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v12 = (_QWORD *)v11[1];
  if ( (unsigned __int64)v12 < v11[3] )
  {
    *v12 = "StGetSpheres";
    v13 = __rdtsc();
    v14 = v12 + 2;
    *((_DWORD *)v14 - 2) = v13;
    v11[1] = v14;
  }
  m_shape = csBody->m_shape;
  v16 = hfBody->m_shape;
  hkTransformf::setMulInverseMul(&v63, (hkTransformf *)hfBody->m_motion, (hkTransformf *)csBody->m_motion);
  v17 = ((unsigned int (__fastcall *)(hkpShape *))m_shape->vfptr[5].__first_virtual_table_function__)(m_shape);
  v18 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (char *)v18->m_cur;
  v20 = (16 * v17 + 127) & 0xFFFFFF80;
  v21 = &m_cur[v20];
  if ( v20 > v18->m_slabSize || v21 > v18->m_end )
    m_cur = (char *)hkLifoAllocator::allocateFromNewSlab(v18, v20);
  else
    v18->m_cur = v21;
  m_motion = (__m128 *)hfBody->m_motion;
  v23 = m_motion[2];
  v24 = _mm_unpacklo_ps(*m_motion, m_motion[1]);
  v25 = _mm_movelh_ps(v24, v23);
  v26 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_shuffle_ps(input->m_path.m_quad, input->m_path.m_quad, 85),
              _mm_shuffle_ps(_mm_movehl_ps(v25, v24), v23, 212)),
            _mm_mul_ps(_mm_shuffle_ps(input->m_path.m_quad, input->m_path.m_quad, 0), v25)),
          _mm_mul_ps(
            _mm_shuffle_ps(_mm_unpackhi_ps(*m_motion, m_motion[1]), v23, 228),
            _mm_shuffle_ps(input->m_path.m_quad, input->m_path.m_quad, 170)));
  v27 = (__int64)m_shape->vfptr[6].__vecDelDtor(m_shape, (unsigned int)m_cur);
  v28 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v29 = (_QWORD *)v28[1];
  v30 = v28;
  if ( (unsigned __int64)v29 < v28[3] )
  {
    *v29 = "StCastSpheres";
    v31 = __rdtsc();
    v32 = v29 + 2;
    *((_DWORD *)v32 - 2) = v31;
    v30[1] = v32;
  }
  m_maxExtraPenetration = input->m_maxExtraPenetration;
  v50 = 0;
  v51 = 0i64;
  v52 = 0i64;
  v55 = m_maxExtraPenetration;
  v57 = (int)FLOAT_1_0;
  v53 = 0i64;
  v61 = csBody;
  v60.m_quad = (__m128)input->m_path;
  v56 = &hkHeightFieldRayForwardingCollector::`vftable;
  v62 = collector;
  if ( (int)v17 > 0 )
  {
    v34 = v17;
    do
    {
      v35 = *(__m128 *)v27;
      v36 = (__m128 *)csBody->m_motion;
      v54 = *(_DWORD *)(v27 + 12);
      v37 = _mm_shuffle_ps(v35, v35, 85);
      v38 = _mm_shuffle_ps(v35, v35, 0);
      v39 = _mm_shuffle_ps(v35, v35, 170);
      v49[0] = _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(v63.m_rotation.m_col0.m_quad, v38),
                     _mm_mul_ps(v63.m_rotation.m_col1.m_quad, v37)),
                   _mm_mul_ps(v63.m_rotation.m_col2.m_quad, v39)),
                 v63.m_translation.m_quad);
      v49[1] = _mm_add_ps(v49[0], v26);
      v40 = _mm_add_ps(
              _mm_add_ps(_mm_add_ps(_mm_mul_ps(v36[1], v37), _mm_mul_ps(*v36, v38)), _mm_mul_ps(v36[2], v39)),
              v36[3]);
      v59 = v54;
      vfptr = v16->vfptr;
      v58 = v40;
      ((void (__fastcall *)(hkpShape *, __m128 *, hkpCdBody *, void ***))vfptr[9].__vecDelDtor)(v16, v49, hfBody, &v56);
      v27 += 16i64;
      --v34;
    }
    while ( v34 );
  }
  v42 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v43 = (v20 + 15) & 0xFFFFFFF0;
  if ( v20 > v42->m_slabSize || &m_cur[v43] != v42->m_cur || v42->m_firstNonLifoEnd == m_cur )
    hkLifoAllocator::slowBlockFree(v42, m_cur, v43);
  else
    v42->m_cur = m_cur;
  v44 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v45 = (_QWORD *)v44[1];
  v46 = v44;
  if ( (unsigned __int64)v45 < v44[3] )
  {
    *v45 = "lt";
    v47 = __rdtsc();
    v48 = v45 + 2;
    *((_DWORD *)v48 - 2) = v47;
    v46[1] = v48;
  }
}

// File Line: 436
// RVA: 0xCFB210
void __fastcall hkpHeightFieldAgent::linearCast(
        hkpHeightFieldAgent *this,
        hkpCdBody *csBody,
        hkpCdBody *hfBody,
        hkpLinearCastCollisionInput *input,
        hkpCdPointCollector *collector,
        hkpCdPointCollector *startCollector)
{
  hkpHeightFieldAgent::staticLinearCast(csBody, hfBody, input, collector, startCollector);
}

