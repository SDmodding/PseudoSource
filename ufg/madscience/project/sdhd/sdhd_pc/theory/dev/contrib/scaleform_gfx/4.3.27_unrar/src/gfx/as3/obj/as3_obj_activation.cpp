// File Line: 34
// RVA: 0x77A920
void __fastcall Scaleform::GFx::AS3::InstanceTraits::Activation::Activation(
        Scaleform::GFx::AS3::InstanceTraits::Activation *this,
        Scaleform::GFx::AS3::VMAbcFile *file,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Abc::MethodBodyInfo *mbi)
{
  Scaleform::GFx::ASString *v8; // r15
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rax
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::GFx::ASString result; // [rsp+80h] [rbp+18h] BYREF

  v8 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
         vm->StringManagerRef,
         &result,
         "activation@");
  pObject = vm->PublicNamespace.pObject;
  if ( pObject )
    pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
  Scaleform::GFx::AS3::Traits::Traits(this, vm, 0i64, 1, 1);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::Traits::`vftable;
  this->Ns.pObject = pObject;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::RTraits::`vftable;
  pNode = v8->pNode;
  this->Name = (Scaleform::GFx::ASString)v8->pNode;
  ++pNode->RefCount;
  v11 = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::Activation::`vftable;
  this->TraitsType = Traits_Activation;
  Scaleform::GFx::AS3::Traits::AddSlots(this, (Scaleform::GFx::AS3::CheckResult *)&result, mbi, file, 0x38u);
}

