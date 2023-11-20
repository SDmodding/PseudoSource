// File Line: 28
// RVA: 0x8BD4A0
int __fastcall Scaleform::GFx::AS3::Impl::CompareAsStringInd::Compare(Scaleform::GFx::AS3::Impl::CompareAsStringInd *this, Scaleform::GFx::ASString *a, Scaleform::GFx::ASString *b)
{
  Scaleform::GFx::AS3::Impl::CompareAsStringInd *v3; // rbx
  int result; // eax
  const char *v5; // rax
  const char *v6; // rdx
  unsigned __int8 v7; // cl

  v3 = this;
  if ( this->UseLocale )
  {
    if ( this->Desc )
      result = Scaleform::GFx::ASString::LocaleCompare_CaseCheck(b, a, this->CaseInsensitive == 0);
    else
      result = Scaleform::GFx::ASString::LocaleCompare_CaseCheck(a, b, this->CaseInsensitive == 0);
  }
  else
  {
    if ( this->CaseInsensitive )
    {
      result = Scaleform::String::CompareNoCase(a->pNode->pData, b->pNode->pData);
    }
    else
    {
      v5 = a->pNode->pData;
      v6 = (const char *)(b->pNode->pData - v5);
      while ( 1 )
      {
        v7 = *v5;
        if ( *v5 != v6[(_QWORD)v5] )
          break;
        ++v5;
        if ( !v7 )
        {
          result = 0;
          goto LABEL_12;
        }
      }
      result = -(v7 < v6[(_QWORD)v5]) | 1;
    }
LABEL_12:
    if ( v3->Desc )
      result = -result;
  }
  return result;
}

