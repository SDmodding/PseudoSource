// File Line: 22
// RVA: 0x1453D40
__int64 Render::_dynamic_initializer_for__gTaskFunctionDecl_MultiMorphSkinBufferTask__()
{
  UFG::qTaskFunctionDecl::qTaskFunctionDecl(
    &Render::gTaskFunctionDecl_MultiMorphSkinBufferTask,
    &Render::gTaskFunctionDeclData_MultiMorphSkinBufferTask);
  return atexit(Render::_dynamic_atexit_destructor_for__gTaskFunctionDecl_MultiMorphSkinBufferTask__);
}

// File Line: 28
// RVA: 0x24250
void __fastcall Render::MultiMorphSkinBufferTask(int worker_id, UFG::qMemoryStreamer *memory_streamer, void *param0, void *param1)
{
  __int64 v4; // rsi
  _OWORD *v5; // rbp
  __m128i *v6; // r14
  unsigned int v7; // er13
  unsigned int v8; // er12
  __int64 v9; // r11
  __int64 v10; // rbx
  unsigned __int8 *v11; // r9
  _DWORD *v12; // rdi
  __m128 *v13; // rdx
  __int64 v14; // r10
  int v15; // er8
  __int64 v16; // rcx
  __m128 *v17; // rax
  __m128 v18; // xmm5
  __m128 v19; // xmm11
  __m128 v20; // xmm12
  __m128 v21; // xmm13
  __m128 v22; // xmm4
  __m128 v23; // xmm3
  __m128 v24; // xmm8
  __m128 v25; // xmm2
  __m128 v26; // xmm5
  __m128 v27; // xmm1
  __m128 v28; // xmm6
  __m128 v29; // xmm7
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
  unsigned int v44; // er15
  __m128i v45; // xmm11
  __m128 v46; // xmm7
  __m128 v47; // xmm9
  __m128 v48; // xmm10
  __m128 v49; // xmm13
  __m128 v50; // xmm5
  signed __int64 v51; // r11
  __int64 v52; // rsi
  __m128 v53; // xmm1
  __m128 v54; // xmm8
  __m128 v55; // xmm2
  unsigned __int8 *v56; // rcx
  int v57; // eax
  char *v58; // rdx
  char *v59; // r8
  int v60; // eax
  char *v61; // r9
  int v62; // eax
  char *v63; // r10
  __m128 v64; // xmm8
  __m128 v65; // xmm4
  __m128 v66; // xmm14
  unsigned int v67; // ecx
  __int64 *v68; // r11
  _OWORD *v69; // rax
  __int64 v70; // rbx
  __int64 v71; // rcx
  __m128 v72; // xmm3
  __m128i v73; // xmm2
  __m128 v74; // xmm3
  __m128 v75; // xmm1
  __m128 v76; // xmm13
  __m128 v77; // xmm6
  __m128 v78; // xmm4
  __m128 v79; // xmm5
  __m128 v80; // xmm8
  __m128 v81; // xmm12
  __m128 v82; // xmm9
  __m128 v83; // xmm10
  __m128 v84; // xmm11
  __m128 v85; // xmm12
  __m128 v86; // xmm7
  __m128 v87; // xmm6
  __m128 v88; // xmm4
  __m128 v89; // xmm5
  __m128 v90; // xmm8
  __m128 v91; // xmm2
  __m128 v92; // xmm3
  __m128 v93; // xmm0
  __m128 v94; // xmm4
  __m128 v95; // xmm6
  __m128 v96; // xmm8
  __m128 v97; // xmm3
  __m128 v98; // xmm0
  __m128 v99; // xmm1
  __m128 v100; // xmm14
  __m128 v101; // xmm8
  __m128 v102; // xmm3
  __m128 v103; // xmm4
  __m128 v104; // xmm3
  __m128 v105; // xmm4
  __m128 v106; // xmm3
  __m128 v107; // xmm4
  __m128i v108; // xmm2
  __m128i v109; // xmm2
  __m128 v110; // xmm1
  __m128 v111; // xmm1
  __m128i v112; // xmm2
  __m128i v113; // xmm2
  __m128 v114; // [rsp+0h] [rbp-41A8h]
  __m128 v115; // [rsp+10h] [rbp-4198h]
  __m128 v116; // [rsp+20h] [rbp-4188h]
  __m128 v117; // [rsp+30h] [rbp-4178h]
  __m128 v118; // [rsp+40h] [rbp-4168h]
  __m128 v119; // [rsp+50h] [rbp-4158h]
  __m128 v120; // [rsp+60h] [rbp-4148h]
  __m128 v121; // [rsp+70h] [rbp-4138h]
  __m128 v122; // [rsp+80h] [rbp-4128h]
  __m128 v123; // [rsp+90h] [rbp-4118h]
  __m128 v124; // [rsp+A0h] [rbp-4108h]
  __m128 v125; // [rsp+B0h] [rbp-40F8h]
  __m128 v126; // [rsp+C0h] [rbp-40E8h]
  __m128 v127; // [rsp+D0h] [rbp-40D8h]
  char v128[32]; // [rsp+E0h] [rbp-40C8h]
  char v129; // [rsp+100h] [rbp-40A8h]
  signed __int64 v130; // [rsp+41C0h] [rbp+18h]

  v4 = *(_QWORD *)param0;
  v5 = (_OWORD *)*((_QWORD *)param0 + 1);
  v6 = (__m128i *)*((_QWORD *)param0 + 2);
  v7 = *((_DWORD *)param0 + 16);
  v8 = *((_DWORD *)param0 + 43);
  v9 = *((_QWORD *)param0 + 4);
  v10 = *((_QWORD *)param0 + 12);
  v11 = (unsigned __int8 *)*((_QWORD *)param0 + 13);
  v12 = param0;
  if ( *((_WORD *)param0 + 20) )
  {
    v13 = (__m128 *)&v129;
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
        v22 = _mm_shuffle_ps(*(__m128 *)(v16 + v9 + 16), v18, 255);
        v23 = _mm_add_ps(v18, v18);
        v24 = _mm_shuffle_ps(*(__m128 *)(v16 + v9 + 16), v18, 201);
        v25 = _mm_shuffle_ps(v23, v23, 210);
        v26 = _mm_shuffle_ps(v18, v18, 210);
        v27 = _mm_shuffle_ps(v23, v23, 201);
        v28 = _mm_sub_ps(gVmxOne_3, _mm_mul_ps(v27, v24));
        v29 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v27, v22), (__m128)0i64), _mm_mul_ps(v26, v23));
        v30 = _mm_sub_ps(_mm_add_ps(_mm_mul_ps(v24, v23), (__m128)0i64), _mm_mul_ps(v25, v22));
        v31 = _mm_sub_ps(v28, _mm_mul_ps(v25, v26));
        v32 = _mm_shuffle_ps(_mm_shuffle_ps(v29, v30, 80), v30, 233);
        v33 = _mm_shuffle_ps(_mm_shuffle_ps(v30, v31, 80), v31, 233);
        v34 = _mm_shuffle_ps(_mm_shuffle_ps(v31, v29, 80), v29, 233);
        v35 = _mm_shuffle_ps(v32, _mm_shuffle_ps(v31, v32, 250), 148);
        v36 = _mm_shuffle_ps(v33, _mm_shuffle_ps(v29, v33, 250), 148);
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
    v130 = v51;
    v127 = _mm_and_ps(gVmxMinusOne_1, gVmxOne_3);
    do
    {
      v53 = *((__m128 *)v5 + 1);
      v54 = *(__m128 *)v5;
      v55 = *(__m128 *)v6;
      v56 = (unsigned __int8 *)v6;
      v57 = LOBYTE(v6->m128i_i64[0]);
      _mm_store_si128((__m128i *)&v114, *v6);
      v5 = (_OWORD *)((char *)v5 + 24);
      v6 = (__m128i *)((char *)v6 + 8);
      v58 = &v128[64 * v57];
      v59 = &v128[64 * v56[1]];
      v60 = v56[2];
      v125 = *(__m128 *)v58;
      v117 = *((__m128 *)v58 + 1);
      v61 = &v128[64 * v60];
      v62 = v56[3] << 6;
      v123 = *((__m128 *)v58 + 2);
      v63 = &v128[v62];
      v119 = *(__m128 *)v59;
      v126 = *((__m128 *)v59 + 1);
      v121 = *((__m128 *)v59 + 2);
      v115 = *(__m128 *)v61;
      v116 = *((__m128 *)v61 + 1);
      v118 = *((__m128 *)v61 + 2);
      v120 = *(__m128 *)v63;
      v122 = *((__m128 *)v63 + 1);
      v124 = *((__m128 *)v63 + 2);
      v64 = _mm_shuffle_ps(v54, _mm_shuffle_ps(v54, v50, 250), 148);
      v65 = _mm_add_ps(
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
      v66 = _mm_add_ps(
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
        v67 = v12[42];
        if ( v67 )
        {
          v68 = (__int64 *)*((_QWORD *)v12 + 19);
          v69 = (_OWORD *)*((_QWORD *)v12 + 20);
          v70 = v67;
          do
          {
            v71 = *v68;
            v72 = *(__m128 *)v69;
            v69 = (_OWORD *)((char *)v69 + 4);
            ++v68;
            v73 = *(__m128i *)(v52 + v71);
            v74 = _mm_shuffle_ps(v72, v72, 0);
            v75 = _mm_add_ps(
                    _mm_mul_ps(_mm_cvtepi32_ps(_mm_srai_epi32(_mm_unpacklo_epi16(v73, v73), 0x10u)), v49),
                    (__m128)0i64);
            v64 = _mm_add_ps(v64, _mm_mul_ps(_mm_shuffle_ps(v75, _mm_shuffle_ps(v75, v50, 250), 148), v74));
            v66 = _mm_add_ps(
                    v66,
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
                                                                                  (__m128)v73,
                                                                                  (__m128)v73,
                                                                                  170),
                                                                       v45),
                                                             v46)),
                                  v47),
                                v48),
                              (__m128)0i64),
                            v42),
                          v43),
                        (__m128)0i64),
                      v74));
            --v70;
          }
          while ( v70 );
          v55 = (__m128)_mm_load_si128((const __m128i *)&v114);
          v51 = v130;
        }
      }
      v76 = _mm_shuffle_ps(v65, v65, 255);
      v77 = _mm_shuffle_ps(v64, v64, 0);
      v114 = _mm_shuffle_ps(v65, _mm_shuffle_ps(v65, (__m128)0i64, 250), 148);
      v78 = _mm_shuffle_ps(v64, v64, 85);
      v79 = _mm_shuffle_ps(v64, v64, 170);
      v80 = _mm_shuffle_ps(v64, v64, 255);
      v81 = _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_cvtepi32_ps((__m128i)_mm_and_ps(
                                                 (__m128)_mm_sub_epi32((__m128i)_mm_shuffle_ps(v55, v55, 85), v45),
                                                 v46)),
                      v47),
                    v48),
                  (__m128)0i64),
                gVmxOneOver255_1),
              (__m128)0i64);
      v82 = _mm_shuffle_ps(v81, v81, 0);
      v83 = _mm_shuffle_ps(v81, v81, 85);
      v84 = _mm_shuffle_ps(v81, v81, 170);
      v85 = _mm_shuffle_ps(v81, v81, 255);
      v86 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v77, v125), (__m128)0i64), _mm_mul_ps(v78, v117)),
                          _mm_mul_ps(v79, v123)),
                        _mm_mul_ps(v80, *((__m128 *)v58 + 3))),
                      v82),
                    (__m128)0i64),
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_add_ps(_mm_mul_ps(v77, v119), (__m128)0i64), _mm_mul_ps(v78, v126)),
                        _mm_mul_ps(v79, v121)),
                      _mm_mul_ps(v80, *((__m128 *)v59 + 3))),
                    v83)),
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_add_ps(_mm_mul_ps(v77, v115), (__m128)0i64), _mm_mul_ps(v78, v116)),
                      _mm_mul_ps(v79, v118)),
                    _mm_mul_ps(v80, *((__m128 *)v61 + 3))),
                  v84)),
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_add_ps(_mm_mul_ps(v77, v120), (__m128)0i64), _mm_mul_ps(v78, v122)),
                    _mm_mul_ps(v79, v124)),
                  _mm_mul_ps(v80, *((__m128 *)v63 + 3))),
                v85));
      v87 = _mm_shuffle_ps(v114, v114, 0);
      v88 = _mm_shuffle_ps(v114, v114, 85);
      v89 = _mm_shuffle_ps(v114, v114, 170);
      v114 = _mm_mul_ps(_mm_shuffle_ps(v114, v114, 255), (__m128)0i64);
      v90 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_add_ps(_mm_mul_ps(v87, v125), (__m128)0i64), _mm_mul_ps(v117, v88)),
                      _mm_mul_ps(v123, v89)),
                    v114),
                  v82),
                (__m128)0i64),
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_add_ps(_mm_mul_ps(v87, v119), (__m128)0i64), _mm_mul_ps(v126, v88)),
                    _mm_mul_ps(v121, v89)),
                  v114),
                v83));
      v91 = _mm_shuffle_ps(v66, v66, 170);
      v92 = _mm_add_ps(
              _mm_add_ps(_mm_add_ps(_mm_mul_ps(v87, v115), (__m128)0i64), _mm_mul_ps(v116, v88)),
              _mm_mul_ps(v118, v89));
      v93 = _mm_mul_ps(v122, v88);
      v94 = v117;
      v95 = _mm_add_ps(
              _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(v87, v120), (__m128)0i64), v93), _mm_mul_ps(v124, v89)),
              v114);
      v96 = _mm_add_ps(v90, _mm_mul_ps(_mm_add_ps(v92, v114), v84));
      v97 = v125;
      v98 = _mm_shuffle_ps(v66, v66, 0);
      v99 = _mm_shuffle_ps(v66, v66, 85);
      *(__m128 *)(v51 - 20) = _mm_shuffle_ps(v86, _mm_shuffle_ps(v86, (__m128)0i64, 250), 148);
      v100 = _mm_mul_ps(_mm_shuffle_ps(v66, v66, 255), (__m128)0i64);
      v101 = _mm_add_ps(v96, _mm_mul_ps(v95, v85));
      v102 = _mm_add_ps(
               _mm_mul_ps(
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_add_ps(_mm_mul_ps(v97, v98), (__m128)0i64), _mm_mul_ps(v94, v99)),
                     _mm_mul_ps(v123, v91)),
                   v100),
                 v82),
               (__m128)0i64);
      v42 = gVmx127_1;
      v51 += 24i64;
      ++v44;
      v52 += 12i64;
      v130 = v51;
      v46 = (__m128)gVmxUnpackMask_1;
      v47 = gVmxUnpackUnbias_1;
      v103 = _mm_mul_ps(
               _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(_mm_add_ps(_mm_mul_ps(v119, v98), (__m128)0i64), _mm_mul_ps(v126, v99)),
                   _mm_mul_ps(v121, v91)),
                 v100),
               v83);
      v48 = gVmxUnpackShift_1;
      v104 = _mm_add_ps(v102, v103);
      v50 = gVmxOne_3;
      v105 = _mm_mul_ps(
               _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(_mm_add_ps(_mm_mul_ps(v115, v98), (__m128)0i64), _mm_mul_ps(v116, v99)),
                   _mm_mul_ps(v118, v91)),
                 v100),
               v84);
      v45 = gVmxUnpackBias_1;
      v106 = _mm_add_ps(v104, v105);
      v107 = _mm_mul_ps(
               _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(_mm_add_ps(_mm_mul_ps(v120, v98), (__m128)0i64), _mm_mul_ps(v122, v99)),
                   _mm_mul_ps(v124, v91)),
                 v100),
               v85);
      v43 = gVmxOneOver127_1;
      v108 = _mm_cvtps_epi32(_mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_add_ps(_mm_mul_ps(_mm_add_ps(v106, v107), gVmx127_1), gVmx127_1))));
      v109 = _mm_packs_epi32(v108, v108);
      v110 = _mm_andnot_ps(gVmxOne_3, _mm_cmpltps(v76, (__m128)0i64));
      v49 = gVmxOneOver16384;
      v111 = _mm_or_ps(v110, v127);
      *(_DWORD *)(v51 - 28) = (unsigned __int128)_mm_packus_epi16(v109, v109);
      v112 = _mm_cvtps_epi32(
               _mm_cvtepi32_ps(
                 _mm_cvtps_epi32(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v101, _mm_shuffle_ps(v101, v111, 250), 148), gVmx127_1),
                     gVmx127_1))));
      v113 = _mm_packs_epi32(v112, v112);
      *(_DWORD *)(v51 - 24) = (unsigned __int128)_mm_packus_epi16(v113, v113);
    }
    while ( v44 < v7 );
  }
}

