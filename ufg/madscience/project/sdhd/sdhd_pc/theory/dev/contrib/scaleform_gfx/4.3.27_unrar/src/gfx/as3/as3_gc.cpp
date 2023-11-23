// File Line: 40
// RVA: 0x77A090
void __fastcall Scaleform::GFx::AS3::ASRefCountCollector::ASRefCountCollector(
        Scaleform::GFx::AS3::ASRefCountCollector *this)
{
  Scaleform::GFx::AS3::RefCountCollector<328>::RefCountCollector<328>(this);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS3::ASRefCountCollector::`vftable;
  this->FrameCnt = 0;
  *(_QWORD *)&this->PeakRootCount = 0i64;
  *(_QWORD *)&this->LastCollectedRoots = 0i64;
  *(_QWORD *)&this->TotalFramesCount = 0i64;
  *(_QWORD *)&this->RunsToCollectOld = 10i64;
  this->SuspendCnt = 0;
  *(_QWORD *)&this->MaxFramesBetweenCollections = 0i64;
  this->MaxRootCount = 1000;
  this->PresetMaxRootCount = 1000;
  this->RunsToUpgradeGen = 5;
  this->RunsToCollectYoung = 5;
}

// File Line: 62
// RVA: 0x81ABB0
void __fastcall Scaleform::GFx::AS3::ASRefCountCollector::SetParams(
        Scaleform::GFx::AS3::ASRefCountCollector *this,
        unsigned int frameBetweenCollections,
        unsigned int maxRootCount,
        unsigned int runsToUpgradeGen,
        unsigned int runsToCollectYoung,
        unsigned int runsToCollectOld)
{
  unsigned int v6; // eax
  unsigned int v8; // ecx
  unsigned int v9; // eax
  unsigned int v10; // ecx

  v6 = 0;
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
  this->RunsToUpgradeGen = v9;
  this->RunsToCollectYoung = v8;
  v10 = 10;
  if ( runsToCollectOld != -1 )
    v10 = runsToCollectOld;
  this->RunsToCollectOld = v10;
}

// File Line: 119
// RVA: 0x7AFE60
void __fastcall Scaleform::GFx::AS3::ASRefCountCollector::AdvanceFrame(
        Scaleform::GFx::AS3::ASRefCountCollector *this,
        unsigned int *movieFrameCnt,
        unsigned int *movieLastCollectFrame,
        Scaleform::GFx::Resource *ampStats)
{
  unsigned int LastCollectionFrameNum; // eax
  unsigned int FrameCnt; // r15d
  unsigned int v10; // ebp
  bool v11; // r12
  unsigned int RunsCnt; // r8d
  unsigned int RootsCount; // eax
  unsigned int v14; // edi
  unsigned int v15; // r15d
  unsigned int PeakRootCount; // edx
  unsigned int v17; // ecx
  unsigned int MaxFramesBetweenCollections; // eax
  unsigned int PresetMaxRootCount; // eax
  unsigned int RootsFreedTotal; // edx
  unsigned int MaxRootCount; // ecx
  unsigned int v22; // eax
  unsigned int v23; // ecx
  Scaleform::GFx::AS3::RefCountCollector<328>::Stats pstat; // [rsp+28h] [rbp-50h] BYREF

  LastCollectionFrameNum = this->LastCollectionFrameNum;
  if ( *movieLastCollectFrame == LastCollectionFrameNum )
  {
    FrameCnt = this->FrameCnt;
    if ( *movieFrameCnt >= FrameCnt )
    {
      v10 = 0;
      v11 = 0;
      RunsCnt = this->RunsCnt;
      if ( RunsCnt )
      {
        if ( RunsCnt % this->RunsToCollectOld )
        {
          if ( !(RunsCnt % this->RunsToCollectYoung) )
            v10 = 1;
        }
        else
        {
          v10 = 2;
        }
        v11 = RunsCnt % this->RunsToUpgradeGen == 0;
      }
      RootsCount = Scaleform::GFx::AS3::RefCountCollector<328>::GetRootsCount(this, v10);
      v14 = RootsCount;
      ++this->TotalFramesCount;
      v15 = FrameCnt + 1;
      this->FrameCnt = v15;
      PeakRootCount = RootsCount;
      if ( RootsCount < this->PeakRootCount )
        PeakRootCount = this->PeakRootCount;
      this->PeakRootCount = PeakRootCount;
      if ( !this->SuspendCnt
        && ((v17 = this->PresetMaxRootCount) != 0 && RootsCount > this->MaxRootCount
         || (MaxFramesBetweenCollections = this->MaxFramesBetweenCollections) != 0
         && v15 >= MaxFramesBetweenCollections
         && v14 > v17) )
      {
        if ( ampStats )
          Scaleform::Render::RenderBuffer::AddRef(ampStats);
        pstat.AdvanceStats.pObject = (Scaleform::AmpStats *)ampStats;
        memset(&pstat.RootsNumber, 0, 20);
        Scaleform::GFx::AS3::RefCountCollector<328>::Collect(this, v10, v11, &pstat);
        ++this->RunsCnt;
        PresetMaxRootCount = this->PresetMaxRootCount;
        RootsFreedTotal = pstat.RootsFreedTotal;
        if ( pstat.RootsFreedTotal > PresetMaxRootCount )
        {
          this->PeakRootCount = v14;
          this->MaxRootCount = PresetMaxRootCount;
        }
        if ( v14 > RootsFreedTotal )
        {
          MaxRootCount = v14 - RootsFreedTotal;
          if ( v14 - RootsFreedTotal < this->MaxRootCount )
            MaxRootCount = this->MaxRootCount;
          this->MaxRootCount = MaxRootCount;
        }
        v22 = (int)((double)(int)this->MaxRootCount * 0.7);
        v23 = this->PeakRootCount;
        if ( v23 < v22 )
          this->MaxRootCount = v22;
        this->LastCollectionFrameNum = this->TotalFramesCount;
        this->FrameCnt = 0;
        this->LastPeakRootCount = v23;
        this->LastCollectedRoots = RootsFreedTotal;
        if ( pstat.AdvanceStats.pObject )
          Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)pstat.AdvanceStats.pObject);
      }
      this->LastRootCount = v14;
      *movieFrameCnt = this->FrameCnt;
      *movieLastCollectFrame = this->LastCollectionFrameNum;
    }
    else
    {
      ++*movieFrameCnt;
    }
  }
  else
  {
    *movieLastCollectFrame = LastCollectionFrameNum;
    *movieFrameCnt = 1;
  }
}

// File Line: 205
// RVA: 0x7D7380
void __fastcall Scaleform::GFx::AS3::ASRefCountCollector::ForceCollect(
        Scaleform::GFx::AS3::ASRefCountCollector *this,
        Scaleform::GFx::Resource *ampStats,
        unsigned int collectFlags)
{
  int v6; // ecx
  bool v7; // r14
  unsigned int RunsCnt; // r8d
  unsigned int v9; // esi
  unsigned int RootsCount; // ebp
  unsigned int PeakRootCount; // ecx
  Scaleform::GFx::AS3::RefCountCollector<328>::Stats pstat; // [rsp+28h] [rbp-50h] BYREF

  if ( !this->SuspendCnt )
  {
    v6 = 0;
    v7 = 0;
    RunsCnt = this->RunsCnt;
    v9 = 2;
    if ( RunsCnt )
    {
      if ( RunsCnt % this->RunsToCollectOld )
      {
        if ( !(RunsCnt % this->RunsToCollectYoung) )
          v6 = 1;
      }
      else
      {
        v6 = 2;
      }
      v7 = RunsCnt % this->RunsToUpgradeGen == 0;
    }
    if ( (collectFlags & 3) != 0 )
    {
      this->Flags |= 0x20u;
    }
    else
    {
      v7 = 0;
      if ( (collectFlags & 0x20) == 0 )
      {
        if ( (collectFlags & 0x10) != 0 )
        {
          v9 = 1;
        }
        else
        {
          v9 = v6;
          if ( (collectFlags & 8) != 0 )
            v9 = 0;
        }
      }
    }
    RootsCount = Scaleform::GFx::AS3::RefCountCollector<328>::GetRootsCount(this, v9);
    if ( ampStats )
      Scaleform::Render::RenderBuffer::AddRef(ampStats);
    pstat.AdvanceStats.pObject = (Scaleform::AmpStats *)ampStats;
    memset(&pstat.RootsNumber, 0, 20);
    Scaleform::GFx::AS3::RefCountCollector<328>::Collect(this, v9, v7, &pstat);
    if ( (collectFlags & 3) != 0 )
      ++this->RunsCnt;
    this->FrameCnt = 0;
    PeakRootCount = RootsCount;
    if ( RootsCount < this->PeakRootCount )
      PeakRootCount = this->PeakRootCount;
    this->PeakRootCount = PeakRootCount;
    this->LastRootCount = RootsCount;
    if ( (this->Flags & 0x10) != 0 )
      this->CollectionScheduledFlags = collectFlags & 0xFFFFFFF0 | 8;
    if ( pstat.AdvanceStats.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)pstat.AdvanceStats.pObject);
  }
}

// File Line: 276
// RVA: 0x7D70A0
void __fastcall Scaleform::GFx::AS3::ForEachChild_GC_Internal(
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        Scaleform::GFx::AS3::Value *v,
        void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::Value::V2U *, void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **), Scaleform::GFx::AS3::RefCountCollector<328> *))
{
  unsigned int v4; // eax
  Scaleform::GFx::AS3::Value::V2U *v5; // rdx
  Scaleform::GFx::AS3::Value::VU *p_value; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> **v7; // rdx

  v4 = v->Flags & 0x1F;
  if ( v4 >= 0xB )
  {
    if ( (v->Flags & 0x1F) <= 0xF )
    {
      p_value = &v->value;
      if ( v->value.VS._1.VStr )
      {
        v7 = 0i64;
        if ( v4 - 11 <= 4 )
          v7 = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)p_value;
        ((void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))op)(
          prcc,
          v7);
      }
    }
    else if ( (v->Flags & 0x1F) <= 0x11 )
    {
      v5 = &v->value.VS._2;
      if ( v5->VObj )
        op(
          prcc,
          v5,
          (void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))op,
          prcc);
    }
  }
}

// File Line: 312
// RVA: 0x7D51D0
void __fastcall Scaleform::GFx::AS3::ForEachChild_GC(
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v,
        void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  __int64 v3; // rbx
  __int64 i; // rdi
  Scaleform::GFx::AS3::Value *v8; // r8
  unsigned int v9; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> **p_VObj; // rdx
  Scaleform::GFx::AS3::Value::V1U *p_value; // r8

  v3 = 0i64;
  if ( v->Data.Size )
  {
    for ( i = 0i64; ; ++i )
    {
      v8 = &v->Data.Data[i];
      v9 = v8->Flags & 0x1F;
      if ( v9 <= 0xA || (v8->Flags & 0x200) != 0 || (v8->Flags & 0x1F) < 0xB )
        goto LABEL_14;
      if ( (v8->Flags & 0x1F) > 0xF )
        break;
      p_value = (Scaleform::GFx::AS3::Value::V1U *)&v8->value;
      if ( p_value->VStr )
      {
        p_VObj = 0i64;
        if ( v9 - 11 <= 4 )
          p_VObj = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)p_value;
LABEL_13:
        op(prcc, p_VObj);
      }
LABEL_14:
      if ( ++v3 >= v->Data.Size )
        return;
    }
    if ( (v8->Flags & 0x1F) > 0x11 )
      goto LABEL_14;
    p_VObj = &v8->value.VS._2.VObj;
    if ( !v8->value.VS._2.VObj )
      goto LABEL_14;
    goto LABEL_13;
  }
}

// File Line: 320
// RVA: 0x78AD70
void __fastcall Scaleform::GFx::AS3::GASRefCountBase::~GASRefCountBase(Scaleform::GFx::AS3::GASRefCountBase *this)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF> > *v2; // rdi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF> >::TableType *pTable; // r9
  __int64 v4; // rcx
  __int64 v5; // rdx
  __int64 v6; // rax
  __int64 v7; // r8
  __int64 v8; // rdx
  __int64 v9; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF> >::TableType *v10; // rdx
  unsigned __int64 SizeMask; // rdx
  Scaleform::GFx::AS3::GASRefCountBase *key; // [rsp+48h] [rbp+10h] BYREF

  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::GASRefCountBase::`vftable;
  if ( (this->RefCount & 0x4000000) != 0 )
  {
    v2 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase *,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase *,Scaleform::GFx::AS3::WeakProxy *,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase *> >::NodeHashF> > *)(this->pRCCRaw & 0xFFFFFFFFFFFFFFFCui64);
    key = this;
    pTable = v2[17].pTable;
    if ( pTable )
    {
      v4 = 5381i64;
      v5 = 8i64;
      do
      {
        --v5;
        v6 = 65599 * v4 + *((unsigned __int8 *)&key + v5);
        v4 = v6;
      }
      while ( v5 );
      v7 = v6 & pTable->SizeMask;
      v8 = v7;
      v9 = (__int64)&pTable[2 * v7 + 1];
      if ( *(_QWORD *)v9 != -2i64 && *(_QWORD *)(v9 + 8) == v7 )
      {
        while ( *(_QWORD *)(v9 + 8) != v7 || *(Scaleform::GFx::AS3::GASRefCountBase **)(v9 + 16) != this )
        {
          v8 = *(_QWORD *)v9;
          if ( *(_QWORD *)v9 == -1i64 )
            goto LABEL_17;
          v9 = (__int64)&pTable[2 * v8 + 1];
        }
        if ( v8 >= 0 )
        {
          v10 = &pTable[2 * v8 + 2];
          if ( v10 )
          {
            SizeMask = v10->SizeMask;
            if ( SizeMask )
            {
              *(_QWORD *)(SizeMask + 8) = 0i64;
              if ( (*(_DWORD *)SizeMask)-- == 1 )
                ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
              key = this;
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
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::RefCountBaseGC<328>::`vftable;
}

