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
void __fastcall hkpHeightFieldAgent::hkpHeightFieldAgent(hkpHeightFieldAgent *this, hkpCdBody *A, hkpCdBody *B, hkpCollisionInput *input, hkpContactMgr *mgr)
{
  hkpContactMgr *v5; // rax
  hkpHeightFieldAgent *v6; // rsi
  int v7; // eax
  int v8; // ecx
  int v9; // ebp
  int v10; // ecx
  int v11; // er9
  int v12; // edx
  unsigned __int16 *v13; // rdi
  __int64 v14; // rcx

  v5 = mgr;
  v6 = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_contactMgr = v5;
  this->vfptr = (hkBaseObjectVtbl *)&hkpHeightFieldAgent::`vftable';
  this->m_contactPointId.m_capacityAndFlags = 2147483648;
  this->m_contactPointId.m_data = 0i64;
  this->m_contactPointId.m_size = 0;
  if ( v5 )
  {
    v7 = ((__int64 (__fastcall *)(hkpShape *, hkpCdBody *, hkpCdBody *, hkpCollisionInput *))A->m_shape->vfptr[5].__first_virtual_table_function__)(
           A->m_shape,
           A,
           B,
           input);
    v8 = v6->m_contactPointId.m_capacityAndFlags & 0x3FFFFFFF;
    v9 = v7;
    if ( v8 < v7 )
    {
      v10 = 2 * v8;
      v11 = v7;
      if ( v7 < v10 )
        v11 = v10;
      hkArrayUtil::_reserve(
        (hkResult *)&mgr,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v6->m_contactPointId,
        v11,
        2);
    }
    v12 = v9 - v6->m_contactPointId.m_size;
    v13 = &v6->m_contactPointId.m_data[v6->m_contactPointId.m_size];
    v14 = v12;
    if ( v12 > 0 )
    {
      while ( v14 )
      {
        *v13 = -1;
        ++v13;
        --v14;
      }
    }
    v6->m_contactPointId.m_size = v9;
  }
}

// File Line: 37
// RVA: 0xCFA930
void __fastcall hkpHeightFieldAgent::registerAgent(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher *v1; // rbx
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h]

  f.m_createFunc = hkpHeightFieldAgent::createHeightFieldAAgent;
  f.m_getPenetrationsFunc = hkpSymmetricAgentLinearCast<hkpHeightFieldAgent>::staticGetPenetrations;
  v1 = dispatcher;
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
  hkpCollisionDispatcher::registerCollisionAgent(v1, &f, SPHERE_REP, HEIGHT_FIELD);
}

// File Line: 66
// RVA: 0xCFB830
void __fastcall hkpHeightFieldAgent::createHeightFieldBAgent(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *mgr)
{
  hkpCdBody *v4; // rbp
  hkpContactMgr *v5; // rbx
  hkpCollisionInput *v6; // rdi
  hkpCdBody *v7; // rsi
  _QWORD **v8; // rax
  hkpHeightFieldAgent *v9; // rax

  v4 = bodyA;
  v5 = mgr;
  v6 = input;
  v7 = bodyB;
  v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkpHeightFieldAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(v8[11], 40i64);
  if ( v9 )
    hkpHeightFieldAgent::hkpHeightFieldAgent(v9, v4, v7, v6, v5);
}

// File Line: 74
// RVA: 0xCFB7A0
hkpHeightFieldAgent *__fastcall hkpHeightFieldAgent::createHeightFieldAAgent(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *mgr)
{
  hkpCdBody *v4; // r14
  hkpContactMgr *v5; // rdi
  hkpCollisionInput *v6; // rsi
  hkpCdBody *v7; // rbp
  _QWORD **v8; // rax
  hkpHeightFieldAgent *result; // rax
  hkpCollisionAgent *v10; // rbx

  v4 = bodyA;
  v5 = mgr;
  v6 = input;
  v7 = bodyB;
  v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkpHeightFieldAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(v8[11], 40i64);
  v10 = (hkpCollisionAgent *)&result->vfptr;
  if ( result )
  {
    hkpHeightFieldAgent::hkpHeightFieldAgent(result, v7, v4, v6, v5);
    v10->vfptr = (hkBaseObjectVtbl *)&hkpSymmetricAgent<hkpHeightFieldAgent>::`vftable';
    result = (hkpHeightFieldAgent *)v10;
  }
  return result;
}

// File Line: 81
// RVA: 0xCFB620
void __fastcall hkpHeightFieldAgent::cleanup(hkpHeightFieldAgent *this, hkpConstraintOwner *constraintOwner)
{
  hkpConstraintOwner *v2; // rbp
  hkpHeightFieldAgent *v3; // rbx
  int v4; // edi
  __int64 v5; // rsi
  __int64 v6; // rdx

  v2 = constraintOwner;
  v3 = this;
  if ( this->m_contactMgr )
  {
    v4 = 0;
    if ( this->m_contactPointId.m_size > 0 )
    {
      v5 = 0i64;
      do
      {
        v6 = v3->m_contactPointId.m_data[v5];
        if ( (_WORD)v6 != -1 )
          ((void (__fastcall *)(hkpContactMgr *, __int64, hkpConstraintOwner *))v3->m_contactMgr->vfptr[2].__first_virtual_table_function__)(
            v3->m_contactMgr,
            v6,
            v2);
        ++v4;
        ++v5;
      }
      while ( v4 < v3->m_contactPointId.m_size );
    }
  }
  v3->vfptr->__vecDelDtor((hkBaseObject *)&v3->vfptr, 1u);
}

