// File Line: 148
// RVA: 0x8EC120
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::ArrayBase::OfCorrectType(
        Scaleform::GFx::AS3::ArrayBase *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Value *v,
        Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  Scaleform::GFx::AS3::ClassTraits::Traits *ClassTraits; // rax

  ClassTraits = Scaleform::GFx::AS3::VM::GetClassTraits(this->VMRef, v);
  result->Result = Scaleform::GFx::AS3::ClassTraits::Traits::IsParentTypeOf(tr, ClassTraits);
  return result;
}

// File Line: 220
// RVA: 0x8A3230
void __fastcall Scaleform::GFx::AS3::VectorBase<long>::ArrayFunc::~ArrayFunc(
        Scaleform::GFx::AS3::VectorBase<long>::ArrayFunc *this)
{
  this->vfptr = (Scaleform::GFx::AS3::VectorBase<long>::ArrayFuncVtbl *)&Scaleform::GFx::AS3::VectorBase<long>::ArrayFunc::`vftable;
}

// File Line: 250
// RVA: 0x8A98D0
_BOOL8 __fastcall Scaleform::GFx::AS3::VectorBase<long>::CompareValuePtr::operator()(
        Scaleform::GFx::AS3::VectorBase<long>::CompareValuePtr *this,
        int *a,
        int *b)
{
  int v3; // eax
  int v4; // eax
  bool v5; // bl
  Scaleform::GFx::AS3::Value aa; // [rsp+28h] [rbp-50h] BYREF
  Scaleform::GFx::AS3::Value ba; // [rsp+48h] [rbp-30h] BYREF

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
    if ( (aa.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&aa);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&aa);
  }
  if ( (ba.Flags & 0x1F) > 9 )
  {
    if ( (ba.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&ba);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&ba);
  }
  return v5;
}

// File Line: 254
// RVA: 0x8C8A20
_BOOL8 __fastcall Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::CompareValuePtr::Equal(
        Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> >::CompareValuePtr *this,
        Scaleform::Ptr<Scaleform::GFx::ASStringNode> *a,
        Scaleform::Ptr<Scaleform::GFx::ASStringNode> *b)
{
  Scaleform::GFx::AS3::Value *v5; // rax
  Scaleform::GFx::AS3::Value *v6; // rdi
  Scaleform::GFx::AS3::Value *v7; // rax
  bool v8; // bl
  Scaleform::GFx::AS3::Value v10; // [rsp+28h] [rbp-50h] BYREF
  Scaleform::GFx::AS3::Value v11; // [rsp+48h] [rbp-30h] BYREF

  Scaleform::GFx::AS3::Value::Value(&v11, b->pObject);
  v6 = v5;
  Scaleform::GFx::AS3::Value::Value(&v10, a->pObject);
  v8 = (unsigned int)Scaleform::GFx::AS3::Impl::CompareFunct(this->Vm, this->Func, v7, v6) == 0;
  if ( (v10.Flags & 0x1F) > 9 )
  {
    if ( (v10.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v10);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
  }
  if ( (v11.Flags & 0x1F) > 9 )
  {
    if ( (v11.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v11);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v11);
  }
  return v8;
}

// File Line: 320
// RVA: 0x8AA620
void __fastcall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::ValuePtrCollector::operator()(
        Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::ValuePtrCollector *this,
        unsigned int __formal,
        Scaleform::GFx::AS3::Instances::fl::XML *v)
{
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> *Ptrs; // rdi
  unsigned __int64 v5; // rbx
  unsigned __int64 v6; // r8
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *Data; // rcx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v8; // rcx

  Ptrs = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> *)this->Ptrs;
  v5 = Ptrs->Size + 1;
  if ( v5 >= Ptrs->Size )
  {
    if ( v5 <= Ptrs->Policy.Capacity )
      goto LABEL_7;
    v6 = v5 + (v5 >> 2);
  }
  else
  {
    if ( v5 >= Ptrs->Policy.Capacity >> 1 )
      goto LABEL_7;
    v6 = Ptrs->Size + 1;
  }
  Scaleform::ArrayDataBase<double const *,Scaleform::AllocatorDH<double const *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    Ptrs,
    Ptrs[1].Data,
    v6);
LABEL_7:
  Data = Ptrs->Data;
  Ptrs->Size = v5;
  v8 = &Data[v5 - 1];
  if ( v8 )
    v8->pObject = v;
}

// File Line: 345
// RVA: 0x8E1320
void __fastcall Scaleform::GFx::AS3::VectorBase<unsigned long>::GetValue(
        Scaleform::GFx::AS3::VectorBase<unsigned long> *this,
        unsigned int ind,
        Scaleform::GFx::AS3::Value *v)
{
  unsigned int v3; // edi
  Scaleform::GFx::AS3::Value::V1U v5; // [rsp+20h] [rbp-18h]
  Scaleform::GFx::AS3::Value::V2U v6; // [rsp+28h] [rbp-10h]

  v3 = this->ValueA.Data.Data[ind];
  if ( (v->Flags & 0x1F) > 9 )
  {
    if ( (v->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(v);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(v);
  }
  v->Flags &= 0xFFFFFFE3;
  v->Flags |= 3u;
  v5.VInt = v3;
  v->value.VS._1 = v5;
  v->value.VS._2 = v6;
}

// File Line: 346
// RVA: 0x8E1460
void __fastcall Scaleform::GFx::AS3::VectorBase<unsigned long>::GetValueUnsafe(
        Scaleform::GFx::AS3::VectorBase<unsigned long> *this,
        unsigned int ind,
        Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::Value::VU v3; // [rsp+0h] [rbp-18h]

  v3.VS._1.VInt = this->ValueA.Data.Data[ind];
  v->Flags = v->Flags & 0xFFFFFFE0 | 3;
  v->value = v3;
}

// File Line: 359
// RVA: 0x8B6030
void __fastcall Scaleform::GFx::AS3::VectorBase<unsigned long>::Append(
        Scaleform::GFx::AS3::VectorBase<unsigned long> *this,
        Scaleform::GFx::AS3::VectorBase<unsigned long> *other)
{
  unsigned __int64 i; // rsi
  unsigned int *v5; // r14
  unsigned __int64 Size; // rax
  unsigned __int64 v7; // rbx
  unsigned __int64 v8; // r8
  unsigned int *Data; // rcx
  unsigned int *v10; // rcx
  Scaleform::GFx::AS3::CheckResult result; // [rsp+50h] [rbp+18h] BYREF

  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &result)->Result )
  {
    for ( i = 0i64; i < LODWORD(other->ValueA.Data.Size); ++i )
    {
      v5 = &other->ValueA.Data.Data[i];
      Size = this->ValueA.Data.Size;
      v7 = Size + 1;
      if ( Size + 1 >= Size )
      {
        if ( v7 > this->ValueA.Data.Policy.Capacity )
        {
          v8 = v7 + (v7 >> 2);
          goto LABEL_8;
        }
      }
      else if ( v7 < this->ValueA.Data.Policy.Capacity >> 1 )
      {
        v8 = Size + 1;
LABEL_8:
        Scaleform::ArrayDataBase<unsigned long,Scaleform::AllocatorDH<unsigned long,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<enum Scaleform::GFx::AS3::XMLParser::Kind,Scaleform::AllocatorDH_POD<enum Scaleform::GFx::AS3::XMLParser::Kind,2>,Scaleform::ArrayDefaultPolicy> *)&this->ValueA,
          (__int64 *)this->ValueA.Data.pHeap,
          v8);
      }
      Data = this->ValueA.Data.Data;
      this->ValueA.Data.Size = v7;
      v10 = &Data[v7 - 1];
      if ( v10 )
        *v10 = *v5;
    }
  }
}

// File Line: 399
// RVA: 0x814430
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::VectorBase<double>::Resize(
        Scaleform::GFx::AS3::VectorBase<double> *this,
        Scaleform::GFx::AS3::CheckResult *result,
        unsigned __int64 newSise)
{
  unsigned __int64 Size; // rbx
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+38h] [rbp+10h] BYREF

  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &resulta)->Result )
  {
    Size = this->ValueA.Data.Size;
    Scaleform::ArrayDataDH<double,Scaleform::AllocatorDH<double,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      &this->ValueA.Data,
      newSise);
    if ( Size < newSise )
    {
      if ( (__int64)(newSise - Size) >= 4 )
      {
        do
        {
          Size += 4i64;
          this->ValueA.Data.Data[Size - 4] = 0.0;
          this->ValueA.Data.Data[Size - 3] = 0.0;
          this->ValueA.Data.Data[Size - 2] = 0.0;
          this->ValueA.Data.Data[Size - 1] = 0.0;
        }
        while ( Size < newSise - 3 );
      }
      for ( ; Size < newSise; this->ValueA.Data.Data[Size - 1] = 0.0 )
        ++Size;
    }
    result->Result = 1;
    return result;
  }
  else
  {
    result->Result = 0;
    return result;
  }
}

// File Line: 419
// RVA: 0x905C90
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Set(
        Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> > *this,
        Scaleform::GFx::AS3::CheckResult *result,
        unsigned int ind,
        Scaleform::GFx::AS3::Value *v,
        Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  __int64 v6; // rsi
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v11; // zf
  unsigned __int64 Size; // rax
  Scaleform::GFx::AS3::Value::V1U v13; // rbp
  Scaleform::Ptr<Scaleform::GFx::ASStringNode> *v14; // rdi
  Scaleform::GFx::ASStringNode *pObject; // rcx
  Scaleform::GFx::AS3::VM::Error v17; // [rsp+38h] [rbp-40h] BYREF
  Scaleform::GFx::AS3::Value coerced; // [rsp+48h] [rbp-30h] BYREF
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+80h] [rbp+8h] BYREF

  v6 = ind;
  if ( this->Fixed && ind >= LODWORD(this->ValueA.Data.Size)
    || (Size = this->ValueA.Data.Size, ind > (unsigned int)Size) )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v17, 1125, this->VMRef);
    Scaleform::GFx::AS3::VM::ThrowRangeError(this->VMRef, v9);
    pNode = v17.Message.pNode;
    v11 = v17.Message.pNode->RefCount-- == 1;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    goto LABEL_5;
  }
  if ( ind == (_DWORD)Size
    && !Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Resize(this, &resulta, ind + 1)->Result )
  {
LABEL_5:
    result->Result = 0;
    return result;
  }
  coerced.Flags = 0;
  coerced.Bonus.pWeakProxy = 0i64;
  if ( Scaleform::GFx::AS3::ArrayBase::CheckCoerce(this, &resulta, tr, v, &coerced)->Result )
  {
    v13 = coerced.value.VS._1;
    v14 = &this->ValueA.Data.Data[v6];
    if ( coerced.value.VS._1.VStr )
      ++coerced.value.VS._1.VStr->RefCount;
    pObject = v14->pObject;
    if ( v14->pObject )
    {
      v11 = pObject->RefCount-- == 1;
      if ( v11 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pObject);
    }
    v14->pObject = (Scaleform::GFx::ASStringNode *)v13;
    result->Result = 1;
  }
  else
  {
    result->Result = 0;
  }
  if ( (coerced.Flags & 0x1F) > 9 )
  {
    if ( (coerced.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&coerced);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&coerced);
  }
  return result;
}

// File Line: 454
// RVA: 0x7E4390
void __fastcall Scaleform::GFx::AS3::VectorBase<long>::Get(
        Scaleform::GFx::AS3::VectorBase<long> *this,
        unsigned int ind,
        Scaleform::GFx::AS3::Value *v)
{
  int v4; // edi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  Scaleform::GFx::AS3::Value::V1U v7; // [rsp+20h] [rbp-18h]
  Scaleform::GFx::AS3::Value::V2U v8; // [rsp+28h] [rbp-10h]

  if ( ind < LODWORD(this->ValueA.Data.Size) )
  {
    v4 = this->ValueA.Data.Data[ind];
    if ( (v->Flags & 0x1F) > 9 )
    {
      if ( (v->Flags & 0x200) != 0 )
      {
        pWeakProxy = v->Bonus.pWeakProxy;
        if ( pWeakProxy->RefCount-- == 1 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        v->Flags &= 0xFFFFFDE0;
        v->Bonus.pWeakProxy = 0i64;
        v->value.VS._1.VStr = 0i64;
        v->value.VS._2.VObj = 0i64;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(v);
      }
    }
    v->Flags &= 0xFFFFFFE2;
    v->Flags |= 2u;
    v7.VInt = v4;
    v->value.VS._1 = v7;
    v->value.VS._2 = v8;
  }
}

// File Line: 461
// RVA: 0x8FEF50
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::RemoveAt(
        Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *this,
        Scaleform::GFx::AS3::CheckResult *result,
        unsigned int ind)
{
  if ( ind < LODWORD(this->ValueA.Data.Size) )
  {
    Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
      &this->ValueA,
      ind);
    result->Result = 1;
    return result;
  }
  else
  {
    result->Result = 0;
    return result;
  }
}

// File Line: 472
// RVA: 0x8863A0
void __fastcall Scaleform::GFx::AS3::VectorBase<unsigned long>::Map<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint>(
        Scaleform::GFx::AS3::VectorBase<unsigned long> *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint> *result,
        Scaleform::GFx::AS3::Value *callback,
        Scaleform::GFx::AS3::Value *thisObject,
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *currObj)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *v9; // r13
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *pObject; // rcx
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *v11; // rbx
  unsigned int RefCount; // eax
  unsigned int v13; // ecx
  unsigned int v14; // ecx
  bool v15; // al
  Scaleform::GFx::AS3::Value *v16; // rcx
  unsigned int Flags; // edx
  Scaleform::GFx::AS3::ClassTraits::Traits *v18; // r14
  __int64 v19; // rdi
  int v20; // ecx
  Scaleform::GFx::AS3::Value resulta; // [rsp+40h] [rbp-C0h] BYREF
  Scaleform::GFx::AS3::Value coerced; // [rsp+60h] [rbp-A0h] BYREF
  Scaleform::GFx::AS3::Value _this; // [rsp+80h] [rbp-80h] BYREF
  __int64 v24; // [rsp+A0h] [rbp-60h]
  Scaleform::GFx::AS3::Value ptr; // [rsp+B0h] [rbp-50h] BYREF
  int v26; // [rsp+D0h] [rbp-30h]
  __int64 v27; // [rsp+D8h] [rbp-28h]
  int v28; // [rsp+E0h] [rbp-20h]
  Scaleform::GFx::AS3::Value v29; // [rsp+F0h] [rbp-10h] BYREF

  v24 = -2i64;
  v9 = currObj;
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_uint::MakeInstance(
    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint> *)&currObj,
    (Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_uint *)currObj->pTraits.pObject);
  pObject = result->pObject;
  v11 = currObj;
  if ( currObj != result->pObject )
  {
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *)((char *)pObject - 1);
      }
      else
      {
        RefCount = pObject->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
    }
    result->pObject = v11;
  }
  v13 = callback->Flags & 0x1F;
  if ( v13
    && (v13 - 12 > 3 && v13 != 10 || callback->value.VS._1.VStr)
    && Scaleform::GFx::AS3::ArrayBase::CheckCallable(this, (Scaleform::GFx::AS3::CheckResult *)&currObj, callback)->Result )
  {
    v14 = thisObject->Flags & 0x1F;
    v15 = !v14 || (v14 - 12 <= 3 || v14 == 10) && !thisObject->value.VS._1.VStr;
    v16 = callback;
    if ( !v15 )
      v16 = thisObject;
    Flags = v16->Flags;
    _this.Flags = Flags;
    _this.Bonus.pWeakProxy = v16->Bonus.pWeakProxy;
    _this.value = v16->value;
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::AddRefWeakRef(v16);
      else
        Scaleform::GFx::AS3::Value::AddRefInternal(v16);
    }
    v18 = v9->pTraits.pObject->pVM->TraitsUint.pObject;
    v19 = 0i64;
    if ( LODWORD(this->ValueA.Data.Size) )
    {
      while ( 1 )
      {
        v20 = this->ValueA.Data.Data[v19];
        ptr.Flags = 3;
        ptr.Bonus.pWeakProxy = 0i64;
        ptr.value.VS._1.VInt = v20;
        v26 = 3;
        v27 = 0i64;
        v28 = v19;
        Scaleform::GFx::AS3::Value::Value(&v29, v9);
        resulta.Flags = 0;
        resulta.Bonus.pWeakProxy = 0i64;
        Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(this->VMRef, callback, &_this, &resulta, 3u, &ptr, 0);
        if ( this->VMRef->HandleException )
          break;
        coerced.Flags = 0;
        coerced.Bonus.pWeakProxy = 0i64;
        if ( !Scaleform::GFx::AS3::ArrayBase::CheckCoerce(
                this,
                (Scaleform::GFx::AS3::CheckResult *)&currObj,
                v18,
                &resulta,
                &coerced)->Result )
        {
          if ( (coerced.Flags & 0x1F) > 9 )
          {
            if ( (coerced.Flags & 0x200) != 0 )
              Scaleform::GFx::AS3::Value::ReleaseWeakRef(&coerced);
            else
              Scaleform::GFx::AS3::Value::ReleaseInternal(&coerced);
          }
          break;
        }
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint::PushBack(
          (Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *)v11,
          (Scaleform::GFx::AS3::XMLParser::Kind)coerced.value.VS._1.VInt);
        if ( (coerced.Flags & 0x1F) > 9 )
        {
          if ( (coerced.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&coerced);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&coerced);
        }
        if ( (resulta.Flags & 0x1F) > 9 )
        {
          if ( (resulta.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&resulta);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&resulta);
        }
        `eh vector destructor iterator(
          &ptr,
          0x20ui64,
          3,
          (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
        if ( ++v19 >= (unsigned __int64)LODWORD(this->ValueA.Data.Size) )
          goto LABEL_47;
      }
      if ( (resulta.Flags & 0x1F) > 9 )
      {
        if ( (resulta.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&resulta);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&resulta);
      }
      `eh vector destructor iterator(
        &ptr,
        0x20ui64,
        3,
        (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
    }
LABEL_47:
    if ( (_this.Flags & 0x1F) > 9 )
    {
      if ( (_this.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&_this);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
    }
  }
}

// File Line: 507
// RVA: 0x8817D0
void __fastcall Scaleform::GFx::AS3::VectorBase<unsigned long>::Concat<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint>(
        Scaleform::GFx::AS3::VectorBase<unsigned long> *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *const argv,
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *currObj)
{
  Scaleform::GFx::AS3::VM *VMRef; // r15
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *v10; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *pObject; // r12
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *v12; // rbx
  unsigned int v13; // ebp
  Scaleform::GFx::AS3::Traits *ValueTraits; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *ClassTraits; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v16; // r14
  Scaleform::GFx::AS3::VM::Error *v17; // rax
  Scaleform::GFx::AS3::VM::Error *v18; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v21; // [rsp+28h] [rbp-40h] BYREF

  VMRef = this->VMRef;
  v10 = currObj;
  pObject = (Scaleform::GFx::AS3::ClassTraits::Traits *)Scaleform::GFx::AS3::Traits::GetConstructor(currObj->pTraits.pObject)->pTraits.pObject;
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_uint::MakeInstance(
    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint> *)&currObj,
    (Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_uint *)v10->pTraits.pObject);
  v12 = currObj;
  Scaleform::GFx::AS3::Value::Pick(result, currObj);
  Scaleform::GFx::AS3::VectorBase<unsigned long>::Append(&v12->V, &v10->V);
  v13 = 0;
  if ( !argc )
    return;
  while ( 1 )
  {
    ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(VMRef, argv);
    ClassTraits = Scaleform::GFx::AS3::VM::GetClassTraits(VMRef, argv);
    v16 = ClassTraits;
    if ( (ValueTraits->Flags & 1) != 0 )
      break;
    if ( !Scaleform::GFx::AS3::ArrayBase::OfCorrectType(
            this,
            (Scaleform::GFx::AS3::CheckResult *)&currObj,
            argv,
            pObject)->Result )
      goto LABEL_12;
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint::PushBack(
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *)v12,
      (Scaleform::GFx::AS3::XMLParser::Kind)argv->value.VS._1.VInt);
LABEL_8:
    ++v13;
    ++argv;
    if ( v13 >= argc )
      return;
  }
  if ( Scaleform::GFx::AS3::ClassTraits::Traits::IsParentTypeOf(VMRef->TraitsArray.pObject, ClassTraits) )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v21, 1001, this->VMRef);
    Scaleform::GFx::AS3::VM::ThrowError(this->VMRef, v17);
    goto LABEL_13;
  }
  if ( pObject == v16 )
  {
    Scaleform::GFx::AS3::VectorBase<unsigned long>::Append(
      &v12->V,
      (Scaleform::GFx::AS3::VectorBase<unsigned long> *)&argv->value.VS._1.VStr[1].16);
    goto LABEL_8;
  }
LABEL_12:
  Scaleform::GFx::AS3::VM::Error::Error(&v21, 1034, this->VMRef);
  Scaleform::GFx::AS3::VM::ThrowTypeError(this->VMRef, v18);
LABEL_13:
  pNode = v21.Message.pNode;
  if ( v21.Message.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 558
// RVA: 0x882940
void __fastcall Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Filter<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String>(
        Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> > *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String> *result,
        Scaleform::GFx::AS3::Value *callback,
        Scaleform::GFx::AS3::Value *thisObject,
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *currObj)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *pObject; // rcx
  unsigned int RefCount; // eax
  unsigned int v11; // ecx
  unsigned int v12; // ecx
  bool v13; // al
  Scaleform::GFx::AS3::Value *v14; // rcx
  unsigned int Flags; // edx
  __int64 v16; // rdi
  char argv; // [rsp+28h] [rbp-71h]
  Scaleform::GFx::AS3::Value _this; // [rsp+38h] [rbp-61h] BYREF
  __int64 v19; // [rsp+58h] [rbp-41h]
  Scaleform::GFx::AS3::Value ptr; // [rsp+68h] [rbp-31h] BYREF
  int v21; // [rsp+88h] [rbp-11h]
  __int64 v22; // [rsp+90h] [rbp-9h]
  int v23; // [rsp+98h] [rbp-1h]
  Scaleform::GFx::AS3::Value v24; // [rsp+A8h] [rbp+Fh] BYREF
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *retaddr; // [rsp+118h] [rbp+7Fh] BYREF

  v19 = -2i64;
  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String::MakeInstance(
    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String> *)&currObj,
    (Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_String *)retaddr->pTraits.pObject);
  pObject = result->pObject;
  if ( retaddr != result->pObject )
  {
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *)((char *)pObject - 1);
      }
      else
      {
        RefCount = pObject->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
    }
    result->pObject = retaddr;
  }
  v11 = callback->Flags & 0x1F;
  if ( v11
    && (v11 - 12 > 3 && v11 != 10 || callback->value.VS._1.VStr)
    && Scaleform::GFx::AS3::ArrayBase::CheckCallable(this, (Scaleform::GFx::AS3::CheckResult *)&retaddr, callback)->Result )
  {
    v12 = thisObject->Flags & 0x1F;
    v13 = !v12 || (v12 - 12 <= 3 || v12 == 10) && !thisObject->value.VS._1.VStr;
    v14 = callback;
    if ( !v13 )
      v14 = thisObject;
    Flags = v14->Flags;
    _this.Flags = Flags;
    _this.Bonus.pWeakProxy = v14->Bonus.pWeakProxy;
    _this.value = v14->value;
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::AddRefWeakRef(v14);
      else
        Scaleform::GFx::AS3::Value::AddRefInternal(v14);
    }
    v16 = 0i64;
    if ( LODWORD(this->ValueA.Data.Size) )
    {
      while ( 1 )
      {
        Scaleform::GFx::AS3::Value::Value(&ptr, this->ValueA.Data.Data[v16].pObject);
        v21 = 3;
        v22 = 0i64;
        v23 = v16;
        Scaleform::GFx::AS3::Value::Value(&v24, retaddr);
        LODWORD(_this.Bonus.pWeakProxy) = 0;
        Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(
          this->VMRef,
          callback,
          &_this,
          (Scaleform::GFx::AS3::Value *)&_this.Bonus,
          3u,
          &ptr,
          0);
        if ( this->VMRef->HandleException )
          break;
        if ( ((__int64)_this.Bonus.pWeakProxy & 0x1F) == 1 && argv )
          Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::PushBack(retaddr, this->ValueA.Data.Data[v16].pObject);
        if ( (unsigned __int64)((__int64)_this.Bonus.pWeakProxy & 0x1F) > 9 )
        {
          if ( ((__int64)_this.Bonus.pWeakProxy & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef((Scaleform::GFx::AS3::Value *)&_this.Bonus);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&_this.Bonus);
        }
        `eh vector destructor iterator(
          &ptr,
          0x20ui64,
          3,
          (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
        if ( ++v16 >= (unsigned __int64)LODWORD(this->ValueA.Data.Size) )
          goto LABEL_41;
      }
      if ( (unsigned __int64)((__int64)_this.Bonus.pWeakProxy & 0x1F) > 9 )
      {
        if ( ((__int64)_this.Bonus.pWeakProxy & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef((Scaleform::GFx::AS3::Value *)&_this.Bonus);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&_this.Bonus);
      }
      `eh vector destructor iterator(
        &ptr,
        0x20ui64,
        3,
        (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
    }
LABEL_41:
    if ( (_this.Flags & 0x1F) > 9 )
    {
      if ( (_this.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&_this);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
    }
  }
}

// File Line: 591
// RVA: 0x8867C0
void __fastcall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::Pop<Scaleform::GFx::AS3::Value>(
        Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value *v4; // rax
  Scaleform::GFx::AS3::Value v5; // [rsp+28h] [rbp-30h] BYREF
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+70h] [rbp+18h] BYREF

  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &resulta)->Result )
  {
    if ( LODWORD(this->ValueA.Data.Size) )
    {
      v4 = Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::Pop(
             &this->ValueA,
             &v5);
      Scaleform::GFx::AS3::Value::Assign(result, v4);
      if ( (v5.Flags & 0x1F) > 9 )
      {
        if ( (v5.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v5);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v5);
      }
    }
  }
}

// File Line: 609
// RVA: 0x8F4ED0
void __fastcall Scaleform::GFx::AS3::VectorBase<double>::PushBack(
        Scaleform::GFx::AS3::VectorBase<double> *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *const argv,
        Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  int v8; // esi
  Scaleform::GFx::AS3::Value::V1U v9; // xmm6_8
  unsigned __int64 Size; // rax
  unsigned __int64 v11; // rdi
  unsigned __int64 v12; // r8
  long double *v13; // rcx
  Scaleform::GFx::AS3::CheckResult result; // [rsp+30h] [rbp-68h] BYREF
  __int64 v15; // [rsp+38h] [rbp-60h]
  Scaleform::GFx::AS3::Value coerced; // [rsp+40h] [rbp-58h] BYREF

  v15 = -2i64;
  if ( !Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &result)->Result )
    return;
  v8 = 0;
  if ( !argc )
    return;
  while ( 1 )
  {
    coerced.Flags = 0;
    coerced.Bonus.pWeakProxy = 0i64;
    if ( !Scaleform::GFx::AS3::ArrayBase::CheckCoerce(this, &result, tr, &argv[v8], &coerced)->Result )
      break;
    v9 = coerced.value.VS._1;
    Size = this->ValueA.Data.Size;
    v11 = Size + 1;
    if ( Size + 1 >= Size )
    {
      if ( v11 > this->ValueA.Data.Policy.Capacity )
      {
        v12 = v11 + (v11 >> 2);
        goto LABEL_9;
      }
    }
    else if ( v11 < this->ValueA.Data.Policy.Capacity >> 1 )
    {
      v12 = Size + 1;
LABEL_9:
      Scaleform::ArrayDataBase<double const *,Scaleform::AllocatorDH<double const *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> *)&this->ValueA,
        this->ValueA.Data.pHeap,
        v12);
    }
    this->ValueA.Data.Size = v11;
    v13 = &this->ValueA.Data.Data[v11 - 1];
    if ( v13 )
      *v13 = *(long double *)&v9.VStr;
    if ( (coerced.Flags & 0x1F) > 9 )
    {
      if ( (coerced.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&coerced);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&coerced);
    }
    if ( ++v8 >= argc )
      return;
  }
  if ( (coerced.Flags & 0x1F) > 9 )
  {
    if ( (coerced.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&coerced);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&coerced);
  }
}

// File Line: 625
// RVA: 0x916630
void __fastcall Scaleform::GFx::AS3::VectorBase<long>::Unshift(
        Scaleform::GFx::AS3::VectorBase<unsigned long> *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *const argv,
        Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  unsigned __int64 v4; // rbp
  __int64 v5; // rbx
  unsigned int v6; // edi
  bool v10; // al
  unsigned __int64 v11; // rdi
  unsigned __int64 v12; // r8
  unsigned __int64 v13; // rcx
  unsigned int *v14; // rdx
  Scaleform::GFx::AS3::Value::VU *p_value; // rdx
  Scaleform::GFx::AS3::CheckResult result; // [rsp+30h] [rbp-28h] BYREF
  Scaleform::GFx::AS3::CheckResult v17; // [rsp+31h] [rbp-27h] BYREF
  unsigned int v18; // [rsp+34h] [rbp-24h]

  v4 = argc;
  v5 = 0i64;
  v6 = 1;
  v18 = 1;
  v10 = 1;
  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &result)->Result )
  {
    v6 = 3;
    v18 = 3;
    if ( Scaleform::GFx::AS3::ArrayBase::CheckCorrectType(this, &v17, v4, argv, tr)->Result )
      v10 = 0;
  }
  if ( (v6 & 2) != 0 )
  {
    v6 &= ~2u;
    v18 = v6;
  }
  if ( (v6 & 1) != 0 )
    v18 = v6 & 0xFFFFFFFE;
  if ( !v10 )
  {
    v11 = v4;
    Scaleform::ArrayDataDH<unsigned long,Scaleform::AllocatorDH<unsigned long,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      (Scaleform::ArrayDataDH<enum Scaleform::GFx::AS3::XMLParser::Kind,Scaleform::AllocatorDH_POD<enum Scaleform::GFx::AS3::XMLParser::Kind,2>,Scaleform::ArrayDefaultPolicy> *)&this->ValueA,
      v4 + this->ValueA.Data.Size);
    v12 = this->ValueA.Data.Size - v4;
    if ( v12 )
      memmove(&this->ValueA.Data.Data[v4], this->ValueA.Data.Data, 4 * v12);
    v13 = 0i64;
    if ( (_DWORD)v4 )
    {
      do
      {
        v14 = &this->ValueA.Data.Data[v13];
        if ( v14 )
          *v14 = 0;
        ++v13;
      }
      while ( v13 < v4 );
      p_value = &argv->value;
      do
      {
        this->ValueA.Data.Data[v5++] = p_value->VS._1.VInt;
        p_value += 2;
        --v11;
      }
      while ( v11 );
    }
  }
}

// File Line: 641
// RVA: 0x88AF90
void __fastcall Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Shift<Scaleform::GFx::ASString>(
        Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> > *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2,Scaleform::ArrayDefaultPolicy> *p_ValueA; // rsi
  Scaleform::GFx::ASStringNode *pObject; // rdi
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+40h] [rbp+18h] BYREF

  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &resulta)->Result && this->ValueA.Data.Size )
  {
    p_ValueA = &this->ValueA;
    pObject = this->ValueA.Data.Data->pObject;
    if ( !pObject )
      pObject = &result->pNode->pManager->NullStringNode;
    ++pObject->RefCount;
    pNode = result->pNode;
    if ( result->pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    result->pNode = pObject;
    Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
      p_ValueA,
      0i64);
  }
}

// File Line: 654
// RVA: 0x88C080
void __fastcall Scaleform::GFx::AS3::VectorBase<double>::Sort<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double>(
        Scaleform::GFx::AS3::VectorBase<double> *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double> *result,
        Scaleform::GFx::AS3::Value *arg,
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *currObj)
{
  unsigned __int64 v6; // rdi
  Scaleform::GFx::AS3::VM *v7; // rbx
  Scaleform::GFx::AS3::VM::Error *v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::MemoryHeap *MHeap; // rcx
  int v12; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v13; // rcx
  unsigned __int64 Size; // rsi
  unsigned int v15; // ebx
  __int64 v16; // rcx
  unsigned int v17; // ebx
  __int64 v18; // r8
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *pObject; // rcx
  unsigned int RefCount; // eax
  __int64 v21; // rsi
  unsigned __int64 v22; // rcx
  Scaleform::GFx::AS3::Instances::fl::XML **v23; // r14
  unsigned __int64 v24; // rbx
  unsigned __int64 v25; // r8
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v26; // rdx
  Scaleform::Pair<double,unsigned long> *Data; // rdx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v28; // rcx
  unsigned __int64 v29; // rsi
  unsigned int v30; // ebx
  __int64 v31; // rcx
  unsigned int v32; // ebx
  __int64 v33; // rdx
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *v34; // rcx
  unsigned int v35; // eax
  unsigned __int64 v36; // rsi
  __int64 v37; // r14
  unsigned __int64 v38; // rcx
  __int64 Second; // r15
  long double *v40; // r12
  unsigned __int64 v41; // rbx
  unsigned __int64 v42; // r8
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v43; // rdx
  Scaleform::GFx::AS3::VM *VMRef; // rax
  unsigned __int64 v45; // rsi
  unsigned int v46; // ebx
  __int64 v47; // rcx
  bool v48; // r12
  char v49; // si
  bool v50; // r14
  unsigned int v51; // ebx
  __int64 v52; // rcx
  Scaleform::GFx::ASString *v53; // rcx
  int v54; // eax
  const char *pData; // rdx
  const char *v56; // rcx
  signed __int64 v57; // rdx
  unsigned __int8 v58; // al
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *v59; // rcx
  unsigned int v60; // eax
  unsigned __int64 v61; // rsi
  __int64 v62; // r14
  unsigned __int64 v63; // rcx
  __int64 v64; // r15
  long double *v65; // r12
  unsigned __int64 v66; // rbx
  unsigned __int64 v67; // r8
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v68; // rdx
  unsigned __int64 v69; // rsi
  Scaleform::Pair<double,unsigned long> *v70; // rbx
  Scaleform::GFx::ASStringNode *v71; // rcx
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double> *Instance; // rax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *pV; // rbx
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *v74; // rcx
  unsigned int v75; // eax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *v76; // rsi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v77; // r14
  unsigned __int64 v78; // rbx
  unsigned __int64 v79; // r8
  Scaleform::GFx::AS3::Instances::fl::XML **v80; // rcx
  unsigned __int64 v81; // rsi
  unsigned __int64 v82; // r8
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *v83; // rbx
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *v84; // rcx
  unsigned int v85; // eax
  signed __int64 end; // [rsp+18h] [rbp-79h]
  unsigned __int64 enda; // [rsp+18h] [rbp-79h]
  signed __int64 endb; // [rsp+18h] [rbp-79h]
  unsigned __int64 endc; // [rsp+18h] [rbp-79h]
  int v90[2]; // [rsp+20h] [rbp-71h] BYREF
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> v91; // [rsp+28h] [rbp-69h] BYREF
  void *pheapAddr; // [rsp+40h] [rbp-51h]
  Scaleform::ArrayDH<Scaleform::Pair<double,unsigned long>,2,Scaleform::ArrayDefaultPolicy> v93; // [rsp+48h] [rbp-49h] BYREF
  Scaleform::GFx::AS3::Value v94; // [rsp+68h] [rbp-29h] BYREF
  Scaleform::GFx::AS3::VectorBase<double>::CompareValuePtr v95; // [rsp+88h] [rbp-9h] BYREF
  Scaleform::ArrayDH<Scaleform::Pair<double,unsigned long>,2,Scaleform::ArrayDefaultPolicy> *v96; // [rsp+98h] [rbp+7h]
  __int64 v97; // [rsp+A8h] [rbp+17h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double> *v98; // [rsp+100h] [rbp+6Fh]
  Scaleform::GFx::AS3::CheckResult resulta[8]; // [rsp+108h] [rbp+77h] BYREF
  __int64 v100; // [rsp+110h] [rbp+7Fh]

  v97 = -2i64;
  v6 = 0i64;
  v94.Flags = 0;
  v94.Bonus.pWeakProxy = 0i64;
  v90[0] = 0;
  if ( (arg->Flags & 0x1F) >= 0xC || (arg->Flags & 0x1F) - 5 <= 2 )
  {
    Scaleform::GFx::AS3::Value::Assign(&v94, arg);
LABEL_7:
    MHeap = this->VMRef->MHeap;
    *(_QWORD *)&resulta[0].Result = &v91;
    memset(&v91, 0, sizeof(v91));
    pheapAddr = MHeap;
    v12 = v94.Flags & 0x1F;
    if ( (v94.Flags & 0x1F) != 0 && ((unsigned int)(v12 - 12) > 3 && v12 != 10 || v94.value.VS._1.VStr) )
    {
      v13 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)this->VMRef->MHeap;
      *(_QWORD *)&resulta[0].Result = &v93;
      v93.Data.Data = 0i64;
      end = 0i64;
      *(_QWORD *)v90 = 0i64;
      v91.Data = v13;
      v91.Size = (unsigned __int64)&Scaleform::GFx::AS3::VectorBase<double>::ValuePtrCollector::`vftable;
      v91.Policy.Capacity = (unsigned __int64)&v93;
      Size = this->ValueA.Data.Size;
      v15 = 0;
      if ( Size )
      {
        v16 = 0i64;
        do
        {
          (*(void (__fastcall **)(unsigned __int64 *, _QWORD, long double *))(v91.Size + 8))(
            &v91.Size,
            v15++,
            &this->ValueA.Data.Data[v16]);
          v16 = v15;
        }
        while ( v15 < Size );
      }
      v93.Data.Data = (Scaleform::Pair<double,unsigned long> *)this->VMRef;
      v93.Data.Size = (unsigned __int64)&v94;
      v95 = *(Scaleform::GFx::AS3::VectorBase<double>::CompareValuePtr *)&v93.Data.Data;
      Scaleform::Alg::QuickSortSlicedSafe<Scaleform::ArrayDH<double const *,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::AS3::VectorBase<double>::CompareValuePtr>(
        (Scaleform::ArrayDH<double const *,2,Scaleform::ArrayDefaultPolicy> *)&v93,
        0i64,
        end,
        &v95);
      if ( (v90[0] & 4) != 0 )
      {
        v17 = 1;
        if ( enda > 1 )
        {
          v18 = 1i64;
          while ( !Scaleform::GFx::AS3::VectorBase<double>::CompareValuePtr::Equal(
                     (Scaleform::GFx::AS3::VectorBase<double>::CompareValuePtr *)&v93,
                     *((const long double **)v93.Data.Data + v17 - 1),
                     *((const long double **)&v93.Data.Data->First + v18)) )
          {
            v18 = ++v17;
            if ( v17 >= enda )
              goto LABEL_27;
          }
          pObject = result->pObject;
          if ( result->pObject )
          {
            if ( ((unsigned __int8)pObject & 1) != 0 )
            {
              result->pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *)((char *)pObject - 1);
            }
            else
            {
              RefCount = pObject->RefCount;
              if ( (RefCount & 0x3FFFFF) != 0 )
              {
                pObject->RefCount = RefCount - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
              }
            }
            result->pObject = 0i64;
          }
          v91.Size = (unsigned __int64)&Scaleform::GFx::AS3::VectorBase<double>::ArrayFunc::`vftable;
          *(_QWORD *)&resulta[0].Result = &v93;
LABEL_56:
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v93.Data.Data);
LABEL_99:
          *(_QWORD *)&resulta[0].Result = &v91;
LABEL_155:
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v91.Data);
          goto LABEL_156;
        }
      }
LABEL_27:
      v21 = 0i64;
      if ( !enda )
      {
LABEL_38:
        v91.Size = (unsigned __int64)&Scaleform::GFx::AS3::VectorBase<double>::ArrayFunc::`vftable;
        *(_QWORD *)&resulta[0].Result = &v93;
        Data = v93.Data.Data;
        goto LABEL_117;
      }
      v22 = v91.Size;
      while ( 1 )
      {
        v23 = (Scaleform::GFx::AS3::Instances::fl::XML **)*((_QWORD *)&v93.Data.Data->First + v21);
        v24 = v22 + 1;
        if ( v22 + 1 >= v22 )
        {
          if ( v24 > v91.Policy.Capacity )
          {
            v25 = v24 + (v24 >> 2);
            goto LABEL_34;
          }
        }
        else if ( v24 < v91.Policy.Capacity >> 1 )
        {
          v25 = v22 + 1;
LABEL_34:
          Scaleform::ArrayDataBase<double const *,Scaleform::AllocatorDH<double const *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            &v91,
            pheapAddr,
            v25);
        }
        v22 = v24;
        v91.Size = v24;
        v26 = &v91.Data[v24 - 1];
        if ( v26 )
        {
          v26->pObject = *v23;
          v22 = v91.Size;
        }
        if ( ++v21 >= enda )
          goto LABEL_38;
      }
    }
    v28 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)this->VMRef->MHeap;
    if ( (v90[0] & 0x10) != 0 )
    {
      *(_QWORD *)&resulta[0].Result = &v93;
      v93.Data.Data = 0i64;
      endb = 0i64;
      *(_QWORD *)v90 = 0i64;
      v91.Data = v28;
      v91.Size = (unsigned __int64)&Scaleform::GFx::AS3::VectorBase<double>::Value2NumberCollector::`vftable;
      v91.Policy.Capacity = (unsigned __int64)&v93;
      v29 = this->ValueA.Data.Size;
      v30 = 0;
      if ( v29 )
      {
        v31 = 0i64;
        do
        {
          (*(void (__fastcall **)(unsigned __int64 *, _QWORD, long double *))(v91.Size + 8))(
            &v91.Size,
            v30++,
            &this->ValueA.Data.Data[v31]);
          v31 = v30;
        }
        while ( v30 < v29 );
      }
      Scaleform::Alg::QuickSortSlicedSafe<Scaleform::ArrayDH<Scaleform::Pair<double,unsigned long>,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::AS3::Impl::CompareAsNumberInd>(
        &v93,
        0i64,
        endb,
        (Scaleform::GFx::AS3::Impl::CompareAsNumberInd)((v90[0] & 2) != 0));
      if ( (v90[0] & 4) != 0 )
      {
        v32 = 1;
        if ( endc > 1 )
        {
          v33 = 1i64;
          while ( v93.Data.Data[v33].First != v93.Data.Data[v32 - 1].First )
          {
            v33 = ++v32;
            if ( v32 >= endc )
              goto LABEL_57;
          }
          v34 = result->pObject;
          if ( result->pObject )
          {
            if ( ((unsigned __int8)v34 & 1) != 0 )
            {
              result->pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *)((char *)v34 - 1);
            }
            else
            {
              v35 = v34->RefCount;
              if ( (v35 & 0x3FFFFF) != 0 )
              {
                v34->RefCount = v35 - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v34);
              }
            }
            result->pObject = 0i64;
          }
          v91.Size = (unsigned __int64)&Scaleform::GFx::AS3::VectorBase<double>::ArrayFunc::`vftable;
          *(_QWORD *)&resulta[0].Result = &v93;
          goto LABEL_56;
        }
      }
