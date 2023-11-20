// File Line: 13
// RVA: 0xBE51F0
void __fastcall hkaiNavMeshGenerationSnapshot::hkaiNavMeshGenerationSnapshot(hkaiNavMeshGenerationSnapshot *this, hkGeometry *geometry, hkaiNavMeshGenerationSettings *settings)
{
  hkaiNavMeshGenerationSnapshot *v3; // r14
  hkaiNavMeshGenerationSettings *v4; // rdi
  hkGeometry *v5; // rsi
  int v6; // ecx
  hkGeometry::Triangle *v7; // rax
  int v8; // ecx
  hkVector4f *v9; // rax

  *(_DWORD *)&this->m_geometry.m_memSizeAndFlags = 0x1FFFF;
  v3 = this;
  this->m_geometry.vfptr = (hkBaseObjectVtbl *)&hkGeometry::`vftable';
  this->m_geometry.m_vertices.m_capacityAndFlags = 2147483648;
  this->m_geometry.m_vertices.m_data = 0i64;
  this->m_geometry.m_vertices.m_size = 0;
  this->m_geometry.m_triangles.m_data = 0i64;
  this->m_geometry.m_triangles.m_size = 0;
  this->m_geometry.m_triangles.m_capacityAndFlags = 2147483648;
  v4 = settings;
  v5 = geometry;
  hkaiNavMeshGenerationSettings::hkaiNavMeshGenerationSettings(&this->m_settings);
  hkaiNavMeshGenerationSettings::operator=(&v3->m_settings, v4);
  v6 = v5->m_triangles.m_size;
  v7 = v5->m_triangles.m_data;
  v3->m_geometry.m_triangles.m_size = v6;
  v3->m_geometry.m_triangles.m_data = v7;
  v3->m_geometry.m_triangles.m_capacityAndFlags = v6 | 0x80000000;
  v8 = v5->m_vertices.m_size;
  v9 = v5->m_vertices.m_data;
  v3->m_geometry.m_vertices.m_size = v8;
  v3->m_geometry.m_vertices.m_data = v9;
  v3->m_geometry.m_vertices.m_capacityAndFlags = v8 | 0x80000000;
}

// File Line: 22
// RVA: 0xBE52B0
void __fastcall hkaiNavMeshGenerationSnapshot::~hkaiNavMeshGenerationSnapshot(hkaiNavMeshGenerationSnapshot *this)
{
  hkaiNavMeshGenerationSnapshot *v1; // rbx

  v1 = this;
  hkaiNavMeshGenerationSettings::~hkaiNavMeshGenerationSettings(&this->m_settings);
  hkGeometry::~hkGeometry(&v1->m_geometry);
}

