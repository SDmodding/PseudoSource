// File Line: 14
// RVA: 0xBB8830
void __fastcall hkaiReferenceFrame::transformLocalPosVelToWorldVel(
        hkaiReferenceFrame *this,
        hkVector4f *localPos,
        hkVector4f *localVel,
        hkVector4f *worldVel)
{
  hkVector4f v4; // xmm8
  __m128 v5; // xmm1
  __m128 v6; // xmm7
  __m128 v7; // xmm6
  hkVector4f v8; // xmm1
  __m128 v9; // xmm4
  hkVector4f v10; // xmm1
  __m128 v11; // xmm2
  __m128 v12; // xmm3

  v4.m_quad = (__m128)this->m_transform.m_rotation.m_col2;
  v5 = _mm_unpacklo_ps(this->m_transform.m_rotation.m_col0.m_quad, this->m_transform.m_rotation.m_col1.m_quad);
  v6 = _mm_movelh_ps(v5, v4.m_quad);
  v7 = _mm_movehl_ps(v6, v5);
  v8.m_quad = (__m128)this->m_angularVelocity;
  v9 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(_mm_shuffle_ps(v8.m_quad, v8.m_quad, 85), _mm_shuffle_ps(v7, v4.m_quad, 212)),
           _mm_mul_ps(_mm_shuffle_ps(v8.m_quad, v8.m_quad, 0), v6)),
         _mm_mul_ps(
           _mm_shuffle_ps(v8.m_quad, v8.m_quad, 170),
           _mm_shuffle_ps(
             _mm_unpackhi_ps(this->m_transform.m_rotation.m_col0.m_quad, this->m_transform.m_rotation.m_col1.m_quad),
             v4.m_quad,
             228)));
  v10.m_quad = (__m128)this->m_linearVelocity;
  v11 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(localPos->m_quad, localPos->m_quad, 201), v9),
          _mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), localPos->m_quad));
  v12 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v10.m_quad, v10.m_quad, 85), _mm_shuffle_ps(v7, v4.m_quad, 212)),
                _mm_mul_ps(_mm_shuffle_ps(v10.m_quad, v10.m_quad, 0), v6)),
              _mm_mul_ps(
                _mm_shuffle_ps(v10.m_quad, v10.m_quad, 170),
                _mm_shuffle_ps(
                  _mm_unpackhi_ps(
                    this->m_transform.m_rotation.m_col0.m_quad,
                    this->m_transform.m_rotation.m_col1.m_quad),
                  v4.m_quad,
                  228))),
            _mm_shuffle_ps(v11, v11, 201)),
          localVel->m_quad);
  worldVel->m_quad = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v12, v12, 0), this->m_transform.m_rotation.m_col0.m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v12, v12, 85), this->m_transform.m_rotation.m_col1.m_quad)),
                       _mm_mul_ps(_mm_shuffle_ps(v12, v12, 170), v4.m_quad));
}

