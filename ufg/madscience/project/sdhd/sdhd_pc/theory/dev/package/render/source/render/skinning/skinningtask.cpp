// File Line: 8
// RVA: 0x14539A0
__int64 Render::_dynamic_initializer_for__gTaskFunctionDecl_SkinBufferTask__()
{
  UFG::qTaskFunctionDecl::qTaskFunctionDecl(
    &Render::gTaskFunctionDecl_SkinBufferTask,
    &Render::gTaskFunctionDeclData_SkinBufferTask);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gTaskFunctionDecl_SkinBufferTask__);
}

// File Line: 9
// RVA: 0x1453A00
__int64 Render::_dynamic_initializer_for__gTaskFunctionDecl_SkinMorphBufferTask__()
{
  UFG::qTaskFunctionDecl::qTaskFunctionDecl(
    &Render::gTaskFunctionDecl_SkinMorphBufferTask,
    &Render::gTaskFunctionDeclData_SkinMorphBufferTask);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gTaskFunctionDecl_SkinMorphBufferTask__);
}

// File Line: 10
// RVA: 0x14539D0
__int64 Render::_dynamic_initializer_for__gTaskFunctionDecl_SkinCacheBufferTask__()
{
  UFG::qTaskFunctionDecl::qTaskFunctionDecl(
    &Render::gTaskFunctionDecl_SkinCacheBufferTask,
    &Render::gTaskFunctionDeclData_SkinCacheBufferTask);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gTaskFunctionDecl_SkinCacheBufferTask__);
}

