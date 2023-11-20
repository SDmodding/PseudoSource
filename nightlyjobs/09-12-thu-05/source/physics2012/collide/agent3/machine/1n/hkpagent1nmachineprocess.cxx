// File Line: 15
// RVA: 0xD3C250
void __fastcall hkAgent1nMachine_Process(hkpAgent1nTrack *agentTrack, hkpAgent3ProcessInput *inputIn, hkpShapeContainer *shapeContainerB, const unsigned int *newKeys, hkpProcessCollisionOutput *output)
{
  hkpShapeContainer *v6; // rsi
  hkpAgent3ProcessInput *v7; // rdi
  hkpAgent1nTrack *v8; // rbx
  hkpProcessCollisionOutput *v9; // r12
  __int128 v10; // xmm0
  hkVector4f v11; // xmm1
  __m128i v12; // xmm2
  __int64 v13; // rax
  const unsigned int *v14; // r8
  __int128 v15; // xmm0
  hkVector4f v16; // xmm1
  hkVector4f v17; // xmm0
  __int64 *v18; // rcx
  __m128 v19; // xmm0
  __int128 v20; // xmm1
  __int64 v21; // rsi
  __m128 *v23; // r13
  _QWORD **v24; // rax
  __m128 *v25; // rax
  char v26; // r10
  signed __int64 v27; // rdx
  signed __int64 v28; // r15
  __m128 *v29; // r14
  signed __int64 v30; // r9
  hkVector4f v31; // xmm0
  hkVector4f v32; // xmm1
  hkVector4f v33; // xmm0
  hkVector4f v34; // xmm1
  __int64 v35; // r8
  __m128 *v36; // rax
  signed int v37; // ecx
  __m128 v38; // xmm0
  signed __int64 v39; // rcx
  unsigned int v40; // ebx
  unsigned int v41; // eax
  __int64 v42; // r8
  __m128 *v43; // rax
  signed int v44; // ecx
  __m128 v45; // xmm0
  signed __int64 v46; // rdx
  hkpShape *v47; // rsi
  hkpShape *v48; // rdi
  __int64 v49; // rdx
  unsigned __int8 v50; // dl
  char v51; // bl
  hkpAgent3ProcessInput *v52; // rdi
  signed __int64 v53; // rax
  char v54; // bl
  unsigned int v55; // ebx
  char v56; // di
  __m128 *v57; // rbx
  __m128 *v58; // rbx
  __int64 v59; // rax
  hkpProcessCdPoint *v60; // rdi
  float v61; // xmm6_4
  __m128 *v62; // rcx
  __m128 v63; // xmm2
  __m128 v64; // xmm0
  __m128 v65; // xmm1
  hkpProcessCollisionInput *v66; // rax
  __m128 *v67; // rsi
  hkpCollisionQualityInfo *v68; // rcx
  __m128 *v69; // rbx
  __m128 v70; // xmm2
  __int64 v71; // rax
  hkpProcessCdPoint *v72; // rdi
  __m128 *v73; // rcx
  __m128 v74; // xmm2
  __m128 v75; // xmm0
  __m128 v76; // xmm1
  unsigned int v77; // ecx
  __int64 v78; // rax
  __int64 v79; // rdi
  unsigned int v80; // edx
  __m128 v81; // xmm3
  __m128 v82; // xmm2
  __m128 v83; // xmm2
  __m128 v84; // xmm1
  bool v85; // zf
  int v86; // esi
  __int64 v87; // rax
  __int64 v88; // rax
  float v89; // xmm0_4
  __m128 *v90; // rsi
  float v91; // xmm1_4
  __int64 v92; // rcx
  __m128 v93; // xmm0
  __m128 *v94; // rbx
  __m128 v95; // xmm2
  __int64 v96; // rax
  __int64 v97; // rdi
  unsigned int v98; // edx
  __m128 v99; // xmm3
  __m128 v100; // xmm2
  __m128 v101; // xmm2
  __m128 v102; // xmm1
  __int64 v103; // rax
  _QWORD **v104; // rax
  hkpAgent1nTrack *v105; // r11
  hkpAgent1nSector *v106; // rbx
  __int64 v107; // rax
  signed __int64 v108; // rdx
  __int64 v109; // rbx
  int v110; // er10
  signed int v111; // er10
  int v112; // er14
  __int64 v113; // rdi
  signed __int64 v114; // r9
  int v115; // ecx
  char *v116; // rax
  signed __int64 v117; // rdx
  __int128 v118; // xmm0
  hkpProcessCollisionOutput::PotentialInfo *v119; // r8
  unsigned __int64 j; // rcx
  signed __int64 v121; // rdx
  __int64 v122; // rcx
  int v123; // esi
  __int64 v124; // r14
  int v125; // ebx
  int v126; // eax
  int v127; // esi
  int v128; // eax
  int v129; // er9
  hkpAgent1nSector **v130; // rax
  signed __int64 v131; // rcx
  _QWORD **v132; // rax
  __m128 *v133; // rax
  signed int v134; // ecx
  char *v135; // rax
  __int128 v136; // xmm0
  hkpProcessCollisionOutput::PotentialInfo *v137; // r8
  unsigned __int64 i; // rcx
  __int64 v139; // rdx
  __int64 v140; // r9
  int v141; // er9
  int v142; // er14
  char *v143; // rax
  signed __int64 v144; // r8
  int v145; // ecx
  signed __int64 v146; // rdx
  __int128 v147; // xmm0
  hkpProcessCollisionOutput::PotentialInfo *v148; // rax
  hkpProcessCollisionOutput::ContactRef *v149; // rcx
  signed __int64 v150; // rdx
  __int64 v151; // r14
  int v152; // ebx
  int v153; // eax
  int v154; // eax
  int v155; // er9
  _QWORD *v156; // rax
  unsigned __int64 v157; // rcx
  signed __int64 v158; // rcx
  hkVector4f v159; // xmm0
  hkVector4f v160; // xmm1
  hkpProcessCollisionOutput::PotentialInfo *v161; // rcx
  hkVector4f v162; // xmm0
  hkVector4f v163; // xmm1
  __int64 v164[2]; // [rsp+30h] [rbp-D0h]
  char v165; // [rsp+40h] [rbp-C0h]
  int v166; // [rsp+44h] [rbp-BCh]
  hkPadSpu<unsigned char> cdBodyHasTransformFlag; // [rsp+48h] [rbp-B8h]
  bool v168; // [rsp+49h] [rbp-B7h]
  char v169; // [rsp+4Ah] [rbp-B6h]
  hkPadSpu<unsigned char> v170; // [rsp+4Bh] [rbp-B5h]
  __int64 v171; // [rsp+50h] [rbp-B0h]
  int v172; // [rsp+58h] [rbp-A8h]
  int v173; // [rsp+5Ch] [rbp-A4h]
  float v174; // [rsp+60h] [rbp-A0h]
  int v175; // [rsp+64h] [rbp-9Ch]
  __int64 v176; // [rsp+68h] [rbp-98h]
  __int64 v177; // [rsp+70h] [rbp-90h]
  unsigned int v178; // [rsp+78h] [rbp-88h]
  __int64 v179; // [rsp+80h] [rbp-80h]
  __int64 v180; // [rsp+88h] [rbp-78h]
  char *v181; // [rsp+90h] [rbp-70h]
  int v182; // [rsp+98h] [rbp-68h]
  hkpProcessCollisionOutput::PotentialInfo *v183; // [rsp+A0h] [rbp-60h]
  __int64 v184; // [rsp+A8h] [rbp-58h]
  hkResult result; // [rsp+B0h] [rbp-50h]
  hkpAgent1nSector *v186; // [rsp+B8h] [rbp-48h]
  hkpCdBody *cdBody[2]; // [rsp+C0h] [rbp-40h]
  __m128i v188; // [rsp+D0h] [rbp-30h]
  __int128 v189; // [rsp+E0h] [rbp-20h]
  hkTransformf v190; // [rsp+F0h] [rbp-10h]
  __int128 v191; // [rsp+130h] [rbp+30h]
  __m128 v192; // [rsp+140h] [rbp+40h]
  __int64 v193; // [rsp+150h] [rbp+50h]
  char v194; // [rsp+160h] [rbp+60h]
  char v195[512]; // [rsp+1E0h] [rbp+E0h]
  hkpShapeContainer *v196; // [rsp+3E0h] [rbp+2E0h]
  unsigned int *v197; // [rsp+3E8h] [rbp+2E8h]
  unsigned int v198; // [rsp+3F0h] [rbp+2F0h]
  hkpAgent3ProcessInput v199; // [rsp+400h] [rbp+300h]
  hkpAgent3Input v200; // [rsp+490h] [rbp+390h]
  hkpAgentNmMachineBodyTemp temp; // [rsp+500h] [rbp+400h]
  hkpAgent3Input v202; // [rsp+5C0h] [rbp+4C0h]
  hkpAgent3ProcessInput out; // [rsp+630h] [rbp+530h]
  hkpAgent3ProcessInput v204; // [rsp+6C0h] [rbp+5C0h]
  hkpCdBody newCdBodies; // [rsp+750h] [rbp+650h]
  hkpAgentNmMachineBodyTemp v206; // [rsp+7D0h] [rbp+6D0h]
  hkMotionState newMotionStates; // [rsp+890h] [rbp+790h]
  char *v208; // [rsp+B50h] [rbp+A50h]
  char *v209; // [rsp+B58h] [rbp+A58h]
  char v210; // [rsp+B60h] [rbp+A60h]
  char v211; // [rsp+1360h] [rbp+1260h]
  hkpAgent1nTrack *array; // [rsp+2BC0h] [rbp+2AC0h]
  hkpAgent3ProcessInput *v213; // [rsp+2BC8h] [rbp+2AC8h]
  hkpShapeContainer *shapeCollection; // [rsp+2BD0h] [rbp+2AD0h]
  const unsigned int *v215; // [rsp+2BD8h] [rbp+2AD8h]

  v215 = newKeys;
  shapeCollection = shapeContainerB;
  v213 = inputIn;
  array = agentTrack;
  _RAX = agentTrack->m_sectors.m_data;
  v6 = shapeContainerB;
  v7 = inputIn;
  v8 = agentTrack;
  __asm { prefetchnta byte ptr [rax]; Prefetch to L1 cache }
  v9 = output;
  v183 = output->m_potentialContacts.m_storage;
  if ( v183 || !shapeContainerB->vfptr->isWeldingEnabled(shapeContainerB) )
  {
    v9->m_potentialContacts.m_storage = 0i64;
  }
  else
  {
    v208 = &v211;
    v209 = &v210;
    v9->m_potentialContacts.m_storage = (hkpProcessCollisionOutput::PotentialInfo *)&v208;
  }
  v10 = *(_OWORD *)&v7->m_bodyA.m_storage;
  v11.m_quad = (__m128)v7->m_aTb.m_rotation.m_col0;
  v12 = *(__m128i *)&v7->m_overrideBodyA.m_storage;
  v13 = (__int64)v7->m_bodyB.m_storage;
  v14 = v215;
  v196 = v6;
  v197 = (unsigned int *)v215;
  v198 = -1;
  v166 = 0;
  *(_OWORD *)cdBody = v10;
  v15 = *(_OWORD *)&v7->m_contactMgr.m_storage;
  v190.m_rotation.m_col0 = (hkVector4f)v11.m_quad;
  v16.m_quad = (__m128)v7->m_aTb.m_rotation.m_col2;
  v189 = v15;
  v190.m_rotation.m_col1 = v7->m_aTb.m_rotation.m_col1;
  v17.m_quad = (__m128)v7->m_aTb.m_translation;
  v188 = v12;
  v18 = (__int64 *)*(_OWORD *)&_mm_srli_si128(v12, 8);
  v190.m_translation = (hkVector4f)v17.m_quad;
  v19 = v7->m_linearTimInfo.m_quad;
  v190.m_rotation.m_col2 = (hkVector4f)v16.m_quad;
  v20 = *(_OWORD *)&v7->m_distAtT1.m_storage;
  v192 = v19;
  v191 = v20;
  v21 = *v18;
  v180 = v13;
  v179 = *(_QWORD *)(v13 + 16);
  v171 = v21;
  cdBody[1] = (hkpCdBody *)&v177;
  _RBX = *v8->m_sectors.m_data;
  v186 = _RBX;
  __asm
  {
    prefetchnta byte ptr [rbx]; Prefetch to L1 cache
    prefetchnta byte ptr [rbx+40h]; Prefetch to L1 cache
    prefetchnta byte ptr [rbx+80h]; Prefetch to L1 cache
    prefetchnta byte ptr [rbx+0C0h]; Prefetch to L1 cache
  }
  v23 = (__m128 *)v18[15];
  if ( !v23 )
  {
    v24 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v25 = (__m128 *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v24[11] + 8i64))(v24[11], 512i64);
    v14 = v215;
    v23 = v25;
    if ( v25 )
      LODWORD(v25->m128_u64[0]) = 0;
    else
      v23 = 0i64;
    v18 = (__int64 *)v188.m128i_i64[1];
  }
  v18[15] = 0i64;
  v200.m_overrideBodyA.m_storage = 0i64;
  v202.m_overrideBodyA.m_storage = 0i64;
  v168 = 0;
  v165 = 0;
  v26 = 0;
  v27 = (signed __int64)&_RBX->m_data[_RBX->m_bytesAllocated];
  v175 = 0;
  v173 = 0;
  v184 = 0i64;
  v181 = (char *)&v23[32];
  LOBYTE(output) = 0;
  v172 = 1;
  v28 = (signed __int64)_RBX->m_data;
  v193 = v27;
  v29 = v23 + 1;
  v176 = 1i64;
  v30 = 5368709120i64;
  while ( 1 )
  {
    v31.m_quad = (__m128)v7->m_aTb.m_rotation.m_col0;
    v32.m_quad = (__m128)v7->m_aTb.m_rotation.m_col1;
    cdBody[1] = (hkpCdBody *)&v177;
    v190.m_rotation.m_col0 = (hkVector4f)v31.m_quad;
    v33.m_quad = (__m128)v7->m_aTb.m_rotation.m_col2;
    v190.m_rotation.m_col1 = (hkVector4f)v32.m_quad;
    v34.m_quad = (__m128)v7->m_aTb.m_translation;
    v190.m_rotation.m_col2 = (hkVector4f)v33.m_quad;
    v190.m_translation = (hkVector4f)v34.m_quad;
    if ( v14 )
    {
      v39 = v28;
      v40 = *v197;
      v198 = v40;
      v41 = *(_DWORD *)(v28 + 8);
      if ( v40 == v41 )
      {
        v42 = *(unsigned __int8 *)(v28 + 3);
        v43 = (__m128 *)v28;
        v44 = (signed int)*(unsigned __int8 *)(v28 + 3) >> 4;
        do
        {
          v45 = *v43;
          --v44;
          ++v43;
          *(__m128 *)((char *)v29 + (_QWORD)v43 - v28 - 16) = v45;
        }
        while ( v44 > 0 );
        v28 += v42;
        goto LABEL_37;
      }
      if ( v40 > v41 )
      {
        v46 = v28 + 32;
        if ( (*(_BYTE *)v28 & 6) != 4 )
          v46 = v28 + 16;
        v28 += *(unsigned __int8 *)(v28 + 3);
        (*(void (__fastcall **)(signed __int64, signed __int64, _QWORD, hkpConstraintOwner *, __int64))(112i64 * *(unsigned __int8 *)(v39 + 1) + v21 + 8184))(
          v39,
          v46,
          v189,
          v9->m_constraintOwner.m_storage,
          v21);
        goto LABEL_81;
      }
      LODWORD(v164[0]) = v40;
      (*(void (__fastcall **)(signed __int64, char *, __int64, hkpCdBody *, hkpCdBody *, hkpShapeContainer *, __int64))(*(_QWORD *)(*(_QWORD *)(v188.m128i_i64[1] + 24) + 24i64) + 8i64))(
        *(_QWORD *)(v188.m128i_i64[1] + 24) + 24i64,
        &v169,
        v188.m128i_i64[1],
        v7->m_bodyA.m_storage,
        v7->m_bodyB.m_storage,
        v196,
        v164[0]);
      if ( v169 )
      {
        if ( hkOutOfMemoryState == 1 )
        {
          ++v197;
LABEL_81:
          v86 = v166;
          goto $checkReadSector;
        }
        v177 = (__int64)v196->vfptr->getChildShape(v196, v198, (char (*)[512])v195);
        v178 = v198;
        v47 = cdBody[0]->m_shape;
        cdBodyHasTransformFlag.m_storage = 0;
        cdBody[1] = hkAgentMachine_processTransformedShapes(
                      cdBody[1],
                      &newCdBodies,
                      &newMotionStates,
                      4,
                      &cdBodyHasTransformFlag);
        v48 = cdBody[1]->m_shape;
        hkTransformf::setMulInverseMul(&v190, (hkTransformf *)cdBody[0]->m_motion, (hkTransformf *)cdBody[1]->m_motion);
        HIDWORD(v29->m128_u64[0]) = -1;
        LODWORD(v29->m128_u64[1]) = v40;
        v49 = (unsigned __int8)v47->m_type.m_storage;
        v21 = v171;
        if ( *(_DWORD *)(v188.m128i_i64[1] + 40) )
          v50 = *(_BYTE *)((unsigned __int8)v48->m_type.m_storage + v171 + 35i64 * (signed int)v49 + 6944);
        else
          v50 = *(_BYTE *)((unsigned __int8)v48->m_type.m_storage + v171 + 35 * v49 + 5712);
        BYTE1(v29->m128_u64[0]) = v50;
        BYTE2(v29->m128_u64[0]) = 0;
        out.m_overrideBodyA.m_storage = 0i64;
        v51 = 0;
        v52 = (hkpAgent3ProcessInput *)cdBody;
        if ( *(_DWORD *)(112i64 * v50 + v21 + 8272) == 2 )
        {
          v51 = 1;
          v52 = &out;
          hkAgent1nMachine_flipInput((hkpAgent3ProcessInput *)cdBody, &out);
        }
        v53 = BYTE1(v29->m128_u64[0]) + 73i64;
        if ( *(_QWORD *)(112i64 * BYTE1(v29->m128_u64[0]) + v21 + 8248) )
        {
          HIDWORD(v29->m128_u64[1]) = -1082130432;
          v54 = cdBodyHasTransformFlag.m_storage | (v51 + 4);
          v29[1] = 0i64;
          LOBYTE(v29->m128_u64[0]) = v54;
          BYTE3(v29->m128_u64[0]) = (unsigned __int64)(*(__int64 (__fastcall **)(hkpAgent3ProcessInput *, __m128 *, __m128 *))(112 * v53 + v21))(
                                                        v52,
                                                        v29,
                                                        v29 + 2)
                                  - (_BYTE)v29;
        }
        else
        {
          LOBYTE(v29->m128_u64[0]) = cdBodyHasTransformFlag.m_storage | (v51 + 2);
          BYTE3(v29->m128_u64[0]) = (unsigned __int64)(*(__int64 (__fastcall **)(hkpAgent3ProcessInput *, __m128 *, __m128 *))(112 * v53 + v21))(
                                                        v52,
                                                        v29,
                                                        v29 + 1)
                                  - (_BYTE)v29;
        }
      }
      else
      {
        LODWORD(v29->m128_u64[0]) = 0;
        HIDWORD(v29->m128_u64[0]) = -1;
        LODWORD(v29->m128_u64[1]) = v40;
        BYTE3(v29->m128_u64[0]) = 16;
      }
      v26 = (char)output;
      v30 = 5368709120i64;
LABEL_37:
      ++v197;
      goto LABEL_38;
    }
    v35 = *(unsigned __int8 *)(v28 + 3);
    v36 = (__m128 *)v28;
    v37 = (signed int)*(unsigned __int8 *)(v28 + 3) >> 4;
    do
    {
      v38 = *v36;
      --v37;
      ++v36;
      *(__m128 *)((char *)v29 + (_QWORD)v36 - v28 - 16) = v38;
    }
    while ( v37 > 0 );
    v28 += v35;
LABEL_38:
    v55 = LOBYTE(v29->m128_u64[0]);
    v56 = 0;
    while ( 2 )
    {
      switch ( v55 )
      {
        case 0u:
        case 1u:
          ++v29;
          goto LABEL_80;
        case 2u:
          v57 = v29;
          v177 = ((__int64 (__fastcall *)(hkpShapeContainer *, _QWORD, char *, signed __int64))v196->vfptr->getChildShape)(
                   v196,
                   v198,
                   v195,
                   5368709120i64);
          v178 = v198;
          v29 = (__m128 *)(*(__int64 (__fastcall **)(hkpCdBody **, __m128 *, __m128 *, _QWORD, hkpProcessCollisionOutput *))(112i64 * BYTE1(v29->m128_u64[0]) + v21 + 8256))(
                            cdBody,
                            v29,
                            v29 + 1,
                            0i64,
                            v9);
          BYTE3(v57->m128_u64[0]) = (_BYTE)v29 - (_BYTE)v57;
          goto LABEL_80;
        case 3u:
          v204.m_overrideBodyA.m_storage = 0i64;
          hkAgent1nMachine_flipInput((hkpAgent3ProcessInput *)cdBody, &v204);
          v58 = v29;
          v59 = (__int64)v196->vfptr->getChildShape(v196, v198, (char (*)[512])v195);
          v60 = v9->m_firstFreeContactPoint.m_storage;
          v61 = v9->m_toi.m_time.m_storage;
          v177 = v59;
          v178 = v198;
          v29 = (__m128 *)(*(__int64 (__fastcall **)(hkpAgent3ProcessInput *, __m128 *, __m128 *, _QWORD, hkpProcessCollisionOutput *))(112i64 * BYTE1(v29->m128_u64[0]) + v21 + 8256))(
                            &v204,
                            v29,
                            v29 + 1,
                            0i64,
                            v9);
          BYTE3(v58->m128_u64[0]) = (_BYTE)v29 - (_BYTE)v58;
          if ( v60 < v9->m_firstFreeContactPoint.m_storage )
          {
            v62 = &v60->m_contact.m_separatingNormal.m_quad;
            v63 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64);
            do
            {
              v64 = *v62;
              v62 += 3;
              v65 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v64, v64, 255), v64), v62[-4]);
              v62[-3] = _mm_xor_ps(v62[-3], v63);
              v62[-4] = v65;
            }
            while ( (hkpProcessCdPoint *)&v62[-1] < v9->m_firstFreeContactPoint.m_storage );
          }
          goto LABEL_47;
        case 4u:
          v88 = v188.m128i_i64[1];
          v89 = *((float *)&v29->m128_u64[1] + 1);
          v90 = v29;
          if ( v89 == *(float *)(v188.m128i_i64[1] + 96) || (v91 = *(float *)(v188.m128i_i64[1] + 100), v89 >= v91) )
          {
            v97 = v171;
          }
          else
          {
            v92 = *(_QWORD *)(v188.m128i_i64[1] + 112);
            if ( !*(_DWORD *)(v92 + 16) )
            {
              *((float *)&v29->m128_u64[1] + 1) = v91;
              v93 = (__m128)*(unsigned int *)(v92 + 24);
              v182 = 1036831949;
              v94 = v29 + 1;
              v95 = _mm_mul_ps(_mm_shuffle_ps((__m128)0x3DCCCCCDu, (__m128)0x3DCCCCCDu, 0), _mm_shuffle_ps(v93, v93, 0));
              v29[1] = _mm_shuffle_ps(aabbOut.m_quad, _mm_unpackhi_ps(aabbOut.m_quad, v95), 196);
$PROCESS_AT_T1_0:
              LODWORD(v191) = v95.m128_i32[0];
              v177 = ((__int64 (__fastcall *)(hkpShapeContainer *, _QWORD, char *, signed __int64))v196->vfptr->getChildShape)(
                       v196,
                       v198,
                       v195,
                       v30);
              v178 = v198;
              v29 = (__m128 *)(*(__int64 (__fastcall **)(hkpCdBody **, __m128 *, __m128 *, __m128 *, hkpProcessCollisionOutput *))(112i64 * BYTE1(v29->m128_u64[0]) + v171 + 8256))(
                                cdBody,
                                v29,
                                v29 + 2,
                                v94,
                                v9);
              BYTE3(v90->m128_u64[0]) = (_BYTE)v29 - (_BYTE)v90;
              goto LABEL_80;
            }
            if ( !v26 )
            {
              LOBYTE(output) = v56 == 0;
              hkAgent1nMachine_initInputAtTime((hkpAgent3Input *)cdBody, &v206, &v200);
            }
            v96 = ((__int64 (__fastcall *)(hkpShapeContainer *, _QWORD, char *, signed __int64))v196->vfptr->getChildShape)(
                    v196,
                    v198,
                    v195,
                    v30);
            v97 = v171;
            v177 = v96;
            v178 = v198;
            v98 = cdBody[1]->m_shapeKey;
            v206.m_bodyB.m_shape = cdBody[1]->m_shape;
            v206.m_bodyB.m_shapeKey = v98;
            (*(void (__fastcall **)(hkpAgent3Input *, __m128 *, __m128 *, __m128 *))(112i64 * BYTE1(v29->m128_u64[0])
                                                                                   + v171
                                                                                   + 8248))(
              &v200,
              v29,
              v29 + 2,
              v29 + 1);
            v88 = v188.m128i_i64[1];
          }
          v94 = v29 + 1;
          HIDWORD(v29->m128_u64[1]) = *(_DWORD *)(v88 + 100);
          v99 = v29[1];
          v100 = _mm_mul_ps(v192, v29[1]);
          v101 = _mm_shuffle_ps(v100, _mm_unpackhi_ps(v100, v192), 196);
          v102 = _mm_add_ps(_mm_shuffle_ps(v101, v101, 78), v101);
          v95 = _mm_sub_ps(_mm_shuffle_ps(v99, v99, 255), _mm_add_ps(_mm_shuffle_ps(v102, v102, 177), v102));
          v174 = *(float *)(v188.m128i_i64[1] + 16);
          if ( v95.m128_f32[0] < COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(v174), (__m128)LODWORD(v174), 0)) )
            goto $PROCESS_AT_T1_0;
          *v94 = _mm_shuffle_ps(v99, _mm_unpackhi_ps(v99, v95), 196);
          if ( BYTE2(v29->m128_u64[0]) )
          {
            v103 = (*(__int64 (__fastcall **)(__m128 *, __m128 *, _QWORD, hkpConstraintOwner *))(112i64
                                                                                               * BYTE1(v29->m128_u64[0])
                                                                                               + v97
                                                                                               + 0x2000))(
                     v29,
                     v29 + 2,
                     v189,
                     v9->m_constraintOwner.m_storage);
            v7 = v213;
            v29 = (__m128 *)v103;
            BYTE3(v90->m128_u64[0]) = v103 - (_BYTE)v90;
          }
          else
          {
            v7 = v213;
            v29 = (__m128 *)((char *)v29 + BYTE3(v29->m128_u64[0]));
          }
          v86 = v166++ + 1;
          break;
        case 5u:
          v199.m_overrideBodyA.m_storage = 0i64;
          hkAgent1nMachine_flipInput((hkpAgent3ProcessInput *)cdBody, &v199);
          v66 = v199.m_input.m_storage;
          v67 = v29;
          if ( v199.m_input.m_storage->m_stepInfo.m_startTime.m_storage == *((float *)&v29->m128_u64[1] + 1) )
          {
            v79 = v171;
          }
          else
          {
            v68 = v199.m_input.m_storage->m_collisionQualityInfo.m_storage;
            if ( !v68->m_useContinuousPhysics.m_storage )
            {
              v69 = v29 + 1;
              HIDWORD(v29->m128_u64[1]) = LODWORD(v199.m_input.m_storage->m_stepInfo.m_endTime.m_storage);
              v70 = _mm_mul_ps(
                      _mm_shuffle_ps((__m128)LODWORD(v68->m_minSeparation), (__m128)LODWORD(v68->m_minSeparation), 0),
                      (__m128)xmmword_141A711B0);
              v29[1] = _mm_shuffle_ps(aabbOut.m_quad, _mm_unpackhi_ps(aabbOut.m_quad, v70), 196);
              goto $PROCESS_AT_T1_FLIPPED;
            }
            if ( !v168 )
            {
              v168 = v56 == 0;
              hkAgent1nMachine_initInputAtTime((hkpAgent3Input *)&v199.m_bodyA, &temp, &v202);
              v77 = v199.m_bodyB.m_storage->m_shapeKey;
              temp.m_bodyB.m_shape = v199.m_bodyB.m_storage->m_shape;
              temp.m_bodyB.m_shapeKey = v77;
            }
            v78 = (__int64)v196->vfptr->getChildShape(v196, v198, (char (*)[512])v195);
            v79 = v171;
            v177 = v78;
            v178 = v198;
            v80 = cdBody[1]->m_shapeKey;
            temp.m_bodyA.m_shape = cdBody[1]->m_shape;
            temp.m_bodyA.m_shapeKey = v80;
            (*(void (__fastcall **)(hkpAgent3Input *, __m128 *, __m128 *, __m128 *))(112i64 * BYTE1(v29->m128_u64[0])
                                                                                   + v171
                                                                                   + 8248))(
              &v202,
              v29,
              v29 + 2,
              v29 + 1);
            v66 = v199.m_input.m_storage;
          }
          v81 = v29[1];
          v69 = v29 + 1;
          HIDWORD(v29->m128_u64[1]) = LODWORD(v66->m_stepInfo.m_endTime.m_storage);
          v82 = _mm_mul_ps(v81, v199.m_linearTimInfo.m_quad);
          v83 = _mm_shuffle_ps(v82, _mm_unpackhi_ps(v82, v199.m_linearTimInfo.m_quad), 196);
          v84 = _mm_add_ps(_mm_shuffle_ps(v83, v83, 78), v83);
          v70 = _mm_sub_ps(_mm_shuffle_ps(v81, v81, 255), _mm_add_ps(_mm_shuffle_ps(v84, v84, 177), v84));
          v174 = v199.m_input.m_storage->m_tolerance.m_storage;
          if ( v70.m128_f32[0] >= COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(v174), (__m128)LODWORD(v174), 0)) )
          {
            v85 = BYTE2(v29->m128_u64[0]) == 0;
            *v69 = _mm_shuffle_ps(v81, _mm_unpackhi_ps(v81, v70), 196);
            if ( v85 )
            {
              v7 = v213;
              v29 = (__m128 *)((char *)v29 + BYTE3(v29->m128_u64[0]));
            }
            else
            {
              v87 = (*(__int64 (__fastcall **)(__m128 *, __m128 *, hkpContactMgr *, hkpConstraintOwner *))(112i64 * BYTE1(v29->m128_u64[0]) + v79 + 0x2000))(
                      v29,
                      v29 + 2,
                      v199.m_contactMgr.m_storage,
                      v9->m_constraintOwner.m_storage);
              v7 = v213;
              v29 = (__m128 *)v87;
              BYTE3(v67->m128_u64[0]) = v87 - (_BYTE)v67;
            }
            v86 = v166++ + 1;
            break;
          }
