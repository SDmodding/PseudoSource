// File Line: 30
// RVA: 0xD2C6B0
void __fastcall hkBoxBoxAgent3::initAgentFunc(hkpCollisionDispatcher::Agent3Funcs *f)
{
  f->m_createFunc = (void *(__fastcall *)(hkpAgent3Input *, hkpAgentEntry *, void *))hkBoxBoxAgent3::create;
  f->m_sepNormalFunc = 0i64;
  f->m_processFunc = (void *(__fastcall *)(hkpAgent3ProcessInput *, hkpAgentEntry *, void *, hkVector4f *, hkpProcessCollisionOutput *))hkBoxBoxAgent3::process;
  f->m_updateFilterFunc = 0i64;
  f->m_cleanupFunc = hkBoxBoxAgent3::cleanup;
  f->m_removePointFunc = hkBoxBoxAgent3::removePoint;
  f->m_commitPotentialFunc = hkBoxBoxAgent3::commitPotential;
  f->m_createZombieFunc = hkBoxBoxAgent3::createZombie;
  f->m_destroyFunc = hkBoxBoxAgent3::destroy;
  f->m_isPredictive.m_bool = 0;
}

// File Line: 47
// RVA: 0xD2C650
void __fastcall hkBoxBoxAgent3::registerAgent3(hkpCollisionDispatcher *dispatcher)
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
  hkBoxBoxAgent3::initAgentFunc(&f);
  hkpCollisionDispatcher::registerAgent3(v1, &f, BOX, BOX);
}

// File Line: 55
// RVA: 0xD2C2E0
signed __int64 __fastcall hkBoxBoxAgent3::create(hkpAgent3Input *input, hkpAgentEntry *entry, void *agentData)
{
  char *v3; // rbx

  v3 = (char *)agentData;
  if ( !agentData )
    return 64i64;
  hkpBoxBoxManifold::hkpBoxBoxManifold((hkpBoxBoxManifold *)agentData);
  return (signed __int64)(v3 + 64);
}

// File Line: 89
// RVA: 0xD2C4E0
void *__fastcall hkBoxBoxAgent3::cleanup(hkpAgentEntry *entry, void *agentData, hkpContactMgr *mgr, hkpConstraintOwner *constraintOwner)
{
  signed int v4; // edi
  hkpConstraintOwner *v5; // rbp
  hkpContactMgr *v6; // r14
  unsigned __int8 *v7; // rsi
  hkpAgentEntry *v8; // r15
  unsigned __int16 *v9; // rbx
  __int64 v10; // rdx
  void *result; // rax

  v4 = 0;
  v5 = constraintOwner;
  v6 = mgr;
  v7 = (unsigned __int8 *)agentData;
  v8 = entry;
  if ( *((_BYTE *)agentData + 33) )
  {
    v9 = (unsigned __int16 *)((char *)agentData + 2);
    do
    {
      v10 = *v9;
      if ( (_WORD)v10 != -1 )
        ((void (__fastcall *)(hkpContactMgr *, __int64, hkpConstraintOwner *))v6->vfptr[2].__first_virtual_table_function__)(
          v6,
          v10,
          v5);
      ++v4;
      v9 += 2;
    }
    while ( v4 < v7[33] );
  }
  v7[33] = 0;
  result = v7 + 64;
  v8->m_numContactPoints = 0;
  return result;
}

// File Line: 104
// RVA: 0xD2C580
void __fastcall hkBoxBoxAgent3::removePoint(hkpAgentEntry *entry, void *agentData, unsigned __int16 idToRemove)
{
  hkpBoxBoxManifold *v3; // r11
  int v4; // edx
  hkpAgentEntry *v5; // rbx
  __int64 v6; // r10
  __int64 v7; // r9
  unsigned __int16 *v8; // rax

  v3 = (hkpBoxBoxManifold *)agentData;
  v4 = 0;
  v5 = entry;
  v6 = (unsigned __int8)v3->m_numPoints;
  v7 = 0i64;
  if ( v6 > 0 )
  {
    v8 = &v3->m_contactPoints[0].m_contactPointId;
    while ( *v8 != idToRemove )
    {
      ++v7;
      ++v4;
      v8 += 2;
      if ( v7 >= v6 )
        return;
    }
    hkpBoxBoxManifold::removePoint(v3, v4);
    --v5->m_numContactPoints;
  }
}

