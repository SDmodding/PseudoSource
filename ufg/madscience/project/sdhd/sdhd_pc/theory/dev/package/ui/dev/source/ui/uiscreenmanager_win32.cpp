// File Line: 39
// RVA: 0xA334A0
void __fastcall UFG::UIScreenManager::UIScreenManager(UFG::UIScreenManager *this, UFG::UIScreenFactory *screenFactory)
{
  Scaleform::GFx::FontProviderWin32 *v3; // rdi
  HDC DC; // rax
  Scaleform::GFx::State *v5; // rax
  Scaleform::GFx::State *v6; // rdi
  Illusion *v7; // rcx

  UFG::UIScreenManagerBase::UIScreenManagerBase(this, screenFactory);
  this->vfptr = (UFG::UIScreenManagerBaseVtbl *)&UFG::UIScreenManager::`vftable;
  UFG::UIScreenManagerBase::baseInit(this);
  v3 = (Scaleform::GFx::FontProviderWin32 *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                              Scaleform::Memory::pGlobalHeap,
                                              32i64);
  if ( v3 )
  {
    DC = GetDC(0i64);
    Scaleform::GFx::FontProviderWin32::FontProviderWin32(v3, DC);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  this->m_gfxMovieLoader->UFG::UIScreenManagerBase::vfptr->SetState(
    this->m_gfxMovieLoader,
    State_ProjectionMatrix3D|0x10,
    v6);
  Illusion::AddRenderThreadCommand(
    RTCMD_CALLBACK,
    (UFG::allocator::free_link *)UFG::UIScreenManager::initHALCbk,
    (UFG::allocator::free_link *)this,
    0i64);
  Illusion::WaitForRenderThread(v7);
  if ( v6 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v6);
}

// File Line: 59
// RVA: 0xA33FA0
// attributes: thunk
void __fastcall UFG::UIScreenManager::initHALCbk(UFG::UIScreenManager *screenMan)
{
  UFG::UIScreenManager::initHAL(screenMan);
}

// File Line: 67
// RVA: 0xA33BF0
void __fastcall UFG::UIScreenManager::initHAL(UFG::UIScreenManager *this)
{
  Scaleform::Render::D3D1x::HAL *v2; // rax
  Scaleform::GFx::State *v3; // r15
  Scaleform::Render::D3D1x::HAL *v4; // rax
  Scaleform::Render::Renderer2D *v5; // rax
  Scaleform::Render::Renderer2D *v6; // rax
  Scaleform::Render::Renderer2D *v7; // rbx
  Scaleform::Render::RenderBuffer *pObject; // rcx
  UFG::UIGfxTextureManager *v9; // r12
  ID3D11DeviceContext *v10; // rdi
  ID3D11Device *v11; // rsi
  UFG::UIThreadCommandQueue *commandQueue; // rbx
  void *CurrentThreadID; // rax
  Illusion::Target *BackBufferTarget; // rax
  __int64 v15; // rbx
  __int64 v16; // rdi
  ID3D11Device *v17; // rbx
  Scaleform::Render::RenderBuffer *mTextureManager; // rbx
  UFG::UIGfxImageCreator *v19; // rbx
  Scaleform::GFx::Resource *v20; // rax
  Scaleform::GFx::State *v21; // rax
  Scaleform::Render::MeshCacheConfig *MeshCacheConfig; // rax
  Scaleform::Render::GlyphCache *GlyphCacheConfig; // rax
  int v24[10]; // [rsp+30h] [rbp-A8h] BYREF
  void *v25; // [rsp+58h] [rbp-80h]
  Scaleform::Render::RenderBuffer *v26; // [rsp+60h] [rbp-78h]
  Scaleform::Render::RenderBuffer *v27; // [rsp+68h] [rbp-70h]
  __int64 v28[3]; // [rsp+70h] [rbp-68h] BYREF
  __int64 v29[6]; // [rsp+88h] [rbp-50h] BYREF
  int v30; // [rsp+B8h] [rbp-20h]
  int v31; // [rsp+BCh] [rbp-1Ch]
  int v32; // [rsp+C0h] [rbp-18h]
  int v33; // [rsp+C4h] [rbp-14h]
  int v34; // [rsp+C8h] [rbp-10h]
  __int64 v35; // [rsp+D8h] [rbp+0h]
  void *v36; // [rsp+118h] [rbp+40h]

  v35 = -2i64;
  v2 = (Scaleform::Render::D3D1x::HAL *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                          Scaleform::Memory::pGlobalHeap,
                                          256416i64,
                                          0i64);
  v36 = v2;
  v3 = 0i64;
  if ( v2 )
    Scaleform::Render::D3D1x::HAL::HAL(v2, this->mThreadCommandQueue);
  else
    v4 = 0i64;
  this->mRenderHAL = v4;
  v5 = (Scaleform::Render::Renderer2D *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                          Scaleform::Memory::pGlobalHeap,
                                          24i64);
  v36 = v5;
  if ( v5 )
  {
    Scaleform::Render::Renderer2D::Renderer2D(v5, this->mRenderHAL);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  pObject = (Scaleform::Render::RenderBuffer *)this->mRenderer2D.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->mRenderer2D.pObject = v7;
  this->mThreadCommandQueue->pHAL = this->mRenderHAL;
  this->mThreadCommandQueue->pR2D = this->mRenderer2D.pObject;
  v9 = (UFG::UIGfxTextureManager *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                     Scaleform::Memory::pGlobalHeap,
                                     552i64,
                                     0i64);
  v36 = v9;
  if ( v9 )
  {
    v10 = *(ID3D11DeviceContext **)(*((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 104i64);
    v11 = UFG::gD3D11Device;
    commandQueue = this->mThreadCommandQueue;
    CurrentThreadID = UFG::qGetCurrentThreadID();
    Scaleform::Render::D3D1x::TextureManager::TextureManager(v9, v11, v10, CurrentThreadID, commandQueue, 0i64);
    v9->Scaleform::Render::D3D1x::TextureManager::Scaleform::Render::TextureManager::Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&UFG::UIGfxTextureManager::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>};
    v9->Scaleform::Render::D3D1x::TextureManager::Scaleform::Render::TextureManager::Scaleform::Render::ImageUpdateSync::vfptr = (Scaleform::Render::ImageUpdateSyncVtbl *)&UFG::UIGfxTextureManager::`vftable{for `Scaleform::Render::ImageUpdateSync};
  }
  else
  {
    v9 = 0i64;
  }
  this->mTextureManager = v9;
  BackBufferTarget = Render::GetBackBufferTarget();
  v15 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index);
  (*(void (__fastcall **)(_QWORD, __int64, ID3D11RenderTargetView *(*)[4], ID3D11DepthStencilView *))(**(_QWORD **)(v15 + 104) + 264i64))(
    *(_QWORD *)(v15 + 104),
    1i64,
    BackBufferTarget->mTargetPlat->mRenderTargetView,
    BackBufferTarget->mTargetPlat->mDepthStencilView);
  v16 = *(_QWORD *)(v15 + 104);
  v17 = UFG::gD3D11Device;
  v25 = UFG::qGetCurrentThreadID();
  v26 = 0i64;
  v27 = 0i64;
  v28[0] = 256i64;
  v28[1] = (__int64)v17;
  v28[2] = v16;
  mTextureManager = (Scaleform::Render::RenderBuffer *)this->mTextureManager;
  if ( mTextureManager )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)this->mTextureManager);
  v26 = mTextureManager;
  this->mRenderHAL->vfptr[98].__vecDelDtor(this->mRenderHAL, (unsigned int)v28);
  v19 = (UFG::UIGfxImageCreator *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                    Scaleform::Memory::pGlobalHeap,
                                    32i64);
  v36 = v19;
  if ( v19 )
  {
    v20 = (Scaleform::GFx::Resource *)((__int64 (__fastcall *)(Scaleform::Render::D3D1x::HAL *))this->mRenderHAL->vfptr[61].__vecDelDtor)(this->mRenderHAL);
    UFG::UIGfxImageCreator::UIGfxImageCreator(v19, v20);
    v3 = v21;
  }
  this->m_gfxMovieLoader->UFG::UIScreenManagerBase::vfptr->SetState(
    this->m_gfxMovieLoader,
    State_OrigNodeBounds|State_MaskNode,
    v3);
  v29[5] = 0x40000i64;
  v30 = 24;
  v31 = 5;
  v32 = 0x2000;
  v33 = 0x4000;
  v34 = 6144;
  v29[0] = 3145728i64;
  v29[1] = 12582912i64;
  v29[2] = 3145728i64;
  v29[3] = 0x400000i64;
  v29[4] = 0x200000i64;
  MeshCacheConfig = Scaleform::Render::Renderer2D::GetMeshCacheConfig(this->mRenderer2D.pObject);
  MeshCacheConfig->vfptr->SetParams(MeshCacheConfig, (Scaleform::Render::MeshCacheParams *)v29);
  v24[4] = 2;
  v24[5] = 256;
  v24[6] = 512;
  v24[7] = 1065353216;
  v24[8] = 500;
  *(float *)&v24[9] = FLOAT_0_25;
  v25 = (void *)__PAIR64__(LODWORD(FLOAT_0_0099999998), LODWORD(FLOAT_0_045000002));
  LODWORD(v26) = 1065353216;
  WORD2(v26) = 257;
  BYTE6(v26) = 1;
  v24[0] = 2048;
  v24[1] = 2048;
  v24[2] = 1;
  v24[3] = 48;
  GlyphCacheConfig = Scaleform::Render::Renderer2D::GetGlyphCacheConfig(this->mRenderer2D.pObject);
  GlyphCacheConfig->Scaleform::RefCountBase<Scaleform::Render::GlyphCache,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[1].__vecDelDtor(
    GlyphCacheConfig,
    (unsigned int)v24);
  if ( v27 )
    Scaleform::RefCountImpl::Release(v27);
  if ( v26 )
    Scaleform::RefCountImpl::Release(v26);
}

// File Line: 127
// RVA: 0xA340D0
// attributes: thunk
void __fastcall UFG::UIScreenManager::update(UFG::UIScreenManager *this, float elapsed)
{
  UFG::UIScreenManagerBase::baseUpdate(this, elapsed);
}

// File Line: 136
// RVA: 0xA33FC0
void __fastcall UFG::UIScreenManager::render(UFG::UIScreenManager *this)
{
  Scaleform::GFx::Resource **DisplayHandle; // rbx
  hkDynamicClassNameRegistry **v3; // rax
  Scaleform::Render::ContextImpl::RenderNotify *expected_type; // rax
  bool v5; // bl
  Scaleform::Render::Renderer2D *pObject; // rbx
  Scaleform::Render::TreeRoot *RenderEntry; // rax
  Scaleform::Render::ContextImpl::RTHandle v8; // [rsp+48h] [rbp+10h] BYREF
  Scaleform::Render::RenderBuffer *v9; // [rsp+50h] [rbp+18h] BYREF

  if ( UFG::gTweakerRenderUI && this->m_renderUI )
  {
    v8.pData.pObject = 0i64;
    DisplayHandle = (Scaleform::GFx::Resource **)Scaleform::GFx::DrawTextManager::GetDisplayHandle(this->m_gfxDrawTextManager);
    if ( *DisplayHandle )
      Scaleform::Render::RenderBuffer::AddRef(*DisplayHandle);
    if ( v8.pData.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v8.pData.pObject);
    v8.pData.pObject = (Scaleform::Render::ContextImpl::RTHandle::HandleData *)*DisplayHandle;
    v3 = (hkDynamicClassNameRegistry **)UFG::UIScreenManager::s_instance->vfptr->getRenderer2D(
                                          UFG::UIScreenManager::s_instance,
                                          &v9);
    expected_type = (Scaleform::Render::ContextImpl::RenderNotify *)SSUnaryParam::get_expected_type(*v3);
    v5 = Scaleform::Render::ContextImpl::RTHandle::NextCapture(&v8, expected_type);
    if ( v9 )
      Scaleform::RefCountImpl::Release(v9);
    if ( v5 )
    {
      pObject = UFG::UIScreenManager::s_instance->vfptr->getRenderer2D(UFG::UIScreenManager::s_instance, &v9)->pObject;
      RenderEntry = (Scaleform::Render::TreeRoot *)Scaleform::Render::ContextImpl::RTHandle::GetRenderEntry(&v8);
      Scaleform::Render::Renderer2D::Display(pObject, RenderEntry);
      if ( v9 )
        Scaleform::RefCountImpl::Release(v9);
    }
    UFG::UIScreenManagerBase::renderScreens(this);
    UFG::UIScreenManagerBase::renderOverlays(this);
    Scaleform::Render::ContextImpl::RTHandle::~RTHandle(&v8);
  }
}

