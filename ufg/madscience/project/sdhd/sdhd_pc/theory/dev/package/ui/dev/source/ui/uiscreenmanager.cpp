// File Line: 156
// RVA: 0xA29490
void __fastcall UFG::UIScreenManagerBase::baseInit(UFG::UIScreenManagerBase *this)
{
  char v2; // bl
  UIGfxAllocator *v3; // rax
  Scaleform::GFx::Loader *v4; // r15
  Scaleform::GFx::ZlibSupportBase *v5; // rax
  __int64 v6; // rax
  Scaleform::GFx::Loader *v7; // rax
  UFG::UIGfxFileOpener *v8; // rax
  UFG::UIGfxFileOpener *v9; // rcx
  __int64 v10; // rax
  Scaleform::GFx::Resource *v11; // rbx
  __int64 v12; // rax
  Scaleform::GFx::State *v13; // rbx
  __int64 v14; // rax
  Scaleform::GFx::State *v15; // rbx
  Scaleform::GFx::ImageFileHandlerRegistry *v16; // rax
  Scaleform::GFx::ImageFileHandlerRegistry *v17; // rax
  Scaleform::GFx::ImageFileHandlerRegistry *v18; // r12
  __int64 v19; // rax
  Scaleform::GFx::State *v20; // r14
  Scaleform::GFx::AS3Support *v21; // rax
  Scaleform::GFx::State *v22; // rax
  Scaleform::GFx::State *v23; // r15
  UFG::UIThreadCommandQueue *v24; // rax
  UFG::UIGfxTranslator *v25; // rax
  UFG::UIGfxTranslator *v26; // rax
  UFG::UIGfxTranslator *v27; // r13
  Scaleform::GFx::Loader *m_gfxMovieLoader; // rbx
  Scaleform::GFx::DrawTextManager *v29; // rax
  Scaleform::GFx::DrawTextManager *v30; // rax
  Scaleform::Ptr<Scaleform::GFx::FontProvider> *FontProvider; // rax
  Scaleform::GFx::DrawTextManager::TextParams *DefaultTextParams; // rbx
  Scaleform::GFx::DrawText **m_drawText; // rbx
  __int64 v34; // rdi
  UFG::UIInputHandler *v35; // rax
  UFG::UIInputHandler *v36; // rax
  const char **v37; // rbx
  Scaleform::GFx::DrawTextManager::TextParams params; // [rsp+40h] [rbp-C0h] BYREF
  Scaleform::MemoryHeap::HeapDesc rootHeapDesc; // [rsp+68h] [rbp-98h] BYREF
  Scaleform::GFx::State *v40; // [rsp+A8h] [rbp-58h]
  Scaleform::GFx::State *v41; // [rsp+B0h] [rbp-50h]
  Scaleform::GFx::State *v42; // [rsp+B8h] [rbp-48h]
  Scaleform::GFx::Loader *v43; // [rsp+C0h] [rbp-40h]
  Scaleform::Render::Rect<float> viewRect; // [rsp+D0h] [rbp-30h] BYREF
  Scaleform::GFx::State *v45; // [rsp+E0h] [rbp-20h]
  __int64 v46; // [rsp+E8h] [rbp-18h]
  Scaleform::GFx::ImageFileHandlerRegistry *v47; // [rsp+F0h] [rbp-10h]
  Scaleform::GFx::Resource *v48; // [rsp+F8h] [rbp-8h]
  Scaleform::Ptr<Scaleform::GFx::FileOpenerBase> pfileOpener; // [rsp+158h] [rbp+58h] BYREF
  Scaleform::Ptr<Scaleform::GFx::ZlibSupportBase> pzlib; // [rsp+160h] [rbp+60h] BYREF
  Scaleform::Ptr<Scaleform::GFx::FontProvider> result; // [rsp+168h] [rbp+68h] BYREF

  v46 = -2i64;
  v2 = 0;
  v3 = (UIGfxAllocator *)UFG::qMemoryPool::Allocate(
                           &gScaleformMemoryPool,
                           8ui64,
                           "UIScreenManagerBase::baseInit",
                           0i64,
                           1u);
  if ( v3 )
  {
    v3->vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::SysAllocBase::`vftable;
    v3->vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::SysAlloc::`vftable;
    v3->vfptr = (Scaleform::SysAllocBaseVtbl *)&UIGfxAllocator::`vftable;
  }
  else
  {
    v3 = 0i64;
  }
  this->m_gfxAllocator = v3;
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
                                              24i64,
                                              0i64);
    if ( v5 )
    {
      v5->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
      v5->RefCount = 1;
      v5->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
      v5->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
      v5->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::State,2>::`vftable;
      v5->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::State::`vftable;
      v5->SType = State_Internal_MaskOwner|State_MaskNode|0x10;
      v5->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ZlibSupportBase::`vftable;
      v5->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ZlibSupport::`vftable;
    }
    else
    {
      v5 = 0i64;
    }
    pzlib.pObject = v5;
    v6 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
           Scaleform::Memory::pGlobalHeap,
           24i64);
    if ( v6 )
    {
      *(_QWORD *)v6 = &Scaleform::RefCountImplCore::`vftable;
      *(_DWORD *)(v6 + 8) = 1;
      *(_QWORD *)v6 = &Scaleform::RefCountImpl::`vftable;
      *(_QWORD *)v6 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
      *(_QWORD *)v6 = &Scaleform::RefCountBase<Scaleform::GFx::State,2>::`vftable;
      *(_QWORD *)v6 = &Scaleform::GFx::State::`vftable;
      *(_DWORD *)(v6 + 16) = 12;
      *(_QWORD *)v6 = &Scaleform::GFx::FileOpenerBase::`vftable;
      GFx_Compile_with_SF_BUILD_DEBUG = 0;
      *(_QWORD *)v6 = &Scaleform::GFx::FileOpener::`vftable;
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
  this->m_gfxMovieLoader = v7;
  if ( (v2 & 2) != 0 )
  {
    v2 &= ~2u;
    if ( pfileOpener.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)pfileOpener.pObject);
  }
  if ( (v2 & 1) != 0 && pzlib.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)pzlib.pObject);
  UFG::sUIGfxFileOpener_ThreadID = GetCurrentThreadId();
  v8 = (UFG::UIGfxFileOpener *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(Scaleform::Memory::pGlobalHeap, 32i64, 0i64);
  v9 = v8;
  if ( v8 )
  {
    v8->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
    v8->RefCount = 1;
    v8->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
    v8->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
    v8->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::State,2>::`vftable;
    v8->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::State::`vftable;
    v8->SType = State_OrigScale9Parent|State_MaskNode;
    v8->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::FileOpenerBase::`vftable;
    GFx_Compile_with_SF_BUILD_DEBUG = 0;
    v8->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::FileOpener::`vftable;
    v8->vfptr = (Scaleform::RefCountImplCoreVtbl *)&UFG::UIGfxFileOpener::`vftable;
    v8->mUsingChunkFiles = 0;
  }
  else
  {
    v9 = 0i64;
  }
  this->m_gfxFileOpener = v9;
  v9->vfptr[6].__vecDelDtor(v9, UFG::gUIChunkFiles);
  this->m_gfxMovieLoader->vfptr->SetState(
    this->m_gfxMovieLoader,
    State_OrigScale9Parent|State_MaskNode,
    this->m_gfxFileOpener);
  v10 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
          Scaleform::Memory::pGlobalHeap,
          16i64);
  v11 = (Scaleform::GFx::Resource *)v10;
  if ( v10 )
  {
    *(_QWORD *)v10 = &Scaleform::RefCountImplCore::`vftable;
    *(_DWORD *)(v10 + 8) = 1;
    *(_QWORD *)v10 = &Scaleform::RefCountImpl::`vftable;
    *(_QWORD *)v10 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
    *(_QWORD *)v10 = &Scaleform::RefCountBase<Scaleform::Log,2>::`vftable;
    *(_QWORD *)v10 = &Scaleform::Log::`vftable;
    *(_QWORD *)v10 = &UFG::UIGfxLog::`vftable;
  }
  else
  {
    v11 = 0i64;
  }
  v48 = v11;
  Scaleform::GFx::StateBag::SetLog(this->m_gfxMovieLoader, v11);
  if ( v11 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v11);
  v12 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
          Scaleform::Memory::pGlobalHeap,
          24i64);
  v13 = (Scaleform::GFx::State *)v12;
  if ( v12 )
  {
    *(_QWORD *)v12 = &Scaleform::RefCountImplCore::`vftable;
    *(_DWORD *)(v12 + 8) = 1;
    *(_QWORD *)v12 = &Scaleform::RefCountImpl::`vftable;
    *(_QWORD *)v12 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
    *(_QWORD *)v12 = &Scaleform::RefCountBase<Scaleform::GFx::State,2>::`vftable;
    *(_QWORD *)v12 = &Scaleform::GFx::State::`vftable;
    *(_DWORD *)(v12 + 16) = 5;
    *(_QWORD *)v12 = &Scaleform::GFx::FSCommandHandler::`vftable;
    *(_QWORD *)v12 = &UFG::UIGfxFsCommandHandler::`vftable;
  }
  else
  {
    v13 = 0i64;
  }
  v45 = v13;
  this->m_gfxMovieLoader->vfptr->SetState(this->m_gfxMovieLoader, State_ViewMatrix3D, v13);
  if ( v13 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v13);
  v14 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
          Scaleform::Memory::pGlobalHeap,
          24i64);
  v15 = (Scaleform::GFx::State *)v14;
  if ( v14 )
  {
    *(_QWORD *)v14 = &Scaleform::RefCountImplCore::`vftable;
    *(_DWORD *)(v14 + 8) = 1;
    *(_QWORD *)v14 = &Scaleform::RefCountImpl::`vftable;
    *(_QWORD *)v14 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
    *(_QWORD *)v14 = &Scaleform::RefCountBase<Scaleform::GFx::State,2>::`vftable;
    *(_QWORD *)v14 = &Scaleform::GFx::State::`vftable;
    *(_DWORD *)(v14 + 16) = 6;
    *(_QWORD *)v14 = &Scaleform::GFx::ExternalInterface::`vftable;
    *(_QWORD *)v14 = &UFG::UIGfxExternalInterface::`vftable;
  }
  else
  {
    v15 = 0i64;
  }
  v40 = v15;
  this->m_gfxMovieLoader->vfptr->SetState(this->m_gfxMovieLoader, State_ProjectionMatrix3D, v15);
  if ( v15 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v15);
  v16 = (Scaleform::GFx::ImageFileHandlerRegistry *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                      Scaleform::Memory::pGlobalHeap,
                                                      56i64);
  if ( v16 )
  {
    Scaleform::GFx::ImageFileHandlerRegistry::ImageFileHandlerRegistry(v16, NoInit);
    v18 = v17;
  }
  else
  {
    v18 = 0i64;
  }
  v47 = v18;
  Scaleform::GFx::ImageFileHandlerRegistry::AddHandler(v18, &Scaleform::Render::TGA::FileReader::Instance);
  this->m_gfxMovieLoader->vfptr->SetState(this->m_gfxMovieLoader, State_Type_Count|State_MaskNode, v18);
  v19 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
          Scaleform::Memory::pGlobalHeap,
          24i64);
  v20 = (Scaleform::GFx::State *)v19;
  if ( v19 )
  {
    *(_QWORD *)v19 = &Scaleform::RefCountImplCore::`vftable;
    *(_DWORD *)(v19 + 8) = 1;
    *(_QWORD *)v19 = &Scaleform::RefCountImpl::`vftable;
    *(_QWORD *)v19 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
    *(_QWORD *)v19 = &Scaleform::RefCountBase<Scaleform::GFx::State,2>::`vftable;
    *(_QWORD *)v19 = &Scaleform::GFx::State::`vftable;
    *(_DWORD *)(v19 + 16) = 38;
    *(_QWORD *)v19 = &Scaleform::GFx::ASSupport::`vftable;
    *(_QWORD *)v19 = &Scaleform::GFx::AS2Support::`vftable;
  }
  else
  {
    v20 = 0i64;
  }
  v41 = v20;
  this->m_gfxMovieLoader->vfptr->SetState(this->m_gfxMovieLoader, State_ProjectionMatrix3D|0x20, v20);
  v21 = (Scaleform::GFx::AS3Support *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
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
  this->m_gfxMovieLoader->vfptr->SetState(this->m_gfxMovieLoader, State_UserData|0x20, v23);
  v24 = (UFG::UIThreadCommandQueue *)UFG::qMalloc(0x18ui64, UFG::gGlobalNewName, 0i64);
  if ( v24 )
  {
    v24->vfptr = (Scaleform::Render::ThreadCommandQueueVtbl *)&Scaleform::Render::ThreadCommandQueue::`vftable;
    v24->vfptr = (Scaleform::Render::ThreadCommandQueueVtbl *)&UFG::UIThreadCommandQueue::`vftable;
  }
  else
  {
    v24 = 0i64;
  }
  this->mThreadCommandQueue = v24;
  v25 = (UFG::UIGfxTranslator *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                  Scaleform::Memory::pGlobalHeap,
                                  144i64,
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
  this->m_translator = v27;
  m_gfxMovieLoader = this->m_gfxMovieLoader;
  v27->mScreenFactory = this->m_screenFactory;
  m_gfxMovieLoader->vfptr->SetState(m_gfxMovieLoader, State_BlendMode, v27);
  v27->mGfxLoader = m_gfxMovieLoader;
  UFG::UIGfxTranslator::setLanguage(this->m_translator, eLang_English, 1);
  v29 = (Scaleform::GFx::DrawTextManager *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                             Scaleform::Memory::pGlobalHeap,
                                             40i64);
  if ( v29 )
    Scaleform::GFx::DrawTextManager::DrawTextManager(v29, this->m_gfxMovieLoader);
  else
    v30 = 0i64;
  this->m_gfxDrawTextManager = v30;
  FontProvider = Scaleform::GFx::StateBag::GetFontProvider(this->m_gfxMovieLoader, &result);
  this->m_gfxDrawTextManager->vfptr->SetState(
    &this->m_gfxDrawTextManager->Scaleform::GFx::StateBag,
    State_ProjectionMatrix3D|0x10,
    FontProvider->pObject);
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
  DefaultTextParams = Scaleform::GFx::DrawTextManager::GetDefaultTextParams(this->m_gfxDrawTextManager);
  params.TextColor.Raw = DefaultTextParams->TextColor.Raw;
  params.HAlignment = DefaultTextParams->HAlignment;
  params.VAlignment = DefaultTextParams->VAlignment;
  params.FontStyle = DefaultTextParams->FontStyle;
  params.FontSize = DefaultTextParams->FontSize;
  Scaleform::String::String(&params.FontName, &DefaultTextParams->FontName);
  params.Underline = DefaultTextParams->Underline;
  params.Multiline = DefaultTextParams->Multiline;
  params.WordWrap = DefaultTextParams->WordWrap;
  params.TextColor.Raw = -1;
  Scaleform::String::operator=(&params.FontName, "$TitleFont");
  params.FontSize = FLOAT_24_0;
  Scaleform::GFx::DrawTextManager::SetDefaultTextParams(this->m_gfxDrawTextManager, &params);
  viewRect = 0i64;
  m_drawText = this->m_drawText;
  v34 = 32i64;
  do
  {
    *m_drawText++ = (Scaleform::GFx::DrawText *)Scaleform::GFx::DrawTextManager::CreateHtmlText(
                                                  this->m_gfxDrawTextManager,
                                                  &customCaption,
                                                  &viewRect,
                                                  0i64,
                                                  0xFFFFFFFF);
    --v34;
  }
  while ( v34 );
  UFG::UIScreenManagerBase::initViewport(this, 0i64);
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
  this->m_inputHandler = v36;
  UFG::UIScreenManagerBase::initCustomRendering(this);
  v37 = UFG::gLanguageOverrideNames;
  do
  {
    *v37 = UFG::UILanguages::getLanguageString((UFG::UILanguages::eLanguage)v34);
    LODWORD(v34) = v34 + 1;
    ++v37;
  }
  while ( (int)v34 < 24 );
  if ( !_InterlockedDecrement((volatile signed __int32 *)((params.FontName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( v23 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v23);
  if ( v20 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v20);
  if ( v18 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v18);
}

// File Line: 295
// RVA: 0xA2FF80
void __fastcall UFG::UIScreenManagerBase::initViewport(UFG::UIScreenManagerBase *this, UFG::UIScreen *single_screen)
{
  Illusion::Target *BackBufferTarget; // rax
  int m_targetWidth; // ecx
  int mHeight; // r8d
  float v7; // xmm4_4
  int v8; // esi
  int y; // r14d
  float v10; // xmm5_4
  int width; // ebp
  int height; // r15d
  float v13; // xmm0_4
  Scaleform::GFx::DrawTextManager *m_gfxDrawTextManager; // rcx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **p_mNext; // r12
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **i; // rbx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **j; // rbx
  Scaleform::Render::Viewport vp; // [rsp+40h] [rbp-48h] BYREF

  this->m_targetWidth = Render::GetBackBufferTarget()->mWidth;
  BackBufferTarget = Render::GetBackBufferTarget();
  m_targetWidth = this->m_targetWidth;
  mHeight = BackBufferTarget->mHeight;
  v7 = (float)m_targetWidth;
  this->m_targetHeight = mHeight;
  v8 = 0;
  y = 0;
  v10 = (float)mHeight;
  width = m_targetWidth;
  height = mHeight;
  v13 = (float)m_targetWidth / (float)mHeight;
  if ( v13 <= 5.3333335 )
  {
    if ( v13 > 3.5555556 )
    {
      v8 = m_targetWidth / 3u;
      width = m_targetWidth / 3u;
    }
  }
  else
  {
    width = (int)(float)((float)((float)mHeight * 16.0) * 0.11111111);
    v8 = (unsigned int)(m_targetWidth - width) >> 1;
  }
  if ( !this->mScaleViewportInCode && UFG::gUIViewportScale != 1.0 && UFG::gUIViewportScale > 0.0 )
  {
    width = (int)(float)(v7 * UFG::gUIViewportScale);
    v8 = (int)(float)((float)((float)(1.0 - UFG::gUIViewportScale) * v7) * 0.5);
    height = (int)(float)(v10 * UFG::gUIViewportScale);
    y = (int)(float)((float)(v10 * (float)(1.0 - UFG::gUIViewportScale)) * 0.5);
  }
  if ( single_screen )
  {
    UFG::UIScreenRenderable::setViewport(single_screen->mRenderable, m_targetWidth, mHeight, v8, y, width, height);
  }
  else
  {
    vp.BufferWidth = m_targetWidth;
    m_gfxDrawTextManager = this->m_gfxDrawTextManager;
    vp.BufferHeight = mHeight;
    vp.Left = v8;
    vp.Top = y;
    vp.Width = width;
    vp.Height = height;
    memset(&vp.ScissorLeft, 0, 20);
    Scaleform::GFx::DrawTextManager::SetViewport(m_gfxDrawTextManager, &vp);
    p_mNext = &this->m_screenStack.mNode.mNext;
    for ( i = &this->m_screenStack.mNode.mNext[-1].mNext;
          i != (UFG::qNode<UFG::UIScreen,UFG::UIScreen> **)this;
          i = &i[2][-1].mNext )
    {
      UFG::UIScreenRenderable::setViewport(
        (UFG::UIScreenRenderable *)i[12],
        this->m_targetWidth,
        this->m_targetHeight,
        v8,
        y,
        width,
        height);
    }
    for ( j = &this->m_overlayStack.mNode.mNext[-1].mNext; j != p_mNext; j = &j[2][-1].mNext )
      UFG::UIScreenRenderable::setViewport(
        (UFG::UIScreenRenderable *)j[12],
        this->m_targetWidth,
        this->m_targetHeight,
        v8,
        y,
        width,
        height);
  }
}

// File Line: 362
// RVA: 0xA2BF10
void __fastcall UFG::UIScreenManagerBase::getViewportOffsetAndScale(
        UFG::UIScreenManagerBase *this,
        UFG::qVector2 *offset,
        UFG::qVector2 *scale)
{
  signed int m_targetWidth; // r9d
  signed int m_targetHeight; // r10d
  int v5; // r11d
  int v6; // ebx
  int v7; // edi
  int v8; // esi
  float v9; // xmm1_4
  float v10; // xmm0_4
  float y; // xmm1_4
  float v12; // xmm3_4
  float v13; // xmm1_4

  m_targetWidth = this->m_targetWidth;
  m_targetHeight = this->m_targetHeight;
  v5 = 0;
  v6 = 0;
  v7 = m_targetWidth;
  v8 = m_targetHeight;
  if ( UFG::gUIViewportScale != 1.0 && UFG::gUIViewportScale > 0.0 )
  {
    v5 = (int)(float)((float)((float)m_targetWidth * (float)(1.0 - UFG::gUIViewportScale)) * 0.5);
    v7 = (int)(float)((float)m_targetWidth * UFG::gUIViewportScale);
    v6 = (int)(float)((float)((float)m_targetHeight * (float)(1.0 - UFG::gUIViewportScale)) * 0.5);
    v8 = (int)(float)((float)m_targetHeight * UFG::gUIViewportScale);
  }
  v9 = (float)m_targetWidth / (float)m_targetHeight;
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
        offset->x = (float)((float)m_targetWidth - (float)((float)(1.0 / v12) * (float)m_targetWidth)) * 0.5;
        scale->x = (float)((float)v7 * (float)(1.0 / v12)) / (float)(int)this->m_flashWidth;
        scale->y = (float)v8 / (float)(int)this->m_flashHeight;
        v5 = (int)(float)((float)v5 * v12);
      }
    }
    else
    {
      offset->x = 0.0;
      offset->y = (float)((float)(int)this->m_targetHeight - (float)((float)m_targetHeight * v12)) * 0.5;
      scale->x = (float)v7 / (float)(int)this->m_flashWidth;
      scale->y = (float)((float)v8 * v12) / (float)(int)this->m_flashHeight;
      v6 = (int)(float)((float)v6 * v12);
    }
  }
  else
  {
    y = UFG::qVector2::msZero.y;
    offset->x = UFG::qVector2::msZero.x;
    offset->y = y;
    scale->x = (float)v7 / (float)(int)this->m_flashWidth;
    scale->y = (float)v8 / (float)(int)this->m_flashHeight;
  }
  v13 = (float)v6 + offset->y;
  offset->x = (float)v5 + offset->x;
  offset->y = v13;
}

// File Line: 445
// RVA: 0xA29D10
void __fastcall UFG::UIScreenManagerBase::baseQuit(UFG::UIScreenManagerBase *this)
{
  int *p_mNext; // rax
  int *i; // rbx
  _QWORD *v4; // rdx
  __int64 v5; // rcx
  _QWORD *v6; // rax
  UFG::UIScreenManagerBase *j; // rax
  UFG::qList<UFG::UIScreen,UFG::UIScreen,1,0> *p_m_screenStack; // rdx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *mPrev; // rcx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *mNext; // rax
  UFG::UIScreenManagerBase *k; // rax
  UFG::qList<UFG::UIScreen,UFG::UIScreen,1,0> *v12; // rdx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v13; // rcx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v14; // rax
  UFG::UIScreenManagerBase *m; // rax
  UFG::qList<UFG::UIScreen,UFG::UIScreen,1,0> *v16; // rdx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v17; // rcx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v18; // rax
  UFG::UIScreenManagerBase *n; // rax
  UFG::qList<UFG::UIScreen,UFG::UIScreen,1,0> *v20; // rdx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v21; // rcx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v22; // rax
  UFG::UIScreenManagerBase *ii; // rax
  UFG::qList<UFG::UIScreen,UFG::UIScreen,1,0> *v24; // rdx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v25; // rcx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v26; // rax
  char *m_inputHandler; // rbx
  Scaleform::GFx::Loader *m_gfxMovieLoader; // rcx
  Scaleform::GFx::DrawText **m_drawText; // rax
  __int64 v30; // rcx

  p_mNext = (int *)&this->m_commandQueue.mNode.mNext[-1].mNext;
  for ( i = &this->m_defaultControllerMask; p_mNext != i; p_mNext = (int *)&this->m_commandQueue.mNode.mNext[-1].mNext )
  {
    v4 = p_mNext + 2;
    v5 = *((_QWORD *)p_mNext + 1);
    v6 = (_QWORD *)*((_QWORD *)p_mNext + 2);
    *(_QWORD *)(v5 + 8) = v6;
    *v6 = v5;
    *v4 = v4;
    v4[1] = v4;
    if ( v4 != (_QWORD *)8 )
      (*(void (__fastcall **)(_QWORD *, __int64))*(v4 - 1))(v4 - 1, 1i64);
  }
  for ( j = (UFG::UIScreenManagerBase *)&this->m_screenCommandQueue.mNode.mNext[-1].mNext;
        j != (UFG::UIScreenManagerBase *)&this->m_commandQueue.mNode.mNext;
        j = (UFG::UIScreenManagerBase *)&this->m_screenCommandQueue.mNode.mNext[-1].mNext )
  {
    p_m_screenStack = &j->m_screenStack;
    mPrev = j->m_screenStack.mNode.mPrev;
    mNext = j->m_screenStack.mNode.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_screenStack->mNode.mPrev = &p_m_screenStack->mNode;
    p_m_screenStack->mNode.mNext = &p_m_screenStack->mNode;
    if ( p_m_screenStack != (UFG::qList<UFG::UIScreen,UFG::UIScreen,1,0> *)8 )
      ((void (__fastcall *)(UFG::qNode<UFG::UIScreen,UFG::UIScreen> **, __int64))p_m_screenStack[-1].mNode.mNext->mPrev)(
        &p_m_screenStack[-1].mNode.mNext,
        1i64);
  }
  for ( k = (UFG::UIScreenManagerBase *)&this->m_pendingMessages.mNode.mNext[-1].mNext;
        k != (UFG::UIScreenManagerBase *)&this->m_screenCommandQueue.mNode.mNext;
        k = (UFG::UIScreenManagerBase *)&this->m_pendingMessages.mNode.mNext[-1].mNext )
  {
    v12 = &k->m_screenStack;
    v13 = k->m_screenStack.mNode.mPrev;
    v14 = k->m_screenStack.mNode.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v12->mNode.mPrev = &v12->mNode;
    v12->mNode.mNext = &v12->mNode;
    if ( v12 != (UFG::qList<UFG::UIScreen,UFG::UIScreen,1,0> *)8 )
      ((void (__fastcall *)(UFG::qNode<UFG::UIScreen,UFG::UIScreen> **, __int64))v12[-1].mNode.mNext->mPrev)(
        &v12[-1].mNode.mNext,
        1i64);
  }
  EnterCriticalSection(&this->mScreenStackLock.cs);
  for ( m = (UFG::UIScreenManagerBase *)&this->m_screenStack.mNode.mNext[-1].mNext;
        m != this;
        m = (UFG::UIScreenManagerBase *)&this->m_screenStack.mNode.mNext[-1].mNext )
  {
    v16 = &m->m_screenStack;
    v17 = m->m_screenStack.mNode.mPrev;
    v18 = m->m_screenStack.mNode.mNext;
    v17->mNext = v18;
    v18->mPrev = v17;
    v16->mNode.mPrev = &v16->mNode;
    v16->mNode.mNext = &v16->mNode;
    if ( v16 != (UFG::qList<UFG::UIScreen,UFG::UIScreen,1,0> *)8 )
      ((void (__fastcall *)(UFG::qNode<UFG::UIScreen,UFG::UIScreen> **, __int64))v16[-1].mNode.mNext->mPrev)(
        &v16[-1].mNode.mNext,
        1i64);
  }
  for ( n = (UFG::UIScreenManagerBase *)&this->m_overlayStack.mNode.mNext[-1].mNext;
        n != (UFG::UIScreenManagerBase *)&this->m_screenStack.mNode.mNext;
        n = (UFG::UIScreenManagerBase *)&this->m_overlayStack.mNode.mNext[-1].mNext )
  {
    v20 = &n->m_screenStack;
    v21 = n->m_screenStack.mNode.mPrev;
    v22 = n->m_screenStack.mNode.mNext;
    v21->mNext = v22;
    v22->mPrev = v21;
    v20->mNode.mPrev = &v20->mNode;
    v20->mNode.mNext = &v20->mNode;
    if ( v20 != (UFG::qList<UFG::UIScreen,UFG::UIScreen,1,0> *)8 )
      ((void (__fastcall *)(UFG::qNode<UFG::UIScreen,UFG::UIScreen> **, __int64))v20[-1].mNode.mNext->mPrev)(
        &v20[-1].mNode.mNext,
        1i64);
  }
  for ( ii = (UFG::UIScreenManagerBase *)&this->mPendingPoppedScreens.mNode.mNext[-1].mNext;
        ii != (UFG::UIScreenManagerBase *)&this->mPendingOverlayLoads.mNode.mNext;
        ii = (UFG::UIScreenManagerBase *)&this->mPendingPoppedScreens.mNode.mNext[-1].mNext )
  {
    v24 = &ii->m_screenStack;
    v25 = ii->m_screenStack.mNode.mPrev;
    v26 = ii->m_screenStack.mNode.mNext;
    v25->mNext = v26;
    v26->mPrev = v25;
    v24->mNode.mPrev = &v24->mNode;
    v24->mNode.mNext = &v24->mNode;
    if ( v24 != (UFG::qList<UFG::UIScreen,UFG::UIScreen,1,0> *)8 )
      ((void (__fastcall *)(UFG::qNode<UFG::UIScreen,UFG::UIScreen> **, __int64))v24[-1].mNode.mNext->mPrev)(
        &v24[-1].mNode.mNext,
        1i64);
  }
  LeaveCriticalSection(&this->mScreenStackLock.cs);
  UFG::qList<UFG::InputMessage,UFG::InputMessage,1,0>::DeleteNodes((UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)&this->mPendingScreenLoads);
  UFG::qList<UFG::InputMessage,UFG::InputMessage,1,0>::DeleteNodes((UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)&this->mPendingOverlayLoads);
  m_inputHandler = (char *)this->m_inputHandler;
  if ( m_inputHandler )
  {
    UFG::UIInputHandler::~UIInputHandler(this->m_inputHandler);
    UFG::qMemoryPool::Free(&gScaleformMemoryPool, m_inputHandler);
    this->m_inputHandler = 0i64;
  }
  m_gfxMovieLoader = this->m_gfxMovieLoader;
  if ( m_gfxMovieLoader )
  {
    ((void (__fastcall *)(Scaleform::GFx::Loader *, __int64))m_gfxMovieLoader->vfptr->~StateBag)(m_gfxMovieLoader, 1i64);
    this->m_gfxMovieLoader = 0i64;
  }
  m_drawText = this->m_drawText;
  v30 = 4i64;
  do
  {
    *m_drawText = 0i64;
    m_drawText[1] = 0i64;
    m_drawText[2] = 0i64;
    m_drawText += 8;
    *(m_drawText - 5) = 0i64;
    *(m_drawText - 4) = 0i64;
    *(m_drawText - 3) = 0i64;
    *(m_drawText - 2) = 0i64;
    *(m_drawText - 1) = 0i64;
    --v30;
  }
  while ( v30 );
  Scaleform::RefCountNTSImpl::Release(this->m_gfxDrawTextManager);
  this->m_gfxDrawTextManager = 0i64;
  Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)this->m_gfxFileOpener);
  this->m_gfxFileOpener = 0i64;
  Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)this->m_translator);
  this->m_translator = 0i64;
}

// File Line: 562
// RVA: 0xA25E00
void __fastcall UFG::UIScreenManagerBase::CheckPendingMessages(UFG::UIScreenManagerBase *this, UFG::UIScreen *screen)
{
  unsigned int mScreenUID; // ebp
  Scaleform::GFx::Movie *pObject; // r14
  UFG::qList<UFG::UICommand,UFG::UICommand,1,0> *i; // rdi
  UFG::qNode<UFG::UICommand,UFG::UICommand> *mNext; // rdx
  UFG::qNode<UFG::UICommand,UFG::UICommand> *mPrev; // rcx
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v8; // rax
  __int64 *v9; // rax
  __int64 **v10; // rax
  __int64 **v11; // rsi
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v12; // rdx
  __int64 *v13; // rcx
  __int64 *v14; // rax
  UFG::qNode<UFG::UICommand,UFG::UICommand> **p_mNext; // rax
  int v16; // ecx
  UFG::qList<UFG::UICommand,UFG::UICommand,1,0> *p_m_commandQueue; // rdx
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v18; // rcx
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v19; // rax
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v20; // rax
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v21; // rax
  __int64 **j; // rax
  _QWORD *v23; // rdx
  __int64 *v24; // rcx
  __int64 *v25; // rax
  __int64 *v26; // rcx
  __int64 **v27; // rax
  _QWORD v28[5]; // [rsp+0h] [rbp-58h] BYREF
  __int64 *v29; // [rsp+28h] [rbp-30h] BYREF
  __int64 **v30; // [rsp+30h] [rbp-28h]

  v28[4] = -2i64;
  mScreenUID = screen->mScreenUID;
  pObject = screen->mRenderable->m_movie.pObject;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->m_pendingMessagesMutex);
  v29 = (__int64 *)&v29;
  v30 = &v29;
  for ( i = &this->m_pendingMessages;
        &this->m_pendingMessages.mNode.mNext[-1].mNext != &this->m_screenCommandQueue.mNode.mNext;
        v29 = (__int64 *)mNext )
  {
    mNext = this->m_pendingMessages.mNode.mNext;
    mPrev = mNext->mPrev;
    v8 = mNext->mNext;
    mPrev->mNext = v8;
    v8->mPrev = mPrev;
    mNext->mPrev = mNext;
    mNext->mNext = mNext;
    v9 = v29;
    v29[1] = (__int64)mNext;
    mNext->mPrev = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)v9;
    mNext->mNext = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)&v29;
  }
  v10 = v30 - 1;
  v11 = (__int64 **)&v28[4];
  while ( v30 - 1 != v11 )
  {
    v12 = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)(v10 + 1);
    v13 = v10[1];
    v14 = v10[2];
    v13[1] = (__int64)v14;
    *v14 = (__int64)v13;
    v12->mPrev = v12;
    v12->mNext = v12;
    p_mNext = &v12[-1].mNext;
    if ( LODWORD(v12[2].mNext) != mScreenUID )
    {
      if ( *((_DWORD *)p_mNext + 6) != 7 )
      {
        v21 = i->mNode.mPrev;
        v21->mNext = v12;
        v12->mPrev = v21;
        v12->mNext = &i->mNode;
        i->mNode.mPrev = v12;
        goto LABEL_21;
      }
      if ( pObject != (Scaleform::GFx::Movie *)p_mNext[12] )
      {
        v20 = i->mNode.mPrev;
        v20->mNext = v12;
        v12->mPrev = v20;
        v12->mNext = &i->mNode;
        i->mNode.mPrev = v12;
        goto LABEL_21;
      }
      *((_DWORD *)p_mNext + 12) = mScreenUID;
      if ( !UFG::gTweakerUpdateUI || !this->m_updateUI )
      {
LABEL_13:
        ((void (__fastcall *)(UFG::qNode<UFG::UICommand,UFG::UICommand> **, __int64))(*p_mNext)->mPrev)(p_mNext, 1i64);
        goto LABEL_21;
      }
      p_m_commandQueue = &this->m_commandQueue;
      goto LABEL_12;
    }
    if ( !UFG::gTweakerUpdateUI || !this->m_updateUI )
      goto LABEL_13;
    v16 = *((_DWORD *)p_mNext + 6);
    if ( v16 >= 0 )
    {
      if ( v16 <= 4 )
      {
        p_m_commandQueue = &this->m_screenCommandQueue;
        goto LABEL_12;
      }
      if ( v16 <= 7 )
      {
        p_m_commandQueue = &this->m_commandQueue;
LABEL_12:
        v18 = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)(p_mNext + 1);
        v19 = p_m_commandQueue->mNode.mPrev;
        v19->mNext = v18;
        v18->mPrev = v19;
        v18->mNext = &p_m_commandQueue->mNode;
        p_m_commandQueue->mNode.mPrev = v18;
      }
    }
LABEL_21:
    v10 = v30 - 1;
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->m_pendingMessagesMutex);
  for ( j = v30 - 1; v30 - 1 != v11; j = v30 - 1 )
  {
    v23 = j + 1;
    v24 = j[1];
    v25 = j[2];
    v24[1] = (__int64)v25;
    *v25 = (__int64)v24;
    *v23 = v23;
    v23[1] = v23;
    if ( v23 != (_QWORD *)8 )
      (*(void (__fastcall **)(_QWORD *, __int64))*(v23 - 1))(v23 - 1, 1i64);
  }
  v26 = v29;
  v27 = v30;
  v29[1] = (__int64)v30;
  *v27 = v26;
}

// File Line: 610
// RVA: 0xA328C0
void __fastcall UFG::UIScreenManagerBase::updatePendingLoads(UFG::UIScreenManagerBase *this, float elapsed)
{
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *mNext; // rsi
  UFG::UIScreen *mPrev; // r14
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::RefCountImplCoreVtbl *vfptr; // rdi
  void *CurrentThreadID; // rax
  __int64 v8; // rdx
  __int64 v9; // r9
  int mPrev_high; // eax
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v11; // rcx
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v12; // rdx
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v13; // rcx
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v14; // rax
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v15; // rax
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v16; // rcx
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v17; // rdx
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v18; // rax
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v19; // r15
  UFG::UIScreen *v20; // r12
  Scaleform::GFx::Movie *v21; // rbx
  Scaleform::RefCountImplCoreVtbl *v22; // rdi
  void *v23; // rax
  __int64 v24; // rdx
  __int64 v25; // r9
  int v26; // eax
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v27; // rcx
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v28; // rdx
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v29; // rcx
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v30; // rax
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v31; // rax
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **p_mNext; // r11
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **v33; // rsi
  __int64 v34; // rdi
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v35; // r14
  __int64 v36; // r10
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v37; // rdx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v38; // r8
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v39; // rax
  __int64 v40; // rcx
  _QWORD *v41; // rax
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v42; // rax
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v43; // rax
  __int64 *v44; // r14
  __int64 v45; // r10
  __int64 v46; // rdx
  __int64 *v47; // r8
  _QWORD *v48; // rax
  __int64 v49; // rcx
  _QWORD *v50; // rax
  __int64 **v51; // rax
  __int64 v52; // rax
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v53; // rcx
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v54; // rdx
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v55; // rax
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v56; // rdi
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v57; // r9
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v58; // r8
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v59; // rax

  if ( (UFG::qList<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad,1,0> *)this->mPendingScreenLoads.mNode.mNext != &this->mPendingScreenLoads )
  {
    mNext = this->mPendingScreenLoads.mNode.mNext;
    mPrev = (UFG::UIScreen *)mNext[1].mPrev;
    if ( mPrev->mRenderable->mIsLoaded )
    {
      pObject = mPrev->mRenderable->m_movie.pObject;
      vfptr = pObject->Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr;
      CurrentThreadID = UFG::qGetCurrentThreadID();
      vfptr[27].__vecDelDtor(pObject, (unsigned int)CurrentThreadID);
      mPrev_high = HIDWORD(mNext[2].mPrev);
      if ( mPrev_high <= 0 )
      {
        UFG::UIScreenManagerBase::CheckPendingMessages(this, mPrev);
        v12 = this->mPendingScreenLoads.mNode.mNext;
        v13 = v12->mPrev;
        v14 = v12->mNext;
        v13->mNext = v14;
        v14->mPrev = v13;
        v12->mPrev = v12;
        v12->mNext = v12;
        if ( LOBYTE(mNext[2].mPrev) )
        {
          UFG::UIScreenManagerBase::shutdownScreen(this, (UFG::UIScreen *)mNext[1].mPrev);
        }
        else
        {
          EnterCriticalSection(&this->mScreenStackLock.cs);
          v15 = this->m_screenStack.mNode.mPrev;
          v15->mNext = &mPrev->UFG::qNode<UFG::UIScreen,UFG::UIScreen>;
          mPrev->mPrev = v15;
          mPrev->mNext = &this->m_screenStack.mNode;
          this->m_screenStack.mNode.mPrev = &mPrev->UFG::qNode<UFG::UIScreen,UFG::UIScreen>;
          LeaveCriticalSection(&this->mScreenStackLock.cs);
          UFG::UIScreenManagerBase::initViewport(this, mPrev);
          (*((void (__fastcall **)(UFG::UIScreen *, UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *))&mPrev->vfptr->__vecDelDtor
           + 1))(
            mPrev,
            mNext[1].mNext);
        }
        v16 = mNext[1].mNext;
        if ( v16 )
          ((void (__fastcall *)(UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *, __int64))v16->mPrev->mPrev)(
            v16,
            1i64);
        v17 = mNext->mPrev;
        v18 = mNext->mNext;
        v17->mNext = v18;
        v18->mPrev = v17;
        mNext->mPrev = mNext;
        mNext->mNext = mNext;
        operator delete[](mNext);
      }
      else
      {
        HIDWORD(mNext[2].mPrev) = mPrev_high - 1;
        v11 = mNext[1].mPrev[6].mPrev;
        if ( LOBYTE(v11[22].mPrev) )
        {
          LOBYTE(v9) = 1;
          ((void (__fastcall *)(UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *, __int64, __int64, __int64, __int64))v11[20].mPrev->mPrev[12].mPrev)(
            v11[20].mPrev,
            v8,
            2i64,
            v9,
            -2i64);
        }
      }
    }
  }
  if ( (UFG::qList<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad,1,0> *)this->mPendingOverlayLoads.mNode.mNext != &this->mPendingOverlayLoads )
  {
    v19 = this->mPendingOverlayLoads.mNode.mNext;
    v20 = (UFG::UIScreen *)v19[1].mPrev;
    if ( v20->mRenderable->mIsLoaded )
    {
      v21 = v20->mRenderable->m_movie.pObject;
      v22 = v21->Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr;
      v23 = UFG::qGetCurrentThreadID();
      v22[27].__vecDelDtor(v21, (unsigned int)v23);
      v26 = HIDWORD(v19[2].mPrev);
      if ( v26 <= 0 )
      {
        UFG::UIScreenManagerBase::CheckPendingMessages(this, v20);
        v28 = this->mPendingOverlayLoads.mNode.mNext;
        v29 = v28->mPrev;
        v30 = v28->mNext;
        v29->mNext = v30;
        v30->mPrev = v29;
        v28->mPrev = v28;
        v28->mNext = v28;
        if ( LOBYTE(v19[2].mPrev) )
        {
          UFG::UIScreenManagerBase::shutdownScreen(this, (UFG::UIScreen *)v19[1].mPrev);
        }
        else
        {
          EnterCriticalSection(&this->mScreenStackLock.cs);
          v31 = this->m_overlayStack.mNode.mPrev;
          v31->mNext = &v20->UFG::qNode<UFG::UIScreen,UFG::UIScreen>;
          v20->mPrev = v31;
          v20->mNext = &this->m_overlayStack.mNode;
          this->m_overlayStack.mNode.mPrev = &v20->UFG::qNode<UFG::UIScreen,UFG::UIScreen>;
          p_mNext = &this->m_overlayStack.mNode.mNext[-1].mNext;
          v33 = &this->m_screenStack.mNode.mNext;
          do
          {
            v34 = 0i64;
            while ( p_mNext != v33 )
            {
              v35 = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)(p_mNext + 1);
              v36 = (__int64)&p_mNext[2][-1].mNext;
              if ( (UFG::qNode<UFG::UIScreen,UFG::UIScreen> **)v36 == v33 )
                break;
              if ( *((_DWORD *)p_mNext + 31) <= *(_DWORD *)(v36 + 124) )
              {
                p_mNext = &p_mNext[2][-1].mNext;
              }
              else
              {
                v37 = v35->mPrev;
                v38 = *(UFG::qNode<UFG::UIScreen,UFG::UIScreen> **)(v36 + 16);
                v39 = p_mNext[2];
                v37->mNext = v39;
                v39->mPrev = v37;
                v35->mPrev = v35;
                p_mNext[2] = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)(p_mNext + 1);
                v40 = *(_QWORD *)(v36 + 8);
                v41 = *(_QWORD **)(v36 + 16);
                *(_QWORD *)(v40 + 8) = v41;
                *v41 = v40;
                *(_QWORD *)(v36 + 8) = v36 + 8;
                *(_QWORD *)(v36 + 16) = v36 + 8;
                v42 = v37->mNext;
                v37->mNext = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)(v36 + 8);
                *(_QWORD *)(v36 + 8) = v37;
                *(_QWORD *)(v36 + 16) = v42;
                v42->mPrev = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)(v36 + 8);
                v43 = v38->mPrev;
                v43->mNext = v35;
                v35->mPrev = v43;
                p_mNext[2] = v38;
                v38->mPrev = v35;
                v34 = v36;
              }
            }
            p_mNext = 0i64;
            if ( !v34 || (UFG::qNode<UFG::UIScreen,UFG::UIScreen> **)v34 == v33 )
              break;
            do
            {
              v44 = (__int64 *)(v34 + 8);
              v45 = *(_QWORD *)(v34 + 8) - 8i64;
              if ( (UFG::qNode<UFG::UIScreen,UFG::UIScreen> **)v45 == v33 )
                break;
              if ( *(_DWORD *)(v45 + 124) <= *(_DWORD *)(v34 + 124) )
              {
                v34 = *(_QWORD *)(v34 + 8) - 8i64;
              }
              else
              {
                v46 = **(_QWORD **)(v34 + 8);
                v47 = *(__int64 **)(v34 + 16);
                v48 = *(_QWORD **)(v45 + 16);
                *(_QWORD *)(v46 + 8) = v48;
                *v48 = v46;
                *(_QWORD *)(v45 + 8) = v45 + 8;
                *(_QWORD *)(v45 + 16) = v45 + 8;
                v49 = *v44;
                v50 = *(_QWORD **)(v34 + 16);
                *(_QWORD *)(v49 + 8) = v50;
                *v50 = v49;
                *v44 = (__int64)v44;
                *(_QWORD *)(v34 + 16) = v34 + 8;
                v51 = *(__int64 ***)(v46 + 8);
                *(_QWORD *)(v46 + 8) = v44;
                *v44 = v46;
                *(_QWORD *)(v34 + 16) = v51;
                *v51 = v44;
                v52 = *v47;
                *(_QWORD *)(v52 + 8) = v45 + 8;
                *(_QWORD *)(v45 + 8) = v52;
                *(_QWORD *)(v45 + 16) = v47;
                *v47 = v45 + 8;
                p_mNext = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> **)v45;
              }
            }
            while ( (UFG::qNode<UFG::UIScreen,UFG::UIScreen> **)v34 != v33 );
          }
          while ( p_mNext );
          LeaveCriticalSection(&this->mScreenStackLock.cs);
          UFG::UIScreenManagerBase::initViewport(this, 0i64);
          (*((void (__fastcall **)(UFG::UIScreen *, UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *))&v20->vfptr->__vecDelDtor
           + 1))(
            v20,
            v19[1].mNext);
        }
        v53 = v19[1].mNext;
        if ( v53 )
          ((void (__fastcall *)(UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *, __int64))v53->mPrev->mPrev)(
            v53,
            1i64);
        v54 = v19->mPrev;
        v55 = v19->mNext;
        v54->mNext = v55;
        v55->mPrev = v54;
        v19->mPrev = v19;
        v19->mNext = v19;
        operator delete[](v19);
      }
      else
      {
        HIDWORD(v19[2].mPrev) = v26 - 1;
        v27 = v19[1].mPrev[6].mPrev;
        if ( LOBYTE(v27[22].mPrev) )
        {
          LOBYTE(v25) = 1;
          ((void (__fastcall *)(UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *, __int64, __int64, __int64))v27[20].mPrev->mPrev[12].mPrev)(
            v27[20].mPrev,
            v24,
            2i64,
            v25);
        }
      }
    }
  }
  if ( (UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> **)&this->mPendingPoppedScreens.mNode.mNext[-1].mNext != &this->mPendingOverlayLoads.mNode.mNext )
  {
    v56 = this->mPendingPoppedScreens.mNode.mNext;
    if ( ((__int64 (__fastcall *)(UFG::qNode<UFG::UIScreen,UFG::UIScreen> *))v56[5].mNext[20].mPrev->mPrev[14].mNext)(v56[5].mNext[20].mPrev) )
    {
      EnterCriticalSection(&this->mScreenStackLock.cs);
      v57 = this->mPendingPoppedScreens.mNode.mNext;
      v58 = v57->mPrev;
      v59 = v57->mNext;
      v58->mNext = v59;
      v59->mPrev = v58;
      v57->mPrev = v57;
      v57->mNext = v57;
      LeaveCriticalSection(&this->mScreenStackLock.cs);
      ((void (__fastcall *)(UFG::qNode<UFG::UIScreen,UFG::UIScreen> **, __int64))v56[-1].mNext->mPrev)(
        &v56[-1].mNext,
        1i64);
    }
  }
}

// File Line: 718
// RVA: 0xA331D0
void __fastcall UFG::UIScreenManagerBase::updateScreenStack(UFG::UIScreenManagerBase *this, float elapsed)
{
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **p_mNext; // rsi
  UFG::UIScreenManagerBase *i; // rbx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **j; // rbx

  if ( this->m_renderUI && UFG::gTweakerRenderUI )
  {
    p_mNext = &this->m_screenStack.mNode.mNext;
    for ( i = (UFG::UIScreenManagerBase *)&this->m_screenStack.mNode.mNext[-1].mNext;
          i != this;
          i = (UFG::UIScreenManagerBase *)&i->m_screenStack.mNode.mNext[-1].mNext )
    {
      i->vfptr->isInputEnabled(i);
    }
    for ( j = &this->m_overlayStack.mNode.mNext[-1].mNext; j != p_mNext; j = &j[2][-1].mNext )
      ((void (__fastcall *)(UFG::qNode<UFG::UIScreen,UFG::UIScreen> **))(*j)[1].mNext)(j);
  }
}

// File Line: 785
// RVA: 0xA2A040
void __fastcall UFG::UIScreenManagerBase::baseUpdate(UFG::UIScreenManagerBase *this, float elapsed)
{
  float v2; // xmm7_4
  AMD_HD3D *v4; // rcx
  float v5; // xmm0_4
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **p_mNext; // rsi
  UFG::UIScreen *i; // rbx
  UFG::UIScreen *j; // rbx
  UFG::UIFlowRoot *v9; // rcx
  UFG::allocator::free_link *v10; // rax
  UFG::qNode<UFG::UITween,UFG::UITween> *mNext; // rsi
  UFG::UIScreenManagerBase *v12; // rbp
  UFG::allocator::free_link *v13; // rax
  UFG::allocator::free_link *v14; // r14
  int mPrev_high; // ebx
  int mPrev; // xmm6_4
  const char *v17; // rdx
  UFG::qNode<UFG::UITween,UFG::UITween> *v18; // rcx
  UFG::allocator::free_link *v19; // rax
  UFG::qNode<UFG::UITween,UFG::UITween> *v20; // rdx
  UFG::qNode<UFG::UITween,UFG::UITween> *v21; // rax

  v2 = elapsed;
  if ( this->m_targetWidth != Render::GetBackBufferTarget()->mWidth
    || this->m_targetHeight != Render::GetBackBufferTarget()->mHeight
    || lastViewportScale != UFG::gUIViewportScale )
  {
    UFG::UIScreenManagerBase::initViewport(this, 0i64);
    v5 = UFG::gUIViewportScale;
    lastViewportScale = UFG::gUIViewportScale;
    if ( this->mScaleViewportInCode )
    {
      p_mNext = &this->m_screenStack.mNode.mNext;
      for ( i = (UFG::UIScreen *)&this->m_screenStack.mNode.mNext[-1].mNext;
            i != (UFG::UIScreen *)this;
            i = (UFG::UIScreen *)&i->mNext[-1].mNext )
      {
        UFG::UIScreen::updateViewportScale(i, v5);
      }
      for ( j = (UFG::UIScreen *)&this->m_overlayStack.mNode.mNext[-1].mNext;
            j != (UFG::UIScreen *)p_mNext;
            j = (UFG::UIScreen *)&j->mNext[-1].mNext )
      {
        UFG::UIScreen::updateViewportScale(j, v5);
      }
    }
  }
  if ( elapsed > 1.0 )
    v2 = *(float *)&FLOAT_1_0;
  _(v4);
  if ( UFG::gTweakerUpdateUI && this->m_updateUI )
  {
    if ( this->vfptr->isInputEnabled(this) )
      UFG::UIInputHandler::handleInput(this->m_inputHandler, v2);
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
        v10->mNext = (UFG::allocator::free_link *)&UFG::UIFlow::`vftable;
        LODWORD(v10[1].mNext) = -1;
        v10[2].mNext = 0i64;
        v10[3].mNext = 0i64;
        v10->mNext = (UFG::allocator::free_link *)&UFG::UIFlowRoot::`vftable;
      }
      else
      {
        v10 = 0i64;
      }
      UFG::LazyInitGet<UFG::UIFlowRoot>::m_instance = (UFG::UIFlowRoot *)v10;
      v9 = (UFG::UIFlowRoot *)v10;
    }
    ((void (__fastcall *)(UFG::UIFlowRoot *))v9->vfptr->flowUpdate)(v9);
    mNext = this->m_activeTweens.mNode.mNext;
    if ( mNext != (UFG::qNode<UFG::UITween,UFG::UITween> *)&this->m_activeTweens )
    {
      do
      {
        v12 = (UFG::UIScreenManagerBase *)mNext->mNext;
        if ( UFG::UITween::Update((UFG::UITween *)mNext, v2) >= 1.0 )
        {
          v13 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x70ui64, "UICommand", 0i64, 1u);
          v14 = v13;
          if ( v13 )
          {
            mPrev_high = HIDWORD(mNext[4].mPrev);
            mPrev = (int)mNext[4].mPrev;
            v17 = (const char *)mNext[3].mPrev;
            v18 = mNext[1].mPrev;
            v19 = v13 + 1;
            v19->mNext = v19;
            v19[1].mNext = v19;
            v14->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
            LODWORD(v14[3].mNext) = -1;
            v14[4].mNext = 0i64;
            v14->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
            LODWORD(v14[5].mNext) = UI_HASH_TWEEN_COMPLETE_35;
            HIDWORD(v14[5].mNext) = 0;
            v14[6].mNext = (UFG::allocator::free_link *)-1i64;
            LODWORD(v14[3].mNext) = 5;
            v14->mNext = (UFG::allocator::free_link *)&UFG::UIMessageTweenComplete::`vftable;
            v14[7].mNext = (UFG::allocator::free_link *)v18;
            UFG::qString::qString((UFG::qString *)&v14[8], v17);
            LODWORD(v14[13].mNext) = mPrev;
            HIDWORD(v14[13].mNext) = mPrev_high;
          }
          else
          {
            v14 = 0i64;
          }
          UFG::UIScreenManagerBase::queueMessageEx(this, (UFG::UIMessage *)v14);
          v20 = mNext->mPrev;
          v21 = mNext->mNext;
          v20->mNext = v21;
          v21->mPrev = v20;
          mNext->mPrev = mNext;
          mNext->mNext = mNext;
          UFG::UITween::~UITween((UFG::UITween *)mNext);
          operator delete[](mNext);
        }
        mNext = (UFG::qNode<UFG::UITween,UFG::UITween> *)v12;
      }
      while ( v12 != (UFG::UIScreenManagerBase *)&this->m_activeTweens );
    }
    UFG::UIScreenManagerBase::updatePendingLoads(this, v2);
    UFG::UIScreenManagerBase::updateCommandQueue(this, v2);
    UFG::UIScreenManagerBase::updateScreenCommandQueue(this, v2);
    UFG::UIScreenManagerBase::updateScreenStack(this, v2);
    Scaleform::GFx::DrawTextManager::Capture(this->m_gfxDrawTextManager, 1);
    UFG::UIScreenManagerBase::debugRender(this);
  }
}

