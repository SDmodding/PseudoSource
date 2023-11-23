// File Line: 28
// RVA: 0x8BD4A0
int __fastcall Scaleform::GFx::AS3::Impl::CompareAsStringInd::Compare(
        Scaleform::GFx::AS3::Impl::CompareAsStringInd *this,
        Scaleform::GFx::ASString *a,
        Scaleform::GFx::ASString *b)
{
  int result; // eax
  const char *pData; // rax
  const char *v6; // rdx
  unsigned __int8 v7; // cl

  if ( this->UseLocale )
  {
    if ( this->Desc )
      return Scaleform::GFx::ASString::LocaleCompare_CaseCheck(b, a, !this->CaseInsensitive);
    else
      return Scaleform::GFx::ASString::LocaleCompare_CaseCheck(a, b, !this->CaseInsensitive);
  }
  else
  {
    if ( this->CaseInsensitive )
    {
      result = Scaleform::String::CompareNoCase(a->pNode->pData, b->pNode->pData);
    }
    else
    {
      pData = a->pNode->pData;
      v6 = (const char *)(b->pNode->pData - pData);
      while ( 1 )
      {
        v7 = *pData;
        if ( *pData != v6[(_QWORD)pData] )
          break;
        ++pData;
        if ( !v7 )
        {
          result = 0;
          goto LABEL_12;
        }
      }
      result = v7 < (unsigned int)v6[(_QWORD)pData] ? -1 : 1;
    }
LABEL_12:
    if ( this->Desc )
      return -result;
  }
  return result;
}

// File Line: 51
// RVA: 0x8BD540
__int64 __fastcall Scaleform::GFx::AS3::Impl::CompareFunct(
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *Funct,
        Scaleform::GFx::AS3::Value *a,
        Scaleform::GFx::AS3::Value *b)
{
  unsigned int v7; // ebx
  unsigned int Flags; // r9d
  unsigned int v9; // ecx
  Scaleform::GFx::AS3::Value *Undefined; // rax
  int v11; // eax
  Scaleform::GFx::AS3::Value result; // [rsp+30h] [rbp-21h] BYREF
  Scaleform::GFx::AS3::Value ptr; // [rsp+58h] [rbp+7h] BYREF
  unsigned int v15; // [rsp+78h] [rbp+27h]
  Scaleform::GFx::AS3::Value::Extra v16; // [rsp+80h] [rbp+2Fh]
  Scaleform::GFx::AS3::Value::VU value; // [rsp+88h] [rbp+37h]
  Scaleform::GFx::AS3::CheckResult v18[8]; // [rsp+B8h] [rbp+67h] BYREF
  void *retaddr; // [rsp+C8h] [rbp+77h] BYREF

  v7 = 0;
  result.Flags = 0;
  result.Bonus.pWeakProxy = 0i64;
  Flags = a->Flags;
  ptr.Flags = Flags;
  ptr.Bonus.pWeakProxy = a->Bonus.pWeakProxy;
  ptr.value = a->value;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(a);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(a);
  }
  v9 = b->Flags;
  v15 = v9;
  v16.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)b->Bonus;
  value = b->value;
  if ( (v9 & 0x1F) > 9 )
  {
    if ( (v9 & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(b);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(b);
  }
  Undefined = Scaleform::GFx::AS3::Value::GetUndefined();
  Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(vm, Funct, Undefined, &result, 2u, &ptr, 0);
  if ( !vm->HandleException && Scaleform::GFx::AS3::Value::Convert2Number(&result, v18, (long double *)&retaddr)->Result )
  {
    *(_QWORD *)&v18[0].Result = retaddr;
    if ( *(double *)&retaddr == -INFINITY )
    {
      v7 = -1;
    }
    else
    {
      *(_QWORD *)&v18[0].Result = retaddr;
      if ( *(double *)&retaddr == INFINITY )
      {
        v7 = 1;
      }
      else
      {
        *(_QWORD *)&v18[0].Result = retaddr;
        if ( retaddr == *(void **)GFxNEGATIVE_ZERO_Bytes )
        {
          v7 = -1;
        }
        else
        {
          *(_QWORD *)&v18[0].Result = retaddr;
          if ( retaddr == *(void **)GFxPOSITIVE_ZERO_Bytes )
          {
            v7 = 1;
          }
          else if ( *(double *)&retaddr != 0.0 )
          {
            v11 = 1;
            if ( *(double *)&retaddr < 0.0 )
              v11 = -1;
            v7 = v11;
          }
        }
      }
    }
  }
  `eh vector destructor iterator(&ptr, 0x20ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
  if ( (result.Flags & 0x1F) > 9 )
  {
    if ( (result.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&result);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
  }
  return v7;
}

// File Line: 88
// RVA: 0x8A3220
void __fastcall Scaleform::GFx::AS3::ArrayBase::~ArrayBase(Scaleform::GFx::AS3::ArrayBase *this)
{
  this->vfptr = (Scaleform::GFx::AS3::ArrayBaseVtbl *)&Scaleform::GFx::AS3::ArrayBase::`vftable;
}

// File Line: 94
// RVA: 0x8AA0B0
void __fastcall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::Value2NumberCollector::operator()(
        Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::Value2NumberCollector *this,
        unsigned int ind,
        Scaleform::GFx::AS3::Value *v)
{
  Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *Pairs; // rdi
  long double v6; // xmm6_8
  unsigned __int64 v7; // rbx
  unsigned __int64 v8; // r8
  Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long> *Data; // rcx
  long double *v10; // rcx
  __int64 v11; // xmm0_8
  long double v12[2]; // [rsp+20h] [rbp-38h] BYREF
  __int64 v13; // [rsp+30h] [rbp-28h]
  Scaleform::GFx::AS3::CheckResult result; // [rsp+78h] [rbp+20h] BYREF

  if ( Scaleform::GFx::AS3::Value::Convert2Number(v, &result, v12)->Result )
  {
    Pairs = (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)this->Pairs;
    LODWORD(v13) = ind;
    v6 = v12[0];
    v7 = Pairs->Size + 1;
    if ( v7 >= Pairs->Size )
    {
      if ( v7 <= Pairs->Policy.Capacity )
        goto LABEL_8;
      v8 = v7 + (v7 >> 2);
    }
    else
    {
      if ( v7 >= Pairs->Policy.Capacity >> 1 )
        goto LABEL_8;
      v8 = Pairs->Size + 1;
    }
    Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      Pairs,
      Pairs[1].Data,
      v8);
LABEL_8:
    Data = Pairs->Data;
    Pairs->Size = v7;
    v10 = (long double *)&Data[v7 - 1];
    if ( v10 )
    {
      v11 = v13;
      *v10 = v6;
      *((_QWORD *)v10 + 1) = v11;
    }
  }
}

