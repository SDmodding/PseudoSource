// File Line: 148
// RVA: 0x8EC120
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::ArrayBase::OfCorrectType(Scaleform::GFx::AS3::ArrayBase *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::Value *v, Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  Scaleform::GFx::AS3::CheckResult *v4; // rdi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rbx
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rax

  v4 = result;
  v5 = tr;
  v6 = Scaleform::GFx::AS3::VM::GetClassTraits(this->VMRef, v);
  v4->Result = Scaleform::GFx::AS3::ClassTraits::Traits::IsParentTypeOf(v5, v6);
  return v4;
}

// File Line: 220
// RVA: 0x8A3230
void __fastcall Scaleform::GFx::AS3::VectorBase<long>::ArrayFunc::~ArrayFunc(Scaleform::GFx::AS3::VectorBase<long>::ArrayFunc *this)
{
  this->vfptr = (Scaleform::GFx::AS3::VectorBase<long>::ArrayFuncVtbl *)&Scaleform::GFx::AS3::VectorBase<long>::ArrayFunc::`vftable';
}

// File Line: 250
// RVA: 0x8A98D0
_BOOL8 __fastcall Scaleform::GFx::AS3::VectorBase<long>::CompareValuePtr::operator()(Scaleform::GFx::AS3::VectorBase<long>::CompareValuePtr *this, const int *a, const int *b)
{
  int v3; // eax
  int v4; // eax
  bool v5; // bl
  Scaleform::GFx::AS3::Value aa; // [rsp+28h] [rbp-50h]
  Scaleform::GFx::AS3::Value ba; // [rsp+48h] [rbp-30h]

  v3 = *b;
  ba.Flags = 2;
  ba.Bonus.pWeakProxy = 0i64;
  ba.value.VS._1.VInt = v3;
  v4 = *a;
  aa.Flags = 2;
  aa.Bonus.pWeakProxy = 0i64;
  aa.value.VS._1.VInt = v4;
  v5 = Scaleform::GFx::AS3::Impl::CompareFunct(this->Vm, this->Func, &aa, &ba) < 0;
  if ( (aa.Flags & 0x1F) > 9 )
  {
    if ( (aa.Flags >> 9) & 1 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&aa);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&aa);
  }
  if ( (ba.Flags & 0x1F) > 9 )
  {
    if ( (ba.Flags >> 9) & 1 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&ba);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&ba);
  }
  return v5;
}

// File Line: 254
// RVA: 0x8C8A20
_BOOL8 __fastcall Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::CompareValuePtr::Equal(Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> >::CompareValuePtr *this, Scaleform::Ptr<Scaleform::GFx::ASStringNode> *a, Scaleform::Ptr<Scaleform::GFx::ASStringNode> *b)
{
  Scaleform::Ptr<Scaleform::GFx::ASStringNode> *v3; // rbx
  Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> >::CompareValuePtr *v4; // rsi
  Scaleform::GFx::AS3::Value *v5; // rax
  Scaleform::GFx::AS3::Value *v6; // rdi
  Scaleform::GFx::AS3::Value *v7; // rax
  bool v8; // bl
  Scaleform::GFx::AS3::Value v10; // [rsp+28h] [rbp-50h]
  Scaleform::GFx::AS3::Value v11; // [rsp+48h] [rbp-30h]

  v3 = a;
  v4 = this;
  Scaleform::GFx::AS3::Value::Value(&v11, b->pObject);
  v6 = v5;
  Scaleform::GFx::AS3::Value::Value(&v10, v3->pObject);
  v8 = (unsigned int)Scaleform::GFx::AS3::Impl::CompareFunct(v4->Vm, v4->Func, v7, v6) == 0;
  if ( (v10.Flags & 0x1F) > 9 )
  {
    if ( (v10.Flags >> 9) & 1 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
  }
  if ( (v11.Flags & 0x1F) > 9 )
  {
    if ( (v11.Flags >> 9) & 1 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v11);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v11);
  }
  return v8;
}

// File Line: 320
// RVA: 0x8AA620
void __fastcall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::ValuePtrCollector::operator()(Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::ValuePtrCollector *this, unsigned int __formal, Scaleform::GFx::AS3::Value *v)
{
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> *v3; // rdi
  Scaleform::GFx::AS3::Value *v4; // rsi
  unsigned __int64 v5; // rbx
  unsigned __int64 v6; // r8
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v7; // rcx
  Scaleform::GFx::AS3::Value **v8; // rcx

  v3 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> *)this->Ptrs;
  v4 = v;
  v5 = v3->Size + 1;
  if ( v5 >= v3->Size )
  {
    if ( v5 <= v3->Policy.Capacity )
      goto LABEL_7;
    v6 = v5 + (v5 >> 2);
  }
  else
  {
    if ( v5 >= v3->Policy.Capacity >> 1 )
      goto LABEL_7;
    v6 = v3->Size + 1;
  }
  Scaleform::ArrayDataBase<double const *,Scaleform::AllocatorDH<double const *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    v3,
    v3[1].Data,
    v6);
LABEL_7:
  v7 = v3->Data;
  v3->Size = v5;
  v8 = (Scaleform::GFx::AS3::Value **)&v7[v5 - 1];
  if ( v8 )
    *v8 = v4;
}

// File Line: 345
// RVA: 0x8E1320
void __fastcall Scaleform::GFx::AS3::VectorBase<unsigned long>::GetValue(Scaleform::GFx::AS3::VectorBase<unsigned long> *this, unsigned int ind, Scaleform::GFx::AS3::Value *v)
{
  unsigned int v3; // edi
  Scaleform::GFx::AS3::Value *v4; // rbx
  long double v5; // [rsp+20h] [rbp-18h]
  Scaleform::GFx::AS3::Value::V2U v6; // [rsp+28h] [rbp-10h]

  v3 = this->ValueA.Data.Data[ind];
  v4 = v;
  if ( (v->Flags & 0x1F) > 9 )
  {
    if ( (v->Flags >> 9) & 1 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(v);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(v);
  }
  v4->Flags &= 0xFFFFFFE3;
  v4->Flags |= 3u;
  LODWORD(v5) = v3;
  v4->value.VNumber = v5;
  v4->value.VS._2 = v6;
}

// File Line: 346
// RVA: 0x8E1460
void __fastcall Scaleform::GFx::AS3::VectorBase<unsigned long>::GetValueUnsafe(Scaleform::GFx::AS3::VectorBase<unsigned long> *this, unsigned int ind, Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::Value::VU v3; // [rsp+0h] [rbp-18h]

  v3.VS._1.VInt = this->ValueA.Data.Data[ind];
  v->Flags = v->Flags & 0xFFFFFFE3 | 3;
  v->value = v3;
}

// File Line: 359
// RVA: 0x8B6030
void __fastcall Scaleform::GFx::AS3::VectorBase<unsigned long>::Append(Scaleform::GFx::AS3::VectorBase<unsigned long> *this, Scaleform::GFx::AS3::VectorBase<unsigned long> *other)
{
  Scaleform::GFx::AS3::VectorBase<unsigned long> *v2; // rbp
  Scaleform::ArrayDataBase<enum Scaleform::GFx::AS3::XMLParser::Kind,Scaleform::AllocatorDH_POD<enum Scaleform::GFx::AS3::XMLParser::Kind,2>,Scaleform::ArrayDefaultPolicy> *v3; // rdi
  unsigned __int64 v4; // rsi
  unsigned int *v5; // r14
  unsigned __int64 v6; // rax
  unsigned __int64 v7; // rbx
  unsigned __int64 v8; // r8
  Scaleform::GFx::AS3::XMLParser::Kind *v9; // rcx
  unsigned int *v10; // rcx
  Scaleform::GFx::AS3::CheckResult result; // [rsp+50h] [rbp+18h]

  v2 = other;
  v3 = (Scaleform::ArrayDataBase<enum Scaleform::GFx::AS3::XMLParser::Kind,Scaleform::AllocatorDH_POD<enum Scaleform::GFx::AS3::XMLParser::Kind,2>,Scaleform::ArrayDefaultPolicy> *)this;
  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed((Scaleform::GFx::AS3::ArrayBase *)&this->vfptr, &result)->Result )
  {
    v4 = 0i64;
    if ( LODWORD(v2->ValueA.Data.Size) )
    {
      do
      {
        v5 = &v2->ValueA.Data.Data[v4];
        v6 = v3[1].Size;
        v7 = v6 + 1;
        if ( v6 + 1 >= v6 )
        {
          if ( v7 > v3[1].Policy.Capacity )
          {
            v8 = v7 + (v7 >> 2);
            goto LABEL_8;
          }
        }
        else if ( v7 < v3[1].Policy.Capacity >> 1 )
        {
          v8 = v6 + 1;
LABEL_8:
          Scaleform::ArrayDataBase<unsigned long,Scaleform::AllocatorDH<unsigned long,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            v3 + 1,
            v3[2].Data,
            v8);
          goto LABEL_9;
        }
LABEL_9:
        v9 = v3[1].Data;
        v3[1].Size = v7;
        v10 = (unsigned int *)&v9[v7 - 1];
        if ( v10 )
          *v10 = *v5;
        ++v4;
      }
      while ( v4 < LODWORD(v2->ValueA.Data.Size) );
    }
  }
}

// File Line: 399
// RVA: 0x814430
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::VectorBase<double>::Resize(Scaleform::GFx::AS3::VectorBase<double> *this, Scaleform::GFx::AS3::CheckResult *result, unsigned __int64 newSise)
{
  Scaleform::GFx::AS3::CheckResult *v3; // r14
  unsigned __int64 v4; // rsi
  Scaleform::GFx::AS3::VectorBase<double> *v5; // rdi
  unsigned __int64 v6; // rbx
  Scaleform::GFx::AS3::CheckResult *v7; // rax
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+38h] [rbp+10h]

  v3 = result;
  v4 = newSise;
  v5 = this;
  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed((Scaleform::GFx::AS3::ArrayBase *)&this->vfptr, &resulta)->Result )
  {
    v6 = v5->ValueA.Data.Size;
    Scaleform::ArrayDataDH<double,Scaleform::AllocatorDH<double,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      &v5->ValueA.Data,
      v4);
    if ( v6 < v4 )
    {
      if ( (signed __int64)(v4 - v6) >= 4 )
      {
        do
        {
          v6 += 4i64;
          v5->ValueA.Data.Data[v6 - 4] = 0.0;
          v5->ValueA.Data.Data[v6 - 3] = 0.0;
          v5->ValueA.Data.Data[v6 - 2] = 0.0;
          v5->ValueA.Data.Data[v6 - 1] = 0.0;
        }
        while ( v6 < v4 - 3 );
      }
      for ( ; v6 < v4; v5->ValueA.Data.Data[v6 - 1] = 0.0 )
        ++v6;
    }
    v3->Result = 1;
    v7 = v3;
  }
  else
  {
    v3->Result = 0;
    v7 = v3;
  }
  return v7;
}

// File Line: 419
// RVA: 0x905C90
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Set(Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> > *this, Scaleform::GFx::AS3::CheckResult *result, unsigned int ind, Scaleform::GFx::AS3::Value *v, Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  Scaleform::GFx::AS3::Value *v5; // rbp
  __int64 v6; // rsi
  Scaleform::GFx::AS3::CheckResult *v7; // rbx
  Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> > *v8; // rdi
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  unsigned __int64 v12; // rax
  Scaleform::GFx::AS3::VM::Error *v13; // rax
  long double v14; // rbp
  Scaleform::GFx::ASStringNode **v15; // rdi
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::AS3::VM::Error v18; // [rsp+38h] [rbp-40h]
  Scaleform::GFx::AS3::Value coerced; // [rsp+48h] [rbp-30h]
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+80h] [rbp+8h]

  v5 = v;
  v6 = ind;
  v7 = result;
  v8 = this;
  if ( this->Fixed && ind >= LODWORD(this->ValueA.Data.Size) )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v18, eOutOfRangeError, this->VMRef);
    Scaleform::GFx::AS3::VM::ThrowRangeError(v8->VMRef, v9);
    goto LABEL_4;
  }
  v12 = this->ValueA.Data.Size;
  if ( ind > (unsigned int)v12 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v18, eOutOfRangeError, this->VMRef);
    Scaleform::GFx::AS3::VM::ThrowRangeError(v8->VMRef, v13);
LABEL_4:
    v10 = v18.Message.pNode;
    v11 = v18.Message.pNode->RefCount == 1;
    --v10->RefCount;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
    goto LABEL_6;
  }
  if ( ind == (_DWORD)v12
    && !Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Resize(this, &resulta, ind + 1)->Result )
  {
LABEL_6:
    v7->Result = 0;
    return v7;
  }
  coerced.Flags = 0;
  coerced.Bonus.pWeakProxy = 0i64;
  if ( Scaleform::GFx::AS3::ArrayBase::CheckCoerce(
         (Scaleform::GFx::AS3::ArrayBase *)&v8->vfptr,
         &resulta,
         tr,
         v5,
         &coerced)->Result )
  {
    v14 = coerced.value.VNumber;
    v15 = &v8->ValueA.Data.Data[v6].pObject;
    if ( *(_QWORD *)&coerced.value.VNumber )
      ++*(_DWORD *)(*(_QWORD *)&coerced.value.VNumber + 24i64);
    v16 = *v15;
    if ( *v15 )
    {
      v11 = v16->RefCount-- == 1;
      if ( v11 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v16);
    }
    *(long double *)v15 = v14;
    v7->Result = 1;
  }
  else
  {
    v7->Result = 0;
  }
  if ( (coerced.Flags & 0x1F) > 9 )
  {
    if ( (coerced.Flags >> 9) & 1 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&coerced);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&coerced);
  }
  return v7;
}

// File Line: 454
// RVA: 0x7E4390
void __fastcall Scaleform::GFx::AS3::VectorBase<long>::Get(Scaleform::GFx::AS3::VectorBase<long> *this, unsigned int ind, Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  int v4; // edi
  Scaleform::GFx::AS3::WeakProxy *v5; // rdx
  bool v6; // zf
  long double v7; // [rsp+20h] [rbp-18h]
  Scaleform::GFx::AS3::Value::V2U v8; // [rsp+28h] [rbp-10h]

  v3 = v;
  if ( ind < LODWORD(this->ValueA.Data.Size) )
  {
    v4 = this->ValueA.Data.Data[ind];
    if ( (signed int)(v->Flags & 0x1F) > 9 )
    {
      if ( (v->Flags >> 9) & 1 )
      {
        v5 = v->Bonus.pWeakProxy;
        v6 = v5->RefCount-- == 1;
        if ( v6 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v3->Flags &= 0xFFFFFDE0;
        v3->Bonus.pWeakProxy = 0i64;
        v3->value.VNumber = 0.0;
        v3->value.VS._2.VObj = 0i64;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(v);
      }
    }
    v3->Flags &= 0xFFFFFFE2;
    v3->Flags |= 2u;
    LODWORD(v7) = v4;
    v3->value.VNumber = v7;
    v3->value.VS._2 = v8;
  }
}

// File Line: 461
// RVA: 0x8FEF50
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::RemoveAt(Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *this, Scaleform::GFx::AS3::CheckResult *result, unsigned int ind)
{
  Scaleform::GFx::AS3::CheckResult *v3; // rbx
  Scaleform::GFx::AS3::CheckResult *v4; // rax

  v3 = result;
  if ( ind < LODWORD(this->ValueA.Data.Size) )
  {
    Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
      (Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> > *)&this->ValueA.Data,
      ind);
    v3->Result = 1;
    v4 = v3;
  }
  else
  {
    result->Result = 0;
    v4 = result;
  }
  return v4;
}

// File Line: 472
// RVA: 0x8863A0
void __fastcall Scaleform::GFx::AS3::VectorBase<unsigned long>::Map<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint>(Scaleform::GFx::AS3::VectorBase<unsigned long> *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint> *result, Scaleform::GFx::AS3::Value *callback, Scaleform::GFx::AS3::Value *thisObject, Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *currObj)
{
  Scaleform::GFx::AS3::Value *v5; // r14
  Scaleform::GFx::AS3::Value *v6; // r15
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint> *v7; // rdi
  Scaleform::GFx::AS3::VectorBase<unsigned long> *v8; // rsi
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *v9; // rcx
  unsigned int v10; // eax
  int v11; // ecx
  int v12; // ecx
  bool v13; // al
  Scaleform::GFx::AS3::Value *v14; // rcx
  unsigned int v15; // edx
  Scaleform::GFx::AS3::ClassTraits::Traits *v16; // r14
  __int64 v17; // rdi
  int v18; // ecx
  Scaleform::GFx::AS3::Value resulta; // [rsp+40h] [rbp-98h]
  Scaleform::GFx::AS3::Value coerced; // [rsp+60h] [rbp-78h]
  Scaleform::GFx::AS3::Value ptr; // [rsp+88h] [rbp-50h]
  int v22; // [rsp+A8h] [rbp-30h]
  __int64 v23; // [rsp+B0h] [rbp-28h]
  int v24; // [rsp+B8h] [rbp-20h]
  Scaleform::GFx::AS3::Value v25; // [rsp+C8h] [rbp-10h]
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_uint **retaddr; // [rsp+138h] [rbp+60h]

  coerced.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)-2i64;
  v5 = thisObject;
  v6 = callback;
  v7 = result;
  v8 = this;
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_uint::MakeInstance(
    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint> *)&currObj,
    retaddr[5]);
  v9 = v7->pObject;
  if ( retaddr != (Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_uint **)v7->pObject )
  {
    if ( v9 )
    {
      if ( (unsigned __int8)v9 & 1 )
      {
        v7->pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *)((char *)v9 - 1);
      }
      else
      {
        v10 = v9->RefCount;
        if ( v10 & 0x3FFFFF )
        {
          v9->RefCount = v10 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v9->vfptr);
        }
      }
    }
    v7->pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *)retaddr;
  }
  v11 = v6->Flags & 0x1F;
  if ( v11
    && ((unsigned int)(v11 - 12) > 3 && v11 != 10 || *(_QWORD *)&v6->value.VNumber)
    && Scaleform::GFx::AS3::ArrayBase::CheckCallable(
         (Scaleform::GFx::AS3::ArrayBase *)&v8->vfptr,
         (Scaleform::GFx::AS3::CheckResult *)&retaddr,
         v6)->Result )
  {
    v12 = v5->Flags & 0x1F;
    v13 = !v12 || ((unsigned int)(v12 - 12) <= 3 || v12 == 10) && !*(_QWORD *)&v5->value.VNumber;
    v14 = v6;
    if ( !v13 )
      v14 = v5;
    v15 = v14->Flags;
    LODWORD(resulta.value.VS._2.VObj) = v15;
    *(_QWORD *)&coerced.Flags = v14->Bonus.pWeakProxy;
    coerced.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v14->value.VS._1.VStr;
    *(_QWORD *)&coerced.value.VNumber = v14->value.VS._2.VObj;
    if ( (char)(v15 & 0x1F) > 9 )
    {
      if ( (v15 >> 9) & 1 )
        Scaleform::GFx::AS3::Value::AddRefWeakRef(v14);
      else
        Scaleform::GFx::AS3::Value::AddRefInternal(v14);
    }
    v16 = (Scaleform::GFx::AS3::ClassTraits::Traits *)&retaddr[5]->pVM->TraitsUint.pObject->vfptr;
    v17 = 0i64;
    if ( LODWORD(v8->ValueA.Data.Size) > 0 )
    {
      while ( 1 )
      {
        v18 = v8->ValueA.Data.Data[v17];
        ptr.Flags = 3;
        ptr.Bonus.pWeakProxy = 0i64;
        ptr.value.VS._1.VInt = v18;
        v22 = 3;
        v23 = 0i64;
        v24 = v17;
        Scaleform::GFx::AS3::Value::Value(&v25, (Scaleform::GFx::AS3::Object *)retaddr);
        resulta.Flags = 0;
        resulta.Bonus.pWeakProxy = 0i64;
        Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(
          v8->VMRef,
          v6,
          (Scaleform::GFx::AS3::Value *)((char *)&resulta + 24),
          &resulta,
          3u,
          &ptr,
          0);
        if ( v8->VMRef->HandleException )
          break;
        coerced.Flags = 0;
        coerced.Bonus.pWeakProxy = 0i64;
        if ( !Scaleform::GFx::AS3::ArrayBase::CheckCoerce(
                (Scaleform::GFx::AS3::ArrayBase *)&v8->vfptr,
                (Scaleform::GFx::AS3::CheckResult *)&retaddr,
                v16,
                &resulta,
                &coerced)->Result )
        {
          if ( (coerced.Flags & 0x1F) > 9 )
          {
            if ( (coerced.Flags >> 9) & 1 )
              Scaleform::GFx::AS3::Value::ReleaseWeakRef(&coerced);
            else
              Scaleform::GFx::AS3::Value::ReleaseInternal(&coerced);
          }
          break;
        }
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint::PushBack(
          (Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *)retaddr,
          coerced.value.VS._1.VInt);
        if ( (coerced.Flags & 0x1F) > 9 )
        {
          if ( (coerced.Flags >> 9) & 1 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&coerced);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&coerced);
        }
        if ( (resulta.Flags & 0x1F) > 9 )
        {
          if ( (resulta.Flags >> 9) & 1 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&resulta);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&resulta);
        }
        `eh vector destructor iterator'(
          &ptr,
          0x20ui64,
          3,
          (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
        if ( ++v17 >= (unsigned __int64)LODWORD(v8->ValueA.Data.Size) )
          goto LABEL_47;
      }
      if ( (resulta.Flags & 0x1F) > 9 )
      {
        if ( (resulta.Flags >> 9) & 1 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&resulta);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&resulta);
      }
      `eh vector destructor iterator'(
        &ptr,
        0x20ui64,
        3,
        (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
    }
LABEL_47:
    if ( ((_QWORD)resulta.value.VS._2.VObj & 0x1F) > 9 )
    {
      if ( (LODWORD(resulta.value.VS._2.VObj) >> 9) & 1 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef((Scaleform::GFx::AS3::Value *)((char *)&resulta + 24));
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)((char *)&resulta + 24));
    }
  }
}

// File Line: 507
// RVA: 0x8817D0
void __fastcall Scaleform::GFx::AS3::VectorBase<unsigned long>::Concat<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint>(Scaleform::GFx::AS3::VectorBase<unsigned long> *this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *const argv, Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *currObj)
{
  Scaleform::GFx::AS3::Value *v5; // rdi
  unsigned int v6; // er14
  Scaleform::GFx::AS3::Value *v7; // rbp
  Scaleform::GFx::AS3::VectorBase<unsigned long> *v8; // r13
  Scaleform::GFx::AS3::VM *v9; // r15
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *v10; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v11; // r12
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *v12; // rbx
  unsigned int v13; // ebp
  Scaleform::GFx::AS3::Traits *v14; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v15; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v16; // r14
  Scaleform::GFx::AS3::VM::Error *v17; // rax
  Scaleform::GFx::AS3::VM::Error *v18; // rax
  Scaleform::GFx::AS3::VM::Error *v19; // rax
  Scaleform::GFx::ASStringNode *v20; // rcx
  bool v21; // zf
  Scaleform::GFx::AS3::VM::Error v22; // [rsp+28h] [rbp-40h]
  unsigned int v23; // [rsp+80h] [rbp+18h]

  v23 = argc;
  v5 = argv;
  v6 = argc;
  v7 = result;
  v8 = this;
  v9 = this->VMRef;
  v10 = currObj;
  v11 = (Scaleform::GFx::AS3::ClassTraits::Traits *)Scaleform::GFx::AS3::Traits::GetConstructor(currObj->pTraits.pObject)->pTraits.pObject;
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_uint::MakeInstance(
    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint> *)&currObj,
    (Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_uint *)v10->pTraits.pObject);
  v12 = currObj;
  Scaleform::GFx::AS3::Value::Pick(v7, (Scaleform::GFx::AS3::Object *)&currObj->vfptr);
  Scaleform::GFx::AS3::VectorBase<unsigned long>::Append(&v12->V, &v10->V);
  v13 = 0;
  if ( !v6 )
    return;
  while ( 1 )
  {
    v14 = Scaleform::GFx::AS3::VM::GetValueTraits(v9, v5);
    v15 = Scaleform::GFx::AS3::VM::GetClassTraits(v9, v5);
    v16 = v15;
    if ( !(v14->Flags & 1) )
      break;
    if ( Scaleform::GFx::AS3::ClassTraits::Traits::IsParentTypeOf(
           (Scaleform::GFx::AS3::ClassTraits::Traits *)&v9->TraitsArray.pObject->vfptr,
           v15) )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v22, eNotImplementedError, v8->VMRef);
      Scaleform::GFx::AS3::VM::ThrowError(v8->VMRef, v18);
      goto LABEL_13;
    }
    if ( v11 != v16 )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v22, eCheckTypeFailedError, v8->VMRef);
      Scaleform::GFx::AS3::VM::ThrowTypeError(v8->VMRef, v17);
      goto LABEL_13;
    }
    Scaleform::GFx::AS3::VectorBase<unsigned long>::Append(
      &v12->V,
      (Scaleform::GFx::AS3::VectorBase<unsigned long> *)(*(_QWORD *)&v5->value.VNumber + 56i64));
LABEL_8:
    ++v13;
    ++v5;
    if ( v13 >= v23 )
      return;
  }
  if ( Scaleform::GFx::AS3::ArrayBase::OfCorrectType(
         (Scaleform::GFx::AS3::ArrayBase *)&v8->vfptr,
         (Scaleform::GFx::AS3::CheckResult *)&currObj,
         v5,
         v11)->Result )
  {
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint::PushBack(
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *)v12,
      v5->value.VS._1.VInt);
    goto LABEL_8;
  }
  Scaleform::GFx::AS3::VM::Error::Error(&v22, eCheckTypeFailedError, v8->VMRef);
  Scaleform::GFx::AS3::VM::ThrowTypeError(v8->VMRef, v19);
LABEL_13:
  v20 = v22.Message.pNode;
  v21 = v22.Message.pNode->RefCount == 1;
  --v20->RefCount;
  if ( v21 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v20);
}

// File Line: 558
// RVA: 0x882940
void __fastcall Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Filter<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String>(Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> > *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String> *result, Scaleform::GFx::AS3::Value *callback, Scaleform::GFx::AS3::Value *thisObject, Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *currObj)
{
  Scaleform::GFx::AS3::Value *v5; // r14
  Scaleform::GFx::AS3::Value *v6; // r15
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String> *v7; // rdi
  Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> > *v8; // rsi
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *v9; // rcx
  unsigned int v10; // eax
  int v11; // ecx
  int v12; // ecx
  bool v13; // al
  Scaleform::GFx::AS3::Value *v14; // rcx
  unsigned int v15; // edx
  __int64 v16; // rdi
  char argv; // [rsp+28h] [rbp-71h]
  Scaleform::GFx::AS3::Value _this; // [rsp+38h] [rbp-61h]
  __int64 v19; // [rsp+58h] [rbp-41h]
  Scaleform::GFx::AS3::Value ptr; // [rsp+68h] [rbp-31h]
  int v21; // [rsp+88h] [rbp-11h]
  __int64 v22; // [rsp+90h] [rbp-9h]
  int v23; // [rsp+98h] [rbp-1h]
  Scaleform::GFx::AS3::Value v24; // [rsp+A8h] [rbp+Fh]
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String **retaddr; // [rsp+118h] [rbp+7Fh]

  v19 = -2i64;
  v5 = thisObject;
  v6 = callback;
  v7 = result;
  v8 = this;
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String::MakeInstance(
    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String> *)&currObj,
    retaddr[5]);
  v9 = v7->pObject;
  if ( retaddr != (Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String **)v7->pObject )
  {
    if ( v9 )
    {
      if ( (unsigned __int8)v9 & 1 )
      {
        v7->pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *)((char *)v9 - 1);
      }
      else
      {
        v10 = v9->RefCount;
        if ( v10 & 0x3FFFFF )
        {
          v9->RefCount = v10 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v9->vfptr);
        }
      }
    }
    v7->pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *)retaddr;
  }
  v11 = v6->Flags & 0x1F;
  if ( v11
    && ((unsigned int)(v11 - 12) > 3 && v11 != 10 || *(_QWORD *)&v6->value.VNumber)
    && Scaleform::GFx::AS3::ArrayBase::CheckCallable(
         (Scaleform::GFx::AS3::ArrayBase *)&v8->vfptr,
         (Scaleform::GFx::AS3::CheckResult *)&retaddr,
         v6)->Result )
  {
    v12 = v5->Flags & 0x1F;
    v13 = !v12 || ((unsigned int)(v12 - 12) <= 3 || v12 == 10) && !*(_QWORD *)&v5->value.VNumber;
    v14 = v6;
    if ( !v13 )
      v14 = v5;
    v15 = v14->Flags;
    _this.Flags = v15;
    _this.Bonus.pWeakProxy = v14->Bonus.pWeakProxy;
    _this.value = v14->value;
    if ( (char)(v15 & 0x1F) > 9 )
    {
      if ( (v15 >> 9) & 1 )
        Scaleform::GFx::AS3::Value::AddRefWeakRef(v14);
      else
        Scaleform::GFx::AS3::Value::AddRefInternal(v14);
    }
    v16 = 0i64;
    if ( LODWORD(v8->ValueA.Data.Size) > 0 )
    {
      while ( 1 )
      {
        Scaleform::GFx::AS3::Value::Value(&ptr, v8->ValueA.Data.Data[v16].pObject);
        v21 = 3;
        v22 = 0i64;
        v23 = v16;
        Scaleform::GFx::AS3::Value::Value(&v24, (Scaleform::GFx::AS3::Object *)retaddr);
        LODWORD(_this.Bonus.pWeakProxy) = 0;
        Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(
          v8->VMRef,
          v6,
          &_this,
          (Scaleform::GFx::AS3::Value *)((char *)&_this + 8),
          3u,
          &ptr,
          0);
        if ( v8->VMRef->HandleException )
          break;
        if ( ((_QWORD)_this.Bonus.pWeakProxy & 0x1F) == 1 && argv )
          Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::PushBack(
            (Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *)retaddr,
            v8->ValueA.Data.Data[v16].pObject);
        if ( ((_QWORD)_this.Bonus.pWeakProxy & 0x1F) > 9 )
        {
          if ( (LODWORD(_this.Bonus.pWeakProxy) >> 9) & 1 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef((Scaleform::GFx::AS3::Value *)((char *)&_this + 8));
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)((char *)&_this + 8));
        }
        `eh vector destructor iterator'(
          &ptr,
          0x20ui64,
          3,
          (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
        if ( ++v16 >= (unsigned __int64)LODWORD(v8->ValueA.Data.Size) )
          goto LABEL_41;
      }
      if ( ((_QWORD)_this.Bonus.pWeakProxy & 0x1F) > 9 )
      {
        if ( (LODWORD(_this.Bonus.pWeakProxy) >> 9) & 1 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef((Scaleform::GFx::AS3::Value *)((char *)&_this + 8));
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)((char *)&_this + 8));
      }
      `eh vector destructor iterator'(
        &ptr,
        0x20ui64,
        3,
        (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
    }
LABEL_41:
    if ( (_this.Flags & 0x1F) > 9 )
    {
      if ( (_this.Flags >> 9) & 1 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&_this);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
    }
  }
}

// File Line: 591
// RVA: 0x8867C0
void __fastcall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::Pop<Scaleform::GFx::AS3::Value>(Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *this, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value *v2; // rdi
  Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *v3; // rbx
  Scaleform::GFx::AS3::Value *v4; // rax
  Scaleform::GFx::AS3::Value v5; // [rsp+28h] [rbp-30h]
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+70h] [rbp+18h]

  v2 = result;
  v3 = this;
  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed((Scaleform::GFx::AS3::ArrayBase *)&this->vfptr, &resulta)->Result )
  {
    if ( LODWORD(v3->ValueA.Data.Size) )
    {
      v4 = Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::Pop(
             (Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> > *)&v3->ValueA.Data,
             &v5);
      Scaleform::GFx::AS3::Value::Assign(v2, v4);
      if ( (v5.Flags & 0x1F) > 9 )
      {
        if ( (v5.Flags >> 9) & 1 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v5);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v5);
      }
    }
  }
}

// File Line: 609
// RVA: 0x8F4ED0
void __fastcall Scaleform::GFx::AS3::VectorBase<double>::PushBack(Scaleform::GFx::AS3::VectorBase<double> *this, unsigned int argc, Scaleform::GFx::AS3::Value *const argv, Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  Scaleform::GFx::AS3::ClassTraits::Traits *v4; // r15
  Scaleform::GFx::AS3::Value *v5; // r12
  unsigned int v6; // ebp
  Scaleform::GFx::AS3::VectorBase<double> *v7; // r14
  int v8; // esi
  long double v9; // xmm6_8
  unsigned __int64 v10; // rax
  unsigned __int64 v11; // rdi
  unsigned __int64 v12; // r8
  long double *v13; // rcx
  Scaleform::GFx::AS3::CheckResult result; // [rsp+30h] [rbp-68h]
  __int64 v15; // [rsp+38h] [rbp-60h]
  Scaleform::GFx::AS3::Value coerced; // [rsp+40h] [rbp-58h]

  v15 = -2i64;
  v4 = tr;
  v5 = argv;
  v6 = argc;
  v7 = this;
  if ( !Scaleform::GFx::AS3::ArrayBase::CheckFixed((Scaleform::GFx::AS3::ArrayBase *)&this->vfptr, &result)->Result )
    return;
  v8 = 0;
  if ( !v6 )
    return;
  while ( 1 )
  {
    coerced.Flags = 0;
    coerced.Bonus.pWeakProxy = 0i64;
    if ( !Scaleform::GFx::AS3::ArrayBase::CheckCoerce(
            (Scaleform::GFx::AS3::ArrayBase *)&v7->vfptr,
            &result,
            v4,
            &v5[v8],
            &coerced)->Result )
      break;
    v9 = coerced.value.VNumber;
    v10 = v7->ValueA.Data.Size;
    v11 = v10 + 1;
    if ( v10 + 1 >= v10 )
    {
      if ( v11 > v7->ValueA.Data.Policy.Capacity )
      {
        v12 = v11 + (v11 >> 2);
        goto LABEL_9;
      }
    }
    else if ( v11 < v7->ValueA.Data.Policy.Capacity >> 1 )
    {
      v12 = v10 + 1;
LABEL_9:
      Scaleform::ArrayDataBase<double const *,Scaleform::AllocatorDH<double const *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> *)&v7->ValueA,
        v7->ValueA.Data.pHeap,
        v12);
      goto LABEL_10;
    }
LABEL_10:
    v7->ValueA.Data.Size = v11;
    v13 = &v7->ValueA.Data.Data[v11 - 1];
    if ( v13 )
      *v13 = v9;
    if ( (coerced.Flags & 0x1F) > 9 )
    {
      if ( (coerced.Flags >> 9) & 1 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&coerced);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&coerced);
    }
    if ( ++v8 >= v6 )
      return;
  }
  if ( (coerced.Flags & 0x1F) > 9 )
  {
    if ( (coerced.Flags >> 9) & 1 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&coerced);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&coerced);
  }
}

// File Line: 625
// RVA: 0x916630
void __fastcall Scaleform::GFx::AS3::VectorBase<long>::Unshift(Scaleform::GFx::AS3::VectorBase<unsigned long> *this, unsigned int argc, Scaleform::GFx::AS3::Value *const argv, Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  unsigned __int64 v4; // rbp
  __int64 v5; // rbx
  signed int v6; // edi
  Scaleform::GFx::AS3::ClassTraits::Traits *v7; // r14
  Scaleform::GFx::AS3::Value *v8; // r15
  Scaleform::GFx::AS3::VectorBase<unsigned long> *v9; // rsi
  bool v10; // al
  unsigned __int64 v11; // rdi
  unsigned __int64 v12; // rcx
  unsigned int *v13; // rdx
  Scaleform::GFx::AS3::Value::VU *v14; // rdx
  Scaleform::GFx::AS3::CheckResult result; // [rsp+30h] [rbp-28h]
  Scaleform::GFx::AS3::CheckResult v16; // [rsp+31h] [rbp-27h]
  unsigned int v17; // [rsp+34h] [rbp-24h]

  v4 = argc;
  v5 = 0i64;
  v6 = 1;
  v7 = tr;
  v8 = argv;
  v9 = this;
  v17 = 1;
  v10 = 1;
  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed((Scaleform::GFx::AS3::ArrayBase *)&this->vfptr, &result)->Result )
  {
    v6 = 3;
    v17 = 3;
    if ( Scaleform::GFx::AS3::ArrayBase::CheckCorrectType(
           (Scaleform::GFx::AS3::ArrayBase *)&v9->vfptr,
           &v16,
           v4,
           v8,
           v7)->Result )
      v10 = 0;
  }
  if ( v6 & 2 )
  {
    v6 &= 0xFFFFFFFD;
    v17 = v6;
  }
  if ( v6 & 1 )
    v17 = v6 & 0xFFFFFFFE;
  if ( !v10 )
  {
    v11 = v4;
    Scaleform::ArrayDataDH<unsigned long,Scaleform::AllocatorDH<unsigned long,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      (Scaleform::ArrayDataDH<enum Scaleform::GFx::AS3::XMLParser::Kind,Scaleform::AllocatorDH_POD<enum Scaleform::GFx::AS3::XMLParser::Kind,2>,Scaleform::ArrayDefaultPolicy> *)&v9->ValueA,
      v4 + v9->ValueA.Data.Size);
    if ( v9->ValueA.Data.Size != v4 )
      memmove(&v9->ValueA.Data.Data[v4], v9->ValueA.Data.Data, 4 * (v9->ValueA.Data.Size - v4));
    v12 = 0i64;
    if ( (_DWORD)v4 )
    {
      do
      {
        v13 = &v9->ValueA.Data.Data[v12];
        if ( v13 )
          *v13 = 0;
        ++v12;
      }
      while ( v12 < v4 );
      if ( (_DWORD)v4 )
      {
        v14 = &v8->value;
        do
        {
          ++v5;
          v9->ValueA.Data.Data[v5 - 1] = (unsigned int)v14->VS._1.VStr;
          v14 += 2;
          --v11;
        }
        while ( v11 );
      }
    }
  }
}

// File Line: 641
// RVA: 0x88AF90
void __fastcall Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Shift<Scaleform::GFx::ASString>(Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> > *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *v2; // rbx
  Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> > *v3; // rdi
  Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2>,Scaleform::ArrayDefaultPolicy> > *v4; // rsi
  signed __int64 v5; // rdi
  Scaleform::GFx::ASStringNode *v6; // rcx
  bool v7; // zf
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+40h] [rbp+18h]

  v2 = result;
  v3 = this;
  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed((Scaleform::GFx::AS3::ArrayBase *)&this->vfptr, &resulta)->Result
    && v3->ValueA.Data.Size )
  {
    v4 = (Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2>,Scaleform::ArrayDefaultPolicy> > *)&v3->ValueA.Data;
    v5 = (signed __int64)v3->ValueA.Data.Data->pObject;
    if ( !v5 )
      v5 = (signed __int64)&v2->pNode->pManager->NullStringNode;
    ++*(_DWORD *)(v5 + 24);
    v6 = v2->pNode;
    v7 = v2->pNode->RefCount == 1;
    --v6->RefCount;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v6);
    v2->pNode = (Scaleform::GFx::ASStringNode *)v5;
    Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
      v4,
      0i64);
  }
}

// File Line: 654
// RVA: 0x88C080
void __usercall Scaleform::GFx::AS3::VectorBase<double>::Sort<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double>(Scaleform::GFx::AS3::VectorBase<double> *this@<rcx>, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double> *result@<rdx>, Scaleform::GFx::AS3::Value *arg@<r8>, Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *currObj@<r9>, __int64 a5@<rbx>, __int64 a6@<rsi>)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double> *v6; // r15
  Scaleform::GFx::AS3::VectorBase<double> *v7; // r13
  unsigned __int64 v8; // rdi
  signed int v9; // eax
  Scaleform::GFx::AS3::VM *v10; // rbx
  Scaleform::GFx::AS3::VM::Error *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  bool v13; // zf
  Scaleform::MemoryHeap *v14; // rcx
  int v15; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v16; // rcx
  unsigned __int64 v17; // rsi
  unsigned int v18; // ebx
  __int64 v19; // rcx
  unsigned int v20; // ebx
  signed __int64 v21; // r8
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *v22; // rcx
  unsigned int v23; // eax
  __int64 v24; // rsi
  unsigned __int64 v25; // rcx
  Scaleform::GFx::AS3::Instances::fl::XML **v26; // r14
  unsigned __int64 v27; // rbx
  unsigned __int64 v28; // r8
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v29; // rdx
  void *v30; // rdx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v31; // rcx
  unsigned __int64 v32; // rsi
  unsigned int v33; // ebx
  __int64 v34; // rcx
  unsigned int v35; // ebx
  signed __int64 v36; // rdx
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *v37; // rcx
  unsigned int v38; // eax
  unsigned __int64 v39; // rsi
  __int64 v40; // r14
  unsigned __int64 v41; // rcx
  __int64 v42; // r15
  long double *v43; // r12
  unsigned __int64 v44; // rbx
  unsigned __int64 v45; // r8
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v46; // rdx
  Scaleform::GFx::AS3::VM *v47; // rax
  unsigned __int64 v48; // rsi
  unsigned int v49; // ebx
  __int64 v50; // rcx
  char v51; // r12
  char v52; // si
  char v53; // r14
  unsigned int v54; // ebx
  signed __int64 v55; // rcx
  Scaleform::GFx::ASString *v56; // rcx
  int v57; // eax
  const char *v58; // rdx
  const char *v59; // rcx
  signed __int64 v60; // rdx
  unsigned __int8 v61; // al
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *v62; // rcx
  unsigned int v63; // eax
  Scaleform::GFx::ASStringNode *v64; // rsi
  __int64 v65; // r14
  unsigned __int64 v66; // rcx
  __int64 v67; // r15
  long double *v68; // r12
  unsigned __int64 v69; // rbx
  unsigned __int64 v70; // r8
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v71; // rdx
  Scaleform::GFx::ASStringNode *v72; // rsi
  signed __int64 v73; // rbx
  Scaleform::GFx::ASStringNode *v74; // rcx
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double> *v75; // rax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *v76; // rbx
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *v77; // rcx
  unsigned int v78; // eax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *v79; // rsi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v80; // r14
  unsigned __int64 v81; // rbx
  unsigned __int64 v82; // r8
  Scaleform::GFx::AS3::Instances::fl::XML **v83; // rcx
  unsigned __int64 v84; // rsi
  unsigned __int64 v85; // r8
  __int64 v86; // rbx
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *v87; // rcx
  unsigned int v88; // eax
  unsigned __int64 end; // [rsp+18h] [rbp-79h]
  unsigned __int64 enda; // [rsp+18h] [rbp-79h]
  unsigned __int64 endb; // [rsp+18h] [rbp-79h]
  unsigned __int64 endc; // [rsp+18h] [rbp-79h]
  int v93[2]; // [rsp+20h] [rbp-71h]
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> v94; // [rsp+28h] [rbp-69h]
  void *pheapAddr; // [rsp+40h] [rbp-51h]
  Scaleform::GFx::AS3::VM::Error v96; // [rsp+48h] [rbp-49h]
  __int64 v97; // [rsp+58h] [rbp-39h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v98; // [rsp+60h] [rbp-31h]
  Scaleform::GFx::AS3::Value v99; // [rsp+68h] [rbp-29h]
  __int128 v100; // [rsp+88h] [rbp-9h]
  Scaleform::GFx::AS3::VM::Error *v101; // [rsp+98h] [rbp+7h]
  __int64 v102; // [rsp+A8h] [rbp+17h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double> *v103; // [rsp+100h] [rbp+6Fh]
  Scaleform::GFx::AS3::CheckResult resulta[8]; // [rsp+108h] [rbp+77h]
  __int64 v105; // [rsp+110h] [rbp+7Fh]

  v102 = -2i64;
  v6 = result;
  v7 = this;
  v8 = 0i64;
  v99.Flags = 0;
  v99.Bonus.pWeakProxy = 0i64;
  v93[0] = 0;
  v9 = arg->Flags & 0x1F;
  if ( v9 >= 12 || (unsigned int)(v9 - 5) <= 2 )
  {
    Scaleform::GFx::AS3::Value::Assign(&v99, arg);
LABEL_7:
    v14 = v7->VMRef->MHeap;
    *(_QWORD *)&resulta[0].Result = &v94;
    v94.Data = 0i64;
    v94.Size = 0i64;
    v94.Policy.Capacity = 0i64;
    pheapAddr = v14;
    v15 = v99.Flags & 0x1F;
    if ( v99.Flags & 0x1F && ((unsigned int)(v15 - 12) > 3 && v15 != 10 || *(_QWORD *)&v99.value.VNumber) )
    {
      v16 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)v7->VMRef->MHeap;
      *(_QWORD *)&resulta[0].Result = &v96;
      *(_QWORD *)&v96.ID = 0i64;
      end = 0i64;
      *(_QWORD *)v93 = 0i64;
      v94.Data = v16;
      v94.Size = (unsigned __int64)&Scaleform::GFx::AS3::VectorBase<double>::ValuePtrCollector::`vftable';
      v94.Policy.Capacity = (unsigned __int64)&v96;
      v17 = v7->ValueA.Data.Size;
      v18 = 0;
      if ( v17 )
      {
        v19 = 0i64;
        do
        {
          (*(void (__fastcall **)(unsigned __int64 *, _QWORD, long double *))(v94.Size + 8))(
            &v94.Size,
            v18++,
            &v7->ValueA.Data.Data[v19]);
          v19 = v18;
        }
        while ( v18 < v17 );
      }
      *(_QWORD *)&v96.ID = v7->VMRef;
      v96.Message.pNode = (Scaleform::GFx::ASStringNode *)&v99;
      _mm_store_si128((__m128i *)&v100, (__m128i)v96);
      Scaleform::Alg::QuickSortSlicedSafe<Scaleform::ArrayDH<double const *,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::AS3::VectorBase<double>::CompareValuePtr>(
        (Scaleform::ArrayDH<double const *,2,Scaleform::ArrayDefaultPolicy> *)&v96,
        0i64,
        end,
        (Scaleform::GFx::AS3::VectorBase<double>::CompareValuePtr *)&v100);
      if ( v93[0] & 4 )
      {
        v20 = 1;
        if ( enda > 1 )
        {
          v21 = 1i64;
          while ( !Scaleform::GFx::AS3::VectorBase<double>::CompareValuePtr::Equal(
                     (Scaleform::GFx::AS3::VectorBase<double>::CompareValuePtr *)&v96,
                     *(const long double **)(*(_QWORD *)&v96.ID + 8i64 * (v20 - 1)),
                     *(const long double **)(*(_QWORD *)&v96.ID + 8 * v21)) )
          {
            v21 = ++v20;
            if ( v20 >= enda )
              goto LABEL_27;
          }
          v22 = v6->pObject;
          if ( v6->pObject )
          {
            if ( (unsigned __int8)v22 & 1 )
            {
              v6->pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *)((char *)v22 - 1);
            }
            else
            {
              v23 = v22->RefCount;
              if ( v23 & 0x3FFFFF )
              {
                v22->RefCount = v23 - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v22->vfptr);
              }
            }
            v6->pObject = 0i64;
          }
          v94.Size = (unsigned __int64)&Scaleform::GFx::AS3::VectorBase<double>::ArrayFunc::`vftable';
          *(_QWORD *)&resulta[0].Result = &v96;
LABEL_56:
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, *(void **)&v96.ID);
LABEL_99:
          *(_QWORD *)&resulta[0].Result = &v94;
LABEL_155:
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v94.Data);
          goto LABEL_156;
        }
      }
LABEL_27:
      v24 = 0i64;
      if ( enda <= 0 )
      {
LABEL_38:
        v94.Size = (unsigned __int64)&Scaleform::GFx::AS3::VectorBase<double>::ArrayFunc::`vftable';
        *(_QWORD *)&resulta[0].Result = &v96;
        v30 = *(void **)&v96.ID;
        goto LABEL_117;
      }
      v25 = v94.Size;
      while ( 1 )
      {
        v26 = *(Scaleform::GFx::AS3::Instances::fl::XML ***)(*(_QWORD *)&v96.ID + 8 * v24);
        v27 = v25 + 1;
        if ( v25 + 1 >= v25 )
        {
          if ( v27 > v94.Policy.Capacity )
          {
            v28 = v27 + (v27 >> 2);
            goto LABEL_34;
          }
        }
        else if ( v27 < v94.Policy.Capacity >> 1 )
        {
          v28 = v25 + 1;
LABEL_34:
          Scaleform::ArrayDataBase<double const *,Scaleform::AllocatorDH<double const *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            &v94,
            pheapAddr,
            v28);
          goto LABEL_35;
        }
