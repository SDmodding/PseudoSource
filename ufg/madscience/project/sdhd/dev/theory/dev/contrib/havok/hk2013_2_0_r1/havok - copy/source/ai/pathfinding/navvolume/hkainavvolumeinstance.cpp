// File Line: 14
// RVA: 0xBF38B0
void __fastcall hkaiNavVolumeInstance::hkaiNavVolumeInstance(hkaiNavVolumeInstance *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiNavVolumeInstance::`vftable;
  this->m_originalVolume.m_pntr = 0i64;
  this->m_cellMap.m_data = 0i64;
  this->m_cellMap.m_size = 0;
  this->m_cellMap.m_capacityAndFlags = 0x80000000;
  this->m_instancedCells.m_data = 0i64;
  this->m_instancedCells.m_size = 0;
  this->m_instancedCells.m_capacityAndFlags = 0x80000000;
  this->m_ownedEdges.m_data = 0i64;
  this->m_ownedEdges.m_size = 0;
  *(_QWORD *)&this->m_ownedEdges.m_capacityAndFlags = 0xFFFFFFFF80000000ui64;
  this->m_runtimeId = -1;
  this->m_translation = 0i64;
}

// File Line: 26
// RVA: 0xBF3910
void __fastcall hkaiNavVolumeInstance::hkaiNavVolumeInstance(hkaiNavVolumeInstance *this, hkFinishLoadedObjectFlag f)
{
  hkaiNavVolume *m_pntr; // rdx

  this->vfptr = (hkBaseObjectVtbl *)&hkaiNavVolumeInstance::`vftable;
  if ( f.m_finishing )
  {
    m_pntr = this->m_originalVolume.m_pntr;
    if ( m_pntr )
    {
      this->m_originalCells = m_pntr->m_cells.m_data;
      this->m_numOriginalCells = m_pntr->m_cells.m_size;
      this->m_originalEdges = m_pntr->m_edges.m_data;
      this->m_numOriginalEdges = m_pntr->m_edges.m_size;
    }
  }
}

// File Line: 34
// RVA: 0xBF3950
void __fastcall hkaiNavVolumeInstance::init(hkaiNavVolumeInstance *this, hkaiNavVolume *vol, unsigned int uid)
{
  hkaiNavVolume *m_pntr; // rcx
  int m_size; // ebp
  int v7; // eax
  int v8; // eax
  int v9; // r9d
  int v10; // edx
  int *v11; // rdi
  __int64 v12; // rcx
  hkResult result; // [rsp+60h] [rbp+18h] BYREF

  this->m_sectionUid = uid;
  if ( vol )
    hkReferencedObject::addReference(vol);
  m_pntr = this->m_originalVolume.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_originalVolume.m_pntr = vol;
  m_size = vol->m_cells.m_size;
  v7 = this->m_cellMap.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v7 < m_size )
  {
    v8 = 2 * v7;
    v9 = vol->m_cells.m_size;
    if ( m_size < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_cellMap, v9, 4);
  }
  v10 = m_size - this->m_cellMap.m_size;
  v11 = &this->m_cellMap.m_data[this->m_cellMap.m_size];
  v12 = v10;
  if ( v10 > 0 )
  {
    while ( v12 )
    {
      *v11++ = -1;
      --v12;
    }
  }
  this->m_cellMap.m_size = m_size;
  this->m_originalCells = vol->m_cells.m_data;
  this->m_numOriginalCells = vol->m_cells.m_size;
  this->m_originalEdges = vol->m_edges.m_data;
  this->m_numOriginalEdges = vol->m_edges.m_size;
}

// File Line: 45
// RVA: 0xBF3A20
void __fastcall hkaiNavVolumeInstance::tempInit(hkaiNavVolumeInstance *this, hkaiNavVolume *vol)
{
  hkaiNavVolume *m_pntr; // rcx

  this->m_runtimeId = 0;
  if ( vol )
    hkReferencedObject::addReference(vol);
  m_pntr = this->m_originalVolume.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_originalVolume.m_pntr = vol;
  if ( vol )
  {
    this->m_originalCells = vol->m_cells.m_data;
    this->m_numOriginalCells = vol->m_cells.m_size;
    this->m_originalEdges = vol->m_edges.m_data;
    this->m_numOriginalEdges = vol->m_edges.m_size;
  }
}