$PROCESS_AT_T1_FLIPPED:
          LODWORD(v199.m_distAtT1.m_storage) = v70.m128_i32[0];
          v71 = (__int64)v196->vfptr->getChildShape(v196, v198, (char (*)[512])v195);
          v72 = v9->m_firstFreeContactPoint.m_storage;
          v61 = v9->m_toi.m_time.m_storage;
          v177 = v71;
          v178 = v198;
          v29 = (__m128 *)(*(__int64 (__fastcall **)(hkpAgent3ProcessInput *, __m128 *, __m128 *, __m128 *, hkpProcessCollisionOutput *))(112i64 * BYTE1(v29->m128_u64[0]) + v171 + 8256))(
                            &v199,
                            v29,
                            v29 + 2,
                            v69,
                            v9);
          BYTE3(v67->m128_u64[0]) = (_BYTE)v29 - (_BYTE)v67;
          if ( v72 < v9->m_firstFreeContactPoint.m_storage )
          {
            v73 = &v72->m_contact.m_separatingNormal.m_quad;
            v74 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64);
            do
            {
              v75 = *v73;
              v73 += 3;
              v76 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v75, v75, 255), v75), v73[-4]);
              v73[-3] = _mm_xor_ps(v74, v73[-3]);
              v73[-4] = v76;
            }
            while ( (hkpProcessCdPoint *)&v73[-1] < v9->m_firstFreeContactPoint.m_storage );
          }
