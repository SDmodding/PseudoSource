// File Line: 25
// RVA: 0xD42A90
void __fastcall hkAgentNnMachine_initInputAtTime(
        hkpAgent3Input *in,
        hkAgentNnMachineBodyTemp *temp,
        hkpAgent3Input *out)
{
  hkTransformf *p_m_transA; // rbp
  unsigned int m_shapeKey; // ecx
  hkpCdBody *m_storage; // rax
  unsigned int v9; // ecx
  hkpCdBody *v10; // rax
  hkpCdBody *v11; // rax

  p_m_transA = &temp->m_transA;
  hkSweptTransformUtil::lerp2(
    (hkSweptTransformf *)((char *)in->m_bodyA.m_storage->m_motion + 64),
    in->m_input.m_storage->m_stepInfo.m_startTime.m_storage,
    &temp->m_transA);
  hkSweptTransformUtil::lerp2(
    (hkSweptTransformf *)((char *)in->m_bodyB.m_storage->m_motion + 64),
    in->m_input.m_storage->m_stepInfo.m_startTime.m_storage,
    &temp->m_transB);
  out->m_bodyA.m_storage = &temp->m_bodyA;
  out->m_bodyB.m_storage = &temp->m_bodyB;
  out->m_contactMgr.m_storage = in->m_contactMgr.m_storage;
  out->m_input.m_storage = in->m_input.m_storage;
  m_shapeKey = in->m_bodyA.m_storage->m_shapeKey;
  temp->m_bodyA.m_shape = in->m_bodyA.m_storage->m_shape;
  temp->m_bodyA.m_shapeKey = m_shapeKey;
  m_storage = in->m_bodyB.m_storage;
  v9 = m_storage->m_shapeKey;
  temp->m_bodyB.m_shape = m_storage->m_shape;
  temp->m_bodyB.m_shapeKey = v9;
  v10 = in->m_bodyA.m_storage;
  temp->m_bodyA.m_motion = p_m_transA;
  temp->m_bodyA.m_parent = v10;
  if ( temp != (hkAgentNnMachineBodyTemp *)-32i64 )
  {
    v11 = in->m_bodyB.m_storage;
    temp->m_bodyB.m_motion = &temp->m_transB;
    temp->m_bodyB.m_parent = v11;
  }
  hkTransformf::setMulInverseMul(&out->m_aTb, p_m_transA, &temp->m_transB);
}

