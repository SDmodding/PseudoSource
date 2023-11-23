// File Line: 73
// RVA: 0xDB8930
void __fastcall setRatio(hkVector4f *a, hkVector4f *b, hkVector4f *ratio, hkVector4f *oneMinusRatio)
{
  __m128 v4; // xmm1
  __m128 v5; // xmm2
  __m128 v6; // xmm3

  v4 = _mm_sub_ps(a->m_quad, b->m_quad);
  v5 = _mm_rcp_ps(v4);
  v6 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v5, v4)), v5);
  ratio->m_quad = _mm_mul_ps(a->m_quad, v6);
  oneMinusRatio->m_quad = _mm_xor_ps(
                            (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                            _mm_mul_ps(b->m_quad, v6));
}

// File Line: 86
// RVA: 0xDB8980
void __fastcall setBundleInterpolateWithMasks(
        RayPointBundle *inStart,
        RayPointBundle *inEnd,
        RayPointBundle *outStart,
        RayPointBundle *outEnd,
        hkVector4f *t,
        hkVector4f *oneMinusT,
        hkVector4fComparison *end0Mask,
        hkVector4fComparison *end1Mask)
{
  __m128 v8; // xmm2
  __m128 v9; // xmm2
  __m128 v10; // xmm2

  v8 = _mm_add_ps(
         _mm_mul_ps(inEnd->m_vec[0].m_quad, t->m_quad),
         _mm_mul_ps(oneMinusT->m_quad, inStart->m_vec[0].m_quad));
  outStart->m_vec[0].m_quad = _mm_or_ps(
                                _mm_andnot_ps(end0Mask->m_mask, outStart->m_vec[0].m_quad),
                                _mm_and_ps(end0Mask->m_mask, v8));
  outEnd->m_vec[0].m_quad = _mm_or_ps(
                              _mm_andnot_ps(end1Mask->m_mask, outEnd->m_vec[0].m_quad),
                              _mm_and_ps(end1Mask->m_mask, v8));
  v9 = _mm_add_ps(
         _mm_mul_ps(inStart->m_vec[1].m_quad, oneMinusT->m_quad),
         _mm_mul_ps(inEnd->m_vec[1].m_quad, t->m_quad));
  outStart->m_vec[1].m_quad = _mm_or_ps(
                                _mm_and_ps(end0Mask->m_mask, v9),
                                _mm_andnot_ps(end0Mask->m_mask, outStart->m_vec[1].m_quad));
  outEnd->m_vec[1].m_quad = _mm_or_ps(
                              _mm_andnot_ps(end1Mask->m_mask, outEnd->m_vec[1].m_quad),
                              _mm_and_ps(end1Mask->m_mask, v9));
  v10 = _mm_add_ps(
          _mm_mul_ps(inStart->m_vec[2].m_quad, oneMinusT->m_quad),
          _mm_mul_ps(inEnd->m_vec[2].m_quad, t->m_quad));
  outStart->m_vec[2].m_quad = _mm_or_ps(
                                _mm_andnot_ps(end0Mask->m_mask, outStart->m_vec[2].m_quad),
                                _mm_and_ps(end0Mask->m_mask, v10));
  outEnd->m_vec[2].m_quad = _mm_or_ps(
                              _mm_and_ps(end1Mask->m_mask, v10),
                              _mm_andnot_ps(end1Mask->m_mask, outEnd->m_vec[2].m_quad));
}

// File Line: 115
// RVA: 0xDB8A70
__int64 __fastcall shouldDoLeftBranchFirst(hkVector4f *la, hkVector4f *lb, hkVector4fComparison *activeMask)
{
  __int64 result; // rax
  __m128 v4; // xmm1
  __m128 v5; // xmm3
  __m128 v6; // xmm1
  __m128 v7; // xmm0
  __m128 v8; // xmm2

  result = 0i64;
  v4 = _mm_and_ps(_mm_cmplt_ps(la->m_quad, lb->m_quad), activeMask->m_mask);
  v5 = _mm_or_ps(_mm_andnot_ps(activeMask->m_mask, (__m128)0i64), _mm_and_ps(activeMask->m_mask, query.m_quad));
  v6 = _mm_or_ps(_mm_andnot_ps(v4, (__m128)0i64), _mm_and_ps(v4, query.m_quad));
  v7 = _mm_add_ps(_mm_shuffle_ps(v6, v6, 78), v6);
  v8 = _mm_add_ps(_mm_shuffle_ps(v5, v5, 78), v5);
  v6.m128_f32[0] = _mm_shuffle_ps(v7, v7, 177).m128_f32[0] + v7.m128_f32[0];
  if ( (float)(v6.m128_f32[0] + v6.m128_f32[0]) >= (float)(_mm_shuffle_ps(v8, v8, 177).m128_f32[0] + v8.m128_f32[0]) )
    return 1i64;
  return result;
}

// File Line: 132
// RVA: 0xDB8AF0
hkVector4fComparison *__fastcall getDifferentSignMask(hkVector4fComparison *result, hkVector4f *a, hkVector4f *b)
{
  hkVector4fComparison *v3; // rax

  v3 = result;
  result->m_mask = _mm_cmplt_ps(_mm_mul_ps(a->m_quad, b->m_quad), (__m128)0i64);
  return v3;
}

// File Line: 156
// RVA: 0xDB8B10
_BOOL8 __fastcall allMaskedAreSet(hkVector4fComparison *v, const __m128i *mask)
{
  return _mm_movemask_ps(_mm_or_ps((__m128)_mm_cmpeq_epi32(_mm_load_si128(mask), (__m128i)0i64), v->m_mask)) == 15;
}

