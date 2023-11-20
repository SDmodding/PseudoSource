// File Line: 23
// RVA: 0xB1ACF0
void __fastcall hkaPose::hkaPose(hkaPose *this, hkaPose::PoseSpace space, hkaSkeleton *skeleton, hkArrayBase<hkQsTransformf> *pose)
{
  this->m_skeleton = skeleton;
  this->m_localPose.m_capacityAndFlags = 2147483648;
  this->m_localPose.m_data = 0i64;
  this->m_localPose.m_size = 0;
  this->m_modelPose.m_data = 0i64;
  this->m_modelPose.m_size = 0;
  this->m_modelPose.m_capacityAndFlags = 2147483648;
  this->m_boneFlags.m_data = 0i64;
  this->m_boneFlags.m_size = 0;
  this->m_boneFlags.m_capacityAndFlags = 2147483648;
  this->m_floatSlotValues.m_data = 0i64;
  this->m_floatSlotValues.m_size = 0;
  this->m_floatSlotValues.m_capacityAndFlags = 2147483648;
  hkaPose::init(this, space, skeleton, pose);
}

// File Line: 30
// RVA: 0xB1AD50
void __fastcall hkaPose::hkaPose(hkaPose *this, hkaPose::PoseSpace space, hkaSkeleton *skeleton, hkQsTransformf *pose, int numBones)
{
  hkArrayBase<hkQsTransformf> posea; // [rsp+20h] [rbp-18h]

  this->m_skeleton = skeleton;
  this->m_localPose.m_capacityAndFlags = 2147483648;
  this->m_localPose.m_data = 0i64;
  this->m_localPose.m_size = 0;
  this->m_modelPose.m_data = 0i64;
  this->m_modelPose.m_size = 0;
  this->m_modelPose.m_capacityAndFlags = 2147483648;
  this->m_boneFlags.m_data = 0i64;
  this->m_boneFlags.m_size = 0;
  this->m_boneFlags.m_capacityAndFlags = 2147483648;
  this->m_floatSlotValues.m_data = 0i64;
  this->m_floatSlotValues.m_size = 0;
  posea.m_data = pose;
  posea.m_size = numBones;
  this->m_floatSlotValues.m_capacityAndFlags = 2147483648;
  posea.m_capacityAndFlags = numBones | 0x80000000;
  hkaPose::init(this, space, skeleton, &posea);
}

// File Line: 41
// RVA: 0xB1C0F0
void __fastcall hkaPose::init(hkaPose *this, hkaPose::PoseSpace space, hkaSkeleton *skeleton, hkArrayBase<hkQsTransformf> *pose)
{
  hkArrayBase<hkQsTransformf> *v4; // rbp
  hkaPose::PoseSpace v5; // er14
  int v6; // edi
  hkaPose *v7; // rsi
  int v8; // eax
  int v9; // eax
  int v10; // er9
  int v11; // eax
  int v12; // eax
  int v13; // er9
  int v14; // eax
  int v15; // eax
  int v16; // er9
  hkArray<float,hkContainerHeapAllocator> *v17; // rbx
  int v18; // er9
  int v19; // esi
  int v20; // eax
  int v21; // eax
  int v22; // er9
  int v23; // edx
  float *v24; // rdi
  __int64 v25; // rcx
  hkResult result; // [rsp+58h] [rbp+10h]

  v4 = pose;
  v5 = space;
  v6 = this->m_skeleton->m_bones.m_size;
  v7 = this;
  v8 = this->m_modelPose.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v8 < v6 )
  {
    v9 = 2 * v8;
    v10 = this->m_skeleton->m_bones.m_size;
    if ( v6 < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &this->m_modelPose,
      v10,
      48);
  }
  v7->m_modelPose.m_size = v6;
  v11 = v7->m_localPose.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v11 < v6 )
  {
    v12 = 2 * v11;
    v13 = v6;
    if ( v6 < v12 )
      v13 = v12;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v7->m_localPose,
      v13,
      48);
  }
  v7->m_localPose.m_size = v6;
  v14 = v7->m_boneFlags.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v14 < v6 )
  {
    v15 = 2 * v14;
    v16 = v6;
    if ( v6 < v15 )
      v16 = v15;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v7->m_boneFlags,
      v16,
      4);
  }
  v7->m_boneFlags.m_size = v6;
  if ( v5 == 1 )
    hkaPose::setPoseLocalSpace(v7, v4);
  else
    hkaPose::setPoseModelSpace(v7, v4);
  v17 = &v7->m_floatSlotValues;
  v18 = (v7->m_skeleton->m_floatSlots.m_size + 3) & 0xFFFFFFFC;
  if ( (v7->m_floatSlotValues.m_capacityAndFlags & 0x3FFFFFFF) < v18 )
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v7->m_floatSlotValues,
      v18,
      4);
  v19 = v7->m_skeleton->m_floatSlots.m_size;
  v20 = v17->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v20 < v19 )
  {
    v21 = 2 * v20;
    v22 = v19;
    if ( v19 < v21 )
      v22 = v21;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v17, v22, 4);
  }
  v23 = v19 - v17->m_size;
  v24 = &v17->m_data[v17->m_size];
  v25 = v23;
  if ( v23 > 0 )
  {
    while ( v25 )
    {
      *v24 = 0.0;
      ++v24;
      --v25;
    }
  }
  v17->m_size = v19;
}

// File Line: 66
// RVA: 0xB1C480
void __fastcall hkaPose::setNonInitializedFlags(hkaPose *this)
{
  __int64 v1; // rdx
  __int64 v2; // r8

  v1 = 0i64;
  v2 = this->m_skeleton->m_bones.m_size;
  if ( v2 <= 0 )
  {
    *(_WORD *)&this->m_modelInSync.m_bool = 0;
  }
  else
  {
    do
      this->m_boneFlags.m_data[++v1 - 1] = 3;
    while ( v1 < v2 );
    *(_WORD *)&this->m_modelInSync.m_bool = 0;
  }
}