// File Line: 51
// RVA: 0xD42B80
void __fastcall hkAgentNnMachine_InlineProcessAgent(
        hkpAgentNnEntry *entry,
        hkpProcessCollisionInput *input,
        int *numTim,
        hkpProcessCollisionOutput *output,
        hkpContactMgr *mgr)
{
  _QWORD *Value; // r10
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  int m_streamCommand; // esi
  hkpLinkedCollidable *v14; // r14
  hkpLinkedCollidable *v15; // r15
  int v16; // eax
  hkpContactMgr *m_contactMgr; // rax
  hkTransformf *m_motion; // rdx
  hkTransformf *v19; // r8
  __m128 m_quad; // xmm0
  __m128 v21; // xmm2
  __m128 v22; // xmm1
  __m128 v23; // xmm4
  __m128 v24; // xmm5
  char *p_m_contactMgr; // r8
  hkVector4f *v26; // r9
  hkpContactMgr *v27; // r8
  hkTransformf *v28; // rcx
  hkTransformf *v29; // rdx
  __m128 v30; // xmm0
  __m128 v31; // xmm2
  __m128 v32; // xmm1
  __m128 v33; // xmm5
  __m128 v34; // xmm4
  float m_storage; // xmm1_4
  bool v36; // zf
  __m128 v37; // xmm6
  __m128 *v38; // rsi
  __m128 v39; // xmm2
  _QWORD *v40; // rax
  _QWORD *v41; // rcx
  _QWORD *v42; // r8
  unsigned __int64 v43; // rax
  _QWORD *v44; // rcx
  int m_shapeKey; // ecx
  int v46; // ecx
  __m128 v47; // xmm3
  __m128 v48; // xmm2
  __m128 v49; // xmm2
  __m128 v50; // xmm1
  hkTransformf *v51; // [rsp+30h] [rbp-C8h]
  hkTransformf *v52; // [rsp+38h] [rbp-C0h]
  hkpLinkedCollidable *v53; // [rsp+40h] [rbp-B8h] BYREF
  hkpLinkedCollidable *v54; // [rsp+48h] [rbp-B0h]
  __int64 v55; // [rsp+50h] [rbp-A8h]
  hkpProcessCollisionInput *v56; // [rsp+58h] [rbp-A0h]
  hkpContactMgr *v57; // [rsp+60h] [rbp-98h]
  hkTransformf v58; // [rsp+70h] [rbp-88h] BYREF
  __m128 v59; // [rsp+B8h] [rbp-40h]
  hkpShape *m_shape; // [rsp+C8h] [rbp-30h] BYREF
  int v61; // [rsp+D0h] [rbp-28h]
  hkTransformf *p_transformOut; // [rsp+D8h] [rbp-20h]
  hkpLinkedCollidable *v63; // [rsp+E0h] [rbp-18h]
  hkpShape *v64; // [rsp+E8h] [rbp-10h] BYREF
  int v65; // [rsp+F0h] [rbp-8h]
  hkTransformf *p_bTc; // [rsp+F8h] [rbp+0h]
  hkpLinkedCollidable *v67; // [rsp+100h] [rbp+8h]
  hkTransformf transformOut; // [rsp+108h] [rbp+10h] BYREF
  hkTransformf bTc; // [rsp+148h] [rbp+50h] BYREF
  __int64 v70[6]; // [rsp+188h] [rbp+90h] BYREF
  hkTransformf v71; // [rsp+1B8h] [rbp+C0h] BYREF
  hkpCdBody v72; // [rsp+1F8h] [rbp+100h] BYREF
  hkpCdBody newCdBodies; // [rsp+278h] [rbp+180h] BYREF
  hkMotionState newMotionStates; // [rsp+2F8h] [rbp+200h] BYREF
  hkMotionState v75; // [rsp+5B8h] [rbp+4C0h] BYREF
  void *cdBodyHasTransformFlag; // [rsp+8B8h] [rbp+7C0h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v10 < Value[3] )
  {
    *v10 = "TtProcessNnEntry";
    v11 = __rdtsc();
    v12 = v10 + 2;
    *((_DWORD *)v12 - 2) = v11;
    Value[1] = v12;
  }
  m_streamCommand = (unsigned __int8)entry->m_streamCommand;
  v14 = entry->m_collidable[0];
  v15 = entry->m_collidable[1];
  v16 = m_streamCommand - 2;
  while ( 2 )
  {
    switch ( v16 )
    {
      case 0:
        m_contactMgr = entry->m_contactMgr;
        v53 = v14;
        v54 = v15;
        v56 = input;
        v57 = m_contactMgr;
        v55 = 0i64;
        m_motion = (hkTransformf *)v14->m_motion;
        v19 = (hkTransformf *)v15->m_motion;
        m_quad = m_motion[1].m_rotation.m_col1.m_quad;
        v21 = v19[1].m_rotation.m_col1.m_quad;
        v22 = _mm_shuffle_ps(
                (__m128)LODWORD(input->m_stepInfo.m_deltaTime.m_storage),
                (__m128)LODWORD(input->m_stepInfo.m_deltaTime.m_storage),
                0);
        v23 = _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 255), v22);
        v24 = _mm_mul_ps(_mm_shuffle_ps(v21, v21, 255), v22);
        v59 = _mm_add_ps(
                _mm_mul_ps(_mm_sub_ps(m_motion[1].m_rotation.m_col0.m_quad, m_quad), v23),
                _mm_mul_ps(_mm_sub_ps(v21, v19[1].m_rotation.m_col0.m_quad), v24));
        v59 = _mm_shuffle_ps(
                v59,
                _mm_unpackhi_ps(
                  v59,
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_mul_ps(
                        _mm_shuffle_ps(m_motion[2].m_rotation.m_col1.m_quad, m_motion[2].m_rotation.m_col1.m_quad, 255),
                        v23),
                      _mm_shuffle_ps(
                        (__m128)m_motion[2].m_rotation.m_col2.m_quad.m128_u32[0],
                        (__m128)m_motion[2].m_rotation.m_col2.m_quad.m128_u32[0],
                        0)),
                    _mm_mul_ps(
                      _mm_mul_ps(
                        _mm_shuffle_ps(v19[2].m_rotation.m_col1.m_quad, v19[2].m_rotation.m_col1.m_quad, 255),
                        v24),
                      _mm_shuffle_ps(
                        (__m128)v19[2].m_rotation.m_col2.m_quad.m128_u32[0],
                        (__m128)v19[2].m_rotation.m_col2.m_quad.m128_u32[0],
                        0)))),
                196);
        hkTransformf::setMulInverseMul(&v58, m_motion, v19);
        p_m_contactMgr = (char *)&entry[1].m_contactMgr;
        v26 = 0i64;
        goto LABEL_13;
      case 2:
        v27 = entry->m_contactMgr;
        v53 = v14;
        v54 = v15;
        v56 = input;
        v57 = v27;
        v55 = 0i64;
        v28 = (hkTransformf *)v14->m_motion;
        v29 = (hkTransformf *)v15->m_motion;
        v52 = v28;
        v51 = v29;
        v30 = v28[1].m_rotation.m_col1.m_quad;
        v31 = v29[1].m_rotation.m_col1.m_quad;
        v32 = _mm_shuffle_ps(
                (__m128)LODWORD(input->m_stepInfo.m_deltaTime.m_storage),
                (__m128)LODWORD(input->m_stepInfo.m_deltaTime.m_storage),
                0);
        v33 = _mm_mul_ps(_mm_shuffle_ps(v30, v30, 255), v32);
        v34 = _mm_mul_ps(_mm_shuffle_ps(v31, v31, 255), v32);
        v59 = _mm_add_ps(
                _mm_mul_ps(_mm_sub_ps(v28[1].m_rotation.m_col0.m_quad, v30), v33),
                _mm_mul_ps(_mm_sub_ps(v31, v29[1].m_rotation.m_col0.m_quad), v34));
        m_storage = input->m_stepInfo.m_startTime.m_storage;
        v36 = m_storage == *(float *)&entry[1].hkpAgentEntry;
        v37 = _mm_shuffle_ps(
                v59,
                _mm_unpackhi_ps(
                  v59,
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_mul_ps(
                        _mm_shuffle_ps(v29[2].m_rotation.m_col1.m_quad, v29[2].m_rotation.m_col1.m_quad, 255),
                        v34),
                      _mm_shuffle_ps(
                        (__m128)v29[2].m_rotation.m_col2.m_quad.m128_u32[0],
                        (__m128)v29[2].m_rotation.m_col2.m_quad.m128_u32[0],
                        0)),
                    _mm_mul_ps(
                      _mm_mul_ps(
                        _mm_shuffle_ps(v28[2].m_rotation.m_col1.m_quad, v28[2].m_rotation.m_col1.m_quad, 255),
                        v33),
                      _mm_shuffle_ps(
                        (__m128)v28[2].m_rotation.m_col2.m_quad.m128_u32[0],
                        (__m128)v28[2].m_rotation.m_col2.m_quad.m128_u32[0],
                        0)))),
                196);
        v59 = v37;
        if ( v36 )
          goto LABEL_18;
        if ( input->m_collisionQualityInfo.m_storage->m_useContinuousPhysics.m_storage )
        {
          v70[2] = 0i64;
          hkSweptTransformUtil::lerp2((hkSweptTransformf *)((char *)v14->m_motion + 64), m_storage, &transformOut);
          hkSweptTransformUtil::lerp2(
            (hkSweptTransformf *)((char *)v54->m_motion + 64),
            v56->m_stepInfo.m_startTime.m_storage,
            &bTc);
          v70[0] = (__int64)&m_shape;
          v70[1] = (__int64)&v64;
          v70[4] = (__int64)v57;
          v70[3] = (__int64)v56;
          m_shapeKey = v53->m_shapeKey;
          m_shape = v53->m_shape;
          v61 = m_shapeKey;
          v46 = v54->m_shapeKey;
          v64 = v54->m_shape;
          p_transformOut = &transformOut;
          v63 = v53;
          v67 = v54;
          v65 = v46;
          p_bTc = &bTc;
          hkTransformf::setMulInverseMul(&v71, &transformOut, &bTc);
          input->m_dispatcher.m_storage->m_agent3Func[(unsigned __int8)entry->m_agentType].m_sepNormalFunc(
            (hkpAgent3Input *)v70,
            entry,
            entry[1].m_collidable,
            (hkVector4f *)&entry[1].m_contactMgr);
          v27 = v57;
          v28 = v52;
          v37 = v59;
          v29 = v51;
LABEL_18:
          v47 = *(__m128 *)&entry[1].m_contactMgr;
          v38 = (__m128 *)&entry[1].m_contactMgr;
          entry[1].hkpAgentEntry = (hkpAgentEntry)LODWORD(input->m_stepInfo.m_endTime.m_storage);
          v48 = _mm_mul_ps(v37, v47);
          v49 = _mm_shuffle_ps(v48, _mm_unpackhi_ps(v48, v37), 196);
          v50 = _mm_add_ps(_mm_shuffle_ps(v49, v49, 78), v49);
          v39 = _mm_sub_ps(_mm_shuffle_ps(v47, v47, 255), _mm_add_ps(_mm_shuffle_ps(v50, v50, 177), v50));
          if ( v39.m128_f32[0] >= _mm_shuffle_ps(
                                    (__m128)LODWORD(input->m_tolerance.m_storage),
                                    (__m128)LODWORD(input->m_tolerance.m_storage),
                                    0).m128_f32[0] )
          {
            v36 = entry->m_numContactPoints == 0;
            *v38 = _mm_shuffle_ps(v47, _mm_unpackhi_ps(v47, v39), 196);
            if ( !v36 )
              input->m_dispatcher.m_storage->m_agent3Func[(unsigned __int8)entry->m_agentType].m_cleanupFunc(
                entry,
                entry[1].m_collidable,
                v27,
                output->m_constraintOwner.m_storage);
            ++*numTim;
            goto LABEL_14;
          }
        }
        else
        {
          v38 = (__m128 *)&entry[1].m_contactMgr;
          entry[1].hkpAgentEntry = (hkpAgentEntry)LODWORD(input->m_stepInfo.m_endTime.m_storage);
          v39.m128_i32[0] = -8388626;
          *(__m128 *)&entry[1].m_contactMgr = _mm_shuffle_ps(
                                                aabbOut.m_quad,
                                                _mm_unpackhi_ps(aabbOut.m_quad, (__m128)xmmword_141A712F0),
                                                196);
        }
        v58.m_translation.m_quad.m128_i32[2] = v39.m128_i32[0];
        hkTransformf::setMulInverseMul(&v58, v28, v29);
        v26 = (hkVector4f *)v38;
        p_m_contactMgr = (char *)entry[1].m_collidable;
