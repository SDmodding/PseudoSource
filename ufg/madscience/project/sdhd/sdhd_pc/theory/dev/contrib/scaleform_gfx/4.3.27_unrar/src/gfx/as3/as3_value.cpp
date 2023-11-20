// File Line: 64
// RVA: 0x784DC0
void __fastcall Scaleform::GFx::AS3::Value::Value(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::ASString *v)
{
  Scaleform::GFx::AS3::Value::V2U v2; // [rsp+8h] [rbp-10h]

  this->Flags = 10;
  this->Bonus.pWeakProxy = 0i64;
  *(Scaleform::GFx::ASString *)&this->value.VNumber = (Scaleform::GFx::ASString)v->pNode;
  if ( v->pNode == &v->pNode->pManager->NullStringNode )
  {
    this->Flags &= 0xFFFFFFEC;
    this->Flags |= 0xCu;
    this->value.VNumber = 0.0;
    this->value.VS._2 = v2;
  }
  else
  {
    ++*(_DWORD *)(*(_QWORD *)&this->value.VNumber + 24i64);
  }
}

// File Line: 78
// RVA: 0x784E20
void __fastcall Scaleform::GFx::AS3::Value::Value(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::ASStringNode *v)
{
  Scaleform::GFx::AS3::Value::V2U v2; // [rsp+8h] [rbp-10h]

  this->Flags = 10;
  this->Bonus.pWeakProxy = 0i64;
  *(_QWORD *)&this->value.VNumber = v;
  if ( !v )
    goto LABEL_4;
  if ( v == &v->pManager->NullStringNode )
  {
    this->value.VNumber = 0.0;
    this->value.VS._2 = v2;
LABEL_4:
    this->Flags &= 0xFFFFFFEC;
    this->Flags |= 0xCu;
    return;
  }
  ++v->RefCount;
}

// File Line: 224
// RVA: 0x7B1530
void __fastcall Scaleform::GFx::AS3::Value::Assign(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::AS3::Value *other)
{
  Scaleform::GFx::AS3::Value *v2; // rbx
  unsigned int v3; // ecx
  Scaleform::GFx::AS3::WeakProxy *v5; // rdx
  bool v6; // zf
  int v7; // eax
  long double v8; // rcx

  if ( other != this )
  {
    v2 = this;
    v3 = this->Flags;
    _RDI = other;
    if ( (char)(v3 & 0x1F) > 9 )
    {
      if ( (v3 >> 9) & 1 )
      {
        v5 = v2->Bonus.pWeakProxy;
        v6 = v5->RefCount-- == 1;
        if ( v6 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v2->Flags &= 0xFFFFFDE0;
        v2->Bonus.pWeakProxy = 0i64;
        v2->value.VNumber = 0.0;
        v2->value.VS._2.VObj = 0i64;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(v2);
      }
    }
    __asm { prefetcht1 byte ptr [rdi]; Prefetch to all cache levels }
    *(_QWORD *)&v2->Flags = *(_QWORD *)&_RDI->Flags;
    v2->Bonus.pWeakProxy = _RDI->Bonus.pWeakProxy;
    v2->value.VNumber = _RDI->value.VNumber;
    v2->value.VS._2.VObj = _RDI->value.VS._2.VObj;
    v7 = v2->Flags & 0x1F;
    if ( v7 > 9 )
    {
      if ( (v2->Flags >> 9) & 1 )
      {
        ++v2->Bonus.pWeakProxy->RefCount;
        return;
      }
      if ( v7 == 10 )
      {
        ++*(_DWORD *)(*(_QWORD *)&v2->value.VNumber + 24i64);
      }
      else
      {
        if ( v7 <= 10 )
          return;
        if ( v7 <= 15 )
        {
          v8 = v2->value.VNumber;
        }
        else
        {
          if ( v7 > 17 )
            return;
          v8 = *(double *)&v2->value.VS._2.VObj;
        }
        if ( v8 != 0.0 )
          *(_DWORD *)(*(_QWORD *)&v8 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v8 + 32i64) + 1) & 0x8FBFFFFF;
      }
    }
  }
}

// File Line: 235
// RVA: 0x7B1A40
void __fastcall Scaleform::GFx::AS3::Value::AssignUnsafe(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::AS3::Value *other)
{
  signed int v2; // eax
  long double v3; // rdx

  if ( other != this )
  {
    __asm { prefetcht1 byte ptr [rdx]; Prefetch to all cache levels }
    *(_QWORD *)&this->Flags = *(_QWORD *)&other->Flags;
    this->Bonus.pWeakProxy = other->Bonus.pWeakProxy;
    this->value = other->value;
    v2 = this->Flags & 0x1F;
    if ( v2 > 9 )
    {
      if ( (this->Flags >> 9) & 1 )
      {
        ++this->Bonus.pWeakProxy->RefCount;
        return;
      }
      if ( v2 == 10 )
      {
        ++*(_DWORD *)(*(_QWORD *)&this->value.VNumber + 24i64);
      }
      else
      {
        if ( v2 <= 10 )
          return;
        if ( v2 <= 15 )
        {
          v3 = this->value.VNumber;
        }
        else
        {
          if ( v2 > 17 )
            return;
          v3 = *(double *)&this->value.VS._2.VObj;
        }
        if ( v3 != 0.0 )
          *(_DWORD *)(*(_QWORD *)&v3 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v3 + 32i64) + 1) & 0x8FBFFFFF;
      }
    }
  }
}

