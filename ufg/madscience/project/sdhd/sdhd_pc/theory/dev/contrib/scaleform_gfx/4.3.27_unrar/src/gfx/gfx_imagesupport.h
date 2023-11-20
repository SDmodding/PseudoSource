// File Line: 112
// RVA: 0x89A550
void __fastcall Scaleform::GFx::MemoryBufferZlibImage::MemoryBufferZlibImage(Scaleform::GFx::MemoryBufferZlibImage *this, Scaleform::GFx::ZlibSupportBase *zlib, Scaleform::Render::ImageFormat format, Scaleform::Render::Size<unsigned long> *size, Scaleform::GFx::ZlibImageSource::SourceBitmapDataFormat bmpFormatId, unsigned __int16 colorTableSize, unsigned int use, Scaleform::Render::ImageUpdateSync *sync, Scaleform::File *file, __int64 filePos, unsigned __int64 length)
{
  Scaleform::GFx::Resource *v11; // rdi
  Scaleform::GFx::MemoryBufferZlibImage *v12; // rbx

  v11 = (Scaleform::GFx::Resource *)zlib;
  v12 = this;
  Scaleform::Render::MemoryBufferImage::MemoryBufferImage(
    (Scaleform::Render::MemoryBufferImage *)&this->vfptr,
    format,
    size,
    use,
    sync,
    file,
    filePos,
    length);
  v12->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::MemoryBufferZlibImage::`vftable';
  if ( v11 )
    Scaleform::Render::RenderBuffer::AddRef(v11);
  v12->Zlib.pObject = (Scaleform::GFx::ZlibSupportBase *)v11;
  v12->ColorTableSize = colorTableSize;
  v12->BitmapFormatId = bmpFormatId;
}

