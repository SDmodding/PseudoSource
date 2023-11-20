// File Line: 28
// RVA: 0xE7CC20
void __fastcall hkDisplaySerializeIStream::hkDisplaySerializeIStream(hkDisplaySerializeIStream *this, hkStreamReader *reader)
{
  hkDisplaySerializeIStream *v2; // rbx

  v2 = this;
  hkIArchive::hkIArchive((hkIArchive *)&this->vfptr, reader, 0);
  v2->vfptr = (hkBaseObjectVtbl *)&hkDisplaySerializeIStream::`vftable;
}

// File Line: 32
// RVA: 0xE7CC50
void __fastcall hkDisplaySerializeIStream::readQuadVector4(hkDisplaySerializeIStream *this, hkVector4f *v)
{
  hkVector4f *v2; // rbx

  v2 = v;
  hkIArchive::readArrayGeneric((hkIArchive *)&this->vfptr, v, 4, 3);
  v2->m_quad.m128_i32[3] = 0;
}

// File Line: 38
// RVA: 0xE7CC80
void __fastcall hkDisplaySerializeIStream::readTransform(hkDisplaySerializeIStream *this, hkTransformf *t)
{
  hkTransformf *v2; // rdi
  hkDisplaySerializeIStream *v3; // rbx
  hkVector4f array; // [rsp+20h] [rbp-28h]
  hkQuaternionf qi; // [rsp+30h] [rbp-18h]

  v2 = t;
  v3 = this;
  hkIArchive::readArrayGeneric((hkIArchive *)&this->vfptr, &array, 4, 3);
  array.m_quad.m128_i32[3] = (signed int)FLOAT_1_0;
  hkIArchive::readArrayGeneric((hkIArchive *)&v3->vfptr, &qi, 4, 4);
  v2->m_translation = (hkVector4f)array.m_quad;
  hkRotationf::set(&v2->m_rotation, &qi);
}

// File Line: 58
// RVA: 0xE7CCF0
void __fastcall hkDisplaySerializeIStream::readTriangle(hkDisplaySerializeIStream *this, hkGeometry::Triangle *ti)
{
  hkGeometry::Triangle *v2; // rdi
  hkDisplaySerializeIStream *v3; // rbx
  int array; // [rsp+38h] [rbp+10h]

  v2 = ti;
  v3 = this;
  hkIArchive::readArrayGeneric((hkIArchive *)&this->vfptr, &array, 4, 1);
  v2->m_a = array;
  hkIArchive::readArrayGeneric((hkIArchive *)&v3->vfptr, &array, 4, 1);
  v2->m_b = array;
  hkIArchive::readArrayGeneric((hkIArchive *)&v3->vfptr, &array, 4, 1);
  v2->m_c = array;
}

// File Line: 66
// RVA: 0xE7CE40
void __fastcall hkDisplaySerializeIStream::readVectorArray(hkDisplaySerializeIStream *this, hkArray<hkVector4f,hkContainerHeapAllocator> *v)
{
  hkArray<hkVector4f,hkContainerHeapAllocator> *v2; // rbx
  hkDisplaySerializeIStream *v3; // rbp
  __int64 v4; // rsi
  __int64 v5; // rdi
  int v6; // er9
  int v7; // eax
  int v8; // eax
  unsigned int array; // [rsp+60h] [rbp+18h]

  v2 = v;
  v3 = this;
  hkIArchive::readArrayGeneric((hkIArchive *)&this->vfptr, &array, 4, 1);
  if ( (signed int)array > 0 )
  {
    v4 = array;
    do
    {
      v5 = v2->m_size;
      v6 = v5 + 1;
      v7 = v2->m_capacityAndFlags & 0x3FFFFFFF;
      if ( v7 >= (signed int)v5 + 1 )
      {
        array = 0;
      }
      else
      {
        v8 = 2 * v7;
        if ( v6 < v8 )
          v6 = v8;
        hkArrayUtil::_reserve(
          (hkResult *)&array,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          v2,
          v6,
          16);
      }
      ++v2->m_size;
      hkDisplaySerializeIStream::readQuadVector4(v3, &v2->m_data[v5]);
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 77
// RVA: 0xE7CD70
void __fastcall hkDisplaySerializeIStream::readGeometry(hkDisplaySerializeIStream *this, hkGeometry *g)
{
  hkGeometry *v2; // rbx
  hkDisplaySerializeIStream *v3; // rbp
  __int64 v4; // rsi
  __int64 v5; // rdi
  int v6; // er9
  int v7; // eax
  int v8; // eax
  unsigned int array; // [rsp+58h] [rbp+10h]

  v2 = g;
  v3 = this;
  hkDisplaySerializeIStream::readVectorArray(this, &g->m_vertices);
  hkIArchive::readArrayGeneric((hkIArchive *)&v3->vfptr, &array, 4, 1);
  if ( (signed int)array > 0 )
  {
    v4 = array;
    do
    {
      v5 = v2->m_triangles.m_size;
      v6 = v5 + 1;
      v7 = v2->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
      if ( v7 >= (signed int)v5 + 1 )
      {
        array = 0;
      }
      else
      {
        v8 = 2 * v7;
        if ( v6 < v8 )
          v6 = v8;
        hkArrayUtil::_reserve(
          (hkResult *)&array,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &v2->m_triangles,
          v6,
          16);
      }
      ++v2->m_triangles.m_size;
      hkDisplaySerializeIStream::readTriangle(v3, &v2->m_triangles.m_data[v5]);
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 93
// RVA: 0xE7CF10
void __fastcall hkDisplaySerializeIStream::readDisplayGeometry(hkDisplaySerializeIStream *this, hkDisplayGeometry **dg)
{
  hkDisplayGeometry **v2; // r14
  hkDisplaySerializeIStream *v3; // rbx
  _QWORD **v4; // rax
  __int64 v5; // rax
  __int64 v6; // rdi
  hkGeometry *v7; // rsi
  _QWORD **v8; // rax
  hkDisplayConvex *v9; // rax
  __int64 v10; // rax
  _QWORD **v11; // rax
  hkDisplaySphere *v12; // rax
  __int64 v13; // rax
  _QWORD **v14; // rax
  hkDisplayCapsule *v15; // rax
  __int64 v16; // rax
  _QWORD **v17; // rax
  hkDisplayTaperedCapsule *v18; // rax
  __int64 v19; // rax
  _QWORD **v20; // rax
  hkDisplayCylinder *v21; // rax
  __int64 v22; // rax
  _QWORD **v23; // rax
  hkDisplayBox *v24; // rax
  __int64 v25; // rax
  _QWORD **v26; // rax
  hkDisplayAABB *v27; // rax
  hkDisplayGeometry *v28; // rax
  _QWORD **v29; // rax
  hkDisplayCone *v30; // rax
  hkDisplayGeometry *v31; // rax
  _QWORD **v32; // rax
  hkDisplaySemiCircle *v33; // rax
  hkDisplayGeometry *v34; // rax
  __m128 v35; // xmm1
  _QWORD **v36; // rax
  hkDisplayPlane *v37; // rax
  hkDisplayGeometry *v38; // rax
  int v39; // esi
  int v40; // er9
  hkObjectResource *v41; // rbx
  hkMemoryMeshBody *v42; // rsi
  _QWORD **v43; // rax
  hkDisplayMesh *v44; // rax
  hkDisplayGeometry *v45; // rax
  _QWORD **v46; // rax
  hkDisplayWireframe *v47; // rax
  __int64 v48; // rax
  hkVector4f v49; // xmm0
  float topRadius; // [rsp+40h] [rbp-C0h]
  hkSphere sphere; // [rsp+50h] [rbp-B0h]
  float radius; // [rsp+60h] [rbp-A0h]
  hkVector4f v; // [rsp+70h] [rbp-90h]
  hkTransformf t; // [rsp+80h] [rbp-80h]
  hkVector4f normal; // [rsp+C0h] [rbp-40h]
  __int64 v56; // [rsp+D0h] [rbp-30h]
  hkVector4f center; // [rsp+E0h] [rbp-20h]
  __int64 v58; // [rsp+F0h] [rbp-10h]
  unsigned int array; // [rsp+140h] [rbp+40h]
  int xRes; // [rsp+148h] [rbp+48h]

  v2 = dg;
  v3 = this;
  hkIArchive::readArrayGeneric((hkIArchive *)&this->vfptr, &array, 1, 1);
  switch ( (char)array )
  {
    case 1:
      hkDisplaySerializeIStream::readTransform(v3, &t);
      hkIArchive::readArrayGeneric((hkIArchive *)&v3->vfptr, &array, 4, 1);
      hkDisplaySerializeIStream::readQuadVector4(v3, &v);
      sphere.m_pos.m_quad = v.m_quad;
      sphere.m_pos.m_quad.m128_i32[3] = array;
      hkIArchive::readArrayGeneric((hkIArchive *)&v3->vfptr, &xRes, 4, 1);
      hkIArchive::readArrayGeneric((hkIArchive *)&v3->vfptr, &array, 4, 1);
      v11 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v12 = (hkDisplaySphere *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v11[11] + 8i64))(v11[11], 144i64);
      if ( !v12 )
        goto LABEL_9;
      hkDisplaySphere::hkDisplaySphere(v12, &sphere, xRes, array);
      v6 = v13;
      goto LABEL_40;
    case 2:
      hkDisplaySerializeIStream::readTransform(v3, &t);
      hkDisplaySerializeIStream::readQuadVector4(v3, &v);
      v23 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v24 = (hkDisplayBox *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v23[11] + 8i64))(v23[11], 128i64);
      if ( !v24 )
        goto LABEL_9;
      hkDisplayBox::hkDisplayBox(v24, &v);
      v6 = v25;
      goto LABEL_40;
    case 3:
      hkDisplaySerializeIStream::readQuadVector4(v3, &sphere.m_pos);
      hkDisplaySerializeIStream::readQuadVector4(v3, &v);
      v26 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v27 = (hkDisplayAABB *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v26[11] + 8i64))(v26[11], 144i64);
      if ( !v27 )
        goto LABEL_26;
      hkDisplayAABB::hkDisplayAABB(v27, &sphere.m_pos, &v);
      *v2 = v28;
      return;
    case 4:
      hkDisplaySerializeIStream::readQuadVector4(v3, &v);
      hkDisplaySerializeIStream::readQuadVector4(v3, &sphere.m_pos);
      hkIArchive::readArrayGeneric((hkIArchive *)&v3->vfptr, &topRadius, 4, 1);
      hkIArchive::readArrayGeneric((hkIArchive *)&v3->vfptr, &xRes, 4, 1);
      hkIArchive::readArrayGeneric((hkIArchive *)&v3->vfptr, &array, 4, 1);
      v29 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v30 = (hkDisplayCone *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v29[11] + 8i64))(v29[11], 160i64);
      if ( !v30 )
        goto LABEL_26;
      hkDisplayCone::hkDisplayCone(v30, topRadius, *(const float *)&xRes, array, &sphere.m_pos, &v);
      *v2 = v31;
      return;
    case 5:
      hkDisplaySerializeIStream::readQuadVector4(v3, &center);
      hkDisplaySerializeIStream::readQuadVector4(v3, &sphere.m_pos);
      hkDisplaySerializeIStream::readQuadVector4(v3, &v);
      hkIArchive::readArrayGeneric((hkIArchive *)&v3->vfptr, &xRes, 4, 1);
      hkIArchive::readArrayGeneric((hkIArchive *)&v3->vfptr, &radius, 4, 1);
      hkIArchive::readArrayGeneric((hkIArchive *)&v3->vfptr, &topRadius, 4, 1);
      hkIArchive::readArrayGeneric((hkIArchive *)&v3->vfptr, &array, 4, 1);
      v32 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v33 = (hkDisplaySemiCircle *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v32[11] + 8i64))(
                                     v32[11],
                                     176i64);
      if ( !v33 )
        goto LABEL_26;
      hkDisplaySemiCircle::hkDisplaySemiCircle(
        v33,
        &center,
        &sphere.m_pos,
        &v,
        radius,
        topRadius,
        *(const float *)&xRes,
        array);
      *v2 = v34;
      return;
    case 6:
      hkDisplaySerializeIStream::readTransform(v3, &t);
      v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v5 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v4[11] + 8i64))(v4[11], 48i64);
      v6 = 0i64;
      v7 = (hkGeometry *)v5;
      if ( v5 )
      {
        *(_DWORD *)(v5 + 8) = 0x1FFFF;
        *(_QWORD *)v5 = &hkGeometry::`vftable;
        *(_QWORD *)(v5 + 16) = 0i64;
        *(_DWORD *)(v5 + 24) = 0;
        *(_DWORD *)(v5 + 28) = 2147483648;
        *(_QWORD *)(v5 + 32) = 0i64;
        *(_DWORD *)(v5 + 40) = 0;
        *(_DWORD *)(v5 + 44) = 2147483648;
      }
      else
      {
        v7 = 0i64;
      }
      hkDisplaySerializeIStream::readGeometry(v3, v7);
      v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v9 = (hkDisplayConvex *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(v8[11], 112i64);
      if ( v9 )
      {
        hkDisplayConvex::hkDisplayConvex(v9, v7);
        v6 = v10;
      }
      goto LABEL_40;
    case 7:
      hkDisplaySerializeIStream::readQuadVector4(v3, &center);
      hkDisplaySerializeIStream::readQuadVector4(v3, &normal);
      hkDisplaySerializeIStream::readQuadVector4(v3, &v);
      hkIArchive::readArrayGeneric((hkIArchive *)&v3->vfptr, &array, 4, 1);
      v35 = _mm_shuffle_ps((__m128)array, (__m128)array, 0);
      sphere.m_pos.m_quad = _mm_shuffle_ps(v35, _mm_unpackhi_ps(v35, sphere.m_pos.m_quad), 196);
      v36 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v37 = (hkDisplayPlane *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v36[11] + 8i64))(v36[11], 176i64);
      if ( v37 )
      {
        hkDisplayPlane::hkDisplayPlane(v37, &normal, &v, &center, &sphere.m_pos);
        *v2 = v38;
      }
      else
      {
LABEL_26:
        *v2 = 0i64;
      }
      return;
    case 8:
      hkDisplaySerializeIStream::readTransform(v3, &t);
      hkIArchive::readArrayGeneric((hkIArchive *)&v3->vfptr, &radius, 4, 1);
      hkDisplaySerializeIStream::readQuadVector4(v3, &sphere.m_pos);
      hkDisplaySerializeIStream::readQuadVector4(v3, &v);
      hkIArchive::readArrayGeneric((hkIArchive *)&v3->vfptr, &xRes, 4, 1);
      hkIArchive::readArrayGeneric((hkIArchive *)&v3->vfptr, &array, 4, 1);
      v14 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v15 = (hkDisplayCapsule *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v14[11] + 8i64))(v14[11], 160i64);
      if ( !v15 )
        goto LABEL_9;
      hkDisplayCapsule::hkDisplayCapsule(v15, &sphere.m_pos, &v, radius, xRes, array);
      v6 = v16;
      goto LABEL_40;
    case 9:
      hkDisplaySerializeIStream::readTransform(v3, &t);
      hkIArchive::readArrayGeneric((hkIArchive *)&v3->vfptr, &topRadius, 4, 1);
      hkDisplaySerializeIStream::readQuadVector4(v3, &sphere.m_pos);
      hkDisplaySerializeIStream::readQuadVector4(v3, &v);
      hkIArchive::readArrayGeneric((hkIArchive *)&v3->vfptr, &xRes, 4, 1);
      hkIArchive::readArrayGeneric((hkIArchive *)&v3->vfptr, &array, 4, 1);
      v20 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v21 = (hkDisplayCylinder *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v20[11] + 8i64))(
                                   v20[11],
                                   160i64);
      if ( !v21 )
        goto LABEL_9;
      hkDisplayCylinder::hkDisplayCylinder(v21, &sphere.m_pos, &v, topRadius, xRes, array);
      v6 = v22;
      goto LABEL_40;
    case 10:
      hkDisplaySerializeIStream::readTransform(v3, &t);
      hkIArchive::readArrayGeneric((hkIArchive *)&v3->vfptr, &radius, 4, 1);
      hkIArchive::readArrayGeneric((hkIArchive *)&v3->vfptr, &topRadius, 4, 1);
      hkDisplaySerializeIStream::readQuadVector4(v3, &sphere.m_pos);
      hkDisplaySerializeIStream::readQuadVector4(v3, &v);
      hkIArchive::readArrayGeneric((hkIArchive *)&v3->vfptr, &xRes, 4, 1);
      hkIArchive::readArrayGeneric((hkIArchive *)&v3->vfptr, &array, 4, 1);
      v17 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v18 = (hkDisplayTaperedCapsule *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v17[11] + 8i64))(
                                         v17[11],
                                         160i64);
      if ( v18 )
      {
        hkDisplayTaperedCapsule::hkDisplayTaperedCapsule(v18, &sphere.m_pos, &v, topRadius, radius, xRes, array);
        v6 = v19;
      }
      else
      {
LABEL_9:
        v6 = 0i64;
      }
      goto LABEL_40;
    case 11:
      sphere.m_pos.m_quad.m128_u64[0] = 0i64;
      sphere.m_pos.m_quad.m128_u64[1] = 0x8000000000000000i64;
      hkIArchive::readArrayGeneric((hkIArchive *)&v3->vfptr, &array, 4, 1);
      v39 = array;
      if ( (signed int)array > 0 )
      {
        v40 = array;
        if ( (array & 0x80000000) != 0 )
          v40 = 0;
        hkArrayUtil::_reserve(
          (hkResult *)&array,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &sphere,
          v40,
          1);
      }
      sphere.m_pos.m_quad.m128_i32[2] = v39;
      hkIArchive::readRaw((hkIArchive *)&v3->vfptr, (void *)sphere.m_pos.m_quad.m128_u64[0], v39);
      normal.m_quad.m128_i32[0] = 0;
      normal.m_quad.m128_u64[1] = 0i64;
      v56 = 0i64;
      center.m_quad = (__m128)normal.m_quad.m128_u64[0];
      v58 = 0i64;
      v41 = hkSerializeUtil::loadOnHeap(
              (const void *)sphere.m_pos.m_quad.m128_u64[0],
              sphere.m_pos.m_quad.m128_i32[2],
              0i64,
              (hkSerializeUtil::LoadOptions *)&center);
      v42 = hkResource::getContents<hkMemoryMeshBody>((hkResource *)&v41->vfptr);
      hkReferencedObject::addReference((hkReferencedObject *)&v42->vfptr);
      hkReferencedObject::removeReference((hkReferencedObject *)&v41->vfptr);
      v43 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v44 = (hkDisplayMesh *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v43[11] + 8i64))(v43[11], 144i64);
      if ( v44 )
        hkDisplayMesh::hkDisplayMesh(v44, (hkMeshBody *)&v42->vfptr);
      else
        v45 = 0i64;
      *v2 = v45;
      hkReferencedObject::removeReference((hkReferencedObject *)&v42->vfptr);
      sphere.m_pos.m_quad.m128_i32[2] = 0;
      if ( sphere.m_pos.m_quad.m128_i32[3] >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          (void *)sphere.m_pos.m_quad.m128_u64[0],
          sphere.m_pos.m_quad.m128_i32[3] & 0x3FFFFFFF);
      break;
    case 12:
      hkDisplaySerializeIStream::readTransform(v3, &t);
      v46 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v47 = (hkDisplayWireframe *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v46[11] + 8i64))(
                                    v46[11],
                                    128i64);
      if ( v47 )
      {
        hkDisplayWireframe::hkDisplayWireframe(v47);
        v6 = v48;
      }
      else
      {
        v6 = 0i64;
      }
      hkDisplaySerializeIStream::readVectorArray(v3, (hkArray<hkVector4f,hkContainerHeapAllocator> *)(v6 + 112));
