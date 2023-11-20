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
void __fastcall setBundleInterpolateWithMasks(RayPointBundle *inStart, RayPointBundle *inEnd, RayPointBundle *outStart, RayPointBundle *outEnd, hkVector4f *t, hkVector4f *oneMinusT, hkVector4fComparison *end0Mask, hkVector4fComparison *end1Mask)
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
signed __int64 __fastcall shouldDoLeftBranchFirst(hkVector4f *la, hkVector4f *lb, hkVector4fComparison *activeMask)
{
  signed __int64 result; // rax
  __m128 v4; // xmm4
  __m128 v5; // xmm3
  __m128 v6; // xmm1
  __m128 v7; // xmm0
  __m128 v8; // xmm2

  result = 0i64;
  v4 = _mm_and_ps(_mm_cmpltps(la->m_quad, lb->m_quad), activeMask->m_mask);
  v5 = _mm_or_ps(_mm_andnot_ps(activeMask->m_mask, (__m128)0i64), _mm_and_ps(activeMask->m_mask, query.m_quad));
  v6 = _mm_or_ps(_mm_andnot_ps(v4, (__m128)0i64), _mm_and_ps(v4, query.m_quad));
  v7 = _mm_add_ps(_mm_shuffle_ps(v6, v6, 78), v6);
  v8 = _mm_add_ps(_mm_shuffle_ps(v5, v5, 78), v5);
  v6.m128_f32[0] = COERCE_FLOAT(_mm_shuffle_ps(v7, v7, 177)) + v7.m128_f32[0];
  if ( (float)(v6.m128_f32[0] + v6.m128_f32[0]) >= (float)(COERCE_FLOAT(_mm_shuffle_ps(v8, v8, 177)) + v8.m128_f32[0]) )
    result = 1i64;
  return result;
}

// File Line: 132
// RVA: 0xDB8AF0
hkVector4fComparison *__fastcall getDifferentSignMask(hkVector4fComparison *result, hkVector4f *a, hkVector4f *b)
{
  hkVector4fComparison *v3; // rax

  v3 = result;
  result->m_mask = _mm_cmpltps(_mm_mul_ps(a->m_quad, b->m_quad), (__m128)0i64);
  return v3;
}

// File Line: 156
// RVA: 0xDB8B10
_BOOL8 __fastcall allMaskedAreSet(hkVector4fComparison *v, hkVector4fComparison *mask)
{
  return _mm_movemask_ps(_mm_or_ps((__m128)_mm_cmpeq_epi32(_mm_load_si128((const __m128i *)mask), (__m128i)0i64), v->m_mask)) == 15;
}