// File Line: 78
// RVA: 0xB1C280
hkQsTransformf *__fastcall hkaPose::calculateBoneModelSpace(hkaPose *this, int theBoneIdx)
{
  unsigned int *v2; // r9
  int v3; // er11
  hkaPose *v4; // r10
  signed __int64 v5; // rbx
  __int64 v6; // r8
  __int16 v7; // ax
  hkQsTransformf *v8; // rdx
  hkQsTransformf *v9; // rax
  signed __int64 v10; // rcx
  signed __int64 v11; // rax
  signed __int64 v12; // r11
  hkQsTransformf *v13; // r8
  __m128 *v14; // r9
  __m128 *v15; // rdx
  __m128 v16; // xmm2
  __m128 v17; // xmm1
  __m128 v18; // xmm6
  __m128 v19; // xmm5
  __m128 v20; // xmm4
  __m128 v21; // xmm6
  __m128 v22; // xmm2
  __m128 v23; // xmm4
  __m128 v24; // xmm0
  __m128 v25; // xmm5
  __m128 v26; // xmm3
  __m128 v27; // xmm6
  __m128 v28; // xmm3
  __m128 v29; // xmm3

  v2 = this->m_boneFlags.m_data;
  v3 = theBoneIdx;
  v4 = this;
  v5 = theBoneIdx;
  if ( v2[theBoneIdx] & 2 )
  {
    v6 = theBoneIdx;
    while ( 1 )
    {
      v7 = this->m_skeleton->m_parentIndices.m_data[v6];
      if ( v7 == -1 )
        break;
      v2[v6] |= 8u;
      v2 = this->m_boneFlags.m_data;
      v3 = v7;
      v6 = v7;
      if ( !(v2[v7] & 2) )
        goto LABEL_7;
    }
    v8 = this->m_localPose.m_data;
    v9 = this->m_modelPose.m_data;
    v10 = v3;
    v9[v10].m_translation = v8[v3].m_translation;
    v9[v10].m_rotation = v8[v3].m_rotation;
    v9[v10].m_scale = v8[v3].m_scale;
    v4->m_boneFlags.m_data[v3] &= 0xFFFFFFFD;
  }
LABEL_7:
  v11 = v3 + 1;
  if ( v11 <= v5 )
  {
    v12 = v11;
    do
    {
      if ( v4->m_boneFlags.m_data[v11] & 8 )
      {
        v13 = v4->m_modelPose.m_data;
        v14 = &v4->m_localPose.m_data[v12].m_translation.m_quad;
        v15 = &v13[v4->m_skeleton->m_parentIndices.m_data[v11]].m_translation.m_quad;
        v16 = v15[1];
        v17 = _mm_mul_ps(*v14, v16);
        v18 = _mm_shuffle_ps(v15[1], v16, 255);
        v19 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(*v14, *v14, 201), v16),
                _mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), *v14));
        v20 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
                      _mm_shuffle_ps(v17, v17, 170)),
                    v16),
                  _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v18, v18), (__m128)xmmword_141A711B0), *v14)),
                _mm_mul_ps(_mm_shuffle_ps(v19, v19, 201), v18));
        v13[v12].m_translation.m_quad = _mm_add_ps(_mm_add_ps(v20, v20), *v15);
        v21 = v15[1];
        v22 = v14[1];
        v23 = _mm_shuffle_ps(v15[1], v15[1], 255);
        v24 = _mm_mul_ps(_mm_shuffle_ps(v21, v21, 201), v22);
        v25 = _mm_shuffle_ps(v14[1], v14[1], 255);
        v26 = _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v21);
        v27 = _mm_mul_ps(v21, v22);
        v28 = _mm_sub_ps(v26, v24);
        v29 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v28, v28, 201), _mm_mul_ps(v14[1], v23)), _mm_mul_ps(v15[1], v25));
        v13[v12].m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                             v29,
                                             _mm_unpackhi_ps(
                                               v29,
                                               _mm_sub_ps(
                                                 _mm_mul_ps(v25, v23),
                                                 _mm_add_ps(
                                                   _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)),
                                                   _mm_shuffle_ps(v27, v27, 170)))),
                                             196);
        v13[v12].m_scale.m_quad = _mm_mul_ps(v15[2], v14[2]);
        v4->m_boneFlags.m_data[v11] &= 0xFFFFFFF5;
      }
      ++v11;
      ++v12;
    }
    while ( v11 <= v5 );
  }
  return &v4->m_modelPose.m_data[v5];
}

// File Line: 147
// RVA: 0xB1ADD0
hkArray<hkQsTransformf,hkContainerHeapAllocator> *__fastcall hkaPose::getSyncedPoseLocalSpace(hkaPose *this)
{
  hkaPose *v1; // rbx

  v1 = this;
  hkaPose::syncLocalSpace(this);
  return &v1->m_localPose;
}

