// File Line: 37
// RVA: 0x340D70
void __fastcall UFG::NavPath::AddResource(UFG::NavPath *this, UFG::NavResource *pNavResource)
{
  __int64 v2; // rbp
  UFG::qArray<UFG::qReflectInventoryBase *,0> *v3; // rdi
  UFG::NavResource *v4; // rsi
  unsigned int v5; // edx
  unsigned int v6; // ebx
  unsigned int v7; // edx
  UFG::qReflectInventoryBase **v8; // rax

  v2 = this->m_aResources.size;
  v3 = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->m_aResources;
  v4 = pNavResource;
  v5 = this->m_aResources.capacity;
  v6 = v2 + 1;
  if ( (signed int)v2 + 1 > v5 )
  {
    if ( v5 )
      v7 = 2 * v5;
    else
      v7 = 1;
    for ( ; v7 < v6; v7 *= 2 )
      ;
    if ( v7 <= 2 )
      v7 = 2;
    if ( v7 - v6 > 0x10000 )
      v7 = v2 + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(v3, v7, "qArray.Add");
  }
  v8 = v3->p;
  v3->size = v6;
  v8[v2] = (UFG::qReflectInventoryBase *)v4;
  v4->vfptr->Reference(v4);
}

// File Line: 96
// RVA: 0xE6330
void __fastcall UFG::NavPathRefPtr::~NavPathRefPtr(UFG::NavPathRefPtr *this)
{
  UFG::NavPath *v1; // rcx
  bool v2; // zf

  v1 = this->m_pNavPath;
  if ( v1 )
  {
    v2 = v1->m_uRefCount-- == 1;
    if ( v2 )
      v1->vfptr->__vecDelDtor(v1, 1u);
  }
}

// File Line: 104
// RVA: 0xE66B0
UFG::NavPathRefPtr *__fastcall UFG::NavPathRefPtr::operator=(UFG::NavPathRefPtr *this, UFG::NavPathRefPtr *ref_ptr)
{
  UFG::NavPath *v2; // rax
  UFG::NavPathRefPtr *v3; // rdi
  UFG::NavPathRefPtr *v4; // rbx
  UFG::NavPath *v5; // rcx
  bool v6; // zf

  v2 = ref_ptr->m_pNavPath;
  v3 = ref_ptr;
  v4 = this;
  if ( this->m_pNavPath != ref_ptr->m_pNavPath )
  {
    if ( v2 )
      ++v2->m_uRefCount;
    v5 = this->m_pNavPath;
    if ( v5 )
    {
      v6 = v5->m_uRefCount-- == 1;
      if ( v6 )
        v5->vfptr->__vecDelDtor(v5, 1u);
    }
    v4->m_pNavPath = v3->m_pNavPath;
  }
  return v4;
}

// File Line: 124
// RVA: 0xE6700
UFG::NavPathRefPtr *__fastcall UFG::NavPathRefPtr::operator=(UFG::NavPathRefPtr *this, UFG::NavPath *pNavPath)
{
  UFG::NavPath *v2; // rdi
  UFG::NavPathRefPtr *v3; // rbx
  UFG::NavPath *v4; // rcx
  bool v5; // zf

  v2 = pNavPath;
  v3 = this;
  if ( this->m_pNavPath != pNavPath )
  {
    if ( pNavPath )
      ++pNavPath->m_uRefCount;
    v4 = this->m_pNavPath;
    if ( v4 )
    {
      v5 = v4->m_uRefCount-- == 1;
      if ( v5 )
        v4->vfptr->__vecDelDtor(v4, 1u);
    }
    v3->m_pNavPath = v2;
  }
  return v3;
}

