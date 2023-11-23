// File Line: 44
// RVA: 0x159C490
__int64 dynamic_initializer_for__Scaleform::Render::RasterGlyphVertex::Format__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Scaleform::Render::RasterGlyphVertex::Format__);
}

// File Line: 51
// RVA: 0x93CD80
void __fastcall Scaleform::Render::GlyphTextureImage::GlyphTextureImage(
        Scaleform::Render::GlyphTextureImage *this,
        Scaleform::Render::GlyphCache *cache,
        unsigned int textureId,
        Scaleform::Render::Size<unsigned long> *size,
        unsigned int use)
{
  unsigned int Height; // ecx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountVImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseV<Scaleform::Render::Image,3>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ImageBase::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Image::`vftable;
  this->pTexture.Value = 0i64;
  this->pUpdateSync = 0i64;
  this->pInverseMatrix = 0i64;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::TextureImage::`vftable;
  this->Format = Image_A8;
  Height = size->Height;
  this->Size.Width = size->Width;
  this->Size.Height = Height;
  this->Use = use;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::GlyphTextureImage::`vftable;
  this->pCache = cache;
  this->TextureId = textureId;
}

// File Line: 58
// RVA: 0x9653C0
Scaleform::Render::GlyphTextureImage *__fastcall Scaleform::Render::GlyphTextureImage::Create(
        Scaleform::MemoryHeap *heap,
        Scaleform::Render::TextureManager *texMan,
        Scaleform::Render::GlyphCache *cache,
        unsigned int textureId,
        Scaleform::Render::Size<unsigned long> *size,
        unsigned int use)
{
  Scaleform::Render::GlyphTextureImage *v9; // rax
  _QWORD *v10; // rax
  _QWORD *v11; // rbx
  __int64 v12; // rax

  v9 = (Scaleform::Render::GlyphTextureImage *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))heap->vfptr->Alloc)(
                                                 heap,
                                                 72i64);
  if ( v9 )
  {
    Scaleform::Render::GlyphTextureImage::GlyphTextureImage(v9, cache, textureId, size, use);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  v12 = ((__int64 (__fastcall *)(Scaleform::Render::TextureManager *, __int64, __int64, Scaleform::Render::Size<unsigned long> *, unsigned int, _QWORD *, _QWORD))texMan->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[1].__vecDelDtor)(
          texMan,
          9i64,
          1i64,
          size,
          use,
          v11,
          0i64);
  if ( v12 )
  {
    v11[2] = v12;
    return (Scaleform::Render::GlyphTextureImage *)v11;
  }
  else
  {
    (*(void (__fastcall **)(_QWORD *))(*v11 + 16i64))(v11);
    return 0i64;
  }
}

// File Line: 73
// RVA: 0x9B9D30
void __fastcall Scaleform::Render::GlyphTextureImage::TextureLost(
        Scaleform::Render::GlyphTextureImage *this,
        unsigned int reason)
{
  volatile signed __int32 *v4; // rbx

  v4 = (volatile signed __int32 *)_InterlockedExchange64((volatile __int64 *)&this->pTexture, 0i64);
  if ( v4 )
  {
    (*(void (__fastcall **)(volatile signed __int32 *))(*(_QWORD *)v4 + 64i64))(v4);
    if ( !_InterlockedDecrement(v4 + 2) )
      (**(void (__fastcall ***)(volatile signed __int32 *, __int64))v4)(v4, 1i64);
  }
  Scaleform::Render::GlyphCache::TextureLost(this->pCache, this->TextureId, reason);
}

// File Line: 83
// RVA: 0x965480
_BOOL8 __fastcall Scaleform::Render::GlyphTextureMapper::Create(
        Scaleform::Render::GlyphTextureMapper *this,
        unsigned int method,
        Scaleform::MemoryHeap *heap,
        Scaleform::Render::TextureManager *texMan,
        Scaleform::Render::Size<unsigned long> *fillMan)
{
  Scaleform::Render::GlyphTextureImage *pObject; // rcx
  Scaleform::Render::RawImage *v10; // rbx
  Scaleform::Render::RawImage *v11; // rcx
  bool v12; // si
  Scaleform::Render::Texture *v13; // r15
  Scaleform::Render::Texture *v14; // rcx
  Scaleform::Render::Texture *v15; // rcx
  Scaleform::Render::PrimitiveFill *v16; // rbx
  Scaleform::Render::PrimitiveFill *v17; // rcx
  bool v18; // zf
  Scaleform::Ptr<Scaleform::Render::Texture> *Textures; // rcx
  Scaleform::Render::RawImage *v20; // rcx
  unsigned int v21; // eax
  Scaleform::Render::GlyphTextureImage *v22; // rbx
  Scaleform::Render::GlyphTextureImage *v23; // rcx
  Scaleform::Render::Texture *v24; // r15
  Scaleform::Render::Texture *v25; // rcx
  Scaleform::Render::Texture *v26; // rcx
  Scaleform::Render::PrimitiveFill *v27; // rbx
  Scaleform::Render::PrimitiveFill *v28; // rcx
  _BOOL8 result; // rax
  Scaleform::Render::PrimitiveFillData pheap; // [rsp+20h] [rbp-31h] BYREF
  Scaleform::Render::PrimitiveFillData initdata; // [rsp+48h] [rbp-9h] BYREF
  Scaleform::Render::PrimitiveFillManager *v32; // [rsp+B8h] [rbp+67h]
  Scaleform::Render::GlyphCache *v33; // [rsp+C0h] [rbp+6Fh]
  unsigned int v34; // [rsp+C8h] [rbp+77h]

  this->pTexMan = texMan;
  this->Method = method;
  if ( method == 2 )
  {
    pObject = this->pTexImg.pObject;
    if ( pObject )
      ((void (__fastcall *)(Scaleform::Render::GlyphTextureImage *))pObject->vfptr[2].__vecDelDtor)(pObject);
    this->pTexImg.pObject = 0i64;
    v10 = Scaleform::Render::RawImage::Create(Image_A8, 1u, fillMan, 0x10u, heap, 0i64);
    v11 = this->pRawImg.pObject;
    if ( v11 )
      ((void (__fastcall *)(Scaleform::Render::RawImage *))v11->vfptr[2].__vecDelDtor)(v11);
    this->pRawImg.pObject = v10;
    v12 = v10 != 0i64;
    if ( v10 )
    {
      v13 = (Scaleform::Render::Texture *)v10->vfptr[21].__vecDelDtor(v10, (unsigned int)texMan);
      *(_QWORD *)&pheap.Type = Scaleform::Ptr<Scaleform::Render::StereoImplBase>::~Ptr<Scaleform::Render::StereoImplBase>;
      `eh vector constructor iterator(
        pheap.Textures,
        8ui64,
        2,
        (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>);
      pheap.pFormat = &Scaleform::Render::RasterGlyphVertex::Format;
      *(_WORD *)&pheap.FillModes[0].Fill = 3;
      if ( v13 )
        _InterlockedExchangeAdd(&v13->RefCount, 1u);
      v14 = pheap.Textures[0].pObject;
      if ( pheap.Textures[0].pObject && !_InterlockedDecrement(&pheap.Textures[0].pObject->RefCount) && v14 )
        v14->vfptr->__vecDelDtor(v14, 1u);
      pheap.Textures[0].pObject = v13;
      v15 = pheap.Textures[1].pObject;
      if ( pheap.Textures[1].pObject && !_InterlockedDecrement(&pheap.Textures[1].pObject->RefCount) && v15 )
        v15->vfptr->__vecDelDtor(v15, 1u);
      pheap.Textures[1].pObject = 0i64;
      v16 = Scaleform::Render::PrimitiveFillManager::CreateFill(v32, &pheap);
      v17 = this->pFill.pObject;
      if ( v17 )
      {
        v18 = v17->RefCount-- == 1;
        if ( v18 )
          v17->vfptr->__vecDelDtor(v17, 1u);
      }
      this->pFill.pObject = v16;
      Textures = pheap.Textures;
LABEL_42:
      `eh vector destructor iterator(
        Textures,
        8ui64,
        2,
        (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::StereoImplBase>::~Ptr<Scaleform::Render::StereoImplBase>);
    }
  }
  else
  {
    v20 = this->pRawImg.pObject;
    if ( v20 )
      ((void (__fastcall *)(Scaleform::Render::RawImage *))v20->vfptr[2].__vecDelDtor)(v20);
    this->pRawImg.pObject = 0i64;
    v21 = 192;
    if ( method == 1 )
      v21 = 32;
    v22 = Scaleform::Render::GlyphTextureImage::Create(heap, texMan, v33, v34, fillMan, v21);
    v23 = this->pTexImg.pObject;
    if ( v23 )
      ((void (__fastcall *)(Scaleform::Render::GlyphTextureImage *))v23->vfptr[2].__vecDelDtor)(v23);
    this->pTexImg.pObject = v22;
    v12 = v22 != 0i64;
    if ( v22 )
    {
      v24 = (Scaleform::Render::Texture *)v22->vfptr[21].__vecDelDtor(v22, (unsigned int)texMan);
      *(_QWORD *)&initdata.Type = 12i64;
      *(_QWORD *)&pheap.Type = Scaleform::Ptr<Scaleform::Render::StereoImplBase>::~Ptr<Scaleform::Render::StereoImplBase>;
      `eh vector constructor iterator(
        initdata.Textures,
        8ui64,
        2,
        (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>);
      initdata.pFormat = &Scaleform::Render::RasterGlyphVertex::Format;
      *(_WORD *)&initdata.FillModes[0].Fill = 3;
      if ( v24 )
        _InterlockedExchangeAdd(&v24->RefCount, 1u);
      v25 = initdata.Textures[0].pObject;
      if ( initdata.Textures[0].pObject && !_InterlockedDecrement(&initdata.Textures[0].pObject->RefCount) && v25 )
        v25->vfptr->__vecDelDtor(v25, 1u);
      initdata.Textures[0].pObject = v24;
      v26 = initdata.Textures[1].pObject;
      if ( initdata.Textures[1].pObject && !_InterlockedDecrement(&initdata.Textures[1].pObject->RefCount) && v26 )
        v26->vfptr->__vecDelDtor(v26, 1u);
      initdata.Textures[1].pObject = 0i64;
      v27 = Scaleform::Render::PrimitiveFillManager::CreateFill(v32, &initdata);
      v28 = this->pFill.pObject;
      if ( v28 )
      {
        v18 = v28->RefCount-- == 1;
        if ( v18 )
          v28->vfptr->__vecDelDtor(v28, 1u);
      }
      this->pFill.pObject = v27;
      Textures = initdata.Textures;
      goto LABEL_42;
    }
  }
  result = v12;
  this->Valid = v12;
  return result;
}

// File Line: 126
// RVA: 0x999210
Scaleform::Render::ImagePlane *__fastcall Scaleform::Render::GlyphTextureMapper::Map(
        Scaleform::Render::GlyphTextureMapper *this)
{
  unsigned int Method; // eax
  void *pObject; // rcx
  __int64 v4; // r9

  Method = this->Method;
  if ( Method )
  {
    if ( Method != 2 )
      return 0i64;
    if ( !this->Mapped )
    {
      pObject = this->pRawImg.pObject;
      v4 = 0i64;
      goto LABEL_8;
    }
  }
  else if ( !this->Mapped )
  {
    pObject = this->pTexImg.pObject;
    v4 = 1i64;
LABEL_8:
    if ( (*(unsigned __int8 (__fastcall **)(void *, Scaleform::Render::ImageData *, _QWORD, __int64))(*(_QWORD *)pObject + 136i64))(
           pObject,
           &this->Data,
           0i64,
           v4) )
    {
      this->Mapped = 1;
      return this->Data.pPlanes;
    }
    return 0i64;
  }
  return this->Data.pPlanes;
}

// File Line: 248
// RVA: 0x93C330
void __fastcall Scaleform::Render::GlyphCache::GlyphCache(
        Scaleform::Render::GlyphCache *this,
        Scaleform::MemoryHeap *heap)
{
  int v4; // esi
  int v5; // ebx
  unsigned __int64 *p_Capacity; // rcx
  Scaleform::Render::TextMeshProvider *v7; // rcx
  Scaleform::Render::VectorGlyphShape *p_Notifier; // rcx
  unsigned int v9; // edx
  char *v10; // r8
  Scaleform::Log *volatile v11; // rax

  this->Scaleform::RefCountBase<Scaleform::Render::GlyphCache,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  v4 = 1;
  this->RefCount = 1;
  this->Scaleform::RefCountBase<Scaleform::Render::GlyphCache,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->Scaleform::RefCountBase<Scaleform::Render::GlyphCache,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->Scaleform::RefCountBase<Scaleform::Render::GlyphCache,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::GlyphCache,2>::`vftable;
  this->Scaleform::Render::CacheBase::vfptr = (Scaleform::Render::CacheBaseVtbl *)&Scaleform::Render::CacheBase::`vftable;
  this->Scaleform::Render::GlyphCacheConfig::vfptr = (Scaleform::Render::GlyphCacheConfigVtbl *)&Scaleform::Render::GlyphCacheConfig::`vftable;
  this->Scaleform::RefCountBase<Scaleform::Render::GlyphCache,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::GlyphCache::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::GlyphCache,2>};
  this->Scaleform::Render::CacheBase::vfptr = (Scaleform::Render::CacheBaseVtbl *)&Scaleform::Render::GlyphCache::`vftable{for `Scaleform::Render::CacheBase};
  this->Scaleform::Render::GlyphCacheConfig::vfptr = (Scaleform::Render::GlyphCacheConfigVtbl *)&Scaleform::Render::GlyphCache::`vftable{for `Scaleform::Render::GlyphCacheConfig};
  this->Param.TextureWidth = 1024;
  this->Param.TextureHeight = 1024;
  this->Param.NumTextures = 1;
  this->Param.MaxSlotHeight = 48;
  this->Param.SlotPadding = 2;
  this->Param.TexUpdWidth = 256;
  this->Param.TexUpdHeight = 512;
  this->Param.MaxRasterScale = 1.0;
  this->Param.MaxVectorCacheSize = 500;
  this->Param.FauxItalicAngle = 0.25;
  this->Param.FauxBoldRatio = 0.045000002;
  this->Param.OutlineRatio = 0.0099999998;
  this->Param.ShadowQuality = 1.0;
  *(_WORD *)&this->Param.UseAutoFit = 257;
  this->Param.FenceWaitOnFullCache = 1;
  this->pHeap = heap;
  v5 = 0;
  this->pRenderer = 0i64;
  this->pFillMan = 0i64;
  this->pTexMan = 0i64;
  *(_QWORD *)&this->TextureWidth = 0i64;
  *(_QWORD *)&this->MaxNumTextures = 0i64;
  *(_QWORD *)&this->SlotPadding = 0i64;
  this->ScaleV = 0.0;
  this->ShadowQuality = 1.0;
  `eh vector constructor iterator(
    this->Textures,
    0x80ui64,
    32,
    (void (__fastcall *)(void *))Scaleform::Render::GlyphTextureMapper::GlyphTextureMapper);
  Scaleform::Render::GlyphQueue::GlyphQueue(&this->Queue);
  *(_QWORD *)&this->Method = 0i64;
  *(_QWORD *)&this->UpdatePacker.Height = 0i64;
  *(_QWORD *)&this->UpdatePacker.LastY = 0i64;
  this->UpdateBuffer.pObject = 0i64;
  this->GlyphsToUpdate.Size = 0i64;
  this->GlyphsToUpdate.NumPages = 0i64;
  this->GlyphsToUpdate.MaxPages = 0i64;
  this->GlyphsToUpdate.Pages = 0i64;
  this->RectsToUpdate.Data = 0i64;
  this->RectsToUpdate.Size = 0i64;
  this->RectsToUpdate.Capacity = 0i64;
  p_Capacity = &this->RectsToUpdate.Capacity;
  if ( this == (Scaleform::Render::GlyphCache *)-4672i64 )
    p_Capacity = 0i64;
  this->TextInUse.Root.pPrev = (Scaleform::Render::TextMeshProvider *)p_Capacity;
  this->TextInUse.Root.pNext = (Scaleform::Render::TextMeshProvider *)p_Capacity;
  v7 = (Scaleform::Render::TextMeshProvider *)&this->TextInUse.Root.8;
  if ( this == (Scaleform::Render::GlyphCache *)-4688i64 )
    v7 = 0i64;
  this->TextInPin.Root.pPrev = v7;
  this->TextInPin.Root.pNext = v7;
  this->Notifier.vfptr = (Scaleform::Render::GlyphEvictNotifierVtbl *)&Scaleform::Render::GlyphEvictNotifier::`vftable;
  this->Notifier.vfptr = (Scaleform::Render::GlyphEvictNotifierVtbl *)&Scaleform::Render::GlyphCache::EvictNotifier::`vftable;
  this->pFontHandleManager.pObject = 0i64;
  this->pRQCaches = 0i64;
  p_Notifier = (Scaleform::Render::VectorGlyphShape *)&this->Notifier;
  if ( this == (Scaleform::Render::GlyphCache *)-4744i64 )
    p_Notifier = 0i64;
  this->VectorGlyphShapeList.Root.pPrev = p_Notifier;
  this->VectorGlyphShapeList.Root.pNext = p_Notifier;
  this->VectorGlyphCache.pTable = 0i64;
  this->pSolidFill.pObject = 0i64;
  this->pMaskFill.pObject = 0i64;
  Scaleform::Render::GlyphFitter::GlyphFitter(&this->Fitter, heap, 1024);
  Scaleform::Render::Rasterizer::Rasterizer(&this->Ras, heap);
  Scaleform::Render::GlyphScanlineFilter::GlyphScanlineFilter(&this->ScanlineFilter, 0.8888889, 0.22222222, 0.022222223);
  this->RasterData.Data.Data = 0i64;
  this->RasterData.Data.Size = 0i64;
  this->RasterData.Data.Policy.Capacity = 0i64;
  this->RasterDataSrc.Data.Data = 0i64;
  this->RasterDataSrc.Data.Size = 0i64;
  this->RasterDataSrc.Data.Policy.Capacity = 0i64;
  this->KnockOutCopy.Data.Data = 0i64;
  this->KnockOutCopy.Data.Size = 0i64;
  this->KnockOutCopy.Data.Policy.Capacity = 0i64;
  this->RasterPitch = 0;
  this->BlurStack.Data.Data = 0i64;
  this->BlurStack.Data.Size = 0i64;
  this->BlurStack.Data.Policy.Capacity = 0i64;
  this->BlurSum.Data.Data = 0i64;
  this->BlurSum.Data.Size = 0i64;
  this->BlurSum.Data.Policy.Capacity = 0i64;
  this->LHeap1.pHeap = heap;
  this->LHeap1.Granularity = 0x2000i64;
  this->LHeap1.pPagePool = 0i64;
  this->LHeap1.pLastPage = 0i64;
  this->LHeap1.MaxPages = 0i64;
  this->LHeap2.pHeap = heap;
  this->LHeap2.Granularity = 0x2000i64;
  this->LHeap2.pPagePool = 0i64;
  this->LHeap2.pLastPage = 0i64;
  this->LHeap2.MaxPages = 0i64;
  this->mStroker.vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::TessBase::`vftable;
  this->mStroker.vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::Stroker::`vftable;
  this->mStroker.pHeap = &this->LHeap2;
  this->mStroker.Path.Path.pHeap = &this->LHeap2;
  this->mStroker.Path.Path.Size = 0i64;
  this->mStroker.Path.Path.NumPages = 0i64;
  this->mStroker.Path.Path.MaxPages = 0i64;
  this->mStroker.Path.Path.Pages = 0i64;
  this->mStroker.Width = 1.0;
  this->mStroker.LineJoin = RoundJoin;
  this->mStroker.StartLineCap = RoundCap;
  this->mStroker.EndLineCap = RoundCap;
  this->mStroker.MiterLimit = 3.0;
  this->mStroker.CurveTolerance = 1.0;
  this->mStroker.IntersectionEpsilon = 0.0099999998;
  this->mStroker.Closed = 0;
  this->TmpPath1.vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::TessBase::`vftable;
  this->TmpPath1.vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::VertexPath::`vftable;
  this->TmpPath1.Vertices.pHeap = &this->LHeap1;
  this->TmpPath1.Vertices.Size = 0i64;
  this->TmpPath1.Vertices.NumPages = 0i64;
  this->TmpPath1.Vertices.MaxPages = 0i64;
  this->TmpPath1.Vertices.Pages = 0i64;
  this->TmpPath1.Paths.pHeap = &this->LHeap1;
  this->TmpPath1.Paths.Size = 0i64;
  this->TmpPath1.Paths.NumPages = 0i64;
  this->TmpPath1.Paths.MaxPages = 0i64;
  this->TmpPath1.Paths.Pages = 0i64;
  this->TmpPath2.vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::TessBase::`vftable;
  this->TmpPath2.vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::VertexPath::`vftable;
  this->TmpPath2.Vertices.pHeap = &this->LHeap2;
  this->TmpPath2.Vertices.Size = 0i64;
  this->TmpPath2.Vertices.NumPages = 0i64;
  this->TmpPath2.Vertices.MaxPages = 0i64;
  this->TmpPath2.Vertices.Pages = 0i64;
  this->TmpPath2.Paths.pHeap = &this->LHeap2;
  this->TmpPath2.Paths.Size = 0i64;
  this->TmpPath2.Paths.NumPages = 0i64;
  this->TmpPath2.Paths.MaxPages = 0i64;
  this->TmpPath2.Paths.Pages = 0i64;
  this->RasterizationCount = 0;
  *(_WORD *)&this->RasterCacheWarning = 257;
  this->Notifier.pCache = this;
  v9 = 0;
  v10 = &this->FontSizeMap[1];
  do
  {
    if ( v9 > FontSizeRamp[v4] )
    {
      ++v5;
      ++v4;
    }
    *(v10 - 1) = v5;
    if ( v9 + 1 > FontSizeRamp[v4] )
    {
      ++v5;
      ++v4;
    }
    *v10 = v5;
    v9 += 2;
    v10 += 2;
  }
  while ( v9 < 0x100 );
  v11 = Scaleform::SF_GlobalLog;
  this->pLog = Scaleform::SF_GlobalLog;
  if ( !v11 )
    this->pLog = Scaleform::Log::GetDefaultLog();
}

// File Line: 267
// RVA: 0x94A690
void __fastcall Scaleform::Render::GlyphCache::~GlyphCache(Scaleform::Render::GlyphCache *this)
{
  Scaleform::Render::PrimitiveFill *pObject; // rcx
  bool v3; // zf
  Scaleform::Render::PrimitiveFill *v4; // rcx
  Scaleform::Render::FontCacheHandleManager *v5; // rcx
  Scaleform::Render::RawImage *v6; // rcx

  this->Scaleform::RefCountBase<Scaleform::Render::GlyphCache,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::GlyphCache::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::GlyphCache,2>};
  this->Scaleform::Render::CacheBase::vfptr = (Scaleform::Render::CacheBaseVtbl *)&Scaleform::Render::GlyphCache::`vftable{for `Scaleform::Render::CacheBase};
  this->Scaleform::Render::GlyphCacheConfig::vfptr = (Scaleform::Render::GlyphCacheConfigVtbl *)&Scaleform::Render::GlyphCache::`vftable{for `Scaleform::Render::GlyphCacheConfig};
  Scaleform::Render::GlyphCache::Destroy(this);
  this->TmpPath2.vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::TessBase::`vftable;
  this->TmpPath1.vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::TessBase::`vftable;
  this->mStroker.vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::TessBase::`vftable;
  Scaleform::Render::LinearHeap::ClearAndRelease(&this->LHeap2);
  Scaleform::Render::LinearHeap::ClearAndRelease(&this->LHeap1);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->BlurSum.Data.Data);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->BlurStack.Data.Data);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->KnockOutCopy.Data.Data);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->RasterDataSrc.Data.Data);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->RasterData.Data.Data);
  Scaleform::Render::LinearHeap::ClearAndRelease(&this->Ras.LHeap);
  this->Ras.vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::TessBase::`vftable;
  Scaleform::Render::LinearHeap::ClearAndRelease(&this->Fitter.LHeap);
  this->Fitter.vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::TessBase::`vftable;
  pObject = this->pMaskFill.pObject;
  if ( pObject )
  {
    v3 = pObject->RefCount-- == 1;
    if ( v3 )
      pObject->vfptr->__vecDelDtor(pObject, 1u);
  }
  v4 = this->pSolidFill.pObject;
  if ( v4 )
  {
    v3 = v4->RefCount-- == 1;
    if ( v3 )
      v4->vfptr->__vecDelDtor(v4, 1u);
  }
  Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor>>::~HashSetBase<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor>>(&this->VectorGlyphCache);
  v5 = this->pFontHandleManager.pObject;
  if ( v5 && !_InterlockedDecrement(&v5->RefCount) )
    v5->vfptr->__vecDelDtor(v5, 1u);
  this->Notifier.vfptr = (Scaleform::Render::GlyphEvictNotifierVtbl *)&Scaleform::Render::GlyphEvictNotifier::`vftable;
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->RectsToUpdate.Data);
  Scaleform::ArrayPagedBase<Scaleform::Render::GlyphCache::UpdateRect,6,16,Scaleform::AllocatorPagedLH_POD<Scaleform::Render::GlyphCache::UpdateRect,2>>::ClearAndRelease((Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2> > *)&this->GlyphsToUpdate);
  v6 = this->UpdateBuffer.pObject;
  if ( v6 )
    ((void (__fastcall *)(Scaleform::Render::RawImage *))v6->vfptr[2].__vecDelDtor)(v6);
  Scaleform::Render::GlyphQueue::~GlyphQueue(&this->Queue);
  `eh vector destructor iterator(
    this->Textures,
    0x80ui64,
    32,
    (void (__fastcall *)(void *))Scaleform::Render::GlyphTextureMapper::~GlyphTextureMapper);
  this->Scaleform::Render::GlyphCacheConfig::vfptr = (Scaleform::Render::GlyphCacheConfigVtbl *)&Scaleform::Render::GlyphCacheConfig::`vftable;
  this->Scaleform::Render::CacheBase::vfptr = (Scaleform::Render::CacheBaseVtbl *)&Scaleform::Render::CacheBase::`vftable;
  this->Scaleform::RefCountBase<Scaleform::Render::GlyphCache,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

