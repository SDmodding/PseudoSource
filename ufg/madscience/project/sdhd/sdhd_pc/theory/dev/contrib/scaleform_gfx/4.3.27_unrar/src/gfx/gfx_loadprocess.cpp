// File Line: 37
// RVA: 0x8995B0
void __fastcall Scaleform::GFx::LoadStates::LoadStates(Scaleform::GFx::LoadStates *this)
{
  Scaleform::GFx::LoadStates *v1; // rbx
  signed __int64 v2; // [rsp+48h] [rbp+10h]

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::LoadStates,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::LoadStates::`vftable';
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
  v1->ThreadedLoading = 0;
  v2 = (signed __int64)&v1->SubstituteFontMovieDefs;
  *(_OWORD *)v2 = 0ui64;
  *(_QWORD *)(v2 + 16) = 0i64;
}

// File Line: 44
// RVA: 0x899220
void __fastcall Scaleform::GFx::LoadStates::LoadStates(Scaleform::GFx::LoadStates *this, Scaleform::GFx::LoaderImpl *pimpl, Scaleform::GFx::StateBag *pstates, Scaleform::GFx::MovieDefBindStates *pbindStates)
{
  Scaleform::GFx::MovieDefBindStates *v4; // r15
  Scaleform::GFx::StateBag *v5; // rdi
  Scaleform::GFx::LoaderImpl *v6; // rbp
  Scaleform::GFx::LoadStates *v7; // rbx
  Scaleform::GFx::MovieDefBindStates *v8; // rsi
  Scaleform::Array<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,2,Scaleform::ArrayDefaultPolicy> *v9; // rax
  Scaleform::Render::RenderBuffer *v10; // rcx
  Scaleform::GFx::ResourceWeakLib *v11; // r14
  Scaleform::Render::RenderBuffer *v12; // rcx
  Scaleform::GFx::MovieDefBindStates *v13; // rax
  Scaleform::GFx::MovieDefBindStates *v14; // rax
  Scaleform::GFx::MovieDefBindStates *v15; // rax
  Scaleform::Render::RenderBuffer *v16; // rcx
  Scaleform::GFx::Resource **v17; // rsi
  Scaleform::Render::RenderBuffer *v18; // rcx
  Scaleform::GFx::Resource **v19; // rsi
  Scaleform::Render::RenderBuffer *v20; // rcx
  Scaleform::GFx::Resource **v21; // rsi
  Scaleform::Render::RenderBuffer *v22; // rcx
  Scaleform::GFx::Resource **v23; // rsi
  Scaleform::Render::RenderBuffer *v24; // rcx
  Scaleform::GFx::Resource **v25; // rsi
  Scaleform::Render::RenderBuffer *v26; // rcx
  Scaleform::GFx::Resource **v27; // rsi
  Scaleform::Render::RenderBuffer *v28; // rcx
  Scaleform::GFx::Resource **v29; // rsi
  Scaleform::Render::RenderBuffer *v30; // rcx
  Scaleform::GFx::Resource **v31; // rdi
  Scaleform::Render::RenderBuffer *v32; // rcx
  Scaleform::Ptr<Scaleform::GFx::TaskManager> v33; // [rsp+20h] [rbp-78h]
  Scaleform::Ptr<Scaleform::GFx::ImageFileHandlerRegistry> v34; // [rsp+28h] [rbp-70h]
  Scaleform::Ptr<Scaleform::GFx::ZlibSupportBase> v35; // [rsp+30h] [rbp-68h]
  Scaleform::Ptr<Scaleform::GFx::ASSupport> v36; // [rsp+38h] [rbp-60h]
  Scaleform::Ptr<Scaleform::GFx::ASSupport> v37; // [rsp+40h] [rbp-58h]
  __int64 v38; // [rsp+48h] [rbp-50h]
  Scaleform::Array<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,2,Scaleform::ArrayDefaultPolicy> *v39; // [rsp+50h] [rbp-48h]
  void *v40; // [rsp+58h] [rbp-40h]
  Scaleform::Ptr<Scaleform::GFx::LogState> result; // [rsp+A8h] [rbp+10h]
  Scaleform::Ptr<Scaleform::GFx::ParseControl> v42; // [rsp+B0h] [rbp+18h]
  Scaleform::Ptr<Scaleform::GFx::ProgressHandler> v43; // [rsp+B8h] [rbp+20h]

  v38 = -2i64;
  v4 = pbindStates;
  v5 = pstates;
  v6 = pimpl;
  v7 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::LoadStates,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::LoadStates::`vftable';
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
  v7->ThreadedLoading = 0;
  v9 = &v7->SubstituteFontMovieDefs;
  v39 = v9;
  v40 = &v7->SubstituteFontMovieDefs;
  v9->Data.Data = 0i64;
  v9->Data.Size = 0i64;
  v9->Data.Policy.Capacity = 0i64;
  if ( v6 )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v6);
  v10 = (Scaleform::Render::RenderBuffer *)v7->pLoaderImpl.pObject;
  if ( v10 )
    Scaleform::RefCountImpl::Release(v10);
  v7->pLoaderImpl.pObject = v6;
  v11 = v6->pWeakResourceLib.pObject;
  if ( v11 )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v6->pWeakResourceLib.pObject);
  v12 = (Scaleform::Render::RenderBuffer *)v7->pWeakResourceLib.pObject;
  if ( v12 )
    Scaleform::RefCountImpl::Release(v12);
  v7->pWeakResourceLib.pObject = v11;
  if ( !v5 )
    v5 = (Scaleform::GFx::StateBag *)&v6->vfptr;
  v13 = (Scaleform::GFx::MovieDefBindStates *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                Scaleform::Memory::pGlobalHeap,
                                                80i64);
  v40 = v13;
  if ( v4 )
  {
    if ( v13 )
    {
      Scaleform::GFx::MovieDefBindStates::MovieDefBindStates(v13, v4);
      v8 = v14;
    }
  }
  else if ( v13 )
  {
    Scaleform::GFx::MovieDefBindStates::MovieDefBindStates(v13, v5);
    v8 = v15;
  }
  v16 = (Scaleform::Render::RenderBuffer *)v7->pBindStates.pObject;
  if ( v16 )
    Scaleform::RefCountImpl::Release(v16);
  v7->pBindStates.pObject = v8;
  v17 = (Scaleform::GFx::Resource **)Scaleform::GFx::StateBag::GetLogState(v5, &result);
  if ( *v17 )
    Scaleform::Render::RenderBuffer::AddRef(*v17);
  v18 = (Scaleform::Render::RenderBuffer *)v7->pLog.pObject;
  if ( v18 )
    Scaleform::RefCountImpl::Release(v18);
  v7->pLog.pObject = (Scaleform::GFx::LogState *)*v17;
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
  v19 = (Scaleform::GFx::Resource **)Scaleform::GFx::StateBag::GetParseControl(v5, &v42);
  if ( *v19 )
    Scaleform::Render::RenderBuffer::AddRef(*v19);
  v20 = (Scaleform::Render::RenderBuffer *)v7->pParseControl.pObject;
  if ( v20 )
    Scaleform::RefCountImpl::Release(v20);
  v7->pParseControl.pObject = (Scaleform::GFx::ParseControl *)*v19;
  if ( v42.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v42.pObject);
  v21 = (Scaleform::GFx::Resource **)Scaleform::GFx::StateBag::GetProgressHandler(v5, &v43);
  if ( *v21 )
    Scaleform::Render::RenderBuffer::AddRef(*v21);
  v22 = (Scaleform::Render::RenderBuffer *)v7->pProgressHandler.pObject;
  if ( v22 )
    Scaleform::RefCountImpl::Release(v22);
  v7->pProgressHandler.pObject = (Scaleform::GFx::ProgressHandler *)*v21;
  if ( v43.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v43.pObject);
  v23 = (Scaleform::GFx::Resource **)Scaleform::GFx::StateBag::GetTaskManager(v5, &v33);
  if ( *v23 )
    Scaleform::Render::RenderBuffer::AddRef(*v23);
  v24 = (Scaleform::Render::RenderBuffer *)v7->pTaskManager.pObject;
  if ( v24 )
    Scaleform::RefCountImpl::Release(v24);
  v7->pTaskManager.pObject = (Scaleform::GFx::TaskManager *)*v23;
  if ( v33.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v33.pObject);
  v25 = (Scaleform::GFx::Resource **)Scaleform::GFx::StateBag::GetImageFileHandlerRegistry(v5, &v34);
  if ( *v25 )
    Scaleform::Render::RenderBuffer::AddRef(*v25);
  v26 = (Scaleform::Render::RenderBuffer *)v7->pImageFileHandlerRegistry.pObject;
  if ( v26 )
    Scaleform::RefCountImpl::Release(v26);
  v7->pImageFileHandlerRegistry.pObject = (Scaleform::GFx::ImageFileHandlerRegistry *)*v25;
  if ( v34.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v34.pObject);
  v27 = (Scaleform::GFx::Resource **)Scaleform::GFx::StateBag::GetZlibSupport(v5, &v35);
  if ( *v27 )
    Scaleform::Render::RenderBuffer::AddRef(*v27);
  v28 = (Scaleform::Render::RenderBuffer *)v7->pZlibSupport.pObject;
  if ( v28 )
    Scaleform::RefCountImpl::Release(v28);
  v7->pZlibSupport.pObject = (Scaleform::GFx::ZlibSupportBase *)*v27;
  if ( v35.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v35.pObject);
  v29 = (Scaleform::GFx::Resource **)Scaleform::GFx::StateBag::GetAS2Support(v5, &v36);
  if ( *v29 )
    Scaleform::Render::RenderBuffer::AddRef(*v29);
  v30 = (Scaleform::Render::RenderBuffer *)v7->pAS2Support.pObject;
  if ( v30 )
    Scaleform::RefCountImpl::Release(v30);
  v7->pAS2Support.pObject = (Scaleform::GFx::ASSupport *)*v29;
  if ( v36.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v36.pObject);
  v31 = (Scaleform::GFx::Resource **)Scaleform::GFx::StateBag::GetAS3Support(v5, &v37);
  if ( *v31 )
    Scaleform::Render::RenderBuffer::AddRef(*v31);
  v32 = (Scaleform::Render::RenderBuffer *)v7->pAS3Support.pObject;
  if ( v32 )
    Scaleform::RefCountImpl::Release(v32);
  v7->pAS3Support.pObject = (Scaleform::GFx::ASSupport *)*v31;
  if ( v37.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v37.pObject);
}

