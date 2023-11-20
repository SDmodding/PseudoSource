// File Line: 112
// RVA: 0x8F5350
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::PushBack(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this, Scaleform::GFx::ASStringNode *v)
{
  Scaleform::GFx::ASStringNode *v2; // rdi
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2>,Scaleform::ArrayDefaultPolicy> *v3; // rbx
  Scaleform::Ptr<Scaleform::GFx::ASStringNode> *v4; // rdx
  bool v5; // zf
  Scaleform::GFx::AS3::CheckResult result; // [rsp+40h] [rbp+8h]
  Scaleform::GFx::ASStringNode *v7; // [rsp+48h] [rbp+10h]
  Scaleform::Ptr<Scaleform::GFx::ASStringNode> *v8; // [rsp+50h] [rbp+18h]

  v2 = v;
  if ( v )
    ++v->RefCount;
  v7 = v;
  v3 = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2>,Scaleform::ArrayDefaultPolicy> *)&this->V;
  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed((Scaleform::GFx::AS3::ArrayBase *)&this->V.vfptr, &result)->Result )
  {
    Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      v3 + 1,
      v3[2].Data,
      v3[1].Size + 1);
    v4 = &v3[1].Data[v3[1].Size - 1];
    *(_QWORD *)&result.Result = v4;
    v8 = v4;
    if ( v4 )
    {
      if ( v2 )
        ++v2->RefCount;
      v4->pObject = v2;
    }
  }
  if ( v2 )
  {
    v5 = v2->RefCount-- == 1;
    if ( v5 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v2);
  }
}

// File Line: 126
// RVA: 0x905F70
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::Set(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this, Scaleform::GFx::AS3::CheckResult *result, unsigned int ind, Scaleform::GFx::AS3::Value *v, Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  Scaleform::GFx::AS3::CheckResult *v5; // rbx

  v5 = result;
  Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Set(&this->V, result, ind, v, tr);
  return v5;
}

// File Line: 128
// RVA: 0x8FEF90
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::RemoveAt(Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this, Scaleform::GFx::AS3::CheckResult *result, unsigned int ind)
{
  Scaleform::GFx::AS3::CheckResult *v3; // rbx

  v3 = result;
  Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::RemoveAt(&this->V, result, ind);
  return v3;
}

// File Line: 321
// RVA: 0x8EA650
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String> *result, Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String *t)
{
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String *v2; // rdi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String> *v3; // rbx
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *v4; // rax

  v2 = t;
  v3 = result;
  v4 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *)Scaleform::GFx::AS3::Traits::Alloc((Scaleform::GFx::AS3::Traits *)&t->vfptr);
  if ( v4 )
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::Vector_String(
      v4,
      (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v2->vfptr);
  v3->pV = v4;
  return v3;
}

// File Line: 338
// RVA: 0x8EA6A0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String> *result, Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String *t, unsigned int length, bool fixed)
{
  bool v4; // si
  unsigned int v5; // ebp
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String *v6; // rdi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String> *v7; // rbx
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *v8; // rax

  v4 = fixed;
  v5 = length;
  v6 = t;
  v7 = result;
  v8 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *)Scaleform::GFx::AS3::Traits::Alloc((Scaleform::GFx::AS3::Traits *)&t->vfptr);
  if ( v8 )
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::Vector_String(
      v8,
      (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v6->vfptr,
      v5,
      v4);
  v7->pV = v8;
  return v7;
}

