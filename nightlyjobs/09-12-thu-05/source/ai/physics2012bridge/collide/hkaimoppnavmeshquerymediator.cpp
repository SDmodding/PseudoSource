// File Line: 26
// RVA: 0xC2E5B0
hkpMoppCode *__fastcall hkaiMoppNavMeshQueryMediator::buildCode(hkaiNavMesh *navMesh, hkpMoppCompilerInput *req)
{
  hkpMoppCompilerInput *v2; // rbx
  hkpMoppCode *v3; // rbx
  hkaiNavMeshShapeCollection v5; // [rsp+20h] [rbp-48h]

  v2 = req;
  hkaiNavMeshShapeCollection::hkaiNavMeshShapeCollection(&v5, navMesh);
  v3 = hkpMoppUtility::buildCode((hkpShapeContainer *)&v5.vfptr, v2, 0i64);
  hkaiNavMeshShapeCollection::~hkaiNavMeshShapeCollection(&v5);
  return v3;
}

// File Line: 35
// RVA: 0xC2E590
void __fastcall hkaiMoppNavMeshQueryMediator::hkaiMoppNavMeshQueryMediator(hkaiMoppNavMeshQueryMediator *this, hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiMoppNavMeshQueryMediator::`vftable;
}

// File Line: 39
// RVA: 0xC2E530
void __fastcall hkaiMoppNavMeshQueryMediator::~hkaiMoppNavMeshQueryMediator(hkaiMoppNavMeshQueryMediator *this)
{
  hkaiMoppNavMeshQueryMediator *v1; // rbx
  hkaiNavMesh *v2; // rcx
  hkReferencedObject *v3; // rcx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiMoppNavMeshQueryMediator::`vftable;
  v2 = this->m_navMesh.m_pntr;
  if ( v2 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
  v1->m_navMesh.m_pntr = 0i64;
  v3 = (hkReferencedObject *)&v1->m_code.m_pntr->vfptr;
  if ( v3 )
    hkReferencedObject::removeReference(v3);
  v1->m_code.m_pntr = 0i64;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 42
// RVA: 0xC2E490
void __fastcall hkaiMoppNavMeshQueryMediator::hkaiMoppNavMeshQueryMediator(hkaiMoppNavMeshQueryMediator *this, hkpMoppCode *code, hkaiNavMesh *navMesh)
{
  hkaiNavMesh *v3; // rdi
  hkpMoppCode *v4; // rsi
  hkaiMoppNavMeshQueryMediator *v5; // rbx
  hkReferencedObject *v6; // rcx
  hkReferencedObject *v7; // rcx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v3 = navMesh;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiMoppNavMeshQueryMediator::`vftable;
  v4 = code;
  this->m_code.m_pntr = 0i64;
  this->m_navMesh.m_pntr = 0i64;
  v5 = this;
  if ( code )
    hkReferencedObject::addReference((hkReferencedObject *)&code->vfptr);
  v6 = (hkReferencedObject *)&v5->m_code.m_pntr->vfptr;
  if ( v6 )
    hkReferencedObject::removeReference(v6);
  v5->m_code.m_pntr = v4;
  v5->m_codeInfoCopy = (hkVector4f)v4->m_info;
  if ( v3 )
    hkReferencedObject::addReference((hkReferencedObject *)&v3->vfptr);
  v7 = (hkReferencedObject *)&v5->m_navMesh.m_pntr->vfptr;
  if ( v7 )
    hkReferencedObject::removeReference(v7);
  v5->m_navMesh.m_pntr = v3;
}

// File Line: 58
// RVA: 0xC2F3B0
hkBool *__fastcall hkaiMoppNavMeshFilter::isCollisionEnabled(hkaiMoppNavMeshFilter *this, hkBool *result, hkpShapeRayCastInput *aInput, hkpShapeContainer *hContainer, unsigned int bKey)
{
  hkaiNavMeshQueryMediator::RaycastInput *v5; // r8
  hkBool *v6; // rbx
  hkaiNavMeshInstance *v7; // rdx
  hkaiSpatialQueryHitFilter *v8; // rcx
  hkBool *v9; // rax

  v5 = this->m_input;
  v6 = result;
  v7 = this->m_instance;
  v8 = v5->m_hitFilter;
  if ( !v8
    || ((unsigned int (__fastcall *)(hkaiSpatialQueryHitFilter *, hkaiNavMeshInstance *, _QWORD, _QWORD, unsigned __int64))v8->vfptr[2].__vecDelDtor)(
         v8,
         v7,
         bKey,
         v5->m_filterInfo,
         v5->m_userData) )
  {
    v6->m_bool = 1;
    v9 = v6;
  }
  else
  {
    v6->m_bool = 0;
    v9 = v6;
  }
  return v9;
}

// File Line: 68
// RVA: 0xC2E9E0
__int64 __fastcall hkaiMoppNavMeshQueryMediator::castRay(hkaiMoppNavMeshQueryMediator *this, hkaiNavMeshQueryMediator::RaycastInput *rcInput, hkaiNavMeshQueryMediator::HitDetails *hitOut)
{
  hkaiMoppNavMeshQueryMediator *v3; // r15
  hkaiNavMeshQueryMediator::HitDetails *v4; // r14
  hkaiNavMeshQueryMediator::RaycastInput *v5; // rdi
  _QWORD *v6; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r8
  unsigned __int64 v9; // rax
  signed __int64 v10; // rcx
  __int64 v11; // rsi
  hkaiSpatialQueryHitFilter *v12; // rcx
  int v13; // ebx
  hkaiNavMesh *v14; // rdx
  hkTransformf *v15; // rax
  __m128 v16; // xmm5
  hkVector4f *v17; // rcx
  __m128 v18; // xmm5
  __m128 v19; // xmm3
  __m128 v20; // xmm1
  __m128 v21; // xmm2
  __m128 v22; // xmm1
  __m128 v23; // xmm0
  __m128 v24; // xmm4
  __m128 v25; // xmm5
  __m128 v26; // xmm5
  __m128 v27; // xmm3
  __m128 v28; // xmm1
  __m128 v29; // xmm4
  unsigned int v30; // eax
  hkpCollidable *v31; // rax
  __m128 v32; // xmm2
  __m128 v33; // xmm0
  __m128 v34; // xmm0
  _QWORD *v35; // rax
  _QWORD *v36; // rcx
  _QWORD *v37; // r8
  unsigned __int64 v38; // rax
  signed __int64 v39; // rcx
  void **v41; // [rsp+30h] [rbp-C8h]
  __int64 v42; // [rsp+38h] [rbp-C0h]
  hkaiNavMeshQueryMediator::RaycastInput *v43; // [rsp+40h] [rbp-B8h]
  hkpShapeRayCastInput input; // [rsp+50h] [rbp-A8h]
  unsigned int v45; // [rsp+98h] [rbp-60h]
  int v46; // [rsp+9Ch] [rbp-5Ch]
  int v47; // [rsp+A8h] [rbp-50h]
  int v48; // [rsp+C8h] [rbp-30h]
  hkaiNavMeshShapeCollection v49; // [rsp+D8h] [rbp-20h]
  hkpMoppLongRayVirtualMachine v50; // [rsp+118h] [rbp+20h]
  hkBool result; // [rsp+1E0h] [rbp+E8h]

  v3 = this;
  v4 = hitOut;
  v5 = rcInput;
  v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)v6[1];
  v8 = v6;
  if ( (unsigned __int64)v7 < v6[3] )
  {
    *v7 = "TtMOPP::castRay";
    v9 = __rdtsc();
    v10 = (signed __int64)(v7 + 2);
    *(_DWORD *)(v10 - 8) = v9;
    v8[1] = v10;
  }
  v11 = (__int64)v5->m_instance;
  if ( v11
    && (v12 = v5->m_hitFilter) != 0i64
    && !((unsigned int (__fastcall *)(hkaiSpatialQueryHitFilter *, __int64, _QWORD, unsigned __int64))v12->vfptr[1].__first_virtual_table_function__)(
          v12,
          v11,
          v5->m_filterInfo,
          v5->m_userData) )
  {
    LOBYTE(v13) = 0;
  }
  else
  {
    v14 = v3->m_navMesh.m_pntr;
    v13 = 0;
    v50.m_ray.m_filterInfo = 0;
    v50.m_ray.m_rayShapeCollectionFilter = 0i64;
    v50.m_ray.m_collidable = 0i64;
    v50.m_ray.m_userData = 0i64;
    hkaiNavMeshShapeCollection::hkaiNavMeshShapeCollection(&v49, v14);
    v15 = v5->m_localToWorldTransform;
    v16 = v5->m_from.m_quad;
    input.m_filterInfo = 0;
    input.m_collidable = 0i64;
    v42 = v11;
    v43 = v5;
    input.m_rayShapeCollectionFilter = 0i64;
    v17 = &transform;
    if ( v15 )
      v17 = &v15->m_rotation.m_col0;
    v41 = &hkaiMoppNavMeshFilter::`vftable;
    v18 = _mm_sub_ps(v16, v17[3].m_quad);
    v19 = v17[2].m_quad;
    v20 = _mm_unpacklo_ps(v17->m_quad, v17[1].m_quad);
    v21 = _mm_movelh_ps(v20, v19);
    v22 = _mm_mul_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(_mm_movehl_ps(v21, v20), v19, 212));
    v23 = _mm_shuffle_ps(v18, v18, 0);
    v24 = _mm_mul_ps(
            _mm_shuffle_ps(_mm_unpackhi_ps(v17->m_quad, v17[1].m_quad), v19, 228),
            _mm_shuffle_ps(v18, v18, 170));
    v25 = v5->m_to.m_quad;
    input.m_from.m_quad = _mm_add_ps(_mm_add_ps(v22, _mm_mul_ps(v23, v21)), v24);
    v26 = _mm_sub_ps(v25, v17[3].m_quad);
    v27 = v17[2].m_quad;
    v28 = _mm_unpacklo_ps(v17->m_quad, v17[1].m_quad);
    v29 = _mm_shuffle_ps(_mm_unpackhi_ps(v17->m_quad, v17[1].m_quad), v27, 228);
    input.m_rayShapeCollectionFilter = (hkpRayShapeCollectionFilter *)&v41;
    v30 = v5->m_filterInfo;
    v46 = -1;
    input.m_filterInfo = v30;
    v31 = (hkpCollidable *)v5->m_userData;
    v48 = 0;
    v32 = _mm_movelh_ps(v28, v27);
    input.m_collidable = v31;
    v47 = -1;
    v45 = (unsigned int)FLOAT_1_0;
    input.m_to.m_quad = _mm_add_ps(
                          _mm_add_ps(
                            _mm_mul_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(_mm_movehl_ps(v32, v28), v27, 212)),
                            _mm_mul_ps(_mm_shuffle_ps(v26, v26, 0), v32)),
                          _mm_mul_ps(v29, _mm_shuffle_ps(v26, v26, 170)));
    hkpMoppLongRayVirtualMachine::queryLongRay(
      &v50,
      &result,
      (hkpShapeContainer *)&v49.vfptr,
      v3->m_code.m_pntr,
      &input,
      (hkpShapeRayCastOutput *)&input.m_userData);
    if ( v47 == -1 )
    {
      v4->m_hitFaceKey = -1;
      v34 = query.m_quad;
    }
    else
    {
      if ( v11 && *(_DWORD *)(v11 + 472) > 0 )
        v13 = *(_DWORD *)(v11 + 472);
      v33 = (__m128)v45;
      v4->m_hitFaceKey = v47 | (v13 << 22);
      LOBYTE(v13) = 1;
      v34 = _mm_shuffle_ps(v33, v33, 0);
    }
    v4->m_hitFraction.m_real = v34;
    v41 = &hkpRayShapeCollectionFilter::`vftable;
    hkaiNavMeshShapeCollection::~hkaiNavMeshShapeCollection(&v49);
  }
  v35 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v36 = (_QWORD *)v35[1];
  v37 = v35;
  if ( (unsigned __int64)v36 < v35[3] )
  {
    *v36 = "Et";
    v38 = __rdtsc();
    v39 = (signed __int64)(v36 + 2);
    *(_DWORD *)(v39 - 8) = v38;
    v37[1] = v39;
  }
  return (unsigned __int8)v13;
}

// File Line: 114
// RVA: 0xC2E600
__int64 __fastcall hkaiMoppNavMeshQueryMediator::getClosestPoint(hkaiMoppNavMeshQueryMediator *this, hkaiNavMeshQueryMediator::GetClosestPointInput *gcpInput, hkVector4f *closestPointOut)
{
  hkaiMoppNavMeshQueryMediator *v3; // rbx
  hkaiNavMeshQueryMediator::GetClosestPointInput *v4; // rdi
  _QWORD *v5; // r9
  _QWORD *v6; // rcx
  unsigned __int64 v7; // rax
  signed __int64 v8; // rcx
  hkaiNavMeshInstance *v9; // r13
  hkaiSpatialQueryHitFilter *v10; // rcx
  unsigned int v11; // esi
  hkaiNavMesh *v12; // rdx
  hkVector4f *v13; // rcx
  __m128 v14; // xmm5
  __m128 v15; // xmm3
  __m128 v16; // xmm1
  __m128 v17; // xmm2
  hkpMoppCode *v18; // rdx
  __int64 v19; // r14
  __m128 v20; // xmm0
  __m128 v21; // xmm1
  __m128 v22; // xmm3
  int v23; // er12
  __m128 v24; // xmm6
  int v25; // er15
  float v26; // xmm7_4
  hkaiSpatialQueryHitFilter *v27; // rcx
  unsigned int v28; // ebx
  hkaiNavMeshCutter *v29; // rcx
  int v30; // ebx
  __m128 v31; // xmm1
  __m128 v32; // xmm1
  float v33; // xmm2_4
  unsigned int v34; // edx
  _QWORD *v35; // rax
  _QWORD *v36; // rcx
  _QWORD *v37; // r8
  unsigned __int64 v38; // rax
  signed __int64 v39; // rcx
  hkArray<hkpMoppPrimitiveInfo,hkContainerHeapAllocator> primitives_out; // [rsp+30h] [rbp-C8h]
  hkVector4f position; // [rsp+40h] [rbp-B8h]
  hkVector4f closestPointOuta; // [rsp+50h] [rbp-A8h]
  hkAabb aabb; // [rsp+60h] [rbp-98h]
  hkpMoppObbVirtualMachine v45; // [rsp+B8h] [rbp-40h]
  hkaiNavMesh **retaddr; // [rsp+178h] [rbp+80h]
  signed int v47; // [rsp+180h] [rbp+88h]
  __m128 *v48; // [rsp+188h] [rbp+90h]
  __m128 *v49; // [rsp+190h] [rbp+98h]

  v3 = this;
  v4 = gcpInput;
  v5 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v6 = (_QWORD *)v5[1];
  if ( (unsigned __int64)v6 < v5[3] )
  {
    *v6 = "TtMOPP::GCP";
    v7 = __rdtsc();
    v8 = (signed __int64)(v6 + 2);
    *(_DWORD *)(v8 - 8) = v7;
    v5[1] = v8;
  }
  v9 = v4->m_instance;
  if ( v9 )
  {
    v10 = v4->m_hitFilter;
    if ( v10 )
    {
      if ( !((unsigned int (__fastcall *)(hkaiSpatialQueryHitFilter *, hkaiNavMeshInstance *, _QWORD, unsigned __int64))v10->vfptr[1].__first_virtual_table_function__)(
              v10,
              v9,
              v4->m_filterInfo,
              v4->m_userData) )
      {
        v11 = -1;
        goto LABEL_31;
      }
    }
  }
  v12 = v3->m_navMesh.m_pntr;
  v13 = &transform;
  if ( v4->m_localToWorldTransform )
    v13 = &v4->m_localToWorldTransform->m_rotation.m_col0;
  v49 = &v13->m_quad;
  v14 = _mm_sub_ps(v4->m_position.m_quad, v13[3].m_quad);
  v15 = v13[2].m_quad;
  v16 = _mm_unpacklo_ps(v13->m_quad, v13[1].m_quad);
  v17 = _mm_movelh_ps(v16, v15);
  position.m_quad = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(_mm_movehl_ps(v17, v16), v15, 212)),
                        _mm_mul_ps(_mm_shuffle_ps(v14, v14, 0), v17)),
                      _mm_mul_ps(
                        _mm_shuffle_ps(_mm_unpackhi_ps(v13->m_quad, v13[1].m_quad), v15, 228),
                        _mm_shuffle_ps(v14, v14, 170)));
  hkaiNavMeshShapeCollection::hkaiNavMeshShapeCollection(
    (hkaiNavMeshShapeCollection *)&aabb.m_max.m_quad.m128_u16[4],
    v12);
  v18 = v3->m_code.m_pntr;
  v19 = 0i64;
  v20 = v3->m_codeInfoCopy.m_quad;
  v21 = _mm_add_ps(_mm_sub_ps((__m128)0i64, v4->m_queryRadius.m_real), position.m_quad);
  v22 = _mm_add_ps(position.m_quad, v4->m_queryRadius.m_real);
  primitives_out.m_data = 0i64;
  primitives_out.m_size = 0;
  primitives_out.m_capacityAndFlags = 2147483648;
  aabb.m_min.m_quad = _mm_max_ps(v20, v21);
  v21.m128_f32[0] = 16777216.0 / v3->m_codeInfoCopy.m_quad.m128_f32[3];
  aabb.m_max.m_quad = _mm_min_ps(_mm_add_ps(_mm_shuffle_ps(v21, v21, 0), v3->m_codeInfoCopy.m_quad), v22);
  hkpMoppObbVirtualMachine::queryAabb(&v45, v18, &aabb, &primitives_out);
  if ( !primitives_out.m_size )
  {
    v11 = -1;
    goto LABEL_28;
  }
  v23 = 0;
  if ( v9 && v9->m_runtimeId > 0 )
    v23 = v9->m_runtimeId;
  v24 = position.m_quad;
  v11 = -1;
  v47 = -1;
  v25 = 0;
  v26 = v4->m_queryRadius.m_real.m128_f32[0] * v4->m_queryRadius.m_real.m128_f32[0];
  if ( primitives_out.m_size > 0 )
  {
    while ( 1 )
    {
      v27 = v4->m_hitFilter;
      v28 = *(unsigned int *)((char *)&primitives_out.m_data->ID + v19);
      if ( v27 )
      {
        if ( !((unsigned int (__fastcall *)(hkaiSpatialQueryHitFilter *, hkaiNavMeshInstance *, _QWORD, _QWORD, unsigned __int64))v27->vfptr[2].__vecDelDtor)(
                v27,
                v9,
                v28,
                v4->m_filterInfo,
                v4->m_userData) )
          break;
      }
      v29 = v4->m_navMeshCutter;
      if ( v29 )
      {
        v30 = hkaiNavMeshCutter::getClosestPointOnFaceLocal(v29, &position, v28 | (v23 << 22), &closestPointOuta);
        if ( v30 == -1 )
          break;
        v28 = v30 & 0x3FFFFF;
      }
      else
      {
        hkaiNavMeshUtils::getClosestPointOnFace(retaddr[6], &position, v28, &closestPointOuta);
      }
      v31 = _mm_sub_ps(position.m_quad, closestPointOuta.m_quad);
      v32 = _mm_mul_ps(v31, v31);
      v33 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v32, v32, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v32, v32, 0)))
          + COERCE_FLOAT(_mm_shuffle_ps(v32, v32, 170));
      if ( v33 >= v26 )
        break;
      v26 = v33;
      v34 = v28;
      v47 = v28;
      v24 = closestPointOuta.m_quad;
