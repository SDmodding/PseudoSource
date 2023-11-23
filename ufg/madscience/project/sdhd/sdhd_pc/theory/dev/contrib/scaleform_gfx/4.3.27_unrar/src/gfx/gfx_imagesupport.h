// File Line: 112
// RVA: 0x89A550
void __fastcall Scaleform::GFx::MemoryBufferZlibImage::MemoryBufferZlibImage(
        Scaleform::GFx::MemoryBufferZlibImage *this,
        Scaleform::GFx::Resource *zlib,
        Scaleform::Render::ImageFormat format,
        Scaleform::Render::Size<unsigned long> *size,
        Scaleform::GFx::ZlibImageSource::SourceBitmapDataFormat bmpFormatId,
        unsigned __int16 colorTableSize,
        unsigned int use,
        Scaleform::Render::ImageUpdateSync *sync,
        Scaleform::File *file,
        __int64 filePos,
        unsigned __int64 length)
{
  Scaleform::Render::MemoryBufferImage::MemoryBufferImage(this, format, size, use, sync, file, filePos, length);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::MemoryBufferZlibImage::`vftable;
  if ( zlib )
    Scaleform::Render::RenderBuffer::AddRef(zlib);
  this->Zlib.pObject = (Scaleform::GFx::ZlibSupportBase *)zlib;
  this->ColorTableSize = colorTableSize;
  this->BitmapFormatId = bmpFormatId;
}