// File Line: 247
// RVA: 0x7B1620
void __fastcall Scaleform::GFx::AS3::Value::Assign(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::ASString *v)
{
  Scaleform::GFx::AS3::Value *v2; // rbx
  unsigned int v3; // ecx
  Scaleform::GFx::ASString *v4; // rdi
  Scaleform::GFx::AS3::WeakProxy *v5; // rdx
  bool v6; // zf
  Scaleform::GFx::AS3::Value::V2U v7; // [rsp+28h] [rbp-10h]

  v2 = this;
  v3 = this->Flags;
  v4 = v;
  if ( (char)(v3 & 0x1F) > 9 )
  {
    if ( (v3 >> 9) & 1 )
    {
      v5 = v2->Bonus.pWeakProxy;
      v6 = v5->RefCount-- == 1;
      if ( v6 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v2->Flags &= 0xFFFFFDE0;
      v2->Bonus.pWeakProxy = 0i64;
      v2->value.VNumber = 0.0;
      v2->value.VS._2.VObj = 0i64;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(v2);
    }
  }
  if ( v4->pNode == &v4->pNode->pManager->NullStringNode )
  {
    v2->Flags &= 0xFFFFFFEC;
    v2->Flags |= 0xCu;
    v2->value.VNumber = 0.0;
    v2->value.VS._2 = v7;
  }
  else
  {
    v2->Flags &= 0xFFFFFFEA;
    v2->Flags |= 0xAu;
    *(Scaleform::GFx::ASString *)&v2->value.VNumber = (Scaleform::GFx::ASString)v4->pNode;
    v2->value.VS._2 = v7;
    ++*(_DWORD *)(*(_QWORD *)&v2->value.VNumber + 24i64);
  }
}

// File Line: 264
// RVA: 0x7B1AC0
void __fastcall Scaleform::GFx::AS3::Value::AssignUnsafe(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::ASString *v)
{
  Scaleform::GFx::AS3::Value::V2U v2; // [rsp+8h] [rbp-10h]

  if ( v->pNode == &v->pNode->pManager->NullStringNode )
  {
    this->Flags &= 0xFFFFFFEC;
    this->Flags |= 0xCu;
    this->value.VNumber = 0.0;
    this->value.VS._2 = v2;
  }
  else
  {
    this->Flags &= 0xFFFFFFEA;
    this->Flags |= 0xAu;
    *(Scaleform::GFx::ASString *)&this->value.VNumber = (Scaleform::GFx::ASString)v->pNode;
    this->value.VS._2 = v2;
    ++*(_DWORD *)(*(_QWORD *)&this->value.VNumber + 24i64);
  }
}

// File Line: 281
// RVA: 0x7B16E0
void __fastcall Scaleform::GFx::AS3::Value::Assign(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::ASStringNode *v)
{
  Scaleform::GFx::AS3::Value *v2; // rbx
  unsigned int v3; // ecx
  Scaleform::GFx::ASStringNode *v4; // rdi
  Scaleform::GFx::AS3::WeakProxy *v5; // rdx
  bool v6; // zf
  Scaleform::GFx::AS3::Value::V2U v7; // [rsp+28h] [rbp-10h]

  v2 = this;
  v3 = this->Flags;
  v4 = v;
  if ( (char)(v3 & 0x1F) > 9 )
  {
    if ( (v3 >> 9) & 1 )
    {
      v5 = v2->Bonus.pWeakProxy;
      v6 = v5->RefCount-- == 1;
      if ( v6 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v2->Flags &= 0xFFFFFDE0;
      v2->Bonus.pWeakProxy = 0i64;
      v2->value.VNumber = 0.0;
      v2->value.VS._2.VObj = 0i64;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(v2);
    }
  }
  *(_QWORD *)&v2->value.VNumber = v4;
  v2->value.VS._2 = v7;
  if ( !v4 )
    goto LABEL_10;
  if ( v4 == &v4->pManager->NullStringNode )
  {
    v2->value.VNumber = 0.0;
    v2->value.VS._2 = v7;
LABEL_10:
    v2->Flags &= 0xFFFFFFEC;
    v2->Flags |= 0xCu;
    return;
  }
  v2->Flags &= 0xFFFFFFEA;
  v2->Flags |= 0xAu;
  ++v4->RefCount;
}

// File Line: 306
// RVA: 0x7B1B20
void __fastcall Scaleform::GFx::AS3::Value::AssignUnsafe(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::ASStringNode *v)
{
  Scaleform::GFx::AS3::Value::V2U v2; // [rsp+8h] [rbp-10h]

  *(_QWORD *)&this->value.VNumber = v;
  this->value.VS._2 = v2;
  if ( !v )
    goto LABEL_4;
  if ( v == &v->pManager->NullStringNode )
  {
    this->value.VNumber = 0.0;
    this->value.VS._2 = v2;
LABEL_4:
    this->Flags &= 0xFFFFFFEC;
    this->Flags |= 0xCu;
    return;
  }
  this->Flags &= 0xFFFFFFEA;
  this->Flags |= 0xAu;
  ++v->RefCount;
}

// File Line: 331
// RVA: 0x825110
void __fastcall Scaleform::GFx::AS3::Value::Swap(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::AS3::Value *other)
{
  long double v2; // r9
  Scaleform::GFx::AS3::Value::V2U v3; // r10
  unsigned int v4; // er11
  Scaleform::GFx::AS3::Value::Extra v5; // rax

  v2 = other->value.VNumber;
  v3.VObj = (Scaleform::GFx::AS3::Object *)other->value.VS._2;
  v4 = other->Flags;
  v5.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)other->Bonus;
  other->Flags = this->Flags;
  other->Bonus.pWeakProxy = this->Bonus.pWeakProxy;
  other->value = this->value;
  this->value.VNumber = v2;
  this->value.VS._2 = v3;
  this->Flags = v4;
  this->Bonus = v5;
}

// File Line: 346
// RVA: 0x807060
void __fastcall Scaleform::GFx::AS3::Value::Pick(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::AS3::Value *other)
{
  Scaleform::GFx::AS3::Value *v2; // rbx
  unsigned int v3; // ecx
  Scaleform::GFx::AS3::WeakProxy *v5; // rdx
  bool v6; // zf

  v2 = this;
  v3 = this->Flags;
  _RDI = other;
  if ( (char)(v3 & 0x1F) > 9 )
  {
    if ( (v3 >> 9) & 1 )
    {
      v5 = v2->Bonus.pWeakProxy;
      v6 = v5->RefCount-- == 1;
      if ( v6 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v2->Flags &= 0xFFFFFDE0;
      v2->Bonus.pWeakProxy = 0i64;
      v2->value.VNumber = 0.0;
      v2->value.VS._2.VObj = 0i64;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(v2);
    }
  }
  __asm { prefetcht1 byte ptr [rdi]; Prefetch to all cache levels }
  *(_QWORD *)&v2->Flags = *(_QWORD *)&_RDI->Flags;
  v2->Bonus.pWeakProxy = _RDI->Bonus.pWeakProxy;
  v2->value.VNumber = _RDI->value.VNumber;
  v2->value.VS._2.VObj = _RDI->value.VS._2.VObj;
  _RDI->Flags = 0;
}

// File Line: 364
// RVA: 0x7F0B80
Scaleform::GFx::AS3::Value *__fastcall Scaleform::GFx::AS3::Value::GetUndefined()
{
  if ( !(_S11_12 & 1) )
  {
    _S11_12 |= 1u;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0i64;
    atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  return &v;
}

// File Line: 371
// RVA: 0x7ED1F0
Scaleform::GFx::AS3::Value *__fastcall Scaleform::GFx::AS3::Value::GetNull()
{
  if ( !(_S12_13 & 1) )
  {
    _S12_13 |= 1u;
    v_0.Flags = 12;
    v_0.Bonus.pWeakProxy = 0i64;
    v_0.value.VNumber = 0.0;
    atexit(Scaleform::GFx::AS3::Value::GetNull_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  return &v_0;
}

// File Line: 397
// RVA: 0x7B99F0
__int64 __fastcall Scaleform::GFx::AS3::Value::Convert2Boolean(Scaleform::GFx::AS3::Value *this)
{
  Scaleform::GFx::AS3::Value *v1; // rbx
  unsigned __int8 v2; // r8
  unsigned int v3; // ecx
  long double v5; // rax
  long double v6; // rax

  v1 = this;
  v2 = 0;
  v3 = this->Flags & 0x1F;
  switch ( v3 )
  {
    case 0u:
    case 0xBu:
      return 0i64;
    case 1u:
      return v1->value.VS._1.VBool;
    case 2u:
    case 3u:
      return v1->value.VS._1.VInt != 0;
    case 4u:
      v5 = v1->value.VNumber;
      if ( (*(_QWORD *)&v5 & 0x7FF0000000000000i64) == 9218868437227405312i64 && *(_QWORD *)&v5 & 0xFFFFFFFFFFFFFi64
        || Scaleform::GFx::NumberUtil::IsPOSITIVE_ZERO(v1->value.VNumber) )
      {
        return 0i64;
      }
      if ( !Scaleform::GFx::NumberUtil::IsNEGATIVE_ZERO(v1->value.VNumber) )
        return 1;
      return 0i64;
    case 5u:
    case 7u:
    case 0x10u:
    case 0x11u:
      return 1;
    case 0xAu:
      v6 = v1->value.VNumber;
      if ( v6 == 0.0 )
        return 0i64;
      return *(_DWORD *)(*(_QWORD *)&v6 + 32i64) != 0;
    case 0xCu:
    case 0xDu:
    case 0xEu:
    case 0xFu:
      if ( (v3 - 12 <= 3 || v3 == 10) && !*(_QWORD *)&v1->value.VNumber )
        return 0i64;
      return 1;
    default:
      return v2;
  }
}

// File Line: 460
// RVA: 0x7B9D40
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Value::Convert2Number(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::AS3::CheckResult *result, long double *a3)
{
  Scaleform::GFx::AS3::CheckResult *v3; // rbx

  v3 = result;
  Scaleform::GFx::AS3::Value::Convert2NumberInline(this, result, a3);
  return v3;
}

// File Line: 465
// RVA: 0x8263A0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Value::ToNumberValue(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::AS3::CheckResult *result)
{
  Scaleform::GFx::AS3::CheckResult *v2; // rbx
  Scaleform::GFx::AS3::Value *v3; // rdi
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+38h] [rbp+10h]
  long double v; // [rsp+40h] [rbp+18h]

  v2 = result;
  result->Result = 1;
  v3 = this;
  if ( Scaleform::GFx::AS3::Value::Convert2Number(this, &resulta, &v)->Result )
    Scaleform::GFx::AS3::Value::SetNumber(v3, v);
  else
    v2->Result = 0;
  return v2;
}

// File Line: 478
// RVA: 0x7B9E30
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Value::Convert2NumberInternal(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::AS3::CheckResult *result, long double *a3, Scaleform::GFx::AS3::Value::KindType kind)
{
  long double *v4; // r15
  Scaleform::GFx::AS3::CheckResult *v5; // r14
  Scaleform::GFx::AS3::Value *v6; // r10
  long double v7; // rax
  unsigned int v8; // er12
  const char *v9; // r13
  double v10; // xmm6_8
  unsigned int v11; // edi
  const char *v12; // rsi
  unsigned int v13; // eax
  int v14; // edi
  unsigned int v15; // edi
  const char *v16; // rsi
  unsigned int v17; // eax
  int v18; // edi
  unsigned int v19; // ecx
  bool v20; // zf
  Scaleform::GFx::AS3::CheckResult v22; // [rsp+20h] [rbp-50h]
  unsigned int endIndex; // [rsp+24h] [rbp-4Ch]
  Scaleform::String str; // [rsp+28h] [rbp-48h]
  Scaleform::String v25; // [rsp+30h] [rbp-40h]
  __int64 v26; // [rsp+38h] [rbp-38h]
  Scaleform::GFx::AS3::Value v27; // [rsp+40h] [rbp-30h]
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+B8h] [rbp+48h]

  v26 = -2i64;
  v4 = a3;
  v5 = result;
  v6 = this;
  if ( kind == 10 )
  {
    v7 = this->value.VNumber;
    if ( v7 != 0.0 )
    {
      v8 = *(_DWORD *)(*(_QWORD *)&v7 + 32i64);
      if ( v8 )
      {
        v9 = **(const char ***)&v7;
        v10 = Scaleform::GFx::NumberUtil::StringToDouble(**(const char ***)&v7, v8, &endIndex);
        v25.pData = *(Scaleform::String::DataDesc **)&v10;
        if ( ((*(_QWORD *)&v10 & 0x7FF0000000000000i64) != 9218868437227405312i64
           || !(*(_QWORD *)&v10 & 0xFFFFFFFFFFFFFi64))
          && v10 != 0.0 )
        {
          goto LABEL_14;
        }
        if ( endIndex != v8 )
        {
          if ( v10 == 0.0 )
          {
            Scaleform::String::String(&str, &v9[endIndex]);
            v11 = v8 - endIndex;
            v12 = &v9[endIndex];
            v13 = Scaleform::GFx::ASUtils::SkipWhiteSpace(&str);
            v14 = Scaleform::UTF8Util::GetByteIndex(v13, v12, v11);
            if ( !_InterlockedDecrement((volatile signed __int32 *)((str.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            if ( v14 + endIndex >= v8 )
              goto LABEL_12;
          }
          v10 = Scaleform::GFx::NumberUtil::StringToInt(v9, v8, 0, &endIndex);
LABEL_14:
          Scaleform::String::String(&v25, &v9[endIndex]);
          v15 = v8 - endIndex;
          v16 = &v9[endIndex];
          v17 = Scaleform::GFx::ASUtils::SkipWhiteSpace(&v25);
          v18 = Scaleform::UTF8Util::GetByteIndex(v17, v16, v15);
          if ( !_InterlockedDecrement((volatile signed __int32 *)((v25.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          if ( v18 + endIndex < v8 )
          {
            *v4 = Scaleform::GFx::NumberUtil::NaN();
            goto LABEL_36;
          }
LABEL_12:
          *v4 = v10;
LABEL_36:
          v5->Result = 1;
          return v5;
        }
      }
    }
LABEL_21:
    *v4 = Scaleform::GFx::NumberUtil::POSITIVE_ZERO();
    goto LABEL_36;
  }
  v19 = this->Flags & 0x1F;
  if ( (v19 - 12 <= 3 || v19 == 10) && !*(_QWORD *)&v6->value.VNumber )
    goto LABEL_21;
  v27.Flags = 0;
  v27.Bonus.pWeakProxy = 0i64;
  if ( Scaleform::GFx::AS3::Value::Convert2PrimitiveValueUnsafeHintNumber(v6, &resulta, &v27)->Result
    && Scaleform::GFx::AS3::Value::Convert2Number(&v27, &v22, v4)->Result )
  {
    if ( (v27.Flags & 0x1F) > 9 )
    {
      if ( (v27.Flags >> 9) & 1 )
      {
        v20 = v27.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v20 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v27.Bonus.pWeakProxy = 0i64;
        v27.value = 0ui64;
        v27.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v27);
      }
    }
    goto LABEL_36;
  }
  v5->Result = 0;
  if ( (v27.Flags & 0x1F) > 9 )
  {
    if ( (v27.Flags >> 9) & 1 )
    {
      v20 = v27.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v20 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v27.Bonus.pWeakProxy = 0i64;
      v27.value = 0ui64;
      v27.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v27);
    }
  }
  return v5;
}

// File Line: 564
// RVA: 0x7BAD60
int Scaleform::GFx::AS3::ConvertDouble2SInt32(...)
{
  __int128 v1; // xmm6
  __int64 v2; // rcx
  bool v3; // zf
  signed int v4; // ecx
  __int64 result; // rax

  v1 = n;
  if ( (n & 0x7FF0000000000000i64) == 9218868437227405312i64
    || Scaleform::GFx::NumberUtil::IsNEGATIVE_ZERO(*(long double *)&n)
    || Scaleform::GFx::NumberUtil::IsPOSITIVE_ZERO(*(long double *)&n) )
  {
    return 0i64;
  }
  if ( *(double *)&n >= 0.0 )
  {
    v2 = (unsigned int)(signed int)*(double *)&n;
    if ( v2 != 0x8000000000000000i64 )
    {
      v3 = (double)(signed int)v2 == *(double *)&n;
LABEL_9:
      if ( !v3 )
        *(double *)&n = (double)(signed int)(v2 - (_mm_movemask_pd(_mm_unpckl_pd((__m128d)n, (__m128d)n)) & 1));
      goto LABEL_11;
    }
  }
  else
  {
    *(double *)&n = -*(double *)&n;
    *((double *)&n + 1) = -*((double *)&v1 + 1);
    v2 = (unsigned int)(signed int)-*(double *)&v1;
    if ( v2 != 0x8000000000000000i64 )
    {
      v3 = (double)(signed int)v2 == *(double *)&n;
      goto LABEL_9;
    }
  }
LABEL_11:
  if ( *(double *)&n > 4294967295.0 )
    *(double *)&n = fmod(*(long double *)&n, 4294967296.0);
  if ( *(double *)&n < 2147483648.0 )
  {
    if ( *(double *)&v1 < 0.0 )
      *(double *)&n = -*(double *)&n;
    result = (unsigned int)(signed int)*(double *)&n;
  }
  else
  {
    v4 = (signed int)(*(double *)&n - 2147483648.0);
    if ( *(double *)&v1 >= 0.0 )
      result = v4 + 2147483648;
    else
      result = 2147483648 - v4;
  }
  return result;
}

// File Line: 639
// RVA: 0x7B9B40
Scaleform::GFx::AS3::CheckResult *__usercall Scaleform::GFx::AS3::Value::Convert2Int32@<rax>(Scaleform::GFx::AS3::Value *this@<rcx>, Scaleform::GFx::AS3::CheckResult *result@<rdx>, int *a3@<r8>, __int64 a4@<rbx>, __int64 a5@<rdi>, __int64 a6@<rsi>)
{
  int *v6; // rsi
  Scaleform::GFx::AS3::CheckResult *v7; // rdi
  unsigned int v8; // edx
  bool v9; // zf
  Scaleform::GFx::AS3::CheckResult v11; // [rsp+20h] [rbp-40h]
  long double n; // [rsp+28h] [rbp-38h]
  __int64 v13; // [rsp+30h] [rbp-30h]
  Scaleform::GFx::AS3::Value v14; // [rsp+38h] [rbp-28h]
  _BYTE savedregs[24]; // [rsp+60h] [rbp+0h]
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+80h] [rbp+20h]
  __int64 v17; // [rsp+88h] [rbp+28h]
  Scaleform::GFx::AS3::CheckResult v18; // [rsp+98h] [rbp+38h]

  *(_QWORD *)&savedregs[16] = savedregs;
  *(_QWORD *)&savedregs[8] = a6;
  *(_QWORD *)savedregs = a5;
  v13 = -2i64;
  v17 = a4;
  v6 = a3;
  v7 = result;
  v8 = this->Flags & 0x1F;
  switch ( v8 )
  {
    case 0u:
    case 5u:
    case 0xFu:
      goto $LN14_51;
    case 1u:
      *a3 = this->value.VS._1.VBool != 0;
      goto LABEL_27;
    case 2u:
    case 3u:
    case 7u:
      *a3 = this->value.VS._1.VInt;
      goto LABEL_27;
    case 4u:
      *a3 = Scaleform::GFx::AS3::ConvertDouble2SInt32(this->value.VNumber);
      goto LABEL_27;
    case 0xAu:
      if ( !*(_QWORD *)&this->value.VNumber )
        goto $LN14_51;
      if ( !Scaleform::GFx::AS3::Value::Convert2Number(this, &resulta, &n)->Result )
      {
        v7->Result = 0;
        return v7;
      }
      *v6 = Scaleform::GFx::AS3::ConvertDouble2SInt32(n);
      goto LABEL_27;
    default:
      if ( (v8 - 12 <= 3 || v8 == 10) && !*(_QWORD *)&this->value.VNumber )
      {
$LN14_51:
        *a3 = 0;
LABEL_27:
        v7->Result = 1;
        return v7;
      }
      v14.Flags = 0;
      v14.Bonus.pWeakProxy = 0i64;
      if ( Scaleform::GFx::AS3::Value::Convert2PrimitiveValueUnsafeHintNumber(this, &v18, &v14)->Result
        && Scaleform::GFx::AS3::Value::Convert2Int32(&v14, &v11, v6)->Result )
      {
        if ( (v14.Flags & 0x1F) > 9 )
        {
          if ( (v14.Flags >> 9) & 1 )
          {
            v9 = v14.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v9 )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            v14.Bonus.pWeakProxy = 0i64;
            v14.value = 0ui64;
            v14.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v14);
          }
        }
        goto LABEL_27;
      }
      v7->Result = 0;
      if ( (v14.Flags & 0x1F) > 9 )
      {
        if ( (v14.Flags >> 9) & 1 )
        {
          v9 = v14.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v9 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          v14.Bonus.pWeakProxy = 0i64;
          v14.value = 0ui64;
          v14.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v14);
        }
      }
      return v7;
  }
}

// File Line: 698
// RVA: 0x7BAA10
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Value::Convert2UInt32(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::AS3::CheckResult *result, unsigned int *a3)
{
  unsigned int *v3; // rsi
  Scaleform::GFx::AS3::CheckResult *v4; // rdi
  unsigned int v5; // edx
  bool v6; // zf
  Scaleform::GFx::AS3::CheckResult v8; // [rsp+20h] [rbp-40h]
  long double n; // [rsp+28h] [rbp-38h]
  __int64 v10; // [rsp+30h] [rbp-30h]
  Scaleform::GFx::AS3::Value v11; // [rsp+38h] [rbp-28h]
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+80h] [rbp+20h]
  Scaleform::GFx::AS3::CheckResult v13; // [rsp+98h] [rbp+38h]

  v10 = -2i64;
  v3 = a3;
  v4 = result;
  v5 = this->Flags & 0x1F;
  switch ( v5 )
  {
    case 0u:
    case 5u:
    case 0xFu:
      goto $LN14_54;
    case 1u:
      *a3 = this->value.VS._1.VBool != 0;
      goto LABEL_27;
    case 2u:
    case 3u:
      *a3 = this->value.VS._1.VUInt;
      goto LABEL_27;
    case 4u:
      *a3 = Scaleform::GFx::AS3::ConvertDouble2SInt32(this->value.VNumber);
      goto LABEL_27;
    case 0xAu:
      if ( !*(_QWORD *)&this->value.VNumber )
        goto $LN14_54;
      if ( !Scaleform::GFx::AS3::Value::Convert2Number(this, &resulta, &n)->Result )
      {
        v4->Result = 0;
        return v4;
      }
      *v3 = Scaleform::GFx::AS3::ConvertDouble2SInt32(n);
      goto LABEL_27;
    default:
      if ( (v5 - 12 <= 3 || v5 == 10) && !*(_QWORD *)&this->value.VNumber )
      {
$LN14_54:
        *a3 = 0;
LABEL_27:
        v4->Result = 1;
        return v4;
      }
      v11.Flags = 0;
      v11.Bonus.pWeakProxy = 0i64;
      if ( Scaleform::GFx::AS3::Value::Convert2PrimitiveValueUnsafeHintNumber(this, &v13, &v11)->Result
        && Scaleform::GFx::AS3::Value::Convert2UInt32(&v11, &v8, v3)->Result )
      {
        if ( (v11.Flags & 0x1F) > 9 )
        {
          if ( (v11.Flags >> 9) & 1 )
          {
            v6 = v11.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v6 )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            v11.Bonus.pWeakProxy = 0i64;
            v11.value = 0ui64;
            v11.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v11);
          }
        }
        goto LABEL_27;
      }
      v4->Result = 0;
      if ( (v11.Flags & 0x1F) > 9 )
      {
        if ( (v11.Flags >> 9) & 1 )
        {
          v6 = v11.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v6 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          v11.Bonus.pWeakProxy = 0i64;
          v11.value = 0ui64;
          v11.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v11);
        }
      }
      return v4;
  }
}

// File Line: 759
// RVA: 0x817010
signed __int64 __fastcall Scaleform::GFx::AS3::SF_ECMA_dtostr(char *buffer, int bufflen, long double val)
{
  char *v3; // rbx
  signed __int64 result; // rax
  double v5; // xmm0_8
  int v6; // eax
  int v7; // er11
  __int64 v8; // rcx
  char v9; // r9
  int v10; // edx
  char *v11; // rcx
  int v12; // er8
  int v13; // ecx
  signed __int64 v14; // rax
  char v15; // r10
  char *v16; // r8
  char *v17; // rdx
  char v18; // al
  char v19; // al
  char *v20; // rdx
  char v21; // al
  char i; // di
  int v23; // eax
  char *v24; // r10
  char v25; // r9
  char *v26; // rdi
  char v27; // [rsp+1Fh] [rbp-31h]
  char dest; // [rsp+20h] [rbp-30h]
  __int64 v29; // [rsp+21h] [rbp-2Fh]
  __int64 v30; // [rsp+29h] [rbp-27h]
  __int64 v31; // [rsp+31h] [rbp-1Fh]
  __int64 v32; // [rsp+39h] [rbp-17h]
  int v33; // [rsp+41h] [rbp-Fh]
  __int16 v34; // [rsp+45h] [rbp-Bh]
  char v35; // [rsp+47h] [rbp-9h]
  long double format; // [rsp+70h] [rbp+20h]

  v3 = buffer;
  if ( val == (double)(signed int)val )
  {
    itoa_s((signed int)val, buffer, bufflen, 10);
    result = -1i64;
    do
      ++result;
    while ( v3[result] );
    return result;
  }
  format = val;
  if ( (*(_QWORD *)&val & 0x7FF0000000000000i64) == 9218868437227405312i64 && *(_QWORD *)&val & 0xFFFFFFFFFFFFFi64 )
  {
    strcpy(buffer, "NaN");
    return 3i64;
  }
  format = val;
  if ( val == 1.797693134862316e308/*+Inf*/ )
  {
    *(_QWORD *)buffer = *(_QWORD *)aInfinity_2;
    buffer[8] = 0;
    return 8i64;
  }
  format = val;
  if ( val == -1.797693134862316e308/*-Inf*/ )
  {
    *(_QWORD *)buffer = *(_QWORD *)aInfinit;
    *((_WORD *)buffer + 4) = 121;
    return 9i64;
  }
  v29 = 0i64;
  v30 = 0i64;
  v31 = 0i64;
  *(_QWORD *)&v5 = *(_QWORD *)&val & _xmm;
  v32 = 0i64;
  v33 = 0;
  v34 = 0;
  v35 = 0;
  dest = 0;
  LODWORD(format) = *(_DWORD *)a16;
  WORD2(format) = 103;
  if ( COERCE_DOUBLE(*(_QWORD *)&val & _xmm) >= 1.0e16 && v5 < 1.0e21 )
  {
    BYTE3(format) = 55;
    if ( v5 >= 1.0e17 )
    {
      BYTE3(format) = 56;
      if ( v5 >= 1.0e18 )
      {
        BYTE3(format) = 57;
        if ( v5 >= 1.0e19 )
        {
          WORD1(format) = 12338;
          if ( v5 >= 1.0e20 )
            WORD1(format) = 12594;
        }
      }
    }
  }
  v6 = Scaleform::SFsprintf(&dest, 0x28ui64, (const char *)&format, val, *(_QWORD *)&dest);
  v7 = 0;
  v8 = 0i64;
  if ( v6 <= 0 )
  {
LABEL_22:
    v9 = dest;
    v10 = 0;
    if ( !dest )
      goto LABEL_35;
    v11 = &dest;
    while ( (*v11 - 44) & 0xFD )
    {
      ++v11;
      ++v10;
      if ( !*v11 )
        goto LABEL_35;
    }
    if ( *(&v27 + v6) == 48 )
      goto LABEL_35;
    v12 = v6 - 2;
    v13 = v12;
    v14 = v6 - 2;
    if ( v12 > (signed __int64)v10 )
    {
      do
      {
        if ( *(&dest + v14) != 48 )
          break;
        --v14;
        --v13;
      }
      while ( v14 > v10 );
    }
    if ( v13 >= v12 || v13 == v10 )
      goto LABEL_35;
    *((_BYTE *)&v29 + v13) = 0;
  }
  else
  {
    while ( *(&dest + v8) != 101 )
    {
      if ( ++v8 >= v6 )
        goto LABEL_22;
    }
  }
  v9 = dest;
LABEL_35:
  v15 = 0;
  v16 = v3;
  v17 = &dest;
  if ( !v9 )
    goto LABEL_65;
  v18 = v9;
  while ( v18 == 44 )
  {
    *v16 = 46;
LABEL_41:
    v18 = (v17++)[1];
    ++v16;
    if ( !v18 )
      goto LABEL_65;
  }
  if ( v18 != 101 )
  {
    *v16 = v18;
    goto LABEL_41;
  }
  v19 = *v17;
  v20 = v17 + 1;
  *(++v16 - 1) = v19;
  v21 = *v20;
  if ( *v20 == 45 )
  {
    v15 = 1;
    goto LABEL_47;
  }
  if ( v21 == 43 )
  {
LABEL_47:
    *v16++ = v21;
    ++v20;
  }
  for ( ; *v20 == 48; ++v20 )
    ;
  for ( i = *v20; *v20 >= 48; v7 = v23 + 2 * (5 * v7 - 24) )
  {
    if ( i > 57 )
      break;
    ++v20;
    v23 = i;
    *v16 = i;
    i = *v20;
    ++v16;
  }
  if ( v15 && (unsigned int)(v7 - 1) <= 5 )
  {
    v24 = &dest;
    v16 = v3;
    if ( v9 == 45 )
    {
      v24 = (char *)&v29;
      v16 = v3 + 1;
    }
    v25 = *v24;
    if ( (unsigned __int8)(*v24 - 49) <= 8u && v16[1] == 46 )
    {
      *(_WORD *)v16 = 11824;
      v16 += 2;
      if ( v7 > 1 )
      {
        v26 = v16;
        v16 += (unsigned int)(v7 - 1);
        memset(v26, 48, (unsigned int)(v7 - 1));
      }
      for ( ; v25 != 101; ++v24 )
      {
        if ( (unsigned __int8)(v25 - 48) <= 9u )
          *v16++ = v25;
        v25 = v24[1];
      }
    }
  }
LABEL_65:
  *v16 = 0;
  return v16 - v3;
}

// File Line: 963
// RVA: 0x7BA350
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Value::Convert2String(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::ASString *a3)
{
  Scaleform::GFx::ASString *v3; // rbx
  Scaleform::GFx::AS3::CheckResult *v4; // rdi
  Scaleform::GFx::AS3::Value *v5; // rsi
  Scaleform::GFx::ASStringManager *v6; // r10
  unsigned int v7; // edx
  unsigned __int64 v8; // r8
  const char *v9; // rdx
  Scaleform::String *v10; // rax
  Scaleform::GFx::ASString *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  bool v13; // zf
  Scaleform::String::DataDesc *v14; // rdx
  Scaleform::String *v15; // rax
  Scaleform::GFx::ASString *v16; // rax
  Scaleform::GFx::ASStringNode *v17; // rcx
  unsigned __int64 v18; // rax
  Scaleform::GFx::ASStringNode *v19; // rax
  int v20; // eax
  Scaleform::GFx::AS3::VM *v21; // rbx
  Scaleform::GFx::AS3::VM::Error *v22; // rax
  Scaleform::GFx::ASStringNode *v23; // rcx
  long double v24; // rsi
  Scaleform::GFx::ASStringNode *v25; // rcx
  Scaleform::GFx::AS3::Value v27; // [rsp+30h] [rbp-49h]
  Scaleform::GFx::ASStringManager *v28; // [rsp+50h] [rbp-29h]
  unsigned int v29; // [rsp+58h] [rbp-21h]
  Scaleform::GFx::ASString v30; // [rsp+60h] [rbp-19h]
  Scaleform::String v31; // [rsp+68h] [rbp-11h]
  Scaleform::String resulta; // [rsp+70h] [rbp-9h]
  Scaleform::GFx::ASString v33; // [rsp+78h] [rbp-1h]
  __int64 v34; // [rsp+80h] [rbp+7h]
  Scaleform::GFx::AS3::VM::Error v35; // [rsp+88h] [rbp+Fh]
  char buffer; // [rsp+98h] [rbp+1Fh]
  Scaleform::GFx::AS3::CheckResult v37; // [rsp+E0h] [rbp+67h]
  Scaleform::GFx::AS3::CheckResult v38; // [rsp+F0h] [rbp+77h]
  int v; // [rsp+F8h] [rbp+7Fh]

  v34 = -2i64;
  v3 = a3;
  v4 = result;
  v5 = this;
  v6 = a3->pNode->pManager;
  v28 = a3->pNode->pManager;
  v7 = this->Flags & 0x1F;
  switch ( v7 )
  {
    case 0u:
      v8 = 9i64;
      v9 = "undefined";
      goto LABEL_42;
    case 1u:
      v8 = 5i64 - (this->value.VS._1.VBool != 0);
      v9 = "false";
      if ( this->value.VS._1.VBool )
        v9 = "true";
      goto LABEL_42;
    case 2u:
      v = this->value.VS._1.VInt;
      v10 = Scaleform::AsString<long>(&resulta, &v);
      v11 = Scaleform::GFx::ASStringManager::CreateString(v28, &v33, v10);
      Scaleform::GFx::ASString::operator=(v3, v11);
      v12 = v33.pNode;
      v13 = v33.pNode->RefCount == 1;
      --v12->RefCount;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v12);
      v14 = resulta.pData;
      goto LABEL_10;
    case 3u:
      v29 = this->value.VS._1.VUInt;
      v15 = Scaleform::AsString<unsigned long>(&v31, &v29);
      v16 = Scaleform::GFx::ASStringManager::CreateString(v28, &v30, v15);
      Scaleform::GFx::ASString::operator=(v3, v16);
      v17 = v30.pNode;
      v13 = v30.pNode->RefCount == 1;
      --v17->RefCount;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v17);
      v14 = v31.pData;
LABEL_10:
      if ( !_InterlockedDecrement((volatile signed __int32 *)(((unsigned __int64)v14 & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      goto LABEL_47;
    case 4u:
      v18 = Scaleform::GFx::AS3::SF_ECMA_dtostr(&buffer, 40, this->value.VNumber);
      v19 = Scaleform::GFx::ASStringManager::CreateStringNode(v28, &buffer, v18);
      goto LABEL_43;
    case 5u:
    case 7u:
    case 0x10u:
    case 0x11u:
      v8 = 22i64;
      v9 = "function Function() {}";
      goto LABEL_42;
    case 8u:
    case 9u:
      *(_QWORD *)&v24 = (char *)v6 + 64;
      ++v6->EmptyStringNode.RefCount;
      goto LABEL_44;
    case 0xAu:
      v24 = this->value.VNumber;
      if ( v24 == 0.0 )
        goto LABEL_41;
      ++*(_DWORD *)(*(_QWORD *)&v24 + 24i64);
      goto LABEL_44;
    case 0xBu:
      Scaleform::GFx::ASString::operator=(a3, (Scaleform::GFx::ASString *)(*(_QWORD *)&this->value.VNumber + 56i64));
      goto LABEL_47;
    case 0xCu:
    case 0xDu:
    case 0xEu:
    case 0xFu:
      if ( (v7 - 12 <= 3 || v7 == 10) && !*(_QWORD *)&this->value.VNumber )
      {
LABEL_41:
        v9 = "null";
        v8 = 4i64;
LABEL_42:
        v19 = Scaleform::GFx::ASStringManager::CreateConstStringNode(v6, v9, v8, 0);
LABEL_43:
        ++v19->RefCount;
        v24 = *(double *)&v19;
LABEL_44:
        v25 = v3->pNode;
        v13 = v3->pNode->RefCount == 1;
        --v25->RefCount;
        if ( v13 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v25);
        *(long double *)&v3->pNode = v24;
        goto LABEL_47;
      }
      v27.Flags = 0;
      v27.Bonus.pWeakProxy = 0i64;
      if ( Scaleform::GFx::AS3::Value::Convert2PrimitiveValueUnsafe(this, &v37, v6, &v27, hintString)->Result )
      {
        v20 = v27.Flags & 0x1F;
        if ( v20 > 4 && v20 != 10 )
        {
          v21 = *(Scaleform::GFx::AS3::VM **)(*(_QWORD *)(*(_QWORD *)&v5->value.VNumber + 40i64) + 128i64);
          Scaleform::GFx::AS3::VM::Error::Error(&v35, eConvertToPrimitiveError, v21);
          Scaleform::GFx::AS3::VM::ThrowErrorInternal(v21, v22, &Scaleform::GFx::AS3::fl::TypeErrorTI);
          v23 = v35.Message.pNode;
          v13 = v35.Message.pNode->RefCount == 1;
          --v23->RefCount;
          if ( v13 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v23);
          goto LABEL_21;
        }
        if ( Scaleform::GFx::AS3::Value::Convert2String(&v27, &v38, v3)->Result )
        {
          if ( (v27.Flags & 0x1F) > 9 )
          {
            if ( (v27.Flags >> 9) & 1 )
            {
              v13 = v27.Bonus.pWeakProxy->RefCount-- == 1;
              if ( v13 )
                ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
              v27.Bonus.pWeakProxy = 0i64;
              v27.value = 0ui64;
              v27.Flags &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&v27);
            }
          }
LABEL_47:
          v4->Result = 1;
          return v4;
        }
      }
LABEL_21:
      v4->Result = 0;
      if ( (v27.Flags & 0x1F) > 9 )
      {
        if ( (v27.Flags >> 9) & 1 )
        {
          v13 = v27.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v13 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          v27.Bonus.pWeakProxy = 0i64;
          v27.value = 0ui64;
          v27.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v27);
        }
      }
      return v4;
    default:
      goto LABEL_47;
  }
}

// File Line: 1060
// RVA: 0x7BA700
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Value::Convert2String(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::StringBuffer *a3)
{
  Scaleform::StringBuffer *v3; // rbx
  Scaleform::GFx::AS3::CheckResult *v4; // rdi
  Scaleform::GFx::AS3::Value *v5; // r10
  unsigned int v6; // ecx
  char *v7; // rdx
  Scaleform::String *v8; // rax
  Scaleform::String::DataDesc *v9; // rdx
  Scaleform::String *v10; // rax
  __int64 v11; // r8
  bool v12; // zf
  long double v13; // rdx
  Scaleform::GFx::AS3::Value v15; // [rsp+30h] [rbp-29h]
  unsigned int v16; // [rsp+50h] [rbp-9h]
  int v; // [rsp+54h] [rbp-5h]
  Scaleform::String v18; // [rsp+58h] [rbp-1h]
  Scaleform::String resulta; // [rsp+60h] [rbp+7h]
  __int64 v20; // [rsp+68h] [rbp+Fh]
  char buffer; // [rsp+70h] [rbp+17h]
  Scaleform::GFx::AS3::CheckResult v22; // [rsp+C0h] [rbp+67h]
  Scaleform::GFx::AS3::CheckResult v23; // [rsp+D8h] [rbp+7Fh]

  v20 = -2i64;
  v3 = a3;
  v4 = result;
  v5 = this;
  v6 = this->Flags & 0x1F;
  switch ( v6 )
  {
    case 0u:
      v7 = "undefined";
      goto LABEL_33;
    case 1u:
      v7 = "false";
      if ( v5->value.VS._1.VBool )
        v7 = "true";
      goto LABEL_33;
    case 2u:
      v = v5->value.VS._1.VInt;
      v8 = Scaleform::AsString<long>(&resulta, &v);
      Scaleform::StringBuffer::AppendString(
        v3,
        (const char *)((v8->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
        *(_QWORD *)(v8->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64);
      v9 = resulta.pData;
      goto LABEL_9;
    case 3u:
      v16 = v5->value.VS._1.VUInt;
      v10 = Scaleform::AsString<unsigned long>(&v18, &v16);
      Scaleform::StringBuffer::AppendString(
        v3,
        (const char *)((v10->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
        *(_QWORD *)(v10->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64);
      v9 = v18.pData;
LABEL_9:
      if ( !_InterlockedDecrement((volatile signed __int32 *)(((unsigned __int64)v9 & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      goto LABEL_35;
    case 4u:
      v11 = Scaleform::GFx::AS3::SF_ECMA_dtostr(&buffer, 40, v5->value.VNumber);
      v7 = &buffer;
      goto LABEL_34;
    case 5u:
    case 7u:
    case 0x10u:
    case 0x11u:
      v7 = "function Function() {}";
      goto LABEL_33;
    case 0xAu:
      v13 = v5->value.VNumber;
      if ( v13 == 0.0 )
        goto LABEL_32;
      v11 = *(unsigned int *)(*(_QWORD *)&v13 + 32i64);
      v7 = **(char ***)&v13;
      goto LABEL_34;
    case 0xBu:
      v7 = **(char ***)(*(_QWORD *)&v5->value.VNumber + 56i64);
      goto LABEL_33;
    case 0xCu:
    case 0xDu:
    case 0xEu:
    case 0xFu:
      if ( (v6 - 12 <= 3 || v6 == 10) && !*(_QWORD *)&v5->value.VNumber )
      {
LABEL_32:
        v7 = "null";
LABEL_33:
        v11 = -1i64;
LABEL_34:
        Scaleform::StringBuffer::AppendString(v3, v7, v11);
        goto LABEL_35;
      }
      v15.Flags = 0;
      v15.Bonus.pWeakProxy = 0i64;
      if ( Scaleform::GFx::AS3::Value::Convert2PrimitiveValueUnsafe(
             v5,
             &v22,
             *(Scaleform::GFx::ASStringManager **)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)&v5->value.VNumber
                                                                                     + 40i64)
                                                                         + 128i64)
                                                             + 16i64)
                                                 + 512i64),
             &v15,
             hintString)->Result
        && Scaleform::GFx::AS3::Value::Convert2String(&v15, &v23, v3)->Result )
      {
        if ( (v15.Flags & 0x1F) > 9 )
        {
          if ( (v15.Flags >> 9) & 1 )
          {
            v12 = v15.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v12 )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            v15.Bonus.pWeakProxy = 0i64;
            v15.value = 0ui64;
            v15.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v15);
          }
        }
LABEL_35:
        v4->Result = 1;
        return v4;
      }
      v4->Result = 0;
      if ( (v15.Flags & 0x1F) > 9 )
      {
        if ( (v15.Flags >> 9) & 1 )
        {
          v12 = v15.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v12 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          v15.Bonus.pWeakProxy = 0i64;
          v15.value = 0ui64;
          v15.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v15);
        }
      }
      return v4;
    default:
      goto LABEL_35;
  }
}

// File Line: 1168
// RVA: 0x825C20
Scaleform::GFx::AS3::CheckResult *__usercall Scaleform::GFx::AS3::Value::ToInt32Value@<rax>(Scaleform::GFx::AS3::Value *this@<rcx>, Scaleform::GFx::AS3::CheckResult *result@<rdx>, __int64 a3@<rsi>)
{
  Scaleform::GFx::AS3::CheckResult *v3; // rbx
  Scaleform::GFx::AS3::Value *v4; // rdi
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+38h] [rbp+10h]
  int v; // [rsp+40h] [rbp+18h]

  v3 = result;
  v4 = this;
  if ( Scaleform::GFx::AS3::Value::Convert2Int32(this, &resulta, &v, (__int64)result, (__int64)this, a3)->Result )
  {
    Scaleform::GFx::AS3::Value::SetSInt32(v4, v);
    v3->Result = 1;
  }
  else
  {
    v3->Result = 0;
  }
  return v3;
}

// File Line: 1181
// RVA: 0x826A00
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Value::ToUInt32Value(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::AS3::CheckResult *result)
{
  Scaleform::GFx::AS3::CheckResult *v2; // rbx
  Scaleform::GFx::AS3::Value *v3; // rdi
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+38h] [rbp+10h]
  unsigned int v; // [rsp+40h] [rbp+18h]

  v2 = result;
  result->Result = 1;
  v3 = this;
  if ( Scaleform::GFx::AS3::Value::Convert2UInt32(this, &resulta, &v)->Result )
    Scaleform::GFx::AS3::Value::SetUInt32(v3, v);
  else
    v2->Result = 0;
  return v2;
}

// File Line: 1194
// RVA: 0x826980
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Value::ToStringValue(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::StringManager *sm)
{
  Scaleform::GFx::AS3::CheckResult *v3; // rbx
  Scaleform::GFx::AS3::Value *v4; // rdi
  Scaleform::GFx::ASStringNode *v5; // rcx
  bool v6; // zf
  Scaleform::GFx::AS3::CheckResult v8; // [rsp+48h] [rbp+10h]
  Scaleform::GFx::ASString resulta; // [rsp+58h] [rbp+20h]

  v3 = result;
  v4 = this;
  result->Result = 1;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)sm->Builtins,
    &resulta);
  if ( Scaleform::GFx::AS3::Value::Convert2String(v4, &v8, &resulta)->Result )
    Scaleform::GFx::AS3::Value::Assign(v4, &resulta);
  else
    v3->Result = 0;
  v5 = resulta.pNode;
  v6 = resulta.pNode->RefCount == 1;
  --v5->RefCount;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  return v3;
}

