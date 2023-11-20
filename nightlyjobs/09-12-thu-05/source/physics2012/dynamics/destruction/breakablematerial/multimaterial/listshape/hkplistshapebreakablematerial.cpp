// File Line: 17
// RVA: 0xD79FF0
void __fastcall hkpListShapeBreakableMaterial::hkpListShapeBreakableMaterial(hkpListShapeBreakableMaterial *this, hkArray<hkpBreakableMaterial *,hkContainerHeapAllocator> *subMaterials, float strength)
{
  hkpListShapeBreakableMaterial *v3; // rbx

  v3 = this;
  hkpBreakableMultiMaterial::hkpBreakableMultiMaterial(
    (hkpBreakableMultiMaterial *)&this->vfptr,
    subMaterials,
    strength);
  v3->m_typeAndFlags &= 0xFFFFFF3F;
  v3->m_typeAndFlags |= 0x30u;
  v3->vfptr = (hkBaseObjectVtbl *)&hkpListShapeBreakableMaterial::`vftable';
}

// File Line: 25
// RVA: 0xD7A090
hkClass *__fastcall hkpListShapeBreakableMaterial::getClassType(hkpListShapeBreakableMaterial *this)
{
  return &hkpListShapeBreakableMaterialClass;
}

// File Line: 34
// RVA: 0xD7A060
void __fastcall hkpListShapeBreakableMaterial::hkpListShapeBreakableMaterial(hkpListShapeBreakableMaterial *this, hkFinishLoadedObjectFlag flag)
{
  hkpListShapeBreakableMaterial *v2; // rbx

  v2 = this;
  hkpBreakableMultiMaterial::hkpBreakableMultiMaterial((hkpBreakableMultiMaterial *)&this->vfptr, flag);
  v2->vfptr = (hkBaseObjectVtbl *)&hkpListShapeBreakableMaterial::`vftable';
}

