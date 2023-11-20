// File Line: 39
// RVA: 0xA334A0
void __fastcall UFG::UIScreenManager::UIScreenManager(UFG::UIScreenManager *this, UFG::UIScreenFactory *screenFactory)
{
  UFG::UIScreenManager *v2; // rbx
  Scaleform::GFx::FontProviderWin32 *v3; // rdi
  HDC v4; // rax
  Scaleform::Render::RenderBuffer *v5; // rax
  Scaleform::Render::RenderBuffer *v6; // rdi
  Illusion *v7; // rcx

  v2 = this;
  UFG::UIScreenManagerBase::UIScreenManagerBase((UFG::UIScreenManagerBase *)&this->vfptr, screenFactory);
  v2->vfptr = (UFG::UIScreenManagerBaseVtbl *)&UFG::UIScreenManager::`vftable;
  UFG::UIScreenManagerBase::baseInit((UFG::UIScreenManagerBase *)&v2->vfptr);
  v3 = (Scaleform::GFx::FontProviderWin32 *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                              Scaleform::Memory::pGlobalHeap,
                                              32i64);
  if ( v3 )
  {
    v4 = GetDC(0i64);
    Scaleform::GFx::FontProviderWin32::FontProviderWin32(v3, v4);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  v2->m_gfxMovieLoader->vfptr->SetState(
    (Scaleform::GFx::StateBag *)&v2->m_gfxMovieLoader->vfptr,
    State_ProjectionMatrix3D|0x10,
    (Scaleform::GFx::State *)v6);
  Illusion::AddRenderThreadCommand(RTCMD_CALLBACK, UFG::UIScreenManager::initHALCbk, v2, 0i64);
  Illusion::WaitForRenderThread(v7);
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
}

// File Line: 59
// RVA: 0xA33FA0
void __fastcall UFG::UIScreenManager::initHALCbk(void *screenMan)
{
  UFG::UIScreenManager::initHAL((UFG::UIScreenManager *)screenMan);
}

// File Line: 67
// RVA: 0xA33BF0
void __fastcall UFG::UIScreenManager::initHAL(UFG::UIScreenManager *this)
{
  UFG::UIScreenManager *v1; // r14
  Scaleform::Render::D3D1x::HAL *v2; // rax
  Scaleform::GFx::State *v3; // r15
  Scaleform::Render::D3D1x::HAL *v4; // rax
  Scaleform::Render::Renderer2D *v5; // rax
  Scaleform::Render::Renderer2D *v6; // rax
  Scaleform::Render::Renderer2D *v7; // rbx
  Scaleform::Render::RenderBuffer *v8; // rcx
  Scaleform::Render::D3D1x::TextureManager *v9; // r12
  ID3D11DeviceContext *v10; // rdi
  ID3D11Device *v11; // rsi
  Scaleform::Render::ThreadCommandQueue *commandQueue; // rbx
  void *v13; // rax
  Illusion::Target *v14; // rax
  __int64 v15; // rbx
  __int64 v16; // rdi
  ID3D11Device *v17; // rbx
  Scaleform::Render::RenderBuffer *v18; // rbx
  UFG::UIGfxImageCreator *v19; // rbx
  Scaleform::Render::TextureManager *v20; // rax
  Scaleform::GFx::State *v21; // rax
  Scaleform::Render::MeshCacheConfig *v22; // rax
  Scaleform::Render::GlyphCache *v23; // rax
  int v24; // [rsp+30h] [rbp-A8h]
  int v25; // [rsp+34h] [rbp-A4h]
  int v26; // [rsp+38h] [rbp-A0h]
  int v27; // [rsp+3Ch] [rbp-9Ch]
  int v28; // [rsp+40h] [rbp-98h]
  int v29; // [rsp+44h] [rbp-94h]
  int v30; // [rsp+48h] [rbp-90h]
  int v31; // [rsp+4Ch] [rbp-8Ch]
  int v32; // [rsp+50h] [rbp-88h]
  float v33; // [rsp+54h] [rbp-84h]
  void *v34; // [rsp+58h] [rbp-80h]
  Scaleform::Render::RenderBuffer *v35; // [rsp+60h] [rbp-78h]
  Scaleform::Render::RenderBuffer *v36; // [rsp+68h] [rbp-70h]
  __int64 v37; // [rsp+70h] [rbp-68h]
  ID3D11Device *v38; // [rsp+78h] [rbp-60h]
  __int64 v39; // [rsp+80h] [rbp-58h]
  __int64 v40; // [rsp+88h] [rbp-50h]
  __int64 v41; // [rsp+90h] [rbp-48h]
  __int64 v42; // [rsp+98h] [rbp-40h]
  __int64 v43; // [rsp+A0h] [rbp-38h]
  __int64 v44; // [rsp+A8h] [rbp-30h]
  __int64 v45; // [rsp+B0h] [rbp-28h]
  int v46; // [rsp+B8h] [rbp-20h]
  int v47; // [rsp+BCh] [rbp-1Ch]
  int v48; // [rsp+C0h] [rbp-18h]
  int v49; // [rsp+C4h] [rbp-14h]
  int v50; // [rsp+C8h] [rbp-10h]
  __int64 v51; // [rsp+D8h] [rbp+0h]
  void *v52; // [rsp+118h] [rbp+40h]

  v51 = -2i64;
  v1 = this;
  v2 = (Scaleform::Render::D3D1x::HAL *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                          Scaleform::Memory::pGlobalHeap,
                                          256416ui64,
                                          0i64);
  v52 = v2;
  v3 = 0i64;
  if ( v2 )
    Scaleform::Render::D3D1x::HAL::HAL(v2, (Scaleform::Render::ThreadCommandQueue *)&v1->mThreadCommandQueue->vfptr);
  else
    v4 = 0i64;
  v1->mRenderHAL = v4;
  v5 = (Scaleform::Render::Renderer2D *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                          Scaleform::Memory::pGlobalHeap,
                                          24i64);
  v52 = v5;
  if ( v5 )
  {
    Scaleform::Render::Renderer2D::Renderer2D(v5, (Scaleform::Render::HAL *)&v1->mRenderHAL->vfptr);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  v8 = (Scaleform::Render::RenderBuffer *)v1->mRenderer2D.pObject;
  if ( v8 )
    Scaleform::RefCountImpl::Release(v8);
  v1->mRenderer2D.pObject = v7;
  v1->mThreadCommandQueue->pHAL = (Scaleform::Render::HAL *)&v1->mRenderHAL->vfptr;
  v1->mThreadCommandQueue->pR2D = v1->mRenderer2D.pObject;
  v9 = (Scaleform::Render::D3D1x::TextureManager *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                                     Scaleform::Memory::pGlobalHeap,
                                                     552ui64,
                                                     0i64);
  v52 = v9;
  if ( v9 )
  {
    v10 = *(ID3D11DeviceContext **)(*((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 104i64);
    v11 = UFG::gD3D11Device;
    commandQueue = (Scaleform::Render::ThreadCommandQueue *)&v1->mThreadCommandQueue->vfptr;
    v13 = UFG::qGetCurrentThreadID();
    Scaleform::Render::D3D1x::TextureManager::TextureManager(v9, v11, v10, v13, commandQueue, 0i64);
    v9->vfptr = (Scaleform::RefCountImplCoreVtbl *)&UFG::UIGfxTextureManager::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>};
    v9->vfptr = (Scaleform::Render::ImageUpdateSyncVtbl *)&UFG::UIGfxTextureManager::`vftable{for `Scaleform::Render::ImageUpdateSync};
  }
  else
  {
    v9 = 0i64;
  }
  v1->mTextureManager = (UFG::UIGfxTextureManager *)v9;
  v14 = Render::GetBackBufferTarget();
  v15 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index);
  (*(void (__fastcall **)(_QWORD, signed __int64, ID3D11RenderTargetView *(*)[4], ID3D11DepthStencilView *))(**(_QWORD **)(v15 + 104) + 264i64))(
    *(_QWORD *)(v15 + 104),
    1i64,
    v14->mTargetPlat->mRenderTargetView,
    v14->mTargetPlat->mDepthStencilView);
  v16 = *(_QWORD *)(v15 + 104);
  v17 = UFG::gD3D11Device;
  v37 = 0i64;
  v34 = UFG::qGetCurrentThreadID();
  v35 = 0i64;
  v36 = 0i64;
  LODWORD(v37) = 256;
  v38 = v17;
  v39 = v16;
  v18 = (Scaleform::Render::RenderBuffer *)v1->mTextureManager;
  if ( v18 )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v1->mTextureManager);
  if ( v35 )
    Scaleform::RefCountImpl::Release(v35);
  v35 = v18;
  v1->mRenderHAL->vfptr[98].__vecDelDtor((Scaleform::RefCountImplCore *)&v1->mRenderHAL->vfptr, (unsigned int)&v37);
  v19 = (UFG::UIGfxImageCreator *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                    Scaleform::Memory::pGlobalHeap,
                                    32i64);
  v52 = v19;
  if ( v19 )
  {
    v20 = (Scaleform::Render::TextureManager *)((__int64 (*)(void))v1->mRenderHAL->vfptr[61].__vecDelDtor)();
    UFG::UIGfxImageCreator::UIGfxImageCreator(v19, v20);
    v3 = v21;
  }
  v1->m_gfxMovieLoader->vfptr->SetState(
    (Scaleform::GFx::StateBag *)&v1->m_gfxMovieLoader->vfptr,
    State_OrigNodeBounds|State_MaskNode,
    v3);
  v45 = 0x40000i64;
  v46 = 24;
  v47 = 5;
  v48 = 0x2000;
  v49 = 0x4000;
  v50 = 6144;
  v40 = 3145728i64;
  v41 = 12582912i64;
  v42 = 3145728i64;
  v43 = 0x400000i64;
  v44 = 0x200000i64;
  v22 = Scaleform::Render::Renderer2D::GetMeshCacheConfig(v1->mRenderer2D.pObject);
  v22->vfptr->SetParams(v22, (Scaleform::Render::MeshCacheParams *)&v40);
  v28 = 2;
  v29 = 256;
  v30 = 512;
  v31 = 1065353216;
  v32 = 500;
  v33 = FLOAT_0_25;
  v34 = (void *)__PAIR__(LODWORD(FLOAT_0_0099999998), LODWORD(FLOAT_0_045000002));
  LODWORD(v35) = 1065353216;
  WORD2(v35) = 257;
  BYTE6(v35) = 1;
  v24 = 2048;
  v25 = 2048;
  v26 = 1;
  v27 = 48;
  v23 = Scaleform::Render::Renderer2D::GetGlyphCacheConfig(v1->mRenderer2D.pObject);
  v23->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v23->vfptr, (unsigned int)&v24);
  if ( v36 )
    Scaleform::RefCountImpl::Release(v36);
  if ( v35 )
    Scaleform::RefCountImpl::Release(v35);
}

// File Line: 127
// RVA: 0xA340D0
void __fastcall UFG::UIScreenManager::update(UFG::UIScreenManager *this, float elapsed)
{
  UFG::UIScreenManagerBase::baseUpdate((UFG::UIScreenManagerBase *)&this->vfptr, elapsed);
}

// File Line: 136
// RVA: 0xA33FC0
void __fastcall UFG::UIScreenManager::render(UFG::UIScreenManager *this)
{
  UFG::UIScreenManager *v1; // rdi
  Scaleform::GFx::Resource **v2; // rbx
  hkDynamicClassNameRegistry **v3; // rax
  Scaleform::Render::ContextImpl::RenderNotify *v4; // rax
  bool v5; // bl
  Scaleform::Render::Renderer2D *v6; // rbx
  Scaleform::Render::TreeRoot *v7; // rax
  Scaleform::Render::ContextImpl::RTHandle v8; // [rsp+48h] [rbp+10h]
  Scaleform::Render::RenderBuffer *v9; // [rsp+50h] [rbp+18h]

  v1 = this;
  if ( UFG::gTweakerRenderUI && this->m_renderUI )
  {
    v8.pData.pObject = 0i64;
    v2 = (Scaleform::GFx::Resource **)Scaleform::GFx::DrawTextManager::GetDisplayHandle(this->m_gfxDrawTextManager);
    if ( *v2 )
      Scaleform::Render::RenderBuffer::AddRef(*v2);
    if ( v8.pData.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v8.pData.pObject);
    v8.pData.pObject = (Scaleform::Render::ContextImpl::RTHandle::HandleData *)*v2;
    v3 = (hkDynamicClassNameRegistry **)UFG::UIScreenManager::s_instance->vfptr->getRenderer2D(
                                          (UFG::UIScreenManagerBase *)UFG::UIScreenManager::s_instance,
                                          (Scaleform::Ptr<Scaleform::Render::Renderer2D> *)&v9);
    v4 = (Scaleform::Render::ContextImpl::RenderNotify *)SSUnaryParam::get_expected_type(*v3);
    v5 = Scaleform::Render::ContextImpl::RTHandle::NextCapture(&v8, v4);
    if ( v9 )
      Scaleform::RefCountImpl::Release(v9);
    if ( v5 )
    {
      v6 = *(Scaleform::Render::Renderer2D **)UFG::UIScreenManager::s_instance->vfptr->getRenderer2D(
                                                (UFG::UIScreenManagerBase *)UFG::UIScreenManager::s_instance,
                                                (Scaleform::Ptr<Scaleform::Render::Renderer2D> *)&v9);
      v7 = (Scaleform::Render::TreeRoot *)Scaleform::Render::ContextImpl::RTHandle::GetRenderEntry(&v8);
      Scaleform::Render::Renderer2D::Display(v6, v7);
      if ( v9 )
        Scaleform::RefCountImpl::Release(v9);
    }
    UFG::UIScreenManagerBase::renderScreens((UFG::UIScreenManagerBase *)&v1->vfptr);
    UFG::UIScreenManagerBase::renderOverlays((UFG::UIScreenManagerBase *)&v1->vfptr);
    Scaleform::Render::ContextImpl::RTHandle::~RTHandle(&v8);
  }
}

