// File Line: 18
// RVA: 0xD775B0
void __fastcall hkpBreakableMultiMaterial::hkpBreakableMultiMaterial(hkpBreakableMultiMaterial *this, hkArray<hkpBreakableMaterial *,hkContainerHeapAllocator> *subMaterials, float strength)
{
  __int64 v3; // rbx
  hkArray<hkpBreakableMaterial *,hkContainerHeapAllocator> *v4; // r13
  __int64 v5; // r15
  hkpBreakableMultiMaterial *v6; // r12
  int v7; // eax
  int v8; // eax
  int v9; // er9
  signed __int64 v10; // rsi
  int v11; // eax
  __int64 i; // rdi
  hkReferencedObject *v13; // rcx
  int v14; // edx
  hkRefPtr<hkpBreakableMaterial> *v15; // r8
  __int64 v16; // rax
  hkRefPtr<hkpBreakableMaterial> *v17; // rsi
  hkpBreakableMaterial *v18; // rdi
  hkReferencedObject *v19; // rcx
  hkResult result; // [rsp+70h] [rbp+18h]

  this->m_strength = strength;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_typeAndFlags = 2;
  v3 = 0i64;
  v4 = subMaterials;
  this->vfptr = (hkBaseObjectVtbl *)&hkpBreakableMultiMaterial::`vftable';
  this->m_properties = 0i64;
  this->m_subMaterials.m_data = 0i64;
  this->m_subMaterials.m_size = 0;
  this->m_subMaterials.m_capacityAndFlags = 2147483648;
  this->m_inverseMapping.m_pntr = 0i64;
  v5 = subMaterials->m_size;
  v6 = this;
  v7 = this->m_subMaterials.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v7 < (signed int)v5 )
  {
    v8 = 2 * v7;
    v9 = v5;
    if ( (signed int)v5 < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &this->m_subMaterials,
      v9,
      8);
  }
  v10 = (signed __int64)&v6->m_subMaterials.m_data[v5];
  v11 = v6->m_subMaterials.m_size - v5 - 1;
  for ( i = v11; i >= 0; *(_QWORD *)(v10 + 8 * i--) = 0i64 )
  {
    v13 = *(hkReferencedObject **)(v10 + 8 * i);
    if ( v13 )
      hkReferencedObject::removeReference(v13);
  }
  v14 = v5 - v6->m_subMaterials.m_size;
  v15 = &v6->m_subMaterials.m_data[v6->m_subMaterials.m_size];
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
  v6->m_subMaterials.m_size = v5;
  if ( (signed int)v5 > 0 )
  {
    do
    {
      v17 = v6->m_subMaterials.m_data;
      v18 = v4->m_data[v3];
      if ( v18 )
        hkReferencedObject::addReference((hkReferencedObject *)&v4->m_data[v3]->vfptr);
      v19 = (hkReferencedObject *)&v17[v3].m_pntr->vfptr;
      if ( v19 )
        hkReferencedObject::removeReference(v19);
      v17[v3++].m_pntr = v18;
    }
    while ( v3 < v5 );
  }
}

// File Line: 34
// RVA: 0xD77710
void __fastcall hkpBreakableMultiMaterial::hkpBreakableMultiMaterial(hkpBreakableMultiMaterial *this, hkpBreakableMultiMaterial *other)
{
  hkpBreakableMultiMaterial *v2; // r15
  hkpBreakableMultiMaterial *v3; // rbp
  hkpBreakableMultiMaterial::InverseMapping *v4; // rcx
  __int64 v5; // rsi
  int v6; // eax
  int v7; // eax
  int v8; // er9
  signed __int64 v9; // rdi
  int v10; // eax
  __int64 i; // rbx
  hkReferencedObject *v12; // rcx
  int v13; // edx
  hkRefPtr<hkpBreakableMaterial> *v14; // r8
  __int64 v15; // rax
  __int64 j; // rbx
  hkRefPtr<hkpBreakableMaterial> *v17; // rsi
  hkRefPtr<hkpBreakableMaterial> *v18; // rdi
  hkReferencedObject *v19; // rcx
  hkReferencedObject *v20; // rcx
  hkpBreakableMaterial *v21; // rax
  hkResult result; // [rsp+60h] [rbp+8h]

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpBreakableMaterial::`vftable';
  v2 = this;
  this->m_strength = other->m_strength;
  v3 = other;
  this->m_typeAndFlags = other->m_typeAndFlags;
  this->m_properties = other->m_properties;
  this->vfptr = (hkBaseObjectVtbl *)&hkpBreakableMultiMaterial::`vftable';
  this->m_subMaterials.m_data = 0i64;
  this->m_subMaterials.m_size = 0;
  this->m_subMaterials.m_capacityAndFlags = 2147483648;
  v4 = other->m_inverseMapping.m_pntr;
  if ( v4 )
    hkReferencedObject::addReference((hkReferencedObject *)&v4->vfptr);
  v2->m_inverseMapping.m_pntr = v3->m_inverseMapping.m_pntr;
  v5 = v3->m_subMaterials.m_size;
  v6 = v2->m_subMaterials.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v6 < (signed int)v5 )
  {
    v7 = 2 * v6;
    v8 = v5;
    if ( (signed int)v5 < v7 )
      v8 = v7;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v2->m_subMaterials,
      v8,
      8);
  }
  v9 = (signed __int64)&v2->m_subMaterials.m_data[v5];
  v10 = v2->m_subMaterials.m_size - v5 - 1;
  for ( i = v10; i >= 0; *(_QWORD *)(v9 + 8 * i--) = 0i64 )
  {
    v12 = *(hkReferencedObject **)(v9 + 8 * i);
    if ( v12 )
      hkReferencedObject::removeReference(v12);
  }
  v13 = v5 - v2->m_subMaterials.m_size;
  v14 = &v2->m_subMaterials.m_data[v2->m_subMaterials.m_size];
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
  v2->m_subMaterials.m_size = v5;
  for ( j = (signed int)v5 - 1; j >= 0; v18[j + 1].m_pntr = v21 )
  {
    v17 = v3->m_subMaterials.m_data;
    v18 = v2->m_subMaterials.m_data;
    v19 = (hkReferencedObject *)&v17[j].m_pntr->vfptr;
    if ( v19 )
      hkReferencedObject::addReference(v19);
    v20 = (hkReferencedObject *)&v18[j].m_pntr->vfptr;
    if ( v20 )
      hkReferencedObject::removeReference(v20);
    v21 = v17[j--].m_pntr;
  }
}

// File Line: 48
// RVA: 0xD778A0
void __fastcall hkpBreakableMultiMaterial::InverseMapping::InverseMapping(hkpBreakableMultiMaterial::InverseMapping *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpBreakableMultiMaterial::InverseMapping::`vftable';
  this->m_descriptors.m_capacityAndFlags = 2147483648;
  this->m_descriptors.m_data = 0i64;
  this->m_descriptors.m_size = 0;
  this->m_subShapeIds.m_data = 0i64;
  this->m_subShapeIds.m_size = 0;
  this->m_subShapeIds.m_capacityAndFlags = 2147483648;
}

