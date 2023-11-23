// File Line: 50
// RVA: 0xD2CD20
void __fastcall hkConvexListAgent3::initAgentFunc(hkpCollisionDispatcher::Agent3Funcs *f)
{
  f->m_createFunc = (void *(__fastcall *)(hkpAgent3Input *, hkpAgentEntry *, void *))hkConvexListAgent3::create;
  f->m_processFunc = (void *(__fastcall *)(hkpAgent3ProcessInput *, hkpAgentEntry *, void *, hkVector4f *, hkpProcessCollisionOutput *))hkConvexListAgent3::process;
  f->m_sepNormalFunc = (void (__fastcall *)(hkpAgent3Input *, hkpAgentEntry *, void *, hkVector4f *))hkConvexListAgent3::sepNormal;
  f->m_cleanupFunc = (void *(__fastcall *)(hkpAgentEntry *, void *, hkpContactMgr *, hkpConstraintOwner *))hkConvexListAgent3::cleanup;
  f->m_removePointFunc = (void (__fastcall *)(hkpAgentEntry *, void *, unsigned __int16))hkConvexListAgent3::removePoint;
  f->m_commitPotentialFunc = (void (__fastcall *)(hkpAgentEntry *, void *, unsigned __int16))hkConvexListAgent3::commitPotential;
  f->m_createZombieFunc = (void (__fastcall *)(hkpAgentEntry *, void *, unsigned __int16))hkConvexListAgent3::createZombie;
  f->m_updateFilterFunc = hkConvexListAgent3::updateFilter;
  f->m_invalidateTimFunc = hkConvexListAgent3::invalidateTim;
  f->m_warpTimeFunc = hkConvexListAgent3::warpTime;
  f->m_destroyFunc = (void (__fastcall *)(hkpAgentEntry *, void *, hkpContactMgr *, hkpConstraintOwner *, hkpCollisionDispatcher *))hkConvexListAgent3::destroy;
  f->m_isPredictive.m_bool = 1;
}

// File Line: 69
// RVA: 0xD2CCA0
void __fastcall hkConvexListAgent3::registerAgent3(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher::Agent3Funcs f; // [rsp+20h] [rbp-68h] BYREF

  *(_WORD *)&f.m_isPredictive.m_bool = 0;
  f.m_reusePreviousEntry.m_bool = 0;
  memset(&f.m_updateFilterFunc, 0, 32);
  hkConvexListAgent3::initAgentFunc(&f);
  hkpCollisionDispatcher::registerAgent3(dispatcher, &f, CONVEX, CONVEX_LIST);
  hkpCollisionDispatcher::registerAgent3(dispatcher, &f, CONVEX_LIST, CONVEX_LIST);
}

// File Line: 138
// RVA: 0xD2CE90
hkpAgent1nTrack *__fastcall hkConvexListAgent3::getAgent1nTrack(hkpAgentEntry *entry, char *data)
{
  return (hkpAgent1nTrack *)(data + 20);
}

// File Line: 143
// RVA: 0xD2CEA0
hkpAgent1nTrack *__fastcall hkConvexListAgent3::getAgent1nTrack(hkpAgentEntry *entry, char *data)
{
  return (hkpAgent1nTrack *)(data + 20);
}

// File Line: 149
// RVA: 0xD2CDB0
void __fastcall hkConvexListAgent3::updateFilter(
        hkpAgentEntry *entry,
        char *agentData,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *mgr,
        hkpConstraintOwner *constraintOwner)
{
  hkpShapeContainer *v10; // rax
  hkpAgent1nMachine_VisitorInput vin; // [rsp+20h] [rbp-48h] BYREF

  if ( (agentData[11] & 0x20) == 0 )
  {
    v10 = (hkpShapeContainer *)((__int64 (__fastcall *)(hkpShape *))bodyB->m_shape->vfptr[7].__vecDelDtor)(bodyB->m_shape);
    vin.m_input = input;
    vin.m_bodyA = bodyA;
    vin.m_contactMgr = mgr;
    vin.m_collectionBodyB = bodyB;
    vin.m_constraintOwner = constraintOwner;
    vin.m_containerShapeB = v10;
    hkAgent1nMachine_UpdateShapeCollectionFilter((hkpAgent1nTrack *)(agentData + 20), &vin);
  }
}

