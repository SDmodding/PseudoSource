// File Line: 15
// RVA: 0xBE52D0
void __fastcall hkaiNavMeshSimplificationSnapshot::hkaiNavMeshSimplificationSnapshot(hkaiNavMeshSimplificationSnapshot *this)
{
  hkaiNavMeshSimplificationSnapshot *v1; // rbx
  hkaiNavMeshGenerationSettings *v2; // rcx

  v1 = this;
  v2 = &this->m_settings;
  *(_QWORD *)&v2[-1].m_carvedMaterialDeprecated = 0i64;
  *(_QWORD *)&v2[-1].m_setBestFaceCenters.m_bool = 0i64;
  LODWORD(v2[-1].m_snapshotFilename.m_stringAndFlag) = 0;
  HIDWORD(v2[-1].m_snapshotFilename.m_stringAndFlag) = 2147483648;
  v2[-1].m_overrideSettings.m_data = 0i64;
  v2[-1].m_overrideSettings.m_size = 0;
  v2[-1].m_overrideSettings.m_capacityAndFlags = 2147483648;
  *((_DWORD *)&v2[-1].m_overrideSettings + 4) = 0;
  hkaiNavMeshGenerationSettings::hkaiNavMeshGenerationSettings(v2);
  v1->m_unsimplifiedNavMesh.m_pntr = 0i64;
}

// File Line: 19
// RVA: 0xBE5360
void __fastcall hkaiNavMeshSimplificationSnapshot::~hkaiNavMeshSimplificationSnapshot(hkaiNavMeshSimplificationSnapshot *this)
{
  hkaiNavMeshSimplificationSnapshot *v1; // rbx
  hkaiNavMesh *v2; // rcx
  int v3; // er8
  hkRefPtr<hkaiVolume const > *v4; // rsi
  int v5; // eax
  __int64 i; // rdi
  hkReferencedObject *v7; // rcx
  int v8; // er8

  v1 = this;
  v2 = this->m_unsimplifiedNavMesh.m_pntr;
  if ( v2 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
  v1->m_unsimplifiedNavMesh.m_pntr = 0i64;
  hkaiNavMeshGenerationSettings::~hkaiNavMeshGenerationSettings(&v1->m_settings);
  v3 = v1->m_cuttingTriangles.m_storage.m_words.m_capacityAndFlags;
  v1->m_cuttingTriangles.m_storage.m_words.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_cuttingTriangles.m_storage.m_words.m_data,
      4 * v3);
  v1->m_cuttingTriangles.m_storage.m_words.m_data = 0i64;
  v1->m_cuttingTriangles.m_storage.m_words.m_capacityAndFlags = 2147483648;
  v4 = v1->m_carvers.m_data;
  v5 = v1->m_carvers.m_size - 1;
  for ( i = v5; i >= 0; v4[i--].m_pntr = 0i64 )
  {
    v7 = (hkReferencedObject *)&v4[i].m_pntr->vfptr;
    if ( v7 )
      hkReferencedObject::removeReference(v7);
  }
  v8 = v1->m_carvers.m_capacityAndFlags;
  v1->m_carvers.m_size = 0;
  if ( v8 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_carvers.m_data,
      8 * v8);
  v1->m_carvers.m_data = 0i64;
  v1->m_carvers.m_capacityAndFlags = 2147483648;
  if ( v1->m_geometry.m_pntr )
    hkReferencedObject::removeReference((hkReferencedObject *)&v1->m_geometry.m_pntr->vfptr);
  v1->m_geometry.m_pntr = 0i64;
}

// File Line: 29
// RVA: 0xBE5330
void __fastcall hkaiNavMeshSimplificationSnapshot::hkaiNavMeshSimplificationSnapshot(hkaiNavMeshSimplificationSnapshot *this, hkFinishLoadedObjectFlag f)
{
  hkaiNavMeshGenerationSettings::hkaiNavMeshGenerationSettings(&this->m_settings, f);
}

