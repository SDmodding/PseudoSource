// File Line: 17
// RVA: 0x12FD000
void __fastcall hkSweptTransformUtil::lerp2(
        hkSweptTransformf *sweptTrans,
        hkSimdFloat32 *t,
        hkTransformf *transformOut)
{
  hkQuaternionf v5; // xmm7
  __m128 v6; // xmm8
  __m128 v7; // xmm6
  __m128 v8; // xmm5
  __m128 v9; // xmm0
  __m128 v10; // xmm1
  __m128 v11; // xmm3
  __m128 v12; // xmm2
  __m128 v13; // xmm5
  __m128 v14; // xmm5
  __m128 v15; // xmm0
  __m128 v16; // xmm2
  __m128 v17; // xmm1
  __m128 v18; // xmm2
  hkVector4f v19; // xmm3
  hkVector4f v20; // xmm1
  hkQuaternionf qi; // [rsp+20h] [rbp-68h] BYREF

  v5.m_vec.m_quad = (__m128)sweptTrans->m_rotation1;
  v6 = _mm_mul_ps(
         _mm_sub_ps(
           t->m_real,
           _mm_shuffle_ps(sweptTrans->m_centerOfMass0.m_quad, sweptTrans->m_centerOfMass0.m_quad, 255)),
         _mm_shuffle_ps(sweptTrans->m_centerOfMass1.m_quad, sweptTrans->m_centerOfMass1.m_quad, 255));
  v7 = _mm_mul_ps((__m128)xmmword_141A710D0, v6);
  v8 = _mm_add_ps(sweptTrans->m_rotation0.m_vec.m_quad, v5.m_vec.m_quad);
  v9 = _mm_mul_ps(v8, v8);
  v10 = _mm_add_ps(_mm_shuffle_ps(v9, v9, 78), v9);
  v11 = _mm_add_ps(_mm_shuffle_ps(v10, v10, 177), v10);
  v12 = _mm_sub_ps(
          _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_75), (__m128)LODWORD(FLOAT_0_75), 0),
          _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(FLOAT_0_125), (__m128)LODWORD(FLOAT_0_125), 0), v11));
  v13 = _mm_mul_ps(
          v8,
          _mm_mul_ps(
            _mm_sub_ps(
              _mm_add_ps(query.m_quad, (__m128)xmmword_141A711B0),
              _mm_mul_ps(_mm_mul_ps(_mm_mul_ps(v11, (__m128)xmmword_141A711B0), v12), v12)),
            v12));
  if ( v6.m128_f32[0] >= 0.5 )
    v14 = _mm_add_ps(v13, _mm_mul_ps(_mm_sub_ps(v7, query.m_quad), _mm_sub_ps(v5.m_vec.m_quad, v13)));
  else
    v14 = _mm_add_ps(
            _mm_mul_ps(_mm_sub_ps(v13, sweptTrans->m_rotation0.m_vec.m_quad), v7),
            sweptTrans->m_rotation0.m_vec.m_quad);
  v15 = _mm_mul_ps(v14, v14);
  v16 = _mm_add_ps(_mm_shuffle_ps(v15, v15, 78), v15);
  v17 = _mm_add_ps(_mm_shuffle_ps(v16, v16, 177), v16);
  v18 = _mm_rsqrt_ps(v17);
  qi.m_vec.m_quad = _mm_mul_ps(
                      v14,
                      _mm_mul_ps(
                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v18, v17), v18)),
                        _mm_mul_ps(*(__m128 *)_xmm, v18)));
  hkRotationf::set(&transformOut->m_rotation, &qi);
  v19.m_quad = _mm_add_ps(
                 _mm_mul_ps(_mm_sub_ps(sweptTrans->m_centerOfMass1.m_quad, sweptTrans->m_centerOfMass0.m_quad), v6),
                 sweptTrans->m_centerOfMass0.m_quad);
  transformOut->m_translation = (hkVector4f)v19.m_quad;
  v20.m_quad = (__m128)sweptTrans->m_centerOfMassLocal;
  transformOut->m_translation.m_quad = _mm_sub_ps(
                                         v19.m_quad,
                                         _mm_add_ps(
                                           _mm_add_ps(
                                             _mm_mul_ps(
                                               _mm_shuffle_ps(v20.m_quad, v20.m_quad, 85),
                                               transformOut->m_rotation.m_col1.m_quad),
                                             _mm_mul_ps(
                                               _mm_shuffle_ps(v20.m_quad, v20.m_quad, 0),
                                               transformOut->m_rotation.m_col0.m_quad)),
                                           _mm_mul_ps(
                                             _mm_shuffle_ps(v20.m_quad, v20.m_quad, 170),
                                             transformOut->m_rotation.m_col2.m_quad)));
}

// File Line: 22
// RVA: 0x12FCFD0
void __fastcall hkSweptTransformUtil::lerp2(hkSweptTransformf *sweptTrans, float t, hkTransformf *transformOut)
{
  hkSimdFloat32 ta; // [rsp+20h] [rbp-18h] BYREF

  ta.m_real = _mm_shuffle_ps((__m128)LODWORD(t), (__m128)LODWORD(t), 0);
  hkSweptTransformUtil::lerp2(sweptTrans, &ta, transformOut);
}