// File Line: 106
// RVA: 0x8A9FB0
void __fastcall Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Value2NumberCollector::operator()(
        Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> >::Value2NumberCollector *this,
        unsigned int ind,
        Scaleform::Ptr<Scaleform::GFx::ASStringNode> *v)
{
  long double v5; // xmm6_8
  Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *Pairs; // rdi
  unsigned __int64 v7; // rbx
  unsigned __int64 v8; // r8
  Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long> *v9; // rcx
  __int64 v10; // [rsp+30h] [rbp-48h]
  Scaleform::GFx::AS3::Value v11; // [rsp+38h] [rbp-40h] BYREF
  Scaleform::GFx::AS3::CheckResult result; // [rsp+90h] [rbp+18h] BYREF
  long double v13; // [rsp+98h] [rbp+20h] BYREF

  Scaleform::GFx::AS3::Value::Value(&v11, v->pObject);
  if ( !Scaleform::GFx::AS3::Value::Convert2Number(&v11, &result, &v13)->Result )
    goto LABEL_10;
  v5 = v13;
  LODWORD(v10) = ind;
  Pairs = (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)this->Pairs;
  v7 = Pairs->Size + 1;
  if ( v7 >= Pairs->Size )
  {
    if ( v7 <= Pairs->Policy.Capacity )
      goto LABEL_8;
    v8 = v7 + (v7 >> 2);
  }
  else
  {
    if ( v7 >= Pairs->Policy.Capacity >> 1 )
      goto LABEL_8;
    v8 = Pairs->Size + 1;
  }
  Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    Pairs,
    Pairs[1].Data,
    v8);
LABEL_8:
  Pairs->Size = v7;
  v9 = &Pairs->Data[v7 - 1];
  if ( v9 )
  {
    *(long double *)&v9->First = v5;
    *(_QWORD *)&v9->Second = v10;
  }
LABEL_10:
  if ( (v11.Flags & 0x1F) > 9 )
  {
    if ( (v11.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v11);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v11);
  }
}

// File Line: 119
// RVA: 0x8A9F20
void __fastcall Scaleform::GFx::AS3::VectorBase<double>::Value2NumberCollector::operator()(
        Scaleform::GFx::AS3::VectorBase<double>::Value2NumberCollector *this,
        unsigned int ind,
        const long double *v)
{
  Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *Pairs; // rdi
  Scaleform::GFx::AS3::Value *v4; // xmm6_8
  unsigned __int64 v5; // rbx
  unsigned __int64 v6; // r8
  Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long> *Data; // rcx
  Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long> *v8; // rcx
  __int64 v9; // [rsp+28h] [rbp-20h]

  Pairs = (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)this->Pairs;
  v4 = *(Scaleform::GFx::AS3::Value **)v;
  LODWORD(v9) = ind;
  v5 = Pairs->Size + 1;
  if ( v5 >= Pairs->Size )
  {
    if ( v5 <= Pairs->Policy.Capacity )
      goto LABEL_7;
    v6 = v5 + (v5 >> 2);
  }
  else
  {
    if ( v5 >= Pairs->Policy.Capacity >> 1 )
      goto LABEL_7;
    v6 = Pairs->Size + 1;
  }
  Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    Pairs,
    Pairs[1].Data,
    v6);
LABEL_7:
  Data = Pairs->Data;
  Pairs->Size = v5;
  v8 = &Data[v5 - 1];
  if ( v8 )
  {
    v8->First = v4;
    *(_QWORD *)&v8->Second = v9;
  }
}

// File Line: 128
// RVA: 0x8A9E90
void __fastcall Scaleform::GFx::AS3::VectorBase<unsigned long>::Value2NumberCollector::operator()(
        Scaleform::GFx::AS3::VectorBase<unsigned long>::Value2NumberCollector *this,
        unsigned int ind,
        const unsigned int *v)
{
  Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *Pairs; // rdi
  double v4; // xmm6_8
  unsigned __int64 v5; // rbx
  unsigned __int64 v6; // r8
  Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long> *Data; // rcx
  __int64 v8; // rcx
  __int64 v9; // [rsp+28h] [rbp-20h]

  Pairs = (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)this->Pairs;
  LODWORD(v9) = ind;
  v4 = (double)*(int *)v;
  v5 = Pairs->Size + 1;
  if ( v5 >= Pairs->Size )
  {
    if ( v5 <= Pairs->Policy.Capacity )
      goto LABEL_7;
    v6 = v5 + (v5 >> 2);
  }
  else
  {
    if ( v5 >= Pairs->Policy.Capacity >> 1 )
      goto LABEL_7;
    v6 = Pairs->Size + 1;
  }
  Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    Pairs,
    Pairs[1].Data,
    v6);
LABEL_7:
  Data = Pairs->Data;
  Pairs->Size = v5;
  v8 = (__int64)&Data[v5 - 1];
  if ( v8 )
  {
    *(double *)v8 = v4;
    *(_QWORD *)(v8 + 8) = v9;
  }
}

