// File Line: 86
// RVA: 0x790E00
Scaleform::String *__fastcall Scaleform::operator+(Scaleform::String *result, const char *l, Scaleform::String *r)
{
  Scaleform::String *v3; // rbx

  v3 = result;
  Scaleform::String::String(result, l, (const char *)((r->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12), 0i64);
  return v3;
}

// File Line: 93
// RVA: 0x790E50
Scaleform::String *__fastcall Scaleform::operator+(Scaleform::String *result, const char *l, Scaleform::GFx::ASString *r)
{
  const char *v3; // rdi
  Scaleform::String *v4; // rsi
  Scaleform::String *v5; // rax
  Scaleform::String *v6; // rbx
  Scaleform::String *v7; // rax
  unsigned __int64 v8; // rdx
  unsigned __int64 v9; // rdx
  Scaleform::String v11; // [rsp+60h] [rbp+18h]
  Scaleform::String v12; // [rsp+68h] [rbp+20h]

  v3 = l;
  v4 = result;
  Scaleform::String::String(&v12, r->pNode->pData, r->pNode->Size);
  v6 = v5;
  Scaleform::String::String(&v11, v3);
  Scaleform::String::operator+(v7, v4, v6);
  v8 = v11.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v11.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *, unsigned __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
      Scaleform::Memory::pGlobalHeap,
      v8);
  v9 = v12.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v12.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *, unsigned __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
      Scaleform::Memory::pGlobalHeap,
      v9);
  return v4;
}

// File Line: 99
// RVA: 0x790D80
Scaleform::String *__fastcall Scaleform::operator+(Scaleform::String *result, Scaleform::String *l, Scaleform::GFx::ASString *r)
{
  Scaleform::String *v3; // rbx
  Scaleform::String *v4; // rdi
  Scaleform::String *v5; // rax
  unsigned __int64 v6; // rdx
  Scaleform::String v8; // [rsp+50h] [rbp+18h]

  v3 = l;
  v4 = result;
  Scaleform::String::String(&v8, r->pNode->pData, r->pNode->Size);
  Scaleform::String::operator+(v3, v4, v5);
  v6 = v8.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v8.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *, unsigned __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
      Scaleform::Memory::pGlobalHeap,
      v6);
  return v4;
}

// File Line: 159
// RVA: 0x787D10
void __fastcall Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent>::~SPtr<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent>(Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::fl::uint> *this)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::fl::uint> *v1; // rdx
  Scaleform::GFx::AS3::ClassTraits::fl::uint *v2; // rcx
  unsigned int v3; // eax

  v1 = this;
  v2 = this->pObject;
  if ( v2 )
  {
    if ( (unsigned __int8)v2 & 1 )
    {
      v1->pObject = (Scaleform::GFx::AS3::ClassTraits::fl::uint *)((char *)v2 - 1);
    }
    else
    {
      v3 = v2->RefCount;
      if ( v3 & 0x3FFFFF )
      {
        v2->RefCount = v3 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v2->vfptr);
      }
    }
  }
}

// File Line: 183
// RVA: 0x790740
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *__fastcall Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object>::operator=(Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *other)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v2; // rdi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v3; // rbx
  Scaleform::GFx::AS3::Instances::fl::XML *v4; // rcx
  unsigned int v5; // eax

  v2 = other;
  v3 = this;
  if ( other != this )
  {
    if ( other->pObject )
      other->pObject->RefCount = (other->pObject->RefCount + 1) & 0x8FBFFFFF;
    v4 = this->pObject;
    if ( v3->pObject )
    {
      if ( (unsigned __int8)v4 & 1 )
      {
        v3->pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)v4 - 1);
      }
      else
      {
        v5 = v4->RefCount;
        if ( v5 & 0x3FFFFF )
        {
          v4->RefCount = v5 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v4->vfptr);
        }
      }
    }
    v3->pObject = v2->pObject;
  }
  return v3;
}

// File Line: 191
// RVA: 0x7907B0
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *__fastcall Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>::operator=(Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *this, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> v)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *v2; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLList *v3; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v4; // rbx
  unsigned int v6; // eax

  v2 = this;
  v3 = this->pObject;
  v4 = v.pV;
  if ( v.pV != v3 )
  {
    if ( v3 )
    {
      if ( (unsigned __int8)v3 & 1 )
      {
        v2->pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v3 - 1);
        v2->pObject = v.pV;
        return v2;
      }
      v6 = v3->RefCount;
      if ( v6 & 0x3FFFFF )
      {
        v3->RefCount = v6 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v3->vfptr);
      }
    }
    v2->pObject = v4;
  }
  return v2;
}

// File Line: 240
// RVA: 0x81D320
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *__fastcall Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *this, Scaleform::GFx::AS3::Instances::fl::XMLList *p)
{
  Scaleform::GFx::AS3::Instances::fl::XMLList *v2; // rdi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *v3; // rbx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v4; // rcx
  unsigned int v6; // eax

  v2 = p;
  v3 = this;
  if ( p != this->pObject )
  {
    if ( p )
      p->RefCount = (p->RefCount + 1) & 0x8FBFFFFF;
    v4 = this->pObject;
    if ( v4 )
    {
      if ( (unsigned __int8)v4 & 1 )
      {
        v3->pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v4 - 1);
        v3->pObject = p;
        return v3;
      }
      v6 = v4->RefCount;
      if ( v6 & 0x3FFFFF )
      {
        v4->RefCount = v6 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v4->vfptr);
      }
    }
    v3->pObject = v2;
  }
  return v3;
}