// File Line: 1239
// RVA: 0x800A80
char __fastcall Scaleform::GFx::AS3::Value::MakeWeakRef(Scaleform::GFx::AS3::Value *this)
{
  Scaleform::GFx::AS3::Value *v1; // rbx
  signed int v2; // edx
  long double v3; // rcx
  Scaleform::GFx::AS3::WeakProxy *v4; // rcx
  Scaleform::Pickable<Scaleform::GFx::AS3::WeakProxy> result; // [rsp+30h] [rbp+8h]

  v1 = this;
  if ( (this->Flags >> 9) & 1 )
    return 0;
  v2 = this->Flags & 0x1F;
  if ( v2 <= 10 )
    return 0;
  if ( v2 == 11 )
    goto LABEL_14;
  if ( v2 <= 11 )
    return 0;
  if ( v2 <= 15 )
  {
LABEL_14:
    v3 = this->value.VNumber;
  }
  else
  {
    if ( v2 > 17 )
      return 0;
    v3 = *(double *)&this->value.VS._2.VObj;
  }
  if ( v3 != 0.0 )
  {
    v4 = Scaleform::GFx::AS3::GASRefCountBase::CreateWeakProxy(*(Scaleform::GFx::AS3::GASRefCountBase **)&v3, &result)->pV;
    v1->Flags |= 0x200u;
    v1->Bonus.pWeakProxy = v4;
    Scaleform::GFx::AS3::Value::ReleaseInternal(v1);
    return 1;
  }
  return 0;
}

