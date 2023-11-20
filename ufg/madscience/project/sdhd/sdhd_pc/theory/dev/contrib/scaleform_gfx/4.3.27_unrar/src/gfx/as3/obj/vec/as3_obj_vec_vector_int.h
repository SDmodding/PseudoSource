// File Line: 112
// RVA: 0x80AE40
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint::PushBack(Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *this, int v)
{
  Scaleform::ArrayDataBase<enum Scaleform::GFx::AS3::XMLParser::Kind,Scaleform::AllocatorDH_POD<enum Scaleform::GFx::AS3::XMLParser::Kind,2>,Scaleform::ArrayDefaultPolicy> *v2; // rbx
  int v3; // esi
  unsigned __int64 v4; // rax
  unsigned __int64 v5; // rdi
  unsigned __int64 v6; // r8
  Scaleform::GFx::AS3::XMLParser::Kind *v7; // rax
  int *v8; // rcx
  Scaleform::GFx::AS3::CheckResult result; // [rsp+30h] [rbp+8h]

  v2 = (Scaleform::ArrayDataBase<enum Scaleform::GFx::AS3::XMLParser::Kind,Scaleform::AllocatorDH_POD<enum Scaleform::GFx::AS3::XMLParser::Kind,2>,Scaleform::ArrayDefaultPolicy> *)&this->V;
  v3 = v;
  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed((Scaleform::GFx::AS3::ArrayBase *)&this->V.vfptr, &result)->Result )
  {
    v4 = v2[1].Size;
    v5 = v4 + 1;
    if ( v4 + 1 >= v4 )
    {
      if ( v5 <= v2[1].Policy.Capacity )
        goto LABEL_8;
      v6 = v5 + (v5 >> 2);
    }
    else
    {
      if ( v5 >= v2[1].Policy.Capacity >> 1 )
        goto LABEL_8;
      v6 = v4 + 1;
    }
    Scaleform::ArrayDataBase<unsigned long,Scaleform::AllocatorDH<unsigned long,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v2 + 1,
      v2[2].Data,
      v6);
LABEL_8:
    v7 = v2[1].Data;
    v2[1].Size = v5;
    v8 = (int *)&v7[v5 - 1];
    if ( v8 )
      *v8 = v3;
  }
}

// File Line: 126
// RVA: 0x905FA0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_int::Set(Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *this, Scaleform::GFx::AS3::CheckResult *result, unsigned int ind, Scaleform::GFx::AS3::Value *v, Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  Scaleform::GFx::AS3::CheckResult *v5; // rbx

  v5 = result;
  Scaleform::GFx::AS3::VectorBase<long>::Set(&this->V, result, ind, v, tr);
  return v5;
}

// File Line: 127
// RVA: 0x7E4730
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_int::Get(Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *this, unsigned int ind, Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::VectorBase<long>::Get(&this->V, ind, v);
}

// File Line: 128
// RVA: 0x8FEFD0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint::RemoveAt(Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *this, Scaleform::GFx::AS3::CheckResult *result, unsigned int ind)
{
  Scaleform::GFx::AS3::CheckResult *v3; // rbx

  v3 = result;
  Scaleform::GFx::AS3::VectorBase<long>::RemoveAt(&this->V, result, ind);
  return v3;
}

// File Line: 321
// RVA: 0x8EA7D0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_int::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int> *result, Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_int *t)
{
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_int *v2; // rdi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int> *v3; // rbx
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *v4; // rax

  v2 = t;
  v3 = result;
  v4 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *)Scaleform::GFx::AS3::Traits::Alloc((Scaleform::GFx::AS3::Traits *)&t->vfptr);
  if ( v4 )
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_int::Vector_int(
      v4,
      (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v2->vfptr);
  v3->pV = v4;
  return v3;
}

// File Line: 338
// RVA: 0x8EA820
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_int::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int> *result, Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_int *t, unsigned int length, bool fixed)
{
  bool v4; // si
  unsigned int v5; // ebp
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_int *v6; // rdi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int> *v7; // rbx
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *v8; // rax

  v4 = fixed;
  v5 = length;
  v6 = t;
  v7 = result;
  v8 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *)Scaleform::GFx::AS3::Traits::Alloc((Scaleform::GFx::AS3::Traits *)&t->vfptr);
  if ( v8 )
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_int::Vector_int(
      v8,
      (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v6->vfptr,
      v5,
      v4);
  v7->pV = v8;
  return v7;
}