// File Line: 13
// RVA: 0x1EC90
void __fastcall Render::SkinBufferTask(
        int worker_id,
        UFG::qMemoryStreamer *memory_streamer,
        _QWORD *param0,
        void *param1)
{
  __int64 v4; // rdi
  __m128 *v5; // rbp
  __m128 v6; // xmm6
  _OWORD *v7; // r14
  __int64 v8; // rsi
  __int64 v9; // r11
  unsigned __int8 *v10; // r9
  __int64 v11; // rbx
  __m128 v12; // xmm15
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
  __m128 v42; // xmm5
  __m128i v43; // xmm4
  __m128 v44; // xmm10
  __m128 v45; // xmm12
  __m128 v46; // xmm14
  __int64 v47; // rdi
  __int64 v48; // r10
  __m128 v49; // xmm1
  __m128 v50; // xmm2
  unsigned __int8 *v51; // rcx
  __int64 v52; // rdx
  __int64 v53; // r8
  __m128 v54; // xmm11
  __int64 v55; // r9
  int v56; // eax
  __m128i v57; // xmm0
  __m128 v58; // xmm4
  __m128 v59; // xmm6
  __m128 v60; // xmm1
  __m128 v61; // xmm4
  __m128 v62; // xmm13
  __m128 v63; // xmm5
  __m128 v64; // xmm4
  __m128 v65; // xmm13
  __m128 v66; // xmm10
  __m128 v67; // xmm12
  __m128 v68; // xmm14
  __m128 v69; // xmm4
  __m128 v70; // xmm11
  __m128 v71; // xmm7
  __m128 v72; // xmm1
  __m128 v73; // xmm15
  __m128 v74; // xmm3
  __m128 v75; // xmm6
  __m128 v76; // xmm4
  __m128 v77; // xmm6
  __m128 v78; // xmm5
  __m128 v79; // xmm3
  __m128 v80; // xmm6
  __m128 v81; // xmm11
  __m128 v82; // xmm15
  __m128 v83; // xmm6
  __m128 v84; // xmm13
  __m128 v85; // xmm8
  __m128 v86; // xmm2
  __m128 v87; // xmm3
  __m128 v88; // xmm6
  __m128 v89; // xmm3
  __m128 v90; // xmm4
  __m128 v91; // xmm5
  __m128 v92; // xmm8
  __m128 v93; // xmm6
  __m128 v94; // xmm13
  __m128 v95; // xmm7
  __m128i v96; // xmm2
  __m128i v97; // xmm2
  __m128 v98; // xmm1
  __m128i v99; // xmm2
  __m128i v100; // xmm2
  __m128i v101; // [rsp+10h] [rbp-4158h] BYREF
  __m128 v102; // [rsp+20h] [rbp-4148h]
  __m128 v103; // [rsp+30h] [rbp-4138h]
  __m128 v104; // [rsp+40h] [rbp-4128h]
  __m128 v105; // [rsp+50h] [rbp-4118h]
  __m128i v106; // [rsp+60h] [rbp-4108h]
  __m128 v107; // [rsp+70h] [rbp-40F8h]
  __m128 v108; // [rsp+80h] [rbp-40E8h]
  __m128 v109; // [rsp+90h] [rbp-40D8h]
  __m128 v110; // [rsp+A0h] [rbp-40C8h]
  __m128 v111; // [rsp+B0h] [rbp-40B8h]
  __int128 v112[2]; // [rsp+C0h] [rbp-40A8h]
  __int128 v113[1022]; // [rsp+E0h] [rbp-4088h] BYREF

  v4 = *param0;
  v5 = (__m128 *)param0[1];
  v6 = gVmxOne_0;
  v7 = (_OWORD *)param0[2];
  v8 = *((unsigned int *)param0 + 16);
  v9 = param0[4];
  v10 = (unsigned __int8 *)param0[13];
  v11 = param0[12];
  v12 = 0i64;
  if ( *((_WORD *)param0 + 20) )
  {
    v13 = (__m128 *)v113;
    v14 = *((unsigned __int16 *)param0 + 20);
    do
    {
      v15 = *v10;
      if ( v15 == 255 )
      {
        v13[-2] = gVmxIdentity0_0;
        v13[-1] = gVmxIdentity1_0;
        *v13 = gVmxIdentity2_0;
        v13[1] = gVmxIdentity3_0;
      }
      else
      {
        v16 = (unsigned int)(48 * v15);
        v17 = (__m128 *)(v11 + (unsigned int)(v15 << 6));
        v18 = *(__m128 *)(v16 + v9 + 16);
        v19 = v17[1];
        v20 = v17[2];
        v21 = v17[3];
        v22 = _mm_shuffle_ps(v18, v18, 255);
        v23 = _mm_add_ps(v18, v18);
        v24 = _mm_shuffle_ps(v18, v18, 201);
        v25 = _mm_shuffle_ps(v18, v18, 210);
        v26 = _mm_shuffle_ps(v23, v23, 201);
        v27 = _mm_sub_ps(v6, _mm_mul_ps(v26, v24));
        v28 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v26, v22), (__m128)0i64), _mm_mul_ps(v25, v23));
        v29 = _mm_shuffle_ps(v23, v23, 210);
        v30 = _mm_sub_ps(_mm_add_ps(_mm_mul_ps(v24, v23), (__m128)0i64), _mm_mul_ps(v29, v22));
        v31 = _mm_sub_ps(v27, _mm_mul_ps(v29, v25));
        v32 = _mm_shuffle_ps(_mm_shuffle_ps(v28, v30, 80), v30, 233);
        v33 = _mm_shuffle_ps(_mm_shuffle_ps(v30, v31, 80), v31, 233);
        v34 = _mm_shuffle_ps(_mm_shuffle_ps(v31, v28, 80), v28, 233);
        v35 = _mm_shuffle_ps(v32, _mm_shuffle_ps(v31, v32, 250), 148);
        v6 = gVmxOne_0;
        v36 = _mm_shuffle_ps(v33, _mm_shuffle_ps(v28, v33, 250), 148);
        v37 = _mm_shuffle_ps(v34, _mm_shuffle_ps(v30, v34, 250), 148);
        v38 = _mm_shuffle_ps(v37, _mm_shuffle_ps(v37, (__m128)0i64, 250), 148);
        v39 = _mm_shuffle_ps(v36, _mm_shuffle_ps(v36, (__m128)0i64, 250), 148);
        v40 = _mm_shuffle_ps(v35, _mm_shuffle_ps(v35, (__m128)0i64, 250), 148);
        v41 = _mm_shuffle_ps(*(__m128 *)(v16 + v9), _mm_shuffle_ps(*(__m128 *)(v16 + v9), gVmxOne_0, 250), 148);
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
      ++v10;
      --v14;
    }
    while ( v14 );
  }
  v42 = gVmx127;
  v43 = gVmxUnpackBias;
  v44 = (__m128)gVmxUnpackMask;
  v45 = gVmxUnpackUnbias;
  v46 = gVmxUnpackShift;
  v107 = gVmxOneOver127;
  v111 = gVmxOneOver255;
  v102 = gVmx127;
  v101 = gVmxUnpackBias;
  v106 = gVmxUnpackMask;
  v108 = gVmxUnpackUnbias;
  v110 = gVmxUnpackShift;
  if ( (_DWORD)v8 )
  {
    v47 = v4 - (_QWORD)v5;
    v48 = v8;
    v104 = _mm_and_ps(gVmxMinusOne, v6);
    do
    {
      v49 = v5[1];
      v50 = *(__m128 *)v7;
      v51 = (unsigned __int8 *)v7;
      v7 = (_OWORD *)((char *)v7 + 8);
      v52 = *v51 << 6;
      v53 = v51[1] << 6;
      v54 = _mm_shuffle_ps(*v5, _mm_shuffle_ps(*v5, v6, 250), 148);
      v55 = v51[2] << 6;
      v56 = v51[3] << 6;
      v57 = (__m128i)_mm_and_ps((__m128)_mm_sub_epi32((__m128i)_mm_shuffle_ps(v49, v49, 0), v43), v44);
      v58 = _mm_cvtepi32_ps((__m128i)_mm_and_ps((__m128)_mm_sub_epi32((__m128i)_mm_shuffle_ps(v49, v49, 85), v43), v44));
      v59 = _mm_shuffle_ps(v54, v54, 0);
      v60 = _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_cvtepi32_ps((__m128i)_mm_and_ps(
                                                 (__m128)_mm_sub_epi32((__m128i)_mm_shuffle_ps(v50, v50, 85), v101),
                                                 v44)),
                      v45),
                    v46),
                  v12),
                v111),
              v12);
      v61 = _mm_sub_ps(_mm_add_ps(_mm_mul_ps(_mm_add_ps(v58, v45), v46), v12), v42);
      v62 = _mm_sub_ps(_mm_add_ps(_mm_mul_ps(_mm_add_ps(_mm_cvtepi32_ps(v57), v45), v46), v12), v42);
      v63 = _mm_shuffle_ps(v54, v54, 170);
      v64 = _mm_add_ps(_mm_mul_ps(v61, v107), v12);
      v65 = _mm_add_ps(_mm_mul_ps(v62, v107), v12);
      v66 = _mm_shuffle_ps(v60, v60, 0);
      v67 = _mm_shuffle_ps(v60, v60, 85);
      v68 = _mm_shuffle_ps(v60, v60, 170);
      v103 = _mm_shuffle_ps(v64, v64, 255);
      v105 = _mm_shuffle_ps(v60, v60, 255);
      v109 = _mm_shuffle_ps(v64, _mm_shuffle_ps(v64, v12, 250), 148);
      v69 = _mm_shuffle_ps(v54, v54, 85);
      v70 = _mm_shuffle_ps(v54, v54, 255);
      v71 = *(__m128 *)((char *)v112 + v55);
      v72 = _mm_mul_ps(v63, *(__m128 *)((char *)v113 + v55));
      v73 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_mul_ps(v59, *(__m128 *)((char *)v112 + v52)), (__m128)0i64),
                        _mm_mul_ps(v69, *(__m128 *)((char *)&v112[1] + v52))),
                      _mm_mul_ps(v63, *(__m128 *)((char *)v113 + v52))),
                    _mm_mul_ps(v70, *(__m128 *)((char *)&v113[1] + v52))),
                  v66),
                (__m128)0i64),
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_mul_ps(v59, *(__m128 *)((char *)v112 + v53)), (__m128)0i64),
                      _mm_mul_ps(v69, *(__m128 *)((char *)&v112[1] + v53))),
                    _mm_mul_ps(v63, *(__m128 *)((char *)v113 + v53))),
                  _mm_mul_ps(v70, *(__m128 *)((char *)&v113[1] + v53))),
                v67));
      v74 = _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(v59, v71), (__m128)0i64),
              _mm_mul_ps(v69, *(__m128 *)((char *)&v112[1] + v55)));
      v75 = _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(v59, *(__m128 *)((char *)v112 + v56)), (__m128)0i64),
              _mm_mul_ps(v69, *(__m128 *)((char *)&v112[1] + v56)));
      v76 = _mm_shuffle_ps(v65, v65, 85);
      v77 = _mm_add_ps(v75, _mm_mul_ps(v63, *(__m128 *)((char *)v113 + v56)));
      v78 = _mm_shuffle_ps(v65, v65, 170);
      v79 = _mm_add_ps(_mm_add_ps(v74, v72), _mm_mul_ps(v70, *(__m128 *)((char *)&v113[1] + v55)));
      v80 = _mm_add_ps(v77, _mm_mul_ps(v70, *(__m128 *)((char *)&v113[1] + v56)));
      v81 = *(__m128 *)((char *)v112 + v52);
      v82 = _mm_add_ps(_mm_add_ps(v73, _mm_mul_ps(v79, v68)), _mm_mul_ps(v80, v105));
      v83 = _mm_shuffle_ps(v65, v65, 0);
      v84 = _mm_mul_ps(_mm_shuffle_ps(v65, v65, 255), (__m128)0i64);
      v85 = _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_mul_ps(v83, v81), (__m128)0i64),
                      _mm_mul_ps(v76, *(__m128 *)((char *)&v112[1] + v52))),
                    _mm_mul_ps(v78, *(__m128 *)((char *)v113 + v52))),
                  v84),
                v66),
              (__m128)0i64);
      v86 = _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_mul_ps(v83, *(__m128 *)((char *)v112 + v53)), (__m128)0i64),
                    _mm_mul_ps(v76, *(__m128 *)((char *)&v112[1] + v53))),
                  _mm_mul_ps(v78, *(__m128 *)((char *)v113 + v53))),
                v84),
              v67);
      v87 = v83;
      v88 = _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_mul_ps(v83, *(__m128 *)((char *)v112 + v56)), (__m128)0i64),
                    _mm_mul_ps(v76, *(__m128 *)((char *)&v112[1] + v56))),
                  _mm_mul_ps(v78, *(__m128 *)((char *)v113 + v56))),
                v84),
              v105);
      v89 = _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_mul_ps(v87, v71), (__m128)0i64),
                    _mm_mul_ps(v76, *(__m128 *)((char *)&v112[1] + v55))),
                  _mm_mul_ps(v78, *(__m128 *)((char *)v113 + v55))),
                v84),
              v68);
      v90 = _mm_shuffle_ps(v109, v109, 85);
      v91 = _mm_shuffle_ps(v109, v109, 170);
      v92 = _mm_add_ps(_mm_add_ps(_mm_add_ps(v85, v86), v89), v88);
      v93 = _mm_shuffle_ps(v109, v109, 0);
      v94 = _mm_mul_ps(_mm_shuffle_ps(v109, v109, 255), (__m128)0i64);
      v95 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(
                            _mm_add_ps(_mm_mul_ps(v93, v81), (__m128)0i64),
                            _mm_mul_ps(v90, *(__m128 *)((char *)&v112[1] + v52))),
                          _mm_mul_ps(v91, *(__m128 *)((char *)v113 + v52))),
                        v94),
                      v66),
                    (__m128)0i64),
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(_mm_mul_ps(v93, *(__m128 *)((char *)v112 + v53)), (__m128)0i64),
                          _mm_mul_ps(v90, *(__m128 *)((char *)&v112[1] + v53))),
                        _mm_mul_ps(v91, *(__m128 *)((char *)v113 + v53))),
                      v94),
                    v67)),
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_mul_ps(v93, v71), (__m128)0i64),
                        _mm_mul_ps(v90, *(__m128 *)((char *)&v112[1] + v55))),
                      _mm_mul_ps(v91, *(__m128 *)((char *)v113 + v55))),
                    v94),
                  v68)),
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_mul_ps(v93, *(__m128 *)((char *)v112 + v56)), (__m128)0i64),
                      _mm_mul_ps(v90, *(__m128 *)((char *)&v112[1] + v56))),
                    _mm_mul_ps(v91, *(__m128 *)((char *)v113 + v56))),
                  v94),
                v105));
      v42 = v102;
      v6 = gVmxOne_0;
      v44 = (__m128)v106;
      *(__m128 *)((char *)v5 + v47) = _mm_shuffle_ps(v82, _mm_shuffle_ps(v82, (__m128)0i64, 250), 148);
      v12 = 0i64;
      v5 = (__m128 *)((char *)v5 + 24);
      v45 = v108;
      v46 = v110;
      v43 = _mm_load_si128(&v101);
      v96 = _mm_cvtps_epi32(_mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_add_ps(_mm_mul_ps(v92, v42), v42))));
      v97 = _mm_packs_epi32(v96, v96);
      v98 = _mm_or_ps(_mm_andnot_ps(gVmxOne_0, _mm_cmplt_ps(v103, (__m128)0i64)), v104);
      *(int *)((char *)&v5->m128_i32[-2] + v47) = _mm_packus_epi16(v97, v97).m128i_u32[0];
      v99 = _mm_cvtps_epi32(_mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v95, _mm_shuffle_ps(v95, v98, 250), 148), v42), v42))));
      v100 = _mm_packs_epi32(v99, v99);
      *(int *)((char *)&v5->m128_i32[-1] + v47) = _mm_packus_epi16(v100, v100).m128i_u32[0];
      --v48;
    }
    while ( v48 );
  }
}

