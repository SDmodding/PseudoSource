// File Line: 28
// RVA: 0xE7CC20
void __fastcall hkDisplaySerializeIStream::hkDisplaySerializeIStream(
        hkDisplaySerializeIStream *this,
        hkStreamReader *reader)
{
  hkIArchive::hkIArchive(this, reader, 0);
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplaySerializeIStream::`vftable;
}

// File Line: 32
// RVA: 0xE7CC50
void __fastcall hkDisplaySerializeIStream::readQuadVector4(hkDisplaySerializeIStream *this, hkVector4f *v)
{
  hkIArchive::readArrayGeneric(this, v, 4, 3);
  v->m_quad.m128_i32[3] = 0;
}

// File Line: 38
// RVA: 0xE7CC80
void __fastcall hkDisplaySerializeIStream::readTransform(hkDisplaySerializeIStream *this, hkTransformf *t)
{
  hkVector4f array; // [rsp+20h] [rbp-28h] BYREF
  hkQuaternionf qi; // [rsp+30h] [rbp-18h] BYREF

  hkIArchive::readArrayGeneric(this, &array, 4, 3);
  array.m_quad.m128_i32[3] = (int)FLOAT_1_0;
  hkIArchive::readArrayGeneric(this, &qi, 4, 4);
  t->m_translation = (hkVector4f)array.m_quad;
  hkRotationf::set(&t->m_rotation, &qi);
}

// File Line: 58
// RVA: 0xE7CCF0
void __fastcall hkDisplaySerializeIStream::readTriangle(hkDisplaySerializeIStream *this, hkGeometry::Triangle *ti)
{
  int array; // [rsp+38h] [rbp+10h] BYREF

  hkIArchive::readArrayGeneric(this, &array, 4, 1);
  ti->m_a = array;
  hkIArchive::readArrayGeneric(this, &array, 4, 1);
  ti->m_b = array;
  hkIArchive::readArrayGeneric(this, &array, 4, 1);
  ti->m_c = array;
}

// File Line: 66
// RVA: 0xE7CE40
void __fastcall hkDisplaySerializeIStream::readVectorArray(
        hkDisplaySerializeIStream *this,
        hkArray<hkVector4f,hkContainerHeapAllocator> *v)
{
  __int64 m_enum; // rsi
  __int64 m_size; // rdi
  int v6; // r9d
  int v7; // eax
  int v8; // eax
  hkResult array; // [rsp+60h] [rbp+18h] BYREF

  hkIArchive::readArrayGeneric(this, &array, 4, 1);
  if ( array.m_enum > HK_SUCCESS )
  {
    m_enum = (unsigned int)array.m_enum;
    do
    {
      m_size = v->m_size;
      v6 = m_size + 1;
      v7 = v->m_capacityAndFlags & 0x3FFFFFFF;
      if ( v7 >= (int)m_size + 1 )
      {
        array.m_enum = HK_SUCCESS;
      }
      else
      {
        v8 = 2 * v7;
        if ( v6 < v8 )
          v6 = v8;
        hkArrayUtil::_reserve(&array, &hkContainerHeapAllocator::s_alloc, (const void **)&v->m_data, v6, 16);
      }
      ++v->m_size;
      hkDisplaySerializeIStream::readQuadVector4(this, &v->m_data[m_size]);
      --m_enum;
    }
    while ( m_enum );
  }
}

// File Line: 77
// RVA: 0xE7CD70
void __fastcall hkDisplaySerializeIStream::readGeometry(hkDisplaySerializeIStream *this, hkGeometry *g)
{
  __int64 m_enum; // rsi
  __int64 m_size; // rdi
  int v6; // r9d
  int v7; // eax
  int v8; // eax
  hkResult array; // [rsp+58h] [rbp+10h] BYREF

  hkDisplaySerializeIStream::readVectorArray(this, &g->m_vertices);
  hkIArchive::readArrayGeneric(this, &array, 4, 1);
  if ( array.m_enum > HK_SUCCESS )
  {
    m_enum = (unsigned int)array.m_enum;
    do
    {
      m_size = g->m_triangles.m_size;
      v6 = m_size + 1;
      v7 = g->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
      if ( v7 >= (int)m_size + 1 )
      {
        array.m_enum = HK_SUCCESS;
      }
      else
      {
        v8 = 2 * v7;
        if ( v6 < v8 )
          v6 = v8;
        hkArrayUtil::_reserve(&array, &hkContainerHeapAllocator::s_alloc, (const void **)&g->m_triangles.m_data, v6, 16);
      }
      ++g->m_triangles.m_size;
      hkDisplaySerializeIStream::readTriangle(this, &g->m_triangles.m_data[m_size]);
      --m_enum;
    }
    while ( m_enum );
  }
}

// File Line: 93
// RVA: 0xE7CF10
void __fastcall hkDisplaySerializeIStream::readDisplayGeometry(hkDisplaySerializeIStream *this, hkDisplayGeometry **dg)
{
  _QWORD **v4; // rax
  __int64 v5; // rax
  __int64 v6; // rdi
  hkGeometry *v7; // rsi
  _QWORD **v8; // rax
  hkDisplayConvex *v9; // rax
  __int64 v10; // rax
  _QWORD **Value; // rax
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
  int m_enum; // esi
  int v40; // r9d
  hkObjectResource *v41; // rbx
  hkMemoryMeshBody *v42; // rsi
  _QWORD **v43; // rax
  hkDisplayMesh *v44; // rax
  hkDisplayGeometry *v45; // rax
  _QWORD **v46; // rax
  hkDisplayWireframe *v47; // rax
  __int64 v48; // rax
  hkVector4f v49; // xmm0
  float topRadius[4]; // [rsp+40h] [rbp-C0h] BYREF
  hkSphere sphere; // [rsp+50h] [rbp-B0h] BYREF
  float radius[4]; // [rsp+60h] [rbp-A0h] BYREF
  hkVector4f v; // [rsp+70h] [rbp-90h] BYREF
  hkTransformf t; // [rsp+80h] [rbp-80h] BYREF
  hkVector4f normal; // [rsp+C0h] [rbp-40h] BYREF
  __int64 v56; // [rsp+D0h] [rbp-30h]
  hkSerializeUtil::LoadOptions center; // [rsp+E0h] [rbp-20h] BYREF
  hkResult array; // [rsp+140h] [rbp+40h] BYREF
  int xRes; // [rsp+148h] [rbp+48h] BYREF

  hkIArchive::readArrayGeneric(this, &array, 1, 1);
  switch ( LOBYTE(array.m_enum) )
  {
    case 1:
      hkDisplaySerializeIStream::readTransform(this, &t);
      hkIArchive::readArrayGeneric(this, &array, 4, 1);
      hkDisplaySerializeIStream::readQuadVector4(this, &v);
      sphere.m_pos.m_quad = v.m_quad;
      sphere.m_pos.m_quad.m128_u32[3] = array.m_enum;
      hkIArchive::readArrayGeneric(this, &xRes, 4, 1);
      hkIArchive::readArrayGeneric(this, &array, 4, 1);
      Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v12 = (hkDisplaySphere *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 144i64);
      if ( !v12 )
        goto LABEL_9;
      hkDisplaySphere::hkDisplaySphere(v12, &sphere, xRes, array.m_enum);
      v6 = v13;
      goto LABEL_40;
    case 2:
      hkDisplaySerializeIStream::readTransform(this, &t);
      hkDisplaySerializeIStream::readQuadVector4(this, &v);
      v23 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v24 = (hkDisplayBox *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v23[11] + 8i64))(v23[11], 128i64);
      if ( !v24 )
        goto LABEL_9;
      hkDisplayBox::hkDisplayBox(v24, &v);
      v6 = v25;
      goto LABEL_40;
    case 3:
      hkDisplaySerializeIStream::readQuadVector4(this, &sphere.m_pos);
      hkDisplaySerializeIStream::readQuadVector4(this, &v);
      v26 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v27 = (hkDisplayAABB *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v26[11] + 8i64))(v26[11], 144i64);
      if ( !v27 )
        goto LABEL_26;
      hkDisplayAABB::hkDisplayAABB(v27, &sphere.m_pos, &v);
      *dg = v28;
      return;
    case 4:
      hkDisplaySerializeIStream::readQuadVector4(this, &v);
      hkDisplaySerializeIStream::readQuadVector4(this, &sphere.m_pos);
      hkIArchive::readArrayGeneric(this, topRadius, 4, 1);
      hkIArchive::readArrayGeneric(this, &xRes, 4, 1);
      hkIArchive::readArrayGeneric(this, &array, 4, 1);
      v29 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v30 = (hkDisplayCone *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v29[11] + 8i64))(v29[11], 160i64);
      if ( !v30 )
        goto LABEL_26;
      hkDisplayCone::hkDisplayCone(v30, topRadius[0], *(const float *)&xRes, array.m_enum, &sphere.m_pos, &v);
      *dg = v31;
      return;
    case 5:
      hkDisplaySerializeIStream::readQuadVector4(this, (hkVector4f *)&center);
      hkDisplaySerializeIStream::readQuadVector4(this, &sphere.m_pos);
      hkDisplaySerializeIStream::readQuadVector4(this, &v);
      hkIArchive::readArrayGeneric(this, &xRes, 4, 1);
      hkIArchive::readArrayGeneric(this, radius, 4, 1);
      hkIArchive::readArrayGeneric(this, topRadius, 4, 1);
      hkIArchive::readArrayGeneric(this, &array, 4, 1);
      v32 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v33 = (hkDisplaySemiCircle *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v32[11] + 8i64))(v32[11], 176i64);
      if ( !v33 )
        goto LABEL_26;
      hkDisplaySemiCircle::hkDisplaySemiCircle(
        v33,
        (hkVector4f *)&center,
        &sphere.m_pos,
        &v,
        radius[0],
        topRadius[0],
        *(const float *)&xRes,
        array.m_enum);
      *dg = v34;
      return;
    case 6:
      hkDisplaySerializeIStream::readTransform(this, &t);
      v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v5 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v4[11] + 8i64))(v4[11], 48i64);
      v6 = 0i64;
      v7 = (hkGeometry *)v5;
      if ( v5 )
      {
        *(_DWORD *)(v5 + 8) = 0x1FFFF;
        *(_QWORD *)v5 = &hkGeometry::`vftable;
        *(_QWORD *)(v5 + 16) = 0i64;
        *(_DWORD *)(v5 + 24) = 0;
        *(_DWORD *)(v5 + 28) = 0x80000000;
        *(_QWORD *)(v5 + 32) = 0i64;
        *(_DWORD *)(v5 + 40) = 0;
        *(_DWORD *)(v5 + 44) = 0x80000000;
      }
      else
      {
        v7 = 0i64;
      }
      hkDisplaySerializeIStream::readGeometry(this, v7);
      v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v9 = (hkDisplayConvex *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v8[11] + 8i64))(v8[11], 112i64);
      if ( v9 )
      {
        hkDisplayConvex::hkDisplayConvex(v9, v7);
        v6 = v10;
      }
      goto LABEL_40;
    case 7:
      hkDisplaySerializeIStream::readQuadVector4(this, (hkVector4f *)&center);
      hkDisplaySerializeIStream::readQuadVector4(this, &normal);
      hkDisplaySerializeIStream::readQuadVector4(this, &v);
      hkIArchive::readArrayGeneric(this, &array, 4, 1);
      v35 = _mm_shuffle_ps((__m128)(unsigned int)array.m_enum, (__m128)(unsigned int)array.m_enum, 0);
      sphere.m_pos.m_quad = _mm_shuffle_ps(v35, _mm_unpackhi_ps(v35, sphere.m_pos.m_quad), 196);
      v36 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v37 = (hkDisplayPlane *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v36[11] + 8i64))(v36[11], 176i64);
      if ( v37 )
      {
        hkDisplayPlane::hkDisplayPlane(v37, &normal, &v, (hkVector4f *)&center, &sphere.m_pos);
        *dg = v38;
      }
      else
      {
LABEL_26:
        *dg = 0i64;
      }
      return;
    case 8:
      hkDisplaySerializeIStream::readTransform(this, &t);
      hkIArchive::readArrayGeneric(this, radius, 4, 1);
      hkDisplaySerializeIStream::readQuadVector4(this, &sphere.m_pos);
      hkDisplaySerializeIStream::readQuadVector4(this, &v);
      hkIArchive::readArrayGeneric(this, &xRes, 4, 1);
      hkIArchive::readArrayGeneric(this, &array, 4, 1);
      v14 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v15 = (hkDisplayCapsule *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v14[11] + 8i64))(v14[11], 160i64);
      if ( !v15 )
        goto LABEL_9;
      hkDisplayCapsule::hkDisplayCapsule(v15, &sphere.m_pos, &v, radius[0], xRes, array.m_enum);
      v6 = v16;
      goto LABEL_40;
    case 9:
      hkDisplaySerializeIStream::readTransform(this, &t);
      hkIArchive::readArrayGeneric(this, topRadius, 4, 1);
      hkDisplaySerializeIStream::readQuadVector4(this, &sphere.m_pos);
      hkDisplaySerializeIStream::readQuadVector4(this, &v);
      hkIArchive::readArrayGeneric(this, &xRes, 4, 1);
      hkIArchive::readArrayGeneric(this, &array, 4, 1);
      v20 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v21 = (hkDisplayCylinder *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v20[11] + 8i64))(v20[11], 160i64);
      if ( !v21 )
        goto LABEL_9;
      hkDisplayCylinder::hkDisplayCylinder(v21, &sphere.m_pos, &v, topRadius[0], xRes, array.m_enum);
      v6 = v22;
      goto LABEL_40;
    case 0xA:
      hkDisplaySerializeIStream::readTransform(this, &t);
      hkIArchive::readArrayGeneric(this, radius, 4, 1);
      hkIArchive::readArrayGeneric(this, topRadius, 4, 1);
      hkDisplaySerializeIStream::readQuadVector4(this, &sphere.m_pos);
      hkDisplaySerializeIStream::readQuadVector4(this, &v);
      hkIArchive::readArrayGeneric(this, &xRes, 4, 1);
      hkIArchive::readArrayGeneric(this, &array, 4, 1);
      v17 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v18 = (hkDisplayTaperedCapsule *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v17[11] + 8i64))(v17[11], 160i64);
      if ( v18 )
      {
        hkDisplayTaperedCapsule::hkDisplayTaperedCapsule(
          v18,
          &sphere.m_pos,
          &v,
          topRadius[0],
          radius[0],
          xRes,
          array.m_enum);
        v6 = v19;
      }
      else
      {
LABEL_9:
        v6 = 0i64;
      }
      goto LABEL_40;
    case 0xB:
      sphere.m_pos.m_quad.m128_u64[0] = 0i64;
      sphere.m_pos.m_quad.m128_u64[1] = 0x8000000000000000ui64;
      hkIArchive::readArrayGeneric(this, &array, 4, 1);
      m_enum = array.m_enum;
      if ( array.m_enum > HK_SUCCESS )
      {
        v40 = array.m_enum;
        if ( array.m_enum < HK_SUCCESS )
          v40 = 0;
        hkArrayUtil::_reserve(&array, &hkContainerHeapAllocator::s_alloc, (const void **)&sphere, v40, 1);
      }
      sphere.m_pos.m_quad.m128_i32[2] = m_enum;
      hkIArchive::readRaw(this, (void *)sphere.m_pos.m_quad.m128_u64[0], m_enum);
      normal.m_quad.m128_i32[0] = 0;
      normal.m_quad.m128_u64[1] = 0i64;
      v56 = 0i64;
      *(_OWORD *)&center.m_storage = normal.m_quad.m128_u64[0];
      center.m_typeInfoReg = 0i64;
      v41 = hkSerializeUtil::loadOnHeap(
              (const void *)sphere.m_pos.m_quad.m128_u64[0],
              sphere.m_pos.m_quad.m128_i32[2],
              0i64,
              &center);
      v42 = hkResource::getContents<hkMemoryMeshBody>(v41);
      hkReferencedObject::addReference(v42);
      hkReferencedObject::removeReference(v41);
      v43 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v44 = (hkDisplayMesh *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v43[11] + 8i64))(v43[11], 144i64);
      if ( v44 )
        hkDisplayMesh::hkDisplayMesh(v44, v42);
      else
        v45 = 0i64;
      *dg = v45;
      hkReferencedObject::removeReference(v42);
      sphere.m_pos.m_quad.m128_i32[2] = 0;
      if ( sphere.m_pos.m_quad.m128_i32[3] >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          (void *)sphere.m_pos.m_quad.m128_u64[0],
          sphere.m_pos.m_quad.m128_i32[3] & 0x3FFFFFFF);
      return;
    case 0xC:
      hkDisplaySerializeIStream::readTransform(this, &t);
      v46 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v47 = (hkDisplayWireframe *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v46[11] + 8i64))(v46[11], 128i64);
      if ( v47 )
      {
        hkDisplayWireframe::hkDisplayWireframe(v47);
        v6 = v48;
      }
      else
      {
        v6 = 0i64;
      }
      hkDisplaySerializeIStream::readVectorArray(this, (hkArray<hkVector4f,hkContainerHeapAllocator> *)(v6 + 112));
