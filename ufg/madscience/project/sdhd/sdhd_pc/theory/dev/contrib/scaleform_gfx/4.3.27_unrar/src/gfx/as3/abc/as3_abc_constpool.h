// File Line: 505
// RVA: 0x7B4680
void __fastcall Scaleform::GFx::AS3::Abc::ConstPool::Clear(Scaleform::GFx::AS3::Abc::ConstPool *this)
{
  Scaleform::GFx::AS3::Abc::ConstPool *v1; // rbx

  v1 = this;
  if ( this->ConstInt.Data.Size && this->ConstInt.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64 )
  {
    if ( this->ConstInt.Data.Data )
    {
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v1->ConstInt.Data.Data = 0i64;
    }
    v1->ConstInt.Data.Policy.Capacity = 0i64;
  }
  v1->ConstInt.Data.Size = 0i64;
  if ( v1->ConstUInt.Data.Size > 0 && v1->ConstUInt.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64 )
  {
    if ( v1->ConstUInt.Data.Data )
    {
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v1->ConstUInt.Data.Data = 0i64;
    }
    v1->ConstUInt.Data.Policy.Capacity = 0i64;
  }
  v1->ConstUInt.Data.Size = 0i64;
  Scaleform::ArrayData<Scaleform::GFx::AS3::Abc::StringView,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::StringView,339>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v1->ConstStr.Data,
    0i64);
  Scaleform::ArrayData<Scaleform::GFx::AS3::Abc::NamespaceInfo,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::NamespaceInfo,339>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v1->ConstNamespace.Data,
    0i64);
  if ( v1->const_ns_set.Data.Size > 0 && v1->const_ns_set.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64 )
  {
    if ( v1->const_ns_set.Data.Data )
    {
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v1->const_ns_set.Data.Data = 0i64;
    }
    v1->const_ns_set.Data.Policy.Capacity = 0i64;
  }
  v1->const_ns_set.Data.Size = 0i64;
  if ( v1->const_multiname.Data.Size > 0 && v1->const_multiname.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64 )
  {
    if ( v1->const_multiname.Data.Data )
    {
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v1->const_multiname.Data.Data = 0i64;
    }
    v1->const_multiname.Data.Policy.Capacity = 0i64;
  }
  v1->const_multiname.Data.Size = 0i64;
}

