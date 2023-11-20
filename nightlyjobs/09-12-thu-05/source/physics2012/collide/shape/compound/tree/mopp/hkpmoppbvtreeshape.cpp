// File Line: 37
// RVA: 0xD0C8C0
void __fastcall hkMoppBvTreeShapeBase::hkMoppBvTreeShapeBase(hkMoppBvTreeShapeBase *this, hkcdShapeType::ShapeTypeEnum type, hkpMoppCode *code)
{
  hkpMoppCode *v3; // rbx
  hkMoppBvTreeShapeBase *v4; // rdi

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_type.m_storage = type;
  *(_WORD *)&this->m_dispatchType.m_storage = 4;
  this->m_shapeInfoCodecType.m_storage = 0;
  this->m_userData = 0i64;
  this->m_bvTreeType.m_storage = 0;
  v3 = code;
  v4 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkMoppBvTreeShapeBase::`vftable';
  this->m_code = code;
  hkReferencedObject::addReference((hkReferencedObject *)&code->vfptr);
  v4->m_codeInfoCopy = (hkVector4f)v3->m_info;
  v4->m_moppData = v3->m_data.m_data;
  v4->m_moppDataSize = v3->m_data.m_size;
}

// File Line: 49
// RVA: 0xD0C930
void __fastcall hkMoppBvTreeShapeBase::queryObb(hkMoppBvTreeShapeBase *this, hkTransformf *obbToMopp, hkVector4f *extent, float tolerance, hkArray<unsigned int,hkContainerHeapAllocator> *hits)
{
  hkpMoppObbVirtualMachine v5; // [rsp+30h] [rbp-58h]

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
void __usercall hkMoppBvTreeShapeBase::queryAabb(hkMoppBvTreeShapeBase *this@<rcx>, hkAabb *aabb@<rdx>, hkArray<unsigned int,hkContainerHeapAllocator> *hits@<r8>, __m128 a4@<xmm1>)
{
  hkVector4f v4; // xmm1
  hkpMoppCode *v5; // rdx
  hkAabb aabba; // [rsp+20h] [rbp-78h]
  hkpMoppObbVirtualMachine v7; // [rsp+40h] [rbp-58h]

  aabba.m_min.m_quad = _mm_max_ps(this->m_codeInfoCopy.m_quad, aabb->m_min.m_quad);
  a4.m128_f32[0] = 16777216.0 / this->m_codeInfoCopy.m_quad.m128_f32[3];
  v4.m_quad = _mm_min_ps(_mm_add_ps(_mm_shuffle_ps(a4, a4, 0), this->m_codeInfoCopy.m_quad), aabb->m_max.m_quad);
  v5 = this->m_code;
  aabba.m_max = (hkVector4f)v4.m_quad;
  hkpMoppObbVirtualMachine::queryAabb(&v7, v5, &aabba, (hkArray<hkpMoppPrimitiveInfo,hkContainerHeapAllocator> *)hits);
}

// File Line: 75
// RVA: 0xD0C9D0
__int64 __usercall hkMoppBvTreeShapeBase::queryAabbImpl@<rax>(hkMoppBvTreeShapeBase *this@<rcx>, hkAabb *aabb@<rdx>, unsigned int *hits@<r8>, int maxNumKeys@<r9d>, __m128 a5@<xmm1>)
{
  hkVector4f v5; // xmm2
  unsigned int v6; // er10
  const char *v7; // rax
  hkVector4f v8; // xmm0
  unsigned __int64 v9; // r11
  unsigned int v10; // ebx
  hkArray<hkpMoppPrimitiveInfo,hkContainerHeapAllocator> primitives_out; // [rsp+20h] [rbp-D8h]
  hkAabb aabba; // [rsp+30h] [rbp-C8h]
  hkpMoppObbVirtualMachine v14; // [rsp+50h] [rbp-A8h]
  char v15; // [rsp+AFh] [rbp-49h]

  v5.m_quad = (__m128)this->m_codeInfoCopy;
  v6 = this->m_moppDataSize;
  v7 = this->m_moppData;
  v8.m_quad = (__m128)this->m_codeInfoCopy;
  primitives_out.m_data = (hkpMoppPrimitiveInfo *)hits;
  primitives_out.m_capacityAndFlags = maxNumKeys | 0x80000000;
  aabba.m_min.m_quad = _mm_max_ps(v8.m_quad, aabb->m_min.m_quad);
  v8.m_quad.m128_f32[0] = 16777216.0 / this->m_codeInfoCopy.m_quad.m128_f32[3];
  v9 = (unsigned __int64)&v15 & 0xFFFFFFFFFFFFFFF0ui64;
  primitives_out.m_size = 0;
  *(hkVector4f *)(v9 + 16) = (hkVector4f)v5.m_quad;
  *(_QWORD *)(v9 + 32) = v7;
  *(_DWORD *)(v9 + 40) = v6;
  *(_DWORD *)(v9 + 44) = v6;
  a5.m128_f32[0] = v8.m_quad.m128_f32[0];
  *(_BYTE *)(v9 + 48) = 2;
  aabba.m_max.m_quad = _mm_min_ps(_mm_add_ps(_mm_shuffle_ps(a5, a5, 0), v5.m_quad), aabb->m_max.m_quad);
  hkpMoppObbVirtualMachine::queryAabb(
    &v14,
    (hkpMoppCode *)((unsigned __int64)&v15 & 0xFFFFFFFFFFFFFFF0ui64),
    &aabba,
    &primitives_out);
  v10 = v14.m_primitives_out->m_size;
  primitives_out.m_size = 0;
  if ( primitives_out.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      primitives_out.m_data,
      4 * primitives_out.m_capacityAndFlags);
  return v10;
}

// File Line: 112
// RVA: 0xD0CAB0
void __fastcall hkpMoppBvTreeShape::hkpMoppBvTreeShape(hkpMoppBvTreeShape *this, hkpShapeCollection *collection, hkpMoppCode *code)
{
  hkpShapeCollection *v3; // rbx
  hkpMoppBvTreeShape *v4; // rdi

  v3 = collection;
  v4 = this;
  hkMoppBvTreeShapeBase::hkMoppBvTreeShapeBase((hkMoppBvTreeShapeBase *)&this->vfptr, MOPP, code);
  v4->vfptr = (hkBaseObjectVtbl *)&hkpMoppBvTreeShape::`vftable';
  v4->m_child.m_childShape = (hkpShape *)&v3->vfptr;
  v4->m_child.vfptr = (hkpShapeContainerVtbl *)&hkpSingleShapeContainer::`vftable';
  hkReferencedObject::addReference((hkReferencedObject *)&v3->vfptr);
}

// File Line: 116
// RVA: 0xD0CB00
void __fastcall hkpMoppBvTreeShape::~hkpMoppBvTreeShape(hkpMoppBvTreeShape *this)
{
  hkpMoppBvTreeShape *v1; // rbx
  hkpShape *v2; // rcx
  hkReferencedObject *v3; // rcx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpMoppBvTreeShape::`vftable';
  this->m_child.vfptr = (hkpShapeContainerVtbl *)&hkpSingleShapeContainer::`vftable';
  v2 = this->m_child.m_childShape;
  if ( v2 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
  v1->m_child.vfptr = (hkpShapeContainerVtbl *)&hkpShapeContainer::`vftable';
  v3 = (hkReferencedObject *)&v1->m_code->vfptr;
  v1->vfptr = (hkBaseObjectVtbl *)&hkMoppBvTreeShapeBase::`vftable';
  hkReferencedObject::removeReference(v3);
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 139
// RVA: 0xD0CB60
void __usercall hkpMoppBvTreeShape::getAabb(hkpMoppBvTreeShape *this@<rcx>, hkTransformf *localToWorld@<rdx>, float tolerance@<xmm2>, hkAabb *out@<r9>, __int64 a5@<r8>)
{
  ((void (__fastcall *)(hkpShape *, hkTransformf *, __int64, hkAabb *))this->m_child.m_childShape->vfptr[2].__vecDelDtor)(
    this->m_child.m_childShape,
    localToWorld,
    a5,
    out);
}

// File Line: 153
// RVA: 0xD0CB80
hkBool *__fastcall hkpMoppBvTreeShape::castRay(hkpMoppBvTreeShape *this, hkBool *result, hkpShapeRayCastInput *input, hkpShapeRayCastOutput *results)
{
  hkpMoppBvTreeShape *v4; // rdi
  hkpShapeRayCastOutput *rayResult; // rsi
  hkpShapeRayCastInput *v6; // rbp
  hkBool *v7; // rbx
  _QWORD *v8; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r10
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  const char *v13; // rax
  unsigned int v14; // ecx
  hkVector4f v15; // xmm0
  hkpShapeContainer *v16; // r8
  unsigned __int64 v17; // r9
  hkpShape *v18; // rax
  _QWORD *v19; // r8
  _QWORD *v20; // rcx
  unsigned __int64 v21; // rax
  signed __int64 v22; // rcx
  hkpMoppLongRayVirtualMachine v24; // [rsp+30h] [rbp-F8h]
  char v25; // [rsp+DFh] [rbp-49h]

  v4 = this;
  rayResult = results;
  v6 = input;
  v7 = result;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  v10 = v8;
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtrcMopp";
    v11 = __rdtsc();
    v12 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v12 - 8) = v11;
    v10[1] = v12;
  }
  v13 = v4->m_moppData;
  v14 = v4->m_moppDataSize;
  v15.m_quad = (__m128)v4->m_codeInfoCopy;
  v16 = 0i64;
  v17 = (unsigned __int64)&v25 & 0xFFFFFFFFFFFFFFF0ui64;
  v24.m_ray.m_filterInfo = 0;
  v24.m_ray.m_rayShapeCollectionFilter = 0i64;
  v24.m_ray.m_collidable = 0i64;
  v24.m_ray.m_userData = 0i64;
  *(hkVector4f *)(v17 + 16) = (hkVector4f)v15.m_quad;
  *(_QWORD *)(v17 + 32) = v13;
  v18 = v4->m_child.m_childShape;
  *(_DWORD *)(v17 + 40) = v14;
  *(_DWORD *)(v17 + 44) = v14;
  *(_BYTE *)(v17 + 48) = 2;
  if ( v18 )
    v16 = (hkpShapeContainer *)&v18[1];
  hkpMoppLongRayVirtualMachine::queryLongRay(&v24, v7, v16, (hkpMoppCode *)v17, v6, rayResult);
  v19 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v20 = (_QWORD *)v19[1];
  if ( (unsigned __int64)v20 < v19[3] )
  {
    *v20 = "Et";
    v21 = __rdtsc();
    v22 = (signed __int64)(v20 + 2);
    *(_DWORD *)(v22 - 8) = v21;
    v19[1] = v22;
  }
  return v7;
}

// File Line: 173
// RVA: 0xD0CDE0
hkVector4fComparison *__fastcall hkpMoppBvTreeShape::castRayBundle(hkpMoppBvTreeShape *this, hkVector4fComparison *result, hkpShapeRayBundleCastInput *input, hkpShapeRayBundleCastOutput *results, hkVector4fComparison *mask)
{
  hkpMoppBvTreeShape *v5; // rbx
  hkpShapeRayBundleCastOutput *rayResult; // rsi
  hkpShapeRayBundleCastInput *v7; // rbp
  hkVector4fComparison *v8; // rdi
  _QWORD *v9; // rax
  _QWORD *v10; // rcx
  _QWORD *v11; // r10
  unsigned __int64 v12; // rax
  signed __int64 v13; // rcx
  unsigned int v14; // ecx
  const char *v15; // rax
  hkpShapeContainer *v16; // r8
  unsigned __int64 v17; // r9
  _QWORD *v18; // r8
  _QWORD *v19; // rcx
  unsigned __int64 v20; // rax
  signed __int64 v21; // rcx
  char v23; // [rsp+4Fh] [rbp-139h]
  hkpMoppRayBundleVirtualMachine v24; // [rsp+90h] [rbp-F8h]

  v5 = this;
  rayResult = results;
  v7 = input;
  v8 = result;
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)v9[1];
  v11 = v9;
  if ( (unsigned __int64)v10 < v9[3] )
  {
    *v10 = "TtrcBundleMopp";
    v12 = __rdtsc();
    v13 = (signed __int64)(v10 + 2);
    *(_DWORD *)(v13 - 8) = v12;
    v11[1] = v13;
  }
  v14 = v5->m_moppDataSize;
  v15 = v5->m_moppData;
  v16 = (hkpShapeContainer *)v5->m_child.m_childShape;
  v17 = (unsigned __int64)&v23 & 0xFFFFFFFFFFFFFFF0ui64;
  *(hkVector4f *)(v17 + 16) = v5->m_codeInfoCopy;
  *(_QWORD *)(v17 + 32) = v15;
  *(_DWORD *)(v17 + 40) = v14;
  *(_DWORD *)(v17 + 44) = v14;
  *(_BYTE *)(v17 + 48) = 2;
  if ( v16 )
    v16 += 4;
  hkpMoppRayBundleVirtualMachine::queryRayBundle(&v24, v8, v16, (hkpMoppCode *)v17, v7, rayResult, mask);
  v18 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v19 = (_QWORD *)v18[1];
  if ( (unsigned __int64)v19 < v18[3] )
  {
    *v19 = "Et";
    v20 = __rdtsc();
    v21 = (signed __int64)(v19 + 2);
    *(_DWORD *)(v21 - 8) = v20;
    v18[1] = v21;
  }
  return v8;
}

// File Line: 194
// RVA: 0xD0CCB0
void __fastcall hkpMoppBvTreeShape::castRayWithCollector(hkpMoppBvTreeShape *this, hkpShapeRayCastInput *input, hkpCdBody *cdBody, hkpRayHitCollector *collector)
{
  hkpMoppBvTreeShape *v4; // rbx
  hkpRayHitCollector *v5; // rdi
  hkpCdBody *body; // rsi
  hkpShapeRayCastInput *v7; // rbp
  _QWORD *v8; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r10
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  const char *v13; // rax
  unsigned int v14; // ecx
  hkVector4f v15; // xmm0
  hkpShapeContainer *v16; // rdx
  unsigned __int64 v17; // r8
  hkpShape *v18; // rax
  _QWORD *v19; // r8
  _QWORD *v20; // rcx
  unsigned __int64 v21; // rax
  signed __int64 v22; // rcx
  hkpMoppLongRayVirtualMachine v23; // [rsp+30h] [rbp-F8h]
  char v24; // [rsp+DFh] [rbp-49h]

  v4 = this;
  v5 = collector;
  body = cdBody;
  v7 = input;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  v10 = v8;
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtrcMopp";
    v11 = __rdtsc();
    v12 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v12 - 8) = v11;
    v10[1] = v12;
  }
  v13 = v4->m_moppData;
  v14 = v4->m_moppDataSize;
  v15.m_quad = (__m128)v4->m_codeInfoCopy;
  v16 = 0i64;
  v17 = (unsigned __int64)&v24 & 0xFFFFFFFFFFFFFFF0ui64;
  v23.m_ray.m_filterInfo = 0;
  v23.m_ray.m_rayShapeCollectionFilter = 0i64;
  v23.m_ray.m_collidable = 0i64;
  v23.m_ray.m_userData = 0i64;
  *(hkVector4f *)(v17 + 16) = (hkVector4f)v15.m_quad;
  *(_QWORD *)(v17 + 32) = v13;
  v18 = v4->m_child.m_childShape;
  *(_DWORD *)(v17 + 40) = v14;
  *(_DWORD *)(v17 + 44) = v14;
  *(_BYTE *)(v17 + 48) = 2;
  if ( v18 )
    v16 = (hkpShapeContainer *)&v18[1];
  hkpMoppLongRayVirtualMachine::queryLongRay(&v23, v16, (hkpMoppCode *)v17, v7, body, v5);
  v19 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v20 = (_QWORD *)v19[1];
  if ( (unsigned __int64)v20 < v19[3] )
  {
    *v20 = "Et";
    v21 = __rdtsc();
    v22 = (signed __int64)(v20 + 2);
    *(_DWORD *)(v22 - 8) = v21;
    v19[1] = v22;
  }
}

// File Line: 215
// RVA: 0xD0CF00
signed __int64 __fastcall hkpMoppBvTreeShape::calcSizeForSpu(hkpMoppBvTreeShape *this, hkpShape::CalcSizeForSpuInput *input, int spuBufferSizeLeft)
{
  hkpMoppBvTreeShape *v3; // rbx
  char v4; // cl
  signed int v6; // eax

  v3 = this;
  v4 = this->m_code->m_buildType.m_storage;
  if ( (unsigned __int8)v4 > 1u )
    return 0xFFFFFFFFi64;
  if ( v4 == 1 )
    return 0xFFFFFFFFi64;
  v6 = ((__int64 (__fastcall *)(hkpShape *, hkpShape::CalcSizeForSpuInput *, signed __int64))v3->m_child.m_childShape->vfptr[8].__vecDelDtor)(
         v3->m_child.m_childShape,
         input,
         256i64);
  if ( v6 < 0 || v6 > 256 )
    return 0xFFFFFFFFi64;
  v3->m_childSize = v6;
  return 112i64;
}

