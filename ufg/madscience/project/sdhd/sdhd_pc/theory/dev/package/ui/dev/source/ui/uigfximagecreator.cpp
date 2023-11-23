// File Line: 21
// RVA: 0x15AAA10
__int64 UFG::_dynamic_initializer_for__DEFAULT_TEXTURE__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("DEFAULT", -1);
  DEFAULT_TEXTURE = result;
  return result;
}

// File Line: 27
// RVA: 0xA23120
void __fastcall UFG::UIGfxImageCreator::UIGfxImageCreator(
        UFG::UIGfxImageCreator *this,
        Scaleform::GFx::Resource *textureManager)
{
  Scaleform::GFx::ImageCreator::ImageCreator(this, textureManager);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&UFG::UIGfxImageCreator::`vftable;
}

// File Line: 33
// RVA: 0xA278B0
Scaleform::Render::Image *__fastcall UFG::UIGfxImageCreator::LoadExportedImage(
        UFG::UIGfxImageCreator *this,
        Scaleform::GFx::ImageCreateExportInfo *info,
        Scaleform::String *url)
{
  unsigned __int64 v6; // rcx

  if ( (unsigned int)(info->Type - 1) > 1 )
    return Scaleform::GFx::ImageCreator::LoadExportedImage(this, info, url);
  v6 = info->ExportName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
  if ( v6 == -12i64 || (int)UFG::qStringLength((const char *)(v6 + 12)) <= 0 )
    return Scaleform::GFx::ImageCreator::LoadExportedImage(this, info, url);
  else
    return UFG::UIGfxImageCreator::LoadIllusionTexture(
             this,
             (const char *)((info->ExportName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
}

// File Line: 51
// RVA: 0xA27C00
Scaleform::Render::Image *__fastcall UFG::UIGfxImageCreator::LoadProtocolImage(
        UFG::UIGfxImageCreator *this,
        Scaleform::GFx::ImageCreateInfo *info,
        Scaleform::String *url)
{
  __int64 Length; // rax
  Scaleform::String *v6; // rax
  Scaleform::Render::Image *IllusionTexture; // rax
  Scaleform::Render::Image *v8; // rbx
  Scaleform::String result; // [rsp+58h] [rbp+20h] BYREF

  Length = Scaleform::String::GetLength(url);
  v6 = Scaleform::String::Substring(url, &result, 6ui64, Length);
  IllusionTexture = UFG::UIGfxImageCreator::LoadIllusionTexture(
                      this,
                      (const char *)((v6->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
  v8 = IllusionTexture;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((result.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
  {
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    return v8;
  }
  return IllusionTexture;
}

// File Line: 59
// RVA: 0xA27930
Scaleform::Render::Image *__fastcall UFG::UIGfxImageCreator::LoadIllusionTexture(
        UFG::UIGfxImageCreator *this,
        const char *textureName)
{
  unsigned int v4; // ebx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v6; // rax
  UFG::qResourceData *mData; // rbx
  Illusion::Texture *v8; // rsi
  unsigned int v9; // eax
  unsigned int v10; // ebx
  UFG::qResourceInventory *v11; // rax
  UFG::qResourceWarehouse *v12; // rax
  Scaleform::Render::Image *v13; // rdi
  unsigned int v14; // r14d
  unsigned int v15; // r15d
  UFG::UIGfxTextureManager *pObject; // rbp
  __int64 v17; // rbx
  Scaleform::Render::Texture *Texture; // rbp
  Scaleform::Render::Image *v19; // rax
  Scaleform::Render::Image *v20; // rsi
  UFG::qResourceInventory *v21; // rax
  UFG::qResourceWarehouse *v22; // rax
  UFG::qResourceHandle v24; // [rsp+38h] [rbp-50h] BYREF
  Scaleform::Render::Size<unsigned long> size; // [rsp+A0h] [rbp+18h] BYREF
  __int64 v26; // [rsp+A8h] [rbp+20h]

  v4 = UFG::qStringHashUpper32(textureName, -1);
  UFG::qResourceHandle::qResourceHandle(&v24);
  Inventory = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
  {
    v6 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v6, 0x8B43FABF);
    `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&v24, 0x8B43FABF, v4, Inventory);
  mData = v24.mData;
  v8 = (Illusion::Texture *)v24.mData;
  if ( !v24.mData || (v9 = DEFAULT_TEXTURE, v24.mData->mNode.mUID == DEFAULT_TEXTURE) )
  {
    v10 = UFG::qToUInt32(textureName, 0);
    v11 = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
    {
      v12 = UFG::qResourceWarehouse::Instance();
      v11 = UFG::qResourceWarehouse::GetInventory(v12, 0x8B43FABF);
      `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = v11;
    }
    UFG::qResourceHandle::Init(&v24, 0x8B43FABF, v10, v11);
    v8 = (Illusion::Texture *)v24.mData;
    UFG::qPrintf("Failed to find a texture by name; direct hash texture = %p\n", v24.mData);
    mData = v24.mData;
    v9 = DEFAULT_TEXTURE;
  }
  if ( v8 )
  {
    if ( v8->mNode.mUID == v9 )
      UFG::qPrintf("UI Warning: Could not find texture %s, using default!\n", textureName);
    v14 = HIWORD(mData[1].mNode.mChild[0]);
    v15 = WORD2(mData[1].mNode.mChild[0]);
    pObject = (UFG::UIGfxTextureManager *)this->pTextureManager.pObject;
    v17 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
            Scaleform::Memory::pGlobalHeap,
            56i64);
    v26 = v17;
    if ( v17 )
    {
      *(_QWORD *)v17 = &Scaleform::RefCountImplCore::`vftable;
      *(_DWORD *)(v17 + 8) = 1;
      *(_QWORD *)v17 = &Scaleform::RefCountVImpl::`vftable;
      *(_QWORD *)v17 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::`vftable;
      *(_QWORD *)v17 = &Scaleform::RefCountBaseV<Scaleform::Render::Image,3>::`vftable;
      *(_QWORD *)v17 = &Scaleform::Render::ImageBase::`vftable;
      *(_QWORD *)v17 = &Scaleform::Render::Image::`vftable;
      v13 = 0i64;
      *(_QWORD *)(v17 + 16) = 0i64;
      *(_QWORD *)(v17 + 24) = 0i64;
      *(_QWORD *)(v17 + 32) = 0i64;
      *(_QWORD *)v17 = &Scaleform::Render::TextureImage::`vftable;
      *(_DWORD *)(v17 + 40) = 1;
      *(_DWORD *)(v17 + 44) = v15;
      *(_DWORD *)(v17 + 48) = v14;
      *(_DWORD *)(v17 + 52) = 0;
    }
    else
    {
      v13 = 0i64;
      v17 = 0i64;
    }
    size.Width = v15;
    size.Height = v14;
    Texture = UFG::UIGfxTextureManager::CreateTexture(
                pObject,
                v8,
                (Scaleform::Render::Size<unsigned long>)&size,
                (Scaleform::Render::ImageBase *)v17);
    v19 = (Scaleform::Render::Image *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                        Scaleform::Memory::pGlobalHeap,
                                        56i64);
    v20 = v19;
    size = (Scaleform::Render::Size<unsigned long>)v19;
    if ( v19 )
    {
      Scaleform::Render::Image::Image(v19, Texture, 0i64);
      v20->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::TextureImage::`vftable;
      LODWORD(v20[1].vfptr) = 1;
      HIDWORD(v20[1].vfptr) = v15;
      v20[1].RefCount = v14;
      *((_DWORD *)&v20[1].RefCount + 1) = 0;
      v13 = v20;
    }
    if ( Texture )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)Texture);
    if ( v17 )
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v17 + 16i64))(v17);
  }
  else
  {
    UFG::qPrintf("UI Warning: Could not find texture %s!\n", textureName);
    v13 = 0i64;
  }
  v21 = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
  {
    v22 = UFG::qResourceWarehouse::Instance();
    v21 = UFG::qResourceWarehouse::GetInventory(v22, 0x8B43FABF);
    `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = v21;
  }
  UFG::qResourceHandle::Close(&v24, v21);
  UFG::qResourceHandle::~qResourceHandle(&v24);
  return v13;
}

