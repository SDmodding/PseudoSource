// File Line: 27
// RVA: 0x14574C0
__int64 dynamic_initializer_for__gTaskFunctionDecl_OceanSkinBufferTask__()
{
  UFG::qTaskFunctionDecl::qTaskFunctionDecl(
    &gTaskFunctionDecl_OceanSkinBufferTask,
    &gTaskFunctionDeclData_OceanSkinBufferTask);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gTaskFunctionDecl_OceanSkinBufferTask__);
}

// File Line: 85
// RVA: 0x79850
void __fastcall OceanSkinBufferTask(
        int worker_id,
        UFG::qMemoryStreamer *memory_streamer,
        _QWORD *param0,
        void *param1,
        void *param2)
{
  unsigned int *v5; // rcx
  __m128 *v6; // r14
  __m128 *v7; // r15
  __int64 v8; // rax
  float v9; // xmm10_4
  float v10; // xmm10_4
  unsigned int v11; // ebp
  float v12; // xmm8_4
  float v13; // xmm6_4
  __m128 v14; // xmm14
  __m128 v15; // xmm3
  __m128 v16; // xmm7
  float v17; // xmm9_4
  unsigned int v18; // edx
  __m128 *v19; // rbx
  __m128 *v20; // rdi
  __int64 v21; // rcx
  __int64 v22; // rsi
  __m128 v23; // xmm12
  __m128 v24; // xmm1
  __m128 v25; // xmm3
  __m128 v26; // xmm1
  float v27; // xmm4_4
  __m128 v28; // xmm1
  __m128 v29; // xmm2
  __m128 v30; // xmm5
  __m128 v31; // xmm1
  float v32; // xmm8_4
  __m128 v33; // xmm11
  float v34; // xmm7_4
  __m128 v35; // xmm1
  float v36; // xmm7_4
  float v37; // xmm6_4
  float v38; // xmm0_4
  float v39; // xmm0_4
  __m128 v40; // xmm12
  __m128 v41; // xmm1
  __m128 v42; // xmm2
  float v43; // xmm9_4
  __m128 v44; // xmm2
  __m128 v45; // xmm12
  __m128 v46; // xmm1
  float v47; // xmm7_4
  __m128 v48; // xmm1
  float v49; // xmm7_4
  float v50; // xmm6_4
  float v51; // xmm0_4
  float v52; // xmm0_4
  float v53; // xmm10_4
  __m128 v54; // xmm12
  __m128 v55; // xmm1
  __m128 v56; // xmm2
  __m128 v57; // xmm2
  __m128 v58; // xmm12
  __m128 v59; // xmm1
  float v60; // xmm7_4
  __m128 v61; // xmm1
  float v62; // xmm7_4
  float v63; // xmm6_4
  float v64; // xmm0_4
  float v65; // xmm0_4
  __m128 v66; // xmm12
  __m128 v67; // xmm1
  __m128 v68; // xmm2
  __m128 v69; // xmm1
  float v70; // xmm7_4
  __m128 v71; // xmm1
  __m128 v72; // xmm2
  float v73; // xmm7_4
  __m128 v74; // xmm12
  float v75; // xmm6_4
  float v76; // xmm0_4
  float v77; // xmm0_4
  __m128 v78; // xmm11
  __m128 v79; // xmm1
  __m128 v80; // xmm2
  __m128 v81; // xmm2
  __m128 v82; // xmm11
  __m128 v83; // xmm1
  float v84; // xmm7_4
  __m128 v85; // xmm1
  float v86; // xmm7_4
  float v87; // xmm6_4
  float v88; // xmm0_4
  float v89; // xmm0_4
  __m128 v90; // xmm11
  __m128 v91; // xmm1
  __m128 v92; // xmm2
  __m128 v93; // xmm2
  __m128 v94; // xmm11
  __m128 v95; // xmm1
  float v96; // xmm7_4
  __m128 v97; // xmm1
  float v98; // xmm7_4
  float v99; // xmm6_4
  float v100; // xmm0_4
  float v101; // xmm0_4
  __m128 v102; // xmm11
  __m128 v103; // xmm1
  __m128 v104; // xmm2
  __m128 v105; // xmm11
  __m128 v106; // xmm2
  __m128 v107; // xmm1
  __m128 v108; // xmm1
  __m128 v109; // xmm4
  __m128 v110; // xmm4
  __m128 v111; // xmm1
  __m128 v112; // xmm2
  __m128 v113; // xmm1
  __m128 v114; // [rsp+20h] [rbp-F8h]
  float v115; // [rsp+30h] [rbp-E8h]
  __m128 v116; // [rsp+40h] [rbp-D8h]
  float v117; // [rsp+50h] [rbp-C8h]
  float v118; // [rsp+130h] [rbp+18h]

  v5 = (unsigned int *)param0[10];
  v6 = (__m128 *)*param0;
  v7 = (__m128 *)param0[1];
  if ( v5 )
  {
    v8 = *((_QWORD *)v5 + 3);
    v9 = (float)(int)v8;
    if ( v8 < 0 )
      v9 = v9 + 1.8446744e19;
    v10 = v9 * 0.001;
    v11 = *((_DWORD *)param0 + 16);
    LODWORD(v12) = _mm_shuffle_ps((__m128)v5[8], (__m128)v5[8], 0).m128_u32[0];
    LODWORD(v13) = _mm_shuffle_ps((__m128)v5[9], (__m128)v5[9], 0).m128_u32[0];
    v118 = v10;
    v117 = v12;
    v115 = v13;
    v14 = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)*v5, (__m128)v5[2]), _mm_unpacklo_ps((__m128)v5[1], (__m128)0i64));
    v15 = _mm_sub_ps(v14, _mm_mul_ps(v14, gWorldUp));
    v16 = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)v5[3], (__m128)v5[5]), _mm_unpacklo_ps((__m128)v5[4], (__m128)0i64));
    v114 = v15;
    v116 = v16;
    if ( v11 )
    {
      v17 = FLOAT_0_25;
      do
      {
        v18 = 512;
        v19 = v6;
        v20 = v7;
        if ( v11 < 0x200 )
          v18 = v11;
        v11 -= v18;
        v21 = 32 * v18;
        v6 = (__m128 *)((char *)v6 + v21);
        v7 = (__m128 *)((char *)v7 + v21);
        v22 = v18;
        do
        {
          v23 = *v20;
          v20 += 2;
          v24 = _mm_sub_ps(v23, v15);
          v25 = _mm_sub_ps(v23, v14);
          v26 = _mm_mul_ps(v24, v24);
          v27 = (float)(_mm_shuffle_ps(v26, v26, 85).m128_f32[0] + _mm_shuffle_ps(v26, v26, 0).m128_f32[0])
              + _mm_shuffle_ps(v26, v26, 170).m128_f32[0];
          v28 = _mm_mul_ps(v25, v25);
          v29 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(v28, v28, 0)),
                  _mm_shuffle_ps(v28, v28, 170));
          v30 = _mm_mul_ps(_mm_mul_ps(_mm_andnot_ps(_mm_cmple_ps(v29, (__m128)0i64), _mm_rsqrt_ps(v29)), v25), v16);
          if ( v27 >= v12
            || (float)((float)(_mm_shuffle_ps(v30, v30, 85).m128_f32[0] + _mm_shuffle_ps(v30, v30, 0).m128_f32[0])
                     + _mm_shuffle_ps(v30, v30, 170).m128_f32[0]) <= v13 )
          {
            *v19 = v23;
            v19[1] = gWorldUp;
          }
          else
          {
            v31 = _mm_mul_ps(v23, gWaveDir1);
            v32 = v10 * 2.0943952;
            v33 = _mm_add_ps(gWaveDir1dxy, v23);
            v34 = (float)(_mm_shuffle_ps(v31, v31, 85).m128_f32[0] + _mm_shuffle_ps(v31, v31, 0).m128_f32[0])
                + _mm_shuffle_ps(v31, v31, 170).m128_f32[0];
            v35 = _mm_mul_ps(v23, gWorldUp);
            v36 = (float)(v34 * 0.44714484) - (float)(v10 * 2.0943952);
            v37 = (float)(_mm_shuffle_ps(v35, v35, 85).m128_f32[0] + _mm_shuffle_ps(v35, v35, 0).m128_f32[0])
                + _mm_shuffle_ps(v35, v35, 170).m128_f32[0];
            v38 = cosf(v36);
            v39 = cosf((float)((float)((float)(v38 * v17) - v37) * v17) + v36);
            v29.m128_f32[0] = v37 - (float)(v39 * v17);
            v40 = _mm_shuffle_ps(v23, _mm_unpackhi_ps(v23, _mm_shuffle_ps(v29, v29, 0)), 180);
            v41 = (__m128)(unsigned int)FLOAT_1_0;
            v41.m128_f32[0] = 1.0 - v39;
            v42 = _mm_sqrt_ps(v41);
            v42.m128_f32[0] = v42.m128_f32[0] * v17;
            v43 = v10 * 2.5132742;
            v44 = _mm_mul_ps(_mm_shuffle_ps(v42, v42, 0), gWaveDir1);
            v45 = _mm_add_ps(v40, v44);
            v46 = _mm_mul_ps(v45, gWaveDir2);
            v47 = (float)(_mm_shuffle_ps(v46, v46, 85).m128_f32[0] + _mm_shuffle_ps(v46, v46, 0).m128_f32[0])
                + _mm_shuffle_ps(v46, v46, 170).m128_f32[0];
            v48 = _mm_mul_ps(v45, gWorldUp);
            v49 = (float)(v47 * 0.64388859) - (float)(v10 * 2.5132742);
            v50 = (float)(_mm_shuffle_ps(v48, v48, 85).m128_f32[0] + _mm_shuffle_ps(v48, v48, 0).m128_f32[0])
                + _mm_shuffle_ps(v48, v48, 170).m128_f32[0];
            v51 = cosf(v49);
            v52 = cosf((float)((float)((float)(v51 * 0.115) - v50) * 0.1) + v49);
            v44.m128_f32[0] = v50 - (float)(v52 * 0.115);
            v53 = v10 * 1.5906799;
            v54 = _mm_shuffle_ps(v45, _mm_unpackhi_ps(v45, _mm_shuffle_ps(v44, v44, 0)), 180);
            v55 = (__m128)(unsigned int)FLOAT_1_0;
            v55.m128_f32[0] = 1.0 - v52;
            v56 = _mm_sqrt_ps(v55);
            v56.m128_f32[0] = v56.m128_f32[0] * 0.115;
            v57 = _mm_mul_ps(_mm_shuffle_ps(v56, v56, 0), gWaveDir2);
            v58 = _mm_add_ps(v54, v57);
            v59 = _mm_mul_ps(v58, gWaveDir3);
            v60 = (float)(_mm_shuffle_ps(v59, v59, 85).m128_f32[0] + _mm_shuffle_ps(v59, v59, 0).m128_f32[0])
                + _mm_shuffle_ps(v59, v59, 170).m128_f32[0];
            v61 = _mm_mul_ps(v58, gWorldUp);
            v62 = (float)(v60 * 0.25792685) - v53;
            v63 = (float)(_mm_shuffle_ps(v61, v61, 85).m128_f32[0] + _mm_shuffle_ps(v61, v61, 0).m128_f32[0])
                + _mm_shuffle_ps(v61, v61, 170).m128_f32[0];
            v64 = cosf(v62);
            v65 = cosf(v62 - (float)((float)((float)(v64 * 0.15000001) - v63) * 0.1));
            v57.m128_f32[0] = v63 - (float)(v65 * 0.15000001);
            v66 = _mm_shuffle_ps(v58, _mm_unpackhi_ps(v58, _mm_shuffle_ps(v57, v57, 0)), 180);
            v67 = (__m128)(unsigned int)FLOAT_1_0;
            v67.m128_f32[0] = 1.0 - v65;
            v68 = _mm_sqrt_ps(v67);
            v69 = _mm_mul_ps(v33, gWaveDir1);
            v68.m128_f32[0] = v68.m128_f32[0] * 0.15000001;
            v70 = (float)(_mm_shuffle_ps(v69, v69, 85).m128_f32[0] + _mm_shuffle_ps(v69, v69, 0).m128_f32[0])
                + _mm_shuffle_ps(v69, v69, 170).m128_f32[0];
            v71 = _mm_mul_ps(v33, gWorldUp);
            v72 = _mm_mul_ps(_mm_shuffle_ps(v68, v68, 0), gWaveDir3);
            v73 = (float)(v70 * 0.44714484) - v32;
            v74 = _mm_add_ps(v66, v72);
            v75 = (float)(_mm_shuffle_ps(v71, v71, 85).m128_f32[0] + _mm_shuffle_ps(v71, v71, 0).m128_f32[0])
                + _mm_shuffle_ps(v71, v71, 170).m128_f32[0];
            v76 = cosf(v73);
            v77 = cosf((float)((float)((float)(v76 * 0.25) - v75) * 0.25) + v73);
            v72.m128_f32[0] = v75 - (float)(v77 * 0.25);
            v78 = _mm_shuffle_ps(v33, _mm_unpackhi_ps(v33, _mm_shuffle_ps(v72, v72, 0)), 180);
            v79 = (__m128)(unsigned int)FLOAT_1_0;
            v79.m128_f32[0] = 1.0 - v77;
            v80 = _mm_sqrt_ps(v79);
            v80.m128_f32[0] = v80.m128_f32[0] * 0.25;
            v81 = _mm_mul_ps(_mm_shuffle_ps(v80, v80, 0), gWaveDir1);
            v82 = _mm_add_ps(_mm_add_ps(v78, v81), gWaveDir2dxy);
            v83 = _mm_mul_ps(gWaveDir2, v82);
            v84 = (float)(_mm_shuffle_ps(v83, v83, 85).m128_f32[0] + _mm_shuffle_ps(v83, v83, 0).m128_f32[0])
                + _mm_shuffle_ps(v83, v83, 170).m128_f32[0];
            v85 = _mm_mul_ps(gWorldUp, v82);
            v86 = (float)(v84 * 0.64388859) - v43;
            v87 = (float)(_mm_shuffle_ps(v85, v85, 85).m128_f32[0] + _mm_shuffle_ps(v85, v85, 0).m128_f32[0])
                + _mm_shuffle_ps(v85, v85, 170).m128_f32[0];
            v88 = cosf(v86);
            v89 = cosf((float)((float)((float)(v88 * 0.115) - v87) * 0.1) + v86);
            v81.m128_f32[0] = v87 - (float)(v89 * 0.115);
            v90 = _mm_shuffle_ps(v82, _mm_unpackhi_ps(v82, _mm_shuffle_ps(v81, v81, 0)), 180);
            v91 = (__m128)(unsigned int)FLOAT_1_0;
            v91.m128_f32[0] = 1.0 - v89;
            v92 = _mm_sqrt_ps(v91);
            v92.m128_f32[0] = v92.m128_f32[0] * 0.115;
            v93 = _mm_mul_ps(_mm_shuffle_ps(v92, v92, 0), gWaveDir2);
            v94 = _mm_add_ps(_mm_add_ps(v90, v93), gWaveDir3dxy);
            v95 = _mm_mul_ps(gWaveDir3, v94);
            v96 = (float)(_mm_shuffle_ps(v95, v95, 85).m128_f32[0] + _mm_shuffle_ps(v95, v95, 0).m128_f32[0])
                + _mm_shuffle_ps(v95, v95, 170).m128_f32[0];
            v97 = _mm_mul_ps(gWorldUp, v94);
            v98 = (float)(v96 * 0.25792685) - v53;
            v99 = (float)(_mm_shuffle_ps(v97, v97, 85).m128_f32[0] + _mm_shuffle_ps(v97, v97, 0).m128_f32[0])
                + _mm_shuffle_ps(v97, v97, 170).m128_f32[0];
            v100 = cosf(v98);
            v101 = cosf(v98 - (float)((float)((float)(v100 * 0.15000001) - v99) * 0.1));
            v16 = v116;
            v10 = v118;
            *v19 = v74;
            v93.m128_f32[0] = v99 - (float)(v101 * 0.15000001);
            v13 = v115;
            v102 = _mm_shuffle_ps(v94, _mm_unpackhi_ps(v94, _mm_shuffle_ps(v93, v93, 0)), 180);
            v103 = (__m128)(unsigned int)FLOAT_1_0;
            v12 = v117;
            v103.m128_f32[0] = 1.0 - v101;
            v104 = _mm_sqrt_ps(v103);
            v104.m128_f32[0] = v104.m128_f32[0] * 0.15000001;
            v17 = FLOAT_0_25;
            v105 = _mm_sub_ps(_mm_add_ps(v102, _mm_mul_ps(_mm_shuffle_ps(v104, v104, 0), gWaveDir3)), v74);
            v106 = _mm_shuffle_ps(v105, v105, 201);
            v107 = _mm_sub_ps(_mm_mul_ps(gWorldUp, v106), _mm_mul_ps(_mm_shuffle_ps(gWorldUp, gWorldUp, 201), v105));
            v108 = _mm_shuffle_ps(v107, v107, 201);
            v109 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v108, v108, 201), v105), _mm_mul_ps(v106, v108));
            v110 = _mm_shuffle_ps(v109, v109, 201);
            v111 = _mm_mul_ps(v110, v110);
            v112 = _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v111, v111, 85), _mm_shuffle_ps(v111, v111, 0)),
                     _mm_shuffle_ps(v111, v111, 170));
            v113 = _mm_rsqrt_ps(v112);
            v19[1] = _mm_mul_ps(
                       _mm_andnot_ps(
                         _mm_cmple_ps(v112, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v113, v112), v113)),
                           _mm_mul_ps(*(__m128 *)_xmm, v113))),
                       v110);
          }
          v15 = v114;
          v19 += 2;
          --v22;
        }
        while ( v22 );
      }
      while ( v11 );
    }
  }
}