LABEL_57:
      v36 = 0i64;
      if ( !endc )
        goto LABEL_69;
      v37 = 0i64;
      v38 = v91.Size;
      while ( 1 )
      {
        Second = v93.Data.Data[v37].Second;
        v40 = this->ValueA.Data.Data;
        v41 = v38 + 1;
        if ( v38 + 1 >= v38 )
        {
          if ( v41 > v91.Policy.Capacity )
          {
            v42 = v41 + (v41 >> 2);
            goto LABEL_64;
          }
        }
        else if ( v41 < v91.Policy.Capacity >> 1 )
        {
          v42 = v38 + 1;
LABEL_64:
          Scaleform::ArrayDataBase<double const *,Scaleform::AllocatorDH<double const *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            &v91,
            pheapAddr,
            v42);
        }
        v38 = v41;
        v91.Size = v41;
        v43 = &v91.Data[v41 - 1];
        if ( v43 )
        {
          v43->pObject = *(Scaleform::GFx::AS3::Instances::fl::XML **)&v40[Second];
          v38 = v91.Size;
        }
        ++v36;
        ++v37;
        if ( v36 >= endc )
        {
          result = v98;
LABEL_69:
          v91.Size = (unsigned __int64)&Scaleform::GFx::AS3::VectorBase<double>::ArrayFunc::`vftable;
          *(_QWORD *)&resulta[0].Result = &v93;
          Data = v93.Data.Data;
LABEL_117:
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, Data);
          if ( (v90[0] & 8) != 0 )
          {
            Instance = Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_double::MakeInstance(
                         (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double> *)resulta,
                         *(Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_double **)(v100 + 40));
            pV = Instance->pV;
            v74 = result->pObject;
            if ( Instance->pV != result->pObject )
            {
              if ( v74 )
              {
                if ( ((unsigned __int8)v74 & 1) != 0 )
                {
                  result->pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *)((char *)v74 - 1);
                }
                else
                {
                  v75 = v74->RefCount;
                  if ( (v75 & 0x3FFFFF) != 0 )
                  {
                    v74->RefCount = v75 - 1;
                    Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v74);
                  }
                }
              }
              result->pObject = pV;
            }
            v76 = result->pObject;
            if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(&result->pObject->V, resulta)->Result && v91.Size )
            {
              do
              {
                v77 = v91.Data;
                v78 = v76->V.ValueA.Data.Size + 1;
                if ( v78 >= v76->V.ValueA.Data.Size )
                {
                  if ( v78 > v76->V.ValueA.Data.Policy.Capacity )
                  {
                    v79 = v78 + (v78 >> 2);
                    goto LABEL_132;
                  }
                }
                else if ( v78 < v76->V.ValueA.Data.Policy.Capacity >> 1 )
                {
                  v79 = v76->V.ValueA.Data.Size + 1;
LABEL_132:
                  Scaleform::ArrayDataBase<double const *,Scaleform::AllocatorDH<double const *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> *)&v76->V.ValueA,
                    v76->V.ValueA.Data.pHeap,
                    v79);
                }
                v76->V.ValueA.Data.Size = v78;
                v80 = (Scaleform::GFx::AS3::Instances::fl::XML **)&v76->V.ValueA.Data.Data[v78 - 1];
                if ( v80 )
                  *v80 = v77[v6].pObject;
                ++v6;
              }
              while ( v6 < v91.Size );
            }
LABEL_154:
            *(_QWORD *)&resulta[0].Result = &v91;
            goto LABEL_155;
          }
          v81 = v91.Size;
          if ( v91.Size >= this->ValueA.Data.Size )
          {
            if ( v91.Size > this->ValueA.Data.Policy.Capacity )
            {
              v82 = v91.Size + (v91.Size >> 2);
LABEL_142:
              Scaleform::ArrayDataBase<double const *,Scaleform::AllocatorDH<double const *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> *)&this->ValueA,
                this->ValueA.Data.pHeap,
                v82);
            }
          }
          else if ( v91.Size < this->ValueA.Data.Policy.Capacity >> 1 )
          {
            v82 = v91.Size;
            goto LABEL_142;
          }
          this->ValueA.Data.Size = v81;
          if ( v81 )
          {
            do
            {
              *(_QWORD *)&this->ValueA.Data.Data[v6] = v91.Data[v6].pObject;
              ++v6;
            }
            while ( v6 < this->ValueA.Data.Size );
          }
          v83 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *)v100;
          if ( (Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *)v100 != result->pObject )
          {
            if ( v100 )
              *(_DWORD *)(v100 + 32) = (*(_DWORD *)(v100 + 32) + 1) & 0x8FBFFFFF;
            v84 = result->pObject;
            if ( result->pObject )
            {
              if ( ((unsigned __int8)v84 & 1) != 0 )
              {
                result->pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *)((char *)v84 - 1);
              }
              else
              {
                v85 = v84->RefCount;
                if ( (v85 & 0x3FFFFF) != 0 )
                {
                  v84->RefCount = v85 - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v84);
                }
              }
            }
            result->pObject = v83;
          }
          goto LABEL_154;
        }
      }
    }
    *(_QWORD *)&resulta[0].Result = &v93;
    memset(&v93, 0, 24);
    v93.Data.pHeap = (Scaleform::MemoryHeap *)v28;
    VMRef = this->VMRef;
    v95.Vm = (Scaleform::GFx::AS3::VM *)&Scaleform::GFx::AS3::VectorBase<double>::Value2StrCollector::`vftable;
    v95.Func = (Scaleform::GFx::AS3::Value *)VMRef;
    v96 = &v93;
    v45 = this->ValueA.Data.Size;
    v46 = 0;
    if ( v45 )
    {
      v47 = 0i64;
      do
      {
        (*(void (__fastcall **)(Scaleform::GFx::AS3::VectorBase<double>::CompareValuePtr *, _QWORD, long double *))&v95.Vm->Initialized)(
          &v95,
          v46++,
          &this->ValueA.Data.Data[v47]);
        v47 = v46;
      }
      while ( v46 < v45 );
    }
    v48 = (v90[0] & 0x400) != 0;
    v49 = v90[0] & 1;
    v50 = (v90[0] & 2) != 0;
    resulta[0].Result = v50;
    resulta[1].Result = v90[0] & 1;
    resulta[2].Result = v48;
    Scaleform::Alg::QuickSortSlicedSafe<Scaleform::ArrayDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::AS3::Impl::CompareAsStringInd>(
      (Scaleform::ArrayDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2,Scaleform::ArrayDefaultPolicy> *)&v93,
      0i64,
      v93.Data.Size,
      (Scaleform::GFx::AS3::Impl::CompareAsStringInd *)resulta);
    if ( (v90[0] & 4) != 0 )
    {
      v51 = 1;
      if ( v93.Data.Size > 1 )
      {
        v52 = 1i64;
        while ( 1 )
        {
          v53 = (Scaleform::GFx::ASString *)&v93.Data.Data[v52];
          if ( v48 )
          {
            v54 = v50
                ? Scaleform::GFx::ASString::LocaleCompare_CaseCheck(
                    v53,
                    (Scaleform::GFx::ASString *)&v93.Data.Data[v51 - 1],
                    v49 == 0)
                : Scaleform::GFx::ASString::LocaleCompare_CaseCheck(
                    (Scaleform::GFx::ASString *)&v93.Data.Data[v51 - 1],
                    v53,
                    v49 == 0);
          }
          else
          {
            pData = v53->pNode->pData;
            v56 = **(const char ***)&v93.Data.Data[v51 - 1].First;
            if ( v49 )
            {
              v54 = Scaleform::String::CompareNoCase(v56, pData);
            }
            else
            {
              v57 = pData - v56;
              while ( 1 )
              {
                v58 = *v56;
                if ( *v56 != v56[v57] )
                  break;
                ++v56;
                if ( !v58 )
                {
                  v54 = 0;
                  goto LABEL_87;
                }
              }
              v54 = v58 < (unsigned int)v56[v57] ? -1 : 1;
            }
LABEL_87:
            if ( v50 )
              v54 = -v54;
          }
          if ( !v54 )
            break;
          v52 = ++v51;
          if ( v51 >= v93.Data.Size )
            goto LABEL_100;
        }
        v59 = result->pObject;
        if ( result->pObject )
        {
          if ( ((unsigned __int8)v59 & 1) != 0 )
          {
            result->pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_double *)((char *)v59 - 1);
          }
          else
          {
            v60 = v59->RefCount;
            if ( (v60 & 0x3FFFFF) != 0 )
            {
              v59->RefCount = v60 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v59);
            }
          }
          result->pObject = 0i64;
        }
        v95.Vm = (Scaleform::GFx::AS3::VM *)&Scaleform::GFx::AS3::VectorBase<double>::ArrayFunc::`vftable;
        *(_QWORD *)&resulta[0].Result = &v93;
        Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&v93);
        goto LABEL_99;
      }
    }
LABEL_100:
    v61 = 0i64;
    if ( !v93.Data.Size )
      goto LABEL_112;
    v62 = 0i64;
    v63 = v91.Size;
    while ( 1 )
    {
      v64 = v93.Data.Data[v62].Second;
      v65 = this->ValueA.Data.Data;
      v66 = v63 + 1;
      if ( v63 + 1 >= v63 )
      {
        if ( v66 > v91.Policy.Capacity )
        {
          v67 = v66 + (v66 >> 2);
          goto LABEL_107;
        }
      }
      else if ( v66 < v91.Policy.Capacity >> 1 )
      {
        v67 = v63 + 1;
LABEL_107:
        Scaleform::ArrayDataBase<double const *,Scaleform::AllocatorDH<double const *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &v91,
          pheapAddr,
          v67);
      }
      v63 = v66;
      v91.Size = v66;
      v68 = &v91.Data[v66 - 1];
      if ( v68 )
      {
        v68->pObject = *(Scaleform::GFx::AS3::Instances::fl::XML **)&v65[v64];
        v63 = v91.Size;
      }
      ++v61;
      ++v62;
      if ( v61 >= v93.Data.Size )
      {
        result = v98;
LABEL_112:
        v95.Vm = (Scaleform::GFx::AS3::VM *)&Scaleform::GFx::AS3::VectorBase<double>::ArrayFunc::`vftable;
        v69 = v93.Data.Size;
        Data = v93.Data.Data;
        v70 = &v93.Data.Data[v93.Data.Size - 1];
        *(_QWORD *)&resulta[0].Result = v70;
        if ( v93.Data.Size )
        {
          do
          {
            v71 = *(Scaleform::GFx::ASStringNode **)&v70->First;
            v10 = (*(_DWORD *)(*(_QWORD *)&v70->First + 24i64))-- == 1;
            if ( v10 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v71);
            *(_QWORD *)&resulta[0].Result = --v70;
            --v69;
          }
          while ( v69 );
          Data = v93.Data.Data;
        }
        goto LABEL_117;
      }
    }
  }
  if ( Scaleform::GFx::AS3::Value::Convert2Int32(arg, resulta, v90)->Result )
    goto LABEL_7;
  v7 = this->VMRef;
  Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v93, 1034, v7);
  Scaleform::GFx::AS3::VM::ThrowTypeError(v7, v8);
  v9 = (Scaleform::GFx::ASStringNode *)v93.Data.Size;
  v10 = (*(_DWORD *)(v93.Data.Size + 24))-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
