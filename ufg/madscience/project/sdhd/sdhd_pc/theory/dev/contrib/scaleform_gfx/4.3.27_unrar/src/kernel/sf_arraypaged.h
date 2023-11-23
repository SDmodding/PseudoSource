// File Line: 141
// RVA: 0x948000
// attributes: thunk
void __fastcall Scaleform::ArrayPagedBase<Scaleform::Render::GlyphCache::UpdateRect,6,16,Scaleform::AllocatorPagedLH_POD<Scaleform::Render::GlyphCache::UpdateRect,2>>::~ArrayPagedBase<Scaleform::Render::GlyphCache::UpdateRect,6,16,Scaleform::AllocatorPagedLH_POD<Scaleform::Render::GlyphCache::UpdateRect,2>>(
        Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2> > *this)
{
  Scaleform::ArrayPagedBase<Scaleform::Render::GlyphCache::UpdateRect,6,16,Scaleform::AllocatorPagedLH_POD<Scaleform::Render::GlyphCache::UpdateRect,2>>::ClearAndRelease(this);
}

// File Line: 153
// RVA: 0x7B4A90
void __fastcall Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329>>::ClearAndRelease(
        Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329> > *this)
{
  unsigned __int64 NumPages; // rcx
  unsigned __int64 Size; // rbp
  void **v4; // r14
  unsigned __int64 v5; // rbp
  unsigned __int64 v6; // rax
  __int64 v7; // rbx
  Scaleform::GFx::AS3::CallFrame *i; // rdi

  NumPages = this->NumPages;
  if ( NumPages )
  {
    Size = this->Size;
    v4 = (void **)&this->Pages[NumPages - 1];
    if ( Size )
      v5 = Size >> 6;
    else
      v5 = 0i64;
    do
    {
      v6 = --this->NumPages;
      if ( v6 >= v5 )
      {
        if ( v6 == v5 )
          v7 = this->Size & 0x3F;
        else
          v7 = 0i64;
      }
      else
      {
        v7 = 64i64;
      }
      for ( i = (Scaleform::GFx::AS3::CallFrame *)((char *)*v4 + 136 * v7 - 136); v7; --v7 )
        Scaleform::GFx::AS3::CallFrame::~CallFrame(i--);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, *v4--);
    }
    while ( this->NumPages );
    --this->NumPages;
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->Pages);
  }
  this->MaxPages = 0i64;
  this->NumPages = 0i64;
  this->Size = 0i64;
  this->Pages = 0i64;
}

// File Line: 185
// RVA: 0x70AC20
char __fastcall Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2>>::PushBackSafe(
        Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2> > *this,
        Scaleform::GFx::AS2::RefCountBaseGC<323> **val)
{
  unsigned __int64 v4; // rdi
  Scaleform::GFx::AS2::RefCountBaseGC<323> **v5; // rdx

  v4 = this->Size >> 10;
  if ( v4 >= this->NumPages
    && !Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2>>::allocatePageSafe(
          this,
          this->Size >> 10) )
  {
    return 0;
  }
  v5 = &this->Pages[v4][this->Size & 0x3FF];
  if ( !v5 )
    return 0;
  *v5 = *val;
  ++this->Size;
  return 1;
}

