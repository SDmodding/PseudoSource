// File Line: 19
// RVA: 0xD25270
void __fastcall hkpMultiSphereTriangleAgent::registerAgent(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher *v1; // rbx
  hkpCollisionDispatcher::AgentFuncs f; // [rsp+20h] [rbp-38h]

  f.m_createFunc = hkpMultiSphereTriangleAgent::createTriangleMultiSphereAgent;
  f.m_getPenetrationsFunc = hkpSymmetricAgentLinearCast<hkpMultiSphereTriangleAgent>::staticGetPenetrations;
  v1 = dispatcher;
  f.m_getClosestPointFunc = hkpSymmetricAgentLinearCast<hkpMultiSphereTriangleAgent>::staticGetClosestPoints;
  *(_WORD *)&f.m_isFlipped.m_bool = 1;
  f.m_linearCastFunc = hkpSymmetricAgentLinearCast<hkpCapsuleTriangleAgent>::staticLinearCast;
  hkpCollisionDispatcher::registerCollisionAgent(dispatcher, &f, TRIANGLE, MULTI_SPHERE);
  f.m_createFunc = hkpMultiSphereTriangleAgent::createMultiSphereTriangleAgent;
  f.m_getPenetrationsFunc = hkpMultiSphereTriangleAgent::staticGetPenetrations;
  f.m_getClosestPointFunc = hkpMultiSphereTriangleAgent::staticGetClosestPoints;
  *(_WORD *)&f.m_isFlipped.m_bool = 0;
  f.m_linearCastFunc = hkpIterativeLinearCastAgent::staticLinearCast;
  hkpCollisionDispatcher::registerCollisionAgent(v1, &f, MULTI_SPHERE, TRIANGLE);
}

// File Line: 57
// RVA: 0xD25D10
hkpCollisionAgent *__fastcall hkpMultiSphereTriangleAgent::createTriangleMultiSphereAgent(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *contactMgr)
{
  hkpCdBody *v4; // rsi
  hkpContactMgr *v5; // rdi
  _QWORD **v6; // rax
  hkpCollisionAgent *result; // rax
  hkpCollisionAgent *v8; // rbx

  v4 = bodyA;
  v5 = contactMgr;
  v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkpCollisionAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v6[11] + 8i64))(v6[11], 56i64);
  v8 = result;
  if ( result )
  {
    result->m_contactMgr = v5;
    result->m_memSizeAndFlags = -1;
    result->m_referenceCount = 1;
    result->vfptr = (hkBaseObjectVtbl *)&hkpMultiSphereTriangleAgent::`vftable;
    result[1].m_contactMgr = (hkpContactMgr *)-1i64;
    result[2].vfptr = (hkBaseObjectVtbl *)-1i64;
    hkpCollideTriangleUtil::setupClosestPointTriangleCache(
      (hkVector4f *)&v4->m_shape[1].m_type,
      (hkpCollideTriangleUtil::ClosestPointTriangleCache *)&result[1]);
    v8->vfptr = (hkBaseObjectVtbl *)&hkpSymmetricAgentLinearCast<hkpMultiSphereTriangleAgent>::`vftable;
    result = v8;
  }
  return result;
}

