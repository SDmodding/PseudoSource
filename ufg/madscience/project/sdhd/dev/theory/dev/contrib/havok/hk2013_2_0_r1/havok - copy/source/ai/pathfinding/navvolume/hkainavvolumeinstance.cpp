// File Line: 14
// RVA: 0xBF38B0
void __fastcall hkaiNavVolumeInstance::hkaiNavVolumeInstance(hkaiNavVolumeInstance *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiNavVolumeInstance::`vftable';
  this->m_originalVolume.m_pntr = 0i64;
  this->m_cellMap.m_data = 0i64;
  this->m_cellMap.m_size = 0;
  this->m_cellMap.m_capacityAndFlags = 2147483648;
  this->m_instancedCells.m_data = 0i64;
  this->m_instancedCells.m_size = 0;
  this->m_instancedCells.m_capacityAndFlags = 2147483648;
  this->m_ownedEdges.m_data = 0i64;
  this->m_ownedEdges.m_size = 0;
  *(_QWORD *)&this->m_ownedEdges.m_capacityAndFlags = -2147483648i64;
  this->m_runtimeId = -1;
  this->m_translation = 0i64;
}

// File Line: 26
// RVA: 0xBF3910
void __fastcall hkaiNavVolumeInstance::hkaiNavVolumeInstance(hkaiNavVolumeInstance *this, hkFinishLoadedObjectFlag f)
{
  hkaiNavVolume *v2; // rdx

  this->vfptr = (hkBaseObjectVtbl *)&hkaiNavVolumeInstance::`vftable';
  if ( f.m_finishing )
  {
    v2 = this->m_originalVolume.m_pntr;
    if ( v2 )
    {
      this->m_originalCells = v2->m_cells.m_data;
      this->m_numOriginalCells = v2->m_cells.m_size;
      this->m_originalEdges = v2->m_edges.m_data;
      this->m_numOriginalEdges = v2->m_edges.m_size;
    }
  }
}

// File Line: 34
// RVA: 0xBF3950
void __fastcall hkaiNavVolumeInstance::init(hkaiNavVolumeInstance *this, hkaiNavVolume *vol, unsigned int uid)
{
  hkaiNavVolume *v3; // rbx
  hkaiNavVolumeInstance *v4; // rsi
  hkReferencedObject *v5; // rcx
  int v6; // ebp
  int v7; // eax
  int v8; // eax
  int v9; // er9
  int v10; // edx
  int *v11; // rdi
  __int64 v12; // rcx
  hkResult result; // [rsp+60h] [rbp+18h]

  v3 = vol;
  v4 = this;
  this->m_sectionUid = uid;
  if ( vol )
    hkReferencedObject::addReference((hkReferencedObject *)&vol->vfptr);
  v5 = (hkReferencedObject *)&v4->m_originalVolume.m_pntr->vfptr;
  if ( v5 )
    hkReferencedObject::removeReference(v5);
  v4->m_originalVolume.m_pntr = v3;
  v6 = v3->m_cells.m_size;
  v7 = v4->m_cellMap.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v7 < v6 )
  {
    v8 = 2 * v7;
    v9 = v3->m_cells.m_size;
    if ( v6 < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v4->m_cellMap, v9, 4);
  }
  v10 = v6 - v4->m_cellMap.m_size;
  v11 = &v4->m_cellMap.m_data[v4->m_cellMap.m_size];
  v12 = v10;
  if ( v10 > 0 )
  {
    while ( v12 )
    {
      *v11 = -1;
      ++v11;
      --v12;
    }
  }
  v4->m_cellMap.m_size = v6;
  v4->m_originalCells = v3->m_cells.m_data;
  v4->m_numOriginalCells = v3->m_cells.m_size;
  v4->m_originalEdges = v3->m_edges.m_data;
  v4->m_numOriginalEdges = v3->m_edges.m_size;
}

// File Line: 45
// RVA: 0xBF3A20
void __fastcall hkaiNavVolumeInstance::tempInit(hkaiNavVolumeInstance *this, hkaiNavVolume *vol)
{
  hkaiNavVolume *v2; // rbx
  hkaiNavVolumeInstance *v3; // rdi
  hkReferencedObject *v4; // rcx

  v2 = vol;
  v3 = this;
  this->m_runtimeId = 0;
  if ( vol )
    hkReferencedObject::addReference((hkReferencedObject *)&vol->vfptr);
  v4 = (hkReferencedObject *)&v3->m_originalVolume.m_pntr->vfptr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  v3->m_originalVolume.m_pntr = v2;
  if ( v2 )
  {
    v3->m_originalCells = v2->m_cells.m_data;
    v3->m_numOriginalCells = v2->m_cells.m_size;
    v3->m_originalEdges = v2->m_edges.m_data;
    v3->m_numOriginalEdges = v2->m_edges.m_size;
  }
}

