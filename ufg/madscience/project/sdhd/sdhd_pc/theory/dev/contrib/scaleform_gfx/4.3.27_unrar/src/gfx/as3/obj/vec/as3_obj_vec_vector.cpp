// File Line: 53
// RVA: 0x903700
Scaleform::GFx::AS3::ClassTraits::Traits **__fastcall Scaleform::GFx::AS3::Classes::fl_vec::Vector::Resolve2Vector(
        Scaleform::GFx::AS3::Classes::fl_vec::Vector *this,
        Scaleform::GFx::AS3::ClassTraits::Traits *elem)
{
  Scaleform::GFx::AS3::VM *pVM; // rsi
  Scaleform::GFx::ASString *v5; // rdi
  Scaleform::GFx::ASString *v6; // rax
  Scaleform::GFx::ASString *v7; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v9; // zf
  Scaleform::GFx::ASStringNode *v10; // rcx
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::GFx::AS3::VMAppDomain *AppDomain; // rbp
  __int64 v13; // rcx
  Scaleform::GFx::AS3::ClassTraits::Traits **RegisteredClassTraits; // rdi
  Scaleform::GFx::ASStringNode *v15; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits **v16; // rax
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,340>,Scaleform::ArrayDefaultPolicy> *v17; // rax
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,340>,Scaleform::ArrayDefaultPolicy> *v18; // rbx
  Scaleform::GFx::ASStringNode *v19; // rdx
  Scaleform::GFx::AS3::Class *Constructor; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace const > v21; // r8
  int v22; // eax
  Scaleform::GFx::ASStringNode *v23; // rcx
  Scaleform::GFx::ASString name; // [rsp+60h] [rbp+8h] BYREF
  Scaleform::GFx::ASString v26; // [rsp+68h] [rbp+10h] BYREF
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+18h] BYREF
  Scaleform::GFx::ASStringNode *v28; // [rsp+78h] [rbp+20h] BYREF

  pVM = this->pTraits.pObject->pVM;
  v5 = (Scaleform::GFx::ASString *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::ClassTraits::Traits *, Scaleform::GFx::ASStringNode **, _QWORD))elem->vfptr[1].Finalize_GC)(
                                     elem,
                                     &v28,
                                     0i64);
  v6 = Scaleform::GFx::AS3::Object::GetName(this, &result);
  v7 = Scaleform::GFx::ASString::operator+(v6, &v26, "$");
  Scaleform::GFx::ASString::operator+(v7, &name, v5);
  pNode = v26.pNode;
  v9 = v26.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v10 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  v11 = v28;
  v9 = v28->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  AppDomain = Scaleform::GFx::AS3::Traits::GetAppDomain(elem);
  RegisteredClassTraits = Scaleform::GFx::AS3::VM::GetRegisteredClassTraits(
                            pVM,
                            &name,
                            pVM->VectorNamespace.pObject,
                            AppDomain);
  if ( !RegisteredClassTraits )
  {
    v26.pNode = (Scaleform::GFx::ASStringNode *)pVM->MHeap;
    v15 = (Scaleform::GFx::ASStringNode *)(*((__int64 (__fastcall **)(__int64, __int64, _QWORD))v26.pNode->pData + 10))(
                                            v13,
                                            216i64,
                                            0i64);
    result.pNode = v15;
    if ( v15 )
    {
      Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_object::Vector_object(
        (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_object *)v15,
        pVM,
        &name,
        elem);
      RegisteredClassTraits = v16;
    }
    else
    {
      RegisteredClassTraits = 0i64;
    }
    result.pNode = (Scaleform::GFx::ASStringNode *)RegisteredClassTraits;
    v17 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,340>,Scaleform::ArrayDefaultPolicy> *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::ClassTraits::Traits *))elem->vfptr[2].~RefCountBaseGC<328>)(elem);
    if ( v17 )
    {
      v18 = v17 + 5;
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,340>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        v17 + 5,
        &v17[5],
        v17[5].Size + 1);
      v19 = (Scaleform::GFx::ASStringNode *)&v18->Data[v18->Size - 1];
      v26.pNode = v19;
      v28 = v19;
      if ( v19 )
      {
        v19->pData = (const char *)RegisteredClassTraits;
        if ( RegisteredClassTraits )
          *((_DWORD *)RegisteredClassTraits + 8) = (*((_DWORD *)RegisteredClassTraits + 8) + 1) & 0x8FBFFFFF;
      }
    }
    else
    {
      v26.pNode = 0i64;
      Constructor = Scaleform::GFx::AS3::Traits::GetConstructor(RegisteredClassTraits[25]);
      v21.pV = pVM->VectorNamespace.pObject;
      if ( v21.pV )
        v21.pV->RefCount = (v21.pV->RefCount + 1) & 0x8FBFFFFF;
      Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::AddFixedSlot(
        pVM->GlobalObject.pObject,
        Constructor,
        v21,
        (unsigned __int64 *)&v26);
    }
    Scaleform::GFx::AS3::VMAppDomain::AddClassTrait(
      AppDomain,
      &name,
      pVM->VectorNamespace.pObject,
      (Scaleform::GFx::AS3::ClassTraits::Traits *)RegisteredClassTraits);
    if ( RegisteredClassTraits )
    {
      if ( ((unsigned __int8)RegisteredClassTraits & 1) != 0 )
      {
        result.pNode = (Scaleform::GFx::ASStringNode *)((char *)RegisteredClassTraits - 1);
      }
      else
      {
        v22 = *((_DWORD *)RegisteredClassTraits + 8);
        if ( (v22 & 0x3FFFFF) != 0 )
        {
          *((_DWORD *)RegisteredClassTraits + 8) = v22 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)RegisteredClassTraits);
        }
      }
    }
  }
  v23 = name.pNode;
  v9 = name.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v23);
  return RegisteredClassTraits;
}

