// File Line: 37
// RVA: 0x8995B0
void __fastcall Scaleform::GFx::LoadStates::LoadStates(Scaleform::GFx::LoadStates *this)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::LoadStates,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::LoadStates::`vftable;
  this->pBindStates.pObject = 0i64;
  this->pLog.pObject = 0i64;
  this->pParseControl.pObject = 0i64;
  this->pProgressHandler.pObject = 0i64;
  this->pTaskManager.pObject = 0i64;
  this->pImageFileHandlerRegistry.pObject = 0i64;
  this->pZlibSupport.pObject = 0i64;
  this->pAS2Support.pObject = 0i64;
  this->pAS3Support.pObject = 0i64;
  this->pWeakResourceLib.pObject = 0i64;
  this->pLoaderImpl.pObject = 0i64;
  Scaleform::String::String(&this->RelativePath);
  this->ThreadedLoading = 0;
  this->SubstituteFontMovieDefs.Data.Data = 0i64;
  this->SubstituteFontMovieDefs.Data.Size = 0i64;
  this->SubstituteFontMovieDefs.Data.Policy.Capacity = 0i64;
}

// File Line: 44
// RVA: 0x899220
void __fastcall Scaleform::GFx::LoadStates::LoadStates(
        Scaleform::GFx::LoadStates *this,
        Scaleform::GFx::Resource *pimpl,
        Scaleform::GFx::ResourceLibBase **pstates,
        Scaleform::GFx::MovieDefBindStates *pbindStates)
{
  Scaleform::GFx::MovieDefBindStates *v8; // rsi
  Scaleform::Render::RenderBuffer *pObject; // rcx
  Scaleform::GFx::ResourceWeakLib *pLib; // r14
  Scaleform::Render::RenderBuffer *v11; // rcx
  Scaleform::GFx::MovieDefBindStates *v12; // rax
  Scaleform::GFx::MovieDefBindStates *v13; // rax
  Scaleform::GFx::MovieDefBindStates *v14; // rax
  Scaleform::Render::RenderBuffer *v15; // rcx
  Scaleform::GFx::Resource **LogState; // rsi
  Scaleform::Render::RenderBuffer *v17; // rcx
  Scaleform::GFx::Resource **ParseControl; // rsi
  Scaleform::Render::RenderBuffer *v19; // rcx
  Scaleform::GFx::Resource **ProgressHandler; // rsi
  Scaleform::Render::RenderBuffer *v21; // rcx
  Scaleform::GFx::Resource **TaskManager; // rsi
  Scaleform::Render::RenderBuffer *v23; // rcx
  Scaleform::GFx::Resource **ImageFileHandlerRegistry; // rsi
  Scaleform::Render::RenderBuffer *v25; // rcx
  Scaleform::GFx::Resource **ZlibSupport; // rsi
  Scaleform::Render::RenderBuffer *v27; // rcx
  Scaleform::GFx::Resource **AS2Support; // rsi
  Scaleform::Render::RenderBuffer *v29; // rcx
  Scaleform::GFx::Resource **AS3Support; // rdi
  Scaleform::Render::RenderBuffer *v31; // rcx
  Scaleform::Ptr<Scaleform::GFx::TaskManager> v32; // [rsp+20h] [rbp-78h] BYREF
  Scaleform::Ptr<Scaleform::GFx::ImageFileHandlerRegistry> v33; // [rsp+28h] [rbp-70h] BYREF
  Scaleform::Ptr<Scaleform::GFx::ZlibSupportBase> v34; // [rsp+30h] [rbp-68h] BYREF
  Scaleform::Ptr<Scaleform::GFx::ASSupport> v35; // [rsp+38h] [rbp-60h] BYREF
  Scaleform::Ptr<Scaleform::GFx::ASSupport> v36; // [rsp+40h] [rbp-58h] BYREF
  __int64 v37; // [rsp+48h] [rbp-50h]
  Scaleform::Array<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,2,Scaleform::ArrayDefaultPolicy> *p_SubstituteFontMovieDefs; // [rsp+50h] [rbp-48h]
  Scaleform::Array<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,2,Scaleform::ArrayDefaultPolicy> *v39; // [rsp+58h] [rbp-40h]
  Scaleform::Ptr<Scaleform::GFx::LogState> result; // [rsp+A8h] [rbp+10h] BYREF
  Scaleform::Ptr<Scaleform::GFx::ParseControl> v41; // [rsp+B0h] [rbp+18h] BYREF
  Scaleform::Ptr<Scaleform::GFx::ProgressHandler> v42; // [rsp+B8h] [rbp+20h] BYREF

  v37 = -2i64;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::LoadStates,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::LoadStates::`vftable;
  v8 = 0i64;
  this->pBindStates.pObject = 0i64;
  this->pLog.pObject = 0i64;
  this->pParseControl.pObject = 0i64;
  this->pProgressHandler.pObject = 0i64;
  this->pTaskManager.pObject = 0i64;
  this->pImageFileHandlerRegistry.pObject = 0i64;
  this->pZlibSupport.pObject = 0i64;
  this->pAS2Support.pObject = 0i64;
  this->pAS3Support.pObject = 0i64;
  this->pWeakResourceLib.pObject = 0i64;
  this->pLoaderImpl.pObject = 0i64;
  Scaleform::String::String(&this->RelativePath);
  this->ThreadedLoading = 0;
  p_SubstituteFontMovieDefs = &this->SubstituteFontMovieDefs;
  v39 = &this->SubstituteFontMovieDefs;
  this->SubstituteFontMovieDefs.Data.Data = 0i64;
  this->SubstituteFontMovieDefs.Data.Size = 0i64;
  this->SubstituteFontMovieDefs.Data.Policy.Capacity = 0i64;
  if ( pimpl )
    Scaleform::Render::RenderBuffer::AddRef(pimpl);
  pObject = (Scaleform::Render::RenderBuffer *)this->pLoaderImpl.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pLoaderImpl.pObject = (Scaleform::GFx::LoaderImpl *)pimpl;
  pLib = (Scaleform::GFx::ResourceWeakLib *)pimpl[1].pLib;
  if ( pLib )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)pimpl[1].pLib);
  v11 = (Scaleform::Render::RenderBuffer *)this->pWeakResourceLib.pObject;
  if ( v11 )
    Scaleform::RefCountImpl::Release(v11);
  this->pWeakResourceLib.pObject = pLib;
  if ( !pstates )
    pstates = &pimpl->pLib;
  v12 = (Scaleform::GFx::MovieDefBindStates *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                Scaleform::Memory::pGlobalHeap,
                                                80i64);
  v39 = (Scaleform::Array<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,2,Scaleform::ArrayDefaultPolicy> *)v12;
  if ( pbindStates )
  {
    if ( v12 )
    {
      Scaleform::GFx::MovieDefBindStates::MovieDefBindStates(v12, pbindStates);
      v8 = v13;
    }
  }
  else if ( v12 )
  {
    Scaleform::GFx::MovieDefBindStates::MovieDefBindStates(v12, (Scaleform::GFx::StateBag *)pstates);
    v8 = v14;
  }
  v15 = (Scaleform::Render::RenderBuffer *)this->pBindStates.pObject;
  if ( v15 )
    Scaleform::RefCountImpl::Release(v15);
  this->pBindStates.pObject = v8;
  LogState = (Scaleform::GFx::Resource **)Scaleform::GFx::StateBag::GetLogState(
                                            (Scaleform::GFx::StateBag *)pstates,
                                            &result);
  if ( *LogState )
    Scaleform::Render::RenderBuffer::AddRef(*LogState);
  v17 = (Scaleform::Render::RenderBuffer *)this->pLog.pObject;
  if ( v17 )
    Scaleform::RefCountImpl::Release(v17);
  this->pLog.pObject = (Scaleform::GFx::LogState *)*LogState;
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
  ParseControl = (Scaleform::GFx::Resource **)Scaleform::GFx::StateBag::GetParseControl(
                                                (Scaleform::GFx::StateBag *)pstates,
                                                &v41);
  if ( *ParseControl )
    Scaleform::Render::RenderBuffer::AddRef(*ParseControl);
  v19 = (Scaleform::Render::RenderBuffer *)this->pParseControl.pObject;
  if ( v19 )
    Scaleform::RefCountImpl::Release(v19);
  this->pParseControl.pObject = (Scaleform::GFx::ParseControl *)*ParseControl;
  if ( v41.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v41.pObject);
  ProgressHandler = (Scaleform::GFx::Resource **)Scaleform::GFx::StateBag::GetProgressHandler(
                                                   (Scaleform::GFx::StateBag *)pstates,
                                                   &v42);
  if ( *ProgressHandler )
    Scaleform::Render::RenderBuffer::AddRef(*ProgressHandler);
  v21 = (Scaleform::Render::RenderBuffer *)this->pProgressHandler.pObject;
  if ( v21 )
    Scaleform::RefCountImpl::Release(v21);
  this->pProgressHandler.pObject = (Scaleform::GFx::ProgressHandler *)*ProgressHandler;
  if ( v42.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v42.pObject);
  TaskManager = (Scaleform::GFx::Resource **)Scaleform::GFx::StateBag::GetTaskManager(
                                               (Scaleform::GFx::StateBag *)pstates,
                                               &v32);
  if ( *TaskManager )
    Scaleform::Render::RenderBuffer::AddRef(*TaskManager);
  v23 = (Scaleform::Render::RenderBuffer *)this->pTaskManager.pObject;
  if ( v23 )
    Scaleform::RefCountImpl::Release(v23);
  this->pTaskManager.pObject = (Scaleform::GFx::TaskManager *)*TaskManager;
  if ( v32.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v32.pObject);
  ImageFileHandlerRegistry = (Scaleform::GFx::Resource **)Scaleform::GFx::StateBag::GetImageFileHandlerRegistry(
                                                            (Scaleform::GFx::StateBag *)pstates,
                                                            &v33);
  if ( *ImageFileHandlerRegistry )
    Scaleform::Render::RenderBuffer::AddRef(*ImageFileHandlerRegistry);
  v25 = (Scaleform::Render::RenderBuffer *)this->pImageFileHandlerRegistry.pObject;
  if ( v25 )
    Scaleform::RefCountImpl::Release(v25);
  this->pImageFileHandlerRegistry.pObject = (Scaleform::GFx::ImageFileHandlerRegistry *)*ImageFileHandlerRegistry;
  if ( v33.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v33.pObject);
  ZlibSupport = (Scaleform::GFx::Resource **)Scaleform::GFx::StateBag::GetZlibSupport(
                                               (Scaleform::GFx::StateBag *)pstates,
                                               &v34);
  if ( *ZlibSupport )
    Scaleform::Render::RenderBuffer::AddRef(*ZlibSupport);
  v27 = (Scaleform::Render::RenderBuffer *)this->pZlibSupport.pObject;
  if ( v27 )
    Scaleform::RefCountImpl::Release(v27);
  this->pZlibSupport.pObject = (Scaleform::GFx::ZlibSupportBase *)*ZlibSupport;
  if ( v34.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v34.pObject);
  AS2Support = (Scaleform::GFx::Resource **)Scaleform::GFx::StateBag::GetAS2Support(
                                              (Scaleform::GFx::StateBag *)pstates,
                                              &v35);
  if ( *AS2Support )
    Scaleform::Render::RenderBuffer::AddRef(*AS2Support);
  v29 = (Scaleform::Render::RenderBuffer *)this->pAS2Support.pObject;
  if ( v29 )
    Scaleform::RefCountImpl::Release(v29);
  this->pAS2Support.pObject = (Scaleform::GFx::ASSupport *)*AS2Support;
  if ( v35.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v35.pObject);
  AS3Support = (Scaleform::GFx::Resource **)Scaleform::GFx::StateBag::GetAS3Support(
                                              (Scaleform::GFx::StateBag *)pstates,
                                              &v36);
  if ( *AS3Support )
    Scaleform::Render::RenderBuffer::AddRef(*AS3Support);
  v31 = (Scaleform::Render::RenderBuffer *)this->pAS3Support.pObject;
  if ( v31 )
    Scaleform::RefCountImpl::Release(v31);
  this->pAS3Support.pObject = (Scaleform::GFx::ASSupport *)*AS3Support;
  if ( v36.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v36.pObject);
}

