// File Line: 112
// RVA: 0x80AE40
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint::PushBack(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *this,
        Scaleform::GFx::AS3::XMLParser::Kind v)
{
  Scaleform::ArrayDataBase<enum Scaleform::GFx::AS3::XMLParser::Kind,Scaleform::AllocatorDH_POD<enum Scaleform::GFx::AS3::XMLParser::Kind,2>,Scaleform::ArrayDefaultPolicy> *p_V; // rbx
  unsigned __int64 Size; // rax
  unsigned __int64 v5; // rdi
  unsigned __int64 v6; // r8
  Scaleform::GFx::AS3::XMLParser::Kind *Data; // rax
  Scaleform::GFx::AS3::XMLParser::Kind *v8; // rcx
  Scaleform::GFx::AS3::CheckResult result; // [rsp+30h] [rbp+8h] BYREF

  p_V = (Scaleform::ArrayDataBase<enum Scaleform::GFx::AS3::XMLParser::Kind,Scaleform::AllocatorDH_POD<enum Scaleform::GFx::AS3::XMLParser::Kind,2>,Scaleform::ArrayDefaultPolicy> *)&this->V;
  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(&this->V, &result)->Result )
  {
    Size = p_V[1].Size;
    v5 = Size + 1;
    if ( Size + 1 >= Size )
    {
      if ( v5 <= p_V[1].Policy.Capacity )
        goto LABEL_8;
      v6 = v5 + (v5 >> 2);
    }
    else
    {
      if ( v5 >= p_V[1].Policy.Capacity >> 1 )
        goto LABEL_8;
      v6 = Size + 1;
    }
    Scaleform::ArrayDataBase<unsigned long,Scaleform::AllocatorDH<unsigned long,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      p_V + 1,
      p_V[2].Data,
      v6);
LABEL_8:
    Data = p_V[1].Data;
    p_V[1].Size = v5;
    v8 = &Data[v5 - 1];
    if ( v8 )
      *v8 = v;
  }
}

// File Line: 126
// RVA: 0x905FA0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_int::Set(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *this,
        Scaleform::GFx::AS3::CheckResult *result,
        unsigned int ind,
        Scaleform::GFx::AS3::Value *v,
        Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  Scaleform::GFx::AS3::VectorBase<long>::Set(&this->V, result, ind, v, tr);
  return result;
}

// File Line: 127
// RVA: 0x7E4730
void __fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_int::Get(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *this,
        unsigned int ind,
        Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::VectorBase<long>::Get(&this->V, ind, v);
}

// File Line: 128
// RVA: 0x8FEFD0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint::RemoveAt(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *this,
        Scaleform::GFx::AS3::CheckResult *result,
        unsigned int ind)
{
  Scaleform::GFx::AS3::VectorBase<long>::RemoveAt(&this->V, result, ind);
  return result;
}

// File Line: 321
// RVA: 0x8EA7D0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_int::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_int *t)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *v4; // rax

  v4 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *)Scaleform::GFx::AS3::Traits::Alloc(t);
  if ( v4 )
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_int::Vector_int(v4, t);
  result->pV = v4;
  return result;
}

// File Line: 338
// RVA: 0x8EA820
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_int::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_int *t,
        unsigned int length,
        bool fixed)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *v8; // rax

  v8 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *)Scaleform::GFx::AS3::Traits::Alloc(t);
  if ( v8 )
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_int::Vector_int(v8, t, length, fixed);
  result->pV = v8;
  return result;
}

