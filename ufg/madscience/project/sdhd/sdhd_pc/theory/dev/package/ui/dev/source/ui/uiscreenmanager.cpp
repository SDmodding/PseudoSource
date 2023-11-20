// File Line: 156
// RVA: 0xA29490
void __fastcall UFG::UIScreenManagerBase::baseInit(UFG::UIScreenManagerBase *this)
{
  UFG::UIScreenManagerBase *v1; // rsi
  char v2; // bl
  Scaleform::SysAllocBase *v3; // rax
  Scaleform::GFx::Loader *v4; // r15
  Scaleform::GFx::ZlibSupportBase *v5; // rax
  __int64 v6; // rax
  Scaleform::GFx::Loader *v7; // rax
  UFG::UIGfxFileOpener *v8; // rax
  UFG::UIGfxFileOpener *v9; // rcx
  __int64 v10; // rax
  Scaleform::Log *v11; // rbx
  __int64 v12; // rax
  Scaleform::Render::RenderBuffer *v13; // rbx
  __int64 v14; // rax
  Scaleform::Render::RenderBuffer *v15; // rbx
  Scaleform::GFx::ImageFileHandlerRegistry *v16; // rax
  Scaleform::GFx::ImageFileHandlerRegistry *v17; // rax
  Scaleform::GFx::ImageFileHandlerRegistry *v18; // r12
  __int64 v19; // rax
  Scaleform::Render::RenderBuffer *v20; // r14
  Scaleform::GFx::AS3Support *v21; // rax
  Scaleform::Render::RenderBuffer *v22; // rax
  Scaleform::Render::RenderBuffer *v23; // r15
  UFG::allocator::free_link *v24; // rax
  UFG::UIGfxTranslator *v25; // rax
  UFG::UIGfxTranslator *v26; // rax
  UFG::UIGfxTranslator *v27; // r13
  Scaleform::GFx::Loader *v28; // rbx
  Scaleform::GFx::DrawTextManager *v29; // rax
  Scaleform::GFx::DrawTextManager *v30; // rax
  Scaleform::Ptr<Scaleform::GFx::FontProvider> *v31; // rax
  Scaleform::GFx::DrawTextManager::TextParams *v32; // rbx
  _QWORD *v33; // rbx
  signed __int64 v34; // rdi
  UFG::UIInputHandler *v35; // rax
  UFG::UIInputHandler *v36; // rax
  const char **v37; // rbx
  Scaleform::GFx::DrawTextManager::TextParams params; // [rsp+40h] [rbp-C0h]
  Scaleform::MemoryHeap::HeapDesc rootHeapDesc; // [rsp+68h] [rbp-98h]
  Scaleform::Render::RenderBuffer *v40; // [rsp+A8h] [rbp-58h]
  Scaleform::Render::RenderBuffer *v41; // [rsp+B0h] [rbp-50h]
  Scaleform::Render::RenderBuffer *v42; // [rsp+B8h] [rbp-48h]
  Scaleform::GFx::Loader *v43; // [rsp+C0h] [rbp-40h]
  Scaleform::Render::Rect<float> viewRect; // [rsp+D0h] [rbp-30h]
  Scaleform::Render::RenderBuffer *v45; // [rsp+E0h] [rbp-20h]
  __int64 v46; // [rsp+E8h] [rbp-18h]
  Scaleform::GFx::ImageFileHandlerRegistry *v47; // [rsp+F0h] [rbp-10h]
  Scaleform::Log *v48; // [rsp+F8h] [rbp-8h]
  unsigned int v49; // [rsp+150h] [rbp+50h]
  Scaleform::Ptr<Scaleform::GFx::FileOpenerBase> pfileOpener; // [rsp+158h] [rbp+58h]
  Scaleform::Ptr<Scaleform::GFx::ZlibSupportBase> pzlib; // [rsp+160h] [rbp+60h]
  Scaleform::Ptr<Scaleform::GFx::FontProvider> result; // [rsp+168h] [rbp+68h]

  v46 = -2i64;
  v1 = this;
  v2 = 0;
  v3 = (Scaleform::SysAllocBase *)UFG::qMemoryPool::Allocate(
                                    &gScaleformMemoryPool,
                                    8ui64,
                                    "UIScreenManagerBase::baseInit",
                                    0i64,
                                    1u);
  if ( v3 )
  {
    v3->vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::SysAllocBase::`vftable';
    v3->vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::SysAlloc::`vftable';
    v3->vfptr = (Scaleform::SysAllocBaseVtbl *)&UIGfxAllocator::`vftable';
  }
  else
  {
    v3 = 0i64;
  }
  v1->m_gfxAllocator = (UIGfxAllocator *)v3;
  rootHeapDesc.Flags = 0;
  rootHeapDesc.MinAlign = 16i64;
  rootHeapDesc.Granularity = 0x4000i64;
  rootHeapDesc.Reserve = 0x4000i64;
  rootHeapDesc.Threshold = 0x40000i64;
  rootHeapDesc.Limit = 0i64;
  rootHeapDesc.HeapId = 1i64;
  rootHeapDesc.Arena = 0i64;
  Scaleform::GFx::System::Init(&rootHeapDesc, v3);
  v4 = (Scaleform::GFx::Loader *)UFG::qMalloc(0x20ui64, "UIScreenManagerBase::baseInit", 0i64);
  v43 = v4;
  if ( v4 )
  {
    v5 = (Scaleform::GFx::ZlibSupportBase *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                              Scaleform::Memory::pGlobalHeap,
                                              24ui64,
                                              0i64);
    if ( v5 )
    {
      v5->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
      v5->RefCount = 1;
      v5->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
      v5->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable';
      v5->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::State,2>::`vftable';
      v5->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::State::`vftable';
      v5->SType = 29;
      v5->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ZlibSupportBase::`vftable';
      v5->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ZlibSupport::`vftable';
    }
    else
    {
      v5 = 0i64;
    }
    pzlib.pObject = v5;
    v6 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
           Scaleform::Memory::pGlobalHeap,
           24i64);
    if ( v6 )
    {
      *(_QWORD *)v6 = &Scaleform::RefCountImplCore::`vftable';
      *(_DWORD *)(v6 + 8) = 1;
      *(_QWORD *)v6 = &Scaleform::RefCountImpl::`vftable';
      *(_QWORD *)v6 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable';
      *(_QWORD *)v6 = &Scaleform::RefCountBase<Scaleform::GFx::State,2>::`vftable';
      *(_QWORD *)v6 = &Scaleform::GFx::State::`vftable';
      *(_DWORD *)(v6 + 16) = 12;
      *(_QWORD *)v6 = &Scaleform::GFx::FileOpenerBase::`vftable';
      GFx_Compile_with_SF_BUILD_DEBUG = 0;
      *(_QWORD *)v6 = &Scaleform::GFx::FileOpener::`vftable';
    }
    else
    {
      v6 = 0i64;
    }
    pfileOpener.pObject = (Scaleform::GFx::FileOpenerBase *)v6;
    v2 = 3;
    Scaleform::GFx::Loader::Loader(v4, &pfileOpener, &pzlib);
  }
  else
  {
    v7 = 0i64;
  }
  v1->m_gfxMovieLoader = v7;
  if ( v2 & 2 )
  {
    v2 &= 0xFDu;
    if ( pfileOpener.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)pfileOpener.pObject);
  }
  if ( v2 & 1 && pzlib.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)pzlib.pObject);
  UFG::sUIGfxFileOpener_ThreadID = GetCurrentThreadId();
  v8 = (UFG::UIGfxFileOpener *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                 Scaleform::Memory::pGlobalHeap,
                                 32ui64,
                                 0i64);
  v9 = v8;
  if ( v8 )
  {
    v8->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
    v8->RefCount = 1;
    v8->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
    v8->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable';
    v8->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::State,2>::`vftable';
    v8->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::State::`vftable';
    v8->SType = 12;
    v8->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::FileOpenerBase::`vftable';
    GFx_Compile_with_SF_BUILD_DEBUG = 0;
    v8->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::FileOpener::`vftable';
    v8->vfptr = (Scaleform::RefCountImplCoreVtbl *)&UFG::UIGfxFileOpener::`vftable';
    v8->mUsingChunkFiles = 0;
  }
  else
  {
    v9 = 0i64;
  }
  v1->m_gfxFileOpener = v9;
  v9->vfptr[6].__vecDelDtor((Scaleform::RefCountImplCore *)&v9->vfptr, UFG::gUIChunkFiles);
  v1->m_gfxMovieLoader->vfptr->SetState(
    (Scaleform::GFx::StateBag *)&v1->m_gfxMovieLoader->vfptr,
    State_OrigScale9Parent|State_MaskNode,
    (Scaleform::GFx::State *)&v1->m_gfxFileOpener->vfptr);
  v10 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
          Scaleform::Memory::pGlobalHeap,
          16i64);
  v11 = (Scaleform::Log *)v10;
  if ( v10 )
  {
    *(_QWORD *)v10 = &Scaleform::RefCountImplCore::`vftable';
    *(_DWORD *)(v10 + 8) = 1;
    *(_QWORD *)v10 = &Scaleform::RefCountImpl::`vftable';
    *(_QWORD *)v10 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable';
    *(_QWORD *)v10 = &Scaleform::RefCountBase<Scaleform::Log,2>::`vftable';
    *(_QWORD *)v10 = &Scaleform::Log::`vftable';
    *(_QWORD *)v10 = &UFG::UIGfxLog::`vftable';
  }
  else
  {
    v11 = 0i64;
  }
  v48 = v11;
  Scaleform::GFx::StateBag::SetLog((Scaleform::GFx::StateBag *)&v1->m_gfxMovieLoader->vfptr, v11);
  if ( v11 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v11);
  v12 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
          Scaleform::Memory::pGlobalHeap,
          24i64);
  v13 = (Scaleform::Render::RenderBuffer *)v12;
  if ( v12 )
  {
    *(_QWORD *)v12 = &Scaleform::RefCountImplCore::`vftable';
    *(_DWORD *)(v12 + 8) = 1;
    *(_QWORD *)v12 = &Scaleform::RefCountImpl::`vftable';
    *(_QWORD *)v12 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable';
    *(_QWORD *)v12 = &Scaleform::RefCountBase<Scaleform::GFx::State,2>::`vftable';
    *(_QWORD *)v12 = &Scaleform::GFx::State::`vftable';
    *(_DWORD *)(v12 + 16) = 5;
    *(_QWORD *)v12 = &Scaleform::GFx::FSCommandHandler::`vftable';
    *(_QWORD *)v12 = &UFG::UIGfxFsCommandHandler::`vftable';
  }
  else
  {
    v13 = 0i64;
  }
  v45 = v13;
  v1->m_gfxMovieLoader->vfptr->SetState(
    (Scaleform::GFx::StateBag *)&v1->m_gfxMovieLoader->vfptr,
    State_ViewMatrix3D,
    (Scaleform::GFx::State *)v13);
  if ( v13 )
    Scaleform::RefCountImpl::Release(v13);
  v14 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
          Scaleform::Memory::pGlobalHeap,
          24i64);
  v15 = (Scaleform::Render::RenderBuffer *)v14;
  if ( v14 )
  {
    *(_QWORD *)v14 = &Scaleform::RefCountImplCore::`vftable';
    *(_DWORD *)(v14 + 8) = 1;
    *(_QWORD *)v14 = &Scaleform::RefCountImpl::`vftable';
    *(_QWORD *)v14 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable';
    *(_QWORD *)v14 = &Scaleform::RefCountBase<Scaleform::GFx::State,2>::`vftable';
    *(_QWORD *)v14 = &Scaleform::GFx::State::`vftable';
    *(_DWORD *)(v14 + 16) = 6;
    *(_QWORD *)v14 = &Scaleform::GFx::ExternalInterface::`vftable';
    *(_QWORD *)v14 = &UFG::UIGfxExternalInterface::`vftable';
  }
  else
  {
    v15 = 0i64;
  }
  v40 = v15;
  v1->m_gfxMovieLoader->vfptr->SetState(
    (Scaleform::GFx::StateBag *)&v1->m_gfxMovieLoader->vfptr,
    State_ProjectionMatrix3D,
    (Scaleform::GFx::State *)v15);
  if ( v15 )
    Scaleform::RefCountImpl::Release(v15);
  v16 = (Scaleform::GFx::ImageFileHandlerRegistry *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                      Scaleform::Memory::pGlobalHeap,
                                                      56i64);
  if ( v16 )
  {
    Scaleform::GFx::ImageFileHandlerRegistry::ImageFileHandlerRegistry(v16, 0);
    v18 = v17;
  }
  else
  {
    v18 = 0i64;
  }
  v47 = v18;
  Scaleform::GFx::ImageFileHandlerRegistry::AddHandler(
    v18,
    (Scaleform::Render::ImageFileHandler *)&Scaleform::Render::TGA::FileReader::Instance.vfptr);
  v1->m_gfxMovieLoader->vfptr->SetState(
    (Scaleform::GFx::StateBag *)&v1->m_gfxMovieLoader->vfptr,
    State_Type_Count|State_MaskNode,
    (Scaleform::GFx::State *)&v18->vfptr);
  v19 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
          Scaleform::Memory::pGlobalHeap,
          24i64);
  v20 = (Scaleform::Render::RenderBuffer *)v19;
  if ( v19 )
  {
    *(_QWORD *)v19 = &Scaleform::RefCountImplCore::`vftable';
    *(_DWORD *)(v19 + 8) = 1;
    *(_QWORD *)v19 = &Scaleform::RefCountImpl::`vftable';
    *(_QWORD *)v19 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable';
    *(_QWORD *)v19 = &Scaleform::RefCountBase<Scaleform::GFx::State,2>::`vftable';
    *(_QWORD *)v19 = &Scaleform::GFx::State::`vftable';
    *(_DWORD *)(v19 + 16) = 38;
    *(_QWORD *)v19 = &Scaleform::GFx::ASSupport::`vftable';
    *(_QWORD *)v19 = &Scaleform::GFx::AS2Support::`vftable';
  }
  else
  {
    v20 = 0i64;
  }
  v41 = v20;
  v1->m_gfxMovieLoader->vfptr->SetState(
    (Scaleform::GFx::StateBag *)&v1->m_gfxMovieLoader->vfptr,
    State_ProjectionMatrix3D|0x20,
    (Scaleform::GFx::State *)v20);
  v21 = (Scaleform::GFx::AS3Support *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                        Scaleform::Memory::pGlobalHeap,
                                        24i64);
  if ( v21 )
  {
    Scaleform::GFx::AS3Support::AS3Support(v21);
    v23 = v22;
  }
  else
  {
    v23 = 0i64;
  }
  v42 = v23;
  v1->m_gfxMovieLoader->vfptr->SetState(
    (Scaleform::GFx::StateBag *)&v1->m_gfxMovieLoader->vfptr,
    State_UserData|0x20,
    (Scaleform::GFx::State *)v23);
  v24 = UFG::qMalloc(0x18ui64, UFG::gGlobalNewName, 0i64);
  if ( v24 )
  {
    v24->mNext = (UFG::allocator::free_link *)&Scaleform::Render::ThreadCommandQueue::`vftable';
    v24->mNext = (UFG::allocator::free_link *)&UFG::UIThreadCommandQueue::`vftable';
  }
  else
  {
    v24 = 0i64;
  }
  v1->mThreadCommandQueue = (UFG::UIThreadCommandQueue *)v24;
  v25 = (UFG::UIGfxTranslator *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                  Scaleform::Memory::pGlobalHeap,
                                  144ui64,
                                  0i64);
  if ( v25 )
  {
    UFG::UIGfxTranslator::UIGfxTranslator(v25);
    v27 = v26;
  }
  else
  {
    v27 = 0i64;
  }
  v1->m_translator = v27;
  v28 = v1->m_gfxMovieLoader;
  v27->mScreenFactory = v1->m_screenFactory;
  v28->vfptr->SetState((Scaleform::GFx::StateBag *)&v28->vfptr, State_BlendMode, (Scaleform::GFx::State *)&v27->vfptr);
  v27->mGfxLoader = v28;
  UFG::UIGfxTranslator::setLanguage(v1->m_translator, eLang_English, 1);
  v29 = (Scaleform::GFx::DrawTextManager *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                             Scaleform::Memory::pGlobalHeap,
                                             40i64);
  if ( v29 )
    Scaleform::GFx::DrawTextManager::DrawTextManager(v29, v1->m_gfxMovieLoader);
  else
    v30 = 0i64;
  v1->m_gfxDrawTextManager = v30;
  v31 = Scaleform::GFx::StateBag::GetFontProvider((Scaleform::GFx::StateBag *)&v1->m_gfxMovieLoader->vfptr, &result);
  v1->m_gfxDrawTextManager->vfptr->SetState(
    (Scaleform::GFx::StateBag *)&v1->m_gfxDrawTextManager->vfptr,
    State_ProjectionMatrix3D|0x10,
    (Scaleform::GFx::State *)&v31->pObject->vfptr);
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
  v32 = Scaleform::GFx::DrawTextManager::GetDefaultTextParams(v1->m_gfxDrawTextManager);
  params.TextColor.Raw = v32->TextColor.Raw;
  params.HAlignment = v32->HAlignment;
  params.VAlignment = v32->VAlignment;
  params.FontStyle = v32->FontStyle;
  params.FontSize = v32->FontSize;
  Scaleform::String::String(&params.FontName, &v32->FontName);
  params.Underline = v32->Underline;
  params.Multiline = v32->Multiline;
  params.WordWrap = v32->WordWrap;
  *(_WORD *)((char *)&v49 + 1) = -1;
  LOBYTE(v49) = -1;
  HIBYTE(v49) = -1;
  params.TextColor.Raw = v49;
  Scaleform::String::operator=(&params.FontName, "$TitleFont");
  params.FontSize = FLOAT_24_0;
  Scaleform::GFx::DrawTextManager::SetDefaultTextParams(v1->m_gfxDrawTextManager, &params);
  viewRect = 0i64;
  v33 = v1->m_drawText;
  v34 = 32i64;
  do
  {
    *v33 = Scaleform::GFx::DrawTextManager::CreateHtmlText(
             v1->m_gfxDrawTextManager,
             &customWorldMapCaption,
             &viewRect,
             0i64,
             0xFFFFFFFF);
    ++v33;
    --v34;
  }
  while ( v34 );
  UFG::UIScreenManagerBase::initViewport(v1, 0i64);
  v35 = (UFG::UIInputHandler *)UFG::qMemoryPool::Allocate(
                                 &gScaleformMemoryPool,
                                 0xDCui64,
                                 "UIScreenManagerBase::UIInputHandler",
                                 0i64,
                                 1u);
  if ( v35 )
    UFG::UIInputHandler::UIInputHandler(v35);
  else
    v36 = 0i64;
  v1->m_inputHandler = v36;
  UFG::UIScreenManagerBase::initCustomRendering(v1);
  v37 = UFG::gLanguageOverrideNames;
  do
  {
    *v37 = UFG::UILanguages::getLanguageString((UFG::UILanguages::eLanguage)v34);
    LODWORD(v34) = v34 + 1;
    ++v37;
  }
  while ( (signed int)v34 < 24 );
  if ( !_InterlockedDecrement((volatile signed __int32 *)((params.FontName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  if ( v23 )
    Scaleform::RefCountImpl::Release(v23);
  if ( v20 )
    Scaleform::RefCountImpl::Release(v20);
  if ( v18 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v18);
}

// File Line: 295
// RVA: 0xA2FF80
void __fastcall UFG::UIScreenManagerBase::initViewport(UFG::UIScreenManagerBase *this, UFG::UIScreen *single_screen)
{
  UFG::UIScreen *v2; // rbx
  UFG::UIScreenManagerBase *v3; // rdi
  Illusion::Target *v4; // rax
  int v5; // ecx
  int v6; // er8
  float v7; // xmm4_4
  int v8; // esi
  int y; // er14
  float v10; // xmm5_4
  int width; // ebp
  int height; // er15
  float v13; // xmm0_4
  Scaleform::GFx::DrawTextManager *v14; // rcx
  signed __int64 v15; // r12
  signed __int64 i; // rbx
  signed __int64 j; // rbx
  Scaleform::Render::Viewport vp; // [rsp+40h] [rbp-48h]

  v2 = single_screen;
  v3 = this;
  this->m_targetWidth = Render::GetBackBufferTarget()->mWidth;
  v4 = Render::GetBackBufferTarget();
  v5 = v3->m_targetWidth;
  v6 = v4->mHeight;
  v7 = (float)v5;
  v3->m_targetHeight = v6;
  v8 = 0;
  y = 0;
  v10 = (float)v6;
  width = v5;
  height = v6;
  v13 = (float)v5 / (float)v6;
  if ( v13 <= 5.3333335 )
  {
    if ( v13 > 3.5555556 )
    {
      v8 = v5 / 3u;
      width = v5 / 3u;
    }
  }
  else
  {
    width = (signed int)(float)((float)((float)v6 * 16.0) * 0.11111111);
    v8 = (unsigned int)(v5 - width) >> 1;
  }
  if ( !v3->mScaleViewportInCode && UFG::gUIViewportScale != 1.0 && UFG::gUIViewportScale > 0.0 )
  {
    width = (signed int)(float)(v7 * UFG::gUIViewportScale);
    v8 = (signed int)(float)((float)((float)(1.0 - UFG::gUIViewportScale) * v7) * 0.5);
    height = (signed int)(float)(v10 * UFG::gUIViewportScale);
    y = (signed int)(float)((float)(v10 * (float)(1.0 - UFG::gUIViewportScale)) * 0.5);
  }
  if ( v2 )
  {
    UFG::UIScreenRenderable::setViewport(v2->mRenderable, v5, v6, v8, y, width, height);
  }
  else
  {
    vp.BufferWidth = v5;
    v14 = v3->m_gfxDrawTextManager;
    vp.BufferHeight = v6;
    vp.Left = v8;
    vp.Top = y;
    vp.Width = width;
    vp.Height = height;
    *(_QWORD *)&vp.ScissorHeight = 0i64;
    *(_QWORD *)&vp.ScissorTop = 0i64;
    vp.ScissorLeft = 0;
    Scaleform::GFx::DrawTextManager::SetViewport(v14, &vp);
    v15 = (signed __int64)&v3->m_screenStack.mNode.mNext;
    for ( i = (signed __int64)&v3->m_screenStack.mNode.mNext[-1].mNext;
          (UFG::UIScreenManagerBase *)i != v3;
          i = *(_QWORD *)(i + 16) - 8i64 )
    {
      UFG::UIScreenRenderable::setViewport(
        *(UFG::UIScreenRenderable **)(i + 96),
        v3->m_targetWidth,
        v3->m_targetHeight,
        v8,
        y,
        width,
        height);
    }
    for ( j = (signed __int64)&v3->m_overlayStack.mNode.mNext[-1].mNext; j != v15; j = *(_QWORD *)(j + 16) - 8i64 )
      UFG::UIScreenRenderable::setViewport(
        *(UFG::UIScreenRenderable **)(j + 96),
        v3->m_targetWidth,
        v3->m_targetHeight,
        v8,
        y,
        width,
        height);
  }
}

// File Line: 362
// RVA: 0xA2BF10
void __fastcall UFG::UIScreenManagerBase::getViewportOffsetAndScale(UFG::UIScreenManagerBase *this, UFG::qVector2 *offset, UFG::qVector2 *scale)
{
  signed int v3; // er9
  signed int v4; // er10
  signed int v5; // er11
  signed int v6; // ebx
  signed int v7; // edi
  signed int v8; // esi
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm3_4
  float v13; // xmm1_4

  v3 = this->m_targetWidth;
  v4 = this->m_targetHeight;
  v5 = 0;
  v6 = 0;
  v7 = this->m_targetWidth;
  v8 = this->m_targetHeight;
  if ( UFG::gUIViewportScale != 1.0 && UFG::gUIViewportScale > 0.0 )
  {
    v5 = (signed int)(float)((float)((float)v3 * (float)(1.0 - UFG::gUIViewportScale)) * 0.5);
    v7 = (signed int)(float)((float)v3 * UFG::gUIViewportScale);
    v6 = (signed int)(float)((float)((float)v4 * (float)(1.0 - UFG::gUIViewportScale)) * 0.5);
    v8 = (signed int)(float)((float)v4 * UFG::gUIViewportScale);
  }
  v9 = (float)v3 / (float)v4;
  v10 = 1.7777778 - v9;
  if ( (float)(1.7777778 - v9) < 0.0 )
    LODWORD(v10) ^= _xmm[0];
  if ( v10 >= 0.001 )
  {
    v12 = v9 * 0.5625;
    if ( v9 >= 1.7777778 )
    {
      if ( v9 > 1.7777778 )
      {
        offset->y = 0.0;
        offset->x = (float)((float)v3 - (float)((float)(1.0 / v12) * (float)v3)) * 0.5;
        scale->x = (float)((float)v7 * (float)(1.0 / v12)) / (float)(signed int)this->m_flashWidth;
        scale->y = (float)v8 / (float)(signed int)this->m_flashHeight;
        v5 = (signed int)(float)((float)v5 * v12);
      }
    }
    else
    {
      offset->x = 0.0;
      offset->y = (float)((float)(signed int)this->m_targetHeight - (float)((float)v4 * v12)) * 0.5;
      scale->x = (float)v7 / (float)(signed int)this->m_flashWidth;
      scale->y = (float)((float)v8 * v12) / (float)(signed int)this->m_flashHeight;
      v6 = (signed int)(float)((float)v6 * v12);
    }
  }
  else
  {
    v11 = UFG::qVector2::msZero.y;
    offset->x = UFG::qVector2::msZero.x;
    offset->y = v11;
    scale->x = (float)v7 / (float)(signed int)this->m_flashWidth;
    scale->y = (float)v8 / (float)(signed int)this->m_flashHeight;
  }
  v13 = (float)v6 + offset->y;
  offset->x = (float)v5 + offset->x;
  offset->y = v13;
}

// File Line: 445
// RVA: 0xA29D10
void __fastcall UFG::UIScreenManagerBase::baseQuit(UFG::UIScreenManagerBase *this)
{
  UFG::UIScreenManagerBase *v1; // rdi
  int *v2; // rax
  int *v3; // rbx
  _QWORD *v4; // rdx
  __int64 v5; // rcx
  _QWORD *v6; // rax
  signed __int64 i; // rax
  _QWORD *v8; // rdx
  __int64 v9; // rcx
  _QWORD *v10; // rax
  signed __int64 j; // rax
  _QWORD *v12; // rdx
  __int64 v13; // rcx
  _QWORD *v14; // rax
  signed __int64 k; // rax
  _QWORD *v16; // rdx
  __int64 v17; // rcx
  _QWORD *v18; // rax
  signed __int64 l; // rax
  _QWORD *v20; // rdx
  __int64 v21; // rcx
  _QWORD *v22; // rax
  signed __int64 m; // rax
  _QWORD *v24; // rdx
  __int64 v25; // rcx
  _QWORD *v26; // rax
  UFG::UIInputHandler *v27; // rbx
  Scaleform::GFx::Loader *v28; // rcx
  Scaleform::GFx::DrawText **v29; // rax
  signed __int64 v30; // rcx

  v1 = this;
  v2 = (int *)&this->m_commandQueue.mNode.mNext[-1].mNext;
  v3 = &this->m_defaultControllerMask;
  if ( v2 != &this->m_defaultControllerMask )
  {
    do
    {
      v4 = v2 + 2;
      v5 = *((_QWORD *)v2 + 1);
      v6 = (_QWORD *)*((_QWORD *)v2 + 2);
      *(_QWORD *)(v5 + 8) = v6;
      *v6 = v5;
      *v4 = v4;
      v4[1] = v4;
      if ( v4 != (_QWORD *)8 )
        (*(void (__fastcall **)(_QWORD *, signed __int64))*(v4 - 1))(v4 - 1, 1i64);
      v2 = (int *)&v1->m_commandQueue.mNode.mNext[-1].mNext;
    }
    while ( v2 != v3 );
  }
  for ( i = (signed __int64)&v1->m_screenCommandQueue.mNode.mNext[-1].mNext;
        (UFG::qNode<UFG::UICommand,UFG::UICommand> **)i != &v1->m_commandQueue.mNode.mNext;
        i = (signed __int64)&v1->m_screenCommandQueue.mNode.mNext[-1].mNext )
  {
    v8 = (_QWORD *)(i + 8);
    v9 = *(_QWORD *)(i + 8);
    v10 = *(_QWORD **)(i + 16);
    *(_QWORD *)(v9 + 8) = v10;
    *v10 = v9;
    *v8 = v8;
    v8[1] = v8;
    if ( v8 != (_QWORD *)8 )
      (*(void (__fastcall **)(_QWORD *, signed __int64))*(v8 - 1))(v8 - 1, 1i64);
  }
  for ( j = (signed __int64)&v1->m_pendingMessages.mNode.mNext[-1].mNext;
        (UFG::qNode<UFG::UICommand,UFG::UICommand> **)j != &v1->m_screenCommandQueue.mNode.mNext;
        j = (signed __int64)&v1->m_pendingMessages.mNode.mNext[-1].mNext )
  {
    v12 = (_QWORD *)(j + 8);
    v13 = *(_QWORD *)(j + 8);
    v14 = *(_QWORD **)(j + 16);
    *(_QWORD *)(v13 + 8) = v14;
    *v14 = v13;
    *v12 = v12;
    v12[1] = v12;
    if ( v12 != (_QWORD *)8 )
      (*(void (__fastcall **)(_QWORD *, signed __int64))*(v12 - 1))(v12 - 1, 1i64);
  }
  EnterCriticalSection(&v1->mScreenStackLock.cs);
  for ( k = (signed __int64)&v1->m_screenStack.mNode.mNext[-1].mNext;
        (UFG::UIScreenManagerBase *)k != v1;
        k = (signed __int64)&v1->m_screenStack.mNode.mNext[-1].mNext )
  {
    v16 = (_QWORD *)(k + 8);
    v17 = *(_QWORD *)(k + 8);
    v18 = *(_QWORD **)(k + 16);
    *(_QWORD *)(v17 + 8) = v18;
    *v18 = v17;
    *v16 = v16;
    v16[1] = v16;
    if ( v16 != (_QWORD *)8 )
      (*(void (__fastcall **)(_QWORD *, signed __int64))*(v16 - 1))(v16 - 1, 1i64);
  }
  for ( l = (signed __int64)&v1->m_overlayStack.mNode.mNext[-1].mNext;
        (UFG::qNode<UFG::UIScreen,UFG::UIScreen> **)l != &v1->m_screenStack.mNode.mNext;
        l = (signed __int64)&v1->m_overlayStack.mNode.mNext[-1].mNext )
  {
    v20 = (_QWORD *)(l + 8);
    v21 = *(_QWORD *)(l + 8);
    v22 = *(_QWORD **)(l + 16);
    *(_QWORD *)(v21 + 8) = v22;
    *v22 = v21;
    *v20 = v20;
    v20[1] = v20;
    if ( v20 != (_QWORD *)8 )
      (*(void (__fastcall **)(_QWORD *, signed __int64))*(v20 - 1))(v20 - 1, 1i64);
  }
  for ( m = (signed __int64)&v1->mPendingPoppedScreens.mNode.mNext[-1].mNext;
        (UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> **)m != &v1->mPendingOverlayLoads.mNode.mNext;
        m = (signed __int64)&v1->mPendingPoppedScreens.mNode.mNext[-1].mNext )
  {
    v24 = (_QWORD *)(m + 8);
    v25 = *(_QWORD *)(m + 8);
    v26 = *(_QWORD **)(m + 16);
    *(_QWORD *)(v25 + 8) = v26;
    *v26 = v25;
    *v24 = v24;
    v24[1] = v24;
    if ( v24 != (_QWORD *)8 )
      (*(void (__fastcall **)(_QWORD *, signed __int64))*(v24 - 1))(v24 - 1, 1i64);
  }
  LeaveCriticalSection(&v1->mScreenStackLock.cs);
  UFG::qList<UFG::InputMessage,UFG::InputMessage,1,0>::DeleteNodes((UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)&v1->mPendingScreenLoads);
  UFG::qList<UFG::InputMessage,UFG::InputMessage,1,0>::DeleteNodes((UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)&v1->mPendingOverlayLoads);
  v27 = v1->m_inputHandler;
  if ( v27 )
  {
    UFG::UIInputHandler::~UIInputHandler(v1->m_inputHandler);
    UFG::qMemoryPool::Free(&gScaleformMemoryPool, v27);
    v1->m_inputHandler = 0i64;
  }
  v28 = v1->m_gfxMovieLoader;
  if ( v28 )
  {
    ((void (__fastcall *)(Scaleform::GFx::Loader *, signed __int64))v28->vfptr->~StateBag)(v28, 1i64);
    v1->m_gfxMovieLoader = 0i64;
  }
  v29 = v1->m_drawText;
  v30 = 4i64;
  do
  {
    *v29 = 0i64;
    v29[1] = 0i64;
    v29[2] = 0i64;
    v29 += 8;
    *(v29 - 5) = 0i64;
    *(v29 - 4) = 0i64;
    *(v29 - 3) = 0i64;
    *(v29 - 2) = 0i64;
    *(v29 - 1) = 0i64;
    --v30;
  }
  while ( v30 );
  Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v1->m_gfxDrawTextManager->vfptr);
  v1->m_gfxDrawTextManager = 0i64;
  Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v1->m_gfxFileOpener);
  v1->m_gfxFileOpener = 0i64;
  Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v1->m_translator);
  v1->m_translator = 0i64;
}

// File Line: 562
// RVA: 0xA25E00
void __fastcall UFG::UIScreenManagerBase::CheckPendingMessages(UFG::UIScreenManagerBase *this, UFG::UIScreen *screen)
{
  UFG::UIScreenManagerBase *v2; // rbx
  unsigned int v3; // ebp
  Scaleform::GFx::Movie *v4; // r14
  UFG::qList<UFG::UICommand,UFG::UICommand,1,0> *i; // rdi
  __int64 *v6; // rdx
  __int64 v7; // rcx
  __int64 *v8; // rax
  __int64 *v9; // rax
  __int64 v10; // rax
  __int64 **j; // rsi
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v12; // rdx
  __int64 v13; // rcx
  _QWORD *v14; // rax
  signed __int64 v15; // rax
  signed int v16; // ecx
  UFG::qList<UFG::UICommand,UFG::UICommand,1,0> *v17; // rdx
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v18; // rcx
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v19; // rax
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v20; // rax
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v21; // rax
  __int64 k; // rax
  _QWORD *v23; // rdx
  __int64 v24; // rcx
  _QWORD *v25; // rax
  __int64 *v26; // rcx
  __int64 **v27; // rax
  __int64 v28; // [rsp+0h] [rbp-58h]
  __int64 v29; // [rsp+20h] [rbp-38h]
  __int64 *v30; // [rsp+28h] [rbp-30h]
  __int64 **v31; // [rsp+30h] [rbp-28h]

  v29 = -2i64;
  v2 = this;
  v3 = screen->mScreenUID;
  v4 = screen->mRenderable->m_movie.pObject;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->m_pendingMessagesMutex);
  v30 = (__int64 *)&v30;
  v31 = &v30;
  for ( i = &v2->m_pendingMessages;
        &v2->m_pendingMessages.mNode.mNext[-1].mNext != &v2->m_screenCommandQueue.mNode.mNext;
        v30 = v6 )
  {
    v6 = (__int64 *)v2->m_pendingMessages.mNode.mNext;
    v7 = *v6;
    v8 = (__int64 *)v6[1];
    *(_QWORD *)(v7 + 8) = v8;
    *v8 = v7;
    *v6 = (__int64)v6;
    v6[1] = (__int64)v6;
    v9 = v30;
    v30[1] = (__int64)v6;
    *v6 = (__int64)v9;
    v6[1] = (__int64)&v30;
  }
  v10 = (__int64)(v31 - 1);
  for ( j = (__int64 **)(&v28 + 4); v31 - 1 != j; v10 = (__int64)(v31 - 1) )
  {
    v12 = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)(v10 + 8);
    v13 = *(_QWORD *)(v10 + 8);
    v14 = *(_QWORD **)(v10 + 16);
    *(_QWORD *)(v13 + 8) = v14;
    *v14 = v13;
    v12->mPrev = v12;
    v12->mNext = v12;
    v15 = (signed __int64)&v12[-1].mNext;
    if ( LODWORD(v12[2].mNext) != v3 )
    {
      if ( *(_DWORD *)(v15 + 24) != 7 )
      {
        v21 = i->mNode.mPrev;
        v21->mNext = v12;
        v12->mPrev = v21;
        v12->mNext = &i->mNode;
        i->mNode.mPrev = v12;
        continue;
      }
      if ( v4 != *(Scaleform::GFx::Movie **)(v15 + 96) )
      {
        v20 = i->mNode.mPrev;
        v20->mNext = v12;
        v12->mPrev = v20;
        v12->mNext = &i->mNode;
        i->mNode.mPrev = v12;
        continue;
      }
      *(_DWORD *)(v15 + 48) = v3;
      if ( !UFG::gTweakerUpdateUI || !v2->m_updateUI )
      {
LABEL_13:
        (**(void (__fastcall ***)(signed __int64, signed __int64))v15)(v15, 1i64);
        continue;
      }
      v17 = &v2->m_commandQueue;
      goto LABEL_12;
    }
    if ( !UFG::gTweakerUpdateUI || !v2->m_updateUI )
      goto LABEL_13;
    v16 = *(_DWORD *)(v15 + 24);
    if ( v16 >= 0 )
    {
      if ( v16 <= 4 )
      {
        v17 = &v2->m_screenCommandQueue;
        goto LABEL_12;
      }
      if ( v16 <= 7 )
      {
        v17 = &v2->m_commandQueue;
LABEL_12:
        v18 = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)(v15 + 8);
        v19 = v17->mNode.mPrev;
        v19->mNext = v18;
        v18->mPrev = v19;
        v18->mNext = &v17->mNode;
        v17->mNode.mPrev = v18;
        continue;
      }
    }
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v2->m_pendingMessagesMutex);
  for ( k = (__int64)(v31 - 1); v31 - 1 != j; k = (__int64)(v31 - 1) )
  {
    v23 = (_QWORD *)(k + 8);
    v24 = *(_QWORD *)(k + 8);
    v25 = *(_QWORD **)(k + 16);
    *(_QWORD *)(v24 + 8) = v25;
    *v25 = v24;
    *v23 = v23;
    v23[1] = v23;
    if ( v23 != (_QWORD *)8 )
      (*(void (__fastcall **)(_QWORD *, signed __int64))*(v23 - 1))(v23 - 1, 1i64);
  }
  v26 = v30;
  v27 = v31;
  v30[1] = (__int64)v31;
  *v27 = v26;
}all **)(_QWORD *, signed __int64))*(v23 - 1))(v23 - 1, 1i64);
  }
  v26 = v30;
  v27

// File Line: 610
// RVA: 0xA328C0
void __fastcall UFG::UIScreenManagerBase::updatePendingLoads(UFG::UIScreenManagerBase *this, float elapsed)
{
  UFG::UIScreenManagerBase *v2; // rbp
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v3; // rsi
  UFG::UIScreen *v4; // r14
  Scaleform::GFx::Movie *v5; // rbx
  Scaleform::RefCountImplCoreVtbl *v6; // rdi
  void *v7; // rax
  __int64 v8; // rdx
  __int64 v9; // r9
  int v10; // eax
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v11; // rcx
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v12; // rdx
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v13; // rcx
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v14; // rax
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v15; // rdx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v16; // rax
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v17; // rcx
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v18; // rdx
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v19; // rax
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v20; // r15
  UFG::UIScreen *v21; // r12
  Scaleform::GFx::Movie *v22; // rbx
  Scaleform::RefCountImplCoreVtbl *v23; // rdi
  void *v24; // rax
  __int64 v25; // rdx
  __int64 v26; // r9
  int v27; // eax
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v28; // rcx
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v29; // rdx
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v30; // rcx
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v31; // rax
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v32; // rcx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v33; // rax
  signed __int64 v34; // r11
  signed __int64 v35; // rsi
  signed __int64 v36; // rdi
  __int64 *v37; // r14
  signed __int64 v38; // r10
  __int64 v39; // rdx
  _QWORD *v40; // r9
  __int64 *v41; // r8
  _QWORD *v42; // rax
  __int64 v43; // rcx
  _QWORD *v44; // rax
  _QWORD *v45; // rax
  __int64 v46; // rax
  __int64 *v47; // r14
  signed __int64 v48; // r10
  _QWORD *v49; // r9
  __int64 v50; // rdx
  __int64 *v51; // r8
  _QWORD *v52; // rax
  __int64 v53; // rcx
  _QWORD *v54; // rax
  __int64 **v55; // rax
  __int64 v56; // rax
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v57; // rcx
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v58; // rdx
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v59; // rax
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v60; // rdi
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v61; // r9
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v62; // r8
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v63; // rax
  signed __int64 v64; // [rsp+20h] [rbp-48h]

  v64 = -2i64;
  v2 = this;
  if ( (UFG::qList<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad,1,0> *)this->mPendingScreenLoads.mNode.mNext != &this->mPendingScreenLoads )
  {
    v3 = this->mPendingScreenLoads.mNode.mNext;
    v4 = (UFG::UIScreen *)v3[1].mPrev;
    if ( v4->mRenderable->mIsLoaded )
    {
      v5 = v4->mRenderable->m_movie.pObject;
      v6 = v5->vfptr;
      v7 = UFG::qGetCurrentThreadID();
      v6[27].__vecDelDtor((Scaleform::RefCountImplCore *)&v5->vfptr, (unsigned int)v7);
      v10 = HIDWORD(v3[2].mPrev);
      if ( v10 <= 0 )
      {
        UFG::UIScreenManagerBase::CheckPendingMessages(v2, v4);
        v12 = v2->mPendingScreenLoads.mNode.mNext;
        v13 = v12->mPrev;
        v14 = v12->mNext;
        v13->mNext = v14;
        v14->mPrev = v13;
        v12->mPrev = v12;
        v12->mNext = v12;
        if ( LOBYTE(v3[2].mPrev) )
        {
          UFG::UIScreenManagerBase::shutdownScreen(v2, (UFG::UIScreen *)v3[1].mPrev);
        }
        else
        {
          EnterCriticalSection(&v2->mScreenStackLock.cs);
          v15 = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)&v4->mPrev;
          v16 = v2->m_screenStack.mNode.mPrev;
          v16->mNext = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)&v4->mPrev;
          v15->mPrev = v16;
          v15->mNext = &v2->m_screenStack.mNode;
          v2->m_screenStack.mNode.mPrev = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)&v4->mPrev;
          LeaveCriticalSection(&v2->mScreenStackLock.cs);
          UFG::UIScreenManagerBase::initViewport(v2, v4);
          (*((void (__fastcall **)(UFG::UIScreen *, UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *))&v4->vfptr->__vecDelDtor
           + 1))(
            v4,
            v3[1].mNext);
        }
        v17 = v3[1].mNext;
        if ( v17 )
          ((void (__fastcall *)(UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *, signed __int64))v17->mPrev->mPrev)(
            v17,
            1i64);
        v18 = v3->mPrev;
        v19 = v3->mNext;
        v18->mNext = v19;
        v19->mPrev = v18;
        v3->mPrev = v3;
        v3->mNext = v3;
        operator delete[](v3);
      }
      else
      {
        HIDWORD(v3[2].mPrev) = v10 - 1;
        v11 = v3[1].mPrev[6].mPrev;
        if ( LOBYTE(v11[22].mPrev) )
        {
          LOBYTE(v9) = 1;
          ((void (__fastcall *)(UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *, __int64, signed __int64, __int64, signed __int64))v11[20].mPrev->mPrev[12].mPrev)(
            v11[20].mPrev,
            v8,
            2i64,
            v9,
            -2i64);
        }
      }
    }
  }
  if ( (UFG::qList<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad,1,0> *)v2->mPendingOverlayLoads.mNode.mNext != &v2->mPendingOverlayLoads )
  {
    v20 = v2->mPendingOverlayLoads.mNode.mNext;
    v21 = (UFG::UIScreen *)v20[1].mPrev;
    if ( v21->mRenderable->mIsLoaded )
    {
      v22 = v21->mRenderable->m_movie.pObject;
      v23 = v22->vfptr;
      v24 = UFG::qGetCurrentThreadID();
      v23[27].__vecDelDtor((Scaleform::RefCountImplCore *)&v22->vfptr, (unsigned int)v24);
      v27 = HIDWORD(v20[2].mPrev);
      if ( v27 <= 0 )
      {
        UFG::UIScreenManagerBase::CheckPendingMessages(v2, v21);
        v29 = v2->mPendingOverlayLoads.mNode.mNext;
        v30 = v29->mPrev;
        v31 = v29->mNext;
        v30->mNext = v31;
        v31->mPrev = v30;
        v29->mPrev = v29;
        v29->mNext = v29;
        if ( LOBYTE(v20[2].mPrev) )
        {
          UFG::UIScreenManagerBase::shutdownScreen(v2, (UFG::UIScreen *)v20[1].mPrev);
        }
        else
        {
          EnterCriticalSection(&v2->mScreenStackLock.cs);
          v32 = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)&v21->mPrev;
          v33 = v2->m_overlayStack.mNode.mPrev;
          v33->mNext = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)&v21->mPrev;
          v32->mPrev = v33;
          v32->mNext = &v2->m_overlayStack.mNode;
          v2->m_overlayStack.mNode.mPrev = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)&v21->mPrev;
          v34 = (signed __int64)&v2->m_overlayStack.mNode.mNext[-1].mNext;
          v35 = (signed __int64)&v2->m_screenStack.mNode.mNext;
          do
          {
            v36 = 0i64;
            while ( v34 != v35 )
            {
              v37 = (__int64 *)(v34 + 8);
              v38 = *(_QWORD *)(v34 + 16) - 8i64;
              if ( v38 == v35 )
                break;
              if ( *(_DWORD *)(v34 + 124) <= *(_DWORD *)(v38 + 124) )
              {
                v34 = *(_QWORD *)(v34 + 16) - 8i64;
              }
              else
              {
                v39 = *v37;
                v40 = *(_QWORD **)(v34 + 16);
                v41 = *(__int64 **)(v38 + 16);
                v42 = *(_QWORD **)(v34 + 16);
                *(_QWORD *)(v39 + 8) = v42;
                *v42 = v39;
                *v37 = (__int64)v37;
                *(_QWORD *)(v34 + 16) = v34 + 8;
                v43 = *(_QWORD *)(v38 + 8);
                v44 = *(_QWORD **)(v38 + 16);
                *(_QWORD *)(v43 + 8) = v44;
                *v44 = v43;
                *v40 = v40;
                v40[1] = v40;
                v45 = *(_QWORD **)(v39 + 8);
                *(_QWORD *)(v39 + 8) = v38 + 8;
                *v40 = v39;
                v40[1] = v45;
                *v45 = v38 + 8;
                v46 = *v41;
                *(_QWORD *)(v46 + 8) = v37;
                *v37 = v46;
                *(_QWORD *)(v34 + 16) = v41;
                *v41 = (__int64)v37;
                v36 = v38;
              }
            }
            v34 = 0i64;
            if ( !v36 || v36 == v35 )
              break;
            do
            {
              v47 = (__int64 *)(v36 + 8);
              v48 = *(_QWORD *)(v36 + 8) - 8i64;
              if ( v48 == v35 )
                break;
              if ( *(_DWORD *)(v48 + 124) <= *(_DWORD *)(v36 + 124) )
              {
                v36 = *(_QWORD *)(v36 + 8) - 8i64;
              }
              else
              {
                v49 = *(_QWORD **)(v36 + 8);
                v50 = **(_QWORD **)(v36 + 8);
                v51 = *(__int64 **)(v36 + 16);
                v52 = *(_QWORD **)(v48 + 16);
                *(_QWORD *)(v50 + 8) = v52;
                *v52 = v50;
                *v49 = v49;
                v49[1] = v49;
                v53 = *v47;
                v54 = *(_QWORD **)(v36 + 16);
                *(_QWORD *)(v53 + 8) = v54;
                *v54 = v53;
                *v47 = (__int64)v47;
                *(_QWORD *)(v36 + 16) = v36 + 8;
                v55 = *(__int64 ***)(v50 + 8);
                *(_QWORD *)(v50 + 8) = v47;
                *v47 = v50;
                *(_QWORD *)(v36 + 16) = v55;
                *v55 = v47;
                v56 = *v51;
                *(_QWORD *)(v56 + 8) = v48 + 8;
                *v49 = v56;
                v49[1] = v51;
                *v51 = v48 + 8;
                v34 = v48;
              }
            }
            while ( v36 != v35 );
          }
          while ( v34 );
          LeaveCriticalSection(&v2->mScreenStackLock.cs);
          UFG::UIScreenManagerBase::initViewport(v2, 0i64);
          (*((void (__fastcall **)(UFG::UIScreen *, UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *))&v21->vfptr->__vecDelDtor
           + 1))(
            v21,
            v20[1].mNext);
        }
        v57 = v20[1].mNext;
        if ( v57 )
          ((void (__fastcall *)(UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *, signed __int64))v57->mPrev->mPrev)(
            v57,
            1i64);
        v58 = v20->mPrev;
        v59 = v20->mNext;
        v58->mNext = v59;
        v59->mPrev = v58;
        v20->mPrev = v20;
        v20->mNext = v20;
        operator delete[](v20);
      }
      else
      {
        HIDWORD(v20[2].mPrev) = v27 - 1;
        v28 = v20[1].mPrev[6].mPrev;
        if ( LOBYTE(v28[22].mPrev) )
        {
          LOBYTE(v26) = 1;
          ((void (__fastcall *)(UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *, __int64, signed __int64, __int64, signed __int64))v28[20].mPrev->mPrev[12].mPrev)(
            v28[20].mPrev,
            v25,
            2i64,
            v26,
            v64);
        }
      }
    }
  }
  if ( (UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> **)&v2->mPendingPoppedScreens.mNode.mNext[-1].mNext != &v2->mPendingOverlayLoads.mNode.mNext )
  {
    v60 = v2->mPendingPoppedScreens.mNode.mNext;
    if ( ((__int64 (__cdecl *)(UFG::qNode<UFG::UIScreen,UFG::UIScreen> *))v60[5].mNext[20].mPrev->mPrev[14].mNext)(v60[5].mNext[20].mPrev) )
    {
      EnterCriticalSection(&v2->mScreenStackLock.cs);
      v61 = v2->mPendingPoppedScreens.mNode.mNext;
      v62 = v61->mPrev;
      v63 = v61->mNext;
      v62->mNext = v63;
      v63->mPrev = v62;
      v61->mPrev = v61;
      v61->mNext = v61;
      LeaveCriticalSection(&v2->mScreenStackLock.cs);
      ((void (__fastcall *)(UFG::qNode<UFG::UIScreen,UFG::UIScreen> **, signed __int64))v60[-1].mNext->mPrev)(
        &v60[-1].mNext,
        1i64);
    }
  }
},UFG::UIScreen> **, signed __int64))v60[-1].mNext->mPrev)(
        &v60[-1].mNext,
        1i64);
    }
  }
}

// File Line: 718
// RVA: 0xA331D0
void __fastcall UFG::UIScreenManagerBase::updateScreenStack(UFG::UIScreenManagerBase *this, float elapsed)
{
  UFG::UIScreenManagerBase *v2; // rdi
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **v3; // rsi
  UFG::UIScreenManagerBase *v4; // rbx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **i; // rbx

  v2 = this;
  if ( this->m_renderUI && UFG::gTweakerRenderUI )
  {
    v3 = &this->m_screenStack.mNode.mNext;
    v4 = (UFG::UIScreenManagerBase *)&this->m_screenStack.mNode.mNext[-1].mNext;
    if ( v4 != this )
    {
      do
      {
        v4->vfptr->isInputEnabled(v4);
        v4 = (UFG::UIScreenManagerBase *)&v4->m_screenStack.mNode.mNext[-1].mNext;
      }
      while ( v4 != v2 );
    }
    for ( i = &v2->m_overlayStack.mNode.mNext[-1].mNext; i != v3; i = &i[2][-1].mNext )
      ((void (__fastcall *)(UFG::qNode<UFG::UIScreen,UFG::UIScreen> **))(*i)[1].mNext)(i);
  }
}

// File Line: 785
// RVA: 0xA2A040
void __fastcall UFG::UIScreenManagerBase::baseUpdate(UFG::UIScreenManagerBase *this, float elapsed)
{
  float v2; // xmm7_4
  UFG::UIScreenManagerBase *v3; // rdi
  AMD_HD3D *v4; // rcx
  __m128 *v5; // xmm0_8
  signed __int64 v6; // rsi
  UFG::UIScreen *i; // rbx
  UFG::UIScreen *j; // rbx
  UFG::UIFlowRoot *v9; // rcx
  UFG::allocator::free_link *v10; // rax
  UFG::qNode<UFG::UITween,UFG::UITween> *v11; // rsi
  UFG::UIScreenManagerBase *v12; // rbp
  UFG::allocator::free_link *v13; // rax
  UFG::allocator::free_link *v14; // r14
  int v15; // ebx
  int v16; // xmm6_4
  const char *v17; // rdx
  UFG::qNode<UFG::UITween,UFG::UITween> *v18; // rcx
  UFG::allocator::free_link *v19; // rax
  UFG::qNode<UFG::UITween,UFG::UITween> *v20; // rdx
  UFG::qNode<UFG::UITween,UFG::UITween> *v21; // rax

  v2 = elapsed;
  v3 = this;
  if ( *(_QWORD *)&this->m_targetWidth != *(_QWORD *)&Render::GetBackBufferTarget()->mWidth
    || (v5 = (__m128 *)LODWORD(lastViewportScale), lastViewportScale != UFG::gUIViewportScale) )
  {
    UFG::UIScreenManagerBase::initViewport(v3, 0i64);
    v5 = (__m128 *)LODWORD(UFG::gUIViewportScale);
    lastViewportScale = UFG::gUIViewportScale;
    if ( v3->mScaleViewportInCode == 1 )
    {
      v6 = (signed __int64)&v3->m_screenStack.mNode.mNext;
      for ( i = (UFG::UIScreen *)&v3->m_screenStack.mNode.mNext[-1].mNext;
            i != (UFG::UIScreen *)v3;
            i = (UFG::UIScreen *)&i->mNext[-1].mNext )
      {
        UFG::UIScreen::updateViewportScale(i, *(float *)&v5);
      }
      for ( j = (UFG::UIScreen *)&v3->m_overlayStack.mNode.mNext[-1].mNext;
            j != (UFG::UIScreen *)v6;
            j = (UFG::UIScreen *)&j->mNext[-1].mNext )
      {
        UFG::UIScreen::updateViewportScale(j, *(float *)&v5);
      }
    }
  }
  if ( elapsed > 1.0 )
    v2 = *(float *)&FLOAT_1_0;
  _(v4);
  if ( UFG::gTweakerUpdateUI && v3->m_updateUI )
  {
    if ( v3->vfptr->isInputEnabled(v3) )
      UFG::UIInputHandler::handleInput(v3->m_inputHandler, v2);
    v9 = UFG::LazyInitGet<UFG::UIFlowRoot>::m_instance;
    if ( !UFG::LazyInitGet<UFG::UIFlowRoot>::m_instance )
    {
      v10 = UFG::qMemoryPool::Allocate(
              &gScaleformMemoryPool,
              (unsigned int)((_DWORD)UFG::LazyInitGet<UFG::UIFlowRoot>::m_instance + 40),
              "UIFlow",
              0i64,
              1u);
      if ( v10 )
      {
        v10->mNext = (UFG::allocator::free_link *)&UFG::UIFlow::`vftable';
        LODWORD(v10[1].mNext) = -1;
        v10[2].mNext = 0i64;
        v10[3].mNext = 0i64;
        v10->mNext = (UFG::allocator::free_link *)&UFG::UIFlowRoot::`vftable';
      }
      else
      {
        v10 = 0i64;
      }
      UFG::LazyInitGet<UFG::UIFlowRoot>::m_instance = (UFG::UIFlowRoot *)v10;
      v9 = (UFG::UIFlowRoot *)v10;
    }
    ((void (*)(void))v9->vfptr->flowUpdate)();
    v11 = v3->m_activeTweens.mNode.mNext;
    if ( v11 != (UFG::qNode<UFG::UITween,UFG::UITween> *)&v3->m_activeTweens )
    {
      do
      {
        v12 = (UFG::UIScreenManagerBase *)v11->mNext;
        *(float *)&v5 = UFG::UITween::Update((UFG::UITween *)v11, v2, v5);
        if ( *(float *)&v5 >= 1.0 )
        {
          v13 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x70ui64, "UICommand", 0i64, 1u);
          v14 = v13;
          if ( v13 )
          {
            v15 = HIDWORD(v11[4].mPrev);
            v16 = (int)v11[4].mPrev;
            v17 = (const char *)v11[3].mPrev;
            v18 = v11[1].mPrev;
            v19 = v13 + 1;
            v19->mNext = v19;
            v19[1].mNext = v19;
            v14->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable';
            LODWORD(v14[3].mNext) = -1;
            v14[4].mNext = 0i64;
            v14->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable';
            LODWORD(v14[5].mNext) = UI_HASH_TWEEN_COMPLETE_35;
            HIDWORD(v14[5].mNext) = 0;
            v14[6].mNext = (UFG::allocator::free_link *)-1i64;
            LODWORD(v14[3].mNext) = 5;
            v14->mNext = (UFG::allocator::free_link *)&UFG::UIMessageTweenComplete::`vftable';
            v14[7].mNext = (UFG::allocator::free_link *)v18;
            UFG::qString::qString((UFG::qString *)&v14[8], v17);
            LODWORD(v14[13].mNext) = v16;
            HIDWORD(v14[13].mNext) = v15;
          }
          else
          {
            v14 = 0i64;
          }
          UFG::UIScreenManagerBase::queueMessageEx(v3, (UFG::UIMessage *)v14);
          v20 = v11->mPrev;
          v21 = v11->mNext;
          v20->mNext = v21;
          v21->mPrev = v20;
          v11->mPrev = v11;
          v11->mNext = v11;
          UFG::UITween::~UITween((UFG::UITween *)v11);
          operator delete[](v11);
        }
        v11 = (UFG::qNode<UFG::UITween,UFG::UITween> *)v12;
      }
      while ( v12 != (UFG::UIScreenManagerBase *)&v3->m_activeTweens );
    }
    UFG::UIScreenManagerBase::updatePendingLoads(v3, v2);
    UFG::UIScreenManagerBase::updateCommandQueue(v3, v2);
    UFG::UIScreenManagerBase::updateScreenCommandQueue(v3, v2);
    UFG::UIScreenManagerBase::updateScreenStack(v3, v2);
    Scaleform::GFx::DrawTextManager::Capture(v3->m_gfxDrawTextManager, 1);
    UFG::UIScreenManagerBase::debugRender(v3);
  }
}