// File Line: 156
// RVA: 0xB1AF50
void __fastcall hkaPose::syncLocalSpace(hkaPose *this)
{
  hkaPose *v1; // r14
  __int64 v2; // r13
  __int64 v3; // rbp
  __int64 v4; // rsi
  unsigned int *v5; // rdx
  hkQsTransformf *v6; // r12
  __int16 v7; // ax
  hkQsTransformf *v8; // r15
  hkQsTransformf *v9; // rdi
  __m128 v10; // xmm3
  __m128i v11; // xmm0
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
  hkVector4f v31; // [rsp+20h] [rbp-98h]

  v1 = this;
  if ( !this->m_localInSync.m_bool )
  {
    v2 = this->m_skeleton->m_bones.m_size;
    v3 = 0i64;
    if ( v2 > 0 )
    {
      v4 = 0i64;
      do
      {
        v5 = v1->m_boneFlags.m_data;
        if ( v5[v3] & 1 )
        {
          v6 = v1->m_modelPose.m_data;
          v7 = v1->m_skeleton->m_parentIndices.m_data[v3];
          if ( v7 == -1 )
          {
            v30 = v1->m_localPose.m_data;
            v30[v4].m_translation = v6[v4].m_translation;
            v30[v4].m_rotation = v6[v4].m_rotation;
            v30[v4].m_scale = v6[v4].m_scale;
          }
          else
          {
            if ( v5[v7] & 2 )
              v8 = hkaPose::calculateBoneModelSpace(v1, v7);
            else
              v8 = &v6[v7];
            v9 = v1->m_localPose.m_data;
            hkVector4f::setRotatedInverseDir(&v31, &v8->m_rotation, &v8->m_translation);
            v10 = v6[v4].m_translation.m_quad;
            v11 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
            v12 = (__m128)_mm_shuffle_epi32(v11, 0);
            v13 = (__m128)_mm_shuffle_epi32(v11, 64);
            v14 = v8->m_scale.m_quad;
            v15 = _mm_xor_ps(v13, v8->m_rotation.m_vec.m_quad);
            v16 = _mm_rcp_ps(v14);
            v17 = _mm_shuffle_ps(v15, v15, 255);
            v18 = _mm_shuffle_ps(v15, v15, 201);
            v19 = _mm_slli_si128((__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v14, v16)), v16), 4);
            v20 = _mm_mul_ps(v6[v4].m_translation.m_quad, v15);
            v21 = _mm_sub_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v15),
                    _mm_mul_ps(v6[v4].m_translation.m_quad, v18));
            v22 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
                          _mm_shuffle_ps(v20, v20, 170)),
                        v15),
                      _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v17, v17), (__m128)xmmword_141A711B0), v10)),
                    _mm_mul_ps(_mm_shuffle_ps(v21, v21, 201), v17));
            v9[v4].m_translation.m_quad = _mm_add_ps(_mm_add_ps(v22, v22), _mm_xor_ps(v12, v31.m_quad));
            v23 = v6[v4].m_rotation.m_vec.m_quad;
            v24 = _mm_shuffle_ps(v6[v4].m_rotation.m_vec.m_quad, v6[v4].m_rotation.m_vec.m_quad, 255);
            v25 = _mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), v15);
            v26 = _mm_mul_ps(v15, v24);
            v27 = _mm_mul_ps(v15, v23);
            v28 = _mm_sub_ps(v25, _mm_mul_ps(v6[v4].m_rotation.m_vec.m_quad, v18));
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
          v1->m_boneFlags.m_data[v3] &= 0xFFFFFFFE;
        }
        ++v3;
        ++v4;
      }
      while ( v3 < v2 );
    }
    v1->m_localInSync.m_bool = 1;
  }
}

// File Line: 193
// RVA: 0xB1ADF0
hkArray<hkQsTransformf,hkContainerHeapAllocator> *__fastcall hkaPose::getSyncedPoseModelSpace(hkaPose *this)
{
  hkaPose *v1; // rbx

  v1 = this;
  hkaPose::syncModelSpace(this);
  return &v1->m_modelPose;
}

// File Line: 202
// RVA: 0xB1B1F0
void __fastcall hkaPose::syncModelSpace(hkaPose *this)
{
  __int64 v1; // r9
  __int64 v2; // rbx
  __int64 v3; // r10
  hkQsTransformf *v4; // r11
  __int16 v5; // ax
  hkQsTransformf *v6; // rdx
  __m128 *v7; // r8
  __m128 v8; // xmm2
  __m128 v9; // xmm1
  __m128 v10; // xmm6
  __m128 v11; // xmm5
  __m128 v12; // xmm4
  __m128 v13; // xmm6
  __m128 v14; // xmm2
  __m128 v15; // xmm4
  __m128 v16; // xmm0
  __m128 v17; // xmm5
  __m128 v18; // xmm3
  __m128 v19; // xmm6
  __m128 v20; // xmm3
  __m128 v21; // xmm3
  hkQsTransformf *v22; // rax

  if ( !this->m_modelInSync.m_bool )
  {
    v1 = 0i64;
    v2 = this->m_skeleton->m_bones.m_size;
    if ( v2 > 0 )
    {
      v3 = 0i64;
      do
      {
        if ( this->m_boneFlags.m_data[v1] & 2 )
        {
          v4 = &this->m_localPose.m_data[v3];
          v5 = this->m_skeleton->m_parentIndices.m_data[v1];
          if ( v5 == -1 )
          {
            v22 = this->m_modelPose.m_data;
            v22[v3].m_translation = v4->m_translation;
            v22[v3].m_rotation = v4->m_rotation;
            v22[v3].m_scale = v4->m_scale;
          }
          else
          {
            v6 = this->m_modelPose.m_data;
            v7 = &v6[v5].m_translation.m_quad;
            v8 = v7[1];
            v9 = _mm_mul_ps(v7[1], v4->m_translation.m_quad);
            v10 = _mm_shuffle_ps(v7[1], v8, 255);
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
            v6[v3].m_translation.m_quad = _mm_add_ps(_mm_add_ps(v12, v12), *v7);
            v13 = v7[1];
            v14 = v4->m_rotation.m_vec.m_quad;
            v15 = _mm_shuffle_ps(v7[1], v7[1], 255);
            v16 = _mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), v14);
            v17 = _mm_shuffle_ps(v4->m_rotation.m_vec.m_quad, v4->m_rotation.m_vec.m_quad, 255);
            v18 = _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v13);
            v19 = _mm_mul_ps(v13, v14);
            v20 = _mm_sub_ps(v18, v16);
            v21 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v20, v20, 201), _mm_mul_ps(v4->m_rotation.m_vec.m_quad, v15)),
                    _mm_mul_ps(v7[1], v17));
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
            v6[v3].m_scale.m_quad = _mm_mul_ps(v7[2], v4->m_scale.m_quad);
          }
          this->m_boneFlags.m_data[v1] &= 0xFFFFFFFD;
        }
        ++v1;
        ++v3;
      }
      while ( v1 < v2 );
    }
    this->m_modelInSync.m_bool = 1;
  }
}