LABEL_47:
          if ( v61 != v9->m_toi.m_time.m_storage )
            hkpProcessCollisionData::ToiInfo::flip(&v9->m_toi);
LABEL_80:
          v7 = v213;
          goto LABEL_81;
        case 6u:
          v177 = ((__int64 (__fastcall *)(hkpShapeContainer *, _QWORD, char *, signed __int64))v196->vfptr->getChildShape)(
                   v196,
                   v198,
                   v195,
                   5368709120i64);
          v178 = v198;
          (*(void (__fastcall **)(unsigned __int64, hkpCdBody *, hkpCdBody *, __int64, hkpProcessCollisionOutput *))(*(_QWORD *)v29[1].m128_u64[0] + 48i64))(
            v29[1].m128_u64[0],
            cdBody[0],
            cdBody[1],
            v188.m128i_i64[1],
            v9);
          v29 += 2;
          goto LABEL_80;
        case 0xAu:
        case 0xBu:
        case 0xCu:
        case 0xDu:
        case 0xEu:
          v177 = ((__int64 (__fastcall *)(hkpShapeContainer *, _QWORD, char *, signed __int64))v196->vfptr->getChildShape)(
                   v196,
                   v198,
                   v195,
                   5368709120i64);
          v178 = v198;
          v170.m_storage = 0;
          cdBody[1] = hkAgentMachine_processTransformedShapes(cdBody[1], &newCdBodies, &newMotionStates, 4, &v170);
          hkTransformf::setMulInverseMul(
            &v190,
            (hkTransformf *)cdBody[0]->m_motion,
            (hkTransformf *)cdBody[1]->m_motion);
          v26 = 0;
          v55 &= 0xF7u;
          v56 = 1;
          v168 = 0;
          LOBYTE(output) = 0;
          v30 = 5368709120i64;
          if ( v55 <= 0xE )
            continue;
          goto LABEL_80;
        default:
          goto LABEL_80;
      }
      break;
    }
