// File Line: 14
// RVA: 0xBB8830
void __fastcall hkaiReferenceFrame::transformLocalPosVelToWorldVel(hkaiReferenceFrame *this, hkVector4f *localPos, hkVector4f *localVel, hkVector4f *worldVel)
{
  hkVector4f v4; // xmm8
  __m128 v5; // xmm1
  __m128 v6; // xmm7
  __m128 v7; // xmm6
  __m128 v8; // xmm1
  __m128 v9; // xmm2
  __m128 v10; // xmm0
  hkVector4f v11; // xmm1
  __m128 v12; // xmm4
  hkVector4f v13; // xmm1
  __m128 v14; // xmm2
  __m128 v15; // xmm3

  v4.m_quad = (__m128)this->m_transform.m_rotation.m_col2;
  v5 = _mm_unpacklo_ps(this->m_transform.m_rotation.m_col0.m_quad, this->m_transform.m_rotation.m_col1.m_quad);
  v6 = _mm_movelh_ps(v5, v4.m_quad);
  v7 = _mm_movehl_ps(v6, v5);
  v8 = v5;
  v9 = _mm_movelh_ps(v8, v4.m_quad);
  v10 = _mm_movehl_ps(v9, v8);
  v11.m_quad = (__m128)this->m_angularVelocity;
  v12 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v11.m_quad, v11.m_quad, 85), _mm_shuffle_ps(v10, v4.m_quad, 212)),
            _mm_mul_ps(_mm_shuffle_ps(this->m_angularVelocity.m_quad, v11.m_quad, 0), v9)),
          _mm_mul_ps(
            _mm_shuffle_ps(v11.m_quad, v11.m_quad, 170),
            _mm_shuffle_ps(
              _mm_unpackhi_ps(this->m_transform.m_rotation.m_col0.m_quad, this->m_transform.m_rotation.m_col1.m_quad),
              v4.m_quad,
              228)));
  v13.m_quad = (__m128)this->m_linearVelocity;
  v14 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(localPos->m_quad, localPos->m_quad, 201), v12),
          _mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), localPos->m_quad));
  v15 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v13.m_quad, v13.m_quad, 85), _mm_shuffle_ps(v7, v4.m_quad, 212)),
                _mm_mul_ps(_mm_shuffle_ps(this->m_linearVelocity.m_quad, v13.m_quad, 0), v6)),
              _mm_mul_ps(
                _mm_shuffle_ps(v13.m_quad, v13.m_quad, 170),
                _mm_shuffle_ps(
                  _mm_unpackhi_ps(
                    this->m_transform.m_rotation.m_col0.m_quad,
                    this->m_transform.m_rotation.m_col1.m_quad),
                  v4.m_quad,
                  228))),
            _mm_shuffle_ps(v14, v14, 201)),
          localVel->m_quad);
  worldVel->m_quad = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v15, v15, 0), this->m_transform.m_rotation.m_col0.m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v15, v15, 85), this->m_transform.m_rotation.m_col1.m_quad)),
                       _mm_mul_ps(_mm_shuffle_ps(v15, v15, 170), v4.m_quad));
}

