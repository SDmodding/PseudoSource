// File Line: 511
// RVA: 0x8AFBF0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::Instances::fl::XML::AS3toXMLString(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    this->pTraits.pObject->pVM->StringManagerRef,
    result);
  Scaleform::GFx::AS3::Instances::fl::XML::AS3toXMLString(this, result);
  return result;
}

// File Line: 550
// RVA: 0x7FE0C0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl::XML *t)
{
  Scaleform::GFx::AS3::Instance *v4; // rax
  Scaleform::GFx::AS3::Instances::fl::XML *v5; // rbx
  int v7; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::Instance *v8; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::AS3::Instance *v9; // [rsp+60h] [rbp+18h]

  v7 = 337;
  v4 = (Scaleform::GFx::AS3::Instance *)t->pVM->MHeap->vfptr->Alloc(t->pVM->MHeap, t->MemSize, &v7);
  v5 = (Scaleform::GFx::AS3::Instances::fl::XML *)v4;
  v8 = v4;
  v9 = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instance::Instance(v4, t);
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable;
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::XML::`vftable;
    Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
      t->pVM->StringManagerRef,
      &v5->Text);
    v5->Parent.pObject = 0i64;
  }
  else
  {
    v5 = 0i64;
  }
  result->pV = v5;
  return result;
}

// File Line: 787
// RVA: 0x789CB0
void __fastcall Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack::~CallBack(
        Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack *this)
{
  this->vfptr = (Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBackVtbl *)&Scaleform::GFx::AS3::Instances::fl::XMLElement::CallBack::`vftable;
}

