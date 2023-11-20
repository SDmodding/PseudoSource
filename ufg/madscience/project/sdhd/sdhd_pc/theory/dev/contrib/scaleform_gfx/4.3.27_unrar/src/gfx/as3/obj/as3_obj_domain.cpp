// File Line: 37
// RVA: 0x1590370
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl::Domain_0_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Instances::fl_utils::ByteArray_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B3A0 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Domain,0,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *>::Method = Scaleform::GFx::AS3::Instances::fl::Domain::loadBytes;
  return result;
}

// File Line: 38
// RVA: 0x15895C0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl::Domain_1_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl::Domain___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B3B0 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Domain,1,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Domain>>::Method = Scaleform::GFx::AS3::Instances::fl::Domain::parentDomainGet;
  return result;
}

// File Line: 39
// RVA: 0x1590310
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl::Domain_2_Scaleform::GFx::AS3::Value_Scaleform::GFx::ASString_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B3C0 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Domain,2,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASString const &>::Method = Scaleform::GFx::AS3::Instances::fl::Domain::getClass;
  return result;
}

// File Line: 40
// RVA: 0x1590340
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl::Domain_3_bool_Scaleform::GFx::ASString_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B3D0 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Domain,3,bool,Scaleform::GFx::ASString const &>::Method = Scaleform::GFx::AS3::Instances::fl::Domain::load;
  return result;
}

