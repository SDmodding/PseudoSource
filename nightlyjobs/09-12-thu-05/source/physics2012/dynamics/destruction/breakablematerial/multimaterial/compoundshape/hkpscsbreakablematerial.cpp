// File Line: 17
// RVA: 0xD7A930
void __fastcall hkpStaticCompoundShapeBreakableMaterial::hkpStaticCompoundShapeBreakableMaterial(hkpStaticCompoundShapeBreakableMaterial *this, hkArray<hkpBreakableMaterial *,hkContainerHeapAllocator> *subMaterials, float strength)
{
  hkpStaticCompoundShapeBreakableMaterial *v3; // rbx

  v3 = this;
  hkpBreakableMultiMaterial::hkpBreakableMultiMaterial(
    (hkpBreakableMultiMaterial *)&this->vfptr,
    subMaterials,
    strength);
  v3->m_typeAndFlags &= 0xFFFFFF2F;
  v3->m_typeAndFlags |= 0x20u;
  v3->vfptr = (hkBaseObjectVtbl *)&hkpStaticCompoundShapeBreakableMaterial::`vftable;
}

// File Line: 25
// RVA: 0xD7A9D0
hkClass *__fastcall hkpStaticCompoundShapeBreakableMaterial::getClassType(hkpStaticCompoundShapeBreakableMaterial *this)
{
  return &hkpStaticCompoundShapeBreakableMaterialClass;
}

// File Line: 34
// RVA: 0xD7A9A0
void __fastcall hkpStaticCompoundShapeBreakableMaterial::hkpStaticCompoundShapeBreakableMaterial(hkpStaticCompoundShapeBreakableMaterial *this, hkFinishLoadedObjectFlag flag)
{
  hkpStaticCompoundShapeBreakableMaterial *v2; // rbx

  v2 = this;
  hkpBreakableMultiMaterial::hkpBreakableMultiMaterial((hkpBreakableMultiMaterial *)&this->vfptr, flag);
  v2->vfptr = (hkBaseObjectVtbl *)&hkpStaticCompoundShapeBreakableMaterial::`vftable;
}