// File Line: 80
// RVA: 0x8A5430
void __fastcall Scaleform::GFx::LoadStates::~LoadStates(Scaleform::GFx::LoadStates *this)
{
  Scaleform::GFx::LoadStates *v1; // rdi
  Scaleform::Array<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,2,Scaleform::ArrayDefaultPolicy> *v2; // rbx
  Scaleform::Render::RenderBuffer *v3; // rcx
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

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::LoadStates::`vftable';
  v2 = &this->SubstituteFontMovieDefs;
  Scaleform::ConstructorMov<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>>::DestructArray(
    this->SubstituteFontMovieDefs.Data.Data,
    this->SubstituteFontMovieDefs.Data.Size);
  if ( v2->Data.Data )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v1->RelativePath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  v3 = (Scaleform::Render::RenderBuffer *)v1->pLoaderImpl.pObject;
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
  v4 = (Scaleform::Render::RenderBuffer *)v1->pWeakResourceLib.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  v5 = (Scaleform::Render::RenderBuffer *)v1->pAS3Support.pObject;
  if ( v5 )
    Scaleform::RefCountImpl::Release(v5);
  v6 = (Scaleform::Render::RenderBuffer *)v1->pAS2Support.pObject;
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
  v7 = (Scaleform::Render::RenderBuffer *)v1->pZlibSupport.pObject;
  if ( v7 )
    Scaleform::RefCountImpl::Release(v7);
  v8 = (Scaleform::Render::RenderBuffer *)v1->pImageFileHandlerRegistry.pObject;
  if ( v8 )
    Scaleform::RefCountImpl::Release(v8);
  v9 = (Scaleform::Render::RenderBuffer *)v1->pTaskManager.pObject;
  if ( v9 )
    Scaleform::RefCountImpl::Release(v9);
  v10 = (Scaleform::Render::RenderBuffer *)v1->pProgressHandler.pObject;
  if ( v10 )
    Scaleform::RefCountImpl::Release(v10);
  v11 = (Scaleform::Render::RenderBuffer *)v1->pParseControl.pObject;
  if ( v11 )
    Scaleform::RefCountImpl::Release(v11);
  v12 = (Scaleform::Render::RenderBuffer *)v1->pLog.pObject;
  if ( v12 )
    Scaleform::RefCountImpl::Release(v12);
  v13 = (Scaleform::Render::RenderBuffer *)v1->pBindStates.pObject;
  if ( v13 )
    Scaleform::RefCountImpl::Release(v13);
  Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)&v1->vfptr);
}

// File Line: 103
// RVA: 0x8D9C50
Scaleform::GFx::ImageCreator *__fastcall Scaleform::GFx::LoadStates::GetImageCreator(Scaleform::GFx::LoadStates *this)
{
  return this->pBindStates.pObject->pImageCreator.pObject;
}

// File Line: 109
// RVA: 0x90ADA0
void __fastcall Scaleform::GFx::LoadStates::SetRelativePathForDataDef(Scaleform::GFx::LoadStates *this, Scaleform::GFx::MovieDataDef *pdef)
{
  Scaleform::String *v2; // rbx

  v2 = &this->RelativePath;
  Scaleform::String::operator=(
    &this->RelativePath,
    (const char *)((pdef->pData.pObject->FileURL.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
  if ( !Scaleform::GFx::URLBuilder::ExtractFilePath(v2) )
    Scaleform::String::Clear(v2);
}

// File Line: 120
// RVA: 0x8EECE0
Scaleform::File *__fastcall Scaleform::GFx::LoadStates::OpenFile(Scaleform::GFx::LoadStates *this, const char *pfilename, unsigned int loadConstants)
{
  const char *v3; // rdi
  Scaleform::GFx::LoadStates *v4; // rbx
  Scaleform::GFx::LogState *v5; // rcx
  Scaleform::File *result; // rax
  Scaleform::Log *v7; // r8
  signed int v8; // ST20_4

  v3 = pfilename;
  v4 = this;
  if ( this->pBindStates.pObject->pFileOpener.pObject )
  {
    if ( _bittest((const signed int *)&loadConstants, 0x15u) )
    {
      v7 = 0i64;
    }
    else
    {
      v7 = this->pLog.pObject->pLog.pObject;
      if ( !v7 )
        v7 = Scaleform::Log::GetGlobalLog();
    }
    v8 = 438;
    result = (Scaleform::File *)((__int64 (__fastcall *)(Scaleform::GFx::FileOpener *, const char *, Scaleform::Log *, signed __int64, signed int))v4->pBindStates.pObject->pFileOpener.pObject->vfptr[3].__vecDelDtor)(
                                  v4->pBindStates.pObject->pFileOpener.pObject,
                                  v3,
                                  v7,
                                  33i64,
                                  v8);
  }
  else
  {
    v5 = this->pLog.pObject;
    if ( v5 )
    {
      if ( !_bittest((const signed int *)&loadConstants, 0x15u) )
        Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
          (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)&v5->vfptr,
          "Loader failed to open '%s', FileOpener not installe",
          pfilename);
    }
    result = 0i64;
  }
  return result;
}

// File Line: 136
// RVA: 0x8B8900
void __fastcall Scaleform::GFx::LoadStates::BuildURL(Scaleform::GFx::LoadStates *this, Scaleform::String *pdest, Scaleform::GFx::URLBuilder::LocationInfo *loc)
{
  Scaleform::GFx::URLBuilder *v3; // rcx

  v3 = this->pBindStates.pObject->pURLBulider.pObject;
  if ( v3 )
    ((void (__fastcall *)(Scaleform::GFx::URLBuilder *, Scaleform::String *, Scaleform::GFx::URLBuilder::LocationInfo *, Scaleform::String *))v3->vfptr[1].__vecDelDtor)(
      v3,
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
  Scaleform::GFx::LoadStates *v1; // rdi
  Scaleform::GFx::MovieDefBindStates *v2; // rax
  _QWORD *v3; // rbx
  Scaleform::GFx::Resource *v4; // rax
  Scaleform::GFx::Resource *v5; // rsi
  Scaleform::GFx::LoadStates *v6; // rax
  _QWORD *v7; // rax
  Scaleform::Render::RenderBuffer *v8; // rcx
  Scaleform::GFx::Resource *v9; // rcx
  Scaleform::Render::RenderBuffer *v10; // rcx
  Scaleform::GFx::Resource *v11; // rcx
  Scaleform::Render::RenderBuffer *v12; // rcx
  Scaleform::GFx::Resource *v13; // rcx
  Scaleform::Render::RenderBuffer *v14; // rcx
  Scaleform::GFx::Resource *v15; // rcx
  Scaleform::Render::RenderBuffer *v16; // rcx
  Scaleform::GFx::Resource *v17; // rcx
  Scaleform::Render::RenderBuffer *v18; // rcx
  Scaleform::GFx::Resource *v19; // rcx
  Scaleform::Render::RenderBuffer *v20; // rcx
  Scaleform::GFx::Resource *v21; // rcx
  Scaleform::Render::RenderBuffer *v22; // rcx
  Scaleform::GFx::Resource *v23; // rcx
  Scaleform::Render::RenderBuffer *v24; // rcx
  Scaleform::GFx::Resource *v25; // rcx
  Scaleform::Render::RenderBuffer *v26; // rcx
  Scaleform::GFx::Resource *v27; // rcx
  Scaleform::Render::RenderBuffer *v28; // rcx

  v1 = this;
  v2 = (Scaleform::GFx::MovieDefBindStates *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                               Scaleform::Memory::pGlobalHeap,
                                               80i64);
  v3 = 0i64;
  if ( v2 )
  {
    Scaleform::GFx::MovieDefBindStates::MovieDefBindStates(v2, v1->pBindStates.pObject);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  v6 = (Scaleform::GFx::LoadStates *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                       Scaleform::Memory::pGlobalHeap,
                                       144ui64,
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
    v9 = (Scaleform::GFx::Resource *)v1->pLoaderImpl.pObject;
    if ( v9 )
      Scaleform::Render::RenderBuffer::AddRef(v9);
    v10 = (Scaleform::Render::RenderBuffer *)v3[12];
    if ( v10 )
      Scaleform::RefCountImpl::Release(v10);
    v3[12] = v1->pLoaderImpl.pObject;
    v11 = (Scaleform::GFx::Resource *)v1->pLog.pObject;
    if ( v11 )
      Scaleform::Render::RenderBuffer::AddRef(v11);
    v12 = (Scaleform::Render::RenderBuffer *)v3[3];
    if ( v12 )
      Scaleform::RefCountImpl::Release(v12);
    v3[3] = v1->pLog.pObject;
    v13 = (Scaleform::GFx::Resource *)v1->pProgressHandler.pObject;
    if ( v13 )
      Scaleform::Render::RenderBuffer::AddRef(v13);
    v14 = (Scaleform::Render::RenderBuffer *)v3[5];
    if ( v14 )
      Scaleform::RefCountImpl::Release(v14);
    v3[5] = v1->pProgressHandler.pObject;
    v15 = (Scaleform::GFx::Resource *)v1->pTaskManager.pObject;
    if ( v15 )
      Scaleform::Render::RenderBuffer::AddRef(v15);
    v16 = (Scaleform::Render::RenderBuffer *)v3[6];
    if ( v16 )
      Scaleform::RefCountImpl::Release(v16);
    v3[6] = v1->pTaskManager.pObject;
    v17 = (Scaleform::GFx::Resource *)v1->pParseControl.pObject;
    if ( v17 )
      Scaleform::Render::RenderBuffer::AddRef(v17);
    v18 = (Scaleform::Render::RenderBuffer *)v3[4];
    if ( v18 )
      Scaleform::RefCountImpl::Release(v18);
    v3[4] = v1->pParseControl.pObject;
    v19 = (Scaleform::GFx::Resource *)v1->pWeakResourceLib.pObject;
    if ( v19 )
      Scaleform::Render::RenderBuffer::AddRef(v19);
    v20 = (Scaleform::Render::RenderBuffer *)v3[11];
    if ( v20 )
      Scaleform::RefCountImpl::Release(v20);
    v3[11] = v1->pWeakResourceLib.pObject;
    v21 = (Scaleform::GFx::Resource *)v1->pImageFileHandlerRegistry.pObject;
    if ( v21 )
      Scaleform::Render::RenderBuffer::AddRef(v21);
    v22 = (Scaleform::Render::RenderBuffer *)v3[7];
    if ( v22 )
      Scaleform::RefCountImpl::Release(v22);
    v3[7] = v1->pImageFileHandlerRegistry.pObject;
    v23 = (Scaleform::GFx::Resource *)v1->pZlibSupport.pObject;
    if ( v23 )
      Scaleform::Render::RenderBuffer::AddRef(v23);
    v24 = (Scaleform::Render::RenderBuffer *)v3[8];
    if ( v24 )
      Scaleform::RefCountImpl::Release(v24);
    v3[8] = v1->pZlibSupport.pObject;
    v25 = (Scaleform::GFx::Resource *)v1->pAS2Support.pObject;
    if ( v25 )
      Scaleform::Render::RenderBuffer::AddRef(v25);
    v26 = (Scaleform::Render::RenderBuffer *)v3[9];
    if ( v26 )
      Scaleform::RefCountImpl::Release(v26);
    v3[9] = v1->pAS2Support.pObject;
    v27 = (Scaleform::GFx::Resource *)v1->pAS3Support.pObject;
    if ( v27 )
      Scaleform::Render::RenderBuffer::AddRef(v27);
    v28 = (Scaleform::Render::RenderBuffer *)v3[10];
    if ( v28 )
      Scaleform::RefCountImpl::Release(v28);
    v3[10] = v1->pAS3Support.pObject;
  }
  if ( v5 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v5);
  return (Scaleform::GFx::LoadStates *)v3;
}

// File Line: 197
// RVA: 0x898C70
void __fastcall Scaleform::GFx::LoadProcess::LoadProcess(Scaleform::GFx::LoadProcess *this, Scaleform::GFx::MovieDataDef *pdataDef, Scaleform::GFx::LoadStates *pstates, unsigned int loadFlags)
{
  unsigned int v4; // ebp
  Scaleform::GFx::LoadStates *v5; // rbx
  Scaleform::GFx::MovieDataDef *v6; // rsi
  Scaleform::GFx::LoadProcess *v7; // rdi
  Scaleform::GFx::ParseControl *v8; // rax
  unsigned int v9; // eax
  Scaleform::GFx::Resource *v10; // rcx
  Scaleform::Render::RenderBuffer *v11; // rcx
  signed __int64 v12; // [rsp+78h] [rbp+10h]

  v4 = loadFlags;
  v5 = pstates;
  v6 = pdataDef;
  v7 = this;
  Scaleform::GFx::LoaderTask::LoaderTask((Scaleform::GFx::LoaderTask *)&this->vfptr, pstates, Id_MovieDataLoad);
  v7->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>Vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::`vftable';
  v7->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::LoadProcess::`vftable'{for `Scaleform::GFx::LoaderTask'};
  v7->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>Vtbl *)&Scaleform::GFx::LoadProcess::`vftable'{for `Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>'};
  v7->pBindProcess.pObject = 0i64;
  v7->pLoadData.pObject = 0i64;
  Scaleform::GFx::SWFProcessInfo::SWFProcessInfo(&v7->ProcessInfo, v6->pData.pObject->pHeap);
  v7->pJpegTables.pObject = 0i64;
  `eh vector constructor iterator'(
    v7->FrameTags,
    0x18ui64,
    2,
    (void (__fastcall *)(void *))Scaleform::Array<Scaleform::GFx::ExecuteTag *,2,Scaleform::ArrayConstPolicy<32,16,0>>::Array<Scaleform::GFx::ExecuteTag *,2,Scaleform::ArrayConstPolicy<32,16,0>>);
  v12 = (signed __int64)&v7->InitActionTags;
  *(_OWORD *)v12 = 0ui64;
  *(_QWORD *)(v12 + 16) = 0i64;
  v8 = v5->pParseControl.pObject;
  if ( v8 )
    v9 = v8->ParseFlags;
  else
    v9 = 0;
  v7->ParseFlags = v9;
  v10 = (Scaleform::GFx::Resource *)v6->pData.pObject;
  if ( v10 )
    Scaleform::Render::RenderBuffer::AddRef(v10);
  v11 = (Scaleform::Render::RenderBuffer *)v7->pLoadData.pObject;
  if ( v11 )
    Scaleform::RefCountImpl::Release(v11);
  v7->pLoadData.pObject = v6->pData.pObject;
  v7->pDataDef_Unsafe = v6;
  v7->pTimelineDef = 0i64;
  v7->LoadFlags = v4;
  v7->LoadState = 0;
  v7->ImportIndex = 0;
  *(_QWORD *)&v7->ImportDataCount = 0i64;
  v7->FontDataCount = 0;
  v7->pImportDataLast = 0i64;
  v7->pImportData = 0i64;
  v7->pResourceDataLast = 0i64;
  v7->pResourceData = 0i64;
  v7->pFontDataLast = 0i64;
  v7->pFontData = 0i64;
  v7->pAltStream = 0i64;
  v7->pTempBindData = 0i64;
  v7->ASInitActionTagsNum = 0;
}

// File Line: 253
// RVA: 0x8A5170
void __fastcall Scaleform::GFx::LoadProcess::~LoadProcess(Scaleform::GFx::LoadProcess *this)
{
  Scaleform::GFx::LoadProcess *v1; // rdi
  Scaleform::Render::RenderBuffer *v2; // rcx
  Scaleform::GFx::MovieDataDef::LoadTaskData *v3; // rax
  Scaleform::GFx::LoadUpdateSync *v4; // rsi
  Scaleform::Render::RenderBuffer *v5; // rcx
  Scaleform::Render::RenderBuffer *v6; // rcx
  Scaleform::Render::RenderBuffer *v7; // rcx
  Scaleform::Render::RenderBuffer *v8; // rcx
  Scaleform::Render::RenderBuffer *v9; // rcx
  Scaleform::Render::RenderBuffer *v10; // rcx
  Scaleform::Render::RenderBuffer *v11; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::LoadProcess::`vftable'{for `Scaleform::GFx::LoaderTask'};
  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>Vtbl *)&Scaleform::GFx::LoadProcess::`vftable'{for `Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>'};
  v2 = (Scaleform::Render::RenderBuffer *)this->pJpegTables.pObject;
  if ( v2 )
    Scaleform::RefCountImpl::Release(v2);
  v1->pJpegTables.pObject = 0i64;
  v3 = v1->pLoadData.pObject;
  v4 = v3->pFrameUpdate.pObject;
  if ( v4 )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v3->pFrameUpdate.pObject);
  Scaleform::String::Clear((Scaleform::String *)&v1->ProcessInfo.Stream.FileName.0);
  v5 = (Scaleform::Render::RenderBuffer *)v1->ProcessInfo.Stream.pInput.pObject;
  if ( v5 )
    Scaleform::RefCountImpl::Release(v5);
  v1->ProcessInfo.Stream.pInput.pObject = 0i64;
  v1->ProcessInfo.Stream.pLog = 0i64;
  v1->ProcessInfo.Stream.pParseControl = 0i64;
  v6 = (Scaleform::Render::RenderBuffer *)v1->pLoadData.pObject;
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
  v1->pLoadData.pObject = 0i64;
  v7 = (Scaleform::Render::RenderBuffer *)v1->pBindProcess.pObject;
  if ( v7 )
    Scaleform::RefCountImpl::Release(v7);
  v1->pBindProcess.pObject = 0i64;
  if ( v4 )
  {
    Scaleform::Mutex::DoLock(&v4->mMutex);
    v4->LoadFinished = 1;
    Scaleform::WaitCondition::NotifyAll(&v4->WC);
    Scaleform::Mutex::Unlock(&v4->mMutex);
  }
  if ( v4 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v4);
  if ( v1->InitActionTags.Data.Data )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  `eh vector destructor iterator'(
    v1->FrameTags,
    0x18ui64,
    2,
    (void (__fastcall *)(void *))Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>);
  v8 = (Scaleform::Render::RenderBuffer *)v1->pJpegTables.pObject;
  if ( v8 )
    Scaleform::RefCountImpl::Release(v8);
  Scaleform::GFx::SWFProcessInfo::~SWFProcessInfo(&v1->ProcessInfo);
  v9 = (Scaleform::Render::RenderBuffer *)v1->pLoadData.pObject;
  if ( v9 )
    Scaleform::RefCountImpl::Release(v9);
  v10 = (Scaleform::Render::RenderBuffer *)v1->pBindProcess.pObject;
  if ( v10 )
    Scaleform::RefCountImpl::Release(v10);
  v1->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>Vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::`vftable';
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::LoaderTask::`vftable';
  Scaleform::GFx::LoaderImpl::UnRegisterLoadProcess(
    v1->pLoadStates.pObject->pLoaderImpl.pObject,
    (Scaleform::GFx::LoaderTask *)&v1->vfptr);
  v11 = (Scaleform::Render::RenderBuffer *)v1->pLoadStates.pObject;
  if ( v11 )
    Scaleform::RefCountImpl::Release(v11);
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::Task::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)&v1->vfptr);
}

// File Line: 295
// RVA: 0x8B6FB0
char __fastcall Scaleform::GFx::LoadProcess::BeginSWFLoading(Scaleform::GFx::LoadProcess *this, Scaleform::File *pfile)
{
  Scaleform::GFx::LoadProcess *v2; // rdi
  char result; // al
  Scaleform::GFx::MovieDataDef::LoadTaskData *v4; // rbx

  v2 = this;
  result = Scaleform::GFx::SWFProcessInfo::Initialize(
             &this->ProcessInfo,
             pfile,
             this->pLoadStates.pObject->pLog.pObject,
             this->pLoadStates.pObject->pZlibSupport.pObject,
             this->pLoadStates.pObject->pParseControl.pObject,
             1);
  if ( result )
  {
    v2->pLoadData.pObject->FileAttributes = v2->ProcessInfo.FileAttributes;
    v4 = v2->pLoadData.pObject;
    Scaleform::GFx::MovieHeaderData::operator=(&v4->Header, &v2->ProcessInfo.Header);
    Scaleform::GFx::MovieDataDef::LoadTaskData::UpdateLoadState(v4, v4->LoadingFrame, LS_LoadingFrames);
    result = 1;
  }
  return result;
}

// File Line: 339
// RVA: 0x8BD270
void __fastcall Scaleform::GFx::LoadProcess::CommitFrameTags(Scaleform::GFx::LoadProcess *this)
{
  Scaleform::GFx::LoadProcess *v1; // rbx
  __int64 v2; // rcx
  Scaleform::GFx::LoadStates *v3; // rax
  Scaleform::GFx::LogState *v4; // rbp
  unsigned __int64 v5; // rax
  Scaleform::GFx::MovieDataDef::LoadTaskData *v6; // rcx
  size_t v7; // rdi
  unsigned __int64 v8; // r8
  Scaleform::GFx::DataAllocator *v9; // rcx
  unsigned __int64 v10; // rdx
  char *v11; // r9
  char *v12; // rax
  Scaleform::GFx::MovieDataDef::LoadTaskData *v13; // r14
  signed __int64 v14; // rsi
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
  char *v28; // [rsp+20h] [rbp-28h]
  int v29; // [rsp+28h] [rbp-20h]

  v1 = this;
  v2 = this->LoadState;
  v3 = v1->pLoadStates.pObject;
  if ( (_DWORD)v2 == 1 )
  {
    v4 = v3->pLog.pObject;
    v28 = 0i64;
    v29 = 0;
    v5 = v1->FrameTags[1].Data.Size;
    if ( v5 )
    {
      v6 = v1->pLoadData.pObject;
      v7 = 8 * v5;
      v8 = v6->TagMemAllocator.BytesLeft;
      v9 = &v6->TagMemAllocator;
      v10 = (8 * v5 + 7) & 0xFFFFFFFFFFFFFFF8ui64;
      if ( v10 > v8 )
      {
        v11 = (char *)Scaleform::GFx::DataAllocator::OverflowAlloc(v9, v10);
      }
      else
      {
        v11 = v9->pCurrent;
        v12 = &v9->pCurrent[v10];
        v9->BytesLeft = v8 - v10;
        v9->pCurrent = v12;
      }
      v28 = v11;
      if ( v11 )
      {
        memmove(v11, v1->FrameTags[1].Data.Data, v7);
        v29 = v1->FrameTags[1].Data.Size;
      }
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::ExecuteTag *,Scaleform::AllocatorGH<Scaleform::GFx::ExecuteTag *,2>,Scaleform::ArrayConstPolicy<32,16,0>>>::Clear((Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::ExecuteTag *,Scaleform::AllocatorGH<Scaleform::GFx::ExecuteTag *,2>,Scaleform::ArrayConstPolicy<32,16,0> > > *)&v1->FrameTags[1].Data);
    }
    ((void (__fastcall *)(Scaleform::GFx::TimelineIODef *, char **, Scaleform::GFx::LogState *))v1->pTimelineDef->vfptr[4].__vecDelDtor)(
      v1->pTimelineDef,
      &v28,
      v4);
  }
  else
  {
    v13 = v1->pLoadData.pObject;
    v14 = (signed __int64)v1 + 24 * v2;
    v15 = v3->pLog.pObject;
    v28 = 0i64;
    v29 = 0;
    v16 = *(_QWORD *)(v14 + 976);
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
        memmove(v20, *(const void **)(v14 + 968), v18);
        v29 = *(_DWORD *)(v14 + 976);
      }
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::ExecuteTag *,Scaleform::AllocatorGH<Scaleform::GFx::ExecuteTag *,2>,Scaleform::ArrayConstPolicy<32,16,0>>>::Clear((Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::ExecuteTag *,Scaleform::AllocatorGH<Scaleform::GFx::ExecuteTag *,2>,Scaleform::ArrayConstPolicy<32,16,0> > > *)(v14 + 968));
    }
    ((void (__fastcall *)(Scaleform::GFx::MovieDataDef::LoadTaskData *, char **, Scaleform::GFx::LogState *))v13->vfptr[2].__vecDelDtor)(
      v13,
      &v28,
      v15);
    v21 = v1->pLoadData.pObject;
    v22 = v1->pLoadStates.pObject->pLog.pObject;
    v28 = 0i64;
    v29 = 0;
    v23 = v1->InitActionTags.Data.Size;
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
        memmove(v27, v1->InitActionTags.Data.Data, v25);
        v29 = v1->InitActionTags.Data.Size;
      }
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::ExecuteTag *,Scaleform::AllocatorGH<Scaleform::GFx::ExecuteTag *,2>,Scaleform::ArrayConstPolicy<32,16,0>>>::Clear((Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::ExecuteTag *,Scaleform::AllocatorGH<Scaleform::GFx::ExecuteTag *,2>,Scaleform::ArrayConstPolicy<32,16,0> > > *)&v1->InitActionTags.Data);
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
  Scaleform::GFx::LoadProcess *v1; // rbx
  unsigned __int64 v2; // rdi
  Scaleform::GFx::ExecuteTag *v3; // rcx
  unsigned __int64 i; // rdi
  Scaleform::GFx::ExecuteTag *v5; // rcx
  unsigned __int64 j; // rdi
  Scaleform::GFx::ExecuteTag *v7; // rcx
  Scaleform::GFx::ExecuteTag **v8; // rdx
  Scaleform::GFx::ExecuteTag **v9; // rax
  Scaleform::GFx::ExecuteTag **v10; // rdx
  Scaleform::GFx::ExecuteTag **v11; // rax
  Scaleform::GFx::ExecuteTag **v12; // rdx
  Scaleform::GFx::ExecuteTag **v13; // rax
  int v14; // [rsp+30h] [rbp+8h]

  v1 = this;
  v2 = 0i64;
  if ( this->FrameTags[1].Data.Size )
  {
    do
    {
      v3 = v1->FrameTags[1].Data.Data[v2];
      v3->vfptr->__vecDelDtor(v3, 0);
      ++v2;
    }
    while ( v2 < v1->FrameTags[1].Data.Size );
  }
  for ( i = 0i64; i < v1->FrameTags[0].Data.Size; ++i )
  {
    v5 = v1->FrameTags[0].Data.Data[i];
    v5->vfptr->__vecDelDtor(v5, 0);
  }
  for ( j = 0i64; j < v1->InitActionTags.Data.Size; ++j )
  {
    v7 = v1->InitActionTags.Data.Data[j];
    v7->vfptr->__vecDelDtor(v7, 0);
  }
  if ( v1->FrameTags[1].Data.Size > 0 && v1->FrameTags[1].Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64 )
  {
    v8 = v1->FrameTags[1].Data.Data;
    if ( v8 )
    {
      v9 = (Scaleform::GFx::ExecuteTag **)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(
                                            Scaleform::Memory::pGlobalHeap,
                                            v8,
                                            256ui64);
    }
    else
    {
      v14 = 2;
      v9 = (Scaleform::GFx::ExecuteTag **)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                            Scaleform::Memory::pGlobalHeap,
                                            256ui64,
                                            (Scaleform::AllocInfo *)&v14);
    }
    v1->FrameTags[1].Data.Data = v9;
    v1->FrameTags[1].Data.Policy.Capacity = 32i64;
  }
  v1->FrameTags[1].Data.Size = 0i64;
  if ( v1->FrameTags[0].Data.Size > 0 && v1->FrameTags[0].Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64 )
  {
    v10 = v1->FrameTags[0].Data.Data;
    if ( v10 )
    {
      v11 = (Scaleform::GFx::ExecuteTag **)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(
                                             Scaleform::Memory::pGlobalHeap,
                                             v10,
                                             256ui64);
    }
    else
    {
      v14 = 2;
      v11 = (Scaleform::GFx::ExecuteTag **)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                             Scaleform::Memory::pGlobalHeap,
                                             256ui64,
                                             (Scaleform::AllocInfo *)&v14);
    }
    v1->FrameTags[0].Data.Data = v11;
    v1->FrameTags[0].Data.Policy.Capacity = 32i64;
  }
  v1->FrameTags[0].Data.Size = 0i64;
  if ( v1->InitActionTags.Data.Size > 0 && v1->InitActionTags.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64 )
  {
    v12 = v1->InitActionTags.Data.Data;
    if ( v12 )
    {
      v13 = (Scaleform::GFx::ExecuteTag **)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(
                                             Scaleform::Memory::pGlobalHeap,
                                             v12,
                                             256ui64);
    }
    else
    {
      v14 = 2;
      v13 = (Scaleform::GFx::ExecuteTag **)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                             Scaleform::Memory::pGlobalHeap,
                                             256ui64,
                                             (Scaleform::AllocInfo *)&v14);
    }
    v1->InitActionTags.Data.Data = v13;
    v1->InitActionTags.Data.Policy.Capacity = 32i64;
  }
  v1->InitActionTags.Data.Size = 0i64;
}

// File Line: 372
// RVA: 0x8B04C0
Scaleform::GFx::ResourceHandle *__fastcall Scaleform::GFx::LoadProcess::AddDataResource(Scaleform::GFx::LoadProcess *this, Scaleform::GFx::ResourceHandle *result, __int64 rid, Scaleform::GFx::ResourceData *resData)
{
  Scaleform::GFx::ResourceData *v4; // r14
  Scaleform::GFx::ResourceHandle *v5; // rbp
  Scaleform::GFx::LoadProcess *v6; // rdi
  Scaleform::GFx::MovieDataDef::LoadTaskData *v7; // rsi
  Scaleform::GFx::ResourceDataNode *v8; // rbx
  Scaleform::GFx::ResourceId rida; // [rsp+50h] [rbp+8h]
  Scaleform::GFx::ResourceHandle *v11; // [rsp+58h] [rbp+10h]

  v11 = result;
  v4 = resData;
  v5 = result;
  v6 = this;
  rida.Id = *(_DWORD *)rid;
  Scaleform::GFx::MovieDataDef::LoadTaskData::AddNewResourceHandle(
    this->pLoadData.pObject,
    result,
    (Scaleform::GFx::ResourceId)&rida);
  v7 = v6->pLoadData.pObject;
  v8 = Scaleform::GFx::MovieDataDef::LoadTaskData::AllocMovieDefClass<Scaleform::GFx::ResourceDataNode>(v6->pLoadData.pObject);
  if ( v8 )
  {
    if ( v4->pInterface )
      v4->pInterface->vfptr->AddRef(v4->pInterface, v4->hData);
    if ( v8->Data.pInterface )
      v8->Data.pInterface->vfptr->Release(v8->Data.pInterface, v8->Data.hData);
    v8->Data.pInterface = v4->pInterface;
    v8->Data.hData = v4->hData;
    v8->BindIndex = v5->BindIndex;
    if ( !v6->pResourceData )
      v6->pResourceData = v8;
    if ( v7->BindData.pResourceNodes.Value )
      v7->BindData.pResourceNodesLast->pNext.Value = v8;
    else
      v7->BindData.pResourceNodes.Value = v8;
    v7->BindData.pResourceNodesLast = v8;
    ++v6->ResourceDataCount;
  }
  return v5;
}

// File Line: 400
// RVA: 0x159C300
__int64 Scaleform::GFx::_dynamic_initializer_for__static_inst__()
{
  static_inst.vfptr = (Scaleform::GFx::ResourceData::DataInterfaceVtbl *)&Scaleform::GFx::FontResourceCreator::`vftable';
  return atexit(Scaleform::GFx::_dynamic_atexit_destructor_for__static_inst__);
}