// File Line: 273
// RVA: 0x96D010
void __fastcall Scaleform::Render::GlyphCache::Destroy(Scaleform::Render::GlyphCache *this)
{
  unsigned int i; // ecx
  __int64 v3; // rax
  Scaleform::Render::VectorGlyphShape *p_Notifier; // rcx
  Scaleform::Render::FontCacheHandleManager *pObject; // rcx
  Scaleform::Render::FontCacheHandleManager *v6; // rcx
  Scaleform::Render::RQCacheInterface *pRQCaches; // rax

  Scaleform::Render::GlyphCache::UnpinAllSlots(this);
  Scaleform::Render::GlyphQueue::Clear(&this->Queue);
  for ( i = 0; i < this->MaxNumTextures; *(unsigned int *)((char *)&this->Textures[0].NumGlyphsToUpdate + v3) = 0 )
  {
    v3 = i++;
    v3 <<= 7;
    *(&this->Textures[0].Valid + v3) = 0;
  }
  *(_QWORD *)&this->UpdatePacker.LastX = 0i64;
  this->UpdatePacker.LastMaxHeight = 0;
  this->GlyphsToUpdate.Size = 0i64;
  this->RectsToUpdate.Size = 0i64;
  p_Notifier = (Scaleform::Render::VectorGlyphShape *)&this->Notifier;
  if ( this == (Scaleform::Render::GlyphCache *)-4744i64 )
    p_Notifier = 0i64;
  this->VectorGlyphShapeList.Root.pPrev = p_Notifier;
  this->VectorGlyphShapeList.Root.pNext = p_Notifier;
  Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor>>::~HashSetBase<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor>>(&this->VectorGlyphCache);
  pObject = this->pFontHandleManager.pObject;
  if ( pObject )
  {
    Scaleform::Render::FontCacheHandleManager::DestroyAllFonts(pObject);
    v6 = this->pFontHandleManager.pObject;
    if ( v6 && !_InterlockedDecrement(&v6->RefCount) )
      v6->vfptr->__vecDelDtor(v6, 1u);
    this->pFontHandleManager.pObject = 0i64;
  }
  pRQCaches = this->pRQCaches;
  if ( pRQCaches )
  {
    pRQCaches->pCaches[1] = 0i64;
    this->pRQCaches = 0i64;
  }
}

// File Line: 300
// RVA: 0x9603E0
void __fastcall Scaleform::Render::GlyphCache::ClearCache(Scaleform::Render::GlyphCache *this)
{
  Scaleform::Render::FontCacheHandleManager *v2; // rax

  Scaleform::Render::GlyphCache::UnpinAllSlots((Scaleform::Render::GlyphCache *)((char *)this - 24));
  Scaleform::Render::GlyphQueue::Clear((Scaleform::Render::GlyphQueue *)&this->Textures[31].pTexImg);
  v2 = 0i64;
  *(void **)((char *)&this->Queue.Notifiers.pHeapOrPtr + 4) = 0i64;
  HIDWORD(this->Queue.pEvictNotifier) = 0;
  *(_QWORD *)&this->UpdatePacker.LastY = 0i64;
  this->GlyphsToUpdate.MaxPages = 0i64;
  if ( this != (Scaleform::Render::GlyphCache *)-4720i64 )
    v2 = (Scaleform::Render::FontCacheHandleManager *)&this->TextInUse.Root.8;
  this->pFontHandleManager.pObject = v2;
  this->pRQCaches = (Scaleform::Render::RQCacheInterface *)v2;
  Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor>>::~HashSetBase<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor>>((Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor> > *)&this->pLog);
}

// File Line: 312
// RVA: 0x9B26F0
char __fastcall Scaleform::Render::GlyphCache::SetParams(
        Scaleform::Render::GlyphCache *this,
        Scaleform::Render::GlyphCacheParams *params)
{
  __int64 v3; // rcx

  *(Scaleform::Render::GlyphCacheParams *)&this->RefCount = *params;
  v3 = *(_QWORD *)&this->Param.FauxBoldRatio;
  if ( v3 && (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v3 + 32i64))(v3) )
    Scaleform::Render::GlyphCache::initialize((Scaleform::Render::GlyphCache *)((char *)this - 24));
  return 1;
}

// File Line: 345
// RVA: 0x9E88A0
void __fastcall Scaleform::Render::GlyphCache::initialize(Scaleform::Render::GlyphCache *this)
{
  unsigned int TextureWidth; // edi
  unsigned int TextureHeight; // ebx
  unsigned int NumTextures; // r14d
  unsigned int MaxSlotHeight; // r15d
  unsigned int SlotPadding; // r9d
  unsigned int TexUpdWidth; // r12d
  unsigned int TexUpdHeight; // r13d
  unsigned int v9; // eax
  unsigned int v10; // ecx
  char v11; // dl
  char i; // r8
  signed int v13; // edx
  char v14; // al
  Scaleform::Render::RawImage *v15; // rbx
  Scaleform::Render::RawImage *pObject; // rcx
  unsigned int j; // ebx
  unsigned int v18; // ecx
  Scaleform::Render::FontCacheHandleManager *v19; // rax
  Scaleform::Render::FontCacheHandleManager *v20; // rax
  Scaleform::Render::FontCacheHandleManager *v21; // rbx
  Scaleform::Render::FontCacheHandleManager *v22; // rcx
  Scaleform::Render::PrimitiveFill *v23; // rbx
  Scaleform::Render::PrimitiveFill *v24; // rcx
  bool v25; // zf
  Scaleform::Render::PrimitiveFill *v26; // rbx
  Scaleform::Render::PrimitiveFill *v27; // rcx
  Scaleform::Render::RQCacheInterface *v28; // rax
  Scaleform::Render::PrimitiveFillData ptr; // [rsp+48h] [rbp-90h] BYREF
  Scaleform::Render::PrimitiveFillData initdata; // [rsp+70h] [rbp-68h] BYREF
  Scaleform::Render::Size<unsigned long> size; // [rsp+E0h] [rbp+8h] BYREF
  Scaleform::Render::Size<unsigned long> v32; // [rsp+E8h] [rbp+10h]
  Scaleform::Render::FontCacheHandleManager *v33; // [rsp+F0h] [rbp+18h]

  Scaleform::Render::GlyphCache::Destroy(this);
  this->pTexMan = (Scaleform::Render::TextureManager *)((__int64 (__fastcall *)(Scaleform::Render::HAL *))this->pRenderer->vfptr[61].__vecDelDtor)(this->pRenderer);
  TextureWidth = this->Param.TextureWidth;
  TextureHeight = this->Param.TextureHeight;
  NumTextures = this->Param.NumTextures;
  MaxSlotHeight = this->Param.MaxSlotHeight;
  SlotPadding = this->Param.SlotPadding;
  TexUpdWidth = this->Param.TexUpdWidth;
  TexUpdHeight = this->Param.TexUpdHeight;
  LOBYTE(size.Width) = this->Param.FenceWaitOnFullCache;
  v9 = 63;
  v10 = 63;
  if ( TextureWidth >= 0x40 )
    v10 = TextureWidth - 1;
  if ( TextureHeight >= 0x40 )
    v9 = TextureHeight - 1;
  v11 = 0;
  for ( i = 0; v10; v10 >>= 1 )
    ++v11;
  for ( ; v9; v9 >>= 1 )
    ++i;
  if ( NumTextures > 0x20 )
    NumTextures = 32;
  v13 = 1 << v11;
  this->TextureWidth = v13;
  this->TextureHeight = 1 << i;
  this->MaxNumTextures = NumTextures;
  this->MaxSlotHeight = MaxSlotHeight;
  this->SlotPadding = SlotPadding;
  this->ScaleU = 1.0 / (float)v13;
  this->ScaleV = 1.0 / (float)(1 << i);
  this->ShadowQuality = this->Param.ShadowQuality;
  if ( NumTextures )
  {
    Scaleform::Render::GlyphQueue::Clear(&this->Queue);
    this->Queue.FirstTexture = 0;
    this->Queue.NumTextures = NumTextures;
    this->Queue.TextureWidth = TextureWidth;
    this->Queue.TextureHeight = TextureHeight;
    this->Queue.MaxSlotHeight = MaxSlotHeight;
    this->Queue.NumBandsInTexture = TextureHeight / MaxSlotHeight;
    this->Queue.FenceWaitOnFullCache = size.Width;
    Scaleform::ArrayUnsafeBase<Scaleform::Render::GlyphBand,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphBand,75>>::Reserve(
      &this->Queue.Bands,
      NumTextures * (TextureHeight / MaxSlotHeight),
      0i64);
    this->Queue.Bands.Size = NumTextures * (TextureHeight / MaxSlotHeight);
    this->Queue.pEvictNotifier = &this->Notifier;
    v14 = (char)this->pTexMan->vfptr[3].__vecDelDtor(this->pTexMan, 9i64);
    if ( v14 >= 0 )
    {
      if ( (v14 & 0x20) != 0 )
      {
        this->Method = TU_MultipleUpdate;
        this->UpdatePacker.Width = TexUpdWidth;
        this->UpdatePacker.Height = TexUpdHeight;
        *(_QWORD *)&this->UpdatePacker.LastX = 0i64;
        this->UpdatePacker.LastMaxHeight = 0;
        size.Width = TexUpdWidth;
        size.Height = TexUpdHeight;
        v15 = Scaleform::Render::RawImage::Create(Image_A8, 1u, &size, 0, this->pHeap, 0i64);
        pObject = this->UpdateBuffer.pObject;
        if ( pObject )
          ((void (__fastcall *)(Scaleform::Render::RawImage *))pObject->vfptr[2].__vecDelDtor)(pObject);
        this->UpdateBuffer.pObject = v15;
      }
      else
      {
        this->Method = TU_WholeImage;
      }
    }
    else
    {
      this->Method = TU_DirectMap;
    }
    for ( j = 0; j < this->MaxNumTextures; ++j )
    {
      v18 = this->TextureHeight;
      v32.Width = this->TextureWidth;
      v32.Height = v18;
      Scaleform::Render::GlyphTextureMapper::Create(
        &this->Textures[(unsigned __int64)j],
        this->Method,
        this->pHeap,
        this->pTexMan,
        (Scaleform::Render::Size<unsigned long> *)this->pFillMan);
    }
  }
  if ( !this->pFontHandleManager.pObject )
  {
    v19 = (Scaleform::Render::FontCacheHandleManager *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                         Scaleform::Memory::pGlobalHeap,
                                                         104i64);
    v33 = v19;
    if ( v19 )
    {
      Scaleform::Render::FontCacheHandleManager::FontCacheHandleManager(v19, this->pHeap, this);
      v21 = v20;
    }
    else
    {
      v21 = 0i64;
    }
    v22 = this->pFontHandleManager.pObject;
    if ( v22 && !_InterlockedDecrement(&v22->RefCount) )
      v22->vfptr->__vecDelDtor(v22, 1u);
    this->pFontHandleManager.pObject = v21;
  }
  *(_QWORD *)&initdata.Type = 4i64;
  *(_WORD *)&initdata.FillModes[0].Fill = 0;
  `eh vector constructor iterator(
    initdata.Textures,
    8ui64,
    2,
    (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>);
  initdata.pFormat = &Scaleform::Render::VertexXY16iCF32::Format;
  *(_QWORD *)&ptr.Type = 1i64;
  *(_WORD *)&ptr.FillModes[0].Fill = 0;
  `eh vector constructor iterator(
    ptr.Textures,
    8ui64,
    2,
    (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>);
  ptr.pFormat = &Scaleform::Render::VertexXY16i::Format;
  v23 = Scaleform::Render::PrimitiveFillManager::CreateFill(this->pFillMan, &initdata);
  v24 = this->pSolidFill.pObject;
  if ( v24 )
  {
    v25 = v24->RefCount-- == 1;
    if ( v25 )
      v24->vfptr->__vecDelDtor(v24, 1u);
  }
  this->pSolidFill.pObject = v23;
  v26 = Scaleform::Render::PrimitiveFillManager::CreateFill(this->pFillMan, &ptr);
  v27 = this->pMaskFill.pObject;
  if ( v27 )
  {
    v25 = v27->RefCount-- == 1;
    if ( v25 )
      v27->vfptr->__vecDelDtor(v27, 1u);
  }
  this->pMaskFill.pObject = v26;
  v28 = (Scaleform::Render::RQCacheInterface *)((__int64 (__fastcall *)(Scaleform::Render::HAL *))this->pRenderer->vfptr[63].__vecDelDtor)(this->pRenderer);
  this->pRQCaches = v28;
  v28->pCaches[1] = &this->Scaleform::Render::CacheBase;
  `eh vector destructor iterator(
    ptr.Textures,
    8ui64,
    2,
    (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::StereoImplBase>::~Ptr<Scaleform::Render::StereoImplBase>);
  `eh vector destructor iterator(
    initdata.Textures,
    8ui64,
    2,
    (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::StereoImplBase>::~Ptr<Scaleform::Render::StereoImplBase>);
}

// File Line: 454
// RVA: 0x95ED80
void __fastcall Scaleform::Render::GlyphCache::CleanUpFont(
        Scaleform::Render::GlyphCache *this,
        Scaleform::Render::FontCacheHandle *font)
{
  Scaleform::Render::VectorGlyphShape *pNext; // r8
  Scaleform::Render::GlyphCache::EvictNotifier *v5; // rax
  Scaleform::Render::VectorGlyphShape *v6; // rbx
  Scaleform::Render::VectorGlyphShape *key; // [rsp+30h] [rbp+8h] BYREF

  Scaleform::Render::GlyphCache::ApplyInUseList(this);
  Scaleform::Render::GlyphCache::UpdatePinList(this);
  Scaleform::Render::GlyphQueue::CleanUpFont(&this->Queue, font);
  pNext = this->VectorGlyphShapeList.Root.pNext;
  for ( key = pNext; ; key = v6 )
  {
    v5 = this == (Scaleform::Render::GlyphCache *)-4744i64 ? 0i64 : &this->Notifier;
    if ( pNext == (Scaleform::Render::VectorGlyphShape *)v5 )
      break;
    v6 = pNext->pNext;
    if ( pNext->Key.pFont == font )
    {
      pNext->pPrev->pNext = v6;
      pNext->pNext->pPrev = pNext->pPrev;
      Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor>>::RemoveAlt<Scaleform::Render::VectorGlyphShape *>(
        &this->VectorGlyphCache,
        &key);
    }
    pNext = v6;
  }
}

// File Line: 475
// RVA: 0x9834D0
Scaleform::Render::PrimitiveFill *__fastcall Scaleform::Render::GlyphCache::GetFill(
        Scaleform::Render::GlyphCache *this,
        Scaleform::Render::TextLayerType type,
        unsigned int textureId)
{
  Scaleform::Render::PrimitiveFill *result; // rax

  switch ( type )
  {
    case TextLayer_Background:
    case TextLayer_Selection:
    case TextLayer_Shapes:
    case TextLayer_Underline:
    case TextLayer_Cursor:
    case TextLayer_Shapes_Masked:
    case TextLayer_Underline_Masked:
      result = this->pSolidFill.pObject;
      break;
    case TextLayer_Shadow:
    case TextLayer_ShadowText:
    case TextLayer_RasterText:
      result = this->Textures[(unsigned __int64)textureId].pFill.pObject;
      break;
    case TextLayer_Mask:
      result = this->pMaskFill.pObject;
      break;
    default:
      result = 0i64;
      break;
  }
  return result;
}

// File Line: 518
// RVA: 0x9EBA70
void __fastcall Scaleform::Render::GlyphCache::partialUpdateTextures(Scaleform::Render::GlyphCache *this)
{
  unsigned int i; // r12d
  Scaleform::Render::GlyphTextureMapper *v3; // r13
  unsigned int NumGlyphsToUpdate; // eax
  unsigned __int64 v5; // rdi
  Scaleform::ArrayUnsafeLH_POD<Scaleform::Render::Texture::UpdateDesc,2> *p_RectsToUpdate; // r15
  __int64 v7; // r8
  unsigned int v8; // esi
  Scaleform::Render::GlyphCache::UpdateRect *v9; // r15
  Scaleform::Render::Texture::UpdateDesc *v10; // rdi
  Scaleform::Render::Texture::UpdateDesc *Data; // rdi
  __int64 v12; // rax
  Scaleform::Render::ImageData v13; // [rsp+20h] [rbp-69h] BYREF
  Scaleform::Render::ImageData v14; // [rsp+60h] [rbp-29h] BYREF
  __int64 v15; // [rsp+A0h] [rbp+17h]
  unsigned int v16; // [rsp+F0h] [rbp+67h]

  v15 = -2i64;
  *(_QWORD *)&v14.Format = 0i64;
  *(_DWORD *)&v14.Flags = 0x10000;
  v14.pPlanes = &v14.Plane0;
  memset(&v14.pPalette, 0, 40);
  Scaleform::Render::ImageData::operator=(&v14, &this->UpdateBuffer.pObject->Data);
  for ( i = 0; i < this->MaxNumTextures; ++i )
  {
    v3 = &this->Textures[(unsigned __int64)i];
    NumGlyphsToUpdate = v3->NumGlyphsToUpdate;
    if ( NumGlyphsToUpdate )
    {
      v5 = NumGlyphsToUpdate;
      p_RectsToUpdate = &this->RectsToUpdate;
      Scaleform::ArrayUnsafeBase<Scaleform::Render::Texture::UpdateDesc,Scaleform::AllocatorLH_POD<Scaleform::Render::Texture::UpdateDesc,2>>::Reserve(
        &this->RectsToUpdate,
        NumGlyphsToUpdate,
        0x20ui64);
      this->RectsToUpdate.Size = v5;
      v7 = 0i64;
      v16 = 0;
      v8 = 0;
      if ( LODWORD(this->GlyphsToUpdate.Size) )
      {
        do
        {
          v9 = &this->GlyphsToUpdate.Pages[(unsigned __int64)v8 >> 6][v8 & 0x3F];
          if ( v9->TextureId == i )
          {
            v10 = &this->RectsToUpdate.Data[(unsigned int)v7];
            v16 = v7 + 1;
            *(_QWORD *)&v13.Format = 0i64;
            *(_DWORD *)&v13.Flags = 0x10000;
            v13.pPlanes = &v13.Plane0;
            memset(&v13.pPalette, 0, 40);
            Scaleform::Render::ImageData::operator=(&v13, &this->UpdateBuffer.pObject->Data);
            v10->DestRect.x1 = v9->DstX;
            v10->DestRect.y1 = v9->DstY;
            v10->DestRect.x2 = v9->DstX + v9->w;
            v10->DestRect.y2 = v9->DstY + v9->h;
            v10->SourcePlane = *v14.pPlanes;
            v10->SourcePlane.pData = &v13.pPlanes->pData[v13.pPlanes->Pitch * v9->SrcY + v9->SrcX];
            v10->PlaneIndex = 0;
            if ( (v13.Flags & 2) != 0 )
            {
              v13.Flags &= ~2u;
              Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v13.pPlanes);
            }
            v13.pPlanes = &v13.Plane0;
            if ( v13.pPalette.pObject && !_InterlockedDecrement(&v13.pPalette.pObject->RefCount.Value) )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            v7 = v16;
          }
          ++v8;
        }
        while ( v8 < LODWORD(this->GlyphsToUpdate.Size) );
        p_RectsToUpdate = &this->RectsToUpdate;
      }
      Data = p_RectsToUpdate->Data;
      if ( v3->Method == 1 )
      {
        v12 = ((__int64 (__fastcall *)(Scaleform::Render::GlyphTextureImage *, Scaleform::Render::TextureManager *, __int64))v3->pTexImg.pObject->vfptr[21].__vecDelDtor)(
                v3->pTexImg.pObject,
                v3->pTexMan,
                v7);
        if ( v12 )
          (*(void (__fastcall **)(__int64, Scaleform::Render::Texture::UpdateDesc *, _QWORD, _QWORD, _QWORD))(*(_QWORD *)v12 + 144i64))(
            v12,
            Data,
            v16,
            0i64,
            *(_QWORD *)&v13.Format);
      }
      v3->NumGlyphsToUpdate = 0;
    }
  }
  this->GlyphsToUpdate.Size = 0i64;
  *(_QWORD *)&this->UpdatePacker.LastX = 0i64;
  this->UpdatePacker.LastMaxHeight = 0;
  if ( (v14.Flags & 2) != 0 )
  {
    v14.Flags &= ~2u;
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v14.pPlanes);
  }
  v14.pPlanes = &v14.Plane0;
  if ( v14.pPalette.pObject )
  {
    if ( !_InterlockedDecrement(&v14.pPalette.pObject->RefCount.Value) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
}

// File Line: 565
// RVA: 0x9DC840
void __fastcall Scaleform::Render::GlyphCache::copyImageData(
        Scaleform::Render::GlyphCache *this,
        Scaleform::Render::ImagePlane *pl,
        const char *data,
        unsigned int pitch,
        unsigned int dstX,
        unsigned int dstY,
        unsigned int w,
        unsigned int h)
{
  unsigned int v8; // ebx
  __int64 v11; // r12

  v8 = 0;
  if ( h )
  {
    v11 = pitch;
    do
    {
      memmove(&pl->pData[dstX + pl->Pitch * (v8 + dstY)], data, w);
      ++v8;
      data += v11;
    }
    while ( v8 < h );
  }
}

// File Line: 577
// RVA: 0x9FAC10
char __fastcall Scaleform::Render::GlyphCache::updateTextureGlyph(
        Scaleform::Render::GlyphCache *this,
        Scaleform::Render::GlyphNode *node)
{
  int v3; // r12d
  unsigned int x; // r14d
  unsigned int y; // r13d
  unsigned int w; // r15d
  unsigned int h; // edi
  unsigned int LastX; // r14d
  unsigned int v9; // ecx
  unsigned int LastY; // esi
  Scaleform::ArrayPagedLH_POD<Scaleform::Render::GlyphCache::UpdateRect,6,16,2> *p_GlyphsToUpdate; // rbx
  unsigned __int64 v12; // r13
  Scaleform::Render::GlyphCache::UpdateRect *v13; // rcx
  Scaleform::Render::ImagePlane *v14; // rax
  const char *data; // [rsp+40h] [rbp-49h]
  char *v17; // [rsp+48h] [rbp-41h]
  Scaleform::Render::ImageData v18; // [rsp+60h] [rbp-29h] BYREF
  unsigned int pitch; // [rsp+F0h] [rbp+67h]
  unsigned int v20; // [rsp+F8h] [rbp+6Fh]
  unsigned int v21; // [rsp+100h] [rbp+77h]

  v3 = node->pSlot->TextureId & 0x7FFF;
  data = this->RasterData.Data.Data;
  pitch = this->RasterPitch;
  x = node->mRect.x;
  v20 = x;
  y = node->mRect.y;
  v21 = y;
  w = node->mRect.w;
  h = node->mRect.h;
  v17 = (char *)this + 128 * (unsigned __int64)(node->pSlot->TextureId & 0x7FFF);
  if ( !v17[152] )
    Scaleform::Render::GlyphTextureMapper::Create(
      (Scaleform::Render::GlyphTextureMapper *)(v17 + 152),
      this->Method,
      this->pHeap,
      this->pTexMan,
      (Scaleform::Render::Size<unsigned long> *)this->pFillMan);
  this->pRQCaches->LockFlags |= 2u;
  if ( this->Method == TU_MultipleUpdate )
  {
    LastX = this->UpdatePacker.LastX;
    v9 = LastX + w;
    if ( LastX + w <= this->UpdatePacker.Width )
    {
      LastY = this->UpdatePacker.LastY;
      if ( LastY + h <= this->UpdatePacker.Height )
      {
LABEL_6:
        this->UpdatePacker.LastX = v9;
        if ( h <= this->UpdatePacker.LastMaxHeight )
        {
LABEL_14:
          *(_QWORD *)&v18.Format = 0i64;
          *(_DWORD *)&v18.Flags = 0x10000;
          v18.pPlanes = &v18.Plane0;
          memset(&v18.pPalette, 0, 40);
          Scaleform::Render::ImageData::operator=(&v18, &this->UpdateBuffer.pObject->Data);
          Scaleform::Render::GlyphCache::copyImageData(this, v18.pPlanes, data, pitch, LastX, LastY, w, h);
          ++*((_DWORD *)v17 + 69);
          p_GlyphsToUpdate = &this->GlyphsToUpdate;
          v12 = p_GlyphsToUpdate->Size >> 6;
          if ( v12 >= p_GlyphsToUpdate->NumPages )
            Scaleform::ArrayPagedBase<Scaleform::Render::GlyphCache::UpdateRect,6,16,Scaleform::AllocatorPagedLH_POD<Scaleform::Render::GlyphCache::UpdateRect,2>>::allocatePage(
              p_GlyphsToUpdate,
              p_GlyphsToUpdate->Size >> 6);
          v13 = &p_GlyphsToUpdate->Pages[v12][p_GlyphsToUpdate->Size & 0x3F];
          v13->SrcX = LastX;
          v13->SrcY = LastY;
          v13->DstX = v20;
          v13->DstY = v21;
          v13->w = w;
          v13->h = h;
          v13->TextureId = v3;
          ++p_GlyphsToUpdate->Size;
          if ( (v18.Flags & 2) != 0 )
          {
            v18.Flags &= ~2u;
            Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v18.pPlanes);
          }
          v18.pPlanes = &v18.Plane0;
          if ( v18.pPalette.pObject )
          {
            if ( !_InterlockedDecrement(&v18.pPalette.pObject->RefCount.Value) )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          }
          return 1;
        }
LABEL_13:
        this->UpdatePacker.LastMaxHeight = h;
        goto LABEL_14;
      }
    }
    this->UpdatePacker.LastY += this->UpdatePacker.LastMaxHeight;
    LastY = this->UpdatePacker.LastY;
    if ( LastY + h <= this->UpdatePacker.Height )
      goto LABEL_12;
    Scaleform::Render::GlyphCache::partialUpdateTextures(this);
    LastX = this->UpdatePacker.LastX;
    v9 = LastX + w;
    if ( LastX + w <= this->UpdatePacker.Width )
    {
      LastY = this->UpdatePacker.LastY;
      if ( LastY + h <= this->UpdatePacker.Height )
        goto LABEL_6;
    }
    this->UpdatePacker.LastY += this->UpdatePacker.LastMaxHeight;
    LastY = this->UpdatePacker.LastY;
    if ( LastY + h <= this->UpdatePacker.Height )
    {
LABEL_12:
      this->UpdatePacker.LastX = w;
      LastX = 0;
      goto LABEL_13;
    }
  }
  else
  {
    v14 = Scaleform::Render::GlyphTextureMapper::Map((Scaleform::Render::GlyphTextureMapper *)(v17 + 152));
    if ( v14 )
    {
      Scaleform::Render::GlyphCache::copyImageData(this, v14, data, pitch, x, y, w, h);
      return 1;
    }
  }
  return 0;
}

// File Line: 682
// RVA: 0x9BB4D0
void __fastcall Scaleform::Render::GlyphCache::UnlockBuffers(Scaleform::Render::GlyphCache *this)
{
  unsigned int v2; // edi
  unsigned __int64 v3; // rbx
  int v4; // eax
  __int64 v5; // rax

  if ( LODWORD(this->Queue.Notifiers.pHeapOrPtr) == 1 )
    Scaleform::Render::GlyphCache::partialUpdateTextures((Scaleform::Render::GlyphCache *)((char *)this - 16));
  v2 = 0;
  if ( LODWORD(this->pTexMan) )
  {
    while ( 1 )
    {
      v3 = (unsigned __int64)v2 << 7;
      v4 = *(_DWORD *)((char *)&this->ScaleU + v3);
      if ( v4 )
        break;
      if ( *((_BYTE *)&this->Textures[0].pTexImg.pObject + v3) )
      {
        (*(void (__fastcall **)(_QWORD))(**(_QWORD **)((char *)&this->Textures[0].Data.Plane0.pData + v3) + 144i64))(*(char **)((char *)&this->Textures[0].Data.Plane0.pData + v3));
LABEL_10:
        *((_BYTE *)&this->Textures[0].pTexImg.pObject + v3) = 0;
      }
LABEL_11:
      if ( ++v2 >= LODWORD(this->pTexMan) )
        goto LABEL_12;
    }
    if ( v4 != 2 || !*((_BYTE *)&this->Textures[0].pTexImg.pObject + v3) )
      goto LABEL_11;
    (*(void (__fastcall **)(_QWORD))(**(_QWORD **)((char *)&this->Textures[0].Data.Plane0.DataSize + v3) + 144i64))(*(unsigned __int64 *)((char *)&this->Textures[0].Data.Plane0.DataSize + v3));
    v5 = (*(__int64 (__fastcall **)(_QWORD, _QWORD))(**(_QWORD **)((char *)&this->Textures[0].Data.Plane0.DataSize + v3)
                                                   + 168i64))(
           *(unsigned __int64 *)((char *)&this->Textures[0].Data.Plane0.DataSize + v3),
           *(_QWORD *)((char *)&this->ScaleV + v3));
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v5 + 136i64))(v5);
    goto LABEL_10;
  }