// File Line: 294
// RVA: 0xDB7500
void __fastcall hkpMoppRayBundleVirtualMachine::queryRayOnTree(
        hkpMoppRayBundleVirtualMachine *this,
        hkpMoppRayBundleVirtualMachine::QueryInt *query,
        hkpMoppRayBundleVirtualMachine::QueryBundle *PC,
        hkpMoppRayBundleVirtualMachine::QueryBundle *const fQuery,
        int chunkId)
{
  hkpMoppRayBundleVirtualMachine::QueryInt *p_m_quad; // r10
  hkpMoppRayBundleVirtualMachine *v8; // r11
  int v9; // r8d
  int v10; // ecx
  __m128 v11; // xmm7
  int v12; // edx
  int v13; // esi
  __m128 v14; // xmm3
  __m128 v15; // xmm4
  __m128 v16; // xmm5
  __m128 v17; // xmm5
  __m128 v18; // xmm0
  __m128 v19; // xmm0
  __m128 v20; // xmm1
  __m128 v21; // xmm2
  __m128 v22; // xmm0
  __m128 v23; // xmm2
  __m128 v24; // xmm0
  __m128 v25; // xmm2
  __m128 v26; // xmm0
  __m128 v27; // xmm2
  __m128 v28; // xmm0
  __m128 v29; // xmm2
  __m128 v30; // xmm5
  __m128 v31; // xmm3
  __m128 v32; // xmm3
  __m128 v33; // xmm1
  __m128 v34; // xmm2
  __m128 v35; // xmm0
  __m128 v36; // xmm1
  __m128 v37; // xmm2
  __m128 v38; // xmm0
  __m128 v39; // xmm1
  __m128 v40; // xmm2
  __m128 v41; // xmm0
  __m128 v42; // xmm1
  __m128 v43; // xmm2
  __m128 v44; // xmm0
  hkpMoppRayBundleVirtualMachine::QueryBundle *v45; // rdi
  __int64 v46; // rcx
  __m128 v47; // xmm2
  __m128 v48; // xmm3
  __m128 v49; // xmm4
  int v50; // esi
  int v51; // ecx
  hkVector4fComparison v52; // xmm11
  __m128i v53; // xmm5
  __m128i v54; // xmm7
  __m128 v55; // xmm10
  __m128 v56; // xmm9
  __m128 v57; // xmm10
  __m128 v58; // xmm12
  __m128 v59; // xmm13
  __m128 v60; // xmm14
  __m128 v61; // xmm15
  __m128 v62; // xmm1
  __m128 v63; // xmm7
  __m128 v64; // xmm2
  __m128 v65; // xmm0
  __m128i v66; // xmm11
  __m128 v67; // xmm6
  __m128 v68; // xmm5
  __m128 v69; // xmm7
  __m128 v70; // xmm3
  __m128 v71; // xmm4
  __m128 v72; // xmm6
  __m128 v73; // xmm2
  __m128 v74; // xmm2
  __m128 v75; // xmm0
  __m128 v76; // xmm1
  __m128 v77; // xmm0
  __m128 v78; // xmm2
  __m128 v79; // xmm8
  __m128 v80; // xmm4
  __m128 v81; // xmm8
  __m128i v82; // xmm3
  __m128 v83; // xmm5
  __m128 v84; // xmm3
  __m128 v85; // xmm0
  __m128 v86; // xmm0
  __m128 v87; // xmm0
  hkpMoppRayBundleVirtualMachine::QueryBundle *p_fQuerya; // r9
  int v89; // edx
  __m128 v90; // xmm11
  __m128 v91; // xmm0
  __m128 v92; // xmm1
  __m128 v93; // xmm2
  __m128 v94; // xmm0
  __m128 v95; // xmm5
  __m128 v96; // xmm6
  hkVector4f v97; // xmm3
  hkpMoppRayBundleVirtualMachine::QueryBundle *v98; // rcx
  hkpMoppCode *m_code; // rax
  __m128 v100; // xmm4
  __m128 v101; // xmm7
  __m128 v102; // xmm0
  __m128 v103; // xmm2
  __m128 v104; // xmm0
  __m128 v105; // xmm1
  __int64 v106; // rax
  __m128 v107; // xmm0
  __m128 v108; // xmm2
  int v109; // ecx
  int v110; // ecx
  __int64 v111; // rax
  __m128 v112; // xmm3
  __m128 v113; // xmm0
  int v114; // eax
  __m128 v115; // xmm0
  __m128 v116; // xmm1
  __m128 v117; // xmm2
  __m128 v118; // xmm3
  __m128 v119; // xmm5
  __m128 v120; // xmm6
  __m128 v121; // xmm7
  __m128 v122; // xmm2
  hkVector4fComparison v123; // xmm1
  __m128 v124; // xmm13
  __m128 v125; // xmm10
  __m128 v126; // xmm15
  __m128 v127; // xmm12
  __m128 v128; // xmm14
  __m128 v129; // xmm8
  __m128 v130; // xmm3
  __m128 v131; // xmm4
  __m128 v132; // xmm1
  __m128 v133; // xmm2
  __m128 v134; // xmm7
  __m128 v135; // xmm5
  __m128 v136; // xmm6
  __m128 v137; // xmm4
  __m128 v138; // xmm7
  __m128 v139; // xmm5
  __m128 v140; // xmm6
  __m128 v141; // xmm2
  __m128 v142; // xmm3
  __m128 v143; // xmm1
  __m128 v144; // xmm0
  __m128 v145; // xmm1
  __m128 v146; // xmm0
  __m128 v147; // xmm4
  __m128 v148; // xmm4
  __m128 v149; // xmm5
  __m128 v150; // xmm1
  __m128 v151; // xmm0
  __m128 v152; // xmm2
  __m128 v153; // xmm3
  __m128 v154; // xmm11
  __m128 v155; // xmm3
  __m128 v156; // xmm5
  __m128 v157; // xmm11
  __m128 v158; // xmm4
  __m128 v159; // xmm13
  __m128 v160; // xmm15
  __m128 v161; // xmm1
  __m128 v162; // xmm0
  __m128 v163; // xmm6
  __m128 v164; // xmm4
  __m128 v165; // xmm3
  __m128 v166; // xmm2
  __m128 v167; // xmm5
  int m_primitiveOffset; // eax
  int v169; // eax
  int v170; // eax
  int v171; // r8d
  int v172; // eax
  int v173; // r8d
  int v174; // eax
  int v175; // edx
  hkpShapeRayBundleCastInput *m_rays; // rax
  hkpRayShapeCollectionFilter *m_rayShapeCollectionFilter; // rcx
  hkpShapeContainer *m_collection; // r9
  unsigned __int64 v179; // rsi
  hkLifoAllocator *Value; // rcx
  hkpMoppRayBundleVirtualMachine::QueryBundle *m_cur; // rax
  bool v182; // cc
  hkVector4f *v183; // rdx
  hkpShape *v184; // rax
  int v185; // edx
  hkVector4f *p_m_earlyOutHitFraction; // r9
  __int64 v187; // r10
  hkLifoAllocator *v188; // rax
  unsigned __int8 v189; // [rsp+30h] [rbp-D0h] BYREF
  float v190; // [rsp+34h] [rbp-CCh]
  int v191; // [rsp+38h] [rbp-C8h]
  __m128 v192; // [rsp+40h] [rbp-C0h]
  hkpMoppRayBundleVirtualMachine::QueryBundle *__that[2]; // [rsp+50h] [rbp-B0h]
  __m128 v194; // [rsp+60h] [rbp-A0h]
  __m128 v195; // [rsp+70h] [rbp-90h]
  __m128 m_quad; // [rsp+80h] [rbp-80h] BYREF
  int m_shift; // [rsp+90h] [rbp-70h]
  __m128 v198; // [rsp+A0h] [rbp-60h]
  unsigned int v199; // [rsp+B0h] [rbp-50h]
  int v200[3]; // [rsp+B4h] [rbp-4Ch]
  __m128 v201; // [rsp+C0h] [rbp-40h] BYREF
  __m128 v202; // [rsp+D0h] [rbp-30h]
  __m128i v203; // [rsp+E0h] [rbp-20h]
  __m128 v204; // [rsp+F0h] [rbp-10h]
  __int128 v205[2]; // [rsp+100h] [rbp+0h] BYREF
  __m128 v206; // [rsp+120h] [rbp+20h]
  __m128 v207; // [rsp+130h] [rbp+30h]
  __m128 v208; // [rsp+140h] [rbp+40h]
  __m128 v209; // [rsp+150h] [rbp+50h]
  __m128 v210; // [rsp+160h] [rbp+60h]
  __m128 m_mask; // [rsp+170h] [rbp+70h]
  hkpMoppRayBundleVirtualMachine::QueryBundle fQuerya; // [rsp+180h] [rbp+80h] BYREF
  hkpMoppRayBundleVirtualMachine::QueryInt *v214; // [rsp+2B8h] [rbp+1B8h]
  unsigned int chunkIda; // [rsp+2D0h] [rbp+1D0h]

  v214 = query;
  p_m_quad = query;
  v8 = this;
  if ( HK_flyingcolors_mopp_1.m_bool )
  {
    while ( 1 )
    {
LABEL_4:
      v9 = (unsigned __int8)PC->m_rayEnds[0].m_vec[0].m_quad.m128_i8[3];
      v10 = (unsigned __int8)PC->m_rayEnds[0].m_vec[0].m_quad.m128_i8[1];
      LODWORD(v190) = (unsigned __int8)PC->m_rayEnds[0].m_vec[0].m_quad.m128_i8[0];
      v11 = (__m128)COERCE_UNSIGNED_INT((float)v9);
      __that[0] = (hkpMoppRayBundleVirtualMachine::QueryBundle *)&PC->m_rayEnds[0].m_vec[0].m_quad.m128_i8[3];
      v12 = v10;
      v192.m128_u64[0] = (unsigned __int64)PC->m_rayEnds[0].m_vec[0].m_quad.m128_u64 + 2;
      v13 = (unsigned __int8)PC->m_rayEnds[0].m_vec[0].m_quad.m128_i8[2];
      v189 = v9;
      v191 = 999;
      v14 = (__m128)COERCE_UNSIGNED_INT((float)v10);
      v15 = (__m128)COERCE_UNSIGNED_INT((float)v13);
      v16 = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)0i64, v15), _mm_unpacklo_ps(v14, v11));
      switch ( LODWORD(v190) )
      {
        case 0:
          return;
        case 1:
        case 2:
        case 3:
        case 4:
          v163 = _mm_unpacklo_ps(_mm_unpacklo_ps(v14, v11), _mm_unpacklo_ps(v15, (__m128)0i64));
          v164 = _mm_shuffle_ps(v163, v163, 0);
          v165 = _mm_shuffle_ps(v163, v163, 85);
          v166 = _mm_shuffle_ps(v163, v163, 170);
          v167 = *(&aabbOut.m_quad + (1 << SLOBYTE(v190)));
          fQuery->m_rayEnds[0].m_vec[0].m_quad = _mm_mul_ps(
                                                   _mm_sub_ps(fQuery->m_rayEnds[0].m_vec[0].m_quad, v164),
                                                   v167);
          fQuery->m_rayEnds[0].m_vec[1].m_quad = _mm_mul_ps(
                                                   _mm_sub_ps(fQuery->m_rayEnds[0].m_vec[1].m_quad, v165),
                                                   v167);
          fQuery->m_rayEnds[0].m_vec[2].m_quad = _mm_mul_ps(
                                                   _mm_sub_ps(fQuery->m_rayEnds[0].m_vec[2].m_quad, v166),
                                                   v167);
          fQuery->m_rayEnds[1].m_vec[0].m_quad = _mm_mul_ps(
                                                   _mm_sub_ps(fQuery->m_rayEnds[1].m_vec[0].m_quad, v164),
                                                   v167);
          fQuery->m_rayEnds[1].m_vec[1].m_quad = _mm_mul_ps(
                                                   _mm_sub_ps(fQuery->m_rayEnds[1].m_vec[1].m_quad, v165),
                                                   v167);
          fQuery->m_rayEnds[1].m_vec[2].m_quad = _mm_mul_ps(
                                                   _mm_sub_ps(fQuery->m_rayEnds[1].m_vec[2].m_quad, v166),
                                                   v167);
          m_quad = _mm_mul_ps(_mm_add_ps(p_m_quad->m_FtoBoffset.m_quad, v163), v167);
          PC = (hkpMoppRayBundleVirtualMachine::QueryBundle *)((char *)PC + 4);
          m_shift = LODWORD(v190) + p_m_quad->m_shift;
          v198 = _mm_mul_ps(p_m_quad->m_FtoBScale.m_quad, v167);
          v200[0] = p_m_quad->m_properties[0];
          m_primitiveOffset = p_m_quad->m_primitiveOffset;
          p_m_quad = (hkpMoppRayBundleVirtualMachine::QueryInt *)&m_quad;
          v199 = m_primitiveOffset;
          v214 = (hkpMoppRayBundleVirtualMachine::QueryInt *)&m_quad;
          continue;
        case 5:
          PC = (hkpMoppRayBundleVirtualMachine::QueryBundle *)((char *)PC
                                                             + (unsigned __int8)PC->m_rayEnds[0].m_vec[0].m_quad.m128_i8[1]
                                                             + 2);
          continue;
        case 6:
          PC = (hkpMoppRayBundleVirtualMachine::QueryBundle *)((char *)PC + 256 * v10 + v13 + 3);
          continue;
        case 7:
          PC = (hkpMoppRayBundleVirtualMachine::QueryBundle *)((char *)PC
                                                             + (unsigned int)((v13 << 8) + v9 + (v10 << 16))
                                                             + 4);
          continue;
        case 8:
          PC = (hkpMoppRayBundleVirtualMachine::QueryBundle *)((char *)PC
                                                             + 0x1000000 * v10
                                                             + 256 * (v9 + (v13 << 8))
                                                             + (unsigned int)(unsigned __int8)PC->m_rayEnds[0].m_vec[0].m_quad.m128_i8[4]
                                                             + 5);
          continue;
        case 9:
          if ( p_m_quad != (hkpMoppRayBundleVirtualMachine::QueryInt *)&m_quad )
          {
            m_quad = p_m_quad->m_FtoBoffset.m_quad;
            m_shift = p_m_quad->m_shift;
            v198 = p_m_quad->m_FtoBScale.m_quad;
            v199 = p_m_quad->m_primitiveOffset;
            v169 = p_m_quad->m_properties[0];
            p_m_quad = (hkpMoppRayBundleVirtualMachine::QueryInt *)&m_quad;
            v200[0] = v169;
            v214 = (hkpMoppRayBundleVirtualMachine::QueryInt *)&m_quad;
          }
          v199 += v10;
          PC = (hkpMoppRayBundleVirtualMachine::QueryBundle *)v192.m128_u64[0];
          continue;
        case 0xA:
          if ( p_m_quad != (hkpMoppRayBundleVirtualMachine::QueryInt *)&m_quad )
          {
            m_quad = p_m_quad->m_FtoBoffset.m_quad;
            m_shift = p_m_quad->m_shift;
            v198 = p_m_quad->m_FtoBScale.m_quad;
            v199 = p_m_quad->m_primitiveOffset;
            v170 = p_m_quad->m_properties[0];
            p_m_quad = (hkpMoppRayBundleVirtualMachine::QueryInt *)&m_quad;
            v200[0] = v170;
            v214 = (hkpMoppRayBundleVirtualMachine::QueryInt *)&m_quad;
          }
          v199 += v13 + (v10 << 8);
          PC = __that[0];
          continue;
        case 0xB:
          v171 = (unsigned __int8)PC->m_rayEnds[0].m_vec[0].m_quad.m128_i8[4] + (v10 << 24) + (v13 << 16) + (v9 << 8);
          if ( p_m_quad != (hkpMoppRayBundleVirtualMachine::QueryInt *)&m_quad )
          {
            m_quad = p_m_quad->m_FtoBoffset.m_quad;
            m_shift = p_m_quad->m_shift;
            v198 = p_m_quad->m_FtoBScale.m_quad;
            v199 = p_m_quad->m_primitiveOffset;
            v172 = p_m_quad->m_properties[0];
            p_m_quad = (hkpMoppRayBundleVirtualMachine::QueryInt *)&m_quad;
            v200[0] = v172;
            v214 = (hkpMoppRayBundleVirtualMachine::QueryInt *)&m_quad;
          }
          v199 = v171;
          goto $LN28_60;
        case 0xC:
          chunkId = v13 | (v10 << 8);
          PC = (hkpMoppRayBundleVirtualMachine::QueryBundle *)&v8->m_code->m_data.m_data[512 * chunkId];
          continue;
        case 0xD:
$LN28_60:
          PC = (hkpMoppRayBundleVirtualMachine::QueryBundle *)((char *)PC + 5);
          continue;
        case 0x10:
        case 0x11:
        case 0x12:
          v191 = LODWORD(v190) - 16;
          v20 = _mm_shuffle_ps(v16, v16, 170);
          v194 = _mm_shuffle_ps(v16, v16, 85);
          v192 = v20;
          v32 = *((__m128 *)&fQuery[-2] + LODWORD(v190) - 2);
          v30 = *((__m128 *)&fQuery[-1] + LODWORD(v190) - 6);
          goto LABEL_18;
        case 0x13:
          v17 = _mm_sub_ps(_mm_add_ps(v16, v16), _mm_mul_ps((__m128)xmmword_141A71160, aabbOut.m_quad));
          v195 = _mm_add_ps(fQuery->m_rayEnds[0].m_vec[2].m_quad, fQuery->m_rayEnds[0].m_vec[1].m_quad);
          v18 = fQuery->m_rayEnds[1].m_vec[2].m_quad;
          v194 = _mm_shuffle_ps(v17, v17, 85);
          v19 = _mm_add_ps(v18, fQuery->m_rayEnds[1].m_vec[1].m_quad);
          v192 = _mm_shuffle_ps(v17, v17, 170);
          v20 = v192;
          *(__m128 *)__that = v19;
          goto $do_compareN4_0;
        case 0x14:
          v21 = _mm_sub_ps(_mm_add_ps(v16, v16), _mm_mul_ps((__m128)xmmword_141A71160, ::query.m_quad));
          v195 = _mm_sub_ps(fQuery->m_rayEnds[0].m_vec[1].m_quad, fQuery->m_rayEnds[0].m_vec[2].m_quad);
          v22 = _mm_sub_ps(fQuery->m_rayEnds[1].m_vec[1].m_quad, fQuery->m_rayEnds[1].m_vec[2].m_quad);
          v194 = _mm_shuffle_ps(v21, v21, 85);
          v192 = _mm_shuffle_ps(v21, v21, 170);
          v20 = v192;
          *(__m128 *)__that = v22;
          goto $do_compareN4_0;
        case 0x15:
          v23 = _mm_sub_ps(_mm_add_ps(v16, v16), _mm_mul_ps((__m128)xmmword_141A71160, aabbOut.m_quad));
          v195 = _mm_add_ps(fQuery->m_rayEnds[0].m_vec[2].m_quad, fQuery->m_rayEnds[0].m_vec[0].m_quad);
          v24 = _mm_add_ps(fQuery->m_rayEnds[1].m_vec[2].m_quad, fQuery->m_rayEnds[1].m_vec[0].m_quad);
          v194 = _mm_shuffle_ps(v23, v23, 85);
          v192 = _mm_shuffle_ps(v23, v23, 170);
          v20 = v192;
          *(__m128 *)__that = v24;
          goto $do_compareN4_0;
        case 0x16:
          v25 = _mm_sub_ps(_mm_add_ps(v16, v16), _mm_mul_ps((__m128)xmmword_141A71160, ::query.m_quad));
          v195 = _mm_sub_ps(fQuery->m_rayEnds[0].m_vec[0].m_quad, fQuery->m_rayEnds[0].m_vec[2].m_quad);
          v26 = _mm_sub_ps(fQuery->m_rayEnds[1].m_vec[0].m_quad, fQuery->m_rayEnds[1].m_vec[2].m_quad);
          v194 = _mm_shuffle_ps(v25, v25, 85);
          v192 = _mm_shuffle_ps(v25, v25, 170);
          v20 = v192;
          *(__m128 *)__that = v26;
          goto $do_compareN4_0;
        case 0x17:
          v27 = _mm_sub_ps(_mm_add_ps(v16, v16), _mm_mul_ps((__m128)xmmword_141A71160, aabbOut.m_quad));
          v195 = _mm_add_ps(fQuery->m_rayEnds[0].m_vec[1].m_quad, fQuery->m_rayEnds[0].m_vec[0].m_quad);
          v28 = _mm_add_ps(fQuery->m_rayEnds[1].m_vec[1].m_quad, fQuery->m_rayEnds[1].m_vec[0].m_quad);
          v194 = _mm_shuffle_ps(v27, v27, 85);
          v192 = _mm_shuffle_ps(v27, v27, 170);
          v20 = v192;
          *(__m128 *)__that = v28;
          goto $do_compareN4_0;
        case 0x18:
          v29 = _mm_sub_ps(_mm_add_ps(v16, v16), _mm_mul_ps((__m128)xmmword_141A71160, ::query.m_quad));
          v30 = _mm_sub_ps(fQuery->m_rayEnds[1].m_vec[0].m_quad, fQuery->m_rayEnds[1].m_vec[1].m_quad);
          v194 = _mm_shuffle_ps(v29, v29, 85);
          v31 = fQuery->m_rayEnds[0].m_vec[0].m_quad;
          v192 = _mm_shuffle_ps(v29, v29, 170);
          v32 = _mm_sub_ps(v31, fQuery->m_rayEnds[0].m_vec[1].m_quad);
          v20 = v192;
LABEL_18:
          *(__m128 *)__that = v30;
          v195 = v32;
          goto $do_compareN4_0;
        case 0x19:
          v33 = _mm_sub_ps(_mm_add_ps(_mm_add_ps(v16, v16), v16), _mm_mul_ps((__m128)xmmword_141A71160, aabbOut.m_quad));
          v34 = _mm_shuffle_ps(v33, v33, 85);
          v20 = _mm_shuffle_ps(v33, v33, 170);
          v35 = _mm_add_ps(
                  _mm_add_ps(fQuery->m_rayEnds[0].m_vec[1].m_quad, fQuery->m_rayEnds[0].m_vec[0].m_quad),
                  fQuery->m_rayEnds[0].m_vec[2].m_quad);
          v194 = v34;
          v192 = v20;
          v195 = v35;
          *(__m128 *)__that = _mm_add_ps(
                                _mm_add_ps(fQuery->m_rayEnds[1].m_vec[1].m_quad, fQuery->m_rayEnds[1].m_vec[0].m_quad),
                                fQuery->m_rayEnds[1].m_vec[2].m_quad);
          goto $do_compareN4_0;
        case 0x1A:
          v36 = _mm_sub_ps(_mm_add_ps(_mm_add_ps(v16, v16), v16), _mm_mul_ps((__m128)xmmword_141A71160, ::query.m_quad));
          v37 = _mm_shuffle_ps(v36, v36, 85);
          v20 = _mm_shuffle_ps(v36, v36, 170);
          v38 = _mm_sub_ps(
                  _mm_add_ps(fQuery->m_rayEnds[0].m_vec[1].m_quad, fQuery->m_rayEnds[0].m_vec[0].m_quad),
                  fQuery->m_rayEnds[0].m_vec[2].m_quad);
          v194 = v37;
          v192 = v20;
          v195 = v38;
          *(__m128 *)__that = _mm_sub_ps(
                                _mm_add_ps(fQuery->m_rayEnds[1].m_vec[1].m_quad, fQuery->m_rayEnds[1].m_vec[0].m_quad),
                                fQuery->m_rayEnds[1].m_vec[2].m_quad);
          goto $do_compareN4_0;
        case 0x1B:
          v39 = _mm_sub_ps(_mm_add_ps(_mm_add_ps(v16, v16), v16), _mm_mul_ps((__m128)xmmword_141A71160, ::query.m_quad));
          v40 = _mm_shuffle_ps(v39, v39, 85);
          v20 = _mm_shuffle_ps(v39, v39, 170);
          v41 = _mm_add_ps(
                  _mm_sub_ps(fQuery->m_rayEnds[0].m_vec[0].m_quad, fQuery->m_rayEnds[0].m_vec[1].m_quad),
                  fQuery->m_rayEnds[0].m_vec[2].m_quad);
          v194 = v40;
          v192 = v20;
          v195 = v41;
          *(__m128 *)__that = _mm_add_ps(
                                _mm_sub_ps(fQuery->m_rayEnds[1].m_vec[0].m_quad, fQuery->m_rayEnds[1].m_vec[1].m_quad),
                                fQuery->m_rayEnds[1].m_vec[2].m_quad);
          goto $do_compareN4_0;
        case 0x1C:
          v42 = _mm_sub_ps(
                  _mm_add_ps(_mm_add_ps(v16, v16), v16),
                  _mm_mul_ps((__m128)xmmword_141A71160, (__m128)xmmword_141A710D0));
          v43 = _mm_shuffle_ps(v42, v42, 85);
          v20 = _mm_shuffle_ps(v42, v42, 170);
          v44 = _mm_sub_ps(
                  _mm_sub_ps(fQuery->m_rayEnds[0].m_vec[0].m_quad, fQuery->m_rayEnds[0].m_vec[1].m_quad),
                  fQuery->m_rayEnds[0].m_vec[2].m_quad);
          v194 = v43;
          v192 = v20;
          v195 = v44;
          *(__m128 *)__that = _mm_sub_ps(
                                _mm_sub_ps(fQuery->m_rayEnds[1].m_vec[0].m_quad, fQuery->m_rayEnds[1].m_vec[1].m_quad),
                                fQuery->m_rayEnds[1].m_vec[2].m_quad);
$do_compareN4_0:
          v47 = v194;
          v48 = v195;
          v49 = *(__m128 *)__that;
          v13 = v9;
          v45 = (hkpMoppRayBundleVirtualMachine::QueryBundle *)&PC->m_rayEnds[0].m_vec[0].m_quad.m128_i16[2];
          goto LABEL_20;
        case 0x20:
        case 0x21:
        case 0x22:
          v45 = __that[0];
          v46 = LODWORD(v190) - 32;
          v20 = _mm_shuffle_ps(v16, v16, 85);
          v191 = LODWORD(v190) - 32;
          v47 = _mm_add_ps(::query.m_quad, v20);
          v192 = v20;
          v194 = v47;
          v48 = fQuery->m_rayEnds[0].m_vec[v46].m_quad;
          v49 = fQuery->m_rayEnds[1].m_vec[v46].m_quad;
LABEL_20:
          v51 = 0;
          goto $do_compare_5;
        case 0x23:
        case 0x24:
        case 0x25:
          v50 = (unsigned __int8)PC->m_rayEnds[0].m_vec[0].m_quad.m128_i8[5] << 8;
          v47 = _mm_shuffle_ps(v16, v16, 85);
          v20 = _mm_shuffle_ps(v16, v16, 170);
          v191 = LODWORD(v190) - 35;
          v194 = v47;
          v192 = v20;
          v48 = fQuery[-5].m_rayEnds[0].m_vec[LODWORD(v190)].m_quad;
          v51 = (v9 << 8) + (unsigned __int8)PC->m_rayEnds[0].m_vec[0].m_quad.m128_i8[4];
          v49 = fQuery[-5].m_rayEnds[1].m_vec[LODWORD(v190)].m_quad;
          v13 = (unsigned __int8)PC->m_rayEnds[0].m_vec[0].m_quad.m128_i8[6] + v50;
          v45 = (hkpMoppRayBundleVirtualMachine::QueryBundle *)&PC->m_rayEnds[0].m_vec[0].m_quad.m128_u8[7];
$do_compare_5:
          v52.m_mask = (__m128)fQuery->m_activeMask;
          v53 = (__m128i)_mm_and_ps(_mm_and_ps(_mm_cmplt_ps(v49, v20), _mm_cmplt_ps(v48, v20)), v52.m_mask);
          m_mask = v52.m_mask;
          v54 = (__m128i)_mm_and_ps(_mm_and_ps(_mm_cmplt_ps(v47, v49), _mm_cmplt_ps(v47, v48)), v52.m_mask);
          v55 = (__m128)_mm_cmpeq_epi32((__m128i)0i64, (__m128i)v52.m_mask);
          if ( _mm_movemask_ps(_mm_or_ps((__m128)v53, v55)) == 15 )
          {
            PC = (hkpMoppRayBundleVirtualMachine::QueryBundle *)((char *)v45 + v51);
          }
          else if ( _mm_movemask_ps(_mm_or_ps((__m128)v54, v55)) == 15 )
          {
            PC = (hkpMoppRayBundleVirtualMachine::QueryBundle *)((char *)v45 + v13);
          }
          else
          {
            v56 = fQuery->m_rayEnds[0].m_vec[0].m_quad;
            v57 = fQuery->m_rayEnds[1].m_vec[0].m_quad;
            v58 = fQuery->m_rayEnds[0].m_vec[1].m_quad;
            v59 = fQuery->m_rayEnds[1].m_vec[1].m_quad;
            v60 = fQuery->m_rayEnds[0].m_vec[2].m_quad;
            v61 = fQuery->m_rayEnds[1].m_vec[2].m_quad;
            v195 = _mm_sub_ps(v48, v20);
            v202 = _mm_sub_ps(v48, v47);
            *(__m128 *)__that = _mm_sub_ps(v49, v20);
            v201 = _mm_sub_ps(v49, v47);
            v62 = _mm_sub_ps(v202, v201);
            v63 = (__m128)_mm_cmpeq_epi32(v54, (__m128i)0i64);
            v203 = _mm_cmpeq_epi32(v53, (__m128i)0i64);
            v210 = _mm_and_ps(v63, v52.m_mask);
            v204 = v63;
            fQuerya.m_activeMask.m_mask = _mm_and_ps((__m128)v203, v52.m_mask);
            v64 = _mm_cmplt_ps(_mm_mul_ps(v201, v202), (__m128)0i64);
            v65 = _mm_rcp_ps(v62);
            v66 = (__m128i)_mm_cmplt_ps(v202, v201);
            v67 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v62, v65)), v65);
            v68 = _mm_mul_ps(v67, v202);
            v69 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
            v70 = _mm_and_ps((__m128)_mm_cmpeq_epi32(v66, (__m128i)0i64), v64);
            v71 = _mm_and_ps((__m128)v66, v64);
            v72 = _mm_xor_ps(_mm_mul_ps(v67, v201), v69);
            v73 = _mm_add_ps(_mm_mul_ps(v57, v68), _mm_mul_ps(v56, v72));
            v205[0] = (__int128)_mm_or_ps(_mm_andnot_ps(v70, v56), _mm_and_ps(v73, v70));
            v207 = _mm_or_ps(_mm_andnot_ps(v71, v57), _mm_and_ps(v73, v71));
            v74 = _mm_add_ps(_mm_mul_ps(v59, v68), _mm_mul_ps(v58, v72));
            v205[1] = (__int128)_mm_or_ps(_mm_andnot_ps(v70, v58), _mm_and_ps(v74, v70));
            v208 = _mm_or_ps(_mm_andnot_ps(v71, v59), _mm_and_ps(v74, v71));
            v75 = _mm_add_ps(_mm_mul_ps(v61, v68), _mm_mul_ps(v60, v72));
            v206 = _mm_or_ps(_mm_andnot_ps(v70, v60), _mm_and_ps(v75, v70));
            v76 = _mm_sub_ps(v195, *(__m128 *)__that);
            v209 = _mm_or_ps(_mm_andnot_ps(v71, v61), _mm_and_ps(v75, v71));
            v77 = _mm_rcp_ps(v76);
            v78 = _mm_cmplt_ps(_mm_mul_ps(*(__m128 *)__that, v195), (__m128)0i64);
            v79 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v76, v77)), v77);
            v80 = _mm_mul_ps(v79, v195);
            v81 = _mm_xor_ps(_mm_mul_ps(v79, *(__m128 *)__that), v69);
            v82 = (__m128i)_mm_cmplt_ps(v201, v202);
            v83 = _mm_and_ps((__m128)v82, v78);
            v84 = _mm_and_ps((__m128)_mm_cmpeq_epi32(v82, (__m128i)0i64), v78);
            v85 = _mm_add_ps(_mm_mul_ps(v57, v80), _mm_mul_ps(v56, v81));
            fQuerya.m_rayEnds[0].m_vec[0].m_quad = _mm_or_ps(_mm_andnot_ps(v84, v56), _mm_and_ps(v85, v84));
            fQuerya.m_rayEnds[1].m_vec[0].m_quad = _mm_or_ps(_mm_andnot_ps(v83, v57), _mm_and_ps(v85, v83));
            v86 = _mm_add_ps(_mm_mul_ps(v59, v80), _mm_mul_ps(v58, v81));
            fQuerya.m_rayEnds[0].m_vec[1].m_quad = _mm_or_ps(_mm_andnot_ps(v84, v58), _mm_and_ps(v86, v84));
            fQuerya.m_rayEnds[1].m_vec[1].m_quad = _mm_or_ps(_mm_andnot_ps(v83, v59), _mm_and_ps(v86, v83));
            v87 = _mm_add_ps(_mm_mul_ps(v61, v80), _mm_mul_ps(v60, v81));
            p_fQuerya = (hkpMoppRayBundleVirtualMachine::QueryBundle *)v205;
            v89 = v51;
            __that[0] = &fQuerya;
            fQuerya.m_rayEnds[0].m_vec[2].m_quad = _mm_or_ps(_mm_andnot_ps(v84, v60), _mm_and_ps(v87, v84));
            v90 = _mm_and_ps((__m128)v66, m_mask);
            fQuerya.m_rayEnds[1].m_vec[2].m_quad = _mm_or_ps(_mm_andnot_ps(v83, v61), _mm_and_ps(v87, v83));
            v91 = _mm_or_ps(_mm_and_ps(::query.m_quad, m_mask), _mm_andnot_ps(m_mask, (__m128)0i64));
            v92 = _mm_or_ps(_mm_and_ps(v90, ::query.m_quad), _mm_andnot_ps(v90, (__m128)0i64));
            v93 = _mm_add_ps(_mm_shuffle_ps(v91, v91, 78), v91);
            v94 = _mm_add_ps(_mm_shuffle_ps(v92, v92, 78), v92);
            v92.m128_f32[0] = _mm_shuffle_ps(v94, v94, 177).m128_f32[0] + v94.m128_f32[0];
            if ( (float)(v92.m128_f32[0] + v92.m128_f32[0]) < (float)(_mm_shuffle_ps(v93, v93, 177).m128_f32[0]
                                                                    + v93.m128_f32[0]) )
            {
              v89 = v13;
              p_fQuerya = &fQuerya;
              __that[0] = (hkpMoppRayBundleVirtualMachine::QueryBundle *)v205;
              v13 = v51;
            }
            hkpMoppRayBundleVirtualMachine::queryRayOnTree(v8, p_m_quad, (const char *)v45 + v89, p_fQuerya, chunkId);
            v95 = v214->m_FtoBScale.m_quad;
            v96 = v214->m_FtoBoffset.m_quad;
            v97.m_quad = (__m128)this->m_earlyOutHitFraction;
            v98 = __that[0];
            m_code = this->m_code;
            v100 = _mm_sub_ps(::query.m_quad, v97.m_quad);
            v101 = _mm_cmplt_ps(v97.m_quad, ::query.m_quad);
            v102 = this->m_from.m_vec[1].m_quad;
            __that[0]->m_rayEnds[1].m_vec[0].m_quad = _mm_or_ps(
                                                        _mm_and_ps(
                                                          _mm_sub_ps(
                                                            _mm_mul_ps(
                                                              _mm_sub_ps(
                                                                _mm_add_ps(
                                                                  _mm_mul_ps(this->m_to.m_vec[0].m_quad, v97.m_quad),
                                                                  _mm_mul_ps(this->m_from.m_vec[0].m_quad, v100)),
                                                                _mm_shuffle_ps(
                                                                  m_code->m_info.m_offset.m_quad,
                                                                  m_code->m_info.m_offset.m_quad,
                                                                  0)),
                                                              _mm_shuffle_ps(v95, v95, 0)),
                                                            _mm_shuffle_ps(
                                                              v214->m_FtoBoffset.m_quad,
                                                              v214->m_FtoBoffset.m_quad,
                                                              0)),
                                                          v101),
                                                        _mm_andnot_ps(v101, __that[0]->m_rayEnds[1].m_vec[0].m_quad));
            v103 = _mm_or_ps(
                     _mm_and_ps(
                       _mm_sub_ps(
                         _mm_mul_ps(
                           _mm_sub_ps(
                             _mm_add_ps(_mm_mul_ps(this->m_to.m_vec[1].m_quad, v97.m_quad), _mm_mul_ps(v102, v100)),
                             _mm_shuffle_ps(m_code->m_info.m_offset.m_quad, m_code->m_info.m_offset.m_quad, 85)),
                           _mm_shuffle_ps(v95, v95, 85)),
                         _mm_shuffle_ps(v96, v96, 85)),
                       v101),
                     _mm_andnot_ps(v101, v98->m_rayEnds[1].m_vec[1].m_quad));
            v104 = this->m_from.m_vec[2].m_quad;
            v98->m_rayEnds[1].m_vec[1].m_quad = v103;
            v105 = m_code->m_info.m_offset.m_quad;
            v106 = v191;
            v98->m_rayEnds[1].m_vec[2].m_quad = _mm_or_ps(
                                                  _mm_and_ps(
                                                    _mm_sub_ps(
                                                      _mm_mul_ps(
                                                        _mm_sub_ps(
                                                          _mm_add_ps(
                                                            _mm_mul_ps(this->m_to.m_vec[2].m_quad, v97.m_quad),
                                                            _mm_mul_ps(v104, v100)),
                                                          _mm_shuffle_ps(v105, v105, 170)),
                                                        _mm_shuffle_ps(v95, v95, 170)),
                                                      _mm_shuffle_ps(v96, v96, 170)),
                                                    v101),
                                                  _mm_andnot_ps(v101, v98->m_rayEnds[1].m_vec[2].m_quad));
            if ( (int)v106 < 3 )
            {
              v107 = v98->m_rayEnds[1].m_vec[v106].m_quad;
              v108 = _mm_cmplt_ps(v194, v107);
              v98->m_activeMask.m_mask = _mm_and_ps(
                                           (__m128)_mm_cmpeq_epi32(
                                                     (__m128i)_mm_and_ps(
                                                                _mm_and_ps(
                                                                  _mm_or_ps(
                                                                    _mm_andnot_ps(v108, _mm_cmplt_ps(v202, v201)),
                                                                    _mm_and_ps(_mm_cmplt_ps(v107, v192), v108)),
                                                                  _mm_and_ps((__m128)v203, v204)),
                                                                v101),
                                                     (__m128i)0i64),
                                           v98->m_activeMask.m_mask);
            }
            if ( !_mm_movemask_ps(v98->m_activeMask.m_mask) )
              return;
            PC = (hkpMoppRayBundleVirtualMachine::QueryBundle *)((char *)v45 + v13);
            hkpMoppRayBundleVirtualMachine::QueryBundle::operator=(fQuery, v98);
            p_m_quad = v214;
            v8 = this;
          }
          break;
        case 0x26:
        case 0x27:
        case 0x28:
          PC = __that[0];
          v114 = LODWORD(v190) - 38;
          v118 = _mm_shuffle_ps(v16, v16, 85);
          v119 = _mm_shuffle_ps(v16, v16, 170);
          goto LABEL_33;
        case 0x29:
        case 0x2A:
        case 0x2B:
          v109 = (unsigned __int8)PC->m_rayEnds[0].m_vec[0].m_quad.m128_i8[4] << 8;
          v191 = LODWORD(v190) - 41;
          v110 = (unsigned __int8)PC->m_rayEnds[0].m_vec[0].m_quad.m128_i8[6]
               + (((unsigned __int8)PC->m_rayEnds[0].m_vec[0].m_quad.m128_i8[5] + v109) << 8);
          v111 = LODWORD(v190) - 41;
          PC = (hkpMoppRayBundleVirtualMachine::QueryBundle *)((char *)PC + 7);
          v190 = (float)(v9 + ((v13 + (v12 << 8)) << 8));
          v112 = _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(v190), (__m128)LODWORD(v190), 0), v8->m_ItoFScale.m_quad);
          v190 = (float)v110;
          v113 = (__m128)`hkVector4f::getComponent::`2::indexToMask[v111];
          v114 = v191;
          v115 = _mm_and_ps(v113, p_m_quad->m_FtoBoffset.m_quad);
          v116 = _mm_or_ps(_mm_shuffle_ps(v115, v115, 78), v115);
          v117 = _mm_or_ps(_mm_shuffle_ps(v116, v116, 177), v116);
          v118 = _mm_sub_ps(_mm_mul_ps(v112, p_m_quad->m_FtoBScale.m_quad), v117);
          v119 = _mm_sub_ps(
                   _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_shuffle_ps(
                         (__m128)COERCE_UNSIGNED_INT((float)v110),
                         (__m128)COERCE_UNSIGNED_INT((float)v110),
                         0),
                       v8->m_ItoFScale.m_quad),
                     p_m_quad->m_FtoBScale.m_quad),
                   v117);