// File Line: 58
// RVA: 0xBF3A90
hkaiNavVolume::Edge *__fastcall hkaiNavVolumeInstance::addEdgeForCell(hkaiNavVolumeInstance *this, int n)
{
  int *m_data; // rax
  int m_numOriginalEdges; // r14d
  int m_size; // r15d
  int v5; // edi
  int v7; // ebp
  __int64 v8; // rdx
  hkaiNavVolumeInstance::CellInstance *v9; // r8
  hkaiNavVolumeInstance::CellInstance *v10; // rax
  int m_numEdges; // edx
  hkaiNavVolumeInstance::CellInstance *v12; // rsi
  hkaiNavVolume::Edge *v13; // rcx
  hkaiNavVolume::Edge *v14; // rax
  hkaiNavVolume::Edge *v15; // r9
  hkaiNavVolume::Edge *v16; // r8
  int v17; // ecx
  int v18; // edx
  hkaiNavVolume::Edge *m_originalEdges; // rax

  m_data = this->m_cellMap.m_data;
  m_numOriginalEdges = this->m_numOriginalEdges;
  m_size = this->m_ownedEdges.m_size;
  v5 = 0;
  v7 = m_data[n];
  if ( v7 == -1 )
  {
    v7 = this->m_instancedCells.m_size;
    m_data[n] = v7;
    if ( this->m_instancedCells.m_size == (this->m_instancedCells.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &this->m_instancedCells, 8);
    v8 = this->m_instancedCells.m_size;
    v9 = &this->m_instancedCells.m_data[v8];
    this->m_instancedCells.m_size = v8 + 1;
    v9->m_numEdges = 0;
    v9->m_startEdgeIndex = -1;
  }
  v10 = this->m_instancedCells.m_data;
  m_numEdges = v10[v7].m_numEdges;
  v12 = &v10[v7];
  if ( m_numEdges )
  {
    v14 = hkaiNavVolumeInstance::expandEdgesBy(this, m_numEdges + 1);
    v15 = v14;
    if ( v12->m_numEdges > 0 )
    {
      v16 = v14;
      do
      {
        v17 = this->m_numOriginalEdges;
        v18 = v5 + v12->m_startEdgeIndex;
        if ( v18 >= v17 )
        {
          m_originalEdges = this->m_ownedEdges.m_data;
          v18 -= v17;
        }
        else
        {
          m_originalEdges = this->m_originalEdges;
        }
        ++v5;
        ++v16;
        v16[-1] = m_originalEdges[v18];
      }
      while ( v5 < v12->m_numEdges );
    }
    v13 = &v15[v12->m_numEdges];
  }
  else
  {
    v13 = hkaiNavVolumeInstance::expandEdgesBy(this, 1);
  }
  ++v12->m_numEdges;
  v12->m_startEdgeIndex = m_size + m_numOriginalEdges;
  return v13;
}

// File Line: 90
// RVA: 0xBF3BB0
void __fastcall hkaiNavVolumeInstance::removeOwnedEdgeForCell(hkaiNavVolumeInstance *this, int n, int e)
{
  int *m_data; // rax
  int m_size; // esi
  __int64 v7; // rdx
  hkaiNavVolumeInstance::CellInstance *v8; // r8
  hkaiNavVolumeInstance::CellInstance *v9; // rax
  int v10; // ebp
  int m_numEdges; // edx
  hkaiNavVolumeInstance::CellInstance *v12; // r8

  m_data = this->m_cellMap.m_data;
  m_size = m_data[n];
  if ( m_size == -1 )
  {
    m_size = this->m_instancedCells.m_size;
    m_data[n] = m_size;
    if ( this->m_instancedCells.m_size == (this->m_instancedCells.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &this->m_instancedCells, 8);
    v7 = this->m_instancedCells.m_size;
    v8 = &this->m_instancedCells.m_data[v7];
    this->m_instancedCells.m_size = v7 + 1;
    v8->m_numEdges = 0;
    v8->m_startEdgeIndex = -1;
  }
  v9 = this->m_instancedCells.m_data;
  v10 = e - this->m_numOriginalEdges;
  m_numEdges = v9[m_size].m_numEdges;
  v12 = &v9[m_size];
  if ( m_numEdges == 1 )
  {
    v12->m_numEdges = 0;
    v12->m_startEdgeIndex = -1;
  }
  else
  {
    this->m_ownedEdges.m_data[v10] = this->m_ownedEdges.m_data[v12->m_startEdgeIndex
                                                             - this->m_numOriginalEdges
                                                             - 1
                                                             + m_numEdges];
    --v12->m_numEdges;
  }
}

// File Line: 113
// RVA: 0xBF3CA0
hkaiNavVolume::Edge *__fastcall hkaiNavVolumeInstance::expandEdgesBy(hkaiNavVolumeInstance *this, int n)
{
  __int64 m_size; // rsi
  hkArray<hkaiNavVolume::Edge,hkContainerHeapAllocator> *p_m_ownedEdges; // rbx
  int v4; // r9d
  int v5; // eax
  int v7; // eax
  hkaiNavVolume::Edge *m_data; // rax
  hkResult result; // [rsp+48h] [rbp+10h] BYREF

  m_size = this->m_ownedEdges.m_size;
  p_m_ownedEdges = &this->m_ownedEdges;
  v4 = m_size + n;
  v5 = this->m_ownedEdges.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v5 < (int)m_size + n )
  {
    v7 = 2 * v5;
    if ( v4 < v7 )
      v4 = v7;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, p_m_ownedEdges, v4, 8);
  }
  m_data = p_m_ownedEdges->m_data;
  p_m_ownedEdges->m_size += n;
  return &m_data[m_size];
}

// File Line: 121
// RVA: 0xBF3D10
void __fastcall hkaiNavVolumeInstance::checkDeterminism(hkaiNavVolumeInstance *this)
{
  ;
}

