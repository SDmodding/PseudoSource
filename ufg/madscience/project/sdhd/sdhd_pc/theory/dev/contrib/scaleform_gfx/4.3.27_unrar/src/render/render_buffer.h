// File Line: 70
// RVA: 0x94C310
void __fastcall Scaleform::Render::RenderBuffer::~RenderBuffer(Scaleform::Render::RenderBuffer *this)
{
  Scaleform::Render::RenderBuffer::RenderTargetData *pRenderTargetData; // rcx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::RenderBuffer::`vftable;
  pRenderTargetData = this->pRenderTargetData;
  if ( pRenderTargetData )
  {
    pRenderTargetData->vfptr->__vecDelDtor(pRenderTargetData, 1u);
    this->pRenderTargetData = 0i64;
  }
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

// File Line: 234
// RVA: 0x9499A0
void __fastcall Scaleform::Render::DepthStencilBuffer::~DepthStencilBuffer(Scaleform::Render::DepthStencilBuffer *this)
{
  Scaleform::Render::RenderBuffer::RenderTargetData *pRenderTargetData; // rcx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::DepthStencilBuffer::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::RenderBuffer::`vftable;
  pRenderTargetData = this->pRenderTargetData;
  if ( pRenderTargetData )
  {
    pRenderTargetData->vfptr->__vecDelDtor(pRenderTargetData, 1u);
    this->pRenderTargetData = 0i64;
  }
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

// File Line: 249
// RVA: 0x94C400
void __fastcall Scaleform::Render::RenderBufferManager::~RenderBufferManager(
        Scaleform::Render::RenderBufferManager *this)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::RenderBufferManager::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

// File Line: 298
// RVA: 0x9FBD90
void __fastcall Scaleform::Render::RenderBuffer::RenderTargetData::~RenderTargetData(
        Scaleform::Render::RenderBuffer::RenderTargetData *this)
{
  Scaleform::Render::DepthStencilBuffer *pObject; // rcx

  this->vfptr = (Scaleform::Render::RenderBuffer::RenderTargetDataVtbl *)&Scaleform::Render::RenderBuffer::RenderTargetData::`vftable;
  pObject = this->pDepthStencilBuffer.pObject;
  if ( pObject )
    ((void (__fastcall *)(Scaleform::Render::DepthStencilBuffer *))pObject->vfptr[2].__vecDelDtor)(pObject);
}