LABEL_156:
  if ( (v94.Flags & 0x1F) > 9 )
  {
    if ( (v94.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v94);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v94);
  }
}  }
  }
  if ( Scaleform::GFx::AS3::Value::Convert2Int32(arg, resulta, v90)->Result )
    goto LABEL_7;
  v7 = this->VMRef;
  Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v93, 1034, v7);
  Scaleform::GFx::AS3::VM::ThrowTypeError(v7, v8);
  v9 = (Scaleform::GFx::ASStringNode *)v93.Data.Size;
  v10 = (*(_DWORD *)(v93.Data.Size + 24))-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);


// File Line: 801
// RVA: 0x88B250
void __fastcall Scaleform::GFx::AS3::VectorBase<long>::Slice<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int>(
        Scaleform::GFx::AS3::VectorBase<long> *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *const argv,
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *currObj)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_int *pV; // rbx
  int Size; // edx
  int v11; // esi
  bool v12; // sf
  __int64 i; // r14
  int v14; // ebp
  unsigned __int64 v15; // rax
  unsigned __int64 v16; // rdi
  unsigned __int64 v17; // r8
  int *Data; // rcx
  int *v19; // rcx
  int v20; // [rsp+20h] [rbp-38h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_int> resulta; // [rsp+28h] [rbp-30h] BYREF
  Scaleform::GFx::AS3::CheckResult v22; // [rsp+70h] [rbp+18h] BYREF

  Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_int::MakeInstance(
    &resulta,
    (Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_int *)currObj->pTraits.pObject);
  pV = resulta.pV;
  Scaleform::GFx::AS3::Value::Pick(result, resulta.pV);
  Size = 0xFFFFFF;
  v11 = 0;
  v20 = 0;
  LODWORD(currObj) = 0xFFFFFF;
  if ( argc )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2Int32(argv, &v22, &v20)->Result )
      return;
    v11 = v20;
    Size = (int)currObj;
  }
  if ( argc > 1 )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2Int32(argv + 1, &v22, (int *)&currObj)->Result )
      return;
    v11 = v20;
    Size = (int)currObj;
  }
  v12 = v11 < 0;
  if ( v11 < 0 )
  {
    v11 += LODWORD(this->ValueA.Data.Size);
    v12 = v11 < 0;
  }
  if ( v12 )
    v11 = 0;
  v20 = v11;
  if ( Size < 0 )
    Size += LODWORD(this->ValueA.Data.Size);
  if ( (int)this->ValueA.Data.Size < Size )
    Size = this->ValueA.Data.Size;
  LODWORD(currObj) = Size;
  if ( v11 < Size )
  {
    for ( i = v11; ; ++i )
    {
      v14 = this->ValueA.Data.Data[i];
      if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(&pV->V, &v22)->Result )
        break;
LABEL_26:
      if ( ++v11 >= (int)currObj )
        return;
    }
    v15 = pV->V.ValueA.Data.Size;
    v16 = v15 + 1;
    if ( v15 + 1 >= v15 )
    {
      if ( v16 <= pV->V.ValueA.Data.Policy.Capacity )
        goto LABEL_24;
      v17 = v16 + (v16 >> 2);
    }
    else
    {
      if ( v16 >= pV->V.ValueA.Data.Policy.Capacity >> 1 )
        goto LABEL_24;
      v17 = v15 + 1;
    }
    Scaleform::ArrayDataBase<unsigned long,Scaleform::AllocatorDH<unsigned long,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<enum Scaleform::GFx::AS3::XMLParser::Kind,Scaleform::AllocatorDH_POD<enum Scaleform::GFx::AS3::XMLParser::Kind,2>,Scaleform::ArrayDefaultPolicy> *)&pV->V.ValueA,
      (__int64 *)pV->V.ValueA.Data.pHeap,
      v17);
