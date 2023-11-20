// File Line: 20
// RVA: 0xE7EB00
void __fastcall hkDisplayMesh::hkDisplayMesh(hkDisplayMesh *this, hkMeshBody *mesh)
{
  hkMeshBody *v2; // rdi
  hkDisplayMesh *v3; // rbx
  hkVector4f v4; // xmm1
  hkVector4f v5; // xmm0
  hkVector4f v6; // xmm1
  hkRotationf v7; // [rsp+20h] [rbp-178h]
  hkMatrix4f matrixIn; // [rsp+60h] [rbp-138h]
  hkMatrixDecompositionImpl<float>::Decomposition decompOut; // [rsp+A0h] [rbp-F8h]

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_geometry = 0i64;
  this->m_type = 11;
  v2 = mesh;
  v3 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayGeometry::`vftable';
  this->m_transform.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_transform.m_translation = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayMesh::`vftable';
  if ( mesh )
    hkReferencedObject::addReference((hkReferencedObject *)&mesh->vfptr);
  v3->m_mesh.m_pntr = v2;
  v3->m_meshAsTagfile.m_data = 0i64;
  v3->m_meshAsTagfile.m_size = 0;
  v3->m_meshAsTagfile.m_capacityAndFlags = 2147483648;
  v2->vfptr[2].__vecDelDtor((hkBaseObject *)&v2->vfptr, (unsigned int)&matrixIn);
  hkMatrixDecompositionImpl<float>::decomposeMatrix(&matrixIn, &decompOut);
  hkRotationf::set(&v7, &decompOut.m_rotation);
  v4.m_quad = (__m128)v7.m_col1;
  v3->m_transform.m_rotation.m_col0 = v7.m_col0;
  v5.m_quad = (__m128)v7.m_col2;
  v3->m_transform.m_rotation.m_col1 = (hkVector4f)v4.m_quad;
  v6.m_quad = (__m128)decompOut.m_translation;
  v3->m_transform.m_rotation.m_col2 = (hkVector4f)v5.m_quad;
  v3->m_transform.m_translation = (hkVector4f)v6.m_quad;
}

// File Line: 32
// RVA: 0xE7EC10
hkMeshBody *__fastcall hkDisplayMesh::getMesh(hkDisplayMesh *this)
{
  return this->m_mesh.m_pntr;
}

// File Line: 37
// RVA: 0xE7EC20
void __fastcall hkDisplayMesh::buildGeometry(hkDisplayMesh *this)
{
  ;
}

// File Line: 41
// RVA: 0xE7EC30
void __fastcall hkDisplayMesh::getWireframeGeometry(hkDisplayMesh *this, hkArrayBase<hkVector4f> *lines, hkMemoryAllocator *a)
{
  ;
}