// File Line: 242
// RVA: 0xB1AE10
void __fastcall hkaPose::setPoseLocalSpace(hkaPose *this, hkArrayBase<hkQsTransformf> *poseLocal)
{
  hkQsTransformf *v2; // r9
  hkQsTransformf *v3; // r10
  __int64 v4; // rdi
  __int64 v5; // rbx
  int v6; // edx
  int v7; // er8
  int v8; // eax
  __int64 i; // rax

  v2 = poseLocal->m_data;
  v3 = this->m_localPose.m_data;
  v4 = this->m_skeleton->m_bones.m_size;
  if ( 3 * (signed int)v4 > 0 )
  {
    v5 = (unsigned int)(3 * v4);
    do
    {
      v6 = v2->m_translation.m_quad.m128_i32[2];
      v7 = v2->m_translation.m_quad.m128_i32[3];
      v8 = v2->m_translation.m_quad.m128_i32[0];
      v3->m_translation.m_quad.m128_i32[1] = v2->m_translation.m_quad.m128_i32[1];
      v3->m_translation.m_quad.m128_i32[2] = v6;
      v3->m_translation.m_quad.m128_i32[3] = v7;
      v3->m_translation.m_quad.m128_i32[0] = v8;
      v3 = (hkQsTransformf *)((char *)v3 + 16);
      v2 = (hkQsTransformf *)((char *)v2 + 16);
      --v5;
    }
    while ( v5 );
  }
  for ( i = 0i64; i < v4; this->m_boneFlags.m_data[i - 1] = 2 )
    ++i;
  *(_WORD *)&this->m_modelInSync.m_bool = 256;
}

// File Line: 262
// RVA: 0xB1AEB0
void __fastcall hkaPose::setPoseModelSpace(hkaPose *this, hkArrayBase<hkQsTransformf> *poseModel)
{
  hkQsTransformf *v2; // r9
  hkQsTransformf *v3; // r10
  __int64 v4; // rdi
  __int64 v5; // rbx
  int v6; // edx
  int v7; // er8
  int v8; // eax
  __int64 i; // rax

  v2 = poseModel->m_data;
  v3 = this->m_modelPose.m_data;
  v4 = this->m_skeleton->m_bones.m_size;
  if ( 3 * (signed int)v4 > 0 )
  {
    v5 = (unsigned int)(3 * v4);
    do
    {
      v6 = v2->m_translation.m_quad.m128_i32[2];
      v7 = v2->m_translation.m_quad.m128_i32[3];
      v8 = v2->m_translation.m_quad.m128_i32[0];
      v3->m_translation.m_quad.m128_i32[1] = v2->m_translation.m_quad.m128_i32[1];
      v3->m_translation.m_quad.m128_i32[2] = v6;
      v3->m_translation.m_quad.m128_i32[3] = v7;
      v3->m_translation.m_quad.m128_i32[0] = v8;
      v3 = (hkQsTransformf *)((char *)v3 + 16);
      v2 = (hkQsTransformf *)((char *)v2 + 16);
      --v5;
    }
    while ( v5 );
  }
  for ( i = 0i64; i < v4; this->m_boneFlags.m_data[i - 1] = 1 )
    ++i;
  *(_WORD *)&this->m_modelInSync.m_bool = 1;
}