// File Line: 57
// RVA: 0xD77880
void __fastcall hkpBreakableMultiMaterial::hkpBreakableMultiMaterial(hkpBreakableMultiMaterial *this, hkFinishLoadedObjectFlag flag)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkpBreakableMultiMaterial::`vftable';
}

// File Line: 66
// RVA: 0xD778E0
void __fastcall hkpBreakableMultiMaterial::InverseMapping::InverseMapping(hkpBreakableMultiMaterial::InverseMapping *this, hkFinishLoadedObjectFlag flag)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkpBreakableMultiMaterial::InverseMapping::`vftable';
}

// File Line: 72
// RVA: 0xD77B70
signed __int64 __fastcall hkpBreakableMultiMaterial::findSubMaterial(hkpBreakableMultiMaterial *this, hkpBreakableMaterial *mtl)
{
  int v2; // er9
  __int64 v3; // rax
  hkRefPtr<hkpBreakableMaterial> *v4; // r8

  v2 = this->m_subMaterials.m_size - 1;
  v3 = v2;
  if ( v2 < 0 )
    return 0xFFFFFFFFi64;
  v4 = &this->m_subMaterials.m_data[v2];
  while ( v4->m_pntr != mtl )
  {
    --v2;
    --v4;
    if ( --v3 < 0 )
      return 0xFFFFFFFFi64;
  }
  return (unsigned int)v2;
}