// File Line: 33
// RVA: 0xBE5460
void __fastcall hkaiNavMeshSimplificationSnapshot::setRaycasterInformation(hkaiNavMeshSimplificationSnapshot *this, hkGeometry *triMesh, hkArrayBase<hkRefPtr<hkaiVolume const > > *carvers, hkBitField *cuttingTriangles)
{
  hkArrayBase<hkRefPtr<hkaiVolume const > > *v4; // r14
  hkGeometry *v5; // rbx
  hkaiNavMeshSimplificationSnapshot *v6; // rdi
  __int64 v7; // r15
  signed int v8; // ebx
  signed __int64 v9; // r12
  int v10; // er13
  int v11; // eax
  int v12; // eax
  int v13; // er9
  signed __int64 v14; // rdi
  __int64 v15; // rbx
  hkReferencedObject *v16; // rcx
  hkReferencedObject **v17; // rbx
  signed __int64 v18; // rsi
  __int64 v19; // rdi
  hkReferencedObject *v20; // rcx
  hkReferencedObject *v21; // rax
  hkReferencedObject **v22; // rbx
  __int64 v23; // rsi
  signed __int64 v24; // r14
  hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator> > *v25; // rdx
  hkaiNavMeshSimplificationSnapshot *v26; // [rsp+70h] [rbp+8h]
  hkResult result; // [rsp+78h] [rbp+10h]
  hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator> > *__that; // [rsp+88h] [rbp+20h]

  __that = &cuttingTriangles->m_storage;
  v26 = this;
  v4 = carvers;
  v5 = triMesh;
  v6 = this;
  if ( triMesh )
    hkReferencedObject::addReference((hkReferencedObject *)&triMesh->vfptr);
  if ( v6->m_geometry.m_pntr )
    hkReferencedObject::removeReference((hkReferencedObject *)&v6->m_geometry.m_pntr->vfptr);
  v6->m_geometry.m_pntr = v5;
  v7 = v4->m_size;
  v8 = v6->m_carvers.m_size;
  v9 = (signed __int64)&v6->m_carvers;
  v10 = v4->m_size;
  if ( (signed int)v7 > v8 )
    v10 = v6->m_carvers.m_size;
  v11 = v6->m_carvers.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v11 < (signed int)v7 )
  {
    v12 = 2 * v11;
    v13 = v7;
    if ( (signed int)v7 < v12 )
      v13 = v12;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v6->m_carvers,
      v13,
      8);
  }
  v14 = *(_QWORD *)v9 + 8 * v7;
  v15 = v8 - (signed int)v7 - 1;
  if ( (signed int)v15 >= 0 )
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
  v17 = *(hkReferencedObject ***)v9;
  if ( v10 > 0 )
  {
    v18 = (char *)v4->m_data - (char *)v17;
    v19 = v10;
    do
    {
      v20 = *(hkReferencedObject **)((char *)v17 + v18);
      if ( v20 )
        hkReferencedObject::addReference(v20);
      if ( *v17 )
        hkReferencedObject::removeReference(*v17);
      v21 = *(hkReferencedObject **)((char *)v17 + v18);
      ++v17;
      *(v17 - 1) = v21;
      --v19;
    }
    while ( v19 );
  }
  v22 = (hkReferencedObject **)&v4->m_data[v10];
  v23 = (signed int)v7 - v10;
  if ( (signed int)v7 - v10 > 0 )
  {
    v24 = *(_QWORD *)v9 + 8i64 * v10 - (_QWORD)v22;
    do
    {
      if ( (hkReferencedObject **)((char *)v22 + v24) )
      {
        if ( *v22 )
          hkReferencedObject::addReference(*v22);
        *(hkReferencedObject **)((char *)v22 + v24) = *v22;
      }
      ++v22;
      --v23;
    }
    while ( v23 );
  }
  v25 = __that;
  *(_DWORD *)(v9 + 8) = v7;
  hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator>>::operator=(&v26->m_cuttingTriangles.m_storage, v25);
}

// File Line: 40
// RVA: 0xBE55E0
void __fastcall hkaiNavMeshSimplificationSnapshot::setMeshAndSettings(hkaiNavMeshSimplificationSnapshot *this, hkaiNavMesh *mesh, hkaiNavMeshGenerationSettings *settings)
{
  hkaiNavMeshGenerationSettings *v3; // rsi
  hkaiNavMesh *v4; // rdi
  hkaiNavMeshSimplificationSnapshot *v5; // rbx
  hkReferencedObject *v6; // rcx

  v3 = settings;
  v4 = mesh;
  v5 = this;
  if ( mesh )
    hkReferencedObject::addReference((hkReferencedObject *)&mesh->vfptr);
  v6 = (hkReferencedObject *)&v5->m_unsimplifiedNavMesh.m_pntr->vfptr;
  if ( v6 )
    hkReferencedObject::removeReference(v6);
  v5->m_unsimplifiedNavMesh.m_pntr = v4;
  hkaiNavMeshGenerationSettings::operator=(&v5->m_settings, v3);
}

// File Line: 46
// RVA: 0xBE5640
void __fastcall hkaiNavMeshSimplificationSnapshot::save(hkaiNavMeshSimplificationSnapshot *this)
{
  hkaiNavMeshSimplificationSnapshot *v1; // rbx
  hkClass *v2; // rax
  hkOstream v3; // [rsp+30h] [rbp-28h]
  hkBool result; // [rsp+60h] [rbp+8h]

  v1 = this;
  hkOstream::hkOstream(
    &v3,
    (const char *)((_QWORD)this->m_settings.m_simplificationSettings.m_snapshotFilename.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64));
  if ( hkOstream::isOk(&v3, &result)->m_bool )
  {
    v2 = hkaiNavMeshSimplificationSnapshot::staticClass();
    hkSerializeUtil::save((hkResult *)&result, v1, v2, v3.m_writer.m_pntr, 0);
  }
  hkOstream::~hkOstream(&v3);
}

