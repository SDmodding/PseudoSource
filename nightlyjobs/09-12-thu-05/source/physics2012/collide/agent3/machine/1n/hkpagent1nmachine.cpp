// File Line: 55
// RVA: 0xD3B170
void __fastcall hkAgent1nMachine_Destroy(
        hkpAgent1nTrack *agentTrack,
        hkpCollisionDispatcher *dispatcher,
        hkpContactMgr *mgr,
        hkpConstraintOwner *constraintOwner)
{
  hkpAgent1nSector **m_data; // r15
  int v5; // ebp
  hkpAgent1nSector *v7; // r10
  hkpAgentEntry *v10; // rbx
  unsigned __int64 v11; // r14
  __int64 v12; // rdi
  unsigned __int64 v13; // r9
  hkpAgentEntry *v14; // rcx
  hkpAgentEntry *v15; // rdx
  hkpAgentEntry *v16; // rdx
  hkpAgent1nSector *v17; // rbx
  _QWORD **v18; // rax
  hkpAgent1nSector *v19; // rcx
  hkpAgent1nSector *v20; // rbx
  _QWORD **Value; // rax
  int m_capacityAndFlags; // r8d
  hkpContactMgr *v23; // [rsp+70h] [rbp+18h]

  v23 = mgr;
  m_data = agentTrack->m_sectors.m_data;
  v5 = 0;
  v7 = *agentTrack->m_sectors.m_data;
  v10 = (hkpAgentEntry *)v7->m_data;
  v11 = (unsigned __int64)&v7->m_data[v7->m_bytesAllocated];
  v12 = 0i64;
  while ( 1 )
  {
    v13 = 0x140000000ui64;
    do
    {
      v14 = v10;
      switch ( v10->m_streamCommand )
      {
        case 0:
          v10 = (hkpAgentEntry *)((char *)v10 + (unsigned __int8)v10->m_size);
          break;
        case 1:
          v20 = m_data[v5];
          if ( v20 )
          {
            Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
            (*(void (__fastcall **)(_QWORD *, hkpAgent1nSector *, __int64))(*Value[11] + 16i64))(Value[11], v20, 512i64);
          }
          m_capacityAndFlags = agentTrack->m_sectors.m_capacityAndFlags;
          agentTrack->m_sectors.m_size = 0;
          if ( m_capacityAndFlags >= 0 )
            ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, hkpAgent1nSector **, _QWORD, unsigned __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
              &hkContainerHeapAllocator::s_alloc,
              agentTrack->m_sectors.m_data,
              (unsigned int)(8 * m_capacityAndFlags),
              v13);
          agentTrack->m_sectors.m_capacityAndFlags = 0x80000000;
          agentTrack->m_sectors.m_data = 0i64;
          return;
        case 2:
        case 3:
        case 6:
        case 0xA:
        case 0xB:
        case 0xE:
          v15 = v10 + 4;
          v10 = (hkpAgentEntry *)((char *)v10 + (unsigned __int8)v10->m_size);
          dispatcher->m_agent3Func[(unsigned __int8)v14->m_agentType].m_destroyFunc(
            v14,
            v15,
            mgr,
            constraintOwner,
            dispatcher);
          mgr = v23;
          v13 = 0x140000000ui64;
          break;
        case 4:
        case 5:
        case 0xC:
        case 0xD:
          v16 = v10 + 8;
          v10 = (hkpAgentEntry *)((char *)v10 + (unsigned __int8)v10->m_size);
          dispatcher->m_agent3Func[(unsigned __int8)v14->m_agentType].m_destroyFunc(
            v14,
            v16,
            mgr,
            constraintOwner,
            dispatcher);
          mgr = v23;
          v13 = 0x140000000ui64;
          break;
        default:
          break;
      }
    }
    while ( (unsigned __int64)v10 < v11 );
    v17 = m_data[v12];
    ++v5;
    ++v12;
    if ( v17 )
    {
      v18 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, hkpAgent1nSector *, __int64))(*v18[11] + 16i64))(v18[11], v17, 512i64);
    }
    mgr = v23;
    v19 = agentTrack->m_sectors.m_data[v12];
    v10 = (hkpAgentEntry *)v19->m_data;
    v11 = (unsigned __int64)&v19->m_data[v19->m_bytesAllocated];
  }
}

// File Line: 153
// RVA: 0xD3B360
void __fastcall hkAgent1nMachine_InvalidateTim(hkpAgent1nTrack *agentTrack, hkpCollisionInput *input)
{
  hkpAgent1nSector *v4; // r8
  __int64 v5; // rdi
  __int64 m_bytesAllocated; // rax
  char *m_data; // rbx
  char *i; // rsi
  char *v9; // rsi
  hkpAgentEntry *v10; // r9
  void *v11; // rdx
  void (__fastcall *m_invalidateTimFunc)(hkpAgentEntry *, void *, hkpCollisionInput *); // r10
  __int64 v13; // rax
  __int64 v14; // rcx
  hkpAgent1nSector *v15; // rcx

  v4 = *agentTrack->m_sectors.m_data;
  v5 = 1i64;
  m_bytesAllocated = v4->m_bytesAllocated;
  m_data = v4->m_data;
  for ( i = v4->m_data; ; i = v15->m_data )
  {
    v9 = &i[m_bytesAllocated];
    do
    {
      v10 = (hkpAgentEntry *)m_data;
      switch ( *m_data )
      {
        case 0:
          m_data += (unsigned __int8)m_data[3];
          break;
        case 1:
          return;
        case 2:
        case 3:
        case 6:
        case 10:
        case 11:
        case 14:
          v11 = m_data + 16;
          m_data += (unsigned __int8)m_data[3];
          m_invalidateTimFunc = input->m_dispatcher.m_storage->m_agent3Func[(unsigned __int8)v10->m_agentType].m_invalidateTimFunc;
          goto LABEL_5;
        case 4:
        case 5:
        case 12:
        case 13:
          v13 = (unsigned __int8)m_data[3];
          v14 = (unsigned __int8)m_data[1];
          *((_DWORD *)m_data + 3) = -1082130432;
          *((_OWORD *)m_data + 1) = 0i64;
          v11 = m_data + 32;
          m_data += v13;
          m_invalidateTimFunc = input->m_dispatcher.m_storage->m_agent3Func[v14].m_invalidateTimFunc;
LABEL_5:
          if ( m_invalidateTimFunc )
            m_invalidateTimFunc(v10, v11, input);
          break;
        default:
          break;
      }
    }
    while ( m_data < v9 );
    v15 = agentTrack->m_sectors.m_data[v5++];
    m_bytesAllocated = v15->m_bytesAllocated;
    m_data = v15->m_data;
  }
}