// File Line: 88
// RVA: 0xD77910
void __fastcall hkpBreakableMultiMaterial::createInverseMapping(hkpBreakableMultiMaterial *this, hkcdShape *shape)
{
  hkpBreakableMultiMaterial *v2; // r12
  hkcdShape *v3; // rbp
  __int64 v4; // r15
  _QWORD **v5; // rax
  hkpBreakableMultiMaterial::InverseMapping *v6; // rax
  hkArrayBase<unsigned int> *v7; // rax
  hkArrayBase<unsigned int> *v8; // r13
  hkReferencedObject *v9; // rcx
  __int64 v10; // rbx
  int v11; // eax
  int v12; // eax
  int v13; // er9
  __int64 v14; // rdx
  unsigned int *v15; // r8
  __int64 v16; // rcx
  unsigned int v17; // eax
  unsigned int i; // er14
  hkResultEnum v19; // eax
  hkBaseObjectVtbl *v20; // r9
  hkResultEnum v21; // esi
  hkpBreakableMaterial *v22; // rax
  int v23; // eax
  __int64 v24; // rbx
  unsigned int *v25; // rax
  int v26; // er10
  unsigned int *v27; // rbp
  int v28; // er9
  __int64 v29; // rdx
  unsigned int *v30; // r8
  __int64 j; // rax
  hkcdShape *v32; // [rsp+78h] [rbp+10h]
  hkResult result; // [rsp+80h] [rbp+18h]
  __int64 v34; // [rsp+88h] [rbp+20h]

  if ( shape )
  {
    v32 = shape;
    v2 = this;
    v3 = shape;
    v4 = ((__int64 (__fastcall *)(hkcdShape *))shape->vfptr[7].__vecDelDtor)(shape);
    if ( v4 )
    {
      v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v6 = (hkpBreakableMultiMaterial::InverseMapping *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v5[11] + 8i64))(
                                                          v5[11],
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
      v9 = (hkReferencedObject *)&v2->m_inverseMapping.m_pntr->vfptr;
      if ( v9 && v9 != (hkReferencedObject *)v8 )
        hkReferencedObject::removeReference(v9);
      v2->m_inverseMapping.m_pntr = (hkpBreakableMultiMaterial::InverseMapping *)v8;
      v10 = v2->m_subMaterials.m_size;
      v11 = v8[1].m_capacityAndFlags & 0x3FFFFFFF;
      if ( v11 < (signed int)v10 )
      {
        v12 = 2 * v11;
        v13 = v2->m_subMaterials.m_size;
        if ( (signed int)v10 < v12 )
          v13 = v12;
        hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v8[1], v13, 4);
      }
      v14 = v8[1].m_size;
      v15 = &v8[1].m_data[v14];
      v16 = (signed int)v10 - (signed int)v14;
      if ( (signed int)v10 - (signed int)v14 > 0 )
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
      v8[1].m_size = v10;
      v17 = (*(__int64 (__fastcall **)(__int64, __int64, unsigned int *))(*(_QWORD *)v4 + 16i64))(v4, v14, v15);
      v34 = v10;
      for ( i = v17; i != -1; i = (*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v4 + 24i64))(v4, i) )
      {
        v19 = (unsigned int)v2->vfptr[4].__vecDelDtor((hkBaseObject *)&v2->vfptr, i);
        v20 = v2->vfptr;
        v21 = v19;
        result.m_enum = v19;
        v22 = (hkpBreakableMaterial *)((__int64 (__fastcall *)(hkpBreakableMultiMaterial *, hkcdShape *, _QWORD))v20[3].__first_virtual_table_function__)(
                                        v2,
                                        v3,
                                        i);
        v23 = hkpBreakableMultiMaterial::findSubMaterial(v2, v22);
        if ( v23 >= 0 )
        {
          v24 = v23;
          v25 = v8[1].m_data;
          v26 = HIWORD(v25[v24]);
          v27 = &v25[v24];
          v28 = v26 - 1;
          v29 = v26 - 1;
          if ( v26 - 1 < 0 )
            goto LABEL_30;
          v30 = &v8[2].m_data[v28 + (unsigned __int64)*(unsigned __int16 *)v27];
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
LABEL_30:
            hkArrayBase<unsigned int>::_insertAt(
              v8 + 2,
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              v26 + *(unsigned __int16 *)v27,
              (const unsigned int *)&result,
              1);
            ++*((_WORD *)v27 + 1);
            for ( j = v34 - 1; j > v24; ++LOWORD(v8[1].m_data[j + 1]) )
              --j;
          }
          v3 = v32;
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

