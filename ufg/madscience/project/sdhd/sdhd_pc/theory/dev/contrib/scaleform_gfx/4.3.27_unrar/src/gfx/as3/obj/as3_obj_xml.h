// File Line: 511
// RVA: 0x8AFBF0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3toXMLString(Scaleform::GFx::AS3::Instances::fl::XML *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *v2; // rdi
  Scaleform::GFx::AS3::Instances::fl::XML *v3; // rbx

  v2 = result;
  v3 = this;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)this->pTraits.pObject->pVM->StringManagerRef->Builtins,
    result);
  Scaleform::GFx::AS3::Instances::fl::XML::AS3toXMLString(v3, v2);
  return v2;
}

// File Line: 550
// RVA: 0x7FE0C0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *result, Scaleform::GFx::AS3::InstanceTraits::fl::XML *t)
{
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *v2; // rsi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *v3; // rdi
  Scaleform::GFx::AS3::Instance *v4; // rax
  Scaleform::GFx::ASString *v5; // rbx
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
  v5 = (Scaleform::GFx::ASString *)v4;
  v8 = v4;
  v9 = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instance::Instance(v4, (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v2->vfptr);
    v5->pNode = (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable;
    v5->pNode = (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::Instances::fl::XML::`vftable;
    Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
      (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v2->pVM->StringManagerRef->Builtins,
      v5 + 7);
    v5[8].pNode = 0i64;
  }
  else
  {
    v5 = 0i64;
  }
  v3->pV = (Scaleform::GFx::AS3::Instances::fl::XML *)v5;
  return v3;
}

// File Line: 787
// RVA: 0x789CB0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack::~CallBack(Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack *this)
{
  this->vfptr = (Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBackVtbl *)&Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack::`vftable;
}

