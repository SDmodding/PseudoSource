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
    this->value.VS._1.VStr = 0i64;
    this->value.VS._2 = v2;
  }
  else
  {
    ++this->value.VS._1.VStr->RefCount;
  }
}

// File Line: 78
// RVA: 0x784E20
void __fastcall Scaleform::GFx::AS3::Value::Value(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::ASStringNode *v)
{
  Scaleform::GFx::AS3::Value::V2U v2; // [rsp+8h] [rbp-10h]

  this->Flags = 10;
  this->Bonus.pWeakProxy = 0i64;
  this->value.VS._1.VStr = v;
  if ( !v )
    goto LABEL_4;
  if ( v == &v->pManager->NullStringNode )
  {
    this->value.VS._1.VStr = 0i64;
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
  unsigned int Flags; // ecx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  Scaleform::GFx::AS3::Value::V1U VObj; // rcx

  if ( other != this )
  {
    Flags = this->Flags;
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
      {
        pWeakProxy = this->Bonus.pWeakProxy;
        if ( pWeakProxy->RefCount-- == 1 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        this->Flags &= 0xFFFFFDE0;
        this->Bonus.pWeakProxy = 0i64;
        this->value.VS._1.VStr = 0i64;
        this->value.VS._2.VObj = 0i64;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(this);
      }
    }
    _mm_prefetch((const char *)other, 2);
    *(_QWORD *)&this->Flags = *(_QWORD *)&other->Flags;
    this->Bonus.pWeakProxy = other->Bonus.pWeakProxy;
    this->value.VS._1.VStr = other->value.VS._1.VStr;
    this->value.VS._2.VObj = other->value.VS._2.VObj;
    if ( (this->Flags & 0x1F) > 9 )
    {
      if ( (this->Flags & 0x200) != 0 )
      {
        ++this->Bonus.pWeakProxy->RefCount;
        return;
      }
      if ( (this->Flags & 0x1F) == 10 )
      {
        ++this->value.VS._1.VStr->RefCount;
      }
      else
      {
        if ( (this->Flags & 0x1F) <= 0xA )
          return;
        if ( (this->Flags & 0x1F) <= 0xF )
        {
          VObj = this->value.VS._1;
        }
        else
        {
          if ( (this->Flags & 0x1F) > 0x11 )
            return;
          VObj = (Scaleform::GFx::AS3::Value::V1U)this->value.VS._2.VObj;
        }
        if ( VObj.VStr )
          VObj.VStr->Size = (VObj.VStr->Size + 1) & 0x8FBFFFFF;
      }
    }
  }
}

// File Line: 235
// RVA: 0x7B1A40
void __fastcall Scaleform::GFx::AS3::Value::AssignUnsafe(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::Value *other)
{
  Scaleform::GFx::AS3::Value::V1U VObj; // rdx

  if ( other != this )
  {
    _mm_prefetch((const char *)other, 2);
    *this = *other;
    if ( (this->Flags & 0x1F) > 9 )
    {
      if ( (this->Flags & 0x200) != 0 )
      {
        ++this->Bonus.pWeakProxy->RefCount;
        return;
      }
      if ( (this->Flags & 0x1F) == 10 )
      {
        ++this->value.VS._1.VStr->RefCount;
      }
      else
      {
        if ( (this->Flags & 0x1F) <= 0xA )
          return;
        if ( (this->Flags & 0x1F) <= 0xF )
        {
          VObj = this->value.VS._1;
        }
        else
        {
          if ( (this->Flags & 0x1F) > 0x11 )
            return;
          VObj = (Scaleform::GFx::AS3::Value::V1U)this->value.VS._2.VObj;
        }
        if ( VObj.VStr )
          VObj.VStr->Size = (VObj.VStr->Size + 1) & 0x8FBFFFFF;
      }
    }
  }
}

// File Line: 247
// RVA: 0x7B1620
void __fastcall Scaleform::GFx::AS3::Value::Assign(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::ASString *v)
{
  unsigned int Flags; // ecx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  Scaleform::GFx::AS3::Value::V2U v7; // [rsp+28h] [rbp-10h]

  Flags = this->Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
    {
      pWeakProxy = this->Bonus.pWeakProxy;
      if ( pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      this->Flags &= 0xFFFFFDE0;
      this->Bonus.pWeakProxy = 0i64;
      this->value.VS._1.VStr = 0i64;
      this->value.VS._2.VObj = 0i64;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(this);
    }
  }
  if ( v->pNode == &v->pNode->pManager->NullStringNode )
  {
    this->Flags &= 0xFFFFFFEC;
    this->Flags |= 0xCu;
    this->value.VS._1.VStr = 0i64;
    this->value.VS._2 = v7;
  }
  else
  {
    this->Flags &= 0xFFFFFFEA;
    this->Flags |= 0xAu;
    *(Scaleform::GFx::ASString *)&this->value.VNumber = (Scaleform::GFx::ASString)v->pNode;
    this->value.VS._2 = v7;
    ++this->value.VS._1.VStr->RefCount;
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
    this->value.VS._1.VStr = 0i64;
    this->value.VS._2 = v2;
  }
  else
  {
    this->Flags &= 0xFFFFFFEA;
    this->Flags |= 0xAu;
    *(Scaleform::GFx::ASString *)&this->value.VNumber = (Scaleform::GFx::ASString)v->pNode;
    this->value.VS._2 = v2;
    ++this->value.VS._1.VStr->RefCount;
  }
}

// File Line: 281
// RVA: 0x7B16E0
void __fastcall Scaleform::GFx::AS3::Value::Assign(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::ASStringNode *v)
{
  unsigned int Flags; // ecx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  Scaleform::GFx::AS3::Value::V2U v7; // [rsp+28h] [rbp-10h]

  Flags = this->Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
    {
      pWeakProxy = this->Bonus.pWeakProxy;
      if ( pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      this->Flags &= 0xFFFFFDE0;
      this->Bonus.pWeakProxy = 0i64;
      this->value.VS._1.VStr = 0i64;
      this->value.VS._2.VObj = 0i64;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(this);
    }
  }
  this->value.VS._1.VStr = v;
  this->value.VS._2 = v7;
  if ( !v )
    goto LABEL_10;
  if ( v == &v->pManager->NullStringNode )
  {
    this->value.VS._1.VStr = 0i64;
    this->value.VS._2 = v7;
LABEL_10:
    this->Flags &= 0xFFFFFFEC;
    this->Flags |= 0xCu;
    return;
  }
  this->Flags &= 0xFFFFFFEA;
  this->Flags |= 0xAu;
  ++v->RefCount;
}

// File Line: 306
// RVA: 0x7B1B20
void __fastcall Scaleform::GFx::AS3::Value::AssignUnsafe(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::ASStringNode *v)
{
  Scaleform::GFx::AS3::Value::V2U v2; // [rsp+8h] [rbp-10h]

  this->value.VS._1.VStr = v;
  this->value.VS._2 = v2;
  if ( !v )
    goto LABEL_4;
  if ( v == &v->pManager->NullStringNode )
  {
    this->value.VS._1.VStr = 0i64;
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
  Scaleform::GFx::AS3::Value::V1U v2; // r9
  Scaleform::GFx::AS3::Value::V2U v3; // r10
  unsigned int Flags; // r11d
  Scaleform::GFx::AS3::Value::Extra v5; // rax

  v2 = other->value.VS._1;
  v3.VObj = (Scaleform::GFx::AS3::Object *)other->value.VS._2;
  Flags = other->Flags;
  v5.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)other->Bonus;
  other->Flags = this->Flags;
  other->Bonus.pWeakProxy = this->Bonus.pWeakProxy;
  other->value = this->value;
  this->value.VS._1 = v2;
  this->value.VS._2 = v3;
  this->Flags = Flags;
  this->Bonus = v5;
}

// File Line: 346
// RVA: 0x807060
void __fastcall Scaleform::GFx::AS3::Value::Pick(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::AS3::Value *other)
{
  unsigned int Flags; // ecx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx

  Flags = this->Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
    {
      pWeakProxy = this->Bonus.pWeakProxy;
      if ( pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      this->Flags &= 0xFFFFFDE0;
      this->Bonus.pWeakProxy = 0i64;
      this->value.VS._1.VStr = 0i64;
      this->value.VS._2.VObj = 0i64;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(this);
    }
  }
  _mm_prefetch((const char *)other, 2);
  *(_QWORD *)&this->Flags = *(_QWORD *)&other->Flags;
  this->Bonus.pWeakProxy = other->Bonus.pWeakProxy;
  this->value.VS._1.VStr = other->value.VS._1.VStr;
  this->value.VS._2.VObj = other->value.VS._2.VObj;
  other->Flags = 0;
}

// File Line: 364
// RVA: 0x7F0B80
Scaleform::GFx::AS3::Value *__fastcall Scaleform::GFx::AS3::Value::GetUndefined()
{
  if ( (_S11_12 & 1) == 0 )
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
  if ( (_S12_13 & 1) == 0 )
  {
    _S12_13 |= 1u;
    v_0.Flags = 12;
    v_0.Bonus.pWeakProxy = 0i64;
    v_0.value.VS._1.VStr = 0i64;
    atexit(Scaleform::GFx::AS3::Value::GetNull_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  return &v_0;
}

// File Line: 397
// RVA: 0x7B99F0
__int64 __fastcall Scaleform::GFx::AS3::Value::Convert2Boolean(Scaleform::GFx::AS3::Value *this)
{
  unsigned __int8 v2; // r8
  unsigned int v3; // ecx
  Scaleform::GFx::AS3::Value::V1U v5; // rax
  Scaleform::GFx::AS3::Value::V1U v6; // rax

  v2 = 0;
  v3 = this->Flags & 0x1F;
  switch ( v3 )
  {
    case 0u:
    case 0xBu:
      return 0i64;
    case 1u:
      return this->value.VS._1.VBool;
    case 2u:
    case 3u:
      return this->value.VS._1.VInt != 0;
    case 4u:
      v5 = this->value.VS._1;
      if ( ((__int64)v5.VStr & 0x7FF0000000000000i64) == 0x7FF0000000000000i64
        && ((__int64)v5.VStr & 0xFFFFFFFFFFFFFi64) != 0
        || Scaleform::GFx::NumberUtil::IsPOSITIVE_ZERO(this->value.VNumber) )
      {
        return 0i64;
      }
      return !Scaleform::GFx::NumberUtil::IsNEGATIVE_ZERO(this->value.VNumber);
    case 5u:
    case 7u:
    case 0x10u:
    case 0x11u:
      return 1;
    case 0xAu:
      v6 = this->value.VS._1;
      if ( !v6.VStr )
        return 0i64;
      return v6.VStr->Size != 0;
    case 0xCu:
    case 0xDu:
    case 0xEu:
    case 0xFu:
      return v3 - 12 > 3 && v3 != 10 || this->value.VS._1.VStr;
    default:
      return v2;
  }
}

// File Line: 460
// RVA: 0x7B9D40
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Value::Convert2Number(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::CheckResult *result,
        long double *a3)
{
  Scaleform::GFx::AS3::Value::Convert2NumberInline(this, result, a3);
  return result;
}

// File Line: 465
// RVA: 0x8263A0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Value::ToNumberValue(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::CheckResult *result)
{
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+38h] [rbp+10h] BYREF
  long double v; // [rsp+40h] [rbp+18h] BYREF

  result->Result = 1;
  if ( Scaleform::GFx::AS3::Value::Convert2Number(this, &resulta, &v)->Result )
    Scaleform::GFx::AS3::Value::SetNumber(this, v);
  else
    result->Result = 0;
  return result;
}

// File Line: 478
// RVA: 0x7B9E30
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Value::Convert2NumberInternal(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::CheckResult *result,
        long double *a3,
        Scaleform::GFx::AS3::Value::KindType kind)
{
  Scaleform::GFx::AS3::Value::V1U v7; // rax
  unsigned int Size; // r12d
  const char *pData; // r13
  double v10; // xmm6_8
  unsigned int v11; // edi
  const char *v12; // rsi
  unsigned int v13; // eax
  int ByteIndex; // edi
  unsigned int v15; // edi
  const char *v16; // rsi
  unsigned int v17; // eax
  int v18; // edi
  unsigned int v19; // ecx
  bool v20; // zf
  Scaleform::GFx::AS3::CheckResult v22; // [rsp+20h] [rbp-50h] BYREF
  unsigned int endIndex; // [rsp+24h] [rbp-4Ch] BYREF
  Scaleform::String str; // [rsp+28h] [rbp-48h] BYREF
  Scaleform::String v25; // [rsp+30h] [rbp-40h] BYREF
  __int64 v26; // [rsp+38h] [rbp-38h]
  Scaleform::GFx::AS3::Value v27; // [rsp+40h] [rbp-30h] BYREF
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+B8h] [rbp+48h] BYREF

  v26 = -2i64;
  if ( kind == kString )
  {
    v7 = this->value.VS._1;
    if ( v7.VStr )
    {
      Size = v7.VStr->Size;
      if ( Size )
      {
        pData = v7.VStr->pData;
        v10 = Scaleform::GFx::NumberUtil::StringToDouble(v7.VStr->pData, Size, &endIndex);
        v25.pData = *(Scaleform::String::DataDesc **)&v10;
        if ( ((*(_QWORD *)&v10 & 0x7FF0000000000000i64) != 0x7FF0000000000000i64
           || (*(_QWORD *)&v10 & 0xFFFFFFFFFFFFFi64) == 0)
          && v10 != 0.0 )
        {
          goto LABEL_14;
        }
        if ( endIndex != Size )
        {
          if ( v10 == 0.0 )
          {
            Scaleform::String::String(&str, &pData[endIndex]);
            v11 = Size - endIndex;
            v12 = &pData[endIndex];
            v13 = Scaleform::GFx::ASUtils::SkipWhiteSpace(&str);
            ByteIndex = Scaleform::UTF8Util::GetByteIndex(v13, v12, v11);
            if ( !_InterlockedDecrement((volatile signed __int32 *)((str.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            if ( ByteIndex + endIndex >= Size )
              goto LABEL_12;
          }
          v10 = Scaleform::GFx::NumberUtil::StringToInt(pData, Size, 0, &endIndex);
LABEL_14:
          Scaleform::String::String(&v25, &pData[endIndex]);
          v15 = Size - endIndex;
          v16 = &pData[endIndex];
          v17 = Scaleform::GFx::ASUtils::SkipWhiteSpace(&v25);
          v18 = Scaleform::UTF8Util::GetByteIndex(v17, v16, v15);
          if ( !_InterlockedDecrement((volatile signed __int32 *)((v25.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          if ( v18 + endIndex < Size )
          {
            *a3 = Scaleform::GFx::NumberUtil::NaN();
            goto LABEL_36;
          }
LABEL_12:
          *a3 = v10;
LABEL_36:
          result->Result = 1;
          return result;
        }
      }
    }
LABEL_21:
    *a3 = Scaleform::GFx::NumberUtil::POSITIVE_ZERO();
    goto LABEL_36;
  }
  v19 = this->Flags & 0x1F;
  if ( (v19 - 12 <= 3 || v19 == 10) && !this->value.VS._1.VStr )
    goto LABEL_21;
  v27.Flags = 0;
  v27.Bonus.pWeakProxy = 0i64;
  if ( Scaleform::GFx::AS3::Value::Convert2PrimitiveValueUnsafeHintNumber(this, &resulta, &v27)->Result
    && Scaleform::GFx::AS3::Value::Convert2Number(&v27, &v22, a3)->Result )
  {
    if ( (v27.Flags & 0x1F) > 9 )
    {
      if ( (v27.Flags & 0x200) != 0 )
      {
        v20 = v27.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v20 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&v27.Bonus, 0, 24);
        v27.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v27);
      }
    }
    goto LABEL_36;
  }
  result->Result = 0;
  if ( (v27.Flags & 0x1F) > 9 )
  {
    if ( (v27.Flags & 0x200) != 0 )
    {
      v20 = v27.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v20 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v27.Bonus, 0, 24);
      v27.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v27);
    }
  }
  return result;
}

// File Line: 564
// RVA: 0x7BAD60
// local variable allocation has failed, the output may be wrong!
__int64 __fastcall Scaleform::GFx::AS3::ConvertDouble2SInt32(long double n)
{
  __int128 v1; // xmm6
  int v2; // ecx
  bool v3; // zf
  int v4; // ecx

  v1 = *(_OWORD *)&n;
  if ( (*(_QWORD *)&n & 0x7FF0000000000000i64) == 0x7FF0000000000000i64
    || Scaleform::GFx::NumberUtil::IsNEGATIVE_ZERO(n)
    || Scaleform::GFx::NumberUtil::IsPOSITIVE_ZERO(n) )
  {
    return 0i64;
  }
  if ( n >= 0.0 )
  {
    v2 = (int)n;
    v3 = (double)v2 == n;
  }
  else
  {
    n = -n;
    *(&n + 1) = -*((double *)&v1 + 1);
    v2 = (int)-*(double *)&v1;
    v3 = (double)v2 == n;
  }
  if ( !v3 )
    n = (double)(v2 - (_mm_movemask_pd(_mm_unpacklo_pd(*(__m128d *)&n, *(__m128d *)&n)) & 1));
  if ( n > 4294967295.0 )
    n = fmod(n, 4294967296.0);
  if ( n < 2147483648.0 )
  {
    if ( *(double *)&v1 < 0.0 )
      n = -n;
    return (unsigned int)(int)n;
  }
  else
  {
    v4 = (int)(n - 2147483648.0);
    if ( *(double *)&v1 >= 0.0 )
      return v4 + 0x80000000;
    else
      return 0x80000000 - v4;
  }
}

// File Line: 639
// RVA: 0x7B9B40
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Value::Convert2Int32(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::CheckResult *result,
        int *a3)
{
  __int64 v3; // rbx
  __int64 v4; // rdi
  __int64 v5; // rsi
  unsigned int v8; // edx
  bool v9; // zf
  Scaleform::GFx::AS3::CheckResult v11; // [rsp+20h] [rbp-40h] BYREF
  long double n[2]; // [rsp+28h] [rbp-38h] BYREF
  Scaleform::GFx::AS3::Value v13; // [rsp+38h] [rbp-28h] BYREF
  _BYTE savedregs[24]; // [rsp+60h] [rbp+0h] BYREF
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+80h] [rbp+20h] BYREF
  __int64 v16; // [rsp+88h] [rbp+28h]
  Scaleform::GFx::AS3::CheckResult v17; // [rsp+98h] [rbp+38h] BYREF

  *(_QWORD *)&savedregs[16] = savedregs;
  *(_QWORD *)&savedregs[8] = v5;
  *(_QWORD *)savedregs = v4;
  n[1] = NAN;
  v16 = v3;
  v8 = this->Flags & 0x1F;
  switch ( v8 )
  {
    case 0u:
    case 5u:
    case 0xFu:
      goto $LN14_51;
    case 1u:
      *a3 = this->value.VS._1.VBool;
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
      if ( !this->value.VS._1.VStr )
        goto $LN14_51;
      if ( !Scaleform::GFx::AS3::Value::Convert2Number(this, &resulta, n)->Result )
      {
        result->Result = 0;
        return result;
      }
      *a3 = Scaleform::GFx::AS3::ConvertDouble2SInt32(n[0]);
      goto LABEL_27;
    default:
      if ( (v8 - 12 <= 3 || v8 == 10) && !this->value.VS._1.VStr )
      {
$LN14_51:
        *a3 = 0;
LABEL_27:
        result->Result = 1;
        return result;
      }
      v13.Flags = 0;
      v13.Bonus.pWeakProxy = 0i64;
      if ( Scaleform::GFx::AS3::Value::Convert2PrimitiveValueUnsafeHintNumber(this, &v17, &v13)->Result
        && Scaleform::GFx::AS3::Value::Convert2Int32(&v13, &v11, a3)->Result )
      {
        if ( (v13.Flags & 0x1F) > 9 )
        {
          if ( (v13.Flags & 0x200) != 0 )
          {
            v9 = v13.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v9 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            memset(&v13.Bonus, 0, 24);
            v13.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v13);
          }
        }
        goto LABEL_27;
      }
      result->Result = 0;
      if ( (v13.Flags & 0x1F) > 9 )
      {
        if ( (v13.Flags & 0x200) != 0 )
        {
          v9 = v13.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v9 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&v13.Bonus, 0, 24);
          v13.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v13);
        }
      }
      return result;
  }
}

// File Line: 698
// RVA: 0x7BAA10
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Value::Convert2UInt32(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::CheckResult *result,
        unsigned int *a3)
{
  unsigned int v5; // edx
  bool v6; // zf
  Scaleform::GFx::AS3::CheckResult v8; // [rsp+20h] [rbp-40h] BYREF
  long double n[2]; // [rsp+28h] [rbp-38h] BYREF
  Scaleform::GFx::AS3::Value v10; // [rsp+38h] [rbp-28h] BYREF
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+80h] [rbp+20h] BYREF
  Scaleform::GFx::AS3::CheckResult v12; // [rsp+98h] [rbp+38h] BYREF

  n[1] = NAN;
  v5 = this->Flags & 0x1F;
  switch ( v5 )
  {
    case 0u:
    case 5u:
    case 0xFu:
      goto $LN14_54;
    case 1u:
      *a3 = this->value.VS._1.VBool;
      goto LABEL_27;
    case 2u:
    case 3u:
      *a3 = this->value.VS._1.VUInt;
      goto LABEL_27;
    case 4u:
      *a3 = Scaleform::GFx::AS3::ConvertDouble2SInt32(this->value.VNumber);
      goto LABEL_27;
    case 0xAu:
      if ( !this->value.VS._1.VStr )
        goto $LN14_54;
      if ( !Scaleform::GFx::AS3::Value::Convert2Number(this, &resulta, n)->Result )
      {
        result->Result = 0;
        return result;
      }
      *a3 = Scaleform::GFx::AS3::ConvertDouble2SInt32(n[0]);
      goto LABEL_27;
    default:
      if ( (v5 - 12 <= 3 || v5 == 10) && !this->value.VS._1.VStr )
      {
$LN14_54:
        *a3 = 0;
LABEL_27:
        result->Result = 1;
        return result;
      }
      v10.Flags = 0;
      v10.Bonus.pWeakProxy = 0i64;
      if ( Scaleform::GFx::AS3::Value::Convert2PrimitiveValueUnsafeHintNumber(this, &v12, &v10)->Result
        && Scaleform::GFx::AS3::Value::Convert2UInt32(&v10, &v8, a3)->Result )
      {
        if ( (v10.Flags & 0x1F) > 9 )
        {
          if ( (v10.Flags & 0x200) != 0 )
          {
            v6 = v10.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v6 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            memset(&v10.Bonus, 0, 24);
            v10.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
          }
        }
        goto LABEL_27;
      }
      result->Result = 0;
      if ( (v10.Flags & 0x1F) > 9 )
      {
        if ( (v10.Flags & 0x200) != 0 )
        {
          v6 = v10.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v6 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&v10.Bonus, 0, 24);
          v10.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
        }
      }
      return result;
  }
}

