// File Line: 45
// RVA: 0x7F350
signed __int64 __fastcall IsLightNear(Render::Light *pLight, float radBoost, float nearplane, UFG::qVector3 *camPosition, UFG::qVector3 *camFacing)
{
  Render::Light *v5; // rdi
  char v6; // cl
  float v7; // xmm7_4
  float v8; // xmm9_4
  signed __int64 result; // rax
  float v10; // xmm8_4
  float v11; // xmm7_4
  float v12; // xmm12_4
  float v13; // xmm10_4
  float v14; // xmm14_4
  float v15; // xmm13_4
  float v16; // xmm9_4
  float v17; // xmm11_4
  float v18; // xmm6_4
  int v19; // esi
  float v20; // xmm0_4
  float v21; // xmm1_4
  signed int v22; // eax

  v5 = pLight;
  v6 = pLight->mType;
  if ( v6 == 1 || v6 == 4 || v6 == 5 && v5->mFovHalfOuter < 1.0 )
  {
    v10 = camPosition->y;
    v11 = camPosition->z;
    v12 = v5->mTransform.v3.z;
    v13 = camPosition->x;
    v14 = v5->mTransform.v3.x;
    v15 = v5->mTransform.v3.y;
    v16 = camFacing->y;
    v17 = camFacing->z;
    v18 = v5->mDecayRadius;
    v19 = ((float)((float)((float)((float)(camFacing->x * (float)(v5->mTransform.v3.x - camPosition->x))
                                 + (float)(camFacing->y * (float)(v5->mTransform.v3.y - v10)))
                         + (float)(camFacing->z * (float)(v12 - v11)))
                 - nearplane) >= 0.0)
        + 1;
    v20 = tanf(v5->mFovHalfOuter) * (float)(v18 * radBoost);
    v21 = (float)((float)((float)(camFacing->x
                                * (float)((float)(v14 - (float)((float)(radBoost * v5->mTransform.v2.x) * v18)) - v13))
                        + (float)(v16
                                * (float)((float)(v15 - (float)((float)(radBoost * v5->mTransform.v2.y) * v18)) - v10)))
                + (float)(v17 * (float)((float)(v12 - (float)((float)(radBoost * v5->mTransform.v2.z) * v18)) - v11)))
        - nearplane;
    if ( v21 < v20 )
    {
      v22 = 3;
      if ( COERCE_FLOAT(LODWORD(v20) ^ _xmm[0]) > v21 )
        v22 = 1;
    }
    else
    {
      v22 = 2;
    }
    if ( v19 == 1 )
    {
      if ( v22 == 1 )
        return 2i64;
    }
    else if ( v19 == 2 && v22 == 2 )
    {
      return 0i64;
    }
    result = 1i64;
  }
  else
  {
    v7 = camPosition->y;
    v8 = camPosition->z;
    result = (float)((float)((float)((float)((float)(v5->mTransform.v3.y - v7) * camFacing->y)
                                   + (float)((float)(v5->mTransform.v3.x - camPosition->x) * camFacing->x))
                           + (float)((float)(v5->mTransform.v3.z - v8) * camFacing->z))
                   - nearplane) < (float)(radBoost * v5->mDecayRadius)
          && (v6 != 5
           || (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(
                                     (float)((float)(v5->mTransform.v2.y * v5->mTransform.v3.y)
                                           + (float)(v5->mTransform.v2.x * v5->mTransform.v3.x))
                                   + (float)(v5->mTransform.v2.z * v5->mTransform.v3.z)) ^ _xmm[0])
                    + (float)((float)((float)((float)(v7 - (float)(v5->mTransform.v2.y * nearplane))
                                            * v5->mTransform.v2.y)
                                    + (float)((float)(camPosition->x - (float)(v5->mTransform.v2.x * nearplane))
                                            * v5->mTransform.v2.x))
                            + (float)((float)(v8 - (float)(v5->mTransform.v2.z * nearplane)) * v5->mTransform.v2.z))) <= 0.000099999997);
  }
  return result;
}

// File Line: 130
// RVA: 0x7E5B0
int __fastcall ClipLightToView(UFG::qVector4 *frustumPlanes, Render::Light *pLight, float scale)
{
  char v3; // al
  Render::Light *v4; // rbx
  UFG::qVector4 *v5; // rdi
  float v7; // xmm7_4
  float v8; // xmm6_4
  float v9; // xmm0_4
  float v10; // xmm7_4
  float v11; // xmm0_4
  signed __int64 v12; // rcx
  float *v13; // rax
  float v14; // xmm7_4
  float v15; // xmm6_4

  v3 = pLight->mType;
  v4 = pLight;
  v5 = frustumPlanes;
  if ( v3 != 1 && v3 != 4 && (v3 != 5 || pLight->mFovHalfOuter >= 1.0) )
    return IntersectSphereFrustum(frustumPlanes, (UFG::qVector3 *)&pLight->mTransform.v3, scale * pLight->mDecayRadius);
  v7 = scale * pLight->mDecayRadius;
  v8 = pLight->mFovHalfOuter;
  v9 = tanf(pLight->mFovHalfOuter);
  v10 = fsqrt((float)((float)(v9 * v7) * (float)(v9 * v7)) + (float)(v7 * v7)) * 0.5;
  v11 = cosf(v8);
  v12 = 0i64;
  v13 = &v5->z;
  v14 = v10 / v11;
  while ( 1 )
  {
    v15 = v14 * 1.01;
    if ( (float)((float)((float)((float)(*(v13 - 1) * (float)(v4->mTransform.v3.y - (float)(v14 * v4->mTransform.v2.y)))
                               + (float)(*(v13 - 2) * (float)(v4->mTransform.v3.x - (float)(v14 * v4->mTransform.v2.x))))
                       + (float)(*v13 * (float)(v4->mTransform.v3.z - (float)(v14 * v4->mTransform.v2.z))))
               + v13[1]) > v15 )
      break;
    ++v12;
    v13 += 4;
    if ( v12 >= 6 )
      return 1;
  }
  return 2;
}

// File Line: 161
// RVA: 0x1457640
__int64 dynamic_initializer_for__gTaskFunctionDecl_UpdateLightingTask__()
{
  UFG::qTaskFunctionDecl::qTaskFunctionDecl(
    &gTaskFunctionDecl_UpdateLightingTask,
    &gTaskFunctionDeclData_UpdateLightingTask);
  return atexit(dynamic_atexit_destructor_for__gTaskFunctionDecl_UpdateLightingTask__);
}

