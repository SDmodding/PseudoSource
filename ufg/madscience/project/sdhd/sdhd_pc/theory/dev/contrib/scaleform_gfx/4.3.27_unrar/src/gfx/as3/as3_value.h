// File Line: 323
// RVA: 0x784EA0
void __fastcall Scaleform::GFx::AS3::Value::Value(UFG::RoadNetworkLocation *this)
{
  this->m_LaneT = 0.0;
  this->m_CurrentLane = 0i64;
}

// File Line: 427
// RVA: 0x78FAE0
void __fastcall Scaleform::GFx::AS3::Value::~Value(Scaleform::GFx::AS3::Value *p)
{
  unsigned int Flags; // ecx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx

  Flags = p->Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
    {
      pWeakProxy = p->Bonus.pWeakProxy;
      if ( pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      p->Flags &= 0xFFFFFDE0;
      p->Bonus.pWeakProxy = 0i64;
      p->value.VS._1.VStr = 0i64;
      p->value.VS._2.VObj = 0i64;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(p);
    }
  }
}

// File Line: 642
// RVA: 0x790C30
Scaleform::GFx::AS3::Value *__fastcall Scaleform::GFx::AS3::Value::operator=(Scaleform::GFx::AS3::Value *this, bool v)
{
  unsigned int Flags; // ecx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  Scaleform::GFx::AS3::Value::V1U v8; // [rsp+20h] [rbp-18h]
  Scaleform::GFx::AS3::Value::V2U v9; // [rsp+28h] [rbp-10h]

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
  this->Flags &= 0xFFFFFFE1;
  this->Flags |= 1u;
  v8.VBool = v;
  this->value.VS._1 = v8;
  this->value.VS._2 = v9;
  return this;
}

// File Line: 644
// RVA: 0x790B30
Scaleform::GFx::AS3::Value *__fastcall Scaleform::GFx::AS3::Value::operator=(Scaleform::GFx::AS3::Value *this, int v)
{
  unsigned int Flags; // ecx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  Scaleform::GFx::AS3::Value::V1U v8; // [rsp+20h] [rbp-18h]
  Scaleform::GFx::AS3::Value::V2U v9; // [rsp+28h] [rbp-10h]

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
  this->Flags &= 0xFFFFFFE3;
  this->Flags |= 3u;
  v8.VInt = v;
  this->value.VS._1 = v8;
  this->value.VS._2 = v9;
  return this;
}

// File Line: 645
// RVA: 0x790BB0
Scaleform::GFx::AS3::Value *__fastcall Scaleform::GFx::AS3::Value::operator=(
        Scaleform::GFx::AS3::Value *this,
        long double v)
{
  unsigned int Flags; // ecx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  Scaleform::GFx::AS3::Value *result; // rax
  Scaleform::GFx::AS3::Value::V2U v7; // [rsp+28h] [rbp-20h]

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
  this->Flags &= 0xFFFFFFE4;
  this->Flags |= 4u;
  this->value.VNumber = v;
  result = this;
  this->value.VS._2 = v7;
  return result;
}

// File Line: 720
// RVA: 0x81EEC0
void __fastcall Scaleform::GFx::AS3::Value::SetUndefined(Scaleform::GFx::AS3::Value *this)
{
  unsigned int Flags; // ecx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx

  Flags = this->Flags;
  if ( (Flags & 0x1F) <= 9 )
    goto LABEL_7;
  if ( (Flags & 0x200) == 0 )
  {
    Scaleform::GFx::AS3::Value::ReleaseInternal(this);
LABEL_7:
    this->Flags &= 0xFFFFFFE0;
    return;
  }
  pWeakProxy = this->Bonus.pWeakProxy;
  if ( pWeakProxy->RefCount-- == 1 )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  this->Flags &= 0xFFFFFDE0;
  this->Bonus.pWeakProxy = 0i64;
  this->value.VS._1.VStr = 0i64;
  this->value.VS._2.VObj = 0i64;
}