LABEL_12:
  LODWORD(this->Notifier.pCache->vfptr) &= ~2u;
}

// File Line: 705
// RVA: 0x9B9C40
void __fastcall Scaleform::Render::GlyphCache::TextureLost(
        Scaleform::Render::GlyphCache *this,
        unsigned int textureId,
        unsigned int reason)
{
  __int64 v4; // rdi
  unsigned __int64 v5; // rax
  unsigned __int64 i; // r10
  Scaleform::Render::GlyphCache::UpdateRect **Pages; // r8
  Scaleform::Render::GlyphCache::UpdateRect *v8; // r9
  Scaleform::Render::GlyphCache::UpdateRect *v9; // r8
  __int64 v10; // rax

  v4 = textureId;
  Scaleform::Render::GlyphQueue::CleanUpTexture(&this->Queue, textureId);
  v5 = 0i64;
  for ( i = 0i64; v5 < this->GlyphsToUpdate.Size; ++v5 )
  {
    Pages = this->GlyphsToUpdate.Pages;
    v8 = &Pages[v5 >> 6][v5 & 0x3F];
    if ( v8->TextureId != (_DWORD)v4 )
    {
      v9 = &Pages[i >> 6][i & 0x3F];
      ++i;
      v9->SrcX = v8->SrcX;
      v9->SrcY = v8->SrcY;
      v9->DstX = v8->DstX;
      v9->DstY = v8->DstY;
      v9->w = v8->w;
      v9->h = v8->h;
      v9->TextureId = v8->TextureId;
    }
  }
  if ( i < this->GlyphsToUpdate.Size )
    this->GlyphsToUpdate.Size = i;
  v10 = v4 << 7;
  *(&this->Textures[0].Valid + v10) = 0;
  *(unsigned int *)((char *)&this->Textures[0].NumGlyphsToUpdate + v10) = 0;
}

// File Line: 722
// RVA: 0x9A7540
Scaleform::Render::FontCacheHandle *__fastcall Scaleform::Render::GlyphCache::RegisterFont(
        Scaleform::Render::GlyphCache *this,
        Scaleform::Render::Font *font)
{
  Scaleform::Render::HAL *pRenderer; // rcx
  Scaleform::Render::FontCacheHandleManager *pObject; // rcx

  if ( !this->pFontHandleManager.pObject )
  {
    pRenderer = this->pRenderer;
    if ( !pRenderer
      || !((unsigned __int8 (__fastcall *)(Scaleform::Render::HAL *))pRenderer->vfptr[4].__vecDelDtor)(pRenderer) )
    {
      return 0i64;
    }
    Scaleform::Render::GlyphCache::initialize(this);
  }
  pObject = this->pFontHandleManager.pObject;
  if ( pObject )
    return Scaleform::Render::FontCacheHandleManager::RegisterFont(pObject, font);
  return 0i64;
}

// File Line: 743
// RVA: 0x9CE4D0
Scaleform::Render::GlyphNode *__fastcall Scaleform::Render::GlyphCache::allocateGlyph(
        Scaleform::Render::GlyphCache *this,
        Scaleform::Render::TextMeshProvider *tm,
        Scaleform::Render::GlyphParam *gp,
        unsigned int w,
        unsigned int h)
{
  Scaleform::Render::GlyphQueue *p_Queue; // rsi
  Scaleform::Render::GlyphNode *result; // rax
  Scaleform::Render::GlyphNode *v8; // rbx
  Scaleform::Render::TextNotifier *Notifier; // rax

  p_Queue = &this->Queue;
  result = Scaleform::Render::GlyphQueue::AllocateGlyph(&this->Queue, gp, w, h);
  v8 = result;
  if ( result )
  {
    Notifier = Scaleform::Render::GlyphQueue::CreateNotifier(p_Queue, result, tm);
    Scaleform::Render::TextMeshProvider::AddNotifier(tm, Notifier);
    return v8;
  }
  return result;
}

// File Line: 762
// RVA: 0x9BBAB0
void __fastcall Scaleform::Render::GlyphCache::UnpinAllSlots(Scaleform::Render::GlyphCache *this)
{
  Scaleform::Render::TextMeshProvider *pNext; // rax
  Scaleform::List<Scaleform::Render::TextMeshProvider,Scaleform::Render::TextMeshProvider> *p_TextInUse; // r8
  Scaleform::Render::TextMeshProvider *v4; // r9
  unsigned __int64 *p_Capacity; // rdx
  Scaleform::Render::TextMeshProvider *v6; // rax
  Scaleform::List<Scaleform::Render::TextMeshProvider,Scaleform::Render::TextMeshProvider> *p_TextInPin; // rcx
  Scaleform::Render::TextMeshProvider *v8; // rdx
  Scaleform::Render::TextMeshProvider *v9; // rax

  pNext = this->TextInUse.Root.pNext;
  p_TextInUse = &this->TextInUse;
  v4 = 0i64;
  while ( 1 )
  {
    p_Capacity = &this->RectsToUpdate.Capacity;
    if ( this == (Scaleform::Render::GlyphCache *)-4672i64 )
      p_Capacity = 0i64;
    if ( pNext == (Scaleform::Render::TextMeshProvider *)p_Capacity )
      break;
    pNext->Flags &= 0xFFFFFFF9;
    pNext = pNext->pNext;
  }
  v6 = this->TextInPin.Root.pNext;
  p_TextInPin = &this->TextInPin;
  while ( 1 )
  {
    v8 = (Scaleform::Render::TextMeshProvider *)&p_TextInPin[-1].Root.8;
    if ( !p_TextInPin )
      v8 = 0i64;
    if ( v6 == v8 )
      break;
    v6->Flags &= 0xFFFFFFF9;
    v6 = v6->pNext;
  }
  v9 = (Scaleform::Render::TextMeshProvider *)&p_TextInUse[-1].Root.8;
  if ( !p_TextInUse )
    v9 = 0i64;
  p_TextInUse->Root.pPrev = v9;
  p_TextInUse->Root.pNext = v9;
  if ( p_TextInPin )
    v4 = (Scaleform::Render::TextMeshProvider *)&p_TextInPin[-1].Root.8;
  p_TextInPin->Root.pPrev = v4;
  p_TextInPin->Root.pNext = v4;
  Scaleform::Render::GlyphQueue::UnpinAllSlots(&this->Queue);
}

// File Line: 792
// RVA: 0x959FB0
void __fastcall Scaleform::Render::GlyphCache::ApplyInUseList(Scaleform::Render::GlyphCache *this)
{
  Scaleform::Render::TextMeshProvider *pNext; // rax
  Scaleform::List<Scaleform::Render::TextMeshProvider,Scaleform::Render::TextMeshProvider> *p_TextInUse; // r9
  __int64 v4; // rdx
  Scaleform::Render::TextMeshProvider *v5; // r11
  unsigned __int64 i; // r8
  Scaleform::Render::GlyphSlot *pSlot; // rcx

  pNext = this->TextInUse.Root.pNext;
  p_TextInUse = &this->TextInUse;
  while ( 1 )
  {
    v4 = p_TextInUse ? (__int64)&p_TextInUse[-1].Root.8 : 0i64;
    if ( pNext == (Scaleform::Render::TextMeshProvider *)v4 )
      break;
    pNext->Flags &= ~2u;
    v5 = pNext->pNext;
    for ( i = 0i64; i < pNext->Notifiers.Data.Size; ++pSlot->PinCount )
      pSlot = pNext->Notifiers.Data.Data[i++]->pSlot;
    pNext->pPrev = this->TextInPin.Root.pPrev;
    pNext->pNext = (Scaleform::Render::TextMeshProvider *)&this->TextInUse.Root.8;
    this->TextInPin.Root.pPrev->pNext = pNext;
    this->TextInPin.Root.pPrev = pNext;
    pNext->Flags |= 4u;
    pNext = v5;
  }
  if ( p_TextInUse )
  {
    p_TextInUse->Root.pPrev = (Scaleform::Render::TextMeshProvider *)&p_TextInUse[-1].Root.8;
    p_TextInUse->Root.pNext = (Scaleform::Render::TextMeshProvider *)&p_TextInUse[-1].Root.8;
  }
  else
  {
    MEMORY[0] = 0i64;
    MEMORY[8] = 0i64;
  }
}

// File Line: 813
// RVA: 0x9BF3E0
__int64 __fastcall Scaleform::Render::GlyphCache::UpdatePinList(Scaleform::Render::GlyphCache *this)
{
  Scaleform::Render::TextMeshProvider *pNext; // rbx
  unsigned __int8 v2; // bp
  Scaleform::List<Scaleform::Render::TextMeshProvider,Scaleform::Render::TextMeshProvider> *p_TextInPin; // rdi
  __int64 v4; // rax
  Scaleform::Render::TextMeshProvider *v5; // rsi

  pNext = this->TextInPin.Root.pNext;
  v2 = 0;
  p_TextInPin = &this->TextInPin;
  while ( 1 )
  {
    v4 = p_TextInPin ? (__int64)&p_TextInPin[-1].Root.8 : 0i64;
    if ( pNext == (Scaleform::Render::TextMeshProvider *)v4 )
      break;
    v5 = pNext->pNext;
    if ( (int)Scaleform::Render::TextMeshProvider::GetMeshUseStatus(pNext) < 4 )
    {
      pNext->Flags &= ~4u;
      Scaleform::Render::TextMeshProvider::UnpinSlots(pNext);
      pNext->pPrev->pNext = pNext->pNext;
      pNext->pNext->pPrev = pNext->pPrev;
      pNext->pPrev = (Scaleform::Render::TextMeshProvider *)-1i64;
      pNext->pNext = (Scaleform::Render::TextMeshProvider *)-1i64;
      v2 = 1;
    }
    pNext = v5;
  }
  return v2;
}

// File Line: 837
// RVA: 0x9E6E70
void __fastcall Scaleform::Render::GlyphCache::getGlyphBounds(
        Scaleform::Render::GlyphCache *this,
        Scaleform::Render::VectorGlyphShape *glyphShape,
        Scaleform::Render::ShapeDataInterface *shapeData)
{
  Scaleform::RefCountImplCoreVtbl *v5; // rax
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax
  float y1; // xmm1_4
  float x2; // xmm0_4
  float y2; // xmm1_4
  Scaleform::Render::Rect<float> bounds; // [rsp+28h] [rbp-39h] BYREF
  Scaleform::Render::ShapePosInfo pos; // [rsp+38h] [rbp-29h] BYREF
  char v15[16]; // [rsp+70h] [rbp+Fh] BYREF
  float coord[6]; // [rsp+80h] [rbp+1Fh] BYREF
  Scaleform::Render::Matrix2x4<float> trans; // [rsp+98h] [rbp+37h] BYREF

  if ( glyphShape->Key.HintedVector )
  {
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::Render::ShapeDataInterface *))shapeData->vfptr[1].__vecDelDtor)(shapeData) )
    {
      ((void (__fastcall *)(Scaleform::Render::Font *, _QWORD, Scaleform::Render::Rect<float> *))glyphShape->Key.pFont->pFont->vfptr[7].__vecDelDtor)(
        glyphShape->Key.pFont->pFont,
        glyphShape->Key.GlyphIndex,
        &glyphShape->Bounds);
    }
    else
    {
      vfptr = shapeData->vfptr;
      *(_OWORD *)&trans.M[0][0] = _xmm;
      *(__m128 *)&trans.M[1][0] = _xmm;
      bounds = (Scaleform::Render::Rect<float>)_xmm_f149f2caf149f2ca7149f2ca7149f2ca;
      pos.Pos = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *))vfptr[6].__vecDelDtor)(shapeData);
      LODWORD(pos.Sfactor) = (_DWORD)FLOAT_1_0;
      memset(&pos.StartX, 0, 44);
      pos.Initialized = 0;
      while ( ((unsigned int (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *, char *))shapeData->vfptr[8].__vecDelDtor)(
                shapeData,
                &pos,
                coord,
                v15) )
        Scaleform::Render::ExpandBoundsToPath<Scaleform::Render::Matrix2x4<float>>(
          shapeData,
          &trans,
          &pos,
          coord,
          &bounds);
      y1 = bounds.y1;
      glyphShape->Bounds.x1 = bounds.x1;
      x2 = bounds.x2;
      glyphShape->Bounds.y1 = y1;
      y2 = bounds.y2;
      glyphShape->Bounds.x2 = x2;
      glyphShape->Bounds.y2 = y2;
    }
  }
  else
  {
    ((void (__fastcall *)(Scaleform::Render::Font *, _QWORD, Scaleform::Render::Rect<float> *))glyphShape->Key.pFont->pFont->vfptr[7].__vecDelDtor)(
      glyphShape->Key.pFont->pFont,
      glyphShape->Key.GlyphIndex,
      &glyphShape->Bounds);
    if ( (glyphShape->Bounds.x2 <= glyphShape->Bounds.x1 || glyphShape->Bounds.y2 <= glyphShape->Bounds.y1)
      && !((unsigned __int8 (__fastcall *)(Scaleform::Render::ShapeDataInterface *))shapeData->vfptr[1].__vecDelDtor)(shapeData) )
    {
      v5 = shapeData->vfptr;
      *(_OWORD *)&trans.M[0][0] = _xmm;
      *(__m128 *)&trans.M[1][0] = _xmm;
      bounds = (Scaleform::Render::Rect<float>)_xmm_f149f2caf149f2ca7149f2ca7149f2ca;
      pos.Pos = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *))v5[6].__vecDelDtor)(shapeData);
      LODWORD(pos.Sfactor) = (_DWORD)FLOAT_1_0;
      memset(&pos.StartX, 0, 44);
      pos.Initialized = 0;
      while ( ((unsigned int (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *, char *))shapeData->vfptr[8].__vecDelDtor)(
                shapeData,
                &pos,
                coord,
                v15) )
        Scaleform::Render::ExpandBoundsToPath<Scaleform::Render::Matrix2x4<float>>(
          shapeData,
          &trans,
          &pos,
          coord,
          &bounds);
      v6 = bounds.y1;
      glyphShape->Bounds.x1 = bounds.x1;
      v7 = bounds.x2;
      glyphShape->Bounds.y1 = v6;
      v8 = bounds.y2;
      glyphShape->Bounds.x2 = v7;
      glyphShape->Bounds.y2 = v8;
    }
  }
}

