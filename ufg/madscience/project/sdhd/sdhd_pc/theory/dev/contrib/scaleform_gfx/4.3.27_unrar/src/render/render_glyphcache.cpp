// File Line: 44
// RVA: 0x159C490
__int64 dynamic_initializer_for__Scaleform::Render::RasterGlyphVertex::Format__()
{
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::RasterGlyphVertex::Format__);
}

// File Line: 51
// RVA: 0x93CD80
void __fastcall Scaleform::Render::GlyphTextureImage::GlyphTextureImage(Scaleform::Render::GlyphTextureImage *this, Scaleform::Render::GlyphCache *cache, unsigned int textureId, Scaleform::Render::Size<unsigned long> *size, unsigned int use)
{
  Scaleform::Render::GlyphTextureImage *v5; // r10
  Scaleform::Render::Texture *volatile v6; // rt1
  Scaleform::Render::Texture *volatile v7; // rax
  unsigned int v8; // ecx

  v5 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountVImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseV<Scaleform::Render::Image,3>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ImageBase::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Image::`vftable';
  this->pTexture.Value = 0i64;
  v6 = this->pTexture.Value;
  v7 = this->pTexture.Value;
  this->pUpdateSync = 0i64;
  this->pInverseMatrix = 0i64;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::TextureImage::`vftable';
  this->Format = 9;
  v8 = size->Height;
  v5->Size.Width = size->Width;
  v5->Size.Height = v8;
  v5->Use = use;
  v5->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::GlyphTextureImage::`vftable';
  v5->pCache = cache;
  v5->TextureId = textureId;
}

// File Line: 58
// RVA: 0x9653C0
Scaleform::Render::GlyphTextureImage *__fastcall Scaleform::Render::GlyphTextureImage::Create(Scaleform::MemoryHeap *heap, Scaleform::Render::TextureManager *texMan, Scaleform::Render::GlyphCache *cache, unsigned int textureId, Scaleform::Render::Size<unsigned long> *size, unsigned int use)
{
  unsigned int v6; // ebx
  Scaleform::Render::GlyphCache *v7; // rbp
  Scaleform::Render::TextureManager *v8; // r14
  Scaleform::Render::GlyphTextureImage *v9; // rax
  Scaleform::Render::GlyphTextureImage *v10; // rax
  Scaleform::Render::GlyphTextureImage *v11; // rbx
  __int64 v12; // rax
  Scaleform::Render::GlyphTextureImage *result; // rax
  __int64 v14; // [rsp+20h] [rbp-48h]

  v6 = textureId;
  v7 = cache;
  v8 = texMan;
  v9 = (Scaleform::Render::GlyphTextureImage *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))heap->vfptr->Alloc)(
                                                 heap,
                                                 72i64);
  if ( v9 )
  {
    Scaleform::Render::GlyphTextureImage::GlyphTextureImage(v9, v7, v6, size, use);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  LODWORD(v14) = use;
  v12 = ((__int64 (__fastcall *)(Scaleform::Render::TextureManager *, signed __int64, signed __int64, Scaleform::Render::Size<unsigned long> *, __int64, Scaleform::Render::GlyphTextureImage *, _QWORD))v8->vfptr[1].__vecDelDtor)(
          v8,
          9i64,
          1i64,
          size,
          v14,
          v11,
          0i64);
  if ( v12 )
  {
    v11->pTexture.Value = (Scaleform::Render::Texture *volatile )v12;
    result = v11;
  }
  else
  {
    ((void (__fastcall *)(Scaleform::Render::GlyphTextureImage *))v11->vfptr[2].__vecDelDtor)(v11);
    result = 0i64;
  }
  return result;
}

// File Line: 73
// RVA: 0x9B9D30
void __fastcall Scaleform::Render::GlyphTextureImage::TextureLost(Scaleform::Render::GlyphTextureImage *this, Scaleform::Render::Image::TextureLossReason reason)
{
  unsigned int v3; // esi
  Scaleform::Render::GlyphTextureImage *v4; // rdi

  _RBX = 0i64;
  v3 = reason;
  v4 = this;
  __asm { xchg    rbx, [rcx+10h]; Exchange Register/Memory with Register }
  if ( _RBX )
  {
    (*(void (__fastcall **)(volatile signed __int32 *))(*(_QWORD *)_RBX + 64i64))(_RBX);
    if ( !_InterlockedDecrement(_RBX + 2) )
      (**(void (__fastcall ***)(volatile signed __int32 *, signed __int64))_RBX)(_RBX, 1i64);
  }
  Scaleform::Render::GlyphCache::TextureLost(v4->pCache, v4->TextureId, v3);
}

// File Line: 83
// RVA: 0x965480
_BOOL8 __fastcall Scaleform::Render::GlyphTextureMapper::Create(Scaleform::Render::GlyphTextureMapper *this, unsigned int method, Scaleform::MemoryHeap *heap, Scaleform::Render::TextureManager *texMan, Scaleform::Render::PrimitiveFillManager *fillMan)
{
  Scaleform::Render::TextureManager *v5; // r15
  Scaleform::MemoryHeap *v6; // rsi
  unsigned int v7; // ebx
  Scaleform::Render::GlyphTextureMapper *v8; // rdi
  Scaleform::Render::GlyphTextureImage *v9; // rcx
  Scaleform::Render::RawImage *v10; // rbx
  Scaleform::Render::RawImage *v11; // rcx
  bool v12; // si
  __int64 v13; // r15
  void (__fastcall ***v14)(_QWORD, signed __int64); // rcx
  void (__fastcall ***v15)(_QWORD, signed __int64); // rcx
  Scaleform::Render::PrimitiveFill *v16; // rbx
  Scaleform::Render::PrimitiveFill *v17; // rcx
  bool v18; // zf
  __int64 *v19; // rcx
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
  Scaleform::MemoryHeap *pheap; // [rsp+20h] [rbp-31h]
  Scaleform::Render::ImageUpdateSync *pupdateSync; // [rsp+28h] [rbp-29h]
  __int64 ptr; // [rsp+30h] [rbp-21h]
  __int64 v33; // [rsp+38h] [rbp-19h]
  Scaleform::Render::VertexFormat *v34; // [rsp+40h] [rbp-11h]
  Scaleform::Render::PrimitiveFillData initdata; // [rsp+48h] [rbp-9h]
  Scaleform::Render::PrimitiveFillManager *v36; // [rsp+B8h] [rbp+67h]
  Scaleform::Render::GlyphCache *v37; // [rsp+C0h] [rbp+6Fh]
  unsigned int v38; // [rsp+C8h] [rbp+77h]

  v5 = texMan;
  v6 = heap;
  v7 = method;
  v8 = this;
  this->pTexMan = texMan;
  this->Method = method;
  if ( method == 2 )
  {
    v9 = this->pTexImg.pObject;
    if ( v9 )
      ((void (*)(void))v9->vfptr[2].__vecDelDtor)();
    v8->pTexImg.pObject = 0i64;
    v10 = Scaleform::Render::RawImage::Create(
            Image_A8,
            1u,
            (Scaleform::Render::Size<unsigned long> *)fillMan,
            0x10u,
            v6,
            0i64);
    v11 = v8->pRawImg.pObject;
    if ( v11 )
      ((void (*)(void))v11->vfptr[2].__vecDelDtor)();
    v8->pRawImg.pObject = v10;
    v12 = v10 != 0i64;
    if ( v10 )
    {
      v13 = (__int64)v10->vfptr[21].__vecDelDtor((Scaleform::RefCountImplCore *)&v10->vfptr, (unsigned int)v5);
      pheap = (Scaleform::MemoryHeap *)Scaleform::Ptr<Scaleform::Render::StereoImplBase>::~Ptr<Scaleform::Render::StereoImplBase>;
      `eh vector constructor iterator'(
        &ptr,
        8ui64,
        2,
        (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>);
      v34 = &Scaleform::Render::RasterGlyphVertex::Format;
      LOWORD(pupdateSync) = 3;
      if ( v13 )
        _InterlockedExchangeAdd((volatile signed __int32 *)(v13 + 8), 1u);
      v14 = (void (__fastcall ***)(_QWORD, signed __int64))ptr;
      if ( ptr && !_InterlockedDecrement((volatile signed __int32 *)(ptr + 8)) && v14 )
        (**v14)(v14, 1i64);
      ptr = v13;
      v15 = (void (__fastcall ***)(_QWORD, signed __int64))v33;
      if ( v33 && !_InterlockedDecrement((volatile signed __int32 *)(v33 + 8)) && v15 )
        (**v15)(v15, 1i64);
      v33 = 0i64;
      v16 = Scaleform::Render::PrimitiveFillManager::CreateFill(v36, (Scaleform::Render::PrimitiveFillData *)&pheap);
      v17 = v8->pFill.pObject;
      if ( v17 )
      {
        v18 = v17->RefCount-- == 1;
        if ( v18 )
          v17->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v17->vfptr, 1u);
      }
      v8->pFill.pObject = v16;
      v19 = &ptr;
LABEL_42:
      `eh vector destructor iterator'(
        v19,
        8ui64,
        2,
        (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::StereoImplBase>::~Ptr<Scaleform::Render::StereoImplBase>);
      goto LABEL_43;
    }
  }
  else
  {
    v20 = this->pRawImg.pObject;
    if ( v20 )
      ((void (*)(void))v20->vfptr[2].__vecDelDtor)();
    v8->pRawImg.pObject = 0i64;
    v21 = 192;
    if ( v7 == 1 )
      v21 = 32;
    v22 = Scaleform::Render::GlyphTextureImage::Create(
            v6,
            v5,
            v37,
            v38,
            (Scaleform::Render::Size<unsigned long> *)fillMan,
            v21);
    v23 = v8->pTexImg.pObject;
    if ( v23 )
      ((void (*)(void))v23->vfptr[2].__vecDelDtor)();
    v8->pTexImg.pObject = v22;
    v12 = v22 != 0i64;
    if ( v22 )
    {
      v24 = (Scaleform::Render::Texture *)v22->vfptr[21].__vecDelDtor(
                                            (Scaleform::RefCountImplCore *)&v22->vfptr,
                                            (unsigned int)v5);
      *(_QWORD *)&initdata.Type = 12i64;
      pheap = (Scaleform::MemoryHeap *)Scaleform::Ptr<Scaleform::Render::StereoImplBase>::~Ptr<Scaleform::Render::StereoImplBase>;
      `eh vector constructor iterator'(
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
        v25->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v25->vfptr, 1u);
      initdata.Textures[0].pObject = v24;
      v26 = initdata.Textures[1].pObject;
      if ( initdata.Textures[1].pObject && !_InterlockedDecrement(&initdata.Textures[1].pObject->RefCount) && v26 )
        v26->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v26->vfptr, 1u);
      initdata.Textures[1].pObject = 0i64;
      v27 = Scaleform::Render::PrimitiveFillManager::CreateFill(v36, &initdata);
      v28 = v8->pFill.pObject;
      if ( v28 )
      {
        v18 = v28->RefCount-- == 1;
        if ( v18 )
          v28->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v28->vfptr, 1u);
      }
      v8->pFill.pObject = v27;
      v19 = (__int64 *)initdata.Textures;
      goto LABEL_42;
    }
  }
LABEL_43:
  result = v12;
  v8->Valid = v12;
  return result;
}

// File Line: 126
// RVA: 0x999210
Scaleform::Render::ImagePlane *__fastcall Scaleform::Render::GlyphTextureMapper::Map(Scaleform::Render::GlyphTextureMapper *this)
{
  unsigned int v1; // eax
  Scaleform::Render::GlyphTextureMapper *v2; // rbx
  void *v3; // rcx
  signed __int64 v4; // r9

  v1 = this->Method;
  v2 = this;
  if ( v1 )
  {
    if ( v1 != 2 )
      return 0i64;
    if ( !this->Mapped )
    {
      v3 = this->pRawImg.pObject;
      v4 = 0i64;
      goto LABEL_8;
    }
  }
  else if ( !this->Mapped )
  {
    v3 = this->pTexImg.pObject;
    v4 = 1i64;
LABEL_8:
    if ( (*(unsigned __int8 (__fastcall **)(void *, Scaleform::Render::ImageData *, _QWORD, signed __int64))(*(_QWORD *)v3 + 136i64))(
           v3,
           &v2->Data,
           0i64,
           v4) )
    {
      v2->Mapped = 1;
      return v2->Data.pPlanes;
    }
    return 0i64;
  }
  return v2->Data.pPlanes;
}

