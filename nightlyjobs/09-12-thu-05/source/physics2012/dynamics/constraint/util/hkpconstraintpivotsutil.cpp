// File Line: 34
// RVA: 0x132E450
__int64 __fastcall hkpConstraintPivotsUtil::findClosestShapeKey(hkpWorld *world, hkpShape *shape, hkVector4f *pivotInBodySpace)
{
  hkpWorld *v3; // rsi
  hkVector4f *v4; // rbx
  hkpShape *v5; // rdi
  __int128 v6; // xmm0
  hkpCollisionDispatcher *v7; // r8
  __int64 v8; // rcx
  unsigned int v9; // er14
  void (__fastcall *v10)(hkpSphereShape **, hkpShape **, __int128 *, void ***, hkpShape *, _QWORD, hkVector4f *, _QWORD, hkpSphereShape *, _QWORD, __m128 *, _QWORD, void **); // rbx
  __int128 *v11; // rax
  __int128 v12; // xmm1
  hkpShape *v14; // [rsp+20h] [rbp-E0h]
  int v15; // [rsp+28h] [rbp-D8h]
  hkVector4f *v16; // [rsp+30h] [rbp-D0h]
  __int64 v17; // [rsp+38h] [rbp-C8h]
  hkpSphereShape *v18; // [rsp+40h] [rbp-C0h]
  int v19; // [rsp+48h] [rbp-B8h]
  __m128 *v20; // [rsp+50h] [rbp-B0h]
  __int64 v21; // [rsp+58h] [rbp-A8h]
  hkpCollisionFilter v22; // [rsp+60h] [rbp-A0h]
  __int128 v23; // [rsp+B0h] [rbp-50h]
  __int128 v24; // [rsp+C0h] [rbp-40h]
  __int128 v25; // [rsp+D0h] [rbp-30h]
  __int128 v26; // [rsp+E0h] [rbp-20h]
  __int128 v27; // [rsp+F0h] [rbp-10h]
  __int128 v28; // [rsp+100h] [rbp+0h]
  void **v29; // [rsp+110h] [rbp+10h]
  float v30; // [rsp+118h] [rbp+18h]
  __m128 v31; // [rsp+130h] [rbp+30h]
  __int64 v32; // [rsp+140h] [rbp+40h]
  unsigned int v33; // [rsp+158h] [rbp+58h]
  __m128 v34; // [rsp+170h] [rbp+70h]
  __m128 v35; // [rsp+180h] [rbp+80h]
  __m128 v36; // [rsp+190h] [rbp+90h]
  __int128 v37; // [rsp+1A0h] [rbp+A0h]
  hkpSphereShape v38; // [rsp+1B0h] [rbp+B0h]

  v3 = world;
  v4 = pivotInBodySpace;
  v5 = shape;
  hkpSphereShape::hkpSphereShape(&v38, 0.0099999998);
  v6 = (__int128)v4->m_quad;
  v7 = v3->m_collisionDispatcher;
  v8 = (unsigned __int8)v5->m_type.m_storage;
  v19 = -1;
  v14 = v5;
  v37 = v6;
  v34 = transform.m_quad;
  v15 = -1;
  v9 = 0;
  v35 = direction.m_quad;
  v18 = &v38;
  v36 = stru_141A71280.m_quad;
  v21 = 0i64;
  v17 = 0i64;
  v32 = 0i64;
  v20 = &v34;
  v30 = FLOAT_3_40282e38;
  v31 = _mm_shuffle_ps(v31, _mm_unpackhi_ps(v31, (__m128)xmmword_141A712A0), 196);
  v16 = &transform;
  v29 = &hkpClosestCdPointCollector::`vftable;
  v10 = (void (__fastcall *)(hkpSphereShape **, hkpShape **, __int128 *, void ***, hkpShape *, _QWORD, hkVector4f *, _QWORD, hkpSphereShape *, _QWORD, __m128 *, _QWORD, void **))*((_QWORD *)&v7->vfptr + 5 * ((unsigned __int8)v7->m_agent2Types[(unsigned __int8)v38.m_type.m_storage][v8] + 79i64));
  v11 = (__int128 *)v3->m_collisionInput;
  v23 = *v11;
  v24 = v11[1];
  v25 = v11[2];
  v26 = v11[3];
  v27 = v11[4];
  v12 = v11[5];
  *(float *)&v24 = FLOAT_1_70141e38;
  v28 = v12;
  hkpCollisionFilter::hkpCollisionFilter(&v22);
  v22.vfptr = (hkpCollidableCollidableFilterVtbl *)&hkpNullCollisionFilter::`vftable{for `hkpCollidableCollidableFilter};
  v22.vfptr = (hkpShapeCollectionFilterVtbl *)&hkpNullCollisionFilter::`vftable{for `hkpShapeCollectionFilter};
  v22.vfptr = (hkpRayShapeCollectionFilterVtbl *)&hkpNullCollisionFilter::`vftable{for `hkpRayShapeCollectionFilter};
  v22.m_type.m_storage = 1;
  v22.vfptr = (hkpRayCollidableFilterVtbl *)&hkpNullCollisionFilter::`vftable{for `hkpRayCollidableFilter};
  *((_QWORD *)&v24 + 1) = &v22;
  v10(
    &v18,
    &v14,
    &v23,
    &v29,
    v5,
    *(_QWORD *)&v15,
    &transform,
    0i64,
    &v38,
    *(_QWORD *)&v19,
    &v34,
    0i64,
    &hkpNullCollisionFilter::`vftable{for `hkReferencedObject});
  if ( v32 )
    v9 = v33;
  hkpNullCollisionFilter::~hkpNullCollisionFilter((hkpNullCollisionFilter *)&v22);
  return v9;
}

