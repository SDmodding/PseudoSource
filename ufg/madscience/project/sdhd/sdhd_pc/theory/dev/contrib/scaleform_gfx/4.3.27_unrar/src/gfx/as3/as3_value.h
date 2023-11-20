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
  Scaleform::GFx::AS3::Value *v1; // rbx
  unsigned int v2; // ecx
  Scaleform::GFx::AS3::WeakProxy *v3; // rdx
  bool v4; // zf

  v1 = p;
  v2 = p->Flags;
  if ( (char)(v2 & 0x1F) > 9 )
  {
    if ( (v2 >> 9) & 1 )
    {
      v3 = v1->Bonus.pWeakProxy;
      v4 = v3->RefCount-- == 1;
      if ( v4 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v1->Flags &= 0xFFFFFDE0;
      v1->Bonus.pWeakProxy = 0i64;
      v1->value.VNumber = 0.0;
      v1->value.VS._2.VObj = 0i64;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(v1);
    }
  }
}

// File Line: 642
// RVA: 0x790C30
Scaleform::GFx::AS3::Value *__fastcall Scaleform::GFx::AS3::Value::operator=(Scaleform::GFx::AS3::Value *this, bool v)
{
  Scaleform::GFx::AS3::Value *v2; // rbx
  unsigned int v3; // ecx
  bool v4; // di
  Scaleform::GFx::AS3::WeakProxy *v5; // rdx
  bool v6; // zf
  long double v8; // [rsp+20h] [rbp-18h]
  Scaleform::GFx::AS3::Value::V2U v9; // [rsp+28h] [rbp-10h]

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
  v2->Flags &= 0xFFFFFFE1;
  v2->Flags |= 1u;
  LOBYTE(v8) = v4;
  v2->value.VNumber = v8;
  v2->value.VS._2 = v9;
  return v2;
}

// File Line: 644
// RVA: 0x790B30
Scaleform::GFx::AS3::Value *__fastcall Scaleform::GFx::AS3::Value::operator=(Scaleform::GFx::AS3::Value *this, unsigned int v)
{
  Scaleform::GFx::AS3::Value *v2; // rbx
  unsigned int v3; // ecx
  unsigned int v4; // edi
  Scaleform::GFx::AS3::WeakProxy *v5; // rdx
  bool v6; // zf
  long double v8; // [rsp+20h] [rbp-18h]
  Scaleform::GFx::AS3::Value::V2U v9; // [rsp+28h] [rbp-10h]

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
  v2->Flags &= 0xFFFFFFE3;
  v2->Flags |= 3u;
  LODWORD(v8) = v4;
  v2->value.VNumber = v8;
  v2->value.VS._2 = v9;
  return v2;
}