// File Line: 900
// RVA: 0xA31820
UFG::UICommand *__fastcall UFG::UIScreenManagerBase::queuePushScreen(UFG::UIScreenManagerBase *this, const char *fileName, int controllerMask)
{
  int v3; // ebx
  const char *v4; // rsi
  UFG::UIScreenManagerBase *v5; // rdi
  UFG::allocator::free_link *v6; // rax
  __int64 v7; // rax
  __int64 v8; // rbx
  signed int v9; // eax
  UFG::qList<UFG::UICommand,UFG::UICommand,1,0> *v10; // rdx
  UFG::qNode<UFG::UICommand,UFG::UICommand> **v11; // rcx
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v12; // rax

  v3 = controllerMask;
  v4 = fileName;
  v5 = this;
  v6 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0xC0ui64, "UIScreenManagerBase::UICommandScreenPush", 0i64, 1u);
  if ( v6 )
  {
    UFG::UICommandScreenPush::UICommandScreenPush((UFG::UICommandScreenPush *)v6, v4, v5->mScreenUIDCounter, v3);
    v8 = v7;
  }
  else
  {
    v8 = 0i64;
  }
  if ( UFG::gTweakerUpdateUI && v5->m_updateUI )
  {
    v9 = *(_DWORD *)(v8 + 24);
    if ( v9 >= 0 )
    {
      if ( v9 <= 4 )
      {
        v10 = &v5->m_screenCommandQueue;
        goto LABEL_11;
      }
      if ( v9 <= 7 )
      {
        v10 = &v5->m_commandQueue;
LABEL_11:
        v11 = (UFG::qNode<UFG::UICommand,UFG::UICommand> **)(v8 + 8);
        v12 = v10->mNode.mPrev;
        v12->mNext = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)(v8 + 8);
        *v11 = v12;
        v11[1] = &v10->mNode;
        v10->mNode.mPrev = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)(v8 + 8);
        goto LABEL_14;
      }
    }
  }
  else if ( v8 )
  {
    (**(void (__fastcall ***)(__int64, signed __int64))v8)(v8, 1i64);
  }