// File Line: 137
// RVA: 0x8A9E00
void __fastcall Scaleform::GFx::AS3::VectorBase<long>::Value2NumberCollector::operator()(
        Scaleform::GFx::AS3::VectorBase<long>::Value2NumberCollector *this,
        unsigned int ind,
        const int *v)
{
  Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *Pairs; // rdi
  double v4; // xmm6_8
  unsigned __int64 v5; // rbx
  unsigned __int64 v6; // r8
  Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long> *Data; // rcx
  __int64 v8; // rcx
  __int64 v9; // [rsp+28h] [rbp-20h]

  Pairs = (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)this->Pairs;
  LODWORD(v9) = ind;
  v4 = (double)*v;
  v5 = Pairs->Size + 1;
  if ( v5 >= Pairs->Size )
  {
    if ( v5 <= Pairs->Policy.Capacity )
      goto LABEL_7;
    v6 = v5 + (v5 >> 2);
  }
  else
  {
    if ( v5 >= Pairs->Policy.Capacity >> 1 )
      goto LABEL_7;
    v6 = Pairs->Size + 1;
  }
  Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    Pairs,
    Pairs[1].Data,
    v6);
LABEL_7:
  Data = Pairs->Data;
  Pairs->Size = v5;
  v8 = (__int64)&Data[v5 - 1];
  if ( v8 )
  {
    *(double *)v8 = v4;
    *(_QWORD *)(v8 + 8) = v9;
  }
}

// File Line: 147
// RVA: 0x8AA550
void __fastcall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::Value2StrCollector::operator()(
        Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::Value2StrCollector *this,
        unsigned int ind,
        Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::ASStringNode *pNode; // rdi
  Scaleform::ArrayDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2,Scaleform::ArrayDefaultPolicy> *Pairs; // rbx
  __int64 v8; // rcx
  __int64 v9; // rdx
  bool v10; // zf
  __int64 v11; // rdx
  Scaleform::GFx::ASStringNode *v12; // rcx
  __int64 v13; // [rsp+60h] [rbp+8h] BYREF
  Scaleform::GFx::ASString result; // [rsp+78h] [rbp+20h] BYREF

  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    this->Vm->StringManagerRef,
    &result);
  if ( Scaleform::GFx::AS3::Value::Convert2String(v, (Scaleform::GFx::AS3::CheckResult *)&v13, &result)->Result )
  {
    pNode = result.pNode;
    ++result.pNode->RefCount;
    Pairs = this->Pairs;
    Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &Pairs->Data,
      Pairs->Data.pHeap,
      Pairs->Data.Size + 1);
    v8 = 16 * Pairs->Data.Size;
    v9 = (__int64)&Pairs->Data.Data[-1];
    v10 = v8 + v9 == 0;
    v11 = v8 + v9;
    v13 = v11;
    if ( !v10 )
    {
      *(_QWORD *)v11 = pNode;
      ++pNode->RefCount;
      *(_DWORD *)(v11 + 8) = ind;
    }
    v10 = pNode->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  v12 = result.pNode;
  v10 = result.pNode->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
}

// File Line: 161
// RVA: 0x8AA4C0
void __fastcall Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Value2StrCollector::operator()(
        Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> >::Value2StrCollector *this,
        unsigned int ind,
        Scaleform::Ptr<Scaleform::GFx::ASStringNode> *v)
{
  Scaleform::GFx::ASStringNode *pObject; // rdi
  Scaleform::ArrayDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2,Scaleform::ArrayDefaultPolicy> *Pairs; // rbx
  __int64 v6; // rdx
  bool v7; // zf

  pObject = v->pObject;
  ++pObject->RefCount;
  ++pObject->RefCount;
  Pairs = this->Pairs;
  Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &Pairs->Data,
    Pairs->Data.pHeap,
    Pairs->Data.Size + 1);
  v6 = (__int64)&Pairs->Data.Data[Pairs->Data.Size - 1];
  if ( v6 )
  {
    *(_QWORD *)v6 = pObject;
    ++pObject->RefCount;
    *(_DWORD *)(v6 + 8) = ind;
  }
  v7 = pObject->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pObject);
  v7 = pObject->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pObject);
}

// File Line: 170
// RVA: 0x8AA3A0
void __fastcall Scaleform::GFx::AS3::VectorBase<double>::Value2StrCollector::operator()(
        Scaleform::GFx::AS3::VectorBase<double>::Value2StrCollector *this,
        unsigned int ind,
        Scaleform::GFx::AS3::Value::V1U *v)
{
  Scaleform::GFx::AS3::Value::V1U v6; // xmm0_8
  bool v7; // bl
  Scaleform::GFx::ASStringNode *pNode; // rdi
  Scaleform::ArrayDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2,Scaleform::ArrayDefaultPolicy> *Pairs; // rbx
  __int64 v10; // rcx
  __int64 v11; // rdx
  bool v12; // zf
  __int64 v13; // rdx
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::AS3::Value v15; // [rsp+28h] [rbp-40h] BYREF
  __int64 v16; // [rsp+70h] [rbp+8h] BYREF
  Scaleform::GFx::ASString result; // [rsp+80h] [rbp+18h] BYREF
  __int64 v18; // [rsp+88h] [rbp+20h]

  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    this->Vm->StringManagerRef,
    &result);
  v6 = *v;
  v15.Flags = 4;
  v15.Bonus.pWeakProxy = 0i64;
  v15.value.VS._1 = v6;
  v7 = !Scaleform::GFx::AS3::Value::Convert2String(&v15, (Scaleform::GFx::AS3::CheckResult *)&v16, &result)->Result;
  if ( (v15.Flags & 0x1F) > 9 )
  {
    if ( (v15.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v15);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v15);
  }
  if ( !v7 )
  {
    pNode = result.pNode;
    *(Scaleform::GFx::ASString *)&v15.Flags = result;
    ++result.pNode->RefCount;
    LODWORD(v15.Bonus.pWeakProxy) = ind;
    Pairs = this->Pairs;
    Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &Pairs->Data,
      Pairs->Data.pHeap,
      Pairs->Data.Size + 1);
    v10 = 16 * Pairs->Data.Size;
    v11 = (__int64)&Pairs->Data.Data[-1];
    v12 = v10 + v11 == 0;
    v13 = v10 + v11;
    v16 = v13;
    v18 = v13;
    if ( !v12 )
    {
      *(_QWORD *)v13 = pNode;
      ++pNode->RefCount;
      *(_DWORD *)(v13 + 8) = ind;
    }
    v12 = pNode->RefCount-- == 1;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  v14 = result.pNode;
  v12 = result.pNode->RefCount-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
}

