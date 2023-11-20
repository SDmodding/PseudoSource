// File Line: 42
// RVA: 0x1453D10
__int64 Render::_dynamic_initializer_for__gTaskFunctionDecl_SoftbodySkinBufferTask__()
{
  UFG::qTaskFunctionDecl::qTaskFunctionDecl(
    &Render::gTaskFunctionDecl_SoftbodySkinBufferTask,
    &Render::gTaskFunctionDeclData_SoftbodySkinBufferTask);
  return atexit(Render::_dynamic_atexit_destructor_for__gTaskFunctionDecl_SoftbodySkinBufferTask__);
}

// File Line: 216
// RVA: 0x23A20
void __fastcall Render::ApplySpringConstraints(__m128 *spring_data, unsigned int spring_size, __m128 *v_zero, __m128 *v_minus_half, __m128 *v_one, __m128 *v_minus_one, __m128 *v_sign_bit, __m128 *v_w_mask, __m128 *v_one_over_4096, unsigned int worker_id, Render::VerletVert *verlet_vertices)
{
  Render::VerletVert *v11; // r15
  __m128 *v12; // r12
  __m128 *v13; // r13
  unsigned int v14; // eax
  signed int v15; // er8
  unsigned int v16; // er9
  __m128 *v17; // rbx
  float v18; // er10
  __m128 v19; // xmm7
  int v20; // ebp
  __m128 v21; // xmm7
  unsigned int v22; // eax
  int v23; // er14
  __int64 v24; // rcx
  unsigned int v25; // esi
  __int64 v26; // r8
  unsigned int v27; // eax
  int v28; // er10
  unsigned int v29; // er9
  __m128 v30; // ST10_16
  __m128 v31; // xmm8
  __m128 v32; // xmm13
  __m128 v33; // xmm11
  unsigned int v34; // eax
  unsigned int v35; // er11
  __int64 v36; // r8
  signed __int64 v37; // rdx
  __m128 v38; // xmm12
  signed __int64 v39; // rdi
  __m128 v40; // xmm6
  __m128 v41; // xmm10
  __m128 v42; // xmm5
  signed __int64 v43; // rdx
  __m128 v44; // xmm14
  __m128 v45; // xmm15
  __m128 v46; // xmm13
  __m128 v47; // xmm12
  __m128 v48; // xmm14
  __m128 v49; // xmm15
  __m128 v50; // xmm4
  __m128 v51; // xmm3
  __m128 v52; // xmm2
  __m128 v53; // xmm4
  __m128 v54; // xmm2
  __m128 v55; // xmm0
  __m128 v56; // xmm7
  __m128 v57; // xmm8
  __m128 v58; // xmm7
  __m128 v59; // xmm4
  __m128 v60; // xmm5
  __m128 v61; // xmm2
  __m128 v62; // xmm1
  __m128 v63; // xmm7
  __m128 v64; // xmm5
  bool v65; // zf
  __m128i *v66; // rcx
  unsigned int v67; // er8
  unsigned int v68; // er9
  __int16 v69; // bp
  unsigned int v70; // eax
  __m128 v71; // xmm8
  unsigned int v72; // ebx
  unsigned int v73; // edi
  __int64 v74; // rcx
  unsigned __int16 v75; // r14
  __m128 v76; // xmm8
  unsigned __int16 v77; // bp
  unsigned __int16 v78; // r9
  __m128 v79; // xmm6
  __m128 v80; // xmm9
  __m128 v81; // xmm10
  unsigned __int8 v82; // r11
  unsigned __int8 v83; // bl
  signed __int64 v84; // r8
  unsigned __int8 v85; // di
  __m128 v86; // xmm8
  __m128 v87; // xmm4
  __m128 v88; // xmm5
  __m128 v89; // xmm2
  __m128 v90; // xmm0
  __m128 v91; // xmm1
  __m128 v92; // xmm3
  __m128 v93; // xmm2
  unsigned int v94; // eax
  signed __int64 v95; // r8
  signed __int64 v96; // rcx
  __m128 v97; // xmm5
  __m128 v98; // xmm3
  __m128 v99; // xmm0
  __m128 v100; // xmm1
  __m128 v101; // xmm4
  __m128 v102; // xmm2
  unsigned int v103; // eax
  signed __int64 v104; // r8
  signed __int64 v105; // rcx
  __m128 v106; // xmm5
  __m128 v107; // xmm3
  __m128 v108; // xmm0
  __m128 v109; // xmm1
  __m128 v110; // xmm4
  __m128 v111; // xmm2
  unsigned int v112; // eax
  signed __int64 v113; // rcx
  signed __int64 v114; // r8
  __m128 v115; // xmm5
  __m128 v116; // xmm3
  __m128 v117; // xmm0
  __m128 v118; // xmm1
  __m128 v119; // xmm4
  __m128 v120; // xmm2
  __int64 v121; // [rsp+0h] [rbp-F8h]
  __m128 *v122; // [rsp+100h] [rbp+8h]
  unsigned int v123; // [rsp+108h] [rbp+10h]
  Render::VerletVert *verlet_verticesa; // [rsp+150h] [rbp+58h]

  v122 = spring_data;
  v11 = verlet_vertices;
  v12 = v_zero;
  v13 = v_minus_half;
  v14 = 0;
  v15 = (spring_size >> 4) - 1;
  v16 = 0;
  v121 = v15;
  if ( v15 > 0 )
  {
    v17 = (__m128 *)((char *)spring_data + 12);
    v123 = (spring_size >> 4) - 1;
    verlet_verticesa = (Render::VerletVert *)((char *)&spring_data->m128_u64[1] + 4);
    do
    {
      v18 = v17[-1].m128_f32[3];
      v19 = _mm_add_ps(
              _mm_mul_ps(
                _mm_cvtepi32_ps(
                  _mm_srai_epi32(
                    _mm_unpacklo_epi16(*(__m128i *)((char *)&v17[-1] + 4), *(__m128i *)((char *)&v17[-1] + 4)),
                    0x10u)),
                *v_one_over_4096),
              *v12);
      v20 = HIWORD(v18) & 0x3FFF;
      v21 = _mm_add_ps(_mm_mul_ps(v19, v19), *v12);
      v22 = (LODWORD(v18) >> 30) + v14;
      v23 = (LODWORD(v17->m128_u64[0]) >> 16) & 0x3FFF;
      v24 = v22;
      v25 = v22;
      v26 = v22 - v20;
      v27 = (unsigned __int16)(LOWORD(v18) >> 14) + v22;
      v28 = v17[-1].m128_i32[3] & 0x3FFF;
      v29 = v27;
      v24 *= 32i64;
      v30 = v11[v26].mPosition;
      v31 = v11[v27].mPosition;
      v32 = _mm_sub_ps(v30, *(__m128 *)((char *)&v11->mPosition + v24));
      v33 = v11[v27 - v28].mPosition;
      v34 = (LODWORD(v17->m128_u64[0]) >> 30) + v27;
      v35 = v34;
      v36 = v34 - v23;
      v37 = v34;
      v14 = ((unsigned __int16)LODWORD(v17->m128_u64[0]) >> 14) + v34;
      v38 = _mm_sub_ps(v33, v31);
      v39 = v14;
      v40 = v11[v37].mPosition;
      v41 = v11[v36].mPosition;
      v42 = v11[v39].mPosition;
      v43 = v14 - (v17->m128_u64[0] & 0x3FFF);
      v44 = _mm_sub_ps(v41, v40);
      v45 = _mm_sub_ps(v11[v43].mPosition, v42);
      v46 = _mm_shuffle_ps(v32, _mm_shuffle_ps(v32, *v12, 250), 148);
      v47 = _mm_shuffle_ps(v38, _mm_shuffle_ps(v38, *v12, 250), 148);
      v48 = _mm_shuffle_ps(v44, _mm_shuffle_ps(v44, *v12, 250), 148);
      v49 = _mm_shuffle_ps(v45, _mm_shuffle_ps(v45, *v12, 250), 148);
      v50 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v47, v47, 0), gVmxIdentity1_2),
                  _mm_add_ps(_mm_mul_ps(v46, gVmxIdentity0_2), *v12)),
                _mm_mul_ps(_mm_shuffle_ps(v48, v48, 0), gVmxIdentity2_2)),
              _mm_mul_ps(_mm_shuffle_ps(v49, v49, 0), gVmxIdentity3_2));
      v51 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v46, v46, 85), gVmxIdentity0_2), *v12),
                  _mm_mul_ps(v47, gVmxIdentity1_2)),
                _mm_mul_ps(_mm_shuffle_ps(v48, v48, 85), gVmxIdentity2_2)),
              _mm_mul_ps(_mm_shuffle_ps(v49, v49, 85), gVmxIdentity3_2));
      v52 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v46, v46, 170), gVmxIdentity0_2), *v12),
                  _mm_mul_ps(_mm_shuffle_ps(v47, v47, 170), gVmxIdentity1_2)),
                _mm_mul_ps(v48, gVmxIdentity2_2)),
              _mm_mul_ps(_mm_shuffle_ps(v49, v49, 170), gVmxIdentity3_2));
      v53 = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(v50, v50), *v12), _mm_mul_ps(v51, v51)), _mm_mul_ps(v52, v52));
      v54 = *(__m128 *)((char *)&v11->mPosition + v24);
      v55 = _mm_add_ps(_mm_mul_ps(_mm_rcp_ps(_mm_add_ps(v53, v21)), v21), *v13);
      v56 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v54, v54, 255), gVmxIdentity0_2), *v12),
                    _mm_mul_ps(_mm_shuffle_ps(v31, v31, 255), gVmxIdentity1_2)),
                  _mm_mul_ps(_mm_shuffle_ps(v40, v40, 255), gVmxIdentity2_2)),
                _mm_mul_ps(_mm_shuffle_ps(v42, v42, 255), gVmxIdentity3_2)),
              *v_minus_one);
      v57 = *v12;
      v58 = _mm_add_ps(_mm_mul_ps(v56, v55), *v12);
      v59 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v58, v58, 85), v47), *v12);
      v60 = _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_or_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v30, v30, 255), gVmxIdentity0_2), *v12),
                          _mm_mul_ps(_mm_shuffle_ps(v33, v33, 255), gVmxIdentity1_2)),
                        _mm_mul_ps(_mm_shuffle_ps(v41, v41, 255), gVmxIdentity2_2)),
                      _mm_mul_ps(_mm_shuffle_ps(v11[v43].mPosition, v11[v43].mPosition, 255), gVmxIdentity3_2)),
                    *v_sign_bit),
                  *v_one),
                v55),
              *v12);
      v11[v25].mPosition = _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v58, v58, 0), v46), *v12), v54);
      v11[v25 - v20].mPosition = _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v60, v60, 0), v46), v57), v30);
      v61 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v58, v58, 170), v48), *v12);
      v62 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v60, v60, 170), v48), *v12);
      v11[v29].mPosition = _mm_add_ps(v59, v11[v29].mPosition);
      v11[v29 - v28].mPosition = _mm_add_ps(
                                   _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v60, v60, 85), v47), v57),
                                   v11[v29 - v28].mPosition);
      v63 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v58, v58, 255), v49), *v12);
      v64 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v60, v60, 255), v49), *v12);
      v11[v35].mPosition = _mm_add_ps(v61, v11[v35].mPosition);
      v11[v35 - v23].mPosition = _mm_add_ps(v11[v35 - v23].mPosition, v62);
      v17 = &verlet_verticesa->m_S0_output;
      v65 = v121-- == 1;
      verlet_verticesa = (Render::VerletVert *)((char *)verlet_verticesa + 16);
      v11[v39].mPosition = _mm_add_ps(v63, v11[v39].mPosition);
      v11[v43].mPosition = _mm_add_ps(v64, v11[v43].mPosition);
    }
    while ( !v65 );
    v16 = v123;
  }
  v66 = (__m128i *)&v122[v16];
  v67 = v66->m128i_i64[1];
  v68 = HIDWORD(v66->m128i_i64[1]);
  v69 = WORD2(v66->m128i_i64[1]);
  v70 = (v67 >> 30) + v14;
  v71 = _mm_add_ps(
          _mm_mul_ps(_mm_cvtepi32_ps(_mm_srai_epi32(_mm_unpacklo_epi16(*v66, *v66), 0x10u)), *v_one_over_4096),
          *v12);
  v72 = v68 >> 30;
  v73 = v68 >> 14;
  v74 = v70 - ((v67 >> 16) & 0x3FFF);
  v75 = v67 & 0x3FFF;
  v76 = _mm_add_ps(_mm_mul_ps(v71, v71), *v12);
  v77 = v69 & 0x3FFF;
  v78 = HIWORD(v68) & 0x3FFF;
  v79 = _mm_shuffle_ps(v76, v76, 0);
  v80 = _mm_shuffle_ps(v76, v76, 85);
  v81 = _mm_shuffle_ps(v76, v76, 170);
  v82 = (v67 >> 14) & 3;
  v83 = v72 & 3;
  v84 = v70;
  v85 = v73 & 3;
  v74 *= 32i64;
  v86 = _mm_shuffle_ps(v76, v76, 255);
  v87 = v11[v84].mPosition;
  v88 = *(__m128 *)((char *)&v11->mPosition + v74);
  v89 = _mm_sub_ps(*(__m128 *)((char *)&v11->mPosition + v74), v87);
  v90 = _mm_add_ps(_mm_mul_ps(v89, v89), *v12);
  v91 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v90, v90, 85), v90), _mm_shuffle_ps(v90, v90, 170));
  v92 = _mm_and_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_add_ps(_mm_mul_ps(_mm_rcp_ps(_mm_add_ps(_mm_shuffle_ps(v91, v91, 0), v79)), v79), *v13), v89),
            *v12),
          *v_w_mask);
  v93 = _mm_mul_ps(_mm_sub_ps(*v_one, _mm_shuffle_ps(v88, v88, 255)), v92);
  v11[v84].mPosition = _mm_add_ps(
                         _mm_mul_ps(_mm_sub_ps(_mm_shuffle_ps(v11[v84].mPosition, v87, 255), *v_one), v92),
                         v87);
  *(__m128 *)((char *)&v11->mPosition + v74) = _mm_add_ps(v93, v88);
  if ( v75 )
  {
    v94 = v82 + v70;
    v95 = v94 - v75;
    v96 = v94;
    v97 = v11[v96].mPosition;
    v98 = _mm_sub_ps(v11[v95].mPosition, v97);
    v99 = _mm_add_ps(_mm_mul_ps(v98, v98), *v12);
    v100 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v99, v99, 85), v99), _mm_shuffle_ps(v99, v99, 170));
    v101 = _mm_and_ps(
             _mm_add_ps(
               _mm_mul_ps(
                 _mm_add_ps(_mm_mul_ps(_mm_rcp_ps(_mm_add_ps(_mm_shuffle_ps(v100, v100, 0), v80)), v80), *v13),
                 v98),
               *v12),
             *v_w_mask);
    v102 = _mm_add_ps(
             _mm_mul_ps(_mm_sub_ps(*v_one, _mm_shuffle_ps(v11[v95].mPosition, v11[v95].mPosition, 255)), v101),
             v11[v95].mPosition);
    v11[v96].mPosition = _mm_add_ps(
                           _mm_mul_ps(_mm_sub_ps(_mm_shuffle_ps(v11[v96].mPosition, v97, 255), *v_one), v101),
                           v97);
    v11[v95].mPosition = v102;
    if ( v78 )
    {
      v103 = v83 + v94;
      v104 = v103 - v78;
      v105 = v103;
      v106 = v11[v105].mPosition;
      v107 = _mm_sub_ps(v11[v104].mPosition, v106);
      v108 = _mm_add_ps(_mm_mul_ps(v107, v107), *v12);
      v109 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v108, v108, 85), v108), _mm_shuffle_ps(v108, v108, 170));
      v110 = _mm_and_ps(
               _mm_add_ps(
                 _mm_mul_ps(
                   _mm_add_ps(_mm_mul_ps(_mm_rcp_ps(_mm_add_ps(_mm_shuffle_ps(v109, v109, 0), v81)), v81), *v13),
                   v107),
                 *v12),
               *v_w_mask);
      v111 = _mm_add_ps(
               _mm_mul_ps(_mm_sub_ps(*v_one, _mm_shuffle_ps(v11[v104].mPosition, v11[v104].mPosition, 255)), v110),
               v11[v104].mPosition);
      v11[v105].mPosition = _mm_add_ps(
                              _mm_mul_ps(_mm_sub_ps(_mm_shuffle_ps(v11[v105].mPosition, v106, 255), *v_one), v110),
                              v106);
      v11[v104].mPosition = v111;
      if ( v77 )
      {
        v112 = v85 + v103;
        v113 = v112;
        v114 = v112 - v77;
        v115 = v11[v113].mPosition;
        v116 = _mm_sub_ps(v11[v114].mPosition, v115);
        v117 = _mm_add_ps(_mm_mul_ps(v116, v116), *v12);
        v118 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v117, v117, 85), v117), _mm_shuffle_ps(v117, v117, 170));
        v119 = _mm_and_ps(
                 _mm_add_ps(
                   _mm_mul_ps(
                     _mm_add_ps(_mm_mul_ps(_mm_rcp_ps(_mm_add_ps(_mm_shuffle_ps(v118, v118, 0), v86)), v86), *v13),
                     v116),
                   *v12),
                 *v_w_mask);
        v120 = _mm_add_ps(
                 _mm_mul_ps(_mm_sub_ps(*v_one, _mm_shuffle_ps(v11[v114].mPosition, v11[v114].mPosition, 255)), v119),
                 v11[v114].mPosition);
        v11[v113].mPosition = _mm_add_ps(
                                _mm_mul_ps(_mm_sub_ps(_mm_shuffle_ps(v11[v113].mPosition, v115, 255), *v_one), v119),
                                v115);
        v11[v114].mPosition = v120;
      }
    }
  }
}

