// File Line: 505
// RVA: 0x7B4680
void __fastcall Scaleform::GFx::AS3::Abc::ConstPool::Clear(Scaleform::GFx::AS3::Abc::ConstPool *this)
{
  if ( this->ConstInt.Data.Size && (this->ConstInt.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    if ( this->ConstInt.Data.Data )
    {
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      this->ConstInt.Data.Data = 0i64;
    }
    this->ConstInt.Data.Policy.Capacity = 0i64;
  }
  this->ConstInt.Data.Size = 0i64;
  if ( this->ConstUInt.Data.Size && (this->ConstUInt.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    if ( this->ConstUInt.Data.Data )
    {
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      this->ConstUInt.Data.Data = 0i64;
    }
    this->ConstUInt.Data.Policy.Capacity = 0i64;
  }
  this->ConstUInt.Data.Size = 0i64;
  Scaleform::ArrayData<Scaleform::GFx::AS3::Abc::StringView,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::StringView,339>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->ConstStr.Data,
    0i64);
  Scaleform::ArrayData<Scaleform::GFx::AS3::Abc::NamespaceInfo,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::NamespaceInfo,339>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->ConstNamespace.Data,
    0i64);
  if ( this->const_ns_set.Data.Size && (this->const_ns_set.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    if ( this->const_ns_set.Data.Data )
    {
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      this->const_ns_set.Data.Data = 0i64;
    }
    this->const_ns_set.Data.Policy.Capacity = 0i64;
  }
  this->const_ns_set.Data.Size = 0i64;
  if ( this->const_multiname.Data.Size && (this->const_multiname.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    if ( this->const_multiname.Data.Data )
    {
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      this->const_multiname.Data.Data = 0i64;
    }
    this->const_multiname.Data.Policy.Capacity = 0i64;
  }
  this->const_multiname.Data.Size = 0i64;
}