// File Line: 98
// RVA: 0xCFBCC0
void __fastcall hkpHeightFieldAgent::processCollision(hkpHeightFieldAgent *this, hkpCdBody *csBody, hkpCdBody *hfBody, hkpProcessCollisionInput *input, hkpProcessCollisionOutput *processOutput)
{
  hkpHeightFieldAgent *v5; // r13
  hkpProcessCollisionInput *v6; // rbp
  hkpCdBody *v7; // rbx
  hkpCdBody *v8; // rdi
  _QWORD *v9; // rax
  _QWORD *v10; // rcx
  _QWORD *v11; // r8
  unsigned __int64 v12; // rax
  signed __int64 v13; // rcx
  hkpShape *v14; // r15
  int v15; // ebx
  hkLifoAllocator *v16; // rax
  _BYTE *v17; // r14
  int v18; // esi
  char *v19; // rcx
  unsigned __int16 *v20; // rdi
  __int64 v21; // rax
  int v22; // er12
  hkVector4f v23; // xmm4
  hkVector4f v24; // xmm5
  hkVector4f v25; // xmm6
  __int64 v26; // rdx
  __m128 *v27; // rcx
  hkVector4f v28; // xmm7
  __m128 v29; // xmm2
  __m128 v30; // xmm3
  hkLifoAllocator *v31; // rax
  __m128 *v32; // r15
  char *v33; // rcx
  hkBaseObjectVtbl *v34; // r9
  __m128 *v35; // rbp
  float v36; // xmm6_4
  signed __int64 v37; // rax
  __m128 v38; // xmm3
  __int64 v39; // rdx
  hkpProcessCdPoint *v40; // r13
  __m128 v41; // xmm2
  __m128 v42; // xmm2
  __m128 v43; // xmm3
  unsigned __int16 v44; // ax
  hkLifoAllocator *v45; // rax
  int v46; // ebx
  hkLifoAllocator *v47; // rax
  _QWORD *v48; // r8
  _QWORD *v49; // rcx
  unsigned __int64 v50; // rax
  signed __int64 v51; // rcx
  hkpShape *v52; // [rsp+40h] [rbp-D8h]
  _BYTE *v53; // [rsp+50h] [rbp-C8h]
  __m128 *v54; // [rsp+58h] [rbp-C0h]
  _BYTE *v55; // [rsp+60h] [rbp-B8h]
  int v56; // [rsp+68h] [rbp-B0h]
  float v57; // [rsp+6Ch] [rbp-ACh]
  hkTransformf v58; // [rsp+70h] [rbp-A8h]
  hkpHeightFieldAgent *v59; // [rsp+120h] [rbp+8h]
  hkpCdBody *v60; // [rsp+128h] [rbp+10h]
  hkpCdBody *v61; // [rsp+130h] [rbp+18h]
  hkpProcessCollisionInput *v62; // [rsp+138h] [rbp+20h]

  v62 = input;
  v61 = hfBody;
  v60 = csBody;
  v59 = this;
  v5 = this;
  v6 = input;
  v7 = hfBody;
  v8 = csBody;
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)v9[1];
  v11 = v9;
  if ( (unsigned __int64)v10 < v9[3] )
  {
    *v10 = "TtHeightField";
    v12 = __rdtsc();
    v13 = (signed __int64)(v10 + 2);
    *(_DWORD *)(v13 - 8) = v12;
    v11[1] = v13;
  }
  v14 = v8->m_shape;
  v52 = v7->m_shape;
  hkTransformf::setMulInverseMul(&v58, (hkTransformf *)v7->m_motion, (hkTransformf *)v8->m_motion);
  v15 = v5->m_contactPointId.m_size;
  v16 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v17 = v16->m_cur;
  v53 = v17;
  v18 = (16 * v15 + 127) & 0xFFFFFF80;
  v19 = &v17[v18];
  if ( v18 > v16->m_slabSize || v19 > v16->m_end )
  {
    v17 = hkLifoAllocator::allocateFromNewSlab(v16, v18);
    v53 = v17;
  }
  else
  {
    v16->m_cur = v19;
  }
  v20 = v5->m_contactPointId.m_data;
  v21 = (__int64)v14->vfptr[6].__vecDelDtor((hkBaseObject *)&v14->vfptr, (unsigned int)v17);
  v22 = v15 - 1;
  v23.m_quad = (__m128)v58.m_rotation.m_col0;
  v24.m_quad = (__m128)v58.m_rotation.m_col1;
  v25.m_quad = (__m128)v58.m_rotation.m_col2;
  v26 = v15 - 1;
  v27 = (__m128 *)(v21 + 16 * v26);
  v28.m_quad = (__m128)v58.m_translation;
  do
  {
    v29 = *v27;
    --v27;
    --v26;
    v30 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v29, v29, 85), v24.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v29, v29, 0), v23.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v29, v29, 170), v25.m_quad)),
            v28.m_quad);
    *(__m128 *)&v17[(_QWORD)v27 - v21 + 16] = _mm_shuffle_ps(v30, _mm_unpackhi_ps(v30, v29), 196);
  }
  while ( v26 >= 0 );
  v31 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v32 = (__m128 *)v31->m_cur;
  v33 = (char *)v32 + v18;
  v54 = (__m128 *)v31->m_cur;
  if ( v18 > v31->m_slabSize || v33 > v31->m_end )
  {
    v32 = (__m128 *)hkLifoAllocator::allocateFromNewSlab(v31, v18);
    v54 = v32;
  }
  else
  {
    v31->m_cur = v33;
  }
  v34 = v52->vfptr;
  v57 = v6->m_tolerance.m_storage;
  v55 = v17;
  v56 = v15;
  ((void (__fastcall *)(hkpShape *, _BYTE **, __m128 *))v34[8].__first_virtual_table_function__)(v52, &v55, v32);
  v35 = v32;
  LODWORD(v36) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(v62->m_tolerance.m_storage),
                                      (__m128)LODWORD(v62->m_tolerance.m_storage),
                                      0);
  if ( v22 >= 0 )
  {
    v37 = v17 - (_BYTE *)v32;
    while ( 1 )
    {
      v38 = *v35;
      if ( COERCE_FLOAT(_mm_shuffle_ps(v38, v38, 255)) <= v36 )
        break;
      v39 = *v20;
      if ( (_WORD)v39 != -1 )
      {
        ((void (__fastcall *)(hkpContactMgr *, __int64, hkpConstraintOwner *))v5->m_contactMgr->vfptr[2].__first_virtual_table_function__)(
          v5->m_contactMgr,
          v39,
          processOutput->m_constraintOwner.m_storage);
        *v20 = -1;
LABEL_22:
        v37 = v17 - (_BYTE *)v32;
      }
      ++v35;
      ++v20;
      if ( --v22 < 0 )
      {
        v18 = (16 * v15 + 127) & 0xFFFFFF80;
        v17 = v53;
        v32 = v54;
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
                                             _mm_mul_ps(_mm_shuffle_ps(v41, v41, 85), *((__m128 *)v61->m_motion + 1)),
                                             _mm_mul_ps(_mm_shuffle_ps(v41, v41, 0), *(__m128 *)v61->m_motion)),
                                           _mm_mul_ps(_mm_shuffle_ps(v41, v41, 170), *((__m128 *)v61->m_motion + 2))),
                                         *((__m128 *)v61->m_motion + 3));
    v42 = *v35;
    v43 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v42, v42, 85), *((__m128 *)v61->m_motion + 1)),
              _mm_mul_ps(_mm_shuffle_ps(*v35, *v35, 0), *(__m128 *)v61->m_motion)),
            _mm_mul_ps(_mm_shuffle_ps(*v35, *v35, 170), *((__m128 *)v61->m_motion + 2)));
    v40->m_contact.m_separatingNormal.m_quad = _mm_shuffle_ps(
                                                 v43,
                                                 _mm_unpackhi_ps(v43, _mm_shuffle_ps(v42, v42, 255)),
                                                 196);
    if ( *v20 != -1
      || (v44 = ((__int64 (__fastcall *)(hkpContactMgr *, hkpCdBody *, hkpCdBody *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *, _QWORD, hkpProcessCdPoint *))v59->m_contactMgr->vfptr[1].__first_virtual_table_function__)(
                  v59->m_contactMgr,
                  v60,
                  v61,
                  v62,
                  processOutput,
                  0i64,
                  v40),
          *v20 = v44,
          v44 != -1) )
    {
      ++processOutput->m_firstFreeContactPoint.m_storage;
    }
    v40->m_contactPointId = *v20;
    v5 = v59;
    goto LABEL_22;
  }
