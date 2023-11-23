// File Line: 30
// RVA: 0xD2C6B0
void __fastcall hkBoxBoxAgent3::initAgentFunc(hkpCollisionDispatcher::Agent3Funcs *f)
{
  f->m_createFunc = (void *(__fastcall *)(hkpAgent3Input *, hkpAgentEntry *, void *))hkBoxBoxAgent3::create;
  f->m_sepNormalFunc = 0i64;
  f->m_processFunc = (void *(__fastcall *)(hkpAgent3ProcessInput *, hkpAgentEntry *, void *, hkVector4f *, hkpProcessCollisionOutput *))hkBoxBoxAgent3::process;
  f->m_updateFilterFunc = 0i64;
  f->m_cleanupFunc = (void *(__fastcall *)(hkpAgentEntry *, void *, hkpContactMgr *, hkpConstraintOwner *))hkBoxBoxAgent3::cleanup;
  f->m_removePointFunc = (void (__fastcall *)(hkpAgentEntry *, void *, unsigned __int16))hkBoxBoxAgent3::removePoint;
  f->m_commitPotentialFunc = (void (__fastcall *)(hkpAgentEntry *, void *, unsigned __int16))hkBoxBoxAgent3::commitPotential;
  f->m_createZombieFunc = hkBoxBoxAgent3::createZombie;
  f->m_destroyFunc = (void (__fastcall *)(hkpAgentEntry *, void *, hkpContactMgr *, hkpConstraintOwner *, hkpCollisionDispatcher *))hkBoxBoxAgent3::destroy;
  f->m_isPredictive.m_bool = 0;
}

// File Line: 47
// RVA: 0xD2C650
void __fastcall hkBoxBoxAgent3::registerAgent3(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher::Agent3Funcs f; // [rsp+20h] [rbp-68h] BYREF

  *(_WORD *)&f.m_isPredictive.m_bool = 0;
  f.m_reusePreviousEntry.m_bool = 0;
  memset(&f.m_updateFilterFunc, 0, 32);
  hkBoxBoxAgent3::initAgentFunc(&f);
  hkpCollisionDispatcher::registerAgent3(dispatcher, &f, BOX, BOX);
}

// File Line: 55
// RVA: 0xD2C2E0
__int64 __fastcall hkBoxBoxAgent3::create(hkpAgent3Input *input, hkpAgentEntry *entry, hkpBoxBoxManifold *agentData)
{
  if ( !agentData )
    return 64i64;
  hkpBoxBoxManifold::hkpBoxBoxManifold(agentData);
  return (__int64)&agentData[1];
}

// File Line: 89
// RVA: 0xD2C4E0
void *__fastcall hkBoxBoxAgent3::cleanup(
        hkpAgentEntry *entry,
        char *agentData,
        hkpContactMgr *mgr,
        hkpConstraintOwner *constraintOwner)
{
  int v4; // edi
  unsigned __int16 *v9; // rbx
  __int64 v10; // rdx
  void *result; // rax

  v4 = 0;
  if ( agentData[33] )
  {
    v9 = (unsigned __int16 *)(agentData + 2);
    do
    {
      v10 = *v9;
      if ( (_WORD)v10 != 0xFFFF )
        ((void (__fastcall *)(hkpContactMgr *, __int64, hkpConstraintOwner *))mgr->vfptr[2].__first_virtual_table_function__)(
          mgr,
          v10,
          constraintOwner);
      ++v4;
      v9 += 2;
    }
    while ( v4 < (unsigned __int8)agentData[33] );
  }
  agentData[33] = 0;
  result = agentData + 64;
  entry->m_numContactPoints = 0;
  return result;
}

// File Line: 104
// RVA: 0xD2C580
void __fastcall hkBoxBoxAgent3::removePoint(
        hkpAgentEntry *entry,
        hkpBoxBoxManifold *agentData,
        unsigned __int16 idToRemove)
{
  int v4; // edx
  __int64 v6; // r9
  unsigned __int16 *i; // rax

  v4 = 0;
  v6 = 0i64;
  if ( agentData->m_numPoints )
  {
    for ( i = &agentData->m_contactPoints[0].m_contactPointId; *i != idToRemove; i += 2 )
    {
      ++v6;
      ++v4;
      if ( v6 >= (unsigned __int8)agentData->m_numPoints )
        return;
    }
    hkpBoxBoxManifold::removePoint(agentData, v4);
    --entry->m_numContactPoints;
  }
}

// File Line: 118
// RVA: 0xD2C5E0
void __fastcall hkBoxBoxAgent3::commitPotential(hkpAgentEntry *entry, _WORD *agentData, unsigned __int16 idToCommit)
{
  int v3; // r9d
  __int64 v4; // rcx
  _WORD *i; // rax

  v3 = 0;
  v4 = 0i64;
  if ( *((_BYTE *)agentData + 33) )
  {
    for ( i = agentData + 1; *i != 0xFFFF; i += 2 )
    {
      ++v4;
      ++v3;
      if ( v4 >= *((unsigned __int8 *)agentData + 33) )
        return;
    }
    agentData[2 * v3 + 1] = idToCommit;
  }
}

// File Line: 131
// RVA: 0xD2C630
void __fastcall hkBoxBoxAgent3::createZombie(hkpAgentEntry *entry, void *agentData, unsigned __int16 idToConvert)
{
  ;
}