// File Line: 63
// RVA: 0xD25C60
hkpCollisionAgent *__fastcall hkpMultiSphereTriangleAgent::createMultiSphereTriangleAgent(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *contactMgr)
{
  hkpContactMgr *v4; // rdi
  hkpCdBody *v5; // rsi
  _QWORD **v6; // rax
  hkpCollisionAgent *result; // rax
  hkpCollisionAgent *v8; // rbx

  v4 = contactMgr;
  v5 = bodyB;
  v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkpCollisionAgent *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v6[11] + 8i64))(v6[11], 56i64);
  v8 = result;
  if ( result )
  {
    result->m_contactMgr = v4;
    result->m_memSizeAndFlags = -1;
    result->m_referenceCount = 1;
    result->vfptr = (hkBaseObjectVtbl *)&hkpMultiSphereTriangleAgent::`vftable;
    result[1].m_contactMgr = (hkpContactMgr *)-1i64;
    result[2].vfptr = (hkBaseObjectVtbl *)-1i64;
    hkpCollideTriangleUtil::setupClosestPointTriangleCache(
      (hkVector4f *)&v5->m_shape[1].m_type,
      (hkpCollideTriangleUtil::ClosestPointTriangleCache *)&result[1]);
    result = v8;
  }
  return result;
}

// File Line: 73
// RVA: 0xD25BE0
void __fastcall hkpMultiSphereTriangleAgent::cleanup(hkpMultiSphereTriangleAgent *this, hkpConstraintOwner *constraintOwner)
{
  hkpConstraintOwner *v2; // rbp
  hkpMultiSphereTriangleAgent *v3; // rsi
  unsigned __int16 *v4; // rbx
  signed __int64 v5; // rdi
  __int64 v6; // rdx

  v2 = constraintOwner;
  v3 = this;
  v4 = this->m_contactPointId;
  v5 = 8i64;
  do
  {
    v6 = *v4;
    if ( (_WORD)v6 != -1 )
      ((void (__fastcall *)(hkpContactMgr *, __int64, hkpConstraintOwner *))v3->m_contactMgr->vfptr[2].__first_virtual_table_function__)(
        v3->m_contactMgr,
        v6,
        v2);
    ++v4;
    --v5;
  }
  while ( v5 );
  if ( v3 )
    v3->vfptr->__vecDelDtor((hkBaseObject *)&v3->vfptr, 1u);
}

// File Line: 86
// RVA: 0xD25F00
void __fastcall hkpMultiSphereTriangleAgent::processCollision(hkpMultiSphereTriangleAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpProcessCollisionInput *input, hkpProcessCollisionOutput *result)
{
  hkpMultiSphereTriangleAgent *v5; // r15
  hkpProcessCollisionInput *v6; // r13
  hkpCdBody *v7; // rbx
  hkpCdBody *v8; // rdi
  _QWORD *v9; // rax
  _QWORD *v10; // rcx
  _QWORD *v11; // r10
  unsigned __int64 v12; // rax
  signed __int64 v13; // rcx
  __m128 *v14; // rax
  hkpShape *v15; // r9
  hkpShape *v16; // r10
  __m128 v17; // xmm3
  __m128 v18; // xmm4
  __m128 v19; // xmm5
  __m128 v20; // xmm6
  hkEnum<enum hkcdShapeType::ShapeTypeEnum,unsigned char> *v21; // rax
  signed __int64 v22; // rdx
  char *v23; // r8
  __m128 v24; // xmm1
  __m128 *v25; // rax
  int v26; // er14
  __m128 v27; // xmm3
  __m128 v28; // xmm4
  __m128 v29; // xmm5
  __int64 v30; // rcx
  __m128 v31; // xmm6
  __m128 *v32; // rax
  __m128 v33; // xmm1
  hkVector4f *v34; // rdi
  _WORD *v35; // rbx
  signed __int64 v36; // r12
  hkpCollideTriangleUtil::ClosestPointTriangleCache *v37; // rcx
  float v38; // xmm6_4
  hkpProcessCdPoint *v39; // rbp
  __int16 v40; // ax
  __int64 v41; // rdx
  _QWORD *v42; // rax
  _QWORD *v43; // rcx
  _QWORD *v44; // r8
  unsigned __int64 v45; // rax
  signed __int64 v46; // rcx
  hkpShape *v47; // [rsp+48h] [rbp-120h]
  hkpCollideTriangleUtil::ClosestPointTriangleResult v48; // [rsp+50h] [rbp-118h]
  hkVector4f tri; // [rsp+70h] [rbp-F8h]
  hkVector4f position; // [rsp+A0h] [rbp-C8h]
  hkpCdBody *v51; // [rsp+178h] [rbp+10h]
  hkpCdBody *v52; // [rsp+180h] [rbp+18h]

  v52 = bodyB;
  v51 = bodyA;
  v5 = this;
  v6 = input;
  v7 = bodyB;
  v8 = bodyA;
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)v9[1];
  v11 = v9;
  if ( (unsigned __int64)v10 < v9[3] )
  {
    *v10 = "TtMultiSphereTri";
    v12 = __rdtsc();
    v13 = (signed __int64)(v10 + 2);
    *(_DWORD *)(v13 - 8) = v12;
    v11[1] = v13;
  }
  v14 = (__m128 *)v7->m_motion;
  v15 = v7->m_shape;
  v16 = v8->m_shape;
  v17 = *v14;
  v18 = v14[1];
  v19 = v14[2];
  v47 = v7->m_shape;
  v20 = v14[3];
  v21 = &v7->m_shape[2].m_type;
  v22 = 2i64;
  v23 = (char *)((char *)&tri - (char *)&v7->m_shape[1].m_type);
  do
  {
    v24 = *(__m128 *)&v21->m_storage;
    v21 -= 16;
    --v22;
    *(__m128 *)&v23[(_QWORD)v21 + 16] = _mm_add_ps(
                                          _mm_add_ps(
                                            _mm_add_ps(
                                              _mm_mul_ps(_mm_shuffle_ps(v24, v24, 85), v18),
                                              _mm_mul_ps(_mm_shuffle_ps(v24, v24, 0), v17)),
                                            _mm_mul_ps(_mm_shuffle_ps(v24, v24, 170), v19)),
                                          v20);
  }
  while ( v22 >= 0 );
  v25 = (__m128 *)v8->m_motion;
  v26 = LODWORD(v16[1].vfptr) - 1;
  v27 = *v25;
  v28 = v25[1];
  v29 = v25[2];
  v30 = v26;
  v31 = v25[3];
  v32 = (__m128 *)(&v16[1].m_type + 16 * v26);
  do
  {
    v33 = *v32;
    --v32;
    --v30;
    *(__m128 *)((char *)v32 + (char *)&position - (char *)&v16[1].m_type + 16) = _mm_add_ps(
                                                                                   _mm_add_ps(
                                                                                     _mm_add_ps(
                                                                                       _mm_mul_ps(
                                                                                         _mm_shuffle_ps(v33, v33, 85),
                                                                                         v28),
                                                                                       _mm_mul_ps(
                                                                                         _mm_shuffle_ps(v33, v33, 0),
                                                                                         v27)),
                                                                                     _mm_mul_ps(
                                                                                       _mm_shuffle_ps(v33, v33, 170),
                                                                                       v29)),
                                                                                   v31);
  }
  while ( v30 >= 0 );
  v34 = &position;
  if ( v26 >= 0 )
  {
    v35 = (_WORD *)((char *)v5 + 2 * (v26 + 20i64));
    v36 = &v16[1].m_type - (hkEnum<enum hkcdShapeType::ShapeTypeEnum,unsigned char> *)&position;
    v37 = &v5->m_closestPointTriangleCache;
    do
    {
      v38 = *(float *)((char *)&v34->m_quad.m128_f32[3] + v36) + *(float *)&v15[1].vfptr;
      hkpCollideTriangleUtil::closestPointTriangle(v34, &tri, v37, &v48, 0i64);
      if ( v48.distance >= (float)(v38 + v6->m_tolerance.m_storage) )
      {
        v41 = (unsigned __int16)*v35;
        if ( (_WORD)v41 != -1 )
        {
          ((void (__fastcall *)(hkpContactMgr *, __int64, hkpConstraintOwner *))v5->m_contactMgr->vfptr[2].__first_virtual_table_function__)(
            v5->m_contactMgr,
            v41,
            result->m_constraintOwner.m_storage);
          *v35 = -1;
        }
      }
      else
      {
        v39 = result->m_firstFreeContactPoint.m_storage;
        v39->m_contact.m_position.m_quad = _mm_add_ps(
                                             _mm_mul_ps(
                                               _mm_shuffle_ps(
                                                 (__m128)COERCE_UNSIGNED_INT(*(float *)&v47[1].vfptr - v48.distance),
                                                 (__m128)COERCE_UNSIGNED_INT(*(float *)&v47[1].vfptr - v48.distance),
                                                 0),
                                               v48.hitDirection.m_quad),
                                             v34->m_quad);
        v39->m_contact.m_separatingNormal = v48.hitDirection;
        v39->m_contact.m_separatingNormal.m_quad.m128_f32[3] = v48.distance - v38;
        if ( *v35 != -1
          || (v40 = ((__int64 (__fastcall *)(hkpContactMgr *, hkpCdBody *, hkpCdBody *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *, _QWORD, hkpProcessCdPoint *))v5->m_contactMgr->vfptr[1].__first_virtual_table_function__)(
                      v5->m_contactMgr,
                      v51,
                      v52,
                      v6,
                      result,
                      0i64,
                      v39),
              *v35 = v40,
              v40 != -1) )
        {
          ++result->m_firstFreeContactPoint.m_storage;
          v39->m_contactPointId = (unsigned __int16)*v35;
        }
      }
      v15 = v47;
      ++v34;
      --v35;
      --v26;
      v37 = &v5->m_closestPointTriangleCache;
    }
    while ( v26 >= 0 );
  }
  v42 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v43 = (_QWORD *)v42[1];
  v44 = v42;
  if ( (unsigned __int64)v43 < v42[3] )
  {
    *v43 = "Et";
    v45 = __rdtsc();
    v46 = (signed __int64)(v43 + 2);
    *(_DWORD *)(v46 - 8) = v45;
    v44[1] = v46;
  }
}

// File Line: 185
// RVA: 0xD25690
void __usercall hkpMultiSphereTriangleAgent::getClosestPoints(hkpMultiSphereTriangleAgent *this@<rcx>, hkpCdBody *bodyA@<rdx>, hkpCdBody *bodyB@<r8>, hkpCollisionInput *input@<r9>, __int64 a5@<rbx>, hkpCdPointCollector *collector)
{
  hkpMultiSphereTriangleAgent *v6; // r15
  hkpCollisionInput *v7; // r13
  hkpCdBody *v8; // rbx
  hkpCdBody *v9; // rdi
  _QWORD *v10; // rax
  _QWORD *v11; // rcx
  _QWORD *v12; // r10
  unsigned __int64 v13; // rax
  signed __int64 v14; // rcx
  __m128 *v15; // rax
  hkpShape *v16; // r14
  hkpShape *v17; // r9
  __m128 v18; // xmm3
  __m128 v19; // xmm4
  __m128 v20; // xmm5
  signed __int64 v21; // rcx
  signed __int64 v22; // rdx
  __m128 v23; // xmm6
  hkEnum<enum hkcdShapeType::ShapeTypeEnum,unsigned char> *v24; // rax
  __m128 v25; // xmm1
  __m128 *v26; // rax
  __int64 v27; // r8
  __m128 v28; // xmm3
  __m128 v29; // xmm4
  __m128 v30; // xmm5
  __m128 v31; // xmm6
  __int64 v32; // rcx
  __m128 *v33; // rax
  __m128 v34; // xmm1
  __int64 v35; // rdi
  signed __int64 v36; // rsi
  hkVector4f *v37; // rbx
  float v38; // xmm6_4
  unsigned int v39; // xmm0_4
  __int64 v40; // rax
  hkVector4f v41; // ST50_16
  __m128 v42; // xmm1
  _QWORD *v43; // rax
  _QWORD *v44; // rcx
  _QWORD *v45; // r8
  unsigned __int64 v46; // rax
  signed __int64 v47; // rcx
  __m128 v48; // [rsp+60h] [rbp-98h]
  __m128 v49; // [rsp+70h] [rbp-88h]
  __int64 v50; // [rsp+88h] [rbp-70h]
  hkpCdBody *v51; // [rsp+90h] [rbp-68h]
  hkpCollideTriangleUtil::ClosestPointTriangleResult result; // [rsp+98h] [rbp-60h]
  hkVector4f tri; // [rsp+B8h] [rbp-40h]
  hkVector4f position; // [rsp+E8h] [rbp-10h]
  __int64 v55; // [rsp+1C0h] [rbp+C8h]
  hkpCdBody *v56; // [rsp+1C8h] [rbp+D0h]
  __int64 *v57; // [rsp+1D8h] [rbp+E0h]

  v56 = bodyA;
  v55 = a5;
  v6 = this;
  v7 = input;
  v8 = bodyB;
  v9 = bodyA;
  v10 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = (_QWORD *)v10[1];
  v12 = v10;
  if ( (unsigned __int64)v11 < v10[3] )
  {
    *v11 = "TtMultiSphereTriangle";
    v13 = __rdtsc();
    v14 = (signed __int64)(v11 + 2);
    *(_DWORD *)(v14 - 8) = v13;
    v12[1] = v14;
  }
  v15 = (__m128 *)v8->m_motion;
  v16 = v8->m_shape;
  v17 = v9->m_shape;
  v18 = *v15;
  v19 = v15[1];
  v20 = v15[2];
  v21 = (signed __int64)&v8->m_shape[1].m_type;
  v22 = 2i64;
  v23 = v15[3];
  v24 = &v8->m_shape[2].m_type;
  do
  {
    v25 = *(__m128 *)&v24->m_storage;
    v24 -= 16;
    --v22;
    *(__m128 *)&v24[(_QWORD)&tri - v21 + 16].m_storage = _mm_add_ps(
                                                           _mm_add_ps(
                                                             _mm_add_ps(
                                                               _mm_mul_ps(_mm_shuffle_ps(v25, v25, 85), v19),
                                                               _mm_mul_ps(_mm_shuffle_ps(v25, v25, 0), v18)),
                                                             _mm_mul_ps(_mm_shuffle_ps(v25, v25, 170), v20)),
                                                           v23);
  }
  while ( v22 >= 0 );
  v26 = (__m128 *)v9->m_motion;
  v27 = SLODWORD(v17[1].vfptr);
  v28 = *v26;
  v29 = v26[1];
  v30 = v26[2];
  v31 = v26[3];
  v32 = (signed int)v27 - 1;
  v33 = (__m128 *)(&v17[1].m_type + 16 * v32);
  do
  {
    v34 = *v33;
    --v33;
    --v32;
    *(__m128 *)((char *)v33 + (char *)&position - (char *)&v17[1].m_type + 16) = _mm_add_ps(
                                                                                   _mm_add_ps(
                                                                                     _mm_add_ps(
                                                                                       _mm_mul_ps(
                                                                                         _mm_shuffle_ps(v34, v34, 85),
                                                                                         v29),
                                                                                       _mm_mul_ps(
                                                                                         _mm_shuffle_ps(v34, v34, 0),
                                                                                         v28)),
                                                                                     _mm_mul_ps(
                                                                                       _mm_shuffle_ps(v34, v34, 170),
                                                                                       v30)),
                                                                                   v31);
  }
  while ( v32 >= 0 );
  v35 = v27;
  if ( (signed int)v27 > 0 )
  {
    v36 = &v17[1].m_type - (hkEnum<enum hkcdShapeType::ShapeTypeEnum,unsigned char> *)&position;
    v37 = &position;
    do
    {
      v38 = *(float *)((char *)&v37->m_quad.m128_f32[3] + v36) + *(float *)&v16[1].vfptr;
      hkpCollideTriangleUtil::closestPointTriangle(v37, &tri, &v6->m_closestPointTriangleCache, &result, 0i64);
      if ( result.distance < (float)(v38 + v7->m_tolerance.m_storage) )
      {
        *(float *)&v39 = *(float *)&v16[1].vfptr - result.distance;
        v50 = v55;
        v51 = v56;
        v40 = *v57;
        v41.m_quad = (__m128)result.hitDirection;
        v41.m_quad.m128_f32[3] = result.distance - v38;
        v42 = _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps((__m128)v39, (__m128)v39, 0), result.hitDirection.m_quad),
                v37->m_quad);
        v49 = v41.m_quad;
        *(hkVector4f *)((char *)&v49 + 8) = (hkVector4f)v41.m_quad;
        v48 = v42;
        (*(void (__fastcall **)(__int64 *, __m128 *))(v40 + 8))(v57, &v48);
      }
      ++v37;
      --v35;
    }
    while ( v35 );
  }
  v43 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v44 = (_QWORD *)v43[1];
  v45 = v43;
  if ( (unsigned __int64)v44 < v43[3] )
  {
    *v44 = "Et";
    v46 = __rdtsc();
    v47 = (signed __int64)(v44 + 2);
    *(_DWORD *)(v47 - 8) = v46;
    v45[1] = v47;
  }
}

// File Line: 233
// RVA: 0xD25950
void __fastcall hkpMultiSphereTriangleAgent::staticGetClosestPoints(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdPointCollector *collector)
{
  hkpCdBody *v4; // rbx
  hkpCdPointCollector *v5; // r12
  hkpCollisionInput *v6; // r15
  hkpCdBody *v7; // r13
  _QWORD *v8; // r10
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  signed __int64 v11; // rcx
  __m128 *v12; // rax
  hkpShape *v13; // r14
  hkpShape *v14; // r8
  __m128 v15; // xmm3
  __m128 v16; // xmm4
  __m128 v17; // xmm5
  hkVector4f *v18; // r9
  signed __int64 v19; // rcx
  __m128 v20; // xmm6
  hkEnum<enum hkcdShapeType::ShapeTypeEnum,unsigned char> *v21; // rax
  __m128 v22; // xmm1
  __m128 *v23; // rax
  __int64 v24; // rdi
  signed __int64 v25; // rsi
  __m128 v26; // xmm3
  __m128 v27; // xmm4
  __m128 v28; // xmm5
  __m128 v29; // xmm6
  __int64 v30; // rdx
  __m128 *v31; // rax
  char *v32; // r8
  __m128 v33; // xmm1
  hkVector4f *v34; // rbx
  signed __int64 v35; // rsi
  float v36; // xmm6_4
  unsigned int v37; // xmm0_4
  hkpCdPointCollectorVtbl *v38; // rax
  _QWORD *v39; // r8
  _QWORD *v40; // rcx
  unsigned __int64 v41; // rax
  signed __int64 v42; // rcx
  hkpCollideTriangleUtil::ClosestPointTriangleCache cache; // [rsp+30h] [rbp-D0h]
  hkVector4f v44; // [rsp+50h] [rbp-B0h]
  __m128 v45; // [rsp+60h] [rbp-A0h]
  hkVector4f v46; // [rsp+70h] [rbp-90h]
  hkVector4f v47; // [rsp+80h] [rbp-80h]
  hkpCdBody *v48; // [rsp+90h] [rbp-70h]
  hkpCdBody *v49; // [rsp+98h] [rbp-68h]
  hkpCollideTriangleUtil::ClosestPointTriangleResult result; // [rsp+A0h] [rbp-60h]
  hkVector4f tri; // [rsp+C0h] [rbp-40h]
  hkVector4f position; // [rsp+F0h] [rbp-10h]
  hkpCdBody *v53; // [rsp+1C0h] [rbp+C0h]

  v53 = bodyA;
  v4 = bodyA;
  v5 = collector;
  v6 = input;
  v7 = bodyB;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtMultiSphereTriangle";
    v10 = __rdtsc();
    v11 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v11 - 8) = v10;
    v8[1] = v11;
  }
  v12 = (__m128 *)v7->m_motion;
  v13 = v7->m_shape;
  v14 = v4->m_shape;
  v15 = *v12;
  v16 = v12[1];
  v17 = v12[2];
  v18 = (hkVector4f *)&v7->m_shape[1].m_type;
  v19 = 2i64;
  v20 = v12[3];
  v21 = &v7->m_shape[2].m_type;
  do
  {
    v22 = *(__m128 *)&v21->m_storage;
    v21 -= 16;
    --v19;
    *(__m128 *)&v21[(char *)&tri - (char *)v18 + 16].m_storage = _mm_add_ps(
                                                                   _mm_add_ps(
                                                                     _mm_add_ps(
                                                                       _mm_mul_ps(_mm_shuffle_ps(v22, v22, 85), v16),
                                                                       _mm_mul_ps(_mm_shuffle_ps(v22, v22, 0), v15)),
                                                                     _mm_mul_ps(_mm_shuffle_ps(v22, v22, 170), v17)),
                                                                   v20);
  }
  while ( v19 >= 0 );
  v23 = (__m128 *)v4->m_motion;
  v24 = SLODWORD(v14[1].vfptr);
  v25 = (signed __int64)&v14[1].m_type;
  v26 = *v23;
  v27 = v23[1];
  v28 = v23[2];
  v29 = v23[3];
  v30 = (signed int)v24 - 1;
  v31 = (__m128 *)(&v14[1].m_type + 16 * v30);
  v32 = (char *)((char *)&position - (char *)&v14[1].m_type);
  do
  {
    v33 = *v31;
    --v31;
    --v30;
    *(__m128 *)((char *)v31 + (_QWORD)v32 + 16) = _mm_add_ps(
                                                    _mm_add_ps(
                                                      _mm_add_ps(
                                                        _mm_mul_ps(_mm_shuffle_ps(v33, v33, 85), v27),
                                                        _mm_mul_ps(_mm_shuffle_ps(v33, v33, 0), v26)),
                                                      _mm_mul_ps(_mm_shuffle_ps(v33, v33, 170), v28)),
                                                    v29);
  }
  while ( v30 >= 0 );
  hkpCollideTriangleUtil::setupClosestPointTriangleCache(v18, &cache);
  if ( v24 > 0 )
  {
    v34 = &position;
    v35 = v25 - (_QWORD)&position;
    do
    {
      v36 = *(float *)((char *)&v34->m_quad.m128_f32[3] + v35) + *(float *)&v13[1].vfptr;
      hkpCollideTriangleUtil::closestPointTriangle(v34, &tri, &cache, &result, 0i64);
      if ( result.distance < (float)(v36 + v6->m_tolerance.m_storage) )
      {
        *(float *)&v37 = *(float *)&v13[1].vfptr - result.distance;
        v48 = v53;
        v38 = v5->vfptr;
        v49 = v7;
        v44.m_quad = (__m128)result.hitDirection;
        v44.m_quad.m128_f32[3] = result.distance - v36;
        v46.m_quad = v44.m_quad;
        v47.m_quad = v44.m_quad;
        v45 = _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps((__m128)v37, (__m128)v37, 0), result.hitDirection.m_quad),
                v34->m_quad);
        v38->addCdPoint(v5, (hkpCdPoint *)&v45);
      }
      ++v34;
      --v24;
    }
    while ( v24 );
  }
  v39 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v40 = (_QWORD *)v39[1];
  if ( (unsigned __int64)v40 < v39[3] )
  {
    *v40 = "Et";
    v41 = __rdtsc();
    v42 = (signed __int64)(v40 + 2);
    *(_DWORD *)(v42 - 8) = v41;
    v39[1] = v42;
  }
}

// File Line: 286
// RVA: 0xD25320
void __fastcall hkpMultiSphereTriangleAgent::getPenetrations(hkpMultiSphereTriangleAgent *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdBodyPairCollector *collector)
{
  hkpShape *v5; // r10
  hkpShape *v6; // r15
  __m128 *v7; // rax
  hkpCdBody *v8; // r12
  hkEnum<enum hkcdShapeType::ShapeTypeEnum,unsigned char> *v9; // r9
  hkpMultiSphereTriangleAgent *v10; // r14
  hkpCdBody *v11; // r13
  __m128 v12; // xmm3
  __m128 v13; // xmm4
  __m128 v14; // xmm5
  signed __int64 v15; // rcx
  __m128 v16; // xmm6
  hkEnum<enum hkcdShapeType::ShapeTypeEnum,unsigned char> *v17; // rax
  __m128 v18; // xmm1
  __m128 *v19; // rax
  __int64 v20; // r8
  __m128 v21; // xmm3
  __m128 v22; // xmm4
  __m128 v23; // xmm5
  __m128 v24; // xmm6
  __int64 v25; // rcx
  __m128 *v26; // rax
  __m128 v27; // xmm1
  int v28; // edi
  __int64 v29; // rbx
  __int64 v30; // rbp
  float *v31; // rsi
  float v32; // xmm6_4
  hkpCollideTriangleUtil::ClosestPointTriangleResult result; // [rsp+30h] [rbp-108h]
  hkVector4f tri; // [rsp+50h] [rbp-E8h]
  char v35[144]; // [rsp+80h] [rbp-B8h]

  v5 = bodyA->m_shape;
  v6 = bodyB->m_shape;
  v7 = (__m128 *)bodyB->m_motion;
  v8 = bodyA;
  v9 = &bodyB->m_shape[1].m_type;
  v10 = this;
  v11 = bodyB;
  v12 = *v7;
  v13 = v7[1];
  v14 = v7[2];
  v15 = 2i64;
  v16 = v7[3];
  v17 = &bodyB->m_shape[2].m_type;
  do
  {
    v18 = *(__m128 *)&v17->m_storage;
    v17 -= 16;
    --v15;
    *(__m128 *)&v17[(char *)&tri - (char *)v9 + 16].m_storage = _mm_add_ps(
                                                                  _mm_add_ps(
                                                                    _mm_add_ps(
                                                                      _mm_mul_ps(_mm_shuffle_ps(v18, v18, 85), v13),
                                                                      _mm_mul_ps(_mm_shuffle_ps(v18, v18, 0), v12)),
                                                                    _mm_mul_ps(_mm_shuffle_ps(v18, v18, 170), v14)),
                                                                  v16);
  }
  while ( v15 >= 0 );
  v19 = (__m128 *)bodyA->m_motion;
  v20 = SLODWORD(v5[1].vfptr);
  v21 = *v19;
  v22 = v19[1];
  v23 = v19[2];
  v24 = v19[3];
  v25 = (signed int)v20 - 1;
  v26 = (__m128 *)(&v5[1].m_type + 16 * v25);
  do
  {
    v27 = *v26;
    --v26;
    --v25;
    *(__m128 *)((char *)v26 + v35 - (char *)&v5[1].m_type + 16) = _mm_add_ps(
                                                                    _mm_add_ps(
                                                                      _mm_add_ps(
                                                                        _mm_mul_ps(_mm_shuffle_ps(v27, v27, 85), v22),
                                                                        _mm_mul_ps(_mm_shuffle_ps(v27, v27, 0), v21)),
                                                                      _mm_mul_ps(_mm_shuffle_ps(v27, v27, 170), v23)),
                                                                    v24);
  }
  while ( v25 >= 0 );
  v28 = 0;
  v29 = 0i64;
  v30 = v20;
  if ( (signed int)v20 > 0 )
  {
    v31 = (float *)((char *)&v5[1].m_userData + 4);
    while ( 1 )
    {
      v32 = *v31 + *(float *)&v6[1].vfptr;
      hkpCollideTriangleUtil::closestPointTriangle(
        (hkVector4f *)&v35[16 * v28],
        &tri,
        &v10->m_closestPointTriangleCache,
        &result,
        0i64);
      if ( result.distance < v32 )
        break;
      ++v29;
      ++v28;
      v31 += 4;
      if ( v29 >= v30 )
        return;
    }
    collector->vfptr->addCdBodyPair(collector, v8, v11);
  }
}

// File Line: 325
// RVA: 0xD254E0
void __fastcall hkpMultiSphereTriangleAgent::staticGetPenetrations(hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpCdBodyPairCollector *collector)
{
  hkpShape *v4; // r14
  hkpShape *v5; // r8
  __m128 *v6; // rax
  hkpCdBody *v7; // r13
  hkVector4f *v8; // r10
  hkpCdBody *v9; // r12
  hkpCdBodyPairCollector *v10; // r15
  __m128 v11; // xmm3
  __m128 v12; // xmm4
  __m128 v13; // xmm5
  signed __int64 v14; // rcx
  __m128 v15; // xmm6
  hkEnum<enum hkcdShapeType::ShapeTypeEnum,unsigned char> *v16; // rax
  __m128 v17; // xmm1
  __m128 *v18; // rax
  __int64 v19; // rbp
  signed __int64 v20; // rdi
  __m128 v21; // xmm3
  __m128 v22; // xmm4
  __m128 v23; // xmm5
  __m128 v24; // xmm6
  __int64 v25; // rdx
  __m128 *v26; // rax
  char *v27; // r8
  __m128 v28; // xmm1
  int v29; // esi
  __int64 v30; // rbx
  float *v31; // rdi
  float v32; // xmm6_4
  hkpCollideTriangleUtil::ClosestPointTriangleCache cache; // [rsp+30h] [rbp-118h]
  hkpCollideTriangleUtil::ClosestPointTriangleResult result; // [rsp+40h] [rbp-108h]
  hkVector4f tri; // [rsp+60h] [rbp-E8h]
  char v36[144]; // [rsp+90h] [rbp-B8h]

  v4 = bodyB->m_shape;
  v5 = bodyA->m_shape;
  v6 = (__m128 *)bodyB->m_motion;
  v7 = bodyB;
  v8 = (hkVector4f *)&bodyB->m_shape[1].m_type;
  v9 = bodyA;
  v10 = collector;
  v11 = *v6;
  v12 = v6[1];
  v13 = v6[2];
  v14 = 2i64;
  v15 = v6[3];
  v16 = &bodyB->m_shape[2].m_type;
  do
  {
    v17 = *(__m128 *)&v16->m_storage;
    v16 -= 16;
    --v14;
    *(__m128 *)&v16[(char *)&tri - (char *)v8 + 16].m_storage = _mm_add_ps(
                                                                  _mm_add_ps(
                                                                    _mm_add_ps(
                                                                      _mm_mul_ps(_mm_shuffle_ps(v17, v17, 85), v12),
                                                                      _mm_mul_ps(_mm_shuffle_ps(v17, v17, 0), v11)),
                                                                    _mm_mul_ps(_mm_shuffle_ps(v17, v17, 170), v13)),
                                                                  v15);
  }
  while ( v14 >= 0 );
  v18 = (__m128 *)v9->m_motion;
  v19 = SLODWORD(v5[1].vfptr);
  v20 = (signed __int64)&v5[1].m_type;
  v21 = *v18;
  v22 = v18[1];
  v23 = v18[2];
  v24 = v18[3];
  v25 = (signed int)v19 - 1;
  v26 = (__m128 *)(&v5[1].m_type + 16 * v25);
  v27 = (char *)(v36 - (char *)&v5[1].m_type);
  do
  {
    v28 = *v26;
    --v26;
    --v25;
    *(__m128 *)((char *)v26 + (_QWORD)v27 + 16) = _mm_add_ps(
                                                    _mm_add_ps(
                                                      _mm_add_ps(
                                                        _mm_mul_ps(_mm_shuffle_ps(v28, v28, 85), v22),
                                                        _mm_mul_ps(_mm_shuffle_ps(v28, v28, 0), v21)),
                                                      _mm_mul_ps(_mm_shuffle_ps(v28, v28, 170), v23)),
                                                    v24);
  }
  while ( v25 >= 0 );
  hkpCollideTriangleUtil::setupClosestPointTriangleCache(v8, &cache);
  v29 = 0;
  v30 = 0i64;
  if ( v19 > 0 )
  {
    v31 = (float *)(v20 + 12);
    while ( 1 )
    {
      v32 = *v31 + *(float *)&v4[1].vfptr;
      hkpCollideTriangleUtil::closestPointTriangle((hkVector4f *)&v36[16 * v29], &tri, &cache, &result, 0i64);
      if ( result.distance < v32 )
        break;
      ++v30;
      ++v29;
      v31 += 4;
      if ( v30 >= v19 )
        return;
    }
    v10->vfptr->addCdBodyPair(v10, v9, v7);
  }
}

