// File Line: 20
// RVA: 0xE7EB00
void __fastcall hkDisplayMesh::hkDisplayMesh(hkDisplayMesh *this, hkMeshBody *mesh)
{
  hkVector4f v4; // xmm1
  hkVector4f v5; // xmm0
  hkVector4f v6; // xmm1
  hkRotationf v7; // [rsp+20h] [rbp-178h] BYREF
  hkMatrix4f matrixIn; // [rsp+60h] [rbp-138h] BYREF
  hkMatrixDecompositionImpl<float>::Decomposition decompOut; // [rsp+A0h] [rbp-F8h] BYREF

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_geometry = 0i64;
  this->m_type = HK_DISPLAY_MESH;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayGeometry::`vftable;
  this->m_transform.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  this->m_transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  this->m_transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_transform.m_translation = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkDisplayMesh::`vftable;
  if ( mesh )
    hkReferencedObject::addReference(mesh);
  this->m_mesh.m_pntr = mesh;
  this->m_meshAsTagfile.m_data = 0i64;
  this->m_meshAsTagfile.m_size = 0;
  this->m_meshAsTagfile.m_capacityAndFlags = 0x80000000;
  mesh->vfptr[2].__vecDelDtor(mesh, (unsigned int)&matrixIn);
  hkMatrixDecompositionImpl<float>::decomposeMatrix(&matrixIn, &decompOut);
  hkRotationf::set(&v7, &decompOut.m_rotation);
  v4.m_quad = (__m128)v7.m_col1;
  this->m_transform.m_rotation.m_col0 = v7.m_col0;
  v5.m_quad = (__m128)v7.m_col2;
  this->m_transform.m_rotation.m_col1 = (hkVector4f)v4.m_quad;
  v6.m_quad = (__m128)decompOut.m_translation;
  this->m_transform.m_rotation.m_col2 = (hkVector4f)v5.m_quad;
  this->m_transform.m_translation = (hkVector4f)v6.m_quad;
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
void __fastcall hkDisplayMesh::getWireframeGeometry(
        hkDisplayMesh *this,
        hkArrayBase<hkVector4f> *lines,
        hkMemoryAllocator *a)
{
  ;
}

// File Line: 45
// RVA: 0xE7EC40
void __fastcall hkDisplayMesh::serializeMeshData(hkDisplayMesh *this)
{
  __int64 v2; // rax
  hkClass *v3; // rbx
  hkDataObject *Contents; // rax
  hkDataObjectImpl *m_impl; // rcx
  hkBinaryTagfileWriter v7; // [rsp+30h] [rbp-1A8h] BYREF
  hkOstream v8; // [rsp+40h] [rbp-198h] BYREF
  hkDataWorldNative v9; // [rsp+60h] [rbp-178h] BYREF
  hkTagfileWriter::Options options; // [rsp+1E0h] [rbp+8h] BYREF
  hkResult v11; // [rsp+1E8h] [rbp+10h] BYREF
  hkDataObject result; // [rsp+1F0h] [rbp+18h] BYREF

  this->m_meshAsTagfile.m_size = 0;
  hkOstream::hkOstream(&v8, &this->m_meshAsTagfile);
  v2 = ((__int64 (__fastcall *)(hkBuiltinTypeRegistry *))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[2].__first_virtual_table_function__)(hkSingleton<hkBuiltinTypeRegistry>::s_instance);
  v3 = (hkClass *)(*(__int64 (__fastcall **)(__int64, hkMeshBody *))(*(_QWORD *)v2 + 40i64))(v2, this->m_mesh.m_pntr);
  hkDataWorldNative::hkDataWorldNative(&v9, 0);
  hkDataWorldNative::setContents(&v9, this->m_mesh.m_pntr, v3);
  v7.vfptr = (hkBaseObjectVtbl *)&hkBinaryTagfileWriter::`vftable;
  *(_DWORD *)&v7.m_memSizeAndFlags = 0x1FFFF;
  *(_WORD *)&options.m_verbose.m_bool = 256;
  options.m_writeSerializeIgnored.m_bool = 0;
  Contents = hkDataWorldNative::getContents(&v9, &result);
  hkBinaryTagfileWriter::save(&v7, &v11, Contents, v8.m_writer.m_pntr, 0i64, &options);
  m_impl = result.m_impl;
  if ( result.m_impl )
  {
    --result.m_impl->m_externalCount;
    if ( m_impl->m_count-- == 1 )
      m_impl->vfptr->__vecDelDtor(m_impl, 1u);
  }
  hkDataWorldNative::~hkDataWorldNative(&v9);
  hkOstream::~hkOstream(&v8);
}

// File Line: 63
// RVA: 0xE7ED60
void __fastcall hkDisplayMesh::freeSerializedMeshData(hkDisplayMesh *this)
{
  int m_capacityAndFlags; // r8d

  m_capacityAndFlags = this->m_meshAsTagfile.m_capacityAndFlags;
  this->m_meshAsTagfile.m_size = 0;
  if ( m_capacityAndFlags < 0 )
  {
    this->m_meshAsTagfile.m_data = 0i64;
    this->m_meshAsTagfile.m_capacityAndFlags = 0x80000000;
  }
  else
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_meshAsTagfile.m_data,
      m_capacityAndFlags & 0x3FFFFFFF);
    this->m_meshAsTagfile.m_data = 0i64;
    this->m_meshAsTagfile.m_capacityAndFlags = 0x80000000;
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
void __fastcall hkForwardingDisplayGeometryBuilder::buildDisplayGeometries(
        hkForwardingDisplayGeometryBuilder *this,
        hkMeshBody *source,
        hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries)
{
  __int64 v5; // rax
  hkClass *v6; // rax
  _QWORD **Value; // rax
  hkDisplayMesh *v8; // rax
  hkDisplayGeometry *v9; // rax
  hkDisplayGeometry *v10; // rdi
  hkBool result; // [rsp+48h] [rbp+20h] BYREF

  v5 = ((__int64 (__fastcall *)(hkBuiltinTypeRegistry *))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[2].__first_virtual_table_function__)(hkSingleton<hkBuiltinTypeRegistry>::s_instance);
  v6 = (hkClass *)(*(__int64 (__fastcall **)(__int64, hkMeshBody *))(*(_QWORD *)v5 + 40i64))(v5, source);
  if ( hkClass::isSuperClass(&hkMeshBodyClass, &result, v6)->m_bool )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v8 = (hkDisplayMesh *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 144i64);
    if ( v8 )
    {
      hkDisplayMesh::hkDisplayMesh(v8, source);
      v10 = v9;
    }
    else
    {
      v10 = 0i64;
    }
    if ( displayGeometries->m_size == (displayGeometries->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&displayGeometries->m_data, 8);
    displayGeometries->m_data[displayGeometries->m_size++] = v10;
  }
}

