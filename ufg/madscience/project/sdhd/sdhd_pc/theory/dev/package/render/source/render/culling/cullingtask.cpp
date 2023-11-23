// File Line: 66
// RVA: 0x14576D0
__int64 Render::_dynamic_initializer_for__gTaskFunctionDecl_CullManager_RasterizeZBuffer__()
{
  UFG::qTaskFunctionDecl::qTaskFunctionDecl(
    &Render::gTaskFunctionDecl_CullManager_RasterizeZBuffer,
    &Render::gTaskFunctionDeclData_CullManager_RasterizeZBuffer);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gTaskFunctionDecl_CullManager_RasterizeZBuffer__);
}

// File Line: 67
// RVA: 0x1457670
__int64 Render::_dynamic_initializer_for__gTaskFunctionDecl_CullManager_CreateOcclusionMap__()
{
  UFG::qTaskFunctionDecl::qTaskFunctionDecl(
    &Render::gTaskFunctionDecl_CullManager_CreateOcclusionMap,
    &Render::gTaskFunctionDeclData_CullManager_CreateOcclusionMap);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gTaskFunctionDecl_CullManager_CreateOcclusionMap__);
}

// File Line: 68
// RVA: 0x14576A0
__int64 Render::_dynamic_initializer_for__gTaskFunctionDecl_CullManager_CullBucketTask__()
{
  UFG::qTaskFunctionDecl::qTaskFunctionDecl(
    &Render::gTaskFunctionDecl_CullManager_CullBucketTask,
    &Render::gTaskFunctionDeclData_CullManager_CullBucketTask);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gTaskFunctionDecl_CullManager_CullBucketTask__);
}