// File Line: 402
// RVA: 0x8B0F40
Scaleform::GFx::ResourceHandle *__fastcall Scaleform::GFx::LoadProcess::AddFontDataResource(Scaleform::GFx::LoadProcess *this, Scaleform::GFx::ResourceHandle *result, __int64 rid, Scaleform::Render::Font *pfontData)
{
  Scaleform::GFx::Resource *v4; // rbp
  unsigned int *v5; // r15
  Scaleform::GFx::ResourceHandle *v6; // r14
  Scaleform::GFx::LoadProcess *v7; // rdi
  Scaleform::GFx::FontDataUseNode *v8; // rax
  Scaleform::GFx::FontDataUseNode *v9; // rbx
  Scaleform::GFx::MovieDataDef::LoadTaskData *v10; // rsi
  Scaleform::Render::RenderBuffer *v11; // rcx
  Scaleform::GFx::ResourceData resData; // [rsp+30h] [rbp-38h]
  Scaleform::GFx::ResourceId rida; // [rsp+70h] [rbp+8h]
  Scaleform::GFx::ResourceHandle *v15; // [rsp+78h] [rbp+10h]

  v15 = result;
  v4 = (Scaleform::GFx::Resource *)pfontData;
  v5 = (unsigned int *)rid;
  v6 = result;
  v7 = this;
  static_inst.vfptr->AddRef((Scaleform::GFx::ResourceData::DataInterface *)&static_inst, pfontData);
  resData.pInterface = (Scaleform::GFx::ResourceData::DataInterface *)&static_inst;
  resData.hData = v4;
  rida.Id = *v5;
  Scaleform::GFx::LoadProcess::AddDataResource(v7, v6, (__int64)&rida, &resData);
  v8 = Scaleform::GFx::MovieDataDef::LoadTaskData::AllocMovieDefClass<Scaleform::GFx::FontDataUseNode>(v7->pLoadData.pObject);
  v9 = v8;
  if ( v8 )
  {
    v10 = v7->pLoadData.pObject;
    v8->Id.Id = *v5;
    if ( v4 )
      Scaleform::Render::RenderBuffer::AddRef(v4);
    v11 = (Scaleform::Render::RenderBuffer *)v9->pFontData.pObject;
    if ( v11 )
      Scaleform::RefCountImpl::Release(v11);
    v9->pFontData.pObject = (Scaleform::Render::Font *)v4;
    v9->BindIndex = v6->BindIndex;
    if ( !v7->pFontData )
      v7->pFontData = v9;
    if ( v10->BindData.pFonts.Value )
      v10->BindData.pFontsLast->pNext.Value = v9;
    else
      v10->BindData.pFonts.Value = v9;
    v10->BindData.pFontsLast = v9;
    ++v7->FontDataCount;
  }
  static_inst.vfptr->Release((Scaleform::GFx::ResourceData::DataInterface *)&static_inst, v4);
  return v6;
}

