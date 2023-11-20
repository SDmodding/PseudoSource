// File Line: 14
// RVA: 0xE385E0
__int64 __fastcall hkxIndexBuffer::getNumTriangles(hkxIndexBuffer *this)
{
  int v1; // edx
  int v2; // ecx

  v1 = this->m_indices16.m_size;
  if ( !v1 )
    v1 = this->m_indices32.m_size;
  v2 = this->m_indexType.m_storage - 1;
  if ( !v2 )
    return v1 / 3;
  if ( v2 != 1 || v1 <= 2 )
    return 0i64;
  return (unsigned int)(v1 - 2);
}

// File Line: 41
// RVA: 0xE38620
char __fastcall hkxIndexBuffer::getTriangleIndices(hkxIndexBuffer *this, unsigned int triIndex, unsigned int *indexAOut, unsigned int *indexBOut, unsigned int *indexCOut)
{
  hkxIndexBuffer *v5; // r10
  int v6; // ecx
  signed int v8; // edx
  int v9; // ecx

  v5 = this;
  if ( this->m_indices16.m_size )
  {
    v6 = this->m_indexType.m_storage - 1;
    if ( !v6 )
    {
      v8 = 3 * triIndex;
      *indexAOut = v5->m_indices16.m_data[v8];
      *indexBOut = v5->m_indices16.m_data[v8 + 1];
      *indexCOut = v5->m_indices16.m_data[v8 + 2];
      return 1;
    }
    if ( v6 == 1 )
    {
      *indexAOut = v5->m_indices16.m_data[triIndex];
      *indexBOut = v5->m_indices16.m_data[triIndex + 1];
      *indexCOut = v5->m_indices16.m_data[triIndex + 2];
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
  *indexAOut = v5->m_indices32.m_data[triIndex];
  *indexBOut = v5->m_indices32.m_data[triIndex + 1];
  *indexCOut = v5->m_indices32.m_data[triIndex + 2];
  return 1;
}

