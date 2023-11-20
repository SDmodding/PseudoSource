// File Line: 497
// RVA: 0x78C900
void __fastcall Scaleform::GFx::AS3::Abc::MethodTable::~MethodTable(Scaleform::GFx::AS3::Abc::MethodTable *this)
{
  Scaleform::GFx::AS3::Abc::MethodTable *v1; // rsi
  unsigned __int64 v2; // rbx
  void **v3; // rdi

  v1 = this;
  v2 = 0i64;
  if ( this->Info.Data.Size )
  {
    do
    {
      v3 = (void **)v1->Info.Data.Data[v2];
      if ( v3 )
      {
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v3[8]);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v3[5]);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v3[2]);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v3);
      }
      ++v2;
    }
    while ( v2 < v1->Info.Data.Size );
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->Info.Data.Data);
}

// File Line: 588
// RVA: 0x78C710
void __fastcall Scaleform::GFx::AS3::Abc::MetadataTable::~MetadataTable(Scaleform::GFx::AS3::Abc::MetadataTable *this)
{
  Scaleform::GFx::AS3::Abc::MetadataTable *v1; // rsi
  unsigned __int64 v2; // rbx
  void **v3; // rdi

  v1 = this;
  v2 = 0i64;
  if ( this->Info.Data.Size )
  {
    do
    {
      v3 = (void **)v1->Info.Data.Data[v2];
      if ( v3 )
      {
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v3[2]);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v3);
      }
      ++v2;
    }
    while ( v2 < v1->Info.Data.Size );
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->Info.Data.Data);
}

// File Line: 797
// RVA: 0x78E850
void __fastcall Scaleform::GFx::AS3::Abc::TraitTable::~TraitTable(Scaleform::GFx::AS3::Abc::TraitTable *this)
{
  Scaleform::GFx::AS3::Abc::TraitTable *v1; // rsi
  unsigned __int64 v2; // rbx
  void **v3; // rdi

  v1 = this;
  v2 = 0i64;
  if ( this->TraitInfos.Data.Size )
  {
    do
    {
      v3 = (void **)v1->TraitInfos.Data.Data[v2];
      if ( v3 )
      {
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v3[3]);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v3);
      }
      ++v2;
    }
    while ( v2 < v1->TraitInfos.Data.Size );
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->TraitInfos.Data.Data);
}

// File Line: 1071
// RVA: 0x78A040
void __fastcall Scaleform::GFx::AS3::Abc::ClassTable::~ClassTable(Scaleform::GFx::AS3::Abc::ClassTable *this)
{
  Scaleform::GFx::AS3::Abc::ClassTable *v1; // rdi
  unsigned __int64 v2; // rbx
  Scaleform::GFx::AS3::Abc::ClassInfo *v3; // rsi

  v1 = this;
  v2 = 0i64;
  if ( this->Info.Data.Size )
  {
    do
    {
      v3 = v1->Info.Data.Data[v2];
      if ( v3 )
      {
        Scaleform::GFx::AS3::Abc::ClassInfo::~ClassInfo(v1->Info.Data.Data[v2]);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v3);
      }
      ++v2;
    }
    while ( v2 < v1->Info.Data.Size );
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->Info.Data.Data);
}

// File Line: 1117
// RVA: 0x78DB30
void __fastcall Scaleform::GFx::AS3::Abc::ScriptTable::~ScriptTable(Scaleform::GFx::AS3::Abc::ScriptTable *this)
{
  Scaleform::GFx::AS3::Abc::ScriptTable *v1; // rsi
  unsigned __int64 v2; // rbx
  void **v3; // rdi

  v1 = this;
  v2 = 0i64;
  if ( this->Info.Data.Size )
  {
    do
    {
      v3 = (void **)&v1->Info.Data.Data[v2]->obj_traits.Data.Data;
      if ( v3 )
      {
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, *v3);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v3);
      }
      ++v2;
    }
    while ( v2 < v1->Info.Data.Size );
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->Info.Data.Data);
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
  Scaleform::GFx::AS3::Abc::File *v1; // rbx
  signed __int64 v2; // [rsp+58h] [rbp+10h]
  signed __int64 v3; // [rsp+58h] [rbp+10h]
  signed __int64 v4; // [rsp+58h] [rbp+10h]
  signed __int64 v5; // [rsp+58h] [rbp+10h]
  signed __int64 v6; // [rsp+58h] [rbp+10h]
  signed __int64 v7; // [rsp+58h] [rbp+10h]

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS3::Abc::File::`vftable;
  this->DataSize = 0;
  Scaleform::String::String(&this->Source);
  Scaleform::GFx::AS3::Abc::ConstPool::ConstPool(&v1->Const_Pool);
  v2 = (signed __int64)&v1->Methods;
  *(_OWORD *)v2 = 0ui64;
  *(_QWORD *)(v2 + 16) = 0i64;
  v3 = (signed __int64)&v1->Metadata;
  *(_OWORD *)v3 = 0ui64;
  *(_QWORD *)(v3 + 16) = 0i64;
  v4 = (signed __int64)&v1->Traits;
  *(_OWORD *)v4 = 0ui64;
  *(_QWORD *)(v4 + 16) = 0i64;
  v5 = (signed __int64)&v1->AS3_Classes;
  *(_OWORD *)v5 = 0ui64;
  *(_QWORD *)(v5 + 16) = 0i64;
  v6 = (signed __int64)&v1->Scripts;
  *(_OWORD *)v6 = 0ui64;
  *(_QWORD *)(v6 + 16) = 0i64;
  v7 = (signed __int64)&v1->MethodBodies;
  *(_OWORD *)v7 = 0ui64;
  *(_QWORD *)(v7 + 16) = 0i64;
}

// File Line: 1748
// RVA: 0x7F0B40
Scaleform::GFx::AS3::Abc::Multiname *__fastcall Scaleform::GFx::AS3::Abc::TraitInfo::GetTypeName(Scaleform::GFx::AS3::Abc::TraitInfo *this, Scaleform::GFx::AS3::Abc::File *f)
{
  Scaleform::GFx::AS3::Abc::Multiname *result; // rax

  if ( this->kind & 0xF && (this->kind & 0xF) != 6 )
    result = &f->Const_Pool.const_multiname.Data.Data[f->AS3_Classes.Info.Data.Data[this->Ind]->inst_info.name_ind];
  else
    result = &f->Const_Pool.const_multiname.Data.Data[this->Ind];
  return result;
}

// File Line: 1876
// RVA: 0x80C170
char __fastcall Scaleform::GFx::AS3::Abc::Reader::Read(Scaleform::GFx::AS3::Abc::Reader *this, unsigned int *v)
{
  const char *v2; // rax
  Scaleform::GFx::AS3::Abc::Reader *v3; // r10
  unsigned int *v4; // r11
  char v5; // r8
  unsigned int v6; // ecx
  int v7; // er9
  char v8; // dl
  int v9; // eax
  char result; // al

  v2 = this->CP;
  v3 = this;
  v4 = v;
  v5 = *v2;
  this->CP = v2 + 1;
  v6 = 7;
  v7 = v5 & 0x7F;
  if ( v5 >= 0 )
  {
    *v = v7;
    result = 1;
  }
  else
  {
    do
    {
      if ( v6 >= 0x20 )
        break;
      v8 = *v3->CP++;
      v9 = (v8 & 0x7F) << v6;
      v6 += 7;
      v7 |= v9;
    }
    while ( v8 < 0 );
    *v4 = v7;
    result = 1;
  }
  return result;
}