$checkReadSector:
    if ( v28 != v193 )
    {
      v105 = array;
      v109 = v176;
      goto LABEL_89;
    }
    if ( *(_QWORD *)(v188.m128i_i64[1] + 120) )
    {
      v104 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, hkpAgent1nSector *, signed __int64))(*v104[11] + 16i64))(v104[11], v186, 512i64);
    }
    else
    {
      *(_QWORD *)(v188.m128i_i64[1] + 120) = v186;
    }
    v105 = array;
    if ( v172 >= array->m_sectors.m_size )
      break;
    v106 = array->m_sectors.m_data[v176];
    ++v172;
    v107 = v106->m_bytesAllocated;
    v28 = (signed __int64)v106->m_data;
    v186 = v106;
    v108 = (signed __int64)&v106->m_data[v107];
    v109 = v176 + 1;
    v193 = v108;
    ++v176;
LABEL_89:
    v21 = v171;
    v14 = v215;
    v26 = (char)output;
    v30 = 5368709120i64;
    if ( &v29[8] > (__m128 *)v181 )
    {
      if ( !v165 )
      {
        v165 = 1;
        v110 = (_DWORD)v29 - (_DWORD)v23;
        v29 = (__m128 *)&v194;
        v181 = v195;
        v173 = v110 - 16;
        goto LABEL_127;
      }
      v111 = v173;
      v112 = (_DWORD)v29 - (unsigned __int64)(&v190.m_rotation.m_col1 + 6);
      v113 = v112;
      if ( v112 > 496 - v173 )
      {
LABEL_104:
        v122 = v184;
        LODWORD(v23->m128_u64[0]) = v111;
        if ( v122 >= v109 )
        {
          v123 = v105->m_sectors.m_size;
          v124 = v172;
          v125 = v123 + 1;
          v126 = v105->m_sectors.m_capacityAndFlags & 0x3FFFFFFF;
          v127 = v123 - v172;
          if ( v125 > v126 )
          {
            if ( v126 >= v125 )
            {
              result.m_enum = 0;
            }
            else
            {
              v128 = 2 * v126;
              v129 = v125;
              if ( v125 < v128 )
                v129 = v128;
              hkArrayUtil::_reserve(
                &result,
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                v105,
                v129,
                8);
              v105 = array;
            }
          }
          hkMemUtil::memMove(&v105->m_sectors.m_data[v124 + 1], &v105->m_sectors.m_data[v124], 8 * v127);
          v105 = array;
          v122 = v184;
          ++v176;
          array->m_sectors.m_size = v125;
          v172 = v124 + 1;
        }
        v130 = v105->m_sectors.m_data;
        ++v175;
        v131 = v122 + 1;
        v130[v131 - 1] = (hkpAgent1nSector *)v23;
        v184 = v131;
        v23 = *(__m128 **)(v188.m128i_i64[1] + 120);
        if ( !v23 )
        {
          v132 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v133 = (__m128 *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v132[11] + 8i64))(v132[11], 512i64);
          v23 = v133;
          if ( v133 )
            LODWORD(v133->m128_u64[0]) = 0;
          else
            v23 = 0i64;
        }
        v21 = v171;
        v14 = v215;
        v26 = (char)output;
        *(_QWORD *)(v188.m128i_i64[1] + 120) = 0i64;
        v29 = v23 + 1;
        v30 = 5368709120i64;
        v181 = (char *)&v23[32];
        if ( v165 )
        {
          v134 = (signed int)v113 >> 4;
          v135 = &v194;
          do
          {
            v136 = *(_OWORD *)v135;
            --v134;
            v135 += 16;
            *(_OWORD *)&v135[(char *)v23 - &v194] = v136;
          }
          while ( v134 > 0 );
          v137 = v9->m_potentialContacts.m_storage;
          if ( v137 )
          {
            for ( i = (unsigned __int64)v137->m_potentialContacts;
                  (hkpProcessCollisionOutput::ContactRef *)i < v137->m_firstFreePotentialContact;
                  i += 24i64 )
            {
              v139 = *(_QWORD *)(i + 8) - (_QWORD)&v194;
              if ( v139 >= 0 && v139 < v113 )
              {
                *(_QWORD *)(i + 8) = (char *)v29 + v139;
                *(_QWORD *)(i + 16) += (char *)v29 - &v194;
              }
            }
          }
          v29 = (__m128 *)((char *)v29 + v113);
          v165 = 0;
          goto LABEL_126;
        }
        v7 = v213;
      }
      else
      {
        v114 = (signed __int64)&v23[1] + v173;
        v115 = v112 >> 4;
        v116 = &v194;
        v117 = (char *)&v23[1] + v173 - &v194;
        do
        {
          v118 = *(_OWORD *)v116;
          --v115;
          v116 += 16;
          *(_OWORD *)&v116[v117 - 16] = v118;
        }
        while ( v115 > 0 );
        v119 = v9->m_potentialContacts.m_storage;
        v111 += v112;
        v173 = v111;
        if ( v119 )
        {
          for ( j = (unsigned __int64)v119->m_potentialContacts;
                (hkpProcessCollisionOutput::ContactRef *)j < v119->m_firstFreePotentialContact;
                j += 24i64 )
          {
            v121 = *(_QWORD *)(j + 8) - (_QWORD)&v194;
            if ( v121 >= 0 && v121 < v112 )
            {
              *(_QWORD *)(j + 8) = v114 + v121;
              *(_QWORD *)(j + 16) += v114 - (_QWORD)&v194;
            }
          }
        }
        if ( v111 >= 496 )
        {
          v165 = 0;
          goto LABEL_104;
        }
        v29 = (__m128 *)&v194;
LABEL_126:
        v7 = v213;
LABEL_127:
        v14 = v215;
        v26 = (char)output;
        v30 = 5368709120i64;
      }
    }
  }
  if ( v165 )
  {
    v141 = v173;
    v142 = (_DWORD)v29 - (unsigned __int64)(&v190.m_rotation.m_col1 + 6);
    v143 = &v194;
    v144 = (signed __int64)&v23[1] + v173;
    v145 = v142 >> 4;
    v146 = (char *)&v23[1] + v173 - &v194;
    do
    {
      v147 = *(_OWORD *)v143;
      --v145;
      v143 += 16;
      *(_OWORD *)&v143[v146 - 16] = v147;
    }
    while ( v145 > 0 );
    v148 = v9->m_potentialContacts.m_storage;
    if ( v148 )
    {
      v149 = v148->m_firstFreePotentialContact;
      if ( v148->m_firstFreePotentialContact > v148->m_potentialContacts )
      {
        v150 = (char *)v149[-1].m_agentEntry - &v194;
        if ( v150 >= 0 && v150 < v142 )
        {
          v149[-1].m_agentEntry = (hkpAgentEntry *)(v150 + v144);
          v149[-1].m_agentData = (char *)v149[-1].m_agentData + v144 - (_QWORD)&v194;
        }
      }
    }
    v140 = (unsigned int)(v142 + v141);
  }
  else
  {
    v140 = (unsigned int)((_DWORD)v29 - (_DWORD)v23 - 16);
  }
  v151 = v175;
  LODWORD(v23->m128_u64[0]) = v140;
  v152 = v151 + 1;
  v153 = array->m_sectors.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v153 < (signed int)v151 + 1 )
  {
    v154 = 2 * v153;
    v155 = v151 + 1;
    if ( v152 < v154 )
      v155 = v154;
    hkArrayUtil::_reserve(
      (hkResult *)&v213,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      array,
      v155,
      8);
    v105 = array;
  }
  v105->m_sectors.m_size = v152;
  v105->m_sectors.m_data[v151] = (hkpAgent1nSector *)v23;
  if ( v86 )
  {
    v156 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v157 = v156[1];
    if ( v157 < v156[3] )
    {
      v158 = v157 + 16;
      *(_QWORD *)(v158 - 16) = "MinumTim";
      *(float *)(v158 - 8) = (float)v86;
      v156[1] = v158;
    }
  }
  v159.m_quad = (__m128)v7->m_aTb.m_rotation.m_col0;
  v160.m_quad = (__m128)v7->m_aTb.m_rotation.m_col1;
  v161 = v9->m_potentialContacts.m_storage;
  cdBody[1] = v7->m_bodyB.m_storage;
  v190.m_rotation.m_col0 = (hkVector4f)v159.m_quad;
  v162.m_quad = (__m128)v7->m_aTb.m_rotation.m_col2;
  v190.m_rotation.m_col1 = (hkVector4f)v160.m_quad;
  v163.m_quad = (__m128)v7->m_aTb.m_translation;
  v190.m_rotation.m_col2 = (hkVector4f)v162.m_quad;
  v190.m_translation = (hkVector4f)v163.m_quad;
  if ( v161 && v161->m_firstFreePotentialContact > v161->m_potentialContacts )
    hkAgent1nMachine_Weld((hkpAgent3Input *)cdBody, shapeCollection, v9, v140);
  v9->m_potentialContacts.m_storage = v183;
}hkAgent1nMachine_Weld((hkpAgent3Input *)cdBody, shapeCollection, v9, v140);
  v9->m_potentialContacts.m_storage = v183;
}

