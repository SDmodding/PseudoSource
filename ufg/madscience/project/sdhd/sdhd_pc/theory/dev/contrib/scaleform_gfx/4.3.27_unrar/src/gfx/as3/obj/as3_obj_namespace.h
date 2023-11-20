// File Line: 115
// RVA: 0x81EF20
void __fastcall Scaleform::GFx::AS3::Instances::fl::Namespace::SetUri(Scaleform::GFx::AS3::Instances::fl::Namespace *this, Scaleform::GFx::ASString *value)
{
  Scaleform::GFx::ASStringNode *v2; // rbx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v3; // rdi
  Scaleform::GFx::ASStringNode *v4; // rcx
  bool v5; // zf

  v2 = value->pNode;
  v3 = this;
  ++v2->RefCount;
  v4 = this->Uri.pNode;
  v5 = v4->RefCount-- == 1;
  if ( v5 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  v3->Uri.pNode = v2;
}

// File Line: 226
// RVA: 0x7FCCC0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::MakeInstance(Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *this, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *result, Scaleform::GFx::AS3::Abc::NamespaceKind kind, Scaleform::GFx::ASString *uri, Scaleform::GFx::AS3::Value *prefix)
{
  Scaleform::GFx::ASString *v5; // rsi
  Scaleform::GFx::AS3::Abc::NamespaceKind v6; // ebp
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *v7; // rbx
  Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *v8; // rdi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v9; // rax
  int v11; // [rsp+68h] [rbp+10h]

  v5 = uri;
  v6 = kind;
  v7 = result;
  v8 = this;
  v11 = 328;
  v9 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                          Scaleform::Memory::pGlobalHeap,
                                                          this,
                                                          104ui64,
                                                          (Scaleform::AllocInfo *)&v11);
  if ( v9 )
    Scaleform::GFx::AS3::Instances::fl::Namespace::Namespace(v9, v8->pVM, v8->pNamespaceFactory.pObject, v6, v5, prefix);
  v7->pV = v9;
  return v7;
}