// File Line: 18
// RVA: 0x1F580
void __fastcall Render::SkinMorphBufferTask(
        int worker_id,
        UFG::qMemoryStreamer *memory_streamer,
        _QWORD *param0,
        void *param1)
{
  __int64 v4; // rdi
  __m128 *v5; // rbp
  __m128 *v6; // r14
  _OWORD *v7; // r15
  __m128 v8; // xmm10
  __int64 v9; // rsi
  __int64 v10; // r11
  unsigned __int8 *v11; // r9
  __int64 v12; // rbx
  __m128 v13; // xmm15
  __m128 *v14; // rdx
  __int64 v15; // r10
  int v16; // r8d
  __int64 v17; // rcx
  __m128 *v18; // rax
  __m128 v19; // xmm5
  __m128 v20; // xmm11
  __m128 v21; // xmm12
  __m128 v22; // xmm13
  __m128 v23; // xmm4
  __m128 v24; // xmm3
  __m128 v25; // xmm8
  __m128 v26; // xmm5
  __m128 v27; // xmm1
  __m128 v28; // xmm6
  __m128 v29; // xmm7
  __m128 v30; // xmm0
  __m128 v31; // xmm8
  __m128 v32; // xmm6
  __m128 v33; // xmm10
  __m128 v34; // xmm5
  __m128 v35; // xmm4
  __m128 v36; // xmm10
  __m128 v37; // xmm5
  __m128 v38; // xmm4
  __m128 v39; // xmm4
  __m128 v40; // xmm5
  __m128 v41; // xmm10
  __m128 v42; // xmm14
  __m128 v43; // xmm1
  __m128 v44; // xmm9
  __m128 v45; // xmm12
  __m128 v46; // xmm4
  __m128 v47; // xmm7
  __m128 v48; // xmm13
  __m128 v49; // xmm11
  __m128 v50; // xmm3
  __int64 v51; // rdi
  __int64 v52; // r10
  __m128 v53; // xmm2
  __m128 v54; // xmm5
  __int64 v55; // rcx
  __int64 v56; // r8
  __m128i v57; // xmm1
  __m128 v58; // xmm6
  __int64 v59; // r9
  int v60; // eax
  __m128 v61; // xmm2
  __m128 v62; // xmm4
  __m128 v63; // xmm1
  __m128i v64; // xmm2
  __m128i v65; // xmm0
  __m128 v66; // xmm4
  __m128 v67; // xmm6
  __m128 v68; // xmm5
  __m128 v69; // xmm3
  __m128 v70; // xmm14
  __m128 v71; // xmm5
  __m128 v72; // xmm9
  __m128 v73; // xmm10
  __m128 v74; // xmm2
  __m128 v75; // xmm0
  __m128 v76; // xmm1
  __m128 v77; // xmm12
  __m128 v78; // xmm15
  __m128 v79; // xmm6
  __m128 v80; // xmm4
  __m128 v81; // xmm13
  __m128 v82; // xmm7
  __m128 v83; // xmm11
  __m128 v84; // xmm2
  __m128 v85; // xmm5
  __m128 v86; // xmm2
  __m128 v87; // xmm0
  __m128 v88; // xmm1
  __m128 v89; // xmm0
  __m128 v90; // xmm5
  __m128 v91; // xmm15
  __m128 v92; // xmm14
  __m128 v93; // xmm6
  __m128 v94; // xmm4
  __m128 v95; // xmm5
  __m128 v96; // xmm8
  __m128 v97; // xmm11
  __m128 v98; // xmm7
  __m128i v99; // xmm2
  __m128i v100; // xmm2
  __m128i v101; // xmm0
  __m128i v102; // xmm2
  __m128i v103; // xmm2
  __m128 v104; // [rsp+0h] [rbp-41B8h]
  __m128 v105; // [rsp+0h] [rbp-41B8h]
  __m128 v106; // [rsp+20h] [rbp-4198h]
  __m128 v107; // [rsp+30h] [rbp-4188h]
  __m128 v108; // [rsp+40h] [rbp-4178h]
  __m128i v109; // [rsp+50h] [rbp-4168h] BYREF
  __m128i v110; // [rsp+60h] [rbp-4158h]
  __m128 v111; // [rsp+70h] [rbp-4148h]
  __m128 v112; // [rsp+80h] [rbp-4138h]
  __m128 v113; // [rsp+90h] [rbp-4128h]
  __m128 v114; // [rsp+A0h] [rbp-4118h]
  __m128 v115; // [rsp+B0h] [rbp-4108h]
  __m128 v116; // [rsp+C0h] [rbp-40F8h]
  __m128 v117; // [rsp+D0h] [rbp-40E8h]
  __m128i v118; // [rsp+E0h] [rbp-40D8h]
  __m128 v119; // [rsp+F0h] [rbp-40C8h]
  __int128 v120[2]; // [rsp+100h] [rbp-40B8h]
  __int128 v121[1022]; // [rsp+120h] [rbp-4098h] BYREF

  v4 = *param0;
  v5 = (__m128 *)param0[1];
  v6 = (__m128 *)param0[2];
  v7 = (_OWORD *)param0[6];
  v104.m128_i32[0] = *((_DWORD *)param0 + 14);
  v8 = gVmxOne_0;
  v9 = *((unsigned int *)param0 + 16);
  v10 = param0[4];
  v11 = (unsigned __int8 *)param0[13];
  v12 = param0[12];
  v13 = 0i64;
  if ( *((_WORD *)param0 + 20) )
  {
    v14 = (__m128 *)v121;
    v15 = *((unsigned __int16 *)param0 + 20);
    do
    {
      v16 = *v11;
      if ( v16 == 255 )
      {
        v14[-2] = gVmxIdentity0_0;
        v14[-1] = gVmxIdentity1_0;
        *v14 = gVmxIdentity2_0;
        v14[1] = gVmxIdentity3_0;
      }
      else
      {
        v17 = (unsigned int)(48 * v16);
        v18 = (__m128 *)(v12 + (unsigned int)(v16 << 6));
        v19 = *(__m128 *)(v17 + v10 + 16);
        v20 = v18[1];
        v21 = v18[2];
        v22 = v18[3];
        v23 = _mm_shuffle_ps(v19, v19, 255);
        v24 = _mm_add_ps(v19, v19);
        v25 = _mm_shuffle_ps(v19, v19, 201);
        v26 = _mm_shuffle_ps(v19, v19, 210);
        v27 = _mm_shuffle_ps(v24, v24, 201);
        v28 = _mm_sub_ps(v8, _mm_mul_ps(v27, v25));
        v29 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v27, v23), (__m128)0i64), _mm_mul_ps(v26, v24));
        v30 = _mm_shuffle_ps(v24, v24, 210);
        v31 = _mm_sub_ps(_mm_add_ps(_mm_mul_ps(v25, v24), (__m128)0i64), _mm_mul_ps(v30, v23));
        v32 = _mm_sub_ps(v28, _mm_mul_ps(v30, v26));
        v33 = _mm_shuffle_ps(_mm_shuffle_ps(v29, v31, 80), v31, 233);
        v34 = _mm_shuffle_ps(_mm_shuffle_ps(v31, v32, 80), v32, 233);
        v35 = _mm_shuffle_ps(_mm_shuffle_ps(v32, v29, 80), v29, 233);
        v36 = _mm_shuffle_ps(v33, _mm_shuffle_ps(v32, v33, 250), 148);
        v37 = _mm_shuffle_ps(v34, _mm_shuffle_ps(v29, v34, 250), 148);
        v38 = _mm_shuffle_ps(v35, _mm_shuffle_ps(v31, v35, 250), 148);
        v39 = _mm_shuffle_ps(v38, _mm_shuffle_ps(v38, (__m128)0i64, 250), 148);
        v40 = _mm_shuffle_ps(v37, _mm_shuffle_ps(v37, (__m128)0i64, 250), 148);
        v41 = _mm_shuffle_ps(v36, _mm_shuffle_ps(v36, (__m128)0i64, 250), 148);
        v42 = _mm_shuffle_ps(*(__m128 *)(v17 + v10), _mm_shuffle_ps(*(__m128 *)(v17 + v10), gVmxOne_0, 250), 148);
        v14[-2] = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(*v18, *v18, 0), v39), (__m128)0i64),
                        _mm_mul_ps(_mm_shuffle_ps(*v18, *v18, 85), v40)),
                      _mm_mul_ps(_mm_shuffle_ps(*v18, *v18, 170), v41)),
                    _mm_mul_ps(_mm_shuffle_ps(*v18, *v18, 255), v42));
        v14[-1] = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v20, v20, 0), v39), (__m128)0i64),
                        _mm_mul_ps(_mm_shuffle_ps(v20, v20, 85), v40)),
                      _mm_mul_ps(_mm_shuffle_ps(v20, v20, 170), v41)),
                    _mm_mul_ps(_mm_shuffle_ps(v20, v20, 255), v42));
        *v14 = _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v21, v21, 0), v39), (__m128)0i64),
                     _mm_mul_ps(_mm_shuffle_ps(v21, v21, 85), v40)),
                   _mm_mul_ps(_mm_shuffle_ps(v21, v21, 170), v41)),
                 _mm_mul_ps(_mm_shuffle_ps(v21, v21, 255), v42));
        v43 = _mm_mul_ps(_mm_shuffle_ps(v22, v22, 170), v41);
        v8 = gVmxOne_0;
        v14[1] = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v22, v22, 0), v39), (__m128)0i64),
                       _mm_mul_ps(_mm_shuffle_ps(v22, v22, 85), v40)),
                     v43),
                   _mm_mul_ps(_mm_shuffle_ps(v22, v22, 255), v42));
      }
      v14 += 4;
      ++v11;
      --v15;
    }
    while ( v15 );
  }
  v44 = gVmx127;
  v45 = gVmxOneOver127;
  v46 = (__m128)gVmxi127;
  v47 = (__m128)gVmxUnpackMask;
  v48 = gVmxUnpackUnbias;
  v49 = gVmxUnpackShift;
  v115 = gVmxOneOver255;
  v119 = gVmx127;
  v114 = gVmxOneOver127;
  v113 = gVmxOneOver511;
  v118 = gVmxi127;
  v109 = gVmxUnpackBias;
  v110 = gVmxUnpackMask;
  v116 = gVmxUnpackUnbias;
  v112 = gVmxUnpackShift;
  if ( (_DWORD)v9 )
  {
    v50 = _mm_shuffle_ps(v104, v104, 0);
    v51 = v4 - (_QWORD)v5;
    v52 = v9;
    v117 = _mm_and_ps(gVmxMinusOne, v8);
    v108 = v50;
    do
    {
      v53 = *(__m128 *)v7;
      v54 = v5[1];
      v7 = (_OWORD *)((char *)v7 + 8);
      v55 = (unsigned __int8)v6->m128_i8[0] << 6;
      v56 = (unsigned __int8)v6->m128_i8[1] << 6;
      v57 = (__m128i)_mm_and_ps(_mm_shuffle_ps(v53, _mm_shuffle_ps(v53, v46, 0), 144), v47);
      v58 = *v6;
      v59 = (unsigned __int8)v6->m128_i8[2] << 6;
      v60 = (unsigned __int8)v6->m128_i8[3];
      v6 = (__m128 *)((char *)v6 + 8);
      v61 = _mm_shuffle_ps(v53, _mm_shuffle_ps(v53, v46, 85), 149);
      v62 = _mm_cvtepi32_ps(v57);
      v60 <<= 6;
      v63 = _mm_cvtepi32_ps((__m128i)_mm_and_ps(v61, v47));
      v64 = _mm_load_si128(&v109);
      v65 = (__m128i)_mm_shuffle_ps(v54, v54, 0);
      v66 = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(_mm_sub_ps(_mm_add_ps(_mm_mul_ps(v62, v49), v13), v44), v113), v13), v50);
      v67 = _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_cvtepi32_ps((__m128i)_mm_and_ps(
                                                 (__m128)_mm_sub_epi32((__m128i)_mm_shuffle_ps(v58, v58, 85), v64),
                                                 v47)),
                      v48),
                    v49),
                  v13),
                v115),
              v13);
      v68 = _mm_add_ps(
              _mm_mul_ps(
                _mm_sub_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_cvtepi32_ps((__m128i)_mm_and_ps(
                                                   (__m128)_mm_sub_epi32((__m128i)_mm_shuffle_ps(v54, v54, 85), v64),
                                                   v47)),
                        v48),
                      v49),
                    v13),
                  v44),
                v45),
              v13);
      v107 = _mm_shuffle_ps(v68, v68, 255);
      v69 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_sub_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_add_ps(_mm_cvtepi32_ps((__m128i)_mm_and_ps((__m128)_mm_sub_epi32(v65, v64), v47)), v48),
                        v49),
                      v13),
                    v44),
                  v45),
                v13),
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(_mm_mul_ps(_mm_sub_ps(_mm_add_ps(_mm_mul_ps(v63, v49), v13), v44), v45), v13),
                  v50),
                v13));
      v70 = _mm_add_ps(_mm_shuffle_ps(*v5, _mm_shuffle_ps(*v5, v8, 250), 148), _mm_add_ps(v66, v13));
      v71 = _mm_shuffle_ps(v68, _mm_shuffle_ps(v68, v13, 250), 148);
      v72 = _mm_shuffle_ps(v67, v67, 0);
      v73 = _mm_shuffle_ps(v67, v67, 85);
      v74 = _mm_shuffle_ps(v69, v69, 0);
      v75 = _mm_shuffle_ps(v69, v69, 85);
      v76 = _mm_shuffle_ps(v69, v69, 170);
      v77 = _mm_shuffle_ps(v67, v67, 170);
      v105 = _mm_shuffle_ps(v67, v67, 255);
      v78 = _mm_add_ps(
              _mm_mul_ps(
                _mm_rsqrt_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_add_ps(_mm_mul_ps(v74, v74), v13), _mm_mul_ps(v75, v75)),
                    _mm_mul_ps(v76, v76))),
                v69),
              (__m128)0i64);
      v79 = _mm_shuffle_ps(v70, v70, 0);
      v80 = _mm_shuffle_ps(v70, v70, 85);
      v81 = _mm_shuffle_ps(v78, v78, 0);
      v82 = _mm_shuffle_ps(v78, v78, 85);
      v83 = _mm_shuffle_ps(v78, v78, 170);
      v84 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v71, v71, 0), v81), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps(v71, v71, 85), v82)),
              _mm_mul_ps(_mm_shuffle_ps(v71, v71, 170), v83));
      v85 = _mm_sub_ps(
              v71,
              _mm_sub_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v84, v84, 201), _mm_shuffle_ps(v78, v78, 210)), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps(v84, v84, 210), _mm_shuffle_ps(v78, v78, 201))));
      v86 = _mm_shuffle_ps(v85, v85, 0);
      v87 = _mm_shuffle_ps(v85, v85, 85);
      v88 = _mm_shuffle_ps(v85, v85, 170);
      v89 = _mm_mul_ps(
              _mm_rsqrt_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_add_ps(_mm_mul_ps(v86, v86), (__m128)0i64), _mm_mul_ps(v87, v87)),
                  _mm_mul_ps(v88, v88))),
              v85);
      v90 = _mm_shuffle_ps(v70, v70, 170);
      v111 = _mm_add_ps(v89, (__m128)0i64);
      v106 = _mm_shuffle_ps(v70, v70, 255);
      v91 = _mm_mul_ps(_mm_shuffle_ps(v78, v78, 255), (__m128)0i64);
      v92 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(
                            _mm_add_ps(_mm_mul_ps(v79, *(__m128 *)((char *)v120 + v55)), (__m128)0i64),
                            _mm_mul_ps(v80, *(__m128 *)((char *)&v120[1] + v55))),
                          _mm_mul_ps(v90, *(__m128 *)((char *)v121 + v55))),
                        _mm_mul_ps(v106, *(__m128 *)((char *)&v121[1] + v55))),
                      v72),
                    (__m128)0i64),
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(_mm_mul_ps(v79, *(__m128 *)((char *)v120 + v56)), (__m128)0i64),
                          _mm_mul_ps(v80, *(__m128 *)((char *)&v120[1] + v56))),
                        _mm_mul_ps(v90, *(__m128 *)((char *)v121 + v56))),
                      _mm_mul_ps(v106, *(__m128 *)((char *)&v121[1] + v56))),
                    v73)),
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_mul_ps(v79, *(__m128 *)((char *)v120 + v59)), (__m128)0i64),
                        _mm_mul_ps(v80, *(__m128 *)((char *)&v120[1] + v59))),
                      _mm_mul_ps(v90, *(__m128 *)((char *)v121 + v59))),
                    _mm_mul_ps(v106, *(__m128 *)((char *)&v121[1] + v59))),
                  v77)),
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_mul_ps(v79, *(__m128 *)((char *)v120 + v60)), (__m128)0i64),
                      _mm_mul_ps(v80, *(__m128 *)((char *)&v120[1] + v60))),
                    _mm_mul_ps(v90, *(__m128 *)((char *)v121 + v60))),
                  _mm_mul_ps(v106, *(__m128 *)((char *)&v121[1] + v60))),
                v105));
      v93 = _mm_shuffle_ps(v111, v111, 0);
      v94 = _mm_shuffle_ps(v111, v111, 85);
      v95 = _mm_shuffle_ps(v111, v111, 170);
      v96 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(
                            _mm_add_ps(_mm_mul_ps(v81, *(__m128 *)((char *)v120 + v55)), (__m128)0i64),
                            _mm_mul_ps(v82, *(__m128 *)((char *)&v120[1] + v55))),
                          _mm_mul_ps(v83, *(__m128 *)((char *)v121 + v55))),
                        v91),
                      v72),
                    (__m128)0i64),
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(_mm_mul_ps(v81, *(__m128 *)((char *)v120 + v56)), (__m128)0i64),
                          _mm_mul_ps(v82, *(__m128 *)((char *)&v120[1] + v56))),
                        _mm_mul_ps(v83, *(__m128 *)((char *)v121 + v56))),
                      v91),
                    v73)),
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_mul_ps(v81, *(__m128 *)((char *)v120 + v59)), (__m128)0i64),
                        _mm_mul_ps(v82, *(__m128 *)((char *)&v120[1] + v59))),
                      _mm_mul_ps(v83, *(__m128 *)((char *)v121 + v59))),
                    v91),
                  v77)),
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_mul_ps(v81, *(__m128 *)((char *)v120 + v60)), (__m128)0i64),
                      _mm_mul_ps(v82, *(__m128 *)((char *)&v120[1] + v60))),
                    _mm_mul_ps(v83, *(__m128 *)((char *)v121 + v60))),
                  v91),
                v105));
      v13 = 0i64;
      v97 = _mm_mul_ps(_mm_shuffle_ps(v111, v111, 255), (__m128)0i64);
      v98 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(
                            _mm_add_ps(_mm_mul_ps(v93, *(__m128 *)((char *)v120 + v55)), (__m128)0i64),
                            _mm_mul_ps(v94, *(__m128 *)((char *)&v120[1] + v55))),
                          _mm_mul_ps(v95, *(__m128 *)((char *)v121 + v55))),
                        v97),
                      v72),
                    (__m128)0i64),
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(_mm_mul_ps(v93, *(__m128 *)((char *)v120 + v56)), (__m128)0i64),
                          _mm_mul_ps(v94, *(__m128 *)((char *)&v120[1] + v56))),
                        _mm_mul_ps(v95, *(__m128 *)((char *)v121 + v56))),
                      v97),
                    v73)),
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_mul_ps(v93, *(__m128 *)((char *)v120 + v59)), (__m128)0i64),
                        _mm_mul_ps(v94, *(__m128 *)((char *)&v120[1] + v59))),
                      _mm_mul_ps(v95, *(__m128 *)((char *)v121 + v59))),
                    v97),
                  v77)),
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_mul_ps(v93, *(__m128 *)((char *)v120 + v60)), (__m128)0i64),
                      _mm_mul_ps(v94, *(__m128 *)((char *)&v120[1] + v60))),
                    _mm_mul_ps(v95, *(__m128 *)((char *)v121 + v60))),
                  v97),
                v105));
      v44 = v119;
      v8 = gVmxOne_0;
      v50 = v108;
      *(__m128 *)((char *)v5 + v51) = _mm_shuffle_ps(v92, _mm_shuffle_ps(v92, (__m128)0i64, 250), 148);
      v5 = (__m128 *)((char *)v5 + 24);
      v49 = v112;
      v45 = v114;
      v48 = v116;
      v46 = (__m128)v118;
      v99 = _mm_cvtps_epi32(_mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_add_ps(_mm_mul_ps(v96, v44), v44))));
      v100 = _mm_packs_epi32(v99, v99);
      *(int *)((char *)&v5->m128_i32[-2] + v51) = _mm_packus_epi16(v100, v100).m128i_u32[0];
      v101 = _mm_cvtps_epi32(
               _mm_add_ps(
                 _mm_mul_ps(
                   _mm_shuffle_ps(
                     v98,
                     _mm_shuffle_ps(
                       v98,
                       _mm_or_ps(_mm_andnot_ps(gVmxOne_0, _mm_cmplt_ps(v107, (__m128)0i64)), v117),
                       250),
                     148),
                   v44),
                 v44));
      v47 = (__m128)v110;
      v102 = _mm_cvtps_epi32(_mm_cvtepi32_ps(v101));
      v103 = _mm_packs_epi32(v102, v102);
      *(int *)((char *)&v5->m128_i32[-1] + v51) = _mm_packus_epi16(v103, v103).m128i_u32[0];
      --v52;
    }
    while ( v52 );
  }
}

