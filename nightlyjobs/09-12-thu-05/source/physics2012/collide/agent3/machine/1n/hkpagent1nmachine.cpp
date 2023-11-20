// File Line: 55
// RVA: 0xD3B170
void __fastcall hkAgent1nMachine_Destroy(hkpAgent1nTrack *agentTrack, hkpCollisionDispatcher *dispatcher, hkpContactMgr *mgr, hkpConstraintOwner *constraintOwner)
{
  hkpAgent1nSector **v4; // r15
  int v5; // ebp
  hkpConstraintOwner *v6; // r13
  hkpAgent1nSector *v7; // r10
  hkpCollisionDispatcher *v8; // r12
  hkpAgent1nTrack *v9; // rsi
  char *v10; // rbx
  unsigned __int64 v11; // r14
  __int64 v12; // rdi
  signed __int64 v13; // r9
  hkpAgentEntry *v14; // rcx
  signed __int64 v15; // rdx
  signed __int64 v16; // rdx
  hkpAgent1nSector *v17; // rbx
  _QWORD **v18; // rax
  hkpAgent1nSector *v19; // rcx
  hkpAgent1nSector *v20; // rbx
  _QWORD **v21; // rax
  int v22; // er8
  hkpContactMgr *v23; // [rsp+70h] [rbp+18h]

  v23 = mgr;
  v4 = agentTrack->m_sectors.m_data;
  v5 = 0;
  v6 = constraintOwner;
  v7 = *agentTrack->m_sectors.m_data;
  v8 = dispatcher;
  v9 = agentTrack;
  v10 = v7->m_data;
  v11 = (unsigned __int64)&v7->m_data[v7->m_bytesAllocated];
  v12 = 0i64;
  while ( 1 )
  {
    v13 = 5368709120i64;
    do
    {
      v14 = (hkpAgentEntry *)v10;
      switch ( *v10 )
      {
        case 0:
          v10 += (unsigned __int8)v10[3];
          break;
        case 1:
          v20 = v4[v5];
          if ( v20 )
          {
            v21 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
            (*(void (__fastcall **)(_QWORD *, hkpAgent1nSector *, signed __int64))(*v21[11] + 16i64))(
              v21[11],
              v20,
              512i64);
          }
          v22 = v9->m_sectors.m_capacityAndFlags;
          v9->m_sectors.m_size = 0;
          if ( v22 >= 0 )
            ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, hkpAgent1nSector **, _QWORD, signed __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
              &hkContainerHeapAllocator::s_alloc,
              v9->m_sectors.m_data,
              (unsigned int)(8 * v22),
              v13);
          v9->m_sectors.m_capacityAndFlags = 2147483648;
          v9->m_sectors.m_data = 0i64;
          return;
        case 2:
        case 3:
        case 6:
        case 0xA:
        case 0xB:
        case 0xE:
          v15 = (signed __int64)(v10 + 16);
          v10 += (unsigned __int8)v10[3];
          v8->m_agent3Func[(unsigned __int8)v14->m_agentType].m_destroyFunc(v14, (void *)v15, mgr, v6, v8);
          mgr = v23;
          v13 = 5368709120i64;
          break;
        case 4:
        case 5:
        case 0xC:
        case 0xD:
          v16 = (signed __int64)(v10 + 32);
          v10 += (unsigned __int8)v10[3];
          v8->m_agent3Func[(unsigned __int8)v14->m_agentType].m_destroyFunc(v14, (void *)v16, mgr, v6, v8);
          mgr = v23;
          v13 = 5368709120i64;
          break;
        default:
          break;
      }
    }
    while ( (unsigned __int64)v10 < v11 );
    v17 = v4[v12];
    ++v5;
    ++v12;
    if ( v17 )
    {
      v18 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, hkpAgent1nSector *, signed __int64))(*v18[11] + 16i64))(v18[11], v17, 512i64);
    }
    mgr = v23;
    v19 = v9->m_sectors.m_data[v12];
    v10 = v19->m_data;
    v11 = (unsigned __int64)&v19->m_data[v19->m_bytesAllocated];
  }
}

// File Line: 153
// RVA: 0xD3B360
void __fastcall hkAgent1nMachine_InvalidateTim(hkpAgent1nTrack *agentTrack, hkpCollisionInput *input)
{
  hkpCollisionInput *v2; // r15
  hkpAgent1nTrack *v3; // r14
  hkpAgent1nSector *v4; // r8
  signed __int64 v5; // rdi
  __int64 v6; // rax
  char *v7; // rbx
  signed __int64 i; // rsi
  unsigned __int64 v9; // rsi
  hkpAgentEntry *v10; // r9
  signed __int64 v11; // rdx
  void (__fastcall *v12)(hkpAgentEntry *, void *, hkpCollisionInput *); // r10
  __int64 v13; // rax
  __int64 v14; // rcx
  hkpAgent1nSector *v15; // rcx

  v2 = input;
  v3 = agentTrack;
  v4 = *agentTrack->m_sectors.m_data;
  v5 = 1i64;
  v6 = v4->m_bytesAllocated;
  v7 = v4->m_data;
  for ( i = (signed __int64)v4->m_data; ; i = (signed __int64)v15->m_data )
  {
    v9 = v6 + i;
    do
    {
      v10 = (hkpAgentEntry *)v7;
      switch ( *v7 )
      {
        case 0:
          v7 += (unsigned __int8)v7[3];
          break;
        case 1:
          return;
        case 2:
        case 3:
        case 6:
        case 0xA:
        case 0xB:
        case 0xE:
          v11 = (signed __int64)(v7 + 16);
          v7 += (unsigned __int8)v7[3];
          v12 = v2->m_dispatcher.m_storage->m_agent3Func[(unsigned __int8)v10->m_agentType].m_invalidateTimFunc;
          goto LABEL_5;
        case 4:
        case 5:
        case 0xC:
        case 0xD:
          v13 = (unsigned __int8)v7[3];
          v14 = (unsigned __int8)v7[1];
          *((_DWORD *)v7 + 3) = -1082130432;
          *((_OWORD *)v7 + 1) = 0i64;
          v11 = (signed __int64)(v7 + 32);
          v7 += v13;
          v12 = v2->m_dispatcher.m_storage->m_agent3Func[v14].m_invalidateTimFunc;
LABEL_5:
          if ( v12 )
            v12(v10, (void *)v11, v2);
          break;
        default:
          break;
      }
    }
    while ( (unsigned __int64)v7 < v9 );
    ++v5;
    v15 = v3->m_sectors.m_data[v5 - 1];
    v6 = v15->m_bytesAllocated;
    v7 = v15->m_data;
  }
}