// File Line: 37
// RVA: 0x12FD210
void __fastcall hkSweptTransformUtil::lerp2Ha(
        hkSweptTransformf *sweptTrans,
        hkSimdFloat32 *t,
        hkSimdFloat32 *tAddOn,
        hkTransformf *transformOut)
{
  hkQuaternionf v6; // xmm7
  __m128 v7; // xmm8
  __m128 v8; // xmm5
  __m128 v9; // xmm6
  __m128 v10; // xmm0
  __m128 v11; // xmm1
  __m128 v12; // xmm3
  __m128 v13; // xmm2
  __m128 v14; // xmm6
  __m128 v15; // xmm5
  __m128 v16; // xmm0
  __m128 v17; // xmm2
  __m128 v18; // xmm1
  __m128 v19; // xmm2
  hkVector4f v20; // xmm3
  hkVector4f v21; // xmm1
  hkQuaternionf qi; // [rsp+20h] [rbp-68h] BYREF

  v6.m_vec.m_quad = (__m128)sweptTrans->m_rotation1;
  v7 = _mm_mul_ps(
         _mm_add_ps(
           _mm_sub_ps(
             t->m_real,
             _mm_shuffle_ps(sweptTrans->m_centerOfMass0.m_quad, sweptTrans->m_centerOfMass0.m_quad, 255)),
           tAddOn->m_real),
         _mm_shuffle_ps(sweptTrans->m_centerOfMass1.m_quad, sweptTrans->m_centerOfMass1.m_quad, 255));
  v8 = _mm_mul_ps((__m128)xmmword_141A710D0, v7);
  v9 = _mm_add_ps(sweptTrans->m_rotation0.m_vec.m_quad, v6.m_vec.m_quad);
  v10 = _mm_mul_ps(v9, v9);
  v11 = _mm_add_ps(_mm_shuffle_ps(v10, v10, 78), v10);
  v12 = _mm_add_ps(_mm_shuffle_ps(v11, v11, 177), v11);
  v13 = _mm_sub_ps(
          _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_75), (__m128)LODWORD(FLOAT_0_75), 0),
          _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(FLOAT_0_125), (__m128)LODWORD(FLOAT_0_125), 0), v12));
  v14 = _mm_mul_ps(
          v9,
          _mm_mul_ps(
            _mm_sub_ps(
              _mm_add_ps(query.m_quad, (__m128)xmmword_141A711B0),
              _mm_mul_ps(_mm_mul_ps(_mm_mul_ps(v12, (__m128)xmmword_141A711B0), v13), v13)),
            v13));
  if ( v7.m128_f32[0] >= 0.5 )
    v15 = _mm_add_ps(v14, _mm_mul_ps(_mm_sub_ps(v8, query.m_quad), _mm_sub_ps(v6.m_vec.m_quad, v14)));
  else
    v15 = _mm_add_ps(
            _mm_mul_ps(v8, _mm_sub_ps(v14, sweptTrans->m_rotation0.m_vec.m_quad)),
            sweptTrans->m_rotation0.m_vec.m_quad);
  v16 = _mm_mul_ps(v15, v15);
  v17 = _mm_add_ps(_mm_shuffle_ps(v16, v16, 78), v16);
  v18 = _mm_add_ps(_mm_shuffle_ps(v17, v17, 177), v17);
  v19 = _mm_rsqrt_ps(v18);
  qi.m_vec.m_quad = _mm_mul_ps(
                      v15,
                      _mm_mul_ps(
                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v18), v19)),
                        _mm_mul_ps(*(__m128 *)_xmm, v19)));
  hkRotationf::set(&transformOut->m_rotation, &qi);
  v20.m_quad = _mm_add_ps(
                 _mm_mul_ps(_mm_sub_ps(sweptTrans->m_centerOfMass1.m_quad, sweptTrans->m_centerOfMass0.m_quad), v7),
                 sweptTrans->m_centerOfMass0.m_quad);
  transformOut->m_translation = (hkVector4f)v20.m_quad;
  v21.m_quad = (__m128)sweptTrans->m_centerOfMassLocal;
  transformOut->m_translation.m_quad = _mm_sub_ps(
                                         v20.m_quad,
                                         _mm_add_ps(
                                           _mm_add_ps(
                                             _mm_mul_ps(
                                               _mm_shuffle_ps(v21.m_quad, v21.m_quad, 85),
                                               transformOut->m_rotation.m_col1.m_quad),
                                             _mm_mul_ps(
                                               _mm_shuffle_ps(v21.m_quad, v21.m_quad, 0),
                                               transformOut->m_rotation.m_col0.m_quad)),
                                           _mm_mul_ps(
                                             _mm_shuffle_ps(v21.m_quad, v21.m_quad, 170),
                                             transformOut->m_rotation.m_col2.m_quad)));
}

// File Line: 43
// RVA: 0x12FD1C0
void __fastcall hkSweptTransformUtil::lerp2Ha(
        hkSweptTransformf *sweptTrans,
        float t,
        float tAddOn,
        hkTransformf *transformOut)
{
  hkSimdFloat32 v4; // [rsp+20h] [rbp-28h] BYREF
  hkSimdFloat32 v5; // [rsp+30h] [rbp-18h] BYREF

  v4.m_real = _mm_shuffle_ps((__m128)LODWORD(tAddOn), (__m128)LODWORD(tAddOn), 0);
  v5.m_real = _mm_shuffle_ps((__m128)LODWORD(t), (__m128)LODWORD(t), 0);
  hkSweptTransformUtil::lerp2Ha(sweptTrans, &v5, &v4, transformOut);
}