// File Line: 859
// RVA: 0x9E8E60
__int64 __fastcall Scaleform::Render::GlyphCache::isOuterContourCW(
        Scaleform::Render::GlyphCache *this,
        Scaleform::Render::ShapeDataInterface *shape)
{
  float v2; // xmm8_4
  float v3; // xmm9_4
  bool v5; // di
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax
  float v7; // xmm10_4
  float v8; // xmm11_4
  float v9; // xmm15_4
  char v10; // si
  int v11; // eax
  Scaleform::RefCountImplCoreVtbl *v12; // rax
  float v13; // xmm13_4
  float v14; // xmm14_4
  float v15; // xmm12_4
  float v16; // xmm6_4
  float v17; // xmm7_4
  int i; // eax
  float v19; // xmm1_4
  float v20; // xmm0_4
  int v22[4]; // [rsp+20h] [rbp-C8h] BYREF
  float v23; // [rsp+30h] [rbp-B8h] BYREF
  float v24; // [rsp+34h] [rbp-B4h]
  float v25; // [rsp+38h] [rbp-B0h]
  float v26; // [rsp+3Ch] [rbp-ACh]
  int v27; // [rsp+48h] [rbp-A0h] BYREF
  __int64 v28; // [rsp+4Ch] [rbp-9Ch]
  __int64 v29; // [rsp+54h] [rbp-94h]
  __int64 v30; // [rsp+5Ch] [rbp-8Ch]
  __int64 v31; // [rsp+64h] [rbp-84h]
  __int64 v32; // [rsp+6Ch] [rbp-7Ch]
  int v33; // [rsp+74h] [rbp-74h]
  int v34; // [rsp+78h] [rbp-70h]
  char v35; // [rsp+7Ch] [rbp-6Ch]
  float vars0; // [rsp+130h] [rbp+48h]
  void *retaddr; // [rsp+138h] [rbp+50h]
  float v38; // [rsp+140h] [rbp+58h]

  v2 = FLOAT_1_0e10;
  v3 = FLOAT_N1_0e10;
  v5 = 1;
  vfptr = shape->vfptr;
  *(float *)&retaddr = FLOAT_N1_0e10;
  v38 = FLOAT_N1_0e10;
  vars0 = FLOAT_1_0e10;
  v7 = FLOAT_1_0e10;
  v8 = FLOAT_N1_0e10;
  v9 = FLOAT_1_0e10;
  v27 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *))vfptr[6].__vecDelDtor)(shape);
  v34 = (int)FLOAT_1_0;
  v28 = 0i64;
  v29 = 0i64;
  v30 = 0i64;
  v31 = 0i64;
  v32 = 0i64;
  v33 = 0;
  v35 = 0;
  v10 = 1;
  v11 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, int *, float *, int *))shape->vfptr[8].__vecDelDtor)(
          shape,
          &v27,
          &v23,
          v22);
  if ( !v11 )
    return 1i64;
  do
  {
    if ( !v10 && v11 == 2 )
      break;
    v10 = 0;
    v12 = shape->vfptr;
    if ( v22[0] == v22[1] )
    {
      v12[10].__vecDelDtor(shape, (unsigned int)&v27);
    }
    else
    {
      v13 = v23;
      v14 = v24;
      v15 = 0.0;
      v16 = v23;
      v17 = v24;
      for ( i = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, int *, float *))v12[9].__vecDelDtor)(
                  shape,
                  &v27,
                  &v23);
            i;
            i = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, int *, float *))shape->vfptr[9].__vecDelDtor)(
                  shape,
                  &v27,
                  &v23) )
      {
        if ( v23 < v2 )
          v2 = v23;
        if ( v24 < v7 )
          v7 = v24;
        if ( v23 > v3 )
          v3 = v23;
        if ( v24 > v8 )
          v8 = v24;
        v19 = v24 * v16;
        v20 = v23 * v17;
        v16 = v23;
        v17 = v24;
        v15 = v15 + (float)(v19 - v20);
        if ( i == 2 )
        {
          v16 = v25;
          if ( v25 < v2 )
            v2 = v25;
          v17 = v26;
          if ( v26 < v7 )
            v7 = v26;
          if ( v25 > v3 )
            v3 = v25;
          if ( v26 > v8 )
            v8 = v26;
          v15 = v15 + (float)((float)(v26 * v23) - (float)(v25 * v24));
        }
      }
      if ( v16 != v13 || v17 != v14 )
      {
        if ( v13 < v2 )
          v2 = v13;
        if ( v14 < v7 )
          v7 = v14;
        if ( v13 > v3 )
          v3 = v13;
        if ( v14 > v8 )
          v8 = v14;
        v15 = v15 + (float)((float)(v16 * v14) - (float)(v17 * v13));
      }
      if ( v2 < v9 || v7 < vars0 || v3 > *(float *)&retaddr || v8 > v38 )
      {
        vars0 = v7;
        *(float *)&retaddr = v3;
        v38 = v8;
        v9 = v2;
        v5 = v15 > 0.0;
      }
    }
    v11 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, int *, float *, int *))shape->vfptr[8].__vecDelDtor)(
            shape,
            &v27,
            &v23,
            v22);
  }
  while ( v11 );
  return v5;
} *))shape->vfptr[8].__vecDelDtor)(
            sh

// File Line: 944
// RVA: 0x9DBA10
void __fastcall Scaleform::Render::GlyphCache::copyAndTransformShape(
        Scaleform::Render::GlyphCache *this,
        Scaleform::Render::VectorGlyphShape *glyphShape,
        Scaleform::Render::ShapeDataInterface *srcShape,
        bool fauxBold)
{
  Scaleform::Render::GlyphCache *v7; // r12
  float v8; // xmm13_4
  float v9; // xmm12_4
  float v10; // xmm9_4
  int v11; // xmm6_4
  float v12; // xmm7_4
  float v13; // xmm10_4
  int v14; // r13d
  char v15; // r15
  unsigned int v16; // ecx
  float v17; // xmm6_4
  float v18; // xmm7_4
  float v19; // xmm8_4
  int v20; // xmm9_4
  int v21; // xmm11_4
  float v22; // xmm1_4
  int v23; // eax
  int v24; // r14d
  int v25; // r15d
  float v26; // xmm1_4
  float v27; // xmm0_4
  Scaleform::Render::GlyphShape *v28; // rcx
  int v29; // ebx
  int v30; // edi
  float v31; // xmm1_4
  int v32; // edi
  int v33; // ebx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *p_mStroker; // r14
  float v35; // xmm6_4
  int v36; // eax
  unsigned __int64 v37; // rdx
  float v38; // xmm13_4
  float v39; // xmm14_4
  float v40; // xmm15_4
  int LastX; // xmm6_4
  int StartY; // xmm11_4
  char v43; // bl
  int v44; // xmm2_4
  int i; // eax
  float v46; // xmm1_4
  float v47; // xmm0_4
  float v48; // xmm9_4
  float v49; // xmm8_4
  float v50; // xmm1_4
  float v51; // xmm7_4
  float y3; // xmm6_4
  double v53; // xmm0_8
  float v54; // xmm11_4
  double v55; // xmm0_8
  unsigned __int64 j; // r8
  Scaleform::Render::VertexBasic *v57; // rcx
  Scaleform::Render::VertexPath *p_TmpPath1; // r15
  int v59; // edi
  unsigned int v60; // edx
  unsigned __int64 v61; // rdi
  unsigned __int64 v62; // rcx
  __int64 v63; // rdi
  Scaleform::Render::PathBasic *v64; // rsi
  unsigned int v65; // ebx
  unsigned int v66; // edx
  unsigned __int64 v67; // r12
  unsigned __int64 v68; // rcx
  __int64 v69; // r12
  Scaleform::Render::PathBasic *v70; // rdi
  __int64 v71; // r8
  Scaleform::Render::VertexBasic *v72; // rdx
  Scaleform::Render::GlyphShape *pObject; // rax
  float y; // xmm7_4
  float x; // xmm8_4
  float Multiplier; // xmm6_4
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *Data; // rbx
  unsigned __int64 Size; // rax
  unsigned __int64 v79; // rsi
  unsigned __int64 v80; // r8
  unsigned __int64 v81; // rax
  unsigned __int64 v82; // rsi
  unsigned __int64 v83; // r8
  unsigned __int64 v84; // rax
  unsigned __int64 v85; // rsi
  unsigned __int64 v86; // r8
  int v87; // r15d
  int v88; // r14d
  unsigned int v89; // esi
  Scaleform::Render::PathBasic *v90; // r13
  __int64 v91; // rdx
  Scaleform::Render::VertexBasic *v92; // rcx
  Scaleform::Render::GlyphShape *v93; // rax
  float v94; // xmm1_4
  int v95; // ebx
  float v96; // xmm1_4
  int v97; // edi
  Scaleform::Render::GlyphShape *v98; // rax
  int Multiplier_low; // xmm0_4
  int v100; // eax
  int v101; // ecx
  int level[4]; // [rsp+48h] [rbp-80h] BYREF
  __int64 v103; // [rsp+58h] [rbp-70h]
  __int64 v104; // [rsp+60h] [rbp-68h]
  int v105; // [rsp+68h] [rbp-60h]
  char v106; // [rsp+6Ch] [rbp-5Ch]
  Scaleform::Render::ShapePosInfo pos; // [rsp+70h] [rbp-58h] BYREF
  unsigned int v108; // [rsp+A8h] [rbp-20h]
  int v109; // [rsp+ACh] [rbp-1Ch]
  Scaleform::Render::VertexPath *p_TmpPath2; // [rsp+B0h] [rbp-18h]
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v111; // [rsp+B8h] [rbp-10h] BYREF
  float v112; // [rsp+C0h] [rbp-8h]
  int v113; // [rsp+C8h] [rbp+0h] BYREF
  __int64 v114; // [rsp+CCh] [rbp+4h]
  __int64 v115; // [rsp+D4h] [rbp+Ch]
  __int64 v116; // [rsp+DCh] [rbp+14h]
  __int64 v117; // [rsp+E4h] [rbp+1Ch]
  __int64 v118; // [rsp+ECh] [rbp+24h]
  int v119; // [rsp+F4h] [rbp+2Ch]
  int v120; // [rsp+F8h] [rbp+30h]
  char v121; // [rsp+FCh] [rbp+34h]
  __int64 v122; // [rsp+100h] [rbp+38h]
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v123; // [rsp+108h] [rbp+40h] BYREF
  float v124; // [rsp+110h] [rbp+48h]
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v125; // [rsp+118h] [rbp+50h] BYREF
  float v126; // [rsp+120h] [rbp+58h]
  Scaleform::Render::ToleranceParams param; // [rsp+138h] [rbp+70h] BYREF
  __int64 v128; // [rsp+188h] [rbp+C0h]
  Scaleform::Render::GlyphCache *v129; // [rsp+278h] [rbp+1B0h]
  Scaleform::Render::VectorGlyphShape *v130; // [rsp+280h] [rbp+1B8h]
  int v131; // [rsp+288h] [rbp+1C0h]
  char v132; // [rsp+298h] [rbp+1D0h]
  int vars0; // [rsp+2A0h] [rbp+1D8h]
  void *retaddr; // [rsp+2A8h] [rbp+1E0h]
  float v135; // [rsp+2B0h] [rbp+1E8h]

  v135 = *(float *)&this;
  v128 = -2i64;
  v7 = this;
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::Render::ShapeDataInterface *))srcShape->vfptr[1].__vecDelDtor)(srcShape) )
    return;
  v8 = v135;
  param.Epsilon = FLOAT_0_0000099999997;
  v9 = FLOAT_0_001;
  param.IntersectionEpsilon = 0.001;
  *(_OWORD *)&param.FillLowerScale = _xmm;
  *(_OWORD *)&param.StrokeLowerScale = _xmm;
  *(_OWORD *)&param.Scale9LowerScale = _xmm;
  param.MinDet3D = 0.001;
  param.MinScale3D = FLOAT_0_050000001;
  param.CurveRecursionLimit = 12;
  param.CurveTolerance = v135 * 0.015625;
  param.CollinearityTolerance = v135 * 0.015625;
  *(_OWORD *)&pos.StartY = _xmm;
  *(__m128 *)&pos.StrokeBase = _xmm;
  v10 = 0.0;
  if ( v132 )
  {
    pos.Fill0 = (unsigned int)retaddr;
    v11 = LODWORD(v7->Param.FauxItalicAngle) ^ _xmm[0];
    v12 = tanf(0.0);
    pos.Pos = 1065353216;
    pos.StartX = tanf(*(float *)&v11);
    *(float *)level = v12;
    *(_QWORD *)&level[1] = 1065353216i64;
    level[3] = 0;
    *(__m128 *)&pos.StartY = _mm_and_ps(
                               _mm_add_ps(
                                 _mm_add_ps(
                                   _mm_mul_ps(
                                     _mm_shuffle_ps(
                                       (__m128)*(unsigned __int64 *)&pos.Pos,
                                       (__m128)*(unsigned __int64 *)&pos.Pos,
                                       85),
                                     *(__m128 *)&pos.StrokeBase),
                                   _mm_mul_ps(
                                     _mm_shuffle_ps(
                                       (__m128)*(unsigned __int64 *)&pos.Pos,
                                       (__m128)*(unsigned __int64 *)&pos.Pos,
                                       0),
                                     (__m128)_xmm)),
                                 _mm_and_ps(
                                   (__m128)*(unsigned __int64 *)&pos.Pos,
                                   (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v)),
                               (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>::`2::v);
    *(__m128 *)&pos.StrokeBase = _mm_and_ps(
                                   _mm_add_ps(
                                     _mm_add_ps(
                                       _mm_mul_ps(
                                         _mm_shuffle_ps(*(__m128 *)level, *(__m128 *)level, 85),
                                         *(__m128 *)&pos.StrokeBase),
                                       _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)level, *(__m128 *)level, 0), (__m128)_xmm)),
                                     _mm_and_ps(
                                       *(__m128 *)level,
                                       (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v)),
                                   (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>::`2::v);
    v13 = _mm_shuffle_ps(*(__m128 *)&pos.StrokeBase, *(__m128 *)&pos.StrokeBase, 255).m128_f32[0] - *(float *)&retaddr;
  }
  else
  {
    v13 = *(float *)&pos.Fill0;
  }
  v113 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *))srcShape->vfptr[6].__vecDelDtor)(srcShape);
  v14 = 0;
  v122 = 0i64;
  v114 = 0i64;
  v115 = 0i64;
  v116 = 0i64;
  v117 = 0i64;
  v118 = 0i64;
  v119 = 0;
  v120 = 1065353216;
  v121 = 0;
  *(_QWORD *)&pos.Pos = 0i64;
  *(_QWORD *)&pos.StartY = 0i64;
  memset(level, 0, sizeof(level));
  v103 = 0i64;
  v104 = 0i64;
  v105 = 1065353216;
  v106 = 0;
  v15 = 1;
  if ( fauxBold || vars0 )
  {
    LOBYTE(v131) = Scaleform::Render::GlyphCache::isOuterContourCW(v7, srcShape);
    p_mStroker = (Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *)&v7->mStroker;
    v111.Data = (Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *)&v7->mStroker;
    (*((void (__fastcall **)(Scaleform::Render::Stroker *))&v7->mStroker.vfptr->__vecDelDtor + 1))(&v7->mStroker);
    (*((void (__fastcall **)(Scaleform::Render::VertexPath *))&v7->TmpPath1.vfptr->__vecDelDtor + 1))(&v7->TmpPath1);
    if ( fauxBold )
      v10 = v135 * v7->Param.FauxBoldRatio;
    v35 = FLOAT_0_5;
    v7->mStroker.Width = v10 * 0.5;
    *(_QWORD *)&pos.Pos = &Scaleform::Render::StrokeScaler::`vftable;
    *(_QWORD *)&pos.StartY = &v7->mStroker;
    level[0] = 1065353216;
    *(float *)&level[1] = FLOAT_1000_0;
    *(_QWORD *)&level[2] = 0i64;
    v36 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, int *, int *, unsigned int *))srcShape->vfptr[8].__vecDelDtor)(
            srcShape,
            &v113,
            &level[2],
            &pos.Fill1);
    if ( v36 )
    {
      v38 = *(float *)&pos.NumFillBits;
      v39 = *(float *)&pos.StrokeBase;
      v40 = *(float *)&pos.FillBase;
      LastX = pos.LastX;
      StartY = pos.StartY;
      v43 = v131;
      do
      {
        if ( !v15 && v36 == 2 )
          break;
        v15 = 0;
        if ( pos.Fill1 == pos.Stroke )
        {
          srcShape->vfptr[10].__vecDelDtor(srcShape, (unsigned int)&v113);
        }
        else
        {
          *(float *)&v44 = (float)((float)(*(float *)&level[3] * v38) + (float)(v39 * *(float *)&level[2])) + v13;
          *(float *)&level[2] = (float)((float)(*(float *)&level[3] * *(float *)&LastX)
                                      + (float)(*(float *)&level[2] * *(float *)&StartY))
                              + v40;
          level[3] = v44;
          (*(void (__fastcall **)(_QWORD))(**(_QWORD **)&pos.StartY + 32i64))(*(_QWORD *)&pos.StartY);
          for ( i = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, int *, int *))srcShape->vfptr[9].__vecDelDtor)(
                      srcShape,
                      &v113,
                      &level[2]);
                i;
                i = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, int *, int *))srcShape->vfptr[9].__vecDelDtor)(
                      srcShape,
                      &v113,
                      &level[2]) )
          {
            v46 = *(float *)&level[2];
            v47 = *(float *)&level[2] * *(float *)&StartY;
            if ( i == 1 )
            {
              *(float *)&level[2] = (float)((float)(*(float *)&level[3] * *(float *)&LastX) + v47) + v40;
              *(float *)&level[3] = (float)((float)(v39 * v46) + (float)(*(float *)&level[3] * v38)) + v13;
              (*(void (__fastcall **)(_QWORD))(**(_QWORD **)&pos.StartY + 32i64))(*(_QWORD *)&pos.StartY);
            }
            else
            {
              v48 = (float)((float)(*(float *)&level[3] * *(float *)&LastX) + v47) + v40;
              *(float *)&level[2] = v48;
              *(float *)&level[3] = (float)((float)(v39 * v46) + (float)(*(float *)&level[3] * v38)) + v13;
              v49 = *(float *)&level[3];
              v50 = *(float *)&v103;
              *(float *)&v103 = (float)((float)(*((float *)&v103 + 1) * *(float *)&LastX)
                                      + (float)(*(float *)&v103 * *(float *)&StartY))
                              + v40;
              v51 = *(float *)&v103;
              *((float *)&v103 + 1) = (float)((float)(v39 * v50) + (float)(*((float *)&v103 + 1) * v38)) + v13;
              y3 = *((float *)&v103 + 1);
              v53 = (*(double (__fastcall **)(Scaleform::Render::ShapePosInfo *))(*(_QWORD *)&pos.Pos + 16i64))(&pos);
              v54 = *(float *)&v53;
              v55 = (*(double (__fastcall **)(Scaleform::Render::ShapePosInfo *))(*(_QWORD *)&pos.Pos + 24i64))(&pos);
              if ( !Scaleform::Render::TestQuadCollinearity(
                      (Scaleform::Render::TessBase *)&pos,
                      &param,
                      v54,
                      *(float *)&v55,
                      v48,
                      v49,
                      v51,
                      y3) )
                Scaleform::Render::TessellateQuadRecursively(
                  (Scaleform::Render::TessBase *)&pos,
                  &param,
                  (float)(param.CurveTolerance * 0.25) * (float)(param.CurveTolerance * 0.25),
                  v54,
                  *(float *)&v55,
                  v48,
                  v49,
                  v51,
                  y3,
                  0);
              StartY = pos.StartY;
              LastX = pos.LastX;
            }
          }
          (*((void (__fastcall **)(Scaleform::Render::Stroker *))p_mStroker->Data.Data + 5))(&v7->mStroker);
          Scaleform::Render::Stroker::CalcEquidistant(
            &v7->mStroker,
            &v7->TmpPath1,
            (Scaleform::Render::StrokerTypes::EquidistantDir)(v43 == 0));
        }
        v36 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, int *, int *, unsigned int *))srcShape->vfptr[8].__vecDelDtor)(
                srcShape,
                &v113,
                &level[2],
                &pos.Fill1);
      }
      while ( v36 );
      v9 = FLOAT_0_001;
      v8 = v135;
      v35 = FLOAT_0_5;
      glyphShape = v130;
    }
    for ( j = 0i64; j < v7->TmpPath1.Vertices.Size; ++j )
    {
      v37 = j & 0xF;
      v57 = v7->TmpPath1.Vertices.Pages[j >> 4];
      v57[v37].y = v57[v37].y * v9;
    }
    p_TmpPath1 = &v7->TmpPath1;
    p_TmpPath2 = &v7->TmpPath1;
    v59 = vars0;
    if ( vars0 )
    {
      p_TmpPath1 = &v7->TmpPath2;
      p_TmpPath2 = &v7->TmpPath2;
      (*((void (__fastcall **)(Scaleform::Render::VertexPath *, unsigned __int64, unsigned __int64))&v7->TmpPath2.vfptr->__vecDelDtor
       + 1))(
        &v7->TmpPath2,
        v37,
        j);
      (*((void (__fastcall **)(Scaleform::Render::Stroker *))p_mStroker->Data.Data + 1))(&v7->mStroker);
      v7->mStroker.Width = (float)((float)((float)v59 * v7->Param.OutlineRatio) * v8) * v35;
      v7->mStroker.LineJoin = MiterJoin;
      v60 = 0;
      v131 = 0;
      if ( v7->TmpPath1.Paths.Size )
      {
        v61 = 0i64;
        do
        {
          v62 = v61 >> 2;
          v63 = v61 & 3;
          v64 = v7->TmpPath1.Paths.Pages[v62];
          if ( v64[v63].Count > 2 )
          {
            v65 = 0;
            do
            {
              (*((void (__fastcall **)(Scaleform::Render::Stroker *))p_mStroker->Data.Data + 4))(&v7->mStroker);
              ++v65;
            }
            while ( v65 < v64[v63].Count );
            (*((void (__fastcall **)(Scaleform::Render::Stroker *))p_mStroker->Data.Data + 5))(&v7->mStroker);
            Scaleform::Render::Stroker::GenerateStroke(&v7->mStroker, &v7->TmpPath2);
            v60 = v131;
          }
          v131 = ++v60;
          v61 = v60;
        }
        while ( v60 < v7->TmpPath1.Paths.Size );
        glyphShape = v130;
      }
    }
    v66 = 0;
    v108 = 0;
    if ( !p_TmpPath1->Paths.Size )
    {
LABEL_97:
      Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndShape(glyphShape->pShape.pObject);
      (*((void (__fastcall **)(Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *))p_mStroker->Data.Data
       + 1))(p_mStroker);
      (*((void (__fastcall **)(Scaleform::Render::VertexPath *))&v7->TmpPath1.vfptr->__vecDelDtor + 1))(&v7->TmpPath1);
      (*((void (__fastcall **)(Scaleform::Render::VertexPath *))&v7->TmpPath2.vfptr->__vecDelDtor + 1))(&v7->TmpPath2);
      Scaleform::Render::LinearHeap::ClearAndRelease(&v7->LHeap1);
      Scaleform::Render::LinearHeap::ClearAndRelease(&v7->LHeap2);
      return;
    }
    v67 = 0i64;
    while ( 1 )
    {
      v68 = v67 >> 2;
      v69 = v67 & 3;
      v70 = p_TmpPath1->Paths.Pages[v68];
      if ( v70[v69].Count > 2 )
        break;
LABEL_95:
      v108 = ++v66;
      v67 = v66;
      if ( v66 >= p_TmpPath1->Paths.Size )
      {
        p_mStroker = v111.Data;
        v7 = v129;
        goto LABEL_97;
      }
    }
    v71 = v70[v69].Start & 0xF;
    v72 = p_TmpPath1->Vertices.Pages[(unsigned __int64)v70[v69].Start >> 4];
    pObject = glyphShape->pShape.pObject;
    y = v72[v71].y;
    x = v72[v71].x;
    Multiplier = pObject->Multiplier;
    v125.Data = pObject->pContainer;
    Data = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)v125.Data;
    v126 = Multiplier;
    Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt15(
      &v125,
      2 - (v14 != 0));
    Size = Data->Size;
    v79 = Size + 1;
    if ( Size + 1 >= Size )
    {
      if ( v79 <= Data->Policy.Capacity )
        goto LABEL_66;
      v80 = v79 + (v79 >> 2);
    }
    else
    {
      if ( v79 >= Data->Policy.Capacity >> 1 )
        goto LABEL_66;
      v80 = Size + 1;
    }
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      Data,
      Data,
      v80);
LABEL_66:
    Data->Size = v79;
    Data->Data[v79 - 1] = 4;
    v81 = Data->Size;
    v82 = v81 + 1;
    if ( v81 + 1 >= v81 )
    {
      if ( v82 <= Data->Policy.Capacity )
        goto LABEL_72;
      v83 = v82 + (v82 >> 2);
    }
    else
    {
      if ( v82 >= Data->Policy.Capacity >> 1 )
        goto LABEL_72;
      v83 = v81 + 1;
    }
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      Data,
      Data,
      v83);
LABEL_72:
    Data->Size = v82;
    Data->Data[v82 - 1] = 0;
    v84 = Data->Size;
    v85 = v84 + 1;
    if ( v84 + 1 >= v84 )
    {
      if ( v85 > Data->Policy.Capacity )
      {
        v86 = v85 + (v85 >> 2);
        goto LABEL_77;
      }
    }
    else if ( v85 < Data->Policy.Capacity >> 1 )
    {
      v86 = v84 + 1;
LABEL_77:
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Data,
        Data,
        v86);
    }
    Data->Size = v85;
    Data->Data[v85 - 1] = 0;
    v87 = (int)(float)(Multiplier * x);
    v109 = v87;
    Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteSInt30(
      &v125,
      v87);
    v88 = (int)(float)(Multiplier * y);
    v131 = v88;
    Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteSInt30(
      &v125,
      v88);
    v89 = 1;
    if ( v70[v69].Count > 1 )
    {
      v90 = v70;
      do
      {
        v91 = ((_BYTE)v89 + LOBYTE(v90[v69].Start)) & 0xF;
        v92 = p_TmpPath2->Vertices.Pages[(unsigned __int64)(v89 + v90[v69].Start) >> 4];
        v93 = v130->pShape.pObject;
        v94 = v93->Multiplier;
        v123.Data = v93->pContainer;
        v124 = v94;
        v95 = (int)(float)(v94 * v92[v91].x) - v87;
        v96 = v94 * v92[v91].y;
        v97 = (int)v96 - v88;
        if ( (int)v96 == v88 )
        {
          Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteHLine(
            &v123,
            v95);
        }
        else if ( v95 )
        {
          Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteLine(
            &v123,
            v95,
            v97);
        }
        else
        {
          Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteVLine(
            &v123,
            v97);
        }
        v87 += v95;
        v88 = (int)v96;
        ++v89;
      }
      while ( v89 < v90[v69].Count );
      v14 = v122;
    }
    glyphShape = v130;
    v98 = v130->pShape.pObject;
    Multiplier_low = LODWORD(v98->Multiplier);
    *(_QWORD *)&pos.StartY = v98->pContainer;
    pos.LastY = Multiplier_low;
    if ( v87 != v109 || v88 != v131 )
    {
      v100 = v109 - v87;
      v101 = v131 - v88;
      if ( v131 == v88 )
      {
        Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteHLine(
          (Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)&pos.StartY,
          v100);
      }
      else if ( v100 )
      {
        Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteLine(
          (Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)&pos.StartY,
          v100,
          v101);
      }
      else
      {
        Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteVLine(
          (Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)&pos.StartY,
          v101);
      }
    }
    Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath(glyphShape->pShape.pObject);
    v122 = (unsigned int)++v14;
    p_TmpPath1 = p_TmpPath2;
    v66 = v108;
    goto LABEL_95;
  }
  v16 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, int *, int *, unsigned int *))srcShape->vfptr[8].__vecDelDtor)(
          srcShape,
          &v113,
          &level[2],
          &pos.Fill1);
  if ( v16 )
  {
    v17 = *(float *)&pos.NumFillBits;
    v18 = *(float *)&pos.StrokeBase;
    v19 = *(float *)&pos.FillBase;
    v20 = pos.LastX;
    v21 = pos.StartY;
    do
    {
      if ( !v15 && v16 == 2 )
        break;
      v15 = 0;
      if ( pos.Fill1 == pos.Stroke )
      {
        srcShape->vfptr[10].__vecDelDtor(srcShape, (unsigned int)&v113);
      }
      else
      {
        v22 = *(float *)&level[2];
        *(float *)&level[2] = (float)((float)(*(float *)&level[3] * *(float *)&v20)
                                    + (float)(*(float *)&level[2] * *(float *)&v21))
                            + v19;
        *(float *)&level[3] = (float)((float)(*(float *)&level[3] * v17) + (float)(v18 * v22)) + v13;
        Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
          glyphShape->pShape.pObject,
          &pos,
          v16,
          pos.Fill1,
          pos.Stroke,
          LODWORD(pos.Sfactor),
          *(float *)&level[2],
          *(float *)&level[3]);
        v23 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, int *, int *))srcShape->vfptr[9].__vecDelDtor)(
                srcShape,
                &v113,
                &level[2]);
        if ( v23 )
        {
          v24 = level[0];
          v25 = pos.LastX;
          do
          {
            v26 = *(float *)&level[2];
            v27 = *(float *)&level[2] * *(float *)&v21;
            v28 = glyphShape->pShape.pObject;
            if ( v23 == 1 )
            {
              *(float *)&level[2] = (float)((float)(*(float *)&level[3] * *(float *)&v20) + v27) + v19;
              *(float *)&level[3] = (float)((float)(*(float *)&level[3] * v17) + (float)(v18 * v26)) + v13;
              v111.Data = v28->pContainer;
              v112 = v28->Multiplier;
              v29 = (int)(float)(*(float *)&level[2] * v112) - v25;
              v30 = (int)(float)(*(float *)&level[3] * v112) - v24;
              if ( v30 )
              {
                if ( v29 )
                  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteLine(
                    &v111,
                    v29,
                    v30);
                else
                  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteVLine(
                    &v111,
                    v30);
              }
              else
              {
                Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteHLine(
                  &v111,
                  v29);
              }
              v25 += v29;
              v24 += v30;
            }
            else
            {
              *(float *)&level[2] = (float)((float)(*(float *)&level[3] * *(float *)&v20) + v27) + v19;
              *(float *)&level[3] = (float)((float)(*(float *)&level[3] * v17) + (float)(v18 * v26)) + v13;
              v31 = *(float *)&v103;
              *(float *)&v103 = (float)((float)(*((float *)&v103 + 1) * *(float *)&v20)
                                      + (float)(*(float *)&v103 * *(float *)&v21))
                              + v19;
              *((float *)&v103 + 1) = (float)((float)(*((float *)&v103 + 1) * v17) + (float)(v18 * v31)) + v13;
              *(_QWORD *)&pos.StartY = v28->pContainer;
              pos.LastY = LODWORD(v28->Multiplier);
              v32 = (int)(float)(*(float *)&v103 * *(float *)&pos.LastY) - v25;
              v33 = (int)(float)(*((float *)&v103 + 1) * *(float *)&pos.LastY) - v24;
              Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteQuad(
                (Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)&pos.StartY,
                (int)(float)(*(float *)&level[2] * *(float *)&pos.LastY) - v25,
                (int)(float)(*(float *)&level[3] * *(float *)&pos.LastY) - v24,
                v32,
                v33);
              v25 += v32;
              v24 += v33;
            }
            level[0] = v24;
            pos.LastX = v25;
            v23 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, int *, int *))srcShape->vfptr[9].__vecDelDtor)(
                    srcShape,
                    &v113,
                    &level[2]);
            glyphShape = v130;
          }
          while ( v23 );
          v15 = 0;
        }
        Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ClosePath(
          glyphShape->pShape.pObject,
          &pos);
        Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath(glyphShape->pShape.pObject);
      }
      v16 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, int *, int *, unsigned int *))srcShape->vfptr[8].__vecDelDtor)(
              srcShape,
              &v113,
              &level[2],
              &pos.Fill1);
    }
    while ( v16 );
  }
  Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndShape(glyphShape->pShape.pObject);
}leform::ArrayDefaultPolicy>>::EndShape(glyphShape->pShape.pObject);
}

// File Line: 1107
// RVA: 0x966A20
Scaleform::Render::VectorGlyphShape *__fastcall Scaleform::Render::GlyphCache::CreateGlyphShape(
        Scaleform::Render::GlyphCache *this,
        Scaleform::Render::GlyphRunData *data,
        unsigned int glyphIndex,
        float screenSize,
        bool fauxBold,
        bool fauxItalic,
        unsigned int outline,
        bool needsVectorShape)
{
  Scaleform::Render::GlyphRunData *v10; // rbp
  Scaleform::Render::Font *pFont; // r15
  Scaleform::Render::ShapeDataInterface *v13; // rdi
  int v14; // esi
  unsigned int v15; // r14d
  __int64 v16; // rax
  Scaleform::Render::FontCacheHandle *pFontHandle; // r11
  unsigned __int16 v19; // r10
  Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor> >::TableType *pTable; // r9
  __int64 v21; // r8
  __int64 v22; // rcx
  unsigned __int64 *v23; // rdx
  unsigned __int64 v24; // rax
  Scaleform::Render::VectorGlyphShape **v25; // rbx
  Scaleform::Render::VectorGlyphShape *v26; // rdx
  Scaleform::Render::VectorGlyphShape *v27; // rdx
  float y2; // xmm2_4
  float x2; // xmm1_4
  float y1; // xmm0_4
  unsigned __int64 EntryCount; // rcx
  unsigned __int64 MaxVectorCacheSize; // rax
  Scaleform::Render::VectorGlyphShape *pNext; // r8
  unsigned __int64 v34; // rsi
  unsigned int v35; // esi
  unsigned int v36; // ebx
  Scaleform::Render::GlyphCache::EvictNotifier *p_Notifier; // rax
  Scaleform::Render::VectorGlyphShape *v38; // rbp
  Scaleform::Render::VectorGlyphShape *v39; // rdx
  Scaleform::Render::VectorGlyphShape *v40; // rax
  Scaleform::Render::VectorGlyphShape *v41; // rax
  Scaleform::Render::VectorGlyphShape *v42; // rsi
  Scaleform::Render::GlyphShape *v43; // rax
  Scaleform::Render::GlyphShape *v44; // rax
  Scaleform::Render::GlyphShape *v45; // rbp
  Scaleform::Render::GlyphShape *pObject; // rcx
  __int64 v47; // r14
  Scaleform::Render::GlyphRaster *v48; // rcx
  Scaleform::Render::ShapeDataInterface *v50; // rbp
  float italicOffset; // xmm6_4
  Scaleform::Render::GlyphRunData *v52; // rbx
  unsigned int v53; // edi
  Scaleform::Render::GlyphShape *v54; // rax
  Scaleform::Render::ShapeDataInterface *v55; // rax
  float v56; // xmm2_4
  float v57; // xmm1_4
  float v58; // xmm0_4
  unsigned int v59; // [rsp+40h] [rbp-88h]
  Scaleform::Render::VectorGlyphShape *key; // [rsp+50h] [rbp-78h] BYREF
  __int64 v61; // [rsp+58h] [rbp-70h]
  __int64 v62; // [rsp+60h] [rbp-68h]
  Scaleform::Render::GlyphShape *v63; // [rsp+68h] [rbp-60h]
  Scaleform::Render::ShapeDataInterface *v64; // [rsp+70h] [rbp-58h]
  unsigned int v66; // [rsp+E0h] [rbp+18h]

  v62 = -2i64;
  v10 = data;
  pFont = data->pFont;
  v13 = 0i64;
  *(_QWORD *)&data->VectorSize = 0i64;
  data->pShape = 0i64;
  data->pRaster = 0i64;
  key = (Scaleform::Render::VectorGlyphShape *)&data->GlyphBounds;
  *(_QWORD *)&data->GlyphBounds.x1 = 0i64;
  *(_QWORD *)&data->GlyphBounds.x2 = 0i64;
  data->NomHeight = ((float (__fastcall *)(Scaleform::Render::Font *))pFont->vfptr[22].__vecDelDtor)(pFont);
  v10->NomWidth = ((float (__fastcall *)(Scaleform::Render::Font *))pFont->vfptr[21].__vecDelDtor)(pFont);
  if ( (_WORD)glyphIndex == 0xFFFF )
    return 0i64;
  if ( (pFont->Flags & 0x20) == 0 )
    screenSize = 0.0;
  v14 = 0;
  v66 = 0;
  v15 = 0;
  v59 = 0;
  if ( screenSize != 0.0 )
  {
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::Render::Font *, _QWORD, _QWORD))pFont->vfptr[9].__vecDelDtor)(
           pFont,
           glyphIndex,
           (unsigned int)(int)screenSize) )
    {
      v15 = (int)screenSize;
    }
    v59 = v15;
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::Render::Font *, _QWORD, _QWORD))pFont->vfptr[8].__vecDelDtor)(
           pFont,
           glyphIndex,
           (unsigned int)(int)screenSize) )
    {
      v14 = (int)screenSize;
    }
    v66 = v14;
  }
  if ( !(fauxItalic | (fauxBold ? 2 : 0)) && !v14 && !v15 && !outline && !needsVectorShape )
  {
    v16 = (__int64)pFont->vfptr[14].__vecDelDtor(pFont, glyphIndex);
    v10->pShape = (Scaleform::Render::ShapeDataInterface *)v16;
    if ( v16 )
    {
      ((void (__fastcall *)(Scaleform::Render::Font *, _QWORD, Scaleform::Render::VectorGlyphShape *))pFont->vfptr[7].__vecDelDtor)(
        pFont,
        glyphIndex,
        key);
      return 0i64;
    }
  }
  pFontHandle = v10->pFontHandle;
  v19 = fauxItalic | (fauxBold ? 2 : 0);
  pTable = this->VectorGlyphCache.pTable;
  if ( pTable )
  {
    v21 = pTable->SizeMask & ((unsigned __int64)pFontHandle ^ (unsigned __int16)glyphIndex ^ (unsigned __int8)v14 ^ (unsigned __int8)v15 ^ (unsigned __int16)outline ^ v19 ^ ((unsigned __int64)pFontHandle >> 6));
    v22 = v21;
    v23 = &pTable[v21 + 1].EntryCount + v21;
    if ( *v23 != -2i64 && v23[1] == v21 )
    {
      while ( 1 )
      {
        if ( v23[1] == v21 )
        {
          v24 = v23[2];
          if ( *(Scaleform::Render::FontCacheHandle **)(v24 + 56) == pFontHandle
            && *(_WORD *)(v24 + 64) == (_WORD)glyphIndex
            && *(_BYTE *)(v24 + 66) == (_BYTE)v14
            && *(_BYTE *)(v24 + 67) == (_BYTE)v15
            && *(_WORD *)(v24 + 68) == v19
            && *(_WORD *)(v24 + 70) == (_WORD)outline )
          {
            break;
          }
        }
        v22 = *v23;
        if ( *v23 == -1i64 )
          goto LABEL_33;
        v23 = &pTable[v22 + 1].EntryCount + v22;
      }
      if ( v22 >= 0 )
      {
        v25 = (Scaleform::Render::VectorGlyphShape **)(&pTable[v22 + 2].EntryCount + v22);
        if ( v25 )
        {
          v26 = *v25;
          (*v25)->pPrev->pNext = (*v25)->pNext;
          v26->pNext->pPrev = v26->pPrev;
          v26->pPrev = this->VectorGlyphShapeList.Root.pPrev;
          v26->pNext = (Scaleform::Render::VectorGlyphShape *)&this->Notifier;
          this->VectorGlyphShapeList.Root.pPrev->pNext = v26;
          this->VectorGlyphShapeList.Root.pPrev = v26;
          v10->VectorSize = (unsigned __int8)(*v25)->Key.HintedVector;
          v10->RasterSize = (unsigned __int8)(*v25)->Key.HintedRaster;
          v10->pShape = (*v25)->pShape.pObject;
          v10->pRaster = (*v25)->pRaster.pObject;
          v27 = *v25;
          y2 = (*v25)->Bounds.y2;
          x2 = (*v25)->Bounds.x2;
          y1 = (*v25)->Bounds.y1;
          v10->GlyphBounds.x1 = (*v25)->Bounds.x1;
          v10->GlyphBounds.y1 = y1;
          v10->GlyphBounds.x2 = x2;
          v10->GlyphBounds.y2 = y2;
          (*((void (__fastcall **)(Scaleform::Render::MeshProvider *))&v27->Scaleform::Render::MeshProvider_KeySupport::Scaleform::Render::MeshProvider_RCImpl::Scaleform::Render::MeshProvider::vfptr->__vecDelDtor
           + 1))(&v27->Scaleform::Render::MeshProvider);
          return *v25;
        }
      }
    }
LABEL_33:
    EntryCount = pTable->EntryCount;
  }
  else
  {
    EntryCount = 0i64;
  }
  MaxVectorCacheSize = this->Param.MaxVectorCacheSize;
  if ( EntryCount > MaxVectorCacheSize )
  {
    pNext = this->VectorGlyphShapeList.Root.pNext;
    key = pNext;
    LODWORD(v34) = 0;
    if ( pTable )
      v34 = pTable->EntryCount;
    v35 = v34 - MaxVectorCacheSize;
    if ( v35 > (unsigned int)MaxVectorCacheSize )
      v35 = MaxVectorCacheSize;
    v36 = 0;
    if ( v35 )
    {
      do
      {
        p_Notifier = &this->Notifier;
        if ( this == (Scaleform::Render::GlyphCache *)-4744i64 )
          p_Notifier = 0i64;
        if ( pNext == (Scaleform::Render::VectorGlyphShape *)p_Notifier )
          break;
        v38 = pNext->pNext;
        if ( !pNext->hKeySet.pKeySet
          || pNext->hKeySet.pKeySet->Meshes.Root.pNext == (Scaleform::Render::MeshKey *)&pNext->hKeySet.pKeySet->Meshes )
        {
          v39 = key;
          key->pPrev->pNext = pNext->pNext;
          pNext->pNext->pPrev = v39->pPrev;
          Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor>>::RemoveAlt<Scaleform::Render::VectorGlyphShape *>(
            &this->VectorGlyphCache,
            &key);
        }
        pNext = v38;
        key = v38;
        ++v36;
      }
      while ( v36 < v35 );
      v15 = v59;
      v10 = data;
    }
  }
  v40 = (Scaleform::Render::VectorGlyphShape *)this->pHeap->vfptr->Alloc(this->pHeap, 128i64, 0i64);
  v61 = (__int64)v40;
  if ( v40 )
  {
    Scaleform::Render::VectorGlyphShape::VectorGlyphShape(v40, this);
    v42 = v41;
  }
  else
  {
    v42 = 0i64;
  }
  key = v42;
  v42->Key.pFont = v10->pFontHandle;
  v42->Key.GlyphIndex = glyphIndex;
  v42->Key.HintedVector = v66;
  v42->Key.HintedRaster = v15;
  v42->Key.Flags = fauxItalic | (fauxBold ? 2 : 0);
  v42->Key.Outline = (unsigned __int8)outline;
  v43 = (Scaleform::Render::GlyphShape *)this->pHeap->vfptr->Alloc(this->pHeap, 144i64, 0i64);
  v61 = (__int64)v43;
  if ( v43 )
  {
    Scaleform::Render::GlyphShape::GlyphShape(v43);
    v45 = v44;
  }
  else
  {
    v45 = 0i64;
  }
  pObject = v42->pShape.pObject;
  if ( pObject && !_InterlockedDecrement(&pObject->RefCount) )
    pObject->vfptr->__vecDelDtor(pObject, 1u);
  v42->pShape.pObject = v45;
  if ( v15 )
  {
    v47 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))this->pHeap->vfptr->Alloc)(this->pHeap, 64i64);
    v61 = v47;
    if ( v47 )
    {
      *(_QWORD *)v47 = &Scaleform::RefCountNTSImplCore::`vftable;
      *(_DWORD *)(v47 + 8) = 1;
      *(_QWORD *)v47 = &Scaleform::RefCountNTSImpl::`vftable;
      *(_QWORD *)v47 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,75>::`vftable;
      *(_QWORD *)v47 = &Scaleform::RefCountBaseNTS<Scaleform::Render::GlyphRaster,75>::`vftable;
      *(_QWORD *)v47 = &Scaleform::Render::GlyphRaster::`vftable;
      v63 = (Scaleform::Render::GlyphShape *)(v47 + 16);
      *(_QWORD *)(v47 + 16) = 0i64;
      *(_QWORD *)(v47 + 24) = 0i64;
      *(_QWORD *)(v47 + 32) = 0i64;
      *(_QWORD *)(v47 + 40) = 0i64;
      *(_QWORD *)(v47 + 48) = 0i64;
      *(_DWORD *)(v47 + 56) = 0;
    }
    else
    {
      v47 = 0i64;
    }
    v48 = v42->pRaster.pObject;
    if ( v48 )
    {
      if ( v48->RefCount-- == 1 )
        v48->vfptr->__vecDelDtor(v48, 1u);
    }
    v42->pRaster.pObject = (Scaleform::Render::GlyphRaster *)v47;
    v15 = v59;
  }
  v50 = 0i64;
  if ( !v66 )
    v50 = (Scaleform::Render::ShapeDataInterface *)pFont->vfptr[14].__vecDelDtor(pFont, glyphIndex);
  italicOffset = pFont->Descent;
  if ( v50 )
  {
    ((void (__fastcall *)(Scaleform::Render::Font *, _QWORD, Scaleform::Render::Rect<float> *))pFont->vfptr[7].__vecDelDtor)(
      pFont,
      glyphIndex,
      &v42->Bounds);
    v52 = data;
    Scaleform::Render::GlyphCache::copyAndTransformShape(
      this,
      v42,
      v50,
      fauxBold,
      fauxItalic,
      outline,
      italicOffset,
      data->NomHeight);
LABEL_80:
    v53 = v66;
    goto LABEL_81;
  }
  if ( fauxBold || fauxItalic || outline )
  {
    v54 = (Scaleform::Render::GlyphShape *)this->pHeap->vfptr->Alloc(this->pHeap, 144i64, 0i64);
    v63 = v54;
    if ( v54 )
    {
      Scaleform::Render::GlyphShape::GlyphShape(v54);
      v13 = v55;
    }
    v64 = v13;
    ((void (__fastcall *)(Scaleform::Render::Font *, _QWORD, _QWORD, Scaleform::Render::ShapeDataInterface *))pFont->vfptr[15].__vecDelDtor)(
      pFont,
      glyphIndex,
      v66,
      v13);
    Scaleform::Render::GlyphCache::getGlyphBounds(this, v42, v13);
    Scaleform::Render::GlyphCache::copyAndTransformShape(
      this,
      v42,
      v13,
      fauxBold,
      fauxItalic,
      outline,
      italicOffset,
      data->NomHeight);
    if ( v13 && !_InterlockedDecrement(&v13->RefCount) )
      v13->vfptr->__vecDelDtor(v13, 1u);
    v52 = data;
    goto LABEL_80;
  }
  Scaleform::Render::GlyphShape::Clear(v42->pShape.pObject);
  v53 = v66;
  ((void (__fastcall *)(Scaleform::Render::Font *, _QWORD, _QWORD, Scaleform::Render::GlyphShape *))pFont->vfptr[15].__vecDelDtor)(
    pFont,
    glyphIndex,
    v66,
    v42->pShape.pObject);
  Scaleform::Render::GlyphCache::getGlyphBounds(this, v42, v42->pShape.pObject);
  v52 = data;
