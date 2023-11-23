// File Line: 39
// RVA: 0xDC7BC0
void __fastcall hkGskAgentUtil_processCollisionNoTim(
        hkpAgent3Input *input,
        hkpAgentEntry *entry,
        hkpProcessCdPoint *agentData,
        hkpGskCache *gskCache,
        hkpGskManifold *gskManifold,
        hkVector4f *separatingNormal,
        int explicitlyAllowNewPoint,
        hkpProcessCollisionOutput *output)
{
  hkpCdBody *m_storage; // r11
  hkVector4f *v9; // rbx
  hkpConvexShape *m_shape; // r10
  hkVector4f *v14; // r9
  float v15; // xmm0_4
  __m128 m_quad; // xmm1
  int v17; // eax
  hkpCdBody *v18; // rax
  __m128 v19; // xmm6
  hkpGskManifold *v20; // r14
  char doesPointExistAndResort; // al
  hkpProcessCollisionOutput *v22; // rdi
  int m_numContactPoints; // edx
  int v24; // r13d
  int v25; // r12d
  hkpCdBody *v26; // rbx
  float v27; // xmm1_4
  hkpShape *v28; // rcx
  float v29; // xmm2_4
  __int64 m_numVertsA; // r8
  hkBaseObjectVtbl *vfptr; // rax
  __m128 *m_motion; // rax
  __int64 v33; // rcx
  __m128 v34; // xmm3
  __m128 v35; // xmm4
  __m128 v36; // xmm5
  __m128 v37; // xmm6
  __int64 v38; // r8
  hkcdVertex *v39; // rdx
  __m128 v40; // xmm1
  hkcdVertex *v41; // rbx
  __m128 *v42; // rax
  __m128 v43; // xmm3
  __m128 v44; // xmm4
  __m128 v45; // xmm5
  __m128 v46; // xmm6
  __int64 v47; // rcx
  __m128 *p_m_quad; // rax
  __m128 v49; // xmm1
  hkpProcessCdPoint *newCdPointInResultArray; // rbx
  hkpProcessCollisionInput *v51; // r9
  hkpCollisionQualityInfo *v52; // rdx
  unsigned int *p_m_create4dContact; // rdx
  hkpProcessCdPoint *v54; // r12
  int v55; // eax
  hkpAgentEntry *v56; // r13
  hkpProcessCollisionOutput::PotentialInfo *v57; // rcx
  hkpProcessCdPoint **p_m_contactPoint; // rdx
  hkpProcessCdPoint *v59; // rax
  unsigned __int16 v60; // ax
  hkpProcessCollisionOutput::PotentialInfo *v61; // rax
  __m128 v62; // [rsp+50h] [rbp-B0h] BYREF
  hkpGskManifold::ContactPoint *v63; // [rsp+60h] [rbp-A0h]
  hkVector4f pointOnBOut; // [rsp+70h] [rbp-90h] BYREF
  hkpProcessCdPoint *resultPointArray; // [rsp+80h] [rbp-80h]
  hkpCdBody *v66; // [rsp+88h] [rbp-78h]
  hkpGsk::GetClosesetPointInput inputa; // [rsp+90h] [rbp-70h] BYREF
  hkpGskManifoldWork work; // [rsp+C0h] [rbp-40h] BYREF
  float *result; // [rsp+230h] [rbp+130h] BYREF
  hkpAgentEntry *v70; // [rsp+238h] [rbp+138h]
  hkpProcessCdPoint *v71; // [rsp+240h] [rbp+140h]

  v71 = agentData;
  v70 = entry;
  m_storage = input->m_bodyA.m_storage;
  v9 = separatingNormal;
  inputa.m_shapeA.m_storage = (hkpConvexShape *)input->m_bodyA.m_storage->m_shape;
  m_shape = (hkpConvexShape *)input->m_bodyB.m_storage->m_shape;
  v14 = separatingNormal;
  inputa.m_aTb.m_storage = &input->m_aTb;
  inputa.m_shapeB.m_storage = m_shape;
  inputa.m_transformA.m_storage = (hkTransformf *)m_storage->m_motion;
  v15 = input->m_input.m_storage->m_tolerance.m_storage;
  agentData->m_contact.m_position.m_quad.m128_i8[11] &= ~0x10u;
  inputa.m_collisionTolerance.m_storage = v15;
  if ( hkpGsk::getClosestPoint((hkResult *)&result, &inputa, gskCache, v14, &pointOnBOut)->m_enum == HK_FAILURE )
  {
    if ( gskManifold->m_numContactPoints )
      hkGskManifold_cleanup(gskManifold, input->m_contactMgr.m_storage, output->m_constraintOwner.m_storage);
    return;
  }
  m_quad = v9->m_quad;
  v62 = v9->m_quad;
  if ( inputa.m_shapeB.m_storage->m_type.m_storage == 2 )
  {
    v17 = ((__int64 (__fastcall *)(hkpConvexShape *, unsigned __int16 *, char *, hkVector4f *, const void *, hkpConvexShape *, const void *, __m128 *))inputa.m_shapeB.m_storage->vfptr[6].__first_virtual_table_function__)(
            inputa.m_shapeB.m_storage,
            &gskCache->m_vertices[(unsigned __int8)gskCache->m_dimA],
            &gskCache->m_dimB,
            &pointOnBOut,
            input->m_bodyB.m_storage->m_motion,
            inputa.m_shapeA.m_storage,
            input->m_bodyA.m_storage->m_motion,
            &v62);
  }
  else
  {
    if ( inputa.m_shapeA.m_storage->m_type.m_storage != 2 || BYTE2(inputa.m_shapeA.m_storage[1].vfptr) == 6 )
      goto LABEL_13;
    v18 = input->m_bodyB.m_storage;
    v19 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64);
    v62 = _mm_xor_ps(m_quad, v19);
    v17 = ((__int64 (__fastcall *)(hkpConvexShape *, hkpGskCache *, char *, hkVector4f *, const void *, hkpConvexShape *, const void *, __m128 *))inputa.m_shapeA.m_storage->vfptr[6].__first_virtual_table_function__)(
            inputa.m_shapeA.m_storage,
            gskCache,
            &gskCache->m_dimA,
            &pointOnBOut,
            input->m_bodyA.m_storage->m_motion,
            inputa.m_shapeB.m_storage,
            v18->m_motion,
            &v62);
    v62 = _mm_xor_ps(v62, v19);
  }
  if ( !v17 )
  {
    hkGskManifold_cleanup(gskManifold, input->m_contactMgr.m_storage, output->m_constraintOwner.m_storage);
    return;
  }
  if ( v17 == 1 )
    agentData->m_contact.m_position.m_quad.m128_i8[11] |= 0x10u;
