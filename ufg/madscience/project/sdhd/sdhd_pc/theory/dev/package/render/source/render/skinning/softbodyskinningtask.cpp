// File Line: 42
// RVA: 0x1453D10
__int64 Render::_dynamic_initializer_for__gTaskFunctionDecl_SoftbodySkinBufferTask__()
{
  UFG::qTaskFunctionDecl::qTaskFunctionDecl(
    &Render::gTaskFunctionDecl_SoftbodySkinBufferTask,
    &Render::gTaskFunctionDeclData_SoftbodySkinBufferTask);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gTaskFunctionDecl_SoftbodySkinBufferTask__);
}

// File Line: 216
// RVA: 0x23A20
void __fastcall Render::ApplySpringConstraints(
        __m128 *spring_data,
        unsigned int spring_size,
        __m128 *v_zero,
        __m128 *v_minus_half,
        __m128 *v_one,
        __m128 *v_minus_one,
        __m128 *v_sign_bit,
        __m128 *v_w_mask,
        __m128 *v_one_over_4096,
        unsigned int worker_id,
        Render::VerletVert *verlet_vertices)
{
  unsigned int v14; // eax
  signed int v15; // r8d
  unsigned int v16; // r9d
  __m128 *p_m_S0_output; // rbx
  unsigned int v18; // r10d
  __m128 v19; // xmm7
  int v20; // ebp
  __m128 v21; // xmm7
  int v22; // r14d
  unsigned int v23; // esi
  unsigned int v24; // r9d
  __int64 v25; // rcx
  __m128 v26; // xmm8
  __m128 v27; // xmm13
  __m128 v28; // xmm11
  unsigned int v29; // r11d
  __m128 v30; // xmm12
  __int64 v31; // rdi
  __m128 v32; // xmm6
  __m128 v33; // xmm10
  __m128 v34; // xmm5
  __int64 v35; // rdx
  __m128 v36; // xmm14
  __m128 v37; // xmm15
  __m128 v38; // xmm13
  __m128 v39; // xmm12
  __m128 v40; // xmm14
  __m128 v41; // xmm15
  __m128 v42; // xmm4
  __m128 v43; // xmm3
  __m128 v44; // xmm2
  __m128 v45; // xmm4
  __m128 v46; // xmm2
  __m128 v47; // xmm0
  __m128 v48; // xmm7
  __m128 v49; // xmm8
  __m128 v50; // xmm7
  __m128 v51; // xmm4
  __m128 v52; // xmm5
  __m128 v53; // xmm2
  __m128 v54; // xmm1
  __m128 v55; // xmm7
  __m128 v56; // xmm5
  bool v57; // zf
  __m128i *v58; // rcx
  unsigned int v59; // r8d
  unsigned int v60; // r9d
  __int16 v61; // bp
  unsigned int v62; // eax
  __m128 v63; // xmm8
  unsigned int v64; // ebx
  unsigned int v65; // edi
  __int64 v66; // rcx
  unsigned __int16 v67; // r14
  __m128 v68; // xmm8
  unsigned __int16 v69; // bp
  unsigned __int16 v70; // r9
  __m128 v71; // xmm6
  __m128 v72; // xmm9
  __m128 v73; // xmm10
  unsigned __int8 v74; // r11
  unsigned __int8 v75; // bl
  __int64 v76; // r8
  unsigned __int8 v77; // di
  __m128 v78; // xmm8
  __m128 v79; // xmm4
  __m128 v80; // xmm5
  __m128 v81; // xmm2
  __m128 v82; // xmm0
  __m128 v83; // xmm1
  __m128 v84; // xmm3
  __m128 v85; // xmm2
  unsigned int v86; // eax
  __int64 v87; // r8
  __int64 v88; // rcx
  __m128 v89; // xmm5
  __m128 v90; // xmm3
  __m128 v91; // xmm0
  __m128 v92; // xmm1
  __m128 v93; // xmm4
  __m128 v94; // xmm2
  unsigned int v95; // eax
  __int64 v96; // r8
  __int64 v97; // rcx
  __m128 v98; // xmm5
  __m128 v99; // xmm3
  __m128 v100; // xmm0
  __m128 v101; // xmm1
  __m128 v102; // xmm4
  __m128 v103; // xmm2
  unsigned int v104; // eax
  __int64 v105; // rcx
  __int64 v106; // r8
  __m128 v107; // xmm5
  __m128 v108; // xmm3
  __m128 v109; // xmm0
  __m128 v110; // xmm1
  __m128 v111; // xmm4
  __m128 v112; // xmm2
  __int64 v113; // [rsp+0h] [rbp-F8h]
  __m128 mPosition; // [rsp+10h] [rbp-E8h]
  unsigned int v116; // [rsp+108h] [rbp+10h]
  Render::VerletVert *verlet_verticesa; // [rsp+150h] [rbp+58h]

  v14 = 0;
  v15 = (spring_size >> 4) - 1;
  v16 = 0;
  v113 = v15;
  if ( v15 > 0 )
  {
    p_m_S0_output = (__m128 *)&spring_data->m128_f32[3];
    v116 = (spring_size >> 4) - 1;
    verlet_verticesa = (Render::VerletVert *)&spring_data->m128_u32[3];
    do
    {
      v18 = p_m_S0_output[-1].m128_u32[3];
      v19 = _mm_add_ps(
              _mm_mul_ps(
                _mm_cvtepi32_ps(
                  _mm_srai_epi32(
                    _mm_unpacklo_epi16(
                      *(__m128i *)((char *)&p_m_S0_output[-1] + 4),
                      *(__m128i *)((char *)&p_m_S0_output[-1] + 4)),
                    0x10u)),
                *v_one_over_4096),
              *v_zero);
      v20 = HIWORD(v18) & 0x3FFF;
      v21 = _mm_add_ps(_mm_mul_ps(v19, v19), *v_zero);
      v22 = HIWORD(p_m_S0_output->m128_i32[0]) & 0x3FFF;
      v23 = (v18 >> 30) + v14;
      v24 = ((unsigned __int16)v18 >> 14) + v23;
      v25 = v23;
      mPosition = verlet_vertices[v23 - v20].mPosition;
      v26 = verlet_vertices[v24].mPosition;
      v27 = _mm_sub_ps(mPosition, verlet_vertices[v25].mPosition);
      v28 = verlet_vertices[v24 - (v18 & 0x3FFF)].mPosition;
      v29 = ((unsigned int)p_m_S0_output->m128_i32[0] >> 30) + v24;
      v14 = ((unsigned __int16)p_m_S0_output->m128_i32[0] >> 14) + v29;
      v30 = _mm_sub_ps(v28, v26);
      v31 = v14;
      v32 = verlet_vertices[v29].mPosition;
      v33 = verlet_vertices[v29 - v22].mPosition;
      v34 = verlet_vertices[v31].mPosition;
      v35 = v14 - (p_m_S0_output->m128_i32[0] & 0x3FFF);
      v36 = _mm_sub_ps(v33, v32);
      v37 = _mm_sub_ps(verlet_vertices[v35].mPosition, v34);
      v38 = _mm_shuffle_ps(v27, _mm_shuffle_ps(v27, *v_zero, 250), 148);
      v39 = _mm_shuffle_ps(v30, _mm_shuffle_ps(v30, *v_zero, 250), 148);
      v40 = _mm_shuffle_ps(v36, _mm_shuffle_ps(v36, *v_zero, 250), 148);
      v41 = _mm_shuffle_ps(v37, _mm_shuffle_ps(v37, *v_zero, 250), 148);
      v42 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v39, v39, 0), gVmxIdentity1_2),
                  _mm_add_ps(_mm_mul_ps(v38, gVmxIdentity0_2), *v_zero)),
                _mm_mul_ps(_mm_shuffle_ps(v40, v40, 0), gVmxIdentity2_2)),
              _mm_mul_ps(_mm_shuffle_ps(v41, v41, 0), gVmxIdentity3_2));
      v43 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v38, v38, 85), gVmxIdentity0_2), *v_zero),
                  _mm_mul_ps(v39, gVmxIdentity1_2)),
                _mm_mul_ps(_mm_shuffle_ps(v40, v40, 85), gVmxIdentity2_2)),
              _mm_mul_ps(_mm_shuffle_ps(v41, v41, 85), gVmxIdentity3_2));
      v44 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v38, v38, 170), gVmxIdentity0_2), *v_zero),
                  _mm_mul_ps(_mm_shuffle_ps(v39, v39, 170), gVmxIdentity1_2)),
                _mm_mul_ps(v40, gVmxIdentity2_2)),
              _mm_mul_ps(_mm_shuffle_ps(v41, v41, 170), gVmxIdentity3_2));
      v45 = _mm_add_ps(
              _mm_add_ps(_mm_add_ps(_mm_mul_ps(v42, v42), *v_zero), _mm_mul_ps(v43, v43)),
              _mm_mul_ps(v44, v44));
      v46 = verlet_vertices[v25].mPosition;
      v47 = _mm_add_ps(_mm_mul_ps(_mm_rcp_ps(_mm_add_ps(v45, v21)), v21), *v_minus_half);
      v48 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v46, v46, 255), gVmxIdentity0_2), *v_zero),
                    _mm_mul_ps(_mm_shuffle_ps(v26, v26, 255), gVmxIdentity1_2)),
                  _mm_mul_ps(_mm_shuffle_ps(v32, v32, 255), gVmxIdentity2_2)),
                _mm_mul_ps(_mm_shuffle_ps(v34, v34, 255), gVmxIdentity3_2)),
              *v_minus_one);
      v49 = *v_zero;
      v50 = _mm_add_ps(_mm_mul_ps(v48, v47), *v_zero);
      v51 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v50, v50, 85), v39), *v_zero);
      v52 = _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_or_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(mPosition, mPosition, 255), gVmxIdentity0_2), *v_zero),
                          _mm_mul_ps(_mm_shuffle_ps(v28, v28, 255), gVmxIdentity1_2)),
                        _mm_mul_ps(_mm_shuffle_ps(v33, v33, 255), gVmxIdentity2_2)),
                      _mm_mul_ps(
                        _mm_shuffle_ps(verlet_vertices[v35].mPosition, verlet_vertices[v35].mPosition, 255),
                        gVmxIdentity3_2)),
                    *v_sign_bit),
                  *v_one),
                v47),
              *v_zero);
      verlet_vertices[v25].mPosition = _mm_add_ps(
                                         _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v50, v50, 0), v38), *v_zero),
                                         v46);
      verlet_vertices[v23 - v20].mPosition = _mm_add_ps(
                                               _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v52, v52, 0), v38), v49),
                                               mPosition);
      v53 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v50, v50, 170), v40), *v_zero);
      v54 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v52, v52, 170), v40), *v_zero);
      verlet_vertices[v24].mPosition = _mm_add_ps(v51, verlet_vertices[v24].mPosition);
      verlet_vertices[v24 - (v18 & 0x3FFF)].mPosition = _mm_add_ps(
                                                          _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v52, v52, 85), v39), v49),
                                                          verlet_vertices[v24 - (v18 & 0x3FFF)].mPosition);
      v55 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v50, v50, 255), v41), *v_zero);
      v56 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v52, v52, 255), v41), *v_zero);
      verlet_vertices[v29].mPosition = _mm_add_ps(v53, verlet_vertices[v29].mPosition);
      verlet_vertices[v29 - v22].mPosition = _mm_add_ps(verlet_vertices[v29 - v22].mPosition, v54);
      p_m_S0_output = &verlet_verticesa->m_S0_output;
      v57 = v113-- == 1;
      verlet_verticesa = (Render::VerletVert *)((char *)verlet_verticesa + 16);
      verlet_vertices[v31].mPosition = _mm_add_ps(v55, verlet_vertices[v31].mPosition);
      verlet_vertices[v35].mPosition = _mm_add_ps(v56, verlet_vertices[v35].mPosition);
    }
    while ( !v57 );
    v16 = v116;
  }
  v58 = (__m128i *)&spring_data[v16];
  v59 = v58->m128i_u32[2];
  v60 = v58->m128i_u32[3];
  v61 = v58->m128i_i16[6];
  v62 = (v59 >> 30) + v14;
  v63 = _mm_add_ps(
          _mm_mul_ps(_mm_cvtepi32_ps(_mm_srai_epi32(_mm_unpacklo_epi16(*v58, *v58), 0x10u)), *v_one_over_4096),
          *v_zero);
  v64 = v60 >> 30;
  v65 = v60 >> 14;
  v66 = v62 - (HIWORD(v59) & 0x3FFF);
  v67 = v59 & 0x3FFF;
  v68 = _mm_add_ps(_mm_mul_ps(v63, v63), *v_zero);
  v69 = v61 & 0x3FFF;
  v70 = HIWORD(v60) & 0x3FFF;
  v71 = _mm_shuffle_ps(v68, v68, 0);
  v72 = _mm_shuffle_ps(v68, v68, 85);
  v73 = _mm_shuffle_ps(v68, v68, 170);
  v74 = (v59 >> 14) & 3;
  v75 = v64 & 3;
  v76 = v62;
  v77 = v65 & 3;
  v66 *= 32i64;
  v78 = _mm_shuffle_ps(v68, v68, 255);
  v79 = verlet_vertices[v76].mPosition;
  v80 = *(__m128 *)((char *)&verlet_vertices->mPosition + v66);
  v81 = _mm_sub_ps(v80, v79);
  v82 = _mm_add_ps(_mm_mul_ps(v81, v81), *v_zero);
  v83 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v82, v82, 85), v82), _mm_shuffle_ps(v82, v82, 170));
  v84 = _mm_and_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(_mm_mul_ps(_mm_rcp_ps(_mm_add_ps(_mm_shuffle_ps(v83, v83, 0), v71)), v71), *v_minus_half),
              v81),
            *v_zero),
          *v_w_mask);
  v85 = _mm_mul_ps(_mm_sub_ps(*v_one, _mm_shuffle_ps(v80, v80, 255)), v84);
  verlet_vertices[v76].mPosition = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(_mm_shuffle_ps(v79, v79, 255), *v_one), v84), v79);
  *(__m128 *)((char *)&verlet_vertices->mPosition + v66) = _mm_add_ps(v85, v80);
  if ( v67 )
  {
    v86 = v74 + v62;
    v87 = v86 - v67;
    v88 = v86;
    v89 = verlet_vertices[v88].mPosition;
    v90 = _mm_sub_ps(verlet_vertices[v87].mPosition, v89);
    v91 = _mm_add_ps(_mm_mul_ps(v90, v90), *v_zero);
    v92 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v91, v91, 85), v91), _mm_shuffle_ps(v91, v91, 170));
    v93 = _mm_and_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(_mm_mul_ps(_mm_rcp_ps(_mm_add_ps(_mm_shuffle_ps(v92, v92, 0), v72)), v72), *v_minus_half),
                v90),
              *v_zero),
            *v_w_mask);
    v94 = _mm_add_ps(
            _mm_mul_ps(
              _mm_sub_ps(*v_one, _mm_shuffle_ps(verlet_vertices[v87].mPosition, verlet_vertices[v87].mPosition, 255)),
              v93),
            verlet_vertices[v87].mPosition);
    verlet_vertices[v88].mPosition = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(_mm_shuffle_ps(v89, v89, 255), *v_one), v93), v89);
    verlet_vertices[v87].mPosition = v94;
    if ( v70 )
    {
      v95 = v75 + v86;
      v96 = v95 - v70;
      v97 = v95;
      v98 = verlet_vertices[v97].mPosition;
      v99 = _mm_sub_ps(verlet_vertices[v96].mPosition, v98);
      v100 = _mm_add_ps(_mm_mul_ps(v99, v99), *v_zero);
      v101 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v100, v100, 85), v100), _mm_shuffle_ps(v100, v100, 170));
      v102 = _mm_and_ps(
               _mm_add_ps(
                 _mm_mul_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_rcp_ps(_mm_add_ps(_mm_shuffle_ps(v101, v101, 0), v73)), v73),
                     *v_minus_half),
                   v99),
                 *v_zero),
               *v_w_mask);
      v103 = _mm_add_ps(
               _mm_mul_ps(
                 _mm_sub_ps(*v_one, _mm_shuffle_ps(verlet_vertices[v96].mPosition, verlet_vertices[v96].mPosition, 255)),
                 v102),
               verlet_vertices[v96].mPosition);
      verlet_vertices[v97].mPosition = _mm_add_ps(
                                         _mm_mul_ps(_mm_sub_ps(_mm_shuffle_ps(v98, v98, 255), *v_one), v102),
                                         v98);
      verlet_vertices[v96].mPosition = v103;
      if ( v69 )
      {
        v104 = v77 + v95;
        v105 = v104;
        v106 = v104 - v69;
        v107 = verlet_vertices[v105].mPosition;
        v108 = _mm_sub_ps(verlet_vertices[v106].mPosition, v107);
        v109 = _mm_add_ps(_mm_mul_ps(v108, v108), *v_zero);
        v110 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v109, v109, 85), v109), _mm_shuffle_ps(v109, v109, 170));
        v111 = _mm_and_ps(
                 _mm_add_ps(
                   _mm_mul_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_rcp_ps(_mm_add_ps(_mm_shuffle_ps(v110, v110, 0), v78)), v78),
                       *v_minus_half),
                     v108),
                   *v_zero),
                 *v_w_mask);
        v112 = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_sub_ps(
                     *v_one,
                     _mm_shuffle_ps(verlet_vertices[v106].mPosition, verlet_vertices[v106].mPosition, 255)),
                   v111),
                 verlet_vertices[v106].mPosition);
        verlet_vertices[v105].mPosition = _mm_add_ps(
                                            _mm_mul_ps(_mm_sub_ps(_mm_shuffle_ps(v107, v107, 255), *v_one), v111),
                                            v107);
        verlet_vertices[v106].mPosition = v112;
      }
    }
  }
}