LABEL_40:
      v49.m_quad = (__m128)t.m_rotation.m_col0;
      *dg = (hkDisplayGeometry *)v6;
      *(hkVector4f *)(v6 + 32) = (hkVector4f)v49.m_quad;
      *(hkVector4f *)(v6 + 48) = t.m_rotation.m_col1;
      *(hkVector4f *)(v6 + 64) = t.m_rotation.m_col2;
      *(hkVector4f *)(v6 + 80) = t.m_translation;
      break;
    default:
      return;
  }
}      *dg = (hkDisplayGeometry *)v6;
      *(hkVector4f *)(v6 + 32) = (hkVec

// File Line: 309
// RVA: 0xE7D800
void __fastcall hkDisplaySerializeIStream::readHash(hkDisplaySerializeIStream *this, unsigned __int64 *hash)
{
  unsigned __int64 array; // [rsp+38h] [rbp+10h] BYREF

  hkIArchive::readArrayGeneric(this, &array, 8, 1);
  *hash = array;
}

// File Line: 314
// RVA: 0xE7D840
void __fastcall hkDisplaySerializeIStream::readAabb(hkDisplaySerializeIStream *this, hkAabb *aabb)
{
  hkDisplaySerializeIStream::readQuadVector4(this, &aabb->m_min);
  hkDisplaySerializeIStream::readQuadVector4(this, &aabb->m_max);
}

