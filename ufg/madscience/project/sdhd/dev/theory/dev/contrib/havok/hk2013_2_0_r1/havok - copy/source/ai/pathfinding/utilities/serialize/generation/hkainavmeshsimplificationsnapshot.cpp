// File Line: 15
// RVA: 0xBE52D0
void __fastcall hkaiNavMeshSimplificationSnapshot::hkaiNavMeshSimplificationSnapshot(
        hkaiNavMeshSimplificationSnapshot *this)
{
  hkaiNavMeshGenerationSettings *p_m_settings; // rcx

  p_m_settings = &this->m_settings;
  *(_QWORD *)&p_m_settings[-1].m_carvedMaterialDeprecated = 0i64;
  *(_QWORD *)&p_m_settings[-1].m_setBestFaceCenters.m_bool = 0i64;
  LODWORD(p_m_settings[-1].m_snapshotFilename.m_stringAndFlag) = 0;
  HIDWORD(p_m_settings[-1].m_snapshotFilename.m_stringAndFlag) = 0x80000000;
  p_m_settings[-1].m_overrideSettings.m_data = 0i64;
  p_m_settings[-1].m_overrideSettings.m_size = 0;
  p_m_settings[-1].m_overrideSettings.m_capacityAndFlags = 0x80000000;
  *((_DWORD *)&p_m_settings[-1].m_overrideSettings + 4) = 0;
  hkaiNavMeshGenerationSettings::hkaiNavMeshGenerationSettings(p_m_settings);
  this->m_unsimplifiedNavMesh.m_pntr = 0i64;
}

// File Line: 19
// RVA: 0xBE5360
void __fastcall hkaiNavMeshSimplificationSnapshot::~hkaiNavMeshSimplificationSnapshot(
        hkaiNavMeshSimplificationSnapshot *this)
{
  hkaiNavMesh *m_pntr; // rcx
  int m_capacityAndFlags; // r8d
  hkRefPtr<hkaiVolume const > *m_data; // rsi
  int v5; // eax
  __int64 i; // rdi
  hkReferencedObject *v7; // rcx
  int v8; // r8d

  m_pntr = this->m_unsimplifiedNavMesh.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_unsimplifiedNavMesh.m_pntr = 0i64;
  hkaiNavMeshGenerationSettings::~hkaiNavMeshGenerationSettings(&this->m_settings);
  m_capacityAndFlags = this->m_cuttingTriangles.m_storage.m_words.m_capacityAndFlags;
  this->m_cuttingTriangles.m_storage.m_words.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_cuttingTriangles.m_storage.m_words.m_data,
      4 * m_capacityAndFlags);
  this->m_cuttingTriangles.m_storage.m_words.m_data = 0i64;
  this->m_cuttingTriangles.m_storage.m_words.m_capacityAndFlags = 0x80000000;
  m_data = this->m_carvers.m_data;
  v5 = this->m_carvers.m_size - 1;
  for ( i = v5; i >= 0; m_data[i--].m_pntr = 0i64 )
  {
    v7 = m_data[i].m_pntr;
    if ( v7 )
      hkReferencedObject::removeReference(v7);
  }
  v8 = this->m_carvers.m_capacityAndFlags;
  this->m_carvers.m_size = 0;
  if ( v8 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, this->m_carvers.m_data, 8 * v8);
  this->m_carvers.m_data = 0i64;
  this->m_carvers.m_capacityAndFlags = 0x80000000;
  if ( this->m_geometry.m_pntr )
    hkReferencedObject::removeReference(this->m_geometry.m_pntr);
  this->m_geometry.m_pntr = 0i64;
}

// File Line: 29
// RVA: 0xBE5330
void __fastcall hkaiNavMeshSimplificationSnapshot::hkaiNavMeshSimplificationSnapshot(
        hkaiNavMeshSimplificationSnapshot *this,
        hkFinishLoadedObjectFlag f)
{
  hkaiNavMeshGenerationSettings::hkaiNavMeshGenerationSettings(&this->m_settings, f);
}

