// File Line: 49
// RVA: 0x896750
void __fastcall Scaleform::GFx::FontHandle::FontHandle(
        Scaleform::GFx::FontHandle *this,
        Scaleform::Render::Text::FontManagerBase *pmanager,
        Scaleform::Render::Font *pfont,
        const char *pfontName,
        unsigned int overridenFontFlags,
        Scaleform::GFx::MovieDef *pdefImpl)
{
  Scaleform::Render::Text::FontHandle::FontHandle(this, pmanager, pfont, pfontName, overridenFontFlags);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::FontHandle::`vftable;
  if ( pdefImpl )
    _InterlockedExchangeAdd(&pdefImpl->RefCount.Value, 1u);
  this->pSourceMovieDef.pObject = pdefImpl;
}

// File Line: 53
// RVA: 0x8966F0
void __fastcall Scaleform::GFx::FontHandle::FontHandle(Scaleform::GFx::FontHandle *this, Scaleform::GFx::FontHandle *f)
{
  Scaleform::GFx::MovieDef *pObject; // rcx

  Scaleform::Render::Text::FontHandle::FontHandle(this, f);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::FontHandle::`vftable;
  pObject = f->pSourceMovieDef.pObject;
  if ( pObject )
    _InterlockedExchangeAdd(&pObject->RefCount.Value, 1u);
  this->pSourceMovieDef.pObject = f->pSourceMovieDef.pObject;
}

// File Line: 125
// RVA: 0x8A9140
bool __fastcall Scaleform::GFx::FontManager::NodePtr::operator==(
        Scaleform::GFx::FontManager::NodePtr *this,
        Scaleform::GFx::FontManager::NodePtr *other)
{
  Scaleform::GFx::FontHandle *pNode; // r8
  _QWORD *v5; // rax
  const char *v6; // rbx
  _QWORD *v7; // rax
  const char *v8; // rax

  pNode = other->pNode;
  if ( this->pNode == other->pNode )
    return 1;
  if ( (((this->pNode->OverridenFontFlags | this->pNode->pFont.pObject->Flags) ^ (pNode->OverridenFontFlags | pNode->pFont.pObject->Flags)) & 0x313) != 0 )
    return 0;
  v5 = (_QWORD *)(pNode->FontName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64);
  v6 = (*v5 & 0x7FFFFFFFFFFFFFFFi64) != 0
     ? (char *)v5 + 12
     : (const char *)((__int64 (__fastcall *)(Scaleform::Render::Font *))pNode->pFont.pObject->Scaleform::Render::Text::FontHandle::vfptr[1].__vecDelDtor)(pNode->pFont.pObject);
  v7 = (_QWORD *)(this->pNode->FontName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64);
  v8 = (*v7 & 0x7FFFFFFFFFFFFFFFi64) != 0
     ? (char *)v7 + 12
     : (const char *)((__int64 (__fastcall *)(Scaleform::Render::Font *))this->pNode->pFont.pObject->vfptr[1].__vecDelDtor)(this->pNode->pFont.pObject);
  return !Scaleform::String::CompareNoCase(v8, v6);
}

// File Line: 250
// RVA: 0x8A47C0
void __fastcall Scaleform::GFx::FontHandle::~FontHandle(Scaleform::GFx::FontHandle *this)
{
  Scaleform::Render::Text::FontManagerBase *pFontManager; // rcx
  Scaleform::Render::RenderBuffer *pObject; // rcx
  Scaleform::GFx::MovieDef *v4; // rsi
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::Render::RenderBuffer *v6; // rcx
  Scaleform::GFx::FontHandle *key; // [rsp+58h] [rbp+10h] BYREF
  Scaleform::StringLH *p_FontName; // [rsp+60h] [rbp+18h]

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::FontHandle::`vftable;
  pFontManager = this->pFontManager;
  if ( pFontManager )
  {
    key = this;
    if ( this != *(Scaleform::GFx::FontHandle **)&pFontManager[4].RefCount )
      Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::RemoveAlt<Scaleform::GFx::FontHandle *>(
        (Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> > *)&pFontManager[1],
        &key);
  }
  pObject = (Scaleform::Render::RenderBuffer *)this->pFont.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pFont.pObject = 0i64;
  v4 = this->pSourceMovieDef.pObject;
  if ( v4 && !_InterlockedDecrement(&v4->RefCount.Value) )
  {
    pLib = v4->pLib;
    if ( pLib )
    {
      pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)v4);
      v4->pLib = 0i64;
    }
    v4->Scaleform::GFx::Resource::vfptr->__vecDelDtor(v4, 1u);
  }
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Text::FontHandle::`vftable;
  v6 = (Scaleform::Render::RenderBuffer *)this->pFont.pObject;
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
  p_FontName = &this->FontName;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((this->FontName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}