LABEL_33:
          v201 = v118;
          v121 = fQuery->m_rayEnds[1].m_vec[v114].m_quad;
          v204 = fQuery->m_rayEnds[0].m_vec[v114].m_quad;
          v120 = v204;
          v203 = (__m128i)v121;
          v202 = _mm_cmplt_ps(v204, v121);
          v195 = _mm_cmple_ps(v121, v204);
          v122 = _mm_or_ps(_mm_cmplt_ps(v204, v118), _mm_cmplt_ps(v119, v121));
          v123.m_mask = _mm_and_ps(
                          (__m128)_mm_cmpeq_epi32(
                                    (__m128i)_mm_or_ps(
                                               _mm_and_ps(
                                                 _mm_or_ps(_mm_cmplt_ps(v121, v118), _mm_cmplt_ps(v119, v204)),
                                                 v122),
                                               _mm_andnot_ps(v122, v202)),
                                    (__m128i)0i64),
                          fQuery->m_activeMask.m_mask);
          fQuery->m_activeMask = (hkVector4fComparison)v123.m_mask;
          if ( !_mm_movemask_ps(v123.m_mask) )
            return;
          v124 = fQuery->m_rayEnds[0].m_vec[0].m_quad;
          v125 = fQuery->m_rayEnds[1].m_vec[0].m_quad;
          v126 = fQuery->m_rayEnds[0].m_vec[1].m_quad;
          v127 = fQuery->m_rayEnds[1].m_vec[1].m_quad;
          v128 = fQuery->m_rayEnds[1].m_vec[2].m_quad;
          v129 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
          v194 = fQuery->m_rayEnds[0].m_vec[2].m_quad;
          v130 = _mm_sub_ps(v120, v119);
          v131 = _mm_sub_ps(v121, v119);
          v132 = _mm_sub_ps(v130, v131);
          v133 = _mm_rcp_ps(v132);
          v134 = _mm_cmplt_ps(_mm_mul_ps(v131, v130), (__m128)0i64);
          v135 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v133, v132)), v133);
          v136 = _mm_mul_ps(v135, v131);
          v137 = _mm_and_ps(v134, v195);
          v138 = _mm_and_ps(v134, v202);
          v139 = _mm_mul_ps(v135, v130);
          v140 = _mm_xor_ps(v136, v129);
          v141 = _mm_add_ps(_mm_mul_ps(v124, v140), _mm_mul_ps(v125, v139));
          fQuery->m_rayEnds[0].m_vec[0].m_quad = _mm_or_ps(_mm_and_ps(v141, v137), _mm_andnot_ps(v137, v124));
          fQuery->m_rayEnds[1].m_vec[0].m_quad = _mm_or_ps(
                                                   _mm_and_ps(v141, v138),
                                                   _mm_andnot_ps(v138, fQuery->m_rayEnds[1].m_vec[0].m_quad));
          v142 = _mm_add_ps(_mm_mul_ps(v126, v140), _mm_mul_ps(v127, v139));
          fQuery->m_rayEnds[0].m_vec[1].m_quad = _mm_or_ps(
                                                   _mm_and_ps(v142, v137),
                                                   _mm_andnot_ps(v137, fQuery->m_rayEnds[0].m_vec[1].m_quad));
          v143 = _mm_mul_ps(v194, v140);
          fQuery->m_rayEnds[1].m_vec[1].m_quad = _mm_or_ps(
                                                   _mm_and_ps(v142, v138),
                                                   _mm_andnot_ps(v138, fQuery->m_rayEnds[1].m_vec[1].m_quad));
          v144 = _mm_add_ps(v143, _mm_mul_ps(v128, v139));
          v145 = _mm_and_ps(v144, v138);
          v146 = _mm_or_ps(_mm_and_ps(v144, v137), _mm_andnot_ps(v137, fQuery->m_rayEnds[0].m_vec[2].m_quad));
          v147 = v204;
          fQuery->m_rayEnds[0].m_vec[2].m_quad = v146;
          fQuery->m_rayEnds[1].m_vec[2].m_quad = _mm_or_ps(
                                                   v145,
                                                   _mm_andnot_ps(v138, fQuery->m_rayEnds[1].m_vec[2].m_quad));
          v148 = _mm_sub_ps(v147, v201);
          v149 = _mm_sub_ps((__m128)v203, v201);
          v150 = _mm_sub_ps(v148, v149);
          v151 = _mm_rcp_ps(v150);
          v152 = _mm_cmplt_ps(_mm_mul_ps(v149, v148), (__m128)0i64);
          v153 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v150, v151)), v151);
          v154 = _mm_mul_ps(v153, v149);
          v155 = _mm_mul_ps(v153, v148);
          v156 = _mm_and_ps(v195, v152);
          v157 = _mm_xor_ps(v154, v129);
          v158 = _mm_and_ps(v202, v152);
          v159 = _mm_add_ps(_mm_mul_ps(v124, v157), _mm_mul_ps(v125, v155));
          v160 = _mm_add_ps(_mm_mul_ps(v126, v157), _mm_mul_ps(v127, v155));
          fQuery->m_rayEnds[0].m_vec[0].m_quad = _mm_or_ps(
                                                   _mm_and_ps(v159, v158),
                                                   _mm_andnot_ps(v158, fQuery->m_rayEnds[0].m_vec[0].m_quad));
          fQuery->m_rayEnds[1].m_vec[0].m_quad = _mm_or_ps(
                                                   _mm_and_ps(v159, v156),
                                                   _mm_andnot_ps(v156, fQuery->m_rayEnds[1].m_vec[0].m_quad));
          fQuery->m_rayEnds[0].m_vec[1].m_quad = _mm_or_ps(
                                                   _mm_and_ps(v160, v158),
                                                   _mm_andnot_ps(v158, fQuery->m_rayEnds[0].m_vec[1].m_quad));
          v161 = _mm_mul_ps(v194, v157);
          fQuery->m_rayEnds[1].m_vec[1].m_quad = _mm_or_ps(
                                                   _mm_and_ps(v160, v156),
                                                   _mm_andnot_ps(v156, fQuery->m_rayEnds[1].m_vec[1].m_quad));
          v162 = _mm_add_ps(v161, _mm_mul_ps(v128, v155));
          fQuery->m_rayEnds[0].m_vec[2].m_quad = _mm_or_ps(
                                                   _mm_and_ps(v162, v158),
                                                   _mm_andnot_ps(v158, fQuery->m_rayEnds[0].m_vec[2].m_quad));
          fQuery->m_rayEnds[1].m_vec[2].m_quad = _mm_or_ps(
                                                   _mm_and_ps(v162, v156),
                                                   _mm_andnot_ps(v156, fQuery->m_rayEnds[1].m_vec[2].m_quad));
          continue;
        case 0x30:
        case 0x31:
        case 0x32:
        case 0x33:
        case 0x34:
        case 0x35:
        case 0x36:
        case 0x37:
        case 0x38:
        case 0x39:
        case 0x3A:
        case 0x3B:
        case 0x3C:
        case 0x3D:
        case 0x3E:
        case 0x3F:
        case 0x40:
        case 0x41:
        case 0x42:
        case 0x43:
        case 0x44:
        case 0x45:
        case 0x46:
        case 0x47:
        case 0x48:
        case 0x49:
        case 0x4A:
        case 0x4B:
        case 0x4C:
        case 0x4D:
        case 0x4E:
        case 0x4F:
          v10 = LODWORD(v190) - 48;
          goto $add_Terminal_5;
        case 0x50:
          v10 = (unsigned __int8)v10;
          goto $add_Terminal_5;
        case 0x51:
          v10 = *(unsigned __int8 *)v192.m128_u64[0] + ((unsigned __int8)v10 << 8);
          goto $add_Terminal_5;
        case 0x52:
          v10 = v189 + ((*(unsigned __int8 *)v192.m128_u64[0] + ((unsigned __int8)v10 << 8)) << 8);
          goto $add_Terminal_5;
        case 0x53:
          v10 = (unsigned __int8)PC->m_rayEnds[0].m_vec[0].m_quad.m128_i8[4]
              + ((v189
                + ((*(unsigned __int8 *)v192.m128_u64[0]
                  + ((unsigned __int8)PC->m_rayEnds[0].m_vec[0].m_quad.m128_i8[1] << 8)) << 8)) << 8);
