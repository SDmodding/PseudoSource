// File Line: 34
// RVA: 0x1597660
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain_0_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F678 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain,0,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain>>::Method = Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain::parentDomainGet;
  return result;
}

// File Line: 35
// RVA: 0x1599880
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain_1_Scaleform::GFx::AS3::Value_Scaleform::GFx::ASString_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F688 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain,1,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASString const &>::Method = Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain::getDefinition;
  return result;
}

// File Line: 36
// RVA: 0x15998B0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain_2_bool_Scaleform::GFx::ASString_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F698 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain,2,bool,Scaleform::GFx::ASString const &>::Method = Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain::hasDefinition;
  return result;
}

// File Line: 45
// RVA: 0x894810
void __fastcall Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain::ApplicationDomain(Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *this, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *v2; // rbx
  Scaleform::GFx::AS3::VMAppDomain *v3; // rax

  v2 = this;
  Scaleform::GFx::AS3::Instances::fl::Object::Object((Scaleform::GFx::AS3::Instances::fl::Object *)&this->vfptr, t);
  v2->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain::`vftable;
  v3 = Scaleform::GFx::AS3::VM::GetFrameAppDomain(v2->pTraits.pObject->pVM);
  v2->VMDomain.pObject = v3;
  if ( v3 )
    v3->RefCount = (v3->RefCount + 1) & 0x8FBFFFFF;
}

// File Line: 51
// RVA: 0x921A30
void __fastcall Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain::parentDomainGet(Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain> *result)
{
  Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *v2; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> **v3; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLList *v4; // rsi
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v5; // rcx
  unsigned int v6; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain> *v7; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v8; // rcx
  Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *v9; // rbx
  unsigned int v10; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain> resulta; // [rsp+30h] [rbp+8h]

  v2 = this;
  v3 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> **)result;
  v4 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::FontManagerStates::GetStateBagImpl((LOCALNAMESPACE::hkNativeResource *)this->VMDomain.pObject);
  if ( v4 )
  {
    v7 = Scaleform::GFx::AS3::InstanceTraits::fl_system::ApplicationDomain::MakeInstance(
           &resulta,
           (Scaleform::GFx::AS3::InstanceTraits::fl_system::ApplicationDomain *)v2->pTraits.pObject);
    v8 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)*v3;
    v9 = v7->pV;
    if ( (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)v7->pV != *v3 )
    {
      if ( v8 )
      {
        if ( (unsigned __int8)v8 & 1 )
        {
          *v3 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)((char *)&v8[-1].RefCount + 7);
        }
        else
        {
          v10 = v8->RefCount;
          if ( v10 & 0x3FFFFF )
          {
            v8->RefCount = v10 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v8);
          }
        }
      }
      *v3 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)v9;
    }
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(*v3 + 7, v4);
  }
  else
  {
    v5 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)*v3;
    if ( *v3 )
    {
      if ( (unsigned __int8)v5 & 1 )
      {
        *v3 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)((char *)&v5[-1].RefCount + 7);
        *v3 = 0i64;
      }
      else
      {
        v6 = v5->RefCount;
        if ( v6 & 0x3FFFFF )
        {
          v5->RefCount = v6 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v5);
        }
        *v3 = 0i64;
      }
    }
  }
}

// File Line: 67
// RVA: 0x9200F0
void __fastcall Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain::getDefinition(Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::ASString *name)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *v4; // rdi
  const char *v5; // rdx
  unsigned __int64 v6; // rax
  Scaleform::GFx::AS3::Multiname *v7; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits **v8; // rdi
  Scaleform::GFx::AS3::GASRefCountBase *v9; // rcx
  unsigned int v10; // eax
  Scaleform::GFx::AS3::Class *v11; // rax
  Scaleform::StringDataPtr qname; // [rsp+28h] [rbp-50h]
  Scaleform::GFx::AS3::Multiname v13; // [rsp+38h] [rbp-40h]

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
  Scaleform::GFx::AS3::Multiname::Multiname(&v13, this->pTraits.pObject->pVM, &qname);
  v8 = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(v4->VMDomain.pObject, v7);
  if ( (v13.Name.Flags & 0x1F) > 9 )
  {
    if ( (v13.Name.Flags >> 9) & 1 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v13.Name);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v13.Name);
  }
  v9 = v13.Obj.pObject;
  if ( v13.Obj.pObject )
  {
    if ( (_QWORD)v13.Obj.pObject & 1 )
    {
      --v13.Obj.pObject;
    }
    else
    {
      v10 = v13.Obj.pObject->RefCount;
      if ( v10 & 0x3FFFFF )
      {
        v13.Obj.pObject->RefCount = v10 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v9->vfptr);
      }
    }
  }
  if ( (v3->Flags & 0x1F) > 9 )
  {
    if ( (v3->Flags >> 9) & 1 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(v3);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(v3);
  }
  v3->Flags &= 0xFFFFFFEC;
  v3->Flags |= 0xCu;
  v3->value.VNumber = 0.0;
  v3->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)qname.Size;
  if ( v8 )
  {
    v11 = Scaleform::GFx::AS3::Traits::GetConstructor((Scaleform::GFx::AS3::Traits *)&(*v8)->ITraits.pObject->vfptr);
    Scaleform::GFx::AS3::Value::Assign(v3, v11);
  }
}

// File Line: 78
// RVA: 0x920B00
void __fastcall Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain::hasDefinition(Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *this, bool *result, Scaleform::GFx::ASString *name)
{
  bool *v3; // rdi
  Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *v4; // rbx
  const char *v5; // r8
  unsigned __int64 v6; // rax
  Scaleform::GFx::AS3::Multiname *v7; // rax
  Scaleform::GFx::AS3::GASRefCountBase *v8; // rcx
  unsigned int v9; // eax
  Scaleform::StringDataPtr qname; // [rsp+28h] [rbp-50h]
  Scaleform::GFx::AS3::Multiname v11; // [rsp+38h] [rbp-40h]

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
  Scaleform::GFx::AS3::Multiname::Multiname(&v11, this->pTraits.pObject->pVM, &qname);
  *v3 = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(v4->VMDomain.pObject, v7) != 0i64;
  if ( (v11.Name.Flags & 0x1F) > 9 )
  {
    if ( (v11.Name.Flags >> 9) & 1 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v11.Name);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v11.Name);
  }
  v8 = v11.Obj.pObject;
  if ( v11.Obj.pObject )
  {
    if ( (_QWORD)v11.Obj.pObject & 1 )
    {
      --v11.Obj.pObject;
    }
    else
    {
      v9 = v11.Obj.pObject->RefCount;
      if ( v9 & 0x3FFFFF )
      {
        v11.Obj.pObject->RefCount = v9 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v8->vfptr);
      }
    }
  }
}

// File Line: 86
// RVA: 0x8AE880
void __fastcall Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain::AS3Constructor(Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *this, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *v3; // rbx
  Scaleform::GFx::AS3::VM *v4; // rdi
  unsigned int v5; // edx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v6; // rax
  Scaleform::GFx::AS3::VMAppDomain *v7; // rax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAppDomain> *v8; // rax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAppDomain> *v9; // rdi
  Scaleform::GFx::AS3::RefCountBaseGC<328> **v10; // rbx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v11; // rcx
  unsigned int v12; // eax
  Scaleform::GFx::AS3::VMAppDomain *v13; // rcx
  unsigned int v14; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAppDomain> result; // [rsp+40h] [rbp+8h]

  v3 = this;
  v4 = this->pTraits.pObject->pVM;
  if ( argc && (v5 = argv->Flags & 0x1F) != 0 && (v5 - 12 > 3 && v5 != 10 || *(_QWORD *)&argv->value.VNumber) )
  {
    v6 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)Scaleform::GFx::AS3::VMAppDomain::AddNewChild(
                                                                                 *(Scaleform::GFx::AS3::VMAppDomain **)(*(_QWORD *)&argv->value.VNumber + 56i64),
                                                                                 &result,
                                                                                 v4);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object>::operator=(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)&v3->VMDomain,
      v6);
  }
  else
  {
    v7 = Scaleform::GFx::AS3::VM::GetFrameAppDomain(v4);
    v8 = Scaleform::GFx::AS3::VMAppDomain::AddNewChild(v7, &result, v4);
    v9 = v8;
    v10 = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v3->VMDomain;
    if ( v8 != (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAppDomain> *)v10 )
    {
      if ( v8->pObject )
        v8->pObject->RefCount = (v8->pObject->RefCount + 1) & 0x8FBFFFFF;
      v11 = *v10;
      if ( *v10 )
      {
        if ( (unsigned __int8)v11 & 1 )
        {
          *v10 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v11 - 1);
        }
        else
        {
          v12 = v11->RefCount;
          if ( v12 & 0x3FFFFF )
          {
            v11->RefCount = v12 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v11);
          }
        }
      }
      *v10 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v9->pObject->vfptr;
    }
  }
  v13 = result.pObject;
  if ( result.pObject )
  {
    if ( (_QWORD)result.pObject & 1 )
    {
      --result.pObject;
    }
    else
    {
      v14 = result.pObject->RefCount;
      if ( v14 & 0x3FFFFF )
      {
        result.pObject->RefCount = v14 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v13->vfptr);
      }
    }
  }
}

// File Line: 100
// RVA: 0x9062B0
void __fastcall Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain::SetAppDomain(Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *this, Scaleform::GFx::AS3::VMAppDomain *appDomain)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->VMDomain,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)appDomain);
}

// File Line: 132
// RVA: 0x8EAC70
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_system::ApplicationDomain::MakeObject(Scaleform::GFx::AS3::InstanceTraits::fl_system::ApplicationDomain *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::Object **v4; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain> resulta; // [rsp+48h] [rbp+20h]

  v3 = result;
  v4 = (Scaleform::GFx::AS3::Object **)Scaleform::GFx::AS3::InstanceTraits::fl_system::ApplicationDomain::MakeInstance(
                                         &resulta,
                                         (Scaleform::GFx::AS3::InstanceTraits::fl_system::ApplicationDomain *)t);
  Scaleform::GFx::AS3::Value::Pick(v3, *v4);
}

// File Line: 150
// RVA: 0x91E580
void __fastcall Scaleform::GFx::AS3::Classes::fl_system::ApplicationDomain::currentDomainGet(Scaleform::GFx::AS3::Classes::fl_system::ApplicationDomain *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain> *result)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> **v2; // rdi
  Scaleform::GFx::AS3::Classes::fl_system::ApplicationDomain *v3; // rsi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain> *v4; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v5; // rcx
  Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *v6; // rbx
  unsigned int v7; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain> resulta; // [rsp+30h] [rbp+8h]

  v2 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> **)result;
  v3 = this;
  v4 = Scaleform::GFx::AS3::InstanceTraits::fl_system::ApplicationDomain::MakeInstance(
         &resulta,
         (Scaleform::GFx::AS3::InstanceTraits::fl_system::ApplicationDomain *)this->pTraits.pObject[1].vfptr);
  v5 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)*v2;
  v6 = v4->pV;
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
    *v2 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)v6;
  }
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    *v2 + 7,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)v3->pTraits.pObject->pVM->CurrentDomain.pObject);
}

// File Line: 164
// RVA: 0x1597630
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_system::ApplicationDomain_0_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F6A8 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_system::ApplicationDomain,0,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain>>::Method = Scaleform::GFx::AS3::Classes::fl_system::ApplicationDomain::currentDomainGet;
  return result;
}

// File Line: 187
// RVA: 0x874960
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_system::ApplicationDomain::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // rbp
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v3; // rbx
  Scaleform::MemoryHeap *v4; // rsi
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v6; // rdi
  Scaleform::GFx::AS3::InstanceTraits::fl::Object *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::fl::Object *v8; // rdi
  Scaleform::GFx::AS3::Class *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rdi

  v2 = vm;
  v3 = result;
  v4 = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::fl::Object *)v4->vfptr->Alloc(v4, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::Object::Object(v5, v2, &Scaleform::GFx::AS3::fl_system::ApplicationDomainCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_system::ApplicationDomain::`vftable;
  }
  else
  {
    v6 = 0i64;
  }
  v3->pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)&v6->vfptr;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::fl::Object *)v4->vfptr->Alloc(v4, 240ui64, 0i64);
  v8 = v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::fl::Object::Object(
      v7,
      v2,
      &Scaleform::GFx::AS3::fl_system::ApplicationDomainCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_system::ApplicationDomain::`vftable;
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
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_system::ApplicationDomain::`vftable;
  }
  return v3;
}