// File Line: 168
// RVA: 0x7DD40
void __fastcall UpdateLightingTask(int workerId, UFG::qMemoryStreamer *memory_streamer, void *param_stream, void *pad0)
{
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm5_4
  unsigned int v7; // er12
  unsigned int v8; // er10
  unsigned int v9; // er15
  char *v10; // r14
  float v11; // xmm9_4
  float v12; // xmm4_4
  float v13; // xmm14_4
  float v14; // xmm9_4
  float v15; // xmm14_4
  int v16; // xmm15_4
  float v17; // xmm0_4
  float v18; // xmm0_4
  signed int v19; // eax
  __int64 v20; // r13
  __int64 v21; // rbx
  char v22; // r9
  unsigned int v23; // er11
  __int64 v24; // r8
  __int64 v25; // rdi
  __int64 v26; // rax
  Render::Light *v27; // rbx
  float v28; // xmm7_4
  float v29; // xmm6_4
  float v30; // xmm8_4
  float v31; // xmm6_4
  float v32; // xmm0_4
  signed __int64 v33; // rcx
  float v34; // xmm6_4
  float v35; // xmm10_4
  float v36; // xmm11_4
  float v37; // xmm12_4
  float v38; // xmm8_4
  float v39; // xmm7_4
  float v40; // xmm1_4
  float v41; // xmm6_4
  char v42; // si
  double v43; // xmm2_8
  float v44; // xmm9_4
  unsigned int v45; // eax
  __int64 v46; // rdx
  float *v47; // rcx
  signed __int64 v48; // rcx
  signed __int64 v49; // rcx
  signed __int64 v50; // rcx
  __int64 v51; // rcx
  void *v52; // rdi
  signed __int64 main_num_bytes; // ST28_8
  void *v54; // rbx
  void *v55; // rsi
  unsigned int *v56; // rcx
  unsigned int *v57; // rdx
  unsigned int *v58; // r8
  float v59; // [rsp+30h] [rbp-D0h]
  unsigned int v60; // [rsp+34h] [rbp-CCh]
  unsigned int v61; // [rsp+38h] [rbp-C8h]
  float v62; // [rsp+3Ch] [rbp-C4h]
  float v63; // [rsp+40h] [rbp-C0h]
  unsigned int v64; // [rsp+44h] [rbp-BCh]
  unsigned int v65; // [rsp+48h] [rbp-B8h]
  float v66; // [rsp+4Ch] [rbp-B4h]
  __int64 v67; // [rsp+50h] [rbp-B0h]
  unsigned int v68; // [rsp+58h] [rbp-A8h]
  float v69; // [rsp+5Ch] [rbp-A4h]
  float v70; // [rsp+60h] [rbp-A0h]
  __int64 v71; // [rsp+68h] [rbp-98h]
  _WORD *local_mem; // [rsp+88h] [rbp-78h]
  char v73; // [rsp+173h] [rbp+73h]
  char *v74; // [rsp+2180h] [rbp+2080h]
  __int64 v75; // [rsp+2188h] [rbp+2088h]
  int v76; // [rsp+2190h] [rbp+2090h]
  void *v77; // [rsp+2198h] [rbp+2098h]
  char v78; // [rsp+2283h] [rbp+2183h]
  char *v79; // [rsp+4290h] [rbp+4190h]
  __int64 v80; // [rsp+4298h] [rbp+4198h]
  int v81; // [rsp+42A0h] [rbp+41A0h]
  void *v82; // [rsp+42A8h] [rbp+41A8h]
  char v83; // [rsp+4393h] [rbp+4293h]
  char *v84; // [rsp+63A0h] [rbp+62A0h]
  __int64 v85; // [rsp+63A8h] [rbp+62A8h]
  int v86; // [rsp+63B0h] [rbp+62B0h]
  void *v87; // [rsp+63B8h] [rbp+62B8h]
  char v88; // [rsp+64A3h] [rbp+63A3h]
  UFG::qMemoryStreamer *v89; // [rsp+E598h] [rbp+E498h]
  char v90; // [rsp+E5A0h] [rbp+E4A0h]

  v89 = memory_streamer;
  v4 = *((float *)param_stream + 43);
  v5 = *((float *)param_stream + 4);
  v6 = *((float *)param_stream + 5);
  v7 = 0;
  v8 = 0;
  v9 = 0;
  v10 = (char *)param_stream;
  v11 = *((float *)param_stream + 8);
  v12 = *((float *)param_stream + 6);
  v13 = *((float *)param_stream + 7);
  v87 = (void *)((unsigned __int64)&v88 & 0xFFFFFFFFFFFFFF80ui64);
  v65 = 0;
  v14 = v11 * v11;
  v15 = v13 * v13;
  v16 = *((_DWORD *)param_stream + 2);
  v70 = v4;
  v17 = *((float *)param_stream + 3);
  v68 = 0;
  v84 = "<unassigned>";
  v69 = v17;
  v18 = FLOAT_2048_0;
  v59 = v5;
  v82 = (void *)((unsigned __int64)&v83 & 0xFFFFFFFFFFFFFF80ui64);
  v85 = 0i64;
  v62 = v6;
  v63 = v12;
  v66 = v14;
  v86 = 0;
  v79 = "<unassigned>";
  local_mem = (_WORD *)((unsigned __int64)&v73 & 0xFFFFFFFFFFFFFF80ui64);
  v80 = 0i64;
  v81 = 0;
  v77 = (void *)((unsigned __int64)&v78 & 0xFFFFFFFFFFFFFF80ui64);
  v19 = *(_DWORD *)param_stream;
  v74 = "<unassigned>";
  v75 = 0i64;
  v76 = 0;
  v61 = 0;
  v64 = 0;
  if ( (float)v19 <= 2048.0 )
    v18 = (float)v19;
  v20 = *((_QWORD *)param_stream + 29);
  v21 = *((_QWORD *)param_stream + 6);
  v22 = 0;
  *(_DWORD *)param_stream = (signed int)v18;
  v23 = *(_DWORD *)v20;
  v24 = 0i64;
  v71 = v21;
  if ( *(_QWORD *)(v20 + 8) )
    v24 = *(_QWORD *)(v20 + 8);
  v25 = 0i64;
  v60 = *(_DWORD *)v20;
  v67 = v24;
  v90 = 0;
  if ( (signed int)v18 )
  {
    while ( 1 )
    {
      if ( (unsigned int)v25 >= v23 )
      {
        v26 = *(_QWORD *)(v20 + 32);
        v20 += 24i64;
        v90 = ++v22;
        if ( v26 )
          v24 = v26;
        v23 += *(_DWORD *)v20;
        v60 = v23;
        v67 = v24;
      }
      v27 = *(Render::Light **)(v21 + 8 * v25);
      if ( v27->mType == 3 )
      {
        if ( v9 < 0x200 )
        {
          v28 = v27->mTransform.v3.x - *((float *)v10 + 40);
          v29 = v27->mTransform.v3.y - *((float *)v10 + 41);
          v30 = v27->mTransform.v3.z - *((float *)v10 + 42);
          if ( (float)((float)((float)(v29 * v27->mTransform.v2.y) + (float)(v28 * v27->mTransform.v2.x))
                     + (float)(v30 * v27->mTransform.v2.z)) < 0.0 )
          {
            v5 = v59;
          }
          else
          {
            if ( ClipLightToView((UFG::qVector4 *)v10 + 4, v27, 1.0) != 2 )
            {
              v31 = (float)((float)((float)(v29 * v29) + (float)(v28 * v28)) + (float)(v30 * v30))
                  - (float)(v27->mDecayRadius * v27->mDecayRadius);
              if ( v31 <= v14 )
              {
                v32 = *(float *)&FLOAT_1_0;
                if ( v31 >= v15 )
                  v32 = 1.0 - (float)((float)(v31 - v15) / (float)(v14 - v15));
                v33 = 2i64 * v9++;
                *((_WORD *)v77 + 4 * v33) = v25;
                v64 = v9;
                *((float *)v77 + 2 * v33 + 3) = v32 * *(float *)(v20 + 16);
              }
            }
            v5 = v59;
            v12 = v63;
            v6 = v62;
            v24 = v67;
            v22 = v90;
            v8 = v61;
            v23 = v60;
          }
        }
        goto LABEL_44;
      }
      v34 = *(float *)&FLOAT_1_0;
      v35 = *((float *)v10 + 40);
      v36 = *((float *)v10 + 41);
      v37 = *((float *)v10 + 42);
      v38 = v27->mDecayRadius;
      v39 = (float)((float)((float)(v27->mTransform.v3.y - v36) * *((float *)v10 + 45))
                  + (float)((float)(v27->mTransform.v3.x - v35) * *((float *)v10 + 44)))
          + (float)((float)(v27->mTransform.v3.z - v37) * *((float *)v10 + 46));
      v40 = v39 / v38;
      if ( (float)(v39 / v38) > v69 )
        goto LABEL_43;
      if ( v40 > v5 )
        v34 = 1.0 - (float)((float)(v40 - v5) / (float)(v69 - v5));
      v41 = v34 * *(float *)(v20 + 16);
      if ( (float)(v38 * v41) < 0.001 )
        goto LABEL_43;
      v42 = 0;
      if ( v6 > v39 )
        v42 = 2;
      if ( v39 <= v12 )
        v43 = 0.0;
      else
        v43 = (float)((float)(v39 - v12) / (float)(v6 - v12));
      v44 = v43;
      if ( ClipLightToView((UFG::qVector4 *)v10 + 4, v27, v41) == 2
        || (v45 = IsLightNear(
                    v27,
                    v41 * 1.05,
                    *((float *)v10 + 10),
                    (UFG::qVector3 *)(v10 + 160),
                    (UFG::qVector3 *)(v10 + 176)),
            v45 == 2) )
      {
        v24 = v67;
        goto LABEL_47;
      }
      if ( v10[36] )
      {
        v46 = 0i64;
        if ( v27->mClipPlaneCount )
        {
          while ( 1 )
          {
            v47 = (float *)(v67 + 16i64 * (unsigned __int8)v27->mClipPlanes[v46]);
            if ( (float)((float)((float)((float)(v36 * v47[1]) + (float)(v35 * *v47)) + (float)(v37 * v47[2])) + v47[3]) < 0.0 )
              break;
            v46 = (unsigned int)(v46 + 1);
            if ( (unsigned int)v46 >= (unsigned __int8)v27->mClipPlaneCount )
              goto LABEL_34;
          }
          v24 = v67;
LABEL_47:
          v14 = v66;
          v6 = v62;
          v12 = v63;
          v22 = v90;
          v5 = v59;
LABEL_42:
          v8 = v61;
          v23 = v60;
LABEL_43:
          v7 = v65;
          v9 = v64;
          goto LABEL_44;
        }
      }
LABEL_34:
      v22 = v90;
      v5 = v59;
      v12 = v63;
      v24 = v67;
      v6 = v62;
      if ( v45 != 1 )
        break;
      v8 = v61;
      v9 = v64;
      v7 = v65;
      v23 = v60;
      if ( v61 >= 0x200 )
        goto LABEL_40;
      v48 = 2i64 * v61;
      v8 = v61 + 1;
      local_mem[4 * v48] = v25;
      ++v61;
      *(float *)(((unsigned __int64)&v73 & 0xFFFFFFFFFFFFFF80ui64) + 8 * v48 + 4) = v41;
      *(_DWORD *)(((unsigned __int64)&v73 & 0xFFFFFFFFFFFFFF80ui64) + 8 * v48 + 0xC) = v16;
      *(_BYTE *)(((unsigned __int64)&v73 & 0xFFFFFFFFFFFFFF80ui64) + 8 * v48 + 2) = v42;
      *(float *)(((unsigned __int64)&v73 & 0xFFFFFFFFFFFFFF80ui64) + 8 * v48 + 8) = v44;
      v14 = v66;
      *(_BYTE *)(((unsigned __int64)&v73 & 0xFFFFFFFFFFFFFF80ui64) + 8 * v48 + 3) = v90;
LABEL_44:
      v21 = v71;
      v25 = (unsigned int)(v25 + 1);
      if ( (unsigned int)v25 >= *(_DWORD *)v10 )
        goto LABEL_45;
    }
    if ( (float)(v38 / v39) <= v70 )
    {
      v50 = 2i64 * v68;
      *((_WORD *)v87 + 4 * v50) = v25;
      ++v68;
      *((float *)v87 + 2 * v50 + 1) = v41;
      *((_DWORD *)v87 + 2 * v50 + 3) = v16;
      *((_BYTE *)v87 + 8 * v50 + 2) = v42;
      *((float *)v87 + 2 * v50 + 2) = v44;
      v14 = v66;
      *((_BYTE *)v87 + 8 * v50 + 3) = v90;
      goto LABEL_42;
    }
    v7 = v65;
    v9 = v64;
    v8 = v61;
    v23 = v60;
    if ( v65 < 0x200 )
    {
      v49 = 2i64 * v65;
      v7 = v65 + 1;
      *((_WORD *)v82 + 4 * v49) = v25;
      ++v65;
      *((float *)v82 + 2 * v49 + 1) = v41;
      *((_DWORD *)v82 + 2 * v49 + 3) = v16;
      *((_BYTE *)v82 + 8 * v49 + 2) = v42;
      *((float *)v82 + 2 * v49 + 2) = v44;
      *((_BYTE *)v82 + 8 * v49 + 3) = v90;
    }
LABEL_40:
    v14 = v66;
    goto LABEL_44;
  }
LABEL_45:
  v51 = *((_QWORD *)v10 + 24);
  v52 = (void *)(v51 + 16i64 * (v8 + v7));
  main_num_bytes = 16i64 * v8;
  v54 = (void *)(v51 + main_num_bytes);
  v55 = (void *)(v51 + 16i64 * (v7 + v8 + v68));
  UFG::qMemoryStreamer::BeginRawWritePlat(
    v89,
    "<unassigned>",
    local_mem,
    0x2000ui64,
    *((void **)v10 + 24),
    main_num_bytes);
  UFG::qMemoryStreamer::BeginRawWritePlat(v89, v79, v82, 0x2000ui64, v54, 16i64 * v7);
  UFG::qMemoryStreamer::BeginRawWritePlat(v89, v84, v87, 0x8000ui64, v52, 16i64 * v68);
  UFG::qMemoryStreamer::BeginRawWritePlat(v89, v74, v77, 0x2000ui64, v55, 16i64 * v9);
  v56 = (unsigned int *)*((_QWORD *)v10 + 26);
  v57 = (unsigned int *)*((_QWORD *)v10 + 27);
  v58 = (unsigned int *)*((_QWORD *)v10 + 28);
  **((_DWORD **)v10 + 25) = v61;
  *v56 = v7;
  *v57 = v68;
  *v58 = v9;
}