// File Line: 233
// RVA: 0xD3B4A0
void __fastcall hkAgent1nMachine_WarpTime(
        hkpAgent1nTrack *agentTrack,
        float oldTime,
        float newTime,
        hkpCollisionInput *input)
{
  __int64 v6; // rdi
  hkpAgent1nSector *v7; // rdx
  char *m_data; // rbx
  unsigned __int64 v9; // rsi
  char *v10; // r9
  char *v11; // rdx
  void (__fastcall *m_warpTimeFunc)(hkpAgentEntry *, void *, float, float, hkpCollisionInput *); // r10
  char *v13; // rdx
  void (__fastcall *v14)(hkpAgentEntry *, void *, float, float, hkpCollisionInput *); // r8
  hkpAgent1nSector *v15; // rcx

  v6 = 1i64;
  v7 = *agentTrack->m_sectors.m_data;
  m_data = v7->m_data;
  v9 = (unsigned __int64)&v7->m_data[v7->m_bytesAllocated];
  while ( 1 )
  {
    v10 = m_data;
    switch ( *m_data )
    {
      case 0:
        m_data += (unsigned __int8)m_data[3];
        break;
      case 1:
        return;
      case 2:
      case 3:
      case 6:
      case 10:
      case 11:
      case 14:
        v11 = m_data + 16;
        m_data += (unsigned __int8)m_data[3];
        m_warpTimeFunc = input->m_dispatcher.m_storage->m_agent3Func[(unsigned __int8)v10[1]].m_warpTimeFunc;
        if ( m_warpTimeFunc )
          ((void (__fastcall *)(char *, char *))m_warpTimeFunc)(v10, v11);
        break;
      case 4:
      case 5:
      case 12:
      case 13:
        v13 = m_data + 32;
        if ( oldTime == *((float *)m_data + 3) )
          *((float *)m_data + 3) = newTime;
        else
          *((_DWORD *)m_data + 3) = -1082130432;
        m_data += (unsigned __int8)m_data[3];
        v14 = input->m_dispatcher.m_storage->m_agent3Func[(unsigned __int8)v10[1]].m_warpTimeFunc;
        if ( v14 )
          ((void (__fastcall *)(char *, char *))v14)(v10, v13);
        break;
      default:
        break;
    }
    if ( (unsigned __int64)m_data >= v9 )
    {
      v15 = agentTrack->m_sectors.m_data[v6];
      m_data = v15->m_data;
      v9 = (unsigned __int64)&v15->m_data[v15->m_bytesAllocated];
      ++v6;
    }
  }
}

// File Line: 324
// RVA: 0xD3BF70
hkpAgent1nMachineEntry *__fastcall hkAgent1nMachine_FindAgent(
        hkpAgent1nTrack *agentTrack,
        hkpShapeKeyPair keyPair,
        hkpShapeKeyPair **agentDataOut)
{
  hkpAgent1nSector **m_data; // r10
  __int64 m_bytesAllocated; // rcx
  hkpAgent1nMachineEntry *result; // rax
  hkpAgent1nMachineEntry *v6; // r11
  unsigned __int64 v7; // r11
  hkpShapeKeyPair *p_m_shapeKeyPair; // rcx

  m_data = agentTrack->m_sectors.m_data;
  m_bytesAllocated = **(unsigned int **)agentTrack->m_sectors.m_data;
  result = (hkpAgent1nMachineEntry *)(*m_data)->m_data;
  v6 = result;
  while ( 2 )
  {
    v7 = (unsigned __int64)v6 + m_bytesAllocated;
    ++m_data;
LABEL_3:
    switch ( result->m_streamCommand )
    {
      case 0:
        goto $LN5_184;
      case 1:
        return 0i64;
      case 2:
      case 3:
      case 6:
      case 0xA:
      case 0xB:
      case 0xE:
        p_m_shapeKeyPair = &result[1].m_shapeKeyPair;
        goto LABEL_6;
      case 4:
      case 5:
      case 0xC:
      case 0xD:
        p_m_shapeKeyPair = (hkpShapeKeyPair *)&result[2].m_shapeKeyPair.m_shapeKeyB;
LABEL_6:
        if ( *(_QWORD *)&result->m_shapeKeyPair != keyPair )
        {
$LN5_184:
          result = (hkpAgent1nMachineEntry *)((char *)result + (unsigned __int8)result->m_size);
LABEL_9:
          if ( (unsigned __int64)result >= v7 )
          {
            m_bytesAllocated = (*m_data)->m_bytesAllocated;
            result = (hkpAgent1nMachineEntry *)(*m_data)->m_data;
            v6 = result;
            continue;
          }
          goto LABEL_3;
        }
        *agentDataOut = p_m_shapeKeyPair;
        return result;
      default:
        goto LABEL_9;
    }
  }
}