// File Line: 49
// RVA: 0x12FD590
void __fastcall hkSweptTransformUtil::lerp2Rel(
        hkSweptTransformf *sweptTrans,
        hkSimdFloat32 *r,
        hkTransformf *transformOut)
{
  hkQuaternionf v3; // xmm6
  __m128 v7; // xmm5
  __m128 v8; // xmm0
  __m128 v9; // xmm1
  __m128 v10; // xmm3
  __m128 v11; // xmm2
  __m128 v12; // xmm0
  __m128 v13; // xmm3
  __m128 v14; // xmm5
  __m128 v15; // xmm3
  __m128 v16; // xmm0
  __m128 v17; // xmm2
  __m128 v18; // xmm1
  __m128 v19; // xmm2
  hkVector4f v20; // xmm3
  hkVector4f v21; // xmm1
  hkQuaternionf qi; // [rsp+20h] [rbp-48h] BYREF

  v3.m_vec.m_quad = (__m128)sweptTrans->m_rotation1;
  v7 = _mm_add_ps(sweptTrans->m_rotation0.m_vec.m_quad, v3.m_vec.m_quad);
  v8 = _mm_mul_ps(v7, v7);
  v9 = _mm_add_ps(_mm_shuffle_ps(v8, v8, 78), v8);
  v10 = _mm_add_ps(_mm_shuffle_ps(v9, v9, 177), v9);
  v11 = _mm_sub_ps(
          _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_75), (__m128)LODWORD(FLOAT_0_75), 0),
          _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(FLOAT_0_125), (__m128)LODWORD(FLOAT_0_125), 0), v10));
  v12 = _mm_sub_ps(
          _mm_add_ps(query.m_quad, (__m128)xmmword_141A711B0),
          _mm_mul_ps(_mm_mul_ps(_mm_mul_ps(v10, (__m128)xmmword_141A711B0), v11), v11));
  v13 = _mm_mul_ps(r->m_real, (__m128)xmmword_141A710D0);
  v14 = _mm_mul_ps(v7, _mm_mul_ps(v12, v11));
  if ( COERCE_FLOAT(*r) >= 0.5 )
    v15 = _mm_add_ps(v14, _mm_mul_ps(_mm_sub_ps(v13, query.m_quad), _mm_sub_ps(v3.m_vec.m_quad, v14)));
  else
    v15 = _mm_add_ps(
            _mm_mul_ps(v13, _mm_sub_ps(v14, sweptTrans->m_rotation0.m_vec.m_quad)),
            sweptTrans->m_rotation0.m_vec.m_quad);
  v16 = _mm_mul_ps(v15, v15);
  v17 = _mm_add_ps(_mm_shuffle_ps(v16, v16, 78), v16);
  v18 = _mm_add_ps(_mm_shuffle_ps(v17, v17, 177), v17);
  v19 = _mm_rsqrt_ps(v18);
  qi.m_vec.m_quad = _mm_mul_ps(
                      v15,
                      _mm_mul_ps(
                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v18), v19)),
                        _mm_mul_ps(*(__m128 *)_xmm, v19)));
  hkRotationf::set(&transformOut->m_rotation, &qi);
  v20.m_quad = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_sub_ps(sweptTrans->m_centerOfMass1.m_quad, sweptTrans->m_centerOfMass0.m_quad),
                   r->m_real),
                 sweptTrans->m_centerOfMass0.m_quad);
  transformOut->m_translation = (hkVector4f)v20.m_quad;
  v21.m_quad = (__m128)sweptTrans->m_centerOfMassLocal;
  transformOut->m_translation.m_quad = _mm_sub_ps(
                                         v20.m_quad,
                                         _mm_add_ps(
                                           _mm_add_ps(
                                             _mm_mul_ps(
                                               _mm_shuffle_ps(v21.m_quad, v21.m_quad, 85),
                                               transformOut->m_rotation.m_col1.m_quad),
                                             _mm_mul_ps(
                                               _mm_shuffle_ps(v21.m_quad, v21.m_quad, 0),
                                               transformOut->m_rotation.m_col0.m_quad)),
                                           _mm_mul_ps(
                                             _mm_shuffle_ps(v21.m_quad, v21.m_quad, 170),
                                             transformOut->m_rotation.m_col2.m_quad)));
}

// File Line: 54
// RVA: 0x12FD3E0
void __fastcall hkSweptTransformUtil::lerp2Rel(hkSweptTransformf *sweptTrans, float r, hkTransformf *transformOut)
{
  hkQuaternionf v3; // xmm6
  __m128 v6; // xmm7
  __m128 v7; // xmm5
  __m128 v8; // xmm0
  __m128 v9; // xmm1
  __m128 v10; // xmm3
  __m128 v11; // xmm2
  __m128 v12; // xmm5
  __m128 v13; // xmm3
  __m128 v14; // xmm0
  __m128 v15; // xmm2
  __m128 v16; // xmm1
  __m128 v17; // xmm2
  hkVector4f v18; // xmm3
  hkVector4f v19; // xmm1
  hkQuaternionf qi; // [rsp+20h] [rbp-58h] BYREF

  v3.m_vec.m_quad = (__m128)sweptTrans->m_rotation1;
  v6 = _mm_shuffle_ps((__m128)LODWORD(r), (__m128)LODWORD(r), 0);
  v7 = _mm_add_ps(sweptTrans->m_rotation0.m_vec.m_quad, v3.m_vec.m_quad);
  v8 = _mm_mul_ps(v7, v7);
  v9 = _mm_add_ps(_mm_shuffle_ps(v8, v8, 78), v8);
  v10 = _mm_add_ps(_mm_shuffle_ps(v9, v9, 177), v9);
  v11 = _mm_sub_ps(
          _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_75), (__m128)LODWORD(FLOAT_0_75), 0),
          _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(FLOAT_0_125), (__m128)LODWORD(FLOAT_0_125), 0), v10));
  v12 = _mm_mul_ps(
          v7,
          _mm_mul_ps(
            _mm_sub_ps(
              _mm_add_ps(query.m_quad, (__m128)xmmword_141A711B0),
              _mm_mul_ps(_mm_mul_ps(_mm_mul_ps(v10, (__m128)xmmword_141A711B0), v11), v11)),
            v11));
  if ( v6.m128_f32[0] >= 0.5 )
    v13 = _mm_add_ps(
            v12,
            _mm_mul_ps(
              _mm_sub_ps(_mm_mul_ps(v6, (__m128)xmmword_141A710D0), query.m_quad),
              _mm_sub_ps(v3.m_vec.m_quad, v12)));
  else
    v13 = _mm_add_ps(
            _mm_mul_ps(_mm_mul_ps(v6, (__m128)xmmword_141A710D0), _mm_sub_ps(v12, sweptTrans->m_rotation0.m_vec.m_quad)),
            sweptTrans->m_rotation0.m_vec.m_quad);
  v14 = _mm_mul_ps(v13, v13);
  v15 = _mm_add_ps(_mm_shuffle_ps(v14, v14, 78), v14);
  v16 = _mm_add_ps(_mm_shuffle_ps(v15, v15, 177), v15);
  v17 = _mm_rsqrt_ps(v16);
  qi.m_vec.m_quad = _mm_mul_ps(
                      v13,
                      _mm_mul_ps(
                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v17, v16), v17)),
                        _mm_mul_ps(*(__m128 *)_xmm, v17)));
  hkRotationf::set(&transformOut->m_rotation, &qi);
  v18.m_quad = _mm_add_ps(
                 _mm_mul_ps(_mm_sub_ps(sweptTrans->m_centerOfMass1.m_quad, sweptTrans->m_centerOfMass0.m_quad), v6),
                 sweptTrans->m_centerOfMass0.m_quad);
  transformOut->m_translation = (hkVector4f)v18.m_quad;
  v19.m_quad = (__m128)sweptTrans->m_centerOfMassLocal;
  transformOut->m_translation.m_quad = _mm_sub_ps(
                                         v18.m_quad,
                                         _mm_add_ps(
                                           _mm_add_ps(
                                             _mm_mul_ps(
                                               _mm_shuffle_ps(v19.m_quad, v19.m_quad, 85),
                                               transformOut->m_rotation.m_col1.m_quad),
                                             _mm_mul_ps(
                                               _mm_shuffle_ps(v19.m_quad, v19.m_quad, 0),
                                               transformOut->m_rotation.m_col0.m_quad)),
                                           _mm_mul_ps(
                                             _mm_shuffle_ps(v19.m_quad, v19.m_quad, 170),
                                             transformOut->m_rotation.m_col2.m_quad)));
}

