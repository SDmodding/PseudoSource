// File Line: 128
// RVA: 0x8EAAA0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_xml::XMLNode> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_xml::XMLNode::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_xml::XMLNode> *result, Scaleform::GFx::AS3::InstanceTraits::fl_xml::XMLNode *t)
{
  Scaleform::GFx::AS3::InstanceTraits::fl_xml::XMLNode *v2; // rdi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_xml::XMLNode> *v3; // rbx
  Scaleform::GFx::AS3::Instances::fl_xml::XMLNode *v4; // rax

  v2 = t;
  v3 = result;
  v4 = (Scaleform::GFx::AS3::Instances::fl_xml::XMLNode *)Scaleform::GFx::AS3::Traits::Alloc((Scaleform::GFx::AS3::Traits *)&t->vfptr);
  if ( v4 )
    Scaleform::GFx::AS3::Instances::fl_xml::XMLNode::XMLNode(
      v4,
      (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v2->vfptr);
  v3->pV = v4;
  return v3;
}