// File Line: 426
// RVA: 0x7E6F0
int DrawLight(...)
{
  __m128 fFar; // xmm6
  Render::Light *v5; // rdi
  LightingTaskVars *v6; // rsi
  Illusion::SubmitContext *v7; // r15
  char *v8; // rbx
  float v9; // xmm4_4
  float v10; // xmm8_4
  float v11; // xmm5_4
  float v12; // xmm0_4
  float *v13; // rax
  float v14; // xmm3_4
  float v15; // xmm2_4
  float v16; // xmm8_4
  float fAspectRatio; // xmm7_4
  float v18; // xmm3_4
  float v19; // xmm2_4
  float v20; // xmm0_4
  float v21; // xmm0_4
  unsigned int v22; // edx
  char v23; // cl
  float *v24; // rax
  float v25; // xmm10_4
  float v26; // xmm9_4
  float v27; // xmm8_4
  char *v28; // rax
  float v29; // xmm2_4
  float v30; // xmm9_4
  UFG::qVector4 v31; // xmm2
  UFG::qVector4 v32; // xmm1
  UFG::qVector4 v33; // xmm0
  Illusion::Mesh *v34; // rbx
  __m128 v35; // xmm0
  __m128 v36; // xmm3
  __m128 v37; // xmm3
  float v38; // xmm3_4
  float v39; // xmm8_4
  __m128 v40; // xmm0
  __m128 v41; // xmm3
  __m128 v42; // xmm3
  UFG::qMatrix44 *v43; // r12
  Illusion::StateArgs *v44; // rdi
  unsigned __int16 v45; // ax
  unsigned __int16 v46; // ax
  unsigned __int16 v47; // ax
  __int64 v48; // rcx
  _QWORD *v49; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v50; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v51; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v52; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v53; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v54; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v55; // rax
  char *v56; // rax
  __int64 v57; // rcx
  _QWORD *v58; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v59; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v60; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v61; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v62; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v63; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v64; // rax
  UFG::qMatrix44 local_world; // [rsp+40h] [rbp-88h]
  Render::cbLocalProjectionState v66; // [rsp+80h] [rbp-48h]
  Render::cbLocalTransformState v67; // [rsp+B8h] [rbp-10h]
  Render::cbShadowTransformState arg; // [rsp+E8h] [rbp+20h]
  __int128 v69; // [rsp+148h] [rbp+80h]
  __int64 v70; // [rsp+158h] [rbp+90h]
  char v71; // [rsp+160h] [rbp+98h]
  UFG::qMatrix44 shadowWorldView; // [rsp+178h] [rbp+B0h]
  UFG::qMatrix44 shadowProjection; // [rsp+1B8h] [rbp+F0h]
  char *v74; // [rsp+298h] [rbp+1D0h]
  char *v75; // [rsp+2A0h] [rbp+1D8h]
  int v76; // [rsp+2B8h] [rbp+1F0h]
  float vars0; // [rsp+2C0h] [rbp+1F8h]
  void *retaddr; // [rsp+2C8h] [rbp+200h]

  v70 = -2i64;
  fFar = _mm_shuffle_ps((__m128)lightRad, (__m128)lightRad, 0);
  v5 = light;
  v6 = vars;
  v7 = vars->submitContext;
  if ( (_BYTE)retaddr )
  {
LABEL_24:
    fAspectRatio = *(float *)&FLOAT_1_0;
    goto LABEL_25;
  }
  v8 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x40u, 0x10u);
  v9 = v5->mTransform.v3.x;
  v10 = v5->mTransform.v3.y;
  v11 = v5->mTransform.v3.z;
  if ( v5->mType == 5 )
  {
    v12 = v5->mAreaLightNearOffset;
    v9 = (float)((float)(v5->mTransform.v2.x * v12) * 0.5) + v9;
    v10 = (float)((float)(v5->mTransform.v2.y * v12) * 0.5) + v10;
    v11 = (float)((float)(v5->mTransform.v2.z * v12) * 0.5) + v11;
  }
  v13 = (float *)v6->taskParams_Local.mMainMemoryAddress;
  v14 = (float)((float)((float)(v10 * v13[4]) + (float)(v9 * *v13)) + (float)(v11 * v13[8])) + v13[12];
  v15 = (float)((float)((float)(v10 * v13[5]) + (float)(v9 * v13[1])) + (float)(v11 * v13[9])) + v13[13];
  v16 = (float)((float)((float)(v10 * v13[6]) + (float)(v9 * v13[2])) + (float)(v11 * v13[10])) + v13[14];
  *(float *)v8 = v14;
  *((float *)v8 + 1) = v15;
  *((float *)v8 + 2) = v16;
  *((_DWORD *)v8 + 3) = LODWORD(v5->mDecayPower);
  fAspectRatio = *(float *)&FLOAT_1_0;
  if ( v5->mType == 5 )
    v18 = v5->mAreaLightIntensityScale;
  else
    v18 = *(float *)&FLOAT_1_0;
  v19 = vars0;
  *((float *)v8 + 4) = (float)((float)(vars0 * v5->mColor.x) * (float)(vars0 * v5->mColor.x)) * v18;
  *((float *)v8 + 5) = (float)((float)(v19 * v5->mColor.y) * (float)(v19 * v5->mColor.y)) * v18;
  *((float *)v8 + 6) = (float)((float)(v19 * v5->mColor.z) * (float)(v19 * v5->mColor.z)) * v18;
  if ( v5->mType == 5 )
    v20 = (float)(v5->mAreaLightNearOffset * 0.5) + fFar.m128_f32[0];
  else
    v20 = fFar.m128_f32[0];
  *((float *)v8 + 7) = 1.0 / powf(v20, *((float *)v8 + 3) + 1.0);
  *((float *)v8 + 8) = cosf(v5->mFovHalfInner);
  *((float *)v8 + 9) = cosf(v5->mFovHalfOuter);
  *((_DWORD *)v8 + 10) = v76;
  if ( v5->mTexDistAttenUID == -1 )
    v21 = FLOAT_N1_0;
  else
    v21 = v5->mTexDistAttenV;
  *((float *)v8 + 11) = v21;
  *((_DWORD *)v8 + 12) = LODWORD(v5->mAreaLightWidth);
  *((_DWORD *)v8 + 13) = LODWORD(v5->mAreaLightHeight);
  *((_DWORD *)v8 + 14) = LODWORD(v5->mAreaLightNearOffset);
  *((_DWORD *)v8 + 15) = LODWORD(v5->mAreaLightFarOffset);
  v22 = *((signed __int16 *)v6->paramIndices_Local.mMainMemoryAddress + 14);
  v23 = *((_WORD *)v6->paramIndices_Local.mMainMemoryAddress + 14);
  if ( v22 >= 0x40 )
    v7->mStateValues.mSetValueMask.mFlags[1] |= 1i64 << (v23 - 64);
  else
    v7->mStateValues.mSetValueMask.mFlags[0] |= 1i64 << v23;
  v7->mStateValues.mParamValues[(signed __int16)v22] = v8;
  v24 = (float *)v6->taskParams_Local.mMainMemoryAddress;
  if ( *((_BYTE *)v24 + 217) )
  {
    v25 = v24[55];
    if ( v25 <= (float)(COERCE_FLOAT(LODWORD(v16) ^ _xmm[0]) - fFar.m128_f32[0]) )
      v25 = COERCE_FLOAT(LODWORD(v16) ^ _xmm[0]) - fFar.m128_f32[0];
    if ( (float)(fFar.m128_f32[0] - v16) >= 1.0 )
      fAspectRatio = fFar.m128_f32[0] - v16;
    v26 = v24[55];
    v27 = v24[56];
    v28 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0xCu, 0x10u);
    v74 = v28;
    v75 = v28;
    if ( v28 )
    {
      *(_DWORD *)v28 = 1;
      v29 = v27 * v26;
      v30 = v26 - v27;
      *((float *)v28 + 1) = (float)((float)(v27 * v25) - v29) / COERCE_FLOAT(COERCE_UNSIGNED_INT(v30 * v25) ^ _xmm[0]);
      *((float *)v28 + 2) = (float)((float)(v27 * fAspectRatio) - v29)
                          / COERCE_FLOAT(COERCE_UNSIGNED_INT(v30 * fAspectRatio) ^ _xmm[0]);
    }
    v7->vfptr->AddRenderCommand(v7, 25, 0, v28);
    goto LABEL_24;
  }
