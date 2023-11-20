// File Line: 66
// RVA: 0x14576D0
__int64 Render::_dynamic_initializer_for__gTaskFunctionDecl_CullManager_RasterizeZBuffer__()
{
  UFG::qTaskFunctionDecl::qTaskFunctionDecl(
    &Render::gTaskFunctionDecl_CullManager_RasterizeZBuffer,
    &Render::gTaskFunctionDeclData_CullManager_RasterizeZBuffer);
  return atexit(Render::_dynamic_atexit_destructor_for__gTaskFunctionDecl_CullManager_RasterizeZBuffer__);
}

// File Line: 67
// RVA: 0x1457670
__int64 Render::_dynamic_initializer_for__gTaskFunctionDecl_CullManager_CreateOcclusionMap__()
{
  UFG::qTaskFunctionDecl::qTaskFunctionDecl(
    &Render::gTaskFunctionDecl_CullManager_CreateOcclusionMap,
    &Render::gTaskFunctionDeclData_CullManager_CreateOcclusionMap);
  return atexit(Render::_dynamic_atexit_destructor_for__gTaskFunctionDecl_CullManager_CreateOcclusionMap__);
}

// File Line: 68
// RVA: 0x14576A0
__int64 Render::_dynamic_initializer_for__gTaskFunctionDecl_CullManager_CullBucketTask__()
{
  UFG::qTaskFunctionDecl::qTaskFunctionDecl(
    &Render::gTaskFunctionDecl_CullManager_CullBucketTask,
    &Render::gTaskFunctionDeclData_CullManager_CullBucketTask);
  return atexit(Render::_dynamic_atexit_destructor_for__gTaskFunctionDecl_CullManager_CullBucketTask__);
}

// File Line: 108
// RVA: 0x7F990
void __fastcall Render::CullManager_RasterizeZBuffer(int worker_id, UFG::qMemoryStreamer *memory_streamer, void *main_mem_view_params, void *main_mem_cull_layer_head)
{
  unsigned int v4; // esi
  void *v5; // rdi
  UFG::qMemoryStreamer *v6; // r15
  const char *v7; // r14
  __int64 v8; // rbx
  volatile int *v9; // r15
  int v10; // eax
  __int64 v11; // r9
  int v12; // edi
  int v13; // edx
  const char **v14; // r8
  const char *v15; // rax
  const char *v16; // rax
  const char *v17; // rcx
  signed int v18; // er11
  const char **v19; // r8
  const char **v20; // rcx
  const char *v21; // r10
  signed __int64 v22; // r9
  const char *v23; // rax
  __int64 v24; // r10
  const char *v25; // rcx
  int v26; // er14
  signed __int64 v27; // rdi
  __int64 v28; // r15
  unsigned __int64 v29; // r15
  unsigned int v30; // esi
  signed __int64 v31; // rax
  __int64 v32; // rbx
  __int64 v33; // rcx
  __int64 v34; // rax
  signed __int64 v35; // r13
  __int64 v36; // rax
  signed __int64 v37; // r12
  UFG::qMatrix44 *v38; // rax
  __int64 v39; // r14
  float v40; // xmm15_4
  float v41; // xmm7_4
  float v42; // xmm6_4
  float v43; // xmm8_4
  signed __int64 v44; // rcx
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
  UFG::qMatrix44 result; // [rsp+20h] [rbp-A0h]
  UFG::qVector4 v1; // [rsp+60h] [rbp-60h]
  UFG::qVector4 v0; // [rsp+70h] [rbp-50h]
  __int64 v61; // [rsp+80h] [rbp-40h]
  int v62; // [rsp+88h] [rbp-38h]
  const char *v63; // [rsp+90h] [rbp-30h]
  __int64 v64; // [rsp+98h] [rbp-28h]
  int v65; // [rsp+A0h] [rbp-20h]
  __int64 v66; // [rsp+A8h] [rbp-18h]
  const char **v67; // [rsp+B0h] [rbp-10h]
  const char **v68; // [rsp+B8h] [rbp-8h]
  UFG::qMemoryStreamer *v69; // [rsp+C0h] [rbp+0h]
  const char *v70; // [rsp+C8h] [rbp+8h]
  __int64 v71; // [rsp+D0h] [rbp+10h]
  int v72; // [rsp+D8h] [rbp+18h]
  const char *v73; // [rsp+E0h] [rbp+20h]
  __int64 v74; // [rsp+E8h] [rbp+28h]
  int v75; // [rsp+F0h] [rbp+30h]
  __int64 v76; // [rsp+F8h] [rbp+38h]
  const char **v77; // [rsp+100h] [rbp+40h]
  const char **v78; // [rsp+108h] [rbp+48h]
  volatile int *v; // [rsp+110h] [rbp+50h]
  __int64 v80; // [rsp+118h] [rbp+58h]
  Render::RasterizeZ v81; // [rsp+120h] [rbp+60h]
  bool v82; // [rsp+250h] [rbp+190h]
  int v83; // [rsp+258h] [rbp+198h]
  int v84; // [rsp+260h] [rbp+1A0h]
  __int64 v85; // [rsp+268h] [rbp+1A8h]
  const char *v86; // [rsp+270h] [rbp+1B0h]

  v4 = *((_DWORD *)main_mem_view_params + 26);
  v5 = main_mem_view_params;
  v6 = memory_streamer;
  v7 = (const char *)main_mem_cull_layer_head;
  v8 = 0i64;
  Render::RasterizeZ::Init(&v81, *((void **)main_mem_view_params + worker_id + 8), 0);
  if ( *v81.mZBufferTag != v4 )
  {
    Render::RasterizeZ::Clear(&v81);
    *v81.mZBufferTag = v4;
  }
  UFG::CoverObjectBase::SetCoverObjectGroup((hkDynamicClassNameRegistry *)&v81, (const char *)v5);
  *(_QWORD *)&v0.x = v6;
  *(_QWORD *)&v0.z = "cull_layer_iterator";
  v63 = "cull_layer_iterator";
  v67 = (const char **)&v0.z;
  v69 = v6;
  v9 = (volatile int *)*((_QWORD *)v5 + 14);
  v68 = &v63;
  v70 = "cull_bucket_iterator";
  v73 = "cull_bucket_iterator";
  v77 = &v70;
  v61 = 0i64;
  v62 = 0;
  v78 = &v73;
  v64 = 0i64;
  v65 = 0;
  v66 = 0i64;
  v71 = 0i64;
  v72 = 0;
  v74 = 0i64;
  v75 = 0;
  v76 = 0i64;
  v = v9;
  v10 = UFG::qAtomicAdd(v9, 1);
  v11 = (__int64)v86;
  v12 = 0;
  v13 = v10;
  v83 = 0;
  if ( v7 == v86 )
  {
    v67[1] = 0i64;
    v68[1] = 0i64;
  }
  else
  {
    v68[1] = v7;
  }
  v66 = v11;
LABEL_7:
  v14 = v67;
  v67 = v68;
  v68 = v14;
  v15 = v67[1];
  if ( v15 )
  {
    v16 = (const char *)*((_QWORD *)v15 + 1);
    v17 = 0i64;
    if ( v16 != (const char *)v11 )
      v17 = v16;
    v18 = 0;
    v14[1] = v17;
    v19 = v78;
    v20 = v77;
    LODWORD(v86) = 0;
    while ( 1 )
    {
      v21 = v67[1];
      v22 = (signed __int64)(v21 + 48);
      if ( v18 == 1 )
        v22 = (signed __int64)(v21 + 64);
      v23 = *(const char **)(v22 + 8);
      if ( v23 == (const char *)v22 )
      {
        v20[1] = 0i64;
        v78[1] = 0i64;
      }
      else
      {
        v19[1] = v23;
      }
      v76 = v22;
      while ( 1 )
      {
        v20 = v78;
        v19 = v77;
        v77 = v78;
        v78 = v19;
        v24 = (__int64)v77[1];
        v80 = v24;
        if ( !v24 )
          break;
        v25 = 0i64;
        if ( *(_QWORD *)(v24 + 8) != v22 )
          v25 = *(const char **)(v24 + 8);
        v19[1] = v25;
        v26 = v12 + *(_DWORD *)(v24 + 48);
        v84 = v12 + *(_DWORD *)(v24 + 48);
        if ( *(_QWORD *)(v24 + 24) )
        {
          if ( v13 >= v26 || v13 < v12 )
            goto LABEL_48;
          do
          {
            if ( *(_QWORD *)(v24 + 24) != v8 )
              v8 = *(_QWORD *)(v24 + 24);
            v85 = v8;
            v27 = v8 + ((signed __int64)(v13 - v12) << 7);
            v28 = *(_QWORD *)(v27 + 48);
            if ( v28 )
            {
              v29 = v28 & 0xFFFFFFFFFFFFFFFEui64;
              v82 = v29 != 0;
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
                    v38 = CullInfo::GetLocalWorld((CullInfo *)v27);
                    UFG::qMatrix44::operator*(v38, &result, v81.mWorldViewProjection);
                    v39 = 0i64;
                    if ( *(_DWORD *)(v32 + 108) )
                    {
                      v40 = result.v3.w;
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
                             + v40;
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
                             + v40;
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
                                    + v40;
                        Render::RasterizeZ::Draw2DH(&v81, &v0, &v1, &result.v2);
                        if ( v82 )
                          Render::RasterizeZ::Draw2DH(&v81, &result.v2, &v1, &v0);
                        v39 = (unsigned int)(v39 + 3);
                      }
                      while ( (unsigned int)v39 < *(_DWORD *)(v32 + 108) );
                    }
                  }
                  ++v30;
                }
                while ( v30 < *(_DWORD *)(v29 + 24) );
                v8 = v85;
                v26 = v84;
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
                  &v81,
                  (UFG::qVector3 *)&v1,
                  (UFG::qVector3 *)&result.v3,
                  (UFG::qMatrix44 *)(v27 + 64));
              }
            }
            v9 = v;
            v57 = UFG::qAtomicAdd(v, 1);
            v12 = v83;
            v24 = v80;
            v13 = v57;
          }
          while ( v57 < v26 && v57 >= v83 );
          v22 = v76;
          v12 = v26;
          v83 = v26;
        }
        else
        {
          for ( ; v13 < v26 && v13 >= v12; v13 = UFG::qAtomicAdd(v9, 1) )
            ;
LABEL_48:
          v22 = v76;
          v12 = v26;
          v83 = v26;
        }
      }
      v18 = (_DWORD)v86 + 1;
      LODWORD(v86) = v18;
      if ( v18 >= 2 )
      {
        v11 = v66;
        goto LABEL_7;
      }
    }
  }
}    if ( v18 >= 2 )
      {
        v11 = v66;
        goto LABEL_7;
      }
    }
  }
}

