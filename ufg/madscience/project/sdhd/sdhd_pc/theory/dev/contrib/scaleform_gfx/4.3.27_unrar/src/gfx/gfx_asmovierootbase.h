// File Line: 51
// RVA: 0x6C6B40
void __fastcall Scaleform::GFx::ASMovieRootBase::ASMovieRootBase(Scaleform::GFx::ASMovieRootBase *this, Scaleform::GFx::ASSupport *asSupport)
{
  Scaleform::GFx::ASSupport *v2; // rdi
  Scaleform::GFx::ASMovieRootBase *v3; // rbx

  v2 = asSupport;
  v3 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::ASMovieRootBase,327>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ASMovieRootBase::`vftable';
  this->pMovieImpl = 0i64;
  if ( asSupport )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)asSupport);
  v3->pASSupport.pObject = v2;
  v3->AVMVersion = ((__int64 (__fastcall *)(Scaleform::GFx::ASSupport *))v2->vfptr[6].__vecDelDtor)(v2);
}

// File Line: 53
// RVA: 0x6D0AA0
void __fastcall Scaleform::GFx::ASMovieRootBase::~ASMovieRootBase(Scaleform::GFx::ASMovieRootBase *this)
{
  Scaleform::GFx::ASMovieRootBase *v1; // rbx
  Scaleform::Render::RenderBuffer *v2; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ASMovieRootBase::`vftable';
  v2 = (Scaleform::Render::RenderBuffer *)this->pASSupport.pObject;
  if ( v2 )
    Scaleform::RefCountImpl::Release(v2);
  Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)&v1->vfptr);
}