LABEL_14:
  ++v5->mScreenUIDCounter;
  return (UFG::UICommand *)v8;
}

// File Line: 920
// RVA: 0xA31600
UFG::allocator::free_link *__fastcall UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManagerBase *this, unsigned int screenUID)
{
  unsigned int v2; // esi
  UFG::UIScreenManagerBase *v3; // rdi
  UFG::allocator::free_link *v4; // rax
  UFG::allocator::free_link *v5; // rbx
  UFG::allocator::free_link *v6; // rax
  signed int v7; // eax
  bool v8; // zf
  bool v9; // sf
  unsigned __int8 v10; // of
  UFG::allocator::free_link *result; // rax
  _QWORD *v12; // rdx
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v13; // rcx
  _QWORD *v14; // rcx
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v15; // rax

  v2 = screenUID;
  v3 = this;
  v4 = UFG::qMemoryPool::Allocate(
         &gScaleformMemoryPool,
         0x30ui64,
         "UIScreenManagerBase::UICommandScreenPopUID",
         0i64,
         1u);
  v5 = v4;
  if ( v4 )
  {
    v6 = v4 + 1;
    v6->mNext = v6;
    v6[1].mNext = v6;
    v5->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable';
    LODWORD(v5[3].mNext) = -1;
    v5[4].mNext = 0i64;
    v5->mNext = (UFG::allocator::free_link *)&UFG::UICommandScreenPop::`vftable';
    LODWORD(v5[3].mNext) = 1;
    LOBYTE(v5[5].mNext) = 0;
    HIDWORD(v5[5].mNext) = v2;
  }
  else
  {
    v5 = 0i64;
  }
  if ( !UFG::gTweakerUpdateUI || !v3->m_updateUI )
  {
    if ( v5 )
      ((void (__fastcall *)(UFG::allocator::free_link *, signed __int64))v5->mNext->mNext)(v5, 1i64);
    return v5;
  }
  v7 = (signed int)v5[3].mNext;
  if ( v7 < 0 )
    return v5;
  if ( v7 <= 4 )
  {
    v14 = &v5[1].mNext;
    v15 = v3->m_screenCommandQueue.mNode.mPrev;
    v15->mNext = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)&v5[1];
    *v14 = v15;
    v14[1] = (char *)v3 + 248;
    v3->m_screenCommandQueue.mNode.mPrev = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)&v5[1];
    return v5;
  }
  v10 = __OFSUB__(v7, 7);
  v8 = v7 == 7;
  v9 = v7 - 7 < 0;
  result = v5;
  if ( (unsigned __int8)(v9 ^ v10) | v8 )
  {
    v12 = &v5[1].mNext;
    v13 = v3->m_commandQueue.mNode.mPrev;
    v13->mNext = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)&v5[1];
    *v12 = v13;
    v12[1] = (char *)v3 + 232;
    v3->m_commandQueue.mNode.mPrev = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)&v5[1];
  }
  return result;
}

// File Line: 933
// RVA: 0xA31300
UFG::allocator::free_link *__fastcall UFG::UIScreenManagerBase::queuePopAllScreens(UFG::UIScreenManagerBase *this)
{
  UFG::UIScreenManagerBase *v1; // rdi
  UFG::allocator::free_link *v2; // rax
  UFG::allocator::free_link *v3; // rbx
  UFG::allocator::free_link *v4; // rax
  signed int v5; // eax
  bool v6; // zf
  bool v7; // sf
  unsigned __int8 v8; // of
  UFG::allocator::free_link *result; // rax
  _QWORD *v10; // rdx
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v11; // rcx
  _QWORD *v12; // rcx
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v13; // rax

  v1 = this;
  v2 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x30ui64, "UIScreenManagerBase::UICommandScreenPop", 0i64, 1u);
  v3 = v2;
  if ( v2 )
  {
    v4 = v2 + 1;
    v4->mNext = v4;
    v4[1].mNext = v4;
    v3->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable';
    LODWORD(v3[3].mNext) = -1;
    v3[4].mNext = 0i64;
    v3->mNext = (UFG::allocator::free_link *)&UFG::UICommandScreenPop::`vftable';
    LODWORD(v3[3].mNext) = 1;
    LOBYTE(v3[5].mNext) = 1;
    HIDWORD(v3[5].mNext) = -1;
  }
  else
  {
    v3 = 0i64;
  }
  if ( !UFG::gTweakerUpdateUI || !v1->m_updateUI )
  {
    if ( v3 )
      ((void (__fastcall *)(UFG::allocator::free_link *, signed __int64))v3->mNext->mNext)(v3, 1i64);
    return v3;
  }
  v5 = (signed int)v3[3].mNext;
  if ( v5 < 0 )
    return v3;
  if ( v5 <= 4 )
  {
    v12 = &v3[1].mNext;
    v13 = v1->m_screenCommandQueue.mNode.mPrev;
    v13->mNext = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)&v3[1];
    *v12 = v13;
    v12[1] = (char *)v1 + 248;
    v1->m_screenCommandQueue.mNode.mPrev = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)&v3[1];
    return v3;
  }
  v8 = __OFSUB__(v5, 7);
  v6 = v5 == 7;
  v7 = v5 - 7 < 0;
  result = v3;
  if ( (unsigned __int8)(v7 ^ v8) | v6 )
  {
    v10 = &v3[1].mNext;
    v11 = v1->m_commandQueue.mNode.mPrev;
    v11->mNext = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)&v3[1];
    *v10 = v11;
    v10[1] = (char *)v1 + 232;
    v1->m_commandQueue.mNode.mPrev = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)&v3[1];
  }
  return result;
}