// File Line: 1259
// RVA: 0x8006F0
char __fastcall Scaleform::GFx::AS3::Value::MakeStrongRef(Scaleform::GFx::AS3::Value *this)
{
  Scaleform::GFx::AS3::Value *v1; // rbx
  unsigned int v2; // ecx
  int v3; // ecx
  long double v4; // rcx
  Scaleform::GFx::AS3::WeakProxy *v5; // rdx
  bool v6; // zf
  char result; // al

  v1 = this;
  v2 = this->Flags;
  if ( !((v2 >> 9) & 1) )
    return 0;
  if ( !v1->Bonus.pWeakProxy->pObject )
  {
    result = 1;
    v1->value.VNumber = 0.0;
    v1->value.VS._2.VObj = 0i64;
    v1->Flags = v2 & 0xFFFFFFE0;
    v1->Flags &= 0xFFFFFDFF;
    v1->Bonus.pWeakProxy = 0i64;
    return result;
  }
  v3 = v2 & 0x1F;
  if ( v3 == 10 )
  {
    ++*(_DWORD *)(*(_QWORD *)&v1->value.VNumber + 24i64);
  }
  else if ( v3 > 10 )
  {
    if ( v3 <= 15 )
    {
      v4 = v1->value.VNumber;
LABEL_9:
      if ( v4 != 0.0 )
        *(_DWORD *)(*(_QWORD *)&v4 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v4 + 32i64) + 1) & 0x8FBFFFFF;
      goto LABEL_12;
    }
    if ( v3 <= 17 )
    {
      v4 = *(double *)&v1->value.VS._2.VObj;
      goto LABEL_9;
    }
  }
