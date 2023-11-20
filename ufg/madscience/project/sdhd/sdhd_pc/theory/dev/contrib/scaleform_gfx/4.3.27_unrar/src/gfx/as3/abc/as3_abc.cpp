// File Line: 58
// RVA: 0x76E520
__int64 __fastcall Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(const char *data, unsigned __int64 *cp)
{
  const char *v2; // r11
  char v3; // r8
  unsigned int v4; // er9
  __int64 result; // rax
  char v6; // r8
  char v7; // cl

  v2 = data;
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
      v6 = v2[(*cp)++];
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
char __fastcall Scaleform::GFx::AS3::Abc::IsValidValueKind(char vk)
{
  char result; // al

  switch ( vk )
  {
    case 0:
    case 1:
    case 3:
    case 4:
    case 5:
    case 6:
    case 8:
    case 0xA:
    case 0xB:
    case 0xC:
    case 0x16:
    case 0x17:
    case 0x18:
    case 0x19:
    case 0x1A:
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
  Scaleform::GFx::AS3::Abc::File *v1; // rbx
  Scaleform::GFx::AS3::Abc::ConstPool *v2; // rcx

  v1 = this;
  v2 = &this->Const_Pool;
  LODWORD(v2[-1].any_namespace.NameURI.Size) = 0;
  Scaleform::GFx::AS3::Abc::ConstPool::Clear(v2);
  if ( v1->Methods.Info.Data.Size > 0 && v1->Methods.Info.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64 )
  {
    if ( v1->Methods.Info.Data.Data )
    {
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v1->Methods.Info.Data.Data = 0i64;
    }
    v1->Methods.Info.Data.Policy.Capacity = 0i64;
  }
  v1->Methods.Info.Data.Size = 0i64;
  if ( v1->Metadata.Info.Data.Size > 0 && v1->Metadata.Info.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64 )
  {
    if ( v1->Metadata.Info.Data.Data )
    {
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v1->Metadata.Info.Data.Data = 0i64;
    }
    v1->Metadata.Info.Data.Policy.Capacity = 0i64;
  }
  v1->Metadata.Info.Data.Size = 0i64;
  if ( v1->Traits.TraitInfos.Data.Size > 0 && v1->Traits.TraitInfos.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64 )
  {
    if ( v1->Traits.TraitInfos.Data.Data )
    {
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v1->Traits.TraitInfos.Data.Data = 0i64;
    }
    v1->Traits.TraitInfos.Data.Policy.Capacity = 0i64;
  }
  v1->Traits.TraitInfos.Data.Size = 0i64;
  if ( v1->AS3_Classes.Info.Data.Size > 0 && v1->AS3_Classes.Info.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64 )
  {
    if ( v1->AS3_Classes.Info.Data.Data )
    {
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v1->AS3_Classes.Info.Data.Data = 0i64;
    }
    v1->AS3_Classes.Info.Data.Policy.Capacity = 0i64;
  }
  v1->AS3_Classes.Info.Data.Size = 0i64;
  if ( v1->Scripts.Info.Data.Size > 0 && v1->Scripts.Info.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64 )
  {
    if ( v1->Scripts.Info.Data.Data )
    {
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v1->Scripts.Info.Data.Data = 0i64;
    }
    v1->Scripts.Info.Data.Policy.Capacity = 0i64;
  }
  v1->Scripts.Info.Data.Size = 0i64;
  if ( v1->MethodBodies.Info.Data.Size > 0 && v1->MethodBodies.Info.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64 )
  {
    if ( v1->MethodBodies.Info.Data.Data )
    {
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v1->MethodBodies.Info.Data.Data = 0i64;
    }
    v1->MethodBodies.Info.Data.Policy.Capacity = 0i64;
  }
  v1->MethodBodies.Info.Data.Size = 0i64;
}

// File Line: 655
// RVA: 0x78A970
void __fastcall Scaleform::GFx::AS3::Abc::File::~File(Scaleform::GFx::AS3::Abc::File *this)
{
  Scaleform::GFx::AS3::Abc::File *v1; // rbx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS3::Abc::File::`vftable;
  Scaleform::GFx::AS3::Abc::MethodBodyTable::~MethodBodyTable(&this->MethodBodies);
  Scaleform::GFx::AS3::Abc::ScriptTable::~ScriptTable(&v1->Scripts);
  Scaleform::GFx::AS3::Abc::ClassTable::~ClassTable(&v1->AS3_Classes);
  Scaleform::GFx::AS3::Abc::TraitTable::~TraitTable(&v1->Traits);
  Scaleform::GFx::AS3::Abc::MetadataTable::~MetadataTable(&v1->Metadata);
  Scaleform::GFx::AS3::Abc::MethodTable::~MethodTable(&v1->Methods);
  Scaleform::GFx::AS3::Abc::ConstPool::~ConstPool(&v1->Const_Pool);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v1->Source.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)&v1->vfptr);
}

// File Line: 660
// RVA: 0x78C7C0
void __fastcall Scaleform::GFx::AS3::Abc::MethodBodyTable::~MethodBodyTable(Scaleform::GFx::AS3::Abc::MethodBodyTable *this)
{
  Scaleform::GFx::AS3::Abc::MethodBodyTable *v1; // rsi
  unsigned __int64 v2; // rbp
  unsigned __int64 v3; // rbx
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v4; // rdi

  v1 = this;
  v2 = this->Info.Data.Size;
  v3 = 0i64;
  if ( v2 )
  {
    do
    {
      v4 = v1->Info.Data.Data[v3];
      if ( v4 )
      {
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v4->exception.info.Data.Data);
        v4->code.vfptr = (Scaleform::GFx::AS3::Abc::CodeVtbl *)&Scaleform::GFx::AS3::Abc::Code::`vftable;
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v4->obj_traits.Data.Data);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v4);
      }
      ++v3;
    }
    while ( v3 < v2 );
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->Info.Data.Data);
}