// File Line: 248
// RVA: 0x93C330
void __fastcall Scaleform::Render::GlyphCache::GlyphCache(Scaleform::Render::GlyphCache *this, Scaleform::MemoryHeap *heap)
{
  Scaleform::MemoryHeap *v2; // rbp
  Scaleform::Render::GlyphCache *v3; // rdi
  signed int v4; // esi
  int v5; // ebx
  signed __int64 v6; // rcx
  signed __int64 v7; // rcx
  signed __int64 v8; // rcx
  Scaleform::Render::LinearHeap *v9; // rcx
  Scaleform::Render::LinearHeap *v10; // rdx
  Scaleform::Render::Stroker *v11; // rax
  Scaleform::Render::VertexPath *v12; // rax
  unsigned int v13; // edx
  char *v14; // r8
  Scaleform::Log *volatile v15; // rax
  Scaleform::ArrayPagedLH_POD<Scaleform::Render::GlyphCache::UpdateRect,6,16,2> *v16; // [rsp+68h] [rbp+10h]
  signed __int64 v17; // [rsp+68h] [rbp+10h]
  Scaleform::Render::GlyphCache::EvictNotifier *v18; // [rsp+68h] [rbp+10h]
  signed __int64 v19; // [rsp+68h] [rbp+10h]
  signed __int64 v20; // [rsp+68h] [rbp+10h]
  signed __int64 v21; // [rsp+68h] [rbp+10h]
  signed __int64 v22; // [rsp+68h] [rbp+10h]
  signed __int64 v23; // [rsp+68h] [rbp+10h]
  Scaleform::Render::VertexPath *v24; // [rsp+68h] [rbp+10h]

  v2 = heap;
  v3 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  v4 = 1;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::GlyphCache,2>::`vftable';
  this->vfptr = (Scaleform::Render::CacheBaseVtbl *)&Scaleform::Render::CacheBase::`vftable';
  this->vfptr = (Scaleform::Render::GlyphCacheConfigVtbl *)&Scaleform::Render::GlyphCacheConfig::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::GlyphCache::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::GlyphCache,2>'};
  this->vfptr = (Scaleform::Render::CacheBaseVtbl *)&Scaleform::Render::GlyphCache::`vftable'{for `Scaleform::Render::CacheBase'};
  this->vfptr = (Scaleform::Render::GlyphCacheConfigVtbl *)&Scaleform::Render::GlyphCache::`vftable'{for `Scaleform::Render::GlyphCacheConfig'};
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
  `eh vector constructor iterator'(
    this->Textures,
    0x80ui64,
    32,
    (void (__fastcall *)(void *))Scaleform::Render::GlyphTextureMapper::GlyphTextureMapper);
  Scaleform::Render::GlyphQueue::GlyphQueue(&v3->Queue);
  *(_QWORD *)&v3->Method = 0i64;
  *(_QWORD *)&v3->UpdatePacker.Height = 0i64;
  *(_QWORD *)&v3->UpdatePacker.LastY = 0i64;
  v3->UpdateBuffer.pObject = 0i64;
  v16 = &v3->GlyphsToUpdate;
  v16->Size = 0i64;
  v16->NumPages = 0i64;
  v16->MaxPages = 0i64;
  v16->Pages = 0i64;
  v17 = (signed __int64)&v3->RectsToUpdate;
  *(_OWORD *)v17 = 0ui64;
  *(_QWORD *)(v17 + 16) = 0i64;
  v6 = (signed __int64)&v3->RectsToUpdate.Capacity;
  if ( v3 == (Scaleform::Render::GlyphCache *)-4672i64 )
    v6 = 0i64;
  v3->TextInUse.Root.pPrev = (Scaleform::Render::TextMeshProvider *)v6;
  v3->TextInUse.Root.pNext = (Scaleform::Render::TextMeshProvider *)v6;
  v7 = (signed __int64)&v3->TextInUse.Root.8;
  if ( v3 == (Scaleform::Render::GlyphCache *)-4688i64 )
    v7 = 0i64;
  v3->TextInPin.Root.pPrev = (Scaleform::Render::TextMeshProvider *)v7;
  v3->TextInPin.Root.pNext = (Scaleform::Render::TextMeshProvider *)v7;
  v18 = &v3->Notifier;
  v18->vfptr = (Scaleform::Render::GlyphEvictNotifierVtbl *)&Scaleform::Render::GlyphEvictNotifier::`vftable';
  v18->vfptr = (Scaleform::Render::GlyphEvictNotifierVtbl *)&Scaleform::Render::GlyphCache::EvictNotifier::`vftable';
  v3->pFontHandleManager.pObject = 0i64;
  v3->pRQCaches = 0i64;
  v8 = (signed __int64)&v3->Notifier;
  if ( v3 == (Scaleform::Render::GlyphCache *)-4744i64 )
    v8 = 0i64;
  v3->VectorGlyphShapeList.Root.pPrev = (Scaleform::Render::VectorGlyphShape *)v8;
  v3->VectorGlyphShapeList.Root.pNext = (Scaleform::Render::VectorGlyphShape *)v8;
  v3->VectorGlyphCache.pTable = 0i64;
  v3->pSolidFill.pObject = 0i64;
  v3->pMaskFill.pObject = 0i64;
  Scaleform::Render::GlyphFitter::GlyphFitter(&v3->Fitter, v2, 1024);
  Scaleform::Render::Rasterizer::Rasterizer(&v3->Ras, v2);
  Scaleform::Render::GlyphScanlineFilter::GlyphScanlineFilter(&v3->ScanlineFilter, 0.8888889, 0.22222222, 0.022222223);
  v19 = (signed __int64)&v3->RasterData;
  *(_OWORD *)v19 = 0ui64;
  *(_QWORD *)(v19 + 16) = 0i64;
  v20 = (signed __int64)&v3->RasterDataSrc;
  *(_OWORD *)v20 = 0ui64;
  *(_QWORD *)(v20 + 16) = 0i64;
  v21 = (signed __int64)&v3->KnockOutCopy;
  *(_OWORD *)v21 = 0ui64;
  *(_QWORD *)(v21 + 16) = 0i64;
  v3->RasterPitch = 0;
  v22 = (signed __int64)&v3->BlurStack;
  *(_OWORD *)v22 = 0ui64;
  *(_QWORD *)(v22 + 16) = 0i64;
  v23 = (signed __int64)&v3->BlurSum;
  *(_OWORD *)v23 = 0ui64;
  *(_QWORD *)(v23 + 16) = 0i64;
  v9 = &v3->LHeap1;
  v9->pHeap = v2;
  v9->Granularity = 0x2000i64;
  v9->pPagePool = 0i64;
  v9->pLastPage = 0i64;
  v9->MaxPages = 0i64;
  v10 = &v3->LHeap2;
  v10->pHeap = v2;
  v10->Granularity = 0x2000i64;
  v10->pPagePool = 0i64;
  v10->pLastPage = 0i64;
  v10->MaxPages = 0i64;
  v11 = &v3->mStroker;
  v11->vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::TessBase::`vftable';
  v11->vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::Stroker::`vftable';
  v3->mStroker.pHeap = &v3->LHeap2;
  v3->mStroker.Path.Path.pHeap = &v3->LHeap2;
  v3->mStroker.Path.Path.Size = 0i64;
  v3->mStroker.Path.Path.NumPages = 0i64;
  v3->mStroker.Path.Path.MaxPages = 0i64;
  v3->mStroker.Path.Path.Pages = 0i64;
  v3->mStroker.Width = 1.0;
  v3->mStroker.LineJoin = 2;
  v3->mStroker.StartLineCap = 2;
  v3->mStroker.EndLineCap = 2;
  v3->mStroker.MiterLimit = 3.0;
  v3->mStroker.CurveTolerance = 1.0;
  v3->mStroker.IntersectionEpsilon = 0.0099999998;
  v3->mStroker.Closed = 0;
  v12 = &v3->TmpPath1;
  v12->vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::TessBase::`vftable';
  v12->vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::VertexPath::`vftable';
  v3->TmpPath1.Vertices.pHeap = &v3->LHeap1;
  v3->TmpPath1.Vertices.Size = 0i64;
  v3->TmpPath1.Vertices.NumPages = 0i64;
  v3->TmpPath1.Vertices.MaxPages = 0i64;
  v3->TmpPath1.Vertices.Pages = 0i64;
  v3->TmpPath1.Paths.pHeap = &v3->LHeap1;
  v3->TmpPath1.Paths.Size = 0i64;
  v3->TmpPath1.Paths.NumPages = 0i64;
  v3->TmpPath1.Paths.MaxPages = 0i64;
  v3->TmpPath1.Paths.Pages = 0i64;
  v24 = &v3->TmpPath2;
  v24->vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::TessBase::`vftable';
  v24->vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::VertexPath::`vftable';
  v3->TmpPath2.Vertices.pHeap = &v3->LHeap2;
  v3->TmpPath2.Vertices.Size = 0i64;
  v3->TmpPath2.Vertices.NumPages = 0i64;
  v3->TmpPath2.Vertices.MaxPages = 0i64;
  v3->TmpPath2.Vertices.Pages = 0i64;
  v3->TmpPath2.Paths.pHeap = &v3->LHeap2;
  v3->TmpPath2.Paths.Size = 0i64;
  v3->TmpPath2.Paths.NumPages = 0i64;
  v3->TmpPath2.Paths.MaxPages = 0i64;
  v3->TmpPath2.Paths.Pages = 0i64;
  v3->RasterizationCount = 0;
  *(_WORD *)&v3->RasterCacheWarning = 257;
  v3->Notifier.pCache = v3;
  v13 = 0;
  v14 = &v3->FontSizeMap[1];
  do
  {
    if ( v13 > FontSizeRamp[v4] )
    {
      ++v5;
      ++v4;
    }
    *(v14 - 1) = v5;
    if ( v13 + 1 > FontSizeRamp[v4] )
    {
      ++v5;
      ++v4;
    }
    *v14 = v5;
    v13 += 2;
    v14 += 2;
  }
  while ( v13 < 0x100 );
  v15 = Scaleform::SF_GlobalLog;
  v3->pLog = Scaleform::SF_GlobalLog;
  if ( !v15 )
    v3->pLog = Scaleform::Log::GetDefaultLog();
}

// File Line: 267
// RVA: 0x94A690
void __fastcall Scaleform::Render::GlyphCache::~GlyphCache(Scaleform::Render::GlyphCache *this)
{
  Scaleform::Render::GlyphCache *v1; // rdi
  Scaleform::Render::PrimitiveFill *v2; // rcx
  bool v3; // zf
  Scaleform::Render::PrimitiveFill *v4; // rcx
  Scaleform::Render::FontCacheHandleManager *v5; // rcx
  Scaleform::Render::RawImage *v6; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::GlyphCache::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::GlyphCache,2>'};
  this->vfptr = (Scaleform::Render::CacheBaseVtbl *)&Scaleform::Render::GlyphCache::`vftable'{for `Scaleform::Render::CacheBase'};
  this->vfptr = (Scaleform::Render::GlyphCacheConfigVtbl *)&Scaleform::Render::GlyphCache::`vftable'{for `Scaleform::Render::GlyphCacheConfig'};
  Scaleform::Render::GlyphCache::Destroy(this);
  v1->TmpPath2.vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::TessBase::`vftable';
  v1->TmpPath1.vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::TessBase::`vftable';
  v1->mStroker.vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::TessBase::`vftable';
  Scaleform::Render::LinearHeap::ClearAndRelease(&v1->LHeap2);
  Scaleform::Render::LinearHeap::ClearAndRelease(&v1->LHeap1);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->BlurSum.Data.Data);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->BlurStack.Data.Data);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->KnockOutCopy.Data.Data);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->RasterDataSrc.Data.Data);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->RasterData.Data.Data);
  Scaleform::Render::LinearHeap::ClearAndRelease(&v1->Ras.LHeap);
  v1->Ras.vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::TessBase::`vftable';
  Scaleform::Render::LinearHeap::ClearAndRelease(&v1->Fitter.LHeap);
  v1->Fitter.vfptr = (Scaleform::Render::TessBaseVtbl *)&Scaleform::Render::TessBase::`vftable';
  v2 = v1->pMaskFill.pObject;
  if ( v2 )
  {
    v3 = v2->RefCount-- == 1;
    if ( v3 )
      v2->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v2->vfptr, 1u);
  }
  v4 = v1->pSolidFill.pObject;
  if ( v4 )
  {
    v3 = v4->RefCount-- == 1;
    if ( v3 )
      v4->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v4->vfptr, 1u);
  }
  Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor>>::~HashSetBase<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor>>((Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor> > *)&v1->VectorGlyphCache.pTable);
  v5 = v1->pFontHandleManager.pObject;
  if ( v5 && !_InterlockedDecrement(&v5->RefCount) && v5 )
    v5->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v5->vfptr, 1u);
  v1->Notifier.vfptr = (Scaleform::Render::GlyphEvictNotifierVtbl *)&Scaleform::Render::GlyphEvictNotifier::`vftable';
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->RectsToUpdate.Data);
  Scaleform::ArrayPagedBase<Scaleform::Render::GlyphCache::UpdateRect,6,16,Scaleform::AllocatorPagedLH_POD<Scaleform::Render::GlyphCache::UpdateRect,2>>::ClearAndRelease((Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2> > *)&v1->GlyphsToUpdate);
  v6 = v1->UpdateBuffer.pObject;
  if ( v6 )
    ((void (__cdecl *)(Scaleform::Render::RawImage *))v6->vfptr[2].__vecDelDtor)(v6);
  Scaleform::Render::GlyphQueue::~GlyphQueue(&v1->Queue);
  `eh vector destructor iterator'(
    v1->Textures,
    0x80ui64,
    32,
    (void (__fastcall *)(void *))Scaleform::Render::GlyphTextureMapper::~GlyphTextureMapper);
  v1->vfptr = (Scaleform::Render::GlyphCacheConfigVtbl *)&Scaleform::Render::GlyphCacheConfig::`vftable';
  v1->vfptr = (Scaleform::Render::CacheBaseVtbl *)&Scaleform::Render::CacheBase::`vftable';
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
}

// File Line: 273
// RVA: 0x96D010
void __fastcall Scaleform::Render::GlyphCache::Destroy(Scaleform::Render::GlyphCache *this)
{
  Scaleform::Render::GlyphCache *v1; // rbx
  unsigned int v2; // ecx
  __int64 v3; // rax
  signed __int64 v4; // rcx
  Scaleform::Render::FontCacheHandleManager *v5; // rcx
  Scaleform::Render::FontCacheHandleManager *v6; // rcx
  Scaleform::Render::RQCacheInterface *v7; // rax

  v1 = this;
  Scaleform::Render::GlyphCache::UnpinAllSlots(this);
  Scaleform::Render::GlyphQueue::Clear(&v1->Queue);
  v2 = 0;
  if ( v1->MaxNumTextures )
  {
    do
    {
      v3 = v2++;
      v3 <<= 7;
      *(&v1->Textures[0].Valid + v3) = 0;
      *(unsigned int *)((char *)&v1->Textures[0].NumGlyphsToUpdate + v3) = 0;
    }
    while ( v2 < v1->MaxNumTextures );
  }
  *(_QWORD *)&v1->UpdatePacker.LastX = 0i64;
  v1->UpdatePacker.LastMaxHeight = 0;
  v1->GlyphsToUpdate.Size = 0i64;
  v1->RectsToUpdate.Size = 0i64;
  v4 = (signed __int64)&v1->Notifier;
  if ( v1 == (Scaleform::Render::GlyphCache *)-4744i64 )
    v4 = 0i64;
  v1->VectorGlyphShapeList.Root.pPrev = (Scaleform::Render::VectorGlyphShape *)v4;
  v1->VectorGlyphShapeList.Root.pNext = (Scaleform::Render::VectorGlyphShape *)v4;
  Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor>>::~HashSetBase<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor>>((Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor> > *)&v1->VectorGlyphCache.pTable);
  v5 = v1->pFontHandleManager.pObject;
  if ( v5 )
  {
    Scaleform::Render::FontCacheHandleManager::DestroyAllFonts(v5);
    v6 = v1->pFontHandleManager.pObject;
    if ( v6 && !_InterlockedDecrement(&v6->RefCount) && v6 )
      v6->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v6->vfptr, 1u);
    v1->pFontHandleManager.pObject = 0i64;
  }
  v7 = v1->pRQCaches;
  if ( v7 )
  {
    v7->pCaches[1] = 0i64;
    v1->pRQCaches = 0i64;
  }
}

// File Line: 300
// RVA: 0x9603E0
void __fastcall Scaleform::Render::GlyphCache::ClearCache(Scaleform::Render::GlyphCache *this)
{
  Scaleform::Render::GlyphCache *v1; // rbx
  signed __int64 v2; // rax

  v1 = this;
  Scaleform::Render::GlyphCache::UnpinAllSlots((Scaleform::Render::GlyphCache *)((char *)this - 24));
  Scaleform::Render::GlyphQueue::Clear((Scaleform::Render::GlyphQueue *)&v1->Textures[31].pTexImg);
  v2 = 0i64;
  *(void **)((char *)&v1->Queue.Notifiers.pHeapOrPtr + 4) = 0i64;
  HIDWORD(v1->Queue.pEvictNotifier) = 0;
  *(_QWORD *)&v1->UpdatePacker.LastY = 0i64;
  v1->GlyphsToUpdate.MaxPages = 0i64;
  if ( v1 != (Scaleform::Render::GlyphCache *)-4720i64 )
    v2 = (signed __int64)&v1->TextInUse.Root.8;
  v1->pFontHandleManager.pObject = (Scaleform::Render::FontCacheHandleManager *)v2;
  v1->pRQCaches = (Scaleform::Render::RQCacheInterface *)v2;
  Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor>>::~HashSetBase<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor>>((Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor> > *)&v1->pLog);
}

// File Line: 312
// RVA: 0x9B26F0
char __fastcall Scaleform::Render::GlyphCache::SetParams(Scaleform::Render::GlyphCache *this, Scaleform::Render::GlyphCacheParams *params)
{
  Scaleform::Render::GlyphCache *v2; // rbx
  __int64 v3; // rcx

  v2 = this;
  this->RefCount = params->TextureWidth;
  *((_DWORD *)&this->RefCount + 1) = params->TextureHeight;
  LODWORD(this->vfptr) = params->NumTextures;
  HIDWORD(this->vfptr) = params->MaxSlotHeight;
  LODWORD(this->vfptr) = params->SlotPadding;
  HIDWORD(this->vfptr) = params->TexUpdWidth;
  this->Param.TextureWidth = params->TexUpdHeight;
  this->Param.TextureHeight = LODWORD(params->MaxRasterScale);
  this->Param.NumTextures = params->MaxVectorCacheSize;
  this->Param.MaxSlotHeight = LODWORD(params->FauxItalicAngle);
  this->Param.SlotPadding = LODWORD(params->FauxBoldRatio);
  this->Param.TexUpdWidth = LODWORD(params->OutlineRatio);
  this->Param.TexUpdHeight = LODWORD(params->ShadowQuality);
  this->Param.MaxRasterScale = *(float *)&params->UseAutoFit;
  v3 = *(_QWORD *)&this->Param.FauxBoldRatio;
  if ( v3 && (*(unsigned __int8 (**)(void))(*(_QWORD *)v3 + 32i64))() )
    Scaleform::Render::GlyphCache::initialize((Scaleform::Render::GlyphCache *)((char *)v2 - 24));
  return 1;
}

// File Line: 345
// RVA: 0x9E88A0
void __fastcall Scaleform::Render::GlyphCache::initialize(Scaleform::Render::GlyphCache *this)
{
  Scaleform::Render::GlyphCache *v1; // rbp
  unsigned int v2; // edi
  unsigned int v3; // ebx
  unsigned int v4; // er14
  unsigned int v5; // er15
  unsigned int v6; // er9
  unsigned int v7; // er12
  unsigned int v8; // er13
  unsigned int v9; // eax
  unsigned int v10; // ecx
  char v11; // dl
  char i; // r8
  signed int v13; // edx
  char v14; // al
  Scaleform::Render::RawImage *v15; // rbx
  Scaleform::Render::RawImage *v16; // rcx
  unsigned int v17; // ebx
  unsigned int v18; // ecx
  Scaleform::Render::FontCacheHandleManager *v19; // rax
  Scaleform::Render::FontCacheHandleManager *v20; // rax
  Scaleform::Render::FontCacheHandleManager *v21; // rbx
  Scaleform::Render::FontCacheHandleManager *v22; // rcx
  Scaleform::Render::PrimitiveFill *v23; // rbx
  Scaleform::Render::PrimitiveFill *v24; // rcx
  bool v25; // zf
  __int64 v26; // rdx
  Scaleform::Render::PrimitiveFill *v27; // rbx
  __int64 v28; // r8
  __int64 v29; // r9
  Scaleform::Render::PrimitiveFill *v30; // rcx
  __int64 v31; // rax
  Scaleform::Render::ImageUpdateSync *pupdateSync; // [rsp+28h] [rbp-B0h]
  unsigned int textureId; // [rsp+30h] [rbp-A8h]
  Scaleform::Render::PrimitiveFillData ptr; // [rsp+48h] [rbp-90h]
  Scaleform::Render::PrimitiveFillData initdata; // [rsp+70h] [rbp-68h]
  Scaleform::Render::Size<unsigned long> size; // [rsp+E0h] [rbp+8h]
  Scaleform::Render::Size<unsigned long> v37; // [rsp+E8h] [rbp+10h]
  Scaleform::Render::FontCacheHandleManager *v38; // [rsp+F0h] [rbp+18h]

  v1 = this;
  Scaleform::Render::GlyphCache::Destroy(this);
  v1->pTexMan = (Scaleform::Render::TextureManager *)((__int64 (*)(void))v1->pRenderer->vfptr[61].__vecDelDtor)();
  v2 = v1->Param.TextureWidth;
  v3 = v1->Param.TextureHeight;
  v4 = v1->Param.NumTextures;
  v5 = v1->Param.MaxSlotHeight;
  v6 = v1->Param.SlotPadding;
  v7 = v1->Param.TexUpdWidth;
  v8 = v1->Param.TexUpdHeight;
  LOBYTE(size.Width) = v1->Param.FenceWaitOnFullCache;
  v9 = 63;
  v10 = 63;
  if ( v2 >= 0x40 )
    v10 = v2 - 1;
  if ( v3 >= 0x40 )
    v9 = v3 - 1;
  v11 = 0;
  for ( i = 0; v10; v10 >>= 1 )
    ++v11;
  for ( ; v9; v9 >>= 1 )
    ++i;
  if ( v4 > 0x20 )
    v4 = 32;
  v13 = 1 << v11;
  v1->TextureWidth = v13;
  v1->TextureHeight = 1 << i;
  v1->MaxNumTextures = v4;
  v1->MaxSlotHeight = v5;
  v1->SlotPadding = v6;
  v1->ScaleU = 1.0 / (float)v13;
  v1->ScaleV = 1.0 / (float)(1 << i);
  v1->ShadowQuality = v1->Param.ShadowQuality;
  if ( v4 )
  {
    Scaleform::Render::GlyphQueue::Clear(&v1->Queue);
    v1->Queue.FirstTexture = 0;
    v1->Queue.NumTextures = v4;
    v1->Queue.TextureWidth = v2;
    v1->Queue.TextureHeight = v3;
    v1->Queue.MaxSlotHeight = v5;
    v1->Queue.NumBandsInTexture = v3 / v5;
    v1->Queue.FenceWaitOnFullCache = size.Width;
    Scaleform::ArrayUnsafeBase<Scaleform::Render::GlyphBand,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphBand,75>>::Reserve(
      (Scaleform::ArrayUnsafeBase<Scaleform::Render::GlyphBand,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphBand,75> > *)&v1->Queue.Bands.Data,
      v4 * (v3 / v5),
      0i64);
    v1->Queue.Bands.Size = v4 * (v3 / v5);
    v1->Queue.pEvictNotifier = (Scaleform::Render::GlyphEvictNotifier *)&v1->Notifier.vfptr;
    v14 = (__int64)v1->pTexMan->vfptr[3].__vecDelDtor((Scaleform::RefCountImplCore *)&v1->pTexMan->vfptr, 9u);
    if ( v14 >= 0 )
    {
      if ( v14 & 0x20 )
      {
        v1->Method = 1;
        v1->UpdatePacker.Width = v7;
        v1->UpdatePacker.Height = v8;
        *(_QWORD *)&v1->UpdatePacker.LastX = 0i64;
        v1->UpdatePacker.LastMaxHeight = 0;
        size.Width = v7;
        size.Height = v8;
        v15 = Scaleform::Render::RawImage::Create(Image_A8, 1u, &size, 0, v1->pHeap, 0i64);
        v16 = v1->UpdateBuffer.pObject;
        if ( v16 )
          ((void (*)(void))v16->vfptr[2].__vecDelDtor)();
        v1->UpdateBuffer.pObject = v15;
      }
      else
      {
        v1->Method = 2;
      }
    }
    else
    {
      v1->Method = 0;
    }
    v17 = 0;
    if ( v1->MaxNumTextures )
    {
      do
      {
        v18 = v1->TextureHeight;
        v37.Width = v1->TextureWidth;
        v37.Height = v18;
        textureId = v17;
        pupdateSync = (Scaleform::Render::ImageUpdateSync *)v1;
        Scaleform::Render::GlyphTextureMapper::Create(
          &v1->Textures[(unsigned __int64)v17++],
          v1->Method,
          v1->pHeap,
          v1->pTexMan,
          v1->pFillMan);
      }
      while ( v17 < v1->MaxNumTextures );
    }
  }
  if ( !v1->pFontHandleManager.pObject )
  {
    v19 = (Scaleform::Render::FontCacheHandleManager *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                         Scaleform::Memory::pGlobalHeap,
                                                         104i64);
    v38 = v19;
    if ( v19 )
    {
      Scaleform::Render::FontCacheHandleManager::FontCacheHandleManager(v19, v1->pHeap, v1);
      v21 = v20;
    }
    else
    {
      v21 = 0i64;
    }
    v22 = v1->pFontHandleManager.pObject;
    if ( v22 && !_InterlockedDecrement(&v22->RefCount) && v22 )
      v22->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v22->vfptr, 1u);
    v1->pFontHandleManager.pObject = v21;
  }
  *(_QWORD *)&initdata.Type = 4i64;
  *(_WORD *)&initdata.FillModes[0].Fill = 0;
  `eh vector constructor iterator'(
    initdata.Textures,
    8ui64,
    2,
    (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>);
  initdata.pFormat = &Scaleform::Render::VertexXY16iCF32::Format;
  *(_QWORD *)&ptr.Type = 1i64;
  *(_WORD *)&ptr.FillModes[0].Fill = 0;
  `eh vector constructor iterator'(
    ptr.Textures,
    8ui64,
    2,
    (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>);
  ptr.pFormat = &Scaleform::Render::VertexXY16i::Format;
  v23 = Scaleform::Render::PrimitiveFillManager::CreateFill(v1->pFillMan, &initdata);
  v24 = v1->pSolidFill.pObject;
  if ( v24 )
  {
    v25 = v24->RefCount-- == 1;
    if ( v25 )
      v24->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v24->vfptr, 1u);
  }
  v1->pSolidFill.pObject = v23;
  v27 = Scaleform::Render::PrimitiveFillManager::CreateFill(v1->pFillMan, &ptr);
  v30 = v1->pMaskFill.pObject;
  if ( v30 )
  {
    v25 = v30->RefCount-- == 1;
    if ( v25 )
      v30->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v30->vfptr, 1u);
  }
  v1->pMaskFill.pObject = v27;
  v31 = ((__int64 (__cdecl *)(Scaleform::Render::HAL *, __int64, __int64, __int64, void (__fastcall *)(Scaleform::Ptr<Scaleform::Render::TextureManagerLocks> *), Scaleform::Render::ImageUpdateSync *, unsigned int))v1->pRenderer->vfptr[63].__vecDelDtor)(
          v1->pRenderer,
          v26,
          v28,
          v29,
          Scaleform::Ptr<Scaleform::Render::StereoImplBase>::~Ptr<Scaleform::Render::StereoImplBase>,
          pupdateSync,
          textureId);
  v1->pRQCaches = (Scaleform::Render::RQCacheInterface *)v31;
  *(_QWORD *)(v31 + 8) = (char *)v1 + 16;
  `eh vector destructor iterator'(
    ptr.Textures,
    8ui64,
    2,
    (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::StereoImplBase>::~Ptr<Scaleform::Render::StereoImplBase>);
  `eh vector destructor iterator'(
    initdata.Textures,
    8ui64,
    2,
    (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::StereoImplBase>::~Ptr<Scaleform::Render::StereoImplBase>);
}

// File Line: 454
// RVA: 0x95ED80
void __fastcall Scaleform::Render::GlyphCache::CleanUpFont(Scaleform::Render::GlyphCache *this, Scaleform::Render::FontCacheHandle *font)
{
  Scaleform::Render::FontCacheHandle *v2; // rbp
  Scaleform::Render::GlyphCache *v3; // rsi
  Scaleform::Render::VectorGlyphShape *v4; // r8
  signed __int64 v5; // rax
  Scaleform::Render::VectorGlyphShape *v6; // rbx
  Scaleform::Render::VectorGlyphShape *key; // [rsp+30h] [rbp+8h]

  v2 = font;
  v3 = this;
  Scaleform::Render::GlyphCache::ApplyInUseList(this);
  Scaleform::Render::GlyphCache::UpdatePinList(v3);
  Scaleform::Render::GlyphQueue::CleanUpFont(&v3->Queue, v2);
  v4 = v3->VectorGlyphShapeList.Root.pNext;
  for ( key = v3->VectorGlyphShapeList.Root.pNext; ; key = v6 )
  {
    v5 = (signed __int64)(v3 == (Scaleform::Render::GlyphCache *)-4744i64 ? 0i64 : &v3->Notifier);
    if ( v4 == (Scaleform::Render::VectorGlyphShape *)v5 )
      break;
    v6 = v4->pNext;
    if ( v4->Key.pFont == v2 )
    {
      v4->pPrev->pNext = v6;
      v4->pNext->pPrev = v4->pPrev;
      Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor>>::RemoveAlt<Scaleform::Render::VectorGlyphShape *>(
        (Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor> > *)&v3->VectorGlyphCache.pTable,
        &key);
    }
    v4 = v6;
  }
}

// File Line: 475
// RVA: 0x9834D0
Scaleform::Render::PrimitiveFill *__fastcall Scaleform::Render::GlyphCache::GetFill(Scaleform::Render::GlyphCache *this, Scaleform::Render::TextLayerType type, unsigned int textureId)
{
  Scaleform::Render::PrimitiveFill *result; // rax

  switch ( type )
  {
    case 0:
    case 1:
    case 8:
    case 9:
    case 10:
    case 12:
    case 13:
      result = this->pSolidFill.pObject;
      break;
    case 2:
    case 3:
    case 4:
      result = this->Textures[(unsigned __int64)textureId].pFill.pObject;
      break;
    case 11:
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
  Scaleform::Render::GlyphCache *v1; // r14
  unsigned int i; // er12
  unsigned __int64 v3; // r13
  unsigned int v4; // eax
  unsigned __int64 v5; // rdi
  Scaleform::ArrayUnsafeLH_POD<Scaleform::Render::Texture::UpdateDesc,2> *v6; // r15
  __int64 v7; // r8
  unsigned int v8; // esi
  unsigned int *v9; // r15
  signed __int64 v10; // rdi
  Scaleform::Render::ImagePlane *v11; // rcx
  Scaleform::Render::Texture::UpdateDesc *v12; // rdi
  __int64 v13; // rax
  Scaleform::Render::ImageData v14; // [rsp+20h] [rbp-69h]
  Scaleform::Render::ImageData v15; // [rsp+60h] [rbp-29h]
  __int64 v16; // [rsp+A0h] [rbp+17h]
  unsigned int v17; // [rsp+F0h] [rbp+67h]

  v16 = -2i64;
  v1 = this;
  *(_QWORD *)&v15.Format = 0i64;
  *(_DWORD *)&v15.Flags = 0x10000;
  v15.pPlanes = &v15.Plane0;
  v15.pPalette.pObject = 0i64;
  *(_QWORD *)&v15.Plane0.Width = 0i64;
  v15.Plane0.Pitch = 0i64;
  v15.Plane0.DataSize = 0i64;
  v15.Plane0.pData = 0i64;
  Scaleform::Render::ImageData::operator=(&v15, &this->UpdateBuffer.pObject->Data);
  for ( i = 0; i < v1->MaxNumTextures; ++i )
  {
    v3 = (unsigned __int64)&v1->Textures[(unsigned __int64)i];
    v4 = *(_DWORD *)(v3 + 124);
    if ( v4 )
    {
      v5 = v4;
      v6 = &v1->RectsToUpdate;
      Scaleform::ArrayUnsafeBase<Scaleform::Render::Texture::UpdateDesc,Scaleform::AllocatorLH_POD<Scaleform::Render::Texture::UpdateDesc,2>>::Reserve(
        (Scaleform::ArrayUnsafeBase<Scaleform::Render::Texture::UpdateDesc,Scaleform::AllocatorLH_POD<Scaleform::Render::Texture::UpdateDesc,2> > *)&v1->RectsToUpdate.Data,
        v4,
        0x20ui64);
      v1->RectsToUpdate.Size = v5;
      v7 = 0i64;
      v17 = 0;
      v8 = 0;
      if ( LODWORD(v1->GlyphsToUpdate.Size) )
      {
        do
        {
          v9 = &v1->GlyphsToUpdate.Pages[(unsigned __int64)v8 >> 6][v8 & 0x3F].SrcX;
          if ( v9[6] == i )
          {
            v10 = (signed __int64)&v1->RectsToUpdate.Data[(unsigned int)v7];
            v17 = v7 + 1;
            *(_QWORD *)&v14.Format = 0i64;
            *(_DWORD *)&v14.Flags = 0x10000;
            v14.pPlanes = &v14.Plane0;
            v14.pPalette.pObject = 0i64;
            *(_QWORD *)&v14.Plane0.Width = 0i64;
            v14.Plane0.Pitch = 0i64;
            v14.Plane0.DataSize = 0i64;
            v14.Plane0.pData = 0i64;
            Scaleform::Render::ImageData::operator=(&v14, &v1->UpdateBuffer.pObject->Data);
            *(_DWORD *)(v10 + 32) = v9[2];
            *(_DWORD *)(v10 + 36) = v9[3];
            *(_DWORD *)(v10 + 40) = v9[2] + v9[4];
            *(_DWORD *)(v10 + 44) = v9[3] + v9[5];
            v11 = v15.pPlanes;
            *(_DWORD *)v10 = v15.pPlanes->Width;
            *(_DWORD *)(v10 + 4) = v11->Height;
            *(_QWORD *)(v10 + 8) = v11->Pitch;
            *(_QWORD *)(v10 + 16) = v11->DataSize;
            *(_QWORD *)(v10 + 24) = v11->pData;
            *(_QWORD *)(v10 + 24) = &v14.pPlanes->pData[v14.pPlanes->Pitch * v9[1] + *v9];
            *(_DWORD *)(v10 + 48) = 0;
            if ( v14.Flags & 2 )
            {
              v14.Flags &= 0xFDu;
              Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v14.pPlanes);
            }
            v14.pPlanes = &v14.Plane0;
            if ( v14.pPalette.pObject && !_InterlockedDecrement(&v14.pPalette.pObject->RefCount.Value) )
              ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            v7 = v17;
          }
          ++v8;
        }
        while ( v8 < LODWORD(v1->GlyphsToUpdate.Size) );
        v6 = &v1->RectsToUpdate;
      }
      v12 = v6->Data;
      if ( *(_DWORD *)(v3 + 4) == 1 )
      {
        v13 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, __int64))(**(_QWORD **)(v3 + 104) + 168i64))(
                *(_QWORD *)(v3 + 104),
                *(_QWORD *)(v3 + 8),
                v7);
        if ( v13 )
          (*(void (__fastcall **)(__int64, Scaleform::Render::Texture::UpdateDesc *, _QWORD, _QWORD, _QWORD))(*(_QWORD *)v13 + 144i64))(
            v13,
            v12,
            v17,
            0i64,
            *(_QWORD *)&v14.Format);
      }
      *(_DWORD *)(v3 + 124) = 0;
    }
  }
  v1->GlyphsToUpdate.Size = 0i64;
  *(_QWORD *)&v1->UpdatePacker.LastX = 0i64;
  v1->UpdatePacker.LastMaxHeight = 0;
  if ( v15.Flags & 2 )
  {
    v15.Flags &= 0xFDu;
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v15.pPlanes);
  }
  v15.pPlanes = &v15.Plane0;
  if ( v15.pPalette.pObject )
  {
    if ( !_InterlockedDecrement(&v15.pPalette.pObject->RefCount.Value) )
      ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
}

// File Line: 565
// RVA: 0x9DC840
void __fastcall Scaleform::Render::GlyphCache::copyImageData(Scaleform::Render::GlyphCache *this, Scaleform::Render::ImagePlane *pl, const char *data, unsigned int pitch, unsigned int dstX, unsigned int dstY, unsigned int w, unsigned int h)
{
  unsigned int v8; // ebx
  const char *v9; // rdi
  Scaleform::Render::ImagePlane *v10; // rsi
  __int64 v11; // r12

  v8 = 0;
  v9 = data;
  v10 = pl;
  if ( h )
  {
    v11 = pitch;
    do
    {
      memmove(&v10->pData[dstX + v10->Pitch * (v8++ + dstY)], v9, w);
      v9 += v11;
    }
    while ( v8 < h );
  }
}

// File Line: 577
// RVA: 0x9FAC10
char __fastcall Scaleform::Render::GlyphCache::updateTextureGlyph(Scaleform::Render::GlyphCache *this, Scaleform::Render::GlyphNode *node)
{
  Scaleform::Render::GlyphCache *v2; // rbx
  int v3; // er12
  unsigned int v4; // er14
  unsigned int v5; // er13
  unsigned int v6; // er15
  unsigned int v7; // edi
  unsigned int v8; // ecx
  unsigned int v9; // er14
  int v10; // ecx
  unsigned int v11; // esi
  Scaleform::ArrayPagedBase<Scaleform::Render::GlyphCache::UpdateRect,6,16,Scaleform::AllocatorPagedLH_POD<Scaleform::Render::GlyphCache::UpdateRect,2> > *v12; // rbx
  unsigned __int64 v13; // r13
  Scaleform::Render::GlyphCache::UpdateRect *v14; // rcx
  Scaleform::Render::ImagePlane *v15; // rax
  const char *data; // [rsp+40h] [rbp-49h]
  char *v18; // [rsp+48h] [rbp-41h]
  Scaleform::Render::ImageData v19; // [rsp+60h] [rbp-29h]
  unsigned int pitch; // [rsp+F0h] [rbp+67h]
  unsigned int v21; // [rsp+F8h] [rbp+6Fh]
  unsigned int v22; // [rsp+100h] [rbp+77h]
  Scaleform::Render::Size<unsigned long> v23; // [rsp+108h] [rbp+7Fh]

  v2 = this;
  v3 = node->pSlot->TextureId & 0x7FFF;
  data = this->RasterData.Data.Data;
  pitch = this->RasterPitch;
  v4 = node->mRect.x;
  v21 = node->mRect.x;
  v5 = node->mRect.y;
  v22 = node->mRect.y;
  v6 = node->mRect.w;
  v7 = node->mRect.h;
  v18 = (char *)this + 128 * (unsigned __int64)(node->pSlot->TextureId & 0x7FFF);
  if ( !v18[152] )
  {
    v8 = this->TextureHeight;
    v23.Width = v2->TextureWidth;
    v23.Height = v8;
    Scaleform::Render::GlyphTextureMapper::Create(
      (Scaleform::Render::GlyphTextureMapper *)(v18 + 152),
      v2->Method,
      v2->pHeap,
      v2->pTexMan,
      v2->pFillMan);
  }
  v2->pRQCaches->LockFlags |= 2u;
  if ( v2->Method == 1 )
  {
    v9 = v2->UpdatePacker.LastX;
    v10 = v9 + v6;
    if ( v9 + v6 <= v2->UpdatePacker.Width )
    {
      v11 = v2->UpdatePacker.LastY;
      if ( v11 + v7 <= v2->UpdatePacker.Height )
      {
LABEL_6:
        v2->UpdatePacker.LastX = v10;
        if ( v7 <= v2->UpdatePacker.LastMaxHeight )
        {
LABEL_14:
          *(_QWORD *)&v19.Format = 0i64;
          *(_DWORD *)&v19.Flags = 0x10000;
          v19.pPlanes = &v19.Plane0;
          v19.pPalette.pObject = 0i64;
          *(_QWORD *)&v19.Plane0.Width = 0i64;
          v19.Plane0.Pitch = 0i64;
          v19.Plane0.DataSize = 0i64;
          v19.Plane0.pData = 0i64;
          Scaleform::Render::ImageData::operator=(&v19, &v2->UpdateBuffer.pObject->Data);
          Scaleform::Render::GlyphCache::copyImageData(v2, v19.pPlanes, data, pitch, v9, v11, v6, v7);
          ++*((_DWORD *)v18 + 69);
          v12 = (Scaleform::ArrayPagedBase<Scaleform::Render::GlyphCache::UpdateRect,6,16,Scaleform::AllocatorPagedLH_POD<Scaleform::Render::GlyphCache::UpdateRect,2> > *)v2->GlyphsToUpdate.gap0;
          v13 = v12->Size >> 6;
          if ( v13 >= v12->NumPages )
            Scaleform::ArrayPagedBase<Scaleform::Render::GlyphCache::UpdateRect,6,16,Scaleform::AllocatorPagedLH_POD<Scaleform::Render::GlyphCache::UpdateRect,2>>::allocatePage(
              v12,
              v12->Size >> 6);
          v14 = &v12->Pages[v13][v12->Size & 0x3F];
          v14->SrcX = v9;
          v14->SrcY = v11;
          v14->DstX = v21;
          v14->DstY = v22;
          v14->w = v6;
          v14->h = v7;
          v14->TextureId = v3;
          ++v12->Size;
          if ( v19.Flags & 2 )
          {
            v19.Flags &= 0xFDu;
            Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v19.pPlanes);
          }
          v19.pPlanes = &v19.Plane0;
          if ( v19.pPalette.pObject )
          {
            if ( !_InterlockedDecrement(&v19.pPalette.pObject->RefCount.Value) )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          }
          return 1;
        }
LABEL_13:
        v2->UpdatePacker.LastMaxHeight = v7;
        goto LABEL_14;
      }
    }
    v2->UpdatePacker.LastY += v2->UpdatePacker.LastMaxHeight;
    v11 = v2->UpdatePacker.LastY;
    if ( v11 + v7 <= v2->UpdatePacker.Height )
      goto LABEL_27;
    Scaleform::Render::GlyphCache::partialUpdateTextures(v2);
    v9 = v2->UpdatePacker.LastX;
    v10 = v9 + v6;
    if ( v9 + v6 <= v2->UpdatePacker.Width )
    {
      v11 = v2->UpdatePacker.LastY;
      if ( v11 + v7 <= v2->UpdatePacker.Height )
        goto LABEL_6;
    }
    v2->UpdatePacker.LastY += v2->UpdatePacker.LastMaxHeight;
    v11 = v2->UpdatePacker.LastY;
    if ( v11 + v7 <= v2->UpdatePacker.Height )
    {
LABEL_27:
      v2->UpdatePacker.LastX = v6;
      v9 = 0;
      goto LABEL_13;
    }
  }
  else
  {
    v15 = Scaleform::Render::GlyphTextureMapper::Map((Scaleform::Render::GlyphTextureMapper *)(v18 + 152));
    if ( v15 )
    {
      Scaleform::Render::GlyphCache::copyImageData(v2, v15, data, pitch, v4, v5, v6, v7);
      return 1;
    }
  }
  return 0;
}

// File Line: 682
// RVA: 0x9BB4D0
void __fastcall Scaleform::Render::GlyphCache::UnlockBuffers(Scaleform::Render::GlyphCache *this)
{
  Scaleform::Render::GlyphCache *v1; // rsi
  unsigned int v2; // edi
  unsigned __int64 v3; // rbx
  int v4; // eax
  __int64 v5; // rax

  v1 = this;
  if ( LODWORD(this->Queue.Notifiers.pHeapOrPtr) == 1 )
    Scaleform::Render::GlyphCache::partialUpdateTextures((Scaleform::Render::GlyphCache *)((char *)this - 16));
  v2 = 0;
  if ( LODWORD(v1->pTexMan) )
  {
    while ( 1 )
    {
      v3 = (unsigned __int64)v2 << 7;
      v4 = *(_DWORD *)((char *)&v1->ScaleU + v3);
      if ( v4 )
        break;
      if ( *((_BYTE *)&v1->Textures[0].pTexImg.pObject + v3) )
      {
        (*(void (**)(void))(**(_QWORD **)((char *)&v1->Textures[0].Data.Plane0.pData + v3) + 144i64))();
LABEL_10:
        *((_BYTE *)&v1->Textures[0].pTexImg.pObject + v3) = 0;
      }
LABEL_11:
      if ( ++v2 >= LODWORD(v1->pTexMan) )
        goto LABEL_12;
    }
    if ( v4 != 2 || !*((_BYTE *)&v1->Textures[0].pTexImg.pObject + v3) )
      goto LABEL_11;
    (*(void (**)(void))(**(_QWORD **)((char *)&v1->Textures[0].Data.Plane0.DataSize + v3) + 144i64))();
    v5 = (*(__int64 (__fastcall **)(_QWORD, _QWORD))(**(_QWORD **)((char *)&v1->Textures[0].Data.Plane0.DataSize + v3)
                                                   + 168i64))(
           *(unsigned __int64 *)((char *)&v1->Textures[0].Data.Plane0.DataSize + v3),
           *(_QWORD *)((char *)&v1->ScaleV + v3));
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v5 + 136i64))(v5);
    goto LABEL_10;
  }
LABEL_12:
  LODWORD(v1->Notifier.pCache->vfptr) &= 0xFFFFFFFD;
}

// File Line: 705
// RVA: 0x9B9C40
void __fastcall Scaleform::Render::GlyphCache::TextureLost(Scaleform::Render::GlyphCache *this, unsigned int textureId, unsigned int reason)
{
  Scaleform::Render::GlyphCache *v3; // rbx
  __int64 v4; // rdi
  unsigned __int64 v5; // rax
  unsigned __int64 v6; // r10
  Scaleform::Render::GlyphCache::UpdateRect **v7; // r8
  Scaleform::Render::GlyphCache::UpdateRect *v8; // r9
  Scaleform::Render::GlyphCache::UpdateRect *v9; // r8
  __int64 v10; // rax

  v3 = this;
  v4 = textureId;
  Scaleform::Render::GlyphQueue::CleanUpTexture(&this->Queue, textureId);
  v5 = 0i64;
  v6 = 0i64;
  if ( v3->GlyphsToUpdate.Size )
  {
    do
    {
      v7 = v3->GlyphsToUpdate.Pages;
      v8 = &v7[v5 >> 6][v5 & 0x3F];
      if ( v8->TextureId != (_DWORD)v4 )
      {
        v9 = &v7[v6 >> 6][v6 & 0x3F];
        ++v6;
        v9->SrcX = v8->SrcX;
        v9->SrcY = v8->SrcY;
        v9->DstX = v8->DstX;
        v9->DstY = v8->DstY;
        v9->w = v8->w;
        v9->h = v8->h;
        v9->TextureId = v8->TextureId;
      }
      ++v5;
    }
    while ( v5 < v3->GlyphsToUpdate.Size );
  }
  if ( v6 < v3->GlyphsToUpdate.Size )
    v3->GlyphsToUpdate.Size = v6;
  v10 = v4 << 7;
  *(&v3->Textures[0].Valid + v10) = 0;
  *(unsigned int *)((char *)&v3->Textures[0].NumGlyphsToUpdate + v10) = 0;
}

// File Line: 722
// RVA: 0x9A7540
Scaleform::Render::FontCacheHandle *__fastcall Scaleform::Render::GlyphCache::RegisterFont(Scaleform::Render::GlyphCache *this, Scaleform::Render::Font *font)
{
  Scaleform::Render::Font *v2; // rdi
  Scaleform::Render::GlyphCache *v3; // rbx
  Scaleform::Render::HAL *v4; // rcx
  Scaleform::Render::FontCacheHandleManager *v5; // rcx

  v2 = font;
  v3 = this;
  if ( !this->pFontHandleManager.pObject )
  {
    v4 = this->pRenderer;
    if ( !v4 || !((unsigned __int8 (*)(void))v4->vfptr[4].__vecDelDtor)() )
      return 0i64;
    Scaleform::Render::GlyphCache::initialize(v3);
  }
  v5 = v3->pFontHandleManager.pObject;
  if ( v5 )
    return Scaleform::Render::FontCacheHandleManager::RegisterFont(v5, v2);
  return 0i64;
}

// File Line: 743
// RVA: 0x9CE4D0
Scaleform::Render::GlyphNode *__fastcall Scaleform::Render::GlyphCache::allocateGlyph(Scaleform::Render::GlyphCache *this, Scaleform::Render::TextMeshProvider *tm, Scaleform::Render::GlyphParam *gp, unsigned int w, unsigned int h)
{
  Scaleform::Render::GlyphQueue *v5; // rsi
  Scaleform::Render::TextMeshProvider *v6; // rdi
  Scaleform::Render::GlyphNode *result; // rax
  Scaleform::Render::GlyphNode *v8; // rbx
  Scaleform::Render::TextNotifier *v9; // rax

  v5 = &this->Queue;
  v6 = tm;
  result = Scaleform::Render::GlyphQueue::AllocateGlyph(&this->Queue, gp, w, h);
  v8 = result;
  if ( result )
  {
    v9 = Scaleform::Render::GlyphQueue::CreateNotifier(v5, result, v6);
    Scaleform::Render::TextMeshProvider::AddNotifier(v6, v9);
    result = v8;
  }
  return result;
}

// File Line: 762
// RVA: 0x9BBAB0
void __fastcall Scaleform::Render::GlyphCache::UnpinAllSlots(Scaleform::Render::GlyphCache *this)
{
  Scaleform::Render::TextMeshProvider *v1; // rax
  Scaleform::Render::GlyphCache *v2; // r10
  _QWORD *v3; // r8
  signed __int64 v4; // r9
  unsigned __int64 *v5; // rdx
  Scaleform::Render::TextMeshProvider *v6; // rax
  _QWORD *v7; // rcx
  signed __int64 v8; // rdx
  signed __int64 v9; // rax

  v1 = this->TextInUse.Root.pNext;
  v2 = this;
  v3 = &this->TextInUse.Root.pPrev;
  v4 = 0i64;
  while ( 1 )
  {
    v5 = &this->RectsToUpdate.Capacity;
    if ( this == (Scaleform::Render::GlyphCache *)-4672i64 )
      v5 = 0i64;
    if ( v1 == (Scaleform::Render::TextMeshProvider *)v5 )
      break;
    v1->Flags &= 0xFFFFFFF9;
    v1 = v1->pNext;
  }
  v6 = this->TextInPin.Root.pNext;
  v7 = &this->TextInPin.Root.pPrev;
  while ( 1 )
  {
    v8 = (signed __int64)(v7 - 1);
    if ( !v7 )
      v8 = 0i64;
    if ( v6 == (Scaleform::Render::TextMeshProvider *)v8 )
      break;
    v6->Flags &= 0xFFFFFFF9;
    v6 = v6->pNext;
  }
  v9 = (signed __int64)(v3 - 1);
  if ( !v3 )
    v9 = 0i64;
  *v3 = v9;
  v3[1] = v9;
  if ( v7 )
    v4 = (signed __int64)(v7 - 1);
  *v7 = v4;
  v7[1] = v4;
  Scaleform::Render::GlyphQueue::UnpinAllSlots(&v2->Queue);
}

// File Line: 792
// RVA: 0x959FB0
void __fastcall Scaleform::Render::GlyphCache::ApplyInUseList(Scaleform::Render::GlyphCache *this)
{
  Scaleform::Render::TextMeshProvider *v1; // rax
  Scaleform::Render::GlyphCache *v2; // r10
  Scaleform::List<Scaleform::Render::TextMeshProvider,Scaleform::Render::TextMeshProvider> *v3; // r9
  signed __int64 v4; // rdx
  Scaleform::Render::TextMeshProvider *v5; // r11
  unsigned __int64 v6; // r8
  Scaleform::Render::GlyphSlot *v7; // rcx

  v1 = this->TextInUse.Root.pNext;
  v2 = this;
  v3 = &this->TextInUse;
  while ( 1 )
  {
    v4 = (signed __int64)(v3 ? &v3[-1].Root.8 : 0i64);
    if ( v1 == (Scaleform::Render::TextMeshProvider *)v4 )
      break;
    v1->Flags &= 0xFFFFFFFD;
    v5 = v1->pNext;
    v6 = 0i64;
    if ( v1->Notifiers.Data.Size )
    {
      do
      {
        v7 = v1->Notifiers.Data.Data[++v6 - 1]->pSlot;
        ++v7->PinCount;
      }
      while ( v6 < v1->Notifiers.Data.Size );
    }
    v1->pPrev = v2->TextInPin.Root.pPrev;
    v1->pNext = (Scaleform::Render::TextMeshProvider *)&v2->TextInUse.Root.8;
    v2->TextInPin.Root.pPrev->pNext = v1;
    v2->TextInPin.Root.pPrev = v1;
    v1->Flags |= 4u;
    v1 = v5;
  }
  if ( v3 )
  {
    v3->Root.pPrev = (Scaleform::Render::TextMeshProvider *)&v3[-1].Root.8;
    v3->Root.pNext = (Scaleform::Render::TextMeshProvider *)&v3[-1].Root.8;
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
  Scaleform::Render::TextMeshProvider *v1; // rbx
  unsigned __int8 v2; // bp
  Scaleform::List<Scaleform::Render::TextMeshProvider,Scaleform::Render::TextMeshProvider> *v3; // rdi
  signed __int64 v4; // rax
  Scaleform::Render::TextMeshProvider *v5; // rsi

  v1 = this->TextInPin.Root.pNext;
  v2 = 0;
  v3 = &this->TextInPin;
  while ( 1 )
  {
    v4 = (signed __int64)(v3 ? &v3[-1].Root.8 : 0i64);
    if ( v1 == (Scaleform::Render::TextMeshProvider *)v4 )
      break;
    v5 = v1->pNext;
    if ( (signed int)Scaleform::Render::TextMeshProvider::GetMeshUseStatus(v1) < 4 )
    {
      v1->Flags &= 0xFFFFFFFB;
      Scaleform::Render::TextMeshProvider::UnpinSlots(v1);
      v1->pPrev->pNext = v1->pNext;
      v1->pNext->pPrev = v1->pPrev;
      v1->pPrev = (Scaleform::Render::TextMeshProvider *)-1i64;
      v1->pNext = (Scaleform::Render::TextMeshProvider *)-1i64;
      v2 = 1;
    }
    v1 = v5;
  }
  return v2;
}

// File Line: 837
// RVA: 0x9E6E70
void __fastcall Scaleform::Render::GlyphCache::getGlyphBounds(Scaleform::Render::GlyphCache *this, Scaleform::Render::VectorGlyphShape *glyphShape, Scaleform::Render::ShapeDataInterface *shapeData)
{
  Scaleform::Render::ShapeDataInterface *v3; // rbx
  Scaleform::Render::VectorGlyphShape *v4; // rdi
  Scaleform::RefCountImplCoreVtbl *v5; // rax
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  Scaleform::RefCountImplCoreVtbl *v9; // rax
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  Scaleform::Render::Rect<float> bounds; // [rsp+28h] [rbp-39h]
  Scaleform::Render::ShapePosInfo pos; // [rsp+38h] [rbp-29h]
  char v15; // [rsp+70h] [rbp+Fh]
  float coord; // [rsp+80h] [rbp+1Fh]
  Scaleform::Render::Matrix2x4<float> trans; // [rsp+98h] [rbp+37h]

  v3 = shapeData;
  v4 = glyphShape;
  if ( glyphShape->Key.HintedVector )
  {
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::Render::ShapeDataInterface *))shapeData->vfptr[1].__vecDelDtor)(shapeData) )
    {
      ((void (__fastcall *)(Scaleform::Render::Font *, _QWORD, Scaleform::Render::Rect<float> *))v4->Key.pFont->pFont->vfptr[7].__vecDelDtor)(
        v4->Key.pFont->pFont,
        v4->Key.GlyphIndex,
        &v4->Bounds);
    }
    else
    {
      v9 = v3->vfptr;
      *(_OWORD *)&trans.M[0][0] = _xmm;
      *(__m128 *)&trans.M[1][0] = _xmm;
      bounds = (Scaleform::Render::Rect<float>)_xmm_f149f2caf149f2ca7149f2ca7149f2ca;
      pos.Pos = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *))v9[6].__vecDelDtor)(v3);
      LODWORD(pos.Sfactor) = (_DWORD)FLOAT_1_0;
      *(_QWORD *)&pos.StartX = 0i64;
      *(_QWORD *)&pos.LastX = 0i64;
      *(_QWORD *)&pos.FillBase = 0i64;
      *(_QWORD *)&pos.NumFillBits = 0i64;
      *(_QWORD *)&pos.Fill0 = 0i64;
      pos.Stroke = 0;
      pos.Initialized = 0;
      while ( ((unsigned int (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *, char *))v3->vfptr[8].__vecDelDtor)(
                v3,
                &pos,
                &coord,
                &v15) )
        Scaleform::Render::ExpandBoundsToPath<Scaleform::Render::Matrix2x4<float>>(v3, &trans, &pos, &coord, &bounds);
      v10 = bounds.y1;
      v4->Bounds.x1 = bounds.x1;
      v11 = bounds.x2;
      v4->Bounds.y1 = v10;
      v12 = bounds.y2;
      v4->Bounds.x2 = v11;
      v4->Bounds.y2 = v12;
    }
  }
  else
  {
    ((void (__fastcall *)(Scaleform::Render::Font *, _QWORD, Scaleform::Render::Rect<float> *))glyphShape->Key.pFont->pFont->vfptr[7].__vecDelDtor)(
      glyphShape->Key.pFont->pFont,
      glyphShape->Key.GlyphIndex,
      &glyphShape->Bounds);
    if ( (v4->Bounds.x2 <= v4->Bounds.x1 || v4->Bounds.y2 <= v4->Bounds.y1)
      && !((unsigned __int8 (__fastcall *)(Scaleform::Render::ShapeDataInterface *))v3->vfptr[1].__vecDelDtor)(v3) )
    {
      v5 = v3->vfptr;
      *(_OWORD *)&trans.M[0][0] = _xmm;
      *(__m128 *)&trans.M[1][0] = _xmm;
      bounds = (Scaleform::Render::Rect<float>)_xmm_f149f2caf149f2ca7149f2ca7149f2ca;
      pos.Pos = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *))v5[6].__vecDelDtor)(v3);
      LODWORD(pos.Sfactor) = (_DWORD)FLOAT_1_0;
      *(_QWORD *)&pos.StartX = 0i64;
      *(_QWORD *)&pos.LastX = 0i64;
      *(_QWORD *)&pos.FillBase = 0i64;
      *(_QWORD *)&pos.NumFillBits = 0i64;
      *(_QWORD *)&pos.Fill0 = 0i64;
      pos.Stroke = 0;
      pos.Initialized = 0;
      while ( ((unsigned int (__fastcall *)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *, char *))v3->vfptr[8].__vecDelDtor)(
                v3,
                &pos,
                &coord,
                &v15) )
        Scaleform::Render::ExpandBoundsToPath<Scaleform::Render::Matrix2x4<float>>(v3, &trans, &pos, &coord, &bounds);
      v6 = bounds.y1;
      v4->Bounds.x1 = bounds.x1;
      v7 = bounds.x2;
      v4->Bounds.y1 = v6;
      v8 = bounds.y2;
      v4->Bounds.x2 = v7;
      v4->Bounds.y2 = v8;
    }
  }
} v6;
      v8 = bounds.y2;
      v4->Bounds.x2 = v7;
      v4->Bounds.y2 = v8;
    }
 

// File Line: 859
// RVA: 0x9E8E60
signed __int64 __fastcall Scaleform::Render::GlyphCache::isOuterContourCW(Scaleform::Render::GlyphCache *this, Scaleform::Render::ShapeDataInterface *shape)
{
  float v2; // xmm8_4
  float v3; // xmm9_4
  Scaleform::Render::ShapeDataInterface *v4; // rbx
  bool v5; // di
  Scaleform::RefCountImplCoreVtbl *v6; // rax
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
  int v22; // [rsp+20h] [rbp-C8h]
  int v23; // [rsp+24h] [rbp-C4h]
  float v24; // [rsp+30h] [rbp-B8h]
  float v25; // [rsp+34h] [rbp-B4h]
  float v26; // [rsp+38h] [rbp-B0h]
  float v27; // [rsp+3Ch] [rbp-ACh]
  int v28; // [rsp+48h] [rbp-A0h]
  __int64 v29; // [rsp+4Ch] [rbp-9Ch]
  __int64 v30; // [rsp+54h] [rbp-94h]
  __int64 v31; // [rsp+5Ch] [rbp-8Ch]
  __int64 v32; // [rsp+64h] [rbp-84h]
  __int64 v33; // [rsp+6Ch] [rbp-7Ch]
  int v34; // [rsp+74h] [rbp-74h]
  int v35; // [rsp+78h] [rbp-70h]
  char v36; // [rsp+7Ch] [rbp-6Ch]
  float vars0; // [rsp+130h] [rbp+48h]
  float retaddr; // [rsp+138h] [rbp+50h]
  float v39; // [rsp+140h] [rbp+58h]

  v2 = FLOAT_1_0e10;
  v3 = FLOAT_N1_0e10;
  v4 = shape;
  v5 = 1;
  v6 = shape->vfptr;
  retaddr = FLOAT_N1_0e10;
  v39 = FLOAT_N1_0e10;
  vars0 = FLOAT_1_0e10;
  v7 = FLOAT_1_0e10;
  v8 = FLOAT_N1_0e10;
  v9 = FLOAT_1_0e10;
  v28 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *))v6[6].__vecDelDtor)(shape);
  v35 = (signed int)FLOAT_1_0;
  v29 = 0i64;
  v30 = 0i64;
  v31 = 0i64;
  v32 = 0i64;
  v33 = 0i64;
  v34 = 0;
  v36 = 0;
  v10 = 1;
  v11 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, int *, float *, int *))v4->vfptr[8].__vecDelDtor)(
          v4,
          &v28,
          &v24,
          &v22);
  if ( !v11 )
    return 1i64;
  do
  {
    if ( !v10 && v11 == 2 )
      break;
    v10 = 0;
    v12 = v4->vfptr;
    if ( v22 == v23 )
    {
      v12[10].__vecDelDtor((Scaleform::RefCountImplCore *)&v4->vfptr, (unsigned int)&v28);
    }
    else
    {
      v13 = v24;
      v14 = v25;
      v15 = 0.0;
      v16 = v24;
      v17 = v25;
      for ( i = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, int *, float *))v12[9].__vecDelDtor)(
                  v4,
                  &v28,
                  &v24);
            i;
            i = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, int *, float *))v4->vfptr[9].__vecDelDtor)(
                  v4,
                  &v28,
                  &v24) )
      {
        if ( v24 < v2 )
          v2 = v24;
        if ( v25 < v7 )
          v7 = v25;
        if ( v24 > v3 )
          v3 = v24;
        if ( v25 > v8 )
          v8 = v25;
        v19 = v25 * v16;
        v20 = v24 * v17;
        v16 = v24;
        v17 = v25;
        v15 = v15 + (float)(v19 - v20);
        if ( i == 2 )
        {
          v16 = v26;
          if ( v26 < v2 )
            v2 = v26;
          v17 = v27;
          if ( v27 < v7 )
            v7 = v27;
          if ( v26 > v3 )
            v3 = v26;
          if ( v27 > v8 )
            v8 = v27;
          v15 = v15 + (float)((float)(v27 * v24) - (float)(v26 * v25));
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
      if ( v2 < v9 || v7 < vars0 || v3 > retaddr || v8 > v39 )
      {
        vars0 = v7;
        retaddr = v3;
        v39 = v8;
        v9 = v2;
        v5 = v15 > 0.0;
      }
    }
    v11 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, int *, float *, int *))v4->vfptr[8].__vecDelDtor)(
            v4,
            &v28,
            &v24,
            &v22);
  }
  while ( v11 );
  return v5;
}*, int *

// File Line: 944
// RVA: 0x9DBA10
void __fastcall Scaleform::Render::GlyphCache::copyAndTransformShape(Scaleform::Render::GlyphCache *this, Scaleform::Render::VectorGlyphShape *glyphShape, Scaleform::Render::ShapeDataInterface *srcShape, bool fauxBold)
{
  bool v4; // di
  Scaleform::Render::ShapeDataInterface *v5; // rsi
  Scaleform::Render::VectorGlyphShape *v6; // rbx
  Scaleform::Render::GlyphCache *v7; // r12
  float v8; // xmm13_4
  float v9; // xmm12_4
  float v10; // xmm9_4
  int v11; // xmm6_4
  float v12; // xmm7_4
  float v13; // xmm10_4
  int v14; // er13
  char v15; // r15
  Scaleform::Render::ShapePathType v16; // ecx
  float v17; // xmm6_4
  float v18; // xmm7_4
  float v19; // xmm8_4
  int v20; // xmm9_4
  int v21; // xmm11_4
  float v22; // xmm1_4
  int v23; // eax
  signed int v24; // er14
  signed int v25; // er15
  float v26; // xmm1_4
  float v27; // xmm0_4
  Scaleform::Render::GlyphShape *v28; // rcx
  int v29; // xmm3_4
  int v30; // ebx
  float v31; // xmm3_4
  int v32; // edi
  float v33; // xmm1_4
  float v34; // xmm2_4
  float v35; // xmm3_4
  float v36; // xmm2_4
  float v37; // xmm3_4
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v38; // r14
  float v39; // xmm6_4
  int v40; // eax
  unsigned __int64 v41; // rdx
  float v42; // xmm13_4
  float v43; // xmm14_4
  float v44; // xmm15_4
  int v45; // xmm6_4
  int v46; // xmm11_4
  char v47; // bl
  int v48; // xmm2_4
  int i; // eax
  float v50; // xmm1_4
  float v51; // xmm0_4
  float v52; // xmm9_4
  float v53; // xmm8_4
  float v54; // xmm1_4
  float v55; // xmm0_4
  float v56; // xmm7_4
  float y3; // xmm6_4
  unsigned __int64 j; // r8
  Scaleform::Render::VertexBasic *v59; // rcx
  Scaleform::Render::VertexPath *v60; // r15
  signed int v61; // edi
  unsigned int v62; // edx
  unsigned __int64 v63; // rdi
  unsigned __int64 v64; // rcx
  __int64 v65; // rdi
  Scaleform::Render::PathBasic *v66; // rsi
  unsigned int v67; // eax
  unsigned int v68; // ebx
  __int64 v69; // rdx
  Scaleform::Render::VertexBasic *v70; // rcx
  __int128 v71; // xmm2
  __int128 v72; // xmm1
  unsigned int v73; // edx
  unsigned __int64 v74; // r12
  unsigned __int64 v75; // rcx
  __int64 v76; // r12
  Scaleform::Render::PathBasic *v77; // rdi
  __int64 v78; // r8
  Scaleform::Render::VertexBasic *v79; // rdx
  Scaleform::Render::GlyphShape *v80; // rax
  float v81; // xmm7_4
  float v82; // xmm8_4
  float v83; // xmm6_4
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v84; // rbx
  unsigned __int64 v85; // rax
  unsigned __int64 v86; // rsi
  unsigned __int64 v87; // r8
  unsigned __int64 v88; // rax
  unsigned __int64 v89; // rsi
  unsigned __int64 v90; // r8
  unsigned __int64 v91; // rax
  unsigned __int64 v92; // rsi
  unsigned __int64 v93; // r8
  int v94; // er15
  float v95; // xmm6_4
  signed int v96; // er14
  unsigned int v97; // esi
  Scaleform::Render::PathBasic *v98; // r13
  __int64 v99; // rdx
  Scaleform::Render::VertexBasic *v100; // rcx
  Scaleform::Render::GlyphShape *v101; // rax
  float v102; // xmm1_4
  int v103; // ebx
  float v104; // xmm1_4
  int v105; // edi
  Scaleform::Render::GlyphShape *v106; // rax
  int v107; // xmm0_4
  int v108; // eax
  int v109; // ecx
  int level[4]; // [rsp+48h] [rbp-80h]
  __int64 v111; // [rsp+58h] [rbp-70h]
  __int64 v112; // [rsp+60h] [rbp-68h]
  int v113; // [rsp+68h] [rbp-60h]
  char v114; // [rsp+6Ch] [rbp-5Ch]
  Scaleform::Render::ShapePosInfo pos; // [rsp+70h] [rbp-58h]
  unsigned int v116; // [rsp+A8h] [rbp-20h]
  int v117; // [rsp+ACh] [rbp-1Ch]
  Scaleform::Render::VertexPath *v118; // [rsp+B0h] [rbp-18h]
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v119; // [rsp+B8h] [rbp-10h]
  float v120; // [rsp+C0h] [rbp-8h]
  int v121; // [rsp+C8h] [rbp+0h]
  __int64 v122; // [rsp+CCh] [rbp+4h]
  __int64 v123; // [rsp+D4h] [rbp+Ch]
  __int64 v124; // [rsp+DCh] [rbp+14h]
  __int64 v125; // [rsp+E4h] [rbp+1Ch]
  __int64 v126; // [rsp+ECh] [rbp+24h]
  int v127; // [rsp+F4h] [rbp+2Ch]
  int v128; // [rsp+F8h] [rbp+30h]
  char v129; // [rsp+FCh] [rbp+34h]
  __int64 v130; // [rsp+100h] [rbp+38h]
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v131; // [rsp+108h] [rbp+40h]
  float v132; // [rsp+110h] [rbp+48h]
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v133; // [rsp+118h] [rbp+50h]
  float v134; // [rsp+120h] [rbp+58h]
  Scaleform::Render::ToleranceParams param; // [rsp+138h] [rbp+70h]
  __int64 v136; // [rsp+188h] [rbp+C0h]
  Scaleform::Render::GlyphCache *v137; // [rsp+278h] [rbp+1B0h]
  Scaleform::Render::VectorGlyphShape *v138; // [rsp+280h] [rbp+1B8h]
  unsigned int v139; // [rsp+288h] [rbp+1C0h]
  char v140; // [rsp+298h] [rbp+1D0h]
  int vars0; // [rsp+2A0h] [rbp+1D8h]
  void *retaddr; // [rsp+2A8h] [rbp+1E0h]
  Scaleform::Render::GlyphCache *v143[4]; // [rsp+2B0h] [rbp+1E8h]

  v143[0] = this;
  v136 = -2i64;
  v4 = fauxBold;
  v5 = srcShape;
  v6 = glyphShape;
  v7 = this;
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::Render::ShapeDataInterface *))srcShape->vfptr[1].__vecDelDtor)(srcShape) )
    return;
  v8 = *(float *)v143;
  param.Epsilon = FLOAT_0_0000099999997;
  v9 = FLOAT_0_001;
  param.IntersectionEpsilon = 0.001;
  *(_OWORD *)&param.FillLowerScale = _xmm;
  *(_OWORD *)&param.StrokeLowerScale = _xmm;
  *(_OWORD *)&param.Scale9LowerScale = _xmm;
  param.MinDet3D = 0.001;
  param.MinScale3D = FLOAT_0_050000001;
  param.CurveRecursionLimit = 12;
  param.CurveTolerance = *(float *)v143 * 0.015625;
  param.CollinearityTolerance = *(float *)v143 * 0.015625;
  *(_OWORD *)&pos.StartY = _xmm;
  *(__m128 *)&pos.StrokeBase = _xmm;
  v10 = 0.0;
  if ( v140 )
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
                                   (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>'::`2'::v)),
                               (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>'::`2'::v);
    *(__m128 *)&pos.StrokeBase = _mm_and_ps(
                                   _mm_add_ps(
                                     _mm_add_ps(
                                       _mm_mul_ps(
                                         _mm_shuffle_ps(*(__m128 *)level, *(__m128 *)level, 85),
                                         *(__m128 *)&pos.StrokeBase),
                                       _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)level, *(__m128 *)level, 0), (__m128)_xmm)),
                                     _mm_and_ps(
                                       *(__m128 *)level,
                                       (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>'::`2'::v)),
                                   (__m128)`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>'::`2'::v);
    v13 = COERCE_FLOAT(_mm_shuffle_ps(*(__m128 *)&pos.StrokeBase, *(__m128 *)&pos.StrokeBase, 255)) - *(float *)&retaddr;
  }
  else
  {
    v13 = *(float *)&pos.Fill0;
  }
  v121 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *))v5->vfptr[6].__vecDelDtor)(v5);
  v14 = 0;
  v130 = 0i64;
  v122 = 0i64;
  v123 = 0i64;
  v124 = 0i64;
  v125 = 0i64;
  v126 = 0i64;
  v127 = 0;
  v128 = 1065353216;
  v129 = 0;
  *(_QWORD *)&pos.Pos = 0i64;
  *(_QWORD *)&pos.StartY = 0i64;
  *(_QWORD *)level = 0i64;
  *(_QWORD *)&level[2] = 0i64;
  v111 = 0i64;
  v112 = 0i64;
  v113 = 1065353216;
  v114 = 0;
  v15 = 1;
  if ( v4 || vars0 )
  {
    LOBYTE(v139) = Scaleform::Render::GlyphCache::isOuterContourCW(v7, v5);
    v38 = (Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *)&v7->mStroker;
    v119.Data = (Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *)&v7->mStroker;
    (*((void (__fastcall **)(Scaleform::Render::Stroker *))&v7->mStroker.vfptr->__vecDelDtor + 1))(&v7->mStroker);
    (*((void (__fastcall **)(Scaleform::Render::VertexPath *))&v7->TmpPath1.vfptr->__vecDelDtor + 1))(&v7->TmpPath1);
    if ( v4 )
      v10 = *(float *)v143 * v7->Param.FauxBoldRatio;
    v39 = FLOAT_0_5;
    v7->mStroker.Width = v10 * 0.5;
    *(_QWORD *)&pos.Pos = &Scaleform::Render::StrokeScaler::`vftable';
    *(_QWORD *)&pos.StartY = (char *)v7 + 7032;
    level[0] = 1065353216;
    *(float *)&level[1] = FLOAT_1000_0;
    *(_QWORD *)&level[2] = 0i64;
    v40 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, int *, int *, unsigned int *))v5->vfptr[8].__vecDelDtor)(
            v5,
            &v121,
            &level[2],
            &pos.Fill1);
    if ( v40 )
    {
      v42 = *(float *)&pos.NumFillBits;
      v43 = *(float *)&pos.StrokeBase;
      v44 = *(float *)&pos.FillBase;
      v45 = pos.LastX;
      v46 = pos.StartY;
      v47 = v139;
      do
      {
        if ( !v15 && v40 == 2 )
          break;
        v15 = 0;
        if ( pos.Fill1 == pos.Stroke )
        {
          v5->vfptr[10].__vecDelDtor((Scaleform::RefCountImplCore *)&v5->vfptr, (unsigned int)&v121);
        }
        else
        {
          *(float *)&v48 = (float)((float)(*(float *)&level[3] * v42) + (float)(v43 * *(float *)&level[2])) + v13;
          *(float *)&level[2] = (float)((float)(*(float *)&level[3] * *(float *)&v45)
                                      + (float)(*(float *)&level[2] * *(float *)&v46))
                              + v44;
          level[3] = v48;
          (*(void (**)(void))(**(_QWORD **)&pos.StartY + 32i64))();
          for ( i = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, int *, int *))v5->vfptr[9].__vecDelDtor)(
                      v5,
                      &v121,
                      &level[2]);
                i;
                i = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, int *, int *))v5->vfptr[9].__vecDelDtor)(
                      v5,
                      &v121,
                      &level[2]) )
          {
            v50 = *(float *)&level[2];
            v51 = *(float *)&level[2] * *(float *)&v46;
            if ( i == 1 )
            {
              *(float *)&level[2] = (float)((float)(*(float *)&level[3] * *(float *)&v45) + v51) + v44;
              *(float *)&level[3] = (float)((float)(v43 * v50) + (float)(*(float *)&level[3] * v42)) + v13;
              (*(void (**)(void))(**(_QWORD **)&pos.StartY + 32i64))();
            }
            else
            {
              v52 = (float)((float)(*(float *)&level[3] * *(float *)&v45) + v51) + v44;
              *(float *)&level[2] = (float)((float)(*(float *)&level[3] * *(float *)&v45) + v51) + v44;
              *(float *)&level[3] = (float)((float)(v43 * v50) + (float)(*(float *)&level[3] * v42)) + v13;
              v53 = *(float *)&level[3];
              v54 = *(float *)&v111;
              v55 = *(float *)&v111 * *(float *)&v46;
              *(float *)&v111 = (float)((float)(*((float *)&v111 + 1) * *(float *)&v45)
                                      + (float)(*(float *)&v111 * *(float *)&v46))
                              + v44;
              v56 = *(float *)&v111;
              *((float *)&v111 + 1) = (float)((float)(v43 * v54) + (float)(*((float *)&v111 + 1) * v42)) + v13;
              y3 = *((float *)&v111 + 1);
              (*(void (__fastcall **)(Scaleform::Render::ShapePosInfo *))(*(_QWORD *)&pos.Pos + 16i64))(&pos);
              (*(void (__fastcall **)(Scaleform::Render::ShapePosInfo *))(*(_QWORD *)&pos.Pos + 24i64))(&pos);
              if ( !Scaleform::Render::TestQuadCollinearity(
                      (Scaleform::Render::TessBase *)&pos,
                      &param,
                      v55,
                      v55,
                      v52,
                      v53,
                      v56,
                      y3) )
                Scaleform::Render::TessellateQuadRecursively(
                  (Scaleform::Render::TessBase *)&pos,
                  &param,
                  (float)(param.CurveTolerance * 0.25) * (float)(param.CurveTolerance * 0.25),
                  v55,
                  v55,
                  v52,
                  v53,
                  v56,
                  y3,
                  0);
              v46 = pos.StartY;
              v45 = pos.LastX;
            }
          }
          (*((void (__fastcall **)(Scaleform::Render::Stroker *))v38->Data.Data + 5))(&v7->mStroker);
          Scaleform::Render::Stroker::CalcEquidistant(
            &v7->mStroker,
            (Scaleform::Render::TessBase *)&v7->TmpPath1.vfptr,
            (Scaleform::Render::StrokerTypes::EquidistantDir)(v47 == 0));
        }
        v40 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, int *, int *, unsigned int *))v5->vfptr[8].__vecDelDtor)(
                v5,
                &v121,
                &level[2],
                &pos.Fill1);
      }
      while ( v40 );
      v9 = FLOAT_0_001;
      v8 = *(float *)v143;
      v39 = FLOAT_0_5;
      v6 = v138;
    }
    for ( j = 0i64; j < v7->TmpPath1.Vertices.Size; ++j )
    {
      v41 = j & 0xF;
      v59 = v7->TmpPath1.Vertices.Pages[j >> 4];
      v59[v41].y = v59[v41].y * v9;
    }
    v60 = &v7->TmpPath1;
    v118 = &v7->TmpPath1;
    v61 = vars0;
    if ( vars0 )
    {
      v60 = &v7->TmpPath2;
      v118 = &v7->TmpPath2;
      (*((void (__fastcall **)(Scaleform::Render::VertexPath *, unsigned __int64, unsigned __int64))&v7->TmpPath2.vfptr->__vecDelDtor
       + 1))(
        &v7->TmpPath2,
        v41,
        j);
      (*((void (__fastcall **)(Scaleform::Render::Stroker *))v38->Data.Data + 1))(&v7->mStroker);
      v7->mStroker.Width = (float)((float)((float)v61 * v7->Param.OutlineRatio) * v8) * v39;
      v7->mStroker.LineJoin = 0;
      v62 = 0;
      v139 = 0;
      if ( v7->TmpPath1.Paths.Size > 0 )
      {
        v63 = 0i64;
        do
        {
          v64 = v63 >> 2;
          v65 = v63 & 3;
          v66 = v7->TmpPath1.Paths.Pages[v64];
          v67 = v66[v65].Count;
          if ( v67 > 2 )
          {
            v68 = 0;
            if ( v67 )
            {
              do
              {
                v69 = ((_BYTE)v68 + LOBYTE(v66[v65].Start)) & 0xF;
                v70 = v7->TmpPath1.Vertices.Pages[(unsigned __int64)(v68 + v66[v65].Start) >> 4];
                v71 = LODWORD(v70[v69].y);
                v72 = LODWORD(v70[v69].x);
                (*((void (__fastcall **)(Scaleform::Render::Stroker *))v38->Data.Data + 4))(&v7->mStroker);
                ++v68;
              }
              while ( v68 < v66[v65].Count );
            }
            (*((void (__fastcall **)(Scaleform::Render::Stroker *))v38->Data.Data + 5))(&v7->mStroker);
            Scaleform::Render::Stroker::GenerateStroke(
              &v7->mStroker,
              (Scaleform::Render::TessBase *)&v7->TmpPath2.vfptr);
            v62 = v139;
          }
          v139 = ++v62;
          v63 = v62;
        }
        while ( v62 < v7->TmpPath1.Paths.Size );
        v6 = v138;
      }
    }
    v73 = 0;
    v116 = 0;
    if ( v60->Paths.Size <= 0 )
    {
LABEL_97:
      Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndShape((Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)&v6->pShape.pObject->vfptr);
      (*((void (__fastcall **)(Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *))v38->Data.Data
       + 1))(v38);
      (*((void (__fastcall **)(Scaleform::Render::VertexPath *))&v7->TmpPath1.vfptr->__vecDelDtor + 1))(&v7->TmpPath1);
      (*((void (**)(void))&v7->TmpPath2.vfptr->__vecDelDtor + 1))();
      Scaleform::Render::LinearHeap::ClearAndRelease(&v7->LHeap1);
      Scaleform::Render::LinearHeap::ClearAndRelease(&v7->LHeap2);
      return;
    }
    v74 = 0i64;
    while ( 1 )
    {
      v75 = v74 >> 2;
      v76 = v74 & 3;
      v77 = v60->Paths.Pages[v75];
      if ( v77[v76].Count > 2 )
        break;
LABEL_95:
      v116 = ++v73;
      v74 = v73;
      if ( v73 >= v60->Paths.Size )
      {
        v38 = v119.Data;
        v7 = v137;
        goto LABEL_97;
      }
    }
    v78 = v77[v76].Start & 0xF;
    v79 = v60->Vertices.Pages[(unsigned __int64)v77[v76].Start >> 4];
    v80 = v6->pShape.pObject;
    v81 = v79[v78].y;
    v82 = v79[v78].x;
    v83 = v80->Multiplier;
    v133.Data = v80->pContainer;
    v84 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)v133.Data;
    v134 = v83;
    Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt15(
      &v133,
      2 - (v14 != 0));
    v85 = v84->Size;
    v86 = v85 + 1;
    if ( v85 + 1 >= v85 )
    {
      if ( v86 <= v84->Policy.Capacity )
        goto LABEL_66;
      v87 = v86 + (v86 >> 2);
    }
    else
    {
      if ( v86 >= v84->Policy.Capacity >> 1 )
        goto LABEL_66;
      v87 = v85 + 1;
    }
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(v84, v84, v87);
LABEL_66:
    v84->Size = v86;
    v84->Data[v86 - 1] = 4;
    v88 = v84->Size;
    v89 = v88 + 1;
    if ( v88 + 1 >= v88 )
    {
      if ( v89 <= v84->Policy.Capacity )
        goto LABEL_72;
      v90 = v89 + (v89 >> 2);
    }
    else
    {
      if ( v89 >= v84->Policy.Capacity >> 1 )
        goto LABEL_72;
      v90 = v88 + 1;
    }
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(v84, v84, v90);
LABEL_72:
    v84->Size = v89;
    v84->Data[v89 - 1] = 0;
    v91 = v84->Size;
    v92 = v91 + 1;
    if ( v91 + 1 >= v91 )
    {
      if ( v92 > v84->Policy.Capacity )
      {
        v93 = v92 + (v92 >> 2);
        goto LABEL_77;
      }
    }
    else if ( v92 < v84->Policy.Capacity >> 1 )
    {
      v93 = v91 + 1;
LABEL_77:
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v84,
        v84,
        v93);
      goto LABEL_78;
    }
LABEL_78:
    v84->Size = v92;
    v84->Data[v92 - 1] = 0;
    v94 = (signed int)(float)(v83 * v82);
    v117 = (signed int)(float)(v83 * v82);
    Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteSInt30(
      &v133,
      v94);
    v95 = v83 * v81;
    v96 = (signed int)v95;
    v139 = (signed int)v95;
    Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteSInt30(
      &v133,
      (signed int)v95);
    v97 = 1;
    if ( v77[v76].Count > 1 )
    {
      v98 = v77;
      do
      {
        v99 = ((_BYTE)v97 + LOBYTE(v98[v76].Start)) & 0xF;
        v100 = v118->Vertices.Pages[(unsigned __int64)(v97 + v98[v76].Start) >> 4];
        v101 = v138->pShape.pObject;
        v102 = v101->Multiplier;
        v131.Data = v101->pContainer;
        v132 = v102;
        v103 = (signed int)(float)(v102 * v100[v99].x) - v94;
        v104 = v102 * v100[v99].y;
        v105 = (signed int)v104 - v96;
        if ( (signed int)v104 == v96 )
        {
          Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteHLine(
            &v131,
            v103);
        }
        else if ( v103 )
        {
          Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteLine(
            &v131,
            v103,
            v105);
        }
        else
        {
          Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteVLine(
            &v131,
            v105);
        }
        v94 += v103;
        v96 = (signed int)v104;
        ++v97;
      }
      while ( v97 < v98[v76].Count );
      v14 = v130;
    }
    v6 = v138;
    v106 = v138->pShape.pObject;
    v107 = LODWORD(v106->Multiplier);
    *(_QWORD *)&pos.StartY = v106->pContainer;
    pos.LastY = v107;
    if ( v94 != v117 || v96 != v139 )
    {
      v108 = v117 - v94;
      v109 = v139 - v96;
      if ( v139 == v96 )
      {
        Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteHLine(
          (Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)&pos.StartY,
          v108);
      }
      else if ( v117 == v94 )
      {
        Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteVLine(
          (Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)&pos.StartY,
          v109);
      }
      else
      {
        Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteLine(
          (Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)&pos.StartY,
          v108,
          v109);
      }
    }
    Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath((Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)&v6->pShape.pObject->vfptr);
    v130 = (unsigned int)++v14;
    v60 = v118;
    v73 = v116;
    goto LABEL_95;
  }
  v16 = ((unsigned int (__fastcall *)(Scaleform::Render::ShapeDataInterface *, int *, int *, unsigned int *))v5->vfptr[8].__vecDelDtor)(
          v5,
          &v121,
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
        v5->vfptr[10].__vecDelDtor((Scaleform::RefCountImplCore *)&v5->vfptr, (unsigned int)&v121);
      }
      else
      {
        v22 = *(float *)&level[2];
        *(float *)&level[2] = (float)((float)(*(float *)&level[3] * *(float *)&v20)
                                    + (float)(*(float *)&level[2] * *(float *)&v21))
                            + v19;
        *(float *)&level[3] = (float)((float)(*(float *)&level[3] * v17) + (float)(v18 * v22)) + v13;
        Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
          (Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)&v6->pShape.pObject->vfptr,
          &pos,
          v16,
          pos.Fill1,
          pos.Stroke,
          LODWORD(pos.Sfactor),
          *(float *)&level[2],
          *(float *)&level[3]);
        v23 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, int *, int *))v5->vfptr[9].__vecDelDtor)(
                v5,
                &v121,
                &level[2]);
        if ( v23 )
        {
          v24 = level[0];
          v25 = pos.LastX;
          do
          {
            v26 = *(float *)&level[2];
            v27 = *(float *)&level[2] * *(float *)&v21;
            v28 = v6->pShape.pObject;
            if ( v23 == 1 )
            {
              *(float *)&level[2] = (float)((float)(*(float *)&level[3] * *(float *)&v20) + v27) + v19;
              *(float *)&v29 = (float)((float)(*(float *)&level[3] * v17) + (float)(v18 * v26)) + v13;
              level[3] = v29;
              v119.Data = v28->pContainer;
              v120 = v28->Multiplier;
              v30 = (signed int)(float)(*(float *)&level[2] * v120) - v25;
              v31 = *(float *)&v29 * v120;
              v32 = (signed int)v31 - v24;
              if ( (signed int)v31 == v24 )
              {
                Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteHLine(
                  &v119,
                  v30);
              }
              else if ( (signed int)(float)(*(float *)&level[2] * v120) == v25 )
              {
                Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteVLine(
                  &v119,
                  v32);
              }
              else
              {
                Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteLine(
                  &v119,
                  v30,
                  v32);
              }
              v25 += v30;
              v24 = (signed int)v31;
            }
            else
            {
              *(float *)&level[2] = (float)((float)(*(float *)&level[3] * *(float *)&v20) + v27) + v19;
              *(float *)&level[3] = (float)((float)(*(float *)&level[3] * v17) + (float)(v18 * v26)) + v13;
              v33 = *(float *)&v111;
              v34 = (float)((float)(*((float *)&v111 + 1) * *(float *)&v20) + (float)(*(float *)&v111 * *(float *)&v21))
                  + v19;
              *(float *)&v111 = v34;
              v35 = (float)((float)(*((float *)&v111 + 1) * v17) + (float)(v18 * v33)) + v13;
              *((float *)&v111 + 1) = v35;
              *(_QWORD *)&pos.StartY = v28->pContainer;
              pos.LastY = LODWORD(v28->Multiplier);
              v36 = v34 * *(float *)&pos.LastY;
              v37 = v35 * *(float *)&pos.LastY;
              Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteQuad(
                (Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)&pos.StartY,
                (signed int)(float)(*(float *)&level[2] * *(float *)&pos.LastY) - v25,
                (signed int)(float)(*(float *)&level[3] * *(float *)&pos.LastY) - v24,
                (signed int)v36 - v25,
                (signed int)v37 - v24);
              v25 = (signed int)v36;
              v24 = (signed int)v37;
            }
            level[0] = v24;
            pos.LastX = v25;
            v23 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, int *, int *))v5->vfptr[9].__vecDelDtor)(
                    v5,
                    &v121,
                    &level[2]);
            v6 = v138;
          }
          while ( v23 );
          v15 = 0;
        }
        Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ClosePath(
          (Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)&v6->pShape.pObject->vfptr,
          &pos);
        Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath((Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)&v6->pShape.pObject->vfptr);
      }
      v16 = ((unsigned int (__fastcall *)(Scaleform::Render::ShapeDataInterface *, int *, int *, unsigned int *))v5->vfptr[8].__vecDelDtor)(
              v5,
              &v121,
              &level[2],
              &pos.Fill1);
    }
    while ( v16 );
  }
  Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndShape((Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)&v6->pShape.pObject->vfptr);
}

// File Line: 1107
// RVA: 0x966A20
Scaleform::Render::VectorGlyphShape *__usercall Scaleform::Render::GlyphCache::CreateGlyphShape@<rax>(Scaleform::Render::GlyphCache *this@<rcx>, Scaleform::Render::GlyphRunData *data@<rdx>, unsigned int glyphIndex@<r8d>, float screenSize@<xmm3>, float a5@<xmm0>, bool fauxBold, bool fauxItalic, unsigned int outline, bool needsVectorShape)
{
  float v9; // xmm6_4
  unsigned int v10; // er12
  Scaleform::Render::GlyphRunData *v11; // rbp
  Scaleform::Render::GlyphCache *v12; // r13
  Scaleform::Render::Font *v13; // r15
  Scaleform::Render::ShapeDataInterface *v14; // rdi
  Scaleform::Render::Rect<float> *v15; // rax
  signed int v16; // esi
  unsigned int v17; // er14
  BOOL v18; // eax
  int v19; // ebx
  __int64 v20; // rax
  Scaleform::Render::FontCacheHandle *v22; // r11
  Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor> >::TableType *v23; // r9
  unsigned __int64 v24; // r8
  signed __int64 v25; // rcx
  unsigned __int64 *v26; // rdx
  unsigned __int64 v27; // rax
  signed __int64 v28; // rbx
  Scaleform::Render::VectorGlyphShape *v29; // rdx
  Scaleform::Render::VectorGlyphShape *v30; // rdx
  float v31; // xmm2_4
  float v32; // xmm1_4
  float v33; // xmm0_4
  unsigned __int64 v34; // rcx
  unsigned __int64 v35; // rax
  Scaleform::Render::VectorGlyphShape *v36; // r8
  unsigned __int64 v37; // rsi
  unsigned int v38; // esi
  unsigned int v39; // ebx
  signed __int64 v40; // rax
  Scaleform::Render::VectorGlyphShape *v41; // rbp
  Scaleform::Render::VectorGlyphShape *v42; // rdx
  Scaleform::Render::VectorGlyphShape *v43; // rax
  Scaleform::Render::VectorGlyphShape *v44; // rax
  Scaleform::Render::VectorGlyphShape *v45; // rsi
  Scaleform::Render::GlyphShape *v46; // rax
  Scaleform::Render::GlyphShape *v47; // rax
  Scaleform::Render::GlyphShape *v48; // rbp
  Scaleform::Render::GlyphShape *v49; // rcx
  __int64 v50; // r14
  _QWORD *v51; // ST48_8
  Scaleform::Render::GlyphRaster *v52; // rcx
  bool v53; // zf
  Scaleform::Render::ShapeDataInterface *v54; // rbp
  float italicOffset; // xmm6_4
  Scaleform::Render::GlyphRunData *v56; // rbx
  unsigned int v57; // edi
  Scaleform::Render::GlyphShape *v58; // rax
  Scaleform::Render::ShapeDataInterface *v59; // rax
  float v60; // xmm2_4
  float v61; // xmm1_4
  float v62; // xmm0_4
  unsigned int v63; // [rsp+40h] [rbp-88h]
  int v64; // [rsp+48h] [rbp-80h]
  Scaleform::Render::VectorGlyphShape *key; // [rsp+50h] [rbp-78h]
  __int64 v66; // [rsp+58h] [rbp-70h]
  __int64 v67; // [rsp+60h] [rbp-68h]
  Scaleform::Render::GlyphShape *v68; // [rsp+68h] [rbp-60h]
  Scaleform::Render::ShapeDataInterface *v69; // [rsp+70h] [rbp-58h]
  Scaleform::Render::GlyphRunData *v70; // [rsp+D8h] [rbp+10h]
  unsigned int v71; // [rsp+E0h] [rbp+18h]

  v70 = data;
  v67 = -2i64;
  v9 = screenSize;
  v10 = glyphIndex;
  v11 = data;
  v12 = this;
  v13 = data->pFont;
  v14 = 0i64;
  *(_QWORD *)&data->VectorSize = 0i64;
  data->pShape = 0i64;
  data->pRaster = 0i64;
  v15 = &data->GlyphBounds;
  key = (Scaleform::Render::VectorGlyphShape *)v15;
  *(_QWORD *)&v15->x1 = 0i64;
  *(_QWORD *)&v15->x2 = 0i64;
  ((void (__fastcall *)(Scaleform::Render::Font *))v13->vfptr[22].__vecDelDtor)(v13);
  v11->NomHeight = a5;
  ((void (__fastcall *)(Scaleform::Render::Font *))v13->vfptr[21].__vecDelDtor)(v13);
  v11->NomWidth = a5;
  if ( (_WORD)v10 == -1 )
    return 0i64;
  if ( !((v13->Flags >> 5) & 1) )
    v9 = 0.0;
  v16 = 0;
  v71 = 0;
  v17 = 0;
  v63 = 0;
  if ( v9 != 0.0 )
  {
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::Render::Font *, _QWORD, _QWORD))v13->vfptr[9].__vecDelDtor)(
           v13,
           v10,
           (unsigned int)(signed int)v9) )
    {
      v17 = (signed int)v9;
    }
    v63 = v17;
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::Render::Font *, _QWORD, _QWORD))v13->vfptr[8].__vecDelDtor)(
           v13,
           v10,
           (unsigned int)(signed int)v9) )
    {
      v16 = (signed int)v9;
    }
    v71 = v16;
  }
  v18 = fauxItalic != 0;
  v19 = v18 | (fauxBold != 0 ? 2 : 0);
  v64 = v18 | (fauxBold != 0 ? 2 : 0);
  if ( !(v18 | (fauxBold != 0 ? 2 : 0)) && !v16 && !v17 && !outline && !needsVectorShape )
  {
    v20 = (__int64)v13->vfptr[14].__vecDelDtor((Scaleform::RefCountImplCore *)&v13->vfptr, v10);
    v11->pShape = (Scaleform::Render::ShapeDataInterface *)v20;
    if ( v20 )
    {
      ((void (__fastcall *)(Scaleform::Render::Font *, _QWORD, Scaleform::Render::VectorGlyphShape *))v13->vfptr[7].__vecDelDtor)(
        v13,
        v10,
        key);
      return 0i64;
    }
  }
  v22 = v11->pFontHandle;
  v23 = v12->VectorGlyphCache.pTable;
  if ( !v23 )
    goto LABEL_88;
  v24 = v23->SizeMask & ((unsigned __int64)v22 ^ (unsigned __int16)v10 ^ (unsigned __int8)v16 ^ (unsigned __int8)v17 ^ (unsigned __int16)outline ^ v19 & 3 ^ ((unsigned __int64)v22 >> 6));
  v25 = v24;
  v26 = &v23->EntryCount + v24 + 2 * (v24 + 1);
  if ( *v26 != -2i64 && v26[1] == v24 )
  {
    while ( 1 )
    {
      if ( v26[1] == v24 )
      {
        v27 = v26[2];
        if ( *(Scaleform::Render::FontCacheHandle **)(v27 + 56) == v22
          && *(_WORD *)(v27 + 64) == (_WORD)v10
          && *(_BYTE *)(v27 + 66) == (_BYTE)v16
          && *(_BYTE *)(v27 + 67) == (_BYTE)v17
          && *(_WORD *)(v27 + 68) == (v19 & 3)
          && *(_WORD *)(v27 + 70) == (_WORD)outline )
        {
          break;
        }
      }
      v25 = *v26;
      if ( *v26 == -1i64 )
        goto LABEL_33;
      v26 = &v23->EntryCount + v25 + 2 * (v25 + 1);
    }
    if ( v25 >= 0 )
    {
      v28 = (signed __int64)v23 + 8 * (v25 + 2 * (v25 + 2));
      if ( v28 )
      {
        v29 = *(Scaleform::Render::VectorGlyphShape **)v28;
        *(_QWORD *)(*(_QWORD *)(*(_QWORD *)v28 + 40i64) + 48i64) = *(_QWORD *)(*(_QWORD *)v28 + 48i64);
        v29->pNext->pPrev = v29->pPrev;
        v29->pPrev = v12->VectorGlyphShapeList.Root.pPrev;
        v29->pNext = (Scaleform::Render::VectorGlyphShape *)&v12->Notifier;
        v12->VectorGlyphShapeList.Root.pPrev->pNext = v29;
        v12->VectorGlyphShapeList.Root.pPrev = v29;
        v11->VectorSize = *(unsigned __int8 *)(*(_QWORD *)v28 + 66i64);
        v11->RasterSize = *(unsigned __int8 *)(*(_QWORD *)v28 + 67i64);
        v11->pShape = *(Scaleform::Render::ShapeDataInterface **)(*(_QWORD *)v28 + 72i64);
        v11->pRaster = *(Scaleform::Render::GlyphRaster **)(*(_QWORD *)v28 + 80i64);
        v30 = *(Scaleform::Render::VectorGlyphShape **)v28;
        v31 = *(float *)(*(_QWORD *)v28 + 108i64);
        v32 = *(float *)(*(_QWORD *)v28 + 104i64);
        v33 = *(float *)(*(_QWORD *)v28 + 100i64);
        v11->GlyphBounds.x1 = *(float *)(*(_QWORD *)v28 + 96i64);
        v11->GlyphBounds.y1 = v33;
        v11->GlyphBounds.x2 = v32;
        v11->GlyphBounds.y2 = v31;
        (*((void (**)(void))&v30->vfptr->__vecDelDtor + 1))();
        return *(Scaleform::Render::VectorGlyphShape **)v28;
      }
    }
  }
LABEL_33:
  if ( v23 )
    v34 = v23->EntryCount;
  else
LABEL_88:
    v34 = 0i64;
  v35 = v12->Param.MaxVectorCacheSize;
  if ( v34 > v35 )
  {
    v36 = v12->VectorGlyphShapeList.Root.pNext;
    key = v12->VectorGlyphShapeList.Root.pNext;
    LODWORD(v37) = 0;
    if ( v23 )
      v37 = v23->EntryCount;
    v38 = v37 - v35;
    if ( v38 > (unsigned int)v35 )
      v38 = v35;
    v39 = 0;
    if ( v38 )
    {
      do
      {
        v40 = (signed __int64)&v12->Notifier;
        if ( v12 == (Scaleform::Render::GlyphCache *)-4744i64 )
          v40 = 0i64;
        if ( v36 == (Scaleform::Render::VectorGlyphShape *)v40 )
          break;
        v41 = v36->pNext;
        if ( !v36->hKeySet.pKeySet
          || v36->hKeySet.pKeySet->Meshes.Root.pNext == (Scaleform::Render::MeshKey *)&v36->hKeySet.pKeySet->Meshes )
        {
          v42 = key;
          key->pPrev->pNext = v36->pNext;
          v36->pNext->pPrev = v42->pPrev;
          Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor>>::RemoveAlt<Scaleform::Render::VectorGlyphShape *>(
            (Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor> > *)&v12->VectorGlyphCache.pTable,
            &key);
        }
        v36 = v41;
        key = v41;
        ++v39;
      }
      while ( v39 < v38 );
      v17 = v63;
      v11 = v70;
    }
  }
  v43 = (Scaleform::Render::VectorGlyphShape *)v12->pHeap->vfptr->Alloc(v12->pHeap, 128ui64, 0i64);
  v66 = (__int64)v43;
  if ( v43 )
  {
    Scaleform::Render::VectorGlyphShape::VectorGlyphShape(v43, v12);
    v45 = v44;
  }
  else
  {
    v45 = 0i64;
  }
  key = v45;
  v45->Key.pFont = v11->pFontHandle;
  v45->Key.GlyphIndex = v10;
  v45->Key.HintedVector = v71;
  v45->Key.HintedRaster = v17;
  v45->Key.Flags = (unsigned __int8)v64;
  v45->Key.Outline = (unsigned __int8)outline;
  v46 = (Scaleform::Render::GlyphShape *)v12->pHeap->vfptr->Alloc(v12->pHeap, 144ui64, 0i64);
  v66 = (__int64)v46;
  if ( v46 )
  {
    Scaleform::Render::GlyphShape::GlyphShape(v46);
    v48 = v47;
  }
  else
  {
    v48 = 0i64;
  }
  v49 = v45->pShape.pObject;
  if ( v49 && !_InterlockedDecrement(&v49->RefCount) && v49 )
    v49->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v49->vfptr, 1u);
  v45->pShape.pObject = v48;
  if ( v17 )
  {
    v50 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v12->pHeap->vfptr->Alloc)(v12->pHeap, 64i64);
    v66 = v50;
    if ( v50 )
    {
      *(_QWORD *)v50 = &Scaleform::RefCountNTSImplCore::`vftable';
      *(_DWORD *)(v50 + 8) = 1;
      *(_QWORD *)v50 = &Scaleform::RefCountNTSImpl::`vftable';
      *(_QWORD *)v50 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,75>::`vftable';
      *(_QWORD *)v50 = &Scaleform::RefCountBaseNTS<Scaleform::Render::GlyphRaster,75>::`vftable';
      *(_QWORD *)v50 = &Scaleform::Render::GlyphRaster::`vftable';
      v51 = (_QWORD *)(v50 + 16);
      v68 = (Scaleform::Render::GlyphShape *)(v50 + 16);
      *v51 = 0i64;
      v51[1] = 0i64;
      v51[2] = 0i64;
      *(_QWORD *)(v50 + 40) = 0i64;
      *(_QWORD *)(v50 + 48) = 0i64;
      *(_DWORD *)(v50 + 56) = 0;
    }
    else
    {
      v50 = 0i64;
    }
    v52 = v45->pRaster.pObject;
    if ( v52 )
    {
      v53 = v52->RefCount-- == 1;
      if ( v53 )
        v52->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v52->vfptr, 1u);
    }
    v45->pRaster.pObject = (Scaleform::Render::GlyphRaster *)v50;
    v17 = v63;
  }
  v54 = 0i64;
  if ( !v71 )
    v54 = (Scaleform::Render::ShapeDataInterface *)v13->vfptr[14].__vecDelDtor(
                                                     (Scaleform::RefCountImplCore *)&v13->vfptr,
                                                     v10);
  italicOffset = v13->Descent;
  if ( v54 )
  {
    ((void (__fastcall *)(Scaleform::Render::Font *, _QWORD, Scaleform::Render::Rect<float> *))v13->vfptr[7].__vecDelDtor)(
      v13,
      v10,
      &v45->Bounds);
    v56 = v70;
    Scaleform::Render::GlyphCache::copyAndTransformShape(
      v12,
      v45,
      v54,
      fauxBold,
      fauxItalic,
      outline,
      italicOffset,
      v70->NomHeight);
LABEL_82:
    v57 = v71;
    goto LABEL_83;
  }
  if ( fauxBold || fauxItalic != fauxBold || outline )
  {
    v58 = (Scaleform::Render::GlyphShape *)v12->pHeap->vfptr->Alloc(v12->pHeap, 144ui64, 0i64);
    v68 = v58;
    if ( v58 )
    {
      Scaleform::Render::GlyphShape::GlyphShape(v58);
      v14 = v59;
    }
    v69 = v14;
    ((void (__fastcall *)(Scaleform::Render::Font *, _QWORD, _QWORD, Scaleform::Render::ShapeDataInterface *))v13->vfptr[15].__vecDelDtor)(
      v13,
      v10,
      v71,
      v14);
    Scaleform::Render::GlyphCache::getGlyphBounds(v12, v45, v14);
    Scaleform::Render::GlyphCache::copyAndTransformShape(
      v12,
      v45,
      v14,
      fauxBold,
      fauxItalic,
      outline,
      italicOffset,
      v70->NomHeight);
    if ( v14 && !_InterlockedDecrement(&v14->RefCount) )
      v14->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v14->vfptr, 1u);
    v56 = v70;
    goto LABEL_82;
  }
  Scaleform::Render::GlyphShape::Clear(v45->pShape.pObject);
  v57 = v71;
  ((void (__fastcall *)(Scaleform::Render::Font *, _QWORD, _QWORD, Scaleform::Render::GlyphShape *))v13->vfptr[15].__vecDelDtor)(
    v13,
    v10,
    v71,
    v45->pShape.pObject);
  Scaleform::Render::GlyphCache::getGlyphBounds(
    v12,
    v45,
    (Scaleform::Render::ShapeDataInterface *)&v45->pShape.pObject->vfptr);
  v56 = v70;
