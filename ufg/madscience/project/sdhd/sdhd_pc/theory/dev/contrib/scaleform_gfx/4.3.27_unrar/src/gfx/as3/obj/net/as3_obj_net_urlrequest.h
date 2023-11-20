// File Line: 223
// RVA: 0x854410
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::Instances::fl_net::URLRequest::methodGet(Scaleform::GFx::AS3::Instances::fl_net::URLRequest *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *v2; // rdi
  Scaleform::GFx::AS3::Instances::fl_net::URLRequest *v3; // rbx
  Scaleform::GFx::ASStringNode *v4; // rbx
  Scaleform::GFx::ASStringNode *v5; // rcx
  bool v6; // zf

  v2 = result;
  v3 = this;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)this->pTraits.pObject->pVM->StringManagerRef->Builtins,
    result);
  v4 = v3->Method.pNode;
  ++v4->RefCount;
  v5 = v2->pNode;
  v6 = v2->pNode->RefCount == 1;
  --v5->RefCount;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  v2->pNode = v4;
  return v2;
}

// File Line: 238
// RVA: 0x86BA30
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::Instances::fl_net::URLRequest::urlGet(Scaleform::GFx::AS3::Instances::fl_net::URLRequest *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *v2; // rdi
  Scaleform::GFx::AS3::Instances::fl_net::URLRequest *v3; // rbx
  Scaleform::GFx::ASStringNode *v4; // rbx
  Scaleform::GFx::ASStringNode *v5; // rcx
  bool v6; // zf

  v2 = result;
  v3 = this;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)this->pTraits.pObject->pVM->StringManagerRef->Builtins,
    result);
  v4 = v3->Url.pNode;
  ++v4->RefCount;
  v5 = v2->pNode;
  v6 = v2->pNode->RefCount == 1;
  --v5->RefCount;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  v2->pNode = v4;
  return v2;
}

// File Line: 296
// RVA: 0x7FDE50
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_net::URLRequest> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_net::URLRequest::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_net::URLRequest> *result, Scaleform::GFx::AS3::InstanceTraits::fl_net::URLRequest *t)
{
  Scaleform::GFx::AS3::InstanceTraits::fl_net::URLRequest *v2; // rdi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_net::URLRequest> *v3; // rbx
  Scaleform::GFx::AS3::Instances::fl_net::URLRequest *v4; // rax
  int v6; // [rsp+40h] [rbp+8h]
  Scaleform::GFx::AS3::Instances::fl_net::URLRequest *v7; // [rsp+48h] [rbp+10h]
  Scaleform::GFx::AS3::Instances::fl_net::URLRequest *v8; // [rsp+50h] [rbp+18h]

  v2 = t;
  v3 = result;
  v6 = 337;
  v4 = (Scaleform::GFx::AS3::Instances::fl_net::URLRequest *)t->pVM->MHeap->vfptr->Alloc(
                                                               t->pVM->MHeap,
                                                               t->MemSize,
                                                               (Scaleform::AllocInfo *)&v6);
  v7 = v4;
  v8 = v4;
  if ( v4 )
    Scaleform::GFx::AS3::Instances::fl_net::URLRequest::URLRequest(
      v4,
      (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v2->vfptr);
  v3->pV = v4;
  return v3;
}

