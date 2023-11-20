// File Line: 137
// RVA: 0x905FD0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_object::Set(Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *this, Scaleform::GFx::AS3::CheckResult *result, unsigned int ind, Scaleform::GFx::AS3::Value *v, Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  Scaleform::GFx::AS3::CheckResult *v5; // rbx

  v5 = result;
  Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::Set(&this->V, result, ind, v, tr);
  return v5;
}

// File Line: 139
// RVA: 0x8FEFF0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_object::RemoveAt(Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *this, Scaleform::GFx::AS3::CheckResult *result, unsigned int ind)
{
  Scaleform::GFx::AS3::CheckResult *v3; // rbx

  v3 = result;
  Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::RemoveAt(&this->V, result, ind);
  return v3;
}

// File Line: 332
// RVA: 0x8EA890
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_object::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *result, Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_object *t)
{
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_object *v2; // rdi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *v3; // rbx
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *v4; // rax

  v2 = t;
  v3 = result;
  v4 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)Scaleform::GFx::AS3::Traits::Alloc((Scaleform::GFx::AS3::Traits *)&t->vfptr);
  if ( v4 )
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_object::Vector_object(
      v4,
      (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v2->vfptr);
  v3->pV = v4;
  return v3;
}

// File Line: 349
// RVA: 0x8EA8E0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_object::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *result, Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_object *t, unsigned int length, bool fixed)
{
  bool v4; // si
  unsigned int v5; // ebp
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_object *v6; // rdi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *v7; // rbx
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *v8; // rax

  v4 = fixed;
  v5 = length;
  v6 = t;
  v7 = result;
  v8 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)Scaleform::GFx::AS3::Traits::Alloc((Scaleform::GFx::AS3::Traits *)&t->vfptr);
  if ( v8 )
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_object::Vector_object(
      v8,
      (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v6->vfptr,
      v5,
      v4);
  v7->pV = v8;
  return v7;
}