LABEL_83:
  if ( v17 )
  {
    ((void (__fastcall *)(Scaleform::Render::Font *, _QWORD, _QWORD, Scaleform::Render::GlyphRaster *))v13->vfptr[16].__vecDelDtor)(
      v13,
      v10,
      v17,
      v45->pRaster.pObject);
    v45->pRaster.pObject->HintedSize = v17;
  }
  v60 = v45->Bounds.y2;
  v61 = v45->Bounds.x2;
  v62 = v45->Bounds.y1;
  v56->GlyphBounds.x1 = v45->Bounds.x1;
  v56->GlyphBounds.y1 = v62;
  v56->GlyphBounds.x2 = v61;
  v56->GlyphBounds.y2 = v60;
  v56->VectorSize = v57;
  v56->RasterSize = v17;
  v56->pShape = (Scaleform::Render::ShapeDataInterface *)&v45->pShape.pObject->vfptr;
  v56->pRaster = v45->pRaster.pObject;
  v56->HintedNomHeight = v45->pShape.pObject->HintedSize;
  v45->pPrev = v12->VectorGlyphShapeList.Root.pPrev;
  v45->pNext = (Scaleform::Render::VectorGlyphShape *)&v12->Notifier;
  v12->VectorGlyphShapeList.Root.pPrev->pNext = v45;
  v12->VectorGlyphShapeList.Root.pPrev = v45;
  Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor>>::add<Scaleform::Render::VectorGlyphShape *>(
    (Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::Render::VectorGlyphShape::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::VectorGlyphShape>,Scaleform::Render::VectorGlyphShape::PtrHashFunctor> > *)&v12->VectorGlyphCache.pTable,
    &v12->VectorGlyphCache,
    &key,
    (_QWORD)v45->Key.pFont ^ ((_QWORD)v45->Key.pFont >> 6) ^ v45->Key.GlyphIndex ^ (unsigned __int8)v45->Key.HintedVector ^ (unsigned __int8)v45->Key.HintedRaster ^ v45->Key.Flags ^ (unsigned __int64)v45->Key.Outline);
  return v45;
}