LABEL_24:
    Data = pV->V.ValueA.Data.Data;
    pV->V.ValueA.Data.Size = v16;
    v19 = &Data[v16 - 1];
    if ( v19 )
      *v19 = v14;
    goto LABEL_26;
  }
}

// File Line: 836
// RVA: 0x88ED90
void __fastcall Scaleform::GFx::AS3::VectorBase<unsigned long>::Splice<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint>(
        Scaleform::GFx::AS3::VectorBase<unsigned long> *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *const argv,
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *currObj)
{
  int v9; // r9d
  unsigned __int64 Size; // rdi
  Scaleform::GFx::AS3::VM::Error *v11; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  int v14; // ecx
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+20h] [rbp-38h] BYREF
  int v16; // [rsp+24h] [rbp-34h] BYREF
  unsigned int v17; // [rsp+28h] [rbp-30h] BYREF
  Scaleform::GFx::AS3::VM::Error v18; // [rsp+30h] [rbp-28h] BYREF
  __int64 v19; // [rsp+40h] [rbp-18h]

  v19 = -2i64;
  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &resulta)->Result )
  {
    v9 = 0;
    v16 = 0;
    if ( argc )
    {
      if ( !Scaleform::GFx::AS3::Value::Convert2Int32(argv, &resulta, &v16)->Result )
        return;
      v9 = v16;
    }
    Size = this->ValueA.Data.Size;
    v17 = 0;
    if ( v9 < 0 )
    {
      v9 += Size;
      v16 = v9;
    }
    if ( argc <= 1 )
    {
      v17 = Size - v9;
    }
    else
    {
      if ( !Scaleform::GFx::AS3::Value::Convert2UInt32(argv + 1, &resulta, &v17)->Result )
        return;
      if ( (int)(v16 + v17) < 0 || v16 + v17 > (unsigned int)Size )
      {
        Scaleform::GFx::AS3::VM::Error::Error(&v18, 1125, this->VMRef);
        Scaleform::GFx::AS3::VM::ThrowRangeError(this->VMRef, v11);
        pNode = v18.Message.pNode;
        if ( v18.Message.pNode->RefCount-- == 1 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        return;
      }
    }
    Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_uint::MakeInstance(
      (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint> *)&v18,
      (Scaleform::GFx::AS3::InstanceTraits::fl_vec::Vector_uint *)currObj->pTraits.pObject);
    Scaleform::GFx::AS3::Value::Pick(result, *(Scaleform::GFx::AS3::Object **)&v18.ID);
    if ( v16 <= (int)Size && v16 >= 0 )
    {
      Scaleform::GFx::AS3::VectorBase<unsigned long>::DeleteMultipleAt<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint>(
        this,
        v16,
        v17,
        *(Scaleform::GFx::AS3::Instances::fl_vec::Vector_int **)&v18.ID);
      if ( argc > 2 )
      {
        v14 = v16;
        if ( (int)this->ValueA.Data.Size < v16 )
          v14 = this->ValueA.Data.Size;
        v16 = v14;
        Scaleform::GFx::AS3::VectorBase<unsigned long>::Insert(this, v14, argc - 2, argv + 2);
      }
    }
  }
}