// File Line: 233
// RVA: 0xD3B4A0
void __fastcall hkAgent1nMachine_WarpTime(hkpAgent1nTrack *agentTrack, float oldTime, float newTime, hkpCollisionInput *input)
{
  hkpCollisionInput *v4; // r15
  hkpAgent1nTrack *v5; // r14
  signed __int64 v6; // rdi
  hkpAgent1nSector *v7; // rdx
  float *v8; // rbx
  unsigned __int64 v9; // rsi
  float *v10; // r9
  signed __int64 v11; // rdx
  void (__fastcall *v12)(hkpAgentEntry *, void *, float, float, hkpCollisionInput *); // r10
  signed __int64 v13; // rdx
  void (__fastcall *v14)(hkpAgentEntry *, void *, float, float, hkpCollisionInput *); // r8
  hkpAgent1nSector *v15; // rcx

  v4 = input;
  v5 = agentTrack;
  v6 = 1i64;
  v7 = *agentTrack->m_sectors.m_data;
  v8 = (float *)v7->m_data;
  v9 = (unsigned __int64)&v7->m_data[v7->m_bytesAllocated];
  while ( 1 )
  {
    v10 = v8;
    switch ( *(unsigned __int8 *)v8 )
    {
      case 0u:
        v8 = (float *)((char *)v8 + *((unsigned __int8 *)v8 + 3));
        break;
      case 1u:
        return;
      case 2u:
      case 3u:
      case 6u:
      case 0xAu:
      case 0xBu:
      case 0xEu:
        v11 = (signed __int64)(v8 + 4);
        v8 = (float *)((char *)v8 + *((unsigned __int8 *)v8 + 3));
        v12 = v4->m_dispatcher.m_storage->m_agent3Func[*((unsigned __int8 *)v10 + 1)].m_warpTimeFunc;
        if ( v12 )
          ((void (__fastcall *)(float *, signed __int64))v12)(v10, v11);
        break;
      case 4u:
      case 5u:
      case 0xCu:
      case 0xDu:
        v13 = (signed __int64)(v8 + 8);
        if ( oldTime == v8[3] )
          v8[3] = newTime;
        else
          v8[3] = -1.0;
        v8 = (float *)((char *)v8 + *((unsigned __int8 *)v8 + 3));
        v14 = v4->m_dispatcher.m_storage->m_agent3Func[*((unsigned __int8 *)v10 + 1)].m_warpTimeFunc;
        if ( v14 )
          ((void (__fastcall *)(float *, signed __int64))v14)(v10, v13);
        break;
      default:
        break;
    }
    if ( (unsigned __int64)v8 >= v9 )
    {
      v15 = v5->m_sectors.m_data[v6];
      v8 = (float *)v15->m_data;
      v9 = (unsigned __int64)&v15->m_data[v15->m_bytesAllocated];
      ++v6;
    }
  }
}

// File Line: 324
// RVA: 0xD3BF70
hkpAgent1nMachineEntry *__fastcall hkAgent1nMachine_FindAgent(hkpAgent1nTrack *agentTrack, hkpShapeKeyPair keyPair, void **agentDataOut)
{
  hkpAgent1nSector **v3; // r10
  __int64 v4; // rcx
  hkpAgent1nMachineEntry *result; // rax
  signed __int64 v6; // r11
  unsigned __int64 v7; // r11
  hkpShapeKeyPair *v8; // rcx

  v3 = agentTrack->m_sectors.m_data;
  v4 = **(unsigned int **)agentTrack->m_sectors.m_data;
  result = (hkpAgent1nMachineEntry *)(*v3)->m_data;
  v6 = (signed __int64)(*v3)->m_data;
  while ( 2 )
  {
    v7 = v4 + v6;
    ++v3;
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
        v8 = &result[1].m_shapeKeyPair;
        goto LABEL_6;
      case 4:
      case 5:
      case 0xC:
      case 0xD:
        v8 = (hkpShapeKeyPair *)((char *)&result[2].m_shapeKeyPair + 4);
LABEL_6:
        if ( *(_QWORD *)&result->m_shapeKeyPair != keyPair )
        {
$LN5_184:
          result = (hkpAgent1nMachineEntry *)((char *)result + (unsigned __int8)result->m_size);
LABEL_8:
          if ( (unsigned __int64)result >= v7 )
          {
            v4 = (*v3)->m_bytesAllocated;
            result = (hkpAgent1nMachineEntry *)(*v3)->m_data;
            v6 = (signed __int64)(*v3)->m_data;
            continue;
          }
          goto LABEL_3;
        }
        *agentDataOut = v8;
        return result;
      default:
        goto LABEL_8;
    }
  }
}

// File Line: 437
// RVA: 0xD3AB70
void __fastcall hkAgent1nMachine_Create(hkpAgent1nTrack *agentTrack)
{
  hkpAgent1nTrack *v1; // rbx
  int v2; // eax
  int v3; // eax
  int v4; // er9
  _QWORD **v5; // rax
  _DWORD *v6; // rax
  _DWORD *v7; // rcx
  hkResult result; // [rsp+40h] [rbp+8h]

  agentTrack->m_sectors.m_size = 0;
  v1 = agentTrack;
  v2 = agentTrack->m_sectors.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v2 < 4 )
  {
    v3 = 2 * v2;
    v4 = 4;
    if ( v3 > 4 )
      v4 = v3;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, agentTrack, v4, 8);
  }
  if ( v1->m_sectors.m_size == (v1->m_sectors.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v1, 8);
  ++v1->m_sectors.m_size;
  v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v6 = (_DWORD *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v5[11] + 8i64))(v5[11], 512i64);
  v7 = v6;
  if ( v6 )
    *v6 = 0;
  else
    v7 = 0i64;
  *v1->m_sectors.m_data = (hkpAgent1nSector *)v7;
  *((_BYTE *)v7 + 19) = 16;
  *((_BYTE *)v7 + 16) = 1;
  *(_QWORD *)(v7 + 5) = -1i64;
  *v7 = 16;
}