// File Line: 1306
// RVA: 0x933E70
int Scaleform::Render::RecursiveBlur<Scaleform::Render::ImgBlurWrapperY,Scaleform::ArrayLH_POD<float,2,Scaleform::ArrayDefaultPolicy>,Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>(...)
{
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v4; // r14
  Scaleform::ArrayLH_POD<float,2,Scaleform::ArrayDefaultPolicy> *v5; // rdi
  Scaleform::Render::ImgBlurWrapperY *v6; // rsi
  __m128 v7; // xmm4
  signed __int64 v8; // r12
  signed int v9; // er13
  float v10; // xmm1_4
  signed int v11; // ecx
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
  signed __int64 v32; // r10
  signed __int64 v33; // r8
  signed int v34; // er11
  signed __int64 v35; // rbp
  __int128 v36; // xmm5
  __int128 v37; // xmm4
  __int128 v38; // xmm3
  signed __int64 v39; // rcx
  int v40; // er9
  signed __int64 v41; // rbx
  signed __int64 v42; // r10
  unsigned __int64 v43; // rdx
  float v44; // xmm2_4
  signed __int64 v45; // rdx
  int v46; // ecx
  __int128 v47; // xmm2
  signed __int64 v48; // r9
  signed __int64 v49; // rcx
  unsigned __int64 v50; // rdx
  __int128 v51; // xmm1
  signed __int64 v52; // rcx
  signed __int64 v53; // rdx
  __int128 v54; // xmm1
  float v55; // xmm3_4
  float v56; // xmm4_4
  float v57; // xmm5_4
  signed __int64 v58; // rdx
  float v59; // xmm2_4
  float v60; // xmm2_4
  char *v61; // rdx
  int v62; // er9
  char *v63; // rcx
  char v64; // al

  v4 = buf;
  v5 = sum;
  v6 = img;
  v7 = (__m128)radius;
  if ( *(float *)&radius < 0.62 )
    v7 = (__m128)LODWORD(FLOAT_0_62);
  v8 = img->H;
  v9 = img->W;
  v10 = v7.m128_f32[0];
  v11 = (signed int)v7.m128_f32[0];
  if ( (signed int)v7.m128_f32[0] != 0x80000000 && (float)v11 != v7.m128_f32[0] )
    v10 = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v7, v7)) & 1 ^ 1) + v11);
  v12 = v7.m128_f32[0] * 0.5;
  v13 = (signed int)v10 + 3;
  if ( v12 >= 2.5 )
  {
    v15 = (float)(v12 * 0.98711002) - 0.96329999;
  }
  else
  {
    v14 = (__m128)(unsigned int)FLOAT_1_0;
    v14.m128_f32[0] = 1.0 - (float)(v12 * 0.26890999);
    v15 = 3.97156 - (float)(COERCE_FLOAT(_mm_sqrt_ps(v14)) * 4.1455402);
  }
  v16 = (signed int)v8 + 2 * v13;
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
  Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    (Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)v4,
    v16);
  v32 = 0i64;
  v33 = v13;
  v34 = 0;
  if ( v9 > 0 )
  {
    v35 = v8 - 1 + 2i64 * v13;
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
          LODWORD(v5->Data.Data[v39 - 4]) = v32;
          LODWORD(v5->Data.Data[v39 - 3]) = v32;
          LODWORD(v5->Data.Data[v39 - 2]) = v32;
          LODWORD(v5->Data.Data[v39 - 1]) = v32;
        }
        while ( v39 < v33 - 3 );
      }
      for ( ; v39 < v33; LODWORD(v5->Data.Data[v39 - 1]) = v32 )
        ++v39;
      v40 = v32;
      v41 = v32;
      if ( v8 >= 4 )
      {
        v42 = v33;
        v43 = ((unsigned __int64)(v8 - 4) >> 2) + 1;
        v41 = 4 * v43;
        do
        {
          v44 = (float)((float)((float)((float)(unsigned __int8)v6->Img[v6->Sx + v34 + v6->Pitch * (v40 + v6->Sy)] * v30)
                              + (float)(*(float *)&v36 * v28))
                      + (float)(*(float *)&v37 * v29))
              + (float)(*(float *)&v38 * v31);
          v5->Data.Data[v42] = v44;
          *(float *)&v38 = (float)((float)((float)((float)(unsigned __int8)v6->Img[v6->Sx
                                                                                 + v34
                                                                                 + v6->Pitch * (v40 + v6->Sy + 1)]
                                                 * v30)
                                         + (float)(v44 * v28))
                                 + (float)(*(float *)&v36 * v29))
                         + (float)(*(float *)&v37 * v31);
          LODWORD(v5->Data.Data[v42 + 1]) = v38;
          v37 = COERCE_UNSIGNED_INT((float)(unsigned __int8)v6->Img[v6->Sx + v34 + v6->Pitch * (v40 + v6->Sy + 2)]);
          *(float *)&v37 = (float)((float)((float)(*(float *)&v37 * v30) + (float)(*(float *)&v38 * v28))
                                 + (float)(v44 * v29))
                         + (float)(*(float *)&v36 * v31);
          LODWORD(v5->Data.Data[v42 + 2]) = v37;
          v36 = COERCE_UNSIGNED_INT((float)(unsigned __int8)v6->Img[v6->Sx + v34 + v6->Pitch * (v40 + v6->Sy + 3)]);
          *(float *)&v36 = (float)((float)((float)(*(float *)&v36 * v30) + (float)(*(float *)&v37 * v28))
                                 + (float)(*(float *)&v38 * v29))
                         + (float)(v44 * v31);
          v42 += 4i64;
          v40 += 4;
          LODWORD(v5->Data.Data[v42 - 1]) = v36;
          --v43;
        }
        while ( v43 );
        v32 = 0i64;
      }
      if ( v41 < v8 )
      {
        v45 = v33 + v41;
        v32 = v8 - v41;
        do
        {
          v46 = v40 + v6->Sy;
          ++v45;
          ++v40;
          v47 = COERCE_UNSIGNED_INT((float)(unsigned __int8)v6->Img[v6->Sx + v34 + v6->Pitch * v46]);
          *(float *)&v47 = (float)((float)((float)(*(float *)&v47 * v30) + (float)(*(float *)&v36 * v28))
                                 + (float)(*(float *)&v37 * v29))
                         + (float)(*(float *)&v38 * v31);
          LODWORD(v38) = v37;
          v37 = v36;
          LODWORD(v5->Data.Data[v45 - 1]) = v47;
          v36 = v47;
          --v32;
        }
        while ( v32 );
      }
      v48 = v32;
      if ( v33 >= 4 )
      {
        v49 = v8 + v33;
        v50 = ((unsigned __int64)(v33 - 4) >> 2) + 1;
        v48 = 4 * v50;
        do
        {
          v51 = v37;
          v49 += 4i64;
          *(float *)&v51 = (float)((float)(*(float *)&v37 * v29) + (float)(*(float *)&v36 * v28))
                         + (float)(*(float *)&v38 * v31);
          v38 = v36;
          LODWORD(v5->Data.Data[v49 - 4]) = v51;
          *(float *)&v38 = (float)((float)(*(float *)&v36 * v29) + (float)(*(float *)&v51 * v28))
                         + (float)(*(float *)&v37 * v31);
          v37 = v51;
          LODWORD(v5->Data.Data[v49 - 3]) = v38;
          *(float *)&v37 = (float)((float)(*(float *)&v51 * v29) + (float)(*(float *)&v38 * v28))
                         + (float)(*(float *)&v36 * v31);
          v36 = v38;
          LODWORD(v5->Data.Data[v49 - 2]) = v37;
          *(float *)&v36 = (float)((float)(*(float *)&v38 * v29) + (float)(*(float *)&v37 * v28))
                         + (float)(*(float *)&v51 * v31);
          LODWORD(v5->Data.Data[v49 - 1]) = v36;
          --v50;
        }
        while ( v50 );
      }
      if ( v48 < v33 )
      {
        v52 = v48 + v8 + v33;
        v53 = v33 - v48;
        do
        {
          v54 = v37;
          ++v52;
          *(float *)&v54 = (float)((float)(*(float *)&v37 * v29) + (float)(*(float *)&v36 * v28))
                         + (float)(*(float *)&v38 * v31);
          LODWORD(v38) = v37;
          v37 = v36;
          LODWORD(v5->Data.Data[v52 - 1]) = v54;
          v36 = v54;
          --v53;
        }
        while ( v53 );
      }
      v55 = 0.0;
      v56 = 0.0;
      v57 = 0.0;
      v58 = v8 - 1 + 2 * v33;
      if ( v35 >= v33 )
      {
        if ( v8 + 2 * v33 - v33 >= 4 )
        {
          do
          {
            v58 -= 4i64;
            v59 = (float)((float)((float)(v30 * v5->Data.Data[v58 + 4]) + (float)(v57 * v28)) + (float)(v56 * v29))
                + (float)(v55 * v31);
            v4->Data.Data[v58 + 4] = (signed int)(float)(v59 + 0.5);
            v55 = (float)((float)((float)(v30 * v5->Data.Data[v58 + 3]) + (float)(v59 * v28)) + (float)(v57 * v29))
                + (float)(v56 * v31);
            v4->Data.Data[v58 + 3] = (signed int)(float)(v55 + 0.5);
            v56 = (float)((float)((float)(v30 * v5->Data.Data[v58 + 2]) + (float)(v55 * v28)) + (float)(v59 * v29))
                + (float)(v57 * v31);
            v4->Data.Data[v58 + 2] = (signed int)(float)(v56 + 0.5);
            v57 = (float)((float)((float)(v30 * v5->Data.Data[v58 + 1]) + (float)(v56 * v28)) + (float)(v55 * v29))
                + (float)(v59 * v31);
            v4->Data.Data[v58 + 1] = (signed int)(float)(v57 + 0.5);
          }
          while ( v58 >= v33 + 3 );
        }
        for ( ; v58 >= v33; v4->Data.Data[v58 + 1] = (signed int)(float)(v60 + 0.5) )
        {
          v60 = (float)((float)((float)(v30 * v5->Data.Data[--v58 + 1]) + (float)(v57 * v28)) + (float)(v56 * v29))
              + (float)(v55 * v31);
          v55 = v56;
          v56 = v57;
          v57 = v60;
        }
      }
      v61 = &v4->Data.Data[v33];
      v62 = v8;
      v63 = &v6->Img[v6->Sx + v34 + (unsigned __int64)(v6->Pitch * v6->Sy)];
      do
      {
        v64 = *v61++;
        *v63 = v64;
        v63 += v6->Pitch;
        --v62;
      }
      while ( v62 );
      ++v34;
    }
    while ( v34 < v9 );
  }
}

