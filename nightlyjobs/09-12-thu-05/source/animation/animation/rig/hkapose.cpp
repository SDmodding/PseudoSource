// File Line: 23
// RVA: 0xB1ACF0
void __fastcall hkaPose::hkaPose(
        hkaPose *this,
        hkaPose::PoseSpace space,
        hkaSkeleton *skeleton,
        hkArrayBase<hkQsTransformf> *pose)
{
  this->m_skeleton = skeleton;
  this->m_localPose.m_capacityAndFlags = 0x80000000;
  this->m_localPose.m_data = 0i64;
  this->m_localPose.m_size = 0;
  this->m_modelPose.m_data = 0i64;
  this->m_modelPose.m_size = 0;
  this->m_modelPose.m_capacityAndFlags = 0x80000000;
  this->m_boneFlags.m_data = 0i64;
  this->m_boneFlags.m_size = 0;
  this->m_boneFlags.m_capacityAndFlags = 0x80000000;
  this->m_floatSlotValues.m_data = 0i64;
  this->m_floatSlotValues.m_size = 0;
  this->m_floatSlotValues.m_capacityAndFlags = 0x80000000;
  hkaPose::init(this, space, skeleton, pose);
}

// File Line: 30
// RVA: 0xB1AD50
void __fastcall hkaPose::hkaPose(
        hkaPose *this,
        hkaPose::PoseSpace space,
        hkaSkeleton *skeleton,
        hkQsTransformf *pose,
        int numBones)
{
  hkArrayBase<hkQsTransformf> posea; // [rsp+20h] [rbp-18h] BYREF

  this->m_skeleton = skeleton;
  this->m_localPose.m_capacityAndFlags = 0x80000000;
  this->m_localPose.m_data = 0i64;
  this->m_localPose.m_size = 0;
  this->m_modelPose.m_data = 0i64;
  this->m_modelPose.m_size = 0;
  this->m_modelPose.m_capacityAndFlags = 0x80000000;
  this->m_boneFlags.m_data = 0i64;
  this->m_boneFlags.m_size = 0;
  this->m_boneFlags.m_capacityAndFlags = 0x80000000;
  this->m_floatSlotValues.m_data = 0i64;
  this->m_floatSlotValues.m_size = 0;
  posea.m_data = pose;
  posea.m_size = numBones;
  this->m_floatSlotValues.m_capacityAndFlags = 0x80000000;
  posea.m_capacityAndFlags = numBones | 0x80000000;
  hkaPose::init(this, space, skeleton, &posea);
}

// File Line: 41
// RVA: 0xB1C0F0
void __fastcall hkaPose::init(
        hkaPose *this,
        hkaPose::PoseSpace space,
        hkaSkeleton *skeleton,
        hkArrayBase<hkQsTransformf> *pose)
{
  int m_size; // edi
  int v8; // eax
  int v9; // eax
  int v10; // r9d
  int v11; // eax
  int v12; // eax
  int v13; // r9d
  int v14; // eax
  int v15; // eax
  int v16; // r9d
  hkArray<float,hkContainerHeapAllocator> *p_m_floatSlotValues; // rbx
  int v18; // r9d
  int v19; // esi
  int v20; // eax
  int v21; // eax
  int v22; // r9d
  int v23; // edx
  float *v24; // rdi
  __int64 v25; // rcx
  hkResult result; // [rsp+58h] [rbp+10h] BYREF

  m_size = this->m_skeleton->m_bones.m_size;
  v8 = this->m_modelPose.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v8 < m_size )
  {
    v9 = 2 * v8;
    v10 = this->m_skeleton->m_bones.m_size;
    if ( m_size < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_modelPose, v10, 48);
  }
  this->m_modelPose.m_size = m_size;
  v11 = this->m_localPose.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v11 < m_size )
  {
    v12 = 2 * v11;
    v13 = m_size;
    if ( m_size < v12 )
      v13 = v12;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_localPose, v13, 48);
  }
  this->m_localPose.m_size = m_size;
  v14 = this->m_boneFlags.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v14 < m_size )
  {
    v15 = 2 * v14;
    v16 = m_size;
    if ( m_size < v15 )
      v16 = v15;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_boneFlags, v16, 4);
  }
  this->m_boneFlags.m_size = m_size;
  if ( space == LOCAL_SPACE )
    hkaPose::setPoseLocalSpace(this, pose);
  else
    hkaPose::setPoseModelSpace(this, pose);
  p_m_floatSlotValues = &this->m_floatSlotValues;
  v18 = (this->m_skeleton->m_floatSlots.m_size + 3) & 0xFFFFFFFC;
  if ( (this->m_floatSlotValues.m_capacityAndFlags & 0x3FFFFFFF) < v18 )
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_floatSlotValues, v18, 4);
  v19 = this->m_skeleton->m_floatSlots.m_size;
  v20 = p_m_floatSlotValues->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v20 < v19 )
  {
    v21 = 2 * v20;
    v22 = v19;
    if ( v19 < v21 )
      v22 = v21;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, p_m_floatSlotValues, v22, 4);
  }
  v23 = v19 - p_m_floatSlotValues->m_size;
  v24 = &p_m_floatSlotValues->m_data[p_m_floatSlotValues->m_size];
  v25 = v23;
  if ( v23 > 0 )
  {
    while ( v25 )
    {
      *v24++ = 0.0;
      --v25;
    }
  }
  p_m_floatSlotValues->m_size = v19;
}

// File Line: 66
// RVA: 0xB1C480
void __fastcall hkaPose::setNonInitializedFlags(hkaPose *this)
{
  __int64 v1; // rdx
  __int64 m_size; // r8

  v1 = 0i64;
  m_size = this->m_skeleton->m_bones.m_size;
  if ( m_size <= 0 )
  {
    *(_WORD *)&this->m_modelInSync.m_bool = 0;
  }
  else
  {
    do
      this->m_boneFlags.m_data[v1++] = 3;
    while ( v1 < m_size );
    *(_WORD *)&this->m_modelInSync.m_bool = 0;
  }
}

