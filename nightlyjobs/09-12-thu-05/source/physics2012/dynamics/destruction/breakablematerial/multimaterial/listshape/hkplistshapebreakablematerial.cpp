// File Line: 17
// RVA: 0xD79FF0
void __fastcall hkpListShapeBreakableMaterial::hkpListShapeBreakableMaterial(
        hkpListShapeBreakableMaterial *this,
        hkArray<hkpBreakableMaterial *,hkContainerHeapAllocator> *subMaterials,
        float strength)
{
  hkpBreakableMultiMaterial::hkpBreakableMultiMaterial(this, subMaterials, strength);
  this->m_typeAndFlags &= 0xFFFFFF3F;
  this->m_typeAndFlags |= 0x30u;
  this->vfptr = (hkBaseObjectVtbl *)&hkpListShapeBreakableMaterial::`vftable;
}

// File Line: 25
// RVA: 0xD7A090
hkClass *__fastcall hkpListShapeBreakableMaterial::getClassType(hkpListShapeBreakableMaterial *this)
{
  return &hkpListShapeBreakableMaterialClass;
}

// File Line: 34
// RVA: 0xD7A060
void __fastcall hkpListShapeBreakableMaterial::hkpListShapeBreakableMaterial(
        hkpListShapeBreakableMaterial *this,
        hkFinishLoadedObjectFlag flag)
{
  hkpBreakableMultiMaterial::hkpBreakableMultiMaterial(this, flag);
  this->vfptr = (hkBaseObjectVtbl *)&hkpListShapeBreakableMaterial::`vftable;
}

// File Line: 41
// RVA: 0xD7A030
void __fastcall hkpListShapeBreakableMaterial::hkpListShapeBreakableMaterial(
        hkpListShapeBreakableMaterial *this,
        hkpListShapeBreakableMaterial *other)
{
  hkpBreakableMultiMaterial::hkpBreakableMultiMaterial(this, other);
  this->vfptr = (hkBaseObjectVtbl *)&hkpListShapeBreakableMaterial::`vftable;
}

// File Line: 47
// RVA: 0xD7A0A0
void __fastcall hkpListShapeBreakableMaterial::duplicate(hkpListShapeBreakableMaterial *this)
{
  _QWORD **Value; // rax
  hkpListShapeBreakableMaterial *v3; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkpListShapeBreakableMaterial *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                          Value[11],
                                          56i64);
  if ( v3 )
    hkpListShapeBreakableMaterial::hkpListShapeBreakableMaterial(v3, this);
}

// File Line: 55
// RVA: 0xD7A0F0
void __fastcall hkpListShapeBreakableMaterial::setDefaultMapping(hkpListShapeBreakableMaterial *this)
{
  this->m_typeAndFlags &= 0xFFFFFF3F;
  this->m_typeAndFlags |= 0x30u;
}

// File Line: 63
// RVA: 0xD7A110
__int64 __fastcall hkpListShapeBreakableMaterial::getSubShapeMaterialIndex(
        hkpListShapeBreakableMaterial *this,
        hkcdShape *rootShape,
        int subShapeId)
{
  if ( rootShape->m_type.m_storage == 9 )
    rootShape = *(hkcdShape **)&rootShape[3].m_type.m_storage;
  return WORD2(rootShape[2].vfptr[2 * subShapeId].__first_virtual_table_function__);
}

// File Line: 72
// RVA: 0xD7A140
hkpBreakableMaterial *__fastcall hkpListShapeBreakableMaterial::getShapeKeyMaterial(
        hkpListShapeBreakableMaterial *this,
        hkcdShape *shapePpu,
        int subShapeKey)
{
  if ( shapePpu->m_type.m_storage == 9 )
    shapePpu = *(hkcdShape **)&shapePpu[3].m_type.m_storage;
  return this->m_subMaterials.m_data[SWORD2(shapePpu[2].vfptr[2 * subShapeKey].__first_virtual_table_function__)].m_pntr;
}

// File Line: 85
// RVA: 0xD7A170
void __fastcall hkpListShapeBreakableMaterial::disableSubShapes(
        hkpListShapeBreakableMaterial *this,
        hkpListShape *rootShape,
        const __int16 *subMaterialIndices,
        int numSubMaterialIndices)
{
  hkpListShape *v5; // rdi
  __int64 i; // rbp
  hkpBreakableMultiMaterial::InverseMapping *m_pntr; // r8
  hkpBreakableMultiMaterial::InverseMappingDescriptor *v9; // rdx
  __int64 v10; // rsi
  int v11; // eax
  __int64 j; // rbx

  v5 = rootShape;
  if ( rootShape->m_type.m_storage == 9 )
    v5 = (hkpListShape *)rootShape->m_aabbHalfExtents.m_quad.m128_u64[1];
  for ( i = numSubMaterialIndices - 1; i >= 0; --i )
  {
    m_pntr = this->m_inverseMapping.m_pntr;
    v9 = &m_pntr->m_descriptors.m_data[subMaterialIndices[i]];
    v10 = (__int64)&m_pntr->m_subShapeIds.m_data[v9->m_offset];
    v11 = v9->m_numKeys - 1;
    for ( j = v11; j >= 0; hkpListShape::disableChild(v5, *(_DWORD *)(v10 + 4 * j--)) )
      ;
  }
}

// File Line: 106
// RVA: 0xD7A220
void __fastcall hkpListShapeBreakableMaterial::getShapeKeysForSubShapes(
        hkpListShapeBreakableMaterial *this,
        hkcdShape *rootShape,
        const unsigned int *subShapeIdPtr,
        int numSubShapeIds,
        hkpBreakableMaterial::ShapeKeyCollector *collector)
{
  collector->vfptr->addShapeKeyBatch(collector, subShapeIdPtr, numSubShapeIds);
}

// File Line: 115
// RVA: 0xD7A240
void __fastcall hkpListShapeBreakableMaterial::getSubShapeMaterialIndices(
        hkpListShapeBreakableMaterial *this,
        hkcdShape *rootShape,
        hkArray<unsigned int,hkContainerHeapAllocator> *subShapeIdsIn,
        hkArray<short,hkContainerHeapAllocator> *subMaterialsOut)
{
  hkcdShape *v6; // rbx
  int m_size; // ebp
  __int64 v8; // r14
  int v9; // r9d
  int v10; // eax
  int v11; // eax
  __int16 *m_data; // rax
  __int16 *v13; // r8
  __int64 i; // rax
  __int64 v15; // rdx
  hkResult result; // [rsp+58h] [rbp+10h] BYREF

  v6 = rootShape;
  if ( rootShape->m_type.m_storage == 9 )
    v6 = *(hkcdShape **)&rootShape[3].m_type.m_storage;
  m_size = subShapeIdsIn->m_size;
  v8 = subMaterialsOut->m_size;
  v9 = v8 + m_size;
  v10 = subMaterialsOut->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v10 < (int)v8 + m_size )
  {
    v11 = 2 * v10;
    if ( v9 < v11 )
      v9 = v11;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&subMaterialsOut->m_data, v9, 2);
  }
  m_data = subMaterialsOut->m_data;
  subMaterialsOut->m_size += m_size;
  v13 = &m_data[v8];
  for ( i = m_size - 1; i >= 0; v13[i + 1] = WORD2(v6[2].vfptr[2 * v15].__first_virtual_table_function__) )
    v15 = (int)subShapeIdsIn->m_data[i--];
}

