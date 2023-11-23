// File Line: 15
// RVA: 0xD3C250
void __fastcall hkAgent1nMachine_Process(
        hkpAgent1nTrack *agentTrack,
        hkpAgent3ProcessInput *inputIn,
        hkpShapeContainer *shapeContainerB,
        unsigned int *newKeys,
        hkpProcessCollisionOutput *output)
{
  hkpAgent3ProcessInput *v6; // rdi
  hkpProcessCollisionOutput *v8; // r12
  __int128 v9; // xmm0
  hkVector4f v10; // xmm1
  __m128i v11; // xmm2
  __int64 v12; // rax
  unsigned int *v13; // r8
  __int128 v14; // xmm0
  hkVector4f v15; // xmm1
  hkVector4f v16; // xmm0
  hkpProcessCollisionInput *v17; // rcx
  hkVector4f v18; // xmm0
  __int128 v19; // xmm1
  __int64 v20; // rsi
  const char *v21; // rbx
  hkpAgent1nSector *m_spareAgentSector; // r13
  _QWORD **Value; // rax
  hkpAgent1nSector *v24; // rax
  char v25; // r10
  __int64 v26; // rdx
  char *v27; // r15
  char *m_data; // r14
  unsigned __int64 v29; // r9
  hkVector4f v30; // xmm0
  hkVector4f v31; // xmm1
  hkVector4f v32; // xmm0
  hkVector4f v33; // xmm1
  __int64 v34; // r8
  char *v35; // rax
  int v36; // ecx
  __int128 v37; // xmm0
  char *v38; // rcx
  unsigned int v39; // ebx
  unsigned int v40; // eax
  __int64 v41; // r8
  char *v42; // rax
  int v43; // ecx
  __int128 v44; // xmm0
  char *v45; // rdx
  hkpShape *m_shape; // rsi
  hkpShape *v47; // rdi
  __int64 v48; // rdx
  unsigned __int8 v49; // dl
  char v50; // bl
  hkpAgent3ProcessInput *p_cdBody; // rdi
  __int64 v52; // rax
  char v53; // bl
  unsigned int v54; // ebx
  char v55; // di
  char *v56; // rbx
  char *v57; // rbx
  __int64 v58; // rax
  hkpProcessCdPoint *v59; // rdi
  float v60; // xmm6_4
  __m128 *p_m_quad; // rcx
  __m128 v62; // xmm2
  __m128 v63; // xmm0
  __m128 v64; // xmm1
  hkpProcessCollisionInput *v65; // rax
  char *v66; // rsi
  hkpCollisionQualityInfo *v67; // rcx
  __m128 *v68; // rbx
  __m128 v69; // xmm2
  __int64 v70; // rax
  hkpProcessCdPoint *v71; // rdi
  __m128 *v72; // rcx
  __m128 v73; // xmm2
  __m128 v74; // xmm0
  __m128 v75; // xmm1
  unsigned int v76; // ecx
  __int64 v77; // rax
  __int64 v78; // rdi
  unsigned int v79; // edx
  __m128 v80; // xmm3
  __m128 v81; // xmm2
  __m128 v82; // xmm2
  __m128 v83; // xmm1
  bool v84; // zf
  int v85; // esi
  __int64 v86; // rax
  hkpProcessCollisionInput *v87; // rax
  float v88; // xmm0_4
  char *v89; // rsi
  float v90; // xmm1_4
  hkpCollisionQualityInfo *v91; // rcx
  __m128 m_minSeparation_low; // xmm0
  __m128 *v93; // rbx
  __m128 v94; // xmm2
  __int64 v95; // rax
  __int64 v96; // rdi
  unsigned int m_shapeKey; // edx
  __m128 v98; // xmm3
  __m128 v99; // xmm2
  __m128 v100; // xmm2
  __m128 v101; // xmm1
  __int64 v102; // rax
  _QWORD **v103; // rax
  hkpAgent1nTrack *v104; // r11
  hkpAgent1nSector *v105; // rbx
  __int64 m_bytesAllocated; // rax
  __int64 v107; // rdx
  __int64 v108; // rbx
  int v109; // r10d
  int v110; // r10d
  int v111; // r14d
  __int64 v112; // rdi
  char *v113; // r9
  int v114; // ecx
  char *v115; // rax
  __int128 v116; // xmm0
  hkpProcessCollisionOutput::PotentialInfo *v117; // r8
  hkpProcessCollisionOutput::ContactRef *j; // rcx
  __int64 v119; // rdx
  __int64 v120; // rcx
  int m_size; // esi
  __int64 v122; // r14
  int v123; // ebx
  int v124; // eax
  int v125; // esi
  int v126; // eax
  int v127; // r9d
  hkpAgent1nSector **v128; // rax
  __int64 v129; // rcx
  _QWORD **v130; // rax
  hkpAgent1nSector *v131; // rax
  int v132; // ecx
  char *v133; // rax
  __int128 v134; // xmm0
  hkpProcessCollisionOutput::PotentialInfo *v135; // r8
  hkpProcessCollisionOutput::ContactRef *i; // rcx
  __int64 v137; // rdx
  __int64 v138; // r9
  int v139; // r9d
  int v140; // r14d
  char *v141; // rax
  char *v142; // r8
  int v143; // ecx
  __int128 v144; // xmm0
  hkpProcessCollisionOutput::PotentialInfo *v145; // rax
  hkpProcessCollisionOutput::ContactRef *m_firstFreePotentialContact; // rcx
  __int64 v147; // rdx
  __int64 v148; // r14
  int v149; // ebx
  int v150; // eax
  int v151; // eax
  int v152; // r9d
  _QWORD *v153; // rax
  unsigned __int64 v154; // rcx
  unsigned __int64 v155; // rcx
  hkVector4f v156; // xmm0
  hkVector4f v157; // xmm1
  hkpProcessCollisionOutput::PotentialInfo *v158; // rcx
  hkVector4f v159; // xmm0
  hkVector4f v160; // xmm1
  char v161; // [rsp+40h] [rbp-C0h]
  int v162; // [rsp+44h] [rbp-BCh]
  hkPadSpu<unsigned char> cdBodyHasTransformFlag; // [rsp+48h] [rbp-B8h] BYREF
  bool v164; // [rsp+49h] [rbp-B7h]
  char v165; // [rsp+4Ah] [rbp-B6h] BYREF
  hkPadSpu<unsigned char> v166; // [rsp+4Bh] [rbp-B5h] BYREF
  __int64 v167; // [rsp+50h] [rbp-B0h]
  int v168; // [rsp+58h] [rbp-A8h]
  int v169; // [rsp+5Ch] [rbp-A4h]
  float v170; // [rsp+60h] [rbp-A0h]
  int v171; // [rsp+64h] [rbp-9Ch]
  __int64 v172; // [rsp+68h] [rbp-98h]
  hkpShape *v173; // [rsp+70h] [rbp-90h] BYREF
  unsigned int v174; // [rsp+78h] [rbp-88h]
  __int64 v175; // [rsp+80h] [rbp-80h]
  __int64 v176; // [rsp+88h] [rbp-78h]
  char *v177; // [rsp+90h] [rbp-70h]
  int v178; // [rsp+98h] [rbp-68h]
  hkpProcessCollisionOutput::PotentialInfo *m_storage; // [rsp+A0h] [rbp-60h]
  __int64 v180; // [rsp+A8h] [rbp-58h]
  hkResult result; // [rsp+B0h] [rbp-50h] BYREF
  hkpAgent1nSector *v182; // [rsp+B8h] [rbp-48h]
  hkpAgent3ProcessInput cdBody; // [rsp+C0h] [rbp-40h] BYREF
  char *v184; // [rsp+150h] [rbp+50h]
  char v185[128]; // [rsp+160h] [rbp+60h] BYREF
  char v186[512]; // [rsp+1E0h] [rbp+E0h] BYREF
  hkpShapeContainer *v187; // [rsp+3E0h] [rbp+2E0h]
  unsigned int *v188; // [rsp+3E8h] [rbp+2E8h]
  unsigned int v189; // [rsp+3F0h] [rbp+2F0h]
  hkpAgent3ProcessInput v190; // [rsp+400h] [rbp+300h] BYREF
  hkpAgent3Input v191; // [rsp+490h] [rbp+390h] BYREF
  hkpAgentNmMachineBodyTemp temp; // [rsp+500h] [rbp+400h] BYREF
  hkpAgent3Input v193; // [rsp+5C0h] [rbp+4C0h] BYREF
  hkpAgent3ProcessInput out; // [rsp+630h] [rbp+530h] BYREF
  hkpAgent3ProcessInput v195; // [rsp+6C0h] [rbp+5C0h] BYREF
  hkpCdBody newCdBodies; // [rsp+750h] [rbp+650h] BYREF
  hkpAgentNmMachineBodyTemp v197; // [rsp+7D0h] [rbp+6D0h] BYREF
  hkMotionState newMotionStates; // [rsp+890h] [rbp+790h] BYREF
  __int64 v199[2]; // [rsp+B50h] [rbp+A50h] BYREF
  char v200; // [rsp+B60h] [rbp+A60h] BYREF
  char v201; // [rsp+1360h] [rbp+1260h] BYREF
  hkpAgent3ProcessInput *v203; // [rsp+2BC8h] [rbp+2AC8h] BYREF
  hkpShapeContainer *shapeCollection; // [rsp+2BD0h] [rbp+2AD0h]
  unsigned int *v205; // [rsp+2BD8h] [rbp+2AD8h]

  v205 = newKeys;
  shapeCollection = shapeContainerB;
  v203 = inputIn;
  v6 = inputIn;
  _mm_prefetch((const char *)agentTrack->m_sectors.m_data, 0);
  v8 = output;
  m_storage = output->m_potentialContacts.m_storage;
  if ( m_storage || !shapeContainerB->vfptr->isWeldingEnabled(shapeContainerB) )
  {
    v8->m_potentialContacts.m_storage = 0i64;
  }
  else
  {
    v199[0] = (__int64)&v201;
    v199[1] = (__int64)&v200;
    v8->m_potentialContacts.m_storage = (hkpProcessCollisionOutput::PotentialInfo *)v199;
  }
  v9 = *(_OWORD *)&v6->m_bodyA.m_storage;
  v10.m_quad = (__m128)v6->m_aTb.m_rotation.m_col0;
  v11 = *(__m128i *)&v6->m_overrideBodyA.m_storage;
  v12 = (__int64)v6->m_bodyB.m_storage;
  v13 = v205;
  v187 = shapeContainerB;
  v188 = v205;
  v189 = -1;
  v162 = 0;
  *(_OWORD *)&cdBody.m_bodyA.m_storage = v9;
  v14 = *(_OWORD *)&v6->m_contactMgr.m_storage;
  cdBody.m_aTb.m_rotation.m_col0 = (hkVector4f)v10.m_quad;
  v15.m_quad = (__m128)v6->m_aTb.m_rotation.m_col2;
  *(_OWORD *)&cdBody.m_contactMgr.m_storage = v14;
  cdBody.m_aTb.m_rotation.m_col1 = v6->m_aTb.m_rotation.m_col1;
  v16.m_quad = (__m128)v6->m_aTb.m_translation;
  *(__m128i *)&cdBody.m_overrideBodyA.m_storage = v11;
  v17 = (hkpProcessCollisionInput *)_mm_srli_si128(v11, 8).m128i_u64[0];
  cdBody.m_aTb.m_translation = (hkVector4f)v16.m_quad;
  v18.m_quad = (__m128)v6->m_linearTimInfo;
  cdBody.m_aTb.m_rotation.m_col2 = (hkVector4f)v15.m_quad;
  v19 = *(_OWORD *)&v6->m_distAtT1.m_storage;
  cdBody.m_linearTimInfo = (hkVector4f)v18.m_quad;
  *(_OWORD *)&cdBody.m_distAtT1.m_storage = v19;
  v20 = (__int64)v17->m_dispatcher.m_storage;
  v176 = v12;
  v175 = *(_QWORD *)(v12 + 16);
  v167 = v20;
  cdBody.m_bodyB.m_storage = (hkpCdBody *)&v173;
  v21 = (const char *)*agentTrack->m_sectors.m_data;
  v182 = (hkpAgent1nSector *)v21;
  _mm_prefetch(v21, 0);
  _mm_prefetch(v21 + 64, 0);
  _mm_prefetch(v21 + 128, 0);
  _mm_prefetch(v21 + 192, 0);
  m_spareAgentSector = v17->m_spareAgentSector;
  if ( !m_spareAgentSector )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v24 = (hkpAgent1nSector *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 512i64);
    v13 = v205;
    m_spareAgentSector = v24;
    if ( v24 )
      v24->m_bytesAllocated = 0;
    else
      m_spareAgentSector = 0i64;
    v17 = cdBody.m_input.m_storage;
  }
  v17->m_spareAgentSector = 0i64;
  v191.m_overrideBodyA.m_storage = 0i64;
  v193.m_overrideBodyA.m_storage = 0i64;
  v164 = 0;
  v161 = 0;
  v25 = 0;
  v26 = (__int64)&v21[*(unsigned int *)v21 + 16];
  v171 = 0;
  v169 = 0;
  v180 = 0i64;
  v177 = (char *)&m_spareAgentSector[1];
  LOBYTE(output) = 0;
  v168 = 1;
  v27 = (char *)(v21 + 16);
  v184 = (char *)v26;
  m_data = m_spareAgentSector->m_data;
  v172 = 1i64;
  v29 = 0x140000000ui64;
  while ( 1 )
  {
    v30.m_quad = (__m128)v6->m_aTb.m_rotation.m_col0;
    v31.m_quad = (__m128)v6->m_aTb.m_rotation.m_col1;
    cdBody.m_bodyB.m_storage = (hkpCdBody *)&v173;
    cdBody.m_aTb.m_rotation.m_col0 = (hkVector4f)v30.m_quad;
    v32.m_quad = (__m128)v6->m_aTb.m_rotation.m_col2;
    cdBody.m_aTb.m_rotation.m_col1 = (hkVector4f)v31.m_quad;
    v33.m_quad = (__m128)v6->m_aTb.m_translation;
    cdBody.m_aTb.m_rotation.m_col2 = (hkVector4f)v32.m_quad;
    cdBody.m_aTb.m_translation = (hkVector4f)v33.m_quad;
    if ( v13 )
    {
      v38 = v27;
      v39 = *v188;
      v189 = v39;
      v40 = *((_DWORD *)v27 + 2);
      if ( v39 == v40 )
      {
        v41 = (unsigned __int8)v27[3];
        v42 = v27;
        v43 = (int)(unsigned __int8)v27[3] >> 4;
        do
        {
          v44 = *(_OWORD *)v42;
          --v43;
          v42 += 16;
          *(_OWORD *)&v42[m_data - v27 - 16] = v44;
        }
        while ( v43 > 0 );
        v27 += v41;
        goto LABEL_37;
      }
      if ( v39 > v40 )
      {
        v45 = v27 + 32;
        if ( (*v27 & 6) != 4 )
          v45 = v27 + 16;
        v27 += (unsigned __int8)v27[3];
        (*(void (__fastcall **)(char *, char *, hkpContactMgr *, hkpConstraintOwner *, __int64))(112i64
                                                                                               * (unsigned __int8)v38[1]
                                                                                               + v20
                                                                                               + 8184))(
          v38,
          v45,
          cdBody.m_contactMgr.m_storage,
          v8->m_constraintOwner.m_storage,
          v20);
        goto LABEL_81;
      }
      cdBody.m_input.m_storage->m_filter.m_storage->vfptr->isCollisionEnabled(
        &cdBody.m_input.m_storage->m_filter.m_storage->hkpShapeCollectionFilter,
        (hkBool *)&v165,
        cdBody.m_input.m_storage,
        v6->m_bodyA.m_storage,
        v6->m_bodyB.m_storage,
        v187,
        v39);
      if ( v165 )
      {
        if ( hkOutOfMemoryState == MEMORY_STATE_OUT_OF_MEMORY )
        {
          ++v188;
LABEL_81:
          v85 = v162;
          goto $checkReadSector;
        }
        v173 = v187->vfptr->getChildShape(v187, v189, (char (*)[512])v186);
        v174 = v189;
        m_shape = cdBody.m_bodyA.m_storage->m_shape;
        cdBodyHasTransformFlag.m_storage = 0;
        cdBody.m_bodyB.m_storage = hkAgentMachine_processTransformedShapes(
                                     cdBody.m_bodyB.m_storage,
                                     &newCdBodies,
                                     &newMotionStates,
                                     4,
                                     &cdBodyHasTransformFlag);
        v47 = cdBody.m_bodyB.m_storage->m_shape;
        hkTransformf::setMulInverseMul(
          &cdBody.m_aTb,
          (hkTransformf *)cdBody.m_bodyA.m_storage->m_motion,
          (hkTransformf *)cdBody.m_bodyB.m_storage->m_motion);
        *((_DWORD *)m_data + 1) = -1;
        *((_DWORD *)m_data + 2) = v39;
        v48 = (unsigned __int8)m_shape->m_type.m_storage;
        v20 = v167;
        if ( cdBody.m_input.m_storage->m_createPredictiveAgents.m_storage )
          v49 = *(_BYTE *)((unsigned __int8)v47->m_type.m_storage + v167 + 35i64 * (int)v48 + 6944);
        else
          v49 = *(_BYTE *)((unsigned __int8)v47->m_type.m_storage + v167 + 35 * v48 + 5712);
        m_data[1] = v49;
        m_data[2] = 0;
        out.m_overrideBodyA.m_storage = 0i64;
        v50 = 0;
        p_cdBody = &cdBody;
        if ( *(_DWORD *)(112i64 * v49 + v20 + 8272) == 2 )
        {
          v50 = 1;
          p_cdBody = &out;
          hkAgent1nMachine_flipInput(&cdBody, &out);
        }
        v52 = (unsigned __int8)m_data[1] + 73i64;
        if ( *(_QWORD *)(112i64 * (unsigned __int8)m_data[1] + v20 + 8248) )
        {
          *((_DWORD *)m_data + 3) = -1082130432;
          v53 = cdBodyHasTransformFlag.m_storage | (v50 + 4);
          *((_OWORD *)m_data + 1) = 0i64;
          *m_data = v53;
          m_data[3] = (*(__int64 (__fastcall **)(hkpAgent3ProcessInput *, char *, char *))(112 * v52 + v20))(
                        p_cdBody,
                        m_data,
                        m_data + 32)
                    - (_BYTE)m_data;
        }
        else
        {
          *m_data = cdBodyHasTransformFlag.m_storage | (v50 + 2);
          m_data[3] = (*(__int64 (__fastcall **)(hkpAgent3ProcessInput *, char *, char *))(112 * v52 + v20))(
                        p_cdBody,
                        m_data,
                        m_data + 16)
                    - (_BYTE)m_data;
        }
      }
      else
      {
        *(_DWORD *)m_data = 0;
        *((_DWORD *)m_data + 1) = -1;
        *((_DWORD *)m_data + 2) = v39;
        m_data[3] = 16;
      }
      v25 = (char)output;
      v29 = 0x140000000ui64;
LABEL_37:
      ++v188;
      goto LABEL_38;
    }
    v34 = (unsigned __int8)v27[3];
    v35 = v27;
    v36 = (int)(unsigned __int8)v27[3] >> 4;
    do
    {
      v37 = *(_OWORD *)v35;
      --v36;
      v35 += 16;
      *(_OWORD *)&v35[m_data - v27 - 16] = v37;
    }
    while ( v36 > 0 );
    v27 += v34;
LABEL_38:
    v54 = (unsigned __int8)*m_data;
    v55 = 0;
    while ( 2 )
    {
      switch ( v54 )
      {
        case 0u:
        case 1u:
          m_data += 16;
          goto LABEL_80;
        case 2u:
          v56 = m_data;
          v173 = (hkpShape *)((__int64 (__fastcall *)(hkpShapeContainer *, _QWORD, char *, unsigned __int64))v187->vfptr->getChildShape)(
                               v187,
                               v189,
                               v186,
                               0x140000000ui64);
          v174 = v189;
          m_data = (char *)(*(__int64 (__fastcall **)(hkpAgent3ProcessInput *, char *, char *, _QWORD, hkpProcessCollisionOutput *))(112i64 * (unsigned __int8)m_data[1] + v20 + 8256))(
                             &cdBody,
                             m_data,
                             m_data + 16,
                             0i64,
                             v8);
          v56[3] = (_BYTE)m_data - (_BYTE)v56;
          goto LABEL_80;
        case 3u:
          v195.m_overrideBodyA.m_storage = 0i64;
          hkAgent1nMachine_flipInput(&cdBody, &v195);
          v57 = m_data;
          v58 = (__int64)v187->vfptr->getChildShape(v187, v189, (char (*)[512])v186);
          v59 = v8->m_firstFreeContactPoint.m_storage;
          v60 = v8->m_toi.m_time.m_storage;
          v173 = (hkpShape *)v58;
          v174 = v189;
          m_data = (char *)(*(__int64 (__fastcall **)(hkpAgent3ProcessInput *, char *, char *, _QWORD, hkpProcessCollisionOutput *))(112i64 * (unsigned __int8)m_data[1] + v20 + 8256))(
                             &v195,
                             m_data,
                             m_data + 16,
                             0i64,
                             v8);
          v57[3] = (_BYTE)m_data - (_BYTE)v57;
          if ( v59 < v8->m_firstFreeContactPoint.m_storage )
          {
            p_m_quad = &v59->m_contact.m_separatingNormal.m_quad;
            v62 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64);
            do
            {
              v63 = *p_m_quad;
              p_m_quad += 3;
              v64 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v63, v63, 255), v63), p_m_quad[-4]);
              p_m_quad[-3] = _mm_xor_ps(p_m_quad[-3], v62);
              p_m_quad[-4] = v64;
            }
            while ( (hkpProcessCdPoint *)&p_m_quad[-1] < v8->m_firstFreeContactPoint.m_storage );
          }
          goto LABEL_47;
        case 4u:
          v87 = cdBody.m_input.m_storage;
          v88 = *((float *)m_data + 3);
          v89 = m_data;
          if ( v88 == cdBody.m_input.m_storage->m_stepInfo.m_startTime.m_storage
            || (v90 = cdBody.m_input.m_storage->m_stepInfo.m_endTime.m_storage, v88 >= v90) )
          {
            v96 = v167;
          }
          else
          {
            v91 = cdBody.m_input.m_storage->m_collisionQualityInfo.m_storage;
            if ( !v91->m_useContinuousPhysics.m_storage )
            {
              *((float *)m_data + 3) = v90;
              m_minSeparation_low = (__m128)LODWORD(v91->m_minSeparation);
              v178 = 1036831949;
              v93 = (__m128 *)(m_data + 16);
              v94 = _mm_mul_ps(
                      _mm_shuffle_ps((__m128)0x3DCCCCCDu, (__m128)0x3DCCCCCDu, 0),
                      _mm_shuffle_ps(m_minSeparation_low, m_minSeparation_low, 0));
              *((__m128 *)m_data + 1) = _mm_shuffle_ps(aabbOut.m_quad, _mm_unpackhi_ps(aabbOut.m_quad, v94), 196);
$PROCESS_AT_T1_0:
              LODWORD(cdBody.m_distAtT1.m_storage) = v94.m128_i32[0];
              v173 = (hkpShape *)((__int64 (__fastcall *)(hkpShapeContainer *, _QWORD, char *, unsigned __int64))v187->vfptr->getChildShape)(
                                   v187,
                                   v189,
                                   v186,
                                   v29);
              v174 = v189;
              m_data = (char *)(*(__int64 (__fastcall **)(hkpAgent3ProcessInput *, char *, char *, __m128 *, hkpProcessCollisionOutput *))(112i64 * (unsigned __int8)m_data[1] + v167 + 8256))(
                                 &cdBody,
                                 m_data,
                                 m_data + 32,
                                 v93,
                                 v8);
              v89[3] = (_BYTE)m_data - (_BYTE)v89;
              goto LABEL_80;
            }
            if ( !v25 )
            {
              LOBYTE(output) = v55 == 0;
              hkAgent1nMachine_initInputAtTime(&cdBody, &v197, &v191);
            }
            v95 = ((__int64 (__fastcall *)(hkpShapeContainer *, _QWORD, char *, unsigned __int64))v187->vfptr->getChildShape)(
                    v187,
                    v189,
                    v186,
                    v29);
            v96 = v167;
            v173 = (hkpShape *)v95;
            v174 = v189;
            m_shapeKey = cdBody.m_bodyB.m_storage->m_shapeKey;
            v197.m_bodyB.m_shape = cdBody.m_bodyB.m_storage->m_shape;
            v197.m_bodyB.m_shapeKey = m_shapeKey;
            (*(void (__fastcall **)(hkpAgent3Input *, char *, char *, char *))(112i64 * (unsigned __int8)m_data[1]
                                                                             + v167
                                                                             + 8248))(
              &v191,
              m_data,
              m_data + 32,
              m_data + 16);
            v87 = cdBody.m_input.m_storage;
          }
          v93 = (__m128 *)(m_data + 16);
          *((_DWORD *)m_data + 3) = LODWORD(v87->m_stepInfo.m_endTime.m_storage);
          v98 = *((__m128 *)m_data + 1);
          v99 = _mm_mul_ps(cdBody.m_linearTimInfo.m_quad, v98);
          v100 = _mm_shuffle_ps(v99, _mm_unpackhi_ps(v99, cdBody.m_linearTimInfo.m_quad), 196);
          v101 = _mm_add_ps(_mm_shuffle_ps(v100, v100, 78), v100);
          v94 = _mm_sub_ps(_mm_shuffle_ps(v98, v98, 255), _mm_add_ps(_mm_shuffle_ps(v101, v101, 177), v101));
          v170 = cdBody.m_input.m_storage->m_tolerance.m_storage;
          if ( v94.m128_f32[0] < _mm_shuffle_ps((__m128)LODWORD(v170), (__m128)LODWORD(v170), 0).m128_f32[0] )
            goto $PROCESS_AT_T1_0;
          *v93 = _mm_shuffle_ps(v98, _mm_unpackhi_ps(v98, v94), 196);
          if ( m_data[2] )
          {
            v102 = (*(__int64 (__fastcall **)(char *, char *, hkpContactMgr *, hkpConstraintOwner *))(112i64 * (unsigned __int8)m_data[1] + v96 + 0x2000))(
                     m_data,
                     m_data + 32,
                     cdBody.m_contactMgr.m_storage,
                     v8->m_constraintOwner.m_storage);
            v6 = v203;
            m_data = (char *)v102;
            v89[3] = v102 - (_BYTE)v89;
          }
          else
          {
            v6 = v203;
            m_data += (unsigned __int8)m_data[3];
          }
          v85 = ++v162;
          break;
        case 5u:
          v190.m_overrideBodyA.m_storage = 0i64;
          hkAgent1nMachine_flipInput(&cdBody, &v190);
          v65 = v190.m_input.m_storage;
          v66 = m_data;
          if ( v190.m_input.m_storage->m_stepInfo.m_startTime.m_storage == *((float *)m_data + 3) )
          {
            v78 = v167;
          }
          else
          {
            v67 = v190.m_input.m_storage->m_collisionQualityInfo.m_storage;
            if ( !v67->m_useContinuousPhysics.m_storage )
            {
              v68 = (__m128 *)(m_data + 16);
              *((_DWORD *)m_data + 3) = LODWORD(v190.m_input.m_storage->m_stepInfo.m_endTime.m_storage);
              v69 = _mm_mul_ps(
                      _mm_shuffle_ps((__m128)LODWORD(v67->m_minSeparation), (__m128)LODWORD(v67->m_minSeparation), 0),
                      (__m128)xmmword_141A711B0);
              *((__m128 *)m_data + 1) = _mm_shuffle_ps(aabbOut.m_quad, _mm_unpackhi_ps(aabbOut.m_quad, v69), 196);
              goto $PROCESS_AT_T1_FLIPPED;
            }
            if ( !v164 )
            {
              v164 = v55 == 0;
              hkAgent1nMachine_initInputAtTime(&v190, &temp, &v193);
              v76 = v190.m_bodyB.m_storage->m_shapeKey;
              temp.m_bodyB.m_shape = v190.m_bodyB.m_storage->m_shape;
              temp.m_bodyB.m_shapeKey = v76;
            }
            v77 = (__int64)v187->vfptr->getChildShape(v187, v189, (char (*)[512])v186);
            v78 = v167;
            v173 = (hkpShape *)v77;
            v174 = v189;
            v79 = cdBody.m_bodyB.m_storage->m_shapeKey;
            temp.m_bodyA.m_shape = cdBody.m_bodyB.m_storage->m_shape;
            temp.m_bodyA.m_shapeKey = v79;
            (*(void (__fastcall **)(hkpAgent3Input *, char *, char *, char *))(112i64 * (unsigned __int8)m_data[1]
                                                                             + v167
                                                                             + 8248))(
              &v193,
              m_data,
              m_data + 32,
              m_data + 16);
            v65 = v190.m_input.m_storage;
          }
          v80 = *((__m128 *)m_data + 1);
          v68 = (__m128 *)(m_data + 16);
          *((_DWORD *)m_data + 3) = LODWORD(v65->m_stepInfo.m_endTime.m_storage);
          v81 = _mm_mul_ps(v80, v190.m_linearTimInfo.m_quad);
          v82 = _mm_shuffle_ps(v81, _mm_unpackhi_ps(v81, v190.m_linearTimInfo.m_quad), 196);
          v83 = _mm_add_ps(_mm_shuffle_ps(v82, v82, 78), v82);
          v69 = _mm_sub_ps(_mm_shuffle_ps(v80, v80, 255), _mm_add_ps(_mm_shuffle_ps(v83, v83, 177), v83));
          v170 = v190.m_input.m_storage->m_tolerance.m_storage;
          if ( v69.m128_f32[0] >= _mm_shuffle_ps((__m128)LODWORD(v170), (__m128)LODWORD(v170), 0).m128_f32[0] )
          {
            v84 = m_data[2] == 0;
            *v68 = _mm_shuffle_ps(v80, _mm_unpackhi_ps(v80, v69), 196);
            if ( v84 )
            {
              v6 = v203;
              m_data += (unsigned __int8)m_data[3];
            }
            else
            {
              v86 = (*(__int64 (__fastcall **)(char *, char *, hkpContactMgr *, hkpConstraintOwner *))(112i64 * (unsigned __int8)m_data[1] + v78 + 0x2000))(
                      m_data,
                      m_data + 32,
                      v190.m_contactMgr.m_storage,
                      v8->m_constraintOwner.m_storage);
              v6 = v203;
              m_data = (char *)v86;
              v66[3] = v86 - (_BYTE)v66;
            }
            v85 = ++v162;
            break;
          }
