// File Line: 252
// RVA: 0x9A33D0
void __fastcall Scaleform::Render::MeshCacheListSet::PushListToFront(
        Scaleform::Render::MeshCacheListSet *this,
        Scaleform::Render::MeshCacheListType to,
        int from)
{
  __int64 v3; // r9
  __int64 v4; // rax
  Scaleform::Render::MeshCache **i; // r9
  char *v6; // rdx
  Scaleform::Render::MeshCache **v7; // r10
  Scaleform::Render::MeshCache *v8; // rcx

  v3 = from + 2i64 * from + 1;
  v4 = *((_QWORD *)&this->Slots[0].Root.pPrev + v3);
  for ( i = &this->pCache + v3; (Scaleform::Render::MeshCache **)v4 != i; v4 = *(_QWORD *)(v4 + 8) )
    *(_DWORD *)(v4 + 24) = to;
  v6 = (char *)this + 24 * to;
  v7 = (Scaleform::Render::MeshCache **)i[1];
  if ( v7 != i )
  {
    v8 = *i;
    i[1] = (Scaleform::Render::MeshCache *)i;
    *i = (Scaleform::Render::MeshCache *)i;
    v8->Scaleform::Render::MeshCacheConfig::vfptr = (Scaleform::Render::MeshCacheConfigVtbl *)*((_QWORD *)v6 + 2);
    *v7 = (Scaleform::Render::MeshCache *)(v6 + 8);
    **((_QWORD **)v6 + 2) = v8;
    *((_QWORD *)v6 + 2) = v7;
  }
  *((_QWORD *)v6 + 3) += i[2];
  i[2] = 0i64;
}

// File Line: 401
// RVA: 0xA066D0
void __fastcall Scaleform::Render::MeshBuffer::~MeshBuffer(Scaleform::Render::MeshBuffer *this)
{
  this->vfptr = (Scaleform::Render::MeshBufferVtbl *)&Scaleform::Render::MeshBuffer::`vftable;
}

// File Line: 527
// RVA: 0x99B9C0
void __fastcall Scaleform::Render::MeshCache::MoveToCacheListFront(
        Scaleform::Render::MeshCache *this,
        Scaleform::Render::MeshCacheListType list,
        Scaleform::Render::MeshCacheItem *p)
{
  __int64 v4; // r8
  Scaleform::Render::MeshCacheListSet *pCacheList; // r9
  __int64 ListType; // rax
  Scaleform::Render::MeshCacheListSet *v7; // rdx
  char *v8; // r8

  v4 = list;
  if ( p )
  {
    pCacheList = p->pCacheList;
    p->pPrev->pNext = p->pNext;
    p->pNext->Scaleform::ListNode<Scaleform::Render::MeshCacheItem>::$A6A32721DD821860D2CFF437DFF6F231::pPrev = p->pPrev;
    ListType = p->ListType;
    p->pPrev = (Scaleform::Render::MeshCacheItem *)-1i64;
    p->pNext = (Scaleform::Render::MeshCacheItem *)-1i64;
    pCacheList->Slots[ListType].Size -= p->AllocSize;
    v7 = p->pCacheList;
    p->ListType = v4;
    v8 = (char *)v7 + 24 * v4;
    p->pNext = (Scaleform::Render::MeshCacheItem *)*((_QWORD *)v8 + 2);
    p->pPrev = (Scaleform::Render::MeshCacheItem *)(v8 + 8);
    **((_QWORD **)v8 + 2) = p;
    *((_QWORD *)v8 + 2) = p;
    *((_QWORD *)v8 + 3) += p->AllocSize;
  }
}