// File Line: 23
// RVA: 0x20000
void __fastcall Render::SkinCacheBufferTask(
        int worker_id,
        UFG::qMemoryStreamer *memory_streamer,
        _QWORD *param0,
        void *param1)
{
  __int64 v4; // rsi
  __int64 v5; // rbp
  __m128 v6; // xmm6
  _OWORD *v7; // r15
  __int64 v8; // r11
  __int64 v9; // r14
  unsigned __int8 *v10; // r9
  __int64 v11; // rbx
  __m128 v12; // xmm15
  __int64 v13; // rdi
  __m128 *v14; // rdx
  __int64 v15; // r10
  int v16; // r8d
  __int64 v17; // rcx
  __m128 *v18; // rax
  __m128 v19; // xmm5
  __m128 v20; // xmm11
  __m128 v21; // xmm12
  __m128 v22; // xmm13
  __m128 v23; // xmm4
  __m128 v24; // xmm3
  __m128 v25; // xmm8
  __m128 v26; // xmm5
  __m128 v27; // xmm1
  __m128 v28; // xmm6
  __m128 v29; // xmm7
  __m128 v30; // xmm0
  __m128 v31; // xmm8
  __m128 v32; // xmm6
  __m128 v33; // xmm10
  __m128 v34; // xmm5
  __m128 v35; // xmm4
  __m128 v36; // xmm10
  __m128 v37; // xmm5
  __m128 v38; // xmm4
  __m128 v39; // xmm4
  __m128 v40; // xmm5
  __m128 v41; // xmm10
  __m128 v42; // xmm14
  __m128 v43; // xmm5
  __m128i v44; // xmm4
  __m128 v45; // xmm10
  __m128 v46; // xmm12
  __m128 v47; // xmm14
  __int64 v48; // rbp
  __int64 v49; // r10
  __int64 v50; // rsi
  __int64 v51; // r11
  __m128 v52; // xmm1
  __m128 v53; // xmm2
  unsigned __int8 *v54; // rcx
  __int64 v55; // rdx
  __int64 v56; // r8
  __m128 v57; // xmm11
  __int64 v58; // r9
  int v59; // eax
  __m128i v60; // xmm0
  __m128 v61; // xmm4
  __m128 v62; // xmm6
  __m128 v63; // xmm1
  __m128 v64; // xmm4
  __m128 v65; // xmm13
  __m128 v66; // xmm5
  __m128 v67; // xmm4
  __m128 v68; // xmm13
  __m128 v69; // xmm10
  __m128 v70; // xmm12
  __m128 v71; // xmm14
  __m128 v72; // xmm4
  __m128 v73; // xmm11
  __m128 v74; // xmm7
  __m128 v75; // xmm1
  __m128 v76; // xmm15
  __m128 v77; // xmm3
  __m128 v78; // xmm6
  __m128 v79; // xmm4
  __m128 v80; // xmm6
  __m128 v81; // xmm5
  __m128 v82; // xmm3
  __m128 v83; // xmm6
  __m128 v84; // xmm11
  __m128 v85; // xmm15
  __m128 v86; // xmm6
  __m128 v87; // xmm13
  __m128 v88; // xmm8
  __m128 v89; // xmm2
  __m128 v90; // xmm3
  __m128 v91; // xmm6
  __m128 v92; // xmm3
  __m128 v93; // xmm4
  __m128 v94; // xmm5
  __m128 v95; // xmm8
  __m128 v96; // xmm6
  __m128 v97; // xmm13
  __m128 v98; // xmm15
  __m128 v99; // xmm7
  __m128i v100; // xmm2
  __m128i v101; // xmm2
  __m128 v102; // xmm1
  __m128i v103; // xmm2
  __m128i v104; // xmm2
  __m128i v105; // [rsp+10h] [rbp-4168h] BYREF
  __m128 v106; // [rsp+20h] [rbp-4158h]
  __m128 v107; // [rsp+30h] [rbp-4148h]
  __m128 v108; // [rsp+40h] [rbp-4138h]
  __m128 v109; // [rsp+50h] [rbp-4128h]
  __m128i v110; // [rsp+60h] [rbp-4118h]
  __m128 v111; // [rsp+70h] [rbp-4108h]
  __m128 v112; // [rsp+80h] [rbp-40F8h]
  __m128 v113; // [rsp+90h] [rbp-40E8h]
  __m128 v114; // [rsp+A0h] [rbp-40D8h]
  __m128 v115; // [rsp+B0h] [rbp-40C8h]
  __int128 v116[2]; // [rsp+C0h] [rbp-40B8h]
  __int128 v117[1022]; // [rsp+E0h] [rbp-4098h] BYREF

  v4 = *param0;
  v5 = param0[1];
  v6 = gVmxOne_0;
  v7 = (_OWORD *)param0[2];
  v8 = param0[18];
  v9 = *((unsigned int *)param0 + 16);
  v10 = (unsigned __int8 *)param0[13];
  v11 = param0[4];
  v12 = 0i64;
  v13 = param0[12];
  if ( *((_WORD *)param0 + 20) )
  {
    v14 = (__m128 *)v117;
    v15 = *((unsigned __int16 *)param0 + 20);
    do
    {
      v16 = *v10;
      if ( v16 == 255 )
      {
        v14[-2] = gVmxIdentity0_0;
        v14[-1] = gVmxIdentity1_0;
        *v14 = gVmxIdentity2_0;
        v14[1] = gVmxIdentity3_0;
      }
      else
      {
        v17 = (unsigned int)(48 * v16);
        v18 = (__m128 *)(v13 + (unsigned int)(v16 << 6));
        v19 = *(__m128 *)(v17 + v11 + 16);
        v20 = v18[1];
        v21 = v18[2];
        v22 = v18[3];
        v23 = _mm_shuffle_ps(v19, v19, 255);
        v24 = _mm_add_ps(v19, v19);
        v25 = _mm_shuffle_ps(v19, v19, 201);
        v26 = _mm_shuffle_ps(v19, v19, 210);
        v27 = _mm_shuffle_ps(v24, v24, 201);
        v28 = _mm_sub_ps(v6, _mm_mul_ps(v27, v25));
        v29 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v27, v23), (__m128)0i64), _mm_mul_ps(v26, v24));
        v30 = _mm_shuffle_ps(v24, v24, 210);
        v31 = _mm_sub_ps(_mm_add_ps(_mm_mul_ps(v25, v24), (__m128)0i64), _mm_mul_ps(v30, v23));
        v32 = _mm_sub_ps(v28, _mm_mul_ps(v30, v26));
        v33 = _mm_shuffle_ps(_mm_shuffle_ps(v29, v31, 80), v31, 233);
        v34 = _mm_shuffle_ps(_mm_shuffle_ps(v31, v32, 80), v32, 233);
        v35 = _mm_shuffle_ps(_mm_shuffle_ps(v32, v29, 80), v29, 233);
        v36 = _mm_shuffle_ps(v33, _mm_shuffle_ps(v32, v33, 250), 148);
        v6 = gVmxOne_0;
        v37 = _mm_shuffle_ps(v34, _mm_shuffle_ps(v29, v34, 250), 148);
        v38 = _mm_shuffle_ps(v35, _mm_shuffle_ps(v31, v35, 250), 148);
        v39 = _mm_shuffle_ps(v38, _mm_shuffle_ps(v38, (__m128)0i64, 250), 148);
        v40 = _mm_shuffle_ps(v37, _mm_shuffle_ps(v37, (__m128)0i64, 250), 148);
        v41 = _mm_shuffle_ps(v36, _mm_shuffle_ps(v36, (__m128)0i64, 250), 148);
        v42 = _mm_shuffle_ps(*(__m128 *)(v17 + v11), _mm_shuffle_ps(*(__m128 *)(v17 + v11), gVmxOne_0, 250), 148);
        v14[-2] = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(*v18, *v18, 0), v39), (__m128)0i64),
                        _mm_mul_ps(_mm_shuffle_ps(*v18, *v18, 85), v40)),
                      _mm_mul_ps(_mm_shuffle_ps(*v18, *v18, 170), v41)),
                    _mm_mul_ps(_mm_shuffle_ps(*v18, *v18, 255), v42));
        v14[-1] = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v20, v20, 0), v39), (__m128)0i64),
                        _mm_mul_ps(_mm_shuffle_ps(v20, v20, 85), v40)),
                      _mm_mul_ps(_mm_shuffle_ps(v20, v20, 170), v41)),
                    _mm_mul_ps(_mm_shuffle_ps(v20, v20, 255), v42));
        *v14 = _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v21, v21, 0), v39), (__m128)0i64),
                     _mm_mul_ps(_mm_shuffle_ps(v21, v21, 85), v40)),
                   _mm_mul_ps(_mm_shuffle_ps(v21, v21, 170), v41)),
                 _mm_mul_ps(_mm_shuffle_ps(v21, v21, 255), v42));
        v14[1] = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v22, v22, 0), v39), (__m128)0i64),
                       _mm_mul_ps(_mm_shuffle_ps(v22, v22, 85), v40)),
                     _mm_mul_ps(_mm_shuffle_ps(v22, v22, 170), v41)),
                   _mm_mul_ps(_mm_shuffle_ps(v22, v22, 255), v42));
      }
      v14 += 4;
      ++v10;
      --v15;
    }
    while ( v15 );
  }
  v43 = gVmx127;
  v44 = gVmxUnpackBias;
  v45 = (__m128)gVmxUnpackMask;
  v46 = gVmxUnpackUnbias;
  v47 = gVmxUnpackShift;
  v111 = gVmxOneOver127;
  v115 = gVmxOneOver255;
  v106 = gVmx127;
  v105 = gVmxUnpackBias;
  v110 = gVmxUnpackMask;
  v112 = gVmxUnpackUnbias;
  v114 = gVmxUnpackShift;
  if ( (_DWORD)v9 )
  {
    v48 = v5 - v8;
    v49 = v8 + 16;
    v50 = v4 - v8;
    v51 = v9;
    v108 = _mm_and_ps(gVmxMinusOne, v6);
    do
    {
      v52 = *(__m128 *)(v49 + v48);
      v53 = *(__m128 *)v7;
      v54 = (unsigned __int8 *)v7;
      v7 = (_OWORD *)((char *)v7 + 8);
      v55 = *v54 << 6;
      v56 = v54[1] << 6;
      v57 = _mm_shuffle_ps(*(__m128 *)(v49 + v48 - 16), _mm_shuffle_ps(*(__m128 *)(v49 + v48 - 16), v6, 250), 148);
      v58 = v54[2] << 6;
      v59 = v54[3] << 6;
      v60 = (__m128i)_mm_and_ps((__m128)_mm_sub_epi32((__m128i)_mm_shuffle_ps(v52, v52, 0), v44), v45);
      v61 = _mm_cvtepi32_ps((__m128i)_mm_and_ps((__m128)_mm_sub_epi32((__m128i)_mm_shuffle_ps(v52, v52, 85), v44), v45));
      v62 = _mm_shuffle_ps(v57, v57, 0);
      v63 = _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_cvtepi32_ps((__m128i)_mm_and_ps(
                                                 (__m128)_mm_sub_epi32((__m128i)_mm_shuffle_ps(v53, v53, 85), v105),
                                                 v45)),
                      v46),
                    v47),
                  v12),
                v115),
              v12);
      v64 = _mm_sub_ps(_mm_add_ps(_mm_mul_ps(_mm_add_ps(v61, v46), v47), v12), v43);
      v65 = _mm_sub_ps(_mm_add_ps(_mm_mul_ps(_mm_add_ps(_mm_cvtepi32_ps(v60), v46), v47), v12), v43);
      v66 = _mm_shuffle_ps(v57, v57, 170);
      v67 = _mm_add_ps(_mm_mul_ps(v64, v111), v12);
      v68 = _mm_add_ps(_mm_mul_ps(v65, v111), v12);
      v69 = _mm_shuffle_ps(v63, v63, 0);
      v70 = _mm_shuffle_ps(v63, v63, 85);
      v71 = _mm_shuffle_ps(v63, v63, 170);
      v107 = _mm_shuffle_ps(v67, v67, 255);
      v109 = _mm_shuffle_ps(v63, v63, 255);
      v113 = _mm_shuffle_ps(v67, _mm_shuffle_ps(v67, v12, 250), 148);
      v72 = _mm_shuffle_ps(v57, v57, 85);
      v73 = _mm_shuffle_ps(v57, v57, 255);
      v74 = *(__m128 *)((char *)v116 + v58);
      v75 = _mm_mul_ps(v66, *(__m128 *)((char *)v117 + v58));
      v76 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_mul_ps(v62, *(__m128 *)((char *)v116 + v55)), (__m128)0i64),
                        _mm_mul_ps(v72, *(__m128 *)((char *)&v116[1] + v55))),
                      _mm_mul_ps(v66, *(__m128 *)((char *)v117 + v55))),
                    _mm_mul_ps(v73, *(__m128 *)((char *)&v117[1] + v55))),
                  v69),
                (__m128)0i64),
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_mul_ps(v62, *(__m128 *)((char *)v116 + v56)), (__m128)0i64),
                      _mm_mul_ps(v72, *(__m128 *)((char *)&v116[1] + v56))),
                    _mm_mul_ps(v66, *(__m128 *)((char *)v117 + v56))),
                  _mm_mul_ps(v73, *(__m128 *)((char *)&v117[1] + v56))),
                v70));
      v77 = _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(v62, v74), (__m128)0i64),
              _mm_mul_ps(v72, *(__m128 *)((char *)&v116[1] + v58)));
      v78 = _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(v62, *(__m128 *)((char *)v116 + v59)), (__m128)0i64),
              _mm_mul_ps(v72, *(__m128 *)((char *)&v116[1] + v59)));
      v79 = _mm_shuffle_ps(v68, v68, 85);
      v80 = _mm_add_ps(v78, _mm_mul_ps(v66, *(__m128 *)((char *)v117 + v59)));
      v81 = _mm_shuffle_ps(v68, v68, 170);
      v82 = _mm_add_ps(_mm_add_ps(v77, v75), _mm_mul_ps(v73, *(__m128 *)((char *)&v117[1] + v58)));
      v83 = _mm_add_ps(v80, _mm_mul_ps(v73, *(__m128 *)((char *)&v117[1] + v59)));
      v84 = *(__m128 *)((char *)v116 + v55);
      v85 = _mm_add_ps(_mm_add_ps(v76, _mm_mul_ps(v82, v71)), _mm_mul_ps(v83, v109));
      v86 = _mm_shuffle_ps(v68, v68, 0);
      v87 = _mm_mul_ps(_mm_shuffle_ps(v68, v68, 255), (__m128)0i64);
      v88 = _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_mul_ps(v86, v84), (__m128)0i64),
                      _mm_mul_ps(v79, *(__m128 *)((char *)&v116[1] + v55))),
                    _mm_mul_ps(v81, *(__m128 *)((char *)v117 + v55))),
                  v87),
                v69),
              (__m128)0i64);
      v89 = _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_mul_ps(v86, *(__m128 *)((char *)v116 + v56)), (__m128)0i64),
                    _mm_mul_ps(v79, *(__m128 *)((char *)&v116[1] + v56))),
                  _mm_mul_ps(v81, *(__m128 *)((char *)v117 + v56))),
                v87),
              v70);
      v90 = v86;
      v91 = _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_mul_ps(v86, *(__m128 *)((char *)v116 + v59)), (__m128)0i64),
                    _mm_mul_ps(v79, *(__m128 *)((char *)&v116[1] + v59))),
                  _mm_mul_ps(v81, *(__m128 *)((char *)v117 + v59))),
                v87),
              v109);
      v92 = _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_mul_ps(v90, v74), (__m128)0i64),
                    _mm_mul_ps(v79, *(__m128 *)((char *)&v116[1] + v58))),
                  _mm_mul_ps(v81, *(__m128 *)((char *)v117 + v58))),
                v87),
              v71);
      v93 = _mm_shuffle_ps(v113, v113, 85);
      v94 = _mm_shuffle_ps(v113, v113, 170);
      v95 = _mm_add_ps(_mm_add_ps(_mm_add_ps(v88, v89), v92), v91);
      v96 = _mm_shuffle_ps(v113, v113, 0);
      v97 = _mm_mul_ps(_mm_shuffle_ps(v113, v113, 255), (__m128)0i64);
      v98 = _mm_shuffle_ps(v85, _mm_shuffle_ps(v85, (__m128)0i64, 250), 148);
      v99 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(
                            _mm_add_ps(_mm_mul_ps(v96, v84), (__m128)0i64),
                            _mm_mul_ps(v93, *(__m128 *)((char *)&v116[1] + v55))),
                          _mm_mul_ps(v94, *(__m128 *)((char *)v117 + v55))),
                        v97),
                      v69),
                    (__m128)0i64),
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(_mm_mul_ps(v96, *(__m128 *)((char *)v116 + v56)), (__m128)0i64),
                          _mm_mul_ps(v93, *(__m128 *)((char *)&v116[1] + v56))),
                        _mm_mul_ps(v94, *(__m128 *)((char *)v117 + v56))),
                      v97),
                    v70)),
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_mul_ps(v96, v74), (__m128)0i64),
                        _mm_mul_ps(v93, *(__m128 *)((char *)&v116[1] + v58))),
                      _mm_mul_ps(v94, *(__m128 *)((char *)v117 + v58))),
                    v97),
                  v71)),
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_mul_ps(v96, *(__m128 *)((char *)v116 + v59)), (__m128)0i64),
                      _mm_mul_ps(v93, *(__m128 *)((char *)&v116[1] + v59))),
                    _mm_mul_ps(v94, *(__m128 *)((char *)v117 + v59))),
                  v97),
                v109));
      v43 = v106;
      v6 = gVmxOne_0;
      v45 = (__m128)v110;
      *(__m128 *)(v50 + v49 - 16) = v98;
      *(__m128 *)(v49 - 16) = v98;
      v12 = 0i64;
      v49 += 24i64;
      v46 = v112;
      v47 = v114;
      v44 = _mm_load_si128(&v105);
      v100 = _mm_cvtps_epi32(_mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_add_ps(_mm_mul_ps(v95, v43), v43))));
      v101 = _mm_packs_epi32(v100, v100);
      v101.m128i_i32[0] = _mm_packus_epi16(v101, v101).m128i_u32[0];
      v102 = _mm_or_ps(_mm_andnot_ps(gVmxOne_0, _mm_cmplt_ps(v107, (__m128)0i64)), v108);
      *(_DWORD *)(v50 + v49 - 24) = v101.m128i_i32[0];
      *(_DWORD *)(v49 - 24) = v101.m128i_i32[0];
      v103 = _mm_cvtps_epi32(_mm_cvtepi32_ps(_mm_cvtps_epi32(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v99, _mm_shuffle_ps(v99, v102, 250), 148), v43), v43))));
      v104 = _mm_packs_epi32(v103, v103);
      v104.m128i_i32[0] = _mm_packus_epi16(v104, v104).m128i_u32[0];
      *(_DWORD *)(v50 + v49 - 20) = v104.m128i_i32[0];
      *(_DWORD *)(v49 - 20) = v104.m128i_i32[0];
      --v51;
    }
    while ( v51 );
  }
}_DWORD *)(v49 - 20) = v104.m128i_i32[0];
      --v51;
    }
    while ( v51 );
  }
}