// File Line: 559
// RVA: 0x21E40
void __fastcall Render::SoftbodySkinBufferTask(
        unsigned int worker_id,
        UFG::qMemoryStreamer *memory_streamer,
        _QWORD *param0,
        void *param1)
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
  __m128i si128; // xmm12
  __m128 v17; // xmm8
  __int64 v18; // rax
  __m128 v19; // xmm9
  __m128 v20; // xmm11
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
  int v39; // r8d
  __int64 v40; // rcx
  __m128 *v41; // rax
  __m128 v42; // xmm5
  __m128 v43; // xmm11
  __m128 v44; // xmm12
  __m128 v45; // xmm13
  __m128 v46; // xmm4
  __m128 v47; // xmm3
  __m128 v48; // xmm8
  __m128 v49; // xmm5
  __m128 v50; // xmm1
  __m128 v51; // xmm6
  __m128 v52; // xmm7
  __m128 v53; // xmm0
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
  unsigned int v69; // r12d
  int v70; // edx
  __int64 v71; // rax
  unsigned __int16 *v72; // rax
  int v73; // ecx
  int v74; // r9d
  __int64 v75; // rbx
  __int64 v76; // r11
  unsigned int v77; // r8d
  unsigned __int64 v78; // rax
  unsigned __int64 v79; // rcx
  unsigned __int64 v80; // rbx
  unsigned __int64 v81; // r11
  __int64 v82; // rax
  __m128 v83; // xmm5
  __m128 *v84; // r14
  __int16 *v85; // rdi
  __m128 v86; // xmm4
  __int64 v87; // r13
  __m128 *v88; // rdx
  unsigned __int64 v89; // rcx
  unsigned int v90; // r8d
  int v91; // ecx
  __int64 v92; // rbx
  __m128 v93; // xmm1
  __m128 *v94; // r9
  __int64 v95; // rcx
  __m128 v96; // xmm7
  __int64 v97; // rdx
  __int64 v98; // r8
  __m128 v99; // xmm0
  __m128 v100; // xmm1
  __m128 v101; // xmm12
  __m128i v102; // xmm2
  __int64 v103; // r9
  __m128i v104; // xmm2
  __m128 v105; // xmm0
  __m128 v106; // xmm1
  __m128 v107; // xmm11
  __m128 v108; // xmm0
  __m128 v109; // xmm1
  __m128 v110; // xmm14
  __m128 v111; // xmm0
  __m128 v112; // xmm1
  __m128 v113; // xmm13
  __m128 v114; // xmm1
  __m128 v115; // xmm0
  __m128 v116; // xmm3
  __m128 v117; // xmm15
  __m128 v118; // xmm0
  __m128 v119; // xmm3
  __m128 v120; // xmm1
  __m128 v121; // xmm0
  __m128 v122; // xmm4
  __m128 v123; // xmm1
  __m128 v124; // xmm0
  __m128 v125; // xmm8
  __m128 v126; // xmm9
  __m128 v127; // xmm10
  __m128 v128; // xmm5
  __m128 v129; // xmm6
  __m128 v130; // xmm7
  __m128 v131; // xmm1
  __m128 v132; // xmm2
  __m128 v133; // xmm3
  __m128 v134; // xmm1
  __m128 v135; // xmm0
  __m128 v136; // xmm3
  __m128 v137; // xmm4
  __m128 v138; // xmm6
  __m128 v139; // xmm0
  __m128 v140; // xmm5
  __m128 v141; // xmm2
  __m128 v142; // xmm3
  __m128 v143; // xmm2
  __m128 v144; // xmm1
  __m128 v145; // xmm3
  __m128 v146; // xmm7
  __m128 v147; // xmm0
  __m128 v148; // xmm2
  __m128 v149; // xmm3
  __m128 v150; // xmm1
  __m128 v151; // xmm6
  __m128 v152; // xmm0
  __m128 v153; // xmm5
  __m128 v154; // xmm2
  __m128 v155; // xmm1
  __m128 v156; // xmm0
  __m128 v157; // xmm2
  __m128 v158; // xmm0
  __m128 v159; // xmm6
  __m128 v160; // xmm5
  __m128 v161; // xmm11
  __m128 v162; // xmm11
  float v163; // xmm15_4
  float v164; // xmm12_4
  unsigned int v165; // eax
  float v166; // xmm13_4
  float v167; // xmm9_4
  float v168; // xmm10_4
  float v169; // xmm7_4
  float v170; // xmm8_4
  float v171; // xmm6_4
  float v172; // xmm3_4
  float v173; // xmm2_4
  float v174; // xmm1_4
  float v175; // xmm4_4
  float v176; // xmm5_4
  float v177; // xmm3_4
  float v178; // xmm0_4
  float v179; // xmm7_4
  float v180; // xmm3_4
  float v181; // xmm2_4
  __m128i v182; // xmm0
  unsigned int v183; // eax
  float v184; // xmm4_4
  __m128i v185; // xmm1
  int v186; // eax
  float v187; // xmm2_4
  float v188; // xmm7_4
  float v189; // xmm3_4
  float v190; // xmm4_4
  __m128 v191; // xmm8
  float v192; // xmm9_4
  __m128 v193; // xmm7
  float v194; // xmm12_4
  float v195; // xmm10_4
  float v196; // xmm13_4
  float v197; // xmm5_4
  float v198; // xmm3_4
  __m128 v199; // xmm1
  __m128 v200; // xmm2
  float v201; // xmm4_4
  float v202; // xmm5_4
  __m128 v203; // xmm0
  float v204; // xmm3_4
  __m128 v205; // xmm5
  __m128 v206; // xmm4
  __m128 v207; // xmm7
  __m128 v208; // xmm1
  __m128 v209; // xmm1
  __m128 v210; // xmm1
  __m128 v211; // xmm5
  __m128 v212; // xmm7
  __m128 v213; // xmm3
  __m128 v214; // xmm2
  __m128 v215; // xmm0
  __m128i v216; // xmm0
  __m128i v217; // xmm2
  __m128i v218; // xmm2
  __m128 v219; // xmm0
  __m128i v220; // xmm0
  __m128i v221; // xmm2
  __m128i v222; // xmm2
  unsigned int v223; // r13d
  __m128 *v224; // rsi
  __int64 v225; // rbx
  __m128 *v226; // r8
  __int64 v227; // r9
  __m128 v228; // xmm2
  int v229; // ecx
  __int64 v230; // r14
  __m128 *v231; // r10
  __int64 v232; // r15
  int v233; // eax
  unsigned int v234; // r11d
  unsigned int v235; // r9d
  unsigned int v236; // edx
  __int64 v237; // r13
  __int64 v238; // r8
  __int64 v239; // rcx
  __m128 *v240; // rbx
  __int64 v241; // rax
  _OWORD *v242; // r10
  __int64 v243; // rcx
  __m128 *v244; // r11
  char v245; // al
  __m128 v246; // xmm8
  char *v247; // rcx
  __m128 *v248; // r13
  __m128 v249; // xmm8
  __int64 v250; // rdx
  __m128 v251; // xmm1
  __m128 v252; // xmm8
  __m128i v253; // xmm7
  __m128 v254; // xmm3
  __m128 v255; // xmm4
  __m128 v256; // xmm5
  int v257; // edi
  int v258; // esi
  int v259; // r14d
  int v260; // r15d
  __m128 v261; // xmm2
  __m128 v262; // xmm8
  __m128 v263; // xmm13
  __m128 v264; // xmm10
  __m128 v265; // xmm11
  __m128 v266; // xmm10
  __int128 v267; // xmm1
  __m128 v268; // xmm12
  __m128 v269; // xmm9
  __m128 v270; // xmm2
  __m128 v271; // xmm5
  __m128 v272; // xmm7
  __m128 v273; // xmm9
  __int64 v274; // rax
  __int64 v275; // rdi
  __int64 v276; // rcx
  int v277; // r15d
  __m128 v278; // xmm3
  __int64 v279; // rdx
  __m128 v280; // xmm4
  __m128 v281; // xmm3
  __m128 v282; // xmm4
  __m128 v283; // xmm4
  __m128 v284; // xmm5
  __m128 v285; // xmm6
  __m128 v286; // xmm8
  __m128 v287; // xmm7
  __m128 v288; // xmm2
  __m128 v289; // xmm3
  __m128 v290; // xmm4
  __m128 v291; // xmm2
  __m128 v292; // xmm5
  __m128 v293; // xmm6
  __m128 v294; // xmm7
  __m128 v295; // xmm10
  __m128 v296; // xmm8
  __m128 v297; // xmm3
  __m128 v298; // xmm2
  __m128 v299; // xmm0
  __m128 v300; // xmm5
  __m128 v301; // xmm3
  __m128 v302; // xmm1
  __m128 v303; // xmm8
  __m128 v304; // xmm2
  __m128 v305; // xmm4
  __m128 v306; // xmm8
  __m128 v307; // xmm3
  __m128 v308; // xmm2
  __m128 v309; // xmm0
  __m128 v310; // xmm1
  __m128 v311; // xmm8
  __m128 v312; // xmm2
  __m128 v313; // xmm8
  __m128 v314; // xmm11
  __m128i v315; // xmm2
  __m128i v316; // xmm0
  __m128 v317; // xmm0
  __m128 v318; // xmm3
  __m128 v319; // xmm0
  __m128 v320; // xmm3
  __m128i v321; // xmm2
  __m128i v322; // xmm2
  __m128i v323; // xmm2
  char v324[4]; // [rsp+E0h] [rbp+0h] BYREF

  v4 = (unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64;
  v5 = param0[10];
  v6 = gVmxOne_2;
  v7 = param0[9] == 0i64;
  v8 = *((_DWORD *)param0 + 16);
  v9 = 0i64;
  v10 = gVmxMinusOne_0;
  v11 = gVmx127_0;
  v12 = *(_DWORD *)(v5 + 364);
  v13 = *(_QWORD *)(v5 + 392);
  v14 = *(_QWORD *)(v5 + 400);
  v15 = gVmxOneOver127_0;
  si128 = gVmxUnpackBias_0;
  v17 = (__m128)gVmxUnpackMask_0;
  *(_QWORD *)(v4 + 720) = *(_QWORD *)(v5 + 40);
  v18 = *(_QWORD *)(v5 + 24);
  v19 = gVmxUnpackUnbias_0;
  v20 = gVmxUnpackShift_0;
  *(__m128 *)(v4 + 672) = gVmxMinusHalf;
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
  *(__m128i *)(v4 + 352) = gVmxUnpackBias_0;
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
  v35 = param0[4];
  v36 = (unsigned __int8 *)param0[13];
  *(__m128i *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0xC0) = v33;
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
        v41 = (__m128 *)(param0[12] + (unsigned int)(v39 << 6));
        v42 = *(__m128 *)(v40 + v35 + 16);
        v43 = v41[1];
        v44 = v41[2];
        v45 = v41[3];
        v46 = _mm_shuffle_ps(v42, v42, 255);
        v47 = _mm_add_ps(v42, v42);
        v48 = _mm_shuffle_ps(v42, v42, 201);
        v49 = _mm_shuffle_ps(v42, v42, 210);
        v50 = _mm_shuffle_ps(v47, v47, 201);
        v51 = _mm_sub_ps(v6, _mm_mul_ps(v50, v48));
        v52 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v50, v46), (__m128)0i64), _mm_mul_ps(v49, v47));
        v53 = _mm_shuffle_ps(v47, v47, 210);
        v54 = _mm_sub_ps(_mm_add_ps(_mm_mul_ps(v48, v47), (__m128)0i64), _mm_mul_ps(v53, v46));
        v55 = _mm_sub_ps(v51, _mm_mul_ps(v53, v49));
        v56 = _mm_shuffle_ps(_mm_shuffle_ps(v52, v54, 80), v54, 233);
        v57 = _mm_shuffle_ps(_mm_shuffle_ps(v54, v55, 80), v55, 233);
        v58 = _mm_shuffle_ps(_mm_shuffle_ps(v55, v52, 80), v52, 233);
        v59 = _mm_shuffle_ps(v56, _mm_shuffle_ps(v55, v56, 250), 148);
        v60 = _mm_shuffle_ps(v57, _mm_shuffle_ps(v52, v57, 250), 148);
        v61 = _mm_shuffle_ps(v58, _mm_shuffle_ps(v54, v58, 250), 148);
        v62 = _mm_shuffle_ps(v61, _mm_shuffle_ps(v61, (__m128)0i64, 250), 148);
        v63 = _mm_shuffle_ps(v60, _mm_shuffle_ps(v60, (__m128)0i64, 250), 148);
        v64 = _mm_shuffle_ps(v59, _mm_shuffle_ps(v59, (__m128)0i64, 250), 148);
        v65 = _mm_shuffle_ps(
                *(__m128 *)(v40 + v35),
                _mm_shuffle_ps(
                  *(__m128 *)(v40 + v35),
                  *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0xA0),
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
        v6 = *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0xA0);
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
    v11 = *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0xE0);
    v17 = *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x260);
    v19 = *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x220);
    v20 = *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x140);
    si128 = _mm_load_si128((const __m128i *)(v4 + 352));
    v15 = *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x240);
    v10 = *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x270);
  }
  v67 = FLOAT_4096_0;
  v68 = *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0xA0);
  v69 = 0;
  *(_QWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x200) = ((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64)
                                                                         + 464;
  *(_QWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x1D0) = "<unassigned>";
  *(_QWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x208) = ((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64)
                                                                         + 488;
  *(_QWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x1E8) = "<unassigned>";
  *(_QWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x180) = "<unassigned>";
  *(_QWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x198) = "<unassigned>";
  v70 = 0;
  *(_QWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x1B0) = ((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64)
                                                                         + 384;
  *(_DWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x1E0) = 0;
  *(_QWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x1B8) = ((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64)
                                                                         + 408;
  v71 = 0i64;
  *(_QWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x1F0) = 0i64;
  if ( !v7 )
    v71 = param0[9];
  *(_DWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x1F8) = 0;
  *(_DWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x210) = 0;
  *(_QWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x2D8) = v71;
  v72 = *(unsigned __int16 **)(v5 + 384);
  *(_DWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x190) = 0;
  v73 = *v72;
  *(_QWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x1A0) = 0i64;
  *(_DWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x1A8) = 0;
  v74 = 0;
  v75 = param0[2] + (unsigned int)(8 * v73);
  *(_DWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x1C0) = 0;
  v76 = param0[1] + (unsigned int)(24 * v73);
  v77 = 0;
  v78 = v75 & 0xFFFFFFFFFFFFFFF0ui64;
  v79 = v76 & 0xFFFFFFFFFFFFFFF0ui64;
  v80 = v75 - (v75 & 0xFFFFFFFFFFFFFFF0ui64);
  *(_QWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x188) = v78;
  v81 = v76 - (v76 & 0xFFFFFFFFFFFFFFF0ui64);
  *(_QWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x1D8) = v79;
  if ( v12 )
  {
    v82 = *(_QWORD *)(v5 + 400);
    v83 = *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0xC0);
    v84 = (__m128 *)(v4 + 17152);
    v85 = (__int16 *)(v82 + 4);
    *(_QWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x18) = *(_QWORD *)(v5 + 384) + 2i64;
    v86 = _mm_and_ps(v83, v68);
    *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x110) = v86;
    *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x150) = _mm_and_ps(v10, v68);
    v87 = v13 - v82;
    do
    {
      v88 = (__m128 *)(v81
                     + *(_QWORD *)(*(_QWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64)
                                             + 0x200
                                             + 8i64 * (int)v69)
                                 + 8i64));
      v89 = v80
          + *(_QWORD *)(*(_QWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x1B0 + 8i64 * v74) + 8i64);
      v90 = v77 + 1;
      *(_QWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x30) = v88;
      *(_QWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x50) = v89;
      *(_DWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x10) = v90;
      if ( v90 < v12 )
      {
        v91 = **(unsigned __int16 **)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x18);
        *(_DWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x210) = ((_BYTE)v69 - 1) & 1;
        *(_DWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x1C0) = ((_BYTE)v74 - 1) & 1;
        v88 = *(__m128 **)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x30);
        v92 = param0[2] + (unsigned int)(8 * v91);
        v81 = (param0[1] + (unsigned int)(24 * v91)) & 0xFFFFFFFFFFFFFFF0ui64;
        *(_QWORD *)(*(_QWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x200 + 8i64
                                                                                          * (((_BYTE)v69 - 1) & 1))
                  + 8i64) = v81;
        v80 = v92 & 0xFFFFFFFFFFFFFFF0ui64;
        *(_QWORD *)(*(_QWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64)
                              + 0x1B0
                              + 8i64 * *(int *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x1C0))
                  + 8i64) = v80;
        v69 = *(_DWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x210);
      }
      v93 = v88[1];
      v94 = *(__m128 **)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x50);
      v95 = (unsigned __int8)v94->m128_i8[0] << 6;
      v96 = _mm_shuffle_ps(*v88, _mm_shuffle_ps(*v88, v68, 250), 148);
      v97 = (unsigned __int8)v94->m128_i8[1] << 6;
      v98 = (unsigned __int8)v94->m128_i8[2] << 6;
      v99 = (__m128)_mm_sub_epi32((__m128i)_mm_shuffle_ps(v93, v93, 0), si128);
      v100 = (__m128)_mm_sub_epi32((__m128i)_mm_shuffle_ps(v93, v93, 85), si128);
      v101 = *(__m128 *)(v4 + 800 + v95);
      v102 = (__m128i)_mm_shuffle_ps(*v94, *v94, 85);
      v103 = (unsigned __int8)v94->m128_i8[3] << 6;
      v104 = (__m128i)_mm_and_ps(
                        (__m128)_mm_sub_epi32(
                                  v102,
                                  *(__m128i *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x160)),
                        v17);
      v105 = _mm_mul_ps(_mm_add_ps(_mm_cvtepi32_ps((__m128i)_mm_and_ps(v99, v17)), v19), v20);
      v106 = _mm_mul_ps(_mm_add_ps(_mm_cvtepi32_ps((__m128i)_mm_and_ps(v100, v17)), v19), v20);
      v107 = *(__m128 *)(v4 + 784 + v95);
      v108 = _mm_sub_ps(_mm_add_ps(v105, v9), v11);
      v109 = _mm_sub_ps(_mm_add_ps(v106, v9), v11);
      v110 = *(__m128 *)(v4 + 800 + v97);
      v111 = _mm_mul_ps(v108, v15);
      v112 = _mm_mul_ps(v109, v15);
      v113 = *(__m128 *)(v4 + 784 + v97);
      v114 = _mm_add_ps(v112, v9);
      *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x30) = _mm_add_ps(v111, v9);
      v115 = _mm_shuffle_ps(v114, v9, 250);
      v116 = _mm_shuffle_ps(v114, v114, 255);
      v117 = *(__m128 *)(v4 + 768 + v97);
      *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x120) = v116;
      *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x230) = _mm_shuffle_ps(v114, v115, 148);
      v118 = v116;
      v119 = *(__m128 *)(v4 + 768 + v98);
      v120 = _mm_or_ps(
               _mm_andnot_ps(
                 v83,
                 _mm_and_ps(v118, *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x250))),
               v86);
      v121 = _mm_mul_ps(
               _mm_add_ps(_mm_cvtepi32_ps(v104), v19),
               *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x140));
      v122 = _mm_shuffle_ps(v96, v96, 0);
      *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x100) = v120;
      v123 = *(__m128 *)(v4 + 768 + v95);
      v124 = _mm_add_ps(
               _mm_mul_ps(
                 _mm_add_ps(v121, (__m128)0i64),
                 *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x2E0)),
               (__m128)0i64);
      v125 = _mm_shuffle_ps(v124, v124, 0);
      v126 = _mm_shuffle_ps(v124, v124, 85);
      v127 = _mm_shuffle_ps(v124, v124, 170);
      *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0xF0) = _mm_shuffle_ps(v124, v124, 255);
      v128 = _mm_shuffle_ps(v96, v96, 85);
      v129 = _mm_shuffle_ps(v96, v96, 170);
      v130 = _mm_shuffle_ps(v96, v96, 255);
      *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x20) = _mm_add_ps(
                                                                                _mm_add_ps(
                                                                                  _mm_mul_ps(v123, v122),
                                                                                  (__m128)0i64),
                                                                                _mm_mul_ps(v107, v128));
      *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x20) = _mm_add_ps(
                                                                                *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64)
                                                                                          + 0x20),
                                                                                _mm_mul_ps(v101, v129));
      *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x20) = _mm_add_ps(
                                                                                _mm_mul_ps(
                                                                                  _mm_add_ps(
                                                                                    *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64)
                                                                                              + 0x20),
                                                                                    _mm_mul_ps(
                                                                                      *(__m128 *)(v4 + 816 + v95),
                                                                                      v130)),
                                                                                  v125),
                                                                                (__m128)0i64);
      v131 = _mm_mul_ps(*(__m128 *)(v4 + 800 + v98), v129);
      v132 = _mm_mul_ps(*(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x300 + v103), v122);
      *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x20) = _mm_add_ps(
                                                                                *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64)
                                                                                          + 0x20),
                                                                                _mm_mul_ps(
                                                                                  _mm_add_ps(
                                                                                    _mm_add_ps(
                                                                                      _mm_add_ps(
                                                                                        _mm_add_ps(
                                                                                          _mm_mul_ps(v117, v122),
                                                                                          (__m128)0i64),
                                                                                        _mm_mul_ps(v113, v128)),
                                                                                      _mm_mul_ps(v110, v129)),
                                                                                    _mm_mul_ps(
                                                                                      *(__m128 *)(v4 + 816 + v97),
                                                                                      v130)),
                                                                                  v126));
      v133 = _mm_add_ps(
               _mm_add_ps(
                 _mm_add_ps(_mm_mul_ps(v119, v122), (__m128)0i64),
                 _mm_mul_ps(*(__m128 *)(v4 + 784 + v98), v128)),
               v131);
      v134 = _mm_mul_ps(*(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x320 + v103), v129);
      v135 = _mm_add_ps(
               *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x20),
               _mm_mul_ps(_mm_add_ps(v133, _mm_mul_ps(*(__m128 *)(v4 + 816 + v98), v130)), v127));
      v136 = *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x30);
      *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x20) = v135;
      v137 = _mm_shuffle_ps(v136, v136, 0);
      v138 = _mm_shuffle_ps(v136, v136, 170);
      v139 = _mm_mul_ps(*(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x310 + v103), v128);
      v140 = _mm_shuffle_ps(v136, v136, 85);
      *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x20) = _mm_add_ps(
                                                                                *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64)
                                                                                          + 0x20),
                                                                                _mm_mul_ps(
                                                                                  _mm_add_ps(
                                                                                    _mm_add_ps(
                                                                                      _mm_add_ps(
                                                                                        _mm_add_ps(v132, (__m128)0i64),
                                                                                        v139),
                                                                                      v134),
                                                                                    _mm_mul_ps(
                                                                                      *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64)
                                                                                                + 0x330
                                                                                                + v103),
                                                                                      v130)),
                                                                                  *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64)
                                                                                            + 0xF0)));
      v141 = *(__m128 *)(v4 + 768 + v95);
      v142 = _mm_mul_ps(_mm_shuffle_ps(v136, v136, 255), (__m128)0i64);
      *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x30) = v142;
      *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x50) = _mm_add_ps(
                                                                                _mm_mul_ps(
                                                                                  _mm_add_ps(
                                                                                    _mm_add_ps(
                                                                                      _mm_add_ps(
                                                                                        _mm_add_ps(
                                                                                          _mm_mul_ps(v141, v137),
                                                                                          (__m128)0i64),
                                                                                        _mm_mul_ps(v107, v140)),
                                                                                      _mm_mul_ps(v101, v138)),
                                                                                    v142),
                                                                                  v125),
                                                                                (__m128)0i64);
      v143 = _mm_add_ps(
               _mm_add_ps(
                 _mm_add_ps(_mm_add_ps(_mm_mul_ps(v117, v137), (__m128)0i64), _mm_mul_ps(v113, v140)),
                 _mm_mul_ps(v110, v138)),
               v142);
      v144 = _mm_mul_ps(*(__m128 *)(v4 + 800 + v98), v138);
      v145 = _mm_add_ps(_mm_mul_ps(*(__m128 *)(v4 + 768 + v98), v137), (__m128)0i64);
      v146 = *(__m128 *)(v4 + 784 + v98);
      v147 = _mm_add_ps(*(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x50), _mm_mul_ps(v143, v126));
      v148 = _mm_mul_ps(*(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x300 + v103), v137);
      *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x50) = v147;
      v149 = _mm_add_ps(
               _mm_add_ps(_mm_add_ps(v145, _mm_mul_ps(v146, v140)), v144),
               *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x30));
      v150 = _mm_mul_ps(*(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x320 + v103), v138);
      v151 = *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x230);
      *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x50) = _mm_add_ps(
                                                                                *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64)
                                                                                          + 0x50),
                                                                                _mm_mul_ps(v149, v127));
      v152 = _mm_mul_ps(*(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x310 + v103), v140);
      v153 = *(__m128 *)(v4 + 768 + v95);
      v154 = _mm_add_ps(
               _mm_add_ps(_mm_add_ps(_mm_add_ps(v148, (__m128)0i64), v152), v150),
               *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x30));
      v155 = _mm_shuffle_ps(v151, v151, 85);
      v156 = _mm_add_ps(
               *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x50),
               _mm_mul_ps(v154, *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0xF0)));
      v157 = _mm_shuffle_ps(v151, v151, 170);
      *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x50) = v156;
      v158 = _mm_shuffle_ps(v151, v151, 0);
      v159 = _mm_mul_ps(_mm_shuffle_ps(v151, v151, 255), (__m128)0i64);
      v160 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v153, v158), (__m128)0i64), _mm_mul_ps(v107, v155));
      *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x30) = v160;
      v7 = *(_BYTE *)(v5 + 408) == 0;
      v161 = _mm_add_ps(
               _mm_add_ps(_mm_mul_ps(_mm_add_ps(_mm_add_ps(v160, _mm_mul_ps(v101, v157)), v159), v125), (__m128)0i64),
               _mm_mul_ps(
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_add_ps(_mm_mul_ps(v117, v158), (__m128)0i64), _mm_mul_ps(v113, v155)),
                     _mm_mul_ps(v110, v157)),
                   v159),
                 v126));
      v9 = 0i64;
      v162 = _mm_add_ps(
               _mm_add_ps(
                 v161,
                 _mm_mul_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_mul_ps(*(__m128 *)(v4 + 768 + v98), v158), (__m128)0i64),
                         _mm_mul_ps(v146, v155)),
                       _mm_mul_ps(*(__m128 *)(v4 + 800 + v98), v157)),
                     v159),
                   v127)),
               _mm_mul_ps(
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(*(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x300 + v103), v158),
                         (__m128)0i64),
                       _mm_mul_ps(*(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x310 + v103), v155)),
                     _mm_mul_ps(*(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x320 + v103), v157)),
                   v159),
                 *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0xF0)));
      *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x30) = v162;
      if ( v7 )
      {
        v163 = *(float *)(v5 + 68);
        v164 = *(float *)(v5 + 72);
        v165 = *(__int16 *)((char *)v85 + v87 - 4);
        v166 = *(float *)(v5 + 88);
        v167 = *(float *)(v5 + 76);
        v168 = *(float *)(v5 + 92);
        v169 = (float)*(v85 - 1) * 0.00024414062;
        v170 = (float)*v85 * 0.00024414062;
        v171 = (float)*(v85 - 2) * 0.00024414062;
        v172 = *(float *)(v5 + 56) * v171;
        v173 = *(float *)(v5 + 60) * v171;
        v174 = *(float *)(v5 + 84) * v170;
        v175 = (float)(*(float *)(v5 + 52) * v171) + (float)(v163 * v169);
        *(float *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x70) = (float)((float)((float)(*(float *)(v5 + 48) * v171)
                                                                                             + (float)(*(float *)(v5 + 64) * v169))
                                                                                     + (float)(*(float *)(v5 + 80) * v170))
                                                                             + *(float *)(v5 + 96);
        v176 = *(float *)(v5 + 52);
        v177 = v172 + (float)(v164 * v169);
        v178 = v167 * v169;
        v179 = *(float *)(v5 + 48);
        v180 = (float)(v177 + (float)(v166 * v170)) + *(float *)(v5 + 104);
        v181 = v173 + v178;
        *(float *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x74) = (float)(v175 + v174)
                                                                             + *(float *)(v5 + 100);
        v182 = _mm_cvtsi32_si128(v165);
        v183 = *(__int16 *)((char *)v85 + v87 - 2);
        v184 = *(float *)(v5 + 80);
        *(float *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x78) = v180;
        v185 = _mm_cvtsi32_si128(v183);
        v186 = *(__int16 *)((char *)v85 + v87);
        *(float *)v182.m128i_i32 = _mm_cvtepi32_ps(v182).m128_f32[0] * 0.00024414062;
        *(float *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x7C) = (float)(v181 + (float)(v168 * v170))
                                                                             + *(float *)(v5 + 108);
        *(float *)v185.m128i_i32 = _mm_cvtepi32_ps(v185).m128_f32[0] * 0.00024414062;
        v187 = (float)v186 * 0.00024414062;
        v188 = (float)((float)((float)(v179 * *(float *)v182.m128i_i32)
                             + (float)(*(float *)(v5 + 64) * *(float *)v185.m128i_i32))
                     + (float)(v184 * v187))
             + *(float *)(v5 + 96);
        v189 = *(float *)(v5 + 84);
        v190 = *(float *)(v5 + 56);
        v191 = *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x20);
        v192 = v167 * *(float *)v185.m128i_i32;
        *(float *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x80) = v188;
        v193 = _mm_sub_ps(v191, *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x70));
        v194 = v164 * *(float *)v185.m128i_i32;
        v195 = v168 * v187;
        v196 = v166 * v187;
        v197 = (float)((float)(v176 * *(float *)v182.m128i_i32) + (float)(v163 * *(float *)v185.m128i_i32))
             + (float)(v189 * v187);
        v198 = *(float *)(v5 + 60) * *(float *)v182.m128i_i32;
        v199 = _mm_shuffle_ps(v193, v193, 170);
        v200 = _mm_shuffle_ps(v193, v193, 0);
        v201 = (float)((float)((float)(v190 * *(float *)v182.m128i_i32) + v194) + v196) + *(float *)(v5 + 104);
        v202 = v197 + *(float *)(v5 + 100);
        v203 = _mm_shuffle_ps(v193, v193, 85);
        *(float *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x88) = v201;
        *(float *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x84) = v202;
        v204 = (float)(v198 + v192) + v195;
        v67 = FLOAT_4096_0;
        v9 = 0i64;
        *(float *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x8C) = v204 + *(float *)(v5 + 108);
        v205 = *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x80);
        v206 = _mm_min_ps(
                 _mm_add_ps(
                   _mm_mul_ps(
                     _mm_rcp_ps(
                       _mm_rsqrt_ps(
                         _mm_add_ps(
                           _mm_add_ps(_mm_add_ps(_mm_mul_ps(v200, v200), (__m128)0i64), _mm_mul_ps(v203, v203)),
                           _mm_mul_ps(v199, v199)))),
                     _mm_sub_ps(
                       (__m128)_xmm,
                       _mm_add_ps(
                         _mm_mul_ps(
                           *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x100),
                           *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x100)),
                         (__m128)0i64))),
                   *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x100)),
                 *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0xA0));
        v207 = _mm_add_ps(_mm_mul_ps(v193, v206), *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x70));
        *(_WORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 4) = (int)(float)(v207.m128_f32[0] * 4096.0);
        v208 = _mm_mul_ps(v205, *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x270));
        *(_WORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 6) = (int)(float)(_mm_shuffle_ps(v207, v207, 85).m128_f32[0]
                                                                                       * 4096.0);
        *(_DWORD *)((char *)v85 + v87 - 4) = *(_DWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 4);
        *(__int16 *)((char *)v85 + v87) = (int)(float)(_mm_shuffle_ps(v207, v207, 170).m128_f32[0] * 4096.0);
        v68 = *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0xA0);
        v209 = _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(v208, *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x90)),
                   _mm_mul_ps(
                     _mm_sub_ps(v207, v205),
                     *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0xB0))),
                 _mm_add_ps(v207, v207));
        v210 = _mm_add_ps(v209, _mm_mul_ps(_mm_sub_ps(v205, v209), v206));
        v211 = *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x50);
        v212 = _mm_sub_ps(_mm_add_ps(_mm_mul_ps(_mm_sub_ps(v207, v210), v206), v210), v191);
        v213 = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_min_ps(
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_max_ps(
                           _mm_add_ps(
                             _mm_add_ps(
                               _mm_add_ps(
                                 _mm_mul_ps(_mm_shuffle_ps(v212, v212, 0), _mm_shuffle_ps(v211, v211, 0)),
                                 (__m128)0i64),
                               _mm_mul_ps(_mm_shuffle_ps(v212, v212, 85), _mm_shuffle_ps(v211, v211, 85))),
                             _mm_mul_ps(_mm_shuffle_ps(v212, v212, 170), _mm_shuffle_ps(v211, v211, 170))),
                           (__m128)0i64),
                         (__m128)_xmm),
                       (__m128)_xmm),
                     v68),
                   v212),
                 v191);
        *v84 = _mm_shuffle_ps(v213, _mm_shuffle_ps(v213, v206, 250), 148);
      }
      else
      {
        v214 = *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x20);
        v67 = FLOAT_4096_0;
        v68 = *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0xA0);
        v211 = *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x50);
        *(_WORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x40) = (int)(float)(v214.m128_f32[0] * 4096.0);
        *(_WORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x42) = (int)(float)(_mm_shuffle_ps(
                                                                                              v214,
                                                                                              v214,
                                                                                              85).m128_f32[0]
                                                                                          * 4096.0);
        *(_DWORD *)((char *)v85 + v87 - 4) = *(_DWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x40);
        v215 = _mm_shuffle_ps(v214, *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x100), 250);
        *(__int16 *)((char *)v85 + v87) = (int)(float)(_mm_shuffle_ps(v214, v214, 170).m128_f32[0] * 4096.0);
        *v84 = _mm_shuffle_ps(v214, v215, 148);
      }
      v11 = *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0xE0);
      v77 = *(_DWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x10);
      *(_QWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x18) += 2i64;
      v17 = *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x260);
      v19 = *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x220);
      si128 = _mm_load_si128((const __m128i *)(v4 + 352));
      v74 = *(_DWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x1C0);
      v84 += 2;
      v85 += 3;
      v216 = _mm_cvtps_epi32(_mm_add_ps(_mm_mul_ps(v211, v11), v11));
      v15 = *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x240);
      v86 = *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x110);
      v83 = *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0xC0);
      v217 = _mm_cvtps_epi32(_mm_cvtepi32_ps(v216));
      v218 = _mm_packs_epi32(v217, v217);
      v219 = _mm_cmplt_ps(*(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x120), v9);
      v84[-1].m128_i32[0] = _mm_packus_epi16(v218, v218).m128i_u32[0];
      v220 = _mm_cvtps_epi32(
               _mm_add_ps(
                 _mm_mul_ps(
                   _mm_shuffle_ps(
                     v162,
                     _mm_shuffle_ps(
                       v162,
                       _mm_or_ps(
                         _mm_andnot_ps(v68, v219),
                         *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x150)),
                       250),
                     148),
                   v11),
                 v11));
      v20 = *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x140);
      v221 = _mm_cvtps_epi32(_mm_cvtepi32_ps(v220));
      v222 = _mm_packs_epi32(v221, v221);
      v84[-1].m128_i32[1] = _mm_packus_epi16(v222, v222).m128i_u32[0];
    }
    while ( v77 < v12 );
    v8 = *(_DWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0xC);
    v14 = *(_QWORD *)(v5 + 400);
    v70 = *(_DWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x210);
    v69 = 0;
  }
  if ( *(float *)v5 > 0.0 )
  {
    v223 = *(_DWORD *)(v5 + 16);
    v224 = *(__m128 **)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0xD0);
    v225 = 5i64;
    do
    {
      Render::ApplySpringConstraints(
        v224,
        v223,
        (__m128 *)(v4 + 656),
        (__m128 *)(v4 + 672),
        (__m128 *)(v4 + 704),
        (__m128 *)(v4 + 640),
        (__m128 *)(v4 + 688),
        (__m128 *)(v4 + 368),
        (__m128 *)(v4 + 304),
        worker_id,
        (Render::VerletVert *)(v4 + 17152));
      --v225;
    }
    while ( v225 );
    v12 = *(_DWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x60);
    v8 = *(_DWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0xC);
    v70 = *(_DWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x210);
  }
  if ( v12 )
  {
    v226 = (__m128 *)(v4 + 17152);
    v227 = v12;
    do
    {
      v228 = *v226;
      v14 += 6i64;
      v226 += 2;
      v229 = (int)(float)(v226[-2].m128_f32[2] * v67);
      *(_WORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 4) = (int)(float)(v228.m128_f32[0] * v67);
      *(_WORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 6) = (int)(float)(_mm_shuffle_ps(v228, v228, 85).m128_f32[0]
                                                                                     * v67);
      *(_DWORD *)(v14 - 6) = *(_DWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 4);
      *(_WORD *)(v14 - 2) = v229;
      --v227;
    }
    while ( v227 );
  }
  v230 = param0[1];
  v231 = (__m128 *)*param0;
  v232 = param0[2];
  v233 = 128;
  if ( v8 < 0x80 )
    v233 = v8;
  v234 = 8 * v233;
  v235 = 24 * v233;
  *(_QWORD *)(*(_QWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x200 + 8i64 * v70) + 8i64) = v230;
  *(_QWORD *)(*(_QWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64)
                        + 0x1B0
                        + 8i64 * *(int *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x1C0))
            + 8i64) = v232;
  if ( v8 )
  {
    v236 = 128;
    if ( v8 < 0x80 )
      v236 = v8;
    do
    {
      v237 = *(int *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x210);
      v8 -= v236;
      v238 = v236;
      v239 = *(_QWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x200 + 8 * v237);
      v240 = v231;
      v241 = 24 * v236;
      v236 = 128;
      *(_DWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0xC) = v8;
      v230 += v235;
      *(_QWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x20) = (char *)v231 + v241;
      v242 = *(_OWORD **)(v239 + 8);
      v232 += v234;
      v243 = *(_QWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64)
                       + 0x1B0
                       + 8i64 * *(int *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x1C0));
      *(_QWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0xD0) = v230;
      v244 = *(__m128 **)(v243 + 8);
      if ( v8 < 0x80 )
        v236 = v8;
      *(_QWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x50) = v232;
      *(_DWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x10) = v236;
      v235 = 24 * v236;
      *(_DWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 4) = 8 * v236;
      *(_DWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x40) = 24 * v236;
      if ( v236 )
      {
        v245 = *(_DWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x1C0) - 1;
        *(_DWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x210) = ((_BYTE)v237 - 1) & 1;
        *(_DWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x1C0) = v245 & 1;
        *(_QWORD *)(*(_QWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64)
                              + 0x200
                              + 8i64 * (((_BYTE)v237 - 1) & 1))
                  + 8i64) = v230;
        *(_QWORD *)(*(_QWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64)
                              + 0x1B0
                              + 8i64 * *(int *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x1C0))
                  + 8i64) = v232;
      }
      if ( (_DWORD)v238 )
      {
        v246 = *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x270);
        v247 = &v240[1].m128_i8[4];
        v248 = v240 + 1;
        *(_QWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x18) = (char *)v240 + 20;
        *(_QWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x30) = v238;
        v249 = _mm_and_ps(v246, v68);
        *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x250) = v249;
        do
        {
          v250 = *(unsigned __int16 *)(*(_QWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x2D0)
                                     + 2i64 * v69);
          if ( (unsigned int)v250 < v12 )
          {
            v242 = (_OWORD *)((char *)v242 + 24);
            v244 = (__m128 *)((char *)v244 + 8);
            v317 = *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x4310 + 32 * v250);
            v318 = _mm_mul_ps(
                     _mm_add_ps(
                       _mm_cvtepi32_ps((__m128i)_mm_and_ps(
                                                  (__m128)_mm_sub_epi32(
                                                            (__m128i)_mm_shuffle_ps(v317, v317, 85),
                                                            *(__m128i *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64)
                                                                       + 0x160)),
                                                  *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x260))),
                       *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x220)),
                     *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x140));
            v319 = _mm_add_ps(
                     _mm_cvtepi32_ps((__m128i)_mm_and_ps(
                                                (__m128)_mm_sub_epi32(
                                                          (__m128i)_mm_shuffle_ps(v317, v317, 0),
                                                          *(__m128i *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64)
                                                                     + 0x160)),
                                                *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x260))),
                     *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x220));
            *v240 = _mm_shuffle_ps(
                      *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x4300 + 32 * v250),
                      _mm_shuffle_ps(
                        *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x4300 + 32 * v250),
                        v9,
                        250),
                      148);
            v320 = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_sub_ps(_mm_add_ps(v318, v9), v11),
                       *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x240)),
                     v9);
            v315 = _mm_cvtps_epi32(
                     _mm_cvtepi32_ps(
                       _mm_cvtps_epi32(
                         _mm_add_ps(
                           _mm_mul_ps(
                             _mm_add_ps(
                               _mm_mul_ps(
                                 _mm_sub_ps(
                                   _mm_add_ps(
                                     _mm_mul_ps(
                                       v319,
                                       *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x140)),
                                     v9),
                                   v11),
                                 *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x240)),
                               v9),
                             v11),
                           v11))));
            v316 = _mm_cvtps_epi32(
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_shuffle_ps(
                           v320,
                           _mm_shuffle_ps(
                             v320,
                             _mm_or_ps(_mm_andnot_ps(v68, _mm_cmplt_ps(_mm_shuffle_ps(v320, v320, 255), v9)), v249),
                             250),
                           148),
                         v11),
                       v11));
          }
          else
          {
            v251 = *((__m128 *)v242 + 1);
            v252 = *(__m128 *)v242;
            v253 = _mm_load_si128((const __m128i *)(v4 + 352));
            v254 = *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x260);
            v255 = *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x220);
            v256 = *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x140);
            v242 = (_OWORD *)((char *)v242 + 24);
            v257 = (unsigned __int8)v244->m128_i8[0];
            v258 = (unsigned __int8)v244->m128_i8[1];
            v259 = (unsigned __int8)v244->m128_i8[2];
            v260 = (unsigned __int8)v244->m128_i8[3];
            v261 = *v244;
            v244 = (__m128 *)((char *)v244 + 8);
            v262 = _mm_shuffle_ps(v252, _mm_shuffle_ps(v252, v68, 250), 148);
            v263 = *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x300 + (v257 << 6));
            *(_OWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x290) = *(_OWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64)
                                                                                               + 0x330
                                                                                               + (v257 << 6));
            *(_OWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x2A0) = *(_OWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64)
                                                                                               + 0x330
                                                                                               + (v258 << 6));
            *(_OWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x2C0) = *(_OWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64)
                                                                                               + 0x330
                                                                                               + (v259 << 6));
            v264 = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_sub_ps(
                         _mm_add_ps(
                           _mm_mul_ps(
                             _mm_add_ps(
                               _mm_cvtepi32_ps((__m128i)_mm_and_ps(
                                                          (__m128)_mm_sub_epi32(
                                                                    (__m128i)_mm_shuffle_ps(v251, v251, 85),
                                                                    v253),
                                                          v254)),
                               v255),
                             v256),
                           v9),
                         v11),
                       *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x240)),
                     v9);
            v265 = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_sub_ps(
                         _mm_add_ps(
                           _mm_mul_ps(
                             _mm_add_ps(
                               _mm_cvtepi32_ps((__m128i)_mm_and_ps(
                                                          (__m128)_mm_sub_epi32(
                                                                    (__m128i)_mm_shuffle_ps(v251, v251, 0),
                                                                    v253),
                                                          v254)),
                               v255),
                             v256),
                           v9),
                         v11),
                       *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x240)),
                     v9);
            *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x2B0) = _mm_shuffle_ps(v264, v264, 255);
            v266 = _mm_shuffle_ps(v264, _mm_shuffle_ps(v264, v9, 250), 148);
            *(_OWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0xC0) = *(_OWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64)
                                                                                              + 0x310
                                                                                              + (v257 << 6));
            *(_OWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0xB0) = *(_OWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64)
                                                                                              + 0x320
                                                                                              + (v257 << 6));
            *(_OWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x80) = *(_OWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64)
                                                                                              + 0x300
                                                                                              + (v258 << 6));
            *(_OWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x70) = *(_OWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64)
                                                                                              + 0x310
                                                                                              + (v258 << 6));
            *(_OWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x170) = *(_OWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64)
                                                                                               + 0x320
                                                                                               + (v258 << 6));
            *(_OWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x110) = *(_OWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64)
                                                                                               + 0x300
                                                                                               + (v259 << 6));
            *(_OWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x150) = *(_OWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64)
                                                                                               + 0x310
                                                                                               + (v259 << 6));
            *(_OWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x120) = *(_OWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64)
                                                                                               + 0x320
                                                                                               + (v259 << 6));
            *(_OWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x100) = *(_OWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64)
                                                                                               + 0x300
                                                                                               + (v260 << 6));
            v7 = *(_BYTE *)v4 == 0;
            v267 = *(_OWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x330 + (v260 << 6));
            *(_OWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0xF0) = *(_OWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64)
                                                                                              + 0x310
                                                                                              + (v260 << 6));
            *(_OWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x230) = *(_OWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64)
                                                                                               + 0x320
                                                                                               + (v260 << 6));
            *(_OWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x280) = v267;
            v268 = v9;
            v269 = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_add_ps(
                             _mm_cvtepi32_ps((__m128i)_mm_and_ps(
                                                        (__m128)_mm_sub_epi32(
                                                                  (__m128i)_mm_shuffle_ps(v261, v261, 85),
                                                                  v253),
                                                        v254)),
                             v255),
                           v256),
                         v9),
                       *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x2E0)),
                     v9);
            v270 = _mm_shuffle_ps(v269, v269, 0);
            v271 = _mm_shuffle_ps(v269, v269, 85);
            v272 = _mm_shuffle_ps(v269, v269, 170);
            *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x90) = v270;
            *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x130) = v271;
            *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0xE0) = v272;
            v273 = _mm_shuffle_ps(v269, v269, 255);
            if ( !v7 )
            {
              v274 = 32 * v257;
              v275 = *(_QWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x2D8);
              v276 = 32 * v258;
              v277 = 32 * v260;
              v278 = _mm_cmplt_ps(v265, v9);
              v279 = 32 * v259;
              v280 = _mm_and_ps(
                       _mm_or_ps(
                         _mm_add_ps(
                           _mm_add_ps(
                             _mm_add_ps(
                               _mm_add_ps(_mm_mul_ps(v270, *(__m128 *)(v274 + v275 + 16)), v9),
                               _mm_mul_ps(v271, *(__m128 *)(v276 + v275 + 16))),
                             _mm_mul_ps(v272, *(__m128 *)(v279 + v275 + 16))),
                           _mm_mul_ps(v273, *(__m128 *)(v277 + v275 + 16))),
                         *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x2F0)),
                       v278);
              v281 = _mm_andnot_ps(
                       v278,
                       _mm_add_ps(
                         _mm_add_ps(
                           _mm_add_ps(
                             _mm_add_ps(_mm_mul_ps(v270, *(__m128 *)(v274 + v275)), v9),
                             _mm_mul_ps(v271, *(__m128 *)(v276 + v275))),
                           _mm_mul_ps(v272, *(__m128 *)(v279 + v275))),
                         _mm_mul_ps(v273, *(__m128 *)(v277 + v275))));
              v270 = *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x90);
              v282 = _mm_add_ps(_mm_mul_ps(_mm_or_ps(v280, v281), v265), v9);
              v268 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v282, v282, 0), _mm_shuffle_ps(v68, v68, 0)), v9),
                         _mm_mul_ps(_mm_shuffle_ps(v282, v282, 85), _mm_shuffle_ps(v68, v68, 85))),
                       _mm_mul_ps(_mm_shuffle_ps(v282, v282, 170), _mm_shuffle_ps(v68, v68, 170)));
            }
            v283 = _mm_shuffle_ps(v262, v262, 0);
            v284 = _mm_shuffle_ps(v262, v262, 85);
            v285 = _mm_shuffle_ps(v262, v262, 170);
            v286 = _mm_shuffle_ps(v262, v262, 255);
            v287 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_add_ps(
                           _mm_add_ps(
                             _mm_add_ps(
                               _mm_add_ps(_mm_mul_ps(v263, v283), v9),
                               _mm_mul_ps(*(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0xC0), v284)),
                             _mm_mul_ps(*(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0xB0), v285)),
                           _mm_mul_ps(*(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x290), v286)),
                         v270),
                       v9),
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_add_ps(
                           _mm_add_ps(
                             _mm_add_ps(
                               _mm_mul_ps(*(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x80), v283),
                               v9),
                             _mm_mul_ps(*(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x70), v284)),
                           _mm_mul_ps(*(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x170), v285)),
                         _mm_mul_ps(*(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x2A0), v286)),
                       *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x130)));
            v288 = _mm_mul_ps(*(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x100), v283);
            v289 = _mm_mul_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_add_ps(
                           _mm_add_ps(
                             _mm_mul_ps(*(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x110), v283),
                             v9),
                           _mm_mul_ps(*(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x150), v284)),
                         _mm_mul_ps(*(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x120), v285)),
                       _mm_mul_ps(*(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x2C0), v286)),
                     *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0xE0));
            v290 = _mm_shuffle_ps(v266, v266, 0);
            v291 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(v288, v9),
                       _mm_mul_ps(*(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0xF0), v284)),
                     _mm_mul_ps(*(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x230), v285));
            v292 = _mm_shuffle_ps(v266, v266, 85);
            v293 = _mm_shuffle_ps(v266, v266, 170);
            v294 = _mm_add_ps(
                     _mm_add_ps(v287, v289),
                     _mm_mul_ps(
                       _mm_add_ps(
                         v291,
                         _mm_mul_ps(*(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x280), v286)),
                       v273));
            v295 = _mm_mul_ps(_mm_shuffle_ps(v266, v266, 255), v9);
            v296 = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_add_ps(
                           _mm_add_ps(
                             _mm_add_ps(_mm_mul_ps(v263, v290), v9),
                             _mm_mul_ps(*(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0xC0), v292)),
                           _mm_mul_ps(*(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0xB0), v293)),
                         v295),
                       *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x90)),
                     v9);
            v297 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(*(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x110), v290),
                       v9),
                     _mm_mul_ps(*(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x150), v292));
            v298 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(*(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x80), v290),
                         v9),
                       _mm_mul_ps(*(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x70), v292)),
                     _mm_mul_ps(*(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x170), v293));
            v299 = _mm_mul_ps(*(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0xF0), v292);
            v300 = *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x230);
            v301 = _mm_add_ps(
                     v297,
                     _mm_mul_ps(*(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x120), v293));
            v302 = _mm_mul_ps(v300, v293);
            v68 = *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0xA0);
            v303 = _mm_add_ps(
                     v296,
                     _mm_mul_ps(
                       _mm_add_ps(v298, v295),
                       *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x130)));
            v304 = _mm_mul_ps(*(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x100), v290);
            v305 = *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x70);
            v306 = _mm_add_ps(
                     v303,
                     _mm_mul_ps(
                       _mm_add_ps(v301, v295),
                       *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0xE0)));
            v307 = *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0xC0);
            v308 = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_add_ps(v304, v9), v299), v302), v295);
            v309 = _mm_shuffle_ps(v265, v265, 0);
            v310 = _mm_shuffle_ps(v265, v265, 85);
            *v240 = _mm_shuffle_ps(v294, _mm_shuffle_ps(v294, v268, 250), 148);
            v311 = _mm_max_ps(
                     _mm_add_ps(v306, _mm_mul_ps(v308, v273)),
                     *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x270));
            v312 = _mm_shuffle_ps(v265, v265, 170);
            v313 = _mm_min_ps(v311, v68);
            v314 = _mm_mul_ps(_mm_shuffle_ps(v265, v265, 255), v9);
            v247 = *(char **)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x18);
            v238 = *(_QWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x30);
            v12 = *(_DWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x60);
            v315 = _mm_cvtps_epi32(
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
                                                 _mm_add_ps(_mm_mul_ps(v263, v309), v9),
                                                 _mm_mul_ps(v307, v310)),
                                               _mm_mul_ps(
                                                 *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0xB0),
                                                 v312)),
                                             v314),
                                           *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x90)),
                                         v9),
                                       _mm_mul_ps(
                                         _mm_add_ps(
                                           _mm_add_ps(
                                             _mm_add_ps(
                                               _mm_add_ps(
                                                 _mm_mul_ps(
                                                   *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x80),
                                                   v309),
                                                 v9),
                                               _mm_mul_ps(v305, v310)),
                                             _mm_mul_ps(
                                               *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x170),
                                               v312)),
                                           v314),
                                         *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x130))),
                                     _mm_mul_ps(
                                       _mm_add_ps(
                                         _mm_add_ps(
                                           _mm_add_ps(
                                             _mm_add_ps(
                                               _mm_mul_ps(
                                                 *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x110),
                                                 v309),
                                               v9),
                                             _mm_mul_ps(
                                               *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x150),
                                               v310)),
                                           _mm_mul_ps(
                                             *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x120),
                                             v312)),
                                         v314),
                                       *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0xE0))),
                                   _mm_mul_ps(
                                     _mm_add_ps(
                                       _mm_add_ps(
                                         _mm_add_ps(
                                           _mm_add_ps(
                                             _mm_mul_ps(
                                               *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x100),
                                               v309),
                                             v9),
                                           _mm_mul_ps(
                                             *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0xF0),
                                             v310)),
                                         _mm_mul_ps(v300, v312)),
                                       v314),
                                     v273)),
                                 *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x270)),
                               v68),
                             v11),
                           v11))));
            v316 = _mm_cvtps_epi32(
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_shuffle_ps(
                           v313,
                           _mm_shuffle_ps(
                             v313,
                             _mm_or_ps(
                               _mm_andnot_ps(
                                 v68,
                                 _mm_cmplt_ps(
                                   *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x2B0),
                                   v9)),
                               *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x250)),
                             250),
                           148),
                         v11),
                       v11));
            v249 = *(__m128 *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x250);
          }
          v321 = _mm_packs_epi32(v315, v315);
          v247 += 24;
          v240 = (__m128 *)((char *)v240 + 24);
          v248 = (__m128 *)((char *)v248 + 24);
          ++v69;
          --v238;
          *(_QWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x18) = v247;
          *(_QWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x30) = v238;
          v248[-2].m128_i32[2] = _mm_packus_epi16(v321, v321).m128i_u32[0];
          v322 = _mm_cvtps_epi32(_mm_cvtepi32_ps(v316));
          v323 = _mm_packs_epi32(v322, v322);
          *((_DWORD *)v247 - 6) = _mm_packus_epi16(v323, v323).m128i_u32[0];
        }
        while ( v238 );
        v236 = *(_DWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x10);
        v8 = *(_DWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0xC);
        v235 = *(_DWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x40);
        v230 = *(_QWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0xD0);
        v232 = *(_QWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x50);
      }
      v231 = *(__m128 **)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 0x20);
      v234 = *(_DWORD *)(((unsigned __int64)v324 & 0xFFFFFFFFFFFFFF80ui64) + 4);
    }
    while ( v8 );
  }
}& 0xFFFFFFFFFFFFFF80ui64) + 4);
    }
    while ( v8 );
  }
}

