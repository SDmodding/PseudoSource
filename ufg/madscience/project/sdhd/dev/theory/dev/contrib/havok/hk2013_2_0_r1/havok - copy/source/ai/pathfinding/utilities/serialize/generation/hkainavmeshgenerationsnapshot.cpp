// File Line: 13
// RVA: 0xBE51F0
void __fastcall hkaiNavMeshGenerationSnapshot::hkaiNavMeshGenerationSnapshot(
        hkaiNavMeshGenerationSnapshot *this,
        hkGeometry *geometry,
        hkaiNavMeshGenerationSettings *settings)
{
  int m_size; // ecx
  hkGeometry::Triangle *m_data; // rax
  int v8; // ecx
  hkVector4f *v9; // rax

  *(_DWORD *)&this->m_geometry.m_memSizeAndFlags = 0x1FFFF;
  this->m_geometry.vfptr = (hkBaseObjectVtbl *)&hkGeometry::`vftable;
  this->m_geometry.m_vertices.m_capacityAndFlags = 0x80000000;
  this->m_geometry.m_vertices.m_data = 0i64;
  this->m_geometry.m_vertices.m_size = 0;
  this->m_geometry.m_triangles.m_data = 0i64;
  this->m_geometry.m_triangles.m_size = 0;
  this->m_geometry.m_triangles.m_capacityAndFlags = 0x80000000;
  hkaiNavMeshGenerationSettings::hkaiNavMeshGenerationSettings(&this->m_settings);
  hkaiNavMeshGenerationSettings::operator=(&this->m_settings, settings);
  m_size = geometry->m_triangles.m_size;
  m_data = geometry->m_triangles.m_data;
  this->m_geometry.m_triangles.m_size = m_size;
  this->m_geometry.m_triangles.m_data = m_data;
  this->m_geometry.m_triangles.m_capacityAndFlags = m_size | 0x80000000;
  v8 = geometry->m_vertices.m_size;
  v9 = geometry->m_vertices.m_data;
  this->m_geometry.m_vertices.m_size = v8;
  this->m_geometry.m_vertices.m_data = v9;
  this->m_geometry.m_vertices.m_capacityAndFlags = v8 | 0x80000000;
}

// File Line: 22
// RVA: 0xBE52B0
void __fastcall hkaiNavMeshGenerationSnapshot::~hkaiNavMeshGenerationSnapshot(hkaiNavMeshGenerationSnapshot *this)
{
  hkaiNavMeshGenerationSettings::~hkaiNavMeshGenerationSettings(&this->m_settings);
  hkGeometry::~hkGeometry(&this->m_geometry);
}

