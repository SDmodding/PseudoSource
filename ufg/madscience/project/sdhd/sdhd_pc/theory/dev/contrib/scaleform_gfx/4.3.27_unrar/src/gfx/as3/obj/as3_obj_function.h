// File Line: 391
// RVA: 0x7FBB10
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::FunctionBase> *__fastcall Scaleform::GFx::AS3::InstanceTraits::Function::MakeInstance(Scaleform::GFx::AS3::InstanceTraits::Function *this, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::FunctionBase> *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::FunctionBase> *v3; // rbx
  Scaleform::GFx::AS3::InstanceTraits::Function *v4; // rdi
  Scaleform::GFx::AS3::Instances::FunctionBase *v5; // rax
  int v7; // [rsp+48h] [rbp+10h]
  Scaleform::GFx::AS3::Instances::FunctionBase *v8; // [rsp+50h] [rbp+18h]
  Scaleform::GFx::AS3::Instances::FunctionBase *v9; // [rsp+58h] [rbp+20h]

  v3 = result;
  v4 = this;
  v7 = 337;
  v5 = (Scaleform::GFx::AS3::Instances::FunctionBase *)t->pVM->MHeap->vfptr->Alloc(
                                                         t->pVM->MHeap,
                                                         t->MemSize,
                                                         (Scaleform::AllocInfo *)&v7);
  v8 = v5;
  v9 = v5;
  if ( v5 )
    Scaleform::GFx::AS3::Instances::FunctionBase::FunctionBase(
      v5,
      (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v4->vfptr);
  v3->pV = v5;
  return v3;
}