// File Line: 900
// RVA: 0xA31820
UFG::UICommand *__fastcall UFG::UIScreenManagerBase::queuePushScreen(
        UFG::UIScreenManagerBase *this,
        char *fileName,
        int controllerMask)
{
  UFG::allocator::free_link *v6; // rax
  __int64 v7; // rax
  __int64 v8; // rbx
  int v9; // eax
  UFG::qList<UFG::UICommand,UFG::UICommand,1,0> *p_m_screenCommandQueue; // rdx
  UFG::qNode<UFG::UICommand,UFG::UICommand> *mPrev; // rax

  v6 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0xC0ui64, "UIScreenManagerBase::UICommandScreenPush", 0i64, 1u);
  if ( v6 )
  {
    UFG::UICommandScreenPush::UICommandScreenPush(
      (UFG::UICommandScreenPush *)v6,
      fileName,
      this->mScreenUIDCounter,
      controllerMask);
    v8 = v7;
  }
  else
  {
    v8 = 0i64;
  }
  if ( UFG::gTweakerUpdateUI && this->m_updateUI )
  {
    v9 = *(_DWORD *)(v8 + 24);
    if ( v9 >= 0 )
    {
      if ( v9 <= 4 )
      {
        p_m_screenCommandQueue = &this->m_screenCommandQueue;
        goto LABEL_11;
      }
      if ( v9 <= 7 )
      {
        p_m_screenCommandQueue = &this->m_commandQueue;
LABEL_11:
        mPrev = p_m_screenCommandQueue->mNode.mPrev;
        mPrev->mNext = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)(v8 + 8);
        *(_QWORD *)(v8 + 8) = mPrev;
        *(_QWORD *)(v8 + 16) = p_m_screenCommandQueue;
        p_m_screenCommandQueue->mNode.mPrev = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)(v8 + 8);
      }
    }
  }
  else if ( v8 )
  {
    (**(void (__fastcall ***)(__int64, __int64))v8)(v8, 1i64);
  }
  ++this->mScreenUIDCounter;
  return (UFG::UICommand *)v8;
}

