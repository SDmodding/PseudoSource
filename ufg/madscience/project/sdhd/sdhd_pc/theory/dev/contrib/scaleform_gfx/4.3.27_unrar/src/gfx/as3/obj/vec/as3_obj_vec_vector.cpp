// File Line: 53
// RVA: 0x903700
Scaleform::GFx::AS3::ClassTraits::Traits **__fastcall Scaleform::GFx::AS3::Classes::fl_vec::Vector::Resolve2Vector(Scaleform::GFx::AS3::Classes::fl_vec::Vector *this, Scaleform::GFx::AS3::ClassTraits::Traits *elem)
{
  Scaleform::GFx::AS3::ClassTraits::Traits *v2; // r14
  Scaleform::GFx::AS3::Classes::fl_vec::Vector *v3; // rbx
  Scaleform::GFx::AS3::VM *v4; // rsi
  Scaleform::GFx::ASString *v5; // rdi
  Scaleform::GFx::ASString *v6; // rax
  Scaleform::GFx::ASString *v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::ASStringNode *v10; // rcx
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::GFx::AS3::VMAppDomain *v12; // rbp
  __int64 v13; // rcx
  Scaleform::GFx::AS3::ClassTraits::Traits **v14; // rdi
  Scaleform::GFx::ASStringNode *v15; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits **v16; // rax
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,340>,Scaleform::ArrayDefaultPolicy> *v17; // rax
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,340>,Scaleform::ArrayDefaultPolicy> *v18; // rbx
  Scaleform::GFx::ASStringNode *v19; // rdx
  Scaleform::GFx::AS3::Class *v20; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace const > v21; // r8
  int v22; // eax
  Scaleform::GFx::ASStringNode *v23; // rcx
  Scaleform::GFx::ASString name; // [rsp+60h] [rbp+8h]
  Scaleform::GFx::ASString v26; // [rsp+68h] [rbp+10h]
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+18h]
  Scaleform::GFx::ASStringNode *v28; // [rsp+78h] [rbp+20h]

  v2 = elem;
  v3 = this;
  v4 = this->pTraits.pObject->pVM;
  v5 = (Scaleform::GFx::ASString *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::ClassTraits::Traits *, Scaleform::GFx::ASStringNode **, _QWORD))elem->vfptr[1].Finalize_GC)(
                                     elem,
                                     &v28,
                                     0i64);
  v6 = Scaleform::GFx::AS3::Object::GetName((Scaleform::GFx::AS3::Object *)&v3->vfptr, &result);
  v7 = Scaleform::GFx::ASString::operator+(v6, &v26, "$");
  Scaleform::GFx::ASString::operator+(v7, &name, v5);
  v8 = v26.pNode;
  v9 = v26.pNode->RefCount == 1;
  --v8->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  v10 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v10->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  v11 = v28;
  v9 = v28->RefCount == 1;
  --v11->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  v12 = Scaleform::GFx::AS3::Traits::GetAppDomain((Scaleform::GFx::AS3::Traits *)&v2->vfptr);
  v14 = Scaleform::GFx::AS3::VM::GetRegisteredClassTraits(v4, &name, v4->VectorNamespace.pObject, v12);
  if ( !v14 )
  {
    v26.pNode = (Scaleform::GFx::ASStringNode *)v4->MHeap;
    v15 = (Scaleform::GFx::ASStringNode *)(*((__int64 (__fastcall **)(__int64, signed __int64, _QWORD))v26.pNode->pData
                                           + 10))(
                                            v13,
                                            216i64,
                                            0i64);
    result.pNode = v15;
    if ( v15 )
    {
      Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_object::Vector_object(
        (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_object *)v15,
        v4,
        &name,
        v2);
      v14 = v16;
    }
    else
    {
      v14 = 0i64;
    }
    result.pNode = (Scaleform::GFx::ASStringNode *)v14;
    v17 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,340>,Scaleform::ArrayDefaultPolicy> *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::ClassTraits::Traits *))v2->vfptr[2].~RefCountBaseGC<328>)(v2);
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
        v19->pData = (const char *)v14;
        if ( v14 )
          *((_DWORD *)v14 + 8) = (*((_DWORD *)v14 + 8) + 1) & 0x8FBFFFFF;
      }
    }
    else
    {
      v26.pNode = 0i64;
      v20 = Scaleform::GFx::AS3::Traits::GetConstructor((Scaleform::GFx::AS3::Traits *)&v14[25]->vfptr);
      v21.pV = v4->VectorNamespace.pObject;
      if ( v21.pV )
        v21.pV->RefCount = (v21.pV->RefCount + 1) & 0x8FBFFFFF;
      Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::AddFixedSlot(
        v4->GlobalObject.pObject,
        v20,
        v21,
        (unsigned __int64 *)&v26);
    }
    Scaleform::GFx::AS3::VMAppDomain::AddClassTrait(
      v12,
      &name,
      v4->VectorNamespace.pObject,
      (Scaleform::GFx::AS3::ClassTraits::Traits *)v14);
    if ( v14 )
    {
      if ( (unsigned __int8)v14 & 1 )
      {
        result.pNode = (Scaleform::GFx::ASStringNode *)((char *)v14 - 1);
      }
      else
      {
        v22 = *((_DWORD *)v14 + 8);
        if ( v22 & 0x3FFFFF )
        {
          *((_DWORD *)v14 + 8) = v22 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v14);
        }
      }
    }
  }
  v23 = name.pNode;
  v9 = name.pNode->RefCount == 1;
  --v23->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v23);
  return v14;
}

