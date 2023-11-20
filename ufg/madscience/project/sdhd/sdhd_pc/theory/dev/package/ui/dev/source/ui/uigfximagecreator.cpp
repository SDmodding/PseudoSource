// File Line: 21
// RVA: 0x15AAA10
__int64 UFG::_dynamic_initializer_for__DEFAULT_TEXTURE__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("DEFAULT", 0xFFFFFFFF);
  DEFAULT_TEXTURE = result;
  return result;
}

// File Line: 27
// RVA: 0xA23120
void __fastcall UFG::UIGfxImageCreator::UIGfxImageCreator(UFG::UIGfxImageCreator *this, Scaleform::Render::TextureManager *textureManager)
{
  UFG::UIGfxImageCreator *v2; // rbx

  v2 = this;
  Scaleform::GFx::ImageCreator::ImageCreator((Scaleform::GFx::ImageCreator *)&this->vfptr, textureManager);
  v2->vfptr = (Scaleform::RefCountImplCoreVtbl *)&UFG::UIGfxImageCreator::`vftable';
}

// File Line: 33
// RVA: 0xA278B0
Scaleform::Render::Image *__fastcall UFG::UIGfxImageCreator::LoadExportedImage(UFG::UIGfxImageCreator *this, Scaleform::GFx::ImageCreateExportInfo *info, Scaleform::String *url)
{
  Scaleform::String *v3; // rsi
  Scaleform::GFx::ImageCreateExportInfo *v4; // rbx
  UFG::UIGfxImageCreator *v5; // rdi
  unsigned __int64 v6; // rcx
  Scaleform::Render::Image *result; // rax

  v3 = url;
  v4 = info;
  v5 = this;
  if ( (unsigned int)(info->Type - 1) > 1
    || (v6 = info->ExportName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64, v6 == -12i64)
    || (signed int)UFG::qStringLength((const char *)(v6 + 12)) <= 0 )
  {
    result = Scaleform::GFx::ImageCreator::LoadExportedImage((Scaleform::GFx::ImageCreator *)&v5->vfptr, v4, v3);
  }
  else
  {
    result = UFG::UIGfxImageCreator::LoadIllusionTexture(
               v5,
               (const char *)((v4->ExportName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
  }
  return result;
}

// File Line: 51
// RVA: 0xA27C00
Scaleform::Render::Image *__fastcall UFG::UIGfxImageCreator::LoadProtocolImage(UFG::UIGfxImageCreator *this, Scaleform::GFx::ImageCreateInfo *info, Scaleform::String *url)
{
  Scaleform::String *v3; // rbx
  UFG::UIGfxImageCreator *v4; // rdi
  signed __int64 v5; // rax
  Scaleform::String *v6; // rax
  Scaleform::Render::Image *v7; // rax
  Scaleform::Render::Image *v8; // rbx
  Scaleform::String result; // [rsp+58h] [rbp+20h]

  v3 = url;
  v4 = this;
  v5 = Scaleform::String::GetLength(url);
  v6 = Scaleform::String::Substring(v3, &result, 6ui64, v5);
  v7 = UFG::UIGfxImageCreator::LoadIllusionTexture(v4, (const char *)((v6->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
  v8 = v7;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((result.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
  {
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    v7 = v8;
  }
  return v7;
}

// File Line: 59
// RVA: 0xA27930
Scaleform::Render::Image *__fastcall UFG::UIGfxImageCreator::LoadIllusionTexture(UFG::UIGfxImageCreator *this, const char *textureName)
{
  const char *v2; // rdi
  UFG::UIGfxImageCreator *v3; // rbp
  unsigned int v4; // ebx
  UFG::qResourceInventory *v5; // rax
  UFG::qResourceWarehouse *v6; // rax
  UFG::qResourceData *v7; // rbx
  Illusion::Texture *v8; // rsi
  unsigned int v9; // eax
  unsigned int v10; // ebx
  UFG::qResourceInventory *v11; // rax
  UFG::qResourceWarehouse *v12; // rax
  Scaleform::Render::Image *v13; // rdi
  unsigned int v14; // er14
  unsigned int v15; // er15
  UFG::UIGfxTextureManager *v16; // rbp
  __int64 v17; // rbx
  __int64 v18; // rt1
  __int64 v19; // rax
  Scaleform::Render::Texture *v20; // rbp
  Scaleform::Render::Image *v21; // rax
  Scaleform::Render::Image *v22; // rsi
  UFG::qResourceInventory *v23; // rax
  UFG::qResourceWarehouse *v24; // rax
  UFG::qResourceHandle v26; // [rsp+38h] [rbp-50h]
  Scaleform::Render::Size<unsigned long> size; // [rsp+A0h] [rbp+18h]
  __int64 v28; // [rsp+A8h] [rbp+20h]

  v2 = textureName;
  v3 = this;
  v4 = UFG::qStringHashUpper32(textureName, 0xFFFFFFFF);
  UFG::qResourceHandle::qResourceHandle(&v26);
  v5 = `UFG::qGetResourceInventory<Illusion::Texture>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Texture>'::`2'::result )
  {
    v6 = UFG::qResourceWarehouse::Instance();
    v5 = UFG::qResourceWarehouse::GetInventory(v6, 0x8B43FABF);
    `UFG::qGetResourceInventory<Illusion::Texture>'::`2'::result = v5;
  }
  UFG::qResourceHandle::Init(&v26, 0x8B43FABF, v4, v5);
  v7 = v26.mData;
  v8 = (Illusion::Texture *)v26.mData;
  if ( !v26.mData || (v9 = DEFAULT_TEXTURE, v26.mData->mNode.mUID == DEFAULT_TEXTURE) )
  {
    v10 = UFG::qToUInt32(v2, 0);
    v11 = `UFG::qGetResourceInventory<Illusion::Texture>'::`2'::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Texture>'::`2'::result )
    {
      v12 = UFG::qResourceWarehouse::Instance();
      v11 = UFG::qResourceWarehouse::GetInventory(v12, 0x8B43FABF);
      `UFG::qGetResourceInventory<Illusion::Texture>'::`2'::result = v11;
    }
    UFG::qResourceHandle::Init(&v26, 0x8B43FABF, v10, v11);
    v8 = (Illusion::Texture *)v26.mData;
    UFG::qPrintf("Failed to find a texture by name; direct hash texture = %p\n", v26.mData);
    v7 = v26.mData;
    v9 = DEFAULT_TEXTURE;
  }
  if ( v8 )
  {
    if ( v8->mNode.mUID == v9 )
      UFG::qPrintf("UI Warning: Could not find texture %s, using default!\n", v2);
    v14 = HIWORD(v7[1].mNode.mChild[0]);
    v15 = WORD2(v7[1].mNode.mChild[0]);
    v16 = (UFG::UIGfxTextureManager *)v3->pTextureManager.pObject;
    v17 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
            Scaleform::Memory::pGlobalHeap,
            56i64);
    v28 = v17;
    if ( v17 )
    {
      *(_QWORD *)v17 = &Scaleform::RefCountImplCore::`vftable';
      *(_DWORD *)(v17 + 8) = 1;
      *(_QWORD *)v17 = &Scaleform::RefCountVImpl::`vftable';
      *(_QWORD *)v17 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountVImpl,3>::`vftable';
      *(_QWORD *)v17 = &Scaleform::RefCountBaseV<Scaleform::Render::Image,3>::`vftable';
      *(_QWORD *)v17 = &Scaleform::Render::ImageBase::`vftable';
      *(_QWORD *)v17 = &Scaleform::Render::Image::`vftable';
      v13 = 0i64;
      *(_QWORD *)(v17 + 16) = 0i64;
      v18 = *(_QWORD *)(v17 + 16);
      v19 = *(_QWORD *)(v17 + 16);
      *(_QWORD *)(v17 + 24) = 0i64;
      *(_QWORD *)(v17 + 32) = 0i64;
      *(_QWORD *)v17 = &Scaleform::Render::TextureImage::`vftable';
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
    v20 = UFG::UIGfxTextureManager::CreateTexture(
            v16,
            v8,
            (Scaleform::Render::Size<unsigned long>)&size,
            (Scaleform::Render::ImageBase *)v17);
    v21 = (Scaleform::Render::Image *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                        Scaleform::Memory::pGlobalHeap,
                                        56i64);
    v22 = v21;
    size = (Scaleform::Render::Size<unsigned long>)v21;
    if ( v21 )
    {
      Scaleform::Render::Image::Image(v21, v20, 0i64);
      v22->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::TextureImage::`vftable';
      LODWORD(v22[1].vfptr) = 1;
      HIDWORD(v22[1].vfptr) = v15;
      v22[1].RefCount = v14;
      *((_DWORD *)&v22[1].RefCount + 1) = 0;
      v13 = v22;
    }
    if ( v20 )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v20);
    if ( v17 )
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v17 + 16i64))(v17);
  }
  else
  {
    UFG::qPrintf("UI Warning: Could not find texture %s!\n", v2);
    v13 = 0i64;
  }
  v23 = `UFG::qGetResourceInventory<Illusion::Texture>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Texture>'::`2'::result )
  {
    v24 = UFG::qResourceWarehouse::Instance();
    v23 = UFG::qResourceWarehouse::GetInventory(v24, 0x8B43FABF);
    `UFG::qGetResourceInventory<Illusion::Texture>'::`2'::result = v23;
  }
  UFG::qResourceHandle::Close(&v26, v23);
  UFG::qResourceHandle::~qResourceHandle(&v26);
  return v13;
}

