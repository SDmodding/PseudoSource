// File Line: 382
// RVA: 0x481190
void __fastcall hkArrayBase<hkpSimulationIsland *>::_spliceInto(
        hkArrayBase<hkProcess *> *this,
        hkMemoryAllocator *alloc,
        int index,
        int numdel,
        hkpEntity *const *p,
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
  hkProcess **v15; // rax
  char *v16; // rdx
  hkProcess *v17; // rcx

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
  hkMemUtil::memMove(&this->m_data[v6] + v8, &this->m_data[v8] + v7, 8 * v11);
  v15 = &this->m_data[v8];
  if ( v6 > 0 )
  {
    v16 = (char *)((char *)p - (char *)v15);
    do
    {
      v17 = *(hkProcess **)((char *)v15++ + (_QWORD)v16);
      *(v15 - 1) = v17;
      --v6;
    }
    while ( v6 );
  }
  this->m_size = v10;
}

// File Line: 400
// RVA: 0x481170
void __fastcall hkArrayBase<hkpEntity *>::_insertAt(
        hkArrayBase<hkProcess *> *this,
        hkMemoryAllocator *alloc,
        int index,
        hkProcess *const *p,
        int numtoinsert)
{
  hkArrayBase<hkpSimulationIsland *>::_spliceInto(this, alloc, index, 0, p, numtoinsert);
}

// File Line: 533
// RVA: 0x44EA20
void __fastcall hkArray<UFG::HavokNavManager::MeshCell *,hkContainerHeapAllocator>::~hkArray<UFG::HavokNavManager::MeshCell *,hkContainerHeapAllocator>(
        hkArray<hkpShape const *,hkContainerHeapAllocator> *this)
{
  int m_capacityAndFlags; // r8d

  m_capacityAndFlags = this->m_capacityAndFlags;
  this->m_size = 0;
  if ( m_capacityAndFlags < 0 )
  {
    this->m_data = 0i64;
    this->m_capacityAndFlags = 0x80000000;
  }
  else
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_data,
      8 * m_capacityAndFlags);
    this->m_data = 0i64;
    this->m_capacityAndFlags = 0x80000000;
  }
}

