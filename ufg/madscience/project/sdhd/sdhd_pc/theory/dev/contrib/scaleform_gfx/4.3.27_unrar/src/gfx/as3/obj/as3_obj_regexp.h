// File Line: 142
// RVA: 0x85F800
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::Instances::fl::RegExp::sourceGet(
        Scaleform::GFx::AS3::Instances::fl::RegExp *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::VM::Error *v4; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v8; // [rsp+30h] [rbp-18h] BYREF

  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    this->pTraits.pObject->pVM->StringManagerRef,
    result);
  Scaleform::GFx::AS3::VM::Error::Error(&v8, 1001, this->pTraits.pObject->pVM);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(this->pTraits.pObject->pVM, v4, &Scaleform::GFx::AS3::fl::ErrorTI);
  pNode = v8.Message.pNode;
  if ( v8.Message.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  return result;
}

// File Line: 188
// RVA: 0x79DB20
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> *__fastcall Scaleform::GFx::AS3::Instances::fl::RegExp::AS3exec(
        Scaleform::GFx::AS3::Instances::fl::RegExp *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> *result,
        Scaleform::GFx::ASString *s)
{
  Scaleform::GFx::AS3::Instances::fl::Object *pObject; // rcx
  unsigned int RefCount; // eax

  result->pObject = 0i64;
  pObject = result->pObject;
  if ( !result->pObject )
    return result;
  if ( ((unsigned __int8)pObject & 1) != 0 )
  {
    result->pObject = (Scaleform::GFx::AS3::Instances::fl::Object *)((char *)pObject - 1);
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
  result->pObject = 0i64;
  return result;
}

// File Line: 235
// RVA: 0x7FD400
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::RegExp> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl::RegExp::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::RegExp> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl::RegExp *t)
{
  Scaleform::GFx::AS3::Instance *v4; // rax
  Scaleform::GFx::AS3::Instances::fl::RegExp *v5; // rbx
  int v7; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::Instance *v8; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::AS3::Instance *v9; // [rsp+60h] [rbp+18h]

  v7 = 337;
  v4 = (Scaleform::GFx::AS3::Instance *)t->pVM->MHeap->vfptr->Alloc(t->pVM->MHeap, t->MemSize, &v7);
  v5 = (Scaleform::GFx::AS3::Instances::fl::RegExp *)v4;
  v8 = v4;
  v9 = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instance::Instance(v4, t);
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable;
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::RegExp::`vftable;
  }
  else
  {
    v5 = 0i64;
  }
  result->pV = v5;
  return result;
}