LABEL_81:
  if ( v15 )
  {
    ((void (__fastcall *)(Scaleform::Render::Font *, _QWORD, _QWORD, Scaleform::Render::GlyphRaster *))pFont->vfptr[16].__vecDelDtor)(
      pFont,
      glyphIndex,
      v15,
      v42->pRaster.pObject);
    v42->pRaster.pObject->HintedSize = v15;
  }
  v56 = v42->Bounds.y2;
  v57 = v42->Bounds.x2;
  v58 = v42->Bounds.y1;
  v52->GlyphBounds.x1 = v42->Bounds.x1;
  v52->GlyphBounds.y1 = v58;
  v52->GlyphBounds.x2 = v57;
  v52->GlyphBounds.y2 = v56;
  v52->VectorSize = v53;
  v52->RasterSize = v15;
  v52->pShape = v42->pShape.pObject;
  v52->pRaster = v42->pRaster.pObject;
  v52->HintedNomHeight = v42->pShape.pObject->HintedSize;
  v42->pPrev = this->VectorGlyphShapeList.Root.pPrev;
  v42->pNext = (Scaleform::Render::VectorGlyphShape *)&this->Notifier;
  this->VectorGlyphShapeList.Root.pPrev->pNext = v42;
  this->VectorGlyphShapeList.Root.pPrev = v42;
  Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor>>::add<Scaleform::Render::VectorGlyphShape *>(
    &this->VectorGlyphCache,
    &this->VectorGlyphCache,
    &key,
    (unsigned __int64)v42->Key.pFont ^ ((unsigned __int64)v42->Key.pFont >> 6) ^ v42->Key.GlyphIndex ^ (unsigned __int8)v42->Key.HintedVector ^ (unsigned __int8)v42->Key.HintedRaster ^ v42->Key.Flags ^ (unsigned __int64)v42->Key.Outline);
  return v42;
}