// File Line: 990
// RVA: 0xA31720
UFG::UICommand *__fastcall UFG::UIScreenManagerBase::queuePushOverlay(UFG::UIScreenManagerBase *this, const char *fileName, int priority, int controllerMask)
{
  int v4; // ebx
  int v5; // esi
  const char *v6; // rbp
  UFG::UIScreenManagerBase *v7; // rdi
  UFG::allocator::free_link *v8; // rax
  __int64 v9; // rax
  __int64 v10; // rbx
  signed int v11; // eax
  UFG::qList<UFG::UICommand,UFG::UICommand,1,0> *v12; // rdx
  UFG::qNode<UFG::UICommand,UFG::UICommand> **v13; // rcx
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v14; // rax

  v4 = controllerMask;
  v5 = priority;
  v6 = fileName;
  v7 = this;
  v8 = UFG::qMemoryPool::Allocate(
         &gScaleformMemoryPool,
         0xC0ui64,
         "UIScreenManagerBase::UICommandOverlayPush",
         0i64,
         1u);
  if ( v8 )
  {
    UFG::UICommandOverlayPush::UICommandOverlayPush((UFG::UICommandOverlayPush *)v8, v6, v7->mScreenUIDCounter, v5, v4);
    v10 = v9;
  }
  else
  {
    v10 = 0i64;
  }
  if ( UFG::gTweakerUpdateUI && v7->m_updateUI )
  {
    v11 = *(_DWORD *)(v10 + 24);
    if ( v11 >= 0 )
    {
      if ( v11 <= 4 )
      {
        v12 = &v7->m_screenCommandQueue;
        goto LABEL_11;
      }
      if ( v11 <= 7 )
      {
        v12 = &v7->m_commandQueue;
LABEL_11:
        v13 = (UFG::qNode<UFG::UICommand,UFG::UICommand> **)(v10 + 8);
        v14 = v12->mNode.mPrev;
        v14->mNext = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)(v10 + 8);
        *v13 = v14;
        v13[1] = &v12->mNode;
        v12->mNode.mPrev = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)(v10 + 8);
        goto LABEL_14;
      }
    }
  }
  else if ( v10 )
  {
    (**(void (__fastcall ***)(__int64, signed __int64))v10)(v10, 1i64);
  }
LABEL_14:
  ++v7->mScreenUIDCounter;
  return (UFG::UICommand *)v10;
}

// File Line: 1008
// RVA: 0xA31530
UFG::UICommand *__fastcall UFG::UIScreenManagerBase::queuePopOverlay(UFG::UIScreenManagerBase *this, const char *fileName)
{
  const char *v2; // rbx
  UFG::UIScreenManagerBase *v3; // rdi
  UFG::allocator::free_link *v4; // rax
  __int64 v5; // rax
  __int64 v6; // rbx
  signed int v7; // eax
  UFG::qList<UFG::UICommand,UFG::UICommand,1,0> *v8; // rdx
  UFG::qNode<UFG::UICommand,UFG::UICommand> **v9; // rcx
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v10; // rax

  v2 = fileName;
  v3 = this;
  v4 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0xB0ui64, "UIScreenManagerBase::UICommandOverlayPop", 0i64, 1u);
  if ( v4 )
  {
    UFG::UICommandOverlayPop::UICommandOverlayPop((UFG::UICommandOverlayPop *)v4, v2);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  if ( UFG::gTweakerUpdateUI && v3->m_updateUI )
  {
    v7 = *(_DWORD *)(v6 + 24);
    if ( v7 >= 0 )
    {
      if ( v7 <= 4 )
      {
        v8 = &v3->m_screenCommandQueue;
        goto LABEL_10;
      }
      if ( v7 <= 7 )
      {
        v8 = &v3->m_commandQueue;
LABEL_10:
        v9 = (UFG::qNode<UFG::UICommand,UFG::UICommand> **)(v6 + 8);
        v10 = v8->mNode.mPrev;
        v10->mNext = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)(v6 + 8);
        *v9 = v10;
        v9[1] = &v8->mNode;
        v8->mNode.mPrev = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)(v6 + 8);
        return (UFG::UICommand *)v6;
      }
    }
  }
  else if ( v6 )
  {
    (**(void (__fastcall ***)(__int64, signed __int64))v6)(v6, 1i64);
  }
  return (UFG::UICommand *)v6;
}