// File Line: 457
// RVA: 0x8B14E0
void __fastcall Scaleform::GFx::LoadProcess::AddImageResource(Scaleform::GFx::LoadProcess *this, __int64 rid, Scaleform::Render::ImageSource *pimage)
{
  int *v3; // r12
  Scaleform::GFx::LoadProcess *v4; // r14
  Scaleform::GFx::MovieDefBindStates *v5; // rax
  Scaleform::GFx::ImageCreator *v6; // rcx
  __int64 v7; // rdx
  __int64 v8; // rax
  Scaleform::Render::Image *v9; // rdi
  Scaleform::GFx::ImageResource *v10; // rax
  Scaleform::GFx::Resource *v11; // rax
  Scaleform::GFx::Resource *v12; // rbx
  int v13; // eax
  Scaleform::GFx::ResourceLibBase *v14; // rcx
  __int64 v15; // rbx
  Scaleform::Render::Image *v16; // rax
  Scaleform::Render::Image *v17; // r15
  Scaleform::Render::WrapperImageSource *v18; // rax
  Scaleform::Render::ImageSource *v19; // rax
  Scaleform::Render::ImageSource *v20; // rdi
  Scaleform::GFx::Resource *v21; // rbx
  Scaleform::GFx::ResourceLibBase *v22; // rcx
  Scaleform::RefCountImplCore v23; // [rsp+20h] [rbp-E0h]
  int v24; // [rsp+30h] [rbp-D0h]
  Scaleform::Render::RenderBuffer *v25; // [rsp+38h] [rbp-C8h]
  int v26; // [rsp+40h] [rbp-C0h]
  Scaleform::GFx::ResourceData result; // [rsp+48h] [rbp-B8h]
  Scaleform::GFx::ResourceHandle v28; // [rsp+58h] [rbp-A8h]
  int v29; // [rsp+68h] [rbp-98h]
  __int64 v30; // [rsp+70h] [rbp-90h]
  int v31; // [rsp+78h] [rbp-88h]
  int v32; // [rsp+7Ch] [rbp-84h]
  __int64 v33; // [rsp+80h] [rbp-80h]
  __int64 v34; // [rsp+88h] [rbp-78h]
  __int64 v35; // [rsp+90h] [rbp-70h]
  __int64 v36; // [rsp+98h] [rbp-68h]
  int v37; // [rsp+A0h] [rbp-60h]
  __int64 v38; // [rsp+A8h] [rbp-58h]
  __int64 v39; // [rsp+B0h] [rbp-50h]
  __int64 v40; // [rsp+B8h] [rbp-48h]
  int v41; // [rsp+C0h] [rbp-40h]
  int v42; // [rsp+C8h] [rbp-38h]
  __int64 v43; // [rsp+D0h] [rbp-30h]
  int v44; // [rsp+D8h] [rbp-28h]
  int v45; // [rsp+DCh] [rbp-24h]
  __int64 v46; // [rsp+E0h] [rbp-20h]
  __int64 v47; // [rsp+E8h] [rbp-18h]
  __int64 v48; // [rsp+F0h] [rbp-10h]
  __int64 v49; // [rsp+F8h] [rbp-8h]
  Scaleform::Render::ImageSource *v50; // [rsp+100h] [rbp+0h]
  __int64 v51; // [rsp+108h] [rbp+8h]
  __int64 v52; // [rsp+110h] [rbp+10h]
  Scaleform::Render::Image *v53; // [rsp+118h] [rbp+18h]
  Scaleform::GFx::Resource *v54; // [rsp+120h] [rbp+20h]
  Scaleform::GFx::ImageResource *rida; // [rsp+180h] [rbp+80h]
  Scaleform::Render::WrapperImageSource *v56; // [rsp+188h] [rbp+88h]

  if ( pimage )
  {
    v51 = -2i64;
    v3 = (int *)rid;
    v4 = this;
    if ( SLOBYTE(this->LoadFlags) >= 0
      && (v5 = this->pLoadStates.pObject->pBindStates.pObject, v5->pImageCreator.pObject)
      && (v6 = v5->pImageCreator.pObject) != 0i64 )
    {
      v7 = (__int64)v4->pLoadData.pObject->pHeap;
      v29 = 1;
      v30 = v7;
      v31 = 1;
      v32 = 1;
      v33 = 0i64;
      v34 = 0i64;
      v35 = 0i64;
      v36 = 0i64;
      v8 = (__int64)v6->vfptr[4].__vecDelDtor((Scaleform::RefCountImplCore *)&v6->vfptr, (unsigned int)&v29);
      v9 = (Scaleform::Render::Image *)v8;
      v52 = v8;
      v10 = (Scaleform::GFx::ImageResource *)(*(__int64 (__fastcall **)(__int64, signed __int64, _QWORD))(*(_QWORD *)v30 + 80i64))(
                                               v30,
                                               104i64,
                                               0i64);
      rida = v10;
      if ( v10 )
      {
        Scaleform::GFx::ImageResource::ImageResource(v10, v9, Use_Bitmap);
        v12 = v11;
      }
      else
      {
        v12 = 0i64;
      }
      v54 = v12;
      v13 = *v3;
      v26 = *v3;
      if ( v4->LoadState == LS_LoadingRoot )
      {
        LODWORD(rida) = v13;
        Scaleform::GFx::MovieDataDef::LoadTaskData::AddResource(
          v4->pLoadData.pObject,
          (Scaleform::GFx::ResourceId)&rida,
          v12);
      }
      if ( v12 && !_InterlockedDecrement(&v12->RefCount.Value) )
      {
        v14 = v12->pLib;
        if ( v14 )
        {
          v14->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v14->vfptr, (unsigned int)v12);
          v12->pLib = 0i64;
        }
        v12->vfptr->__vecDelDtor(v12, 1u);
      }
      if ( v9 )
        ((void (__fastcall *)(Scaleform::Render::Image *))v9->vfptr[2].__vecDelDtor)(v9);
    }
    else
    {
      v15 = (__int64)v4->pLoadData.pObject->pHeap;
      v42 = 1;
      v43 = v15;
      v44 = 1;
      v45 = 1;
      v46 = 0i64;
      v47 = 0i64;
      v48 = 0i64;
      v49 = 0i64;
      v23.RefCount = 1;
      v24 = 14;
      v23.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ImageCreator::`vftable';
      v25 = 0i64;
      v40 = 0i64;
      v41 = 0;
      v38 = v15;
      v37 = 1;
      v39 = 0i64;
      v16 = (Scaleform::Render::Image *)pimage->vfptr[12].__vecDelDtor(
                                          (Scaleform::RefCountImplCore *)pimage,
                                          (unsigned int)&v37);
      v17 = v16;
      v53 = v16;
      v18 = (Scaleform::Render::WrapperImageSource *)(*(__int64 (__fastcall **)(__int64, signed __int64, _QWORD))(*(_QWORD *)v15 + 80i64))(
                                                       v15,
                                                       24i64,
                                                       0i64);
      v56 = v18;
      if ( v18 )
      {
        Scaleform::Render::WrapperImageSource::WrapperImageSource(v18, v17);
        v20 = v19;
      }
      else
      {
        v20 = 0i64;
      }
      v50 = v20;
      Scaleform::GFx::ImageResourceCreator::CreateImageResourceData(&result, v20);
      LODWORD(v56) = *v3;
      Scaleform::GFx::LoadProcess::AddDataResource(v4, &v28, (__int64)&v56, &result);
      if ( v28.HType == RH_Pointer )
      {
        v21 = v28.pResource;
        if ( v28.pResource )
        {
          if ( !_InterlockedDecrement(&v28.pResource->RefCount.Value) )
          {
            v22 = v21->pLib;
            if ( v22 )
            {
              v22->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v22->vfptr, (unsigned int)v21);
              v21->pLib = 0i64;
            }
            v21->vfptr->__vecDelDtor(v21, 1u);
          }
        }
      }
      if ( result.pInterface )
        result.pInterface->vfptr->Release(result.pInterface, result.hData);
      if ( v20 )
        ((void (__fastcall *)(Scaleform::Render::ImageSource *))v20->vfptr[2].__vecDelDtor)(v20);
      if ( v17 )
        ((void (__fastcall *)(Scaleform::Render::Image *))v17->vfptr[2].__vecDelDtor)(v17);
      if ( v25 )
        Scaleform::RefCountImpl::Release(v25);
      v23.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::State::`vftable';
      Scaleform::RefCountImplCore::~RefCountImplCore(&v23);
    }
  }
}