// File Line: 51
// RVA: 0x8BD540
__int64 __fastcall Scaleform::GFx::AS3::Impl::CompareFunct(Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *Funct, Scaleform::GFx::AS3::Value *a, Scaleform::GFx::AS3::Value *b)
{
  Scaleform::GFx::AS3::Value *v4; // rdi
  Scaleform::GFx::AS3::Value *v5; // r14
  Scaleform::GFx::AS3::VM *v6; // rsi
  unsigned int v7; // ebx
  unsigned int v8; // er9
  unsigned int v9; // ecx
  Scaleform::GFx::AS3::Value *v10; // rax
  signed int v11; // eax
  Scaleform::GFx::AS3::Value result; // [rsp+30h] [rbp-21h]
  Scaleform::GFx::AS3::Value ptr; // [rsp+58h] [rbp+7h]
  unsigned int v15; // [rsp+78h] [rbp+27h]
  Scaleform::GFx::AS3::Value::Extra v16; // [rsp+80h] [rbp+2Fh]
  Scaleform::GFx::AS3::Value::VU v17; // [rsp+88h] [rbp+37h]
  Scaleform::GFx::AS3::CheckResult v18[8]; // [rsp+B8h] [rbp+67h]
  void *retaddr; // [rsp+C8h] [rbp+77h]

  v4 = b;
  v5 = Funct;
  v6 = vm;
  v7 = 0;
  result.Flags = 0;
  result.Bonus.pWeakProxy = 0i64;
  v8 = a->Flags;
  ptr.Flags = v8;
  ptr.Bonus.pWeakProxy = a->Bonus.pWeakProxy;
  ptr.value = a->value;
  if ( (char)(v8 & 0x1F) > 9 )
  {
    if ( (v8 >> 9) & 1 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(a);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(a);
  }
  v9 = v4->Flags;
  v15 = v9;
  v16.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v4->Bonus;
  v17 = v4->value;
  if ( (char)(v9 & 0x1F) > 9 )
  {
    if ( (v9 >> 9) & 1 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(v4);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(v4);
  }
  v10 = Scaleform::GFx::AS3::Value::GetUndefined();
  Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(v6, v5, v10, &result, 2u, &ptr, 0);
  if ( !v6->HandleException && Scaleform::GFx::AS3::Value::Convert2Number(&result, v18, (long double *)&retaddr)->Result )
  {
    *(_QWORD *)&v18[0].Result = retaddr;
    if ( *(double *)&retaddr == -1.797693134862316e308/*-Inf*/ )
    {
      v7 = -1;
    }
    else
    {
      *(_QWORD *)&v18[0].Result = retaddr;
      if ( *(double *)&retaddr == 1.797693134862316e308/*+Inf*/ )
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
  `eh vector destructor iterator'(&ptr, 0x20ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
  if ( (result.Flags & 0x1F) > 9 )
  {
    if ( (result.Flags >> 9) & 1 )
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
  this->vfptr = (Scaleform::GFx::AS3::ArrayBaseVtbl *)&Scaleform::GFx::AS3::ArrayBase::`vftable';
}

// File Line: 94
// RVA: 0x8AA0B0
void __fastcall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::Value2NumberCollector::operator()(Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::Value2NumberCollector *this, unsigned int ind, Scaleform::GFx::AS3::Value *v)
{
  unsigned int v3; // ebx
  Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::Value2NumberCollector *v4; // rdi
  Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *v5; // rdi
  long double v6; // xmm6_8
  unsigned __int64 v7; // rbx
  unsigned __int64 v8; // r8
  Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long> *v9; // rcx
  long double *v10; // rcx
  __int64 v11; // xmm0_8
  long double v12; // [rsp+20h] [rbp-38h]
  __int64 v13; // [rsp+30h] [rbp-28h]
  Scaleform::GFx::AS3::CheckResult result; // [rsp+78h] [rbp+20h]

  v3 = ind;
  v4 = this;
  if ( Scaleform::GFx::AS3::Value::Convert2Number(v, &result, &v12)->Result )
  {
    v5 = (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)v4->Pairs;
    LODWORD(v13) = v3;
    v6 = v12;
    v7 = v5->Size + 1;
    if ( v7 >= v5->Size )
    {
      if ( v7 <= v5->Policy.Capacity )
        goto LABEL_8;
      v8 = v7 + (v7 >> 2);
    }
    else
    {
      if ( v7 >= v5->Policy.Capacity >> 1 )
        goto LABEL_8;
      v8 = v5->Size + 1;
    }
    Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v5,
      v5[1].Data,
      v8);
LABEL_8:
    v9 = v5->Data;
    v5->Size = v7;
    v10 = (long double *)&v9[v7 - 1];
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
void __fastcall Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Value2NumberCollector::operator()(Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> >::Value2NumberCollector *this, unsigned int ind, Scaleform::Ptr<Scaleform::GFx::ASStringNode> *v)
{
  unsigned int v3; // ebx
  Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> >::Value2NumberCollector *v4; // rdi
  long double v5; // xmm6_8
  Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *v6; // rdi
  unsigned __int64 v7; // rbx
  unsigned __int64 v8; // r8
  Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long> *v9; // rcx
  __int64 v10; // [rsp+30h] [rbp-48h]
  Scaleform::GFx::AS3::Value v11; // [rsp+38h] [rbp-40h]
  Scaleform::GFx::AS3::CheckResult result; // [rsp+90h] [rbp+18h]
  long double v13; // [rsp+98h] [rbp+20h]

  v3 = ind;
  v4 = this;
  Scaleform::GFx::AS3::Value::Value(&v11, v->pObject);
  if ( !Scaleform::GFx::AS3::Value::Convert2Number(&v11, &result, &v13)->Result )
    goto LABEL_10;
  v5 = v13;
  LODWORD(v10) = v3;
  v6 = (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)v4->Pairs;
  v7 = v6->Size + 1;
  if ( v7 >= v6->Size )
  {
    if ( v7 <= v6->Policy.Capacity )
      goto LABEL_8;
    v8 = v7 + (v7 >> 2);
  }
  else
  {
    if ( v7 >= v6->Policy.Capacity >> 1 )
      goto LABEL_8;
    v8 = v6->Size + 1;
  }
  Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    v6,
    v6[1].Data,
    v8);
LABEL_8:
  v6->Size = v7;
  v9 = &v6->Data[v7 - 1];
  if ( v9 )
  {
    *(long double *)&v9->First = v5;
    *(_QWORD *)&v9->Second = v10;
  }
LABEL_10:
  if ( (v11.Flags & 0x1F) > 9 )
  {
    if ( (v11.Flags >> 9) & 1 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v11);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v11);
  }
}

// File Line: 119
// RVA: 0x8A9F20
void __fastcall Scaleform::GFx::AS3::VectorBase<double>::Value2NumberCollector::operator()(Scaleform::GFx::AS3::VectorBase<double>::Value2NumberCollector *this, unsigned int ind, const long double *v)
{
  Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *v3; // rdi
  Scaleform::GFx::AS3::Value *v4; // xmm6_8
  unsigned __int64 v5; // rbx
  unsigned __int64 v6; // r8
  Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long> *v7; // rcx
  Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long> *v8; // rcx
  __int64 v9; // [rsp+28h] [rbp-20h]

  v3 = (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)this->Pairs;
  v4 = *(Scaleform::GFx::AS3::Value **)v;
  LODWORD(v9) = ind;
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
  Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    v3,
    v3[1].Data,
    v6);
LABEL_7:
  v7 = v3->Data;
  v3->Size = v5;
  v8 = &v7[v5 - 1];
  if ( v8 )
  {
    v8->First = v4;
    *(_QWORD *)&v8->Second = v9;
  }
}

// File Line: 128
// RVA: 0x8A9E90
void __fastcall Scaleform::GFx::AS3::VectorBase<unsigned long>::Value2NumberCollector::operator()(Scaleform::GFx::AS3::VectorBase<unsigned long>::Value2NumberCollector *this, unsigned int ind, const unsigned int *v)
{
  Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *v3; // rdi
  double v4; // xmm6_8
  unsigned __int64 v5; // rbx
  unsigned __int64 v6; // r8
  Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long> *v7; // rcx
  signed __int64 v8; // rcx
  __int64 v9; // [rsp+28h] [rbp-20h]

  v3 = (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)this->Pairs;
  LODWORD(v9) = ind;
  v4 = (double)*(signed int *)v;
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
  Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    v3,
    v3[1].Data,
    v6);
LABEL_7:
  v7 = v3->Data;
  v3->Size = v5;
  v8 = (signed __int64)&v7[v5 - 1];
  if ( v8 )
  {
    *(double *)v8 = v4;
    *(_QWORD *)(v8 + 8) = v9;
  }
}

// File Line: 137
// RVA: 0x8A9E00
void __fastcall Scaleform::GFx::AS3::VectorBase<long>::Value2NumberCollector::operator()(Scaleform::GFx::AS3::VectorBase<long>::Value2NumberCollector *this, unsigned int ind, const int *v)
{
  Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *v3; // rdi
  double v4; // xmm6_8
  unsigned __int64 v5; // rbx
  unsigned __int64 v6; // r8
  Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long> *v7; // rcx
  signed __int64 v8; // rcx
  __int64 v9; // [rsp+28h] [rbp-20h]

  v3 = (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)this->Pairs;
  LODWORD(v9) = ind;
  v4 = (double)*v;
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
  Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    v3,
    v3[1].Data,
    v6);
LABEL_7:
  v7 = v3->Data;
  v3->Size = v5;
  v8 = (signed __int64)&v7[v5 - 1];
  if ( v8 )
  {
    *(double *)v8 = v4;
    *(_QWORD *)(v8 + 8) = v9;
  }
}

// File Line: 147
// RVA: 0x8AA550
void __fastcall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::Value2StrCollector::operator()(Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::Value2StrCollector *this, unsigned int ind, Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  unsigned int v4; // esi
  Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::Value2StrCollector *v5; // rbp
  Scaleform::GFx::ASStringNode *v6; // rdi
  Scaleform::ArrayDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2,Scaleform::ArrayDefaultPolicy> *v7; // rbx
  signed __int64 v8; // rcx
  signed __int64 v9; // rdx
  bool v10; // zf
  signed __int64 v11; // rdx
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::AS3::CheckResult v13; // [rsp+60h] [rbp+8h]
  Scaleform::GFx::ASString result; // [rsp+78h] [rbp+20h]

  v3 = v;
  v4 = ind;
  v5 = this;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)this->Vm->StringManagerRef->Builtins,
    &result);
  if ( Scaleform::GFx::AS3::Value::Convert2String(v3, &v13, &result)->Result )
  {
    v6 = result.pNode;
    ++result.pNode->RefCount;
    v7 = v5->Pairs;
    Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&v5->Pairs->Data.Data,
      v7->Data.pHeap,
      v7->Data.Size + 1);
    v8 = 16 * v7->Data.Size;
    v9 = (signed __int64)&v7->Data.Data[-1];
    v10 = v8 + v9 == 0;
    v11 = v8 + v9;
    *(_QWORD *)&v13.Result = v11;
    if ( !v10 )
    {
      *(_QWORD *)v11 = v6;
      ++v6->RefCount;
      *(_DWORD *)(v11 + 8) = v4;
    }
    v10 = v6->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  }
  v12 = result.pNode;
  v10 = result.pNode->RefCount == 1;
  --v12->RefCount;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
}