// File Line: 61
// RVA: 0x12FDAC0
void __fastcall hkSweptTransformUtil::backStepMotionState(hkSimdFloat32 *time, hkMotionState *motionState)
{
  hkVector4f v2; // xmm0
  hkVector4f v3; // xmm1
  hkQuaternionf *p_m_rotation1; // rdx
  __m128 m_quad; // xmm7
  hkQuaternionf v7; // xmm8
  __m128 v8; // xmm6
  __m128 v9; // xmm4
  __m128 v10; // xmm1
  __m128 v11; // xmm0
  __m128 v12; // xmm3
  __m128 v13; // xmm2
  __m128 v14; // xmm1
  __m128 v15; // xmm1
  __m128 v16; // xmm3
  __m128 v17; // xmm0
  __m128 v18; // xmm2
  __m128 v19; // xmm1
  __m128 v20; // xmm2
  hkVector4f v21; // xmm4
  __m128 v22; // xmm1
  __m128 v23; // xmm2
  __m128 v24; // xmm4
  hkVector4f v25; // xmm1

  v2.m_quad = (__m128)motionState->m_sweptTransform.m_centerOfMass0;
  v3.m_quad = (__m128)motionState->m_sweptTransform.m_centerOfMass1;
  p_m_rotation1 = &motionState->m_sweptTransform.m_rotation1;
  m_quad = p_m_rotation1->m_vec.m_quad;
  v7.m_vec.m_quad = (__m128)motionState->m_sweptTransform.m_rotation0;
  v8 = _mm_max_ps(
         _mm_mul_ps(
           _mm_sub_ps(time->m_real, _mm_shuffle_ps(v2.m_quad, v2.m_quad, 255)),
           _mm_shuffle_ps(v3.m_quad, v3.m_quad, 255)),
         *(__m128 *)&epsilon);
  v9 = _mm_add_ps(v7.m_vec.m_quad, p_m_rotation1->m_vec.m_quad);
  v10 = _mm_mul_ps(v9, v9);
  *p_m_rotation1 = (hkQuaternionf)v9;
  v11 = _mm_add_ps(_mm_shuffle_ps(v10, v10, 78), v10);
  v12 = _mm_add_ps(_mm_shuffle_ps(v11, v11, 177), v11);
  v13 = _mm_sub_ps(
          _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_75), (__m128)LODWORD(FLOAT_0_75), 0),
          _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(FLOAT_0_125), (__m128)LODWORD(FLOAT_0_125), 0), v12));
  v14 = _mm_mul_ps(
          _mm_mul_ps(
            _mm_sub_ps(
              _mm_add_ps(query.m_quad, (__m128)xmmword_141A711B0),
              _mm_mul_ps(_mm_mul_ps(_mm_mul_ps(v12, (__m128)xmmword_141A711B0), v13), v13)),
            v13),
          v9);
  *p_m_rotation1 = (hkQuaternionf)v14;
  if ( v8.m128_f32[0] >= 0.5 )
    v15 = _mm_add_ps(
            _mm_mul_ps(
              _mm_sub_ps(_mm_mul_ps(v8, (__m128)xmmword_141A710D0), query.m_quad),
              _mm_sub_ps(m_quad, p_m_rotation1->m_vec.m_quad)),
            p_m_rotation1->m_vec.m_quad);
  else
    v15 = _mm_add_ps(
            _mm_mul_ps(_mm_sub_ps(v14, v7.m_vec.m_quad), _mm_mul_ps(v8, (__m128)xmmword_141A710D0)),
            v7.m_vec.m_quad);
  *p_m_rotation1 = (hkQuaternionf)v15;
  v16 = v15;
  v17 = _mm_mul_ps(v15, v15);
  v18 = _mm_add_ps(_mm_shuffle_ps(v17, v17, 78), v17);
  v19 = _mm_add_ps(_mm_shuffle_ps(v18, v18, 177), v18);
  v20 = _mm_rsqrt_ps(v19);
  p_m_rotation1->m_vec.m_quad = _mm_mul_ps(
                                  _mm_mul_ps(
                                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v20, v19), v20)),
                                    _mm_mul_ps(*(__m128 *)_xmm, v20)),
                                  v16);
  v21.m_quad = (__m128)motionState->m_sweptTransform.m_centerOfMass1;
  v22 = _mm_rcp_ps(v8);
  v23 = _mm_shuffle_ps(v21.m_quad, v21.m_quad, 255);
  v24 = _mm_add_ps(
          _mm_mul_ps(_mm_sub_ps(v21.m_quad, motionState->m_sweptTransform.m_centerOfMass0.m_quad), v8),
          motionState->m_sweptTransform.m_centerOfMass0.m_quad);
  motionState->m_sweptTransform.m_centerOfMass1.m_quad = _mm_shuffle_ps(
                                                           v24,
                                                           _mm_unpackhi_ps(
                                                             v24,
                                                             _mm_mul_ps(
                                                               _mm_mul_ps(
                                                                 _mm_sub_ps((__m128)_xmm, _mm_mul_ps(v22, v8)),
                                                                 v22),
                                                               v23)),
                                                           196);
  motionState->m_deltaAngle.m_quad = _mm_mul_ps(motionState->m_deltaAngle.m_quad, v8);
  hkRotationf::set(&motionState->m_transform.m_rotation, p_m_rotation1);
  v25.m_quad = (__m128)motionState->m_sweptTransform.m_centerOfMassLocal;
  motionState->m_transform.m_translation.m_quad = _mm_sub_ps(
                                                    motionState->m_sweptTransform.m_centerOfMass1.m_quad,
                                                    _mm_add_ps(
                                                      _mm_add_ps(
                                                        _mm_mul_ps(
                                                          _mm_shuffle_ps(v25.m_quad, v25.m_quad, 85),
                                                          motionState->m_transform.m_rotation.m_col1.m_quad),
                                                        _mm_mul_ps(
                                                          _mm_shuffle_ps(v25.m_quad, v25.m_quad, 0),
                                                          motionState->m_transform.m_rotation.m_col0.m_quad)),
                                                      _mm_mul_ps(
                                                        _mm_shuffle_ps(v25.m_quad, v25.m_quad, 170),
                                                        motionState->m_transform.m_rotation.m_col2.m_quad)));
}

