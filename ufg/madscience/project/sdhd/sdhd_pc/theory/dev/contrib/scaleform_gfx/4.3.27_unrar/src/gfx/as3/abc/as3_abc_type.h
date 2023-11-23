// File Line: 86
// RVA: 0x790E00
Scaleform::String *__fastcall Scaleform::operator+(Scaleform::String *result, const char *l, Scaleform::String *r)
{
  Scaleform::String::String(result, l, (const char *)((r->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12), 0i64);
  return result;
}

// File Line: 93
// RVA: 0x790E50
Scaleform::String *__fastcall Scaleform::operator+(
        Scaleform::String *result,
        const char *l,
        Scaleform::GFx::ASString *r)
{
  Scaleform::String *v5; // rax
  Scaleform::String *v6; // rbx
  Scaleform::String *v7; // rax
  Scaleform::String v9; // [rsp+60h] [rbp+18h] BYREF
  Scaleform::String v10; // [rsp+68h] [rbp+20h] BYREF

  Scaleform::String::String(&v10, r->pNode->pData, r->pNode->Size);
  v6 = v5;
  Scaleform::String::String(&v9, l);
  Scaleform::String::operator+(v7, result, v6);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v9.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v10.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  return result;
}

// File Line: 99
// RVA: 0x790D80
Scaleform::String *__fastcall Scaleform::operator+(
        Scaleform::String *result,
        Scaleform::String *l,
        Scaleform::GFx::ASString *r)
{
  Scaleform::String *v5; // rax
  Scaleform::String v7; // [rsp+50h] [rbp+18h] BYREF

  Scaleform::String::String(&v7, r->pNode->pData, r->pNode->Size);
  Scaleform::String::operator+(l, result, v5);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v7.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  return result;
}

// File Line: 159
// RVA: 0x787D10
void __fastcall Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent>::~SPtr<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent>(
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::fl::uint> *this)
{
  Scaleform::GFx::AS3::ClassTraits::fl::uint *pObject; // rcx
  unsigned int RefCount; // eax

  pObject = this->pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->pObject = (Scaleform::GFx::AS3::ClassTraits::fl::uint *)((char *)pObject - 1);
    }
    else
    {
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
}

// File Line: 183
// RVA: 0x790740
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *__fastcall Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object>::operator=(
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *other)
{
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // rcx
  unsigned int RefCount; // eax

  if ( other != this )
  {
    if ( other->pObject )
      other->pObject->RefCount = (other->pObject->RefCount + 1) & 0x8FBFFFFF;
    pObject = this->pObject;
    if ( this->pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        this->pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)pObject - 1);
      }
      else
      {
        RefCount = pObject->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
    }
    this->pObject = other->pObject;
  }
  return this;
}

// File Line: 191
// RVA: 0x7907B0
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *__fastcall Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>::operator=(
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> v)
{
  Scaleform::GFx::AS3::Instances::fl::XMLList *pObject; // rcx
  unsigned int RefCount; // eax

  pObject = this->pObject;
  if ( v.pV != pObject )
  {
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        this->pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)pObject - 1);
        this->pObject = v.pV;
        return this;
      }
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
    this->pObject = v.pV;
  }
  return this;
}

// File Line: 240
// RVA: 0x81D320
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *__fastcall Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *this,
        Scaleform::GFx::AS3::Instances::fl::XMLList *p)
{
  Scaleform::GFx::AS3::Instances::fl::XMLList *pObject; // rcx
  unsigned int RefCount; // eax

  if ( p != this->pObject )
  {
    if ( p )
      p->RefCount = (p->RefCount + 1) & 0x8FBFFFFF;
    pObject = this->pObject;
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        this->pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)pObject - 1);
        this->pObject = p;
        return this;
      }
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
    this->pObject = p;
  }
  return this;
}