// File Line: 33
// RVA: 0xBE5460
void __fastcall hkaiNavMeshSimplificationSnapshot::setRaycasterInformation(
        hkaiNavMeshSimplificationSnapshot *this,
        hkGeometry *triMesh,
        hkArrayBase<hkRefPtr<hkaiVolume const > > *carvers,
        hkBitField *cuttingTriangles)
{
  __int64 m_size; // r15
  int v8; // ebx
  hkArray<hkRefPtr<hkaiVolume const >,hkContainerHeapAllocator> *p_m_carvers; // r12
  int v10; // r13d
  int v11; // eax
  int v12; // eax
  int v13; // r9d
  __int64 v14; // rdi
  __int64 v15; // rbx
  hkReferencedObject *v16; // rcx
  hkReferencedObject **p_m_pntr; // rbx
  char *v18; // rsi
  __int64 v19; // rdi
  hkReferencedObject *v20; // rcx
  hkReferencedObject *v21; // rax
  hkRefPtr<hkaiVolume const > *v22; // rbx
  __int64 v23; // rsi
  signed __int64 v24; // r14
  hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator> > *v25; // rdx
  hkResult result; // [rsp+78h] [rbp+10h] BYREF
  hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator> > *__that; // [rsp+88h] [rbp+20h]

  __that = &cuttingTriangles->m_storage;
  if ( triMesh )
    hkReferencedObject::addReference(triMesh);
  if ( this->m_geometry.m_pntr )
    hkReferencedObject::removeReference(this->m_geometry.m_pntr);
  this->m_geometry.m_pntr = triMesh;
  m_size = carvers->m_size;
  v8 = this->m_carvers.m_size;
  p_m_carvers = &this->m_carvers;
  v10 = carvers->m_size;
  if ( (int)m_size > v8 )
    v10 = this->m_carvers.m_size;
  v11 = this->m_carvers.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v11 < (int)m_size )
  {
    v12 = 2 * v11;
    v13 = carvers->m_size;
    if ( (int)m_size < v12 )
      v13 = v12;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_carvers, v13, 8);
  }
  v14 = (__int64)&p_m_carvers->m_data[m_size];
  v15 = v8 - (int)m_size - 1;
  if ( (int)v15 >= 0 )
  {
    do
    {
      v16 = *(hkReferencedObject **)(v14 + 8 * v15);
      if ( v16 )
        hkReferencedObject::removeReference(v16);
      *(_QWORD *)(v14 + 8 * v15--) = 0i64;
    }
    while ( v15 >= 0 );
  }
  p_m_pntr = &p_m_carvers->m_data->m_pntr;
  if ( v10 > 0 )
  {
    v18 = (char *)((char *)carvers->m_data - (char *)p_m_pntr);
    v19 = v10;
    do
    {
      v20 = *(hkReferencedObject **)((char *)p_m_pntr + (_QWORD)v18);
      if ( v20 )
        hkReferencedObject::addReference(v20);
      if ( *p_m_pntr )
        hkReferencedObject::removeReference(*p_m_pntr);
      v21 = *(hkReferencedObject **)((char *)p_m_pntr++ + (_QWORD)v18);
      *(p_m_pntr - 1) = v21;
      --v19;
    }
    while ( v19 );
  }
  v22 = &carvers->m_data[v10];
  v23 = (int)m_size - v10;
  if ( (int)m_size - v10 > 0 )
  {
    v24 = (char *)&p_m_carvers->m_data[v10] - (char *)v22;
    do
    {
      if ( (hkRefPtr<hkaiVolume const > *)((char *)v22 + v24) )
      {
        if ( v22->m_pntr )
          hkReferencedObject::addReference(v22->m_pntr);
        *(hkRefPtr<hkaiVolume const > *)((char *)v22 + v24) = (hkRefPtr<hkaiVolume const >)v22->m_pntr;
      }
      ++v22;
      --v23;
    }
    while ( v23 );
  }
  v25 = __that;
  p_m_carvers->m_size = m_size;
  hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator>>::operator=(&this->m_cuttingTriangles.m_storage, v25);
}

// File Line: 40
// RVA: 0xBE55E0
void __fastcall hkaiNavMeshSimplificationSnapshot::setMeshAndSettings(
        hkaiNavMeshSimplificationSnapshot *this,
        hkaiNavMesh *mesh,
        hkaiNavMeshGenerationSettings *settings)
{
  hkaiNavMesh *m_pntr; // rcx

  if ( mesh )
    hkReferencedObject::addReference(mesh);
  m_pntr = this->m_unsimplifiedNavMesh.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_unsimplifiedNavMesh.m_pntr = mesh;
  hkaiNavMeshGenerationSettings::operator=(&this->m_settings, settings);
}

// File Line: 46
// RVA: 0xBE5640
void __fastcall hkaiNavMeshSimplificationSnapshot::save(hkaiNavMeshSimplificationSnapshot *this)
{
  hkClass *v2; // rax
  hkOstream v3; // [rsp+30h] [rbp-28h] BYREF
  hkResult result; // [rsp+60h] [rbp+8h] BYREF

  hkOstream::hkOstream(
    &v3,
    (const char *)((unsigned __int64)this->m_settings.m_simplificationSettings.m_snapshotFilename.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64));
  if ( hkOstream::isOk(&v3, (hkBool *)&result)->m_bool )
  {
    v2 = hkaiNavMeshSimplificationSnapshot::staticClass();
    hkSerializeUtil::save(&result, this, v2, v3.m_writer.m_pntr, 0);
  }
  hkOstream::~hkOstream(&v3);
}