// File Line: 305
// RVA: 0x81180
void __fastcall Render::CompositeZBuffers(UFG::qMemoryStreamer *memory_streamer, Render::RasterizeZ *rasterizer, unsigned int zbuffer_tag, void *main_mem_zbuffer1, void *main_mem_zbuffer2, void *main_mem_zbuffer3, void *main_mem_zbuffer4)
{
  unsigned int v7; // edi
  Render::RasterizeZ *v8; // rbx
  void *v9; // rsi
  Render::RasterizeZ v10; // [rsp+20h] [rbp-48h]

  v7 = zbuffer_tag;
  v8 = rasterizer;
  v9 = main_mem_zbuffer1;
  Render::RasterizeZ::Init(&v10, main_mem_zbuffer1, 0);
  if ( *v10.mZBufferTag == v7 )
    Render::RasterizeZ::Composite(v8, v9);
  Render::RasterizeZ::Init(&v10, main_mem_zbuffer2, 0);
  if ( *v10.mZBufferTag == v7 )
    Render::RasterizeZ::Composite(v8, main_mem_zbuffer2);
  Render::RasterizeZ::Init(&v10, main_mem_zbuffer3, 0);
  if ( *v10.mZBufferTag == v7 )
    Render::RasterizeZ::Composite(v8, main_mem_zbuffer3);
  Render::RasterizeZ::Init(&v10, main_mem_zbuffer4, 0);
  if ( *v10.mZBufferTag == v7 )
    Render::RasterizeZ::Composite(v8, main_mem_zbuffer4);
}

// File Line: 400
// RVA: 0x80180
void __fastcall Render::CullManager_CreateOcclusionMap(int worker_id, UFG::qMemoryStreamer *memory_streamer, void *main_mem_view_params, void *main_mem_occlusion_map_buffer)
{
  void *v4; // rdi
  void *v5; // r14
  void *main_mem_zbuffer2; // r15
  void *main_mem_zbuffer3; // r12
  void *main_mem_zbuffer4; // r13
  unsigned int v9; // ebx
  UFG::qMemoryStreamer *v10; // rbp
  void *v11; // rsi
  Render::OcclusionMap v12; // [rsp+40h] [rbp-88h]
  Render::RasterizeZ rasterizer; // [rsp+60h] [rbp-68h]

  v4 = (void *)*((_QWORD *)main_mem_view_params + 8);
  v5 = (void *)*((_QWORD *)main_mem_view_params + 9);
  main_mem_zbuffer2 = (void *)*((_QWORD *)main_mem_view_params + 10);
  main_mem_zbuffer3 = (void *)*((_QWORD *)main_mem_view_params + 11);
  main_mem_zbuffer4 = (void *)*((_QWORD *)main_mem_view_params + 12);
  v9 = *((_DWORD *)main_mem_view_params + 26);
  v10 = memory_streamer;
  v11 = main_mem_occlusion_map_buffer;
  Render::RasterizeZ::Init(&rasterizer, v4, 0);
  if ( *rasterizer.mZBufferTag != v9 )
  {
    Render::RasterizeZ::Clear(&rasterizer);
    *rasterizer.mZBufferTag = v9;
  }
  Render::CompositeZBuffers(v10, &rasterizer, v9, v5, main_mem_zbuffer2, main_mem_zbuffer3, main_mem_zbuffer4);
  Render::OcclusionMap::Init(&v12, v11);
  Render::OcclusionMap::CreateFromZBuffer(&v12, v4);
}

