// File Line: 497
// RVA: 0x78C900
void __fastcall Scaleform::GFx::AS3::Abc::MethodTable::~MethodTable(Scaleform::GFx::AS3::Abc::MethodTable *this)
{
  unsigned __int64 i; // rbx
  Scaleform::GFx::AS3::Abc::MethodInfo *v3; // rdi

  for ( i = 0i64; i < this->Info.Data.Size; ++i )
  {
    v3 = this->Info.Data.Data[i];
    if ( v3 )
    {
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v3->ParamNames.Data.Data);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v3->OptionalParams.Data.Data);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v3->ParamTypes.Data.Data);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v3);
    }
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->Info.Data.Data);
}

// File Line: 588
// RVA: 0x78C710
void __fastcall Scaleform::GFx::AS3::Abc::MetadataTable::~MetadataTable(Scaleform::GFx::AS3::Abc::MetadataTable *this)
{
  unsigned __int64 i; // rbx
  Scaleform::GFx::AS3::Abc::MetadataInfo *v3; // rdi

  for ( i = 0i64; i < this->Info.Data.Size; ++i )
  {
    v3 = this->Info.Data.Data[i];
    if ( v3 )
    {
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v3->Items.Data.Data);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v3);
    }
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->Info.Data.Data);
}

// File Line: 797
// RVA: 0x78E850
void __fastcall Scaleform::GFx::AS3::Abc::TraitTable::~TraitTable(Scaleform::GFx::AS3::Abc::TraitTable *this)
{
  unsigned __int64 i; // rbx
  Scaleform::GFx::AS3::Abc::TraitInfo *v3; // rdi

  for ( i = 0i64; i < this->TraitInfos.Data.Size; ++i )
  {
    v3 = this->TraitInfos.Data.Data[i];
    if ( v3 )
    {
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v3->meta_info.info.Data.Data);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v3);
    }
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->TraitInfos.Data.Data);
}

// File Line: 1071
// RVA: 0x78A040
void __fastcall Scaleform::GFx::AS3::Abc::ClassTable::~ClassTable(Scaleform::GFx::AS3::Abc::ClassTable *this)
{
  unsigned __int64 i; // rbx
  Scaleform::GFx::AS3::Abc::ClassInfo *v3; // rsi

  for ( i = 0i64; i < this->Info.Data.Size; ++i )
  {
    v3 = this->Info.Data.Data[i];
    if ( v3 )
    {
      Scaleform::GFx::AS3::Abc::ClassInfo::~ClassInfo(this->Info.Data.Data[i]);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v3);
    }
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->Info.Data.Data);
}

// File Line: 1117
// RVA: 0x78DB30
void __fastcall Scaleform::GFx::AS3::Abc::ScriptTable::~ScriptTable(Scaleform::GFx::AS3::Abc::ScriptTable *this)
{
  unsigned __int64 i; // rbx
  Scaleform::GFx::AS3::Abc::ScriptInfo *v3; // rdi

  for ( i = 0i64; i < this->Info.Data.Size; ++i )
  {
    v3 = this->Info.Data.Data[i];
    if ( v3 )
    {
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v3->obj_traits.Data.Data);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v3);
    }
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->Info.Data.Data);
}

// File Line: 1158
// RVA: 0x78A0D0
void __fastcall Scaleform::GFx::AS3::Abc::Code::~Code(Scaleform::GFx::AS3::Abc::Code *this)
{
  this->vfptr = (Scaleform::GFx::AS3::Abc::CodeVtbl *)&Scaleform::GFx::AS3::Abc::Code::`vftable;
}

// File Line: 1634
// RVA: 0x77CF50
void __fastcall Scaleform::GFx::AS3::Abc::File::File(Scaleform::GFx::AS3::Abc::File *this)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS3::Abc::File::`vftable;
  this->DataSize = 0;
  Scaleform::String::String(&this->Source);
  Scaleform::GFx::AS3::Abc::ConstPool::ConstPool(&this->Const_Pool);
  this->Methods.Info.Data.Data = 0i64;
  this->Methods.Info.Data.Size = 0i64;
  this->Methods.Info.Data.Policy.Capacity = 0i64;
  this->Metadata.Info.Data.Data = 0i64;
  this->Metadata.Info.Data.Size = 0i64;
  this->Metadata.Info.Data.Policy.Capacity = 0i64;
  this->Traits.TraitInfos.Data.Data = 0i64;
  this->Traits.TraitInfos.Data.Size = 0i64;
  this->Traits.TraitInfos.Data.Policy.Capacity = 0i64;
  this->AS3_Classes.Info.Data.Data = 0i64;
  this->AS3_Classes.Info.Data.Size = 0i64;
  this->AS3_Classes.Info.Data.Policy.Capacity = 0i64;
  this->Scripts.Info.Data.Data = 0i64;
  this->Scripts.Info.Data.Size = 0i64;
  this->Scripts.Info.Data.Policy.Capacity = 0i64;
  this->MethodBodies.Info.Data.Data = 0i64;
  this->MethodBodies.Info.Data.Size = 0i64;
  this->MethodBodies.Info.Data.Policy.Capacity = 0i64;
}

// File Line: 1748
// RVA: 0x7F0B40
Scaleform::GFx::AS3::Abc::Multiname *__fastcall Scaleform::GFx::AS3::Abc::TraitInfo::GetTypeName(
        Scaleform::GFx::AS3::Abc::TraitInfo *this,
        Scaleform::GFx::AS3::Abc::File *f)
{
  if ( (this->kind & 0xF) == 0 || (this->kind & 0xF) == 6 )
    return &f->Const_Pool.const_multiname.Data.Data[this->Ind];
  else
    return &f->Const_Pool.const_multiname.Data.Data[f->AS3_Classes.Info.Data.Data[this->Ind]->inst_info.name_ind];
}

// File Line: 1876
// RVA: 0x80C170
char __fastcall Scaleform::GFx::AS3::Abc::Reader::Read(Scaleform::GFx::AS3::Abc::Reader *this, unsigned int *v)
{
  const char *CP; // rax
  char v5; // r8
  unsigned int v6; // ecx
  int v7; // r9d
  char v8; // dl
  int v9; // eax

  CP = this->CP;
  v5 = *CP;
  this->CP = CP + 1;
  v6 = 7;
  v7 = v5 & 0x7F;
  if ( v5 >= 0 )
  {
    *v = v7;
    return 1;
  }
  else
  {
    do
    {
      if ( v6 >= 0x20 )
        break;
      v8 = *this->CP++;
      v9 = (v8 & 0x7F) << v6;
      v6 += 7;
      v7 |= v9;
    }
    while ( v8 < 0 );
    *v = v7;
    return 1;
  }
}