// File Line: 1306
// RVA: 0x933E70
// local variable allocation has failed, the output may be wrong!
void __fastcall Scaleform::Render::RecursiveBlur<Scaleform::Render::ImgBlurWrapperY,Scaleform::ArrayLH_POD<float,2,Scaleform::ArrayDefaultPolicy>,Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>(
        Scaleform::Render::ImgBlurWrapperY *img,
        double radius,
        Scaleform::ArrayLH_POD<float,2,Scaleform::ArrayDefaultPolicy> *sum,
        Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *buf)
{
  __m128 v7; // xmm4
  __int64 H; // r12
  signed int W; // r13d
  float v10; // xmm1_4
  int v11; // ecx
  float v12; // xmm4_4
  int v13; // ebp
  __m128 v14; // xmm0
  float v15; // xmm4_4
  unsigned __int64 v16; // rbx
  float v17; // xmm7_4
  float v18; // xmm6_4
  float v19; // xmm0_4
  float v20; // xmm3_4
  float v21; // xmm4_4
  float v22; // xmm8_4
  float v23; // xmm3_4
  float v24; // xmm6_4
  float v25; // xmm7_4
  float v26; // xmm2_4
  float v27; // xmm0_4
  float v28; // xmm7_4
  float v29; // xmm6_4
  float v30; // xmm9_4
  float v31; // xmm8_4
  __int64 v32; // r10
  __int64 v33; // r8
  signed int v34; // r11d
  __int64 v35; // rbp
  __int128 v36; // xmm5
  __int128 v37; // xmm4
  __int128 v38; // xmm3
  __int64 v39; // rcx
  int v40; // r9d
  __int64 v41; // rbx
  __int64 v42; // r10
  unsigned __int64 v43; // rdx
  float v44; // xmm2_4
  __int64 v45; // rdx
  int v46; // ecx
  __int128 v47; // xmm2
  __int64 v48; // r9
  __int64 v49; // rcx
  unsigned __int64 v50; // rdx
  __int128 v51; // xmm1
  __int64 v52; // rcx
  __int64 v53; // rdx
  __int128 v54; // xmm1
  float v55; // xmm3_4
  float v56; // xmm4_4
  float v57; // xmm5_4
  __int64 v58; // rdx
  float v59; // xmm2_4
  float v60; // xmm2_4
  char *v61; // rdx
  int v62; // r9d
  char *v63; // rcx
  char v64; // al

  v7 = *(__m128 *)&radius;
  if ( *(float *)&radius < 0.62 )
    v7 = (__m128)LODWORD(FLOAT_0_62);
  H = img->H;
  W = img->W;
  v10 = v7.m128_f32[0];
  v11 = (int)v7.m128_f32[0];
  if ( (int)v7.m128_f32[0] != 0x80000000 && (float)v11 != v7.m128_f32[0] )
    v10 = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(v7, v7)) & 1) + v11);
  v12 = v7.m128_f32[0] * 0.5;
  v13 = (int)v10 + 3;
  if ( v12 >= 2.5 )
  {
    v15 = (float)(v12 * 0.98711002) - 0.96329999;
  }
  else
  {
    v14 = (__m128)(unsigned int)FLOAT_1_0;
    v14.m128_f32[0] = 1.0 - (float)(v12 * 0.26890999);
    v15 = 3.97156 - (float)(_mm_sqrt_ps(v14).m128_f32[0] * 4.1455402);
  }
  v16 = (int)H + 2 * v13;
  v17 = v15 * v15;
  v18 = (float)(v15 * v15) * -1.4281;
  v19 = (float)(v15 * v15) * 1.4281;
  v20 = (float)(v15 * v15) * v15;
  v21 = v15 * 2.4441299;
  v22 = v20 * 0.422205;
  v23 = v20 * 1.26661;
  v24 = v18 - v23;
  v25 = (float)((float)(v17 * 2.85619) + v21) + v23;
  v26 = 1.0 / (float)((float)((float)(v21 + 1.5782501) + v19) + v22);
  v27 = (float)((float)(v24 + v25) + v22) * v26;
  v28 = v25 * v26;
  v29 = v24 * v26;
  v30 = 1.0 - v27;
  v31 = v22 * v26;
  Scaleform::ArrayData<float,Scaleform::AllocatorLH_POD<float,2>,Scaleform::ArrayDefaultPolicy>::Resize(&sum->Data, v16);
  Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Resize(buf, v16);
  v32 = 0i64;
  v33 = v13;
  v34 = 0;
  if ( W > 0 )
  {
    v35 = H - 1 + 2i64 * v13;
    do
    {
      v36 = 0i64;
      v37 = 0i64;
      LODWORD(v38) = 0;
      v39 = v32;
      if ( v33 >= 4 )
      {
        do
        {
          v39 += 4i64;
          LODWORD(sum->Data.Data[v39 - 4]) = v32;
          LODWORD(sum->Data.Data[v39 - 3]) = v32;
          LODWORD(sum->Data.Data[v39 - 2]) = v32;
          LODWORD(sum->Data.Data[v39 - 1]) = v32;
        }
        while ( v39 < v33 - 3 );
      }
      for ( ; v39 < v33; LODWORD(sum->Data.Data[v39 - 1]) = v32 )
        ++v39;
      v40 = v32;
      v41 = v32;
      if ( H >= 4 )
      {
        v42 = v33;
        v43 = ((unsigned __int64)(H - 4) >> 2) + 1;
        v41 = 4 * v43;
        do
        {
          v44 = (float)((float)((float)((float)(unsigned __int8)img->Img[img->Sx + v34 + img->Pitch * (v40 + img->Sy)]
                                      * v30)
                              + (float)(*(float *)&v36 * v28))
                      + (float)(*(float *)&v37 * v29))
              + (float)(*(float *)&v38 * v31);
          sum->Data.Data[v42] = v44;
          *(float *)&v38 = (float)((float)((float)((float)(unsigned __int8)img->Img[img->Sx
                                                                                  + v34
                                                                                  + img->Pitch * (v40 + img->Sy + 1)]
                                                 * v30)
                                         + (float)(v44 * v28))
                                 + (float)(*(float *)&v36 * v29))
                         + (float)(*(float *)&v37 * v31);
          LODWORD(sum->Data.Data[v42 + 1]) = v38;
          v37 = COERCE_UNSIGNED_INT((float)(unsigned __int8)img->Img[img->Sx + v34 + img->Pitch * (v40 + img->Sy + 2)]);
          *(float *)&v37 = (float)((float)((float)(*(float *)&v37 * v30) + (float)(*(float *)&v38 * v28))
                                 + (float)(v44 * v29))
                         + (float)(*(float *)&v36 * v31);
          LODWORD(sum->Data.Data[v42 + 2]) = v37;
          v36 = COERCE_UNSIGNED_INT((float)(unsigned __int8)img->Img[img->Sx + v34 + img->Pitch * (v40 + img->Sy + 3)]);
          *(float *)&v36 = (float)((float)((float)(*(float *)&v36 * v30) + (float)(*(float *)&v37 * v28))
                                 + (float)(*(float *)&v38 * v29))
                         + (float)(v44 * v31);
          v42 += 4i64;
          v40 += 4;
          LODWORD(sum->Data.Data[v42 - 1]) = v36;
          --v43;
        }
        while ( v43 );
        v32 = 0i64;
      }
      if ( v41 < H )
      {
        v45 = v33 + v41;
        v32 = H - v41;
        do
        {
          v46 = v40 + img->Sy;
          ++v45;
          ++v40;
          v47 = COERCE_UNSIGNED_INT((float)(unsigned __int8)img->Img[img->Sx + v34 + img->Pitch * v46]);
          *(float *)&v47 = (float)((float)((float)(*(float *)&v47 * v30) + (float)(*(float *)&v36 * v28))
                                 + (float)(*(float *)&v37 * v29))
                         + (float)(*(float *)&v38 * v31);
          LODWORD(v38) = v37;
          v37 = v36;
          LODWORD(sum->Data.Data[v45 - 1]) = v47;
          v36 = v47;
          --v32;
        }
        while ( v32 );
      }
      v48 = v32;
      if ( v33 >= 4 )
      {
        v49 = H + v33;
        v50 = ((unsigned __int64)(v33 - 4) >> 2) + 1;
        v48 = 4 * v50;
        do
        {
          v51 = v37;
          v49 += 4i64;
          *(float *)&v51 = (float)((float)(*(float *)&v37 * v29) + (float)(*(float *)&v36 * v28))
                         + (float)(*(float *)&v38 * v31);
          v38 = v36;
          LODWORD(sum->Data.Data[v49 - 4]) = v51;
          *(float *)&v38 = (float)((float)(*(float *)&v36 * v29) + (float)(*(float *)&v51 * v28))
                         + (float)(*(float *)&v37 * v31);
          v37 = v51;
          LODWORD(sum->Data.Data[v49 - 3]) = v38;
          *(float *)&v37 = (float)((float)(*(float *)&v51 * v29) + (float)(*(float *)&v38 * v28))
                         + (float)(*(float *)&v36 * v31);
          v36 = v38;
          LODWORD(sum->Data.Data[v49 - 2]) = v37;
          *(float *)&v36 = (float)((float)(*(float *)&v38 * v29) + (float)(*(float *)&v37 * v28))
                         + (float)(*(float *)&v51 * v31);
          LODWORD(sum->Data.Data[v49 - 1]) = v36;
          --v50;
        }
        while ( v50 );
      }
      if ( v48 < v33 )
      {
        v52 = v48 + H + v33;
        v53 = v33 - v48;
        do
        {
          v54 = v37;
          ++v52;
          *(float *)&v54 = (float)((float)(*(float *)&v37 * v29) + (float)(*(float *)&v36 * v28))
                         + (float)(*(float *)&v38 * v31);
          LODWORD(v38) = v37;
          v37 = v36;
          LODWORD(sum->Data.Data[v52 - 1]) = v54;
          v36 = v54;
          --v53;
        }
        while ( v53 );
      }
      v55 = 0.0;
      v56 = 0.0;
      v57 = 0.0;
      v58 = H - 1 + 2 * v33;
      if ( v35 >= v33 )
      {
        if ( H + 2 * v33 - v33 >= 4 )
        {
          do
          {
            v58 -= 4i64;
            v59 = (float)((float)((float)(v30 * sum->Data.Data[v58 + 4]) + (float)(v57 * v28)) + (float)(v56 * v29))
                + (float)(v55 * v31);
            buf->Data[v58 + 4] = (int)(float)(v59 + 0.5);
            v55 = (float)((float)((float)(v30 * sum->Data.Data[v58 + 3]) + (float)(v59 * v28)) + (float)(v57 * v29))
                + (float)(v56 * v31);
            buf->Data[v58 + 3] = (int)(float)(v55 + 0.5);
            v56 = (float)((float)((float)(v30 * sum->Data.Data[v58 + 2]) + (float)(v55 * v28)) + (float)(v59 * v29))
                + (float)(v57 * v31);
            buf->Data[v58 + 2] = (int)(float)(v56 + 0.5);
            v57 = (float)((float)((float)(v30 * sum->Data.Data[v58 + 1]) + (float)(v56 * v28)) + (float)(v55 * v29))
                + (float)(v59 * v31);
            buf->Data[v58 + 1] = (int)(float)(v57 + 0.5);
          }
          while ( v58 >= v33 + 3 );
        }
        for ( ; v58 >= v33; buf->Data[v58 + 1] = (int)(float)(v60 + 0.5) )
        {
          v60 = (float)((float)((float)(v30 * sum->Data.Data[v58--]) + (float)(v57 * v28)) + (float)(v56 * v29))
              + (float)(v55 * v31);
          v55 = v56;
          v56 = v57;
          v57 = v60;
        }
      }
      v61 = (char *)&buf->Data[v33];
      v62 = H;
      v63 = &img->Img[img->Sx + v34 + (unsigned __int64)(img->Pitch * img->Sy)];
      do
      {
        v64 = *v61++;
        *v63 = v64;
        v63 += img->Pitch;
        --v62;
      }
      while ( v62 );
      ++v34;
    }
    while ( v34 < W );
  }
}

// File Line: 1381
// RVA: 0x9EFAB0
void __fastcall Scaleform::Render::GlyphCache::recursiveBlur(
        Scaleform::Render::GlyphCache *this,
        char *img,
        unsigned int pitch,
        unsigned int sx,
        unsigned int sy,
        unsigned int w,
        unsigned int h,
        float rx,
        float ry)
{
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *p_BlurStack; // rbx
  Scaleform::ArrayLH_POD<float,2,Scaleform::ArrayDefaultPolicy> *p_BlurSum; // rdi
  Scaleform::Render::ImgBlurWrapperY imga; // [rsp+20h] [rbp-48h] BYREF

  p_BlurStack = &this->BlurStack;
  p_BlurSum = &this->BlurSum;
  imga.Pitch = pitch;
  imga.Sx = sx;
  imga.Img = img;
  imga.Sy = sy;
  imga.W = w;
  imga.H = h;
  Scaleform::Render::RecursiveBlur<Scaleform::Render::ImgBlurWrapperX,Scaleform::ArrayLH_POD<float,2,Scaleform::ArrayDefaultPolicy>,Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>(
    (Scaleform::Render::ImgBlurWrapperX *)&imga,
    COERCE_DOUBLE((unsigned __int64)LODWORD(rx)),
    &this->BlurSum,
    (Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)&this->BlurStack);
  imga.Img = img;
  imga.Pitch = pitch;
  imga.Sx = sx;
  imga.Sy = sy;
  imga.W = w;
  imga.H = h;
  Scaleform::Render::RecursiveBlur<Scaleform::Render::ImgBlurWrapperY,Scaleform::ArrayLH_POD<float,2,Scaleform::ArrayDefaultPolicy>,Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>(
    &imga,
    COERCE_DOUBLE((unsigned __int64)LODWORD(ry)),
    p_BlurSum,
    (Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)p_BlurStack);
}

// File Line: 1395
// RVA: 0x9F39F0
void __fastcall Scaleform::Render::GlyphCache::strengthenImage(
        Scaleform::Render::GlyphCache *this,
        char *img,
        unsigned int pitch,
        unsigned int sx,
        unsigned int sy,
        signed int w,
        unsigned int h,
        float ratio,
        int bias)
{
  __int64 v10; // rbp
  __int64 v11; // rbx
  unsigned int v12; // r11d
  unsigned int v13; // r9d
  char *v14; // rcx
  unsigned int v15; // eax
  __int64 v16; // r8
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  __int64 v21; // r8
  int v22; // eax

  if ( ratio != 1.0 && h )
  {
    v10 = sx;
    v11 = h;
    v12 = sy * pitch;
    do
    {
      v13 = 0;
      v14 = &img[v10 + v12];
      if ( w >= 4 )
      {
        v15 = ((unsigned int)(w - 4) >> 2) + 1;
        v16 = v15;
        v13 = 4 * v15;
        do
        {
          v17 = bias + (int)(float)((float)((float)((unsigned __int8)*v14 - bias) * ratio) + 0.5);
          if ( v17 >= 0 )
          {
            if ( v17 > 255 )
              LOBYTE(v17) = -1;
          }
          else
          {
            LOBYTE(v17) = 0;
          }
          *v14 = v17;
          v18 = bias + (int)(float)((float)((float)((unsigned __int8)v14[1] - bias) * ratio) + 0.5);
          if ( v18 >= 0 )
          {
            if ( v18 > 255 )
              LOBYTE(v18) = -1;
          }
          else
          {
            LOBYTE(v18) = 0;
          }
          v14[1] = v18;
          v19 = bias + (int)(float)((float)((float)((unsigned __int8)v14[2] - bias) * ratio) + 0.5);
          if ( v19 >= 0 )
          {
            if ( v19 > 255 )
              LOBYTE(v19) = -1;
          }
          else
          {
            LOBYTE(v19) = 0;
          }
          v14[2] = v19;
          v20 = bias + (int)(float)((float)((float)((unsigned __int8)v14[3] - bias) * ratio) + 0.5);
          if ( v20 >= 0 )
          {
            if ( v20 > 255 )
              LOBYTE(v20) = -1;
          }
          else
          {
            LOBYTE(v20) = 0;
          }
          v14[3] = v20;
          v14 += 4;
          --v16;
        }
        while ( v16 );
      }
      if ( v13 < w )
      {
        v21 = w - v13;
        do
        {
          v22 = bias + (int)(float)((float)((float)((unsigned __int8)*v14 - bias) * ratio) + 0.5);
          if ( v22 >= 0 )
          {
            if ( v22 > 255 )
              LOBYTE(v22) = -1;
          }
          else
          {
            LOBYTE(v22) = 0;
          }
          *v14++ = v22;
          --v21;
        }
        while ( v21 );
      }
      v12 += pitch;
      --v11;
    }
    while ( v11 );
  }
}

// File Line: 1431
// RVA: 0x9C9470
void __fastcall Scaleform::Render::GlyphCache::addShapeToRasterizer(
        Scaleform::Render::GlyphCache *this,
        Scaleform::Render::ShapeDataInterface *shape,
        float scaleX,
        float scaleY)
{
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax
  char v7; // r15
  int i; // eax
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  int j; // eax
  Scaleform::Render::Rasterizer *p_Ras; // rcx
  int LastY; // r8d
  int LastX; // edx
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // [rsp+30h] [rbp-B8h] BYREF
  float v22; // [rsp+34h] [rbp-B4h]
  float v23; // [rsp+38h] [rbp-B0h]
  float y3; // [rsp+3Ch] [rbp-ACh]
  int v25; // [rsp+48h] [rbp-A0h] BYREF
  __int64 v26; // [rsp+4Ch] [rbp-9Ch]
  __int64 v27; // [rsp+54h] [rbp-94h]
  __int64 v28; // [rsp+5Ch] [rbp-8Ch]
  __int64 v29; // [rsp+64h] [rbp-84h] BYREF
  __int64 v30; // [rsp+6Ch] [rbp-7Ch]
  int v31; // [rsp+74h] [rbp-74h]
  Scaleform::Render::ToleranceParams param; // [rsp+78h] [rbp-70h] BYREF

  if ( !((unsigned __int8 (__fastcall *)(Scaleform::Render::ShapeDataInterface *))shape->vfptr[1].__vecDelDtor)(shape) )
  {
    vfptr = shape->vfptr;
    param.CurveRecursionLimit = 12;
    *(_OWORD *)&param.Epsilon = _xmm;
    *(_OWORD *)&param.FillLowerScale = _xmm;
    *(_OWORD *)&param.StrokeLowerScale = _xmm;
    param.MinDet3D = FLOAT_0_001;
    *(_OWORD *)&param.Scale9LowerScale = _xmm;
    param.MinScale3D = FLOAT_0_050000001;
    v25 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *))vfptr[6].__vecDelDtor)(shape);
    LODWORD(param.Epsilon) = (_DWORD)FLOAT_1_0;
    v26 = 0i64;
    v27 = 0i64;
    v28 = 0i64;
    v29 = 0i64;
    v30 = 0i64;
    v31 = 0;
    LOBYTE(param.CurveTolerance) = 0;
    v7 = 1;
    for ( i = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, int *, float *, char *))shape->vfptr[8].__vecDelDtor)(
                shape,
                &v25,
                &v21,
                (char *)&v29 + 4);
          i;
          i = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, int *, float *, char *))shape->vfptr[8].__vecDelDtor)(
                shape,
                &v25,
                &v21,
                (char *)&v29 + 4) )
    {
      if ( !v7 && i == 2 )
        break;
      v7 = 0;
      if ( HIDWORD(v29) == (_DWORD)v30 )
      {
        shape->vfptr[10].__vecDelDtor(shape, (unsigned int)&v25);
      }
      else
      {
        v9 = v21 * scaleX;
        v10 = v22 * scaleY;
        this->Ras.LastXf = v21 * scaleX;
        this->Ras.LastYf = v10;
        v21 = v9;
        v11 = v9 * 256.0;
        v22 = v10;
        v12 = v10 * 256.0;
        this->Ras.LastX = (int)v11;
        this->Ras.StartX = (int)v11;
        this->Ras.LastY = (int)v12;
        this->Ras.StartY = (int)v12;
        for ( j = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, int *, float *))shape->vfptr[9].__vecDelDtor)(
                    shape,
                    &v25,
                    &v21);
              j;
              j = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, int *, float *))shape->vfptr[9].__vecDelDtor)(
                    shape,
                    &v25,
                    &v21) )
        {
          p_Ras = &this->Ras;
          if ( j == 1 )
          {
            LastY = this->Ras.LastY;
            LastX = this->Ras.LastX;
            v17 = v21 * scaleX;
            v18 = v22 * scaleY;
            v21 = v17;
            this->Ras.LastXf = v17;
            v22 = v18;
            v19 = v17 * 256.0;
            this->Ras.LastYf = v18;
            v20 = v18 * 256.0;
            Scaleform::Render::Rasterizer::line(p_Ras, LastX, LastY, (int)v19, (int)v20);
            this->Ras.LastX = (int)v19;
            this->Ras.LastY = (int)v20;
          }
          else
          {
            v21 = v21 * scaleX;
            v22 = v22 * scaleY;
            y3 = y3 * scaleY;
            v23 = v23 * scaleX;
            Scaleform::Render::TessellateQuadCurve(p_Ras, &param, v21, v22, v23, y3);
          }
        }
        this->Ras.vfptr->ClosePath(&this->Ras);
      }
    }
  }
}

