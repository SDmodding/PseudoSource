// File Line: 17
// RVA: 0xD79A90
void __fastcall hkpExtendedMeshShapeBreakableMaterial::hkpExtendedMeshShapeBreakableMaterial(
        hkpExtendedMeshShapeBreakableMaterial *this,
        hkArray<hkpBreakableMaterial *,hkContainerHeapAllocator> *subMaterials,
        char numBitsPerSubPart,
        float strength)
{
  hkpBreakableMultiMaterial::hkpBreakableMultiMaterial(this, subMaterials, strength);
  BYTE1(this->m_typeAndFlags) = 0;
  this->vfptr = (hkBaseObjectVtbl *)&hkpExtendedMeshShapeBreakableMaterial::`vftable;
  this->m_typeAndFlags = this->m_typeAndFlags & 0xFFFFFF4F | ((unsigned __int8)(32 - numBitsPerSubPart) << 8) | 0x40;
}

// File Line: 26
// RVA: 0xD79B50
hkClass *__fastcall hkpExtendedMeshShapeBreakableMaterial::getClassType(hkpExtendedMeshShapeBreakableMaterial *this)
{
  return &hkpExtendedMeshShapeBreakableMaterialClass;
}

// File Line: 35
// RVA: 0xD79B20
void __fastcall hkpExtendedMeshShapeBreakableMaterial::hkpExtendedMeshShapeBreakableMaterial(
        hkpExtendedMeshShapeBreakableMaterial *this,
        hkFinishLoadedObjectFlag flag)
{
  hkpBreakableMultiMaterial::hkpBreakableMultiMaterial(this, flag);
  this->vfptr = (hkBaseObjectVtbl *)&hkpExtendedMeshShapeBreakableMaterial::`vftable;
}

