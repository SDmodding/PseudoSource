// File Line: 40
// RVA: 0xD2F680
void __fastcall hkpCollectionAgent3::initAgentFunc(hkpCollisionDispatcher::Agent3Funcs *f)
{
  hkpCollisionDispatcher::Agent3Funcs *v1; // rbx

  v1 = f;
  hkListAgent3::initAgentFunc(f);
  v1->m_processFunc = (void *(__fastcall *)(hkpAgent3ProcessInput *, hkpAgentEntry *, void *, hkVector4f *, hkpProcessCollisionOutput *))hkpCollectionAgent3::process;
}

// File Line: 48
// RVA: 0xD2F620
void __fastcall hkpCollectionAgent3::registerAgent3(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher *v1; // rbx
  hkpCollisionDispatcher::Agent3Funcs f; // [rsp+20h] [rbp-68h]

  v1 = dispatcher;
  *(_WORD *)&f.m_isPredictive.m_bool = 0;
  f.m_reusePreviousEntry.m_bool = 0;
  f.m_updateFilterFunc = 0i64;
  f.m_invalidateTimFunc = 0i64;
  f.m_warpTimeFunc = 0i64;
  f.m_sepNormalFunc = 0i64;
  hkpCollectionAgent3::initAgentFunc(&f);
  hkpCollisionDispatcher::registerAgent3(v1, &f, CONVEX, COLLECTION);
}