$PROCESS_AT_T1_FLIPPED:
          LODWORD(v190.m_distAtT1.m_storage) = v69.m128_i32[0];
          v70 = (__int64)v187->vfptr->getChildShape(v187, v189, (char (*)[512])v186);
          v71 = v8->m_firstFreeContactPoint.m_storage;
          v60 = v8->m_toi.m_time.m_storage;
          v173 = (hkpShape *)v70;
          v174 = v189;
          m_data = (char *)(*(__int64 (__fastcall **)(hkpAgent3ProcessInput *, char *, char *, __m128 *, hkpProcessCollisionOutput *))(112i64 * (unsigned __int8)m_data[1] + v167 + 8256))(
                             &v190,
                             m_data,
                             m_data + 32,
                             v68,
                             v8);
          v66[3] = (_BYTE)m_data - (_BYTE)v66;
          if ( v71 < v8->m_firstFreeContactPoint.m_storage )
          {
            v72 = &v71->m_contact.m_separatingNormal.m_quad;
            v73 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64);
            do
            {
              v74 = *v72;
              v72 += 3;
              v75 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v74, v74, 255), v74), v72[-4]);
              v72[-3] = _mm_xor_ps(v73, v72[-3]);
              v72[-4] = v75;
            }
            while ( (hkpProcessCdPoint *)&v72[-1] < v8->m_firstFreeContactPoint.m_storage );
          }