// File Line: 76
// RVA: 0x12FDA90
void __fastcall hkSweptTransformUtil::backStepMotionState(float time, hkMotionState *motionState)
{
  hkSimdFloat32 timea; // [rsp+20h] [rbp-18h] BYREF

  timea.m_real = _mm_shuffle_ps((__m128)LODWORD(time), (__m128)LODWORD(time), 0);
  hkSweptTransformUtil::backStepMotionState(&timea, motionState);
}

// File Line: 83
// RVA: 0x12FDD00
void __fastcall hkSweptTransformUtil::freezeMotionState(hkSimdFloat32 *time, hkMotionState *motionState)
{
  hkVector4f v2; // xmm1
  hkQuaternionf *p_m_rotation1; // rdx
  __m128 v5; // xmm1
  __m128 m_quad; // xmm7
  hkQuaternionf v7; // xmm9
  __m128 v8; // xmm11
  __m128 v9; // xmm8
  __m128 v10; // xmm6
  __m128 v11; // xmm0
  __m128 v12; // xmm1
  __m128 v13; // xmm4
  __m128 v14; // xmm0
  __m128 v15; // xmm3
  __m128 v16; // xmm2
  __m128 v17; // xmm0
  __m128 v18; // xmm0
  __m128 v19; // xmm2
  __m128 v20; // xmm1
  __m128 v21; // xmm2
  hkQuaternionf v22; // xmm3
  hkVector4f v23; // xmm1
  hkVector4f v24; // xmm1
  hkVector4f v25; // xmm1

  v2.m_quad = (__m128)motionState->m_sweptTransform.m_centerOfMass0;
  p_m_rotation1 = &motionState->m_sweptTransform.m_rotation1;
  v5 = _mm_shuffle_ps(v2.m_quad, v2.m_quad, 255);
  m_quad = p_m_rotation1->m_vec.m_quad;
  v7.m_vec.m_quad = (__m128)motionState->m_sweptTransform.m_rotation0;
  v8 = _mm_max_ps(time->m_real, v5);
  v9 = _mm_mul_ps(
         _mm_shuffle_ps(p_m_rotation1[-2].m_vec.m_quad, p_m_rotation1[-2].m_vec.m_quad, 255),
         _mm_sub_ps(v8, v5));
  v10 = _mm_mul_ps((__m128)xmmword_141A710D0, v9);
  v11 = _mm_add_ps(v7.m_vec.m_quad, p_m_rotation1->m_vec.m_quad);
  v12 = _mm_mul_ps(v11, v11);
  *p_m_rotation1 = (hkQuaternionf)v11;
  v13 = v11;
  v14 = _mm_add_ps(_mm_shuffle_ps(v12, v12, 78), v12);
  v15 = _mm_add_ps(_mm_shuffle_ps(v14, v14, 177), v14);
  v16 = _mm_sub_ps(
          _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_75), (__m128)LODWORD(FLOAT_0_75), 0),
          _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(FLOAT_0_125), (__m128)LODWORD(FLOAT_0_125), 0), v15));
  v17 = _mm_mul_ps(
          _mm_mul_ps(
            _mm_sub_ps(
              _mm_add_ps(query.m_quad, (__m128)xmmword_141A711B0),
              _mm_mul_ps(_mm_mul_ps(_mm_mul_ps(v15, (__m128)xmmword_141A711B0), v16), v16)),
            v16),
          v13);
  *p_m_rotation1 = (hkQuaternionf)v17;
  if ( v9.m128_f32[0] >= 0.5 )
    p_m_rotation1->m_vec.m_quad = _mm_add_ps(
                                    _mm_mul_ps(
                                      _mm_sub_ps(v10, query.m_quad),
                                      _mm_sub_ps(m_quad, p_m_rotation1->m_vec.m_quad)),
                                    p_m_rotation1->m_vec.m_quad);
  else
    p_m_rotation1->m_vec.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v17, v7.m_vec.m_quad), v10), v7.m_vec.m_quad);
  v18 = _mm_mul_ps(p_m_rotation1->m_vec.m_quad, p_m_rotation1->m_vec.m_quad);
  v19 = _mm_add_ps(_mm_shuffle_ps(v18, v18, 78), v18);
  v20 = _mm_add_ps(_mm_shuffle_ps(v19, v19, 177), v19);
  v21 = _mm_rsqrt_ps(v20);
  v22.m_vec.m_quad = _mm_mul_ps(
                       p_m_rotation1->m_vec.m_quad,
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
                         _mm_mul_ps(*(__m128 *)_xmm, v21)));
  v23.m_quad = (__m128)motionState->m_sweptTransform.m_centerOfMass1;
  *p_m_rotation1 = (hkQuaternionf)v22.m_vec.m_quad;
  motionState->m_sweptTransform.m_rotation0 = (hkQuaternionf)v22.m_vec.m_quad;
  v24.m_quad = _mm_add_ps(
                 _mm_mul_ps(_mm_sub_ps(v23.m_quad, motionState->m_sweptTransform.m_centerOfMass0.m_quad), v9),
                 motionState->m_sweptTransform.m_centerOfMass0.m_quad);
  motionState->m_sweptTransform.m_centerOfMass1 = (hkVector4f)v24.m_quad;
  motionState->m_sweptTransform.m_centerOfMass0.m_quad = _mm_shuffle_ps(
                                                           v24.m_quad,
                                                           _mm_unpackhi_ps(v24.m_quad, v8),
                                                           196);
  motionState->m_sweptTransform.m_centerOfMass1 = (hkVector4f)_mm_srli_si128(
                                                                _mm_slli_si128(
                                                                  _mm_load_si128((const __m128i *)&motionState->m_sweptTransform.m_centerOfMass1),
                                                                  4),
                                                                4);
  hkRotationf::set(&motionState->m_transform.m_rotation, p_m_rotation1);
  v25.m_quad = (__m128)motionState->m_sweptTransform.m_centerOfMassLocal;
  motionState->m_transform.m_translation.m_quad = _mm_sub_ps(
                                                    motionState->m_sweptTransform.m_centerOfMass1.m_quad,
                                                    _mm_add_ps(
                                                      _mm_add_ps(
                                                        _mm_mul_ps(
                                                          _mm_shuffle_ps(v25.m_quad, v25.m_quad, 85),
                                                          motionState->m_transform.m_rotation.m_col1.m_quad),
                                                        _mm_mul_ps(
                                                          _mm_shuffle_ps(v25.m_quad, v25.m_quad, 0),
                                                          motionState->m_transform.m_rotation.m_col0.m_quad)),
                                                      _mm_mul_ps(
                                                        _mm_shuffle_ps(v25.m_quad, v25.m_quad, 170),
                                                        motionState->m_transform.m_rotation.m_col2.m_quad)));
}