// File Line: 933
// RVA: 0x8CDB30
void __fastcall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::ForEachChild_GC(
        Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::Value::V2U *, void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **), Scaleform::GFx::AS3::RefCountCollector<328> *))
{
  unsigned __int64 Size; // rdi
  __int64 v7; // rbx
  Scaleform::GFx::AS3::Value *v8; // rdx

  Size = this->ValueA.Data.Size;
  if ( Size )
  {
    v7 = 0i64;
    do
    {
      v8 = &this->ValueA.Data.Data[v7];
      if ( (v8->Flags & 0x1F) > 0xA && (v8->Flags & 0x200) == 0 )
        Scaleform::GFx::AS3::ForEachChild_GC_Internal(prcc, v8, op);
      ++v7;
      --Size;
    }
    while ( Size );
  }
}

// File Line: 941
// RVA: 0x881C40
void __fastcall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::DeleteMultipleAt<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object>(
        Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *this,
        unsigned __int64 pos,
        unsigned __int64 count,
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *deleted)
{
  unsigned __int64 v4; // rbx
  unsigned __int64 v9; // rdi
  Scaleform::GFx::AS3::Value *v10; // r12
  Scaleform::GFx::AS3::CheckResult result; // [rsp+50h] [rbp+8h] BYREF

  v4 = 0i64;
  if ( count )
  {
    v9 = pos;
    do
    {
      if ( v4 + pos >= this->ValueA.Data.Size )
        break;
      v10 = &this->ValueA.Data.Data[v9];
      if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(&deleted->V, &result)->Result )
        Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
          &deleted->V.ValueA.Data,
          v10);
      ++v4;
      ++v9;
    }
    while ( v4 < count );
  }
  Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::RemoveMultipleAt(
    &this->ValueA,
    pos,
    count);
}

