// File Line: 40
// RVA: 0x77A090
void __fastcall Scaleform::GFx::AS3::ASRefCountCollector::ASRefCountCollector(Scaleform::GFx::AS3::ASRefCountCollector *this)
{
  Scaleform::GFx::AS3::ASRefCountCollector *v1; // rbx

  v1 = this;
  Scaleform::GFx::AS3::RefCountCollector<328>::RefCountCollector<328>((Scaleform::GFx::AS3::RefCountCollector<328> *)&this->vfptr);
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS3::ASRefCountCollector::`vftable;
  v1->FrameCnt = 0;
  *(_QWORD *)&v1->PeakRootCount = 0i64;
  *(_QWORD *)&v1->LastCollectedRoots = 0i64;
  *(_QWORD *)&v1->TotalFramesCount = 0i64;
  *(_QWORD *)&v1->RunsToCollectOld = 10i64;
  v1->SuspendCnt = 0;
  *(_QWORD *)&v1->MaxFramesBetweenCollections = 0i64;
  v1->MaxRootCount = 1000;
  v1->PresetMaxRootCount = 1000;
  v1->RunsToUpgradeGen = 5;
  v1->RunsToCollectYoung = 5;
}

// File Line: 62
// RVA: 0x81ABB0
void __fastcall Scaleform::GFx::AS3::ASRefCountCollector::SetParams(Scaleform::GFx::AS3::ASRefCountCollector *this, unsigned int frameBetweenCollections, unsigned int maxRootCount, unsigned int runsToUpgradeGen, unsigned int runsToCollectYoung, unsigned int runsToCollectOld)
{
  unsigned int v6; // eax
  Scaleform::GFx::AS3::ASRefCountCollector *v7; // r10
  unsigned int v8; // ecx
  unsigned int v9; // eax
  unsigned int v10; // ecx

  v6 = 0;
  v7 = this;
  if ( frameBetweenCollections != -1 )
    v6 = frameBetweenCollections;
  this->MaxFramesBetweenCollections = v6;
  if ( maxRootCount == -1 )
  {
    this->MaxRootCount = 1000;
    this->PresetMaxRootCount = 1000;
  }
  else
  {
    this->MaxRootCount = maxRootCount;
    this->PresetMaxRootCount = maxRootCount;
  }
  v8 = 5;
  v9 = 5;
  if ( runsToUpgradeGen != -1 )
    v9 = runsToUpgradeGen;
  if ( runsToCollectYoung != -1 )
    v8 = runsToCollectYoung;
  v7->RunsToUpgradeGen = v9;
  v7->RunsToCollectYoung = v8;
  v10 = 10;
  if ( runsToCollectOld != -1 )
    v10 = runsToCollectOld;
  v7->RunsToCollectOld = v10;
}

// File Line: 119
// RVA: 0x7AFE60
void __fastcall Scaleform::GFx::AS3::ASRefCountCollector::AdvanceFrame(Scaleform::GFx::AS3::ASRefCountCollector *this, unsigned int *movieFrameCnt, unsigned int *movieLastCollectFrame, Scaleform::AmpStats *ampStats)
{
  Scaleform::GFx::Resource *v4; // r13
  unsigned int *v5; // r14
  unsigned int *v6; // rsi
  Scaleform::GFx::AS3::ASRefCountCollector *v7; // rbx
  unsigned int v8; // eax
  unsigned int v9; // er15
  unsigned int v10; // ebp
  bool v11; // r12
  unsigned int v12; // er8
  unsigned int v13; // eax
  unsigned int v14; // edi
  unsigned int v15; // er15
  unsigned int v16; // edx
  unsigned int v17; // ecx
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // edx
  int v21; // ecx
  unsigned int v22; // eax
  unsigned int v23; // ecx
  Scaleform::GFx::AS3::RefCountCollector<328>::Stats pstat; // [rsp+28h] [rbp-50h]

  v4 = (Scaleform::GFx::Resource *)ampStats;
  v5 = movieLastCollectFrame;
  v6 = movieFrameCnt;
  v7 = this;
  v8 = this->LastCollectionFrameNum;
  if ( *movieLastCollectFrame == v8 )
  {
    v9 = this->FrameCnt;
    if ( *movieFrameCnt >= v9 )
    {
      v10 = 0;
      v11 = 0;
      v12 = this->RunsCnt;
      if ( v12 )
      {
        if ( v12 % this->RunsToCollectOld )
        {
          if ( !(v12 % this->RunsToCollectYoung) )
            v10 = 1;
        }
        else
        {
          v10 = 2;
        }
        v11 = 0;
        if ( !(v12 % this->RunsToUpgradeGen) )
          v11 = 1;
      }
      v13 = Scaleform::GFx::AS3::RefCountCollector<328>::GetRootsCount(
              (Scaleform::GFx::AS3::RefCountCollector<328> *)&this->vfptr,
              v10);
      v14 = v13;
      ++v7->TotalFramesCount;
      v15 = v9 + 1;
      v7->FrameCnt = v15;
      v16 = v13;
      if ( v13 < v7->PeakRootCount )
        v16 = v7->PeakRootCount;
      v7->PeakRootCount = v16;
      if ( !v7->SuspendCnt )
      {
        if ( (v17 = v7->PresetMaxRootCount) != 0 && v13 > v7->MaxRootCount
          || (v18 = v7->MaxFramesBetweenCollections) != 0 && v15 >= v18 && v14 > v17 )
        {
          if ( v4 )
            Scaleform::Render::RenderBuffer::AddRef(v4);
          pstat.AdvanceStats.pObject = (Scaleform::AmpStats *)v4;
          *(_QWORD *)&pstat.ObjectsFreedTotal = 0i64;
          *(_QWORD *)&pstat.RootsFreedTotal = 0i64;
          pstat.RootsNumber = 0;
          Scaleform::GFx::AS3::RefCountCollector<328>::Collect(
            (Scaleform::GFx::AS3::RefCountCollector<328> *)&v7->vfptr,
            v10,
            v11,
            &pstat);
          ++v7->RunsCnt;
          v19 = v7->PresetMaxRootCount;
          v20 = pstat.RootsFreedTotal;
          if ( pstat.RootsFreedTotal > v19 )
          {
            v7->PeakRootCount = v14;
            v7->MaxRootCount = v19;
          }
          if ( v14 > v20 )
          {
            v21 = v14 - v20;
            if ( v14 - v20 < v7->MaxRootCount )
              v21 = v7->MaxRootCount;
            v7->MaxRootCount = v21;
          }
          v22 = (signed int)((double)(signed int)v7->MaxRootCount * 0.7);
          v23 = v7->PeakRootCount;
          if ( v23 < v22 )
            v7->MaxRootCount = v22;
          v7->LastCollectionFrameNum = v7->TotalFramesCount;
          v7->FrameCnt = 0;
          v7->LastPeakRootCount = v23;
          v7->LastCollectedRoots = v20;
          if ( pstat.AdvanceStats.pObject )
            Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)pstat.AdvanceStats.pObject);
        }
      }
      v7->LastRootCount = v14;
      *v6 = v7->FrameCnt;
      *v5 = v7->LastCollectionFrameNum;
    }
    else
    {
      ++*movieFrameCnt;
    }
  }
  else
  {
    *movieLastCollectFrame = v8;
    *movieFrameCnt = 1;
  }
}

// File Line: 205
// RVA: 0x7D7380
void __fastcall Scaleform::GFx::AS3::ASRefCountCollector::ForceCollect(Scaleform::GFx::AS3::ASRefCountCollector *this, Scaleform::AmpStats *ampStats, unsigned int collectFlags)
{
  unsigned int v3; // edi
  Scaleform::GFx::Resource *v4; // r12
  Scaleform::GFx::AS3::ASRefCountCollector *v5; // rbx
  signed int v6; // ecx
  bool v7; // r14
  unsigned int v8; // er8
  unsigned int v9; // esi
  unsigned int v10; // ebp
  unsigned int v11; // ecx
  Scaleform::GFx::AS3::RefCountCollector<328>::Stats pstat; // [rsp+28h] [rbp-50h]

  v3 = collectFlags;
  v4 = (Scaleform::GFx::Resource *)ampStats;
  v5 = this;
  if ( !this->SuspendCnt )
  {
    v6 = 0;
    v7 = 0;
    v8 = v5->RunsCnt;
    v9 = 2;
    if ( v8 )
    {
      if ( v8 % v5->RunsToCollectOld )
      {
        if ( !(v8 % v5->RunsToCollectYoung) )
          v6 = 1;
      }
      else
      {
        v6 = 2;
      }
      v7 = 0;
      if ( !(v8 % v5->RunsToUpgradeGen) )
        v7 = 1;
    }
    if ( v3 & 3 )
    {
      v5->Flags |= 0x20u;
    }
    else
    {
      v7 = 0;
      if ( !(v3 & 0x20) )
      {
        if ( v3 & 0x10 )
        {
          v9 = 1;
        }
        else
        {
          v9 = v6;
          if ( v3 & 8 )
            v9 = 0;
        }
      }
    }
    v10 = Scaleform::GFx::AS3::RefCountCollector<328>::GetRootsCount(
            (Scaleform::GFx::AS3::RefCountCollector<328> *)&v5->vfptr,
            v9);
    if ( v4 )
      Scaleform::Render::RenderBuffer::AddRef(v4);
    pstat.AdvanceStats.pObject = (Scaleform::AmpStats *)v4;
    *(_QWORD *)&pstat.ObjectsFreedTotal = 0i64;
    *(_QWORD *)&pstat.RootsFreedTotal = 0i64;
    pstat.RootsNumber = 0;
    Scaleform::GFx::AS3::RefCountCollector<328>::Collect(
      (Scaleform::GFx::AS3::RefCountCollector<328> *)&v5->vfptr,
      v9,
      v7,
      &pstat);
    if ( v3 & 3 )
      ++v5->RunsCnt;
    v5->FrameCnt = 0;
    v11 = v10;
    if ( v10 < v5->PeakRootCount )
      v11 = v5->PeakRootCount;
    v5->PeakRootCount = v11;
    v5->LastRootCount = v10;
    if ( v5->Flags & 0x10 )
      v5->CollectionScheduledFlags = v3 & 0xFFFFFFF8 | 8;
    if ( pstat.AdvanceStats.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)pstat.AdvanceStats.pObject);
  }
}

// File Line: 276
// RVA: 0x7D70A0
void __fastcall Scaleform::GFx::AS3::ForEachChild_GC_Internal(Scaleform::GFx::AS3::RefCountCollector<328> *prcc, Scaleform::GFx::AS3::Value *v, void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  Scaleform::GFx::AS3::RefCountCollector<328> *v3; // r9
  signed int v4; // eax
  Scaleform::GFx::AS3::Value::V2U *v5; // rdx
  Scaleform::GFx::AS3::RefCountBaseGC<328> **v6; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> **v7; // rdx

  v3 = prcc;
  v4 = v->Flags & 0x1F;
  if ( v4 >= 11 )
  {
    if ( v4 <= 15 )
    {
      v6 = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v->value;
      if ( *(_QWORD *)&v->value.VNumber )
      {
        v7 = 0i64;
        if ( (unsigned int)(v4 - 11) <= 4 )
          v7 = v6;
        op(v3, v7);
      }
    }
    else if ( v4 <= 17 )
    {
      v5 = &v->value.VS._2;
      if ( v5->VObj )
        ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::Value::V2U *, void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **), Scaleform::GFx::AS3::RefCountCollector<328> *))op)(
          prcc,
          v5,
          op,
          prcc);
    }
  }
}

// File Line: 312
// RVA: 0x7D51D0
void __fastcall Scaleform::GFx::AS3::ForEachChild_GC(Scaleform::GFx::AS3::RefCountCollector<328> *prcc, Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v, void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  unsigned __int64 v3; // rbx
  void (__fastcall *v4)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **); // rbp
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v5; // rsi
  Scaleform::GFx::AS3::RefCountCollector<328> *v6; // r14
  __int64 v7; // rdi
  Scaleform::GFx::AS3::Value *v8; // r8
  int v9; // eax
  signed __int64 v10; // rdx
  _QWORD *v11; // r8

  v3 = 0i64;
  v4 = op;
  v5 = v;
  v6 = prcc;
  if ( v->Data.Size )
  {
    v7 = 0i64;
    while ( 1 )
    {
      v8 = &v5->Data.Data[v7];
      v9 = v8->Flags & 0x1F;
      if ( v9 <= 10 || (v8->Flags >> 9) & 1 || v9 < 11 )
        goto LABEL_14;
      if ( v9 > 15 )
        break;
      v11 = (_QWORD *)&v8->value.VNumber;
      if ( *v11 )
      {
        v10 = 0i64;
        if ( (unsigned int)(v9 - 11) <= 4 )
          v10 = (signed __int64)v11;
LABEL_13:
        v4(v6, (Scaleform::GFx::AS3::RefCountBaseGC<328> **)v10);
      }
LABEL_14:
      ++v3;
      ++v7;
      if ( v3 >= v5->Data.Size )
        return;
    }
    if ( v9 > 17 )
      goto LABEL_14;
    v10 = (signed __int64)&v8->value.VS._2.VObj;
    if ( !v8->value.VS._2.VObj )
      goto LABEL_14;
    goto LABEL_13;
  }
}

// File Line: 320
// RVA: 0x78AD70
void __fastcall Scaleform::GFx::AS3::GASRefCountBase::~GASRefCountBase(Scaleform::GFx::AS3::GASRefCountBase *this)
{
  Scaleform::GFx::AS3::GASRefCountBase *v1; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF> > *v2; // rdi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF> >::TableType *v3; // r9
  signed __int64 v4; // rcx
  signed __int64 v5; // rdx
  signed __int64 v6; // rax
  signed __int64 v7; // r8
  signed __int64 v8; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF> >::TableType *v9; // rcx
  signed __int64 v10; // rdx
  __int64 v11; // rdx
  bool v12; // zf
  Scaleform::GFx::AS3::GASRefCountBase *key; // [rsp+48h] [rbp+10h]

  v1 = this;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::GASRefCountBase::`vftable;
  if ( (this->RefCount >> 26) & 1 )
  {
    v2 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF> > *)(this->pRCCRaw & 0xFFFFFFFFFFFFFFFCui64);
    key = this;
    v3 = v2[17].pTable;
    if ( v3 )
    {
      v4 = 5381i64;
      v5 = 8i64;
      do
      {
        v6 = 65599 * v4 + *((unsigned __int8 *)&key + --v5);
        v4 = 65599 * v4 + *((unsigned __int8 *)&key + v5);
      }
      while ( v5 );
      v7 = v6 & v3->SizeMask;
      v8 = v6 & v3->SizeMask;
      v9 = &v3[2 * (v6 & v3->SizeMask) + 1];
      if ( v9->EntryCount != -2i64 && v9->SizeMask == v7 )
      {
        while ( v9->SizeMask != v7 || (Scaleform::GFx::AS3::GASRefCountBase *)v9[1].EntryCount != v1 )
        {
          v8 = v9->EntryCount;
          if ( v9->EntryCount == -1i64 )
            goto LABEL_17;
          v9 = &v3[2 * v8 + 1];
        }
        if ( v8 >= 0 )
        {
          v10 = (signed __int64)&v3[2 * (v8 + 1)];
          if ( v10 )
          {
            v11 = *(_QWORD *)(v10 + 8);
            if ( v11 )
            {
              *(_QWORD *)(v11 + 8) = 0i64;
              v12 = (*(_DWORD *)v11)-- == 1;
              if ( v12 )
                ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
              key = v1;
              Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *>>::NodeHashF>>::RemoveAlt<Scaleform::GFx::AS3::GASRefCountBase *>(
                v2 + 17,
                &key);
            }
          }
        }
      }
    }
  }
LABEL_17:
  v1->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::RefCountBaseGC<328>::`vftable;
}

