// File Line: 28
// RVA: 0xE79880
void __fastcall hkDisplaySerializeOStream::hkDisplaySerializeOStream(hkDisplaySerializeOStream *this, hkStreamWriter *writer)
{
  hkDisplaySerializeOStream *v2; // rbx

  v2 = this;
  hkOArchive::hkOArchive((hkOArchive *)&this->vfptr, writer, 0);
  v2->vfptr = (hkBaseObjectVtbl *)&hkDisplaySerializeOStream::`vftable;
}

// File Line: 33
// RVA: 0xE798B0
void __fastcall hkDisplaySerializeOStream::hkDisplaySerializeOStream(hkDisplaySerializeOStream *this, hkArray<char,hkContainerHeapAllocator> *buf)
{
  hkDisplaySerializeOStream *v2; // rbx

  v2 = this;
  hkOArchive::hkOArchive((hkOArchive *)&this->vfptr, buf, 0);
  v2->vfptr = (hkBaseObjectVtbl *)&hkDisplaySerializeOStream::`vftable;
}

// File Line: 37
// RVA: 0xE798E0
void __fastcall hkDisplaySerializeOStream::writeQuadVector4(hkDisplaySerializeOStream *this, hkVector4f *v)
{
  hkOArchive::writeArrayFloat32((hkOArchive *)&this->vfptr, v->m_quad.m128_f32, 3);
}

// File Line: 42
// RVA: 0xE79900
void __fastcall hkDisplaySerializeOStream::writeTransform(hkDisplaySerializeOStream *this, hkTransformf *t)
{
  hkVector4f v2; // xmm1
  hkDisplaySerializeOStream *v3; // rbx
  hkVector4f v4; // xmm0
  float array[4]; // [rsp+20h] [rbp-58h]
  hkQuaternionf v6; // [rsp+30h] [rbp-48h]
  hkRotationf r; // [rsp+40h] [rbp-38h]

  v2.m_quad = (__m128)t->m_rotation.m_col1;
  v3 = this;
  _mm_store_si128((__m128i *)array, (__m128i)t->m_translation.m_quad);
  v4.m_quad = (__m128)t->m_rotation.m_col0;
  r.m_col1 = (hkVector4f)v2.m_quad;
  r.m_col0 = (hkVector4f)v4.m_quad;
  r.m_col2 = t->m_rotation.m_col2;
  hkRotationf::renormalize(&r);
  hkQuaternionf::set(&v6, &r);
  hkOArchive::writeArrayFloat32((hkOArchive *)&v3->vfptr, array, 3);
  hkOArchive::writeArrayFloat32((hkOArchive *)&v3->vfptr, v6.m_vec.m_quad.m128_f32, 4);
}

// File Line: 62
// RVA: 0xE79980
void __fastcall hkDisplaySerializeOStream::writeTriangle(hkDisplaySerializeOStream *this, hkGeometry::Triangle *ti)
{
  hkGeometry::Triangle *v2; // rbx
  hkDisplaySerializeOStream *v3; // rdi

  v2 = ti;
  v3 = this;
  hkOArchive::write32((hkOArchive *)&this->vfptr, ti->m_a);
  hkOArchive::write32((hkOArchive *)&v3->vfptr, v2->m_b);
  hkOArchive::write32((hkOArchive *)&v3->vfptr, v2->m_c);
}

// File Line: 69
// RVA: 0xE79A40
void __fastcall hkDisplaySerializeOStream::writeVectorArray(hkDisplaySerializeOStream *this, hkArrayBase<hkVector4f> *v)
{
  __int64 v2; // rdi
  hkArrayBase<hkVector4f> *v3; // rsi
  hkDisplaySerializeOStream *v4; // rbp
  __int64 v5; // rbx

  v2 = (unsigned int)v->m_size;
  v3 = v;
  v4 = this;
  hkOArchive::write32((hkOArchive *)&this->vfptr, v->m_size);
  if ( (signed int)v2 > 0 )
  {
    v5 = 0i64;
    do
    {
      hkDisplaySerializeOStream::writeQuadVector4(v4, &v3->m_data[v5]);
      ++v5;
      --v2;
    }
    while ( v2 );
  }
}