// File Line: 104
// RVA: 0x8B6810
Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_int *__fastcall Scaleform::GFx::AS3::Classes::fl_vec::Vector::ApplyTypeArgs(Scaleform::GFx::AS3::Classes::fl_vec::Vector *this, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Classes::fl_vec::Vector *v3; // rdi
  Scaleform::GFx::AS3::Traits *v4; // rax
  Scaleform::GFx::AS3::VM *v5; // rbx
  Scaleform::GFx::AS3::VM::Error *v6; // rax
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  unsigned int v10; // ecx
  Scaleform::GFx::AS3::VM::Error *v11; // rax
  long double v12; // rax
  __int64 v13; // rdx
  Scaleform::GFx::AS3::VM::Error v14; // [rsp+28h] [rbp-20h]

  v3 = this;
  v4 = this->pTraits.pObject;
  v5 = v4->pVM;
  if ( argc == 1 )
  {
    v10 = argv->Flags & 0x1F;
    if ( v10 != 13 )
    {
      if ( !v10 )
        goto LABEL_17;
      if ( v10 - 12 > 3 && v10 != 10 || *(_QWORD *)&argv->value.VNumber )
      {
        Scaleform::GFx::AS3::VM::Error::Error(&v14, eCorruptABCError, v5);
        Scaleform::GFx::AS3::VM::ThrowTypeError(v5, v11);
        goto LABEL_3;
      }
    }
    if ( v10 && (v10 - 12 > 3 && v10 != 10 || *(_QWORD *)&argv->value.VNumber) )
    {
      v12 = argv->value.VNumber;
      goto LABEL_18;
    }
LABEL_17:
    v12 = COERCE_DOUBLE(Scaleform::GFx::AS3::Traits::GetConstructor((Scaleform::GFx::AS3::Traits *)&v5->TraitsObject.pObject->ITraits.pObject->vfptr));
LABEL_18:
    v13 = *(_QWORD *)(*(_QWORD *)&v12 + 40i64);
    switch ( *(_DWORD *)(v13 + 120) )
    {
      case 2:
        return v5->TraitsVector_int.pObject;
      case 3:
        return (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_int *)v5->TraitsVector_uint.pObject;
      case 4:
        return (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_int *)v5->TraitsVector_Number.pObject;
      case 5:
        return (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_int *)v5->TraitsVector_String.pObject;
    }
    return (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_int *)Scaleform::GFx::AS3::Classes::fl_vec::Vector::Resolve2Vector(
                                                                     v3,
                                                                     (Scaleform::GFx::AS3::ClassTraits::Traits *)v13);
  }
  Scaleform::GFx::AS3::VM::Error::Error(&v14, eWrongTypeArgCountError, v4->pVM);
  Scaleform::GFx::AS3::VM::ThrowTypeError(v5, v6);
LABEL_3:
  v7 = v14.Message.pNode;
  v8 = v14.Message.pNode->RefCount == 1;
  --v7->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  return (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_int *)v3->pTraits.pObject;
}

// File Line: 161
// RVA: 0x87C8B0
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // r14
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v3; // rbx
  Scaleform::MemoryHeap *v4; // rsi
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v6; // rdi
  Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> v7; // rbp
  Scaleform::GFx::AS3::InstanceTraits::fl::Object *v8; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rax
  Scaleform::GFx::AS3::Class *v11; // rdi

  v2 = vm;
  v3 = result;
  v4 = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::fl::Object *)v4->vfptr->Alloc(v4, 208ui64, 0i64);
  v6 = v5;
  v7.pV = 0i64;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::Object::Object(v5, v2, &Scaleform::GFx::AS3::fl_vec::VectorCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector::`vftable';
  }
  else
  {
    v6 = 0i64;
  }
  v3->pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)&v6->vfptr;
  v8 = (Scaleform::GFx::AS3::InstanceTraits::fl::Object *)v4->vfptr->Alloc(v4, 240ui64, 0i64);
  if ( v8 )
  {
    Scaleform::GFx::AS3::InstanceTraits::fl::Object::Object(v8, v2, &Scaleform::GFx::AS3::fl_vec::VectorCI);
    v7.pV = v9;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(v3->pV, v7);
  v10 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v4->vfptr->Alloc)(
                                        v4,
                                        72i64);
  v11 = v10;
  if ( v10 )
  {
    Scaleform::GFx::AS3::Class::Class(v10, v3->pV);
    v11->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_vec::Vector::`vftable';
  }
  return v3;
}