// File Line: 184
// RVA: 0x8AA280
void __fastcall Scaleform::GFx::AS3::VectorBase<unsigned long>::Value2StrCollector::operator()(
        Scaleform::GFx::AS3::VectorBase<unsigned long>::Value2StrCollector *this,
        unsigned int ind,
        const unsigned int *v)
{
  int v6; // eax
  bool v7; // bl
  Scaleform::GFx::ASStringNode *pNode; // rdi
  Scaleform::ArrayDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2,Scaleform::ArrayDefaultPolicy> *Pairs; // rbx
  __int64 v10; // rcx
  __int64 v11; // rdx
  bool v12; // zf
  __int64 v13; // rdx
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::AS3::Value v15; // [rsp+28h] [rbp-40h] BYREF
  __int64 v16; // [rsp+70h] [rbp+8h] BYREF
  Scaleform::GFx::ASString result; // [rsp+80h] [rbp+18h] BYREF
  __int64 v18; // [rsp+88h] [rbp+20h]

  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    this->Vm->StringManagerRef,
    &result);
  v6 = *v;
  v15.Flags = 3;
  v15.Bonus.pWeakProxy = 0i64;
  v15.value.VS._1.VInt = v6;
  v7 = !Scaleform::GFx::AS3::Value::Convert2String(&v15, (Scaleform::GFx::AS3::CheckResult *)&v16, &result)->Result;
  if ( (v15.Flags & 0x1F) > 9 )
  {
    if ( (v15.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v15);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v15);
  }
  if ( !v7 )
  {
    pNode = result.pNode;
    *(Scaleform::GFx::ASString *)&v15.Flags = result;
    ++result.pNode->RefCount;
    LODWORD(v15.Bonus.pWeakProxy) = ind;
    Pairs = this->Pairs;
    Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &Pairs->Data,
      Pairs->Data.pHeap,
      Pairs->Data.Size + 1);
    v10 = 16 * Pairs->Data.Size;
    v11 = (__int64)&Pairs->Data.Data[-1];
    v12 = v10 + v11 == 0;
    v13 = v10 + v11;
    v16 = v13;
    v18 = v13;
    if ( !v12 )
    {
      *(_QWORD *)v13 = pNode;
      ++pNode->RefCount;
      *(_DWORD *)(v13 + 8) = ind;
    }
    v12 = pNode->RefCount-- == 1;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  v14 = result.pNode;
  v12 = result.pNode->RefCount-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
}

// File Line: 198
// RVA: 0x8AA160
void __fastcall Scaleform::GFx::AS3::VectorBase<long>::Value2StrCollector::operator()(
        Scaleform::GFx::AS3::VectorBase<long>::Value2StrCollector *this,
        unsigned int ind,
        int *v)
{
  int v6; // eax
  bool v7; // bl
  Scaleform::GFx::ASStringNode *pNode; // rdi
  Scaleform::ArrayDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2,Scaleform::ArrayDefaultPolicy> *Pairs; // rbx
  __int64 v10; // rcx
  __int64 v11; // rdx
  bool v12; // zf
  __int64 v13; // rdx
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::AS3::Value v15; // [rsp+28h] [rbp-40h] BYREF
  __int64 v16; // [rsp+70h] [rbp+8h] BYREF
  Scaleform::GFx::ASString result; // [rsp+80h] [rbp+18h] BYREF
  __int64 v18; // [rsp+88h] [rbp+20h]

  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    this->Vm->StringManagerRef,
    &result);
  v6 = *v;
  v15.Flags = 2;
  v15.Bonus.pWeakProxy = 0i64;
  v15.value.VS._1.VInt = v6;
  v7 = !Scaleform::GFx::AS3::Value::Convert2String(&v15, (Scaleform::GFx::AS3::CheckResult *)&v16, &result)->Result;
  if ( (v15.Flags & 0x1F) > 9 )
  {
    if ( (v15.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v15);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v15);
  }
  if ( !v7 )
  {
    pNode = result.pNode;
    *(Scaleform::GFx::ASString *)&v15.Flags = result;
    ++result.pNode->RefCount;
    LODWORD(v15.Bonus.pWeakProxy) = ind;
    Pairs = this->Pairs;
    Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &Pairs->Data,
      Pairs->Data.pHeap,
      Pairs->Data.Size + 1);
    v10 = 16 * Pairs->Data.Size;
    v11 = (__int64)&Pairs->Data.Data[-1];
    v12 = v10 + v11 == 0;
    v13 = v10 + v11;
    v16 = v13;
    v18 = v13;
    if ( !v12 )
    {
      *(_QWORD *)v13 = pNode;
      ++pNode->RefCount;
      *(_DWORD *)(v13 + 8) = ind;
    }
    v12 = pNode->RefCount-- == 1;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  v14 = result.pNode;
  v12 = result.pNode->RefCount-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
}

// File Line: 212
// RVA: 0x8EC160
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::ArrayBase::OfCorrectType(
        Scaleform::GFx::AS3::ArrayBase *this,
        Scaleform::GFx::AS3::CheckResult *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *const argv,
        Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  int v5; // ebx
  Scaleform::GFx::AS3::ClassTraits::Traits *v10; // rbp
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+50h] [rbp+18h] BYREF

  v5 = 0;
  if ( argc )
  {
    v10 = tr;
    while ( Scaleform::GFx::AS3::ArrayBase::OfCorrectType(this, &resulta, &argv[v5], v10)->Result )
    {
      if ( ++v5 >= argc )
        goto LABEL_5;
    }
    result->Result = 0;
  }
  else
  {
LABEL_5:
    result->Result = 1;
  }
  return result;
}