// File Line: 58
// RVA: 0xBF3A90
hkaiNavVolume::Edge *__fastcall hkaiNavVolumeInstance::addEdgeForCell(hkaiNavVolumeInstance *this, __int64 n)
{
  int *v2; // rax
  int v3; // er14
  int v4; // er15
  int v5; // edi
  hkaiNavVolumeInstance *v6; // rbx
  int v7; // ebp
  __int64 v8; // rdx
  hkaiNavVolumeInstance::CellInstance *v9; // r8
  hkaiNavVolumeInstance::CellInstance *v10; // rax
  int v11; // edx
  hkaiNavVolumeInstance::CellInstance *v12; // rsi
  hkaiNavVolume::Edge *v13; // rcx
  hkaiNavVolume::Edge *v14; // rax
  hkaiNavVolume::Edge *v15; // r9
  hkaiNavVolume::Edge *v16; // r8
  int v17; // ecx
  int v18; // edx
  hkaiNavVolume::Edge *v19; // rax

  v2 = this->m_cellMap.m_data;
  v3 = this->m_numOriginalEdges;
  v4 = this->m_ownedEdges.m_size;
  n = (signed int)n;
  v5 = 0;
  v6 = this;
  v7 = v2[(signed int)n];
  if ( v7 == -1 )
  {
    v7 = this->m_instancedCells.m_size;
    v2[n] = v7;
    if ( this->m_instancedCells.m_size == (this->m_instancedCells.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &this->m_instancedCells,
        8);
    v8 = v6->m_instancedCells.m_size;
    v9 = &v6->m_instancedCells.m_data[v8];
    v6->m_instancedCells.m_size = v8 + 1;
    v9->m_numEdges = 0;
    v9->m_startEdgeIndex = -1;
  }
  v10 = v6->m_instancedCells.m_data;
  v11 = v10[v7].m_numEdges;
  v12 = &v10[v7];
  if ( v11 )
  {
    v14 = hkaiNavVolumeInstance::expandEdgesBy(v6, v11 + 1);
    v15 = v14;
    if ( v12->m_numEdges > 0 )
    {
      v16 = v14;
      do
      {
        v17 = v6->m_numOriginalEdges;
        v18 = v5 + v12->m_startEdgeIndex;
        if ( v18 >= v17 )
        {
          v19 = v6->m_ownedEdges.m_data;
          v18 -= v17;
        }
        else
        {
          v19 = v6->m_originalEdges;
        }
        ++v5;
        ++v16;
        v16[-1] = v19[v18];
      }
      while ( v5 < v12->m_numEdges );
    }
    v13 = &v15[v12->m_numEdges];
  }
  else
  {
    v13 = hkaiNavVolumeInstance::expandEdgesBy(v6, 1);
  }
  ++v12->m_numEdges;
  v12->m_startEdgeIndex = v4 + v3;
  return v13;
}

// File Line: 90
// RVA: 0xBF3BB0
void __fastcall hkaiNavVolumeInstance::removeOwnedEdgeForCell(hkaiNavVolumeInstance *this, __int64 n, int e)
{
  int *v3; // rax
  int v4; // esi
  int v5; // ebp
  hkaiNavVolumeInstance *v6; // rdi
  __int64 v7; // rdx
  hkaiNavVolumeInstance::CellInstance *v8; // r8
  hkaiNavVolumeInstance::CellInstance *v9; // rax
  int v10; // ebp
  int v11; // edx
  hkaiNavVolumeInstance::CellInstance *v12; // r8

  v3 = this->m_cellMap.m_data;
  n = (signed int)n;
  v4 = v3[(signed int)n];
  v5 = e;
  v6 = this;
  if ( v4 == -1 )
  {
    v4 = this->m_instancedCells.m_size;
    v3[n] = v4;
    if ( this->m_instancedCells.m_size == (this->m_instancedCells.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &this->m_instancedCells,
        8);
    v7 = v6->m_instancedCells.m_size;
    v8 = &v6->m_instancedCells.m_data[v7];
    v6->m_instancedCells.m_size = v7 + 1;
    v8->m_numEdges = 0;
    v8->m_startEdgeIndex = -1;
  }
  v9 = v6->m_instancedCells.m_data;
  v10 = v5 - v6->m_numOriginalEdges;
  v11 = v9[v4].m_numEdges;
  v12 = &v9[v4];
  if ( v11 == 1 )
  {
    v12->m_numEdges = 0;
    v12->m_startEdgeIndex = -1;
  }
  else
  {
    v6->m_ownedEdges.m_data[v10] = v6->m_ownedEdges.m_data[v12->m_startEdgeIndex - v6->m_numOriginalEdges - 1 + v11];
    --v12->m_numEdges;
  }
}

// File Line: 113
// RVA: 0xBF3CA0
hkaiNavVolume::Edge *__fastcall hkaiNavVolumeInstance::expandEdgesBy(hkaiNavVolumeInstance *this, int n)
{
  __int64 v2; // rsi
  hkArray<hkaiNavVolume::Edge,hkContainerHeapAllocator> *v3; // rbx
  int v4; // er9
  int v5; // eax
  int v6; // edi
  int v7; // eax
  hkaiNavVolume::Edge *v8; // rax
  hkResult result; // [rsp+48h] [rbp+10h]

  v2 = this->m_ownedEdges.m_size;
  v3 = &this->m_ownedEdges;
  v4 = v2 + n;
  v5 = this->m_ownedEdges.m_capacityAndFlags & 0x3FFFFFFF;
  v6 = n;
  if ( v5 < (signed int)v2 + n )
  {
    v7 = 2 * v5;
    if ( v4 < v7 )
      v4 = v7;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, v4, 8);
  }
  v8 = v3->m_data;
  v3->m_size += v6;
  return &v8[v2];
}

// File Line: 121
// RVA: 0xBF3D10
void __fastcall hkaiNavVolumeInstance::checkDeterminism(hkaiNavVolumeInstance *this)
{
  ;
}