// File Line: 731
// RVA: 0x81AAB0
void __fastcall Scaleform::GFx::AS3::Value::SetNull(Scaleform::GFx::AS3::Value *this)
{
  unsigned int Flags; // ecx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  Scaleform::GFx::AS3::Value::V2U v5; // [rsp+28h] [rbp-10h]

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
  this->Flags &= 0xFFFFFFEC;
  this->Flags |= 0xCu;
  this->value.VS._1.VStr = 0i64;
  this->value.VS._2 = v5;
}

// File Line: 744
// RVA: 0x818500
void __fastcall Scaleform::GFx::AS3::Value::SetBool(Scaleform::GFx::AS3::Value *this, bool v)
{
  unsigned int Flags; // ecx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  Scaleform::GFx::AS3::Value::V1U v7; // [rsp+20h] [rbp-18h]
  Scaleform::GFx::AS3::Value::V2U v8; // [rsp+28h] [rbp-10h]

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
  this->Flags &= 0xFFFFFFE1;
  this->Flags |= 1u;
  v7.VBool = v;
  this->value.VS._1 = v7;
  this->value.VS._2 = v8;
}

// File Line: 757
// RVA: 0x81D4B0
void __fastcall Scaleform::GFx::AS3::Value::SetSInt32(Scaleform::GFx::AS3::Value *this, int v)
{
  unsigned int Flags; // ecx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  Scaleform::GFx::AS3::Value::V1U v7; // [rsp+20h] [rbp-18h]
  Scaleform::GFx::AS3::Value::V2U v8; // [rsp+28h] [rbp-10h]

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
  this->Flags &= 0xFFFFFFE2;
  this->Flags |= 2u;
  v7.VInt = v;
  this->value.VS._1 = v7;
  this->value.VS._2 = v8;
}

// File Line: 785
// RVA: 0x81EE40
void __fastcall Scaleform::GFx::AS3::Value::SetUInt32(Scaleform::GFx::AS3::Value *this, int v)
{
  unsigned int Flags; // ecx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  Scaleform::GFx::AS3::Value::V1U v7; // [rsp+20h] [rbp-18h]
  Scaleform::GFx::AS3::Value::V2U v8; // [rsp+28h] [rbp-10h]

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
  this->Flags &= 0xFFFFFFE3;
  this->Flags |= 3u;
  v7.VInt = v;
  this->value.VS._1 = v7;
  this->value.VS._2 = v8;
}

// File Line: 798
// RVA: 0x81AB30
void __fastcall Scaleform::GFx::AS3::Value::SetNumber(Scaleform::GFx::AS3::Value *this, long double v)
{
  unsigned int Flags; // ecx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  Scaleform::GFx::AS3::Value::V2U v6; // [rsp+28h] [rbp-20h]

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
  this->Flags &= 0xFFFFFFE4;
  this->Flags |= 4u;
  this->value.VNumber = v;
  this->value.VS._2 = v6;
}

// File Line: 859
// RVA: 0x7B1170
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASStringNode *VStr; // rax

  VStr = this->value.VS._1.VStr;
  result->pNode = VStr;
  ++VStr->RefCount;
  return result;
}