// File Line: 42
// RVA: 0xD79AF0
void __fastcall hkpExtendedMeshShapeBreakableMaterial::hkpExtendedMeshShapeBreakableMaterial(
        hkpExtendedMeshShapeBreakableMaterial *this,
        hkpExtendedMeshShapeBreakableMaterial *other)
{
  hkpBreakableMultiMaterial::hkpBreakableMultiMaterial(this, other);
  this->vfptr = (hkBaseObjectVtbl *)&hkpExtendedMeshShapeBreakableMaterial::`vftable;
}

// File Line: 48
// RVA: 0xD79E50
void __fastcall hkpExtendedMeshShapeBreakableMaterial::createInverseMapping(
        hkpExtendedMeshShapeBreakableMaterial *this,
        hkcdShape *shape)
{
  hkcdShape *v2; // rbx
  hkpBreakableMultiMaterial::InverseMapping *m_pntr; // rbp
  unsigned int *m_data; // rsi
  int v6; // eax
  __int64 i; // r11
  hkpBreakableMultiMaterial::InverseMappingDescriptor *v8; // rax
  int v9; // r8d
  hkpBreakableMultiMaterial::InverseMappingDescriptor *j; // rdi
  int *v11; // r10
  signed int v12; // edx
  __int64 v13; // rax
  int v14; // eax

  v2 = shape;
  hkpBreakableMultiMaterial::createInverseMapping(this, shape);
  if ( v2->m_type.m_storage == 9 )
    v2 = *(hkcdShape **)&v2[3].m_type.m_storage;
  m_pntr = this->m_inverseMapping.m_pntr;
  m_data = m_pntr->m_subShapeIds.m_data;
  v6 = m_pntr->m_descriptors.m_size - 1;
  for ( i = v6; i >= 0; --i )
  {
    v8 = m_pntr->m_descriptors.m_data;
    v9 = v8[i].m_numKeys - 1;
    for ( j = &v8[i]; v9 >= 0; *v11 |= v14 - 1 )
    {
      v11 = (int *)&m_data[v9 + j->m_offset];
      v12 = (*v11 & 0x7FFFFFFFu) >> (32 - v2[9].m_type.m_storage);
      if ( *v11 < 0 )
        v13 = *(_QWORD *)&v2[10].m_type.m_storage + 80i64 * v12;
      else
        v13 = (__int64)&v2[10].vfptr[9 * v12];
      if ( (*(_BYTE *)v13 & 1) != 0 )
        v14 = *(_DWORD *)(v13 + 40);
      else
        v14 = *(_DWORD *)(v13 + 32);
      --v9;
    }
  }
}

// File Line: 95
// RVA: 0xD79B60
void __fastcall hkpExtendedMeshShapeBreakableMaterial::duplicate(hkpExtendedMeshShapeBreakableMaterial *this)
{
  _QWORD **Value; // rax
  hkpExtendedMeshShapeBreakableMaterial *v3; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkpExtendedMeshShapeBreakableMaterial *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                                  Value[11],
                                                  56i64);
  if ( v3 )
    hkpExtendedMeshShapeBreakableMaterial::hkpExtendedMeshShapeBreakableMaterial(v3, this);
}

// File Line: 103
// RVA: 0xD79F40
void __fastcall hkpExtendedMeshShapeBreakableMaterial::setDefaultMapping(hkpExtendedMeshShapeBreakableMaterial *this)
{
  this->m_typeAndFlags &= 0xFFFFFF4F;
  this->m_typeAndFlags |= 0x40u;
}

// File Line: 111
// RVA: 0xD79BB0
__int64 __fastcall hkpExtendedMeshShapeBreakableMaterial::getSubShapeMaterialIndex(
        hkpExtendedMeshShapeBreakableMaterial *this,
        hkcdShape *rootShape,
        int subShapeId)
{
  __int64 v3; // r9
  hkBaseObjectVtbl *v4; // rcx

  if ( rootShape->m_type.m_storage == 9 )
    rootShape = *(hkcdShape **)&rootShape[3].m_type.m_storage;
  v3 = (subShapeId & 0x7FFFFFFFu) >> (32 - rootShape[9].m_type.m_storage);
  if ( subShapeId < 0 )
    v4 = (hkBaseObjectVtbl *)(*(_QWORD *)&rootShape[10].m_type.m_storage + 80 * v3);
  else
    v4 = &rootShape[10].vfptr[9 * v3];
  return WORD1(v4->__vecDelDtor);
}

// File Line: 120
// RVA: 0xD79C10
hkpBreakableMaterial *__fastcall hkpExtendedMeshShapeBreakableMaterial::getShapeKeyMaterial(
        hkpExtendedMeshShapeBreakableMaterial *this,
        hkcdShape *shapePpu,
        int shapeKey)
{
  __int64 v4; // r9
  __int64 v5; // rcx

  if ( shapePpu->m_type.m_storage == 9 )
    shapePpu = *(hkcdShape **)&shapePpu[3].m_type.m_storage;
  v4 = (shapeKey & 0x7FFFFFFFu) >> (32 - shapePpu[9].m_type.m_storage);
  if ( shapeKey < 0 )
    v5 = *(__int16 *)(*(_QWORD *)&shapePpu[10].m_type.m_storage + 80 * v4 + 2);
  else
    v5 = SWORD1(shapePpu[10].vfptr[9 * v4].__vecDelDtor);
  return this->m_subMaterials.m_data[v5].m_pntr;
}

// File Line: 134
// RVA: 0xD79C80
__int64 __fastcall hkpExtendedMeshShapeBreakableMaterial::convertShapeKeyToSubShapeId(
        hkpExtendedMeshShapeBreakableMaterial *this,
        unsigned int shapeKey)
{
  return shapeKey & (-1 << BYTE1(this->m_typeAndFlags));
}

// File Line: 146
// RVA: 0xD79CA0
void __fastcall hkpExtendedMeshShapeBreakableMaterial::convertShapeKeysToSubShapeIds(
        hkpExtendedMeshShapeBreakableMaterial *this,
        hkArray<unsigned int,hkContainerHeapAllocator> *shapeKeysInOut)
{
  int v2; // r8d
  __int64 v3; // rax

  v2 = -1 << BYTE1(this->m_typeAndFlags);
  v3 = shapeKeysInOut->m_size - 1;
  if ( (int)v3 >= 0 )
  {
    do
      shapeKeysInOut->m_data[v3--] &= v2;
    while ( v3 >= 0 );
  }
}

// File Line: 161
// RVA: 0xD79CE0
void __fastcall hkpExtendedMeshShapeBreakableMaterial::getShapeKeysForSubShapes(
        hkpExtendedMeshShapeBreakableMaterial *this,
        hkcdShape *__formal,
        const unsigned int *subShapeIdPtr,
        int numSubShapeIds,
        hkpBreakableMaterial::ShapeKeyCollector *collector)
{
  __int64 v5; // rbx
  __int64 v7; // r14
  int i; // esi

  v5 = 0i64;
  v7 = numSubShapeIds;
  for ( i = -1 << BYTE1(this->m_typeAndFlags); v5 < v7; ++v5 )
    collector->vfptr->addContiguousShapeKeyRange(collector, i & subShapeIdPtr[v5], (~i & subShapeIdPtr[v5]) + 1);
}

// File Line: 181
// RVA: 0xD79D60
void __fastcall hkpExtendedMeshShapeBreakableMaterial::getSubShapeMaterialIndices(
        hkpExtendedMeshShapeBreakableMaterial *this,
        hkcdShape *rootShape,
        hkArray<unsigned int,hkContainerHeapAllocator> *subShapeIdsIn,
        hkArray<short,hkContainerHeapAllocator> *subMaterialsOut)
{
  int m_size; // esi
  __int64 v5; // r14
  int m_capacityAndFlags; // eax
  int v8; // r9d
  int v10; // eax
  int v12; // eax
  __int16 *m_data; // rax
  __int16 *v14; // r10
  __int64 i; // r8
  __int64 v16; // r9
  hkBaseObjectVtbl *v17; // rax
  hkResult result; // [rsp+58h] [rbp+10h] BYREF

  m_size = subShapeIdsIn->m_size;
  v5 = subMaterialsOut->m_size;
  m_capacityAndFlags = subMaterialsOut->m_capacityAndFlags;
  v8 = v5 + m_size;
  v10 = m_capacityAndFlags & 0x3FFFFFFF;
  if ( v10 < (int)v5 + m_size )
  {
    v12 = 2 * v10;
    if ( v8 < v12 )
      v8 = v12;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&subMaterialsOut->m_data, v8, 2);
  }
  m_data = subMaterialsOut->m_data;
  subMaterialsOut->m_size += m_size;
  v14 = &m_data[v5];
  if ( rootShape->m_type.m_storage == 9 )
    rootShape = *(hkcdShape **)&rootShape[3].m_type.m_storage;
  for ( i = m_size - 1; i >= 0; v14[i + 1] = WORD1(v17->__vecDelDtor) )
  {
    v16 = (subShapeIdsIn->m_data[i] & 0x7FFFFFFF) >> (32 - rootShape[9].m_type.m_storage);
    if ( (subShapeIdsIn->m_data[i] & 0x80000000) != 0 )
      v17 = (hkBaseObjectVtbl *)(*(_QWORD *)&rootShape[10].m_type.m_storage + 80 * v16);
    else
      v17 = &rootShape[10].vfptr[9 * v16];
    --i;
  }
}

