// File Line: 252
// RVA: 0x9A33D0
void __fastcall Scaleform::Render::MeshCacheListSet::PushListToFront(Scaleform::Render::MeshCacheListSet *this, Scaleform::Render::MeshCacheListType to, Scaleform::Render::MeshCacheListType from)
{
  signed __int64 v3; // r9
  __int64 v4; // rax
  Scaleform::Render::MeshCache **i; // r9
  char *v6; // rdx
  Scaleform::Render::MeshCache **v7; // r10
  Scaleform::Render::MeshCache *v8; // rcx

  v3 = (signed int)from + 2i64 * (signed int)from + 1;
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
    v8->vfptr = (Scaleform::Render::MeshCacheConfigVtbl *)*((_QWORD *)v6 + 2);
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
  this->vfptr = (Scaleform::Render::MeshBufferVtbl *)&Scaleform::Render::MeshBuffer::`vftable';
}

// File Line: 527
// RVA: 0x99B9C0
void __fastcall Scaleform::Render::MeshCache::MoveToCacheListFront(Scaleform::Render::MeshCache *this, Scaleform::Render::MeshCacheListType list, Scaleform::Render::MeshCacheItem *p)
{
  Scaleform::Render::MeshCacheItem *v3; // r10
  __int64 v4; // r8
  Scaleform::Render::MeshCacheListSet *v5; // r9
  __int64 v6; // rax
  Scaleform::Render::MeshCacheListSet *v7; // rdx
  signed __int64 v8; // r8

  v3 = p;
  v4 = list;
  if ( v3 )
  {
    v5 = v3->pCacheList;
    v3->pPrev->pNext = v3->pNext;
    v3->pNext->pPrev = v3->pPrev;
    v6 = v3->ListType;
    v3->pPrev = (Scaleform::Render::MeshCacheItem *)-1i64;
    v3->pNext = (Scaleform::Render::MeshCacheItem *)-1i64;
    *((_QWORD *)&v5->pCache + 3 * (v6 + 1)) -= v3->AllocSize;
    v7 = v3->pCacheList;
    v3->ListType = v4;
    v8 = (signed __int64)v7 + 24 * v4;
    v3->pNext = *(Scaleform::Render::MeshCacheItem **)(v8 + 16);
    v3->pPrev = (Scaleform::Render::MeshCacheItem *)(v8 + 8);
    **(_QWORD **)(v8 + 16) = v3;
    *(_QWORD *)(v8 + 16) = v3;
    *(_QWORD *)(v8 + 24) += v3->AllocSize;
  }
}

