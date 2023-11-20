// File Line: 15
// RVA: 0x12FAFD0
void __fastcall hkaiPhysicsBodySilhouetteGeneratorBase::hkaiPhysicsBodySilhouetteGeneratorBase(hkaiPhysicsBodySilhouetteGeneratorBase *this)
{
  hkaiPhysicsBodySilhouetteGeneratorBase *v1; // rbx

  v1 = this;
  hkaiPointCloudSilhouetteGenerator::hkaiPointCloudSilhouetteGenerator((hkaiPointCloudSilhouetteGenerator *)&this->vfptr);
  v1->vfptr = (hkBaseObjectVtbl *)&hkaiPhysicsBodySilhouetteGeneratorBase::`vftable;
  v1->m_linearVelocityAndThreshold.m_quad = _mm_shuffle_ps(
                                              (__m128)0i64,
                                              _mm_unpackhi_ps((__m128)0i64, (__m128)xmmword_141A710E0),
                                              196);
}

// File Line: 24
// RVA: 0x12FB010
void __fastcall hkaiPhysicsBodySilhouetteGeneratorBase::hkaiPhysicsBodySilhouetteGeneratorBase(hkaiPhysicsBodySilhouetteGeneratorBase *this, hkFinishLoadedObjectFlag f)
{
  hkaiPhysicsBodySilhouetteGeneratorBase *v2; // rbx

  v2 = this;
  hkaiPointCloudSilhouetteGenerator::hkaiPointCloudSilhouetteGenerator(
    (hkaiPointCloudSilhouetteGenerator *)&this->vfptr,
    f);
  v2->vfptr = (hkBaseObjectVtbl *)&hkaiPhysicsBodySilhouetteGeneratorBase::`vftable;
}