// File Line: 108
// RVA: 0x7F990
void __fastcall Render::CullManager_RasterizeZBuffer(
        int worker_id,
        UFG::qMemoryStreamer *memory_streamer,
        _DWORD *main_mem_view_params,
        void *main_mem_cull_layer_head)
{
  unsigned int v4; // esi
  __int64 v8; // rbx
  volatile int *v9; // r15
  int v10; // eax
  void *v11; // r9
  int v12; // edi
  int v13; // edx
  __int64 *v14; // r8
  __int64 v15; // rax
  void *v16; // rax
  __int64 v17; // rcx
  int v18; // r11d
  __int64 v19; // r8
  __int64 v20; // rcx
  __int64 v21; // r10
  __int64 v22; // r9
  __int64 v23; // rax
  __int64 v24; // r10
  __int64 v25; // rcx
  int v26; // r14d
  __int64 v27; // rdi
  __int64 v28; // r15
  unsigned __int64 v29; // r15
  unsigned int v30; // esi
  __int64 v31; // rax
  __int64 v32; // rbx
  __int64 v33; // rcx
  __int64 v34; // rax
  __int64 v35; // r13
  __int64 v36; // rax
  __int64 v37; // r12
  UFG::qMatrix44 *LocalWorld; // rax
  __int64 v39; // r14
  float w; // xmm15_4
  float v41; // xmm7_4
  float v42; // xmm6_4
  float v43; // xmm8_4
  __int64 v44; // rcx
  float v45; // xmm10_4
  float v46; // xmm11_4
  float v47; // xmm9_4
  __int64 v48; // rcx
  float v49; // xmm13_4
  float v50; // xmm14_4
  float v51; // xmm12_4
  float v52; // xmm1_4
  float v53; // xmm4_4
  float v54; // xmm0_4
  float v55; // xmm2_4
  float v56; // xmm5_4
  int v57; // eax
  UFG::qMatrix44 result; // [rsp+20h] [rbp-A0h] BYREF
  UFG::qVector4 v1; // [rsp+60h] [rbp-60h] BYREF
  UFG::qVector4 v0; // [rsp+70h] [rbp-50h] BYREF
  __int64 v61; // [rsp+80h] [rbp-40h]
  int v62; // [rsp+88h] [rbp-38h]
  __int64 v63[2]; // [rsp+90h] [rbp-30h] BYREF
  int v64; // [rsp+A0h] [rbp-20h]
  void *v65; // [rsp+A8h] [rbp-18h]
  __int64 *p_z; // [rsp+B0h] [rbp-10h]
  __int64 *v67; // [rsp+B8h] [rbp-8h]
  UFG::qMemoryStreamer *v68; // [rsp+C0h] [rbp+0h]
  __int64 v69[2]; // [rsp+C8h] [rbp+8h] BYREF
  int v70; // [rsp+D8h] [rbp+18h]
  __int64 v71[2]; // [rsp+E0h] [rbp+20h] BYREF
  int v72; // [rsp+F0h] [rbp+30h]
  __int64 v73; // [rsp+F8h] [rbp+38h]
  __int64 *v74; // [rsp+100h] [rbp+40h]
  __int64 *v75; // [rsp+108h] [rbp+48h]
  volatile int *v; // [rsp+110h] [rbp+50h]
  __int64 v77; // [rsp+118h] [rbp+58h]
  Render::RasterizeZ v78; // [rsp+120h] [rbp+60h] BYREF
  bool v79; // [rsp+250h] [rbp+190h]
  int v80; // [rsp+258h] [rbp+198h]
  int v81; // [rsp+260h] [rbp+1A0h]
  __int64 v82; // [rsp+268h] [rbp+1A8h]
  void *v83; // [rsp+270h] [rbp+1B0h]

  v4 = main_mem_view_params[26];
  v8 = 0i64;
  Render::RasterizeZ::Init(&v78, *(unsigned int **)&main_mem_view_params[2 * worker_id + 16], 0);
  if ( *v78.mZBufferTag != v4 )
  {
    Render::RasterizeZ::Clear(&v78);
    *v78.mZBufferTag = v4;
  }
  UFG::CoverObjectBase::SetCoverObjectGroup((hkDynamicClassNameRegistry *)&v78, (const char *)main_mem_view_params);
  *(_QWORD *)&v0.x = memory_streamer;
  *(_QWORD *)&v0.z = "cull_layer_iterator";
  v63[0] = (__int64)"cull_layer_iterator";
  p_z = (__int64 *)&v0.z;
  v68 = memory_streamer;
  v9 = (volatile int *)*((_QWORD *)main_mem_view_params + 14);
  v67 = v63;
  v69[0] = (__int64)"cull_bucket_iterator";
  v71[0] = (__int64)"cull_bucket_iterator";
  v74 = v69;
  v61 = 0i64;
  v62 = 0;
  v75 = v71;
  v63[1] = 0i64;
  v64 = 0;
  v65 = 0i64;
  v69[1] = 0i64;
  v70 = 0;
  v71[1] = 0i64;
  v72 = 0;
  v73 = 0i64;
  v = v9;
  v10 = UFG::qAtomicAdd(v9, 1);
  v11 = v83;
  v12 = 0;
  v13 = v10;
  v80 = 0;
  if ( main_mem_cull_layer_head == v83 )
  {
    p_z[1] = 0i64;
    v67[1] = 0i64;
  }
  else
  {
    v67[1] = (__int64)main_mem_cull_layer_head;
  }
  v65 = v11;
LABEL_7:
  v14 = p_z;
  p_z = v67;
  v67 = v14;
  v15 = p_z[1];
  if ( v15 )
  {
    v16 = *(void **)(v15 + 8);
    v17 = 0i64;
    if ( v16 != v11 )
      v17 = (__int64)v16;
    v18 = 0;
    v14[1] = v17;
    v19 = (__int64)v75;
    v20 = (__int64)v74;
    LODWORD(v83) = 0;
    while ( 1 )
    {
      v21 = p_z[1];
      v22 = v21 + 48;
      if ( v18 == 1 )
        v22 = v21 + 64;
      v23 = *(_QWORD *)(v22 + 8);
      if ( v23 == v22 )
      {
        *(_QWORD *)(v20 + 8) = 0i64;
        v75[1] = 0i64;
      }
      else
      {
        *(_QWORD *)(v19 + 8) = v23;
      }
      v73 = v22;
      while ( 1 )
      {
        v20 = (__int64)v75;
        v19 = (__int64)v74;
        v74 = v75;
        v75 = (__int64 *)v19;
        v24 = v74[1];
        v77 = v24;
        if ( !v24 )
          break;
        v25 = 0i64;
        if ( *(_QWORD *)(v24 + 8) != v22 )
          v25 = *(_QWORD *)(v24 + 8);
        *(_QWORD *)(v19 + 8) = v25;
        v26 = v12 + *(_DWORD *)(v24 + 48);
        v81 = v26;
        if ( *(_QWORD *)(v24 + 24) )
        {
          if ( v13 >= v26 || v13 < v12 )
            goto LABEL_48;
          do
          {
            if ( *(_QWORD *)(v24 + 24) != v8 )
              v8 = *(_QWORD *)(v24 + 24);
            v82 = v8;
            v27 = v8 + ((__int64)(v13 - v12) << 7);
            v28 = *(_QWORD *)(v27 + 48);
            if ( v28 )
            {
              v29 = v28 & 0xFFFFFFFFFFFFFFFEui64;
              v79 = v29 != 0;
              v30 = 0;
              if ( *(_DWORD *)(v29 + 24) )
              {
                do
                {
                  v31 = *(_QWORD *)(v29 + 16) + 272i64 * v30;
                  v32 = *(_QWORD *)(v31 + 104);
                  v33 = *(_QWORD *)(v31 + 136);
                  if ( v32 && v33 )
                  {
                    v34 = *(_QWORD *)(v32 + 96);
                    v35 = v34 ? v34 + v32 + 96 : 0i64;
                    v36 = *(_QWORD *)(v33 + 96);
                    v37 = v36 ? v36 + v33 + 96 : 0i64;
                    LocalWorld = CullInfo::GetLocalWorld((CullInfo *)v27);
                    UFG::qMatrix44::operator*(LocalWorld, &result, v78.mWorldViewProjection);
                    v39 = 0i64;
                    if ( *(_DWORD *)(v32 + 108) )
                    {
                      w = result.v3.w;
                      do
                      {
                        v41 = *(float *)(v37 + 12i64 * *(unsigned __int16 *)(v35 + 2 * v39) + 4);
                        v42 = *(float *)(v37 + 12i64 * *(unsigned __int16 *)(v35 + 2 * v39));
                        v43 = *(float *)(v37 + 12i64 * *(unsigned __int16 *)(v35 + 2 * v39) + 8);
                        v0.w = 1.0;
                        v44 = 3i64 * *(unsigned __int16 *)(v35 + 2i64 * (unsigned int)(v39 + 1));
                        v0.x = v42;
                        v0.y = v41;
                        v0.z = v43;
                        v45 = *(float *)(v37 + 4 * v44 + 4);
                        v46 = *(float *)(v37 + 4 * v44 + 8);
                        v47 = *(float *)(v37 + 4 * v44);
                        v48 = *(unsigned __int16 *)(v35 + 2i64 * (unsigned int)(v39 + 2));
                        v1.w = 1.0;
                        v1.x = v47;
                        v1.y = v45;
                        v1.z = v46;
                        v49 = *(float *)(v37 + 12 * v48 + 4);
                        v50 = *(float *)(v37 + 12 * v48 + 8);
                        v51 = *(float *)(v37 + 12 * v48);
                        v0.x = (float)((float)((float)(result.v0.x * v42) + (float)(result.v1.x * v41))
                                     + (float)(result.v2.x * v43))
                             + result.v3.x;
                        v0.y = (float)((float)((float)(result.v0.y * v42) + (float)(result.v1.y * v41))
                                     + (float)(result.v2.y * v43))
                             + result.v3.y;
                        v0.z = (float)((float)((float)(result.v0.z * v42) + (float)(result.v1.z * v41))
                                     + (float)(result.v2.z * v43))
                             + result.v3.z;
                        v0.w = (float)((float)((float)(result.v0.w * v42) + (float)(result.v1.w * v41))
                                     + (float)(result.v2.w * v43))
                             + w;
                        v1.x = (float)((float)((float)(result.v0.x * v47) + (float)(result.v1.x * v45))
                                     + (float)(result.v2.x * v46))
                             + result.v3.x;
                        v1.y = (float)((float)((float)(result.v0.y * v47) + (float)(result.v1.y * v45))
                                     + (float)(result.v2.y * v46))
                             + result.v3.y;
                        v1.z = (float)((float)((float)(result.v0.z * v47) + (float)(result.v1.z * v45))
                                     + (float)(result.v2.z * v46))
                             + result.v3.z;
                        v1.w = (float)((float)((float)(result.v0.w * v47) + (float)(result.v1.w * v45))
                                     + (float)(result.v2.w * v46))
                             + w;
                        result.v2.x = (float)((float)((float)(result.v0.x * v51) + (float)(result.v1.x * v49))
                                            + (float)(result.v2.x * v50))
                                    + result.v3.x;
                        result.v2.y = (float)((float)((float)(result.v0.y * v51) + (float)(result.v1.y * v49))
                                            + (float)(result.v2.y * v50))
                                    + result.v3.y;
                        result.v2.z = (float)((float)((float)(result.v0.z * v51) + (float)(result.v1.z * v49))
                                            + (float)(result.v2.z * v50))
                                    + result.v3.z;
                        result.v2.w = (float)((float)((float)(result.v0.w * v51) + (float)(result.v1.w * v49))
                                            + (float)(result.v2.w * v50))
                                    + w;
                        Render::RasterizeZ::Draw2DH(&v78, &v0, &v1, &result.v2);
                        if ( v79 )
                          Render::RasterizeZ::Draw2DH(&v78, &result.v2, &v1, &v0);
                        v39 = (unsigned int)(v39 + 3);
                      }
                      while ( (unsigned int)v39 < *(_DWORD *)(v32 + 108) );
                    }
                  }
                  ++v30;
                }
                while ( v30 < *(_DWORD *)(v29 + 24) );
                v8 = v82;
                v26 = v81;
              }
            }
            else
            {
              v52 = *(float *)(v27 + 16);
              v53 = *(float *)v27;
              v54 = *(float *)(v27 + 4);
              v55 = *(float *)(v27 + 24);
              v56 = *(float *)(v27 + 8);
              result.v3.y = *(float *)(v27 + 20);
              result.v3.x = v52;
              result.v3.z = v55;
              v1.x = v53;
              v1.y = v54;
              v1.z = v56;
              if ( (float)((float)((float)(result.v3.y - v54) * (float)(v52 - v53)) * (float)(v55 - v56)) > 1.0
                && *(float *)(v27 + 124) != 0.0 )
              {
                Render::RasterizeZ::DrawAABB(
                  &v78,
                  (UFG::qVector3 *)&v1,
                  (UFG::qVector3 *)&result.v3,
                  (UFG::qMatrix44 *)(v27 + 64));
              }
            }
            v9 = v;
            v57 = UFG::qAtomicAdd(v, 1);
            v12 = v80;
            v24 = v77;
            v13 = v57;
          }
          while ( v57 < v26 && v57 >= v80 );
          v22 = v73;
          v12 = v26;
          v80 = v26;
        }
        else
        {
          for ( ; v13 < v26 && v13 >= v12; v13 = UFG::qAtomicAdd(v9, 1) )
            ;
LABEL_48:
          v22 = v73;
          v12 = v26;
          v80 = v26;
        }
      }
      v18 = (_DWORD)v83 + 1;
      LODWORD(v83) = v18;
      if ( v18 >= 2 )
      {
        v11 = v65;
        goto LABEL_7;
      }
    }
  }
} if ( v18 >= 2 )
      {
        v11 = v65;
        goto LABEL_7;
      }
    }
  }
}