// File Line: 489
// RVA: 0x8BFD50
Scaleform::GFx::FrameBindData *__fastcall Scaleform::GFx::LoadProcess::CreateFrameBindData(Scaleform::GFx::LoadProcess *this)
{
  Scaleform::GFx::LoadProcess *v1; // rbx
  Scaleform::GFx::FrameBindData *result; // rax

  v1 = this;
  result = Scaleform::GFx::MovieDataDef::LoadTaskData::AllocMovieDefClass<Scaleform::GFx::FrameBindData>(this->pLoadData.pObject);
  if ( result )
  {
    result->ImportCount = v1->ImportDataCount;
    result->pImportData = v1->pImportData;
    result->FontCount = v1->FontDataCount;
    result->pFontData = v1->pFontData;
    result->ResourceCount = v1->ResourceDataCount;
    result->pResourceData = v1->pResourceData;
    *(_QWORD *)&v1->ImportDataCount = 0i64;
    v1->FontDataCount = 0;
    v1->pImportData = 0i64;
    v1->pResourceData = 0i64;
    v1->pFontData = 0i64;
  }
  return result;
}

// File Line: 523
// RVA: 0x8C2CE0
__int64 __fastcall Scaleform::GFx::ImageFileResourceCreator::CreateResource(Scaleform::GFx::ImageFileResourceCreator *this, void *hdata, Scaleform::GFx::ResourceBindData *pbindData, Scaleform::GFx::LoadStates *pls)
{
  Scaleform::GFx::LoadStates *v4; // r15
  Scaleform::GFx::ResourceBindData *v5; // rdi
  unsigned __int16 *v6; // r14
  Scaleform::GFx::ResourceFileInfo *v7; // rax
  __int64 v8; // rsi
  Scaleform::GFx::Resource *v9; // rbx
  _DWORD *v10; // rax
  Scaleform::GFx::URLBuilder *v11; // rcx
  Scaleform::Render::Image *v12; // rdi
  Scaleform::GFx::MovieDefBindStates *v13; // r8
  __int64 v14; // rcx
  int v15; // eax
  Scaleform::GFx::ImageFileHandlerRegistry *v16; // rbx
  Scaleform::GFx::FileOpener *v17; // rdi
  Scaleform::Log *v18; // rax
  int v19; // edx
  __int64 v20; // rdi
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
  Scaleform::GFx::ResourceLibBase *v31; // rcx
  __int64 v32; // rbx
  Scaleform::GFx::ResourceLibBase *v33; // rcx
  Scaleform::GFx::Resource *v34; // rbx
  Scaleform::GFx::ResourceLibBase *v35; // rcx
  Scaleform::GFx::ResourceLib::BindHandle phandle; // [rsp+30h] [rbp-D0h]
  __int64 v38; // [rsp+40h] [rbp-C0h]
  Scaleform::Render::Image *pimage; // [rsp+48h] [rbp-B8h]
  __m128 v40; // [rsp+50h] [rbp-B0h]
  __m128 v41; // [rsp+60h] [rbp-A0h]
  Scaleform::MemoryHeap *pimageHeap; // [rsp+70h] [rbp-90h]
  Scaleform::GFx::ImageResource *v43; // [rsp+78h] [rbp-88h]
  Scaleform::GFx::ResourceKey result; // [rsp+80h] [rbp-80h]
  Scaleform::GFx::URLBuilder::LocationInfo loc; // [rsp+90h] [rbp-70h]
  int v46; // [rsp+A8h] [rbp-58h]
  Scaleform::MemoryHeap *v47; // [rsp+B0h] [rbp-50h]
  int v48; // [rsp+B8h] [rbp-48h]
  int v49; // [rsp+BCh] [rbp-44h]
  Scaleform::Log *v50; // [rsp+C0h] [rbp-40h]
  __int64 v51; // [rsp+C8h] [rbp-38h]
  __int64 v52; // [rsp+D0h] [rbp-30h]
  __int64 v53; // [rsp+D8h] [rbp-28h]
  int v54; // [rsp+E0h] [rbp-20h]
  Scaleform::MemoryHeap *v55; // [rsp+E8h] [rbp-18h]
  int v56; // [rsp+F0h] [rbp-10h]
  int v57; // [rsp+F4h] [rbp-Ch]
  Scaleform::Log *v58; // [rsp+F8h] [rbp-8h]
  __int128 v59; // [rsp+100h] [rbp+0h]
  __int64 v60; // [rsp+110h] [rbp+10h]
  Scaleform::Render::ImageFileFormat v61; // [rsp+118h] [rbp+18h]
  __int64 v62; // [rsp+120h] [rbp+20h]
  Scaleform::String v63; // [rsp+128h] [rbp+28h]
  int v64; // [rsp+130h] [rbp+30h]
  int v65; // [rsp+134h] [rbp+34h]
  Scaleform::MemoryHeap *v66; // [rsp+140h] [rbp+40h]
  __int64 v67; // [rsp+148h] [rbp+48h]
  __int64 v68; // [rsp+150h] [rbp+50h]
  Scaleform::String v69; // [rsp+1A8h] [rbp+A8h]
  Scaleform::GFx::ResourceBindData *v70; // [rsp+1B0h] [rbp+B0h]
  Scaleform::GFx::Resource *v71; // [rsp+1B8h] [rbp+B8h]

  v70 = pbindData;
  v68 = -2i64;
  v4 = pls;
  v5 = pbindData;
  v6 = (unsigned __int16 *)hdata;
  v7 = (Scaleform::GFx::ResourceFileInfo *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                             Scaleform::Memory::pGlobalHeap,
                                             56i64);
  v8 = (__int64)v7;
  v71 = (Scaleform::GFx::Resource *)v7;
  v9 = 0i64;
  if ( v7 )
  {
    Scaleform::GFx::ResourceFileInfo::ResourceFileInfo(v7, (Scaleform::GFx::ResourceFileInfo *)v6);
    *(_QWORD *)v8 = &Scaleform::GFx::ImageFileInfo::`vftable';
    Scaleform::String::String((Scaleform::String *)(v8 + 48));
    *(_WORD *)(v8 + 40) = v6[20];
    *(_WORD *)(v8 + 42) = v6[21];
    *(_DWORD *)(v8 + 44) = *((_DWORD *)v6 + 11);
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
  loc.Use = 2;
  Scaleform::String::String(&loc.FileName, (Scaleform::String *)v6 + 4);
  Scaleform::String::String(&loc.ParentPath, &v4->RelativePath);
  v11 = v4->pBindStates.pObject->pURLBulider.pObject;
  if ( v11 )
    ((void (__fastcall *)(Scaleform::GFx::URLBuilder *, __int64, Scaleform::GFx::URLBuilder::LocationInfo *))v11->vfptr[1].__vecDelDtor)(
      v11,
      v8 + 32,
      &loc);
  else
    Scaleform::GFx::URLBuilder::DefaultBuildURL((Scaleform::String *)(v8 + 32), &loc);
  pimageHeap = v4->pWeakResourceLib.pObject->pImageHeap.pObject;
  v66 = pimageHeap;
  Scaleform::GFx::ImageResource::CreateImageFileKey(
    &result,
    (Scaleform::GFx::ImageFileInfo *)v8,
    v4->pBindStates.pObject->pFileOpener.pObject,
    v4->pBindStates.pObject->pImageCreator.pObject,
    pimageHeap);
  Scaleform::String::String(&v69);
  phandle.State = 0;
  phandle.pResource = 0i64;
  v71 = 0i64;
  if ( (unsigned int)Scaleform::GFx::ResourceWeakLib::BindResourceKey(v4->pWeakResourceLib.pObject, &phandle, &result) == 3 )
  {
    v12 = 0i64;
    pimage = 0i64;
    v13 = v4->pBindStates.pObject;
    v14 = (__int64)v13->pImageCreator.pObject;
    v38 = v14;
    if ( !v14 )
      goto LABEL_70;
    v15 = *((_DWORD *)v6 + 11);
    if ( *((_QWORD *)v6 + 3) )
    {
      v54 = 2;
      v55 = pimageHeap;
      v56 = 0;
      v57 = v15;
      v58 = 0i64;
      _mm_store_si128((__m128i *)&v59, (__m128i)0i64);
      v60 = 0i64;
      Scaleform::String::String(&v63);
      v16 = v4->pImageFileHandlerRegistry.pObject;
      v17 = v4->pBindStates.pObject->pFileOpener.pObject;
      v18 = (Scaleform::Log *)v4->pLog.pObject;
      if ( v18 )
      {
        v18 = (Scaleform::Log *)v18[2].vfptr;
        if ( !v18 )
          v18 = Scaleform::Log::GetGlobalLog();
      }
      *(_QWORD *)&v59 = v17;
      v58 = v18;
      *((_QWORD *)&v59 + 1) = v16;
      v62 = *((_QWORD *)v6 + 3);
      v61 = Scaleform::GFx::LoaderImpl::FileFormat2RenderImageFile(*((Scaleform::GFx::FileTypeConstants::FileFormatType *)v6
                                                                   + 4));
      v19 = v6[21];
      v64 = v6[20];
      v65 = v19;
      Scaleform::String::operator=(&v63, (Scaleform::String *)v6 + 6);
      pimage = (Scaleform::Render::Image *)(*(__int64 (__fastcall **)(__int64, int *, __int64))(*(_QWORD *)v38 + 24i64))(
                                             v38,
                                             &v54,
                                             v8 + 32);
      if ( !_InterlockedDecrement((volatile signed __int32 *)((v63.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
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
      v20 = (__int64)v4->pImageFileHandlerRegistry.pObject;
      v21 = (__int64)v13->pFileOpener.pObject;
      v43 = (Scaleform::GFx::ImageResource *)v13->pFileOpener.pObject;
      v22 = v4->pLog.pObject;
      if ( v22 )
      {
        v23 = v22->pLog.pObject;
        if ( !v23 )
        {
          v23 = Scaleform::Log::GetGlobalLog();
          v14 = v38;
          v21 = (__int64)v43;
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
      goto LABEL_70;
    v40 = (__m128)_xmm;
    v41 = _xmm;
    v12->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v12->vfptr, (unsigned int)&v38);
    v24 = (__m128)COERCE_UNSIGNED_INT((float)v6[21]);
    v24.m128_f32[0] = v24.m128_f32[0] / (float)SHIDWORD(v38);
    v25 = (__m128)COERCE_UNSIGNED_INT((float)v6[20]);
    v25.m128_f32[0] = v25.m128_f32[0] / (float)(signed int)v38;
    v40 = _mm_mul_ps(v40, _mm_shuffle_ps(v25, v25, 0));
    v41 = _mm_mul_ps(v41, _mm_shuffle_ps(v24, v24, 0));
    ((void (__fastcall *)(Scaleform::Render::Image *, __m128 *, _QWORD))v12->vfptr[13].__vecDelDtor)(v12, &v40, 0i64);
    v26 = (Scaleform::GFx::ImageResource *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))pimageHeap->vfptr->Alloc)(
                                             pimageHeap,
                                             104i64);
    v43 = v26;
    if ( v26 )
    {
      Scaleform::GFx::ImageResource::ImageResource(
        v26,
        v12,
        &result,
        *((Scaleform::GFx::Resource::ResourceUse *)v6 + 11));
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
LABEL_70:
      Scaleform::String::operator=(&v69, "Failed to load image '");
      Scaleform::String::operator+=(&v69, (Scaleform::String *)(v8 + 32));
      Scaleform::String::AppendString(&v69, "'", -1i64);
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
    if ( phandle.State < 2 )
      v28 = &customWorldMapCaption;
    else
      v28 = (const char *)((*(_QWORD *)&phandle.pResource[2].RefCount.Value & 0xFFFFFFFFFFFFFFFCui64) + 12);
    Scaleform::String::operator=(&v69, v28);
  }
  if ( !v9 )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
      (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)&v4->pLog.pObject->vfptr,
      "%s",
      (v69.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
    v29 = 0;
    goto LABEL_47;
  }
LABEL_41:
  _InterlockedExchangeAdd(&v9->RefCount.Value, 1u);
  v30 = v5->pResource.pObject;
  if ( v5->pResource.pObject && !_InterlockedDecrement(&v30->RefCount.Value) )
  {
    v31 = v30->pLib;
    if ( v31 )
    {
      v31->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v31->vfptr, (unsigned int)v30);
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
      v33->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v33->vfptr, (unsigned int)v71);
      *(_QWORD *)(v32 + 16) = 0i64;
    }
    (**(void (__fastcall ***)(__int64, signed __int64))v32)(v32, 1i64);
  }
  if ( phandle.State == 1 )
  {
    if ( !_InterlockedDecrement(&phandle.pResource->RefCount.Value) )
    {
      v34 = phandle.pResource;
      v35 = phandle.pResource->pLib;
      if ( v35 )
      {
        v35->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v35->vfptr, (unsigned int)phandle.pResource);
        v34->pLib = 0i64;
      }
      v34->vfptr->__vecDelDtor(v34, 1u);
    }
  }
  else if ( phandle.State >= 2 )
  {
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)phandle.pResource);
  }
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v69.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  if ( result.pKeyInterface )
    result.pKeyInterface->vfptr->Release(result.pKeyInterface, result.hKeyData);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((loc.ParentPath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  if ( _InterlockedExchangeAdd(
         (volatile signed __int32 *)((loc.FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8),
         0xFFFFFFFF) == 1 )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v8);
  return v29;
}vfptr->Free)();
  if ( _InterlockedExchangeAdd(
         (volatile signed __int32 *)((loc.FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8),

// File Line: 633
// RVA: 0x8C0000
Scaleform::GFx::ResourceData *__fastcall Scaleform::GFx::ImageFileResourceCreator::CreateImageFileResourceData(Scaleform::GFx::ResourceData *result, Scaleform::GFx::ImageFileInfo *prfi)
{
  Scaleform::GFx::ImageFileInfo *v2; // rdi
  Scaleform::GFx::ResourceData *v3; // rbx

  v2 = prfi;
  v3 = result;
  if ( !(_S13_10 & 1) )
  {
    _S13_10 |= 1u;
    inst.vfptr = (Scaleform::GFx::ResourceData::DataInterfaceVtbl *)&Scaleform::GFx::ImageFileResourceCreator::`vftable';
    atexit(Scaleform::GFx::ImageFileResourceCreator::CreateImageFileResourceData_::_2_::_dynamic_atexit_destructor_for__inst__);
  }
  inst.vfptr->AddRef((Scaleform::GFx::ResourceData::DataInterface *)&inst, v2);
  v3->pInterface = (Scaleform::GFx::ResourceData::DataInterface *)&inst;
  v3->hData = v2;
  return v3;
}

