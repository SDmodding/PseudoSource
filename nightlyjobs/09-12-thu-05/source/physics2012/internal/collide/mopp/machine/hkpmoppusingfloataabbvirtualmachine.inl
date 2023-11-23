// File Line: 24
// RVA: 0xDB3F00
void __fastcall hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObjectOptimized>::queryMoppTree(
        hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObjectOptimized> *this,
        hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObjectOptimized>::hkpMoppUsingFloatAabbVirtualMachineQueryInt *query,
        char *PC,
        hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObjectOptimized>::hkpMoppTempAabb *fQueryL)
{
  int v8; // r11d
  int v9; // r9d
  unsigned __int8 v10; // dl
  unsigned __int8 v11; // r8
  hkVector4f v12; // xmm1
  const char *v13; // rbx
  int v14; // ecx
  hkVector4f v15; // xmm1
  int v16; // eax
  int v17; // r9d
  __int64 v18; // rdx
  __m128i v19; // xmm0
  int v20; // eax
  const char *v21; // rbx
  int v22; // ecx
  hkVector4f v23; // xmm1
  int v24; // edx
  __int64 v25; // r8
  unsigned int v26; // r9d
  __m128i v27; // xmm0
  int v28; // ecx
  hkVector4f v29; // xmm1
  __int64 v30; // rdx
  __int64 v31; // r8
  int v32; // eax
  __int64 v33; // rdx
  unsigned int v34; // ecx
  __m128i v35; // xmm0
  unsigned int v36; // eax
  __int64 v37; // r9
  int i; // eax
  __int64 v39; // rdx
  int v40; // ecx
  int v41; // ecx
  __int64 v42; // r8
  int v43; // eax
  hkVector4f v44; // xmm11
  hkVector4f v45; // xmm12
  __int64 v46; // rax
  int v47; // r11d
  int v48; // r9d
  hkMoppPlanesQueryObjectOptimized *p_m_queryObject; // rax
  hkTransformf *m_rotatedPlanes; // r8
  __m128 v51; // xmm5
  __m128 v52; // xmm6
  hkTransformf *v53; // rdx
  hkVector4f *p_m_col2; // rcx
  __m128 v55; // xmm7
  __m128 v56; // xmm8
  __m128 v57; // xmm9
  __m128 v58; // xmm10
  __m128 v59; // xmm6
  __m128 v60; // xmm5
  __m128 v61; // xmm3
  __m128 v62; // xmm2
  hkVector4f v63; // xmm5
  int v64; // edx
  int v65; // r9d
  __m128 v66; // xmm6
  __m128 v67; // xmm5
  __m128 *p_m_quad; // rcx
  __m128 v69; // xmm7
  __m128 v70; // xmm8
  __m128 v71; // xmm9
  __m128 v72; // xmm10
  __m128 v73; // xmm5
  __m128 v74; // xmm6
  __m128 v75; // xmm3
  __m128 v76; // xmm2
  int v77; // eax
  __int64 v78; // rdx
  unsigned int v79; // ecx
  __m128i v80; // xmm0
  hkVector4f v81; // xmm5
  int v82; // r8d
  int v83; // r9d
  hkTransformf *v84; // rdx
  __m128 v85; // xmm6
  __m128 v86; // xmm5
  hkVector4f *v87; // rcx
  __m128 v88; // xmm7
  __m128 v89; // xmm8
  __m128 v90; // xmm9
  __m128 v91; // xmm10
  __m128 v92; // xmm5
  __m128 v93; // xmm6
  __m128 v94; // xmm3
  __m128 v95; // xmm2
  unsigned int m_primitiveOffset; // eax
  int m_shift; // eax
  int v98; // eax
  int v99; // ecx
  int v100; // eax
  int v101; // edx
  __int64 v102; // rax
  unsigned int v103; // ecx
  int v104; // eax
  int v105; // ecx
  hkArray<hkpMoppPrimitiveInfo,hkContainerHeapAllocator> *m_primitives_out; // rbx
  hkpMoppPrimitiveInfo *m_data; // rcx
  __int64 m_size; // rdx
  int v109; // [rsp+8h] [rbp-79h]
  char *PCa; // [rsp+10h] [rbp-71h]
  char *PCb; // [rsp+10h] [rbp-71h]
  hkTransformf *v112; // [rsp+18h] [rbp-69h]
  unsigned int v113; // [rsp+20h] [rbp-61h] BYREF
  unsigned int v114; // [rsp+24h] [rbp-5Dh]
  int m_offset_x; // [rsp+28h] [rbp-59h]
  int m_offset_y; // [rsp+2Ch] [rbp-55h]
  int m_offset_z; // [rsp+30h] [rbp-51h]
  int v118; // [rsp+34h] [rbp-4Dh]
  hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObjectOptimized>::hkpMoppTempAabb fQueryLa; // [rsp+38h] [rbp-49h] BYREF
  hkMoppPlanesQueryObjectOptimized *retaddr; // [rsp+F8h] [rbp+77h]
  hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObjectOptimized>::hkpMoppTempAabb *v121; // [rsp+100h] [rbp+7Fh]

  while ( 2 )
  {
    LOBYTE(v8) = PC[2];
    v9 = (unsigned __int8)*PC;
    v10 = PC[3];
    v11 = PC[1];
    LOBYTE(retaddr) = v10;
    switch ( *PC )
    {
      case 0:
        return;
      case 1:
      case 2:
      case 3:
      case 4:
        m_offset_x = query->m_offset_x + (v11 << query->m_shift);
        m_offset_y = query->m_offset_y + ((unsigned __int8)v8 << query->m_shift);
        m_offset_z = query->m_offset_z + (v10 << query->m_shift);
        PC += 4;
        v118 = query->m_shift - v9;
        v114 = query->m_properties[0];
        m_primitiveOffset = query->m_primitiveOffset;
        query = (hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObjectOptimized>::hkpMoppUsingFloatAabbVirtualMachineQueryInt *)&v113;
        v113 = m_primitiveOffset;
        continue;
      case 5:
        PC += v11 + 2;
        continue;
      case 6:
        PC += 256 * v11 + (unsigned __int8)v8 + 3;
        continue;
      case 7:
        PC += 0x10000 * v11 + 256 * (unsigned __int8)v8 + (unsigned int)v10 + 4;
        continue;
      case 8:
        PC += 0x1000000 * v11 + 256 * (v10 + ((unsigned __int8)v8 << 8)) + (unsigned int)(unsigned __int8)PC[4] + 5;
        continue;
      case 9:
        if ( query != (hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObjectOptimized>::hkpMoppUsingFloatAabbVirtualMachineQueryInt *)&v113 )
        {
          v113 = query->m_primitiveOffset;
          v114 = query->m_properties[0];
          m_offset_x = query->m_offset_x;
          m_offset_y = query->m_offset_y;
          m_offset_z = query->m_offset_z;
          m_shift = query->m_shift;
          query = (hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObjectOptimized>::hkpMoppUsingFloatAabbVirtualMachineQueryInt *)&v113;
          v118 = m_shift;
        }
        v113 += v11;
        PC += 2;
        continue;
      case 10:
        if ( query != (hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObjectOptimized>::hkpMoppUsingFloatAabbVirtualMachineQueryInt *)&v113 )
        {
          v113 = query->m_primitiveOffset;
          v114 = query->m_properties[0];
          m_offset_x = query->m_offset_x;
          m_offset_y = query->m_offset_y;
          m_offset_z = query->m_offset_z;
          v98 = query->m_shift;
          query = (hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObjectOptimized>::hkpMoppUsingFloatAabbVirtualMachineQueryInt *)&v113;
          v118 = v98;
        }
        v113 += (unsigned __int8)v8 + (v11 << 8);
        PC += 3;
        continue;
      case 11:
        v99 = (unsigned __int8)PC[4] + (v11 << 24) + ((unsigned __int8)v8 << 16) + (v10 << 8);
        if ( query != (hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObjectOptimized>::hkpMoppUsingFloatAabbVirtualMachineQueryInt *)&v113 )
        {
          v113 = query->m_primitiveOffset;
          v114 = query->m_properties[0];
          m_offset_x = query->m_offset_x;
          m_offset_y = query->m_offset_y;
          m_offset_z = query->m_offset_z;
          v100 = query->m_shift;
          query = (hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObjectOptimized>::hkpMoppUsingFloatAabbVirtualMachineQueryInt *)&v113;
          v118 = v100;
        }
        v113 = v99;
        PC += 5;
        continue;
      case 16:
      case 17:
      case 18:
        v14 = query->m_shift;
        v15.m_quad = (__m128)fQueryL->m_aabb.m_max;
        v16 = v9 - 16;
        v17 = 0;
        v18 = v16;
        fQueryLa.m_aabb.m_min = fQueryL->m_aabb.m_min;
        fQueryLa.m_aabb.m_max = (hkVector4f)v15.m_quad;
        v19 = _mm_cvtsi32_si128(*(&query->m_offset_x + v16) + (v11 << v14));
        v20 = (unsigned __int8)v8;
        v8 = (unsigned __int8)retaddr;
        fQueryL->m_aabb.m_max.m_quad.m128_f32[v18] = _mm_cvtepi32_ps(v19).m128_f32[0] * this->m_ItoFScale;
        v21 = PC + 4;
        fQueryLa.m_aabb.m_min.m_quad.m128_f32[v18] = (float)(*(&query->m_offset_x + v18) + (v20 << query->m_shift))
                                                   * this->m_ItoFScale;
        goto LABEL_6;
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
        v12.m_quad = (__m128)fQueryL->m_aabb.m_max;
        v13 = PC + 4;
        fQueryLa.m_aabb.m_min = fQueryL->m_aabb.m_min;
        fQueryLa.m_aabb.m_max = (hkVector4f)v12.m_quad;
        hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObjectOptimized>::queryMoppTree(
          this,
          query,
          v13,
          &fQueryLa);
        fQueryL = v121;
        PC = (char *)&v13[(unsigned __int8)retaddr];
        continue;
      case 32:
      case 33:
      case 34:
        v22 = query->m_shift;
        v23.m_quad = (__m128)fQueryL->m_aabb.m_max;
        v21 = PC + 3;
        v24 = v11;
        fQueryLa.m_aabb.m_min = fQueryL->m_aabb.m_min;
        fQueryLa.m_aabb.m_max = (hkVector4f)v23.m_quad;
        v25 = v9 - 32;
        v8 = (unsigned __int8)v8;
        v26 = *(&query->m_offset_x + v25) + ((v24 + 1) << v22);
        fQueryLa.m_aabb.m_min.m_quad.m128_f32[v25] = (float)(*(&query->m_offset_x + v25) + (v24 << v22))
                                                   * this->m_ItoFScale;
        v27 = _mm_cvtsi32_si128(v26);
        v17 = 0;
        fQueryL->m_aabb.m_max.m_quad.m128_f32[v25] = _mm_cvtepi32_ps(v27).m128_f32[0] * this->m_ItoFScale;
        goto LABEL_6;
      case 35:
      case 36:
      case 37:
        v28 = query->m_shift;
        v29.m_quad = (__m128)fQueryL->m_aabb.m_max;
        v30 = v9 - 35;
        fQueryLa.m_aabb.m_min = fQueryL->m_aabb.m_min;
        fQueryLa.m_aabb.m_max = (hkVector4f)v29.m_quad;
        fQueryL->m_aabb.m_max.m_quad.m128_f32[v30] = (float)(*(&query->m_offset_x + v30) + (v11 << v28))
                                                   * this->m_ItoFScale;
        fQueryLa.m_aabb.m_min.m_quad.m128_f32[v30] = (float)(*(&query->m_offset_x + v30)
                                                           + ((unsigned __int8)v8 << query->m_shift))
                                                   * this->m_ItoFScale;
        v17 = (unsigned __int8)PC[4] + ((unsigned __int8)retaddr << 8);
        v8 = (unsigned __int8)PC[6] + ((unsigned __int8)PC[5] << 8);
        v21 = PC + 7;
LABEL_6:
        v31 = v17;
        v109 = v17;
        v32 = (unsigned __int8)v21[v17];
        if ( (unsigned int)v32 >= 0x26 )
        {
          do
          {
            if ( v32 > 43 )
              break;
            if ( v32 < 41 )
            {
              v17 += 3;
              v33 = v32 - 38;
              fQueryL->m_aabb.m_min.m_quad.m128_f32[v33] = (float)(*(&query->m_offset_x + v33)
                                                                 + ((unsigned __int8)v21[v31 + 1] << query->m_shift))
                                                         * this->m_ItoFScale;
              v36 = *(&query->m_offset_x + v33) + ((unsigned __int8)v21[v31 + 2] << query->m_shift);
              v31 += 3i64;
              v35 = _mm_cvtsi32_si128(v36);
            }
            else
            {
              v17 += 7;
              v33 = v32 - 41;
              fQueryL->m_aabb.m_min.m_quad.m128_f32[v33] = (float)((unsigned __int8)v21[v31 + 3]
                                                                 + ((((unsigned __int8)v21[v31 + 1] << 8)
                                                                   + (unsigned __int8)v21[v31 + 2]) << 8))
                                                         * this->m_ItoFScale;
              v34 = (unsigned __int8)v21[v31 + 6]
                  + ((((unsigned __int8)v21[v31 + 4] << 8) + (unsigned __int8)v21[v31 + 5]) << 8);
              v31 += 7i64;
              v35 = _mm_cvtsi32_si128(v34);
            }
            fQueryL->m_aabb.m_max.m_quad.m128_f32[v33] = _mm_cvtepi32_ps(v35).m128_f32[0] * this->m_ItoFScale;
            v32 = (unsigned __int8)v21[v31];
          }
          while ( (unsigned int)v32 >= 0x26 );
          v109 = v17;
        }
        v37 = v8;
        for ( i = (unsigned __int8)v21[v8]; (unsigned int)i >= 0x26; i = (unsigned __int8)v21[v37] )
        {
          if ( i > 43 )
            break;
          if ( i < 41 )
          {
            v41 = query->m_shift;
            v8 += 3;
            v42 = i - 38;
            fQueryLa.m_aabb.m_min.m_quad.m128_f32[v42] = (float)(*(&query->m_offset_x + v42)
                                                               + ((unsigned __int8)v21[v37 + 1] << v41))
                                                       * this->m_ItoFScale;
            v43 = *(&query->m_offset_x + v42) + ((unsigned __int8)v21[v37 + 2] << v41);
            v37 += 3i64;
            fQueryLa.m_aabb.m_max.m_quad.m128_f32[v42] = (float)v43 * this->m_ItoFScale;
          }
          else
          {
            v8 += 7;
            v39 = i - 41;
            fQueryLa.m_aabb.m_min.m_quad.m128_f32[v39] = (float)((unsigned __int8)v21[v37 + 3]
                                                               + ((((unsigned __int8)v21[v37 + 1] << 8)
                                                                 + (unsigned __int8)v21[v37 + 2]) << 8))
                                                       * this->m_ItoFScale;
            v40 = (unsigned __int8)v21[v37 + 6]
                + ((((unsigned __int8)v21[v37 + 4] << 8) + (unsigned __int8)v21[v37 + 5]) << 8);
            v37 += 7i64;
            fQueryLa.m_aabb.m_max.m_quad.m128_f32[v39] = (float)v40 * this->m_ItoFScale;
          }
        }
        v44.m_quad = (__m128)fQueryLa.m_aabb.m_max;
        v45.m_quad = (__m128)fQueryLa.m_aabb.m_min;
        v46 = v8;
        v47 = 15;
        v48 = this->m_queryObject.m_numTransforms - 1;
        PCa = (char *)&v21[v46];
        p_m_queryObject = &this->m_queryObject;
        m_rotatedPlanes = this->m_queryObject.m_rotatedPlanes;
        v51 = _mm_add_ps(fQueryLa.m_aabb.m_max.m_quad, fQueryLa.m_aabb.m_min.m_quad);
        v52 = _mm_sub_ps(fQueryLa.m_aabb.m_max.m_quad, fQueryLa.m_aabb.m_min.m_quad);
        v53 = this->m_queryObject.m_rotatedPlanes;
        if ( v48 < 0 )
          goto LABEL_27;
        p_m_col2 = &this->m_queryObject.m_absRotPlanes[0].m_rotation.m_col2;
        v55 = _mm_shuffle_ps(v52, v52, 85);
        v56 = _mm_shuffle_ps(v52, v52, 0);
        v57 = _mm_shuffle_ps(v51, v51, 85);
        v58 = _mm_shuffle_ps(v51, v51, 0);
        v59 = _mm_shuffle_ps(v52, v52, 170);
        v60 = _mm_shuffle_ps(v51, v51, 170);
        do
        {
          v61 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_mul_ps(p_m_col2[-2].m_quad, v56), _mm_mul_ps(p_m_col2[-1].m_quad, v55)),
                    _mm_mul_ps(p_m_col2->m_quad, v59)),
                  p_m_col2[1].m_quad);
          v62 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_mul_ps(p_m_col2[-33].m_quad, v57), _mm_mul_ps(v53->m_rotation.m_col0.m_quad, v58)),
                    _mm_mul_ps(p_m_col2[-32].m_quad, v60)),
                  p_m_col2[-31].m_quad);
          if ( _mm_movemask_ps(_mm_cmplt_ps(_mm_sub_ps(v62, v61), (__m128)0i64)) != 15 )
          {
            LODWORD(retaddr) = 0;
            goto LABEL_28;
          }
          ++v53;
          p_m_col2 += 4;
          v47 &= _mm_movemask_ps(_mm_cmplt_ps(_mm_add_ps(v62, v61), (__m128)0i64));
          --v48;
        }
        while ( v48 >= 0 );
        if ( v47 == 15 )
        {
          p_m_queryObject = &this->m_queryObject;
LABEL_27:
          hkpMoppFindAllVirtualMachine::queryOnTreeLeft(p_m_queryObject, query, PCa);
          hkpMoppFindAllVirtualMachine::queryOnTreeRight(&this->m_queryObject, query, PCb);
          fQueryL = v121;
          m_rotatedPlanes = v112;
          v44.m_quad = (__m128)fQueryLa.m_aabb.m_max;
          v45.m_quad = (__m128)fQueryLa.m_aabb.m_min;
          LODWORD(retaddr) = 1;
        }
        else
        {
          LODWORD(retaddr) = 2;
        }