// File Line: 29
// RVA: 0xBB8950
void __fastcall hkaiReferenceFrame::transformLocalPosDirVelToWorldPosDirVel(hkaiReferenceFrame *this, hkVector4f *localPos, hkVector4f *localDir, hkVector4f *localVel, hkVector4f *worldUp, hkVector4f *worldPos, hkVector4f *worldDir, hkVector4f *worldVel)
{
  __m128 v8; // xmm0
  hkVector4f v9; // xmm8
  __m128 v10; // ST00_16
  __m128 v11; // xmm1
  hkVector4f v12; // xmm10
  __m128 v13; // xmm11
  __m128 v14; // xmm7
  __m128 v15; // xmm6
  __m128 v16; // xmm1
  __m128 v17; // xmm2
  __m128 v18; // xmm15
  __m128 v19; // xmm4
  hkVector4f v20; // xmm1
  __m128 v21; // xmm2
  __m128 v22; // xmm3
  __m128 v23; // xmm10
  __m128 v24; // xmm5
  __m128 v25; // xmm2

  v8 = localDir->m_quad;
  v9.m_quad = (__m128)this->m_transform.m_rotation.m_col2;
  v10 = _mm_mul_ps(_mm_shuffle_ps(v8, v8, 170), this->m_transform.m_rotation.m_col2.m_quad);
  v11 = _mm_unpacklo_ps(this->m_transform.m_rotation.m_col0.m_quad, this->m_transform.m_rotation.m_col1.m_quad);
  v12.m_quad = (__m128)this->m_angularVelocity;
  v13 = localPos->m_quad;
  v14 = _mm_movelh_ps(v11, v9.m_quad);
  v15 = _mm_movehl_ps(v14, v11);
  v16 = v11;
  v17 = _mm_movelh_ps(v16, v9.m_quad);
  v18 = _mm_add_ps(
          _mm_mul_ps(_mm_shuffle_ps(v8, v8, 0), this->m_transform.m_rotation.m_col0.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(v8, v8, 85), this->m_transform.m_rotation.m_col1.m_quad));
  v19 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_shuffle_ps(v12.m_quad, v12.m_quad, 85),
              _mm_shuffle_ps(_mm_movehl_ps(v17, v16), v9.m_quad, 212)),
            _mm_mul_ps(_mm_shuffle_ps(this->m_angularVelocity.m_quad, v12.m_quad, 0), v17)),
          _mm_mul_ps(
            _mm_shuffle_ps(this->m_angularVelocity.m_quad, v12.m_quad, 170),
            _mm_shuffle_ps(
              _mm_unpackhi_ps(this->m_transform.m_rotation.m_col0.m_quad, this->m_transform.m_rotation.m_col1.m_quad),
              v9.m_quad,
              228)));
  v20.m_quad = (__m128)this->m_linearVelocity;
  v21 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), v19),
          _mm_mul_ps(_mm_shuffle_ps(v19, v19, 201), localPos->m_quad));
  v22 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v20.m_quad, v20.m_quad, 85), _mm_shuffle_ps(v15, v9.m_quad, 212)),
                _mm_mul_ps(_mm_shuffle_ps(this->m_linearVelocity.m_quad, v20.m_quad, 0), v14)),
              _mm_mul_ps(
                _mm_shuffle_ps(v20.m_quad, v20.m_quad, 170),
                _mm_shuffle_ps(
                  _mm_unpackhi_ps(
                    this->m_transform.m_rotation.m_col0.m_quad,
                    this->m_transform.m_rotation.m_col1.m_quad),
                  v9.m_quad,
                  228))),
            _mm_shuffle_ps(v21, v21, 201)),
          localVel->m_quad);
  v23 = _mm_mul_ps(v12.m_quad, worldUp->m_quad);
  v24 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v22, v22, 0), this->m_transform.m_rotation.m_col0.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v22, v22, 85), this->m_transform.m_rotation.m_col1.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v22, v22, 170), v9.m_quad));
  v25 = _mm_unpackhi_ps(
          v24,
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)),
              _mm_shuffle_ps(v23, v23, 170)),
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
                         _mm_mul_ps(_mm_shuffle_ps(v13, v13, 170), v9.m_quad)),
                       this->m_transform.m_translation.m_quad);
  worldDir->m_quad = _mm_add_ps(v18, v10);
  worldVel->m_quad = _mm_shuffle_ps(v24, v25, 196);
}