// File Line: 468
// RVA: 0xD3C050
char __fastcall contactPointIsValid(float radiusA, hkContactPoint *pointToCheck, hkpCollisionQualityInfo *qi, float radiusB, hkpProcessCdPoint *referenceCdPoint)
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
  float v26; // [rsp+60h] [rbp+8h]

  v26 = radiusA;
  v5.m_quad = (__m128)pointToCheck->m_separatingNormal;
  v6.m_quad = (__m128)referenceCdPoint->m_contact.m_separatingNormal;
  v7 = _mm_sub_ps(referenceCdPoint->m_contact.m_position.m_quad, pointToCheck->m_position.m_quad);
  v8 = (__m128)LODWORD(radiusB);
  v9 = _mm_mul_ps(referenceCdPoint->m_contact.m_separatingNormal.m_quad, v7);
  v10 = _mm_mul_ps(pointToCheck->m_separatingNormal.m_quad, v7);
  v11 = _mm_unpacklo_ps(v10, v9);
  v12 = _mm_unpackhi_ps(v10, v9);
  v13 = _mm_mul_ps(referenceCdPoint->m_contact.m_separatingNormal.m_quad, v5.m_quad);
  v14 = _mm_movelh_ps(v11, v13);
  v15 = _mm_shuffle_ps(_mm_movehl_ps(v14, v11), v13, 212);
  v16 = _mm_shuffle_ps(v12, v13, 228);
  v17 = 0.0;
  v18 = _mm_add_ps(v16, _mm_add_ps(v14, v15));
  v19 = _mm_shuffle_ps((__m128)LODWORD(v26), (__m128)LODWORD(v26), 0);
  v20 = _mm_shuffle_ps(v18, v18, 170);
  v21 = _mm_add_ps(_mm_shuffle_ps(v8, v8, 0), v19);
  v22 = _mm_mul_ps(_mm_sub_ps(v20, query.m_quad), v19);
  v23 = _mm_add_ps(_mm_sub_ps((__m128)0i64, _mm_shuffle_ps(v18, v18, 85)), v22);
  v24 = _mm_add_ps(_mm_shuffle_ps(v18, v18, 0), v22);
  if ( v23.m128_f32[0] > v21.m128_f32[0]
    || v20.m128_f32[0] > COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(FLOAT_0_99989998), (__m128)LODWORD(FLOAT_0_99989998), 0))
    && referenceCdPoint->m_contactPointId == 0xFFFF )
  {
    return 0;
  }
  if ( referenceCdPoint->m_contactPointId == 0xFFFF )
  {
    if ( _mm_movemask_ps(
           _mm_and_ps(
             _mm_cmpltps(
               _mm_add_ps(_mm_shuffle_ps(v5.m_quad, v5.m_quad, 255), _mm_shuffle_ps(v6.m_quad, v6.m_quad, 255)),
               _mm_sub_ps((__m128)0i64, _mm_add_ps(v21, v21))),
             _mm_and_ps(
               _mm_cmpltps(
                 _mm_add_ps(v24, v23),
                 _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_1), (__m128)LODWORD(FLOAT_0_1), 0)),
               _mm_cmpltps(v20, _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_80000001), (__m128)LODWORD(FLOAT_0_80000001), 0))))) )
    {
      return 2;
    }
  }
  else
  {
    v17 = COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(FLOAT_0_050000001), (__m128)LODWORD(FLOAT_0_050000001), 0))
        * COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(qi->m_keepContact), (__m128)LODWORD(qi->m_keepContact), 0));
  }
  return COERCE_FLOAT(_mm_shuffle_ps(v5.m_quad, v5.m_quad, 255)) > (float)(COERCE_FLOAT(_mm_shuffle_ps(v6.m_quad, v6.m_quad, 255))
                                                                         - v17);
}

