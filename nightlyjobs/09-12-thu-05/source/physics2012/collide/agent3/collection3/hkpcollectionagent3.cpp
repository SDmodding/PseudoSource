// File Line: 40
// RVA: 0xD2F680
void __fastcall hkpCollectionAgent3::initAgentFunc(hkpCollisionDispatcher::Agent3Funcs *f)
{
  hkListAgent3::initAgentFunc(f);
  f->m_processFunc = (void *(__fastcall *)(hkpAgent3ProcessInput *, hkpAgentEntry *, void *, hkVector4f *, hkpProcessCollisionOutput *))hkpCollectionAgent3::process;
}

// File Line: 48
// RVA: 0xD2F620
void __fastcall hkpCollectionAgent3::registerAgent3(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher::Agent3Funcs f; // [rsp+20h] [rbp-68h] BYREF

  *(_WORD *)&f.m_isPredictive.m_bool = 0;
  f.m_reusePreviousEntry.m_bool = 0;
  memset(&f.m_updateFilterFunc, 0, 32);
  hkpCollectionAgent3::initAgentFunc(&f);
  hkpCollisionDispatcher::registerAgent3(dispatcher, &f, CONVEX, COLLECTION);
}

// File Line: 110
// RVA: 0xD2F3C0
char *__fastcall hkpCollectionAgent3::process(
        hkpAgent3ProcessInput *input,
        hkpAgentEntry *entry,
        char *agentData,
        hkVector4f *separatingNormal,
        hkpProcessCollisionOutput *output)
{
  _QWORD *Value; // rax
  _QWORD *v10; // rcx
  _QWORD *v11; // r10
  unsigned __int64 v12; // rax
  _QWORD *v13; // rcx
  __int128 v14; // xmm1
  __int128 v15; // xmm0
  hkVector4f v16; // xmm1
  hkVector4f v17; // xmm0
  hkVector4f v18; // xmm1
  hkVector4f v19; // xmm0
  __int128 v20; // xmm1
  hkpShape *m_shape; // rcx
  hkpCdBody *m_storage; // rdx
  __int64 v23; // rax
  __int64 v24; // r8
  hkpCdBody *m_parent; // rax
  const void *m_motion; // rcx
  char *v27; // rbx
  _QWORD *v28; // r8
  _QWORD *v29; // rcx
  unsigned __int64 v30; // rax
  _QWORD *v31; // rcx
  __int64 v33; // [rsp+30h] [rbp-D0h] BYREF
  int v34; // [rsp+38h] [rbp-C8h]
  __int128 v35; // [rsp+40h] [rbp-C0h]
  char v36; // [rsp+50h] [rbp-B0h]
  char v37; // [rsp+51h] [rbp-AFh]
  __int16 v38; // [rsp+52h] [rbp-AEh]
  int v39; // [rsp+54h] [rbp-ACh] BYREF
  char v40; // [rsp+58h] [rbp-A8h]
  char v41; // [rsp+59h] [rbp-A7h]
  char v42; // [rsp+5Ah] [rbp-A6h]
  int v43; // [rsp+5Ch] [rbp-A4h]
  hkpCollidable::BoundingVolumeData v44; // [rsp+60h] [rbp-A0h] BYREF
  float v45; // [rsp+98h] [rbp-68h]
  hkpAgent3ProcessInput inputa; // [rsp+A0h] [rbp-60h] BYREF
  hkpListShape array; // [rsp+130h] [rbp+30h] BYREF
  hkpShape *shapeArray; // [rsp+1F0h] [rbp+F0h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)Value[1];
  v11 = Value;
  if ( (unsigned __int64)v10 < Value[3] )
  {
    *v10 = "TtColl3";
    v12 = __rdtsc();
    v13 = v10 + 2;
    *((_DWORD *)v13 - 2) = v12;
    v11[1] = v13;
  }
  v14 = *(_OWORD *)&input->m_overrideBodyA.m_storage;
  *(_OWORD *)&inputa.m_bodyA.m_storage = *(_OWORD *)&input->m_bodyA.m_storage;
  v15 = *(_OWORD *)&input->m_contactMgr.m_storage;
  *(_OWORD *)&inputa.m_overrideBodyA.m_storage = v14;
  v16.m_quad = (__m128)input->m_aTb.m_rotation.m_col0;
  *(_OWORD *)&inputa.m_contactMgr.m_storage = v15;
  inputa.m_aTb.m_rotation.m_col1 = input->m_aTb.m_rotation.m_col1;
  v17.m_quad = (__m128)input->m_aTb.m_translation;
  inputa.m_aTb.m_rotation.m_col0 = (hkVector4f)v16.m_quad;
  v18.m_quad = (__m128)input->m_aTb.m_rotation.m_col2;
  inputa.m_aTb.m_translation = (hkVector4f)v17.m_quad;
  v19.m_quad = (__m128)input->m_linearTimInfo;
  inputa.m_aTb.m_rotation.m_col2 = (hkVector4f)v18.m_quad;
  v20 = *(_OWORD *)&input->m_distAtT1.m_storage;
  inputa.m_linearTimInfo = (hkVector4f)v19.m_quad;
  *(_OWORD *)&inputa.m_distAtT1.m_storage = v20;
  m_shape = inputa.m_bodyA.m_storage->m_shape;
  v33 = 0i64;
  v35 = 0i64;
  shapeArray = m_shape;
  v34 = -1;
  v36 = 0;
  v39 = 0;
  v40 = 0;
  v43 = 0;
  v42 = -1;
  hkpCollidable::BoundingVolumeData::BoundingVolumeData(&v44);
  v45 = FLOAT_N1_0;
  v37 = 8;
  v38 = 0;
  v41 = (unsigned __int8)&v33 - (unsigned __int8)&v39;
  hkpListShape::hkpListShape(&array, &shapeArray, 1, REFERENCE_POLICY_IGNORE);
  m_storage = input->m_bodyA.m_storage;
  v24 = v23;
  if ( !input->m_bodyA.m_storage->m_parent )
    v44 = *(hkpCollidable::BoundingVolumeData *)&m_storage[1].m_motion;
  m_parent = m_storage->m_parent;
  m_motion = m_storage->m_motion;
  v33 = v24;
  *((_QWORD *)&v35 + 1) = m_parent;
  *(_QWORD *)&v35 = m_motion;
  inputa.m_bodyA.m_storage = (hkpCdBody *)&v33;
  inputa.m_overrideBodyA.m_storage = m_storage;
  v34 = -1;
  v27 = hkpCollectionCollectionAgent3::process(&inputa, entry, agentData, separatingNormal, output);
  array.m_childInfo.m_size = 0;
  array.hkpShapeCollection::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr->__vecDelDtor(
    &array,
    0i64);
  v28 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v29 = (_QWORD *)v28[1];
  if ( (unsigned __int64)v29 < v28[3] )
  {
    *v29 = "Et";
    v30 = __rdtsc();
    v31 = v29 + 2;
    *((_DWORD *)v31 - 2) = v30;
    v28[1] = v31;
  }
  return v27;
};
    v30 = __rdtsc();
    v31 = v29 + 2;
    *((_DWORD *)v31 - 2) = v30;
    v28[1] = v31;
  }
  ret

