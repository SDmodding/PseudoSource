// File Line: 30
// RVA: 0x93BBA0
void __fastcall Scaleform::Render::FileImageSource::FileImageSource(Scaleform::Render::FileImageSource *this, Scaleform::File *file, Scaleform::Render::ImageFormat format, unsigned __int64 len)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountVImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseV<Scaleform::Render::Image,3>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ImageBase::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ImageSource::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::FileImageSource::`vftable';
  this->Format = format;
  this->Use = 0;
  if ( file )
    _InterlockedExchangeAdd(&file->RefCount, 1u);
  this->pFile.pObject = file;
  this->FileLen = len;
  this->FilePos = ((__int64 (__cdecl *)(Scaleform::File *))this->pFile.pObject->vfptr[5].__vecDelDtor)(this->pFile.pObject);
}

// File Line: 36
// RVA: 0x94A1C0
void __fastcall Scaleform::Render::FileImageSource::~FileImageSource(Scaleform::Render::FileImageSource *this)
{
  Scaleform::Render::FileImageSource *v1; // rbx
  Scaleform::File *v2; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::FileImageSource::`vftable';
  v2 = this->pFile.pObject;
  if ( v2 && !_InterlockedDecrement(&v2->RefCount) && v2 )
    v2->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v2->vfptr, 1u);
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
}

// File Line: 52
// RVA: 0x93F620
void __fastcall Scaleform::Render::MemoryBufferImage::MemoryBufferImage(Scaleform::Render::MemoryBufferImage *this, Scaleform::Render::ImageFormat format, Scaleform::Render::Size<unsigned long> *size, unsigned int use, Scaleform::Render::ImageUpdateSync *sync, Scaleform::File *file, __int64 filePos, unsigned __int64 length)
{
  Scaleform::Render::MemoryBufferImage *v8; // rdi
  unsigned __int64 v9; // rbx
  Scaleform::Render::Texture *volatile v10; // rt1
  Scaleform::Render::Texture *volatile v11; // rt1
  unsigned int v12; // ecx
  Scaleform::ArrayLH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v13; // r15
  __int64 v14; // rsi
  const char *v15; // rax

  v8 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountVImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseV<Scaleform::Render::Image,3>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ImageBase::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Image::`vftable';
  v9 = 0i64;
  this->pTexture.Value = 0i64;
  v10 = this->pTexture.Value;
  v11 = this->pTexture.Value;
  this->pUpdateSync = sync;
  this->pInverseMatrix = 0i64;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::MemoryBufferImage::`vftable';
  this->Format = format;
  v12 = size->Height;
  v8->Size.Width = size->Width;
  v8->Size.Height = v12;
  v8->Use = use;
  v13 = &v8->FileData;
  v13->Data.Data = 0i64;
  v13->Data.Size = 0i64;
  v13->Data.Policy.Capacity = 0i64;
  _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
  v8->FilePath.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData | 1;
  if ( !file )
    goto LABEL_13;
  v14 = length;
  if ( !length )
    v14 = ((__int64 (__fastcall *)(Scaleform::File *))file->vfptr[7].__vecDelDtor)(file) - filePos;
  Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    (Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)&v8->FileData,
    v14);
  if ( v8->FileData.Data.Size == v14
    && (((void (__fastcall *)(Scaleform::File *, __int64, _QWORD))file->vfptr[15].__vecDelDtor)(file, filePos, 0i64),
        ((signed int (__fastcall *)(Scaleform::File *, char *, _QWORD))file->vfptr[10].__vecDelDtor)(
          file,
          v13->Data.Data,
          (unsigned int)v14) >= (signed int)v14) )
  {
    v15 = (const char *)((__int64 (__fastcall *)(Scaleform::File *))file->vfptr[1].__vecDelDtor)(file);
    if ( v15 )
    {
      v9 = -1i64;
      do
        ++v9;
      while ( v15[v9] );
    }
    Scaleform::String::AssignString((Scaleform::String *)&v8->FilePath.0, v15, v9);
  }
  else
  {
LABEL_13:
    v8->Format = 0;
  }
}