// File Line: 437
// RVA: 0xD3AB70
void __fastcall hkAgent1nMachine_Create(hkpAgent1nTrack *agentTrack)
{
  int v2; // r9d
  _QWORD **Value; // rax
  _DWORD *v4; // rax
  _DWORD *v5; // rcx
  hkResult result; // [rsp+40h] [rbp+8h] BYREF

  agentTrack->m_sectors.m_size = 0;
  if ( (agentTrack->m_sectors.m_capacityAndFlags & 0x3FFFFFFFu) < 4 )
  {
    v2 = 4;
    if ( 2 * (agentTrack->m_sectors.m_capacityAndFlags & 0x3FFFFFFF) > 4 )
      v2 = 2 * (agentTrack->m_sectors.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&agentTrack->m_sectors.m_data,
      v2,
      8);
  }
  if ( agentTrack->m_sectors.m_size == (agentTrack->m_sectors.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&agentTrack->m_sectors.m_data, 8);
  ++agentTrack->m_sectors.m_size;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v4 = (_DWORD *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 512i64);
  v5 = v4;
  if ( v4 )
    *v4 = 0;
  else
    v5 = 0i64;
  *agentTrack->m_sectors.m_data = (hkpAgent1nSector *)v5;
  *((_BYTE *)v5 + 19) = 16;
  *((_BYTE *)v5 + 16) = 1;
  *(_QWORD *)(v5 + 5) = -1i64;
  *v5 = 16;
}

// File Line: 468
// RVA: 0xD3C050
__int64 __fastcall contactPointIsValid(
        float radiusA,
        hkContactPoint *pointToCheck,
        hkpCollisionQualityInfo *qi,
        float radiusB,
        hkpProcessCdPoint *referenceCdPoint)
{
  hkVector4f v5; // xmm5
  hkVector4f v6; // xmm4
  __m128 v7; // xmm1
  __m128 v8; // xmm9
  __m128 v9; // xmm0
  __m128 v10; // xmm6
  __m128 v11; // xmm1
  __m128 v12; // xmm6
  __m128 v13; // xmm3
  __m128 v14; // xmm2
  __m128 v15; // xmm0
  __m128 v16; // xmm6
  float v17; // xmm3_4
  __m128 v18; // xmm6
  __m128 v19; // xmm2
  __m128 v20; // xmm8
  __m128 v21; // xmm9
  __m128 v22; // xmm1
  __m128 v23; // xmm10
  __m128 v24; // xmm6

  v5.m_quad = (__m128)pointToCheck->m_separatingNormal;
  v6.m_quad = (__m128)referenceCdPoint->m_contact.m_separatingNormal;
  v7 = _mm_sub_ps(referenceCdPoint->m_contact.m_position.m_quad, pointToCheck->m_position.m_quad);
  v8 = (__m128)LODWORD(radiusB);
  v9 = _mm_mul_ps(v6.m_quad, v7);
  v10 = _mm_mul_ps(v5.m_quad, v7);
  v11 = _mm_unpacklo_ps(v10, v9);
  v12 = _mm_unpackhi_ps(v10, v9);
  v13 = _mm_mul_ps(v6.m_quad, v5.m_quad);
  v14 = _mm_movelh_ps(v11, v13);
  v15 = _mm_shuffle_ps(_mm_movehl_ps(v14, v11), v13, 212);
  v16 = _mm_shuffle_ps(v12, v13, 228);
  v17 = 0.0;
  v18 = _mm_add_ps(v16, _mm_add_ps(v14, v15));
  v19 = _mm_shuffle_ps((__m128)LODWORD(radiusA), (__m128)LODWORD(radiusA), 0);
  v20 = _mm_shuffle_ps(v18, v18, 170);
  v21 = _mm_add_ps(_mm_shuffle_ps(v8, v8, 0), v19);
  v22 = _mm_mul_ps(_mm_sub_ps(v20, query.m_quad), v19);
  v23 = _mm_add_ps(_mm_sub_ps((__m128)0i64, _mm_shuffle_ps(v18, v18, 85)), v22);
  v24 = _mm_add_ps(_mm_shuffle_ps(v18, v18, 0), v22);
  if ( v23.m128_f32[0] > v21.m128_f32[0]
    || v20.m128_f32[0] > _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_99989998), (__m128)LODWORD(FLOAT_0_99989998), 0).m128_f32[0]
    && referenceCdPoint->m_contactPointId == 0xFFFF )
  {
    return 0i64;
  }
  if ( referenceCdPoint->m_contactPointId == 0xFFFF )
  {
    if ( _mm_movemask_ps(
           _mm_and_ps(
             _mm_cmplt_ps(
               _mm_add_ps(_mm_shuffle_ps(v5.m_quad, v5.m_quad, 255), _mm_shuffle_ps(v6.m_quad, v6.m_quad, 255)),
               _mm_sub_ps((__m128)0i64, _mm_add_ps(v21, v21))),
             _mm_and_ps(
               _mm_cmplt_ps(
                 _mm_add_ps(v24, v23),
                 _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_1), (__m128)LODWORD(FLOAT_0_1), 0)),
               _mm_cmplt_ps(
                 v20,
                 _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_80000001), (__m128)LODWORD(FLOAT_0_80000001), 0))))) )
    {
      return 2i64;
    }
  }
  else
  {
    v17 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_050000001), (__m128)LODWORD(FLOAT_0_050000001), 0).m128_f32[0]
        * _mm_shuffle_ps((__m128)LODWORD(qi->m_keepContact), (__m128)LODWORD(qi->m_keepContact), 0).m128_f32[0];
  }
  return _mm_shuffle_ps(v5.m_quad, v5.m_quad, 255).m128_f32[0] > (float)(_mm_shuffle_ps(v6.m_quad, v6.m_quad, 255).m128_f32[0]
                                                                       - v17);
}