$add_Terminal_5:
          v175 = (v10 + p_m_quad->m_primitiveOffset) | this->m_reindexingMask & (chunkId << 8);
          m_rays = this->m_rays;
          m_rayShapeCollectionFilter = m_rays->m_rayShapeCollectionFilter;
          chunkIda = v175;
          if ( m_rayShapeCollectionFilter )
          {
            m_collection = this->m_collection;
            v179 = 0i64;
            v206.m128_i32[0] = 0;
            v206.m128_u64[1] = 0i64;
            v207 = 0ui64;
            v206.m128_i32[0] = m_rays->m_filterInfo;
            if ( *(_BYTE *)m_rayShapeCollectionFilter->vfptr->isCollisionEnabled(
                             m_rayShapeCollectionFilter,
                             (hkBool *)&v189,
                             (hkpShapeRayCastInput *)v205,
                             m_collection,
                             v175) )
            {
              Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
              m_cur = (hkpMoppRayBundleVirtualMachine::QueryBundle *)Value->m_cur;
              v182 = Value->m_slabSize < 512;
              __that[0] = m_cur;
              v183 = &m_cur[4].m_rayEnds[1].m_vec[1];
              if ( v182 || v183 > Value->m_end )
              {
                m_cur = (hkpMoppRayBundleVirtualMachine::QueryBundle *)hkLifoAllocator::allocateFromNewSlab(Value, 512);
                __that[0] = m_cur;
              }
              else
              {
                Value->m_cur = v183;
              }
              v184 = this->m_collection->vfptr->getChildShape(this->m_collection, chunkIda, m_cur);
              ++this->m_rayResultPtr->m_outputs[0].m_shapeKeyIndex;
              ++this->m_rayResultPtr->m_outputs[1].m_shapeKeyIndex;
              ++this->m_rayResultPtr->m_outputs[2].m_shapeKeyIndex;
              ++this->m_rayResultPtr->m_outputs[3].m_shapeKeyIndex;
              ((void (__fastcall *)(hkpShape *, __m128 *, hkpShapeRayBundleCastInput *, hkpShapeRayBundleCastOutput *, hkVector4fComparison *))v184->vfptr[3].__first_virtual_table_function__)(
                v184,
                &v201,
                this->m_rays,
                this->m_rayResultPtr,
                &fQuery->m_activeMask);
              v185 = 1;
              p_m_earlyOutHitFraction = &this->m_earlyOutHitFraction;
              v187 = 4i64;
              do
              {
                --this->m_rayResultPtr->m_outputs[v179 / 0x14].m_shapeKeyIndex;
                if ( (_mm_movemask_ps(v201) & v185) != 0 )
                {
                  p_m_earlyOutHitFraction->m_quad.m128_i32[0] = LODWORD(this->m_rayResultPtr->m_outputs[v179 / 0x14].m_hitFraction);
                  this->m_rayResultPtr->m_outputs[0].m_shapeKeys[this->m_rayResultPtr->m_outputs[v179 / 0x14].m_shapeKeyIndex
                                                               + v179] = chunkIda;
                }
                v185 = __ROL4__(v185, 1);
                p_m_earlyOutHitFraction = (hkVector4f *)((char *)p_m_earlyOutHitFraction + 4);
                v179 += 20i64;
                --v187;
              }
              while ( v187 );
              this->m_hitsFound.m_mask = _mm_or_ps(this->m_hitsFound.m_mask, v201);
              v188 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
              if ( v188->m_slabSize < 512
                || &__that[0][4].m_rayEnds[1].m_vec[1] != v188->m_cur
                || v188->m_firstNonLifoEnd == __that[0] )
              {
                hkLifoAllocator::slowBlockFree(v188, (char *)__that[0], 512);
              }
              else
              {
                v188->m_cur = __that[0];
              }
            }
          }
          return;
        case 0x60:
        case 0x61:
        case 0x62:
        case 0x63:
          PC = (hkpMoppRayBundleVirtualMachine::QueryBundle *)v192.m128_u64[0];
          v200[LODWORD(v190) - 96] = v10;
          goto $propertyCopy_5;
        case 0x64:
        case 0x65:
        case 0x66:
        case 0x67:
          PC = __that[0];
          v200[LODWORD(v190) - 100] = v13 + (v10 << 8);
          goto $propertyCopy_5;
        case 0x68:
        case 0x69:
        case 0x6A:
        case 0x6B:
          v173 = (unsigned __int8)PC->m_rayEnds[0].m_vec[0].m_quad.m128_i8[4] + (v10 << 24) + (v13 << 16) + (v9 << 8);
          PC = (hkpMoppRayBundleVirtualMachine::QueryBundle *)((char *)PC + 5);
          v200[LODWORD(v190) - 104] = v173;