LABEL_25:
  v45 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v46 = (v18 + 15) & 0xFFFFFFF0;
  if ( v18 > v45->m_slabSize || (char *)v32 + v46 != v45->m_cur || v45->m_firstNonLifoEnd == v32 )
    hkLifoAllocator::slowBlockFree(v45, v32, v46);
  else
    v45->m_cur = v32;
  v47 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( v18 > v47->m_slabSize || &v17[v46] != v47->m_cur || v47->m_firstNonLifoEnd == v17 )
    hkLifoAllocator::slowBlockFree(v47, v17, v46);
  else
    v47->m_cur = v17;
  v48 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v49 = (_QWORD *)v48[1];
  if ( (unsigned __int64)v49 < v48[3] )
  {
    *v49 = "Et";
    v50 = __rdtsc();
    v51 = (signed __int64)(v49 + 2);
    *(_DWORD *)(v51 - 8) = v50;
    v48[1] = v51;
  }
}tream__m_instance.m_slotID);
  v49 = (_QWORD *)v48[1];
  if ( (unsigned __int64)v49 < v48[3] )
  {
    *

// File Line: 202
// RVA: 0xCFA9F0
void __fastcall hkpHeightFieldAgent::getPenetrations(hkpHeightFieldAgent *this, hkpCdBody *csBody, hkpCdBody *hfBody, hkpCollisionInput *input, hkpCdBodyPairCollector *collector)
{
  hkpHeightFieldAgent::staticGetPenetrations(csBody, hfBody, input, collector);
}

// File Line: 208
// RVA: 0xCFAA10
void __fastcall hkpHeightFieldAgent::staticGetPenetrations(hkpCdBody *csBody, hkpCdBody *hfBody, hkpCollisionInput *input, hkpCdBodyPairCollector *collector)
{
  hkpCdBody *v4; // r15
  hkpCdBodyPairCollector *v5; // r12
  hkpCdBody *v6; // r14
  _QWORD *v7; // r11
  unsigned __int64 v8; // r10
  unsigned __int64 v9; // rax
  hkpShape *v10; // rdi
  int v11; // er13
  hkLifoAllocator *v12; // rax
  char *v13; // rbp
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
  signed __int64 v29; // rcx
  hkLifoAllocator *v30; // rax
  float *v31; // rsi
  char *v32; // rcx
  _QWORD *v33; // r8
  _QWORD *v34; // rcx
  unsigned __int64 v35; // rax
  signed __int64 v36; // rcx
  float *v37; // rax
  hkLifoAllocator *v38; // rax
  int v39; // edi
  hkLifoAllocator *v40; // rax
  _QWORD *v41; // r8
  _QWORD *v42; // rcx
  unsigned __int64 v43; // rax
  signed __int64 v44; // rcx
  char *v45; // [rsp+20h] [rbp-A8h]
  int v46; // [rsp+28h] [rbp-A0h]
  float v47; // [rsp+2Ch] [rbp-9Ch]
  hkTransformf v48; // [rsp+30h] [rbp-98h]
  hkpShape *v49; // [rsp+D0h] [rbp+8h]
  hkpCollisionInput *v50; // [rsp+E0h] [rbp+18h]

  v50 = input;
  v4 = csBody;
  v5 = collector;
  v6 = hfBody;
  v7 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v8 = v7[1];
  if ( v8 < v7[3] )
  {
    *(_QWORD *)v8 = "LtHeightField";
    *(_QWORD *)(v8 + 16) = "StGetSpheres";
    v9 = __rdtsc();
    *(_DWORD *)(v8 + 8) = v9;
    v7[1] = v8 + 24;
  }
  v10 = v4->m_shape;
  v49 = v6->m_shape;
  hkTransformf::setMulInverseMul(&v48, (hkTransformf *)v6->m_motion, (hkTransformf *)v4->m_motion);
  v11 = ((__int64 (__fastcall *)(hkpShape *))v10->vfptr[5].__first_virtual_table_function__)(v10);
  v12 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v13 = (char *)v12->m_cur;
  v14 = (16 * v11 + 127) & 0xFFFFFF80;
  v15 = &v13[v14];
  if ( v14 > v12->m_slabSize || v15 > v12->m_end )
    v13 = (char *)hkLifoAllocator::allocateFromNewSlab(v12, v14);
  else
    v12->m_cur = v15;
  v16 = (__int64)v10->vfptr[6].__vecDelDtor((hkBaseObject *)&v10->vfptr, (unsigned int)v13);
  v17 = v11 - 1;
  v18.m_quad = (__m128)v48.m_rotation.m_col0;
  v19.m_quad = (__m128)v48.m_rotation.m_col1;
  v20.m_quad = (__m128)v48.m_rotation.m_col2;
  v21 = v11 - 1;
  v22 = (__m128 *)(v16 + 16 * v21);
  v23.m_quad = (__m128)v48.m_translation;
  do
  {
    v24 = *v22;
    --v22;
    --v21;
    v25 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v24, v24, 85), v19.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v24, v24, 0), v18.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v24, v24, 170), v20.m_quad)),
            v23.m_quad);
    *(__m128 *)&v13[(_QWORD)v22 - v16 + 16] = _mm_shuffle_ps(v25, _mm_unpackhi_ps(v25, v24), 196);
  }
  while ( v21 >= 0 );
  v26 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v27 = (_QWORD *)v26[1];
  if ( (unsigned __int64)v27 < v26[3] )
  {
    *v27 = "StCollide";
    v28 = __rdtsc();
    v29 = (signed __int64)(v27 + 2);
    *(_DWORD *)(v29 - 8) = v28;
    v26[1] = v29;
  }
  v30 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v31 = (float *)v30->m_cur;
  v32 = (char *)v31 + v14;
  if ( v14 > v30->m_slabSize || v32 > v30->m_end )
    v31 = (float *)hkLifoAllocator::allocateFromNewSlab(v30, v14);
  else
    v30->m_cur = v32;
  v45 = v13;
  v46 = v11;
  v47 = v50->m_tolerance.m_storage;
  ((void (__fastcall *)(hkpShape *, char **, float *))v49->vfptr[8].__first_virtual_table_function__)(v49, &v45, v31);
  v33 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v34 = (_QWORD *)v33[1];
  if ( (unsigned __int64)v34 < v33[3] )
  {
    *v34 = "StExamine";
    v35 = __rdtsc();
    v36 = (signed __int64)(v34 + 2);
    *(_DWORD *)(v36 - 8) = v35;
    v33[1] = v36;
  }
  if ( v17 >= 0 )
  {
    v37 = v31 + 3;
    while ( *v37 >= 0.0 )
    {
      v37 += 4;
      if ( --v17 < 0 )
        goto LABEL_23;
    }
    v5->vfptr->addCdBodyPair(v5, v4, v6);
  }
