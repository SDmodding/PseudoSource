// File Line: 18
// RVA: 0xD775B0
void __fastcall hkpBreakableMultiMaterial::hkpBreakableMultiMaterial(
        hkpBreakableMultiMaterial *this,
        hkArray<hkpBreakableMaterial *,hkContainerHeapAllocator> *subMaterials,
        float strength)
{
  __int64 v3; // rbx
  __int64 m_size; // r15
  int v7; // eax
  int v8; // eax
  int v9; // r9d
  hkRefPtr<hkpBreakableMaterial> *v10; // rsi
  int v11; // eax
  __int64 i; // rdi
  hkReferencedObject *m_pntr; // rcx
  int v14; // edx
  hkRefPtr<hkpBreakableMaterial> *v15; // r8
  __int64 v16; // rax
  hkRefPtr<hkpBreakableMaterial> *m_data; // rsi
  hkpBreakableMaterial *v18; // rdi
  hkReferencedObject *v19; // rcx
  hkResult result; // [rsp+70h] [rbp+18h] BYREF

  this->m_strength = strength;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_typeAndFlags = 2;
  v3 = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkpBreakableMultiMaterial::`vftable;
  this->m_properties = 0i64;
  this->m_subMaterials.m_data = 0i64;
  this->m_subMaterials.m_size = 0;
  this->m_subMaterials.m_capacityAndFlags = 0x80000000;
  this->m_inverseMapping.m_pntr = 0i64;
  m_size = subMaterials->m_size;
  v7 = this->m_subMaterials.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v7 < (int)m_size )
  {
    v8 = 2 * v7;
    v9 = subMaterials->m_size;
    if ( (int)m_size < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&this->m_subMaterials.m_data,
      v9,
      8);
  }
  v10 = &this->m_subMaterials.m_data[m_size];
  v11 = this->m_subMaterials.m_size - m_size - 1;
  for ( i = v11; i >= 0; v10[i--].m_pntr = 0i64 )
  {
    m_pntr = v10[i].m_pntr;
    if ( m_pntr )
      hkReferencedObject::removeReference(m_pntr);
  }
  v14 = m_size - this->m_subMaterials.m_size;
  v15 = &this->m_subMaterials.m_data[this->m_subMaterials.m_size];
  v16 = v14;
  if ( v14 > 0 )
  {
    do
    {
      if ( v15 )
        v15->m_pntr = 0i64;
      ++v15;
      --v16;
    }
    while ( v16 );
  }
  this->m_subMaterials.m_size = m_size;
  if ( (int)m_size > 0 )
  {
    do
    {
      m_data = this->m_subMaterials.m_data;
      v18 = subMaterials->m_data[v3];
      if ( v18 )
        hkReferencedObject::addReference(subMaterials->m_data[v3]);
      v19 = m_data[v3].m_pntr;
      if ( v19 )
        hkReferencedObject::removeReference(v19);
      m_data[v3++].m_pntr = v18;
    }
    while ( v3 < m_size );
  }
}

// File Line: 34
// RVA: 0xD77710
void __fastcall hkpBreakableMultiMaterial::hkpBreakableMultiMaterial(
        hkpBreakableMultiMaterial *this,
        hkpBreakableMultiMaterial *other)
{
  hkpBreakableMultiMaterial::InverseMapping *m_pntr; // rcx
  __int64 m_size; // rsi
  int v6; // eax
  int v7; // eax
  int v8; // r9d
  hkRefPtr<hkpBreakableMaterial> *v9; // rdi
  int v10; // eax
  __int64 i; // rbx
  hkReferencedObject *v12; // rcx
  int v13; // edx
  hkRefPtr<hkpBreakableMaterial> *v14; // r8
  __int64 v15; // rax
  __int64 j; // rbx
  hkRefPtr<hkpBreakableMaterial> *m_data; // rsi
  hkRefPtr<hkpBreakableMaterial> *v18; // rdi
  hkReferencedObject *v19; // rcx
  hkReferencedObject *v20; // rcx
  hkpBreakableMaterial *v21; // rax
  hkResult result; // [rsp+60h] [rbp+8h] BYREF

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpBreakableMaterial::`vftable;
  this->m_strength = other->m_strength;
  this->m_typeAndFlags = other->m_typeAndFlags;
  this->m_properties = other->m_properties;
  this->vfptr = (hkBaseObjectVtbl *)&hkpBreakableMultiMaterial::`vftable;
  this->m_subMaterials.m_data = 0i64;
  this->m_subMaterials.m_size = 0;
  this->m_subMaterials.m_capacityAndFlags = 0x80000000;
  m_pntr = other->m_inverseMapping.m_pntr;
  if ( m_pntr )
    hkReferencedObject::addReference(m_pntr);
  this->m_inverseMapping.m_pntr = other->m_inverseMapping.m_pntr;
  m_size = other->m_subMaterials.m_size;
  v6 = this->m_subMaterials.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v6 < (int)m_size )
  {
    v7 = 2 * v6;
    v8 = other->m_subMaterials.m_size;
    if ( (int)m_size < v7 )
      v8 = v7;
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&this->m_subMaterials.m_data,
      v8,
      8);
  }
  v9 = &this->m_subMaterials.m_data[m_size];
  v10 = this->m_subMaterials.m_size - m_size - 1;
  for ( i = v10; i >= 0; v9[i--].m_pntr = 0i64 )
  {
    v12 = v9[i].m_pntr;
    if ( v12 )
      hkReferencedObject::removeReference(v12);
  }
  v13 = m_size - this->m_subMaterials.m_size;
  v14 = &this->m_subMaterials.m_data[this->m_subMaterials.m_size];
  v15 = v13;
  if ( v13 > 0 )
  {
    do
    {
      if ( v14 )
        v14->m_pntr = 0i64;
      ++v14;
      --v15;
    }
    while ( v15 );
  }
  this->m_subMaterials.m_size = m_size;
  for ( j = (int)m_size - 1; j >= 0; v18[j + 1].m_pntr = v21 )
  {
    m_data = other->m_subMaterials.m_data;
    v18 = this->m_subMaterials.m_data;
    v19 = m_data[j].m_pntr;
    if ( v19 )
      hkReferencedObject::addReference(v19);
    v20 = v18[j].m_pntr;
    if ( v20 )
      hkReferencedObject::removeReference(v20);
    v21 = m_data[j--].m_pntr;
  }
}

// File Line: 48
// RVA: 0xD778A0
void __fastcall hkpBreakableMultiMaterial::InverseMapping::InverseMapping(
        hkpBreakableMultiMaterial::InverseMapping *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpBreakableMultiMaterial::InverseMapping::`vftable;
  this->m_descriptors.m_capacityAndFlags = 0x80000000;
  this->m_descriptors.m_data = 0i64;
  this->m_descriptors.m_size = 0;
  this->m_subShapeIds.m_data = 0i64;
  this->m_subShapeIds.m_size = 0;
  this->m_subShapeIds.m_capacityAndFlags = 0x80000000;
}

