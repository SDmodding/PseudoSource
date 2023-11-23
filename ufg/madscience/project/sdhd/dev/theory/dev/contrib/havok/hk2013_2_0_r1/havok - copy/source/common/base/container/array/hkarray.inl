// File Line: 382
// RVA: 0xBFC1F0
void __fastcall hkArrayBase<hkaiHierarchyUtils::SemiSparse2dArraySorted::Cost>::_spliceInto(
        hkArrayBase<hkpMoppCodeReindexedTerminal> *this,
        hkMemoryAllocator *alloc,
        int index,
        int numdel,
        hkaiHierarchyUtils::SemiSparse2dArraySorted::Cost *p,
        int numtoinsert)
{
  __int64 v6; // rdi
  __int64 v7; // r15
  __int64 v8; // rbx
  int v9; // eax
  int v10; // esi
  int v11; // ebp
  int v13; // eax
  int v14; // r9d
  hkpMoppCodeReindexedTerminal *v15; // rax
  char *v16; // rdx

  v6 = numtoinsert;
  v7 = numdel;
  v8 = index;
  v9 = this->m_capacityAndFlags & 0x3FFFFFFF;
  v10 = numtoinsert + this->m_size - numdel;
  v11 = this->m_size - index - numdel;
  if ( v10 > v9 )
  {
    v13 = 2 * v9;
    v14 = numtoinsert + this->m_size - numdel;
    if ( v10 < v13 )
      v14 = v13;
    hkArrayUtil::_reserve((hkResult *)&numtoinsert, alloc, this, v14, 8);
  }
  hkMemUtil::memMove(&this->m_data[v6 + v8], &this->m_data[v8 + v7], 8 * v11);
  v15 = &this->m_data[v8];
  if ( v6 > 0 )
  {
    v16 = (char *)((char *)p - (char *)v15);
    do
    {
      if ( v15 )
        *v15 = *(hkpMoppCodeReindexedTerminal *)((char *)v15 + (_QWORD)v16);
      ++v15;
      --v6;
    }
    while ( v6 );
  }
  this->m_size = v10;
}

// File Line: 400
// RVA: 0xC24C10
void __fastcall hkArrayBase<hkaiStringPulling::Vertex>::_insertAt(
        hkArrayBase<hkaiStringPulling::Vertex> *this,
        hkMemoryAllocator *alloc,
        int index,
        hkaiStringPulling::Vertex *p,
        int numtoinsert)
{
  hkArrayBase<hkaiStringPulling::Vertex>::_spliceInto(this, alloc, index, 0, p, numtoinsert);
}

// File Line: 406
// RVA: 0xBE4D70
void __fastcall hkArrayBase<hkaiNavMesh::Edge>::_append(
        hkArrayBase<hkaiNavMesh::Edge> *this,
        hkMemoryAllocator *alloc,
        hkaiNavMesh::Edge *a,
        int numtoinsert)
{
  __int64 v4; // r14
  int v5; // esi
  int v6; // eax
  int v9; // eax
  int v10; // r9d
  __int64 v11; // rdx
  hkaiNavMesh::Edge *v12; // r8
  int *p_m_b; // rax
  char *v14; // rdi
  int v15; // ecx
  hkResult result; // [rsp+58h] [rbp+20h] BYREF

  v4 = numtoinsert;
  v5 = numtoinsert + this->m_size;
  v6 = this->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v5 > v6 )
  {
    v9 = 2 * v6;
    v10 = numtoinsert + this->m_size;
    if ( v5 < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(&result, alloc, this, v10, 20);
  }
  v11 = v4;
  v12 = &this->m_data[this->m_size];
  if ( (int)v4 > 0 )
  {
    p_m_b = &v12->m_b;
    v14 = (char *)((char *)a - (char *)v12);
    do
    {
      v15 = *(int *)((char *)p_m_b + (_QWORD)v14 - 4);
      p_m_b += 5;
      *(p_m_b - 6) = v15;
      *(p_m_b - 5) = *(int *)((char *)p_m_b + (_QWORD)v14 - 20);
      *(p_m_b - 4) = *(int *)((char *)p_m_b + (_QWORD)v14 - 16);
      *(p_m_b - 3) = *(int *)((char *)p_m_b + (_QWORD)v14 - 12);
      *((_BYTE *)p_m_b - 8) = *((_BYTE *)p_m_b + (_QWORD)v14 - 8);
      *((_BYTE *)p_m_b - 7) = *((_BYTE *)p_m_b + (_QWORD)v14 - 7);
      *((_WORD *)p_m_b - 3) = *(_WORD *)((char *)p_m_b + (_QWORD)v14 - 6);
      --v11;
    }
    while ( v11 );
  }
  this->m_size = v5;
}

// File Line: 436
// RVA: 0xC24BF0
void __fastcall hkArrayBase<hkaiStringPulling::Vertex>::_insertAt(
        hkArrayBase<hkaiStringPulling::Vertex> *this,
        hkMemoryAllocator *alloc,
        int i,
        hkaiStringPulling::Vertex *t)
{
  hkArrayBase<hkaiStringPulling::Vertex>::_insertAt(this, alloc, i, t, 1);
}