LABEL_35:
        v25 = v27;
        v94.Size = v27;
        v29 = &v94.Data[v27 - 1];
        if ( v29 )
        {
          v29->pObject = *v26;
          v25 = v94.Size;
        }
        if ( ++v24 >= enda )
          goto LABEL_38;
      }
    }
    v31 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)v7->VMRef->MHeap;
    if ( v93[0] & 0x10 )
    {
      *(_QWORD *)&resulta[0].Result = &v96;
      *(_QWORD *)&v96.ID = 0i64;
      endb = 0i64;
      *(_QWORD *)v93 = 0i64;
      v94.Data = v31;
      v94.Size = (unsigned __int64)&Scaleform::GFx::AS3::VectorBase<double>::Value2NumberCollector::`vftable';
      v94.Policy.Capacity = (unsigned __int64)&v96;
      v32 = v7->ValueA.Data.Size;
      v33 = 0;
      if ( v32 )
      {
        v34 = 0i64;
        do
        {
          (*(void (__fastcall **)(unsigned __int64 *, _QWORD, long double *))(v94.Size + 8))(
            &v94.Size,
            v33++,
            &v7->ValueA.Data.Data[v34]);
          v34 = v33;
        }
        while ( v33 < v32 );
      }
      Scaleform::Alg::QuickSortSlicedSafe<Scaleform::ArrayDH<Scaleform::Pair<double,unsigned long>,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::AS3::Impl::CompareAsNumberInd>(
        (Scaleform::ArrayDH<Scaleform::Pair<double,unsigned long>,2,Scaleform::ArrayDefaultPolicy> *)&v96,
        0i64,
        endb,
        (Scaleform::GFx::AS3::Impl::CompareAsNumberInd)(((unsigned int)v93[0] >> 1) & 1));
      if ( v93[0] & 4 )
      {
        v35 = 1;
        if ( endc > 1 )
        {
          v36 = 1i64;
          while ( *(double *)(*(_QWORD *)&v96.ID + 16 * v36) != *(double *)(*(_QWORD *)&v96.ID + 16i64 * (v35 - 1)) )
          {
            v36 = ++v35;
            if ( v35 >= endc )
              goto LABEL_57;
          }
          v37 = v6->pObject;
          if ( v6->pObject )
          {
            if ( (unsigned __int8)v37 & 1 )
            {
              v6->pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *)((char *)v37 - 1);
            }
            else
            {
              v38 = v37->RefCount;
              if ( v38 & 0x3FFFFF )
              {
                v37->RefCount = v38 - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v37->vfptr);
              }
            }
            v6->pObject = 0i64;
          }
          v94.Size = (unsigned __int64)&Scaleform::GFx::AS3::VectorBase<double>::ArrayFunc::`vftable';
          *(_QWORD *)&resulta[0].Result = &v96;
          goto LABEL_56;
        }
      }
