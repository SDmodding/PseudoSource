// File Line: 115
// RVA: 0x81EF20
void __fastcall Scaleform::GFx::AS3::Instances::fl::Namespace::SetUri(
        Scaleform::GFx::AS3::Instances::fl::Namespace *this,
        Scaleform::GFx::ASString *value)
{
  Scaleform::GFx::ASStringNode *pNode; // rbx
  Scaleform::GFx::ASStringNode *v4; // rcx

  pNode = value->pNode;
  ++value->pNode->RefCount;
  v4 = this->Uri.pNode;
  if ( v4->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  this->Uri.pNode = pNode;
}

// File Line: 226
// RVA: 0x7FCCC0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::MakeInstance(
        Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *result,
        Scaleform::GFx::AS3::Abc::NamespaceKind kind,
        Scaleform::GFx::ASString *uri,
        Scaleform::GFx::AS3::Value *prefix)
{
  Scaleform::GFx::AS3::Instances::fl::Namespace *v9; // rax
  int v11; // [rsp+68h] [rbp+10h] BYREF

  v11 = 328;
  v9 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                          Scaleform::Memory::pGlobalHeap,
                                                          this,
                                                          104i64,
                                                          &v11);
  if ( v9 )
    Scaleform::GFx::AS3::Instances::fl::Namespace::Namespace(
      v9,
      this->pVM,
      (Scaleform::GFx::Resource *)this->pNamespaceFactory.pObject,
      kind,
      uri,
      prefix);
  result->pV = v9;
  return result;
}