// File Line: 104
// RVA: 0x8B6810
Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_int *__fastcall Scaleform::GFx::AS3::Classes::fl_vec::Vector::ApplyTypeArgs(
        Scaleform::GFx::AS3::Classes::fl_vec::Vector *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Traits *pObject; // rax
  Scaleform::GFx::AS3::VM *pVM; // rbx
  Scaleform::GFx::AS3::VM::Error *v6; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  unsigned int v10; // ecx
  Scaleform::GFx::AS3::VM::Error *v11; // rax
  Scaleform::GFx::AS3::Class *VClass; // rax
  Scaleform::GFx::AS3::Traits *v13; // rdx
  Scaleform::GFx::AS3::VM::Error v14; // [rsp+28h] [rbp-20h] BYREF

  pObject = this->pTraits.pObject;
  pVM = pObject->pVM;
  if ( argc == 1 )
  {
    v10 = argv->Flags & 0x1F;
    if ( v10 != 13 )
    {
      if ( !v10 )
        goto LABEL_16;
      if ( v10 - 12 > 3 && v10 != 10 || argv->value.VS._1.VStr )
      {
        Scaleform::GFx::AS3::VM::Error::Error(&v14, 1107, pVM);
        Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v11);
        goto LABEL_3;
      }
    }
    if ( v10 - 12 > 3 && v10 != 10 || argv->value.VS._1.VStr )
    {
      VClass = argv->value.VS._1.VClass;
      goto LABEL_17;
    }
LABEL_16:
    VClass = Scaleform::GFx::AS3::Traits::GetConstructor(pVM->TraitsObject.pObject->ITraits.pObject);
LABEL_17:
    v13 = VClass->pTraits.pObject;
    switch ( v13->TraitsType )
    {
      case Traits_SInt:
        return pVM->TraitsVector_int.pObject;
      case Traits_UInt:
        return (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_int *)pVM->TraitsVector_uint.pObject;
      case Traits_Number:
        return (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_int *)pVM->TraitsVector_Number.pObject;
      case Traits_String:
        return (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_int *)pVM->TraitsVector_String.pObject;
    }
    return (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_int *)Scaleform::GFx::AS3::Classes::fl_vec::Vector::Resolve2Vector(
                                                                     this,
                                                                     (Scaleform::GFx::AS3::ClassTraits::Traits *)v13);
  }
  Scaleform::GFx::AS3::VM::Error::Error(&v14, 1128, pObject->pVM);
  Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v6);
LABEL_3:
  pNode = v14.Message.pNode;
  if ( v14.Message.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  return (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_int *)this->pTraits.pObject;
}

// File Line: 161
// RVA: 0x87C8B0
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector::MakeClassTraits(
        Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // rsi
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rdi
  Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> v7; // rbp
  Scaleform::GFx::AS3::InstanceTraits::fl::Object *v8; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rax
  Scaleform::GFx::AS3::Class *v11; // rdi

  MHeap = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::fl::Object *)MHeap->vfptr->Alloc(MHeap, 208ui64, 0i64);
  v6 = v5;
  v7.pV = 0i64;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::Object::Object(v5, vm, &Scaleform::GFx::AS3::fl_vec::VectorCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector::`vftable;
  }
  else
  {
    v6 = 0i64;
  }
  result->pV = v6;
  v8 = (Scaleform::GFx::AS3::InstanceTraits::fl::Object *)MHeap->vfptr->Alloc(MHeap, 240ui64, 0i64);
  if ( v8 )
  {
    Scaleform::GFx::AS3::InstanceTraits::fl::Object::Object(v8, vm, &Scaleform::GFx::AS3::fl_vec::VectorCI);
    v7.pV = v9;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(result->pV, v7);
  v10 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))MHeap->vfptr->Alloc)(
                                        MHeap,
                                        72i64);
  v11 = v10;
  if ( v10 )
  {
    Scaleform::GFx::AS3::Class::Class(v10, result->pV);
    v11->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_vec::Vector::`vftable;
  }
  return result;
}