// File Line: 161
// RVA: 0x8AA4C0
void __fastcall Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Value2StrCollector::operator()(Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> >::Value2StrCollector *this, unsigned int ind, Scaleform::Ptr<Scaleform::GFx::ASStringNode> *v)
{
  unsigned int v3; // esi
  Scaleform::GFx::ASStringNode *v4; // rdi
  Scaleform::ArrayDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2,Scaleform::ArrayDefaultPolicy> *v5; // rbx
  signed __int64 v6; // rdx
  bool v7; // zf

  v3 = ind;
  v4 = v->pObject;
  ++v4->RefCount;
  ++v4->RefCount;
  v5 = this->Pairs;
  Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Pairs->Data.Data,
    v5->Data.pHeap,
    v5->Data.Size + 1);
  v6 = (signed __int64)&v5->Data.Data[v5->Data.Size - 1];
  if ( v6 )
  {
    *(_QWORD *)v6 = v4;
    ++v4->RefCount;
    *(_DWORD *)(v6 + 8) = v3;
  }
  v7 = v4->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  v7 = v4->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
}

// File Line: 170
// RVA: 0x8AA3A0
void __fastcall Scaleform::GFx::AS3::VectorBase<double>::Value2StrCollector::operator()(Scaleform::GFx::AS3::VectorBase<double>::Value2StrCollector *this, unsigned int ind, const long double *v)
{
  const long double *v3; // rbx
  unsigned int v4; // esi
  Scaleform::GFx::AS3::VectorBase<double>::Value2StrCollector *v5; // rbp
  long double v6; // xmm0_8
  bool v7; // bl
  Scaleform::GFx::ASStringNode *v8; // rdi
  Scaleform::ArrayDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2,Scaleform::ArrayDefaultPolicy> *v9; // rbx
  signed __int64 v10; // rcx
  signed __int64 v11; // rdx
  bool v12; // zf
  __int64 v13; // rdx
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::AS3::Value v15; // [rsp+28h] [rbp-40h]
  Scaleform::GFx::AS3::CheckResult v16; // [rsp+70h] [rbp+8h]
  Scaleform::GFx::ASString result; // [rsp+80h] [rbp+18h]
  __int64 v18; // [rsp+88h] [rbp+20h]

  v3 = v;
  v4 = ind;
  v5 = this;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)this->Vm->StringManagerRef->Builtins,
    &result);
  v6 = *(double *)v3;
  v15.Flags = 4;
  v15.Bonus.pWeakProxy = 0i64;
  v15.value.VNumber = v6;
  v7 = Scaleform::GFx::AS3::Value::Convert2String(&v15, &v16, &result)->Result == 0;
  if ( (v15.Flags & 0x1F) > 9 )
  {
    if ( (v15.Flags >> 9) & 1 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v15);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v15);
  }
  if ( !v7 )
  {
    v8 = result.pNode;
    *(Scaleform::GFx::ASString *)&v15.Flags = result;
    ++*(_DWORD *)(*(_QWORD *)&v15.Flags + 24i64);
    LODWORD(v15.Bonus.pWeakProxy) = v4;
    v9 = v5->Pairs;
    Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&v5->Pairs->Data.Data,
      v9->Data.pHeap,
      v9->Data.Size + 1);
    v10 = 16 * v9->Data.Size;
    v11 = (signed __int64)&v9->Data.Data[-1];
    v12 = v10 + v11 == 0;
    v13 = v10 + v11;
    *(_QWORD *)&v16.Result = v13;
    v18 = v13;
    if ( !v12 )
    {
      *(_QWORD *)v13 = v8;
      ++v8->RefCount;
      *(_DWORD *)(v13 + 8) = v4;
    }
    v12 = v8->RefCount-- == 1;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  }
  v14 = result.pNode;
  v12 = result.pNode->RefCount == 1;
  --v14->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
}

// File Line: 184
// RVA: 0x8AA280
void __fastcall Scaleform::GFx::AS3::VectorBase<unsigned long>::Value2StrCollector::operator()(Scaleform::GFx::AS3::VectorBase<unsigned long>::Value2StrCollector *this, unsigned int ind, const unsigned int *v)
{
  const unsigned int *v3; // rbx
  unsigned int v4; // esi
  Scaleform::GFx::AS3::VectorBase<unsigned long>::Value2StrCollector *v5; // rbp
  int v6; // eax
  bool v7; // bl
  Scaleform::GFx::ASStringNode *v8; // rdi
  Scaleform::ArrayDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2,Scaleform::ArrayDefaultPolicy> *v9; // rbx
  signed __int64 v10; // rcx
  signed __int64 v11; // rdx
  bool v12; // zf
  __int64 v13; // rdx
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::AS3::Value v15; // [rsp+28h] [rbp-40h]
  Scaleform::GFx::AS3::CheckResult v16; // [rsp+70h] [rbp+8h]
  Scaleform::GFx::ASString result; // [rsp+80h] [rbp+18h]
  __int64 v18; // [rsp+88h] [rbp+20h]

  v3 = v;
  v4 = ind;
  v5 = this;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)this->Vm->StringManagerRef->Builtins,
    &result);
  v6 = *v3;
  v15.Flags = 3;
  v15.Bonus.pWeakProxy = 0i64;
  v15.value.VS._1.VInt = v6;
  v7 = Scaleform::GFx::AS3::Value::Convert2String(&v15, &v16, &result)->Result == 0;
  if ( (v15.Flags & 0x1F) > 9 )
  {
    if ( (v15.Flags >> 9) & 1 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v15);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v15);
  }
  if ( !v7 )
  {
    v8 = result.pNode;
    *(Scaleform::GFx::ASString *)&v15.Flags = result;
    ++*(_DWORD *)(*(_QWORD *)&v15.Flags + 24i64);
    LODWORD(v15.Bonus.pWeakProxy) = v4;
    v9 = v5->Pairs;
    Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&v5->Pairs->Data.Data,
      v9->Data.pHeap,
      v9->Data.Size + 1);
    v10 = 16 * v9->Data.Size;
    v11 = (signed __int64)&v9->Data.Data[-1];
    v12 = v10 + v11 == 0;
    v13 = v10 + v11;
    *(_QWORD *)&v16.Result = v13;
    v18 = v13;
    if ( !v12 )
    {
      *(_QWORD *)v13 = v8;
      ++v8->RefCount;
      *(_DWORD *)(v13 + 8) = v4;
    }
    v12 = v8->RefCount-- == 1;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  }
  v14 = result.pNode;
  v12 = result.pNode->RefCount == 1;
  --v14->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
}