// File Line: 1024
// RVA: 0xA31410
UFG::allocator::free_link *__fastcall UFG::UIScreenManagerBase::queuePopOverlay(UFG::UIScreenManagerBase *this, unsigned int screenUID)
{
  unsigned int v2; // esi
  UFG::UIScreenManagerBase *v3; // rdi
  UFG::allocator::free_link *v4; // rax
  UFG::allocator::free_link *v5; // rbx
  UFG::allocator::free_link *v6; // rax
  signed int v7; // eax
  bool v8; // zf
  bool v9; // sf
  unsigned __int8 v10; // of
  UFG::allocator::free_link *result; // rax
  _QWORD *v12; // rdx
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v13; // rcx
  _QWORD *v14; // rcx
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v15; // rax

  v2 = screenUID;
  v3 = this;
  v4 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0xB0ui64, "UIScreenManagerBase::UICommandOverlayPop", 0i64, 1u);
  v5 = v4;
  if ( v4 )
  {
    v6 = v4 + 1;
    v6->mNext = v6;
    v6[1].mNext = v6;
    v5->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable';
    LODWORD(v5[3].mNext) = -1;
    v5[4].mNext = 0i64;
    v5->mNext = (UFG::allocator::free_link *)&UFG::UICommandOverlayPop::`vftable';
    LODWORD(v5[5].mNext) = v2;
    BYTE4(v5[5].mNext) = 0;
    LODWORD(v5[3].mNext) = 4;
  }
  else
  {
    v5 = 0i64;
  }
  if ( !UFG::gTweakerUpdateUI || !v3->m_updateUI )
  {
    if ( v5 )
      ((void (__fastcall *)(UFG::allocator::free_link *, signed __int64))v5->mNext->mNext)(v5, 1i64);
    return v5;
  }
  v7 = (signed int)v5[3].mNext;
  if ( v7 < 0 )
    return v5;
  if ( v7 <= 4 )
  {
    v14 = &v5[1].mNext;
    v15 = v3->m_screenCommandQueue.mNode.mPrev;
    v15->mNext = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)&v5[1];
    *v14 = v15;
    v14[1] = (char *)v3 + 248;
    v3->m_screenCommandQueue.mNode.mPrev = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)&v5[1];
    return v5;
  }
  v10 = __OFSUB__(v7, 7);
  v8 = v7 == 7;
  v9 = v7 - 7 < 0;
  result = v5;
  if ( (unsigned __int8)(v9 ^ v10) | v8 )
  {
    v12 = &v5[1].mNext;
    v13 = v3->m_commandQueue.mNode.mPrev;
    v13->mNext = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)&v5[1];
    *v12 = v13;
    v12[1] = (char *)v3 + 232;
    v3->m_commandQueue.mNode.mPrev = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)&v5[1];
  }
  return result;
}

// File Line: 1041
// RVA: 0xA30FE0
UFG::allocator::free_link *__fastcall UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManagerBase *this, unsigned int messageId, unsigned int receiverUID)
{
  unsigned int v3; // esi
  unsigned int v4; // ebp
  UFG::UIScreenManagerBase *v5; // rdi
  UFG::allocator::free_link *v6; // rax
  UFG::allocator::free_link *v7; // rbx
  UFG::allocator::free_link *v8; // rax

  v3 = receiverUID;
  v4 = messageId;
  v5 = this;
  v6 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x38ui64, "UIScreenManagerBase::UIMessage", 0i64, 1u);
  v7 = v6;
  if ( v6 )
  {
    v8 = v6 + 1;
    v8->mNext = v8;
    v8[1].mNext = v8;
    v7->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable';
    LODWORD(v7[3].mNext) = -1;
    v7[4].mNext = 0i64;
    v7->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable';
    LODWORD(v7[5].mNext) = v4;
    HIDWORD(v7[5].mNext) = 0;
    LODWORD(v7[6].mNext) = v3;
    LODWORD(v7[3].mNext) = 5;
    HIDWORD(v7[6].mNext) = -1;
  }
  else
  {
    v7 = 0i64;
  }
  UFG::UIScreenManagerBase::queueMessageEx(v5, (UFG::UIMessage *)v7);
  return v7;
}

// File Line: 1056
// RVA: 0xA310B0
UFG::UIMessage *__fastcall UFG::UIScreenManagerBase::queueMessageEx(UFG::UIScreenManagerBase *this, UFG::UIMessage *message)
{
  unsigned int v2; // er9
  char v3; // r8
  UFG::UIMessage *v4; // rdi
  UFG::UIScreenManagerBase *v5; // rsi
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v6; // rdx
  UFG::qList<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad,1,0> *v7; // rcx
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v8; // rax
  UFG::UIScreenManagerBase *v9; // rdx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v10; // rax
  signed __int64 i; // rcx
  int v12; // eax
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v13; // rdx
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v14; // rax
  __int64 v16; // rdx
  char *v17; // rax
  __int64 v18; // rcx
  __int64 v19; // rcx
  signed int v20; // eax
  UFG::qList<UFG::UICommand,UFG::UICommand,1,0> *v21; // rdx
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v22; // rax
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v23; // rcx

  v2 = message->m_receiverUID;
  v3 = 0;
  v4 = message;
  v5 = this;
  if ( v2 == -1 )
  {
    if ( message->m_commandType == 7 )
    {
      v16 = *(_QWORD *)&message[1].m_messageId;
      v17 = (char *)&this->m_screenStack.mNode.mNext[-1].mNext;
      if ( v17 == (char *)this )
      {
LABEL_30:
        v17 = (char *)&v5->m_overlayStack.mNode.mNext[-1].mNext;
        if ( v17 == (char *)&v5->m_screenStack.mNode.mNext )
          goto LABEL_22;
        while ( 1 )
        {
          v19 = *((_QWORD *)v17 + 12);
          if ( v19 )
          {
            if ( *(_QWORD *)(v19 + 320) == v16 )
              break;
          }
          v17 = (char *)(*((_QWORD *)v17 + 2) - 8i64);
          if ( v17 == (char *)&v5->m_screenStack.mNode.mNext )
            goto LABEL_22;
        }
      }
      else
      {
        while ( 1 )
        {
          v18 = *((_QWORD *)v17 + 12);
          if ( v18 )
          {
            if ( *(_QWORD *)(v18 + 320) == v16 )
              break;
          }
          v17 = (char *)(*((_QWORD *)v17 + 2) - 8i64);
          if ( v17 == (char *)v5 )
            goto LABEL_30;
        }
      }
      v4->m_receiverUID = *((_DWORD *)v17 + 28);
    }
  }
  else
  {
    v6 = this->mPendingScreenLoads.mNode.mNext;
    v7 = &this->mPendingScreenLoads;
    while ( v6 != (UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *)v7 )
    {
      v8 = v6[1].mPrev;
      v6 = v6->mNext;
      if ( LODWORD(v8[7].mPrev) == v2 )
        v3 = 1;
    }
    v9 = (UFG::UIScreenManagerBase *)v5->mPendingOverlayLoads.mNode.mNext;
    while ( v9 != (UFG::UIScreenManagerBase *)&v5->mPendingOverlayLoads )
    {
      v10 = v9->m_screenStack.mNode.mNext;
      v9 = (UFG::UIScreenManagerBase *)v9->m_screenStack.mNode.mPrev;
      if ( LODWORD(v10[7].mPrev) == v2 )
        v3 = 1;
    }
    for ( i = (signed __int64)&v5->m_screenCommandQueue.mNode.mNext[-1].mNext;
          (UFG::qNode<UFG::UICommand,UFG::UICommand> **)i != &v5->m_commandQueue.mNode.mNext;
          i = *(_QWORD *)(i + 16) - 8i64 )
    {
      v12 = *(_DWORD *)(i + 24);
      if ( v12 )
      {
        if ( v12 == 2 )
        {
          if ( *(_DWORD *)(i + 172) == v2 )
            v3 = 1;
        }
        else if ( v12 == 3 && *(_DWORD *)(i + 168) == v2 )
        {
          v3 = 1;
        }
      }
      else if ( *(_DWORD *)(i + 168) == v2 )
      {
        v3 = 1;
      }
    }
    if ( v3 )
    {
LABEL_22:
      if ( UFG::gTweakerUpdateUI && v5->m_updateUI )
      {
        UFG::qMutex::Lock((LPCRITICAL_SECTION)&v5->m_pendingMessagesMutex);
        v13 = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)&v4->mPrev;
        v14 = v5->m_pendingMessages.mNode.mPrev;
        v14->mNext = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)&v4->mPrev;
        v13->mPrev = v14;
        v13->mNext = &v5->m_pendingMessages.mNode;
        v5->m_pendingMessages.mNode.mPrev = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)&v4->mPrev;
        UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v5->m_pendingMessagesMutex);
        return v4;
      }
      goto LABEL_44;
    }
  }
  if ( !UFG::gTweakerUpdateUI || !v5->m_updateUI )
  {
LABEL_44:
    v4->vfptr->__vecDelDtor((UFG::UICommand *)&v4->vfptr, 1u);
    return v4;
  }
  v20 = v4->m_commandType;
  if ( v20 >= 0 )
  {
    if ( v20 <= 4 )
    {
      v21 = &v5->m_screenCommandQueue;
      goto LABEL_42;
    }
    if ( v20 <= 7 )
    {
      v21 = &v5->m_commandQueue;
LABEL_42:
      v22 = v21->mNode.mPrev;
      v23 = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)&v4->mPrev;
      v22->mNext = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)&v4->mPrev;
      v23->mPrev = v22;
      v23->mNext = &v21->mNode;
      v21->mNode.mPrev = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)&v4->mPrev;
      return v4;
    }
  }
  return v4;
}

// File Line: 1170
// RVA: 0xA30E40
UFG::UIScreen *__fastcall UFG::UIScreenManagerBase::pushScreen(UFG::UIScreenManagerBase *this, UFG::UICommandScreenPush *pushScreenCommand)
{
  UFG::UICommandScreenPush *v2; // rsi
  UFG::UIScreenManagerBase *v3; // rbx
  unsigned int v4; // er15
  int v5; // ebp
  UFG::UIScreen *v6; // rdi
  UFG::UIMessage *v7; // r14
  int v8; // ecx
  signed __int64 v9; // rax
  int v10; // eax
  int v11; // er9
  int v12; // er8
  signed __int64 i; // rax
  signed __int64 v14; // rdx
  int v15; // ecx
  UFG::UIScreenManagerBase *v16; // rax
  signed __int64 v17; // rax
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v18; // rax
  UFG::allocator::free_link *v19; // rax
  UFG::UIMessage *v20; // rax

  v2 = pushScreenCommand;
  v3 = this;
  v4 = pushScreenCommand->m_screenUID;
  v5 = pushScreenCommand->m_controllerMask;
  v6 = pushScreenCommand->m_preCreatedInstance;
  if ( !v6 )
    v6 = (UFG::UIScreen *)UFG::UIScreenFactory::createScreen(this->m_screenFactory, pushScreenCommand->m_screenName);
  v6->mScreenUID = v4;
  v7 = 0i64;
  if ( v5 == -1 )
  {
    v8 = 0;
    v9 = (signed __int64)&v3->m_screenStack.mNode.mNext[-1].mNext;
    if ( (UFG::UIScreenManagerBase *)v9 == v3 )
      goto LABEL_26;
    do
    {
      ++v8;
      v9 = *(_QWORD *)(v9 + 16) - 8i64;
    }
    while ( (UFG::UIScreenManagerBase *)v9 != v3 );
    if ( v8 <= 0 )
LABEL_26:
      v10 = v3->m_defaultControllerMask;
    else
      v10 = HIDWORD(v3->m_screenStack.mNode.mPrev[6].mNext);
    v6->mControllerMask = v10;
  }
  else
  {
    v6->mControllerMask = v5;
  }
  v6->mDimToApplyType = v2->m_dimType;
  UFG::UIScreenManagerBase::dimPreviousScreen(v3, v2->m_dimType, v6);
  v11 = v3->m_maxScreenLimit;
  if ( v11 > 0 )
  {
    v12 = 0;
    for ( i = (signed __int64)&v3->m_screenStack.mNode.mNext[-1].mNext;
          (UFG::UIScreenManagerBase *)i != v3;
          i = *(_QWORD *)(i + 16) - 8i64 )
    {
      ++v12;
    }
    v14 = (signed __int64)&v3->mPendingScreenLoads;
    v15 = 0;
    v16 = (UFG::UIScreenManagerBase *)v3->mPendingScreenLoads.mNode.mNext;
    if ( v16 != (UFG::UIScreenManagerBase *)&v3->mPendingScreenLoads )
    {
      do
      {
        ++v15;
        v16 = (UFG::UIScreenManagerBase *)v16->m_screenStack.mNode.mPrev;
      }
      while ( v16 != (UFG::UIScreenManagerBase *)v14 );
    }
    if ( v15 + v12 >= v11 )
    {
      v17 = (signed __int64)&v3->m_screenStack.mNode.mNext[-1].mNext;
      if ( (UFG::UIScreenManagerBase *)v17 == v3 )
      {
        v18 = v3->mPendingScreenLoads.mNode.mNext;
        if ( v18 == (UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *)v14 )
          goto LABEL_21;
        v17 = (signed __int64)v18[1].mPrev;
      }
      UFG::UIScreenManagerBase::queuePopScreen(v3, *(_DWORD *)(v17 + 112));
    }
  }
LABEL_21:
  v19 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x68ui64, "UICommand", 0i64, 1u);
  if ( v19 )
  {
    UFG::UIMessageScreenPushed::UIMessageScreenPushed((UFG::UIMessageScreenPushed *)v19, v2->m_screenName, v4);
    v7 = v20;
  }
  UFG::UIScreenManagerBase::queueMessageEx(v3, v7);
  return v6;
}

// File Line: 1230
// RVA: 0xA309A0
void __fastcall UFG::UIScreenManagerBase::popScreen(UFG::UIScreenManagerBase *this, UFG::UICommandScreenPop *popScreenCommand)
{
  UFG::UIScreenManagerBase *v2; // r14
  _RTL_CRITICAL_SECTION *v3; // rbx
  UFG::qList<UFG::UIScreen,UFG::UIScreen,1,0> *v4; // r13
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v5; // rsi
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v6; // rcx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v7; // rax
  UFG::allocator::free_link *v8; // rax
  UFG::allocator::free_link *v9; // rdx
  int v10; // ecx
  UFG::allocator::free_link *v11; // rax
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v12; // rax
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *i; // rbx
  UFG::allocator::free_link *v14; // rax
  int v15; // edx
  UFG::allocator::free_link *v16; // rcx
  unsigned int v17; // ebx
  UFG::allocator::free_link *v18; // rax
  UFG::allocator::free_link *v19; // rdx
  UFG::allocator::free_link *v20; // rax
  signed __int64 v21; // rsi
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **v22; // rdi
  __int64 v23; // rcx
  _QWORD *v24; // rax
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v25; // rax
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v26; // rcx
  signed __int64 v27; // rbx

  v2 = this;
  if ( popScreenCommand->m_popAll )
  {
    if ( (UFG::UIScreenManagerBase *)&this->m_screenStack.mNode.mNext[-1].mNext != this )
    {
      v3 = &this->mScreenStackLock.cs;
      v4 = &this->mPendingPoppedScreens;
      do
      {
        EnterCriticalSection(v3);
        v5 = v2->m_screenStack.mNode.mPrev;
        v6 = v5->mPrev;
        v7 = v5->mNext;
        v6->mNext = v7;
        v7->mPrev = v6;
        v5->mPrev = v5;
        v5->mNext = v5;
        LeaveCriticalSection(v3);
        v8 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x40ui64, "UICommand", 0i64, 1u);
        v9 = v8;
        if ( v8 )
        {
          v10 = (int)v5[6].mNext;
          v11 = v8 + 1;
          v11->mNext = v11;
          v11[1].mNext = v11;
          v9->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable';
          LODWORD(v9[3].mNext) = -1;
          v9[4].mNext = 0i64;
          v9->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable';
          LODWORD(v9[5].mNext) = UI_HASH_SCREEN_POPPED_35;
          HIDWORD(v9[5].mNext) = 0;
          v9[6].mNext = (UFG::allocator::free_link *)-1i64;
          LODWORD(v9[3].mNext) = 5;
          v9->mNext = (UFG::allocator::free_link *)&UFG::UIMessageScreenPopped::`vftable';
          LODWORD(v9[7].mNext) = v10;
        }
        else
        {
          v9 = 0i64;
        }
        UFG::UIScreenManagerBase::queueMessageEx(v2, (UFG::UIMessage *)v9);
        ((void (__fastcall *)(UFG::qNode<UFG::UIScreen,UFG::UIScreen> *, _QWORD))v5[5].mNext[20].mPrev->mPrev[14].mPrev)(
          v5[5].mNext[20].mPrev,
          0i64);
        EnterCriticalSection(v3);
        v12 = v4->mNode.mPrev;
        v12->mNext = v5;
        v5->mPrev = v12;
        v5->mNext = &v4->mNode;
        v4->mNode.mPrev = v5;
        LeaveCriticalSection(v3);
      }
      while ( (UFG::UIScreenManagerBase *)&v2->m_screenStack.mNode.mNext[-1].mNext != v2 );
    }
    for ( i = v2->mPendingScreenLoads.mNode.mNext;
          i != (UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *)&v2->mPendingScreenLoads;
          i = i->mNext )
    {
      v14 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x40ui64, "UICommand", 0i64, 1u);
      if ( v14 )
      {
        v15 = (int)i[1].mPrev[7].mPrev;
        v16 = v14 + 1;
        v16->mNext = v16;
        v16[1].mNext = v16;
        v14->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable';
        LODWORD(v14[3].mNext) = -1;
        v14[4].mNext = 0i64;
        v14->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable';
        LODWORD(v14[5].mNext) = UI_HASH_SCREEN_POPPED_35;
        HIDWORD(v14[5].mNext) = 0;
        v14[6].mNext = (UFG::allocator::free_link *)-1i64;
        LODWORD(v14[3].mNext) = 5;
        v14->mNext = (UFG::allocator::free_link *)&UFG::UIMessageScreenPopped::`vftable';
        LODWORD(v14[7].mNext) = v15;
      }
      else
      {
        v14 = 0i64;
      }
      UFG::UIScreenManagerBase::queueMessageEx(v2, (UFG::UIMessage *)v14);
      LOBYTE(i[2].mPrev) = 1;
    }
  }
  else
  {
    v17 = popScreenCommand->m_screenUID;
    v18 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x40ui64, "UICommand", 0i64, 1u);
    v19 = v18;
    if ( v18 )
    {
      v20 = v18 + 1;
      v20->mNext = v20;
      v20[1].mNext = v20;
      v19->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable';
      LODWORD(v19[3].mNext) = -1;
      v19[4].mNext = 0i64;
      v19->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable';
      LODWORD(v19[5].mNext) = UI_HASH_SCREEN_POPPED_35;
      HIDWORD(v19[5].mNext) = 0;
      v19[6].mNext = (UFG::allocator::free_link *)-1i64;
      LODWORD(v19[3].mNext) = 5;
      v19->mNext = (UFG::allocator::free_link *)&UFG::UIMessageScreenPopped::`vftable';
      LODWORD(v19[7].mNext) = v17;
    }
    else
    {
      v19 = 0i64;
    }
    UFG::UIScreenManagerBase::queueMessageEx(v2, (UFG::UIMessage *)v19);
    v21 = (signed __int64)&v2->m_screenStack.mNode.mPrev[-1].mNext;
    if ( (UFG::UIScreenManagerBase *)v21 == v2 )
    {
LABEL_23:
      v26 = v2->mPendingScreenLoads.mNode.mPrev;
      if ( v26 != (UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *)&v2->mPendingScreenLoads )
      {
        while ( LODWORD(v26[1].mPrev[7].mPrev) != v17 && v17 != -1 )
        {
          v26 = v26->mPrev;
          if ( v26 == (UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *)&v2->mPendingScreenLoads )
            goto LABEL_29;
        }
        LOBYTE(v26[2].mPrev) = 1;
      }
    }
    else
    {
      while ( *(_DWORD *)(v21 + 112) != v17 && v17 != -1 )
      {
        v21 = *(_QWORD *)(v21 + 8) - 8i64;
        if ( (UFG::UIScreenManagerBase *)v21 == v2 )
          goto LABEL_23;
      }
      EnterCriticalSection(&v2->mScreenStackLock.cs);
      v22 = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> **)(v21 + 8);
      v23 = *(_QWORD *)(v21 + 8);
      v24 = *(_QWORD **)(v21 + 16);
      *(_QWORD *)(v23 + 8) = v24;
      *v24 = v23;
      *v22 = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)v22;
      v22[1] = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)v22;
      LeaveCriticalSection(&v2->mScreenStackLock.cs);
      (*(void (__fastcall **)(_QWORD, _QWORD))(**(_QWORD **)(*(_QWORD *)(v21 + 96) + 320i64) + 224i64))(
        *(_QWORD *)(*(_QWORD *)(v21 + 96) + 320i64),
        0i64);
      EnterCriticalSection(&v2->mScreenStackLock.cs);
      v25 = v2->mPendingPoppedScreens.mNode.mPrev;
      v25->mNext = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)(v21 + 8);
      *v22 = v25;
      *(_QWORD *)(v21 + 16) = (char *)v2 + 112;
      v2->mPendingPoppedScreens.mNode.mPrev = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)(v21 + 8);
      LeaveCriticalSection(&v2->mScreenStackLock.cs);
    }
  }
