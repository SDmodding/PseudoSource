// File Line: 36
// RVA: 0x8CDBB0
void __fastcall Scaleform::GFx::AS3::ForEachChild_GC(
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        bool WeakKeys,
        Scaleform::HashLH<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor,2,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> > *v,
        void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::Value::V2U *, void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **), Scaleform::GFx::AS3::RefCountCollector<328> *))
{
  void (__fastcall *v4)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::Value::V2U *, void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **), Scaleform::GFx::AS3::RefCountCollector<328> *); // r14
  bool v6; // r8
  unsigned __int64 v8; // r15
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::TableType *pTable; // rdx
  unsigned __int64 v10; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::TableType *v11; // rcx
  __int64 Index; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> > *pHash; // rsi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::TableType *v14; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::TableType *v15; // rdx
  unsigned __int64 SizeMask; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::TableType *v17; // rax
  __int64 v18; // r14
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::TableType *v19; // rdi
  unsigned __int64 EntryCount; // rdi
  Scaleform::GFx::Resource *v21; // rbx
  Scaleform::GFx::ResourceVtbl *vfptr; // rcx
  unsigned int vecDelDtor; // eax
  Scaleform::GFx::Resource *pObject; // rcx
  Scaleform::Render::RenderBuffer *v25; // rcx
  Scaleform::Render::RenderBuffer *v26; // rcx
  Scaleform::Render::RenderBuffer *v27; // rcx
  Scaleform::Render::RenderBuffer *v28; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::TableType *v29; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::TableType *v30; // rax
  signed __int64 v31; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> > *v32; // rsi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::TableType *v33; // rax
  __int64 v34; // rdi
  Scaleform::GFx::AS3::Value *v35; // rdx
  Scaleform::GFx::AS3::Value *v36; // rdx
  unsigned __int64 v37; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::TableType *v38; // rcx
  int v39; // [rsp+20h] [rbp-40h] BYREF
  Scaleform::GFx::Resource *v40; // [rsp+28h] [rbp-38h]
  __int64 v41; // [rsp+30h] [rbp-30h]
  Scaleform::GFx::Resource *v42; // [rsp+38h] [rbp-28h]
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::Iterator v43; // [rsp+40h] [rbp-20h] BYREF
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::Iterator v44; // [rsp+50h] [rbp-10h]

  v41 = -2i64;
  v4 = op;
  v6 = WeakKeys;
  v8 = 0i64;
  if ( WeakKeys && (char *)op == (char *)Scaleform::GFx::AS3::RefCountBaseGC<328>::MarkInCycleCall )
  {
LABEL_3:
    pTable = v->mHash.pTable;
    if ( v->mHash.pTable )
    {
      v10 = 0i64;
      v11 = pTable + 1;
      do
      {
        if ( v11->EntryCount != -2i64 )
          break;
        ++v10;
        v11 += 5;
      }
      while ( v10 <= pTable->SizeMask );
      v44.pHash = &v->mHash;
      v44.Index = v10;
    }
    else
    {
      v44 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::Iterator)0i64;
    }
    v43 = v44;
    Index = v44.Index;
    pHash = v44.pHash;
    while ( pHash )
    {
      v14 = pHash->pTable;
      if ( !pHash->pTable || Index > (signed __int64)v14->SizeMask )
        break;
      if ( !Scaleform::GFx::AS3::Value::IsValidWeakRef((Scaleform::GFx::AS3::Value *)&v14[5 * Index + 2]) )
      {
        v18 = 5 * Index;
        v19 = pHash->pTable;
        if ( (pHash->pTable[5 * Index + 4].EntryCount & 0x1F) <= 0xF )
        {
          if ( (pHash->pTable[5 * Index + 4].EntryCount & 0x1F) - 12 <= 3 )
          {
            EntryCount = v19[v18 + 5].EntryCount;
            goto LABEL_24;
          }
        }
        else
        {
          EntryCount = v19[v18 + 5].SizeMask;
LABEL_24:
          if ( EntryCount )
          {
            v40 = 0i64;
            v39 = 328;
            v21 = (Scaleform::GFx::Resource *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                Scaleform::Memory::pGlobalHeap,
                                                v,
                                                40i64,
                                                &v39);
            v42 = v21;
            if ( v21 )
            {
              v21->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::RefCountImplCore::`vftable;
              v21->RefCount.Value = 1;
              v21->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::RefCountImpl::`vftable;
              v21->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,328>::`vftable;
              v21->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::AS3::PtrReleaseProxy<328>,328>::`vftable;
              v21->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::AS3::PtrReleaseProxy<328>::`vftable;
              v21->pLib = 0i64;
              v21[1].vfptr = 0i64;
              *(_QWORD *)&v21[1].RefCount.Value = 0i64;
            }
            else
            {
              v21 = 0i64;
            }
            v40 = v21;
            if ( (Scaleform::GFx::ResourceVtbl *)EntryCount != v21[1].vfptr )
            {
              *(_DWORD *)(EntryCount + 32) = (*(_DWORD *)(EntryCount + 32) + 1) & 0x8FBFFFFF;
              vfptr = v21[1].vfptr;
              if ( vfptr )
              {
                if ( ((unsigned __int8)vfptr & 1) != 0 )
                {
                  v21[1].vfptr = (Scaleform::GFx::ResourceVtbl *)((char *)vfptr - 1);
                }
                else
                {
                  vecDelDtor = (unsigned int)vfptr[1].__vecDelDtor;
                  if ( (vecDelDtor & 0x3FFFFF) != 0 )
                  {
                    LODWORD(vfptr[1].__vecDelDtor) = vecDelDtor - 1;
                    Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)vfptr);
                  }
                }
              }
              v21[1].vfptr = (Scaleform::GFx::ResourceVtbl *)EntryCount;
            }
            pObject = (Scaleform::GFx::Resource *)prcc->HeadDelayedPtrRelease.pObject;
            if ( pObject )
            {
              Scaleform::Render::RenderBuffer::AddRef(pObject);
              v27 = *(Scaleform::Render::RenderBuffer **)&v21[1].RefCount.Value;
              if ( v27 )
                Scaleform::RefCountImpl::Release(v27);
              *(_QWORD *)&v21[1].RefCount.Value = prcc->HeadDelayedPtrRelease.pObject;
              Scaleform::Render::RenderBuffer::AddRef(v21);
              v28 = (Scaleform::Render::RenderBuffer *)prcc->HeadDelayedPtrRelease.pObject;
              if ( v28 )
                Scaleform::RefCountImpl::Release(v28);
              prcc->HeadDelayedPtrRelease.pObject = (Scaleform::GFx::AS3::PtrReleaseProxy<328> *)v21;
            }
            else
            {
              Scaleform::Render::RenderBuffer::AddRef(v21);
              v25 = (Scaleform::Render::RenderBuffer *)prcc->HeadDelayedPtrRelease.pObject;
              if ( v25 )
                Scaleform::RefCountImpl::Release(v25);
              prcc->HeadDelayedPtrRelease.pObject = (Scaleform::GFx::AS3::PtrReleaseProxy<328> *)v21;
              v26 = *(Scaleform::Render::RenderBuffer **)&v21[1].RefCount.Value;
              if ( v26 )
                Scaleform::RefCountImpl::Release(v26);
              *(_QWORD *)&v21[1].RefCount.Value = 0i64;
            }
            Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v21);
          }
        }
        Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF>>::Iterator::RemoveAlt<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>>(
          &v43,
          (Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor> *)&pHash->pTable[v18 + 2]);
        goto LABEL_3;
      }
      v15 = pHash->pTable;
      SizeMask = pHash->pTable->SizeMask;
      if ( Index <= (__int64)SizeMask )
      {
        v43.Index = ++Index;
        if ( Index <= SizeMask )
        {
          v17 = &v15[5 * Index + 1];
          do
          {
            if ( v17->EntryCount != -2i64 )
              break;
            v43.Index = ++Index;
            v17 += 5;
          }
          while ( Index <= SizeMask );
        }
      }
    }
    v4 = op;
    v6 = WeakKeys;
  }
  v29 = v->mHash.pTable;
  if ( v->mHash.pTable )
  {
    v30 = v29 + 1;
    do
    {
      if ( v30->EntryCount != -2i64 )
        break;
      ++v8;
      v30 += 5;
    }
    while ( v8 <= v29->SizeMask );
    v44.pHash = &v->mHash;
  }
  else
  {
    v44.pHash = 0i64;
  }
  v44.Index = v8;
  v43 = v44;
  v31 = v8;
  v32 = v44.pHash;
  while ( v32 )
  {
    v33 = v32->pTable;
    if ( !v32->pTable || v31 > (signed __int64)v33->SizeMask )
      break;
    if ( !v6
      || (v34 = 5 * v31, Scaleform::GFx::AS3::Value::IsValidWeakRef((Scaleform::GFx::AS3::Value *)&v33[5 * v31 + 2])) )
    {
      v34 = 5 * v31;
      v35 = (Scaleform::GFx::AS3::Value *)&v32->pTable[5 * v31 + 2];
      if ( (v35->Flags & 0x1F) > 0xA && (v35->Flags & 0x200) == 0 )
        Scaleform::GFx::AS3::ForEachChild_GC_Internal(prcc, v35, v4);
    }
    v36 = (Scaleform::GFx::AS3::Value *)&v32->pTable[v34 + 4];
    if ( (v36->Flags & 0x1F) > 0xA && (v36->Flags & 0x200) == 0 )
      Scaleform::GFx::AS3::ForEachChild_GC_Internal(prcc, v36, v4);
    v37 = v32->pTable->SizeMask;
    v6 = WeakKeys;
    if ( v31 <= (__int64)v37 && ++v31 <= v37 )
    {
      v38 = &v32->pTable[5 * v31 + 1];
      do
      {
        v6 = WeakKeys;
        if ( v38->EntryCount != -2i64 )
          break;
        ++v31;
        v38 += 5;
      }
      while ( v31 <= v37 );
    }
  }
}

// File Line: 171
// RVA: 0x8CC250
Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::Iterator *__fastcall Scaleform::GFx::AS3::Instances::fl_utils::Dictionary::FindKey(
        Scaleform::GFx::AS3::Instances::fl_utils::Dictionary *this,
        Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::Iterator *result,
        Scaleform::GFx::AS3::Multiname *prop_name)
{
  Scaleform::GFx::AS3::Value *p_Name; // rsi
  Scaleform::HashLH<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor,2,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> > *p_ValueH; // rdi
  __int64 v7; // rax
  __int64 v8; // rax
  bool v9; // zf
  Scaleform::GFx::AS3::Value *p_v; // rcx
  Scaleform::HashLH<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor,2,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> > *v11; // rdi
  __int64 v12; // rax
  __int64 v13; // rax
  Scaleform::HashLH<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor,2,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> > *v14; // rdi
  __int64 v15; // rax
  __int64 v16; // rax
  long double v18[2]; // [rsp+20h] [rbp-50h] BYREF
  Scaleform::GFx::AS3::Value v; // [rsp+30h] [rbp-40h] BYREF
  Scaleform::GFx::AS3::Value key; // [rsp+50h] [rbp-20h] BYREF
  Scaleform::GFx::AS3::Value::HashFunctor v21; // [rsp+A8h] [rbp+38h] BYREF
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+B0h] [rbp+40h] BYREF
  Scaleform::GFx::AS3::CheckResult v23; // [rsp+B8h] [rbp+48h] BYREF

  v18[1] = NAN;
  p_Name = &prop_name->Name;
  result->pHash = 0i64;
  result->Index = 0i64;
  if ( (prop_name->Name.Flags & 0x1F) < 2 )
    goto LABEL_19;
  if ( (prop_name->Name.Flags & 0x1F) > 3 )
  {
    if ( (prop_name->Name.Flags & 0x1F) == 10
      && Scaleform::GFx::AS3::GetStrNumber(&resulta, prop_name->Name.value.VS._1.VStr, v18)->Result )
    {
      v.Flags = 4;
      v.Bonus.pWeakProxy = 0i64;
      v.value.VNumber = v18[0];
      p_ValueH = &this->ValueH;
      if ( !p_ValueH->mHash.pTable
        || (v21 = 0,
            v7 = Scaleform::GFx::AS3::Value::HashFunctor::operator()(&v21, &v),
            v8 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::AS3::Value>(
                   &p_ValueH->mHash,
                   &v,
                   v7 & p_ValueH->mHash.pTable->SizeMask),
            v8 < 0) )
      {
        p_ValueH = 0i64;
        v8 = 0i64;
      }
      result->pHash = &p_ValueH->mHash;
      result->Index = v8;
      if ( (v.Flags & 0x1F) > 9 )
      {
        v9 = (v.Flags & 0x200) == 0;
        p_v = &v;
        goto LABEL_10;
      }
      return result;
    }
LABEL_19:
    v14 = &this->ValueH;
    if ( !v14->mHash.pTable
      || (v21 = 0,
          v15 = Scaleform::GFx::AS3::Value::HashFunctor::operator()(&v21, p_Name),
          v16 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::AS3::Value>(
                  &v14->mHash,
                  p_Name,
                  v15 & v14->mHash.pTable->SizeMask),
          v16 < 0) )
    {
      v14 = 0i64;
      v16 = 0i64;
    }
    result->pHash = &v14->mHash;
    result->Index = v16;
    return result;
  }
  if ( Scaleform::GFx::AS3::Value::Convert2Number(p_Name, &v23, v18)->Result )
  {
    key.Flags = 4;
    key.Bonus.pWeakProxy = 0i64;
    key.value.VNumber = v18[0];
    v11 = &this->ValueH;
    if ( !v11->mHash.pTable
      || (v21 = 0,
          v12 = Scaleform::GFx::AS3::Value::HashFunctor::operator()(&v21, &key),
          v13 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::AS3::Value>(
                  &v11->mHash,
                  &key,
                  v12 & v11->mHash.pTable->SizeMask),
          v13 < 0) )
    {
      v11 = 0i64;
      v13 = 0i64;
    }
    result->pHash = &v11->mHash;
    result->Index = v13;
    if ( (key.Flags & 0x1F) > 9 )
    {
      v9 = (key.Flags & 0x200) == 0;
      p_v = &key;
LABEL_10:
      if ( v9 )
        Scaleform::GFx::AS3::Value::ReleaseInternal(p_v);
      else
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_v);
    }
  }
  return result;
}

// File Line: 198
// RVA: 0x8B0A70
void __fastcall Scaleform::GFx::AS3::Instances::fl_utils::Dictionary::AddDynamicSlotValuePair(
        Scaleform::GFx::AS3::Instances::fl_utils::Dictionary *this,
        Scaleform::GFx::AS3::Value *prop_name,
        Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::AS3::SlotInfo::Attribute a)
{
  unsigned int Flags; // r9d
  int v7; // eax
  long double v8; // xmm6_8
  unsigned int v9; // ecx
  Scaleform::HashLH<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor,2,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> > *p_ValueH; // rsi
  __int64 v11; // r14
  __int64 v12; // rbx
  __int64 v13; // rdi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::TableType *pTable; // rax
  __int64 v15; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::Iterator v16; // [rsp+28h] [rbp-48h] BYREF
  Scaleform::GFx::AS3::Value v; // [rsp+38h] [rbp-38h] BYREF
  Scaleform::GFx::AS3::CheckResult result; // [rsp+A0h] [rbp+30h] BYREF
  long double v19; // [rsp+A8h] [rbp+38h] BYREF

  Flags = prop_name->Flags;
  v.Flags = Flags;
  v.Bonus.pWeakProxy = prop_name->Bonus.pWeakProxy;
  v.value = prop_name->value;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
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
        if ( (v.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
        v9 = v.Flags;
      }
      v.Flags = v9 & 0xFFFFFFE0 | 4;
      v.value.VNumber = v8;
      v.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v16.Index;
    }
  }
  else if ( (unsigned int)(v7 - 2) <= 1 )
  {
    Scaleform::GFx::AS3::Value::ToNumberValue(&v, &result);
  }
  p_ValueH = &this->ValueH;
  if ( this->ValueH.mHash.pTable )
  {
    result.Result = 0;
    v11 = Scaleform::GFx::AS3::Value::HashFunctor::operator()((Scaleform::GFx::AS3::Value::HashFunctor *)&result, &v) & p_ValueH->mHash.pTable->SizeMask;
    v12 = v11;
    v13 = (__int64)&p_ValueH->mHash.pTable[5 * v11 + 1];
    if ( *(_QWORD *)v13 != -2i64 && *(_QWORD *)(v13 + 8) == v11 )
    {
      while ( *(_QWORD *)(v13 + 8) != v11
           || !Scaleform::GFx::AS3::StrictEqual((Scaleform::GFx::AS3::Value *)(v13 + 16), &v) )
      {
        v12 = *(_QWORD *)v13;
        if ( *(_QWORD *)v13 == -1i64 )
          goto LABEL_30;
        v13 = (__int64)&p_ValueH->mHash.pTable[5 * v12 + 1];
      }
      if ( v12 >= 0 )
      {
        v16.pHash = &this->ValueH.mHash;
        v16.Index = v12;
        if ( this != (Scaleform::GFx::AS3::Instances::fl_utils::Dictionary *)-64i64 )
        {
          pTable = p_ValueH->mHash.pTable;
          if ( p_ValueH->mHash.pTable )
          {
            if ( v12 <= (signed __int64)pTable->SizeMask )
            {
              if ( !this->WeakKeys
                || Scaleform::GFx::AS3::Value::IsValidWeakRef((Scaleform::GFx::AS3::Value *)&pTable[5 * v12 + 2]) )
              {
                Scaleform::GFx::AS3::Value::Assign(
                  (Scaleform::GFx::AS3::Value *)&p_ValueH->mHash.pTable[5 * v12 + 4],
                  value);
                goto LABEL_33;
              }
              Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF>>::Iterator::RemoveAlt<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>>(
                &v16,
                (Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor> *)&p_ValueH->mHash.pTable[5 * v12 + 2]);
            }
          }
        }
      }
    }
  }
LABEL_30:
  if ( this->WeakKeys )
    Scaleform::GFx::AS3::Value::MakeWeakRef(&v);
  v16.pHash = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> > *)&v;
  v16.Index = (__int64)value;
  result.Result = 0;
  v15 = Scaleform::GFx::AS3::Value::HashFunctor::operator()((Scaleform::GFx::AS3::Value::HashFunctor *)&result, &v);
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeRef>(
    &this->ValueH.mHash,
    &this->ValueH,
    (Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeRef *)&v16,
    v15);
LABEL_33:
  if ( (v.Flags & 0x1F) > 9 )
  {
    if ( (v.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
  }
}

// File Line: 274
// RVA: 0x8CB9A0
Scaleform::GFx::AS3::PropRef *__fastcall Scaleform::GFx::AS3::Instances::fl_utils::Dictionary::FindDynamicSlot(
        Scaleform::GFx::AS3::Instances::fl_utils::Dictionary *this,
        Scaleform::GFx::AS3::PropRef *result,
        Scaleform::GFx::AS3::Multiname *prop_name)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> > *pHash; // rdi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::TableType *pTable; // rax
  __int64 Index; // rsi
  __int64 v9; // r14
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::Iterator resulta; // [rsp+30h] [rbp-28h] BYREF

  if ( !Scaleform::GFx::AS3::Multiname::ContainsNamespace(
          prop_name,
          this->pTraits.pObject->pVM->PublicNamespace.pObject) )
    goto LABEL_9;
  Scaleform::GFx::AS3::Instances::fl_utils::Dictionary::FindKey(this, &resulta, prop_name);
  pHash = resulta.pHash;
  if ( !resulta.pHash )
    goto LABEL_9;
  pTable = resulta.pHash->pTable;
  if ( !resulta.pHash->pTable )
    goto LABEL_9;
  Index = resulta.Index;
  if ( resulta.Index > (signed __int64)pTable->SizeMask )
    goto LABEL_9;
  if ( this->WeakKeys )
  {
    v9 = 5 * resulta.Index;
    if ( !Scaleform::GFx::AS3::Value::IsValidWeakRef((Scaleform::GFx::AS3::Value *)&pTable[5 * resulta.Index + 2]) )
    {
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF>>::Iterator::RemoveAlt<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>>(
        &resulta,
        (Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor> *)&pHash->pTable[v9 + 2]);
LABEL_9:
      result->pSI = 0i64;
      result->SlotIndex = 0i64;
      result->This.Flags = 0;
      result->This.Bonus.pWeakProxy = 0i64;
      return result;
    }
  }
  result->pSI = (Scaleform::GFx::AS3::SlotInfo *)((__int64)&pHash->pTable[5 * Index + 4] | 1);
  Scaleform::GFx::AS3::Value::Value(&result->This, this);
  return result;
}

// File Line: 293
// RVA: 0x90A1F0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl_utils::Dictionary::SetProperty(
        Scaleform::GFx::AS3::Instances::fl_utils::Dictionary *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Multiname *prop_name,
        Scaleform::GFx::AS3::Value *value)
{
  ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl_utils::Dictionary *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *, _QWORD))this->vfptr[4].Finalize_GC)(
    this,
    &prop_name->Name,
    value,
    0i64);
  result->Result = 1;
  return result;
}

// File Line: 299
// RVA: 0x8DC710
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl_utils::Dictionary::GetProperty(
        Scaleform::GFx::AS3::Instances::fl_utils::Dictionary *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Multiname *prop_name,
        Scaleform::GFx::AS3::Value *value)
{
  bool v8; // bp
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> > *pHash; // rdi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::TableType *pTable; // rax
  __int64 Index; // rbx
  __int64 v12; // rsi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::Iterator resulta; // [rsp+20h] [rbp-28h] BYREF

  v8 = 0;
  if ( Scaleform::GFx::AS3::Multiname::ContainsNamespace(prop_name, this->pTraits.pObject->pVM->PublicNamespace.pObject) )
  {
    Scaleform::GFx::AS3::Instances::fl_utils::Dictionary::FindKey(this, &resulta, prop_name);
    pHash = resulta.pHash;
    if ( resulta.pHash )
    {
      pTable = resulta.pHash->pTable;
      if ( resulta.pHash->pTable )
      {
        Index = resulta.Index;
        if ( resulta.Index <= (signed __int64)pTable->SizeMask )
        {
          if ( !this->WeakKeys
            || (v12 = 5 * resulta.Index,
                Scaleform::GFx::AS3::Value::IsValidWeakRef((Scaleform::GFx::AS3::Value *)&pTable[5 * resulta.Index + 2])) )
          {
            Scaleform::GFx::AS3::Value::Assign(value, (Scaleform::GFx::AS3::Value *)&pHash->pTable[5 * Index + 4]);
            v8 = 1;
          }
          else
          {
            Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF>>::Iterator::RemoveAlt<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>>(
              &resulta,
              (Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor> *)&pHash->pTable[v12 + 2]);
          }
        }
      }
    }
  }
  result->Result = v8;
  return result;
}

// File Line: 322
// RVA: 0x8D7300
void __fastcall Scaleform::GFx::AS3::Instances::fl_utils::Dictionary::GetDynamicProperty(
        Scaleform::GFx::AS3::Instances::fl_utils::Dictionary *this,
        Scaleform::GFx::AS3::AbsoluteIndex ind,
        Scaleform::GFx::AS3::Value *value)
{
  Scaleform::HashLH<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor,2,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> > *p_ValueH; // r9
  Scaleform::HashLH<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor,2,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> > *v4; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::TableType *pTable; // rcx
  unsigned __int64 SizeMask; // r8
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::TableType *v8; // rcx

  p_ValueH = &this->ValueH;
  v4 = 0i64;
  pTable = this->ValueH.mHash.pTable;
  if ( pTable )
  {
    SizeMask = pTable->SizeMask;
    v8 = pTable + 1;
    do
    {
      if ( v8->EntryCount != -2i64 )
        break;
      v4 = (Scaleform::HashLH<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor,2,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> > *)((char *)v4 + 1);
      v8 += 5;
    }
    while ( (unsigned __int64)v4 <= SizeMask );
    v4 = p_ValueH;
  }
  Scaleform::GFx::AS3::Value::Assign(value, (Scaleform::GFx::AS3::Value *)&v4->mHash.pTable[5 * LODWORD(ind.Index) + 4]);
}

// File Line: 330
// RVA: 0x8C5180
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl_utils::Dictionary::DeleteProperty(
        Scaleform::GFx::AS3::Instances::fl_utils::Dictionary *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Multiname *prop_name)
{
  bool v6; // di
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::TableType *pTable; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::Iterator resulta; // [rsp+20h] [rbp-18h] BYREF

  v6 = 0;
  if ( Scaleform::GFx::AS3::Multiname::ContainsNamespace(prop_name, this->pTraits.pObject->pVM->PublicNamespace.pObject) )
  {
    Scaleform::GFx::AS3::Instances::fl_utils::Dictionary::FindKey(this, &resulta, prop_name);
    if ( resulta.pHash )
    {
      pTable = resulta.pHash->pTable;
      if ( resulta.pHash->pTable )
      {
        if ( resulta.Index <= (signed __int64)pTable->SizeMask )
        {
          Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF>>::Iterator::RemoveAlt<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>>(
            &resulta,
            (Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor> *)&pTable[5 * resulta.Index + 2]);
          v6 = 1;
        }
      }
    }
  }
  result->Result = v6;
  return result;
}

// File Line: 348
// RVA: 0x8CE090
void __fastcall Scaleform::GFx::AS3::Instances::fl_utils::Dictionary::ForEachChild_GC(
        Scaleform::GFx::AS3::Instances::fl_utils::Dictionary *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  Scaleform::GFx::AS3::Object::ForEachChild_GC(this, prcc, op);
  Scaleform::GFx::AS3::ForEachChild_GC(
    prcc,
    this->WeakKeys,
    &this->ValueH,
    (void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::Value::V2U *, void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **), Scaleform::GFx::AS3::RefCountCollector<328> *))op);
}

// File Line: 355
// RVA: 0x8DBB00
void __fastcall Scaleform::GFx::AS3::Instances::fl_utils::Dictionary::GetNextPropertyName(
        Scaleform::GFx::AS3::Instances::fl_utils::Dictionary *this,
        Scaleform::GFx::AS3::Value *name,
        Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::TableType *pTable; // rcx
  Scaleform::HashLH<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor,2,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> > *p_ValueH; // rax
  unsigned __int64 SizeMask; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::TableType *v8; // rcx

  if ( ind.Index )
  {
    pTable = this->ValueH.mHash.pTable;
    p_ValueH = 0i64;
    if ( pTable )
    {
      SizeMask = pTable->SizeMask;
      v8 = pTable + 1;
      do
      {
        if ( v8->EntryCount != -2i64 )
          break;
        p_ValueH = (Scaleform::HashLH<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor,2,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> > *)((char *)p_ValueH + 1);
        v8 += 5;
      }
      while ( (unsigned __int64)p_ValueH <= SizeMask );
      p_ValueH = &this->ValueH;
    }
    Scaleform::GFx::AS3::Value::Assign(
      name,
      (Scaleform::GFx::AS3::Value *)&p_ValueH->mHash.pTable[5 * (ind.Index - 1) + 2]);
    if ( this->WeakKeys )
      Scaleform::GFx::AS3::Value::MakeStrongRef(name);
  }
}

// File Line: 371
// RVA: 0x8DB720
Scaleform::GFx::AS3::GlobalSlotIndex *__fastcall Scaleform::GFx::AS3::Instances::fl_utils::Dictionary::GetNextDynPropIndex(
        Scaleform::GFx::AS3::Instances::fl_utils::Dictionary *this,
        Scaleform::GFx::AS3::GlobalSlotIndex *result,
        Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::TableType *pTable; // rax
  Scaleform::HashLH<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor,2,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> > *p_ValueH; // rdi
  unsigned __int64 SizeMask; // rdx
  unsigned __int64 v8; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::TableType *v9; // rax
  __int64 v10; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::TableType *v11; // r8
  unsigned __int64 v12; // rdx
  unsigned __int64 v13; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::TableType *v14; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::TableType *v15; // rcx

  pTable = this->ValueH.mHash.pTable;
  p_ValueH = &this->ValueH;
  if ( pTable )
  {
    SizeMask = pTable->SizeMask;
    v8 = 0i64;
    v9 = pTable + 1;
    do
    {
      if ( v9->EntryCount != -2i64 )
        break;
      ++v8;
      v9 += 5;
    }
    while ( v8 <= SizeMask );
  }
  else
  {
    p_ValueH = 0i64;
  }
  if ( ind.Index )
    v10 = ind.Index - 1;
  else
    v10 = -1i64;
  if ( p_ValueH )
  {
    v11 = p_ValueH->mHash.pTable;
    if ( p_ValueH->mHash.pTable )
    {
      v12 = v11->SizeMask;
      if ( v10 <= (__int64)v12 )
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
        while ( v11 && (__int64)v13 <= (__int64)v12 )
        {
          if ( !this->WeakKeys
            || Scaleform::GFx::AS3::Value::IsValidWeakRef((Scaleform::GFx::AS3::Value *)&v11[5 * v13 + 2]) )
          {
            result->Index = v13 + 1;
            return result;
          }
          v11 = p_ValueH->mHash.pTable;
          v12 = p_ValueH->mHash.pTable->SizeMask;
          if ( (__int64)v13 <= (__int64)v12 && ++v13 <= v12 )
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
  result->Index = 0;
  return result;
}

// File Line: 388
// RVA: 0x8AE990
void __fastcall Scaleform::GFx::AS3::Instances::fl_utils::Dictionary::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_utils::Dictionary *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  if ( argc )
  {
    if ( (unsigned __int8)Scaleform::GFx::AS3::Value::Convert2Boolean(argv) )
      this->WeakKeys = 1;
  }
}

// File Line: 413
// RVA: 0x8EADC0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_utils::Dictionary::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_utils::Dictionary *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_utils::Dictionary *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_utils::Dictionary> *Instance; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_utils::Dictionary> resulta; // [rsp+48h] [rbp+20h] BYREF

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_utils::Dictionary::MakeInstance(&resulta, t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}

// File Line: 436
// RVA: 0x877520
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_utils::Dictionary::MakeClassTraits(
        Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // rsi
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v6; // rbx
  Scaleform::GFx::AS3::InstanceTraits::fl::Object *v7; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> v8; // rbx
  Scaleform::GFx::AS3::Class *v9; // rax

  MHeap = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::fl::Object *)MHeap->vfptr->Alloc(MHeap, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::Object::Object(v5, vm, &Scaleform::GFx::AS3::fl_utils::DictionaryCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_utils::Dictionary::`vftable;
    v6->TraitsType = Traits_Dictionary;
  }
  else
  {
    v6 = 0i64;
  }
  result->pV = v6;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::fl::Object *)MHeap->vfptr->Alloc(MHeap, 240ui64, 0i64);
  v8.pV = v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::fl::Object::Object(v7, vm, &Scaleform::GFx::AS3::fl_utils::DictionaryCI);
    v8.pV->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_utils::Dictionary::`vftable;
    v8.pV->Flags |= 1ui64;
    v8.pV->TraitsType = Traits_Dictionary;
  }
  else
  {
    v8.pV = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(result->pV, v8);
  v9 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))MHeap->vfptr->Alloc)(
                                       MHeap,
                                       72i64);
  if ( v9 )
    Scaleform::GFx::AS3::Class::Class(v9, result->pV);
  return result;
}