LABEL_13:
  v20 = gskManifold;
  doesPointExistAndResort = hkGskManifold_doesPointExistAndResort(gskManifold, gskCache);
  v22 = output;
  m_numContactPoints = (unsigned __int8)v20->m_numContactPoints;
  v24 = doesPointExistAndResort & 2 | explicitlyAllowNewPoint;
  v25 = doesPointExistAndResort & 1;
  resultPointArray = output->m_firstFreeContactPoint.m_storage;
  if ( m_numContactPoints > v25 )
  {
    v26 = input->m_bodyA.m_storage;
    v27 = input->m_input.m_storage->m_tolerance.m_storage;
    v66 = input->m_bodyB.m_storage;
    work.m_keepContact.m_storage = v27;
    v28 = v26->m_shape;
    result = (float *)v66->m_shape;
    work.m_radiusA.m_storage = *(float *)&v28[1].vfptr;
    v29 = (float)(work.m_radiusA.m_storage + v27) + result[8];
    work.m_radiusB.m_storage = result[8];
    work.m_masterNormal.m_quad = v62;
    work.m_radiusSumSqrd.m_storage = v29 * v29;
    if ( (_BYTE)m_numContactPoints )
    {
      m_numVertsA = (unsigned __int8)v20->m_numVertsA;
      vfptr = v28->vfptr;
      v63 = &v20->m_contactPoints[m_numContactPoints];
      ((void (__fastcall *)(hkpShape *, hkpGskManifold::ContactPoint *, __int64, hkpGskManifoldWork *))vfptr[4].__first_virtual_table_function__)(
        v28,
        v63,
        m_numVertsA,
        &work);
      m_motion = (__m128 *)v26->m_motion;
      v33 = (unsigned __int8)v20->m_numVertsA;
      v34 = *m_motion;
      v35 = m_motion[1];
      v36 = m_motion[2];
      v37 = m_motion[3];
      v38 = (int)v33 - 1;
      v39 = &work.m_vertices[v38];
      do
      {
        v40 = v39->m_quad;
        --v39;
        --v38;
        v39[1].m_quad = _mm_add_ps(
                          _mm_add_ps(
                            _mm_add_ps(
                              _mm_mul_ps(_mm_shuffle_ps(v40, v40, 85), v35),
                              _mm_mul_ps(_mm_shuffle_ps(v40, v40, 0), v34)),
                            _mm_mul_ps(_mm_shuffle_ps(v40, v40, 170), v36)),
                          v37);
      }
      while ( v38 >= 0 );
      v41 = &work.m_vertices[v33];
      (*(void (__fastcall **)(float *, __int64, _QWORD, hkcdVertex *))(*(_QWORD *)result + 72i64))(
        result,
        (__int64)v63 + 2 * v33,
        (unsigned __int8)v20->m_numVertsB,
        v41);
      v42 = (__m128 *)v66->m_motion;
      v43 = *v42;
      v44 = v42[1];
      v45 = v42[2];
      v46 = v42[3];
      v47 = (unsigned __int8)v20->m_numVertsB - 1;
      p_m_quad = &v41[v47].m_quad;
      do
      {
        v49 = *p_m_quad--;
        --v47;
        p_m_quad[1] = _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(
                            _mm_mul_ps(_mm_shuffle_ps(v49, v49, 85), v44),
                            _mm_mul_ps(_mm_shuffle_ps(v49, v49, 0), v43)),
                          _mm_mul_ps(_mm_shuffle_ps(v49, v49, 170), v45)),
                        v46);
      }
      while ( v47 >= 0 );
    }
    v24 |= hkGskManifold_verifyAndGetPoints(v20, &work, v25, v22, input->m_contactMgr.m_storage);
  }
  newCdPointInResultArray = v22->m_firstFreeContactPoint.m_storage;
  newCdPointInResultArray->m_contact.m_position = (hkVector4f)pointOnBOut.m_quad;
  newCdPointInResultArray->m_contact.m_separatingNormal.m_quad = v62;
  if ( v25 )
  {
    newCdPointInResultArray->m_contactPointId = v20->m_contactPoints[0].m_id;
    ++v22->m_firstFreeContactPoint.m_storage;
  }
  else
  {
    v51 = input->m_input.m_storage;
    v52 = v51->m_collisionQualityInfo.m_storage;
    if ( (unsigned __int8)gskCache->m_dimA + (unsigned __int8)gskCache->m_dimB == 4 )
      p_m_create4dContact = (unsigned int *)&v52->m_create4dContact;
    else
      p_m_create4dContact = (unsigned int *)&v52->m_createContact;
    if ( _mm_shuffle_ps(separatingNormal->m_quad, separatingNormal->m_quad, 255).m128_f32[0] >= _mm_shuffle_ps(
                                                                                                  (__m128)*p_m_create4dContact,
                                                                                                  (__m128)*p_m_create4dContact,
                                                                                                  0).m128_f32[0]
      && !v24 )
    {
      goto LABEL_42;
    }
    v54 = resultPointArray;
    v55 = hkGskManifold_addPoint(
            v20,
            input->m_bodyA.m_storage,
            input->m_bodyB.m_storage,
            v51,
            v22,
            gskCache,
            newCdPointInResultArray,
            resultPointArray,
            input->m_contactMgr.m_storage,
            (hkpGskManifoldUtilMgrHandling)(v51->m_enableDeprecatedWelding.m_bool != 0));
    switch ( v55 )
    {
      case 4:
        if ( newCdPointInResultArray->m_contactPointId == 0xFFFF )
        {
          if ( v22->m_potentialContacts.m_storage && (v56 = v70) != 0i64 )
          {
            ((void (__fastcall *)(hkpContactMgr *, float **, __int64))input->m_contactMgr.m_storage->vfptr[2].__vecDelDtor)(
              input->m_contactMgr.m_storage,
              &result,
              1i64);
            if ( !(_DWORD)result )
            {
              v57 = v22->m_potentialContacts.m_storage;
              p_m_contactPoint = &v57->m_firstFreePotentialContact->m_contactPoint;
              ++v57->m_firstFreePotentialContact;
              v59 = v71;
              *p_m_contactPoint = newCdPointInResultArray;
              p_m_contactPoint[2] = v59;
              p_m_contactPoint[1] = (hkpProcessCdPoint *)v56;
              ++v22->m_firstFreeContactPoint.m_storage;
              break;
            }
          }
          else
          {
            v60 = ((__int64 (__fastcall *)(hkpContactMgr *, hkpCdBody *, hkpCdBody *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *, hkpGskCache *, hkpProcessCdPoint *))input->m_contactMgr.m_storage->vfptr[1].__first_virtual_table_function__)(
                    input->m_contactMgr.m_storage,
                    input->m_bodyA.m_storage,
                    input->m_bodyB.m_storage,
                    input->m_input.m_storage,
                    v22,
                    gskCache,
                    newCdPointInResultArray);
            newCdPointInResultArray->m_contactPointId = v60;
            if ( v60 != 0xFFFF )
            {
              v20->m_contactPoints[0].m_id = v60;
              ++v22->m_firstFreeContactPoint.m_storage;
              break;
            }
          }
          hkGskManifold_removePoint(v20, 0);
          newCdPointInResultArray = v54;
          break;
        }
        ++v22->m_firstFreeContactPoint.m_storage;
        break;
      case 5:
        newCdPointInResultArray = v54;
        break;
      case 6:
        --v22->m_firstFreeContactPoint.m_storage;
        newCdPointInResultArray = v54;
        break;
      default:
        newCdPointInResultArray = &v54[v55];
        break;
    }
  }
LABEL_42:
  v61 = v22->m_potentialContacts.m_storage;
  if ( v61 && newCdPointInResultArray < v22->m_firstFreeContactPoint.m_storage )
  {
    *v61->m_firstFreeRepresentativeContact = newCdPointInResultArray;
    ++v22->m_potentialContacts.m_storage->m_firstFreeRepresentativeContact;
  }
}eak;
    }
  }
LABEL_42:
  v61 = v22->m_potentialContacts.m_storage;
  if ( v61 && newCdPointInResultArray < v22->m_firstFreeContactPoint.m_storage )
  {
    *v61->m_firstFreeRepresentativeContact = newCdPointInResultArray;
    ++v2

