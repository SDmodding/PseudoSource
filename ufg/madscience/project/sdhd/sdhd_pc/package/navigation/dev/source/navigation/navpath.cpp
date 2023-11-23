// File Line: 7
// RVA: 0x262FB0
void __fastcall UFG::NavPath::~NavPath(UFG::NavPath *this)
{
  unsigned int i; // esi
  UFG::NavWaypoint *v3; // rbx
  UFG::NavObject *m_pNavObject; // rcx
  unsigned int j; // esi
  UFG::NavResource *v6; // rbx
  UFG::NavResource **p; // rcx
  UFG::NavWaypoint *v8; // rcx
  UFG::NavObject **p_m_pNavObject; // rbx

  this->vfptr = (UFG::NavPathVtbl *)&UFG::NavPath::`vftable;
  for ( i = 0; i < this->m_aWaypoints.size; ++i )
  {
    v3 = &this->m_aWaypoints.p[i];
    m_pNavObject = v3->m_pNavObject;
    if ( m_pNavObject )
    {
      m_pNavObject->vfptr->__vecDelDtor(m_pNavObject, 1u);
      v3->m_pNavObject = 0i64;
    }
  }
  for ( j = 0; j < this->m_aResources.size; ++j )
  {
    v6 = this->m_aResources.p[j];
    v6->vfptr->Dereference(v6);
    v6->vfptr->__vecDelDtor(v6, 1u);
  }
  p = this->m_aResources.p;
  if ( p )
    operator delete[](p);
  this->m_aResources.p = 0i64;
  *(_QWORD *)&this->m_aResources.size = 0i64;
  v8 = this->m_aWaypoints.p;
  if ( v8 )
  {
    p_m_pNavObject = &v8[-1].m_pNavObject;
    `eh vector destructor iterator(v8, 0x50ui64, (int)v8[-1].m_pNavObject, (void (__fastcall *)(void *))_);
    operator delete[](p_m_pNavObject);
  }
  this->m_aWaypoints.p = 0i64;
  *(_QWORD *)&this->m_aWaypoints.size = 0i64;
}

// File Line: 30
// RVA: 0x265D80
void __fastcall UFG::NavPath::RemoveWaypointEnd(UFG::NavPath *this)
{
  UFG::NavWaypoint *v2; // rdi
  UFG::NavObject *m_pNavObject; // rcx
  unsigned int size; // eax

  v2 = &this->m_aWaypoints.p[this->m_aWaypoints.size - 1];
  m_pNavObject = v2->m_pNavObject;
  if ( m_pNavObject )
  {
    m_pNavObject->vfptr->__vecDelDtor(m_pNavObject, 1u);
    v2->m_pNavObject = 0i64;
  }
  size = this->m_aWaypoints.size;
  if ( size > 1 )
    this->m_aWaypoints.size = size - 1;
  else
    this->m_aWaypoints.size = 0;
}