LABEL_28:
        v63.m_quad = (__m128)fQueryL->m_aabb.m_max;
        PC = (char *)&v21[v109];
        v64 = this->m_queryObject.m_numTransforms - 1;
        v65 = 15;
        v66 = _mm_add_ps(fQueryL->m_aabb.m_min.m_quad, v63.m_quad);
        v67 = _mm_sub_ps(v63.m_quad, fQueryL->m_aabb.m_min.m_quad);
        if ( v64 < 0 )
        {
LABEL_35:
          hkpMoppFindAllVirtualMachine::queryOnTreeLeft(&this->m_queryObject, query, PC);
          hkpMoppFindAllVirtualMachine::queryOnTreeRight(&this->m_queryObject, query, PC);
          fQueryL = v121;
          v77 = 1;
          v44.m_quad = (__m128)fQueryLa.m_aabb.m_max;
          v45.m_quad = (__m128)fQueryLa.m_aabb.m_min;
        }
        else
        {
          p_m_quad = &m_rotatedPlanes[8].m_rotation.m_col2.m_quad;
          v69 = _mm_shuffle_ps(v67, v67, 85);
          v70 = _mm_shuffle_ps(v67, v67, 0);
          v71 = _mm_shuffle_ps(v66, v66, 85);
          v72 = _mm_shuffle_ps(v66, v66, 0);
          v73 = _mm_shuffle_ps(v67, v67, 170);
          v74 = _mm_shuffle_ps(v66, v66, 170);
          do
          {
            v75 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_mul_ps(p_m_quad[-2], v70), _mm_mul_ps(p_m_quad[-1], v69)),
                      _mm_mul_ps(*p_m_quad, v73)),
                    p_m_quad[1]);
            v76 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(p_m_quad[-33], v71),
                        _mm_mul_ps(m_rotatedPlanes->m_rotation.m_col0.m_quad, v72)),
                      _mm_mul_ps(p_m_quad[-32], v74)),
                    p_m_quad[-31]);
            if ( _mm_movemask_ps(_mm_cmplt_ps(_mm_sub_ps(v76, v75), (__m128)0i64)) != 15 )
            {
              v77 = 0;
              goto LABEL_36;
            }
            ++m_rotatedPlanes;
            p_m_quad += 4;
            v65 &= _mm_movemask_ps(_mm_cmplt_ps(_mm_add_ps(v76, v75), (__m128)0i64));
            --v64;
          }
          while ( v64 >= 0 );
          if ( v65 == 15 )
            goto LABEL_35;
          v77 = 2;
        }
