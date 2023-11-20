// File Line: 44
// RVA: 0x9413D0
void __fastcall Scaleform::Render::Renderer2DImpl::Renderer2DImpl(Scaleform::Render::Renderer2DImpl *this, Scaleform::Render::HAL *hal)
{
  Scaleform::Render::HAL *v2; // rsi
  Scaleform::Render::Renderer2DImpl *v3; // rdi
  Scaleform::Render::ThreadCommandQueue *v4; // r8
  Scaleform::List<Scaleform::Render::ContextImpl::RenderNotify::ContextNode,Scaleform::Render::ContextImpl::RenderNotify::ContextNode> *v5; // rax
  Scaleform::Render::ContextImpl::RenderNotify::ServiceCommand *v6; // rax
  Scaleform::Render::HALNotify *v7; // rbx
  Scaleform::Render::GlyphCache *v8; // rbp
  Scaleform::MemoryHeap *v9; // rax
  Scaleform::MemoryHeap *v10; // rax
  signed __int64 v11; // r12
  Scaleform::MemoryHeap *v12; // rax
  Scaleform::List<Scaleform::Render::MatrixPoolImpl::HandlePage,Scaleform::Render::MatrixPoolImpl::HandlePageBase> *v13; // rax
  Scaleform::List<Scaleform::Render::MatrixPoolImpl::HandlePage,Scaleform::Render::MatrixPoolImpl::HandlePageBase> *v14; // rax
  Scaleform::List<Scaleform::Render::MatrixPoolImpl::DataPage,Scaleform::Render::MatrixPoolImpl::DataPage> *v15; // rax
  Scaleform::List<Scaleform::Render::ComplexMesh::UpdateNode,Scaleform::Render::ComplexMesh::UpdateNode> *v16; // rax
  signed __int64 v17; // rax
  Scaleform::MemoryHeap *v18; // r14
  Scaleform::Render::MeshKeyManager *v19; // rax
  Scaleform::Render::MeshKeyManager *v20; // rax
  Scaleform::Render::MeshKeyManager *v21; // r15
  Scaleform::Render::MeshKeyManager *v22; // rcx
  Scaleform::Render::GlyphCache *v23; // rax
  Scaleform::Render::GlyphCache *v24; // rax
  Scaleform::Render::GlyphCache *v25; // rcx
  signed __int64 v26; // [rsp+78h] [rbp+10h]

  v2 = hal;
  v3 = this;
  v4 = hal->pRTCommandQueue;
  this->vfptr = (Scaleform::Render::ContextImpl::RenderNotifyVtbl *)&Scaleform::Render::ContextImpl::RenderNotify::`vftable';
  v5 = &this->ActiveContextSet;
  v5->Root.pPrev = (Scaleform::Render::ContextImpl::RenderNotify::ContextNode *)v5;
  v5->Root.pNext = (Scaleform::Render::ContextImpl::RenderNotify::ContextNode *)v5;
  this->pRTCommandQueue = v4;
  v6 = &this->ServiceCommandInstance;
  v6->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  v6->RefCount = 1;
  v6->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  v6->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable';
  v6->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::ThreadCommand,2>::`vftable';
  v6->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ThreadCommand::`vftable';
  v6->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ContextImpl::RenderNotify::ServiceCommand::`vftable';
  v6->pNotify = (Scaleform::Render::ContextImpl::RenderNotify *)&this->vfptr;
  v7 = (Scaleform::Render::HALNotify *)&this->vfptr;
  v7->vfptr = (Scaleform::Render::HALNotifyVtbl *)&Scaleform::Render::HALNotify::`vftable';
  v8 = 0i64;
  v7->pNext = 0i64;
  v7->pPrev = 0i64;
  this->vfptr = (Scaleform::Render::ContextImpl::RenderNotifyVtbl *)&Scaleform::Render::Renderer2DImpl::`vftable'{for `Scaleform::Render::ContextImpl::RenderNotify'};
  v7->vfptr = (Scaleform::Render::HALNotifyVtbl *)&Scaleform::Render::Renderer2DImpl::`vftable'{for `Scaleform::Render::HALNotify'};
  _InterlockedExchangeAdd(&hal->RefCount, 1u);
  this->pHal.pObject = hal;
  v9 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  Scaleform::Render::MeshGenerator::MeshGenerator(&v3->MeshGen, v9);
  v10 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v3);
  Scaleform::Render::StrokeGenerator::StrokeGenerator(&v3->StrokeGen, v10);
  v3->Tolerances.Epsilon = 0.0000099999997;
  v3->Tolerances.CurveTolerance = 1.0;
  v3->Tolerances.CollinearityTolerance = 1.0;
  v3->Tolerances.IntersectionEpsilon = 0.001;
  v3->Tolerances.FillLowerScale = 0.70709997;
  v3->Tolerances.FillUpperScale = 1.4141999;
  v3->Tolerances.FillAliasedLowerScale = 0.5;
  v3->Tolerances.FillAliasedUpperScale = 2.0;
  v3->Tolerances.StrokeLowerScale = 0.99000001;
  v3->Tolerances.StrokeUpperScale = 1.01;
  v3->Tolerances.HintedStrokeLowerScale = 0.99900001;
  v3->Tolerances.HintedStrokeUpperScale = 1.001;
  v3->Tolerances.Scale9LowerScale = 0.995;
  v3->Tolerances.Scale9UpperScale = 1.005;
  v3->Tolerances.EdgeAAScale = 0.94999999;
  v3->Tolerances.MorphTolerance = 0.000099999997;
  v3->Tolerances.MinDet3D = 0.001;
  v3->Tolerances.MinScale3D = 0.050000001;
  v3->Tolerances.CurveRecursionLimit = 12;
  v11 = (signed __int64)&v3->FillManager;
  *(_QWORD *)v11 = &Scaleform::RefCountImplCore::`vftable';
  *(_DWORD *)(v11 + 8) = 1;
  *(_QWORD *)v11 = &Scaleform::RefCountImpl::`vftable';
  *(_QWORD *)v11 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,71>::`vftable';
  *(_QWORD *)v11 = &Scaleform::RefCountBase<Scaleform::Render::PrimitiveFillManager,71>::`vftable';
  *(_QWORD *)v11 = &Scaleform::Render::PrimitiveFillManager::`vftable';
  v3->FillManager.pHAL = v2;
  v3->FillManager.FillSet.pTable = 0i64;
  v3->FillManager.Gradients.pTable = 0i64;
  v12 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v3);
  v26 = (signed __int64)&v3->MPool;
  *(_QWORD *)v26 = &Scaleform::RefCountImplCore::`vftable';
  *(_DWORD *)(v26 + 8) = 1;
  *(_QWORD *)v26 = &Scaleform::RefCountImpl::`vftable';
  *(_QWORD *)v26 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,73>::`vftable';
  *(_QWORD *)v26 = &Scaleform::RefCountBase<Scaleform::Render::MatrixPoolImpl::MatrixPool,73>::`vftable';
  *(_QWORD *)v26 = &Scaleform::Render::MatrixPoolImpl::MatrixPool::`vftable';
  v3->MPool.pHeap = v12;
  v3->MPool.AllocatedSpace = 0i64;
  v3->MPool.DataPageCount = 0i64;
  v3->MPool.FreedSpace = 0i64;
  v3->MPool.HandleTable.pHeap = v12;
  v3->MPool.HandleTable.pPool = &v3->MPool;
  v13 = &v3->MPool.HandleTable.FullPages;
  v13->Root.pPrev = (Scaleform::Render::MatrixPoolImpl::HandlePageBase *)v13;
  v13->Root.pNext = (Scaleform::Render::MatrixPoolImpl::HandlePageBase *)v13;
  v14 = &v3->MPool.HandleTable.PartiallyFreePages;
  v14->Root.pPrev = (Scaleform::Render::MatrixPoolImpl::HandlePageBase *)v14;
  v14->Root.pNext = (Scaleform::Render::MatrixPoolImpl::HandlePageBase *)v14;
  v15 = &v3->MPool.DataPages;
  v15->Root.pPrev = (Scaleform::Render::MatrixPoolImpl::DataPage *)v15;
  v15->Root.pNext = (Scaleform::Render::MatrixPoolImpl::DataPage *)v15;
  v3->MPool.pAllocPage = 0i64;
  v3->MPool.pSqueezePage = 0i64;
  v3->MPool.pLastFreedPage = 0i64;
  v3->pMeshKeyManager.pObject = 0i64;
  v3->pGlyphCache.pObject = 0i64;
  v3->mGlyphCacheParam.TextureWidth = 1024;
  v3->mGlyphCacheParam.TextureHeight = 1024;
  v3->mGlyphCacheParam.NumTextures = 1;
  v3->mGlyphCacheParam.MaxSlotHeight = 48;
  v3->mGlyphCacheParam.SlotPadding = 2;
  v3->mGlyphCacheParam.TexUpdWidth = 256;
  v3->mGlyphCacheParam.TexUpdHeight = 512;
  v3->mGlyphCacheParam.MaxRasterScale = 1.0;
  v3->mGlyphCacheParam.MaxVectorCacheSize = 500;
  v3->mGlyphCacheParam.FauxItalicAngle = 0.25;
  v3->mGlyphCacheParam.FauxBoldRatio = 0.045000002;
  v3->mGlyphCacheParam.OutlineRatio = 0.0099999998;
  v3->mGlyphCacheParam.ShadowQuality = 1.0;
  *(_WORD *)&v3->mGlyphCacheParam.UseAutoFit = 257;
  v3->mGlyphCacheParam.FenceWaitOnFullCache = 1;
  v16 = &v3->mComplexMeshUpdateList;
  v16->Root.pPrev = (Scaleform::Render::ComplexMesh::UpdateNode *)v16;
  v16->Root.pNext = (Scaleform::Render::ComplexMesh::UpdateNode *)v16;
  *(_QWORD *)&v3->VP.BufferWidth = 0i64;
  *(_QWORD *)&v3->VP.Left = 0i64;
  v3->VP.Height = 1;
  v3->VP.Width = 1;
  *(_QWORD *)&v3->VP.ScissorWidth = 0i64;
  *(_QWORD *)&v3->VP.ScissorLeft = 0i64;
  v3->VP.Flags = 0;
  v17 = (signed __int64)&v3->VP.Flags;
  if ( v3 == (Scaleform::Render::Renderer2DImpl *)-3680i64 )
    v17 = 0i64;
  v3->RenderRoots.Root.pPrev = (Scaleform::Render::TreeCacheNode *)v17;
  v3->RenderRoots.Root.pNext = (Scaleform::Render::TreeCacheNode *)v17;
  v3->pPrev = v2->NotifyList.Root.pPrev;
  v3->pNext = (Scaleform::Render::HALNotify *)&v2->HALState;
  v2->NotifyList.Root.pPrev->pNext = v7;
  v2->NotifyList.Root.pPrev = v7;
  v18 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v3);
  v19 = (Scaleform::Render::MeshKeyManager *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                               Scaleform::Memory::pGlobalHeap,
                                               96i64);
  if ( v19 )
  {
    Scaleform::Render::MeshKeyManager::MeshKeyManager(v19, v18);
    v21 = v20;
  }
  else
  {
    v21 = 0i64;
  }
  v22 = v3->pMeshKeyManager.pObject;
  if ( v22 && !_InterlockedDecrement(&v22->RefCount) && v22 )
    v22->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v22->vfptr, 1u);
  v3->pMeshKeyManager.pObject = v21;
  v23 = (Scaleform::Render::GlyphCache *)v18->vfptr->Alloc(v18, 7320ui64, 0i64);
  if ( v23 )
  {
    Scaleform::Render::GlyphCache::GlyphCache(v23, v18);
    v8 = v24;
  }
  v25 = v3->pGlyphCache.pObject;
  if ( v25 && !_InterlockedDecrement(&v25->RefCount) && v25 )
    v25->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v25->vfptr, 1u);
  v3->pGlyphCache.pObject = v8;
  v8->pRenderer = v2;
  v8->pFillMan = (Scaleform::Render::PrimitiveFillManager *)v11;
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::Render::HAL *))v2->vfptr[4].__vecDelDtor)(v2) )
    Scaleform::Render::GlyphCache::initialize(v8);
}

