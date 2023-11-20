// File Line: 141
// RVA: 0x948000
void __fastcall Scaleform::ArrayPagedBase<Scaleform::Render::GlyphCache::UpdateRect,6,16,Scaleform::AllocatorPagedLH_POD<Scaleform::Render::GlyphCache::UpdateRect,2>>::~ArrayPagedBase<Scaleform::Render::GlyphCache::UpdateRect,6,16,Scaleform::AllocatorPagedLH_POD<Scaleform::Render::GlyphCache::UpdateRect,2>>(Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2> > *this)
{
  Scaleform::ArrayPagedBase<Scaleform::Render::GlyphCache::UpdateRect,6,16,Scaleform::AllocatorPagedLH_POD<Scaleform::Render::GlyphCache::UpdateRect,2>>::ClearAndRelease(this);
}

// File Line: 153
// RVA: 0x7B4A90
void __fastcall Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329>>::ClearAndRelease(Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329> > *this)
{
  Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329> > *v1; // rsi
  unsigned __int64 v2; // rcx
  unsigned __int64 v3; // rbp
  void **v4; // r14
  unsigned __int64 v5; // rbp
  unsigned __int64 v6; // rax
  signed __int64 v7; // rbx
  Scaleform::GFx::AS3::CallFrame *i; // rdi

  v1 = this;
  v2 = this->NumPages;
  if ( v2 )
  {
    v3 = v1->Size;
    v4 = (void **)&v1->Pages[v2 - 1];
    if ( v3 )
      v5 = v3 >> 6;
    else
      v5 = 0i64;
    do
    {
      v6 = --v1->NumPages;
      if ( v6 >= v5 )
      {
        if ( v6 == v5 )
          v7 = v1->Size & 0x3F;
        else
          v7 = 0i64;
      }
      else
      {
        v7 = 64i64;
      }
      for ( i = (Scaleform::GFx::AS3::CallFrame *)((char *)*v4 + 136 * v7 - 136); v7; --v7 )
      {
        Scaleform::GFx::AS3::CallFrame::~CallFrame(i);
        --i;
      }
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, *v4);
      --v4;
    }
    while ( v1->NumPages );
    --v1->NumPages;
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->Pages);
  }
  v1->MaxPages = 0i64;
  v1->NumPages = 0i64;
  v1->Size = 0i64;
  v1->Pages = 0i64;
}

// File Line: 185
// RVA: 0x70AC20
char __fastcall Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2>>::PushBackSafe(Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2> > *this, Scaleform::GFx::AS2::RefCountBaseGC<323> *const *val)
{
  Scaleform::GFx::AS2::RefCountBaseGC<323> *const *v2; // rsi
  Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2> > *v3; // rbx
  unsigned __int64 v4; // rdi
  Scaleform::GFx::AS2::RefCountBaseGC<323> **v5; // rdx

  v2 = val;
  v3 = this;
  v4 = this->Size >> 10;
  if ( v4 >= this->NumPages
    && !Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2>>::allocatePageSafe(
          this,
          this->Size >> 10) )
  {
    return 0;
  }
  v5 = &v3->Pages[v4][v3->Size & 0x3FF];
  if ( !v5 )
    return 0;
  *v5 = *v2;
  ++v3->Size;
  return 1;
}