// File Line: 645
// RVA: 0x790BB0
Scaleform::GFx::AS3::Value *__fastcall Scaleform::GFx::AS3::Value::operator=(Scaleform::GFx::AS3::Value *this, long double v)
{
  Scaleform::GFx::AS3::Value *v2; // rbx
  unsigned int v3; // ecx
  Scaleform::GFx::AS3::WeakProxy *v4; // rdx
  bool v5; // zf
  Scaleform::GFx::AS3::Value *result; // rax
  Scaleform::GFx::AS3::Value::V2U v7; // [rsp+28h] [rbp-20h]

  v2 = this;
  v3 = this->Flags;
  if ( (char)(v3 & 0x1F) > 9 )
  {
    if ( (v3 >> 9) & 1 )
    {
      v4 = v2->Bonus.pWeakProxy;
      v5 = v4->RefCount-- == 1;
      if ( v5 )
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
  v2->Flags &= 0xFFFFFFE4;
  v2->Flags |= 4u;
  v2->value.VNumber = v;
  result = v2;
  v2->value.VS._2 = v7;
  return result;
}

// File Line: 720
// RVA: 0x81EEC0
void __fastcall Scaleform::GFx::AS3::Value::SetUndefined(Scaleform::GFx::AS3::Value *this)
{
  Scaleform::GFx::AS3::Value *v1; // rbx
  unsigned int v2; // ecx
  Scaleform::GFx::AS3::WeakProxy *v3; // rdx
  bool v4; // zf

  v1 = this;
  v2 = this->Flags;
  if ( (char)(v2 & 0x1F) <= 9 )
    goto LABEL_7;
  if ( !((v2 >> 9) & 1) )
  {
    Scaleform::GFx::AS3::Value::ReleaseInternal(v1);
LABEL_7:
    v1->Flags &= 0xFFFFFFE0;
    return;
  }
  v3 = v1->Bonus.pWeakProxy;
  v4 = v3->RefCount-- == 1;
  if ( v4 )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  v1->Flags &= 0xFFFFFDE0;
  v1->Bonus.pWeakProxy = 0i64;
  v1->value.VNumber = 0.0;
  v1->value.VS._2.VObj = 0i64;
}

// File Line: 731
// RVA: 0x81AAB0
void __fastcall Scaleform::GFx::AS3::Value::SetNull(Scaleform::GFx::AS3::Value *this)
{
  Scaleform::GFx::AS3::Value *v1; // rbx
  unsigned int v2; // ecx
  Scaleform::GFx::AS3::WeakProxy *v3; // rdx
  bool v4; // zf
  Scaleform::GFx::AS3::Value::V2U v5; // [rsp+28h] [rbp-10h]

  v1 = this;
  v2 = this->Flags;
  if ( (char)(v2 & 0x1F) > 9 )
  {
    if ( (v2 >> 9) & 1 )
    {
      v3 = v1->Bonus.pWeakProxy;
      v4 = v3->RefCount-- == 1;
      if ( v4 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v1->Flags &= 0xFFFFFDE0;
      v1->Bonus.pWeakProxy = 0i64;
      v1->value.VNumber = 0.0;
      v1->value.VS._2.VObj = 0i64;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(v1);
    }
  }
  v1->Flags &= 0xFFFFFFEC;
  v1->Flags |= 0xCu;
  v1->value.VNumber = 0.0;
  v1->value.VS._2 = v5;
}

// File Line: 744
// RVA: 0x818500
void __fastcall Scaleform::GFx::AS3::Value::SetBool(Scaleform::GFx::AS3::Value *this, bool v)
{
  Scaleform::GFx::AS3::Value *v2; // rbx
  unsigned int v3; // ecx
  bool v4; // di
  Scaleform::GFx::AS3::WeakProxy *v5; // rdx
  bool v6; // zf
  long double v7; // [rsp+20h] [rbp-18h]
  Scaleform::GFx::AS3::Value::V2U v8; // [rsp+28h] [rbp-10h]

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
  v2->Flags &= 0xFFFFFFE1;
  v2->Flags |= 1u;
  LOBYTE(v7) = v4;
  v2->value.VNumber = v7;
  v2->value.VS._2 = v8;
}

// File Line: 757
// RVA: 0x81D4B0
void __fastcall Scaleform::GFx::AS3::Value::SetSInt32(Scaleform::GFx::AS3::Value *this, int v)
{
  Scaleform::GFx::AS3::Value *v2; // rbx
  unsigned int v3; // ecx
  int v4; // edi
  Scaleform::GFx::AS3::WeakProxy *v5; // rdx
  bool v6; // zf
  long double v7; // [rsp+20h] [rbp-18h]
  Scaleform::GFx::AS3::Value::V2U v8; // [rsp+28h] [rbp-10h]

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
  v2->Flags &= 0xFFFFFFE2;
  v2->Flags |= 2u;
  LODWORD(v7) = v4;
  v2->value.VNumber = v7;
  v2->value.VS._2 = v8;
}

// File Line: 785
// RVA: 0x81EE40
void __fastcall Scaleform::GFx::AS3::Value::SetUInt32(Scaleform::GFx::AS3::Value *this, unsigned int v)
{
  Scaleform::GFx::AS3::Value *v2; // rbx
  unsigned int v3; // ecx
  unsigned int v4; // edi
  Scaleform::GFx::AS3::WeakProxy *v5; // rdx
  bool v6; // zf
  long double v7; // [rsp+20h] [rbp-18h]
  Scaleform::GFx::AS3::Value::V2U v8; // [rsp+28h] [rbp-10h]

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
  v2->Flags &= 0xFFFFFFE3;
  v2->Flags |= 3u;
  LODWORD(v7) = v4;
  v2->value.VNumber = v7;
  v2->value.VS._2 = v8;
}

// File Line: 798
// RVA: 0x81AB30
void __fastcall Scaleform::GFx::AS3::Value::SetNumber(Scaleform::GFx::AS3::Value *this, long double v)
{
  Scaleform::GFx::AS3::Value *v2; // rbx
  unsigned int v3; // ecx
  Scaleform::GFx::AS3::WeakProxy *v4; // rdx
  bool v5; // zf
  Scaleform::GFx::AS3::Value::V2U v6; // [rsp+28h] [rbp-20h]

  v2 = this;
  v3 = this->Flags;
  if ( (char)(v3 & 0x1F) > 9 )
  {
    if ( (v3 >> 9) & 1 )
    {
      v4 = v2->Bonus.pWeakProxy;
      v5 = v4->RefCount-- == 1;
      if ( v5 )
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
  v2->Flags &= 0xFFFFFFE4;
  v2->Flags |= 4u;
  v2->value.VNumber = v;
  v2->value.VS._2 = v6;
}

// File Line: 859
// RVA: 0x7B1170
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASStringNode *v2; // rax

  v2 = this->value.VS._1.VStr;
  result->pNode = v2;
  ++v2->RefCount;
  return result;
}

// File Line: 1216
// RVA: 0x826460
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Value::ToPrimitiveValue(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::ASStringManager *sm)
{
  Scaleform::GFx::ASStringManager *v3; // rbx
  Scaleform::GFx::AS3::CheckResult *v4; // rdi
  Scaleform::GFx::AS3::Value *v5; // rsi
  __int64 v6; // rcx
  __int64 v7; // r8
  Scaleform::GFx::AS3::Value::VU v8; // kr00_16
  int v9; // edx
  char v10; // r14
  unsigned int v11; // er8
  Scaleform::GFx::AS3::Value::Extra v12; // rax
  Scaleform::GFx::AS3::Value::VU v13; // kr10_16
  unsigned int v14; // ebx
  Scaleform::GFx::AS3::WeakProxy *v15; // rdx
  bool v16; // zf
  Scaleform::GFx::AS3::Value v18; // [rsp+38h] [rbp-28h]
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+88h] [rbp+28h]

  v3 = sm;
  v4 = result;
  v5 = this;
  if ( !(_S11_12 & 1) )
  {
    _S11_12 |= 1u;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0i64;
    atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  v18.Flags = v.Flags;
  v18.Bonus.pWeakProxy = v.Bonus.pWeakProxy;
  v8 = v.value;
  v7 = *(_OWORD *)&v8 >> 64;
  v6 = (unsigned __int128)v8;
  v18.value = v.value;
  v9 = v.Flags & 0x1F;
  if ( v9 > 9 )
  {
    if ( (v.Flags >> 9) & 1 )
    {
      ++v.Bonus.pWeakProxy->RefCount;
    }
    else if ( v9 == 10 )
    {
      ++*(_DWORD *)(*(_QWORD *)&v.value.VNumber + 24i64);
    }
    else if ( v9 > 10 )
    {
      if ( v9 <= 15 )
      {
        if ( *(_QWORD *)&v.value.VNumber )
        {
          ++*(_DWORD *)(*(_QWORD *)&v.value.VNumber + 32i64);
          *(_DWORD *)(v6 + 32) &= 0x8FBFFFFF;
        }
      }
      else if ( v9 <= 17 && v.value.VS._2.VObj )
      {
        ++v.value.VS._2.VObj->RefCount;
        *(_DWORD *)(v7 + 32) &= 0x8FBFFFFF;
      }
    }
  }
  v10 = 0;
  if ( Scaleform::GFx::AS3::Value::Convert2PrimitiveValueUnsafe(v5, &resulta, v3, &v18, 0)->Result )
  {
    v11 = v18.Flags;
    v12.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v18.Bonus;
    v13 = v18.value;
    v14 = v5->Flags;
    v18.Flags = v5->Flags;
    v15 = v5->Bonus.pWeakProxy;
    v18.Bonus.pWeakProxy = v5->Bonus.pWeakProxy;
    v18.value = v5->value;
    v5->Flags = v11;
    v5->Bonus = v12;
    v5->value = v13;
    v10 = 1;
  }
  else
  {
    v15 = v18.Bonus.pWeakProxy;
    v14 = v18.Flags;
  }
  v4->Result = v10;
  if ( (char)(v14 & 0x1F) > 9 )
  {
    if ( (v14 >> 9) & 1 )
    {
      v16 = v15->RefCount-- == 1;
      if ( v16 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v18.Bonus.pWeakProxy = 0i64;
      v18.value = 0ui64;
      v18.Flags = v14 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v18);
    }
  }
  return v4;
}

// File Line: 1254
// RVA: 0x7B9D60
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Value::Convert2NumberInline(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::AS3::CheckResult *result, long double *a3)
{
  long double *v3; // rbx
  Scaleform::GFx::AS3::CheckResult *v4; // rdi
  Scaleform::GFx::AS3::CheckResult *v5; // rax
  double v6; // xmm0_8

  v3 = a3;
  v4 = result;
  switch ( this->Flags & 0x1F )
  {
    case 0u:
      v6 = Scaleform::GFx::NumberUtil::NaN();
LABEL_14:
      *v3 = v6;
      v5 = v4;
      v4->Result = 1;
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
      v5 = result;
      break;
    default:
      Scaleform::GFx::AS3::Value::Convert2NumberInternal(
        this,
        result,
        a3,
        (Scaleform::GFx::AS3::Value::KindType)(this->Flags & 0x1F));
      v5 = v4;
      break;
  }
  return v5;
}

// File Line: 1293
// RVA: 0x826400
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Value::ToNumberValueInline(Scaleform::GFx::AS3::Value *this, Scaleform::GFx::AS3::CheckResult *result)
{
  Scaleform::GFx::AS3::CheckResult *v2; // rbx
  Scaleform::GFx::AS3::Value *v3; // rdi
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+38h] [rbp+10h]
  long double v; // [rsp+40h] [rbp+18h]

  v2 = result;
  result->Result = 1;
  v3 = this;
  if ( Scaleform::GFx::AS3::Value::Convert2NumberInline(this, &resulta, &v)->Result )
    Scaleform::GFx::AS3::Value::SetNumber(v3, v);
  else
    v2->Result = 0;
  return v2;
}

// File Line: 1408
// RVA: 0x7F83D0
bool __fastcall Scaleform::GFx::AS3::Value::IsCallable(Scaleform::GFx::AS3::Value *this)
{
  signed int v1; // eax

  v1 = this->Flags & 0x1F;
  return v1 > 4 && (unsigned int)(v1 - 8) > 3;
}

// File Line: 1998
// RVA: 0x7F9700
bool __fastcall Scaleform::GFx::AS3::IsXMLObject(Scaleform::GFx::AS3::Value *v)
{
  long double v1; // rax
  __int64 v2; // rcx
  bool result; // al

  result = 0;
  if ( (v->Flags & 0x1F) - 12 <= 3 )
  {
    v1 = v->value.VNumber;
    if ( v1 != 0.0 )
    {
      v2 = *(_QWORD *)(*(_QWORD *)&v1 + 40i64);
      if ( *(_DWORD *)(v2 + 120) == 18 )
      {
        if ( ~(*(_BYTE *)(v2 + 112) >> 5) & 1 )
          result = 1;
      }
    }
  }
  return result;
}

// File Line: 2002
// RVA: 0x7F96C0
bool __fastcall Scaleform::GFx::AS3::IsXMLListObject(Scaleform::GFx::AS3::Value *v)
{
  long double v1; // rax
  __int64 v2; // rcx
  bool result; // al

  result = 0;
  if ( (v->Flags & 0x1F) - 12 <= 3 )
  {
    v1 = v->value.VNumber;
    if ( v1 != 0.0 )
    {
      v2 = *(_QWORD *)(*(_QWORD *)&v1 + 40i64);
      if ( *(_DWORD *)(v2 + 120) == 19 )
      {
        if ( ~(*(_BYTE *)(v2 + 112) >> 5) & 1 )
          result = 1;
      }
    }
  }
  return result;
}

// File Line: 2192
// RVA: 0x7F99A0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::LessThan(Scaleform::GFx::AS3::CheckResult *result, bool *a2, Scaleform::GFx::AS3::Value *l, Scaleform::GFx::AS3::Value *r)
{
  bool *v4; // rbx
  Scaleform::GFx::AS3::CheckResult *v5; // rdi
  bool v6; // r8
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+30h] [rbp+8h]
  Scaleform::GFx::AS3::Boolean3 v9; // [rsp+38h] [rbp+10h]

  v4 = a2;
  v5 = result;
  v9 = 0;
  v6 = Scaleform::GFx::AS3::AbstractLessThan(&resulta, &v9, l, r)->Result;
  *v4 = v9 == 1;
  v5->Result = v6;
  return v5;
}

// File Line: 2205
// RVA: 0x7F1E00
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::GreaterThan(Scaleform::GFx::AS3::CheckResult *result, bool *a2, Scaleform::GFx::AS3::Value *l, Scaleform::GFx::AS3::Value *r)
{
  bool *v4; // rbx
  Scaleform::GFx::AS3::CheckResult *v5; // rdi
  bool v6; // r8
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+30h] [rbp+8h]
  Scaleform::GFx::AS3::Boolean3 v9; // [rsp+38h] [rbp+10h]

  v4 = a2;
  v5 = result;
  v9 = 0;
  v6 = Scaleform::GFx::AS3::AbstractLessThan(&resulta, &v9, r, l)->Result;
  *v4 = v9 == 1;
  v5->Result = v6;
  return v5;
}

// File Line: 2219
// RVA: 0x7F99F0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::LessThanOrEqual(Scaleform::GFx::AS3::CheckResult *result, bool *a2, Scaleform::GFx::AS3::Value *l, Scaleform::GFx::AS3::Value *r)
{
  bool *v4; // rbx
  Scaleform::GFx::AS3::CheckResult *v5; // rdi
  bool v6; // r8
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+30h] [rbp+8h]
  Scaleform::GFx::AS3::Boolean3 v9; // [rsp+38h] [rbp+10h]

  v4 = a2;
  v5 = result;
  v9 = 0;
  v6 = Scaleform::GFx::AS3::AbstractLessThan(&resulta, &v9, r, l)->Result;
  *v4 = v9 == 2;
  v5->Result = v6;
  return v5;
}

// File Line: 2233
// RVA: 0x7F1E50
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::GreaterThanOrEqual(Scaleform::GFx::AS3::CheckResult *result, bool *a2, Scaleform::GFx::AS3::Value *l, Scaleform::GFx::AS3::Value *r)
{
  bool *v4; // rbx
  Scaleform::GFx::AS3::CheckResult *v5; // rdi
  bool v6; // r8
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+30h] [rbp+8h]
  Scaleform::GFx::AS3::Boolean3 v9; // [rsp+38h] [rbp+10h]

  v4 = a2;
  v5 = result;
  v9 = 0;
  v6 = Scaleform::GFx::AS3::AbstractLessThan(&resulta, &v9, l, r)->Result;
  *v4 = v9 == 2;
  v5->Result = v6;
  return v5;
}

