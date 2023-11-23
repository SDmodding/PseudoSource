// File Line: 15
// RVA: 0x12FAFD0
void __fastcall hkaiPhysicsBodySilhouetteGeneratorBase::hkaiPhysicsBodySilhouetteGeneratorBase(
        hkaiPhysicsBodySilhouetteGeneratorBase *this)
{
  hkaiPointCloudSilhouetteGenerator::hkaiPointCloudSilhouetteGenerator(this);
  this->vfptr = (hkBaseObjectVtbl *)&hkaiPhysicsBodySilhouetteGeneratorBase::`vftable;
  this->m_linearVelocityAndThreshold.m_quad = _mm_shuffle_ps(
                                                (__m128)0i64,
                                                _mm_unpackhi_ps((__m128)0i64, (__m128)xmmword_141A710E0),
                                                196);
}

// File Line: 24
// RVA: 0x12FB010
void __fastcall hkaiPhysicsBodySilhouetteGeneratorBase::hkaiPhysicsBodySilhouetteGeneratorBase(
        hkaiPhysicsBodySilhouetteGeneratorBase *this,
        hkFinishLoadedObjectFlag f)
{
  hkaiPointCloudSilhouetteGenerator::hkaiPointCloudSilhouetteGenerator(this, f);
  this->vfptr = (hkBaseObjectVtbl *)&hkaiPhysicsBodySilhouetteGeneratorBase::`vftable;
}