// File Line: 29
// RVA: 0xBB8950
void __fastcall hkaiReferenceFrame::transformLocalPosDirVelToWorldPosDirVel(
        hkaiReferenceFrame *this,
        hkVector4f *localPos,
        hkVector4f *localDir,
        hkVector4f *localVel,
        hkVector4f *worldUp,
        hkVector4f *worldPos,
        hkVector4f *worldDir,
        hkVector4f *worldVel)
{
  __m128 m_quad; // xmm0
  hkVector4f v9; // xmm8
  __m128 v10; // xmm1
  hkVector4f v11; // xmm10
  __m128 v12; // xmm7
  __m128 v13; // xmm6
  __m128 v14; // xmm15
  __m128 v15; // xmm4
  hkVector4f v16; // xmm1
  __m128 v17; // xmm2
  __m128 v18; // xmm3
  __m128 v19; // xmm10
  __m128 v20; // xmm5
  __m128 v21; // xmm2

  m_quad = localDir->m_quad;
  v9.m_quad = (__m128)this->m_transform.m_rotation.m_col2;
  v10 = _mm_unpacklo_ps(this->m_transform.m_rotation.m_col0.m_quad, this->m_transform.m_rotation.m_col1.m_quad);
  v11.m_quad = (__m128)this->m_angularVelocity;
  v12 = _mm_movelh_ps(v10, v9.m_quad);
  v13 = _mm_movehl_ps(v12, v10);
  v14 = _mm_add_ps(
          _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), this->m_transform.m_rotation.m_col0.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), this->m_transform.m_rotation.m_col1.m_quad));
  v15 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v11.m_quad, v11.m_quad, 85), _mm_shuffle_ps(v13, v9.m_quad, 212)),
            _mm_mul_ps(_mm_shuffle_ps(v11.m_quad, v11.m_quad, 0), v12)),
          _mm_mul_ps(
            _mm_shuffle_ps(v11.m_quad, v11.m_quad, 170),
            _mm_shuffle_ps(
              _mm_unpackhi_ps(this->m_transform.m_rotation.m_col0.m_quad, this->m_transform.m_rotation.m_col1.m_quad),
              v9.m_quad,
              228)));
  v16.m_quad = (__m128)this->m_linearVelocity;
  v17 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(localPos->m_quad, localPos->m_quad, 201), v15),
          _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), localPos->m_quad));
  v18 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v16.m_quad, v16.m_quad, 85), _mm_shuffle_ps(v13, v9.m_quad, 212)),
                _mm_mul_ps(_mm_shuffle_ps(v16.m_quad, v16.m_quad, 0), v12)),
              _mm_mul_ps(
                _mm_shuffle_ps(v16.m_quad, v16.m_quad, 170),
                _mm_shuffle_ps(
                  _mm_unpackhi_ps(
                    this->m_transform.m_rotation.m_col0.m_quad,
                    this->m_transform.m_rotation.m_col1.m_quad),
                  v9.m_quad,
                  228))),
            _mm_shuffle_ps(v17, v17, 201)),
          localVel->m_quad);
  v19 = _mm_mul_ps(v11.m_quad, worldUp->m_quad);
  v20 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v18, v18, 0), this->m_transform.m_rotation.m_col0.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v18, v18, 85), this->m_transform.m_rotation.m_col1.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v18, v18, 170), v9.m_quad));
  v21 = _mm_unpackhi_ps(
          v20,
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
              _mm_shuffle_ps(v19, v19, 170)),
            _mm_shuffle_ps(localVel->m_quad, localVel->m_quad, 255)));
  worldPos->m_quad = _mm_add_ps(
                       _mm_add_ps(
                         _mm_add_ps(
                           _mm_mul_ps(
                             _mm_shuffle_ps(localPos->m_quad, localPos->m_quad, 0),
                             this->m_transform.m_rotation.m_col0.m_quad),
                           _mm_mul_ps(
                             _mm_shuffle_ps(localPos->m_quad, localPos->m_quad, 85),
                             this->m_transform.m_rotation.m_col1.m_quad)),
                         _mm_mul_ps(_mm_shuffle_ps(localPos->m_quad, localPos->m_quad, 170), v9.m_quad)),
                       this->m_transform.m_translation.m_quad);
  worldDir->m_quad = _mm_add_ps(v14, _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), v9.m_quad));
  worldVel->m_quad = _mm_shuffle_ps(v20, v21, 196);
}m_quad, m_quad, 170), v9.m_quad));