LABEL_12:
  v5 = v1->Bonus.pWeakProxy;
  v6 = v5->RefCount-- == 1;
  if ( v6 )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  result = 1;
  v1->Flags &= 0xFFFFFDFF;
  v1->Bonus.pWeakProxy = 0i64;
  return result;
}

// File Line: 1289
// RVA: 0x7F96A0
bool __fastcall Scaleform::GFx::AS3::Value::IsValidWeakRef(Scaleform::GFx::AS3::Value *this)
{
  bool result; // al

  if ( (this->Flags >> 9) & 1 )
    result = this->Bonus.pWeakProxy->pObject != 0i64;
  else
    result = 1;
  return result;
}

// File Line: 1307
// RVA: 0x790F30
signed __int64 __fastcall Scaleform::GFx::AS3::Value::HashFunctor::operator()(Scaleform::GFx::AS3::Value::HashFunctor *this, Scaleform::GFx::AS3::Value *v)
{
  signed __int64 v2; // r8
  signed int v3; // er10
  signed __int64 result; // rax
  signed __int64 v5; // rcx
  signed __int64 v6; // r8
  __int64 v7; // rax
  signed __int64 v8; // rcx
  signed __int64 v9; // r8
  __int64 v10; // rax
  long double v11; // rax
  signed __int64 v12; // r8
  signed __int64 v13; // rcx
  Scaleform::GFx::AS3::Value::V2U v14; // rax
  signed __int64 v15; // rdx
  __int64 v16; // rax
  signed __int64 v17; // rcx
  __int64 v18; // rax
  signed __int64 v19; // r8
  signed __int64 v20; // rcx
  Scaleform::GFx::AS3::Value::V2U v21; // rax
  signed __int64 v22; // rdx
  __int64 v23; // rax
  signed __int64 v24; // rcx
  __int64 v25; // rax
  signed __int64 v26; // rcx
  signed __int64 v27; // r8
  __int64 v28; // rax
  signed __int64 v29; // rcx
  signed __int64 v30; // r8
  __int64 v31; // rax
  Scaleform::GFx::AS3::Value::V2U v32; // rax
  long double v33; // r9
  signed __int64 v34; // r8
  signed __int64 v35; // rcx
  signed __int64 v36; // rdx
  __int64 v37; // rax
  signed __int64 v38; // rcx
  __int64 v39; // rax
  char v40; // [rsp+Fh] [rbp+Fh]
  Scaleform::GFx::AS3::Value::V1U v41; // [rsp+10h] [rbp+10h]
  Scaleform::GFx::AS3::Value::V2U v42; // [rsp+18h] [rbp+18h]

  v2 = 0i64;
  v3 = v->Flags & 0x1F;
  switch ( v3 )
  {
    case 1:
      LOBYTE(v2) = v->value.VS._1.VBool != 0;
      result = v2 + v3;
      break;
    case 2:
    case 3:
      v5 = 4i64;
      v6 = 5381i64;
      v41.VInt = v->value.VS._1.VInt;
      do
      {
        v7 = (unsigned __int8)*(&v40 + v5--);
        v6 = v7 + 65599 * v6;
      }
      while ( v5 );
      result = v6 + v3;
      break;
    case 4:
      v8 = 8i64;
      v9 = 5381i64;
      v41 = *(Scaleform::GFx::AS3::Value::V1U *)&v->value.VNumber;
      do
      {
        v10 = (unsigned __int8)*(&v40 + v8--);
        v9 = v10 + 65599 * v9;
      }
      while ( v8 );
      result = v9 + v3;
      break;
    case 5:
      v26 = 48i64;
      v27 = 5381i64;
      do
      {
        v28 = *(unsigned __int8 *)(*(_QWORD *)&v->value.VNumber + v26-- - 1);
        v27 = v28 + 65599 * v27;
      }
      while ( v26 );
      result = v27 + v3;
      break;
    case 7:
      v12 = 5381i64;
      v13 = 4i64;
      v41.VInt = v->value.VS._1.VInt;
      v14.VObj = (Scaleform::GFx::AS3::Object *)v->value.VS._2;
      v15 = 5381i64;
      v42.VObj = v14.VObj;
      do
      {
        v16 = (unsigned __int8)*(&v40 + v13--);
        v15 = v16 + 65599 * v15;
      }
      while ( v13 );
      v17 = 8i64;
      do
      {
        v18 = *((unsigned __int8 *)&v41.VFunct + v17-- + 7);
        v12 = v18 + 65599 * v12;
      }
      while ( v17 );
      result = (v15 ^ v12) + v3;
      break;
    case 10:
      v11 = v->value.VNumber;
      if ( v11 == 0.0 )
        goto LABEL_33;
      result = (*(_DWORD *)(*(_QWORD *)&v11 + 28i64) & 0xFFFFFF) + (signed __int64)v3;
      break;
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
      if ( !*(_QWORD *)&v->value.VNumber )
        goto LABEL_33;
      v41 = *(Scaleform::GFx::AS3::Value::V1U *)&v->value.VNumber;
      v29 = 8i64;
      v30 = 5381i64;
      do
      {
        v31 = (unsigned __int8)*(&v40 + v29--);
        v30 = v31 + 65599 * v30;
      }
      while ( v29 );
      result = v30 + v3;
      break;
    case 16:
      v32.VObj = (Scaleform::GFx::AS3::Object *)v->value.VS._2;
      v33 = v->value.VNumber;
      v34 = 5381i64;
      v35 = 48i64;
      v36 = 5381i64;
      v41 = (Scaleform::GFx::AS3::Value::V1U)v32.VObj;
      do
      {
        v37 = *(unsigned __int8 *)(*(_QWORD *)&v33 + v35-- - 1);
        v36 = v37 + 65599 * v36;
      }
      while ( v35 );
      v38 = 8i64;
      do
      {
        v39 = (unsigned __int8)*(&v40 + v38--);
        v34 = v39 + 65599 * v34;
      }
      while ( v38 );
      v2 = v36 ^ v34;
      goto LABEL_33;
    case 17:
      v19 = 5381i64;
      v20 = 4i64;
      v41.VInt = v->value.VS._1.VInt;
      v21.VObj = (Scaleform::GFx::AS3::Object *)v->value.VS._2;
      v22 = 5381i64;
      v42.VObj = v21.VObj;
      do
      {
        v23 = (unsigned __int8)*(&v40 + v20--);
        v22 = v23 + 65599 * v22;
      }
      while ( v20 );
      v24 = 8i64;
      do
      {
        v25 = *((unsigned __int8 *)&v41.VFunct + v24-- + 7);
        v19 = v25 + 65599 * v19;
      }
      while ( v24 );
      result = (v22 ^ v19) + v3;
      break;
    default:
LABEL_33:
      result = v2 + v3;
      break;
  }
  return result;
}