// File Line: 305
// RVA: 0x81180
void __fastcall Render::CompositeZBuffers(
        UFG::qMemoryStreamer *memory_streamer,
        Render::RasterizeZ *rasterizer,
        unsigned int zbuffer_tag,
        __m128i *main_mem_zbuffer1,
        __m128i *main_mem_zbuffer2,
        __m128i *main_mem_zbuffer3,
        __m128i *main_mem_zbuffer4)
{
  Render::RasterizeZ v10; // [rsp+20h] [rbp-48h] BYREF

  Render::RasterizeZ::Init(&v10, (unsigned int *)main_mem_zbuffer1, 0);
  if ( *v10.mZBufferTag == zbuffer_tag )
    Render::RasterizeZ::Composite(rasterizer, main_mem_zbuffer1);
  Render::RasterizeZ::Init(&v10, (unsigned int *)main_mem_zbuffer2, 0);
  if ( *v10.mZBufferTag == zbuffer_tag )
    Render::RasterizeZ::Composite(rasterizer, main_mem_zbuffer2);
  Render::RasterizeZ::Init(&v10, (unsigned int *)main_mem_zbuffer3, 0);
  if ( *v10.mZBufferTag == zbuffer_tag )
    Render::RasterizeZ::Composite(rasterizer, main_mem_zbuffer3);
  Render::RasterizeZ::Init(&v10, (unsigned int *)main_mem_zbuffer4, 0);
  if ( *v10.mZBufferTag == zbuffer_tag )
    Render::RasterizeZ::Composite(rasterizer, main_mem_zbuffer4);
}

// File Line: 400
// RVA: 0x80180
void __fastcall Render::CullManager_CreateOcclusionMap(
        int worker_id,
        UFG::qMemoryStreamer *memory_streamer,
        _QWORD *main_mem_view_params,
        char *main_mem_occlusion_map_buffer)
{
  __m128i *v4; // rdi
  void *v5; // r14
  void *main_mem_zbuffer2; // r15
  void *main_mem_zbuffer3; // r12
  void *main_mem_zbuffer4; // r13
  unsigned int v9; // ebx
  Render::OcclusionMap v12; // [rsp+40h] [rbp-88h] BYREF
  Render::RasterizeZ rasterizer; // [rsp+60h] [rbp-68h] BYREF

  v4 = (__m128i *)main_mem_view_params[8];
  v5 = (void *)main_mem_view_params[9];
  main_mem_zbuffer2 = (void *)main_mem_view_params[10];
  main_mem_zbuffer3 = (void *)main_mem_view_params[11];
  main_mem_zbuffer4 = (void *)main_mem_view_params[12];
  v9 = *((_DWORD *)main_mem_view_params + 26);
  Render::RasterizeZ::Init(&rasterizer, (unsigned int *)v4, 0);
  if ( *rasterizer.mZBufferTag != v9 )
  {
    Render::RasterizeZ::Clear(&rasterizer);
    *rasterizer.mZBufferTag = v9;
  }
  Render::CompositeZBuffers(
    memory_streamer,
    &rasterizer,
    v9,
    v5,
    main_mem_zbuffer2,
    main_mem_zbuffer3,
    main_mem_zbuffer4);
  Render::OcclusionMap::Init(&v12, main_mem_occlusion_map_buffer);
  Render::OcclusionMap::CreateFromZBuffer(&v12, v4);
}