// File Line: 920
// RVA: 0xA31600
UFG::allocator::free_link *__fastcall UFG::UIScreenManagerBase::queuePopScreen(
        UFG::UIScreenManagerBase *this,
        unsigned int screenUID)
{
  UFG::allocator::free_link *v4; // rax
  UFG::allocator::free_link *v5; // rbx
  UFG::allocator::free_link *v6; // rax
  int mNext; // eax
  bool v8; // cc
  UFG::allocator::free_link *result; // rax
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v10; // rcx
  UFG::qNode<UFG::UICommand,UFG::UICommand> *mPrev; // rax

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
    v5->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
    LODWORD(v5[3].mNext) = -1;
    v5[4].mNext = 0i64;
    v5->mNext = (UFG::allocator::free_link *)&UFG::UICommandScreenPop::`vftable;
    LODWORD(v5[3].mNext) = 1;
    LOBYTE(v5[5].mNext) = 0;
    HIDWORD(v5[5].mNext) = screenUID;
  }
  else
  {
    v5 = 0i64;
  }
  if ( !UFG::gTweakerUpdateUI || !this->m_updateUI )
  {
    if ( v5 )
      ((void (__fastcall *)(UFG::allocator::free_link *, __int64))v5->mNext->mNext)(v5, 1i64);
    return v5;
  }
  mNext = (int)v5[3].mNext;
  if ( mNext < 0 )
    return v5;
  if ( mNext <= 4 )
  {
    mPrev = this->m_screenCommandQueue.mNode.mPrev;
    mPrev->mNext = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)&v5[1];
    v5[1].mNext = (UFG::allocator::free_link *)mPrev;
    v5[2].mNext = (UFG::allocator::free_link *)&this->m_screenCommandQueue;
    this->m_screenCommandQueue.mNode.mPrev = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)&v5[1];
    return v5;
  }
  v8 = mNext <= 7;
  result = v5;
  if ( v8 )
  {
    v10 = this->m_commandQueue.mNode.mPrev;
    v10->mNext = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)&v5[1];
    v5[1].mNext = (UFG::allocator::free_link *)v10;
    v5[2].mNext = (UFG::allocator::free_link *)&this->m_commandQueue;
    this->m_commandQueue.mNode.mPrev = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)&v5[1];
  }
  return result;
}

// File Line: 933
// RVA: 0xA31300
UFG::allocator::free_link *__fastcall UFG::UIScreenManagerBase::queuePopAllScreens(UFG::UIScreenManagerBase *this)
{
  UFG::allocator::free_link *v2; // rax
  UFG::allocator::free_link *v3; // rbx
  UFG::allocator::free_link *v4; // rax
  int mNext; // eax
  bool v6; // cc
  UFG::allocator::free_link *result; // rax
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v8; // rcx
  UFG::qNode<UFG::UICommand,UFG::UICommand> *mPrev; // rax

  v2 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x30ui64, "UIScreenManagerBase::UICommandScreenPop", 0i64, 1u);
  v3 = v2;
  if ( v2 )
  {
    v4 = v2 + 1;
    v4->mNext = v4;
    v4[1].mNext = v4;
    v3->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
    LODWORD(v3[3].mNext) = -1;
    v3[4].mNext = 0i64;
    v3->mNext = (UFG::allocator::free_link *)&UFG::UICommandScreenPop::`vftable;
    LODWORD(v3[3].mNext) = 1;
    LOBYTE(v3[5].mNext) = 1;
    HIDWORD(v3[5].mNext) = -1;
  }
  else
  {
    v3 = 0i64;
  }
  if ( !UFG::gTweakerUpdateUI || !this->m_updateUI )
  {
    if ( v3 )
      ((void (__fastcall *)(UFG::allocator::free_link *, __int64))v3->mNext->mNext)(v3, 1i64);
    return v3;
  }
  mNext = (int)v3[3].mNext;
  if ( mNext < 0 )
    return v3;
  if ( mNext <= 4 )
  {
    mPrev = this->m_screenCommandQueue.mNode.mPrev;
    mPrev->mNext = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)&v3[1];
    v3[1].mNext = (UFG::allocator::free_link *)mPrev;
    v3[2].mNext = (UFG::allocator::free_link *)&this->m_screenCommandQueue;
    this->m_screenCommandQueue.mNode.mPrev = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)&v3[1];
    return v3;
  }
  v6 = mNext <= 7;
  result = v3;
  if ( v6 )
  {
    v8 = this->m_commandQueue.mNode.mPrev;
    v8->mNext = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)&v3[1];
    v3[1].mNext = (UFG::allocator::free_link *)v8;
    v3[2].mNext = (UFG::allocator::free_link *)&this->m_commandQueue;
    this->m_commandQueue.mNode.mPrev = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)&v3[1];
  }
  return result;
}