// File Line: 78
// RVA: 0xB1C280
hkQsTransformf *__fastcall hkaPose::calculateBoneModelSpace(hkaPose *this, int theBoneIdx)
{
  unsigned int *m_data; // r9
  int v3; // r11d
  signed __int64 v4; // rbx
  __int64 v5; // r8
  __int16 v6; // ax
  signed __int64 v7; // rax
  unsigned __int64 v8; // r11
  hkQsTransformf *v9; // r8
  hkQsTransformf *v10; // r9
  __m128 *p_m_quad; // rdx
  __m128 v12; // xmm2
  __m128 v13; // xmm1
  __m128 v14; // xmm6
  __m128 v15; // xmm5
  __m128 v16; // xmm4
  __m128 v17; // xmm6
  __m128 m_quad; // xmm2
  __m128 v19; // xmm4
  __m128 v20; // xmm0
  __m128 v21; // xmm5
  __m128 v22; // xmm3
  __m128 v23; // xmm6
  __m128 v24; // xmm3
  __m128 v25; // xmm3

  m_data = this->m_boneFlags.m_data;
  v3 = theBoneIdx;
  v4 = theBoneIdx;
  if ( (m_data[theBoneIdx] & 2) != 0 )
  {
    v5 = theBoneIdx;
    while ( 1 )
    {
      v6 = this->m_skeleton->m_parentIndices.m_data[v5];
      if ( v6 == -1 )
        break;
      m_data[v5] |= 8u;
      m_data = this->m_boneFlags.m_data;
      v3 = v6;
      v5 = v6;
      if ( (m_data[v6] & 2) == 0 )
        goto LABEL_7;
    }
    this->m_modelPose.m_data[v3] = this->m_localPose.m_data[v3];
    this->m_boneFlags.m_data[v3] &= ~2u;
  }
LABEL_7:
  v7 = v3 + 1;
  if ( v7 <= theBoneIdx )
  {
    v8 = v7;
    do
    {
      if ( (this->m_boneFlags.m_data[v7] & 8) != 0 )
      {
        v9 = this->m_modelPose.m_data;
        v10 = &this->m_localPose.m_data[v8];
        p_m_quad = &v9[this->m_skeleton->m_parentIndices.m_data[v7]].m_translation.m_quad;
        v12 = p_m_quad[1];
        v13 = _mm_mul_ps(v10->m_translation.m_quad, v12);
        v14 = _mm_shuffle_ps(v12, v12, 255);
        v15 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v10->m_translation.m_quad, v10->m_translation.m_quad, 201), v12),
                _mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v10->m_translation.m_quad));
        v16 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
                      _mm_shuffle_ps(v13, v13, 170)),
                    v12),
                  _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v14, v14), (__m128)xmmword_141A711B0), v10->m_translation.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v14));
        v9[v8].m_translation.m_quad = _mm_add_ps(_mm_add_ps(v16, v16), *p_m_quad);
        v17 = p_m_quad[1];
        m_quad = v10->m_rotation.m_vec.m_quad;
        v19 = _mm_shuffle_ps(v17, v17, 255);
        v20 = _mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), m_quad);
        v21 = _mm_shuffle_ps(m_quad, m_quad, 255);
        v22 = _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v17);
        v23 = _mm_mul_ps(v17, m_quad);
        v24 = _mm_sub_ps(v22, v20);
        v25 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v24, v24, 201), _mm_mul_ps(m_quad, v19)),
                _mm_mul_ps(p_m_quad[1], v21));
        v9[v8].m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                           v25,
                                           _mm_unpackhi_ps(
                                             v25,
                                             _mm_sub_ps(
                                               _mm_mul_ps(v21, v19),
                                               _mm_add_ps(
                                                 _mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)),
                                                 _mm_shuffle_ps(v23, v23, 170)))),
                                           196);
        v9[v8].m_scale.m_quad = _mm_mul_ps(p_m_quad[2], v10->m_scale.m_quad);
        this->m_boneFlags.m_data[v7] &= 0xFFFFFFF5;
      }
      ++v7;
      ++v8;
    }
    while ( v7 <= v4 );
  }
  return &this->m_modelPose.m_data[v4];
}

// File Line: 147
// RVA: 0xB1ADD0
hkArray<hkQsTransformf,hkContainerHeapAllocator> *__fastcall hkaPose::getSyncedPoseLocalSpace(hkaPose *this)
{
  hkaPose::syncLocalSpace(this);
  return &this->m_localPose;
}

// File Line: 156
// RVA: 0xB1AF50
void __fastcall hkaPose::syncLocalSpace(hkaPose *this)
{
  __int64 m_size; // r13
  __int64 v3; // rbp
  __int64 v4; // rsi
  unsigned int *m_data; // rdx
  hkQsTransformf *v6; // r12
  __int16 v7; // ax
  hkQsTransformf *v8; // r15
  hkQsTransformf *v9; // rdi
  __m128 m_quad; // xmm3
  __m128i inserted; // xmm0
  __m128 v12; // xmm6
  __m128 v13; // xmm8
  __m128 v14; // xmm0
  __m128 v15; // xmm8
  __m128 v16; // xmm1
  __m128 v17; // xmm7
  __m128 v18; // xmm5
  __m128i v19; // xmm9
  __m128 v20; // xmm1
  __m128 v21; // xmm4
  __m128 v22; // xmm2
  __m128 v23; // xmm2
  __m128 v24; // xmm3
  __m128 v25; // xmm4
  __m128 v26; // xmm1
  __m128 v27; // xmm8
  __m128 v28; // xmm4
  __m128 v29; // xmm4
  hkQsTransformf *v30; // rax
  hkVector4f v31; // [rsp+20h] [rbp-98h] BYREF

  if ( !this->m_localInSync.m_bool )
  {
    m_size = this->m_skeleton->m_bones.m_size;
    v3 = 0i64;
    if ( m_size > 0 )
    {
      v4 = 0i64;
      do
      {
        m_data = this->m_boneFlags.m_data;
        if ( (m_data[v3] & 1) != 0 )
        {
          v6 = this->m_modelPose.m_data;
          v7 = this->m_skeleton->m_parentIndices.m_data[v3];
          if ( v7 == -1 )
          {
            v30 = this->m_localPose.m_data;
            v30[v4].m_translation = v6[v4].m_translation;
            v30[v4].m_rotation = v6[v4].m_rotation;
            v30[v4].m_scale = v6[v4].m_scale;
          }
          else
          {
            if ( (m_data[v7] & 2) != 0 )
              v8 = hkaPose::calculateBoneModelSpace(this, v7);
            else
              v8 = &v6[v7];
            v9 = this->m_localPose.m_data;
            hkVector4f::setRotatedInverseDir(&v31, &v8->m_rotation, &v8->m_translation);
            m_quad = v6[v4].m_translation.m_quad;
            inserted = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
            v12 = (__m128)_mm_shuffle_epi32(inserted, 0);
            v13 = (__m128)_mm_shuffle_epi32(inserted, 64);
            v14 = v8->m_scale.m_quad;
            v15 = _mm_xor_ps(v13, v8->m_rotation.m_vec.m_quad);
            v16 = _mm_rcp_ps(v14);
            v17 = _mm_shuffle_ps(v15, v15, 255);
            v18 = _mm_shuffle_ps(v15, v15, 201);
            v19 = _mm_slli_si128((__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v14, v16)), v16), 4);
            v20 = _mm_mul_ps(m_quad, v15);
            v21 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v15), _mm_mul_ps(m_quad, v18));
            v22 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
                          _mm_shuffle_ps(v20, v20, 170)),
                        v15),
                      _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v17, v17), (__m128)xmmword_141A711B0), m_quad)),
                    _mm_mul_ps(_mm_shuffle_ps(v21, v21, 201), v17));
            v9[v4].m_translation.m_quad = _mm_add_ps(_mm_add_ps(v22, v22), _mm_xor_ps(v12, v31.m_quad));
            v23 = v6[v4].m_rotation.m_vec.m_quad;
            v24 = _mm_shuffle_ps(v23, v23, 255);
            v25 = _mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), v15);
            v26 = _mm_mul_ps(v15, v24);
            v27 = _mm_mul_ps(v15, v23);
            v28 = _mm_sub_ps(v25, _mm_mul_ps(v23, v18));
            v29 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v28, v28, 201), _mm_mul_ps(v17, v23)), v26);
            v9[v4].m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                               v29,
                                               _mm_unpackhi_ps(
                                                 v29,
                                                 _mm_sub_ps(
                                                   _mm_mul_ps(v24, v17),
                                                   _mm_add_ps(
                                                     _mm_add_ps(
                                                       _mm_shuffle_ps(v27, v27, 85),
                                                       _mm_shuffle_ps(v27, v27, 0)),
                                                     _mm_shuffle_ps(v27, v27, 170)))),
                                               196);
            v9[v4].m_scale.m_quad = _mm_mul_ps(v6[v4].m_scale.m_quad, (__m128)_mm_srli_si128(v19, 4));
          }
          this->m_boneFlags.m_data[v3] &= ~1u;
        }
        ++v3;
        ++v4;
      }
      while ( v3 < m_size );
    }
    this->m_localInSync.m_bool = 1;
  }
}