LABEL_29:
  v27 = (signed __int64)&v2->m_screenStack.mNode.mPrev[-1].mNext;
  if ( !v2->mIsMidSwitch
    && (UFG::UIScreenManagerBase *)v27 != v2
    && ((*(unsigned __int8 (__fastcall **)(UFG::qNode<UFG::UIScreen,UFG::UIScreen> **))(*(_QWORD *)v27 + 72i64))(&v2->m_screenStack.mNode.mPrev[-1].mNext)
     || (*(unsigned __int8 (__fastcall **)(signed __int64))(*(_QWORD *)v27 + 88i64))(v27)) )
  {
    (*(void (__fastcall **)(signed __int64, _QWORD))(*(_QWORD *)v27 + 64i64))(v27, 0i64);
  }
}

// File Line: 1308
// RVA: 0xA322A0
UFG::UIScreen *__fastcall UFG::UIScreenManagerBase::switchScreen(UFG::UIScreenManagerBase *this, UFG::UICommandScreenSwitch *switchScreenCommand)
{
  UFG::UICommandScreenSwitch *v2; // rbx
  UFG::UIScreenManagerBase *v3; // rdi
  unsigned int v4; // eax
  int v5; // ecx
  unsigned int v6; // eax
  UFG::UIScreen *v7; // r8
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v8; // rdx
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v9; // rcx
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v10; // rcx
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v11; // rax
  UFG::UICommandScreenPop popScreenCommand; // [rsp+20h] [rbp-D8h]
  __int64 v14; // [rsp+50h] [rbp-A8h]
  UFG::UICommandScreenPush pushScreenCommand; // [rsp+60h] [rbp-98h]

  v14 = -2i64;
  v2 = switchScreenCommand;
  v3 = this;
  this->mIsMidSwitch = 1;
  v4 = switchScreenCommand->m_screenUIDToPop;
  popScreenCommand.mPrev = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)&popScreenCommand.mPrev;
  popScreenCommand.mNext = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)&popScreenCommand.mPrev;
  popScreenCommand.m_commandData = 0i64;
  popScreenCommand.vfptr = (UFG::UICommandVtbl *)&UFG::UICommandScreenPop::`vftable';
  popScreenCommand.m_commandType = 1;
  popScreenCommand.m_popAll = 0;
  popScreenCommand.m_screenUID = v4;
  UFG::UIScreenManagerBase::popScreen(this, &popScreenCommand);
  v5 = v2->m_controllerMask;
  v6 = v2->m_screenUIDToPush;
  pushScreenCommand.mPrev = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)&pushScreenCommand.mPrev;
  pushScreenCommand.mNext = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)&pushScreenCommand.mPrev;
  *(_QWORD *)&pushScreenCommand.m_commandType = 0i64;
  pushScreenCommand.vfptr = (UFG::UICommandVtbl *)&UFG::UICommandScreenPush::`vftable';
  *(_DWORD *)&pushScreenCommand.m_screenName[120] = v6;
  *(_DWORD *)&pushScreenCommand.m_screenName[124] = v5;
  *(_QWORD *)&pushScreenCommand.m_screenUID = 0i64;
  LODWORD(pushScreenCommand.m_preCreatedInstance) = UFG::UIScreen::mDefaultDim;
  UFG::qStringCopy((char *)&pushScreenCommand.m_commandData, 128, v2->m_screenName, -1);
  pushScreenCommand.m_commandType = 0;
  *(_QWORD *)&pushScreenCommand.m_screenUID = v2->m_preCreatedInstance;
  LODWORD(pushScreenCommand.m_preCreatedInstance) = v2->m_dimType;
  v7 = UFG::UIScreenManagerBase::pushScreen(v3, &pushScreenCommand);
  v3->mIsMidSwitch = 0;
  v8 = pushScreenCommand.mPrev;
  v9 = pushScreenCommand.mNext;
  pushScreenCommand.mPrev->mNext = pushScreenCommand.mNext;
  v9->mPrev = v8;
  v10 = popScreenCommand.mPrev;
  v11 = popScreenCommand.mNext;
  popScreenCommand.mPrev->mNext = popScreenCommand.mNext;
  v11->mPrev = v10;
  return v7;
}

// File Line: 1327
// RVA: 0xA30D80
UFG::UIScreen *__fastcall UFG::UIScreenManagerBase::pushOverlay(UFG::UIScreenManagerBase *this, UFG::UICommandOverlayPush *pushOverlayCommand)
{
  _DWORD *v2; // r8
  unsigned int v3; // esi
  unsigned int v4; // ebp
  int v5; // edi
  UFG::UIScreenManagerBase *v6; // rbx
  int v7; // eax
  int v8; // eax
  signed __int64 v9; // rcx

  v2 = pushOverlayCommand->m_preCreatedInstance;
  v3 = pushOverlayCommand->m_screenUID;
  v4 = pushOverlayCommand->m_priority;
  v5 = pushOverlayCommand->m_controllerMask;
  v6 = this;
  if ( !v2 )
    v2 = UFG::UIScreenFactory::createScreen(this->m_screenFactory, pushOverlayCommand->m_screenName);
  v2[28] = v3;
  v2[31] = v4;
  if ( v5 == -1 )
  {
    v7 = v6->m_defaultControllerMask;
    if ( v7 == -1 )
    {
      v8 = 0;
      v9 = (signed __int64)&v6->m_screenStack.mNode.mNext[-1].mNext;
      if ( (UFG::UIScreenManagerBase *)v9 != v6 )
      {
        do
        {
          ++v8;
          v9 = *(_QWORD *)(v9 + 16) - 8i64;
        }
        while ( (UFG::UIScreenManagerBase *)v9 != v6 );
        if ( v8 > 0 )
          v2[29] = HIDWORD(v6->m_screenStack.mNode.mPrev[6].mNext);
      }
    }
    else
    {
      v2[29] = v7;
    }
  }
  else
  {
    v2[29] = v5;
  }
  return (UFG::UIScreen *)v2;
}

// File Line: 1373
// RVA: 0xA30750
void __fastcall UFG::UIScreenManagerBase::popOverlay(UFG::UIScreenManagerBase *this, UFG::UICommandOverlayPop *popOverlayCommand)
{
  UFG::UIScreenManagerBase *v2; // rbp
  unsigned int v3; // er14
  const char *v4; // rsi
  UFG::qList<UFG::UIScreen,UFG::UIScreen,1,0> *v5; // rsi
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v6; // rdi
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v7; // rcx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v8; // rax
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v9; // rax
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v10; // rax
  signed __int64 i; // rbp
  signed __int64 v12; // rdi
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **v13; // rsi
  __int64 v14; // rcx
  _QWORD *v15; // rax
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v16; // rax
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v17; // rbx
  signed __int64 v18; // rbp
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v19; // rdi

  v2 = this;
  v3 = popOverlayCommand->m_screenUID;
  v4 = popOverlayCommand->m_screenName;
  if ( v3 != -1 || (unsigned int)UFG::qStringCompare(v4, &customWorldMapCaption, -1) )
  {
    v12 = (signed __int64)&v2->m_overlayStack.mNode.mNext[-1].mNext;
    if ( (UFG::qNode<UFG::UIScreen,UFG::UIScreen> **)v12 == &v2->m_screenStack.mNode.mNext )
    {
LABEL_16:
      v17 = v2->mPendingOverlayLoads.mNode.mNext;
      v18 = (signed __int64)&v2->mPendingOverlayLoads;
      if ( v17 != (UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *)v18 )
      {
        while ( 1 )
        {
          v19 = v17[1].mPrev;
          if ( LODWORD(v19[7].mPrev) == v3
            || (unsigned int)UFG::qStringCompare(v4, &customWorldMapCaption, -1)
            && !(unsigned int)UFG::qStringCompare((const char *)&v19[1].mNext, v4, -1) )
          {
            break;
          }
          v17 = v17->mNext;
          if ( v17 == (UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *)v18 )
            return;
        }
        LOBYTE(v17[2].mPrev) = 1;
      }
    }
    else
    {
      while ( *(_DWORD *)(v12 + 112) != v3
           && (!(unsigned int)UFG::qStringCompare(v4, &customWorldMapCaption, -1)
            || (unsigned int)UFG::qStringCompare((const char *)(v12 + 24), v4, -1)) )
      {
        v12 = *(_QWORD *)(v12 + 16) - 8i64;
        if ( (UFG::qNode<UFG::UIScreen,UFG::UIScreen> **)v12 == &v2->m_screenStack.mNode.mNext )
          goto LABEL_16;
      }
      EnterCriticalSection(&v2->mScreenStackLock.cs);
      v13 = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> **)(v12 + 8);
      v14 = *(_QWORD *)(v12 + 8);
      v15 = *(_QWORD **)(v12 + 16);
      *(_QWORD *)(v14 + 8) = v15;
      *v15 = v14;
      *v13 = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)v13;
      v13[1] = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)v13;
      LeaveCriticalSection(&v2->mScreenStackLock.cs);
      (*(void (__fastcall **)(_QWORD, _QWORD))(**(_QWORD **)(*(_QWORD *)(v12 + 96) + 320i64) + 224i64))(
        *(_QWORD *)(*(_QWORD *)(v12 + 96) + 320i64),
        0i64);
      EnterCriticalSection(&v2->mScreenStackLock.cs);
      v16 = v2->mPendingPoppedScreens.mNode.mPrev;
      v16->mNext = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)(v12 + 8);
      *v13 = v16;
      *(_QWORD *)(v12 + 16) = (char *)v2 + 112;
      v2->mPendingPoppedScreens.mNode.mPrev = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)(v12 + 8);
      LeaveCriticalSection(&v2->mScreenStackLock.cs);
    }
  }
  else
  {
    if ( &v2->m_overlayStack.mNode.mNext[-1].mNext != &v2->m_screenStack.mNode.mNext )
    {
      v5 = &v2->mPendingPoppedScreens;
      do
      {
        EnterCriticalSection(&v2->mScreenStackLock.cs);
        v6 = v2->m_overlayStack.mNode.mPrev;
        v7 = v6->mPrev;
        v8 = v6->mNext;
        v7->mNext = v8;
        v8->mPrev = v7;
        v6->mPrev = v6;
        v6->mNext = v6;
        LeaveCriticalSection(&v2->mScreenStackLock.cs);
        ((void (__fastcall *)(UFG::qNode<UFG::UIScreen,UFG::UIScreen> *, _QWORD))v6[5].mNext[20].mPrev->mPrev[14].mPrev)(
          v6[5].mNext[20].mPrev,
          0i64);
        EnterCriticalSection(&v2->mScreenStackLock.cs);
        v9 = v5->mNode.mPrev;
        v9->mNext = v6;
        v6->mPrev = v9;
        v6->mNext = &v5->mNode;
        v5->mNode.mPrev = v6;
        LeaveCriticalSection(&v2->mScreenStackLock.cs);
      }
      while ( &v2->m_overlayStack.mNode.mNext[-1].mNext != &v2->m_screenStack.mNode.mNext );
    }
    v10 = v2->mPendingOverlayLoads.mNode.mNext;
    for ( i = (signed __int64)&v2->mPendingOverlayLoads;
          v10 != (UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *)i;
          v10 = v10->mNext )
    {
      LOBYTE(v10[2].mPrev) = 1;
    }
  }
}

// File Line: 1440
// RVA: 0xA2F500
bool __fastcall UFG::UIScreenManagerBase::handleMessage(UFG::UIScreenManagerBase *this, UFG::UIMessage *msg)
{
  UFG::UIMessage *v2; // rdi
  UFG::UIScreenManagerBase *v3; // rsi
  UFG::UIFlowRoot *v4; // rax
  bool result; // al
  UFG::UIScreen *v6; // rbx
  unsigned int v7; // er14
  void (__fastcall *v8)(const char *, unsigned int, unsigned int, unsigned int); // rax

  v2 = msg;
  v3 = this;
  v4 = UFG::LazyInitGet<UFG::UIFlowRoot>::get();
  if ( v4->vfptr->flowHandleMessage((UFG::UIFlow *)&v4->vfptr, v2->m_messageId, v2) )
    return 1;
  result = UFG::UIScreenManagerBase::handleMessage(v3, v2, &v3->m_screenStack, v3->m_eatInputForScreens);
  if ( !result )
  {
    v6 = (UFG::UIScreen *)&v3->m_overlayStack.mNode.mPrev[-1].mNext;
    v7 = v2->m_receiverUID;
    if ( v6 == (UFG::UIScreen *)&v3->m_screenStack.mNode.mNext )
    {
LABEL_18:
      result = 0;
    }
    else
    {
      while ( 1 )
      {
        if ( (v2->m_receiverUID == -1 || v6->mScreenUID == v7)
          && (v2->m_commandType != 6
           || v6->mInputEnabled >= 0
           && !v6->vfptr->isDimmed(v6)
           && !v6->vfptr->isDimming(v6)
           && !v6->vfptr->isUnDimming(v6)
           && (v2->m_messageType || v6->mControllerMask & HIDWORD(v2[1].vfptr))) )
        {
          if ( v2->m_commandType == 6 )
            UFG::UIScreen::handleInput(v6, v2->m_messageId, v2);
          if ( v6->vfptr->handleMessage(v6, v2->m_messageId, v2) )
            break;
        }
        v6 = (UFG::UIScreen *)&v6->mPrev[-1].mNext;
        if ( v6 == (UFG::UIScreen *)&v3->m_screenStack.mNode.mNext )
          goto LABEL_18;
      }
      v8 = v3->m_audioCallback;
      if ( v8 )
        v8(v6->m_screenName, v6->m_screenNameHash, v2->m_messageId, v2->m_resultId);
      result = 1;
    }
  }
  return result;
}

// File Line: 1496
// RVA: 0xA2F650
char __fastcall UFG::UIScreenManagerBase::handleMessage(UFG::UIScreenManagerBase *this, UFG::UIMessage *msg, UFG::qList<UFG::UIScreen,UFG::UIScreen,1,0> *stack, bool eatInput)
{
  unsigned int v4; // er14
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **v5; // r15
  char *v6; // rbx
  bool v7; // bp
  UFG::UIMessage *v8; // rdi
  UFG::UIScreenManagerBase *v9; // r13
  bool v10; // si
  bool v11; // zf
  void (__fastcall *v13)(const char *, unsigned int, unsigned int, unsigned int); // rax

  v4 = msg->m_receiverUID;
  v5 = &stack[-1].mNode.mNext;
  v6 = (char *)&stack->mNode.mPrev[-1].mNext;
  v7 = eatInput;
  v8 = msg;
  v9 = this;
  if ( v6 == (char *)&stack[-1].mNode.mNext )
    return 0;
  while ( 1 )
  {
    if ( v8->m_receiverUID != -1 && *((_DWORD *)v6 + 28) != v4 )
      goto LABEL_19;
    v10 = v8->m_commandType == 6;
    if ( v8->m_commandType == 6
      && (*((_DWORD *)v6 + 30) < 0
       || (*(unsigned __int8 (__fastcall **)(char *))(*(_QWORD *)v6 + 72i64))(v6)
       || (*(unsigned __int8 (__fastcall **)(char *))(*(_QWORD *)v6 + 88i64))(v6)
       || (*(unsigned __int8 (__fastcall **)(char *))(*(_QWORD *)v6 + 80i64))(v6)
       || v8->m_messageType == UIMESSAGE_PAD_INPUT && !(*((_DWORD *)v6 + 29) & HIDWORD(v8[1].vfptr))) )
    {
      v11 = v7 == 0;
      goto LABEL_18;
    }
    if ( v8->m_commandType == 6 )
      UFG::UIScreen::handleInput((UFG::UIScreen *)v6, v8->m_messageId, v8);
    if ( (*(unsigned __int8 (__fastcall **)(char *, _QWORD, UFG::UIMessage *))(*(_QWORD *)v6 + 32i64))(
           v6,
           v8->m_messageId,
           v8) )
    {
      break;
    }
    if ( !v10 || !v7 )
      goto LABEL_19;
    v11 = v8->m_messageType == 3;
LABEL_18:
    if ( !v11 )
      return 1;
LABEL_19:
    v6 = (char *)(*((_QWORD *)v6 + 1) - 8i64);
    if ( v6 == (char *)v5 )
      return 0;
  }
  v13 = v9->m_audioCallback;
  if ( v13 )
    v13(v6 + 24, *((_DWORD *)v6 + 22), v8->m_messageId, v8->m_resultId);
  return 1;
}