// File Line: 1237
// RVA: 0x80250
void __fastcall Render::CullManager_CullBucketTask(
        int worker_id,
        UFG::qMemoryStreamer *memory_streamer,
        unsigned __int16 *main_mem_view_params,
        void *main_mem_layer_list_head)
{
  __int64 v7; // r13
  void *v8; // rcx
  char *v9; // rdx
  __m128 v10; // xmm6
  __m128 v11; // xmm7
  char *v12; // r14
  int v13; // edi
  int v14; // r12d
  int v15; // ebx
  int v16; // edx
  unsigned __int64 v17; // r8
  __m128 v18; // xmm2
  __int64 *v19; // r9
  __int64 v20; // rax
  void *v21; // rax
  __int64 v22; // rcx
  int v23; // esi
  __int64 v24; // r10
  __int64 v25; // rcx
  __int64 v26; // r9
  __int64 v27; // r11
  __int64 v28; // rax
  __int64 v29; // r9
  __int64 v30; // rcx
  __m128 *v31; // rbx
  __int64 v32; // rsi
  unsigned int v33; // r9d
  BOOL v34; // eax
  unsigned int v35; // r15d
  int v36; // ecx
  void **v37; // r12
  UFG::qMatrix44 *v38; // r11
  __int64 v39; // rax
  unsigned int v40; // edx
  __int64 v41; // r9
  __int64 v42; // rax
  __m128 v43; // xmm0
  __m128 v44; // xmm8
  __m128 v45; // xmm9
  __m128 v46; // xmm10
  __m128 v47; // xmm11
  __m128 v48; // xmm15
  __m128 v49; // xmm12
  __m128 v50; // xmm13
  __m128 v51; // xmm14
  __m128 v52; // xmm6
  __m128 v53; // xmm5
  __m128 v54; // xmm4
  __m128 v55; // xmm6
  __m128 v56; // xmm4
  __m128 v57; // xmm15
  __m128 v58; // xmm0
  __m128 v59; // xmm1
  __m128 v60; // xmm2
  __m128 v61; // xmm4
  __m128 v62; // xmm0
  __m128 v63; // xmm1
  __m128 v64; // xmm2
  __m128 v65; // xmm3
  __m128 v66; // xmm1
  __m128 v67; // xmm2
  __m128 v68; // xmm0
  __m128 v69; // xmm8
  __m128 v70; // xmm9
  __m128 v71; // xmm10
  __m128 v72; // xmm6
  __m128 v73; // xmm7
  __m128 v74; // xmm8
  __m128 v75; // xmm5
  __m128 v76; // xmm3
  __m128 v77; // xmm4
  __m128 v78; // xmm9
  float v79; // xmm12_4
  int v80; // xmm6_4
  unsigned int v81; // edi
  int v82; // xmm7_4
  __int64 v83; // rax
  unsigned __int64 v84; // r12
  unsigned int v85; // edi
  char *v86; // rax
  unsigned int v87; // [rsp+30h] [rbp-98h]
  float v88; // [rsp+34h] [rbp-94h]
  BOOL v89; // [rsp+38h] [rbp-90h]
  int v90; // [rsp+3Ch] [rbp-8Ch]
  int v91; // [rsp+40h] [rbp-88h]
  int v92; // [rsp+44h] [rbp-84h]
  __m128 miny; // [rsp+48h] [rbp-80h]
  unsigned int minya; // [rsp+48h] [rbp-80h]
  __m128 minyb; // [rsp+48h] [rbp-80h]
  __m128 v96; // [rsp+58h] [rbp-70h]
  __m128 maxy; // [rsp+68h] [rbp-60h]
  __m128 maxyb; // [rsp+68h] [rbp-60h]
  __int64 maxya; // [rsp+68h] [rbp-60h]
  __m128 v100; // [rsp+78h] [rbp-50h]
  __m128 v101; // [rsp+88h] [rbp-40h]
  __m128 v102; // [rsp+98h] [rbp-30h]
  __m128 v103; // [rsp+A8h] [rbp-20h]
  __m128 v104; // [rsp+B8h] [rbp-10h]
  __m128 v105; // [rsp+C8h] [rbp+0h]
  void *v106; // [rsp+110h] [rbp+48h]
  __int64 *v107; // [rsp+118h] [rbp+50h] BYREF
  __int64 *v108; // [rsp+120h] [rbp+58h]
  UFG::qMemoryStreamer *v109; // [rsp+128h] [rbp+60h]
  __int64 v110[2]; // [rsp+130h] [rbp+68h] BYREF
  int v111; // [rsp+140h] [rbp+78h]
  __int64 v112[2]; // [rsp+148h] [rbp+80h] BYREF
  int v113; // [rsp+158h] [rbp+90h]
  __int64 i; // [rsp+160h] [rbp+98h]
  __int64 *v115; // [rsp+168h] [rbp+A0h]
  __int64 *v116; // [rsp+170h] [rbp+A8h]
  UFG::qLinearAllocator *v117; // [rsp+178h] [rbp+B0h]
  __m128 v118; // [rsp+188h] [rbp+C0h]
  __m128 v119; // [rsp+198h] [rbp+D0h]
  __m128 v120; // [rsp+1A8h] [rbp+E0h]
  __m128 v121; // [rsp+1B8h] [rbp+F0h]
  volatile int *v; // [rsp+1C8h] [rbp+100h]
  const char *ptr; // [rsp+1D0h] [rbp+108h] BYREF
  __int64 v124[2]; // [rsp+1D8h] [rbp+110h]
  const char *v125; // [rsp+1E8h] [rbp+120h]
  __m128 v126; // [rsp+208h] [rbp+140h]
  __m128 v127; // [rsp+218h] [rbp+150h]
  __m128 v128; // [rsp+228h] [rbp+160h]
  __m128 v129; // [rsp+238h] [rbp+170h]
  __int64 v130; // [rsp+248h] [rbp+180h]
  char *v131; // [rsp+258h] [rbp+190h]
  Render::OcclusionMap v132; // [rsp+268h] [rbp+1A0h] BYREF
  __int64 v133; // [rsp+290h] [rbp+1C8h]
  unsigned int v134; // [rsp+390h] [rbp+2C8h]
  int v135; // [rsp+398h] [rbp+2D0h]
  int v136; // [rsp+3A0h] [rbp+2D8h]
  void *v137; // [rsp+3A8h] [rbp+2E0h] BYREF

  v130 = -2i64;
  v92 = 0;
  v90 = 0;
  v107 = (__int64 *)&v107;
  v108 = v110;
  v7 = 0i64;
  v131 = 0i64;
  `eh vector constructor iterator(
    &ptr,
    0x18ui64,
    2,
    (void (__fastcall *)(void *))UFG::qMemoryStream<UFG::AIInterestComponent,432>::qMemoryStream<UFG::AIInterestComponent,432>);
  ptr = "local_world_matrix_stream";
  v125 = "local_world_matrix_stream";
  v117 = (UFG::qLinearAllocator *)*((_QWORD *)main_mem_view_params + 12);
  v8 = v137;
  if ( main_mem_layer_list_head == v137 )
  {
    v107[1] = 0i64;
    v108[1] = 0i64;
  }
  else
  {
    v108[1] = (__int64)main_mem_layer_list_head;
  }
  v106 = v8;
  v88 = 0.0;
  v9 = (char *)*((_QWORD *)main_mem_view_params + 8);
  if ( v9 )
  {
    v88 = (float)main_mem_view_params[36];
    Render::OcclusionMap::Init(&v132, v9);
    Render::OcclusionMap::BeginFrame(&v132, (UFG::qMatrix44 *)main_mem_view_params);
  }
  v87 = main_mem_view_params[37];
  maxy.m128_i32[2] = 1 << v87;
  v105 = _mm_shuffle_ps(
           (__m128)*((unsigned int *)main_mem_view_params + 21),
           (__m128)*((unsigned int *)main_mem_view_params + 21),
           0);
  v102.m128_u64[0] = 0i64;
  v102.m128_i32[2] = 0;
  v102.m128_i32[3] = *((_DWORD *)main_mem_view_params + 23);
  v10 = *(__m128 *)main_mem_view_params;
  v126 = *(__m128 *)main_mem_view_params;
  v11 = *((__m128 *)main_mem_view_params + 1);
  v103 = v11;
  v129 = *((__m128 *)main_mem_view_params + 2);
  v128 = *((__m128 *)main_mem_view_params + 3);
  v12 = 0i64;
  v13 = 7;
  v135 = 7;
  v = (volatile int *)*((_QWORD *)main_mem_view_params + 13);
  v14 = 0;
  v91 = 0;
  v15 = UFG::qAtomicAdd(v, 1);
  v109 = memory_streamer;
  v110[0] = (__int64)"cull_bucket_iterator";
  v110[1] = 0i64;
  v111 = 0;
  v112[0] = (__int64)"cull_bucket_iterator";
  v112[1] = 0i64;
  v113 = 0;
  i = 0i64;
  v115 = v110;
  v116 = v112;
  v16 = v87;
  v17 = v87;
  miny.m128_u64[1] = v87;
  v18 = (__m128)(unsigned int)FLOAT_1_0;
  while ( 1 )
  {
    v19 = v107;
    v107 = v108;
    v108 = v19;
    v20 = v107[1];
    if ( !v20 )
      break;
    v21 = *(void **)(v20 + 8);
    v22 = 0i64;
    if ( v21 != v106 )
      v22 = (__int64)v21;
    v19[1] = v22;
    v23 = 0;
    minya = 0;
    v24 = (__int64)v116;
    v25 = (__int64)v115;
    do
    {
      v26 = v107[1];
      v27 = v26 + 48;
      if ( v23 == 1 )
        v27 = v26 + 64;
      v28 = *(_QWORD *)(v27 + 8);
      if ( v28 == v27 )
      {
        *(_QWORD *)(v25 + 8) = 0i64;
        v116[1] = 0i64;
      }
      else
      {
        *(_QWORD *)(v24 + 8) = v28;
      }
      for ( i = v27; ; v27 = i )
      {
        v25 = (__int64)v116;
        v24 = (__int64)v115;
        v115 = v116;
        v116 = (__int64 *)v24;
        v29 = v115[1];
        if ( !v29 )
          break;
        v30 = 0i64;
        if ( *(_QWORD *)(v29 + 8) != v27 )
          v30 = *(_QWORD *)(v29 + 8);
        *(_QWORD *)(v24 + 8) = v30;
        if ( v14 == v15 )
        {
          v31 = *(__m128 **)(v29 + 16);
          v32 = *(_QWORD *)(v29 + 32);
          v133 = v32;
          v33 = *(_DWORD *)(v29 + 48);
          v134 = v33;
          v34 = v32 != 0;
          v89 = v34;
          if ( v33 )
          {
            v124[0] = v31[3].m128_i64[1];
            if ( !v124[0] )
              v124[0] = 0i64;
          }
          v35 = 0;
          if ( v33 )
          {
            while ( 1 )
            {
              v36 = v31->m128_u16[7];
              v136 = v36;
              v37 = &v137;
              if ( v34 )
              {
                v36 = v136;
                if ( v16 <= 16 && v16 >= 0 )
                  v37 = (void **)(v32 + v16);
                else
                  v37 = 0i64;
              }
              v38 = &UFG::qMatrix44::msIdentity;
              v39 = v31[3].m128_i64[1];
              if ( v39 )
              {
                if ( v39 != v124[3 * (v35 & 1)] )
                  v124[3 * (v35 & 1)] = v39;
                v38 = (UFG::qMatrix44 *)v124[3 * (v35 & 1)];
              }
              v40 = v36 + v35;
              if ( v36 + v35 + 1 < v33 )
              {
                v41 = v31[4 * v36 + 7].m128_i64[1];
                if ( v41 )
                  v124[3 * (((unsigned __int8)v35 - 1) & 1)] = v41;
                else
                  v124[3 * (((unsigned __int8)v35 - 1) & 1)] = 0i64;
                v33 = v134;
              }
              if ( (v31[1].m128_i16[7] & maxy.m128_i16[4]) == 0 )
                break;
              *(_BYTE *)v37 = 2;
              v35 += v36;
              v42 = (__int64)v36 << 6;
              v31 = (__m128 *)((char *)v31 + v42);
              v32 += v42;
              ++v92;
              v90 += v36;
LABEL_68:
              ++v35;
              v31 += 4;
              v32 += 64i64;
              v17 = miny.m128_u64[1];
              v16 = v87;
              v34 = v89;
              if ( v35 >= v33 )
              {
                v14 = v91;
                goto LABEL_70;
              }
            }
            v43 = (__m128)COERCE_UNSIGNED_INT((float)v31[1].m128_u16[6]);
            if ( v43.m128_f32[0] < v18.m128_f32[0] )
              v43 = v18;
            v104 = _mm_shuffle_ps(v43, v43, 0);
            v44 = (__m128)v38->v0;
            v45 = (__m128)v38->v1;
            v46 = (__m128)v38->v2;
            v47 = (__m128)v38->v3;
            v48 = _mm_shuffle_ps(*v31, _mm_shuffle_ps(*v31, gXYZ0W1, 250), 148);
            minyb = _mm_mul_ps(_mm_shuffle_ps(v47, v47, 0), v10);
            v49 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v44, v44, 0), v10), _xmm),
                        _mm_mul_ps(_mm_shuffle_ps(v44, v44, 85), v11)),
                      _mm_mul_ps(_mm_shuffle_ps(v44, v44, 170), v129)),
                    _mm_mul_ps(_mm_shuffle_ps(v44, v44, 255), v128));
            v50 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v45, v45, 0), v10), (__m128)0i64),
                        _mm_mul_ps(_mm_shuffle_ps(v45, v45, 85), v11)),
                      _mm_mul_ps(_mm_shuffle_ps(v45, v45, 170), v129)),
                    _mm_mul_ps(_mm_shuffle_ps(v45, v45, 255), v128));
            v51 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v46, v46, 0), v10), (__m128)0i64),
                        _mm_mul_ps(_mm_shuffle_ps(v46, v46, 85), v11)),
                      _mm_mul_ps(_mm_shuffle_ps(v46, v46, 170), v129)),
                    _mm_mul_ps(_mm_shuffle_ps(v46, v46, 255), v128));
            v52 = _mm_sub_ps(_mm_shuffle_ps(v31[1], _mm_shuffle_ps(v31[1], gXYZ0W1, 250), 148), v48);
            v53 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v52, v52, 0), v49), (__m128)0i64);
            v54 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v52, v52, 85), v50), (__m128)0i64);
            v55 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v52, v52, 170), v51), (__m128)0i64);
            miny = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_add_ps(
                           _mm_add_ps(_mm_add_ps(minyb, (__m128)0i64), _mm_mul_ps(_mm_shuffle_ps(v47, v47, 85), v103)),
                           _mm_mul_ps(_mm_shuffle_ps(v47, v47, 170), v129)),
                         _mm_mul_ps(_mm_shuffle_ps(v47, v47, 255), v128)),
                       _mm_shuffle_ps(v48, v48, 255)),
                     _mm_add_ps(
                       _mm_mul_ps(v51, _mm_shuffle_ps(v48, v48, 170)),
                       _mm_add_ps(
                         _mm_mul_ps(v50, _mm_shuffle_ps(v48, v48, 85)),
                         _mm_add_ps(_mm_mul_ps(v49, _mm_shuffle_ps(v48, v48, 0)), (__m128)0i64))));
            v120 = _mm_add_ps(miny, v53);
            v121 = _mm_add_ps(miny, v54);
            v118 = _mm_add_ps(miny, _mm_add_ps(v54, v53));
            v119 = _mm_add_ps(v120, v55);
            v100 = _mm_add_ps(miny, v55);
            v127 = _mm_add_ps(v121, v55);
            v56 = _mm_shuffle_ps(v118, v102, 239);
            maxyb = _mm_shuffle_ps(v118, v118, 164);
            maxy = _mm_or_ps(
                     (__m128)_mm_slli_epi32(
                               _mm_srli_epi32((__m128i)_mm_cmplt_ps(maxyb, _mm_sub_ps((__m128)0i64, v56)), 0x1Fu),
                               0x1Eu),
                     (__m128)_mm_slli_epi32((__m128i)_mm_cmplt_ps(v56, maxyb), 0x1Fu));
            v57 = _mm_add_ps(v118, v55);
            v58 = _mm_sub_ps(v57, miny);
            v59 = _mm_add_ps((__m128)0i64, _mm_mul_ps(v58, v58));
            v60 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v59, v59, 85), v59), _mm_shuffle_ps(v59, v59, 170));
            v61 = _mm_add_ps((__m128)0i64, _mm_mul_ps(_mm_rsqrt_ps(v60), v60));
            v62 = _mm_sub_ps((__m128)0i64, _mm_add_ps(_mm_mul_ps(_mm_add_ps(v57, miny), gHalf), (__m128)0i64));
            v63 = _mm_add_ps((__m128)0i64, _mm_mul_ps(v62, v62));
            v64 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v63, v63, 85), v63), _mm_shuffle_ps(v63, v63, 170));
            v101 = _mm_max_ps(
                     _mm_sub_ps(
                       _mm_add_ps((__m128)0i64, _mm_mul_ps(_mm_rsqrt_ps(v64), v64)),
                       _mm_add_ps(_mm_mul_ps(v61, gHalf), (__m128)0i64)),
                     gMinDistance);
            v96 = _mm_add_ps(
                    (__m128)0i64,
                    _mm_mul_ps(
                      _mm_add_ps((__m128)0i64, _mm_mul_ps(v61, v104)),
                      _mm_rcp_ps(_mm_max_ps(gOne, _mm_sub_ps(v101, v105)))));
            v65 = _mm_shuffle_ps(miny, v120, 255);
            v66 = _mm_shuffle_ps(v121, v118, 255);
            v67 = _mm_shuffle_ps(v119, v100, 255);
            v68 = _mm_shuffle_ps(v57, v127, 255);
            v69 = _mm_rcp_ps(_mm_shuffle_ps(_mm_shuffle_ps(v65, v65, 153), _mm_shuffle_ps(v66, v66, 153), 68));
            v70 = _mm_rcp_ps(_mm_shuffle_ps(_mm_shuffle_ps(v67, v67, 153), _mm_shuffle_ps(v68, v68, 153), 68));
            v71 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v69, gXYZ0W1, 240), miny), (__m128)0i64);
            v72 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v69, gXYZ0W1, 245), v120), (__m128)0i64);
            v73 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v69, gXYZ0W1, 250), v121), (__m128)0i64);
            v74 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v69, gXYZ0W1, 255), v118), (__m128)0i64);
            v75 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v70, gXYZ0W1, 240), v119), (__m128)0i64);
            v76 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v70, gXYZ0W1, 245), v100), (__m128)0i64);
            v77 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v70, gXYZ0W1, 250), v57), (__m128)0i64);
            v78 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v70, gXYZ0W1, 255), v127), (__m128)0i64);
            v119 = _mm_max_ps(
                     _mm_min_ps(
                       _mm_min_ps(_mm_min_ps(v71, v72), _mm_min_ps(v73, v74)),
                       _mm_min_ps(_mm_min_ps(v75, v76), _mm_min_ps(v77, v78))),
                     gMinusOne);
            v120 = v119;
            v118 = _mm_min_ps(
                     _mm_max_ps(
                       _mm_max_ps(_mm_max_ps(v71, v72), _mm_max_ps(v73, v74)),
                       _mm_max_ps(_mm_max_ps(v75, v76), _mm_max_ps(v77, v78))),
                     gOne);
            v121 = v118;
            v79 = _mm_shuffle_ps(v119, v119, 255).m128_f32[0];
            v18 = (__m128)(unsigned int)FLOAT_1_0;
            if ( v79 < 1.0 )
              v79 = *(float *)&FLOAT_1_0;
            minya = (int)(float)((float)(1.0 - (float)((float)(v121.m128_f32[1] + 1.0) * 0.5)) * v88);
            maxya = (unsigned int)(int)(float)((float)(1.0 - (float)((float)(v120.m128_f32[1] + 1.0) * 0.5)) * v88);
            if ( v79 < 1.0 )
              v79 = *(float *)&FLOAT_1_0;
            v80 = v96.m128_i32[0];
            if ( v96.m128_i32[0] == 2 )
            {
              v81 = 3;
            }
            else
            {
              v81 = v96.m128_i32[0] == 1;
              if ( v96.m128_f32[0] >= 0.0 )
              {
                if ( (_DWORD)maxya == 0 && v96.m128_u64[1] != 0 )
                {
                  if ( !(unsigned int)Render::OcclusionMap::TestRect(
                                        (Render::OcclusionMap *)v96.m128_u64[1],
                                        (int)(float)((float)((float)(v119.m128_f32[0] + 1.0) * 0.5) * v88),
                                        minya,
                                        (int)(float)((float)((float)(v118.m128_f32[0] + 1.0) * 0.5) * v88),
                                        maxya,
                                        (int)(float)((float)(1.0 - (float)(1.0 / v79)) * 65536.0)) )
                    v81 = 5;
                  v18 = (__m128)(unsigned int)FLOAT_1_0;
                  v40 = HIDWORD(maxya);
                  v17 = miny.m128_u64[1];
                }
                v36 = v136;
              }
              else
              {
                v81 = 4;
              }
            }
            v82 = v101.m128_i32[0];
            if ( v87 < 6 && v89 )
            {
              *(_DWORD *)(v32 + 4 * v17 + 16) = v101.m128_i32[0];
              *(_DWORD *)(v32 + 4 * v17 + 40) = v96.m128_i32[0];
            }
            *(_BYTE *)v37 = v81;
            if ( v81 > 1 )
            {
              v35 = v40;
              v83 = (__int64)v36 << 6;
              v31 = (__m128 *)((char *)v31 + v83);
              v32 += v83;
              goto LABEL_66;
            }
            v84 = v31[2].m128_u64[1];
            if ( *(_OWORD *)((char *)&v31[2] + 8) == 0i64 )
            {
LABEL_66:
              v13 = v135;
            }
            else
            {
              v85 = v135;
              if ( v135 == 7 )
              {
                if ( v12 )
                {
                  *(_QWORD *)v12 = _InterlockedExchange64((volatile __int64 *)(v107[1] + 8 * v17 + 80), v7);
                  v82 = v101.m128_i32[0];
                  v80 = v96.m128_i32[0];
                }
                v86 = UFG::qLinearAllocator::Malloc(v117, 0xC0u, 0x20u);
                v7 = (__int64)v86;
                if ( !v86 )
                  goto LABEL_75;
                v131 = v86;
                v12 = v86;
                v85 = 0;
              }
              *(_QWORD *)&v12[8 * v85 + 24] = v84;
              *(_QWORD *)&v12[8 * v85 + 80] = v31[3].m128_u64[0];
              v12[v85 + 12] = 0;
              *(_DWORD *)&v12[4 * v85 + 164] = v82;
              *(_DWORD *)&v12[4 * v85 + 136] = v80;
              v13 = v85 + 1;
              v135 = v13;
              *((_DWORD *)v12 + 2) = v13;
              v18 = (__m128)(unsigned int)FLOAT_1_0;
            }
            v10 = v126;
            v11 = v103;
            v33 = v134;
            goto LABEL_68;
          }
LABEL_70:
          v15 = UFG::qAtomicAdd(v, 1);
          v18 = (__m128)(unsigned int)FLOAT_1_0;
          v17 = miny.m128_u64[1];
          v16 = v87;
        }
        v91 = ++v14;
      }
      v23 = minya + 1;
      minya = v23;
    }
    while ( v23 < 2 );
    if ( v13 != 0 && v12 != 0i64 )
    {
      *(_QWORD *)v12 = _InterlockedExchange64((volatile __int64 *)(v107[1] + 8 * v17 + 80), v7);
      v12 = 0i64;
      v13 = 7;
      v135 = 7;
      v7 = (__int64)v131;
    }
  }
LABEL_75:
  `eh vector destructor iterator(&ptr, 0x18ui64, 2, (void (__fastcall *)(void *))_);
}   }
  }