// File Line: 1487
// RVA: 0x9C8E00
void __fastcall Scaleform::Render::GlyphCache::addShapeAutoFit(
        Scaleform::Render::GlyphCache *this,
        Scaleform::Render::ShapeDataInterface *shape,
        int nomHeight,
        int lowerCaseTop,
        int upperCaseTop,
        float screenSize,
        float stretch)
{
  Scaleform::Render::GlyphFitter *p_Fitter; // rsi
  unsigned __int64 p_Ras; // r14
  signed int v12; // eax
  __m128i v13; // xmm2
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax
  float v15; // xmm6_4
  float v16; // xmm6_4
  Scaleform::RefCountImplCoreVtbl *v17; // rax
  char v18; // di
  int i; // eax
  int j; // eax
  int v21; // r8d
  int v22; // ecx
  int NominalFontHeight; // eax
  __int64 v24; // rdx
  Scaleform::Render::GlyphCache *v25; // rbx
  float v26; // xmm9_4
  unsigned __int64 v27; // r15
  unsigned __int64 v28; // rcx
  __int64 v29; // r15
  Scaleform::Render::GlyphFitter::ContourType *v30; // r12
  int MinY; // edx
  int v32; // ecx
  __int16 v33; // r8
  __int16 v34; // cx
  int MinX; // r9d
  __int64 v36; // rdx
  unsigned int v37; // r13d
  float v38; // xmm1_4
  float v39; // xmm0_4
  float v40; // xmm0_4
  int v41; // eax
  int v42; // edx
  int v43; // ecx
  __int16 v44; // r8
  __int16 v45; // dx
  int v46; // r9d
  int v47; // ecx
  int v48; // eax
  int v49; // r8d
  __m128i v50; // xmm1
  int v51; // eax
  int v52; // edx
  int v53; // ebx
  float v54; // xmm0_4
  float v55; // xmm0_4
  float v56; // [rsp+30h] [rbp-D0h] BYREF
  float v57; // [rsp+34h] [rbp-CCh]
  float x3; // [rsp+38h] [rbp-C8h]
  float y3; // [rsp+3Ch] [rbp-C4h]
  unsigned __int64 v60; // [rsp+48h] [rbp-B8h]
  int v61; // [rsp+50h] [rbp-B0h] BYREF
  __int64 v62; // [rsp+54h] [rbp-ACh]
  __int64 v63; // [rsp+5Ch] [rbp-A4h]
  __int64 v64; // [rsp+64h] [rbp-9Ch]
  __int64 v65; // [rsp+6Ch] [rbp-94h]
  __int64 v66; // [rsp+74h] [rbp-8Ch]
  int v67; // [rsp+7Ch] [rbp-84h]
  int v68; // [rsp+80h] [rbp-80h]
  char v69; // [rsp+84h] [rbp-7Ch]
  int v70[6]; // [rsp+88h] [rbp-78h] BYREF
  Scaleform::Render::ToleranceParams param; // [rsp+A0h] [rbp-60h] BYREF
  Scaleform::Render::GlyphFitter::VertexType v73; // [rsp+168h] [rbp+68h]
  Scaleform::Render::GlyphFitter::VertexType v74; // [rsp+168h] [rbp+68h]

  p_Fitter = &this->Fitter;
  p_Ras = (unsigned __int64)this;
  (*((void (__fastcall **)(Scaleform::Render::GlyphFitter *))&this->Fitter.vfptr->__vecDelDtor + 1))(&this->Fitter);
  if ( !((unsigned __int8 (__fastcall *)(Scaleform::Render::ShapeDataInterface *))shape->vfptr[1].__vecDelDtor)(shape) )
  {
    param.IntersectionEpsilon = 0.001;
    param.MinDet3D = 0.001;
    param.CurveRecursionLimit = 12;
    *(_OWORD *)&param.FillLowerScale = _xmm;
    v12 = (int)(float)(screenSize * 64.0);
    *(_OWORD *)&param.Scale9LowerScale = _xmm;
    if ( v12 > 2048 )
      v12 = 2048;
    *(_DWORD *)(p_Ras + 5056) = v12;
    v13 = _mm_cvtsi32_si128(v12);
    vfptr = shape->vfptr;
    v15 = _mm_cvtepi32_ps(v13).m128_f32[0];
    *(float *)v13.m128i_i32 = (float)(v15 * 0.5) / screenSize;
    v16 = v15 / (float)nomHeight;
    param.Epsilon = FLOAT_0_0000099999997;
    *(_OWORD *)&param.StrokeLowerScale = _xmm;
    param.MinScale3D = FLOAT_0_050000001;
    LODWORD(param.CurveTolerance) = v13.m128i_i32[0];
    LODWORD(param.CollinearityTolerance) = v13.m128i_i32[0];
    LODWORD(p_Ras) = 0;
    v61 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *))vfptr[6].__vecDelDtor)(shape);
    v17 = shape->vfptr;
    v60 = 0i64;
    v62 = 0i64;
    v63 = 0i64;
    v64 = 0i64;
    v65 = 0i64;
    v66 = 0i64;
    v67 = 0;
    v68 = 1065353216;
    v69 = 0;
    v18 = 1;
    for ( i = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, int *, float *, int *))v17[8].__vecDelDtor)(
                shape,
                &v61,
                &v56,
                v70);
          i;
          i = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, int *, float *, int *))shape->vfptr[8].__vecDelDtor)(
                shape,
                &v61,
                &v56,
                v70) )
    {
      if ( !v18 && i == 2 )
        break;
      v18 = 0;
      if ( v70[0] == v70[1] )
      {
        shape->vfptr[10].__vecDelDtor(shape, (unsigned int)&v61);
      }
      else
      {
        v56 = v56 * v16;
        LODWORD(v57) = COERCE_UNSIGNED_INT(v57 * v16) ^ _xmm[0];
        Scaleform::Render::GlyphFitter::MoveTo(p_Fitter, v56, v57);
        for ( j = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, int *, float *))shape->vfptr[9].__vecDelDtor)(
                    shape,
                    &v61,
                    &v56);
              j;
              j = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, int *, float *))shape->vfptr[9].__vecDelDtor)(
                    shape,
                    &v61,
                    &v56) )
        {
          v56 = v56 * v16;
          LODWORD(v57) = COERCE_UNSIGNED_INT(v57 * v16) ^ _xmm[0];
          if ( j == 1 )
          {
            Scaleform::Render::GlyphFitter::LineTo(p_Fitter, v56, v57);
          }
          else
          {
            LODWORD(y3) = COERCE_UNSIGNED_INT(y3 * v16) ^ _xmm[0];
            x3 = x3 * v16;
            Scaleform::Render::TessellateQuadCurve(p_Fitter, &param, v56, v57, x3, y3);
          }
        }
        p_Fitter->vfptr->ClosePath(p_Fitter);
      }
    }
    v21 = (int)screenSize;
    p_Fitter->UnitsPerPixelX = 1;
    if ( (int)screenSize )
      v22 = p_Fitter->NominalFontHeight / v21;
    else
      v22 = 1;
    NominalFontHeight = p_Fitter->NominalFontHeight;
    p_Fitter->UnitsPerPixelY = v22;
    v24 = (unsigned int)(NominalFontHeight >> 31);
    LODWORD(v24) = NominalFontHeight % v22;
    p_Fitter->SnappedHeight = v22 * (NominalFontHeight / v22);
    if ( v21 )
    {
      Scaleform::Render::GlyphFitter::removeDuplicateClosures(p_Fitter);
      Scaleform::Render::GlyphFitter::computeBounds(p_Fitter);
      if ( p_Fitter->MaxY > p_Fitter->MinY )
      {
        Scaleform::Render::GlyphFitter::detectEvents(p_Fitter, FitY);
        Scaleform::Render::GlyphFitter::computeLerpRamp(
          p_Fitter,
          FitY,
          p_Fitter->UnitsPerPixelY,
          p_Fitter->MinY + (p_Fitter->MaxY - p_Fitter->MinY) / 3,
          (int)(float)((float)lowerCaseTop * v16),
          (int)(float)((float)upperCaseTop * v16));
      }
    }
    v25 = this;
    v26 = 1.0 / (float)this->Fitter.UnitsPerPixelY;
    if ( this->Fitter.Contours.Size )
    {
      v27 = 0i64;
      do
      {
        v28 = v27;
        v29 = v27 & 3;
        v30 = v25->Fitter.Contours.Pages[v28 >> 2];
        if ( v30[v29].NumVertices > 2 )
        {
          MinY = p_Fitter->MinY;
          v73 = v25->Fitter.Vertices.Pages[(unsigned __int64)v30[v29].StartVertex >> 4][v30[v29].StartVertex & 0xF];
          v32 = v73.y - MinY;
          if ( v32 < 0 || v32 >= SLODWORD(p_Fitter->LerpRampY.Size) )
            v33 = HIWORD(*(_DWORD *)&v25->Fitter.Vertices.Pages[(unsigned __int64)v30[v29].StartVertex >> 4][v30[v29].StartVertex & 0xF]);
          else
            v33 = MinY + p_Fitter->LerpRampY.Array[v32];
          v34 = (__int16)v25->Fitter.Vertices.Pages[(unsigned __int64)v30[v29].StartVertex >> 4][v30[v29].StartVertex & 0xF];
          MinX = p_Fitter->MinX;
          v36 = (unsigned int)(v73.x - MinX);
          if ( v73.x - MinX >= 0 && (int)v36 < SLODWORD(p_Fitter->LerpRampX.Size) )
            v34 = MinX + p_Fitter->LerpRampX.Array[(int)v36];
          p_Ras = (unsigned __int64)&v25->Ras;
          v37 = 1;
          v38 = (float)-v33 * v26;
          v25->Ras.LastYf = v38;
          v39 = (float)((float)v34 * v26) * stretch;
          v25->Ras.LastXf = v39;
          v40 = v39 * 256.0;
          v25->Ras.LastX = (int)v40;
          v25->Ras.StartX = (int)v40;
          v41 = (int)(float)(v38 * 256.0);
          v25->Ras.LastY = v41;
          for ( v25->Ras.StartY = v41; v37 < v30[v29].NumVertices; *(_DWORD *)(p_Ras + 704) = (int)v55 )
          {
            v42 = p_Fitter->MinY;
            v74 = v25->Fitter.Vertices.Pages[(unsigned __int64)(v37 + v30[v29].StartVertex) >> 4][((_BYTE)v37
                                                                                                 + LOBYTE(v30[v29].StartVertex)) & 0xF];
            v43 = v74.y - v42;
            if ( v43 < 0 || v43 >= SLODWORD(p_Fitter->LerpRampY.Size) )
              v44 = HIWORD(*(_DWORD *)&v25->Fitter.Vertices.Pages[(unsigned __int64)(v37 + v30[v29].StartVertex) >> 4][((_BYTE)v37 + LOBYTE(v30[v29].StartVertex)) & 0xF]);
            else
              v44 = v42 + p_Fitter->LerpRampY.Array[v43];
            v45 = (__int16)v25->Fitter.Vertices.Pages[(unsigned __int64)(v37 + v30[v29].StartVertex) >> 4][((_BYTE)v37 + LOBYTE(v30[v29].StartVertex)) & 0xF];
            v46 = p_Fitter->MinX;
            v47 = v74.x - v46;
            if ( v47 >= 0 && v47 < SLODWORD(p_Fitter->LerpRampX.Size) )
              v45 = v46 + p_Fitter->LerpRampX.Array[v47];
            v48 = v44;
            v49 = *(_DWORD *)(p_Ras + 708);
            v50 = _mm_cvtsi32_si128(-v48);
            v51 = v45;
            v52 = *(_DWORD *)(p_Ras + 704);
            *(float *)v50.m128i_i32 = _mm_cvtepi32_ps(v50).m128_f32[0] * v26;
            *(_DWORD *)(p_Ras + 716) = v50.m128i_i32[0];
            v53 = (int)(float)(*(float *)v50.m128i_i32 * 256.0);
            v54 = (float)((float)v51 * v26) * stretch;
            *(float *)(p_Ras + 712) = v54;
            v55 = v54 * 256.0;
            Scaleform::Render::Rasterizer::line((Scaleform::Render::Rasterizer *)p_Ras, v52, v49, (int)v55, v53);
            *(_DWORD *)(p_Ras + 708) = v53;
            v25 = this;
            ++v37;
          }
          (*(void (__fastcall **)(unsigned __int64, unsigned int))(*(_QWORD *)p_Ras + 40i64))(p_Ras, v36);
          LODWORD(p_Ras) = v60;
        }
        p_Ras = (unsigned int)(p_Ras + 1);
        v27 = (unsigned int)p_Ras;
        v60 = p_Ras;
      }
      while ( (unsigned int)p_Ras < v25->Fitter.Contours.Size );
    }
    (*((void (__fastcall **)(Scaleform::Render::GlyphFitter *, __int64))&p_Fitter->vfptr->__vecDelDtor + 1))(
      p_Fitter,
      v24);
  }
}

// File Line: 1602
// RVA: 0x980A90
// local variable allocation has failed, the output may be wrong!
float __fastcall Scaleform::Render::GlyphCache::GetCachedFontSize(
        Scaleform::Render::GlyphCache *this,
        Scaleform::Render::GlyphParam *gp,
        double screenSize,
        bool exactFit)
{
  int v5; // edx
  __int64 v6; // rcx
  int v7; // eax
  int v8; // ecx
  float v9; // xmm1_4

  if ( !exactFit )
  {
    if ( (gp->Flags & 1) != 0 )
    {
      *(float *)&screenSize = (float)(*(float *)&screenSize * 4.0) + 0.5;
      v8 = (int)*(float *)&screenSize;
      if ( (int)*(float *)&screenSize != 0x80000000 && (float)v8 != *(float *)&screenSize )
        *(float *)&screenSize = (float)(v8
                                      - (_mm_movemask_ps(_mm_unpacklo_ps(*(__m128 *)&screenSize, *(__m128 *)&screenSize)) & 1));
      *(float *)&screenSize = *(float *)&screenSize * 0.25;
    }
    else
    {
      v5 = (int)*(float *)&screenSize;
      if ( (int)*(float *)&screenSize != 0x80000000 && (float)v5 != *(float *)&screenSize )
        *(float *)&screenSize = (float)(v5
                                      - (_mm_movemask_ps(_mm_unpacklo_ps(*(__m128 *)&screenSize, *(__m128 *)&screenSize)) & 1));
      v6 = ((unsigned int)((int)*(float *)&screenSize + 3) >> 2) + (int)*(float *)&screenSize;
      v7 = 255;
      if ( (unsigned int)v6 <= 0xFF )
        v7 = FontSizeRamp[(unsigned __int8)this->FontSizeMap[v6] + 1];
      *(float *)&screenSize = (float)v7;
    }
  }
  v9 = (float)(this->MaxSlotHeight - 2 * this->SlotPadding);
  if ( *(float *)&screenSize <= (float)(v9 * this->Param.MaxRasterScale) && *(float *)&screenSize > v9 )
    *(float *)&screenSize = (float)(this->MaxSlotHeight - 2 * this->SlotPadding);
  return *(float *)&screenSize;
}

// File Line: 1629
// RVA: 0x980B80
// local variable allocation has failed, the output may be wrong!
float __fastcall Scaleform::Render::GlyphCache::GetCachedShadowSize(
        Scaleform::Render::GlyphCache *this,
        double screenSize,
        Scaleform::Render::GlyphRaster *ras)
{
  float result; // xmm0_4
  int v5; // ecx
  int v6; // eax
  signed int v7; // eax

  if ( ras )
    return (float)(int)ras->HintedSize;
  v5 = (int)*(float *)&screenSize;
  if ( (int)*(float *)&screenSize != 0x80000000 && (float)v5 != *(float *)&screenSize )
    *(float *)&screenSize = (float)(v5
                                  - (_mm_movemask_ps(_mm_unpacklo_ps(*(__m128 *)&screenSize, *(__m128 *)&screenSize)) & 1));
  v6 = 255;
  if ( (unsigned int)(int)*(float *)&screenSize <= 0xFF )
    v6 = FontSizeRamp[(unsigned __int8)this->FontSizeMap[*(float *)&screenSize] + 1];
  result = (float)v6;
  v7 = this->MaxSlotHeight - 2 * this->SlotPadding;
  if ( result > (float)v7 )
    return (float)v7;
  return result;
}

// File Line: 1639
// RVA: 0x9E7450
Scaleform::Render::GlyphNode *__fastcall Scaleform::Render::GlyphCache::getPrerasterizedGlyph(
        Scaleform::Render::GlyphCache *this,
        Scaleform::Render::GlyphRunData *data,
        Scaleform::Render::TextMeshProvider *tm,
        Scaleform::Render::GlyphParam *gp)
{
  Scaleform::Render::GlyphRaster *pRaster; // rsi
  unsigned int SlotPadding; // ebp
  int v8; // ebx
  int v9; // r12d
  unsigned int v10; // r15d
  unsigned int MaxSlotHeight; // r14d
  Scaleform::Render::GlyphNode *Glyph; // rax
  Scaleform::Render::GlyphNode *v13; // r15
  Scaleform::Render::TextNotifier *Notifier; // rax
  unsigned __int64 v15; // rbx
  char *v16; // rcx
  unsigned int i; // ebx
  bool v18; // zf
  unsigned int v19; // [rsp+60h] [rbp+8h]

  pRaster = data->pRaster;
  if ( pRaster->Height + 2 * this->SlotPadding < this->MaxSlotHeight
    || ((unsigned __int8 (__fastcall *)(Scaleform::Render::ShapeDataInterface *))data->pShape->vfptr[1].__vecDelDtor)(data->pShape) )
  {
    SlotPadding = this->SlotPadding;
    v8 = -(pRaster->OriginX + SlotPadding);
    v9 = -(pRaster->OriginY + SlotPadding);
    v10 = 2 * SlotPadding + pRaster->Width + 1;
    MaxSlotHeight = pRaster->Height + SlotPadding + SlotPadding + 1;
    v19 = v10;
    if ( MaxSlotHeight > this->MaxSlotHeight )
    {
      MaxSlotHeight = this->MaxSlotHeight;
      if ( this->RasterTooBigWarning )
      {
        Scaleform::Render::GlyphCache::LogWarning(
          this,
          "Warning: Raster glyph is too big - increase GlyphCacheParams.MaxSlotHeight");
        this->RasterTooBigWarning = 0;
      }
    }
    Glyph = Scaleform::Render::GlyphQueue::AllocateGlyph(&this->Queue, gp, v10, MaxSlotHeight);
    v13 = Glyph;
    if ( Glyph )
    {
      Notifier = Scaleform::Render::GlyphQueue::CreateNotifier(&this->Queue, Glyph, tm);
      Scaleform::Render::TextMeshProvider::AddNotifier(tm, Notifier);
      v13->Origin.x = 16 * v8;
      v13->Scale = 1.0;
      v13->Origin.y = 16 * v9;
      v15 = v19 * MaxSlotHeight;
      Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        (Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)&this->RasterData,
        v15);
      v16 = this->RasterData.Data.Data;
      this->RasterPitch = v19;
      memset(v16, 0, (unsigned int)v15);
      for ( i = 0; i < pRaster->Height; ++i )
      {
        if ( i + SlotPadding >= MaxSlotHeight )
          break;
        memmove(
          &this->RasterData.Data.Data[SlotPadding + this->RasterPitch * (i + SlotPadding)],
          &pRaster->Raster.Data.Data[i * pRaster->Width],
          pRaster->Width);
      }
      Scaleform::Render::GlyphCache::updateTextureGlyph(this, v13);
      ++this->RasterizationCount;
      return v13;
    }
    else
    {
      v18 = !this->RasterCacheWarning;
      this->Result = Res_CacheFull;
      if ( !v18 )
      {
        Scaleform::Render::GlyphCache::LogWarning(
          this,
          "Warning: Increase raster glyph cache capacity - see GlyphCacheParams");
        this->RasterCacheWarning = 0;
      }
      return 0i64;
    }
  }
  else
  {
    this->Result = Res_ShapeIsTooBig;
    return 0i64;
  }
}

// File Line: 1707
// RVA: 0x9E2CC0
void __fastcall Scaleform::Render::GlyphCache::filterScanline(
        Scaleform::Render::GlyphCache *this,
        char *sl,
        unsigned int w)
{
  unsigned int v3; // ebx
  unsigned int v6; // r11d
  char *v7; // rax
  __int64 v8; // rcx
  char v9; // r10
  char v10; // dl
  char Dst; // [rsp+20h] [rbp-108h] BYREF
  char v12[255]; // [rsp+21h] [rbp-107h] BYREF

  v3 = w;
  if ( w > 0x100 )
    v3 = 256;
  memset(&Dst, 0, v3);
  if ( v3 > 4 )
  {
    v6 = 4;
    v7 = v12;
    do
    {
      v8 = (unsigned __int8)v7[sl - v12 + 2];
      ++v6;
      ++v7;
      v9 = this->ScanlineFilter.Tertiary[v8];
      v10 = this->ScanlineFilter.Secondary[v8];
      *v7 += this->ScanlineFilter.Primary[v8];
      *(v7 - 2) += v9;
      *(v7 - 1) += v10;
      v7[1] += v10;
      v7[2] += v9;
    }
    while ( v6 < v3 );
  }
  memmove(sl, &Dst, v3);
}

// File Line: 1724
// RVA: 0x9A3AB0
Scaleform::Render::GlyphNode *__fastcall Scaleform::Render::GlyphCache::RasterizeGlyph(
        Scaleform::Render::GlyphCache *this,
        Scaleform::Render::GlyphRunData *data,
        Scaleform::Render::TextMeshProvider *tm,
        Scaleform::Render::GlyphParam *gp)
{
  int upperCaseTop; // ebp
  int v9; // r12d
  bool v10; // r14
  float stretch; // xmm7_4
  Scaleform::Render::Font *pFont; // rbp
  __int16 LowerCaseTop; // ax
  Scaleform::Render::Font *v14; // rbp
  __int16 v15; // ax
  signed int HintedNomHeight; // eax
  float NomHeight; // xmm0_4
  __m128 v18; // xmm6
  __m128 v19; // xmm2
  int v20; // ecx
  __m128 v21; // xmm1
  int v22; // ecx
  Scaleform::Render::ShapeDataInterface *pShape; // rdx
  __int64 SlotPadding; // r14
  int v25; // ebx
  int v26; // ebp
  int v27; // r13d
  int v28; // r12d
  unsigned int MaxSlotHeight; // r12d
  unsigned int v30; // ebp
  Scaleform::Render::GlyphNode *Glyph; // rax
  Scaleform::Render::GlyphNode *v32; // rsi
  char *v33; // rcx
  bool v34; // r13
  unsigned int v35; // ebx
  char *v36; // rsi
  Scaleform::Render::TessBaseVtbl *vfptr; // rax
  Scaleform::Render::GlyphNode *v38; // [rsp+B0h] [rbp+8h]

  if ( this->MaxNumTextures )
  {
    if ( data->RasterSize )
    {
      return Scaleform::Render::GlyphCache::getPrerasterizedGlyph(this, data, tm, gp);
    }
    else if ( data->pShape )
    {
      upperCaseTop = 0;
      v9 = 0;
      v10 = this->Param.UseAutoFit && (gp->Flags & 2) != 0;
      if ( (gp->Flags & 4) != 0 )
        stretch = FLOAT_2_5;
      else
        stretch = *(float *)&FLOAT_1_0;
      if ( v10 )
      {
        pFont = gp->pFont->pFont;
        if ( !pFont->LowerCaseTop )
          Scaleform::Render::Font::calcLowerUpperTop(gp->pFont->pFont, this);
        LowerCaseTop = pFont->LowerCaseTop;
        if ( LowerCaseTop <= 0 )
          LowerCaseTop = 0;
        v9 = (unsigned __int16)LowerCaseTop;
        v14 = gp->pFont->pFont;
        if ( !v14->UpperCaseTop )
          Scaleform::Render::Font::calcLowerUpperTop(gp->pFont->pFont, this);
        v15 = v14->UpperCaseTop;
        if ( v15 <= 0 )
          v15 = 0;
        upperCaseTop = (unsigned __int16)v15;
        if ( !v9 || !v15 )
          v10 = 0;
      }
      HintedNomHeight = data->HintedNomHeight;
      NomHeight = data->NomHeight;
      if ( HintedNomHeight )
      {
        v10 = 0;
        NomHeight = (float)HintedNomHeight;
      }
      v18 = (__m128)COERCE_UNSIGNED_INT((float)gp->FontSize);
      v18.m128_f32[0] = (float)(v18.m128_f32[0] * 0.0625) / NomHeight;
      v19 = v18;
      v19.m128_f32[0] = v18.m128_f32[0] * data->GlyphBounds.y1;
      v20 = (int)v19.m128_f32[0];
      if ( (int)v19.m128_f32[0] != 0x80000000 && (float)v20 != v19.m128_f32[0] )
        v19.m128_f32[0] = (float)(v20 - (_mm_movemask_ps(_mm_unpacklo_ps(v19, v19)) & 1));
      v21 = v18;
      v21.m128_f32[0] = v18.m128_f32[0] * data->GlyphBounds.y2;
      v22 = (int)v21.m128_f32[0];
      if ( (int)v21.m128_f32[0] != 0x80000000 && (float)v22 != v21.m128_f32[0] )
        v21.m128_f32[0] = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(v21, v21)) & 1) + v22);
      if ( v19.m128_f32[0] >= v21.m128_f32[0] )
      {
        v19.m128_i32[0] = 0;
        v21.m128_i32[0] = 0;
      }
      if ( (int)(float)(v21.m128_f32[0] - v19.m128_f32[0]) + 2 * this->SlotPadding < this->MaxSlotHeight )
      {
        (*((void (__fastcall **)(Scaleform::Render::Rasterizer *))&this->Ras.vfptr->__vecDelDtor + 1))(&this->Ras);
        pShape = data->pShape;
        if ( v10 )
          Scaleform::Render::GlyphCache::addShapeAutoFit(
            this,
            pShape,
            (int)data->NomHeight,
            v9,
            upperCaseTop,
            (float)gp->FontSize * 0.0625,
            stretch);
        else
          Scaleform::Render::GlyphCache::addShapeToRasterizer(this, pShape, v18.m128_f32[0] * stretch, v18.m128_f32[0]);
        SlotPadding = (int)this->SlotPadding;
        v25 = 0;
        v26 = 0;
        v27 = 0;
        v28 = 0;
        if ( Scaleform::Render::Rasterizer::SortCells(&this->Ras) )
        {
          v25 = this->Ras.MinX - SlotPadding;
          v26 = SlotPadding + this->Ras.MaxX;
          v27 = this->Ras.MinY - SlotPadding;
          v28 = SlotPadding + this->Ras.MaxY;
        }
        MaxSlotHeight = v28 - v27 + 1;
        v30 = v26 - v25 + 1;
        if ( MaxSlotHeight > this->MaxSlotHeight )
          MaxSlotHeight = this->MaxSlotHeight;
        Glyph = Scaleform::Render::GlyphCache::allocateGlyph(this, tm, gp, v30, MaxSlotHeight);
        v32 = Glyph;
        v38 = Glyph;
        if ( Glyph )
        {
          Glyph->Scale = 1.0;
          Glyph->Origin.x = 16 * v25;
          Glyph->Origin.y = 16 * v27;
          Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Resize(
            (Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)&this->RasterData,
            v30 * MaxSlotHeight);
          v33 = this->RasterData.Data.Data;
          this->RasterPitch = v30;
          memset(v33, 0, v30 * MaxSlotHeight);
          if ( 1.0 != this->Ras.Gamma1 )
          {
            Scaleform::Render::Rasterizer::setGamma(&this->Ras, 0, 1.0);
            this->Ras.Gamma1 = 1.0;
          }
          v34 = v30 >= 5 && stretch > 1.0;
          v35 = 0;
          if ( this->Ras.SortedYs.Size )
          {
            do
            {
              if ( v35 + (unsigned int)SlotPadding >= MaxSlotHeight )
                break;
              v36 = &this->RasterData.Data.Data[this->RasterPitch * (v35 + (unsigned int)SlotPadding)];
              Scaleform::Render::Rasterizer::SweepScanline(&this->Ras, v35, &v36[SlotPadding], 1u, 0);
              if ( v34 )
                Scaleform::Render::GlyphCache::filterScanline(this, v36, v30);
              ++v35;
            }
            while ( v35 < this->Ras.SortedYs.Size );
            v32 = v38;
          }
          Scaleform::Render::GlyphCache::updateTextureGlyph(this, v32);
          vfptr = this->Ras.vfptr;
          ++this->RasterizationCount;
          (*((void (__fastcall **)(Scaleform::Render::Rasterizer *))&vfptr->__vecDelDtor + 1))(&this->Ras);
          return v32;
        }
        else
        {
          this->Result = Res_CacheFull;
          Scaleform::Render::GlyphCache::cacheFullWarning(this);
          return 0i64;
        }
      }
      else
      {
        this->Result = Res_ShapeIsTooBig;
        return 0i64;
      }
    }
    else
    {
      this->Result = Res_ShapeNotFound;
      return 0i64;
    }
  }
  else
  {
    this->Result = Res_NoRasterCache;
    return 0i64;
  }
}