// File Line: 935
// RVA: 0xD3EB20
hkpAgent1nMachineEntry *__fastcall hkAgentNmMachine_UpdateShapeCollectionFilterVisitor(hkpAgent1nMachine_VisitorInput *vin, hkpAgent1nMachineEntry *entry, void *agentData)
{
  hkpShapeKeyPair v3; // rbx
  hkpAgent1nMachine_VisitorInput *v4; // r14
  void *v5; // r13
  hkpCollisionInput *v6; // r8
  hkpCdBody *v7; // r9
  hkpAgent1nMachineEntry *v8; // r15
  hkpCollisionFilter *v9; // rcx
  hkpShapeCollectionFilterVtbl *v10; // r10
  unsigned int v11; // ST40_4
  unsigned int v12; // ST38_4
  hkpShapeContainer *v13; // ST30_8
  hkpShapeContainer *v14; // rax
  bool v15; // zf
  hkpCollisionInput *v16; // rax
  void (__fastcall *v17)(hkpAgentEntry *, void *, hkpCdBody *, hkpCdBody *, hkpCollisionInput *, hkpContactMgr *, hkpConstraintOwner *); // r12
  unsigned int v18; // esi
  hkpShape *v19; // rdi
  hkpShape *v20; // rax
  hkpCdBody *v21; // rcx
  hkpCdBody *v22; // rdx
  const void *v23; // rcx
  hkpCdBody *v24; // rcx
  const void *v25; // rcx
  hkpCdBody *v26; // rbx
  hkpContactMgr *v27; // rax
  hkpAgent1nMachineEntry *result; // rax
  hkpCdBody cdBody; // [rsp+50h] [rbp-B0h]
  hkpCdBody v30; // [rsp+70h] [rbp-90h]
  hkpCdBody v31; // [rsp+90h] [rbp-70h]
  hkpCdBody newCdBodies; // [rsp+110h] [rbp+10h]
  char v33; // [rsp+190h] [rbp+90h]
  hkMotionState newMotionStates; // [rsp+390h] [rbp+290h]
  char v35; // [rsp+650h] [rbp+550h]
  hkMotionState v36; // [rsp+850h] [rbp+750h]
  hkPadSpu<unsigned char> cdBodyHasTransformFlag; // [rsp+B50h] [rbp+A50h]
  hkpShapeKeyPair v38; // [rsp+B58h] [rbp+A58h]

  v3 = entry->m_shapeKeyPair;
  v4 = vin;
  v5 = agentData;
  v6 = vin->m_input;
  v7 = vin->m_bodyA;
  v8 = entry;
  v9 = v6->m_filter.m_storage;
  v10 = v9->vfptr;
  v13 = v4->m_containerShapeB;
  v14 = v4->m_containerShapeA;
  v38 = entry->m_shapeKeyPair;
  v11 = v38.m_shapeKeyB;
  v12 = v38.m_shapeKeyA;
  v15 = *(_BYTE *)v10->isCollisionEnabled(
                    (hkpShapeCollectionFilter *)&v9->vfptr,
                    (hkBool *)&cdBodyHasTransformFlag,
                    v6,
                    v7,
                    v4->m_collectionBodyB,
                    v14,
                    v13,
                    v12,
                    v11) == 0;
  v16 = v4->m_input;
  if ( v15 )
  {
    v16->m_dispatcher.m_storage->m_agent3Func[(unsigned __int8)v8->m_agentType].m_destroyFunc(
      (hkpAgentEntry *)&v8->m_streamCommand,
      v5,
      v4->m_contactMgr,
      v4->m_constraintOwner,
      v16->m_dispatcher.m_storage);
    result = v8;
  }
  else
  {
    v17 = v16->m_dispatcher.m_storage->m_agent3Func[(unsigned __int8)v8->m_agentType].m_updateFilterFunc;
    if ( v17 )
    {
      v18 = v38.m_shapeKeyB;
      v19 = v4->m_containerShapeB->vfptr->getChildShape(v4->m_containerShapeB, v38.m_shapeKeyB, (char (*)[512])&v35);
      v20 = v4->m_containerShapeA->vfptr->getChildShape(v4->m_containerShapeA, v3.m_shapeKeyA, (char (*)[512])&v33);
      v15 = (v8->m_streamCommand & 8) == 0;
      v21 = v4->m_collectionBodyB;
      v22 = &v30;
      cdBody.m_parent = v21;
      v23 = v21->m_motion;
      cdBody.m_shape = v19;
      cdBody.m_motion = v23;
      v24 = v4->m_bodyA;
      cdBody.m_shapeKey = v18;
      v30.m_parent = v24;
      v25 = v24->m_motion;
      v30.m_shapeKey = v3.m_shapeKeyA;
      v30.m_shape = v20;
      v30.m_motion = v25;
      v26 = &cdBody;
      if ( !v15 )
      {
        cdBodyHasTransformFlag.m_storage = 0;
        v26 = hkAgentMachine_processTransformedShapes(
                &cdBody,
                &newCdBodies,
                &newMotionStates,
                4,
                &cdBodyHasTransformFlag);
        v22 = hkAgentMachine_processTransformedShapes(&v30, &v31, &v36, 4, &cdBodyHasTransformFlag);
      }
      if ( ((v8->m_streamCommand & 7) - 3) & 0xFD )
      {
        v17((hkpAgentEntry *)&v8->m_streamCommand, v5, v22, v26, v4->m_input, v4->m_contactMgr, v4->m_constraintOwner);
      }
      else
      {
        v27 = v4->m_contactMgr;
        v17((hkpAgentEntry *)&v8->m_streamCommand, v5, v26, v22, v4->m_input, v4->m_contactMgr, v4->m_constraintOwner);
      }
    }
    result = (hkpAgent1nMachineEntry *)((char *)v8 + (unsigned __int8)v8->m_size);
  }
  return result;
}

