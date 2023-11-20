// File Line: 17
// RVA: 0xD79A90
void __fastcall hkpExtendedMeshShapeBreakableMaterial::hkpExtendedMeshShapeBreakableMaterial(hkpExtendedMeshShapeBreakableMaterial *this, hkArray<hkpBreakableMaterial *,hkContainerHeapAllocator> *subMaterials, int numBitsPerSubPart, float strength)
{
  char v4; // bl
  hkpExtendedMeshShapeBreakableMaterial *v5; // rdi

  v4 = numBitsPerSubPart;
  v5 = this;
  hkpBreakableMultiMaterial::hkpBreakableMultiMaterial(
    (hkpBreakableMultiMaterial *)&this->vfptr,
    subMaterials,
    strength);
  BYTE1(v5->m_typeAndFlags) = 0;
  v5->vfptr = (hkBaseObjectVtbl *)&hkpExtendedMeshShapeBreakableMaterial::`vftable';
  v5->m_typeAndFlags = (v5->m_typeAndFlags | ((unsigned __int8)(32 - v4) << 8)) & 0xFFFFFF4F | 0x40;
}

// File Line: 26
// RVA: 0xD79B50
hkClass *__fastcall hkpExtendedMeshShapeBreakableMaterial::getClassType(hkpExtendedMeshShapeBreakableMaterial *this)
{
  return &hkpExtendedMeshShapeBreakableMaterialClass;
}

// File Line: 35
// RVA: 0xD79B20
void __fastcall hkpExtendedMeshShapeBreakableMaterial::hkpExtendedMeshShapeBreakableMaterial(hkpExtendedMeshShapeBreakableMaterial *this, hkFinishLoadedObjectFlag flag)
{
  hkpExtendedMeshShapeBreakableMaterial *v2; // rbx

  v2 = this;
  hkpBreakableMultiMaterial::hkpBreakableMultiMaterial((hkpBreakableMultiMaterial *)&this->vfptr, flag);
  v2->vfptr = (hkBaseObjectVtbl *)&hkpExtendedMeshShapeBreakableMaterial::`vftable';
}