// File Line: 80
// RVA: 0x8A5430
void __fastcall Scaleform::GFx::LoadStates::~LoadStates(Scaleform::GFx::LoadStates *this)
{
  Scaleform::Array<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,2,Scaleform::ArrayDefaultPolicy> *p_SubstituteFontMovieDefs; // rbx
  Scaleform::Render::RenderBuffer *pObject; // rcx
  Scaleform::Render::RenderBuffer *v4; // rcx
  Scaleform::Render::RenderBuffer *v5; // rcx
  Scaleform::Render::RenderBuffer *v6; // rcx
  Scaleform::Render::RenderBuffer *v7; // rcx
  Scaleform::Render::RenderBuffer *v8; // rcx
  Scaleform::Render::RenderBuffer *v9; // rcx
  Scaleform::Render::RenderBuffer *v10; // rcx
  Scaleform::Render::RenderBuffer *v11; // rcx
  Scaleform::Render::RenderBuffer *v12; // rcx
  Scaleform::Render::RenderBuffer *v13; // rcx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::LoadStates::`vftable;
  p_SubstituteFontMovieDefs = &this->SubstituteFontMovieDefs;
  Scaleform::ConstructorMov<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>>::DestructArray(
    this->SubstituteFontMovieDefs.Data.Data,
    this->SubstituteFontMovieDefs.Data.Size);
  if ( p_SubstituteFontMovieDefs->Data.Data )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((this->RelativePath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  pObject = (Scaleform::Render::RenderBuffer *)this->pLoaderImpl.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  v4 = (Scaleform::Render::RenderBuffer *)this->pWeakResourceLib.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  v5 = (Scaleform::Render::RenderBuffer *)this->pAS3Support.pObject;
  if ( v5 )
    Scaleform::RefCountImpl::Release(v5);
  v6 = (Scaleform::Render::RenderBuffer *)this->pAS2Support.pObject;
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
  v7 = (Scaleform::Render::RenderBuffer *)this->pZlibSupport.pObject;
  if ( v7 )
    Scaleform::RefCountImpl::Release(v7);
  v8 = (Scaleform::Render::RenderBuffer *)this->pImageFileHandlerRegistry.pObject;
  if ( v8 )
    Scaleform::RefCountImpl::Release(v8);
  v9 = (Scaleform::Render::RenderBuffer *)this->pTaskManager.pObject;
  if ( v9 )
    Scaleform::RefCountImpl::Release(v9);
  v10 = (Scaleform::Render::RenderBuffer *)this->pProgressHandler.pObject;
  if ( v10 )
    Scaleform::RefCountImpl::Release(v10);
  v11 = (Scaleform::Render::RenderBuffer *)this->pParseControl.pObject;
  if ( v11 )
    Scaleform::RefCountImpl::Release(v11);
  v12 = (Scaleform::Render::RenderBuffer *)this->pLog.pObject;
  if ( v12 )
    Scaleform::RefCountImpl::Release(v12);
  v13 = (Scaleform::Render::RenderBuffer *)this->pBindStates.pObject;
  if ( v13 )
    Scaleform::RefCountImpl::Release(v13);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}

// File Line: 103
// RVA: 0x8D9C50
Scaleform::GFx::ImageCreator *__fastcall Scaleform::GFx::LoadStates::GetImageCreator(Scaleform::GFx::LoadStates *this)
{
  return this->pBindStates.pObject->pImageCreator.pObject;
}

// File Line: 109
// RVA: 0x90ADA0
void __fastcall Scaleform::GFx::LoadStates::SetRelativePathForDataDef(
        Scaleform::GFx::LoadStates *this,
        Scaleform::GFx::MovieDataDef *pdef)
{
  Scaleform::String *p_RelativePath; // rbx

  p_RelativePath = &this->RelativePath;
  Scaleform::String::operator=(
    &this->RelativePath,
    (const char *)((pdef->pData.pObject->FileURL.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
  if ( !Scaleform::GFx::URLBuilder::ExtractFilePath(p_RelativePath) )
    Scaleform::String::Clear(p_RelativePath);
}

// File Line: 120
// RVA: 0x8EECE0
Scaleform::File *__fastcall Scaleform::GFx::LoadStates::OpenFile(
        Scaleform::GFx::LoadStates *this,
        const char *pfilename,
        unsigned int loadConstants)
{
  Scaleform::GFx::LogState *v5; // rcx
  Scaleform::Log *pObject; // r8

  if ( this->pBindStates.pObject->pFileOpener.pObject )
  {
    if ( (loadConstants & 0x200000) != 0 )
    {
      pObject = 0i64;
    }
    else
    {
      pObject = this->pLog.pObject->pLog.pObject;
      if ( !pObject )
        pObject = Scaleform::Log::GetGlobalLog();
    }
    return (Scaleform::File *)((__int64 (__fastcall *)(Scaleform::GFx::FileOpener *, const char *, Scaleform::Log *, __int64, int))this->pBindStates.pObject->pFileOpener.pObject->vfptr[3].__vecDelDtor)(
                                this->pBindStates.pObject->pFileOpener.pObject,
                                pfilename,
                                pObject,
                                33i64,
                                438);
  }
  else
  {
    v5 = this->pLog.pObject;
    if ( v5 )
    {
      if ( (loadConstants & 0x200000) == 0 )
        Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
          &v5->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
          "Loader failed to open %s, FileOpener not installe",
          pfilename);
    }
    return 0i64;
  }
}

// File Line: 136
// RVA: 0x8B8900
void __fastcall Scaleform::GFx::LoadStates::BuildURL(
        Scaleform::GFx::LoadStates *this,
        Scaleform::String *pdest,
        Scaleform::GFx::URLBuilder::LocationInfo *loc)
{
  Scaleform::GFx::URLBuilder *pObject; // rcx

  pObject = this->pBindStates.pObject->pURLBulider.pObject;
  if ( pObject )
    ((void (__fastcall *)(Scaleform::GFx::URLBuilder *, Scaleform::String *, Scaleform::GFx::URLBuilder::LocationInfo *, Scaleform::String *))pObject->vfptr[1].__vecDelDtor)(
      pObject,
      pdest,
      loc,
      pdest);
  else
    Scaleform::GFx::URLBuilder::DefaultBuildURL(pdest, loc);
}

// File Line: 149
// RVA: 0x8BCD70
Scaleform::GFx::LoadStates *__fastcall Scaleform::GFx::LoadStates::CloneForImport(Scaleform::GFx::LoadStates *this)
{
  Scaleform::GFx::MovieDefBindStates *v2; // rax
  _QWORD *v3; // rbx
  Scaleform::GFx::Resource *v4; // rax
  Scaleform::GFx::Resource *v5; // rsi
  Scaleform::GFx::LoadStates *v6; // rax
  _QWORD *v7; // rax
  Scaleform::Render::RenderBuffer *v8; // rcx
  Scaleform::GFx::Resource *pObject; // rcx
  Scaleform::Render::RenderBuffer *v10; // rcx
  Scaleform::GFx::Resource *v11; // rcx
  Scaleform::Render::RenderBuffer *v12; // rcx
  Scaleform::GFx::Resource *v13; // rcx
  Scaleform::Render::RenderBuffer *v14; // rcx
  Scaleform::GFx::Resource *v15; // rcx
  Scaleform::Render::RenderBuffer *v16; // rcx
  Scaleform::GFx::Resource *v17; // rcx
  Scaleform::Render::RenderBuffer *v18; // rcx
  Scaleform::GFx::ResourceWeakLib *v19; // rcx
  Scaleform::Render::RenderBuffer *v20; // rcx
  Scaleform::GFx::ImageFileHandlerRegistry *v21; // rcx
  Scaleform::Render::RenderBuffer *v22; // rcx
  Scaleform::GFx::Resource *v23; // rcx
  Scaleform::Render::RenderBuffer *v24; // rcx
  Scaleform::GFx::Resource *v25; // rcx
  Scaleform::Render::RenderBuffer *v26; // rcx
  Scaleform::GFx::Resource *v27; // rcx
  Scaleform::Render::RenderBuffer *v28; // rcx

  v2 = (Scaleform::GFx::MovieDefBindStates *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                               Scaleform::Memory::pGlobalHeap,
                                               80i64);
  v3 = 0i64;
  if ( v2 )
  {
    Scaleform::GFx::MovieDefBindStates::MovieDefBindStates(v2, this->pBindStates.pObject);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  v6 = (Scaleform::GFx::LoadStates *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                       Scaleform::Memory::pGlobalHeap,
                                       144i64,
                                       0i64);
  if ( v6 )
  {
    Scaleform::GFx::LoadStates::LoadStates(v6);
    v3 = v7;
  }
  if ( v3 )
  {
    if ( v5 )
      Scaleform::Render::RenderBuffer::AddRef(v5);
    v8 = (Scaleform::Render::RenderBuffer *)v3[2];
    if ( v8 )
      Scaleform::RefCountImpl::Release(v8);
    v3[2] = v5;
    pObject = (Scaleform::GFx::Resource *)this->pLoaderImpl.pObject;
    if ( pObject )
      Scaleform::Render::RenderBuffer::AddRef(pObject);
    v10 = (Scaleform::Render::RenderBuffer *)v3[12];
    if ( v10 )
      Scaleform::RefCountImpl::Release(v10);
    v3[12] = this->pLoaderImpl.pObject;
    v11 = (Scaleform::GFx::Resource *)this->pLog.pObject;
    if ( v11 )
      Scaleform::Render::RenderBuffer::AddRef(v11);
    v12 = (Scaleform::Render::RenderBuffer *)v3[3];
    if ( v12 )
      Scaleform::RefCountImpl::Release(v12);
    v3[3] = this->pLog.pObject;
    v13 = (Scaleform::GFx::Resource *)this->pProgressHandler.pObject;
    if ( v13 )
      Scaleform::Render::RenderBuffer::AddRef(v13);
    v14 = (Scaleform::Render::RenderBuffer *)v3[5];
    if ( v14 )
      Scaleform::RefCountImpl::Release(v14);
    v3[5] = this->pProgressHandler.pObject;
    v15 = (Scaleform::GFx::Resource *)this->pTaskManager.pObject;
    if ( v15 )
      Scaleform::Render::RenderBuffer::AddRef(v15);
    v16 = (Scaleform::Render::RenderBuffer *)v3[6];
    if ( v16 )
      Scaleform::RefCountImpl::Release(v16);
    v3[6] = this->pTaskManager.pObject;
    v17 = (Scaleform::GFx::Resource *)this->pParseControl.pObject;
    if ( v17 )
      Scaleform::Render::RenderBuffer::AddRef(v17);
    v18 = (Scaleform::Render::RenderBuffer *)v3[4];
    if ( v18 )
      Scaleform::RefCountImpl::Release(v18);
    v3[4] = this->pParseControl.pObject;
    v19 = this->pWeakResourceLib.pObject;
    if ( v19 )
      Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v19);
    v20 = (Scaleform::Render::RenderBuffer *)v3[11];
    if ( v20 )
      Scaleform::RefCountImpl::Release(v20);
    v3[11] = this->pWeakResourceLib.pObject;
    v21 = this->pImageFileHandlerRegistry.pObject;
    if ( v21 )
      Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v21);
    v22 = (Scaleform::Render::RenderBuffer *)v3[7];
    if ( v22 )
      Scaleform::RefCountImpl::Release(v22);
    v3[7] = this->pImageFileHandlerRegistry.pObject;
    v23 = (Scaleform::GFx::Resource *)this->pZlibSupport.pObject;
    if ( v23 )
      Scaleform::Render::RenderBuffer::AddRef(v23);
    v24 = (Scaleform::Render::RenderBuffer *)v3[8];
    if ( v24 )
      Scaleform::RefCountImpl::Release(v24);
    v3[8] = this->pZlibSupport.pObject;
    v25 = (Scaleform::GFx::Resource *)this->pAS2Support.pObject;
    if ( v25 )
      Scaleform::Render::RenderBuffer::AddRef(v25);
    v26 = (Scaleform::Render::RenderBuffer *)v3[9];
    if ( v26 )
      Scaleform::RefCountImpl::Release(v26);
    v3[9] = this->pAS2Support.pObject;
    v27 = (Scaleform::GFx::Resource *)this->pAS3Support.pObject;
    if ( v27 )
      Scaleform::Render::RenderBuffer::AddRef(v27);
    v28 = (Scaleform::Render::RenderBuffer *)v3[10];
    if ( v28 )
      Scaleform::RefCountImpl::Release(v28);
    v3[10] = this->pAS3Support.pObject;
  }
  if ( v5 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v5);
  return (Scaleform::GFx::LoadStates *)v3;
}

// File Line: 197
// RVA: 0x898C70
void __fastcall Scaleform::GFx::LoadProcess::LoadProcess(
        Scaleform::GFx::LoadProcess *this,
        Scaleform::GFx::MovieDataDef *pdataDef,
        Scaleform::GFx::LoadStates *pstates,
        unsigned int loadFlags)
{
  Scaleform::GFx::ParseControl *pObject; // rax
  unsigned int ParseFlags; // eax
  Scaleform::GFx::Resource *v10; // rcx
  Scaleform::Render::RenderBuffer *v11; // rcx

  Scaleform::GFx::LoaderTask::LoaderTask(this, pstates, Id_MovieDataLoad);
  this->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>Vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::`vftable;
  this->Scaleform::GFx::LoaderTask::Scaleform::GFx::Task::Scaleform::RefCountBase<Scaleform::GFx::Task,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::LoadProcess::`vftable{for `Scaleform::GFx::LoaderTask};
  this->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>Vtbl *)&Scaleform::GFx::LoadProcess::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>};
  this->pBindProcess.pObject = 0i64;
  this->pLoadData.pObject = 0i64;
  Scaleform::GFx::SWFProcessInfo::SWFProcessInfo(&this->ProcessInfo, pdataDef->pData.pObject->pHeap);
  this->pJpegTables.pObject = 0i64;
  `eh vector constructor iterator(
    this->FrameTags,
    0x18ui64,
    2,
    (void (__fastcall *)(void *))Scaleform::Array<Scaleform::GFx::ExecuteTag *,2,Scaleform::ArrayConstPolicy<32,16,0>>::Array<Scaleform::GFx::ExecuteTag *,2,Scaleform::ArrayConstPolicy<32,16,0>>);
  this->InitActionTags.Data.Data = 0i64;
  this->InitActionTags.Data.Size = 0i64;
  this->InitActionTags.Data.Policy.Capacity = 0i64;
  pObject = pstates->pParseControl.pObject;
  if ( pObject )
    ParseFlags = pObject->ParseFlags;
  else
    ParseFlags = 0;
  this->ParseFlags = ParseFlags;
  v10 = (Scaleform::GFx::Resource *)pdataDef->pData.pObject;
  if ( v10 )
    Scaleform::Render::RenderBuffer::AddRef(v10);
  v11 = (Scaleform::Render::RenderBuffer *)this->pLoadData.pObject;
  if ( v11 )
    Scaleform::RefCountImpl::Release(v11);
  this->pLoadData.pObject = pdataDef->pData.pObject;
  this->pDataDef_Unsafe = pdataDef;
  this->pTimelineDef = 0i64;
  this->LoadFlags = loadFlags;
  this->LoadState = LS_LoadingRoot;
  this->ImportIndex = 0;
  *(_QWORD *)&this->ImportDataCount = 0i64;
  this->FontDataCount = 0;
  this->pImportDataLast = 0i64;
  this->pImportData = 0i64;
  this->pResourceDataLast = 0i64;
  this->pResourceData = 0i64;
  this->pFontDataLast = 0i64;
  this->pFontData = 0i64;
  this->pAltStream = 0i64;
  this->pTempBindData = 0i64;
  this->ASInitActionTagsNum = 0;
}

// File Line: 253
// RVA: 0x8A5170
void __fastcall Scaleform::GFx::LoadProcess::~LoadProcess(Scaleform::GFx::LoadProcess *this)
{
  Scaleform::Render::RenderBuffer *pObject; // rcx
  Scaleform::GFx::MovieDataDef::LoadTaskData *v3; // rax
  Scaleform::GFx::LoadUpdateSync *v4; // rsi
  Scaleform::Render::RenderBuffer *v5; // rcx
  Scaleform::Render::RenderBuffer *v6; // rcx
  Scaleform::Render::RenderBuffer *v7; // rcx
  Scaleform::Render::RenderBuffer *v8; // rcx
  Scaleform::Render::RenderBuffer *v9; // rcx
  Scaleform::Render::RenderBuffer *v10; // rcx
  Scaleform::Render::RenderBuffer *v11; // rcx

  this->Scaleform::GFx::LoaderTask::Scaleform::GFx::Task::Scaleform::RefCountBase<Scaleform::GFx::Task,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::LoadProcess::`vftable{for `Scaleform::GFx::LoaderTask};
  this->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>Vtbl *)&Scaleform::GFx::LoadProcess::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>};
  pObject = (Scaleform::Render::RenderBuffer *)this->pJpegTables.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pJpegTables.pObject = 0i64;
  v3 = this->pLoadData.pObject;
  v4 = v3->pFrameUpdate.pObject;
  if ( v4 )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v3->pFrameUpdate.pObject);
  Scaleform::String::Clear(&this->ProcessInfo.Stream.FileName);
  v5 = (Scaleform::Render::RenderBuffer *)this->ProcessInfo.Stream.pInput.pObject;
  if ( v5 )
    Scaleform::RefCountImpl::Release(v5);
  this->ProcessInfo.Stream.pInput.pObject = 0i64;
  this->ProcessInfo.Stream.pLog = 0i64;
  this->ProcessInfo.Stream.pParseControl = 0i64;
  v6 = (Scaleform::Render::RenderBuffer *)this->pLoadData.pObject;
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
  this->pLoadData.pObject = 0i64;
  v7 = (Scaleform::Render::RenderBuffer *)this->pBindProcess.pObject;
  if ( v7 )
    Scaleform::RefCountImpl::Release(v7);
  this->pBindProcess.pObject = 0i64;
  if ( v4 )
  {
    Scaleform::Mutex::DoLock(&v4->mMutex);
    v4->LoadFinished = 1;
    Scaleform::WaitCondition::NotifyAll(&v4->WC);
    Scaleform::Mutex::Unlock(&v4->mMutex);
  }
  if ( v4 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v4);
  if ( this->InitActionTags.Data.Data )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  `eh vector destructor iterator(
    this->FrameTags,
    0x18ui64,
    2,
    (void (__fastcall *)(void *))Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>);
  v8 = (Scaleform::Render::RenderBuffer *)this->pJpegTables.pObject;
  if ( v8 )
    Scaleform::RefCountImpl::Release(v8);
  Scaleform::GFx::SWFProcessInfo::~SWFProcessInfo(&this->ProcessInfo);
  v9 = (Scaleform::Render::RenderBuffer *)this->pLoadData.pObject;
  if ( v9 )
    Scaleform::RefCountImpl::Release(v9);
  v10 = (Scaleform::Render::RenderBuffer *)this->pBindProcess.pObject;
  if ( v10 )
    Scaleform::RefCountImpl::Release(v10);
  this->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>Vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::`vftable;
  this->Scaleform::GFx::LoaderTask::Scaleform::GFx::Task::Scaleform::RefCountBase<Scaleform::GFx::Task,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::LoaderTask::`vftable;
  Scaleform::GFx::LoaderImpl::UnRegisterLoadProcess(this->pLoadStates.pObject->pLoaderImpl.pObject, this);
  v11 = (Scaleform::Render::RenderBuffer *)this->pLoadStates.pObject;
  if ( v11 )
    Scaleform::RefCountImpl::Release(v11);
  this->Scaleform::GFx::LoaderTask::Scaleform::GFx::Task::Scaleform::RefCountBase<Scaleform::GFx::Task,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::Task::`vftable;
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}