// File Line: 254
// RVA: 0x711320
void __fastcall Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2>>::Resize(
        Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2> > *this,
        unsigned __int64 newSize)
{
  unsigned __int64 Size; // rax
  unsigned __int64 NumPages; // rdi
  unsigned __int64 i; // rbp
  unsigned __int64 MaxPages; // r8
  Scaleform::GFx::AS2::RefCountBaseGC<323> ***Pages; // rdx
  Scaleform::GFx::AS2::RefCountBaseGC<323> ***v9; // rax
  int v10; // [rsp+30h] [rbp+8h] BYREF

  Size = this->Size;
  if ( newSize <= Size )
  {
    if ( newSize < Size )
      this->Size = newSize;
  }
  else
  {
    NumPages = this->NumPages;
    for ( i = (newSize + 1023) >> 10; NumPages < i; ++this->NumPages )
    {
      MaxPages = this->MaxPages;
      if ( NumPages >= MaxPages )
      {
        Pages = this->Pages;
        if ( Pages )
        {
          v9 = (Scaleform::GFx::AS2::RefCountBaseGC<323> ***)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(
                                                               Scaleform::Memory::pGlobalHeap,
                                                               Pages,
                                                               8 * MaxPages + 40);
        }
        else
        {
          v10 = 2;
          v9 = (Scaleform::GFx::AS2::RefCountBaseGC<323> ***)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                               Scaleform::Memory::pGlobalHeap,
                                                               this,
                                                               40i64,
                                                               &v10);
        }
        this->MaxPages += 5i64;
        this->Pages = v9;
      }
      v10 = 2;
      this->Pages[NumPages++] = (Scaleform::GFx::AS2::RefCountBaseGC<323> **)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                                               Scaleform::Memory::pGlobalHeap,
                                                                               this,
                                                                               0x2000i64,
                                                                               &v10);
    }
    this->Size = newSize;
  }
}

// File Line: 370
// RVA: 0x82BE40
void __fastcall Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329>>::allocatePage(
        Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329> > *this,
        unsigned __int64 nb)
{
  unsigned __int64 MaxPages; // r8
  Scaleform::GFx::AS3::CallFrame **Pages; // rdx
  Scaleform::GFx::AS3::CallFrame **v6; // rax
  int v7; // [rsp+30h] [rbp+8h] BYREF

  MaxPages = this->MaxPages;
  if ( nb >= MaxPages )
  {
    Pages = this->Pages;
    if ( Pages )
    {
      v6 = (Scaleform::GFx::AS3::CallFrame **)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(
                                                Scaleform::Memory::pGlobalHeap,
                                                Pages,
                                                8 * MaxPages + 512);
    }
    else
    {
      v7 = 329;
      v6 = (Scaleform::GFx::AS3::CallFrame **)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                Scaleform::Memory::pGlobalHeap,
                                                this,
                                                512i64,
                                                &v7);
    }
    this->MaxPages += 64i64;
    this->Pages = v6;
  }
  v7 = 329;
  this->Pages[nb] = (Scaleform::GFx::AS3::CallFrame *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                        Scaleform::Memory::pGlobalHeap,
                                                        this,
                                                        8704i64,
                                                        &v7);
  ++this->NumPages;
}

// File Line: 402
// RVA: 0x724E90
char __fastcall Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2>>::allocatePageSafe(
        Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2> > *this,
        unsigned __int64 nb)
{
  unsigned __int64 MaxPages; // r8
  Scaleform::GFx::AS2::RefCountBaseGC<323> ***Pages; // rdx
  Scaleform::GFx::AS2::RefCountBaseGC<323> ***v6; // rax
  int v8; // [rsp+30h] [rbp+8h] BYREF

  MaxPages = this->MaxPages;
  if ( nb >= MaxPages )
  {
    Pages = this->Pages;
    if ( Pages )
    {
      v6 = (Scaleform::GFx::AS2::RefCountBaseGC<323> ***)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(
                                                           Scaleform::Memory::pGlobalHeap,
                                                           Pages,
                                                           8 * MaxPages + 40);
    }
    else
    {
      v8 = 2;
      v6 = (Scaleform::GFx::AS2::RefCountBaseGC<323> ***)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                           Scaleform::Memory::pGlobalHeap,
                                                           this,
                                                           40i64,
                                                           &v8);
    }
    if ( !v6 )
      return 0;
    this->MaxPages += 5i64;
    this->Pages = v6;
  }
  v8 = 2;
  this->Pages[nb] = (Scaleform::GFx::AS2::RefCountBaseGC<323> **)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                                   Scaleform::Memory::pGlobalHeap,
                                                                   this,
                                                                   0x2000i64,
                                                                   &v8);
  if ( !this->Pages[nb] )
    return 0;
  ++this->NumPages;
  return 1;
}