// File Line: 58
// RVA: 0x94C6B0
void __fastcall Scaleform::Render::Renderer2DImpl::~Renderer2DImpl(Scaleform::Render::Renderer2DImpl *this)
{
  Scaleform::Render::Renderer2DImpl *v1; // rdi
  Scaleform::Render::GlyphCache *v2; // rcx
  Scaleform::Render::MeshKeyManager *v3; // rcx
  Scaleform::Render::PrimitiveFillManager *v4; // rbx
  Scaleform::Render::HAL *v5; // rcx

  v1 = this;
  this->vfptr = (Scaleform::Render::ContextImpl::RenderNotifyVtbl *)&Scaleform::Render::Renderer2DImpl::`vftable'{for `Scaleform::Render::ContextImpl::RenderNotify'};
  this->vfptr = (Scaleform::Render::HALNotifyVtbl *)&Scaleform::Render::Renderer2DImpl::`vftable'{for `Scaleform::Render::HALNotify'};
  Scaleform::Render::ContextImpl::RenderNotify::ReleaseAllContextData((Scaleform::Render::ContextImpl::RenderNotify *)&this->vfptr);
  Scaleform::Render::MeshKeyManager::DestroyAllKeys(v1->pMeshKeyManager.pObject);
  v1->pPrev->pNext = v1->pNext;
  v1->pNext->pPrev = v1->pPrev;
  v1->pPrev = (Scaleform::Render::HALNotify *)-1i64;
  v1->pNext = (Scaleform::Render::HALNotify *)-1i64;
  v2 = v1->pGlyphCache.pObject;
  if ( v2 && !_InterlockedDecrement(&v2->RefCount) && v2 )
    v2->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v2->vfptr, 1u);
  v3 = v1->pMeshKeyManager.pObject;
  if ( v3 && !_InterlockedDecrement(&v3->RefCount) && v3 )
    v3->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, 1u);
  Scaleform::Render::MatrixPoolImpl::MatrixPool::~MatrixPool(&v1->MPool);
  v4 = &v1->FillManager;
  v4->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::PrimitiveFillManager::`vftable';
  Scaleform::HashSet<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::GradientImage *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor>>::~HashSet<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::GradientImage *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor>>((Scaleform::HashSet<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> > *)&v1->FillManager.Gradients);
  Scaleform::HashSet<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::GradientImage *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor>>::~HashSet<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::GradientImage *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor>>((Scaleform::HashSet<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> > *)&v1->FillManager.FillSet);
  v4->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  v1->StrokeGen.mPath.vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::TessBase::`vftable';
  v1->StrokeGen.mStrokeSorter.vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::TessBase::`vftable';
  v1->StrokeGen.mStroker.vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::TessBase::`vftable';
  Scaleform::Render::LinearHeap::ClearAndRelease(&v1->StrokeGen.Heap2);
  Scaleform::Render::LinearHeap::ClearAndRelease(&v1->StrokeGen.Heap1);
  Scaleform::Render::MeshGenerator::~MeshGenerator(&v1->MeshGen);
  v5 = v1->pHal.pObject;
  if ( v5 && _InterlockedExchangeAdd(&v5->RefCount, 0xFFFFFFFF) == 1 && v5 )
    v5->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v5->vfptr, 1u);
  v1->vfptr = (Scaleform::Render::HALNotifyVtbl *)&Scaleform::Render::HALNotify::`vftable';
  v1->vfptr = (Scaleform::Render::ContextImpl::RenderNotifyVtbl *)&Scaleform::Render::ContextImpl::RenderNotify::`vftable';
  Scaleform::Render::ContextImpl::RenderNotify::ReleaseAllContextData((Scaleform::Render::ContextImpl::RenderNotify *)&v1->vfptr);
  v1->ServiceCommandInstance.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
}

