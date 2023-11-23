// File Line: 22
// RVA: 0x1453D40
__int64 Render::_dynamic_initializer_for__gTaskFunctionDecl_MultiMorphSkinBufferTask__()
{
  UFG::qTaskFunctionDecl::qTaskFunctionDecl(
    &Render::gTaskFunctionDecl_MultiMorphSkinBufferTask,
    &Render::gTaskFunctionDeclData_MultiMorphSkinBufferTask);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gTaskFunctionDecl_MultiMorphSkinBufferTask__);
}

// File Line: 28
// RVA: 0x24250
void __fastcall Render::MultiMorphSkinBufferTask(
        int worker_id,
        UFG::qMemoryStreamer *memory_streamer,
        _QWORD *param0,
        void *param1)
{
  __int64 v4; // rsi
  _OWORD *v5; // rbp
  _OWORD *v6; // r14
  unsigned int v7; // r13d
  unsigned int v8; // r12d
  __int64 v9; // r11
  __int64 v10; // rbx
  unsigned __int8 *v11; // r9
  __m128 *v13; // rdx
  __int64 v14; // r10
  int v15; // r8d
  __int64 v16; // rcx
  __m128 *v17; // rax
  __m128 v18; // xmm5
  __m128 v19; // xmm11
  __m128 v20; // xmm12
  __m128 v21; // xmm13
  __m128 v22; // xmm4
  __m128 v23; // xmm3
  __m128 v24; // xmm8
  __m128 v25; // xmm5
  __m128 v26; // xmm1
  __m128 v27; // xmm6
  __m128 v28; // xmm7
  __m128 v29; // xmm0
  __m128 v30; // xmm8
  __m128 v31; // xmm6
  __m128 v32; // xmm10
  __m128 v33; // xmm5
  __m128 v34; // xmm4
  __m128 v35; // xmm10
  __m128 v36; // xmm5
  __m128 v37; // xmm4
  __m128 v38; // xmm4
  __m128 v39; // xmm5
  __m128 v40; // xmm10
  __m128 v41; // xmm14
  __m128 v42; // xmm6
  __m128 v43; // xmm12
  unsigned int v44; // r15d
  __m128i v45; // xmm11
  __m128 v46; // xmm7
  __m128 v47; // xmm9
  __m128 v48; // xmm10
  __m128 v49; // xmm13
  __m128 v50; // xmm5
  __int64 v51; // r11
  __int64 v52; // rsi
  __m128 v53; // xmm1
  __m128 v54; // xmm8
  __m128 si128; // xmm2
  unsigned __int8 *v56; // rcx
  __m128 *v57; // rdx
  __m128 *v58; // r8
  int v59; // eax
  __m128 *v60; // r9
  int v61; // eax
  __m128 *v62; // r10
  __m128 v63; // xmm8
  __m128 v64; // xmm4
  __m128 v65; // xmm14
  unsigned int v66; // ecx
  __int64 *v67; // r11
  _OWORD *v68; // rax
  __int64 v69; // rbx
  __int64 v70; // rcx
  __m128 v71; // xmm3
  __m128i v72; // xmm2
  __m128 v73; // xmm3
  __m128 v74; // xmm1
  __m128 v75; // xmm13
  __m128 v76; // xmm6
  __m128 v77; // xmm4
  __m128 v78; // xmm5
  __m128 v79; // xmm8
  __m128 v80; // xmm12
  __m128 v81; // xmm9
  __m128 v82; // xmm10
  __m128 v83; // xmm11
  __m128 v84; // xmm12
  __m128 v85; // xmm7
  __m128 v86; // xmm6
  __m128 v87; // xmm4
  __m128 v88; // xmm5
  __m128 v89; // xmm8
  __m128 v90; // xmm2
  __m128 v91; // xmm3
  __m128 v92; // xmm0
  __m128 v93; // xmm4
  __m128 v94; // xmm6
  __m128 v95; // xmm8
  __m128 v96; // xmm3
  __m128 v97; // xmm0
  __m128 v98; // xmm1
  __m128 v99; // xmm14
  __m128 v100; // xmm8
  __m128 v101; // xmm3
  __m128 v102; // xmm4
  __m128 v103; // xmm3
  __m128 v104; // xmm4
  __m128 v105; // xmm3
  __m128 v106; // xmm4
  __m128i v107; // xmm2
  __m128i v108; // xmm2
  __m128 v109; // xmm1
  __m128 v110; // xmm1
  __m128i v111; // xmm2
  __m128i v112; // xmm2
  __m128 v113; // [rsp+0h] [rbp-41A8h] BYREF
  __m128 v114; // [rsp+10h] [rbp-4198h]
  __m128 v115; // [rsp+20h] [rbp-4188h]
  __m128 v116; // [rsp+30h] [rbp-4178h]
  __m128 v117; // [rsp+40h] [rbp-4168h]
  __m128 v118; // [rsp+50h] [rbp-4158h]
  __m128 v119; // [rsp+60h] [rbp-4148h]
  __m128 v120; // [rsp+70h] [rbp-4138h]
  __m128 v121; // [rsp+80h] [rbp-4128h]
  __m128 v122; // [rsp+90h] [rbp-4118h]
  __m128 v123; // [rsp+A0h] [rbp-4108h]
  __m128 v124; // [rsp+B0h] [rbp-40F8h]
  __m128 v125; // [rsp+C0h] [rbp-40E8h]
  __m128 v126; // [rsp+D0h] [rbp-40D8h]
  char v127[32]; // [rsp+E0h] [rbp-40C8h] BYREF
  char v128; // [rsp+100h] [rbp-40A8h] BYREF
  __int64 v129; // [rsp+41C0h] [rbp+18h]

  v4 = *param0;
  v5 = (_OWORD *)param0[1];
  v6 = (_OWORD *)param0[2];
  v7 = *((_DWORD *)param0 + 16);
  v8 = *((_DWORD *)param0 + 43);
  v9 = param0[4];
  v10 = param0[12];
  v11 = (unsigned __int8 *)param0[13];
  if ( *((_WORD *)param0 + 20) )
  {
    v13 = (__m128 *)&v128;
    v14 = *((unsigned __int16 *)param0 + 20);
    do
    {
      v15 = *v11;
      if ( v15 == 255 )
      {
        v13[-2] = gVmxIdentity0_3;
        v13[-1] = gVmxIdentity1_3;
        *v13 = gVmxIdentity2_3;
        v13[1] = gVmxIdentity3_3;
      }
      else
      {
        v16 = (unsigned int)(48 * v15);
        v17 = (__m128 *)(v10 + (unsigned int)(v15 << 6));
        v18 = *(__m128 *)(v16 + v9 + 16);
        v19 = v17[1];
        v20 = v17[2];
        v21 = v17[3];
        v22 = _mm_shuffle_ps(v18, v18, 255);
        v23 = _mm_add_ps(v18, v18);
        v24 = _mm_shuffle_ps(v18, v18, 201);
        v25 = _mm_shuffle_ps(v18, v18, 210);
        v26 = _mm_shuffle_ps(v23, v23, 201);
        v27 = _mm_sub_ps(gVmxOne_3, _mm_mul_ps(v26, v24));
        v28 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v26, v22), (__m128)0i64), _mm_mul_ps(v25, v23));
        v29 = _mm_shuffle_ps(v23, v23, 210);
        v30 = _mm_sub_ps(_mm_add_ps(_mm_mul_ps(v24, v23), (__m128)0i64), _mm_mul_ps(v29, v22));
        v31 = _mm_sub_ps(v27, _mm_mul_ps(v29, v25));
        v32 = _mm_shuffle_ps(_mm_shuffle_ps(v28, v30, 80), v30, 233);
        v33 = _mm_shuffle_ps(_mm_shuffle_ps(v30, v31, 80), v31, 233);
        v34 = _mm_shuffle_ps(_mm_shuffle_ps(v31, v28, 80), v28, 233);
        v35 = _mm_shuffle_ps(v32, _mm_shuffle_ps(v31, v32, 250), 148);
        v36 = _mm_shuffle_ps(v33, _mm_shuffle_ps(v28, v33, 250), 148);
        v37 = _mm_shuffle_ps(v34, _mm_shuffle_ps(v30, v34, 250), 148);
        v38 = _mm_shuffle_ps(v37, _mm_shuffle_ps(v37, (__m128)0i64, 250), 148);
        v39 = _mm_shuffle_ps(v36, _mm_shuffle_ps(v36, (__m128)0i64, 250), 148);
        v40 = _mm_shuffle_ps(v35, _mm_shuffle_ps(v35, (__m128)0i64, 250), 148);
        v41 = _mm_shuffle_ps(*(__m128 *)(v16 + v9), _mm_shuffle_ps(*(__m128 *)(v16 + v9), gVmxOne_3, 250), 148);
        v13[-2] = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(*v17, *v17, 0), v38), (__m128)0i64),
                        _mm_mul_ps(_mm_shuffle_ps(*v17, *v17, 85), v39)),
                      _mm_mul_ps(_mm_shuffle_ps(*v17, *v17, 170), v40)),
                    _mm_mul_ps(_mm_shuffle_ps(*v17, *v17, 255), v41));
        v13[-1] = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v19, v19, 0), v38), (__m128)0i64),
                        _mm_mul_ps(_mm_shuffle_ps(v19, v19, 85), v39)),
                      _mm_mul_ps(_mm_shuffle_ps(v19, v19, 170), v40)),
                    _mm_mul_ps(_mm_shuffle_ps(v19, v19, 255), v41));
        *v13 = _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v20, v20, 0), v38), (__m128)0i64),
                     _mm_mul_ps(_mm_shuffle_ps(v20, v20, 85), v39)),
                   _mm_mul_ps(_mm_shuffle_ps(v20, v20, 170), v40)),
                 _mm_mul_ps(_mm_shuffle_ps(v20, v20, 255), v41));
        v13[1] = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v21, v21, 0), v38), (__m128)0i64),
                       _mm_mul_ps(_mm_shuffle_ps(v21, v21, 85), v39)),
                     _mm_mul_ps(_mm_shuffle_ps(v21, v21, 170), v40)),
                   _mm_mul_ps(_mm_shuffle_ps(v21, v21, 255), v41));
      }
      v13 += 4;
      ++v11;
      --v14;
    }
    while ( v14 );
  }
  v42 = gVmx127_1;
  v43 = gVmxOneOver127_1;
  v44 = 0;
  v45 = gVmxUnpackBias_1;
  v46 = (__m128)gVmxUnpackMask_1;
  v47 = gVmxUnpackUnbias_1;
  v48 = gVmxUnpackShift_1;
  v49 = gVmxOneOver16384;
  if ( v7 )
  {
    v50 = gVmxOne_3;
    v51 = v4 + 20;
    v52 = 0i64;
    v129 = v51;
    v126 = _mm_and_ps(gVmxMinusOne_1, gVmxOne_3);
    do
    {
      v53 = *((__m128 *)v5 + 1);
      v54 = *(__m128 *)v5;
      si128 = *(__m128 *)v6;
      v56 = (unsigned __int8 *)v6;
      v113 = *(__m128 *)v6;
      v5 = (_OWORD *)((char *)v5 + 24);
      v6 = (_OWORD *)((char *)v6 + 8);
      v57 = (__m128 *)&v127[64 * (unsigned __int8)v113.m128_i8[0]];
      v58 = (__m128 *)&v127[64 * v56[1]];
      v59 = v56[2];
      v124 = *v57;
      v116 = v57[1];
      v60 = (__m128 *)&v127[64 * v59];
      v61 = v56[3] << 6;
      v122 = v57[2];
      v62 = (__m128 *)&v127[v61];
      v118 = *v58;
      v125 = v58[1];
      v120 = v58[2];
      v114 = *v60;
      v115 = v60[1];
      v117 = v60[2];
      v119 = *v62;
      v121 = v62[1];
      v123 = v62[2];
      v63 = _mm_shuffle_ps(v54, _mm_shuffle_ps(v54, v50, 250), 148);
      v64 = _mm_add_ps(
              _mm_mul_ps(
                _mm_sub_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_cvtepi32_ps((__m128i)_mm_and_ps(
                                                   (__m128)_mm_sub_epi32((__m128i)_mm_shuffle_ps(v53, v53, 85), v45),
                                                   v46)),
                        v47),
                      v48),
                    (__m128)0i64),
                  v42),
                v43),
              (__m128)0i64);
      v65 = _mm_add_ps(
              _mm_mul_ps(
                _mm_sub_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_cvtepi32_ps((__m128i)_mm_and_ps(
                                                   (__m128)_mm_sub_epi32((__m128i)_mm_shuffle_ps(v53, v53, 0), v45),
                                                   v46)),
                        v47),
                      v48),
                    (__m128)0i64),
                  v42),
                v43),
              (__m128)0i64);
      if ( v44 < v8 )
      {
        v66 = *((_DWORD *)param0 + 42);
        if ( v66 )
        {
          v67 = (__int64 *)param0[19];
          v68 = (_OWORD *)param0[20];
          v69 = v66;
          do
          {
            v70 = *v67;
            v71 = *(__m128 *)v68;
            v68 = (_OWORD *)((char *)v68 + 4);
            ++v67;
            v72 = *(__m128i *)(v52 + v70);
            v73 = _mm_shuffle_ps(v71, v71, 0);
            v74 = _mm_add_ps(
                    _mm_mul_ps(_mm_cvtepi32_ps(_mm_srai_epi32(_mm_unpacklo_epi16(v72, v72), 0x10u)), v49),
                    (__m128)0i64);
            v63 = _mm_add_ps(v63, _mm_mul_ps(_mm_shuffle_ps(v74, _mm_shuffle_ps(v74, v50, 250), 148), v73));
            v65 = _mm_add_ps(
                    v65,
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_sub_ps(
                            _mm_add_ps(
                              _mm_mul_ps(
                                _mm_add_ps(
                                  _mm_cvtepi32_ps((__m128i)_mm_and_ps(
                                                             (__m128)_mm_sub_epi32(
                                                                       (__m128i)_mm_shuffle_ps(
                                                                                  (__m128)v72,
                                                                                  (__m128)v72,
                                                                                  170),
                                                                       v45),
                                                             v46)),
                                  v47),
                                v48),
                              (__m128)0i64),
                            v42),
                          v43),
                        (__m128)0i64),
                      v73));
            --v69;
          }
          while ( v69 );
          si128 = (__m128)_mm_load_si128((const __m128i *)&v113);
          v51 = v129;
        }
      }
      v75 = _mm_shuffle_ps(v64, v64, 255);
      v76 = _mm_shuffle_ps(v63, v63, 0);
      v113 = _mm_shuffle_ps(v64, _mm_shuffle_ps(v64, (__m128)0i64, 250), 148);
      v77 = _mm_shuffle_ps(v63, v63, 85);
      v78 = _mm_shuffle_ps(v63, v63, 170);
      v79 = _mm_shuffle_ps(v63, v63, 255);
      v80 = _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_cvtepi32_ps((__m128i)_mm_and_ps(
                                                 (__m128)_mm_sub_epi32((__m128i)_mm_shuffle_ps(si128, si128, 85), v45),
                                                 v46)),
                      v47),
                    v48),
                  (__m128)0i64),
                gVmxOneOver255_1),
              (__m128)0i64);
      v81 = _mm_shuffle_ps(v80, v80, 0);
      v82 = _mm_shuffle_ps(v80, v80, 85);
      v83 = _mm_shuffle_ps(v80, v80, 170);
      v84 = _mm_shuffle_ps(v80, v80, 255);
      v85 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v76, v124), (__m128)0i64), _mm_mul_ps(v77, v116)),
                          _mm_mul_ps(v78, v122)),
                        _mm_mul_ps(v79, v57[3])),
                      v81),
                    (__m128)0i64),
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_add_ps(_mm_mul_ps(v76, v118), (__m128)0i64), _mm_mul_ps(v77, v125)),
                        _mm_mul_ps(v78, v120)),
                      _mm_mul_ps(v79, v58[3])),
                    v82)),
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_add_ps(_mm_mul_ps(v76, v114), (__m128)0i64), _mm_mul_ps(v77, v115)),
                      _mm_mul_ps(v78, v117)),
                    _mm_mul_ps(v79, v60[3])),
                  v83)),
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_add_ps(_mm_mul_ps(v76, v119), (__m128)0i64), _mm_mul_ps(v77, v121)),
                    _mm_mul_ps(v78, v123)),
                  _mm_mul_ps(v79, v62[3])),
                v84));
      v86 = _mm_shuffle_ps(v113, v113, 0);
      v87 = _mm_shuffle_ps(v113, v113, 85);
      v88 = _mm_shuffle_ps(v113, v113, 170);
      v113 = _mm_mul_ps(_mm_shuffle_ps(v113, v113, 255), (__m128)0i64);
      v89 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_add_ps(_mm_mul_ps(v86, v124), (__m128)0i64), _mm_mul_ps(v116, v87)),
                      _mm_mul_ps(v122, v88)),
                    v113),
                  v81),
                (__m128)0i64),
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_add_ps(_mm_mul_ps(v86, v118), (__m128)0i64), _mm_mul_ps(v125, v87)),
                    _mm_mul_ps(v120, v88)),
                  v113),
                v82));
      v90 = _mm_shuffle_ps(v65, v65, 170);
      v91 = _mm_add_ps(
              _mm_add_ps(_mm_add_ps(_mm_mul_ps(v86, v114), (__m128)0i64), _mm_mul_ps(v115, v87)),
              _mm_mul_ps(v117, v88));
      v92 = _mm_mul_ps(v121, v87);
      v93 = v116;
      v94 = _mm_add_ps(
              _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(v86, v119), (__m128)0i64), v92), _mm_mul_ps(v123, v88)),
              v113);
      v95 = _mm_add_ps(v89, _mm_mul_ps(_mm_add_ps(v91, v113), v83));
      v96 = v124;
      v97 = _mm_shuffle_ps(v65, v65, 0);
      v98 = _mm_shuffle_ps(v65, v65, 85);
      *(__m128 *)(v51 - 20) = _mm_shuffle_ps(v85, _mm_shuffle_ps(v85, (__m128)0i64, 250), 148);
      v99 = _mm_mul_ps(_mm_shuffle_ps(v65, v65, 255), (__m128)0i64);
      v100 = _mm_add_ps(v95, _mm_mul_ps(v94, v84));
      v101 = _mm_add_ps(
               _mm_mul_ps(
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_add_ps(_mm_mul_ps(v96, v97), (__m128)0i64), _mm_mul_ps(v93, v98)),
                     _mm_mul_ps(v122, v90)),
                   v99),
                 v81),
               (__m128)0i64);
      v42 = gVmx127_1;
      v51 += 24i64;
      ++v44;
      v52 += 12i64;
      v129 = v51;
      v46 = (__m128)gVmxUnpackMask_1;
      v47 = gVmxUnpackUnbias_1;
      v102 = _mm_mul_ps(
               _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(_mm_add_ps(_mm_mul_ps(v118, v97), (__m128)0i64), _mm_mul_ps(v125, v98)),
                   _mm_mul_ps(v120, v90)),
                 v99),
               v82);
      v48 = gVmxUnpackShift_1;
      v103 = _mm_add_ps(v101, v102);
      v50 = gVmxOne_3;
      v104 = _mm_mul_ps(
               _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(_mm_add_ps(_mm_mul_ps(v114, v97), (__m128)0i64), _mm_mul_ps(v115, v98)),
                   _mm_mul_ps(v117, v90)),
                 v99),
               v83);
      v45 = gVmxUnpackBias_1;
      v105 = _mm_add_ps(v103, v104);
      v106 = _mm_mul_ps(
               _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(_mm_add_ps(_mm_mul_ps(v119, v97), (__m128)0i64), _mm_mul_ps(v121, v98)),
                   _mm_mul_ps(v123, v90)),
                 v99),
               v84);
      v43 = gVmxOneOver127_1;
      v107 = _mm_cvtps_epi32(_mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_add_ps(_mm_mul_ps(_mm_add_ps(v105, v106), gVmx127_1), gVmx127_1))));
      v108 = _mm_packs_epi32(v107, v107);
      v109 = _mm_andnot_ps(gVmxOne_3, _mm_cmplt_ps(v75, (__m128)0i64));
      v49 = gVmxOneOver16384;
      v110 = _mm_or_ps(v109, v126);
      *(_DWORD *)(v51 - 28) = _mm_packus_epi16(v108, v108).m128i_u32[0];
      v111 = _mm_cvtps_epi32(
               _mm_cvtepi32_ps(
                 _mm_cvtps_epi32(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v100, _mm_shuffle_ps(v100, v110, 250), 148), gVmx127_1),
                     gVmx127_1))));
      v112 = _mm_packs_epi32(v111, v111);
      *(_DWORD *)(v51 - 24) = _mm_packus_epi16(v112, v112).m128i_u32[0];
    }
    while ( v44 < v7 );
  }
}