LABEL_57:
      v39 = 0i64;
      if ( endc <= 0 )
        goto LABEL_69;
      v40 = 0i64;
      v41 = v94.Size;
      while ( 1 )
      {
        v42 = *(unsigned int *)(*(_QWORD *)&v96.ID + v40 + 8);
        v43 = v7->ValueA.Data.Data;
        v44 = v41 + 1;
        if ( v41 + 1 >= v41 )
        {
          if ( v44 > v94.Policy.Capacity )
          {
            v45 = v44 + (v44 >> 2);
            goto LABEL_64;
          }
        }
        else if ( v44 < v94.Policy.Capacity >> 1 )
        {
          v45 = v41 + 1;
LABEL_64:
          Scaleform::ArrayDataBase<double const *,Scaleform::AllocatorDH<double const *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            &v94,
            pheapAddr,
            v45);
          goto LABEL_65;
        }
LABEL_65:
        v41 = v44;
        v94.Size = v44;
        v46 = &v94.Data[v44 - 1];
        if ( v46 )
        {
          v46->pObject = *(Scaleform::GFx::AS3::Instances::fl::XML **)&v43[v42];
          v41 = v94.Size;
        }
        ++v39;
        v40 += 16i64;
        if ( v39 >= endc )
        {
          v6 = v103;
LABEL_69:
          v94.Size = (unsigned __int64)&Scaleform::GFx::AS3::VectorBase<double>::ArrayFunc::`vftable';
          *(_QWORD *)&resulta[0].Result = &v96;
          v30 = *(void **)&v96.ID;
LABEL_117:
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v30);
          if ( v93[0] & 8 )
          {
            v75 = Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_double::MakeInstance(
                    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double> *)resulta,
                    *(Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_double **)(v105 + 40));
            v76 = v75->pV;
            v77 = v6->pObject;
            if ( v75->pV != v6->pObject )
            {
              if ( v77 )
              {
                if ( (unsigned __int8)v77 & 1 )
                {
                  v6->pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *)((char *)v77 - 1);
                }
                else
                {
                  v78 = v77->RefCount;
                  if ( v78 & 0x3FFFFF )
                  {
                    v77->RefCount = v78 - 1;
                    Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v77->vfptr);
                  }
                }
              }
              v6->pObject = v76;
            }
            v79 = v6->pObject;
            if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(
                   (Scaleform::GFx::AS3::ArrayBase *)&v6->pObject->V.vfptr,
                   resulta)->Result
              && v94.Size )
            {
              do
              {
                v80 = v94.Data;
                v81 = v79->V.ValueA.Data.Size + 1;
                if ( v81 >= v79->V.ValueA.Data.Size )
                {
                  if ( v81 > v79->V.ValueA.Data.Policy.Capacity )
                  {
                    v82 = v81 + (v81 >> 2);
                    goto LABEL_132;
                  }
                }
                else if ( v81 < v79->V.ValueA.Data.Policy.Capacity >> 1 )
                {
                  v82 = v79->V.ValueA.Data.Size + 1;
LABEL_132:
                  Scaleform::ArrayDataBase<double const *,Scaleform::AllocatorDH<double const *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> *)&v79->V.ValueA,
                    v79->V.ValueA.Data.pHeap,
                    v82);
                  goto LABEL_133;
                }
LABEL_133:
                v79->V.ValueA.Data.Size = v81;
                v83 = (Scaleform::GFx::AS3::Instances::fl::XML **)&v79->V.ValueA.Data.Data[v81 - 1];
                if ( v83 )
                  *v83 = v80[v8].pObject;
                ++v8;
              }
              while ( v8 < v94.Size );
            }
LABEL_154:
            *(_QWORD *)&resulta[0].Result = &v94;
            goto LABEL_155;
          }
          v84 = v94.Size;
          if ( v94.Size >= v7->ValueA.Data.Size )
          {
            if ( v94.Size > v7->ValueA.Data.Policy.Capacity )
            {
              v85 = v94.Size + (v94.Size >> 2);
LABEL_142:
              Scaleform::ArrayDataBase<double const *,Scaleform::AllocatorDH<double const *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> *)&v7->ValueA,
                v7->ValueA.Data.pHeap,
                v85);
            }
          }
          else if ( v94.Size < v7->ValueA.Data.Policy.Capacity >> 1 )
          {
            v85 = v94.Size;
            goto LABEL_142;
          }
          v7->ValueA.Data.Size = v84;
          if ( v84 )
          {
            do
            {
              *(_QWORD *)&v7->ValueA.Data.Data[v8] = v94.Data[v8].pObject;
              ++v8;
            }
            while ( v8 < v7->ValueA.Data.Size );
          }
          v86 = v105;
          if ( (Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *)v105 != v6->pObject )
          {
            if ( v105 )
              *(_DWORD *)(v105 + 32) = (*(_DWORD *)(v105 + 32) + 1) & 0x8FBFFFFF;
            v87 = v6->pObject;
            if ( v6->pObject )
            {
              if ( (unsigned __int8)v87 & 1 )
              {
                v6->pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *)((char *)v87 - 1);
              }
              else
              {
                v88 = v87->RefCount;
                if ( v88 & 0x3FFFFF )
                {
                  v87->RefCount = v88 - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v87->vfptr);
                }
              }
            }
            v6->pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *)v86;
          }
          goto LABEL_154;
        }
      }
    }
    *(_QWORD *)&resulta[0].Result = &v96;
    *(_QWORD *)&v96.ID = 0i64;
    v96.Message.pNode = 0i64;
    v97 = 0i64;
    v98 = v31;
    v47 = v7->VMRef;
    *(_QWORD *)&v100 = &Scaleform::GFx::AS3::VectorBase<double>::Value2StrCollector::`vftable';
    *((_QWORD *)&v100 + 1) = v47;
    v101 = &v96;
    v48 = v7->ValueA.Data.Size;
    v49 = 0;
    if ( v48 )
    {
      v50 = 0i64;
      do
      {
        (*(void (__fastcall **)(__int128 *, _QWORD, long double *))(v100 + 8))(&v100, v49++, &v7->ValueA.Data.Data[v50]);
        v50 = v49;
      }
      while ( v49 < v48 );
    }
    v51 = ((unsigned int)v93[0] >> 10) & 1;
    v52 = v93[0] & 1;
    v53 = ((unsigned int)v93[0] >> 1) & 1;
    resulta[0].Result = ((unsigned int)v93[0] >> 1) & 1;
    resulta[1].Result = v93[0] & 1;
    resulta[2].Result = ((unsigned int)v93[0] >> 10) & 1;
    Scaleform::Alg::QuickSortSlicedSafe<Scaleform::ArrayDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::AS3::Impl::CompareAsStringInd>(
      (Scaleform::ArrayDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2,Scaleform::ArrayDefaultPolicy> *)&v96,
      0i64,
      (unsigned __int64)v96.Message.pNode,
      (Scaleform::GFx::AS3::Impl::CompareAsStringInd *)resulta);
    if ( v93[0] & 4 )
    {
      v54 = 1;
      if ( v96.Message.pNode > (Scaleform::GFx::ASStringNode *)1 )
      {
        v55 = 1i64;
        while ( 1 )
        {
          v56 = (Scaleform::GFx::ASString *)(*(_QWORD *)&v96.ID + 16 * v55);
          if ( v51 )
          {
            v57 = v53 ? Scaleform::GFx::ASString::LocaleCompare_CaseCheck(
                          v56,
                          (Scaleform::GFx::ASString *)(*(_QWORD *)&v96.ID + 16i64 * (v54 - 1)),
                          v52 == 0) : Scaleform::GFx::ASString::LocaleCompare_CaseCheck(
                                        (Scaleform::GFx::ASString *)(*(_QWORD *)&v96.ID + 16i64 * (v54 - 1)),
                                        v56,
                                        v52 == 0);
          }
          else
          {
            v58 = v56->pNode->pData;
            v59 = **(const char ***)(*(_QWORD *)&v96.ID + 16i64 * (v54 - 1));
            if ( v52 )
            {
              v57 = Scaleform::String::CompareNoCase(v59, v58);
            }
            else
            {
              v60 = v58 - v59;
              while ( 1 )
              {
                v61 = *v59;
                if ( *v59 != v59[v60] )
                  break;
                ++v59;
                if ( !v61 )
                {
                  v57 = 0;
                  goto LABEL_87;
                }
              }
              v57 = -(v61 < v59[v60]) | 1;
            }
LABEL_87:
            if ( v53 )
              v57 = -v57;
          }
          if ( !v57 )
            break;
          v55 = ++v54;
          if ( (Scaleform::GFx::ASStringNode *)v54 >= v96.Message.pNode )
            goto LABEL_100;
        }
        v62 = v6->pObject;
        if ( v6->pObject )
        {
          if ( (unsigned __int8)v62 & 1 )
          {
            v6->pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *)((char *)v62 - 1);
          }
          else
          {
            v63 = v62->RefCount;
            if ( v63 & 0x3FFFFF )
            {
              v62->RefCount = v63 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v62->vfptr);
            }
          }
          v6->pObject = 0i64;
        }
        *(_QWORD *)&v100 = &Scaleform::GFx::AS3::VectorBase<double>::ArrayFunc::`vftable';
        *(_QWORD *)&resulta[0].Result = &v96;
        Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&v96);
        goto LABEL_99;
      }
    }
LABEL_100:
    v64 = 0i64;
    if ( v96.Message.pNode <= 0 )
      goto LABEL_112;
    v65 = 0i64;
    v66 = v94.Size;
    while ( 1 )
    {
      v67 = *(unsigned int *)(v65 + *(_QWORD *)&v96.ID + 8);
      v68 = v7->ValueA.Data.Data;
      v69 = v66 + 1;
      if ( v66 + 1 >= v66 )
      {
        if ( v69 > v94.Policy.Capacity )
        {
          v70 = v69 + (v69 >> 2);
          goto LABEL_107;
        }
      }
      else if ( v69 < v94.Policy.Capacity >> 1 )
      {
        v70 = v66 + 1;
LABEL_107:
        Scaleform::ArrayDataBase<double const *,Scaleform::AllocatorDH<double const *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &v94,
          pheapAddr,
          v70);
        goto LABEL_108;
      }
LABEL_108:
      v66 = v69;
      v94.Size = v69;
      v71 = &v94.Data[v69 - 1];
      if ( v71 )
      {
        v71->pObject = *(Scaleform::GFx::AS3::Instances::fl::XML **)&v68[v67];
        v66 = v94.Size;
      }
      v64 = (Scaleform::GFx::ASStringNode *)((char *)v64 + 1);
      v65 += 16i64;
      if ( v64 >= v96.Message.pNode )
      {
        v6 = v103;
LABEL_112:
        *(_QWORD *)&v100 = &Scaleform::GFx::AS3::VectorBase<double>::ArrayFunc::`vftable';
        v72 = v96.Message.pNode;
        v30 = *(void **)&v96.ID;
        v73 = 16i64 * (_QWORD)v96.Message.pNode + *(_QWORD *)&v96.ID - 16i64;
        *(_QWORD *)&resulta[0].Result = 16i64 * (_QWORD)v96.Message.pNode + *(_QWORD *)&v96.ID - 16i64;
        if ( v96.Message.pNode )
        {
          do
          {
            v74 = *(Scaleform::GFx::ASStringNode **)v73;
            v13 = *(_DWORD *)(*(_QWORD *)v73 + 24i64) == 1;
            --v74->RefCount;
            if ( v13 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v74);
            v73 -= 16i64;
            *(_QWORD *)&resulta[0].Result = v73;
            v72 = (Scaleform::GFx::ASStringNode *)((char *)v72 - 1);
          }
          while ( v72 );
          v30 = *(void **)&v96.ID;
        }
        goto LABEL_117;
      }
    }
  }
  if ( Scaleform::GFx::AS3::Value::Convert2Int32(arg, resulta, v93, a5, 0i64, a6)->Result )
    goto LABEL_7;
  v10 = v7->VMRef;
  Scaleform::GFx::AS3::VM::Error::Error(&v96, eCheckTypeFailedError, v7->VMRef);
  Scaleform::GFx::AS3::VM::ThrowTypeError(v10, v11);
  v12 = v96.Message.pNode;
  v13 = v96.Message.pNode->RefCount == 1;
  --v12->RefCount;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