LABEL_24:
      ++v25;
      v19 += 4i64;
      if ( v25 >= primitives_out.m_size )
      {
        if ( v34 != -1 )
        {
          v11 = v34 | (v23 << 22);
          *v48 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v24, v24, 0), *v49),
                       _mm_mul_ps(_mm_shuffle_ps(v24, v24, 85), v49[1])),
                     _mm_mul_ps(_mm_shuffle_ps(v24, v24, 170), v49[2])),
                   v49[3]);
        }
        LODWORD(v19) = 0;
        goto LABEL_28;
      }
    }
    v34 = v47;
    goto LABEL_24;
  }
LABEL_28:
  primitives_out.m_size = v19;
  if ( primitives_out.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      primitives_out.m_data,
      4 * primitives_out.m_capacityAndFlags);
  primitives_out.m_data = 0i64;
  primitives_out.m_capacityAndFlags = 2147483648;
  hkaiNavMeshShapeCollection::~hkaiNavMeshShapeCollection((hkaiNavMeshShapeCollection *)&aabb.m_max.m_quad.m128_u16[4]);
LABEL_31:
  v35 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v36 = (_QWORD *)v35[1];
  v37 = v35;
  if ( (unsigned __int64)v36 < v35[3] )
  {
    *v36 = "Et";
    v38 = __rdtsc();
    v39 = (signed __int64)(v36 + 2);
    *(_DWORD *)(v39 - 8) = v38;
    v37[1] = v39;
  }
  return v11;
}

