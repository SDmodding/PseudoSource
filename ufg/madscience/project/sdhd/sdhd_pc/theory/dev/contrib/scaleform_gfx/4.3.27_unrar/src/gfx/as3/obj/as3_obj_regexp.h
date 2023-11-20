// File Line: 142
// RVA: 0x85F800
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::Instances::fl::RegExp::sourceGet(Scaleform::GFx::AS3::Instances::fl::RegExp *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *v2; // rdi
  Scaleform::GFx::AS3::Instances::fl::RegExp *v3; // rbx
  Scaleform::GFx::AS3::VM::Error *v4; // rax
  Scaleform::GFx::ASStringNode *v5; // rcx
  bool v6; // zf
  Scaleform::GFx::AS3::VM::Error v8; // [rsp+30h] [rbp-18h]

  v2 = result;
  v3 = this;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)this->pTraits.pObject->pVM->StringManagerRef->Builtins,
    result);
  Scaleform::GFx::AS3::VM::Error::Error(&v8, eNotImplementedError, v3->pTraits.pObject->pVM);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(v3->pTraits.pObject->pVM, v4, &Scaleform::GFx::AS3::fl::ErrorTI);
  v5 = v8.Message.pNode;
  v6 = v8.Message.pNode->RefCount == 1;
  --v5->RefCount;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  return v2;
}

// File Line: 188
// RVA: 0x79DB20
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> *__fastcall Scaleform::GFx::AS3::Instances::fl::RegExp::AS3exec(Scaleform::GFx::AS3::Instances::fl::RegExp *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> *result, Scaleform::GFx::ASString *s)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> *v3; // rbx
  Scaleform::GFx::AS3::Instances::fl::Object *v4; // rcx
  unsigned int v5; // eax

  v3 = result;
  result->pObject = 0i64;
  v4 = result->pObject;
  if ( !result->pObject )
    return result;
  if ( (unsigned __int8)v4 & 1 )
  {
    result->pObject = (Scaleform::GFx::AS3::Instances::fl::Object *)((char *)v4 - 1);
  }
  else
  {
    v5 = v4->RefCount;
    if ( v5 & 0x3FFFFF )
    {
      v4->RefCount = v5 - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v4->vfptr);
    }
  }
  v3->pObject = 0i64;
  return v3;
}

// File Line: 235
// RVA: 0x7FD400
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::RegExp> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl::RegExp::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::RegExp> *result, Scaleform::GFx::AS3::InstanceTraits::fl::RegExp *t)
{
  Scaleform::GFx::AS3::InstanceTraits::fl::RegExp *v2; // rsi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::RegExp> *v3; // rdi
  Scaleform::GFx::AS3::Instance *v4; // rax
  Scaleform::GFx::AS3::Instances::fl::RegExp *v5; // rbx
  int v7; // [rsp+50h] [rbp+8h]
  Scaleform::GFx::AS3::Instance *v8; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::AS3::Instance *v9; // [rsp+60h] [rbp+18h]

  v2 = t;
  v3 = result;
  v7 = 337;
  v4 = (Scaleform::GFx::AS3::Instance *)t->pVM->MHeap->vfptr->Alloc(
                                          t->pVM->MHeap,
                                          t->MemSize,
                                          (Scaleform::AllocInfo *)&v7);
  v5 = (Scaleform::GFx::AS3::Instances::fl::RegExp *)v4;
  v8 = v4;
  v9 = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instance::Instance(v4, (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v2->vfptr);
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable;
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::RegExp::`vftable;
  }
  else
  {
    v5 = 0i64;
  }
  v3->pV = v5;
  return v3;
}