// File Line: 54
// RVA: 0xBB8B60
void __fastcall hkaiReferenceFrame::transformWorldPosVelToLocalVel(
        hkaiReferenceFrame *this,
        hkVector4f *worldPos,
        hkVector4f *worldVel,
        hkVector4f *localVel)
{
  hkVector4f v4; // xmm3
  __m128 v5; // xmm5
  __m128 v6; // xmm1
  __m128 v7; // xmm2
  __m128 v8; // xmm9
  __m128 v9; // xmm13
  hkVector4f v10; // xmm1
  __m128 v11; // xmm5
  __m128 v12; // xmm4
  __m128 v13; // xmm0
  __m128 v14; // xmm1
  __m128 v15; // xmm5
  __m128 v16; // xmm6
  __m128 v17; // xmm4
  hkVector4f v18; // xmm1
  __m128 v19; // xmm13

  v4.m_quad = (__m128)this->m_transform.m_rotation.m_col2;
  v5 = _mm_sub_ps(worldPos->m_quad, this->m_transform.m_translation.m_quad);
  v6 = _mm_unpacklo_ps(this->m_transform.m_rotation.m_col0.m_quad, this->m_transform.m_rotation.m_col1.m_quad);
  v7 = _mm_movelh_ps(v6, v4.m_quad);
  v8 = _mm_shuffle_ps(_mm_movehl_ps(v7, v6), v4.m_quad, 212);
  v9 = _mm_add_ps(
         _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v5, v5, 85), v8), _mm_mul_ps(_mm_shuffle_ps(v5, v5, 0), v7)),
         _mm_mul_ps(
           _mm_shuffle_ps(v5, v5, 170),
           _mm_shuffle_ps(
             _mm_unpackhi_ps(this->m_transform.m_rotation.m_col0.m_quad, this->m_transform.m_rotation.m_col1.m_quad),
             v4.m_quad,
             228)));
  v10.m_quad = (__m128)this->m_angularVelocity;
  v11 = _mm_mul_ps(_mm_shuffle_ps(v10.m_quad, v10.m_quad, 85), v8);
  v12 = _mm_mul_ps(
          _mm_shuffle_ps(
            _mm_unpackhi_ps(this->m_transform.m_rotation.m_col0.m_quad, this->m_transform.m_rotation.m_col1.m_quad),
            v4.m_quad,
            228),
          _mm_shuffle_ps(v10.m_quad, v10.m_quad, 170));
  v13 = _mm_mul_ps(_mm_shuffle_ps(v10.m_quad, v10.m_quad, 0), v7);
  v14 = _mm_unpacklo_ps(this->m_transform.m_rotation.m_col0.m_quad, this->m_transform.m_rotation.m_col1.m_quad);
  v15 = _mm_add_ps(_mm_add_ps(v11, v13), v12);
  v16 = _mm_movelh_ps(v14, v4.m_quad);
  v17 = _mm_movehl_ps(v16, v14);
  v18.m_quad = (__m128)this->m_linearVelocity;
  v19 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), v15), _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v9));
  localVel->m_quad = _mm_sub_ps(
                       _mm_add_ps(
                         _mm_add_ps(
                           _mm_mul_ps(
                             _mm_shuffle_ps(worldVel->m_quad, worldVel->m_quad, 85),
                             _mm_shuffle_ps(v17, v4.m_quad, 212)),
                           _mm_mul_ps(_mm_shuffle_ps(worldVel->m_quad, worldVel->m_quad, 0), v16)),
                         _mm_mul_ps(
                           _mm_shuffle_ps(
                             _mm_unpackhi_ps(
                               this->m_transform.m_rotation.m_col0.m_quad,
                               this->m_transform.m_rotation.m_col1.m_quad),
                             v4.m_quad,
                             228),
                           _mm_shuffle_ps(worldVel->m_quad, worldVel->m_quad, 170))),
                       _mm_add_ps(
                         _mm_add_ps(
                           _mm_add_ps(
                             _mm_mul_ps(_mm_shuffle_ps(v18.m_quad, v18.m_quad, 85), v8),
                             _mm_mul_ps(_mm_shuffle_ps(v18.m_quad, v18.m_quad, 0), v7)),
                           _mm_mul_ps(
                             _mm_shuffle_ps(v18.m_quad, v18.m_quad, 170),
                             _mm_shuffle_ps(
                               _mm_unpackhi_ps(
                                 this->m_transform.m_rotation.m_col0.m_quad,
                                 this->m_transform.m_rotation.m_col1.m_quad),
                               v4.m_quad,
                               228))),
                         _mm_shuffle_ps(v19, v19, 201)));
}