// File Line: 28
// RVA: 0x12FB040
void __fastcall hkaiPhysicsBodySilhouetteGeneratorBase::~hkaiPhysicsBodySilhouetteGeneratorBase(
        hkaiPhysicsBodySilhouetteGeneratorBase *this)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiPhysicsBodySilhouetteGeneratorBase::`vftable;
  hkaiPointCloudSilhouetteGenerator::~hkaiPointCloudSilhouetteGenerator(this);
}

// File Line: 32
// RVA: 0x12FB0C0
void __fastcall hkaiPhysicsBodySilhouetteGeneratorBase::update(
        hkaiPhysicsBodySilhouetteGeneratorBase *this,
        hkVector4f *up)
{
  hkaiPointCloudSilhouetteGenerator::update(this, up);
  hkaiPhysicsBodySilhouetteGeneratorBase::updateCachedTransform(this);
}

// File Line: 42
// RVA: 0x12FB350
void __fastcall hkaiPhysicsBodySilhouetteGeneratorBase::updateFromBodyInfo(
        hkaiPhysicsBodySilhouetteGeneratorBase *this,
        hkQuaternionf *rbRotation,
        hkVector4f *translation,
        hkVector4f *linearVel)
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
bool __fastcall hkaiPhysicsBodySilhouetteGeneratorBase::willGenerateSilhouettes(
        hkaiPhysicsBodySilhouetteGeneratorBase *this,
        hkaiNavMeshInstance *meshInstance,
        hkVector4f *up)
{
  bool result; // al
  __m128 v7; // xmm2
  __m128 v8; // xmm1
  __m128 v9; // xmm4
  __m128 v10; // xmm4
  hkVector4f localVel; // [rsp+20h] [rbp-18h] BYREF

  result = hkaiPointCloudSilhouetteGenerator::willGenerateSilhouettes(this, meshInstance, up);
  if ( result )
  {
    hkaiReferenceFrame::transformWorldPosVelToLocalVel(
      &meshInstance->m_referenceFrame,
      &this->m_transform.m_translation,
      &this->m_linearVelocityAndThreshold,
      &localVel);
    v7 = _mm_mul_ps(up->m_quad, localVel.m_quad);
    v8 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170));
    v7.m128_f32[0] = _mm_shuffle_ps(
                       this->m_linearVelocityAndThreshold.m_quad,
                       this->m_linearVelocityAndThreshold.m_quad,
                       255).m128_f32[0];
    v9 = _mm_add_ps(localVel.m_quad, _mm_mul_ps(_mm_sub_ps((__m128)0i64, v8), up->m_quad));
    v10 = _mm_mul_ps(v9, v9);
    return (float)((float)(_mm_shuffle_ps(v10, v10, 85).m128_f32[0] + _mm_shuffle_ps(v10, v10, 0).m128_f32[0])
                 + _mm_shuffle_ps(v10, v10, 170).m128_f32[0]) < (float)(v7.m128_f32[0] * v7.m128_f32[0]);
  }
  return result;
}

// File Line: 74
// RVA: 0x12FB380
void __fastcall getSphereVerts(hkSimdFloat32 *radius, hkVector4f *vertsOut)
{
  __m128 v2; // xmm3
  __m128 v3; // xmm2
  __m128 v4; // xmm1
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
  v4 = _mm_movelh_ps(_mm_unpacklo_ps(radius->m_real, (__m128)0i64), v2);
  *vertsOut = (hkVector4f)v4;
  vertsOut[1].m_quad = _mm_xor_ps(v3, v4);
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
void __fastcall hkaiPhysicsBodySilhouetteGeneratorBase::getPointsForSphere(
        hkVector4f *p,
        hkSimdFloat32 *radius,
        hkArray<hkVector4f,hkContainerTempAllocator> *vertsOut)
{
  int v6; // r9d
  hkVector4f *m_data; // rdx
  int v8; // ecx
  __int64 v9; // rdx
  hkResult result; // [rsp+50h] [rbp+18h] BYREF

  if ( (vertsOut->m_capacityAndFlags & 0x3FFFFFFFu) < 0xE )
  {
    v6 = 14;
    if ( 2 * (vertsOut->m_capacityAndFlags & 0x3FFFFFFF) > 14 )
      v6 = 2 * (vertsOut->m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, (const void **)&vertsOut->m_data, v6, 16);
  }
  m_data = vertsOut->m_data;
  vertsOut->m_size = 14;
  getSphereVerts(radius, m_data);
  v8 = 0;
  if ( vertsOut->m_size > 0 )
  {
    v9 = 0i64;
    do
    {
      ++v8;
      ++v9;
      vertsOut->m_data[v9 - 1].m_quad = _mm_add_ps(p->m_quad, vertsOut->m_data[v9 - 1].m_quad);
    }
    while ( v8 < vertsOut->m_size );
  }
}

// File Line: 110
// RVA: 0x12FB280
void __fastcall hkaiPhysicsBodySilhouetteGeneratorBase::getPointsForCapsule(
        hkVector4f *p0,
        hkVector4f *p1,
        hkSimdFloat32 *radius,
        hkArray<hkVector4f,hkContainerTempAllocator> *vertsOut)
{
  __int64 v7; // r9
  __int64 v8; // rdi
  int v9; // eax
  int v10; // r9d
  __int64 v11; // rcx
  hkVector4f *p_vertsOuta; // rdx
  __int64 v13; // r8
  hkVector4f vertsOuta; // [rsp+30h] [rbp-E8h] BYREF
  hkResult result; // [rsp+138h] [rbp+20h] BYREF

  getSphereVerts(radius, &vertsOuta);
  v8 = 1i64;
  if ( (*(_DWORD *)(v7 + 12) & 0x3FFFFFFFu) < 0x1C )
  {
    v9 = 2 * (*(_DWORD *)(v7 + 12) & 0x3FFFFFFF);
    v10 = 28;
    if ( v9 > 28 )
      v10 = v9;
    hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, (const void **)&vertsOut->m_data, v10, 16);
  }
  v11 = 0i64;
  vertsOut->m_size = 28;
  p_vertsOuta = &vertsOuta;
  v13 = 14i64;
  do
  {
    v8 += 2i64;
    ++p_vertsOuta;
    v11 += 2i64;
    vertsOut->m_data[v11 - 2].m_quad = _mm_add_ps(p0->m_quad, p_vertsOuta[-1].m_quad);
    vertsOut->m_data[v8 - 2].m_quad = _mm_add_ps(p1->m_quad, p_vertsOuta[-1].m_quad);
    --v13;
  }
  while ( v13 );
}

// File Line: 123
// RVA: 0x12FB1C0
// attributes: thunk
void __fastcall hkaiPhysicsBodySilhouetteGeneratorBase::preSerialize(hkaiPhysicsBodySilhouetteGeneratorBase *this)
{
  hkaiPhysicsBodySilhouetteGeneratorBase::updateCachedTransform(this);
}

// File Line: 128
// RVA: 0x12FB060
void __fastcall hkaiPhysicsBodySilhouetteGeneratorBase::updateCachedTransform(
        hkaiPhysicsBodySilhouetteGeneratorBase *this)
{
  hkVector4f linearVel; // [rsp+20h] [rbp-38h] BYREF
  hkVector4f translation; // [rsp+30h] [rbp-28h] BYREF
  hkQuaternionf rbRotation; // [rsp+40h] [rbp-18h] BYREF

  if ( ((unsigned __int8 (__fastcall *)(hkaiPhysicsBodySilhouetteGeneratorBase *))this->vfptr[8].__first_virtual_table_function__)(this) )
  {
    ((void (__fastcall *)(hkaiPhysicsBodySilhouetteGeneratorBase *, hkQuaternionf *, hkVector4f *))this->vfptr[7].__first_virtual_table_function__)(
      this,
      &rbRotation,
      &translation);
    this->vfptr[8].__vecDelDtor(this, (unsigned int)&linearVel);
    hkaiPhysicsBodySilhouetteGeneratorBase::updateFromBodyInfo(this, &rbRotation, &translation, &linearVel);
  }
}