// File Line: 295
// RVA: 0x8B6FB0
char __fastcall Scaleform::GFx::LoadProcess::BeginSWFLoading(Scaleform::GFx::LoadProcess *this, Scaleform::File *pfile)
{
  char result; // al
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // rbx

  result = Scaleform::GFx::SWFProcessInfo::Initialize(
             &this->ProcessInfo,
             pfile,
             this->pLoadStates.pObject->pLog.pObject,
             this->pLoadStates.pObject->pZlibSupport.pObject,
             this->pLoadStates.pObject->pParseControl.pObject,
             1);
  if ( result )
  {
    this->pLoadData.pObject->FileAttributes = this->ProcessInfo.FileAttributes;
    pObject = this->pLoadData.pObject;
    Scaleform::GFx::MovieHeaderData::operator=(&pObject->Header, &this->ProcessInfo.Header);
    Scaleform::GFx::MovieDataDef::LoadTaskData::UpdateLoadState(pObject, pObject->LoadingFrame, LS_LoadingFrames);
    return 1;
  }
  return result;
}

// File Line: 339
// RVA: 0x8BD270
void __fastcall Scaleform::GFx::LoadProcess::CommitFrameTags(Scaleform::GFx::LoadProcess *this)
{
  __int64 LoadState; // rcx
  Scaleform::GFx::LoadStates *pObject; // rax
  Scaleform::GFx::LogState *v4; // rbp
  unsigned __int64 Size; // rax
  Scaleform::GFx::MovieDataDef::LoadTaskData *v6; // rcx
  size_t v7; // rdi
  unsigned __int64 BytesLeft; // r8
  Scaleform::GFx::DataAllocator *p_TagMemAllocator; // rcx
  unsigned __int64 v10; // rdx
  char *pCurrent; // r9
  char *v12; // rax
  Scaleform::GFx::MovieDataDef::LoadTaskData *v13; // r14
  Scaleform::GFx::Task *v14; // rsi
  Scaleform::GFx::LogState *v15; // r15
  __int64 v16; // rax
  unsigned __int64 v17; // r9
  size_t v18; // rbp
  unsigned __int64 v19; // rdx
  char *v20; // rcx
  Scaleform::GFx::MovieDataDef::LoadTaskData *v21; // rsi
  Scaleform::GFx::LogState *v22; // rbp
  unsigned __int64 v23; // rdi
  unsigned __int64 v24; // r9
  size_t v25; // rdi
  unsigned __int64 v26; // rdx
  char *v27; // rcx
  char *v28; // [rsp+20h] [rbp-28h] BYREF
  Scaleform::GFx::Task::TaskId ThisTaskId; // [rsp+28h] [rbp-20h]

  LoadState = this->LoadState;
  pObject = this->pLoadStates.pObject;
  if ( (_DWORD)LoadState == 1 )
  {
    v4 = pObject->pLog.pObject;
    v28 = 0i64;
    ThisTaskId = 0;
    Size = this->FrameTags[1].Data.Size;
    if ( Size )
    {
      v6 = this->pLoadData.pObject;
      v7 = 8 * Size;
      BytesLeft = v6->TagMemAllocator.BytesLeft;
      p_TagMemAllocator = &v6->TagMemAllocator;
      v10 = (8 * Size + 7) & 0xFFFFFFFFFFFFFFF8ui64;
      if ( v10 > BytesLeft )
      {
        pCurrent = (char *)Scaleform::GFx::DataAllocator::OverflowAlloc(p_TagMemAllocator, v10);
      }
      else
      {
        pCurrent = p_TagMemAllocator->pCurrent;
        v12 = &p_TagMemAllocator->pCurrent[v10];
        p_TagMemAllocator->BytesLeft = BytesLeft - v10;
        p_TagMemAllocator->pCurrent = v12;
      }
      v28 = pCurrent;
      if ( pCurrent )
      {
        memmove(pCurrent, this->FrameTags[1].Data.Data, v7);
        ThisTaskId = this->FrameTags[1].Data.Size;
      }
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::ExecuteTag *,Scaleform::AllocatorGH<Scaleform::GFx::ExecuteTag *,2>,Scaleform::ArrayConstPolicy<32,16,0>>>::Clear(&this->FrameTags[1]);
    }
    ((void (__fastcall *)(Scaleform::GFx::TimelineIODef *, char **, Scaleform::GFx::LogState *))this->pTimelineDef->vfptr[4].__vecDelDtor)(
      this->pTimelineDef,
      &v28,
      v4);
  }
  else
  {
    v13 = this->pLoadData.pObject;
    v14 = (Scaleform::GFx::LoadProcess *)((char *)this + 24 * LoadState);
    v15 = pObject->pLog.pObject;
    v28 = 0i64;
    ThisTaskId = 0;
    v16 = *(_QWORD *)&v14[40].ThisTaskId;
    if ( v16 )
    {
      v17 = v13->TagMemAllocator.BytesLeft;
      v18 = 8 * v16;
      v19 = (8 * v16 + 7) & 0xFFFFFFFFFFFFFFF8ui64;
      if ( v19 > v17 )
      {
        v20 = (char *)Scaleform::GFx::DataAllocator::OverflowAlloc(&v13->TagMemAllocator, v19);
      }
      else
      {
        v20 = v13->TagMemAllocator.pCurrent;
        v13->TagMemAllocator.BytesLeft = v17 - v19;
        v13->TagMemAllocator.pCurrent = &v20[v19];
      }
      v28 = v20;
      if ( v20 )
      {
        memmove(v20, *(const void **)&v14[40].RefCount, v18);
        ThisTaskId = v14[40].ThisTaskId;
      }
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::ExecuteTag *,Scaleform::AllocatorGH<Scaleform::GFx::ExecuteTag *,2>,Scaleform::ArrayConstPolicy<32,16,0>>>::Clear((Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::ExecuteTag *,Scaleform::AllocatorGH<Scaleform::GFx::ExecuteTag *,2>,Scaleform::ArrayConstPolicy<32,16,0> > > *)&v14[40].RefCount);
    }
    ((void (__fastcall *)(Scaleform::GFx::MovieDataDef::LoadTaskData *, char **, Scaleform::GFx::LogState *))v13->vfptr[2].__vecDelDtor)(
      v13,
      &v28,
      v15);
    v21 = this->pLoadData.pObject;
    v22 = this->pLoadStates.pObject->pLog.pObject;
    v28 = 0i64;
    ThisTaskId = 0;
    v23 = this->InitActionTags.Data.Size;
    if ( v23 )
    {
      v24 = v21->TagMemAllocator.BytesLeft;
      v25 = 8 * v23;
      v26 = (v25 + 7) & 0xFFFFFFFFFFFFFFF8ui64;
      if ( v26 > v24 )
      {
        v27 = (char *)Scaleform::GFx::DataAllocator::OverflowAlloc(&v21->TagMemAllocator, v26);
      }
      else
      {
        v27 = v21->TagMemAllocator.pCurrent;
        v21->TagMemAllocator.BytesLeft = v24 - v26;
        v21->TagMemAllocator.pCurrent = &v27[v26];
      }
      v28 = v27;
      if ( v27 )
      {
        memmove(v27, this->InitActionTags.Data.Data, v25);
        ThisTaskId = this->InitActionTags.Data.Size;
      }
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::ExecuteTag *,Scaleform::AllocatorGH<Scaleform::GFx::ExecuteTag *,2>,Scaleform::ArrayConstPolicy<32,16,0>>>::Clear(&this->InitActionTags);
    }
    ((void (__fastcall *)(Scaleform::GFx::MovieDataDef::LoadTaskData *, char **, Scaleform::GFx::LogState *))v21->vfptr[3].__vecDelDtor)(
      v21,
      &v28,
      v22);
  }
}