// File Line: 284
// RVA: 0xB1B3B0
hkQsTransformf *__fastcall hkaPose::accessBoneLocalSpace(hkaPose *this, int boneIdx)
{
  __int64 v2; // r13
  hkaPose *v3; // rsi
  __int64 v4; // r8
  int v5; // eax
  __int64 v6; // r14
  signed __int64 v7; // rbp
  __int64 v8; // rdx
  unsigned int *v9; // rcx
  hkQsTransformf *v10; // r12
  hkQsTransformf *v11; // r15
  hkQsTransformf *v12; // rdi
  __m128 v13; // xmm3
  __m128i v14; // xmm0
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
  hkQsTransformf *v33; // rax
  __int64 i; // rcx
  unsigned int *v35; // rdx
  unsigned int v36; // eax
  unsigned int *v37; // rdx
  hkQsTransformf *v38; // r15
  __int16 v39; // ax
  hkQsTransformf *v40; // r14
  hkQsTransformf *v41; // rdi
  __m128 v42; // xmm3
  __m128 v43; // xmm2
  __m128i v44; // xmm0
  __m128 v45; // xmm8
  __m128 v46; // xmm9
  __m128 v47; // xmm1
  __m128 v48; // xmm7
  __m128 v49; // xmm5
  __m128 v50; // xmm4
  __m128 v51; // xmm2
  __m128 v52; // xmm2
  __m128 v53; // xmm3
  __m128 v54; // xmm4
  __m128 v55; // xmm1
  __m128 v56; // xmm8
  __m128 v57; // xmm4
  __m128 v58; // xmm4
  hkQsTransformf *v59; // rax
  hkVector4f v61; // [rsp+20h] [rbp-A8h]
  __int64 v62; // [rsp+D0h] [rbp+8h]
  int v63; // [rsp+D8h] [rbp+10h]

  v2 = boneIdx;
  v3 = this;
  v4 = this->m_skeleton->m_bones.m_size;
  this->m_boneFlags.m_data[v2] |= 4u;
  v5 = boneIdx + 1;
  v62 = v4;
  v6 = boneIdx + 1;
  v63 = boneIdx + 1;
  if ( v6 < v4 )
  {
    v7 = v5;
    do
    {
      LOWORD(v8) = v3->m_skeleton->m_parentIndices.m_data[v6];
      if ( (_WORD)v8 != -1 )
      {
        v9 = v3->m_boneFlags.m_data;
        if ( v9[(signed __int16)v8] & 4 )
        {
          if ( v9[v6] & 1 )
          {
            v10 = v3->m_modelPose.m_data;
            if ( (_WORD)v8 == -1 )
            {
              v33 = v3->m_localPose.m_data;
              v33[v7].m_translation = v10[v7].m_translation;
              v33[v7].m_rotation = v10[v7].m_rotation;
              v33[v7].m_scale = v10[v7].m_scale;
            }
            else
            {
              v8 = (signed __int16)v8;
              if ( v9[(signed __int16)v8] & 2 )
                v11 = hkaPose::calculateBoneModelSpace(v3, v8);
              else
                v11 = &v10[v8];
              v12 = v3->m_localPose.m_data;
              hkVector4f::setRotatedInverseDir(&v61, &v11->m_rotation, &v11->m_translation);
              v13 = v10[v7].m_translation.m_quad;
              v14 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
              v15 = (__m128)_mm_shuffle_epi32(v14, 0);
              v16 = (__m128)_mm_shuffle_epi32(v14, 64);
              v17 = v11->m_scale.m_quad;
              v18 = _mm_xor_ps(v16, v11->m_rotation.m_vec.m_quad);
              v19 = _mm_rcp_ps(v17);
              v20 = _mm_shuffle_ps(v18, v18, 255);
              v21 = _mm_shuffle_ps(v18, v18, 201);
              v22 = _mm_slli_si128((__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v17, v19)), v19), 4);
              v23 = _mm_mul_ps(v18, v13);
              v24 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), v18), _mm_mul_ps(v21, v13));
              v25 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_add_ps(
                            _mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)),
                            _mm_shuffle_ps(v23, v23, 170)),
                          v18),
                        _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v20, v20), (__m128)xmmword_141A711B0), v13)),
                      _mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), v20));
              v12[v7].m_translation.m_quad = _mm_add_ps(_mm_add_ps(v25, v25), _mm_xor_ps(v15, v61.m_quad));
              v26 = v10[v7].m_rotation.m_vec.m_quad;
              v27 = _mm_shuffle_ps(v10[v7].m_rotation.m_vec.m_quad, v10[v7].m_rotation.m_vec.m_quad, 255);
              v28 = _mm_mul_ps(_mm_shuffle_ps(v10[v7].m_rotation.m_vec.m_quad, v26, 201), v18);
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
              v4 = v62;
              v12[v7].m_scale.m_quad = _mm_mul_ps(v10[v7].m_scale.m_quad, (__m128)_mm_srli_si128(v22, 4));
            }
            v3->m_boneFlags.m_data[v6] &= 0xFFFFFFFE;
          }
          v3->m_boneFlags.m_data[v6] |= 4u;
          v3->m_modelInSync.m_bool = 0;
        }
      }
      ++v6;
      ++v7;
    }
    while ( v6 < v4 );
    v5 = v63;
  }
  for ( i = v5; i < v4; ++i )
  {
    v35 = v3->m_boneFlags.m_data;
    v36 = v35[i];
    if ( v36 & 4 )
      v35[i] = v36 & 0xFFFFFFFB | 2;
  }
  v37 = v3->m_boneFlags.m_data;
  if ( v37[v2] & 1 )
  {
    v38 = v3->m_modelPose.m_data;
    v39 = v3->m_skeleton->m_parentIndices.m_data[v2];
    if ( v39 == -1 )
    {
      v59 = v3->m_localPose.m_data;
      v59[v2].m_translation = v38[v2].m_translation;
      v59[v2].m_rotation = v38[v2].m_rotation;
      v59[v2].m_scale = v38[v2].m_scale;
    }
    else
    {
      if ( v37[v39] & 2 )
        v40 = hkaPose::calculateBoneModelSpace(v3, v39);
      else
        v40 = &v38[v39];
      v41 = v3->m_localPose.m_data;
      hkVector4f::setRotatedInverseDir(&v61, &v40->m_rotation, &v40->m_translation);
      v42 = v38[v2].m_translation.m_quad;
      v43 = _mm_rcp_ps(v40->m_scale.m_quad);
      v44 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
      v45 = _mm_xor_ps((__m128)_mm_shuffle_epi32(v44, 64), v40->m_rotation.m_vec.m_quad);
      v46 = (__m128)_mm_srli_si128(
                      _mm_slli_si128(
                        (__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v43, v40->m_scale.m_quad)), v43),
                        4),
                      4);
      v47 = _mm_mul_ps(v38[v2].m_translation.m_quad, v45);
      v48 = _mm_shuffle_ps(v45, v45, 255);
      v49 = _mm_shuffle_ps(v45, v45, 201);
      v50 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v42, v42, 201), v45), _mm_mul_ps(v38[v2].m_translation.m_quad, v49));
      v51 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v47, v47, 85), _mm_shuffle_ps(v47, v47, 0)),
                    _mm_shuffle_ps(v47, v47, 170)),
                  v45),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v48, v48), (__m128)xmmword_141A711B0), v42)),
              _mm_mul_ps(_mm_shuffle_ps(v50, v50, 201), v48));
      v41[v2].m_translation.m_quad = _mm_add_ps(
                                       _mm_add_ps(v51, v51),
                                       _mm_xor_ps((__m128)_mm_shuffle_epi32(v44, 0), v61.m_quad));
      v52 = v38[v2].m_rotation.m_vec.m_quad;
      v53 = _mm_shuffle_ps(v38[v2].m_rotation.m_vec.m_quad, v38[v2].m_rotation.m_vec.m_quad, 255);
      v54 = _mm_mul_ps(_mm_shuffle_ps(v52, v52, 201), v45);
      v55 = _mm_mul_ps(v45, v53);
      v56 = _mm_mul_ps(v45, v52);
      v57 = _mm_sub_ps(v54, _mm_mul_ps(v38[v2].m_rotation.m_vec.m_quad, v49));
      v58 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v57, v57, 201), _mm_mul_ps(v38[v2].m_rotation.m_vec.m_quad, v48)), v55);
      v41[v2].m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                          v58,
                                          _mm_unpackhi_ps(
                                            v58,
                                            _mm_sub_ps(
                                              _mm_mul_ps(v53, v48),
                                              _mm_add_ps(
                                                _mm_add_ps(_mm_shuffle_ps(v56, v56, 85), _mm_shuffle_ps(v56, v56, 0)),
                                                _mm_shuffle_ps(v56, v56, 170)))),
                                          196);
      v41[v2].m_scale.m_quad = _mm_mul_ps(v38[v2].m_scale.m_quad, v46);
    }
    v3->m_boneFlags.m_data[v2] &= 0xFFFFFFFE;
  }
  v3->m_boneFlags.m_data[v2] = 2;
  v3->m_modelInSync.m_bool = 0;
  return &v3->m_localPose.m_data[v2];
}

