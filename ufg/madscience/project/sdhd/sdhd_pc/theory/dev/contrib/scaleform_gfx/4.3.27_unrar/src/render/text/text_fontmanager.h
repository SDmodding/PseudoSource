// File Line: 67
// RVA: 0x896850
void __fastcall Scaleform::Render::Text::FontHandle::FontHandle(Scaleform::Render::Text::FontHandle *this, Scaleform::Render::Text::FontManagerBase *pmanager, Scaleform::Render::Font *pfont, const char *pfontName, unsigned int overridenFontFlags)
{
  const char *v5; // rsi
  Scaleform::Render::Font *v6; // rdi
  Scaleform::Render::Text::FontHandle *v7; // rbx
  const char *v8; // rax

  v5 = pfontName;
  v6 = pfont;
  v7 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,74>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::Text::FontHandle,74>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Text::FontHandle::`vftable';
  this->pFontManager = pmanager;
  this->OverridenFontFlags = overridenFontFlags;
  Scaleform::StringLH::StringLH(&this->FontName);
  v7->FontScaleFactor = 1.0;
  if ( v6 )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v6);
  v7->pFont.pObject = v6;
  if ( v5 )
  {
    v8 = (const char *)((__int64 (__fastcall *)(Scaleform::Render::Font *))v6->vfptr[1].__vecDelDtor)(v6);
    if ( Scaleform::String::CompareNoCase(v8, v5) )
      Scaleform::String::operator=((Scaleform::String *)&v7->FontName.0, v5);
  }
}

// File Line: 75
// RVA: 0x8967A0
void __fastcall Scaleform::Render::Text::FontHandle::FontHandle(Scaleform::Render::Text::FontHandle *this, Scaleform::Render::Text::FontHandle *f)
{
  Scaleform::Render::Text::FontHandle *v2; // rdi
  Scaleform::Render::Text::FontHandle *v3; // rbx
  Scaleform::GFx::Resource *v4; // rcx

  v2 = f;
  v3 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,74>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::Text::FontHandle,74>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Text::FontHandle::`vftable';
  this->pFontManager = f->pFontManager;
  this->OverridenFontFlags = f->OverridenFontFlags;
  Scaleform::StringLH::CopyConstructHelper(&this->FontName, (Scaleform::String *)&f->FontName.0);
  v3->FontScaleFactor = v2->FontScaleFactor;
  v4 = (Scaleform::GFx::Resource *)v2->pFont.pObject;
  if ( v4 )
    Scaleform::Render::RenderBuffer::AddRef(v4);
  v3->pFont.pObject = v2->pFont.pObject;
}

// File Line: 77
// RVA: 0x8A48A0
void __fastcall Scaleform::Render::Text::FontHandle::~FontHandle(Scaleform::Render::Text::FontHandle *this)
{
  Scaleform::Render::Text::FontHandle *v1; // rbx
  Scaleform::Render::RenderBuffer *v2; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Text::FontHandle::`vftable';
  v2 = (Scaleform::Render::RenderBuffer *)this->pFont.pObject;
  if ( v2 )
    Scaleform::RefCountImpl::Release(v2);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v1->FontName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)&v1->vfptr);
}

// File Line: 101
// RVA: 0x94E7C0
char __fastcall Scaleform::Render::Text::FontHandle::operator==(Scaleform::Render::Text::FontHandle *this, Scaleform::Render::Text::FontHandle *f)
{
  Scaleform::Render::Text::FontHandle *v2; // r9
  Scaleform::Render::Text::FontHandle *v3; // r10
  unsigned __int8 *v4; // rax
  unsigned __int64 v5; // r8
  int v6; // ecx
  int v7; // edx
  char result; // al

  v2 = f;
  v3 = this;
  if ( this->pFontManager != f->pFontManager
    || this->pFont.pObject != f->pFont.pObject
    || this->OverridenFontFlags != f->OverridenFontFlags )
  {
    goto LABEL_13;
  }
  v4 = (unsigned __int8 *)((this->FontName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
  v5 = (f->FontName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) - (this->FontName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64);
  do
  {
    v6 = v4[v5];
    v7 = *v4 - v6;
    if ( *v4 != v6 )
      break;
    ++v4;
  }
  while ( v6 );
  if ( v7 || v2->FontScaleFactor != v3->FontScaleFactor )
LABEL_13:
    result = 0;
  else
    result = 1;
  return result;
}

// File Line: 125
// RVA: 0x8A4A30
void __fastcall Scaleform::Render::Text::FontManagerBase::~FontManagerBase(Scaleform::Render::Text::FontManagerBase *this)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Text::FontManagerBase::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)&this->vfptr);
}