// File Line: 294
// RVA: 0xDB7500
void __fastcall hkpMoppRayBundleVirtualMachine::queryRayOnTree(hkpMoppRayBundleVirtualMachine *this, hkpMoppRayBundleVirtualMachine::QueryInt *query, const char *PC, hkpMoppRayBundleVirtualMachine::QueryBundle *const fQuery, int chunkId)
{
  hkpMoppRayBundleVirtualMachine::QueryBundle *v5; // rbx
  hkpMoppRayBundleVirtualMachine::QueryBundle *v6; // rdi
  hkpMoppRayBundleVirtualMachine::QueryInt *v7; // r10
  hkpMoppRayBundleVirtualMachine *v8; // r11
  signed int v9; // er8
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
  __m128i v52; // xmm11
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
  __m128 v81; // xmm5
  __m128 v82; // xmm8
  __m128i v83; // xmm3
  __m128 v84; // xmm5
  __m128 v85; // xmm3
  __m128 v86; // xmm0
  __m128 v87; // xmm0
  __m128 v88; // xmm0
  hkpMoppRayBundleVirtualMachine::QueryBundle *v89; // r9
  int v90; // edx
  __m128 v91; // xmm11
  __m128 v92; // xmm0
  __m128 v93; // xmm1
  __m128 v94; // xmm2
  __m128 v95; // xmm0
  __m128 v96; // xmm5
  __m128 v97; // xmm6
  __m128 v98; // xmm3
  hkpMoppRayBundleVirtualMachine::QueryBundle *v99; // rcx
  __m128 *v100; // rax
  __m128 v101; // xmm4
  __m128 v102; // xmm7
  __m128 v103; // xmm0
  __m128 v104; // xmm2
  __m128 v105; // xmm0
  __m128 v106; // xmm1
  __int64 v107; // rax
  __m128 v108; // xmm0
  __m128 v109; // xmm2
  int v110; // ecx
  int v111; // ecx
  __int64 v112; // rax
  __m128 v113; // xmm3
  __m128 v114; // xmm0
  int v115; // eax
  __m128 v116; // xmm0
  __m128 v117; // xmm1
  __m128 v118; // xmm2
  __m128 v119; // xmm3
  __m128 v120; // xmm5
  __m128 v121; // xmm6
  __m128 v122; // xmm7
  __m128 v123; // xmm2
  __m128 v124; // xmm1
  __m128 v125; // xmm13
  __m128 v126; // xmm10
  __m128 v127; // xmm15
  __m128 v128; // xmm12
  __m128 v129; // xmm14
  __m128 v130; // xmm8
  __m128 v131; // xmm3
  __m128 v132; // xmm4
  __m128 v133; // xmm1
  __m128 v134; // xmm2
  __m128 v135; // xmm7
  __m128 v136; // xmm6
  __m128 v137; // xmm5
  __m128 v138; // xmm6
  __m128 v139; // xmm4
  __m128 v140; // xmm7
  __m128 v141; // xmm5
  __m128 v142; // xmm6
  __m128 v143; // xmm2
  __m128 v144; // xmm3
  __m128 v145; // xmm1
  __m128 v146; // xmm1
  __m128 v147; // xmm0
  __m128 v148; // xmm4
  __m128 v149; // xmm4
  __m128 v150; // xmm5
  __m128 v151; // xmm1
  __m128 v152; // xmm0
  __m128 v153; // xmm2
  __m128 v154; // xmm11
  __m128 v155; // xmm3
  __m128 v156; // xmm11
  __m128 v157; // xmm3
  __m128 v158; // xmm5
  __m128 v159; // xmm11
  __m128 v160; // xmm4
  __m128 v161; // xmm13
  __m128 v162; // xmm15
  __m128 v163; // xmm1
  __m128 v164; // xmm0
  __m128 v165; // xmm6
  __m128 v166; // xmm4
  __m128 v167; // xmm3
  __m128 v168; // xmm2
  __m128 v169; // xmm5
  int v170; // eax
  int v171; // eax
  int v172; // eax
  int v173; // er8
  int v174; // eax
  int v175; // er8
  int v176; // eax
  int v177; // edx
  hkpShapeRayBundleCastInput *v178; // rax
  hkpRayShapeCollectionFilter *v179; // rcx
  hkpShapeContainer *v180; // r9
  unsigned __int64 v181; // rsi
  LPVOID v182; // rax
  hkLifoAllocator *v183; // rcx
  hkpMoppRayBundleVirtualMachine::QueryBundle *v184; // rax
  bool v185; // sf
  unsigned __int8 v186; // of
  unsigned __int64 v187; // rdx
  __int64 v188; // rax
  signed int v189; // edx
  __m128 *v190; // r9
  signed __int64 v191; // r10
  hkLifoAllocator *v192; // rax
  __int64 v193[2]; // [rsp+20h] [rbp-E0h]
  unsigned __int8 v194; // [rsp+30h] [rbp-D0h]
  float v195; // [rsp+34h] [rbp-CCh]
  int v196; // [rsp+38h] [rbp-C8h]
  __m128 v197; // [rsp+40h] [rbp-C0h]
  hkpMoppRayBundleVirtualMachine::QueryBundle *__that[2]; // [rsp+50h] [rbp-B0h]
  __m128 v199; // [rsp+60h] [rbp-A0h]
  __m128 v200; // [rsp+70h] [rbp-90h]
  __m128 v201; // [rsp+80h] [rbp-80h]
  int v202; // [rsp+90h] [rbp-70h]
  __m128 v203; // [rsp+A0h] [rbp-60h]
  unsigned int v204; // [rsp+B0h] [rbp-50h]
  int v205[3]; // [rsp+B4h] [rbp-4Ch]
  __m128 v206; // [rsp+C0h] [rbp-40h]
  __m128 v207; // [rsp+D0h] [rbp-30h]
  __m128 v208; // [rsp+E0h] [rbp-20h]
  __m128 v209; // [rsp+F0h] [rbp-10h]
  __m128 v210; // [rsp+100h] [rbp+0h]
  __m128 v211; // [rsp+110h] [rbp+10h]
  __m128 v212; // [rsp+120h] [rbp+20h]
  __m128 v213; // [rsp+130h] [rbp+30h]
  __m128 v214; // [rsp+140h] [rbp+40h]
  __m128 v215; // [rsp+150h] [rbp+50h]
  __m128 v216; // [rsp+160h] [rbp+60h]
  __m128 v217; // [rsp+170h] [rbp+70h]
  hkpMoppRayBundleVirtualMachine::QueryBundle fQuerya; // [rsp+180h] [rbp+80h]
  hkpMoppRayBundleVirtualMachine *v219; // [rsp+2B0h] [rbp+1B0h]
  hkpMoppRayBundleVirtualMachine::QueryInt *v220; // [rsp+2B8h] [rbp+1B8h]
  unsigned int chunkIda; // [rsp+2D0h] [rbp+1D0h]

  v220 = query;
  v219 = this;
  v5 = fQuery;
  v6 = (hkpMoppRayBundleVirtualMachine::QueryBundle *)PC;
  v7 = query;
  v8 = this;
  if ( HK_flyingcolors_mopp_1.m_bool )
  {
    while ( 1 )
    {
LABEL_4:
      v9 = (unsigned __int8)v6->m_rayEnds[0].m_vec[0].m_quad.m128_i8[3];
      v10 = (unsigned __int8)v6->m_rayEnds[0].m_vec[0].m_quad.m128_i8[1];
      LODWORD(v195) = (unsigned __int8)v6->m_rayEnds[0].m_vec[0].m_quad.m128_i8[0];
      v11 = (__m128)COERCE_UNSIGNED_INT((float)v9);
      __that[0] = (hkpMoppRayBundleVirtualMachine::QueryBundle *)((char *)v6 + 3);
      v12 = v10;
      v197.m128_u64[0] = (unsigned __int64)v6->m_rayEnds[0].m_vec[0].m_quad.m128_u64 + 2;
      v13 = (unsigned __int8)v6->m_rayEnds[0].m_vec[0].m_quad.m128_i8[2];
      v194 = v9;
      v196 = 999;
      v14 = (__m128)COERCE_UNSIGNED_INT((float)v10);
      v15 = (__m128)COERCE_UNSIGNED_INT((float)v13);
      v16 = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)0i64, v15), _mm_unpacklo_ps(v14, v11));
      switch ( 0x40000000 )
      {
        case 0:
          return;
        case 1:
        case 2:
        case 3:
        case 4:
          v165 = _mm_unpacklo_ps(_mm_unpacklo_ps(v14, v11), _mm_unpacklo_ps(v15, (__m128)0i64));
          v166 = _mm_shuffle_ps(v165, v165, 0);
          v167 = _mm_shuffle_ps(v165, v165, 85);
          v168 = _mm_shuffle_ps(v165, v165, 170);
          v169 = *(&aabbOut.m_quad + (1 << SLOBYTE(v195)));
          v5->m_rayEnds[0].m_vec[0].m_quad = _mm_mul_ps(_mm_sub_ps(v5->m_rayEnds[0].m_vec[0].m_quad, v166), v169);
          v5->m_rayEnds[0].m_vec[1].m_quad = _mm_mul_ps(_mm_sub_ps(v5->m_rayEnds[0].m_vec[1].m_quad, v167), v169);
          v5->m_rayEnds[0].m_vec[2].m_quad = _mm_mul_ps(_mm_sub_ps(v5->m_rayEnds[0].m_vec[2].m_quad, v168), v169);
          v5->m_rayEnds[1].m_vec[0].m_quad = _mm_mul_ps(_mm_sub_ps(v5->m_rayEnds[1].m_vec[0].m_quad, v166), v169);
          v5->m_rayEnds[1].m_vec[1].m_quad = _mm_mul_ps(_mm_sub_ps(v5->m_rayEnds[1].m_vec[1].m_quad, v167), v169);
          v5->m_rayEnds[1].m_vec[2].m_quad = _mm_mul_ps(_mm_sub_ps(v5->m_rayEnds[1].m_vec[2].m_quad, v168), v169);
          v201 = _mm_mul_ps(_mm_add_ps(v7->m_FtoBoffset.m_quad, v165), v169);
          v6 = (hkpMoppRayBundleVirtualMachine::QueryBundle *)((char *)v6 + 4);
          v202 = LODWORD(v195) + v7->m_shift;
          v203 = _mm_mul_ps(v7->m_FtoBScale.m_quad, v169);
          v205[0] = v7->m_properties[0];
          v170 = v7->m_primitiveOffset;
          v7 = (hkpMoppRayBundleVirtualMachine::QueryInt *)&v201;
          v204 = v170;
          v220 = (hkpMoppRayBundleVirtualMachine::QueryInt *)&v201;
          continue;
        case 5:
          v6 = (hkpMoppRayBundleVirtualMachine::QueryBundle *)((char *)v6
                                                             + (unsigned __int8)v6->m_rayEnds[0].m_vec[0].m_quad.m128_i8[1]
                                                             + 2);
          continue;
        case 6:
          v6 = (hkpMoppRayBundleVirtualMachine::QueryBundle *)((char *)v6 + 256 * v10 + v13 + 3);
          continue;
        case 7:
          v6 = (hkpMoppRayBundleVirtualMachine::QueryBundle *)((char *)v6
                                                             + (unsigned int)((v13 << 8) + v9 + (v10 << 16))
                                                             + 4);
          continue;
        case 8:
          v6 = (hkpMoppRayBundleVirtualMachine::QueryBundle *)((char *)v6
                                                             + 0x1000000 * v10
                                                             + 256 * (v9 + (v13 << 8))
                                                             + (unsigned int)(unsigned __int8)v6->m_rayEnds[0].m_vec[0].m_quad.m128_i8[4]
                                                             + 5);
          continue;
        case 9:
          if ( v7 != (hkpMoppRayBundleVirtualMachine::QueryInt *)&v201 )
          {
            v201 = v7->m_FtoBoffset.m_quad;
            v202 = v7->m_shift;
            v203 = v7->m_FtoBScale.m_quad;
            v204 = v7->m_primitiveOffset;
            v171 = v7->m_properties[0];
            v7 = (hkpMoppRayBundleVirtualMachine::QueryInt *)&v201;
            v205[0] = v171;
            v220 = (hkpMoppRayBundleVirtualMachine::QueryInt *)&v201;
          }
          v204 += v10;
          v6 = (hkpMoppRayBundleVirtualMachine::QueryBundle *)v197.m128_u64[0];
          continue;
        case 10:
          if ( v7 != (hkpMoppRayBundleVirtualMachine::QueryInt *)&v201 )
          {
            v201 = v7->m_FtoBoffset.m_quad;
            v202 = v7->m_shift;
            v203 = v7->m_FtoBScale.m_quad;
            v204 = v7->m_primitiveOffset;
            v172 = v7->m_properties[0];
            v7 = (hkpMoppRayBundleVirtualMachine::QueryInt *)&v201;
            v205[0] = v172;
            v220 = (hkpMoppRayBundleVirtualMachine::QueryInt *)&v201;
          }
          v204 += v13 + (v10 << 8);
          v6 = __that[0];
          continue;
        case 11:
          v173 = (unsigned __int8)v6->m_rayEnds[0].m_vec[0].m_quad.m128_i8[4] + (v10 << 24) + (v13 << 16) + (v9 << 8);
          if ( v7 != (hkpMoppRayBundleVirtualMachine::QueryInt *)&v201 )
          {
            v201 = v7->m_FtoBoffset.m_quad;
            v202 = v7->m_shift;
            v203 = v7->m_FtoBScale.m_quad;
            v204 = v7->m_primitiveOffset;
            v174 = v7->m_properties[0];
            v7 = (hkpMoppRayBundleVirtualMachine::QueryInt *)&v201;
            v205[0] = v174;
            v220 = (hkpMoppRayBundleVirtualMachine::QueryInt *)&v201;
          }
          v204 = v173;
          goto $LN28_60;
        case 12:
          chunkId = v13 | (v10 << 8);
          v6 = (hkpMoppRayBundleVirtualMachine::QueryBundle *)&v8->m_code->m_data.m_data[512 * chunkId];
          continue;
        case 13:
$LN28_60:
          v6 = (hkpMoppRayBundleVirtualMachine::QueryBundle *)((char *)v6 + 5);
          continue;
        case 16:
        case 17:
        case 18:
          v196 = LODWORD(v195) - 16;
          v20 = _mm_shuffle_ps(v16, v16, 170);
          v199 = _mm_shuffle_ps(v16, v16, 85);
          v197 = v20;
          v32 = v5->m_rayEnds[0].m_vec[LODWORD(v195) - 16].m_quad;
          v30 = v5->m_rayEnds[0].m_vec[LODWORD(v195) - 16 + 3i64].m_quad;
          goto LABEL_18;
        case 19:
          v17 = _mm_sub_ps(_mm_add_ps(v16, v16), _mm_mul_ps((__m128)xmmword_141A71160, aabbOut.m_quad));
          v200 = _mm_add_ps(v5->m_rayEnds[0].m_vec[2].m_quad, v5->m_rayEnds[0].m_vec[1].m_quad);
          v18 = v5->m_rayEnds[1].m_vec[2].m_quad;
          v199 = _mm_shuffle_ps(v17, v17, 85);
          v19 = _mm_add_ps(v18, v5->m_rayEnds[1].m_vec[1].m_quad);
          v197 = _mm_shuffle_ps(v17, v17, 170);
          v20 = v197;
          *(__m128 *)__that = v19;
          goto $do_compareN4_0;
        case 20:
          v21 = _mm_sub_ps(_mm_add_ps(v16, v16), _mm_mul_ps((__m128)xmmword_141A71160, ::query.m_quad));
          v200 = _mm_sub_ps(v5->m_rayEnds[0].m_vec[1].m_quad, v5->m_rayEnds[0].m_vec[2].m_quad);
          v22 = _mm_sub_ps(v5->m_rayEnds[1].m_vec[1].m_quad, v5->m_rayEnds[1].m_vec[2].m_quad);
          v199 = _mm_shuffle_ps(v21, v21, 85);
          v197 = _mm_shuffle_ps(v21, v21, 170);
          v20 = v197;
          *(__m128 *)__that = v22;
          goto $do_compareN4_0;
        case 21:
          v23 = _mm_sub_ps(_mm_add_ps(v16, v16), _mm_mul_ps((__m128)xmmword_141A71160, aabbOut.m_quad));
          v200 = _mm_add_ps(v5->m_rayEnds[0].m_vec[2].m_quad, v5->m_rayEnds[0].m_vec[0].m_quad);
          v24 = _mm_add_ps(v5->m_rayEnds[1].m_vec[2].m_quad, v5->m_rayEnds[1].m_vec[0].m_quad);
          v199 = _mm_shuffle_ps(v23, v23, 85);
          v197 = _mm_shuffle_ps(v23, v23, 170);
          v20 = v197;
          *(__m128 *)__that = v24;
          goto $do_compareN4_0;
        case 22:
          v25 = _mm_sub_ps(_mm_add_ps(v16, v16), _mm_mul_ps((__m128)xmmword_141A71160, ::query.m_quad));
          v200 = _mm_sub_ps(v5->m_rayEnds[0].m_vec[0].m_quad, v5->m_rayEnds[0].m_vec[2].m_quad);
          v26 = _mm_sub_ps(v5->m_rayEnds[1].m_vec[0].m_quad, v5->m_rayEnds[1].m_vec[2].m_quad);
          v199 = _mm_shuffle_ps(v25, v25, 85);
          v197 = _mm_shuffle_ps(v25, v25, 170);
          v20 = v197;
          *(__m128 *)__that = v26;
          goto $do_compareN4_0;
        case 23:
          v27 = _mm_sub_ps(_mm_add_ps(v16, v16), _mm_mul_ps((__m128)xmmword_141A71160, aabbOut.m_quad));
          v200 = _mm_add_ps(v5->m_rayEnds[0].m_vec[1].m_quad, v5->m_rayEnds[0].m_vec[0].m_quad);
          v28 = _mm_add_ps(v5->m_rayEnds[1].m_vec[1].m_quad, v5->m_rayEnds[1].m_vec[0].m_quad);
          v199 = _mm_shuffle_ps(v27, v27, 85);
          v197 = _mm_shuffle_ps(v27, v27, 170);
          v20 = v197;
          *(__m128 *)__that = v28;
          goto $do_compareN4_0;
        case 24:
          v29 = _mm_sub_ps(_mm_add_ps(v16, v16), _mm_mul_ps((__m128)xmmword_141A71160, ::query.m_quad));
          v30 = _mm_sub_ps(v5->m_rayEnds[1].m_vec[0].m_quad, v5->m_rayEnds[1].m_vec[1].m_quad);
          v199 = _mm_shuffle_ps(v29, v29, 85);
          v31 = v5->m_rayEnds[0].m_vec[0].m_quad;
          v197 = _mm_shuffle_ps(v29, v29, 170);
          v32 = _mm_sub_ps(v31, v5->m_rayEnds[0].m_vec[1].m_quad);
          v20 = v197;
LABEL_18:
          *(__m128 *)__that = v30;
          v200 = v32;
          goto $do_compareN4_0;
        case 25:
          v33 = _mm_sub_ps(_mm_add_ps(_mm_add_ps(v16, v16), v16), _mm_mul_ps((__m128)xmmword_141A71160, aabbOut.m_quad));
          v34 = _mm_shuffle_ps(v33, v33, 85);
          v20 = _mm_shuffle_ps(v33, v33, 170);
          v35 = _mm_add_ps(
                  _mm_add_ps(v5->m_rayEnds[0].m_vec[1].m_quad, v5->m_rayEnds[0].m_vec[0].m_quad),
                  v5->m_rayEnds[0].m_vec[2].m_quad);
          v199 = v34;
          v197 = v20;
          v200 = v35;
          *(__m128 *)__that = _mm_add_ps(
                                _mm_add_ps(v5->m_rayEnds[1].m_vec[1].m_quad, v5->m_rayEnds[1].m_vec[0].m_quad),
                                v5->m_rayEnds[1].m_vec[2].m_quad);
          goto $do_compareN4_0;
        case 26:
          v36 = _mm_sub_ps(_mm_add_ps(_mm_add_ps(v16, v16), v16), _mm_mul_ps((__m128)xmmword_141A71160, ::query.m_quad));
          v37 = _mm_shuffle_ps(v36, v36, 85);
          v20 = _mm_shuffle_ps(v36, v36, 170);
          v38 = _mm_sub_ps(
                  _mm_add_ps(v5->m_rayEnds[0].m_vec[1].m_quad, v5->m_rayEnds[0].m_vec[0].m_quad),
                  v5->m_rayEnds[0].m_vec[2].m_quad);
          v199 = v37;
          v197 = v20;
          v200 = v38;
          *(__m128 *)__that = _mm_sub_ps(
                                _mm_add_ps(v5->m_rayEnds[1].m_vec[1].m_quad, v5->m_rayEnds[1].m_vec[0].m_quad),
                                v5->m_rayEnds[1].m_vec[2].m_quad);
          goto $do_compareN4_0;
        case 27:
          v39 = _mm_sub_ps(_mm_add_ps(_mm_add_ps(v16, v16), v16), _mm_mul_ps((__m128)xmmword_141A71160, ::query.m_quad));
          v40 = _mm_shuffle_ps(v39, v39, 85);
          v20 = _mm_shuffle_ps(v39, v39, 170);
          v41 = _mm_add_ps(
                  _mm_sub_ps(v5->m_rayEnds[0].m_vec[0].m_quad, v5->m_rayEnds[0].m_vec[1].m_quad),
                  v5->m_rayEnds[0].m_vec[2].m_quad);
          v199 = v40;
          v197 = v20;
          v200 = v41;
          *(__m128 *)__that = _mm_add_ps(
                                _mm_sub_ps(v5->m_rayEnds[1].m_vec[0].m_quad, v5->m_rayEnds[1].m_vec[1].m_quad),
                                v5->m_rayEnds[1].m_vec[2].m_quad);
          goto $do_compareN4_0;
        case 28:
          v42 = _mm_sub_ps(
                  _mm_add_ps(_mm_add_ps(v16, v16), v16),
                  _mm_mul_ps((__m128)xmmword_141A71160, (__m128)xmmword_141A710D0));
          v43 = _mm_shuffle_ps(v42, v42, 85);
          v20 = _mm_shuffle_ps(v42, v42, 170);
          v44 = _mm_sub_ps(
                  _mm_sub_ps(v5->m_rayEnds[0].m_vec[0].m_quad, v5->m_rayEnds[0].m_vec[1].m_quad),
                  v5->m_rayEnds[0].m_vec[2].m_quad);
          v199 = v43;
          v197 = v20;
          v200 = v44;
          *(__m128 *)__that = _mm_sub_ps(
                                _mm_sub_ps(v5->m_rayEnds[1].m_vec[0].m_quad, v5->m_rayEnds[1].m_vec[1].m_quad),
                                v5->m_rayEnds[1].m_vec[2].m_quad);
$do_compareN4_0:
          v47 = v199;
          v48 = v200;
          v49 = *(__m128 *)__that;
          v13 = v9;
          v45 = (hkpMoppRayBundleVirtualMachine::QueryBundle *)((char *)v6 + 4);
          goto LABEL_20;
        case 32:
        case 33:
        case 34:
          v45 = __that[0];
          v46 = LODWORD(v195) - 32;
          v20 = _mm_shuffle_ps(v16, v16, 85);
          v196 = LODWORD(v195) - 32;
          v47 = _mm_add_ps(::query.m_quad, v20);
          v197 = v20;
          v199 = v47;
          v48 = v5->m_rayEnds[0].m_vec[v46].m_quad;
          v49 = v5->m_rayEnds[0].m_vec[v46 + 3].m_quad;
LABEL_20:
          v51 = 0;
          goto $do_compare_5;
        case 35:
        case 36:
        case 37:
          v50 = (unsigned __int8)v6->m_rayEnds[0].m_vec[0].m_quad.m128_i8[5] << 8;
          v47 = _mm_shuffle_ps(v16, v16, 85);
          v20 = _mm_shuffle_ps(v16, v16, 170);
          v196 = LODWORD(v195) - 35;
          v199 = v47;
          v197 = v20;
          v48 = v5->m_rayEnds[0].m_vec[LODWORD(v195) - 35].m_quad;
          v51 = (v9 << 8) + (unsigned __int8)v6->m_rayEnds[0].m_vec[0].m_quad.m128_i8[4];
          v49 = v5->m_rayEnds[0].m_vec[LODWORD(v195) - 35 + 3i64].m_quad;
          v13 = (unsigned __int8)v6->m_rayEnds[0].m_vec[0].m_quad.m128_i8[6] + v50;
          v45 = (hkpMoppRayBundleVirtualMachine::QueryBundle *)((char *)v6 + 7);
$do_compare_5:
          v52 = (__m128i)v5->m_activeMask;
          v53 = (__m128i)_mm_and_ps(_mm_and_ps(_mm_cmpltps(v49, v20), _mm_cmpltps(v48, v20)), (__m128)v52);
          v217 = v5->m_activeMask.m_mask;
          v54 = (__m128i)_mm_and_ps(_mm_and_ps(_mm_cmpltps(v47, v49), _mm_cmpltps(v47, v48)), (__m128)v52);
          v55 = (__m128)_mm_cmpeq_epi32((__m128i)0i64, v52);
          if ( _mm_movemask_ps(_mm_or_ps((__m128)v53, v55)) == 15 )
          {
            v6 = (hkpMoppRayBundleVirtualMachine::QueryBundle *)((char *)v45 + v51);
          }
          else if ( _mm_movemask_ps(_mm_or_ps((__m128)v54, v55)) == 15 )
          {
            v6 = (hkpMoppRayBundleVirtualMachine::QueryBundle *)((char *)v45 + v13);
          }
          else
          {
            v56 = v5->m_rayEnds[0].m_vec[0].m_quad;
            v57 = v5->m_rayEnds[1].m_vec[0].m_quad;
            v58 = v5->m_rayEnds[0].m_vec[1].m_quad;
            v59 = v5->m_rayEnds[1].m_vec[1].m_quad;
            v60 = v5->m_rayEnds[0].m_vec[2].m_quad;
            v61 = v5->m_rayEnds[1].m_vec[2].m_quad;
            v200 = _mm_sub_ps(v48, v20);
            v207 = _mm_sub_ps(v48, v47);
            *(__m128 *)__that = _mm_sub_ps(v49, v20);
            v206 = _mm_sub_ps(v49, v47);
            v62 = _mm_sub_ps(v207, v206);
            v63 = (__m128)_mm_cmpeq_epi32(v54, (__m128i)0i64);
            v208 = (__m128)_mm_cmpeq_epi32(v53, (__m128i)0i64);
            v216 = _mm_and_ps(v63, (__m128)v52);
            v209 = v63;
            fQuerya.m_activeMask.m_mask = _mm_and_ps(v208, (__m128)v52);
            v64 = _mm_cmpltps(_mm_mul_ps(v206, v207), (__m128)0i64);
            v65 = _mm_rcp_ps(v62);
            v66 = (__m128i)_mm_cmpltps(v207, v206);
            v67 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v62, v65)), v65);
            v68 = _mm_mul_ps(v67, v207);
            v69 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
            v70 = _mm_and_ps((__m128)_mm_cmpeq_epi32(v66, (__m128i)0i64), v64);
            v71 = _mm_and_ps((__m128)v66, v64);
            v72 = _mm_xor_ps(_mm_mul_ps(v67, v206), v69);
            v73 = _mm_add_ps(_mm_mul_ps(v57, v68), _mm_mul_ps(v56, v72));
            v210 = _mm_or_ps(_mm_andnot_ps(v70, v56), _mm_and_ps(v73, v70));
            v213 = _mm_or_ps(_mm_andnot_ps(v71, v57), _mm_and_ps(v73, v71));
            v74 = _mm_add_ps(_mm_mul_ps(v59, v68), _mm_mul_ps(v58, v72));
            v211 = _mm_or_ps(_mm_andnot_ps(v70, v58), _mm_and_ps(v74, v70));
            v214 = _mm_or_ps(_mm_andnot_ps(v71, v59), _mm_and_ps(v74, v71));
            v75 = _mm_add_ps(_mm_mul_ps(v61, v68), _mm_mul_ps(v60, v72));
            v212 = _mm_or_ps(_mm_andnot_ps(v70, v60), _mm_and_ps(v75, v70));
            v76 = _mm_sub_ps(v200, *(__m128 *)__that);
            v215 = _mm_or_ps(_mm_andnot_ps(v71, v61), _mm_and_ps(v75, v71));
            v77 = _mm_rcp_ps(v76);
            v78 = _mm_cmpltps(_mm_mul_ps(*(__m128 *)__that, v200), (__m128)0i64);
            v79 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v76, v77)), v77);
            v80 = _mm_mul_ps(v79, v200);
            v81 = _mm_cmpltps(v206, v207);
            v82 = _mm_xor_ps(_mm_mul_ps(v79, *(__m128 *)__that), v69);
            v83 = (__m128i)v81;
            v84 = _mm_and_ps(v81, v78);
            v85 = _mm_and_ps((__m128)_mm_cmpeq_epi32(v83, (__m128i)0i64), v78);
            v86 = _mm_add_ps(_mm_mul_ps(v57, v80), _mm_mul_ps(v56, v82));
            fQuerya.m_rayEnds[0].m_vec[0].m_quad = _mm_or_ps(_mm_andnot_ps(v85, v56), _mm_and_ps(v86, v85));
            fQuerya.m_rayEnds[1].m_vec[0].m_quad = _mm_or_ps(_mm_andnot_ps(v84, v57), _mm_and_ps(v86, v84));
            v87 = _mm_add_ps(_mm_mul_ps(v59, v80), _mm_mul_ps(v58, v82));
            fQuerya.m_rayEnds[0].m_vec[1].m_quad = _mm_or_ps(_mm_andnot_ps(v85, v58), _mm_and_ps(v87, v85));
            fQuerya.m_rayEnds[1].m_vec[1].m_quad = _mm_or_ps(_mm_andnot_ps(v84, v59), _mm_and_ps(v87, v84));
            v88 = _mm_add_ps(_mm_mul_ps(v61, v80), _mm_mul_ps(v60, v82));
            v89 = (hkpMoppRayBundleVirtualMachine::QueryBundle *)&v210;
            v90 = v51;
            __that[0] = &fQuerya;
            fQuerya.m_rayEnds[0].m_vec[2].m_quad = _mm_or_ps(_mm_andnot_ps(v85, v60), _mm_and_ps(v88, v85));
            v91 = _mm_and_ps((__m128)v66, v217);
            fQuerya.m_rayEnds[1].m_vec[2].m_quad = _mm_or_ps(_mm_andnot_ps(v84, v61), _mm_and_ps(v88, v84));
            v92 = _mm_or_ps(_mm_and_ps(::query.m_quad, v217), _mm_andnot_ps(v217, (__m128)0i64));
            v93 = _mm_or_ps(_mm_and_ps(v91, ::query.m_quad), _mm_andnot_ps(v91, (__m128)0i64));
            v94 = _mm_add_ps(_mm_shuffle_ps(v92, v92, 78), v92);
            v95 = _mm_add_ps(_mm_shuffle_ps(v93, v93, 78), v93);
            v93.m128_f32[0] = COERCE_FLOAT(_mm_shuffle_ps(v95, v95, 177)) + v95.m128_f32[0];
            if ( (float)(v93.m128_f32[0] + v93.m128_f32[0]) < (float)(COERCE_FLOAT(_mm_shuffle_ps(v94, v94, 177))
                                                                    + v94.m128_f32[0]) )
            {
              v90 = v13;
              v89 = &fQuerya;
              __that[0] = (hkpMoppRayBundleVirtualMachine::QueryBundle *)&v210;
              v13 = v51;
            }
            hkpMoppRayBundleVirtualMachine::queryRayOnTree(v8, v7, (const char *)v45 + v90, v89, chunkId);
            v96 = v220->m_FtoBScale.m_quad;
            v97 = v220->m_FtoBoffset.m_quad;
            v98 = v219->m_earlyOutHitFraction.m_quad;
            v99 = __that[0];
            v100 = (__m128 *)v219->m_code;
            v101 = _mm_sub_ps(::query.m_quad, v98);
            v102 = _mm_cmpltps(v219->m_earlyOutHitFraction.m_quad, ::query.m_quad);
            v103 = v219->m_from.m_vec[1].m_quad;
            __that[0]->m_rayEnds[1].m_vec[0].m_quad = _mm_or_ps(
                                                        _mm_and_ps(
                                                          _mm_sub_ps(
                                                            _mm_mul_ps(
                                                              _mm_sub_ps(
                                                                _mm_add_ps(
                                                                  _mm_mul_ps(v219->m_to.m_vec[0].m_quad, v98),
                                                                  _mm_mul_ps(v219->m_from.m_vec[0].m_quad, v101)),
                                                                _mm_shuffle_ps(v100[1], v100[1], 0)),
                                                              _mm_shuffle_ps(v96, v96, 0)),
                                                            _mm_shuffle_ps(v97, v97, 0)),
                                                          v102),
                                                        _mm_andnot_ps(v102, __that[0]->m_rayEnds[1].m_vec[0].m_quad));
            v104 = _mm_or_ps(
                     _mm_and_ps(
                       _mm_sub_ps(
                         _mm_mul_ps(
                           _mm_sub_ps(
                             _mm_add_ps(_mm_mul_ps(v219->m_to.m_vec[1].m_quad, v98), _mm_mul_ps(v103, v101)),
                             _mm_shuffle_ps(v100[1], v100[1], 85)),
                           _mm_shuffle_ps(v96, v96, 85)),
                         _mm_shuffle_ps(v97, v97, 85)),
                       v102),
                     _mm_andnot_ps(v102, v99->m_rayEnds[1].m_vec[1].m_quad));
            v105 = v219->m_from.m_vec[2].m_quad;
            v99->m_rayEnds[1].m_vec[1].m_quad = v104;
            v106 = v100[1];
            v107 = v196;
            v99->m_rayEnds[1].m_vec[2].m_quad = _mm_or_ps(
                                                  _mm_and_ps(
                                                    _mm_sub_ps(
                                                      _mm_mul_ps(
                                                        _mm_sub_ps(
                                                          _mm_add_ps(
                                                            _mm_mul_ps(v219->m_to.m_vec[2].m_quad, v98),
                                                            _mm_mul_ps(v105, v101)),
                                                          _mm_shuffle_ps(v106, v106, 170)),
                                                        _mm_shuffle_ps(v96, v96, 170)),
                                                      _mm_shuffle_ps(v97, v97, 170)),
                                                    v102),
                                                  _mm_andnot_ps(v102, v99->m_rayEnds[1].m_vec[2].m_quad));
            if ( (signed int)v107 < 3 )
            {
              v108 = v99->m_rayEnds[0].m_vec[v107 + 3].m_quad;
              v109 = _mm_cmpltps(v199, v108);
              v99->m_activeMask.m_mask = _mm_and_ps(
                                           (__m128)_mm_cmpeq_epi32(
                                                     (__m128i)_mm_and_ps(
                                                                _mm_and_ps(
                                                                  _mm_or_ps(
                                                                    _mm_andnot_ps(v109, _mm_cmpltps(v207, v206)),
                                                                    _mm_and_ps(_mm_cmpltps(v108, v197), v109)),
                                                                  _mm_and_ps(v208, v209)),
                                                                v102),
                                                     (__m128i)0i64),
                                           v99->m_activeMask.m_mask);
            }
            if ( !_mm_movemask_ps(v99->m_activeMask.m_mask) )
              return;
            v6 = (hkpMoppRayBundleVirtualMachine::QueryBundle *)((char *)v45 + v13);
            hkpMoppRayBundleVirtualMachine::QueryBundle::operator=(v5, v99);
            v7 = v220;
            v8 = v219;
          }
          break;
        case 38:
        case 39:
        case 40:
          v6 = __that[0];
          v115 = LODWORD(v195) - 38;
          v119 = _mm_shuffle_ps(v16, v16, 85);
          v120 = _mm_shuffle_ps(v16, v16, 170);
          goto LABEL_33;
        case 41:
        case 42:
        case 43:
          v110 = (unsigned __int8)v6->m_rayEnds[0].m_vec[0].m_quad.m128_i8[4] << 8;
          v196 = LODWORD(v195) - 41;
          v111 = (unsigned __int8)v6->m_rayEnds[0].m_vec[0].m_quad.m128_i8[6]
               + (((unsigned __int8)v6->m_rayEnds[0].m_vec[0].m_quad.m128_i8[5] + v110) << 8);
          v112 = LODWORD(v195) - 41;
          v6 = (hkpMoppRayBundleVirtualMachine::QueryBundle *)((char *)v6 + 7);
          v195 = (float)(v9 + ((v13 + (v12 << 8)) << 8));
          v113 = _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(v195), (__m128)LODWORD(v195), 0), v8->m_ItoFScale.m_quad);
          v195 = (float)v111;
          v114 = (__m128)`hkVector4f::getComponent::`2::indexToMask[v112];
          v115 = v196;
          v116 = _mm_and_ps(v114, v7->m_FtoBoffset.m_quad);
          v117 = _mm_or_ps(_mm_shuffle_ps(v116, v116, 78), v116);
          v118 = _mm_or_ps(_mm_shuffle_ps(v117, v117, 177), v117);
          v119 = _mm_sub_ps(_mm_mul_ps(v113, v7->m_FtoBScale.m_quad), v118);
          v120 = _mm_sub_ps(
                   _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_shuffle_ps(
                         (__m128)COERCE_UNSIGNED_INT((float)v111),
                         (__m128)COERCE_UNSIGNED_INT((float)v111),
                         0),
                       v8->m_ItoFScale.m_quad),
                     v7->m_FtoBScale.m_quad),
                   v118);