// File Line: 1381
// RVA: 0x9EFAB0
void __fastcall Scaleform::Render::GlyphCache::recursiveBlur(Scaleform::Render::GlyphCache *this, char *img, unsigned int pitch, unsigned int sx, unsigned int sy, unsigned int w, unsigned int h, float rx, float ry)
{
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v9; // rbx
  Scaleform::ArrayLH_POD<float,2,Scaleform::ArrayDefaultPolicy> *v10; // rdi
  unsigned int v11; // er13
  unsigned int v12; // er12
  char *v13; // r15
  Scaleform::Render::ImgBlurWrapperY imga; // [rsp+20h] [rbp-48h]

  v9 = &this->BlurStack;
  v10 = &this->BlurSum;
  v11 = sx;
  v12 = pitch;
  imga.Pitch = pitch;
  imga.Sx = sx;
  v13 = img;
  imga.Img = img;
  imga.Sy = sy;
  imga.W = w;
  imga.H = h;
  Scaleform::Render::RecursiveBlur<Scaleform::Render::ImgBlurWrapperX,Scaleform::ArrayLH_POD<float,2,Scaleform::ArrayDefaultPolicy>,Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>(
    (Scaleform::Render::ImgBlurWrapperX *)&imga,
    rx,
    &this->BlurSum,
    &this->BlurStack);
  imga.Img = v13;
  imga.Pitch = v12;
  imga.Sx = v11;
  imga.Sy = sy;
  imga.W = w;
  imga.H = h;
  Scaleform::Render::RecursiveBlur<Scaleform::Render::ImgBlurWrapperY,Scaleform::ArrayLH_POD<float,2,Scaleform::ArrayDefaultPolicy>,Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>(
    &imga,
    ry,
    v10,
    v9);
}

