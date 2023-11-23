// File Line: 30
// RVA: 0x93BBA0
void __fastcall Scaleform::Render::FileImageSource::FileImageSource(
        Scaleform::Render::FileImageSource *this,
        Scaleform::File *file,
        Scaleform::Render::ImageFormat format,
        unsigned __int64 len)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountVImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseV<Scaleform::Render::Image,3>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ImageBase::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ImageSource::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::FileImageSource::`vftable;
  this->Format = format;
  this->Use = 0;
  if ( file )
    _InterlockedExchangeAdd(&file->RefCount, 1u);
  this->pFile.pObject = file;
  this->FileLen = len;
  this->FilePos = ((__int64 (__fastcall *)(Scaleform::File *))this->pFile.pObject->vfptr[5].__vecDelDtor)(this->pFile.pObject);
}

// File Line: 36
// RVA: 0x94A1C0
void __fastcall Scaleform::Render::FileImageSource::~FileImageSource(Scaleform::Render::FileImageSource *this)
{
  Scaleform::File *pObject; // rcx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::FileImageSource::`vftable;
  pObject = this->pFile.pObject;
  if ( pObject && !_InterlockedDecrement(&pObject->RefCount) )
    pObject->vfptr->__vecDelDtor(pObject, 1u);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

// File Line: 52
// RVA: 0x93F620
void __fastcall Scaleform::Render::MemoryBufferImage::MemoryBufferImage(
        Scaleform::Render::MemoryBufferImage *this,
        Scaleform::Render::ImageFormat format,
        Scaleform::Render::Size<unsigned long> *size,
        unsigned int use,
        Scaleform::Render::ImageUpdateSync *sync,
        Scaleform::File *file,
        __int64 filePos,
        unsigned __int64 length)
{
  unsigned __int64 v9; // rbx
  unsigned int Height; // ecx
  unsigned __int64 v11; // rsi
  const char *v12; // rax

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountVImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseV<Scaleform::Render::Image,3>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ImageBase::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Image::`vftable;
  v9 = 0i64;
  this->pTexture.Value = 0i64;
  this->pUpdateSync = sync;
  this->pInverseMatrix = 0i64;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::MemoryBufferImage::`vftable;
  this->Format = format;
  Height = size->Height;
  this->Size.Width = size->Width;
  this->Size.Height = Height;
  this->Use = use;
  this->FileData.Data.Data = 0i64;
  this->FileData.Data.Size = 0i64;
  this->FileData.Data.Policy.Capacity = 0i64;
  _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
  this->FilePath.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData.Size + 1;
  if ( !file )
    goto LABEL_2;
  v11 = length;
  if ( !length )
    v11 = ((__int64 (__fastcall *)(Scaleform::File *))file->vfptr[7].__vecDelDtor)(file) - filePos;
  Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    (Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)&this->FileData,
    v11);
  if ( this->FileData.Data.Size == v11
    && (((void (__fastcall *)(Scaleform::File *, __int64, _QWORD))file->vfptr[15].__vecDelDtor)(file, filePos, 0i64),
        ((int (__fastcall *)(Scaleform::File *, char *, _QWORD))file->vfptr[10].__vecDelDtor)(
          file,
          this->FileData.Data.Data,
          (unsigned int)v11) >= (int)v11) )
  {
    v12 = (const char *)((__int64 (__fastcall *)(Scaleform::File *))file->vfptr[1].__vecDelDtor)(file);
    if ( v12 )
    {
      v9 = -1i64;
      do
        ++v9;
      while ( v12[v9] );
    }
    Scaleform::String::AssignString(&this->FilePath, v12, v9);
  }
  else
  {
LABEL_2:
    this->Format = Image_None;
  }
}

// File Line: 89
// RVA: 0x98DAE0
Scaleform::Render::Texture *__fastcall Scaleform::Render::MemoryBufferImage::GetTexture(
        Scaleform::Render::MemoryBufferImage *this,
        Scaleform::Render::TextureManager *pmanager)
{
  Scaleform::Render::TextureManagerLocks *pObject; // rax
  Scaleform::Render::TextureManager *v4; // rax
  Scaleform::Render::Texture *result; // rax

  if ( this->pTexture.Value )
  {
    pObject = this->pTexture.Value->pManagerLocks.pObject;
    v4 = pObject ? pObject->pManager : 0i64;
    if ( v4 == pmanager )
      return this->pTexture.Value;
  }
  this->pTexture.Value = 0i64;
  result = (Scaleform::Render::Texture *)((__int64 (__fastcall *)(Scaleform::Render::TextureManager *, _QWORD, __int64, Scaleform::Render::Size<unsigned long> *, unsigned int, Scaleform::Render::MemoryBufferImage *, _QWORD))pmanager->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[1].__vecDelDtor)(
                                           pmanager,
                                           (unsigned int)this->Format,
                                           1i64,
                                           &this->Size,
                                           this->Use,
                                           this,
                                           0i64);
  this->pTexture.Value = result;
  return result;
}

