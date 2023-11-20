// File Line: 7
// RVA: 0x262FB0
void __fastcall UFG::NavPath::~NavPath(UFG::NavPath *this)
{
  UFG::NavPath *v1; // rdi
  unsigned int v2; // esi
  signed __int64 v3; // rbx
  void (__fastcall ***v4)(_QWORD, signed __int64); // rcx
  unsigned int i; // esi
  UFG::NavResource *v6; // rbx
  UFG::NavResource **v7; // rcx
  UFG::NavWaypoint *v8; // rcx
  UFG::NavObject **v9; // rbx

  v1 = this;
  this->vfptr = (UFG::NavPathVtbl *)&UFG::NavPath::`vftable;
  v2 = 0;
  if ( this->m_aWaypoints.size )
  {
    do
    {
      v3 = (signed __int64)&v1->m_aWaypoints.p[v2];
      v4 = *(void (__fastcall ****)(_QWORD, signed __int64))(v3 + 64);
      if ( v4 )
      {
        (**v4)(v4, 1i64);
        *(_QWORD *)(v3 + 64) = 0i64;
      }
      ++v2;
    }
    while ( v2 < v1->m_aWaypoints.size );
  }
  for ( i = 0; i < v1->m_aResources.size; ++i )
  {
    v6 = v1->m_aResources.p[i];
    v6->vfptr->Dereference(v1->m_aResources.p[i]);
    v6->vfptr->__vecDelDtor(v6, 1u);
  }
  v7 = v1->m_aResources.p;
  if ( v7 )
    operator delete[](v7);
  v1->m_aResources.p = 0i64;
  *(_QWORD *)&v1->m_aResources.size = 0i64;
  v8 = v1->m_aWaypoints.p;
  if ( v8 )
  {
    v9 = &v8[-1].m_pNavObject;
    `eh vector destructor iterator(v8, 0x50ui64, (int)v8[-1].m_pNavObject, (void (__fastcall *)(void *))_);
    operator delete[](v9);
  }
  v1->m_aWaypoints.p = 0i64;
  *(_QWORD *)&v1->m_aWaypoints.size = 0i64;
}

// File Line: 30
// RVA: 0x265D80
void __fastcall UFG::NavPath::RemoveWaypointEnd(UFG::NavPath *this)
{
  UFG::NavPath *v1; // rbx
  UFG::NavWaypoint *v2; // rdi
  UFG::NavObject *v3; // rcx
  unsigned int v4; // eax

  v1 = this;
  v2 = &this->m_aWaypoints.p[this->m_aWaypoints.size - 1];
  v3 = v2->m_pNavObject;
  if ( v3 )
  {
    v3->vfptr->__vecDelDtor(v3, 1u);
    v2->m_pNavObject = 0i64;
  }
  v4 = v1->m_aWaypoints.size;
  if ( v4 > 1 )
    v1->m_aWaypoints.size = v4 - 1;
  else
    v1->m_aWaypoints.size = 0;
}

