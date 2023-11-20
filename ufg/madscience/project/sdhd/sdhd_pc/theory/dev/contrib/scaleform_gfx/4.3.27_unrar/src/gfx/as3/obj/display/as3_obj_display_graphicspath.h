// File Line: 181
// RVA: 0x7FC0D0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::GraphicsPath> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_display::GraphicsPath::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::GraphicsPath> *result, Scaleform::GFx::AS3::InstanceTraits::fl_display::GraphicsPath *t)
{
  Scaleform::GFx::AS3::InstanceTraits::fl_display::GraphicsPath *v2; // rsi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::GraphicsPath> *v3; // rdi
  Scaleform::GFx::AS3::Instance *v4; // rax
  Scaleform::GFx::ASString *v5; // rbx
  int v7; // [rsp+50h] [rbp+8h]
  Scaleform::GFx::AS3::Instance *v8; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::AS3::Instance *v9; // [rsp+60h] [rbp+18h]

  v2 = t;
  v3 = result;
  v7 = 337;
  v4 = (Scaleform::GFx::AS3::Instance *)t->pVM->MHeap->vfptr->Alloc(
                                          t->pVM->MHeap,
                                          t->MemSize,
                                          (Scaleform::AllocInfo *)&v7);
  v5 = (Scaleform::GFx::ASString *)v4;
  v8 = v4;
  v9 = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instance::Instance(v4, (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v2->vfptr);
    v5->pNode = (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable';
    v5->pNode = (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::Instances::fl_display::GraphicsPath::`vftable';
    v5[7].pNode = 0i64;
    v5[8].pNode = 0i64;
    Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
      (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v5[5].pNode[3].pManager->StringSet.pTable,
      v5 + 9,
      "evenOdd");
  }
  else
  {
    v5 = 0i64;
  }
  v3->pV = (Scaleform::GFx::AS3::Instances::fl_display::GraphicsPath *)v5;
  return v3;
}