// File Line: 193
// RVA: 0xB1ADF0
hkArray<hkQsTransformf,hkContainerHeapAllocator> *__fastcall hkaPose::getSyncedPoseModelSpace(hkaPose *this)
{
  hkaPose::syncModelSpace(this);
  return &this->m_modelPose;
}

// File Line: 202
// RVA: 0xB1B1F0
void __fastcall hkaPose::syncModelSpace(hkaPose *this)
{
  __int64 v1; // r9
  __int64 m_size; // rbx
  __int64 v3; // r10
  hkQsTransformf *v4; // r11
  __int16 v5; // ax
  hkQsTransformf *v6; // rdx
  __m128 *p_m_quad; // r8
  __m128 v8; // xmm2
  __m128 v9; // xmm1
  __m128 v10; // xmm6
  __m128 v11; // xmm5
  __m128 v12; // xmm4
  __m128 v13; // xmm6
  __m128 m_quad; // xmm2
  __m128 v15; // xmm4
  __m128 v16; // xmm0
  __m128 v17; // xmm5
  __m128 v18; // xmm3
  __m128 v19; // xmm6
  __m128 v20; // xmm3
  __m128 v21; // xmm3
  hkQsTransformf *m_data; // rax

  if ( !this->m_modelInSync.m_bool )
  {
    v1 = 0i64;
    m_size = this->m_skeleton->m_bones.m_size;
    if ( m_size > 0 )
    {
      v3 = 0i64;
      do
      {
        if ( (this->m_boneFlags.m_data[v1] & 2) != 0 )
        {
          v4 = &this->m_localPose.m_data[v3];
          v5 = this->m_skeleton->m_parentIndices.m_data[v1];
          if ( v5 == -1 )
          {
            m_data = this->m_modelPose.m_data;
            m_data[v3].m_translation = v4->m_translation;
            m_data[v3].m_rotation = v4->m_rotation;
            m_data[v3].m_scale = v4->m_scale;
          }
          else
          {
            v6 = this->m_modelPose.m_data;
            p_m_quad = &v6[v5].m_translation.m_quad;
            v8 = p_m_quad[1];
            v9 = _mm_mul_ps(v8, v4->m_translation.m_quad);
            v10 = _mm_shuffle_ps(v8, v8, 255);
            v11 = _mm_sub_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v4->m_translation.m_quad, v4->m_translation.m_quad, 201), v8),
                    _mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), v4->m_translation.m_quad));
            v12 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)),
                          _mm_shuffle_ps(v9, v9, 170)),
                        v8),
                      _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v10, v10), (__m128)xmmword_141A711B0), v4->m_translation.m_quad)),
                    _mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), v10));
            v6[v3].m_translation.m_quad = _mm_add_ps(_mm_add_ps(v12, v12), *p_m_quad);
            v13 = p_m_quad[1];
            m_quad = v4->m_rotation.m_vec.m_quad;
            v15 = _mm_shuffle_ps(v13, v13, 255);
            v16 = _mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), m_quad);
            v17 = _mm_shuffle_ps(m_quad, m_quad, 255);
            v18 = _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v13);
            v19 = _mm_mul_ps(v13, m_quad);
            v20 = _mm_sub_ps(v18, v16);
            v21 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v20, v20, 201), _mm_mul_ps(m_quad, v15)),
                    _mm_mul_ps(p_m_quad[1], v17));
            v6[v3].m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                               v21,
                                               _mm_unpackhi_ps(
                                                 v21,
                                                 _mm_sub_ps(
                                                   _mm_mul_ps(v17, v15),
                                                   _mm_add_ps(
                                                     _mm_add_ps(
                                                       _mm_shuffle_ps(v19, v19, 85),
                                                       _mm_shuffle_ps(v19, v19, 0)),
                                                     _mm_shuffle_ps(v19, v19, 170)))),
                                               196);
            v6[v3].m_scale.m_quad = _mm_mul_ps(p_m_quad[2], v4->m_scale.m_quad);
          }
          this->m_boneFlags.m_data[v1] &= ~2u;
        }
        ++v1;
        ++v3;
      }
      while ( v1 < m_size );
    }
    this->m_modelInSync.m_bool = 1;
  }
}

