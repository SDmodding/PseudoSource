// File Line: 120
// RVA: 0x8EAA10
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_xml::XMLDocument> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_xml::XMLDocument::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_xml::XMLDocument> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_xml::XMLDocument *t)
{
  Scaleform::GFx::AS3::Instances::fl_xml::XMLNode *v4; // rax
  Scaleform::GFx::AS3::Instances::fl_xml::XMLDocument *v5; // rbx

  v4 = (Scaleform::GFx::AS3::Instances::fl_xml::XMLNode *)Scaleform::GFx::AS3::Traits::Alloc(t);
  v5 = (Scaleform::GFx::AS3::Instances::fl_xml::XMLDocument *)v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instances::fl_xml::XMLNode::XMLNode(v4, t);
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_xml::XMLDocument::`vftable;
    v5->docTypeDecl.pObject = 0i64;
    v5->idMap.pObject = 0i64;
    v5->ignoreWhite = 0;
    v5->xmlDecl.pObject = 0i64;
  }
  else
  {
    v5 = 0i64;
  }
  result->pV = v5;
  return result;
}