// File Line: 254
// RVA: 0x711320
void __fastcall Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2>>::Resize(Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2> > *this, unsigned __int64 newSize)
{
  unsigned __int64 v2; // rax
  unsigned __int64 v3; // rsi
  Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2> > *v4; // rbx
  unsigned __int64 v5; // rdi
  unsigned __int64 i; // rbp
  unsigned __int64 v7; // r8
  Scaleform::GFx::AS2::RefCountBaseGC<323> ***v8; // rdx
  Scaleform::GFx::AS2::RefCountBaseGC<323> ***v9; // rax
  int v10; // [rsp+30h] [rbp+8h]

  v2 = this->Size;
  v3 = newSize;
  v4 = this;
  if ( newSize <= v2 )
  {
    if ( newSize < v2 )
      this->Size = newSize;
  }
  else
  {
    v5 = this->NumPages;
    for ( i = (newSize + 1023) >> 10; v5 < i; ++v4->NumPages )
    {
      v7 = v4->MaxPages;
      if ( v5 >= v7 )
      {
        v8 = v4->Pages;
        if ( v8 )
        {
          v9 = (Scaleform::GFx::AS2::RefCountBaseGC<323> ***)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(
                                                               Scaleform::Memory::pGlobalHeap,
                                                               v8,
                                                               8 * v7 + 40);
        }
        else
        {
          v10 = 2;
          v9 = (Scaleform::GFx::AS2::RefCountBaseGC<323> ***)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                               Scaleform::Memory::pGlobalHeap,
                                                               v4,
                                                               40ui64,
                                                               (Scaleform::AllocInfo *)&v10);
        }
        v4->MaxPages += 5i64;
        v4->Pages = v9;
      }
      v10 = 2;
      v4->Pages[++v5 - 1] = (Scaleform::GFx::AS2::RefCountBaseGC<323> **)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                                           Scaleform::Memory::pGlobalHeap,
                                                                           v4,
                                                                           0x2000ui64,
                                                                           (Scaleform::AllocInfo *)&v10);
    }
    v4->Size = v3;
  }
}

// File Line: 370
// RVA: 0x82BE40
void __fastcall Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329>>::allocatePage(Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329> > *this, unsigned __int64 nb)
{
  unsigned __int64 v2; // r8
  unsigned __int64 v3; // rdi
  Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329> > *v4; // rbx
  Scaleform::GFx::AS3::CallFrame **v5; // rdx
  Scaleform::GFx::AS3::CallFrame **v6; // rax
  int v7; // [rsp+30h] [rbp+8h]

  v2 = this->MaxPages;
  v3 = nb;
  v4 = this;
  if ( nb >= v2 )
  {
    v5 = this->Pages;
    if ( v5 )
    {
      v6 = (Scaleform::GFx::AS3::CallFrame **)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(
                                                Scaleform::Memory::pGlobalHeap,
                                                v5,
                                                8 * v2 + 512);
    }
    else
    {
      v7 = 329;
      v6 = (Scaleform::GFx::AS3::CallFrame **)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                Scaleform::Memory::pGlobalHeap,
                                                this,
                                                512ui64,
                                                (Scaleform::AllocInfo *)&v7);
    }
    v4->MaxPages += 64i64;
    v4->Pages = v6;
  }
  v7 = 329;
  v4->Pages[v3] = (Scaleform::GFx::AS3::CallFrame *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                      Scaleform::Memory::pGlobalHeap,
                                                      v4,
                                                      8704ui64,
                                                      (Scaleform::AllocInfo *)&v7);
  ++v4->NumPages;
}

// File Line: 402
// RVA: 0x724E90
char __fastcall Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2>>::allocatePageSafe(Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2> > *this, unsigned __int64 nb)
{
  unsigned __int64 v2; // r8
  unsigned __int64 v3; // rdi
  Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2> > *v4; // rbx
  Scaleform::GFx::AS2::RefCountBaseGC<323> ***v5; // rdx
  Scaleform::GFx::AS2::RefCountBaseGC<323> ***v6; // rax
  int v8; // [rsp+30h] [rbp+8h]

  v2 = this->MaxPages;
  v3 = nb;
  v4 = this;
  if ( nb >= v2 )
  {
    v5 = this->Pages;
    if ( v5 )
    {
      v6 = (Scaleform::GFx::AS2::RefCountBaseGC<323> ***)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(
                                                           Scaleform::Memory::pGlobalHeap,
                                                           v5,
                                                           8 * v2 + 40);
    }
    else
    {
      v8 = 2;
      v6 = (Scaleform::GFx::AS2::RefCountBaseGC<323> ***)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                           Scaleform::Memory::pGlobalHeap,
                                                           this,
                                                           40ui64,
                                                           (Scaleform::AllocInfo *)&v8);
    }
    if ( !v6 )
      return 0;
    v4->MaxPages += 5i64;
    v4->Pages = v6;
  }
  v8 = 2;
  v4->Pages[v3] = (Scaleform::GFx::AS2::RefCountBaseGC<323> **)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                                 Scaleform::Memory::pGlobalHeap,
                                                                 v4,
                                                                 0x2000ui64,
                                                                 (Scaleform::AllocInfo *)&v8);
  if ( !v4->Pages[v3] )
    return 0;
  ++v4->NumPages;
  return 1;
}