// File Line: 1399
// RVA: 0x7A9F30
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::AbstractLessThan(Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::Boolean3 *a2, Scaleform::GFx::AS3::Value *l, Scaleform::GFx::AS3::Value *r)
{
  Scaleform::GFx::AS3::Value *v4; // rbx
  Scaleform::GFx::AS3::Boolean3 *v5; // r12
  Scaleform::GFx::AS3::CheckResult *v6; // rsi
  unsigned int v7; // edi
  int v8; // er15
  unsigned int v9; // ebx
  int v10; // er14
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::ASStringNode *v16; // rcx
  bool v17; // zf
  bool v18; // sf
  unsigned __int8 v19; // of
  unsigned int v20; // ebx
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+0h] [rbp-39h]
  Scaleform::GFx::AS3::Value v23; // [rsp+8h] [rbp-31h]
  Scaleform::GFx::AS3::Value v24; // [rsp+28h] [rbp-11h]
  Scaleform::GFx::ASString v25; // [rsp+48h] [rbp+Fh]
  Scaleform::GFx::ASString v26; // [rsp+50h] [rbp+17h]
  Scaleform::GFx::ASString str; // [rsp+58h] [rbp+1Fh]
  __int64 v28; // [rsp+60h] [rbp+27h]

  v28 = -2i64;
  v4 = r;
  v5 = a2;
  v6 = result;
  v24.Flags = 0;
  v24.Bonus.pWeakProxy = 0i64;
  if ( !Scaleform::GFx::AS3::Value::Convert2PrimitiveValueUnsafeHintNumber(l, &resulta, &v23)->Result )
  {
    v6->Result = 0;
    goto LABEL_55;
  }
  if ( !Scaleform::GFx::AS3::Value::Convert2PrimitiveValueUnsafeHintNumber(v4, &resulta, &v24)->Result )
  {
    v6->Result = 0;
    goto LABEL_48;
  }
  v7 = v23.Flags;
  v8 = v23.Flags & 0x1F;
  v9 = v24.Flags;
  v10 = v24.Flags & 0x1F;
  if ( v8 != 2 )
  {
    if ( v8 == 3 )
    {
      if ( v10 == 3 )
      {
        *v5 = 2 - ((unsigned int)v23.value.VS._1.VInt < v24.value.VS._1.VInt);
        v6->Result = 1;
        goto LABEL_14;
      }
    }
    else if ( v8 == 10 && v10 == 10 && *(_QWORD *)&v23.value.VNumber && *(_QWORD *)&v24.value.VNumber )
    {
      Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v23, &v26);
      v25.pNode = v26.pNode;
      ++v25.pNode->RefCount;
      v13 = v26.pNode;
      v17 = v26.pNode->RefCount == 1;
      --v13->RefCount;
      if ( v17 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v13);
      Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v24, &v26);
      str.pNode = v26.pNode;
      ++str.pNode->RefCount;
      v14 = v26.pNode;
      v17 = v26.pNode->RefCount == 1;
      --v14->RefCount;
      if ( v17 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
      *v5 = 2 - (Scaleform::GFx::ASString::operator<(&v25, &str) != 0);
      v6->Result = 1;
      v15 = str.pNode;
      v17 = str.pNode->RefCount == 1;
      --v15->RefCount;
      if ( v17 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v15);
      v16 = v25.pNode;
      v17 = v25.pNode->RefCount == 1;
      --v16->RefCount;
      if ( v17 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v16);
      goto LABEL_8;
    }
