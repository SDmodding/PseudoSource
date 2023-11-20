// File Line: 43
// RVA: 0x8974F0
void __fastcall Scaleform::GFx::ImageFileInfoKeyData::ImageFileInfoKeyData(Scaleform::GFx::ImageFileInfoKeyData *this, Scaleform::GFx::ImageFileInfo *pfileInfo, Scaleform::GFx::FileOpener *pfileOpener, Scaleform::GFx::ImageCreator *pimageCreator, Scaleform::MemoryHeap *pimageHeap)
{
  Scaleform::GFx::ImageCreator *v5; // rdi
  Scaleform::GFx::FileOpener *v6; // rbp
  Scaleform::GFx::ImageFileInfo *v7; // rsi
  Scaleform::GFx::ImageFileInfoKeyData *v8; // rbx
  Scaleform::GFx::ImageFileInfo *v9; // rcx
  Scaleform::Render::RenderBuffer *v10; // rcx
  Scaleform::Render::RenderBuffer *v11; // rcx

  v5 = pimageCreator;
  v6 = pfileOpener;
  v7 = pfileInfo;
  v8 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::ImageFileInfoKeyData,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ImageFileInfoKeyData::`vftable';
  this->pFileOpener.pObject = 0i64;
  this->pImageCreator.pObject = 0i64;
  this->pFileInfo.pObject = 0i64;
  if ( pfileInfo )
    ++pfileInfo->RefCount;
  v9 = this->pFileInfo.pObject;
  if ( v9 )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v9->vfptr);
  v8->pFileInfo.pObject = v7;
  if ( v6 )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v6);
  v10 = (Scaleform::Render::RenderBuffer *)v8->pFileOpener.pObject;
  if ( v10 )
    Scaleform::RefCountImpl::Release(v10);
  v8->pFileOpener.pObject = v6;
  if ( v5 )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v5);
  v11 = (Scaleform::Render::RenderBuffer *)v8->pImageCreator.pObject;
  if ( v11 )
    Scaleform::RefCountImpl::Release(v11);
  v8->pImageCreator.pObject = v5;
  v8->pImageHeap = pimageHeap;
}

// File Line: 67
// RVA: 0x8D9910
unsigned __int64 __fastcall Scaleform::GFx::ImageFileInfoKeyData::GetHashCode(Scaleform::GFx::ImageFileInfoKeyData *this)
{
  Scaleform::GFx::ImageFileInfo *v1; // rdi

  v1 = this->pFileInfo.pObject;
  return Scaleform::String::BernsteinHashFunction(
           (const void *)((v1->FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
           *(_QWORD *)(v1->FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
           0x1505ui64) ^ (_QWORD)this->pImageHeap ^ (_QWORD)this->pImageCreator.pObject ^ (_QWORD)this->pFileOpener.pObject ^ (signed int)v1->Format ^ (((_QWORD)this->pImageHeap ^ (_QWORD)this->pImageCreator.pObject ^ (_QWORD)this->pFileOpener.pObject) >> 7);
}

// File Line: 91
// RVA: 0x159C2D0
__int64 Scaleform::GFx::_dynamic_initializer_for__ImageFileKeyInterface_Instance__()
{
  ImageFileKeyInterface_Instance.vfptr = (Scaleform::GFx::ResourceKey::KeyInterfaceVtbl *)&Scaleform::GFx::ImageFileKeyInterface::`vftable';
  return atexit(Scaleform::GFx::_dynamic_atexit_destructor_for__ImageFileKeyInterface_Instance__);
}

// File Line: 117
// RVA: 0x8D9980
unsigned __int64 __fastcall Scaleform::GFx::ImageFileKeyInterface::GetHashCode(Scaleform::GFx::ImageFileKeyInterface *this, void *hdata)
{
  return Scaleform::GFx::ImageFileInfoKeyData::GetHashCode((Scaleform::GFx::ImageFileInfoKeyData *)hdata);
}