// File Line: 643
// RVA: 0x8C3300
char __fastcall Scaleform::GFx::ImageResourceCreator::CreateResource(Scaleform::GFx::ImageResourceCreator *this, void *hdata, Scaleform::GFx::ResourceBindData *pbindData, Scaleform::GFx::LoadStates *pls, Scaleform::MemoryHeap *pbindHeap)
{
  Scaleform::GFx::LoadStates *v5; // rdi
  Scaleform::GFx::ResourceBindData *v6; // r15
  void *v7; // r14
  Scaleform::GFx::ImageFileHandlerRegistry *v8; // rsi
  Scaleform::GFx::FileOpener *v9; // rbp
  Scaleform::GFx::LogState *v10; // rax
  Scaleform::Log *v11; // rax
  Scaleform::GFx::ImageCreator *v12; // rcx
  Scaleform::Render::Image *v14; // r14
  char v15; // si
  Scaleform::GFx::ImageResource *v16; // rax
  Scaleform::GFx::Resource *v17; // rax
  Scaleform::GFx::Resource *v18; // rdi
  Scaleform::GFx::Resource *v19; // rsi
  Scaleform::GFx::ResourceLibBase *v20; // rcx
  Scaleform::GFx::ResourceLibBase *v21; // rcx
  int v22; // [rsp+28h] [rbp-60h]
  Scaleform::MemoryHeap *v23; // [rsp+30h] [rbp-58h]
  __int64 v24; // [rsp+38h] [rbp-50h]
  Scaleform::Log *v25; // [rsp+40h] [rbp-48h]
  Scaleform::GFx::FileOpener *v26; // [rsp+48h] [rbp-40h]
  Scaleform::GFx::ImageFileHandlerRegistry *v27; // [rsp+50h] [rbp-38h]
  __int64 v28; // [rsp+58h] [rbp-30h]

  v5 = pls;
  v6 = pbindData;
  v7 = hdata;
  v22 = 1;
  v23 = pbindHeap;
  v24 = 0i64;
  v25 = 0i64;
  v26 = 0i64;
  v27 = 0i64;
  v28 = 0i64;
  v8 = pls->pImageFileHandlerRegistry.pObject;
  v9 = pls->pBindStates.pObject->pFileOpener.pObject;
  v10 = pls->pLog.pObject;
  if ( v10 )
  {
    v11 = v10->pLog.pObject;
    if ( !v11 )
      v11 = Scaleform::Log::GetGlobalLog();
  }
  else
  {
    v11 = 0i64;
  }
  v26 = v9;
  v25 = v11;
  v27 = v8;
  v23 = pbindHeap;
  v12 = v5->pBindStates.pObject->pImageCreator.pObject;
  if ( !v12 )
    return 0;
  v14 = (Scaleform::Render::Image *)((__int64 (__fastcall *)(Scaleform::GFx::ImageCreator *, int *, void *))v12->vfptr[4].__vecDelDtor)(
                                      v12,
                                      &v22,
                                      v7);
  if ( v14 )
  {
    v16 = (Scaleform::GFx::ImageResource *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))pbindHeap->vfptr->Alloc)(
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
      v19 = v6->pResource.pObject;
      if ( v6->pResource.pObject && !_InterlockedDecrement(&v19->RefCount.Value) )
      {
        v20 = v19->pLib;
        if ( v20 )
        {
          v20->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v20->vfptr, (unsigned int)v19);
          v19->pLib = 0i64;
        }
        v19->vfptr->__vecDelDtor(v19, 1u);
      }
      v6->pResource.pObject = v18;
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
        v21->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v21->vfptr, (unsigned int)v18);
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
Scaleform::GFx::ResourceData *__fastcall Scaleform::GFx::ImageResourceCreator::CreateImageResourceData(Scaleform::GFx::ResourceData *result, Scaleform::Render::ImageSource *pimage)
{
  Scaleform::Render::ImageSource *v2; // rdi
  Scaleform::GFx::ResourceData *v3; // rbx

  v2 = pimage;
  v3 = result;
  if ( !(_S14_7 & 1) )
  {
    _S14_7 |= 1u;
    inst_0.vfptr = (Scaleform::GFx::ResourceData::DataInterfaceVtbl *)&Scaleform::GFx::ImageResourceCreator::`vftable';
    atexit(Scaleform::GFx::ImageResourceCreator::CreateImageResourceData_::_2_::_dynamic_atexit_destructor_for__inst__);
  }
  if ( v2 )
  {
    inst_0.vfptr->AddRef((Scaleform::GFx::ResourceData::DataInterface *)&inst_0, v2);
    v3->pInterface = (Scaleform::GFx::ResourceData::DataInterface *)&inst_0;
    v3->hData = v2;
  }
  else
  {
    v3->pInterface = 0i64;
    v3->hData = 0i64;
  }
  return v3;
}

// File Line: 688
// RVA: 0x8C34C0
char __fastcall Scaleform::GFx::SubImageResourceCreator::CreateResource(Scaleform::GFx::SubImageResourceCreator *this, void *hdata, Scaleform::GFx::ResourceBindData *pbindData, Scaleform::GFx::LoadStates *pls, Scaleform::MemoryHeap *pbindHeap)
{
  Scaleform::GFx::ResourceBindData *v5; // r14
  Scaleform::Render::Rect<unsigned long> *v6; // rbp
  Scaleform::GFx::ImageResource *v7; // rdi
  __int64 v8; // rdx
  Scaleform::GFx::Resource *v9; // rax
  Scaleform::GFx::ImageResource *v10; // rsi
  Scaleform::GFx::Resource *v11; // rsi
  Scaleform::GFx::ResourceLibBase *v12; // rcx
  Scaleform::GFx::SubImageResource *v14; // rax
  Scaleform::GFx::Resource *v15; // rax
  Scaleform::GFx::Resource *v16; // rsi
  Scaleform::GFx::Resource *v17; // rdi
  Scaleform::GFx::ResourceLibBase *v18; // rcx
  Scaleform::GFx::ResourceId baseid; // [rsp+30h] [rbp-48h]
  int v20; // [rsp+34h] [rbp-44h]
  __int64 v21; // [rsp+38h] [rbp-40h]
  Scaleform::GFx::SubImageResource *v22; // [rsp+40h] [rbp-38h]
  Scaleform::GFx::ResourceHandle v23; // [rsp+48h] [rbp-30h]
  int v24; // [rsp+88h] [rbp+10h]

  v21 = -2i64;
  v5 = pbindData;
  v6 = (Scaleform::Render::Rect<unsigned long> *)hdata;
  v7 = (Scaleform::GFx::ImageResource *)*((_QWORD *)hdata + 3);
  if ( !v7 )
  {
    v23.HType = 0;
    v23.pResource = 0i64;
    v20 = *((_DWORD *)hdata + 4);
    v8 = *(_QWORD *)(*(_QWORD *)&pbindData->pBinding->pOwnerDefRes[4].RefCount.Value + 24i64);
    v24 = v20;
    Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(
      *(Scaleform::GFx::MovieDataDef::LoadTaskData **)(v8 + 64),
      &v23,
      (Scaleform::GFx::ResourceId)&v24);
    v9 = Scaleform::GFx::ResourceHandle::GetResource(&v23, v5->pBinding);
    v10 = (Scaleform::GFx::ImageResource *)v9;
    if ( v9 && (v9->vfptr->GetResourceTypeCode(v9) & 0xFF00) == 256 )
      v7 = v10;
    if ( v23.HType == RH_Pointer && v23.pResource && !_InterlockedDecrement(&v23.pResource->RefCount.Value) )
    {
      v11 = v23.pResource;
      v12 = v23.pResource->pLib;
      if ( v12 )
      {
        v12->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v12->vfptr, (unsigned int)v23.pResource);
        v11->pLib = 0i64;
      }
      v11->vfptr->__vecDelDtor(v11, 1u);
    }
    if ( !v7 )
      return 0;
  }
  v14 = (Scaleform::GFx::SubImageResource *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64, _QWORD, Scaleform::GFx::LoadStates *))pbindHeap->vfptr->Alloc)(
                                              pbindHeap,
                                              128i64,
                                              0i64,
                                              pls);
  v22 = v14;
  if ( v14 )
  {
    baseid.Id = 0;
    Scaleform::GFx::SubImageResource::SubImageResource(v14, v7, (__int64)&baseid, v6 + 2);
    v16 = v15;
  }
  else
  {
    v16 = 0i64;
  }
  v17 = v5->pResource.pObject;
  if ( v5->pResource.pObject && !_InterlockedDecrement(&v17->RefCount.Value) )
  {
    v18 = v17->pLib;
    if ( v18 )
    {
      v18->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v18->vfptr, (unsigned int)v17);
      v17->pLib = 0i64;
    }
    v17->vfptr->__vecDelDtor(v17, 1u);
  }
  v5->pResource.pObject = v16;
  return 1;
}

// File Line: 722
// RVA: 0x8C3FC0
Scaleform::GFx::ResourceData *__fastcall Scaleform::GFx::SubImageResourceCreator::CreateSubImageResourceData(Scaleform::GFx::ResourceData *result, Scaleform::GFx::SubImageResourceInfo *pinfo)
{
  Scaleform::GFx::SubImageResourceInfo *v2; // rdi
  Scaleform::GFx::ResourceData *v3; // rbx

  v2 = pinfo;
  v3 = result;
  if ( !(_S15_7 & 1) )
  {
    _S15_7 |= 1u;
    inst_1.vfptr = (Scaleform::GFx::ResourceData::DataInterfaceVtbl *)&Scaleform::GFx::SubImageResourceCreator::`vftable';
    atexit(Scaleform::GFx::SubImageResourceCreator::CreateSubImageResourceData_::_2_::_dynamic_atexit_destructor_for__inst__);
  }
  inst_1.vfptr->AddRef((Scaleform::GFx::ResourceData::DataInterface *)&inst_1, v2);
  v3->pInterface = (Scaleform::GFx::ResourceData::DataInterface *)&inst_1;
  v3->hData = v2;
  return v3;
}

