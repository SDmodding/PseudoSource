// File Line: 37
// RVA: 0xD0C8C0
void __fastcall hkMoppBvTreeShapeBase::hkMoppBvTreeShapeBase(
        hkMoppBvTreeShapeBase *this,
        hkcdShapeType::ShapeTypeEnum type,
        hkpMoppCode *code)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_type.m_storage = type;
  *(_WORD *)&this->m_dispatchType.m_storage = 4;
  this->m_shapeInfoCodecType.m_storage = 0;
  this->m_userData = 0i64;
  this->m_bvTreeType.m_storage = 0;
  this->vfptr = (hkBaseObjectVtbl *)&hkMoppBvTreeShapeBase::`vftable;
  this->m_code = code;
  hkReferencedObject::addReference(code);
  this->m_codeInfoCopy = (hkVector4f)code->m_info;
  this->m_moppData = code->m_data.m_data;
  this->m_moppDataSize = code->m_data.m_size;
}

// File Line: 49
// RVA: 0xD0C930
void __fastcall hkMoppBvTreeShapeBase::queryObb(
        hkMoppBvTreeShapeBase *this,
        hkTransformf *obbToMopp,
        hkVector4f *extent,
        float tolerance,
        hkArray<unsigned int,hkContainerHeapAllocator> *hits)
{
  hkpMoppObbVirtualMachine v5; // [rsp+30h] [rbp-58h] BYREF

  hkpMoppObbVirtualMachine::queryObb(
    &v5,
    this->m_code,
    obbToMopp,
    extent,
    tolerance,
    (hkArray<hkpMoppPrimitiveInfo,hkContainerHeapAllocator> *)hits);
}

// File Line: 56
// RVA: 0xD0C970
void __fastcall hkMoppBvTreeShapeBase::queryAabb(
        hkMoppBvTreeShapeBase *this,
        hkAabb *aabb,
        hkArray<hkpMoppPrimitiveInfo,hkContainerHeapAllocator> *hits)
{
  __m128 v3; // xmm1
  hkVector4f v4; // xmm1
  hkpMoppCode *m_code; // rdx
  hkAabb aabba; // [rsp+20h] [rbp-78h] BYREF
  hkpMoppObbVirtualMachine v7; // [rsp+40h] [rbp-58h] BYREF

  aabba.m_min.m_quad = _mm_max_ps(this->m_codeInfoCopy.m_quad, aabb->m_min.m_quad);
  v3.m128_f32[0] = 16777216.0 / this->m_codeInfoCopy.m_quad.m128_f32[3];
  v4.m_quad = _mm_min_ps(_mm_add_ps(_mm_shuffle_ps(v3, v3, 0), this->m_codeInfoCopy.m_quad), aabb->m_max.m_quad);
  m_code = this->m_code;
  aabba.m_max = (hkVector4f)v4.m_quad;
  hkpMoppObbVirtualMachine::queryAabb(&v7, m_code, &aabba, hits);
}

// File Line: 75
// RVA: 0xD0C9D0
__int64 __fastcall hkMoppBvTreeShapeBase::queryAabbImpl(
        hkMoppBvTreeShapeBase *this,
        hkAabb *aabb,
        hkpMoppPrimitiveInfo *hits,
        int maxNumKeys)
{
  __m128 v4; // xmm1
  hkVector4f v5; // xmm2
  int m_moppDataSize; // r10d
  char *m_moppData; // rax
  float v8; // xmm0_4
  unsigned int m_size; // ebx
  hkArray<hkpMoppPrimitiveInfo,hkContainerHeapAllocator> primitives_out; // [rsp+20h] [rbp-D8h] BYREF
  hkAabb aabba; // [rsp+30h] [rbp-C8h] BYREF
  hkpMoppObbVirtualMachine v13; // [rsp+50h] [rbp-A8h] BYREF
  hkpMoppCode v14; // [rsp+A0h] [rbp-58h] BYREF

  v5.m_quad = (__m128)this->m_codeInfoCopy;
  m_moppDataSize = this->m_moppDataSize;
  m_moppData = (char *)this->m_moppData;
  primitives_out.m_data = hits;
  primitives_out.m_capacityAndFlags = maxNumKeys | 0x80000000;
  aabba.m_min.m_quad = _mm_max_ps(v5.m_quad, aabb->m_min.m_quad);
  v8 = 16777216.0 / this->m_codeInfoCopy.m_quad.m128_f32[3];
  primitives_out.m_size = 0;
  v14.m_info.m_offset = (hkVector4f)v5.m_quad;
  v14.m_data.m_data = m_moppData;
  v14.m_data.m_size = m_moppDataSize;
  v14.m_data.m_capacityAndFlags = m_moppDataSize;
  v4.m128_f32[0] = v8;
  v14.m_buildType.m_storage = 2;
  aabba.m_max.m_quad = _mm_min_ps(_mm_add_ps(_mm_shuffle_ps(v4, v4, 0), v5.m_quad), aabb->m_max.m_quad);
  hkpMoppObbVirtualMachine::queryAabb(&v13, &v14, &aabba, &primitives_out);
  m_size = v13.m_primitives_out->m_size;
  primitives_out.m_size = 0;
  if ( primitives_out.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      primitives_out.m_data,
      4 * primitives_out.m_capacityAndFlags);
  return m_size;
}

// File Line: 112
// RVA: 0xD0CAB0
void __fastcall hkpMoppBvTreeShape::hkpMoppBvTreeShape(
        hkpMoppBvTreeShape *this,
        hkpShapeCollection *collection,
        hkpMoppCode *code)
{
  hkMoppBvTreeShapeBase::hkMoppBvTreeShapeBase(this, MOPP, code);
  this->vfptr = (hkBaseObjectVtbl *)&hkpMoppBvTreeShape::`vftable;
  this->m_child.m_childShape = collection;
  this->m_child.vfptr = (hkpShapeContainerVtbl *)&hkpSingleShapeContainer::`vftable;
  hkReferencedObject::addReference(collection);
}

// File Line: 116
// RVA: 0xD0CB00
void __fastcall hkpMoppBvTreeShape::~hkpMoppBvTreeShape(hkpMoppBvTreeShape *this)
{
  hkpShape *m_childShape; // rcx
  hkpMoppCode *m_code; // rcx

  this->vfptr = (hkBaseObjectVtbl *)&hkpMoppBvTreeShape::`vftable;
  this->m_child.vfptr = (hkpShapeContainerVtbl *)&hkpSingleShapeContainer::`vftable;
  m_childShape = this->m_child.m_childShape;
  if ( m_childShape )
    hkReferencedObject::removeReference(m_childShape);
  this->m_child.vfptr = (hkpShapeContainerVtbl *)&hkpShapeContainer::`vftable;
  m_code = this->m_code;
  this->vfptr = (hkBaseObjectVtbl *)&hkMoppBvTreeShapeBase::`vftable;
  hkReferencedObject::removeReference(m_code);
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 139
// RVA: 0xD0CB60
void __fastcall hkpMoppBvTreeShape::getAabb(
        hkpMoppBvTreeShape *this,
        hkTransformf *localToWorld,
        float tolerance,
        hkAabb *out)
{
  __int64 v4; // r8

  ((void (__fastcall *)(hkpShape *, hkTransformf *, __int64, hkAabb *))this->m_child.m_childShape->vfptr[2].__vecDelDtor)(
    this->m_child.m_childShape,
    localToWorld,
    v4,
    out);
}

// File Line: 153
// RVA: 0xD0CB80
hkBool *__fastcall hkpMoppBvTreeShape::castRay(
        hkpMoppBvTreeShape *this,
        hkBool *result,
        hkpShapeRayCastInput *input,
        hkpShapeRayCastOutput *results)
{
  _QWORD *Value; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r10
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  char *m_moppData; // rax
  int m_moppDataSize; // ecx
  hkVector4f v15; // xmm0
  hkpShapeContainer *v16; // r8
  hkpShape *m_childShape; // rax
  _QWORD *v18; // r8
  _QWORD *v19; // rcx
  unsigned __int64 v20; // rax
  _QWORD *v21; // rcx
  hkpMoppLongRayVirtualMachine v23; // [rsp+30h] [rbp-F8h] BYREF
  hkpMoppCode v24; // [rsp+D0h] [rbp-58h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  v10 = Value;
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtrcMopp";
    v11 = __rdtsc();
    v12 = v9 + 2;
    *((_DWORD *)v12 - 2) = v11;
    v10[1] = v12;
  }
  m_moppData = (char *)this->m_moppData;
  m_moppDataSize = this->m_moppDataSize;
  v15.m_quad = (__m128)this->m_codeInfoCopy;
  v16 = 0i64;
  v23.m_ray.m_filterInfo = 0;
  memset(&v23.m_ray.m_rayShapeCollectionFilter, 0, 24);
  v24.m_info.m_offset = (hkVector4f)v15.m_quad;
  v24.m_data.m_data = m_moppData;
  m_childShape = this->m_child.m_childShape;
  v24.m_data.m_size = m_moppDataSize;
  v24.m_data.m_capacityAndFlags = m_moppDataSize;
  v24.m_buildType.m_storage = 2;
  if ( m_childShape )
    v16 = (hkpShapeContainer *)&m_childShape[1];
  hkpMoppLongRayVirtualMachine::queryLongRay(&v23, result, v16, &v24, input, results);
  v18 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v19 = (_QWORD *)v18[1];
  if ( (unsigned __int64)v19 < v18[3] )
  {
    *v19 = "Et";
    v20 = __rdtsc();
    v21 = v19 + 2;
    *((_DWORD *)v21 - 2) = v20;
    v18[1] = v21;
  }
  return result;
}

// File Line: 173
// RVA: 0xD0CDE0
hkVector4fComparison *__fastcall hkpMoppBvTreeShape::castRayBundle(
        hkpMoppBvTreeShape *this,
        hkVector4fComparison *result,
        hkpShapeRayBundleCastInput *input,
        hkpShapeRayBundleCastOutput *results,
        hkVector4fComparison *mask)
{
  _QWORD *Value; // rax
  _QWORD *v10; // rcx
  _QWORD *v11; // r10
  unsigned __int64 v12; // rax
  _QWORD *v13; // rcx
  int m_moppDataSize; // ecx
  char *m_moppData; // rax
  hkpShape *m_childShape; // r8
  _QWORD *v17; // r8
  _QWORD *v18; // rcx
  unsigned __int64 v19; // rax
  _QWORD *v20; // rcx
  hkpMoppCode v22; // [rsp+40h] [rbp-148h] BYREF
  hkpMoppRayBundleVirtualMachine v23; // [rsp+90h] [rbp-F8h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)Value[1];
  v11 = Value;
  if ( (unsigned __int64)v10 < Value[3] )
  {
    *v10 = "TtrcBundleMopp";
    v12 = __rdtsc();
    v13 = v10 + 2;
    *((_DWORD *)v13 - 2) = v12;
    v11[1] = v13;
  }
  m_moppDataSize = this->m_moppDataSize;
  m_moppData = (char *)this->m_moppData;
  m_childShape = this->m_child.m_childShape;
  v22.m_info = (hkpMoppCode::CodeInfo)this->m_codeInfoCopy;
  v22.m_data.m_data = m_moppData;
  v22.m_data.m_size = m_moppDataSize;
  v22.m_data.m_capacityAndFlags = m_moppDataSize;
  v22.m_buildType.m_storage = 2;
  if ( m_childShape )
    ++m_childShape;
  hkpMoppRayBundleVirtualMachine::queryRayBundle(
    &v23,
    result,
    (hkpShapeContainer *)m_childShape,
    &v22,
    input,
    results,
    mask);
  v17 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v18 = (_QWORD *)v17[1];
  if ( (unsigned __int64)v18 < v17[3] )
  {
    *v18 = "Et";
    v19 = __rdtsc();
    v20 = v18 + 2;
    *((_DWORD *)v20 - 2) = v19;
    v17[1] = v20;
  }
  return result;
}

// File Line: 194
// RVA: 0xD0CCB0
void __fastcall hkpMoppBvTreeShape::castRayWithCollector(
        hkpMoppBvTreeShape *this,
        hkpShapeRayCastInput *input,
        hkpCdBody *cdBody,
        hkpRayHitCollector *collector)
{
  _QWORD *Value; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r10
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  char *m_moppData; // rax
  int m_moppDataSize; // ecx
  hkVector4f v15; // xmm0
  hkpShapeContainer *v16; // rdx
  hkpShape *m_childShape; // rax
  _QWORD *v18; // r8
  _QWORD *v19; // rcx
  unsigned __int64 v20; // rax
  _QWORD *v21; // rcx
  hkpMoppLongRayVirtualMachine v22; // [rsp+30h] [rbp-F8h] BYREF
  hkpMoppCode v23; // [rsp+D0h] [rbp-58h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  v10 = Value;
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtrcMopp";
    v11 = __rdtsc();
    v12 = v9 + 2;
    *((_DWORD *)v12 - 2) = v11;
    v10[1] = v12;
  }
  m_moppData = (char *)this->m_moppData;
  m_moppDataSize = this->m_moppDataSize;
  v15.m_quad = (__m128)this->m_codeInfoCopy;
  v16 = 0i64;
  v22.m_ray.m_filterInfo = 0;
  memset(&v22.m_ray.m_rayShapeCollectionFilter, 0, 24);
  v23.m_info.m_offset = (hkVector4f)v15.m_quad;
  v23.m_data.m_data = m_moppData;
  m_childShape = this->m_child.m_childShape;
  v23.m_data.m_size = m_moppDataSize;
  v23.m_data.m_capacityAndFlags = m_moppDataSize;
  v23.m_buildType.m_storage = 2;
  if ( m_childShape )
    v16 = (hkpShapeContainer *)&m_childShape[1];
  hkpMoppLongRayVirtualMachine::queryLongRay(&v22, v16, &v23, input, cdBody, collector);
  v18 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v19 = (_QWORD *)v18[1];
  if ( (unsigned __int64)v19 < v18[3] )
  {
    *v19 = "Et";
    v20 = __rdtsc();
    v21 = v19 + 2;
    *((_DWORD *)v21 - 2) = v20;
    v18[1] = v21;
  }
}

// File Line: 215
// RVA: 0xD0CF00
__int64 __fastcall hkpMoppBvTreeShape::calcSizeForSpu(
        hkpMoppBvTreeShape *this,
        hkpShape::CalcSizeForSpuInput *input,
        int spuBufferSizeLeft)
{
  unsigned int v5; // eax

  if ( this->m_code->m_buildType.m_storage )
    return 0xFFFFFFFFi64;
  v5 = ((__int64 (__fastcall *)(hkpShape *, hkpShape::CalcSizeForSpuInput *, __int64))this->m_child.m_childShape->vfptr[8].__vecDelDtor)(
         this->m_child.m_childShape,
         input,
         256i64);
  if ( v5 > 0x100 )
    return 0xFFFFFFFFi64;
  this->m_childSize = v5;
  return 112i64;
}

