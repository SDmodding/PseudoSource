// File Line: 70
// RVA: 0x94C310
void __fastcall Scaleform::Render::RenderBuffer::~RenderBuffer(Scaleform::Render::RenderBuffer *this)
{
  Scaleform::Render::RenderBuffer *v1; // rbx
  Scaleform::Render::RenderBuffer::RenderTargetData *v2; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::RenderBuffer::`vftable;
  v2 = this->pRenderTargetData;
  if ( v2 )
  {
    v2->vfptr->__vecDelDtor(v2, 1u);
    v1->pRenderTargetData = 0i64;
  }
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

// File Line: 234
// RVA: 0x9499A0
void __fastcall Scaleform::Render::DepthStencilBuffer::~DepthStencilBuffer(Scaleform::Render::DepthStencilBuffer *this)
{
  Scaleform::Render::DepthStencilBuffer *v1; // rbx
  Scaleform::Render::RenderBuffer::RenderTargetData *v2; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::DepthStencilBuffer::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::RenderBuffer::`vftable;
  v2 = this->pRenderTargetData;
  if ( v2 )
  {
    v2->vfptr->__vecDelDtor(v2, 1u);
    v1->pRenderTargetData = 0i64;
  }
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

// File Line: 249
// RVA: 0x94C400
void __fastcall Scaleform::Render::RenderBufferManager::~RenderBufferManager(Scaleform::Render::RenderBufferManager *this)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::RenderBufferManager::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

// File Line: 298
// RVA: 0x9FBD90
void __fastcall Scaleform::Render::RenderBuffer::RenderTargetData::~RenderTargetData(Scaleform::Render::RenderBuffer::RenderTargetData *this)
{
  Scaleform::Render::DepthStencilBuffer *v1; // rcx

  this->vfptr = (Scaleform::Render::RenderBuffer::RenderTargetDataVtbl *)&Scaleform::Render::RenderBuffer::RenderTargetData::`vftable;
  v1 = this->pDepthStencilBuffer.pObject;
  if ( v1 )
    ((void (*)(void))v1->vfptr[2].__vecDelDtor)();
}