LABEL_37:
    if ( !Scaleform::GFx::AS3::Value::ToNumberValueInline(&v23, &resulta)->Result )
    {
      v6->Result = 0;
      v19 = __OFSUB__(v10, 9);
      v17 = v10 == 9;
      v18 = v10 - 9 < 0;
      goto LABEL_49;
    }
    if ( Scaleform::GFx::AS3::Value::ToNumberValueInline(&v24, &resulta)->Result )
    {
      v25.pNode = v23.value.VS._1.VStr;
      if ( (*(_QWORD *)&v23.value.VNumber & 0x7FF0000000000000i64) == 9218868437227405312i64
        && *(_QWORD *)&v23.value.VNumber & 0xFFFFFFFFFFFFFi64
        || (v25.pNode = v24.value.VS._1.VStr,
            (*(_QWORD *)&v24.value.VNumber & 0x7FF0000000000000i64) == 9218868437227405312i64)
        && *(_QWORD *)&v24.value.VNumber & 0xFFFFFFFFFFFFFi64 )
      {
        *v5 = 0;
      }
      else
      {
        *v5 = (v24.value.VNumber <= v23.value.VNumber) + 1;
      }
      v6->Result = 1;
    }
    else
    {
      v6->Result = 0;
    }
LABEL_48:
    v9 = v24.Flags;
    v19 = __OFSUB__(v24.Flags & 0x1F, 9);
    v17 = (v24.Flags & 0x1F) == 9;
    v18 = (char)((v24.Flags & 0x1F) - 9) < 0;
