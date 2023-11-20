// File Line: 34
// RVA: 0x77A920
void __fastcall Scaleform::GFx::AS3::InstanceTraits::Activation::Activation(Scaleform::GFx::AS3::InstanceTraits::Activation *this, Scaleform::GFx::AS3::VMAbcFile *file, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Abc::MethodBodyInfo *mbi)
{
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v4; // rbp
  Scaleform::GFx::AS3::VM *v5; // rsi
  Scaleform::GFx::AS3::VMAbcFile *v6; // r14
  Scaleform::GFx::AS3::InstanceTraits::Activation *v7; // rdi
  Scaleform::GFx::ASString *v8; // r15
  Scaleform::GFx::AS3::Instances::fl::Namespace *v9; // rbx
  Scaleform::GFx::ASStringNode *v10; // rax
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  Scaleform::GFx::AS3::CheckResult result; // [rsp+80h] [rbp+18h]

  v4 = mbi;
  v5 = vm;
  v6 = file;
  v7 = this;
  v8 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
         (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)vm->StringManagerRef->Builtins,
         (Scaleform::GFx::ASString *)&result,
         "activation@");
  v9 = v5->PublicNamespace.pObject;
  if ( v9 )
    v9->RefCount = (v9->RefCount + 1) & 0x8FBFFFFF;
  Scaleform::GFx::AS3::Traits::Traits((Scaleform::GFx::AS3::Traits *)&v7->vfptr, v5, 0i64, 1, 1);
  v7->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::Traits::`vftable';
  v7->Ns.pObject = v9;
  v7->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::RTraits::`vftable';
  v10 = v8->pNode;
  v7->Name = (Scaleform::GFx::ASString)v8->pNode;
  ++v10->RefCount;
  v11 = *(Scaleform::GFx::ASStringNode **)&result.Result;
  v12 = *(_DWORD *)(*(_QWORD *)&result.Result + 24i64) == 1;
  --v11->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  v7->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::Activation::`vftable';
  v7->TraitsType = 20;
  Scaleform::GFx::AS3::Traits::AddSlots(
    (Scaleform::GFx::AS3::Traits *)&v7->vfptr,
    &result,
    (Scaleform::GFx::AS3::Abc::HasTraits *)&v4->obj_traits,
    v6,
    0x38u);
}

