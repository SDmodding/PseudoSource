// File Line: 51
// RVA: 0x6C6B40
void __fastcall Scaleform::GFx::ASMovieRootBase::ASMovieRootBase(
        Scaleform::GFx::ASMovieRootBase *this,
        Scaleform::GFx::Resource *asSupport)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::ASMovieRootBase,327>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ASMovieRootBase::`vftable;
  this->pMovieImpl = 0i64;
  if ( asSupport )
    Scaleform::Render::RenderBuffer::AddRef(asSupport);
  this->pASSupport.pObject = (Scaleform::GFx::ASSupport *)asSupport;
  this->AVMVersion = asSupport->vfptr[1].GetResourceTypeCode(asSupport);
}

// File Line: 53
// RVA: 0x6D0AA0
void __fastcall Scaleform::GFx::ASMovieRootBase::~ASMovieRootBase(Scaleform::GFx::ASMovieRootBase *this)
{
  Scaleform::Render::RenderBuffer *pObject; // rcx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ASMovieRootBase::`vftable;
  pObject = (Scaleform::Render::RenderBuffer *)this->pASSupport.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}

