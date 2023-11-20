// File Line: 10
// RVA: 0xBF7B70
void __fastcall hkaiOverlapManagerSection::GeneratorData::GeneratorData(hkaiOverlapManagerSection::GeneratorData *this, hkaiSilhouetteGenerator *gen, hkQTransformf *initialTransform)
{
  int v3; // esi
  hkQTransformf *v4; // rbp
  hkaiSilhouetteGenerator *v5; // rdi
  hkaiOverlapManagerSection::GeneratorData *v6; // rbx
  hkReferencedObject *v7; // rcx

  v3 = 0;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiOverlapManagerSection::GeneratorData::`vftable';
  this->m_context.m_generator = 0i64;
  this->m_context.m_generatorSize = 0;
  this->m_overlappedFaces.m_data = 0i64;
  this->m_overlappedFaces.m_size = 0;
  this->m_overlappedFaces.m_capacityAndFlags = 2147483648;
  v4 = initialTransform;
  v5 = gen;
  v6 = this;
  if ( gen )
    hkReferencedObject::addReference((hkReferencedObject *)&gen->vfptr);
  v7 = (hkReferencedObject *)&v6->m_context.m_generator->vfptr;
  if ( v7 )
    hkReferencedObject::removeReference(v7);
  v6->m_context.m_generator = v5;
  if ( v5 )
    v3 = ((__int64 (__fastcall *)(hkaiSilhouetteGenerator *))v5->vfptr[6].__vecDelDtor)(v5);
  v6->m_context.m_generatorSize = v3;
  v6->m_context.m_lastRelativeTransform.m_rotation = v4->m_rotation;
  v6->m_context.m_lastRelativeTransform.m_translation = v4->m_translation;
  *(_WORD *)&v6->m_context.m_generatedLastFrame.m_bool = 257;
}

// File Line: 18
// RVA: 0xBF7F10
hkReferencedObject *__fastcall hkaiOverlapManagerSection::getGeneratorData(hkaiOverlapManagerSection *this, hkaiSilhouetteGenerator *gen)
{
  hkaiOverlapManagerSection *v2; // rsi
  hkReferencedObject *v3; // rbx
  int v4; // eax
  hkReferencedObject *v5; // rcx
  char v6; // di
  hkReferencedObject **v7; // rbx
  hkReferencedObject *v9; // [rsp+30h] [rbp+8h]

  v2 = this;
  v3 = 0i64;
  v4 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
         (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_generatorDataMap->m_map.m_elem,
         (unsigned __int64)gen,
         0xFFFFFFFFFFFFFFFFui64);
  if ( v4 == -1 )
  {
    v9 = 0i64;
    v5 = 0i64;
    v6 = 1;
  }
  else
  {
    v6 = 2;
    v7 = (hkReferencedObject **)&v2->m_generatorData.m_data[v4];
    if ( *v7 )
      hkReferencedObject::addReference(*v7);
    v5 = *v7;
    v9 = *v7;
    v3 = *v7;
  }
  if ( v6 & 2 )
  {
    v6 &= 0xFDu;
    if ( v5 )
      hkReferencedObject::removeReference(v5);
  }
  if ( v6 & 1 && v3 )
    hkReferencedObject::removeReference(v3);
  return v9;
}

// File Line: 30
// RVA: 0xBF8470
void __fastcall hkaiOverlapManagerSection::setFaceDirty(hkaiOverlapManagerSection *this, int f, float priorityDelta)
{
  int v3; // ebx
  hkSet<hkIntRealPair,hkContainerHeapAllocator,hkMapOperations<hkIntRealPair> > *v4; // rdi
  int v5; // edx
  hkaiOverlapManagerSection *v6; // r10
  int v7; // er8
  int v8; // ecx
  int v9; // ecx
  hkIntRealPair *v10; // r8
  int v11; // er9
  signed int v12; // er10
  int v13; // ecx
  int v14; // edx
  unsigned __int64 v15; // [rsp+30h] [rbp+8h]
  hkResult result; // [rsp+38h] [rbp+10h]

  v3 = f;
  v15 = __PAIR__(LODWORD(priorityDelta), f);
  v4 = (hkSet<hkIntRealPair,hkContainerHeapAllocator,hkMapOperations<hkIntRealPair> > *)&this->m_facePriorities.m_elem;
  v5 = this->m_facePriorities.m_elem.m_size - 1;
  v6 = this;
  if ( v5 <= 0 || (v7 = v5 & -1640531535 * v3, v8 = v4->m_elem.m_data[v7].m_key, v8 == -1) )
  {
LABEL_5:
    v9 = v5 + 1;
  }
  else
  {
    while ( v8 != v3 )
    {
      v7 = v5 & (v7 + 1);
      v8 = v4->m_elem.m_data[v7].m_key;
      if ( v8 == -1 )
        goto LABEL_5;
    }
    v9 = v7;
  }
  if ( v9 > v6->m_facePriorities.m_elem.m_size - 1 )
  {
    if ( 2 * v4->m_numElems > v5 )
      hkSet<hkIntRealPair,hkContainerHeapAllocator,hkMapOperations<hkIntRealPair>>::resizeTable(v4, &result, 2 * v5 + 2);
    v10 = v4->m_elem.m_data;
    v11 = v4->m_elem.m_size - 1;
    v12 = 1;
    v13 = v11 & -1640531535 * v3;
    v14 = v4->m_elem.m_data[v13].m_key;
    if ( v14 != -1 )
    {
      while ( v14 != v3 )
      {
        v13 = v11 & (v13 + 1);
        v14 = v10[v13].m_key;
        if ( v14 == -1 )
          goto LABEL_16;
      }
      v12 = 0;
    }
LABEL_16:
    v4->m_numElems += v12;
    v10[v13] = (hkIntRealPair)v15;
  }
  else
  {
    *((float *)&v15 + 1) = COERCE_FLOAT(*(_QWORD *)&v4->m_elem.m_data[v9] >> 32) + priorityDelta;
    v4->m_elem.m_data[v9] = (hkIntRealPair)v15;
  }
}