LABEL_40:
      v49.m_quad = (__m128)t.m_rotation.m_col0;
      *v2 = (hkDisplayGeometry *)v6;
      *(hkVector4f *)(v6 + 32) = (hkVector4f)v49.m_quad;
      *(hkVector4f *)(v6 + 48) = t.m_rotation.m_col1;
      *(hkVector4f *)(v6 + 64) = t.m_rotation.m_col2;
      *(hkVector4f *)(v6 + 80) = t.m_translation;
      break;
    default:
      return;
  }
}

// File Line: 309
// RVA: 0xE7D800
void __fastcall hkDisplaySerializeIStream::readHash(hkDisplaySerializeIStream *this, unsigned __int64 *hash)
{
  unsigned __int64 *v2; // rbx
  unsigned __int64 array; // [rsp+38h] [rbp+10h]

  v2 = hash;
  hkIArchive::readArrayGeneric((hkIArchive *)&this->vfptr, &array, 8, 1);
  *v2 = array;
}

// File Line: 314
// RVA: 0xE7D840
void __fastcall hkDisplaySerializeIStream::readAabb(hkDisplaySerializeIStream *this, hkAabb *aabb)
{
  hkAabb *v2; // rbx
  hkDisplaySerializeIStream *v3; // rdi

  v2 = aabb;
  v3 = this;
  hkDisplaySerializeIStream::readQuadVector4(this, &aabb->m_min);
  hkDisplaySerializeIStream::readQuadVector4(v3, &v2->m_max);
}