// File Line: 242
// RVA: 0xB1AE10
void __fastcall hkaPose::setPoseLocalSpace(hkaPose *this, hkArrayBase<hkQsTransformf> *poseLocal)
{
  hkQsTransformf *m_data; // r9
  hkQsTransformf *v3; // r10
  __int64 m_size; // rdi
  __int64 v5; // rbx
  int v6; // edx
  int v7; // r8d
  int v8; // eax
  __int64 i; // rax

  m_data = poseLocal->m_data;
  v3 = this->m_localPose.m_data;
  m_size = this->m_skeleton->m_bones.m_size;
  if ( 3 * (int)m_size > 0 )
  {
    v5 = (unsigned int)(3 * m_size);
    do
    {
      v6 = m_data->m_translation.m_quad.m128_i32[2];
      v7 = m_data->m_translation.m_quad.m128_i32[3];
      v8 = m_data->m_translation.m_quad.m128_i32[0];
      v3->m_translation.m_quad.m128_i32[1] = m_data->m_translation.m_quad.m128_i32[1];
      v3->m_translation.m_quad.m128_i32[2] = v6;
      v3->m_translation.m_quad.m128_i32[3] = v7;
      v3->m_translation.m_quad.m128_i32[0] = v8;
      v3 = (hkQsTransformf *)((char *)v3 + 16);
      m_data = (hkQsTransformf *)((char *)m_data + 16);
      --v5;
    }
    while ( v5 );
  }
  for ( i = 0i64; i < m_size; this->m_boneFlags.m_data[i - 1] = 2 )
    ++i;
  *(_WORD *)&this->m_modelInSync.m_bool = 256;
}

// File Line: 262
// RVA: 0xB1AEB0
void __fastcall hkaPose::setPoseModelSpace(hkaPose *this, hkArrayBase<hkQsTransformf> *poseModel)
{
  hkQsTransformf *m_data; // r9
  hkQsTransformf *v3; // r10
  __int64 m_size; // rdi
  __int64 v5; // rbx
  int v6; // edx
  int v7; // r8d
  int v8; // eax
  __int64 i; // rax

  m_data = poseModel->m_data;
  v3 = this->m_modelPose.m_data;
  m_size = this->m_skeleton->m_bones.m_size;
  if ( 3 * (int)m_size > 0 )
  {
    v5 = (unsigned int)(3 * m_size);
    do
    {
      v6 = m_data->m_translation.m_quad.m128_i32[2];
      v7 = m_data->m_translation.m_quad.m128_i32[3];
      v8 = m_data->m_translation.m_quad.m128_i32[0];
      v3->m_translation.m_quad.m128_i32[1] = m_data->m_translation.m_quad.m128_i32[1];
      v3->m_translation.m_quad.m128_i32[2] = v6;
      v3->m_translation.m_quad.m128_i32[3] = v7;
      v3->m_translation.m_quad.m128_i32[0] = v8;
      v3 = (hkQsTransformf *)((char *)v3 + 16);
      m_data = (hkQsTransformf *)((char *)m_data + 16);
      --v5;
    }
    while ( v5 );
  }
  for ( i = 0i64; i < m_size; this->m_boneFlags.m_data[i - 1] = 1 )
    ++i;
  *(_WORD *)&this->m_modelInSync.m_bool = 1;
}