// File Line: 110
// RVA: 0xD2F3C0
signed __int64 __fastcall hkpCollectionAgent3::process(hkpAgent3ProcessInput *input, hkpAgentEntry *entry, void *agentData, hkVector4f *separatingNormal, hkpProcessCollisionOutput *output)
{
  hkpAgent3ProcessInput *v5; // rdi
  hkVector4f *v6; // rsi
  void *v7; // r14
  hkpAgentEntry *v8; // r15
  _QWORD *v9; // rax
  _QWORD *v10; // rcx
  _QWORD *v11; // r10
  unsigned __int64 v12; // rax
  signed __int64 v13; // rcx
  __int128 v14; // xmm1
  __int128 v15; // xmm0
  hkVector4f v16; // xmm1
  hkVector4f v17; // xmm0
  hkVector4f v18; // xmm1
  hkVector4f v19; // xmm0
  __int128 v20; // xmm1
  hkpShape *v21; // rcx
  hkpCdBody *v22; // rdx
  __int64 v23; // rax
  __int64 v24; // r8
  hkpCdBody *v25; // rax
  const void *v26; // rcx
  signed __int64 v27; // rbx
  int v28; // er9
  _QWORD *v29; // r8
  _QWORD *v30; // rcx
  unsigned __int64 v31; // rax
  signed __int64 v32; // rcx
  __int64 v34; // [rsp+30h] [rbp-D0h]
  int v35; // [rsp+38h] [rbp-C8h]
  __int128 v36; // [rsp+40h] [rbp-C0h]
  char v37; // [rsp+50h] [rbp-B0h]
  char v38; // [rsp+51h] [rbp-AFh]
  __int16 v39; // [rsp+52h] [rbp-AEh]
  int v40; // [rsp+54h] [rbp-ACh]
  __int16 v41; // [rsp+58h] [rbp-A8h]
  char v42; // [rsp+5Ah] [rbp-A6h]
  int v43; // [rsp+5Ch] [rbp-A4h]
  hkpCollidable::BoundingVolumeData v44; // [rsp+60h] [rbp-A0h]
  float v45; // [rsp+98h] [rbp-68h]
  hkpAgent3ProcessInput inputa; // [rsp+A0h] [rbp-60h]
  hkpListShape array; // [rsp+130h] [rbp+30h]
  hkpShape *shapeArray; // [rsp+1F0h] [rbp+F0h]

  v5 = input;
  v6 = separatingNormal;
  v7 = agentData;
  v8 = entry;
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)v9[1];
  v11 = v9;
  if ( (unsigned __int64)v10 < v9[3] )
  {
    *v10 = "TtColl3";
    v12 = __rdtsc();
    v13 = (signed __int64)(v10 + 2);
    *(_DWORD *)(v13 - 8) = v12;
    v11[1] = v13;
  }
  v14 = *(_OWORD *)&v5->m_overrideBodyA.m_storage;
  *(_OWORD *)&inputa.m_bodyA.m_storage = *(_OWORD *)&v5->m_bodyA.m_storage;
  v15 = *(_OWORD *)&v5->m_contactMgr.m_storage;
  *(_OWORD *)&inputa.m_overrideBodyA.m_storage = v14;
  v16.m_quad = (__m128)v5->m_aTb.m_rotation.m_col0;
  *(_OWORD *)&inputa.m_contactMgr.m_storage = v15;
  inputa.m_aTb.m_rotation.m_col1 = v5->m_aTb.m_rotation.m_col1;
  v17.m_quad = (__m128)v5->m_aTb.m_translation;
  inputa.m_aTb.m_rotation.m_col0 = (hkVector4f)v16.m_quad;
  v18.m_quad = (__m128)v5->m_aTb.m_rotation.m_col2;
  inputa.m_aTb.m_translation = (hkVector4f)v17.m_quad;
  v19.m_quad = (__m128)v5->m_linearTimInfo;
  inputa.m_aTb.m_rotation.m_col2 = (hkVector4f)v18.m_quad;
  v20 = *(_OWORD *)&v5->m_distAtT1.m_storage;
  inputa.m_linearTimInfo = (hkVector4f)v19.m_quad;
  *(_OWORD *)&inputa.m_distAtT1.m_storage = v20;
  v21 = inputa.m_bodyA.m_storage->m_shape;
  v34 = 0i64;
  _mm_store_si128((__m128i *)&v36, (__m128i)0i64);
  shapeArray = v21;
  v35 = -1;
  v37 = 0;
  v40 = 0;
  v41 = 32512;
  v43 = 0;
  v42 = -1;
  hkpCollidable::BoundingVolumeData::BoundingVolumeData(&v44);
  v45 = FLOAT_N1_0;
  v38 = 8;
  v39 = 0;
  HIBYTE(v41) = (unsigned __int64)&v34 - (unsigned __int64)&v40;
  hkpListShape::hkpListShape(&array, &shapeArray, 1, 0);
  v22 = v5->m_bodyA.m_storage;
  v24 = v23;
  if ( !v5->m_bodyA.m_storage->m_parent )
  {
    *(_OWORD *)v44.m_min = *(_OWORD *)&v22[1].m_motion;
    *(_OWORD *)v44.m_max = *(_OWORD *)&v22[2].m_shape;
    *(_OWORD *)&v44.m_numChildShapeAabbs = *(_OWORD *)&v22[2].m_motion;
    v44.m_childShapeKeys = (unsigned int *)v22[3].m_shape;
  }
  v25 = v22->m_parent;
  v26 = v22->m_motion;
  v34 = v24;
  *((_QWORD *)&v36 + 1) = v25;
  *(_QWORD *)&v36 = v26;
  inputa.m_bodyA.m_storage = (hkpCdBody *)&v34;
  inputa.m_overrideBodyA.m_storage = v22;
  v35 = -1;
  v27 = hkpCollectionCollectionAgent3::process(&inputa, v8, v7, v6, output);
  if ( (array.m_childInfo.m_capacityAndFlags & 0x3FFFFFFF) < 0 )
  {
    v28 = 0;
    if ( 2 * (array.m_childInfo.m_capacityAndFlags & 0x3FFFFFFF) > 0 )
      v28 = 2 * (array.m_childInfo.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      (hkResult *)&shapeArray,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &array.m_childInfo,
      v28,
      32);
  }
  array.m_childInfo.m_size = 0;
  array.vfptr->__vecDelDtor((hkBaseObject *)&array, 0);
  v29 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v30 = (_QWORD *)v29[1];
  if ( (unsigned __int64)v30 < v29[3] )
  {
    *v30 = "Et";
    v31 = __rdtsc();
    v32 = (signed __int64)(v30 + 2);
    *(_DWORD *)(v32 - 8) = v31;
    v29[1] = v32;
  }
  return v27;
}