// File Line: 71
// RVA: 0x95A780
__int64 __fastcall Scaleform::Render::Renderer2DImpl::BeginFrame(Scaleform::Render::Renderer2DImpl *this)
{
  Scaleform::Render::Renderer2DImpl *v1; // rdi
  Scaleform::Render::GlyphCache *v2; // rbx
  Scaleform::Render::HAL *v3; // rcx
  Scaleform::Render::FontCacheHandleManager *v4; // rcx

  v1 = this;
  Scaleform::Render::MeshKeyManager::ProcessKillList(this->pMeshKeyManager.pObject);
  v2 = v1->pGlyphCache.pObject;
  if ( v2 )
  {
    if ( !v2->pFontHandleManager.pObject )
    {
      v3 = v2->pRenderer;
      if ( !v3 || !((unsigned __int8 (*)(void))v3->vfptr[4].__vecDelDtor)() )
        return ((__int64 (*)(void))v1->pHal.pObject->vfptr[5].__vecDelDtor)();
      Scaleform::Render::GlyphCache::initialize(v2);
    }
    v4 = v2->pFontHandleManager.pObject;
    if ( v4 )
      Scaleform::Render::FontCacheHandleManager::ProcessKillList(v4);
  }
  return ((__int64 (*)(void))v1->pHal.pObject->vfptr[5].__vecDelDtor)();
}