LABEL_25:
  v31 = v5->mTransform.v1;
  v32 = v5->mTransform.v2;
  v33 = v5->mTransform.v3;
  local_world.v0 = v5->mTransform.v0;
  local_world.v1 = v31;
  local_world.v2 = v32;
  local_world.v3 = v33;
  v34 = 0i64;
  if ( v5->mType )
  {
    switch ( v5->mType )
    {
      case 1:
        goto LABEL_63;
      case 2:
        return;
      case 4:
LABEL_63:
        v39 = v5->mFovHalfOuter;
        v40 = (__m128)LODWORD(v5->mFovHalfOuter);
        v40.m128_f32[0] = tanf(v40.m128_f32[0]);
        v41 = v40;
        v41.m128_f32[0] = v40.m128_f32[0] * fFar.m128_f32[0];
        v42 = _mm_shuffle_ps(v41, v41, 0);
        local_world.v0 = (UFG::qVector4)_mm_mul_ps((__m128)local_world.v0, v42);
        local_world.v1 = (UFG::qVector4)_mm_mul_ps((__m128)local_world.v1, v42);
        local_world.v2 = (UFG::qVector4)_mm_mul_ps((__m128)local_world.v2, fFar);
        v34 = (Illusion::Mesh *)*((_QWORD *)v6->taskParams_Local.mMainMemoryAddress + 53);
        if ( !(_BYTE)retaddr )
          Render::BuildShadowSpotView(
            &shadowWorldView,
            &shadowProjection,
            &v5->mTransform,
            v5->mShadowNear,
            fFar.m128_f32[0],
            v39 * 2.0,
            fAspectRatio);
        break;
      case 5:
        v35 = (__m128)LODWORD(v5->mFovHalfOuter);
        if ( v35.m128_f32[0] >= fAspectRatio )
        {
          local_world.v0 = (UFG::qVector4)_mm_mul_ps((__m128)local_world.v0, fFar);
          local_world.v1 = (UFG::qVector4)_mm_mul_ps((__m128)local_world.v1, fFar);
          local_world.v2 = (UFG::qVector4)_mm_mul_ps((__m128)local_world.v2, fFar);
          v34 = (Illusion::Mesh *)*((_QWORD *)v6->taskParams_Local.mMainMemoryAddress + 52);
        }
        else
        {
          v35.m128_f32[0] = tanf(v35.m128_f32[0]);
          v36 = v35;
          v36.m128_f32[0] = v35.m128_f32[0] * fFar.m128_f32[0];
          v37 = _mm_shuffle_ps(v36, v36, 0);
          local_world.v0 = (UFG::qVector4)_mm_mul_ps((__m128)local_world.v0, v37);
          local_world.v1 = (UFG::qVector4)_mm_mul_ps((__m128)local_world.v1, v37);
          local_world.v2 = (UFG::qVector4)_mm_mul_ps((__m128)local_world.v2, fFar);
          v34 = (Illusion::Mesh *)*((_QWORD *)v6->taskParams_Local.mMainMemoryAddress + 53);
        }
        if ( !(_BYTE)retaddr )
        {
          v38 = v5->mShadowNear;
          if ( v38 <= (float)(v5->mAreaLightNearOffset * 0.5) )
            v38 = v5->mAreaLightNearOffset * 0.5;
          Render::BuildShadowSpotView(
            &shadowWorldView,
            &shadowProjection,
            &v5->mTransform,
            v38,
            fFar.m128_f32[0],
            v5->mFovHalfInner * 2.0,
            v5->mAreaLightWidth / v5->mAreaLightHeight);
        }
        break;
    }
  }
  else
  {
    local_world.v0 = (UFG::qVector4)_mm_mul_ps((__m128)local_world.v0, fFar);
    local_world.v1 = (UFG::qVector4)_mm_mul_ps((__m128)local_world.v1, fFar);
    local_world.v2 = (UFG::qVector4)_mm_mul_ps((__m128)local_world.v2, fFar);
    v34 = (Illusion::Mesh *)*((_QWORD *)v6->taskParams_Local.mMainMemoryAddress + 52);
  }
  v43 = (UFG::qMatrix44 *)v6->taskParams_Local.mMainMemoryAddress;
  v44 = &v6->submitContext->mStateArgs;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mCallback = 0i64;
  arg.mStateParamIndex = Render::cbShadowTransformState::sStateParamIndex;
  *(_WORD *)&arg.mFlags = 1;
  if ( (_WORD)Render::cbShadowTransformState::sStateParamIndex == -1 )
  {
    v45 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbShadowTransform");
    Render::cbShadowTransformState::sStateParamIndex = v45;
    arg.mStateParamIndex = v45;
  }
  arg.mViewWorld = &v6->viewWorld;
  arg.mWorldView = &shadowWorldView;
  arg.mProjection = &shadowProjection;
  arg.mCutplanes = 0i64;
  _mm_store_si128((__m128i *)&arg.mBiases, (__m128i)0i64);
  arg.mCached_Remote.m_Stream = 0i64;
  Render::cbLocalTransformState::cbLocalTransformState(&v67, v43, &v6->worldViewProjection, &local_world);
  v66.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v66;
  v66.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v66;
  v66.mCallback = 0i64;
  v66.mStateParamIndex = Render::cbLocalProjectionState::sStateParamIndex;
  *(_WORD *)&v66.mFlags = 1;
  if ( (_WORD)Render::cbLocalProjectionState::sStateParamIndex == -1 )
  {
    v46 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalProjection");
    Render::cbLocalProjectionState::sStateParamIndex = v46;
    v66.mStateParamIndex = v46;
  }
  v66.mCached_Remote.m_Stream = 0i64;
  v66.mWorldViewProjection = &v6->worldViewProjection;
  v66.mLocalWorld = &local_world;
  *(_QWORD *)&local_world.v0.z = (char *)&local_world + 8;
  *(_QWORD *)&local_world.v1.x = (char *)&local_world + 8;
  *(_QWORD *)&local_world.v1.z = 0i64;
  LOWORD(local_world.v2.x) = Render::cbLocalTransformInverseState::sStateParamIndex;
  HIWORD(local_world.v2.x) = 1;
  if ( (_WORD)Render::cbLocalTransformInverseState::sStateParamIndex == -1 )
  {
    v47 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalTransformInverse");
    Render::cbLocalTransformInverseState::sStateParamIndex = v47;
    LOWORD(local_world.v2.x) = v47;
  }
  *(_QWORD *)&local_world.v3.z = 0i64;
  *(_QWORD *)&local_world.v2.z = v43;
  *(_QWORD *)&local_world.v3.x = &local_world;
  Illusion::StateArgs::Set<Render::cbShadowTransformState>(v44, &arg);
  Illusion::StateArgs::Set<Render::cbLocalTransformState>(v44, &v67);
  Illusion::StateArgs::Set<Render::cbLocalProjectionState>(v44, &v66);
  Illusion::StateArgs::Set<Render::cbLocalTransformInverseState>(
    v44,
    (Render::cbLocalTransformInverseState *)&local_world.v0.z);
  v69 = 0ui64;
  _mm_store_si128((__m128i *)&v69, (__m128i)0i64);
  Illusion::SubmitContext::Draw(v7, (UFG::BitFlags128 *)&v71, v34, 0i64, (UFG::BitFlags128 *)&v69, v34);
  v48 = *(_QWORD *)&local_world.v0.z;
  v49 = *(_QWORD **)&local_world.v1.x;
  *(_QWORD *)(*(_QWORD *)&local_world.v0.z + 8i64) = *(_QWORD *)&local_world.v1.x;
  *v49 = v48;
  *(_QWORD *)&local_world.v0.z = (char *)&local_world + 8;
  *(_QWORD *)&local_world.v1.x = (char *)&local_world + 8;
  HIBYTE(local_world.v2.x) = 0;
  if ( (Illusion::StateArgs *)v44->mStateArgsCreateMask.mFlags[2 * (SLOWORD(local_world.v2.x) + 3i64) + 1] == (Illusion::StateArgs *)((char *)v44 + 16 * (SLOWORD(local_world.v2.x) + 3i64)) )
    v44->mStateArgsCreateMask.mFlags[(unsigned int)SLOWORD(local_world.v2.x) >> 6] &= ~(1i64 << (LOBYTE(local_world.v2.x) & 0x3F));
  v50 = v66.mPrev;
  v51 = v66.mNext;
  v66.mPrev->mNext = v66.mNext;
  v51->mPrev = v50;
  v66.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v66;
  v66.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v66;
  v66.mIsSet = 0;
  if ( (Illusion::StateArgs *)v44->mStateArgsCreateMask.mFlags[2 * (v66.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v44 + 16 * (v66.mStateParamIndex + 3i64)) )
    v44->mStateArgsCreateMask.mFlags[(unsigned int)v66.mStateParamIndex >> 6] &= ~(1i64 << (v66.mStateParamIndex & 0x3F));
  v52 = v67.mPrev;
  v53 = v67.mNext;
  v67.mPrev->mNext = v67.mNext;
  v53->mPrev = v52;
  v67.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v67;
  v67.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v67;
  v67.mIsSet = 0;
  if ( (Illusion::StateArgs *)v44->mStateArgsCreateMask.mFlags[2 * (v67.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v44 + 16 * (v67.mStateParamIndex + 3i64)) )
    v44->mStateArgsCreateMask.mFlags[(unsigned int)v67.mStateParamIndex >> 6] &= ~(1i64 << (v67.mStateParamIndex & 0x3F));
  v54 = arg.mPrev;
  v55 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v55->mPrev = v54;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mIsSet = 0;
  if ( (Illusion::StateArgs *)v44->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v44 + 16 * (arg.mStateParamIndex + 3i64)) )
    v44->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
  if ( !(_BYTE)retaddr && *((_BYTE *)v6->taskParams_Local.mMainMemoryAddress + 217) )
  {
    v56 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0xCu, 0x10u);
    v74 = v56;
    v75 = v56;
    if ( v56 )
    {
      *(_QWORD *)v56 = 0i64;
      *((_DWORD *)v56 + 2) = 0;
    }
    v7->vfptr->AddRenderCommand(v7, 25, 0, v56);
  }
  v57 = *(_QWORD *)&local_world.v0.z;
  v58 = *(_QWORD **)&local_world.v1.x;
  *(_QWORD *)(*(_QWORD *)&local_world.v0.z + 8i64) = *(_QWORD *)&local_world.v1.x;
  *v58 = v57;
  v59 = v66.mPrev;
  v60 = v66.mNext;
  v66.mPrev->mNext = v66.mNext;
  v60->mPrev = v59;
  v61 = v67.mPrev;
  v62 = v67.mNext;
  v67.mPrev->mNext = v67.mNext;
  v62->mPrev = v61;
  v63 = arg.mPrev;
  v64 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v64->mPrev = v63;
}