// File Line: 573
// RVA: 0xD3B770
void __fastcall hkAgent1nMachine_Weld(hkpAgent3Input *input, hkpShapeContainer *shapeCollection, hkpProcessCollisionOutput *output, __int64 a4)
{
  hkpProcessCollisionOutput::PotentialInfo *v4; // rsi
  signed __int64 v5; // r15
  hkpAgent3Input *v6; // r14
  hkpProcessCollisionOutput::ContactRef *v7; // r12
  int v8; // er13
  hkpShape *v9; // r8
  hkpProcessCdPoint **v10; // rcx
  hkpProcessCdPoint **v11; // r10
  __m128 *v12; // r11
  __m128 *v13; // rdx
  __m128 v14; // xmm6
  __m128 v15; // xmm5
  hkpProcessCollisionInput *v16; // rax
  hkpCollisionQualityInfo *v17; // rbx
  __m128 v18; // xmm3
  __m128 v19; // xmm2
  __m128 v20; // xmm4
  __m128 v21; // xmm2
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
  int v35; // er8
  __m128 v36; // xmm0
  hkpConvexShape *v37; // rax
  hkpAgentEntry *v38; // rbx
  hkpConvexShape *v39; // rax
  hkpProcessCollisionInput *v40; // r9
  hkpConvexShape **v41; // rdx
  hkpAgentEntry v42; // ecx
  hkpProcessCdPoint *v43; // rax
  __int16 v44; // ax
  int v45; // er12
  hkpCollisionDispatcher *v46; // rdi
  signed __int64 v47; // rbx
  hkpAgentEntry *v48; // rcx
  _QWORD *v49; // r8
  __int16 *v50; // r9
  _QWORD *v51; // rcx
  unsigned __int64 v52; // rax
  signed __int64 v53; // rcx
  __m128 v54; // xmm7
  __m128i v55; // xmm9
  __m128i v56; // xmm6
  __m128i v57; // xmm5
  signed __int64 v58; // r8
  signed __int64 v59; // r10
  signed __int64 v60; // rdx
  __m128i v61; // xmm8
  __m128i i; // xmm4
  __int64 v63; // rax
  __m128 v64; // xmm1
  __m128 v65; // xmm3
  __m128i v66; // xmm2
  __m128i v67; // xmm0
  __int64 v68; // r15
  signed __int64 v69; // r12
  __int64 v70; // rdx
  hkpConvexShape *v71; // rdi
  __int64 v72; // rax
  hkpConvexShape **v73; // rdx
  hkpConvexShape *v74; // r8
  __int16 v75; // ax
  unsigned int v76; // ecx
  __int16 v77; // ax
  _QWORD *v78; // rax
  _QWORD *v79; // rcx
  _QWORD *v80; // r8
  unsigned __int64 v81; // rax
  signed __int64 v82; // rcx
  bool v83; // zf
  hkVector4f **v84; // r12
  __int64 v85; // rbx
  __int64 v86; // rdx
  hkpContactMgr *v87; // rcx
  hkBaseObjectVtbl *v88; // rax
  hkpProcessCollisionOutput::ContactRef *v89; // rbx
  hkpCollisionDispatcher *v90; // r15
  int v91; // edx
  __int64 j; // rsi
  unsigned __int16 v93; // di
  hkVector4f *v94; // rdx
  hkpProcessCdPoint *v95; // rcx
  hkpShape *v96; // [rsp+40h] [rbp-80h]
  __int64 v97; // [rsp+48h] [rbp-78h]
  hkpConvexShape *shapeBs; // [rsp+50h] [rbp-70h]
  __int64 v99; // [rsp+58h] [rbp-68h]
  const void *v100; // [rsp+60h] [rbp-60h]
  hkpCdBody *v101; // [rsp+68h] [rbp-58h]
  hkContactPoint *pointsOut; // [rsp+70h] [rbp-50h]
  hkpConvexShape *shapeA; // [rsp+78h] [rbp-48h]
  __int16 v104[256]; // [rsp+80h] [rbp-40h]
  __int16 v105[256]; // [rsp+280h] [rbp+1C0h]
  char v106; // [rsp+480h] [rbp+3C0h]
  char v107; // [rsp+680h] [rbp+5C0h]
  int v108; // [rsp+940h] [rbp+880h]
  __int64 v109; // [rsp+948h] [rbp+888h]
  __int64 v110; // [rsp+950h] [rbp+890h]
  hkResult result; // [rsp+958h] [rbp+898h]

  v4 = output->m_potentialContacts.m_storage;
  v5 = 0i64;
  v6 = input;
  v7 = v4->m_potentialContacts;
  v108 = 0;
  v8 = 0;
  v9 = input->m_bodyA.m_storage->m_shape;
  v96 = input->m_bodyA.m_storage->m_shape;
  if ( v4->m_potentialContacts < v4->m_firstFreePotentialContact )
  {
    v10 = v4->m_representativeContacts;
    shapeBs = (hkpConvexShape *)v104;
    while ( 1 )
    {
      v11 = v4->m_firstFreeRepresentativeContact;
      v12 = &v7->m_contactPoint->m_contact.m_position.m_quad;
      LOBYTE(a4) = 0;
      v105[v8] = -1;
      if ( v10 < v11 )
        break;
LABEL_18:
      v38 = v4->m_potentialContacts[v8].m_agentEntry;
      v39 = (hkpConvexShape *)(*(__int64 (__fastcall **)(__int64, _QWORD, char *, __int64))(*(_QWORD *)v109 + 40i64))(
                                v109,
                                *(_DWORD *)&v38[2],
                                &v106,
                                a4);
      v40 = v6->m_input.m_storage;
      v41 = (hkpConvexShape **)v6->m_bodyA.m_storage;
      v101 = v6->m_bodyB.m_storage;
      v100 = v101->m_motion;
      v42 = v38[2];
      shapeBs = v39;
      v43 = v4->m_potentialContacts[v8].m_contactPoint;
      LODWORD(v99) = v42;
      v44 = ((__int64 (__fastcall *)(hkpContactMgr *, hkpConvexShape **, hkpConvexShape **, hkpProcessCollisionInput *, __int64, _QWORD, hkpProcessCdPoint *))v6->m_contactMgr.m_storage->vfptr[1].__first_virtual_table_function__)(
              v6->m_contactMgr.m_storage,
              v41,
              &shapeBs,
              v40,
              v110,
              0i64,
              v43);
      v105[v8] = v44;
      if ( v44 != -1 )
        ((void (__fastcall *)(hkpContactMgr *, __int64 *, signed __int64))v6->m_contactMgr.m_storage->vfptr[2].__vecDelDtor)(
          v6->m_contactMgr.m_storage,
          &v97,
          0xFFFFFFFFi64);
$tryNextPoint:
      v9 = v96;
      ++v7;
      ++v8;
      v10 = v4->m_representativeContacts;
      if ( v7 >= v4->m_firstFreePotentialContact )
        goto LABEL_21;
    }
    while ( 1 )
    {
      v13 = (__m128 *)*v10;
      if ( v12 == (__m128 *)*v10 )
        goto LABEL_15;
      v14 = v12[1];
      v15 = v13[1];
      v16 = v6->m_input.m_storage;
      result.m_enum = (hkResultEnum)v9[1].vfptr;
      LODWORD(pointsOut) = 0;
      v17 = v16->m_collisionQualityInfo.m_storage;
      v18 = _mm_mul_ps(v15, v14);
      v19 = _mm_sub_ps(*v13, *v12);
      v20 = v19;
      v21 = _mm_mul_ps(v19, v15);
      v22 = _mm_mul_ps(v20, v14);
      v23 = _mm_unpacklo_ps(v22, v21);
      v24 = _mm_shuffle_ps(_mm_unpackhi_ps(v22, v21), v18, 228);
      v25 = _mm_movelh_ps(v23, v18);
      v26 = _mm_shuffle_ps((__m128)(unsigned int)result.m_enum, (__m128)(unsigned int)result.m_enum, 0);
      v27 = _mm_shuffle_ps(_mm_movehl_ps(v25, v23), v18, 212);
      v28 = 0.0;
      v29 = _mm_add_ps(_mm_shuffle_ps(0, 0, 0), v26);
      v30 = _mm_add_ps(_mm_add_ps(v27, v25), v24);
      v31 = _mm_shuffle_ps(v30, v30, 170);
      v32 = _mm_mul_ps(_mm_sub_ps(v31, query.m_quad), v26);
      v33 = _mm_add_ps(_mm_sub_ps((__m128)0i64, _mm_shuffle_ps(v30, v30, 85)), v32);
      v34 = _mm_add_ps(_mm_shuffle_ps(v30, v30, 0), v32);
      if ( v33.m128_f32[0] > v29.m128_f32[0] )
        goto LABEL_15;
      LODWORD(v100) = 1065351538;
      if ( v31.m128_f32[0] > COERCE_FLOAT(_mm_shuffle_ps((__m128)0x3F7FF972u, (__m128)0x3F7FF972u, 0))
        && v13[2].m128_i32[0] == 0xFFFF )
      {
        goto LABEL_15;
      }
      v35 = v13[2].m128_i32[0];
      LODWORD(v96) = 1061997773;
      LODWORD(shapeA) = 1036831949;
      if ( v35 != 0xFFFF )
        break;
      if ( !_mm_movemask_ps(
              _mm_and_ps(
                _mm_cmpltps(
                  _mm_add_ps(_mm_shuffle_ps(v15, v15, 255), _mm_shuffle_ps(v14, v14, 255)),
                  _mm_sub_ps((__m128)0i64, _mm_add_ps(v29, v29))),
                _mm_and_ps(
                  _mm_cmpltps(_mm_add_ps(v34, v33), _mm_shuffle_ps((__m128)0x3DCCCCCDu, (__m128)0x3DCCCCCDu, 0)),
                  _mm_cmpltps(v31, _mm_shuffle_ps((__m128)0x3F4CCCCDu, (__m128)0x3F4CCCCDu, 0))))) )
        goto LABEL_13;
      LOBYTE(a4) = 1;
LABEL_14:
      v9 = v96;
LABEL_15:
      ++v10;
      if ( v10 >= v11 )
      {
        if ( (_BYTE)a4 )
        {
          v37 = shapeBs;
          ++v108;
          LOWORD(shapeBs->vfptr) = v8;
          shapeBs = (hkpConvexShape *)((char *)v37 + 2);
        }
        goto LABEL_18;
      }
    }
    v36 = (__m128)LODWORD(v17->m_keepContact);
    LODWORD(v101) = 1028443341;
    v28 = COERCE_FLOAT(_mm_shuffle_ps((__m128)0x3D4CCCCDu, (__m128)0x3D4CCCCDu, 0))
        * COERCE_FLOAT(_mm_shuffle_ps(v36, v36, 0));
LABEL_13:
    if ( COERCE_FLOAT(_mm_shuffle_ps(v14, v14, 255)) > (float)(COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 255)) - v28) )
      goto $tryNextPoint;
    goto LABEL_14;
  }