// File Line: 573
// RVA: 0xD3B770
void __fastcall hkAgent1nMachine_Weld(
        hkpAgent3Input *input,
        hkpShapeContainer *shapeCollection,
        hkpProcessCollisionOutput *output,
        __int64 a4)
{
  hkpProcessCollisionOutput::PotentialInfo *m_storage; // rsi
  __int64 v5; // r15
  hkpProcessCollisionOutput::ContactRef *m_potentialContacts; // r12
  int v8; // r13d
  hkpShape *m_shape; // r8
  hkpProcessCdPoint **m_representativeContacts; // rcx
  hkpProcessCdPoint **m_firstFreeRepresentativeContact; // r10
  __m128 *p_m_quad; // r11
  __m128 *v13; // rdx
  __m128 v14; // xmm6
  __m128 v15; // xmm5
  hkpProcessCollisionInput *v16; // rax
  hkpCollisionQualityInfo *v17; // rbx
  __m128 v18; // xmm3
  __m128 v19; // xmm4
  __m128 v20; // xmm2
  __m128 v21; // xmm1
  __m128 v22; // xmm4
  __m128 v23; // xmm1
  __m128 v24; // xmm4
  __m128 v25; // xmm0
  __m128 v26; // xmm2
  __m128 v27; // xmm7
  float v28; // xmm3_4
  __m128 v29; // xmm9
  __m128 v30; // xmm7
  __m128 v31; // xmm8
  __m128 v32; // xmm1
  __m128 v33; // xmm10
  __m128 v34; // xmm7
  int v35; // r8d
  __m128 m_keepContact_low; // xmm0
  hkpConvexShape *v37; // rax
  hkpAgentEntry *m_agentEntry; // rbx
  hkpConvexShape *v39; // rax
  hkpProcessCollisionInput *v40; // r9
  hkpCdBody *v41; // rdx
  hkpAgentEntry v42; // ecx
  hkpProcessCdPoint *m_contactPoint; // rax
  __int16 v44; // ax
  int v45; // r12d
  hkpCollisionDispatcher *v46; // rdi
  __int64 v47; // rbx
  hkpAgentEntry *v48; // rcx
  _QWORD *Value; // r8
  _QWORD *v50; // rcx
  unsigned __int64 v51; // rax
  _QWORD *v52; // rcx
  __m128 v53; // xmm7
  __m128i v54; // xmm9
  __m128i v55; // xmm6
  __m128i v56; // xmm5
  __int64 v57; // r8
  __int16 *v58; // r9
  __int64 v59; // r10
  __int64 v60; // rdx
  __m128i v61; // xmm8
  __m128i i; // xmm4
  __int64 v63; // rax
  __m128 v64; // xmm1
  __m128 v65; // xmm2
  __m128 v66; // xmm3
  __m128i v67; // xmm2
  __m128i v68; // xmm0
  __int64 v69; // r15
  __int64 v70; // r12
  hkpAgentEntry *v71; // rdx
  hkpConvexShape *v72; // rdi
  __int64 v73; // rax
  hkpCdBody *v74; // rdx
  hkpConvexShape *v75; // r8
  __int16 v76; // ax
  unsigned int m_slotID; // ecx
  __int16 v78; // ax
  _QWORD *v79; // rax
  _QWORD *v80; // rcx
  _QWORD *v81; // r8
  unsigned __int64 v82; // rax
  _QWORD *v83; // rcx
  bool v84; // zf
  hkVector4f **v85; // r12
  __int64 v86; // rbx
  __int64 v87; // rdx
  hkpContactMgr *v88; // rcx
  hkBaseObjectVtbl *vfptr; // rax
  hkpProcessCollisionOutput::ContactRef *m_firstFreePotentialContact; // rbx
  hkpCollisionDispatcher *v91; // r15
  __int64 v92; // rcx
  __int64 j; // rsi
  unsigned __int16 v94; // di
  hkVector4f *v95; // rdx
  hkpProcessCdPoint *v96; // rcx
  hkpShape *v97; // [rsp+40h] [rbp-80h]
  __int64 v98; // [rsp+48h] [rbp-78h] BYREF
  hkpConvexShape *shapeBs; // [rsp+50h] [rbp-70h] BYREF
  __int64 v100; // [rsp+58h] [rbp-68h]
  const void *m_motion; // [rsp+60h] [rbp-60h]
  hkpCdBody *v102; // [rsp+68h] [rbp-58h]
  hkContactPoint *pointsOut; // [rsp+70h] [rbp-50h] BYREF
  hkpConvexShape *shapeA; // [rsp+78h] [rbp-48h]
  __int16 v105[512]; // [rsp+80h] [rbp-40h] BYREF
  char v106[512]; // [rsp+480h] [rbp+3C0h] BYREF
  char v107[576]; // [rsp+680h] [rbp+5C0h] BYREF
  int v108; // [rsp+940h] [rbp+880h]
  __int64 v109; // [rsp+948h] [rbp+888h]
  __int64 v110; // [rsp+950h] [rbp+890h] BYREF
  hkResult result; // [rsp+958h] [rbp+898h] BYREF

  m_storage = output->m_potentialContacts.m_storage;
  v5 = 0i64;
  m_potentialContacts = m_storage->m_potentialContacts;
  v108 = 0;
  v8 = 0;
  m_shape = input->m_bodyA.m_storage->m_shape;
  v97 = m_shape;
  if ( m_storage->m_potentialContacts < m_storage->m_firstFreePotentialContact )
  {
    m_representativeContacts = m_storage->m_representativeContacts;
    shapeBs = (hkpConvexShape *)v105;
    while ( 1 )
    {
      m_firstFreeRepresentativeContact = m_storage->m_firstFreeRepresentativeContact;
      p_m_quad = &m_potentialContacts->m_contactPoint->m_contact.m_position.m_quad;
      LOBYTE(a4) = 0;
      v105[v8 + 256] = -1;
      if ( m_representativeContacts < m_firstFreeRepresentativeContact )
        break;
LABEL_18:
      m_agentEntry = m_storage->m_potentialContacts[v8].m_agentEntry;
      v39 = (hkpConvexShape *)(*(__int64 (__fastcall **)(__int64, _QWORD, char *, __int64))(*(_QWORD *)v109 + 40i64))(
                                v109,
                                *(_DWORD *)&m_agentEntry[2],
                                v106,
                                a4);
      v40 = input->m_input.m_storage;
      v41 = input->m_bodyA.m_storage;
      v102 = input->m_bodyB.m_storage;
      m_motion = v102->m_motion;
      v42 = m_agentEntry[2];
      shapeBs = v39;
      m_contactPoint = m_storage->m_potentialContacts[v8].m_contactPoint;
      LODWORD(v100) = v42;
      v44 = ((__int64 (__fastcall *)(hkpContactMgr *, hkpCdBody *, hkpConvexShape **, hkpProcessCollisionInput *, __int64, _QWORD, hkpProcessCdPoint *))input->m_contactMgr.m_storage->vfptr[1].__first_virtual_table_function__)(
              input->m_contactMgr.m_storage,
              v41,
              &shapeBs,
              v40,
              v110,
              0i64,
              m_contactPoint);
      v105[v8 + 256] = v44;
      if ( v44 != -1 )
        ((void (__fastcall *)(hkpContactMgr *, __int64 *, __int64))input->m_contactMgr.m_storage->vfptr[2].__vecDelDtor)(
          input->m_contactMgr.m_storage,
          &v98,
          0xFFFFFFFFi64);
$tryNextPoint:
      m_shape = v97;
      ++m_potentialContacts;
      ++v8;
      m_representativeContacts = m_storage->m_representativeContacts;
      if ( m_potentialContacts >= m_storage->m_firstFreePotentialContact )
        goto LABEL_21;
    }
    while ( 1 )
    {
      v13 = (__m128 *)*m_representativeContacts;
      if ( p_m_quad == (__m128 *)*m_representativeContacts )
        goto LABEL_15;
      v14 = p_m_quad[1];
      v15 = v13[1];
      v16 = input->m_input.m_storage;
      result.m_enum = (hkResultEnum)m_shape[1].vfptr;
      LODWORD(pointsOut) = 0;
      v17 = v16->m_collisionQualityInfo.m_storage;
      v18 = _mm_mul_ps(v15, v14);
      v19 = _mm_sub_ps(*v13, *p_m_quad);
      v20 = _mm_mul_ps(v19, v15);
      v21 = _mm_mul_ps(v19, v14);
      v22 = _mm_unpackhi_ps(v21, v20);
      v23 = _mm_unpacklo_ps(v21, v20);
      v24 = _mm_shuffle_ps(v22, v18, 228);
      v25 = _mm_movelh_ps(v23, v18);
      v26 = _mm_shuffle_ps((__m128)(unsigned int)result.m_enum, (__m128)(unsigned int)result.m_enum, 0);
      v27 = _mm_shuffle_ps(_mm_movehl_ps(v25, v23), v18, 212);
      v28 = 0.0;
      v29 = _mm_add_ps(_mm_shuffle_ps((__m128)0, (__m128)0, 0), v26);
      v30 = _mm_add_ps(_mm_add_ps(v27, v25), v24);
      v31 = _mm_shuffle_ps(v30, v30, 170);
      v32 = _mm_mul_ps(_mm_sub_ps(v31, query.m_quad), v26);
      v33 = _mm_add_ps(_mm_sub_ps((__m128)0i64, _mm_shuffle_ps(v30, v30, 85)), v32);
      v34 = _mm_add_ps(_mm_shuffle_ps(v30, v30, 0), v32);
      if ( v33.m128_f32[0] > v29.m128_f32[0] )
        goto LABEL_15;
      LODWORD(m_motion) = 1065351538;
      if ( v31.m128_f32[0] > _mm_shuffle_ps((__m128)0x3F7FF972u, (__m128)0x3F7FF972u, 0).m128_f32[0]
        && v13[2].m128_i32[0] == 0xFFFF )
      {
        goto LABEL_15;
      }
      v35 = v13[2].m128_i32[0];
      LODWORD(v97) = 1061997773;
      LODWORD(shapeA) = 1036831949;
      if ( v35 != 0xFFFF )
        break;
      if ( !_mm_movemask_ps(
              _mm_and_ps(
                _mm_cmplt_ps(
                  _mm_add_ps(_mm_shuffle_ps(v15, v15, 255), _mm_shuffle_ps(v14, v14, 255)),
                  _mm_sub_ps((__m128)0i64, _mm_add_ps(v29, v29))),
                _mm_and_ps(
                  _mm_cmplt_ps(_mm_add_ps(v34, v33), _mm_shuffle_ps((__m128)0x3DCCCCCDu, (__m128)0x3DCCCCCDu, 0)),
                  _mm_cmplt_ps(v31, _mm_shuffle_ps((__m128)0x3F4CCCCDu, (__m128)0x3F4CCCCDu, 0))))) )
        goto LABEL_13;
      LOBYTE(a4) = 1;
LABEL_14:
      m_shape = v97;
LABEL_15:
      if ( ++m_representativeContacts >= m_firstFreeRepresentativeContact )
      {
        if ( (_BYTE)a4 )
        {
          v37 = shapeBs;
          ++v108;
          LOWORD(shapeBs->vfptr) = v8;
          shapeBs = (hkpConvexShape *)((char *)&v37->vfptr + 2);
        }
        goto LABEL_18;
      }
    }
    m_keepContact_low = (__m128)LODWORD(v17->m_keepContact);
    LODWORD(v102) = 1028443341;
    v28 = _mm_shuffle_ps((__m128)0x3D4CCCCDu, (__m128)0x3D4CCCCDu, 0).m128_f32[0]
        * _mm_shuffle_ps(m_keepContact_low, m_keepContact_low, 0).m128_f32[0];
LABEL_13:
    if ( _mm_shuffle_ps(v14, v14, 255).m128_f32[0] > (float)(_mm_shuffle_ps(v15, v15, 255).m128_f32[0] - v28) )
      goto $tryNextPoint;
    goto LABEL_14;
  }
LABEL_21:
  v45 = v108;
  v46 = input->m_input.m_storage->m_dispatcher.m_storage;
  v47 = v108;
  if ( v108 > 0 )
  {
    do
    {
      v48 = m_storage->m_potentialContacts[(unsigned __int16)v105[v5]].m_agentEntry;
      v46->m_agent3Func[(unsigned __int8)v48->m_agentType].m_createZombieFunc(
        v48,
        m_storage->m_potentialContacts[(unsigned __int16)v105[v5++]].m_agentData,
        0xFFFFu);
    }
    while ( v5 < v47 );
  }
  if ( v47 >= 2 )
  {
    do
    {
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v50 = (_QWORD *)Value[1];
      if ( (unsigned __int64)v50 < Value[3] )
      {
        *v50 = "TtConflicts";
        v51 = __rdtsc();
        v52 = v50 + 2;
        *((_DWORD *)v52 - 2) = v51;
        Value[1] = v52;
      }
      v53 = (__m128)xmmword_141A710D0;
      v54 = 0i64;
      v55 = (__m128i)xmmword_141A72090;
      v56 = 0i64;
      v57 = 1i64;
      v58 = v105;
      v59 = v47;
      do
      {
        v60 = v57;
        v61 = _mm_add_epi32((__m128i)xmmword_141A72090, v54);
        for ( i = v61; v60 < v47; v55 = _mm_or_si128(_mm_and_si128(v68, v67), _mm_andnot_si128(v67, v55)) )
        {
          v63 = (unsigned __int16)v105[v60++];
          v64 = _mm_mul_ps(
                  m_storage->m_potentialContacts[v63].m_contactPoint->m_contact.m_separatingNormal.m_quad,
                  m_storage->m_potentialContacts[(unsigned __int16)*v58].m_contactPoint->m_contact.m_separatingNormal.m_quad);
          v65 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v64, v64, 85), _mm_shuffle_ps(v64, v64, 0)),
                  _mm_shuffle_ps(v64, v64, 170));
          v66 = _mm_min_ps(v65, v53);
          v67 = (__m128i)_mm_cmplt_ps(v65, v53);
          v53 = v66;
          v56 = _mm_or_si128(_mm_and_si128(v54, v67), _mm_andnot_si128(v67, v56));
          v68 = i;
          i = _mm_add_epi32(i, (__m128i)xmmword_141A72090);
        }
        ++v58;
        ++v57;
        v54 = v61;
        --v59;
      }
      while ( v59 );
      LODWORD(shapeBs) = v56.m128i_i32[0];
      v69 = v56.m128i_i32[0];
      v70 = 3 * ((unsigned __int16)v105[v56.m128i_i32[0]] + 86i64);
      v71 = m_storage->m_potentialContacts[(unsigned __int16)v105[v56.m128i_i32[0]]].m_agentEntry;
      v102 = (hkpCdBody *)(3 * ((unsigned __int16)v105[v55.m128i_i32[0]] + 86i64));
      v98 = *((_QWORD *)&m_storage->m_firstFreeRepresentativeContact + (_QWORD)v102);
      shapeA = (hkpConvexShape *)input->m_bodyA.m_storage->m_shape;
      if ( (input->m_input.m_storage->m_dispatcher.m_storage->m_hasAlternateType[(unsigned __int8)shapeA->m_type.m_storage] & 0x800000) == 0 )
        break;
      v72 = (hkpConvexShape *)(*(__int64 (__fastcall **)(__int64, _QWORD, char *, __int16 *))(*(_QWORD *)v109 + 40i64))(
                                v109,
                                *(_DWORD *)&v71[2],
                                v106,
                                v58);
      if ( (input->m_input.m_storage->m_dispatcher.m_storage->m_hasAlternateType[(unsigned __int8)v72->m_type.m_storage] & 0x800000) == 0 )
        break;
      v73 = (*(__int64 (__fastcall **)(__int64, _QWORD, char *))(*(_QWORD *)v109 + 40i64))(
              v109,
              *(unsigned int *)(v98 + 8),
              v107);
      if ( (input->m_input.m_storage->m_dispatcher.m_storage->m_hasAlternateType[*(unsigned __int8 *)(v73 + 16)] & 0x800000) == 0 )
        break;
      v74 = input->m_bodyA.m_storage;
      v75 = shapeA;
      v100 = v73;
      shapeBs = v72;
      pointsOut = (hkContactPoint *)(&m_storage->m_firstFreePotentialContact)[v70];
      shapeA = (hkpConvexShape *)*((_QWORD *)&m_storage->m_firstFreePotentialContact + (_QWORD)v102);
      hkCalcMultiPenetrationDepth(&result, (hkTransformf *)v74->m_motion, v75, &shapeBs, 2, &input->m_aTb, &pointsOut);
      v76 = v105[v47 - 1];
      m_slotID = hkMonitorStream__m_instance.m_slotID;
      v108 -= 2;
      v105[v55.m128i_i32[0]] = v76;
      v78 = v105[v47 - 2];
      v47 -= 2i64;
      v105[v69] = v78;
      v79 = TlsGetValue(m_slotID);
      v80 = (_QWORD *)v79[1];
      v81 = v79;
      if ( (unsigned __int64)v80 < v79[3] )
      {
        *v80 = "Et";
        v82 = __rdtsc();
        v83 = v80 + 2;
        *((_DWORD *)v83 - 2) = v82;
        v81[1] = v83;
      }
    }
    while ( v47 >= 2 );
    v45 = v108;
  }
  v84 = v45 == 0;
  v85 = (hkVector4f **)v110;
  if ( !v84 )
  {
    v86 = (unsigned __int16)v105[0];
    v87 = (unsigned __int16)v105[(unsigned __int16)v105[0] + 256];
    if ( (_WORD)v87 != 0xFFFF )
    {
      ((void (__fastcall *)(hkpContactMgr *, __int64, _QWORD))input->m_contactMgr.m_storage->vfptr[2].__first_virtual_table_function__)(
        input->m_contactMgr.m_storage,
        v87,
        *(_QWORD *)(v110 + 8));
      v88 = input->m_contactMgr.m_storage;
      vfptr = v88->vfptr;
      v105[v86 + 256] = -1;
      ((void (__fastcall *)(hkpContactMgr *, __int64 *, __int64))vfptr[2].__vecDelDtor)(v88, &v110, 1i64);
    }
  }
  m_firstFreePotentialContact = m_storage->m_firstFreePotentialContact;
  v91 = input->m_input.m_storage->m_dispatcher.m_storage;
  v92 = (char *)m_storage->m_firstFreePotentialContact - (char *)m_storage - 2064;
  for ( j = (int)v92 / 24 - 1; j >= 0; --j )
  {
    v94 = v105[j + 256];
    --m_firstFreePotentialContact;
    if ( v94 == 0xFFFF )
    {
      ((void (__fastcall *)(hkpContactMgr *, __int64 *, __int64))input->m_contactMgr.m_storage->vfptr[2].__vecDelDtor)(
        input->m_contactMgr.m_storage,
        &v110,
        0xFFFFFFFFi64);
      v91->m_agent3Func[(unsigned __int8)m_firstFreePotentialContact->m_agentEntry->m_agentType].m_removePointFunc(
        m_firstFreePotentialContact->m_agentEntry,
        m_firstFreePotentialContact->m_agentData,
        0xFFFFu);
      *v85 -= 3;
      v95 = *v85;
      v96 = m_firstFreePotentialContact->m_contactPoint;
      v96->m_contact.m_position = (hkVector4f)(*v85)->m_quad;
      v96->m_contact.m_separatingNormal = (hkVector4f)v95[1].m_quad;
      v96->m_contactPointId = v95[2].m_quad.m128_u32[0];
      v96->m_padding[0] = v95[2].m_quad.m128_u32[1];
      v96->m_padding[1] = v95[2].m_quad.m128_u32[2];
      v96->m_padding[2] = v95[2].m_quad.m128_u32[3];
    }
    else
    {
      v91->m_agent3Func[(unsigned __int8)m_firstFreePotentialContact->m_agentEntry->m_agentType].m_commitPotentialFunc(
        m_firstFreePotentialContact->m_agentEntry,
        m_firstFreePotentialContact->m_agentData,
        v94);
      m_firstFreePotentialContact->m_contactPoint->m_contactPointId = v94;
    }
  }
}