// File Line: 613
// RVA: 0x7F680
void __fastcall SetLightMaterialState(LightingTaskVars *vars, Render::Light *light, float lightRadius, bool useStencil, bool isNear, Illusion::Texture *resolvedTexture, Illusion::Texture *resolvedDistAttenTexture)
{
  Illusion::SubmitContext *v7; // r8
  void *v8; // rdi
  unsigned int v9; // er11
  LightingTaskVars *v10; // r10
  bool v11; // si
  char v12; // cl
  void *v13; // r11
  unsigned int v14; // er9
  char v15; // cl
  void *v16; // r11
  unsigned int v17; // er9
  char v18; // cl
  void *v19; // r11
  unsigned int v20; // er9
  char v21; // cl
  void *v22; // rcx
  void **v23; // rax
  void **v24; // rcx
  void *v25; // r11
  bool v26; // cl
  char v27; // r9
  void **v28; // rax
  void *v29; // rax
  Illusion::Texture *v30; // r9
  unsigned int v31; // er10
  char v32; // cl
  void **v33; // rax
  void *v34; // rax
  Illusion::Texture *v35; // r9
  unsigned int v36; // ebx
  char v37; // cl

  v7 = vars->submitContext;
  v8 = (void *)*((_QWORD *)vars->taskParams_Local.mMainMemoryAddress + 40);
  v9 = *(signed __int16 *)vars->paramIndices_Local.mMainMemoryAddress;
  v10 = vars;
  v11 = useStencil;
  v12 = *(_WORD *)vars->paramIndices_Local.mMainMemoryAddress;
  if ( v9 >= 0x40 )
    v7->mStateValues.mSetValueMask.mFlags[1] |= 1i64 << (v12 - 64);
  else
    v7->mStateValues.mSetValueMask.mFlags[0] |= 1i64 << v12;
  v7->mStateValues.mParamValues[(signed __int16)v9] = v8;
  v13 = (void *)*((_QWORD *)v10->taskParams_Local.mMainMemoryAddress + 41);
  v14 = *((signed __int16 *)v10->paramIndices_Local.mMainMemoryAddress + 2);
  v15 = *((_WORD *)v10->paramIndices_Local.mMainMemoryAddress + 2);
  if ( v14 >= 0x40 )
    v7->mStateValues.mSetValueMask.mFlags[1] |= 1i64 << (v15 - 64);
  else
    v7->mStateValues.mSetValueMask.mFlags[0] |= 1i64 << v15;
  v7->mStateValues.mParamValues[(signed __int16)v14] = v13;
  v16 = (void *)*((_QWORD *)v10->taskParams_Local.mMainMemoryAddress + 43);
  v17 = *((signed __int16 *)v10->paramIndices_Local.mMainMemoryAddress + 4);
  v18 = *((_WORD *)v10->paramIndices_Local.mMainMemoryAddress + 4);
  if ( v17 >= 0x40 )
    v7->mStateValues.mSetValueMask.mFlags[1] |= 1i64 << (v18 - 64);
  else
    v7->mStateValues.mSetValueMask.mFlags[0] |= 1i64 << v18;
  v7->mStateValues.mParamValues[(signed __int16)v17] = v16;
  v19 = (void *)*((_QWORD *)v10->taskParams_Local.mMainMemoryAddress + 42);
  v20 = *((signed __int16 *)v10->paramIndices_Local.mMainMemoryAddress + 8);
  v21 = *((_WORD *)v10->paramIndices_Local.mMainMemoryAddress + 8);
  if ( v20 >= 0x40 )
    v7->mStateValues.mSetValueMask.mFlags[1] |= 1i64 << (v21 - 64);
  else
    v7->mStateValues.mSetValueMask.mFlags[0] |= 1i64 << v21;
  v7->mStateValues.mParamValues[(signed __int16)v20] = v19;
  v22 = (void *)*((_QWORD *)v10->taskParams_Local.mMainMemoryAddress + 44);
  v7->mStateValues.mSetValueMask.mFlags[0] |= 0x200ui64;
  v7->mStateValues.mParamValues[9] = v22;
  v23 = (void **)v10->taskParams_Local.mMainMemoryAddress;
  if ( v11 )
  {
    v24 = v23 + 51;
    if ( !isNear )
      v24 = v23 + 49;
  }
  else
  {
    v24 = v23 + 47;
    if ( !isNear )
      v24 = v23 + 46;
  }
  v25 = *v24;
  v26 = *((_BYTE *)v23 + 213) && light->mSpecular;
  v27 = light->mType;
  switch ( v27 )
  {
    case 0:
      if ( v26 )
        v28 = v23 + 35;
      else
        v28 = v23 + 34;
      v29 = *v28;
      v7->mStateValues.mSetValueMask.mFlags[0] |= 2ui64;
      v30 = resolvedDistAttenTexture;
      v7->mStateValues.mParamValues[1] = v29;
      if ( !resolvedDistAttenTexture )
        v30 = (Illusion::Texture *)*((_QWORD *)v10->taskParams_Local.mMainMemoryAddress + 39);
      v31 = *((signed __int16 *)v10->paramIndices_Local.mMainMemoryAddress + 12);
      v32 = v31;
      if ( v31 < 0x40 )
      {
        v7->mStateValues.mSetValueMask.mFlags[0] |= 1i64 << v31;
LABEL_51:
        v7->mStateValues.mParamValues[(signed __int16)v31] = v30;
        break;
      }
      goto LABEL_50;
    case 1:
    case 4:
      if ( v26 )
        v33 = v23 + 33;
      else
        v33 = v23 + 32;
LABEL_41:
      v34 = *v33;
      v7->mStateValues.mSetValueMask.mFlags[0] |= 2ui64;
      v35 = resolvedDistAttenTexture;
      v7->mStateValues.mParamValues[1] = v34;
      if ( !resolvedDistAttenTexture )
        v35 = (Illusion::Texture *)*((_QWORD *)v10->taskParams_Local.mMainMemoryAddress + 39);
      v36 = *((signed __int16 *)v10->paramIndices_Local.mMainMemoryAddress + 12);
      v37 = *((_WORD *)v10->paramIndices_Local.mMainMemoryAddress + 12);
      if ( v36 >= 0x40 )
        v7->mStateValues.mSetValueMask.mFlags[1] |= 1i64 << (v37 - 64);
      else
        v7->mStateValues.mSetValueMask.mFlags[0] |= 1i64 << v37;
      v7->mStateValues.mParamValues[(signed __int16)v36] = v35;
      v30 = resolvedTexture;
      if ( !resolvedTexture )
        v30 = (Illusion::Texture *)*((_QWORD *)v10->taskParams_Local.mMainMemoryAddress + 39);
      v31 = *((signed __int16 *)v10->paramIndices_Local.mMainMemoryAddress + 6);
      v32 = v31;
      if ( v31 < 0x40 )
      {
        v7->mStateValues.mSetValueMask.mFlags[0] |= 1i64 << v31;
        goto LABEL_51;
      }
LABEL_50:
      v7->mStateValues.mSetValueMask.mFlags[1] |= 1i64 << (v32 - 64);
      goto LABEL_51;
    case 5:
      if ( v26 )
      {
        v33 = v23 + 31;
      }
      else if ( light->mAreaLightNearOffset >= 0.000099999997 )
      {
        v33 = v23 + 29;
      }
      else
      {
        v33 = v23 + 30;
      }
      goto LABEL_41;
  }
  v7->mStateValues.mSetValueMask.mFlags[0] |= 0x400ui64;
  v7->mStateValues.mParamValues[10] = v25;
}

