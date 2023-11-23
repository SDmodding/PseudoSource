// File Line: 67
// RVA: 0x896850
void __fastcall Scaleform::Render::Text::FontHandle::FontHandle(
        Scaleform::Render::Text::FontHandle *this,
        Scaleform::Render::Text::FontManagerBase *pmanager,
        Scaleform::GFx::Resource *pfont,
        const char *pfontName,
        unsigned int overridenFontFlags)
{
  const char *v8; // rax

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,74>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::Text::FontHandle,74>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Text::FontHandle::`vftable;
  this->pFontManager = pmanager;
  this->OverridenFontFlags = overridenFontFlags;
  Scaleform::StringLH::StringLH(&this->FontName);
  this->FontScaleFactor = 1.0;
  if ( pfont )
    Scaleform::Render::RenderBuffer::AddRef(pfont);
  this->pFont.pObject = (Scaleform::Render::Font *)pfont;
  if ( pfontName )
  {
    v8 = (const char *)((__int64 (__fastcall *)(Scaleform::GFx::Resource *))pfont->vfptr->GetKey)(pfont);
    if ( Scaleform::String::CompareNoCase(v8, pfontName) )
      Scaleform::String::operator=(&this->FontName, pfontName);
  }
}

// File Line: 75
// RVA: 0x8967A0
void __fastcall Scaleform::Render::Text::FontHandle::FontHandle(
        Scaleform::Render::Text::FontHandle *this,
        Scaleform::Render::Text::FontHandle *f)
{
  Scaleform::Render::Font *pObject; // rcx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,74>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::Text::FontHandle,74>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Text::FontHandle::`vftable;
  this->pFontManager = f->pFontManager;
  this->OverridenFontFlags = f->OverridenFontFlags;
  Scaleform::StringLH::CopyConstructHelper(&this->FontName, &f->FontName);
  this->FontScaleFactor = f->FontScaleFactor;
  pObject = f->pFont.pObject;
  if ( pObject )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)pObject);
  this->pFont.pObject = f->pFont.pObject;
}

// File Line: 77
// RVA: 0x8A48A0
void __fastcall Scaleform::Render::Text::FontHandle::~FontHandle(Scaleform::Render::Text::FontHandle *this)
{
  Scaleform::Render::RenderBuffer *pObject; // rcx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Text::FontHandle::`vftable;
  pObject = (Scaleform::Render::RenderBuffer *)this->pFont.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((this->FontName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}

// File Line: 101
// RVA: 0x94E7C0
bool __fastcall Scaleform::Render::Text::FontHandle::operator==(
        Scaleform::Render::Text::FontHandle *this,
        Scaleform::Render::Text::FontHandle *f)
{
  unsigned __int8 *v4; // rax
  unsigned __int64 v5; // r8
  int v6; // ecx
  int v7; // edx

  if ( this->pFontManager != f->pFontManager
    || this->pFont.pObject != f->pFont.pObject
    || this->OverridenFontFlags != f->OverridenFontFlags )
  {
    return 0;
  }
  v4 = (unsigned __int8 *)((this->FontName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
  v5 = (f->FontName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) - (this->FontName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64);
  do
  {
    v6 = v4[v5];
    v7 = *v4 - v6;
    if ( v7 )
      break;
    ++v4;
  }
  while ( v6 );
  return !v7 && f->FontScaleFactor == this->FontScaleFactor;
}

// File Line: 125
// RVA: 0x8A4A30
void __fastcall Scaleform::Render::Text::FontManagerBase::~FontManagerBase(
        Scaleform::Render::Text::FontManagerBase *this)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Text::FontManagerBase::`vftable;
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}