// File Line: 734
// RVA: 0x8C2AE0
bool __fastcall Scaleform::GFx::FontResourceCreator::CreateResource(Scaleform::GFx::FontResourceCreator *this, void *hdata, Scaleform::GFx::ResourceBindData *pbindData, Scaleform::GFx::LoadStates *pls, Scaleform::MemoryHeap *pbindHeap)
{
  Scaleform::GFx::LoadStates *v5; // r15
  Scaleform::GFx::ResourceBindData *v6; // r12
  Scaleform::Render::Font *v7; // r14
  unsigned int v8; // ebp
  __int64 v9; // rcx
  Scaleform::GFx::MovieDefImpl *v10; // r13
  Scaleform::GFx::FontDataUseNode *volatile v11; // rbx
  Scaleform::Render::Font *v12; // rsi
  int v13; // edi
  const char *v14; // rsi
  const char *v15; // rax
  unsigned int v16; // er8
  bool result; // al
  bool v18; // zf
  Scaleform::GFx::FontResource *v19; // rax
  Scaleform::GFx::Resource *v20; // rax
  Scaleform::GFx::Resource *v21; // rdi
  Scaleform::GFx::Resource *v22; // rbx
  Scaleform::GFx::ResourceLibBase *v23; // rcx

  v5 = pls;
  v6 = pbindData;
  v7 = (Scaleform::Render::Font *)hdata;
  v8 = 0;
  if ( pls->SubstituteFontMovieDefs.Data.Size )
  {
    v9 = 0i64;
    while ( 1 )
    {
      v10 = v5->SubstituteFontMovieDefs.Data.Data[v9].pObject;
      v11 = v10->pBindData.pObject->pDataDef.pObject->pData.pObject->BindData.pFonts.Value;
      if ( v11 )
        break;
LABEL_8:
      v9 = ++v8;
      if ( v8 >= v5->SubstituteFontMovieDefs.Data.Size )
        goto LABEL_15;
    }
    while ( 1 )
    {
      v12 = v11->pFontData.pObject;
      if ( ((unsigned int (__fastcall *)(Scaleform::Render::Font *))v12->vfptr[18].__vecDelDtor)(v11->pFontData.pObject) )
      {
        v13 = v12->Flags & 0x303;
        v14 = (const char *)((__int64 (__fastcall *)(Scaleform::Render::Font *))v12->vfptr[1].__vecDelDtor)(v12);
        if ( (v7->Flags & (v13 & 0x10 | ((v13 & 0x300) != 0 ? 0x300 : 0) | 3)) == (v13 & 0x313) )
        {
          v15 = (const char *)((__int64 (__fastcall *)(Scaleform::Render::Font *))v7->vfptr[1].__vecDelDtor)(v7);
          if ( !Scaleform::String::CompareNoCase(v15, v14) )
            break;
        }
      }
      v11 = v11->pNext.Value;
      if ( !v11 )
        goto LABEL_8;
    }
    v16 = v11->BindIndex;
    if ( v10->pBindData.pObject->ResourceBinding.Frozen && v16 < v10->pBindData.pObject->ResourceBinding.ResourceCount )
      Scaleform::GFx::ResourceBindData::operator=(v6, &v10->pBindData.pObject->ResourceBinding.pResources[v16]);
    else
      Scaleform::GFx::ResourceBinding::GetResourceData_Locked(&v10->pBindData.pObject->ResourceBinding, v6, v16);
    result = 1;
  }
  else
  {
LABEL_15:
    if ( !((unsigned __int8 (__fastcall *)(Scaleform::Render::Font *))v7->vfptr[19].__vecDelDtor)(v7)
      && ((__int64 (__fastcall *)(Scaleform::Render::Font *))v7->vfptr[1].__vecDelDtor)(v7) )
    {
      v7->Flags |= 0x40u;
    }
    v18 = v6->pResource.pObject == 0i64;
    if ( !v6->pResource.pObject )
    {
      v19 = (Scaleform::GFx::FontResource *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))pbindHeap->vfptr->Alloc)(
                                              pbindHeap,
                                              64i64);
      if ( v19 )
      {
        Scaleform::GFx::FontResource::FontResource(v19, v7, v6->pBinding);
        v21 = v20;
      }
      else
      {
        v21 = 0i64;
      }
      v22 = v6->pResource.pObject;
      if ( v6->pResource.pObject && !_InterlockedDecrement(&v22->RefCount.Value) )
      {
        v23 = v22->pLib;
        if ( v23 )
        {
          v23->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v23->vfptr, (unsigned int)v22);
          v22->pLib = 0i64;
        }
        v22->vfptr->__vecDelDtor(v22, 1u);
      }
      v6->pResource.pObject = v21;
      v18 = v21 == 0i64;
    }
    result = !v18;
  }
  return result;
}