LABEL_49:
    if ( !((unsigned __int8)(v18 ^ v19) | v17) )
    {
      if ( (v9 >> 9) & 1 )
      {
        v17 = v24.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v17 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v24.Bonus.pWeakProxy = 0i64;
        v24.value = 0ui64;
        v24.Flags = v9 & 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v24);
      }
    }
LABEL_55:
    v20 = v23.Flags;
    if ( (v23.Flags & 0x1F) <= 9 )
      return v6;
    if ( (v23.Flags >> 9) & 1 )
    {
      v17 = v23.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v17 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v23.Bonus.pWeakProxy = 0i64;
      v23.value = 0ui64;
      v23.Flags = v20 & 0xFFFFFDE0;
      return v6;
    }
LABEL_60:
    Scaleform::GFx::AS3::Value::ReleaseInternal(&v23);
    return v6;
  }
  if ( v10 != 2 )
    goto LABEL_37;
  *v5 = (v23.value.VS._1.VInt >= v24.value.VS._1.VInt) + 1;
  v6->Result = 1;
LABEL_8:
  if ( v10 > 9 )
  {
    if ( (v9 >> 9) & 1 )
    {
      v17 = v24.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v17 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v24.Bonus.pWeakProxy = 0i64;
      v24.value = 0ui64;
      v24.Flags = v9 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v24);
    }
  }
LABEL_14:
  if ( v8 <= 9 )
    return v6;
  if ( !((v7 >> 9) & 1) )
    goto LABEL_60;
  v17 = v23.Bonus.pWeakProxy->RefCount-- == 1;
  if ( v17 )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  v23.Bonus.pWeakProxy = 0i64;
  v23.value = 0ui64;
  v23.Flags = v7 & 0xFFFFFDE0;
  return v6;
}

// File Line: 1457
// RVA: 0x8226B0
bool __fastcall Scaleform::GFx::AS3::StrictEqual(Scaleform::GFx::AS3::Value *x, Scaleform::GFx::AS3::Value *y)
{
  Scaleform::GFx::AS3::Value *v2; // r8
  Scaleform::GFx::AS3::Value *v3; // r9
  unsigned int v4; // edx
  int v5; // ecx
  double v6; // xmm0_8
  bool v7; // zf
  bool result; // al
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  int v12; // ecx

  v2 = y;
  v3 = x;
  v4 = x->Flags & 0x1F;
  v5 = v2->Flags & 0x1F;
  if ( v4 == v5 )
    goto LABEL_25;
  if ( v4 - 2 > 2 || (unsigned int)(v5 - 2) > 2 )
    return 0;
  if ( v4 == 3 )
  {
    if ( v5 == 2 )
    {
      v9 = v2->value.VS._1.VInt;
      if ( v9 >= 0 )
        return v3->value.VS._1.VInt == v9;
      return 0;
    }
    if ( v5 == 4 )
    {
      v6 = (double)v3->value.VS._1.VInt;
LABEL_8:
      v7 = v6 == v2->value.VNumber;
      goto LABEL_9;
    }
    goto LABEL_25;
  }
  if ( v4 == 2 )
  {
    v10 = v5 - 3;
    if ( !v10 )
    {
      v11 = v3->value.VS._1.VInt;
      if ( v11 >= 0 )
        return v11 == v2->value.VS._1.VInt;
      return 0;
    }
    if ( v10 == 1 )
    {
      v6 = (double)v3->value.VS._1.VInt;
      goto LABEL_8;
    }
    goto LABEL_25;
  }
  if ( v4 != 4 )
    goto LABEL_25;
  v12 = v5 - 2;
  if ( v12 )
  {
    if ( v12 == 1 )
    {
      v7 = (double)v2->value.VS._1.VInt == v3->value.VNumber;
      goto LABEL_9;
    }
LABEL_25:
    switch ( 0x40000000 )
    {
      case 0:
        return 1;
      case 1:
        return v3->value.VS._1.VBool == v2->value.VS._1.VBool;
      case 2:
      case 3:
        return v3->value.VS._1.VInt == v2->value.VS._1.VInt;
      case 4:
        v7 = v2->value.VNumber == v3->value.VNumber;
        goto LABEL_9;
      case 5:
        return *(_QWORD *)&v3->value.VNumber == *(_QWORD *)&v2->value.VNumber;
      case 7:
        if ( v3->value.VS._1.VInt != v2->value.VS._1.VInt )
          goto LABEL_11;
        v7 = v3->value.VS._2.VObj == v2->value.VS._2.VObj;
        goto LABEL_9;
      case 10:
      case 11:
        return *(_QWORD *)&v3->value.VNumber == *(_QWORD *)&v2->value.VNumber;
      case 12:
      case 13:
      case 14:
      case 15:
        goto $LN11_74;
      case 16:
        if ( v3->value.VS._2.VObj != v2->value.VS._2.VObj )
          return 0;
$LN11_74:
        if ( *(_QWORD *)&v3->value.VNumber != *(_QWORD *)&v2->value.VNumber )
          return 0;
        return 1;
      case 17:
        if ( v3->value.VS._2.VObj != v2->value.VS._2.VObj || v3->value.VS._1.VInt != v2->value.VS._1.VInt )
          return 0;
        return 1;
      default:
        return 0;
    }
    return 0;
  }
  v7 = (double)v2->value.VS._1.VInt == v3->value.VNumber;
LABEL_9:
  if ( v7 )
    result = 1;
  else
LABEL_11:
    result = 0;
  return result;
}

// File Line: 1573
// RVA: 0x7F9060
signed __int64 __fastcall Scaleform::GFx::AS3::IsQNameObject(Scaleform::GFx::AS3::Value *v)
{
  long double v1; // rax
  __int64 v2; // rcx
  signed __int64 result; // rax

  if ( (v->Flags & 0x1F) - 12 > 3 )
    return 0i64;
  v1 = v->value.VNumber;
  if ( v1 == 0.0 )
    return 0i64;
  v2 = *(_QWORD *)(*(_QWORD *)&v1 + 40i64);
  if ( *(_DWORD *)(v2 + 120) != 17 )
    return 0i64;
  result = 0i64;
  if ( ~(*(_BYTE *)(v2 + 112) >> 5) & 1 )
    result = 1i64;
  return result;
}

// File Line: 1619
// RVA: 0x7A9780
Scaleform::GFx::AS3::AbstractEqual

// File Line: 1894
// RVA: 0x7E59E0
Scaleform::GFx::AS3::Value *__fastcall Scaleform::GFx::AS3::GetAbsObject(Scaleform::GFx::AS3::Value *result, unsigned __int64 addr)
{
  int v2; // er8
  long double v3; // rdx
  Scaleform::GFx::AS3::Value::V2U v5; // [rsp+18h] [rbp-10h]

  result->Flags = 0;
  result->Bonus.pWeakProxy = 0i64;
  v2 = addr & 6;
  *(_QWORD *)&v3 = addr - (addr & 6);
  if ( v2 )
  {
    switch ( v2 )
    {
      case 2:
        result->Flags &= 0xFFFFFFED;
        result->Flags |= 0xDu;
        break;
      case 4:
        result->Flags &= 0xFFFFFFEE;
        result->Flags |= 0xEu;
        break;
      case 6:
        result->Flags &= 0xFFFFFFEB;
        result->Flags |= 0xBu;
        break;
      default:
        return result;
    }
  }
  else
  {
    result->Flags &= 0xFFFFFFEC;
    result->Flags |= 0xCu;
  }
  result->value.VNumber = v3;
  result->value.VS._2 = v5;
  if ( v3 != 0.0 )
    *(_DWORD *)(*(_QWORD *)&v3 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v3 + 32i64) + 1) & 0x8FBFFFFF;
  return result;
}

// File Line: 1974
// RVA: 0x7F1160
void __fastcall Scaleform::GFx::AS3::STPtr::GetValueUnsafe(Scaleform::GFx::AS3::STPtr *this, Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::Value *v2; // r8
  Scaleform::GFx::AS3::Instances::fl::Namespace *v3; // rdx
  int v4; // eax
  Scaleform::GFx::AS3::Value::V2U v5; // [rsp+28h] [rbp-10h]

  v2 = v;
  if ( !this->pObject )
  {
LABEL_12:
    Scaleform::GFx::AS3::Value::SetNull(v2);
    return;
  }
  v3 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((_QWORD)this->pObject & 0xFFFFFFFFFFFFFFF8ui64);
  v4 = (_QWORD)this->pObject & 6;
  if ( v4 )
  {
    switch ( v4 )
    {
      case 2:
        v2->Flags &= 0xFFFFFFED;
        v2->Flags |= 0xDu;
        break;
      case 4:
        v2->Flags &= 0xFFFFFFEE;
        v2->Flags |= 0xEu;
        break;
      case 6:
        Scaleform::GFx::AS3::Value::AssignUnsafe(v2, v3);
        return;
      default:
        goto LABEL_12;
    }
  }
  else
  {
    v2->Flags &= 0xFFFFFFEC;
    v2->Flags |= 0xCu;
  }
  *(_QWORD *)&v2->value.VNumber = v3;
  v2->value.VS._2 = v5;
  if ( v3 )
    v3->RefCount = (v3->RefCount + 1) & 0x8FBFFFFF;
}

