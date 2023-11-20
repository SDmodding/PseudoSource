// File Line: 62
// RVA: 0x897350
void __fastcall Scaleform::GFx::ImageCreator::ImageCreator(Scaleform::GFx::ImageCreator *this, Scaleform::Render::TextureManager *textureManager)
{
  Scaleform::Render::TextureManager *v2; // rdi
  Scaleform::GFx::ImageCreator *v3; // rbx

  v2 = textureManager;
  v3 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::State,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::State::`vftable;
  this->SType = 14;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ImageCreator::`vftable;
  if ( textureManager )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)textureManager);
  v3->pTextureManager.pObject = v2;
}

// File Line: 74
// RVA: 0x8E88E0
Scaleform::Render::Image *__fastcall Scaleform::GFx::ImageCreator::LoadImageFile(Scaleform::GFx::ImageCreator *this, Scaleform::GFx::ImageCreateInfo *info, Scaleform::String *url)
{
  Scaleform::String *v3; // rbx
  Scaleform::GFx::ImageCreateInfo *v4; // rsi
  Scaleform::GFx::ImageCreator *v5; // r12
  Scaleform::GFx::ImageFileHandlerRegistry *v6; // r14
  Scaleform::Render::TextureManager *v7; // rcx
  char v8; // al
  Scaleform::String *v9; // rax
  Scaleform::String::DataDesc *v10; // rdx
  Scaleform::String *v11; // rax
  Scaleform::String *v12; // rax
  Scaleform::String *v13; // rax
  Scaleform::File *v14; // rbx
  signed int v15; // eax
  __int64 v16; // rax
  __int64 v17; // r15
  __int64 v18; // rsi
  unsigned int v20; // [rsp+8h] [rbp-69h]
  Scaleform::MemoryHeap *v21; // [rsp+10h] [rbp-61h]
  Scaleform::Render::TextureManager *v22; // [rsp+18h] [rbp-59h]
  int v23; // [rsp+28h] [rbp-49h]
  Scaleform::File *v24; // [rsp+30h] [rbp-41h]
  Scaleform::Render::ImageFileReader *preader; // [rsp+38h] [rbp-39h]
  Scaleform::String v26; // [rsp+40h] [rbp-31h]
  Scaleform::String v27; // [rsp+48h] [rbp-29h]
  __int64 *v28; // [rsp+50h] [rbp-21h]
  Scaleform::String v29; // [rsp+58h] [rbp-19h]
  __int64 v30; // [rsp+60h] [rbp-11h]
  __int64 v31; // [rsp+68h] [rbp-9h]
  __int64 v32; // [rsp+70h] [rbp-1h]
  __int64 v33; // [rsp+78h] [rbp+7h]
  Scaleform::FileStat pfileStat; // [rsp+80h] [rbp+Fh]
  __int64 v35; // [rsp+98h] [rbp+27h]
  Scaleform::String path; // [rsp+E0h] [rbp+6Fh]
  Scaleform::String result; // [rsp+F0h] [rbp+7Fh]

  v33 = -2i64;
  v3 = url;
  v4 = info;
  v5 = this;
  v6 = info->pIFHRegistry;
  if ( !v6 || !info->pFileOpener )
    return 0i64;
  Scaleform::String::String(&path, url);
  if ( !Scaleform::String::HasExtension((const char *)((v3->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12)) )
  {
    v7 = v5->pTextureManager.pObject;
    if ( v7 )
    {
      v8 = ((__int64 (*)(void))v7->vfptr[2].__vecDelDtor)();
      if ( v8 & 1 )
      {
        v9 = Scaleform::String::operator+(v3, &result, ".dds");
        Scaleform::String::operator=(&path, v9);
        v10 = result.pData;
        goto LABEL_15;
      }
      if ( v8 & 8 || v8 & 0x20 )
      {
        v12 = Scaleform::String::operator+(v3, &v27, ".pvr");
        Scaleform::String::operator=(&path, v12);
        v10 = v27.pData;
LABEL_15:
        if ( !_InterlockedDecrement((volatile signed __int32 *)(((unsigned __int64)v10 & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        if ( Scaleform::SysFile::GetFileStat(&pfileStat, &path) )
          goto $file_detected;
        goto LABEL_18;
      }
      if ( v8 & 0x10 )
      {
        v11 = Scaleform::String::operator+(v3, &v26, ".sif");
        Scaleform::String::operator=(&path, v11);
        if ( !_InterlockedDecrement((volatile signed __int32 *)((v26.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        if ( Scaleform::SysFile::GetFileStat(&pfileStat, &path) )
          goto $file_detected;
      }
    }
LABEL_18:
    v13 = Scaleform::String::operator+(v3, &v29, ".tga");
    Scaleform::String::operator=(&path, v13);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((v29.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  }
$file_detected:
  v14 = 0i64;
  v24 = 0i64;
  v28 = &v30;
  v30 = 0i64;
  v31 = 0i64;
  v32 = 0i64;
  if ( !(unsigned __int8)Scaleform::GFx::URLBuilder::IsProtocol(&path) )
  {
    v14 = (Scaleform::File *)((__int64 (__fastcall *)(Scaleform::GFx::FileOpener *, unsigned __int64, signed __int64, signed __int64))v4->pFileOpener->vfptr[1].__vecDelDtor)(
                               v4->pFileOpener,
                               (path.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12,
                               33i64,
                               438i64);
    v24 = v14;
  }
  v23 = 0;
  if ( Scaleform::Render::ImageFileHandlerRegistry::DetectFormat(
         (Scaleform::Render::ImageFileHandlerRegistry *)&v6->vfptr,
         &preader,
         v14,
         0i64,
         0i64) == 1 )
    goto LABEL_38;
  v21 = v4->pHeap;
  v20 = v4->Use;
  v22 = v5->pTextureManager.pObject;
  v15 = v23;
  if ( v4->RUse == 3 )
    v15 = 9;
  v23 = v15;
  v16 = ((__int64 (__fastcall *)(Scaleform::Render::ImageFileReader *, Scaleform::File *, unsigned int *))preader->vfptr[1].GetFormat)(
          preader,
          v14,
          &v20);
  v17 = v16;
  v35 = v16;
  if ( v16 )
  {
    v18 = ((__int64 (__fastcall *)(Scaleform::GFx::ImageCreator *, Scaleform::GFx::ImageCreateInfo *, __int64))v5->vfptr[4].__vecDelDtor)(
            v5,
            v4,
            v16);
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v17 + 16i64))(v17);
  }
  else
  {
LABEL_38:
    v18 = (__int64)v6->vfptr->ReadImage(
                     (Scaleform::Render::ImageFileHandlerRegistry *)&v6->vfptr,
                     v14,
                     (Scaleform::Render::ImageCreateArgs *)&v20);
  }
  v28 = &v30;
  if ( v30 )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  if ( v14 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v14);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((path.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  return (Scaleform::Render::Image *)v18;
}

// File Line: 146
// RVA: 0x8E83B0
Scaleform::Render::Image *__fastcall Scaleform::GFx::ImageCreator::LoadExportedImage(Scaleform::GFx::ImageCreator *this, Scaleform::GFx::ImageCreateExportInfo *info, Scaleform::String *url)
{
  Scaleform::String *v3; // rsi
  Scaleform::GFx::ImageCreateExportInfo *v4; // r15
  Scaleform::GFx::ImageCreator *v5; // r14
  Scaleform::Render::Image *v6; // rax
  Scaleform::Render::Image *v7; // rbx
  Scaleform::String *v8; // rax
  unsigned __int64 v9; // rdx
  __int64 v10; // rax
  char v11; // cl
  bool v12; // zf
  bool v13; // bp
  Scaleform::String result; // [rsp+20h] [rbp-38h]
  __int64 v15; // [rsp+28h] [rbp-30h]
  Scaleform::String v16; // [rsp+60h] [rbp+8h]
  Scaleform::String v17; // [rsp+78h] [rbp+20h]

  v15 = -2i64;
  v3 = url;
  v4 = info;
  v5 = this;
  v6 = (Scaleform::Render::Image *)((__int64 (*)(void))this->vfptr[2].__vecDelDtor)();
  v7 = v6;
  if ( !v6 )
  {
    if ( Scaleform::String::HasExtension((const char *)((v3->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12)) )
    {
      v8 = Scaleform::String::GetExtension(v3, &result);
      v9 = Scaleform::String::ToLower(v8, &v17)->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
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
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      if ( !_InterlockedDecrement((volatile signed __int32 *)((result.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      if ( v13 )
      {
        Scaleform::String::String(&v16, v3);
        Scaleform::String::StripExtension(&v16);
        Scaleform::String::AppendString(&v16, ".dds", -1i64);
        v6 = (Scaleform::Render::Image *)((__int64 (__fastcall *)(Scaleform::GFx::ImageCreator *, Scaleform::GFx::ImageCreateExportInfo *, Scaleform::String *))v5->vfptr[2].__vecDelDtor)(
                                           v5,
                                           v4,
                                           &v16);
        v7 = v6;
        if ( _InterlockedExchangeAdd(
               (volatile signed __int32 *)((v16.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8),
               0xFFFFFFFF) != 1 )
          return v6;
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      }
    }
    v6 = v7;
  }
  return v6;
}

// File Line: 168
// RVA: 0x8BFED0
Scaleform::Render::Image *__fastcall Scaleform::GFx::ImageCreator::CreateImage(Scaleform::GFx::ImageCreator *this, Scaleform::GFx::ImageCreateInfo *info, Scaleform::Render::ImageSource *source)
{
  signed int v3; // er9
  bool v4; // zf
  unsigned int v5; // eax
  Scaleform::RefCountImplCoreVtbl *v6; // rax
  unsigned int v8; // [rsp+20h] [rbp-38h]
  Scaleform::MemoryHeap *v9; // [rsp+28h] [rbp-30h]
  Scaleform::Render::TextureManager *v10; // [rsp+30h] [rbp-28h]
  __int64 v11; // [rsp+38h] [rbp-20h]
  int v12; // [rsp+40h] [rbp-18h]

  v3 = 0;
  v4 = info->RUse == 3;
  v9 = info->pHeap;
  v5 = info->Use;
  v11 = 0i64;
  v8 = v5;
  v10 = this->pTextureManager.pObject;
  if ( v4 )
    v3 = 9;
  v6 = source->vfptr;
  v12 = v3;
  return (Scaleform::Render::Image *)v6[12].__vecDelDtor(
                                       (Scaleform::RefCountImplCore *)&source->vfptr,
                                       (unsigned int)&v8);
}

// File Line: 182
// RVA: 0x897420
void __fastcall Scaleform::GFx::ImageFileHandlerRegistry::ImageFileHandlerRegistry(Scaleform::GFx::ImageFileHandlerRegistry *this, Scaleform::GFx::ImageFileHandlerRegistry::InitType init)
{
  Scaleform::GFx::ImageFileHandlerRegistry::InitType v2; // ebx
  Scaleform::GFx::ImageFileHandlerRegistry *v3; // rdi

  v2 = init;
  v3 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::State,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::State::`vftable;
  this->SType = 15;
  Scaleform::Render::ImageFileHandlerRegistry::ImageFileHandlerRegistry(
    (Scaleform::Render::ImageFileHandlerRegistry *)&this->vfptr,
    0);
  v3->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ImageFileHandlerRegistry::`vftable{for `Scaleform::GFx::State};
  v3->vfptr = (Scaleform::Render::ImageFileHandlerRegistryVtbl *)&Scaleform::GFx::ImageFileHandlerRegistry::`vftable{for `Scaleform::Render::ImageFileHandlerRegistry};
  if ( v2 == 1 )
  {
    Scaleform::Render::ImageFileHandlerRegistry::AddHandler(
      (Scaleform::Render::ImageFileHandlerRegistry *)&v3->vfptr,
      (Scaleform::Render::ImageFileHandler *)&Scaleform::Render::SIF::FileReader::Instance.vfptr);
    Scaleform::Render::ImageFileHandlerRegistry::AddHandler(
      (Scaleform::Render::ImageFileHandlerRegistry *)&v3->vfptr,
      (Scaleform::Render::ImageFileHandler *)&Scaleform::Render::TGA::FileReader::Instance.vfptr);
    Scaleform::Render::ImageFileHandlerRegistry::AddHandler(
      (Scaleform::Render::ImageFileHandlerRegistry *)&v3->vfptr,
      (Scaleform::Render::ImageFileHandler *)&Scaleform::Render::DDS::FileReader::Instance.vfptr);
  }
}

// File Line: 226
// RVA: 0x8B13F0
void __fastcall Scaleform::GFx::ImageFileHandlerRegistry::AddHandler(Scaleform::GFx::ImageFileHandlerRegistry *this, Scaleform::Render::ImageFileHandler *handler)
{
  Scaleform::Render::ImageFileHandlerRegistry::AddHandler(
    (Scaleform::Render::ImageFileHandlerRegistry *)&this->vfptr,
    handler);
}

