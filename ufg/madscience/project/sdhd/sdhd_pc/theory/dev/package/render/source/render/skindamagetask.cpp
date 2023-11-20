// File Line: 14
// RVA: 0x1457490
__int64 dynamic_initializer_for__gTaskFunctionDecl_SkinDamageBufferTask__()
{
  UFG::qTaskFunctionDecl::qTaskFunctionDecl(
    &gTaskFunctionDecl_SkinDamageBufferTask,
    &gTaskFunctionDeclData_SkinDamageBufferTask);
  return atexit(dynamic_atexit_destructor_for__gTaskFunctionDecl_SkinDamageBufferTask__);
}

// File Line: 15
// RVA: 0x1457460
__int64 dynamic_initializer_for__gTaskFunctionDecl_MorphSkinDamageBufferTask__()
{
  UFG::qTaskFunctionDecl::qTaskFunctionDecl(
    &gTaskFunctionDecl_MorphSkinDamageBufferTask,
    &gTaskFunctionDeclData_MorphSkinDamageBufferTask);
  return atexit(dynamic_atexit_destructor_for__gTaskFunctionDecl_MorphSkinDamageBufferTask__);
}

// File Line: 18
// RVA: 0x78360
void __fastcall SkinDamageBufferTask(int worker_id, UFG::qMemoryStreamer *memory_streamer, void *param0, void *param1)
{
  __int64 v4; // rbp
  __int64 v5; // rsi
  __m128 *v6; // r14
  __m128 *v7; // r15
  __int64 v8; // r11
  __int64 v9; // rbx
  __int64 v10; // rdi
  unsigned __int8 *v11; // r9
  __m128 v12; // xmm13
  __m128 *v13; // rax
  __int64 v14; // r10
  int v15; // er8
  __int64 v16; // rdx
  __m128 *v17; // rcx
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
  __m128 v42; // xmm7
  __m128 v43; // xmm9
  __m128 v44; // xmm12
  __m128i v45; // xmm6
  __m128 v46; // xmm3
  __m128 v47; // xmm4
  __m128 v48; // xmm5
  signed __int64 v49; // r13
  __m128 v50; // xmm1
  int v51; // edx
  int v52; // er8
  int v53; // edi
  __m128 v54; // xmm8
  int v55; // esi
  int v56; // eax
  __m128 v57; // xmm2
  __m128 *v58; // r9
  __m128 *v59; // r10
  __m128 *v60; // r11
  __m128 *v61; // rbx
  __m128 v62; // xmm10
  __m128 v63; // xmm11
  __m128 v64; // xmm10
  __m128 v65; // xmm9
  __m128 v66; // xmm12
  __m128 v67; // xmm9
  __m128 v68; // xmm14
  __m128 v69; // xmm0
  __m128 v70; // xmm9
  __m128 v71; // xmm6
  __m128 v72; // xmm8
  __m128 v73; // xmm6
  __m128 v74; // xmm4
  __m128 v75; // xmm5
  __m128 v76; // xmm3
  __m128 v77; // xmm8
  __m128 v78; // xmm2
  __m128 v79; // xmm7
  __m128 v80; // xmm0
  __m128 v81; // xmm6
  __m128 v82; // xmm4
  __m128 v83; // xmm3
  __m128 v84; // xmm5
  __m128 v85; // xmm10
  __m128 v86; // xmm7
  __m128 v87; // xmm2
  __m128 v88; // xmm8
  __m128 v89; // xmm3
  __m128 v90; // xmm5
  __m128 v91; // xmm3
  __m128 v92; // xmm4
  __m128 v93; // xmm8
  __m128 v94; // xmm0
  __m128 v95; // xmm5
  __m128 v96; // xmm11
  __m128 v97; // xmm8
  __m128 v98; // xmm6
  bool v99; // zf
  __m128i v100; // xmm2
  __m128i v101; // xmm2
  __m128i v102; // xmm2
  __m128i v103; // xmm2
  __m128 v104; // [rsp+0h] [rbp-41A8h]
  __m128 v105; // [rsp+10h] [rbp-4198h]
  __m128 v106; // [rsp+20h] [rbp-4188h]
  __m128 v107; // [rsp+70h] [rbp-4138h]
  __int128 v108; // [rsp+80h] [rbp-4128h]
  __m128 v109; // [rsp+90h] [rbp-4118h]
  __m128 v110; // [rsp+A0h] [rbp-4108h]
  __m128 v111; // [rsp+B0h] [rbp-40F8h]
  __m128 v112; // [rsp+C0h] [rbp-40E8h]
  __m128 v113; // [rsp+D0h] [rbp-40D8h]
  char v114[32]; // [rsp+E0h] [rbp-40C8h]
  char v115; // [rsp+100h] [rbp-40A8h]
  __int64 v116; // [rsp+41C0h] [rbp+18h]

  v4 = *((_QWORD *)param0 + 9);
  v5 = *(_QWORD *)param0;
  v6 = (__m128 *)*((_QWORD *)param0 + 1);
  v7 = (__m128 *)*((_QWORD *)param0 + 2);
  v8 = *((unsigned int *)param0 + 16);
  v9 = *((_QWORD *)param0 + 4);
  v10 = *((_QWORD *)param0 + 12);
  v11 = (unsigned __int8 *)*((_QWORD *)param0 + 13);
  v12 = gVmxOne_5;
  if ( *((_WORD *)param0 + 20) )
  {
    v13 = (__m128 *)&v115;
    v14 = *((unsigned __int16 *)param0 + 20);
    do
    {
      v15 = *v11;
      if ( v15 == 255 )
      {
        v13[-2] = gVmxIdentity0_5;
        v13[-1] = gVmxIdentity1_5;
        *v13 = gVmxIdentity2_5;
        v13[1] = gVmxIdentity3_5;
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
        v28 = _mm_sub_ps(gVmxOne_5, _mm_mul_ps(v27, v24));
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
        v41 = _mm_shuffle_ps(*(__m128 *)(v16 + v9), _mm_shuffle_ps(*(__m128 *)(v16 + v9), gVmxOne_5, 250), 148);
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
    v12 = gVmxOne_5;
  }
  v42 = gVmx127_3;
  v43 = gVmxOneOver127_3;
  v44 = gVmxOneOver255_3;
  v45 = gVmxUnpackBias_3;
  v46 = (__m128)gVmxUnpackMask_3;
  v47 = gVmxUnpackUnbias_3;
  v48 = gVmxUnpackShift_3;
  v113 = gVmx127_3;
  v110 = gVmxOneOver127_3;
  v112 = gVmxOneOver255_3;
  v111 = (__m128)gVmxSignBit_0;
  _mm_store_si128((__m128i *)&v108, gVmxUnpackBias_3);
  if ( (_DWORD)v8 )
  {
    v116 = v8;
    v49 = v5 + 20;
    v106 = _mm_and_ps(gVmxMinusOne_3, v12);
    do
    {
      v50 = v6[1];
      v51 = LOBYTE(v7->m128_u64[0]);
      v52 = BYTE1(v7->m128_u64[0]);
      v53 = BYTE2(v7->m128_u64[0]);
      v54 = _mm_shuffle_ps(*v6, _mm_shuffle_ps(*v6, v12, 250), 148);
      v55 = BYTE3(v7->m128_u64[0]);
      v56 = LOBYTE(v7->m128_u64[0]);
      v57 = (__m128)_mm_sub_epi32((__m128i)_mm_shuffle_ps(*v7, *v7, 85), v45);
      v109 = v54;
      v6 = (__m128 *)((char *)v6 + 24);
      v58 = (__m128 *)&v114[64 * v56];
      v7 = (__m128 *)((char *)v7 + 8);
      v59 = (__m128 *)&v114[64 * v52];
      v60 = (__m128 *)&v114[64 * v53];
      v61 = (__m128 *)&v114[64 * v55];
      v62 = _mm_add_ps(
              _mm_mul_ps(
                _mm_sub_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_cvtepi32_ps((__m128i)_mm_and_ps(
                                                   (__m128)_mm_sub_epi32((__m128i)_mm_shuffle_ps(v50, v50, 85), v45),
                                                   v46)),
                        v47),
                      v48),
                    (__m128)0i64),
                  v42),
                v43),
              (__m128)0i64);
      v63 = _mm_add_ps(
              _mm_mul_ps(
                _mm_sub_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_cvtepi32_ps((__m128i)_mm_and_ps(
                                                   (__m128)_mm_sub_epi32((__m128i)_mm_shuffle_ps(v50, v50, 0), v45),
                                                   v46)),
                        v47),
                      v48),
                    (__m128)0i64),
                  v42),
                v43),
              (__m128)0i64);
      v107 = _mm_shuffle_ps(v62, v62, 255);
      v64 = _mm_shuffle_ps(v62, _mm_shuffle_ps(v62, (__m128)0i64, 250), 148);
      v65 = _mm_mul_ps(
              _mm_add_ps(_mm_mul_ps(_mm_add_ps(_mm_cvtepi32_ps((__m128i)_mm_and_ps(v57, v46)), v47), v48), (__m128)0i64),
              v44);
      v66 = 0i64;
      v67 = _mm_add_ps(v65, (__m128)0i64);
      v68 = _mm_shuffle_ps(v67, v67, 0);
      v105 = _mm_shuffle_ps(v67, v67, 85);
      v69 = _mm_shuffle_ps(v67, v67, 170);
      v70 = _mm_shuffle_ps(v67, v67, 255);
      v104 = v69;
      if ( v4 != 0 )
      {
        v71 = _mm_cmpltps(v63, (__m128)0i64);
        v72 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_or_ps(
                    _mm_and_ps(
                      _mm_or_ps(
                        _mm_add_ps(
                          _mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(_mm_mul_ps(*(__m128 *)(32 * v51 + v4 + 16), v68), (__m128)0i64),
                              _mm_mul_ps(*(__m128 *)(32 * v52 + v4 + 16), v105)),
                            _mm_mul_ps(*(__m128 *)(32 * v53 + v4 + 16), v69)),
                          _mm_mul_ps(*(__m128 *)(32 * v55 + v4 + 16), v70)),
                        v111),
                      v71),
                    _mm_andnot_ps(
                      v71,
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(
                            _mm_add_ps(_mm_mul_ps(*(__m128 *)(32 * v51 + v4), v68), (__m128)0i64),
                            _mm_mul_ps(*(__m128 *)(32 * v52 + v4), v105)),
                          _mm_mul_ps(*(__m128 *)(32 * v53 + v4), v69)),
                        _mm_mul_ps(*(__m128 *)(32 * v55 + v4), v70)))),
                  v63),
                (__m128)0i64);
        v66 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v72, v72, 0), _mm_shuffle_ps(v12, v12, 0)), (__m128)0i64),
                  _mm_mul_ps(_mm_shuffle_ps(v72, v72, 85), _mm_shuffle_ps(v12, v12, 85))),
                _mm_mul_ps(_mm_shuffle_ps(v72, v72, 170), _mm_shuffle_ps(v12, v12, 170)));
        v54 = v109;
      }
      v73 = _mm_shuffle_ps(v54, v54, 0);
      v74 = _mm_shuffle_ps(v54, v54, 85);
      v75 = _mm_shuffle_ps(v54, v54, 170);
      v76 = v73;
      v77 = _mm_shuffle_ps(v54, v54, 255);
      v78 = _mm_add_ps(
              _mm_add_ps(_mm_add_ps(_mm_mul_ps(v73, *v59), (__m128)0i64), _mm_mul_ps(v74, v59[1])),
              _mm_mul_ps(v75, v59[2]));
      v79 = _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_add_ps(_mm_mul_ps(v73, *v58), (__m128)0i64), _mm_mul_ps(v74, v58[1])),
                    _mm_mul_ps(v75, v58[2])),
                  _mm_mul_ps(v77, v58[3])),
                v68),
              (__m128)0i64);
      v80 = _mm_mul_ps(v74, v60[1]);
      v81 = _mm_add_ps(
              _mm_add_ps(_mm_add_ps(_mm_mul_ps(v73, *v61), (__m128)0i64), _mm_mul_ps(v74, v61[1])),
              _mm_mul_ps(v75, v61[2]));
      v82 = _mm_shuffle_ps(v64, v64, 85);
      v83 = _mm_add_ps(
              _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(v76, *v60), (__m128)0i64), v80), _mm_mul_ps(v75, v60[2])),
              _mm_mul_ps(v77, v60[3]));
      v84 = _mm_shuffle_ps(v64, v64, 0);
      v85 = _mm_shuffle_ps(v64, v64, 170);
      v86 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(v79, _mm_mul_ps(_mm_add_ps(v78, _mm_mul_ps(v77, v59[3])), v105)),
                _mm_mul_ps(v83, v104)),
              _mm_mul_ps(_mm_add_ps(v81, _mm_mul_ps(v77, v61[3])), v70));
      v87 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v84, *v59), (__m128)0i64), _mm_mul_ps(v82, v59[1]));
      v88 = _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_add_ps(_mm_mul_ps(v84, *v58), (__m128)0i64), _mm_mul_ps(v82, v58[1])),
                  _mm_mul_ps(v85, v58[2])),
                v68),
              (__m128)0i64);
      v89 = v84;
      v90 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v84, *v61), (__m128)0i64), _mm_mul_ps(v82, v61[1]));
      v91 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v89, *v60), (__m128)0i64), _mm_mul_ps(v82, v60[1]));
      v92 = _mm_shuffle_ps(v63, v63, 85);
      v93 = _mm_max_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(v88, _mm_mul_ps(_mm_add_ps(v87, _mm_mul_ps(v85, v59[2])), v105)),
                  _mm_mul_ps(_mm_add_ps(v91, _mm_mul_ps(v85, v60[2])), v104)),
                _mm_mul_ps(_mm_add_ps(v90, _mm_mul_ps(v85, v61[2])), v70)),
              gVmxMinusOne_3);
      v94 = _mm_mul_ps(v92, v58[1]);
      v95 = _mm_shuffle_ps(v63, v63, 0);
      v96 = _mm_shuffle_ps(v63, v63, 170);
      *(__m128 *)(v49 - 20) = _mm_shuffle_ps(v86, _mm_shuffle_ps(v86, v66, 250), 148);
      v97 = _mm_min_ps(v93, v12);
      v42 = v113;
      v98 = _mm_add_ps(
              _mm_mul_ps(
                _mm_min_ps(
                  _mm_max_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(
                            _mm_mul_ps(
                              _mm_add_ps(
                                _mm_add_ps(_mm_add_ps(_mm_mul_ps(v95, *v58), (__m128)0i64), v94),
                                _mm_mul_ps(v96, v58[2])),
                              v68),
                            (__m128)0i64),
                          _mm_mul_ps(
                            _mm_add_ps(
                              _mm_add_ps(_mm_add_ps(_mm_mul_ps(v95, *v59), (__m128)0i64), _mm_mul_ps(v92, v59[1])),
                              _mm_mul_ps(v96, v59[2])),
                            v105)),
                        _mm_mul_ps(
                          _mm_add_ps(
                            _mm_add_ps(_mm_add_ps(_mm_mul_ps(v95, *v60), (__m128)0i64), _mm_mul_ps(v92, v60[1])),
                            _mm_mul_ps(v96, v60[2])),
                          v104)),
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v95, *v61), (__m128)0i64), _mm_mul_ps(v92, v61[1])),
                          _mm_mul_ps(v96, v61[2])),
                        v70)),
                    gVmxMinusOne_3),
                  v12),
                v113),
              v113);
      v46 = (__m128)gVmxUnpackMask_3;
      v47 = gVmxUnpackUnbias_3;
      v48 = gVmxUnpackShift_3;
      v49 += 24i64;
      v99 = v116-- == 1;
      v100 = _mm_cvtps_epi32(_mm_cvtepi32_ps(_mm_cvtps_epi32(v98)));
      v45 = _mm_load_si128((const __m128i *)&v108);
      v43 = v110;
      v101 = _mm_packs_epi32(v100, v100);
      v44 = v112;
      *(_DWORD *)(v49 - 28) = (unsigned __int128)_mm_packus_epi16(v101, v101);
      v102 = _mm_cvtps_epi32(
               _mm_cvtepi32_ps(
                 _mm_cvtps_epi32(
                   _mm_add_ps(
                     _mm_mul_ps(
                       _mm_shuffle_ps(
                         v97,
                         _mm_shuffle_ps(v97, _mm_or_ps(_mm_andnot_ps(v12, _mm_cmpltps(v107, (__m128)0i64)), v106), 250),
                         148),
                       v42),
                     v42))));
      v103 = _mm_packs_epi32(v102, v102);
      *(_DWORD *)(v49 - 24) = (unsigned __int128)_mm_packus_epi16(v103, v103);
    }
    while ( !v99 );
  }
}

