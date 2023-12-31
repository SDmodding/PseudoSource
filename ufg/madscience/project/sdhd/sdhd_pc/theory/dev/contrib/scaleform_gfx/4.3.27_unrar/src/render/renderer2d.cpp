// File Line: 28
// RVA: 0x941320
void __fastcall Scaleform::Render::Renderer2D::Renderer2D(
        Scaleform::Render::Renderer2D *this,
        Scaleform::Render::HAL *hal)
{
  Scaleform::Render::Renderer2DImpl *v4; // rax
  int v5; // [rsp+50h] [rbp+18h] BYREF
  Scaleform::Render::Renderer2DImpl *v6; // [rsp+58h] [rbp+20h]

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,65>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::Renderer2D,65>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Renderer2D::`vftable;
  v5 = 65;
  v4 = (Scaleform::Render::Renderer2DImpl *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::Renderer2D *, __int64, int *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                              Scaleform::Memory::pGlobalHeap,
                                              this,
                                              3696i64,
                                              &v5,
                                              -2i64);
  v6 = v4;
  if ( v4 )
    Scaleform::Render::Renderer2DImpl::Renderer2DImpl(v4, hal);
  this->pImpl = v4;
}

// File Line: 49
// RVA: 0x989550
Scaleform::Render::MeshCacheConfig *__fastcall Scaleform::Render::Renderer2D::GetMeshCacheConfig(
        Scaleform::Render::Renderer2D *this)
{
  Scaleform::Render::MeshCacheConfig *result; // rax

  result = (Scaleform::Render::MeshCacheConfig *)((__int64 (__fastcall *)(Scaleform::Render::HAL *))this->pImpl->pHal.pObject->vfptr[62].__vecDelDtor)(this->pImpl->pHal.pObject);
  if ( result )
    ++result;
  return result;
}

// File Line: 53
// RVA: 0x984D70
Scaleform::Render::GlyphCache *__fastcall Scaleform::Render::Renderer2D::GetGlyphCacheConfig(
        Scaleform::Render::Renderer2D *this)
{
  Scaleform::Render::GlyphCache *result; // rax

  result = this->pImpl->pGlyphCache.pObject;
  if ( result )
    return (Scaleform::Render::GlyphCache *)((char *)result + 24);
  return result;
}

// File Line: 68
// RVA: 0x95A770
bool __fastcall Scaleform::Render::Renderer2D::BeginFrame(Scaleform::Render::Renderer2D *this)
{
  return Scaleform::Render::Renderer2DImpl::BeginFrame(this->pImpl);
}

// File Line: 72
// RVA: 0x9709E0
void __fastcall Scaleform::Render::Renderer2D::EndFrame(Scaleform::Render::Renderer2D *this)
{
  Scaleform::Render::Renderer2DImpl *pImpl; // rbx
  Scaleform::Render::ContextImpl::RenderNotify::ContextNode *pNext; // rax
  Scaleform::List<Scaleform::Render::ContextImpl::RenderNotify::ContextNode,Scaleform::Render::ContextImpl::RenderNotify::ContextNode> *i; // rbx

  pImpl = this->pImpl;
  ((void (__fastcall *)(Scaleform::Render::HAL *))pImpl->pHal.pObject->vfptr[6].__vecDelDtor)(pImpl->pHal.pObject);
  pNext = pImpl->ActiveContextSet.Root.pNext;
  for ( i = &pImpl->ActiveContextSet;
        pNext != (Scaleform::Render::ContextImpl::RenderNotify::ContextNode *)i;
        pNext = pNext->pNext )
  {
    pNext->pContext->NextCaptureCalledInFrame = 0;
  }
}

// File Line: 97
// RVA: 0x96E450
void __fastcall Scaleform::Render::Renderer2D::Display(
        Scaleform::Render::Renderer2D *this,
        Scaleform::Render::TreeRoot *node)
{
  Scaleform::Render::Renderer2DImpl::Draw(this->pImpl, node);
}