// File Line: 54
// RVA: 0xBB8B60
void __fastcall hkaiReferenceFrame::transformWorldPosVelToLocalVel(hkaiReferenceFrame *this, hkVector4f *worldPos, hkVector4f *worldVel, hkVector4f *localVel)
{
  hkVector4f v4; // xmm3
  __m128 v5; // xmm5
  __m128 v6; // xmm1
  __m128 v7; // xmm2
  __m128 v8; // xmm0
  __m128 v9; // xmm1
  hkVector4f v10; // xmm7
  __m128 v11; // xmm10
  __m128 v12; // xmm9
  __m128 v13; // xmm1
  __m128 v14; // xmm13
  __m128 v15; // xmm2
  __m128 v16; // xmm0
  hkVector4f v17; // xmm1
  __m128 v18; // xmm5
  __m128 v19; // xmm4
  __m128 v20; // xmm0
  __m128 v21; // xmm1
  __m128 v22; // xmm5
  __m128 v23; // xmm6
  __m128 v24; // xmm4
  hkVector4f v25; // xmm1
  __m128 v26; // xmm13

  v4.m_quad = (__m128)this->m_transform.m_rotation.m_col2;
  v5 = _mm_sub_ps(worldPos->m_quad, this->m_transform.m_translation.m_quad);
  v6 = _mm_unpacklo_ps(this->m_transform.m_rotation.m_col0.m_quad, this->m_transform.m_rotation.m_col1.m_quad);
  v7 = _mm_movelh_ps(v6, v4.m_quad);
  v8 = _mm_shuffle_ps(_mm_movehl_ps(v7, v6), v4.m_quad, 212);
  v9 = v6;
  v10.m_quad = (__m128)this->m_transform.m_rotation.m_col2;
  v11 = _mm_movelh_ps(v9, this->m_transform.m_rotation.m_col2.m_quad);
  v12 = _mm_shuffle_ps(_mm_movehl_ps(v11, v9), v4.m_quad, 212);
  v13 = _mm_unpacklo_ps(this->m_transform.m_rotation.m_col0.m_quad, this->m_transform.m_rotation.m_col1.m_quad);
  v14 = _mm_add_ps(
          _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v5, v5, 85), v8), _mm_mul_ps(_mm_shuffle_ps(v5, v5, 0), v7)),
          _mm_mul_ps(
            _mm_shuffle_ps(v5, v5, 170),
            _mm_shuffle_ps(
              _mm_unpackhi_ps(this->m_transform.m_rotation.m_col0.m_quad, this->m_transform.m_rotation.m_col1.m_quad),
              v4.m_quad,
              228)));
  v15 = _mm_movelh_ps(v13, v4.m_quad);
  v16 = _mm_shuffle_ps(_mm_movehl_ps(v15, v13), v4.m_quad, 212);
  v17.m_quad = (__m128)this->m_angularVelocity;
  v18 = _mm_mul_ps(_mm_shuffle_ps(v17.m_quad, v17.m_quad, 85), v16);
  v19 = _mm_mul_ps(
          _mm_shuffle_ps(
            _mm_unpackhi_ps(this->m_transform.m_rotation.m_col0.m_quad, this->m_transform.m_rotation.m_col1.m_quad),
            v4.m_quad,
            228),
          _mm_shuffle_ps(v17.m_quad, v17.m_quad, 170));
  v20 = _mm_mul_ps(_mm_shuffle_ps(this->m_angularVelocity.m_quad, v17.m_quad, 0), v15);
  v21 = _mm_unpacklo_ps(this->m_transform.m_rotation.m_col0.m_quad, this->m_transform.m_rotation.m_col1.m_quad);
  v22 = _mm_add_ps(_mm_add_ps(v18, v20), v19);
  v23 = _mm_movelh_ps(v21, v10.m_quad);
  v24 = _mm_movehl_ps(v23, v21);
  v25.m_quad = (__m128)this->m_linearVelocity;
  v26 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v22), _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v14));
  localVel->m_quad = _mm_sub_ps(
                       _mm_add_ps(
                         _mm_add_ps(
                           _mm_mul_ps(
                             _mm_shuffle_ps(worldVel->m_quad, worldVel->m_quad, 85),
                             _mm_shuffle_ps(v24, v4.m_quad, 212)),
                           _mm_mul_ps(_mm_shuffle_ps(worldVel->m_quad, worldVel->m_quad, 0), v23)),
                         _mm_mul_ps(
                           _mm_shuffle_ps(
                             _mm_unpackhi_ps(
                               this->m_transform.m_rotation.m_col0.m_quad,
                               this->m_transform.m_rotation.m_col1.m_quad),
                             v10.m_quad,
                             228),
                           _mm_shuffle_ps(worldVel->m_quad, worldVel->m_quad, 170))),
                       _mm_add_ps(
                         _mm_add_ps(
                           _mm_add_ps(
                             _mm_mul_ps(_mm_shuffle_ps(v25.m_quad, v25.m_quad, 85), v12),
                             _mm_mul_ps(_mm_shuffle_ps(this->m_linearVelocity.m_quad, v25.m_quad, 0), v11)),
                           _mm_mul_ps(
                             _mm_shuffle_ps(v25.m_quad, v25.m_quad, 170),
                             _mm_shuffle_ps(
                               _mm_unpackhi_ps(
                                 this->m_transform.m_rotation.m_col0.m_quad,
                                 this->m_transform.m_rotation.m_col1.m_quad),
                               v10.m_quad,
                               228))),
                         _mm_shuffle_ps(v26, v26, 201)));
}