// File Line: 28
// RVA: 0x12FB040
void __fastcall hkaiPhysicsBodySilhouetteGeneratorBase::~hkaiPhysicsBodySilhouetteGeneratorBase(hkaiPhysicsBodySilhouetteGeneratorBase *this)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiPhysicsBodySilhouetteGeneratorBase::`vftable;
  hkaiPointCloudSilhouetteGenerator::~hkaiPointCloudSilhouetteGenerator((hkaiPointCloudSilhouetteGenerator *)&this->vfptr);
}

// File Line: 32
// RVA: 0x12FB0C0
void __fastcall hkaiPhysicsBodySilhouetteGeneratorBase::update(hkaiPhysicsBodySilhouetteGeneratorBase *this, hkVector4f *up)
{
  hkaiPhysicsBodySilhouetteGeneratorBase *v2; // rbx

  v2 = this;
  hkaiPointCloudSilhouetteGenerator::update((hkaiPointCloudSilhouetteGenerator *)&this->vfptr, up);
  hkaiPhysicsBodySilhouetteGeneratorBase::updateCachedTransform(v2);
}

// File Line: 42
// RVA: 0x12FB350
void __fastcall hkaiPhysicsBodySilhouetteGeneratorBase::updateFromBodyInfo(hkaiPhysicsBodySilhouetteGeneratorBase *this, hkQuaternionf *rbRotation, hkVector4f *translation, hkVector4f *linearVel)
{
  this->m_transform.m_rotation = (hkQuaternionf)rbRotation->m_vec.m_quad;
  this->m_transform.m_translation = (hkVector4f)translation->m_quad;
  this->m_linearVelocityAndThreshold.m_quad = _mm_shuffle_ps(
                                                linearVel->m_quad,
                                                _mm_unpackhi_ps(
                                                  linearVel->m_quad,
                                                  this->m_linearVelocityAndThreshold.m_quad),
                                                196);
}

// File Line: 52
// RVA: 0x12FB0F0
bool __fastcall hkaiPhysicsBodySilhouetteGeneratorBase::willGenerateSilhouettes(hkaiPhysicsBodySilhouetteGeneratorBase *this, hkaiNavMeshInstance *meshInstance, hkVector4f *up)
{
  hkVector4f *v3; // rsi
  hkaiNavMeshInstance *v4; // rbp
  hkaiPhysicsBodySilhouetteGeneratorBase *v5; // rdi
  bool result; // al
  __m128 v7; // xmm2
  __m128 v8; // xmm1
  __m128 v9; // xmm4
  __m128 v10; // xmm4
  hkVector4f localVel; // [rsp+20h] [rbp-18h]

  v3 = up;
  v4 = meshInstance;
  v5 = this;
  result = hkaiPointCloudSilhouetteGenerator::willGenerateSilhouettes(
             (hkaiPointCloudSilhouetteGenerator *)&this->vfptr,
             meshInstance,
             up);
  if ( result )
  {
    hkaiReferenceFrame::transformWorldPosVelToLocalVel(
      &v4->m_referenceFrame,
      &v5->m_transform.m_translation,
      &v5->m_linearVelocityAndThreshold,
      &localVel);
    v7 = _mm_mul_ps(v3->m_quad, localVel.m_quad);
    v8 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170));
    v7.m128_i32[0] = (unsigned __int128)_mm_shuffle_ps(
                                          v5->m_linearVelocityAndThreshold.m_quad,
                                          v5->m_linearVelocityAndThreshold.m_quad,
                                          255);
    v9 = _mm_add_ps(localVel.m_quad, _mm_mul_ps(_mm_sub_ps((__m128)0i64, v8), v3->m_quad));
    v10 = _mm_mul_ps(v9, v9);
    result = (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v10, v10, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v10, v10, 0)))
                   + COERCE_FLOAT(_mm_shuffle_ps(v10, v10, 170))) < (float)(v7.m128_f32[0] * v7.m128_f32[0]);
  }
  return result;
}

// File Line: 74
// RVA: 0x12FB380
void __fastcall getSphereVerts(hkSimdFloat32 *radius, hkVector4f *vertsOut)
{
  __m128 v2; // xmm3
  __m128 v3; // xmm2
  hkVector4f v4; // xmm1
  __m128 v5; // xmm1
  __m128 v6; // xmm3
  __m128 v7; // xmm4
  __m128 v8; // xmm5
  __m128 v9; // xmm1
  __m128 v10; // xmm6
  __m128 v11; // xmm3
  __m128 v12; // xmm2
  __m128 v13; // xmm1
  __m128 v14; // xmm5

  v2 = _mm_unpacklo_ps((__m128)0i64, (__m128)0i64);
  v3 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
  v4.m_quad = _mm_movelh_ps(_mm_unpacklo_ps(radius->m_real, (__m128)0i64), v2);
  *vertsOut = (hkVector4f)v4.m_quad;
  vertsOut[1].m_quad = _mm_xor_ps(v3, v4.m_quad);
  v5 = _mm_movelh_ps(_mm_unpacklo_ps((__m128)0i64, radius->m_real), v2);
  vertsOut[2] = (hkVector4f)v5;
  vertsOut[3].m_quad = _mm_xor_ps(v5, v3);
  v6 = _mm_movelh_ps(v2, _mm_unpacklo_ps(radius->m_real, (__m128)0i64));
  vertsOut[4] = (hkVector4f)v6;
  vertsOut[5].m_quad = _mm_xor_ps(v6, v3);
  v7 = _mm_mul_ps(
         _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_75055534), (__m128)LODWORD(FLOAT_0_75055534), 0),
         radius->m_real);
  v8 = _mm_sub_ps((__m128)0i64, v7);
  v9 = _mm_unpacklo_ps(v7, v7);
  v10 = _mm_unpacklo_ps(v7, (__m128)0i64);
  v11 = _mm_unpacklo_ps(v8, (__m128)0i64);
  v12 = _mm_unpacklo_ps(v8, v7);
  vertsOut[6].m_quad = _mm_movelh_ps(v9, v10);
  vertsOut[7].m_quad = _mm_movelh_ps(v9, v11);
  v13 = _mm_unpacklo_ps(v7, v8);
  v14 = _mm_unpacklo_ps(v8, v8);
  vertsOut[8].m_quad = _mm_movelh_ps(v13, v10);
  vertsOut[10].m_quad = _mm_movelh_ps(v12, v10);
  vertsOut[12].m_quad = _mm_movelh_ps(v14, v10);
  vertsOut[13].m_quad = _mm_movelh_ps(v14, v11);
  vertsOut[9].m_quad = _mm_movelh_ps(v13, v11);
  vertsOut[11].m_quad = _mm_movelh_ps(v12, v11);
}

// File Line: 99
// RVA: 0x12FB1D0
void __fastcall hkaiPhysicsBodySilhouetteGeneratorBase::getPointsForSphere(hkVector4f *p, hkSimdFloat32 *radius, hkArray<hkVector4f,hkContainerTempAllocator> *vertsOut)
{
  hkArray<hkVector4f,hkContainerTempAllocator> *v3; // rbx
  hkSimdFloat32 *v4; // rsi
  int v5; // eax
  hkVector4f *v6; // rdi
  int v7; // eax
  int v8; // er9
  hkVector4f *v9; // rdx
  int v10; // ecx
  __int64 v11; // rdx
  hkResult result; // [rsp+50h] [rbp+18h]

  v3 = vertsOut;
  v4 = radius;
  v5 = vertsOut->m_capacityAndFlags & 0x3FFFFFFF;
  v6 = p;
  if ( v5 < 14 )
  {
    v7 = 2 * v5;
    v8 = 14;
    if ( v7 > 14 )
      v8 = v7;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, vertsOut, v8, 16);
  }
  v9 = v3->m_data;
  v3->m_size = 14;
  getSphereVerts(v4, v9);
  v10 = 0;
  if ( v3->m_size > 0 )
  {
    v11 = 0i64;
    do
    {
      ++v10;
      ++v11;
      v3->m_data[v11 - 1].m_quad = _mm_add_ps(v6->m_quad, v3->m_data[v11 - 1].m_quad);
    }
    while ( v10 < v3->m_size );
  }
}

// File Line: 110
// RVA: 0x12FB280
void __fastcall hkaiPhysicsBodySilhouetteGeneratorBase::getPointsForCapsule(hkVector4f *p0, hkVector4f *p1, hkSimdFloat32 *radius, hkArray<hkVector4f,hkContainerTempAllocator> *vertsOut)
{
  hkVector4f *v4; // rsi
  hkVector4f *v5; // rbp
  hkArray<hkVector4f,hkContainerTempAllocator> *v6; // rbx
  __int64 v7; // r9
  signed __int64 v8; // rdi
  int v9; // eax
  int v10; // eax
  int v11; // er9
  __int64 v12; // rcx
  hkVector4f *v13; // rdx
  signed __int64 v14; // r8
  hkVector4f vertsOuta; // [rsp+30h] [rbp-E8h]
  hkResult result; // [rsp+138h] [rbp+20h]

  v4 = p1;
  v5 = p0;
  v6 = vertsOut;
  getSphereVerts(radius, &vertsOuta);
  v8 = 1i64;
  v9 = *(_DWORD *)(v7 + 12) & 0x3FFFFFFF;
  if ( v9 < 28 )
  {
    v10 = 2 * v9;
    v11 = 28;
    if ( v10 > 28 )
      v11 = v10;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v6, v11, 16);
  }
  v12 = 0i64;
  v6->m_size = 28;
  v13 = &vertsOuta;
  v14 = 14i64;
  do
  {
    v8 += 2i64;
    ++v13;
    v12 += 2i64;
    v6->m_data[v12 - 2].m_quad = _mm_add_ps(v5->m_quad, v13[-1].m_quad);
    v6->m_data[v8 - 2].m_quad = _mm_add_ps(v4->m_quad, v13[-1].m_quad);
    --v14;
  }
  while ( v14 );
}

// File Line: 123
// RVA: 0x12FB1C0
void __fastcall hkaiPhysicsBodySilhouetteGeneratorBase::preSerialize(hkaiPhysicsBodySilhouetteGeneratorBase *this)
{
  hkaiPhysicsBodySilhouetteGeneratorBase::updateCachedTransform(this);
}

// File Line: 128
// RVA: 0x12FB060
void __fastcall hkaiPhysicsBodySilhouetteGeneratorBase::updateCachedTransform(hkaiPhysicsBodySilhouetteGeneratorBase *this)
{
  hkaiPhysicsBodySilhouetteGeneratorBase *v1; // rbx
  hkVector4f linearVel; // [rsp+20h] [rbp-38h]
  hkVector4f translation; // [rsp+30h] [rbp-28h]
  hkQuaternionf rbRotation; // [rsp+40h] [rbp-18h]

  v1 = this;
  if ( ((unsigned __int8 (*)(void))this->vfptr[8].__first_virtual_table_function__)() )
  {
    ((void (__fastcall *)(hkaiPhysicsBodySilhouetteGeneratorBase *, hkQuaternionf *, hkVector4f *))v1->vfptr[7].__first_virtual_table_function__)(
      v1,
      &rbRotation,
      &translation);
    v1->vfptr[8].__vecDelDtor((hkBaseObject *)&v1->vfptr, (unsigned int)&linearVel);
    hkaiPhysicsBodySilhouetteGeneratorBase::updateFromBodyInfo(v1, &rbRotation, &translation, &linearVel);
  }
}

