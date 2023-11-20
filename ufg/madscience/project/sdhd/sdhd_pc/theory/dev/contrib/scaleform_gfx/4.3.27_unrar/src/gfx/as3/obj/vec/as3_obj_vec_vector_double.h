// File Line: 114
// RVA: 0x80ADB0
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_double::PushBack(Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *this, long double v)
{
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> *v2; // rbx
  unsigned __int64 v3; // rax
  unsigned __int64 v4; // rdi
  unsigned __int64 v5; // r8
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v6; // rax
  long double *v7; // rcx
  Scaleform::GFx::AS3::CheckResult result; // [rsp+40h] [rbp+8h]

  v2 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> *)&this->V;
  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed((Scaleform::GFx::AS3::ArrayBase *)&this->V.vfptr, &result)->Result )
  {
    v3 = v2[1].Size;
    v4 = v3 + 1;
    if ( v3 + 1 >= v3 )
    {
      if ( v4 <= v2[1].Policy.Capacity )
        goto LABEL_8;
      v5 = v4 + (v4 >> 2);
    }
    else
    {
      if ( v4 >= v2[1].Policy.Capacity >> 1 )
        goto LABEL_8;
      v5 = v3 + 1;
    }
    Scaleform::ArrayDataBase<double const *,Scaleform::AllocatorDH<double const *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v2 + 1,
      v2[2].Data,
      v5);
LABEL_8:
    v6 = v2[1].Data;
    v2[1].Size = v4;
    v7 = (long double *)&v6[v4 - 1];
    if ( v7 )
      *v7 = v;
  }
}

// File Line: 125
// RVA: 0x818130
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_double::Set(Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *this, Scaleform::GFx::AS3::CheckResult *result, unsigned int ind, Scaleform::GFx::AS3::Value *v, Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  Scaleform::GFx::AS3::CheckResult *v5; // rbx

  v5 = result;
  Scaleform::GFx::AS3::VectorBase<double>::Set(&this->V, result, ind, v, tr);
  return v5;
}

// File Line: 126
// RVA: 0x7E4720
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_double::Get(Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *this, unsigned int ind, Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::VectorBase<double>::Get(&this->V, ind, v);
}

// File Line: 127
// RVA: 0x8FEFB0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_double::RemoveAt(Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *this, Scaleform::GFx::AS3::CheckResult *result, unsigned int ind)
{
  Scaleform::GFx::AS3::CheckResult *v3; // rbx

  v3 = result;
  Scaleform::GFx::AS3::VectorBase<double>::RemoveAt(&this->V, result, ind);
  return v3;
}

// File Line: 323
// RVA: 0x8EA710
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_double::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double> *result, Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_double *t)
{
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_double *v2; // rdi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double> *v3; // rbx
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *v4; // rax

  v2 = t;
  v3 = result;
  v4 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *)Scaleform::GFx::AS3::Traits::Alloc((Scaleform::GFx::AS3::Traits *)&t->vfptr);
  if ( v4 )
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_double::Vector_double(
      v4,
      (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v2->vfptr);
  v3->pV = v4;
  return v3;
}

// File Line: 340
// RVA: 0x8EA760
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_double::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double> *result, Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_double *t, unsigned int length, bool fixed)
{
  bool v4; // si
  unsigned int v5; // ebp
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_double *v6; // rdi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double> *v7; // rbx
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *v8; // rax

  v4 = fixed;
  v5 = length;
  v6 = t;
  v7 = result;
  v8 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *)Scaleform::GFx::AS3::Traits::Alloc((Scaleform::GFx::AS3::Traits *)&t->vfptr);
  if ( v8 )
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_double::Vector_double(
      v8,
      (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v6->vfptr,
      v5,
      v4);
  v7->pV = v8;
  return v7;
}

