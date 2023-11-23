// File Line: 62
// RVA: 0x897350
void __fastcall Scaleform::GFx::ImageCreator::ImageCreator(
        Scaleform::GFx::ImageCreator *this,
        Scaleform::GFx::Resource *textureManager)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::State,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::State::`vftable;
  this->SType = State_OrigNodeBounds|State_MaskNode;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ImageCreator::`vftable;
  if ( textureManager )
    Scaleform::Render::RenderBuffer::AddRef(textureManager);
  this->pTextureManager.pObject = (Scaleform::Render::TextureManager *)textureManager;
}

// File Line: 74
// RVA: 0x8E88E0
Scaleform::Render::Image *__fastcall Scaleform::GFx::ImageCreator::LoadImageFile(
        Scaleform::GFx::ImageCreator *this,
        Scaleform::GFx::ImageCreateInfo *info,
        Scaleform::String *url)
{
  Scaleform::GFx::ImageFileHandlerRegistry *pIFHRegistry; // r14
  Scaleform::Render::TextureManager *pObject; // rcx
  char v8; // al
  Scaleform::String *v9; // rax
  Scaleform::String::DataDesc *pData; // rdx
  Scaleform::String *v11; // rax
  Scaleform::String *v12; // rax
  Scaleform::String *v13; // rax
  Scaleform::File *v14; // rbx
  int v15; // eax
  __int64 v16; // rax
  __int64 v17; // r15
  __int64 v18; // rsi
  unsigned int Use; // [rsp+8h] [rbp-69h] BYREF
  Scaleform::MemoryHeap *pHeap; // [rsp+10h] [rbp-61h]
  Scaleform::Render::TextureManager *v22; // [rsp+18h] [rbp-59h]
  int v23; // [rsp+28h] [rbp-49h]
  Scaleform::File *v24; // [rsp+30h] [rbp-41h]
  Scaleform::Render::ImageFileReader *preader; // [rsp+38h] [rbp-39h] BYREF
  Scaleform::String v26; // [rsp+40h] [rbp-31h] BYREF
  Scaleform::String v27; // [rsp+48h] [rbp-29h] BYREF
  __int64 *v28; // [rsp+50h] [rbp-21h]
  Scaleform::String v29; // [rsp+58h] [rbp-19h] BYREF
  __int64 v30[4]; // [rsp+60h] [rbp-11h] BYREF
  Scaleform::FileStat pfileStat; // [rsp+80h] [rbp+Fh] BYREF
  __int64 v32; // [rsp+98h] [rbp+27h]
  Scaleform::String path; // [rsp+E0h] [rbp+6Fh] BYREF
  Scaleform::String result; // [rsp+F0h] [rbp+7Fh] BYREF

  v30[3] = -2i64;
  pIFHRegistry = info->pIFHRegistry;
  if ( !pIFHRegistry || !info->pFileOpener )
    return 0i64;
  Scaleform::String::String(&path, url);
  if ( !Scaleform::String::HasExtension((const char *)((url->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12)) )
  {
    pObject = this->pTextureManager.pObject;
    if ( pObject )
    {
      v8 = ((__int64 (__fastcall *)(Scaleform::Render::TextureManager *))pObject->Scaleform::RefCountBase<Scaleform::Render::TextureManager,72>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,72>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[2].__vecDelDtor)(pObject);
      if ( (v8 & 1) != 0 )
      {
        v9 = Scaleform::String::operator+(url, &result, ".dds");
        Scaleform::String::operator=(&path, v9);
        pData = result.pData;
        goto LABEL_15;
      }
      if ( (v8 & 8) != 0 || (v8 & 0x20) != 0 )
      {
        v12 = Scaleform::String::operator+(url, &v27, ".pvr");
        Scaleform::String::operator=(&path, v12);
        pData = v27.pData;
LABEL_15:
        if ( !_InterlockedDecrement((volatile signed __int32 *)(((unsigned __int64)pData & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        if ( Scaleform::SysFile::GetFileStat(&pfileStat, &path) )
          goto $file_detected;
        goto LABEL_18;
      }
      if ( (v8 & 0x10) != 0 )
      {
        v11 = Scaleform::String::operator+(url, &v26, ".sif");
        Scaleform::String::operator=(&path, v11);
        if ( !_InterlockedDecrement((volatile signed __int32 *)((v26.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        if ( Scaleform::SysFile::GetFileStat(&pfileStat, &path) )
          goto $file_detected;
      }
    }
LABEL_18:
    v13 = Scaleform::String::operator+(url, &v29, ".tga");
    Scaleform::String::operator=(&path, v13);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((v29.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
$file_detected:
  v14 = 0i64;
  v24 = 0i64;
  v28 = v30;
  memset(v30, 0, 24);
  if ( !(unsigned __int8)Scaleform::GFx::URLBuilder::IsProtocol(&path) )
  {
    v14 = (Scaleform::File *)((__int64 (__fastcall *)(Scaleform::GFx::FileOpener *, unsigned __int64, __int64, __int64))info->pFileOpener->vfptr[1].__vecDelDtor)(
                               info->pFileOpener,
                               (path.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12,
                               33i64,
                               438i64);
    v24 = v14;
  }
  v23 = 0;
  if ( Scaleform::Render::ImageFileHandlerRegistry::DetectFormat(
         &pIFHRegistry->Scaleform::Render::ImageFileHandlerRegistry,
         &preader,
         v14,
         0i64,
         0i64) == ImageFile_Unknown )
    goto LABEL_27;
  pHeap = info->pHeap;
  Use = info->Use;
  v22 = this->pTextureManager.pObject;
  v15 = v23;
  if ( info->RUse == Use_FontTexture )
    v15 = 9;
  v23 = v15;
  v16 = ((__int64 (__fastcall *)(Scaleform::Render::ImageFileReader *, Scaleform::File *, unsigned int *))preader->vfptr[1].GetFormat)(
          preader,
          v14,
          &Use);
  v17 = v16;
  v32 = v16;
  if ( !v16 )
  {
LABEL_27:
    v18 = (__int64)pIFHRegistry->Scaleform::Render::ImageFileHandlerRegistry::vfptr->ReadImage(
                     &pIFHRegistry->Scaleform::Render::ImageFileHandlerRegistry,
                     v14,
                     (Scaleform::Render::ImageCreateArgs *)&Use);
  }
  else
  {
    v18 = ((__int64 (__fastcall *)(Scaleform::GFx::ImageCreator *, Scaleform::GFx::ImageCreateInfo *, __int64))this->vfptr[4].__vecDelDtor)(
            this,
            info,
            v16);
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v17 + 16i64))(v17);
  }
  v28 = v30;
  if ( v30[0] )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( v14 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v14);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((path.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  return (Scaleform::Render::Image *)v18;
}

// File Line: 146
// RVA: 0x8E83B0
Scaleform::Render::Image *__fastcall Scaleform::GFx::ImageCreator::LoadExportedImage(
        Scaleform::GFx::ImageCreator *this,
        Scaleform::GFx::ImageCreateExportInfo *info,
        Scaleform::String *url)
{
  Scaleform::Render::Image *v6; // rax
  Scaleform::Render::Image *v7; // rbx
  Scaleform::String *Extension; // rax
  unsigned __int64 v9; // rdx
  __int64 v10; // rax
  char v11; // cl
  bool v12; // zf
  bool v13; // bp
  Scaleform::String result; // [rsp+20h] [rbp-38h] BYREF
  __int64 v15; // [rsp+28h] [rbp-30h]
  Scaleform::String v16; // [rsp+60h] [rbp+8h] BYREF
  Scaleform::String v17; // [rsp+78h] [rbp+20h] BYREF

  v15 = -2i64;
  v6 = (Scaleform::Render::Image *)((__int64 (__fastcall *)(Scaleform::GFx::ImageCreator *))this->vfptr[2].__vecDelDtor)(this);
  v7 = v6;
  if ( !v6 )
  {
    if ( Scaleform::String::HasExtension((const char *)((url->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12)) )
    {
      Extension = Scaleform::String::GetExtension(url, &result);
      v9 = Scaleform::String::ToLower(Extension, &v17)->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
      v10 = 0i64;
      while ( 1 )
      {
        v11 = *(_BYTE *)(v9 + v10++ + 12);
        v12 = v11 == aDds[v10 - 1];
        if ( v11 != aDds[v10 - 1] )
          break;
        if ( v10 == 5 )
        {
          v12 = v11 == aDds[4];
          break;
        }
      }
      v13 = !v12;
      if ( !_InterlockedDecrement((volatile signed __int32 *)((v17.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      if ( !_InterlockedDecrement((volatile signed __int32 *)((result.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      if ( v13 )
      {
        Scaleform::String::String(&v16, url);
        Scaleform::String::StripExtension(&v16);
        Scaleform::String::AppendString(&v16, ".dds", -1i64);
        v6 = (Scaleform::Render::Image *)((__int64 (__fastcall *)(Scaleform::GFx::ImageCreator *, Scaleform::GFx::ImageCreateExportInfo *, Scaleform::String *))this->vfptr[2].__vecDelDtor)(
                                           this,
                                           info,
                                           &v16);
        v7 = v6;
        if ( _InterlockedExchangeAdd(
               (volatile signed __int32 *)((v16.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8),
               0xFFFFFFFF) != 1 )
          return v6;
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      }
    }
    return v7;
  }
  return v6;
}

// File Line: 168
// RVA: 0x8BFED0
Scaleform::Render::Image *__fastcall Scaleform::GFx::ImageCreator::CreateImage(
        Scaleform::GFx::ImageCreator *this,
        Scaleform::GFx::ImageCreateInfo *info,
        Scaleform::Render::ImageSource *source)
{
  int v3; // r9d
  bool v4; // zf
  unsigned int Use; // eax
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax
  unsigned int v8; // [rsp+20h] [rbp-38h] BYREF
  Scaleform::MemoryHeap *pHeap; // [rsp+28h] [rbp-30h]
  Scaleform::Render::TextureManager *pObject; // [rsp+30h] [rbp-28h]
  __int64 v11; // [rsp+38h] [rbp-20h]
  int v12; // [rsp+40h] [rbp-18h]

  v3 = 0;
  v4 = info->RUse == Use_FontTexture;
  pHeap = info->pHeap;
  Use = info->Use;
  v11 = 0i64;
  v8 = Use;
  pObject = this->pTextureManager.pObject;
  if ( v4 )
    v3 = 9;
  vfptr = source->vfptr;
  v12 = v3;
  return (Scaleform::Render::Image *)vfptr[12].__vecDelDtor(source, (unsigned int)&v8);
}

// File Line: 182
// RVA: 0x897420
void __fastcall Scaleform::GFx::ImageFileHandlerRegistry::ImageFileHandlerRegistry(
        Scaleform::GFx::ImageFileHandlerRegistry *this,
        Scaleform::GFx::ImageFileHandlerRegistry::InitType init)
{
  this->Scaleform::GFx::State::Scaleform::RefCountBase<Scaleform::GFx::State,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->Scaleform::GFx::State::Scaleform::RefCountBase<Scaleform::GFx::State,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->Scaleform::GFx::State::Scaleform::RefCountBase<Scaleform::GFx::State,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->Scaleform::GFx::State::Scaleform::RefCountBase<Scaleform::GFx::State,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::State,2>::`vftable;
  this->Scaleform::GFx::State::Scaleform::RefCountBase<Scaleform::GFx::State,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::State::`vftable;
  this->SType = State_Type_Count|State_MaskNode;
  Scaleform::Render::ImageFileHandlerRegistry::ImageFileHandlerRegistry(
    &this->Scaleform::Render::ImageFileHandlerRegistry,
    0);
  this->Scaleform::GFx::State::Scaleform::RefCountBase<Scaleform::GFx::State,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ImageFileHandlerRegistry::`vftable{for `Scaleform::GFx::State};
  this->Scaleform::Render::ImageFileHandlerRegistry::vfptr = (Scaleform::Render::ImageFileHandlerRegistryVtbl *)&Scaleform::GFx::ImageFileHandlerRegistry::`vftable{for `Scaleform::Render::ImageFileHandlerRegistry};
  if ( init == AddDefaultHandlers )
  {
    Scaleform::Render::ImageFileHandlerRegistry::AddHandler(
      &this->Scaleform::Render::ImageFileHandlerRegistry,
      &Scaleform::Render::SIF::FileReader::Instance);
    Scaleform::Render::ImageFileHandlerRegistry::AddHandler(
      &this->Scaleform::Render::ImageFileHandlerRegistry,
      &Scaleform::Render::TGA::FileReader::Instance);
    Scaleform::Render::ImageFileHandlerRegistry::AddHandler(
      &this->Scaleform::Render::ImageFileHandlerRegistry,
      &Scaleform::Render::DDS::FileReader::Instance);
  }
}

// File Line: 226
// RVA: 0x8B13F0
void __fastcall Scaleform::GFx::ImageFileHandlerRegistry::AddHandler(
        Scaleform::GFx::ImageFileHandlerRegistry *this,
        Scaleform::Render::ImageFileHandler *handler)
{
  Scaleform::Render::ImageFileHandlerRegistry::AddHandler(&this->Scaleform::Render::ImageFileHandlerRegistry, handler);
}

