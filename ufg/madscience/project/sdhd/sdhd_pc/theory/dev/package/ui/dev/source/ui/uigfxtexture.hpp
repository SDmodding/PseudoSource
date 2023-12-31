// File Line: 84
// RVA: 0xA264F0
Scaleform::Render::Size<unsigned long> *__fastcall UFG::UIGfxTexture::GetTextureSize(
        UFG::UIGfxTexture *this,
        Scaleform::Render::Size<unsigned long> *result,
        unsigned int plane)
{
  *result = this->ImgSize;
  return result;
}

// File Line: 100
// RVA: 0xA264E0
Scaleform::Render::TextureFormat *__fastcall UFG::UIGfxTexture::GetTextureFormatMapping(UFG::UIGfxTexture *this)
{
  Scaleform::Render::TextureFormat *result; // rax

  result = this->pFormat;
  if ( result )
    return (Scaleform::Render::TextureFormat *)result[1].vfptr;
  return result;
}

