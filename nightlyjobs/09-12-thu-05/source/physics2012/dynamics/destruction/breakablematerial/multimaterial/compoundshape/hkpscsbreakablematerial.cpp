// File Line: 17
// RVA: 0xD7A930
void __fastcall hkpStaticCompoundShapeBreakableMaterial::hkpStaticCompoundShapeBreakableMaterial(
        hkpStaticCompoundShapeBreakableMaterial *this,
        hkArray<hkpBreakableMaterial *,hkContainerHeapAllocator> *subMaterials,
        float strength)
{
  hkpBreakableMultiMaterial::hkpBreakableMultiMaterial(this, subMaterials, strength);
  this->m_typeAndFlags &= 0xFFFFFF2F;
  this->m_typeAndFlags |= 0x20u;
  this->vfptr = (hkBaseObjectVtbl *)&hkpStaticCompoundShapeBreakableMaterial::`vftable;
}

// File Line: 25
// RVA: 0xD7A9D0
hkClass *__fastcall hkpStaticCompoundShapeBreakableMaterial::getClassType(
        hkpStaticCompoundShapeBreakableMaterial *this)
{
  return &hkpStaticCompoundShapeBreakableMaterialClass;
}

// File Line: 34
// RVA: 0xD7A9A0
void __fastcall hkpStaticCompoundShapeBreakableMaterial::hkpStaticCompoundShapeBreakableMaterial(
        hkpStaticCompoundShapeBreakableMaterial *this,
        hkFinishLoadedObjectFlag flag)
{
  hkpBreakableMultiMaterial::hkpBreakableMultiMaterial(this, flag);
  this->vfptr = (hkBaseObjectVtbl *)&hkpStaticCompoundShapeBreakableMaterial::`vftable;
}