// File Line: 355
// RVA: 0x8BB3F0
void __fastcall Scaleform::GFx::LoadProcess::CleanupFrameTags(Scaleform::GFx::LoadProcess *this)
{
  unsigned __int64 i; // rdi
  Scaleform::GFx::ExecuteTag *v3; // rcx
  unsigned __int64 j; // rdi
  Scaleform::GFx::ExecuteTag *v5; // rcx
  unsigned __int64 k; // rdi
  Scaleform::GFx::ExecuteTag *v7; // rcx
  Scaleform::GFx::ExecuteTag **Data; // rdx
  Scaleform::GFx::ExecuteTag **v9; // rax
  Scaleform::GFx::ExecuteTag **v10; // rdx
  Scaleform::GFx::ExecuteTag **v11; // rax
  Scaleform::GFx::ExecuteTag **v12; // rdx
  Scaleform::GFx::ExecuteTag **v13; // rax
  int v14; // [rsp+30h] [rbp+8h] BYREF

  for ( i = 0i64; i < this->FrameTags[1].Data.Size; ++i )
  {
    v3 = this->FrameTags[1].Data.Data[i];
    v3->vfptr->__vecDelDtor(v3, 0);
  }
  for ( j = 0i64; j < this->FrameTags[0].Data.Size; ++j )
  {
    v5 = this->FrameTags[0].Data.Data[j];
    v5->vfptr->__vecDelDtor(v5, 0);
  }
  for ( k = 0i64; k < this->InitActionTags.Data.Size; ++k )
  {
    v7 = this->InitActionTags.Data.Data[k];
    v7->vfptr->__vecDelDtor(v7, 0);
  }
  if ( this->FrameTags[1].Data.Size && (this->FrameTags[1].Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    Data = this->FrameTags[1].Data.Data;
    if ( Data )
    {
      v9 = (Scaleform::GFx::ExecuteTag **)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(
                                            Scaleform::Memory::pGlobalHeap,
                                            Data,
                                            256i64);
    }
    else
    {
      v14 = 2;
      v9 = (Scaleform::GFx::ExecuteTag **)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                            Scaleform::Memory::pGlobalHeap,
                                            256i64,
                                            &v14);
    }
    this->FrameTags[1].Data.Data = v9;
    this->FrameTags[1].Data.Policy.Capacity = 32i64;
  }
  this->FrameTags[1].Data.Size = 0i64;
  if ( this->FrameTags[0].Data.Size && (this->FrameTags[0].Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v10 = this->FrameTags[0].Data.Data;
    if ( v10 )
    {
      v11 = (Scaleform::GFx::ExecuteTag **)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(
                                             Scaleform::Memory::pGlobalHeap,
                                             v10,
                                             256i64);
    }
    else
    {
      v14 = 2;
      v11 = (Scaleform::GFx::ExecuteTag **)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                             Scaleform::Memory::pGlobalHeap,
                                             256i64,
                                             &v14);
    }
    this->FrameTags[0].Data.Data = v11;
    this->FrameTags[0].Data.Policy.Capacity = 32i64;
  }
  this->FrameTags[0].Data.Size = 0i64;
  if ( this->InitActionTags.Data.Size && (this->InitActionTags.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v12 = this->InitActionTags.Data.Data;
    if ( v12 )
    {
      v13 = (Scaleform::GFx::ExecuteTag **)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(
                                             Scaleform::Memory::pGlobalHeap,
                                             v12,
                                             256i64);
    }
    else
    {
      v14 = 2;
      v13 = (Scaleform::GFx::ExecuteTag **)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                             Scaleform::Memory::pGlobalHeap,
                                             256i64,
                                             &v14);
    }
    this->InitActionTags.Data.Data = v13;
    this->InitActionTags.Data.Policy.Capacity = 32i64;
  }
  this->InitActionTags.Data.Size = 0i64;
}