// File Line: 41
// RVA: 0xD7A030
void __fastcall hkpListShapeBreakableMaterial::hkpListShapeBreakableMaterial(hkpListShapeBreakableMaterial *this, hkpListShapeBreakableMaterial *other)
{
  hkpListShapeBreakableMaterial *v2; // rbx

  v2 = this;
  hkpBreakableMultiMaterial::hkpBreakableMultiMaterial(
    (hkpBreakableMultiMaterial *)&this->vfptr,
    (hkpBreakableMultiMaterial *)&other->vfptr);
  v2->vfptr = (hkBaseObjectVtbl *)&hkpListShapeBreakableMaterial::`vftable';
}

// File Line: 47
// RVA: 0xD7A0A0
void __fastcall hkpListShapeBreakableMaterial::duplicate(hkpListShapeBreakableMaterial *this)
{
  hkpListShapeBreakableMaterial *v1; // rbx
  _QWORD **v2; // rax
  hkpListShapeBreakableMaterial *v3; // rax

  v1 = this;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkpListShapeBreakableMaterial *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(
                                          v2[11],
                                          56i64);
  if ( v3 )
    hkpListShapeBreakableMaterial::hkpListShapeBreakableMaterial(v3, v1);
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
__int64 __fastcall hkpListShapeBreakableMaterial::getSubShapeMaterialIndex(hkpListShapeBreakableMaterial *this, hkcdShape *rootShape, unsigned int subShapeId)
{
  if ( rootShape->m_type.m_storage == 9 )
    rootShape = *(hkcdShape **)&rootShape[3].m_type.m_storage;
  return WORD2(rootShape[2].vfptr[2 * (signed int)subShapeId].__first_virtual_table_function__);
}

// File Line: 72
// RVA: 0xD7A140
hkpBreakableMaterial *__fastcall hkpListShapeBreakableMaterial::getShapeKeyMaterial(hkpListShapeBreakableMaterial *this, hkcdShape *shapePpu, unsigned int subShapeKey)
{
  if ( shapePpu->m_type.m_storage == 9 )
    shapePpu = *(hkcdShape **)&shapePpu[3].m_type.m_storage;
  return this->m_subMaterials.m_data[SWORD2(shapePpu[2].vfptr[2 * (signed int)subShapeKey].__first_virtual_table_function__)].m_pntr;
}

// File Line: 85
// RVA: 0xD7A170
void __fastcall hkpListShapeBreakableMaterial::disableSubShapes(hkpListShapeBreakableMaterial *this, hkcdShape *rootShape, const __int16 *subMaterialIndices, int numSubMaterialIndices)
{
  const __int16 *v4; // r14
  hkpListShape *v5; // rdi
  hkpListShapeBreakableMaterial *v6; // r15
  __int64 i; // rbp
  hkpBreakableMultiMaterial::InverseMapping *v8; // r8
  hkpBreakableMultiMaterial::InverseMappingDescriptor *v9; // rdx
  signed __int64 v10; // rsi
  int v11; // eax
  __int64 j; // rbx

  v4 = subMaterialIndices;
  v5 = (hkpListShape *)rootShape;
  v6 = this;
  if ( rootShape->m_type.m_storage == 9 )
    v5 = *(hkpListShape **)&rootShape[3].m_type.m_storage;
  for ( i = numSubMaterialIndices - 1; i >= 0; --i )
  {
    v8 = v6->m_inverseMapping.m_pntr;
    v9 = &v8->m_descriptors.m_data[v4[i]];
    v10 = (signed __int64)&v8->m_subShapeIds.m_data[v9->m_offset];
    v11 = v9->m_numKeys - 1;
    for ( j = v11; j >= 0; hkpListShape::disableChild(v5, *(_DWORD *)(v10 + 4 * j--)) )
      ;
  }
}

// File Line: 106
// RVA: 0xD7A220
void __fastcall hkpListShapeBreakableMaterial::getShapeKeysForSubShapes(hkpListShapeBreakableMaterial *this, hkcdShape *rootShape, const unsigned int *subShapeIdPtr, int numSubShapeIds, hkpBreakableMaterial::ShapeKeyCollector *collector)
{
  collector->vfptr->addShapeKeyBatch(collector, subShapeIdPtr, numSubShapeIds);
}

// File Line: 115
// RVA: 0xD7A240
void __fastcall hkpListShapeBreakableMaterial::getSubShapeMaterialIndices(hkpListShapeBreakableMaterial *this, hkcdShape *rootShape, hkArray<unsigned int,hkContainerHeapAllocator> *subShapeIdsIn, hkArray<short,hkContainerHeapAllocator> *subMaterialsOut)
{
  hkArray<short,hkContainerHeapAllocator> *v4; // rsi
  hkArray<unsigned int,hkContainerHeapAllocator> *v5; // rdi
  hkcdShape *v6; // rbx
  int v7; // ebp
  __int64 v8; // r14
  int v9; // er9
  int v10; // eax
  int v11; // eax
  __int16 *v12; // rax
  signed __int64 v13; // r8
  __int64 i; // rax
  __int64 v15; // rdx
  hkResult result; // [rsp+58h] [rbp+10h]

  v4 = subMaterialsOut;
  v5 = subShapeIdsIn;
  v6 = rootShape;
  if ( rootShape->m_type.m_storage == 9 )
    v6 = *(hkcdShape **)&rootShape[3].m_type.m_storage;
  v7 = subShapeIdsIn->m_size;
  v8 = subMaterialsOut->m_size;
  v9 = v8 + v7;
  v10 = v4->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v10 < (signed int)v8 + v7 )
  {
    v11 = 2 * v10;
    if ( v9 < v11 )
      v9 = v11;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, v9, 2);
  }
  v12 = v4->m_data;
  v4->m_size += v7;
  v13 = (signed __int64)&v12[v8];
  for ( i = v7 - 1; i >= 0; *(_WORD *)(v13 + 2 * i + 2) = WORD2(v6[2].vfptr[2 * v15].__first_virtual_table_function__) )
    v15 = (signed int)v5->m_data[i--];
}

