// File Line: 182
// RVA: 0x7AC9D0
Scaleform::GFx::AS3::SlotInfo *__fastcall Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::AddFixedSlot(
        Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *this,
        Scaleform::GFx::AS3::Class *cl,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace const > ns,
        unsigned __int64 *index)
{
  Scaleform::GFx::ASString *Name; // rax
  Scaleform::GFx::AS3::SlotInfo *v8; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::Value v; // [rsp+38h] [rbp-30h] BYREF
  Scaleform::GFx::ASString result; // [rsp+78h] [rbp+10h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace const > nsa; // [rsp+80h] [rbp+18h]

  nsa.pV = ns.pV;
  v.Flags = 13;
  v.Bonus.pWeakProxy = 0i64;
  v.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)cl;
  if ( cl )
    cl->RefCount = (cl->RefCount + 1) & 0x8FBFFFFF;
  Name = Scaleform::GFx::AS3::Object::GetName(cl, &result);
  v8 = Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::AddFixedSlotValuePair(
         this,
         Name,
         nsa,
         (Scaleform::GFx::AS3::ClassTraits::Traits *)cl->pTraits.pObject,
         &v,
         index);
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
  return v8;
}

