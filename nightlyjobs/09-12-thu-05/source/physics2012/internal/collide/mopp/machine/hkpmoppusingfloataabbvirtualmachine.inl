// File Line: 24
// RVA: 0xDB3F00
void __fastcall hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObjectOptimized>::queryMoppTree(hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObjectOptimized> *this, hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObjectOptimized>::hkpMoppUsingFloatAabbVirtualMachineQueryInt *query, const char *PC, hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObjectOptimized>::hkpMoppTempAabb *fQueryL)
{
  hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObjectOptimized>::hkpMoppTempAabb *v4; // r10
  const char *v5; // rbx
  hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObjectOptimized>::hkpMoppUsingFloatAabbVirtualMachineQueryInt *v6; // rdi
  hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObjectOptimized> *v7; // rsi
  int v8; // er11
  int v9; // er9
  unsigned __int8 v10; // dl
  unsigned __int8 v11; // r8
  hkVector4f v12; // xmm1
  const char *v13; // rbx
  int v14; // ecx
  hkVector4f v15; // xmm1
  int v16; // eax
  int v17; // er9
  __int64 v18; // rdx
  __m128i v19; // xmm0
  int v20; // eax
  signed __int64 v21; // rbx
  int v22; // ecx
  hkVector4f v23; // xmm1
  int v24; // edx
  __int64 v25; // r8
  unsigned int v26; // er9
  __m128i v27; // xmm0
  int v28; // ecx
  hkVector4f v29; // xmm1
  __int64 v30; // rdx
  __int64 v31; // r8
  signed int v32; // eax
  __int64 v33; // rdx
  unsigned int v34; // ecx
  __m128i v35; // xmm0
  unsigned int v36; // eax
  __int64 v37; // r9
  signed int i; // eax
  __int64 v39; // rdx
  int v40; // ecx
  int v41; // ecx
  __int64 v42; // r8
  int v43; // eax
  hkVector4f v44; // xmm11
  hkVector4f v45; // xmm12
  __int64 v46; // rax
  signed int v47; // er11
  int v48; // er9
  hkpMoppFindAllVirtualMachine *v49; // rax
  __m128 *v50; // r8
  __m128 v51; // xmm5
  __m128 v52; // xmm6
  __m128 *v53; // rdx
  __m128 *v54; // rcx
  __m128 v55; // xmm7
  __m128 v56; // xmm8
  __m128 v57; // xmm9
  __m128 v58; // xmm10
  __m128 v59; // xmm6
  __m128 v60; // xmm5
  __m128 v61; // xmm3
  __m128 v62; // xmm2
  char *v63; // ST10_8
  __m128 *v64; // ST18_8
  __m128 v65; // xmm5
  int v66; // edx
  signed int v67; // er9
  __m128 v68; // xmm6
  __m128 v69; // xmm5
  __m128 *v70; // rcx
  __m128 v71; // xmm7
  __m128 v72; // xmm8
  __m128 v73; // xmm9
  __m128 v74; // xmm10
  __m128 v75; // xmm5
  __m128 v76; // xmm6
  __m128 v77; // xmm3
  __m128 v78; // xmm2
  signed int v79; // eax
  __int64 v80; // rdx
  unsigned int v81; // ecx
  __m128i v82; // xmm0
  __m128 v83; // xmm5
  int v84; // er8
  signed int v85; // er9
  __m128 *v86; // rdx
  __m128 v87; // xmm6
  __m128 v88; // xmm5
  __m128 *v89; // rcx
  __m128 v90; // xmm7
  __m128 v91; // xmm8
  __m128 v92; // xmm9
  __m128 v93; // xmm10
  __m128 v94; // xmm5
  __m128 v95; // xmm6
  __m128 v96; // xmm3
  __m128 v97; // xmm2
  int v98; // eax
  int v99; // eax
  int v100; // eax
  int v101; // ecx
  int v102; // eax
  int v103; // edx
  __int64 v104; // rax
  int v105; // ecx
  int v106; // eax
  int v107; // ecx
  hkArray<hkpMoppPrimitiveInfo,hkContainerHeapAllocator> *v108; // rbx
  hkpMoppPrimitiveInfo *v109; // rcx
  __int64 v110; // rdx
  int v111; // [rsp+8h] [rbp-79h]
  char *PCa; // [rsp+10h] [rbp-71h]
  unsigned int v113; // [rsp+20h] [rbp-61h]
  unsigned int v114; // [rsp+24h] [rbp-5Dh]
  int v115; // [rsp+28h] [rbp-59h]
  int v116; // [rsp+2Ch] [rbp-55h]
  int v117; // [rsp+30h] [rbp-51h]
  int v118; // [rsp+34h] [rbp-4Dh]
  hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObjectOptimized>::hkpMoppTempAabb fQueryLa; // [rsp+38h] [rbp-49h]
  hkpMoppFindAllVirtualMachine *retaddr; // [rsp+F8h] [rbp+77h]
  hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObjectOptimized>::hkpMoppTempAabb *v121; // [rsp+100h] [rbp+7Fh]

  v4 = fQueryL;
  v5 = PC;
  v6 = query;
  v7 = this;
  while ( 2 )
  {
    LOBYTE(v8) = v5[2];
    v9 = *(unsigned __int8 *)v5;
    v10 = v5[3];
    v11 = v5[1];
    LOBYTE(retaddr) = v5[3];
    switch ( v9 )
    {
      case 0:
        return;
      case 1:
      case 2:
      case 3:
      case 4:
        v115 = v6->m_offset_x + (v11 << v6->m_shift);
        v116 = v6->m_offset_y + ((unsigned __int8)v8 << v6->m_shift);
        v117 = v6->m_offset_z + (v10 << v6->m_shift);
        v5 += 4;
        v118 = v6->m_shift - v9;
        v114 = v6->m_properties[0];
        v98 = v6->m_primitiveOffset;
        v6 = (hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObjectOptimized>::hkpMoppUsingFloatAabbVirtualMachineQueryInt *)&v113;
        v113 = v98;
        continue;
      case 5:
        v5 += v11 + 2;
        continue;
      case 6:
        v5 += 256 * v11 + (unsigned __int8)v8 + 3;
        continue;
      case 7:
        v5 += 0x10000 * v11 + 256 * (unsigned __int8)v8 + (unsigned int)v10 + 4;
        continue;
      case 8:
        v5 += 0x1000000 * v11
            + 256 * (v10 + ((unsigned __int8)v8 << 8))
            + (unsigned int)*((unsigned __int8 *)v5 + 4)
            + 5;
        continue;
      case 9:
        if ( v6 != (hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObjectOptimized>::hkpMoppUsingFloatAabbVirtualMachineQueryInt *)&v113 )
        {
          v113 = v6->m_primitiveOffset;
          v114 = v6->m_properties[0];
          v115 = v6->m_offset_x;
          v116 = v6->m_offset_y;
          v117 = v6->m_offset_z;
          v99 = v6->m_shift;
          v6 = (hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObjectOptimized>::hkpMoppUsingFloatAabbVirtualMachineQueryInt *)&v113;
          v118 = v99;
        }
        v113 += v11;
        v5 += 2;
        continue;
      case 10:
        if ( v6 != (hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObjectOptimized>::hkpMoppUsingFloatAabbVirtualMachineQueryInt *)&v113 )
        {
          v113 = v6->m_primitiveOffset;
          v114 = v6->m_properties[0];
          v115 = v6->m_offset_x;
          v116 = v6->m_offset_y;
          v117 = v6->m_offset_z;
          v100 = v6->m_shift;
          v6 = (hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObjectOptimized>::hkpMoppUsingFloatAabbVirtualMachineQueryInt *)&v113;
          v118 = v100;
        }
        v113 += (unsigned __int8)v8 + (v11 << 8);
        v5 += 3;
        continue;
      case 11:
        v101 = *((unsigned __int8 *)v5 + 4) + (v11 << 24) + ((unsigned __int8)v8 << 16) + (v10 << 8);
        if ( v6 != (hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObjectOptimized>::hkpMoppUsingFloatAabbVirtualMachineQueryInt *)&v113 )
        {
          v113 = v6->m_primitiveOffset;
          v114 = v6->m_properties[0];
          v115 = v6->m_offset_x;
          v116 = v6->m_offset_y;
          v117 = v6->m_offset_z;
          v102 = v6->m_shift;
          v6 = (hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObjectOptimized>::hkpMoppUsingFloatAabbVirtualMachineQueryInt *)&v113;
          v118 = v102;
        }
        v113 = v101;
        v5 += 5;
        continue;
      case 16:
      case 17:
      case 18:
        v14 = v6->m_shift;
        v15.m_quad = (__m128)v4->m_aabb.m_max;
        v16 = v9 - 16;
        v17 = 0;
        v18 = v16;
        fQueryLa.m_aabb.m_min = v4->m_aabb.m_min;
        fQueryLa.m_aabb.m_max = (hkVector4f)v15.m_quad;
        v19 = _mm_cvtsi32_si128(*(&v6->m_offset_x + v16) + ((unsigned int)v11 << v14));
        v20 = (unsigned __int8)v8;
        v8 = (unsigned __int8)retaddr;
        v4->m_aabb.m_max.m_quad.m128_f32[v18] = COERCE_FLOAT(_mm_cvtepi32_ps(v19)) * v7->m_ItoFScale;
        v21 = (signed __int64)(v5 + 4);
        fQueryLa.m_aabb.m_min.m_quad.m128_f32[v18] = (float)(*(&v6->m_offset_x + v18) + (v20 << v6->m_shift))
                                                   * v7->m_ItoFScale;
        goto LABEL_7;
      case 19:
      case 20:
      case 21:
      case 22:
      case 23:
      case 24:
      case 25:
      case 26:
      case 27:
      case 28:
        v12.m_quad = (__m128)v4->m_aabb.m_max;
        v13 = v5 + 4;
        fQueryLa.m_aabb.m_min = v4->m_aabb.m_min;
        fQueryLa.m_aabb.m_max = (hkVector4f)v12.m_quad;
        hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObjectOptimized>::queryMoppTree(
          v7,
          v6,
          v13,
          &fQueryLa);
        v4 = v121;
        v5 = &v13[(unsigned __int8)retaddr];
        continue;
      case 32:
      case 33:
      case 34:
        v22 = v6->m_shift;
        v23.m_quad = (__m128)v4->m_aabb.m_max;
        v21 = (signed __int64)(v5 + 3);
        v24 = v11;
        fQueryLa.m_aabb.m_min = v4->m_aabb.m_min;
        fQueryLa.m_aabb.m_max = (hkVector4f)v23.m_quad;
        v25 = v9 - 32;
        v8 = (unsigned __int8)v8;
        v26 = *(&v6->m_offset_x + v25) + ((v24 + 1) << v22);
        fQueryLa.m_aabb.m_min.m_quad.m128_f32[v25] = (float)(*(&v6->m_offset_x + v25) + (v24 << v22)) * v7->m_ItoFScale;
        v27 = _mm_cvtsi32_si128(v26);
        v17 = 0;
        v4->m_aabb.m_max.m_quad.m128_f32[v25] = COERCE_FLOAT(_mm_cvtepi32_ps(v27)) * v7->m_ItoFScale;
        goto LABEL_7;
      case 35:
      case 36:
      case 37:
        v28 = v6->m_shift;
        v29.m_quad = (__m128)v4->m_aabb.m_max;
        v30 = v9 - 35;
        fQueryLa.m_aabb.m_min = v4->m_aabb.m_min;
        fQueryLa.m_aabb.m_max = (hkVector4f)v29.m_quad;
        v4->m_aabb.m_max.m_quad.m128_f32[v30] = (float)(*(&v6->m_offset_x + v30) + (v11 << v28)) * v7->m_ItoFScale;
        fQueryLa.m_aabb.m_min.m_quad.m128_f32[v30] = (float)(*(&v6->m_offset_x + v30)
                                                           + ((unsigned __int8)v8 << v6->m_shift))
                                                   * v7->m_ItoFScale;
        v17 = *((unsigned __int8 *)v5 + 4) + ((unsigned __int8)retaddr << 8);
        v8 = *((unsigned __int8 *)v5 + 6) + (*((unsigned __int8 *)v5 + 5) << 8);
        v21 = (signed __int64)(v5 + 7);
LABEL_7:
        v31 = v17;
        v111 = v17;
        v32 = *(unsigned __int8 *)(v17 + v21);
        if ( v32 >= 38 )
        {
          do
          {
            if ( v32 > 43 )
              break;
            if ( v32 < 41 )
            {
              v17 += 3;
              v33 = v32 - 38;
              v4->m_aabb.m_min.m_quad.m128_f32[v33] = (float)(*(&v6->m_offset_x + v33)
                                                            + (*(unsigned __int8 *)(v31 + v21 + 1) << v6->m_shift))
                                                    * v7->m_ItoFScale;
              v36 = *(&v6->m_offset_x + v33) + (*(unsigned __int8 *)(v31 + v21 + 2) << v6->m_shift);
              v31 += 3i64;
              v35 = _mm_cvtsi32_si128(v36);
            }
            else
            {
              v17 += 7;
              v33 = v32 - 41;
              v4->m_aabb.m_min.m_quad.m128_f32[v33] = (float)(*(unsigned __int8 *)(v31 + v21 + 3)
                                                            + (((*(unsigned __int8 *)(v31 + v21 + 1) << 8)
                                                              + *(unsigned __int8 *)(v31 + v21 + 2)) << 8))
                                                    * v7->m_ItoFScale;
              v34 = *(unsigned __int8 *)(v31 + v21 + 6)
                  + (((*(unsigned __int8 *)(v31 + v21 + 4) << 8) + *(unsigned __int8 *)(v31 + v21 + 5)) << 8);
              v31 += 7i64;
              v35 = _mm_cvtsi32_si128(v34);
            }
            v4->m_aabb.m_max.m_quad.m128_f32[v33] = COERCE_FLOAT(_mm_cvtepi32_ps(v35)) * v7->m_ItoFScale;
            v32 = *(unsigned __int8 *)(v31 + v21);
          }
          while ( v32 >= 38 );
          v111 = v17;
        }
        v37 = v8;
        for ( i = *(unsigned __int8 *)(v8 + v21); i >= 38; i = *(unsigned __int8 *)(v37 + v21) )
        {
          if ( i > 43 )
            break;
          if ( i < 41 )
          {
            v41 = v6->m_shift;
            v8 += 3;
            v42 = i - 38;
            fQueryLa.m_aabb.m_min.m_quad.m128_f32[v42] = (float)(*(&v6->m_offset_x + v42)
                                                               + (*(unsigned __int8 *)(v37 + v21 + 1) << v41))
                                                       * v7->m_ItoFScale;
            v43 = *(&v6->m_offset_x + v42) + (*(unsigned __int8 *)(v37 + v21 + 2) << v41);
            v37 += 3i64;
            fQueryLa.m_aabb.m_max.m_quad.m128_f32[v42] = (float)v43 * v7->m_ItoFScale;
          }
          else
          {
            v8 += 7;
            v39 = i - 41;
            fQueryLa.m_aabb.m_min.m_quad.m128_f32[v39] = (float)(*(unsigned __int8 *)(v37 + v21 + 3)
                                                               + (((*(unsigned __int8 *)(v37 + v21 + 1) << 8)
                                                                 + *(unsigned __int8 *)(v37 + v21 + 2)) << 8))
                                                       * v7->m_ItoFScale;
            v40 = *(unsigned __int8 *)(v37 + v21 + 6)
                + (((*(unsigned __int8 *)(v37 + v21 + 4) << 8) + *(unsigned __int8 *)(v37 + v21 + 5)) << 8);
            v37 += 7i64;
            fQueryLa.m_aabb.m_max.m_quad.m128_f32[v39] = (float)v40 * v7->m_ItoFScale;
          }
        }
        v44.m_quad = (__m128)fQueryLa.m_aabb.m_max;
        v45.m_quad = (__m128)fQueryLa.m_aabb.m_min;
        v46 = v8;
        v47 = 15;
        v48 = v7->m_queryObject.m_numTransforms - 1;
        PCa = (char *)(v21 + v46);
        v49 = (hkpMoppFindAllVirtualMachine *)&v7->m_queryObject.m_primitives_out;
        v50 = (__m128 *)v7->m_queryObject.m_rotatedPlanes;
        v51 = _mm_add_ps(fQueryLa.m_aabb.m_max.m_quad, fQueryLa.m_aabb.m_min.m_quad);
        v52 = _mm_sub_ps(fQueryLa.m_aabb.m_max.m_quad, fQueryLa.m_aabb.m_min.m_quad);
        v53 = (__m128 *)v7->m_queryObject.m_rotatedPlanes;
        if ( v48 < 0 )
          goto LABEL_28;
        v54 = &v7->m_queryObject.m_absRotPlanes[0].m_rotation.m_col2.m_quad;
        v55 = _mm_shuffle_ps(v52, v52, 85);
        v56 = _mm_shuffle_ps(v52, v52, 0);
        v57 = _mm_shuffle_ps(v51, v51, 85);
        v58 = _mm_shuffle_ps(v51, v51, 0);
        v59 = _mm_shuffle_ps(v52, v52, 170);
        v60 = _mm_shuffle_ps(v51, v51, 170);
        do
        {
          v61 = _mm_add_ps(
                  _mm_add_ps(_mm_add_ps(_mm_mul_ps(v54[-2], v56), _mm_mul_ps(v54[-1], v55)), _mm_mul_ps(*v54, v59)),
                  v54[1]);
          v62 = _mm_add_ps(
                  _mm_add_ps(_mm_add_ps(_mm_mul_ps(v54[-33], v57), _mm_mul_ps(*v53, v58)), _mm_mul_ps(v54[-32], v60)),
                  v54[-31]);
          if ( _mm_movemask_ps(_mm_cmpltps(_mm_sub_ps(v62, v61), (__m128)0i64)) != 15 )
          {
            LODWORD(retaddr) = 0;
            goto LABEL_29;
          }
          v53 += 4;
          v54 += 4;
          v47 &= _mm_movemask_ps(_mm_cmpltps(_mm_add_ps(v62, v61), (__m128)0i64));
          --v48;
        }
        while ( v48 >= 0 );
        if ( v47 == 15 )
        {
          v49 = (hkpMoppFindAllVirtualMachine *)&v7->m_queryObject.m_primitives_out;
LABEL_28:
          hkpMoppFindAllVirtualMachine::queryOnTreeLeft(v49, &v6->0, PCa);
          hkpMoppFindAllVirtualMachine::queryOnTreeRight(
            (hkpMoppFindAllVirtualMachine *)&v7->m_queryObject.m_primitives_out,
            &v6->0,
            v63);
          v4 = v121;
          v50 = v64;
          v44.m_quad = (__m128)fQueryLa.m_aabb.m_max;
          v45.m_quad = (__m128)fQueryLa.m_aabb.m_min;
          LODWORD(retaddr) = 1;
        }
        else
        {
          LODWORD(retaddr) = 2;
        }
LABEL_29:
        v65 = v4->m_aabb.m_max.m_quad;
        v5 = (const char *)(v111 + v21);
        v66 = v7->m_queryObject.m_numTransforms - 1;
        v67 = 15;
        v68 = _mm_add_ps(v4->m_aabb.m_min.m_quad, v65);
        v69 = _mm_sub_ps(v65, v4->m_aabb.m_min.m_quad);
        if ( v66 < 0 )
        {
LABEL_36:
          hkpMoppFindAllVirtualMachine::queryOnTreeLeft(
            (hkpMoppFindAllVirtualMachine *)&v7->m_queryObject.m_primitives_out,
            &v6->0,
            v5);
          hkpMoppFindAllVirtualMachine::queryOnTreeRight(
            (hkpMoppFindAllVirtualMachine *)&v7->m_queryObject.m_primitives_out,
            &v6->0,
            v5);
          v4 = v121;
          v79 = 1;
          v44.m_quad = (__m128)fQueryLa.m_aabb.m_max;
          v45.m_quad = (__m128)fQueryLa.m_aabb.m_min;
        }
        else
        {
          v70 = v50 + 34;
          v71 = _mm_shuffle_ps(v69, v69, 85);
          v72 = _mm_shuffle_ps(v69, v69, 0);
          v73 = _mm_shuffle_ps(v68, v68, 85);
          v74 = _mm_shuffle_ps(v68, v68, 0);
          v75 = _mm_shuffle_ps(v69, v69, 170);
          v76 = _mm_shuffle_ps(v68, v68, 170);
          do
          {
            v77 = _mm_add_ps(
                    _mm_add_ps(_mm_add_ps(_mm_mul_ps(v70[-2], v72), _mm_mul_ps(v70[-1], v71)), _mm_mul_ps(*v70, v75)),
                    v70[1]);
            v78 = _mm_add_ps(
                    _mm_add_ps(_mm_add_ps(_mm_mul_ps(v70[-33], v73), _mm_mul_ps(*v50, v74)), _mm_mul_ps(v70[-32], v76)),
                    v70[-31]);
            if ( _mm_movemask_ps(_mm_cmpltps(_mm_sub_ps(v78, v77), (__m128)0i64)) != 15 )
            {
              v79 = 0;
              goto LABEL_37;
            }
            v50 += 4;
            v70 += 4;
            v67 &= _mm_movemask_ps(_mm_cmpltps(_mm_add_ps(v78, v77), (__m128)0i64));
            --v66;
          }
          while ( v66 >= 0 );
          if ( v67 == 15 )
            goto LABEL_36;
          v79 = 2;
        }
LABEL_37:
        if ( (_DWORD)retaddr == 2 )
        {
          if ( v79 == 2 )
          {
            hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObjectOptimized>::queryMoppTree(
              v7,
              v6,
              PCa,
              &fQueryLa);
            v4 = v121;
          }
          else
          {
            v5 = PCa;
            v4->m_aabb.m_min = (hkVector4f)v45.m_quad;
            v4->m_aabb.m_max = (hkVector4f)v44.m_quad;
          }
          continue;
        }
        if ( v79 == 2 )
          continue;
        return;
      case 38:
      case 39:
      case 40:
        v5 += 3;
        v80 = v9 - 38;
        v4->m_aabb.m_min.m_quad.m128_f32[v80] = (float)(*(&v6->m_offset_x + v80) + (v11 << v6->m_shift))
                                              * v7->m_ItoFScale;
        v82 = _mm_cvtsi32_si128(*(&v6->m_offset_x + v80) + ((unsigned int)(unsigned __int8)v8 << v6->m_shift));
        goto LABEL_45;
      case 41:
      case 42:
      case 43:
        v80 = v9 - 41;
        v4->m_aabb.m_min.m_quad.m128_f32[v80] = (float)((unsigned __int8)retaddr
                                                      + (((unsigned __int8)v8 + (v11 << 8)) << 8))
                                              * v7->m_ItoFScale;
        v81 = *((unsigned __int8 *)v5 + 6) + ((*((unsigned __int8 *)v5 + 5) + (*((unsigned __int8 *)v5 + 4) << 8)) << 8);
        v5 += 7;
        v82 = _mm_cvtsi32_si128(v81);
LABEL_45:
        v4->m_aabb.m_max.m_quad.m128_f32[v80] = COERCE_FLOAT(_mm_cvtepi32_ps(v82)) * v7->m_ItoFScale;
        if ( *v5 >= 0x26u && *v5 <= 0x2Bu )
          continue;
        v83 = v4->m_aabb.m_max.m_quad;
        v84 = v7->m_queryObject.m_numTransforms - 1;
        v85 = 15;
        retaddr = (hkpMoppFindAllVirtualMachine *)&v7->m_queryObject.m_primitives_out;
        v86 = (__m128 *)v7->m_queryObject.m_rotatedPlanes;
        v87 = _mm_add_ps(v4->m_aabb.m_min.m_quad, v83);
        v88 = _mm_sub_ps(v83, v4->m_aabb.m_min.m_quad);
        if ( v84 < 0 )
          goto LABEL_52;
        v89 = &v7->m_queryObject.m_absRotPlanes[0].m_rotation.m_col2.m_quad;
        v90 = _mm_shuffle_ps(v88, v88, 85);
        v91 = _mm_shuffle_ps(v88, v88, 0);
        v92 = _mm_shuffle_ps(v87, v87, 85);
        v93 = _mm_shuffle_ps(v87, v87, 0);
        v94 = _mm_shuffle_ps(v88, v88, 170);
        v95 = _mm_shuffle_ps(v87, v87, 170);
        do
        {
          v96 = _mm_add_ps(
                  _mm_add_ps(_mm_add_ps(_mm_mul_ps(v89[-2], v91), _mm_mul_ps(v89[-1], v90)), _mm_mul_ps(v94, *v89)),
                  v89[1]);
          v97 = _mm_add_ps(
                  _mm_add_ps(_mm_add_ps(_mm_mul_ps(v89[-33], v92), _mm_mul_ps(v93, *v86)), _mm_mul_ps(v89[-32], v95)),
                  v89[-31]);
          if ( _mm_movemask_ps(_mm_cmpltps(_mm_sub_ps(v97, v96), (__m128)0i64)) != 15 )
            return;
          v86 += 4;
          v89 += 4;
          v85 &= _mm_movemask_ps(_mm_cmpltps(_mm_add_ps(v97, v96), (__m128)0i64));
          --v84;
        }
        while ( v84 >= 0 );
        if ( v85 != 15 )
          continue;
LABEL_52:
        hkpMoppFindAllVirtualMachine::queryOnTreeLeft(
          (hkpMoppFindAllVirtualMachine *)&v7->m_queryObject.m_primitives_out,
          &v6->0,
          v5);
        hkpMoppFindAllVirtualMachine::queryOnTreeRight(retaddr, &v6->0, v5);
        return;
      case 48:
      case 49:
      case 50:
      case 51:
      case 52:
      case 53:
      case 54:
      case 55:
      case 56:
      case 57:
      case 58:
      case 59:
      case 60:
      case 61:
      case 62:
      case 63:
      case 64:
      case 65:
      case 66:
      case 67:
      case 68:
      case 69:
      case 70:
      case 71:
      case 72:
      case 73:
      case 74:
      case 75:
      case 76:
      case 77:
      case 78:
      case 79:
        v107 = v9 - 48;
        goto $add_Terminal_2;
      case 80:
        v107 = v11;
        goto $add_Terminal_2;
      case 81:
        v107 = (unsigned __int8)v8 + (v11 << 8);
        goto $add_Terminal_2;
      case 82:
        v107 = v10 + (((unsigned __int8)v8 + (v11 << 8)) << 8);
        goto $add_Terminal_2;
      case 83:
        v107 = *((unsigned __int8 *)v5 + 4) + ((v10 + (((unsigned __int8)v8 + (v11 << 8)) << 8)) << 8);
$add_Terminal_2:
        v108 = v7->m_primitives_out;
        LODWORD(retaddr) = v6->m_primitiveOffset + v107;
        if ( v7->m_primitives_out->m_size == (v7->m_primitives_out->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            v7->m_primitives_out,
            4);
        v109 = v108->m_data;
        v110 = v108->m_size;
        v108->m_size = v110 + 1;
        v109[v110].ID = (unsigned int)retaddr;
        return;
      case 96:
      case 97:
      case 98:
      case 99:
        v5 += 2;
        *(&v114 + (unsigned int)(v9 - 96)) = v11;
        goto $propertyCopy_2;
      case 100:
      case 101:
      case 102:
      case 103:
        v5 += 3;
        v103 = (unsigned __int8)v8 + (v11 << 8);
        v104 = (unsigned int)(v9 - 100);
        goto LABEL_70;
      case 104:
      case 105:
      case 106:
      case 107:
        v103 = *((unsigned __int8 *)v5 + 4) + (v11 << 24) + ((unsigned __int8)v8 << 16) + (v10 << 8);
        v104 = (unsigned int)(v9 - 104);
        v5 += 5;
LABEL_70:
        *(&v114 + v104) = v103;
$propertyCopy_2:
        v105 = v114;
        if ( v6 != (hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObjectOptimized>::hkpMoppUsingFloatAabbVirtualMachineQueryInt *)&v113 )
        {
          v113 = v6->m_primitiveOffset;
          v114 = v6->m_properties[0];
          v115 = v6->m_offset_x;
          v116 = v6->m_offset_y;
          v117 = v6->m_offset_z;
          v106 = v6->m_shift;
          v6 = (hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObjectOptimized>::hkpMoppUsingFloatAabbVirtualMachineQueryInt *)&v113;
          v118 = v106;
        }
        v114 = v105;
        continue;
      default:
        __debugbreak();
        continue;
    }
  }
}ine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObjectOptimized>::hkpMoppUsingFloatAabbVirtualMachineQueryInt *)&v113 )
        {
          v113 = v6->m_primitiveOffset;
          v114 = v6->m_properties[0];
          v115 = v6->m_offset_x;
          v116 = v6->m_offset_y;
          v117 = v6->m_offset_z;
          v106 = v6->m_shift;
          v6 = (hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObjectOptimized>::hkpMoppUsingFloatAabbVirtualMachineQueryInt *)&v113;
          v118 = v106;
        }
        v114 = v105;
        continue;
      default:
        __debugbreak();
        continue;
    }
  }
}§§§§нннн@}Вrwt

