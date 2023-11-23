// File Line: 112
// RVA: 0x8F5350
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::PushBack(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this,
        Scaleform::GFx::ASStringNode *v)
{
  Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> > *p_V; // rbx
  Scaleform::Ptr<Scaleform::GFx::ASStringNode> *v4; // rdx
  Scaleform::Ptr<Scaleform::GFx::ASStringNode> *result; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::GFx::ASStringNode *v7; // [rsp+48h] [rbp+10h]
  Scaleform::Ptr<Scaleform::GFx::ASStringNode> *v8; // [rsp+50h] [rbp+18h]

  if ( v )
    ++v->RefCount;
  v7 = v;
  p_V = &this->V;
  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(&this->V, (Scaleform::GFx::AS3::CheckResult *)&result)->Result )
  {
    Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &p_V->ValueA.Data,
      p_V->ValueA.Data.pHeap,
      p_V->ValueA.Data.Size + 1);
    v4 = &p_V->ValueA.Data.Data[p_V->ValueA.Data.Size - 1];
    result = v4;
    v8 = v4;
    if ( v4 )
    {
      if ( v )
        ++v->RefCount;
      v4->pObject = v;
    }
  }
  if ( v )
  {
    if ( v->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v);
  }
}

// File Line: 126
// RVA: 0x905F70
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::Set(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this,
        Scaleform::GFx::AS3::CheckResult *result,
        unsigned int ind,
        Scaleform::GFx::AS3::Value *v,
        Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Set(&this->V, result, ind, v, tr);
  return result;
}

// File Line: 128
// RVA: 0x8FEF90
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::RemoveAt(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this,
        Scaleform::GFx::AS3::CheckResult *result,
        unsigned int ind)
{
  Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::RemoveAt(&this->V, result, ind);
  return result;
}

// File Line: 321
// RVA: 0x8EA650
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String *t)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *v4; // rax

  v4 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *)Scaleform::GFx::AS3::Traits::Alloc(t);
  if ( v4 )
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::Vector_String(v4, t);
  result->pV = v4;
  return result;
}

// File Line: 338
// RVA: 0x8EA6A0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String *t,
        unsigned int length,
        bool fixed)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *v8; // rax

  v8 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *)Scaleform::GFx::AS3::Traits::Alloc(t);
  if ( v8 )
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::Vector_String(v8, t, length, fixed);
  result->pV = v8;
  return result;
}