// File Line: 1395
// RVA: 0x9F39F0
void __fastcall Scaleform::Render::GlyphCache::strengthenImage(Scaleform::Render::GlyphCache *this, char *img, unsigned int pitch, unsigned int sx, unsigned int sy, unsigned int w, unsigned int h, float ratio, int bias)
{
  unsigned int v9; // edi
  __int64 v10; // rbp
  __int64 v11; // rbx
  unsigned int v12; // er11
  unsigned int v13; // er9
  char *v14; // rcx
  unsigned int v15; // eax
  __int64 v16; // r8
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  __int64 v21; // r8
  int v22; // eax

  v9 = pitch;
  if ( ratio != 1.0 && h )
  {
    v10 = sx;
    v11 = h;
    v12 = sy * pitch;
    do
    {
      v13 = 0;
      v14 = &img[v10 + v12];
      if ( (signed int)w >= 4 )
      {
        v15 = ((w - 4) >> 2) + 1;
        v16 = v15;
        v13 = 4 * v15;
        do
        {
          v17 = bias + (signed int)(float)((float)((float)((unsigned __int8)*v14 - bias) * ratio) + 0.5);
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
          v18 = bias + (signed int)(float)((float)((float)((unsigned __int8)v14[1] - bias) * ratio) + 0.5);
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
          v19 = bias + (signed int)(float)((float)((float)((unsigned __int8)v14[2] - bias) * ratio) + 0.5);
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
          v20 = bias + (signed int)(float)((float)((float)((unsigned __int8)v14[3] - bias) * ratio) + 0.5);
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
          v22 = bias + (signed int)(float)((float)((float)((unsigned __int8)*v14 - bias) * ratio) + 0.5);
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
      v12 += v9;
      --v11;
    }
    while ( v11 );
  }
}

// File Line: 1431
// RVA: 0x9C9470
void __fastcall Scaleform::Render::GlyphCache::addShapeToRasterizer(Scaleform::Render::GlyphCache *this, Scaleform::Render::ShapeDataInterface *shape, float scaleX, float scaleY)
{
  Scaleform::Render::GlyphCache *v4; // r13
  Scaleform::Render::ShapeDataInterface *v5; // r14
  Scaleform::RefCountImplCoreVtbl *v6; // rax
  char v7; // r15
  int i; // eax
  signed __int64 v9; // rsi
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  int j; // eax
  Scaleform::Render::Rasterizer *v15; // rcx
  int v16; // er8
  int v17; // edx
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // [rsp+30h] [rbp-B8h]
  float v23; // [rsp+34h] [rbp-B4h]
  float v24; // [rsp+38h] [rbp-B0h]
  float y3; // [rsp+3Ch] [rbp-ACh]
  int v26; // [rsp+48h] [rbp-A0h]
  __int64 v27; // [rsp+4Ch] [rbp-9Ch]
  __int64 v28; // [rsp+54h] [rbp-94h]
  __int64 v29; // [rsp+5Ch] [rbp-8Ch]
  __int64 v30; // [rsp+64h] [rbp-84h]
  __int64 v31; // [rsp+6Ch] [rbp-7Ch]
  int v32; // [rsp+74h] [rbp-74h]
  Scaleform::Render::ToleranceParams param; // [rsp+78h] [rbp-70h]

  v4 = this;
  v5 = shape;
  if ( !((unsigned __int8 (__fastcall *)(Scaleform::Render::ShapeDataInterface *))shape->vfptr[1].__vecDelDtor)(shape) )
  {
    v6 = v5->vfptr;
    param.CurveRecursionLimit = 12;
    *(_OWORD *)&param.Epsilon = _xmm;
    *(_OWORD *)&param.FillLowerScale = _xmm;
    *(_OWORD *)&param.StrokeLowerScale = _xmm;
    param.MinDet3D = FLOAT_0_001;
    *(_OWORD *)&param.Scale9LowerScale = _xmm;
    param.MinScale3D = FLOAT_0_050000001;
    v26 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *))v6[6].__vecDelDtor)(v5);
    LODWORD(param.Epsilon) = (_DWORD)FLOAT_1_0;
    v27 = 0i64;
    v28 = 0i64;
    v29 = 0i64;
    v30 = 0i64;
    v31 = 0i64;
    v32 = 0;
    LOBYTE(param.CurveTolerance) = 0;
    v7 = 1;
    for ( i = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, int *, float *, char *))v5->vfptr[8].__vecDelDtor)(
                v5,
                &v26,
                &v22,
                (char *)&v30 + 4);
          i;
          i = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, int *, float *, char *))v5->vfptr[8].__vecDelDtor)(
                v5,
                &v26,
                &v22,
                (char *)&v30 + 4) )
    {
      if ( !v7 && i == 2 )
        break;
      v7 = 0;
      if ( HIDWORD(v30) == (_DWORD)v31 )
      {
        v5->vfptr[10].__vecDelDtor((Scaleform::RefCountImplCore *)&v5->vfptr, (unsigned int)&v26);
      }
      else
      {
        v9 = (signed __int64)&v4->Ras;
        v10 = v22 * scaleX;
        v11 = v23 * scaleY;
        *(float *)(v9 + 712) = v22 * scaleX;
        *(float *)(v9 + 716) = v11;
        v22 = v10;
        v12 = v10 * 256.0;
        v23 = v11;
        v13 = v11 * 256.0;
        *(_DWORD *)(v9 + 704) = (signed int)v12;
        *(_DWORD *)(v9 + 696) = (signed int)v12;
        *(_DWORD *)(v9 + 708) = (signed int)v13;
        *(_DWORD *)(v9 + 700) = (signed int)v13;
        for ( j = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, int *, float *))v5->vfptr[9].__vecDelDtor)(
                    v5,
                    &v26,
                    &v22);
              j;
              j = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, int *, float *))v5->vfptr[9].__vecDelDtor)(
                    v5,
                    &v26,
                    &v22) )
        {
          v15 = &v4->Ras;
          if ( j == 1 )
          {
            v16 = v4->Ras.LastY;
            v17 = v4->Ras.LastX;
            v18 = v22 * scaleX;
            v19 = v23 * scaleY;
            v22 = v18;
            v4->Ras.LastXf = v18;
            v23 = v19;
            v20 = v18 * 256.0;
            v4->Ras.LastYf = v19;
            v21 = v19 * 256.0;
            Scaleform::Render::Rasterizer::line(v15, v17, v16, (signed int)v20, (signed int)v21);
            v4->Ras.LastX = (signed int)v20;
            v4->Ras.LastY = (signed int)v21;
          }
          else
          {
            v22 = v22 * scaleX;
            v23 = v23 * scaleY;
            y3 = y3 * scaleY;
            v24 = v24 * scaleX;
            Scaleform::Render::TessellateQuadCurve(
              (Scaleform::Render::TessBase *)&v15->vfptr,
              &param,
              v22,
              v23,
              y3,
              v24,
              y3);
          }
        }
        (*(void (__fastcall **)(Scaleform::Render::Rasterizer *))(*(_QWORD *)v9 + 40i64))(&v4->Ras);
      }
    }
  }
}

