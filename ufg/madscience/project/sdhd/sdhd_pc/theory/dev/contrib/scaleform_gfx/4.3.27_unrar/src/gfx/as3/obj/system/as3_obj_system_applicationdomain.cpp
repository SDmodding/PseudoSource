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
void __fastcall Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain::ApplicationDomain(
        Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::VMAppDomain *FrameAppDomain; // rax

  Scaleform::GFx::AS3::Instances::fl::Object::Object(this, t);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain::`vftable;
  FrameAppDomain = Scaleform::GFx::AS3::VM::GetFrameAppDomain(this->pTraits.pObject->pVM);
  this->VMDomain.pObject = FrameAppDomain;
  if ( FrameAppDomain )
    FrameAppDomain->RefCount = (FrameAppDomain->RefCount + 1) & 0x8FBFFFFF;
}

// File Line: 51
// RVA: 0x921A30
void __fastcall Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain::parentDomainGet(
        Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain> *result)
{
  Scaleform::GFx::AS3::Instances::fl::XMLList *StateBagImpl; // rsi
  Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *v5; // rcx
  unsigned int v6; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain> *Instance; // rax
  Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *pObject; // rcx
  Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *pV; // rbx
  unsigned int RefCount; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain> resulta; // [rsp+30h] [rbp+8h] BYREF

  StateBagImpl = (Scaleform::GFx::AS3::Instances::fl::XMLList *)Scaleform::GFx::FontManagerStates::GetStateBagImpl((LOCALNAMESPACE::hkNativeResource *)this->VMDomain.pObject);
  if ( StateBagImpl )
  {
    Instance = Scaleform::GFx::AS3::InstanceTraits::fl_system::ApplicationDomain::MakeInstance(
                 &resulta,
                 (Scaleform::GFx::AS3::InstanceTraits::fl_system::ApplicationDomain *)this->pTraits.pObject);
    pObject = result->pObject;
    pV = Instance->pV;
    if ( Instance->pV != result->pObject )
    {
      if ( pObject )
      {
        if ( ((unsigned __int8)pObject & 1) != 0 )
        {
          result->pObject = (Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *)((char *)pObject - 1);
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
      StateBagImpl);
  }
  else
  {
    v5 = result->pObject;
    if ( result->pObject )
    {
      if ( ((unsigned __int8)v5 & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *)((char *)v5 - 1);
        result->pObject = 0i64;
      }
      else
      {
        v6 = v5->RefCount;
        if ( (v6 & 0x3FFFFF) != 0 )
        {
          v5->RefCount = v6 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v5);
        }
        result->pObject = 0i64;
      }
    }
  }
}

// File Line: 67
// RVA: 0x9200F0
void __fastcall Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain::getDefinition(
        Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::ASString *name)
{
  const char *pData; // rdx
  unsigned __int64 v6; // rax
  Scaleform::GFx::AS3::Multiname *v7; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits **ClassTrait; // rdi
  Scaleform::GFx::AS3::GASRefCountBase *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Class *Constructor; // rax
  Scaleform::StringDataPtr qname; // [rsp+28h] [rbp-50h] BYREF
  Scaleform::GFx::AS3::Multiname v13; // [rsp+38h] [rbp-40h] BYREF

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
  Scaleform::GFx::AS3::Multiname::Multiname(&v13, this->pTraits.pObject->pVM, &qname);
  ClassTrait = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(this->VMDomain.pObject, v7);
  if ( (v13.Name.Flags & 0x1F) > 9 )
  {
    if ( (v13.Name.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v13.Name);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v13.Name);
  }
  pObject = v13.Obj.pObject;
  if ( v13.Obj.pObject )
  {
    if ( ((__int64)v13.Obj.pObject & 1) != 0 )
    {
      --v13.Obj.pObject;
    }
    else
    {
      RefCount = v13.Obj.pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        v13.Obj.pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
  if ( (result->Flags & 0x1F) > 9 )
  {
    if ( (result->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(result);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(result);
  }
  result->Flags &= 0xFFFFFFEC;
  result->Flags |= 0xCu;
  result->value.VS._1.VStr = 0i64;
  result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)qname.Size;
  if ( ClassTrait )
  {
    Constructor = Scaleform::GFx::AS3::Traits::GetConstructor((*ClassTrait)->ITraits.pObject);
    Scaleform::GFx::AS3::Value::Assign(result, Constructor);
  }
}

// File Line: 78
// RVA: 0x920B00
void __fastcall Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain::hasDefinition(
        Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *this,
        bool *result,
        Scaleform::GFx::ASString *name)
{
  const char *pData; // r8
  unsigned __int64 v6; // rax
  Scaleform::GFx::AS3::Multiname *v7; // rax
  Scaleform::GFx::AS3::GASRefCountBase *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::StringDataPtr qname; // [rsp+28h] [rbp-50h] BYREF
  Scaleform::GFx::AS3::Multiname v11; // [rsp+38h] [rbp-40h] BYREF

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
  Scaleform::GFx::AS3::Multiname::Multiname(&v11, this->pTraits.pObject->pVM, &qname);
  *result = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(this->VMDomain.pObject, v7) != 0i64;
  if ( (v11.Name.Flags & 0x1F) > 9 )
  {
    if ( (v11.Name.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v11.Name);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v11.Name);
  }
  pObject = v11.Obj.pObject;
  if ( v11.Obj.pObject )
  {
    if ( ((__int64)v11.Obj.pObject & 1) != 0 )
    {
      --v11.Obj.pObject;
    }
    else
    {
      RefCount = v11.Obj.pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        v11.Obj.pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
}

// File Line: 86
// RVA: 0x8AE880
void __fastcall Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::VM *pVM; // rdi
  unsigned int v5; // edx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v6; // rax
  Scaleform::GFx::AS3::VMAppDomain *FrameAppDomain; // rax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAppDomain> *v8; // rax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAppDomain> *v9; // rdi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAppDomain> *p_VMDomain; // rbx
  Scaleform::GFx::AS3::VMAppDomain *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::VMAppDomain *v13; // rcx
  unsigned int v14; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAppDomain> result; // [rsp+40h] [rbp+8h] BYREF

  pVM = this->pTraits.pObject->pVM;
  if ( argc && (v5 = argv->Flags & 0x1F) != 0 && (v5 - 12 > 3 && v5 != 10 || argv->value.VS._1.VStr) )
  {
    v6 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)Scaleform::GFx::AS3::VMAppDomain::AddNewChild(
                                                                                 (Scaleform::GFx::AS3::VMAppDomain *)argv->value.VS._1.VStr[1].pLower,
                                                                                 &result,
                                                                                 pVM);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object>::operator=(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)&this->VMDomain,
      v6);
  }
  else
  {
    FrameAppDomain = Scaleform::GFx::AS3::VM::GetFrameAppDomain(pVM);
    v8 = Scaleform::GFx::AS3::VMAppDomain::AddNewChild(FrameAppDomain, &result, pVM);
    v9 = v8;
    p_VMDomain = &this->VMDomain;
    if ( v8 != p_VMDomain )
    {
      if ( v8->pObject )
        v8->pObject->RefCount = (v8->pObject->RefCount + 1) & 0x8FBFFFFF;
      pObject = p_VMDomain->pObject;
      if ( p_VMDomain->pObject )
      {
        if ( ((unsigned __int8)pObject & 1) != 0 )
        {
          p_VMDomain->pObject = (Scaleform::GFx::AS3::VMAppDomain *)((char *)pObject - 1);
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
      p_VMDomain->pObject = v9->pObject;
    }
  }
  v13 = result.pObject;
  if ( result.pObject )
  {
    if ( ((__int64)result.pObject & 1) != 0 )
    {
      --result.pObject;
    }
    else
    {
      v14 = result.pObject->RefCount;
      if ( (v14 & 0x3FFFFF) != 0 )
      {
        result.pObject->RefCount = v14 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v13);
      }
    }
  }
}

// File Line: 100
// RVA: 0x9062B0
void __fastcall Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain::SetAppDomain(
        Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *this,
        Scaleform::GFx::AS3::Instances::fl::XMLList *appDomain)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->VMDomain,
    appDomain);
}

// File Line: 132
// RVA: 0x8EAC70
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_system::ApplicationDomain::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_system::ApplicationDomain *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_system::ApplicationDomain *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain> *Instance; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain> resulta; // [rsp+48h] [rbp+20h] BYREF

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_system::ApplicationDomain::MakeInstance(&resulta, t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}

// File Line: 150
// RVA: 0x91E580
void __fastcall Scaleform::GFx::AS3::Classes::fl_system::ApplicationDomain::currentDomainGet(
        Scaleform::GFx::AS3::Classes::fl_system::ApplicationDomain *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain> *result)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain> *Instance; // rax
  Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *pObject; // rcx
  Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *pV; // rbx
  unsigned int RefCount; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain> resulta; // [rsp+30h] [rbp+8h] BYREF

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_system::ApplicationDomain::MakeInstance(
               &resulta,
               (Scaleform::GFx::AS3::InstanceTraits::fl_system::ApplicationDomain *)this->pTraits.pObject[1].vfptr);
  pObject = result->pObject;
  pV = Instance->pV;
  if ( Instance->pV != result->pObject )
  {
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *)((char *)pObject - 1);
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
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_system::ApplicationDomain::MakeClassTraits(
        Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // rsi
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rdi
  Scaleform::GFx::AS3::InstanceTraits::fl::Object *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::fl::Object *v8; // rdi
  Scaleform::GFx::AS3::Class *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rdi

  MHeap = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::fl::Object *)MHeap->vfptr->Alloc(MHeap, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::Object::Object(v5, vm, &Scaleform::GFx::AS3::fl_system::ApplicationDomainCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_system::ApplicationDomain::`vftable;
  }
  else
  {
    v6 = 0i64;
  }
  result->pV = v6;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::fl::Object *)MHeap->vfptr->Alloc(MHeap, 240ui64, 0i64);
  v8 = v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::fl::Object::Object(
      v7,
      vm,
      &Scaleform::GFx::AS3::fl_system::ApplicationDomainCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_system::ApplicationDomain::`vftable;
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
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_system::ApplicationDomain::`vftable;
  }
  return result;
}