// File Line: 216
// RVA: 0xC2ECB0
void __usercall hkaiMoppNavMeshQueryMediator::queryAabb(hkaiMoppNavMeshQueryMediator *this@<rcx>, hkaiNavMeshQueryMediator::AabbQueryInput *input@<rdx>, hkArray<unsigned int,hkContainerTempAllocator> *hits@<r8>, __m128 a4@<xmm1>)
{
  hkaiMoppNavMeshQueryMediator *v4; // rbx
  hkArray<unsigned int,hkContainerTempAllocator> *v5; // rsi
  hkaiNavMeshQueryMediator::AabbQueryInput *v6; // rdi
  _QWORD *v7; // rax
  _QWORD *v8; // rcx
  _QWORD *v9; // r8
  unsigned __int64 v10; // rax
  signed __int64 v11; // rcx
  hkaiNavMeshInstance *v12; // r14
  hkaiSpatialQueryHitFilter *v13; // rcx
  hkTransformf *v14; // rdx
  hkpMoppCode *v15; // rdx
  float v16; // xmm0_4
  __int64 v17; // rbp
  int v18; // eax
  int v19; // eax
  int v20; // er9
  int v21; // er15
  __int64 v22; // rbx
  __int64 v23; // r12
  hkaiSpatialQueryHitFilter *v24; // rcx
  unsigned int v25; // ebp
  _QWORD *v26; // rax
  _QWORD *v27; // rcx
  _QWORD *v28; // r8
  unsigned __int64 v29; // rax
  signed __int64 v30; // rcx
  hkArray<hkpMoppPrimitiveInfo,hkContainerHeapAllocator> primitives_out; // [rsp+30h] [rbp-118h]
  hkSimdFloat32 extraRadius; // [rsp+40h] [rbp-108h]
  hkAabb aabbOut; // [rsp+50h] [rbp-F8h]
  hkAabb aabb; // [rsp+70h] [rbp-D8h]
  hkTransformf BvToWorld; // [rsp+90h] [rbp-B8h]
  hkpMoppObbVirtualMachine v36; // [rsp+D0h] [rbp-78h]
  hkResult result; // [rsp+158h] [rbp+10h]

  v4 = this;
  v5 = hits;
  v6 = input;
  v7 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v8 = (_QWORD *)v7[1];
  v9 = v7;
  if ( (unsigned __int64)v8 < v7[3] )
  {
    *v8 = "TtMOPP::queryAabb";
    v10 = __rdtsc();
    v11 = (signed __int64)(v8 + 2);
    *(_DWORD *)(v11 - 8) = v10;
    v9[1] = v11;
  }
  v12 = v6->m_instance;
  if ( !v12
    || (v13 = v6->m_hitFilter) == 0i64
    || ((unsigned int (__fastcall *)(hkaiSpatialQueryHitFilter *, hkaiNavMeshInstance *, _QWORD, unsigned __int64))v13->vfptr[1].__first_virtual_table_function__)(
         v13,
         v6->m_instance,
         v6->m_filterInfo,
         v6->m_userData) )
  {
    v14 = (hkTransformf *)&transform;
    if ( v6->m_localToWorldTransform )
      v14 = v6->m_localToWorldTransform;
    hkTransformf::setInverse(&BvToWorld, v14);
    extraRadius.m_real = ::aabbOut.m_quad;
    hkAabbUtil::calcAabb(&BvToWorld, &v6->m_aabb, &extraRadius, &aabbOut);
    v15 = v4->m_code.m_pntr;
    aabb.m_min.m_quad = _mm_max_ps(v4->m_codeInfoCopy.m_quad, aabbOut.m_min.m_quad);
    v16 = 16777216.0 / v4->m_codeInfoCopy.m_quad.m128_f32[3];
    primitives_out.m_data = 0i64;
    primitives_out.m_size = 0;
    primitives_out.m_capacityAndFlags = 2147483648;
    a4.m128_f32[0] = v16;
    aabb.m_max.m_quad = _mm_min_ps(
                          _mm_add_ps(_mm_shuffle_ps(a4, a4, 0), v4->m_codeInfoCopy.m_quad),
                          aabbOut.m_max.m_quad);
    hkpMoppObbVirtualMachine::queryAabb(&v36, v15, &aabb, &primitives_out);
    v17 = primitives_out.m_size;
    v18 = v5->m_capacityAndFlags & 0x3FFFFFFF;
    if ( v18 < primitives_out.m_size )
    {
      v19 = 2 * v18;
      v20 = v17;
      if ( (signed int)v17 < v19 )
        v20 = v19;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v5, v20, 4);
    }
    v21 = 0;
    if ( v12 && v12->m_runtimeId > 0 )
      v21 = v12->m_runtimeId;
    v22 = 0i64;
    v23 = v17;
    if ( (signed int)v17 > 0 )
    {
      do
      {
        v24 = v6->m_hitFilter;
        v25 = primitives_out.m_data[v22].ID;
        if ( !v24
          || ((unsigned int (__fastcall *)(hkaiSpatialQueryHitFilter *, hkaiNavMeshInstance *, _QWORD, _QWORD, unsigned __int64))v24->vfptr[2].__vecDelDtor)(
               v24,
               v12,
               v25,
               v6->m_filterInfo,
               v6->m_userData) )
        {
          v5->m_data[v5->m_size++] = v25 | (v21 << 22);
        }
        ++v22;
      }
      while ( v22 < v23 );
    }
    primitives_out.m_size = 0;
    if ( primitives_out.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        primitives_out.m_data,
        4 * primitives_out.m_capacityAndFlags);
    primitives_out.m_data = 0i64;
    primitives_out.m_capacityAndFlags = 2147483648;
  }
  v26 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v27 = (_QWORD *)v26[1];
  v28 = v26;
  if ( (unsigned __int64)v27 < v26[3] )
  {
    *v27 = "Et";
    v29 = __rdtsc();
    v30 = (signed __int64)(v27 + 2);
    *(_DWORD *)(v30 - 8) = v29;
    v28[1] = v30;
  }
}