// File Line: 990
// RVA: 0xA31720
UFG::UICommand *__fastcall UFG::UIScreenManagerBase::queuePushOverlay(
        UFG::UIScreenManagerBase *this,
        char *fileName,
        unsigned int priority,
        int controllerMask)
{
  UFG::allocator::free_link *v8; // rax
  __int64 v9; // rax
  __int64 v10; // rbx
  int v11; // eax
  UFG::qList<UFG::UICommand,UFG::UICommand,1,0> *p_m_screenCommandQueue; // rdx
  UFG::qNode<UFG::UICommand,UFG::UICommand> *mPrev; // rax

  v8 = UFG::qMemoryPool::Allocate(
         &gScaleformMemoryPool,
         0xC0ui64,
         "UIScreenManagerBase::UICommandOverlayPush",
         0i64,
         1u);
  if ( v8 )
  {
    UFG::UICommandOverlayPush::UICommandOverlayPush(
      (UFG::UICommandOverlayPush *)v8,
      fileName,
      this->mScreenUIDCounter,
      priority,
      controllerMask);
    v10 = v9;
  }
  else
  {
    v10 = 0i64;
  }
  if ( UFG::gTweakerUpdateUI && this->m_updateUI )
  {
    v11 = *(_DWORD *)(v10 + 24);
    if ( v11 >= 0 )
    {
      if ( v11 <= 4 )
      {
        p_m_screenCommandQueue = &this->m_screenCommandQueue;
        goto LABEL_11;
      }
      if ( v11 <= 7 )
      {
        p_m_screenCommandQueue = &this->m_commandQueue;
LABEL_11:
        mPrev = p_m_screenCommandQueue->mNode.mPrev;
        mPrev->mNext = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)(v10 + 8);
        *(_QWORD *)(v10 + 8) = mPrev;
        *(_QWORD *)(v10 + 16) = p_m_screenCommandQueue;
        p_m_screenCommandQueue->mNode.mPrev = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)(v10 + 8);
      }
    }
  }
  else if ( v10 )
  {
    (**(void (__fastcall ***)(__int64, __int64))v10)(v10, 1i64);
  }
  ++this->mScreenUIDCounter;
  return (UFG::UICommand *)v10;
}

// File Line: 1008
// RVA: 0xA31530
UFG::UICommand *__fastcall UFG::UIScreenManagerBase::queuePopOverlay(UFG::UIScreenManagerBase *this, char *fileName)
{
  UFG::allocator::free_link *v4; // rax
  __int64 v5; // rax
  __int64 v6; // rbx
  int v7; // eax
  UFG::qList<UFG::UICommand,UFG::UICommand,1,0> *p_m_screenCommandQueue; // rdx
  UFG::qNode<UFG::UICommand,UFG::UICommand> *mPrev; // rax

  v4 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0xB0ui64, "UIScreenManagerBase::UICommandOverlayPop", 0i64, 1u);
  if ( v4 )
  {
    UFG::UICommandOverlayPop::UICommandOverlayPop((UFG::UICommandOverlayPop *)v4, fileName);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  if ( UFG::gTweakerUpdateUI && this->m_updateUI )
  {
    v7 = *(_DWORD *)(v6 + 24);
    if ( v7 >= 0 )
    {
      if ( v7 <= 4 )
      {
        p_m_screenCommandQueue = &this->m_screenCommandQueue;
        goto LABEL_10;
      }
      if ( v7 <= 7 )
      {
        p_m_screenCommandQueue = &this->m_commandQueue;
LABEL_10:
        mPrev = p_m_screenCommandQueue->mNode.mPrev;
        mPrev->mNext = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)(v6 + 8);
        *(_QWORD *)(v6 + 8) = mPrev;
        *(_QWORD *)(v6 + 16) = p_m_screenCommandQueue;
        p_m_screenCommandQueue->mNode.mPrev = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)(v6 + 8);
      }
    }
  }
  else if ( v6 )
  {
    (**(void (__fastcall ***)(__int64, __int64))v6)(v6, 1i64);
  }
  return (UFG::UICommand *)v6;
}