LABEL_21:
  v45 = v108;
  v46 = v6->m_input.m_storage->m_dispatcher.m_storage;
  v47 = v108;
  if ( v108 > 0 )
  {
    do
    {
      v48 = (hkpAgentEntry *)*((_QWORD *)&v4->m_firstFreeRepresentativeContact + 3
                                                                               * ((unsigned __int16)v104[v5] + 86i64));
      v46->m_agent3Func[(unsigned __int8)v48->m_agentType].m_createZombieFunc(
        v48,
        v4->m_representativeContacts[3 * ((unsigned __int16)v104[v5++] + 86i64)],
        0xFFFFu);
    }
    while ( v5 < v47 );
  }
  if ( v47 >= 2 )
  {
    do
    {
      v49 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v51 = (_QWORD *)v49[1];
      if ( (unsigned __int64)v51 < v49[3] )
      {
        *v51 = "TtConflicts";
        v52 = __rdtsc();
        v53 = (signed __int64)(v51 + 2);
        *(_DWORD *)(v53 - 8) = v52;
        v49[1] = v53;
      }
      v54 = (__m128)xmmword_141A710D0;
      v55 = 0i64;
      v56 = (__m128i)xmmword_141A72090;
      v57 = 0i64;
      if ( v47 > 0 )
      {
        v58 = 1i64;
        v50 = v104;
        v59 = v47;
        do
        {
          v60 = v58;
          v61 = _mm_add_epi32((__m128i)xmmword_141A72090, v55);
          for ( i = v61; v60 < v47; v56 = _mm_or_si128(_mm_and_si128(v67, v66), _mm_andnot_si128(v66, v56)) )
          {
            v63 = (unsigned __int16)v104[v60++];
            v64 = _mm_mul_ps(
                    *(__m128 *)&(&v4->m_firstFreePotentialContact)[3 * (v63 + 86)]->m_agentData,
                    *(__m128 *)&(&v4->m_firstFreePotentialContact)[3 * ((unsigned __int16)*v50 + 86i64)]->m_agentData);
            v65 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v64, v64, 85), _mm_shuffle_ps(v64, v64, 0)),
                    _mm_shuffle_ps(v64, v64, 170));
            v66 = (__m128i)_mm_cmpltps(v65, v54);
            v54 = _mm_min_ps(v65, v54);
            v57 = _mm_or_si128(_mm_and_si128(v55, v66), _mm_andnot_si128(v66, v57));
            v67 = i;
            i = _mm_add_epi32(i, (__m128i)xmmword_141A72090);
          }
          ++v50;
          ++v58;
          v55 = v61;
          --v59;
        }
        while ( v59 );
      }
      LODWORD(shapeBs) = v57.m128i_i32[0];
      v68 = v57.m128i_i32[0];
      v69 = 3 * ((unsigned __int16)v104[v57.m128i_i32[0]] + 86i64);
      v70 = *((_QWORD *)&v4->m_firstFreeRepresentativeContact + 3 * ((unsigned __int16)v104[v57.m128i_i32[0]] + 86i64));
      v101 = (hkpCdBody *)(3 * ((unsigned __int16)v104[v56.m128i_i32[0]] + 86i64));
      v97 = *((_QWORD *)&v4->m_firstFreeRepresentativeContact + (_QWORD)v101);
      shapeA = (hkpConvexShape *)v6->m_bodyA.m_storage->m_shape;
      if ( !(v6->m_input.m_storage->m_dispatcher.m_storage->m_hasAlternateType[(unsigned __int8)shapeA->m_type.m_storage] & 0x800000) )
        break;
      v71 = (hkpConvexShape *)(*(__int64 (__fastcall **)(__int64, _QWORD, char *, __int16 *))(*(_QWORD *)v109 + 40i64))(
                                v109,
                                *(unsigned int *)(v70 + 8),
                                &v106,
                                v50);
      if ( !(v6->m_input.m_storage->m_dispatcher.m_storage->m_hasAlternateType[(unsigned __int8)v71->m_type.m_storage] & 0x800000) )
        break;
      v72 = (*(__int64 (__fastcall **)(__int64, _QWORD, char *))(*(_QWORD *)v109 + 40i64))(
              v109,
              *(unsigned int *)(v97 + 8),
              &v107);
      if ( !(v6->m_input.m_storage->m_dispatcher.m_storage->m_hasAlternateType[*(unsigned __int8 *)(v72 + 16)] & 0x800000) )
        break;
      v73 = (hkpConvexShape **)v6->m_bodyA.m_storage;
      v74 = shapeA;
      v99 = v72;
      shapeBs = v71;
      pointsOut = (hkContactPoint *)(&v4->m_firstFreePotentialContact)[v69];
      shapeA = (hkpConvexShape *)*((_QWORD *)&v4->m_firstFreePotentialContact + (_QWORD)v101);
      hkCalcMultiPenetrationDepth(&result, (hkTransformf *)v73[2], v74, &shapeBs, 2, &v6->m_aTb, &pointsOut);
      v75 = *((_WORD *)&shapeA + v47 + 3);
      v76 = hkMonitorStream__m_instance.m_slotID;
      v108 -= 2;
      v104[v56.m128i_i32[0]] = v75;
      v77 = *((_WORD *)&shapeA + v47 + 2);
      v47 -= 2i64;
      v104[v68] = v77;
      v78 = TlsGetValue(v76);
      v79 = (_QWORD *)v78[1];
      v80 = v78;
      if ( (unsigned __int64)v79 < v78[3] )
      {
        *v79 = "Et";
        v81 = __rdtsc();
        v82 = (signed __int64)(v79 + 2);
        *(_DWORD *)(v82 - 8) = v81;
        v80[1] = v82;
      }
    }
    while ( v47 >= 2 );
    v45 = v108;
  }
  v83 = v45 == 0;
  v84 = (hkVector4f **)v110;
  if ( !v83 )
  {
    v85 = (unsigned __int16)v104[0];
    v86 = (unsigned __int16)v105[(unsigned __int16)v104[0]];
    if ( (_WORD)v86 != -1 )
    {
      ((void (__fastcall *)(hkpContactMgr *, __int64, _QWORD))v6->m_contactMgr.m_storage->vfptr[2].__first_virtual_table_function__)(
        v6->m_contactMgr.m_storage,
        v86,
        *(_QWORD *)(v110 + 8));
      v87 = v6->m_contactMgr.m_storage;
      v88 = v87->vfptr;
      v105[v85] = -1;
      ((void (__fastcall *)(hkpContactMgr *, __int64 *, signed __int64))v88[2].__vecDelDtor)(v87, &v110, 1i64);
    }
  }
  v89 = v4->m_firstFreePotentialContact;
  v90 = v6->m_input.m_storage->m_dispatcher.m_storage;
  v91 = ((unsigned __int64)((unsigned __int128)((_QWORD)((char *)v4->m_firstFreePotentialContact - (char *)v4 - 2064)
                                              * (signed __int128)3074457345618258603i64) >> 64) >> 63)
      + ((signed __int64)((unsigned __int128)((_QWORD)((char *)v4->m_firstFreePotentialContact - (char *)v4 - 2064)
                                            * (signed __int128)3074457345618258603i64) >> 64) >> 2)
      - 1;
  for ( j = v91; j >= 0; --j )
  {
    v93 = v105[j];
    --v89;
    if ( v93 == -1 )
    {
      ((void (__fastcall *)(hkpContactMgr *, __int64 *, signed __int64))v6->m_contactMgr.m_storage->vfptr[2].__vecDelDtor)(
        v6->m_contactMgr.m_storage,
        &v110,
        0xFFFFFFFFi64);
      v90->m_agent3Func[(unsigned __int8)v89->m_agentEntry->m_agentType].m_removePointFunc(
        v89->m_agentEntry,
        v89->m_agentData,
        0xFFFFu);
      *v84 -= 3;
      v94 = *v84;
      v95 = v89->m_contactPoint;
      v95->m_contact.m_position = (hkVector4f)(*v84)->m_quad;
      v95->m_contact.m_separatingNormal = (hkVector4f)v94[1].m_quad;
      v95->m_contactPointId = v94[2].m_quad.m128_u32[0];
      v95->m_padding[0] = v94[2].m_quad.m128_u32[1];
      v95->m_padding[1] = v94[2].m_quad.m128_u32[2];
      v95->m_padding[2] = v94[2].m_quad.m128_u32[3];
    }
    else
    {
      v90->m_agent3Func[(unsigned __int8)v89->m_agentEntry->m_agentType].m_commitPotentialFunc(
        v89->m_agentEntry,
        v89->m_agentData,
        v93);
      v89->m_contactPoint->m_contactPointId = v93;
    }
  }
}