// File Line: 284
// RVA: 0xB1B3B0
hkQsTransformf *__fastcall hkaPose::accessBoneLocalSpace(hkaPose *this, int boneIdx)
{
  __int64 v2; // r13
  __int64 m_size; // r8
  int v5; // eax
  __int64 v6; // r14
  __int64 v7; // rbp
  __int64 v8; // rdx
  unsigned int *m_data; // rcx
  hkQsTransformf *v10; // r12
  hkQsTransformf *v11; // r15
  hkQsTransformf *v12; // rdi
  __m128 m_quad; // xmm3
  __m128i inserted; // xmm0
  __m128 v15; // xmm6
  __m128 v16; // xmm8
  __m128 v17; // xmm0
  __m128 v18; // xmm8
  __m128 v19; // xmm1
  __m128 v20; // xmm7
  __m128 v21; // xmm5
  __m128i v22; // xmm9
  __m128 v23; // xmm1
  __m128 v24; // xmm4
  __m128 v25; // xmm2
  __m128 v26; // xmm2
  __m128 v27; // xmm3
  __m128 v28; // xmm4
  __m128 v29; // xmm1
  __m128 v30; // xmm8
  __m128 v31; // xmm4
  __m128 v32; // xmm4
  __int64 i; // rcx
  unsigned int *v34; // rdx
  unsigned int v35; // eax
  unsigned int *v36; // rdx
  hkQsTransformf *v37; // r15
  __int16 v38; // ax
  hkQsTransformf *v39; // r14
  hkQsTransformf *v40; // rdi
  __m128 v41; // xmm3
  __m128 v42; // xmm2
  __m128i v43; // xmm0
  __m128 v44; // xmm8
  __m128 v45; // xmm9
  __m128 v46; // xmm1
  __m128 v47; // xmm7
  __m128 v48; // xmm5
  __m128 v49; // xmm4
  __m128 v50; // xmm2
  __m128 v51; // xmm2
  __m128 v52; // xmm3
  __m128 v53; // xmm4
  __m128 v54; // xmm1
  __m128 v55; // xmm8
  __m128 v56; // xmm4
  __m128 v57; // xmm4
  hkQsTransformf *v58; // rax
  hkVector4f v60; // [rsp+20h] [rbp-A8h] BYREF
  __int64 v61; // [rsp+D0h] [rbp+8h]
  int v62; // [rsp+D8h] [rbp+10h]
  __int64 v63; // [rsp+E0h] [rbp+18h]

  v2 = boneIdx;
  v63 = boneIdx;
  m_size = this->m_skeleton->m_bones.m_size;
  this->m_boneFlags.m_data[boneIdx] |= 4u;
  v5 = boneIdx + 1;
  v61 = m_size;
  v6 = boneIdx + 1;
  v62 = boneIdx + 1;
  if ( v6 < m_size )
  {
    v7 = v5;
    do
    {
      LOWORD(v8) = this->m_skeleton->m_parentIndices.m_data[v6];
      if ( (_WORD)v8 != 0xFFFF )
      {
        m_data = this->m_boneFlags.m_data;
        if ( (m_data[(__int16)v8] & 4) != 0 )
        {
          if ( (m_data[v6] & 1) != 0 )
          {
            v10 = this->m_modelPose.m_data;
            v8 = (__int16)v8;
            if ( (m_data[(__int16)v8] & 2) != 0 )
              v11 = hkaPose::calculateBoneModelSpace(this, v8);
            else
              v11 = &v10[v8];
            v12 = this->m_localPose.m_data;
            hkVector4f::setRotatedInverseDir(&v60, &v11->m_rotation, &v11->m_translation);
            m_quad = v10[v7].m_translation.m_quad;
            inserted = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
            v15 = (__m128)_mm_shuffle_epi32(inserted, 0);
            v16 = (__m128)_mm_shuffle_epi32(inserted, 64);
            v17 = v11->m_scale.m_quad;
            v18 = _mm_xor_ps(v16, v11->m_rotation.m_vec.m_quad);
            v19 = _mm_rcp_ps(v17);
            v20 = _mm_shuffle_ps(v18, v18, 255);
            v21 = _mm_shuffle_ps(v18, v18, 201);
            v22 = _mm_slli_si128((__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v17, v19)), v19), 4);
            v23 = _mm_mul_ps(v18, m_quad);
            v24 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v18), _mm_mul_ps(v21, m_quad));
            v25 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)),
                          _mm_shuffle_ps(v23, v23, 170)),
                        v18),
                      _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v20, v20), (__m128)xmmword_141A711B0), m_quad)),
                    _mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), v20));
            v12[v7].m_translation.m_quad = _mm_add_ps(_mm_add_ps(v25, v25), _mm_xor_ps(v15, v60.m_quad));
            v26 = v10[v7].m_rotation.m_vec.m_quad;
            v27 = _mm_shuffle_ps(v26, v26, 255);
            v28 = _mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), v18);
            v29 = _mm_mul_ps(v18, v27);
            v30 = _mm_mul_ps(v18, v26);
            v31 = _mm_sub_ps(v28, _mm_mul_ps(v21, v26));
            v32 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v31, v31, 201), _mm_mul_ps(v20, v26)), v29);
            v12[v7].m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                                v32,
                                                _mm_unpackhi_ps(
                                                  v32,
                                                  _mm_sub_ps(
                                                    _mm_mul_ps(v27, v20),
                                                    _mm_add_ps(
                                                      _mm_add_ps(
                                                        _mm_shuffle_ps(v30, v30, 85),
                                                        _mm_shuffle_ps(v30, v30, 0)),
                                                      _mm_shuffle_ps(v30, v30, 170)))),
                                                196);
            m_size = v61;
            v12[v7].m_scale.m_quad = _mm_mul_ps(v10[v7].m_scale.m_quad, (__m128)_mm_srli_si128(v22, 4));
            this->m_boneFlags.m_data[v6] &= ~1u;
          }
          this->m_boneFlags.m_data[v6] |= 4u;
          this->m_modelInSync.m_bool = 0;
        }
      }
      ++v6;
      ++v7;
    }
    while ( v6 < m_size );
    v2 = v63;
    v5 = v62;
  }
  for ( i = v5; i < m_size; ++i )
  {
    v34 = this->m_boneFlags.m_data;
    v35 = v34[i];
    if ( (v35 & 4) != 0 )
      v34[i] = v35 & 0xFFFFFFF9 | 2;
  }
  v36 = this->m_boneFlags.m_data;
  if ( (v36[v2] & 1) != 0 )
  {
    v37 = this->m_modelPose.m_data;
    v38 = this->m_skeleton->m_parentIndices.m_data[v2];
    if ( v38 == -1 )
    {
      v58 = this->m_localPose.m_data;
      v58[v2].m_translation = v37[v2].m_translation;
      v58[v2].m_rotation = v37[v2].m_rotation;
      v58[v2].m_scale = v37[v2].m_scale;
    }
    else
    {
      if ( (v36[v38] & 2) != 0 )
        v39 = hkaPose::calculateBoneModelSpace(this, v38);
      else
        v39 = &v37[v38];
      v40 = this->m_localPose.m_data;
      hkVector4f::setRotatedInverseDir(&v60, &v39->m_rotation, &v39->m_translation);
      v41 = v37[v2].m_translation.m_quad;
      v42 = _mm_rcp_ps(v39->m_scale.m_quad);
      v43 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
      v44 = _mm_xor_ps((__m128)_mm_shuffle_epi32(v43, 64), v39->m_rotation.m_vec.m_quad);
      v45 = (__m128)_mm_srli_si128(
                      _mm_slli_si128(
                        (__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v42, v39->m_scale.m_quad)), v42),
                        4),
                      4);
      v46 = _mm_mul_ps(v41, v44);
      v47 = _mm_shuffle_ps(v44, v44, 255);
      v48 = _mm_shuffle_ps(v44, v44, 201);
      v49 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v41, v41, 201), v44), _mm_mul_ps(v41, v48));
      v50 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v46, v46, 85), _mm_shuffle_ps(v46, v46, 0)),
                    _mm_shuffle_ps(v46, v46, 170)),
                  v44),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v47, v47), (__m128)xmmword_141A711B0), v41)),
              _mm_mul_ps(_mm_shuffle_ps(v49, v49, 201), v47));
      v40[v2].m_translation.m_quad = _mm_add_ps(
                                       _mm_add_ps(v50, v50),
                                       _mm_xor_ps((__m128)_mm_shuffle_epi32(v43, 0), v60.m_quad));
      v51 = v37[v2].m_rotation.m_vec.m_quad;
      v52 = _mm_shuffle_ps(v51, v51, 255);
      v53 = _mm_mul_ps(_mm_shuffle_ps(v51, v51, 201), v44);
      v54 = _mm_mul_ps(v44, v52);
      v55 = _mm_mul_ps(v44, v51);
      v56 = _mm_sub_ps(v53, _mm_mul_ps(v51, v48));
      v57 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v56, v56, 201), _mm_mul_ps(v51, v47)), v54);
      v40[v2].m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                          v57,
                                          _mm_unpackhi_ps(
                                            v57,
                                            _mm_sub_ps(
                                              _mm_mul_ps(v52, v47),
                                              _mm_add_ps(
                                                _mm_add_ps(_mm_shuffle_ps(v55, v55, 85), _mm_shuffle_ps(v55, v55, 0)),
                                                _mm_shuffle_ps(v55, v55, 170)))),
                                          196);
      v40[v2].m_scale.m_quad = _mm_mul_ps(v37[v2].m_scale.m_quad, v45);
    }
    this->m_boneFlags.m_data[v2] &= ~1u;
  }
  this->m_boneFlags.m_data[v2] = 2;
  this->m_modelInSync.m_bool = 0;
  return &this->m_localPose.m_data[v2];
}

