// File Line: 43
// RVA: 0x8974F0
void __fastcall Scaleform::GFx::ImageFileInfoKeyData::ImageFileInfoKeyData(
        Scaleform::GFx::ImageFileInfoKeyData *this,
        Scaleform::GFx::ImageFileInfo *pfileInfo,
        Scaleform::GFx::Resource *pfileOpener,
        Scaleform::GFx::Resource *pimageCreator,
        Scaleform::MemoryHeap *pimageHeap)
{
  Scaleform::GFx::ImageFileInfo *pObject; // rcx
  Scaleform::Render::RenderBuffer *v10; // rcx
  Scaleform::Render::RenderBuffer *v11; // rcx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::ImageFileInfoKeyData,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ImageFileInfoKeyData::`vftable;
  this->pFileOpener.pObject = 0i64;
  this->pImageCreator.pObject = 0i64;
  this->pFileInfo.pObject = 0i64;
  if ( pfileInfo )
    ++pfileInfo->RefCount;
  pObject = this->pFileInfo.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  this->pFileInfo.pObject = pfileInfo;
  if ( pfileOpener )
    Scaleform::Render::RenderBuffer::AddRef(pfileOpener);
  v10 = (Scaleform::Render::RenderBuffer *)this->pFileOpener.pObject;
  if ( v10 )
    Scaleform::RefCountImpl::Release(v10);
  this->pFileOpener.pObject = (Scaleform::GFx::FileOpener *)pfileOpener;
  if ( pimageCreator )
    Scaleform::Render::RenderBuffer::AddRef(pimageCreator);
  v11 = (Scaleform::Render::RenderBuffer *)this->pImageCreator.pObject;
  if ( v11 )
    Scaleform::RefCountImpl::Release(v11);
  this->pImageCreator.pObject = (Scaleform::GFx::ImageCreator *)pimageCreator;
  this->pImageHeap = pimageHeap;
}

// File Line: 67
// RVA: 0x8D9910
unsigned __int64 __fastcall Scaleform::GFx::ImageFileInfoKeyData::GetHashCode(
        Scaleform::GFx::ImageFileInfoKeyData *this)
{
  Scaleform::GFx::ImageFileInfo *pObject; // rdi

  pObject = this->pFileInfo.pObject;
  return Scaleform::String::BernsteinHashFunction(
           (const void *)((pObject->FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
           *(_QWORD *)(pObject->FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
           0x1505ui64) ^ (__int64)this->pImageHeap ^ (__int64)this->pImageCreator.pObject ^ (__int64)this->pFileOpener.pObject ^ (int)pObject->Format ^ ((unsigned __int64)((__int64)this->pImageHeap ^ (__int64)this->pImageCreator.pObject ^ (__int64)this->pFileOpener.pObject) >> 7);
}

// File Line: 91
// RVA: 0x159C2D0
__int64 Scaleform::GFx::_dynamic_initializer_for__ImageFileKeyInterface_Instance__()
{
  ImageFileKeyInterface_Instance.vfptr = (Scaleform::GFx::ResourceKey::KeyInterfaceVtbl *)&Scaleform::GFx::ImageFileKeyInterface::`vftable;
  return atexit((int (__fastcall *)())Scaleform::GFx::_dynamic_atexit_destructor_for__ImageFileKeyInterface_Instance__);
}

// File Line: 117
// RVA: 0x8D9980
unsigned __int64 __fastcall Scaleform::GFx::ImageFileKeyInterface::GetHashCode(
        Scaleform::GFx::ImageFileKeyInterface *this,
        Scaleform::GFx::ImageFileInfoKeyData *hdata)
{
  return Scaleform::GFx::ImageFileInfoKeyData::GetHashCode(hdata);
}

// File Line: 123
// RVA: 0x8E8020
bool __fastcall Scaleform::GFx::ImageFileKeyInterface::KeyEquals(
        Scaleform::GFx::ImageFileKeyInterface *this,
        _OWORD *hdata,
        Scaleform::GFx::ResourceKey *other)
{
  _OWORD *hKeyData; // rcx
  unsigned __int8 *v5; // rax
  unsigned __int64 v6; // r8
  int v7; // ecx
  int v8; // edx

  if ( this != other->pKeyInterface )
    return 0;
  hKeyData = other->hKeyData;
  if ( hdata[1] != hKeyData[1] || *((_QWORD *)hdata + 4) != *((_QWORD *)hKeyData + 4) )
    return 0;
  v5 = (unsigned __int8 *)((*(_QWORD *)(*((_QWORD *)hdata + 5) + 32i64) & 0xFFFFFFFFFFFFFFFCui64) + 12);
  v6 = (*(_QWORD *)(*((_QWORD *)hKeyData + 5) + 32i64) & 0xFFFFFFFFFFFFFFFCui64)
     - (*(_QWORD *)(*((_QWORD *)hdata + 5) + 32i64) & 0xFFFFFFFFFFFFFFFCui64);
  do
  {
    v7 = v5[v6];
    v8 = *v5 - v7;
    if ( v8 )
      break;
    ++v5;
  }
  while ( v7 );
  return !v8;
}

// File Line: 145
// RVA: 0x8D7B90
const char *__fastcall Scaleform::GFx::ImageFileKeyInterface::GetFileURL(
        Scaleform::GFx::ImageFileKeyInterface *this,
        _QWORD *hdata)
{
  return (const char *)((*(_QWORD *)(hdata[5] + 32i64) & 0xFFFFFFFFFFFFFFFCui64) + 12);
}

// File Line: 158
// RVA: 0x8BFF20
Scaleform::GFx::ResourceKey *__fastcall Scaleform::GFx::ImageResource::CreateImageFileKey(
        Scaleform::GFx::ResourceKey *result,
        Scaleform::GFx::ImageFileInfo *pfileInfo,
        Scaleform::GFx::Resource *pfileOpener,
        Scaleform::GFx::Resource *pimageCreator,
        Scaleform::MemoryHeap *pimageHeap)
{
  Scaleform::Render::RenderBuffer *v9; // rbx
  Scaleform::MemoryHeap *v10; // rcx
  Scaleform::GFx::ImageFileInfoKeyData *v11; // rax
  Scaleform::Render::RenderBuffer *v12; // rax

  v9 = 0i64;
  v10 = Scaleform::Memory::pGlobalHeap;
  if ( pimageHeap )
    v10 = pimageHeap;
  v11 = (Scaleform::GFx::ImageFileInfoKeyData *)v10->vfptr->Alloc(v10, 48ui64, 0i64);
  if ( v11 )
  {
    Scaleform::GFx::ImageFileInfoKeyData::ImageFileInfoKeyData(v11, pfileInfo, pfileOpener, pimageCreator, pimageHeap);
    v9 = v12;
  }
  ImageFileKeyInterface_Instance.vfptr->AddRef(&ImageFileKeyInterface_Instance, v9);
  result->pKeyInterface = &ImageFileKeyInterface_Instance;
  result->hKeyData = v9;
  if ( v9 )
    Scaleform::RefCountImpl::Release(v9);
  return result;
}