// File Line: 372
// RVA: 0x8B04C0
Scaleform::GFx::ResourceHandle *__fastcall Scaleform::GFx::LoadProcess::AddDataResource(
        Scaleform::GFx::LoadProcess *this,
        Scaleform::GFx::ResourceHandle *result,
        unsigned int *rid,
        Scaleform::GFx::ResourceData *resData)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // rsi
  Scaleform::GFx::ResourceDataNode *v8; // rbx
  Scaleform::GFx::ResourceId rida; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::GFx::ResourceHandle *v11; // [rsp+58h] [rbp+10h]

  v11 = result;
  rida.Id = *rid;
  Scaleform::GFx::MovieDataDef::LoadTaskData::AddNewResourceHandle(
    this->pLoadData.pObject,
    result,
    (Scaleform::GFx::ResourceId)&rida);
  pObject = this->pLoadData.pObject;
  v8 = Scaleform::GFx::MovieDataDef::LoadTaskData::AllocMovieDefClass<Scaleform::GFx::ResourceDataNode>(pObject);
  if ( v8 )
  {
    if ( resData->pInterface )
      resData->pInterface->vfptr->AddRef(resData->pInterface, resData->hData);
    if ( v8->Data.pInterface )
      v8->Data.pInterface->vfptr->Release(v8->Data.pInterface, v8->Data.hData);
    v8->Data.pInterface = resData->pInterface;
    v8->Data.hData = resData->hData;
    v8->BindIndex = result->BindIndex;
    if ( !this->pResourceData )
      this->pResourceData = v8;
    if ( pObject->BindData.pResourceNodes.Value )
      pObject->BindData.pResourceNodesLast->pNext.Value = v8;
    else
      pObject->BindData.pResourceNodes.Value = v8;
    pObject->BindData.pResourceNodesLast = v8;
    ++this->ResourceDataCount;
  }
  return result;
}