// File Line: 118
// RVA: 0xD2C5E0
void __fastcall hkBoxBoxAgent3::commitPotential(hkpAgentEntry *entry, void *agentData, unsigned __int16 idToCommit)
{
  __int64 v3; // r10
  int v4; // er9
  __int64 v5; // rcx
  _WORD *v6; // rax

  v3 = *((unsigned __int8 *)agentData + 33);
  v4 = 0;
  v5 = 0i64;
  if ( v3 > 0 )
  {
    v6 = (char *)agentData + 2;
    while ( *v6 != -1 )
    {
      ++v5;
      ++v4;
      v6 += 2;
      if ( v5 >= v3 )
        return;
    }
    *((_WORD *)agentData + 2 * v4 + 1) = idToCommit;
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
void __fastcall hkBoxBoxAgent3::destroy(hkpAgentEntry *entry, void *agentData, hkpContactMgr *mgr, hkpConstraintOwner *constraintOwner, hkpCollisionDispatcher *dispatcher)
{
  hkBoxBoxAgent3::cleanup(entry, agentData, mgr, constraintOwner);
}

// File Line: 143
// RVA: 0xD2C310
signed __int64 __fastcall hkBoxBoxAgent3::process(hkpAgent3ProcessInput *input, hkpAgentEntry *entry, void *agentData, hkVector4f *separatingNormal, hkpProcessCollisionOutput *output)
{
  __m128 ***v5; // rdi
  hkpBoxBoxManifold *v6; // rbx
  hkpAgentEntry *v7; // rsi
  _QWORD *v8; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r9
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  hkpCdBody *v13; // r9
  __m128 **v14; // r8
  hkTransformf *v15; // rdx
  __m128i v16; // xmm4
  __m128i v17; // xmm3
  hkTransformf *v18; // rcx
  __m128 **v19; // rax
  hkVector4f v20; // xmm0
  hkVector4f v21; // xmm1
  hkpContactMgr *v22; // rax
  __m128 v23; // xmm2
  hkVector4f v24; // xmm0
  _QWORD *v25; // r8
  _QWORD *v26; // rcx
  unsigned __int64 v27; // rax
  signed __int64 v28; // rcx
  hkpBoxBoxCollisionDetection v30; // [rsp+20h] [rbp-158h]
  unsigned int v31; // [rsp+180h] [rbp+8h]

  v5 = (__m128 ***)input;
  v6 = (hkpBoxBoxManifold *)agentData;
  v7 = entry;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  v10 = v8;
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtBoxBox3";
    v11 = __rdtsc();
    v12 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v12 - 8) = v11;
    v10[1] = v12;
  }
  v13 = (hkpCdBody *)*v5;
  v14 = v5[1];
  v15 = (hkTransformf *)v14[2];
  v16 = (__m128i)_mm_add_ps(_mm_shuffle_ps((__m128)(**v5)[2].m128_u32[0], (__m128)(**v5)[2].m128_u32[0], 0), (**v5)[3]);
  v17 = (__m128i)_mm_add_ps(_mm_shuffle_ps((__m128)(*v14)[2].m128_u32[0], (__m128)(*v14)[2].m128_u32[0], 0), (*v14)[3]);
  v18 = (hkTransformf *)(*v5)[2];
  v19 = v5[3];
  v31 = *((_DWORD *)v19 + 4);
  v30.m_aTb.m_rotation.m_col1 = (hkVector4f)*((_OWORD *)v5 + 4);
  v20.m_quad = (__m128)*((_OWORD *)v5 + 3);
  v21.m_quad = (__m128)*((_OWORD *)v5 + 6);
  v30.m_env = (hkpProcessCollisionInput *)v19;
  v22 = (hkpContactMgr *)v5[4];
  v30.m_wTa = v18;
  v30.m_wTb = v15;
  v23 = _mm_shuffle_ps((__m128)v31, (__m128)v31, 0);
  v30.m_contactMgr = v22;
  v30.m_aTb.m_rotation.m_col0 = (hkVector4f)v20.m_quad;
  v24.m_quad = (__m128)*((_OWORD *)v5 + 5);
  v30.m_aTb.m_translation = (hkVector4f)v21.m_quad;
  v30.m_bodyA = v13;
  v30.m_bodyB = (hkpCdBody *)v14;
  v30.m_aTb.m_rotation.m_col2 = (hkVector4f)v24.m_quad;
  _mm_store_si128((__m128i *)&v30.m_radiusA, v16);
  _mm_store_si128((__m128i *)&v30.m_radiusB, v17);
  v30.m_result = output;
  v30.m_boundaryTolerance.m_real = _mm_shuffle_ps(
                                     (__m128)LODWORD(FLOAT_0_0099999998),
                                     (__m128)LODWORD(FLOAT_0_0099999998),
                                     0);
  v30.m_tolerance4.m_quad = _mm_shuffle_ps(v23, _mm_unpackhi_ps(v23, (__m128)xmmword_141A712A0), 196);
  v30.m_keepRadiusB.m_quad = _mm_add_ps(v30.m_tolerance4.m_quad, (__m128)v17);
  v30.m_keepRadiusA.m_quad = _mm_add_ps(v30.m_tolerance4.m_quad, (__m128)v16);
  hkpBoxBoxCollisionDetection::calcManifold(&v30, v6);
  v7->m_numContactPoints = v6->m_numPoints;
  v25 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v26 = (_QWORD *)v25[1];
  if ( (unsigned __int64)v26 < v25[3] )
  {
    *v26 = "Et";
    v27 = __rdtsc();
    v28 = (signed __int64)(v26 + 2);
    *(_DWORD *)(v28 - 8) = v27;
    v25[1] = v28;
  }
  return (signed __int64)&v6[1];
}

