// File Line: 36
// RVA: 0x8A1250
void __fastcall Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Image *,32,2>::~ArrayStaticBuffPOD<Scaleform::Render::Image *,32,2>(Scaleform::ArrayStaticBuffPOD<Scaleform::RefCountImpl *,32,2> *this)
{
  Scaleform::RefCountImpl **v1; // rdi
  Scaleform::ArrayStaticBuffPOD<Scaleform::RefCountImpl *,32,2> *v2; // rbx

  v1 = this->Static;
  v2 = this;
  if ( this->Data == this->Static )
  {
    this->Data = v1;
    this->Size = 0i64;
  }
  else
  {
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    v2->Data = v1;
    v2->Size = 0i64;
  }
}

// File Line: 49
// RVA: 0x9A2720
void __fastcall Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Font *,32,2>::PushBack(Scaleform::ArrayStaticBuffPOD<Scaleform::RefCountImpl *,32,2> *this, Scaleform::RefCountImpl *const *val)
{
  Scaleform::ArrayStaticBuffPOD<Scaleform::RefCountImpl *,32,2> *v2; // rbx
  unsigned __int64 v3; // rcx
  Scaleform::RefCountImpl *const *v4; // rdi
  Scaleform::MemoryHeap *v5; // rcx
  signed __int64 v6; // r8
  Scaleform::RefCountImpl **v7; // rax
  Scaleform::RefCountImpl **v8; // rcx
  Scaleform::RefCountImpl **v9; // rdx
  signed __int64 v10; // rax
  __int128 v11; // xmm0
  unsigned __int64 v12; // rax
  Scaleform::RefCountImpl **v13; // rdx
  signed __int64 v14; // rax

  v2 = this;
  v3 = this->Size;
  v4 = val;
  if ( v3 >= 0x20 )
  {
    if ( v3 == 32 )
    {
      v5 = v2->pHeap;
      v6 = 2 * v2->Reserved;
      v2->Reserved = v6;
      if ( v5 )
        v7 = (Scaleform::RefCountImpl **)v5->vfptr->Alloc(v5, 8 * v6, 0i64);
      else
        v7 = (Scaleform::RefCountImpl **)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                           Scaleform::Memory::pGlobalHeap,
                                           v2,
                                           8 * v6,
                                           0i64);
      v8 = v7;
      v2->Data = v7;
      v9 = v2->Static;
      if ( ((unsigned __int8)v7 | (unsigned __int8)((_BYTE)v2 + 24)) & 0xF )
      {
        memmove(v7, v9, 0x100ui64);
      }
      else
      {
        v10 = 2i64;
        do
        {
          v11 = *(_OWORD *)v9;
          v8 += 16;
          v9 += 16;
          *((_OWORD *)v8 - 8) = v11;
          *((_OWORD *)v8 - 7) = *((_OWORD *)v9 - 7);
          *((_OWORD *)v8 - 6) = *((_OWORD *)v9 - 6);
          *((_OWORD *)v8 - 5) = *((_OWORD *)v9 - 5);
          *((_OWORD *)v8 - 4) = *((_OWORD *)v9 - 4);
          *((_OWORD *)v8 - 3) = *((_OWORD *)v9 - 3);
          *((_OWORD *)v8 - 2) = *((_OWORD *)v9 - 2);
          *((_OWORD *)v8 - 1) = *((_OWORD *)v9 - 1);
          --v10;
        }
        while ( v10 );
      }
    }
    else
    {
      v12 = v2->Reserved;
      if ( v3 >= v12 )
      {
        v13 = v2->Data;
        v14 = 2 * v12;
        v2->Reserved = v14;
        v2->Data = (Scaleform::RefCountImpl **)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 v13,
                                                 8 * v14);
      }
    }
    v2->Data[v2->Size++] = *v4;
  }
  else
  {
    v2->Static[v3] = *val;
    ++v2->Size;
  }
}