// File Line: 1237
// RVA: 0x80250
void __fastcall Render::CullManager_CullBucketTask(int worker_id, UFG::qMemoryStreamer *memory_streamer, void *main_mem_view_params, void *main_mem_layer_list_head)
{
  const char *v4; // rdi
  unsigned __int16 *v5; // rbx
  UFG::qMemoryStreamer *v6; // rsi
  __int64 v8; // rcx
  void *v9; // rdx
  __m128 v10; // xmm6
  __m128 v11; // xmm7
  char *v12; // r14
  int v13; // edi
  int v14; // er12
  int v15; // ebx
  signed int v16; // edx
  __m128 v18; // xmm2
  const char **v19; // r9
  __int64 v20; // rax
  const char *v21; // rax
  const char *v22; // rcx
  int v23; // esi
  const char **v24; // r10
  const char **v25; // rcx
  __int64 v26; // r9
  signed __int64 v27; // r11
  const char *v28; // rax
  const char *v29; // r9
  const char *v30; // rcx
  __m128 *v31; // rbx
  __int64 v32; // rsi
  unsigned int v33; // er9
  BOOL v34; // eax
  unsigned int v35; // er15
  int v36; // ecx
  __int64 *v37; // r12
  UFG::qMatrix44 *v38; // r11
  __int64 v39; // rax
  int v40; // edx
  unsigned __int64 v41; // r9
  signed __int64 v42; // rax
  __m128 v43; // xmm0
  __m128 v44; // STB8_16
  __m128 v45; // xmm8
  __m128 v46; // xmm9
  __m128 v47; // xmm10
  __m128 v48; // xmm11
  __m128 v49; // xmm15
  __m128 v50; // ST48_16
  __m128 v51; // xmm12
  __m128 v52; // xmm13
  __m128 v53; // xmm14
  __m128 v54; // xmm6
  __m128 v55; // xmm5
  __m128 v56; // xmm4
  __m128 v57; // xmm6
  __m128 v58; // ST78_16
  __m128 v59; // ST88_16
  __m128 v60; // xmm4
  __m128 v61; // xmm15
  __m128 v62; // xmm0
  __m128 v63; // xmm1
  __m128 v64; // xmm2
  __m128 v65; // xmm4
  __m128 v66; // xmm0
  __m128 v67; // xmm1
  __m128 v68; // xmm2
  __m128 v69; // xmm3
  __m128 v70; // xmm1
  __m128 v71; // xmm2
  __m128 v72; // xmm0
  __m128 v73; // xmm8
  __m128 v74; // xmm9
  __m128 v75; // xmm10
  __m128 v76; // xmm6
  __m128 v77; // xmm7
  __m128 v78; // xmm8
  __m128 v79; // xmm5
  __m128 v80; // xmm3
  __m128 v81; // xmm4
  __m128 v82; // xmm9
  __m128 v83; // xmm12
  float v84; // xmm12_4
  int v85; // xmm6_4
  unsigned int v86; // edi
  int v87; // xmm7_4
  signed __int64 v88; // rax
  unsigned __int64 v89; // r12
  unsigned int v90; // edi
  char *v93; // rax
  __int64 v94; // rcx
  unsigned int v97; // [rsp+30h] [rbp-98h]
  float v98; // [rsp+34h] [rbp-94h]
  BOOL v99; // [rsp+38h] [rbp-90h]
  int v100; // [rsp+3Ch] [rbp-8Ch]
  int v101; // [rsp+40h] [rbp-88h]
  int v102; // [rsp+44h] [rbp-84h]
  __m128 miny; // [rsp+48h] [rbp-80h]
  unsigned int minya; // [rsp+48h] [rbp-80h]
  __m128 v105; // [rsp+58h] [rbp-70h]
  __m128 maxy; // [rsp+68h] [rbp-60h]
  __int64 maxya; // [rsp+68h] [rbp-60h]
  __m128 v108; // [rsp+88h] [rbp-40h]
  __m128 v109; // [rsp+98h] [rbp-30h]
  __m128 v110; // [rsp+A8h] [rbp-20h]
  __m128 v111; // [rsp+C8h] [rbp+0h]
  const char *v112; // [rsp+F8h] [rbp+30h]
  __int64 v113; // [rsp+100h] [rbp+38h]
  int v114; // [rsp+108h] [rbp+40h]
  const char *v115; // [rsp+110h] [rbp+48h]
  __int64 *v116; // [rsp+118h] [rbp+50h]
  const char **v117; // [rsp+120h] [rbp+58h]
  UFG::qMemoryStreamer *v118; // [rsp+128h] [rbp+60h]
  const char *v119; // [rsp+130h] [rbp+68h]
  __int64 v120; // [rsp+138h] [rbp+70h]
  int v121; // [rsp+140h] [rbp+78h]
  const char *v122; // [rsp+148h] [rbp+80h]
  __int64 v123; // [rsp+150h] [rbp+88h]
  int v124; // [rsp+158h] [rbp+90h]
  __int64 i; // [rsp+160h] [rbp+98h]
  const char **v126; // [rsp+168h] [rbp+A0h]
  const char **v127; // [rsp+170h] [rbp+A8h]
  UFG::qLinearAllocator *v128; // [rsp+178h] [rbp+B0h]
  __m128 v129; // [rsp+188h] [rbp+C0h]
  __m128 v130; // [rsp+198h] [rbp+D0h]
  __m128 v131; // [rsp+1A8h] [rbp+E0h]
  __m128 v132; // [rsp+1B8h] [rbp+F0h]
  volatile int *v; // [rsp+1C8h] [rbp+100h]
  const char *ptr; // [rsp+1D0h] [rbp+108h]
  __int64 v135[2]; // [rsp+1D8h] [rbp+110h]
  const char *v136; // [rsp+1E8h] [rbp+120h]
  __m128 v137; // [rsp+208h] [rbp+140h]
  __m128 v138; // [rsp+218h] [rbp+150h]
  __m128 v139; // [rsp+228h] [rbp+160h]
  __m128 v140; // [rsp+238h] [rbp+170h]
  __int64 v141; // [rsp+248h] [rbp+180h]
  char *v142; // [rsp+258h] [rbp+190h]
  Render::OcclusionMap v143; // [rsp+268h] [rbp+1A0h]
  __int64 v144; // [rsp+290h] [rbp+1C8h]
  unsigned int v145; // [rsp+390h] [rbp+2C8h]
  int v146; // [rsp+398h] [rbp+2D0h]
  int v147; // [rsp+3A0h] [rbp+2D8h]
  const char *v148; // [rsp+3A8h] [rbp+2E0h]

  v141 = -2i64;
  v4 = (const char *)main_mem_layer_list_head;
  v5 = (unsigned __int16 *)main_mem_view_params;
  v6 = memory_streamer;
  v102 = 0;
  v100 = 0;
  v112 = "cull_layer_iterator";
  v113 = 0i64;
  v114 = 0;
  v115 = 0i64;
  v116 = (__int64 *)&v116;
  v117 = &v112;
  _R13 = 0i64;
  v142 = 0i64;
  `eh vector constructor iterator'(
    &ptr,
    0x18ui64,
    2,
    (void (__fastcall *)(void *))UFG::qMemoryStream<UFG::AIInterestComponent,432>::qMemoryStream<UFG::AIInterestComponent,432>);
  ptr = "local_world_matrix_stream";
  v136 = "local_world_matrix_stream";
  v128 = (UFG::qLinearAllocator *)*((_QWORD *)v5 + 12);
  v8 = (__int64)v148;
  if ( v4 == v148 )
  {
    v116[1] = 0i64;
    v117[1] = 0i64;
  }
  else
  {
    v117[1] = v4;
  }
  v115 = (const char *)v8;
  v98 = 0.0;
  v9 = (void *)*((_QWORD *)v5 + 8);
  if ( v9 )
  {
    v98 = (float)v5[36];
    Render::OcclusionMap::Init(&v143, v9);
    Render::OcclusionMap::BeginFrame(&v143, (UFG::qMatrix44 *)v5);
  }
  v97 = v5[37];
  maxy.m128_i32[2] = 1 << v97;
  miny.m128_i32[1] = *((_DWORD *)v5 + 20);
  v111 = _mm_shuffle_ps((__m128)*((unsigned int *)v5 + 21), (__m128)*((unsigned int *)v5 + 21), 0);
  v109.m128_u64[0] = 0i64;
  v109.m128_i32[2] = 0;
  v109.m128_i32[3] = *((_DWORD *)v5 + 23);
  v10 = *(__m128 *)v5;
  v137 = *(__m128 *)v5;
  v11 = *((__m128 *)v5 + 1);
  v110 = *((__m128 *)v5 + 1);
  v140 = *((__m128 *)v5 + 2);
  v139 = *((__m128 *)v5 + 3);
  v12 = 0i64;
  v13 = 7;
  v146 = 7;
  v = (volatile int *)*((_QWORD *)v5 + 13);
  v14 = 0;
  v101 = 0;
  v15 = UFG::qAtomicAdd(v, 1);
  v118 = v6;
  v119 = "cull_bucket_iterator";
  v120 = 0i64;
  v121 = 0;
  v122 = "cull_bucket_iterator";
  v123 = 0i64;
  v124 = 0;
  i = 0i64;
  v126 = &v119;
  v127 = &v122;
  v16 = v97;
  _R8 = v97;
  miny.m128_u64[1] = v97;
  v18 = (__m128)(unsigned int)FLOAT_1_0;
  while ( 1 )
  {
    v19 = (const char **)v116;
    v116 = (__int64 *)v117;
    v117 = v19;
    v20 = v116[1];
    if ( !v20 )
      break;
    v21 = *(const char **)(v20 + 8);
    v22 = 0i64;
    if ( v21 != v115 )
      v22 = v21;
    v19[1] = v22;
    v23 = 0;
    minya = 0;
    v24 = v127;
    v25 = v126;
    do
    {
      v26 = v116[1];
      v27 = v26 + 48;
      if ( v23 == 1 )
        v27 = v26 + 64;
      v28 = *(const char **)(v27 + 8);
      if ( v28 == (const char *)v27 )
      {
        v25[1] = 0i64;
        v127[1] = 0i64;
      }
      else
      {
        v24[1] = v28;
      }
      for ( i = v27; ; v27 = i )
      {
        v25 = v127;
        v24 = v126;
        v126 = v127;
        v127 = v24;
        v29 = v126[1];
        if ( !v29 )
          break;
        v30 = 0i64;
        if ( *((_QWORD *)v29 + 1) != v27 )
          v30 = (const char *)*((_QWORD *)v29 + 1);
        v24[1] = v30;
        if ( v14 == v15 )
        {
          v31 = (__m128 *)*((_QWORD *)v29 + 2);
          v32 = *((_QWORD *)v29 + 4);
          v144 = v32;
          v33 = *((_DWORD *)v29 + 12);
          v145 = v33;
          v34 = v32 != 0;
          v99 = v32 != 0;
          if ( v33 )
          {
            v135[0] = v31[3].m128_i64[1];
            if ( !v135[0] )
              v135[0] = 0i64;
          }
          v35 = 0;
          if ( v33 )
          {
            while ( 1 )
            {
              v36 = HIWORD(v31->m128_u64[1]);
              v147 = HIWORD(v31->m128_u64[1]);
              v37 = (__int64 *)&v148;
              if ( v34 )
              {
                v36 = v147;
                if ( v16 <= 16 && v16 >= 0 )
                  v37 = (__int64 *)(v32 + v16);
                else
                  v37 = 0i64;
              }
              v38 = &UFG::qMatrix44::msIdentity;
              v39 = v31[3].m128_i64[1];
              if ( v39 )
              {
                if ( v39 != v135[3 * (v35 & 1)] )
                  v135[3 * (v35 & 1)] = v39;
                v38 = (UFG::qMatrix44 *)v135[3 * (v35 & 1)];
              }
              v40 = v36 + v35;
              if ( v36 + v35 + 1 < v33 )
              {
                v41 = v31[4 * (v36 + 1i64) + 3].m128_u64[1];
                if ( v41 )
                  v135[3 * (((unsigned __int8)v35 - 1) & 1)] = v31[4 * (v36 + 1i64) + 3].m128_i64[1];
                else
                  v135[3 * (((unsigned __int8)v35 - 1) & 1)] = 0i64;
                v33 = v145;
              }
              if ( !(v31[1].m128_i16[7] & maxy.m128_i16[4]) )
                break;
              *(_BYTE *)v37 = 2;
              v35 += v36;
              v42 = (signed __int64)v36 << 6;
              v31 = (__m128 *)((char *)v31 + v42);
              v32 += v42;
              ++v102;
              v100 += v36;
LABEL_68:
              ++v35;
              v31 += 4;
              v32 += 64i64;
              _R8 = miny.m128_u64[1];
              v16 = v97;
              v34 = v99;
              if ( v35 >= v33 )
              {
                v14 = v101;
                goto LABEL_70;
              }
            }
            v43 = (__m128)COERCE_UNSIGNED_INT((float)v31[1].m128_u16[6]);
            if ( v43.m128_f32[0] < v18.m128_f32[0] )
              v43 = v18;
            v44 = _mm_shuffle_ps(v43, v43, 0);
            v45 = (__m128)v38->v0;
            v46 = (__m128)v38->v1;
            v47 = (__m128)v38->v2;
            v48 = (__m128)v38->v3;
            v49 = _mm_shuffle_ps(*v31, _mm_shuffle_ps(*v31, gXYZ0W1, 250), 148);
            v50 = _mm_mul_ps(_mm_shuffle_ps(v48, v48, 0), v10);
            v51 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v45, v45, 0), v10), _xmm),
                        _mm_mul_ps(_mm_shuffle_ps(v45, v45, 85), v11)),
                      _mm_mul_ps(_mm_shuffle_ps(v45, v45, 170), v140)),
                    _mm_mul_ps(_mm_shuffle_ps(v45, v45, 255), v139));
            v52 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v46, v46, 0), v10), (__m128)0i64),
                        _mm_mul_ps(_mm_shuffle_ps(v46, v46, 85), v11)),
                      _mm_mul_ps(_mm_shuffle_ps(v46, v46, 170), v140)),
                    _mm_mul_ps(_mm_shuffle_ps(v46, v46, 255), v139));
            v53 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v47, v47, 0), v10), (__m128)0i64),
                        _mm_mul_ps(_mm_shuffle_ps(v47, v47, 85), v11)),
                      _mm_mul_ps(_mm_shuffle_ps(v47, v47, 170), v140)),
                    _mm_mul_ps(_mm_shuffle_ps(v47, v47, 255), v139));
            v54 = _mm_sub_ps(_mm_shuffle_ps(v31[1], _mm_shuffle_ps(v31[1], gXYZ0W1, 250), 148), v49);
            v55 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v54, v54, 0), v51), (__m128)0i64);
            v56 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v54, v54, 85), v52), (__m128)0i64);
            v57 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v54, v54, 170), v53), (__m128)0i64);
            miny = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_add_ps(
                           _mm_add_ps(_mm_add_ps(v50, (__m128)0i64), _mm_mul_ps(_mm_shuffle_ps(v48, v48, 85), v110)),
                           _mm_mul_ps(_mm_shuffle_ps(v48, v48, 170), v140)),
                         _mm_mul_ps(_mm_shuffle_ps(v48, v48, 255), v139)),
                       _mm_shuffle_ps(v49, v49, 255)),
                     _mm_add_ps(
                       _mm_mul_ps(v53, _mm_shuffle_ps(v49, v49, 170)),
                       _mm_add_ps(
                         _mm_mul_ps(v52, _mm_shuffle_ps(v49, v49, 85)),
                         _mm_add_ps(_mm_mul_ps(v51, _mm_shuffle_ps(v49, v49, 0)), (__m128)0i64))));
            v131 = _mm_add_ps(miny, v55);
            v132 = _mm_add_ps(miny, v56);
            v129 = _mm_add_ps(miny, _mm_add_ps(v56, v55));
            v130 = _mm_add_ps(v131, v57);
            v58 = _mm_add_ps(miny, v57);
            v59 = _mm_add_ps(v129, v57);
            v138 = _mm_add_ps(v132, v57);
            v60 = _mm_shuffle_ps(v129, v109, 239);
            maxy = _mm_shuffle_ps(v129, v129, 164);
            maxy.m128_i16[4] = *(unsigned __int128 *)&_mm_or_ps(
                                                        (__m128)_mm_slli_epi32(
                                                                  _mm_srli_epi32(
                                                                    (__m128i)_mm_cmpltps(
                                                                               maxy,
                                                                               _mm_sub_ps((__m128)0i64, v60)),
                                                                    0x1Fu),
                                                                  0x1Eu),
                                                        (__m128)_mm_slli_epi32((__m128i)_mm_cmpltps(v60, maxy), 0x1Fu)) >> 64;
            v61 = v59;
            v62 = _mm_sub_ps(v59, miny);
            v63 = _mm_add_ps((__m128)0i64, _mm_mul_ps(v62, v62));
            v64 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v63, v63, 85), v63), _mm_shuffle_ps(v63, v63, 170));
            v65 = _mm_add_ps((__m128)0i64, _mm_mul_ps(_mm_rsqrt_ps(v64), v64));
            v66 = _mm_sub_ps((__m128)0i64, _mm_add_ps(_mm_mul_ps(_mm_add_ps(v59, miny), gHalf), (__m128)0i64));
            v67 = _mm_add_ps((__m128)0i64, _mm_mul_ps(v66, v66));
            v68 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v67, v67, 85), v67), _mm_shuffle_ps(v67, v67, 170));
            v108 = _mm_max_ps(
                     _mm_sub_ps(
                       _mm_add_ps((__m128)0i64, _mm_mul_ps(_mm_rsqrt_ps(v68), v68)),
                       _mm_add_ps(_mm_mul_ps(v65, gHalf), (__m128)0i64)),
                     gMinDistance);
            v105 = _mm_add_ps(
                     (__m128)0i64,
                     _mm_mul_ps(
                       _mm_add_ps((__m128)0i64, _mm_mul_ps(v65, v44)),
                       _mm_rcp_ps(_mm_max_ps(gOne, _mm_sub_ps(v108, v111)))));
            v69 = _mm_shuffle_ps(miny, v131, 255);
            v70 = _mm_shuffle_ps(v132, v129, 255);
            v71 = _mm_shuffle_ps(v130, v58, 255);
            v72 = _mm_shuffle_ps(v61, v138, 255);
            v73 = _mm_rcp_ps(_mm_shuffle_ps(_mm_shuffle_ps(v69, v69, 153), _mm_shuffle_ps(v70, v70, 153), 68));
            v74 = _mm_rcp_ps(_mm_shuffle_ps(_mm_shuffle_ps(v71, v71, 153), _mm_shuffle_ps(v72, v72, 153), 68));
            v75 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v73, gXYZ0W1, 240), miny), (__m128)0i64);
            v76 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v73, gXYZ0W1, 245), v131), (__m128)0i64);
            v77 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v73, gXYZ0W1, 250), v132), (__m128)0i64);
            v78 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v73, gXYZ0W1, 255), v129), (__m128)0i64);
            v79 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v74, gXYZ0W1, 240), v130), (__m128)0i64);
            v80 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v74, gXYZ0W1, 245), v58), (__m128)0i64);
            v81 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v74, gXYZ0W1, 250), v61), (__m128)0i64);
            v82 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v74, gXYZ0W1, 255), v138), (__m128)0i64);
            v83 = _mm_max_ps(
                    _mm_min_ps(
                      _mm_min_ps(_mm_min_ps(v75, v76), _mm_min_ps(v77, v78)),
                      _mm_min_ps(_mm_min_ps(v79, v80), _mm_min_ps(v81, v82))),
                    gMinusOne);
            v130 = v83;
            v131 = v83;
            v129 = _mm_min_ps(
                     _mm_max_ps(
                       _mm_max_ps(_mm_max_ps(v75, v76), _mm_max_ps(v77, v78)),
                       _mm_max_ps(_mm_max_ps(v79, v80), _mm_max_ps(v81, v82))),
                     gOne);
            v132 = v129;
            LODWORD(v84) = (unsigned __int128)_mm_shuffle_ps(v83, v83, 255);
            v18 = (__m128)(unsigned int)FLOAT_1_0;
            if ( v84 < 1.0 )
              v84 = *(float *)&FLOAT_1_0;
            minya = (signed int)(float)((float)(1.0 - (float)((float)(v132.m128_f32[1] + 1.0) * 0.5)) * v98);
            maxya = (unsigned int)(signed int)(float)((float)(1.0 - (float)((float)(v131.m128_f32[1] + 1.0) * 0.5)) * v98);
            if ( v84 < 1.0 )
              v84 = *(float *)&FLOAT_1_0;
            v85 = v105.m128_i32[0];
            if ( v105.m128_i32[0] == 2 )
            {
              v86 = 3;
            }
            else
            {
              v86 = v105.m128_i32[0] == 1;
              if ( v105.m128_f32[0] >= 0.0 )
              {
                if ( (_DWORD)maxya == 0 && v105.m128_u64[1] != 0 )
                {
                  if ( !(unsigned int)Render::OcclusionMap::TestRect(
                                        (Render::OcclusionMap *)v105.m128_u64[1],
                                        (signed int)(float)((float)((float)(v130.m128_f32[0] + 1.0) * 0.5) * v98),
                                        minya,
                                        (signed int)(float)((float)((float)(v129.m128_f32[0] + 1.0) * 0.5) * v98),
                                        maxya,
                                        (signed int)(float)((float)(1.0 - (float)(1.0 / v84)) * 65536.0)) )
                    v86 = 5;
                  v18 = (__m128)(unsigned int)FLOAT_1_0;
                  v40 = HIDWORD(maxya);
                  _R8 = miny.m128_u64[1];
                }
                v36 = v147;
              }
              else
              {
                v86 = 4;
              }
            }
            v87 = v108.m128_i32[0];
            if ( (v97 < 6) & (unsigned __int8)v99 )
            {
              *(_DWORD *)(v32 + 4 * _R8 + 16) = v108.m128_i32[0];
              *(_DWORD *)(v32 + 4 * _R8 + 40) = v105.m128_i32[0];
            }
            *(_BYTE *)v37 = v86;
            if ( v86 > 1 )
            {
              v35 = v40;
              v88 = (signed __int64)v36 << 6;
              v31 = (__m128 *)((char *)v31 + v88);
              v32 += v88;
              goto LABEL_66;
            }
            v89 = v31[2].m128_u64[1];
            if ( *(_OWORD *)((char *)&v31[2] + 8) == 0i64 )
            {
LABEL_66:
              v13 = v146;
            }
            else
            {
              v90 = v146;
              if ( v146 == 7 )
              {
                if ( v12 )
                {
                  _RCX = v116[1];
                  __asm { xchg    r13, [rcx+r8*8+50h]; Exchange Register/Memory with Register }
                  *(_QWORD *)v12 = _R13;
                  v87 = v108.m128_i32[0];
                  v85 = v105.m128_i32[0];
                }
                v93 = UFG::qLinearAllocator::Malloc(v128, 0xC0u, 0x20u);
                _R13 = (__int64)v93;
                if ( !v93 )
                  goto LABEL_75;
                v142 = v93;
                v12 = v93;
                v90 = 0;
              }
              v94 = v90;
              *(_QWORD *)&v12[8 * v94 + 24] = v89;
              *(_QWORD *)&v12[8 * v94 + 80] = v31[3].m128_u64[0];
              v12[v94 + 12] = 0;
              *(_DWORD *)&v12[4 * v94 + 164] = v87;
              *(_DWORD *)&v12[4 * v94 + 136] = v85;
              v13 = v90 + 1;
              v146 = v13;
              *((_DWORD *)v12 + 2) = v13;
              v18 = (__m128)(unsigned int)FLOAT_1_0;
            }
            v10 = v137;
            v11 = v110;
            v33 = v145;
            goto LABEL_68;
          }
LABEL_70:
          v15 = UFG::qAtomicAdd(v, 1);
          v18 = (__m128)(unsigned int)FLOAT_1_0;
          _R8 = miny.m128_u64[1];
          v16 = v97;
        }
        v101 = ++v14;
      }
      v23 = minya + 1;
      minya = v23;
    }
    while ( v23 < 2 );
    if ( v13 != 0 && v12 != 0i64 )
    {
      _RCX = v116[1];
      __asm { xchg    r13, [rcx+r8*8+50h]; Exchange Register/Memory with Register }
      *(_QWORD *)v12 = _R13;
      v12 = 0i64;
      v13 = 7;
      v146 = 7;
      _R13 = (__int64)v142;
    }
  }
LABEL_75:
  `eh vector destructor iterator'(&ptr, 0x18ui64, 2, (void (__fastcall *)(void *))_);
}

