// File Line: 223
// RVA: 0x854410
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::Instances::fl_net::URLRequest::methodGet(
        Scaleform::GFx::AS3::Instances::fl_net::URLRequest *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASStringNode *pNode; // rbx
  Scaleform::GFx::ASStringNode *v5; // rcx

  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    this->pTraits.pObject->pVM->StringManagerRef,
    result);
  pNode = this->Method.pNode;
  ++pNode->RefCount;
  v5 = result->pNode;
  if ( result->pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  result->pNode = pNode;
  return result;
}

// File Line: 238
// RVA: 0x86BA30
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::Instances::fl_net::URLRequest::urlGet(
        Scaleform::GFx::AS3::Instances::fl_net::URLRequest *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASStringNode *pNode; // rbx
  Scaleform::GFx::ASStringNode *v5; // rcx

  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    this->pTraits.pObject->pVM->StringManagerRef,
    result);
  pNode = this->Url.pNode;
  ++pNode->RefCount;
  v5 = result->pNode;
  if ( result->pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  result->pNode = pNode;
  return result;
}

// File Line: 296
// RVA: 0x7FDE50
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_net::URLRequest> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_net::URLRequest::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_net::URLRequest> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_net::URLRequest *t)
{
  Scaleform::GFx::AS3::Instances::fl_net::URLRequest *v4; // rax
  int v6; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::Instances::fl_net::URLRequest *v7; // [rsp+48h] [rbp+10h]
  Scaleform::GFx::AS3::Instances::fl_net::URLRequest *v8; // [rsp+50h] [rbp+18h]

  v6 = 337;
  v4 = (Scaleform::GFx::AS3::Instances::fl_net::URLRequest *)t->pVM->MHeap->vfptr->Alloc(t->pVM->MHeap, t->MemSize, &v6);
  v7 = v4;
  v8 = v4;
  if ( v4 )
    Scaleform::GFx::AS3::Instances::fl_net::URLRequest::URLRequest(v4, t);
  result->pV = v4;
  return result;
}