// File Line: 105
// RVA: 0x12FDCD0
void __fastcall hkSweptTransformUtil::freezeMotionState(float time, hkMotionState *motionState)
{
  hkSimdFloat32 timea; // [rsp+20h] [rbp-18h] BYREF

  timea.m_real = _mm_shuffle_ps((__m128)LODWORD(time), (__m128)LODWORD(time), 0);
  hkSweptTransformUtil::freezeMotionState(&timea, motionState);
}

// File Line: 111
// RVA: 0x12FDF00
void __fastcall hkSweptTransformUtil::setTimeInformation(
        float startTime,
        float invDeltaTime,
        hkMotionState *motionState)
{
  motionState->m_sweptTransform.m_centerOfMass0.m_quad.m128_f32[3] = startTime;
  motionState->m_sweptTransform.m_centerOfMass1.m_quad.m128_f32[3] = invDeltaTime;
}

// File Line: 118
// RVA: 0x12FDF20
void __fastcall hkSweptTransformUtil::setTimeInformation(
        hkSimdFloat32 *startTime,
        hkSimdFloat32 *invDeltaTime,
        hkMotionState *motionState)
{
  motionState->m_sweptTransform.m_centerOfMass0.m_quad = _mm_shuffle_ps(
                                                           motionState->m_sweptTransform.m_centerOfMass0.m_quad,
                                                           _mm_unpackhi_ps(
                                                             motionState->m_sweptTransform.m_centerOfMass0.m_quad,
                                                             startTime->m_real),
                                                           196);
  motionState->m_sweptTransform.m_centerOfMass1.m_quad = _mm_shuffle_ps(
                                                           motionState->m_sweptTransform.m_centerOfMass1.m_quad,
                                                           _mm_unpackhi_ps(
                                                             motionState->m_sweptTransform.m_centerOfMass1.m_quad,
                                                             invDeltaTime->m_real),
                                                           196);
}

// File Line: 124
// RVA: 0x12FE000
void __fastcall hkSweptTransformUtil::warpTo(hkVector4f *position, hkQuaternionf *rotation, hkMotionState *ms)
{
  hkVector4f v5; // xmm1
  __m128 v6; // xmm3
  hkVector4f v7; // xmm2

  ms->m_deltaAngle = 0i64;
  ms->m_sweptTransform.m_rotation0 = (hkQuaternionf)rotation->m_vec.m_quad;
  ms->m_sweptTransform.m_rotation1 = (hkQuaternionf)rotation->m_vec.m_quad;
  hkRotationf::set(&ms->m_transform.m_rotation, rotation);
  ms->m_transform.m_translation = (hkVector4f)position->m_quad;
  v5.m_quad = (__m128)ms->m_sweptTransform.m_centerOfMassLocal;
  v6 = _mm_shuffle_ps(ms->m_sweptTransform.m_centerOfMass0.m_quad, ms->m_sweptTransform.m_centerOfMass0.m_quad, 255);
  v7.m_quad = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v5.m_quad, v5.m_quad, 85), ms->m_transform.m_rotation.m_col1.m_quad),
                    _mm_mul_ps(_mm_shuffle_ps(v5.m_quad, v5.m_quad, 0), ms->m_transform.m_rotation.m_col0.m_quad)),
                  _mm_mul_ps(_mm_shuffle_ps(v5.m_quad, v5.m_quad, 170), ms->m_transform.m_rotation.m_col2.m_quad)),
                position->m_quad);
  ms->m_sweptTransform.m_centerOfMass0 = (hkVector4f)v7.m_quad;
  ms->m_sweptTransform.m_centerOfMass1 = (hkVector4f)v7.m_quad;
  ms->m_sweptTransform.m_centerOfMass0.m_quad = _mm_shuffle_ps(
                                                  ms->m_sweptTransform.m_centerOfMass0.m_quad,
                                                  _mm_unpackhi_ps(ms->m_sweptTransform.m_centerOfMass0.m_quad, v6),
                                                  196);
  ms->m_sweptTransform.m_centerOfMass1 = (hkVector4f)_mm_srli_si128(
                                                       _mm_slli_si128(
                                                         _mm_load_si128((const __m128i *)&ms->m_sweptTransform.m_centerOfMass1),
                                                         4),
                                                       4);
}

// File Line: 147
// RVA: 0x12FE0B0
void __fastcall hkSweptTransformUtil::warpTo(hkTransformf *transform, hkMotionState *ms)
{
  __m128 m_quad; // xmm0
  hkVector4f v5; // xmm1
  __m128 v6; // xmm3
  hkVector4f v7; // xmm2
  hkQuaternionf v8; // [rsp+20h] [rbp-18h] BYREF

  ms->m_deltaAngle = 0i64;
  hkQuaternionf::set(&v8, &transform->m_rotation);
  ms->m_transform.m_rotation.m_col0 = transform->m_rotation.m_col0;
  ms->m_transform.m_rotation.m_col1 = transform->m_rotation.m_col1;
  ms->m_transform.m_rotation.m_col2 = transform->m_rotation.m_col2;
  m_quad = v8.m_vec.m_quad;
  ms->m_transform.m_translation = transform->m_translation;
  ms->m_sweptTransform.m_rotation0.m_vec.m_quad = m_quad;
  ms->m_sweptTransform.m_rotation1.m_vec.m_quad = m_quad;
  v5.m_quad = (__m128)ms->m_sweptTransform.m_centerOfMassLocal;
  v6 = _mm_shuffle_ps(ms->m_sweptTransform.m_centerOfMass0.m_quad, ms->m_sweptTransform.m_centerOfMass0.m_quad, 255);
  v7.m_quad = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v5.m_quad, v5.m_quad, 85), transform->m_rotation.m_col1.m_quad),
                    _mm_mul_ps(_mm_shuffle_ps(v5.m_quad, v5.m_quad, 0), transform->m_rotation.m_col0.m_quad)),
                  _mm_mul_ps(_mm_shuffle_ps(v5.m_quad, v5.m_quad, 170), transform->m_rotation.m_col2.m_quad)),
                transform->m_translation.m_quad);
  ms->m_sweptTransform.m_centerOfMass0 = (hkVector4f)v7.m_quad;
  ms->m_sweptTransform.m_centerOfMass1 = (hkVector4f)v7.m_quad;
  ms->m_sweptTransform.m_centerOfMass0.m_quad = _mm_shuffle_ps(
                                                  ms->m_sweptTransform.m_centerOfMass0.m_quad,
                                                  _mm_unpackhi_ps(ms->m_sweptTransform.m_centerOfMass0.m_quad, v6),
                                                  196);
  ms->m_sweptTransform.m_centerOfMass1 = (hkVector4f)_mm_srli_si128(
                                                       _mm_slli_si128(
                                                         _mm_load_si128((const __m128i *)&ms->m_sweptTransform.m_centerOfMass1),
                                                         4),
                                                       4);
}