LABEL_75:
  `eh vector destructor iterator(&ptr, 0x18ui64, 2, (void (__fastcall *)(void *))_);
}

// File Line: 1718
// RVA: 0x81250
// local variable allocation has failed, the output may be wrong!
__int64 __fastcall Render::GetCullResultsAABB(
        UFG::qMatrix44 *world_view_proj,
        float view_far_plane,
        float view_pixel_threshold,
        double distance_bias,
        CullInfo *cull_info,
        Render::CullMetrics *cull_metrics)
{
  UFG::qVector4 v6; // xmm13
  UFG::qVector4 v7; // xmm11
  UFG::qVector4 v8; // xmm12
  float *mpLocalWorld; // rax
  __m128 v10; // xmm2
  __m128 v11; // xmm4
  __m128 v12; // xmm6
  __m128 v13; // xmm10
  __m128 v14; // xmm0
  __m128 v15; // xmm14
  __m128 v16; // xmm8
  __m128 v17; // xmm7
  __m128 v18; // xmm3
  __m128 v19; // xmm15
  __m128 v20; // xmm0
  __m128 v21; // xmm2
  __m128 v22; // xmm15
  __m128 v23; // xmm5
  __m128 v24; // xmm10
  __m128 v25; // xmm6
  __m128 v26; // xmm9
  __m128 v27; // xmm8
  __m128 v28; // xmm7
  __m128 v29; // xmm1
  __m128 v30; // xmm13
  __m128 v31; // xmm11
  __m128 v32; // xmm0
  __m128 v33; // xmm2
  __m128 v34; // xmm12
  __m128 v35; // xmm1
  __m128 v36; // xmm10
  __m128 v37; // xmm1
  __m128 v38; // xmm6
  __m128 v39; // xmm0
  __m128 v40; // xmm2
  __m128 v41; // xmm1
  __m128 v42; // xmm3
  __m128 v43; // xmm9
  __m128 v44; // xmm1
  __m128i v45; // xmm10
  __m128 v46; // xmm0
  __m128 v47; // xmm10
  __m128 v48; // xmm2
  __m128 v49; // xmm1
  __m128 v50; // xmm13
  __m128i v51; // xmm2
  __m128i v52; // xmm9
  __m128 v53; // xmm0
  __m128 v54; // xmm9
  __m128 v55; // xmm2
  __m128 v56; // xmm1
  __m128 v57; // xmm8
  __m128i v58; // xmm2
  __m128i v59; // xmm13
  __m128 v60; // xmm0
  __m128 v61; // xmm13
  __m128 v62; // xmm2
  __m128 v63; // xmm1
  __m128 v64; // xmm7
  __m128i v65; // xmm2
  __m128i v66; // xmm8
  __m128 v67; // xmm0
  __m128 v68; // xmm8
  __m128 v69; // xmm2
  __m128 v70; // xmm1
  __m128 v71; // xmm7
  __m128 v72; // xmm0
  __m128 v73; // xmm11
  __m128 v74; // xmm0
  __m128 v75; // xmm3
  __m128 v76; // xmm11
  __m128 v77; // xmm4
  __m128 v78; // xmm11
  __m128 v79; // xmm1
  __m128 v80; // xmm1
  __m128 v81; // xmm0
  __m128 v82; // xmm1
  __m128 v83; // xmm4
  __m128 v84; // xmm1
  __m128 v85; // xmm0
  __m128 v86; // xmm3
  float v87; // xmm2_4
  __m128 v89; // [rsp+0h] [rbp-F8h]
  __m128 v90; // [rsp+10h] [rbp-E8h]
  float v91; // [rsp+20h] [rbp-D8h]
  __m128 v92; // [rsp+30h] [rbp-C8h]
  unsigned int v93; // [rsp+108h] [rbp+10h]

  v89.m128_f32[3] = view_far_plane;
  v89.m128_u64[0] = 0i64;
  v89.m128_i32[2] = 0;
  v90 = _mm_shuffle_ps(*(__m128 *)&distance_bias, *(__m128 *)&distance_bias, 0);
  v6 = world_view_proj->v3;
  v7 = world_view_proj->v1;
  v8 = world_view_proj->v2;
  mpLocalWorld = cull_info->mpLocalWorld;
  v10 = *(__m128 *)mpLocalWorld;
  v11 = *(__m128 *)(mpLocalWorld + 4);
  v12 = *(__m128 *)(mpLocalWorld + 8);
  v13 = *(__m128 *)(mpLocalWorld + 12);
  v14 = (__m128)COERCE_UNSIGNED_INT((float)cull_info->mPixelScaleBias);
  v91 = _mm_shuffle_ps(v14, v14, 0).m128_f32[0];
  v15 = _mm_shuffle_ps(
          *(__m128 *)cull_info->mAABBMin,
          _mm_shuffle_ps(*(__m128 *)cull_info->mAABBMin, gXYZ0W1, 250),
          148);
  v16 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v10, v10, 0), (__m128)world_view_proj->v0), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps(v10, v10, 85), (__m128)v7)),
            _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)mpLocalWorld, *(__m128 *)mpLocalWorld, 170), (__m128)v8)),
          _mm_mul_ps(_mm_shuffle_ps(v10, v10, 255), (__m128)v6));
  v17 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v11, v11, 0), (__m128)world_view_proj->v0), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps(v11, v11, 85), (__m128)v7)),
            _mm_mul_ps(_mm_shuffle_ps(v11, v11, 170), (__m128)v8)),
          _mm_mul_ps(_mm_shuffle_ps(v11, v11, 255), (__m128)v6));
  v18 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v12, v12, 0), (__m128)world_view_proj->v0), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps(v12, v12, 85), (__m128)v7)),
            _mm_mul_ps(_mm_shuffle_ps(v12, v12, 170), (__m128)v8)),
          _mm_mul_ps(_mm_shuffle_ps(v12, v12, 255), (__m128)v6));
  v19 = _mm_sub_ps(
          _mm_shuffle_ps(
            *(__m128 *)cull_info->mAABBMax,
            _mm_shuffle_ps(*(__m128 *)cull_info->mAABBMax, gXYZ0W1, 250),
            148),
          v15);
  v20 = _mm_shuffle_ps(v19, v19, 85);
  v21 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v19, v19, 0), v16), (__m128)0i64);
  v22 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v19, v19, 170), v18), (__m128)0i64);
  v92 = _mm_add_ps(_mm_mul_ps(v20, v17), (__m128)0i64);
  v23 = _mm_add_ps(
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v13, v13, 0), (__m128)world_view_proj->v0), (__m128)0i64),
                  _mm_mul_ps(_mm_shuffle_ps(v13, v13, 85), (__m128)v7)),
                _mm_mul_ps(_mm_shuffle_ps(v13, v13, 170), (__m128)v8)),
              _mm_mul_ps(_mm_shuffle_ps(v13, v13, 255), (__m128)v6)),
            _mm_shuffle_ps(v15, v15, 255)),
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v15, v15, 0), v16), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps(v15, v15, 85), v17)),
            _mm_mul_ps(_mm_shuffle_ps(v15, v15, 170), v18)));
  v24 = _mm_add_ps(v23, v21);
  v25 = _mm_shuffle_ps(v23, v23, 164);
  v26 = _mm_add_ps(v23, v92);
  v27 = _mm_add_ps(v24, v22);
  v28 = _mm_add_ps(v23, v22);
  v29 = _mm_shuffle_ps(v23, v89, 239);
  v30 = _mm_add_ps(_mm_add_ps(v92, v21), v23);
  v31 = _mm_add_ps(v26, v22);
  v32 = _mm_sub_ps((__m128)0i64, v29);
  v33 = (__m128)_mm_slli_epi32((__m128i)_mm_cmplt_ps(v29, v25), 0x1Fu);
  v34 = _mm_add_ps(v30, v22);
  v35 = v24;
  v36 = _mm_shuffle_ps(v24, v24, 164);
  v37 = _mm_shuffle_ps(v35, v89, 239);
  v38 = _mm_or_ps((__m128)_mm_slli_epi32(_mm_srli_epi32((__m128i)_mm_cmplt_ps(v25, v32), 0x1Fu), 0x1Eu), v33);
  v39 = _mm_sub_ps((__m128)0i64, v37);
  v40 = (__m128)_mm_slli_epi32((__m128i)_mm_cmplt_ps(v37, v36), 0x1Fu);
  v41 = v26;
  v42 = _mm_shuffle_ps(v34, v34, 164);
  v43 = _mm_shuffle_ps(v26, v26, 164);
  v44 = _mm_shuffle_ps(v41, v89, 239);
  v45 = _mm_srli_epi32((__m128i)_mm_cmplt_ps(v36, v39), 0x1Fu);
  v46 = _mm_sub_ps((__m128)0i64, v44);
  v47 = _mm_or_ps((__m128)_mm_slli_epi32(v45, 0x1Eu), v40);
  v48 = v44;
  v49 = _mm_shuffle_ps(v30, v89, 239);
  v50 = _mm_shuffle_ps(v30, v30, 164);
  v51 = (__m128i)_mm_cmplt_ps(v48, v43);
  v52 = (__m128i)_mm_cmplt_ps(v43, v46);
  v53 = _mm_sub_ps((__m128)0i64, v49);
  v54 = _mm_or_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v52, 0x1Fu), 0x1Eu), (__m128)_mm_slli_epi32(v51, 0x1Fu));
  v55 = v49;
  v56 = _mm_shuffle_ps(v27, v89, 239);
  v57 = _mm_shuffle_ps(v27, v27, 164);
  v58 = (__m128i)_mm_cmplt_ps(v55, v50);
  v59 = (__m128i)_mm_cmplt_ps(v50, v53);
  v60 = _mm_sub_ps((__m128)0i64, v56);
  v61 = _mm_or_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v59, 0x1Fu), 0x1Eu), (__m128)_mm_slli_epi32(v58, 0x1Fu));
  v62 = v56;
  v63 = _mm_shuffle_ps(v28, v89, 239);
  v64 = _mm_shuffle_ps(v28, v28, 164);
  v65 = (__m128i)_mm_cmplt_ps(v62, v57);
  v66 = (__m128i)_mm_cmplt_ps(v57, v60);
  v67 = _mm_sub_ps((__m128)0i64, v63);
  v68 = _mm_or_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v66, 0x1Fu), 0x1Eu), (__m128)_mm_slli_epi32(v65, 0x1Fu));
  v69 = v63;
  v70 = _mm_shuffle_ps(v34, v89, 239);
  v71 = _mm_or_ps(
          (__m128)_mm_slli_epi32(_mm_srli_epi32((__m128i)_mm_cmplt_ps(v64, v67), 0x1Fu), 0x1Eu),
          (__m128)_mm_slli_epi32((__m128i)_mm_cmplt_ps(v69, v64), 0x1Fu));
  v72 = v31;
  v73 = _mm_shuffle_ps(v31, v31, 164);
  v74 = _mm_shuffle_ps(v72, v89, 239);
  v75 = _mm_or_ps(
          (__m128)_mm_slli_epi32(
                    _mm_srli_epi32((__m128i)_mm_cmplt_ps(v42, _mm_sub_ps((__m128)0i64, v70)), 0x1Fu),
                    0x1Eu),
          (__m128)_mm_slli_epi32((__m128i)_mm_cmplt_ps(v70, v42), 0x1Fu));
  v76 = _mm_or_ps(
          (__m128)_mm_slli_epi32(
                    _mm_srli_epi32((__m128i)_mm_cmplt_ps(v73, _mm_sub_ps((__m128)0i64, v74)), 0x1Fu),
                    0x1Eu),
          (__m128)_mm_slli_epi32((__m128i)_mm_cmplt_ps(v74, v73), 0x1Fu));
  v77 = _mm_and_ps(
          _mm_and_ps(
            _mm_and_ps(_mm_and_ps(v76, v75), _mm_and_ps(v71, v68)),
            _mm_and_ps(_mm_and_ps(v61, v54), _mm_and_ps(v47, v38))),
          (__m128)gMask_Outcode);
  v78 = _mm_and_ps(
          _mm_or_ps(
            _mm_or_ps(_mm_or_ps(v76, v75), _mm_or_ps(v71, v68)),
            _mm_or_ps(_mm_or_ps(v61, v54), _mm_or_ps(v47, v38))),
          (__m128)gMask_Outcode);
  v79 = _mm_sub_ps(v34, v23);
  v80 = _mm_add_ps(_mm_mul_ps(v79, v79), (__m128)0i64);
  v93 = _mm_andnot_ps(
          (__m128)_mm_cmpeq_epi32(
                    (__m128i)_mm_or_ps(
                               _mm_or_ps(_mm_shuffle_ps(v77, v77, 255), _mm_shuffle_ps(v77, v77, 170)),
                               _mm_or_ps(_mm_shuffle_ps(v77, v77, 85), _mm_shuffle_ps(v77, v77, 0))),
                    (__m128i)0i64),
          (__m128)_xmm).m128_u32[0] | _mm_cmpeq_epi32(
                                        (__m128i)_mm_or_ps(
                                                   _mm_or_ps(_mm_shuffle_ps(v78, v78, 85), _mm_shuffle_ps(v78, v78, 0)),
                                                   _mm_or_ps(
                                                     _mm_shuffle_ps(v78, v78, 255),
                                                     _mm_shuffle_ps(v78, v78, 170))),
                                        (__m128i)0i64).m128i_u32[0] & _xmm[0];
  v81 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v80, v80, 85), v80), _mm_shuffle_ps(v80, v80, 170));
  v82 = _mm_sub_ps((__m128)0i64, _mm_add_ps(_mm_mul_ps(_mm_add_ps(v34, v23), gHalf), (__m128)0i64));
  v83 = _mm_add_ps(_mm_mul_ps(_mm_rsqrt_ps(v81), v81), (__m128)0i64);
  v84 = _mm_add_ps(_mm_mul_ps(v82, v82), (__m128)0i64);
  v85 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v84, v84, 85), v84), _mm_shuffle_ps(v84, v84, 170));
  v86 = _mm_max_ps(
          _mm_sub_ps(
            _mm_add_ps(_mm_mul_ps(_mm_rsqrt_ps(v85), v85), (__m128)0i64),
            _mm_add_ps(_mm_mul_ps(v83, gHalf), (__m128)0i64)),
          gMinDistance);
  LODWORD(cull_metrics->mDistance) = v86.m128_i32[0];
  v87 = (float)(_mm_rcp_ps(_mm_max_ps(gOne, _mm_sub_ps(v86, v90))).m128_f32[0]
              * (float)((float)(v83.m128_f32[0] * v91) + 0.0))
      + 0.0;
  cull_metrics->mPixelCoverage = v87;
  if ( v93 == 2 )
    return 3i64;
  if ( v87 >= view_pixel_threshold )
    return v93 == 1;
  return 4i64;
}

