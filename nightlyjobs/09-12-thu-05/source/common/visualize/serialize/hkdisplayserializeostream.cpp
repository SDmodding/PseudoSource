// File Line: 28
// RVA: 0xE79880
void __fastcall hkDisplaySerializeOStream::hkDisplaySerializeOStream(
        hkDisplaySerializeOStream *this,
        hkStreamWriter *writer)
{
  hkOArchive::hkOArchive(this, writer, 0);
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplaySerializeOStream::`vftable;
}

// File Line: 33
// RVA: 0xE798B0
void __fastcall hkDisplaySerializeOStream::hkDisplaySerializeOStream(
        hkDisplaySerializeOStream *this,
        hkArray<char,hkContainerHeapAllocator> *buf)
{
  hkOArchive::hkOArchive(this, buf, 0);
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplaySerializeOStream::`vftable;
}

// File Line: 37
// RVA: 0xE798E0
void __fastcall hkDisplaySerializeOStream::writeQuadVector4(hkDisplaySerializeOStream *this, hkVector4f *v)
{
  hkOArchive::writeArrayFloat32(this, v->m_quad.m128_f32, 3);
}

// File Line: 42
// RVA: 0xE79900
void __fastcall hkDisplaySerializeOStream::writeTransform(hkDisplaySerializeOStream *this, hkTransformf *t)
{
  hkVector4f v2; // xmm1
  hkVector4f v4; // xmm0
  float array[4]; // [rsp+20h] [rbp-58h] BYREF
  hkQuaternionf v6; // [rsp+30h] [rbp-48h] BYREF
  hkRotationf r; // [rsp+40h] [rbp-38h] BYREF

  v2.m_quad = (__m128)t->m_rotation.m_col1;
  *(hkVector4f *)array = t->m_translation;
  v4.m_quad = (__m128)t->m_rotation.m_col0;
  r.m_col1 = (hkVector4f)v2.m_quad;
  r.m_col0 = (hkVector4f)v4.m_quad;
  r.m_col2 = t->m_rotation.m_col2;
  hkRotationf::renormalize(&r);
  hkQuaternionf::set(&v6, &r);
  hkOArchive::writeArrayFloat32(this, array, 3);
  hkOArchive::writeArrayFloat32(this, v6.m_vec.m_quad.m128_f32, 4);
}

// File Line: 62
// RVA: 0xE79980
void __fastcall hkDisplaySerializeOStream::writeTriangle(hkDisplaySerializeOStream *this, hkGeometry::Triangle *ti)
{
  hkOArchive::write32(this, ti->m_a);
  hkOArchive::write32(this, ti->m_b);
  hkOArchive::write32(this, ti->m_c);
}

// File Line: 69
// RVA: 0xE79A40
void __fastcall hkDisplaySerializeOStream::writeVectorArray(
        hkDisplaySerializeOStream *this,
        hkArrayBase<hkVector4f> *v)
{
  __int64 m_size; // rdi
  __int64 v5; // rbx

  m_size = (unsigned int)v->m_size;
  hkOArchive::write32(this, v->m_size);
  if ( (int)m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      hkDisplaySerializeOStream::writeQuadVector4(this, &v->m_data[v5++]);
      --m_size;
    }
    while ( m_size );
  }
}

// File Line: 82
// RVA: 0xE799C0
void __fastcall hkDisplaySerializeOStream::writeGeometry(hkDisplaySerializeOStream *this, hkGeometry *g)
{
  __int64 m_size; // rdi
  __int64 v5; // rbx

  hkDisplaySerializeOStream::writeVectorArray(this, &g->m_vertices);
  m_size = (unsigned int)g->m_triangles.m_size;
  hkOArchive::write32(this, g->m_triangles.m_size);
  if ( (int)m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      hkDisplaySerializeOStream::writeTriangle(this, &g->m_triangles.m_data[v5++]);
      --m_size;
    }
    while ( m_size );
  }
}

// File Line: 98
// RVA: 0xE79EC0
__int64 __fastcall hkDisplaySerializeOStream::computeBytesRequired(hkGeometry *g)
{
  return hkDisplaySerializeOStream::computeBytesRequired(&g->m_vertices) + 12 * g->m_triangles.m_size + 4;
}

// File Line: 106
// RVA: 0xE79EF0
__int64 __fastcall hkDisplaySerializeOStream::computeBytesRequired(hkArrayBase<hkVector4f> *v)
{
  return (unsigned int)(12 * v->m_size + 4);
}

