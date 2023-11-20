// File Line: 39
// RVA: 0xDC7BC0
void __fastcall hkGskAgentUtil_processCollisionNoTim(hkpAgent3Input *input, hkpAgentEntry *entry, void *agentData, hkpGskCache *gskCache, hkpGskManifold *gskManifold, hkVector4f *separatingNormal, int explicitlyAllowNewPoint, hkpProcessCollisionOutput *output)
{
  hkpCdBody *v8; // r11
  hkVector4f *v9; // rbx
  hkpGskCache *newPoint; // r15
  hkpAgent3Input *v11; // rsi
  _BYTE *v12; // rdi
  hkpConvexShape *v13; // r10
  hkVector4f *v14; // r9
  float v15; // xmm0_4
  __m128 v16; // xmm1
  int v17; // eax
  hkpCdBody *v18; // rax
  __m128 v19; // xmm6
  hkpGskManifold *v20; // r14
  char v21; // al
  hkpProcessCollisionOutput *v22; // rdi
  int v23; // edx
  int v24; // er13
  int v25; // er12
  hkpCdBody *v26; // rbx
  float v27; // xmm1_4
  hkpShape *v28; // rcx
  float v29; // xmm2_4
  float v30; // xmm2_4
  __int64 v31; // r8
  hkBaseObjectVtbl *v32; // rax
  __m128 *v33; // rax
  __int64 v34; // rcx
  __m128 v35; // xmm3
  __m128 v36; // xmm4
  __m128 v37; // xmm5
  __m128 v38; // xmm6
  __int64 v39; // r8
  hkcdVertex *v40; // rdx
  __m128 v41; // xmm1
  hkcdVertex *v42; // rbx
  __m128 *v43; // rax
  __m128 v44; // xmm3
  __m128 v45; // xmm4
  __m128 v46; // xmm5
  __m128 v47; // xmm6
  __int64 v48; // rcx
  signed __int64 v49; // rax
  __m128 v50; // xmm1
  unsigned __int64 newCdPointInResultArray; // rbx
  hkpProcessCollisionInput *v52; // r9
  hkpCollisionQualityInfo *v53; // rdx
  unsigned int *v54; // rdx
  hkpProcessCdPoint *v55; // r12
  int v56; // eax
  hkpAgentEntry *v57; // r13
  hkpProcessCollisionOutput::PotentialInfo *v58; // rcx
  unsigned __int64 *v59; // rdx
  unsigned __int64 v60; // rax
  unsigned __int16 v61; // ax
  hkpProcessCollisionOutput::PotentialInfo *v62; // rax
  hkVector4f v63; // [rsp+50h] [rbp-B0h]
  hkpGskManifold::ContactPoint *v64; // [rsp+60h] [rbp-A0h]
  hkVector4f pointOnBOut; // [rsp+70h] [rbp-90h]
  hkpProcessCdPoint *resultPointArray; // [rsp+80h] [rbp-80h]
  hkpCdBody *v67; // [rsp+88h] [rbp-78h]
  hkpGsk::GetClosesetPointInput inputa; // [rsp+90h] [rbp-70h]
  hkpGskManifoldWork work; // [rsp+C0h] [rbp-40h]
  hkResult result; // [rsp+230h] [rbp+130h]
  hkpAgentEntry *v71; // [rsp+238h] [rbp+138h]
  void *v72; // [rsp+240h] [rbp+140h]

  v72 = agentData;
  v71 = entry;
  v8 = input->m_bodyA.m_storage;
  v9 = separatingNormal;
  newPoint = gskCache;
  v11 = input;
  v12 = agentData;
  inputa.m_shapeA.m_storage = (hkpConvexShape *)input->m_bodyA.m_storage->m_shape;
  v13 = (hkpConvexShape *)input->m_bodyB.m_storage->m_shape;
  v14 = separatingNormal;
  inputa.m_aTb.m_storage = &input->m_aTb;
  inputa.m_shapeB.m_storage = v13;
  inputa.m_transformA.m_storage = (hkTransformf *)v8->m_motion;
  v15 = input->m_input.m_storage->m_tolerance.m_storage;
  *((_BYTE *)agentData + 11) &= 0xEFu;
  inputa.m_collisionTolerance.m_storage = v15;
  if ( hkpGsk::getClosestPoint(&result, &inputa, newPoint, v14, &pointOnBOut)->m_enum == 1 )
  {
    if ( gskManifold->m_numContactPoints )
      hkGskManifold_cleanup(gskManifold, v11->m_contactMgr.m_storage, output->m_constraintOwner.m_storage);
    return;
  }
  v16 = v9->m_quad;
  v63.m_quad = v9->m_quad;
  if ( inputa.m_shapeB.m_storage->m_type.m_storage == 2 )
  {
    v17 = ((__int64 (__fastcall *)(hkpConvexShape *, unsigned __int16 *, char *, hkVector4f *, const void *, hkpConvexShape *, const void *, hkVector4f *))inputa.m_shapeB.m_storage->vfptr[6].__first_virtual_table_function__)(
            inputa.m_shapeB.m_storage,
            &newPoint->m_vertices[(unsigned __int8)newPoint->m_dimA],
            &newPoint->m_dimB,
            &pointOnBOut,
            v11->m_bodyB.m_storage->m_motion,
            inputa.m_shapeA.m_storage,
            v11->m_bodyA.m_storage->m_motion,
            &v63);
  }
  else
  {
    if ( inputa.m_shapeA.m_storage->m_type.m_storage != 2 || BYTE2(inputa.m_shapeA.m_storage[1].vfptr) == 6 )
      goto LABEL_13;
    v18 = v11->m_bodyB.m_storage;
    v19 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64);
    v63.m_quad = _mm_xor_ps(v16, v19);
    v17 = ((__int64 (__fastcall *)(hkpConvexShape *, hkpGskCache *, char *, hkVector4f *, const void *, hkpConvexShape *, const void *, hkVector4f *))inputa.m_shapeA.m_storage->vfptr[6].__first_virtual_table_function__)(
            inputa.m_shapeA.m_storage,
            newPoint,
            &newPoint->m_dimA,
            &pointOnBOut,
            v11->m_bodyA.m_storage->m_motion,
            inputa.m_shapeB.m_storage,
            v18->m_motion,
            &v63);
    v63.m_quad = _mm_xor_ps(v63.m_quad, v19);
  }
  if ( !v17 )
  {
    hkGskManifold_cleanup(gskManifold, v11->m_contactMgr.m_storage, output->m_constraintOwner.m_storage);
    return;
  }
  if ( v17 == 1 )
    v12[11] |= 0x10u;