// File Line: 400
// RVA: 0x159C300
__int64 Scaleform::GFx::_dynamic_initializer_for__static_inst__()
{
  static_inst.vfptr = (Scaleform::GFx::ResourceData::DataInterfaceVtbl *)&Scaleform::GFx::FontResourceCreator::`vftable;
  return atexit((int (__fastcall *)())Scaleform::GFx::_dynamic_atexit_destructor_for__static_inst__);
}

// File Line: 402
// RVA: 0x8B0F40
Scaleform::GFx::ResourceHandle *__fastcall Scaleform::GFx::LoadProcess::AddFontDataResource(
        Scaleform::GFx::LoadProcess *this,
        Scaleform::GFx::ResourceHandle *result,
        unsigned int *rid,
        Scaleform::GFx::Resource *pfontData)
{
  Scaleform::GFx::FontDataUseNode *v8; // rax
  Scaleform::GFx::FontDataUseNode *v9; // rbx
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // rsi
  Scaleform::Render::RenderBuffer *v11; // rcx
  Scaleform::GFx::ResourceData resData; // [rsp+30h] [rbp-38h] BYREF
  Scaleform::GFx::ResourceId rida; // [rsp+70h] [rbp+8h] BYREF
  Scaleform::GFx::ResourceHandle *v15; // [rsp+78h] [rbp+10h]

  v15 = result;
  static_inst.vfptr->AddRef(&static_inst, pfontData);
  resData.pInterface = &static_inst;
  resData.hData = pfontData;
  rida.Id = *rid;
  Scaleform::GFx::LoadProcess::AddDataResource(this, result, &rida.Id, &resData);
  v8 = Scaleform::GFx::MovieDataDef::LoadTaskData::AllocMovieDefClass<Scaleform::GFx::FontDataUseNode>(this->pLoadData.pObject);
  v9 = v8;
  if ( v8 )
  {
    pObject = this->pLoadData.pObject;
    v8->Id.Id = *rid;
    if ( pfontData )
      Scaleform::Render::RenderBuffer::AddRef(pfontData);
    v11 = (Scaleform::Render::RenderBuffer *)v9->pFontData.pObject;
    if ( v11 )
      Scaleform::RefCountImpl::Release(v11);
    v9->pFontData.pObject = (Scaleform::Render::Font *)pfontData;
    v9->BindIndex = result->BindIndex;
    if ( !this->pFontData )
      this->pFontData = v9;
    if ( pObject->BindData.pFonts.Value )
      pObject->BindData.pFontsLast->pNext.Value = v9;
    else
      pObject->BindData.pFonts.Value = v9;
    pObject->BindData.pFontsLast = v9;
    ++this->FontDataCount;
  }
  static_inst.vfptr->Release(&static_inst, pfontData);
  return result;
}

// File Line: 457
// RVA: 0x8B14E0
void __fastcall Scaleform::GFx::LoadProcess::AddImageResource(
        Scaleform::GFx::LoadProcess *this,
        int *rid,
        Scaleform::Render::ImageSource *pimage)
{
  Scaleform::GFx::MovieDefBindStates *pObject; // rax
  Scaleform::GFx::ImageCreator *v6; // rcx
  Scaleform::MemoryHeap *pHeap; // rdx
  Scaleform::Render::Image *v8; // rdi
  Scaleform::GFx::ImageResource *v9; // rax
  Scaleform::GFx::Resource *v10; // rax
  Scaleform::GFx::Resource *v11; // rbx
  int v12; // eax
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::MemoryHeap *v14; // rbx
  Scaleform::Render::Image *v15; // r15
  Scaleform::Render::WrapperImageSource *v16; // rax
  Scaleform::Render::ImageSource *v17; // rax
  Scaleform::Render::ImageSource *v18; // rdi
  Scaleform::GFx::Resource *pResource; // rbx
  Scaleform::GFx::ResourceLibBase *v20; // rcx
  Scaleform::RefCountImplCore v21; // [rsp+20h] [rbp-E0h] BYREF
  int v22; // [rsp+30h] [rbp-D0h]
  Scaleform::Render::RenderBuffer *v23; // [rsp+38h] [rbp-C8h]
  int v24; // [rsp+40h] [rbp-C0h]
  Scaleform::GFx::ResourceData result; // [rsp+48h] [rbp-B8h] BYREF
  Scaleform::GFx::ResourceHandle v26; // [rsp+58h] [rbp-A8h] BYREF
  int v27; // [rsp+68h] [rbp-98h] BYREF
  Scaleform::MemoryHeap *v28; // [rsp+70h] [rbp-90h]
  int v29; // [rsp+78h] [rbp-88h]
  int v30; // [rsp+7Ch] [rbp-84h]
  __int64 v31; // [rsp+80h] [rbp-80h]
  __int64 v32; // [rsp+88h] [rbp-78h]
  __int64 v33; // [rsp+90h] [rbp-70h]
  __int64 v34; // [rsp+98h] [rbp-68h]
  int v35; // [rsp+A0h] [rbp-60h] BYREF
  Scaleform::MemoryHeap *v36; // [rsp+A8h] [rbp-58h]
  __int64 v37; // [rsp+B0h] [rbp-50h]
  __int64 v38; // [rsp+B8h] [rbp-48h]
  int v39; // [rsp+C0h] [rbp-40h]
  int v40; // [rsp+C8h] [rbp-38h]
  Scaleform::MemoryHeap *v41; // [rsp+D0h] [rbp-30h]
  int v42; // [rsp+D8h] [rbp-28h]
  int v43; // [rsp+DCh] [rbp-24h]
  __int64 v44; // [rsp+E0h] [rbp-20h]
  __int64 v45; // [rsp+E8h] [rbp-18h]
  __int64 v46; // [rsp+F0h] [rbp-10h]
  __int64 v47; // [rsp+F8h] [rbp-8h]
  Scaleform::Render::ImageSource *v48; // [rsp+100h] [rbp+0h]
  __int64 v49; // [rsp+108h] [rbp+8h]
  Scaleform::Render::Image *v50; // [rsp+110h] [rbp+10h]
  Scaleform::Render::Image *v51; // [rsp+118h] [rbp+18h]
  Scaleform::GFx::Resource *v52; // [rsp+120h] [rbp+20h]
  Scaleform::GFx::ImageResource *rida; // [rsp+180h] [rbp+80h] BYREF
  Scaleform::Render::WrapperImageSource *v54; // [rsp+188h] [rbp+88h] BYREF

  if ( pimage )
  {
    v49 = -2i64;
    if ( SLOBYTE(this->LoadFlags) >= 0
      && (pObject = this->pLoadStates.pObject->pBindStates.pObject, pObject->pImageCreator.pObject)
      && (v6 = pObject->pImageCreator.pObject) != 0i64 )
    {
      pHeap = this->pLoadData.pObject->pHeap;
      v27 = 1;
      v28 = pHeap;
      v29 = 1;
      v30 = 1;
      v31 = 0i64;
      v32 = 0i64;
      v33 = 0i64;
      v34 = 0i64;
      v8 = (Scaleform::Render::Image *)v6->vfptr[4].__vecDelDtor(v6, (unsigned int)&v27);
      v50 = v8;
      v9 = (Scaleform::GFx::ImageResource *)v28->vfptr->Alloc(v28, 104ui64, 0i64);
      rida = v9;
      if ( v9 )
      {
        Scaleform::GFx::ImageResource::ImageResource(v9, v8, Use_Bitmap);
        v11 = v10;
      }
      else
      {
        v11 = 0i64;
      }
      v52 = v11;
      v12 = *rid;
      v24 = *rid;
      if ( this->LoadState == LS_LoadingRoot )
      {
        LODWORD(rida) = v12;
        Scaleform::GFx::MovieDataDef::LoadTaskData::AddResource(
          this->pLoadData.pObject,
          (Scaleform::GFx::ResourceId)&rida,
          v11);
      }
      if ( v11 && !_InterlockedDecrement(&v11->RefCount.Value) )
      {
        pLib = v11->pLib;
        if ( pLib )
        {
          pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)v11);
          v11->pLib = 0i64;
        }
        v11->vfptr->__vecDelDtor(v11, 1u);
      }
      if ( v8 )
        ((void (__fastcall *)(Scaleform::Render::Image *))v8->vfptr[2].__vecDelDtor)(v8);
    }
    else
    {
      v14 = this->pLoadData.pObject->pHeap;
      v40 = 1;
      v41 = v14;
      v42 = 1;
      v43 = 1;
      v44 = 0i64;
      v45 = 0i64;
      v46 = 0i64;
      v47 = 0i64;
      v21.RefCount = 1;
      v22 = 14;
      v21.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ImageCreator::`vftable;
      v23 = 0i64;
      v38 = 0i64;
      v39 = 0;
      v36 = v14;
      v35 = 1;
      v37 = 0i64;
      v15 = (Scaleform::Render::Image *)pimage->vfptr[12].__vecDelDtor(pimage, &v35);
      v51 = v15;
      v16 = (Scaleform::Render::WrapperImageSource *)v14->vfptr->Alloc(v14, 24ui64, 0i64);
      v54 = v16;
      if ( v16 )
      {
        Scaleform::Render::WrapperImageSource::WrapperImageSource(v16, v15);
        v18 = v17;
      }
      else
      {
        v18 = 0i64;
      }
      v48 = v18;
      Scaleform::GFx::ImageResourceCreator::CreateImageResourceData(&result, v18);
      LODWORD(v54) = *rid;
      Scaleform::GFx::LoadProcess::AddDataResource(this, &v26, (unsigned int *)&v54, &result);
      if ( v26.HType == RH_Pointer )
      {
        pResource = v26.pResource;
        if ( v26.pResource )
        {
          if ( !_InterlockedDecrement(&v26.pResource->RefCount.Value) )
          {
            v20 = pResource->pLib;
            if ( v20 )
            {
              v20->vfptr[1].__vecDelDtor(v20, (unsigned int)pResource);
              pResource->pLib = 0i64;
            }
            pResource->vfptr->__vecDelDtor(pResource, 1u);
          }
        }
      }
      if ( result.pInterface )
        result.pInterface->vfptr->Release(result.pInterface, result.hData);
      if ( v18 )
        ((void (__fastcall *)(Scaleform::Render::ImageSource *))v18->vfptr[2].__vecDelDtor)(v18);
      if ( v15 )
        ((void (__fastcall *)(Scaleform::Render::Image *))v15->vfptr[2].__vecDelDtor)(v15);
      if ( v23 )
        Scaleform::RefCountImpl::Release(v23);
      v21.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::State::`vftable;
      Scaleform::RefCountImplCore::~RefCountImplCore(&v21);
    }
  }
}

// File Line: 489
// RVA: 0x8BFD50
Scaleform::GFx::FrameBindData *__fastcall Scaleform::GFx::LoadProcess::CreateFrameBindData(
        Scaleform::GFx::LoadProcess *this)
{
  Scaleform::GFx::FrameBindData *result; // rax

  result = Scaleform::GFx::MovieDataDef::LoadTaskData::AllocMovieDefClass<Scaleform::GFx::FrameBindData>(this->pLoadData.pObject);
  if ( result )
  {
    result->ImportCount = this->ImportDataCount;
    result->pImportData = this->pImportData;
    result->FontCount = this->FontDataCount;
    result->pFontData = this->pFontData;
    result->ResourceCount = this->ResourceDataCount;
    result->pResourceData = this->pResourceData;
    *(_QWORD *)&this->ImportDataCount = 0i64;
    this->FontDataCount = 0;
    this->pImportData = 0i64;
    this->pResourceData = 0i64;
    this->pFontData = 0i64;
  }
  return result;
}

// File Line: 523
// RVA: 0x8C2CE0
__int64 __fastcall Scaleform::GFx::ImageFileResourceCreator::CreateResource(
        Scaleform::GFx::ImageFileResourceCreator *this,
        unsigned __int16 *hdata,
        Scaleform::GFx::ResourceBindData *pbindData,
        Scaleform::GFx::LoadStates *pls)
{
  Scaleform::GFx::ResourceBindData *v5; // rdi
  Scaleform::GFx::ResourceFileInfo *v7; // rax
  __int64 v8; // rsi
  Scaleform::GFx::Resource *v9; // rbx
  _DWORD *v10; // rax
  Scaleform::GFx::URLBuilder *pObject; // rcx
  Scaleform::Render::Image *v12; // rdi
  Scaleform::GFx::MovieDefBindStates *v13; // r8
  __int64 v14; // rcx
  int v15; // eax
  Scaleform::GFx::ImageFileHandlerRegistry *v16; // rbx
  Scaleform::GFx::FileOpener *v17; // rdi
  Scaleform::GFx::LogState *GlobalLog; // rax
  int v19; // edx
  Scaleform::GFx::ImageFileHandlerRegistry *v20; // rdi
  __int64 v21; // rdx
  Scaleform::GFx::LogState *v22; // rax
  Scaleform::Log *v23; // rax
  __m128 v24; // xmm3
  __m128 v25; // xmm2
  Scaleform::GFx::ImageResource *v26; // rax
  Scaleform::GFx::Resource *v27; // rax
  const char *v28; // rdx
  unsigned __int8 v29; // di
  Scaleform::GFx::Resource *v30; // rbx
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  __int64 v32; // rbx
  Scaleform::GFx::ResourceLibBase *v33; // rcx
  Scaleform::GFx::Resource *pResource; // rbx
  Scaleform::GFx::ResourceLibBase *v35; // rcx
  Scaleform::GFx::ResourceLib::BindHandle phandle; // [rsp+30h] [rbp-D0h] BYREF
  __int64 v38; // [rsp+40h] [rbp-C0h] BYREF
  Scaleform::Render::Image *pimage; // [rsp+48h] [rbp-B8h]
  __m128 v40; // [rsp+50h] [rbp-B0h] BYREF
  __m128 v41; // [rsp+60h] [rbp-A0h]
  Scaleform::MemoryHeap *pimageHeap; // [rsp+70h] [rbp-90h]
  __int64 v43; // [rsp+78h] [rbp-88h]
  Scaleform::GFx::ResourceKey result; // [rsp+80h] [rbp-80h] BYREF
  Scaleform::GFx::URLBuilder::LocationInfo loc; // [rsp+90h] [rbp-70h] BYREF
  int v46; // [rsp+A8h] [rbp-58h] BYREF
  Scaleform::MemoryHeap *v47; // [rsp+B0h] [rbp-50h]
  int v48; // [rsp+B8h] [rbp-48h]
  int v49; // [rsp+BCh] [rbp-44h]
  Scaleform::Log *v50; // [rsp+C0h] [rbp-40h]
  __int64 v51; // [rsp+C8h] [rbp-38h]
  Scaleform::GFx::ImageFileHandlerRegistry *v52; // [rsp+D0h] [rbp-30h]
  __int64 v53; // [rsp+D8h] [rbp-28h]
  int v54; // [rsp+E0h] [rbp-20h] BYREF
  Scaleform::MemoryHeap *v55; // [rsp+E8h] [rbp-18h]
  int v56; // [rsp+F0h] [rbp-10h]
  int v57; // [rsp+F4h] [rbp-Ch]
  Scaleform::GFx::LogState *v58; // [rsp+F8h] [rbp-8h]
  __int128 v59; // [rsp+100h] [rbp+0h]
  __int64 v60; // [rsp+110h] [rbp+10h]
  Scaleform::Render::ImageFileFormat v61; // [rsp+118h] [rbp+18h]
  __int64 v62; // [rsp+120h] [rbp+20h]
  Scaleform::String v63; // [rsp+128h] [rbp+28h] BYREF
  int v64; // [rsp+130h] [rbp+30h]
  int v65; // [rsp+134h] [rbp+34h]
  Scaleform::MemoryHeap *v66; // [rsp+140h] [rbp+40h]
  __int64 v67; // [rsp+148h] [rbp+48h]
  __int64 v68; // [rsp+150h] [rbp+50h]
  Scaleform::String v69; // [rsp+1A8h] [rbp+A8h] BYREF
  Scaleform::GFx::ResourceBindData *v70; // [rsp+1B0h] [rbp+B0h]
  Scaleform::GFx::Resource *v71; // [rsp+1B8h] [rbp+B8h]

  v70 = pbindData;
  v68 = -2i64;
  v5 = pbindData;
  v7 = (Scaleform::GFx::ResourceFileInfo *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                             Scaleform::Memory::pGlobalHeap,
                                             56i64);
  v8 = (__int64)v7;
  v71 = (Scaleform::GFx::Resource *)v7;
  v9 = 0i64;
  if ( v7 )
  {
    Scaleform::GFx::ResourceFileInfo::ResourceFileInfo(v7, (Scaleform::GFx::ResourceFileInfo *)hdata);
    *(_QWORD *)v8 = &Scaleform::GFx::ImageFileInfo::`vftable;
    Scaleform::String::String((Scaleform::String *)(v8 + 48));
    *(_WORD *)(v8 + 40) = hdata[20];
    *(_WORD *)(v8 + 42) = hdata[21];
    *(_DWORD *)(v8 + 44) = *((_DWORD *)hdata + 11);
  }
  else
  {
    v8 = 0i64;
  }
  v67 = v8;
  if ( *(_DWORD *)(v8 + 16) == 1 )
  {
    v10 = *(_DWORD **)(v8 + 24);
    if ( v10 )
      *(_DWORD *)(v8 + 16) = *v10;
  }
  loc.Use = File_ImageImport;
  Scaleform::String::String(&loc.FileName, (Scaleform::String *)hdata + 4);
  Scaleform::String::String(&loc.ParentPath, &pls->RelativePath);
  pObject = pls->pBindStates.pObject->pURLBulider.pObject;
  if ( pObject )
    ((void (__fastcall *)(Scaleform::GFx::URLBuilder *, __int64, Scaleform::GFx::URLBuilder::LocationInfo *))pObject->vfptr[1].__vecDelDtor)(
      pObject,
      v8 + 32,
      &loc);
  else
    Scaleform::GFx::URLBuilder::DefaultBuildURL((Scaleform::String *)(v8 + 32), &loc);
  pimageHeap = pls->pWeakResourceLib.pObject->pImageHeap.pObject;
  v66 = pimageHeap;
  Scaleform::GFx::ImageResource::CreateImageFileKey(
    &result,
    (Scaleform::GFx::ImageFileInfo *)v8,
    (Scaleform::GFx::Resource *)pls->pBindStates.pObject->pFileOpener.pObject,
    (Scaleform::GFx::Resource *)pls->pBindStates.pObject->pImageCreator.pObject,
    pimageHeap);
  Scaleform::String::String(&v69);
  phandle.State = RS_Unbound;
  phandle.pResource = 0i64;
  v71 = 0i64;
  if ( (unsigned int)Scaleform::GFx::ResourceWeakLib::BindResourceKey(pls->pWeakResourceLib.pObject, &phandle, &result) == 3 )
  {
    v12 = 0i64;
    pimage = 0i64;
    v13 = pls->pBindStates.pObject;
    v14 = (__int64)v13->pImageCreator.pObject;
    v38 = v14;
    if ( !v14 )
      goto LABEL_30;
    v15 = *((_DWORD *)hdata + 11);
    if ( *((_QWORD *)hdata + 3) )
    {
      v54 = 2;
      v55 = pimageHeap;
      v56 = 0;
      v57 = v15;
      v58 = 0i64;
      v59 = 0i64;
      v60 = 0i64;
      Scaleform::String::String(&v63);
      v16 = pls->pImageFileHandlerRegistry.pObject;
      v17 = pls->pBindStates.pObject->pFileOpener.pObject;
      GlobalLog = pls->pLog.pObject;
      if ( GlobalLog )
      {
        GlobalLog = (Scaleform::GFx::LogState *)GlobalLog->pLog.pObject;
        if ( !GlobalLog )
          GlobalLog = (Scaleform::GFx::LogState *)Scaleform::Log::GetGlobalLog();
      }
      *(_QWORD *)&v59 = v17;
      v58 = GlobalLog;
      *((_QWORD *)&v59 + 1) = v16;
      v62 = *((_QWORD *)hdata + 3);
      v61 = Scaleform::GFx::LoaderImpl::FileFormat2RenderImageFile(*((Scaleform::GFx::FileTypeConstants::FileFormatType *)hdata
                                                                   + 4));
      v19 = hdata[21];
      v64 = hdata[20];
      v65 = v19;
      Scaleform::String::operator=(&v63, (Scaleform::String *)hdata + 6);
      pimage = (Scaleform::Render::Image *)(*(__int64 (__fastcall **)(__int64, int *, __int64))(*(_QWORD *)v38 + 24i64))(
                                             v38,
                                             &v54,
                                             v8 + 32);
      if ( !_InterlockedDecrement((volatile signed __int32 *)((v63.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v9 = v71;
      v12 = pimage;
    }
    else
    {
      v46 = 1;
      v47 = pimageHeap;
      v48 = 0;
      v49 = v15;
      v50 = 0i64;
      v51 = 0i64;
      v52 = 0i64;
      v53 = 0i64;
      v20 = pls->pImageFileHandlerRegistry.pObject;
      v21 = (__int64)v13->pFileOpener.pObject;
      v43 = v21;
      v22 = pls->pLog.pObject;
      if ( v22 )
      {
        v23 = v22->pLog.pObject;
        if ( !v23 )
        {
          v23 = Scaleform::Log::GetGlobalLog();
          v14 = v38;
          v21 = v43;
        }
      }
      else
      {
        v23 = 0i64;
      }
      v51 = v21;
      v50 = v23;
      v52 = v20;
      v12 = (Scaleform::Render::Image *)(*(__int64 (__fastcall **)(__int64, int *, __int64))(*(_QWORD *)v14 + 16i64))(
                                          v14,
                                          &v46,
                                          v8 + 32);
      pimage = v12;
    }
    if ( !v12 )
      goto LABEL_30;
    v40 = (__m128)_xmm;
    v41 = _xmm;
    v12->vfptr[5].__vecDelDtor(v12, (unsigned int)&v38);
    v24 = (__m128)COERCE_UNSIGNED_INT((float)hdata[21]);
    v24.m128_f32[0] = v24.m128_f32[0] / (float)SHIDWORD(v38);
    v25 = (__m128)COERCE_UNSIGNED_INT((float)hdata[20]);
    v25.m128_f32[0] = v25.m128_f32[0] / (float)(int)v38;
    v40 = _mm_mul_ps(v40, _mm_shuffle_ps(v25, v25, 0));
    v41 = _mm_mul_ps(v41, _mm_shuffle_ps(v24, v24, 0));
    ((void (__fastcall *)(Scaleform::Render::Image *, __m128 *, _QWORD))v12->vfptr[13].__vecDelDtor)(v12, &v40, 0i64);
    v26 = (Scaleform::GFx::ImageResource *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))pimageHeap->vfptr->Alloc)(
                                             pimageHeap,
                                             104i64);
    v43 = (__int64)v26;
    if ( v26 )
    {
      Scaleform::GFx::ImageResource::ImageResource(
        v26,
        v12,
        &result,
        *((Scaleform::GFx::Resource::ResourceUse *)hdata + 11));
      v9 = v27;
    }
    else
    {
      v9 = 0i64;
    }
    v71 = v9;
    if ( v9 )
    {
      Scaleform::GFx::ResourceLib::ResourceSlot::Resolve(phandle.pSlot, v9);
    }
    else
    {
LABEL_30:
      Scaleform::String::operator=(&v69, "Failed to load image ");
      Scaleform::String::operator+=(&v69, (Scaleform::String *)(v8 + 32));
      Scaleform::String::AppendString(&v69, "", -1i64);
      Scaleform::GFx::ResourceLib::ResourceSlot::CancelResolve(
        phandle.pSlot,
        (const char *)((v69.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
    }
    if ( v12 )
      ((void (__fastcall *)(Scaleform::Render::Image *))v12->vfptr[2].__vecDelDtor)(v12);
    v5 = v70;
  }
  else
  {
    v9 = Scaleform::GFx::ResourceLib::BindHandle::WaitForResolve(&phandle);
    v71 = v9;
    if ( v9 )
      goto LABEL_41;
    if ( phandle.State < RS_WaitingResolve )
      v28 = &customCaption;
    else
      v28 = (const char *)((*(_QWORD *)&phandle.pResource[2].RefCount.Value & 0xFFFFFFFFFFFFFFFCui64) + 12);
    Scaleform::String::operator=(&v69, v28);
  }
  if ( !v9 )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
      &pls->pLog.pObject->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
      "%s",
      (const char *)((v69.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
    v29 = 0;
    goto LABEL_47;
  }
LABEL_41:
  _InterlockedExchangeAdd(&v9->RefCount.Value, 1u);
  v30 = v5->pResource.pObject;
  if ( v5->pResource.pObject && !_InterlockedDecrement(&v30->RefCount.Value) )
  {
    pLib = v30->pLib;
    if ( pLib )
    {
      pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)v30);
      v30->pLib = 0i64;
    }
    v30->vfptr->__vecDelDtor(v30, 1u);
  }
  v9 = v71;
  v5->pResource.pObject = v71;
  v29 = 1;
LABEL_47:
  if ( v9 && !_InterlockedDecrement(&v9->RefCount.Value) )
  {
    v32 = (__int64)v71;
    v33 = v71->pLib;
    if ( v33 )
    {
      v33->vfptr[1].__vecDelDtor(v33, (unsigned int)v71);
      *(_QWORD *)(v32 + 16) = 0i64;
    }
    (**(void (__fastcall ***)(__int64, __int64))v32)(v32, 1i64);
  }
  if ( phandle.State == RS_Available )
  {
    if ( !_InterlockedDecrement(&phandle.pResource->RefCount.Value) )
    {
      pResource = phandle.pResource;
      v35 = phandle.pResource->pLib;
      if ( v35 )
      {
        v35->vfptr[1].__vecDelDtor(v35, (unsigned int)phandle.pResource);
        pResource->pLib = 0i64;
      }
      pResource->vfptr->__vecDelDtor(pResource, 1u);
    }
  }
  else if ( phandle.State >= RS_WaitingResolve )
  {
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)phandle.pResource);
  }
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v69.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( result.pKeyInterface )
    result.pKeyInterface->vfptr->Release(result.pKeyInterface, result.hKeyData);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((loc.ParentPath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( _InterlockedExchangeAdd(
         (volatile signed __int32 *)((loc.FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8),
         0xFFFFFFFF) == 1 )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v8);
  return v29;
}

// File Line: 633
// RVA: 0x8C0000
Scaleform::GFx::ResourceData *__fastcall Scaleform::GFx::ImageFileResourceCreator::CreateImageFileResourceData(
        Scaleform::GFx::ResourceData *result,
        Scaleform::GFx::ImageFileInfo *prfi)
{
  if ( (_S13_10 & 1) == 0 )
  {
    _S13_10 |= 1u;
    inst.vfptr = (Scaleform::GFx::ResourceData::DataInterfaceVtbl *)&Scaleform::GFx::ImageFileResourceCreator::`vftable;
    atexit(Scaleform::GFx::ImageFileResourceCreator::CreateImageFileResourceData_::_2_::_dynamic_atexit_destructor_for__inst__);
  }
  inst.vfptr->AddRef(&inst, prfi);
  result->pInterface = &inst;
  result->hData = prfi;
  return result;
}

// File Line: 643
// RVA: 0x8C3300
char __fastcall Scaleform::GFx::ImageResourceCreator::CreateResource(
        Scaleform::GFx::ImageResourceCreator *this,
        void *hdata,
        Scaleform::GFx::ResourceBindData *pbindData,
        Scaleform::GFx::LoadStates *pls,
        Scaleform::MemoryHeap *pbindHeap)
{
  Scaleform::GFx::ImageFileHandlerRegistry *pObject; // rsi
  Scaleform::GFx::FileOpener *v9; // rbp
  Scaleform::GFx::LogState *v10; // rax
  Scaleform::Log *GlobalLog; // rax
  Scaleform::GFx::ImageCreator *v12; // rcx
  Scaleform::Render::Image *v14; // r14
  char v15; // si
  Scaleform::GFx::ImageResource *v16; // rax
  Scaleform::GFx::Resource *v17; // rax
  Scaleform::GFx::Resource *v18; // rdi
  Scaleform::GFx::Resource *v19; // rsi
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::GFx::ResourceLibBase *v21; // rcx
  int v22; // [rsp+28h] [rbp-60h] BYREF
  Scaleform::MemoryHeap *v23; // [rsp+30h] [rbp-58h]
  __int64 v24; // [rsp+38h] [rbp-50h]
  Scaleform::Log *v25; // [rsp+40h] [rbp-48h]
  Scaleform::GFx::FileOpener *v26; // [rsp+48h] [rbp-40h]
  Scaleform::GFx::ImageFileHandlerRegistry *v27; // [rsp+50h] [rbp-38h]
  __int64 v28; // [rsp+58h] [rbp-30h]

  v22 = 1;
  v23 = pbindHeap;
  v24 = 0i64;
  v25 = 0i64;
  v26 = 0i64;
  v27 = 0i64;
  v28 = 0i64;
  pObject = pls->pImageFileHandlerRegistry.pObject;
  v9 = pls->pBindStates.pObject->pFileOpener.pObject;
  v10 = pls->pLog.pObject;
  if ( v10 )
  {
    GlobalLog = v10->pLog.pObject;
    if ( !GlobalLog )
      GlobalLog = Scaleform::Log::GetGlobalLog();
  }
  else
  {
    GlobalLog = 0i64;
  }
  v26 = v9;
  v25 = GlobalLog;
  v27 = pObject;
  v23 = pbindHeap;
  v12 = pls->pBindStates.pObject->pImageCreator.pObject;
  if ( !v12 )
    return 0;
  v14 = (Scaleform::Render::Image *)((__int64 (__fastcall *)(Scaleform::GFx::ImageCreator *, int *, void *))v12->vfptr[4].__vecDelDtor)(
                                      v12,
                                      &v22,
                                      hdata);
  if ( v14 )
  {
    v16 = (Scaleform::GFx::ImageResource *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))pbindHeap->vfptr->Alloc)(
                                             pbindHeap,
                                             104i64);
    if ( v16 )
    {
      Scaleform::GFx::ImageResource::ImageResource(v16, v14, Use_Bitmap);
      v18 = v17;
    }
    else
    {
      v18 = 0i64;
    }
    if ( v18 )
    {
      _InterlockedExchangeAdd(&v18->RefCount.Value, 1u);
      v19 = pbindData->pResource.pObject;
      if ( pbindData->pResource.pObject && !_InterlockedDecrement(&v19->RefCount.Value) )
      {
        pLib = v19->pLib;
        if ( pLib )
        {
          pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)v19);
          v19->pLib = 0i64;
        }
        v19->vfptr->__vecDelDtor(v19, 1u);
      }
      pbindData->pResource.pObject = v18;
      v15 = 1;
    }
    else
    {
      v15 = 0;
    }
    if ( v18 && !_InterlockedDecrement(&v18->RefCount.Value) )
    {
      v21 = v18->pLib;
      if ( v21 )
      {
        v21->vfptr[1].__vecDelDtor(v21, (unsigned int)v18);
        v18->pLib = 0i64;
      }
      v18->vfptr->__vecDelDtor(v18, 1u);
    }
  }
  else
  {
    v15 = 0;
  }
  if ( v14 )
    ((void (__fastcall *)(Scaleform::Render::Image *))v14->vfptr[2].__vecDelDtor)(v14);
  return v15;
}

// File Line: 676
// RVA: 0x8C03A0
Scaleform::GFx::ResourceData *__fastcall Scaleform::GFx::ImageResourceCreator::CreateImageResourceData(
        Scaleform::GFx::ResourceData *result,
        Scaleform::Render::ImageSource *pimage)
{
  if ( (_S14_7 & 1) == 0 )
  {
    _S14_7 |= 1u;
    inst_0.vfptr = (Scaleform::GFx::ResourceData::DataInterfaceVtbl *)&Scaleform::GFx::ImageResourceCreator::`vftable;
    atexit(Scaleform::GFx::ImageResourceCreator::CreateImageResourceData_::_2_::_dynamic_atexit_destructor_for__inst__);
  }
  if ( pimage )
  {
    inst_0.vfptr->AddRef(&inst_0, pimage);
    result->pInterface = &inst_0;
    result->hData = pimage;
  }
  else
  {
    result->pInterface = 0i64;
    result->hData = 0i64;
  }
  return result;
}

// File Line: 688
// RVA: 0x8C34C0
char __fastcall Scaleform::GFx::SubImageResourceCreator::CreateResource(
        Scaleform::GFx::SubImageResourceCreator *this,
        void *hdata,
        Scaleform::GFx::ResourceBindData *pbindData,
        Scaleform::GFx::LoadStates *pls,
        Scaleform::MemoryHeap *pbindHeap)
{
  Scaleform::GFx::ImageResource *v7; // rdi
  __int64 v8; // rdx
  Scaleform::GFx::Resource *Resource; // rax
  Scaleform::GFx::ImageResource *v10; // rsi
  Scaleform::GFx::Resource *pResource; // rsi
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::GFx::SubImageResource *v14; // rax
  Scaleform::GFx::Resource *v15; // rax
  Scaleform::GFx::Resource *v16; // rsi
  Scaleform::GFx::Resource *pObject; // rdi
  Scaleform::GFx::ResourceLibBase *v18; // rcx
  Scaleform::GFx::ResourceId baseid; // [rsp+30h] [rbp-48h] BYREF
  int v20; // [rsp+34h] [rbp-44h]
  __int64 v21; // [rsp+38h] [rbp-40h]
  Scaleform::GFx::SubImageResource *v22; // [rsp+40h] [rbp-38h]
  Scaleform::GFx::ResourceHandle v23; // [rsp+48h] [rbp-30h] BYREF
  int v24; // [rsp+88h] [rbp+10h] BYREF

  v21 = -2i64;
  v7 = (Scaleform::GFx::ImageResource *)*((_QWORD *)hdata + 3);
  if ( !v7 )
  {
    v23.HType = RH_Pointer;
    v23.pResource = 0i64;
    v20 = *((_DWORD *)hdata + 4);
    v8 = *(_QWORD *)(*(_QWORD *)&pbindData->pBinding->pOwnerDefRes[4].RefCount.Value + 24i64);
    v24 = v20;
    Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(
      *(Scaleform::GFx::MovieDataDef::LoadTaskData **)(v8 + 64),
      &v23,
      (Scaleform::GFx::ResourceId)&v24);
    Resource = Scaleform::GFx::ResourceHandle::GetResource(&v23, pbindData->pBinding);
    v10 = (Scaleform::GFx::ImageResource *)Resource;
    if ( Resource
      && (((__int64 (__fastcall *)(Scaleform::GFx::Resource *))Resource->vfptr->GetResourceTypeCode)(Resource) & 0xFF00) == 256 )
    {
      v7 = v10;
    }
    if ( v23.HType == RH_Pointer && v23.pResource && !_InterlockedDecrement(&v23.pResource->RefCount.Value) )
    {
      pResource = v23.pResource;
      pLib = v23.pResource->pLib;
      if ( pLib )
      {
        pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)v23.pResource);
        pResource->pLib = 0i64;
      }
      pResource->vfptr->__vecDelDtor(pResource, 1u);
    }
    if ( !v7 )
      return 0;
  }
  v14 = (Scaleform::GFx::SubImageResource *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64, _QWORD, Scaleform::GFx::LoadStates *))pbindHeap->vfptr->Alloc)(
                                              pbindHeap,
                                              128i64,
                                              0i64,
                                              pls);
  v22 = v14;
  if ( v14 )
  {
    baseid.Id = 0;
    Scaleform::GFx::SubImageResource::SubImageResource(
      v14,
      v7,
      &baseid.Id,
      (Scaleform::Render::Rect<unsigned long> *)hdata + 2);
    v16 = v15;
  }
  else
  {
    v16 = 0i64;
  }
  pObject = pbindData->pResource.pObject;
  if ( pbindData->pResource.pObject && !_InterlockedDecrement(&pObject->RefCount.Value) )
  {
    v18 = pObject->pLib;
    if ( v18 )
    {
      v18->vfptr[1].__vecDelDtor(v18, (unsigned int)pObject);
      pObject->pLib = 0i64;
    }
    pObject->vfptr->__vecDelDtor(pObject, 1u);
  }
  pbindData->pResource.pObject = v16;
  return 1;
}