// File Line: 171
// RVA: 0xD2CE40
void __fastcall hkConvexListAgent3::invalidateTim(hkpAgentEntry *entry, char *agentData, hkpCollisionInput *input)
{
  if ( (agentData[11] & 0x20) == 0 )
    hkAgent1nMachine_InvalidateTim((hkpAgent1nTrack *)(agentData + 20), input);
}

// File Line: 180
// RVA: 0xD2CE60
void __fastcall hkConvexListAgent3::warpTime(
        hkpAgentEntry *entry,
        char *agentData,
        float oldTime,
        float newTime,
        hkpCollisionInput *input)
{
  if ( (agentData[11] & 0x20) == 0 )
    hkAgent1nMachine_WarpTime((hkpAgent1nTrack *)(agentData + 20), oldTime, newTime, input);
}

// File Line: 190
// RVA: 0xD2C710
char *__fastcall hkConvexListAgent3::create(hkpAgent3Input *input, hkpAgentEntry *entry, hkpGskCache *agentData)
{
  char *result; // rax

  result = hkPredGskAgent3::create(input, entry, agentData);
  agentData->m_gskFlags = agentData->m_gskFlags & 0x9F | 0x20;
  return result;
}

// File Line: 203
// RVA: 0xD2CC80
void __fastcall hkConvexListAgent3::destroy(
        hkpAgentEntry *entry,
        char *agentData,
        hkpContactMgr *mgr,
        hkpConstraintOwner *constraintOwner,
        hkpCollisionDispatcher *dispatcher)
{
  if ( (agentData[11] & 0x20) != 0 )
    hkPredGskAgent3::destroy(entry, agentData, mgr, constraintOwner);
  else
    hkAgent1nMachine_Destroy((hkpAgent1nTrack *)(agentData + 20), dispatcher, mgr, constraintOwner);
}

// File Line: 216
// RVA: 0xD2CBD0
void __fastcall hkConvexListAgent3::sepNormal(
        hkpAgent3Input *input,
        hkpAgentEntry *entry,
        hkpGskCache *agentData,
        hkVector4f *separatingNormalOut)
{
  if ( (agentData->m_gskFlags & 0x20) != 0 )
    hkPredGskAgent3::sepNormal(input, entry, agentData, separatingNormalOut);
  else
    separatingNormalOut->m_quad = _mm_shuffle_ps(
                                    transform.m_quad,
                                    _mm_unpackhi_ps(
                                      transform.m_quad,
                                      _mm_mul_ps((__m128)xmmword_141A711B0, (__m128)xmmword_141A712F0)),
                                    196);
}

// File Line: 230
// RVA: 0xD2CC10
// attributes: thunk
char *__fastcall hkConvexListAgent3::cleanup(
        hkpAgentEntry *entry,
        char *agentData,
        hkpContactMgr *mgr,
        hkpConstraintOwner *constraintOwner)
{
  return hkPredGskAgent3::cleanup(entry, agentData, mgr, constraintOwner);
}

// File Line: 240
// RVA: 0xD2CC20
void __fastcall hkConvexListAgent3::removePoint(
        hkpAgentEntry *entry,
        unsigned __int8 *agentData,
        unsigned __int16 idToRemove)
{
  if ( (agentData[11] & 0x20) != 0 )
    hkPredGskAgent3::removePoint(entry, agentData, idToRemove);
}

// File Line: 248
// RVA: 0xD2CC40
void __fastcall hkConvexListAgent3::commitPotential(
        hkpAgentEntry *entry,
        unsigned __int8 *agentData,
        unsigned __int16 idToCommit)
{
  if ( (agentData[11] & 0x20) != 0 )
    hkPredGskAgent3::commitPotential(entry, agentData, idToCommit);
}