LABEL_13:
  v20 = gskManifold;
  v21 = hkGskManifold_doesPointExistAndResort(gskManifold, newPoint);
  v22 = output;
  v23 = (unsigned __int8)v20->m_numContactPoints;
  v24 = v21 & 2 | explicitlyAllowNewPoint;
  v25 = v21 & 1;
  resultPointArray = output->m_firstFreeContactPoint.m_storage;
  if ( v23 > v25 )
  {
    v26 = v11->m_bodyA.m_storage;
    v27 = v11->m_input.m_storage->m_tolerance.m_storage;
    v67 = v11->m_bodyB.m_storage;
    work.m_keepContact.m_storage = v27;
    v28 = v26->m_shape;
    *(_QWORD *)&result.m_enum = v67->m_shape;
    v29 = *(float *)&v28[1].vfptr;
    work.m_radiusA.m_storage = v29;
    v30 = (float)(v29 + v27) + *(float *)(*(_QWORD *)&result.m_enum + 32i64);
    work.m_radiusB.m_storage = *(float *)(*(_QWORD *)&result.m_enum + 32i64);
    work.m_masterNormal = (hkVector4f)v63.m_quad;
    work.m_radiusSumSqrd.m_storage = v30 * v30;
    if ( (_BYTE)v23 )
    {
      v31 = (unsigned __int8)v20->m_numVertsA;
      v32 = v28->vfptr;
      v64 = &v20->m_contactPoints[v23];
      ((void (__fastcall *)(hkpShape *, hkpGskManifold::ContactPoint *, __int64, hkpGskManifoldWork *))v32[4].__first_virtual_table_function__)(
        v28,
        v64,
        v31,
        &work);
      v33 = (__m128 *)v26->m_motion;
      v34 = (unsigned __int8)v20->m_numVertsA;
      v35 = *v33;
      v36 = v33[1];
      v37 = v33[2];
      v38 = v33[3];
      v39 = (signed int)v34 - 1;
      v40 = &work.m_vertices[v39];
      do
      {
        v41 = v40->m_quad;
        --v40;
        --v39;
        v40[1].m_quad = _mm_add_ps(
                          _mm_add_ps(
                            _mm_add_ps(
                              _mm_mul_ps(_mm_shuffle_ps(v41, v41, 85), v36),
                              _mm_mul_ps(_mm_shuffle_ps(v41, v41, 0), v35)),
                            _mm_mul_ps(_mm_shuffle_ps(v41, v41, 170), v37)),
                          v38);
      }
      while ( v39 >= 0 );
      v42 = &work.m_vertices[v34];
      (*(void (__fastcall **)(_QWORD, __int64, _QWORD, hkcdVertex *))(**(_QWORD **)&result.m_enum + 72i64))(
        *(_QWORD *)&result.m_enum,
        (__int64)v64 + 2 * v34,
        (unsigned __int8)v20->m_numVertsB,
        v42);
      v43 = (__m128 *)v67->m_motion;
      v44 = *v43;
      v45 = v43[1];
      v46 = v43[2];
      v47 = v43[3];
      v48 = (unsigned __int8)v20->m_numVertsB - 1;
      v49 = (signed __int64)&v42[v48];
      do
      {
        v50 = *(__m128 *)v49;
        v49 -= 16i64;
        --v48;
        *(__m128 *)(v49 + 16) = _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(
                                      _mm_mul_ps(_mm_shuffle_ps(v50, v50, 85), v45),
                                      _mm_mul_ps(_mm_shuffle_ps(v50, v50, 0), v44)),
                                    _mm_mul_ps(_mm_shuffle_ps(v50, v50, 170), v46)),
                                  v47);
      }
      while ( v48 >= 0 );
    }
    v24 |= hkGskManifold_verifyAndGetPoints(v20, &work, v25, v22, v11->m_contactMgr.m_storage);
  }
  newCdPointInResultArray = (unsigned __int64)v22->m_firstFreeContactPoint.m_storage;
  *(hkVector4f *)newCdPointInResultArray = (hkVector4f)pointOnBOut.m_quad;
  *(hkVector4f *)(newCdPointInResultArray + 16) = (hkVector4f)v63.m_quad;
  if ( v25 )
  {
    *(_DWORD *)(newCdPointInResultArray + 32) = v20->m_contactPoints[0].m_id;
    ++v22->m_firstFreeContactPoint.m_storage;
  }
  else
  {
    v52 = v11->m_input.m_storage;
    v53 = v52->m_collisionQualityInfo.m_storage;
    if ( (unsigned __int8)newPoint->m_dimA + (unsigned __int8)newPoint->m_dimB == 4 )
      v54 = (unsigned int *)&v53->m_create4dContact;
    else
      v54 = (unsigned int *)&v53->m_createContact;
    if ( COERCE_FLOAT(_mm_shuffle_ps(separatingNormal->m_quad, separatingNormal->m_quad, 255)) >= COERCE_FLOAT(_mm_shuffle_ps((__m128)*v54, (__m128)*v54, 0))
      && !v24 )
    {
      goto LABEL_42;
    }
    v55 = resultPointArray;
    v56 = hkGskManifold_addPoint(
            v20,
            v11->m_bodyA.m_storage,
            v11->m_bodyB.m_storage,
            v52,
            v22,
            newPoint,
            (hkpProcessCdPoint *)newCdPointInResultArray,
            resultPointArray,
            v11->m_contactMgr.m_storage,
            (hkpGskManifoldUtilMgrHandling)(v52->m_enableDeprecatedWelding.m_bool != 0));
    switch ( v56 )
    {
      case 4:
        if ( *(_DWORD *)(newCdPointInResultArray + 32) == 0xFFFF )
        {
          if ( v22->m_potentialContacts.m_storage && (v57 = v71) != 0i64 )
          {
            ((void (__fastcall *)(hkpContactMgr *, hkResult *, signed __int64))v11->m_contactMgr.m_storage->vfptr[2].__vecDelDtor)(
              v11->m_contactMgr.m_storage,
              &result,
              1i64);
            if ( result.m_enum == HK_SUCCESS )
            {
              v58 = v22->m_potentialContacts.m_storage;
              v59 = (unsigned __int64 *)v58->m_firstFreePotentialContact;
              ++v58->m_firstFreePotentialContact;
              v60 = (unsigned __int64)v72;
              *v59 = newCdPointInResultArray;
              v59[2] = v60;
              v59[1] = (unsigned __int64)v57;
              ++v22->m_firstFreeContactPoint.m_storage;
              break;
            }
          }
          else
          {
            v61 = ((__int64 (__fastcall *)(hkpContactMgr *, hkpCdBody *, hkpCdBody *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *, hkpGskCache *, unsigned __int64))v11->m_contactMgr.m_storage->vfptr[1].__first_virtual_table_function__)(
                    v11->m_contactMgr.m_storage,
                    v11->m_bodyA.m_storage,
                    v11->m_bodyB.m_storage,
                    v11->m_input.m_storage,
                    v22,
                    newPoint,
                    newCdPointInResultArray);
            *(_DWORD *)(newCdPointInResultArray + 32) = v61;
            if ( v61 != 0xFFFF )
            {
              v20->m_contactPoints[0].m_id = v61;
              ++v22->m_firstFreeContactPoint.m_storage;
              break;
            }
          }
          hkGskManifold_removePoint(v20, 0);
          newCdPointInResultArray = (unsigned __int64)v55;
          break;
        }
        ++v22->m_firstFreeContactPoint.m_storage;
        break;
      case 5:
        newCdPointInResultArray = (unsigned __int64)v55;
        break;
      case 6:
        --v22->m_firstFreeContactPoint.m_storage;
        newCdPointInResultArray = (unsigned __int64)v55;
        break;
      default:
        newCdPointInResultArray = (unsigned __int64)&v55[v56];
        break;
    }
  }
LABEL_42:
  v62 = v22->m_potentialContacts.m_storage;
  if ( v62 && (hkpProcessCdPoint *)newCdPointInResultArray < v22->m_firstFreeContactPoint.m_storage )
  {
    *v62->m_firstFreeRepresentativeContact = (hkpProcessCdPoint *)newCdPointInResultArray;
    ++v22->m_potentialContacts.m_storage->m_firstFreeRepresentativeContact;
  }
}