LABEL_156:
  if ( (v99.Flags & 0x1F) > 9 )
  {
    if ( (v99.Flags >> 9) & 1 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v99);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v99);
  }
}

// File Line: 801
// RVA: 0x88B250
void __fastcall Scaleform::GFx::AS3::VectorBase<long>::Slice<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int>(Scaleform::GFx::AS3::VectorBase<long> *this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *const argv, Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *currObj)
{
  Scaleform::GFx::AS3::Value *v5; // rdi
  Scaleform::GFx::AS3::VectorBase<long> *v6; // r13
  Scaleform::GFx::AS3::Value *v7; // rbp
  unsigned int v8; // er14
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *v9; // rbx
  signed int v10; // edx
  __int64 v11; // rsi
  bool v12; // sf
  unsigned __int64 v13; // rax
  signed __int64 v14; // r14
  int v15; // ebp
  unsigned __int64 v16; // rax
  unsigned __int64 v17; // rdi
  unsigned __int64 v18; // r8
  int *v19; // rcx
  int *v20; // rcx
  int v21; // [rsp+20h] [rbp-38h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int> resulta; // [rsp+28h] [rbp-30h]
  Scaleform::GFx::AS3::CheckResult v23; // [rsp+70h] [rbp+18h]

  v5 = result;
  v6 = this;
  v7 = argv;
  v8 = argc;
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_int::MakeInstance(
    &resulta,
    (Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_int *)currObj->pTraits.pObject);
  v9 = resulta.pV;
  Scaleform::GFx::AS3::Value::Pick(v5, (Scaleform::GFx::AS3::Object *)&resulta.pV->vfptr);
  v10 = 0xFFFFFF;
  v11 = 0i64;
  v21 = 0;
  LODWORD(currObj) = 0xFFFFFF;
  if ( v8 )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2Int32(v7, &v23, &v21, (__int64)v9, 0i64, 0i64)->Result )
      return;
    v11 = (unsigned int)v21;
    v10 = (signed int)currObj;
  }
  if ( v8 > 1 )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2Int32(v7 + 1, &v23, (int *)&currObj, (__int64)v9, 0i64, v11)->Result )
      return;
    LODWORD(v11) = v21;
    v10 = (signed int)currObj;
  }
  v12 = (signed int)v11 < 0;
  if ( (signed int)v11 < 0 )
  {
    LODWORD(v11) = LODWORD(v6->ValueA.Data.Size) + v11;
    v12 = (signed int)v11 < 0;
  }
  if ( v12 )
    LODWORD(v11) = 0;
  v21 = v11;
  if ( v10 < 0 )
    v10 += LODWORD(v6->ValueA.Data.Size);
  v13 = v6->ValueA.Data.Size;
  if ( (signed int)v13 < v10 )
    v10 = v13;
  LODWORD(currObj) = v10;
  if ( (signed int)v11 < v10 )
  {
    v14 = (signed int)v11;
    while ( 1 )
    {
      v15 = v6->ValueA.Data.Data[v14];
      if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed((Scaleform::GFx::AS3::ArrayBase *)&v9->V.vfptr, &v23)->Result )
        break;
LABEL_26:
      LODWORD(v11) = v11 + 1;
      ++v14;
      if ( (signed int)v11 >= (signed int)currObj )
        return;
    }
    v16 = v9->V.ValueA.Data.Size;
    v17 = v16 + 1;
    if ( v16 + 1 >= v16 )
    {
      if ( v17 <= v9->V.ValueA.Data.Policy.Capacity )
        goto LABEL_24;
      v18 = v17 + (v17 >> 2);
    }
    else
    {
      if ( v17 >= v9->V.ValueA.Data.Policy.Capacity >> 1 )
        goto LABEL_24;
      v18 = v16 + 1;
    }
    Scaleform::ArrayDataBase<unsigned long,Scaleform::AllocatorDH<unsigned long,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<enum Scaleform::GFx::AS3::XMLParser::Kind,Scaleform::AllocatorDH_POD<enum Scaleform::GFx::AS3::XMLParser::Kind,2>,Scaleform::ArrayDefaultPolicy> *)&v9->V.ValueA,
      v9->V.ValueA.Data.pHeap,
      v18);
