// File Line: 14
// RVA: 0xE385E0
__int64 __fastcall hkxIndexBuffer::getNumTriangles(hkxIndexBuffer *this)
{
  int m_size; // edx
  int v2; // ecx

  m_size = this->m_indices16.m_size;
  if ( !m_size )
    m_size = this->m_indices32.m_size;
  v2 = this->m_indexType.m_storage - 1;
  if ( !v2 )
    return (unsigned int)(m_size / 3);
  if ( v2 == 1 && m_size > 2 )
    return (unsigned int)(m_size - 2);
  return 0i64;
}

// File Line: 41
// RVA: 0xE38620
char __fastcall hkxIndexBuffer::getTriangleIndices(
        hkxIndexBuffer *this,
        unsigned int triIndex,
        unsigned int *indexAOut,
        unsigned int *indexBOut,
        unsigned int *indexCOut)
{
  int v6; // ecx
  unsigned int v8; // edx
  int v9; // ecx

  if ( this->m_indices16.m_size )
  {
    v6 = this->m_indexType.m_storage - 1;
    if ( !v6 )
    {
      v8 = 3 * triIndex;
      *indexAOut = this->m_indices16.m_data[v8];
      *indexBOut = this->m_indices16.m_data[v8 + 1];
      *indexCOut = this->m_indices16.m_data[v8 + 2];
      return 1;
    }
    if ( v6 == 1 )
    {
      *indexAOut = this->m_indices16.m_data[triIndex];
      *indexBOut = this->m_indices16.m_data[triIndex + 1];
      *indexCOut = this->m_indices16.m_data[triIndex + 2];
      return 1;
    }
    goto LABEL_9;
  }
  if ( !this->m_indices32.m_size )
  {
LABEL_9:
    *indexAOut = -1;
    *indexBOut = -1;
    *indexCOut = -1;
    return 0;
  }
  v9 = this->m_indexType.m_storage - 1;
  if ( v9 )
  {
    if ( v9 != 1 )
      goto LABEL_9;
  }
  else
  {
    triIndex *= 3;
  }
  *indexAOut = this->m_indices32.m_data[triIndex];
  *indexBOut = this->m_indices32.m_data[triIndex + 1];
  *indexCOut = this->m_indices32.m_data[triIndex + 2];
  return 1;
}

