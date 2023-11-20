// File Line: 25
// RVA: 0xD42A90
void __fastcall hkAgentNnMachine_initInputAtTime(hkpAgent3Input *in, hkAgentNnMachineBodyTemp *temp, hkpAgent3Input *out)
{
  hkpAgent3Input *v3; // rdi
  hkTransformf *v4; // rbp
  hkpAgent3Input *v5; // r14
  hkAgentNnMachineBodyTemp *v6; // rbx
  signed __int64 v7; // r9
  unsigned int v8; // ecx
  hkpCdBody *v9; // rax
  unsigned int v10; // ecx
  hkpCdBody *v11; // rax
  hkpCdBody *v12; // rax

  v3 = in;
  v4 = &temp->m_transA;
  v5 = out;
  v6 = temp;
  hkSweptTransformUtil::lerp2(
    (hkSweptTransformf *)((char *)in->m_bodyA.m_storage->m_motion + 64),
    in->m_input.m_storage->m_stepInfo.m_startTime.m_storage,
    &temp->m_transA);
  hkSweptTransformUtil::lerp2(
    (hkSweptTransformf *)((char *)v3->m_bodyB.m_storage->m_motion + 64),
    v3->m_input.m_storage->m_stepInfo.m_startTime.m_storage,
    &v6->m_transB);
  v5->m_bodyA.m_storage = &v6->m_bodyA;
  v7 = (signed __int64)&v6->m_bodyB;
  v5->m_bodyB.m_storage = &v6->m_bodyB;
  v5->m_contactMgr.m_storage = v3->m_contactMgr.m_storage;
  v5->m_input.m_storage = v3->m_input.m_storage;
  v8 = v3->m_bodyA.m_storage->m_shapeKey;
  v6->m_bodyA.m_shape = v3->m_bodyA.m_storage->m_shape;
  v6->m_bodyA.m_shapeKey = v8;
  v9 = v3->m_bodyB.m_storage;
  v10 = v9->m_shapeKey;
  *(_QWORD *)v7 = v9->m_shape;
  *(_DWORD *)(v7 + 8) = v10;
  v11 = v3->m_bodyA.m_storage;
  v6->m_bodyA.m_motion = v4;
  v6->m_bodyA.m_parent = v11;
  if ( v6 != (hkAgentNnMachineBodyTemp *)-32i64 )
  {
    v12 = v3->m_bodyB.m_storage;
    v6->m_bodyB.m_motion = &v6->m_transB;
    v6->m_bodyB.m_parent = v12;
  }
  hkTransformf::setMulInverseMul(&v5->m_aTb, v4, &v6->m_transB);
}