// File Line: 1601
// RVA: 0xA32820
void __fastcall UFG::UIScreenManagerBase::updateCommandQueue(UFG::UIScreenManagerBase *this, float elapsed)
{
  int *v2; // rsi
  UFG::UIScreenManagerBase *v3; // rdi
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v4; // rbx
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v5; // rax
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v6; // rcx

  v2 = &this->m_defaultControllerMask;
  v3 = this;
  if ( (int *)&this->m_commandQueue.mNode.mNext[-1].mNext != &this->m_defaultControllerMask )
  {
    do
    {
      v4 = v3->m_commandQueue.mNode.mNext;
      v5 = v4->mNext;
      v6 = v4->mPrev;
      v6->mNext = v5;
      v5->mPrev = v6;
      v4->mPrev = v4;
      v4->mNext = v4;
      if ( (unsigned int)(LODWORD(v4[1].mPrev) - 5) <= 2 )
        UFG::UIScreenManagerBase::handleMessage(v3, (UFG::UIMessage *)&v4[-1].mNext);
      ((void (__fastcall *)(UFG::qNode<UFG::UICommand,UFG::UICommand> **, signed __int64))v4[-1].mNext->mPrev)(
        &v4[-1].mNext,
        1i64);
    }
    while ( (int *)&v3->m_commandQueue.mNode.mNext[-1].mNext != v2 );
  }
}

