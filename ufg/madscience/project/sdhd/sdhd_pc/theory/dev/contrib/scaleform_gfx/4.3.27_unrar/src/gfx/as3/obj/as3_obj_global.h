// File Line: 182
// RVA: 0x7AC9D0
Scaleform::GFx::AS3::SlotInfo *__fastcall Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::AddFixedSlot(Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *this, Scaleform::GFx::AS3::Class *cl, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace const > ns, unsigned __int64 *index)
{
  unsigned __int64 *v4; // rdi
  Scaleform::GFx::AS3::Class *v5; // rbx
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *v6; // rsi
  Scaleform::GFx::ASString *v7; // rax
  Scaleform::GFx::AS3::SlotInfo *v8; // rbx
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::AS3::Value v; // [rsp+38h] [rbp-30h]
  Scaleform::GFx::ASString result; // [rsp+78h] [rbp+10h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace const > nsa; // [rsp+80h] [rbp+18h]

  nsa.pV = ns.pV;
  v4 = index;
  v5 = cl;
  v6 = this;
  v.Flags = 13;
  v.Bonus.pWeakProxy = 0i64;
  *(_QWORD *)&v.value.VNumber = cl;
  if ( cl )
    cl->RefCount = (cl->RefCount + 1) & 0x8FBFFFFF;
  v7 = Scaleform::GFx::AS3::Object::GetName((Scaleform::GFx::AS3::Object *)&cl->vfptr, &result);
  v8 = Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::AddFixedSlotValuePair(
         v6,
         v7,
         nsa,
         (Scaleform::GFx::AS3::ClassTraits::Traits *)v5->pTraits.pObject,
         &v,
         v4);
  v9 = result.pNode;
  v10 = result.pNode->RefCount == 1;
  --v9->RefCount;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
  return v8;
}