LABEL_47:
          if ( v60 != v8->m_toi.m_time.m_storage )
            hkpProcessCollisionData::ToiInfo::flip(&v8->m_toi);
LABEL_80:
          v6 = v203;
          goto LABEL_81;
        case 6u:
          v173 = (hkpShape *)((__int64 (__fastcall *)(hkpShapeContainer *, _QWORD, char *, unsigned __int64))v187->vfptr->getChildShape)(
                               v187,
                               v189,
                               v186,
                               0x140000000ui64);
          v174 = v189;
          (*(void (__fastcall **)(_QWORD, hkpCdBody *, hkpCdBody *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *))(**((_QWORD **)m_data + 2) + 48i64))(
            *((_QWORD *)m_data + 2),
            cdBody.m_bodyA.m_storage,
            cdBody.m_bodyB.m_storage,
            cdBody.m_input.m_storage,
            v8);
          m_data += 32;
          goto LABEL_80;
        case 0xAu:
        case 0xBu:
        case 0xCu:
        case 0xDu:
        case 0xEu:
          v173 = (hkpShape *)((__int64 (__fastcall *)(hkpShapeContainer *, _QWORD, char *, unsigned __int64))v187->vfptr->getChildShape)(
                               v187,
                               v189,
                               v186,
                               0x140000000ui64);
          v174 = v189;
          v166.m_storage = 0;
          cdBody.m_bodyB.m_storage = hkAgentMachine_processTransformedShapes(
                                       cdBody.m_bodyB.m_storage,
                                       &newCdBodies,
                                       &newMotionStates,
                                       4,
                                       &v166);
          hkTransformf::setMulInverseMul(
            &cdBody.m_aTb,
            (hkTransformf *)cdBody.m_bodyA.m_storage->m_motion,
            (hkTransformf *)cdBody.m_bodyB.m_storage->m_motion);
          v25 = 0;
          v54 &= 0xF7u;
          v55 = 1;
          v164 = 0;
          LOBYTE(output) = 0;
          v29 = 0x140000000ui64;
          if ( v54 <= 0xE )
            continue;
          goto LABEL_80;
        default:
          goto LABEL_80;
      }
      break;
    }