// File Line: 198
// RVA: 0x8AA160
void __fastcall Scaleform::GFx::AS3::VectorBase<long>::Value2StrCollector::operator()(Scaleform::GFx::AS3::VectorBase<long>::Value2StrCollector *this, unsigned int ind, const int *v)
{
  const int *v3; // rbx
  unsigned int v4; // esi
  Scaleform::GFx::AS3::VectorBase<long>::Value2StrCollector *v5; // rbp
  int v6; // eax
  bool v7; // bl
  Scaleform::GFx::ASStringNode *v8; // rdi
  Scaleform::ArrayDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2,Scaleform::ArrayDefaultPolicy> *v9; // rbx
  signed __int64 v10; // rcx
  signed __int64 v11; // rdx
  bool v12; // zf
  __int64 v13; // rdx
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::AS3::Value v15; // [rsp+28h] [rbp-40h]
  Scaleform::GFx::AS3::CheckResult v16; // [rsp+70h] [rbp+8h]
  Scaleform::GFx::ASString result; // [rsp+80h] [rbp+18h]
  __int64 v18; // [rsp+88h] [rbp+20h]

  v3 = v;
  v4 = ind;
  v5 = this;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)this->Vm->StringManagerRef->Builtins,
    &result);
  v6 = *v3;
  v15.Flags = 2;
  v15.Bonus.pWeakProxy = 0i64;
  v15.value.VS._1.VInt = v6;
  v7 = Scaleform::GFx::AS3::Value::Convert2String(&v15, &v16, &result)->Result == 0;
  if ( (v15.Flags & 0x1F) > 9 )
  {
    if ( (v15.Flags >> 9) & 1 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v15);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v15);
  }
  if ( !v7 )
  {
    v8 = result.pNode;
    *(Scaleform::GFx::ASString *)&v15.Flags = result;
    ++*(_DWORD *)(*(_QWORD *)&v15.Flags + 24i64);
    LODWORD(v15.Bonus.pWeakProxy) = v4;
    v9 = v5->Pairs;
    Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&v5->Pairs->Data.Data,
      v9->Data.pHeap,
      v9->Data.Size + 1);
    v10 = 16 * v9->Data.Size;
    v11 = (signed __int64)&v9->Data.Data[-1];
    v12 = v10 + v11 == 0;
    v13 = v10 + v11;
    *(_QWORD *)&v16.Result = v13;
    v18 = v13;
    if ( !v12 )
    {
      *(_QWORD *)v13 = v8;
      ++v8->RefCount;
      *(_DWORD *)(v13 + 8) = v4;
    }
    v12 = v8->RefCount-- == 1;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  }
  v14 = result.pNode;
  v12 = result.pNode->RefCount == 1;
  --v14->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
}

// File Line: 212
// RVA: 0x8EC160
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::ArrayBase::OfCorrectType(Scaleform::GFx::AS3::ArrayBase *this, Scaleform::GFx::AS3::CheckResult *result, unsigned int argc, Scaleform::GFx::AS3::Value *const argv, Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  int v5; // ebx
  Scaleform::GFx::AS3::Value *v6; // r14
  unsigned int v7; // esi
  Scaleform::GFx::AS3::CheckResult *v8; // rdi
  Scaleform::GFx::AS3::ArrayBase *v9; // r15
  Scaleform::GFx::AS3::ClassTraits::Traits *v10; // rbp
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+50h] [rbp+18h]

  v5 = 0;
  v6 = argv;
  v7 = argc;
  v8 = result;
  v9 = this;
  if ( argc )
  {
    v10 = tr;
    while ( Scaleform::GFx::AS3::ArrayBase::OfCorrectType(v9, &resulta, &v6[v5], v10)->Result )
    {
      if ( ++v5 >= v7 )
        goto LABEL_5;
    }
    v8->Result = 0;
  }
  else
  {
LABEL_5:
    v8->Result = 1;
  }
  return v8;
}

// File Line: 238
// RVA: 0x8BAE70
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::ArrayBase::CheckFixed(Scaleform::GFx::AS3::ArrayBase *this, Scaleform::GFx::AS3::CheckResult *result)
{
  Scaleform::GFx::AS3::CheckResult *v2; // rdi
  Scaleform::GFx::AS3::ArrayBase *v3; // rbx
  Scaleform::GFx::AS3::VM::Error *v4; // rax
  Scaleform::GFx::ASStringNode *v5; // rcx
  bool v6; // zf
  Scaleform::GFx::AS3::VM::Error v8; // [rsp+28h] [rbp-20h]

  v2 = result;
  v3 = this;
  if ( this->Fixed )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v8, eVectorFixedError, this->VMRef);
    Scaleform::GFx::AS3::VM::ThrowRangeError(v3->VMRef, v4);
    v5 = v8.Message.pNode;
    v6 = v8.Message.pNode->RefCount == 1;
    --v5->RefCount;
    if ( v6 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  }
  v2->Result = v3->Fixed == 0;
  return v2;
}

// File Line: 246
// RVA: 0x8BA8F0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::ArrayBase::CheckCorrectType(Scaleform::GFx::AS3::ArrayBase *this, Scaleform::GFx::AS3::CheckResult *result, unsigned int argc, Scaleform::GFx::AS3::Value *const argv, Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  Scaleform::GFx::AS3::CheckResult *v5; // rdi
  Scaleform::GFx::AS3::ArrayBase *v6; // rbx
  Scaleform::GFx::AS3::VM *v7; // rbx
  Scaleform::GFx::AS3::VM::Error *v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::AS3::VM::Error v12; // [rsp+38h] [rbp-20h]
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+68h] [rbp+10h]

  v5 = result;
  v6 = this;
  if ( Scaleform::GFx::AS3::ArrayBase::OfCorrectType(this, &resulta, argc, argv, tr)->Result )
  {
    v5->Result = 1;
  }
  else
  {
    v7 = v6->VMRef;
    Scaleform::GFx::AS3::VM::Error::Error(&v12, eCheckTypeFailedError, v7);
    Scaleform::GFx::AS3::VM::ThrowTypeError(v7, v8);
    v9 = v12.Message.pNode;
    v10 = v12.Message.pNode->RefCount == 1;
    --v9->RefCount;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
    v5->Result = 0;
  }
  return v5;
}