// File Line: 266
// RVA: 0xC2EF70
__int64 __fastcall hkaiMoppNavMeshQueryMediator::getClosestBoundaryEdge(hkaiMoppNavMeshQueryMediator *this, hkaiNavMeshQueryMediator::GetClosestBoundaryEdgeInput *gcbInput, hkVector4f *closestPointOut)
{
  hkaiMoppNavMeshQueryMediator *v3; // rdi
  hkaiNavMeshQueryMediator::GetClosestBoundaryEdgeInput *v4; // rbx
  _QWORD *v5; // rax
  _QWORD *v6; // rcx
  _QWORD *v7; // r9
  unsigned __int64 v8; // rax
  signed __int64 v9; // rcx
  hkaiNavMeshInstance *v10; // r13
  hkaiSpatialQueryHitFilter *v11; // rcx
  unsigned int v12; // edi
  hkaiNavMesh *v13; // rdx
  hkVector4f *v14; // rcx
  __m128 v15; // xmm5
  __m128 v16; // xmm3
  __m128 v17; // xmm1
  __m128 v18; // xmm2
  hkpMoppCode *v19; // rdx
  __m128 v20; // xmm0
  __m128 v21; // xmm1
  __m128 v22; // xmm3
  int v23; // er12
  __m128 v24; // xmm6
  int v25; // er15
  float v26; // xmm7_4
  __int64 v27; // r14
  hkaiSpatialQueryHitFilter *v28; // rcx
  unsigned int v29; // esi
  hkaiNavMeshCutter *v30; // rcx
  hkVector4f *v31; // r9
  int v32; // eax
  int v33; // eax
  float v34; // xmm0_4
  int v35; // edx
  _QWORD *v36; // rax
  _QWORD *v37; // rcx
  _QWORD *v38; // r8
  unsigned __int64 v39; // rax
  signed __int64 v40; // rcx
  hkArray<hkpMoppPrimitiveInfo,hkContainerHeapAllocator> primitives_out; // [rsp+30h] [rbp-C0h]
  hkVector4f position; // [rsp+40h] [rbp-B0h]
  hkVector4f v44; // [rsp+50h] [rbp-A0h]
  hkAabb aabb; // [rsp+60h] [rbp-90h]
  hkpMoppObbVirtualMachine v46; // [rsp+B0h] [rbp-40h]
  __int64 vars0; // [rsp+170h] [rbp+80h]
  signed int retaddr; // [rsp+178h] [rbp+88h]
  hkaiMoppNavMeshQueryMediator *v49; // [rsp+180h] [rbp+90h]
  __m128 *v50; // [rsp+188h] [rbp+98h]

  v49 = this;
  v3 = this;
  v4 = gcbInput;
  v5 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v6 = (_QWORD *)v5[1];
  v7 = v5;
  if ( (unsigned __int64)v6 < v5[3] )
  {
    *v6 = "TtMOPP::GCBoundary";
    v8 = __rdtsc();
    v9 = (signed __int64)(v6 + 2);
    *(_DWORD *)(v9 - 8) = v8;
    v7[1] = v9;
  }
  v10 = v4->m_instance;
  if ( v10 )
  {
    v11 = v4->m_hitFilter;
    if ( v11 )
    {
      if ( !((unsigned int (__fastcall *)(hkaiSpatialQueryHitFilter *, hkaiNavMeshInstance *, _QWORD, unsigned __int64))v11->vfptr[1].__first_virtual_table_function__)(
              v11,
              v4->m_instance,
              v4->m_filterInfo,
              v4->m_userData) )
      {
        v12 = -1;
        goto LABEL_31;
      }
    }
  }
  v13 = v3->m_navMesh.m_pntr;
  v14 = &transform;
  if ( v4->m_localToWorldTransform )
    v14 = &v4->m_localToWorldTransform->m_rotation.m_col0;
  v50 = &v14->m_quad;
  v15 = _mm_sub_ps(v4->m_position.m_quad, v14[3].m_quad);
  v16 = v14[2].m_quad;
  v17 = _mm_unpacklo_ps(v14->m_quad, v14[1].m_quad);
  v18 = _mm_movelh_ps(v17, v16);
  position.m_quad = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(_mm_movehl_ps(v18, v17), v16, 212)),
                        _mm_mul_ps(_mm_shuffle_ps(v15, v15, 0), v18)),
                      _mm_mul_ps(
                        _mm_shuffle_ps(_mm_unpackhi_ps(v14->m_quad, v14[1].m_quad), v16, 228),
                        _mm_shuffle_ps(v15, v15, 170)));
  hkaiNavMeshShapeCollection::hkaiNavMeshShapeCollection((hkaiNavMeshShapeCollection *)&aabb.m_max, v13);
  v19 = v3->m_code.m_pntr;
  v20 = v3->m_codeInfoCopy.m_quad;
  v21 = _mm_add_ps(_mm_sub_ps((__m128)0i64, v4->m_queryRadius.m_real), position.m_quad);
  v22 = _mm_add_ps(position.m_quad, v4->m_queryRadius.m_real);
  primitives_out.m_data = 0i64;
  primitives_out.m_size = 0;
  primitives_out.m_capacityAndFlags = 2147483648;
  aabb.m_min.m_quad = _mm_max_ps(v20, v21);
  v21.m128_f32[0] = 16777216.0 / v3->m_codeInfoCopy.m_quad.m128_f32[3];
  aabb.m_max.m_quad = _mm_min_ps(_mm_add_ps(_mm_shuffle_ps(v21, v21, 0), v3->m_codeInfoCopy.m_quad), v22);
  hkpMoppObbVirtualMachine::queryAabb(&v46, v19, &aabb, &primitives_out);
  if ( !primitives_out.m_size )
  {
    v12 = -1;
    goto LABEL_28;
  }
  v23 = 0;
  if ( v10 && v10->m_runtimeId > 0 )
    v23 = v10->m_runtimeId;
  v24 = position.m_quad;
  v12 = -1;
  retaddr = -1;
  v25 = 0;
  v26 = v4->m_queryRadius.m_real.m128_f32[0] * v4->m_queryRadius.m_real.m128_f32[0];
  if ( primitives_out.m_size > 0 )
  {
    v27 = 0i64;
    while ( 1 )
    {
      v28 = v4->m_hitFilter;
      v29 = primitives_out.m_data[v27].ID;
      if ( v28 )
      {
        if ( !((unsigned int (__fastcall *)(hkaiSpatialQueryHitFilter *, hkaiNavMeshInstance *, _QWORD, _QWORD, unsigned __int64))v28->vfptr[2].__vecDelDtor)(
                v28,
                v10,
                v29,
                v4->m_filterInfo,
                v4->m_userData) )
          break;
      }
      v30 = v4->m_navMeshCutter;
      v31 = &v4->m_projectionDirection;
      if ( v30 )
      {
        v32 = hkaiNavMeshCutter::getClosestBoundaryOnFaceLocal(v30, &position, v29 | (v23 << 22), v31, &v44);
        if ( v32 == -1 )
          break;
        v33 = v32 & 0x3FFFFF;
      }
      else
      {
        v33 = hkaiNavMeshUtils::getClosestBoundaryOnFace(*(hkaiNavMesh **)(vars0 + 48), &position, v29, v31, &v44);
      }
      LODWORD(v34) = (unsigned __int128)_mm_shuffle_ps(v44.m_quad, v44.m_quad, 255);
      if ( v34 >= v26 )
        break;
      v26 = v34;
      v35 = v33;
      retaddr = v33;
      v24 = v44.m_quad;
LABEL_25:
      ++v25;
      ++v27;
      if ( v25 >= primitives_out.m_size )
      {
        if ( v35 != -1 )
        {
          v12 = v35 | (v23 << 22);
          *(__m128 *)&v49->vfptr = _mm_add_ps(
                                     _mm_add_ps(
                                       _mm_add_ps(
                                         _mm_mul_ps(_mm_shuffle_ps(v24, v24, 85), v50[1]),
                                         _mm_mul_ps(_mm_shuffle_ps(v24, v24, 0), *v50)),
                                       _mm_mul_ps(_mm_shuffle_ps(v24, v24, 170), v50[2])),
                                     v50[3]);
        }
        goto LABEL_28;
      }
    }
    v35 = retaddr;
    goto LABEL_25;
  }
LABEL_28:
  primitives_out.m_size = 0;
  if ( primitives_out.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      primitives_out.m_data,
      4 * primitives_out.m_capacityAndFlags);
  primitives_out.m_data = 0i64;
  primitives_out.m_capacityAndFlags = 2147483648;
  hkaiNavMeshShapeCollection::~hkaiNavMeshShapeCollection((hkaiNavMeshShapeCollection *)&aabb.m_max);
LABEL_31:
  v36 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v37 = (_QWORD *)v36[1];
  v38 = v36;
  if ( (unsigned __int64)v37 < v36[3] )
  {
    *v37 = "Et";
    v39 = __rdtsc();
    v40 = (signed __int64)(v37 + 2);
    *(_DWORD *)(v40 - 8) = v39;
    v38[1] = v40;
  }
  return v12;
}

