// File Line: 34
// RVA: 0x132E450
__int64 __fastcall hkpConstraintPivotsUtil::findClosestShapeKey(
        hkpWorld *world,
        hkpShape *shape,
        hkVector4f *pivotInBodySpace)
{
  __m128 m_quad; // xmm0
  hkpCollisionDispatcher *m_collisionDispatcher; // r8
  __int64 m_storage; // rcx
  unsigned int v9; // r14d
  void (__fastcall *m_getClosestPointFunc)(hkpCdBody *, hkpCdBody *, hkpCollisionInput *, hkpCdPointCollector *); // rbx
  __int128 *m_collisionInput; // rax
  __int128 v12; // xmm1
  hkpShape *v14; // [rsp+20h] [rbp-E0h] BYREF
  int v15; // [rsp+28h] [rbp-D8h]
  hkVector4f *v16; // [rsp+30h] [rbp-D0h]
  __int64 v17; // [rsp+38h] [rbp-C8h]
  hkpSphereShape *v18; // [rsp+40h] [rbp-C0h] BYREF
  int v19; // [rsp+48h] [rbp-B8h]
  __int128 *v20; // [rsp+50h] [rbp-B0h]
  __int64 v21; // [rsp+58h] [rbp-A8h]
  hkpCollisionFilter v22; // [rsp+60h] [rbp-A0h] BYREF
  __int128 v23; // [rsp+B0h] [rbp-50h] BYREF
  __int128 v24; // [rsp+C0h] [rbp-40h]
  __int128 v25; // [rsp+D0h] [rbp-30h]
  __int128 v26; // [rsp+E0h] [rbp-20h]
  __int128 v27; // [rsp+F0h] [rbp-10h]
  __int128 v28; // [rsp+100h] [rbp+0h]
  void **v29; // [rsp+110h] [rbp+10h] BYREF
  float v30; // [rsp+118h] [rbp+18h]
  __m128 v31; // [rsp+130h] [rbp+30h]
  __int64 v32; // [rsp+140h] [rbp+40h]
  unsigned int v33; // [rsp+158h] [rbp+58h]
  __int128 v34[4]; // [rsp+170h] [rbp+70h] BYREF
  hkpSphereShape v35; // [rsp+1B0h] [rbp+B0h] BYREF

  hkpSphereShape::hkpSphereShape(&v35, 0.0099999998);
  m_quad = pivotInBodySpace->m_quad;
  m_collisionDispatcher = world->m_collisionDispatcher;
  m_storage = (unsigned __int8)shape->m_type.m_storage;
  v19 = -1;
  v14 = shape;
  v34[3] = (__int128)m_quad;
  v34[0] = (__int128)transform.m_quad;
  v15 = -1;
  v9 = 0;
  v34[1] = (__int128)direction.m_quad;
  v18 = &v35;
  v34[2] = (__int128)stru_141A71280.m_quad;
  v21 = 0i64;
  v17 = 0i64;
  v32 = 0i64;
  v20 = v34;
  v30 = FLOAT_3_40282e38;
  v31 = _mm_shuffle_ps(v31, _mm_unpackhi_ps(v31, (__m128)xmmword_141A712A0), 196);
  v16 = &transform;
  v29 = &hkpClosestCdPointCollector::`vftable;
  m_getClosestPointFunc = m_collisionDispatcher->m_agent2Func[(unsigned __int8)m_collisionDispatcher->m_agent2Types[(unsigned __int8)v35.m_type.m_storage][m_storage]].m_getClosestPointFunc;
  m_collisionInput = (__int128 *)world->m_collisionInput;
  v23 = *m_collisionInput;
  v24 = m_collisionInput[1];
  v25 = m_collisionInput[2];
  v26 = m_collisionInput[3];
  v27 = m_collisionInput[4];
  v12 = m_collisionInput[5];
  *(float *)&v24 = FLOAT_1_70141e38;
  v28 = v12;
  hkpCollisionFilter::hkpCollisionFilter(&v22);
  v22.hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpNullCollisionFilter::`vftable{for `hkReferencedObject};
  v22.hkpCollidableCollidableFilter::vfptr = (hkpCollidableCollidableFilterVtbl *)&hkpNullCollisionFilter::`vftable{for `hkpCollidableCollidableFilter};
  v22.hkpShapeCollectionFilter::vfptr = (hkpShapeCollectionFilterVtbl *)&hkpNullCollisionFilter::`vftable{for `hkpShapeCollectionFilter};
  v22.hkpRayShapeCollectionFilter::vfptr = (hkpRayShapeCollectionFilterVtbl *)&hkpNullCollisionFilter::`vftable{for `hkpRayShapeCollectionFilter};
  v22.m_type.m_storage = 1;
  v22.hkpRayCollidableFilter::vfptr = (hkpRayCollidableFilterVtbl *)&hkpNullCollisionFilter::`vftable{for `hkpRayCollidableFilter};
  *((_QWORD *)&v24 + 1) = &v22;
  m_getClosestPointFunc((hkpCdBody *)&v18, (hkpCdBody *)&v14, (hkpCollisionInput *)&v23, (hkpCdPointCollector *)&v29);
  if ( v32 )
    v9 = v33;
  hkpNullCollisionFilter::~hkpNullCollisionFilter((hkpNullCollisionFilter *)&v22);
  return v9;
}