// File Line: 681
// RVA: 0x7F0B0
__int64 __fastcall DrawLightArray(LightingTaskVars *vars, bool useStencil, unsigned int startIndex, unsigned int count)
{
  __int64 v4; // r14
  bool v5; // r8
  LightingTaskVars *v6; // rbx
  unsigned int v7; // er13
  unsigned int v8; // edx
  signed __int64 v9; // r15
  signed __int64 v10; // rdi
  _BYTE *v11; // rsi
  Render::Light *v12; // rbp
  float v13; // xmm6_4
  float *v14; // rax
  bool v15; // r12
  float colorFade; // xmm7_4
  char *v17; // rax
  Illusion::SubmitContext *v18; // rdx
  void *v19; // rcx
  void *v20; // rcx
  char *v21; // rax
  void **v22; // rax
  void *v23; // rax
  UFG::qstream_typed<Render::Light> light_Remote; // [rsp+40h] [rbp-98h]
  __int64 v26; // [rsp+48h] [rbp-90h]
  char *v27; // [rsp+50h] [rbp-88h]
  Illusion::SubmitContext *v28; // [rsp+E0h] [rbp+8h]
  bool v29; // [rsp+E8h] [rbp+10h]
  unsigned int v30; // [rsp+F0h] [rbp+18h]

  v29 = useStencil;
  v26 = -2i64;
  v4 = startIndex;
  v5 = useStencil;
  v6 = vars;
  v7 = 0;
  v28 = vars->submitContext;
  v8 = v4 + count;
  v30 = v4 + count;
  if ( (unsigned int)v4 < (unsigned int)v4 + count )
  {
    v9 = 8 * v4;
    v10 = 16i64 * (unsigned int)v4;
    do
    {
      v11 = v6->processedLights_Local.mMainMemoryAddress;
      if ( !(v11[v10 + 2] & 1) )
      {
        v12 = (Render::Light *)*((_QWORD *)v6->lights_Local.mMainMemoryAddress + *(unsigned __int16 *)&v11[v10]);
        v13 = v12->mDecayRadius * *(float *)&v11[v10 + 4];
        if ( v13 >= 0.0099999998 )
        {
          v14 = (float *)v6->taskParams_Local.mMainMemoryAddress;
          v15 = (unsigned int)v4 < *((_DWORD *)v14 + 50);
          colorFade = v14[57] * *(float *)&v11[v10 + 12];
          if ( v5 )
          {
            if ( *((_BYTE *)v14 + 216) )
            {
              v17 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x28u, 0x10u);
              light_Remote.m_Stream = v17;
              v27 = v17;
              if ( v17 )
              {
                *(_QWORD *)v17 = 0i64;
                *((_DWORD *)v17 + 2) = 0;
                *((_DWORD *)v17 + 3) = 0;
                *((_DWORD *)v17 + 4) = 0;
                *((_DWORD *)v17 + 5) = 0;
                *((_DWORD *)v17 + 6) = 4;
                *(_QWORD *)(v17 + 28) = 1065353216i64;
              }
              v28->vfptr->AddRenderCommand(v28, 16, 0, v17);
            }
            v18 = v6->submitContext;
            v19 = (void *)*((_QWORD *)v6->taskParams_Local.mMainMemoryAddress + 38);
            v18->mStateValues.mSetValueMask.mFlags[0] |= 2ui64;
            v18->mStateValues.mParamValues[1] = v19;
            v20 = (void *)*((_QWORD *)v6->taskParams_Local.mMainMemoryAddress + 45);
            v18->mStateValues.mSetValueMask.mFlags[0] |= 0x200ui64;
            v18->mStateValues.mParamValues[9] = v20;
            v21 = (char *)v6->taskParams_Local.mMainMemoryAddress;
            if ( v15 )
              v22 = (void **)(v21 + 400);
            else
              v22 = (void **)(v21 + 384);
            v23 = *v22;
            v18->mStateValues.mSetValueMask.mFlags[0] |= 0x400ui64;
            v18->mStateValues.mParamValues[10] = v23;
            DrawLight(v6, v12, &light_Remote, v13, *(float *)&v11[v10 + 8], colorFade, 1);
            v5 = v29;
          }
          SetLightMaterialState(
            v6,
            v12,
            v13,
            v5,
            v15,
            *(Illusion::Texture **)((char *)v6->resolvedTextures_Local.mMainMemoryAddress + v9),
            *(Illusion::Texture **)((char *)v6->resolvedDistAttenTextures_local.mMainMemoryAddress + v9));
          DrawLight(v6, v12, &light_Remote, v13, *(float *)&v11[v10 + 8], colorFade, 0);
          ++v7;
          v8 = v30;
          v5 = v29;
        }
      }
      LODWORD(v4) = v4 + 1;
      v10 += 16i64;
      v9 += 8i64;
    }
    while ( (unsigned int)v4 < v8 );
  }
  return v7;
}