// File Line: 50
// RVA: 0x263770
void __fastcall UFG::NavPath::Append(UFG::NavPath *this, UFG::NavPath *pNavPath)
{
  UFG::NavPath *v2; // rdi
  UFG::NavPath *v3; // rsi
  UFG::NavWaypoint *v4; // rbp
  UFG::NavObject *v5; // rcx
  __int64 v6; // r15
  unsigned int v7; // ebx
  UFG::NavResource **v8; // r12
  unsigned int v9; // ebp
  unsigned int v10; // ebx
  unsigned __int64 v11; // rax
  UFG::allocator::free_link *v12; // rax
  UFG::NavResource **v13; // r14
  signed __int64 v14; // r9
  signed __int64 v15; // r8
  UFG::NavResource **v16; // rcx
  signed int v17; // er8
  signed __int64 v18; // rdx
  unsigned int v19; // eax
  int v20; // eax

  if ( pNavPath )
  {
    v2 = pNavPath;
    v3 = this;
    if ( pNavPath->m_aWaypoints.size )
    {
      v4 = pNavPath->m_aWaypoints.p;
      v5 = v4->m_pNavObject;
      if ( v5 )
      {
        v5->vfptr->__vecDelDtor(v5, 1u);
        v4->m_pNavObject = 0i64;
      }
      UFG::qArray<UFG::NavWaypoint,0>::StableDelete(&v2->m_aWaypoints, 0);
    }
    while ( v2->m_aWaypoints.size )
    {
      UFG::qArray<UFG::NavWaypoint,0>::Add(&v3->m_aWaypoints, v2->m_aWaypoints.p, "qArray.Add");
      UFG::qArray<UFG::NavWaypoint,0>::StableDelete(&v2->m_aWaypoints, 0);
    }
    if ( v2->m_aResources.size )
    {
      while ( 1 )
      {
        v6 = v3->m_aResources.size;
        v7 = v3->m_aResources.capacity;
        v8 = v2->m_aResources.p;
        v9 = v6 + 1;
        if ( (signed int)v6 + 1 > v7 )
        {
          if ( v7 )
            v10 = 2 * v7;
          else
            v10 = 1;
          for ( ; v10 < v9; v10 *= 2 )
            ;
          if ( v10 <= 2 )
            v10 = 2;
          if ( v10 - v9 > 0x10000 )
            v10 = v6 + 65537;
          if ( v10 != (_DWORD)v6 )
          {
            v11 = 8i64 * v10;
            if ( !is_mul_ok(v10, 8ui64) )
              v11 = -1i64;
            v12 = UFG::qMalloc(v11, "qArray.Add", 0i64);
            v13 = (UFG::NavResource **)v12;
            if ( v3->m_aResources.p )
            {
              v14 = 0i64;
              if ( v3->m_aResources.size )
              {
                do
                {
                  v15 = v14;
                  v14 = (unsigned int)(v14 + 1);
                  v12[v15] = (UFG::allocator::free_link)v3->m_aResources.p[v15];
                }
                while ( (unsigned int)v14 < v3->m_aResources.size );
              }
              operator delete[](v3->m_aResources.p);
            }
            v3->m_aResources.p = v13;
            v3->m_aResources.capacity = v10;
          }
        }
        v16 = v3->m_aResources.p;
        v3->m_aResources.size = v9;
        v17 = 1;
        v16[v6] = *v8;
        if ( v2->m_aResources.size != 1 )
        {
          v18 = 1i64;
          do
          {
            ++v17;
            ++v18;
            v2->m_aResources.p[v18 - 2] = v2->m_aResources.p[v18 - 1];
          }
          while ( v17 != v2->m_aResources.size );
        }
        v19 = v2->m_aResources.size;
        if ( v19 <= 1 )
          break;
        v20 = v19 - 1;
        v2->m_aResources.size = v20;
        if ( !v20 )
          return;
      }
      v2->m_aResources.size = 0;
    }
  }
}

// File Line: 100
// RVA: 0x265CA0
void __fastcall UFG::NavPath::RemoveTaggedResources(UFG::NavPath *this, unsigned int tag)
{
  unsigned int v2; // er14
  UFG::NavPath *v3; // rbx
  unsigned int v4; // edi
  signed __int64 v5; // rbp
  UFG::NavResource *v6; // rsi
  int v7; // edx
  signed __int64 v8; // r8
  unsigned int v9; // eax

  v2 = tag;
  v3 = this;
  v4 = 0;
  if ( this->m_aResources.size )
  {
    v5 = 8i64;
    do
    {
      v6 = v3->m_aResources.p[v4];
      if ( v6->m_tag == v2 )
      {
        v6->vfptr->Dereference(v6);
        v7 = v4 + 1;
        if ( v4 + 1 != v3->m_aResources.size )
        {
          v8 = v5;
          do
          {
            ++v7;
            v8 += 8i64;
            *(UFG::NavResource **)((char *)v3->m_aResources.p + v8 - 16) = *(UFG::NavResource **)((char *)v3->m_aResources.p
                                                                                                + v8
                                                                                                - 8);
          }
          while ( v7 != v3->m_aResources.size );
        }
        v9 = v3->m_aResources.size;
        if ( v9 > 1 )
          v3->m_aResources.size = v9 - 1;
        else
          v3->m_aResources.size = 0;
        v6->vfptr->__vecDelDtor(v6, 1u);
      }
      else
      {
        ++v4;
        v5 += 8i64;
      }
    }
    while ( v4 < v3->m_aResources.size );
  }
}