// File Line: 256
// RVA: 0xD2CC60
void __fastcall hkConvexListAgent3::createZombie(hkpAgentEntry *entry, _BYTE *agentData, unsigned __int16 idToConvert)
{
  if ( (agentData[11] & 0x20) != 0 )
    hkPredGskAgent3::createZombie(entry, agentData, idToConvert);
}

// File Line: 267
// RVA: 0xD2C740
unsigned __int64 __fastcall hkConvexListAgent3::process(
        hkpAgent3ProcessInput *input,
        hkpAgentEntry *entry,
        char *agentData,
        hkVector4f *separatingNormal,
        hkpProcessCollisionOutput *output)
{
  _QWORD *Value; // rax
  unsigned __int64 v10; // rcx
  _QWORD *v11; // r8
  unsigned __int64 v12; // rax
  hkpProcessCollisionOutput *v13; // r13
  unsigned int v14; // r14d
  __int128 v15; // xmm0
  __int128 v16; // xmm1
  hkpContactMgr *m_storage; // rax
  __int128 v18; // xmm0
  hkVector4f v19; // xmm1
  hkVector4f v20; // xmm0
  hkVector4f v21; // xmm0
  hkVector4f v22; // xmm1
  hkVector4f v23; // xmm0
  __int128 v24; // xmm1
  char *v25; // rax
  char *v26; // rsi
  hkpCdBody *v27; // rdx
  hkpCdBody *i; // rcx
  hkpCdBody *v29; // rcx
  float v30; // xmm2_4
  hkpCdBody *j; // rax
  float v32; // xmm2_4
  _QWORD *v33; // r8
  _QWORD *v34; // rcx
  unsigned __int64 v35; // rax
  _QWORD *v36; // rcx
  __int16 v37; // cx
  hkpCdBody *v38; // rdx
  hkpConvexShape *v39; // rcx
  __int64 v40; // rax
  __int64 v41; // r15
  hkLifoAllocator *v42; // rax
  unsigned int *m_cur; // rsi
  int v44; // edx
  char *v45; // rcx
  __int64 v46; // rcx
  hkpShapeContainer *p_m_memSizeAndFlags; // r8
  int v48; // ebx
  hkLifoAllocator *v49; // rax
  int v50; // r8d
  _QWORD *v51; // r8
  _QWORD *v52; // rcx
  unsigned __int64 v53; // rax
  _QWORD *v54; // rcx
  hkpGsk::GetClosesetPointInput v56; // [rsp+30h] [rbp-D0h] BYREF
  hkpAgent3ProcessInput inputa; // [rsp+60h] [rbp-A0h] BYREF
  hkVector4f pointOnBOut; // [rsp+F0h] [rbp-10h] BYREF
  hkTransformf v59; // [rsp+100h] [rbp+0h] BYREF
  hkpProcessCollisionOutputBackup v60; // [rsp+140h] [rbp+40h] BYREF
  hkResult result; // [rsp+2220h] [rbp+2120h] BYREF
  hkpShape *m_shape; // [rsp+2230h] [rbp+2130h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = Value[1];
  v11 = Value;
  if ( v10 < Value[3] )
  {
    *(_QWORD *)v10 = "LtCvxLst";
    *(_QWORD *)(v10 + 16) = "StTim";
    v12 = __rdtsc();
    *(_DWORD *)(v10 + 8) = v12;
    v11[1] = v10 + 24;
  }
  v13 = output;
  m_shape = input->m_bodyB.m_storage->m_shape;
  hkpProcessCollisionOutputBackup::hkpProcessCollisionOutputBackup(&v60, output);
  v14 = 0;
  if ( (agentData[11] & 0x20) == 0 )
    goto $streamMode_0;
  while ( 1 )
  {
    v15 = *(_OWORD *)&input->m_bodyA.m_storage;
    v16 = *(_OWORD *)&input->m_overrideBodyA.m_storage;
    v56.m_aTb.m_storage = (hkTransformf *)&hkpMapPointsToSubShapeContactMgr::`vftable;
    m_storage = input->m_contactMgr.m_storage;
    *(_OWORD *)&inputa.m_bodyA.m_storage = v15;
    v18 = *(_OWORD *)&input->m_contactMgr.m_storage;
    *(_OWORD *)&inputa.m_overrideBodyA.m_storage = v16;
    v56.m_shapeB.m_storage = (hkpConvexShape *)m_storage;
    LODWORD(v56.m_transformA.m_storage) = 0x1FFFF;
    LODWORD(v56.m_shapeA.m_storage) = 2;
    v19.m_quad = (__m128)input->m_aTb.m_rotation.m_col0;
    *(_OWORD *)&inputa.m_contactMgr.m_storage = v18;
    v20.m_quad = (__m128)input->m_aTb.m_rotation.m_col1;
    LOBYTE(v56.m_collisionTolerance.m_storage) = 0;
    inputa.m_contactMgr.m_storage = (hkpContactMgr *)&v56;
    inputa.m_aTb.m_rotation.m_col1 = (hkVector4f)v20.m_quad;
    v21.m_quad = (__m128)input->m_aTb.m_translation;
    inputa.m_aTb.m_rotation.m_col0 = (hkVector4f)v19.m_quad;
    v22.m_quad = (__m128)input->m_aTb.m_rotation.m_col2;
    inputa.m_aTb.m_translation = (hkVector4f)v21.m_quad;
    v23.m_quad = (__m128)input->m_linearTimInfo;
    inputa.m_aTb.m_rotation.m_col2 = (hkVector4f)v22.m_quad;
    v24 = *(_OWORD *)&input->m_distAtT1.m_storage;
    inputa.m_linearTimInfo = (hkVector4f)v23.m_quad;
    *(_OWORD *)&inputa.m_distAtT1.m_storage = v24;
    v25 = hkPredGskAgent3::process(&inputa, entry, agentData, separatingNormal, v13);
    inputa.m_contactMgr.m_storage = (hkpContactMgr *)v56.m_shapeB.m_storage;
    v26 = v25;
    if ( !LOBYTE(v56.m_collisionTolerance.m_storage) )
    {
      if ( !agentData[14] || (agentData[11] & 0x40) != 0 )
        break;
      v27 = input->m_bodyA.m_storage;
      for ( i = input->m_bodyA.m_storage->m_parent; i; i = i->m_parent )
        v27 = i;
      v29 = input->m_bodyB.m_storage;
      LODWORD(v30) = _mm_shuffle_ps((__m128)v27[3].m_shapeKey, (__m128)v27[3].m_shapeKey, 0).m128_u32[0];
      for ( j = v29->m_parent; j; j = j->m_parent )
        v29 = j;
      v32 = fmin(v30, _mm_shuffle_ps((__m128)v29[3].m_shapeKey, (__m128)v29[3].m_shapeKey, 0).m128_f32[0]);
      if ( _mm_shuffle_ps(separatingNormal->m_quad, separatingNormal->m_quad, 255).m128_f32[0] >= (float)(0.0 - (float)(v32 + v32)) )
        break;
    }
    hkpProcessCollisionOutputBackup::rollbackOutput(
      &v60,
      input->m_bodyA.m_storage,
      input->m_bodyB.m_storage,
      v13,
      input->m_contactMgr.m_storage);
    hkPredGskAgent3::cleanup(entry, agentData, input->m_contactMgr.m_storage, v13->m_constraintOwner.m_storage);
    agentData[11] &= ~0x20u;
    if ( agentData != (char *)-12i64 )
    {
      *(_QWORD *)(agentData + 20) = 0i64;
      *((_DWORD *)agentData + 7) = 0;
      *((_DWORD *)agentData + 8) = 0x80000000;
    }
    hkAgent1nMachine_Create((hkpAgent1nTrack *)(agentData + 20));
    *((_WORD *)agentData + 6) = 25;
$streamMode_0:
    v33 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v34 = (_QWORD *)v33[1];
    if ( (unsigned __int64)v34 < v33[3] )
    {
      *v34 = "StStream";
      v35 = __rdtsc();
      v36 = v34 + 2;
      *((_DWORD *)v36 - 2) = v35;
      v33[1] = v36;
    }
    v37 = *((_WORD *)agentData + 6);
    *((_WORD *)agentData + 6) = v37 - 1;
    if ( v37 >= 0 )
      goto LABEL_20;
    *((_WORD *)agentData + 6) = 25;
    hkTransformf::setMulInverseMul(
      &v59,
      (hkTransformf *)input->m_bodyA.m_storage->m_motion,
      (hkTransformf *)input->m_bodyB.m_storage->m_motion);
    v38 = input->m_bodyA.m_storage;
    v56.m_shapeA.m_storage = (hkpConvexShape *)input->m_bodyA.m_storage->m_shape;
    v39 = (hkpConvexShape *)input->m_bodyB.m_storage->m_shape;
    v56.m_aTb.m_storage = &v59;
    v56.m_shapeB.m_storage = v39;
    v56.m_transformA.m_storage = (hkTransformf *)v38->m_motion;
    v56.m_collisionTolerance.m_storage = input->m_input.m_storage->m_tolerance.m_storage;
    if ( hkpGsk::getClosestPoint(&result, &v56, (hkpGskCache *)agentData, separatingNormal, &pointOnBOut)->m_enum == HK_SUCCESS )
    {
LABEL_20:
      v40 = (__int64)m_shape;
      separatingNormal->m_quad = _mm_shuffle_ps(
                                   separatingNormal->m_quad,
                                   _mm_unpackhi_ps(
                                     separatingNormal->m_quad,
                                     _mm_mul_ps((__m128)xmmword_141A711B0, (__m128)xmmword_141A712F0)),
                                   196);
      v41 = *(int *)(v40 + 112);
      v42 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      m_cur = (unsigned int *)v42->m_cur;
      v44 = (4 * v41 + 131) & 0xFFFFFF80;
      v45 = (char *)m_cur + v44;
      if ( v44 > v42->m_slabSize || v45 > v42->m_end )
        m_cur = (unsigned int *)hkLifoAllocator::allocateFromNewSlab(v42, v44);
      else
        v42->m_cur = v45;
      v46 = 0i64;
      if ( (int)v41 > 0 )
      {
        do
          m_cur[v46++] = v14++;
        while ( v46 < v41 );
      }
      p_m_memSizeAndFlags = (hkpShapeContainer *)&m_shape[1].m_memSizeAndFlags;
      m_cur[v41] = -1;
      hkAgent1nMachine_Process((hkpAgent1nTrack *)(agentData + 20), input, p_m_memSizeAndFlags, m_cur, v13);
      v48 = (4 * v41 + 131) & 0xFFFFFF80;
      v49 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v50 = (v48 + 15) & 0xFFFFFFF0;
      if ( v48 > v49->m_slabSize || (char *)m_cur + v50 != v49->m_cur || v49->m_firstNonLifoEnd == m_cur )
        hkLifoAllocator::slowBlockFree(v49, (char *)m_cur, v50);
      else
        v49->m_cur = m_cur;
      v26 = agentData + 36;
      break;
    }
    hkAgent1nMachine_Destroy(
      (hkpAgent1nTrack *)(agentData + 20),
      input->m_input.m_storage->m_dispatcher.m_storage,
      input->m_contactMgr.m_storage,
      v13->m_constraintOwner.m_storage);
    agentData[11] |= 0x20u;
    *((_DWORD *)agentData + 3) = 0;
    hkpProcessCollisionOutputBackup::rollbackOutput(
      &v60,
      input->m_bodyA.m_storage,
      input->m_bodyB.m_storage,
      v13,
      input->m_contactMgr.m_storage);
  }
  agentData[11] |= 0x40u;
  v51 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v52 = (_QWORD *)v51[1];
  if ( (unsigned __int64)v52 < v51[3] )
  {
    *v52 = "lt";
    v53 = __rdtsc();
    v54 = v52 + 2;
    *((_DWORD *)v54 - 2) = v53;
    v51[1] = v54;
  }
  return (unsigned __int64)(v26 + 15) & 0xFFFFFFFFFFFFFFF0ui64;
}