// File Line: 1024
// RVA: 0xA31410
UFG::allocator::free_link *__fastcall UFG::UIScreenManagerBase::queuePopOverlay(
        UFG::UIScreenManagerBase *this,
        unsigned int screenUID)
{
  UFG::allocator::free_link *v4; // rax
  UFG::allocator::free_link *v5; // rbx
  UFG::allocator::free_link *v6; // rax
  int mNext; // eax
  bool v8; // cc
  UFG::allocator::free_link *result; // rax
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v10; // rcx
  UFG::qNode<UFG::UICommand,UFG::UICommand> *mPrev; // rax

  v4 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0xB0ui64, "UIScreenManagerBase::UICommandOverlayPop", 0i64, 1u);
  v5 = v4;
  if ( v4 )
  {
    v6 = v4 + 1;
    v6->mNext = v6;
    v6[1].mNext = v6;
    v5->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
    LODWORD(v5[3].mNext) = -1;
    v5[4].mNext = 0i64;
    v5->mNext = (UFG::allocator::free_link *)&UFG::UICommandOverlayPop::`vftable;
    LODWORD(v5[5].mNext) = screenUID;
    BYTE4(v5[5].mNext) = 0;
    LODWORD(v5[3].mNext) = 4;
  }
  else
  {
    v5 = 0i64;
  }
  if ( !UFG::gTweakerUpdateUI || !this->m_updateUI )
  {
    if ( v5 )
      ((void (__fastcall *)(UFG::allocator::free_link *, __int64))v5->mNext->mNext)(v5, 1i64);
    return v5;
  }
  mNext = (int)v5[3].mNext;
  if ( mNext < 0 )
    return v5;
  if ( mNext <= 4 )
  {
    mPrev = this->m_screenCommandQueue.mNode.mPrev;
    mPrev->mNext = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)&v5[1];
    v5[1].mNext = (UFG::allocator::free_link *)mPrev;
    v5[2].mNext = (UFG::allocator::free_link *)&this->m_screenCommandQueue;
    this->m_screenCommandQueue.mNode.mPrev = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)&v5[1];
    return v5;
  }
  v8 = mNext <= 7;
  result = v5;
  if ( v8 )
  {
    v10 = this->m_commandQueue.mNode.mPrev;
    v10->mNext = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)&v5[1];
    v5[1].mNext = (UFG::allocator::free_link *)v10;
    v5[2].mNext = (UFG::allocator::free_link *)&this->m_commandQueue;
    this->m_commandQueue.mNode.mPrev = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)&v5[1];
  }
  return result;
}

// File Line: 1041
// RVA: 0xA30FE0
UFG::allocator::free_link *__fastcall UFG::UIScreenManagerBase::queueMessage(
        UFG::UIScreenManagerBase *this,
        unsigned int messageId,
        unsigned int receiverUID)
{
  UFG::allocator::free_link *v6; // rax
  UFG::allocator::free_link *v7; // rbx
  UFG::allocator::free_link *v8; // rax

  v6 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x38ui64, "UIScreenManagerBase::UIMessage", 0i64, 1u);
  v7 = v6;
  if ( v6 )
  {
    v8 = v6 + 1;
    v8->mNext = v8;
    v8[1].mNext = v8;
    v7->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
    LODWORD(v7[3].mNext) = -1;
    v7[4].mNext = 0i64;
    v7->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
    LODWORD(v7[5].mNext) = messageId;
    HIDWORD(v7[5].mNext) = 0;
    LODWORD(v7[6].mNext) = receiverUID;
    LODWORD(v7[3].mNext) = 5;
    HIDWORD(v7[6].mNext) = -1;
  }
  else
  {
    v7 = 0i64;
  }
  UFG::UIScreenManagerBase::queueMessageEx(this, (UFG::UIMessage *)v7);
  return v7;
}

// File Line: 1056
// RVA: 0xA310B0
UFG::UIMessage *__fastcall UFG::UIScreenManagerBase::queueMessageEx(
        UFG::UIScreenManagerBase *this,
        UFG::UIMessage *message)
{
  unsigned int m_receiverUID; // r9d
  char v3; // r8
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *mNext; // rdx
  UFG::qList<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad,1,0> *p_mPendingScreenLoads; // rcx
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *mPrev; // rax
  UFG::UIScreenManagerBase *v9; // rdx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v10; // rax
  UFG::qNode<UFG::UICommand,UFG::UICommand> **i; // rcx
  int v12; // eax
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v13; // rax
  __int64 v15; // rdx
  char *p_mNext; // rax
  __int64 v17; // rcx
  __int64 v18; // rcx
  UFG::UICommand::UICommandType m_commandType; // eax
  UFG::qList<UFG::UICommand,UFG::UICommand,1,0> *p_m_screenCommandQueue; // rdx
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v21; // rax

  m_receiverUID = message->m_receiverUID;
  v3 = 0;
  if ( m_receiverUID == -1 )
  {
    if ( message->m_commandType == UICOMMAND_FLASH_COMMAND )
    {
      v15 = *(_QWORD *)&message[1].m_messageId;
      p_mNext = (char *)&this->m_screenStack.mNode.mNext[-1].mNext;
      if ( p_mNext == (char *)this )
      {
LABEL_30:
        p_mNext = (char *)&this->m_overlayStack.mNode.mNext[-1].mNext;
        if ( p_mNext == (char *)&this->m_screenStack.mNode.mNext )
          goto LABEL_22;
        while ( 1 )
        {
          v18 = *((_QWORD *)p_mNext + 12);
          if ( v18 )
          {
            if ( *(_QWORD *)(v18 + 320) == v15 )
              break;
          }
          p_mNext = (char *)(*((_QWORD *)p_mNext + 2) - 8i64);
          if ( p_mNext == (char *)&this->m_screenStack.mNode.mNext )
            goto LABEL_22;
        }
      }
      else
      {
        while ( 1 )
        {
          v17 = *((_QWORD *)p_mNext + 12);
          if ( v17 )
          {
            if ( *(_QWORD *)(v17 + 320) == v15 )
              break;
          }
          p_mNext = (char *)(*((_QWORD *)p_mNext + 2) - 8i64);
          if ( p_mNext == (char *)this )
            goto LABEL_30;
        }
      }
      message->m_receiverUID = *((_DWORD *)p_mNext + 28);
    }
  }
  else
  {
    mNext = this->mPendingScreenLoads.mNode.mNext;
    p_mPendingScreenLoads = &this->mPendingScreenLoads;
    while ( mNext != (UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *)p_mPendingScreenLoads )
    {
      mPrev = mNext[1].mPrev;
      mNext = mNext->mNext;
      if ( LODWORD(mPrev[7].mPrev) == m_receiverUID )
        v3 = 1;
    }
    v9 = (UFG::UIScreenManagerBase *)this->mPendingOverlayLoads.mNode.mNext;
    while ( v9 != (UFG::UIScreenManagerBase *)&this->mPendingOverlayLoads )
    {
      v10 = v9->m_screenStack.mNode.mNext;
      v9 = (UFG::UIScreenManagerBase *)v9->m_screenStack.mNode.mPrev;
      if ( LODWORD(v10[7].mPrev) == m_receiverUID )
        v3 = 1;
    }
    for ( i = &this->m_screenCommandQueue.mNode.mNext[-1].mNext; i != &this->m_commandQueue.mNode.mNext; i = &i[2][-1].mNext )
    {
      v12 = *((_DWORD *)i + 6);
      if ( v12 )
      {
        if ( v12 == 2 )
        {
          if ( *((_DWORD *)i + 43) == m_receiverUID )
            v3 = 1;
        }
        else if ( v12 == 3 && *((_DWORD *)i + 42) == m_receiverUID )
        {
          v3 = 1;
        }
      }
      else if ( *((_DWORD *)i + 42) == m_receiverUID )
      {
        v3 = 1;
      }
    }
    if ( v3 )
    {
LABEL_22:
      if ( UFG::gTweakerUpdateUI && this->m_updateUI )
      {
        UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->m_pendingMessagesMutex);
        v13 = this->m_pendingMessages.mNode.mPrev;
        v13->mNext = &message->UFG::qNode<UFG::UICommand,UFG::UICommand>;
        message->mPrev = v13;
        message->mNext = &this->m_pendingMessages.mNode;
        this->m_pendingMessages.mNode.mPrev = &message->UFG::qNode<UFG::UICommand,UFG::UICommand>;
        UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->m_pendingMessagesMutex);
        return message;
      }
      goto LABEL_44;
    }
  }
  if ( !UFG::gTweakerUpdateUI || !this->m_updateUI )
  {
LABEL_44:
    message->vfptr->__vecDelDtor(message, 1i64);
    return message;
  }
  m_commandType = message->m_commandType;
  if ( m_commandType >= UICOMMAND_SCREEN_PUSH )
  {
    if ( m_commandType <= UICOMMAND_OVERLAY_POP )
    {
      p_m_screenCommandQueue = &this->m_screenCommandQueue;
      goto LABEL_42;
    }
    if ( m_commandType <= UICOMMAND_FLASH_COMMAND )
    {
      p_m_screenCommandQueue = &this->m_commandQueue;
LABEL_42:
      v21 = p_m_screenCommandQueue->mNode.mPrev;
      v21->mNext = &message->UFG::qNode<UFG::UICommand,UFG::UICommand>;
      message->mPrev = v21;
      message->mNext = &p_m_screenCommandQueue->mNode;
      p_m_screenCommandQueue->mNode.mPrev = &message->UFG::qNode<UFG::UICommand,UFG::UICommand>;
      return message;
    }
  }
  return message;
}

// File Line: 1170
// RVA: 0xA30E40
UFG::UIScreen *__fastcall UFG::UIScreenManagerBase::pushScreen(
        UFG::UIScreenManagerBase *this,
        UFG::UICommandScreenPush *pushScreenCommand)
{
  unsigned int m_screenUID; // r15d
  int m_controllerMask; // ebp
  UFG::UIScreen *m_preCreatedInstance; // rdi
  UFG::UIMessage *v7; // r14
  int v8; // ecx
  UFG::UIScreenManagerBase *p_mNext; // rax
  int m_defaultControllerMask; // eax
  int m_maxScreenLimit; // r9d
  int v12; // r8d
  UFG::UIScreenManagerBase *i; // rax
  UFG::qList<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad,1,0> *p_mPendingScreenLoads; // rdx
  int v15; // ecx
  UFG::UIScreenManagerBase *mNext; // rax
  UFG::UIScreenManagerBase *mPrev; // rax
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v18; // rax
  UFG::allocator::free_link *v19; // rax
  UFG::UIMessage *v20; // rax

  m_screenUID = pushScreenCommand->m_screenUID;
  m_controllerMask = pushScreenCommand->m_controllerMask;
  m_preCreatedInstance = pushScreenCommand->m_preCreatedInstance;
  if ( !m_preCreatedInstance )
    m_preCreatedInstance = (UFG::UIScreen *)UFG::UIScreenFactory::createScreen(
                                              this->m_screenFactory,
                                              pushScreenCommand->m_screenName);
  m_preCreatedInstance->mScreenUID = m_screenUID;
  v7 = 0i64;
  if ( m_controllerMask == -1 )
  {
    v8 = 0;
    p_mNext = (UFG::UIScreenManagerBase *)&this->m_screenStack.mNode.mNext[-1].mNext;
    if ( p_mNext == this )
      goto LABEL_9;
    do
    {
      ++v8;
      p_mNext = (UFG::UIScreenManagerBase *)&p_mNext->m_screenStack.mNode.mNext[-1].mNext;
    }
    while ( p_mNext != this );
    if ( v8 <= 0 )
LABEL_9:
      m_defaultControllerMask = this->m_defaultControllerMask;
    else
      m_defaultControllerMask = HIDWORD(this->m_screenStack.mNode.mPrev[6].mNext);
    m_preCreatedInstance->mControllerMask = m_defaultControllerMask;
  }
  else
  {
    m_preCreatedInstance->mControllerMask = m_controllerMask;
  }
  m_preCreatedInstance->mDimToApplyType = pushScreenCommand->m_dimType;
  UFG::UIScreenManagerBase::dimPreviousScreen(this, pushScreenCommand->m_dimType, m_preCreatedInstance);
  m_maxScreenLimit = this->m_maxScreenLimit;
  if ( m_maxScreenLimit > 0 )
  {
    v12 = 0;
    for ( i = (UFG::UIScreenManagerBase *)&this->m_screenStack.mNode.mNext[-1].mNext;
          i != this;
          i = (UFG::UIScreenManagerBase *)&i->m_screenStack.mNode.mNext[-1].mNext )
    {
      ++v12;
    }
    p_mPendingScreenLoads = &this->mPendingScreenLoads;
    v15 = 0;
    mNext = (UFG::UIScreenManagerBase *)this->mPendingScreenLoads.mNode.mNext;
    if ( mNext != (UFG::UIScreenManagerBase *)&this->mPendingScreenLoads )
    {
      do
      {
        ++v15;
        mNext = (UFG::UIScreenManagerBase *)mNext->m_screenStack.mNode.mPrev;
      }
      while ( mNext != (UFG::UIScreenManagerBase *)p_mPendingScreenLoads );
    }
    if ( v15 + v12 >= m_maxScreenLimit )
    {
      mPrev = (UFG::UIScreenManagerBase *)&this->m_screenStack.mNode.mNext[-1].mNext;
      if ( mPrev == this )
      {
        v18 = this->mPendingScreenLoads.mNode.mNext;
        if ( v18 == (UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *)p_mPendingScreenLoads )
          goto LABEL_21;
        mPrev = (UFG::UIScreenManagerBase *)v18[1].mPrev;
      }
      UFG::UIScreenManagerBase::queuePopScreen(this, (unsigned int)mPrev->mPendingPoppedScreens.mNode.mPrev);
    }
  }
LABEL_21:
  v19 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x68ui64, "UICommand", 0i64, 1u);
  if ( v19 )
  {
    UFG::UIMessageScreenPushed::UIMessageScreenPushed(
      (UFG::UIMessageScreenPushed *)v19,
      pushScreenCommand->m_screenName,
      m_screenUID);
    v7 = v20;
  }
  UFG::UIScreenManagerBase::queueMessageEx(this, v7);
  return m_preCreatedInstance;
}

// File Line: 1230
// RVA: 0xA309A0
void __fastcall UFG::UIScreenManagerBase::popScreen(
        UFG::UIScreenManagerBase *this,
        UFG::UICommandScreenPop *popScreenCommand)
{
  Scaleform::Lock *p_mScreenStackLock; // rbx
  UFG::qList<UFG::UIScreen,UFG::UIScreen,1,0> *p_mPendingPoppedScreens; // r13
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *mPrev; // rsi
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v6; // rcx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *mNext; // rax
  UFG::allocator::free_link *v8; // rax
  UFG::allocator::free_link *v9; // rdx
  int v10; // ecx
  UFG::allocator::free_link *v11; // rax
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v12; // rax
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *i; // rbx
  UFG::allocator::free_link *v14; // rax
  int v15; // edx
  unsigned int m_screenUID; // ebx
  UFG::allocator::free_link *v17; // rax
  UFG::allocator::free_link *v18; // rdx
  UFG::allocator::free_link *v19; // rax
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **p_mNext; // rsi
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v21; // rcx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v22; // rax
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v23; // rax
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v24; // rcx
  UFG::UIScreenManagerBase *v25; // rbx

  if ( popScreenCommand->m_popAll )
  {
    if ( (UFG::UIScreenManagerBase *)&this->m_screenStack.mNode.mNext[-1].mNext != this )
    {
      p_mScreenStackLock = &this->mScreenStackLock;
      p_mPendingPoppedScreens = &this->mPendingPoppedScreens;
      do
      {
        EnterCriticalSection(&p_mScreenStackLock->cs);
        mPrev = this->m_screenStack.mNode.mPrev;
        v6 = mPrev->mPrev;
        mNext = mPrev->mNext;
        v6->mNext = mNext;
        mNext->mPrev = v6;
        mPrev->mPrev = mPrev;
        mPrev->mNext = mPrev;
        LeaveCriticalSection(&p_mScreenStackLock->cs);
        v8 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x40ui64, "UICommand", 0i64, 1u);
        v9 = v8;
        if ( v8 )
        {
          v10 = (int)mPrev[6].mNext;
          v11 = v8 + 1;
          v11->mNext = v11;
          v11[1].mNext = v11;
          v9->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
          LODWORD(v9[3].mNext) = -1;
          v9[4].mNext = 0i64;
          v9->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
          LODWORD(v9[5].mNext) = UI_HASH_SCREEN_POPPED_35;
          HIDWORD(v9[5].mNext) = 0;
          v9[6].mNext = (UFG::allocator::free_link *)-1i64;
          LODWORD(v9[3].mNext) = 5;
          v9->mNext = (UFG::allocator::free_link *)&UFG::UIMessageScreenPopped::`vftable;
          LODWORD(v9[7].mNext) = v10;
        }
        else
        {
          v9 = 0i64;
        }
        UFG::UIScreenManagerBase::queueMessageEx(this, (UFG::UIMessage *)v9);
        ((void (__fastcall *)(UFG::qNode<UFG::UIScreen,UFG::UIScreen> *, _QWORD))mPrev[5].mNext[20].mPrev->mPrev[14].mPrev)(
          mPrev[5].mNext[20].mPrev,
          0i64);
        EnterCriticalSection(&p_mScreenStackLock->cs);
        v12 = p_mPendingPoppedScreens->mNode.mPrev;
        v12->mNext = mPrev;
        mPrev->mPrev = v12;
        mPrev->mNext = &p_mPendingPoppedScreens->mNode;
        p_mPendingPoppedScreens->mNode.mPrev = mPrev;
        LeaveCriticalSection(&p_mScreenStackLock->cs);
      }
      while ( (UFG::UIScreenManagerBase *)&this->m_screenStack.mNode.mNext[-1].mNext != this );
    }
    for ( i = this->mPendingScreenLoads.mNode.mNext;
          i != (UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *)&this->mPendingScreenLoads;
          i = i->mNext )
    {
      v14 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x40ui64, "UICommand", 0i64, 1u);
      if ( v14 )
      {
        v15 = (int)i[1].mPrev[7].mPrev;
        v14[1].mNext = v14 + 1;
        v14[2].mNext = v14 + 1;
        v14->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
        LODWORD(v14[3].mNext) = -1;
        v14[4].mNext = 0i64;
        v14->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
        LODWORD(v14[5].mNext) = UI_HASH_SCREEN_POPPED_35;
        HIDWORD(v14[5].mNext) = 0;
        v14[6].mNext = (UFG::allocator::free_link *)-1i64;
        LODWORD(v14[3].mNext) = 5;
        v14->mNext = (UFG::allocator::free_link *)&UFG::UIMessageScreenPopped::`vftable;
        LODWORD(v14[7].mNext) = v15;
      }
      else
      {
        v14 = 0i64;
      }
      UFG::UIScreenManagerBase::queueMessageEx(this, (UFG::UIMessage *)v14);
      LOBYTE(i[2].mPrev) = 1;
    }
  }
  else
  {
    m_screenUID = popScreenCommand->m_screenUID;
    v17 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x40ui64, "UICommand", 0i64, 1u);
    v18 = v17;
    if ( v17 )
    {
      v19 = v17 + 1;
      v19->mNext = v19;
      v19[1].mNext = v19;
      v18->mNext = (UFG::allocator::free_link *)&UFG::UICommand::`vftable;
      LODWORD(v18[3].mNext) = -1;
      v18[4].mNext = 0i64;
      v18->mNext = (UFG::allocator::free_link *)&UFG::UIMessage::`vftable;
      LODWORD(v18[5].mNext) = UI_HASH_SCREEN_POPPED_35;
      HIDWORD(v18[5].mNext) = 0;
      v18[6].mNext = (UFG::allocator::free_link *)-1i64;
      LODWORD(v18[3].mNext) = 5;
      v18->mNext = (UFG::allocator::free_link *)&UFG::UIMessageScreenPopped::`vftable;
      LODWORD(v18[7].mNext) = m_screenUID;
    }
    else
    {
      v18 = 0i64;
    }
    UFG::UIScreenManagerBase::queueMessageEx(this, (UFG::UIMessage *)v18);
    p_mNext = &this->m_screenStack.mNode.mPrev[-1].mNext;
    if ( p_mNext == (UFG::qNode<UFG::UIScreen,UFG::UIScreen> **)this )
    {
LABEL_23:
      v24 = this->mPendingScreenLoads.mNode.mPrev;
      if ( v24 != (UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *)&this->mPendingScreenLoads )
      {
        while ( LODWORD(v24[1].mPrev[7].mPrev) != m_screenUID && m_screenUID != -1 )
        {
          v24 = v24->mPrev;
          if ( v24 == (UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *)&this->mPendingScreenLoads )
            goto LABEL_29;
        }
        LOBYTE(v24[2].mPrev) = 1;
      }
    }
    else
    {
      while ( *((_DWORD *)p_mNext + 28) != m_screenUID && m_screenUID != -1 )
      {
        p_mNext = &p_mNext[1][-1].mNext;
        if ( p_mNext == (UFG::qNode<UFG::UIScreen,UFG::UIScreen> **)this )
          goto LABEL_23;
      }
      EnterCriticalSection(&this->mScreenStackLock.cs);
      v21 = p_mNext[1];
      v22 = p_mNext[2];
      v21->mNext = v22;
      v22->mPrev = v21;
      p_mNext[1] = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)(p_mNext + 1);
      p_mNext[2] = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)(p_mNext + 1);
      LeaveCriticalSection(&this->mScreenStackLock.cs);
      ((void (__fastcall *)(UFG::qNode<UFG::UIScreen,UFG::UIScreen> *, _QWORD))p_mNext[12][20].mPrev->mPrev[14].mPrev)(
        p_mNext[12][20].mPrev,
        0i64);
      EnterCriticalSection(&this->mScreenStackLock.cs);
      v23 = this->mPendingPoppedScreens.mNode.mPrev;
      v23->mNext = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)(p_mNext + 1);
      p_mNext[1] = v23;
      p_mNext[2] = &this->mPendingPoppedScreens.mNode;
      this->mPendingPoppedScreens.mNode.mPrev = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)(p_mNext + 1);
      LeaveCriticalSection(&this->mScreenStackLock.cs);
    }
  }