// File Line: 793
// RVA: 0xD3AC80
void __fastcall hkAgent1nMachine_VisitAllAgents(hkpAgent1nTrack *agentTrack, hkpAgent1nMachine_VisitorInput *vin, void *(__fastcall *visitor)(hkpAgent1nMachine_VisitorInput *, hkpAgent1nMachineEntry *, void *))
{
  hkpAgent1nTrack *v3; // r15
  hkpAgent1nSector *v4; // r14
  int v5; // esi
  hkpAgent1nSector *v6; // r13
  _QWORD **v7; // rax
  int *v8; // rax
  int *v9; // rdi
  __int64 v10; // rax
  signed int v11; // er9
  char v12; // r12
  signed __int64 v13; // r11
  signed __int64 v14; // r8
  char *v15; // rbx
  __int128 *v16; // rbp
  signed __int64 v17; // r10
  __int128 *v18; // rax
  signed int v19; // ecx
  __int128 v20; // xmm0
  signed int v21; // edx
  __int128 v22; // xmm1
  __int128 v23; // xmm1
  int v24; // eax
  __int64 v25; // rax
  _QWORD **v26; // rax
  __int64 v27; // rax
  int v28; // esi
  int v29; // esp
  int v30; // ebx
  __int64 v31; // r14
  int v32; // edx
  char *v33; // rcx
  __int128 v34; // xmm0
  signed __int64 v35; // r11
  int v36; // ebp
  int v37; // ebx
  int v38; // eax
  int v39; // ebp
  int v40; // eax
  int v41; // er9
  signed __int64 v42; // r11
  _QWORD **v43; // rax
  int *v44; // rax
  signed int v45; // ecx
  char *v46; // rax
  __int128 v47; // xmm0
  int v48; // esi
  int v49; // esp
  char *v50; // rcx
  int v51; // ebx
  int v52; // edx
  __int128 v53; // xmm0
  int v54; // ebx
  int v55; // eax
  int v56; // eax
  int v57; // er9
  _QWORD **v58; // rax
  signed int v59; // [rsp+30h] [rbp-138h]
  signed __int64 v60; // [rsp+38h] [rbp-130h]
  signed __int64 v61; // [rsp+40h] [rbp-128h]
  hkpAgent1nSector *v62; // [rsp+48h] [rbp-120h]
  signed __int64 v63; // [rsp+50h] [rbp-118h]
  signed __int64 v64; // [rsp+58h] [rbp-110h]
  char v65; // [rsp+60h] [rbp-108h]
  __int128 v66; // [rsp+E0h] [rbp-88h]
  __int128 v67; // [rsp+F0h] [rbp-78h]
  __int128 v68; // [rsp+100h] [rbp-68h]
  __int128 v69; // [rsp+110h] [rbp-58h]
  int v70; // [rsp+170h] [rbp+8h]
  __int128 *v71; // [rsp+178h] [rbp+10h]
  void *(__fastcall *v72)(hkpAgent1nMachine_VisitorInput *, hkpAgent1nMachineEntry *, void *); // [rsp+180h] [rbp+18h]
  hkResult result; // [rsp+188h] [rbp+20h]

  v72 = visitor;
  v71 = (__int128 *)vin;
  v3 = agentTrack;
  v4 = *agentTrack->m_sectors.m_data;
  v5 = 0;
  v6 = 0i64;
  v62 = *agentTrack->m_sectors.m_data;
  v70 = 0;
  v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v8 = (int *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v7[11] + 8i64))(v7[11], 512i64);
  v9 = v8;
  if ( v8 )
    *v8 = 0;
  else
    v9 = 0i64;
  v10 = v4->m_bytesAllocated;
  v11 = 1;
  v12 = 0;
  v13 = (signed __int64)&v4->m_data[v10];
  v59 = 1;
  v14 = (signed __int64)v4->m_data;
  v15 = (char *)(v9 + 4);
  v16 = (__int128 *)(v9 + 128);
  v63 = (signed __int64)&v4->m_data[v10];
  v17 = 1i64;
  v60 = 1i64;
  v64 = 0i64;
  while ( 1 )
  {
    v18 = (__int128 *)v14;
    v19 = (unsigned int)*(unsigned __int8 *)(v14 + 3) >> 4;
    do
    {
      v20 = *v18;
      --v19;
      ++v18;
      *(_OWORD *)&v15[(_QWORD)v18 - v14 - 16] = v20;
    }
    while ( v19 > 0 );
    v21 = 16;
    v14 += *(unsigned __int8 *)(v14 + 3);
    v61 = v14;
    v22 = v71[1];
    v66 = *v71;
    v67 = v22;
    v23 = v71[3];
    v68 = v71[2];
    v69 = v23;
    v24 = *v15 & 0xF7;
    switch ( 0x40000000 )
    {
      case 0:
        v15 += 16;
        break;
      case 1:
      case 2:
      case 5:
        goto $LN19_73;
      case 3:
      case 4:
        v21 = 32;
$LN19_73:
        v25 = (__int64)v72((hkpAgent1nMachine_VisitorInput *)&v66, (hkpAgent1nMachineEntry *)v15, &v15[v21]);
        v14 = v61;
        v11 = v59;
        v17 = v60;
        v13 = v63;
        v15 = (char *)v25;
        break;
      default:
        break;
    }
    if ( v14 != v13 )
      goto LABEL_17;
    if ( v6 )
    {
      v26 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, hkpAgent1nSector *, signed __int64))(*v26[11] + 16i64))(v26[11], v6, 512i64);
      v11 = v59;
    }
    v6 = v4;
    if ( v11 >= v3->m_sectors.m_size )
      break;
    ++v11;
    v4 = v3->m_sectors.m_data[v60];
    v59 = v11;
    v27 = v4->m_bytesAllocated;
    v14 = (signed __int64)v4->m_data;
    v13 = (signed __int64)&v4->m_data[v27];
    v17 = v60 + 1;
    v62 = v3->m_sectors.m_data[v60++];
    v61 = (signed __int64)v4->m_data;
    v63 = (signed __int64)&v4->m_data[v27];