LABEL_24:
    v19 = v9->V.ValueA.Data.Data;
    v9->V.ValueA.Data.Size = v17;
    v20 = &v19[v17 - 1];
    if ( v20 )
      *v20 = v15;
    goto LABEL_26;
  }
}

// File Line: 836
// RVA: 0x88ED90
void __usercall Scaleform::GFx::AS3::VectorBase<unsigned long>::Splice<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint>(Scaleform::GFx::AS3::VectorBase<unsigned long> *this@<rcx>, Scaleform::GFx::AS3::Value *result@<rdx>, unsigned int argc@<r8d>, Scaleform::GFx::AS3::Value *const argv@<r9>, __int64 a5@<rbx>, __int64 a6@<rdi>, Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *currObj)
{
  Scaleform::GFx::AS3::Value *v7; // r14
  unsigned int v8; // ebp
  Scaleform::GFx::AS3::Value *v9; // r15
  Scaleform::GFx::AS3::VectorBase<unsigned long> *v10; // rsi
  int v11; // er9
  unsigned __int64 v12; // rdi
  Scaleform::GFx::AS3::VM::Error *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  bool v15; // zf
  unsigned __int64 v16; // rax
  int v17; // ecx
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+20h] [rbp-38h]
  int v19; // [rsp+24h] [rbp-34h]
  unsigned int v20; // [rsp+28h] [rbp-30h]
  Scaleform::GFx::AS3::VM::Error v21; // [rsp+30h] [rbp-28h]
  __int64 v22; // [rsp+40h] [rbp-18h]

  v22 = -2i64;
  v7 = argv;
  v8 = argc;
  v9 = result;
  v10 = this;
  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed((Scaleform::GFx::AS3::ArrayBase *)&this->vfptr, &resulta)->Result )
  {
    v11 = 0;
    v19 = 0;
    if ( v8 )
    {
      if ( !Scaleform::GFx::AS3::Value::Convert2Int32(v7, &resulta, &v19, a5, a6, (__int64)v10)->Result )
        return;
      v11 = v19;
    }
    v12 = v10->ValueA.Data.Size;
    v20 = 0;
    if ( v11 < 0 )
    {
      v11 += v12;
      v19 = v11;
    }
    if ( v8 <= 1 )
    {
      v20 = v12 - v11;
    }
    else
    {
      if ( !Scaleform::GFx::AS3::Value::Convert2UInt32(v7 + 1, &resulta, &v20)->Result )
        return;
      if ( (signed int)(v19 + v20) < 0 || v19 + v20 > (unsigned int)v12 )
      {
        Scaleform::GFx::AS3::VM::Error::Error(&v21, eOutOfRangeError, v10->VMRef);
        Scaleform::GFx::AS3::VM::ThrowRangeError(v10->VMRef, v13);
        v14 = v21.Message.pNode;
        v15 = v21.Message.pNode->RefCount == 1;
        --v14->RefCount;
        if ( v15 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v14);
        return;
      }
    }
    Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_uint::MakeInstance(
      (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint> *)&v21,
      (Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_uint *)currObj->pTraits.pObject);
    Scaleform::GFx::AS3::Value::Pick(v9, *(Scaleform::GFx::AS3::Object **)&v21.ID);
    if ( v19 <= (signed int)v12 && v19 >= 0 )
    {
      Scaleform::GFx::AS3::VectorBase<unsigned long>::DeleteMultipleAt<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint>(
        v10,
        v19,
        v20,
        *(Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint **)&v21.ID);
      if ( v8 > 2 )
      {
        v16 = v10->ValueA.Data.Size;
        v17 = v19;
        if ( (signed int)v16 < v19 )
          v17 = v10->ValueA.Data.Size;
        v19 = v17;
        Scaleform::GFx::AS3::VectorBase<unsigned long>::Insert(v10, v17, v8 - 2, v7 + 2);
      }
    }
  }
}