// File Line: 45
// RVA: 0xE7EC40
void __fastcall hkDisplayMesh::serializeMeshData(hkDisplayMesh *this)
{
  hkDisplayMesh *v1; // rdi
  __int64 v2; // rax
  hkClass *v3; // rbx
  hkDataObject *v4; // rax
  hkDataObjectImpl *v5; // rcx
  bool v6; // zf
  hkBinaryTagfileWriter v7; // [rsp+30h] [rbp-1A8h]
  hkOstream v8; // [rsp+40h] [rbp-198h]
  hkDataWorldNative v9; // [rsp+60h] [rbp-178h]
  hkTagfileWriter::Options options; // [rsp+1E0h] [rbp+8h]
  hkResult v11; // [rsp+1E8h] [rbp+10h]
  hkDataObject result; // [rsp+1F0h] [rbp+18h]

  v1 = this;
  this->m_meshAsTagfile.m_size = 0;
  hkOstream::hkOstream(&v8, &this->m_meshAsTagfile);
  v2 = ((__int64 (*)(void))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[2].__first_virtual_table_function__)();
  v3 = (hkClass *)(*(__int64 (__fastcall **)(__int64, hkMeshBody *))(*(_QWORD *)v2 + 40i64))(v2, v1->m_mesh.m_pntr);
  hkDataWorldNative::hkDataWorldNative(&v9, 0);
  hkDataWorldNative::setContents(&v9, v1->m_mesh.m_pntr, v3);
  v7.vfptr = (hkBaseObjectVtbl *)&hkBinaryTagfileWriter::`vftable';
  *(_DWORD *)&v7.m_memSizeAndFlags = 0x1FFFF;
  *(_WORD *)&options.m_verbose.m_bool = 256;
  options.m_writeSerializeIgnored.m_bool = 0;
  v4 = hkDataWorldNative::getContents(&v9, &result);
  hkBinaryTagfileWriter::save(&v7, &v11, v4, v8.m_writer.m_pntr, 0i64, &options);
  v5 = result.m_impl;
  if ( result.m_impl )
  {
    --result.m_impl->m_externalCount;
    v6 = v5->m_count-- == 1;
    if ( v6 )
      v5->vfptr->__vecDelDtor((hkDataRefCounted *)&v5->vfptr, 1u);
  }
  hkDataWorldNative::~hkDataWorldNative(&v9);
  hkOstream::~hkOstream(&v8);
}

// File Line: 63
// RVA: 0xE7ED60
void __fastcall hkDisplayMesh::freeSerializedMeshData(hkDisplayMesh *this)
{
  int v1; // er8
  hkDisplayMesh *v2; // rbx

  v1 = this->m_meshAsTagfile.m_capacityAndFlags;
  v2 = this;
  this->m_meshAsTagfile.m_size = 0;
  if ( v1 < 0 )
  {
    this->m_meshAsTagfile.m_data = 0i64;
    this->m_meshAsTagfile.m_capacityAndFlags = 2147483648;
  }
  else
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      this->m_meshAsTagfile.m_data,
      v1 & 0x3FFFFFFF);
    v2->m_meshAsTagfile.m_data = 0i64;
    v2->m_meshAsTagfile.m_capacityAndFlags = 2147483648;
  }
}

// File Line: 68
// RVA: 0xE7EDE0
__int64 __fastcall hkDisplayMesh::getSeriaizedMeshDataSize(hkDisplayMesh *this)
{
  return (unsigned int)this->m_meshAsTagfile.m_size;
}

// File Line: 73
// RVA: 0xE7EDF0
char *__fastcall hkDisplayMesh::getSeriaizedMeshData(hkDisplayMesh *this)
{
  return this->m_meshAsTagfile.m_data;
}

// File Line: 78
// RVA: 0xE7EE00
void __fastcall hkForwardingDisplayGeometryBuilder::buildDisplayGeometries(hkForwardingDisplayGeometryBuilder *this, hkReferencedObject *source, hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries)
{
  hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *v3; // rbx
  hkMeshBody *v4; // rdi
  __int64 v5; // rax
  hkClass *v6; // rax
  _QWORD **v7; // rax
  hkDisplayMesh *v8; // rax
  hkDisplayGeometry *v9; // rax
  hkDisplayGeometry *v10; // rdi
  hkBool result; // [rsp+48h] [rbp+20h]

  v3 = displayGeometries;
  v4 = (hkMeshBody *)source;
  v5 = ((__int64 (*)(void))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[2].__first_virtual_table_function__)();
  v6 = (hkClass *)(*(__int64 (__fastcall **)(__int64, hkMeshBody *))(*(_QWORD *)v5 + 40i64))(v5, v4);
  if ( hkClass::isSuperClass(&hkMeshBodyClass, &result, v6)->m_bool )
  {
    v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v8 = (hkDisplayMesh *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v7[11] + 8i64))(v7[11], 144i64);
    if ( v8 )
    {
      hkDisplayMesh::hkDisplayMesh(v8, v4);
      v10 = v9;
    }
    else
    {
      v10 = 0i64;
    }
    if ( v3->m_size == (v3->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, 8);
    v3->m_data[v3->m_size++] = v10;
  }
}