// File Line: 73
// RVA: 0xBB8D30
void __fastcall hkaiReferenceFrame::transformWorldPosDirVelToLocalPosDirVel(hkaiReferenceFrame *this, hkVector4f *worldPos, hkVector4f *worldDir, hkVector4f *worldVel, hkVector4f *worldUp, hkVector4f *localPosOut, hkVector4f *localDirOut, hkVector4f *localVelOut, hkVector4f *localUpOut)
{
  hkVector4f v9; // xmm3
  __m128 v10; // xmm5
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  __m128 v13; // xmm15
  __m128 v14; // xmm8
  hkVector4f v15; // xmm2
  hkVector4f v16; // ST00_16
  __m128 v17; // xmm1
  __m128 v18; // xmm3
  __m128 v19; // xmm0
  __m128 v20; // xmm1
  __m128 v21; // ST20_16
  __m128 v22; // ST10_16
  hkVector4f v23; // xmm2
  __m128 v24; // xmm1
  __m128 v25; // xmm3
  __m128 v26; // ST40_16
  __m128 v27; // xmm1
  hkVector4f v28; // xmm12
  __m128 v29; // xmm15
  __m128 v30; // ST30_16
  hkVector4f v31; // xmm7
  __m128 v32; // xmm1
  __m128 v33; // xmm14
  __m128 v34; // xmm11
  __m128 v35; // xmm10
  __m128 v36; // xmm1
  __m128 v37; // xmm10
  __m128 v38; // xmm2
  __m128 v39; // xmm0
  __m128 v40; // xmm1
  __m128 v41; // xmm6
  __m128 v42; // xmm5
  __m128 v43; // xmm8
  __m128 v44; // xmm2
  __m128 v45; // xmm5

  v9.m_quad = (__m128)this->m_transform.m_rotation.m_col2;
  v10 = _mm_sub_ps(worldPos->m_quad, this->m_transform.m_translation.m_quad);
  v11 = _mm_unpacklo_ps(this->m_transform.m_rotation.m_col0.m_quad, this->m_transform.m_rotation.m_col1.m_quad);
  v12 = _mm_movelh_ps(v11, v9.m_quad);
  v13 = worldUp->m_quad;
  v14 = _mm_add_ps(
          _mm_mul_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(_mm_movehl_ps(v12, v11), v9.m_quad, 212)),
          _mm_mul_ps(_mm_shuffle_ps(v10, v10, 0), v12));
  v15.m_quad = (__m128)this->m_transform.m_rotation.m_col2;
  v16.m_quad = _mm_add_ps(
                 v14,
                 _mm_mul_ps(
                   _mm_shuffle_ps(
                     _mm_unpackhi_ps(
                       this->m_transform.m_rotation.m_col0.m_quad,
                       this->m_transform.m_rotation.m_col1.m_quad),
                     v9.m_quad,
                     228),
                   _mm_shuffle_ps(v10, v10, 170)));
  v17 = v11;
  v18 = _mm_movelh_ps(v17, v15.m_quad);
  v19 = _mm_movehl_ps(v18, v17);
  v20 = worldDir->m_quad;
  v21 = _mm_mul_ps(
          _mm_shuffle_ps(v20, v20, 170),
          _mm_shuffle_ps(
            _mm_unpackhi_ps(this->m_transform.m_rotation.m_col0.m_quad, this->m_transform.m_rotation.m_col1.m_quad),
            v15.m_quad,
            228));
  v22 = _mm_add_ps(
          _mm_mul_ps(_mm_shuffle_ps(worldDir->m_quad, worldDir->m_quad, 85), _mm_shuffle_ps(v19, v15.m_quad, 212)),
          _mm_mul_ps(_mm_shuffle_ps(v20, v20, 0), v18));
  v23.m_quad = (__m128)this->m_transform.m_rotation.m_col2;
  v24 = _mm_unpacklo_ps(this->m_transform.m_rotation.m_col0.m_quad, this->m_transform.m_rotation.m_col1.m_quad);
  v25 = _mm_movelh_ps(v24, v23.m_quad);
  v26 = _mm_mul_ps(
          _mm_shuffle_ps(v13, v13, 170),
          _mm_shuffle_ps(
            _mm_unpackhi_ps(this->m_transform.m_rotation.m_col0.m_quad, this->m_transform.m_rotation.m_col1.m_quad),
            v23.m_quad,
            228));
  v27 = _mm_add_ps(
          _mm_mul_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(_mm_movehl_ps(v25, v24), v23.m_quad, 212)),
          _mm_mul_ps(_mm_shuffle_ps(v13, v13, 0), v25));
  v28.m_quad = (__m128)this->m_angularVelocity;
  v29 = _mm_mul_ps(worldUp->m_quad, v28.m_quad);
  v30 = v27;
  v31.m_quad = (__m128)this->m_transform.m_rotation.m_col2;
  v32 = _mm_unpacklo_ps(this->m_transform.m_rotation.m_col0.m_quad, this->m_transform.m_rotation.m_col1.m_quad);
  v33 = _mm_shuffle_ps(
          _mm_unpackhi_ps(this->m_transform.m_rotation.m_col0.m_quad, this->m_transform.m_rotation.m_col1.m_quad),
          v23.m_quad,
          228);
  v34 = _mm_movelh_ps(v32, v23.m_quad);
  v35 = _mm_movehl_ps(v34, v32);
  v36 = v32;
  v37 = _mm_shuffle_ps(v35, v23.m_quad, 212);
  v38 = _mm_movelh_ps(v36, v23.m_quad);
  v39 = _mm_movehl_ps(v38, v36);
  v40 = _mm_unpacklo_ps(this->m_transform.m_rotation.m_col0.m_quad, this->m_transform.m_rotation.m_col1.m_quad);
  v41 = _mm_movelh_ps(v40, v31.m_quad);
  v42 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v28.m_quad, v28.m_quad, 85), _mm_shuffle_ps(v39, v31.m_quad, 212)),
            _mm_mul_ps(_mm_shuffle_ps(v28.m_quad, v28.m_quad, 0), v38)),
          _mm_mul_ps(
            _mm_shuffle_ps(
              _mm_unpackhi_ps(this->m_transform.m_rotation.m_col0.m_quad, this->m_transform.m_rotation.m_col1.m_quad),
              v31.m_quad,
              228),
            _mm_shuffle_ps(v28.m_quad, v28.m_quad, 170)));
  v43 = worldVel->m_quad;
  v44 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v16.m_quad, v16.m_quad, 201), v42),
          _mm_mul_ps(_mm_shuffle_ps(v42, v42, 201), v16.m_quad));
  v45 = _mm_sub_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v43, v43, 85), _mm_shuffle_ps(_mm_movehl_ps(v41, v40), v31.m_quad, 212)),
              _mm_mul_ps(_mm_shuffle_ps(worldVel->m_quad, worldVel->m_quad, 0), v41)),
            _mm_mul_ps(
              _mm_shuffle_ps(
                _mm_unpackhi_ps(this->m_transform.m_rotation.m_col0.m_quad, this->m_transform.m_rotation.m_col1.m_quad),
                v31.m_quad,
                228),
              _mm_shuffle_ps(worldVel->m_quad, worldVel->m_quad, 170))),
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(this->m_linearVelocity.m_quad, this->m_linearVelocity.m_quad, 85), v37),
                _mm_mul_ps(_mm_shuffle_ps(this->m_linearVelocity.m_quad, this->m_linearVelocity.m_quad, 0), v34)),
              _mm_mul_ps(_mm_shuffle_ps(this->m_linearVelocity.m_quad, this->m_linearVelocity.m_quad, 170), v33)),
            _mm_shuffle_ps(v44, v44, 201)));
  *localPosOut = (hkVector4f)v16.m_quad;
  localDirOut->m_quad = _mm_add_ps(v22, v21);
  localVelOut->m_quad = _mm_shuffle_ps(
                          v45,
                          _mm_unpackhi_ps(
                            v45,
                            _mm_sub_ps(
                              _mm_shuffle_ps(v43, v43, 255),
                              _mm_add_ps(
                                _mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)),
                                _mm_shuffle_ps(v29, v29, 170)))),
                          196);
  localUpOut->m_quad = _mm_add_ps(v30, v26);
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
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v1, v1, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v1, v1, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v1, v1, 170))) <= 0.00000011920929 )
  {
    v2 = _mm_mul_ps(this->m_angularVelocity.m_quad, this->m_angularVelocity.m_quad);
    if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v2, v2, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v2, v2, 0)))
               + COERCE_FLOAT(_mm_shuffle_ps(v2, v2, 170))) <= 0.00000011920929 )
      result = 0;
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