// File Line: 41
// RVA: 0xD7A970
void __fastcall hkpStaticCompoundShapeBreakableMaterial::hkpStaticCompoundShapeBreakableMaterial(
        hkpStaticCompoundShapeBreakableMaterial *this,
        hkpStaticCompoundShapeBreakableMaterial *other)
{
  hkpBreakableMultiMaterial::hkpBreakableMultiMaterial(this, other);
  this->vfptr = (hkBaseObjectVtbl *)&hkpStaticCompoundShapeBreakableMaterial::`vftable;
}

// File Line: 47
// RVA: 0xD7A9E0
void __fastcall hkpStaticCompoundShapeBreakableMaterial::duplicate(hkpStaticCompoundShapeBreakableMaterial *this)
{
  _QWORD **Value; // rax
  hkpStaticCompoundShapeBreakableMaterial *v3; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkpStaticCompoundShapeBreakableMaterial *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                                    Value[11],
                                                    56i64);
  if ( v3 )
    hkpStaticCompoundShapeBreakableMaterial::hkpStaticCompoundShapeBreakableMaterial(v3, this);
}

// File Line: 55
// RVA: 0xD7AA30
void __fastcall hkpStaticCompoundShapeBreakableMaterial::setDefaultMapping(
        hkpStaticCompoundShapeBreakableMaterial *this)
{
  this->m_typeAndFlags &= 0xFFFFFF2F;
  this->m_typeAndFlags |= 0x20u;
}

// File Line: 63
// RVA: 0xD7AA50
__int64 __fastcall hkpStaticCompoundShapeBreakableMaterial::getSubShapeMaterialIndex(
        hkpStaticCompoundShapeBreakableMaterial *this,
        hkcdShape *rootShape,
        int subShapeId)
{
  return *((unsigned __int16 *)&rootShape[3].vfptr->__vecDelDtor + subShapeId);
}

// File Line: 74
// RVA: 0xD7AA70
hkpBreakableMaterial *__fastcall hkpStaticCompoundShapeBreakableMaterial::getShapeKeyMaterial(
        hkpStaticCompoundShapeBreakableMaterial *this,
        hkcdShape *shapePpu,
        unsigned int shapeKey)
{
  return this->m_subMaterials.m_data[*((__int16 *)&shapePpu[3].vfptr->__vecDelDtor
                                     + (int)(shapeKey >> BYTE1(this->m_typeAndFlags)))].m_pntr;
}

// File Line: 91
// RVA: 0xD7AAA0
__int64 __fastcall hkpStaticCompoundShapeBreakableMaterial::convertShapeKeyToSubShapeId(
        hkpStaticCompoundShapeBreakableMaterial *this,
        unsigned int shapeKey)
{
  return shapeKey >> BYTE1(this->m_typeAndFlags);
}

// File Line: 101
// RVA: 0xD7AAC0
void __fastcall hkpStaticCompoundShapeBreakableMaterial::convertShapeKeysToSubShapeIds(
        hkpStaticCompoundShapeBreakableMaterial *this,
        hkArray<unsigned int,hkContainerHeapAllocator> *shapeKeysInOut)
{
  char v2; // r9
  __int64 v3; // rax

  v2 = BYTE1(this->m_typeAndFlags);
  v3 = shapeKeysInOut->m_size - 1;
  if ( (int)v3 >= 0 )
  {
    do
      shapeKeysInOut->m_data[v3--] >>= v2;
    while ( v3 >= 0 );
  }
}

// File Line: 113
// RVA: 0xD7ACB0
void __fastcall hkpStaticCompoundShapeBreakableMaterial::disableSubShapes(
        hkpStaticCompoundShapeBreakableMaterial *this,
        hkcdShape *rootShape,
        const __int16 *subMaterialIndices,
        int numSubMaterialIndices)
{
  __int64 i; // r10
  hkpBreakableMultiMaterial::InverseMapping *m_pntr; // r9
  __int64 v7; // rdx
  hkpBreakableMultiMaterial::InverseMappingDescriptor *m_data; // rax
  __int64 v9; // r9
  __int64 v10; // rax
  __int64 v11; // rdx

  for ( i = numSubMaterialIndices - 1; i >= 0; --i )
  {
    m_pntr = this->m_inverseMapping.m_pntr;
    v7 = subMaterialIndices[i];
    m_data = m_pntr->m_descriptors.m_data;
    v9 = (__int64)&m_pntr->m_subShapeIds.m_data[m_data[v7].m_offset];
    v10 = m_data[v7].m_numKeys - 1;
    if ( (int)v10 >= 0 )
    {
      do
      {
        v11 = *(_QWORD *)&rootShape[2].m_memSizeAndFlags + 80i64 * *(int *)(v9 + 4 * v10);
        *(_DWORD *)(v11 + 12) |= 0x3F000010u;
        --v10;
      }
      while ( v10 >= 0 );
    }
  }
}

// File Line: 140
// RVA: 0xD7AB00
void __fastcall hkpStaticCompoundShapeBreakableMaterial::getShapeKeysForSubShapes(
        hkpStaticCompoundShapeBreakableMaterial *this,
        hkcdShape *rootShape,
        const unsigned int *subShapeIdPtr,
        int numSubShapeIds,
        hkpBreakableMaterial::ShapeKeyCollector *collector)
{
  __int64 v5; // rbp
  __int64 v8; // r15
  char v9; // cl
  unsigned int v10; // r14d
  __int64 v11; // rcx
  __int64 v12; // rax
  __int64 v13; // rdi
  unsigned int j; // ebx
  char i; // [rsp+68h] [rbp+20h]

  v5 = 0i64;
  v8 = numSubShapeIds;
  v9 = BYTE1(this->m_typeAndFlags);
  for ( i = v9; v5 < v8; ++v5 )
  {
    v10 = subShapeIdPtr[v5] << v9;
    v11 = *(_QWORD *)(*(_QWORD *)&rootShape[2].m_memSizeAndFlags + 80i64 * (int)subShapeIdPtr[v5] + 48);
    v12 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v11 + 112i64))(v11);
    v13 = v12;
    if ( v12 )
    {
      for ( j = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v12 + 16i64))(v12);
            j != -1;
            j = (*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v13 + 24i64))(v13, j) )
      {
        collector->vfptr->addShapeKey(collector, v10 | j);
      }
    }
    else
    {
      collector->vfptr->addShapeKey(collector, v10);
    }
    v9 = i;
  }
}

// File Line: 174
// RVA: 0xD7AC00
void __fastcall hkpStaticCompoundShapeBreakableMaterial::getSubShapeMaterialIndices(
        hkpStaticCompoundShapeBreakableMaterial *this,
        hkcdShape *rootShape,
        hkArray<unsigned int,hkContainerHeapAllocator> *subShapeIdsIn,
        hkArray<short,hkContainerHeapAllocator> *subMaterialsOut)
{
  int m_size; // ebp
  __int64 v5; // r14
  int m_capacityAndFlags; // eax
  int v8; // r9d
  int v10; // eax
  int v12; // eax
  __int16 *m_data; // rax
  __int16 *v14; // r8
  __int64 i; // rax
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
  for ( i = m_size - 1;
        i >= 0;
        v14[i + 1] = *((_WORD *)&rootShape[3].vfptr->__vecDelDtor + (int)subShapeIdsIn->m_data[i + 1]) )
  {
    --i;
  }
}