// File Line: 1865
// RVA: 0x9DE590
Scaleform::Render::GlyphNode *__fastcall Scaleform::Render::GlyphCache::createShadowFromRaster(
        Scaleform::Render::GlyphCache *this,
        Scaleform::Render::GlyphRunData *data,
        Scaleform::Render::TextMeshProvider *tm,
        Scaleform::Render::GlyphParam *gp,
        float screenSize,
        Scaleform::Render::GlyphRaster *ras)
{
  float HeightRatio; // xmm0_4
  unsigned int MaxSlotHeight; // r8d
  unsigned int SlotPadding; // edx
  Scaleform::Render::GlyphCache *v10; // rdi
  float v12; // xmm2_4
  __m128i v13; // xmm1
  __m128i v14; // xmm7
  int BlurY; // eax
  signed int Height; // r9d
  __m128 ry; // xmm6
  __m128 rx; // xmm7
  float v19; // xmm1_4
  float v20; // xmm3_4
  float v21; // xmm1_4
  int v22; // ecx
  int v23; // r14d
  float v24; // xmm1_4
  int v25; // ecx
  unsigned int v26; // r14d
  unsigned int v27; // ebx
  signed int w; // r12d
  int h; // ebp
  __m128 v30; // xmm9
  __m128 v31; // xmm1
  int v32; // ecx
  signed int v33; // r15d
  __m128 v34; // xmm8
  __m128 v35; // xmm1
  int v36; // ecx
  signed int v37; // esi
  Scaleform::Render::GlyphNode *Glyph; // rax
  Scaleform::Render::TextNotifier *Notifier; // rax
  unsigned int v40; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *p_RasterDataSrc; // r14
  size_t v42; // rax
  Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *p_RasterData; // r15
  char *v44; // rcx
  unsigned __int64 v45; // rbx
  unsigned int v46; // esi
  unsigned int v47; // ebp
  Scaleform::Render::GlyphParam *v48; // rsi
  int v49; // r13d
  unsigned __int64 i; // rdx
  float v51; // xmm0_4
  char *v52; // r8
  char *v53; // rdx
  unsigned __int64 j; // r9
  __int16 v55; // cx
  __int16 v56; // ax
  bool v58; // zf
  signed int v59; // [rsp+60h] [rbp-C8h]
  int dstWidth; // [rsp+68h] [rbp-C0h]
  Scaleform::Render::GlyphNode *node; // [rsp+70h] [rbp-B8h]
  size_t Size; // [rsp+78h] [rbp-B0h]
  unsigned int v64; // [rsp+138h] [rbp+10h]
  unsigned int screenSizea; // [rsp+150h] [rbp+28h]
  unsigned int rasa; // [rsp+158h] [rbp+30h]

  HeightRatio = data->HeightRatio;
  MaxSlotHeight = this->MaxSlotHeight;
  SlotPadding = this->SlotPadding;
  v10 = this;
  v12 = *(float *)&FLOAT_1_0;
  v13 = _mm_cvtsi32_si128(gp->FontSize);
  v14 = _mm_cvtsi32_si128(gp->BlurX);
  BlurY = gp->BlurY;
  Height = ras->Height;
  *(float *)v13.m128i_i32 = (float)(_mm_cvtepi32_ps(v13).m128_f32[0] * 0.0625) / screenSize;
  rx = _mm_cvtepi32_ps(v14);
  ry = (__m128)COERCE_UNSIGNED_INT((float)BlurY);
  ry.m128_f32[0] = (float)((float)(ry.m128_f32[0] * 0.0625) * *(float *)v13.m128i_i32) * HeightRatio;
  rx.m128_f32[0] = (float)((float)(rx.m128_f32[0] * 0.0625) * *(float *)v13.m128i_i32) * HeightRatio;
  v19 = (float)((float)(int)MaxSlotHeight * this->ShadowQuality) - (float)(int)(2 * SlotPadding);
  v20 = (float)(ry.m128_f32[0] * 2.0) + (float)Height;
  if ( v20 >= v19 )
  {
    v12 = v19 / v20;
    rx.m128_f32[0] = rx.m128_f32[0] * (float)(v19 / v20);
    ry.m128_f32[0] = ry.m128_f32[0] * (float)(v19 / v20);
  }
  v21 = rx.m128_f32[0];
  v22 = (int)rx.m128_f32[0];
  if ( (int)rx.m128_f32[0] != 0x80000000 && (float)v22 != rx.m128_f32[0] )
    v21 = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(rx, rx)) & 1) + v22);
  v23 = (int)v21;
  v24 = ry.m128_f32[0];
  v25 = (int)ry.m128_f32[0];
  v26 = SlotPadding + v23;
  v64 = v26;
  if ( (int)ry.m128_f32[0] != 0x80000000 && (float)v25 != ry.m128_f32[0] )
    v24 = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(ry, ry)) & 1) + v25);
  v30 = 0i64;
  v27 = SlotPadding + (int)v24;
  w = ras->Width + 1 + 2 * v26;
  h = Height + 1 + 2 * v27;
  rasa = v27;
  screenSizea = h;
  v30.m128_f32[0] = (float)w;
  v31 = v30;
  v31.m128_f32[0] = (float)w * v12;
  v32 = (int)v31.m128_f32[0];
  if ( (int)v31.m128_f32[0] != 0x80000000 && (float)v32 != v31.m128_f32[0] )
    v31.m128_f32[0] = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(v31, v31)) & 1) + v32);
  v33 = (int)v31.m128_f32[0];
  v34 = 0i64;
  v34.m128_f32[0] = (float)h;
  dstWidth = (int)v31.m128_f32[0];
  v35 = v34;
  v35.m128_f32[0] = (float)h * v12;
  v36 = (int)v35.m128_f32[0];
  if ( (int)v35.m128_f32[0] != 0x80000000 && (float)v36 != v35.m128_f32[0] )
    v35.m128_f32[0] = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(v35, v35)) & 1) + v36);
  v37 = (int)v35.m128_f32[0];
  if ( (int)v35.m128_f32[0] > MaxSlotHeight )
    v37 = MaxSlotHeight;
  v59 = v37;
  Glyph = Scaleform::Render::GlyphQueue::AllocateGlyph(&v10->Queue, gp, v33, v37);
  node = Glyph;
  if ( Glyph )
  {
    Notifier = Scaleform::Render::GlyphQueue::CreateNotifier(&v10->Queue, Glyph, tm);
    Scaleform::Render::TextMeshProvider::AddNotifier(tm, Notifier);
    v40 = v26 + ras->OriginX;
    p_RasterDataSrc = &v10->RasterDataSrc;
    node->Origin.x = (int)(float)((float)((float)(int)(-16 * v40) * (float)v33) / v30.m128_f32[0]);
    node->Origin.y = (int)(float)((float)((float)(int)(-16 * (v27 + ras->OriginY)) * (float)v37) / v34.m128_f32[0]);
    node->Scale = (float)((float)(v34.m128_f32[0] / (float)v37) + (float)(v30.m128_f32[0] / (float)v33)) * 0.5;
    Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      (Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)&v10->RasterDataSrc,
      (unsigned int)(w * h));
    v42 = (unsigned int)(v33 * v37);
    p_RasterData = (Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)&v10->RasterData;
    Size = v42;
    Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      (Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)&v10->RasterData,
      (unsigned int)v42);
    v44 = v10->RasterDataSrc.Data.Data;
    v10->RasterPitch = dstWidth;
    memset(v44, 0, (unsigned int)(w * h));
    v45 = 0i64;
    if ( (unsigned int)w > 1 && (unsigned int)h > 1 )
    {
      v46 = 0;
      if ( ras->Height )
      {
        v47 = v64 + rasa * w;
        do
        {
          if ( v46 + rasa >= screenSizea )
            break;
          memmove(&p_RasterDataSrc->Data.Data[v47], &ras->Raster.Data.Data[v46 * ras->Width], ras->Width);
          ++v46;
          v47 += w;
        }
        while ( v46 < ras->Height );
        v10 = this;
        h = screenSizea;
        p_RasterData = (Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)&this->RasterData;
      }
      v48 = gp;
      v49 = 0;
      if ( (gp->Flags & 0x20) != 0 )
      {
        Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Resize(
          (Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)&v10->KnockOutCopy,
          p_RasterDataSrc->Data.Size);
        for ( i = 0i64;
              i < v10->KnockOutCopy.Data.Size;
              v10->KnockOutCopy.Data.Data[i - 1] = p_RasterDataSrc->Data.Data[i - 1] )
        {
          ++i;
        }
        v48 = gp;
      }
      if ( rx.m128_f32[0] > 0.0 || ry.m128_f32[0] > 0.0 )
      {
        Scaleform::Render::GlyphCache::recursiveBlur(
          v10,
          p_RasterDataSrc->Data.Data,
          w,
          0,
          0,
          w,
          h,
          rx.m128_f32[0],
          ry.m128_f32[0]);
        v49 = 8;
      }
      v51 = (float)v48->BlurStrength * 0.0625;
      if ( v51 <= 1.0 )
        v49 = 0;
      Scaleform::Render::GlyphCache::strengthenImage(v10, p_RasterDataSrc->Data.Data, w, 0, 0, w, h, v51, v49);
      if ( (v48->Flags & 0x20) != 0 )
      {
        v52 = v10->KnockOutCopy.Data.Data;
        v53 = p_RasterDataSrc->Data.Data;
        for ( j = 0i64; j < v10->KnockOutCopy.Data.Size; *(v53 - 1) = (unsigned __int16)(v55 * v56 + 255) >> 8 )
        {
          ++j;
          v55 = 255 - (unsigned __int8)*v52;
          v56 = (unsigned __int8)*v53;
          ++v52;
          ++v53;
        }
      }
      v37 = v59;
    }
    if ( h == v37 && w == dstWidth )
    {
      Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        p_RasterData,
        p_RasterDataSrc->Data.Size);
      if ( p_RasterData->Size )
      {
        do
        {
          ++v45;
          p_RasterData->Data[v45 - 1] = p_RasterDataSrc->Data.Data[v45 - 1];
        }
        while ( v45 < p_RasterData->Size );
      }
    }
    else
    {
      memset(p_RasterData->Data, 0, Size);
      if ( dstWidth > 0 && v37 > 0 && w > 0 && h > 0 )
        Scaleform::Render::ImageResizeFilter2x2_void____cdecl___unsigned_char_____ptr64_unsigned_char_const_____ptr64_unsigned_char_const_____ptr64_unsigned_char_const_____ptr64_unsigned_char_const_____ptr64_int_int__(
          (char *)p_RasterData->Data,
          dstWidth,
          v37,
          dstWidth,
          1,
          p_RasterDataSrc->Data.Data,
          w,
          h,
          w,
          1,
          Scaleform::Render::PixelFilterBilinearGray8);
    }
    Scaleform::Render::GlyphCache::updateTextureGlyph(v10, node);
    ++v10->RasterizationCount;
    return node;
  }
  else
  {
    v58 = !v10->RasterCacheWarning;
    v10->Result = Res_CacheFull;
    if ( !v58 )
    {
      Scaleform::Render::GlyphCache::LogWarning(
        v10,
        "Warning: Increase raster glyph cache capacity - see GlyphCacheParams");
      v10->RasterCacheWarning = 0;
    }
    return 0i64;
  }
}

// File Line: 1964
// RVA: 0x9A3F10
Scaleform::Render::GlyphNode *__fastcall Scaleform::Render::GlyphCache::RasterizeShadow(
        Scaleform::Render::GlyphCache *this,
        Scaleform::Render::GlyphRunData *data,
        Scaleform::Render::TextMeshProvider *tm,
        Scaleform::Render::GlyphParam *gp,
        float screenSize,
        Scaleform::Render::GlyphRaster *ras)
{
  Scaleform::Render::GlyphNode *result; // rax
  float HeightRatio; // xmm0_4
  float v10; // xmm6_4
  float v11; // xmm9_4
  __m128 rx; // xmm8
  __m128 ry; // xmm7
  signed int HintedNomHeight; // eax
  float v15; // xmm1_4
  float NomHeight; // xmm0_4
  float y1; // xmm2_4
  float v18; // xmm6_4
  float y2; // xmm0_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  unsigned int SlotPadding; // edx
  float v23; // xmm1_4
  int v24; // ecx
  int v25; // r13d
  float v26; // xmm1_4
  int v27; // ecx
  signed int v28; // r13d
  unsigned __int64 v29; // rsi
  int v30; // ebx
  unsigned int v31; // r14d
  unsigned int v32; // ebp
  unsigned int v33; // r12d
  int v34; // ecx
  unsigned int h; // ebp
  Scaleform::Render::GlyphNode *Glyph; // rax
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *p_RasterData; // r14
  char *v38; // rcx
  float v39; // xmm1_4
  unsigned int i; // ebx
  int v41; // r12d
  float v42; // xmm0_4
  char *v43; // r8
  char *v44; // rdx
  __int16 v45; // cx
  __int16 v46; // ax
  Scaleform::Render::TessBaseVtbl *vfptr; // rax
  Scaleform::Render::GlyphNode *node; // [rsp+50h] [rbp-B8h]
  unsigned int w; // [rsp+110h] [rbp+8h]
  Scaleform::Render::GlyphParam *gpa; // [rsp+128h] [rbp+20h]

  gpa = gp;
  if ( !this->MaxNumTextures )
  {
    this->Result = Res_NoRasterCache;
    return 0i64;
  }
  if ( ras )
  {
    result = Scaleform::Render::GlyphCache::createShadowFromRaster(this, data, tm, gp, screenSize, ras);
    if ( result )
      return result;
    gp = gpa;
  }
  if ( data->pShape )
  {
    HeightRatio = data->HeightRatio;
    rx = (__m128)COERCE_UNSIGNED_INT((float)gp->BlurX);
    v10 = (float)gp->FontSize * 0.0625;
    v11 = *(float *)&FLOAT_1_0;
    ry = (__m128)COERCE_UNSIGNED_INT((float)gp->BlurY);
    rx.m128_f32[0] = (float)((float)(rx.m128_f32[0] * 0.0625) * (float)(v10 / screenSize)) * HeightRatio;
    ry.m128_f32[0] = (float)((float)(ry.m128_f32[0] * 0.0625) * (float)(v10 / screenSize)) * HeightRatio;
    HintedNomHeight = data->HintedNomHeight;
    v15 = (float)((float)(int)this->MaxSlotHeight * this->ShadowQuality) - (float)(2 * this->SlotPadding);
    if ( HintedNomHeight )
      NomHeight = (float)HintedNomHeight;
    else
      NomHeight = data->NomHeight;
    y1 = data->GlyphBounds.y1;
    v18 = v10 / NomHeight;
    y2 = data->GlyphBounds.y2;
    if ( y1 >= y2 )
    {
      y2 = 0.0;
      y1 = 0.0;
    }
    v20 = (float)((float)(y2 * v18) + ry.m128_f32[0]) - (float)((float)(y1 * v18) - ry.m128_f32[0]);
    if ( v20 >= v15 )
    {
      v21 = v15 / v20;
      v18 = v18 * v21;
      rx.m128_f32[0] = rx.m128_f32[0] * v21;
      ry.m128_f32[0] = ry.m128_f32[0] * v21;
      v11 = 1.0 / v21;
    }
    (*((void (__fastcall **)(Scaleform::Render::Rasterizer *))&this->Ras.vfptr->__vecDelDtor + 1))(&this->Ras);
    Scaleform::Render::GlyphCache::addShapeToRasterizer(this, data->pShape, v18, v18);
    SlotPadding = this->SlotPadding;
    v23 = rx.m128_f32[0];
    v24 = (int)rx.m128_f32[0];
    if ( (int)rx.m128_f32[0] != 0x80000000 && (float)v24 != rx.m128_f32[0] )
      v23 = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(rx, rx)) & 1) + v24);
    v25 = (int)v23;
    v26 = ry.m128_f32[0];
    v27 = (int)ry.m128_f32[0];
    v28 = SlotPadding + v25;
    if ( (int)ry.m128_f32[0] != 0x80000000 && (float)v27 != ry.m128_f32[0] )
      v26 = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(ry, ry)) & 1) + v27);
    v29 = 0i64;
    v30 = 0;
    v31 = 0;
    v32 = 0;
    v33 = SlotPadding + (int)v26;
    if ( Scaleform::Render::Rasterizer::SortCells(&this->Ras) )
    {
      v30 = this->Ras.MinX - v28;
      v34 = v28 + this->Ras.MaxX;
      v31 = this->Ras.MinY - v33;
      v32 = v33 + this->Ras.MaxY;
    }
    else
    {
      v34 = 0;
    }
    h = v32 - v31 + 1;
    w = v34 - v30 + 1;
    if ( h > this->MaxSlotHeight )
      h = this->MaxSlotHeight;
    Glyph = Scaleform::Render::GlyphCache::allocateGlyph(this, tm, gpa, v34 - v30 + 1, h);
    node = Glyph;
    if ( Glyph )
    {
      Glyph->Scale = v11;
      Glyph->Origin.x = 16 * v30;
      Glyph->Origin.y = 16 * v31;
      p_RasterData = &this->RasterData;
      Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        (Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)&this->RasterData,
        w * h);
      v38 = this->RasterData.Data.Data;
      this->RasterPitch = w;
      memset(v38, 0, w * h);
      if ( w > 1 && h > 1 )
      {
        v39 = *(float *)&FLOAT_1_0;
        if ( gpa->BlurX || gpa->BlurY )
          v39 = FLOAT_0_40000001;
        if ( v39 != this->Ras.Gamma2 )
          Scaleform::Render::Rasterizer::SetGamma2(&this->Ras, v39);
        for ( i = 0; i < this->Ras.SortedYs.Size; ++i )
        {
          if ( i + v33 >= h )
            break;
          Scaleform::Render::Rasterizer::SweepScanline(
            &this->Ras,
            i,
            &p_RasterData->Data.Data[v28 + (unsigned __int64)(this->RasterPitch * (i + v33))],
            1u,
            1);
        }
        v41 = 0;
        if ( (gpa->Flags & 0x20) != 0 )
          Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>::operator=(
            &this->KnockOutCopy,
            &this->RasterData);
        if ( rx.m128_f32[0] > 0.0 || ry.m128_f32[0] > 0.0 )
        {
          Scaleform::Render::GlyphCache::recursiveBlur(
            this,
            p_RasterData->Data.Data,
            this->RasterPitch,
            0,
            0,
            w,
            h,
            rx.m128_f32[0],
            ry.m128_f32[0]);
          v41 = 8;
        }
        v42 = (float)gpa->BlurStrength * 0.0625;
        if ( v42 <= 1.0 )
          v41 = 0;
        Scaleform::Render::GlyphCache::strengthenImage(
          this,
          p_RasterData->Data.Data,
          this->RasterPitch,
          0,
          0,
          w,
          h,
          v42,
          v41);
        if ( (gpa->Flags & 0x20) != 0 )
        {
          v43 = this->KnockOutCopy.Data.Data;
          v44 = p_RasterData->Data.Data;
          if ( this->KnockOutCopy.Data.Size )
          {
            do
            {
              ++v29;
              v45 = 255 - (unsigned __int8)*v43;
              v46 = (unsigned __int8)*v44;
              ++v43;
              *v44++ = (unsigned __int16)(v45 * v46 + 255) >> 8;
            }
            while ( v29 < this->KnockOutCopy.Data.Size );
          }
        }
      }
      Scaleform::Render::GlyphCache::updateTextureGlyph(this, node);
      vfptr = this->Ras.vfptr;
      ++this->RasterizationCount;
      (*((void (__fastcall **)(Scaleform::Render::Rasterizer *))&vfptr->__vecDelDtor + 1))(&this->Ras);
      return node;
    }
    else
    {
      this->Result = Res_CacheFull;
      if ( this->RasterCacheWarning )
      {
        Scaleform::Render::GlyphCache::LogWarning(
          this,
          "Warning: Increase raster glyph cache capacity - see GlyphCacheParams");
        this->RasterCacheWarning = 0;
      }
      return 0i64;
    }
  }
  else
  {
    this->Result = Res_ShapeNotFound;
    return 0i64;
  }
}

// File Line: 2105
// RVA: 0x998CB0
void Scaleform::Render::GlyphCache::LogWarning(Scaleform::Render::GlyphCache *this, const char *fmt, ...)
{
  Scaleform::Log *pLog; // rcx
  int v3[6]; // [rsp+20h] [rbp-18h] BYREF
  va_list va; // [rsp+50h] [rbp+18h] BYREF

  va_start(va, fmt);
  pLog = this->pLog;
  if ( pLog )
  {
    v3[0] = 143360;
    ((void (__fastcall *)(Scaleform::Log *, int *, const char *, __int64 *))pLog->vfptr[1].__vecDelDtor)(
      pLog,
      v3,
      fmt,
      (__int64 *)va);
  }
}

// File Line: 2125
// RVA: 0x9D00A0
void __fastcall Scaleform::Render::GlyphCache::cacheFullWarning(Scaleform::Render::GlyphCache *this)
{
  if ( this->RasterCacheWarning )
  {
    Scaleform::Render::GlyphCache::LogWarning(
      this,
      "Warning: Increase raster glyph cache capacity - see GlyphCacheParams");
    this->RasterCacheWarning = 0;
  }
}