// File Line: 300
// RVA: 0xB1B8A0
hkQsTransformf *__fastcall hkaPose::accessBoneModelSpace(hkaPose *this, int boneIdx, hkaPose::PropagateOrNot propagateOrNot)
{
  hkaSkeleton *v3; // rax
  __int64 v4; // r9
  hkaPose *v5; // rsi
  __int64 v6; // rbp
  int v7; // edi
  __int64 j; // rbx
  __int64 v9; // rdx
  int v10; // eax
  __int64 v11; // r14
  __int64 v12; // r13
  signed __int64 v13; // rbp
  __int64 v14; // rdx
  unsigned int *v15; // rcx
  hkQsTransformf *v16; // r12
  hkQsTransformf *v17; // r15
  hkQsTransformf *v18; // rdi
  __m128 v19; // xmm3
  __m128i v20; // xmm0
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
  hkQsTransformf *v39; // rax
  __int64 i; // rcx
  unsigned int *v41; // rdx
  unsigned int v42; // eax
  __int64 v43; // rbx
  hkVector4f v45; // [rsp+20h] [rbp-A8h]
  int v46; // [rsp+D8h] [rbp+10h]
  int v47; // [rsp+E0h] [rbp+18h]

  v46 = boneIdx;
  v3 = this->m_skeleton;
  v4 = boneIdx;
  v5 = this;
  if ( propagateOrNot )
  {
    v9 = v3->m_bones.m_size;
    this->m_boneFlags.m_data[v4] |= 4u;
    v10 = v4 + 1;
    v11 = (signed int)v4 + 1;
    v47 = v4 + 1;
    v12 = v9;
    if ( v11 < v9 )
    {
      v13 = v10;
      do
      {
        LOWORD(v14) = v5->m_skeleton->m_parentIndices.m_data[v11];
        if ( (_WORD)v14 != -1 )
        {
          v15 = v5->m_boneFlags.m_data;
          if ( v15[(signed __int16)v14] & 4 )
          {
            if ( v15[v11] & 1 )
            {
              v16 = v5->m_modelPose.m_data;
              if ( (_WORD)v14 == -1 )
              {
                v39 = v5->m_localPose.m_data;
                v39[v13].m_translation = v16[v13].m_translation;
                v39[v13].m_rotation = v16[v13].m_rotation;
                v39[v13].m_scale = v16[v13].m_scale;
              }
              else
              {
                v14 = (signed __int16)v14;
                if ( v15[(signed __int16)v14] & 2 )
                  v17 = hkaPose::calculateBoneModelSpace(v5, v14);
                else
                  v17 = &v16[v14];
                v18 = v5->m_localPose.m_data;
                hkVector4f::setRotatedInverseDir(&v45, &v17->m_rotation, &v17->m_translation);
                v19 = v16[v13].m_translation.m_quad;
                v20 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
                v21 = (__m128)_mm_shuffle_epi32(v20, 0);
                v22 = (__m128)_mm_shuffle_epi32(v20, 64);
                v23 = v17->m_scale.m_quad;
                v24 = _mm_xor_ps(v22, v17->m_rotation.m_vec.m_quad);
                v25 = _mm_rcp_ps(v23);
                v26 = _mm_shuffle_ps(v24, v24, 255);
                v27 = _mm_shuffle_ps(v24, v24, 201);
                v28 = _mm_slli_si128((__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v23, v25)), v25), 4);
                v29 = _mm_mul_ps(v24, v19);
                v30 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v19, v19, 201), v24), _mm_mul_ps(v27, v19));
                v31 = _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(
                            _mm_add_ps(
                              _mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)),
                              _mm_shuffle_ps(v29, v29, 170)),
                            v24),
                          _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v26, v26), (__m128)xmmword_141A711B0), v19)),
                        _mm_mul_ps(_mm_shuffle_ps(v30, v30, 201), v26));
                v18[v13].m_translation.m_quad = _mm_add_ps(_mm_add_ps(v31, v31), _mm_xor_ps(v21, v45.m_quad));
                v32 = v16[v13].m_rotation.m_vec.m_quad;
                v33 = _mm_shuffle_ps(v16[v13].m_rotation.m_vec.m_quad, v16[v13].m_rotation.m_vec.m_quad, 255);
                v34 = _mm_mul_ps(_mm_shuffle_ps(v16[v13].m_rotation.m_vec.m_quad, v32, 201), v24);
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
              }
              v5->m_boneFlags.m_data[v11] &= 0xFFFFFFFE;
            }
            v5->m_boneFlags.m_data[v11] |= 4u;
            v5->m_modelInSync.m_bool = 0;
          }
        }
        ++v11;
        ++v13;
      }
      while ( v11 < v12 );
      LODWORD(v4) = v46;
      v10 = v47;
    }
    for ( i = v10; i < v12; ++i )
    {
      v41 = v5->m_boneFlags.m_data;
      v42 = v41[i];
      if ( v42 & 4 )
        v41[i] = v42 & 0xFFFFFFFB | 2;
    }
  }
  else
  {
    v6 = v3->m_bones.m_size;
    v7 = boneIdx + 1;
    for ( j = boneIdx + 1; j < v6; ++v7 )
    {
      if ( v5->m_skeleton->m_parentIndices.m_data[j] == (_DWORD)v4 )
      {
        if ( v5->m_boneFlags.m_data[j] & 2 )
        {
          hkaPose::calculateBoneModelSpace(v5, v7);
          LODWORD(v4) = v46;
        }
        v5->m_boneFlags.m_data[j] = 1;
        v5->m_localInSync.m_bool = 0;
      }
      ++j;
    }
  }
  v43 = (signed int)v4;
  if ( v5->m_boneFlags.m_data[(signed int)v4] & 2 )
    hkaPose::calculateBoneModelSpace(v5, v4);
  v5->m_boneFlags.m_data[v43] = 1;
  v5->m_localInSync.m_bool = 0;
  return &v5->m_modelPose.m_data[v43];
}

// File Line: 326
// RVA: 0xB1BC60
hkArray<hkQsTransformf,hkContainerHeapAllocator> *__fastcall hkaPose::accessSyncedPoseLocalSpace(hkaPose *this)
{
  hkaPose *v1; // rbx

  v1 = this;
  hkaPose::syncLocalSpace(this);
  return hkaPose::accessUnsyncedPoseLocalSpace(v1);
}

// File Line: 334
// RVA: 0xB1BC90
hkArray<hkQsTransformf,hkContainerHeapAllocator> *__fastcall hkaPose::accessSyncedPoseModelSpace(hkaPose *this)
{
  hkaPose *v1; // rbx

  v1 = this;
  hkaPose::syncModelSpace(this);
  return hkaPose::accessUnsyncedPoseModelSpace(v1);
}