// File Line: 722
// RVA: 0x8C3FC0
Scaleform::GFx::ResourceData *__fastcall Scaleform::GFx::SubImageResourceCreator::CreateSubImageResourceData(
        Scaleform::GFx::ResourceData *result,
        Scaleform::GFx::SubImageResourceInfo *pinfo)
{
  if ( (_S15_7 & 1) == 0 )
  {
    _S15_7 |= 1u;
    inst_1.vfptr = (Scaleform::GFx::ResourceData::DataInterfaceVtbl *)&Scaleform::GFx::SubImageResourceCreator::`vftable;
    atexit(Scaleform::GFx::SubImageResourceCreator::CreateSubImageResourceData_::_2_::_dynamic_atexit_destructor_for__inst__);
  }
  inst_1.vfptr->AddRef(&inst_1, pinfo);
  result->pInterface = &inst_1;
  result->hData = pinfo;
  return result;
}

// File Line: 734
// RVA: 0x8C2AE0
bool __fastcall Scaleform::GFx::FontResourceCreator::CreateResource(
        Scaleform::GFx::FontResourceCreator *this,
        Scaleform::GFx::Resource *hdata,
        Scaleform::GFx::ResourceBindData *pbindData,
        Scaleform::GFx::LoadStates *pls,
        Scaleform::MemoryHeap *pbindHeap)
{
  unsigned int v8; // ebp
  __int64 v9; // rcx
  Scaleform::GFx::MovieDefImpl *pObject; // r13
  Scaleform::GFx::FontDataUseNode *volatile Value; // rbx
  Scaleform::Render::Font *v12; // rsi
  int v13; // edi
  const char *v14; // rsi
  const char *v15; // rax
  unsigned int BindIndex; // r8d
  bool v18; // zf
  Scaleform::GFx::FontResource *v19; // rax
  Scaleform::GFx::Resource *v20; // rax
  Scaleform::GFx::Resource *v21; // rdi
  Scaleform::GFx::Resource *v22; // rbx
  Scaleform::GFx::ResourceLibBase *pLib; // rcx

  v8 = 0;
  if ( pls->SubstituteFontMovieDefs.Data.Size )
  {
    v9 = 0i64;
    while ( 1 )
    {
      pObject = pls->SubstituteFontMovieDefs.Data.Data[v9].pObject;
      Value = pObject->pBindData.pObject->pDataDef.pObject->pData.pObject->BindData.pFonts.Value;
      if ( Value )
        break;
LABEL_8:
      v9 = ++v8;
      if ( v8 >= pls->SubstituteFontMovieDefs.Data.Size )
        goto LABEL_15;
    }
    while ( 1 )
    {
      v12 = Value->pFontData.pObject;
      if ( ((unsigned int (__fastcall *)(Scaleform::Render::Font *))v12->vfptr[18].__vecDelDtor)(v12) )
      {
        v13 = v12->Flags & 0x303;
        v14 = (const char *)((__int64 (__fastcall *)(Scaleform::Render::Font *))v12->vfptr[1].__vecDelDtor)(v12);
        if ( (HIDWORD(hdata[1].vfptr) & (v13 & 0x10 | ((v13 & 0x300) != 0 ? 0x300 : 0) | 3)) == (v13 & 0x313) )
        {
          v15 = (const char *)((__int64 (__fastcall *)(Scaleform::GFx::Resource *))hdata->vfptr->GetKey)(hdata);
          if ( !Scaleform::String::CompareNoCase(v15, v14) )
            break;
        }
      }
      Value = Value->pNext.Value;
      if ( !Value )
        goto LABEL_8;
    }
    BindIndex = Value->BindIndex;
    if ( pObject->pBindData.pObject->ResourceBinding.Frozen
      && BindIndex < pObject->pBindData.pObject->ResourceBinding.ResourceCount )
    {
      Scaleform::GFx::ResourceBindData::operator=(
        pbindData,
        &pObject->pBindData.pObject->ResourceBinding.pResources[BindIndex]);
    }
    else
    {
      Scaleform::GFx::ResourceBinding::GetResourceData_Locked(
        &pObject->pBindData.pObject->ResourceBinding,
        pbindData,
        BindIndex);
    }
    return 1;
  }
  else
  {
LABEL_15:
    if ( !hdata->vfptr[4].GetResourceReport(hdata)
      && ((__int64 (__fastcall *)(Scaleform::GFx::Resource *))hdata->vfptr->GetKey)(hdata) )
    {
      HIDWORD(hdata[1].vfptr) |= 0x40u;
    }
    v18 = pbindData->pResource.pObject == 0i64;
    if ( !pbindData->pResource.pObject )
    {
      v19 = (Scaleform::GFx::FontResource *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))pbindHeap->vfptr->Alloc)(
                                              pbindHeap,
                                              64i64);
      if ( v19 )
      {
        Scaleform::GFx::FontResource::FontResource(v19, hdata, pbindData->pBinding);
        v21 = v20;
      }
      else
      {
        v21 = 0i64;
      }
      v22 = pbindData->pResource.pObject;
      if ( pbindData->pResource.pObject && !_InterlockedDecrement(&v22->RefCount.Value) )
      {
        pLib = v22->pLib;
        if ( pLib )
        {
          pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)v22);
          v22->pLib = 0i64;
        }
        v22->vfptr->__vecDelDtor(v22, 1u);
      }
      pbindData->pResource.pObject = v21;
      v18 = v21 == 0i64;
    }
    return !v18;
  }
}