// File Line: 89
// RVA: 0x98DAE0
Scaleform::Render::Texture *__fastcall Scaleform::Render::MemoryBufferImage::GetTexture(Scaleform::Render::MemoryBufferImage *this, Scaleform::Render::TextureManager *pmanager)
{
  Scaleform::Render::MemoryBufferImage *v2; // rbx
  Scaleform::Render::TextureManagerLocks *v3; // rax
  Scaleform::Render::TextureManager *v4; // rax
  Scaleform::Render::Texture *result; // rax
  unsigned int v6; // ST20_4

  v2 = this;
  if ( this->pTexture.Value )
  {
    v3 = this->pTexture.Value->pManagerLocks.pObject;
    v4 = v3 ? v3->pManager : 0i64;
    if ( v4 == pmanager )
      return this->pTexture.Value;
  }
  this->pTexture.Value = 0i64;
  v6 = this->Use;
  result = (Scaleform::Render::Texture *)((__int64 (__fastcall *)(Scaleform::Render::TextureManager *, _QWORD, signed __int64, Scaleform::Render::Size<unsigned long> *, unsigned int, Scaleform::Render::MemoryBufferImage *, _QWORD))pmanager->vfptr[1].__vecDelDtor)(
                                           pmanager,
                                           (unsigned int)this->Format,
                                           1i64,
                                           &this->Size,
                                           v6,
                                           this,
                                           0i64);
  v2->pTexture.Value = result;
  return result;
}

// File Line: 120
// RVA: 0x93BAC0
void __fastcall Scaleform::Render::FileHeaderReaderImpl::FileHeaderReaderImpl(Scaleform::Render::FileHeaderReaderImpl *this, Scaleform::File *file, char *header, unsigned __int64 headerSize, char *tempBuffer, char sizeNeeded)
{
  unsigned __int64 v6; // rdi
  char *v7; // rbx
  Scaleform::File *v8; // r15
  Scaleform::Render::FileHeaderReaderImpl *v9; // r14
  __int64 v10; // rdi
  signed int v11; // ebx

  v6 = headerSize;
  v7 = header;
  v8 = file;
  v9 = this;
  this->pHeader = 0i64;
  if ( file && ((unsigned __int8 (__fastcall *)(Scaleform::File *))file->vfptr[2].__vecDelDtor)(file) )
  {
    if ( v7 && v6 >= (unsigned __int8)sizeNeeded )
    {
      v9->pHeader = v7;
    }
    else
    {
      v10 = ((__int64 (__fastcall *)(Scaleform::File *))v8->vfptr[5].__vecDelDtor)(v8);
      v11 = ((__int64 (__fastcall *)(Scaleform::File *, char *, _QWORD))v8->vfptr[10].__vecDelDtor)(
              v8,
              tempBuffer,
              (unsigned __int8)sizeNeeded);
      ((void (__fastcall *)(Scaleform::File *, __int64, _QWORD))v8->vfptr[15].__vecDelDtor)(v8, v10, 0i64);
      if ( v11 >= (unsigned __int8)sizeNeeded )
        v9->pHeader = tempBuffer;
    }
  }
}