$checkReadSector:
    if ( v27 != v184 )
    {
      v104 = agentTrack;
      v108 = v172;
      goto LABEL_89;
    }
    if ( cdBody.m_input.m_storage->m_spareAgentSector )
    {
      v103 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, hkpAgent1nSector *, __int64))(*v103[11] + 16i64))(v103[11], v182, 512i64);
    }
    else
    {
      cdBody.m_input.m_storage->m_spareAgentSector = v182;
    }
    v104 = agentTrack;
    if ( v168 >= agentTrack->m_sectors.m_size )
      break;
    v105 = agentTrack->m_sectors.m_data[v172];
    ++v168;
    m_bytesAllocated = v105->m_bytesAllocated;
    v27 = v105->m_data;
    v182 = v105;
    v107 = (__int64)&v105->m_data[m_bytesAllocated];
    v108 = v172 + 1;
    v184 = (char *)v107;
    ++v172;
LABEL_89:
    v20 = v167;
    v13 = v205;
    v25 = (char)output;
    v29 = 0x140000000ui64;
    if ( m_data + 128 > v177 )
    {
      if ( !v161 )
      {
        v161 = 1;
        v109 = (_DWORD)m_data - (_DWORD)m_spareAgentSector;
        m_data = v185;
        v177 = v186;
        v169 = v109 - 16;
        goto LABEL_125;
      }
      v110 = v169;
      v111 = (_DWORD)m_data - ((unsigned int)&cdBody.m_aTb.m_rotation.m_col1 + 96);
      v112 = v111;
      if ( v111 > 496 - v169 )
      {
LABEL_104:
        v120 = v180;
        m_spareAgentSector->m_bytesAllocated = v110;
        if ( v120 >= v108 )
        {
          m_size = v104->m_sectors.m_size;
          v122 = v168;
          v123 = m_size + 1;
          v124 = v104->m_sectors.m_capacityAndFlags & 0x3FFFFFFF;
          v125 = m_size - v168;
          if ( v123 > v124 )
          {
            v126 = 2 * v124;
            v127 = v123;
            if ( v123 < v126 )
              v127 = v126;
            hkArrayUtil::_reserve(
              &result,
              &hkContainerHeapAllocator::s_alloc,
              (const void **)&v104->m_sectors.m_data,
              v127,
              8);
            v104 = agentTrack;
          }
          hkMemUtil::memMove(&v104->m_sectors.m_data[v122 + 1], &v104->m_sectors.m_data[v122], 8 * v125);
          v104 = agentTrack;
          v120 = v180;
          ++v172;
          agentTrack->m_sectors.m_size = v123;
          v168 = v122 + 1;
        }
        v128 = v104->m_sectors.m_data;
        ++v171;
        v129 = v120 + 1;
        v128[v129 - 1] = m_spareAgentSector;
        v180 = v129;
        m_spareAgentSector = cdBody.m_input.m_storage->m_spareAgentSector;
        if ( !m_spareAgentSector )
        {
          v130 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v131 = (hkpAgent1nSector *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v130[11] + 8i64))(v130[11], 512i64);
          m_spareAgentSector = v131;
          if ( v131 )
            v131->m_bytesAllocated = 0;
          else
            m_spareAgentSector = 0i64;
        }
        v20 = v167;
        v13 = v205;
        v25 = (char)output;
        cdBody.m_input.m_storage->m_spareAgentSector = 0i64;
        m_data = m_spareAgentSector->m_data;
        v29 = 0x140000000ui64;
        v177 = (char *)&m_spareAgentSector[1];
        if ( v161 )
        {
          v132 = (int)v112 >> 4;
          v133 = v185;
          do
          {
            v134 = *(_OWORD *)v133;
            --v132;
            v133 += 16;
            *(_OWORD *)&v133[(char *)m_spareAgentSector - v185] = v134;
          }
          while ( v132 > 0 );
          v135 = v8->m_potentialContacts.m_storage;
          if ( v135 )
          {
            for ( i = v135->m_potentialContacts; i < v135->m_firstFreePotentialContact; ++i )
            {
              v137 = (char *)i->m_agentEntry - v185;
              if ( v137 >= 0 && v137 < v112 )
              {
                i->m_agentEntry = (hkpAgentEntry *)&m_data[v137];
                i->m_agentData = (char *)i->m_agentData + m_data - v185;
              }
            }
          }
          m_data += v112;
          v161 = 0;
          goto LABEL_124;
        }
        v6 = v203;
      }
      else
      {
        v113 = &m_spareAgentSector->m_data[v169];
        v114 = v111 >> 4;
        v115 = v185;
        do
        {
          v116 = *(_OWORD *)v115;
          --v114;
          v115 += 16;
          *(_OWORD *)&v115[v113 - v185 - 16] = v116;
        }
        while ( v114 > 0 );
        v117 = v8->m_potentialContacts.m_storage;
        v110 += v111;
        v169 = v110;
        if ( v117 )
        {
          for ( j = v117->m_potentialContacts; j < v117->m_firstFreePotentialContact; ++j )
          {
            v119 = (char *)j->m_agentEntry - v185;
            if ( v119 >= 0 && v119 < v111 )
            {
              j->m_agentEntry = (hkpAgentEntry *)&v113[v119];
              j->m_agentData = (char *)j->m_agentData + v113 - v185;
            }
          }
        }
        if ( v110 >= 496 )
        {
          v161 = 0;
          goto LABEL_104;
        }
        m_data = v185;
LABEL_124:
        v6 = v203;
LABEL_125:
        v13 = v205;
        v25 = (char)output;
        v29 = 0x140000000ui64;
      }
    }
  }
  if ( v161 )
  {
    v139 = v169;
    v140 = (_DWORD)m_data - ((unsigned int)&cdBody.m_aTb.m_rotation.m_col1 + 96);
    v141 = v185;
    v142 = &m_spareAgentSector->m_data[v169];
    v143 = v140 >> 4;
    do
    {
      v144 = *(_OWORD *)v141;
      --v143;
      v141 += 16;
      *(_OWORD *)&v141[v142 - v185 - 16] = v144;
    }
    while ( v143 > 0 );
    v145 = v8->m_potentialContacts.m_storage;
    if ( v145 )
    {
      m_firstFreePotentialContact = v145->m_firstFreePotentialContact;
      if ( v145->m_firstFreePotentialContact > v145->m_potentialContacts )
      {
        v147 = (char *)m_firstFreePotentialContact[-1].m_agentEntry - v185;
        if ( v147 >= 0 && v147 < v140 )
        {
          m_firstFreePotentialContact[-1].m_agentEntry = (hkpAgentEntry *)&v142[v147];
          m_firstFreePotentialContact[-1].m_agentData = (char *)m_firstFreePotentialContact[-1].m_agentData
                                                      + v142
                                                      - v185;
        }
      }
    }
    v138 = (unsigned int)(v140 + v139);
  }
  else
  {
    v138 = (unsigned int)((_DWORD)m_data - (_DWORD)m_spareAgentSector - 16);
  }
  v148 = v171;
  m_spareAgentSector->m_bytesAllocated = v138;
  v149 = v148 + 1;
  v150 = agentTrack->m_sectors.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v150 < (int)v148 + 1 )
  {
    v151 = 2 * v150;
    v152 = v148 + 1;
    if ( v149 < v151 )
      v152 = v151;
    hkArrayUtil::_reserve(
      (hkResult *)&v203,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&agentTrack->m_sectors.m_data,
      v152,
      8);
    v104 = agentTrack;
  }
  v104->m_sectors.m_size = v149;
  v104->m_sectors.m_data[v148] = m_spareAgentSector;
  if ( v85 )
  {
    v153 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v154 = v153[1];
    if ( v154 < v153[3] )
    {
      v155 = v154 + 16;
      *(_QWORD *)(v155 - 16) = "MinumTim";
      *(float *)(v155 - 8) = (float)v85;
      v153[1] = v155;
    }
  }
  v156.m_quad = (__m128)v6->m_aTb.m_rotation.m_col0;
  v157.m_quad = (__m128)v6->m_aTb.m_rotation.m_col1;
  v158 = v8->m_potentialContacts.m_storage;
  cdBody.m_bodyB.m_storage = v6->m_bodyB.m_storage;
  cdBody.m_aTb.m_rotation.m_col0 = (hkVector4f)v156.m_quad;
  v159.m_quad = (__m128)v6->m_aTb.m_rotation.m_col2;
  cdBody.m_aTb.m_rotation.m_col1 = (hkVector4f)v157.m_quad;
  v160.m_quad = (__m128)v6->m_aTb.m_translation;
  cdBody.m_aTb.m_rotation.m_col2 = (hkVector4f)v159.m_quad;
  cdBody.m_aTb.m_translation = (hkVector4f)v160.m_quad;
  if ( v158 && v158->m_firstFreePotentialContact > v158->m_potentialContacts )
    hkAgent1nMachine_Weld(&cdBody, shapeCollection, v8, v138);
  v8->m_potentialContacts.m_storage = m_storage;
}
    v153 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v154 = v153[1];
    if ( v154 < v153[3] )
    {
      v155 = v154 + 16;
      *(_QWORD *)(v155 - 16) = "MinumTim";
      *(float *)(v155 - 8) = (float)v85;
      v153[1] = v155;
    }
  }
  v156.m_quad = (__m128)v6->m_aTb.m_rotation.m_col0;
  v157.m_quad = (__m128)v6->m_aTb.m_rotation.m_col1;
  v158 = v8->m_potentialContacts.m_storage;
  cdBody.m_bodyB.m_storage = v6->m_bodyB.m_storage;
  cdBody.m_aTb.m_rotation.m_col0 = (hkVector4f)v156.m_quad;
 

