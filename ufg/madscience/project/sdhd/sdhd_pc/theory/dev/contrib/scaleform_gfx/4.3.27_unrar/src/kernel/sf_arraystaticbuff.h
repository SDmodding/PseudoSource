// File Line: 36
// RVA: 0x8A1250
void __fastcall Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Image *,32,2>::~ArrayStaticBuffPOD<Scaleform::Render::Image *,32,2>(
        Scaleform::ArrayStaticBuffPOD<Scaleform::RefCountImpl *,32,2> *this)
{
  Scaleform::RefCountImpl **Static; // rdi

  Static = this->Static;
  if ( this->Data == this->Static )
  {
    this->Data = Static;
    this->Size = 0i64;
  }
  else
  {
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    this->Data = Static;
    this->Size = 0i64;
  }
}

// File Line: 49
// RVA: 0x9A2720
void __fastcall Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Font *,32,2>::PushBack(
        Scaleform::ArrayStaticBuffPOD<Scaleform::RefCountImpl *,32,2> *this,
        Scaleform::RefCountImpl **val)
{
  unsigned __int64 Size; // rcx
  Scaleform::MemoryHeap *pHeap; // rcx
  unsigned __int64 v6; // r8
  Scaleform::RefCountImpl **v7; // rax
  Scaleform::RefCountImpl **v8; // rcx
  Scaleform::RefCountImpl **Static; // rdx
  __int64 v10; // rax
  __int128 v11; // xmm0
  unsigned __int64 Reserved; // rax
  Scaleform::RefCountImpl **Data; // rdx
  unsigned __int64 v14; // rax

  Size = this->Size;
  if ( Size >= 0x20 )
  {
    if ( Size == 32 )
    {
      pHeap = this->pHeap;
      v6 = 2 * this->Reserved;
      this->Reserved = v6;
      if ( pHeap )
        v7 = (Scaleform::RefCountImpl **)pHeap->vfptr->Alloc(pHeap, 8 * v6, 0i64);
      else
        v7 = (Scaleform::RefCountImpl **)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                           Scaleform::Memory::pGlobalHeap,
                                           this,
                                           8 * v6,
                                           0i64);
      v8 = v7;
      this->Data = v7;
      Static = this->Static;
      if ( (((unsigned __int8)v7 | (unsigned __int8)((_BYTE)this + 24)) & 0xF) != 0 )
      {
        memmove(v7, Static, 0x100ui64);
      }
      else
      {
        v10 = 2i64;
        do
        {
          v11 = *(_OWORD *)Static;
          v8 += 16;
          Static += 16;
          *((_OWORD *)v8 - 8) = v11;
          *((_OWORD *)v8 - 7) = *((_OWORD *)Static - 7);
          *((_OWORD *)v8 - 6) = *((_OWORD *)Static - 6);
          *((_OWORD *)v8 - 5) = *((_OWORD *)Static - 5);
          *((_OWORD *)v8 - 4) = *((_OWORD *)Static - 4);
          *((_OWORD *)v8 - 3) = *((_OWORD *)Static - 3);
          *((_OWORD *)v8 - 2) = *((_OWORD *)Static - 2);
          *((_OWORD *)v8 - 1) = *((_OWORD *)Static - 1);
          --v10;
        }
        while ( v10 );
      }
    }
    else
    {
      Reserved = this->Reserved;
      if ( Size >= Reserved )
      {
        Data = this->Data;
        v14 = 2 * Reserved;
        this->Reserved = v14;
        this->Data = (Scaleform::RefCountImpl **)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   Data,
                                                   8 * v14);
      }
    }
    this->Data[this->Size++] = *val;
  }
  else
  {
    this->Static[Size] = *val;
    ++this->Size;
  }
}