// File Line: 1487
// RVA: 0x9C8E00
void __fastcall Scaleform::Render::GlyphCache::addShapeAutoFit(Scaleform::Render::GlyphCache *this, Scaleform::Render::ShapeDataInterface *shape, unsigned int nomHeight, int lowerCaseTop, int upperCaseTop, float screenSize, float stretch)
{
  Scaleform::Render::GlyphFitter *v7; // rsi
  signed __int64 v8; // r14
  int v9; // er15
  signed int v10; // edi
  Scaleform::Render::ShapeDataInterface *v11; // rbx
  signed int v12; // eax
  __m128i v13; // xmm2
  Scaleform::RefCountImplCoreVtbl *v14; // rax
  float v15; // xmm6_4
  Scaleform::RefCountImplCoreVtbl *v16; // rax
  char v17; // di
  int i; // eax
  int j; // eax
  signed int v20; // er8
  int v21; // ecx
  int v22; // eax
  __int64 v23; // rdx
  Scaleform::Render::GlyphCache *v24; // rbx
  float v25; // xmm9_4
  unsigned __int64 v26; // r15
  unsigned __int64 v27; // rcx
  __int64 v28; // r15
  Scaleform::Render::GlyphFitter::ContourType *v29; // r12
  int v30; // edx
  int v31; // ecx
  __int16 v32; // r8
  __int16 v33; // cx
  int v34; // er9
  __int64 v35; // rdx
  unsigned int v36; // er13
  float v37; // xmm1_4
  float v38; // xmm0_4
  float v39; // xmm0_4
  signed int v40; // eax
  int v41; // edx
  int v42; // ecx
  __int16 v43; // r8
  __int16 v44; // dx
  int v45; // er9
  int v46; // ecx
  int v47; // eax
  int v48; // er8
  __m128i v49; // xmm1
  signed int v50; // eax
  int v51; // edx
  int v52; // ebx
  float v53; // xmm0_4
  float v54; // xmm0_4
  float v55; // [rsp+30h] [rbp-D0h]
  float v56; // [rsp+34h] [rbp-CCh]
  float x3; // [rsp+38h] [rbp-C8h]
  float y3; // [rsp+3Ch] [rbp-C4h]
  __int64 v59; // [rsp+48h] [rbp-B8h]
  int v60; // [rsp+50h] [rbp-B0h]
  __int64 v61; // [rsp+54h] [rbp-ACh]
  __int64 v62; // [rsp+5Ch] [rbp-A4h]
  __int64 v63; // [rsp+64h] [rbp-9Ch]
  __int64 v64; // [rsp+6Ch] [rbp-94h]
  __int64 v65; // [rsp+74h] [rbp-8Ch]
  int v66; // [rsp+7Ch] [rbp-84h]
  int v67; // [rsp+80h] [rbp-80h]
  char v68; // [rsp+84h] [rbp-7Ch]
  int v69; // [rsp+88h] [rbp-78h]
  int v70; // [rsp+8Ch] [rbp-74h]
  Scaleform::Render::ToleranceParams param; // [rsp+A0h] [rbp-60h]
  Scaleform::Render::GlyphCache *v72; // [rsp+160h] [rbp+60h]
  Scaleform::Render::GlyphFitter::VertexType v73; // [rsp+168h] [rbp+68h]
  Scaleform::Render::GlyphFitter::VertexType v74; // [rsp+168h] [rbp+68h]

  v72 = this;
  v7 = &this->Fitter;
  v8 = (signed __int64)this;
  v9 = lowerCaseTop;
  v10 = nomHeight;
  v11 = shape;
  (*((void (__fastcall **)(Scaleform::Render::GlyphFitter *))&this->Fitter.vfptr->__vecDelDtor + 1))(&this->Fitter);
  if ( !((unsigned __int8 (__fastcall *)(Scaleform::Render::ShapeDataInterface *))v11->vfptr[1].__vecDelDtor)(v11) )
  {
    param.IntersectionEpsilon = 0.001;
    param.MinDet3D = 0.001;
    param.CurveRecursionLimit = 12;
    *(_OWORD *)&param.FillLowerScale = _xmm;
    v12 = (signed int)(float)(screenSize * 64.0);
    *(_OWORD *)&param.Scale9LowerScale = _xmm;
    if ( v12 > 2048 )
      v12 = 2048;
    *(_DWORD *)(v8 + 5056) = v12;
    v13 = _mm_cvtsi32_si128(v12);
    v14 = v11->vfptr;
    v13.m128i_i32[0] = (unsigned __int128)_mm_cvtepi32_ps(v13);
    v15 = *(float *)v13.m128i_i32 / (float)v10;
    param.Epsilon = FLOAT_0_0000099999997;
    *(_OWORD *)&param.StrokeLowerScale = _xmm;
    param.MinScale3D = FLOAT_0_050000001;
    param.CurveTolerance = (float)(*(float *)v13.m128i_i32 * 0.5) / screenSize;
    param.CollinearityTolerance = (float)(*(float *)v13.m128i_i32 * 0.5) / screenSize;
    LODWORD(v8) = 0;
    v60 = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *))v14[6].__vecDelDtor)(v11);
    v16 = v11->vfptr;
    v59 = 0i64;
    v61 = 0i64;
    v62 = 0i64;
    v63 = 0i64;
    v64 = 0i64;
    v65 = 0i64;
    v66 = 0;
    v67 = 1065353216;
    v68 = 0;
    v17 = 1;
    for ( i = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, int *, float *, int *))v16[8].__vecDelDtor)(
                v11,
                &v60,
                &v55,
                &v69);
          i;
          i = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, int *, float *, int *))v11->vfptr[8].__vecDelDtor)(
                v11,
                &v60,
                &v55,
                &v69) )
    {
      if ( !v17 && i == 2 )
        break;
      v17 = 0;
      if ( v69 == v70 )
      {
        v11->vfptr[10].__vecDelDtor((Scaleform::RefCountImplCore *)&v11->vfptr, (unsigned int)&v60);
      }
      else
      {
        v55 = v55 * v15;
        LODWORD(v56) = COERCE_UNSIGNED_INT(v56 * v15) ^ _xmm[0];
        Scaleform::Render::GlyphFitter::MoveTo(v7, v55, v56);
        for ( j = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, int *, float *))v11->vfptr[9].__vecDelDtor)(
                    v11,
                    &v60,
                    &v55);
              j;
              j = ((__int64 (__fastcall *)(Scaleform::Render::ShapeDataInterface *, int *, float *))v11->vfptr[9].__vecDelDtor)(
                    v11,
                    &v60,
                    &v55) )
        {
          if ( j == 1 )
          {
            v55 = v55 * v15;
            LODWORD(v56) = COERCE_UNSIGNED_INT(v56 * v15) ^ _xmm[0];
            Scaleform::Render::GlyphFitter::LineTo(v7, v55, v56);
          }
          else
          {
            v55 = v55 * v15;
            LODWORD(v56) = COERCE_UNSIGNED_INT(v56 * v15) ^ _xmm[0];
            LODWORD(y3) = COERCE_UNSIGNED_INT(y3 * v15) ^ _xmm[0];
            x3 = x3 * v15;
            Scaleform::Render::TessellateQuadCurve(
              (Scaleform::Render::TessBase *)&v7->vfptr,
              &param,
              v55,
              v56,
              y3,
              x3,
              y3);
          }
        }
        v7->vfptr->ClosePath((Scaleform::Render::TessBase *)&v7->vfptr);
      }
    }
    v20 = (signed int)screenSize;
    v7->UnitsPerPixelX = 1;
    if ( (signed int)screenSize )
      v21 = v7->NominalFontHeight / v20;
    else
      v21 = 1;
    v22 = v7->NominalFontHeight;
    v7->UnitsPerPixelY = v21;
    v23 = (unsigned int)(v22 >> 31);
    LODWORD(v23) = v22 % v21;
    v7->SnappedHeight = v21 * (v22 / v21);
    if ( v20 )
    {
      Scaleform::Render::GlyphFitter::removeDuplicateClosures(v7);
      Scaleform::Render::GlyphFitter::computeBounds(v7);
      if ( v7->MaxY > v7->MinY )
      {
        Scaleform::Render::GlyphFitter::detectEvents(v7, FitY);
        Scaleform::Render::GlyphFitter::computeLerpRamp(
          v7,
          FitY,
          v7->UnitsPerPixelY,
          v7->MinY + (v7->MaxY - v7->MinY) / 3,
          (signed int)(float)((float)v9 * v15),
          (signed int)(float)((float)upperCaseTop * v15));
      }
    }
    v24 = v72;
    v25 = 1.0 / (float)v72->Fitter.UnitsPerPixelY;
    if ( v72->Fitter.Contours.Size > 0 )
    {
      v26 = 0i64;
      do
      {
        v27 = v26;
        v28 = v26 & 3;
        v29 = v24->Fitter.Contours.Pages[v27 >> 2];
        if ( v29[v28].NumVertices > 2 )
        {
          v30 = v7->MinY;
          v73 = v24->Fitter.Vertices.Pages[(unsigned __int64)v29[v28].StartVertex >> 4][v29[v28].StartVertex & 0xF];
          v31 = v73.y - v30;
          if ( v31 < 0 || v31 >= SLODWORD(v7->LerpRampY.Size) )
            v32 = *(_DWORD *)&v24->Fitter.Vertices.Pages[(unsigned __int64)v29[v28].StartVertex >> 4][v29[v28].StartVertex & 0xF] >> 16;
          else
            v32 = v30 + v7->LerpRampY.Array[v31];
          v33 = (__int16)v24->Fitter.Vertices.Pages[(unsigned __int64)v29[v28].StartVertex >> 4][v29[v28].StartVertex & 0xF];
          v34 = v7->MinX;
          v35 = (unsigned int)(v73.x - v34);
          if ( v73.x - v34 >= 0 && (signed int)v35 < SLODWORD(v7->LerpRampX.Size) )
            v33 = v34 + v7->LerpRampX.Array[(signed int)v35];
          v8 = (signed __int64)&v24->Ras;
          v36 = 1;
          v37 = (float)-v32 * v25;
          *(float *)(v8 + 716) = v37;
          v38 = (float)((float)v33 * v25) * stretch;
          *(float *)(v8 + 712) = v38;
          v39 = v38 * 256.0;
          *(_DWORD *)(v8 + 704) = (signed int)v39;
          *(_DWORD *)(v8 + 696) = (signed int)v39;
          v40 = (signed int)(float)(v37 * 256.0);
          *(_DWORD *)(v8 + 708) = v40;
          for ( *(_DWORD *)(v8 + 700) = v40; v36 < v29[v28].NumVertices; *(_DWORD *)(v8 + 704) = (signed int)v54 )
          {
            v41 = v7->MinY;
            v74 = v24->Fitter.Vertices.Pages[(unsigned __int64)(v36 + v29[v28].StartVertex) >> 4][((_BYTE)v36
                                                                                                 + LOBYTE(v29[v28].StartVertex)) & 0xF];
            v42 = v74.y - v41;
            if ( v42 < 0 || v42 >= SLODWORD(v7->LerpRampY.Size) )
              v43 = *(_DWORD *)&v24->Fitter.Vertices.Pages[(unsigned __int64)(v36 + v29[v28].StartVertex) >> 4][((_BYTE)v36 + LOBYTE(v29[v28].StartVertex)) & 0xF] >> 16;
            else
              v43 = v41 + v7->LerpRampY.Array[v42];
            v44 = (__int16)v24->Fitter.Vertices.Pages[(unsigned __int64)(v36 + v29[v28].StartVertex) >> 4][((_BYTE)v36 + LOBYTE(v29[v28].StartVertex)) & 0xF];
            v45 = v7->MinX;
            v46 = v74.x - v45;
            if ( v46 >= 0 && v46 < SLODWORD(v7->LerpRampX.Size) )
              v44 = v45 + v7->LerpRampX.Array[v46];
            v47 = v43;
            v48 = *(_DWORD *)(v8 + 708);
            v49 = _mm_cvtsi32_si128(-v47);
            v50 = v44;
            v51 = *(_DWORD *)(v8 + 704);
            *(float *)v49.m128i_i32 = COERCE_FLOAT(_mm_cvtepi32_ps(v49)) * v25;
            *(_DWORD *)(v8 + 716) = v49.m128i_i32[0];
            v52 = (signed int)(float)(*(float *)v49.m128i_i32 * 256.0);
            v53 = (float)((float)v50 * v25) * stretch;
            *(float *)(v8 + 712) = v53;
            v54 = v53 * 256.0;
            Scaleform::Render::Rasterizer::line((Scaleform::Render::Rasterizer *)v8, v51, v48, (signed int)v54, v52);
            *(_DWORD *)(v8 + 708) = v52;
            v24 = v72;
            ++v36;
          }
          (*(void (__fastcall **)(signed __int64, __int64))(*(_QWORD *)v8 + 40i64))(v8, v35);
          LODWORD(v8) = v59;
        }
        v8 = (unsigned int)(v8 + 1);
        v26 = (unsigned int)v8;
        v59 = v8;
      }
      while ( (unsigned int)v8 < v24->Fitter.Contours.Size );
    }
    (*((void (__fastcall **)(Scaleform::Render::GlyphFitter *, __int64))&v7->vfptr->__vecDelDtor + 1))(v7, v23);
  }
}

// File Line: 1602
// RVA: 0x980A90
int Scaleform::Render::GlyphCache::GetCachedFontSize(...)
{
  Scaleform::Render::GlyphCache *v4; // r8
  signed int v5; // edx
  __int64 v6; // rcx
  signed int v7; // eax
  signed int v8; // ecx
  float v9; // xmm1_4

  v4 = this;
  if ( !exactFit )
  {
    if ( gp->Flags & 1 )
    {
      *(float *)&screenSize = (float)(*(float *)&screenSize * 4.0) + 0.5;
      v8 = (signed int)*(float *)&screenSize;
      if ( (signed int)*(float *)&screenSize != 0x80000000 && (float)v8 != *(float *)&screenSize )
        *(float *)&screenSize = (float)(v8
                                      - (_mm_movemask_ps(_mm_unpacklo_ps((__m128)screenSize, (__m128)screenSize)) & 1));
      *(float *)&screenSize = *(float *)&screenSize * 0.25;
    }
    else
    {
      v5 = (signed int)*(float *)&screenSize;
      if ( (signed int)*(float *)&screenSize != 0x80000000 && (float)v5 != *(float *)&screenSize )
        *(float *)&screenSize = (float)(v5
                                      - (_mm_movemask_ps(_mm_unpacklo_ps((__m128)screenSize, (__m128)screenSize)) & 1));
      v6 = ((unsigned int)((signed int)*(float *)&screenSize + 3) >> 2) + (signed int)*(float *)&screenSize;
      v7 = 255;
      if ( (unsigned int)v6 <= 0xFF )
        v7 = FontSizeRamp[(unsigned __int8)v4->FontSizeMap[v6] + 1];
      *(float *)&screenSize = (float)v7;
    }
  }
  v9 = (float)(v4->MaxSlotHeight - 2 * v4->SlotPadding);
  if ( *(float *)&screenSize <= (float)(v9 * v4->Param.MaxRasterScale) && *(float *)&screenSize > v9 )
    *(float *)&screenSize = (float)(v4->MaxSlotHeight - 2 * v4->SlotPadding);
  return *(float *)&screenSize;
}

// File Line: 1629
// RVA: 0x980B80
int Scaleform::Render::GlyphCache::GetCachedShadowSize(...)
{
  Scaleform::Render::GlyphCache *v3; // rdx
  float result; // xmm0_4
  signed int v5; // ecx
  signed int v6; // eax
  int v7; // eax

  v3 = this;
  if ( ras )
    return (float)(signed int)ras->HintedSize;
  v5 = (signed int)*(float *)&screenSize;
  if ( (signed int)*(float *)&screenSize != 0x80000000 && (float)v5 != *(float *)&screenSize )
    *(float *)&screenSize = (float)(v5 - (_mm_movemask_ps(_mm_unpacklo_ps((__m128)screenSize, (__m128)screenSize)) & 1));
  v6 = 255;
  if ( (unsigned int)(signed int)*(float *)&screenSize <= 0xFF )
    v6 = FontSizeRamp[(unsigned __int8)v3->FontSizeMap[*(float *)&screenSize] + 1];
  result = (float)v6;
  v7 = v3->MaxSlotHeight - 2 * v3->SlotPadding;
  if ( result > (float)v7 )
    result = (float)v7;
  return result;
}

// File Line: 1639
// RVA: 0x9E7450
Scaleform::Render::GlyphNode *__fastcall Scaleform::Render::GlyphCache::getPrerasterizedGlyph(Scaleform::Render::GlyphCache *this, Scaleform::Render::GlyphRunData *data, Scaleform::Render::TextMeshProvider *tm, Scaleform::Render::GlyphParam *gp)
{
  Scaleform::Render::GlyphRaster *v4; // rsi
  Scaleform::Render::GlyphCache *v5; // rdi
  Scaleform::Render::GlyphNode *result; // rax
  unsigned int v7; // ebp
  int v8; // ebx
  int v9; // er12
  int v10; // ecx
  unsigned int v11; // er15
  unsigned int v12; // er14
  Scaleform::Render::GlyphNode *v13; // rax
  Scaleform::Render::GlyphNode *v14; // r15
  Scaleform::Render::TextNotifier *v15; // rax
  char *v16; // rcx
  unsigned int v17; // ebx
  bool v18; // zf
  int v19; // [rsp+60h] [rbp+8h]
  Scaleform::Render::TextMeshProvider *tma; // [rsp+70h] [rbp+18h]
  Scaleform::Render::GlyphParam *gpa; // [rsp+78h] [rbp+20h]

  gpa = gp;
  tma = tm;
  v4 = data->pRaster;
  v5 = this;
  if ( v4->Height + 2 * this->SlotPadding < this->MaxSlotHeight
    || ((unsigned __int8 (*)(void))data->pShape->vfptr[1].__vecDelDtor)() )
  {
    v7 = v5->SlotPadding;
    v8 = -(v4->OriginX + v7);
    v9 = -(v4->OriginY + v7);
    v10 = 2 * v5->SlotPadding;
    v11 = v10 + v4->Width + 1;
    v12 = v4->Height + v7 + v7 + 1;
    v19 = v10 + v4->Width + 1;
    if ( v12 > v5->MaxSlotHeight )
    {
      v12 = v5->MaxSlotHeight;
      if ( v5->RasterTooBigWarning )
      {
        Scaleform::Render::GlyphCache::LogWarning(
          v5,
          "Warning: Raster glyph is too big - increase GlyphCacheParams.MaxSlotHeight");
        v5->RasterTooBigWarning = 0;
      }
    }
    v13 = Scaleform::Render::GlyphQueue::AllocateGlyph(&v5->Queue, gpa, v11, v12);
    v14 = v13;
    if ( v13 )
    {
      v15 = Scaleform::Render::GlyphQueue::CreateNotifier(&v5->Queue, v13, tma);
      Scaleform::Render::TextMeshProvider::AddNotifier(tma, v15);
      v14->Origin.x = 16 * v8;
      v14->Scale = 1.0;
      v14->Origin.y = 16 * v9;
      Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        (Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)&v5->RasterData,
        v19 * v12);
      v16 = v5->RasterData.Data.Data;
      v5->RasterPitch = v19;
      memset(v16, 0, v19 * v12);
      v17 = 0;
      if ( v4->Height )
      {
        do
        {
          if ( v17 + v7 >= v12 )
            break;
          memmove(
            &v5->RasterData.Data.Data[v7 + v5->RasterPitch * (v17 + v7)],
            &v4->Raster.Data.Data[v17 * v4->Width],
            v4->Width);
          ++v17;
        }
        while ( v17 < v4->Height );
      }
      Scaleform::Render::GlyphCache::updateTextureGlyph(v5, v14);
      ++v5->RasterizationCount;
      result = v14;
    }
    else
    {
      v18 = v5->RasterCacheWarning == 0;
      v5->Result = 5;
      if ( !v18 )
      {
        Scaleform::Render::GlyphCache::LogWarning(
          v5,
          "Warning: Increase raster glyph cache capacity - see GlyphCacheParams");
        v5->RasterCacheWarning = 0;
      }
      result = 0i64;
    }
  }
  else
  {
    v5->Result = 3;
    result = 0i64;
  }
  return result;
}

// File Line: 1707
// RVA: 0x9E2CC0
void __fastcall Scaleform::Render::GlyphCache::filterScanline(Scaleform::Render::GlyphCache *this, char *sl, unsigned int w)
{
  unsigned int v3; // ebx
  Scaleform::Render::GlyphCache *v4; // r14
  char *v5; // rsi
  unsigned int v6; // er11
  char *v7; // rax
  __int64 v8; // rcx
  char v9; // r10
  char v10; // dl
  char Dst; // [rsp+20h] [rbp-108h]
  char v12; // [rsp+21h] [rbp-107h]

  v3 = w;
  v4 = this;
  v5 = sl;
  if ( w > 0x100 )
    v3 = 256;
  memset(&Dst, 0, v3);
  if ( v3 > 4 )
  {
    v6 = 4;
    v7 = &v12;
    do
    {
      v8 = (unsigned __int8)v7[v5 - &v12 + 2];
      ++v6;
      ++v7;
      v9 = v4->ScanlineFilter.Tertiary[v8];
      v10 = v4->ScanlineFilter.Secondary[v8];
      *v7 += v4->ScanlineFilter.Primary[v8];
      *(v7 - 2) += v9;
      *(v7 - 1) += v10;
      v7[1] += v10;
      v7[2] += v9;
    }
    while ( v6 < v3 );
  }
  memmove(v5, &Dst, v3);
}

// File Line: 1724
// RVA: 0x9A3AB0
Scaleform::Render::GlyphNode *__fastcall Scaleform::Render::GlyphCache::RasterizeGlyph(Scaleform::Render::GlyphCache *this, Scaleform::Render::GlyphRunData *data, Scaleform::Render::TextMeshProvider *tm, Scaleform::Render::GlyphParam *gp)
{
  Scaleform::Render::GlyphParam *v4; // rsi
  Scaleform::Render::GlyphRunData *v5; // rbx
  Scaleform::Render::GlyphCache *v6; // rdi
  Scaleform::Render::GlyphNode *result; // rax
  int upperCaseTop; // ebp
  int v9; // er12
  bool v10; // r14
  float stretch; // xmm7_4
  Scaleform::Render::Font *v12; // rbp
  unsigned __int16 v13; // ax
  Scaleform::Render::Font *v14; // rbp
  unsigned __int16 v15; // ax
  signed int v16; // eax
  float v17; // xmm0_4
  __m128 v18; // xmm6
  __m128 v19; // xmm2
  signed int v20; // ecx
  __m128 v21; // xmm1
  signed int v22; // ecx
  Scaleform::Render::ShapeDataInterface *v23; // rdx
  __int64 v24; // r14
  int v25; // ebx
  int v26; // ebp
  int v27; // er13
  int v28; // er12
  unsigned int v29; // er12
  unsigned int v30; // ebp
  Scaleform::Render::GlyphNode *v31; // rax
  Scaleform::Render::GlyphNode *v32; // rsi
  char *v33; // rcx
  bool v34; // r13
  unsigned int v35; // ebx
  char *v36; // rsi
  Scaleform::Render::TessBaseVtbl *v37; // rax
  Scaleform::Render::GlyphNode *v38; // [rsp+B0h] [rbp+8h]
  Scaleform::Render::TextMeshProvider *tma; // [rsp+C0h] [rbp+18h]

  tma = tm;
  v4 = gp;
  v5 = data;
  v6 = this;
  if ( this->MaxNumTextures )
  {
    if ( data->RasterSize )
    {
      result = Scaleform::Render::GlyphCache::getPrerasterizedGlyph(this, data, tm, gp);
    }
    else if ( data->pShape )
    {
      upperCaseTop = 0;
      v9 = 0;
      v10 = this->Param.UseAutoFit && (LOBYTE(gp->Flags) >> 1) & 1;
      if ( gp->Flags & 4 )
        stretch = FLOAT_2_5;
      else
        stretch = *(float *)&FLOAT_1_0;
      if ( v10 )
      {
        v12 = gp->pFont->pFont;
        if ( !v12->LowerCaseTop )
          Scaleform::Render::Font::calcLowerUpperTop(gp->pFont->pFont, this);
        v13 = v12->LowerCaseTop;
        if ( (signed __int16)v13 <= 0 )
          v13 = 0;
        v9 = v13;
        v14 = v4->pFont->pFont;
        if ( !v14->UpperCaseTop )
          Scaleform::Render::Font::calcLowerUpperTop(v4->pFont->pFont, v6);
        v15 = v14->UpperCaseTop;
        if ( (signed __int16)v15 <= 0 )
          v15 = 0;
        upperCaseTop = v15;
        if ( !v9 || !v15 )
          v10 = 0;
      }
      v16 = v5->HintedNomHeight;
      v17 = v5->NomHeight;
      if ( v16 )
      {
        v10 = 0;
        v17 = (float)v16;
      }
      v18 = (__m128)COERCE_UNSIGNED_INT((float)v4->FontSize);
      v18.m128_f32[0] = (float)(v18.m128_f32[0] * 0.0625) / v17;
      v19 = v18;
      v19.m128_f32[0] = v18.m128_f32[0] * v5->GlyphBounds.y1;
      v20 = (signed int)v19.m128_f32[0];
      if ( (signed int)v19.m128_f32[0] != 0x80000000 && (float)v20 != v19.m128_f32[0] )
        v19.m128_f32[0] = (float)(v20 - (_mm_movemask_ps(_mm_unpacklo_ps(v19, v19)) & 1));
      v21 = v18;
      v21.m128_f32[0] = v18.m128_f32[0] * v5->GlyphBounds.y2;
      v22 = (signed int)v21.m128_f32[0];
      if ( (signed int)v21.m128_f32[0] != 0x80000000 && (float)v22 != v21.m128_f32[0] )
        v21.m128_f32[0] = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v21, v21)) & 1 ^ 1) + v22);
      if ( v19.m128_f32[0] >= v21.m128_f32[0] )
      {
        v19.m128_i32[0] = 0;
        v21.m128_i32[0] = 0;
      }
      if ( (signed int)(float)(v21.m128_f32[0] - v19.m128_f32[0]) + 2 * v6->SlotPadding < v6->MaxSlotHeight )
      {
        (*((void (__fastcall **)(Scaleform::Render::Rasterizer *))&v6->Ras.vfptr->__vecDelDtor + 1))(&v6->Ras);
        v23 = v5->pShape;
        if ( v10 )
          Scaleform::Render::GlyphCache::addShapeAutoFit(
            v6,
            v23,
            (signed int)v5->NomHeight,
            v9,
            upperCaseTop,
            (float)v4->FontSize * 0.0625,
            stretch);
        else
          Scaleform::Render::GlyphCache::addShapeToRasterizer(v6, v23, v18.m128_f32[0] * stretch, v18.m128_f32[0]);
        v24 = (signed int)v6->SlotPadding;
        v25 = 0;
        v26 = 0;
        v27 = 0;
        v28 = 0;
        if ( Scaleform::Render::Rasterizer::SortCells(&v6->Ras) )
        {
          v25 = v6->Ras.MinX - v24;
          v26 = v24 + v6->Ras.MaxX;
          v27 = v6->Ras.MinY - v24;
          v28 = v24 + v6->Ras.MaxY;
        }
        v29 = v28 - v27 + 1;
        v30 = v26 - v25 + 1;
        if ( v29 > v6->MaxSlotHeight )
          v29 = v6->MaxSlotHeight;
        v31 = Scaleform::Render::GlyphCache::allocateGlyph(v6, tma, v4, v30, v29);
        v32 = v31;
        v38 = v31;
        if ( v31 )
        {
          v31->Scale = 1.0;
          v31->Origin.x = 16 * v25;
          v31->Origin.y = 16 * v27;
          Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Resize(
            (Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)&v6->RasterData,
            v30 * v29);
          v33 = v6->RasterData.Data.Data;
          v6->RasterPitch = v30;
          memset(v33, 0, v30 * v29);
          if ( 1.0 != v6->Ras.Gamma1 )
          {
            Scaleform::Render::Rasterizer::setGamma(&v6->Ras, 0, 1.0);
            v6->Ras.Gamma1 = 1.0;
          }
          v34 = v30 >= 5 && stretch > 1.0;
          v35 = 0;
          if ( v6->Ras.SortedYs.Size )
          {
            do
            {
              if ( v35 + (unsigned int)v24 >= v29 )
                break;
              v36 = &v6->RasterData.Data.Data[v6->RasterPitch * (v35 + (unsigned int)v24)];
              Scaleform::Render::Rasterizer::SweepScanline(&v6->Ras, v35, &v36[v24], 1u, 0);
              if ( v34 )
                Scaleform::Render::GlyphCache::filterScanline(v6, v36, v30);
              ++v35;
            }
            while ( v35 < v6->Ras.SortedYs.Size );
            v32 = v38;
          }
          Scaleform::Render::GlyphCache::updateTextureGlyph(v6, v32);
          v37 = v6->Ras.vfptr;
          ++v6->RasterizationCount;
          (*((void (__fastcall **)(Scaleform::Render::Rasterizer *))&v37->__vecDelDtor + 1))(&v6->Ras);
          result = v32;
        }
        else
        {
          v6->Result = 5;
          Scaleform::Render::GlyphCache::cacheFullWarning(v6);
          result = 0i64;
        }
      }
      else
      {
        v6->Result = 3;
        result = 0i64;
      }
    }
    else
    {
      this->Result = 2;
      result = 0i64;
    }
  }
  else
  {
    this->Result = 4;
    result = 0i64;
  }
  return result;
}