// File Line: 125
// RVA: 0x96EC70
void __fastcall Scaleform::Render::Renderer2DImpl::Draw(Scaleform::Render::Renderer2DImpl *this, Scaleform::Render::TreeRoot *pnode)
{
  Scaleform::Render::TreeRoot *v2; // r15
  Scaleform::Render::Renderer2DImpl *v3; // rsi
  Scaleform::Render::TreeCacheRoot *v4; // rbx
  unsigned __int64 v5; // r12
  unsigned __int64 v6; // rdx
  unsigned __int64 v7; // r14
  unsigned __int64 v8; // r13
  Scaleform::Render::Viewport *v9; // rdi
  int v10; // er10
  int v11; // er8
  Scaleform::Render::HAL *v12; // rcx
  Scaleform::Render::MatrixState *v13; // rax
  int v14; // er9
  int v15; // edx
  char v16; // bp
  float v17; // xmm6_4
  float v18; // xmm7_4
  float v19; // xmm8_4
  float v20; // xmm9_4
  int v21; // eax
  int v22; // ebx
  Scaleform::Render::TreeCacheRoot *v23; // rax
  Scaleform::Render::TreeCacheRoot *v24; // rax
  signed int v25; // eax
  signed int v26; // ecx
  signed int v27; // eax
  signed int v28; // ecx
  Scaleform::Render::Rect<int> prect; // [rsp+38h] [rbp-A0h]
  __int128 v30; // [rsp+50h] [rbp-88h]
  int v31; // [rsp+E8h] [rbp+10h]
  Scaleform::Render::TreeCacheRoot *v32; // [rsp+F0h] [rbp+18h]

  v2 = pnode;
  v3 = this;
  v4 = (Scaleform::Render::TreeCacheRoot *)pnode->pRenderer;
  v5 = (unsigned __int64)pnode & 0xFFFFFFFFFFFFF000ui64;
  v6 = (unsigned __int128)((signed __int64)((signed __int64)&pnode[-1]
                                          - ((unsigned __int64)pnode & 0xFFFFFFFFFFFFF000ui64))
                         * (signed __int128)5270498306774157605i64) >> 64;
  v7 = (v6 >> 63) + ((signed __int64)v6 >> 4);
  v8 = *(_QWORD *)(*(_QWORD *)(v5 + 40) + 8 * ((v6 >> 63) + (unsigned int)((signed __int64)v6 >> 4)) + 40) & 0xFFFFFFFFFFFFFFFEui64;
  v9 = (Scaleform::Render::Viewport *)(v8 + 160);
  if ( *(_DWORD *)(v8 + 160) && *(_DWORD *)(v8 + 164) )
  {
    v10 = *(_DWORD *)(v8 + 172);
    v11 = *(_DWORD *)(v8 + 168);
    v12 = this->pHal.pObject;
    v13 = v12->Matrices.pObject;
    if ( ((*(_DWORD *)(v8 + 200) & 0x30) - 16) & 0xFFFFFFDF )
    {
      v14 = *(_DWORD *)(v8 + 180);
      v15 = *(_DWORD *)(v8 + 176);
    }
    else
    {
      v14 = *(_DWORD *)(v8 + 176);
      v15 = *(_DWORD *)(v8 + 180);
    }
    v13->ViewRectOriginal.x1 = v11;
    v13->ViewRectOriginal.y1 = v10;
    v13->ViewRectOriginal.x2 = v11 + v15;
    v13->ViewRectOriginal.y2 = v10 + v14;
    v12->Matrices.pObject->UVPOChanged = 1;
  }
  else
  {
    v9 = &this->VP;
  }
  v30 = 0i64;
  *(_QWORD *)&prect.x1 = 0i64;
  *(_QWORD *)&prect.x2 = 0i64;
  if ( Scaleform::Render::Viewport::GetClippedRect<int>(v9, &prect, 1) )
  {
    v17 = (float)(prect.y2 - v9->Top);
    v18 = (float)(prect.x2 - v9->Left);
    v19 = (float)(prect.y1 - v9->Top);
    v20 = (float)(prect.x1 - v9->Left);
    v16 = 1;
  }
  else
  {
    v16 = 0;
    v17 = *((float *)&v30 + 3);
    v18 = *((float *)&v30 + 2);
    v19 = *((float *)&v30 + 1);
    v20 = *(float *)&v30;
  }
  if ( v9->BufferWidth && v9->BufferHeight )
  {
    if ( v4 )
    {
      if ( v16 == v4->ViewValid
        && v20 == v4->ViewCullRect.x1
        && v18 == v4->ViewCullRect.x2
        && v19 == v4->ViewCullRect.y1
        && v17 == v4->ViewCullRect.y2 )
      {
        goto LABEL_32;
      }
      v4->ViewValid = v16;
      v4->ViewCullRect.x1 = v20;
      v4->ViewCullRect.y1 = v19;
      v4->ViewCullRect.x2 = v18;
      v4->ViewCullRect.y2 = v17;
      v27 = 1;
      v28 = v4->UpdateFlags;
      if ( v28 >= 0 )
      {
        v4->pNextUpdate = v4->pUpdateList;
        v4->pUpdateList = (Scaleform::Render::TreeCacheNode *)&v4->vfptr;
        v27 = -2147483647;
      }
      v4->UpdateFlags = v28 | v27;
LABEL_31:
      Scaleform::Render::TreeCacheRoot::UpdateTreeData(v4);
LABEL_32:
      if ( v16 )
        Scaleform::Render::TreeCacheRoot::Draw(v4);
      return;
    }
    v21 = *(_WORD *)(v8 + 10) & 0xC;
    if ( !v21 )
      v21 = 4;
    v22 = v21 | *(_BYTE *)(v8 + 10) & 1;
    v31 = 71;
    v23 = (Scaleform::Render::TreeCacheRoot *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                Scaleform::Memory::pGlobalHeap,
                                                v3,
                                                496ui64,
                                                (Scaleform::AllocInfo *)&v31);
    v32 = v23;
    if ( v23 )
    {
      Scaleform::Render::TreeCacheRoot::TreeCacheRoot(v23, v3, v3->pHal.pObject, v22, v2);
      v4 = v24;
    }
    else
    {
      v4 = 0i64;
    }
    if ( v4 )
    {
      v2->pRenderer = (Scaleform::Render::TreeCacheNode *)&v4->vfptr;
      v4->pPrev = v3->RenderRoots.Root.pPrev;
      v4->pNext = (Scaleform::Render::TreeCacheNode *)&v3->VP.Flags;
      v3->RenderRoots.Root.pPrev->pNext = (Scaleform::Render::TreeCacheNode *)&v4->vfptr;
      v3->RenderRoots.Root.pPrev = (Scaleform::Render::TreeCacheNode *)&v4->vfptr;
      v4->ViewValid = v16;
      v4->ViewCullRect.x1 = v20;
      v4->ViewCullRect.y1 = v19;
      v4->ViewCullRect.x2 = v18;
      v4->ViewCullRect.y2 = v17;
      v4->vfptr->UpdateChildSubtree(
        (Scaleform::Render::TreeCacheNode *)&v4->vfptr,
        (Scaleform::Render::TreeNode::NodeData *)(*(_QWORD *)(*(_QWORD *)(v5 + 40) + 8i64 * (unsigned int)v7 + 40) & 0xFFFFFFFFFFFFFFFEui64),
        1u);
      v25 = 16777219;
      v26 = v4->UpdateFlags;
      if ( v26 >= 0 )
      {
        v4->pNextUpdate = v4->pUpdateList;
        v4->pUpdateList = (Scaleform::Render::TreeCacheNode *)&v4->vfptr;
        v25 = -2130706429;
      }
      v4->UpdateFlags = v25 | v26;
      Scaleform::Render::TreeCacheRoot::ChainUpdatesByDepth(v4);
      goto LABEL_31;
    }
  }
}

