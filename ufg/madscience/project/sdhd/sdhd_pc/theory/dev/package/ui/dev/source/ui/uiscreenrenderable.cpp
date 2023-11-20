// File Line: 65
// RVA: 0xA23ED0
void __fastcall UFG::UIScreenRenderable::~UIScreenRenderable(UFG::UIScreenRenderable *this)
{
  UFG::UIScreenRenderable *v1; // rbx
  Illusion::Target *v2; // rcx
  Scaleform::GFx::Resource *v3; // rcx
  Scaleform::GFx::Movie *v4; // rcx
  Scaleform::GFx::Movie *v5; // rcx
  Scaleform::GFx::Resource *v6; // rcx

  v1 = this;
  this->vfptr = (UFG::UIScreenRenderableVtbl *)&UFG::UIScreenRenderable::`vftable';
  if ( this->m_ownsOffscreenTarget )
  {
    v2 = this->m_offscreenTarget;
    if ( v2 )
    {
      Illusion::DeleteTarget(v2, 1);
      v1->m_offscreenTarget = 0i64;
      v1->m_ownsOffscreenTarget = 0;
    }
  }
  v3 = (Scaleform::GFx::Resource *)&v1->m_movieDef.pObject->vfptr;
  if ( v3 )
    Scaleform::GFx::Resource::Release(v3);
  v1->m_movieDef.pObject = 0i64;
  v4 = v1->m_movie.pObject;
  if ( v4 )
    Scaleform::GFx::Movie::Release(v4);
  v1->m_movie.pObject = 0i64;
  v5 = v1->m_movie.pObject;
  if ( v5 )
    Scaleform::GFx::Movie::Release(v5);
  v6 = (Scaleform::GFx::Resource *)&v1->m_movieDef.pObject->vfptr;
  if ( v6 )
    Scaleform::GFx::Resource::Release(v6);
}

// File Line: 78
// RVA: 0xA274E0
void __fastcall UFG::UIScreenRenderable::Load(UFG::UIScreenRenderable *this)
{
  UFG::UIScreenRenderable *v1; // rsi
  Scaleform::GFx::MovieDefImpl *v2; // rbx
  Scaleform::GFx::Resource *v3; // rcx
  UFG::UIThreadCommandQueue *v4; // rdx
  Scaleform::GFx::Movie *v5; // rbx
  Scaleform::GFx::Movie *v6; // rcx
  Scaleform::GFx::MovieDef *v7; // rbx
  UFG::UIScreenManager *v8; // rdi
  int height; // er8
  Scaleform::GFx::Value value; // [rsp+38h] [rbp-59h]
  int v11; // [rsp+68h] [rbp-29h]
  __int64 v12; // [rsp+70h] [rbp-21h]
  __int64 v13; // [rsp+78h] [rbp-19h]
  __int64 v14; // [rsp+80h] [rbp-11h]
  __int64 v15; // [rsp+88h] [rbp-9h]
  __int64 v16; // [rsp+90h] [rbp-1h]
  __int64 v17; // [rsp+98h] [rbp+7h]
  __int64 v18; // [rsp+A0h] [rbp+Fh]
  float v19; // [rsp+A8h] [rbp+17h]
  __int64 v20; // [rsp+ACh] [rbp+1Bh]
  __int64 v21; // [rsp+B4h] [rbp+23h]
  __int64 v22; // [rsp+BCh] [rbp+2Bh]
  __int64 v23; // [rsp+C8h] [rbp+37h]

  v23 = -2i64;
  v1 = this;
  v2 = Scaleform::GFx::Loader::CreateMovie(this->mLoader, this->m_fileName, 0, 0i64);
  v3 = (Scaleform::GFx::Resource *)&v1->m_movieDef.pObject->vfptr;
  if ( v3 )
    Scaleform::GFx::Resource::Release(v3);
  v1->m_movieDef.pObject = (Scaleform::GFx::MovieDef *)&v2->vfptr;
  if ( v2 )
  {
    v4 = UFG::UIScreenManager::s_instance->mThreadCommandQueue;
    v11 = 0;
    v12 = 16i64;
    v13 = 0x2000i64;
    v14 = 0x2000i64;
    v15 = -1i64;
    v16 = 0i64;
    v17 = 0i64;
    v19 = FLOAT_0_25;
    v20 = -1i64;
    v21 = -1i64;
    v22 = -1i64;
    v18 = 0i64;
    v5 = (Scaleform::GFx::Movie *)((__int64 (__fastcall *)(Scaleform::GFx::MovieDefImpl *, int *, _QWORD, _QWORD, UFG::UIThreadCommandQueue *))v2->vfptr[6].__vecDelDtor)(
                                    v2,
                                    &v11,
                                    0i64,
                                    0i64,
                                    v4);
    v6 = v1->m_movie.pObject;
    if ( v6 )
      Scaleform::GFx::Movie::Release(v6);
    v1->m_movie.pObject = v5;
    value.pObjectInterface = 0i64;
    value.Type = 6;
    *(_QWORD *)&value.mValue.NValue = "true";
    Scaleform::GFx::Movie::SetVariable(v5, "_global.noInvisibleAdvance", &value, 1i64);
    if ( ((unsigned int)value.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        *(_QWORD *)&value.mValue.NValue);
      value.pObjectInterface = 0i64;
    }
    value.Type = 0;
    ((void (*)(void))v1->m_movie.pObject->vfptr[33].__vecDelDtor)();
    if ( !v1->m_offscreenTarget )
    {
      v7 = v1->m_movieDef.pObject;
      v8 = UFG::UIScreenManager::s_instance;
      v7->vfptr[1].GetResourceReport((Scaleform::GFx::Resource *)&v1->m_movieDef.pObject->vfptr);
      v7->vfptr[1].GetResourceTypeCode((Scaleform::GFx::Resource *)&v7->vfptr);
      v8->m_flashWidth = (signed int)0.25;
      v8->m_flashHeight = (signed int)0.25;
    }
    v1->m_width = Render::GetBackBufferTarget()->mWidth;
    height = Render::GetBackBufferTarget()->mHeight;
    v1->m_height = height;
    UFG::UIScreenRenderable::setViewport(v1, v1->m_width, height, 0, 0, v1->m_width, height);
    v1->mIsLoaded = 1;
  }
}

// File Line: 124
// RVA: 0xA32110
void __fastcall UFG::UIScreenRenderable::setViewport(UFG::UIScreenRenderable *this, int bufferWidth, int bufferHeight, int x, int y, int width, int height)
{
  int v7; // er10
  int v8; // edi
  UFG::UIScreenRenderable *v9; // rbx
  unsigned __int64 v10; // rdx
  Illusion::Target *v11; // rcx
  signed int v12; // eax
  Illusion::Target *v13; // rcx
  int v14; // [rsp+20h] [rbp-48h]
  int v15; // [rsp+24h] [rbp-44h]
  int v16; // [rsp+28h] [rbp-40h]
  int v17; // [rsp+2Ch] [rbp-3Ch]
  int v18; // [rsp+30h] [rbp-38h]
  int v19; // [rsp+34h] [rbp-34h]
  __int64 v20; // [rsp+38h] [rbp-30h]
  __int64 v21; // [rsp+40h] [rbp-28h]
  int v22; // [rsp+48h] [rbp-20h]
  int v23; // [rsp+4Ch] [rbp-1Ch]
  float v24; // [rsp+50h] [rbp-18h]

  v7 = width;
  v8 = bufferWidth;
  v9 = this;
  this->m_x = x;
  this->m_y = y;
  if ( width <= 0 )
    v7 = this->m_movieInfo.Width;
  v10 = (unsigned int)height;
  this->m_width = v7;
  if ( height <= 0 )
    v10 = (unsigned int)this->m_movieInfo.Height;
  this->m_height = v10;
  v11 = this->m_offscreenTarget;
  v12 = 2;
  v14 = v8;
  if ( v11 )
    v12 = 3;
  v15 = bufferHeight;
  v16 = x;
  v17 = y;
  v18 = v7;
  v21 = 0i64;
  v20 = 0i64;
  v19 = v10;
  v22 = v12;
  v24 = 1.0;
  v23 = 1065353216;
  if ( v11 )
    v24 = 1.0;
  else
    v24 = UFG::Wheelie_EngineState::GetDefaultLoad(0i64, (AkAudioFormat *)v10);
  v9->m_movie.pObject->vfptr[12].__vecDelDtor(
    (Scaleform::RefCountImplCore *)&v9->m_movie.pObject->vfptr,
    (unsigned int)&v14);
  if ( v9->m_ownsOffscreenTarget )
  {
    v13 = v9->m_offscreenTarget;
    if ( v13 )
    {
      Illusion::DeleteTarget(v13, 1);
      v9->m_offscreenTarget = 0i64;
      v9->m_ownsOffscreenTarget = 0;
    }
  }
}

// File Line: 150
// RVA: 0xA31EC0
void __fastcall UFG::UIScreenRenderable::setBuffer(UFG::UIScreenRenderable *this, Illusion::Target *target)
{
  Illusion::Target *v2; // rdi
  UFG::UIScreenRenderable *v3; // rbx
  Illusion::Target *v4; // rcx

  v2 = target;
  v3 = this;
  if ( this->m_ownsOffscreenTarget )
  {
    v4 = this->m_offscreenTarget;
    if ( v4 )
    {
      Illusion::DeleteTarget(v4, 1);
      v3->m_offscreenTarget = 0i64;
      v3->m_offscreenTarget = v2;
      v3->m_ownsOffscreenTarget = 0;
    }
    else
    {
      v3->m_offscreenTarget = target;
    }
  }
  else
  {
    this->m_offscreenTarget = target;
  }
}

// File Line: 253
// RVA: 0xA319F0
void __fastcall UFG::UIScreenRenderable::render(UFG::UIScreenRenderable *this)
{
  Scaleform::GFx::Resource **v1; // rbx
  hkDynamicClassNameRegistry **v2; // rax
  Scaleform::Render::ContextImpl::RenderNotify *v3; // rax
  bool v4; // bl
  Scaleform::Render::Renderer2D *v5; // rbx
  Scaleform::Render::TreeRoot *v6; // rax
  Scaleform::Render::ContextImpl::RTHandle v7; // [rsp+40h] [rbp+8h]
  Scaleform::Render::RenderBuffer *v8; // [rsp+48h] [rbp+10h]

  if ( this->m_shouldRender )
  {
    v7.pData.pObject = 0i64;
    v1 = (Scaleform::GFx::Resource **)((__int64 (__cdecl *)(Scaleform::GFx::Movie *))this->m_movie.pObject->vfptr[26].__vecDelDtor)(this->m_movie.pObject);
    if ( *v1 )
      Scaleform::Render::RenderBuffer::AddRef(*v1);
    if ( v7.pData.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v7.pData.pObject);
    v7.pData.pObject = (Scaleform::Render::ContextImpl::RTHandle::HandleData *)*v1;
    v2 = (hkDynamicClassNameRegistry **)UFG::UIScreenManager::s_instance->vfptr->getRenderer2D(
                                          (UFG::UIScreenManagerBase *)UFG::UIScreenManager::s_instance,
                                          (Scaleform::Ptr<Scaleform::Render::Renderer2D> *)&v8);
    v3 = (Scaleform::Render::ContextImpl::RenderNotify *)SSUnaryParam::get_expected_type(*v2);
    v4 = Scaleform::Render::ContextImpl::RTHandle::NextCapture(&v7, v3);
    if ( v8 )
      Scaleform::RefCountImpl::Release(v8);
    if ( v4 )
    {
      v5 = *(Scaleform::Render::Renderer2D **)UFG::UIScreenManager::s_instance->vfptr->getRenderer2D(
                                                (UFG::UIScreenManagerBase *)UFG::UIScreenManager::s_instance,
                                                (Scaleform::Ptr<Scaleform::Render::Renderer2D> *)&v8);
      v6 = (Scaleform::Render::TreeRoot *)Scaleform::Render::ContextImpl::RTHandle::GetRenderEntry(&v7);
      Scaleform::Render::Renderer2D::Display(v5, v6);
      if ( v8 )
        Scaleform::RefCountImpl::Release(v8);
    }
    Scaleform::Render::ContextImpl::RTHandle::~RTHandle(&v7);
  }
}

// File Line: 291
// RVA: 0xA31C70
void __fastcall UFG::UIScreenRenderable::replaceTexture(UFG::UIScreenRenderable *this, const char *flaTexture, Illusion::Texture *engineTexture)
{
  Illusion::Texture *v3; // rdi
  const char *v4; // rbx
  UFG::UIScreenRenderable *v5; // r13
  __int64 v6; // rax
  __int64 v7; // rax
  Scaleform::GFx::ImageResource *v8; // rsi
  Scaleform::Render::ImageBase *v9; // rcx
  unsigned int v10; // er15
  Scaleform::Render::ImageBase *v11; // rcx
  unsigned int v12; // er14
  UFG::UIGfxTextureManager *v13; // rbp
  __int64 v14; // rbx
  __int64 v15; // rt1
  __int64 v16; // rax
  Scaleform::Render::Texture *v17; // rax
  Scaleform::Render::Texture *v18; // rbp
  Scaleform::Render::Image *v19; // rax
  Scaleform::Render::Image *v20; // rdi
  char v21; // [rsp+28h] [rbp-60h]
  __int64 v22; // [rsp+30h] [rbp-58h]
  __int64 v23; // [rsp+38h] [rbp-50h]
  Scaleform::Render::Texture *v24; // [rsp+40h] [rbp-48h]
  Scaleform::Render::Size<unsigned long> size; // [rsp+90h] [rbp+8h]
  char v26; // [rsp+A8h] [rbp+20h]

  v3 = engineTexture;
  v4 = flaTexture;
  v5 = this;
  v6 = ((__int64 (__cdecl *)(Scaleform::GFx::Movie *))this->m_movie.pObject->vfptr[1].__vecDelDtor)(this->m_movie.pObject);
  v7 = (*(__int64 (__fastcall **)(__int64, const char *))(*(_QWORD *)v6 + 216i64))(v6, v4);
  v8 = (Scaleform::GFx::ImageResource *)v7;
  if ( v7 && ((*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v7 + 16i64))(v7) & 0xFF00) == 256 && v3 )
  {
    v9 = v8->pImage;
    if ( v9 )
      v10 = *(_DWORD *)((__int64)v9->vfptr[5].__vecDelDtor(
                                   (Scaleform::RefCountImplCore *)&v9->vfptr,
                                   (unsigned int)&v26)
                      + 4);
    else
      v10 = 0;
    v11 = v8->pImage;
    if ( v11 )
      v12 = *(_DWORD *)v11->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v11->vfptr, (unsigned int)&v21);
    else
      v12 = 0;
    v13 = (UFG::UIGfxTextureManager *)((__int64 (*)(void))UFG::UIScreenManager::s_instance->mRenderHAL->vfptr[61].__vecDelDtor)();
    v14 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
            Scaleform::Memory::pGlobalHeap,
            56i64);
    v22 = v14;
    if ( v14 )
    {
      *(_QWORD *)v14 = &Scaleform::RefCountImplCore::`vftable';
      *(_DWORD *)(v14 + 8) = 1;
      *(_QWORD *)v14 = &Scaleform::RefCountVImpl::`vftable';
      *(_QWORD *)v14 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::`vftable';
      *(_QWORD *)v14 = &Scaleform::RefCountBaseV<Scaleform::Render::Image,3>::`vftable';
      *(_QWORD *)v14 = &Scaleform::Render::ImageBase::`vftable';
      *(_QWORD *)v14 = &Scaleform::Render::Image::`vftable';
      *(_QWORD *)(v14 + 16) = 0i64;
      v15 = *(_QWORD *)(v14 + 16);
      v16 = *(_QWORD *)(v14 + 16);
      *(_QWORD *)(v14 + 24) = 0i64;
      *(_QWORD *)(v14 + 32) = 0i64;
      *(_QWORD *)v14 = &Scaleform::Render::TextureImage::`vftable';
      *(_DWORD *)(v14 + 40) = 1;
      *(_DWORD *)(v14 + 44) = v12;
      *(_DWORD *)(v14 + 48) = v10;
      *(_DWORD *)(v14 + 52) = 0;
    }
    else
    {
      v14 = 0i64;
    }
    v23 = v14;
    size.Width = v12;
    size.Height = v10;
    v17 = UFG::UIGfxTextureManager::CreateTexture(
            v13,
            v3,
            (Scaleform::Render::Size<unsigned long>)&size,
            (Scaleform::Render::ImageBase *)v14);
    v18 = v17;
    v24 = v17;
    v19 = (Scaleform::Render::Image *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                        Scaleform::Memory::pGlobalHeap,
                                        56i64);
    v20 = v19;
    size = (Scaleform::Render::Size<unsigned long>)v19;
    if ( v19 )
    {
      Scaleform::Render::Image::Image(v19, v18, 0i64);
      v20->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::TextureImage::`vftable';
      LODWORD(v20[1].vfptr) = 1;
      HIDWORD(v20[1].vfptr) = v12;
      v20[1].RefCount = v10;
      *((_DWORD *)&v20[1].RefCount + 1) = 0;
    }
    else
    {
      v20 = 0i64;
    }
    Scaleform::GFx::ImageResource::SetImage(v8, v20);
    ((void (*)(void))v5->m_movie.pObject->vfptr[65].__vecDelDtor)();
    if ( v18 )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v18);
    if ( v14 )
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v14 + 16i64))(v14);
  }
}