// File Line: 300
// RVA: 0xB1B8A0
hkQsTransformf *__fastcall hkaPose::accessBoneModelSpace(
        hkaPose *this,
        int boneIdx,
        hkaPose::PropagateOrNot propagateOrNot)
{
  hkaSkeleton *m_skeleton; // rax
  __int64 v4; // r9
  __int64 v6; // rbp
  int v7; // edi
  __int64 j; // rbx
  __int64 m_size; // rdx
  int v10; // eax
  __int64 v11; // r14
  __int64 v12; // r13
  __int64 v13; // rbp
  __int64 v14; // rdx
  unsigned int *m_data; // rcx
  hkQsTransformf *v16; // r12
  hkQsTransformf *v17; // r15
  hkQsTransformf *v18; // rdi
  __m128 m_quad; // xmm3
  __m128i inserted; // xmm0
  __m128 v21; // xmm6
  __m128 v22; // xmm8
  __m128 v23; // xmm0
  __m128 v24; // xmm8
  __m128 v25; // xmm1
  __m128 v26; // xmm7
  __m128 v27; // xmm5
  __m128i v28; // xmm9
  __m128 v29; // xmm1
  __m128 v30; // xmm4
  __m128 v31; // xmm2
  __m128 v32; // xmm2
  __m128 v33; // xmm3
  __m128 v34; // xmm4
  __m128 v35; // xmm1
  __m128 v36; // xmm8
  __m128 v37; // xmm4
  __m128 v38; // xmm4
  __int64 i; // rcx
  unsigned int *v40; // rdx
  unsigned int v41; // eax
  __int64 v42; // rbx
  hkVector4f v44; // [rsp+20h] [rbp-A8h] BYREF
  int v46; // [rsp+E0h] [rbp+18h]

  m_skeleton = this->m_skeleton;
  v4 = boneIdx;
  if ( propagateOrNot )
  {
    m_size = m_skeleton->m_bones.m_size;
    this->m_boneFlags.m_data[v4] |= 4u;
    v10 = v4 + 1;
    v11 = (int)v4 + 1;
    v46 = v4 + 1;
    v12 = m_size;
    if ( v11 < m_size )
    {
      v13 = v10;
      do
      {
        LOWORD(v14) = this->m_skeleton->m_parentIndices.m_data[v11];
        if ( (_WORD)v14 != 0xFFFF )
        {
          m_data = this->m_boneFlags.m_data;
          if ( (m_data[(__int16)v14] & 4) != 0 )
          {
            if ( (m_data[v11] & 1) != 0 )
            {
              v16 = this->m_modelPose.m_data;
              v14 = (__int16)v14;
              if ( (m_data[(__int16)v14] & 2) != 0 )
                v17 = hkaPose::calculateBoneModelSpace(this, v14);
              else
                v17 = &v16[v14];
              v18 = this->m_localPose.m_data;
              hkVector4f::setRotatedInverseDir(&v44, &v17->m_rotation, &v17->m_translation);
              m_quad = v16[v13].m_translation.m_quad;
              inserted = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
              v21 = (__m128)_mm_shuffle_epi32(inserted, 0);
              v22 = (__m128)_mm_shuffle_epi32(inserted, 64);
              v23 = v17->m_scale.m_quad;
              v24 = _mm_xor_ps(v22, v17->m_rotation.m_vec.m_quad);
              v25 = _mm_rcp_ps(v23);
              v26 = _mm_shuffle_ps(v24, v24, 255);
              v27 = _mm_shuffle_ps(v24, v24, 201);
              v28 = _mm_slli_si128((__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v23, v25)), v25), 4);
              v29 = _mm_mul_ps(v24, m_quad);
              v30 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v24), _mm_mul_ps(v27, m_quad));
              v31 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_add_ps(
                            _mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)),
                            _mm_shuffle_ps(v29, v29, 170)),
                          v24),
                        _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v26, v26), (__m128)xmmword_141A711B0), m_quad)),
                      _mm_mul_ps(_mm_shuffle_ps(v30, v30, 201), v26));
              v18[v13].m_translation.m_quad = _mm_add_ps(_mm_add_ps(v31, v31), _mm_xor_ps(v21, v44.m_quad));
              v32 = v16[v13].m_rotation.m_vec.m_quad;
              v33 = _mm_shuffle_ps(v32, v32, 255);
              v34 = _mm_mul_ps(_mm_shuffle_ps(v32, v32, 201), v24);
              v35 = _mm_mul_ps(v33, v24);
              v36 = _mm_mul_ps(v24, v32);
              v37 = _mm_sub_ps(v34, _mm_mul_ps(v27, v32));
              v38 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v37, v37, 201), _mm_mul_ps(v26, v32)), v35);
              v18[v13].m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                                   v38,
                                                   _mm_unpackhi_ps(
                                                     v38,
                                                     _mm_sub_ps(
                                                       _mm_mul_ps(v33, v26),
                                                       _mm_add_ps(
                                                         _mm_add_ps(
                                                           _mm_shuffle_ps(v36, v36, 85),
                                                           _mm_shuffle_ps(v36, v36, 0)),
                                                         _mm_shuffle_ps(v36, v36, 170)))),
                                                   196);
              v18[v13].m_scale.m_quad = _mm_mul_ps(v16[v13].m_scale.m_quad, (__m128)_mm_srli_si128(v28, 4));
              this->m_boneFlags.m_data[v11] &= ~1u;
            }
            this->m_boneFlags.m_data[v11] |= 4u;
            this->m_modelInSync.m_bool = 0;
          }
        }
        ++v11;
        ++v13;
      }
      while ( v11 < v12 );
      LODWORD(v4) = boneIdx;
      v10 = v46;
    }
    for ( i = v10; i < v12; ++i )
    {
      v40 = this->m_boneFlags.m_data;
      v41 = v40[i];
      if ( (v41 & 4) != 0 )
        v40[i] = v41 & 0xFFFFFFF9 | 2;
    }
  }
  else
  {
    v6 = m_skeleton->m_bones.m_size;
    v7 = boneIdx + 1;
    for ( j = boneIdx + 1; j < v6; ++v7 )
    {
      if ( this->m_skeleton->m_parentIndices.m_data[j] == (_DWORD)v4 )
      {
        if ( (this->m_boneFlags.m_data[j] & 2) != 0 )
        {
          hkaPose::calculateBoneModelSpace(this, v7);
          LODWORD(v4) = boneIdx;
        }
        this->m_boneFlags.m_data[j] = 1;
        this->m_localInSync.m_bool = 0;
      }
      ++j;
    }
  }
  v42 = (int)v4;
  if ( (this->m_boneFlags.m_data[(int)v4] & 2) != 0 )
    hkaPose::calculateBoneModelSpace(this, v4);
  this->m_boneFlags.m_data[v42] = 1;
  this->m_localInSync.m_bool = 0;
  return &this->m_modelPose.m_data[v42];
}

// File Line: 326
// RVA: 0xB1BC60
hkArray<hkQsTransformf,hkContainerHeapAllocator> *__fastcall hkaPose::accessSyncedPoseLocalSpace(hkaPose *this)
{
  hkaPose::syncLocalSpace(this);
  return hkaPose::accessUnsyncedPoseLocalSpace(this);
}

