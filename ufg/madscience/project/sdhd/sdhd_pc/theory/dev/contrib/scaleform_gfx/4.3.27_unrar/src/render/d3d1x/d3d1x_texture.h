// File Line: 51
// RVA: 0xA0ED40
__int64 __fastcall Scaleform::Render::D3D1x::TextureFormat::GetImageFormat(Scaleform::Render::D3D1x::TextureFormat *this)
{
  return this->pMapping->Format;
}

// File Line: 52
// RVA: 0xA0ED50
void (__fastcall *__fastcall Scaleform::Render::D3D1x::TextureFormat::GetScanlineCopyFn(Scaleform::Render::D3D1x::TextureFormat *this))(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *)
{
  return this->pMapping->CopyFunc;
}

// File Line: 53
// RVA: 0xA0ED60
void (__fastcall *__fastcall Scaleform::Render::D3D1x::TextureFormat::GetScanlineUncopyFn(Scaleform::Render::D3D1x::TextureFormat *this))(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *)
{
  return this->pMapping->UncopyFunc;
}

// File Line: 87
// RVA: 0xA0ED80
Scaleform::Render::Size<unsigned long> *__fastcall Scaleform::Render::D3D1x::Texture::GetTextureSize(Scaleform::Render::D3D1x::Texture *this, Scaleform::Render::Size<unsigned long> *result, unsigned int plane)
{
  Scaleform::Render::D3D1x::Texture::HWTextureDesc *v3; // r9

  v3 = &this->pTextures[plane];
  result->Width = v3->Size.Width;
  result->Height = v3->Size.Height;
  return result;
}

// File Line: 179
// RVA: 0xA10160
Scaleform::Render::D3D1x::MappedTexture *__fastcall Scaleform::Render::D3D1x::TextureManager::getDefaultMappedTexture(Scaleform::Render::D3D1x::TextureManager *this)
{
  return &this->MappedTexture0;
}

// File Line: 180
// RVA: 0xA100F0
Scaleform::Render::MappedTextureBase *__fastcall Scaleform::Render::D3D1x::TextureManager::createMappedTexture(Scaleform::Render::D3D1x::TextureManager *this)
{
  Scaleform::Render::MappedTextureBase *v1; // rax
  Scaleform::Render::MappedTextureBase *v2; // rbx
  int v4; // [rsp+48h] [rbp+10h]
  Scaleform::Render::MappedTextureBase *v5; // [rsp+50h] [rbp+18h]

  v4 = 72;
  v1 = (Scaleform::Render::MappedTextureBase *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::D3D1x::TextureManager *, signed __int64, int *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 this,
                                                 216i64,
                                                 &v4,
                                                 -2i64);
  v2 = v1;
  v5 = v1;
  if ( !v1 )
    return 0i64;
  Scaleform::Render::MappedTextureBase::MappedTextureBase(v1);
  v2->vfptr = (Scaleform::Render::MappedTextureBaseVtbl *)&Scaleform::Render::D3D1x::MappedTexture::`vftable';
  return v2;
}

// File Line: 217
// RVA: 0xA0F440
bool __fastcall Scaleform::Render::D3D1x::TextureManager::IsDrawableImageFormat(Scaleform::Render::D3D1x::TextureManager *this, Scaleform::Render::ImageFormat format)
{
  return (unsigned int)(format - 1) <= 1;
}