// File Line: 793
// RVA: 0xD3AC80
void __fastcall hkAgent1nMachine_VisitAllAgents(
        hkpAgent1nTrack *agentTrack,
        hkpAgent1nMachine_VisitorInput *vin,
        void *(__fastcall *visitor)(hkpAgent1nMachine_VisitorInput *, hkpAgent1nMachineEntry *, void *))
{
  hkpAgent1nSector *v4; // r14
  int v5; // esi
  hkpAgent1nSector *v6; // r13
  _QWORD **Value; // rax
  hkpAgent1nSector *v8; // rax
  hkpAgent1nSector *v9; // rdi
  int v10; // r9d
  char v11; // r12
  __int64 v12; // r11
  char *m_data; // r8
  char *v14; // rbx
  __int128 *v15; // rbp
  __int64 v16; // r10
  char *v17; // rax
  int v18; // ecx
  __int128 v19; // xmm0
  int v20; // edx
  __int128 v21; // xmm1
  __int128 v22; // xmm1
  __int64 v23; // rax
  _QWORD **v24; // rax
  int v25; // esi
  int v26; // esp
  int v27; // ebx
  __int64 v28; // r14
  int v29; // edx
  char *v30; // rcx
  __int128 v31; // xmm0
  __int64 v32; // r11
  int m_size; // ebp
  int v34; // ebx
  int v35; // eax
  int v36; // ebp
  int v37; // eax
  int v38; // r9d
  __int64 v39; // r11
  _QWORD **v40; // rax
  hkpAgent1nSector *v41; // rax
  int v42; // ecx
  char *v43; // rax
  __int128 v44; // xmm0
  unsigned int v45; // esi
  int v46; // esp
  char *v47; // rcx
  int v48; // ebx
  int v49; // edx
  __int128 v50; // xmm0
  int v51; // ebx
  int v52; // eax
  int v53; // eax
  int v54; // r9d
  _QWORD **v55; // rax
  int v56; // [rsp+30h] [rbp-138h]
  __int64 v57; // [rsp+38h] [rbp-130h]
  char *v58; // [rsp+40h] [rbp-128h]
  hkpAgent1nSector *v59; // [rsp+48h] [rbp-120h]
  __int64 v60; // [rsp+50h] [rbp-118h]
  __int64 v61; // [rsp+58h] [rbp-110h]
  char v62[128]; // [rsp+60h] [rbp-108h] BYREF
  __int128 v63[8]; // [rsp+E0h] [rbp-88h] BYREF
  int v64; // [rsp+170h] [rbp+8h]
  __int128 *v65; // [rsp+178h] [rbp+10h] BYREF
  void *(__fastcall *v66)(hkpAgent1nMachine_VisitorInput *, hkpAgent1nMachineEntry *, void *); // [rsp+180h] [rbp+18h]
  hkResult result; // [rsp+188h] [rbp+20h] BYREF

  v66 = visitor;
  v65 = (__int128 *)vin;
  v4 = *agentTrack->m_sectors.m_data;
  v5 = 0;
  v6 = 0i64;
  v59 = v4;
  v64 = 0;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v8 = (hkpAgent1nSector *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 512i64);
  v9 = v8;
  if ( v8 )
    v8->m_bytesAllocated = 0;
  else
    v9 = 0i64;
  v10 = 1;
  v11 = 0;
  v12 = (__int64)&v4->m_data[v4->m_bytesAllocated];
  v56 = 1;
  m_data = v4->m_data;
  v14 = v9->m_data;
  v15 = (__int128 *)&v9[1];
  v60 = v12;
  v16 = 1i64;
  v57 = 1i64;
  v61 = 0i64;
  while ( 1 )
  {
    v17 = m_data;
    v18 = (unsigned __int8)m_data[3] >> 4;
    do
    {
      v19 = *(_OWORD *)v17;
      --v18;
      v17 += 16;
      *(_OWORD *)&v17[v14 - m_data - 16] = v19;
    }
    while ( v18 > 0 );
    v20 = 16;
    m_data += (unsigned __int8)m_data[3];
    v58 = m_data;
    v21 = v65[1];
    v63[0] = *v65;
    v63[1] = v21;
    v22 = v65[3];
    v63[2] = v65[2];
    v63[3] = v22;
    switch ( *v14 & 0xF7 )
    {
      case 1:
        v14 += 16;
        break;
      case 2:
      case 3:
      case 6:
        goto $LN19_73;
      case 4:
      case 5:
        v20 = 32;
$LN19_73:
        v23 = (__int64)v66((hkpAgent1nMachine_VisitorInput *)v63, (hkpAgent1nMachineEntry *)v14, &v14[v20]);
        m_data = v58;
        v10 = v56;
        v16 = v57;
        v12 = v60;
        v14 = (char *)v23;
        break;
      default:
        break;
    }
    if ( m_data != (char *)v12 )
      goto LABEL_17;
    if ( v6 )
    {
      v24 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, hkpAgent1nSector *, __int64))(*v24[11] + 16i64))(v24[11], v6, 512i64);
      v10 = v56;
    }
    v6 = v4;
    if ( v10 >= agentTrack->m_sectors.m_size )
      break;
    ++v10;
    v4 = agentTrack->m_sectors.m_data[v57];
    v56 = v10;
    m_data = v4->m_data;
    v12 = (__int64)&v4->m_data[v4->m_bytesAllocated];
    v16 = v57 + 1;
    v59 = v4;
    ++v57;
    v58 = v4->m_data;
    v60 = v12;