// File Line: 41
// RVA: 0xD7A970
void __fastcall hkpStaticCompoundShapeBreakableMaterial::hkpStaticCompoundShapeBreakableMaterial(hkpStaticCompoundShapeBreakableMaterial *this, hkpStaticCompoundShapeBreakableMaterial *other)
{
  hkpStaticCompoundShapeBreakableMaterial *v2; // rbx

  v2 = this;
  hkpBreakableMultiMaterial::hkpBreakableMultiMaterial(
    (hkpBreakableMultiMaterial *)&this->vfptr,
    (hkpBreakableMultiMaterial *)&other->vfptr);
  v2->vfptr = (hkBaseObjectVtbl *)&hkpStaticCompoundShapeBreakableMaterial::`vftable;
}

// File Line: 47
// RVA: 0xD7A9E0
void __fastcall hkpStaticCompoundShapeBreakableMaterial::duplicate(hkpStaticCompoundShapeBreakableMaterial *this)
{
  hkpStaticCompoundShapeBreakableMaterial *v1; // rbx
  _QWORD **v2; // rax
  hkpStaticCompoundShapeBreakableMaterial *v3; // rax

  v1 = this;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkpStaticCompoundShapeBreakableMaterial *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(
                                                    v2[11],
                                                    56i64);
  if ( v3 )
    hkpStaticCompoundShapeBreakableMaterial::hkpStaticCompoundShapeBreakableMaterial(v3, v1);
}

// File Line: 55
// RVA: 0xD7AA30
void __fastcall hkpStaticCompoundShapeBreakableMaterial::setDefaultMapping(hkpStaticCompoundShapeBreakableMaterial *this)
{
  this->m_typeAndFlags &= 0xFFFFFF2F;
  this->m_typeAndFlags |= 0x20u;
}

// File Line: 63
// RVA: 0xD7AA50
__int64 __fastcall hkpStaticCompoundShapeBreakableMaterial::getSubShapeMaterialIndex(hkpStaticCompoundShapeBreakableMaterial *this, hkcdShape *rootShape, unsigned int subShapeId)
{
  return *((unsigned __int16 *)&rootShape[3].vfptr->__vecDelDtor + (signed int)subShapeId);
}

// File Line: 74
// RVA: 0xD7AA70
hkpBreakableMaterial *__fastcall hkpStaticCompoundShapeBreakableMaterial::getShapeKeyMaterial(hkpStaticCompoundShapeBreakableMaterial *this, hkcdShape *shapePpu, unsigned int shapeKey)
{
  return this->m_subMaterials.m_data[*((signed __int16 *)&shapePpu[3].vfptr->__vecDelDtor
                                     + (signed int)(shapeKey >> (LOWORD(this->m_typeAndFlags) >> 8)))].m_pntr;
}

// File Line: 91
// RVA: 0xD7AAA0
__int64 __fastcall hkpStaticCompoundShapeBreakableMaterial::convertShapeKeyToSubShapeId(hkpStaticCompoundShapeBreakableMaterial *this, unsigned int shapeKey)
{
  return shapeKey >> (LOWORD(this->m_typeAndFlags) >> 8);
}

// File Line: 101
// RVA: 0xD7AAC0
void __fastcall hkpStaticCompoundShapeBreakableMaterial::convertShapeKeysToSubShapeIds(hkpStaticCompoundShapeBreakableMaterial *this, hkArray<unsigned int,hkContainerHeapAllocator> *shapeKeysInOut)
{
  int v2; // eax
  char v3; // r9
  __int64 v4; // rax

  v2 = this->m_typeAndFlags;
  v3 = BYTE1(v2);
  v4 = shapeKeysInOut->m_size - 1;
  if ( (signed int)v4 >= 0 )
  {
    do
      shapeKeysInOut->m_data[v4--] >>= v3;
    while ( v4 >= 0 );
  }
}

// File Line: 113
// RVA: 0xD7ACB0
void __fastcall hkpStaticCompoundShapeBreakableMaterial::disableSubShapes(hkpStaticCompoundShapeBreakableMaterial *this, hkcdShape *rootShape, const __int16 *subMaterialIndices, int numSubMaterialIndices)
{
  hkcdShape *v4; // r11
  __int64 i; // r10
  hkpBreakableMultiMaterial::InverseMapping *v6; // r9
  __int64 v7; // rdx
  hkpBreakableMultiMaterial::InverseMappingDescriptor *v8; // rax
  signed __int64 v9; // r9
  __int64 v10; // rax
  signed __int64 v11; // rdx

  v4 = rootShape;
  for ( i = numSubMaterialIndices - 1; i >= 0; --i )
  {
    v6 = this->m_inverseMapping.m_pntr;
    v7 = subMaterialIndices[i];
    v8 = v6->m_descriptors.m_data;
    v9 = (signed __int64)&v6->m_subShapeIds.m_data[v8[v7].m_offset];
    v10 = v8[v7].m_numKeys - 1;
    if ( (signed int)v10 >= 0 )
    {
      do
      {
        v11 = *(_QWORD *)&v4[2].m_memSizeAndFlags + 80i64 * *(signed int *)(v9 + 4 * v10);
        *(_DWORD *)(v11 + 12) |= 0x3F000010u;
        --v10;
      }
      while ( v10 >= 0 );
    }
  }
}

// File Line: 140
// RVA: 0xD7AB00
void __fastcall hkpStaticCompoundShapeBreakableMaterial::getShapeKeysForSubShapes(hkpStaticCompoundShapeBreakableMaterial *this, hkcdShape *rootShape, const unsigned int *subShapeIdPtr, int numSubShapeIds, hkpBreakableMaterial::ShapeKeyCollector *collector)
{
  __int64 v5; // rbp
  const unsigned int *v6; // r12
  hkcdShape *v7; // r13
  __int64 v8; // r15
  int v9; // ecx
  unsigned int v10; // er14
  __int64 v11; // rax
  __int64 v12; // rdi
  unsigned int i; // ebx
  int v14; // [rsp+68h] [rbp+20h]

  v5 = 0i64;
  v6 = subShapeIdPtr;
  v7 = rootShape;
  v8 = numSubShapeIds;
  v9 = (unsigned __int8)(LOWORD(this->m_typeAndFlags) >> 8);
  v14 = v9;
  if ( numSubShapeIds > 0 )
  {
    do
    {
      v10 = v6[v5] << v9;
      v11 = (*(__int64 (**)(void))(**(_QWORD **)(*(_QWORD *)&v7[2].m_memSizeAndFlags + 80i64 * (signed int)v6[v5] + 48)
                                 + 112i64))();
      v12 = v11;
      if ( v11 )
      {
        for ( i = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v11 + 16i64))(v11);
              i != -1;
              i = (*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v12 + 24i64))(v12, i) )
        {
          collector->vfptr->addShapeKey(collector, v10 | i);
        }
      }
      else
      {
        collector->vfptr->addShapeKey(collector, v10);
      }
      LOBYTE(v9) = v14;
      ++v5;
    }
    while ( v5 < v8 );
  }
}

// File Line: 174
// RVA: 0xD7AC00
void __fastcall hkpStaticCompoundShapeBreakableMaterial::getSubShapeMaterialIndices(hkpStaticCompoundShapeBreakableMaterial *this, hkcdShape *rootShape, hkArray<unsigned int,hkContainerHeapAllocator> *subShapeIdsIn, hkArray<short,hkContainerHeapAllocator> *subMaterialsOut)
{
  int v4; // ebp
  __int64 v5; // r14
  hkArray<short,hkContainerHeapAllocator> *v6; // rsi
  int v7; // eax
  int v8; // er9
  hkArray<unsigned int,hkContainerHeapAllocator> *v9; // rbx
  int v10; // eax
  hkcdShape *v11; // rdi
  int v12; // eax
  __int16 *v13; // rax
  signed __int64 v14; // r8
  __int64 i; // rax
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
  for ( i = v4 - 1;
        i >= 0;
        *(_WORD *)(v14 + 2 * i + 2) = *((_WORD *)&v11[3].vfptr->__vecDelDtor + (signed int)v9->m_data[i + 1]) )
  {
    --i;
  }
}