LABEL_29:
  v25 = (UFG::UIScreenManagerBase *)&this->m_screenStack.mNode.mPrev[-1].mNext;
  if ( !this->mIsMidSwitch
    && v25 != this
    && (v25->vfptr[1].isInputEnabled((UFG::UIScreenManagerBase *)&this->m_screenStack.mNode.mPrev[-1].mNext)
     || ((unsigned __int8 (__fastcall *)(UFG::UIScreenManagerBase *))v25->vfptr[1].~UIScreenManagerBase)(v25)) )
  {
    v25->vfptr[1].enableInput(v25, 0);
  }
}

// File Line: 1308
// RVA: 0xA322A0
UFG::UIScreen *__fastcall UFG::UIScreenManagerBase::switchScreen(
        UFG::UIScreenManagerBase *this,
        UFG::UICommandScreenSwitch *switchScreenCommand)
{
  unsigned int m_screenUIDToPop; // eax
  int m_controllerMask; // ecx
  unsigned int m_screenUIDToPush; // eax
  UFG::UIScreen *v7; // r8
  UFG::qNode<UFG::UICommand,UFG::UICommand> *mPrev; // rdx
  UFG::qNode<UFG::UICommand,UFG::UICommand> *mNext; // rcx
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v10; // rcx
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v11; // rax
  UFG::UICommandScreenPop popScreenCommand; // [rsp+20h] [rbp-D8h] BYREF
  __int64 v14; // [rsp+50h] [rbp-A8h]
  UFG::UICommandScreenPush pushScreenCommand; // [rsp+60h] [rbp-98h] BYREF

  v14 = -2i64;
  this->mIsMidSwitch = 1;
  m_screenUIDToPop = switchScreenCommand->m_screenUIDToPop;
  popScreenCommand.mPrev = &popScreenCommand.UFG::qNode<UFG::UICommand,UFG::UICommand>;
  popScreenCommand.mNext = &popScreenCommand.UFG::qNode<UFG::UICommand,UFG::UICommand>;
  popScreenCommand.m_commandData = 0i64;
  popScreenCommand.vfptr = (UFG::UICommandVtbl *)&UFG::UICommandScreenPop::`vftable;
  popScreenCommand.m_commandType = UICOMMAND_SCREEN_POP;
  popScreenCommand.m_popAll = 0;
  popScreenCommand.m_screenUID = m_screenUIDToPop;
  UFG::UIScreenManagerBase::popScreen(this, &popScreenCommand);
  m_controllerMask = switchScreenCommand->m_controllerMask;
  m_screenUIDToPush = switchScreenCommand->m_screenUIDToPush;
  pushScreenCommand.mPrev = &pushScreenCommand.UFG::qNode<UFG::UICommand,UFG::UICommand>;
  pushScreenCommand.mNext = &pushScreenCommand.UFG::qNode<UFG::UICommand,UFG::UICommand>;
  *(_QWORD *)&pushScreenCommand.m_commandType = 0i64;
  pushScreenCommand.vfptr = (UFG::UICommandVtbl *)&UFG::UICommandScreenPush::`vftable;
  *(_DWORD *)&pushScreenCommand.m_screenName[120] = m_screenUIDToPush;
  *(_DWORD *)&pushScreenCommand.m_screenName[124] = m_controllerMask;
  *(_QWORD *)&pushScreenCommand.m_screenUID = 0i64;
  LODWORD(pushScreenCommand.m_preCreatedInstance) = UFG::UIScreen::mDefaultDim;
  UFG::qStringCopy((char *)&pushScreenCommand.m_commandData, 128, switchScreenCommand->m_screenName, -1);
  pushScreenCommand.m_commandType = UICOMMAND_SCREEN_PUSH;
  *(_QWORD *)&pushScreenCommand.m_screenUID = switchScreenCommand->m_preCreatedInstance;
  LODWORD(pushScreenCommand.m_preCreatedInstance) = switchScreenCommand->m_dimType;
  v7 = UFG::UIScreenManagerBase::pushScreen(this, &pushScreenCommand);
  this->mIsMidSwitch = 0;
  mPrev = pushScreenCommand.mPrev;
  mNext = pushScreenCommand.mNext;
  pushScreenCommand.mPrev->mNext = pushScreenCommand.mNext;
  mNext->mPrev = mPrev;
  v10 = popScreenCommand.mPrev;
  v11 = popScreenCommand.mNext;
  popScreenCommand.mPrev->mNext = popScreenCommand.mNext;
  v11->mPrev = v10;
  return v7;
}

// File Line: 1327
// RVA: 0xA30D80
UFG::UIScreen *__fastcall UFG::UIScreenManagerBase::pushOverlay(
        UFG::UIScreenManagerBase *this,
        UFG::UICommandOverlayPush *pushOverlayCommand)
{
  _DWORD *m_preCreatedInstance; // r8
  unsigned int m_screenUID; // esi
  unsigned int m_priority; // ebp
  int m_controllerMask; // edi
  int m_defaultControllerMask; // eax
  int v8; // eax
  UFG::UIScreenManagerBase *p_mNext; // rcx

  m_preCreatedInstance = pushOverlayCommand->m_preCreatedInstance;
  m_screenUID = pushOverlayCommand->m_screenUID;
  m_priority = pushOverlayCommand->m_priority;
  m_controllerMask = pushOverlayCommand->m_controllerMask;
  if ( !m_preCreatedInstance )
    m_preCreatedInstance = UFG::UIScreenFactory::createScreen(this->m_screenFactory, pushOverlayCommand->m_screenName);
  m_preCreatedInstance[28] = m_screenUID;
  m_preCreatedInstance[31] = m_priority;
  if ( m_controllerMask == -1 )
  {
    m_defaultControllerMask = this->m_defaultControllerMask;
    if ( m_defaultControllerMask == -1 )
    {
      v8 = 0;
      p_mNext = (UFG::UIScreenManagerBase *)&this->m_screenStack.mNode.mNext[-1].mNext;
      if ( p_mNext != this )
      {
        do
        {
          ++v8;
          p_mNext = (UFG::UIScreenManagerBase *)&p_mNext->m_screenStack.mNode.mNext[-1].mNext;
        }
        while ( p_mNext != this );
        if ( v8 > 0 )
          m_preCreatedInstance[29] = HIDWORD(this->m_screenStack.mNode.mPrev[6].mNext);
      }
    }
    else
    {
      m_preCreatedInstance[29] = m_defaultControllerMask;
    }
  }
  else
  {
    m_preCreatedInstance[29] = m_controllerMask;
  }
  return (UFG::UIScreen *)m_preCreatedInstance;
}