// File Line: 23
// RVA: 0x78CF0
void __fastcall MorphSkinDamageBufferTask(int worker_id, UFG::qMemoryStreamer *memory_streamer, void *param0, void *param1)
{
  __int64 v4; // rdi
  __m128 *v5; // rax
  __int64 v6; // r14
  __m128 *v7; // r12
  __m128 *v8; // r13
  __m128 v9; // xmm10
  __int64 v10; // rbx
  __int64 v11; // rsi
  __int64 v12; // rbp
  unsigned __int8 *v13; // r9
  char *v14; // r10
  __m128 *v15; // rax
  __int64 v16; // r11
  int v17; // er8
  __int64 v18; // rdx
  __m128 *v19; // rcx
  __m128 v20; // xmm5
  __m128 v21; // xmm11
  __m128 v22; // xmm12
  __m128 v23; // xmm13
  __m128 v24; // xmm4
  __m128 v25; // xmm3
  __m128 v26; // xmm8
  __m128 v27; // xmm2
  __m128 v28; // xmm5
  __m128 v29; // xmm1
  __m128 v30; // xmm6
  __m128 v31; // xmm7
  __m128 v32; // xmm8
  __m128 v33; // xmm6
  __m128 v34; // xmm10
  __m128 v35; // xmm5
  __m128 v36; // xmm4
  __m128 v37; // xmm10
  __m128 v38; // xmm5
  __m128 v39; // xmm4
  __m128 v40; // xmm4
  __m128 v41; // xmm5
  __m128 v42; // xmm10
  __m128 v43; // xmm14
  __m128 v44; // xmm1
  __m128 v45; // xmm7
  __m128 v46; // xmm3
  __m128 v47; // xmm11
  __m128 v48; // xmm4
  __m128i v49; // xmm14
  __m128 v50; // xmm9
  __m128 v51; // xmm13
  __m128 v52; // xmm12
  __m128 v53; // xmm3
  signed __int64 v54; // r14
  __int64 v55; // r15
  __m128 v56; // xmm5
  int v57; // edx
  int v58; // er8
  int v59; // esi
  int v60; // ebp
  __m128 v61; // xmm6
  __m128 v62; // xmm2
  __m128 v63; // xmm8
  __m128 *v64; // r9
  __m128 *v65; // r10
  __m128 *v66; // r11
  __m128 *v67; // rbx
  __m128 v68; // xmm4
  __m128 v69; // xmm3
  __m128 v70; // xmm5
  __m128 v71; // xmm2
  __m128 v72; // xmm1
  __m128 v73; // xmm5
  __m128 v74; // xmm0
  __m128 v75; // xmm11
  __m128 v76; // xmm12
  __m128 v77; // xmm2
  __m128 v78; // xmm5
  __m128 v79; // xmm2
  __m128 v80; // xmm0
  __m128 v81; // xmm1
  __m128 v82; // xmm9
  __m128 v83; // xmm8
  __m128 v84; // xmm13
  __m128 v85; // xmm14
  __m128 v86; // xmm11
  __m128 v87; // xmm6
  __m128 v88; // xmm8
  __m128 v89; // xmm4
  __m128 v90; // xmm5
  __m128 v91; // xmm7
  __m128 v92; // xmm12
  __m128 v93; // xmm7
  __m128 v94; // xmm5
  __m128 v95; // xmm4
  __m128 v96; // xmm2
  __m128 v97; // xmm12
  __m128 v98; // xmm6
  __m128 v99; // xmm3
  __m128 v100; // xmm5
  __m128 v101; // xmm3
  __m128 v102; // xmm2
  __m128 v103; // xmm1
  __m128 v104; // xmm12
  __m128 v105; // xmm6
  __m128i v106; // xmm2
  __m128i v107; // xmm2
  __m128i v108; // xmm2
  __m128i v109; // xmm2
  __m128 *v110; // [rsp+0h] [rbp-4218h]
  __m128 v111; // [rsp+10h] [rbp-4208h]
  __m128 v112; // [rsp+20h] [rbp-41F8h]
  __m128 v113; // [rsp+30h] [rbp-41E8h]
  __m128 v114; // [rsp+50h] [rbp-41C8h]
  __m128 v115; // [rsp+60h] [rbp-41B8h]
  __m128 v116; // [rsp+70h] [rbp-41A8h]
  __m128 v117; // [rsp+A0h] [rbp-4178h]
  __m128 v118; // [rsp+E0h] [rbp-4138h]
  __int128 v119; // [rsp+110h] [rbp-4108h]
  __m128 v120; // [rsp+120h] [rbp-40F8h]
  __m128i v121; // [rsp+130h] [rbp-40E8h]
  __m128 v122; // [rsp+140h] [rbp-40D8h]
  char v123[32]; // [rsp+150h] [rbp-40C8h]
  char v124; // [rsp+170h] [rbp-40A8h]

  v4 = *((_QWORD *)param0 + 9);
  v5 = (__m128 *)*((_QWORD *)param0 + 6);
  v6 = *(_QWORD *)param0;
  v7 = (__m128 *)*((_QWORD *)param0 + 1);
  v8 = (__m128 *)*((_QWORD *)param0 + 2);
  v9 = gVmxOne_5;
  v10 = *((unsigned int *)param0 + 16);
  v11 = *((_QWORD *)param0 + 4);
  v12 = *((_QWORD *)param0 + 12);
  v13 = (unsigned __int8 *)*((_QWORD *)param0 + 13);
  v14 = (char *)param0;
  v110 = (__m128 *)*((_QWORD *)param0 + 6);
  if ( *((_WORD *)param0 + 20) )
  {
    v15 = (__m128 *)&v124;
    v16 = *((unsigned __int16 *)param0 + 20);
    do
    {
      v17 = *v13;
      if ( v17 == 255 )
      {
        v15[-2] = gVmxIdentity0_5;
        v15[-1] = gVmxIdentity1_5;
        *v15 = gVmxIdentity2_5;
        v15[1] = gVmxIdentity3_5;
      }
      else
      {
        v18 = (unsigned int)(48 * v17);
        v19 = (__m128 *)(v12 + (unsigned int)(v17 << 6));
        v20 = *(__m128 *)(v18 + v11 + 16);
        v21 = v19[1];
        v22 = v19[2];
        v23 = v19[3];
        v24 = _mm_shuffle_ps(*(__m128 *)(v18 + v11 + 16), v20, 255);
        v25 = _mm_add_ps(v20, v20);
        v26 = _mm_shuffle_ps(*(__m128 *)(v18 + v11 + 16), v20, 201);
        v27 = _mm_shuffle_ps(v25, v25, 210);
        v28 = _mm_shuffle_ps(v20, v20, 210);
        v29 = _mm_shuffle_ps(v25, v25, 201);
        v30 = _mm_sub_ps(v9, _mm_mul_ps(v29, v26));
        v31 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v29, v24), (__m128)0i64), _mm_mul_ps(v28, v25));
        v32 = _mm_sub_ps(_mm_add_ps(_mm_mul_ps(v26, v25), (__m128)0i64), _mm_mul_ps(v27, v24));
        v33 = _mm_sub_ps(v30, _mm_mul_ps(v27, v28));
        v34 = _mm_shuffle_ps(_mm_shuffle_ps(v31, v32, 80), v32, 233);
        v35 = _mm_shuffle_ps(_mm_shuffle_ps(v32, v33, 80), v33, 233);
        v36 = _mm_shuffle_ps(_mm_shuffle_ps(v33, v31, 80), v31, 233);
        v37 = _mm_shuffle_ps(v34, _mm_shuffle_ps(v33, v34, 250), 148);
        v38 = _mm_shuffle_ps(v35, _mm_shuffle_ps(v31, v35, 250), 148);
        v39 = _mm_shuffle_ps(v36, _mm_shuffle_ps(v32, v36, 250), 148);
        v40 = _mm_shuffle_ps(v39, _mm_shuffle_ps(v39, (__m128)0i64, 250), 148);
        v41 = _mm_shuffle_ps(v38, _mm_shuffle_ps(v38, (__m128)0i64, 250), 148);
        v42 = _mm_shuffle_ps(v37, _mm_shuffle_ps(v37, (__m128)0i64, 250), 148);
        v43 = _mm_shuffle_ps(*(__m128 *)(v18 + v11), _mm_shuffle_ps(*(__m128 *)(v18 + v11), gVmxOne_5, 250), 148);
        v15[-2] = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(*v19, *v19, 0), v40), (__m128)0i64),
                        _mm_mul_ps(_mm_shuffle_ps(*v19, *v19, 85), v41)),
                      _mm_mul_ps(_mm_shuffle_ps(*v19, *v19, 170), v42)),
                    _mm_mul_ps(_mm_shuffle_ps(*v19, *v19, 255), v43));
        v15[-1] = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v21, v21, 0), v40), (__m128)0i64),
                        _mm_mul_ps(_mm_shuffle_ps(v21, v21, 85), v41)),
                      _mm_mul_ps(_mm_shuffle_ps(v21, v21, 170), v42)),
                    _mm_mul_ps(_mm_shuffle_ps(v21, v21, 255), v43));
        *v15 = _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v22, v22, 0), v40), (__m128)0i64),
                     _mm_mul_ps(_mm_shuffle_ps(v22, v22, 85), v41)),
                   _mm_mul_ps(_mm_shuffle_ps(v22, v22, 170), v42)),
                 _mm_mul_ps(_mm_shuffle_ps(v22, v22, 255), v43));
        v44 = _mm_mul_ps(_mm_shuffle_ps(v23, v23, 170), v42);
        v9 = gVmxOne_5;
        v15[1] = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v23, v23, 0), v40), (__m128)0i64),
                       _mm_mul_ps(_mm_shuffle_ps(v23, v23, 85), v41)),
                     v44),
                   _mm_mul_ps(_mm_shuffle_ps(v23, v23, 255), v43));
      }
      v15 += 4;
      ++v13;
      --v16;
    }
    while ( v16 );
    v5 = v110;
  }
  v45 = gVmx127_3;
  v46 = *(__m128 *)(v14 + 56);
  v47 = gVmxOneOver127_3;
  v48 = (__m128)gVmxi127_3;
  v49 = gVmxUnpackBias_3;
  v50 = (__m128)gVmxUnpackMask_3;
  v51 = gVmxUnpackUnbias_3;
  v52 = gVmxUnpackShift_3;
  v122 = (__m128)gVmxSignBit_0;
  v121 = gVmxi127_3;
  _mm_store_si128((__m128i *)&v119, gVmxUnpackBias_3);
  if ( (_DWORD)v10 )
  {
    v53 = _mm_shuffle_ps(v46, v46, 0);
    v54 = v6 + 20;
    v55 = v10;
    v116 = v53;
    v114 = _mm_and_ps(gVmxMinusOne_3, v9);
    do
    {
      v56 = v7[1];
      v57 = LOBYTE(v8->m128_u64[0]);
      v58 = BYTE1(v8->m128_u64[0]);
      v59 = BYTE2(v8->m128_u64[0]);
      v60 = BYTE3(v8->m128_u64[0]);
      v61 = *v8;
      v62 = _mm_shuffle_ps(*v5, _mm_shuffle_ps(*v5, v48, 85), 149);
      v63 = _mm_shuffle_ps(*v7, _mm_shuffle_ps(*v7, v9, 250), 148);
      v64 = (__m128 *)&v123[64 * v57];
      v7 = (__m128 *)((char *)v7 + 24);
      v8 = (__m128 *)((char *)v8 + 8);
      v65 = (__m128 *)&v123[64 * v58];
      v66 = (__m128 *)&v123[64 * v59];
      v67 = (__m128 *)&v123[64 * v60];
      v68 = _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_sub_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_cvtepi32_ps((__m128i)_mm_and_ps(
                                                     _mm_shuffle_ps(*v5, _mm_shuffle_ps(*v5, v48, 0), 144),
                                                     v50)),
                          v52),
                        (__m128)0i64),
                      v45),
                    gVmxOneOver511_3),
                  (__m128)0i64),
                v53),
              (__m128)0i64);
      v69 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_sub_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_cvtepi32_ps((__m128i)_mm_and_ps(
                                                     (__m128)_mm_sub_epi32((__m128i)_mm_shuffle_ps(v56, v56, 0), v49),
                                                     v50)),
                          v51),
                        v52),
                      (__m128)0i64),
                    v45),
                  v47),
                (__m128)0i64),
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_sub_ps(
                        _mm_add_ps(_mm_mul_ps(_mm_cvtepi32_ps((__m128i)_mm_and_ps(v62, v50)), v52), (__m128)0i64),
                        v45),
                      v47),
                    (__m128)0i64),
                  v53),
                (__m128)0i64));
      v70 = _mm_add_ps(
              _mm_mul_ps(
                _mm_sub_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_cvtepi32_ps((__m128i)_mm_and_ps(
                                                   (__m128)_mm_sub_epi32((__m128i)_mm_shuffle_ps(v56, v56, 85), v49),
                                                   v50)),
                        v51),
                      v52),
                    (__m128)0i64),
                  v45),
                v47),
              (__m128)0i64);
      v71 = _mm_shuffle_ps(v69, v69, 0);
      v72 = _mm_shuffle_ps(v69, v69, 170);
      v113 = _mm_shuffle_ps(v70, v70, 255);
      v115 = _mm_add_ps(v63, v68);
      v73 = _mm_shuffle_ps(v70, _mm_shuffle_ps(v70, (__m128)0i64, 250), 148);
      v74 = _mm_shuffle_ps(v69, v69, 85);
      v75 = _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_cvtepi32_ps((__m128i)_mm_and_ps(
                                                 (__m128)_mm_sub_epi32((__m128i)_mm_shuffle_ps(v61, v61, 85), v49),
                                                 v50)),
                      v51),
                    v52),
                  (__m128)0i64),
                gVmxOneOver255_3),
              (__m128)0i64);
      v76 = _mm_add_ps(
              _mm_mul_ps(
                _mm_rsqrt_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_add_ps(_mm_mul_ps(v71, v71), (__m128)0i64), _mm_mul_ps(v74, v74)),
                    _mm_mul_ps(v72, v72))),
                v69),
              (__m128)0i64);
      v120 = _mm_shuffle_ps(v76, v76, 0);
      v117 = _mm_shuffle_ps(v76, v76, 85);
      v112 = _mm_shuffle_ps(v76, v76, 170);
      v77 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v73, v73, 0), v120), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps(v73, v73, 85), v117)),
              _mm_mul_ps(_mm_shuffle_ps(v73, v73, 170), v112));
      v78 = _mm_sub_ps(
              v73,
              _mm_sub_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v77, v77, 201), _mm_shuffle_ps(v76, v76, 210)), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps(v77, v77, 210), _mm_shuffle_ps(v76, v76, 201))));
      v79 = _mm_shuffle_ps(v78, v78, 0);
      v80 = _mm_shuffle_ps(v78, v78, 85);
      v81 = _mm_shuffle_ps(v78, v78, 170);
      v82 = 0i64;
      v83 = _mm_shuffle_ps(v75, v75, 170);
      v84 = _mm_shuffle_ps(v75, v75, 0);
      v111 = v83;
      v118 = _mm_add_ps(
               _mm_mul_ps(
                 _mm_rsqrt_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_add_ps(_mm_mul_ps(v79, v79), (__m128)0i64), _mm_mul_ps(v80, v80)),
                     _mm_mul_ps(v81, v81))),
                 v78),
               (__m128)0i64);
      v85 = _mm_shuffle_ps(v75, v75, 85);
      v86 = _mm_shuffle_ps(v75, v75, 255);
      if ( v4 != 0 )
      {
        v87 = _mm_cmpltps(v76, (__m128)0i64);
        v88 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_or_ps(
                    _mm_and_ps(
                      _mm_or_ps(
                        _mm_add_ps(
                          _mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(_mm_mul_ps(*(__m128 *)(32 * v57 + v4 + 16), v84), (__m128)0i64),
                              _mm_mul_ps(*(__m128 *)(32 * v58 + v4 + 16), v85)),
                            _mm_mul_ps(*(__m128 *)(32 * v59 + v4 + 16), v83)),
                          _mm_mul_ps(*(__m128 *)(32 * v60 + v4 + 16), v86)),
                        v122),
                      v87),
                    _mm_andnot_ps(
                      v87,
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(
                            _mm_add_ps(_mm_mul_ps(*(__m128 *)(32 * v57 + v4), v84), (__m128)0i64),
                            _mm_mul_ps(*(__m128 *)(32 * v58 + v4), v85)),
                          _mm_mul_ps(*(__m128 *)(32 * v59 + v4), v83)),
                        _mm_mul_ps(*(__m128 *)(32 * v60 + v4), v86)))),
                  v76),
                (__m128)0i64);
        v82 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v88, v88, 0), _mm_shuffle_ps(v9, v9, 0)), (__m128)0i64),
                  _mm_mul_ps(_mm_shuffle_ps(v88, v88, 85), _mm_shuffle_ps(v9, v9, 85))),
                _mm_mul_ps(_mm_shuffle_ps(v88, v88, 170), _mm_shuffle_ps(v9, v9, 170)));
        v83 = v111;
      }
      v89 = _mm_shuffle_ps(v115, v115, 85);
      v90 = _mm_shuffle_ps(v115, v115, 170);
      v91 = _mm_shuffle_ps(v115, v115, 0);
      v92 = _mm_shuffle_ps(v115, v115, 255);
      v93 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v91, *v64), (__m128)0i64), _mm_mul_ps(v89, v64[1])),
                          _mm_mul_ps(v90, v64[2])),
                        _mm_mul_ps(v92, v64[3])),
                      v84),
                    (__m128)0i64),
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_add_ps(_mm_mul_ps(v91, *v65), (__m128)0i64), _mm_mul_ps(v89, v65[1])),
                        _mm_mul_ps(v90, v65[2])),
                      _mm_mul_ps(v92, v65[3])),
                    v85)),
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_add_ps(_mm_mul_ps(v91, *v66), (__m128)0i64), _mm_mul_ps(v89, v66[1])),
                      _mm_mul_ps(v90, v66[2])),
                    _mm_mul_ps(v92, v66[3])),
                  v83)),
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_add_ps(_mm_mul_ps(v91, *v67), (__m128)0i64), _mm_mul_ps(v89, v67[1])),
                    _mm_mul_ps(v90, v67[2])),
                  _mm_mul_ps(v92, v67[3])),
                v86));
      v94 = _mm_shuffle_ps(v118, v118, 0);
      v95 = _mm_shuffle_ps(v118, v118, 85);
      v96 = _mm_add_ps(_mm_mul_ps(v94, *v65), (__m128)0i64);
      v97 = _mm_shuffle_ps(v118, v118, 170);
      v98 = _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_add_ps(_mm_mul_ps(v94, *v64), (__m128)0i64), _mm_mul_ps(v95, v64[1])),
                  _mm_mul_ps(v97, v64[2])),
                v84),
              (__m128)0i64);
      v99 = v94;
      v100 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v94, *v67), (__m128)0i64), _mm_mul_ps(v95, v67[1]));
      v101 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v99, *v66), (__m128)0i64), _mm_mul_ps(v95, v66[1]));
      v102 = _mm_add_ps(_mm_add_ps(v96, _mm_mul_ps(v95, v65[1])), _mm_mul_ps(v97, v65[2]));
      v103 = _mm_mul_ps(v97, v66[2]);
      v104 = _mm_mul_ps(v97, v67[2]);
      *(__m128 *)(v54 - 20) = _mm_shuffle_ps(v93, _mm_shuffle_ps(v93, v82, 250), 148);
      v105 = _mm_min_ps(
               _mm_max_ps(
                 _mm_add_ps(
                   _mm_add_ps(_mm_add_ps(v98, _mm_mul_ps(v102, v85)), _mm_mul_ps(_mm_add_ps(v101, v103), v83)),
                   _mm_mul_ps(_mm_add_ps(v100, v104), v86)),
                 gVmxMinusOne_3),
               v9);
      v45 = gVmx127_3;
      v53 = v116;
      v50 = (__m128)gVmxUnpackMask_3;
      v52 = gVmxUnpackShift_3;
      v5 = (__m128 *)((char *)v5 + 8);
      v54 += 24i64;
      v106 = _mm_cvtps_epi32(
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
                                         _mm_add_ps(_mm_mul_ps(v120, *v64), (__m128)0i64),
                                         _mm_mul_ps(v117, v64[1])),
                                       _mm_mul_ps(v112, v64[2])),
                                     v84),
                                   (__m128)0i64),
                                 _mm_mul_ps(
                                   _mm_add_ps(
                                     _mm_add_ps(
                                       _mm_add_ps(_mm_mul_ps(v120, *v65), (__m128)0i64),
                                       _mm_mul_ps(v117, v65[1])),
                                     _mm_mul_ps(v112, v65[2])),
                                   v85)),
                               _mm_mul_ps(
                                 _mm_add_ps(
                                   _mm_add_ps(
                                     _mm_add_ps(_mm_mul_ps(v120, *v66), (__m128)0i64),
                                     _mm_mul_ps(v117, v66[1])),
                                   _mm_mul_ps(v112, v66[2])),
                                 v83)),
                             _mm_mul_ps(
                               _mm_add_ps(
                                 _mm_add_ps(_mm_add_ps(_mm_mul_ps(v120, *v67), (__m128)0i64), _mm_mul_ps(v117, v67[1])),
                                 _mm_mul_ps(v112, v67[2])),
                               v86)),
                           gVmxMinusOne_3),
                         v9),
                       gVmx127_3),
                     gVmx127_3))));
      v47 = gVmxOneOver127_3;
      v51 = gVmxUnpackUnbias_3;
      v107 = _mm_packs_epi32(v106, v106);
      *(_DWORD *)(v54 - 28) = (unsigned __int128)_mm_packus_epi16(v107, v107);
      v49 = _mm_load_si128((const __m128i *)&v119);
      v48 = (__m128)v121;
      v108 = _mm_cvtps_epi32(
               _mm_cvtepi32_ps(
                 _mm_cvtps_epi32(
                   _mm_add_ps(
                     _mm_mul_ps(
                       _mm_shuffle_ps(
                         v105,
                         _mm_shuffle_ps(v105, _mm_or_ps(_mm_andnot_ps(v9, _mm_cmpltps(v113, (__m128)0i64)), v114), 250),
                         148),
                       gVmx127_3),
                     gVmx127_3))));
      v109 = _mm_packs_epi32(v108, v108);
      *(_DWORD *)(v54 - 24) = (unsigned __int128)_mm_packus_epi16(v109, v109);
      --v55;
    }
    while ( v55 );
  }
}

