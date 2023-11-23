// File Line: 45
// RVA: 0x89F930
void __fastcall Scaleform::GFx::AS3::Instances::fl_xml::XMLNode::XMLNode(
        Scaleform::GFx::AS3::Instances::fl_xml::XMLNode *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Instances::fl::Object::Object(this, t);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_xml::XMLNode::`vftable;
  this->firstChild.pObject = 0i64;
  this->lastChild.pObject = 0i64;
  this->nextSibling.pObject = 0i64;
  Scaleform::GFx::AS3::DefaultValue<Scaleform::GFx::ASString const &>(
    &this->nodeName,
    this->pTraits.pObject->pVM->StringManagerRef);
  this->nodeType = 0;
  Scaleform::GFx::AS3::DefaultValue<Scaleform::GFx::ASString const &>(
    &this->nodeValue,
    this->pTraits.pObject->pVM->StringManagerRef);
  this->parentNode.pObject = 0i64;
  this->previousSibling.pObject = 0i64;
}

// File Line: 114
// RVA: 0x8EB210
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_xml::XMLNode::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_xml::XMLNode *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_xml::XMLNode *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_xml::XMLNode> *Instance; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_xml::XMLNode> resulta; // [rsp+48h] [rbp+20h] BYREF

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_xml::XMLNode::MakeInstance(&resulta, t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}

// File Line: 136
// RVA: 0x875EE0
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_xml::XMLNode::MakeClassTraits(
        Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // rsi
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rdi
  Scaleform::GFx::AS3::InstanceTraits::fl::Object *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::fl::Object *v8; // rdi
  Scaleform::GFx::AS3::Class *v9; // rax

  MHeap = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::fl::Object *)MHeap->vfptr->Alloc(MHeap, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::Object::Object(v5, vm, &Scaleform::GFx::AS3::fl_xml::XMLNodeCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_xml::XMLNode::`vftable;
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
    Scaleform::GFx::AS3::InstanceTraits::fl::Object::Object(v7, vm, &Scaleform::GFx::AS3::fl_xml::XMLNodeCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_xml::XMLNode::`vftable;
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
  if ( v9 )
    Scaleform::GFx::AS3::Class::Class(v9, result->pV);
  return result;
}