LABEL_33:
          v206 = v119;
          v122 = v5->m_rayEnds[0].m_vec[v115 + 3i64].m_quad;
          v209 = v5->m_rayEnds[0].m_vec[v115].m_quad;
          v121 = v209;
          v208 = v122;
          v207 = _mm_cmpltps(v209, v122);
          v200 = _mm_cmpleps(v122, v209);
          v123 = _mm_or_ps(_mm_cmpltps(v209, v119), _mm_cmpltps(v120, v122));
          v124 = _mm_and_ps(
                   (__m128)_mm_cmpeq_epi32(
                             (__m128i)_mm_or_ps(
                                        _mm_and_ps(_mm_or_ps(_mm_cmpltps(v122, v119), _mm_cmpltps(v120, v209)), v123),
                                        _mm_andnot_ps(v123, v207)),
                             (__m128i)0i64),
                   v5->m_activeMask.m_mask);
          v5->m_activeMask.m_mask = v124;
          if ( !_mm_movemask_ps(v124) )
            return;
          v125 = v5->m_rayEnds[0].m_vec[0].m_quad;
          v126 = v5->m_rayEnds[1].m_vec[0].m_quad;
          v127 = v5->m_rayEnds[0].m_vec[1].m_quad;
          v128 = v5->m_rayEnds[1].m_vec[1].m_quad;
          v129 = v5->m_rayEnds[1].m_vec[2].m_quad;
          v130 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
          v199 = v5->m_rayEnds[0].m_vec[2].m_quad;
          v131 = _mm_sub_ps(v121, v120);
          v132 = _mm_sub_ps(v122, v120);
          v133 = _mm_sub_ps(v131, v132);
          v134 = _mm_rcp_ps(v133);
          v135 = _mm_cmpltps(_mm_mul_ps(v132, v131), (__m128)0i64);
          v136 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v134, v133)), v134);
          v137 = v136;
          v138 = _mm_mul_ps(v136, v132);
          v139 = _mm_and_ps(v135, v200);
          v140 = _mm_and_ps(v135, v207);
          v141 = _mm_mul_ps(v137, v131);
          v142 = _mm_xor_ps(v138, v130);
          v143 = _mm_add_ps(_mm_mul_ps(v125, v142), _mm_mul_ps(v126, v141));
          v5->m_rayEnds[0].m_vec[0].m_quad = _mm_or_ps(_mm_and_ps(v143, v139), _mm_andnot_ps(v139, v125));
          v5->m_rayEnds[1].m_vec[0].m_quad = _mm_or_ps(
                                               _mm_and_ps(v143, v140),
                                               _mm_andnot_ps(v140, v5->m_rayEnds[1].m_vec[0].m_quad));
          v144 = _mm_add_ps(_mm_mul_ps(v127, v142), _mm_mul_ps(v128, v141));
          v5->m_rayEnds[0].m_vec[1].m_quad = _mm_or_ps(
                                               _mm_and_ps(v144, v139),
                                               _mm_andnot_ps(v139, v5->m_rayEnds[0].m_vec[1].m_quad));
          v145 = _mm_mul_ps(v199, v142);
          v5->m_rayEnds[1].m_vec[1].m_quad = _mm_or_ps(
                                               _mm_and_ps(v144, v140),
                                               _mm_andnot_ps(v140, v5->m_rayEnds[1].m_vec[1].m_quad));
          v146 = _mm_add_ps(v145, _mm_mul_ps(v129, v141));
          v147 = _mm_or_ps(_mm_and_ps(v146, v139), _mm_andnot_ps(v139, v5->m_rayEnds[0].m_vec[2].m_quad));
          v148 = v209;
          v5->m_rayEnds[0].m_vec[2].m_quad = v147;
          v5->m_rayEnds[1].m_vec[2].m_quad = _mm_or_ps(
                                               _mm_and_ps(v146, v140),
                                               _mm_andnot_ps(v140, v5->m_rayEnds[1].m_vec[2].m_quad));
          v149 = _mm_sub_ps(v148, v206);
          v150 = _mm_sub_ps(v208, v206);
          v151 = _mm_sub_ps(v149, v150);
          v152 = _mm_rcp_ps(v151);
          v153 = _mm_cmpltps(_mm_mul_ps(v150, v149), (__m128)0i64);
          v154 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v151, v152)), v152);
          v155 = v154;
          v156 = _mm_mul_ps(v154, v150);
          v157 = _mm_mul_ps(v155, v149);
          v158 = _mm_and_ps(v200, v153);
          v159 = _mm_xor_ps(v156, v130);
          v160 = _mm_and_ps(v207, v153);
          v161 = _mm_add_ps(_mm_mul_ps(v125, v159), _mm_mul_ps(v126, v157));
          v162 = _mm_add_ps(_mm_mul_ps(v127, v159), _mm_mul_ps(v128, v157));
          v5->m_rayEnds[0].m_vec[0].m_quad = _mm_or_ps(
                                               _mm_and_ps(v161, v160),
                                               _mm_andnot_ps(v160, v5->m_rayEnds[0].m_vec[0].m_quad));
          v5->m_rayEnds[1].m_vec[0].m_quad = _mm_or_ps(
                                               _mm_and_ps(v161, v158),
                                               _mm_andnot_ps(v158, v5->m_rayEnds[1].m_vec[0].m_quad));
          v5->m_rayEnds[0].m_vec[1].m_quad = _mm_or_ps(
                                               _mm_and_ps(v162, v160),
                                               _mm_andnot_ps(v160, v5->m_rayEnds[0].m_vec[1].m_quad));
          v163 = _mm_mul_ps(v199, v159);
          v5->m_rayEnds[1].m_vec[1].m_quad = _mm_or_ps(
                                               _mm_and_ps(v162, v158),
                                               _mm_andnot_ps(v158, v5->m_rayEnds[1].m_vec[1].m_quad));
          v164 = _mm_add_ps(v163, _mm_mul_ps(v129, v157));
          v5->m_rayEnds[0].m_vec[2].m_quad = _mm_or_ps(
                                               _mm_and_ps(v164, v160),
                                               _mm_andnot_ps(v160, v5->m_rayEnds[0].m_vec[2].m_quad));
          v5->m_rayEnds[1].m_vec[2].m_quad = _mm_or_ps(
                                               _mm_and_ps(v164, v158),
                                               _mm_andnot_ps(v158, v5->m_rayEnds[1].m_vec[2].m_quad));
          continue;
        case 48:
        case 49:
        case 50:
        case 51:
        case 52:
        case 53:
        case 54:
        case 55:
        case 56:
        case 57:
        case 58:
        case 59:
        case 60:
        case 61:
        case 62:
        case 63:
        case 64:
        case 65:
        case 66:
        case 67:
        case 68:
        case 69:
        case 70:
        case 71:
        case 72:
        case 73:
        case 74:
        case 75:
        case 76:
        case 77:
        case 78:
        case 79:
          v10 = LODWORD(v195) - 48;
          goto $add_Terminal_5;
        case 80:
          v10 = (unsigned __int8)v10;
          goto $add_Terminal_5;
        case 81:
          v10 = *(unsigned __int8 *)v197.m128_u64[0] + ((unsigned __int8)v10 << 8);
          goto $add_Terminal_5;
        case 82:
          v10 = v194 + ((*(unsigned __int8 *)v197.m128_u64[0] + ((unsigned __int8)v10 << 8)) << 8);
          goto $add_Terminal_5;
        case 83:
          v10 = (unsigned __int8)v6->m_rayEnds[0].m_vec[0].m_quad.m128_i8[4]
              + ((v194
                + ((*(unsigned __int8 *)v197.m128_u64[0]
                  + ((unsigned __int8)v6->m_rayEnds[0].m_vec[0].m_quad.m128_i8[1] << 8)) << 8)) << 8);