// File Line: 51
// RVA: 0xD42B80
void __fastcall hkAgentNnMachine_InlineProcessAgent(hkpAgentNnEntry *entry, hkpProcessCollisionInput *input, int *numTim, hkpProcessCollisionOutput *output, hkpContactMgr *mgr)
{
  hkpAgentNnEntry *v5; // rbx
  hkpProcessCollisionOutput *v6; // r13
  int *v7; // r12
  hkpProcessCollisionInput *v8; // rdi
  _QWORD *v9; // r10
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  int v13; // esi
  hkpCdBody *v14; // r14
  hkpCdBody *v15; // r15
  int v16; // eax
  __int64 v17; // rax
  hkTransformf *v18; // rdx
  hkTransformf *v19; // r8
  __m128 v20; // xmm0
  __m128 v21; // xmm2
  __m128 v22; // xmm1
  __m128 v23; // xmm4
  __m128 v24; // xmm5
  signed __int64 v25; // r8
  hkVector4f *v26; // r9
  __int64 v27; // r8
  hkTransformf *v28; // rcx
  hkTransformf *v29; // rdx
  __m128 v30; // xmm0
  __m128 v31; // xmm2
  __m128 v32; // xmm1
  __m128 v33; // xmm5
  __m128 v34; // xmm4
  __m128 v35; // xmm6
  float v36; // xmm1_4
  bool v37; // zf
  __m128 v38; // xmm6
  __m128 *v39; // rsi
  __m128 v40; // xmm2
  _QWORD *v41; // rax
  _QWORD *v42; // rcx
  _QWORD *v43; // r8
  unsigned __int64 v44; // rax
  signed __int64 v45; // rcx
  int v46; // ecx
  int v47; // ecx
  __m128 v48; // xmm3
  __m128 v49; // xmm2
  __m128 v50; // xmm2
  __m128 v51; // xmm1
  hkTransformf *v52; // [rsp+30h] [rbp-C8h]
  hkTransformf *v53; // [rsp+38h] [rbp-C0h]
  hkpCdBody *v54; // [rsp+40h] [rbp-B8h]
  hkpCdBody *v55; // [rsp+48h] [rbp-B0h]
  __int64 v56; // [rsp+50h] [rbp-A8h]
  hkpProcessCollisionInput *v57; // [rsp+58h] [rbp-A0h]
  __int64 v58; // [rsp+60h] [rbp-98h]
  hkTransformf v59; // [rsp+70h] [rbp-88h]
  __m128 v60; // [rsp+B8h] [rbp-40h]
  hkpShape *v61; // [rsp+C8h] [rbp-30h]
  int v62; // [rsp+D0h] [rbp-28h]
  hkTransformf *v63; // [rsp+D8h] [rbp-20h]
  hkpCdBody *v64; // [rsp+E0h] [rbp-18h]
  hkpShape *v65; // [rsp+E8h] [rbp-10h]
  int v66; // [rsp+F0h] [rbp-8h]
  hkTransformf *v67; // [rsp+F8h] [rbp+0h]
  hkpCdBody *v68; // [rsp+100h] [rbp+8h]
  hkTransformf transformOut; // [rsp+108h] [rbp+10h]
  hkTransformf bTc; // [rsp+148h] [rbp+50h]
  __int64 *v71; // [rsp+188h] [rbp+90h]
  __int64 *v72; // [rsp+190h] [rbp+98h]
  __int64 v73; // [rsp+198h] [rbp+A0h]
  hkpProcessCollisionInput *v74; // [rsp+1A0h] [rbp+A8h]
  __int64 v75; // [rsp+1A8h] [rbp+B0h]
  hkTransformf v76; // [rsp+1B8h] [rbp+C0h]
  hkpCdBody v77; // [rsp+1F8h] [rbp+100h]
  hkpCdBody newCdBodies; // [rsp+278h] [rbp+180h]
  hkMotionState newMotionStates; // [rsp+2F8h] [rbp+200h]
  hkMotionState v80; // [rsp+5B8h] [rbp+4C0h]
  void *cdBodyHasTransformFlag; // [rsp+8B8h] [rbp+7C0h]

  v5 = entry;
  v6 = output;
  v7 = numTim;
  v8 = input;
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)v9[1];
  if ( (unsigned __int64)v10 < v9[3] )
  {
    *v10 = "TtProcessNnEntry";
    v11 = __rdtsc();
    v12 = (signed __int64)(v10 + 2);
    *(_DWORD *)(v12 - 8) = v11;
    v9[1] = v12;
  }
  v13 = (unsigned __int8)v5->m_streamCommand;
  v14 = (hkpCdBody *)&v5->m_collidable[0]->m_shape;
  v15 = (hkpCdBody *)&v5->m_collidable[1]->m_shape;
  v16 = v13 - 2;
  while ( 2 )
  {
    switch ( v16 )
    {
      case 0:
        v17 = (__int64)v5->m_contactMgr;
        v54 = v14;
        v55 = v15;
        v57 = v8;
        v58 = v17;
        v56 = 0i64;
        v18 = (hkTransformf *)v14->m_motion;
        v19 = (hkTransformf *)v15->m_motion;
        v20 = v18[1].m_rotation.m_col1.m_quad;
        v21 = v19[1].m_rotation.m_col1.m_quad;
        v22 = _mm_shuffle_ps(
                (__m128)LODWORD(v8->m_stepInfo.m_deltaTime.m_storage),
                (__m128)LODWORD(v8->m_stepInfo.m_deltaTime.m_storage),
                0);
        v23 = _mm_mul_ps(_mm_shuffle_ps(v18[1].m_rotation.m_col1.m_quad, v20, 255), v22);
        v24 = _mm_mul_ps(_mm_shuffle_ps(v21, v21, 255), v22);
        v60 = _mm_add_ps(
                _mm_mul_ps(_mm_sub_ps(v18[1].m_rotation.m_col0.m_quad, v20), v23),
                _mm_mul_ps(_mm_sub_ps(v21, v19[1].m_rotation.m_col0.m_quad), v24));
        v60 = _mm_shuffle_ps(
                v60,
                _mm_unpackhi_ps(
                  v60,
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_mul_ps(
                        _mm_shuffle_ps(v18[2].m_rotation.m_col1.m_quad, v18[2].m_rotation.m_col1.m_quad, 255),
                        v23),
                      _mm_shuffle_ps(
                        (__m128)v18[2].m_rotation.m_col2.m_quad.m128_u32[0],
                        (__m128)v18[2].m_rotation.m_col2.m_quad.m128_u32[0],
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
        hkTransformf::setMulInverseMul(&v59, v18, v19);
        v25 = (signed __int64)&v5[1].m_contactMgr;
        v26 = 0i64;
        goto LABEL_13;
      case 2:
        v27 = (__int64)v5->m_contactMgr;
        v54 = v14;
        v55 = v15;
        v57 = v8;
        v58 = v27;
        v56 = 0i64;
        v28 = (hkTransformf *)v14->m_motion;
        v29 = (hkTransformf *)v15->m_motion;
        v53 = v28;
        v52 = v29;
        v30 = v28[1].m_rotation.m_col1.m_quad;
        v31 = v29[1].m_rotation.m_col1.m_quad;
        v32 = _mm_shuffle_ps(
                (__m128)LODWORD(v8->m_stepInfo.m_deltaTime.m_storage),
                (__m128)LODWORD(v8->m_stepInfo.m_deltaTime.m_storage),
                0);
        v33 = _mm_mul_ps(_mm_shuffle_ps(v28[1].m_rotation.m_col1.m_quad, v30, 255), v32);
        v34 = _mm_mul_ps(_mm_shuffle_ps(v31, v31, 255), v32);
        v35 = _mm_add_ps(
                _mm_mul_ps(_mm_sub_ps(v28[1].m_rotation.m_col0.m_quad, v30), v33),
                _mm_mul_ps(_mm_sub_ps(v31, v29[1].m_rotation.m_col0.m_quad), v34));
        v60 = v35;
        v36 = v8->m_stepInfo.m_startTime.m_storage;
        v37 = v36 == *(float *)&v5[1].0;
        v38 = _mm_shuffle_ps(
                v35,
                _mm_unpackhi_ps(
                  v35,
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
        v60 = v38;
        if ( v37 )
          goto LABEL_18;
        if ( v8->m_collisionQualityInfo.m_storage->m_useContinuousPhysics.m_storage )
        {
          v73 = 0i64;
          hkSweptTransformUtil::lerp2((hkSweptTransformf *)((char *)v14->m_motion + 64), v36, &transformOut);
          hkSweptTransformUtil::lerp2(
            (hkSweptTransformf *)((char *)v55->m_motion + 64),
            v57->m_stepInfo.m_startTime.m_storage,
            &bTc);
          v71 = (__int64 *)&v61;
          v72 = (__int64 *)&v65;
          v75 = v58;
          v74 = v57;
          v46 = v54->m_shapeKey;
          v61 = v54->m_shape;
          v62 = v46;
          v47 = v55->m_shapeKey;
          v65 = v55->m_shape;
          v63 = &transformOut;
          v64 = v54;
          v68 = v55;
          v66 = v47;
          v67 = &bTc;
          hkTransformf::setMulInverseMul(&v76, &transformOut, &bTc);
          v8->m_dispatcher.m_storage->m_agent3Func[(unsigned __int8)v5->m_agentType].m_sepNormalFunc(
            (hkpAgent3Input *)&v71,
            (hkpAgentEntry *)&v5->m_streamCommand,
            v5[1].m_collidable,
            (hkVector4f *)&v5[1].m_contactMgr);
          v27 = v58;
          v28 = v53;
          v38 = v60;
          v29 = v52;
LABEL_18:
          v48 = *(__m128 *)&v5[1].m_contactMgr;
          v39 = (__m128 *)&v5[1].m_contactMgr;
          v5[1].0 = (hkpAgentEntry)LODWORD(v8->m_stepInfo.m_endTime.m_storage);
          v49 = _mm_mul_ps(v38, v48);
          v50 = _mm_shuffle_ps(v49, _mm_unpackhi_ps(v49, v38), 196);
          v51 = _mm_add_ps(_mm_shuffle_ps(v50, v50, 78), v50);
          v40 = _mm_sub_ps(_mm_shuffle_ps(v48, v48, 255), _mm_add_ps(_mm_shuffle_ps(v51, v51, 177), v51));
          if ( v40.m128_f32[0] >= COERCE_FLOAT(
                                    _mm_shuffle_ps(
                                      (__m128)LODWORD(v8->m_tolerance.m_storage),
                                      (__m128)LODWORD(v8->m_tolerance.m_storage),
                                      0)) )
          {
            v37 = v5->m_numContactPoints == 0;
            *v39 = _mm_shuffle_ps(v48, _mm_unpackhi_ps(v48, v40), 196);
            if ( !v37 )
              v8->m_dispatcher.m_storage->m_agent3Func[(unsigned __int8)v5->m_agentType].m_cleanupFunc(
                (hkpAgentEntry *)&v5->m_streamCommand,
                v5[1].m_collidable,
                (hkpContactMgr *)v27,
                v6->m_constraintOwner.m_storage);
            ++*v7;
            goto LABEL_14;
          }
        }
        else
        {
          v39 = (__m128 *)&v5[1].m_contactMgr;
          v5[1].0 = (hkpAgentEntry)LODWORD(v8->m_stepInfo.m_endTime.m_storage);
          v40.m128_i32[0] = xmmword_141A712F0;
          *(__m128 *)&v5[1].m_contactMgr = _mm_shuffle_ps(
                                             aabbOut.m_quad,
                                             _mm_unpackhi_ps(aabbOut.m_quad, (__m128)xmmword_141A712F0),
                                             196);
        }
        v59.m_translation.m_quad.m128_i32[2] = v40.m128_i32[0];
        hkTransformf::setMulInverseMul(&v59, v28, v29);
        v26 = (hkVector4f *)v39;
        v25 = (signed __int64)v5[1].m_collidable;
LABEL_13:
        v8->m_dispatcher.m_storage->m_agent3Func[(unsigned __int8)v5->m_agentType].m_processFunc(
          (hkpAgent3ProcessInput *)&v54,
          (hkpAgentEntry *)&v5->m_streamCommand,
          (void *)v25,
          v26,
          v6);
LABEL_14:
        v41 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v42 = (_QWORD *)v41[1];
        v43 = v41;
        if ( (unsigned __int64)v42 < v41[3] )
        {
          *v42 = "Et";
          v44 = __rdtsc();
          v45 = (signed __int64)(v42 + 2);
          *(_DWORD *)(v45 - 8) = v44;
          v43[1] = v45;
        }
        return;
      case 4:
        ((void (__fastcall *)(hkpContactMgr *, hkpCdBody *, hkpCdBody *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *))v5[1].m_contactMgr->vfptr[3].__vecDelDtor)(
          v5[1].m_contactMgr,
          v14,
          v15,
          v8,
          v6);
        goto LABEL_14;
      case 8:
      case 10:
      case 12:
        v14 = hkAgentMachine_processTransformedShapes(
                v14,
                &newCdBodies,
                &newMotionStates,
                4,
                (hkPadSpu<unsigned char> *)&cdBodyHasTransformFlag);
        v13 &= 0xF7u;
        v15 = hkAgentMachine_processTransformedShapes(
                v15,
                &v77,
                &v80,
                4,
                (hkPadSpu<unsigned char> *)&cdBodyHasTransformFlag);
        v16 = v13 - 2;
        if ( (unsigned int)(v13 - 2) <= 0xC )
          continue;
        goto LABEL_14;
      default:
        goto LABEL_14;
    }
  }
}           v15,
                &v77,
                &v80,
                4,
                (hkPadSpu<unsigned char> *)&cdBodyHasTransformFlag);
        v16 = v13 - 2;
        if ( (unsigned int)(v13 - 2) <= 0xC )
          continue;
        goto LABEL_14;
    