// File Line: 559
// RVA: 0x21E40
void __fastcall Render::SoftbodySkinBufferTask(int worker_id, UFG::qMemoryStreamer *memory_streamer, void *param0, void *param1)
{
  unsigned __int64 v4; // rbp
  __int64 v5; // r10
  __m128 v6; // xmm10
  bool v7; // zf
  unsigned int v8; // edi
  __m128 v9; // xmm15
  __m128 v10; // xmm7
  __m128 v11; // xmm14
  unsigned int v12; // esi
  __int64 v13; // r13
  __int64 v14; // r14
  __m128 v15; // xmm13
  __m128i v16; // xmm12
  __m128 v17; // xmm8
  __int64 v18; // rax
  __m128 v19; // xmm9
  __m128 v20; // xmm11
  __m128 **v21; // r15
  float v22; // xmm5_4
  float v23; // xmm6_4
  float v24; // xmm5_4
  float v25; // xmm3_4
  float v26; // xmm6_4
  float v27; // xmm4_4
  float v28; // xmm2_4
  float v29; // xmm6_4
  float v30; // xmm0_4
  float v31; // xmm3_4
  __m128 v32; // xmm1
  __m128i v33; // xmm0
  unsigned int v34; // eax
  __int64 v35; // r12
  unsigned __int8 *v36; // r9
  __m128 *v37; // rdx
  __int64 v38; // r11
  int v39; // er8
  __int64 v40; // rcx
  __m128 *v41; // rax
  __m128 v42; // xmm5
  __m128 v43; // xmm11
  __m128 v44; // xmm12
  __m128 v45; // xmm13
  __m128 v46; // xmm4
  __m128 v47; // xmm3
  __m128 v48; // xmm8
  __m128 v49; // xmm2
  __m128 v50; // xmm5
  __m128 v51; // xmm1
  __m128 v52; // xmm6
  __m128 v53; // xmm7
  __m128 v54; // xmm8
  __m128 v55; // xmm6
  __m128 v56; // xmm10
  __m128 v57; // xmm5
  __m128 v58; // xmm4
  __m128 v59; // xmm10
  __m128 v60; // xmm5
  __m128 v61; // xmm4
  __m128 v62; // xmm4
  __m128 v63; // xmm5
  __m128 v64; // xmm10
  __m128 v65; // xmm14
  __m128 v66; // xmm1
  float v67; // xmm10_4
  __m128 v68; // xmm6
  unsigned int v69; // er12
  int v70; // edx
  __m128 *v71; // rax
  unsigned __int16 *v72; // rax
  int v73; // ecx
  int v74; // er9
  unsigned __int64 v75; // rbx
  unsigned __int64 v76; // r11
  unsigned int v77; // er8
  unsigned __int64 v78; // rax
  unsigned __int64 v79; // rcx
  unsigned __int64 v80; // rbx
  unsigned __int64 v81; // r11
  __int64 v82; // rax
  __m128 v83; // xmm5
  __m128 v84; // xmm4
  __m128 *v85; // r14
  signed __int16 *v86; // rdi
  __m128 v87; // xmm4
  __int64 v88; // r13
  __m128 *v89; // rdx
  unsigned __int64 v90; // rcx
  unsigned int v91; // er8
  int v92; // ecx
  unsigned __int64 v93; // rbx
  __m128 v94; // xmm1
  __m128 *v95; // r9
  __int64 v96; // rcx
  __m128 v97; // xmm7
  __int64 v98; // rdx
  __int64 v99; // r8
  __m128 v100; // xmm0
  __m128 v101; // xmm1
  __m128 v102; // xmm12
  __m128i v103; // xmm2
  __int64 v104; // r9
  __m128i v105; // xmm2
  __m128 v106; // xmm0
  __m128 v107; // xmm1
  __m128 v108; // xmm11
  __m128 v109; // xmm0
  __m128 v110; // xmm1
  __m128 v111; // xmm14
  __m128 v112; // xmm0
  __m128 v113; // xmm1
  __m128 v114; // xmm13
  __m128 v115; // xmm1
  __m128 v116; // xmm0
  __m128 v117; // xmm3
  __m128 v118; // xmm15
  __m128 v119; // xmm0
  __m128 v120; // xmm3
  __m128 v121; // xmm1
  __m128 v122; // xmm0
  __m128 v123; // xmm4
  __m128 v124; // xmm1
  __m128 v125; // xmm0
  __m128 v126; // xmm8
  __m128 v127; // xmm9
  __m128 v128; // xmm10
  __m128 v129; // xmm5
  __m128 v130; // xmm6
  __m128 v131; // xmm7
  __m128 v132; // xmm1
  __m128 v133; // xmm2
  __m128 v134; // xmm3
  __m128 v135; // xmm1
  __m128 v136; // xmm0
  __m128 v137; // xmm3
  __m128 v138; // xmm6
  __m128 v139; // xmm4
  __m128 v140; // xmm6
  __m128 v141; // xmm0
  __m128 v142; // xmm5
  __m128 v143; // xmm2
  __m128 v144; // xmm3
  __m128 v145; // xmm2
  __m128 v146; // xmm1
  __m128 v147; // xmm3
  __m128 v148; // xmm7
  __m128 v149; // xmm0
  __m128 v150; // xmm2
  __m128 v151; // xmm3
  __m128 v152; // xmm1
  __m128 v153; // xmm6
  __m128 v154; // xmm0
  __m128 v155; // xmm5
  __m128 v156; // xmm2
  __m128 v157; // xmm1
  __m128 v158; // xmm0
  __m128 v159; // xmm2
  __m128 v160; // xmm0
  __m128 v161; // xmm6
  __m128 v162; // xmm5
  __m128 v163; // xmm11
  __m128 v164; // xmm11
  float v165; // xmm15_4
  float v166; // xmm12_4
  unsigned int v167; // eax
  float v168; // xmm13_4
  float v169; // xmm9_4
  float v170; // xmm10_4
  float v171; // xmm7_4
  float v172; // xmm8_4
  float v173; // xmm6_4
  float v174; // xmm3_4
  float v175; // xmm2_4
  float v176; // xmm1_4
  float v177; // xmm4_4
  float v178; // xmm5_4
  float v179; // xmm3_4
  float v180; // xmm0_4
  float v181; // xmm7_4
  float v182; // xmm3_4
  float v183; // xmm2_4
  __m128i v184; // xmm0
  unsigned int v185; // eax
  float v186; // xmm4_4
  __m128i v187; // xmm1
  signed int v188; // eax
  float v189; // xmm2_4
  float v190; // xmm7_4
  float v191; // xmm3_4
  float v192; // xmm4_4
  __m128 v193; // xmm8
  float v194; // xmm9_4
  __m128 v195; // xmm7
  float v196; // xmm12_4
  float v197; // xmm10_4
  float v198; // xmm13_4
  float v199; // xmm5_4
  float v200; // xmm3_4
  __m128 v201; // xmm1
  __m128 v202; // xmm2
  float v203; // xmm4_4
  float v204; // xmm5_4
  __m128 v205; // xmm0
  float v206; // xmm3_4
  __m128 v207; // xmm5
  __m128 v208; // xmm4
  __m128 v209; // xmm7
  __m128 v210; // xmm1
  __m128 v211; // xmm1
  __m128 v212; // xmm1
  __m128 v213; // xmm5
  __m128 v214; // xmm7
  __m128 v215; // xmm3
  __m128 v216; // xmm2
  float v217; // xmm0_4
  signed int v218; // ecx
  __m128 v219; // xmm0
  __m128i v220; // xmm0
  __m128i v221; // xmm2
  __m128i v222; // xmm2
  __m128 v223; // xmm0
  __m128i v224; // xmm0
  __m128i v225; // xmm2
  __m128i v226; // xmm2
  unsigned int v227; // er13
  __m128 *v228; // rsi
  signed __int64 v229; // rbx
  __m128 *v230; // r8
  __int64 v231; // r9
  __m128 v232; // xmm2
  signed int v233; // ecx
  __m128 *v234; // r14
  __m128 *v235; // r10
  __m128 *v236; // r15
  signed int v237; // eax
  unsigned int v238; // er11
  unsigned int v239; // er9
  unsigned int v240; // edx
  __int64 v241; // r13
  __int64 v242; // r8
  __int64 v243; // rcx
  __m128 *v244; // rbx
  __int64 v245; // rax
  _OWORD *v246; // r10
  __int64 v247; // rcx
  __m128 *v248; // r11
  char v249; // al
  __m128 v250; // xmm8
  signed __int64 v251; // rcx
  signed __int64 v252; // r13
  __m128 v253; // xmm8
  __int64 v254; // rdx
  __m128 v255; // xmm1
  __m128 v256; // xmm8
  __m128i v257; // xmm7
  __m128 v258; // xmm3
  __m128 v259; // xmm4
  __m128 v260; // xmm5
  int v261; // edi
  int v262; // esi
  int v263; // er14
  int v264; // er15
  __m128 v265; // xmm2
  __m128 v266; // xmm8
  __m128 v267; // xmm13
  __m128 v268; // xmm10
  __m128 v269; // xmm11
  __m128 v270; // xmm10
  __int128 v271; // xmm1
  __m128 v272; // xmm12
  __m128 v273; // xmm9
  __m128 v274; // xmm2
  __m128 v275; // xmm5
  __m128 v276; // xmm7
  __m128 v277; // xmm9
  __int64 v278; // rax
  __int64 v279; // rdi
  __int64 v280; // rcx
  int v281; // er15
  __m128 v282; // xmm3
  __int64 v283; // rdx
  __m128 v284; // xmm4
  __m128 v285; // xmm3
  __m128 v286; // xmm4
  __m128 v287; // xmm4
  __m128 v288; // xmm5
  __m128 v289; // xmm6
  __m128 v290; // xmm8
  __m128 v291; // xmm7
  __m128 v292; // xmm2
  __m128 v293; // xmm3
  __m128 v294; // xmm4
  __m128 v295; // xmm2
  __m128 v296; // xmm5
  __m128 v297; // xmm6
  __m128 v298; // xmm7
  __m128 v299; // xmm10
  __m128 v300; // xmm8
  __m128 v301; // xmm3
  __m128 v302; // xmm2
  __m128 v303; // xmm0
  __m128 v304; // xmm5
  __m128 v305; // xmm3
  __m128 v306; // xmm1
  __m128 v307; // xmm8
  __m128 v308; // xmm2
  __m128 v309; // xmm4
  __m128 v310; // xmm8
  __m128 v311; // xmm3
  __m128 v312; // xmm2
  __m128 v313; // xmm0
  __m128 v314; // xmm1
  __m128 v315; // xmm8
  __m128 v316; // xmm2
  __m128 v317; // xmm8
  __m128 v318; // xmm11
  __m128i v319; // xmm2
  __m128i v320; // xmm0
  __m128 v321; // xmm0
  __m128 v322; // xmm3
  __m128 v323; // xmm0
  __m128 v324; // xmm3
  __m128i v325; // xmm2
  __m128i v326; // xmm2
  __m128i v327; // xmm2
  char v328; // [rsp+E0h] [rbp+0h]
  int v329; // [rsp+125B0h] [rbp+124D0h]

  v329 = worker_id;
  v4 = (unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64;
  v5 = *((_QWORD *)param0 + 10);
  v6 = gVmxOne_2;
  v7 = *((_QWORD *)param0 + 9) == 0i64;
  v8 = *((_DWORD *)param0 + 16);
  v9 = 0i64;
  v10 = gVmxMinusOne_0;
  v11 = gVmx127_0;
  v12 = *(_DWORD *)(v5 + 364);
  v13 = *(_QWORD *)(v5 + 392);
  v14 = *(_QWORD *)(v5 + 400);
  v15 = gVmxOneOver127_0;
  v16 = gVmxUnpackBias_0;
  v17 = (__m128)gVmxUnpackMask_0;
  *(_QWORD *)(v4 + 720) = *(_QWORD *)(v5 + 40);
  v18 = *(_QWORD *)(v5 + 24);
  v19 = gVmxUnpackUnbias_0;
  v20 = gVmxUnpackShift_0;
  *(__m128 *)(v4 + 672) = gVmxMinusHalf;
  v21 = (__m128 **)param0;
  *(_BYTE *)v4 = !v7;
  *(_DWORD *)(v4 + 12) = v8;
  *(_OWORD *)(v4 + 656) = 0i64;
  *(__m128 *)(v4 + 160) = gVmxOne_2;
  *(_DWORD *)(v4 + 96) = v12;
  *(_QWORD *)(v4 + 208) = v18;
  *(__m128 *)(v4 + 736) = gVmxOneOver255_0;
  *(__m128 *)(v4 + 704) = gVmxOne_2;
  *(__m128 *)(v4 + 304) = gVmxOneOver4096_0;
  *(__m128 *)(v4 + 624) = gVmxMinusOne_0;
  *(__m128i *)(v4 + 592) = gVmxAbsMask;
  *(__m128 *)(v4 + 640) = gVmxMinusOne_0;
  *(__m128i *)(v4 + 752) = gVmxSignBit;
  *(__m128i *)(v4 + 688) = gVmxSignBit;
  *(__m128i *)(v4 + 368) = gVmxWMask;
  *(__m128 *)(v4 + 224) = gVmx127_0;
  *(__m128 *)(v4 + 576) = gVmxOneOver127_0;
  v22 = *(float *)v5;
  _mm_store_si128((__m128i *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 352), gVmxUnpackBias_0);
  *(__m128i *)(v4 + 608) = gVmxUnpackMask_0;
  *(__m128 *)(v4 + 544) = gVmxUnpackUnbias_0;
  *(__m128 *)(v4 + 320) = gVmxUnpackShift_0;
  v23 = (float)(v22 * v22) * 0.5;
  v24 = v23 * *(float *)(v5 + 200);
  v25 = v23 * *(float *)(v5 + 192);
  v26 = v23 * *(float *)(v5 + 196);
  v27 = (float)((float)((float)(v26 * *(float *)(v5 + 128)) + (float)(v25 * *(float *)(v5 + 112)))
              + (float)(v24 * *(float *)(v5 + 144)))
      + (float)(*(float *)(v5 + 160) * 0.0);
  v28 = (float)((float)((float)(v26 * *(float *)(v5 + 132)) + (float)(v25 * *(float *)(v5 + 116)))
              + (float)(v24 * *(float *)(v5 + 148)))
      + (float)(*(float *)(v5 + 164) * 0.0);
  v29 = v26 * *(float *)(v5 + 136);
  v30 = *(float *)(v5 + 168);
  v31 = v25 * *(float *)(v5 + 120);
  *(float *)(v4 + 144) = v27;
  *(float *)(v4 + 148) = v28;
  *(_DWORD *)(v4 + 156) = 0;
  v32 = _mm_shuffle_ps((__m128)*(unsigned int *)(v5 + 8), (__m128)*(unsigned int *)(v5 + 8), 0);
  *(float *)(v4 + 152) = (float)((float)(v29 + v31) + (float)(v24 * *(float *)(v5 + 152))) + (float)(v30 * 0.0);
  *(__m128 *)(v4 + 176) = v32;
  if ( *(float *)v5 == 0.0 )
    v33 = gVmxAllBitsSet;
  else
    v33 = 0i64;
  v34 = *((unsigned __int16 *)param0 + 20);
  v35 = *((_QWORD *)param0 + 4);
  v36 = (unsigned __int8 *)*((_QWORD *)param0 + 13);
  *(__m128i *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0xC0) = v33;
  if ( v34 )
  {
    v37 = (__m128 *)(v4 + 800);
    v38 = v34;
    do
    {
      v39 = *v36;
      if ( v39 == 255 )
      {
        v37[-2] = gVmxIdentity0_2;
        v37[-1] = gVmxIdentity1_2;
        *v37 = gVmxIdentity2_2;
        v37[1] = gVmxIdentity3_2;
      }
      else
      {
        v40 = (unsigned int)(48 * v39);
        v41 = &v21[12][4 * (unsigned int)*v36];
        v42 = *(__m128 *)(v40 + v35 + 16);
        v43 = v41[1];
        v44 = v41[2];
        v45 = v41[3];
        v46 = _mm_shuffle_ps(*(__m128 *)(v40 + v35 + 16), v42, 255);
        v47 = _mm_add_ps(v42, v42);
        v48 = _mm_shuffle_ps(*(__m128 *)(v40 + v35 + 16), v42, 201);
        v49 = _mm_shuffle_ps(v47, v47, 210);
        v50 = _mm_shuffle_ps(v42, v42, 210);
        v51 = _mm_shuffle_ps(v47, v47, 201);
        v52 = _mm_sub_ps(v6, _mm_mul_ps(v51, v48));
        v53 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v51, v46), (__m128)0i64), _mm_mul_ps(v50, v47));
        v54 = _mm_sub_ps(_mm_add_ps(_mm_mul_ps(v48, v47), (__m128)0i64), _mm_mul_ps(v49, v46));
        v55 = _mm_sub_ps(v52, _mm_mul_ps(v49, v50));
        v56 = _mm_shuffle_ps(_mm_shuffle_ps(v53, v54, 80), v54, 233);
        v57 = _mm_shuffle_ps(_mm_shuffle_ps(v54, v55, 80), v55, 233);
        v58 = _mm_shuffle_ps(_mm_shuffle_ps(v55, v53, 80), v53, 233);
        v59 = _mm_shuffle_ps(v56, _mm_shuffle_ps(v55, v56, 250), 148);
        v60 = _mm_shuffle_ps(v57, _mm_shuffle_ps(v53, v57, 250), 148);
        v61 = _mm_shuffle_ps(v58, _mm_shuffle_ps(v54, v58, 250), 148);
        v62 = _mm_shuffle_ps(v61, _mm_shuffle_ps(v61, (__m128)0i64, 250), 148);
        v63 = _mm_shuffle_ps(v60, _mm_shuffle_ps(v60, (__m128)0i64, 250), 148);
        v64 = _mm_shuffle_ps(v59, _mm_shuffle_ps(v59, (__m128)0i64, 250), 148);
        v65 = _mm_shuffle_ps(
                *(__m128 *)(v40 + v35),
                _mm_shuffle_ps(
                  *(__m128 *)(v40 + v35),
                  *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0xA0),
                  250),
                148);
        v37[-2] = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(*v41, *v41, 0), v62), (__m128)0i64),
                        _mm_mul_ps(_mm_shuffle_ps(*v41, *v41, 85), v63)),
                      _mm_mul_ps(_mm_shuffle_ps(*v41, *v41, 170), v64)),
                    _mm_mul_ps(_mm_shuffle_ps(*v41, *v41, 255), v65));
        v37[-1] = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v43, v43, 0), v62), (__m128)0i64),
                        _mm_mul_ps(_mm_shuffle_ps(v43, v43, 85), v63)),
                      _mm_mul_ps(_mm_shuffle_ps(v43, v43, 170), v64)),
                    _mm_mul_ps(_mm_shuffle_ps(v43, v43, 255), v65));
        *v37 = _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v44, v44, 0), v62), (__m128)0i64),
                     _mm_mul_ps(_mm_shuffle_ps(v44, v44, 85), v63)),
                   _mm_mul_ps(_mm_shuffle_ps(v44, v44, 170), v64)),
                 _mm_mul_ps(_mm_shuffle_ps(v44, v44, 255), v65));
        v66 = _mm_mul_ps(_mm_shuffle_ps(v45, v45, 170), v64);
        v6 = *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0xA0);
        v37[1] = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v45, v45, 0), v62), (__m128)0i64),
                       _mm_mul_ps(_mm_shuffle_ps(v45, v45, 85), v63)),
                     v66),
                   _mm_mul_ps(_mm_shuffle_ps(v45, v45, 255), v65));
      }
      v37 += 4;
      ++v36;
      --v38;
    }
    while ( v38 );
    v11 = *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0xE0);
    v17 = *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x260);
    v19 = *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x220);
    v20 = *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x140);
    v16 = _mm_load_si128((const __m128i *)(v4 + 352));
    v15 = *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x240);
    v10 = *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x270);
  }
  v67 = FLOAT_4096_0;
  v68 = *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0xA0);
  v69 = 0;
  *(_QWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x200) = ((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64)
                                                                          + 464;
  *(_QWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x1D0) = "<unassigned>";
  *(_QWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x208) = ((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64)
                                                                          + 488;
  *(_QWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x1E8) = "<unassigned>";
  *(_QWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x180) = "<unassigned>";
  *(_QWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x198) = "<unassigned>";
  v70 = 0;
  *(_QWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x1B0) = ((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64)
                                                                          + 384;
  *(_DWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x1E0) = 0;
  *(_QWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x1B8) = ((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64)
                                                                          + 408;
  v71 = 0i64;
  *(_QWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x1F0) = 0i64;
  if ( !v7 )
    v71 = v21[9];
  *(_DWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x1F8) = 0;
  *(_DWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x210) = 0;
  *(_QWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x2D8) = v71;
  v72 = *(unsigned __int16 **)(v5 + 384);
  *(_DWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x190) = 0;
  v73 = *v72;
  *(_QWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x1A0) = 0i64;
  *(_DWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x1A8) = 0;
  v74 = 0;
  v75 = (unsigned __int64)v21[2] + (unsigned int)(8 * v73);
  *(_DWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x1C0) = 0;
  v76 = (unsigned __int64)v21[1] + (unsigned int)(24 * v73);
  v77 = 0;
  v78 = v75 & 0xFFFFFFFFFFFFFFF0ui64;
  v79 = v76 & 0xFFFFFFFFFFFFFFF0ui64;
  v80 = v75 - (v75 & 0xFFFFFFFFFFFFFFF0ui64);
  *(_QWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x188) = v78;
  v81 = v76 - (v76 & 0xFFFFFFFFFFFFFFF0ui64);
  *(_QWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x1D8) = v79;
  if ( v12 )
  {
    v82 = *(_QWORD *)(v5 + 400);
    v83 = *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0xC0);
    v84 = *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0xC0);
    v85 = (__m128 *)(v4 + 17152);
    v86 = (signed __int16 *)(v82 + 4);
    *(_QWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x18) = *(_QWORD *)(v5 + 384) + 2i64;
    v87 = _mm_and_ps(v84, v68);
    *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x110) = v87;
    *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x150) = _mm_and_ps(v10, v68);
    v88 = v13 - v82;
    do
    {
      v89 = (__m128 *)(v81
                     + *(_QWORD *)(*(_QWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64)
                                             + 0x200
                                             + 8i64 * (signed int)v69)
                                 + 8i64));
      v90 = v80
          + *(_QWORD *)(*(_QWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x1B0 + 8i64 * v74) + 8i64);
      v91 = v77 + 1;
      *(_QWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x30) = v89;
      *(_QWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x50) = v90;
      *(_DWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x10) = v91;
      if ( v91 < v12 )
      {
        v92 = **(unsigned __int16 **)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x18);
        *(_DWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x210) = ((_BYTE)v69 - 1) & 1;
        *(_DWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x1C0) = ((_BYTE)v74 - 1) & 1;
        v89 = *(__m128 **)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x30);
        v93 = (unsigned __int64)v21[2] + (unsigned int)(8 * v92);
        v81 = ((unsigned __int64)v21[1] + (unsigned int)(24 * v92)) & 0xFFFFFFFFFFFFFFF0ui64;
        *(_QWORD *)(*(_QWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64)
                              + 0x200
                              + 8i64 * (((_BYTE)v69 - 1) & 1))
                  + 8i64) = v81;
        v80 = v93 & 0xFFFFFFFFFFFFFFF0ui64;
        *(_QWORD *)(*(_QWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64)
                              + 0x1B0
                              + 8i64 * *(signed int *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x1C0))
                  + 8i64) = v80;
        v69 = *(_DWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x210);
      }
      v94 = v89[1];
      v95 = *(__m128 **)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x50);
      v96 = LOBYTE(v95->m128_u64[0]) << 6;
      v97 = _mm_shuffle_ps(*v89, _mm_shuffle_ps(*v89, v68, 250), 148);
      v98 = BYTE1(v95->m128_u64[0]) << 6;
      v99 = BYTE2(v95->m128_u64[0]) << 6;
      v100 = (__m128)_mm_sub_epi32((__m128i)_mm_shuffle_ps(v94, v94, 0), v16);
      v101 = (__m128)_mm_sub_epi32((__m128i)_mm_shuffle_ps(v94, v94, 85), v16);
      v102 = *(__m128 *)(v4 + 800 + v96);
      v103 = (__m128i)_mm_shuffle_ps(*v95, *v95, 85);
      v104 = BYTE3(v95->m128_u64[0]) << 6;
      v105 = (__m128i)_mm_and_ps(
                        (__m128)_mm_sub_epi32(
                                  v103,
                                  *(__m128i *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x160)),
                        v17);
      v106 = _mm_mul_ps(_mm_add_ps(_mm_cvtepi32_ps((__m128i)_mm_and_ps(v100, v17)), v19), v20);
      v107 = _mm_mul_ps(_mm_add_ps(_mm_cvtepi32_ps((__m128i)_mm_and_ps(v101, v17)), v19), v20);
      v108 = *(__m128 *)(v4 + 784 + v96);
      v109 = _mm_sub_ps(_mm_add_ps(v106, v9), v11);
      v110 = _mm_sub_ps(_mm_add_ps(v107, v9), v11);
      v111 = *(__m128 *)(v4 + 800 + v98);
      v112 = _mm_mul_ps(v109, v15);
      v113 = _mm_mul_ps(v110, v15);
      v114 = *(__m128 *)(v4 + 784 + v98);
      v115 = _mm_add_ps(v113, v9);
      *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x30) = _mm_add_ps(v112, v9);
      v116 = _mm_shuffle_ps(v115, v9, 250);
      v117 = _mm_shuffle_ps(v115, v115, 255);
      v118 = *(__m128 *)(v4 + 768 + v98);
      *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x120) = v117;
      *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x230) = _mm_shuffle_ps(v115, v116, 148);
      v119 = v117;
      v120 = *(__m128 *)(v4 + 768 + v99);
      v121 = _mm_or_ps(
               _mm_andnot_ps(
                 v83,
                 _mm_and_ps(v119, *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x250))),
               v87);
      v122 = _mm_mul_ps(
               _mm_add_ps(_mm_cvtepi32_ps(v105), v19),
               *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x140));
      v123 = _mm_shuffle_ps(v97, v97, 0);
      *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x100) = v121;
      v124 = *(__m128 *)(v4 + 768 + v96);
      v125 = _mm_add_ps(
               _mm_mul_ps(
                 _mm_add_ps(v122, (__m128)0i64),
                 *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x2E0)),
               (__m128)0i64);
      v126 = _mm_shuffle_ps(v125, v125, 0);
      v127 = _mm_shuffle_ps(v125, v125, 85);
      v128 = _mm_shuffle_ps(v125, v125, 170);
      *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0xF0) = _mm_shuffle_ps(v125, v125, 255);
      v129 = _mm_shuffle_ps(v97, v97, 85);
      v130 = _mm_shuffle_ps(v97, v97, 170);
      v131 = _mm_shuffle_ps(v97, v97, 255);
      *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x20) = _mm_add_ps(
                                                                                 _mm_add_ps(
                                                                                   _mm_mul_ps(v124, v123),
                                                                                   (__m128)0i64),
                                                                                 _mm_mul_ps(v108, v129));
      *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x20) = _mm_add_ps(
                                                                                 *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64)
                                                                                           + 0x20),
                                                                                 _mm_mul_ps(v102, v130));
      *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x20) = _mm_add_ps(
                                                                                 _mm_mul_ps(
                                                                                   _mm_add_ps(
                                                                                     *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64)
                                                                                               + 0x20),
                                                                                     _mm_mul_ps(
                                                                                       *(__m128 *)(v4 + 816 + v96),
                                                                                       v131)),
                                                                                   v126),
                                                                                 (__m128)0i64);
      v132 = _mm_mul_ps(*(__m128 *)(v4 + 800 + v99), v130);
      v133 = _mm_mul_ps(*(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x300 + v104), v123);
      *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x20) = _mm_add_ps(
                                                                                 *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64)
                                                                                           + 0x20),
                                                                                 _mm_mul_ps(
                                                                                   _mm_add_ps(
                                                                                     _mm_add_ps(
                                                                                       _mm_add_ps(
                                                                                         _mm_add_ps(
                                                                                           _mm_mul_ps(v118, v123),
                                                                                           (__m128)0i64),
                                                                                         _mm_mul_ps(v114, v129)),
                                                                                       _mm_mul_ps(v111, v130)),
                                                                                     _mm_mul_ps(
                                                                                       *(__m128 *)(v4 + 816 + v98),
                                                                                       v131)),
                                                                                   v127));
      v134 = _mm_add_ps(
               _mm_add_ps(
                 _mm_add_ps(_mm_mul_ps(v120, v123), (__m128)0i64),
                 _mm_mul_ps(*(__m128 *)(v4 + 784 + v99), v129)),
               v132);
      v135 = _mm_mul_ps(*(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x320 + v104), v130);
      v136 = _mm_add_ps(
               *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x20),
               _mm_mul_ps(_mm_add_ps(v134, _mm_mul_ps(*(__m128 *)(v4 + 816 + v99), v131)), v128));
      v137 = *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x30);
      v138 = *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x30);
      *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x20) = v136;
      v139 = _mm_shuffle_ps(v137, v137, 0);
      v140 = _mm_shuffle_ps(v138, v137, 170);
      v141 = _mm_mul_ps(*(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x310 + v104), v129);
      v142 = _mm_shuffle_ps(v137, v137, 85);
      *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x20) = _mm_add_ps(
                                                                                 *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64)
                                                                                           + 0x20),
                                                                                 _mm_mul_ps(
                                                                                   _mm_add_ps(
                                                                                     _mm_add_ps(
                                                                                       _mm_add_ps(
                                                                                         _mm_add_ps(v133, (__m128)0i64),
                                                                                         v141),
                                                                                       v135),
                                                                                     _mm_mul_ps(
                                                                                       *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64)
                                                                                                 + 0x330
                                                                                                 + v104),
                                                                                       v131)),
                                                                                   *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64)
                                                                                             + 0xF0)));
      v143 = *(__m128 *)(v4 + 768 + v96);
      v144 = _mm_mul_ps(_mm_shuffle_ps(v137, v137, 255), (__m128)0i64);
      *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x30) = v144;
      *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x50) = _mm_add_ps(
                                                                                 _mm_mul_ps(
                                                                                   _mm_add_ps(
                                                                                     _mm_add_ps(
                                                                                       _mm_add_ps(
                                                                                         _mm_add_ps(
                                                                                           _mm_mul_ps(v143, v139),
                                                                                           (__m128)0i64),
                                                                                         _mm_mul_ps(v108, v142)),
                                                                                       _mm_mul_ps(v102, v140)),
                                                                                     v144),
                                                                                   v126),
                                                                                 (__m128)0i64);
      v145 = _mm_add_ps(
               _mm_add_ps(
                 _mm_add_ps(_mm_add_ps(_mm_mul_ps(v118, v139), (__m128)0i64), _mm_mul_ps(v114, v142)),
                 _mm_mul_ps(v111, v140)),
               v144);
      v146 = _mm_mul_ps(*(__m128 *)(v4 + 800 + v99), v140);
      v147 = _mm_add_ps(_mm_mul_ps(*(__m128 *)(v4 + 768 + v99), v139), (__m128)0i64);
      v148 = *(__m128 *)(v4 + 784 + v99);
      v149 = _mm_add_ps(*(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x50), _mm_mul_ps(v145, v127));
      v150 = _mm_mul_ps(*(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x300 + v104), v139);
      *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x50) = v149;
      v151 = _mm_add_ps(
               _mm_add_ps(_mm_add_ps(v147, _mm_mul_ps(v148, v142)), v146),
               *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x30));
      v152 = _mm_mul_ps(*(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x320 + v104), v140);
      v153 = *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x230);
      *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x50) = _mm_add_ps(
                                                                                 *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64)
                                                                                           + 0x50),
                                                                                 _mm_mul_ps(v151, v128));
      v154 = _mm_mul_ps(*(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x310 + v104), v142);
      v155 = *(__m128 *)(v4 + 768 + v96);
      v156 = _mm_add_ps(
               _mm_add_ps(_mm_add_ps(_mm_add_ps(v150, (__m128)0i64), v154), v152),
               *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x30));
      v157 = _mm_shuffle_ps(v153, v153, 85);
      v158 = _mm_add_ps(
               *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x50),
               _mm_mul_ps(v156, *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0xF0)));
      v159 = _mm_shuffle_ps(v153, v153, 170);
      *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x50) = v158;
      v160 = _mm_shuffle_ps(v153, v153, 0);
      v161 = _mm_mul_ps(_mm_shuffle_ps(v153, v153, 255), (__m128)0i64);
      v162 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v155, v160), (__m128)0i64), _mm_mul_ps(v108, v157));
      *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x30) = v162;
      v7 = *(_BYTE *)(v5 + 408) == 0;
      v163 = _mm_add_ps(
               _mm_add_ps(_mm_mul_ps(_mm_add_ps(_mm_add_ps(v162, _mm_mul_ps(v102, v159)), v161), v126), (__m128)0i64),
               _mm_mul_ps(
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_add_ps(_mm_mul_ps(v118, v160), (__m128)0i64), _mm_mul_ps(v114, v157)),
                     _mm_mul_ps(v111, v159)),
                   v161),
                 v127));
      v9 = 0i64;
      v164 = _mm_add_ps(
               _mm_add_ps(
                 v163,
                 _mm_mul_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_mul_ps(*(__m128 *)(v4 + 768 + v99), v160), (__m128)0i64),
                         _mm_mul_ps(v148, v157)),
                       _mm_mul_ps(*(__m128 *)(v4 + 800 + v99), v159)),
                     v161),
                   v128)),
               _mm_mul_ps(
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x300 + v104),
                           v160),
                         (__m128)0i64),
                       _mm_mul_ps(*(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x310 + v104), v157)),
                     _mm_mul_ps(*(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x320 + v104), v159)),
                   v161),
                 *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0xF0)));
      *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x30) = v164;
      if ( v7 )
      {
        v165 = *(float *)(v5 + 68);
        v166 = *(float *)(v5 + 72);
        v167 = *(signed __int16 *)((char *)v86 + v88 - 4);
        v168 = *(float *)(v5 + 88);
        v169 = *(float *)(v5 + 76);
        v170 = *(float *)(v5 + 92);
        v171 = (float)*(v86 - 1) * 0.00024414062;
        v172 = (float)*v86 * 0.00024414062;
        v173 = (float)*(v86 - 2) * 0.00024414062;
        v174 = *(float *)(v5 + 56) * v173;
        v175 = *(float *)(v5 + 60) * v173;
        v176 = *(float *)(v5 + 84) * v172;
        v177 = (float)(*(float *)(v5 + 52) * v173) + (float)(*(float *)(v5 + 68) * v171);
        *(float *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x70) = (float)((float)((float)(*(float *)(v5 + 48) * v173)
                                                                                              + (float)(*(float *)(v5 + 64) * v171))
                                                                                      + (float)(*(float *)(v5 + 80)
                                                                                              * v172))
                                                                              + *(float *)(v5 + 96);
        v178 = *(float *)(v5 + 52);
        v179 = v174 + (float)(v166 * v171);
        v180 = v169 * v171;
        v181 = *(float *)(v5 + 48);
        v182 = (float)(v179 + (float)(v168 * v172)) + *(float *)(v5 + 104);
        v183 = v175 + v180;
        *(float *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x74) = (float)(v177 + v176)
                                                                              + *(float *)(v5 + 100);
        v184 = _mm_cvtsi32_si128(v167);
        v185 = *(signed __int16 *)((char *)v86 + v88 - 2);
        v186 = *(float *)(v5 + 80);
        *(float *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x78) = v182;
        v187 = _mm_cvtsi32_si128(v185);
        v188 = *(signed __int16 *)((char *)v86 + v88);
        *(float *)v184.m128i_i32 = COERCE_FLOAT(_mm_cvtepi32_ps(v184)) * 0.00024414062;
        *(float *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x7C) = (float)(v183 + (float)(v170 * v172))
                                                                              + *(float *)(v5 + 108);
        *(float *)v187.m128i_i32 = COERCE_FLOAT(_mm_cvtepi32_ps(v187)) * 0.00024414062;
        v189 = (float)v188 * 0.00024414062;
        v190 = (float)((float)((float)(v181 * *(float *)v184.m128i_i32)
                             + (float)(*(float *)(v5 + 64) * *(float *)v187.m128i_i32))
                     + (float)(v186 * v189))
             + *(float *)(v5 + 96);
        v191 = *(float *)(v5 + 84);
        v192 = *(float *)(v5 + 56);
        v193 = *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x20);
        v194 = v169 * *(float *)v187.m128i_i32;
        *(float *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x80) = v190;
        v195 = _mm_sub_ps(v193, *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x70));
        v196 = v166 * *(float *)v187.m128i_i32;
        v197 = v170 * v189;
        v198 = v168 * v189;
        v199 = (float)((float)(v178 * *(float *)v184.m128i_i32) + (float)(v165 * *(float *)v187.m128i_i32))
             + (float)(v191 * v189);
        v200 = *(float *)(v5 + 60) * *(float *)v184.m128i_i32;
        v201 = _mm_shuffle_ps(v195, v195, 170);
        v202 = _mm_shuffle_ps(v195, v195, 0);
        v203 = (float)((float)((float)(v192 * *(float *)v184.m128i_i32) + v196) + v198) + *(float *)(v5 + 104);
        v204 = v199 + *(float *)(v5 + 100);
        v205 = _mm_shuffle_ps(v195, v195, 85);
        *(float *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x88) = v203;
        *(float *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x84) = v204;
        v206 = (float)(v200 + v194) + v197;
        v67 = FLOAT_4096_0;
        v9 = 0i64;
        *(float *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x8C) = v206 + *(float *)(v5 + 108);
        v207 = *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x80);
        v208 = _mm_min_ps(
                 _mm_add_ps(
                   _mm_mul_ps(
                     _mm_rcp_ps(
                       _mm_rsqrt_ps(
                         _mm_add_ps(
                           _mm_add_ps(_mm_add_ps(_mm_mul_ps(v202, v202), (__m128)0i64), _mm_mul_ps(v205, v205)),
                           _mm_mul_ps(v201, v201)))),
                     _mm_sub_ps(
                       (__m128)_xmm,
                       _mm_add_ps(
                         _mm_mul_ps(
                           *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x100),
                           *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x100)),
                         (__m128)0i64))),
                   *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x100)),
                 *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0xA0));
        v209 = _mm_add_ps(
                 _mm_mul_ps(v195, v208),
                 *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x70));
        *(_WORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 4) = (signed int)(float)(v209.m128_f32[0]
                                                                                               * 4096.0);
        v210 = _mm_mul_ps(v207, *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x270));
        *(_WORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 6) = (signed int)(float)(COERCE_FLOAT(
                                                                                                   _mm_shuffle_ps(
                                                                                                     v209,
                                                                                                     v209,
                                                                                                     85))
                                                                                               * 4096.0);
        *(_DWORD *)((char *)v86 + v88 - 4) = *(_DWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 4);
        *(signed __int16 *)((char *)v86 + v88) = (signed int)(float)(COERCE_FLOAT(_mm_shuffle_ps(v209, v209, 170))
                                                                   * 4096.0);
        v68 = *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0xA0);
        v211 = _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(v210, *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x90)),
                   _mm_mul_ps(
                     _mm_sub_ps(v209, v207),
                     *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0xB0))),
                 _mm_add_ps(v209, v209));
        v212 = _mm_add_ps(v211, _mm_mul_ps(_mm_sub_ps(v207, v211), v208));
        v213 = *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x50);
        v214 = _mm_sub_ps(_mm_add_ps(_mm_mul_ps(_mm_sub_ps(v209, v212), v208), v212), v193);
        v215 = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_min_ps(
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_max_ps(
                           _mm_add_ps(
                             _mm_add_ps(
                               _mm_add_ps(
                                 _mm_mul_ps(_mm_shuffle_ps(v214, v214, 0), _mm_shuffle_ps(v213, v213, 0)),
                                 (__m128)0i64),
                               _mm_mul_ps(
                                 _mm_shuffle_ps(v214, v214, 85),
                                 _mm_shuffle_ps(
                                   *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x50),
                                   v213,
                                   85))),
                             _mm_mul_ps(
                               _mm_shuffle_ps(v214, v214, 170),
                               _mm_shuffle_ps(
                                 *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x50),
                                 v213,
                                 170))),
                           (__m128)0i64),
                         (__m128)_xmm),
                       (__m128)_xmm),
                     v68),
                   v214),
                 v193);
        *v85 = _mm_shuffle_ps(v215, _mm_shuffle_ps(v215, v208, 250), 148);
      }
      else
      {
        v216 = *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x20);
        v67 = FLOAT_4096_0;
        v68 = *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0xA0);
        v213 = *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x50);
        LODWORD(v217) = (unsigned __int128)_mm_shuffle_ps(
                                             *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x20),
                                             v216,
                                             170);
        *(_WORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x40) = (signed int)(float)(COERCE_FLOAT(*(_OWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x20))
                                                                                                  * 4096.0);
        v218 = (signed int)(float)(v217 * 4096.0);
        *(_WORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x42) = (signed int)(float)(COERCE_FLOAT(_mm_shuffle_ps(v216, v216, 85))
                                                                                                  * 4096.0);
        *(_DWORD *)((char *)v86 + v88 - 4) = *(_DWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x40);
        v219 = _mm_shuffle_ps(v216, *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x100), 250);
        *(signed __int16 *)((char *)v86 + v88) = v218;
        *v85 = _mm_shuffle_ps(v216, v219, 148);
      }
      v11 = *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0xE0);
      v77 = *(_DWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x10);
      *(_QWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x18) += 2i64;
      v17 = *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x260);
      v19 = *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x220);
      v16 = _mm_load_si128((const __m128i *)(v4 + 352));
      v74 = *(_DWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x1C0);
      v85 += 2;
      v86 += 3;
      v220 = _mm_cvtps_epi32(_mm_add_ps(_mm_mul_ps(v213, v11), v11));
      v15 = *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x240);
      v87 = *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x110);
      v83 = *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0xC0);
      v221 = _mm_cvtps_epi32(_mm_cvtepi32_ps(v220));
      v222 = _mm_packs_epi32(v221, v221);
      v223 = _mm_cmpltps(*(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x120), v9);
      v85[-1].m128_i32[0] = (unsigned __int128)_mm_packus_epi16(v222, v222);
      v224 = _mm_cvtps_epi32(
               _mm_add_ps(
                 _mm_mul_ps(
                   _mm_shuffle_ps(
                     v164,
                     _mm_shuffle_ps(
                       v164,
                       _mm_or_ps(
                         _mm_andnot_ps(v68, v223),
                         *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x150)),
                       250),
                     148),
                   v11),
                 v11));
      v20 = *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x140);
      v225 = _mm_cvtps_epi32(_mm_cvtepi32_ps(v224));
      v226 = _mm_packs_epi32(v225, v225);
      v85[-1].m128_i32[1] = (unsigned __int128)_mm_packus_epi16(v226, v226);
    }
    while ( v77 < v12 );
    v8 = *(_DWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0xC);
    v14 = *(_QWORD *)(v5 + 400);
    v70 = *(_DWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x210);
    v69 = 0;
  }
  if ( *(float *)v5 > 0.0 )
  {
    v227 = *(_DWORD *)(v5 + 16);
    v228 = *(__m128 **)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0xD0);
    v229 = 5i64;
    do
    {
      Render::ApplySpringConstraints(
        v228,
        v227,
        (__m128 *)(v4 + 656),
        (__m128 *)(v4 + 672),
        (__m128 *)(v4 + 704),
        (__m128 *)(v4 + 640),
        (__m128 *)(v4 + 688),
        (__m128 *)(v4 + 368),
        (__m128 *)(v4 + 304),
        v329,
        (Render::VerletVert *)(v4 + 17152));
      --v229;
    }
    while ( v229 );
    v12 = *(_DWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x60);
    v8 = *(_DWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0xC);
    v70 = *(_DWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x210);
  }
  if ( v12 )
  {
    v230 = (__m128 *)(v4 + 17152);
    v231 = v12;
    do
    {
      v232 = *v230;
      v14 += 6i64;
      v230 += 2;
      v233 = (signed int)(float)(v230[-2].m128_f32[2] * v67);
      *(_WORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 4) = (signed int)(float)(v232.m128_f32[0] * v67);
      *(_WORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 6) = (signed int)(float)(COERCE_FLOAT(
                                                                                                 _mm_shuffle_ps(
                                                                                                   v232,
                                                                                                   v232,
                                                                                                   85))
                                                                                             * v67);
      *(_DWORD *)(v14 - 6) = *(_DWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 4);
      *(_WORD *)(v14 - 2) = v233;
      --v231;
    }
    while ( v231 );
  }
  v234 = v21[1];
  v235 = *v21;
  v236 = v21[2];
  v237 = 128;
  if ( v8 < 0x80 )
    v237 = v8;
  v238 = 8 * v237;
  v239 = 24 * v237;
  *(_QWORD *)(*(_QWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x200 + 8i64 * v70) + 8i64) = v234;
  *(_QWORD *)(*(_QWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64)
                        + 0x1B0
                        + 8i64 * *(signed int *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x1C0))
            + 8i64) = v236;
  if ( v8 )
  {
    v240 = 128;
    if ( v8 < 0x80 )
      v240 = v8;
    do
    {
      v241 = *(signed int *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x210);
      v8 -= v240;
      v242 = v240;
      v243 = *(_QWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x200 + 8 * v241);
      v244 = v235;
      v245 = 24 * v240;
      v240 = 128;
      *(_DWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0xC) = v8;
      v234 = (__m128 *)((char *)v234 + v239);
      *(_QWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x20) = (char *)v235 + v245;
      v246 = *(_OWORD **)(v243 + 8);
      v236 = (__m128 *)((char *)v236 + v238);
      v247 = *(_QWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64)
                       + 0x1B0
                       + 8i64 * *(signed int *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x1C0));
      *(_QWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0xD0) = v234;
      v248 = *(__m128 **)(v247 + 8);
      if ( v8 < 0x80 )
        v240 = v8;
      *(_QWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x50) = v236;
      *(_DWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x10) = v240;
      v239 = 24 * v240;
      *(_DWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 4) = 8 * v240;
      *(_DWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x40) = 24 * v240;
      if ( v240 )
      {
        v249 = *(unsigned int *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x1C0) - 1;
        *(_DWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x210) = ((_BYTE)v241 - 1) & 1;
        *(_DWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x1C0) = v249 & 1;
        *(_QWORD *)(*(_QWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64)
                              + 0x200
                              + 8i64 * (((_BYTE)v241 - 1) & 1))
                  + 8i64) = v234;
        *(_QWORD *)(*(_QWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64)
                              + 0x1B0
                              + 8i64 * *(signed int *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x1C0))
                  + 8i64) = v236;
      }
      if ( (_DWORD)v242 )
      {
        v250 = *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x270);
        v251 = (signed __int64)v244[1].m128_i64 + 4;
        v252 = (signed __int64)&v244[1];
        *(_QWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x18) = (char *)v244 + 20;
        *(_QWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x30) = v242;
        v253 = _mm_and_ps(v250, v68);
        *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x250) = v253;
        do
        {
          v254 = *(unsigned __int16 *)(*(_QWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x2D0)
                                     + 2i64 * v69);
          if ( (unsigned int)v254 < v12 )
          {
            v246 = (_OWORD *)((char *)v246 + 24);
            v248 = (__m128 *)((char *)v248 + 8);
            v321 = *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x4310 + 32 * v254);
            v322 = _mm_mul_ps(
                     _mm_add_ps(
                       _mm_cvtepi32_ps((__m128i)_mm_and_ps(
                                                  (__m128)_mm_sub_epi32(
                                                            (__m128i)_mm_shuffle_ps(v321, v321, 85),
                                                            *(__m128i *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64)
                                                                       + 0x160)),
                                                  *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x260))),
                       *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x220)),
                     *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x140));
            v323 = _mm_add_ps(
                     _mm_cvtepi32_ps((__m128i)_mm_and_ps(
                                                (__m128)_mm_sub_epi32(
                                                          (__m128i)_mm_shuffle_ps(v321, v321, 0),
                                                          *(__m128i *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64)
                                                                     + 0x160)),
                                                *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x260))),
                     *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x220));
            *v244 = _mm_shuffle_ps(
                      *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x4300 + 32 * v254),
                      _mm_shuffle_ps(
                        *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x4300 + 32 * v254),
                        v9,
                        250),
                      148);
            v324 = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_sub_ps(_mm_add_ps(v322, v9), v11),
                       *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x240)),
                     v9);
            v319 = _mm_cvtps_epi32(
                     _mm_cvtepi32_ps(
                       _mm_cvtps_epi32(
                         _mm_add_ps(
                           _mm_mul_ps(
                             _mm_add_ps(
                               _mm_mul_ps(
                                 _mm_sub_ps(
                                   _mm_add_ps(
                                     _mm_mul_ps(
                                       v323,
                                       *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x140)),
                                     v9),
                                   v11),
                                 *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x240)),
                               v9),
                             v11),
                           v11))));
            v320 = _mm_cvtps_epi32(
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_shuffle_ps(
                           v324,
                           _mm_shuffle_ps(
                             v324,
                             _mm_or_ps(_mm_andnot_ps(v68, _mm_cmpltps(_mm_shuffle_ps(v324, v324, 255), v9)), v253),
                             250),
                           148),
                         v11),
                       v11));
          }
          else
          {
            v255 = *((__m128 *)v246 + 1);
            v256 = *(__m128 *)v246;
            v257 = _mm_load_si128((const __m128i *)(v4 + 352));
            v258 = *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x260);
            v259 = *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x220);
            v260 = *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x140);
            v246 = (_OWORD *)((char *)v246 + 24);
            v261 = LOBYTE(v248->m128_u64[0]);
            v262 = BYTE1(v248->m128_u64[0]);
            v263 = BYTE2(v248->m128_u64[0]);
            v264 = BYTE3(v248->m128_u64[0]);
            v265 = *v248;
            v248 = (__m128 *)((char *)v248 + 8);
            v266 = _mm_shuffle_ps(v256, _mm_shuffle_ps(v256, v68, 250), 148);
            v267 = *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x300 + (v261 << 6));
            *(_OWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x290) = *(_OWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64)
                                                                                                + 0x330
                                                                                                + (v261 << 6));
            *(_OWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x2A0) = *(_OWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64)
                                                                                                + 0x330
                                                                                                + (v262 << 6));
            *(_OWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x2C0) = *(_OWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64)
                                                                                                + 0x330
                                                                                                + (v263 << 6));
            v268 = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_sub_ps(
                         _mm_add_ps(
                           _mm_mul_ps(
                             _mm_add_ps(
                               _mm_cvtepi32_ps((__m128i)_mm_and_ps(
                                                          (__m128)_mm_sub_epi32(
                                                                    (__m128i)_mm_shuffle_ps(v255, v255, 85),
                                                                    v257),
                                                          v258)),
                               v259),
                             v260),
                           v9),
                         v11),
                       *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x240)),
                     v9);
            v269 = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_sub_ps(
                         _mm_add_ps(
                           _mm_mul_ps(
                             _mm_add_ps(
                               _mm_cvtepi32_ps((__m128i)_mm_and_ps(
                                                          (__m128)_mm_sub_epi32(
                                                                    (__m128i)_mm_shuffle_ps(v255, v255, 0),
                                                                    v257),
                                                          v258)),
                               v259),
                             v260),
                           v9),
                         v11),
                       *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x240)),
                     v9);
            *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x2B0) = _mm_shuffle_ps(v268, v268, 255);
            v270 = _mm_shuffle_ps(v268, _mm_shuffle_ps(v268, v9, 250), 148);
            *(_OWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0xC0) = *(_OWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64)
                                                                                               + 0x310
                                                                                               + (v261 << 6));
            *(_OWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0xB0) = *(_OWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64)
                                                                                               + 0x320
                                                                                               + (v261 << 6));
            *(_OWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x80) = *(_OWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64)
                                                                                               + 0x300
                                                                                               + (v262 << 6));
            *(_OWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x70) = *(_OWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64)
                                                                                               + 0x310
                                                                                               + (v262 << 6));
            *(_OWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x170) = *(_OWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64)
                                                                                                + 0x320
                                                                                                + (v262 << 6));
            *(_OWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x110) = *(_OWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64)
                                                                                                + 0x300
                                                                                                + (v263 << 6));
            *(_OWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x150) = *(_OWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64)
                                                                                                + 0x310
                                                                                                + (v263 << 6));
            *(_OWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x120) = *(_OWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64)
                                                                                                + 0x320
                                                                                                + (v263 << 6));
            *(_OWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x100) = *(_OWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64)
                                                                                                + 0x300
                                                                                                + (v264 << 6));
            v7 = *(_BYTE *)v4 == 0;
            v271 = *(_OWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x330 + (v264 << 6));
            *(_OWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0xF0) = *(_OWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64)
                                                                                               + 0x310
                                                                                               + (v264 << 6));
            *(_OWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x230) = *(_OWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64)
                                                                                                + 0x320
                                                                                                + (v264 << 6));
            *(_OWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x280) = v271;
            v272 = v9;
            v273 = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_add_ps(
                             _mm_cvtepi32_ps((__m128i)_mm_and_ps(
                                                        (__m128)_mm_sub_epi32(
                                                                  (__m128i)_mm_shuffle_ps(v265, v265, 85),
                                                                  v257),
                                                        v258)),
                             v259),
                           v260),
                         v9),
                       *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x2E0)),
                     v9);
            v274 = _mm_shuffle_ps(v273, v273, 0);
            v275 = _mm_shuffle_ps(v273, v273, 85);
            v276 = _mm_shuffle_ps(v273, v273, 170);
            *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x90) = v274;
            *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x130) = v275;
            *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0xE0) = v276;
            v277 = _mm_shuffle_ps(v273, v273, 255);
            if ( !v7 )
            {
              v278 = 32 * v261;
              v279 = *(_QWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x2D8);
              v280 = 32 * v262;
              v281 = 32 * v264;
              v282 = _mm_cmpltps(v269, v9);
              v283 = 32 * v263;
              v284 = _mm_and_ps(
                       _mm_or_ps(
                         _mm_add_ps(
                           _mm_add_ps(
                             _mm_add_ps(
                               _mm_add_ps(_mm_mul_ps(v274, *(__m128 *)(v278 + v279 + 16)), v9),
                               _mm_mul_ps(v275, *(__m128 *)(v280 + v279 + 16))),
                             _mm_mul_ps(v276, *(__m128 *)(v283 + v279 + 16))),
                           _mm_mul_ps(v277, *(__m128 *)(v281 + v279 + 16))),
                         *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x2F0)),
                       v282);
              v285 = _mm_andnot_ps(
                       v282,
                       _mm_add_ps(
                         _mm_add_ps(
                           _mm_add_ps(
                             _mm_add_ps(_mm_mul_ps(v274, *(__m128 *)(v278 + v279)), v9),
                             _mm_mul_ps(v275, *(__m128 *)(v280 + v279))),
                           _mm_mul_ps(v276, *(__m128 *)(v283 + v279))),
                         _mm_mul_ps(v277, *(__m128 *)(v281 + v279))));
              v274 = *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x90);
              v286 = _mm_add_ps(_mm_mul_ps(_mm_or_ps(v284, v285), v269), v9);
              v272 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v286, v286, 0), _mm_shuffle_ps(v68, v68, 0)), v9),
                         _mm_mul_ps(_mm_shuffle_ps(v286, v286, 85), _mm_shuffle_ps(v68, v68, 85))),
                       _mm_mul_ps(_mm_shuffle_ps(v286, v286, 170), _mm_shuffle_ps(v68, v68, 170)));
            }
            v287 = _mm_shuffle_ps(v266, v266, 0);
            v288 = _mm_shuffle_ps(v266, v266, 85);
            v289 = _mm_shuffle_ps(v266, v266, 170);
            v290 = _mm_shuffle_ps(v266, v266, 255);
            v291 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_add_ps(
                           _mm_add_ps(
                             _mm_add_ps(
                               _mm_add_ps(_mm_mul_ps(v267, v287), v9),
                               _mm_mul_ps(*(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0xC0), v288)),
                             _mm_mul_ps(*(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0xB0), v289)),
                           _mm_mul_ps(*(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x290), v290)),
                         v274),
                       v9),
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_add_ps(
                           _mm_add_ps(
                             _mm_add_ps(
                               _mm_mul_ps(*(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x80), v287),
                               v9),
                             _mm_mul_ps(*(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x70), v288)),
                           _mm_mul_ps(*(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x170), v289)),
                         _mm_mul_ps(*(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x2A0), v290)),
                       *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x130)));
            v292 = _mm_mul_ps(*(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x100), v287);
            v293 = _mm_mul_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_add_ps(
                           _mm_add_ps(
                             _mm_mul_ps(*(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x110), v287),
                             v9),
                           _mm_mul_ps(*(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x150), v288)),
                         _mm_mul_ps(*(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x120), v289)),
                       _mm_mul_ps(*(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x2C0), v290)),
                     *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0xE0));
            v294 = _mm_shuffle_ps(v270, v270, 0);
            v295 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(v292, v9),
                       _mm_mul_ps(*(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0xF0), v288)),
                     _mm_mul_ps(*(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x230), v289));
            v296 = _mm_shuffle_ps(v270, v270, 85);
            v297 = _mm_shuffle_ps(v270, v270, 170);
            v298 = _mm_add_ps(
                     _mm_add_ps(v291, v293),
                     _mm_mul_ps(
                       _mm_add_ps(
                         v295,
                         _mm_mul_ps(*(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x280), v290)),
                       v277));
            v299 = _mm_mul_ps(_mm_shuffle_ps(v270, v270, 255), v9);
            v300 = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_add_ps(
                           _mm_add_ps(
                             _mm_add_ps(_mm_mul_ps(v267, v294), v9),
                             _mm_mul_ps(*(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0xC0), v296)),
                           _mm_mul_ps(*(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0xB0), v297)),
                         v299),
                       *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x90)),
                     v9);
            v301 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(*(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x110), v294),
                       v9),
                     _mm_mul_ps(*(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x150), v296));
            v302 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(*(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x80), v294),
                         v9),
                       _mm_mul_ps(*(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x70), v296)),
                     _mm_mul_ps(*(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x170), v297));
            v303 = _mm_mul_ps(*(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0xF0), v296);
            v304 = *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x230);
            v305 = _mm_add_ps(
                     v301,
                     _mm_mul_ps(*(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x120), v297));
            v306 = _mm_mul_ps(*(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x230), v297);
            v68 = *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0xA0);
            v307 = _mm_add_ps(
                     v300,
                     _mm_mul_ps(
                       _mm_add_ps(v302, v299),
                       *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x130)));
            v308 = _mm_mul_ps(*(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x100), v294);
            v309 = *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x70);
            v310 = _mm_add_ps(
                     v307,
                     _mm_mul_ps(
                       _mm_add_ps(v305, v299),
                       *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0xE0)));
            v311 = *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0xC0);
            v312 = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_add_ps(v308, v9), v303), v306), v299);
            v313 = _mm_shuffle_ps(v269, v269, 0);
            v314 = _mm_shuffle_ps(v269, v269, 85);
            *v244 = _mm_shuffle_ps(v298, _mm_shuffle_ps(v298, v272, 250), 148);
            v315 = _mm_max_ps(
                     _mm_add_ps(v310, _mm_mul_ps(v312, v277)),
                     *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x270));
            v316 = _mm_shuffle_ps(v269, v269, 170);
            v317 = _mm_min_ps(v315, v68);
            v318 = _mm_mul_ps(_mm_shuffle_ps(v269, v269, 255), v9);
            v251 = *(_QWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x18);
            v242 = *(_QWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x30);
            v12 = *(_DWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x60);
            v319 = _mm_cvtps_epi32(
                     _mm_cvtepi32_ps(
                       _mm_cvtps_epi32(
                         _mm_add_ps(
                           _mm_mul_ps(
                             _mm_min_ps(
                               _mm_max_ps(
                                 _mm_add_ps(
                                   _mm_add_ps(
                                     _mm_add_ps(
                                       _mm_add_ps(
                                         _mm_mul_ps(
                                           _mm_add_ps(
                                             _mm_add_ps(
                                               _mm_add_ps(
                                                 _mm_add_ps(_mm_mul_ps(v267, v313), v9),
                                                 _mm_mul_ps(v311, v314)),
                                               _mm_mul_ps(
                                                 *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0xB0),
                                                 v316)),
                                             v318),
                                           *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x90)),
                                         v9),
                                       _mm_mul_ps(
                                         _mm_add_ps(
                                           _mm_add_ps(
                                             _mm_add_ps(
                                               _mm_add_ps(
                                                 _mm_mul_ps(
                                                   *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x80),
                                                   v313),
                                                 v9),
                                               _mm_mul_ps(v309, v314)),
                                             _mm_mul_ps(
                                               *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x170),
                                               v316)),
                                           v318),
                                         *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x130))),
                                     _mm_mul_ps(
                                       _mm_add_ps(
                                         _mm_add_ps(
                                           _mm_add_ps(
                                             _mm_add_ps(
                                               _mm_mul_ps(
                                                 *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x110),
                                                 v313),
                                               v9),
                                             _mm_mul_ps(
                                               *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x150),
                                               v314)),
                                           _mm_mul_ps(
                                             *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x120),
                                             v316)),
                                         v318),
                                       *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0xE0))),
                                   _mm_mul_ps(
                                     _mm_add_ps(
                                       _mm_add_ps(
                                         _mm_add_ps(
                                           _mm_add_ps(
                                             _mm_mul_ps(
                                               *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x100),
                                               v313),
                                             v9),
                                           _mm_mul_ps(
                                             *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0xF0),
                                             v314)),
                                         _mm_mul_ps(v304, v316)),
                                       v318),
                                     v277)),
                                 *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x270)),
                               v68),
                             v11),
                           v11))));
            v320 = _mm_cvtps_epi32(
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_shuffle_ps(
                           v317,
                           _mm_shuffle_ps(
                             v317,
                             _mm_or_ps(
                               _mm_andnot_ps(
                                 v68,
                                 _mm_cmpltps(
                                   *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x2B0),
                                   v9)),
                               *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x250)),
                             250),
                           148),
                         v11),
                       v11));
            v253 = *(__m128 *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x250);
          }
          v325 = _mm_packs_epi32(v319, v319);
          v251 += 24i64;
          v244 = (__m128 *)((char *)v244 + 24);
          v252 += 24i64;
          ++v69;
          --v242;
          *(_QWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x18) = v251;
          *(_QWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x30) = v242;
          *(_DWORD *)(v252 - 24) = (unsigned __int128)_mm_packus_epi16(v325, v325);
          v326 = _mm_cvtps_epi32(_mm_cvtepi32_ps(v320));
          v327 = _mm_packs_epi32(v326, v326);
          *(_DWORD *)(v251 - 24) = (unsigned __int128)_mm_packus_epi16(v327, v327);
        }
        while ( v242 );
        v240 = *(_DWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x10);
        v8 = *(_DWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0xC);
        v239 = *(_DWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x40);
        v234 = *(__m128 **)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0xD0);
        v236 = *(__m128 **)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x50);
      }
      v235 = *(__m128 **)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 0x20);
      v238 = *(_DWORD *)(((unsigned __int64)&v328 & 0xFFFFFFFFFFFFFF80ui64) + 4);
    }
    while ( v8 );
  }
}