// File Line: 950
// RVA: 0x8E5D40
void __fastcall Scaleform::GFx::AS3::VectorBase<unsigned long>::Insert(
        Scaleform::GFx::AS3::VectorBase<unsigned long> *this,
        unsigned __int64 pos,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  unsigned __int64 v4; // rsi
  Scaleform::GFx::AS3::Value::VU *p_value; // r15
  __int64 v6; // rbp
  Scaleform::ArrayDH<unsigned long,2,Scaleform::ArrayDefaultPolicy> *p_ValueA; // rdi
  unsigned __int64 v8; // r14
  unsigned __int64 Size; // rax
  int VInt; // r12d
  unsigned __int64 v11; // rbx
  unsigned __int64 v12; // r8
  unsigned int *v13; // rcx

  if ( argc )
  {
    v4 = pos;
    p_value = &argv->value;
    v6 = argc;
    p_ValueA = &this->ValueA;
    v8 = pos;
    do
    {
      Size = p_ValueA->Data.Size;
      VInt = p_value->VS._1.VInt;
      v11 = Size + 1;
      if ( Size + 1 >= Size )
      {
        if ( v11 > p_ValueA->Data.Policy.Capacity )
        {
          v12 = v11 + (v11 >> 2);
          goto LABEL_8;
        }
      }
      else if ( v11 < p_ValueA->Data.Policy.Capacity >> 1 )
      {
        v12 = Size + 1;
LABEL_8:
        Scaleform::ArrayDataBase<unsigned long,Scaleform::AllocatorDH<unsigned long,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<enum Scaleform::GFx::AS3::XMLParser::Kind,Scaleform::AllocatorDH_POD<enum Scaleform::GFx::AS3::XMLParser::Kind,2>,Scaleform::ArrayDefaultPolicy> *)p_ValueA,
          (__int64 *)p_ValueA->Data.pHeap,
          v12);
      }
      p_ValueA->Data.Size = v11;
      if ( v4 < v11 - 1 )
        memmove(&p_ValueA->Data.Data[v8 + 1], &p_ValueA->Data.Data[v8], 4 * (v11 - v4) - 4);
      v13 = &p_ValueA->Data.Data[v8];
      if ( v13 )
        *v13 = VInt;
      ++v8;
      p_value += 2;
      ++v4;
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 961
// RVA: 0x90E7E0
void __fastcall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::SetUnsafe(
        Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *this,
        unsigned int ind,
        Scaleform::GFx::AS3::Value *v)
{
  __int64 v3; // rbx
  unsigned int Flags; // r9d
  Scaleform::GFx::AS3::Value other; // [rsp+28h] [rbp-30h] BYREF

  v3 = ind;
  Flags = v->Flags;
  other.Flags = Flags;
  other.Bonus.pWeakProxy = v->Bonus.pWeakProxy;
  other.value = v->value;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(v);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(v);
  }
  Scaleform::GFx::AS3::Value::Assign(&this->ValueA.Data.Data[v3], &other);
  if ( (other.Flags & 0x1F) > 9 )
  {
    if ( (other.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&other);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
  }
}

// File Line: 966
// RVA: 0x8F5580
void __fastcall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::PushBackUnsafe(
        Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *this,
        Scaleform::GFx::AS3::Value *v)
{
  unsigned int Flags; // r8d
  Scaleform::GFx::AS3::Value val; // [rsp+28h] [rbp-30h] BYREF

  Flags = v->Flags;
  val.Flags = Flags;
  val.Bonus.pWeakProxy = v->Bonus.pWeakProxy;
  val.value = v->value;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(v);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(v);
  }
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
    &this->ValueA.Data,
    &val);
  if ( (val.Flags & 0x1F) > 9 )
  {
    if ( (val.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&val);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&val);
  }
}