// File Line: 120
// RVA: 0x93BAC0
void __fastcall Scaleform::Render::FileHeaderReaderImpl::FileHeaderReaderImpl(
        Scaleform::Render::FileHeaderReaderImpl *this,
        Scaleform::File *file,
        char *header,
        unsigned __int64 headerSize,
        char *tempBuffer,
        unsigned __int8 sizeNeeded)
{
  __int64 v10; // rdi
  int v11; // ebx

  this->pHeader = 0i64;
  if ( file && ((unsigned __int8 (__fastcall *)(Scaleform::File *))file->vfptr[2].__vecDelDtor)(file) )
  {
    if ( header && headerSize >= sizeNeeded )
    {
      this->pHeader = header;
    }
    else
    {
      v10 = ((__int64 (__fastcall *)(Scaleform::File *))file->vfptr[5].__vecDelDtor)(file);
      v11 = ((__int64 (__fastcall *)(Scaleform::File *, char *, _QWORD))file->vfptr[10].__vecDelDtor)(
              file,
              tempBuffer,
              sizeNeeded);
      ((void (__fastcall *)(Scaleform::File *, __int64, _QWORD))file->vfptr[15].__vecDelDtor)(file, v10, 0i64);
      if ( v11 >= sizeNeeded )
        this->pHeader = tempBuffer;
    }
  }
}

// File Line: 154
// RVA: 0x93DFA0
void __fastcall Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(
        Scaleform::Render::ImageScanlineBufferImpl *this,
        Scaleform::Render::ImageFormat readFormat,
        unsigned int width,
        Scaleform::Render::ImageFormat convertSourceFormat,
        char *tempBuffer,
        unsigned __int64 tempBufferSize)
{
  Scaleform::Render::ImageFormat v6; // edi
  void (__fastcall *CopyFunc)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *); // rbp
  unsigned int FormatBitsPerPixel; // eax
  unsigned __int64 v12; // r15
  unsigned __int64 v13; // rcx
  Scaleform::Render::ScanlineConvert *v14; // rax
  Scaleform::Render::ImageFormat Source; // ecx
  unsigned __int64 v16; // rdi
  unsigned __int64 v17; // rdx
  bool v19; // zf

  v6 = readFormat;
  this->ReadFormat = readFormat;
  this->Width = width;
  if ( convertSourceFormat )
    v6 = convertSourceFormat;
  CopyFunc = 0i64;
  this->pReadScanline = 0i64;
  this->pConvertScanline = 0i64;
  this->ConvertSourceFormat = v6;
  FormatBitsPerPixel = Scaleform::Render::ImageData::GetFormatBitsPerPixel(readFormat, 0);
  this->ConvertScanlineSize = 0i64;
  this->pConvertFunc = 0i64;
  this->BuffersAllocated = 0;
  v12 = (unsigned __int64)(width * FormatBitsPerPixel) >> 3;
  this->ReadScanlineSize = v12;
  if ( readFormat == v6 )
    goto LABEL_11;
  v13 = width * Scaleform::Render::ImageData::GetFormatBitsPerPixel(v6, 0);
  v14 = ImageScanlineConvertTable;
  this->ConvertScanlineSize = v13 >> 3;
  Source = ImageScanlineConvertTable[0].Source;
  if ( ImageScanlineConvertTable[0].Source )
  {
    while ( Source != readFormat || v14->Dest != v6 )
    {
      Source = v14[1].Source;
      ++v14;
      if ( Source == Image_None )
        goto LABEL_10;
    }
    CopyFunc = v14->CopyFunc;
  }
LABEL_10:
  this->pConvertFunc = CopyFunc;
  if ( CopyFunc )
  {
LABEL_11:
    v16 = (v12 + 16) & 0xFFFFFFFFFFFFFFF0ui64;
    v17 = v16 + this->ConvertScanlineSize;
    if ( v17 > tempBufferSize )
    {
      tempBuffer = (char *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(Scaleform::Memory::pGlobalHeap, v17, 0i64);
      this->BuffersAllocated = 1;
    }
    v19 = this->pConvertFunc == 0i64;
    this->pReadScanline = tempBuffer;
    if ( !v19 )
      this->pConvertScanline = &tempBuffer[v16];
  }
}

// File Line: 184
// RVA: 0x94B0C0
void __fastcall Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(
        Scaleform::Render::ImageScanlineBufferImpl *this)
{
  if ( this->BuffersAllocated )
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->pReadScanline);
}

// File Line: 191
// RVA: 0x963860
void __fastcall Scaleform::Render::ImageScanlineBufferImpl::ConvertReadBuffer(
        Scaleform::Render::ImageScanlineBufferImpl *this,
        char *dest,
        Scaleform::Render::Palette *pal,
        void (__fastcall *copyScanline)(char *, char *, unsigned __int64, Scaleform::Render::Palette *),
        void *scanlineArg)
{
  void (__fastcall *pConvertFunc)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *); // rax
  char *pReadScanline; // rdx
  unsigned __int64 ReadScanlineSize; // r8

  pConvertFunc = this->pConvertFunc;
  pReadScanline = this->pReadScanline;
  ReadScanlineSize = this->ReadScanlineSize;
  if ( pConvertFunc )
  {
    pConvertFunc(this->pConvertScanline, pReadScanline, ReadScanlineSize, pal, 0i64);
    ReadScanlineSize = this->ConvertScanlineSize;
    pReadScanline = this->pConvertScanline;
    pal = 0i64;
  }
  copyScanline(dest, pReadScanline, ReadScanlineSize, pal);
}

