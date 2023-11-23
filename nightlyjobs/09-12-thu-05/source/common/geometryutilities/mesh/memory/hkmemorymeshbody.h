// File Line: 39
// RVA: 0x131A070
hkMeshShape *__fastcall hkMemoryMeshBody::getMeshShape(hkMemoryMeshBody *this)
{
  return this->m_shape.m_pntr;
}

// File Line: 42
// RVA: 0x131A0B0
void __fastcall hkMemoryMeshBody::getTransform(hkMemoryMeshBody *this, hkMatrix4f *transform)
{
  *transform = this->m_transform;
}

// File Line: 45
// RVA: 0x131A100
void __fastcall hkMemoryMeshBody::setTransform(hkMemoryMeshBody *this, hkMatrix4f *matrix)
{
  this->m_transform = *matrix;
}

// File Line: 51
// RVA: 0x131A0D0
hkMeshVertexBuffer *__fastcall hkMemoryMeshBody::getVertexBuffer(hkMemoryMeshBody *this, int sectionIndex)
{
  return this->m_vertexBuffers.m_data[sectionIndex];
}

// File Line: 54
// RVA: 0x131A0A0
hkIndexedTransformSet *__fastcall hkMemoryMeshBody::getNumIndexedTransforms(hkMemoryMeshBody *this)
{
  hkIndexedTransformSet *result; // rax

  result = this->m_transformSet.m_pntr;
  if ( result )
    return (hkIndexedTransformSet *)(unsigned int)result->m_matrices.m_size;
  return result;
}

// File Line: 56
// RVA: 0x131A0E0
void __fastcall hkMemoryMeshBody::setIndexedTransforms(
        hkMemoryMeshBody *this,
        int startIndex,
        hkMatrix4f *matrices,
        int numMatrices)
{
  hkIndexedTransformSet::setMatrices(this->m_transformSet.m_pntr, startIndex, matrices, numMatrices);
}

// File Line: 58
// RVA: 0x131A060
void __fastcall hkMemoryMeshBody::getIndexedTransforms(
        hkMemoryMeshBody *this,
        int startIndex,
        hkMatrix4f *matrices,
        int numMatrices)
{
  hkIndexedTransformSet::getMatrices(this->m_transformSet.m_pntr, startIndex, matrices, numMatrices);
}

// File Line: 60
// RVA: 0x131A050
void __fastcall hkMemoryMeshBody::getIndexedInverseTransforms(
        hkMemoryMeshBody *this,
        int startIndex,
        hkMatrix4f *matrices,
        int numMatrices)
{
  hkIndexedTransformSet::getInverseMatrices(this->m_transformSet.m_pntr, startIndex, matrices, numMatrices);
}

// File Line: 63
// RVA: 0x131A040
__int16 *__fastcall hkMemoryMeshBody::getIndexTransformsOrder(hkMemoryMeshBody *this)
{
  return this->m_transformSet.m_pntr->m_matricesOrder.m_data;
}

// File Line: 65
// RVA: 0x131A030
hkStringPtr *__fastcall hkMemoryMeshBody::getIndexTransformNames(hkMemoryMeshBody *this)
{
  return this->m_transformSet.m_pntr->m_matricesNames.m_data;
}

// File Line: 67
// RVA: 0x131A020
hkMeshBoneIndexMapping *__fastcall hkMemoryMeshBody::getIndexMappings(hkMemoryMeshBody *this)
{
  return this->m_transformSet.m_pntr->m_indexMappings.m_data;
}

// File Line: 69
// RVA: 0x131A090
hkIndexedTransformSet *__fastcall hkMemoryMeshBody::getNumIndexMappings(hkMemoryMeshBody *this)
{
  hkIndexedTransformSet *result; // rax

  result = this->m_transformSet.m_pntr;
  if ( result )
    return (hkIndexedTransformSet *)(unsigned int)result->m_indexMappings.m_size;
  return result;
}

// File Line: 75
// RVA: 0x131A080
const char *__fastcall hkMemoryMeshBody::getName(hkMemoryMeshBody *this)
{
  return (const char *)((unsigned __int64)this->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
}

// File Line: 76
// RVA: 0x131A0F0
void __fastcall hkMemoryMeshBody::setName(hkMemoryMeshBody *this, const char *n)
{
  hkStringPtr::operator=(&this->m_name, n);
}

