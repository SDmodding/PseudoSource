// File Line: 44
// RVA: 0x9413D0
void __fastcall Scaleform::Render::Renderer2DImpl::Renderer2DImpl(
        Scaleform::Render::Renderer2DImpl *this,
        Scaleform::Render::HAL *hal)
{
  Scaleform::Render::ThreadCommandQueue *pRTCommandQueue; // r8
  Scaleform::Render::HALNotify *v5; // rbx
  Scaleform::Render::GlyphCache *v6; // rbp
  Scaleform::MemoryHeap *v7; // rax
  Scaleform::MemoryHeap *v8; // rax
  Scaleform::MemoryHeap *v9; // rax
  unsigned int *p_Flags; // rax
  Scaleform::MemoryHeap *v11; // r14
  Scaleform::Render::MeshKeyManager *v12; // rax
  Scaleform::Render::MeshKeyManager *v13; // rax
  Scaleform::Render::MeshKeyManager *v14; // r15
  Scaleform::Render::MeshKeyManager *pObject; // rcx
  Scaleform::Render::GlyphCache *v16; // rax
  Scaleform::Render::GlyphCache *v17; // rax
  Scaleform::Render::GlyphCache *v18; // rcx

  pRTCommandQueue = hal->pRTCommandQueue;
  this->Scaleform::Render::ContextImpl::RenderNotify::vfptr = (Scaleform::Render::ContextImpl::RenderNotifyVtbl *)&Scaleform::Render::ContextImpl::RenderNotify::`vftable;
  this->ActiveContextSet.Root.Scaleform::Render::ContextImpl::RenderNotify::pPrev = (Scaleform::Render::ContextImpl::RenderNotify::ContextNode *)&this->ActiveContextSet;
  this->ActiveContextSet.Root.pNext = (Scaleform::Render::ContextImpl::RenderNotify::ContextNode *)&this->ActiveContextSet;
  this->pRTCommandQueue = pRTCommandQueue;
  this->ServiceCommandInstance.Scaleform::Render::ContextImpl::RenderNotify::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->ServiceCommandInstance.RefCount = 1;
  this->ServiceCommandInstance.Scaleform::Render::ContextImpl::RenderNotify::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->ServiceCommandInstance.Scaleform::Render::ContextImpl::RenderNotify::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->ServiceCommandInstance.Scaleform::Render::ContextImpl::RenderNotify::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::ThreadCommand,2>::`vftable;
  this->ServiceCommandInstance.Scaleform::Render::ContextImpl::RenderNotify::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ThreadCommand::`vftable;
  this->ServiceCommandInstance.Scaleform::Render::ContextImpl::RenderNotify::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ContextImpl::RenderNotify::ServiceCommand::`vftable;
  this->ServiceCommandInstance.pNotify = this;
  v5 = &this->Scaleform::Render::HALNotify;
  this->Scaleform::Render::HALNotify::vfptr = (Scaleform::Render::HALNotifyVtbl *)&Scaleform::Render::HALNotify::`vftable;
  v6 = 0i64;
  this->pNext = 0i64;
  this->pPrev = 0i64;
  this->Scaleform::Render::ContextImpl::RenderNotify::vfptr = (Scaleform::Render::ContextImpl::RenderNotifyVtbl *)&Scaleform::Render::Renderer2DImpl::`vftable{for `Scaleform::Render::ContextImpl::RenderNotify};
  this->Scaleform::Render::HALNotify::vfptr = (Scaleform::Render::HALNotifyVtbl *)&Scaleform::Render::Renderer2DImpl::`vftable{for `Scaleform::Render::HALNotify};
  _InterlockedExchangeAdd(&hal->RefCount, 1u);
  this->pHal.pObject = hal;
  v7 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  Scaleform::Render::MeshGenerator::MeshGenerator(&this->MeshGen, v7);
  v8 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  Scaleform::Render::StrokeGenerator::StrokeGenerator(&this->StrokeGen, v8);
  this->Tolerances.Epsilon = 0.0000099999997;
  this->Tolerances.CurveTolerance = 1.0;
  this->Tolerances.CollinearityTolerance = 1.0;
  this->Tolerances.IntersectionEpsilon = 0.001;
  this->Tolerances.FillLowerScale = 0.70709997;
  this->Tolerances.FillUpperScale = 1.4141999;
  this->Tolerances.FillAliasedLowerScale = 0.5;
  this->Tolerances.FillAliasedUpperScale = 2.0;
  this->Tolerances.StrokeLowerScale = 0.99000001;
  this->Tolerances.StrokeUpperScale = 1.01;
  this->Tolerances.HintedStrokeLowerScale = 0.99900001;
  this->Tolerances.HintedStrokeUpperScale = 1.001;
  this->Tolerances.Scale9LowerScale = 0.995;
  this->Tolerances.Scale9UpperScale = 1.005;
  this->Tolerances.EdgeAAScale = 0.94999999;
  this->Tolerances.MorphTolerance = 0.000099999997;
  this->Tolerances.MinDet3D = 0.001;
  this->Tolerances.MinScale3D = 0.050000001;
  this->Tolerances.CurveRecursionLimit = 12;
  this->FillManager.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->FillManager.RefCount = 1;
  this->FillManager.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->FillManager.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,71>::`vftable;
  this->FillManager.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::PrimitiveFillManager,71>::`vftable;
  this->FillManager.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::PrimitiveFillManager::`vftable;
  this->FillManager.pHAL = hal;
  this->FillManager.FillSet.pTable = 0i64;
  this->FillManager.Gradients.pTable = 0i64;
  v9 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  this->MPool.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->MPool.RefCount = 1;
  this->MPool.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->MPool.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,73>::`vftable;
  this->MPool.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::MatrixPoolImpl::MatrixPool,73>::`vftable;
  this->MPool.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::MatrixPoolImpl::MatrixPool::`vftable;
  this->MPool.pHeap = v9;
  this->MPool.AllocatedSpace = 0i64;
  this->MPool.DataPageCount = 0i64;
  this->MPool.FreedSpace = 0i64;
  this->MPool.HandleTable.pHeap = v9;
  this->MPool.HandleTable.pPool = &this->MPool;
  this->MPool.HandleTable.FullPages.Root.pPrev = (Scaleform::Render::MatrixPoolImpl::HandlePageBase *)&this->MPool.HandleTable.FullPages;
  this->MPool.HandleTable.FullPages.Root.pNext = (Scaleform::Render::MatrixPoolImpl::HandlePageBase *)&this->MPool.HandleTable.FullPages;
  this->MPool.HandleTable.PartiallyFreePages.Root.pPrev = (Scaleform::Render::MatrixPoolImpl::HandlePageBase *)&this->MPool.HandleTable.PartiallyFreePages;
  this->MPool.HandleTable.PartiallyFreePages.Root.pNext = (Scaleform::Render::MatrixPoolImpl::HandlePageBase *)&this->MPool.HandleTable.PartiallyFreePages;
  this->MPool.DataPages.Root.pPrev = (Scaleform::Render::MatrixPoolImpl::DataPage *)&this->MPool.DataPages;
  this->MPool.DataPages.Root.pNext = (Scaleform::Render::MatrixPoolImpl::DataPage *)&this->MPool.DataPages;
  this->MPool.pAllocPage = 0i64;
  this->MPool.pSqueezePage = 0i64;
  this->MPool.pLastFreedPage = 0i64;
  this->pMeshKeyManager.pObject = 0i64;
  this->pGlyphCache.pObject = 0i64;
  this->mGlyphCacheParam.TextureWidth = 1024;
  this->mGlyphCacheParam.TextureHeight = 1024;
  this->mGlyphCacheParam.NumTextures = 1;
  this->mGlyphCacheParam.MaxSlotHeight = 48;
  this->mGlyphCacheParam.SlotPadding = 2;
  this->mGlyphCacheParam.TexUpdWidth = 256;
  this->mGlyphCacheParam.TexUpdHeight = 512;
  this->mGlyphCacheParam.MaxRasterScale = 1.0;
  this->mGlyphCacheParam.MaxVectorCacheSize = 500;
  this->mGlyphCacheParam.FauxItalicAngle = 0.25;
  this->mGlyphCacheParam.FauxBoldRatio = 0.045000002;
  this->mGlyphCacheParam.OutlineRatio = 0.0099999998;
  this->mGlyphCacheParam.ShadowQuality = 1.0;
  *(_WORD *)&this->mGlyphCacheParam.UseAutoFit = 257;
  this->mGlyphCacheParam.FenceWaitOnFullCache = 1;
  this->mComplexMeshUpdateList.Root.pPrev = (Scaleform::Render::ComplexMesh::UpdateNode *)&this->mComplexMeshUpdateList;
  this->mComplexMeshUpdateList.Root.pNext = (Scaleform::Render::ComplexMesh::UpdateNode *)&this->mComplexMeshUpdateList;
  *(_QWORD *)&this->VP.BufferWidth = 0i64;
  *(_QWORD *)&this->VP.Left = 0i64;
  this->VP.Height = 1;
  this->VP.Width = 1;
  *(_QWORD *)&this->VP.ScissorWidth = 0i64;
  *(_QWORD *)&this->VP.ScissorLeft = 0i64;
  this->VP.Flags = 0;
  p_Flags = &this->VP.Flags;
  if ( this == (Scaleform::Render::Renderer2DImpl *)-3680i64 )
    p_Flags = 0i64;
  this->RenderRoots.Root.pPrev = (Scaleform::Render::TreeCacheNode *)p_Flags;
  this->RenderRoots.Root.pNext = (Scaleform::Render::TreeCacheNode *)p_Flags;
  this->pPrev = hal->NotifyList.Root.pPrev;
  this->pNext = (Scaleform::Render::HALNotify *)&hal->HALState;
  hal->NotifyList.Root.pPrev->pNext = v5;
  hal->NotifyList.Root.pPrev = v5;
  v11 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  v12 = (Scaleform::Render::MeshKeyManager *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                               Scaleform::Memory::pGlobalHeap,
                                               96i64);
  if ( v12 )
  {
    Scaleform::Render::MeshKeyManager::MeshKeyManager(v12, v11);
    v14 = v13;
  }
  else
  {
    v14 = 0i64;
  }
  pObject = this->pMeshKeyManager.pObject;
  if ( pObject && !_InterlockedDecrement(&pObject->RefCount) )
    pObject->vfptr->__vecDelDtor(pObject, 1u);
  this->pMeshKeyManager.pObject = v14;
  v16 = (Scaleform::Render::GlyphCache *)v11->vfptr->Alloc(v11, 7320ui64, 0i64);
  if ( v16 )
  {
    Scaleform::Render::GlyphCache::GlyphCache(v16, v11);
    v6 = v17;
  }
  v18 = this->pGlyphCache.pObject;
  if ( v18 && !_InterlockedDecrement(&v18->RefCount) )
    v18->Scaleform::RefCountBase<Scaleform::Render::GlyphCache,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr->__vecDelDtor(
      v18,
      1u);
  this->pGlyphCache.pObject = v6;
  v6->pRenderer = hal;
  v6->pFillMan = &this->FillManager;
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::Render::HAL *))hal->vfptr[4].__vecDelDtor)(hal) )
    Scaleform::Render::GlyphCache::initialize(v6);
}

// File Line: 58
// RVA: 0x94C6B0
void __fastcall Scaleform::Render::Renderer2DImpl::~Renderer2DImpl(Scaleform::Render::Renderer2DImpl *this)
{
  Scaleform::Render::GlyphCache *pObject; // rcx
  Scaleform::Render::MeshKeyManager *v3; // rcx
  Scaleform::Render::HAL *v4; // rcx

  this->Scaleform::Render::ContextImpl::RenderNotify::vfptr = (Scaleform::Render::ContextImpl::RenderNotifyVtbl *)&Scaleform::Render::Renderer2DImpl::`vftable{for `Scaleform::Render::ContextImpl::RenderNotify};
  this->Scaleform::Render::HALNotify::vfptr = (Scaleform::Render::HALNotifyVtbl *)&Scaleform::Render::Renderer2DImpl::`vftable{for `Scaleform::Render::HALNotify};
  Scaleform::Render::ContextImpl::RenderNotify::ReleaseAllContextData(this);
  Scaleform::Render::MeshKeyManager::DestroyAllKeys(this->pMeshKeyManager.pObject);
  this->pPrev->pNext = this->pNext;
  this->pNext->pPrev = this->pPrev;
  this->pPrev = (Scaleform::Render::HALNotify *)-1i64;
  this->pNext = (Scaleform::Render::HALNotify *)-1i64;
  pObject = this->pGlyphCache.pObject;
  if ( pObject && !_InterlockedDecrement(&pObject->RefCount) )
    pObject->Scaleform::RefCountBase<Scaleform::Render::GlyphCache,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr->__vecDelDtor(
      pObject,
      1u);
  v3 = this->pMeshKeyManager.pObject;
  if ( v3 && !_InterlockedDecrement(&v3->RefCount) )
    v3->vfptr->__vecDelDtor(v3, 1u);
  Scaleform::Render::MatrixPoolImpl::MatrixPool::~MatrixPool(&this->MPool);
  this->FillManager.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::PrimitiveFillManager::`vftable;
  Scaleform::HashSet<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::GradientImage *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor>>::~HashSet<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::GradientImage *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor>>((Scaleform::HashSet<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> > *)&this->FillManager.Gradients);
  Scaleform::HashSet<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::GradientImage *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor>>::~HashSet<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::GradientImage *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor>>((Scaleform::HashSet<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> > *)&this->FillManager.FillSet);
  this->FillManager.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->StrokeGen.mPath.vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::TessBase::`vftable;
  this->StrokeGen.mStrokeSorter.vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::TessBase::`vftable;
  this->StrokeGen.mStroker.vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::TessBase::`vftable;
  Scaleform::Render::LinearHeap::ClearAndRelease(&this->StrokeGen.Heap2);
  Scaleform::Render::LinearHeap::ClearAndRelease(&this->StrokeGen.Heap1);
  Scaleform::Render::MeshGenerator::~MeshGenerator(&this->MeshGen);
  v4 = this->pHal.pObject;
  if ( v4 && _InterlockedExchangeAdd(&v4->RefCount, 0xFFFFFFFF) == 1 )
    v4->vfptr->__vecDelDtor(v4, 1u);
  this->Scaleform::Render::HALNotify::vfptr = (Scaleform::Render::HALNotifyVtbl *)&Scaleform::Render::HALNotify::`vftable;
  this->Scaleform::Render::ContextImpl::RenderNotify::vfptr = (Scaleform::Render::ContextImpl::RenderNotifyVtbl *)&Scaleform::Render::ContextImpl::RenderNotify::`vftable;
  Scaleform::Render::ContextImpl::RenderNotify::ReleaseAllContextData(this);
  this->ServiceCommandInstance.Scaleform::Render::ContextImpl::RenderNotify::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

// File Line: 71
// RVA: 0x95A780
__int64 __fastcall Scaleform::Render::Renderer2DImpl::BeginFrame(Scaleform::Render::Renderer2DImpl *this)
{
  Scaleform::Render::GlyphCache *pObject; // rbx
  Scaleform::Render::HAL *pRenderer; // rcx
  Scaleform::Render::FontCacheHandleManager *v4; // rcx

  Scaleform::Render::MeshKeyManager::ProcessKillList(this->pMeshKeyManager.pObject);
  pObject = this->pGlyphCache.pObject;
  if ( pObject )
  {
    if ( !pObject->pFontHandleManager.pObject )
    {
      pRenderer = pObject->pRenderer;
      if ( !pRenderer
        || !((unsigned __int8 (__fastcall *)(Scaleform::Render::HAL *))pRenderer->vfptr[4].__vecDelDtor)(pRenderer) )
      {
        return ((__int64 (__fastcall *)(Scaleform::Render::HAL *))this->pHal.pObject->vfptr[5].__vecDelDtor)(this->pHal.pObject);
      }
      Scaleform::Render::GlyphCache::initialize(pObject);
    }
    v4 = pObject->pFontHandleManager.pObject;
    if ( v4 )
      Scaleform::Render::FontCacheHandleManager::ProcessKillList(v4);
  }
  return ((__int64 (__fastcall *)(Scaleform::Render::HAL *))this->pHal.pObject->vfptr[5].__vecDelDtor)(this->pHal.pObject);
}

// File Line: 125
// RVA: 0x96EC70
void __fastcall Scaleform::Render::Renderer2DImpl::Draw(
        Scaleform::Render::Renderer2DImpl *this,
        Scaleform::Render::TreeRoot *pnode)
{
  Scaleform::Render::TreeCacheRoot *pRenderer; // rbx
  unsigned __int64 v5; // r12
  __int64 v6; // r14
  unsigned __int64 v7; // r13
  Scaleform::Render::Viewport *p_VP; // rdi
  int v9; // r10d
  int v10; // r8d
  Scaleform::Render::HAL *pObject; // rcx
  Scaleform::Render::MatrixState *v12; // rax
  int v13; // r9d
  int v14; // edx
  char v15; // bp
  float v16; // xmm6_4
  float v17; // xmm7_4
  float v18; // xmm8_4
  float v19; // xmm9_4
  __int16 v20; // ax
  unsigned __int16 v21; // bx
  Scaleform::Render::TreeCacheRoot *v22; // rax
  Scaleform::Render::TreeCacheRoot *v23; // rax
  int v24; // eax
  int v25; // ecx
  int v26; // eax
  int UpdateFlags; // ecx
  Scaleform::Render::Rect<int> prect; // [rsp+38h] [rbp-A0h] BYREF
  __int128 v29; // [rsp+50h] [rbp-88h]
  int v30; // [rsp+E8h] [rbp+10h] BYREF
  Scaleform::Render::TreeCacheRoot *v31; // [rsp+F0h] [rbp+18h]

  pRenderer = (Scaleform::Render::TreeCacheRoot *)pnode->pRenderer;
  v5 = (unsigned __int64)pnode & 0xFFFFFFFFFFFFF000ui64;
  v6 = (__int64)((__int64)&pnode[-1] - ((unsigned __int64)pnode & 0xFFFFFFFFFFFFF000ui64)) / 56;
  v7 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)pnode & 0xFFFFFFFFFFFFF000ui64) + 0x28) + 8i64 * (unsigned int)v6 + 40) & 0xFFFFFFFFFFFFFFFEui64;
  p_VP = (Scaleform::Render::Viewport *)(v7 + 160);
  if ( *(_DWORD *)(v7 + 160) && *(_DWORD *)(v7 + 164) )
  {
    v9 = *(_DWORD *)(v7 + 172);
    v10 = *(_DWORD *)(v7 + 168);
    pObject = this->pHal.pObject;
    v12 = pObject->Matrices.pObject;
    if ( (((*(_DWORD *)(v7 + 200) & 0x30) - 16) & 0xFFFFFFDF) != 0 )
    {
      v13 = *(_DWORD *)(v7 + 180);
      v14 = *(_DWORD *)(v7 + 176);
    }
    else
    {
      v13 = *(_DWORD *)(v7 + 176);
      v14 = *(_DWORD *)(v7 + 180);
    }
    v12->ViewRectOriginal.x1 = v10;
    v12->ViewRectOriginal.y1 = v9;
    v12->ViewRectOriginal.x2 = v10 + v14;
    v12->ViewRectOriginal.y2 = v9 + v13;
    pObject->Matrices.pObject->UVPOChanged = 1;
  }
  else
  {
    p_VP = &this->VP;
  }
  v29 = 0i64;
  *(_QWORD *)&prect.x1 = 0i64;
  *(_QWORD *)&prect.x2 = 0i64;
  if ( Scaleform::Render::Viewport::GetClippedRect<int>(p_VP, &prect, 1) )
  {
    v16 = (float)(prect.y2 - p_VP->Top);
    v17 = (float)(prect.x2 - p_VP->Left);
    v18 = (float)(prect.y1 - p_VP->Top);
    v19 = (float)(prect.x1 - p_VP->Left);
    v15 = 1;
  }
  else
  {
    v15 = 0;
    v16 = *((float *)&v29 + 3);
    v17 = *((float *)&v29 + 2);
    v18 = *((float *)&v29 + 1);
    v19 = *(float *)&v29;
  }
  if ( p_VP->BufferWidth && p_VP->BufferHeight )
  {
    if ( pRenderer )
    {
      if ( v15 == pRenderer->ViewValid
        && v19 == pRenderer->ViewCullRect.x1
        && v17 == pRenderer->ViewCullRect.x2
        && v18 == pRenderer->ViewCullRect.y1
        && v16 == pRenderer->ViewCullRect.y2 )
      {
        goto LABEL_32;
      }
      pRenderer->ViewValid = v15;
      pRenderer->ViewCullRect.x1 = v19;
      pRenderer->ViewCullRect.y1 = v18;
      pRenderer->ViewCullRect.x2 = v17;
      pRenderer->ViewCullRect.y2 = v16;
      v26 = 1;
      UpdateFlags = pRenderer->UpdateFlags;
      if ( UpdateFlags >= 0 )
      {
        pRenderer->pNextUpdate = pRenderer->pUpdateList;
        pRenderer->pUpdateList = pRenderer;
        v26 = -2147483647;
      }
      pRenderer->UpdateFlags = UpdateFlags | v26;
LABEL_31:
      Scaleform::Render::TreeCacheRoot::UpdateTreeData(pRenderer);
LABEL_32:
      if ( v15 )
        Scaleform::Render::TreeCacheRoot::Draw(pRenderer);
      return;
    }
    v20 = *(_WORD *)(v7 + 10) & 0xC;
    if ( (*(_WORD *)(v7 + 10) & 0xC) == 0 )
      v20 = 4;
    v21 = v20 | *(_BYTE *)(v7 + 10) & 1;
    v30 = 71;
    v22 = (Scaleform::Render::TreeCacheRoot *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                Scaleform::Memory::pGlobalHeap,
                                                this,
                                                496i64,
                                                &v30);
    v31 = v22;
    if ( v22 )
    {
      Scaleform::Render::TreeCacheRoot::TreeCacheRoot(v22, this, this->pHal.pObject, v21, pnode);
      pRenderer = v23;
    }
    else
    {
      pRenderer = 0i64;
    }
    if ( pRenderer )
    {
      pnode->pRenderer = pRenderer;
      pRenderer->pPrev = this->RenderRoots.Root.pPrev;
      pRenderer->pNext = (Scaleform::Render::TreeCacheNode *)&this->VP.Flags;
      this->RenderRoots.Root.pPrev->pNext = pRenderer;
      this->RenderRoots.Root.pPrev = pRenderer;
      pRenderer->ViewValid = v15;
      pRenderer->ViewCullRect.x1 = v19;
      pRenderer->ViewCullRect.y1 = v18;
      pRenderer->ViewCullRect.x2 = v17;
      pRenderer->ViewCullRect.y2 = v16;
      pRenderer->vfptr->UpdateChildSubtree(
        pRenderer,
        (Scaleform::Render::TreeNode::NodeData *)(*(_QWORD *)(*(_QWORD *)(v5 + 40) + 8i64 * (unsigned int)v6 + 40) & 0xFFFFFFFFFFFFFFFEui64),
        1u);
      v24 = 16777219;
      v25 = pRenderer->UpdateFlags;
      if ( v25 >= 0 )
      {
        pRenderer->pNextUpdate = pRenderer->pUpdateList;
        pRenderer->pUpdateList = pRenderer;
        v24 = -2130706429;
      }
      pRenderer->UpdateFlags = v24 | v25;
      Scaleform::Render::TreeCacheRoot::ChainUpdatesByDepth(pRenderer);
      goto LABEL_31;
    }
  }
}

// File Line: 219
// RVA: 0x971100
void __fastcall Scaleform::Render::Renderer2DImpl::EntryDestroy(
        Scaleform::Render::Renderer2DImpl *this,
        Scaleform::Render::ContextImpl::Entry *p)
{
  Scaleform::Render::TreeCacheNode *pRenderer; // rcx

  pRenderer = p->pRenderer;
  if ( pRenderer )
  {
    pRenderer->vfptr->__vecDelDtor(pRenderer, 1u);
    p->pRenderer = 0i64;
  }
}

// File Line: 231
// RVA: 0x971130
void __fastcall Scaleform::Render::Renderer2DImpl::EntryFlush(
        Scaleform::Render::Renderer2DImpl *this,
        Scaleform::Render::ContextImpl::Entry *p)
{
  this->Scaleform::Render::ContextImpl::RenderNotify::vfptr->EntryDestroy(this, p);
}

// File Line: 239
// RVA: 0x970E30
void __fastcall Scaleform::Render::Renderer2DImpl::EntryChanges(
        Scaleform::Render::Renderer2DImpl *this,
        Scaleform::Render::ContextImpl::Context *context,
        Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63> *cb,
        bool forceUpdateImages)
{
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63>::Page *pPages; // r15
  Scaleform::Render::ContextImpl::Context *v6; // r13
  Scaleform::Render::Renderer2DImpl *v7; // rdi
  unsigned int i; // r14d
  Scaleform::Render::ContextImpl::EntryChange *v9; // rdi
  Scaleform::Render::TreeCacheNode *pRenderer; // rbx
  unsigned int ChangeBits; // eax
  Scaleform::Render::TreeCacheRoot *pRoot; // rbp
  int v13; // esi
  unsigned int v14; // eax
  int v15; // eax
  Scaleform::Render::TreeCacheNode *pParent; // rcx
  int v17; // ecx
  Scaleform::Render::TreeCacheNode *v18; // rcx
  int v19; // eax
  Scaleform::Render::TreeCacheRoot *pNext; // rbx
  Scaleform::List<Scaleform::Render::TreeCacheNode,Scaleform::Render::TreeCacheNode> *p_RenderRoots; // rdi
  __int64 v22; // rax

  pPages = cb->pPages;
  v6 = context;
  v7 = this;
  if ( cb->pPages )
  {
    do
    {
      for ( i = 0; i < pPages->Count; ++i )
      {
        v9 = &pPages->Items[i];
        if ( v9->pNode )
        {
          pRenderer = v9->pNode->pRenderer;
          if ( pRenderer )
          {
            if ( (v9->ChangeBits & 0x3730) != 0 )
              (*(void (__fastcall **)(Scaleform::Render::TreeCacheNode *))pRenderer->vfptr->gap8)(pRenderer);
            ChangeBits = v9->ChangeBits;
            pRoot = pRenderer->pRoot;
            if ( (ChangeBits & 0x7E208C) != 0 )
            {
              v13 = 0;
              if ( (ChangeBits & 4) != 0 )
              {
                v13 = 0x1000000;
                pRenderer->Flags ^= (pRenderer->Flags ^ *(_WORD *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)pRenderer->pNode & 0xFFFFFFFFFFFFF000ui64)
                                                                                          + 0x28)
                                                                              + 8i64
                                                                              * (unsigned int)((int)(LODWORD(pRenderer->pNode) - ((__int64)pRenderer->pNode & 0xFFFFF000) - 56)
                                                                                             / 56)
                                                                              + 40) & 0xFFFFFFFFFFFFFFFEui64)
                                                                 + 10)) & 1;
              }
              if ( (v9->ChangeBits & 0x40000) != 0 )
                Scaleform::Render::TreeCacheNode::updateMaskCache(
                  pRenderer,
                  (Scaleform::Render::TreeNode::NodeData *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)pRenderer->pNode & 0xFFFFFFFFFFFFF000ui64)
                                                                                  + 0x28)
                                                                      + 8i64
                                                                      * (unsigned int)((int)(LODWORD(pRenderer->pNode)
                                                                                           - ((__int64)pRenderer->pNode & 0xFFFFF000)
                                                                                           - 56)
                                                                                     / 56)
                                                                      + 40) & 0xFFFFFFFFFFFFFFFEui64),
                  pRenderer->Depth + 1,
                  0);
              v14 = v9->ChangeBits;
              if ( (v14 & 8) != 0 )
                v13 |= 0x2000000u;
              v15 = v14 & 0x7E0000;
              if ( v15 )
              {
                pRenderer->UpdateFlags |= v15;
                v13 |= 0x1000000u;
              }
              if ( (v9->ChangeBits & 0x2000) != 0 )
                v13 |= 0x1000000u;
              if ( !pRoot )
                continue;
              if ( v13 )
              {
                pParent = pRenderer->pParent;
                if ( pParent )
                {
                  if ( (pParent->UpdateFlags & 0x80000000) == 0 )
                  {
                    v13 |= 0x80000000;
                    pParent->pNextUpdate = pRoot->pUpdateList;
                    pRoot->pUpdateList = pParent;
                  }
                  pParent->UpdateFlags |= v13;
                }
              }
            }
            if ( pRoot )
            {
              v17 = v9->ChangeBits & 0x12003;
              if ( v17 )
              {
                if ( (pRenderer->UpdateFlags & 0x80000000) == 0 )
                {
                  v17 |= 0x80000000;
                  pRenderer->pNextUpdate = pRoot->pUpdateList;
                  pRoot->pUpdateList = pRenderer;
                }
                pRenderer->UpdateFlags |= v17;
                if ( (v9->ChangeBits & 1) != 0 && (pRenderer->Flags & 0x20) != 0 )
                {
                  v18 = pRenderer->pParent;
                  v19 = 33554433;
                  if ( (v18->UpdateFlags & 0x80000000) == 0 )
                  {
                    v18->pNextUpdate = pRoot->pUpdateList;
                    pRoot->pUpdateList = v18;
                    v19 = -2113929215;
                  }
                  v18->UpdateFlags |= v19;
                }
              }
            }
          }
        }
      }
      pPages = pPages->pNext;
    }
    while ( pPages );
    v6 = context;
    v7 = this;
  }
  if ( forceUpdateImages )
    Scaleform::Render::Renderer2DImpl::UpdateComplexMeshes(v7);
  pNext = (Scaleform::Render::TreeCacheRoot *)v7->RenderRoots.Root.pNext;
  p_RenderRoots = &v7->RenderRoots;
  while ( 1 )
  {
    v22 = p_RenderRoots ? (__int64)&p_RenderRoots[-1].Root.8 : 0i64;
    if ( pNext == (Scaleform::Render::TreeCacheRoot *)v22 )
      break;
    if ( forceUpdateImages
      && *(Scaleform::Render::ContextImpl::Context **)(*(_QWORD *)(((unsigned __int64)pNext->pNode & 0xFFFFFFFFFFFFF000ui64)
                                                                 + 0x18)
                                                     + 16i64) == v6 )
    {
      pNext->vfptr->forceUpdateImages(pNext);
    }
    Scaleform::Render::TreeCacheRoot::ChainUpdatesByDepth(pNext);
    Scaleform::Render::TreeCacheRoot::UpdateTreeData(pNext);
    pNext = (Scaleform::Render::TreeCacheRoot *)pNext->pNext;
  }
}

// File Line: 401
// RVA: 0x99CAE0
void __fastcall Scaleform::Render::Renderer2DImpl::OnHALEvent(
        Scaleform::Render::Renderer2DImpl *this,
        Scaleform::Render::HALNotifyType type)
{
  int v3; // edx
  int v4; // edx
  Scaleform::Render::GlyphCache *pNext; // rdi
  Scaleform::Render::ThreadCommandQueue *pRTCommandQueue; // rcx

  if ( type == HAL_Initialize )
    goto LABEL_5;
  v3 = type - 1;
  if ( !v3 )
  {
    Scaleform::Render::ContextImpl::RenderNotify::ReleaseAllContextData((Scaleform::Render::Renderer2DImpl *)((char *)this - 56));
    Scaleform::Render::MeshKeyManager::DestroyAllKeys((Scaleform::Render::MeshKeyManager *)this->MPool.HandleTable.PartiallyFreePages.Root.pPrev);
    Scaleform::Render::GlyphCache::Destroy((Scaleform::Render::GlyphCache *)this->MPool.HandleTable.PartiallyFreePages.Root.pNext);
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
LABEL_5:
    pNext = (Scaleform::Render::GlyphCache *)this->MPool.HandleTable.PartiallyFreePages.Root.pNext;
    pRTCommandQueue = this->pRTCommandQueue;
    pNext->pFillMan = (Scaleform::Render::PrimitiveFillManager *)&this->Tolerances.FillAliasedLowerScale;
    pNext->pRenderer = (Scaleform::Render::HAL *)pRTCommandQueue;
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::Render::ThreadCommandQueue *))pRTCommandQueue->vfptr[1].PushThreadCommand)(pRTCommandQueue) )
      Scaleform::Render::GlyphCache::initialize(pNext);
  }
}

// File Line: 433
// RVA: 0x9BDB90
void __fastcall Scaleform::Render::Renderer2DImpl::UpdateComplexMeshes(Scaleform::Render::Renderer2DImpl *this)
{
  Scaleform::Lock *p_KeySetLock; // rbx
  Scaleform::Render::ComplexMesh::UpdateNode *pNext; // r15
  Scaleform::List<Scaleform::Render::ComplexMesh::UpdateNode,Scaleform::Render::ComplexMesh::UpdateNode> *p_mComplexMeshUpdateList; // r13
  Scaleform::Render::ComplexMesh::UpdateNode *v5; // rbp
  Scaleform::Render::TextureManager *textureManager; // r12
  unsigned int v7; // r14d
  __int64 v8; // rdi
  unsigned int *v9; // rdi
  Scaleform::Render::PrimitiveFill *v10; // rax
  Scaleform::Render::PrimitiveFill *v11; // rsi
  __int64 v12; // rcx
  bool v13; // zf
  void (__fastcall *pDtor)(void *); // [rsp+20h] [rbp-C8h]
  Scaleform::Ptr<Scaleform::Render::Image> ptr; // [rsp+58h] [rbp-90h] BYREF
  Scaleform::Ptr<Scaleform::Render::Image> gradientImg1; // [rsp+60h] [rbp-88h] BYREF
  Scaleform::Render::FillData fd0; // [rsp+70h] [rbp-78h] BYREF
  Scaleform::Render::FillData fd1; // [rsp+90h] [rbp-58h] BYREF
  Scaleform::List<Scaleform::Render::ComplexMesh::UpdateNode,Scaleform::Render::ComplexMesh::UpdateNode> *i; // [rsp+F0h] [rbp+8h]

  p_KeySetLock = &this->pMeshKeyManager.pObject->KeySetLock;
  EnterCriticalSection(&p_KeySetLock->cs);
  pNext = this->mComplexMeshUpdateList.Root.pNext;
  p_mComplexMeshUpdateList = &this->mComplexMeshUpdateList;
  for ( i = &this->mComplexMeshUpdateList;
        pNext != (Scaleform::Render::ComplexMesh::UpdateNode *)p_mComplexMeshUpdateList;
        pNext = pNext->pNext )
  {
    v5 = pNext - 10;
    if ( ((__int64 (__fastcall *)(Scaleform::Render::ComplexMesh::UpdateNode *))pNext[-5].pNext->Scaleform::ListNode<Scaleform::Render::ComplexMesh::UpdateNode>::$33BF73C4AE1B64C528F7D9912F00A9F4::pPrev[6].pNext)(pNext[-5].pNext) )
    {
      textureManager = (Scaleform::Render::TextureManager *)((__int64 (__fastcall *)(Scaleform::Render::ComplexMesh::UpdateNode *))v5[5].pPrev[5].pPrev->pPrev[30].pNext)(v5[5].pPrev[5].pPrev);
      v7 = 0;
      if ( v5[15].pNext )
      {
        v8 = 0i64;
        do
        {
          v9 = (unsigned int *)v5[15].pPrev + 14 * v8;
          if ( *(_QWORD *)v9 )
          {
            fd0.Type = Fill_VColor;
            fd0.Color = 0;
            fd0.PrimFill = PrimFill_VColor_EAlpha;
            fd0.FillMode.Fill = 0;
            fd0.pVFormat = &Scaleform::Render::VertexXY16iCF32::Format;
            fd1.Type = Fill_VColor;
            fd1.Color = 0;
            fd1.PrimFill = PrimFill_VColor_EAlpha;
            fd1.FillMode.Fill = 0;
            fd1.pVFormat = &Scaleform::Render::VertexXY16iCF32::Format;
            pDtor = (void (__fastcall *)(void *))ARefPtr<SSClassDescBase>::~ARefPtr<SSClassDescBase>;
            `eh vector constructor iterator(
              &ptr,
              8ui64,
              2,
              (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>);
            LODWORD(pDtor) = v5[9].pNext;
            ((void (__fastcall *)(Scaleform::Render::ComplexMesh::UpdateNode *, Scaleform::Render::FillData *, _QWORD, _QWORD, void (__fastcall *)(void *)))v5[5].pNext->Scaleform::ListNode<Scaleform::Render::ComplexMesh::UpdateNode>::$33BF73C4AE1B64C528F7D9912F00A9F4::pPrev[5].pNext)(
              v5[5].pNext,
              &fd0,
              HIDWORD(v5[9].pVoidPrev),
              v9[11],
              pDtor);
            ((void (__fastcall *)(Scaleform::Render::ComplexMesh::UpdateNode *, Scaleform::Render::FillData *, _QWORD, _QWORD, _DWORD))v5[5].pNext->Scaleform::ListNode<Scaleform::Render::ComplexMesh::UpdateNode>::$33BF73C4AE1B64C528F7D9912F00A9F4::pPrev[5].pNext)(
              v5[5].pNext,
              &fd1,
              HIDWORD(v5[9].pVoidPrev),
              v9[12],
              v5[9].pNext);
            v10 = Scaleform::Render::PrimitiveFillManager::CreateMergedFill(
                    (Scaleform::Render::PrimitiveFillManager *)v5[11].pPrev,
                    v9[13],
                    *(Scaleform::Render::VertexFormat **)(*(_QWORD *)v9 + 48i64),
                    &fd0,
                    &fd1,
                    &ptr,
                    &gradientImg1,
                    textureManager,
                    *(float *)&v5[9].pPrev);
            v11 = v10;
            if ( v10 )
            {
              ++v10->RefCount;
              v12 = *(_QWORD *)v9;
              if ( *(_QWORD *)v9 )
              {
                v13 = (*(_DWORD *)(v12 + 8))-- == 1;
                if ( v13 )
                  (**(void (__fastcall ***)(__int64, __int64))v12)(v12, 1i64);
              }
              *(_QWORD *)v9 = v11;
              v13 = v11->RefCount-- == 1;
              if ( v13 )
                v11->vfptr->__vecDelDtor(v11, 1u);
            }
            `eh vector destructor iterator(
              &ptr,
              8ui64,
              2,
              (void (__fastcall *)(void *))ARefPtr<SSClassDescBase>::~ARefPtr<SSClassDescBase>);
          }
          v8 = ++v7;
        }
        while ( (Scaleform::Render::ComplexMesh::UpdateNode *)v7 < v5[15].pNext );
        p_mComplexMeshUpdateList = i;
      }
      Scaleform::Render::ComplexMesh::updateFillMatrixCache(
        (Scaleform::Render::ComplexMesh *)&pNext[-10],
        (Scaleform::Render::Matrix2x4<float> *)&v5[13]);
    }
  }
  LeaveCriticalSection(&p_KeySetLock->cs);
}