// File Line: 57
// RVA: 0xD77880
void __fastcall hkpBreakableMultiMaterial::hkpBreakableMultiMaterial(
        hkpBreakableMultiMaterial *this,
        hkFinishLoadedObjectFlag flag)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkpBreakableMultiMaterial::`vftable;
}

// File Line: 66
// RVA: 0xD778E0
void __fastcall hkpBreakableMultiMaterial::InverseMapping::InverseMapping(
        hkpBreakableMultiMaterial::InverseMapping *this,
        hkFinishLoadedObjectFlag flag)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkpBreakableMultiMaterial::InverseMapping::`vftable;
}

// File Line: 72
// RVA: 0xD77B70
__int64 __fastcall hkpBreakableMultiMaterial::findSubMaterial(
        hkpBreakableMultiMaterial *this,
        hkpBreakableMaterial *mtl)
{
  int v2; // r9d
  __int64 v3; // rax
  hkRefPtr<hkpBreakableMaterial> *i; // r8

  v2 = this->m_subMaterials.m_size - 1;
  v3 = v2;
  if ( v2 < 0 )
    return 0xFFFFFFFFi64;
  for ( i = &this->m_subMaterials.m_data[v2]; i->m_pntr != mtl; --i )
  {
    --v2;
    if ( --v3 < 0 )
      return 0xFFFFFFFFi64;
  }
  return (unsigned int)v2;
}