LABEL_23:
  v38 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v39 = (v14 + 15) & 0xFFFFFFF0;
  if ( v14 > v38->m_slabSize || (char *)v31 + v39 != v38->m_cur || v38->m_firstNonLifoEnd == v31 )
    hkLifoAllocator::slowBlockFree(v38, v31, v39);
  else
    v38->m_cur = v31;
  v40 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( v14 > v40->m_slabSize || &v13[v39] != v40->m_cur || v40->m_firstNonLifoEnd == v13 )
    hkLifoAllocator::slowBlockFree(v40, v13, v39);
  else
    v40->m_cur = v13;
  v41 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v42 = (_QWORD *)v41[1];
  if ( (unsigned __int64)v42 < v41[3] )
  {
    *v42 = "lt";
    v43 = __rdtsc();
    v44 = (signed __int64)(v42 + 2);
    *(_DWORD *)(v44 - 8) = v43;
    v41[1] = v44;
  }
}

// File Line: 269
// RVA: 0xCFAD60
void __fastcall hkpHeightFieldAgent::getClosestPoints(hkpHeightFieldAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdPointCollector *collector)
{
  hkpHeightFieldAgent::staticGetClosestPoints(bodyA, bodyB, input, collector);
}

// File Line: 275
// RVA: 0xCFAD80
void __fastcall hkpHeightFieldAgent::staticGetClosestPoints(hkpCdBody *csBody, hkpCdBody *hfBody, hkpCollisionInput *input, hkpCdPointCollector *collector)
{
  hkpCdBody *v4; // rdi
  hkpCollisionInput *v5; // r12
  hkpCdBody *v6; // r13
  _QWORD *v7; // r11
  unsigned __int64 v8; // r10
  unsigned __int64 v9; // rax
  hkpShape *v10; // rbx
  int v11; // er15
  hkLifoAllocator *v12; // rax
  _BYTE *v13; // r14
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
  signed __int64 v24; // rcx
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
  signed __int64 v37; // rcx
  hkLifoAllocator *v38; // rax
  __m128 *v39; // rbp
  char *v40; // rcx
  hkBaseObjectVtbl *v41; // r9
  _QWORD *v42; // r8
  _QWORD *v43; // rcx
  unsigned __int64 v44; // rax
  signed __int64 v45; // rcx
  __m128 *v46; // rbx
  float v47; // xmm6_4
  __m128 v48; // xmm5
  __m128 v49; // xmm4
  __m128 *v50; // rax
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
  signed __int64 v64; // rcx
  _BYTE *v65; // [rsp+20h] [rbp-F8h]
  int v66; // [rsp+28h] [rbp-F0h]
  float v67; // [rsp+2Ch] [rbp-ECh]
  __m128 v68; // [rsp+30h] [rbp-E8h]
  __m128 v69; // [rsp+40h] [rbp-D8h]
  __m128 v70; // [rsp+50h] [rbp-C8h]
  hkpCdBody *v71; // [rsp+60h] [rbp-B8h]
  hkpCdBody *v72; // [rsp+68h] [rbp-B0h]
  hkTransformf v73; // [rsp+70h] [rbp-A8h]
  hkpCdBody *v74; // [rsp+120h] [rbp+8h]
  hkpShape *v75; // [rsp+130h] [rbp+18h]
  hkpCdPointCollector *v76; // [rsp+138h] [rbp+20h]

  v76 = collector;
  v74 = csBody;
  v4 = csBody;
  v5 = input;
  v6 = hfBody;
  v7 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v8 = v7[1];
  if ( v8 < v7[3] )
  {
    *(_QWORD *)v8 = "LtHeightField";
    *(_QWORD *)(v8 + 16) = "StbTA";
    v9 = __rdtsc();
    *(_DWORD *)(v8 + 8) = v9;
    v7[1] = v8 + 24;
  }
  v10 = v4->m_shape;
  v75 = v6->m_shape;
  hkTransformf::setMulInverseMul(&v73, (hkTransformf *)v6->m_motion, (hkTransformf *)v4->m_motion);
  v11 = ((__int64 (__fastcall *)(hkpShape *))v10->vfptr[5].__first_virtual_table_function__)(v10);
  v12 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v13 = v12->m_cur;
  v14 = (16 * v11 + 127) & 0xFFFFFF80;
  v15 = &v13[v14];
  if ( v14 > v12->m_slabSize || v15 > v12->m_end )
    v13 = hkLifoAllocator::allocateFromNewSlab(v12, v14);
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
  v19 = (__int64)v10->vfptr[6].__vecDelDtor((hkBaseObject *)&v10->vfptr, (unsigned int)v13);
  v20 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v21 = (_QWORD *)v20[1];
  v22 = v20;
  if ( (unsigned __int64)v21 < v20[3] )
  {
    *v21 = "Sttransform";
    v23 = __rdtsc();
    v24 = (signed __int64)(v21 + 2);
    *(_DWORD *)(v24 - 8) = v23;
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
    v32 = *v30;
    --v30;
    --v29;
    v33 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v32, v32, 85), v26.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v32, v32, 0), v25.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v32, v32, 170), v27.m_quad)),
            v31.m_quad);
    *(__m128 *)&v13[(_QWORD)v30 - v19 + 16] = _mm_shuffle_ps(v33, _mm_unpackhi_ps(v33, v32), 196);
  }
  while ( v29 >= 0 );
  v34 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v35 = (_QWORD *)v34[1];
  if ( (unsigned __int64)v35 < v34[3] )
  {
    *v35 = "Stcollide";
    v36 = __rdtsc();
    v37 = (signed __int64)(v35 + 2);
    *(_DWORD *)(v37 - 8) = v36;
    v34[1] = v37;
  }
  v38 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v39 = (__m128 *)v38->m_cur;
  v40 = (char *)v39 + v14;
  if ( v14 > v38->m_slabSize || v40 > v38->m_end )
    v39 = (__m128 *)hkLifoAllocator::allocateFromNewSlab(v38, v14);
  else
    v38->m_cur = v40;
  v41 = v75->vfptr;
  v67 = v5->m_tolerance.m_storage;
  v65 = v13;
  v66 = v11;
  ((void (__fastcall *)(hkpShape *, _BYTE **, __m128 *))v41[8].__first_virtual_table_function__)(v75, &v65, v39);
  v42 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v43 = (_QWORD *)v42[1];
  if ( (unsigned __int64)v43 < v42[3] )
  {
    *v43 = "Stexamine";
    v44 = __rdtsc();
    v45 = (signed __int64)(v43 + 2);
    *(_DWORD *)(v45 - 8) = v44;
    v42[1] = v45;
  }
  v46 = v39;
  LODWORD(v47) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(v5->m_tolerance.m_storage),
                                      (__m128)LODWORD(v5->m_tolerance.m_storage),
                                      0);
  if ( v28 >= 0 )
  {
    do
    {
      v48 = *v46;
      v49 = _mm_shuffle_ps(v48, v48, 255);
      if ( v49.m128_f32[0] <= v47 )
      {
        v50 = (__m128 *)v6->m_motion;
        v51 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_sub_ps(
                    _mm_sub_ps(
                      (__m128)0i64,
                      _mm_shuffle_ps(
                        *(__m128 *)((char *)v46 + v13 - (_BYTE *)v39),
                        *(__m128 *)((char *)v46 + v13 - (_BYTE *)v39),
                        255)),
                    v49),
                  v48),
                *(__m128 *)((char *)v46 + v13 - (_BYTE *)v39));
        v52 = _mm_mul_ps(_mm_shuffle_ps(v48, v48, 85), v50[1]);
        v53 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v51, v51, 85), v50[1]),
                    _mm_mul_ps(_mm_shuffle_ps(v51, v51, 0), *v50)),
                  _mm_mul_ps(_mm_shuffle_ps(v51, v51, 170), v50[2])),
                v50[3]);
        v54 = _mm_mul_ps(_mm_shuffle_ps(v48, v48, 0), *v50);
        v55 = _mm_mul_ps(_mm_shuffle_ps(v48, v48, 170), v50[2]);
        v56 = v76->vfptr;
        v68 = v53;
        v71 = v74;
        v72 = v6;
        v57 = _mm_add_ps(_mm_add_ps(v52, v54), v55);
        v69 = _mm_shuffle_ps(v57, _mm_unpackhi_ps(v57, v49), 196);
        v70 = v69;
        ((void (__fastcall *)(hkpCdPointCollector *, __m128 *, _QWORD *))v56->addCdPoint)(v76, &v68, v42);
      }
      ++v46;
      --v28;
    }
    while ( v28 >= 0 );
    v14 = (16 * v11 + 127) & 0xFFFFFF80;
  }
  v58 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v59 = (v14 + 15) & 0xFFFFFFF0;
  if ( v14 > v58->m_slabSize || (char *)v39 + v59 != v58->m_cur || v58->m_firstNonLifoEnd == v39 )
    hkLifoAllocator::slowBlockFree(v58, v39, v59);
  else
    v58->m_cur = v39;
  v60 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( v14 > v60->m_slabSize || &v13[v59] != v60->m_cur || v60->m_firstNonLifoEnd == v13 )
    hkLifoAllocator::slowBlockFree(v60, v13, v59);
  else
    v60->m_cur = v13;
  v61 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v62 = (_QWORD *)v61[1];
  if ( (unsigned __int64)v62 < v61[3] )
  {
    *v62 = "lt";
    v63 = __rdtsc();
    v64 = (signed __int64)(v62 + 2);
    *(_DWORD *)(v64 - 8) = v63;
    v61[1] = v64;
  }
}(hkMonitorStream__m_instance.m_slotID);
  v62 = (_QWORD *)v61[1];
  if ( (unsigned __int64)v62 < v61[3] )
  {
    *v62 = "lt";
    v63 = __rdtsc();
    v64 = (signed __int64)(

// File Line: 351
// RVA: 0xCFB980
void __fastcall hkHeightFieldRayForwardingCollector::addRayHit(hkHeightFieldRayForwardingCollector *this, hkpCdBody *cdBody, hkpShapeRayCastCollectorOutput *hitInfo)
{
  hkVector4f v3; // xmm1
  __m128 *v4; // rax
  hkHeightFieldRayForwardingCollector *v5; // rbx
  __m128 v6; // xmm3
  __m128 v7; // xmm2
  __m128 v8; // xmm1
  unsigned int v9; // xmm0_4
  hkpCdBody *v10; // rax
  hkpCdPointCollector *v11; // rcx
  __m128 v12; // xmm2
  __int128 v13; // ST30_16
  __m128 v14; // [rsp+40h] [rbp-48h]
  __int128 v15; // [rsp+50h] [rbp-38h]
  __int128 v16; // [rsp+60h] [rbp-28h]
  hkpCdBody *v17; // [rsp+70h] [rbp-18h]
  hkpCdBody *v18; // [rsp+78h] [rbp-10h]

  v3.m_quad = (__m128)hitInfo->m_normal;
  v4 = (__m128 *)cdBody->m_motion;
  v5 = this;
  v6 = _mm_add_ps(
         _mm_mul_ps(
           _mm_shuffle_ps((__m128)LODWORD(hitInfo->m_hitFraction), (__m128)LODWORD(hitInfo->m_hitFraction), 0),
           this->m_path.m_quad),
         this->m_currentFrom.m_quad);
  v7 = _mm_add_ps(
         _mm_mul_ps(_mm_shuffle_ps(v3.m_quad, v3.m_quad, 85), v4[1]),
         _mm_mul_ps(_mm_shuffle_ps(hitInfo->m_normal.m_quad, hitInfo->m_normal.m_quad, 0), *v4));
  v8 = _mm_mul_ps(_mm_shuffle_ps(v3.m_quad, v3.m_quad, 170), v4[2]);
  v9 = LODWORD(this->m_currentRadius) ^ _xmm[0];
  v10 = this->m_csBody;
  v11 = this->m_collector;
  v12 = _mm_add_ps(v7, v8);
  v13 = (__int128)v12;
  HIDWORD(v13) = LODWORD(hitInfo->m_hitFraction);
  v15 = v13;
  v14 = _mm_add_ps(v6, _mm_mul_ps(_mm_shuffle_ps((__m128)v9, (__m128)v9, 0), v12));
  v18 = cdBody;
  v17 = v10;
  v16 = v13;
  v11->vfptr->addCdPoint(v11, (hkpCdPoint *)&v14);
  v5->m_earlyOutHitFraction = fminf(v5->m_collector->m_earlyOutDistance, v5->m_earlyOutHitFraction);
}

// File Line: 383
// RVA: 0xCFB250
void __fastcall hkpHeightFieldAgent::staticLinearCast(hkpCdBody *csBody, hkpCdBody *hfBody, hkpLinearCastCollisionInput *input, hkpCdPointCollector *collector, hkpCdPointCollector *startCollector)
{
  hkpCdBody *v5; // rsi
  hkpLinearCastCollisionInput *v6; // rbp
  hkpCdBody *v7; // r14
  _QWORD *v8; // rcx
  unsigned __int64 v9; // r10
  unsigned __int64 v10; // rax
  _QWORD *v11; // r8
  _QWORD *v12; // rcx
  unsigned __int64 v13; // rax
  signed __int64 v14; // rcx
  hkpShape *v15; // r15
  hkpShape *v16; // r13
  __int64 v17; // r12
  hkLifoAllocator *v18; // rax
  char *v19; // rdi
  int v20; // ebx
  char *v21; // rcx
  __m128 *v22; // rcx
  __m128 v23; // xmm3
  __m128 v24; // xmm1
  __m128 v25; // xmm2
  __m128 v26; // xmm7
  __int64 v27; // r15
  _QWORD *v28; // rax
  _QWORD *v29; // rcx
  _QWORD *v30; // r8
  unsigned __int64 v31; // rax
  signed __int64 v32; // rcx
  int v33; // xmm0_4
  __int64 v34; // rbp
  __m128 v35; // xmm6
  __m128 *v36; // rax
  __m128 v37; // xmm4
  __m128 v38; // xmm5
  __m128 v39; // xmm6
  __m128 v40; // xmm2
  hkBaseObjectVtbl *v41; // rax
  hkLifoAllocator *v42; // rax
  int v43; // er8
  _QWORD *v44; // rax
  _QWORD *v45; // rcx
  _QWORD *v46; // r8
  unsigned __int64 v47; // rax
  signed __int64 v48; // rcx
  __m128 v49; // [rsp+20h] [rbp-128h]
  __m128 v50; // [rsp+30h] [rbp-118h]
  int v51; // [rsp+40h] [rbp-108h]
  __int64 v52; // [rsp+48h] [rbp-100h]
  __int64 v53; // [rsp+50h] [rbp-F8h]
  __int64 v54; // [rsp+58h] [rbp-F0h]
  int v55; // [rsp+60h] [rbp-E8h]
  int v56; // [rsp+64h] [rbp-E4h]
  void **v57; // [rsp+70h] [rbp-D8h]
  int v58; // [rsp+78h] [rbp-D0h]
  __m128 v59; // [rsp+80h] [rbp-C8h]
  int v60; // [rsp+90h] [rbp-B8h]
  __int128 v61; // [rsp+A0h] [rbp-A8h]
  hkpCdBody *v62; // [rsp+B0h] [rbp-98h]
  hkpCdPointCollector *v63; // [rsp+B8h] [rbp-90h]
  hkTransformf v64; // [rsp+C0h] [rbp-88h]
  hkpCdPointCollector *v65; // [rsp+168h] [rbp+20h]

  v65 = collector;
  v5 = csBody;
  v6 = input;
  v7 = hfBody;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = v8[1];
  if ( v9 < v8[3] )
  {
    *(_QWORD *)v9 = "LtHeightField";
    *(_QWORD *)(v9 + 16) = "StClosestPoints";
    v10 = __rdtsc();
    *(_DWORD *)(v9 + 8) = v10;
    v8[1] = v9 + 24;
  }
  if ( startCollector )
    hkpHeightFieldAgent::staticGetClosestPoints(v5, v7, (hkpCollisionInput *)&v6->m_dispatcher, startCollector);
  v11 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v12 = (_QWORD *)v11[1];
  if ( (unsigned __int64)v12 < v11[3] )
  {
    *v12 = "StGetSpheres";
    v13 = __rdtsc();
    v14 = (signed __int64)(v12 + 2);
    *(_DWORD *)(v14 - 8) = v13;
    v11[1] = v14;
  }
  v15 = v5->m_shape;
  v16 = v7->m_shape;
  hkTransformf::setMulInverseMul(&v64, (hkTransformf *)v7->m_motion, (hkTransformf *)v5->m_motion);
  v17 = ((unsigned int (__fastcall *)(hkpShape *))v15->vfptr[5].__first_virtual_table_function__)(v15);
  v18 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v19 = (char *)v18->m_cur;
  v20 = (16 * v17 + 127) & 0xFFFFFF80;
  v21 = &v19[v20];
  if ( v20 > v18->m_slabSize || v21 > v18->m_end )
    v19 = (char *)hkLifoAllocator::allocateFromNewSlab(v18, v20);
  else
    v18->m_cur = v21;
  v22 = (__m128 *)v7->m_motion;
  v23 = v22[2];
  v24 = _mm_unpacklo_ps(*v22, v22[1]);
  v25 = _mm_movelh_ps(v24, v23);
  v26 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_shuffle_ps(v6->m_path.m_quad, v6->m_path.m_quad, 85),
              _mm_shuffle_ps(_mm_movehl_ps(v25, v24), v23, 212)),
            _mm_mul_ps(_mm_shuffle_ps(v6->m_path.m_quad, v6->m_path.m_quad, 0), v25)),
          _mm_mul_ps(
            _mm_shuffle_ps(_mm_unpackhi_ps(*v22, v22[1]), v23, 228),
            _mm_shuffle_ps(v6->m_path.m_quad, v6->m_path.m_quad, 170)));
  v27 = (__int64)v15->vfptr[6].__vecDelDtor((hkBaseObject *)&v15->vfptr, (unsigned int)v19);
  v28 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v29 = (_QWORD *)v28[1];
  v30 = v28;
  if ( (unsigned __int64)v29 < v28[3] )
  {
    *v29 = "StCastSpheres";
    v31 = __rdtsc();
    v32 = (signed __int64)(v29 + 2);
    *(_DWORD *)(v32 - 8) = v31;
    v30[1] = v32;
  }
  v33 = LODWORD(v6->m_maxExtraPenetration);
  v51 = 0;
  v52 = 0i64;
  v53 = 0i64;
  v56 = v33;
  v58 = (signed int)FLOAT_1_0;
  v54 = 0i64;
  v62 = v5;
  _mm_store_si128((__m128i *)&v61, (__m128i)v6->m_path.m_quad);
  v57 = &hkHeightFieldRayForwardingCollector::`vftable';
  v63 = v65;
  if ( (signed int)v17 > 0 )
  {
    v34 = v17;
    do
    {
      v35 = *(__m128 *)v27;
      v36 = (__m128 *)v5->m_motion;
      v55 = *(_DWORD *)(v27 + 12);
      v37 = _mm_shuffle_ps(v35, v35, 85);
      v38 = _mm_shuffle_ps(v35, v35, 0);
      v39 = _mm_shuffle_ps(v35, v35, 170);
      v49 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(v64.m_rotation.m_col0.m_quad, v38), _mm_mul_ps(v64.m_rotation.m_col1.m_quad, v37)),
                _mm_mul_ps(v64.m_rotation.m_col2.m_quad, v39)),
              v64.m_translation.m_quad);
      v50 = _mm_add_ps(v49, v26);
      v40 = _mm_add_ps(
              _mm_add_ps(_mm_add_ps(_mm_mul_ps(v36[1], v37), _mm_mul_ps(*v36, v38)), _mm_mul_ps(v36[2], v39)),
              v36[3]);
      v60 = v55;
      v41 = v16->vfptr;
      v59 = v40;
      ((void (__fastcall *)(hkpShape *, __m128 *, hkpCdBody *, void ***, unsigned __int64, unsigned __int64, unsigned __int64, unsigned __int64, _QWORD, __int64, __int64, __int64, _QWORD))v41[9].__vecDelDtor)(
        v16,
        &v49,
        v7,
        &v57,
        v49.m128_u64[0],
        v49.m128_u64[1],
        v50.m128_u64[0],
        v50.m128_u64[1],
        *(_QWORD *)&v51,
        v52,
        v53,
        v54,
        *(_QWORD *)&v55);
      v27 += 16i64;
      --v34;
    }
    while ( v34 );
  }
  v42 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v43 = (v20 + 15) & 0xFFFFFFF0;
  if ( v20 > v42->m_slabSize || &v19[v43] != v42->m_cur || v42->m_firstNonLifoEnd == v19 )
    hkLifoAllocator::slowBlockFree(v42, v19, v43);
  else
    v42->m_cur = v19;
  v44 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v45 = (_QWORD *)v44[1];
  v46 = v44;
  if ( (unsigned __int64)v45 < v44[3] )
  {
    *v45 = "lt";
    v47 = __rdtsc();
    v48 = (signed __int64)(v45 + 2);
    *(_DWORD *)(v48 - 8) = v47;
    v46[1] = v48;
  }
}

// File Line: 436
// RVA: 0xCFB210
void __fastcall hkpHeightFieldAgent::linearCast(hkpHeightFieldAgent *this, hkpCdBody *csBody, hkpCdBody *hfBody, hkpLinearCastCollisionInput *input, hkpCdPointCollector *collector, hkpCdPointCollector *startCollector)
{
  hkpHeightFieldAgent::staticLinearCast(csBody, hfBody, input, collector, startCollector);
}