LABEL_36:
        if ( (_DWORD)retaddr == 2 )
        {
          if ( v77 == 2 )
          {
            hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObjectOptimized>::queryMoppTree(
              this,
              query,
              PCa,
              &fQueryLa);
            fQueryL = v121;
          }
          else
          {
            PC = PCa;
            fQueryL->m_aabb.m_min = (hkVector4f)v45.m_quad;
            fQueryL->m_aabb.m_max = (hkVector4f)v44.m_quad;
          }
          continue;
        }
        if ( v77 == 2 )
          continue;
        return;
      case 38:
      case 39:
      case 40:
        PC += 3;
        v78 = v9 - 38;
        fQueryL->m_aabb.m_min.m_quad.m128_f32[v78] = (float)(*(&query->m_offset_x + v78) + (v11 << query->m_shift))
                                                   * this->m_ItoFScale;
        v80 = _mm_cvtsi32_si128(*(&query->m_offset_x + v78) + ((unsigned __int8)v8 << query->m_shift));
        goto LABEL_44;
      case 41:
      case 42:
      case 43:
        v78 = v9 - 41;
        fQueryL->m_aabb.m_min.m_quad.m128_f32[v78] = (float)((unsigned __int8)retaddr
                                                           + (((unsigned __int8)v8 + (v11 << 8)) << 8))
                                                   * this->m_ItoFScale;
        v79 = (unsigned __int8)PC[6] + (((unsigned __int8)PC[5] + ((unsigned __int8)PC[4] << 8)) << 8);
        PC += 7;
        v80 = _mm_cvtsi32_si128(v79);