// File Line: 759
// RVA: 0x817010
unsigned __int64 __fastcall Scaleform::GFx::AS3::SF_ECMA_dtostr(char *buffer, int bufflen, long double val)
{
  unsigned __int64 result; // rax
  double v5; // xmm0_8
  int v6; // eax
  int v7; // r11d
  __int64 v8; // rcx
  char v9; // r9
  int v10; // edx
  char *p_dest; // rcx
  int v12; // r8d
  int v13; // ecx
  __int64 v14; // rax
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
  char dest; // [rsp+20h] [rbp-30h] BYREF
  __int64 v29[4]; // [rsp+21h] [rbp-2Fh] BYREF
  int v30; // [rsp+41h] [rbp-Fh]
  __int16 v31; // [rsp+45h] [rbp-Bh]
  char v32; // [rsp+47h] [rbp-9h]
  long double format; // [rsp+70h] [rbp+20h] BYREF

  if ( val == (double)(int)val )
  {
    itoa_s((int)val, buffer, bufflen, 10);
    result = -1i64;
    do
      ++result;
    while ( buffer[result] );
    return result;
  }
  format = val;
  if ( (*(_QWORD *)&val & 0x7FF0000000000000i64) == 0x7FF0000000000000i64 && (*(_QWORD *)&val & 0xFFFFFFFFFFFFFi64) != 0 )
  {
    strcpy(buffer, "NaN");
    return 3i64;
  }
  format = val;
  if ( val == INFINITY )
  {
    strcpy(buffer, "Infinity");
    return 8i64;
  }
  format = val;
  if ( val == -INFINITY )
  {
    strcpy(buffer, "-Infinity");
    return 9i64;
  }
  memset(v29, 0, sizeof(v29));
  *(_QWORD *)&v5 = *(_QWORD *)&val & _xmm;
  v30 = 0;
  v31 = 0;
  v32 = 0;
  dest = 0;
  strcpy((char *)&format, "%.16g");
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
  v6 = Scaleform::SFsprintf(&dest, 0x28ui64, (const char *)&format, val);
  v7 = 0;
  v8 = 0i64;
  if ( v6 <= 0 )
  {
LABEL_22:
    v9 = dest;
    v10 = 0;
    if ( !dest )
      goto LABEL_35;
    p_dest = &dest;
    while ( ((*p_dest - 44) & 0xFD) != 0 )
    {
      ++p_dest;
      ++v10;
      if ( !*p_dest )
        goto LABEL_35;
    }
    if ( *(&v27 + v6) == 48 )
      goto LABEL_35;
    v12 = v6 - 2;
    v13 = v12;
    v14 = v6 - 2;
    if ( v12 > (__int64)v10 )
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
    *((_BYTE *)v29 + v13) = 0;
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
  v16 = buffer;
  v17 = &dest;
  if ( !v9 )
    goto LABEL_65;
  v18 = v9;
  while ( v18 == 44 )
  {
    *v16 = 46;
LABEL_41:
    v18 = *++v17;
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
  *v16++ = v19;
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
    v16 = buffer;
    if ( v9 == 45 )
    {
      v24 = (char *)v29;
      v16 = buffer + 1;
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
  return v16 - buffer;
}     for ( ;

// File Line: 963
// RVA: 0x7BA350
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Value::Convert2String(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::ASString *a3)
{
  Scaleform::GFx::ASStringManager *pManager; // r10
  unsigned int v7; // edx
  unsigned __int64 v8; // r8
  const char *v9; // rdx
  Scaleform::String *v10; // rax
  Scaleform::GFx::ASString *v11; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v13; // zf
  Scaleform::String::DataDesc *pData; // rdx
  Scaleform::String *v15; // rax
  Scaleform::GFx::ASString *v16; // rax
  Scaleform::GFx::ASStringNode *v17; // rcx
  unsigned __int64 v18; // rax
  Scaleform::GFx::ASStringNode *StringNode; // rax
  Scaleform::GFx::AS3::VM *v20; // rbx
  Scaleform::GFx::AS3::VM::Error *v21; // rax
  Scaleform::GFx::ASStringNode *v22; // rcx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // rsi
  Scaleform::GFx::ASStringNode *v24; // rcx
  Scaleform::GFx::AS3::Value v26; // [rsp+30h] [rbp-49h] BYREF
  Scaleform::GFx::ASStringManager *v27; // [rsp+50h] [rbp-29h]
  unsigned int VUInt; // [rsp+58h] [rbp-21h] BYREF
  Scaleform::GFx::ASString v29; // [rsp+60h] [rbp-19h] BYREF
  Scaleform::String v30; // [rsp+68h] [rbp-11h] BYREF
  Scaleform::String resulta; // [rsp+70h] [rbp-9h] BYREF
  Scaleform::GFx::ASString v32; // [rsp+78h] [rbp-1h] BYREF
  __int64 v33; // [rsp+80h] [rbp+7h]
  Scaleform::GFx::AS3::VM::Error v34; // [rsp+88h] [rbp+Fh] BYREF
  char buffer[56]; // [rsp+98h] [rbp+1Fh] BYREF
  Scaleform::GFx::AS3::CheckResult v36; // [rsp+E0h] [rbp+67h] BYREF
  Scaleform::GFx::AS3::CheckResult v37; // [rsp+F0h] [rbp+77h] BYREF
  int v; // [rsp+F8h] [rbp+7Fh] BYREF

  v33 = -2i64;
  pManager = a3->pNode->pManager;
  v27 = pManager;
  v7 = this->Flags & 0x1F;
  switch ( v7 )
  {
    case 0u:
      v8 = 9i64;
      v9 = "undefined";
      goto LABEL_42;
    case 1u:
      v8 = 5i64 - this->value.VS._1.VBool;
      v9 = "false";
      if ( this->value.VS._1.VBool )
        v9 = "true";
      goto LABEL_42;
    case 2u:
      v = this->value.VS._1.VInt;
      v10 = Scaleform::AsString<long>(&resulta, &v);
      v11 = Scaleform::GFx::ASStringManager::CreateString(v27, &v32, v10);
      Scaleform::GFx::ASString::operator=(a3, v11);
      pNode = v32.pNode;
      v13 = v32.pNode->RefCount-- == 1;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      pData = resulta.pData;
      goto LABEL_10;
    case 3u:
      VUInt = this->value.VS._1.VUInt;
      v15 = Scaleform::AsString<unsigned long>(&v30, &VUInt);
      v16 = Scaleform::GFx::ASStringManager::CreateString(v27, &v29, v15);
      Scaleform::GFx::ASString::operator=(a3, v16);
      v17 = v29.pNode;
      v13 = v29.pNode->RefCount-- == 1;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v17);
      pData = v30.pData;
LABEL_10:
      if ( !_InterlockedDecrement((volatile signed __int32 *)(((unsigned __int64)pData & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      goto LABEL_47;
    case 4u:
      v18 = Scaleform::GFx::AS3::SF_ECMA_dtostr(buffer, 40, this->value.VNumber);
      StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(v27, buffer, v18);
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
      p_EmptyStringNode = &pManager->EmptyStringNode;
      ++pManager->EmptyStringNode.RefCount;
      goto LABEL_44;
    case 0xAu:
      p_EmptyStringNode = this->value.VS._1.VStr;
      if ( !p_EmptyStringNode )
        goto LABEL_41;
      ++p_EmptyStringNode->RefCount;
      goto LABEL_44;
    case 0xBu:
      Scaleform::GFx::ASString::operator=(a3, (Scaleform::GFx::ASString *)&this->value.VS._1.VStr[1].16);
      goto LABEL_47;
    case 0xCu:
    case 0xDu:
    case 0xEu:
    case 0xFu:
      if ( (v7 - 12 <= 3 || v7 == 10) && !this->value.VS._1.VStr )
      {
LABEL_41:
        v9 = "null";
        v8 = 4i64;
LABEL_42:
        StringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(pManager, v9, v8, 0);
LABEL_43:
        ++StringNode->RefCount;
        p_EmptyStringNode = StringNode;
LABEL_44:
        v24 = a3->pNode;
        v13 = a3->pNode->RefCount-- == 1;
        if ( v13 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v24);
        a3->pNode = p_EmptyStringNode;
        goto LABEL_47;
      }
      v26.Flags = 0;
      v26.Bonus.pWeakProxy = 0i64;
      if ( Scaleform::GFx::AS3::Value::Convert2PrimitiveValueUnsafe(this, &v36, pManager, &v26, hintString)->Result )
      {
        if ( (v26.Flags & 0x1F) > 4 && (v26.Flags & 0x1F) != 10 )
        {
          v20 = (Scaleform::GFx::AS3::VM *)*((_QWORD *)this->value.VS._1.VStr[1].pData + 16);
          Scaleform::GFx::AS3::VM::Error::Error(&v34, 1050, v20);
          Scaleform::GFx::AS3::VM::ThrowErrorInternal(v20, v21, &Scaleform::GFx::AS3::fl::TypeErrorTI);
          v22 = v34.Message.pNode;
          v13 = v34.Message.pNode->RefCount-- == 1;
          if ( v13 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v22);
          goto LABEL_21;
        }
        if ( Scaleform::GFx::AS3::Value::Convert2String(&v26, &v37, a3)->Result )
        {
          if ( (v26.Flags & 0x1F) > 9 )
          {
            if ( (v26.Flags & 0x200) != 0 )
            {
              v13 = v26.Bonus.pWeakProxy->RefCount-- == 1;
              if ( v13 )
                ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
              memset(&v26.Bonus, 0, 24);
              v26.Flags &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&v26);
            }
          }
LABEL_47:
          result->Result = 1;
          return result;
        }
      }
LABEL_21:
      result->Result = 0;
      if ( (v26.Flags & 0x1F) > 9 )
      {
        if ( (v26.Flags & 0x200) != 0 )
        {
          v13 = v26.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v13 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&v26.Bonus, 0, 24);
          v26.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v26);
        }
      }
      return result;
    default:
      goto LABEL_47;
  }
}

// File Line: 1060
// RVA: 0x7BA700
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Value::Convert2String(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::StringBuffer *a3)
{
  unsigned int v6; // ecx
  const char *v7; // rdx
  Scaleform::String *v8; // rax
  Scaleform::String::DataDesc *pData; // rdx
  Scaleform::String *v10; // rax
  __int64 Size; // r8
  bool v12; // zf
  Scaleform::GFx::AS3::Value::V1U v13; // rdx
  Scaleform::GFx::AS3::Value v15; // [rsp+30h] [rbp-29h] BYREF
  unsigned int VUInt; // [rsp+50h] [rbp-9h] BYREF
  int v; // [rsp+54h] [rbp-5h] BYREF
  Scaleform::String v18; // [rsp+58h] [rbp-1h] BYREF
  Scaleform::String resulta; // [rsp+60h] [rbp+7h] BYREF
  __int64 v20; // [rsp+68h] [rbp+Fh]
  char buffer[64]; // [rsp+70h] [rbp+17h] BYREF
  Scaleform::GFx::AS3::CheckResult v22; // [rsp+C0h] [rbp+67h] BYREF
  Scaleform::GFx::AS3::CheckResult v23; // [rsp+D8h] [rbp+7Fh] BYREF

  v20 = -2i64;
  v6 = this->Flags & 0x1F;
  switch ( v6 )
  {
    case 0u:
      v7 = "undefined";
      goto LABEL_33;
    case 1u:
      v7 = "false";
      if ( this->value.VS._1.VBool )
        v7 = "true";
      goto LABEL_33;
    case 2u:
      v = this->value.VS._1.VInt;
      v8 = Scaleform::AsString<long>(&resulta, &v);
      Scaleform::StringBuffer::AppendString(
        a3,
        (const char *)((v8->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
        *(_QWORD *)(v8->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64);
      pData = resulta.pData;
      goto LABEL_9;
    case 3u:
      VUInt = this->value.VS._1.VUInt;
      v10 = Scaleform::AsString<unsigned long>(&v18, &VUInt);
      Scaleform::StringBuffer::AppendString(
        a3,
        (const char *)((v10->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
        *(_QWORD *)(v10->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64);
      pData = v18.pData;
LABEL_9:
      if ( !_InterlockedDecrement((volatile signed __int32 *)(((unsigned __int64)pData & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      goto LABEL_35;
    case 4u:
      Size = Scaleform::GFx::AS3::SF_ECMA_dtostr(buffer, 40, this->value.VNumber);
      v7 = buffer;
      goto LABEL_34;
    case 5u:
    case 7u:
    case 0x10u:
    case 0x11u:
      v7 = "function Function() {}";
      goto LABEL_33;
    case 0xAu:
      v13 = this->value.VS._1;
      if ( !v13.VStr )
        goto LABEL_32;
      Size = v13.VStr->Size;
      v7 = v13.VStr->pData;
      goto LABEL_34;
    case 0xBu:
      v7 = this->value.VS._1.VStr[1].pLower->$09FB520FFAA77E97CDD800E2BDD737E6::pData;
      goto LABEL_33;
    case 0xCu:
    case 0xDu:
    case 0xEu:
    case 0xFu:
      if ( (v6 - 12 <= 3 || v6 == 10) && !this->value.VS._1.VStr )
      {
LABEL_32:
        v7 = "null";
LABEL_33:
        Size = -1i64;
LABEL_34:
        Scaleform::StringBuffer::AppendString(a3, v7, Size);
        goto LABEL_35;
      }
      v15.Flags = 0;
      v15.Bonus.pWeakProxy = 0i64;
      if ( Scaleform::GFx::AS3::Value::Convert2PrimitiveValueUnsafe(
             this,
             &v22,
             *(Scaleform::GFx::ASStringManager **)(*(_QWORD *)(*((_QWORD *)this->value.VS._1.VStr[1].pData + 16) + 16i64)
                                                 + 512i64),
             &v15,
             hintString)->Result
        && Scaleform::GFx::AS3::Value::Convert2String(&v15, &v23, a3)->Result )
      {
        if ( (v15.Flags & 0x1F) > 9 )
        {
          if ( (v15.Flags & 0x200) != 0 )
          {
            v12 = v15.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v12 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            memset(&v15.Bonus, 0, 24);
            v15.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v15);
          }
        }
LABEL_35:
        result->Result = 1;
        return result;
      }
      result->Result = 0;
      if ( (v15.Flags & 0x1F) > 9 )
      {
        if ( (v15.Flags & 0x200) != 0 )
        {
          v12 = v15.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v12 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&v15.Bonus, 0, 24);
          v15.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v15);
        }
      }
      return result;
    default:
      goto LABEL_35;
  }
}

// File Line: 1168
// RVA: 0x825C20
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Value::ToInt32Value(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::CheckResult *result)
{
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+38h] [rbp+10h] BYREF
  int v; // [rsp+40h] [rbp+18h] BYREF

  if ( Scaleform::GFx::AS3::Value::Convert2Int32(this, &resulta, &v)->Result )
  {
    Scaleform::GFx::AS3::Value::SetSInt32(this, v);
    result->Result = 1;
  }
  else
  {
    result->Result = 0;
  }
  return result;
}

// File Line: 1181
// RVA: 0x826A00
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Value::ToUInt32Value(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::CheckResult *result)
{
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+38h] [rbp+10h] BYREF
  unsigned int v; // [rsp+40h] [rbp+18h] BYREF

  result->Result = 1;
  if ( Scaleform::GFx::AS3::Value::Convert2UInt32(this, &resulta, &v)->Result )
    Scaleform::GFx::AS3::Value::SetUInt32(this, v);
  else
    result->Result = 0;
  return result;
}

// File Line: 1194
// RVA: 0x826980
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Value::ToStringValue(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::StringManager *sm)
{
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::CheckResult v8; // [rsp+48h] [rbp+10h] BYREF
  Scaleform::GFx::ASString resulta; // [rsp+58h] [rbp+20h] BYREF

  result->Result = 1;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(sm, &resulta);
  if ( Scaleform::GFx::AS3::Value::Convert2String(this, &v8, &resulta)->Result )
    Scaleform::GFx::AS3::Value::Assign(this, &resulta);
  else
    result->Result = 0;
  pNode = resulta.pNode;
  if ( resulta.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  return result;
}

// File Line: 1239
// RVA: 0x800A80
char __fastcall Scaleform::GFx::AS3::Value::MakeWeakRef(Scaleform::GFx::AS3::Value *this)
{
  Scaleform::GFx::AS3::GASRefCountBase *VObj; // rcx
  Scaleform::GFx::AS3::WeakProxy *pV; // rcx
  Scaleform::Pickable<Scaleform::GFx::AS3::WeakProxy> result; // [rsp+30h] [rbp+8h] BYREF

  if ( (this->Flags & 0x200) != 0 || (this->Flags & 0x1F) <= 0xA )
    return 0;
  if ( (this->Flags & 0x1F) < 0x10 )
  {
    VObj = this->value.VS._1.VObj;
  }
  else
  {
    if ( (this->Flags & 0x1F) > 0x11 )
      return 0;
    VObj = this->value.VS._2.VObj;
  }
  if ( VObj )
  {
    pV = Scaleform::GFx::AS3::GASRefCountBase::CreateWeakProxy(VObj, &result)->pV;
    this->Flags |= 0x200u;
    this->Bonus.pWeakProxy = pV;
    Scaleform::GFx::AS3::Value::ReleaseInternal(this);
    return 1;
  }
  return 0;
}

// File Line: 1259
// RVA: 0x8006F0
bool __fastcall Scaleform::GFx::AS3::Value::MakeStrongRef(Scaleform::GFx::AS3::Value *this)
{
  unsigned int Flags; // ecx
  int v3; // ecx
  Scaleform::GFx::AS3::Value::V1U VObj; // rcx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  bool result; // al

  Flags = this->Flags;
  if ( (Flags & 0x200) == 0 )
    return 0;
  if ( !this->Bonus.pWeakProxy->pObject )
  {
    result = 1;
    this->value.VS._1.VStr = 0i64;
    this->value.VS._2.VObj = 0i64;
    this->Flags = Flags & 0xFFFFFFE0;
    this->Flags &= ~0x200u;
    this->Bonus.pWeakProxy = 0i64;
    return result;
  }
  v3 = Flags & 0x1F;
  if ( v3 == 10 )
  {
    ++this->value.VS._1.VStr->RefCount;
  }
  else if ( v3 > 10 )
  {
    if ( v3 <= 15 )
    {
      VObj = this->value.VS._1;
LABEL_9:
      if ( VObj.VStr )
        VObj.VStr->Size = (VObj.VStr->Size + 1) & 0x8FBFFFFF;
      goto LABEL_12;
    }
    if ( v3 <= 17 )
    {
      VObj = (Scaleform::GFx::AS3::Value::V1U)this->value.VS._2.VObj;
      goto LABEL_9;
    }
  }
LABEL_12:
  pWeakProxy = this->Bonus.pWeakProxy;
  if ( pWeakProxy->RefCount-- == 1 )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  result = 1;
  this->Flags &= ~0x200u;
  this->Bonus.pWeakProxy = 0i64;
  return result;
}

// File Line: 1289
// RVA: 0x7F96A0
bool __fastcall Scaleform::GFx::AS3::Value::IsValidWeakRef(Scaleform::GFx::AS3::Value *this)
{
  return (this->Flags & 0x200) == 0 || this->Bonus.pWeakProxy->pObject != 0i64;
}

// File Line: 1307
// RVA: 0x790F30
__int64 __fastcall Scaleform::GFx::AS3::Value::HashFunctor::operator()(
        Scaleform::GFx::AS3::Value::HashFunctor *this,
        Scaleform::GFx::AS3::Value *v)
{
  __int64 v2; // r8
  signed int v3; // r10d
  __int64 result; // rax
  __int64 v5; // rcx
  __int64 v6; // r8
  __int64 v7; // rax
  __int64 v8; // rcx
  __int64 v9; // r8
  __int64 v10; // rax
  Scaleform::GFx::AS3::Value::V1U v11; // rax
  __int64 v12; // r8
  __int64 v13; // rcx
  Scaleform::GFx::AS3::Value::V2U v14; // rax
  __int64 v15; // rdx
  __int64 v16; // rax
  __int64 v17; // rcx
  __int64 v18; // rax
  __int64 v19; // r8
  __int64 v20; // rcx
  Scaleform::GFx::AS3::Value::V2U v21; // rax
  __int64 v22; // rdx
  __int64 v23; // rax
  __int64 v24; // rcx
  __int64 v25; // rax
  __int64 v26; // rcx
  __int64 v27; // r8
  __int64 v28; // rax
  __int64 v29; // rcx
  __int64 v30; // r8
  __int64 v31; // rax
  Scaleform::GFx::AS3::Value::V2U v32; // rax
  Scaleform::GFx::AS3::Value::V1U v33; // r9
  __int64 v34; // r8
  __int64 v35; // rcx
  __int64 v36; // rdx
  __int64 v37; // rax
  __int64 v38; // rcx
  __int64 v39; // rax
  char v40; // [rsp+Fh] [rbp+Fh]
  Scaleform::GFx::AS3::Value::V1U VObj; // [rsp+10h] [rbp+10h]
  Scaleform::GFx::AS3::Value::V2U v42; // [rsp+18h] [rbp+18h]

  v2 = 0i64;
  v3 = v->Flags & 0x1F;
  switch ( v3 )
  {
    case 1:
      LOBYTE(v2) = v->value.VS._1.VBool;
      result = v2 + v3;
      break;
    case 2:
    case 3:
      v5 = 4i64;
      v6 = 5381i64;
      VObj.VInt = v->value.VS._1.VInt;
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
      VObj = v->value.VS._1;
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
        v28 = *((unsigned __int8 *)v->value.VS._1.VStr + --v26);
        v27 = v28 + 65599 * v27;
      }
      while ( v26 );
      result = v27 + v3;
      break;
    case 7:
      v12 = 5381i64;
      v13 = 4i64;
      VObj.VInt = v->value.VS._1.VInt;
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
        v18 = *((unsigned __int8 *)&VObj.VFunct + v17-- + 7);
        v12 = v18 + 65599 * v12;
      }
      while ( v17 );
      result = (v15 ^ v12) + v3;
      break;
    case 10:
      v11 = v->value.VS._1;
      if ( !v11.VStr )
        goto LABEL_33;
      result = (v11.VStr->HashFlags & 0xFFFFFF) + (__int64)v3;
      break;
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
      if ( !v->value.VS._1.VStr )
        goto LABEL_33;
      VObj = v->value.VS._1;
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
      v33 = v->value.VS._1;
      v34 = 5381i64;
      v35 = 48i64;
      v36 = 5381i64;
      VObj = (Scaleform::GFx::AS3::Value::V1U)v32.VObj;
      do
      {
        v37 = *((unsigned __int8 *)v33.VStr + --v35);
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
      VObj.VInt = v->value.VS._1.VInt;
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
        v25 = *((unsigned __int8 *)&VObj.VFunct + v24-- + 7);
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
// bad sp value at call has been detected, the output may be wrong!
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::AbstractLessThan(
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Boolean3 *a2,
        Scaleform::GFx::AS3::Value *l,
        Scaleform::GFx::AS3::Value *r)
{
  unsigned int Flags; // edi
  int v8; // r15d
  unsigned int v9; // ebx
  int v10; // r14d
  bool v11; // zf
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::ASStringNode *v15; // rcx
  bool v16; // cc
  unsigned int v17; // ebx
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+0h] [rbp-39h] BYREF
  Scaleform::GFx::AS3::Value v20; // [rsp+8h] [rbp-31h] BYREF
  Scaleform::GFx::AS3::Value v21; // [rsp+28h] [rbp-11h] BYREF
  Scaleform::GFx::ASString v22; // [rsp+48h] [rbp+Fh] BYREF
  Scaleform::GFx::ASString v23; // [rsp+50h] [rbp+17h] BYREF
  Scaleform::GFx::ASString str; // [rsp+58h] [rbp+1Fh] BYREF
  __int64 v25; // [rsp+60h] [rbp+27h]

  v25 = -2i64;
  v21.Flags = 0;
  v21.Bonus.pWeakProxy = 0i64;
  if ( !Scaleform::GFx::AS3::Value::Convert2PrimitiveValueUnsafeHintNumber(l, &resulta, &v20)->Result )
  {
    result->Result = 0;
    goto LABEL_52;
  }
  if ( !Scaleform::GFx::AS3::Value::Convert2PrimitiveValueUnsafeHintNumber(r, &resulta, &v21)->Result )
  {
    result->Result = 0;
    goto LABEL_45;
  }
  Flags = v20.Flags;
  v8 = v20.Flags & 0x1F;
  v9 = v21.Flags;
  v10 = v21.Flags & 0x1F;
  if ( v8 != 2 )
  {
    if ( v8 == 3 )
    {
      if ( v10 == 3 )
      {
        *a2 = 2 - (v20.value.VS._1.VInt < (unsigned int)v21.value.VS._1.VInt);
        result->Result = 1;
        goto LABEL_14;
      }
    }
    else if ( v8 == 10 && v10 == 10 && v20.value.VS._1.VStr && v21.value.VS._1.VStr )
    {
      Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v20, &v23);
      v22.pNode = v23.pNode;
      ++v23.pNode->RefCount;
      pNode = v23.pNode;
      v11 = v23.pNode->RefCount-- == 1;
      if ( v11 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v21, &v23);
      str.pNode = v23.pNode;
      ++v23.pNode->RefCount;
      v13 = v23.pNode;
      v11 = v23.pNode->RefCount-- == 1;
      if ( v11 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v13);
      *a2 = 2 - Scaleform::GFx::ASString::operator<(&v22, &str);
      result->Result = 1;
      v14 = str.pNode;
      v11 = str.pNode->RefCount-- == 1;
      if ( v11 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
      v15 = v22.pNode;
      v11 = v22.pNode->RefCount-- == 1;
      if ( v11 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v15);
      goto LABEL_8;
    }
LABEL_34:
    if ( !Scaleform::GFx::AS3::Value::ToNumberValueInline(&v20, &resulta)->Result )
    {
      result->Result = 0;
      v16 = v10 <= 9;
      goto LABEL_46;
    }
    if ( Scaleform::GFx::AS3::Value::ToNumberValueInline(&v21, &resulta)->Result )
    {
      v22.pNode = v20.value.VS._1.VStr;
      if ( ((__int64)v20.value.VS._1.VStr & 0x7FF0000000000000i64) == 0x7FF0000000000000i64
        && ((__int64)v20.value.VS._1.VStr & 0xFFFFFFFFFFFFFi64) != 0
        || (v22.pNode = v21.value.VS._1.VStr,
            ((__int64)v21.value.VS._1.VStr & 0x7FF0000000000000i64) == 0x7FF0000000000000i64)
        && ((__int64)v21.value.VS._1.VStr & 0xFFFFFFFFFFFFFi64) != 0 )
      {
        *a2 = undefined3;
      }
      else
      {
        *a2 = (v21.value.VNumber <= v20.value.VNumber) + 1;
      }
      result->Result = 1;
    }
    else
    {
      result->Result = 0;
    }
LABEL_45:
    v9 = v21.Flags;
    v16 = (v21.Flags & 0x1F) <= 9;
LABEL_46:
    if ( !v16 )
    {
      if ( (v9 & 0x200) != 0 )
      {
        v11 = v21.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v11 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&v21.Bonus, 0, 24);
        v21.Flags = v9 & 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v21);
      }
    }
LABEL_52:
    v17 = v20.Flags;
    if ( (v20.Flags & 0x1F) <= 9 )
      return result;
    if ( (v20.Flags & 0x200) != 0 )
    {
      v11 = v20.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v11 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v20.Bonus, 0, 24);
      v20.Flags = v17 & 0xFFFFFDE0;
      return result;
    }
LABEL_57:
    Scaleform::GFx::AS3::Value::ReleaseInternal(&v20);
    return result;
  }
  if ( v10 != 2 )
    goto LABEL_34;
  *a2 = (v20.value.VS._1.VInt >= v21.value.VS._1.VInt) + 1;
  result->Result = 1;
LABEL_8:
  if ( v10 > 9 )
  {
    if ( (v9 & 0x200) != 0 )
    {
      v11 = v21.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v11 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v21.Bonus, 0, 24);
      v21.Flags = v9 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v21);
    }
  }
LABEL_14:
  if ( v8 <= 9 )
    return result;
  if ( (Flags & 0x200) == 0 )
    goto LABEL_57;
  v11 = v20.Bonus.pWeakProxy->RefCount-- == 1;
  if ( v11 )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  memset(&v20.Bonus, 0, 24);
  v20.Flags = Flags & 0xFFFFFDE0;
  return result;
}

// File Line: 1457
// RVA: 0x8226B0
bool __fastcall Scaleform::GFx::AS3::StrictEqual(Scaleform::GFx::AS3::Value *x, Scaleform::GFx::AS3::Value *y)
{
  unsigned int v4; // edx
  unsigned int v5; // ecx
  double VInt; // xmm0_8
  bool result; // al
  int v9; // eax
  unsigned int v10; // ecx
  int v11; // eax
  unsigned int v12; // ecx

  v4 = x->Flags & 0x1F;
  v5 = y->Flags & 0x1F;
  if ( v4 == v5 )
    goto LABEL_25;
  if ( v4 - 2 > 2 || v5 - 2 > 2 )
    return 0;
  if ( v4 == 3 )
  {
    if ( v5 != 2 )
    {
      if ( v5 == 4 )
      {
        VInt = (double)x->value.VS._1.VInt;
        return VInt == y->value.VNumber;
      }
      goto LABEL_25;
    }
    v9 = y->value.VS._1.VInt;
    if ( v9 >= 0 )
      return x->value.VS._1.VInt == v9;
    return 0;
  }
  if ( v4 != 2 )
  {
    if ( v4 != 4 )
      goto LABEL_25;
    v12 = v5 - 2;
    if ( v12 )
    {
      if ( v12 != 1 )
        goto LABEL_25;
      return (double)y->value.VS._1.VInt == x->value.VNumber;
    }
    else
    {
      return (double)y->value.VS._1.VInt == x->value.VNumber;
    }
  }
  v10 = v5 - 3;
  if ( !v10 )
  {
    v11 = x->value.VS._1.VInt;
    if ( v11 >= 0 )
      return v11 == y->value.VS._1.VInt;
    return 0;
  }
  if ( v10 == 1 )
  {
    VInt = (double)x->value.VS._1.VInt;
    return VInt == y->value.VNumber;
  }
LABEL_25:
  switch ( v4 )
  {
    case 0u:
      return 1;
    case 1u:
      return x->value.VS._1.VBool == y->value.VS._1.VBool;
    case 2u:
    case 3u:
      return x->value.VS._1.VInt == y->value.VS._1.VInt;
    case 4u:
      return y->value.VNumber == x->value.VNumber;
    case 5u:
      return x->value.VS._1.VStr == y->value.VS._1.VStr;
    case 7u:
      if ( x->value.VS._1.VInt != y->value.VS._1.VInt )
        return 0;
      return x->value.VS._2.VObj == y->value.VS._2.VObj;
    case 0xAu:
    case 0xBu:
      return x->value.VS._1.VStr == y->value.VS._1.VStr;
    case 0xCu:
    case 0xDu:
    case 0xEu:
    case 0xFu:
      goto $LN11_74;
    case 0x10u:
      if ( x->value.VS._2.VObj != y->value.VS._2.VObj )
        return 0;
$LN11_74:
      if ( x->value.VS._1.VStr != y->value.VS._1.VStr )
        return 0;
      result = 1;
      break;
    case 0x11u:
      return x->value.VS._2.VObj == y->value.VS._2.VObj && x->value.VS._1.VInt == y->value.VS._1.VInt;
    default:
      return 0;
  }
  return result;
}

// File Line: 1573
// RVA: 0x7F9060
_BOOL8 __fastcall Scaleform::GFx::AS3::IsQNameObject(Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::Value::V1U v1; // rax
  const char *pData; // rcx

  if ( (v->Flags & 0x1F) - 12 <= 3
    && (v1 = v->value.VS._1, v1.VStr)
    && (pData = v1.VStr[1].pData, *((_DWORD *)pData + 30) == 17) )
  {
    return (pData[112] & 0x20) == 0;
  }
  else
  {
    return 0i64;
  }
}

// File Line: 1619
// RVA: 0x7A9780
Scaleform::GFx::AS3::AbstractEqual

// File Line: 1894
// RVA: 0x7E59E0
Scaleform::GFx::AS3::Value *__fastcall Scaleform::GFx::AS3::GetAbsObject(
        Scaleform::GFx::AS3::Value *result,
        unsigned __int64 addr)
{
  int v2; // r8d
  Scaleform::GFx::AS3::Value::V1U v3; // rdx
  Scaleform::GFx::AS3::Value::V2U v5; // [rsp+18h] [rbp-10h]

  result->Flags = 0;
  result->Bonus.pWeakProxy = 0i64;
  v2 = addr & 6;
  v3.VStr = (Scaleform::GFx::ASStringNode *)(addr - (addr & 6));
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
  result->value.VS._1 = v3;
  result->value.VS._2 = v5;
  if ( v3.VStr )
    v3.VStr->Size = (v3.VStr->Size + 1) & 0x8FBFFFFF;
  return result;
}

// File Line: 1974
// RVA: 0x7F1160
void __fastcall Scaleform::GFx::AS3::STPtr::GetValueUnsafe(
        Scaleform::GFx::AS3::STPtr *this,
        Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::Instances::fl::Namespace *v3; // rdx
  int v4; // eax
  Scaleform::GFx::AS3::Value::V2U v5; // [rsp+28h] [rbp-10h]

  if ( !this->pObject )
  {
LABEL_12:
    Scaleform::GFx::AS3::Value::SetNull(v);
    return;
  }
  v3 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((unsigned __int64)this->pObject & 0xFFFFFFFFFFFFFFF8ui64);
  v4 = (__int64)this->pObject & 6;
  if ( v4 )
  {
    switch ( v4 )
    {
      case 2:
        v->Flags &= 0xFFFFFFED;
        v->Flags |= 0xDu;
        break;
      case 4:
        v->Flags &= 0xFFFFFFEE;
        v->Flags |= 0xEu;
        break;
      case 6:
        Scaleform::GFx::AS3::Value::AssignUnsafe(v, v3);
        return;
      default:
        goto LABEL_12;
    }
  }
  else
  {
    v->Flags &= 0xFFFFFFEC;
    v->Flags |= 0xCu;
  }
  v->value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)v3;
  v->value.VS._2 = v5;
  if ( v3 )
    v3->RefCount = (v3->RefCount + 1) & 0x8FBFFFFF;
}