// File Line: 284
// RVA: 0x8BA7F0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::ArrayBase::CheckCallable(Scaleform::GFx::AS3::ArrayBase *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::Value *callback)
{
  Scaleform::GFx::AS3::CheckResult *v3; // rdi
  signed int v4; // eax
  Scaleform::GFx::AS3::VM *v5; // rbx
  Scaleform::GFx::AS3::VM::Error *v6; // rax
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::GFx::AS3::VM::Error v10; // [rsp+28h] [rbp-20h]

  v3 = result;
  v4 = callback->Flags & 0x1F;
  if ( v4 <= 4 || (unsigned int)(v4 - 8) <= 3 )
  {
    v5 = this->VMRef;
    Scaleform::GFx::AS3::VM::Error::Error(&v10, eCheckTypeFailedError, this->VMRef);
    Scaleform::GFx::AS3::VM::ThrowTypeError(v5, v6);
    v7 = v10.Message.pNode;
    v8 = v10.Message.pNode->RefCount == 1;
    --v7->RefCount;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
    v3->Result = 0;
  }
  else
  {
    result->Result = 1;
  }
  return v3;
}

// File Line: 303
// RVA: 0x8BA870
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::ArrayBase::CheckCoerce(Scaleform::GFx::AS3::ArrayBase *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::ClassTraits::Traits *tr, Scaleform::GFx::AS3::Value *v, Scaleform::GFx::AS3::Value *coerced)
{
  Scaleform::GFx::AS3::CheckResult *v5; // rdi
  Scaleform::GFx::AS3::ArrayBase *v6; // rbx
  Scaleform::GFx::AS3::VM *v7; // rbx
  Scaleform::GFx::AS3::VM::Error *v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::AS3::VM::Error v12; // [rsp+28h] [rbp-20h]

  v5 = result;
  v6 = this;
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::ClassTraits::Traits *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))tr->vfptr[3].Finalize_GC)(
         tr,
         v,
         coerced) )
  {
    v5->Result = 1;
  }
  else
  {
    v7 = v6->VMRef;
    Scaleform::GFx::AS3::VM::Error::Error(&v12, eCheckTypeFailedError, v7);
    Scaleform::GFx::AS3::VM::ThrowTypeError(v7, v8);
    v9 = v12.Message.pNode;
    v10 = v12.Message.pNode->RefCount == 1;
    --v9->RefCount;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
    v5->Result = 0;
  }
  return v5;
}

// File Line: 322
// RVA: 0x912E00
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::ArrayBase::ToString(Scaleform::GFx::AS3::ArrayBase *this, Scaleform::GFx::ASString *result, Scaleform::GFx::ASString *sep)
{
  const char ***v3; // r14
  Scaleform::GFx::ASString *v4; // rbp
  Scaleform::GFx::AS3::ArrayBase *v5; // rsi
  unsigned int v6; // edi
  unsigned int v7; // ebx
  char *v8; // r8
  Scaleform::GFx::AS3::Value v10; // [rsp+30h] [rbp-78h]
  Scaleform::StringBuffer v11; // [rsp+50h] [rbp-58h]
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+B0h] [rbp+8h]
  Scaleform::GFx::ASString *v13; // [rsp+B8h] [rbp+10h]

  v13 = result;
  v3 = (const char ***)sep;
  v4 = result;
  v5 = this;
  Scaleform::StringBuffer::StringBuffer(&v11, this->VMRef->MHeap);
  v6 = v5->vfptr->GetArraySize(v5);
  v7 = 0;
  if ( v6 )
  {
    while ( 1 )
    {
      if ( v7 )
        Scaleform::StringBuffer::AppendString(&v11, **v3, -1i64);
      v10.Flags = 0;
      v10.Bonus.pWeakProxy = 0i64;
      v5->vfptr->GetValueUnsafe(v5, v7, &v10);
      if ( !Scaleform::GFx::AS3::Value::Convert2String(&v10, &resulta, &v11)->Result )
        break;
      if ( (v10.Flags & 0x1F) > 9 )
      {
        if ( (v10.Flags >> 9) & 1 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v10);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
      }
      if ( ++v7 >= v6 )
        goto LABEL_15;
    }
    if ( (v10.Flags & 0x1F) > 9 )
    {
      if ( (v10.Flags >> 9) & 1 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v10);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
    }
  }
LABEL_15:
  v8 = &customWorldMapCaption;
  if ( v11.pData )
    v8 = v11.pData;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v5->VMRef->StringManagerRef->Builtins,
    v4,
    v8,
    v11.Size);
  Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&v11);
  return v4;
}

// File Line: 380
// RVA: 0x8B6610
void __fastcall Scaleform::GFx::AS3::ArrayBase::AppendCoerce(Scaleform::GFx::AS3::ArrayBase *this, Scaleform::GFx::AS3::Instances::fl::Array *arr, Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  Scaleform::GFx::AS3::ClassTraits::Traits *v3; // rbp
  Scaleform::GFx::AS3::Instances::fl::Array *v4; // rbx
  Scaleform::GFx::AS3::ArrayBase *v5; // rdi
  Scaleform::GFx::AS3::Impl::SparseArray *v6; // r14
  unsigned __int64 v7; // rsi
  unsigned __int64 v8; // rbx
  Scaleform::GFx::AS3::Value *v9; // rax
  Scaleform::GFx::AS3::Value coerced; // [rsp+38h] [rbp-40h]
  Scaleform::GFx::AS3::CheckResult result; // [rsp+98h] [rbp+20h]

  v3 = tr;
  v4 = arr;
  v5 = this;
  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &result)->Result )
  {
    v6 = &v4->SA;
    v7 = v4->SA.Length;
    v8 = 0i64;
    if ( v7 )
    {
      while ( 1 )
      {
        coerced.Flags = 0;
        coerced.Bonus.pWeakProxy = 0i64;
        v9 = Scaleform::GFx::AS3::Impl::SparseArray::At(v6, v8);
        if ( !Scaleform::GFx::AS3::ArrayBase::CheckCoerce(v5, &result, v3, v9, &coerced)->Result )
          break;
        v5->vfptr->PushBackValueUnsafe(v5, &coerced);
        if ( (coerced.Flags & 0x1F) > 9 )
        {
          if ( (coerced.Flags >> 9) & 1 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&coerced);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&coerced);
        }
        if ( ++v8 >= v7 )
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
  }
}

