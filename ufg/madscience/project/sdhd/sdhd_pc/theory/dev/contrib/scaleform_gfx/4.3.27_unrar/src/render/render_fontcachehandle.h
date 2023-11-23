// File Line: 41
// RVA: 0x93BF90
void __fastcall Scaleform::Render::FontCacheHandleManager::FontCacheHandleManager(
        Scaleform::Render::FontCacheHandleManager *this,
        Scaleform::MemoryHeap *renderHeap,
        Scaleform::Render::GlyphCache *q)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,75>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::FontCacheHandleManager,75>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::FontCacheHandleManager::`vftable;
  Scaleform::Lock::Lock(&this->FontLock, 0);
  this->Fonts[0].Root.pPrev = (Scaleform::Render::FontCacheHandle *)this->Fonts;
  this->Fonts[0].Root.pNext = (Scaleform::Render::FontCacheHandle *)this->Fonts;
  this->Fonts[1].Root.pPrev = (Scaleform::Render::FontCacheHandle *)&this->Fonts[1];
  this->Fonts[1].Root.pNext = (Scaleform::Render::FontCacheHandle *)&this->Fonts[1];
  this->pRenderHeap = renderHeap;
  this->pCache = q;
}

