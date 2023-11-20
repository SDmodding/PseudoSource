// File Line: 382
// RVA: 0xBFC1F0
void __fastcall hkArrayBase<hkaiHierarchyUtils::SemiSparse2dArraySorted::Cost>::_spliceInto(hkArrayBase<hkpMoppCodeReindexedTerminal> *this, hkMemoryAllocator *alloc, int index, int numdel, hkpMoppCodeReindexedTerminal *p, int numtoinsert)
{
  __int64 v6; // rdi
  __int64 v7; // r15
  __int64 v8; // rbx
  int v9; // eax
  int v10; // esi
  int v11; // ebp
  hkArrayBase<hkpMoppCodeReindexedTerminal> *v12; // r14
  int v13; // eax
  int v14; // er9
  char *v15; // rax
  signed __int64 v16; // rdx

  v6 = numtoinsert;
  v7 = numdel;
  v8 = index;
  v9 = this->m_capacityAndFlags & 0x3FFFFFFF;
  v10 = numtoinsert + this->m_size - numdel;
  v11 = this->m_size - index - numdel;
  v12 = this;
  if ( v10 > v9 && v9 < v10 )
  {
    v13 = 2 * v9;
    v14 = numtoinsert + this->m_size - numdel;
    if ( v10 < v13 )
      v14 = v13;
    hkArrayUtil::_reserve((hkResult *)&numtoinsert, alloc, this, v14, 8);
  }
  hkMemUtil::memMove(&v12->m_data[v6 + v8], &v12->m_data[v8 + v7], 8 * v11);
  v15 = (char *)&v12->m_data[v8];
  if ( v6 > 0 )
  {
    v16 = (char *)p - v15;
    do
    {
      if ( v15 )
        *(_QWORD *)v15 = *(_QWORD *)&v15[v16];
      v15 += 8;
      --v6;
    }
    while ( v6 );
  }
  v12->m_size = v10;
}

// File Line: 400
// RVA: 0xC24C10
void __fastcall hkArrayBase<hkaiStringPulling::Vertex>::_insertAt(hkArrayBase<hkaiStringPulling::Vertex> *this, hkMemoryAllocator *alloc, int index, hkaiStringPulling::Vertex *p, int numtoinsert)
{
  hkArrayBase<hkaiStringPulling::Vertex>::_spliceInto(this, alloc, index, 0, p, numtoinsert);
}

// File Line: 406
// RVA: 0xBE4D70
void __fastcall hkArrayBase<hkaiNavMesh::Edge>::_append(hkArrayBase<hkaiNavMesh::Edge> *this, hkMemoryAllocator *alloc, hkaiNavMesh::Edge *a, int numtoinsert)
{
  __int64 v4; // r14
  int v5; // esi
  int v6; // eax
  hkaiNavMesh::Edge *v7; // rdi
  hkArrayBase<hkaiNavMesh::Edge> *v8; // rbx
  int v9; // eax
  int v10; // er9
  __int64 v11; // rdx
  signed __int64 v12; // r8
  signed __int64 v13; // rax
  char *v14; // rdi
  int v15; // ecx
  hkResult result; // [rsp+58h] [rbp+20h]

  v4 = numtoinsert;
  v5 = numtoinsert + this->m_size;
  v6 = this->m_capacityAndFlags & 0x3FFFFFFF;
  v7 = a;
  v8 = this;
  if ( v5 > v6 && v6 < v5 )
  {
    v9 = 2 * v6;
    v10 = numtoinsert + this->m_size;
    if ( v5 < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(&result, alloc, this, v10, 20);
  }
  v11 = v4;
  v12 = (signed __int64)&v8->m_data[v8->m_size];
  if ( (signed int)v4 > 0 )
  {
    v13 = v12 + 4;
    v14 = (char *)v7 - v12;
    do
    {
      v15 = *(_DWORD *)&v14[v13 - 4];
      v13 += 20i64;
      *(_DWORD *)(v13 - 24) = v15;
      *(_DWORD *)(v13 - 20) = *(_DWORD *)&v14[v13 - 20];
      *(_DWORD *)(v13 - 16) = *(_DWORD *)&v14[v13 - 16];
      *(_DWORD *)(v13 - 12) = *(_DWORD *)&v14[v13 - 12];
      *(_BYTE *)(v13 - 8) = v14[v13 - 8];
      *(_BYTE *)(v13 - 7) = v14[v13 - 7];
      *(_WORD *)(v13 - 6) = *(_WORD *)&v14[v13 - 6];
      --v11;
    }
    while ( v11 );
  }
  v8->m_size = v5;
}

// File Line: 436
// RVA: 0xC24BF0
void __fastcall hkArrayBase<hkaiStringPulling::Vertex>::_insertAt(hkArrayBase<hkaiStringPulling::Vertex> *this, hkMemoryAllocator *alloc, int i, hkaiStringPulling::Vertex *t)
{
  hkArrayBase<hkaiStringPulling::Vertex>::_insertAt(this, alloc, i, t, 1);
}

