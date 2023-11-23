// File Line: 37
// RVA: 0xC0DDF0
hkJobQueue::JobStatus __fastcall hkaiProcessAvoidanceSolverJob(
        hkJobQueue *jobQueue,
        hkJobQueue::JobQueueEntry *nextJobOut)
{
  _QWORD *Value; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  _QWORD *v7; // rcx
  hkVector4f *v8; // rsi
  int i; // edi
  hkaiLocalSteeringInput *p_Dst; // rcx
  hkVector4f *v11; // rdx
  __int64 v12; // rax
  hkVector4f v13; // xmm0
  hkVector4f v14; // xmm1
  hkVector4f v15; // xmm0
  hkVector4f v16; // xmm1
  hkVector4f v17; // xmm0
  hkVector4f v18; // xmm1
  hkVector4f v19; // xmm0
  hkVector4f v20; // xmm1
  hkVector4f v21; // xmm1
  hkVector4f v22; // xmm0
  hkVector4f v23; // xmm1
  hkVector4f v24; // xmm0
  hkResultEnum m_enum; // eax
  hkVector4f *v26; // rax
  _QWORD *v27; // r8
  _QWORD *v28; // rcx
  unsigned __int64 v29; // rax
  _QWORD *v30; // rcx
  hkVector4f up; // [rsp+90h] [rbp-70h] BYREF
  __m128 m_quad; // [rsp+A0h] [rbp-60h]
  hkVector4f steerVelocityOut; // [rsp+B0h] [rbp-50h] BYREF
  hkaiObstacleCollector v35; // [rsp+C0h] [rbp-40h] BYREF
  hkVector4f steerForwardOut; // [rsp+120h] [rbp+20h] BYREF
  hkaiLocalSteeringInput Dst; // [rsp+130h] [rbp+30h] BYREF
  int numAgents; // [rsp+1E0h] [rbp+E0h]
  unsigned int navMeshFaceKey; // [rsp+1E8h] [rbp+E8h]
  hkVector4f *v40; // [rsp+1F0h] [rbp+F0h]
  hkaiAvoidanceSolver::SteeringAgent agentIn; // [rsp+200h] [rbp+100h] BYREF
  hkResult result; // [rsp+358h] [rbp+258h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v5 < Value[3] )
  {
    *v5 = "TtAvoidanceJob";
    v6 = __rdtsc();
    v7 = v5 + 2;
    *((_DWORD *)v7 - 2) = v6;
    Value[1] = v7;
  }
  v8 = *(hkVector4f **)&nextJobOut->m_data[48];
  for ( i = 0; i < *(_DWORD *)&nextJobOut->m_data[56]; ++i )
  {
    p_Dst = &Dst;
    v11 = v8;
    if ( (((unsigned __int8)&Dst | (unsigned __int8)v8) & 0xF) != 0 )
    {
      memmove(&Dst, v8, 0xD0ui64);
    }
    else
    {
      v12 = 1i64;
      do
      {
        v13.m_quad = v11->m_quad;
        v14.m_quad = (__m128)v11[1];
        p_Dst = (hkaiLocalSteeringInput *)((char *)p_Dst + 128);
        v11 += 8;
        p_Dst[-1].m_currentUp = (hkVector4f)v13.m_quad;
        v15.m_quad = (__m128)v11[-6];
        p_Dst[-1].m_currentVelocity = (hkVector4f)v14.m_quad;
        v16.m_quad = (__m128)v11[-5];
        p_Dst[-1].m_desiredVelocity = (hkVector4f)v15.m_quad;
        v17.m_quad = (__m128)v11[-4];
        p_Dst[-1].m_desiredFutureDir = (hkVector4f)v16.m_quad;
        v18.m_quad = (__m128)v11[-3];
        p_Dst[-1].m_localGoalPlane = (hkVector4f)v17.m_quad;
        v19.m_quad = (__m128)v11[-2];
        *(hkVector4f *)&p_Dst[-1].m_distToLocalGoal = (hkVector4f)v18.m_quad;
        v20.m_quad = (__m128)v11[-1];
        *(hkVector4f *)&p_Dst[-1].m_referenceFrame = (hkVector4f)v19.m_quad;
        *(hkVector4f *)&p_Dst[-1].m_isLocalGoalLast.m_bool = (hkVector4f)v20.m_quad;
        --v12;
      }
      while ( v12 );
      v21.m_quad = (__m128)v11[1];
      p_Dst->m_currentPosition = (hkVector4f)v11->m_quad;
      v22.m_quad = (__m128)v11[2];
      p_Dst->m_currentForward = (hkVector4f)v21.m_quad;
      v23.m_quad = (__m128)v11[3];
      p_Dst->m_currentUp = (hkVector4f)v22.m_quad;
      v24.m_quad = (__m128)v11[4];
      p_Dst->m_currentVelocity = (hkVector4f)v23.m_quad;
      p_Dst->m_desiredVelocity = (hkVector4f)v24.m_quad;
    }
    up.m_quad = (__m128)Dst.m_currentUp;
    v8 += 13;
    hkaiObstacleCollector::hkaiObstacleCollector(&v35, numAgents, &Dst.m_character->m_position, &up);
    hkaiAvoidanceSolverUtils::setupAgent(
      &Dst,
      *(hkaiObstacleCollector **)&nextJobOut->m_data[24],
      navMeshFaceKey,
      *(float *)&nextJobOut->m_data[20]);
    m_enum = hkaiAvoidanceSolverUtils::calcSteeringVelocity(
               &result,
               *(float *)&nextJobOut->m_data[16],
               &up,
               &agentIn,
               &steerVelocityOut,
               &steerForwardOut)->m_enum;
    m_quad = steerForwardOut.m_quad;
    v35.m_neighborAgents.m_size = 0;
    m_quad.m128_i32[3] = m_enum | 0x3F000000;
    if ( v35.m_neighborAgents.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        v35.m_neighborAgents.m_data,
        80 * (v35.m_neighborAgents.m_capacityAndFlags & 0x3FFFFFFF));
    v35.m_neighborAgents.m_data = 0i64;
    v35.m_neighborAgents.m_capacityAndFlags = 0x80000000;
    v35.m_boundaries.m_size = 0;
    if ( v35.m_boundaries.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        v35.m_boundaries.m_data,
        32 * v35.m_boundaries.m_capacityAndFlags);
    v35.m_boundaries.m_data = 0i64;
    v35.m_boundaries.m_capacityAndFlags = 0x80000000;
    v35.m_spheres.m_size = 0;
    if ( v35.m_spheres.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        v35.m_spheres.m_data,
        32 * v35.m_spheres.m_capacityAndFlags);
    v26 = v40;
    *v40 = (hkVector4f)m_quad;
    v26[1] = (hkVector4f)steerVelocityOut.m_quad;
  }
  v27 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v28 = (_QWORD *)v27[1];
  if ( (unsigned __int64)v28 < v27[3] )
  {
    *v28 = "Et";
    v29 = __rdtsc();
    v30 = v28 + 2;
    *((_DWORD *)v30 - 2) = v29;
    v27[1] = v30;
  }
  return hkJobQueue::finishJobAndGetNextJob(jobQueue, nextJobOut, nextJobOut, WAIT_FOR_NEXT_JOB);
}