// File Line: 73
// RVA: 0xBB8D30
void __fastcall hkaiReferenceFrame::transformWorldPosDirVelToLocalPosDirVel(
        hkaiReferenceFrame *this,
        hkVector4f *worldPos,
        hkVector4f *worldDir,
        hkVector4f *worldVel,
        hkVector4f *worldUp,
        hkVector4f *localPosOut,
        hkVector4f *localDirOut,
        hkVector4f *localVelOut,
        hkVector4f *localUpOut)
{
  hkVector4f v9; // xmm3
  __m128 v10; // xmm5
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  __m128 m_quad; // xmm15
  __m128 v14; // xmm8
  __m128 v15; // xmm2
  __m128 v16; // xmm3
  __m128 v17; // xmm0
  __m128 v18; // xmm1
  hkVector4f v19; // xmm2
  __m128 v20; // xmm1
  __m128 v21; // xmm3
  __m128 v22; // xmm1
  hkVector4f v23; // xmm12
  __m128 v24; // xmm15
  __m128 v25; // xmm7
  __m128 v26; // xmm1
  __m128 v27; // xmm14
  __m128 v28; // xmm11
  __m128 v29; // xmm10
  __m128 v30; // xmm5
  __m128 v31; // xmm8
  __m128 v32; // xmm2
  __m128 v33; // xmm5
  __m128 v34; // [rsp+0h] [rbp-F8h]
  __m128 v35; // [rsp+10h] [rbp-E8h]
  __m128 v36; // [rsp+20h] [rbp-D8h]
  __m128 v37; // [rsp+30h] [rbp-C8h]
  __m128 v38; // [rsp+40h] [rbp-B8h]

  v9.m_quad = (__m128)this->m_transform.m_rotation.m_col2;
  v10 = _mm_sub_ps(worldPos->m_quad, this->m_transform.m_translation.m_quad);
  v11 = _mm_unpacklo_ps(this->m_transform.m_rotation.m_col0.m_quad, this->m_transform.m_rotation.m_col1.m_quad);
  v12 = _mm_movelh_ps(v11, v9.m_quad);
  m_quad = worldUp->m_quad;
  v14 = _mm_add_ps(
          _mm_mul_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(_mm_movehl_ps(v12, v11), v9.m_quad, 212)),
          _mm_mul_ps(_mm_shuffle_ps(v10, v10, 0), v12));
  v15 = v9.m_quad;
  v34 = _mm_add_ps(
          v14,
          _mm_mul_ps(
            _mm_shuffle_ps(
              _mm_unpackhi_ps(this->m_transform.m_rotation.m_col0.m_quad, this->m_transform.m_rotation.m_col1.m_quad),
              v9.m_quad,
              228),
            _mm_shuffle_ps(v10, v10, 170)));
  v16 = _mm_movelh_ps(v11, v9.m_quad);
  v17 = _mm_movehl_ps(v16, v11);
  v18 = worldDir->m_quad;
  v36 = _mm_mul_ps(
          _mm_shuffle_ps(v18, v18, 170),
          _mm_shuffle_ps(
            _mm_unpackhi_ps(this->m_transform.m_rotation.m_col0.m_quad, this->m_transform.m_rotation.m_col1.m_quad),
            v15,
            228));
  v35 = _mm_add_ps(
          _mm_mul_ps(_mm_shuffle_ps(worldDir->m_quad, worldDir->m_quad, 85), _mm_shuffle_ps(v17, v15, 212)),
          _mm_mul_ps(_mm_shuffle_ps(v18, v18, 0), v16));
  v19.m_quad = (__m128)this->m_transform.m_rotation.m_col2;
  v20 = _mm_unpacklo_ps(this->m_transform.m_rotation.m_col0.m_quad, this->m_transform.m_rotation.m_col1.m_quad);
  v21 = _mm_movelh_ps(v20, v19.m_quad);
  v38 = _mm_mul_ps(
          _mm_shuffle_ps(m_quad, m_quad, 170),
          _mm_shuffle_ps(
            _mm_unpackhi_ps(this->m_transform.m_rotation.m_col0.m_quad, this->m_transform.m_rotation.m_col1.m_quad),
            v19.m_quad,
            228));
  v22 = _mm_add_ps(
          _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), _mm_shuffle_ps(_mm_movehl_ps(v21, v20), v19.m_quad, 212)),
          _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), v21));
  v23.m_quad = (__m128)this->m_angularVelocity;
  v24 = _mm_mul_ps(worldUp->m_quad, v23.m_quad);
  v37 = v22;
  v25 = v19.m_quad;
  v26 = _mm_unpacklo_ps(this->m_transform.m_rotation.m_col0.m_quad, this->m_transform.m_rotation.m_col1.m_quad);
  v27 = _mm_shuffle_ps(
          _mm_unpackhi_ps(this->m_transform.m_rotation.m_col0.m_quad, this->m_transform.m_rotation.m_col1.m_quad),
          v19.m_quad,
          228);
  v28 = _mm_movelh_ps(v26, v19.m_quad);
  v29 = _mm_shuffle_ps(_mm_movehl_ps(v28, v26), v19.m_quad, 212);
  v30 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v23.m_quad, v23.m_quad, 85), _mm_shuffle_ps(_mm_movehl_ps(v28, v26), v25, 212)),
            _mm_mul_ps(_mm_shuffle_ps(v23.m_quad, v23.m_quad, 0), v28)),
          _mm_mul_ps(
            _mm_shuffle_ps(
              _mm_unpackhi_ps(this->m_transform.m_rotation.m_col0.m_quad, this->m_transform.m_rotation.m_col1.m_quad),
              v25,
              228),
            _mm_shuffle_ps(v23.m_quad, v23.m_quad, 170)));
  v31 = worldVel->m_quad;
  v32 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v34, v34, 201), v30), _mm_mul_ps(_mm_shuffle_ps(v30, v30, 201), v34));
  v33 = _mm_sub_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(_mm_movehl_ps(v28, v26), v25, 212)),
              _mm_mul_ps(_mm_shuffle_ps(worldVel->m_quad, worldVel->m_quad, 0), v28)),
            _mm_mul_ps(
              _mm_shuffle_ps(
                _mm_unpackhi_ps(this->m_transform.m_rotation.m_col0.m_quad, this->m_transform.m_rotation.m_col1.m_quad),
                v25,
                228),
              _mm_shuffle_ps(worldVel->m_quad, worldVel->m_quad, 170))),
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(this->m_linearVelocity.m_quad, this->m_linearVelocity.m_quad, 85), v29),
                _mm_mul_ps(_mm_shuffle_ps(this->m_linearVelocity.m_quad, this->m_linearVelocity.m_quad, 0), v28)),
              _mm_mul_ps(_mm_shuffle_ps(this->m_linearVelocity.m_quad, this->m_linearVelocity.m_quad, 170), v27)),
            _mm_shuffle_ps(v32, v32, 201)));
  *localPosOut = (hkVector4f)v34;
  localDirOut->m_quad = _mm_add_ps(v35, v36);
  localVelOut->m_quad = _mm_shuffle_ps(
                          v33,
                          _mm_unpackhi_ps(
                            v33,
                            _mm_sub_ps(
                              _mm_shuffle_ps(v31, v31, 255),
                              _mm_add_ps(
                                _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
                                _mm_shuffle_ps(v24, v24, 170)))),
                          196);
  localUpOut->m_quad = _mm_add_ps(v37, v38);
}