// File Line: 342
// RVA: 0xB1BCC0
hkArray<hkQsTransformf,hkContainerHeapAllocator> *__fastcall hkaPose::accessUnsyncedPoseLocalSpace(hkaPose *this)
{
  __int64 v1; // rax
  __int64 v2; // r8

  v1 = 0i64;
  v2 = this->m_skeleton->m_bones.m_size;
  if ( (signed int)v2 > 0 )
  {
    do
      this->m_boneFlags.m_data[++v1 - 1] = 2;
    while ( v1 < v2 );
  }
  *(_WORD *)&this->m_modelInSync.m_bool = 256;
  return &this->m_localPose;
}

// File Line: 358
// RVA: 0xB1BD00
hkArray<hkQsTransformf,hkContainerHeapAllocator> *__fastcall hkaPose::accessUnsyncedPoseModelSpace(hkaPose *this)
{
  __int64 v1; // rax
  __int64 v2; // r8

  v1 = 0i64;
  v2 = this->m_skeleton->m_bones.m_size;
  if ( (signed int)v2 > 0 )
  {
    do
      this->m_boneFlags.m_data[++v1 - 1] = 1;
    while ( v1 < v2 );
  }
  *(_WORD *)&this->m_modelInSync.m_bool = 1;
  return &this->m_modelPose;
}

// File Line: 376
// RVA: 0xB1C4D0
hkBool *__fastcall hkaPose::checkPoseValidity(hkaPose *this, hkBool *result)
{
  __int64 v2; // r8
  hkaPose *v3; // rbx
  __int64 v4; // r9
  __int64 v5; // r10
  unsigned int *v6; // rax
  unsigned int v7; // er11
  __int64 v8; // rax
  unsigned int *v9; // rcx
  unsigned int *v10; // rax
  hkBool *v11; // rax

  v2 = 0i64;
  v3 = this;
  v4 = this->m_skeleton->m_bones.m_size;
  v5 = 0i64;
  if ( v4 > 0 )
  {
    v6 = this->m_boneFlags.m_data;
    do
    {
      v7 = *v6;
      if ( *v6 & 1 )
      {
        if ( v7 & 2 )
          goto LABEL_17;
      }
      ++v5;
      ++v6;
    }
    while ( v5 < v4 );
  }
  if ( this->m_localInSync.m_bool )
  {
    v8 = 0i64;
    if ( v4 > 0 )
    {
      v9 = this->m_boneFlags.m_data;
      while ( !(*(_BYTE *)v9 & 1) )
      {
        ++v8;
        ++v9;
        if ( v8 >= v4 )
          goto LABEL_11;
      }
LABEL_17:
      result->m_bool = 0;
      return result;
    }
  }
LABEL_11:
  if ( v3->m_modelInSync.m_bool && v4 > 0 )
  {
    v10 = v3->m_boneFlags.m_data;
    while ( !(*(_BYTE *)v10 & 2) )
    {
      ++v2;
      ++v10;
      if ( v2 >= v4 )
        goto LABEL_16;
    }
    result->m_bool = 0;
    v11 = result;
  }
  else
  {
LABEL_16:
    result->m_bool = 1;
    v11 = result;
  }
  return v11;
}

// File Line: 422
// RVA: 0xB1C580
hkBool *__fastcall hkaPose::checkPoseTransformsValidity(hkaPose *this, hkBool *result)
{
  int v2; // edi
  __int64 v3; // rbp
  hkBool *v4; // rsi
  hkaPose *v5; // r14
  __int64 v6; // rbx
  unsigned int v7; // ecx

  v2 = 0;
  v3 = this->m_skeleton->m_bones.m_size;
  v4 = result;
  v5 = this;
  v6 = 0i64;
  if ( v3 <= 0 )
  {
LABEL_9:
    v4->m_bool = 1;
  }
  else
  {
    while ( 1 )
    {
      v7 = v5->m_boneFlags.m_data[v6];
      if ( v5->m_boneFlags.m_data[v6] & 2 )
      {
        if ( v7 & 1 )
          break;
      }
      if ( !(v5->m_boneFlags.m_data[v6] & 2) && !hkQsTransformf::isOk(&v5->m_modelPose.m_data[v2], 0.001)
        || !(v5->m_boneFlags.m_data[v6] & 1) && !hkQsTransformf::isOk(&v5->m_localPose.m_data[v2], 0.001) )
      {
        break;
      }
      ++v6;
      ++v2;
      if ( v6 >= v3 )
        goto LABEL_9;
    }
    v4->m_bool = 0;
  }
  return v4;
}

// File Line: 452
// RVA: 0xB1BD40
void __fastcall hkaPose::setToReferencePose(hkaPose *this)
{
  hkQsTransformf *v1; // r10
  hkaPose *v2; // r11
  hkQsTransformf *v3; // r9
  int v4; // ecx
  __int64 v5; // rbx
  int v6; // ecx
  int v7; // er8
  int v8; // eax
  int v9; // ecx
  __int64 v10; // rdx
  hkaSkeleton *v11; // rdx
  int v12; // ecx
  float *v13; // rax

  v1 = this->m_localPose.m_data;
  v2 = this;
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
      v1->m_translation.m_quad.m128_i32[1] = v3->m_translation.m_quad.m128_i32[1];
      v1->m_translation.m_quad.m128_i32[2] = v6;
      v1->m_translation.m_quad.m128_i32[3] = v7;
      v1->m_translation.m_quad.m128_i32[0] = v8;
      v1 = (hkQsTransformf *)((char *)v1 + 16);
      v3 = (hkQsTransformf *)((char *)v3 + 16);
      --v5;
    }
    while ( v5 );
  }
  v9 = 0;
  if ( v2->m_skeleton->m_bones.m_size > 0 )
  {
    v10 = 0i64;
    do
    {
      ++v9;
      ++v10;
      v2->m_boneFlags.m_data[v10 - 1] = 2;
    }
    while ( v9 < v2->m_skeleton->m_bones.m_size );
  }
  *(_WORD *)&v2->m_modelInSync.m_bool = 256;
  v11 = v2->m_skeleton;
  v12 = 0;
  if ( v2->m_skeleton->m_floatSlots.m_size > 0 )
  {
    v13 = v2->m_floatSlotValues.m_data;
    do
    {
      *v13 = 0.0;
      ++v12;
      ++v13;
    }
    while ( v12 < v11->m_floatSlots.m_size );
  }
}

