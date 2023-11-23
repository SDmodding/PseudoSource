// File Line: 114
// RVA: 0x80ADB0
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_double::PushBack(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *this,
        long double v)
{
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> *p_V; // rbx
  unsigned __int64 Size; // rax
  unsigned __int64 v4; // rdi
  unsigned __int64 v5; // r8
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *Data; // rax
  long double *v7; // rcx
  Scaleform::GFx::AS3::CheckResult result; // [rsp+40h] [rbp+8h] BYREF

  p_V = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> *)&this->V;
  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(&this->V, &result)->Result )
  {
    Size = p_V[1].Size;
    v4 = Size + 1;
    if ( Size + 1 >= Size )
    {
      if ( v4 <= p_V[1].Policy.Capacity )
        goto LABEL_8;
      v5 = v4 + (v4 >> 2);
    }
    else
    {
      if ( v4 >= p_V[1].Policy.Capacity >> 1 )
        goto LABEL_8;
      v5 = Size + 1;
    }
    Scaleform::ArrayDataBase<double const *,Scaleform::AllocatorDH<double const *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      p_V + 1,
      p_V[2].Data,
      v5);
LABEL_8:
    Data = p_V[1].Data;
    p_V[1].Size = v4;
    v7 = (long double *)&Data[v4 - 1];
    if ( v7 )
      *v7 = v;
  }
}

// File Line: 125
// RVA: 0x818130
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_double::Set(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *this,
        Scaleform::GFx::AS3::CheckResult *result,
        unsigned int ind,
        Scaleform::GFx::AS3::Value *v,
        Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  Scaleform::GFx::AS3::VectorBase<double>::Set(&this->V, result, ind, v, tr);
  return result;
}

// File Line: 126
// RVA: 0x7E4720
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_double::Get(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *this,
        unsigned int ind,
        Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::VectorBase<double>::Get(&this->V, ind, v);
}

// File Line: 127
// RVA: 0x8FEFB0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_double::RemoveAt(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *this,
        Scaleform::GFx::AS3::CheckResult *result,
        unsigned int ind)
{
  Scaleform::GFx::AS3::VectorBase<double>::RemoveAt(&this->V, result, ind);
  return result;
}

// File Line: 323
// RVA: 0x8EA710
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_double::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_double *t)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *v4; // rax

  v4 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *)Scaleform::GFx::AS3::Traits::Alloc(t);
  if ( v4 )
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_double::Vector_double(v4, t);
  result->pV = v4;
  return result;
}

// File Line: 340
// RVA: 0x8EA760
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_double::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_double *t,
        unsigned int length,
        bool fixed)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *v8; // rax

  v8 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *)Scaleform::GFx::AS3::Traits::Alloc(t);
  if ( v8 )
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_double::Vector_double(v8, t, length, fixed);
  result->pV = v8;
  return result;
}