// File Line: 49
// RVA: 0x77C7D0
void __fastcall Scaleform::GFx::AS3::Instances::fl::Domain::Domain(Scaleform::GFx::AS3::Instances::fl::Domain *this, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Instances::fl::Domain *v2; // rbx
  Scaleform::GFx::AS3::VM *v3; // r8
  Scaleform::GFx::AS3::VMAppDomain *v4; // rdx
  signed __int64 v5; // [rsp+50h] [rbp+18h]

  v2 = this;
  Scaleform::GFx::AS3::Instance::Instance((Scaleform::GFx::AS3::Instance *)&this->vfptr, t);
  v2->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable';
  v2->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Domain::`vftable';
  v3 = v2->pTraits.pObject->pVM;
  if ( v3->CallStack.Size && Scaleform::GFx::AS3::VMAppDomain::Enabled )
    v4 = v3->CallStack.Pages[(v3->CallStack.Size - 1) >> 6][(LODWORD(v3->CallStack.Size) - 1) & 0x3F].pFile->AppDomain.pObject;
  else
    v4 = v3->CurrentDomain.pObject;
  v2->VMDomain.pObject = v4;
  if ( v4 )
    v4->RefCount = (v4->RefCount + 1) & 0x8FBFFFFF;
  Scaleform::String::String(&v2->Path);
  v5 = (signed __int64)&v2->FileData;
  *(_OWORD *)v5 = 0ui64;
  *(_QWORD *)(v5 + 16) = 0i64;
}

// File Line: 55
// RVA: 0x852580
void __fastcall Scaleform::GFx::AS3::Instances::fl::Domain::loadBytes(Scaleform::GFx::AS3::Instances::fl::Domain *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *byteArray)
{
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *v3; // rbx
  Scaleform::GFx::AS3::Instances::fl::Domain *v4; // rbp
  unsigned __int64 v5; // r14
  Scaleform::GFx::AS3::Abc::Reader *v6; // rbx
  char *v7; // rax
  Scaleform::GFx::AS3::Abc::File *v8; // rax
  Scaleform::GFx::AS3::Abc::File *v9; // rax
  Scaleform::GFx::AS3::Abc::File *v10; // rsi
  Scaleform::GFx::AS3::VMAbcFile *v11; // rcx
  unsigned int v12; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> resulta; // [rsp+30h] [rbp-48h]
  __int64 v14; // [rsp+38h] [rbp-40h]
  Scaleform::GFx::AS3::Abc::Reader *v15; // [rsp+40h] [rbp-38h]
  char v16; // [rsp+48h] [rbp-30h]
  Scaleform::String src; // [rsp+80h] [rbp+8h]
  Scaleform::GFx::AS3::Abc::Reader *v18; // [rsp+90h] [rbp+18h]
  Scaleform::Ptr<Scaleform::GFx::AS3::Abc::File> file; // [rsp+98h] [rbp+20h]

  src.pData = (Scaleform::String::DataDesc *)this;
  v14 = -2i64;
  v3 = byteArray;
  v4 = this;
  v5 = byteArray->Length;
  Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH<unsigned char,328>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->FileData.Data,
    v5);
  memmove(v4->FileData.Data.Data, v3->Data.Data.Data, (unsigned int)v5);
  v6 = (Scaleform::GFx::AS3::Abc::Reader *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                             Scaleform::Memory::pGlobalHeap,
                                             16i64);
  v18 = v6;
  if ( v6 )
  {
    v7 = v4->FileData.Data.Data;
    v6->Size = v5;
    v6->CP = v7;
  }
  else
  {
    v6 = 0i64;
  }
  v15 = v6;
  v16 = 1;
  LODWORD(v18) = 338;
  v8 = (Scaleform::GFx::AS3::Abc::File *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                           Scaleform::Memory::pGlobalHeap,
                                           v4,
                                           368ui64,
                                           (Scaleform::AllocInfo *)&v18);
  file.pObject = v8;
  if ( v8 )
  {
    Scaleform::GFx::AS3::Abc::File::File(v8);
    v10 = v9;
  }
  else
  {
    v10 = 0i64;
  }
  file.pObject = v10;
  Scaleform::String::String(&src, "ByteArray");
  Scaleform::String::operator=(&v10->Source, &src);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  v10->DataSize = v5;
  if ( Scaleform::GFx::AS3::Abc::Reader::Read(v6, v10) )
  {
    Scaleform::GFx::AS3::VM::LoadFile(v4->pTraits.pObject->pVM, &resulta, &file, v4->VMDomain.pObject, 0);
    v11 = resulta.pObject;
    if ( resulta.pObject )
    {
      if ( !((_QWORD)resulta.pObject & 1) )
      {
        v12 = resulta.pObject->RefCount;
        if ( v12 & 0x3FFFFF )
        {
          resulta.pObject->RefCount = v12 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v11->vfptr);
        }
      }
    }
  }
  else
  {
    if ( v4->FileData.Data.Size && v4->FileData.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64 )
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorLH<unsigned char,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorLH<unsigned char,328>,Scaleform::ArrayDefaultPolicy> *)&v4->FileData.Data.Data,
        &v4->FileData,
        0i64);
    v4->FileData.Data.Size = 0i64;
  }
  Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v10);
  v16 = 0;
  if ( v6 )
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v6);
}

// File Line: 76
// RVA: 0x855F70
void __fastcall Scaleform::GFx::AS3::Instances::fl::Domain::parentDomainGet(Scaleform::GFx::AS3::Instances::fl::Domain *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Domain> *result)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> **v2; // rdi
  Scaleform::GFx::AS3::VMAppDomain *v3; // rsi
  Scaleform::GFx::AS3::Instances::fl::Domain *v4; // rcx
  unsigned int v5; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Domain> *v6; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v7; // rcx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *v8; // rbx
  unsigned int v9; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Domain> resulta; // [rsp+30h] [rbp+8h]

  v2 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> **)result;
  v3 = this->VMDomain.pObject->ParentDomain;
  if ( v3 )
  {
    v6 = Scaleform::GFx::AS3::InstanceTraits::fl::Domain::MakeInstance(
           &resulta,
           (Scaleform::GFx::AS3::InstanceTraits::fl::Domain *)this->pTraits.pObject);
    v7 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)*v2;
    v8 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)v6->pV;
    if ( (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)v6->pV != *v2 )
    {
      if ( v7 )
      {
        if ( (unsigned __int8)v7 & 1 )
        {
          *v2 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)((char *)&v7[-1].RefCount + 7);
        }
        else
        {
          v9 = v7->RefCount;
          if ( v9 & 0x3FFFFF )
          {
            v7->RefCount = v9 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v7);
          }
        }
      }
      *v2 = v8;
    }
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      *v2 + 7,
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)v3);
  }
  else
  {
    v4 = result->pObject;
    if ( result->pObject )
    {
      if ( (unsigned __int8)v4 & 1 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl::Domain *)((char *)v4 - 1);
        result->pObject = 0i64;
      }
      else
      {
        v5 = v4->RefCount;
        if ( v5 & 0x3FFFFF )
        {
          v4->RefCount = v5 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v4->vfptr);
        }
        *v2 = 0i64;
      }
    }
  }
}

// File Line: 90
// RVA: 0x84A960
void __fastcall Scaleform::GFx::AS3::Instances::fl::Domain::getClass(Scaleform::GFx::AS3::Instances::fl::Domain *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::ASString *name)
{
  Scaleform::GFx::AS3::Value *v3; // rbp
  Scaleform::GFx::AS3::Instances::fl::Domain *v4; // rsi
  const char *v5; // r8
  unsigned __int64 v6; // rax
  Scaleform::GFx::AS3::Multiname *v7; // rax
  Scaleform::GFx::AS3::Multiname *v8; // rdi
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329> *v9; // rsi
  Scaleform::GFx::AS3::VMAppDomain *v10; // rcx
  Scaleform::GFx::AS3::ClassTraits::Traits **v11; // rbx
  __int64 v12; // r8
  Scaleform::GFx::AS3::WeakProxy *v13; // rdx
  bool v14; // zf
  Scaleform::GFx::AS3::GASRefCountBase *v15; // rcx
  unsigned int v16; // eax
  Scaleform::GFx::AS3::Class **v17; // rbx
  Scaleform::StringDataPtr qname; // [rsp+28h] [rbp-50h]
  Scaleform::GFx::AS3::Multiname v19; // [rsp+38h] [rbp-40h]

  v3 = result;
  v4 = this;
  v5 = name->pNode->pData;
  qname.pStr = v5;
  if ( v5 )
  {
    v6 = -1i64;
    do
      ++v6;
    while ( v5[v6] );
    qname.Size = v6;
  }
  else
  {
    qname.Size = 0i64;
  }
  Scaleform::GFx::AS3::Multiname::Multiname(&v19, this->pTraits.pObject->pVM, &qname);
  v8 = v7;
  v9 = (Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329> *)v4->VMDomain.pObject;
  v10 = (Scaleform::GFx::AS3::VMAppDomain *)v9[2].Entries.mHash.pHeap;
  if ( !v10 || (v11 = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(v10, v7)) == 0i64 )
    v11 = Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Get(v9 + 3, v8);
  if ( (v19.Name.Flags & 0x1F) > 9 )
  {
    if ( (v19.Name.Flags >> 9) & 1 )
    {
      v13 = v19.Name.Bonus.pWeakProxy;
      v14 = v19.Name.Bonus.pWeakProxy->RefCount == 1;
      --v13->RefCount;
      if ( v14 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::WeakProxy *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v13,
          v12);
      v19.Name.Bonus.pWeakProxy = 0i64;
      v19.Name.value = 0ui64;
      v19.Name.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v19.Name);
    }
  }
  v15 = v19.Obj.pObject;
  if ( v19.Obj.pObject )
  {
    if ( (_QWORD)v19.Obj.pObject & 1 )
    {
      --v19.Obj.pObject;
    }
    else
    {
      v16 = v19.Obj.pObject->RefCount;
      if ( v16 & 0x3FFFFF )
      {
        v19.Obj.pObject->RefCount = v16 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v15->vfptr);
      }
    }
  }
  Scaleform::GFx::AS3::Value::SetNull(v3);
  if ( v11 )
  {
    v17 = (Scaleform::GFx::AS3::Class **)(*v11)->ITraits.pObject;
    if ( !v17[17] )
      ((void (__fastcall *)(Scaleform::GFx::AS3::Class **))(*v17)[1]._pRCC)(v17);
    Scaleform::GFx::AS3::Value::Assign(v3, v17[17]);
  }
}

// File Line: 99
// RVA: 0x851E80
void __fastcall Scaleform::GFx::AS3::Instances::fl::Domain::load(Scaleform::GFx::AS3::Instances::fl::Domain *this, bool *result, Scaleform::GFx::ASString *fileName)
{
  Scaleform::GFx::ASString *v3; // r13
  bool *v4; // r15
  Scaleform::GFx::AS3::Instances::fl::Domain *v5; // r14
  Scaleform::GFx::AS3::VM *v6; // rdi
  Scaleform::GFx::AS3::VM::Error *v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  const char *v10; // rbx
  unsigned int v11; // eax
  Scaleform::String *v12; // rax
  int v13; // edi
  unsigned __int64 v14; // rsi
  Scaleform::GFx::AS3::Abc::Reader *v15; // rdi
  char *v16; // rax
  Scaleform::GFx::AS3::Abc::File *v17; // rax
  Scaleform::GFx::AS3::Abc::File *v18; // rax
  Scaleform::GFx::AS3::Abc::File *v19; // rsi
  bool v20; // al
  Scaleform::GFx::AS3::VMAbcFile *v21; // rcx
  unsigned int v22; // eax
  Scaleform::GFx::AS3::VM::Error *v23; // rax
  Scaleform::GFx::ASStringNode *v24; // rcx
  Scaleform::String v25; // [rsp+30h] [rbp-69h]
  Scaleform::SysFile v26; // [rsp+38h] [rbp-61h]
  Scaleform::GFx::AS3::Abc::Reader *v27; // [rsp+50h] [rbp-49h]
  char v28; // [rsp+58h] [rbp-41h]
  Scaleform::GFx::AS3::VM *v29; // [rsp+60h] [rbp-39h]
  Scaleform::Ptr<Scaleform::GFx::AS3::Abc::File> file; // [rsp+68h] [rbp-31h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> v31; // [rsp+70h] [rbp-29h]
  Scaleform::String resulta; // [rsp+78h] [rbp-21h]
  __int64 v33; // [rsp+80h] [rbp-19h]
  Scaleform::GFx::AS3::VM::Error v34; // [rsp+88h] [rbp-11h]
  Scaleform::GFx::AS3::VM::Error v35; // [rsp+98h] [rbp-1h]
  Scaleform::GFx::AS3::Abc::File *v36; // [rsp+A8h] [rbp+Fh]
  Scaleform::GFx::AS3::Abc::Reader *v37; // [rsp+108h] [rbp+6Fh]
  int v38; // [rsp+110h] [rbp+77h]
  Scaleform::String src; // [rsp+118h] [rbp+7Fh]

  v33 = -2i64;
  v3 = fileName;
  v4 = result;
  v5 = this;
  *result = 0;
  Scaleform::SysFile::SysFile(&v26);
  v6 = v5->pTraits.pObject->pVM;
  v29 = v5->pTraits.pObject->pVM;
  if ( v3->pNode == &v3->pNode->pManager->NullStringNode )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v35, eNullArgumentError, v6);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v5->pTraits.pObject->pVM, v7, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v8 = v35.Message.pNode;
    v9 = v35.Message.pNode->RefCount == 1;
    --v8->RefCount;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
    if ( v26.pFile.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v26.pFile.pObject);
  }
  else
  {
    v10 = v3->pNode->pData;
    v11 = Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&v3->pNode);
    Scaleform::String::String(&src, v10, v11);
    if ( !Scaleform::GFx::URLBuilder::IsPathAbsolute((const char *)((src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12)) )
    {
      v12 = Scaleform::String::operator+(&v5->Path, &resulta, &src);
      Scaleform::String::operator=(&src, v12);
      if ( !_InterlockedDecrement((volatile signed __int32 *)((resulta.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    }
    if ( Scaleform::SysFile::Open(&v26, &src, 33, 438) )
    {
      v13 = ((__int64 (*)(void))v26.pFile.pObject->vfptr[6].__vecDelDtor)();
      v38 = v13;
      v14 = v13;
      Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH<unsigned char,328>,Scaleform::ArrayDefaultPolicy>::Resize(
        &v5->FileData.Data,
        v13);
      if ( ((unsigned int (__fastcall *)(Scaleform::File *, char *, _QWORD))v26.pFile.pObject->vfptr[10].__vecDelDtor)(
             v26.pFile.pObject,
             v5->FileData.Data.Data,
             (unsigned int)v13) == v13 )
      {
        v15 = (Scaleform::GFx::AS3::Abc::Reader *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                    Scaleform::Memory::pGlobalHeap,
                                                    16i64);
        v37 = v15;
        if ( v15 )
        {
          v16 = v5->FileData.Data.Data;
          v15->Size = v14;
          v15->CP = v16;
        }
        else
        {
          v15 = 0i64;
        }
        v27 = v15;
        v28 = 1;
        LODWORD(v37) = 338;
        v17 = (Scaleform::GFx::AS3::Abc::File *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                  Scaleform::Memory::pGlobalHeap,
                                                  v5,
                                                  368ui64,
                                                  (Scaleform::AllocInfo *)&v37);
        v36 = v17;
        if ( v17 )
        {
          Scaleform::GFx::AS3::Abc::File::File(v17);
          v19 = v18;
        }
        else
        {
          v19 = 0i64;
        }
        file.pObject = v19;
        Scaleform::String::String(&v25, v3->pNode->pData);
        Scaleform::String::operator=(&v19->Source, &v25);
        if ( !_InterlockedDecrement((volatile signed __int32 *)((v25.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v19->DataSize = v38;
        v20 = Scaleform::GFx::AS3::Abc::Reader::Read(v15, v19);
        *v4 = v20;
        if ( v20 )
        {
          Scaleform::GFx::AS3::VM::LoadFile(v29, &v31, &file, v5->VMDomain.pObject, 0);
          v21 = v31.pObject;
          if ( v31.pObject )
          {
            if ( !((_QWORD)v31.pObject & 1) )
            {
              v22 = v31.pObject->RefCount;
              if ( v22 & 0x3FFFFF )
              {
                v31.pObject->RefCount = v22 - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v21->vfptr);
              }
            }
          }
        }
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v19);
        if ( v15 )
        {
          v28 = 0;
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v15);
          v27 = 0i64;
        }
        v28 = 0;
      }
      if ( !*v4 )
        Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH<unsigned char,328>,Scaleform::ArrayDefaultPolicy>>::Clear((Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH<unsigned char,328>,Scaleform::ArrayDefaultPolicy> > *)&v5->FileData.Data);
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v34, eFileOpenError, v5->pTraits.pObject->pVM);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v6, v23, &Scaleform::GFx::AS3::fl::ErrorTI);
      v24 = v34.Message.pNode;
      v9 = v34.Message.pNode->RefCount == 1;
      --v24->RefCount;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v24);
    }
    if ( !_InterlockedDecrement((volatile signed __int32 *)((src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    if ( v26.pFile.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v26.pFile.pObject);
  }
  Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)&v26.vfptr);
}

// File Line: 144
// RVA: 0x796000
void __fastcall Scaleform::GFx::AS3::Instances::fl::Domain::AS3Constructor(Scaleform::GFx::AS3::Instances::fl::Domain *this, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Instances::fl::Domain *v3; // rsi
  Scaleform::GFx::AS3::Traits *v4; // rcx
  Scaleform::GFx::AS3::VM *v5; // rbx
  long double v6; // rdi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v7; // rax
  Scaleform::GFx::AS3::VMAppDomain *v8; // rcx
  unsigned int v9; // eax
  Scaleform::String *v10; // rax
  Scaleform::String::DataDesc *v11; // rdx
  Scaleform::GFx::AS3::VMAppDomain *v12; // rcx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAppDomain> *v13; // rax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAppDomain> *v14; // r14
  Scaleform::GFx::AS3::RefCountBaseGC<328> **v15; // rdi
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v16; // rcx
  unsigned int v17; // eax
  Scaleform::GFx::AS3::VMAppDomain *v18; // rcx
  unsigned int v19; // eax
  Scaleform::String *v20; // rax
  Scaleform::String v21; // [rsp+20h] [rbp-38h]
  Scaleform::String v22; // [rsp+28h] [rbp-30h]
  __int64 v23; // [rsp+30h] [rbp-28h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAppDomain> result; // [rsp+60h] [rbp+8h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAppDomain> v25; // [rsp+78h] [rbp+20h]

  v23 = -2i64;
  v3 = this;
  v4 = this->pTraits.pObject;
  v5 = v4->pVM;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 <= 3 )
    {
      v6 = argv->value.VNumber;
      if ( v6 != 0.0 && v4 == *(Scaleform::GFx::AS3::Traits **)(*(_QWORD *)&v6 + 40i64) )
      {
        v7 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)Scaleform::GFx::AS3::VMAppDomain::AddNewChild(
                                                                                     *(Scaleform::GFx::AS3::VMAppDomain **)(*(_QWORD *)&v6 + 56i64),
                                                                                     &result,
                                                                                     v4->pVM);
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object>::operator=(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)&v3->VMDomain,
          v7);
        v8 = result.pObject;
        if ( result.pObject )
        {
          if ( (_QWORD)result.pObject & 1 )
          {
            --result.pObject;
          }
          else
          {
            v9 = result.pObject->RefCount;
            if ( v9 & 0x3FFFFF )
            {
              result.pObject->RefCount = v9 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v8->vfptr);
            }
          }
        }
        if ( *(_QWORD *)(*(_QWORD *)(*(_QWORD *)&v6 + 64i64) & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64 )
        {
          Scaleform::String::operator=(&v3->Path, (Scaleform::String *)(*(_QWORD *)&v6 + 64i64));
          return;
        }
        if ( !v5->CallStack.Size )
          return;
        v10 = Scaleform::String::GetPath(
                &v5->CallStack.Pages[(v5->CallStack.Size - 1) >> 6][(LODWORD(v5->CallStack.Size) - 1) & 0x3F].pFile->File.pObject->Source,
                &v21);
        Scaleform::String::operator=(&v3->Path, v10);
        v11 = v21.pData;
        goto LABEL_34;
      }
    }
  }
  if ( v5->CallStack.Size && Scaleform::GFx::AS3::VMAppDomain::Enabled )
    v12 = v5->CallStack.Pages[(v5->CallStack.Size - 1) >> 6][(LODWORD(v5->CallStack.Size) - 1) & 0x3F].pFile->AppDomain.pObject;
  else
    v12 = v5->CurrentDomain.pObject;
  v13 = Scaleform::GFx::AS3::VMAppDomain::AddNewChild(v12, &v25, v5);
  v14 = v13;
  v15 = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v3->VMDomain;
  if ( v13 != &v3->VMDomain )
  {
    if ( v13->pObject )
      v13->pObject->RefCount = (v13->pObject->RefCount + 1) & 0x8FBFFFFF;
    v16 = *v15;
    if ( *v15 )
    {
      if ( (unsigned __int8)v16 & 1 )
      {
        *v15 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v16 - 1);
      }
      else
      {
        v17 = v16->RefCount;
        if ( v17 & 0x3FFFFF )
        {
          v16->RefCount = v17 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v16);
        }
      }
    }
    *v15 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v14->pObject->vfptr;
  }
  v18 = v25.pObject;
  if ( v25.pObject )
  {
    if ( (_QWORD)v25.pObject & 1 )
    {
      --v25.pObject;
    }
    else
    {
      v19 = v25.pObject->RefCount;
      if ( v19 & 0x3FFFFF )
      {
        v25.pObject->RefCount = v19 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v18->vfptr);
      }
    }
  }
  if ( v5->CallStack.Size )
  {
    v20 = Scaleform::String::GetPath(
            &v5->CallStack.Pages[(v5->CallStack.Size - 1) >> 6][(LODWORD(v5->CallStack.Size) - 1) & 0x3F].pFile->File.pObject->Source,
            &v22);
    Scaleform::String::operator=(&v3->Path, v20);
    v11 = v22.pData;
LABEL_34:
    if ( !_InterlockedDecrement((volatile signed __int32 *)(((unsigned __int64)v11 & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  }
}

// File Line: 186
// RVA: 0x7D5660
void __fastcall Scaleform::GFx::AS3::Instances::fl::Domain::ForEachChild_GC(Scaleform::GFx::AS3::Instances::fl::Domain *this, Scaleform::GFx::AS3::RefCountCollector<328> *prcc, void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  void (__fastcall *v3)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **); // rdi
  Scaleform::GFx::AS3::RefCountCollector<328> *v4; // rsi
  Scaleform::GFx::AS3::Instances::fl::Domain *v5; // rbx

  v3 = op;
  v4 = prcc;
  v5 = this;
  Scaleform::GFx::AS3::Object::ForEachChild_GC((Scaleform::GFx::AS3::Object *)&this->vfptr, prcc, op);
  if ( v5->VMDomain.pObject )
    v3(v4, (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v5->VMDomain);
}

// File Line: 221
// RVA: 0x7FF430
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Domain::MakeObject(Scaleform::GFx::AS3::InstanceTraits::fl::Domain *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::Object **v4; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Domain> resulta; // [rsp+48h] [rbp+20h]

  v3 = result;
  v4 = (Scaleform::GFx::AS3::Object **)Scaleform::GFx::AS3::InstanceTraits::fl::Domain::MakeInstance(
                                         &resulta,
                                         (Scaleform::GFx::AS3::InstanceTraits::fl::Domain *)t);
  Scaleform::GFx::AS3::Value::Pick(v3, *v4);
}

// File Line: 239
// RVA: 0x832D30
void __fastcall Scaleform::GFx::AS3::Classes::fl::Domain::currentDomainGet(Scaleform::GFx::AS3::Classes::fl::Domain *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Domain> *result)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> **v2; // rdi
  Scaleform::GFx::AS3::Classes::fl::Domain *v3; // rsi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Domain> *v4; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v5; // rcx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *v6; // rbx
  unsigned int v7; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Domain> resulta; // [rsp+30h] [rbp+8h]

  v2 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> **)result;
  v3 = this;
  v4 = Scaleform::GFx::AS3::InstanceTraits::fl::Domain::MakeInstance(
         &resulta,
         (Scaleform::GFx::AS3::InstanceTraits::fl::Domain *)this->pTraits.pObject[1].vfptr);
  v5 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)*v2;
  v6 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)v4->pV;
  if ( (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)v4->pV != *v2 )
  {
    if ( v5 )
    {
      if ( (unsigned __int8)v5 & 1 )
      {
        *v2 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)((char *)&v5[-1].RefCount + 7);
      }
      else
      {
        v7 = v5->RefCount;
        if ( v7 & 0x3FFFFF )
        {
          v5->RefCount = v7 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v5);
        }
      }
    }
    *v2 = v6;
  }
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    *v2 + 7,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)v3->pTraits.pObject->pVM->CurrentDomain.pObject);
}

// File Line: 253
// RVA: 0x1589590
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl::Domain_0_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl::Domain___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243B3E0 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl::Domain,0,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Domain>>::Method = Scaleform::GFx::AS3::Classes::fl::Domain::currentDomainGet;
  return result;
}

// File Line: 276
// RVA: 0x762BD0
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl::Domain::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // rbp
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v3; // rdi
  Scaleform::MemoryHeap *v4; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rbx
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v8; // rbx
  Scaleform::GFx::AS3::Class *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rbx

  v2 = vm;
  v3 = result;
  v4 = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->vfptr->Alloc(v4, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, v2, &Scaleform::GFx::AS3::fl::DomainCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable';
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Domain::`vftable';
  }
  else
  {
    v6 = 0i64;
  }
  v3->pV = v6;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)v4->vfptr->Alloc(v4, 240ui64, 0i64);
  v8 = v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, v2, &Scaleform::GFx::AS3::fl::DomainCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable';
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Domain::`vftable';
  }
  else
  {
    v8 = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(
    v3->pV,
    (Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits>)v8);
  v9 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v4->vfptr->Alloc)(
                                       v4,
                                       72i64);
  v10 = v9;
  if ( v9 )
  {
    Scaleform::GFx::AS3::Class::Class(v9, v3->pV);
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl::Domain::`vftable';
  }
  return v3;
}