// File Line: 102
// RVA: 0xBB9060
bool __fastcall hkaiReferenceFrame::isMoving(hkaiReferenceFrame *this)
{
  __m128 v1; // xmm2
  __m128 v2; // xmm2
  bool result; // al

  v1 = _mm_mul_ps(this->m_linearVelocity.m_quad, this->m_linearVelocity.m_quad);
  result = 1;
  if ( (float)((float)(_mm_shuffle_ps(v1, v1, 85).m128_f32[0] + _mm_shuffle_ps(v1, v1, 0).m128_f32[0])
             + _mm_shuffle_ps(v1, v1, 170).m128_f32[0]) <= 0.00000011920929 )
  {
    v2 = _mm_mul_ps(this->m_angularVelocity.m_quad, this->m_angularVelocity.m_quad);
    if ( (float)((float)(_mm_shuffle_ps(v2, v2, 85).m128_f32[0] + _mm_shuffle_ps(v2, v2, 0).m128_f32[0])
               + _mm_shuffle_ps(v2, v2, 170).m128_f32[0]) <= 0.00000011920929 )
      return 0;
  }
  return result;
}

// File Line: 109
// RVA: 0xBB90C0
void __fastcall hkaiReferenceFrame::validate(hkaiReferenceFrame *this)
{
  ;
}

// File Line: 116
// RVA: 0xBB90D0
void __fastcall hkaiReferenceFrame::checkDeterminism(hkaiReferenceFrame *this)
{
  ;
}