// File Line: 334
// RVA: 0xB1BC90
hkArray<hkQsTransformf,hkContainerHeapAllocator> *__fastcall hkaPose::accessSyncedPoseModelSpace(hkaPose *this)
{
  hkaPose::syncModelSpace(this);
  return hkaPose::accessUnsyncedPoseModelSpace(this);
}

// File Line: 342
// RVA: 0xB1BCC0
hkArray<hkQsTransformf,hkContainerHeapAllocator> *__fastcall hkaPose::accessUnsyncedPoseLocalSpace(hkaPose *this)
{
  __int64 v1; // rax
  __int64 m_size; // r8

  v1 = 0i64;
  m_size = this->m_skeleton->m_bones.m_size;
  if ( (int)m_size > 0 )
  {
    do
      this->m_boneFlags.m_data[v1++] = 2;
    while ( v1 < m_size );
  }
  *(_WORD *)&this->m_modelInSync.m_bool = 256;
  return &this->m_localPose;
}

// File Line: 358
// RVA: 0xB1BD00
hkArray<hkQsTransformf,hkContainerHeapAllocator> *__fastcall hkaPose::accessUnsyncedPoseModelSpace(hkaPose *this)
{
  __int64 v1; // rax
  __int64 m_size; // r8

  v1 = 0i64;
  m_size = this->m_skeleton->m_bones.m_size;
  if ( (int)m_size > 0 )
  {
    do
      this->m_boneFlags.m_data[v1++] = 1;
    while ( v1 < m_size );
  }
  *(_WORD *)&this->m_modelInSync.m_bool = 1;
  return &this->m_modelPose;
}

// File Line: 376
// RVA: 0xB1C4D0
hkBool *__fastcall hkaPose::checkPoseValidity(hkaPose *this, hkBool *result)
{
  __int64 v2; // r8
  __int64 m_size; // r9
  __int64 v5; // r10
  unsigned int *m_data; // rax
  __int64 v7; // rax
  unsigned int *v8; // rcx
  unsigned int *v9; // rax

  v2 = 0i64;
  m_size = this->m_skeleton->m_bones.m_size;
  v5 = 0i64;
  if ( m_size > 0 )
  {
    m_data = this->m_boneFlags.m_data;
    while ( (*m_data & 1) == 0 || (*m_data & 2) == 0 )
    {
      ++v5;
      ++m_data;
      if ( v5 >= m_size )
        goto LABEL_6;
    }
    goto LABEL_17;
  }
LABEL_6:
  if ( this->m_localInSync.m_bool )
  {
    v7 = 0i64;
    if ( m_size > 0 )
    {
      v8 = this->m_boneFlags.m_data;
      while ( (*(_BYTE *)v8 & 1) == 0 )
      {
        ++v7;
        ++v8;
        if ( v7 >= m_size )
          goto LABEL_11;
      }
LABEL_17:
      result->m_bool = 0;
      return result;
    }
  }
LABEL_11:
  if ( this->m_modelInSync.m_bool && m_size > 0 )
  {
    v9 = this->m_boneFlags.m_data;
    while ( (*(_BYTE *)v9 & 2) == 0 )
    {
      ++v2;
      ++v9;
      if ( v2 >= m_size )
        goto LABEL_16;
    }
    result->m_bool = 0;
    return result;
  }
  else
  {
LABEL_16:
    result->m_bool = 1;
    return result;
  }
}

// File Line: 422
// RVA: 0xB1C580
hkBool *__fastcall hkaPose::checkPoseTransformsValidity(hkaPose *this, hkBool *result)
{
  int v2; // edi
  __int64 m_size; // rbp
  __int64 v6; // rbx
  unsigned int v7; // ecx

  v2 = 0;
  m_size = this->m_skeleton->m_bones.m_size;
  v6 = 0i64;
  if ( m_size <= 0 )
  {
LABEL_9:
    result->m_bool = 1;
  }
  else
  {
    while ( 1 )
    {
      v7 = this->m_boneFlags.m_data[v6];
      if ( (v7 & 2) != 0 && (v7 & 1) != 0 )
        break;
      if ( (this->m_boneFlags.m_data[v6] & 2) == 0 && !hkQsTransformf::isOk(&this->m_modelPose.m_data[v2], 0.001)
        || (this->m_boneFlags.m_data[v6] & 1) == 0 && !hkQsTransformf::isOk(&this->m_localPose.m_data[v2], 0.001) )
      {
        break;
      }
      ++v6;
      ++v2;
      if ( v6 >= m_size )
        goto LABEL_9;
    }
    result->m_bool = 0;
  }
  return result;
}

// File Line: 452
// RVA: 0xB1BD40
void __fastcall hkaPose::setToReferencePose(hkaPose *this)
{
  hkQsTransformf *m_data; // r10
  hkQsTransformf *v3; // r9
  int v4; // ecx
  __int64 v5; // rbx
  int v6; // ecx
  int v7; // r8d
  int v8; // eax
  int v9; // ecx
  __int64 v10; // rdx
  hkaSkeleton *m_skeleton; // rdx
  int v12; // ecx
  float *v13; // rax

  m_data = this->m_localPose.m_data;
  v3 = this->m_skeleton->m_referencePose.m_data;
  v4 = 3 * this->m_skeleton->m_bones.m_size;
  if ( v4 > 0 )
  {
    v5 = (unsigned int)v4;
    do
    {
      v6 = v3->m_translation.m_quad.m128_i32[2];
      v7 = v3->m_translation.m_quad.m128_i32[3];
      v8 = v3->m_translation.m_quad.m128_i32[0];
      m_data->m_translation.m_quad.m128_i32[1] = v3->m_translation.m_quad.m128_i32[1];
      m_data->m_translation.m_quad.m128_i32[2] = v6;
      m_data->m_translation.m_quad.m128_i32[3] = v7;
      m_data->m_translation.m_quad.m128_i32[0] = v8;
      m_data = (hkQsTransformf *)((char *)m_data + 16);
      v3 = (hkQsTransformf *)((char *)v3 + 16);
      --v5;
    }
    while ( v5 );
  }
  v9 = 0;
  if ( this->m_skeleton->m_bones.m_size > 0 )
  {
    v10 = 0i64;
    do
    {
      ++v9;
      this->m_boneFlags.m_data[v10++] = 2;
    }
    while ( v9 < this->m_skeleton->m_bones.m_size );
  }
  *(_WORD *)&this->m_modelInSync.m_bool = 256;
  m_skeleton = this->m_skeleton;
  v12 = 0;
  if ( this->m_skeleton->m_floatSlots.m_size > 0 )
  {
    v13 = this->m_floatSlotValues.m_data;
    do
    {
      *v13 = 0.0;
      ++v12;
      ++v13;
    }
    while ( v12 < m_skeleton->m_floatSlots.m_size );
  }
}