// File Line: 397
// RVA: 0x8B64A0
void __fastcall Scaleform::GFx::AS3::ArrayBase::AppendCoerce(Scaleform::GFx::AS3::ArrayBase *this, Scaleform::GFx::AS3::ArrayBase *arr, Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  Scaleform::GFx::AS3::ClassTraits::Traits *v3; // r15
  Scaleform::GFx::AS3::ArrayBase *v4; // r14
  Scaleform::GFx::AS3::ArrayBase *v5; // rdi
  unsigned int v6; // esi
  unsigned int v7; // ebx
  Scaleform::GFx::AS3::Value v; // [rsp+38h] [rbp-48h]
  Scaleform::GFx::AS3::Value coerced; // [rsp+58h] [rbp-28h]
  Scaleform::GFx::AS3::CheckResult result; // [rsp+C8h] [rbp+48h]

  v3 = tr;
  v4 = arr;
  v5 = this;
  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &result)->Result )
  {
    v6 = v4->vfptr->GetArraySize(v4);
    v7 = 0;
    if ( v6 )
    {
      while ( 1 )
      {
        coerced.Flags = 0;
        coerced.Bonus.pWeakProxy = 0i64;
        v.Flags = 0;
        v.Bonus.pWeakProxy = 0i64;
        v4->vfptr->GetValueUnsafe(v4, v7, &v);
        if ( !Scaleform::GFx::AS3::ArrayBase::CheckCoerce(v5, &result, v3, &v, &coerced)->Result )
          break;
        v5->vfptr->PushBackValueUnsafe(v5, &coerced);
        if ( (v.Flags & 0x1F) > 9 )
        {
          if ( (v.Flags >> 9) & 1 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
        }
        if ( (coerced.Flags & 0x1F) > 9 )
        {
          if ( (coerced.Flags >> 9) & 1 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&coerced);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&coerced);
        }
        if ( ++v7 >= v6 )
          return;
      }
      if ( (v.Flags & 0x1F) > 9 )
      {
        if ( (v.Flags >> 9) & 1 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
      }
      if ( (coerced.Flags & 0x1F) > 9 )
      {
        if ( (coerced.Flags >> 9) & 1 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&coerced);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&coerced);
      }
    }
  }
}

// File Line: 416
// RVA: 0x8B6730
bool __fastcall Scaleform::GFx::AS3::ArrayBase::AppendCoerce(Scaleform::GFx::AS3::ArrayBase *this, Scaleform::GFx::AS3::Value *value, Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  Scaleform::GFx::AS3::VM *v3; // rbp
  Scaleform::GFx::AS3::ArrayBase *v4; // rbx
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rsi
  Scaleform::GFx::AS3::Value *v6; // rdi
  Scaleform::GFx::AS3::Traits *v7; // rax
  bool result; // al

  v3 = this->VMRef;
  v4 = this;
  v5 = tr;
  v6 = value;
  v7 = Scaleform::GFx::AS3::VM::GetValueTraits(this->VMRef, value);
  if ( !(~(LOBYTE(v7->Flags) >> 5) & 1) )
    return 0;
  switch ( v7->TraitsType )
  {
    case 7:
      Scaleform::GFx::AS3::ArrayBase::AppendCoerce(
        v4,
        (Scaleform::GFx::AS3::Instances::fl::Array *)v6->value.VS._1.VStr,
        v5);
      result = v4->VMRef->HandleException == 0;
      break;
    case 0xC:
    case 0xD:
    case 0xE:
    case 0xF:
    case 0x10:
      Scaleform::GFx::AS3::ArrayBase::AppendCoerce(
        v4,
        (Scaleform::GFx::AS3::ArrayBase *)(*(_QWORD *)&v6->value.VNumber + 56i64),
        v5);
      result = v3->HandleException == 0;
      break;
    default:
      return 0;
  }
  return result;
}