// File Line: 970
// RVA: 0x8F5620
// attributes: thunk
void __fastcall Scaleform::GFx::AS3::VectorBase<long>::PushBackValueUnsafe(
        Scaleform::GFx::AS3::VectorBase<unsigned long> *this,
        Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::VectorBase<unsigned long>::PushBackUnsafe(this, v);
}

// File Line: 987
// RVA: 0x8E36D0
void __fastcall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::IndexOf(
        Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *this,
        int *result,
        Scaleform::GFx::AS3::Value *searchElement,
        int fromIndex)
{
  unsigned __int64 v4; // rbx
  __int64 v8; // rdi

  v4 = fromIndex;
  if ( fromIndex >= (unsigned __int64)LODWORD(this->ValueA.Data.Size) )
  {
LABEL_5:
    *result = -1;
  }
  else
  {
    v8 = fromIndex;
    while ( !Scaleform::GFx::AS3::StrictEqual(&this->ValueA.Data.Data[v8], searchElement) )
    {
      ++v4;
      ++v8;
      if ( v4 >= LODWORD(this->ValueA.Data.Size) )
        goto LABEL_5;
    }
    *result = v4;
  }
}

// File Line: 1003
// RVA: 0x8E80F0
void __fastcall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::LastIndexOf(
        Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *this,
        int *result,
        Scaleform::GFx::AS3::Value *searchElement,
        int fromIndex)
{
  __int64 v5; // rbx
  __int64 v8; // rdi

  v5 = LODWORD(this->ValueA.Data.Size) - 1i64;
  if ( fromIndex < v5 )
    v5 = fromIndex;
  if ( v5 < 0 )
  {
LABEL_7:
    *result = -1;
  }
  else
  {
    v8 = v5;
    while ( !Scaleform::GFx::AS3::StrictEqual(&this->ValueA.Data.Data[v8], searchElement) )
    {
      --v8;
      if ( --v5 < 0 )
        goto LABEL_7;
    }
    *result = v5;
  }
}