// File Line: 112
// RVA: 0x7865C0
void __fastcall Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2>::~ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2>(Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2> *this)
{
  Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2> *v1; // rbx

  v1 = this;
  Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2>::Clear(this);
  `eh vector destructor iterator'(
    v1->Static,
    8ui64,
    32,
    (void (__fastcall *)(void *))Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent>::~SPtr<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent>);
}

// File Line: 117
// RVA: 0x7B3D40
void __fastcall Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2>::Clear(Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2> *this)
{
  Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2> *v1; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *v2; // rbp
  Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2> *v3; // rsi
  unsigned __int64 i; // rdi
  Scaleform::MemoryHeap *v5; // rcx
  unsigned int v6; // eax

  v1 = (Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2> *)this->Data;
  v2 = this->Static;
  v3 = this;
  if ( v1 == (Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2> *)this->Static )
  {
    this->Data = v2;
    this->Size = 0i64;
  }
  else
  {
    for ( i = this->Size; i; --i )
    {
      v5 = v1->pHeap;
      if ( v1->pHeap )
      {
        if ( (unsigned __int8)v5 & 1 )
        {
          v1->pHeap = (Scaleform::MemoryHeap *)((char *)v5 - 1);
        }
        else
        {
          v6 = v5->RefCount;
          if ( v6 & 0x3FFFFF )
          {
            v5->RefCount = v6 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v5);
          }
        }
      }
      v1 = (Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2> *)((char *)v1 + 8);
    }
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v3->Data);
    v3->Data = v2;
    v3->Size = 0i64;
  }
}

// File Line: 128
// RVA: 0x80A950
void __fastcall Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2>::PushBack(Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2> *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *val)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *v2; // r15
  Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2> *v3; // rdi
  unsigned __int64 v4; // rax
  unsigned __int64 v5; // r8
  Scaleform::MemoryHeap *v6; // rcx
  __int64 v7; // rax
  unsigned __int64 v8; // rbp
  unsigned __int64 v9; // rcx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *i; // rax
  signed __int64 v11; // rsi
  Scaleform::GFx::AS3::RefCountBaseGC<328> **v12; // rbx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v13; // rcx
  unsigned int v14; // eax
  unsigned __int64 v15; // rcx
  unsigned __int64 v16; // rcx
  unsigned __int64 v17; // r8
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *v18; // rdx
  unsigned __int64 v19; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> **v20; // rbx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v21; // rcx
  unsigned int v22; // eax

  v2 = val;
  v3 = this;
  v4 = this->Size;
  if ( v4 >= 0x20 )
  {
    if ( v4 == 32 )
    {
      v5 = 2 * this->Reserved;
      this->Reserved = v5;
      v6 = this->pHeap;
      if ( v6 )
        v7 = (__int64)v6->vfptr->Alloc(v6, 8 * v5, 0i64);
      else
        v7 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2> *, unsigned __int64, _QWORD, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
               Scaleform::Memory::pGlobalHeap,
               v3,
               8 * v5,
               0i64,
               -2i64);
      v3->Data = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *)v7;
      v8 = 0i64;
      v9 = v3->Reserved;
      for ( i = v3->Data; v9; --v9 )
      {
        if ( i )
          i->pObject = 0i64;
        ++i;
      }
      if ( v3->Size )
      {
        v11 = (signed __int64)v3->Static;
        do
        {
          v12 = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)((char *)v3->Data + -24i64 - (_QWORD)v3 + v11);
          if ( (Scaleform::GFx::AS3::RefCountBaseGC<328> **)v11 != v12 )
          {
            if ( *(_QWORD *)v11 )
              *(_DWORD *)(*(_QWORD *)v11 + 32i64) = (*(_DWORD *)(*(_QWORD *)v11 + 32i64) + 1) & 0x8FBFFFFF;
            v13 = *v12;
            if ( *v12 )
            {
              if ( (unsigned __int8)v13 & 1 )
              {
                *v12 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v13 - 1);
              }
              else
              {
                v14 = v13->RefCount;
                if ( v14 & 0x3FFFFF )
                {
                  v13->RefCount = v14 - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v13);
                }
              }
            }
            *v12 = *(Scaleform::GFx::AS3::RefCountBaseGC<328> **)v11;
          }
          ++v8;
          v11 += 8i64;
        }
        while ( v8 < v3->Size );
      }
    }
    else
    {
      v15 = this->Reserved;
      if ( v4 >= v15 )
      {
        v3->Reserved = 2 * v15;
        v3->Data = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(Scaleform::Memory::pGlobalHeap, v3->Data, 16 * v15);
        v16 = v3->Size;
        v17 = v3->Reserved - v16;
        v18 = &v3->Data[v16];
        if ( v3->Reserved != v16 )
        {
          do
          {
            if ( v18 )
              v18->pObject = 0i64;
            ++v18;
            --v17;
          }
          while ( v17 );
        }
      }
    }
    v19 = v3->Size;
    v20 = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v3->Data[v19];
    v3->Size = v19 + 1;
    if ( v2 != (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *)v20 )
    {
      if ( v2->pObject )
        v2->pObject->RefCount = (v2->pObject->RefCount + 1) & 0x8FBFFFFF;
      v21 = *v20;
      if ( *v20 )
      {
        if ( (unsigned __int8)v21 & 1 )
        {
          *v20 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v21 - 1);
        }
        else
        {
          v22 = v21->RefCount;
          if ( v22 & 0x3FFFFF )
          {
            v21->RefCount = v22 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v21);
          }
        }
      }
      *v20 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v2->pObject->vfptr;
    }
  }
  else
  {
    this->Size = v4 + 1;
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object>::operator=(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)&this->Static[v4],
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)val);
  }
}