// File Line: 50
// RVA: 0x263770
void __fastcall UFG::NavPath::Append(UFG::NavPath *this, UFG::NavPath *pNavPath)
{
  UFG::NavWaypoint *p; // rbp
  UFG::NavObject *m_pNavObject; // rcx
  __int64 size; // r15
  unsigned int capacity; // ebx
  UFG::NavResource **v8; // r12
  unsigned int v9; // ebp
  unsigned int v10; // ebx
  unsigned __int64 v11; // rax
  UFG::allocator::free_link *v12; // rax
  UFG::NavResource **v13; // r14
  __int64 i; // r9
  __int64 v15; // r8
  UFG::NavResource **v16; // rcx
  int v17; // r8d
  __int64 v18; // rdx
  unsigned int v19; // eax
  unsigned int v20; // eax

  if ( pNavPath )
  {
    if ( pNavPath->m_aWaypoints.size )
    {
      p = pNavPath->m_aWaypoints.p;
      m_pNavObject = p->m_pNavObject;
      if ( m_pNavObject )
      {
        m_pNavObject->vfptr->__vecDelDtor(m_pNavObject, 1u);
        p->m_pNavObject = 0i64;
      }
      UFG::qArray<UFG::NavWaypoint,0>::StableDelete(&pNavPath->m_aWaypoints, 0);
    }
    while ( pNavPath->m_aWaypoints.size )
    {
      UFG::qArray<UFG::NavWaypoint,0>::Add(&this->m_aWaypoints, pNavPath->m_aWaypoints.p, "qArray.Add");
      UFG::qArray<UFG::NavWaypoint,0>::StableDelete(&pNavPath->m_aWaypoints, 0);
    }
    if ( pNavPath->m_aResources.size )
    {
      while ( 1 )
      {
        size = this->m_aResources.size;
        capacity = this->m_aResources.capacity;
        v8 = pNavPath->m_aResources.p;
        v9 = size + 1;
        if ( (int)size + 1 > capacity )
        {
          if ( capacity )
            v10 = 2 * capacity;
          else
            v10 = 1;
          for ( ; v10 < v9; v10 *= 2 )
            ;
          if ( v10 <= 2 )
            v10 = 2;
          if ( v10 - v9 > 0x10000 )
            v10 = size + 65537;
          if ( v10 != (_DWORD)size )
          {
            v11 = 8i64 * v10;
            if ( !is_mul_ok(v10, 8ui64) )
              v11 = -1i64;
            v12 = UFG::qMalloc(v11, "qArray.Add", 0i64);
            v13 = (UFG::NavResource **)v12;
            if ( this->m_aResources.p )
            {
              for ( i = 0i64;
                    (unsigned int)i < this->m_aResources.size;
                    v12[v15] = (UFG::allocator::free_link)this->m_aResources.p[v15] )
              {
                v15 = i;
                i = (unsigned int)(i + 1);
              }
              operator delete[](this->m_aResources.p);
            }
            this->m_aResources.p = v13;
            this->m_aResources.capacity = v10;
          }
        }
        v16 = this->m_aResources.p;
        this->m_aResources.size = v9;
        v17 = 1;
        v16[size] = *v8;
        if ( pNavPath->m_aResources.size != 1 )
        {
          v18 = 1i64;
          do
          {
            ++v17;
            ++v18;
            pNavPath->m_aResources.p[v18 - 2] = pNavPath->m_aResources.p[v18 - 1];
          }
          while ( v17 != pNavPath->m_aResources.size );
        }
        v19 = pNavPath->m_aResources.size;
        if ( v19 <= 1 )
          break;
        v20 = v19 - 1;
        pNavPath->m_aResources.size = v20;
        if ( !v20 )
          return;
      }
      pNavPath->m_aResources.size = 0;
    }
  }
}

// File Line: 100
// RVA: 0x265CA0
void __fastcall UFG::NavPath::RemoveTaggedResources(UFG::NavPath *this, unsigned int tag)
{
  unsigned int v4; // edi
  __int64 v5; // rbp
  UFG::NavResource *v6; // rsi
  unsigned int v7; // edx
  __int64 v8; // r8
  unsigned int size; // eax

  v4 = 0;
  if ( this->m_aResources.size )
  {
    v5 = 8i64;
    do
    {
      v6 = this->m_aResources.p[v4];
      if ( v6->m_tag == tag )
      {
        v6->vfptr->Dereference(v6);
        v7 = v4 + 1;
        if ( v4 + 1 != this->m_aResources.size )
        {
          v8 = v5;
          do
          {
            ++v7;
            v8 += 8i64;
            *(UFG::NavResource **)((char *)this->m_aResources.p + v8 - 16) = *(UFG::NavResource **)((char *)this->m_aResources.p
                                                                                                  + v8
                                                                                                  - 8);
          }
          while ( v7 != this->m_aResources.size );
        }
        size = this->m_aResources.size;
        if ( size > 1 )
          this->m_aResources.size = size - 1;
        else
          this->m_aResources.size = 0;
        v6->vfptr->__vecDelDtor(v6, 1u);
      }
      else
      {
        ++v4;
        v5 += 8i64;
      }
    }
    while ( v4 < this->m_aResources.size );
  }
}