LABEL_17:
    if ( v14 + 128 > (char *)v15 )
    {
      if ( v11 )
      {
        v27 = (_DWORD)v14 - (v26 + 96);
        v28 = v27;
        if ( v27 <= 496 - v5 )
        {
          v29 = v27 >> 4;
          v30 = v62;
          do
          {
            v31 = *(_OWORD *)v30;
            --v29;
            v30 += 16;
            *(_OWORD *)((char *)&v9->m_bytesAllocated + v5 - (_QWORD)v62 + (_QWORD)v30) = v31;
          }
          while ( v29 > 0 );
          v5 += v27;
          if ( v5 < 496 )
          {
            m_data = v58;
            v14 = v62;
            goto LABEL_5;
          }
          v11 = 0;
        }
        v32 = v61;
        v9->m_bytesAllocated = v5;
        if ( v61 >= v16 )
        {
          m_size = agentTrack->m_sectors.m_size;
          v34 = m_size + 1;
          v35 = agentTrack->m_sectors.m_capacityAndFlags & 0x3FFFFFFF;
          v36 = m_size - v10;
          if ( v34 > v35 )
          {
            v37 = 2 * v35;
            v38 = v34;
            if ( v34 < v37 )
              v38 = v37;
            hkArrayUtil::_reserve(
              &result,
              &hkContainerHeapAllocator::s_alloc,
              (const void **)&agentTrack->m_sectors.m_data,
              v38,
              8);
            v10 = v56;
          }
          hkMemUtil::memMove(&agentTrack->m_sectors.m_data[v10 + 1], &agentTrack->m_sectors.m_data[v10], 8 * v36);
          ++v56;
          ++v57;
          v32 = v61;
          agentTrack->m_sectors.m_size = v34;
        }
        ++v64;
        v39 = v32 + 1;
        agentTrack->m_sectors.m_data[v39 - 1] = v9;
        v61 = v39;
        if ( v6 )
        {
          v9 = v6;
          v6 = 0i64;
        }
        else
        {
          v40 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v41 = (hkpAgent1nSector *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v40[11] + 8i64))(v40[11], 512i64);
          v9 = v41;
          if ( v41 )
            v41->m_bytesAllocated = 0;
          else
            v9 = 0i64;
        }
        m_data = v58;
        v10 = v56;
        v16 = v57;
        v12 = v60;
        v14 = v9->m_data;
        v15 = (__int128 *)&v9[1];
        if ( v11 )
        {
          v42 = (int)v28 >> 4;
          v43 = v62;
          do
          {
            v44 = *(_OWORD *)v43;
            --v42;
            v43 += 16;
            *(_OWORD *)&v43[(char *)v9 - v62] = v44;
          }
          while ( v42 > 0 );
          m_data = v58;
          v10 = v56;
          v14 += v28;
          v11 = 0;
        }
LABEL_5:
        v4 = v59;
      }
      else
      {
        v11 = 1;
        v15 = v63;
        v25 = (_DWORD)v14 - (_DWORD)v9;
        v14 = v62;
        v5 = v25 - 16;
      }
    }
  }
  if ( v11 )
  {
    v47 = v62;
    v48 = (_DWORD)v14 - (v46 + 96);
    v49 = v48 >> 4;
    do
    {
      v50 = *(_OWORD *)v47;
      --v49;
      v47 += 16;
      *(_OWORD *)((char *)&v9->m_bytesAllocated + v5 - (_QWORD)v62 + (_QWORD)v47) = v50;
    }
    while ( v49 > 0 );
    v45 = v48 + v5;
  }
  else
  {
    v45 = (_DWORD)v14 - (_DWORD)v9 - 16;
  }
  v9->m_bytesAllocated = v45;
  v51 = v64 + 1;
  v52 = agentTrack->m_sectors.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v52 < v64 + 1 )
  {
    v53 = 2 * v52;
    v54 = v64 + 1;
    if ( v51 < v53 )
      v54 = v53;
    hkArrayUtil::_reserve(
      (hkResult *)&v65,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&agentTrack->m_sectors.m_data,
      v54,
      8);
  }
  agentTrack->m_sectors.m_size = v51;
  agentTrack->m_sectors.m_data[v64] = v9;
  v55 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, hkpAgent1nSector *, __int64))(*v55[11] + 16i64))(v55[11], v4, 512i64);
}ue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, hkpAgent1nSector *, __int64))(*v55[11] + 16i64))(v55[11], v4, 512i64);
}