// File Line: 1718
// RVA: 0x81250
int Render::GetCullResultsAABB(...)
{
  __m128 v6; // ST00_16
  __m128 v7; // ST10_16
  UFG::qVector4 v8; // xmm13
  UFG::qVector4 v9; // xmm11
  UFG::qVector4 v10; // xmm12
  float *v11; // rax
  __m128 v12; // xmm2
  __m128 v13; // xmm4
  __m128 v14; // xmm6
  __m128 v15; // xmm10
  __m128 v16; // xmm0
  float v17; // ST20_4
  __m128 v18; // xmm14
  __m128 v19; // xmm8
  __m128 v20; // xmm7
  __m128 v21; // xmm3
  __m128 v22; // xmm15
  __m128 v23; // xmm0
  __m128 v24; // xmm2
  __m128 v25; // xmm15
  __m128 v26; // ST30_16
  __m128 v27; // xmm5
  __m128 v28; // xmm10
  __m128 v29; // xmm6
  __m128 v30; // xmm9
  __m128 v31; // xmm8
  __m128 v32; // xmm7
  __m128 v33; // xmm1
  __m128 v34; // xmm13
  __m128 v35; // xmm11
  __m128 v36; // xmm0
  __m128 v37; // xmm2
  __m128 v38; // xmm12
  __m128 v39; // xmm1
  __m128 v40; // xmm10
  __m128 v41; // xmm1
  __m128 v42; // xmm6
  __m128 v43; // xmm0
  __m128 v44; // xmm2
  __m128 v45; // xmm1
  __m128 v46; // xmm3
  __m128 v47; // xmm9
  __m128 v48; // xmm1
  __m128i v49; // xmm10
  __m128 v50; // xmm0
  __m128 v51; // xmm10
  __m128 v52; // xmm2
  __m128 v53; // xmm1
  __m128 v54; // xmm13
  __m128i v55; // xmm2
  __m128i v56; // xmm9
  __m128 v57; // xmm0
  __m128 v58; // xmm9
  __m128 v59; // xmm2
  __m128 v60; // xmm1
  __m128 v61; // xmm8
  __m128i v62; // xmm2
  __m128i v63; // xmm13
  __m128 v64; // xmm0
  __m128 v65; // xmm13
  __m128 v66; // xmm2
  __m128 v67; // xmm1
  __m128 v68; // xmm7
  __m128i v69; // xmm2
  __m128i v70; // xmm8
  __m128 v71; // xmm0
  __m128 v72; // xmm8
  __m128 v73; // xmm2
  __m128 v74; // xmm1
  __m128 v75; // xmm7
  __m128 v76; // xmm0
  __m128 v77; // xmm11
  __m128 v78; // xmm0
  __m128 v79; // xmm3
  __m128 v80; // xmm11
  __m128 v81; // xmm4
  __m128 v82; // xmm11
  __m128 v83; // xmm1
  __m128 v84; // xmm1
  __m128 v85; // xmm0
  __m128 v86; // xmm1
  __m128 v87; // xmm4
  __m128 v88; // xmm1
  __m128 v89; // xmm0
  __m128 v90; // xmm3
  float v91; // xmm2_4
  signed __int64 result; // rax
  char v93; // cl
  int v94; // [rsp+108h] [rbp+10h]
  float v95; // [rsp+110h] [rbp+18h]

  v95 = view_pixel_threshold;
  v6.m128_f32[3] = view_far_plane;
  v6.m128_u64[0] = 0i64;
  v6.m128_i32[2] = 0;
  v7 = _mm_shuffle_ps((__m128)distance_bias, (__m128)distance_bias, 0);
  v8 = world_view_proj->v3;
  v9 = world_view_proj->v1;
  v10 = world_view_proj->v2;
  v11 = cull_info->mpLocalWorld;
  v12 = *(__m128 *)v11;
  v13 = *(__m128 *)((char *)v11 + 16);
  v14 = *(__m128 *)((char *)v11 + 32);
  v15 = *(__m128 *)((char *)v11 + 48);
  v16 = (__m128)COERCE_UNSIGNED_INT((float)cull_info->mPixelScaleBias);
  LODWORD(v17) = (unsigned __int128)_mm_shuffle_ps(v16, v16, 0);
  v18 = _mm_shuffle_ps(
          *(__m128 *)cull_info->mAABBMin,
          _mm_shuffle_ps(*(__m128 *)cull_info->mAABBMin, gXYZ0W1, 250),
          148);
  v19 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v12, v12, 0), (__m128)world_view_proj->v0), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps(v12, v12, 85), (__m128)v9)),
            _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)v11, *(__m128 *)v11, 170), (__m128)v10)),
          _mm_mul_ps(_mm_shuffle_ps(v12, v12, 255), (__m128)v8));
  v20 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v13, v13, 0), (__m128)world_view_proj->v0), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps(v13, v13, 85), (__m128)v9)),
            _mm_mul_ps(_mm_shuffle_ps(v13, v13, 170), (__m128)v10)),
          _mm_mul_ps(_mm_shuffle_ps(v13, v13, 255), (__m128)v8));
  v21 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v14, v14, 0), (__m128)world_view_proj->v0), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps(v14, v14, 85), (__m128)v9)),
            _mm_mul_ps(_mm_shuffle_ps(v14, v14, 170), (__m128)v10)),
          _mm_mul_ps(_mm_shuffle_ps(v14, v14, 255), (__m128)v8));
  v22 = _mm_sub_ps(
          _mm_shuffle_ps(
            *(__m128 *)cull_info->mAABBMax,
            _mm_shuffle_ps(*(__m128 *)cull_info->mAABBMax, gXYZ0W1, 250),
            148),
          v18);
  v23 = _mm_shuffle_ps(v22, v22, 85);
  v24 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v22, v22, 0), v19), (__m128)0i64);
  v25 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v22, v22, 170), v21), (__m128)0i64);
  v26 = _mm_add_ps(_mm_mul_ps(v23, v20), (__m128)0i64);
  v27 = _mm_add_ps(
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v15, v15, 0), (__m128)world_view_proj->v0), (__m128)0i64),
                  _mm_mul_ps(_mm_shuffle_ps(v15, v15, 85), (__m128)v9)),
                _mm_mul_ps(_mm_shuffle_ps(v15, v15, 170), (__m128)v10)),
              _mm_mul_ps(_mm_shuffle_ps(v15, v15, 255), (__m128)v8)),
            _mm_shuffle_ps(v18, v18, 255)),
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v18, v18, 0), v19), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps(v18, v18, 85), v20)),
            _mm_mul_ps(_mm_shuffle_ps(v18, v18, 170), v21)));
  v28 = _mm_add_ps(v27, v24);
  v29 = _mm_shuffle_ps(v27, v27, 164);
  v30 = _mm_add_ps(v27, v26);
  v31 = _mm_add_ps(v28, v25);
  v32 = _mm_add_ps(v27, v25);
  v33 = _mm_shuffle_ps(v27, v6, 239);
  v34 = _mm_add_ps(_mm_add_ps(v26, v24), v27);
  v35 = _mm_add_ps(v30, v25);
  v36 = _mm_sub_ps((__m128)0i64, v33);
  v37 = (__m128)_mm_slli_epi32((__m128i)_mm_cmpltps(v33, v29), 0x1Fu);
  v38 = _mm_add_ps(v34, v25);
  v39 = v28;
  v40 = _mm_shuffle_ps(v28, v28, 164);
  v41 = _mm_shuffle_ps(v39, v6, 239);
  v42 = _mm_or_ps((__m128)_mm_slli_epi32(_mm_srli_epi32((__m128i)_mm_cmpltps(v29, v36), 0x1Fu), 0x1Eu), v37);
  v43 = _mm_sub_ps((__m128)0i64, v41);
  v44 = (__m128)_mm_slli_epi32((__m128i)_mm_cmpltps(v41, v40), 0x1Fu);
  v45 = v30;
  v46 = _mm_shuffle_ps(v38, v38, 164);
  v47 = _mm_shuffle_ps(v30, v30, 164);
  v48 = _mm_shuffle_ps(v45, v6, 239);
  v49 = _mm_srli_epi32((__m128i)_mm_cmpltps(v40, v43), 0x1Fu);
  v50 = _mm_sub_ps((__m128)0i64, v48);
  v51 = _mm_or_ps((__m128)_mm_slli_epi32(v49, 0x1Eu), v44);
  v52 = v48;
  v53 = _mm_shuffle_ps(v34, v6, 239);
  v54 = _mm_shuffle_ps(v34, v34, 164);
  v55 = (__m128i)_mm_cmpltps(v52, v47);
  v56 = (__m128i)_mm_cmpltps(v47, v50);
  v57 = _mm_sub_ps((__m128)0i64, v53);
  v58 = _mm_or_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v56, 0x1Fu), 0x1Eu), (__m128)_mm_slli_epi32(v55, 0x1Fu));
  v59 = v53;
  v60 = _mm_shuffle_ps(v31, v6, 239);
  v61 = _mm_shuffle_ps(v31, v31, 164);
  v62 = (__m128i)_mm_cmpltps(v59, v54);
  v63 = (__m128i)_mm_cmpltps(v54, v57);
  v64 = _mm_sub_ps((__m128)0i64, v60);
  v65 = _mm_or_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v63, 0x1Fu), 0x1Eu), (__m128)_mm_slli_epi32(v62, 0x1Fu));
  v66 = v60;
  v67 = _mm_shuffle_ps(v32, v6, 239);
  v68 = _mm_shuffle_ps(v32, v32, 164);
  v69 = (__m128i)_mm_cmpltps(v66, v61);
  v70 = (__m128i)_mm_cmpltps(v61, v64);
  v71 = _mm_sub_ps((__m128)0i64, v67);
  v72 = _mm_or_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v70, 0x1Fu), 0x1Eu), (__m128)_mm_slli_epi32(v69, 0x1Fu));
  v73 = v67;
  v74 = _mm_shuffle_ps(v38, v6, 239);
  v75 = _mm_or_ps(
          (__m128)_mm_slli_epi32(_mm_srli_epi32((__m128i)_mm_cmpltps(v68, v71), 0x1Fu), 0x1Eu),
          (__m128)_mm_slli_epi32((__m128i)_mm_cmpltps(v73, v68), 0x1Fu));
  v76 = v35;
  v77 = _mm_shuffle_ps(v35, v35, 164);
  v78 = _mm_shuffle_ps(v76, v6, 239);
  v79 = _mm_or_ps(
          (__m128)_mm_slli_epi32(_mm_srli_epi32((__m128i)_mm_cmpltps(v46, _mm_sub_ps((__m128)0i64, v74)), 0x1Fu), 0x1Eu),
          (__m128)_mm_slli_epi32((__m128i)_mm_cmpltps(v74, v46), 0x1Fu));
  v80 = _mm_or_ps(
          (__m128)_mm_slli_epi32(_mm_srli_epi32((__m128i)_mm_cmpltps(v77, _mm_sub_ps((__m128)0i64, v78)), 0x1Fu), 0x1Eu),
          (__m128)_mm_slli_epi32((__m128i)_mm_cmpltps(v78, v77), 0x1Fu));
  v81 = _mm_and_ps(
          _mm_and_ps(
            _mm_and_ps(_mm_and_ps(v80, v79), _mm_and_ps(v75, v72)),
            _mm_and_ps(_mm_and_ps(v65, v58), _mm_and_ps(v51, v42))),
          (__m128)gMask_Outcode);
  v82 = _mm_and_ps(
          _mm_or_ps(
            _mm_or_ps(_mm_or_ps(v80, v79), _mm_or_ps(v75, v72)),
            _mm_or_ps(_mm_or_ps(v65, v58), _mm_or_ps(v51, v42))),
          (__m128)gMask_Outcode);
  v83 = _mm_sub_ps(v38, v27);
  v84 = _mm_add_ps(_mm_mul_ps(v83, v83), (__m128)0i64);
  v94 = *(unsigned __int128 *)&_mm_andnot_ps(
                                 (__m128)_mm_cmpeq_epi32(
                                           (__m128i)_mm_or_ps(
                                                      _mm_or_ps(
                                                        _mm_shuffle_ps(v81, v81, 255),
                                                        _mm_shuffle_ps(v81, v81, 170)),
                                                      _mm_or_ps(
                                                        _mm_shuffle_ps(v81, v81, 85),
                                                        _mm_shuffle_ps(v81, v81, 0))),
                                           (__m128i)0i64),
                                 (__m128)_xmm) | *(unsigned __int128 *)&_mm_cmpeq_epi32(
                                                                          (__m128i)_mm_or_ps(
                                                                                     _mm_or_ps(
                                                                                       _mm_shuffle_ps(v82, v82, 85),
                                                                                       _mm_shuffle_ps(v82, v82, 0)),
                                                                                     _mm_or_ps(
                                                                                       _mm_shuffle_ps(v82, v82, 255),
                                                                                       _mm_shuffle_ps(v82, v82, 170))),
                                                                          (__m128i)0i64) & _xmm[0];
  v85 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v84, v84, 85), v84), _mm_shuffle_ps(v84, v84, 170));
  v86 = _mm_sub_ps((__m128)0i64, _mm_add_ps(_mm_mul_ps(_mm_add_ps(v38, v27), gHalf), (__m128)0i64));
  v87 = _mm_add_ps(_mm_mul_ps(_mm_rsqrt_ps(v85), v85), (__m128)0i64);
  v88 = _mm_add_ps(_mm_mul_ps(v86, v86), (__m128)0i64);
  v89 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v88, v88, 85), v88), _mm_shuffle_ps(v88, v88, 170));
  v90 = _mm_max_ps(
          _mm_sub_ps(
            _mm_add_ps(_mm_mul_ps(_mm_rsqrt_ps(v89), v89), (__m128)0i64),
            _mm_add_ps(_mm_mul_ps(v87, gHalf), (__m128)0i64)),
          gMinDistance);
  LODWORD(cull_metrics->mDistance) = v90.m128_i32[0];
  v91 = (float)(COERCE_FLOAT(_mm_rcp_ps(_mm_max_ps(gOne, _mm_sub_ps(v90, v7))))
              * (float)((float)(v87.m128_f32[0] * v17) + 0.0))
      + 0.0;
  cull_metrics->mPixelCoverage = v91;
  if ( v94 == 2 )
    return 3i64;
  v93 = 0;
  if ( v94 == 1 )
    v93 = 1;
  if ( v91 >= v95 )
    result = v93 != 0;
  else
    result = 4i64;
  return result;
}