// File Line: 113
// RVA: 0xE79AB0
void __fastcall hkDisplaySerializeOStream::writeDisplayGeometry(hkDisplaySerializeOStream *this, hkDisplayAABB *dg)
{
  hkDisplayGeometryType m_type; // ebx
  hkVector4f *MinExtent; // rax
  hkVector4f *MaxExtent; // rax
  hkVector4f *Position; // rax
  hkVector4f *Axis; // rax
  float Angle; // xmm0_4
  float Height; // xmm0_4
  int NumSegments; // eax
  hkVector4f *Center; // rax
  hkVector4f *Normal; // rax
  hkVector4f *Perp; // rax
  float Radius; // xmm0_4
  float ThetaMin; // xmm0_4
  float ThetaMax; // xmm0_4
  int v18; // eax
  hkVector4f *v19; // rax
  hkVector4f *v20; // rax
  hkVector4f *PerpToNormal; // rax
  hkVector4f *Extents; // rax
  int SeriaizedMeshDataSize; // eax
  unsigned int v24; // ebx
  const char *SeriaizedMeshData; // rax
  hkVector4f v; // [rsp+20h] [rbp-68h] BYREF
  hkVector4f result; // [rsp+30h] [rbp-58h] BYREF
  hkVector4f v28; // [rsp+40h] [rbp-48h] BYREF
  hkVector4f v29; // [rsp+50h] [rbp-38h] BYREF
  hkVector4f v30; // [rsp+60h] [rbp-28h] BYREF
  hkVector4f v31; // [rsp+70h] [rbp-18h] BYREF

  m_type = dg->m_type;
  hkOArchive::write8(this, m_type);
  switch ( m_type )
  {
    case HK_DISPLAY_SPHERE:
      hkDisplaySerializeOStream::writeTransform(this, &dg->m_transform);
      v.m_quad = (__m128)dg->m_minExtent;
      hkOArchive::writeFloat32(this, dg->m_minExtent.m_quad.m128_f32[3]);
      hkDisplaySerializeOStream::writeQuadVector4(this, &v);
      hkOArchive::write32(this, dg->m_maxExtent.m_quad.m128_i32[0]);
      hkOArchive::write32(this, dg->m_maxExtent.m_quad.m128_i32[1]);
      break;
    case HK_DISPLAY_BOX:
      hkDisplaySerializeOStream::writeTransform(this, &dg->m_transform);
      hkDisplaySerializeOStream::writeQuadVector4(this, &dg->m_minExtent);
      break;
    case HK_DISPLAY_AABB:
      MinExtent = hkDisplayAABB::getMinExtent(dg);
      hkDisplaySerializeOStream::writeQuadVector4(this, MinExtent);
      MaxExtent = hkDisplayAABB::getMaxExtent(dg);
      hkDisplaySerializeOStream::writeQuadVector4(this, MaxExtent);
      break;
    case HK_DISPLAY_CONE:
      Position = hkDisplayCone::getPosition((hkDisplayCone *)dg, &result);
      hkDisplaySerializeOStream::writeQuadVector4(this, Position);
      Axis = hkDisplayCone::getAxis((hkDisplayCone *)dg, &v28);
      hkDisplaySerializeOStream::writeQuadVector4(this, Axis);
      Angle = hkDisplayCone::getAngle((hkDisplayCone *)dg);
      hkOArchive::writeFloat32(this, Angle);
      Height = hkDisplayCone::getHeight((hkDisplayCone *)dg);
      hkOArchive::writeFloat32(this, Height);
      NumSegments = hkDisplayCone::getNumSegments((hkDisplayCone *)dg);
      hkOArchive::write32(this, NumSegments);
      break;
    case HK_DISPLAY_SEMICIRCLE:
      Center = hkDisplaySemiCircle::getCenter((hkDisplaySemiCircle *)dg, &v29);
      hkDisplaySerializeOStream::writeQuadVector4(this, Center);
      Normal = hkDisplaySemiCircle::getNormal((hkDisplaySemiCircle *)dg, &v30);
      hkDisplaySerializeOStream::writeQuadVector4(this, Normal);
      Perp = hkDisplaySemiCircle::getPerp((hkDisplaySemiCircle *)dg, &v31);
      hkDisplaySerializeOStream::writeQuadVector4(this, Perp);
      Radius = hkDisplaySemiCircle::getRadius((hkDisplaySemiCircle *)dg);
      hkOArchive::writeFloat32(this, Radius);
      ThetaMin = hkDisplaySemiCircle::getThetaMin((hkDisplaySemiCircle *)dg);
      hkOArchive::writeFloat32(this, ThetaMin);
      ThetaMax = hkDisplaySemiCircle::getThetaMax((hkDisplaySemiCircle *)dg);
      hkOArchive::writeFloat32(this, ThetaMax);
      v18 = hkDisplaySemiCircle::getNumSegments((hkDisplaySemiCircle *)dg);
      hkOArchive::write32(this, v18);
      break;
    case HK_DISPLAY_CONVEX:
      hkDisplaySerializeOStream::writeTransform(this, &dg->m_transform);
      hkDisplaySerializeOStream::writeGeometry(this, dg->m_geometry);
      break;
    case HK_DISPLAY_PLANE:
      v19 = hkDisplayPlane::getCenter((hkDisplayPlane *)dg);
      hkDisplaySerializeOStream::writeQuadVector4(this, v19);
      v20 = hkDisplayPlane::getNormal((hkDisplayPlane *)dg);
      hkDisplaySerializeOStream::writeQuadVector4(this, v20);
      PerpToNormal = hkDisplayPlane::getPerpToNormal((hkDisplayPlane *)dg);
      hkDisplaySerializeOStream::writeQuadVector4(this, PerpToNormal);
      Extents = hkDisplayPlane::getExtents((hkDisplayPlane *)dg);
      hkOArchive::writeFloat32(this, Extents->m_quad.m128_f32[0]);
      break;
    case HK_DISPLAY_CAPSULE:
    case HK_DISPLAY_CYLINDER:
      hkDisplaySerializeOStream::writeTransform(this, &dg->m_transform);
      hkOArchive::writeFloat32(this, *(float *)&dg[1].vfptr);
      hkDisplaySerializeOStream::writeQuadVector4(this, &dg->m_minExtent);
      hkDisplaySerializeOStream::writeQuadVector4(this, &dg->m_maxExtent);
      hkOArchive::write32(this, HIDWORD(dg[1].vfptr));
      hkOArchive::write32(this, *(_DWORD *)&dg[1].m_memSizeAndFlags);
      break;
    case HK_DISPLAY_TAPERED_CAPSULE:
      hkDisplaySerializeOStream::writeTransform(this, &dg->m_transform);
      hkOArchive::writeFloat32(this, *((float *)&dg[1].vfptr + 1));
      hkOArchive::writeFloat32(this, *(float *)&dg[1].vfptr);
      hkDisplaySerializeOStream::writeQuadVector4(this, &dg->m_minExtent);
      hkDisplaySerializeOStream::writeQuadVector4(this, &dg->m_maxExtent);
      hkOArchive::write32(this, *(_DWORD *)&dg[1].m_memSizeAndFlags);
      hkOArchive::write32(this, *(_DWORD *)(&dg[1].m_referenceCount + 1));
      break;
    case HK_DISPLAY_MESH:
      SeriaizedMeshDataSize = hkDisplayMesh::getSeriaizedMeshDataSize((hkDisplayMesh *)dg);
      hkOArchive::write32(this, SeriaizedMeshDataSize);
      v24 = hkDisplayMesh::getSeriaizedMeshDataSize((hkDisplayMesh *)dg);
      SeriaizedMeshData = hkDisplayMesh::getSeriaizedMeshData((hkDisplayMesh *)dg);
      hkOArchive::writeRaw(this, SeriaizedMeshData, v24);
      hkDisplayMesh::freeSerializedMeshData((hkDisplayMesh *)dg);
      break;
    case HK_DISPLAY_WIREFRAME:
      hkDisplaySerializeOStream::writeTransform(this, &dg->m_transform);
      hkDisplaySerializeOStream::writeVectorArray(this, (hkArrayBase<hkVector4f> *)&dg->m_minExtent);
      break;
    default:
      return;
  }
}