LABEL_44:
        fQueryL->m_aabb.m_max.m_quad.m128_f32[v78] = _mm_cvtepi32_ps(v80).m128_f32[0] * this->m_ItoFScale;
        if ( (unsigned __int8)*PC >= 0x26u && (unsigned __int8)*PC <= 0x2Bu )
          continue;
        v81.m_quad = (__m128)fQueryL->m_aabb.m_max;
        v82 = this->m_queryObject.m_numTransforms - 1;
        v83 = 15;
        retaddr = &this->m_queryObject;
        v84 = this->m_queryObject.m_rotatedPlanes;
        v85 = _mm_add_ps(fQueryL->m_aabb.m_min.m_quad, v81.m_quad);
        v86 = _mm_sub_ps(v81.m_quad, fQueryL->m_aabb.m_min.m_quad);
        if ( v82 < 0 )
          goto LABEL_51;
        v87 = &this->m_queryObject.m_absRotPlanes[0].m_rotation.m_col2;
        v88 = _mm_shuffle_ps(v86, v86, 85);
        v89 = _mm_shuffle_ps(v86, v86, 0);
        v90 = _mm_shuffle_ps(v85, v85, 85);
        v91 = _mm_shuffle_ps(v85, v85, 0);
        v92 = _mm_shuffle_ps(v86, v86, 170);
        v93 = _mm_shuffle_ps(v85, v85, 170);
        do
        {
          v94 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_mul_ps(v87[-2].m_quad, v89), _mm_mul_ps(v87[-1].m_quad, v88)),
                    _mm_mul_ps(v92, v87->m_quad)),
                  v87[1].m_quad);
          v95 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_mul_ps(v87[-33].m_quad, v90), _mm_mul_ps(v91, v84->m_rotation.m_col0.m_quad)),
                    _mm_mul_ps(v87[-32].m_quad, v93)),
                  v87[-31].m_quad);
          if ( _mm_movemask_ps(_mm_cmplt_ps(_mm_sub_ps(v95, v94), (__m128)0i64)) != 15 )
            return;
          ++v84;
          v87 += 4;
          v83 &= _mm_movemask_ps(_mm_cmplt_ps(_mm_add_ps(v95, v94), (__m128)0i64));
          --v82;
        }
        while ( v82 >= 0 );
        if ( v83 != 15 )
          continue;