// File Line: 474
// RVA: 0xB1BE00
void __fastcall hkaPose::enforceSkeletonConstraintsLocalSpace(hkaPose *this)
{
  hkaPose *v1; // rbx
  __int64 v2; // rdi
  __int64 v3; // r8
  __int64 v4; // rdx
  __int64 v5; // r10
  __int64 v6; // r9
  hkaSkeleton *v7; // rcx
  __int16 v8; // cx
  unsigned int *v9; // r11
  __int64 v10; // rcx

  v1 = this;
  v2 = this->m_skeleton->m_bones.m_size;
  hkaPose::syncLocalSpace(this);
  v3 = 0i64;
  v4 = 0i64;
  if ( v2 > 0 )
  {
    v5 = 0i64;
    v6 = 0i64;
    do
    {
      v7 = v1->m_skeleton;
      if ( v1->m_skeleton->m_bones.m_data[v6].m_lockTranslation.m_bool )
      {
        v1->m_localPose.m_data[v5].m_translation = v7->m_referencePose.m_data[v5].m_translation;
        v1->m_boneFlags.m_data[v4] |= 2u;
      }
      else
      {
        v8 = v7->m_parentIndices.m_data[v4];
        if ( v8 == -1 )
          goto LABEL_9;
        v9 = v1->m_boneFlags.m_data;
        if ( !(v9[v8] & 4) )
          goto LABEL_9;
        v9[v4] |= 2u;
      }
      v1->m_boneFlags.m_data[v4] |= 4u;
LABEL_9:
      ++v4;
      ++v6;
      ++v5;
    }
    while ( v4 < v2 );
  }
  v10 = v1->m_boneFlags.m_size;
  if ( v10 > 0 )
  {
    do
      v1->m_boneFlags.m_data[++v3 - 1] &= 0xFFFFFFE3;
    while ( v3 < v10 );
  }
}

// File Line: 511
// RVA: 0xB1BED0
void __fastcall hkaPose::enforceSkeletonConstraintsModelSpace(hkaPose *this)
{
  __int64 v1; // rdi
  hkaPose *v2; // rbx
  __int64 v3; // r9
  __int64 v4; // rsi
  __int64 v5; // r8
  __int64 v6; // r10
  __int64 v7; // r11
  __int16 v8; // dx
  hkQsTransformf *v9; // rdi
  __m128 v10; // xmm4
  hkQsTransformf *v11; // rcx
  __m128 *v12; // rdx
  __m128 v13; // xmm2
  __m128 v14; // xmm1
  __m128 v15; // xmm6
  __m128 v16; // xmm5
  __m128 v17; // xmm3
  hkQsTransformf *v18; // rax
  __m128 v19; // xmm0
  unsigned int *v20; // rcx
  __int64 v21; // rcx

  v1 = this->m_skeleton->m_bones.m_size;
  v2 = this;
  hkaPose::syncModelSpace(this);
  v3 = 0i64;
  v4 = v1;
  v5 = 0i64;
  if ( (signed int)v1 > 0 )
  {
    v6 = 0i64;
    v7 = 0i64;
    do
    {
      v8 = v2->m_skeleton->m_parentIndices.m_data[v5];
      if ( v2->m_skeleton->m_bones.m_data[v7].m_lockTranslation.m_bool )
      {
        v9 = v2->m_skeleton->m_referencePose.m_data;
        if ( v8 == -1 )
        {
          v18 = v2->m_modelPose.m_data;
          v19 = v9[v6].m_translation.m_quad;
        }
        else
        {
          v10 = v9[v6].m_translation.m_quad;
          v11 = v2->m_modelPose.m_data;
          v12 = &v11[v8].m_translation.m_quad;
          v13 = v12[1];
          v14 = _mm_mul_ps(v12[1], v10);
          v15 = _mm_shuffle_ps(v12[1], v13, 255);
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
          v18 = v2->m_modelPose.m_data;
          v19 = _mm_add_ps(*v12, v18[v6].m_translation.m_quad);
        }
        v18[v6].m_translation.m_quad = v19;
        v2->m_boneFlags.m_data[v5] |= 1u;
        v2->m_boneFlags.m_data[v5] |= 4u;
      }
      else if ( v8 != -1 )
      {
        v20 = v2->m_boneFlags.m_data;
        if ( v20[v8] & 4 )
          v20[v5] |= 1u;
      }
      ++v5;
      ++v7;
      ++v6;
    }
    while ( v5 < v4 );
  }
  v21 = v2->m_boneFlags.m_size;
  if ( v21 > 0 )
  {
    do
      v2->m_boneFlags.m_data[++v3 - 1] &= 0xFFFFFFE3;
    while ( v3 < v21 );
  }
}

// File Line: 564
// RVA: 0xB1C050
void __fastcall hkaPose::getModelSpaceAabb(hkaPose *this, hkAabb *aabbOut)
{
  hkAabb *v2; // rbx
  hkaPose *v3; // rsi
  __int64 v4; // rdi
  __int64 v5; // rdx
  __m128 v6; // xmm1
  __int64 v7; // rcx
  hkQsTransformf *v8; // rax

  aabbOut->m_min = (hkVector4f)xmmword_141A712A0;
  v2 = aabbOut;
  v3 = this;
  aabbOut->m_max.m_quad = _mm_xor_ps(
                            (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                            aabbOut->m_min.m_quad);
  v4 = this->m_skeleton->m_bones.m_size;
  hkaPose::syncModelSpace(this);
  v5 = v4;
  if ( (signed int)v4 > 0 )
  {
    v6 = v2->m_max.m_quad;
    v7 = 0i64;
    do
    {
      v8 = v3->m_modelPose.m_data;
      ++v7;
      v2->m_min.m_quad = _mm_min_ps(v2->m_min.m_quad, v8[v7 - 1].m_translation.m_quad);
      v6 = _mm_max_ps(v6, v8[v7 - 1].m_translation.m_quad);
      v2->m_max.m_quad = v6;
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

