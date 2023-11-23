// File Line: 58
// RVA: 0x76E520
__int64 __fastcall Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(const char *data, unsigned __int64 *cp)
{
  char v3; // r8
  unsigned int v4; // r9d
  __int64 result; // rax
  char v6; // r8
  char v7; // cl

  v3 = data[*cp];
  v4 = 7;
  ++*cp;
  result = v3 & 0x7F;
  if ( v3 < 0 )
  {
    do
    {
      if ( v4 >= 0x20 )
        break;
      v6 = data[(*cp)++];
      v7 = v4;
      v4 += 7;
      result = ((v6 & 0x7F) << v7) | (unsigned int)result;
    }
    while ( v6 < 0 );
  }
  return result;
}

// File Line: 211
// RVA: 0x7F9650
bool __fastcall Scaleform::GFx::AS3::Abc::IsValidValueKind(char vk)
{
  bool result; // al

  switch ( vk )
  {
    case 0:
    case 1:
    case 3:
    case 4:
    case 5:
    case 6:
    case 8:
    case 10:
    case 11:
    case 12:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

// File Line: 641
// RVA: 0x7B4790
void __fastcall Scaleform::GFx::AS3::Abc::File::Clear(Scaleform::GFx::AS3::Abc::File *this)
{
  Scaleform::GFx::AS3::Abc::ConstPool *p_Const_Pool; // rcx

  p_Const_Pool = &this->Const_Pool;
  LODWORD(p_Const_Pool[-1].any_namespace.NameURI.Size) = 0;
  Scaleform::GFx::AS3::Abc::ConstPool::Clear(p_Const_Pool);
  if ( this->Methods.Info.Data.Size && (this->Methods.Info.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    if ( this->Methods.Info.Data.Data )
    {
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      this->Methods.Info.Data.Data = 0i64;
    }
    this->Methods.Info.Data.Policy.Capacity = 0i64;
  }
  this->Methods.Info.Data.Size = 0i64;
  if ( this->Metadata.Info.Data.Size && (this->Metadata.Info.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    if ( this->Metadata.Info.Data.Data )
    {
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      this->Metadata.Info.Data.Data = 0i64;
    }
    this->Metadata.Info.Data.Policy.Capacity = 0i64;
  }
  this->Metadata.Info.Data.Size = 0i64;
  if ( this->Traits.TraitInfos.Data.Size && (this->Traits.TraitInfos.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    if ( this->Traits.TraitInfos.Data.Data )
    {
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      this->Traits.TraitInfos.Data.Data = 0i64;
    }
    this->Traits.TraitInfos.Data.Policy.Capacity = 0i64;
  }
  this->Traits.TraitInfos.Data.Size = 0i64;
  if ( this->AS3_Classes.Info.Data.Size && (this->AS3_Classes.Info.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    if ( this->AS3_Classes.Info.Data.Data )
    {
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      this->AS3_Classes.Info.Data.Data = 0i64;
    }
    this->AS3_Classes.Info.Data.Policy.Capacity = 0i64;
  }
  this->AS3_Classes.Info.Data.Size = 0i64;
  if ( this->Scripts.Info.Data.Size && (this->Scripts.Info.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    if ( this->Scripts.Info.Data.Data )
    {
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      this->Scripts.Info.Data.Data = 0i64;
    }
    this->Scripts.Info.Data.Policy.Capacity = 0i64;
  }
  this->Scripts.Info.Data.Size = 0i64;
  if ( this->MethodBodies.Info.Data.Size && (this->MethodBodies.Info.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    if ( this->MethodBodies.Info.Data.Data )
    {
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      this->MethodBodies.Info.Data.Data = 0i64;
    }
    this->MethodBodies.Info.Data.Policy.Capacity = 0i64;
  }
  this->MethodBodies.Info.Data.Size = 0i64;
}

// File Line: 655
// RVA: 0x78A970
void __fastcall Scaleform::GFx::AS3::Abc::File::~File(Scaleform::GFx::AS3::Abc::File *this)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS3::Abc::File::`vftable;
  Scaleform::GFx::AS3::Abc::MethodBodyTable::~MethodBodyTable(&this->MethodBodies);
  Scaleform::GFx::AS3::Abc::ScriptTable::~ScriptTable(&this->Scripts);
  Scaleform::GFx::AS3::Abc::ClassTable::~ClassTable(&this->AS3_Classes);
  Scaleform::GFx::AS3::Abc::TraitTable::~TraitTable(&this->Traits);
  Scaleform::GFx::AS3::Abc::MetadataTable::~MetadataTable(&this->Metadata);
  Scaleform::GFx::AS3::Abc::MethodTable::~MethodTable(&this->Methods);
  Scaleform::GFx::AS3::Abc::ConstPool::~ConstPool(&this->Const_Pool);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((this->Source.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}

// File Line: 660
// RVA: 0x78C7C0
void __fastcall Scaleform::GFx::AS3::Abc::MethodBodyTable::~MethodBodyTable(
        Scaleform::GFx::AS3::Abc::MethodBodyTable *this)
{
  unsigned __int64 Size; // rbp
  unsigned __int64 i; // rbx
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v4; // rdi

  Size = this->Info.Data.Size;
  for ( i = 0i64; i < Size; ++i )
  {
    v4 = this->Info.Data.Data[i];
    if ( v4 )
    {
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v4->exception.info.Data.Data);
      v4->code.vfptr = (Scaleform::GFx::AS3::Abc::CodeVtbl *)&Scaleform::GFx::AS3::Abc::Code::`vftable;
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v4->obj_traits.Data.Data);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v4);
    }
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->Info.Data.Data);
}