// File Line: 1373
// RVA: 0xA30750
void __fastcall UFG::UIScreenManagerBase::popOverlay(
        UFG::UIScreenManagerBase *this,
        UFG::UICommandOverlayPop *popOverlayCommand)
{
  unsigned int m_screenUID; // r14d
  char *m_screenName; // rsi
  UFG::qList<UFG::UIScreen,UFG::UIScreen,1,0> *p_mPendingPoppedScreens; // rsi
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v6; // rdi
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v7; // rcx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v8; // rax
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v9; // rax
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v10; // rax
  UFG::qList<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad,1,0> *i; // rbp
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **p_mNext; // rdi
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v13; // rcx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v14; // rax
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v15; // rax
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *mNext; // rbx
  UFG::qList<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad,1,0> *p_mPendingOverlayLoads; // rbp
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *mPrev; // rdi

  m_screenUID = popOverlayCommand->m_screenUID;
  m_screenName = popOverlayCommand->m_screenName;
  if ( m_screenUID != -1 || (unsigned int)UFG::qStringCompare(m_screenName, &customCaption, -1) )
  {
    p_mNext = &this->m_overlayStack.mNode.mNext[-1].mNext;
    if ( p_mNext == &this->m_screenStack.mNode.mNext )
    {
LABEL_16:
      mNext = this->mPendingOverlayLoads.mNode.mNext;
      p_mPendingOverlayLoads = &this->mPendingOverlayLoads;
      if ( mNext != (UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *)p_mPendingOverlayLoads )
      {
        while ( 1 )
        {
          mPrev = mNext[1].mPrev;
          if ( LODWORD(mPrev[7].mPrev) == m_screenUID
            || (unsigned int)UFG::qStringCompare(m_screenName, &customCaption, -1)
            && !(unsigned int)UFG::qStringCompare((const char *)&mPrev[1].mNext, m_screenName, -1) )
          {
            break;
          }
          mNext = mNext->mNext;
          if ( mNext == (UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *)p_mPendingOverlayLoads )
            return;
        }
        LOBYTE(mNext[2].mPrev) = 1;
      }
    }
    else
    {
      while ( *((_DWORD *)p_mNext + 28) != m_screenUID
           && (!(unsigned int)UFG::qStringCompare(m_screenName, &customCaption, -1)
            || (unsigned int)UFG::qStringCompare((const char *)p_mNext + 24, m_screenName, -1)) )
      {
        p_mNext = &p_mNext[2][-1].mNext;
        if ( p_mNext == &this->m_screenStack.mNode.mNext )
          goto LABEL_16;
      }
      EnterCriticalSection(&this->mScreenStackLock.cs);
      v13 = p_mNext[1];
      v14 = p_mNext[2];
      v13->mNext = v14;
      v14->mPrev = v13;
      p_mNext[1] = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)(p_mNext + 1);
      p_mNext[2] = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)(p_mNext + 1);
      LeaveCriticalSection(&this->mScreenStackLock.cs);
      ((void (__fastcall *)(UFG::qNode<UFG::UIScreen,UFG::UIScreen> *, _QWORD))p_mNext[12][20].mPrev->mPrev[14].mPrev)(
        p_mNext[12][20].mPrev,
        0i64);
      EnterCriticalSection(&this->mScreenStackLock.cs);
      v15 = this->mPendingPoppedScreens.mNode.mPrev;
      v15->mNext = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)(p_mNext + 1);
      p_mNext[1] = v15;
      p_mNext[2] = &this->mPendingPoppedScreens.mNode;
      this->mPendingPoppedScreens.mNode.mPrev = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)(p_mNext + 1);
      LeaveCriticalSection(&this->mScreenStackLock.cs);
    }
  }
  else
  {
    if ( &this->m_overlayStack.mNode.mNext[-1].mNext != &this->m_screenStack.mNode.mNext )
    {
      p_mPendingPoppedScreens = &this->mPendingPoppedScreens;
      do
      {
        EnterCriticalSection(&this->mScreenStackLock.cs);
        v6 = this->m_overlayStack.mNode.mPrev;
        v7 = v6->mPrev;
        v8 = v6->mNext;
        v7->mNext = v8;
        v8->mPrev = v7;
        v6->mPrev = v6;
        v6->mNext = v6;
        LeaveCriticalSection(&this->mScreenStackLock.cs);
        ((void (__fastcall *)(UFG::qNode<UFG::UIScreen,UFG::UIScreen> *, _QWORD))v6[5].mNext[20].mPrev->mPrev[14].mPrev)(
          v6[5].mNext[20].mPrev,
          0i64);
        EnterCriticalSection(&this->mScreenStackLock.cs);
        v9 = p_mPendingPoppedScreens->mNode.mPrev;
        v9->mNext = v6;
        v6->mPrev = v9;
        v6->mNext = &p_mPendingPoppedScreens->mNode;
        p_mPendingPoppedScreens->mNode.mPrev = v6;
        LeaveCriticalSection(&this->mScreenStackLock.cs);
      }
      while ( &this->m_overlayStack.mNode.mNext[-1].mNext != &this->m_screenStack.mNode.mNext );
    }
    v10 = this->mPendingOverlayLoads.mNode.mNext;
    for ( i = &this->mPendingOverlayLoads;
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
  UFG::UIFlowRoot *v4; // rax
  bool result; // al
  UFG::UIScreen *p_mNext; // rbx
  unsigned int m_receiverUID; // r14d
  void (__fastcall *m_audioCallback)(const char *, unsigned int, unsigned int, unsigned int); // rax

  v4 = UFG::LazyInitGet<UFG::UIFlowRoot>::get();
  if ( v4->vfptr->flowHandleMessage(v4, msg->m_messageId, msg) )
    return 1;
  result = UFG::UIScreenManagerBase::handleMessage(this, msg, &this->m_screenStack, this->m_eatInputForScreens);
  if ( !result )
  {
    p_mNext = (UFG::UIScreen *)&this->m_overlayStack.mNode.mPrev[-1].mNext;
    m_receiverUID = msg->m_receiverUID;
    if ( p_mNext == (UFG::UIScreen *)&this->m_screenStack.mNode.mNext )
    {
      return 0;
    }
    else
    {
      while ( 1 )
      {
        if ( (msg->m_receiverUID == -1 || p_mNext->mScreenUID == m_receiverUID)
          && (msg->m_commandType != UICOMMAND_INPUT
           || p_mNext->mInputEnabled >= 0
           && !p_mNext->vfptr->isDimmed(p_mNext)
           && !p_mNext->vfptr->isDimming(p_mNext)
           && !p_mNext->vfptr->isUnDimming(p_mNext)
           && (msg->m_messageType || (p_mNext->mControllerMask & HIDWORD(msg[1].vfptr)) != 0)) )
        {
          if ( msg->m_commandType == UICOMMAND_INPUT )
            UFG::UIScreen::handleInput(p_mNext, msg->m_messageId, msg);
          if ( p_mNext->vfptr->handleMessage(p_mNext, msg->m_messageId, msg) )
            break;
        }
        p_mNext = (UFG::UIScreen *)&p_mNext->mPrev[-1].mNext;
        if ( p_mNext == (UFG::UIScreen *)&this->m_screenStack.mNode.mNext )
          return 0;
      }
      m_audioCallback = this->m_audioCallback;
      if ( m_audioCallback )
        m_audioCallback(p_mNext->m_screenName, p_mNext->m_screenNameHash, msg->m_messageId, msg->m_resultId);
      return 1;
    }
  }
  return result;
}

// File Line: 1496
// RVA: 0xA2F650
char __fastcall UFG::UIScreenManagerBase::handleMessage(
        UFG::UIScreenManagerBase *this,
        UFG::UIMessage *msg,
        UFG::qList<UFG::UIScreen,UFG::UIScreen,1,0> *stack,
        bool eatInput)
{
  unsigned int m_receiverUID; // r14d
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **p_mNext; // r15
  char *v6; // rbx
  bool v10; // si
  bool v11; // zf
  void (__fastcall *m_audioCallback)(const char *, unsigned int, unsigned int, unsigned int); // rax

  m_receiverUID = msg->m_receiverUID;
  p_mNext = &stack[-1].mNode.mNext;
  v6 = (char *)&stack->mNode.mPrev[-1].mNext;
  if ( v6 == (char *)&stack[-1].mNode.mNext )
    return 0;
  while ( 1 )
  {
    if ( msg->m_receiverUID != -1 && *((_DWORD *)v6 + 28) != m_receiverUID )
      goto LABEL_19;
    v10 = msg->m_commandType == UICOMMAND_INPUT;
    if ( msg->m_commandType == UICOMMAND_INPUT
      && (*((int *)v6 + 30) < 0
       || (*(unsigned __int8 (__fastcall **)(char *))(*(_QWORD *)v6 + 72i64))(v6)
       || (*(unsigned __int8 (__fastcall **)(char *))(*(_QWORD *)v6 + 88i64))(v6)
       || (*(unsigned __int8 (__fastcall **)(char *))(*(_QWORD *)v6 + 80i64))(v6)
       || msg->m_messageType == UIMESSAGE_PAD_INPUT && (*((_DWORD *)v6 + 29) & HIDWORD(msg[1].vfptr)) == 0) )
    {
      v11 = !eatInput;
      goto LABEL_18;
    }
    if ( msg->m_commandType == UICOMMAND_INPUT )
      UFG::UIScreen::handleInput((UFG::UIScreen *)v6, msg->m_messageId, msg);
    if ( (*(unsigned __int8 (__fastcall **)(char *, _QWORD, UFG::UIMessage *))(*(_QWORD *)v6 + 32i64))(
           v6,
           msg->m_messageId,
           msg) )
    {
      break;
    }
    if ( !v10 || !eatInput )
      goto LABEL_19;
    v11 = msg->m_messageType == UIMESSAGE_MOUSE_INPUT;
LABEL_18:
    if ( !v11 )
      return 1;
LABEL_19:
    v6 = (char *)(*((_QWORD *)v6 + 1) - 8i64);
    if ( v6 == (char *)p_mNext )
      return 0;
  }
  m_audioCallback = this->m_audioCallback;
  if ( m_audioCallback )
    m_audioCallback(v6 + 24, *((_DWORD *)v6 + 22), msg->m_messageId, msg->m_resultId);
  return 1;
}

// File Line: 1601
// RVA: 0xA32820
void __fastcall UFG::UIScreenManagerBase::updateCommandQueue(UFG::UIScreenManagerBase *this, float elapsed)
{
  int *p_m_defaultControllerMask; // rsi
  UFG::qNode<UFG::UICommand,UFG::UICommand> *mNext; // rbx
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v5; // rax
  UFG::qNode<UFG::UICommand,UFG::UICommand> *mPrev; // rcx

  p_m_defaultControllerMask = &this->m_defaultControllerMask;
  while ( (int *)&this->m_commandQueue.mNode.mNext[-1].mNext != p_m_defaultControllerMask )
  {
    mNext = this->m_commandQueue.mNode.mNext;
    v5 = mNext->mNext;
    mPrev = mNext->mPrev;
    mPrev->mNext = v5;
    v5->mPrev = mPrev;
    mNext->mPrev = mNext;
    mNext->mNext = mNext;
    if ( (unsigned int)(LODWORD(mNext[1].mPrev) - 5) <= 2 )
      UFG::UIScreenManagerBase::handleMessage(this, (UFG::UIMessage *)&mNext[-1].mNext);
    ((void (__fastcall *)(UFG::qNode<UFG::UICommand,UFG::UICommand> **, __int64))mNext[-1].mNext->mPrev)(
      &mNext[-1].mNext,
      1i64);
  }
}

// File Line: 1641
// RVA: 0xA32D40
void __fastcall UFG::UIScreenManagerBase::updateScreenCommandQueue(UFG::UIScreenManagerBase *this, float elapsed)
{
  UFG::qNode<UFG::UICommand,UFG::UICommand> *p_mNext; // r14
  UFG::qNode<UFG::UICommand,UFG::UICommand> *mNext; // rdx
  UFG::qNode<UFG::UICommand,UFG::UICommand> *mPrev; // rcx
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v6; // rax
  UFG::qNode<UFG::UICommand,UFG::UICommand> **v7; // rdi
  int v8; // ecx
  int v9; // ecx
  int v10; // ecx
  int v11; // ecx
  UFG::UIScreen *v12; // rbp
  UFG::allocator::free_link *v13; // rbx
  UFG::allocator::free_link *v14; // rax
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v15; // rdx
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v16; // rax
  UFG::allocator::free_link *v17; // rbx
  Scaleform::GFx::Loader *m_gfxMovieLoader; // rax
  int v19; // eax
  UFG::allocator::free_link *v20; // rbx
  UFG::allocator::free_link *v21; // rax
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v22; // rdx
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v23; // rax
  Scaleform::GFx::Loader *v24; // rax
  int v25; // eax
  UFG::allocator::free_link *v26; // rbx
  UFG::allocator::free_link *v27; // rax
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v28; // rdx
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v29; // rax
  Scaleform::GFx::Loader *v30; // rax
  int v31; // eax
  char dest[512]; // [rsp+40h] [rbp-628h] BYREF
  char text[512]; // [rsp+240h] [rbp-428h] BYREF
  char v34[512]; // [rsp+440h] [rbp-228h] BYREF

  p_mNext = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)&this->m_commandQueue.mNode.mNext;
  if ( &this->m_screenCommandQueue.mNode.mNext[-1].mNext != &this->m_commandQueue.mNode.mNext )
  {
    while ( 1 )
    {
      mNext = this->m_screenCommandQueue.mNode.mNext;
      mPrev = mNext->mPrev;
      v6 = mNext->mNext;
      mPrev->mNext = v6;
      v6->mPrev = mPrev;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      v7 = &mNext[-1].mNext;
      v8 = (int)mNext[1].mPrev;
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
              UFG::UIScreenManagerBase::popOverlay(this, (UFG::UICommandOverlayPop *)&mNext[-1].mNext);
            goto LABEL_28;
          }
          v12 = UFG::UIScreenManagerBase::pushOverlay(this, (UFG::UICommandOverlayPush *)&mNext[-1].mNext);
          v13 = (UFG::allocator::free_link *)v7[4];
          v14 = UFG::qMalloc(0x28ui64, "UIScreenManagerBase::updateScreenCommandQueue", 0i64);
          v15 = (UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *)v14;
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
          v16 = this->mPendingOverlayLoads.mNode.mPrev;
          v16->mNext = v15;
          v15->mPrev = v16;
          v15->mNext = &this->mPendingOverlayLoads.mNode;
          this->mPendingOverlayLoads.mNode.mPrev = v15;
          UFG::qSPrintf(dest, "%s%s.gfx", this->m_screenFactory->m_rootDir, (const char *)v7 + 40);
          v17 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x168ui64, "UIScreen::load", 0i64, 1u);
          if ( v17 )
          {
            m_gfxMovieLoader = this->m_gfxMovieLoader;
            v17->mNext = (UFG::allocator::free_link *)&UFG::UIScreenRenderable::`vftable;
            v17[1].mNext = 0i64;
            LOBYTE(v17[2].mNext) = 0;
            v17[39].mNext = 0i64;
            v17[40].mNext = 0i64;
            v17[41].mNext = (UFG::allocator::free_link *)m_gfxMovieLoader;
            v17[42].mNext = 0i64;
            v17[43].mNext = 0i64;
            LOBYTE(v17[44].mNext) = 1;
            BYTE1(v17[44].mNext) = 0;
            v19 = UFG::qStringLength(dest);
            UFG::qStringCopy((char *)&v17[2].mNext + 1, 256, dest, v19);
          }
          else
          {
            v17 = 0i64;
          }
        }
        else
        {
          v12 = UFG::UIScreenManagerBase::switchScreen(this, (UFG::UICommandScreenSwitch *)&mNext[-1].mNext);
          v20 = (UFG::allocator::free_link *)v7[4];
          v21 = UFG::qMalloc(0x28ui64, "UIScreenManagerBase::updateScreenCommandQueue", 0i64);
          v22 = (UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *)v21;
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
          v23 = this->mPendingScreenLoads.mNode.mPrev;
          v23->mNext = v22;
          v22->mPrev = v23;
          v22->mNext = &this->mPendingScreenLoads.mNode;
          this->mPendingScreenLoads.mNode.mPrev = v22;
          UFG::qSPrintf(text, "%s%s.gfx", this->m_screenFactory->m_rootDir, (const char *)v7 + 44);
          v17 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x168ui64, "UIScreen::load", 0i64, 1u);
          if ( v17 )
          {
            v24 = this->m_gfxMovieLoader;
            v17->mNext = (UFG::allocator::free_link *)&UFG::UIScreenRenderable::`vftable;
            v17[1].mNext = 0i64;
            LOBYTE(v17[2].mNext) = 0;
            v17[39].mNext = 0i64;
            v17[40].mNext = 0i64;
            v17[41].mNext = (UFG::allocator::free_link *)v24;
            v17[42].mNext = 0i64;
            v17[43].mNext = 0i64;
            LOBYTE(v17[44].mNext) = 1;
            BYTE1(v17[44].mNext) = 0;
            v25 = UFG::qStringLength(text);
            UFG::qStringCopy((char *)&v17[2].mNext + 1, 256, text, v25);
          }
          else
          {
            v17 = 0i64;
          }
        }
        goto LABEL_27;
      }
      UFG::UIScreenManagerBase::popScreen(this, (UFG::UICommandScreenPop *)&mNext[-1].mNext);