// File Line: 170
// RVA: 0x12FDF50
void __fastcall hkSweptTransformUtil::warpToPosition(hkVector4f *position, hkMotionState *ms)
{
  hkVector4f v2; // xmm1
  __m128 v3; // xmm3
  hkVector4f v4; // xmm2
  hkQuaternionf v5; // xmm0

  ms->m_deltaAngle = 0i64;
  ms->m_transform.m_translation = (hkVector4f)position->m_quad;
  v2.m_quad = (__m128)ms->m_sweptTransform.m_centerOfMassLocal;
  v3 = _mm_shuffle_ps(ms->m_sweptTransform.m_centerOfMass0.m_quad, ms->m_sweptTransform.m_centerOfMass0.m_quad, 255);
  v4.m_quad = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v2.m_quad, v2.m_quad, 85), ms->m_transform.m_rotation.m_col1.m_quad),
                    _mm_mul_ps(_mm_shuffle_ps(v2.m_quad, v2.m_quad, 0), ms->m_transform.m_rotation.m_col0.m_quad)),
                  _mm_mul_ps(_mm_shuffle_ps(v2.m_quad, v2.m_quad, 170), ms->m_transform.m_rotation.m_col2.m_quad)),
                position->m_quad);
  ms->m_sweptTransform.m_centerOfMass0 = (hkVector4f)v4.m_quad;
  v5.m_vec.m_quad = (__m128)ms->m_sweptTransform.m_rotation1;
  ms->m_sweptTransform.m_centerOfMass1 = (hkVector4f)v4.m_quad;
  ms->m_sweptTransform.m_rotation0 = (hkQuaternionf)v5.m_vec.m_quad;
  ms->m_sweptTransform.m_centerOfMass0.m_quad = _mm_shuffle_ps(
                                                  ms->m_sweptTransform.m_centerOfMass0.m_quad,
                                                  _mm_unpackhi_ps(ms->m_sweptTransform.m_centerOfMass0.m_quad, v3),
                                                  196);
  ms->m_sweptTransform.m_centerOfMass1 = (hkVector4f)_mm_srli_si128(
                                                       _mm_slli_si128(
                                                         _mm_load_si128((const __m128i *)&ms->m_sweptTransform.m_centerOfMass1),
                                                         4),
                                                       4);
}

// File Line: 192
// RVA: 0x12FDFE0
void __fastcall hkSweptTransformUtil::warpToRotation(hkQuaternionf *rotation, hkMotionState *ms)
{
  hkSweptTransformUtil::warpTo(&ms->m_transform.m_translation, rotation, ms);
}

