// File Line: 126
// RVA: 0x818160
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint::Set(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *this,
        Scaleform::GFx::AS3::CheckResult *result,
        unsigned int ind,
        Scaleform::GFx::AS3::Value *v,
        Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  Scaleform::GFx::AS3::VectorBase<unsigned long>::Set(&this->V, result, ind, v, tr);
  return result;
}

// File Line: 127
// RVA: 0x7E4740
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint::Get(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *this,
        unsigned int ind,
        Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::VectorBase<unsigned long>::Get(&this->V, ind, v);
}

// File Line: 201
// RVA: 0x851890
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint::lengthSet(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *this,
        unsigned int value)
{
  if ( (_S11_12 & 1) == 0 )
  {
    _S11_12 |= 1u;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0i64;
    atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint::lengthSet(this, &v, value);
}

// File Line: 321
// RVA: 0x8EA950
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_uint::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_uint *t)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *v4; // rax

  v4 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *)Scaleform::GFx::AS3::Traits::Alloc(t);
  if ( v4 )
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint::Vector_uint(v4, t);
  result->pV = v4;
  return result;
}

// File Line: 338
// RVA: 0x8EA9A0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_uint::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_uint *t,
        unsigned int length,
        bool fixed)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *v8; // rax

  v8 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *)Scaleform::GFx::AS3::Traits::Alloc(t);
  if ( v8 )
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint::Vector_uint(v8, t, length, fixed);
  result->pV = v8;
  return result;
}

