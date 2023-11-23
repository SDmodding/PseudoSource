// File Line: 65
// RVA: 0xA23ED0
void __fastcall UFG::UIScreenRenderable::~UIScreenRenderable(UFG::UIScreenRenderable *this)
{
  Illusion::Target *m_offscreenTarget; // rcx
  Scaleform::GFx::MovieDef *pObject; // rcx
  Scaleform::GFx::Movie *v4; // rcx
  Scaleform::GFx::Movie *v5; // rcx
  Scaleform::GFx::MovieDef *v6; // rcx

  this->vfptr = (UFG::UIScreenRenderableVtbl *)&UFG::UIScreenRenderable::`vftable;
  if ( this->m_ownsOffscreenTarget )
  {
    m_offscreenTarget = this->m_offscreenTarget;
    if ( m_offscreenTarget )
    {
      Illusion::DeleteTarget((AMD_HD3D *)m_offscreenTarget, 1);
      this->m_offscreenTarget = 0i64;
      this->m_ownsOffscreenTarget = 0;
    }
  }
  pObject = this->m_movieDef.pObject;
  if ( pObject )
    Scaleform::GFx::Resource::Release(pObject);
  this->m_movieDef.pObject = 0i64;
  v4 = this->m_movie.pObject;
  if ( v4 )
    Scaleform::GFx::Movie::Release(v4);
  this->m_movie.pObject = 0i64;
  v5 = this->m_movie.pObject;
  if ( v5 )
    Scaleform::GFx::Movie::Release(v5);
  v6 = this->m_movieDef.pObject;
  if ( v6 )
    Scaleform::GFx::Resource::Release(v6);
}

// File Line: 78
// RVA: 0xA274E0
void __fastcall UFG::UIScreenRenderable::Load(UFG::UIScreenRenderable *this)
{
  Scaleform::GFx::MovieDefImpl *Movie; // rbx
  Scaleform::GFx::MovieDef *pObject; // rcx
  UFG::UIThreadCommandQueue *mThreadCommandQueue; // rdx
  Scaleform::GFx::Movie *v5; // rbx
  Scaleform::GFx::Movie *v6; // rcx
  Scaleform::GFx::MovieDef *v7; // rbx
  UFG::UIScreenManager *v8; // rdi
  double v9; // xmm0_8
  float v10; // xmm6_4
  int height; // r8d
  Scaleform::GFx::Value value; // [rsp+38h] [rbp-59h] BYREF
  int v13; // [rsp+68h] [rbp-29h] BYREF
  __int64 v14; // [rsp+70h] [rbp-21h]
  __int64 v15; // [rsp+78h] [rbp-19h]
  __int64 v16; // [rsp+80h] [rbp-11h]
  __int64 v17; // [rsp+88h] [rbp-9h]
  __int64 v18; // [rsp+90h] [rbp-1h]
  __int64 v19; // [rsp+98h] [rbp+7h]
  __int64 v20; // [rsp+A0h] [rbp+Fh]
  float v21; // [rsp+A8h] [rbp+17h]
  __int64 v22; // [rsp+ACh] [rbp+1Bh]
  __int64 v23; // [rsp+B4h] [rbp+23h]
  __int64 v24; // [rsp+BCh] [rbp+2Bh]
  __int64 v25; // [rsp+C8h] [rbp+37h]

  v25 = -2i64;
  Movie = Scaleform::GFx::Loader::CreateMovie(this->mLoader, this->m_fileName, 0, 0i64);
  pObject = this->m_movieDef.pObject;
  if ( pObject )
    Scaleform::GFx::Resource::Release(pObject);
  this->m_movieDef.pObject = Movie;
  if ( Movie )
  {
    mThreadCommandQueue = UFG::UIScreenManager::s_instance->mThreadCommandQueue;
    v13 = 0;
    v14 = 16i64;
    v15 = 0x2000i64;
    v16 = 0x2000i64;
    v17 = -1i64;
    v18 = 0i64;
    v19 = 0i64;
    v21 = FLOAT_0_25;
    v22 = -1i64;
    v23 = -1i64;
    v24 = -1i64;
    v20 = 0i64;
    v5 = (Scaleform::GFx::Movie *)((__int64 (__fastcall *)(Scaleform::GFx::MovieDefImpl *, int *, _QWORD, _QWORD, UFG::UIThreadCommandQueue *))Movie->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::vfptr[6].__vecDelDtor)(
                                    Movie,
                                    &v13,
                                    0i64,
                                    0i64,
                                    mThreadCommandQueue);
    v6 = this->m_movie.pObject;
    if ( v6 )
      Scaleform::GFx::Movie::Release(v6);
    this->m_movie.pObject = v5;
    value.pObjectInterface = 0i64;
    value.Type = VT_String;
    value.mValue.pString = "true";
    Scaleform::GFx::Movie::SetVariable(v5, "_global.noInvisibleAdvance", &value, 1i64);
    if ( (value.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        value.mValue);
      value.pObjectInterface = 0i64;
    }
    value.Type = VT_Undefined;
    ((void (__fastcall *)(Scaleform::GFx::Movie *))this->m_movie.pObject->vfptr[33].__vecDelDtor)(this->m_movie.pObject);
    if ( !this->m_offscreenTarget )
    {
      v7 = this->m_movieDef.pObject;
      v8 = UFG::UIScreenManager::s_instance;
      v9 = ((double (__fastcall *)(Scaleform::GFx::MovieDef *))v7->Scaleform::GFx::Resource::vfptr[1].GetResourceReport)(v7);
      v10 = *(float *)&v9;
      v8->m_flashWidth = (int)((float (__fastcall *)(Scaleform::GFx::MovieDef *))v7->Scaleform::GFx::Resource::vfptr[1].GetResourceTypeCode)(v7);
      v8->m_flashHeight = (int)v10;
    }
    this->m_width = Render::GetBackBufferTarget()->mWidth;
    height = Render::GetBackBufferTarget()->mHeight;
    this->m_height = height;
    UFG::UIScreenRenderable::setViewport(this, this->m_width, height, 0, 0, this->m_width, height);
    this->mIsLoaded = 1;
  }
}

// File Line: 124
// RVA: 0xA32110
void __fastcall UFG::UIScreenRenderable::setViewport(
        UFG::UIScreenRenderable *this,
        int bufferWidth,
        int bufferHeight,
        int x,
        int y,
        int width,
        int height)
{
  int v7; // r10d
  unsigned __int64 v10; // rdx
  Illusion::Target *m_offscreenTarget; // rcx
  int v12; // eax
  Illusion::Target *v13; // rcx
  int v14[6]; // [rsp+20h] [rbp-48h] BYREF
  __int64 v15; // [rsp+38h] [rbp-30h]
  __int64 v16; // [rsp+40h] [rbp-28h]
  int v17; // [rsp+48h] [rbp-20h]
  int v18; // [rsp+4Ch] [rbp-1Ch]
  int DefaultLoad; // [rsp+50h] [rbp-18h]

  v7 = width;
  this->m_x = x;
  this->m_y = y;
  if ( width <= 0 )
    v7 = this->m_movieInfo.Width;
  v10 = (unsigned int)height;
  this->m_width = v7;
  if ( height <= 0 )
    v10 = (unsigned int)this->m_movieInfo.Height;
  this->m_height = v10;
  m_offscreenTarget = this->m_offscreenTarget;
  v12 = 2;
  v14[0] = bufferWidth;
  if ( m_offscreenTarget )
    v12 = 3;
  v14[1] = bufferHeight;
  v14[2] = x;
  v14[3] = y;
  v14[4] = v7;
  v16 = 0i64;
  v15 = 0i64;
  v14[5] = v10;
  v17 = v12;
  DefaultLoad = 1065353216;
  v18 = 1065353216;
  if ( m_offscreenTarget )
    DefaultLoad = 1065353216;
  else
    DefaultLoad = UFG::Wheelie_EngineState::GetDefaultLoad(0i64, (AkAudioFormat *)v10);
  this->m_movie.pObject->vfptr[12].__vecDelDtor(this->m_movie.pObject, (unsigned int)v14);
  if ( this->m_ownsOffscreenTarget )
  {
    v13 = this->m_offscreenTarget;
    if ( v13 )
    {
      Illusion::DeleteTarget((AMD_HD3D *)v13, 1);
      this->m_offscreenTarget = 0i64;
      this->m_ownsOffscreenTarget = 0;
    }
  }
}

// File Line: 150
// RVA: 0xA31EC0
void __fastcall UFG::UIScreenRenderable::setBuffer(UFG::UIScreenRenderable *this, Illusion::Target *target)
{
  Illusion::Target *m_offscreenTarget; // rcx

  if ( this->m_ownsOffscreenTarget )
  {
    m_offscreenTarget = this->m_offscreenTarget;
    if ( m_offscreenTarget )
    {
      Illusion::DeleteTarget((AMD_HD3D *)m_offscreenTarget, 1);
      this->m_offscreenTarget = 0i64;
      this->m_offscreenTarget = target;
      this->m_ownsOffscreenTarget = 0;
    }
    else
    {
      this->m_offscreenTarget = target;
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
  Scaleform::Render::ContextImpl::RenderNotify *expected_type; // rax
  bool v4; // bl
  Scaleform::Render::Renderer2D *pObject; // rbx
  Scaleform::Render::TreeRoot *RenderEntry; // rax
  Scaleform::Render::ContextImpl::RTHandle v7; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::Render::RenderBuffer *v8; // [rsp+48h] [rbp+10h] BYREF

  if ( this->m_shouldRender )
  {
    v7.pData.pObject = 0i64;
    v1 = (Scaleform::GFx::Resource **)((__int64 (__fastcall *)(Scaleform::GFx::Movie *))this->m_movie.pObject->vfptr[26].__vecDelDtor)(this->m_movie.pObject);
    if ( *v1 )
      Scaleform::Render::RenderBuffer::AddRef(*v1);
    if ( v7.pData.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v7.pData.pObject);
    v7.pData.pObject = (Scaleform::Render::ContextImpl::RTHandle::HandleData *)*v1;
    v2 = (hkDynamicClassNameRegistry **)UFG::UIScreenManager::s_instance->vfptr->getRenderer2D(
                                          UFG::UIScreenManager::s_instance,
                                          &v8);
    expected_type = (Scaleform::Render::ContextImpl::RenderNotify *)SSUnaryParam::get_expected_type(*v2);
    v4 = Scaleform::Render::ContextImpl::RTHandle::NextCapture(&v7, expected_type);
    if ( v8 )
      Scaleform::RefCountImpl::Release(v8);
    if ( v4 )
    {
      pObject = UFG::UIScreenManager::s_instance->vfptr->getRenderer2D(UFG::UIScreenManager::s_instance, &v8)->pObject;
      RenderEntry = (Scaleform::Render::TreeRoot *)Scaleform::Render::ContextImpl::RTHandle::GetRenderEntry(&v7);
      Scaleform::Render::Renderer2D::Display(pObject, RenderEntry);
      if ( v8 )
        Scaleform::RefCountImpl::Release(v8);
    }
    Scaleform::Render::ContextImpl::RTHandle::~RTHandle(&v7);
  }
}

// File Line: 291
// RVA: 0xA31C70
void __fastcall UFG::UIScreenRenderable::replaceTexture(
        UFG::UIScreenRenderable *this,
        const char *flaTexture,
        Illusion::Texture *engineTexture)
{
  __int64 v6; // rax
  __int64 v7; // rax
  Scaleform::GFx::ImageResource *v8; // rsi
  Scaleform::Render::ImageBase *pImage; // rcx
  unsigned int v10; // r15d
  Scaleform::Render::ImageBase *v11; // rcx
  unsigned int v12; // r14d
  UFG::UIGfxTextureManager *v13; // rbp
  __int64 v14; // rbx
  Scaleform::Render::Texture *Texture; // rbp
  Scaleform::Render::Image *v16; // rax
  Scaleform::Render::Image *v17; // rdi
  char v18[8]; // [rsp+28h] [rbp-60h] BYREF
  __int64 v19; // [rsp+30h] [rbp-58h]
  __int64 v20; // [rsp+38h] [rbp-50h]
  Scaleform::Render::Texture *v21; // [rsp+40h] [rbp-48h]
  Scaleform::Render::Size<unsigned long> size; // [rsp+90h] [rbp+8h] BYREF
  char v23; // [rsp+A8h] [rbp+20h] BYREF

  v6 = ((__int64 (__fastcall *)(Scaleform::GFx::Movie *))this->m_movie.pObject->vfptr[1].__vecDelDtor)(this->m_movie.pObject);
  v7 = (*(__int64 (__fastcall **)(__int64, const char *))(*(_QWORD *)v6 + 216i64))(v6, flaTexture);
  v8 = (Scaleform::GFx::ImageResource *)v7;
  if ( v7 && ((*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v7 + 16i64))(v7) & 0xFF00) == 256 && engineTexture )
  {
    pImage = v8->pImage;
    if ( pImage )
      v10 = *((_DWORD *)pImage->vfptr[5].__vecDelDtor(pImage, (unsigned int)&v23) + 1);
    else
      v10 = 0;
    v11 = v8->pImage;
    if ( v11 )
      v12 = *(_DWORD *)v11->vfptr[5].__vecDelDtor(v11, (unsigned int)v18);
    else
      v12 = 0;
    v13 = (UFG::UIGfxTextureManager *)((__int64 (__fastcall *)(Scaleform::Render::D3D1x::HAL *))UFG::UIScreenManager::s_instance->mRenderHAL->vfptr[61].__vecDelDtor)(UFG::UIScreenManager::s_instance->mRenderHAL);
    v14 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
            Scaleform::Memory::pGlobalHeap,
            56i64);
    v19 = v14;
    if ( v14 )
    {
      *(_QWORD *)v14 = &Scaleform::RefCountImplCore::`vftable;
      *(_DWORD *)(v14 + 8) = 1;
      *(_QWORD *)v14 = &Scaleform::RefCountVImpl::`vftable;
      *(_QWORD *)v14 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::`vftable;
      *(_QWORD *)v14 = &Scaleform::RefCountBaseV<Scaleform::Render::Image,3>::`vftable;
      *(_QWORD *)v14 = &Scaleform::Render::ImageBase::`vftable;
      *(_QWORD *)v14 = &Scaleform::Render::Image::`vftable;
      *(_QWORD *)(v14 + 16) = 0i64;
      *(_QWORD *)(v14 + 24) = 0i64;
      *(_QWORD *)(v14 + 32) = 0i64;
      *(_QWORD *)v14 = &Scaleform::Render::TextureImage::`vftable;
      *(_DWORD *)(v14 + 40) = 1;
      *(_DWORD *)(v14 + 44) = v12;
      *(_DWORD *)(v14 + 48) = v10;
      *(_DWORD *)(v14 + 52) = 0;
    }
    else
    {
      v14 = 0i64;
    }
    v20 = v14;
    size.Width = v12;
    size.Height = v10;
    Texture = UFG::UIGfxTextureManager::CreateTexture(
                v13,
                engineTexture,
                (Scaleform::Render::Size<unsigned long>)&size,
                (Scaleform::Render::ImageBase *)v14);
    v21 = Texture;
    v16 = (Scaleform::Render::Image *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                        Scaleform::Memory::pGlobalHeap,
                                        56i64);
    v17 = v16;
    size = (Scaleform::Render::Size<unsigned long>)v16;
    if ( v16 )
    {
      Scaleform::Render::Image::Image(v16, Texture, 0i64);
      v17->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::TextureImage::`vftable;
      LODWORD(v17[1].vfptr) = 1;
      HIDWORD(v17[1].vfptr) = v12;
      v17[1].RefCount = v10;
      *((_DWORD *)&v17[1].RefCount + 1) = 0;
    }
    else
    {
      v17 = 0i64;
    }
    Scaleform::GFx::ImageResource::SetImage(v8, v17);
    ((void (__fastcall *)(Scaleform::GFx::Movie *))this->m_movie.pObject->vfptr[65].__vecDelDtor)(this->m_movie.pObject);
    if ( Texture )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)Texture);
    if ( v14 )
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v14 + 16i64))(v14);
  }
}