// File Line: 250
// RVA: 0xE79F10
__int64 __fastcall hkDisplaySerializeOStream::computeBytesRequired(hkDisplayMesh *dg)
{
  unsigned int v2; // r8d
  __int64 result; // rax

  v2 = 1;
  switch ( dg->m_type )
  {
    case HK_DISPLAY_SPHERE:
    case HK_DISPLAY_SEMICIRCLE:
      result = 53i64;
      break;
    case HK_DISPLAY_BOX:
    case HK_DISPLAY_PLANE:
      result = 41i64;
      break;
    case HK_DISPLAY_AABB:
      result = 25i64;
      break;
    case HK_DISPLAY_CONE:
      result = 37i64;
      break;
    case HK_DISPLAY_CONVEX:
      result = (unsigned int)hkDisplaySerializeOStream::computeBytesRequired(dg->m_geometry) + 29;
      break;
    case HK_DISPLAY_CAPSULE:
    case HK_DISPLAY_CYLINDER:
      result = 65i64;
      break;
    case HK_DISPLAY_TAPERED_CAPSULE:
      result = 69i64;
      break;
    case HK_DISPLAY_MESH:
      hkDisplayMesh::serializeMeshData(dg);
      result = (unsigned int)(hkDisplayMesh::getSeriaizedMeshDataSize(dg) + 5);
      break;
    case HK_DISPLAY_WIREFRAME:
      v2 = hkDisplaySerializeOStream::computeBytesRequired((hkArrayBase<hkVector4f> *)&dg->m_mesh) + 29;
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
  hkOArchive::write64u(this, *hash);
}

// File Line: 403
// RVA: 0xE79E80
void __fastcall hkDisplaySerializeOStream::writeAabb(hkDisplaySerializeOStream *this, hkAabb *aabb)
{
  hkDisplaySerializeOStream::writeQuadVector4(this, &aabb->m_min);
  hkDisplaySerializeOStream::writeQuadVector4(this, &aabb->m_max);
}