$add_Terminal_5:
          v177 = (v10 + v7->m_primitiveOffset) | v219->m_reindexingMask & (chunkId << 8);
          v178 = v219->m_rays;
          v179 = v178->m_rayShapeCollectionFilter;
          chunkIda = v177;
          if ( v179 )
          {
            v180 = v219->m_collection;
            v181 = 0i64;
            LODWORD(v193[0]) = v177;
            v212.m128_i32[0] = 0;
            v212.m128_u64[1] = 0i64;
            v213 = 0ui64;
            v212.m128_i32[0] = v178->m_filterInfo;
            if ( *(_BYTE *)v179->vfptr->isCollisionEnabled(
                             v179,
                             (hkBool *)&v194,
                             (hkpShapeRayCastInput *)&v210,
                             v180,
                             v193[0]) )
            {
              v182 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
              v183 = (hkLifoAllocator *)v182;
              v184 = (hkpMoppRayBundleVirtualMachine::QueryBundle *)*((_QWORD *)v182 + 3);
              v186 = __OFSUB__(v183->m_slabSize, 512);
              v185 = v183->m_slabSize - 512 < 0;
              __that[0] = v184;
              v187 = (unsigned __int64)&v184[4].m_rayEnds[1].m_vec[1];
              if ( v185 ^ v186 || (void *)v187 > v183->m_end )
              {
                v184 = (hkpMoppRayBundleVirtualMachine::QueryBundle *)hkLifoAllocator::allocateFromNewSlab(v183, 512);
                __that[0] = v184;
              }
              else
              {
                v183->m_cur = (void *)v187;
              }
              v188 = (__int64)v219->m_collection->vfptr->getChildShape(
                                v219->m_collection,
                                chunkIda,
                                (char (*)[512])v184);
              ++v219->m_rayResultPtr->m_outputs[0].m_shapeKeyIndex;
              ++v219->m_rayResultPtr->m_outputs[1].m_shapeKeyIndex;
              ++v219->m_rayResultPtr->m_outputs[2].m_shapeKeyIndex;
              ++v219->m_rayResultPtr->m_outputs[3].m_shapeKeyIndex;
              (*(void (__fastcall **)(__int64, __m128 *, hkpShapeRayBundleCastInput *, hkpShapeRayBundleCastOutput *, hkVector4fComparison *))(*(_QWORD *)v188 + 56i64))(
                v188,
                &v206,
                v219->m_rays,
                v219->m_rayResultPtr,
                &v5->m_activeMask);
              v189 = 1;
              v190 = &v219->m_earlyOutHitFraction.m_quad;
              v191 = 4i64;
              do
              {
                --v219->m_rayResultPtr->m_outputs[v181 / 0x14].m_shapeKeyIndex;
                if ( _mm_movemask_ps(v206) & v189 )
                {
                  *(float *)v190->m128_u64 = v219->m_rayResultPtr->m_outputs[v181 / 0x14].m_hitFraction;
                  v219->m_rayResultPtr->m_outputs[0].m_shapeKeys[v219->m_rayResultPtr->m_outputs[v181 / 0x14].m_shapeKeyIndex
                                                               + v181] = chunkIda;
                }
                v189 = __ROL4__(v189, 1);
                v190 = (__m128 *)((char *)v190 + 4);
                v181 += 20i64;
                --v191;
              }
              while ( v191 );
              v219->m_hitsFound.m_mask = _mm_or_ps(v219->m_hitsFound.m_mask, v206);
              v192 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
              if ( v192->m_slabSize < 512
                || &__that[0][4].m_rayEnds[1].m_vec[1] != v192->m_cur
                || v192->m_firstNonLifoEnd == __that[0] )
              {
                hkLifoAllocator::slowBlockFree(v192, __that[0], 512);
              }
              else
              {
                v192->m_cur = __that[0];
              }
            }
          }
          return;
        case 96:
        case 97:
        case 98:
        case 99:
          v6 = (hkpMoppRayBundleVirtualMachine::QueryBundle *)v197.m128_u64[0];
          v205[LODWORD(v195) - 96] = v10;
          goto $propertyCopy_5;
        case 100:
        case 101:
        case 102:
        case 103:
          v6 = __that[0];
          v205[LODWORD(v195) - 100] = v13 + (v10 << 8);
          goto $propertyCopy_5;
        case 104:
        case 105:
        case 106:
        case 107:
          v175 = (unsigned __int8)v6->m_rayEnds[0].m_vec[0].m_quad.m128_i8[4] + (v10 << 24) + (v13 << 16) + (v9 << 8);
          v6 = (hkpMoppRayBundleVirtualMachine::QueryBundle *)((char *)v6 + 5);
          v205[LODWORD(v195) - 104] = v175;