LABEL_17:
    if ( v15 + 128 > (char *)v16 )
    {
      if ( v12 )
      {
        v30 = (_DWORD)v15 - (v29 + 96);
        v31 = v30;
        if ( v30 <= 496 - v5 )
        {
          v32 = v30 >> 4;
          v33 = &v65;
          do
          {
            v34 = *(_OWORD *)v33;
            --v32;
            v33 += 16;
            *(_OWORD *)((char *)v9 + v5 - (_QWORD)&v65 + (_QWORD)v33) = v34;
          }
          while ( v32 > 0 );
          v5 += v30;
          if ( v5 < 496 )
          {
            v14 = v61;
            v15 = &v65;
            goto LABEL_5;
          }
          v12 = 0;
        }
        v35 = v64;
        *v9 = v5;
        if ( v64 >= v17 )
        {
          v36 = v3->m_sectors.m_size;
          v37 = v36 + 1;
          v38 = v3->m_sectors.m_capacityAndFlags & 0x3FFFFFFF;
          v39 = v36 - v11;
          if ( v37 > v38 )
          {
            if ( v38 >= v37 )
            {
              result.m_enum = 0;
            }
            else
            {
              v40 = 2 * v38;
              v41 = v37;
              if ( v37 < v40 )
                v41 = v40;
              hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, v41, 8);
              v11 = v59;
            }
          }
          hkMemUtil::memMove(&v3->m_sectors.m_data[v11 + 1], &v3->m_sectors.m_data[v11], 8 * v39);
          ++v59;
          ++v60;
          v35 = v64;
          v3->m_sectors.m_size = v37;
        }
        ++v70;
        v42 = v35 + 1;
        v3->m_sectors.m_data[v42 - 1] = (hkpAgent1nSector *)v9;
        v64 = v42;
        if ( v6 )
        {
          v9 = (int *)v6;
          v6 = 0i64;
        }
        else
        {
          v43 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v44 = (int *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v43[11] + 8i64))(v43[11], 512i64);
          v9 = v44;
          if ( v44 )
            *v44 = 0;
          else
            v9 = 0i64;
        }
        v14 = v61;
        v11 = v59;
        v17 = v60;
        v13 = v63;
        v15 = (char *)(v9 + 4);
        v16 = (__int128 *)(v9 + 128);
        if ( v12 )
        {
          v45 = (signed int)v31 >> 4;
          v46 = &v65;
          do
          {
            v47 = *(_OWORD *)v46;
            --v45;
            v46 += 16;
            *(_OWORD *)&v46[(char *)v9 - &v65] = v47;
          }
          while ( v45 > 0 );
          v14 = v61;
          v11 = v59;
          v15 += v31;
          v12 = 0;
        }