// File Line: 1012
// RVA: 0xD3B630
void __fastcall hkAgent1nMachine_initInputAtTime(
        hkpAgent3Input *in,
        hkpAgentNmMachineBodyTemp *temp,
        hkpAgent3Input *out)
{
  hkTransformf *p_m_transA; // rbp
  unsigned int m_shapeKey; // ecx
  hkpCdBody *m_storage; // rax
  hkpCdBody *v9; // rax

  p_m_transA = &temp->m_transA;
  hkSweptTransformUtil::lerp2(
    (hkSweptTransformf *)((char *)in->m_bodyA.m_storage->m_motion + 64),
    in->m_input.m_storage->m_stepInfo.m_startTime.m_storage,
    &temp->m_transA);
  hkSweptTransformUtil::lerp2(
    (hkSweptTransformf *)((char *)in->m_bodyB.m_storage->m_motion + 64),
    in->m_input.m_storage->m_stepInfo.m_startTime.m_storage,
    &temp->m_transB);
  out->m_bodyA.m_storage = &temp->m_bodyA;
  out->m_bodyB.m_storage = &temp->m_bodyB;
  out->m_contactMgr.m_storage = in->m_contactMgr.m_storage;
  out->m_input.m_storage = in->m_input.m_storage;
  m_shapeKey = in->m_bodyA.m_storage->m_shapeKey;
  temp->m_bodyA.m_shape = in->m_bodyA.m_storage->m_shape;
  temp->m_bodyA.m_shapeKey = m_shapeKey;
  m_storage = in->m_bodyA.m_storage;
  temp->m_bodyA.m_motion = p_m_transA;
  temp->m_bodyA.m_parent = m_storage;
  if ( temp != (hkpAgentNmMachineBodyTemp *)-32i64 )
  {
    v9 = in->m_bodyB.m_storage;
    temp->m_bodyB.m_motion = &temp->m_transB;
    temp->m_bodyB.m_parent = v9;
  }
  hkTransformf::setMulInverseMul(&out->m_aTb, p_m_transA, &temp->m_transB);
}