LABEL_51:
        hkpMoppFindAllVirtualMachine::queryOnTreeLeft(&this->m_queryObject, query, PC);
        hkpMoppFindAllVirtualMachine::queryOnTreeRight(retaddr, query, PC);
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
        v105 = v9 - 48;
        goto $add_Terminal_2;
      case 80:
        v105 = v11;
        goto $add_Terminal_2;
      case 81:
        v105 = (unsigned __int8)v8 + (v11 << 8);
        goto $add_Terminal_2;
      case 82:
        v105 = v10 + (((unsigned __int8)v8 + (v11 << 8)) << 8);
        goto $add_Terminal_2;
      case 83:
        v105 = (unsigned __int8)PC[4] + ((v10 + (((unsigned __int8)v8 + (v11 << 8)) << 8)) << 8);
$add_Terminal_2:
        m_primitives_out = this->m_primitives_out;
        LODWORD(retaddr) = query->m_primitiveOffset + v105;
        if ( this->m_primitives_out->m_size == (this->m_primitives_out->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(
            &hkContainerHeapAllocator::s_alloc,
            (const void **)&this->m_primitives_out->m_data,
            4);
        m_data = m_primitives_out->m_data;
        m_size = m_primitives_out->m_size;
        m_primitives_out->m_size = m_size + 1;
        m_data[m_size].ID = (unsigned int)retaddr;
        return;
      case 96:
      case 97:
      case 98:
      case 99:
        PC += 2;
        *(&v114 + (unsigned int)(v9 - 96)) = v11;
        goto $propertyCopy_2;
      case 100:
      case 101:
      case 102:
      case 103:
        PC += 3;
        v101 = (unsigned __int8)v8 + (v11 << 8);
        v102 = (unsigned int)(v9 - 100);
        goto LABEL_69;
      case 104:
      case 105:
      case 106:
      case 107:
        v101 = (unsigned __int8)PC[4] + (v11 << 24) + ((unsigned __int8)v8 << 16) + (v10 << 8);
        v102 = (unsigned int)(v9 - 104);
        PC += 5;
LABEL_69:
        *(&v114 + v102) = v101;
$propertyCopy_2:
        v103 = v114;
        if ( query != (hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObjectOptimized>::hkpMoppUsingFloatAabbVirtualMachineQueryInt *)&v113 )
        {
          v113 = query->m_primitiveOffset;
          v114 = query->m_properties[0];
          m_offset_x = query->m_offset_x;
          m_offset_y = query->m_offset_y;
          m_offset_z = query->m_offset_z;
          v104 = query->m_shift;
          query = (hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObjectOptimized>::hkpMoppUsingFloatAabbVirtualMachineQueryInt *)&v113;
          v118 = v104;
        }
        v114 = v103;
        continue;
      default:
        __debugbreak();
        continue;
    }
  }
}eryObjectOptimized>::hkpMoppUsingFloatAabbVirtualMachineQueryInt *)&v113 )
        {
          v113 = query->m_primitiveOffset;
          v114 = query->m_properties[0];
          m_offset_x = query->m_offset_x;
          m_offset_y = query->m

