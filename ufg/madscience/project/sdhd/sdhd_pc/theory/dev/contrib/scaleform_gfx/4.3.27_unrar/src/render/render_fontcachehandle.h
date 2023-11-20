// File Line: 41
// RVA: 0x93BF90
void __fastcall Scaleform::Render::FontCacheHandleManager::FontCacheHandleManager(Scaleform::Render::FontCacheHandleManager *this, Scaleform::MemoryHeap *renderHeap, Scaleform::Render::GlyphCache *q)
{
  Scaleform::Render::GlyphCache *v3; // rdi
  Scaleform::MemoryHeap *v4; // rbx
  Scaleform::Render::FontCacheHandleManager *v5; // rsi
  Scaleform::List<Scaleform::Render::FontCacheHandle,Scaleform::Render::FontCacheHandle> *v6; // rcx

  v3 = q;
  v4 = renderHeap;
  v5 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,75>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::FontCacheHandleManager,75>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::FontCacheHandleManager::`vftable';
  Scaleform::Lock::Lock(&this->FontLock, 0);
  v6 = v5->Fonts;
  v6->Root.pPrev = (Scaleform::Render::FontCacheHandle *)v6;
  v6->Root.pNext = (Scaleform::Render::FontCacheHandle *)v6;
  v5->Fonts[1].Root.pPrev = (Scaleform::Render::FontCacheHandle *)&v5->Fonts[1];
  v6[1].Root.pNext = (Scaleform::Render::FontCacheHandle *)&v5->Fonts[1];
  v5->pRenderHeap = v4;
  v5->pCache = v3;
}