// File Line: 933
// RVA: 0x8CDB30
void __fastcall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::ForEachChild_GC(Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *this, Scaleform::GFx::AS3::RefCountCollector<328> *prcc, void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  unsigned __int64 v3; // rdi
  void (__fastcall *v4)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **); // rbp
  Scaleform::GFx::AS3::RefCountCollector<328> *v5; // r14
  Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *v6; // rsi
  __int64 v7; // rbx
  Scaleform::GFx::AS3::Value *v8; // rdx

  v3 = this->ValueA.Data.Size;
  v4 = op;
  v5 = prcc;
  v6 = this;
  if ( v3 )
  {
    v7 = 0i64;
    do
    {
      v8 = &v6->ValueA.Data.Data[v7];
      if ( (v8->Flags & 0x1F) > 10 && !((v8->Flags >> 9) & 1) )
        Scaleform::GFx::AS3::ForEachChild_GC_Internal(v5, v8, v4);
      ++v7;
      --v3;
    }
    while ( v3 );
  }
}

// File Line: 941
// RVA: 0x881C40
void __fastcall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::DeleteMultipleAt<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object>(Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *this, unsigned __int64 pos, unsigned __int64 count, Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *deleted)
{
  unsigned __int64 v4; // rbx
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *v5; // r13
  unsigned __int64 v6; // r14
  unsigned __int64 v7; // r15
  Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *v8; // rsi
  unsigned __int64 v9; // rdi
  Scaleform::GFx::AS3::Value *v10; // r12
  Scaleform::GFx::AS3::CheckResult result; // [rsp+50h] [rbp+8h]

  v4 = 0i64;
  v5 = deleted;
  v6 = count;
  v7 = pos;
  v8 = this;
  if ( count )
  {
    v9 = pos;
    do
    {
      if ( v4 + v7 >= v8->ValueA.Data.Size )
        break;
      v10 = &v8->ValueA.Data.Data[v9];
      if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed((Scaleform::GFx::AS3::ArrayBase *)&v5->V.vfptr, &result)->Result )
        Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
          &v5->V.ValueA.Data,
          v10);
      ++v4;
      ++v9;
    }
    while ( v4 < v6 );
  }
  Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::RemoveMultipleAt(
    (Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> > *)&v8->ValueA.Data,
    v7,
    v6);
}