// File Line: 1029
// RVA: 0xD3B710
void __fastcall hkAgent1nMachine_flipInput(hkpAgent3ProcessInput *in, hkpAgent3ProcessInput *out)
{
  out->m_bodyA.m_storage = in->m_bodyB.m_storage;
  out->m_bodyB.m_storage = in->m_bodyA.m_storage;
  out->m_input.m_storage = in->m_input.m_storage;
  out->m_contactMgr.m_storage = in->m_contactMgr.m_storage;
  out->m_linearTimInfo.m_quad = _mm_xor_ps(
                                  (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64),
                                  in->m_linearTimInfo.m_quad);
  hkTransformf::setInverse(&out->m_aTb, &in->m_aTb);
}

// File Line: 1072
// RVA: 0xD3AC40
void __fastcall hkAgent1nMachine_UpdateShapeCollectionFilter(
        hkpAgent1nTrack *agentTrack,
        hkpAgent1nMachine_VisitorInput *vin)
{
  hkAgent1nMachine_VisitAllAgents(agentTrack, vin, hkAgent1nMachine_UpdateShapeCollectionFilterVisitor);
}

// File Line: 1077
// RVA: 0xD3AC60
void __fastcall hkAgentNmMachine_UpdateShapeCollectionFilter(
        hkpAgent1nTrack *agentTrack,
        hkpAgent1nMachine_VisitorInput *vin)
{
  hkAgent1nMachine_VisitAllAgents(agentTrack, vin, hkAgentNmMachine_UpdateShapeCollectionFilterVisitor);
}

