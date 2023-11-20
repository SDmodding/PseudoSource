// File Line: 49
// RVA: 0x896750
void __fastcall Scaleform::GFx::FontHandle::FontHandle(Scaleform::GFx::FontHandle *this, Scaleform::Render::Text::FontManagerBase *pmanager, Scaleform::Render::Font *pfont, const char *pfontName, unsigned int overridenFontFlags, Scaleform::GFx::MovieDef *pdefImpl)
{
  Scaleform::GFx::FontHandle *v6; // rbx

  v6 = this;
  Scaleform::Render::Text::FontHandle::FontHandle(
    (Scaleform::Render::Text::FontHandle *)&this->vfptr,
    pmanager,
    pfont,
    pfontName,
    overridenFontFlags);
  v6->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::FontHandle::`vftable';
  if ( pdefImpl )
    _InterlockedExchangeAdd(&pdefImpl->RefCount.Value, 1u);
  v6->pSourceMovieDef.pObject = pdefImpl;
}

// File Line: 53
// RVA: 0x8966F0
void __fastcall Scaleform::GFx::FontHandle::FontHandle(Scaleform::GFx::FontHandle *this, Scaleform::GFx::FontHandle *f)
{
  Scaleform::GFx::FontHandle *v2; // rdi
  Scaleform::GFx::FontHandle *v3; // rbx
  Scaleform::GFx::MovieDef *v4; // rcx

  v2 = f;
  v3 = this;
  Scaleform::Render::Text::FontHandle::FontHandle(
    (Scaleform::Render::Text::FontHandle *)&this->vfptr,
    (Scaleform::Render::Text::FontHandle *)&f->vfptr);
  v3->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::FontHandle::`vftable';
  v4 = v2->pSourceMovieDef.pObject;
  if ( v4 )
    _InterlockedExchangeAdd(&v4->RefCount.Value, 1u);
  v3->pSourceMovieDef.pObject = v2->pSourceMovieDef.pObject;
}

// File Line: 125
// RVA: 0x8A9140
char __fastcall Scaleform::GFx::FontManager::NodePtr::operator==(Scaleform::GFx::FontManager::NodePtr *this, Scaleform::GFx::FontManager::NodePtr *other)
{
  Scaleform::GFx::FontHandle *v2; // r8
  Scaleform::GFx::FontManager::NodePtr *v3; // rdi
  _QWORD *v5; // rax
  const char *v6; // rbx
  _QWORD *v7; // rax
  const char *v8; // rax

  v2 = other->pNode;
  v3 = this;
  if ( this->pNode == other->pNode )
    return 1;
  if ( ((this->pNode->OverridenFontFlags | this->pNode->pFont.pObject->Flags) ^ (v2->OverridenFontFlags | v2->pFont.pObject->Flags)) & 0x313 )
    return 0;
  v5 = (_QWORD *)(v2->FontName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64);
  v6 = (const char *)(*v5 & 0x7FFFFFFFFFFFFFFFi64 ? (_QWORD *)((char *)v5 + 12) : ((__int64 (*)(void))v2->pFont.pObject->vfptr[1].__vecDelDtor)());
  v7 = (_QWORD *)(v3->pNode->FontName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64);
  v8 = (const char *)(*v7 & 0x7FFFFFFFFFFFFFFFi64 ? (_QWORD *)((char *)v7 + 12) : ((__int64 (*)(void))v3->pNode->pFont.pObject->vfptr[1].__vecDelDtor)());
  if ( Scaleform::String::CompareNoCase(v8, v6) )
    return 0;
  return 1;
}

// File Line: 250
// RVA: 0x8A47C0
void __fastcall Scaleform::GFx::FontHandle::~FontHandle(Scaleform::GFx::FontHandle *this)
{
  Scaleform::GFx::FontHandle *v1; // rdi
  Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> > *v2; // rcx
  Scaleform::Render::RenderBuffer *v3; // rcx
  Scaleform::GFx::MovieDef *v4; // rsi
  Scaleform::GFx::ResourceLibBase *v5; // rcx
  Scaleform::Render::RenderBuffer *v6; // rcx
  Scaleform::GFx::FontHandle *key; // [rsp+58h] [rbp+10h]
  Scaleform::StringLH *v8; // [rsp+60h] [rbp+18h]

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::FontHandle::`vftable';
  v2 = (Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> > *)this->pFontManager;
  if ( v2 )
  {
    key = v1;
    if ( v1 != (Scaleform::GFx::FontHandle *)v2[9].pTable )
      Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::RemoveAlt<Scaleform::GFx::FontHandle *>(
        v2 + 2,
        &key);
  }
  v3 = (Scaleform::Render::RenderBuffer *)v1->pFont.pObject;
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
  v1->pFont.pObject = 0i64;
  v4 = v1->pSourceMovieDef.pObject;
  if ( v4 && !_InterlockedDecrement(&v4->RefCount.Value) )
  {
    v5 = v4->pLib;
    if ( v5 )
    {
      v5->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v5->vfptr, (unsigned int)v4);
      v4->pLib = 0i64;
    }
    v4->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v4->vfptr, 1u);
  }
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Text::FontHandle::`vftable';
  v6 = (Scaleform::Render::RenderBuffer *)v1->pFont.pObject;
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
  v8 = &v1->FontName;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v1->FontName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)&v1->vfptr);
}