// File Line: 112
// RVA: 0x7865C0
void __fastcall Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2>::~ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2>(
        Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2> *this)
{
  Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2>::Clear(this);
  `eh vector destructor iterator(
    this->Static,
    8ui64,
    32,
    (void (__fastcall *)(void *))Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent>::~SPtr<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent>);
}

// File Line: 117
// RVA: 0x7B3D40
void __fastcall Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2>::Clear(
        Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2> *this)
{
  Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2> *Data; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *Static; // rbp
  unsigned __int64 i; // rdi
  Scaleform::MemoryHeap *pHeap; // rcx
  unsigned int RefCount; // eax

  Data = (Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2> *)this->Data;
  Static = this->Static;
  if ( Data == (Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2> *)this->Static )
  {
    this->Data = Static;
    this->Size = 0i64;
  }
  else
  {
    for ( i = this->Size; i; --i )
    {
      pHeap = Data->pHeap;
      if ( Data->pHeap )
      {
        if ( ((unsigned __int8)pHeap & 1) != 0 )
        {
          Data->pHeap = (Scaleform::MemoryHeap *)((char *)pHeap - 1);
        }
        else
        {
          RefCount = pHeap->RefCount;
          if ( (RefCount & 0x3FFFFF) != 0 )
          {
            pHeap->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)pHeap);
          }
        }
      }
      Data = (Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2> *)((char *)Data + 8);
    }
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->Data);
    this->Data = Static;
    this->Size = 0i64;
  }
}

// File Line: 128
// RVA: 0x80A950
void __fastcall Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2>::PushBack(
        Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2> *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *val)
{
  unsigned __int64 Size; // rax
  unsigned __int64 v5; // r8
  Scaleform::MemoryHeap *pHeap; // rcx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *v7; // rax
  unsigned __int64 v8; // rbp
  unsigned __int64 Reserved; // rcx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *i; // rax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *Static; // rsi
  Scaleform::GFx::AS3::RefCountBaseGC<328> **v12; // rbx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v13; // rcx
  unsigned int RefCount; // eax
  unsigned __int64 v15; // rcx
  unsigned __int64 v16; // rcx
  unsigned __int64 v17; // r8
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *j; // rdx
  unsigned __int64 v19; // rcx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *v20; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> v21; // rcx
  unsigned int v22; // eax

  Size = this->Size;
  if ( Size >= 0x20 )
  {
    if ( Size == 32 )
    {
      v5 = 2 * this->Reserved;
      this->Reserved = v5;
      pHeap = this->pHeap;
      if ( pHeap )
        v7 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *)pHeap->vfptr->Alloc(pHeap, 8 * v5, 0i64);
      else
        v7 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::ArrayStaticBuff<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject>,32,2> *, unsigned __int64, _QWORD, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(Scaleform::Memory::pGlobalHeap, this, 8 * v5, 0i64, -2i64);
      this->Data = v7;
      v8 = 0i64;
      Reserved = this->Reserved;
      for ( i = this->Data; Reserved; --Reserved )
      {
        if ( i )
          i->pObject = 0i64;
        ++i;
      }
      if ( this->Size )
      {
        Static = this->Static;
        do
        {
          v12 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject **)((char *)&this->Data->pObject
                                                                             + (unsigned __int64)Static
                                                                             - 24
                                                                             - (_QWORD)this);
          if ( Static != (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *)v12 )
          {
            if ( Static->pObject )
              Static->pObject->RefCount = (Static->pObject->RefCount + 1) & 0x8FBFFFFF;
            v13 = *v12;
            if ( *v12 )
            {
              if ( ((unsigned __int8)v13 & 1) != 0 )
              {
                *v12 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v13 - 1);
              }
              else
              {
                RefCount = v13->RefCount;
                if ( (RefCount & 0x3FFFFF) != 0 )
                {
                  v13->RefCount = RefCount - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v13);
                }
              }
            }
            *v12 = Static->pObject;
          }
          ++v8;
          ++Static;
        }
        while ( v8 < this->Size );
      }
    }
    else
    {
      v15 = this->Reserved;
      if ( Size >= v15 )
      {
        this->Reserved = 2 * v15;
        this->Data = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(Scaleform::Memory::pGlobalHeap, this->Data, 16 * v15);
        v16 = this->Size;
        v17 = this->Reserved - v16;
        for ( j = &this->Data[v16]; v17; --v17 )
        {
          if ( j )
            j->pObject = 0i64;
          ++j;
        }
      }
    }
    v19 = this->Size;
    v20 = &this->Data[v19];
    this->Size = v19 + 1;
    if ( val != (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)v20 )
    {
      if ( val->pObject )
        val->pObject->RefCount = (val->pObject->RefCount + 1) & 0x8FBFFFFF;
      v21.pObject = v20->pObject;
      if ( v20->pObject )
      {
        if ( ((__int64)v21.pObject & 1) != 0 )
        {
          v20->pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v21.pObject - 1);
        }
        else
        {
          v22 = v21.pObject->RefCount;
          if ( (v22 & 0x3FFFFF) != 0 )
          {
            v21.pObject->RefCount = v22 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v21.pObject);
          }
        }
      }
      v20->pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)val->pObject;
    }
  }
  else
  {
    this->Size = Size + 1;
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object>::operator=(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)&this->Static[Size],
      val);
  }
}