// File Line: 1216
// RVA: 0x826460
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Value::ToPrimitiveValue(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::ASStringManager *sm)
{
  Scaleform::GFx::AS3::Value::V1U v6; // rcx
  Scaleform::GFx::AS3::Value::V2U v7; // r8
  bool v8; // r14
  unsigned int Flags; // r8d
  Scaleform::GFx::AS3::Value::Extra v10; // rax
  Scaleform::GFx::AS3::Value::VU value; // kr10_16
  unsigned int v12; // ebx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  Scaleform::GFx::AS3::Value v16; // [rsp+38h] [rbp-28h] BYREF
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+88h] [rbp+28h] BYREF

  if ( (_S11_12 & 1) == 0 )
  {
    _S11_12 |= 1u;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0i64;
    atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  v16.Flags = v.Flags;
  v16.Bonus.pWeakProxy = v.Bonus.pWeakProxy;
  v7.VObj = (Scaleform::GFx::AS3::Object *)v.value.VS._2;
  v6 = v.value.VS._1;
  v16.value = v.value;
  if ( (v.Flags & 0x1F) > 9 )
  {
    if ( (v.Flags & 0x200) != 0 )
    {
      ++v.Bonus.pWeakProxy->RefCount;
    }
    else if ( (v.Flags & 0x1F) == 10 )
    {
      ++v.value.VS._1.VStr->RefCount;
    }
    else if ( (v.Flags & 0x1F) > 0xA )
    {
      if ( (v.Flags & 0x1F) <= 0xF )
      {
        if ( v.value.VS._1.VStr )
        {
          ++v.value.VS._1.VStr->Size;
          v6.VStr->Size &= 0x8FBFFFFF;
        }
      }
      else if ( (v.Flags & 0x1F) <= 0x11 && v.value.VS._2.VObj )
      {
        ++v.value.VS._2.VObj->RefCount;
        v7.VObj->RefCount &= 0x8FBFFFFF;
      }
    }
  }
  v8 = 0;
  if ( Scaleform::GFx::AS3::Value::Convert2PrimitiveValueUnsafe(this, &resulta, sm, &v16, hintNone)->Result )
  {
    Flags = v16.Flags;
    v10.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v16.Bonus;
    value = v16.value;
    v12 = this->Flags;
    v16.Flags = this->Flags;
    pWeakProxy = this->Bonus.pWeakProxy;
    v16.Bonus.pWeakProxy = pWeakProxy;
    v16.value = this->value;
    this->Flags = Flags;
    this->Bonus = v10;
    this->value = value;
    v8 = 1;
  }
  else
  {
    pWeakProxy = v16.Bonus.pWeakProxy;
    v12 = v16.Flags;
  }
  result->Result = v8;
  if ( (v12 & 0x1F) > 9 )
  {
    if ( (v12 & 0x200) != 0 )
    {
      if ( pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v16.Bonus, 0, 24);
      v16.Flags = v12 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v16);
    }
  }
  return result;
}

// File Line: 1254
// RVA: 0x7B9D60
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Value::Convert2NumberInline(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::CheckResult *result,
        long double *a3)
{
  Scaleform::GFx::AS3::CheckResult *v5; // rax
  double v6; // xmm0_8

  switch ( this->Flags & 0x1F )
  {
    case 0u:
      v6 = Scaleform::GFx::NumberUtil::NaN();
LABEL_14:
      *a3 = v6;
      v5 = result;
      result->Result = 1;
      return v5;
    case 1u:
      if ( this->value.VS._1.VBool )
        v6 = DOUBLE_1_0;
      else
        v6 = Scaleform::GFx::NumberUtil::POSITIVE_ZERO();
      goto LABEL_14;
    case 2u:
      v5 = result;
      *a3 = (double)this->value.VS._1.VInt;
      result->Result = 1;
      break;
    case 3u:
      v5 = result;
      *a3 = (double)this->value.VS._1.VInt;
      result->Result = 1;
      break;
    case 4u:
      *a3 = this->value.VNumber;
      result->Result = 1;
      return result;
    default:
      Scaleform::GFx::AS3::Value::Convert2NumberInternal(
        this,
        result,
        a3,
        (Scaleform::GFx::AS3::Value::KindType)(this->Flags & 0x1F));
      return result;
  }
  return v5;
}

// File Line: 1293
// RVA: 0x826400
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Value::ToNumberValueInline(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::CheckResult *result)
{
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+38h] [rbp+10h] BYREF
  long double v; // [rsp+40h] [rbp+18h] BYREF

  result->Result = 1;
  if ( Scaleform::GFx::AS3::Value::Convert2NumberInline(this, &resulta, &v)->Result )
    Scaleform::GFx::AS3::Value::SetNumber(this, v);
  else
    result->Result = 0;
  return result;
}