// File Line: 1865
// RVA: 0x9DE590
Scaleform::Render::GlyphNode *__fastcall Scaleform::Render::GlyphCache::createShadowFromRaster(Scaleform::Render::GlyphCache *this, Scaleform::Render::GlyphRunData *data, Scaleform::Render::TextMeshProvider *tm, Scaleform::Render::GlyphParam *gp, float screenSize, Scaleform::Render::GlyphRaster *ras)
{
  float v6; // xmm0_4
  unsigned int v7; // er8
  unsigned int v8; // edx
  Scaleform::Render::GlyphRaster *v9; // r13
  Scaleform::Render::GlyphCache *v10; // rdi
  Scaleform::Render::GlyphParam *v11; // r10
  float v12; // xmm2_4
  __m128i v13; // xmm1
  __m128i v14; // xmm7
  signed int v15; // eax
  signed int v16; // er9
  __m128 ry; // xmm6
  __m128 rx; // xmm7
  float v19; // xmm1_4
  float v20; // xmm3_4
  float v21; // xmm1_4
  signed int v22; // ecx
  signed int v23; // er14
  float v24; // xmm1_4
  signed int v25; // ecx
  int v26; // er14
  int v27; // ebx
  unsigned int w; // er12
  signed int v29; // eax
  int h; // ebp
  __m128 v31; // xmm9
  __m128 v32; // xmm1
  signed int v33; // ecx
  signed int v34; // er15
  __m128 v35; // xmm8
  __m128 v36; // xmm1
  signed int v37; // ecx
  signed int v38; // esi
  Scaleform::Render::GlyphNode *v39; // rax
  Scaleform::Render::TextNotifier *v40; // rax
  int v41; // ecx
  signed __int64 v42; // r14
  size_t v43; // rax
  Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v44; // r15
  char *v45; // rcx
  unsigned __int64 v46; // rbx
  unsigned int v47; // esi
  unsigned int v48; // ebp
  Scaleform::Render::GlyphParam *v49; // rsi
  int v50; // er13
  unsigned __int64 i; // rdx
  float v52; // xmm0_4
  char *v53; // r8
  char *v54; // rdx
  unsigned __int64 j; // r9
  __int16 v56; // cx
  __int16 v57; // ax
  Scaleform::Render::GlyphNode *result; // rax
  bool v59; // zf
  signed int v60; // [rsp+60h] [rbp-C8h]
  int dstWidth; // [rsp+68h] [rbp-C0h]
  Scaleform::Render::GlyphNode *node; // [rsp+70h] [rbp-B8h]
  size_t Size; // [rsp+78h] [rbp-B0h]
  Scaleform::Render::GlyphCache *v64; // [rsp+130h] [rbp+8h]
  int v65; // [rsp+138h] [rbp+10h]
  Scaleform::Render::TextMeshProvider *tma; // [rsp+140h] [rbp+18h]
  Scaleform::Render::GlyphParam *v67; // [rsp+148h] [rbp+20h]
  unsigned int screenSizea; // [rsp+150h] [rbp+28h]
  int rasa; // [rsp+158h] [rbp+30h]

  v67 = gp;
  tma = tm;
  v64 = this;
  v6 = data->HeightRatio;
  v7 = this->MaxSlotHeight;
  v8 = this->SlotPadding;
  v9 = ras;
  v10 = this;
  v11 = gp;
  v12 = *(float *)&FLOAT_1_0;
  v13 = _mm_cvtsi32_si128(gp->FontSize);
  v14 = _mm_cvtsi32_si128(gp->BlurX);
  v15 = gp->BlurY;
  v16 = ras->Height;
  *(float *)v13.m128i_i32 = (float)(COERCE_FLOAT(_mm_cvtepi32_ps(v13)) * 0.0625) / screenSize;
  rx = _mm_cvtepi32_ps(v14);
  ry = (__m128)COERCE_UNSIGNED_INT((float)v15);
  ry.m128_f32[0] = (float)((float)(ry.m128_f32[0] * 0.0625) * *(float *)v13.m128i_i32) * v6;
  rx.m128_f32[0] = (float)((float)(rx.m128_f32[0] * 0.0625) * *(float *)v13.m128i_i32) * v6;
  v19 = (float)((float)(signed int)v7 * this->ShadowQuality) - (float)(signed int)(2 * v8);
  v20 = (float)(ry.m128_f32[0] * 2.0) + (float)v16;
  if ( v20 >= v19 )
  {
    v12 = v19 / v20;
    rx.m128_f32[0] = rx.m128_f32[0] * (float)(v19 / v20);
    ry.m128_f32[0] = ry.m128_f32[0] * (float)(v19 / v20);
  }
  v21 = rx.m128_f32[0];
  v22 = (signed int)rx.m128_f32[0];
  if ( (signed int)rx.m128_f32[0] != 0x80000000 && (float)v22 != rx.m128_f32[0] )
    v21 = (float)((_mm_movemask_ps(_mm_unpacklo_ps(rx, rx)) & 1 ^ 1) + v22);
  v23 = (signed int)v21;
  v24 = ry.m128_f32[0];
  v25 = (signed int)ry.m128_f32[0];
  v26 = v8 + v23;
  v65 = v26;
  if ( (signed int)ry.m128_f32[0] != 0x80000000 && (float)v25 != ry.m128_f32[0] )
    v24 = (float)((_mm_movemask_ps(_mm_unpacklo_ps(ry, ry)) & 1 ^ 1) + v25);
  v31 = 0i64;
  v27 = v8 + (signed int)v24;
  w = ras->Width + 1 + 2 * v26;
  v29 = ras->Width + 1 + 2 * v26;
  h = v16 + 1 + 2 * v27;
  rasa = v8 + (signed int)v24;
  screenSizea = v16 + 1 + 2 * v27;
  v31.m128_f32[0] = (float)v29;
  v32 = v31;
  v32.m128_f32[0] = (float)v29 * v12;
  v33 = (signed int)v32.m128_f32[0];
  if ( (signed int)v32.m128_f32[0] != 0x80000000 && (float)v33 != v32.m128_f32[0] )
    v32.m128_f32[0] = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v32, v32)) & 1 ^ 1) + v33);
  v34 = (signed int)v32.m128_f32[0];
  v35 = 0i64;
  v35.m128_f32[0] = (float)h;
  dstWidth = (signed int)v32.m128_f32[0];
  v36 = v35;
  v36.m128_f32[0] = (float)h * v12;
  v37 = (signed int)v36.m128_f32[0];
  if ( (signed int)v36.m128_f32[0] != 0x80000000 && (float)v37 != v36.m128_f32[0] )
    v36.m128_f32[0] = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v36, v36)) & 1 ^ 1) + v37);
  v38 = (signed int)v36.m128_f32[0];
  if ( (signed int)v36.m128_f32[0] > v7 )
    v38 = v7;
  v60 = v38;
  v39 = Scaleform::Render::GlyphQueue::AllocateGlyph(&v10->Queue, v11, v34, v38);
  node = v39;
  if ( v39 )
  {
    v40 = Scaleform::Render::GlyphQueue::CreateNotifier(&v10->Queue, v39, tma);
    Scaleform::Render::TextMeshProvider::AddNotifier(tma, v40);
    v41 = v26 + v9->OriginX;
    v42 = (signed __int64)&v10->RasterDataSrc;
    node->Origin.x = (signed int)(float)((float)((float)(-16 * v41) * (float)v34) / v31.m128_f32[0]);
    node->Origin.y = (signed int)(float)((float)((float)(-16 * (v27 + v9->OriginY)) * (float)v38) / v35.m128_f32[0]);
    node->Scale = (float)((float)(v35.m128_f32[0] / (float)v38) + (float)(v31.m128_f32[0] / (float)v34)) * 0.5;
    Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      (Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)&v10->RasterDataSrc,
      w * h);
    v43 = (unsigned int)(v34 * v38);
    v44 = (Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)&v10->RasterData;
    Size = v43;
    Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      (Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)&v10->RasterData,
      (unsigned int)v43);
    v45 = v10->RasterDataSrc.Data.Data;
    v10->RasterPitch = dstWidth;
    memset(v45, 0, w * h);
    v46 = 0i64;
    if ( w > 1 && (unsigned int)h > 1 )
    {
      v47 = 0;
      if ( v9->Height > 0 )
      {
        v48 = v65 + rasa * w;
        do
        {
          if ( v47 + rasa >= screenSizea )
            break;
          memmove((void *)(*(_QWORD *)v42 + v48), &v9->Raster.Data.Data[v47++ * v9->Width], v9->Width);
          v48 += w;
        }
        while ( v47 < v9->Height );
        v10 = v64;
        h = screenSizea;
        v44 = (Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)&v64->RasterData;
      }
      v49 = v67;
      v50 = 0;
      if ( (LOBYTE(v67->Flags) >> 5) & 1 )
      {
        Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Resize(
          (Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)&v10->KnockOutCopy,
          *(_QWORD *)(v42 + 8));
        for ( i = 0i64;
              i < v10->KnockOutCopy.Data.Size;
              v10->KnockOutCopy.Data.Data[i - 1] = *(_BYTE *)(i + *(_QWORD *)v42 - 1) )
        {
          ++i;
        }
        v49 = v67;
      }
      if ( rx.m128_f32[0] > 0.0 || ry.m128_f32[0] > 0.0 )
      {
        Scaleform::Render::GlyphCache::recursiveBlur(v10, *(char **)v42, w, 0, 0, w, h, rx.m128_f32[0], ry.m128_f32[0]);
        v50 = 8;
      }
      v52 = (float)v49->BlurStrength * 0.0625;
      if ( v52 <= 1.0 )
        v50 = 0;
      Scaleform::Render::GlyphCache::strengthenImage(v10, *(char **)v42, w, 0, 0, w, h, v52, v50);
      if ( (LOBYTE(v49->Flags) >> 5) & 1 )
      {
        v53 = v10->KnockOutCopy.Data.Data;
        v54 = *(char **)v42;
        for ( j = 0i64; j < v10->KnockOutCopy.Data.Size; *(v54 - 1) = (unsigned __int16)(v56 * v57 + 255) >> 8 )
        {
          ++j;
          v56 = 255 - (unsigned __int8)*v53;
          v57 = (unsigned __int8)*v54;
          ++v53;
          ++v54;
        }
      }
      v38 = v60;
    }
    if ( h != v38 || w != dstWidth )
    {
      memset(v44->Data, 0, Size);
      if ( dstWidth > 0 && v38 > 0 && (signed int)w > 0 && h > 0 )
        Scaleform::Render::ImageResizeFilter2x2_void____cdecl___unsigned_char_____ptr64_unsigned_char_const_____ptr64_unsigned_char_const_____ptr64_unsigned_char_const_____ptr64_unsigned_char_const_____ptr64_int_int__(
          (char *)v44->Data,
          dstWidth,
          v38,
          dstWidth,
          1,
          *(const char **)v42,
          w,
          h,
          w,
          1,
          Scaleform::Render::PixelFilterBilinearGray8);
    }
    else
    {
      Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        v44,
        *(_QWORD *)(v42 + 8));
      if ( v44->Size > 0 )
      {
        do
        {
          ++v46;
          v44->Data[v46 - 1] = *(_BYTE *)(v46 + *(_QWORD *)v42 - 1);
        }
        while ( v46 < v44->Size );
      }
    }
    Scaleform::Render::GlyphCache::updateTextureGlyph(v10, node);
    ++v10->RasterizationCount;
    result = node;
  }
  else
  {
    v59 = v10->RasterCacheWarning == 0;
    v10->Result = 5;
    if ( !v59 )
    {
      Scaleform::Render::GlyphCache::LogWarning(
        v10,
        "Warning: Increase raster glyph cache capacity - see GlyphCacheParams");
      v10->RasterCacheWarning = 0;
    }
    result = 0i64;
  }
  return result;
}

// File Line: 1964
// RVA: 0x9A3F10
Scaleform::Render::GlyphNode *__fastcall Scaleform::Render::GlyphCache::RasterizeShadow(Scaleform::Render::GlyphCache *this, Scaleform::Render::GlyphRunData *data, Scaleform::Render::TextMeshProvider *tm, Scaleform::Render::GlyphParam *gp, float screenSize, Scaleform::Render::GlyphRaster *ras)
{
  Scaleform::Render::GlyphRunData *v6; // rbx
  Scaleform::Render::GlyphCache *v7; // rdi
  Scaleform::Render::GlyphNode *result; // rax
  float v9; // xmm0_4
  float v10; // xmm6_4
  float v11; // xmm9_4
  __m128 rx; // xmm8
  __m128 ry; // xmm7
  signed int v14; // eax
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm2_4
  float v18; // xmm6_4
  float v19; // xmm0_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  unsigned int v22; // edx
  float v23; // xmm1_4
  signed int v24; // ecx
  signed int v25; // er13
  float v26; // xmm1_4
  signed int v27; // ecx
  int v28; // er13
  unsigned __int64 v29; // rsi
  int v30; // ebx
  int v31; // er14
  int v32; // ebp
  int v33; // er12
  int v34; // ecx
  unsigned int h; // ebp
  Scaleform::Render::GlyphNode *v36; // rax
  char **v37; // r14
  char *v38; // rcx
  float v39; // xmm1_4
  unsigned int v40; // ebx
  int v41; // er12
  float v42; // xmm0_4
  char *v43; // r8
  char *v44; // rdx
  __int16 v45; // cx
  __int16 v46; // ax
  Scaleform::Render::TessBaseVtbl *v47; // rax
  Scaleform::Render::GlyphNode *node; // [rsp+50h] [rbp-B8h]
  unsigned int w; // [rsp+110h] [rbp+8h]
  Scaleform::Render::TextMeshProvider *tma; // [rsp+120h] [rbp+18h]
  Scaleform::Render::GlyphParam *gpa; // [rsp+128h] [rbp+20h]

  gpa = gp;
  tma = tm;
  v6 = data;
  v7 = this;
  if ( !this->MaxNumTextures )
  {
    this->Result = 4;
    return 0i64;
  }
  if ( ras )
  {
    result = Scaleform::Render::GlyphCache::createShadowFromRaster(this, data, tm, gp, screenSize, ras);
    if ( result )
      return result;
    gp = gpa;
  }
  if ( v6->pShape )
  {
    v9 = v6->HeightRatio;
    rx = (__m128)COERCE_UNSIGNED_INT((float)gp->BlurX);
    v10 = (float)gp->FontSize * 0.0625;
    v11 = *(float *)&FLOAT_1_0;
    ry = (__m128)COERCE_UNSIGNED_INT((float)gp->BlurY);
    rx.m128_f32[0] = (float)((float)(rx.m128_f32[0] * 0.0625) * (float)(v10 / screenSize)) * v9;
    ry.m128_f32[0] = (float)((float)(ry.m128_f32[0] * 0.0625) * (float)(v10 / screenSize)) * v9;
    v14 = v6->HintedNomHeight;
    v15 = (float)((float)(signed int)v7->MaxSlotHeight * v7->ShadowQuality) - (float)(2 * v7->SlotPadding);
    if ( v14 )
      v16 = (float)v14;
    else
      v16 = v6->NomHeight;
    v17 = v6->GlyphBounds.y1;
    v18 = v10 / v16;
    v19 = v6->GlyphBounds.y2;
    if ( v17 >= v19 )
    {
      v19 = 0.0;
      v17 = 0.0;
    }
    v20 = (float)((float)(v19 * v18) + ry.m128_f32[0]) - (float)((float)(v17 * v18) - ry.m128_f32[0]);
    if ( v20 >= v15 )
    {
      v21 = v15 / v20;
      v18 = v18 * v21;
      rx.m128_f32[0] = rx.m128_f32[0] * v21;
      ry.m128_f32[0] = ry.m128_f32[0] * v21;
      v11 = 1.0 / v21;
    }
    (*((void (__fastcall **)(Scaleform::Render::Rasterizer *))&v7->Ras.vfptr->__vecDelDtor + 1))(&v7->Ras);
    Scaleform::Render::GlyphCache::addShapeToRasterizer(v7, v6->pShape, v18, v18);
    v22 = v7->SlotPadding;
    v23 = rx.m128_f32[0];
    v24 = (signed int)rx.m128_f32[0];
    if ( (signed int)rx.m128_f32[0] != 0x80000000 && (float)v24 != rx.m128_f32[0] )
      v23 = (float)((_mm_movemask_ps(_mm_unpacklo_ps(rx, rx)) & 1 ^ 1) + v24);
    v25 = (signed int)v23;
    v26 = ry.m128_f32[0];
    v27 = (signed int)ry.m128_f32[0];
    v28 = v22 + v25;
    if ( (signed int)ry.m128_f32[0] != 0x80000000 && (float)v27 != ry.m128_f32[0] )
      v26 = (float)((_mm_movemask_ps(_mm_unpacklo_ps(ry, ry)) & 1 ^ 1) + v27);
    v29 = 0i64;
    v30 = 0;
    v31 = 0;
    v32 = 0;
    v33 = v22 + (signed int)v26;
    if ( Scaleform::Render::Rasterizer::SortCells(&v7->Ras) )
    {
      v30 = v7->Ras.MinX - v28;
      v34 = v28 + v7->Ras.MaxX;
      v31 = v7->Ras.MinY - v33;
      v32 = v33 + v7->Ras.MaxY;
    }
    else
    {
      v34 = 0;
    }
    h = v32 - v31 + 1;
    w = v34 - v30 + 1;
    if ( h > v7->MaxSlotHeight )
      h = v7->MaxSlotHeight;
    v36 = Scaleform::Render::GlyphCache::allocateGlyph(v7, tma, gpa, v34 - v30 + 1, h);
    node = v36;
    if ( v36 )
    {
      v36->Scale = v11;
      v36->Origin.x = 16 * v30;
      v36->Origin.y = 16 * v31;
      v37 = &v7->RasterData.Data.Data;
      Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        (Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)&v7->RasterData,
        w * h);
      v38 = v7->RasterData.Data.Data;
      v7->RasterPitch = w;
      memset(v38, 0, w * h);
      if ( w > 1 && h > 1 )
      {
        v39 = *(float *)&FLOAT_1_0;
        if ( gpa->BlurX || gpa->BlurY )
          v39 = FLOAT_0_40000001;
        if ( v39 != v7->Ras.Gamma2 )
          Scaleform::Render::Rasterizer::SetGamma2(&v7->Ras, v39);
        v40 = 0;
        if ( v7->Ras.SortedYs.Size > 0 )
        {
          do
          {
            if ( v40 + v33 >= h )
              break;
            Scaleform::Render::Rasterizer::SweepScanline(
              &v7->Ras,
              v40,
              &(*v37)[v28 + (unsigned __int64)(v7->RasterPitch * (v40 + v33))],
              1u,
              1);
            ++v40;
          }
          while ( v40 < v7->Ras.SortedYs.Size );
        }
        v41 = 0;
        if ( (LOBYTE(gpa->Flags) >> 5) & 1 )
          Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>::operator=(
            &v7->KnockOutCopy,
            &v7->RasterData);
        if ( rx.m128_f32[0] > 0.0 || ry.m128_f32[0] > 0.0 )
        {
          Scaleform::Render::GlyphCache::recursiveBlur(
            v7,
            *v37,
            v7->RasterPitch,
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
        Scaleform::Render::GlyphCache::strengthenImage(v7, *v37, v7->RasterPitch, 0, 0, w, h, v42, v41);
        if ( (LOBYTE(gpa->Flags) >> 5) & 1 )
        {
          v43 = v7->KnockOutCopy.Data.Data;
          v44 = *v37;
          if ( v7->KnockOutCopy.Data.Size > 0 )
          {
            do
            {
              ++v29;
              v45 = 255 - (unsigned __int8)*v43;
              v46 = (unsigned __int8)*v44;
              ++v43;
              *(++v44 - 1) = (unsigned __int16)(v45 * v46 + 255) >> 8;
            }
            while ( v29 < v7->KnockOutCopy.Data.Size );
          }
        }
      }
      Scaleform::Render::GlyphCache::updateTextureGlyph(v7, node);
      v47 = v7->Ras.vfptr;
      ++v7->RasterizationCount;
      (*((void (__fastcall **)(Scaleform::Render::Rasterizer *))&v47->__vecDelDtor + 1))(&v7->Ras);
      result = node;
    }
    else
    {
      v7->Result = 5;
      if ( v7->RasterCacheWarning )
      {
        Scaleform::Render::GlyphCache::LogWarning(
          v7,
          "Warning: Increase raster glyph cache capacity - see GlyphCacheParams");
        v7->RasterCacheWarning = 0;
      }
      result = 0i64;
    }
  }
  else
  {
    v7->Result = 2;
    result = 0i64;
  }
  return result;
}

// File Line: 2105
// RVA: 0x998CB0
void Scaleform::Render::GlyphCache::LogWarning(Scaleform::Render::GlyphCache *this, const char *fmt, ...)
{
  Scaleform::Log *v2; // rcx
  int v3; // [rsp+20h] [rbp-18h]
  va_list va; // [rsp+50h] [rbp+18h]

  va_start(va, fmt);
  v2 = this->pLog;
  if ( v2 )
  {
    v3 = 143360;
    ((void (__fastcall *)(Scaleform::Log *, int *, const char *, __int64 *, _QWORD))v2->vfptr[1].__vecDelDtor)(
      v2,
      &v3,
      fmt,
      (__int64 *)va,
      *(_QWORD *)&v3);
  }
}

// File Line: 2125
// RVA: 0x9D00A0
void __fastcall Scaleform::Render::GlyphCache::cacheFullWarning(Scaleform::Render::GlyphCache *this)
{
  Scaleform::Render::GlyphCache *v1; // rbx

  v1 = this;
  if ( this->RasterCacheWarning )
  {
    Scaleform::Render::GlyphCache::LogWarning(
      this,
      "Warning: Increase raster glyph cache capacity - see GlyphCacheParams");
    v1->RasterCacheWarning = 0;
  }
}