// File Line: 935
// RVA: 0xD3EB20
hkpAgent1nMachineEntry *__fastcall hkAgentNmMachine_UpdateShapeCollectionFilterVisitor(
        hkpAgent1nMachine_VisitorInput *vin,
        hkpAgent1nMachineEntry *entry,
        void *agentData)
{
  hkpShapeKeyPair m_shapeKeyPair; // rbx
  hkpCollisionInput *m_input; // r8
  hkpCdBody *m_bodyA; // r9
  hkpCollisionFilter *m_storage; // rcx
  hkpShapeCollectionFilterVtbl *vfptr; // r10
  hkpShapeContainer *m_containerShapeA; // rax
  bool v12; // zf
  hkpCollisionInput *v13; // rax
  void (__fastcall *m_updateFilterFunc)(hkpAgentEntry *, void *, hkpCdBody *, hkpCdBody *, hkpCollisionInput *, hkpContactMgr *, hkpConstraintOwner *); // r12
  unsigned int m_shapeKeyB; // esi
  hkpShape *v16; // rdi
  hkpShape *v17; // rax
  hkpCdBody *v18; // rdx
  const void *m_motion; // rcx
  hkpCdBody *v20; // rcx
  const void *v21; // rcx
  hkpCdBody *p_cdBody; // rbx
  hkpShapeContainer *m_containerShapeB; // [rsp+30h] [rbp-D0h]
  hkpCdBody cdBody; // [rsp+50h] [rbp-B0h] BYREF
  hkpCdBody v26; // [rsp+70h] [rbp-90h] BYREF
  hkpCdBody v27; // [rsp+90h] [rbp-70h] BYREF
  hkpCdBody newCdBodies; // [rsp+110h] [rbp+10h] BYREF
  char v29[512]; // [rsp+190h] [rbp+90h] BYREF
  hkMotionState newMotionStates; // [rsp+390h] [rbp+290h] BYREF
  char v31[512]; // [rsp+650h] [rbp+550h] BYREF
  hkMotionState v32; // [rsp+850h] [rbp+750h] BYREF
  hkPadSpu<unsigned char> cdBodyHasTransformFlag; // [rsp+B50h] [rbp+A50h] BYREF
  hkpShapeKeyPair v34; // [rsp+B58h] [rbp+A58h]

  m_shapeKeyPair = entry->m_shapeKeyPair;
  m_input = vin->m_input;
  m_bodyA = vin->m_bodyA;
  m_storage = m_input->m_filter.m_storage;
  vfptr = m_storage->hkpShapeCollectionFilter::vfptr;
  m_containerShapeB = vin->m_containerShapeB;
  m_containerShapeA = vin->m_containerShapeA;
  v34 = m_shapeKeyPair;
  v12 = *(_BYTE *)vfptr->isCollisionEnabled(
                    &m_storage->hkpShapeCollectionFilter,
                    (hkBool *)&cdBodyHasTransformFlag,
                    m_input,
                    m_bodyA,
                    vin->m_collectionBodyB,
                    m_containerShapeA,
                    m_containerShapeB,
                    m_shapeKeyPair.m_shapeKeyA,
                    m_shapeKeyPair.m_shapeKeyB) == 0;
  v13 = vin->m_input;
  if ( v12 )
  {
    v13->m_dispatcher.m_storage->m_agent3Func[(unsigned __int8)entry->m_agentType].m_destroyFunc(
      entry,
      agentData,
      vin->m_contactMgr,
      vin->m_constraintOwner,
      v13->m_dispatcher.m_storage);
    return entry;
  }
  else
  {
    m_updateFilterFunc = v13->m_dispatcher.m_storage->m_agent3Func[(unsigned __int8)entry->m_agentType].m_updateFilterFunc;
    if ( m_updateFilterFunc )
    {
      m_shapeKeyB = v34.m_shapeKeyB;
      v16 = vin->m_containerShapeB->vfptr->getChildShape(vin->m_containerShapeB, v34.m_shapeKeyB, v31);
      v17 = vin->m_containerShapeA->vfptr->getChildShape(vin->m_containerShapeA, m_shapeKeyPair.m_shapeKeyA, v29);
      v12 = (entry->m_streamCommand & 8) == 0;
      v18 = &v26;
      cdBody.m_parent = vin->m_collectionBodyB;
      m_motion = cdBody.m_parent->m_motion;
      cdBody.m_shape = v16;
      cdBody.m_motion = m_motion;
      v20 = vin->m_bodyA;
      cdBody.m_shapeKey = m_shapeKeyB;
      v26.m_parent = v20;
      v21 = v20->m_motion;
      v26.m_shapeKey = m_shapeKeyPair.m_shapeKeyA;
      v26.m_shape = v17;
      v26.m_motion = v21;
      p_cdBody = &cdBody;
      if ( !v12 )
      {
        cdBodyHasTransformFlag.m_storage = 0;
        p_cdBody = hkAgentMachine_processTransformedShapes(
                     &cdBody,
                     &newCdBodies,
                     &newMotionStates,
                     4,
                     &cdBodyHasTransformFlag);
        v18 = hkAgentMachine_processTransformedShapes(&v26, &v27, &v32, 4, &cdBodyHasTransformFlag);
      }
      if ( (((entry->m_streamCommand & 7) - 3) & 0xFD) != 0 )
        m_updateFilterFunc(entry, agentData, v18, p_cdBody, vin->m_input, vin->m_contactMgr, vin->m_constraintOwner);
      else
        m_updateFilterFunc(entry, agentData, p_cdBody, v18, vin->m_input, vin->m_contactMgr, vin->m_constraintOwner);
    }
    return (hkpAgent1nMachineEntry *)((char *)entry + (unsigned __int8)entry->m_size);
  }
}