// File Line: 238
// RVA: 0x8BAE70
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::ArrayBase::CheckFixed(
        Scaleform::GFx::AS3::ArrayBase *this,
        Scaleform::GFx::AS3::CheckResult *result)
{
  Scaleform::GFx::AS3::VM::Error *v4; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v8; // [rsp+28h] [rbp-20h] BYREF

  if ( this->Fixed )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v8, 1126, this->VMRef);
    Scaleform::GFx::AS3::VM::ThrowRangeError(this->VMRef, v4);
    pNode = v8.Message.pNode;
    if ( v8.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  result->Result = !this->Fixed;
  return result;
}

// File Line: 246
// RVA: 0x8BA8F0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::ArrayBase::CheckCorrectType(
        Scaleform::GFx::AS3::ArrayBase *this,
        Scaleform::GFx::AS3::CheckResult *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *const argv,
        Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  Scaleform::GFx::AS3::VM *VMRef; // rbx
  Scaleform::GFx::AS3::VM::Error *v8; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v12; // [rsp+38h] [rbp-20h] BYREF
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+68h] [rbp+10h] BYREF

  if ( Scaleform::GFx::AS3::ArrayBase::OfCorrectType(this, &resulta, argc, argv, tr)->Result )
  {
    result->Result = 1;
  }
  else
  {
    VMRef = this->VMRef;
    Scaleform::GFx::AS3::VM::Error::Error(&v12, 1034, VMRef);
    Scaleform::GFx::AS3::VM::ThrowTypeError(VMRef, v8);
    pNode = v12.Message.pNode;
    if ( v12.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    result->Result = 0;
  }
  return result;
}

// File Line: 284
// RVA: 0x8BA7F0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::ArrayBase::CheckCallable(
        Scaleform::GFx::AS3::ArrayBase *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Value *callback)
{
  Scaleform::GFx::AS3::VM *VMRef; // rbx
  Scaleform::GFx::AS3::VM::Error *v5; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v9; // [rsp+28h] [rbp-20h] BYREF

  if ( (callback->Flags & 0x1F) <= 4 || (callback->Flags & 0x1F) - 8 <= 3 )
  {
    VMRef = this->VMRef;
    Scaleform::GFx::AS3::VM::Error::Error(&v9, 1034, VMRef);
    Scaleform::GFx::AS3::VM::ThrowTypeError(VMRef, v5);
    pNode = v9.Message.pNode;
    if ( v9.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    result->Result = 0;
  }
  else
  {
    result->Result = 1;
  }
  return result;
}

// File Line: 303
// RVA: 0x8BA870
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::ArrayBase::CheckCoerce(
        Scaleform::GFx::AS3::ArrayBase *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::ClassTraits::Traits *tr,
        Scaleform::GFx::AS3::Value *v,
        Scaleform::GFx::AS3::Value *coerced)
{
  Scaleform::GFx::AS3::VM *VMRef; // rbx
  Scaleform::GFx::AS3::VM::Error *v8; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v12; // [rsp+28h] [rbp-20h] BYREF

  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::ClassTraits::Traits *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))tr->vfptr[3].Finalize_GC)(
         tr,
         v,
         coerced) )
  {
    result->Result = 1;
  }
  else
  {
    VMRef = this->VMRef;
    Scaleform::GFx::AS3::VM::Error::Error(&v12, 1034, VMRef);
    Scaleform::GFx::AS3::VM::ThrowTypeError(VMRef, v8);
    pNode = v12.Message.pNode;
    if ( v12.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    result->Result = 0;
  }
  return result;
}

// File Line: 322
// RVA: 0x912E00
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::ArrayBase::ToString(
        Scaleform::GFx::AS3::ArrayBase *this,
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::ASString *sep)
{
  unsigned int v6; // edi
  unsigned int v7; // ebx
  char *pData; // r8
  Scaleform::GFx::AS3::Value v10; // [rsp+30h] [rbp-78h] BYREF
  Scaleform::StringBuffer v11; // [rsp+50h] [rbp-58h] BYREF
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+B0h] [rbp+8h] BYREF
  Scaleform::GFx::ASString *v13; // [rsp+B8h] [rbp+10h]

  v13 = result;
  Scaleform::StringBuffer::StringBuffer(&v11, this->VMRef->MHeap);
  v6 = this->vfptr->GetArraySize(this);
  v7 = 0;
  if ( v6 )
  {
    while ( 1 )
    {
      if ( v7 )
        Scaleform::StringBuffer::AppendString(&v11, sep->pNode->pData, -1i64);
      v10.Flags = 0;
      v10.Bonus.pWeakProxy = 0i64;
      this->vfptr->GetValueUnsafe(this, v7, &v10);
      if ( !Scaleform::GFx::AS3::Value::Convert2String(&v10, &resulta, &v11)->Result )
        break;
      if ( (v10.Flags & 0x1F) > 9 )
      {
        if ( (v10.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v10);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
      }
      if ( ++v7 >= v6 )
        goto LABEL_15;
    }
    if ( (v10.Flags & 0x1F) > 9 )
    {
      if ( (v10.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v10);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
    }
  }
LABEL_15:
  pData = &customCaption;
  if ( v11.pData )
    pData = v11.pData;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
    this->VMRef->StringManagerRef,
    result,
    pData,
    v11.Size);
  Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&v11);
  return result;
}