// File Line: 1641
// RVA: 0xA32D40
void __fastcall UFG::UIScreenManagerBase::updateScreenCommandQueue(UFG::UIScreenManagerBase *this, float elapsed)
{
  UFG::UIScreenManagerBase *v2; // rsi
  UFG::qNode<UFG::UICommand,UFG::UICommand> **v3; // r14
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v4; // rdx
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v5; // rcx
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v6; // rax
  signed __int64 v7; // rdi
  int v8; // ecx
  int v9; // ecx
  int v10; // ecx
  int v11; // ecx
  UFG::UIScreen *v12; // rbp
  UFG::allocator::free_link *v13; // rbx
  UFG::allocator::free_link *v14; // rax
  UFG::allocator::free_link *v15; // rdx
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v16; // rax
  UFG::allocator::free_link *v17; // rbx
  Scaleform::GFx::Loader *v18; // rax
  int v19; // eax
  UFG::allocator::free_link *v20; // rbx
  UFG::allocator::free_link *v21; // rax
  UFG::allocator::free_link *v22; // rdx
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v23; // rax
  Scaleform::GFx::Loader *v24; // rax
  int v25; // eax
  UFG::allocator::free_link *v26; // rbx
  UFG::allocator::free_link *v27; // rax
  UFG::allocator::free_link *v28; // rdx
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v29; // rax
  Scaleform::GFx::Loader *v30; // rax
  int v31; // eax
  char dest; // [rsp+40h] [rbp-628h]
  char text; // [rsp+240h] [rbp-428h]
  char v34; // [rsp+440h] [rbp-228h]

  v2 = this;
  v3 = &this->m_commandQueue.mNode.mNext;
  if ( &this->m_screenCommandQueue.mNode.mNext[-1].mNext != &this->m_commandQueue.mNode.mNext )
  {
    while ( 1 )
    {
      v4 = v2->m_screenCommandQueue.mNode.mNext;
      v5 = v4->mPrev;
      v6 = v4->mNext;
      v5->mNext = v6;
      v6->mPrev = v5;
      v4->mPrev = v4;
      v4->mNext = v4;
      v7 = (signed __int64)&v4[-1].mNext;
      v8 = (int)v4[1].mPrev;
      if ( !v8 )
        break;
      v9 = v8 - 1;
      if ( v9 )
      {
        v10 = v9 - 1;
        if ( v10 )
        {
          v11 = v10 - 1;
          if ( v11 )
          {
            if ( v11 == 1 )
              UFG::UIScreenManagerBase::popOverlay(v2, (UFG::UICommandOverlayPop *)&v4[-1].mNext);
            goto LABEL_30;
          }
          v12 = UFG::UIScreenManagerBase::pushOverlay(v2, (UFG::UICommandOverlayPush *)&v4[-1].mNext);
          v13 = *(UFG::allocator::free_link **)(v7 + 32);
          v14 = UFG::qMalloc(0x28ui64, "UIScreenManagerBase::updateScreenCommandQueue", 0i64);
          v15 = v14;
          if ( v14 )
          {
            v14->mNext = v14;
            v14[1].mNext = v14;
            v14[2].mNext = (UFG::allocator::free_link *)v12;
            v14[3].mNext = v13;
            LOBYTE(v14[4].mNext) = 0;
            HIDWORD(v14[4].mNext) = 1;
          }
          else
          {
            v15 = 0i64;
          }
          v16 = v2->mPendingOverlayLoads.mNode.mPrev;
          v16->mNext = (UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *)v15;
          v15->mNext = (UFG::allocator::free_link *)v16;
          v15[1].mNext = (UFG::allocator::free_link *)&v2->mPendingOverlayLoads;
          v2->mPendingOverlayLoads.mNode.mPrev = (UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *)v15;
          UFG::qSPrintf(&dest, "%s%s.gfx", v2->m_screenFactory->m_rootDir, v7 + 40);
          v17 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x168ui64, "UIScreen::load", 0i64, 1u);
          if ( v17 )
          {
            v18 = v2->m_gfxMovieLoader;
            v17->mNext = (UFG::allocator::free_link *)&UFG::UIScreenRenderable::`vftable';
            v17[1].mNext = 0i64;
            LOBYTE(v17[2].mNext) = 0;
            v17[39].mNext = 0i64;
            v17[40].mNext = 0i64;
            v17[41].mNext = (UFG::allocator::free_link *)v18;
            v17[42].mNext = 0i64;
            v17[43].mNext = 0i64;
            LOBYTE(v17[44].mNext) = 1;
            BYTE1(v17[44].mNext) = 0;
            v19 = UFG::qStringLength(&dest);
            UFG::qStringCopy((char *)&v17[2].mNext + 1, 256, &dest, v19);
          }
          else
          {
            v17 = 0i64;
          }
        }
        else
        {
          v12 = UFG::UIScreenManagerBase::switchScreen(v2, (UFG::UICommandScreenSwitch *)&v4[-1].mNext);
          v20 = *(UFG::allocator::free_link **)(v7 + 32);
          v21 = UFG::qMalloc(0x28ui64, "UIScreenManagerBase::updateScreenCommandQueue", 0i64);
          v22 = v21;
          if ( v21 )
          {
            v21->mNext = v21;
            v21[1].mNext = v21;
            v21[2].mNext = (UFG::allocator::free_link *)v12;
            v21[3].mNext = v20;
            LOBYTE(v21[4].mNext) = 0;
            HIDWORD(v21[4].mNext) = 1;
          }
          else
          {
            v22 = 0i64;
          }
          v23 = v2->mPendingScreenLoads.mNode.mPrev;
          v23->mNext = (UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *)v22;
          v22->mNext = (UFG::allocator::free_link *)v23;
          v22[1].mNext = (UFG::allocator::free_link *)&v2->mPendingScreenLoads;
          v2->mPendingScreenLoads.mNode.mPrev = (UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *)v22;
          UFG::qSPrintf(&text, "%s%s.gfx", v2->m_screenFactory->m_rootDir, v7 + 44);
          v17 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x168ui64, "UIScreen::load", 0i64, 1u);
          if ( v17 )
          {
            v24 = v2->m_gfxMovieLoader;
            v17->mNext = (UFG::allocator::free_link *)&UFG::UIScreenRenderable::`vftable';
            v17[1].mNext = 0i64;
            LOBYTE(v17[2].mNext) = 0;
            v17[39].mNext = 0i64;
            v17[40].mNext = 0i64;
            v17[41].mNext = (UFG::allocator::free_link *)v24;
            v17[42].mNext = 0i64;
            v17[43].mNext = 0i64;
            LOBYTE(v17[44].mNext) = 1;
            BYTE1(v17[44].mNext) = 0;
            v25 = UFG::qStringLength(&text);
            UFG::qStringCopy((char *)&v17[2].mNext + 1, 256, &text, v25);
          }
          else
          {
            v17 = 0i64;
          }
        }
        goto LABEL_29;
      }
      UFG::UIScreenManagerBase::popScreen(v2, (UFG::UICommandScreenPop *)&v4[-1].mNext);
LABEL_30:
      (**(void (__fastcall ***)(signed __int64, signed __int64))v7)(v7, 1i64);
      if ( &v2->m_screenCommandQueue.mNode.mNext[-1].mNext == v3 )
        return;
    }
    v12 = UFG::UIScreenManagerBase::pushScreen(v2, (UFG::UICommandScreenPush *)&v4[-1].mNext);
    v26 = *(UFG::allocator::free_link **)(v7 + 32);
    v27 = UFG::qMalloc(0x28ui64, "UIScreenManagerBase::updateScreenCommandQueue", 0i64);
    v28 = v27;
    if ( v27 )
    {
      v27->mNext = v27;
      v27[1].mNext = v27;
      v27[2].mNext = (UFG::allocator::free_link *)v12;
      v27[3].mNext = v26;
      LOBYTE(v27[4].mNext) = 0;
      HIDWORD(v27[4].mNext) = 1;
    }
    else
    {
      v28 = 0i64;
    }
    v29 = v2->mPendingScreenLoads.mNode.mPrev;
    v29->mNext = (UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *)v28;
    v28->mNext = (UFG::allocator::free_link *)v29;
    v28[1].mNext = (UFG::allocator::free_link *)&v2->mPendingScreenLoads;
    v2->mPendingScreenLoads.mNode.mPrev = (UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *)v28;
    UFG::qSPrintf(&v34, "%s%s.gfx", v2->m_screenFactory->m_rootDir, v7 + 40);
    v17 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x168ui64, "UIScreen::load", 0i64, 1u);
    if ( v17 )
    {
      v30 = v2->m_gfxMovieLoader;
      v17->mNext = (UFG::allocator::free_link *)&UFG::UIScreenRenderable::`vftable';
      v17[1].mNext = 0i64;
      LOBYTE(v17[2].mNext) = 0;
      v17[39].mNext = 0i64;
      v17[40].mNext = 0i64;
      v17[41].mNext = (UFG::allocator::free_link *)v30;
      v17[42].mNext = 0i64;
      v17[43].mNext = 0i64;
      LOBYTE(v17[44].mNext) = 1;
      BYTE1(v17[44].mNext) = 0;
      v31 = UFG::qStringLength(&v34);
      UFG::qStringCopy((char *)&v17[2].mNext + 1, 256, &v34, v31);
    }
    else
    {
      v17 = 0i64;
    }
LABEL_29:
    UFG::UIScreen::load(v12, (UFG::UIScreenRenderable *)v17);
    goto LABEL_30;
  }
}  UFG::qStringCopy((char *)&v17[2].mNext + 1, 256, &v34, v31);
    }
 

// File Line: 1724
// RVA: 0xA2BA30
UFG::UIScreen *__fastcall UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManagerBase *this, const char *fileName)
{
  const char *v2; // rdi
  UFG::UIScreenManagerBase *v3; // rbx
  UFG::UIScreen *result; // rax

  v2 = fileName;
  v3 = this;
  result = (UFG::UIScreen *)UFG::UIScreenManagerBase::getScreenFromStack(this, fileName, &this->m_screenStack);
  if ( !result )
    result = UFG::UIScreenManagerBase::getScreenFromPendingStack(v3, v2, &v3->mPendingScreenLoads);
  return result;
}

// File Line: 1739
// RVA: 0xA2B9A0
UFG::UIScreen *__fastcall UFG::UIScreenManagerBase::getOverlay(UFG::UIScreenManagerBase *this, const char *fileName)
{
  const char *v2; // rdi
  UFG::UIScreenManagerBase *v3; // rbx
  UFG::UIScreen *result; // rax

  v2 = fileName;
  v3 = this;
  result = (UFG::UIScreen *)UFG::UIScreenManagerBase::getScreenFromStack(this, fileName, &this->m_overlayStack);
  if ( !result )
    result = UFG::UIScreenManagerBase::getScreenFromPendingStack(v3, v2, &v3->mPendingOverlayLoads);
  return result;
}

// File Line: 1754
// RVA: 0xA2BB60
signed __int64 __fastcall UFG::UIScreenManagerBase::getScreenUID(UFG::UIScreenManagerBase *this, const char *fileName)
{
  const char *v2; // rdi
  UFG::UIScreenManagerBase *v3; // rbx
  unsigned int *v4; // rax
  signed __int64 result; // rax

  v2 = fileName;
  v3 = this;
  v4 = (unsigned int *)UFG::UIScreenManagerBase::getScreenFromStack(this, fileName, &this->m_screenStack);
  if ( v4
    || (v4 = (unsigned int *)UFG::UIScreenManagerBase::getScreenFromPendingStack(v3, v2, &v3->mPendingScreenLoads)) != 0i64 )
  {
    result = v4[28];
  }
  else
  {
    result = 0xFFFFFFFFi64;
  }
  return result;
}

// File Line: 1814
// RVA: 0xA2B9E0
UFG::qNode<UFG::UIScreen,UFG::UIScreen> **__fastcall UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManagerBase *this, unsigned int screenUID)
{
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **result; // rax
  UFG::UIScreenManagerBase *v3; // rax

  result = &this->m_screenStack.mNode.mNext[-1].mNext;
  if ( result == (UFG::qNode<UFG::UIScreen,UFG::UIScreen> **)this )
  {
LABEL_4:
    v3 = (UFG::UIScreenManagerBase *)this->mPendingScreenLoads.mNode.mNext;
    if ( v3 == (UFG::UIScreenManagerBase *)&this->mPendingScreenLoads )
    {
LABEL_7:
      result = 0i64;
    }
    else
    {
      while ( LODWORD(v3->m_screenStack.mNode.mNext[7].mPrev) != screenUID )
      {
        v3 = (UFG::UIScreenManagerBase *)v3->m_screenStack.mNode.mPrev;
        if ( v3 == (UFG::UIScreenManagerBase *)&this->mPendingScreenLoads )
          goto LABEL_7;
      }
      result = &v3->m_screenStack.mNode.mNext->mPrev;
    }
  }
  else
  {
    while ( *((_DWORD *)result + 28) != screenUID )
    {
      result = &result[2][-1].mNext;
      if ( result == (UFG::qNode<UFG::UIScreen,UFG::UIScreen> **)this )
        goto LABEL_4;
    }
  }
  return result;
}

// File Line: 1845
// RVA: 0xA2BAE0
UFG::qNode<UFG::UIScreen,UFG::UIScreen> **__fastcall UFG::UIScreenManagerBase::getScreenFromStack(UFG::UIScreenManagerBase *this, const char *screenName, UFG::qList<UFG::UIScreen,UFG::UIScreen,1,0> *stack)
{
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **v3; // rdi
  const char *v4; // rsi
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **v5; // rbx

  v3 = &stack[-1].mNode.mNext;
  v4 = screenName;
  v5 = &stack->mNode.mNext[-1].mNext;
  if ( v5 == &stack[-1].mNode.mNext )
    return 0i64;
  while ( (unsigned int)UFG::qStringCompare((const char *)v5 + 24, v4, -1) )
  {
    v5 = &v5[2][-1].mNext;
    if ( v5 == v3 )
      return 0i64;
  }
  return v5;
}

// File Line: 1903
// RVA: 0xA2BA70
UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *__fastcall UFG::UIScreenManagerBase::getScreenFromPendingStack(UFG::UIScreenManagerBase *this, const char *screenName, UFG::qList<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad,1,0> *stack)
{
  UFG::qList<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad,1,0> *v3; // rbx
  UFG::qList<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad,1,0> *v4; // rdi
  const char *v5; // rbp
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v6; // rsi

  v3 = (UFG::qList<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad,1,0> *)stack->mNode.mNext;
  v4 = stack;
  v5 = screenName;
  if ( v3 == stack )
    return 0i64;
  while ( 1 )
  {
    v6 = v3[1].mNode.mPrev;
    if ( !(unsigned int)UFG::qStringCompare((const char *)&v6[1].mNext, v5, -1) )
      break;
    v3 = (UFG::qList<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad,1,0> *)v3->mNode.mNext;
    if ( v3 == v4 )
      return 0i64;
  }
  return v6;
}

// File Line: 1995
// RVA: 0xA2BEF0
UFG::qNode<UFG::UIScreen,UFG::UIScreen> **__fastcall UFG::UIScreenManagerBase::getTopScreen(UFG::UIScreenManagerBase *this)
{
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **result; // rax

  result = &this->m_screenStack.mNode.mPrev[-1].mNext;
  if ( result == (UFG::qNode<UFG::UIScreen,UFG::UIScreen> **)this )
    result = 0i64;
  return result;
}

// File Line: 2009
// RVA: 0xA29480
bool __fastcall UFG::UIScreenManagerBase::areScreensPending(UFG::UIScreenManagerBase *this)
{
  return this->mPendingScreenLoads.mNode.mNext != &this->mPendingScreenLoads.mNode;
}

// File Line: 2019
// RVA: 0xA29470
bool __fastcall UFG::UIScreenManagerBase::areOverlaysPending(UFG::UIScreenManagerBase *this)
{
  return this->mPendingOverlayLoads.mNode.mNext != &this->mPendingOverlayLoads.mNode;
}

// File Line: 2047
// RVA: 0xA2A8E0
void __fastcall UFG::UIScreenManagerBase::debugRender(UFG::UIScreenManagerBase *this)
{
  UFG::UIScreenManagerBase *v1; // rdi
  Render::DebugDrawContext *v2; // rsi
  UFG::UIGfxTranslator *v3; // rax
  const char *v4; // rax
  signed __int64 v5; // rbx
  int v6; // ebp
  int i; // er14
  int v8; // eax
  const char *v9; // r9
  signed __int64 j; // rbx
  int v11; // eax
  const char *v12; // r9
  char dest; // [rsp+30h] [rbp-28h]

  v1 = this;
  if ( UFG::gUIPrint )
  {
    v2 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
    v3 = v1->m_translator;
    if ( !UFG::gUIShowIconsInBlankLoc || v3->mLanguage )
      v4 = UFG::UILanguages::getLanguageString(v3->mLanguage);
    else
      v4 = "English";
    Render::DebugDrawContext::DrawTextA(v2, 50, 400, &UFG::qColour::White, "Language: %s", v4);
    Render::DebugDrawContext::DrawTextA(v2, 50, 415, &UFG::qColour::White, "Overlays:");
    v5 = (signed __int64)&v1->m_overlayStack.mNode.mPrev[-1].mNext;
    v6 = 430;
    for ( i = 430;
          (UFG::qNode<UFG::UIScreen,UFG::UIScreen> **)v5 != &v1->m_screenStack.mNode.mNext;
          v5 = *(_QWORD *)(v5 + 8) - 8i64 )
    {
      UFG::qSPrintf(&dest, 16, "%d", *(unsigned int *)(v5 + 112));
      Render::DebugDrawContext::DrawTextA(v2, 50, i, &UFG::qColour::Grey, &dest);
      UFG::qSPrintf(&dest, 16, "%d", *(unsigned int *)(v5 + 120));
      Render::DebugDrawContext::DrawTextA(v2, 75, i, &UFG::qColour::Grey, &dest);
      v8 = Scaleform::GFx::Movie::GetAVMVersion(*(Scaleform::GFx::Movie **)(*(_QWORD *)(v5 + 96) + 320i64));
      v9 = "AS3";
      if ( v8 == 1 )
        v9 = "AS2";
      UFG::qSPrintf(&dest, 16, "%s", v9);
      Render::DebugDrawContext::DrawTextA(v2, 95, i, &UFG::qColour::Grey, &dest);
      Render::DebugDrawContext::DrawTextA(v2, 125, i, &UFG::qColour::Grey, (const char *)(v5 + 24));
      i += 15;
    }
    Render::DebugDrawContext::DrawTextA(v2, 250, 415, &UFG::qColour::White, "Screens:");
    for ( j = (signed __int64)&v1->m_screenStack.mNode.mPrev[-1].mNext;
          (UFG::UIScreenManagerBase *)j != v1;
          j = *(_QWORD *)(j + 8) - 8i64 )
    {
      UFG::qSPrintf(&dest, 16, "%d", *(unsigned int *)(j + 112));
      Render::DebugDrawContext::DrawTextA(v2, 250, v6, &UFG::qColour::Grey, &dest);
      UFG::qSPrintf(&dest, 16, "%d", *(unsigned int *)(j + 120));
      Render::DebugDrawContext::DrawTextA(v2, 275, v6, &UFG::qColour::Grey, &dest);
      v11 = Scaleform::GFx::Movie::GetAVMVersion(*(Scaleform::GFx::Movie **)(*(_QWORD *)(j + 96) + 320i64));
      v12 = "AS3";
      if ( v11 == 1 )
        v12 = "AS2";
      UFG::qSPrintf(&dest, 16, "%s", v12);
      Render::DebugDrawContext::DrawTextA(v2, 295, v6, &UFG::qColour::Grey, &dest);
      Render::DebugDrawContext::DrawTextA(v2, 325, v6, &UFG::qColour::Grey, (const char *)(j + 24));
      v6 += 15;
    }
    v1->m_currentNumDrawText = 0;
  }
  else
  {
    this->m_currentNumDrawText = 0;
  }
}

// File Line: 2129
// RVA: 0xA31B60
void __fastcall UFG::UIScreenManagerBase::renderScreens(UFG::UIScreenManagerBase *this)
{
  UFG::UIScreenManagerBase *v1; // rsi
  _RTL_CRITICAL_SECTION *v2; // rbx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **i; // rdi
  signed __int64 v4; // rdi
  signed __int64 j; // rbp
  Scaleform::GFx::Resource **v6; // rsi
  hkDynamicClassNameRegistry **v7; // rax
  Scaleform::Render::ContextImpl::RenderNotify *v8; // rax
  Scaleform::Render::ContextImpl::RTHandle v9; // [rsp+50h] [rbp+8h]
  Scaleform::Render::RenderBuffer *v10; // [rsp+58h] [rbp+10h]
  Scaleform::Lock *v11; // [rsp+60h] [rbp+18h]

  v1 = this;
  v2 = &this->mScreenStackLock.cs;
  v11 = &this->mScreenStackLock;
  EnterCriticalSection(&this->mScreenStackLock.cs);
  for ( i = &v1->m_screenStack.mNode.mNext[-1].mNext;
        i != (UFG::qNode<UFG::UIScreen,UFG::UIScreen> **)v1;
        i = &i[2][-1].mNext )
  {
    if ( !i[12]->mNext )
      ((void (__fastcall *)(UFG::qNode<UFG::UIScreen,UFG::UIScreen> **))(*i)[1].mPrev)(i);
  }
  v4 = (signed __int64)&v1->mPendingPoppedScreens.mNode.mNext[-1].mNext;
  for ( j = (signed __int64)&v1->mPendingOverlayLoads.mNode.mNext; v4 != j; v4 = *(_QWORD *)(v4 + 16) - 8i64 )
  {
    v6 = (Scaleform::GFx::Resource **)(*(__int64 (__cdecl **)(_QWORD))(**(_QWORD **)(*(_QWORD *)(v4 + 96) + 320i64)
                                                                     + 208i64))(*(_QWORD *)(*(_QWORD *)(v4 + 96) + 320i64));
    if ( *v6 )
      Scaleform::Render::RenderBuffer::AddRef(*v6);
    v9.pData.pObject = (Scaleform::Render::ContextImpl::RTHandle::HandleData *)*v6;
    v7 = (hkDynamicClassNameRegistry **)UFG::UIScreenManager::s_instance->vfptr->getRenderer2D(
                                          (UFG::UIScreenManagerBase *)UFG::UIScreenManager::s_instance,
                                          (Scaleform::Ptr<Scaleform::Render::Renderer2D> *)&v10);
    v8 = (Scaleform::Render::ContextImpl::RenderNotify *)SSUnaryParam::get_expected_type(*v7);
    Scaleform::Render::ContextImpl::RTHandle::NextCapture(&v9, v8);
    if ( v10 )
      Scaleform::RefCountImpl::Release(v10);
    Scaleform::Render::ContextImpl::RTHandle::~RTHandle(&v9);
  }
  LeaveCriticalSection(v2);
}

// File Line: 2151
// RVA: 0xA31AE0
void __fastcall UFG::UIScreenManagerBase::renderOverlays(UFG::UIScreenManagerBase *this)
{
  UFG::UIScreenManagerBase *v1; // rsi
  _RTL_CRITICAL_SECTION *v2; // rbx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **v3; // rdi
  signed __int64 i; // rsi

  v1 = this;
  v2 = &this->mScreenStackLock.cs;
  EnterCriticalSection(&this->mScreenStackLock.cs);
  v3 = &v1->m_overlayStack.mNode.mNext[-1].mNext;
  for ( i = (signed __int64)&v1->m_screenStack.mNode.mNext;
        v3 != (UFG::qNode<UFG::UIScreen,UFG::UIScreen> **)i;
        v3 = &v3[2][-1].mNext )
  {
    if ( !v3[12]->mNext )
      ((void (__fastcall *)(UFG::qNode<UFG::UIScreen,UFG::UIScreen> **))(*v3)[1].mPrev)(v3);
  }
  LeaveCriticalSection(v2);
}

// File Line: 2170
// RVA: 0xA2FDF0
void __fastcall UFG::UIScreenManagerBase::initCustomRendering(UFG::UIScreenManagerBase *this)
{
  unsigned int v1; // eax
  UFG::qResourceData *v2; // rax
  UFG::qResourceData *v3; // rbx
  UFG::qResourceWarehouse *v4; // rax
  unsigned int v5; // eax
  UFG::qResourceData *v6; // rax
  UFG::qResourceData *v7; // rbx
  UFG::qResourceWarehouse *v8; // rax
  unsigned int v9; // eax
  UFG::qResourceData *v10; // rax
  UFG::qResourceData *v11; // rbx
  UFG::qResourceWarehouse *v12; // rax
  unsigned int v13; // eax
  UFG::qResourceData *v14; // rax
  UFG::qResourceData *v15; // rbx
  UFG::qResourceWarehouse *v16; // rax

  v1 = UFG::qStringHash32("UIrasterState_Mask_Clear_SetBit0", 0xFFFFFFFF);
  UFG::gUIrasterState_Mask_Clear_SetBit0_UID = v1;
  v2 = Illusion::Factory::NewRasterState("UIrasterState_Mask_Clear_SetBit0", v1, 0i64, 0i64, 0i64);
  LODWORD(v2[1].mNode.mParent) = 458752;
  HIWORD(v2[1].mNode.mParent) = 1;
  *(_DWORD *)((char *)v2[1].mNode.mChild + 6) = 519;
  WORD2(v2[1].mNode.mChild[0]) = 255;
  BYTE3(v2[1].mNode.mChild[0]) = 1;
  v3 = v2;
  v4 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v4, v3);
  v5 = UFG::qStringHash32("UIrasterState_Mask_Clear_SetBit1", 0xFFFFFFFF);
  UFG::gUIrasterState_Mask_Clear_SetBit1_UID = v5;
  v6 = Illusion::Factory::NewRasterState("UIrasterState_Mask_Clear_SetBit1", v5, 0i64, 0i64, 0i64);
  LODWORD(v6[1].mNode.mParent) = 458752;
  HIWORD(v6[1].mNode.mParent) = 1;
  *(_DWORD *)((char *)v6[1].mNode.mChild + 6) = 519;
  WORD2(v6[1].mNode.mChild[0]) = -1;
  BYTE3(v6[1].mNode.mChild[0]) = 1;
  v7 = v6;
  v8 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v8, v7);
  v9 = UFG::qStringHash32("UIrasterState_Mask_End", 0xFFFFFFFF);
  UFG::gUIrasterState_Mask_End_UID = v9;
  v10 = Illusion::Factory::NewRasterState("UIrasterState_Mask_End", v9, 0i64, 0i64, 0i64);
  LODWORD(v10[1].mNode.mParent) = 458752;
  BYTE6(v10[1].mNode.mParent) = 1;
  *(_DWORD *)((char *)v10[1].mNode.mChild + 6) = 2;
  WORD2(v10[1].mNode.mChild[0]) = -1;
  v11 = v10;
  v12 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v12, v11);
  v13 = UFG::qStringHash32("UIrasterState_Mask_End2", 0xFFFFFFFF);
  UFG::gUIrasterState_Mask2_End_UID = v13;
  v14 = Illusion::Factory::NewRasterState("UIrasterState_Mask_End2", v13, 0i64, 0i64, 0i64);
  LODWORD(v14[1].mNode.mParent) = 458752;
  BYTE6(v14[1].mNode.mParent) = 1;
  *(_DWORD *)((char *)v14[1].mNode.mChild + 6) = 514;
  WORD2(v14[1].mNode.mChild[0]) = -1;
  v15 = v14;
  v16 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v16, v15);
}

// File Line: 2275
// RVA: 0xA2A850
void __fastcall UFG::UIScreenManagerBase::customPreRender(UFG::UIScreenManagerBase *this, Render::View *view)
{
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **v2; // r14
  Render::View *v3; // rsi
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **v4; // rbx
  UFG::UIScreenManagerBase *i; // rdi
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **j; // rbx

  v2 = &this->m_screenStack.mNode.mNext;
  v3 = view;
  v4 = &this->m_screenStack.mNode.mNext[-1].mNext;
  for ( i = this; v4 != (UFG::qNode<UFG::UIScreen,UFG::UIScreen> **)i; v4 = &v4[2][-1].mNext )
    ((void (__fastcall *)(UFG::qNode<UFG::UIScreen,UFG::UIScreen> **, Render::View *))(*v4)[2].mNext)(v4, v3);
  for ( j = &i->m_overlayStack.mNode.mNext[-1].mNext; j != v2; j = &j[2][-1].mNext )
    ((void (__fastcall *)(UFG::qNode<UFG::UIScreen,UFG::UIScreen> **, Render::View *))(*j)[2].mNext)(j, v3);
}

// File Line: 2287
// RVA: 0xA29390
void __usercall UFG::UIScreenManagerBase::advance(UFG::UIScreenManagerBase *this@<rcx>, float elapsed@<xmm1>, __int64 a3@<rdx>, __int64 a4@<r9>, __int64 a5@<r8>)
{
  UFG::UIScreenManagerBase *v5; // rdi
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **v6; // rsi
  UFG::UIScreenManagerBase *v7; // rbx
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v8; // rcx
  signed __int64 i; // rbx
  __int64 v10; // rcx

  v5 = this;
  if ( this->m_renderUI && UFG::gTweakerRenderUI )
  {
    v6 = &this->m_screenStack.mNode.mNext;
    v7 = (UFG::UIScreenManagerBase *)&this->m_screenStack.mNode.mNext[-1].mNext;
    if ( v7 != this )
    {
      do
      {
        v8 = v7->mPendingOverlayLoads.mNode.mPrev;
        if ( LOBYTE(v8[22].mPrev) )
        {
          LOBYTE(a4) = 1;
          ((void (__fastcall *)(UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *, __int64, signed __int64, __int64))v8[20].mPrev->mPrev[12].mPrev)(
            v8[20].mPrev,
            a3,
            2i64,
            a4);
        }
        v7 = (UFG::UIScreenManagerBase *)&v7->m_screenStack.mNode.mNext[-1].mNext;
      }
      while ( v7 != v5 );
    }
    for ( i = (signed __int64)&v5->m_overlayStack.mNode.mNext[-1].mNext;
          (UFG::qNode<UFG::UIScreen,UFG::UIScreen> **)i != v6;
          i = *(_QWORD *)(i + 16) - 8i64 )
    {
      v10 = *(_QWORD *)(i + 96);
      if ( *(_BYTE *)(v10 + 352) )
      {
        LOBYTE(a4) = 1;
        (*(void (__fastcall **)(_QWORD, __int64, signed __int64, __int64))(**(_QWORD **)(v10 + 320) + 192i64))(
          *(_QWORD *)(v10 + 320),
          a3,
          2i64,
          a4);
      }
    }
  }
}

// File Line: 2303
// RVA: 0xA2A7C0
void __fastcall UFG::UIScreenManagerBase::customPostRender(UFG::UIScreenManagerBase *this, Render::View *view)
{
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **v2; // r14
  Render::View *v3; // rsi
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **v4; // rbx
  UFG::UIScreenManagerBase *i; // rdi
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **j; // rbx

  v2 = &this->m_screenStack.mNode.mNext;
  v3 = view;
  v4 = &this->m_screenStack.mNode.mNext[-1].mNext;
  for ( i = this; v4 != (UFG::qNode<UFG::UIScreen,UFG::UIScreen> **)i; v4 = &v4[2][-1].mNext )
    ((void (__fastcall *)(UFG::qNode<UFG::UIScreen,UFG::UIScreen> **, Render::View *))(*v4)[3].mPrev)(v4, v3);
  for ( j = &i->m_overlayStack.mNode.mNext[-1].mNext; j != v2; j = &j[2][-1].mNext )
    ((void (__fastcall *)(UFG::qNode<UFG::UIScreen,UFG::UIScreen> **, Render::View *))(*j)[3].mPrev)(j, v3);
}

// File Line: 2323
// RVA: 0xA32220
void __fastcall UFG::UIScreenManagerBase::shutdownScreen(UFG::UIScreenManagerBase *this, UFG::UIScreen *screen)
{
  UFG::UIScreen *v2; // rsi
  UFG::UIScreenManagerBase *v3; // rdi
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v4; // rcx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v5; // rax

  v2 = screen;
  v3 = this;
  screen->mRenderable->m_movie.pObject->vfptr[28].__vecDelDtor(
    (Scaleform::RefCountImplCore *)screen->mRenderable->m_movie.pObject,
    0);
  EnterCriticalSection(&v3->mScreenStackLock.cs);
  v4 = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)&v2->mPrev;
  v5 = v3->mPendingPoppedScreens.mNode.mPrev;
  v5->mNext = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)&v2->mPrev;
  v4->mPrev = v5;
  v4->mNext = &v3->mPendingPoppedScreens.mNode;
  v3->mPendingPoppedScreens.mNode.mPrev = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)&v2->mPrev;
  LeaveCriticalSection(&v3->mScreenStackLock.cs);
}

// File Line: 2432
// RVA: 0xA2ACF0
void __fastcall UFG::UIScreenManagerBase::dimPreviousScreen(UFG::UIScreenManagerBase *this, UFG::UIScreen::eDimType dimType, UFG::UIScreen *newScreen)
{
  UFG::UIScreen::eDimType v3; // edi
  char *v4; // rbx

  v3 = dimType;
  v4 = (char *)&this->m_screenStack.mNode.mPrev[-1].mNext;
  if ( v4 == (char *)this )
  {
LABEL_4:
    v4 = (char *)&this->m_screenStack.mNode.mPrev[-1].mNext;
  }
  else
  {
    while ( *((_DWORD *)v4 + 29) != newScreen->mControllerMask )
    {
      v4 = (char *)(*((_QWORD *)v4 + 1) - 8i64);
      if ( v4 == (char *)this )
        goto LABEL_4;
    }
  }
  if ( v4 != (char *)this
    && (!(*(unsigned __int8 (__fastcall **)(char *))(*(_QWORD *)v4 + 72i64))(v4)
     || (*(unsigned __int8 (__fastcall **)(char *))(*(_QWORD *)v4 + 80i64))(v4)) )
  {
    (*(void (__fastcall **)(char *, _QWORD, _QWORD))(*(_QWORD *)v4 + 56i64))(v4, (unsigned int)v3, 0i64);
  }
}

// File Line: 2485
// RVA: 0xA31F20
void __fastcall UFG::UIScreenManagerBase::setFontScale(UFG::UIScreenManagerBase *this, float scale)
{
  UFG::UIGfxTranslator *v2; // rcx

  v2 = this->m_translator;
  if ( v2 )
  {
    v2->mFontScale = scale;
    UFG::UIGfxTranslator::createFontMap(v2);
  }
}