// File Line: 82
// RVA: 0xE799C0
void __fastcall hkDisplaySerializeOStream::writeGeometry(hkDisplaySerializeOStream *this, hkGeometry *g)
{
  hkGeometry *v2; // rsi
  hkDisplaySerializeOStream *v3; // rbp
  __int64 v4; // rdi
  __int64 v5; // rbx

  v2 = g;
  v3 = this;
  hkDisplaySerializeOStream::writeVectorArray(this, (hkArrayBase<hkVector4f> *)&g->m_vertices.m_data);
  v4 = (unsigned int)v2->m_triangles.m_size;
  hkOArchive::write32((hkOArchive *)&v3->vfptr, v2->m_triangles.m_size);
  if ( (signed int)v4 > 0 )
  {
    v5 = 0i64;
    do
    {
      hkDisplaySerializeOStream::writeTriangle(v3, &v2->m_triangles.m_data[v5]);
      ++v5;
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 98
// RVA: 0xE79EC0
__int64 __fastcall hkDisplaySerializeOStream::computeBytesRequired(hkGeometry *g)
{
  return hkDisplaySerializeOStream::computeBytesRequired((hkArrayBase<hkVector4f> *)&g->m_vertices.m_data)
       + 12 * g->m_triangles.m_size
       + 4;
}

// File Line: 106
// RVA: 0xE79EF0
__int64 __fastcall hkDisplaySerializeOStream::computeBytesRequired(hkArrayBase<hkVector4f> *v)
{
  return (unsigned int)(12 * v->m_size + 4);
}

// File Line: 113
// RVA: 0xE79AB0
void __fastcall hkDisplaySerializeOStream::writeDisplayGeometry(hkDisplaySerializeOStream *this, hkDisplayGeometry *dg)
{
  hkDisplayGeometryType v2; // ebx
  unsigned __int128 v3; // di
  hkVector4f *v4; // rax
  hkVector4f *v5; // rax
  hkVector4f *v6; // rax
  hkVector4f *v7; // rax
  float v8; // xmm0_4
  float v9; // xmm0_4
  int v10; // eax
  hkVector4f *v11; // rax
  hkVector4f *v12; // rax
  hkVector4f *v13; // rax
  float v14; // xmm0_4
  float v15; // xmm0_4
  float v16; // xmm0_4
  int v17; // eax
  hkVector4f *v18; // rax
  hkVector4f *v19; // rax
  hkVector4f *v20; // rax
  hkVector4f *v21; // rax
  int v22; // eax
  unsigned int v23; // ebx
  const char *v24; // rax
  hkVector4f v; // [rsp+20h] [rbp-68h]
  hkVector4f result; // [rsp+30h] [rbp-58h]
  hkVector4f v27; // [rsp+40h] [rbp-48h]
  hkVector4f v28; // [rsp+50h] [rbp-38h]
  hkVector4f v29; // [rsp+60h] [rbp-28h]
  hkVector4f v30; // [rsp+70h] [rbp-18h]

  v2 = dg->m_type;
  v3 = __PAIR__((unsigned __int64)this, (unsigned __int64)dg);
  hkOArchive::write8((hkOArchive *)&this->vfptr, dg->m_type);
  switch ( v2 )
  {
    case 1:
      hkDisplaySerializeOStream::writeTransform(*((hkDisplaySerializeOStream **)&v3 + 1), (hkTransformf *)(v3 + 32));
      v.m_quad = *(__m128 *)(v3 + 112);
      hkOArchive::writeFloat32(*((hkOArchive **)&v3 + 1), *(float *)(v3 + 124));
      hkDisplaySerializeOStream::writeQuadVector4(*((hkDisplaySerializeOStream **)&v3 + 1), &v);
      hkOArchive::write32(*((hkOArchive **)&v3 + 1), *(_DWORD *)(v3 + 128));
      hkOArchive::write32(*((hkOArchive **)&v3 + 1), *(_DWORD *)(v3 + 132));
      break;
    case 2:
      hkDisplaySerializeOStream::writeTransform(*((hkDisplaySerializeOStream **)&v3 + 1), (hkTransformf *)(v3 + 32));
      hkDisplaySerializeOStream::writeQuadVector4(*((hkDisplaySerializeOStream **)&v3 + 1), (hkVector4f *)(v3 + 112));
      break;
    case 3:
      v4 = hkDisplayAABB::getMinExtent((hkDisplayAABB *)v3);
      hkDisplaySerializeOStream::writeQuadVector4(*((hkDisplaySerializeOStream **)&v3 + 1), v4);
      v5 = hkDisplayAABB::getMaxExtent((hkDisplayAABB *)v3);
      hkDisplaySerializeOStream::writeQuadVector4(*((hkDisplaySerializeOStream **)&v3 + 1), v5);
      break;
    case 4:
      v6 = hkDisplayCone::getPosition((hkDisplayCone *)v3, &result);
      hkDisplaySerializeOStream::writeQuadVector4(*((hkDisplaySerializeOStream **)&v3 + 1), v6);
      v7 = hkDisplayCone::getAxis((hkDisplayCone *)v3, &v27);
      hkDisplaySerializeOStream::writeQuadVector4(*((hkDisplaySerializeOStream **)&v3 + 1), v7);
      v8 = hkDisplayCone::getAngle((hkDisplayCone *)v3);
      hkOArchive::writeFloat32(*((hkOArchive **)&v3 + 1), v8);
      v9 = hkDisplayCone::getHeight((hkDisplayCone *)v3);
      hkOArchive::writeFloat32(*((hkOArchive **)&v3 + 1), v9);
      v10 = hkDisplayCone::getNumSegments((hkDisplayCone *)v3);
      hkOArchive::write32(*((hkOArchive **)&v3 + 1), v10);
      break;
    case 5:
      v11 = hkDisplaySemiCircle::getCenter((hkDisplaySemiCircle *)v3, &v28);
      hkDisplaySerializeOStream::writeQuadVector4(*((hkDisplaySerializeOStream **)&v3 + 1), v11);
      v12 = hkDisplaySemiCircle::getNormal((hkDisplaySemiCircle *)v3, &v29);
      hkDisplaySerializeOStream::writeQuadVector4(*((hkDisplaySerializeOStream **)&v3 + 1), v12);
      v13 = hkDisplaySemiCircle::getPerp((hkDisplaySemiCircle *)v3, &v30);
      hkDisplaySerializeOStream::writeQuadVector4(*((hkDisplaySerializeOStream **)&v3 + 1), v13);
      v14 = hkDisplaySemiCircle::getRadius((hkDisplaySemiCircle *)v3);
      hkOArchive::writeFloat32(*((hkOArchive **)&v3 + 1), v14);
      v15 = hkDisplaySemiCircle::getThetaMin((hkDisplaySemiCircle *)v3);
      hkOArchive::writeFloat32(*((hkOArchive **)&v3 + 1), v15);
      v16 = hkDisplaySemiCircle::getThetaMax((hkDisplaySemiCircle *)v3);
      hkOArchive::writeFloat32(*((hkOArchive **)&v3 + 1), v16);
      v17 = hkDisplaySemiCircle::getNumSegments((hkDisplaySemiCircle *)v3);
      hkOArchive::write32(*((hkOArchive **)&v3 + 1), v17);
      break;
    case 6:
      hkDisplaySerializeOStream::writeTransform(*((hkDisplaySerializeOStream **)&v3 + 1), (hkTransformf *)(v3 + 32));
      hkDisplaySerializeOStream::writeGeometry(*((hkDisplaySerializeOStream **)&v3 + 1), *(hkGeometry **)(v3 + 16));
      break;
    case 7:
      v18 = hkDisplayPlane::getCenter((hkDisplayPlane *)v3);
      hkDisplaySerializeOStream::writeQuadVector4(*((hkDisplaySerializeOStream **)&v3 + 1), v18);
      v19 = hkDisplayPlane::getNormal((hkDisplayPlane *)v3);
      hkDisplaySerializeOStream::writeQuadVector4(*((hkDisplaySerializeOStream **)&v3 + 1), v19);
      v20 = hkDisplayPlane::getPerpToNormal((hkDisplayPlane *)v3);
      hkDisplaySerializeOStream::writeQuadVector4(*((hkDisplaySerializeOStream **)&v3 + 1), v20);
      v21 = hkDisplayPlane::getExtents((hkDisplayPlane *)v3);
      hkOArchive::writeFloat32(*((hkOArchive **)&v3 + 1), v21->m_quad.m128_f32[0]);
      break;
    case 8:
    case 9:
      hkDisplaySerializeOStream::writeTransform(*((hkDisplaySerializeOStream **)&v3 + 1), (hkTransformf *)(v3 + 32));
      hkOArchive::writeFloat32(*((hkOArchive **)&v3 + 1), *(float *)(v3 + 144));
      hkDisplaySerializeOStream::writeQuadVector4(*((hkDisplaySerializeOStream **)&v3 + 1), (hkVector4f *)(v3 + 112));
      hkDisplaySerializeOStream::writeQuadVector4(*((hkDisplaySerializeOStream **)&v3 + 1), (hkVector4f *)(v3 + 128));
      hkOArchive::write32(*((hkOArchive **)&v3 + 1), *(_DWORD *)(v3 + 148));
      hkOArchive::write32(*((hkOArchive **)&v3 + 1), *(_DWORD *)(v3 + 152));
      break;
    case 10:
      hkDisplaySerializeOStream::writeTransform(*((hkDisplaySerializeOStream **)&v3 + 1), (hkTransformf *)(v3 + 32));
      hkOArchive::writeFloat32(*((hkOArchive **)&v3 + 1), *(float *)(v3 + 148));
      hkOArchive::writeFloat32(*((hkOArchive **)&v3 + 1), *(float *)(v3 + 144));
      hkDisplaySerializeOStream::writeQuadVector4(*((hkDisplaySerializeOStream **)&v3 + 1), (hkVector4f *)(v3 + 112));
      hkDisplaySerializeOStream::writeQuadVector4(*((hkDisplaySerializeOStream **)&v3 + 1), (hkVector4f *)(v3 + 128));
      hkOArchive::write32(*((hkOArchive **)&v3 + 1), *(_DWORD *)(v3 + 152));
      hkOArchive::write32(*((hkOArchive **)&v3 + 1), *(_DWORD *)(v3 + 156));
      break;
    case 11:
      v22 = hkDisplayMesh::getSeriaizedMeshDataSize((hkDisplayMesh *)v3);
      hkOArchive::write32(*((hkOArchive **)&v3 + 1), v22);
      v23 = hkDisplayMesh::getSeriaizedMeshDataSize((hkDisplayMesh *)v3);
      v24 = hkDisplayMesh::getSeriaizedMeshData((hkDisplayMesh *)v3);
      hkOArchive::writeRaw(*((hkOArchive **)&v3 + 1), v24, v23);
      hkDisplayMesh::freeSerializedMeshData((hkDisplayMesh *)v3);
      break;
    case 12:
      hkDisplaySerializeOStream::writeTransform(*((hkDisplaySerializeOStream **)&v3 + 1), (hkTransformf *)(v3 + 32));
      hkDisplaySerializeOStream::writeVectorArray(
        *((hkDisplaySerializeOStream **)&v3 + 1),
        (hkArrayBase<hkVector4f> *)(v3 + 112));
      break;
    default:
      return;
  }
}

// File Line: 250
// RVA: 0xE79F10
signed __int64 __fastcall hkDisplaySerializeOStream::computeBytesRequired(hkDisplayGeometry *dg)
{
  hkDisplayMesh *v1; // rbx
  unsigned int v2; // er8
  signed __int64 result; // rax

  v1 = (hkDisplayMesh *)dg;
  v2 = 1;
  switch ( dg->m_type )
  {
    case 1:
    case 5:
      result = 53i64;
      break;
    case 2:
    case 7:
      result = 41i64;
      break;
    case 3:
      result = 25i64;
      break;
    case 4:
      result = 37i64;
      break;
    case 6:
      result = (unsigned int)hkDisplaySerializeOStream::computeBytesRequired(dg->m_geometry) + 29;
      break;
    case 8:
    case 9:
      result = 65i64;
      break;
    case 0xA:
      result = 69i64;
      break;
    case 0xB:
      hkDisplayMesh::serializeMeshData((hkDisplayMesh *)dg);
      result = (unsigned int)(hkDisplayMesh::getSeriaizedMeshDataSize(v1) + 5);
      break;
    case 0xC:
      v2 = (unsigned __int64)hkDisplaySerializeOStream::computeBytesRequired((hkArrayBase<hkVector4f> *)&dg[1]) + 29;
      goto LABEL_11;
    default:
LABEL_11:
      result = v2;
      break;
  }
  return result;
}

// File Line: 398
// RVA: 0xE79E70
void __fastcall hkDisplaySerializeOStream::writeHash(hkDisplaySerializeOStream *this, const unsigned __int64 *hash)
{
  hkOArchive::write64u((hkOArchive *)&this->vfptr, *hash);
}

// File Line: 403
// RVA: 0xE79E80
void __fastcall hkDisplaySerializeOStream::writeAabb(hkDisplaySerializeOStream *this, hkAabb *aabb)
{
  hkAabb *v2; // rbx
  hkDisplaySerializeOStream *v3; // rdi

  v2 = aabb;
  v3 = this;
  hkDisplaySerializeOStream::writeQuadVector4(this, &aabb->m_min);
  hkDisplaySerializeOStream::writeQuadVector4(v3, &v2->m_max);
}