// File Line: 88
// RVA: 0xD77910
void __fastcall hkpBreakableMultiMaterial::createInverseMapping(hkpBreakableMultiMaterial *this, hkcdShape *shape)
{
  hkcdShape *v3; // rbp
  __int64 v4; // r15
  _QWORD **Value; // rax
  hkpBreakableMultiMaterial::InverseMapping *v6; // rax
  hkpBreakableMultiMaterial::InverseMapping *v7; // rax
  hkpBreakableMultiMaterial::InverseMapping *v8; // r13
  hkpBreakableMultiMaterial::InverseMapping *m_pntr; // rcx
  __int64 m_size; // rbx
  int v11; // eax
  int v12; // eax
  int v13; // r9d
  __int64 v14; // rdx
  hkpBreakableMultiMaterial::InverseMappingDescriptor *v15; // r8
  __int64 v16; // rcx
  unsigned int v17; // eax
  unsigned int i; // r14d
  hkResultEnum v19; // eax
  hkBaseObjectVtbl *vfptr; // r9
  hkResultEnum v21; // esi
  hkpBreakableMaterial *v22; // rax
  int SubMaterial; // eax
  __int64 v24; // rbx
  hkpBreakableMultiMaterial::InverseMappingDescriptor *m_data; // rax
  int m_numKeys; // r10d
  hkpBreakableMultiMaterial::InverseMappingDescriptor *v27; // rbp
  int v28; // r9d
  __int64 v29; // rdx
  unsigned int *v30; // r8
  __int64 j; // rax
  hkResult result; // [rsp+80h] [rbp+18h] BYREF
  __int64 v34; // [rsp+88h] [rbp+20h]

  if ( shape )
  {
    v3 = shape;
    v4 = ((__int64 (__fastcall *)(hkcdShape *))shape->vfptr[7].__vecDelDtor)(shape);
    if ( v4 )
    {
      Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v6 = (hkpBreakableMultiMaterial::InverseMapping *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                                          Value[11],
                                                          48i64);
      if ( v6 )
      {
        hkpBreakableMultiMaterial::InverseMapping::InverseMapping(v6);
        v8 = v7;
      }
      else
      {
        v8 = 0i64;
      }
      m_pntr = this->m_inverseMapping.m_pntr;
      if ( m_pntr && m_pntr != v8 )
        hkReferencedObject::removeReference(m_pntr);
      this->m_inverseMapping.m_pntr = v8;
      m_size = this->m_subMaterials.m_size;
      v11 = v8->m_descriptors.m_capacityAndFlags & 0x3FFFFFFF;
      if ( v11 < (int)m_size )
      {
        v12 = 2 * v11;
        v13 = this->m_subMaterials.m_size;
        if ( (int)m_size < v12 )
          v13 = v12;
        hkArrayUtil::_reserve(
          &result,
          &hkContainerHeapAllocator::s_alloc,
          (const void **)&v8->m_descriptors.m_data,
          v13,
          4);
      }
      v14 = v8->m_descriptors.m_size;
      v15 = &v8->m_descriptors.m_data[v14];
      v16 = (int)m_size - (int)v14;
      if ( (int)m_size - (int)v14 > 0 )
      {
        do
        {
          if ( v15 )
            *v15 = 0;
          ++v15;
          --v16;
        }
        while ( v16 );
      }
      v8->m_descriptors.m_size = m_size;
      v17 = (*(__int64 (__fastcall **)(__int64, __int64, hkpBreakableMultiMaterial::InverseMappingDescriptor *))(*(_QWORD *)v4 + 16i64))(
              v4,
              v14,
              v15);
      v34 = m_size;
      for ( i = v17; i != -1; i = (*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v4 + 24i64))(v4, i) )
      {
        v19 = (hkResultEnum)this->vfptr[4].__vecDelDtor(this, i);
        vfptr = this->vfptr;
        v21 = v19;
        result.m_enum = v19;
        v22 = (hkpBreakableMaterial *)((__int64 (__fastcall *)(hkpBreakableMultiMaterial *, hkcdShape *, _QWORD))vfptr[3].__first_virtual_table_function__)(
                                        this,
                                        v3,
                                        i);
        SubMaterial = hkpBreakableMultiMaterial::findSubMaterial(this, v22);
        if ( SubMaterial >= 0 )
        {
          v24 = SubMaterial;
          m_data = v8->m_descriptors.m_data;
          m_numKeys = m_data[v24].m_numKeys;
          v27 = &m_data[v24];
          v28 = m_numKeys - 1;
          v29 = m_numKeys - 1;
          if ( m_numKeys - 1 < 0 )
            goto LABEL_24;
          v30 = &v8->m_subShapeIds.m_data[v28 + (unsigned __int64)v27->m_offset];
          do
          {
            if ( *v30 == v21 )
              break;
            --v28;
            --v30;
            --v29;
          }
          while ( v29 >= 0 );
          if ( v28 < 0 )
          {
LABEL_24:
            hkArrayBase<unsigned int>::_insertAt(
              &v8->m_subShapeIds,
              &hkContainerHeapAllocator::s_alloc,
              m_numKeys + v27->m_offset,
              (const unsigned int *)&result,
              1);
            ++v27->m_numKeys;
            for ( j = v34 - 1; j > v24; ++v8->m_descriptors.m_data[j + 1].m_offset )
              --j;
          }
          v3 = shape;
        }
      }
    }
  }
}

// File Line: 151
// RVA: 0xD77900
hkClass *__fastcall hkpBreakableMultiMaterial::getClassType(hkpBreakableMultiMaterial *this)
{
  return &hkpBreakableMultiMaterialClass;
}

// File Line: 159
// RVA: 0xD77B60
__int64 __fastcall hkpBreakableMultiMaterial::getNumSubMaterials(hkpBreakableMultiMaterial *this)
{
  return (unsigned int)this->m_subMaterials.m_size;
}