// File Line: 380
// RVA: 0x8B6610
void __fastcall Scaleform::GFx::AS3::ArrayBase::AppendCoerce(
        Scaleform::GFx::AS3::ArrayBase *this,
        Scaleform::GFx::AS3::Instances::fl::Array *arr,
        Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  Scaleform::GFx::AS3::Impl::SparseArray *p_SA; // r14
  unsigned __int64 Length; // rsi
  unsigned __int64 v8; // rbx
  Scaleform::GFx::AS3::Value *v9; // rax
  Scaleform::GFx::AS3::Value coerced; // [rsp+38h] [rbp-40h] BYREF
  Scaleform::GFx::AS3::CheckResult result; // [rsp+98h] [rbp+20h] BYREF

  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &result)->Result )
  {
    p_SA = &arr->SA;
    Length = arr->SA.Length;
    v8 = 0i64;
    if ( Length )
    {
      while ( 1 )
      {
        coerced.Flags = 0;
        coerced.Bonus.pWeakProxy = 0i64;
        v9 = Scaleform::GFx::AS3::Impl::SparseArray::At(p_SA, v8);
        if ( !Scaleform::GFx::AS3::ArrayBase::CheckCoerce(this, &result, tr, v9, &coerced)->Result )
          break;
        this->vfptr->PushBackValueUnsafe(this, &coerced);
        if ( (coerced.Flags & 0x1F) > 9 )
        {
          if ( (coerced.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&coerced);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&coerced);
        }
        if ( ++v8 >= Length )
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
  }
}

// File Line: 397
// RVA: 0x8B64A0
void __fastcall Scaleform::GFx::AS3::ArrayBase::AppendCoerce(
        Scaleform::GFx::AS3::ArrayBase *this,
        Scaleform::GFx::AS3::ArrayBase *arr,
        Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  unsigned int v6; // esi
  unsigned int v7; // ebx
  Scaleform::GFx::AS3::Value v; // [rsp+38h] [rbp-48h] BYREF
  Scaleform::GFx::AS3::Value coerced; // [rsp+58h] [rbp-28h] BYREF
  Scaleform::GFx::AS3::CheckResult result; // [rsp+C8h] [rbp+48h] BYREF

  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &result)->Result )
  {
    v6 = arr->vfptr->GetArraySize(arr);
    v7 = 0;
    if ( v6 )
    {
      while ( 1 )
      {
        coerced.Flags = 0;
        coerced.Bonus.pWeakProxy = 0i64;
        v.Flags = 0;
        v.Bonus.pWeakProxy = 0i64;
        arr->vfptr->GetValueUnsafe(arr, v7, &v);
        if ( !Scaleform::GFx::AS3::ArrayBase::CheckCoerce(this, &result, tr, &v, &coerced)->Result )
          break;
        this->vfptr->PushBackValueUnsafe(this, &coerced);
        if ( (v.Flags & 0x1F) > 9 )
        {
          if ( (v.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
        }
        if ( (coerced.Flags & 0x1F) > 9 )
        {
          if ( (coerced.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&coerced);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&coerced);
        }
        if ( ++v7 >= v6 )
          return;
      }
      if ( (v.Flags & 0x1F) > 9 )
      {
        if ( (v.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
      }
      if ( (coerced.Flags & 0x1F) > 9 )
      {
        if ( (coerced.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&coerced);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&coerced);
      }
    }
  }
}

// File Line: 416
// RVA: 0x8B6730
bool __fastcall Scaleform::GFx::AS3::ArrayBase::AppendCoerce(
        Scaleform::GFx::AS3::ArrayBase *this,
        Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  Scaleform::GFx::AS3::VM *VMRef; // rbp
  Scaleform::GFx::AS3::Traits *ValueTraits; // rax
  bool result; // al

  VMRef = this->VMRef;
  ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(VMRef, value);
  if ( (ValueTraits->Flags & 0x20) != 0 )
    return 0;
  switch ( ValueTraits->TraitsType )
  {
    case Traits_Array:
      Scaleform::GFx::AS3::ArrayBase::AppendCoerce(
        this,
        (Scaleform::GFx::AS3::Instances::fl::Array *)value->value.VS._1.VStr,
        tr);
      result = !this->VMRef->HandleException;
      break;
    case Traits_Vector_int:
    case Traits_Vector_uint:
    case Traits_Vector_double:
    case Traits_Vector_String:
    case Traits_Vector_object:
      Scaleform::GFx::AS3::ArrayBase::AppendCoerce(
        this,
        (Scaleform::GFx::AS3::ArrayBase *)&value->value.VS._1.VStr[1].16,
        tr);
      result = !VMRef->HandleException;
      break;
    default:
      return 0;
  }
  return result;
}

// File Line: 465
// RVA: 0x8C9020
bool __fastcall Scaleform::GFx::AS3::ArrayBase::Every(
        Scaleform::GFx::AS3::ArrayBase *this,
        Scaleform::GFx::AS3::Value *callback,
        Scaleform::GFx::AS3::Value *thisObject,
        Scaleform::GFx::AS3::Object *currObj)
{
  unsigned int v8; // r10d
  unsigned int v9; // ebx
  unsigned int v10; // ecx
  bool v11; // al
  Scaleform::GFx::AS3::Value *v12; // rcx
  unsigned int Flags; // edx
  unsigned int v14; // edi
  Scaleform::GFx::AS3::Value *Undefined; // rax
  bool v16; // bl
  Scaleform::GFx::AS3::Value v18; // [rsp+18h] [rbp-79h] BYREF
  Scaleform::GFx::AS3::Value _this; // [rsp+38h] [rbp-59h] BYREF
  __int64 v20; // [rsp+58h] [rbp-39h]
  Scaleform::GFx::AS3::Value argv; // [rsp+68h] [rbp-29h] BYREF
  int v22; // [rsp+88h] [rbp-9h]
  __int64 v23; // [rsp+90h] [rbp-1h]
  unsigned int v24; // [rsp+98h] [rbp+7h]
  Scaleform::GFx::AS3::Value v25; // [rsp+A8h] [rbp+17h] BYREF
  Scaleform::GFx::AS3::CheckResult result; // [rsp+100h] [rbp+6Fh] BYREF

  v20 = -2i64;
  v8 = callback->Flags & 0x1F;
  if ( !v8
    || (v8 - 12 <= 3 || v8 == 10) && !callback->value.VS._1.VStr
    || !Scaleform::GFx::AS3::ArrayBase::CheckCallable(this, &result, callback)->Result )
  {
    return 0;
  }
  v9 = 0;
  v10 = thisObject->Flags & 0x1F;
  v11 = !v10 || (v10 - 12 <= 3 || v10 == 10) && !thisObject->value.VS._1.VStr;
  v12 = callback;
  if ( !v11 )
    v12 = thisObject;
  Flags = v12->Flags;
  _this.Flags = Flags;
  _this.Bonus.pWeakProxy = v12->Bonus.pWeakProxy;
  _this.value = v12->value;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(v12);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(v12);
  }
  v14 = this->vfptr->GetArraySize(this);
  if ( v14 )
  {
    while ( 1 )
    {
      Undefined = Scaleform::GFx::AS3::Value::GetUndefined();
      argv.Flags = Undefined->Flags;
      argv.Bonus.pWeakProxy = Undefined->Bonus.pWeakProxy;
      argv.value = Undefined->value;
      if ( (Undefined->Flags & 0x1F) > 9 )
      {
        if ( (Undefined->Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
        else
          Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
      }
      v22 = 3;
      v23 = 0i64;
      v24 = v9;
      Scaleform::GFx::AS3::Value::Value(&v25, currObj);
      v18.Flags = 0;
      v18.Bonus.pWeakProxy = 0i64;
      this->vfptr->GetValueUnsafe(this, v9, &argv);
      Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(this->VMRef, callback, &_this, &v18, 3u, &argv, 0);
      if ( this->VMRef->HandleException || (v18.Flags & 0x1F) != 1 || !v18.value.VS._1.VBool )
        break;
      if ( (v18.Flags & 0x1F) > 9 )
      {
        if ( (v18.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v18);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v18);
      }
      `eh vector destructor iterator(
        &argv,
        0x20ui64,
        3,
        (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
      if ( ++v9 >= v14 )
        goto LABEL_37;
    }
    if ( (v18.Flags & 0x1F) > 9 )
    {
      if ( (v18.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v18);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v18);
    }
    `eh vector destructor iterator(&argv, 0x20ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
  }
LABEL_37:
  v16 = v9 == v14;
  if ( (_this.Flags & 0x1F) > 9 )
  {
    if ( (_this.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&_this);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
  }
  return v16;
}

// File Line: 499
// RVA: 0x8CD7B0
void __fastcall Scaleform::GFx::AS3::ArrayBase::ForEach(
        Scaleform::GFx::AS3::ArrayBase *this,
        Scaleform::GFx::AS3::Value *callback,
        Scaleform::GFx::AS3::Value *thisObject,
        Scaleform::GFx::AS3::Object *currObj)
{
  unsigned int v8; // r10d
  unsigned int v9; // ecx
  bool v10; // al
  Scaleform::GFx::AS3::Value *v11; // rcx
  unsigned int Flags; // edx
  unsigned int v13; // r14d
  unsigned int v14; // ebx
  Scaleform::GFx::AS3::Value *Undefined; // rax
  Scaleform::GFx::AS3::Value v16; // [rsp+18h] [rbp-79h] BYREF
  Scaleform::GFx::AS3::Value _this; // [rsp+38h] [rbp-59h] BYREF
  __int64 v18; // [rsp+58h] [rbp-39h]
  Scaleform::GFx::AS3::Value argv; // [rsp+68h] [rbp-29h] BYREF
  int v20; // [rsp+88h] [rbp-9h]
  __int64 v21; // [rsp+90h] [rbp-1h]
  unsigned int v22; // [rsp+98h] [rbp+7h]
  Scaleform::GFx::AS3::Value v23; // [rsp+A8h] [rbp+17h] BYREF
  Scaleform::GFx::AS3::CheckResult result; // [rsp+100h] [rbp+6Fh] BYREF

  v18 = -2i64;
  v8 = callback->Flags & 0x1F;
  if ( v8
    && (v8 - 12 > 3 && v8 != 10 || callback->value.VS._1.VStr)
    && Scaleform::GFx::AS3::ArrayBase::CheckCallable(this, &result, callback)->Result )
  {
    v9 = thisObject->Flags & 0x1F;
    v10 = !v9 || (v9 - 12 <= 3 || v9 == 10) && !thisObject->value.VS._1.VStr;
    v11 = callback;
    if ( !v10 )
      v11 = thisObject;
    Flags = v11->Flags;
    _this.Flags = Flags;
    _this.Bonus.pWeakProxy = v11->Bonus.pWeakProxy;
    _this.value = v11->value;
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::AddRefWeakRef(v11);
      else
        Scaleform::GFx::AS3::Value::AddRefInternal(v11);
    }
    v13 = this->vfptr->GetArraySize(this);
    v14 = 0;
    if ( v13 )
    {
      while ( 1 )
      {
        Undefined = Scaleform::GFx::AS3::Value::GetUndefined();
        argv.Flags = Undefined->Flags;
        argv.Bonus.pWeakProxy = Undefined->Bonus.pWeakProxy;
        argv.value = Undefined->value;
        if ( (Undefined->Flags & 0x1F) > 9 )
        {
          if ( (Undefined->Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
          else
            Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
        }
        v20 = 3;
        v21 = 0i64;
        v22 = v14;
        Scaleform::GFx::AS3::Value::Value(&v23, currObj);
        v16.Flags = 0;
        v16.Bonus.pWeakProxy = 0i64;
        this->vfptr->GetValueUnsafe(this, v14, &argv);
        Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(this->VMRef, callback, &_this, &v16, 3u, &argv, 0);
        if ( this->VMRef->HandleException )
          break;
        if ( (v16.Flags & 0x1F) > 9 )
        {
          if ( (v16.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v16);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v16);
        }
        `eh vector destructor iterator(
          &argv,
          0x20ui64,
          3,
          (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
        if ( ++v14 >= v13 )
          goto LABEL_35;
      }
      if ( (v16.Flags & 0x1F) > 9 )
      {
        if ( (v16.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v16);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v16);
      }
      `eh vector destructor iterator(
        &argv,
        0x20ui64,
        3,
        (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
    }
LABEL_35:
    if ( (_this.Flags & 0x1F) > 9 )
    {
      if ( (_this.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&_this);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
    }
  }
}

// File Line: 523
// RVA: 0x910D10
char __fastcall Scaleform::GFx::AS3::ArrayBase::Some(
        Scaleform::GFx::AS3::ArrayBase *this,
        Scaleform::GFx::AS3::Value *callback,
        Scaleform::GFx::AS3::Value *thisObject,
        Scaleform::GFx::AS3::Object *currObj)
{
  unsigned int v8; // r10d
  unsigned int v9; // ecx
  bool v10; // al
  Scaleform::GFx::AS3::Value *v11; // rcx
  unsigned int Flags; // edx
  unsigned int v13; // r14d
  unsigned int v14; // ebx
  Scaleform::GFx::AS3::Value *Undefined; // rax
  char v16; // bl
  Scaleform::GFx::AS3::Value _this; // [rsp+38h] [rbp-81h] BYREF
  Scaleform::GFx::AS3::Value v19; // [rsp+60h] [rbp-59h] BYREF
  __int64 v20; // [rsp+80h] [rbp-39h]
  Scaleform::GFx::AS3::Value argv; // [rsp+90h] [rbp-29h] BYREF
  int v22; // [rsp+B0h] [rbp-9h]
  __int64 v23; // [rsp+B8h] [rbp-1h]
  unsigned int v24; // [rsp+C0h] [rbp+7h]
  Scaleform::GFx::AS3::Value v25; // [rsp+D0h] [rbp+17h] BYREF
  Scaleform::GFx::AS3::CheckResult v26; // [rsp+128h] [rbp+6Fh] BYREF

  v20 = -2i64;
  v8 = callback->Flags & 0x1F;
  if ( !v8
    || (v8 - 12 <= 3 || v8 == 10) && !callback->value.VS._1.VStr
    || !Scaleform::GFx::AS3::ArrayBase::CheckCallable(this, &v26, callback)->Result )
  {
    return 0;
  }
  v9 = thisObject->Flags & 0x1F;
  v10 = !v9 || (v9 - 12 <= 3 || v9 == 10) && !thisObject->value.VS._1.VStr;
  v11 = callback;
  if ( !v10 )
    v11 = thisObject;
  Flags = v11->Flags;
  v19.Flags = Flags;
  v19.Bonus.pWeakProxy = v11->Bonus.pWeakProxy;
  v19.value = v11->value;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(v11);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(v11);
  }
  v13 = this->vfptr->GetArraySize(this);
  v14 = 0;
  if ( v13 )
  {
    while ( 1 )
    {
      Undefined = Scaleform::GFx::AS3::Value::GetUndefined();
      argv.Flags = Undefined->Flags;
      argv.Bonus.pWeakProxy = Undefined->Bonus.pWeakProxy;
      argv.value = Undefined->value;
      if ( (Undefined->Flags & 0x1F) > 9 )
      {
        if ( (Undefined->Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::AddRefWeakRef(Undefined);
        else
          Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
      }
      v22 = 3;
      v23 = 0i64;
      v24 = v14;
      Scaleform::GFx::AS3::Value::Value(&v25, currObj);
      LODWORD(_this.Bonus.pWeakProxy) = 0;
      _this.value.VS._1.VStr = 0i64;
      this->vfptr->GetValueUnsafe(this, v14, &argv);
      Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(
        this->VMRef,
        callback,
        &v19,
        (Scaleform::GFx::AS3::Value *)&_this.Bonus,
        3u,
        &argv,
        0);
      if ( this->VMRef->HandleException )
        break;
      if ( ((__int64)_this.Bonus.pWeakProxy & 0x1F) != 1 )
      {
        v16 = 0;
        goto LABEL_34;
      }
      if ( LOBYTE(_this.value.VS._2.VObj) == 1 )
      {
        v16 = 1;
LABEL_34:
        if ( (unsigned __int64)((__int64)_this.Bonus.pWeakProxy & 0x1F) > 9 )
        {
          if ( ((__int64)_this.Bonus.pWeakProxy & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef((Scaleform::GFx::AS3::Value *)&_this.Bonus);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&_this.Bonus);
        }
        `eh vector destructor iterator(
          &argv,
          0x20ui64,
          3,
          (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
        goto LABEL_45;
      }
      if ( (unsigned __int64)((__int64)_this.Bonus.pWeakProxy & 0x1F) > 9 )
      {
        if ( ((__int64)_this.Bonus.pWeakProxy & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef((Scaleform::GFx::AS3::Value *)&_this.Bonus);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&_this.Bonus);
      }
      `eh vector destructor iterator(
        &argv,
        0x20ui64,
        3,
        (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
      if ( ++v14 >= v13 )
        goto LABEL_44;
    }
    if ( (unsigned __int64)((__int64)_this.Bonus.pWeakProxy & 0x1F) > 9 )
    {
      if ( ((__int64)_this.Bonus.pWeakProxy & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef((Scaleform::GFx::AS3::Value *)&_this.Bonus);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&_this.Bonus);
    }
    `eh vector destructor iterator(&argv, 0x20ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
  }
LABEL_44:
  v16 = 0;
LABEL_45:
  if ( (v19.Flags & 0x1F) > 9 )
  {
    if ( (v19.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v19);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v19);
  }
  return v16;
}

