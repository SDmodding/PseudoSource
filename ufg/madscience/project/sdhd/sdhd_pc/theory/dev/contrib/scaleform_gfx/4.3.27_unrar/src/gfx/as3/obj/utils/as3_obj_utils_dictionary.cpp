// File Line: 36
// RVA: 0x8CDBB0
void __fastcall Scaleform::GFx::AS3::ForEachChild_GC(Scaleform::GFx::AS3::RefCountCollector<328> *prcc, bool WeakKeys, Scaleform::HashLH<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor,2,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> > *v, void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  void (__fastcall *v4)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **); // r14
  Scaleform::HashLH<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor,2,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> > *v5; // r12
  bool v6; // r8
  Scaleform::GFx::AS3::RefCountCollector<328> *v7; // r13
  unsigned __int64 v8; // r15
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::TableType *v9; // rdx
  unsigned __int64 v10; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::TableType *v11; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> > *v12; // rsi
  __int64 v13; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::TableType *v14; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::TableType *v15; // rdx
  unsigned __int64 v16; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::TableType *v17; // rax
  signed __int64 v18; // r14
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::TableType *v19; // rdi
  int v20; // eax
  unsigned __int64 v21; // rdi
  __int64 v22; // rbx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v23; // rcx
  unsigned int v24; // eax
  Scaleform::GFx::Resource *v25; // rcx
  Scaleform::Render::RenderBuffer *v26; // rcx
  Scaleform::Render::RenderBuffer *v27; // rcx
  Scaleform::Render::RenderBuffer *v28; // rcx
  Scaleform::Render::RenderBuffer *v29; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::TableType *v30; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::TableType *v31; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> > *v32; // rsi
  __int64 v33; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::TableType *v34; // rax
  signed __int64 v35; // rdi
  Scaleform::GFx::AS3::Value *v36; // rdx
  Scaleform::GFx::AS3::Value *v37; // rdx
  unsigned __int64 v38; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::TableType *v39; // rcx
  int v40; // [rsp+20h] [rbp-40h]
  __int64 v41; // [rsp+28h] [rbp-38h]
  __int64 v42; // [rsp+30h] [rbp-30h]
  __int64 v43; // [rsp+38h] [rbp-28h]
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::Iterator v44; // [rsp+40h] [rbp-20h]
  __m128i v45; // [rsp+50h] [rbp-10h]
  bool v46; // [rsp+A8h] [rbp+48h]
  void (__fastcall *v47)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **); // [rsp+B8h] [rbp+58h]

  v47 = op;
  v46 = WeakKeys;
  v42 = -2i64;
  v4 = op;
  v5 = v;
  v6 = WeakKeys;
  v7 = prcc;
  v8 = 0i64;
  if ( WeakKeys && op == Scaleform::GFx::AS3::RefCountBaseGC<328>::MarkInCycleCall )
  {
LABEL_3:
    v9 = v5->mHash.pTable;
    if ( v5->mHash.pTable )
    {
      v10 = 0i64;
      v11 = v9 + 1;
      do
      {
        if ( v11->EntryCount != -2i64 )
          break;
        ++v10;
        v11 += 5;
      }
      while ( v10 <= v9->SizeMask );
      v45.m128i_i64[0] = (__int64)v5;
      v45.m128i_i64[1] = v10;
    }
    else
    {
      v45 = 0ui64;
    }
    _mm_store_si128((__m128i *)&v44, v45);
    v12 = v44.pHash;
    v13 = v44.Index;
    while ( v12 )
    {
      v14 = v12->pTable;
      if ( !v12->pTable || v13 > (signed __int64)v14->SizeMask )
        break;
      if ( !Scaleform::GFx::AS3::Value::IsValidWeakRef((Scaleform::GFx::AS3::Value *)&v14[5 * v13 + 2]) )
      {
        v18 = 5 * v13;
        v19 = v12->pTable;
        v20 = v12->pTable[5 * v13 + 4].EntryCount & 0x1F;
        if ( v20 <= 15 )
        {
          if ( (unsigned int)(v20 - 12) <= 3 )
          {
            v21 = v19[v18 + 5].EntryCount;
            goto LABEL_24;
          }
        }
        else
        {
          v21 = v19[v18 + 5].SizeMask;
LABEL_24:
          if ( v21 )
          {
            v41 = 0i64;
            v40 = 328;
            v22 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::HashLH<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor,2,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> > *, signed __int64, int *, _QWORD, _QWORD, __int64, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                    Scaleform::Memory::pGlobalHeap,
                    v5,
                    40i64,
                    &v40,
                    *(_QWORD *)&v40,
                    0i64,
                    v42,
                    v43);
            v43 = v22;
            if ( v22 )
            {
              *(_QWORD *)v22 = &Scaleform::RefCountImplCore::`vftable;
              *(_DWORD *)(v22 + 8) = 1;
              *(_QWORD *)v22 = &Scaleform::RefCountImpl::`vftable;
              *(_QWORD *)v22 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,328>::`vftable;
              *(_QWORD *)v22 = &Scaleform::RefCountBase<Scaleform::GFx::AS3::PtrReleaseProxy<328>,328>::`vftable;
              *(_QWORD *)v22 = &Scaleform::GFx::AS3::PtrReleaseProxy<328>::`vftable;
              *(_QWORD *)(v22 + 16) = 0i64;
              *(_QWORD *)(v22 + 24) = 0i64;
              *(_QWORD *)(v22 + 32) = 0i64;
            }
            else
            {
              v22 = 0i64;
            }
            v41 = v22;
            if ( v21 != *(_QWORD *)(v22 + 24) )
            {
              *(_DWORD *)(v21 + 32) = (*(_DWORD *)(v21 + 32) + 1) & 0x8FBFFFFF;
              v23 = *(Scaleform::GFx::AS3::RefCountBaseGC<328> **)(v22 + 24);
              if ( v23 )
              {
                if ( (unsigned __int8)v23 & 1 )
                {
                  *(_QWORD *)(v22 + 24) = (char *)v23 - 1;
                }
                else
                {
                  v24 = v23->RefCount;
                  if ( v24 & 0x3FFFFF )
                  {
                    v23->RefCount = v24 - 1;
                    Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v23);
                  }
                }
              }
              *(_QWORD *)(v22 + 24) = v21;
            }
            v25 = (Scaleform::GFx::Resource *)v7->HeadDelayedPtrRelease.pObject;
            if ( v25 )
            {
              Scaleform::Render::RenderBuffer::AddRef(v25);
              v28 = *(Scaleform::Render::RenderBuffer **)(v22 + 32);
              if ( v28 )
                Scaleform::RefCountImpl::Release(v28);
              *(_QWORD *)(v22 + 32) = v7->HeadDelayedPtrRelease.pObject;
              Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v22);
              v29 = (Scaleform::Render::RenderBuffer *)v7->HeadDelayedPtrRelease.pObject;
              if ( v29 )
                Scaleform::RefCountImpl::Release(v29);
              v7->HeadDelayedPtrRelease.pObject = (Scaleform::GFx::AS3::PtrReleaseProxy<328> *)v22;
            }
            else
            {
              Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v22);
              v26 = (Scaleform::Render::RenderBuffer *)v7->HeadDelayedPtrRelease.pObject;
              if ( v26 )
                Scaleform::RefCountImpl::Release(v26);
              v7->HeadDelayedPtrRelease.pObject = (Scaleform::GFx::AS3::PtrReleaseProxy<328> *)v22;
              v27 = *(Scaleform::Render::RenderBuffer **)(v22 + 32);
              if ( v27 )
                Scaleform::RefCountImpl::Release(v27);
              *(_QWORD *)(v22 + 32) = 0i64;
            }
            Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v22);
          }
        }
        Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF>>::Iterator::RemoveAlt<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>>(
          &v44,
          (Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor> *)&v12->pTable[v18 + 2]);
        goto LABEL_3;
      }
      v15 = v12->pTable;
      v16 = v12->pTable->SizeMask;
      if ( v13 <= (signed __int64)v16 )
      {
        v44.Index = ++v13;
        if ( v13 <= v16 )
        {
          v17 = &v15[5 * v13 + 1];
          do
          {
            if ( v17->EntryCount != -2i64 )
              break;
            v44.Index = ++v13;
            v17 += 5;
          }
          while ( v13 <= v16 );
        }
      }
    }
    v4 = v47;
    v6 = v46;
  }
  v30 = v5->mHash.pTable;
  if ( v5->mHash.pTable )
  {
    v31 = v30 + 1;
    do
    {
      if ( v31->EntryCount != -2i64 )
        break;
      ++v8;
      v31 += 5;
    }
    while ( v8 <= v30->SizeMask );
    v45.m128i_i64[0] = (__int64)v5;
  }
  else
  {
    v45.m128i_i64[0] = 0i64;
  }
  v45.m128i_i64[1] = v8;
  _mm_store_si128((__m128i *)&v44, v45);
  v32 = v44.pHash;
  v33 = v44.Index;
  while ( v32 )
  {
    v34 = v32->pTable;
    if ( !v32->pTable || v33 > (signed __int64)v34->SizeMask )
      break;
    if ( !v6
      || (v35 = 5 * v33, Scaleform::GFx::AS3::Value::IsValidWeakRef((Scaleform::GFx::AS3::Value *)&v34[5 * v33 + 2])) )
    {
      v35 = 5 * v33;
      v36 = (Scaleform::GFx::AS3::Value *)&v32->pTable[5 * v33 + 2];
      if ( (v36->Flags & 0x1F) > 10 && !((v36->Flags >> 9) & 1) )
        Scaleform::GFx::AS3::ForEachChild_GC_Internal(v7, v36, v4);
    }
    v37 = (Scaleform::GFx::AS3::Value *)&v32->pTable[v35 + 4];
    if ( (v37->Flags & 0x1F) > 10 && !((v37->Flags >> 9) & 1) )
      Scaleform::GFx::AS3::ForEachChild_GC_Internal(v7, v37, v4);
    v38 = v32->pTable->SizeMask;
    v6 = v46;
    if ( v33 <= (signed __int64)v38 && ++v33 <= v38 )
    {
      v39 = &v32->pTable[5 * v33 + 1];
      do
      {
        v6 = v46;
        if ( v39->EntryCount != -2i64 )
          break;
        ++v33;
        v39 += 5;
      }
      while ( v33 <= v38 );
    }
  }
}

// File Line: 171
// RVA: 0x8CC250
Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::Iterator *__fastcall Scaleform::GFx::AS3::Instances::fl_utils::Dictionary::FindKey(Scaleform::GFx::AS3::Instances::fl_utils::Dictionary *this, Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::Iterator *result, Scaleform::GFx::AS3::Multiname *prop_name)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::Iterator *v3; // rbx
  Scaleform::GFx::AS3::Instances::fl_utils::Dictionary *v4; // rdi
  Scaleform::GFx::AS3::Value *v5; // rsi
  signed int v6; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> > *v7; // rdi
  signed __int64 v8; // rax
  signed __int64 v9; // rax
  bool v10; // zf
  Scaleform::GFx::AS3::Value *v11; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> > *v12; // rdi
  signed __int64 v13; // rax
  signed __int64 v14; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> > *v15; // rdi
  signed __int64 v16; // rax
  signed __int64 v17; // rax
  long double v19; // [rsp+20h] [rbp-50h]
  __int64 v20; // [rsp+28h] [rbp-48h]
  Scaleform::GFx::AS3::Value v; // [rsp+30h] [rbp-40h]
  Scaleform::GFx::AS3::Value key; // [rsp+50h] [rbp-20h]
  char v23; // [rsp+A8h] [rbp+38h]
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+B0h] [rbp+40h]
  Scaleform::GFx::AS3::CheckResult v25; // [rsp+B8h] [rbp+48h]

  v20 = -2i64;
  v3 = result;
  v4 = this;
  v5 = &prop_name->Name;
  result->pHash = 0i64;
  result->Index = 0i64;
  v6 = prop_name->Name.Flags & 0x1F;
  if ( v6 < 2 )
    goto LABEL_19;
  if ( v6 > 3 )
  {
    if ( v6 == 10 && Scaleform::GFx::AS3::GetStrNumber(&resulta, prop_name->Name.value.VS._1.VStr, &v19)->Result )
    {
      v.Flags = 4;
      v.Bonus.pWeakProxy = 0i64;
      v.value.VNumber = v19;
      v7 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> > *)&v4->ValueH.mHash.pTable;
      if ( !v7->pTable
        || (v23 = 0,
            v8 = Scaleform::GFx::AS3::Value::HashFunctor::operator()(
                   (Scaleform::GFx::AS3::Value::HashFunctor *)&v23,
                   &v),
            v9 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::AS3::Value>(
                   v7,
                   &v,
                   v8 & v7->pTable->SizeMask),
            v9 < 0) )
      {
        v7 = 0i64;
        v9 = 0i64;
      }
      v3->pHash = v7;
      v3->Index = v9;
      if ( (v.Flags & 0x1F) > 9 )
      {
        v10 = ((v.Flags >> 9) & 1) == 0;
        v11 = &v;
        goto LABEL_10;
      }
      return v3;
    }
LABEL_19:
    v15 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> > *)&v4->ValueH.mHash.pTable;
    if ( !v15->pTable
      || (v23 = 0,
          v16 = Scaleform::GFx::AS3::Value::HashFunctor::operator()((Scaleform::GFx::AS3::Value::HashFunctor *)&v23, v5),
          v17 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::AS3::Value>(
                  v15,
                  v5,
                  v16 & v15->pTable->SizeMask),
          v17 < 0) )
    {
      v15 = 0i64;
      v17 = 0i64;
    }
    v3->pHash = v15;
    v3->Index = v17;
    return v3;
  }
  if ( Scaleform::GFx::AS3::Value::Convert2Number(v5, &v25, &v19)->Result )
  {
    key.Flags = 4;
    key.Bonus.pWeakProxy = 0i64;
    key.value.VNumber = v19;
    v12 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> > *)&v4->ValueH.mHash.pTable;
    if ( !v12->pTable
      || (v23 = 0,
          v13 = Scaleform::GFx::AS3::Value::HashFunctor::operator()(
                  (Scaleform::GFx::AS3::Value::HashFunctor *)&v23,
                  &key),
          v14 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::AS3::Value>(
                  v12,
                  &key,
                  v13 & v12->pTable->SizeMask),
          v14 < 0) )
    {
      v12 = 0i64;
      v14 = 0i64;
    }
    v3->pHash = v12;
    v3->Index = v14;
    if ( (key.Flags & 0x1F) > 9 )
    {
      v10 = ((key.Flags >> 9) & 1) == 0;
      v11 = &key;
LABEL_10:
      if ( v10 )
        Scaleform::GFx::AS3::Value::ReleaseInternal(v11);
      else
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(v11);
      return v3;
    }
  }
  return v3;
});
      else
        Scaleform::GFx::AS3::Value::ReleaseWeakR

// File Line: 198
// RVA: 0x8B0A70
void __fastcall Scaleform::GFx::AS3::Instances::fl_utils::Dictionary::AddDynamicSlotValuePair(Scaleform::GFx::AS3::Instances::fl_utils::Dictionary *this, Scaleform::GFx::AS3::Value *prop_name, Scaleform::GFx::AS3::Value *value, Scaleform::GFx::AS3::SlotInfo::Attribute a)
{
  Scaleform::GFx::AS3::Value *v4; // r12
  Scaleform::GFx::AS3::Instances::fl_utils::Dictionary *v5; // r15
  unsigned int v6; // er9
  int v7; // eax
  long double v8; // xmm6_8
  unsigned int v9; // ecx
  signed __int64 v10; // rsi
  signed __int64 v11; // r14
  __int64 v12; // rbx
  signed __int64 v13; // rdi
  __int64 v14; // rax
  signed __int64 v15; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::Iterator v16; // [rsp+28h] [rbp-48h]
  Scaleform::GFx::AS3::Value v; // [rsp+38h] [rbp-38h]
  Scaleform::GFx::AS3::CheckResult result; // [rsp+A0h] [rbp+30h]
  long double v19; // [rsp+A8h] [rbp+38h]

  v4 = value;
  v5 = this;
  v6 = prop_name->Flags;
  v.Flags = v6;
  v.Bonus.pWeakProxy = prop_name->Bonus.pWeakProxy;
  v.value = prop_name->value;
  if ( (char)(v6 & 0x1F) > 9 )
  {
    if ( (v6 >> 9) & 1 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(prop_name);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(prop_name);
  }
  v7 = v.Flags & 0x1F;
  if ( v7 == 10 )
  {
    if ( Scaleform::GFx::AS3::GetStrNumber(&result, v.value.VS._1.VStr, &v19)->Result )
    {
      v8 = v19;
      v9 = v.Flags;
      if ( (v.Flags & 0x1F) > 9 )
      {
        if ( (v.Flags >> 9) & 1 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
        v9 = v.Flags;
      }
      v.Flags = v9 & 0xFFFFFFE4 | 4;
      v.value.VNumber = v8;
      v.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v16.Index;
    }
  }
  else if ( (unsigned int)(v7 - 2) <= 1 )
  {
    Scaleform::GFx::AS3::Value::ToNumberValue(&v, &result);
  }
  v10 = (signed __int64)&v5->ValueH;
  if ( v5->ValueH.mHash.pTable )
  {
    result.Result = 0;
    v11 = Scaleform::GFx::AS3::Value::HashFunctor::operator()((Scaleform::GFx::AS3::Value::HashFunctor *)&result, &v) & *(_QWORD *)(*(_QWORD *)v10 + 8i64);
    v12 = v11;
    v13 = 80 * v11 + *(_QWORD *)v10 + 16i64;
    if ( *(_QWORD *)v13 != -2i64 && *(_QWORD *)(v13 + 8) == v11 )
    {
      while ( *(_QWORD *)(v13 + 8) != v11
           || !Scaleform::GFx::AS3::StrictEqual((Scaleform::GFx::AS3::Value *)(v13 + 16), &v) )
      {
        v12 = *(_QWORD *)v13;
        if ( *(_QWORD *)v13 == -1i64 )
          goto LABEL_30;
        v13 = 80 * v12 + *(_QWORD *)v10 + 16i64;
      }
      if ( v12 >= 0 )
      {
        v16.pHash = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> > *)&v5->ValueH.mHash.pTable;
        v16.Index = v12;
        if ( v5 != (Scaleform::GFx::AS3::Instances::fl_utils::Dictionary *)-64i64 )
        {
          v14 = *(_QWORD *)v10;
          if ( *(_QWORD *)v10 )
          {
            if ( v12 <= *(_QWORD *)(v14 + 8) )
            {
              if ( !v5->WeakKeys
                || Scaleform::GFx::AS3::Value::IsValidWeakRef((Scaleform::GFx::AS3::Value *)(80 * v12 + v14 + 32)) )
              {
                Scaleform::GFx::AS3::Value::Assign(
                  (Scaleform::GFx::AS3::Value *)(*(_QWORD *)v10 + 64i64 + 80 * v12),
                  v4);
                goto LABEL_33;
              }
              Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF>>::Iterator::RemoveAlt<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>>(
                &v16,
                (Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor> *)(80 * v12 + *(_QWORD *)v10 + 32i64));
            }
          }
        }
      }
    }
  }
LABEL_30:
  if ( v5->WeakKeys )
    Scaleform::GFx::AS3::Value::MakeWeakRef(&v);
  v16.pHash = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> > *)&v;
  v16.Index = (__int64)v4;
  result.Result = 0;
  v15 = Scaleform::GFx::AS3::Value::HashFunctor::operator()((Scaleform::GFx::AS3::Value::HashFunctor *)&result, &v);
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeRef>(
    (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> > *)&v5->ValueH.mHash.pTable,
    &v5->ValueH,
    (Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeRef *)&v16,
    v15);
LABEL_33:
  if ( (v.Flags & 0x1F) > 9 )
  {
    if ( (v.Flags >> 9) & 1 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
  }
}

// File Line: 274
// RVA: 0x8CB9A0
Scaleform::GFx::AS3::PropRef *__fastcall Scaleform::GFx::AS3::Instances::fl_utils::Dictionary::FindDynamicSlot(Scaleform::GFx::AS3::Instances::fl_utils::Dictionary *this, Scaleform::GFx::AS3::PropRef *result, Scaleform::GFx::AS3::Multiname *prop_name)
{
  Scaleform::GFx::AS3::Multiname *v3; // rdi
  Scaleform::GFx::AS3::PropRef *v4; // rbx
  Scaleform::GFx::AS3::Instances::fl_utils::Dictionary *v5; // rbp
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> > *v6; // rdi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::TableType *v7; // rax
  __int64 v8; // rsi
  __int64 v9; // r14
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::Iterator resulta; // [rsp+30h] [rbp-28h]

  v3 = prop_name;
  v4 = result;
  v5 = this;
  if ( !Scaleform::GFx::AS3::Multiname::ContainsNamespace(
          prop_name,
          this->pTraits.pObject->pVM->PublicNamespace.pObject) )
    goto LABEL_9;
  Scaleform::GFx::AS3::Instances::fl_utils::Dictionary::FindKey(v5, &resulta, v3);
  v6 = resulta.pHash;
  if ( !resulta.pHash )
    goto LABEL_9;
  v7 = resulta.pHash->pTable;
  if ( !resulta.pHash->pTable )
    goto LABEL_9;
  v8 = resulta.Index;
  if ( resulta.Index > (signed __int64)v7->SizeMask )
    goto LABEL_9;
  if ( v5->WeakKeys )
  {
    v9 = 5 * resulta.Index;
    if ( !Scaleform::GFx::AS3::Value::IsValidWeakRef((Scaleform::GFx::AS3::Value *)&v7[5 * resulta.Index + 2]) )
    {
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF>>::Iterator::RemoveAlt<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>>(
        &resulta,
        (Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor> *)&v6->pTable[v9 + 2]);
LABEL_9:
      v4->pSI = 0i64;
      v4->SlotIndex = 0i64;
      v4->This.Flags = 0;
      v4->This.Bonus.pWeakProxy = 0i64;
      return v4;
    }
  }
  v4->pSI = (Scaleform::GFx::AS3::SlotInfo *)((_QWORD)&v6->pTable[5 * v8 + 4] | 1);
  Scaleform::GFx::AS3::Value::Value(&v4->This, (Scaleform::GFx::AS3::Object *)&v5->vfptr);
  return v4;
}

// File Line: 293
// RVA: 0x90A1F0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl_utils::Dictionary::SetProperty(Scaleform::GFx::AS3::Instances::fl_utils::Dictionary *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::Multiname *prop_name, Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::CheckResult *v4; // rbx

  v4 = result;
  ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl_utils::Dictionary *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *, _QWORD))this->vfptr[4].Finalize_GC)(
    this,
    &prop_name->Name,
    value,
    0i64);
  v4->Result = 1;
  return v4;
}

// File Line: 299
// RVA: 0x8DC710
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl_utils::Dictionary::GetProperty(Scaleform::GFx::AS3::Instances::fl_utils::Dictionary *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::Multiname *prop_name, Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::CheckResult *v4; // r14
  Scaleform::GFx::AS3::Instances::fl_utils::Dictionary *v5; // rsi
  Scaleform::GFx::AS3::Value *v6; // r15
  Scaleform::GFx::AS3::Multiname *v7; // rbx
  char v8; // bp
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> > *v9; // rdi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::TableType *v10; // rax
  __int64 v11; // rbx
  __int64 v12; // rsi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::Iterator resulta; // [rsp+20h] [rbp-28h]

  v4 = result;
  v5 = this;
  v6 = value;
  v7 = prop_name;
  v8 = 0;
  if ( Scaleform::GFx::AS3::Multiname::ContainsNamespace(prop_name, this->pTraits.pObject->pVM->PublicNamespace.pObject) )
  {
    Scaleform::GFx::AS3::Instances::fl_utils::Dictionary::FindKey(v5, &resulta, v7);
    v9 = resulta.pHash;
    if ( resulta.pHash )
    {
      v10 = resulta.pHash->pTable;
      if ( resulta.pHash->pTable )
      {
        v11 = resulta.Index;
        if ( resulta.Index <= (signed __int64)v10->SizeMask )
        {
          if ( !v5->WeakKeys
            || (v12 = 5 * resulta.Index,
                Scaleform::GFx::AS3::Value::IsValidWeakRef((Scaleform::GFx::AS3::Value *)&v10[5 * resulta.Index + 2])) )
          {
            Scaleform::GFx::AS3::Value::Assign(v6, (Scaleform::GFx::AS3::Value *)&v9->pTable[5 * v11 + 4]);
            v8 = 1;
          }
          else
          {
            Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF>>::Iterator::RemoveAlt<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>>(
              &resulta,
              (Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor> *)&v9->pTable[v12 + 2]);
          }
        }
      }
    }
  }
  v4->Result = v8;
  return v4;
}

// File Line: 322
// RVA: 0x8D7300
void __fastcall Scaleform::GFx::AS3::Instances::fl_utils::Dictionary::GetDynamicProperty(Scaleform::GFx::AS3::Instances::fl_utils::Dictionary *this, Scaleform::GFx::AS3::AbsoluteIndex ind, Scaleform::GFx::AS3::Value *value)
{
  Scaleform::HashLH<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor,2,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> > *v3; // r9
  Scaleform::HashLH<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor,2,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> > *v4; // rax
  Scaleform::GFx::AS3::Value *v5; // r10
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::TableType *v6; // rcx
  unsigned __int64 v7; // r8
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::TableType *v8; // rcx

  v3 = &this->ValueH;
  v4 = 0i64;
  v5 = value;
  v6 = this->ValueH.mHash.pTable;
  if ( v6 )
  {
    v7 = v6->SizeMask;
    v8 = v6 + 1;
    do
    {
      if ( v8->EntryCount != -2i64 )
        break;
      v4 = (Scaleform::HashLH<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor,2,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> > *)((char *)v4 + 1);
      v8 += 5;
    }
    while ( (unsigned __int64)v4 <= v7 );
    v4 = v3;
  }
  Scaleform::GFx::AS3::Value::Assign(v5, (Scaleform::GFx::AS3::Value *)&v4->mHash.pTable[5 * LODWORD(ind.Index) + 4]);
}

// File Line: 330
// RVA: 0x8C5180
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl_utils::Dictionary::DeleteProperty(Scaleform::GFx::AS3::Instances::fl_utils::Dictionary *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::Multiname *prop_name)
{
  Scaleform::GFx::AS3::CheckResult *v3; // rbx
  Scaleform::GFx::AS3::Instances::fl_utils::Dictionary *v4; // rbp
  Scaleform::GFx::AS3::Multiname *v5; // rsi
  char v6; // di
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::TableType *v7; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::Iterator resulta; // [rsp+20h] [rbp-18h]

  v3 = result;
  v4 = this;
  v5 = prop_name;
  v6 = 0;
  if ( Scaleform::GFx::AS3::Multiname::ContainsNamespace(prop_name, this->pTraits.pObject->pVM->PublicNamespace.pObject) )
  {
    Scaleform::GFx::AS3::Instances::fl_utils::Dictionary::FindKey(v4, &resulta, v5);
    if ( resulta.pHash )
    {
      v7 = resulta.pHash->pTable;
      if ( resulta.pHash->pTable )
      {
        if ( resulta.Index <= (signed __int64)v7->SizeMask )
        {
          Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF>>::Iterator::RemoveAlt<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>>(
            &resulta,
            (Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor> *)&v7[5 * resulta.Index + 2]);
          v6 = 1;
        }
      }
    }
  }
  v3->Result = v6;
  return v3;
}

// File Line: 348
// RVA: 0x8CE090
void __fastcall Scaleform::GFx::AS3::Instances::fl_utils::Dictionary::ForEachChild_GC(Scaleform::GFx::AS3::Instances::fl_utils::Dictionary *this, Scaleform::GFx::AS3::RefCountCollector<328> *prcc, void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  void (__fastcall *v3)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **); // rdi
  Scaleform::GFx::AS3::RefCountCollector<328> *v4; // rsi
  Scaleform::GFx::AS3::Instances::fl_utils::Dictionary *v5; // rbx

  v3 = op;
  v4 = prcc;
  v5 = this;
  Scaleform::GFx::AS3::Object::ForEachChild_GC((Scaleform::GFx::AS3::Object *)&this->vfptr, prcc, op);
  Scaleform::GFx::AS3::ForEachChild_GC(v4, v5->WeakKeys, &v5->ValueH, v3);
}

// File Line: 355
// RVA: 0x8DBB00
void __fastcall Scaleform::GFx::AS3::Instances::fl_utils::Dictionary::GetNextPropertyName(Scaleform::GFx::AS3::Instances::fl_utils::Dictionary *this, Scaleform::GFx::AS3::Value *name, Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
  Scaleform::GFx::AS3::Instances::fl_utils::Dictionary *v3; // rdi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::TableType *v4; // rcx
  Scaleform::HashLH<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor,2,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> > *v5; // rax
  Scaleform::GFx::AS3::Value *v6; // rbx
  unsigned __int64 v7; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::TableType *v8; // rcx

  if ( ind.Index )
  {
    v3 = this;
    v4 = this->ValueH.mHash.pTable;
    v5 = 0i64;
    v6 = name;
    if ( v4 )
    {
      v7 = v4->SizeMask;
      v8 = v4 + 1;
      do
      {
        if ( v8->EntryCount != -2i64 )
          break;
        v5 = (Scaleform::HashLH<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor,2,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> > *)((char *)v5 + 1);
        v8 += 5;
      }
      while ( (unsigned __int64)v5 <= v7 );
      v5 = &v3->ValueH;
    }
    Scaleform::GFx::AS3::Value::Assign(v6, (Scaleform::GFx::AS3::Value *)&v5->mHash.pTable[5 * (ind.Index - 1) + 2]);
    if ( v3->WeakKeys )
      Scaleform::GFx::AS3::Value::MakeStrongRef(v6);
  }
}

// File Line: 371
// RVA: 0x8DB720
Scaleform::GFx::AS3::GlobalSlotIndex *__fastcall Scaleform::GFx::AS3::Instances::fl_utils::Dictionary::GetNextDynPropIndex(Scaleform::GFx::AS3::Instances::fl_utils::Dictionary *this, Scaleform::GFx::AS3::GlobalSlotIndex *result, Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::TableType *v3; // rax
  Scaleform::HashLH<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor,2,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> > *v4; // rdi
  Scaleform::GFx::AS3::GlobalSlotIndex *v5; // rsi
  Scaleform::GFx::AS3::Instances::fl_utils::Dictionary *v6; // rbp
  unsigned __int64 v7; // rdx
  unsigned __int64 v8; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::TableType *v9; // rax
  signed __int64 v10; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::TableType *v11; // r8
  unsigned __int64 v12; // rdx
  unsigned __int64 v13; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::TableType *v14; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::TableType *v15; // rcx

  v3 = this->ValueH.mHash.pTable;
  v4 = &this->ValueH;
  v5 = result;
  v6 = this;
  if ( v3 )
  {
    v7 = v3->SizeMask;
    v8 = 0i64;
    v9 = v3 + 1;
    do
    {
      if ( v9->EntryCount != -2i64 )
        break;
      ++v8;
      v9 += 5;
    }
    while ( v8 <= v7 );
  }
  else
  {
    v4 = 0i64;
  }
  if ( ind.Index )
    v10 = ind.Index - 1;
  else
    v10 = -1i64;
  if ( v4 )
  {
    v11 = v4->mHash.pTable;
    if ( v4->mHash.pTable )
    {
      v12 = v11->SizeMask;
      if ( v10 <= (signed __int64)v12 )
      {
        v13 = v10 + 1;
        if ( v13 <= v12 )
        {
          v14 = &v11[5 * v13 + 1];
          do
          {
            if ( v14->EntryCount != -2i64 )
              break;
            ++v13;
            v14 += 5;
          }
          while ( v13 <= v12 );
        }
        while ( v11 && (signed __int64)v13 <= (signed __int64)v12 )
        {
          if ( !v6->WeakKeys
            || Scaleform::GFx::AS3::Value::IsValidWeakRef((Scaleform::GFx::AS3::Value *)&v11[5 * v13 + 2]) )
          {
            v5->Index = v13 + 1;
            return v5;
          }
          v11 = v4->mHash.pTable;
          v12 = v4->mHash.pTable->SizeMask;
          if ( (signed __int64)v13 <= (signed __int64)v12 && ++v13 <= v12 )
          {
            v15 = &v11[5 * v13 + 1];
            do
            {
              if ( v15->EntryCount != -2i64 )
                break;
              ++v13;
              v15 += 5;
            }
            while ( v13 <= v12 );
          }
        }
      }
    }
  }
  v5->Index = 0;
  return v5;
}

// File Line: 388
// RVA: 0x8AE990
void __fastcall Scaleform::GFx::AS3::Instances::fl_utils::Dictionary::AS3Constructor(Scaleform::GFx::AS3::Instances::fl_utils::Dictionary *this, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Instances::fl_utils::Dictionary *v3; // rbx

  if ( argc )
  {
    v3 = this;
    if ( (unsigned __int8)Scaleform::GFx::AS3::Value::Convert2Boolean(argv) )
      v3->WeakKeys = 1;
  }
}

// File Line: 413
// RVA: 0x8EADC0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_utils::Dictionary::MakeObject(Scaleform::GFx::AS3::InstanceTraits::fl_utils::Dictionary *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::Object **v4; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_utils::Dictionary> resulta; // [rsp+48h] [rbp+20h]

  v3 = result;
  v4 = (Scaleform::GFx::AS3::Object **)Scaleform::GFx::AS3::InstanceTraits::fl_utils::Dictionary::MakeInstance(
                                         &resulta,
                                         (Scaleform::GFx::AS3::InstanceTraits::fl_utils::Dictionary *)t);
  Scaleform::GFx::AS3::Value::Pick(v3, *v4);
}

// File Line: 436
// RVA: 0x877520
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_utils::Dictionary::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // rbp
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v3; // rdi
  Scaleform::MemoryHeap *v4; // rsi
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v6; // rbx
  Scaleform::GFx::AS3::InstanceTraits::fl::Object *v7; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> v8; // rbx
  Scaleform::GFx::AS3::Class *v9; // rax

  v2 = vm;
  v3 = result;
  v4 = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::fl::Object *)v4->vfptr->Alloc(v4, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::Object::Object(v5, v2, &Scaleform::GFx::AS3::fl_utils::DictionaryCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_utils::Dictionary::`vftable;
    v6->TraitsType = 11;
  }
  else
  {
    v6 = 0i64;
  }
  v3->pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)&v6->vfptr;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::fl::Object *)v4->vfptr->Alloc(v4, 240ui64, 0i64);
  v8.pV = (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v7->vfptr;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::fl::Object::Object(v7, v2, &Scaleform::GFx::AS3::fl_utils::DictionaryCI);
    v8.pV->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_utils::Dictionary::`vftable;
    v8.pV->Flags |= 1ui64;
    v8.pV->TraitsType = 11;
  }
  else
  {
    v8.pV = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(v3->pV, v8);
  v9 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v4->vfptr->Alloc)(
                                       v4,
                                       72i64);
  if ( v9 )
    Scaleform::GFx::AS3::Class::Class(v9, v3->pV);
  return v3;
}