// File Line: 474
// RVA: 0xB1BE00
void __fastcall hkaPose::enforceSkeletonConstraintsLocalSpace(hkaPose *this)
{
  __int64 m_size; // rdi
  __int64 v3; // r8
  __int64 v4; // rdx
  __int64 v5; // r10
  __int64 v6; // r9
  hkaSkeleton *m_skeleton; // rcx
  __int16 v8; // cx
  unsigned int *m_data; // r11
  __int64 v10; // rcx

  m_size = this->m_skeleton->m_bones.m_size;
  hkaPose::syncLocalSpace(this);
  v3 = 0i64;
  v4 = 0i64;
  if ( m_size > 0 )
  {
    v5 = 0i64;
    v6 = 0i64;
    do
    {
      m_skeleton = this->m_skeleton;
      if ( this->m_skeleton->m_bones.m_data[v6].m_lockTranslation.m_bool )
      {
        this->m_localPose.m_data[v5].m_translation = m_skeleton->m_referencePose.m_data[v5].m_translation;
        this->m_boneFlags.m_data[v4] |= 2u;
      }
      else
      {
        v8 = m_skeleton->m_parentIndices.m_data[v4];
        if ( v8 == -1 )
          goto LABEL_9;
        m_data = this->m_boneFlags.m_data;
        if ( (m_data[v8] & 4) == 0 )
          goto LABEL_9;
        m_data[v4] |= 2u;
      }
      this->m_boneFlags.m_data[v4] |= 4u;
LABEL_9:
      ++v4;
      ++v6;
      ++v5;
    }
    while ( v4 < m_size );
  }
  v10 = this->m_boneFlags.m_size;
  if ( v10 > 0 )
  {
    do
      this->m_boneFlags.m_data[v3++] &= 0xFFFFFFE3;
    while ( v3 < v10 );
  }
}

// File Line: 511
// RVA: 0xB1BED0
void __fastcall hkaPose::enforceSkeletonConstraintsModelSpace(hkaPose *this)
{
  __int64 m_size; // rdi
  __int64 v3; // r9
  __int64 v4; // rsi
  __int64 v5; // r8
  __int64 v6; // r10
  __int64 v7; // r11
  __int16 v8; // dx
  hkQsTransformf *m_data; // rdi
  __m128 v10; // xmm4
  hkQsTransformf *v11; // rcx
  hkQsTransformf *v12; // rdx
  __m128 v13; // xmm2
  __m128 v14; // xmm1
  __m128 v15; // xmm6
  __m128 v16; // xmm5
  __m128 v17; // xmm3
  hkQsTransformf *v18; // rax
  __m128 m_quad; // xmm0
  unsigned int *v20; // rcx
  __int64 v21; // rcx

  m_size = this->m_skeleton->m_bones.m_size;
  hkaPose::syncModelSpace(this);
  v3 = 0i64;
  v4 = m_size;
  v5 = 0i64;
  if ( (int)m_size > 0 )
  {
    v6 = 0i64;
    v7 = 0i64;
    do
    {
      v8 = this->m_skeleton->m_parentIndices.m_data[v5];
      if ( this->m_skeleton->m_bones.m_data[v7].m_lockTranslation.m_bool )
      {
        m_data = this->m_skeleton->m_referencePose.m_data;
        if ( v8 == -1 )
        {
          v18 = this->m_modelPose.m_data;
          m_quad = m_data[v6].m_translation.m_quad;
        }
        else
        {
          v10 = m_data[v6].m_translation.m_quad;
          v11 = this->m_modelPose.m_data;
          v12 = &v11[v8];
          v13 = v12->m_rotation.m_vec.m_quad;
          v14 = _mm_mul_ps(v13, v10);
          v15 = _mm_shuffle_ps(v13, v13, 255);
          v16 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v13),
                  _mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), v10));
          v17 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
                        _mm_shuffle_ps(v14, v14, 170)),
                      v13),
                    _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v15, v15), (__m128)xmmword_141A711B0), v10)),
                  _mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v15));
          v11[v6].m_translation.m_quad = _mm_add_ps(v17, v17);
          v18 = this->m_modelPose.m_data;
          m_quad = _mm_add_ps(v12->m_translation.m_quad, v18[v6].m_translation.m_quad);
        }
        v18[v6].m_translation.m_quad = m_quad;
        this->m_boneFlags.m_data[v5] |= 1u;
        this->m_boneFlags.m_data[v5] |= 4u;
      }
      else if ( v8 != -1 )
      {
        v20 = this->m_boneFlags.m_data;
        if ( (v20[v8] & 4) != 0 )
          v20[v5] |= 1u;
      }
      ++v5;
      ++v7;
      ++v6;
    }
    while ( v5 < v4 );
  }
  v21 = this->m_boneFlags.m_size;
  if ( v21 > 0 )
  {
    do
      this->m_boneFlags.m_data[v3++] &= 0xFFFFFFE3;
    while ( v3 < v21 );
  }
}

// File Line: 564
// RVA: 0xB1C050
void __fastcall hkaPose::getModelSpaceAabb(hkaPose *this, hkAabb *aabbOut)
{
  __int64 m_size; // rdi
  __int64 v5; // rdx
  __m128 m_quad; // xmm1
  __int64 v7; // rcx
  hkQsTransformf *m_data; // rax

  aabbOut->m_min = (hkVector4f)xmmword_141A712A0;
  aabbOut->m_max.m_quad = _mm_xor_ps(
                            (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                            aabbOut->m_min.m_quad);
  m_size = this->m_skeleton->m_bones.m_size;
  hkaPose::syncModelSpace(this);
  v5 = m_size;
  if ( (int)m_size > 0 )
  {
    m_quad = aabbOut->m_max.m_quad;
    v7 = 0i64;
    do
    {
      m_data = this->m_modelPose.m_data;
      aabbOut->m_min.m_quad = _mm_min_ps(aabbOut->m_min.m_quad, m_data[v7++].m_translation.m_quad);
      m_quad = _mm_max_ps(m_quad, m_data[v7 - 1].m_translation.m_quad);
      aabbOut->m_max.m_quad = m_quad;
      --v5;
    }
    while ( v5 );
  }
}

// File Line: 582
// RVA: 0xB1C4C0
hkBool *__fastcall hkaPose::checkInternalFlagIsClear(hkaPose *this, hkBool *result, unsigned int flag)
{
  result->m_bool = 1;
  return result;
}