// File Line: 197
// RVA: 0x12FD7B0
void __fastcall hkSweptTransformUtil::keyframeMotionState(
        hkStepInfo *stepInfo,
        hkVector4f *pos1,
        hkQuaternionf *rot1,
        hkMotionState *ms)
{
  hkQuaternionf v5; // xmm3
  __m128 v6; // xmm1
  __m128 v7; // xmm11
  __m128 v8; // xmm0
  __m128 v9; // xmm3
  __m128 v10; // xmm11
  __m128 v11; // xmm0
  __m128 v12; // xmm11
  __m128i v13; // xmm10
  __m128 v14; // xmm9
  __m128 v15; // xmm7
  __m128 v16; // xmm2
  __m128 v17; // xmm5
  __m128 v18; // xmm4
  __m128 v19; // xmm3
  __m128 v20; // xmm2
  __m128 v21; // xmm3
  __m128 v22; // xmm1
  __m128 v23; // xmm5
  __m128 v24; // xmm2
  __m128 v25; // xmm5
  __m128 v26; // xmm2
  __m128 v27; // xmm1
  __m128 v28; // xmm10
  __m128 v29; // xmm10
  hkVector4f v30; // xmm1
  unsigned int v31; // [rsp+90h] [rbp+8h]

  ms->m_sweptTransform.m_centerOfMass0 = ms->m_sweptTransform.m_centerOfMass1;
  ms->m_sweptTransform.m_rotation0 = ms->m_sweptTransform.m_rotation1;
  v5.m_vec.m_quad = (__m128)ms->m_sweptTransform.m_rotation0;
  ms->m_sweptTransform.m_centerOfMass1 = (hkVector4f)pos1->m_quad;
  ms->m_sweptTransform.m_rotation1 = (hkQuaternionf)rot1->m_vec.m_quad;
  v6 = _mm_mul_ps(_mm_shuffle_ps(v5.m_vec.m_quad, v5.m_vec.m_quad, 255), rot1->m_vec.m_quad);
  v7 = _mm_sub_ps(
         _mm_mul_ps(_mm_shuffle_ps(rot1->m_vec.m_quad, rot1->m_vec.m_quad, 201), v5.m_vec.m_quad),
         _mm_mul_ps(_mm_shuffle_ps(v5.m_vec.m_quad, v5.m_vec.m_quad, 201), rot1->m_vec.m_quad));
  v8 = _mm_mul_ps(_mm_shuffle_ps(rot1->m_vec.m_quad, rot1->m_vec.m_quad, 255), v5.m_vec.m_quad);
  v9 = _mm_mul_ps(v5.m_vec.m_quad, rot1->m_vec.m_quad);
  v10 = _mm_add_ps(_mm_sub_ps(_mm_shuffle_ps(v7, v7, 201), v8), v6);
  v11 = _mm_add_ps(_mm_shuffle_ps(v9, v9, 78), v9);
  v12 = _mm_shuffle_ps(v10, _mm_unpackhi_ps(v10, _mm_add_ps(_mm_shuffle_ps(v11, v11, 177), v11)), 196);
  v13 = (__m128i)_mm_shuffle_ps(v12, v12, 255);
  v14 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v13, 1u), 1u);
  v15 = _mm_andnot_ps(*(__m128 *)_xmm, v14);
  v16 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v15), *(__m128 *)_xmm);
  v17 = _mm_cmplt_ps(*(__m128 *)_xmm, v15);
  v18 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v16), v17), _mm_andnot_ps(v17, v15));
  v19 = _mm_or_ps(_mm_andnot_ps(v17, _mm_mul_ps(v15, v15)), _mm_and_ps(v17, v16));
  v20 = _mm_add_ps(
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v19, *(__m128 *)coeff4), *(__m128 *)coeff3), v19),
                        *(__m128 *)coeff2),
                      v19),
                    *(__m128 *)coeff1),
                  v19),
                *(__m128 *)coeff0),
              v19),
            v18),
          v18);
  v21 = _mm_mul_ps(v12, v12);
  v22 = _mm_and_ps(_mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v20, v20)), v17);
  v23 = _mm_andnot_ps(v17, v20);
  v24 = _mm_cmplt_ps(v15, *(__m128 *)_xmm);
  *(float *)&v31 = (float)(1.5707964
                         - COERCE_FLOAT((_mm_andnot_ps(v24, _mm_or_ps(v22, v23)).m128_u32[0] | v24.m128_i32[0] & v15.m128_i32[0]) ^ v14.m128_i32[0] & _xmm[0]))
                 * 2.0;
  v25 = _mm_shuffle_ps((__m128)v31, (__m128)v31, 0);
  if ( (float)((float)(_mm_shuffle_ps(v21, v21, 85).m128_f32[0] + _mm_shuffle_ps(v21, v21, 0).m128_f32[0])
             + _mm_shuffle_ps(v21, v21, 170).m128_f32[0]) <= 1.4210855e-14 )
  {
    v28 = 0i64;
  }
  else
  {
    v26 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)),
            _mm_shuffle_ps(v21, v21, 170));
    v27 = _mm_rsqrt_ps(v26);
    v28 = _mm_xor_ps(
            (__m128)_mm_slli_epi32(_mm_srli_epi32((__m128i)_mm_cmplt_ps((__m128)v13, (__m128)0i64), 0x1Fu), 0x1Fu),
            _mm_mul_ps(
              _mm_andnot_ps(
                _mm_cmple_ps(v26, (__m128)0i64),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v27, v26), v27)),
                  _mm_mul_ps(*(__m128 *)_xmm, v27))),
              v12));
  }
  v29 = _mm_mul_ps(v28, v25);
  ms->m_deltaAngle.m_quad = _mm_shuffle_ps(v29, _mm_unpackhi_ps(v29, v25), 196);
  ms->m_sweptTransform.m_centerOfMass0.m_quad.m128_i32[3] = LODWORD(stepInfo->m_startTime.m_storage);
  ms->m_sweptTransform.m_centerOfMass1.m_quad.m128_i32[3] = LODWORD(stepInfo->m_invDeltaTime.m_storage);
  hkRotationf::set(&ms->m_transform.m_rotation, &ms->m_sweptTransform.m_rotation1);
  v30.m_quad = (__m128)ms->m_sweptTransform.m_centerOfMassLocal;
  ms->m_transform.m_translation.m_quad = _mm_sub_ps(
                                           ms->m_sweptTransform.m_centerOfMass1.m_quad,
                                           _mm_add_ps(
                                             _mm_add_ps(
                                               _mm_mul_ps(
                                                 _mm_shuffle_ps(v30.m_quad, v30.m_quad, 85),
                                                 ms->m_transform.m_rotation.m_col1.m_quad),
                                               _mm_mul_ps(
                                                 _mm_shuffle_ps(v30.m_quad, v30.m_quad, 0),
                                                 ms->m_transform.m_rotation.m_col0.m_quad)),
                                             _mm_mul_ps(
                                               _mm_shuffle_ps(v30.m_quad, v30.m_quad, 170),
                                               ms->m_transform.m_rotation.m_col2.m_quad)));
}

// File Line: 250
// RVA: 0x12FD720
void __fastcall hkSweptTransformUtil::setCentreOfRotationLocal(
        hkVector4f *newCenterOfRotation,
        hkMotionState *motionState)
{
  __m128 v2; // xmm1
  __m128 v3; // xmm4
  hkVector4f v4; // xmm0
  __m128 v5; // xmm2

  v2 = _mm_sub_ps(newCenterOfRotation->m_quad, motionState->m_sweptTransform.m_centerOfMassLocal.m_quad);
  motionState->m_sweptTransform.m_centerOfMassLocal = (hkVector4f)newCenterOfRotation->m_quad;
  v3 = _mm_shuffle_ps(
         motionState->m_sweptTransform.m_centerOfMass1.m_quad,
         motionState->m_sweptTransform.m_centerOfMass1.m_quad,
         255);
  v4.m_quad = (__m128)motionState->m_sweptTransform.m_centerOfMass0;
  v5 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(_mm_shuffle_ps(v2, v2, 85), motionState->m_transform.m_rotation.m_col1.m_quad),
           _mm_mul_ps(_mm_shuffle_ps(v2, v2, 0), motionState->m_transform.m_rotation.m_col0.m_quad)),
         _mm_mul_ps(_mm_shuffle_ps(v2, v2, 170), motionState->m_transform.m_rotation.m_col2.m_quad));
  motionState->m_sweptTransform.m_centerOfMass0.m_quad = _mm_add_ps(v4.m_quad, v5);
  motionState->m_sweptTransform.m_centerOfMass1.m_quad = _mm_add_ps(
                                                           motionState->m_sweptTransform.m_centerOfMass1.m_quad,
                                                           v5);
  motionState->m_sweptTransform.m_centerOfMass0.m_quad = _mm_shuffle_ps(
                                                           motionState->m_sweptTransform.m_centerOfMass0.m_quad,
                                                           _mm_unpackhi_ps(
                                                             motionState->m_sweptTransform.m_centerOfMass0.m_quad,
                                                             _mm_shuffle_ps(v4.m_quad, v4.m_quad, 255)),
                                                           196);
  motionState->m_sweptTransform.m_centerOfMass1.m_quad = _mm_shuffle_ps(
                                                           motionState->m_sweptTransform.m_centerOfMass1.m_quad,
                                                           _mm_unpackhi_ps(
                                                             motionState->m_sweptTransform.m_centerOfMass1.m_quad,
                                                             v3),
                                                           196);
}