// File Line: 465
// RVA: 0x8C9020
bool __fastcall Scaleform::GFx::AS3::ArrayBase::Every(Scaleform::GFx::AS3::ArrayBase *this, Scaleform::GFx::AS3::Value *callback, Scaleform::GFx::AS3::Value *thisObject, Scaleform::GFx::AS3::Object *currObj)
{
  Scaleform::GFx::AS3::Object *v4; // r15
  Scaleform::GFx::AS3::Value *v5; // rdi
  Scaleform::GFx::AS3::Value *v6; // r14
  Scaleform::GFx::AS3::ArrayBase *v7; // rsi
  unsigned int v8; // er10
  unsigned int v9; // ebx
  int v10; // ecx
  bool v11; // al
  Scaleform::GFx::AS3::Value *v12; // rcx
  unsigned int v13; // edx
  unsigned int v14; // edi
  Scaleform::GFx::AS3::Value *v15; // rax
  bool v16; // bl
  Scaleform::GFx::AS3::Value v18; // [rsp+18h] [rbp-79h]
  Scaleform::GFx::AS3::Value _this; // [rsp+38h] [rbp-59h]
  __int64 v20; // [rsp+58h] [rbp-39h]
  Scaleform::GFx::AS3::Value argv; // [rsp+68h] [rbp-29h]
  int v22; // [rsp+88h] [rbp-9h]
  __int64 v23; // [rsp+90h] [rbp-1h]
  unsigned int v24; // [rsp+98h] [rbp+7h]
  Scaleform::GFx::AS3::Value v25; // [rsp+A8h] [rbp+17h]
  Scaleform::GFx::AS3::CheckResult result; // [rsp+100h] [rbp+6Fh]

  v20 = -2i64;
  v4 = currObj;
  v5 = thisObject;
  v6 = callback;
  v7 = this;
  v8 = callback->Flags & 0x1F;
  if ( !v8
    || (v8 - 12 <= 3 || v8 == 10) && !*(_QWORD *)&callback->value.VNumber
    || !Scaleform::GFx::AS3::ArrayBase::CheckCallable(this, &result, callback)->Result )
  {
    return 0;
  }
  v9 = 0;
  v10 = v5->Flags & 0x1F;
  v11 = !v10 || ((unsigned int)(v10 - 12) <= 3 || v10 == 10) && !*(_QWORD *)&v5->value.VNumber;
  v12 = v6;
  if ( !v11 )
    v12 = v5;
  v13 = v12->Flags;
  _this.Flags = v13;
  _this.Bonus.pWeakProxy = v12->Bonus.pWeakProxy;
  _this.value = v12->value;
  if ( (char)(v13 & 0x1F) > 9 )
  {
    if ( (v13 >> 9) & 1 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(v12);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(v12);
  }
  v14 = v7->vfptr->GetArraySize(v7);
  if ( v14 )
  {
    while ( 1 )
    {
      v15 = Scaleform::GFx::AS3::Value::GetUndefined();
      argv.Flags = v15->Flags;
      argv.Bonus.pWeakProxy = v15->Bonus.pWeakProxy;
      argv.value = v15->value;
      if ( (v15->Flags & 0x1F) > 9 )
      {
        if ( (v15->Flags >> 9) & 1 )
          Scaleform::GFx::AS3::Value::AddRefWeakRef(v15);
        else
          Scaleform::GFx::AS3::Value::AddRefInternal(v15);
      }
      v22 = 3;
      v23 = 0i64;
      v24 = v9;
      Scaleform::GFx::AS3::Value::Value(&v25, v4);
      v18.Flags = 0;
      v18.Bonus.pWeakProxy = 0i64;
      v7->vfptr->GetValueUnsafe(v7, v9, &argv);
      Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(v7->VMRef, v6, &_this, &v18, 3u, &argv, 0);
      if ( v7->VMRef->HandleException || (v18.Flags & 0x1F) != 1 || !v18.value.VS._1.VBool )
        break;
      if ( (v18.Flags & 0x1F) > 9 )
      {
        if ( (v18.Flags >> 9) & 1 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v18);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v18);
      }
      `eh vector destructor iterator'(
        &argv,
        0x20ui64,
        3,
        (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
      if ( ++v9 >= v14 )
        goto LABEL_37;
    }
    if ( (v18.Flags & 0x1F) > 9 )
    {
      if ( (v18.Flags >> 9) & 1 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v18);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v18);
    }
    `eh vector destructor iterator'(&argv, 0x20ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
  }
LABEL_37:
  v16 = v9 == v14;
  if ( (_this.Flags & 0x1F) > 9 )
  {
    if ( (_this.Flags >> 9) & 1 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&_this);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
  }
  return v16;
}

// File Line: 499
// RVA: 0x8CD7B0
void __fastcall Scaleform::GFx::AS3::ArrayBase::ForEach(Scaleform::GFx::AS3::ArrayBase *this, Scaleform::GFx::AS3::Value *callback, Scaleform::GFx::AS3::Value *thisObject, Scaleform::GFx::AS3::Object *currObj)
{
  Scaleform::GFx::AS3::Object *v4; // r15
  Scaleform::GFx::AS3::Value *v5; // rbx
  Scaleform::GFx::AS3::Value *v6; // rsi
  Scaleform::GFx::AS3::ArrayBase *v7; // rdi
  unsigned int v8; // er10
  int v9; // ecx
  bool v10; // al
  Scaleform::GFx::AS3::Value *v11; // rcx
  unsigned int v12; // edx
  unsigned int v13; // er14
  unsigned int v14; // ebx
  Scaleform::GFx::AS3::Value *v15; // rax
  Scaleform::GFx::AS3::Value v16; // [rsp+18h] [rbp-79h]
  Scaleform::GFx::AS3::Value _this; // [rsp+38h] [rbp-59h]
  __int64 v18; // [rsp+58h] [rbp-39h]
  Scaleform::GFx::AS3::Value argv; // [rsp+68h] [rbp-29h]
  int v20; // [rsp+88h] [rbp-9h]
  __int64 v21; // [rsp+90h] [rbp-1h]
  unsigned int v22; // [rsp+98h] [rbp+7h]
  Scaleform::GFx::AS3::Value v23; // [rsp+A8h] [rbp+17h]
  Scaleform::GFx::AS3::CheckResult result; // [rsp+100h] [rbp+6Fh]

  v18 = -2i64;
  v4 = currObj;
  v5 = thisObject;
  v6 = callback;
  v7 = this;
  v8 = callback->Flags & 0x1F;
  if ( v8
    && (v8 - 12 > 3 && v8 != 10 || *(_QWORD *)&callback->value.VNumber)
    && Scaleform::GFx::AS3::ArrayBase::CheckCallable(this, &result, callback)->Result )
  {
    v9 = v5->Flags & 0x1F;
    v10 = !v9 || ((unsigned int)(v9 - 12) <= 3 || v9 == 10) && !*(_QWORD *)&v5->value.VNumber;
    v11 = v6;
    if ( !v10 )
      v11 = v5;
    v12 = v11->Flags;
    _this.Flags = v12;
    _this.Bonus.pWeakProxy = v11->Bonus.pWeakProxy;
    _this.value = v11->value;
    if ( (char)(v12 & 0x1F) > 9 )
    {
      if ( (v12 >> 9) & 1 )
        Scaleform::GFx::AS3::Value::AddRefWeakRef(v11);
      else
        Scaleform::GFx::AS3::Value::AddRefInternal(v11);
    }
    v13 = v7->vfptr->GetArraySize(v7);
    v14 = 0;
    if ( v13 )
    {
      while ( 1 )
      {
        v15 = Scaleform::GFx::AS3::Value::GetUndefined();
        argv.Flags = v15->Flags;
        argv.Bonus.pWeakProxy = v15->Bonus.pWeakProxy;
        argv.value = v15->value;
        if ( (v15->Flags & 0x1F) > 9 )
        {
          if ( (v15->Flags >> 9) & 1 )
            Scaleform::GFx::AS3::Value::AddRefWeakRef(v15);
          else
            Scaleform::GFx::AS3::Value::AddRefInternal(v15);
        }
        v20 = 3;
        v21 = 0i64;
        v22 = v14;
        Scaleform::GFx::AS3::Value::Value(&v23, v4);
        v16.Flags = 0;
        v16.Bonus.pWeakProxy = 0i64;
        v7->vfptr->GetValueUnsafe(v7, v14, &argv);
        Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(v7->VMRef, v6, &_this, &v16, 3u, &argv, 0);
        if ( v7->VMRef->HandleException )
          break;
        if ( (v16.Flags & 0x1F) > 9 )
        {
          if ( (v16.Flags >> 9) & 1 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v16);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v16);
        }
        `eh vector destructor iterator'(
          &argv,
          0x20ui64,
          3,
          (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
        if ( ++v14 >= v13 )
          goto LABEL_35;
      }
      if ( (v16.Flags & 0x1F) > 9 )
      {
        if ( (v16.Flags >> 9) & 1 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v16);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v16);
      }
      `eh vector destructor iterator'(
        &argv,
        0x20ui64,
        3,
        (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
    }
LABEL_35:
    if ( (_this.Flags & 0x1F) > 9 )
    {
      if ( (_this.Flags >> 9) & 1 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&_this);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
    }
  }
}

// File Line: 523
// RVA: 0x910D10
char __fastcall Scaleform::GFx::AS3::ArrayBase::Some(Scaleform::GFx::AS3::ArrayBase *this, Scaleform::GFx::AS3::Value *callback, Scaleform::GFx::AS3::Value *thisObject, Scaleform::GFx::AS3::Object *currObj)
{
  Scaleform::GFx::AS3::Object *v4; // r15
  Scaleform::GFx::AS3::Value *v5; // rbx
  Scaleform::GFx::AS3::Value *v6; // rsi
  Scaleform::GFx::AS3::ArrayBase *v7; // rdi
  unsigned int v8; // er10
  int v9; // ecx
  bool v10; // al
  Scaleform::GFx::AS3::Value *v11; // rcx
  unsigned int v12; // edx
  unsigned int v13; // er14
  unsigned int v14; // ebx
  Scaleform::GFx::AS3::Value *v15; // rax
  char v16; // bl
  Scaleform::GFx::AS3::Value v18; // [rsp+18h] [rbp-79h]
  Scaleform::GFx::AS3::Value _this; // [rsp+38h] [rbp-59h]
  __int64 v20; // [rsp+58h] [rbp-39h]
  Scaleform::GFx::AS3::Value argv; // [rsp+68h] [rbp-29h]
  int v22; // [rsp+88h] [rbp-9h]
  __int64 v23; // [rsp+90h] [rbp-1h]
  unsigned int v24; // [rsp+98h] [rbp+7h]
  Scaleform::GFx::AS3::Value v25; // [rsp+A8h] [rbp+17h]
  Scaleform::GFx::AS3::CheckResult result; // [rsp+100h] [rbp+6Fh]

  v20 = -2i64;
  v4 = currObj;
  v5 = thisObject;
  v6 = callback;
  v7 = this;
  v8 = callback->Flags & 0x1F;
  if ( !v8
    || (v8 - 12 <= 3 || v8 == 10) && !*(_QWORD *)&callback->value.VNumber
    || !Scaleform::GFx::AS3::ArrayBase::CheckCallable(this, &result, callback)->Result )
  {
    return 0;
  }
  v9 = v5->Flags & 0x1F;
  v10 = !v9 || ((unsigned int)(v9 - 12) <= 3 || v9 == 10) && !*(_QWORD *)&v5->value.VNumber;
  v11 = v6;
  if ( !v10 )
    v11 = v5;
  v12 = v11->Flags;
  _this.Flags = v12;
  _this.Bonus.pWeakProxy = v11->Bonus.pWeakProxy;
  _this.value = v11->value;
  if ( (char)(v12 & 0x1F) > 9 )
  {
    if ( (v12 >> 9) & 1 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(v11);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(v11);
  }
  v13 = v7->vfptr->GetArraySize(v7);
  v14 = 0;
  if ( v13 )
  {
    while ( 1 )
    {
      v15 = Scaleform::GFx::AS3::Value::GetUndefined();
      argv.Flags = v15->Flags;
      argv.Bonus.pWeakProxy = v15->Bonus.pWeakProxy;
      argv.value = v15->value;
      if ( (v15->Flags & 0x1F) > 9 )
      {
        if ( (v15->Flags >> 9) & 1 )
          Scaleform::GFx::AS3::Value::AddRefWeakRef(v15);
        else
          Scaleform::GFx::AS3::Value::AddRefInternal(v15);
      }
      v22 = 3;
      v23 = 0i64;
      v24 = v14;
      Scaleform::GFx::AS3::Value::Value(&v25, v4);
      v18.Flags = 0;
      v18.Bonus.pWeakProxy = 0i64;
      v7->vfptr->GetValueUnsafe(v7, v14, &argv);
      Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(v7->VMRef, v6, &_this, &v18, 3u, &argv, 0);
      if ( v7->VMRef->HandleException )
        break;
      if ( (v18.Flags & 0x1F) != 1 )
      {
        v16 = 0;
        goto LABEL_34;
      }
      if ( v18.value.VS._1.VBool == 1 )
      {
        v16 = 1;
LABEL_34:
        if ( (v18.Flags & 0x1F) > 9 )
        {
          if ( (v18.Flags >> 9) & 1 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v18);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v18);
        }
        `eh vector destructor iterator'(
          &argv,
          0x20ui64,
          3,
          (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
        goto LABEL_45;
      }
      if ( (v18.Flags & 0x1F) > 9 )
      {
        if ( (v18.Flags >> 9) & 1 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v18);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v18);
      }
      `eh vector destructor iterator'(
        &argv,
        0x20ui64,
        3,
        (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
      if ( ++v14 >= v13 )
        goto LABEL_44;
    }
    if ( (v18.Flags & 0x1F) > 9 )
    {
      if ( (v18.Flags >> 9) & 1 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v18);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v18);
    }
    `eh vector destructor iterator'(&argv, 0x20ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
  }
LABEL_44:
  v16 = 0;
LABEL_45:
  if ( (_this.Flags & 0x1F) > 9 )
  {
    if ( (_this.Flags >> 9) & 1 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&_this);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
  }
  return v16;
}

