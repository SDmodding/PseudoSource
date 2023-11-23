// File Line: 137
// RVA: 0x905FD0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_object::Set(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *this,
        Scaleform::GFx::AS3::CheckResult *result,
        unsigned int ind,
        Scaleform::GFx::AS3::Value *v,
        Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::Set(&this->V, result, ind, v, tr);
  return result;
}

// File Line: 139
// RVA: 0x8FEFF0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_object::RemoveAt(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *this,
        Scaleform::GFx::AS3::CheckResult *result,
        unsigned int ind)
{
  Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::RemoveAt(&this->V, result, ind);
  return result;
}

// File Line: 332
// RVA: 0x8EA890
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_object::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_object *t)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *v4; // rax

  v4 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)Scaleform::GFx::AS3::Traits::Alloc(t);
  if ( v4 )
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_object::Vector_object(v4, t);
  result->pV = v4;
  return result;
}

// File Line: 349
// RVA: 0x8EA8E0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_object::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_object *t,
        unsigned int length,
        bool fixed)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *v8; // rax

  v8 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)Scaleform::GFx::AS3::Traits::Alloc(t);
  if ( v8 )
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_object::Vector_object(v8, t, length, fixed);
  result->pV = v8;
  return result;
}

