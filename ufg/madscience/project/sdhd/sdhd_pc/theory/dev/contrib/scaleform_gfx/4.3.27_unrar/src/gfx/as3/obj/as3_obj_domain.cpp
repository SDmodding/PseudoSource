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
void __fastcall Scaleform::GFx::AS3::Instances::fl::Domain::Domain(
        Scaleform::GFx::AS3::Instances::fl::Domain *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::VM *pVM; // r8
  Scaleform::GFx::AS3::VMAppDomain *pObject; // rdx

  Scaleform::GFx::AS3::Instance::Instance(this, t);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Domain::`vftable;
  pVM = this->pTraits.pObject->pVM;
  if ( pVM->CallStack.Size && Scaleform::GFx::AS3::VMAppDomain::Enabled )
    pObject = pVM->CallStack.Pages[(pVM->CallStack.Size - 1) >> 6][(LODWORD(pVM->CallStack.Size) - 1) & 0x3F].pFile->AppDomain.pObject;
  else
    pObject = pVM->CurrentDomain.pObject;
  this->VMDomain.pObject = pObject;
  if ( pObject )
    pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
  Scaleform::String::String(&this->Path);
  this->FileData.Data.Data = 0i64;
  this->FileData.Data.Size = 0i64;
  this->FileData.Data.Policy.Capacity = 0i64;
}

// File Line: 55
// RVA: 0x852580
void __fastcall Scaleform::GFx::AS3::Instances::fl::Domain::loadBytes(
        Scaleform::GFx::AS3::Instances::fl::Domain *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *byteArray)
{
  unsigned __int64 Length; // r14
  Scaleform::GFx::AS3::Abc::Reader *v6; // rbx
  char *Data; // rax
  Scaleform::GFx::AS3::Abc::File *v8; // rax
  Scaleform::GFx::AS3::Abc::File *v9; // rax
  Scaleform::GFx::AS3::Abc::File *v10; // rsi
  Scaleform::GFx::AS3::VMAbcFile *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> resulta; // [rsp+30h] [rbp-48h] BYREF
  __int64 v14; // [rsp+38h] [rbp-40h]
  Scaleform::GFx::AS3::Abc::Reader *v15; // [rsp+40h] [rbp-38h]
  char v16; // [rsp+48h] [rbp-30h]
  Scaleform::String src; // [rsp+80h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::Abc::Reader *v18; // [rsp+90h] [rbp+18h] BYREF
  Scaleform::Ptr<Scaleform::GFx::AS3::Abc::File> file; // [rsp+98h] [rbp+20h] BYREF

  src.pData = (Scaleform::String::DataDesc *)this;
  v14 = -2i64;
  Length = byteArray->Length;
  Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH<unsigned char,328>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->FileData.Data,
    Length);
  memmove(this->FileData.Data.Data, byteArray->Data.Data.Data, (unsigned int)Length);
  v6 = (Scaleform::GFx::AS3::Abc::Reader *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                             Scaleform::Memory::pGlobalHeap,
                                             16i64);
  v18 = v6;
  if ( v6 )
  {
    Data = this->FileData.Data.Data;
    v6->Size = Length;
    v6->CP = Data;
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
                                           this,
                                           368i64,
                                           &v18);
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
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  v10->DataSize = Length;
  if ( Scaleform::GFx::AS3::Abc::Reader::Read(v6, v10) )
  {
    Scaleform::GFx::AS3::VM::LoadFile(this->pTraits.pObject->pVM, &resulta, &file, this->VMDomain.pObject, 0);
    pObject = resulta.pObject;
    if ( resulta.pObject )
    {
      if ( ((__int64)resulta.pObject & 1) == 0 )
      {
        RefCount = resulta.pObject->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          resulta.pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
    }
  }
  else
  {
    if ( this->FileData.Data.Size && (this->FileData.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 )
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorLH<unsigned char,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &this->FileData.Data,
        &this->FileData,
        0i64);
    this->FileData.Data.Size = 0i64;
  }
  Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v10);
  v16 = 0;
  if ( v6 )
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v6);
}

// File Line: 76
// RVA: 0x855F70
void __fastcall Scaleform::GFx::AS3::Instances::fl::Domain::parentDomainGet(
        Scaleform::GFx::AS3::Instances::fl::Domain *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Domain> *result)
{
  Scaleform::GFx::AS3::VMAppDomain *ParentDomain; // rsi
  Scaleform::GFx::AS3::Instances::fl::Domain *v4; // rcx
  unsigned int v5; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Domain> *Instance; // rax
  Scaleform::GFx::AS3::Instances::fl::Domain *pObject; // rcx
  Scaleform::GFx::AS3::Instances::fl::Domain *pV; // rbx
  unsigned int RefCount; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Domain> resulta; // [rsp+30h] [rbp+8h] BYREF

  ParentDomain = this->VMDomain.pObject->ParentDomain;
  if ( ParentDomain )
  {
    Instance = Scaleform::GFx::AS3::InstanceTraits::fl::Domain::MakeInstance(
                 &resulta,
                 (Scaleform::GFx::AS3::InstanceTraits::fl::Domain *)this->pTraits.pObject);
    pObject = result->pObject;
    pV = Instance->pV;
    if ( Instance->pV != result->pObject )
    {
      if ( pObject )
      {
        if ( ((unsigned __int8)pObject & 1) != 0 )
        {
          result->pObject = (Scaleform::GFx::AS3::Instances::fl::Domain *)((char *)pObject - 1);
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
      result->pObject = pV;
    }
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&result->pObject->VMDomain,
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)ParentDomain);
  }
  else
  {
    v4 = result->pObject;
    if ( result->pObject )
    {
      if ( ((unsigned __int8)v4 & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl::Domain *)((char *)v4 - 1);
        result->pObject = 0i64;
      }
      else
      {
        v5 = v4->RefCount;
        if ( (v5 & 0x3FFFFF) != 0 )
        {
          v4->RefCount = v5 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v4);
        }
        result->pObject = 0i64;
      }
    }
  }
}

// File Line: 90
// RVA: 0x84A960
void __fastcall Scaleform::GFx::AS3::Instances::fl::Domain::getClass(
        Scaleform::GFx::AS3::Instances::fl::Domain *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::ASString *name)
{
  const char *pData; // r8
  unsigned __int64 v6; // rax
  Scaleform::GFx::AS3::Multiname *v7; // rax
  Scaleform::GFx::AS3::Multiname *v8; // rdi
  Scaleform::GFx::AS3::VMAppDomain *pObject; // rsi
  Scaleform::GFx::AS3::VMAppDomain *ParentDomain; // rcx
  Scaleform::GFx::AS3::ClassTraits::Traits **ClassTrait; // rbx
  Scaleform::GFx::AS3::GASRefCountBase *v13; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Class **v15; // rbx
  Scaleform::StringDataPtr qname; // [rsp+28h] [rbp-50h] BYREF
  Scaleform::GFx::AS3::Multiname v17; // [rsp+38h] [rbp-40h] BYREF

  pData = name->pNode->pData;
  qname.pStr = pData;
  if ( pData )
  {
    v6 = -1i64;
    do
      ++v6;
    while ( pData[v6] );
    qname.Size = v6;
  }
  else
  {
    qname.Size = 0i64;
  }
  Scaleform::GFx::AS3::Multiname::Multiname(&v17, this->pTraits.pObject->pVM, &qname);
  v8 = v7;
  pObject = this->VMDomain.pObject;
  ParentDomain = pObject->ParentDomain;
  if ( !ParentDomain || (ClassTrait = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(ParentDomain, v7)) == 0i64 )
    ClassTrait = Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Get(
                   &pObject->ClassTraitsSet,
                   v8);
  if ( (v17.Name.Flags & 0x1F) > 9 )
  {
    if ( (v17.Name.Flags & 0x200) != 0 )
    {
      if ( v17.Name.Bonus.pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v17.Name.Bonus, 0, 24);
      v17.Name.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v17.Name);
    }
  }
  v13 = v17.Obj.pObject;
  if ( v17.Obj.pObject )
  {
    if ( ((__int64)v17.Obj.pObject & 1) != 0 )
    {
      --v17.Obj.pObject;
    }
    else
    {
      RefCount = v17.Obj.pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        v17.Obj.pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v13);
      }
    }
  }
  Scaleform::GFx::AS3::Value::SetNull(result);
  if ( ClassTrait )
  {
    v15 = (Scaleform::GFx::AS3::Class **)(*ClassTrait)->ITraits.pObject;
    if ( !v15[17] )
      ((void (__fastcall *)(Scaleform::GFx::AS3::Class **))(*v15)[1]._pRCC)(v15);
    Scaleform::GFx::AS3::Value::Assign(result, v15[17]);
  }
}

// File Line: 99
// RVA: 0x851E80
void __fastcall Scaleform::GFx::AS3::Instances::fl::Domain::load(
        Scaleform::GFx::AS3::Instances::fl::Domain *this,
        bool *result,
        Scaleform::GFx::ASString *fileName)
{
  Scaleform::GFx::AS3::VM *pVM; // rdi
  Scaleform::GFx::AS3::VM::Error *v7; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v9; // zf
  const char *pData; // rbx
  unsigned int Length; // eax
  Scaleform::String *v12; // rax
  int v13; // edi
  unsigned __int64 v14; // rsi
  Scaleform::GFx::AS3::Abc::Reader *v15; // rdi
  char *Data; // rax
  Scaleform::GFx::AS3::Abc::File *v17; // rax
  Scaleform::GFx::AS3::Abc::File *v18; // rax
  Scaleform::GFx::AS3::Abc::File *v19; // rsi
  bool v20; // al
  Scaleform::GFx::AS3::VMAbcFile *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::VM::Error *v23; // rax
  Scaleform::GFx::ASStringNode *v24; // rcx
  Scaleform::String v25; // [rsp+30h] [rbp-69h] BYREF
  Scaleform::SysFile v26; // [rsp+38h] [rbp-61h] BYREF
  Scaleform::GFx::AS3::Abc::Reader *v27; // [rsp+50h] [rbp-49h]
  char v28; // [rsp+58h] [rbp-41h]
  Scaleform::GFx::AS3::VM *v29; // [rsp+60h] [rbp-39h]
  Scaleform::Ptr<Scaleform::GFx::AS3::Abc::File> file; // [rsp+68h] [rbp-31h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> v31; // [rsp+70h] [rbp-29h] BYREF
  Scaleform::String resulta; // [rsp+78h] [rbp-21h] BYREF
  __int64 v33; // [rsp+80h] [rbp-19h]
  Scaleform::GFx::AS3::VM::Error v34; // [rsp+88h] [rbp-11h] BYREF
  Scaleform::GFx::AS3::VM::Error v35; // [rsp+98h] [rbp-1h] BYREF
  Scaleform::GFx::AS3::Abc::File *v36; // [rsp+A8h] [rbp+Fh]
  Scaleform::GFx::AS3::Abc::Reader *v37; // [rsp+108h] [rbp+6Fh] BYREF
  int v38; // [rsp+110h] [rbp+77h]
  Scaleform::String src; // [rsp+118h] [rbp+7Fh] BYREF

  v33 = -2i64;
  *result = 0;
  Scaleform::SysFile::SysFile(&v26);
  pVM = this->pTraits.pObject->pVM;
  v29 = pVM;
  if ( fileName->pNode == &fileName->pNode->pManager->NullStringNode )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v35, 1507, pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(this->pTraits.pObject->pVM, v7, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v35.Message.pNode;
    v9 = v35.Message.pNode->RefCount-- == 1;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    if ( v26.pFile.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v26.pFile.pObject);
  }
  else
  {
    pData = fileName->pNode->pData;
    Length = Scaleform::GFx::ASConstString::GetLength(fileName);
    Scaleform::String::String(&src, pData, Length);
    if ( !Scaleform::GFx::URLBuilder::IsPathAbsolute((const char *)((src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12)) )
    {
      v12 = Scaleform::String::operator+(&this->Path, &resulta, &src);
      Scaleform::String::operator=(&src, v12);
      if ( !_InterlockedDecrement((volatile signed __int32 *)((resulta.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    }
    if ( Scaleform::SysFile::Open(&v26, &src, 33, 438) )
    {
      v13 = ((__int64 (__fastcall *)(Scaleform::File *))v26.pFile.pObject->Scaleform::DelegatedFile::vfptr[6].__vecDelDtor)(v26.pFile.pObject);
      v38 = v13;
      v14 = v13;
      Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH<unsigned char,328>,Scaleform::ArrayDefaultPolicy>::Resize(
        &this->FileData.Data,
        v13);
      if ( ((unsigned int (__fastcall *)(Scaleform::File *, char *, _QWORD))v26.pFile.pObject->Scaleform::DelegatedFile::vfptr[10].__vecDelDtor)(
             v26.pFile.pObject,
             this->FileData.Data.Data,
             (unsigned int)v13) == v13 )
      {
        v15 = (Scaleform::GFx::AS3::Abc::Reader *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                    Scaleform::Memory::pGlobalHeap,
                                                    16i64);
        v37 = v15;
        if ( v15 )
        {
          Data = this->FileData.Data.Data;
          v15->Size = v14;
          v15->CP = Data;
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
                                                  this,
                                                  368i64,
                                                  &v37);
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
        Scaleform::String::String(&v25, fileName->pNode->pData);
        Scaleform::String::operator=(&v19->Source, &v25);
        if ( !_InterlockedDecrement((volatile signed __int32 *)((v25.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        v19->DataSize = v38;
        v20 = Scaleform::GFx::AS3::Abc::Reader::Read(v15, v19);
        *result = v20;
        if ( v20 )
        {
          Scaleform::GFx::AS3::VM::LoadFile(v29, &v31, &file, this->VMDomain.pObject, 0);
          pObject = v31.pObject;
          if ( v31.pObject )
          {
            if ( ((__int64)v31.pObject & 1) == 0 )
            {
              RefCount = v31.pObject->RefCount;
              if ( (RefCount & 0x3FFFFF) != 0 )
              {
                v31.pObject->RefCount = RefCount - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
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
      if ( !*result )
        Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH<unsigned char,328>,Scaleform::ArrayDefaultPolicy>>::Clear(&this->FileData);
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v34, 1500, this->pTraits.pObject->pVM);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(pVM, v23, &Scaleform::GFx::AS3::fl::ErrorTI);
      v24 = v34.Message.pNode;
      v9 = v34.Message.pNode->RefCount-- == 1;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v24);
    }
    if ( !_InterlockedDecrement((volatile signed __int32 *)((src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    if ( v26.pFile.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v26.pFile.pObject);
  }
  Scaleform::RefCountImplCore::~RefCountImplCore(&v26);
}

// File Line: 144
// RVA: 0x796000
void __fastcall Scaleform::GFx::AS3::Instances::fl::Domain::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl::Domain *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Traits *pObject; // rcx
  Scaleform::GFx::AS3::VM *pVM; // rbx
  Scaleform::GFx::AS3::Value::V1U v6; // rdi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v7; // rax
  Scaleform::GFx::AS3::VMAppDomain *v8; // rcx
  unsigned int RefCount; // eax
  Scaleform::String *Path; // rax
  Scaleform::String::DataDesc *pData; // rdx
  Scaleform::GFx::AS3::VMAppDomain *v12; // rcx
  Scaleform::GFx::AS3::Instances::fl::Domain *v13; // rax
  Scaleform::GFx::AS3::Instances::fl::Domain *v14; // r14
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAppDomain> *p_VMDomain; // rdi
  Scaleform::GFx::AS3::VMAppDomain *v16; // rcx
  unsigned int v17; // eax
  Scaleform::GFx::AS3::VMAppDomain *v18; // rcx
  unsigned int v19; // eax
  Scaleform::String *v20; // rax
  Scaleform::String v21; // [rsp+20h] [rbp-38h] BYREF
  Scaleform::String v22; // [rsp+28h] [rbp-30h] BYREF
  __int64 v23; // [rsp+30h] [rbp-28h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAppDomain> result; // [rsp+60h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAppDomain> v25; // [rsp+78h] [rbp+20h] BYREF

  v23 = -2i64;
  pObject = this->pTraits.pObject;
  pVM = pObject->pVM;
  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 <= 3 )
    {
      v6 = argv->value.VS._1;
      if ( v6.VStr )
      {
        if ( pObject == (Scaleform::GFx::AS3::Traits *)v6.VStr[1].pData )
        {
          v7 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)Scaleform::GFx::AS3::VMAppDomain::AddNewChild(
                                                                                       (Scaleform::GFx::AS3::VMAppDomain *)v6.VStr[1].pLower,
                                                                                       &result,
                                                                                       pObject->pVM);
          Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object>::operator=(
            (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)&this->VMDomain,
            v7);
          v8 = result.pObject;
          if ( result.pObject )
          {
            if ( ((__int64)result.pObject & 1) != 0 )
            {
              --result.pObject;
            }
            else
            {
              RefCount = result.pObject->RefCount;
              if ( (RefCount & 0x3FFFFF) != 0 )
              {
                result.pObject->RefCount = RefCount - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v8);
              }
            }
          }
          if ( (*(_QWORD *)(*(_QWORD *)&v6.VStr[1].RefCount & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64) != 0 )
          {
            Scaleform::String::operator=(&this->Path, (Scaleform::String *)&v6.VStr[1].RefCount);
            return;
          }
          if ( !pVM->CallStack.Size )
            return;
          Path = Scaleform::String::GetPath(
                   &pVM->CallStack.Pages[(pVM->CallStack.Size - 1) >> 6][(LODWORD(pVM->CallStack.Size) - 1) & 0x3F].pFile->File.pObject->Source,
                   &v21);
          Scaleform::String::operator=(&this->Path, Path);
          pData = v21.pData;
          goto LABEL_34;
        }
      }
    }
  }
  if ( pVM->CallStack.Size && Scaleform::GFx::AS3::VMAppDomain::Enabled )
    v12 = pVM->CallStack.Pages[(pVM->CallStack.Size - 1) >> 6][(LODWORD(pVM->CallStack.Size) - 1) & 0x3F].pFile->AppDomain.pObject;
  else
    v12 = pVM->CurrentDomain.pObject;
  v13 = (Scaleform::GFx::AS3::Instances::fl::Domain *)Scaleform::GFx::AS3::VMAppDomain::AddNewChild(v12, &v25, pVM);
  v14 = v13;
  p_VMDomain = &this->VMDomain;
  if ( v13 != (Scaleform::GFx::AS3::Instances::fl::Domain *)&this->VMDomain )
  {
    if ( v13->vfptr )
      LODWORD(v13->vfptr[1].~RefCountBaseGC<328>) = (LODWORD(v13->vfptr[1].~RefCountBaseGC<328>) + 1) & 0x8FBFFFFF;
    v16 = p_VMDomain->pObject;
    if ( p_VMDomain->pObject )
    {
      if ( ((unsigned __int8)v16 & 1) != 0 )
      {
        p_VMDomain->pObject = (Scaleform::GFx::AS3::VMAppDomain *)((char *)v16 - 1);
      }
      else
      {
        v17 = v16->RefCount;
        if ( (v17 & 0x3FFFFF) != 0 )
        {
          v16->RefCount = v17 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v16);
        }
      }
    }
    p_VMDomain->pObject = (Scaleform::GFx::AS3::VMAppDomain *)v14->vfptr;
  }
  v18 = v25.pObject;
  if ( v25.pObject )
  {
    if ( ((__int64)v25.pObject & 1) != 0 )
    {
      --v25.pObject;
    }
    else
    {
      v19 = v25.pObject->RefCount;
      if ( (v19 & 0x3FFFFF) != 0 )
      {
        v25.pObject->RefCount = v19 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v18);
      }
    }
  }
  if ( pVM->CallStack.Size )
  {
    v20 = Scaleform::String::GetPath(
            &pVM->CallStack.Pages[(pVM->CallStack.Size - 1) >> 6][(LODWORD(pVM->CallStack.Size) - 1) & 0x3F].pFile->File.pObject->Source,
            &v22);
    Scaleform::String::operator=(&this->Path, v20);
    pData = v22.pData;
LABEL_34:
    if ( !_InterlockedDecrement((volatile signed __int32 *)(((unsigned __int64)pData & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
}

// File Line: 186
// RVA: 0x7D5660
void __fastcall Scaleform::GFx::AS3::Instances::fl::Domain::ForEachChild_GC(
        Scaleform::GFx::AS3::Instances::fl::Domain *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  Scaleform::GFx::AS3::Object::ForEachChild_GC(this, prcc, op);
  if ( this->VMDomain.pObject )
    op(prcc, &this->VMDomain.pObject);
}

// File Line: 221
// RVA: 0x7FF430
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Domain::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl::Domain *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl::Domain *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Domain> *Instance; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Domain> resulta; // [rsp+48h] [rbp+20h] BYREF

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl::Domain::MakeInstance(&resulta, t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}

// File Line: 239
// RVA: 0x832D30
void __fastcall Scaleform::GFx::AS3::Classes::fl::Domain::currentDomainGet(
        Scaleform::GFx::AS3::Classes::fl::Domain *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Domain> *result)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Domain> *Instance; // rax
  Scaleform::GFx::AS3::Instances::fl::Domain *pObject; // rcx
  Scaleform::GFx::AS3::Instances::fl::Domain *pV; // rbx
  unsigned int RefCount; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Domain> resulta; // [rsp+30h] [rbp+8h] BYREF

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl::Domain::MakeInstance(
               &resulta,
               (Scaleform::GFx::AS3::InstanceTraits::fl::Domain *)this->pTraits.pObject[1].vfptr);
  pObject = result->pObject;
  pV = Instance->pV;
  if ( Instance->pV != result->pObject )
  {
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl::Domain *)((char *)pObject - 1);
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
    result->pObject = pV;
  }
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&result->pObject->VMDomain,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)this->pTraits.pObject->pVM->CurrentDomain.pObject);
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
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl::Domain::MakeClassTraits(
        Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rbx
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v8; // rbx
  Scaleform::GFx::AS3::Class *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rbx

  MHeap = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)MHeap->vfptr->Alloc(MHeap, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, vm, &Scaleform::GFx::AS3::fl::DomainCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Domain::`vftable;
  }
  else
  {
    v6 = 0i64;
  }
  result->pV = v6;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)MHeap->vfptr->Alloc(MHeap, 240ui64, 0i64);
  v8 = v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, vm, &Scaleform::GFx::AS3::fl::DomainCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Domain::`vftable;
  }
  else
  {
    v8 = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(
    result->pV,
    (Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits>)v8);
  v9 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))MHeap->vfptr->Alloc)(
                                       MHeap,
                                       72i64);
  v10 = v9;
  if ( v9 )
  {
    Scaleform::GFx::AS3::Class::Class(v9, result->pV);
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl::Domain::`vftable;
  }
  return result;
}

