// File Line: 10
// RVA: 0xBF7B70
void __fastcall hkaiOverlapManagerSection::GeneratorData::GeneratorData(
        hkaiOverlapManagerSection::GeneratorData *this,
        hkaiSilhouetteGenerator *gen,
        hkQTransformf *initialTransform)
{
  int v3; // esi
  hkaiSilhouetteGenerator *m_generator; // rcx

  v3 = 0;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiOverlapManagerSection::GeneratorData::`vftable;
  this->m_context.m_generator = 0i64;
  this->m_context.m_generatorSize = 0;
  this->m_overlappedFaces.m_data = 0i64;
  this->m_overlappedFaces.m_size = 0;
  this->m_overlappedFaces.m_capacityAndFlags = 0x80000000;
  if ( gen )
    hkReferencedObject::addReference(gen);
  m_generator = this->m_context.m_generator;
  if ( m_generator )
    hkReferencedObject::removeReference(m_generator);
  this->m_context.m_generator = gen;
  if ( gen )
    v3 = ((__int64 (__fastcall *)(hkaiSilhouetteGenerator *))gen->vfptr[6].__vecDelDtor)(gen);
  this->m_context.m_generatorSize = v3;
  this->m_context.m_lastRelativeTransform.m_rotation = initialTransform->m_rotation;
  this->m_context.m_lastRelativeTransform.m_translation = initialTransform->m_translation;
  *(_WORD *)&this->m_context.m_generatedLastFrame.m_bool = 257;
}

// File Line: 18
// RVA: 0xBF7F10
hkaiOverlapManagerSection::GeneratorData *__fastcall hkaiOverlapManagerSection::getGeneratorData(
        hkaiOverlapManagerSection *this,
        hkaiSilhouetteGenerator *gen)
{
  hkReferencedObject *v3; // rbx
  int v4; // eax
  hkReferencedObject *m_pntr; // rcx
  char v6; // di
  hkRefPtr<hkaiOverlapManagerSection::GeneratorData> *v7; // rbx
  hkReferencedObject *v9; // [rsp+30h] [rbp+8h]

  v3 = 0i64;
  v4 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
         &this->m_generatorDataMap->m_map,
         (unsigned __int64)gen,
         0xFFFFFFFFFFFFFFFFui64);
  if ( v4 == -1 )
  {
    v9 = 0i64;
    m_pntr = 0i64;
    v6 = 1;
  }
  else
  {
    v6 = 2;
    v7 = &this->m_generatorData.m_data[v4];
    if ( v7->m_pntr )
      hkReferencedObject::addReference(v7->m_pntr);
    m_pntr = v7->m_pntr;
    v9 = v7->m_pntr;
    v3 = v7->m_pntr;
  }
  if ( (v6 & 2) != 0 )
  {
    v6 &= ~2u;
    if ( m_pntr )
      hkReferencedObject::removeReference(m_pntr);
  }
  if ( (v6 & 1) != 0 && v3 )
    hkReferencedObject::removeReference(v3);
  return (hkaiOverlapManagerSection::GeneratorData *)v9;
}

// File Line: 30
// RVA: 0xBF8470
void __fastcall hkaiOverlapManagerSection::setFaceDirty(
        hkaiOverlapManagerSection *this,
        unsigned int f,
        float priorityDelta)
{
  hkSetIntFloatPair *p_m_facePriorities; // rdi
  int v5; // edx
  int v7; // r8d
  int m_key; // ecx
  int v9; // ecx
  hkIntRealPair *m_data; // r8
  int v11; // r9d
  int v12; // r10d
  int v13; // ecx
  int v14; // edx
  unsigned __int64 v15; // [rsp+30h] [rbp+8h]
  hkResult result; // [rsp+38h] [rbp+10h] BYREF

  v15 = __PAIR64__(LODWORD(priorityDelta), f);
  p_m_facePriorities = &this->m_facePriorities;
  v5 = this->m_facePriorities.m_elem.m_size - 1;
  if ( v5 <= 0 || (v7 = v5 & (-1640531535 * f), m_key = p_m_facePriorities->m_elem.m_data[v7].m_key, m_key == -1) )
  {
LABEL_5:
    v9 = v5 + 1;
  }
  else
  {
    while ( m_key != f )
    {
      v7 = v5 & (v7 + 1);
      m_key = p_m_facePriorities->m_elem.m_data[v7].m_key;
      if ( m_key == -1 )
        goto LABEL_5;
    }
    v9 = v7;
  }
  if ( v9 > this->m_facePriorities.m_elem.m_size - 1 )
  {
    if ( 2 * p_m_facePriorities->m_numElems > v5 )
      hkSet<hkIntRealPair,hkContainerHeapAllocator,hkMapOperations<hkIntRealPair>>::resizeTable(
        p_m_facePriorities,
        &result,
        2 * v5 + 2);
    m_data = p_m_facePriorities->m_elem.m_data;
    v11 = p_m_facePriorities->m_elem.m_size - 1;
    v12 = 1;
    v13 = v11 & (-1640531535 * f);
    v14 = p_m_facePriorities->m_elem.m_data[v13].m_key;
    if ( v14 != -1 )
    {
      while ( v14 != f )
      {
        v13 = v11 & (v13 + 1);
        v14 = m_data[v13].m_key;
        if ( v14 == -1 )
          goto LABEL_16;
      }
      v12 = 0;
    }
LABEL_16:
    p_m_facePriorities->m_numElems += v12;
    m_data[v13] = (hkIntRealPair)v15;
  }
  else
  {
    *((float *)&v15 + 1) = COERCE_FLOAT(HIDWORD(*(_QWORD *)&p_m_facePriorities->m_elem.m_data[v9])) + priorityDelta;
    p_m_facePriorities->m_elem.m_data[v9] = (hkIntRealPair)v15;
  }
}