$propertyCopy_5:
          if ( p_m_quad != (hkpMoppRayBundleVirtualMachine::QueryInt *)&m_quad )
          {
            m_quad = p_m_quad->m_FtoBoffset.m_quad;
            m_shift = p_m_quad->m_shift;
            v198 = p_m_quad->m_FtoBScale.m_quad;
            v174 = p_m_quad->m_primitiveOffset;
            p_m_quad = (hkpMoppRayBundleVirtualMachine::QueryInt *)&m_quad;
            v199 = v174;
            v214 = (hkpMoppRayBundleVirtualMachine::QueryInt *)&m_quad;
          }
          continue;
        default:
          __debugbreak();
          continue;
      }
    }
  }
  hkpCheckKeycode();
  hkpProcessFlyingColors(&HK_flyingcolors_mopp_1);
  if ( HK_flyingcolors_mopp_1.m_bool )
  {
    p_m_quad = v214;
    v8 = this;
    goto LABEL_4;
  }
}

// File Line: 901
// RVA: 0xDB7330
hkVector4fComparison *__fastcall hkpMoppRayBundleVirtualMachine::queryRayBundle(
        hkpMoppRayBundleVirtualMachine *this,
        hkVector4fComparison *result,
        hkpShapeContainer *collection,
        hkpMoppCode *code,
        hkpShapeRayBundleCastInput *input,
        hkpShapeRayBundleCastOutput *rayResult,
        hkVector4fComparison *mask)
{
  char *m_data; // r8
  __m128 v10; // xmm3
  __m128 v11; // xmm2
  hkVector4f v12; // xmm1
  __m128 v13; // xmm2
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm0
  __m128 m_quad; // xmm2
  __m128 v18; // xmm4
  __m128 v19; // xmm1
  hkVector4f v20; // xmm4
  hkpMoppCode::CodeInfo v21; // xmm3
  __m128 v22; // xmm0
  __m128 v23; // xmm1
  __m128 v24; // xmm2
  __m128 v25; // xmm0
  __m128 v26; // xmm3
  __m128 v27; // xmm2
  __m128 v28; // xmm1
  __m128 v29; // xmm1
  __m128 v30; // xmm0
  __m128 v31; // xmm1
  __m128 m_mask; // xmm0
  hkVector4fComparison *v33; // rax
  hkpMoppRayBundleVirtualMachine::QueryInt query; // [rsp+30h] [rbp-B8h] BYREF
  hkpMoppRayBundleVirtualMachine::QueryBundle v35; // [rsp+70h] [rbp-78h] BYREF

  this->m_rayResultPtr = rayResult;
  this->m_collection = collection;
  this->m_earlyOutHitFraction = (hkVector4f)::query.m_quad;
  this->m_from = (RayPointBundle)input->m_from;
  this->m_to = (RayPointBundle)input->m_to;
  this->m_code = code;
  m_data = code->m_data.m_data;
  query.m_FtoBoffset = 0i64;
  v10 = _mm_shuffle_ps(
          (__m128)code->m_info.m_offset.m_quad.m128_u32[3],
          (__m128)code->m_info.m_offset.m_quad.m128_u32[3],
          0);
  v11 = _mm_rcp_ps(v10);
  v12.m_quad = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v11, v10)), v11);
  v13 = 0i64;
  v13.m128_f32[0] = (float)0x10000;
  this->m_ItoFScale = (hkVector4f)v12.m_quad;
  v14 = _mm_shuffle_ps(v13, v13, 0);
  v15 = _mm_rcp_ps(v14);
  v16 = _mm_mul_ps(v15, v14);
  m_quad = this->m_from.m_vec[0].m_quad;
  v18 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v16), v15);
  v19 = this->m_to.m_vec[0].m_quad;
  v20.m_quad = _mm_mul_ps(v18, v10);
  v21.m_offset.m_quad = (__m128)code->m_info;
  query.m_FtoBScale = (hkVector4f)v20.m_quad;
  v22 = _mm_shuffle_ps(v21.m_offset.m_quad, v21.m_offset.m_quad, 0);
  v23 = _mm_sub_ps(v19, v22);
  v24 = _mm_sub_ps(m_quad, v22);
  v25 = _mm_shuffle_ps(v21.m_offset.m_quad, v21.m_offset.m_quad, 85);
  v26 = _mm_shuffle_ps(v21.m_offset.m_quad, v21.m_offset.m_quad, 170);
  v35.m_rayEnds[0].m_vec[0].m_quad = _mm_mul_ps(v24, v20.m_quad);
  v27 = this->m_from.m_vec[1].m_quad;
  v35.m_rayEnds[1].m_vec[0].m_quad = _mm_mul_ps(v23, v20.m_quad);
  v28 = this->m_to.m_vec[1].m_quad;
  v35.m_rayEnds[0].m_vec[1].m_quad = _mm_mul_ps(_mm_sub_ps(v27, v25), v20.m_quad);
  v29 = _mm_mul_ps(_mm_sub_ps(v28, v25), v20.m_quad);
  v30 = _mm_sub_ps(this->m_to.m_vec[2].m_quad, v26);
  v35.m_rayEnds[1].m_vec[1].m_quad = v29;
  v31 = _mm_sub_ps(this->m_from.m_vec[2].m_quad, v26);
  v35.m_rayEnds[1].m_vec[2].m_quad = _mm_mul_ps(v30, v20.m_quad);
  m_mask = mask->m_mask;
  this->m_rays = input;
  v35.m_rayEnds[0].m_vec[2].m_quad = _mm_mul_ps(v31, v20.m_quad);
  v35.m_activeMask.m_mask = m_mask;
  this->m_hitsFound = 0i64;
  *(_QWORD *)&query.m_primitiveOffset = 0i64;
  query.m_shift = 0;
  this->m_reindexingMask = (*m_data != 13) - 1;
  hkpMoppRayBundleVirtualMachine::queryRayOnTree(this, &query, m_data, &v35, 0);
  v33 = result;
  *result = this->m_hitsFound;
  return v33;
}