// File Line: 123
// RVA: 0x8E8020
char __fastcall Scaleform::GFx::ImageFileKeyInterface::KeyEquals(Scaleform::GFx::ImageFileKeyInterface *this, void *hdata, Scaleform::GFx::ResourceKey *other)
{
  char result; // al
  _OWORD *v4; // rcx
  unsigned __int8 *v5; // rax
  unsigned __int64 v6; // r8
  int v7; // ecx
  int v8; // edx

  if ( this != (Scaleform::GFx::ImageFileKeyInterface *)other->pKeyInterface )
    return 0;
  v4 = other->hKeyData;
  if ( *((_OWORD *)hdata + 1) != v4[1] || *((_QWORD *)hdata + 4) != *((_QWORD *)v4 + 4) )
    goto LABEL_13;
  v5 = (unsigned __int8 *)((*(_QWORD *)(*((_QWORD *)hdata + 5) + 32i64) & 0xFFFFFFFFFFFFFFFCui64) + 12);
  v6 = (*(_QWORD *)(*((_QWORD *)v4 + 5) + 32i64) & 0xFFFFFFFFFFFFFFFCui64)
     - (*(_QWORD *)(*((_QWORD *)hdata + 5) + 32i64) & 0xFFFFFFFFFFFFFFFCui64);
  do
  {
    v7 = v5[v6];
    v8 = *v5 - v7;
    if ( *v5 != v7 )
      break;
    ++v5;
  }
  while ( v7 );
  if ( v8 )
LABEL_13:
    result = 0;
  else
    result = 1;
  return result;
}

// File Line: 145
// RVA: 0x8D7B90
const char *__fastcall Scaleform::GFx::ImageFileKeyInterface::GetFileURL(Scaleform::GFx::ImageFileKeyInterface *this, void *hdata)
{
  return (const char *)((*(_QWORD *)(*((_QWORD *)hdata + 5) + 32i64) & 0xFFFFFFFFFFFFFFFCui64) + 12);
}

// File Line: 158
// RVA: 0x8BFF20
Scaleform::GFx::ResourceKey *__fastcall Scaleform::GFx::ImageResource::CreateImageFileKey(Scaleform::GFx::ResourceKey *result, Scaleform::GFx::ImageFileInfo *pfileInfo, Scaleform::GFx::FileOpener *pfileOpener, Scaleform::GFx::ImageCreator *pimageCreator, Scaleform::MemoryHeap *pimageHeap)
{
  Scaleform::GFx::ImageCreator *v5; // rbp
  Scaleform::GFx::FileOpener *v6; // r14
  Scaleform::GFx::ImageFileInfo *v7; // r15
  Scaleform::GFx::ResourceKey *v8; // rdi
  Scaleform::Render::RenderBuffer *v9; // rbx
  Scaleform::MemoryHeap *v10; // rcx
  Scaleform::GFx::ImageFileInfoKeyData *v11; // rax
  Scaleform::Render::RenderBuffer *v12; // rax

  v5 = pimageCreator;
  v6 = pfileOpener;
  v7 = pfileInfo;
  v8 = result;
  v9 = 0i64;
  v10 = Scaleform::Memory::pGlobalHeap;
  if ( pimageHeap )
    v10 = pimageHeap;
  v11 = (Scaleform::GFx::ImageFileInfoKeyData *)v10->vfptr->Alloc(v10, 48ui64, 0i64);
  if ( v11 )
  {
    Scaleform::GFx::ImageFileInfoKeyData::ImageFileInfoKeyData(v11, v7, v6, v5, pimageHeap);
    v9 = v12;
  }
  ImageFileKeyInterface_Instance.vfptr->AddRef(
    (Scaleform::GFx::ResourceKey::KeyInterface *)&ImageFileKeyInterface_Instance,
    v9);
  v8->pKeyInterface = (Scaleform::GFx::ResourceKey::KeyInterface *)&ImageFileKeyInterface_Instance;
  v8->hKeyData = v9;
  if ( v9 )
    Scaleform::RefCountImpl::Release(v9);
  return v8;
}