// File Line: 1408
// RVA: 0x7F83D0
bool __fastcall Scaleform::GFx::AS3::Value::IsCallable(Scaleform::GFx::AS3::Value *this)
{
  return (this->Flags & 0x1F) > 4 && (this->Flags & 0x1F) - 8 > 3;
}

// File Line: 1998
// RVA: 0x7F9700
bool __fastcall Scaleform::GFx::AS3::IsXMLObject(Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::Value::V1U v1; // rax
  const char *pData; // rcx
  bool result; // al

  result = 0;
  if ( (v->Flags & 0x1F) - 12 <= 3 )
  {
    v1 = v->value.VS._1;
    if ( v1.VStr )
    {
      pData = v1.VStr[1].pData;
      if ( *((_DWORD *)pData + 30) == 18 && (pData[112] & 0x20) == 0 )
        return 1;
    }
  }
  return result;
}

// File Line: 2002
// RVA: 0x7F96C0
bool __fastcall Scaleform::GFx::AS3::IsXMLListObject(Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::Value::V1U v1; // rax
  const char *pData; // rcx
  bool result; // al

  result = 0;
  if ( (v->Flags & 0x1F) - 12 <= 3 )
  {
    v1 = v->value.VS._1;
    if ( v1.VStr )
    {
      pData = v1.VStr[1].pData;
      if ( *((_DWORD *)pData + 30) == 19 && (pData[112] & 0x20) == 0 )
        return 1;
    }
  }
  return result;
}

// File Line: 2192
// RVA: 0x7F99A0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::LessThan(
        Scaleform::GFx::AS3::CheckResult *result,
        bool *a2,
        Scaleform::GFx::AS3::Value *l,
        Scaleform::GFx::AS3::Value *r)
{
  bool v6; // r8
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+30h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::Boolean3 v9; // [rsp+38h] [rbp+10h] BYREF

  v9 = undefined3;
  v6 = Scaleform::GFx::AS3::AbstractLessThan(&resulta, &v9, l, r)->Result;
  *a2 = v9 == true3;
  result->Result = v6;
  return result;
}

// File Line: 2205
// RVA: 0x7F1E00
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::GreaterThan(
        Scaleform::GFx::AS3::CheckResult *result,
        bool *a2,
        Scaleform::GFx::AS3::Value *l,
        Scaleform::GFx::AS3::Value *r)
{
  bool v6; // r8
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+30h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::Boolean3 v9; // [rsp+38h] [rbp+10h] BYREF

  v9 = undefined3;
  v6 = Scaleform::GFx::AS3::AbstractLessThan(&resulta, &v9, r, l)->Result;
  *a2 = v9 == true3;
  result->Result = v6;
  return result;
}

// File Line: 2219
// RVA: 0x7F99F0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::LessThanOrEqual(
        Scaleform::GFx::AS3::CheckResult *result,
        bool *a2,
        Scaleform::GFx::AS3::Value *l,
        Scaleform::GFx::AS3::Value *r)
{
  bool v6; // r8
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+30h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::Boolean3 v9; // [rsp+38h] [rbp+10h] BYREF

  v9 = undefined3;
  v6 = Scaleform::GFx::AS3::AbstractLessThan(&resulta, &v9, r, l)->Result;
  *a2 = v9 == false3;
  result->Result = v6;
  return result;
}

// File Line: 2233
// RVA: 0x7F1E50
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::GreaterThanOrEqual(
        Scaleform::GFx::AS3::CheckResult *result,
        bool *a2,
        Scaleform::GFx::AS3::Value *l,
        Scaleform::GFx::AS3::Value *r)
{
  bool v6; // r8
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+30h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::Boolean3 v9; // [rsp+38h] [rbp+10h] BYREF

  v9 = undefined3;
  v6 = Scaleform::GFx::AS3::AbstractLessThan(&resulta, &v9, l, r)->Result;
  *a2 = v9 == false3;
  result->Result = v6;
  return result;
}