$propertyCopy_5:
          if ( v7 != (hkpMoppRayBundleVirtualMachine::QueryInt *)&v201 )
          {
            v201 = v7->m_FtoBoffset.m_quad;
            v202 = v7->m_shift;
            v203 = v7->m_FtoBScale.m_quad;
            v176 = v7->m_primitiveOffset;
            v7 = (hkpMoppRayBundleVirtualMachine::QueryInt *)&v201;
            v204 = v176;
            v220 = (hkpMoppRayBundleVirtualMachine::QueryInt *)&v201;
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
    v7 = v220;
    v8 = v219;
    goto LABEL_4;
  }
}ngcolors_mopp_1.m_bool )
  {
    v7 = v220;
    v8 = v219;
    goto LABEL_4;
  }
}

// File Line: 901
// RVA: 0xDB7330
hkVector4fComparison *__fastcall hkpMoppRayBundleVirtualMachine::queryRayBundle(hkpMoppRayBundleVirtualMachine *this, hkVector4fComparison *result, hkpShapeContainer *collection, hkpMoppCode *code, hkpShapeRayBundleCastInput *input, hkpShapeRayBundleCastOutput *rayResult, hkVector4fComparison *mask)
{
  hkVector4fComparison *v7; // rdi
  hkpMoppRayBundleVirtualMachine *v8; // rbx
  char *v9; // r8
  __m128 v10; // xmm3
  __m128 v11; // xmm2
  hkVector4f v12; // xmm1
  __m128 v13; // xmm2
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm0
  __m128 v17; // xmm2
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
  __m128 v32; // xmm0
  hkVector4fComparison *v33; // rax
  hkpMoppRayBundleVirtualMachine::QueryInt query; // [rsp+30h] [rbp-B8h]
  __m128 v35; // [rsp+70h] [rbp-78h]
  __m128 v36; // [rsp+80h] [rbp-68h]
  __m128 v37; // [rsp+90h] [rbp-58h]
  __m128 v38; // [rsp+A0h] [rbp-48h]
  __m128 v39; // [rsp+B0h] [rbp-38h]
  __m128 v40; // [rsp+C0h] [rbp-28h]
  __int64 v41; // [rsp+D0h] [rbp-18h]

  this->m_rayResultPtr = rayResult;
  this->m_collection = collection;
  v7 = result;
  v8 = this;
  this->m_earlyOutHitFraction = (hkVector4f)::query.m_quad;
  this->m_from.m_vec[0] = input->m_from.m_vertices[0];
  this->m_from.m_vec[1] = input->m_from.m_vertices[1];
  this->m_from.m_vec[2] = input->m_from.m_vertices[2];
  this->m_to.m_vec[0] = input->m_to.m_vertices[0];
  this->m_to.m_vec[1] = input->m_to.m_vertices[1];
  this->m_to.m_vec[2] = input->m_to.m_vertices[2];
  this->m_code = code;
  v9 = code->m_data.m_data;
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
  v17 = this->m_from.m_vec[0].m_quad;
  v18 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v16), v15);
  v19 = this->m_to.m_vec[0].m_quad;
  v20.m_quad = _mm_mul_ps(v18, v10);
  v21.m_offset.m_quad = (__m128)code->m_info;
  query.m_FtoBScale = (hkVector4f)v20.m_quad;
  v22 = _mm_shuffle_ps(v21.m_offset.m_quad, v21.m_offset.m_quad, 0);
  v23 = _mm_sub_ps(v19, v22);
  v24 = _mm_sub_ps(v17, v22);
  v25 = _mm_shuffle_ps(v21.m_offset.m_quad, v21.m_offset.m_quad, 85);
  v26 = _mm_shuffle_ps(v21.m_offset.m_quad, v21.m_offset.m_quad, 170);
  v35 = _mm_mul_ps(v24, v20.m_quad);
  v27 = this->m_from.m_vec[1].m_quad;
  v38 = _mm_mul_ps(v23, v20.m_quad);
  v28 = this->m_to.m_vec[1].m_quad;
  v36 = _mm_mul_ps(_mm_sub_ps(v27, v25), v20.m_quad);
  v29 = _mm_mul_ps(_mm_sub_ps(v28, v25), v20.m_quad);
  v30 = _mm_sub_ps(this->m_to.m_vec[2].m_quad, v26);
  v39 = v29;
  v31 = _mm_sub_ps(this->m_from.m_vec[2].m_quad, v26);
  v40 = _mm_mul_ps(v30, v20.m_quad);
  v32 = mask->m_mask;
  this->m_rays = input;
  v37 = _mm_mul_ps(v31, v20.m_quad);
  _mm_store_si128((__m128i *)&v41, (__m128i)v32);
  this->m_hitsFound = 0i64;
  *(_QWORD *)&query.m_primitiveOffset = 0i64;
  query.m_shift = 0;
  this->m_reindexingMask = (*v9 != 13) - 1;
  hkpMoppRayBundleVirtualMachine::queryRayOnTree(
    this,
    &query,
    v9,
    (hkpMoppRayBundleVirtualMachine::QueryBundle *const )&v35,
    0);
  v33 = v7;
  _mm_store_si128((__m128i *)v7, (__m128i)v8->m_hitsFound.m_mask);
  return v33;
}

