// File Line: 37
// RVA: 0x340D70
void __fastcall UFG::NavPath::AddResource(UFG::NavPath *this, UFG::qReflectInventoryBase *pNavResource)
{
  __int64 size; // rbp
  UFG::qArray<UFG::qReflectInventoryBase *,0> *p_m_aResources; // rdi
  unsigned int capacity; // edx
  unsigned int v6; // ebx
  unsigned int v7; // edx
  UFG::qReflectInventoryBase **p; // rax

  size = this->m_aResources.size;
  p_m_aResources = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->m_aResources;
  capacity = this->m_aResources.capacity;
  v6 = size + 1;
  if ( (int)size + 1 > capacity )
  {
    if ( capacity )
      v7 = 2 * capacity;
    else
      v7 = 1;
    for ( ; v7 < v6; v7 *= 2 )
      ;
    if ( v7 <= 2 )
      v7 = 2;
    if ( v7 - v6 > 0x10000 )
      v7 = size + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(p_m_aResources, v7, "qArray.Add");
  }
  p = p_m_aResources->p;
  p_m_aResources->size = v6;
  p[size] = pNavResource;
  ((void (__fastcall *)(UFG::qReflectInventoryBase *))pNavResource->vfptr->IsBaseClassOfThis)(pNavResource);
}

// File Line: 96
// RVA: 0xE6330
void __fastcall UFG::NavPathRefPtr::~NavPathRefPtr(UFG::NavPathRefPtr *this)
{
  UFG::NavPath *m_pNavPath; // rcx

  m_pNavPath = this->m_pNavPath;
  if ( m_pNavPath )
  {
    if ( m_pNavPath->m_uRefCount-- == 1 )
      m_pNavPath->vfptr->__vecDelDtor(m_pNavPath, 1u);
  }
}

// File Line: 104
// RVA: 0xE66B0
UFG::NavPathRefPtr *__fastcall UFG::NavPathRefPtr::operator=(UFG::NavPathRefPtr *this, UFG::NavPathRefPtr *ref_ptr)
{
  UFG::NavPath *m_pNavPath; // rax
  UFG::NavPath *v5; // rcx

  m_pNavPath = ref_ptr->m_pNavPath;
  if ( this->m_pNavPath != ref_ptr->m_pNavPath )
  {
    if ( m_pNavPath )
      ++m_pNavPath->m_uRefCount;
    v5 = this->m_pNavPath;
    if ( v5 )
    {
      if ( v5->m_uRefCount-- == 1 )
        v5->vfptr->__vecDelDtor(v5, 1u);
    }
    this->m_pNavPath = ref_ptr->m_pNavPath;
  }
  return this;
}

// File Line: 124
// RVA: 0xE6700
UFG::NavPathRefPtr *__fastcall UFG::NavPathRefPtr::operator=(UFG::NavPathRefPtr *this, UFG::NavPath *pNavPath)
{
  UFG::NavPath *m_pNavPath; // rcx

  if ( this->m_pNavPath != pNavPath )
  {
    if ( pNavPath )
      ++pNavPath->m_uRefCount;
    m_pNavPath = this->m_pNavPath;
    if ( m_pNavPath )
    {
      if ( m_pNavPath->m_uRefCount-- == 1 )
        m_pNavPath->vfptr->__vecDelDtor(m_pNavPath, 1u);
    }
    this->m_pNavPath = pNavPath;
  }
  return this;
}

