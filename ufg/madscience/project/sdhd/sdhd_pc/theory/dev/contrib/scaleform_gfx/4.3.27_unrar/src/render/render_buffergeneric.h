// File Line: 209
// RVA: 0x98DC00
hkLocalFrameGroup *__fastcall Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture(hkSimpleLocalFrame *this)
{
  return this->m_group;
}

// File Line: 257
// RVA: 0x9E8600
void __fastcall Scaleform::Render::RBGenericImpl::DepthStencilBuffer::initSurface(Scaleform::Render::RBGenericImpl::DepthStencilBuffer *this, Scaleform::Render::DepthStencilSurface *surface)
{
  Scaleform::Render::DepthStencilSurface *v2; // rbx
  Scaleform::Render::RBGenericImpl::DepthStencilBuffer *v3; // rdi
  Scaleform::Render::DepthStencilSurface *v4; // rcx

  v2 = surface;
  v3 = this;
  if ( surface )
    _InterlockedExchangeAdd(&surface->RefCount, 1u);
  v4 = this->pSurface.pObject;
  if ( v4 && !_InterlockedDecrement(&v4->RefCount) && v4 )
  {
    v4->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v4->vfptr, 1u);
    v3->pSurface.pObject = v2;
  }
  else
  {
    v3->pSurface.pObject = surface;
  }
}