// File Line: 950
// RVA: 0x8E5D40
void __fastcall Scaleform::GFx::AS3::VectorBase<unsigned long>::Insert(Scaleform::GFx::AS3::VectorBase<unsigned long> *this, unsigned __int64 pos, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  unsigned __int64 v4; // rsi
  Scaleform::GFx::AS3::Value::VU *v5; // r15
  __int64 v6; // rbp
  Scaleform::ArrayDataBase<enum Scaleform::GFx::AS3::XMLParser::Kind,Scaleform::AllocatorDH_POD<enum Scaleform::GFx::AS3::XMLParser::Kind,2>,Scaleform::ArrayDefaultPolicy> *v7; // rdi
  unsigned __int64 v8; // r14
  unsigned __int64 v9; // rax
  Scaleform::GFx::AS3::XMLParser::Kind v10; // er12
  unsigned __int64 v11; // rbx
  unsigned __int64 v12; // r8
  Scaleform::GFx::AS3::XMLParser::Kind *v13; // rcx

  if ( argc )
  {
    v4 = pos;
    v5 = &argv->value;
    v6 = argc;
    v7 = (Scaleform::ArrayDataBase<enum Scaleform::GFx::AS3::XMLParser::Kind,Scaleform::AllocatorDH_POD<enum Scaleform::GFx::AS3::XMLParser::Kind,2>,Scaleform::ArrayDefaultPolicy> *)&this->ValueA;
    v8 = pos;
    do
    {
      v9 = v7->Size;
      v10 = (Scaleform::GFx::AS3::XMLParser::Kind)v5->VS._1.VStr;
      v11 = v9 + 1;
      if ( v9 + 1 >= v9 )
      {
        if ( v11 > v7->Policy.Capacity )
        {
          v12 = v11 + (v11 >> 2);
          goto LABEL_8;
        }
      }
      else if ( v11 < v7->Policy.Capacity >> 1 )
      {
        v12 = v9 + 1;
LABEL_8:
        Scaleform::ArrayDataBase<unsigned long,Scaleform::AllocatorDH<unsigned long,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          v7,
          v7[1].Data,
          v12);
        goto LABEL_9;
      }
LABEL_9:
      v7->Size = v11;
      if ( v4 < v11 - 1 )
        memmove(&v7->Data[v8 + 1], &v7->Data[v8], 4 * (v11 - v4) - 4);
      v13 = &v7->Data[v8];
      if ( v13 )
        *v13 = v10;
      ++v8;
      v5 += 2;
      ++v4;
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 961
// RVA: 0x90E7E0
void __fastcall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::SetUnsafe(Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *this, unsigned int ind, Scaleform::GFx::AS3::Value *v)
{
  __int64 v3; // rbx
  Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *v4; // rdi
  unsigned int v5; // er9
  Scaleform::GFx::AS3::Value other; // [rsp+28h] [rbp-30h]

  v3 = ind;
  v4 = this;
  v5 = v->Flags;
  other.Flags = v5;
  other.Bonus.pWeakProxy = v->Bonus.pWeakProxy;
  other.value = v->value;
  if ( (char)(v5 & 0x1F) > 9 )
  {
    if ( (v5 >> 9) & 1 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(v);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(v);
  }
  Scaleform::GFx::AS3::Value::Assign(&v4->ValueA.Data.Data[v3], &other);
  if ( (other.Flags & 0x1F) > 9 )
  {
    if ( (other.Flags >> 9) & 1 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&other);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
  }
}

// File Line: 966
// RVA: 0x8F5580
void __fastcall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::PushBackUnsafe(Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *this, Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *v2; // rbx
  unsigned int v3; // er8
  Scaleform::GFx::AS3::Value val; // [rsp+28h] [rbp-30h]

  v2 = this;
  v3 = v->Flags;
  val.Flags = v3;
  val.Bonus.pWeakProxy = v->Bonus.pWeakProxy;
  val.value = v->value;
  if ( (char)(v3 & 0x1F) > 9 )
  {
    if ( (v3 >> 9) & 1 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(v);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(v);
  }
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
    &v2->ValueA.Data,
    &val);
  if ( (val.Flags & 0x1F) > 9 )
  {
    if ( (val.Flags >> 9) & 1 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&val);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&val);
  }
}

// File Line: 970
// RVA: 0x8F5620
void __fastcall Scaleform::GFx::AS3::VectorBase<long>::PushBackValueUnsafe(Scaleform::GFx::AS3::VectorBase<unsigned long> *this, Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::VectorBase<unsigned long>::PushBackUnsafe(this, v);
}

// File Line: 987
// RVA: 0x8E36D0
void __fastcall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::IndexOf(Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *this, int *result, Scaleform::GFx::AS3::Value *searchElement, int fromIndex)
{
  unsigned __int64 v4; // rbx
  Scaleform::GFx::AS3::Value *v5; // rbp
  int *v6; // r14
  Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *v7; // rsi
  signed __int64 v8; // rdi

  v4 = fromIndex;
  v5 = searchElement;
  v6 = result;
  v7 = this;
  if ( fromIndex >= (unsigned __int64)LODWORD(this->ValueA.Data.Size) )
  {
LABEL_5:
    *v6 = -1;
  }
  else
  {
    v8 = fromIndex;
    while ( !Scaleform::GFx::AS3::StrictEqual(&v7->ValueA.Data.Data[v8], v5) )
    {
      ++v4;
      ++v8;
      if ( v4 >= LODWORD(v7->ValueA.Data.Size) )
        goto LABEL_5;
    }
    *v6 = v4;
  }
}

// File Line: 1003
// RVA: 0x8E80F0
void __fastcall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::LastIndexOf(Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *this, int *result, Scaleform::GFx::AS3::Value *searchElement, int fromIndex)
{
  Scaleform::GFx::AS3::Value *v4; // rbp
  signed __int64 v5; // rbx
  int *v6; // r14
  Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *v7; // rsi
  signed __int64 v8; // rdi

  v4 = searchElement;
  v5 = LODWORD(this->ValueA.Data.Size) - 1i64;
  v6 = result;
  v7 = this;
  if ( fromIndex < v5 )
    v5 = fromIndex;
  if ( v5 < 0 )
  {
LABEL_7:
    *v6 = -1;
  }
  else
  {
    v8 = v5;
    while ( !Scaleform::GFx::AS3::StrictEqual(&v7->ValueA.Data.Data[v8], v4) )
    {
      --v8;
      if ( --v5 < 0 )
        goto LABEL_7;
    }
    *v6 = v5;
  }
}

// File Line: 1026
// RVA: 0x8F54F0
void __fastcall Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::PushBackUnsafe(Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> > *this, Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::ASStringNode *v2; // rdi
  Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2,Scaleform::ArrayDefaultPolicy> *v3; // rbx
  Scaleform::Ptr<Scaleform::GFx::ASStringNode> *v4; // rdx
  bool v5; // zf

  v2 = v->value.VS._1.VStr;
  if ( v2 )
    ++v2->RefCount;
  v3 = &this->ValueA;
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2>,Scaleform::ArrayDefaultPolicy> *)&this->ValueA.Data.Data,
    this->ValueA.Data.pHeap,
    this->ValueA.Data.Size + 1);
  v4 = &v3->Data.Data[v3->Data.Size - 1];
  if ( v4 )
  {
    if ( v2 )
      ++v2->RefCount;
    v4->pObject = v2;
  }
  if ( v2 )
  {
    v5 = v2->RefCount-- == 1;
    if ( v5 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v2);
  }
}