LABEL_13:
        input->m_dispatcher.m_storage->m_agent3Func[(unsigned __int8)entry->m_agentType].m_processFunc(
          (hkpAgent3ProcessInput *)&v53,
          entry,
          p_m_contactMgr,
          v26,
          output);
LABEL_14:
        v40 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v41 = (_QWORD *)v40[1];
        v42 = v40;
        if ( (unsigned __int64)v41 < v40[3] )
        {
          *v41 = "Et";
          v43 = __rdtsc();
          v44 = v41 + 2;
          *((_DWORD *)v44 - 2) = v43;
          v42[1] = v44;
        }
        return;
      case 4:
        ((void (__fastcall *)(hkpContactMgr *, hkpLinkedCollidable *, hkpLinkedCollidable *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *))entry[1].m_contactMgr->vfptr[3].__vecDelDtor)(
          entry[1].m_contactMgr,
          v14,
          v15,
          input,
          output);
        goto LABEL_14;
      case 8:
      case 10:
      case 12:
        v14 = (hkpLinkedCollidable *)hkAgentMachine_processTransformedShapes(
                                       v14,
                                       &newCdBodies,
                                       &newMotionStates,
                                       4,
                                       (hkPadSpu<unsigned char> *)&cdBodyHasTransformFlag);
        m_streamCommand &= 0xF7u;
        v15 = (hkpLinkedCollidable *)hkAgentMachine_processTransformedShapes(
                                       v15,
                                       &v72,
                                       &v75,
                                       4,
                                       (hkPadSpu<unsigned char> *)&cdBodyHasTransformFlag);
        v16 = m_streamCommand - 2;
        if ( (unsigned int)(m_streamCommand - 2) <= 0xC )
          continue;
        goto LABEL_14;
      default:
        goto LABEL_14;
    }
  }
}                      4,
             