LABEL_28:
      ((void (__fastcall *)(UFG::qNode<UFG::UICommand,UFG::UICommand> **, __int64))(*v7)->mPrev)(v7, 1i64);
      if ( (UFG::qNode<UFG::UICommand,UFG::UICommand> *)((char *)this->m_screenCommandQueue.mNode.mNext - 8) == p_mNext )
        return;
    }
    v12 = UFG::UIScreenManagerBase::pushScreen(this, (UFG::UICommandScreenPush *)&mNext[-1].mNext);
    v26 = (UFG::allocator::free_link *)v7[4];
    v27 = UFG::qMalloc(0x28ui64, "UIScreenManagerBase::updateScreenCommandQueue", 0i64);
    v28 = (UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *)v27;
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
    v29 = this->mPendingScreenLoads.mNode.mPrev;
    v29->mNext = v28;
    v28->mPrev = v29;
    v28->mNext = &this->mPendingScreenLoads.mNode;
    this->mPendingScreenLoads.mNode.mPrev = v28;
    UFG::qSPrintf(v34, "%s%s.gfx", this->m_screenFactory->m_rootDir, (const char *)v7 + 40);
    v17 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x168ui64, "UIScreen::load", 0i64, 1u);
    if ( v17 )
    {
      v30 = this->m_gfxMovieLoader;
      v17->mNext = (UFG::allocator::free_link *)&UFG::UIScreenRenderable::`vftable;
      v17[1].mNext = 0i64;
      LOBYTE(v17[2].mNext) = 0;
      v17[39].mNext = 0i64;
      v17[40].mNext = 0i64;
      v17[41].mNext = (UFG::allocator::free_link *)v30;
      v17[42].mNext = 0i64;
      v17[43].mNext = 0i64;
      LOBYTE(v17[44].mNext) = 1;
      BYTE1(v17[44].mNext) = 0;
      v31 = UFG::qStringLength(v34);
      UFG::qStringCopy((char *)&v17[2].mNext + 1, 256, v34, v31);
    }
    else
    {
      v17 = 0i64;
    }
LABEL_27:
    UFG::UIScreen::load(v12, (UFG::UIScreenRenderable *)v17);
    goto LABEL_28;
  }
} UFG::qStringCopy((char *)&v17[2].mN

// File Line: 1724
// RVA: 0xA2BA30
UFG::UIScreen *__fastcall UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManagerBase *this, const char *fileName)
{
  UFG::UIScreen *result; // rax

  result = (UFG::UIScreen *)UFG::UIScreenManagerBase::getScreenFromStack(this, fileName, &this->m_screenStack);
  if ( !result )
    return UFG::UIScreenManagerBase::getScreenFromPendingStack(this, fileName, &this->mPendingScreenLoads);
  return result;
}

// File Line: 1739
// RVA: 0xA2B9A0
UFG::UIScreen *__fastcall UFG::UIScreenManagerBase::getOverlay(UFG::UIScreenManagerBase *this, const char *fileName)
{
  UFG::UIScreen *result; // rax

  result = (UFG::UIScreen *)UFG::UIScreenManagerBase::getScreenFromStack(this, fileName, &this->m_overlayStack);
  if ( !result )
    return UFG::UIScreenManagerBase::getScreenFromPendingStack(this, fileName, &this->mPendingOverlayLoads);
  return result;
}

// File Line: 1754
// RVA: 0xA2BB60
signed __int64 __fastcall UFG::UIScreenManagerBase::getScreenUID(UFG::UIScreenManagerBase *this, const char *fileName)
{
  unsigned int *ScreenFromStack; // rax

  ScreenFromStack = (unsigned int *)UFG::UIScreenManagerBase::getScreenFromStack(this, fileName, &this->m_screenStack);
  if ( ScreenFromStack )
    return ScreenFromStack[28];
  ScreenFromStack = (unsigned int *)UFG::UIScreenManagerBase::getScreenFromPendingStack(
                                      this,
                                      fileName,
                                      &this->mPendingScreenLoads);
  if ( ScreenFromStack )
    return ScreenFromStack[28];
  else
    return 0xFFFFFFFFi64;
}

// File Line: 1814
// RVA: 0xA2B9E0
UFG::qNode<UFG::UIScreen,UFG::UIScreen> **__fastcall UFG::UIScreenManagerBase::getScreen(
        UFG::UIScreenManagerBase *this,
        unsigned int screenUID)
{
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **result; // rax
  UFG::UIScreenManagerBase *mNext; // rax

  result = &this->m_screenStack.mNode.mNext[-1].mNext;
  if ( result == (UFG::qNode<UFG::UIScreen,UFG::UIScreen> **)this )
  {
LABEL_4:
    mNext = (UFG::UIScreenManagerBase *)this->mPendingScreenLoads.mNode.mNext;
    if ( mNext == (UFG::UIScreenManagerBase *)&this->mPendingScreenLoads )
    {
      return 0i64;
    }
    else
    {
      while ( LODWORD(mNext->m_screenStack.mNode.mNext[7].mPrev) != screenUID )
      {
        mNext = (UFG::UIScreenManagerBase *)mNext->m_screenStack.mNode.mPrev;
        if ( mNext == (UFG::UIScreenManagerBase *)&this->mPendingScreenLoads )
          return 0i64;
      }
      return (UFG::qNode<UFG::UIScreen,UFG::UIScreen> **)mNext->m_screenStack.mNode.mNext;
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
UFG::qNode<UFG::UIScreen,UFG::UIScreen> **__fastcall UFG::UIScreenManagerBase::getScreenFromStack(
        UFG::UIScreenManagerBase *this,
        const char *screenName,
        UFG::qList<UFG::UIScreen,UFG::UIScreen,1,0> *stack)
{
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **p_mNext; // rdi
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **v5; // rbx

  p_mNext = &stack[-1].mNode.mNext;
  v5 = &stack->mNode.mNext[-1].mNext;
  if ( v5 == &stack[-1].mNode.mNext )
    return 0i64;
  while ( (unsigned int)UFG::qStringCompare((const char *)v5 + 24, screenName, -1) )
  {
    v5 = &v5[2][-1].mNext;
    if ( v5 == p_mNext )
      return 0i64;
  }
  return v5;
}

// File Line: 1903
// RVA: 0xA2BA70
UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *__fastcall UFG::UIScreenManagerBase::getScreenFromPendingStack(
        UFG::UIScreenManagerBase *this,
        const char *screenName,
        UFG::qList<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad,1,0> *stack)
{
  UFG::qList<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad,1,0> *mNext; // rbx
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *mPrev; // rsi

  mNext = (UFG::qList<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad,1,0> *)stack->mNode.mNext;
  if ( mNext == stack )
    return 0i64;
  while ( 1 )
  {
    mPrev = mNext[1].mNode.mPrev;
    if ( !(unsigned int)UFG::qStringCompare((const char *)&mPrev[1].mNext, screenName, -1) )
      break;
    mNext = (UFG::qList<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad,1,0> *)mNext->mNode.mNext;
    if ( mNext == stack )
      return 0i64;
  }
  return mPrev;
}

// File Line: 1995
// RVA: 0xA2BEF0
UFG::qNode<UFG::UIScreen,UFG::UIScreen> **__fastcall UFG::UIScreenManagerBase::getTopScreen(
        UFG::UIScreenManagerBase *this)
{
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **result; // rax

  result = &this->m_screenStack.mNode.mPrev[-1].mNext;
  if ( result == (UFG::qNode<UFG::UIScreen,UFG::UIScreen> **)this )
    return 0i64;
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
  Render::DebugDrawContext *Context; // rsi
  UFG::UIGfxTranslator *m_translator; // rax
  const char *LanguageString; // rax
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **p_mNext; // rbx
  int v6; // ebp
  int i; // r14d
  int AVMVersion; // eax
  const char *v9; // r9
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **j; // rbx
  int v11; // eax
  const char *v12; // r9
  char dest[16]; // [rsp+30h] [rbp-28h] BYREF

  if ( UFG::gUIPrint )
  {
    Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
    m_translator = this->m_translator;
    if ( !UFG::gUIShowIconsInBlankLoc || m_translator->mLanguage )
      LanguageString = UFG::UILanguages::getLanguageString(m_translator->mLanguage);
    else
      LanguageString = "English";
    Render::DebugDrawContext::DrawTextA(Context, 50, 400, &UFG::qColour::White, "Language: %s", LanguageString);
    Render::DebugDrawContext::DrawTextA(Context, 50, 415, &UFG::qColour::White, "Overlays:");
    p_mNext = &this->m_overlayStack.mNode.mPrev[-1].mNext;
    v6 = 430;
    for ( i = 430; p_mNext != &this->m_screenStack.mNode.mNext; p_mNext = &p_mNext[1][-1].mNext )
    {
      UFG::qSPrintf(dest, 16, "%d", *((unsigned int *)p_mNext + 28));
      Render::DebugDrawContext::DrawTextA(Context, 50, i, &UFG::qColour::Grey, dest);
      UFG::qSPrintf(dest, 16, "%d", *((unsigned int *)p_mNext + 30));
      Render::DebugDrawContext::DrawTextA(Context, 75, i, &UFG::qColour::Grey, dest);
      AVMVersion = Scaleform::GFx::Movie::GetAVMVersion((Scaleform::GFx::Movie *)p_mNext[12][20].mPrev);
      v9 = "AS3";
      if ( AVMVersion == 1 )
        v9 = "AS2";
      UFG::qSPrintf(dest, 16, "%s", v9);
      Render::DebugDrawContext::DrawTextA(Context, 95, i, &UFG::qColour::Grey, dest);
      Render::DebugDrawContext::DrawTextA(Context, 125, i, &UFG::qColour::Grey, (const char *)p_mNext + 24);
      i += 15;
    }
    Render::DebugDrawContext::DrawTextA(Context, 250, 415, &UFG::qColour::White, "Screens:");
    for ( j = &this->m_screenStack.mNode.mPrev[-1].mNext;
          j != (UFG::qNode<UFG::UIScreen,UFG::UIScreen> **)this;
          j = &j[1][-1].mNext )
    {
      UFG::qSPrintf(dest, 16, "%d", *((unsigned int *)j + 28));
      Render::DebugDrawContext::DrawTextA(Context, 250, v6, &UFG::qColour::Grey, dest);
      UFG::qSPrintf(dest, 16, "%d", *((unsigned int *)j + 30));
      Render::DebugDrawContext::DrawTextA(Context, 275, v6, &UFG::qColour::Grey, dest);
      v11 = Scaleform::GFx::Movie::GetAVMVersion((Scaleform::GFx::Movie *)j[12][20].mPrev);
      v12 = "AS3";
      if ( v11 == 1 )
        v12 = "AS2";
      UFG::qSPrintf(dest, 16, "%s", v12);
      Render::DebugDrawContext::DrawTextA(Context, 295, v6, &UFG::qColour::Grey, dest);
      Render::DebugDrawContext::DrawTextA(Context, 325, v6, &UFG::qColour::Grey, (const char *)j + 24);
      v6 += 15;
    }
    this->m_currentNumDrawText = 0;
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
  Scaleform::Lock *p_mScreenStackLock; // rbx
  UFG::UIScreenManagerBase *i; // rdi
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **p_mNext; // rdi
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> **j; // rbp
  Scaleform::GFx::Resource **v6; // rsi
  hkDynamicClassNameRegistry **v7; // rax
  Scaleform::Render::ContextImpl::RenderNotify *expected_type; // rax
  Scaleform::Render::ContextImpl::RTHandle v9; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::Render::RenderBuffer *v10; // [rsp+58h] [rbp+10h] BYREF
  Scaleform::Lock *v11; // [rsp+60h] [rbp+18h]

  p_mScreenStackLock = &this->mScreenStackLock;
  v11 = &this->mScreenStackLock;
  EnterCriticalSection(&this->mScreenStackLock.cs);
  for ( i = (UFG::UIScreenManagerBase *)&this->m_screenStack.mNode.mNext[-1].mNext;
        i != this;
        i = (UFG::UIScreenManagerBase *)&i->m_screenStack.mNode.mNext[-1].mNext )
  {
    if ( !i->mPendingOverlayLoads.mNode.mPrev->mNext )
      ((void (__fastcall *)(UFG::UIScreenManagerBase *))i->vfptr->enableInput)(i);
  }
  p_mNext = &this->mPendingPoppedScreens.mNode.mNext[-1].mNext;
  for ( j = &this->mPendingOverlayLoads.mNode.mNext;
        p_mNext != (UFG::qNode<UFG::UIScreen,UFG::UIScreen> **)j;
        p_mNext = &p_mNext[2][-1].mNext )
  {
    v6 = (Scaleform::GFx::Resource **)((__int64 (__fastcall *)(UFG::qNode<UFG::UIScreen,UFG::UIScreen> *))p_mNext[12][20].mPrev->mPrev[13].mPrev)(p_mNext[12][20].mPrev);
    if ( *v6 )
      Scaleform::Render::RenderBuffer::AddRef(*v6);
    v9.pData.pObject = (Scaleform::Render::ContextImpl::RTHandle::HandleData *)*v6;
    v7 = (hkDynamicClassNameRegistry **)UFG::UIScreenManager::s_instance->vfptr->getRenderer2D(
                                          UFG::UIScreenManager::s_instance,
                                          &v10);
    expected_type = (Scaleform::Render::ContextImpl::RenderNotify *)SSUnaryParam::get_expected_type(*v7);
    Scaleform::Render::ContextImpl::RTHandle::NextCapture(&v9, expected_type);
    if ( v10 )
      Scaleform::RefCountImpl::Release(v10);
    Scaleform::Render::ContextImpl::RTHandle::~RTHandle(&v9);
  }
  LeaveCriticalSection(&p_mScreenStackLock->cs);
}

// File Line: 2151
// RVA: 0xA31AE0
void __fastcall UFG::UIScreenManagerBase::renderOverlays(UFG::UIScreenManagerBase *this)
{
  Scaleform::Lock *p_mScreenStackLock; // rbx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **p_mNext; // rdi
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **i; // rsi

  p_mScreenStackLock = &this->mScreenStackLock;
  EnterCriticalSection(&this->mScreenStackLock.cs);
  p_mNext = &this->m_overlayStack.mNode.mNext[-1].mNext;
  for ( i = &this->m_screenStack.mNode.mNext; p_mNext != i; p_mNext = &p_mNext[2][-1].mNext )
  {
    if ( !p_mNext[12]->mNext )
      ((void (__fastcall *)(UFG::qNode<UFG::UIScreen,UFG::UIScreen> **))(*p_mNext)[1].mPrev)(p_mNext);
  }
  LeaveCriticalSection(&p_mScreenStackLock->cs);
}

// File Line: 2170
// RVA: 0xA2FDF0
void __fastcall UFG::UIScreenManagerBase::initCustomRendering(UFG::UIScreenManagerBase *this)
{
  UFG::qResourceData *v1; // rax
  UFG::qResourceData *v2; // rbx
  UFG::qResourceWarehouse *v3; // rax
  UFG::qResourceData *v4; // rax
  UFG::qResourceData *v5; // rbx
  UFG::qResourceWarehouse *v6; // rax
  UFG::qResourceData *v7; // rax
  UFG::qResourceData *v8; // rbx
  UFG::qResourceWarehouse *v9; // rax
  UFG::qResourceData *v10; // rax
  UFG::qResourceData *v11; // rbx
  UFG::qResourceWarehouse *v12; // rax

  UFG::gUIrasterState_Mask_Clear_SetBit0_UID = UFG::qStringHash32("UIrasterState_Mask_Clear_SetBit0", 0xFFFFFFFF);
  v1 = Illusion::Factory::NewRasterState(
         "UIrasterState_Mask_Clear_SetBit0",
         UFG::gUIrasterState_Mask_Clear_SetBit0_UID,
         0i64,
         0i64,
         0i64);
  LODWORD(v1[1].mNode.mParent) = 458752;
  HIWORD(v1[1].mNode.mParent) = 1;
  *(_DWORD *)((char *)v1[1].mNode.mChild + 6) = 519;
  WORD2(v1[1].mNode.mChild[0]) = 255;
  BYTE3(v1[1].mNode.mChild[0]) = 1;
  v2 = v1;
  v3 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v3, v2);
  UFG::gUIrasterState_Mask_Clear_SetBit1_UID = UFG::qStringHash32("UIrasterState_Mask_Clear_SetBit1", 0xFFFFFFFF);
  v4 = Illusion::Factory::NewRasterState(
         "UIrasterState_Mask_Clear_SetBit1",
         UFG::gUIrasterState_Mask_Clear_SetBit1_UID,
         0i64,
         0i64,
         0i64);
  LODWORD(v4[1].mNode.mParent) = 458752;
  HIWORD(v4[1].mNode.mParent) = 1;
  *(_DWORD *)((char *)v4[1].mNode.mChild + 6) = 519;
  WORD2(v4[1].mNode.mChild[0]) = -1;
  BYTE3(v4[1].mNode.mChild[0]) = 1;
  v5 = v4;
  v6 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v6, v5);
  UFG::gUIrasterState_Mask_End_UID = UFG::qStringHash32("UIrasterState_Mask_End", 0xFFFFFFFF);
  v7 = Illusion::Factory::NewRasterState("UIrasterState_Mask_End", UFG::gUIrasterState_Mask_End_UID, 0i64, 0i64, 0i64);
  LODWORD(v7[1].mNode.mParent) = 458752;
  BYTE6(v7[1].mNode.mParent) = 1;
  *(_DWORD *)((char *)v7[1].mNode.mChild + 6) = 2;
  WORD2(v7[1].mNode.mChild[0]) = -1;
  v8 = v7;
  v9 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v9, v8);
  UFG::gUIrasterState_Mask2_End_UID = UFG::qStringHash32("UIrasterState_Mask_End2", 0xFFFFFFFF);
  v10 = Illusion::Factory::NewRasterState(
          "UIrasterState_Mask_End2",
          UFG::gUIrasterState_Mask2_End_UID,
          0i64,
          0i64,
          0i64);
  LODWORD(v10[1].mNode.mParent) = 458752;
  BYTE6(v10[1].mNode.mParent) = 1;
  *(_DWORD *)((char *)v10[1].mNode.mChild + 6) = 514;
  WORD2(v10[1].mNode.mChild[0]) = -1;
  v11 = v10;
  v12 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v12, v11);
}

// File Line: 2275
// RVA: 0xA2A850
void __fastcall UFG::UIScreenManagerBase::customPreRender(UFG::UIScreenManagerBase *this, Render::View *view)
{
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **p_mNext; // r14
  UFG::UIScreenManagerBase *i; // rbx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **j; // rbx

  p_mNext = &this->m_screenStack.mNode.mNext;
  for ( i = (UFG::UIScreenManagerBase *)&this->m_screenStack.mNode.mNext[-1].mNext;
        i != this;
        i = (UFG::UIScreenManagerBase *)&i->m_screenStack.mNode.mNext[-1].mNext )
  {
    ((void (__fastcall *)(UFG::UIScreenManagerBase *, Render::View *))i->vfptr->~UIScreenManagerBase)(i, view);
  }
  for ( j = &this->m_overlayStack.mNode.mNext[-1].mNext; j != p_mNext; j = &j[2][-1].mNext )
    ((void (__fastcall *)(UFG::qNode<UFG::UIScreen,UFG::UIScreen> **, Render::View *))(*j)[2].mNext)(j, view);
}

// File Line: 2287
// RVA: 0xA29390
void __fastcall UFG::UIScreenManagerBase::advance(
        UFG::UIScreenManagerBase *this,
        float elapsed,
        __int64 a3,
        __int64 a4)
{
  __int64 v4; // rdx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **p_mNext; // rsi
  UFG::UIScreenManagerBase *i; // rbx
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *mPrev; // rcx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **j; // rbx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v10; // rcx

  if ( this->m_renderUI && UFG::gTweakerRenderUI )
  {
    p_mNext = &this->m_screenStack.mNode.mNext;
    for ( i = (UFG::UIScreenManagerBase *)&this->m_screenStack.mNode.mNext[-1].mNext;
          i != this;
          i = (UFG::UIScreenManagerBase *)&i->m_screenStack.mNode.mNext[-1].mNext )
    {
      mPrev = i->mPendingOverlayLoads.mNode.mPrev;
      if ( LOBYTE(mPrev[22].mPrev) )
      {
        LOBYTE(a4) = 1;
        ((void (__fastcall *)(UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *, __int64, __int64, __int64))mPrev[20].mPrev->mPrev[12].mPrev)(
          mPrev[20].mPrev,
          v4,
          2i64,
          a4);
      }
    }
    for ( j = &this->m_overlayStack.mNode.mNext[-1].mNext; j != p_mNext; j = &j[2][-1].mNext )
    {
      v10 = j[12];
      if ( LOBYTE(v10[22].mPrev) )
      {
        LOBYTE(a4) = 1;
        ((void (__fastcall *)(UFG::qNode<UFG::UIScreen,UFG::UIScreen> *, __int64, __int64, __int64))v10[20].mPrev->mPrev[12].mPrev)(
          v10[20].mPrev,
          v4,
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
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **p_mNext; // r14
  UFG::UIScreenManagerBase *i; // rbx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **j; // rbx

  p_mNext = &this->m_screenStack.mNode.mNext;
  for ( i = (UFG::UIScreenManagerBase *)&this->m_screenStack.mNode.mNext[-1].mNext;
        i != this;
        i = (UFG::UIScreenManagerBase *)&i->m_screenStack.mNode.mNext[-1].mNext )
  {
    ((void (__fastcall *)(UFG::UIScreenManagerBase *, Render::View *))i->vfptr[1].update)(i, view);
  }
  for ( j = &this->m_overlayStack.mNode.mNext[-1].mNext; j != p_mNext; j = &j[2][-1].mNext )
    ((void (__fastcall *)(UFG::qNode<UFG::UIScreen,UFG::UIScreen> **, Render::View *))(*j)[3].mPrev)(j, view);
}

// File Line: 2323
// RVA: 0xA32220
void __fastcall UFG::UIScreenManagerBase::shutdownScreen(UFG::UIScreenManagerBase *this, UFG::UIScreen *screen)
{
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *mPrev; // rax

  screen->mRenderable->m_movie.pObject->vfptr[28].__vecDelDtor(screen->mRenderable->m_movie.pObject, 0);
  EnterCriticalSection(&this->mScreenStackLock.cs);
  mPrev = this->mPendingPoppedScreens.mNode.mPrev;
  mPrev->mNext = &screen->UFG::qNode<UFG::UIScreen,UFG::UIScreen>;
  screen->mPrev = mPrev;
  screen->mNext = &this->mPendingPoppedScreens.mNode;
  this->mPendingPoppedScreens.mNode.mPrev = &screen->UFG::qNode<UFG::UIScreen,UFG::UIScreen>;
  LeaveCriticalSection(&this->mScreenStackLock.cs);
}

// File Line: 2432
// RVA: 0xA2ACF0
void __fastcall UFG::UIScreenManagerBase::dimPreviousScreen(
        UFG::UIScreenManagerBase *this,
        unsigned int dimType,
        UFG::UIScreen *newScreen)
{
  char *p_mNext; // rbx

  p_mNext = (char *)&this->m_screenStack.mNode.mPrev[-1].mNext;
  if ( p_mNext == (char *)this )
  {
LABEL_4:
    p_mNext = (char *)&this->m_screenStack.mNode.mPrev[-1].mNext;
  }
  else
  {
    while ( *((_DWORD *)p_mNext + 29) != newScreen->mControllerMask )
    {
      p_mNext = (char *)(*((_QWORD *)p_mNext + 1) - 8i64);
      if ( p_mNext == (char *)this )
        goto LABEL_4;
    }
  }
  if ( p_mNext != (char *)this
    && (!(*(unsigned __int8 (__fastcall **)(char *))(*(_QWORD *)p_mNext + 72i64))(p_mNext)
     || (*(unsigned __int8 (__fastcall **)(char *))(*(_QWORD *)p_mNext + 80i64))(p_mNext)) )
  {
    (*(void (__fastcall **)(char *, _QWORD, _QWORD))(*(_QWORD *)p_mNext + 56i64))(p_mNext, dimType, 0i64);
  }
}

// File Line: 2485
// RVA: 0xA31F20
void __fastcall UFG::UIScreenManagerBase::setFontScale(UFG::UIScreenManagerBase *this, float scale)
{
  UFG::UIGfxTranslator *m_translator; // rcx

  m_translator = this->m_translator;
  if ( m_translator )
  {
    m_translator->mFontScale = scale;
    UFG::UIGfxTranslator::createFontMap(m_translator);
  }
}