// File Line: 1033
// RVA: 0x8D6830
Scaleform::Ptr<Scaleform::GFx::ASStringNode> *__fastcall Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::GetDefaultValue(Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> > *this, Scaleform::Ptr<Scaleform::GFx::ASStringNode> *result)
{
  Scaleform::GFx::ASStringNode *v2; // rax

  v2 = &this->VMRef->StringManagerRef->pStringManager->NullStringNode;
  if ( this->VMRef->StringManagerRef->pStringManager != (Scaleform::GFx::ASStringManager *)-104i64 )
    ++this->VMRef->StringManagerRef->pStringManager->NullStringNode.RefCount;
  result->pObject = v2;
  return result;
}

// File Line: 1040
// RVA: 0x8D6880
Scaleform::GFx::AS3::Value *__fastcall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::GetDefaultValue(Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *this, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value *v2; // rbx
  Scaleform::GFx::AS3::Value *v3; // rax

  v2 = result;
  v3 = Scaleform::GFx::AS3::Value::GetNull();
  v2->Flags = v3->Flags;
  v2->Bonus.pWeakProxy = v3->Bonus.pWeakProxy;
  v2->value.VNumber = v3->value.VNumber;
  v2->value.VS._2.VObj = v3->value.VS._2.VObj;
  if ( (v3->Flags & 0x1F) > 9 )
  {
    if ( (v3->Flags >> 9) & 1 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(v3);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(v3);
  }
  return v2;
}