// File Line: 733
// RVA: 0x1457610
__int64 dynamic_initializer_for__gTaskFunctionDecl_SubmitLightingTask__()
{
  UFG::qTaskFunctionDecl::qTaskFunctionDecl(
    &gTaskFunctionDecl_SubmitLightingTask,
    &gTaskFunctionDeclData_SubmitLightingTask);
  return atexit(dynamic_atexit_destructor_for__gTaskFunctionDecl_SubmitLightingTask__);
}

// File Line: 741
// RVA: 0x7D760
void __fastcall SubmitLightingTask(int workerId, UFG::qMemoryStreamer *memory_streamer, void *param_stream, void *pad0)
{
  UFG::qMemoryStreamer *v4; // rsi
  int v5; // er15
  UFG::qMatrix44 *v6; // rax
  UFG::qVector4 v7; // xmm2
  UFG::qVector4 v8; // xmm1
  UFG::qVector4 v9; // xmm0
  char *v10; // rbx
  unsigned __int16 v11; // ax
  UFG::qMatrix44 *v12; // rbx
  unsigned __int16 v13; // ax
  _DWORD *v14; // rax
  _DWORD *v15; // rax
  _DWORD *v16; // rbx
  _DWORD *v17; // rbx
  float *v18; // rdx
  __int64 v19; // rdi
  unsigned int v20; // er13
  signed __int64 v21; // r14
  signed __int64 v22; // rbx
  char *v23; // rsi
  Render::Light *v24; // r12
  float v25; // xmm3_4
  float v26; // xmm1_4
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v27; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v28; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v29; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v30; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v31; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v32; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v33; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v34; // rax
  Render::cbExternalViewTransformState v35; // [rsp+40h] [rbp-C0h]
  Render::cbViewTransformState arg; // [rsp+80h] [rbp-80h]
  LightingTaskVars vars; // [rsp+D0h] [rbp-30h]
  __int64 v38; // [rsp+200h] [rbp+100h]
  char *stream_name; // [rsp+210h] [rbp+110h]
  __int64 v40; // [rsp+218h] [rbp+118h]
  int v41; // [rsp+220h] [rbp+120h]
  void *local_mem; // [rsp+228h] [rbp+128h]
  char v43; // [rsp+313h] [rbp+213h]
  UFG::qMatrix44 result; // [rsp+3A0h] [rbp+2A0h]
  SimpleTaskSubmitContext dest; // [rsp+3E0h] [rbp+2E0h]
  UFG::qMemoryStreamer *v46; // [rsp+10A8h] [rbp+FA8h]
  UFG::qstream_typed<Render::Light> light_Remote; // [rsp+10B0h] [rbp+FB0h]

  v46 = memory_streamer;
  v38 = -2i64;
  v4 = memory_streamer;
  vars.taskParams_Local.mName = "<unassigned>";
  v5 = 0;
  vars.taskParams_Local.mState = 0;
  vars.paramIndices_Local.mName = "<unassigned>";
  vars.paramIndices_Local.mMainMemoryAddress = 0i64;
  vars.paramIndices_Local.mState = 0;
  vars.resolvedTextures_Local.mName = "<unassigned>";
  vars.resolvedTextures_Local.mMainMemoryAddress = 0i64;
  vars.resolvedTextures_Local.mState = 0;
  vars.resolvedDistAttenTextures_local.mName = "<unassigned>";
  vars.resolvedDistAttenTextures_local.mMainMemoryAddress = 0i64;
  vars.resolvedDistAttenTextures_local.mState = 0;
  vars.processedLights_Local.mName = "<unassigned>";
  vars.processedLights_Local.mMainMemoryAddress = 0i64;
  vars.processedLights_Local.mState = 0;
  vars.lights_Local.mName = "<unassigned>";
  vars.lights_Local.mMainMemoryAddress = 0i64;
  vars.lights_Local.mState = 0;
  vars.light_groups_Local.mName = "<unassigned>";
  vars.light_groups_Local.mMainMemoryAddress = 0i64;
  vars.light_groups_Local.mState = 0;
  vars.taskParams_Local.mMainMemoryAddress = param_stream;
  vars.paramIndices_Local.mMainMemoryAddress = (void *)*((_QWORD *)param_stream + 18);
  vars.resolvedTextures_Local.mMainMemoryAddress = (void *)*((_QWORD *)param_stream + 23);
  vars.resolvedDistAttenTextures_local.mMainMemoryAddress = (void *)*((_QWORD *)param_stream + 24);
  vars.processedLights_Local.mMainMemoryAddress = (void *)*((_QWORD *)param_stream + 22);
  vars.lights_Local.mMainMemoryAddress = (void *)*((_QWORD *)param_stream + 21);
  vars.light_groups_Local.mMainMemoryAddress = (void *)*((_QWORD *)param_stream + 55);
  SimpleTaskSubmitContext::SimpleTaskSubmitContext(&dest);
  dest.mRenderQueueProvider = (RenderQueueLayer *)*((_QWORD *)vars.taskParams_Local.mMainMemoryAddress + 20);
  UFG::qMemSet(dest.mStateValues.mParamValues, 0, 0x400u);
  dest.mStateValues.mSetValueMask.mFlags[1] = 0i64;
  dest.mStateValues.mSetValueMask.mFlags[0] = 0i64;
  vars.submitContext = (Illusion::SubmitContext *)&dest;
  UFG::qInverseAffine(&vars.viewWorld, (UFG::qMatrix44 *)vars.taskParams_Local.mMainMemoryAddress);
  v6 = UFG::qMatrix44::operator*(
         (UFG::qMatrix44 *)vars.taskParams_Local.mMainMemoryAddress,
         &result,
         (UFG::qMatrix44 *)vars.taskParams_Local.mMainMemoryAddress + 1);
  v7 = v6->v1;
  v8 = v6->v2;
  v9 = v6->v3;
  vars.worldViewProjection.v0 = v6->v0;
  vars.worldViewProjection.v1 = v7;
  vars.worldViewProjection.v2 = v8;
  vars.worldViewProjection.v3 = v9;
  v10 = (char *)vars.taskParams_Local.mMainMemoryAddress;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mCallback = 0i64;
  arg.mStateParamIndex = Render::cbViewTransformState::sStateParamIndex;
  *(_WORD *)&arg.mFlags = 1;
  if ( (_WORD)Render::cbViewTransformState::sStateParamIndex == -1 )
  {
    v11 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbViewTransform");
    Render::cbViewTransformState::sStateParamIndex = v11;
    arg.mStateParamIndex = v11;
  }
  arg.mWorldViewProjection = (UFG::qMatrix44 *)&vars;
  arg.mViewWorld = &vars.viewWorld;
  arg.mProjection = (UFG::qMatrix44 *)(v10 + 64);
  arg.mScreenOffset = (UFG::qVector2 *)(v10 + 448);
  arg.mCached_Remote.m_Stream = 0i64;
  v12 = (UFG::qMatrix44 *)vars.taskParams_Local.mMainMemoryAddress;
  v35.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v35;
  v35.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v35;
  v35.mCallback = 0i64;
  v35.mStateParamIndex = Render::cbExternalViewTransformState::sStateParamIndex;
  *(_WORD *)&v35.mFlags = 1;
  if ( (_WORD)Render::cbExternalViewTransformState::sStateParamIndex == -1 )
  {
    v13 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbExternalViewTransform");
    Render::cbExternalViewTransformState::sStateParamIndex = v13;
    v35.mStateParamIndex = v13;
  }
  v35.mWorldView = v12;
  v35.mProjection = v12 + 1;
  v35.mCached_Remote.m_Stream = 0i64;
  Illusion::StateArgs::Set<Render::cbViewTransformState>(&dest.mStateArgs, &arg);
  Illusion::StateArgs::Set<Render::cbExternalViewTransformState>(&dest.mStateArgs, &v35);
  stream_name = "<unassigned>";
  v40 = 0i64;
  v41 = 0;
  v14 = (_DWORD *)((unsigned __int64)&v43 & 0xFFFFFFFFFFFFFF80ui64);
  local_mem = v14;
  *v14 = 0;
  v15 = vars.taskParams_Local.mMainMemoryAddress;
  if ( *((_BYTE *)vars.taskParams_Local.mMainMemoryAddress + 214) )
  {
    v16 = local_mem;
    *v16 = DrawLightArray(
             &vars,
             *((_BYTE *)vars.taskParams_Local.mMainMemoryAddress + 215),
             0,
             *((_DWORD *)vars.taskParams_Local.mMainMemoryAddress + 50));
    v15 = vars.taskParams_Local.mMainMemoryAddress;
  }
  v17 = local_mem;
  v17[1] = DrawLightArray(&vars, 1, v15[50], v15[52]);
  v18 = (float *)vars.taskParams_Local.mMainMemoryAddress;
  v19 = (unsigned int)(*((_DWORD *)vars.taskParams_Local.mMainMemoryAddress + 50)
                     + *((_DWORD *)vars.taskParams_Local.mMainMemoryAddress + 52));
  v20 = v19 + *((_DWORD *)vars.taskParams_Local.mMainMemoryAddress + 51);
  if ( (unsigned int)v19 < v20 )
  {
    v21 = 8 * v19;
    v22 = 16i64 * (unsigned int)v19;
    do
    {
      v23 = (char *)vars.processedLights_Local.mMainMemoryAddress;
      if ( !(*((_BYTE *)vars.processedLights_Local.mMainMemoryAddress + v22 + 2) & 1) )
      {
        v24 = (Render::Light *)*((_QWORD *)vars.lights_Local.mMainMemoryAddress
                               + *(unsigned __int16 *)((char *)vars.processedLights_Local.mMainMemoryAddress + v22));
        v25 = v24->mDecayRadius * *(float *)((char *)vars.processedLights_Local.mMainMemoryAddress + v22 + 4);
        if ( v25 >= 0.0099999998 )
        {
          v26 = v18[57] * *(float *)((char *)vars.processedLights_Local.mMainMemoryAddress + v22 + 12);
          SetLightMaterialState(
            &vars,
            v24,
            v25,
            0,
            (unsigned int)v19 < *((_DWORD *)v18 + 50),
            *(Illusion::Texture **)((char *)vars.resolvedTextures_Local.mMainMemoryAddress + v21),
            *(Illusion::Texture **)((char *)vars.resolvedDistAttenTextures_local.mMainMemoryAddress + v21));
          DrawLight(&vars, v24, &light_Remote, v25, *(float *)&v23[v22 + 8], v26, 0);
          ++v5;
          v18 = (float *)vars.taskParams_Local.mMainMemoryAddress;
        }
      }
      LODWORD(v19) = v19 + 1;
      v22 += 16i64;
      v21 += 8i64;
    }
    while ( (unsigned int)v19 < v20 );
    v4 = v46;
  }
  *((_DWORD *)local_mem + 2) = v5;
  v27 = arg.mPrev;
  v28 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v28->mPrev = v27;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mIsSet = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)dest.mStateArgs.mStateArgs[arg.mStateParamIndex].mNode.mNext == &dest.mStateArgs.mStateArgs[arg.mStateParamIndex] )
    dest.mStateArgs.mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
  v29 = v35.mPrev;
  v30 = v35.mNext;
  v35.mPrev->mNext = v35.mNext;
  v30->mPrev = v29;
  v35.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v35;
  v35.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v35;
  v35.mIsSet = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)dest.mStateArgs.mStateArgs[v35.mStateParamIndex].mNode.mNext == &dest.mStateArgs.mStateArgs[v35.mStateParamIndex] )
    dest.mStateArgs.mStateArgsCreateMask.mFlags[(unsigned int)v35.mStateParamIndex >> 6] &= ~(1i64 << (v35.mStateParamIndex & 0x3F));
  UFG::qMemoryStreamer::BeginRawWritePlat(
    v4,
    stream_name,
    local_mem,
    0x10ui64,
    *((void **)vars.taskParams_Local.mMainMemoryAddress + 54),
    0x10ui64);
  v31 = v35.mPrev;
  v32 = v35.mNext;
  v35.mPrev->mNext = v35.mNext;
  v32->mPrev = v31;
  v35.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v35;
  v35.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v35;
  v33 = arg.mPrev;
  v34 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v34->mPrev = v33;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  light_Remote.m_Stream = &dest.mStateArgs;
  `eh vector destructor iterator(
    dest.mStateArgs.mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
}