// File Line: 219
// RVA: 0x971100
void __fastcall Scaleform::Render::Renderer2DImpl::EntryDestroy(Scaleform::Render::Renderer2DImpl *this, Scaleform::Render::ContextImpl::Entry *p)
{
  Scaleform::Render::TreeCacheNode *v2; // rcx
  Scaleform::Render::ContextImpl::Entry *v3; // rbx

  v2 = p->pRenderer;
  v3 = p;
  if ( v2 )
  {
    v2->vfptr->__vecDelDtor(v2, 1u);
    v3->pRenderer = 0i64;
  }
}

// File Line: 231
// RVA: 0x971130
void __fastcall Scaleform::Render::Renderer2DImpl::EntryFlush(Scaleform::Render::Renderer2DImpl *this, Scaleform::Render::ContextImpl::Entry *p)
{
  this->vfptr->EntryDestroy((Scaleform::Render::ContextImpl::RenderNotify *)this, p);
}

// File Line: 239
// RVA: 0x970E30
void __fastcall Scaleform::Render::Renderer2DImpl::EntryChanges(Scaleform::Render::Renderer2DImpl *this, Scaleform::Render::ContextImpl::Context *context, Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63> *cb, bool forceUpdateImages)
{
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63>::Page *v4; // r15
  bool v5; // r12
  Scaleform::Render::ContextImpl::Context *v6; // r13
  Scaleform::Render::Renderer2DImpl *v7; // rdi
  unsigned int v8; // er14
  _DWORD *v9; // rdi
  __int64 v10; // rbx
  int v11; // eax
  __int64 v12; // rbp
  signed int v13; // esi
  unsigned __int64 v14; // rdx
  int v15; // eax
  int v16; // eax
  __int64 v17; // rcx
  int v18; // ecx
  __int64 v19; // rcx
  signed int v20; // eax
  Scaleform::Render::TreeCacheRoot *v21; // rbx
  signed __int64 v22; // rdi
  signed __int64 v23; // rax
  Scaleform::Render::Renderer2DImpl *v24; // [rsp+60h] [rbp+8h]
  Scaleform::Render::ContextImpl::Context *v25; // [rsp+68h] [rbp+10h]

  v25 = context;
  v24 = this;
  v4 = cb->pPages;
  v5 = forceUpdateImages;
  v6 = context;
  v7 = this;
  if ( cb->pPages )
  {
    do
    {
      v8 = 0;
      if ( v4->Count )
      {
        do
        {
          v9 = (_DWORD *)((char *)v4 + 16 * (v8 + 1i64));
          if ( *(_QWORD *)v9 )
          {
            v10 = *(_QWORD *)(*(_QWORD *)v9 + 24i64);
            if ( v10 )
            {
              if ( v9[2] & 0x3730 )
                (*(void (__fastcall **)(__int64))(*(_QWORD *)v10 + 8i64))(v10);
              v11 = v9[2];
              v12 = *(_QWORD *)(v10 + 24);
              if ( v11 & 0x7E208C )
              {
                v13 = 0;
                if ( v11 & 4 )
                {
                  v13 = 0x1000000;
                  *(_WORD *)(v10 + 74) ^= (*(_WORD *)(v10 + 74) ^ *(_WORD *)((*(_QWORD *)(*(_QWORD *)((*(_QWORD *)(v10 + 32) & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                                                                        + 8
                                                                                        * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)(*(_QWORD *)(v10 + 32) - (*(_QWORD *)(v10 + 32) & 0xFFFFFFFFFFFFF000ui64) - 56) * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                                                                         + ((unsigned __int64)((unsigned __int128)((signed __int64)(*(_QWORD *)(v10 + 32) - (*(_QWORD *)(v10 + 32) & 0xFFFFFFFFFFFFF000ui64) - 56) * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                                                                        + 40) & 0xFFFFFFFFFFFFFFFEui64)
                                                                           + 10)) & 1;
                }
                if ( v9[2] & 0x40000 )
                {
                  v14 = (unsigned __int128)((signed __int64)(*(_QWORD *)(v10 + 32)
                                                           - (*(_QWORD *)(v10 + 32) & 0xFFFFFFFFFFFFF000ui64)
                                                           - 56)
                                          * (signed __int128)5270498306774157605i64) >> 64;
                  Scaleform::Render::TreeCacheNode::updateMaskCache(
                    (Scaleform::Render::TreeCacheNode *)v10,
                    (Scaleform::Render::TreeNode::NodeData *)(*(_QWORD *)(*(_QWORD *)((*(_QWORD *)(v10 + 32) & 0xFFFFFFFFFFFFF000ui64)
                                                                                    + 0x28)
                                                                        + 8
                                                                        * ((unsigned int)((signed __int64)v14 >> 4)
                                                                         + (v14 >> 63))
                                                                        + 40) & 0xFFFFFFFFFFFFFFFEui64),
                    *(_WORD *)(v10 + 72) + 1,
                    0);
                }
                v15 = v9[2];
                if ( v15 & 8 )
                  v13 |= 0x2000000u;
                v16 = v15 & 0x7E0000;
                if ( v16 )
                {
                  *(_DWORD *)(v10 + 76) |= v16;
                  v13 |= 0x1000000u;
                }
                if ( v9[2] & 0x2000 )
                  v13 |= 0x1000000u;
                if ( !v12 )
                  goto LABEL_33;
                if ( v13 )
                {
                  v17 = *(_QWORD *)(v10 + 48);
                  if ( v17 )
                  {
                    if ( *(_DWORD *)(v17 + 76) >= 0 )
                    {
                      v13 |= 0x80000000;
                      *(_QWORD *)(v17 + 80) = *(_QWORD *)(v12 + 192);
                      *(_QWORD *)(v12 + 192) = v17;
                    }
                    *(_DWORD *)(v17 + 76) |= v13;
                  }
                }
              }
              if ( v12 )
              {
                v18 = v9[2] & 0x12003;
                if ( v18 )
                {
                  if ( *(_DWORD *)(v10 + 76) >= 0 )
                  {
                    v18 |= 0x80000000;
                    *(_QWORD *)(v10 + 80) = *(_QWORD *)(v12 + 192);
                    *(_QWORD *)(v12 + 192) = v10;
                  }
                  *(_DWORD *)(v10 + 76) |= v18;
                  if ( v9[2] & 1 && (*(_BYTE *)(v10 + 74) >> 5) & 1 )
                  {
                    v19 = *(_QWORD *)(v10 + 48);
                    v20 = 33554433;
                    if ( *(_DWORD *)(v19 + 76) >= 0 )
                    {
                      *(_QWORD *)(v19 + 80) = *(_QWORD *)(v12 + 192);
                      *(_QWORD *)(v12 + 192) = v19;
                      v20 = -2113929215;
                    }
                    *(_DWORD *)(v19 + 76) |= v20;
                  }
                }
              }
            }
          }
LABEL_33:
          ++v8;
        }
        while ( v8 < v4->Count );
      }
      v4 = v4->pNext;
    }
    while ( v4 );
    v6 = v25;
    v7 = v24;
  }
  if ( v5 )
    Scaleform::Render::Renderer2DImpl::UpdateComplexMeshes(v7);
  v21 = (Scaleform::Render::TreeCacheRoot *)v7->RenderRoots.Root.pNext;
  v22 = (signed __int64)&v7->RenderRoots;
  while ( 1 )
  {
    v23 = v22 ? v22 - 8 : 0i64;
    if ( v21 == (Scaleform::Render::TreeCacheRoot *)v23 )
      break;
    if ( v5
      && *(Scaleform::Render::ContextImpl::Context **)(*(_QWORD *)(((_QWORD)v21->pNode & 0xFFFFFFFFFFFFF000ui64) + 0x18)
                                                     + 16i64) == v6 )
    {
      v21->vfptr->forceUpdateImages((Scaleform::Render::TreeCacheNode *)&v21->vfptr);
    }
    Scaleform::Render::TreeCacheRoot::ChainUpdatesByDepth(v21);
    Scaleform::Render::TreeCacheRoot::UpdateTreeData(v21);
    v21 = (Scaleform::Render::TreeCacheRoot *)v21->pNext;
  }
}

// File Line: 401
// RVA: 0x99CAE0
void __fastcall Scaleform::Render::Renderer2DImpl::OnHALEvent(Scaleform::Render::Renderer2DImpl *this, Scaleform::Render::HALNotifyType type)
{
  Scaleform::Render::Renderer2DImpl *v2; // rbx
  __int32 v3; // edx
  int v4; // edx
  Scaleform::Render::GlyphCache *v5; // rdi
  Scaleform::Render::ThreadCommandQueue *v6; // rcx

  v2 = this;
  if ( type == HAL_Initialize )
    goto LABEL_12;
  v3 = type - 1;
  if ( !v3 )
  {
    Scaleform::Render::ContextImpl::RenderNotify::ReleaseAllContextData((Scaleform::Render::ContextImpl::RenderNotify *)&this[-1].VP.Left);
    Scaleform::Render::MeshKeyManager::DestroyAllKeys((Scaleform::Render::MeshKeyManager *)v2->MPool.HandleTable.PartiallyFreePages.Root.pPrev);
    Scaleform::Render::GlyphCache::Destroy((Scaleform::Render::GlyphCache *)v2->MPool.HandleTable.PartiallyFreePages.Root.pNext);
    return;
  }
  v4 = v3 - 1;
  if ( !v4 )
  {
    Scaleform::Render::GlyphCache::Destroy((Scaleform::Render::GlyphCache *)this->MPool.HandleTable.PartiallyFreePages.Root.pNext);
    return;
  }
  if ( v4 == 1 )
  {
LABEL_12:
    v5 = (Scaleform::Render::GlyphCache *)this->MPool.HandleTable.PartiallyFreePages.Root.pNext;
    v6 = this->pRTCommandQueue;
    v5->pFillMan = (Scaleform::Render::PrimitiveFillManager *)&v2->Tolerances.FillAliasedLowerScale;
    v5->pRenderer = (Scaleform::Render::HAL *)v6;
    if ( ((unsigned __int8 (*)(void))v6->vfptr[1].PushThreadCommand)() )
      Scaleform::Render::GlyphCache::initialize(v5);
  }
}

// File Line: 433
// RVA: 0x9BDB90
void __fastcall Scaleform::Render::Renderer2DImpl::UpdateComplexMeshes(Scaleform::Render::Renderer2DImpl *this)
{
  Scaleform::Render::Renderer2DImpl *v1; // rdi
  _RTL_CRITICAL_SECTION *v2; // rbx
  Scaleform::Render::Renderer2DImpl *v3; // r15
  signed __int64 v4; // r13
  signed __int64 v5; // rbp
  Scaleform::Render::TextureManager *textureManager; // r12
  unsigned int v7; // er14
  __int64 v8; // rdi
  unsigned int *v9; // rdi
  int pDtor; // ST20_4
  int v11; // ST20_4
  Scaleform::Render::PrimitiveFill *v12; // rax
  Scaleform::Render::PrimitiveFill *v13; // rsi
  __int64 v14; // rcx
  bool v15; // zf
  char ptr; // [rsp+58h] [rbp-90h]
  Scaleform::Ptr<Scaleform::Render::Image> gradientImg1; // [rsp+60h] [rbp-88h]
  Scaleform::Render::FillData fd0; // [rsp+70h] [rbp-78h]
  Scaleform::Render::FillData fd1; // [rsp+90h] [rbp-58h]
  signed __int64 v20; // [rsp+F0h] [rbp+8h]
  Scaleform::Lock *v21; // [rsp+F8h] [rbp+10h]

  v1 = this;
  v2 = &this->pMeshKeyManager.pObject->KeySetLock.cs;
  v21 = &this->pMeshKeyManager.pObject->KeySetLock;
  EnterCriticalSection(v2);
  v3 = (Scaleform::Render::Renderer2DImpl *)v1->mComplexMeshUpdateList.Root.pNext;
  v4 = (signed __int64)&v1->mComplexMeshUpdateList;
  v20 = (signed __int64)&v1->mComplexMeshUpdateList;
  if ( v3 != (Scaleform::Render::Renderer2DImpl *)&v1->mComplexMeshUpdateList )
  {
    do
    {
      v5 = (signed __int64)&v3[-1].MPool.pLastFreedPage;
      if ( ((unsigned __int8 (*)(void))v3[-1].mComplexMeshUpdateList.Root.pNext->pPrev[6].pNext)() )
      {
        textureManager = (Scaleform::Render::TextureManager *)(*(__int64 (**)(void))(**(_QWORD **)(*(_QWORD *)(v5 + 80)
                                                                                                 + 80i64)
                                                                                   + 488i64))();
        v7 = 0;
        if ( *(_QWORD *)(v5 + 248) )
        {
          v8 = 0i64;
          do
          {
            v9 = (unsigned int *)(*(_QWORD *)(v5 + 240) + 56 * v8);
            if ( *(_QWORD *)v9 )
            {
              fd0.Type = 3;
              fd0.Color = 0;
              fd0.PrimFill = 4;
              fd0.FillMode.Fill = 0;
              fd0.pVFormat = &Scaleform::Render::VertexXY16iCF32::Format;
              fd1.Type = 3;
              fd1.Color = 0;
              fd1.PrimFill = 4;
              fd1.FillMode.Fill = 0;
              fd1.pVFormat = &Scaleform::Render::VertexXY16iCF32::Format;
              `eh vector constructor iterator'(
                &ptr,
                8ui64,
                2,
                (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>);
              pDtor = *(_DWORD *)(v5 + 152);
              (*(void (__fastcall **)(_QWORD, Scaleform::Render::FillData *, _QWORD, _QWORD))(**(_QWORD **)(v5 + 88)
                                                                                            + 88i64))(
                *(_QWORD *)(v5 + 88),
                &fd0,
                *(unsigned int *)(v5 + 148),
                v9[11]);
              v11 = *(_DWORD *)(v5 + 152);
              (*(void (__fastcall **)(_QWORD, Scaleform::Render::FillData *, _QWORD, _QWORD))(**(_QWORD **)(v5 + 88)
                                                                                            + 88i64))(
                *(_QWORD *)(v5 + 88),
                &fd1,
                *(unsigned int *)(v5 + 148),
                v9[12]);
              v12 = Scaleform::Render::PrimitiveFillManager::CreateMergedFill(
                      *(Scaleform::Render::PrimitiveFillManager **)(v5 + 176),
                      v9[13],
                      *(Scaleform::Render::VertexFormat **)(*(_QWORD *)v9 + 48i64),
                      &fd0,
                      &fd1,
                      (Scaleform::Ptr<Scaleform::Render::Image> *)&ptr,
                      &gradientImg1,
                      textureManager,
                      *(float *)(v5 + 144));
              v13 = v12;
              if ( v12 )
              {
                ++v12->RefCount;
                v14 = *(_QWORD *)v9;
                if ( *(_QWORD *)v9 )
                {
                  v15 = (*(_DWORD *)(v14 + 8))-- == 1;
                  if ( v15 )
                    (**(void (__fastcall ***)(__int64, signed __int64))v14)(v14, 1i64);
                }
                *(_QWORD *)v9 = v13;
                v15 = v13->RefCount-- == 1;
                if ( v15 )
                  v13->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v13->vfptr, 1u);
              }
              `eh vector destructor iterator'(
                &ptr,
                8ui64,
                2,
                (void (__fastcall *)(void *))ARefPtr<SSClassDescBase>::~ARefPtr<SSClassDescBase>);
            }
            v8 = ++v7;
          }
          while ( (unsigned __int64)v7 < *(_QWORD *)(v5 + 248) );
          v4 = v20;
        }
        Scaleform::Render::ComplexMesh::updateFillMatrixCache(
          (Scaleform::Render::ComplexMesh *)&v3[-1].MPool.pLastFreedPage,
          (Scaleform::Render::Matrix2x4<float> *)(v5 + 208));
      }
      v3 = (Scaleform::Render::Renderer2DImpl *)v3->ActiveContextSet.Root.pPrev;
    }
    while ( v3 != (Scaleform::Render::Renderer2DImpl *)v4 );
    v2 = &v21->cs;
  }
  LeaveCriticalSection(v2);
}