// File Line: 137
// RVA: 0xD2C640
// attributes: thunk
void __fastcall hkBoxBoxAgent3::destroy(
        hkpAgentEntry *entry,
        char *agentData,
        hkpContactMgr *mgr,
        hkpConstraintOwner *constraintOwner,
        hkpCollisionDispatcher *dispatcher)
{
  hkBoxBoxAgent3::cleanup(entry, agentData, mgr, constraintOwner);
}

// File Line: 143
// RVA: 0xD2C310
hkpBoxBoxManifold *__fastcall hkBoxBoxAgent3::process(
        hkpAgent3ProcessInput *input,
        hkpAgentEntry *entry,
        hkpBoxBoxManifold *agentData,
        hkVector4f *separatingNormal,
        hkpProcessCollisionOutput *output)
{
  _QWORD *Value; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r9
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  hkpCdBody *m_storage; // r9
  __m128 **v14; // r8
  hkTransformf *v15; // rdx
  hkVector4f v16; // xmm4
  hkVector4f v17; // xmm3
  hkTransformf *m_motion; // rcx
  hkpProcessCollisionInput *v19; // rax
  hkVector4f v20; // xmm0
  hkVector4f v21; // xmm1
  hkpContactMgr *v22; // rax
  __m128 v23; // xmm2
  hkVector4f v24; // xmm0
  _QWORD *v25; // r8
  _QWORD *v26; // rcx
  unsigned __int64 v27; // rax
  _QWORD *v28; // rcx
  hkpBoxBoxCollisionDetection v30; // [rsp+20h] [rbp-158h] BYREF
  float v31; // [rsp+180h] [rbp+8h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  v10 = Value;
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtBoxBox3";
    v11 = __rdtsc();
    v12 = v9 + 2;
    *((_DWORD *)v12 - 2) = v11;
    v10[1] = v12;
  }
  m_storage = input->m_bodyA.m_storage;
  v14 = (__m128 **)input->m_bodyB.m_storage;
  v15 = (hkTransformf *)v14[2];
  v16.m_quad = _mm_add_ps(
                 _mm_shuffle_ps(
                   (__m128)LODWORD(input->m_bodyA.m_storage->m_shape[1].vfptr),
                   (__m128)LODWORD(input->m_bodyA.m_storage->m_shape[1].vfptr),
                   0),
                 *(__m128 *)&input->m_bodyA.m_storage->m_shape[1].m_type.m_storage);
  v17.m_quad = _mm_add_ps(_mm_shuffle_ps((__m128)(*v14)[2].m128_u32[0], (__m128)(*v14)[2].m128_u32[0], 0), (*v14)[3]);
  m_motion = (hkTransformf *)input->m_bodyA.m_storage->m_motion;
  v19 = input->m_input.m_storage;
  v31 = v19->m_tolerance.m_storage;
  v30.m_aTb.m_rotation.m_col1 = input->m_aTb.m_rotation.m_col1;
  v20.m_quad = (__m128)input->m_aTb.m_rotation.m_col0;
  v21.m_quad = (__m128)input->m_aTb.m_translation;
  v30.m_env = v19;
  v22 = input->m_contactMgr.m_storage;
  v30.m_wTa = m_motion;
  v30.m_wTb = v15;
  v23 = _mm_shuffle_ps((__m128)LODWORD(v31), (__m128)LODWORD(v31), 0);
  v30.m_contactMgr = v22;
  v30.m_aTb.m_rotation.m_col0 = (hkVector4f)v20.m_quad;
  v24.m_quad = (__m128)input->m_aTb.m_rotation.m_col2;
  v30.m_aTb.m_translation = (hkVector4f)v21.m_quad;
  v30.m_bodyA = m_storage;
  v30.m_bodyB = (hkpCdBody *)v14;
  v30.m_aTb.m_rotation.m_col2 = (hkVector4f)v24.m_quad;
  v30.m_radiusA = (hkVector4f)v16.m_quad;
  v30.m_radiusB = (hkVector4f)v17.m_quad;
  v30.m_result = output;
  v30.m_boundaryTolerance.m_real = _mm_shuffle_ps(
                                     (__m128)LODWORD(FLOAT_0_0099999998),
                                     (__m128)LODWORD(FLOAT_0_0099999998),
                                     0);
  v30.m_tolerance4.m_quad = _mm_shuffle_ps(v23, _mm_unpackhi_ps(v23, (__m128)xmmword_141A712A0), 196);
  v30.m_keepRadiusB.m_quad = _mm_add_ps(v30.m_tolerance4.m_quad, v17.m_quad);
  v30.m_keepRadiusA.m_quad = _mm_add_ps(v30.m_tolerance4.m_quad, v16.m_quad);
  hkpBoxBoxCollisionDetection::calcManifold(&v30, agentData);
  entry->m_numContactPoints = agentData->m_numPoints;
  v25 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v26 = (_QWORD *)v25[1];
  if ( (unsigned __int64)v26 < v25[3] )
  {
    *v26 = "Et";
    v27 = __rdtsc();
    v28 = v26 + 2;
    *((_DWORD *)v28 - 2) = v27;
    v25[1] = v28;
  }
  return agentData + 1;
}