// File Line: 42
// RVA: 0xD79AF0
void __fastcall hkpExtendedMeshShapeBreakableMaterial::hkpExtendedMeshShapeBreakableMaterial(hkpExtendedMeshShapeBreakableMaterial *this, hkpExtendedMeshShapeBreakableMaterial *other)
{
  hkpExtendedMeshShapeBreakableMaterial *v2; // rbx

  v2 = this;
  hkpBreakableMultiMaterial::hkpBreakableMultiMaterial(
    (hkpBreakableMultiMaterial *)&this->vfptr,
    (hkpBreakableMultiMaterial *)&other->vfptr);
  v2->vfptr = (hkBaseObjectVtbl *)&hkpExtendedMeshShapeBreakableMaterial::`vftable';
}

// File Line: 48
// RVA: 0xD79E50
void __fastcall hkpExtendedMeshShapeBreakableMaterial::createInverseMapping(hkpExtendedMeshShapeBreakableMaterial *this, hkcdShape *shape)
{
  hkcdShape *v2; // rbx
  hkpExtendedMeshShapeBreakableMaterial *v3; // rdi
  hkpBreakableMultiMaterial::InverseMapping *v4; // rbp
  unsigned int *v5; // rsi
  int v6; // eax
  __int64 i; // r11
  hkpBreakableMultiMaterial::InverseMappingDescriptor *v8; // rax
  int v9; // er8
  hkpBreakableMultiMaterial::InverseMappingDescriptor *j; // rdi
  unsigned int *v11; // r10
  signed int v12; // edx
  signed __int64 v13; // rax
  int v14; // eax

  v2 = shape;
  v3 = this;
  hkpBreakableMultiMaterial::createInverseMapping((hkpBreakableMultiMaterial *)&this->vfptr, shape);
  if ( v2->m_type.m_storage == 9 )
    v2 = *(hkcdShape **)&v2[3].m_type.m_storage;
  v4 = v3->m_inverseMapping.m_pntr;
  v5 = v4->m_subShapeIds.m_data;
  v6 = v4->m_descriptors.m_size - 1;
  for ( i = v6; i >= 0; --i )
  {
    v8 = v4->m_descriptors.m_data;
    v9 = v8[i].m_numKeys - 1;
    for ( j = &v8[i]; v9 >= 0; *v11 |= v14 - 1 )
    {
      v11 = &v5[v9 + j->m_offset];
      v12 = (*v11 & 0x7FFFFFFF) >> (32 - v2[9].m_type.m_storage);
      if ( (*v11 & 0x80000000) != 0 )
        v13 = *(_QWORD *)&v2[10].m_type.m_storage + 80i64 * v12;
      else
        v13 = (signed __int64)&v2[10].vfptr[9 * v12];
      if ( *(_BYTE *)v13 & 1 )
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
  hkpExtendedMeshShapeBreakableMaterial *v1; // rbx
  _QWORD **v2; // rax
  hkpExtendedMeshShapeBreakableMaterial *v3; // rax

  v1 = this;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkpExtendedMeshShapeBreakableMaterial *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(
                                                  v2[11],
                                                  56i64);
  if ( v3 )
    hkpExtendedMeshShapeBreakableMaterial::hkpExtendedMeshShapeBreakableMaterial(v3, v1);
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
__int64 __fastcall hkpExtendedMeshShapeBreakableMaterial::getSubShapeMaterialIndex(hkpExtendedMeshShapeBreakableMaterial *this, hkcdShape *rootShape, unsigned int subShapeId)
{
  __int64 v3; // r9
  hkBaseObjectVtbl *v4; // rcx

  if ( rootShape->m_type.m_storage == 9 )
    rootShape = *(hkcdShape **)&rootShape[3].m_type.m_storage;
  v3 = (subShapeId & 0x7FFFFFFF) >> (32 - rootShape[9].m_type.m_storage);
  if ( (subShapeId & 0x80000000) != 0 )
    v4 = (hkBaseObjectVtbl *)(*(_QWORD *)&rootShape[10].m_type.m_storage + 80 * v3);
  else
    v4 = &rootShape[10].vfptr[9 * v3];
  return WORD1(v4->__vecDelDtor);
}

// File Line: 120
// RVA: 0xD79C10
hkpBreakableMaterial *__fastcall hkpExtendedMeshShapeBreakableMaterial::getShapeKeyMaterial(hkpExtendedMeshShapeBreakableMaterial *this, hkcdShape *shapePpu, unsigned int shapeKey)
{
  hkpExtendedMeshShapeBreakableMaterial *v3; // r10
  __int64 v4; // r9
  __int64 v5; // rcx

  v3 = this;
  if ( shapePpu->m_type.m_storage == 9 )
    shapePpu = *(hkcdShape **)&shapePpu[3].m_type.m_storage;
  v4 = (shapeKey & 0x7FFFFFFF) >> (32 - shapePpu[9].m_type.m_storage);
  if ( (shapeKey & 0x80000000) != 0 )
    v5 = *(signed __int16 *)(*(_QWORD *)&shapePpu[10].m_type.m_storage + 80 * v4 + 2);
  else
    v5 = SWORD1(shapePpu[10].vfptr[9 * v4].__vecDelDtor);
  return v3->m_subMaterials.m_data[v5].m_pntr;
}

// File Line: 134
// RVA: 0xD79C80
__int64 __fastcall hkpExtendedMeshShapeBreakableMaterial::convertShapeKeyToSubShapeId(hkpExtendedMeshShapeBreakableMaterial *this, unsigned int shapeKey)
{
  return shapeKey & (-1 << (LOWORD(this->m_typeAndFlags) >> 8));
}

// File Line: 146
// RVA: 0xD79CA0
void __fastcall hkpExtendedMeshShapeBreakableMaterial::convertShapeKeysToSubShapeIds(hkpExtendedMeshShapeBreakableMaterial *this, hkArray<unsigned int,hkContainerHeapAllocator> *shapeKeysInOut)
{
  signed int v2; // er8
  __int64 v3; // rax

  v2 = -1 << (LOWORD(this->m_typeAndFlags) >> 8);
  v3 = shapeKeysInOut->m_size - 1;
  if ( (signed int)v3 >= 0 )
  {
    do
      shapeKeysInOut->m_data[v3--] &= v2;
    while ( v3 >= 0 );
  }
}

// File Line: 161
// RVA: 0xD79CE0
void __fastcall hkpExtendedMeshShapeBreakableMaterial::getShapeKeysForSubShapes(hkpExtendedMeshShapeBreakableMaterial *this, hkcdShape *__formal, const unsigned int *subShapeIdPtr, int numSubShapeIds, hkpBreakableMaterial::ShapeKeyCollector *collector)
{
  __int64 v5; // rbx
  const unsigned int *v6; // r15
  __int64 v7; // r14
  signed int v8; // esi

  v5 = 0i64;
  v6 = subShapeIdPtr;
  v7 = numSubShapeIds;
  v8 = -1 << (LOWORD(this->m_typeAndFlags) >> 8);
  if ( numSubShapeIds > 0 )
  {
    do
    {
      collector->vfptr->addContiguousShapeKeyRange(collector, v8 & v6[v5], (~v8 & v6[v5]) + 1);
      ++v5;
    }
    while ( v5 < v7 );
  }
}

// File Line: 181
// RVA: 0xD79D60
void __fastcall hkpExtendedMeshShapeBreakableMaterial::getSubShapeMaterialIndices(hkpExtendedMeshShapeBreakableMaterial *this, hkcdShape *rootShape, hkArray<unsigned int,hkContainerHeapAllocator> *subShapeIdsIn, hkArray<short,hkContainerHeapAllocator> *subMaterialsOut)
{
  int v4; // esi
  __int64 v5; // r14
  hkArray<short,hkContainerHeapAllocator> *v6; // rdi
  int v7; // eax
  int v8; // er9
  hkArray<unsigned int,hkContainerHeapAllocator> *v9; // r15
  int v10; // eax
  hkcdShape *v11; // rbx
  int v12; // eax
  __int16 *v13; // rax
  signed __int64 v14; // r10
  __int64 i; // r8
  __int64 v16; // r9
  signed __int64 v17; // rax
  hkResult result; // [rsp+58h] [rbp+10h]

  v4 = subShapeIdsIn->m_size;
  v5 = subMaterialsOut->m_size;
  v6 = subMaterialsOut;
  v7 = subMaterialsOut->m_capacityAndFlags;
  v8 = v5 + v4;
  v9 = subShapeIdsIn;
  v10 = v7 & 0x3FFFFFFF;
  v11 = rootShape;
  if ( v10 < (signed int)v5 + v4 )
  {
    v12 = 2 * v10;
    if ( v8 < v12 )
      v8 = v12;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6, v8, 2);
  }
  v13 = v6->m_data;
  v6->m_size += v4;
  v14 = (signed __int64)&v13[v5];
  if ( v11->m_type.m_storage == 9 )
    v11 = *(hkcdShape **)&v11[3].m_type.m_storage;
  for ( i = v4 - 1; i >= 0; *(_WORD *)(v14 + 2 * --i + 2) = *(_WORD *)(v17 + 2) )
  {
    v16 = (v9->m_data[i] & 0x7FFFFFFF) >> (32 - v11[9].m_type.m_storage);
    if ( (v9->m_data[i] & 0x80000000) != 0 )
      v17 = *(_QWORD *)&v11[10].m_type.m_storage + 80 * v16;
    else
      v17 = (signed __int64)&v11[10].vfptr[9 * v16];
  }
}