// File Line: 154
// RVA: 0x93DFA0
void __fastcall Scaleform::Render::ImageScanlineBufferImpl::ImageScanlineBufferImpl(Scaleform::Render::ImageScanlineBufferImpl *this, Scaleform::Render::ImageFormat readFormat, unsigned int width, Scaleform::Render::ImageFormat convertSourceFormat, char *tempBuffer, unsigned __int64 tempBufferSize)
{
  Scaleform::Render::ImageFormat v6; // edi
  Scaleform::Render::ImageFormat v7; // esi
  Scaleform::Render::ImageScanlineBufferImpl *v8; // rbx
  void (__fastcall *v9)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *); // rbp
  unsigned int v10; // er14
  unsigned int v11; // eax
  unsigned __int64 v12; // r15
  unsigned __int64 v13; // rcx
  Scaleform::Render::ScanlineConvert *v14; // rax
  Scaleform::Render::ImageFormat v15; // ecx
  unsigned __int64 v16; // rdi
  unsigned __int64 v17; // rdx
  char *v18; // rax
  bool v19; // zf

  v6 = readFormat;
  v7 = readFormat;
  this->ReadFormat = readFormat;
  v8 = this;
  this->Width = width;
  if ( convertSourceFormat )
    v6 = convertSourceFormat;
  v9 = 0i64;
  this->pReadScanline = 0i64;
  this->pConvertScanline = 0i64;
  this->ConvertSourceFormat = v6;
  v10 = width;
  v11 = Scaleform::Render::ImageData::GetFormatBitsPerPixel(readFormat, 0);
  v8->ConvertScanlineSize = 0i64;
  v8->pConvertFunc = 0i64;
  v8->BuffersAllocated = 0;
  v12 = (unsigned __int64)(v10 * v11) >> 3;
  v8->ReadScanlineSize = v12;
  if ( v7 == v6 )
    goto LABEL_18;
  v13 = v10 * Scaleform::Render::ImageData::GetFormatBitsPerPixel(v6, 0);
  v14 = ImageScanlineConvertTable;
  v8->ConvertScanlineSize = v13 >> 3;
  v15 = ImageScanlineConvertTable[0].Source;
  if ( ImageScanlineConvertTable[0].Source )
  {
    while ( v15 != v7 || v14->Dest != v6 )
    {
      v15 = v14[1].Source;
      ++v14;
      if ( v15 == Image_None )
        goto LABEL_10;
    }
    v9 = v14->CopyFunc;
  }
LABEL_10:
  v8->pConvertFunc = v9;
  if ( v9 )
  {
LABEL_18:
    v16 = (v12 + 16) & 0xFFFFFFFFFFFFFFF0ui64;
    v17 = v16 + v8->ConvertScanlineSize;
    if ( v17 > tempBufferSize )
    {
      v18 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(Scaleform::Memory::pGlobalHeap, v17, 0i64);
      v8->BuffersAllocated = 1;
    }
    else
    {
      v18 = tempBuffer;
    }
    v19 = v8->pConvertFunc == 0i64;
    v8->pReadScanline = v18;
    if ( !v19 )
      v8->pConvertScanline = &v18[v16];
  }
}

// File Line: 184
// RVA: 0x94B0C0
void __fastcall Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(Scaleform::Render::ImageScanlineBufferImpl *this)
{
  if ( this->BuffersAllocated )
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->pReadScanline);
}

// File Line: 191
// RVA: 0x963860
void __fastcall Scaleform::Render::ImageScanlineBufferImpl::ConvertReadBuffer(Scaleform::Render::ImageScanlineBufferImpl *this, char *dest, Scaleform::Render::Palette *pal, void (__fastcall *copyScanline)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *), void *scanlineArg)
{
  void (__fastcall *v5)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *); // rax
  void (__fastcall *v6)(char *, const char *, unsigned __int64, Scaleform::Render::Palette *, void *); // rdi
  char *v7; // rsi
  char *v8; // rdx
  Scaleform::Render::Palette *v9; // r9
  unsigned __int64 v10; // r8
  Scaleform::Render::ImageScanlineBufferImpl *v11; // rbx

  v5 = this->pConvertFunc;
  v6 = copyScanline;
  v7 = dest;
  v8 = this->pReadScanline;
  v9 = pal;
  v10 = this->ReadScanlineSize;
  v11 = this;
  if ( v5 )
  {
    v5(this->pConvertScanline, v8, v10, v9, 0i64);
    v10 = v11->ConvertScanlineSize;
    v8 = v11->pConvertScanline;
    v9 = 0i64;
  }
  ((void (__fastcall *)(char *, char *, unsigned __int64, Scaleform::Render::Palette *))v6)(v7, v8, v10, v9);
}

