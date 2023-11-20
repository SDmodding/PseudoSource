// File Line: 45
// RVA: 0x89F930
void __fastcall Scaleform::GFx::AS3::Instances::fl_xml::XMLNode::XMLNode(Scaleform::GFx::AS3::Instances::fl_xml::XMLNode *this, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Instances::fl_xml::XMLNode *v2; // rbx

  v2 = this;
  Scaleform::GFx::AS3::Instances::fl::Object::Object((Scaleform::GFx::AS3::Instances::fl::Object *)&this->vfptr, t);
  v2->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_xml::XMLNode::`vftable';
  v2->firstChild.pObject = 0i64;
  v2->lastChild.pObject = 0i64;
  v2->nextSibling.pObject = 0i64;
  Scaleform::GFx::AS3::DefaultValue<Scaleform::GFx::ASString const &>(
    &v2->nodeName,
    v2->pTraits.pObject->pVM->StringManagerRef);
  v2->nodeType = 0;
  Scaleform::GFx::AS3::DefaultValue<Scaleform::GFx::ASString const &>(
    &v2->nodeValue,
    v2->pTraits.pObject->pVM->StringManagerRef);
  v2->parentNode.pObject = 0i64;
  v2->previousSibling.pObject = 0i64;
}

// File Line: 114
// RVA: 0x8EB210
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_xml::XMLNode::MakeObject(Scaleform::GFx::AS3::InstanceTraits::fl_xml::XMLNode *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::Object **v4; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_xml::XMLNode> resulta; // [rsp+48h] [rbp+20h]

  v3 = result;
  v4 = (Scaleform::GFx::AS3::Object **)Scaleform::GFx::AS3::InstanceTraits::fl_xml::XMLNode::MakeInstance(
                                         &resulta,
                                         (Scaleform::GFx::AS3::InstanceTraits::fl_xml::XMLNode *)t);
  Scaleform::GFx::AS3::Value::Pick(v3, *v4);
}

// File Line: 136
// RVA: 0x875EE0
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_xml::XMLNode::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // rbp
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v3; // rbx
  Scaleform::MemoryHeap *v4; // rsi
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v6; // rdi
  Scaleform::GFx::AS3::InstanceTraits::fl::Object *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::fl::Object *v8; // rdi
  Scaleform::GFx::AS3::Class *v9; // rax

  v2 = vm;
  v3 = result;
  v4 = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::fl::Object *)v4->vfptr->Alloc(v4, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::Object::Object(v5, v2, &Scaleform::GFx::AS3::fl_xml::XMLNodeCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_xml::XMLNode::`vftable';
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
    Scaleform::GFx::AS3::InstanceTraits::fl::Object::Object(v7, v2, &Scaleform::GFx::AS3::fl_xml::XMLNodeCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_xml::XMLNode::`vftable';
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
  if ( v9 )
    Scaleform::GFx::AS3::Class::Class(v9, v3->pV);
  return v3;
}