LABEL_5:
        v4 = v62;
      }
      else
      {
        v12 = 1;
        v16 = &v66;
        v28 = (_DWORD)v15 - (_DWORD)v9;
        v15 = &v65;
        v5 = v28 - 16;
      }
    }
  }
  if ( v12 )
  {
    v50 = &v65;
    v51 = (_DWORD)v15 - (v49 + 96);
    v52 = v51 >> 4;
    do
    {
      v53 = *(_OWORD *)v50;
      --v52;
      v50 += 16;
      *(_OWORD *)((char *)v9 + v5 - (_QWORD)&v65 + (_QWORD)v50) = v53;
    }
    while ( v52 > 0 );
    v48 = v51 + v5;
  }
  else
  {
    v48 = (_DWORD)v15 - (_DWORD)v9 - 16;
  }
  *v9 = v48;
  v54 = v70 + 1;
  v55 = v3->m_sectors.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v55 < v70 + 1 )
  {
    v56 = 2 * v55;
    v57 = v70 + 1;
    if ( v54 < v56 )
      v57 = v56;
    hkArrayUtil::_reserve((hkResult *)&v71, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, v57, 8);
  }
  v3->m_sectors.m_size = v54;
  v3->m_sectors.m_data[v70] = (hkpAgent1nSector *)v9;
  v58 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, hkpAgent1nSector *, signed __int64))(*v58[11] + 16i64))(v58[11], v4, 512i64);
}or::s_alloc.vfptr, v3, v57, 8);
  }
  v3->m_sectors.m_size = v54;
  v3->m_sectors.m_data[v70] = (hkpAgent1nSector *)v9;
  v58 = (_QWO

// File Line: 1012
// RVA: 0xD3B630
void __fastcall hkAgent1nMachine_initInputAtTime(hkpAgent3Input *in, hkpAgentNmMachineBodyTemp *temp, hkpAgent3Input *out)
{
  hkpAgent3Input *v3; // rdi
  hkTransformf *v4; // rbp
  hkpAgent3Input *v5; // r14
  hkpAgentNmMachineBodyTemp *v6; // rbx
  unsigned int v7; // ecx
  hkpCdBody *v8; // rax
  hkpCdBody *v9; // rax

  v3 = in;
  v4 = &temp->m_transA;
  v5 = out;
  v6 = temp;
  hkSweptTransformUtil::lerp2(
    (hkSweptTransformf *)((char *)in->m_bodyA.m_storage->m_motion + 64),
    in->m_input.m_storage->m_stepInfo.m_startTime.m_storage,
    &temp->m_transA);
  hkSweptTransformUtil::lerp2(
    (hkSweptTransformf *)((char *)v3->m_bodyB.m_storage->m_motion + 64),
    v3->m_input.m_storage->m_stepInfo.m_startTime.m_storage,
    &v6->m_transB);
  v5->m_bodyA.m_storage = &v6->m_bodyA;
  v5->m_bodyB.m_storage = &v6->m_bodyB;
  v5->m_contactMgr.m_storage = v3->m_contactMgr.m_storage;
  v5->m_input.m_storage = v3->m_input.m_storage;
  v7 = v3->m_bodyA.m_storage->m_shapeKey;
  v6->m_bodyA.m_shape = v3->m_bodyA.m_storage->m_shape;
  v6->m_bodyA.m_shapeKey = v7;
  v8 = v3->m_bodyA.m_storage;
  v6->m_bodyA.m_motion = v4;
  v6->m_bodyA.m_parent = v8;
  if ( v6 != (hkpAgentNmMachineBodyTemp *)-32i64 )
  {
    v9 = v3->m_bodyB.m_storage;
    v6->m_bodyB.m_motion = &v6->m_transB;
    v6->m_bodyB.m_parent = v9;
  }
  hkTransformf::setMulInverseMul(&v5->m_aTb, v4, &v6->m_transB);
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
void __fastcall hkAgent1nMachine_UpdateShapeCollectionFilter(hkpAgent1nTrack *agentTrack, hkpAgent1nMachine_VisitorInput *vin)
{
  hkAgent1nMachine_VisitAllAgents(agentTrack, vin, hkAgent1nMachine_UpdateShapeCollectionFilterVisitor);
}

// File Line: 1077
// RVA: 0xD3AC60
void __fastcall hkAgentNmMachine_UpdateShapeCollectionFilter(hkpAgent1nTrack *agentTrack, hkpAgent1nMachine_VisitorInput *vin)
{
  hkAgent1nMachine_VisitAllAgents(agentTrack, vin, hkAgentNmMachine_UpdateShapeCollectionFilterVisitor);
}