// File Line: 1026
// RVA: 0x8F54F0
void __fastcall Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::PushBackUnsafe(
        Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> > *this,
        Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::ASStringNode *VStr; // rdi
  Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2,Scaleform::ArrayDefaultPolicy> *p_ValueA; // rbx
  Scaleform::Ptr<Scaleform::GFx::ASStringNode> *v4; // rdx

  VStr = v->value.VS._1.VStr;
  if ( VStr )
    ++VStr->RefCount;
  p_ValueA = &this->ValueA;
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->ValueA.Data,
    this->ValueA.Data.pHeap,
    this->ValueA.Data.Size + 1);
  v4 = &p_ValueA->Data.Data[p_ValueA->Data.Size - 1];
  if ( v4 )
  {
    if ( VStr )
      ++VStr->RefCount;
    v4->pObject = VStr;
  }
  if ( VStr )
  {
    if ( VStr->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
  }
}

// File Line: 1033
// RVA: 0x8D6830
Scaleform::Ptr<Scaleform::GFx::ASStringNode> *__fastcall Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::GetDefaultValue(
        Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> > *this,
        Scaleform::Ptr<Scaleform::GFx::ASStringNode> *result)
{
  Scaleform::GFx::ASStringNode *p_NullStringNode; // rax

  p_NullStringNode = &this->VMRef->StringManagerRef->pStringManager->NullStringNode;
  if ( this->VMRef->StringManagerRef->pStringManager != (Scaleform::GFx::ASStringManager *)-104i64 )
    ++p_NullStringNode->RefCount;
  result->pObject = p_NullStringNode;
  return result;
}

// File Line: 1040
// RVA: 0x8D6880
Scaleform::GFx::AS3::Value *__fastcall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::GetDefaultValue(
        Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value *Null; // rax

  Null = Scaleform::GFx::AS3::Value::GetNull();
  result->Flags = Null->Flags;
  result->Bonus.pWeakProxy = Null->Bonus.pWeakProxy;
  result->value = Null->value;
  if ( (Null->Flags & 0x1F) > 9 )
  {
    if ( (Null->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(Null);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(Null);
  }
  return result;
}

