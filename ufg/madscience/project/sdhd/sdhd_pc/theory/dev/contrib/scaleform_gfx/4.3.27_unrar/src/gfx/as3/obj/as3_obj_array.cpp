// File Line: 37
// RVA: 0x7B78D0
int __fastcall Scaleform::GFx::AS3::Impl::CompareAsString::Compare(Scaleform::GFx::AS3::Impl::CompareAsString *this, Scaleform::GFx::ASString *a, Scaleform::GFx::ASString *b)
{
  Scaleform::GFx::ASString *v3; // rsi
  Scaleform::GFx::ASString *v4; // r14
  Scaleform::GFx::AS3::Impl::CompareAsString *v5; // rbx
  const char *v6; // rbx
  bool v7; // di
  unsigned int v8; // eax
  bool v9; // r9
  const char *v10; // rdx
  Scaleform::GFx::ASConstString *v11; // rcx
  int result; // eax
  const char *v13; // rbx
  bool v14; // di
  const char *v15; // rax
  const char *v16; // rdx
  unsigned __int8 v17; // cl

  v3 = b;
  v4 = a;
  v5 = this;
  if ( this->UseLocale )
  {
    if ( this->Desc )
    {
      v6 = a->pNode->pData;
      v7 = this->CaseInsensitive == 0;
      v8 = Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&a->pNode);
      v9 = v7;
      v10 = v6;
      v11 = (Scaleform::GFx::ASConstString *)&v3->pNode;
    }
    else
    {
      v13 = b->pNode->pData;
      v14 = this->CaseInsensitive == 0;
      v8 = Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&b->pNode);
      v9 = v14;
      v10 = v13;
      v11 = (Scaleform::GFx::ASConstString *)&v4->pNode;
    }
    result = Scaleform::GFx::ASConstString::LocaleCompare_CaseCheck(v11, v10, v8, v9);
  }
  else
  {
    if ( this->CaseInsensitive )
    {
      result = Scaleform::String::CompareNoCase(a->pNode->pData, b->pNode->pData);
    }
    else
    {
      v15 = a->pNode->pData;
      v16 = (const char *)(b->pNode->pData - v15);
      while ( 1 )
      {
        v17 = *v15;
        if ( *v15 != v16[(_QWORD)v15] )
          break;
        ++v15;
        if ( !v17 )
        {
          result = 0;
          goto LABEL_14;
        }
      }
      result = -(v17 < v16[(_QWORD)v15]) | 1;
    }
LABEL_14:
    if ( v5->Desc )
      result = -result;
  }
  return result;
}

// File Line: 59
// RVA: 0x7B84D0
__int64 __fastcall Scaleform::GFx::AS3::Impl::CompareValuePtr::Compare(Scaleform::GFx::AS3::Impl::CompareValuePtr *this, Scaleform::GFx::AS3::Value *a, Scaleform::GFx::AS3::Value *b)
{
  Scaleform::GFx::AS3::Impl::CompareValuePtr *v3; // rbx
  unsigned int v4; // er9
  Scaleform::GFx::AS3::WeakProxy *v5; // r10
  int v6; // eax
  long double v7; // rcx
  unsigned int v8; // ecx
  Scaleform::GFx::AS3::WeakProxy *v9; // rdx
  int v10; // eax
  long double v11; // rcx
  signed int v12; // eax
  unsigned int v13; // ebx
  bool v14; // zf
  Scaleform::GFx::AS3::Value result; // [rsp+40h] [rbp-11h]
  Scaleform::GFx::AS3::Value ptr; // [rsp+68h] [rbp+17h]
  unsigned int v18; // [rsp+88h] [rbp+37h]
  Scaleform::GFx::AS3::Value::Extra v19; // [rsp+90h] [rbp+3Fh]
  Scaleform::GFx::AS3::Value::VU v20; // [rsp+98h] [rbp+47h]
  long double retaddr; // [rsp+B8h] [rbp+67h]
  long double v; // [rsp+C0h] [rbp+6Fh]

  v3 = this;
  result.Flags = 0;
  result.Bonus.pWeakProxy = 0i64;
  v4 = a->Flags;
  ptr.Flags = v4;
  v5 = a->Bonus.pWeakProxy;
  ptr.Bonus.pWeakProxy = a->Bonus.pWeakProxy;
  ptr.value = a->value;
  v6 = v4 & 0x1F;
  if ( v6 > 9 )
  {
    if ( (v4 >> 9) & 1 )
    {
      ++v5->RefCount;
      goto LABEL_13;
    }
    if ( v6 == 10 )
    {
      ++*(_DWORD *)(*(_QWORD *)&a->value.VNumber + 24i64);
    }
    else
    {
      if ( v6 <= 10 )
        goto LABEL_13;
      if ( v6 <= 15 )
      {
        v7 = a->value.VNumber;
      }
      else
      {
        if ( v6 > 17 )
          goto LABEL_13;
        v7 = *(double *)&a->value.VS._2.VObj;
      }
      if ( v7 != 0.0 )
        *(_DWORD *)(*(_QWORD *)&v7 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v7 + 32i64) + 1) & 0x8FBFFFFF;
    }
  }
LABEL_13:
  v8 = b->Flags;
  v18 = v8;
  v9 = b->Bonus.pWeakProxy;
  v19.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)b->Bonus;
  v20 = b->value;
  v10 = v8 & 0x1F;
  if ( v10 <= 9 )
    goto LABEL_25;
  if ( (v8 >> 9) & 1 )
  {
    ++v9->RefCount;
    goto LABEL_25;
  }
  if ( v10 == 10 )
  {
    ++*(_DWORD *)(*(_QWORD *)&b->value.VNumber + 24i64);
  }
  else
  {
    if ( v10 <= 10 )
      goto LABEL_25;
    if ( v10 <= 15 )
    {
      v11 = b->value.VNumber;
    }
    else
    {
      if ( v10 > 17 )
        goto LABEL_25;
      v11 = *(double *)&b->value.VS._2.VObj;
    }
    if ( v11 != 0.0 )
      *(_DWORD *)(*(_QWORD *)&v11 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v11 + 32i64) + 1) & 0x8FBFFFFF;
  }
LABEL_25:
  if ( !(_S11_12 & 1) )
  {
    _S11_12 |= 1u;
    ::v.Flags = 0;
    ::v.Bonus.pWeakProxy = 0i64;
    atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(v3->Vm, v3->Func, &::v, &result, 2u, &ptr, 0);
  if ( v3->Vm->HandleException
    || !Scaleform::GFx::AS3::Value::Convert2Number(&result, (Scaleform::GFx::AS3::CheckResult *)&retaddr, &v)->Result )
  {
    v12 = 0;
    goto LABEL_43;
  }
  retaddr = v;
  if ( v == -1.797693134862316e308/*-Inf*/ )
  {
    v12 = -1;
LABEL_43:
    v13 = v12;
    goto LABEL_44;
  }
  retaddr = v;
  if ( v == 1.797693134862316e308/*+Inf*/ )
  {
    v12 = 1;
    goto LABEL_43;
  }
  if ( Scaleform::GFx::NumberUtil::IsNEGATIVE_ZERO(v) )
  {
    v12 = -1;
    goto LABEL_43;
  }
  if ( Scaleform::GFx::NumberUtil::IsPOSITIVE_ZERO(v) )
  {
    v12 = 1;
    goto LABEL_43;
  }
  if ( v == 0.0 )
  {
    v13 = 0;
  }
  else
  {
    v13 = 1;
    if ( v < 0.0 )
      v13 = -1;
  }
LABEL_44:
  `eh vector destructor iterator'(&ptr, 0x20ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
  if ( (result.Flags & 0x1F) > 9 )
  {
    if ( (result.Flags >> 9) & 1 )
    {
      v14 = result.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v14 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      result.Bonus.pWeakProxy = 0i64;
      result.value = 0ui64;
      result.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
    }
  }
  return v13;
}alue = 0ui64;
      result.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::

// File Line: 95
// RVA: 0x7B79C0
double __fastcall Scaleform::GFx::AS3::Impl::CompareOn::Compare(Scaleform::GFx::AS3::Impl::CompareOn *this, Scaleform::GFx::AS3::Value *a, Scaleform::GFx::AS3::Value *b)
{
  Scaleform::GFx::AS3::Value *v3; // rsi
  Scaleform::GFx::AS3::Value *v4; // r14
  Scaleform::GFx::AS3::Impl::CompareOn *v5; // r15
  int v6; // edi
  double v7; // xmm6_8
  unsigned __int64 v8; // r13
  unsigned __int64 v9; // r12
  Scaleform::GFx::AS3::Value *v10; // rdx
  Scaleform::GFx::AS3::GASRefCountBase *v11; // rcx
  Scaleform::GFx::ASString *v12; // rbx
  Scaleform::GFx::ASStringNode *v13; // rax
  Scaleform::GFx::AS3::GASRefCountBase *v14; // rbx
  Scaleform::GFx::AS3::GASRefCountBase *v15; // rcx
  unsigned int v16; // eax
  Scaleform::GFx::ASString *v17; // rax
  Scaleform::GFx::ASStringNode *v18; // rcx
  bool v19; // zf
  Scaleform::GFx::ASStringNode *v20; // rcx
  int v21; // edi
  bool v22; // al
  unsigned int v23; // ebx
  char v24; // r14
  bool v25; // al
  bool v26; // al
  bool v27; // si
  const char *v28; // rbx
  unsigned int v29; // eax
  int v30; // eax
  const char *v31; // rdx
  const char *v32; // rcx
  signed __int64 v33; // rdx
  unsigned __int8 v34; // al
  Scaleform::GFx::ASStringNode *v35; // rcx
  Scaleform::GFx::ASStringNode *v36; // rcx
  Scaleform::GFx::AS3::GASRefCountBase *v37; // rcx
  unsigned int v38; // eax
  Scaleform::GFx::ASStringNode *v39; // rcx
  Scaleform::GFx::ASStringNode *v40; // rcx
  Scaleform::GFx::AS3::Value value; // [rsp+38h] [rbp-88h]
  Scaleform::GFx::AS3::PropRef v43; // [rsp+58h] [rbp-68h]
  Scaleform::GFx::AS3::PropRef v44; // [rsp+88h] [rbp-38h]
  Scaleform::GFx::AS3::Multiname mn; // [rsp+B8h] [rbp-8h]
  Scaleform::GFx::ASString result; // [rsp+E8h] [rbp+28h]
  long double v47; // [rsp+F0h] [rbp+30h]
  long double v48; // [rsp+F8h] [rbp+38h]
  Scaleform::GFx::ASString v49; // [rsp+100h] [rbp+40h]
  __int64 v50; // [rsp+108h] [rbp+48h]
  Scaleform::GFx::AS3::CheckResult v51; // [rsp+190h] [rbp+D0h]
  Scaleform::GFx::AS3::Value *v52; // [rsp+198h] [rbp+D8h]
  Scaleform::GFx::AS3::Value *v53; // [rsp+1A0h] [rbp+E0h]
  Scaleform::GFx::AS3::CheckResult v54; // [rsp+1A8h] [rbp+E8h]

  v50 = -2i64;
  v3 = b;
  v4 = a;
  v5 = this;
  v6 = 0;
  v7 = 0.0;
  v8 = this->Fields->Data.Size;
  v9 = 0i64;
  if ( v8 )
  {
    do
    {
      if ( v7 != 0.0 )
        return v7;
      v10 = &v5->Fields->Data.Data[v9];
      v11 = (Scaleform::GFx::AS3::GASRefCountBase *)&v5->Vm->PublicNamespace.pObject->vfptr;
      mn.Kind = 0;
      mn.Obj.pObject = v11;
      if ( v11 )
        v11->RefCount = (v11->RefCount + 1) & 0x8FBFFFFF;
      mn.Name.Flags = 0;
      mn.Name.Bonus.pWeakProxy = 0i64;
      if ( (v10->Flags & 0x1F) - 12 <= 3
        && (v12 = (Scaleform::GFx::ASString *)v10->value.VS._1.VStr) != 0i64
        && (v13 = v12[5].pNode, LODWORD(v13[3].pData) == 17)
        && ~(LOBYTE(v13[2].Size) >> 5) & 1 )
      {
        Scaleform::GFx::AS3::Value::Assign(&mn.Name, v12 + 7);
        v14 = (Scaleform::GFx::AS3::GASRefCountBase *)v12[8].pNode;
        v15 = mn.Obj.pObject;
        if ( v14 != mn.Obj.pObject )
        {
          if ( v14 )
          {
            v14->RefCount = (v14->RefCount + 1) & 0x8FBFFFFF;
            v15 = mn.Obj.pObject;
          }
          if ( v15 )
          {
            if ( (_QWORD)mn.Obj.pObject & 1 )
            {
              mn.Obj.pObject = (Scaleform::GFx::AS3::GASRefCountBase *)((char *)v15 - 1);
            }
            else
            {
              v16 = v15->RefCount;
              if ( v16 & 0x3FFFFF )
              {
                v15->RefCount = v16 - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v15->vfptr);
              }
            }
          }
          mn.Obj.pObject = v14;
        }
        mn.Kind &= 0xFFFFFFF9;
      }
      else
      {
        Scaleform::GFx::AS3::Value::AssignUnsafe(&mn.Name, v10);
        if ( (mn.Name.Flags & 0x1F) == 10 )
        {
          Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&mn.Name, &result);
          if ( result.pNode->Size )
          {
            if ( *result.pNode->pData == 64 )
            {
              mn.Kind |= 8u;
              v17 = Scaleform::GFx::ASString::Substring(&result, &v49, 1, result.pNode->Size);
              Scaleform::GFx::AS3::Value::Assign(&mn.Name, v17);
              v18 = v49.pNode;
              v19 = v49.pNode->RefCount == 1;
              --v18->RefCount;
              if ( v19 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v18);
            }
          }
          v20 = result.pNode;
          v19 = result.pNode->RefCount == 1;
          --v20->RefCount;
          if ( v19 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v20);
        }
      }
      v43.pSI = 0i64;
      v43.SlotIndex = 0i64;
      v43.This.Flags = 0;
      v43.This.Bonus.pWeakProxy = 0i64;
      v44.pSI = 0i64;
      v44.SlotIndex = 0i64;
      v44.This.Flags = 0;
      v44.This.Bonus.pWeakProxy = 0i64;
      Scaleform::GFx::AS3::FindObjProperty(&v43, v5->Vm, v4, &mn, 0);
      Scaleform::GFx::AS3::FindObjProperty(&v44, v5->Vm, v3, &mn, 0);
      if ( v43.This.Flags & 0x1F
        && (!((_QWORD)v43.pSI & 1) || (_QWORD)v43.pSI & 0xFFFFFFFFFFFFFFFEui64)
        && (!((LOBYTE(v43.pSI) >> 1) & 1) || (_QWORD)v43.pSI & 0xFFFFFFFFFFFFFFFDui64)
        && v44.This.Flags & 0x1F
        && (!((_QWORD)v44.pSI & 1) || (_QWORD)v44.pSI & 0xFFFFFFFFFFFFFFFEui64)
        && (!((LOBYTE(v44.pSI) >> 1) & 1) || (_QWORD)v44.pSI & 0xFFFFFFFFFFFFFFFDui64) )
      {
        value.Flags = 0;
        value.Bonus.pWeakProxy = 0i64;
        LODWORD(v43.pSI) = 0;
        v43.SlotIndex = 0i64;
        v21 = v6 | 1;
        v22 = 1;
        if ( Scaleform::GFx::AS3::PropRef::GetSlotValueUnsafe(&v43, &v51, v5->Vm, &value, 0)->Result )
        {
          v21 |= 2u;
          if ( Scaleform::GFx::AS3::PropRef::GetSlotValueUnsafe(
                 &v44,
                 &v54,
                 v5->Vm,
                 (Scaleform::GFx::AS3::Value *)&v43,
                 0)->Result )
            v22 = 0;
        }
        if ( v21 & 2 )
          v21 &= 0xFFFFFFFD;
        if ( v21 & 1 )
          v21 &= 0xFFFFFFFE;
        if ( v22 )
        {
          if ( ((_QWORD)v43.pSI & 0x1F) > 9 )
          {
            if ( (LODWORD(v43.pSI) >> 9) & 1 )
            {
              v19 = (*(_DWORD *)v43.SlotIndex)-- == 1;
              if ( v19 )
                ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
              v43.SlotIndex = 0i64;
              *(_QWORD *)&v43.This.Flags = 0i64;
              v43.This.Bonus.pWeakProxy = 0i64;
              LODWORD(v43.pSI) &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v43);
            }
          }
          if ( (value.Flags & 0x1F) > 9 )
          {
            if ( (value.Flags >> 9) & 1 )
            {
              v19 = value.Bonus.pWeakProxy->RefCount-- == 1;
              if ( v19 )
                ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
              value.Bonus.pWeakProxy = 0i64;
              value.value = 0ui64;
              value.Flags &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
            }
          }
          if ( (v44.This.Flags & 0x1F) > 9 )
          {
            if ( (v44.This.Flags >> 9) & 1 )
            {
              v19 = v44.This.Bonus.pWeakProxy->RefCount-- == 1;
              if ( v19 )
                ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
              v44.This.Bonus.pWeakProxy = 0i64;
              v44.This.value = 0ui64;
              v44.This.Flags &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&v44.This);
            }
          }
          if ( (v43.This.Flags & 0x1F) <= 9 )
            goto LABEL_191;
          if ( (v43.This.Flags >> 9) & 1 )
          {
            v19 = v43.This.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v19 )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
LABEL_189:
            v43.This.Bonus.pWeakProxy = 0i64;
            v43.This.value = 0ui64;
            v43.This.Flags &= 0xFFFFFDE0;
LABEL_191:
            Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
            return v7;
          }
LABEL_190:
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v43.This);
          goto LABEL_191;
        }
        v23 = v5->Flags->Data.Data[v9];
        v24 = (v23 >> 1) & 1;
        if ( v23 & 0x10 )
        {
          v47 = 0.0;
          v48 = 0.0;
          v6 = v21 | 4;
          v25 = 1;
          if ( Scaleform::GFx::AS3::Value::Convert2Number(
                 &value,
                 (Scaleform::GFx::AS3::CheckResult *)&value.Bonus,
                 &v47)->Result )
          {
            v6 |= 8u;
            if ( Scaleform::GFx::AS3::Value::Convert2Number(
                   (Scaleform::GFx::AS3::Value *)&v43,
                   (Scaleform::GFx::AS3::CheckResult *)&value.Bonus.pWeakProxy + 1,
                   &v48)->Result )
              v25 = 0;
          }
          if ( v6 & 8 )
            v6 &= 0xFFFFFFF7;
          if ( v6 & 4 )
            v6 &= 0xFFFFFFFB;
          if ( v25 )
          {
            if ( ((_QWORD)v43.pSI & 0x1F) > 9 )
            {
              if ( (LODWORD(v43.pSI) >> 9) & 1 )
              {
                v19 = (*(_DWORD *)v43.SlotIndex)-- == 1;
                if ( v19 )
                  ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
                v43.SlotIndex = 0i64;
                *(_QWORD *)&v43.This.Flags = 0i64;
                v43.This.Bonus.pWeakProxy = 0i64;
                LODWORD(v43.pSI) &= 0xFFFFFDE0;
              }
              else
              {
                Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v43);
              }
            }
            if ( (value.Flags & 0x1F) > 9 )
            {
              if ( (value.Flags >> 9) & 1 )
              {
                v19 = value.Bonus.pWeakProxy->RefCount-- == 1;
                if ( v19 )
                  ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
                value.Bonus.pWeakProxy = 0i64;
                value.value = 0ui64;
                value.Flags &= 0xFFFFFDE0;
              }
              else
              {
                Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
              }
            }
            if ( (v44.This.Flags & 0x1F) > 9 )
            {
              if ( (v44.This.Flags >> 9) & 1 )
              {
                v19 = v44.This.Bonus.pWeakProxy->RefCount-- == 1;
                if ( v19 )
                  ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
                v44.This.Bonus.pWeakProxy = 0i64;
                v44.This.value = 0ui64;
                v44.This.Flags &= 0xFFFFFDE0;
              }
              else
              {
                Scaleform::GFx::AS3::Value::ReleaseInternal(&v44.This);
              }
            }
            if ( (v43.This.Flags & 0x1F) <= 9 )
              goto LABEL_191;
            if ( (v43.This.Flags >> 9) & 1 )
            {
              v19 = v43.This.Bonus.pWeakProxy->RefCount-- == 1;
              if ( !v19 )
                goto LABEL_189;
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
              v43.This.Bonus.pWeakProxy = 0i64;
              v43.This.value = 0ui64;
              v43.This.Flags &= 0xFFFFFDE0;
              goto LABEL_191;
            }
            goto LABEL_190;
          }
          v7 = v47 - v48;
        }
        else
        {
          Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
            (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v5->Vm->StringManagerRef->Builtins,
            (Scaleform::GFx::ASString *)&v43.This.value);
          value.value.VNumber = v43.This.value.VNumber;
          ++*(_DWORD *)(*(_QWORD *)&value.value.VNumber + 24i64);
          v6 = v21 | 0x10;
          v26 = 1;
          if ( Scaleform::GFx::AS3::Value::Convert2String(
                 &value,
                 (Scaleform::GFx::AS3::CheckResult *)&value.Bonus.pWeakProxy + 2,
                 (Scaleform::GFx::ASString *)&v43.This.value)->Result )
          {
            v6 |= 0x20u;
            if ( Scaleform::GFx::AS3::Value::Convert2String(
                   (Scaleform::GFx::AS3::Value *)&v43,
                   (Scaleform::GFx::AS3::CheckResult *)&value.value.VS._2,
                   (Scaleform::GFx::ASString *)&value.value)->Result )
              v26 = 0;
          }
          if ( v6 & 0x20 )
            v6 &= 0xFFFFFFDF;
          if ( v6 & 0x10 )
            v6 &= 0xFFFFFFEF;
          if ( v26 )
          {
            v39 = value.value.VS._1.VStr;
            v19 = *(_DWORD *)(*(_QWORD *)&value.value.VNumber + 24i64) == 1;
            --v39->RefCount;
            if ( v19 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v39);
            v40 = v43.This.value.VS._1.VStr;
            v19 = *(_DWORD *)(*(_QWORD *)&v43.This.value.VNumber + 24i64) == 1;
            --v40->RefCount;
            if ( v19 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v40);
            if ( ((_QWORD)v43.pSI & 0x1F) > 9 )
            {
              if ( (LODWORD(v43.pSI) >> 9) & 1 )
              {
                v19 = (*(_DWORD *)v43.SlotIndex)-- == 1;
                if ( v19 )
                  ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
                v43.SlotIndex = 0i64;
                *(_QWORD *)&v43.This.Flags = 0i64;
                v43.This.Bonus.pWeakProxy = 0i64;
                LODWORD(v43.pSI) &= 0xFFFFFDE0;
              }
              else
              {
                Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v43);
              }
            }
            if ( (value.Flags & 0x1F) > 9 )
            {
              if ( (value.Flags >> 9) & 1 )
              {
                v19 = value.Bonus.pWeakProxy->RefCount-- == 1;
                if ( v19 )
                  ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
                value.Bonus.pWeakProxy = 0i64;
                value.value = 0ui64;
                value.Flags &= 0xFFFFFDE0;
              }
              else
              {
                Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
              }
            }
            if ( (v44.This.Flags & 0x1F) > 9 )
            {
              if ( (v44.This.Flags >> 9) & 1 )
              {
                v19 = v44.This.Bonus.pWeakProxy->RefCount-- == 1;
                if ( v19 )
                  ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
                v44.This.Bonus.pWeakProxy = 0i64;
                v44.This.value = 0ui64;
                v44.This.Flags &= 0xFFFFFDE0;
              }
              else
              {
                Scaleform::GFx::AS3::Value::ReleaseInternal(&v44.This);
              }
            }
            if ( (v43.This.Flags & 0x1F) <= 9 )
              goto LABEL_191;
            if ( (v43.This.Flags >> 9) & 1 )
            {
              v19 = v43.This.Bonus.pWeakProxy->RefCount-- == 1;
              if ( !v19 )
                goto LABEL_189;
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
              v43.This.Bonus.pWeakProxy = 0i64;
              v43.This.value = 0ui64;
              v43.This.Flags &= 0xFFFFFDE0;
              goto LABEL_191;
            }
            goto LABEL_190;
          }
          v27 = ~(_BYTE)v23 & 1;
          if ( _bittest((const signed int *)&v23, 0xAu) )
          {
            v28 = value.value.VS._1.VStr->pData;
            v29 = Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&value.value);
            v30 = Scaleform::GFx::ASConstString::LocaleCompare_CaseCheck(
                    (Scaleform::GFx::ASConstString *)&v43.This.value,
                    v28,
                    v29,
                    v27);
          }
          else
          {
            v31 = value.value.VS._1.VStr->pData;
            v32 = v43.This.value.VS._1.VStr->pData;
            if ( v27 )
            {
              v33 = v31 - v32;
              while ( 1 )
              {
                v34 = *v32;
                if ( *v32 != v32[v33] )
                  break;
                ++v32;
                if ( !v34 )
                {
                  v30 = 0;
                  goto LABEL_74;
                }
              }
              v30 = -(v34 < v32[v33]) | 1;
            }
            else
            {
              v30 = Scaleform::String::CompareNoCase(v32, v31);
            }
          }
LABEL_74:
          v7 = (double)v30;
          v35 = value.value.VS._1.VStr;
          v19 = *(_DWORD *)(*(_QWORD *)&value.value.VNumber + 24i64) == 1;
          --v35->RefCount;
          if ( v19 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v35);
          v36 = v43.This.value.VS._1.VStr;
          v19 = *(_DWORD *)(*(_QWORD *)&v43.This.value.VNumber + 24i64) == 1;
          --v36->RefCount;
          if ( v19 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v36);
          v3 = v53;
        }
        if ( v24 )
          *(_QWORD *)&v7 ^= _xmm[0];
        if ( ((_QWORD)v43.pSI & 0x1F) > 9 )
        {
          if ( (LODWORD(v43.pSI) >> 9) & 1 )
          {
            v19 = (*(_DWORD *)v43.SlotIndex)-- == 1;
            if ( v19 )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            v43.SlotIndex = 0i64;
            *(_QWORD *)&v43.This.Flags = 0i64;
            v43.This.Bonus.pWeakProxy = 0i64;
            LODWORD(v43.pSI) &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v43);
          }
        }
        if ( (value.Flags & 0x1F) > 9 )
        {
          if ( (value.Flags >> 9) & 1 )
          {
            v19 = value.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v19 )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            value.Bonus.pWeakProxy = 0i64;
            value.value = 0ui64;
            value.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
          }
        }
        v4 = v52;
      }
      if ( (v44.This.Flags & 0x1F) > 9 )
      {
        if ( (v44.This.Flags >> 9) & 1 )
        {
          v19 = v44.This.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v19 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          v44.This.Bonus.pWeakProxy = 0i64;
          v44.This.value = 0ui64;
          v44.This.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v44.This);
        }
      }
      if ( (v43.This.Flags & 0x1F) > 9 )
      {
        if ( (v43.This.Flags >> 9) & 1 )
        {
          v19 = v43.This.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v19 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          v43.This.Bonus.pWeakProxy = 0i64;
          v43.This.value = 0ui64;
          v43.This.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v43.This);
        }
      }
      if ( (mn.Name.Flags & 0x1F) > 9 )
      {
        if ( (mn.Name.Flags >> 9) & 1 )
        {
          v19 = mn.Name.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v19 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          mn.Name.Bonus.pWeakProxy = 0i64;
          mn.Name.value = 0ui64;
          mn.Name.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&mn.Name);
        }
      }
      v37 = mn.Obj.pObject;
      if ( mn.Obj.pObject )
      {
        if ( (_QWORD)mn.Obj.pObject & 1 )
        {
          --mn.Obj.pObject;
        }
        else
        {
          v38 = mn.Obj.pObject->RefCount;
          if ( v38 & 0x3FFFFF )
          {
            mn.Obj.pObject->RefCount = v38 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v37->vfptr);
          }
        }
      }
      ++v9;
    }
    while ( v9 < v8 );
  }
  return v7;
}

// File Line: 181
// RVA: 0x801860
void __fastcall Scaleform::GFx::AS3::Impl::SparseArray::MoveHashRight(Scaleform::GFx::AS3::Impl::SparseArray *this, unsigned __int64 first_ind, unsigned __int64 offset)
{
  unsigned __int64 v3; // r14
  unsigned __int64 v4; // rsi
  unsigned __int64 v5; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *v6; // rdi
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > v7; // r8
  signed __int64 v8; // rcx
  signed __int64 v9; // rdx
  signed __int64 v10; // rax
  unsigned __int64 v11; // rdx
  signed __int64 v12; // rcx
  unsigned __int64 *v13; // rax
  signed __int64 v14; // rdx
  int v15; // eax
  bool v16; // zf
  Scaleform::GFx::ASStringNode *v17; // rcx
  long double v18; // rcx
  int v19; // eax
  Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef v20; // [rsp+28h] [rbp-38h]
  Scaleform::GFx::AS3::Value v21; // [rsp+38h] [rbp-28h]
  unsigned __int64 key; // [rsp+80h] [rbp+20h]

  v3 = offset;
  v4 = first_ind;
  v21.Flags = 0;
  v21.Bonus.pWeakProxy = 0i64;
  v5 = this->ValueHHighInd + 1;
  if ( v5 > first_ind )
  {
    v6 = (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&this->ValueH.mHash.pTable;
    do
    {
      key = --v5;
      v7.pTable = v6->pTable;
      if ( v6->pTable )
      {
        v8 = 5381i64;
        v9 = 8i64;
        do
        {
          v10 = 65599 * v8 + *((unsigned __int8 *)&key + --v9);
          v8 = 65599 * v8 + *((unsigned __int8 *)&key + v9);
        }
        while ( v9 );
        v11 = v10 & v7.pTable->SizeMask;
        v12 = v10 & v7.pTable->SizeMask;
        v13 = &v7.pTable[1].EntryCount + 7 * (v10 & v7.pTable->SizeMask);
        if ( *v13 != -2i64 && v13[1] == v11 )
        {
          while ( v13[1] != v11 || v13[2] != v5 )
          {
            v12 = *v13;
            if ( *v13 == -1i64 )
              goto LABEL_15;
            v13 = &v7.pTable[1].EntryCount + 7 * v12;
          }
          if ( v12 >= 0 )
          {
            v14 = (signed __int64)&v7.pTable[2] + 56 * v12;
            if ( v14 )
            {
              Scaleform::GFx::AS3::Value::Assign(&v21, (Scaleform::GFx::AS3::Value *)(v14 + 8));
              Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::RemoveAlt<unsigned __int64>(
                v6,
                &key);
              key += v3;
              v20.pFirst = &key;
              v20.pSecond = &v21;
              Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
                v6,
                v6[1].pTable,
                &v20);
            }
          }
        }
      }
LABEL_15:
      ;
    }
    while ( v5 > v4 );
  }
  v15 = v21.Flags & 0x1F;
  if ( v15 > 9 )
  {
    if ( (v21.Flags >> 9) & 1 )
    {
      v16 = v21.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v16 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v21.Bonus.pWeakProxy = 0i64;
      v21.value = 0ui64;
      v21.Flags &= 0xFFFFFDE0;
    }
    else
    {
      switch ( v15 )
      {
        case 10:
          v17 = v21.value.VS._1.VStr;
          v16 = *(_DWORD *)(*(_QWORD *)&v21.value.VNumber + 24i64) == 1;
          --v17->RefCount;
          if ( v16 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v17);
          break;
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
          v18 = v21.value.VNumber;
          if ( !v21.value.VS._1.VBool )
            goto LABEL_28;
          --*(_QWORD *)&v21.value.VNumber;
          break;
        case 16:
        case 17:
          v18 = *(double *)&v21.value.VS._2.VObj;
          if ( (_QWORD)v21.value.VS._2.VObj & 1 )
          {
            --v21.value.VS._2.VObj;
          }
          else
          {
LABEL_28:
            if ( v18 != 0.0 )
            {
              v19 = *(_DWORD *)(*(_QWORD *)&v18 + 32i64);
              if ( v19 & 0x3FFFFF )
              {
                *(_DWORD *)(*(_QWORD *)&v18 + 32i64) = v19 - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(*(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v18);
              }
            }
          }
          break;
        default:
          return;
      }
    }
  }
}

// File Line: 198
// RVA: 0x7BFAE0
void __fastcall Scaleform::GFx::AS3::Impl::SparseArray::CutHash(Scaleform::GFx::AS3::Impl::SparseArray *this, unsigned __int64 pos, unsigned __int64 del_num, Scaleform::GFx::AS3::Impl::SparseArray *deleted)
{
  Scaleform::GFx::AS3::Impl::SparseArray *v4; // rsi
  unsigned __int64 v5; // rbx
  Scaleform::GFx::AS3::Impl::SparseArray *v6; // r14
  unsigned __int64 v7; // r15
  unsigned __int64 v8; // r12
  unsigned __int64 v9; // rdi
  unsigned __int64 v10; // r12
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v11; // r9
  signed __int64 v12; // rcx
  signed __int64 v13; // rdx
  signed __int64 v14; // rax
  signed __int64 v15; // r8
  signed __int64 v16; // rdx
  unsigned __int64 *v17; // rcx
  signed __int64 v18; // rdx
  signed __int64 v19; // rcx
  signed __int64 v20; // rdx
  bool v21; // zf
  Scaleform::GFx::AS3::Value::VU *v22; // rdx
  int v23; // eax
  long double v24; // rax
  unsigned __int64 v25; // r15
  unsigned __int64 v26; // r12
  int v27; // eax
  Scaleform::GFx::ASStringNode *v28; // rcx
  long double v29; // rcx
  int v30; // eax
  unsigned __int64 key; // [rsp+20h] [rbp-60h]
  unsigned __int64 v32; // [rsp+28h] [rbp-58h]
  unsigned __int64 v33; // [rsp+30h] [rbp-50h]
  __int64 v34; // [rsp+38h] [rbp-48h]
  Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef v35; // [rsp+40h] [rbp-40h]
  Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef v36; // [rsp+50h] [rbp-30h]
  Scaleform::GFx::AS3::Value v37; // [rsp+60h] [rbp-20h]
  unsigned __int64 v38; // [rsp+C0h] [rbp+40h]

  if ( del_num )
  {
    v38 = del_num;
    v34 = -2i64;
    v4 = deleted;
    v5 = del_num;
    v6 = this;
    v32 = del_num + pos - 1;
    v7 = this->ValueHLowInd;
    if ( v7 < pos )
      v7 = pos;
    v8 = this->ValueHHighInd;
    if ( del_num + pos - 1 < v8 )
      v8 = del_num + pos - 1;
    v33 = v8;
    v37.Flags = 0;
    v37.Bonus.pWeakProxy = 0i64;
    v9 = v7;
    key = v7;
    if ( v7 <= this->ValueHHighInd )
    {
      v10 = del_num + pos - 1;
      while ( 1 )
      {
        v11 = v6->ValueH.mHash.pTable;
        if ( !v11 )
          goto LABEL_40;
        v12 = 5381i64;
        v13 = 8i64;
        do
        {
          v14 = 65599 * v12 + *((unsigned __int8 *)&key + --v13);
          v12 = 65599 * v12 + *((unsigned __int8 *)&key + v13);
        }
        while ( v13 );
        v15 = v14 & v11->SizeMask;
        v16 = v14 & v11->SizeMask;
        v17 = &v11[1].EntryCount + 7 * (v14 & v11->SizeMask);
        if ( *v17 == -2i64 || v17[1] != v15 )
          goto LABEL_40;
        while ( v17[1] != v15 || v17[2] != v9 )
        {
          v16 = *v17;
          if ( *v17 == -1i64 )
            goto LABEL_40;
          v17 = &v11[1].EntryCount + 7 * v16;
        }
        if ( v16 < 0 )
          goto LABEL_40;
        v18 = (signed __int64)&v11[2] + 56 * v16;
        if ( !v18 )
          goto LABEL_40;
        Scaleform::GFx::AS3::Value::Assign(&v37, (Scaleform::GFx::AS3::Value *)(v18 + 8));
        Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::RemoveAlt<unsigned __int64>(
          (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v6->ValueH.mHash.pTable,
          &key);
        v9 = key;
        if ( key > v10 )
        {
          if ( v37.Flags & 0x1F )
          {
            v32 = key - v5;
            v35.pFirst = &v32;
            v35.pSecond = &v37;
            Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
              (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v6->ValueH.mHash.pTable,
              v6->ValueH.mHash.pHeap,
              &v35);
          }
          goto LABEL_40;
        }
        if ( v4 )
          break;
LABEL_40:
        key = ++v9;
        if ( v9 > v6->ValueHHighInd )
        {
          v8 = v33;
          goto LABEL_42;
        }
      }
      if ( v4->Length != v4->ValueA.Data.Size )
      {
        v4->ValueHHighInd = v4->Length;
        v36.pFirst = &v4->ValueHHighInd;
        v36.pSecond = &v37;
        Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
          (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v4->ValueH.mHash.pTable,
          v4->ValueH.mHash.pHeap,
          &v36);
        goto LABEL_39;
      }
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v4->ValueA.Data.Data,
        v4->ValueA.Data.pHeap,
        v4->ValueA.Data.Size + 1);
      v19 = 32 * v4->ValueA.Data.Size;
      v20 = (signed __int64)&v4->ValueA.Data.Data[-1];
      v21 = v19 + v20 == 0;
      v22 = (Scaleform::GFx::AS3::Value::VU *)(v19 + v20);
      v32 = (unsigned __int64)v22;
      key = (unsigned __int64)v22;
      if ( !v21 )
      {
        LODWORD(v22->VS._1.VStr) = v37.Flags;
        v22->VS._2.VObj = (Scaleform::GFx::AS3::Object *)v37.Bonus.pWeakProxy;
        v22[1] = v37.value;
        v23 = v37.Flags & 0x1F;
        if ( v23 > 9 )
        {
          if ( (v37.Flags >> 9) & 1 )
          {
            ++v37.Bonus.pWeakProxy->RefCount;
          }
          else
          {
            if ( v23 == 10 )
            {
              ++*(_DWORD *)(*(_QWORD *)&v37.value.VNumber + 24i64);
              goto LABEL_37;
            }
            if ( v23 > 10 )
            {
              if ( v23 <= 15 )
              {
                v24 = v37.value.VNumber;
              }
              else
              {
                if ( v23 > 17 )
                  goto LABEL_37;
                v24 = *(double *)&v37.value.VS._2.VObj;
              }
              if ( v24 != 0.0 )
              {
                ++*(_DWORD *)(*(_QWORD *)&v24 + 32i64);
                *(_DWORD *)(*(_QWORD *)&v24 + 32i64) &= 0x8FBFFFFF;
              }
              goto LABEL_37;
            }
          }
        }
      }
LABEL_37:
      v5 = v38;
LABEL_39:
      ++v4->Length;
      goto LABEL_40;
    }
LABEL_42:
    if ( v6->ValueHLowInd < v7 )
      v7 = v6->ValueHLowInd;
    v6->ValueHLowInd = v7;
    if ( v7 <= v5 )
      v25 = 0i64;
    else
      v25 = v7 - v5;
    v6->ValueHLowInd = v25;
    if ( v8 < v6->ValueHHighInd )
      v8 = v6->ValueHHighInd;
    v6->ValueHHighInd = v8;
    if ( v8 <= v5 )
      v26 = 0i64;
    else
      v26 = v8 - v5;
    v6->ValueHHighInd = v26;
    v27 = v37.Flags & 0x1F;
    if ( v27 > 9 )
    {
      if ( (v37.Flags >> 9) & 1 )
      {
        v21 = v37.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v21 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v37.Bonus.pWeakProxy = 0i64;
        v37.value = 0ui64;
        v37.Flags &= 0xFFFFFDE0;
      }
      else
      {
        switch ( v27 )
        {
          case 10:
            v28 = v37.value.VS._1.VStr;
            v21 = *(_DWORD *)(*(_QWORD *)&v37.value.VNumber + 24i64) == 1;
            --v28->RefCount;
            if ( v21 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v28);
            break;
          case 11:
          case 12:
          case 13:
          case 14:
          case 15:
            v29 = v37.value.VNumber;
            if ( !v37.value.VS._1.VBool )
              goto LABEL_64;
            --*(_QWORD *)&v37.value.VNumber;
            break;
          case 16:
          case 17:
            v29 = *(double *)&v37.value.VS._2.VObj;
            if ( (_QWORD)v37.value.VS._2.VObj & 1 )
            {
              --v37.value.VS._2.VObj;
            }
            else
            {
LABEL_64:
              if ( v29 != 0.0 )
              {
                v30 = *(_DWORD *)(*(_QWORD *)&v29 + 32i64);
                if ( v30 & 0x3FFFFF )
                {
                  *(_DWORD *)(*(_QWORD *)&v29 + 32i64) = v30 - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(*(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v29);
                }
              }
            }
            break;
          default:
            return;
        }
      }
    }
  }
}

// File Line: 235
// RVA: 0x811AE0
void __fastcall Scaleform::GFx::AS3::Impl::SparseArray::RemoveHash(Scaleform::GFx::AS3::Impl::SparseArray *this, unsigned __int64 first_ind, unsigned __int64 num)
{
  unsigned int v3; // ebx
  unsigned __int64 v4; // rsi
  unsigned __int64 v5; // rbp
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *v6; // rdi
  __int64 v7; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > v8; // r8
  unsigned __int64 v9; // r9
  signed __int64 v10; // rcx
  signed __int64 v11; // rdx
  __int64 v12; // rax
  signed __int64 v13; // rax
  unsigned __int64 v14; // rdx
  signed __int64 v15; // rcx
  unsigned __int64 *v16; // rax
  __int64 v17; // [rsp+38h] [rbp+10h]
  unsigned __int64 key; // [rsp+40h] [rbp+18h]

  if ( num )
  {
    v3 = 0;
    v4 = num;
    v5 = first_ind;
    v6 = (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&this->ValueH.mHash.pTable;
    v7 = 0i64;
    do
    {
      v8.pTable = v6->pTable;
      v9 = v7 + v5;
      key = v7 + v5;
      if ( v8.pTable )
      {
        v10 = 5381i64;
        v11 = 8i64;
        do
        {
          v12 = *((unsigned __int8 *)&v17 + v11-- + 7);
          v13 = 65599 * v10 + v12;
          v10 = v13;
        }
        while ( v11 );
        v14 = v13 & v8.pTable->SizeMask;
        v15 = v14;
        v16 = &v8.pTable[1].EntryCount + 7 * v14;
        if ( *v16 != -2i64 && v16[1] == v14 )
        {
          while ( v16[1] != v14 || v16[2] != v9 )
          {
            v15 = *v16;
            if ( *v16 == -1i64 )
              goto LABEL_15;
            v16 = &v8.pTable[1].EntryCount + 7 * v15;
          }
          if ( v15 >= 0 )
          {
            if ( (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *)((char *)&v8.pTable[2] + 56 * v15) )
              Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::RemoveAlt<unsigned __int64>(
                v6,
                &key);
          }
        }
      }
LABEL_15:
      v7 = ++v3;
    }
    while ( v3 < v4 );
  }
}

// File Line: 246
// RVA: 0x814510
void __fastcall Scaleform::GFx::AS3::Impl::SparseArray::Resize(Scaleform::GFx::AS3::Impl::SparseArray *this, unsigned __int64 newLength)
{
  unsigned __int64 v2; // rdi
  Scaleform::GFx::AS3::Impl::SparseArray *v3; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *v4; // rcx
  unsigned __int64 v5; // rax
  unsigned __int64 v6; // r8

  v2 = newLength;
  v3 = this;
  if ( !newLength )
  {
    Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      &this->ValueA.Data,
      0i64);
    v4 = (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v3->ValueH.mHash.pTable;
LABEL_8:
    Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Clear(v4);
    v3->Length = v2;
    v3->ValueHLowInd = 0i64;
    v3->ValueHHighInd = 0i64;
    return;
  }
  v5 = this->ValueA.Data.Size;
  if ( newLength <= v5 && v5 )
  {
    Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      &this->ValueA.Data,
      newLength);
    v4 = (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v3->ValueH.mHash.pTable;
    goto LABEL_8;
  }
  if ( newLength < this->ValueHLowInd )
  {
    v4 = (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&this->ValueH.mHash.pTable;
    goto LABEL_8;
  }
  v6 = this->ValueHHighInd;
  if ( newLength >= v6 )
  {
    this->Length = newLength;
  }
  else
  {
    Scaleform::GFx::AS3::Impl::SparseArray::CutHash(this, newLength, v6 - newLength + 1, 0i64);
    v3->Length = v2;
  }
}

// File Line: 289
// RVA: 0x7B1450
void __fastcall Scaleform::GFx::AS3::Impl::SparseArray::Assign(Scaleform::GFx::AS3::Impl::SparseArray *this, Scaleform::GFx::AS3::Impl::SparseArray *other)
{
  Scaleform::GFx::AS3::Impl::SparseArray *v2; // rsi
  Scaleform::GFx::AS3::Impl::SparseArray *v3; // r14
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *v4; // rcx

  if ( this != other )
  {
    v2 = other;
    this->Length = other->Length;
    v3 = this;
    this->ValueHLowInd = other->ValueHLowInd;
    v4 = (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&this->ValueH.mHash.pTable;
    v4[-9].pTable = (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *)other->ValueHHighInd;
    Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Assign(
      v4,
      other->ValueH.mHash.pHeap,
      (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&other->ValueH.mHash.pTable);
    v3->ValueH.mHash.pHeap = v2->ValueH.mHash.pHeap;
    Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy>::operator=(&v3->ValueA, &v2->ValueA);
  }
}

// File Line: 301
// RVA: 0x80AD10
void __fastcall Scaleform::GFx::AS3::Impl::SparseArray::PushBack(Scaleform::GFx::AS3::Impl::SparseArray *this, Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::Impl::SparseArray *v2; // rdi
  unsigned __int64 v3; // rcx
  Scaleform::GFx::AS3::Value *v4; // rsi
  void *v5; // rdx
  Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef key; // [rsp+20h] [rbp-18h]

  v2 = this;
  v3 = this->Length;
  v4 = v;
  if ( v3 == v2->ValueA.Data.Size )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v2->ValueA.Data.Data,
      v2->ValueA.Data.pHeap,
      v2->ValueA.Data.Size + 1);
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
      &v2->ValueA.Data.Data[v2->ValueA.Data.Size - 1],
      v4);
  }
  else
  {
    key.pSecond = v;
    v2->ValueHHighInd = v3;
    v5 = v2->ValueH.mHash.pHeap;
    key.pFirst = &v2->ValueHHighInd;
    Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
      (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v2->ValueH.mHash.pTable,
      v5,
      &key);
  }
  ++v2->Length;
}

// File Line: 364
// RVA: 0x806F10
void __fastcall Scaleform::GFx::AS3::Impl::SparseArray::Pick(Scaleform::GFx::AS3::Impl::SparseArray *this, Scaleform::GFx::AS3::ValueStack *x, unsigned __int64 num)
{
  unsigned __int64 v3; // r12
  unsigned __int64 v4; // r15
  Scaleform::GFx::AS3::ValueStack *v5; // rsi
  Scaleform::GFx::AS3::Impl::SparseArray *v6; // r14
  unsigned __int64 v7; // rdi
  void *v8; // rdx
  Scaleform::GFx::AS3::Value *v9; // rbx
  Scaleform::GFx::AS3::WeakProxy *v10; // rdx
  bool v11; // zf
  Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef key; // [rsp+20h] [rbp-38h]
  unsigned __int64 v13; // [rsp+70h] [rbp+18h]

  if ( num )
  {
    v3 = this->ValueA.Data.Size;
    v4 = num;
    v5 = x;
    v6 = this;
    if ( this->Length == v3 )
    {
      Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        &this->ValueA.Data,
        v3 + num);
      memmove(&v6->ValueA.Data.Data[v3], &v5->pCurrent[-(unsigned __int16)(v4 - 1)], 32 * v4);
      v5->pCurrent -= v4;
      v6->Length = v6->ValueA.Data.Size;
    }
    else
    {
      v13 = num + this->ValueHHighInd;
      if ( num )
      {
        v7 = num;
        key.pFirst = &v13;
        do
        {
          v8 = v6->ValueH.mHash.pHeap;
          key.pSecond = v5->pCurrent;
          Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
            (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v6->ValueH.mHash.pTable,
            v8,
            &key);
          v9 = v5->pCurrent;
          if ( (v5->pCurrent->Flags & 0x1F) > 9 )
          {
            if ( (v5->pCurrent->Flags >> 9) & 1 )
            {
              v10 = v9->Bonus.pWeakProxy;
              v11 = v10->RefCount-- == 1;
              if ( v11 )
                ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
              v9->Flags &= 0xFFFFFDE0;
              v9->Bonus.pWeakProxy = 0i64;
              v9->value.VNumber = 0.0;
              v9->value.VS._2.VObj = 0i64;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(v5->pCurrent);
            }
          }
          --v5->pCurrent;
          --v13;
          --v7;
        }
        while ( v7 );
      }
      v6->ValueHHighInd += v4;
      v6->Length += v4;
    }
  }
}

// File Line: 391
// RVA: 0x7B0610
void __fastcall Scaleform::GFx::AS3::Impl::SparseArray::Append(Scaleform::GFx::AS3::Impl::SparseArray *this, Scaleform::GFx::AS3::Impl::SparseArray *other, unsigned __int64 ind, unsigned __int64 num)
{
  unsigned __int64 v4; // r13
  unsigned __int64 v5; // rbx
  Scaleform::GFx::AS3::Impl::SparseArray *v6; // rsi
  Scaleform::GFx::AS3::Impl::SparseArray *v7; // r14
  unsigned __int64 v8; // r15
  signed __int64 v9; // r12
  Scaleform::GFx::AS3::Value *v10; // rbp
  signed __int64 v11; // rax
  signed __int64 v12; // rbp
  unsigned __int64 v13; // r15
  signed __int64 v14; // r12
  unsigned __int64 v15; // rax
  Scaleform::GFx::AS3::Value *v16; // rcx
  signed __int64 v17; // rax
  signed __int64 v18; // rcx
  void *v19; // rdx
  Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef v20; // [rsp+20h] [rbp-48h]
  unsigned __int64 key; // [rsp+70h] [rbp+8h]
  unsigned __int64 v22; // [rsp+88h] [rbp+20h]

  v22 = num;
  v4 = other->Length;
  v5 = ind;
  v6 = other;
  v7 = this;
  if ( this->Length == this->ValueA.Data.Size )
  {
    if ( num )
    {
      v8 = ind;
      v9 = -(signed __int64)ind;
      do
      {
        if ( v5 >= v4 )
          break;
        key = v5;
        if ( v5 >= v6->ValueA.Data.Size )
        {
          if ( v5 < v6->ValueHLowInd
            || v5 > v6->ValueHHighInd
            || (v11 = Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::findIndexAlt<unsigned __int64>(
                        (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v6->ValueH.mHash.pTable,
                        &key),
                v11 < 0)
            || (v12 = (signed __int64)&v6->ValueH.mHash.pTable[2] + 56 * v11) == 0
            || (v10 = (Scaleform::GFx::AS3::Value *)(v12 + 8)) == 0i64 )
          {
            v10 = &v6->DefaultValue;
          }
        }
        else
        {
          v10 = &v6->ValueA.Data.Data[v8];
        }
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v7->ValueA.Data.Data,
          v7->ValueA.Data.pHeap,
          v7->ValueA.Data.Size + 1);
        Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
          &v7->ValueA.Data.Data[v7->ValueA.Data.Size - 1],
          v10);
        ++v5;
        ++v8;
      }
      while ( v9 + v5 < v22 );
    }
    v7->Length = v7->ValueA.Data.Size;
  }
  else if ( num )
  {
    v13 = ind;
    v14 = -(signed __int64)ind;
    do
    {
      if ( v5 >= v4 )
        break;
      v15 = v7->Length;
      key = v5;
      v7->ValueHHighInd = v15;
      if ( v5 >= v6->ValueA.Data.Size )
      {
        if ( v5 < v6->ValueHLowInd
          || v5 > v6->ValueHHighInd
          || (v17 = Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::findIndexAlt<unsigned __int64>(
                      (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v6->ValueH.mHash.pTable,
                      &key),
              v17 < 0)
          || (v18 = (signed __int64)&v6->ValueH.mHash.pTable[2] + 56 * v17) == 0
          || (v16 = (Scaleform::GFx::AS3::Value *)(v18 + 8)) == 0i64 )
        {
          v16 = &v6->DefaultValue;
        }
      }
      else
      {
        v16 = &v6->ValueA.Data.Data[v13];
      }
      v19 = v7->ValueH.mHash.pHeap;
      v20.pSecond = v16;
      v20.pFirst = &v7->ValueHHighInd;
      Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
        (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v7->ValueH.mHash.pTable,
        v19,
        &v20);
      ++v7->Length;
      ++v5;
      ++v13;
    }
    while ( v5 + v14 < v22 );
  }
}

// File Line: 414
// RVA: 0x7B07D0
void __fastcall Scaleform::GFx::AS3::Impl::SparseArray::Append(Scaleform::GFx::AS3::Impl::SparseArray *this, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v3; // rdi
  Scaleform::GFx::AS3::Impl::SparseArray *v4; // rbx
  __int64 v5; // rbp
  unsigned __int64 *v6; // r14
  __int64 v7; // rbp
  void *v8; // rdx
  Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef key; // [rsp+20h] [rbp-18h]

  v3 = argv;
  v4 = this;
  if ( this->Length == this->ValueA.Data.Size )
  {
    if ( argc )
    {
      v5 = argc;
      do
      {
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v4->ValueA.Data.Data,
          v4->ValueA.Data.pHeap,
          v4->ValueA.Data.Size + 1);
        Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
          &v4->ValueA.Data.Data[v4->ValueA.Data.Size - 1],
          v3);
        ++v3;
        --v5;
      }
      while ( v5 );
    }
    v4->Length = v4->ValueA.Data.Size;
  }
  else if ( argc )
  {
    v6 = &this->ValueHHighInd;
    v7 = argc;
    key.pFirst = &this->ValueHHighInd;
    do
    {
      *v6 = v4->Length;
      v8 = v4->ValueH.mHash.pHeap;
      key.pSecond = v3;
      Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
        (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v4->ValueH.mHash.pTable,
        v8,
        &key);
      ++v4->Length;
      ++v3;
      --v7;
    }
    while ( v7 );
  }
}

// File Line: 436
// RVA: 0x7F5AC0
void __fastcall Scaleform::GFx::AS3::Impl::SparseArray::Insert(Scaleform::GFx::AS3::Impl::SparseArray *this, unsigned __int64 pos, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v4; // rbp
  unsigned __int64 v5; // r12
  unsigned __int64 v6; // rdi
  Scaleform::GFx::AS3::Impl::SparseArray *v7; // rsi
  unsigned __int64 v8; // rax
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *v9; // r15
  __int64 v10; // rsi
  unsigned __int64 v11; // r12
  char *v12; // r13
  unsigned __int64 v13; // r14
  signed __int64 v14; // rax
  signed __int64 v15; // rbx
  unsigned __int64 v16; // r8
  unsigned __int64 v17; // rdx
  unsigned __int64 v18; // rbx
  unsigned __int64 v19; // r8
  __int64 v20; // rdi
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v21; // rax
  unsigned __int64 v22; // rdx
  __int64 v23; // rbx
  Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef key; // [rsp+28h] [rbp-50h]
  Scaleform::GFx::AS3::Impl::SparseArray *v25; // [rsp+80h] [rbp+8h]
  Scaleform::GFx::AS3::Value *v26; // [rsp+88h] [rbp+10h]
  unsigned int v27; // [rsp+90h] [rbp+18h]

  v27 = argc;
  v25 = this;
  v4 = argv;
  v5 = argc;
  v6 = pos;
  v7 = this;
  v8 = this->ValueA.Data.Size;
  if ( pos >= v8 )
  {
    if ( pos == v8 )
    {
      if ( argc )
      {
        v20 = argc;
        do
        {
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
            (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v7->ValueA.Data.Data,
            v7->ValueA.Data.pHeap,
            v7->ValueA.Data.Size + 1);
          Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
            &v7->ValueA.Data.Data[v7->ValueA.Data.Size - 1],
            v4);
          ++v4;
          --v20;
        }
        while ( v20 );
      }
      v21 = v7->ValueH.mHash.pTable;
      if ( v21 && v21->EntryCount )
      {
        v18 = v5;
        v19 = v5;
        v17 = v7->ValueHLowInd;
        goto LABEL_22;
      }
    }
    else
    {
      v22 = this->ValueHLowInd;
      v23 = argc;
      if ( v6 >= v22 )
      {
        if ( v6 > this->ValueHHighInd )
        {
          this->ValueHHighInd = argc + v6 - 1;
        }
        else
        {
          Scaleform::GFx::AS3::Impl::SparseArray::MoveHashRight(this, v6, argc);
          v7->ValueHHighInd += v5;
        }
      }
      else
      {
        Scaleform::GFx::AS3::Impl::SparseArray::MoveHashRight(this, v22, argc);
        v7->ValueHLowInd = v6;
        v7->ValueHHighInd += v5;
      }
      if ( (_DWORD)v5 )
      {
        key.pFirst = (const unsigned __int64 *)&v25;
        do
        {
          v25 = (Scaleform::GFx::AS3::Impl::SparseArray *)v6;
          key.pSecond = v4;
          Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
            (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v7->ValueH.mHash.pTable,
            v7->ValueH.mHash.pHeap,
            &key);
          ++v6;
          ++v4;
          --v23;
        }
        while ( v23 );
      }
    }
  }
  else
  {
    if ( argc )
    {
      v9 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&this->ValueA.Data.Data;
      v10 = (unsigned int)v5;
      v11 = 32 * pos - (_QWORD)argv;
      do
      {
        v12 = (char *)v4 + v11;
        v13 = v9->Size;
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          v9,
          v9[1].Data,
          v13 + 1);
        if ( v13 + 1 > v13 )
        {
          v14 = (signed __int64)&v9->Data[v13];
          v26 = &v9->Data[v13];
          v15 = 1i64;
          do
          {
            key.pFirst = (const unsigned __int64 *)v14;
            if ( v14 )
            {
              *(_DWORD *)v14 = 0;
              *(_QWORD *)(v14 + 8) = 0i64;
            }
            v14 += 32i64;
            v26 = (Scaleform::GFx::AS3::Value *)v14;
            --v15;
          }
          while ( v15 );
        }
        v16 = v9->Size;
        if ( v6 < v16 - 1 )
          memmove(&v12[(unsigned __int64)v9->Data + 32], &v12[(unsigned __int64)v9->Data], 32 * (v16 - v6 - 1));
        Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(&v12[(unsigned __int64)v9->Data], v4);
        ++v6;
        ++v4;
        --v10;
      }
      while ( v10 );
      v7 = v25;
      LODWORD(v5) = v27;
    }
    v17 = v7->ValueHLowInd;
    if ( v17 )
    {
      v18 = (unsigned int)v5;
      v19 = (unsigned int)v5;
LABEL_22:
      Scaleform::GFx::AS3::Impl::SparseArray::MoveHashRight(v7, v17, v19);
      v7->ValueHLowInd += v18;
      v7->ValueHHighInd += v18;
      goto LABEL_31;
    }
  }
LABEL_31:
  v7->Length += (unsigned int)v5;
}

// File Line: 502
// RVA: 0x811F90
void __fastcall Scaleform::GFx::AS3::Impl::SparseArray::RemoveMultipleAt(Scaleform::GFx::AS3::Impl::SparseArray *this, unsigned __int64 pos, unsigned __int64 count, Scaleform::GFx::AS3::Impl::SparseArray::OP op)
{
  unsigned __int64 v4; // rsi
  Scaleform::GFx::AS3::Impl::SparseArray::OP v5; // er12
  unsigned __int64 v6; // rbp
  unsigned __int64 v7; // rdi
  Scaleform::GFx::AS3::Impl::SparseArray *v8; // rbx
  unsigned __int64 v9; // rax
  unsigned __int64 v10; // r14
  void *v11; // rdx
  unsigned __int64 v12; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v13; // rax
  unsigned __int64 v14; // rdx
  unsigned __int64 v15; // rsi
  unsigned __int64 v16; // rax
  bool v17; // cf
  unsigned __int64 v18; // rax
  Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef key; // [rsp+20h] [rbp-38h]
  unsigned __int64 v20; // [rsp+70h] [rbp+18h]

  if ( !count )
    return;
  v4 = this->ValueA.Data.Size;
  v5 = op;
  v6 = count;
  v7 = pos;
  v8 = this;
  if ( pos < v4 )
  {
    v9 = pos + count;
    v10 = v4 - pos;
    if ( pos + count < v4 )
    {
      v20 = pos + count;
      key.pFirst = &v20;
      do
      {
        if ( !v8->ValueHLowInd )
          v8->ValueHLowInd = v9;
        v11 = v8->ValueH.mHash.pHeap;
        key.pSecond = &v8->ValueA.Data.Data[v9];
        Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
          (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v8->ValueH.mHash.pTable,
          v11,
          &key);
        v12 = v20;
        if ( v8->ValueHHighInd < v20 )
          v8->ValueHHighInd = v20;
        v9 = v12 + 1;
        v20 = v9;
      }
      while ( v9 < v4 );
    }
    Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::RemoveMultipleAt(
      (Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> > *)&v8->ValueA.Data,
      v7,
      v10);
  }
  v13 = v8->ValueH.mHash.pTable;
  if ( v13 )
  {
    if ( v13->EntryCount )
    {
      v14 = v8->ValueHLowInd;
      v15 = v7 + v6;
      if ( v14 < v7 + v6 )
      {
        v16 = v8->ValueHHighInd;
        if ( v16 >= v7 )
        {
          v17 = v14 < v7;
          if ( v14 >= v7 )
          {
            if ( v16 < v15 )
            {
              Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Clear((Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v8->ValueH.mHash.pTable);
              v18 = 0i64;
              v8->ValueHHighInd = 0i64;
LABEL_25:
              v8->ValueHLowInd = v18;
              goto LABEL_26;
            }
            v17 = v14 < v7;
          }
          if ( v17 )
            v14 = v7;
          Scaleform::GFx::AS3::Impl::SparseArray::RemoveHash(v8, v14, v6);
          if ( v8->ValueHHighInd < v15 )
            v8->ValueHHighInd = Scaleform::GFx::AS3::Impl::SparseArray::GetLeftEqualInd(v8, v7);
          if ( v8->ValueHLowInd < v7 )
            goto LABEL_26;
          v18 = Scaleform::GFx::AS3::Impl::SparseArray::GetRightEqualInd(v8, v7 + v6, v8->ValueHHighInd);
          goto LABEL_25;
        }
      }
    }
  }
LABEL_26:
  if ( v5 == opCut && v8->Length <= v7 + v6 )
    v8->Length = v7;
}

// File Line: 572
// RVA: 0x7EB8E0
signed __int64 __fastcall Scaleform::GFx::AS3::Impl::SparseArray::GetLeftEqualInd(Scaleform::GFx::AS3::Impl::SparseArray *this, unsigned __int64 start_from)
{
  signed __int64 v2; // r8
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v3; // r9
  signed __int64 v4; // rcx
  signed __int64 v5; // rdx
  __int64 v6; // rax
  signed __int64 v7; // rax
  unsigned __int64 v8; // rdx
  signed __int64 v9; // rcx
  unsigned __int64 *v10; // rax
  char v12; // [rsp+Fh] [rbp+Fh]
  __int64 v13; // [rsp+10h] [rbp+10h]

  v2 = start_from;
  if ( (start_from & 0x8000000000000000ui64) == 0i64 )
  {
    v3 = this->ValueH.mHash.pTable;
    do
    {
      v13 = v2;
      if ( v3 )
      {
        v4 = 5381i64;
        v5 = 8i64;
        do
        {
          v6 = (unsigned __int8)*(&v12 + v5--);
          v7 = 65599 * v4 + v6;
          v4 = v7;
        }
        while ( v5 );
        v8 = v7 & v3->SizeMask;
        v9 = v8;
        v10 = &v3[1].EntryCount + 7 * v8;
        if ( *v10 != -2i64 && v10[1] == v8 )
        {
          while ( v10[1] != v8 || v10[2] != v2 )
          {
            v9 = *v10;
            if ( *v10 == -1i64 )
              goto LABEL_14;
            v10 = &v3[1].EntryCount + 7 * v9;
          }
          if ( v9 >= 0
            && (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *)((char *)&v3[2] + 56 * v9) )
          {
            break;
          }
        }
      }
LABEL_14:
      --v2;
    }
    while ( v2 >= 0 );
  }
  return v2;
}

// File Line: 585
// RVA: 0x7EEE60
unsigned __int64 __fastcall Scaleform::GFx::AS3::Impl::SparseArray::GetRightEqualInd(Scaleform::GFx::AS3::Impl::SparseArray *this, unsigned __int64 start_from, unsigned __int64 end_ind)
{
  unsigned __int64 v3; // r9
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v4; // r10
  signed __int64 v5; // rcx
  signed __int64 v6; // rdx
  __int64 v7; // rax
  signed __int64 v8; // rax
  unsigned __int64 v9; // rdx
  signed __int64 v10; // rcx
  unsigned __int64 *v11; // rax
  char v13; // [rsp+Fh] [rbp+Fh]
  unsigned __int64 v14; // [rsp+10h] [rbp+10h]

  v3 = start_from;
  v14 = start_from;
  if ( start_from <= end_ind )
  {
    v4 = this->ValueH.mHash.pTable;
    do
    {
      if ( v4 )
      {
        v5 = 5381i64;
        v6 = 8i64;
        do
        {
          v7 = (unsigned __int8)*(&v13 + v6--);
          v8 = 65599 * v5 + v7;
          v5 = v8;
        }
        while ( v6 );
        v9 = v8 & v4->SizeMask;
        v10 = v9;
        v11 = &v4[1].EntryCount + 7 * v9;
        if ( *v11 != -2i64 && v11[1] == v9 )
        {
          while ( v11[1] != v9 || v11[2] != v3 )
          {
            v10 = *v11;
            if ( *v11 == -1i64 )
              goto LABEL_14;
            v11 = &v4[1].EntryCount + 7 * v10;
          }
          if ( v10 >= 0
            && (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *)((char *)&v4[2] + 56 * v10) )
          {
            break;
          }
        }
      }
LABEL_14:
      v14 = ++v3;
    }
    while ( v3 <= end_ind );
  }
  return v3;
}

// File Line: 599
// RVA: 0x7BFEB0
void __fastcall Scaleform::GFx::AS3::Impl::SparseArray::CutMultipleAt(Scaleform::GFx::AS3::Impl::SparseArray *this, unsigned __int64 pos, unsigned __int64 count, Scaleform::GFx::AS3::Impl::SparseArray *deleted)
{
  unsigned __int64 v4; // r14
  Scaleform::GFx::AS3::Impl::SparseArray *v5; // r15
  unsigned __int64 v6; // r12
  unsigned __int64 v7; // rbp
  Scaleform::GFx::AS3::Impl::SparseArray *v8; // rbx
  unsigned __int64 v9; // r14
  unsigned __int64 v10; // rdi
  unsigned __int64 v11; // rsi
  unsigned __int64 v12; // rax

  if ( count )
  {
    v4 = this->ValueA.Data.Size;
    v5 = deleted;
    v6 = count;
    v7 = pos;
    v8 = this;
    if ( pos < v4 )
    {
      v9 = v4 - pos;
      if ( count < v9 )
        v9 = count;
      if ( deleted && pos < v9 + pos )
      {
        v10 = pos;
        v11 = v9;
        do
        {
          Scaleform::GFx::AS3::Impl::SparseArray::PushBack(v5, &v8->ValueA.Data.Data[v10]);
          ++v10;
          --v11;
        }
        while ( v11 );
      }
      Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::RemoveMultipleAt(
        (Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> > *)&v8->ValueA.Data,
        v7,
        v9);
    }
    Scaleform::GFx::AS3::Impl::SparseArray::CutHash(v8, v7, v6, v5);
    v12 = v8->ValueHHighInd;
    if ( v12 )
      v8->Length = v12 + 1;
    else
      v8->Length = v8->ValueA.Data.Size;
  }
}

// File Line: 624
// RVA: 0x7B1C00
Scaleform::GFx::AS3::Value *__fastcall Scaleform::GFx::AS3::Impl::SparseArray::At(Scaleform::GFx::AS3::Impl::SparseArray *this, unsigned __int64 ind)
{
  Scaleform::GFx::AS3::Impl::SparseArray *v2; // rbx
  Scaleform::GFx::AS3::Value *result; // rax
  signed __int64 v4; // rax
  signed __int64 v5; // rax
  unsigned __int64 key; // [rsp+38h] [rbp+10h]

  key = ind;
  v2 = this;
  if ( ind < this->ValueA.Data.Size )
    return &this->ValueA.Data.Data[ind];
  if ( ind < this->ValueHLowInd || ind > this->ValueHHighInd )
    return &this->DefaultValue;
  v4 = Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::findIndexAlt<unsigned __int64>(
         (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&this->ValueH.mHash.pTable,
         &key);
  if ( v4 < 0
    || (v5 = (signed __int64)&v2->ValueH.mHash.pTable[2] + 56 * v4) == 0
    || (result = (Scaleform::GFx::AS3::Value *)(v5 + 8)) == 0i64 )
  {
    result = &v2->DefaultValue;
  }
  return result;
}

// File Line: 644
// RVA: 0x818030
void __fastcall Scaleform::GFx::AS3::Impl::SparseArray::Set(Scaleform::GFx::AS3::Impl::SparseArray *this, unsigned __int64 ind, Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::Value *v3; // rsi
  unsigned __int64 v4; // rax
  Scaleform::GFx::AS3::Impl::SparseArray *v5; // rdi
  unsigned __int64 v6; // rcx
  void *v7; // rdx
  unsigned __int64 v8; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v9; // rcx
  Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef key; // [rsp+20h] [rbp-18h]
  unsigned __int64 v11; // [rsp+48h] [rbp+10h]

  v11 = ind;
  v3 = v;
  v4 = ind;
  v5 = this;
  if ( ind >= this->Length )
  {
    Scaleform::GFx::AS3::Impl::SparseArray::Resize(this, ind + 1);
    v4 = v11;
  }
  v6 = v5->ValueA.Data.Size;
  if ( v4 >= v6 )
  {
    if ( v4 == v6 )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v5->ValueA.Data.Data,
        v5->ValueA.Data.pHeap,
        v6 + 1);
      Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
        &v5->ValueA.Data.Data[v5->ValueA.Data.Size - 1],
        v3);
      Scaleform::GFx::AS3::Impl::SparseArray::Optimize(v5);
    }
    else
    {
      v7 = v5->ValueH.mHash.pHeap;
      key.pFirst = &v11;
      key.pSecond = v3;
      Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
        (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v5->ValueH.mHash.pTable,
        v7,
        &key);
      v8 = v11;
      if ( v11 < v5->ValueHLowInd || (v9 = v5->ValueH.mHash.pTable) != 0i64 && v9->EntryCount == 1 )
        v5->ValueHLowInd = v11;
      if ( v8 > v5->ValueHHighInd )
        v5->ValueHHighInd = v8;
    }
  }
  else
  {
    Scaleform::GFx::AS3::Value::Assign(&v5->ValueA.Data.Data[v4], v3);
  }
}

// File Line: 671
// RVA: 0x7AFCC0
void __fastcall Scaleform::GFx::AS3::Impl::SparseArray::AdjustValueHLowInd(Scaleform::GFx::AS3::Impl::SparseArray *this)
{
  Scaleform::GFx::AS3::Impl::SparseArray *v1; // rbp
  unsigned int v2; // edi
  Scaleform::GFx::AS3::WeakProxy *v3; // rdx
  signed __int64 v4; // rax
  signed __int64 v5; // rdx
  int v6; // ecx
  bool v7; // zf
  Scaleform::GFx::ASStringNode *v8; // rcx
  long double v9; // rcx
  int v10; // eax
  Scaleform::GFx::AS3::Value v11; // [rsp+28h] [rbp-30h]

  v1 = this;
  v2 = 0;
  v11.Flags = 0;
  v3 = 0i64;
  v11.Bonus.pWeakProxy = 0i64;
  if ( this->ValueHLowInd <= this->ValueHHighInd )
  {
    do
    {
      v4 = Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::findIndexAlt<unsigned __int64>(
             (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v1->ValueH.mHash.pTable,
             &v1->ValueHLowInd);
      if ( v4 >= 0 )
      {
        v5 = (signed __int64)&v1->ValueH.mHash.pTable[2] + 56 * v4;
        if ( v5 )
        {
          Scaleform::GFx::AS3::Value::Assign(&v11, (Scaleform::GFx::AS3::Value *)(v5 + 8));
          v2 = v11.Flags;
          if ( v11.Flags & 0x1F )
            break;
          Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::RemoveAlt<unsigned __int64>(
            (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v1->ValueH.mHash.pTable,
            &v1->ValueHLowInd);
        }
      }
      ++v1->ValueHLowInd;
    }
    while ( v1->ValueHLowInd <= v1->ValueHHighInd );
    v3 = v11.Bonus.pWeakProxy;
  }
  v6 = v2 & 0x1F;
  if ( v6 > 9 )
  {
    if ( (v2 >> 9) & 1 )
    {
      v7 = v3->RefCount-- == 1;
      if ( v7 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v11.Bonus.pWeakProxy = 0i64;
      v11.value = 0ui64;
      v11.Flags = v2 & 0xFFFFFDE0;
    }
    else
    {
      switch ( v6 )
      {
        case 10:
          v8 = v11.value.VS._1.VStr;
          v7 = *(_DWORD *)(*(_QWORD *)&v11.value.VNumber + 24i64) == 1;
          --v8->RefCount;
          if ( v7 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v8);
          break;
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
          if ( !v11.value.VS._1.VBool )
          {
            v9 = v11.value.VNumber;
            goto LABEL_22;
          }
          --*(_QWORD *)&v11.value.VNumber;
          break;
        case 16:
        case 17:
          if ( (_QWORD)v11.value.VS._2.VObj & 1 )
          {
            --v11.value.VS._2.VObj;
          }
          else
          {
            v9 = *(double *)&v11.value.VS._2.VObj;
LABEL_22:
            if ( v9 != 0.0 )
            {
              v10 = *(_DWORD *)(*(_QWORD *)&v9 + 32i64);
              if ( v10 & 0x3FFFFF )
              {
                *(_DWORD *)(*(_QWORD *)&v9 + 32i64) = v10 - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(*(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v9);
              }
            }
          }
          break;
        default:
          return;
      }
    }
  }
}

// File Line: 697
// RVA: 0x805930
void __fastcall Scaleform::GFx::AS3::Impl::SparseArray::Optimize(Scaleform::GFx::AS3::Impl::SparseArray *this)
{
  Scaleform::GFx::AS3::Impl::SparseArray *v1; // rbp
  unsigned int v2; // er14
  Scaleform::GFx::AS3::WeakProxy *v3; // rbx
  bool i; // zf
  unsigned __int64 v5; // r9
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v6; // r8
  signed __int64 v7; // rdx
  signed __int64 v8; // rcx
  signed __int64 v9; // rax
  signed __int64 v10; // rdx
  signed __int64 v11; // rcx
  unsigned __int64 *v12; // rax
  signed __int64 v13; // rdx
  int v14; // edi
  signed __int64 v15; // rcx
  signed __int64 v16; // rdx
  signed __int64 v17; // rdx
  long double v18; // rcx
  Scaleform::GFx::AS3::Value::V2U v19; // r8
  Scaleform::GFx::AS3::Value v20; // [rsp+28h] [rbp-50h]

  v1 = this;
  v2 = 0;
  v20.Flags = 0;
  v3 = 0i64;
  v20.Bonus.pWeakProxy = 0i64;
  for ( i = this->ValueA.Data.Size == this->ValueHLowInd; i; i = v1->ValueA.Data.Size == v1->ValueHLowInd )
  {
    v5 = v1->ValueHLowInd;
    if ( v5 > v1->ValueHHighInd )
      break;
    v6 = v1->ValueH.mHash.pTable;
    if ( !v6 )
      goto LABEL_30;
    v7 = 8i64;
    v8 = 5381i64;
    do
    {
      v9 = 65599 * v8 + *((unsigned __int8 *)&v1->ValueHLowInd + --v7);
      v8 = 65599 * v8 + *((unsigned __int8 *)&v1->ValueHLowInd + v7);
    }
    while ( v7 );
    v10 = v9 & v6->SizeMask;
    v11 = v9 & v6->SizeMask;
    v12 = &v6[1].EntryCount + 7 * (v9 & v6->SizeMask);
    if ( *v12 == -2i64 || v12[1] != v10 )
      goto LABEL_30;
    while ( v12[1] != v10 || v12[2] != v5 )
    {
      v11 = *v12;
      if ( *v12 == -1i64 )
        goto LABEL_30;
      v12 = &v6[1].EntryCount + 7 * v11;
    }
    if ( v11 >= 0 && (v13 = (signed __int64)&v6[2] + 56 * v11) != 0 )
    {
      Scaleform::GFx::AS3::Value::Assign(&v20, (Scaleform::GFx::AS3::Value *)(v13 + 8));
      Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::RemoveAlt<unsigned __int64>(
        (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v1->ValueH.mHash.pTable,
        &v1->ValueHLowInd);
      ++v1->ValueHLowInd;
      v2 = v20.Flags;
      v14 = v20.Flags & 0x1F;
      if ( !(v20.Flags & 0x1F) )
      {
        Scaleform::GFx::AS3::Impl::SparseArray::AdjustValueHLowInd(v1);
        v3 = v20.Bonus.pWeakProxy;
        break;
      }
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v1->ValueA.Data.Data,
        v1->ValueA.Data.pHeap,
        v1->ValueA.Data.Size + 1);
      v15 = 32 * v1->ValueA.Data.Size;
      v16 = (signed __int64)&v1->ValueA.Data.Data[-1];
      i = v15 + v16 == 0;
      v17 = v15 + v16;
      v3 = v20.Bonus.pWeakProxy;
      if ( !i )
      {
        *(_DWORD *)v17 = v2;
        *(_QWORD *)(v17 + 8) = v3;
        v18 = v20.value.VNumber;
        *(long double *)(v17 + 16) = v20.value.VNumber;
        v19.VObj = (Scaleform::GFx::AS3::Object *)v20.value.VS._2;
        *(_QWORD *)(v17 + 24) = v20.value.VS._2.VObj;
        if ( v14 > 9 )
        {
          if ( (v2 >> 9) & 1 )
          {
            ++v3->RefCount;
          }
          else if ( v14 == 10 )
          {
            ++*(_DWORD *)(*(_QWORD *)&v18 + 24i64);
          }
          else if ( v14 > 10 )
          {
            if ( v14 <= 15 )
            {
              if ( v18 != 0.0 )
                *(_DWORD *)(*(_QWORD *)&v18 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v18 + 32i64) + 1) & 0x8FBFFFFF;
            }
            else if ( v14 <= 17 )
            {
              if ( v19.VObj )
                v19.VObj->RefCount = (v19.VObj->RefCount + 1) & 0x8FBFFFFF;
            }
          }
        }
      }
    }
    else
    {
LABEL_30:
      v1->ValueHLowInd = v5 + 1;
      Scaleform::GFx::AS3::Impl::SparseArray::AdjustValueHLowInd(v1);
    }
  }
  if ( v1->ValueHLowInd > v1->ValueHHighInd )
  {
    Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Clear((Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v1->ValueH.mHash.pTable);
    v1->ValueHLowInd = 0i64;
    v1->ValueHHighInd = 0i64;
  }
  if ( (char)(v2 & 0x1F) > 9 )
  {
    if ( (v2 >> 9) & 1 )
    {
      i = v3->RefCount-- == 1;
      if ( i )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v3);
      v20.Bonus.pWeakProxy = 0i64;
      v20.value = 0ui64;
      v20.Flags = v2 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v20);
    }
  }
}

// File Line: 734
// RVA: 0x816630
void __fastcall Scaleform::GFx::AS3::Impl::SparseArray::Reverse(Scaleform::GFx::AS3::Impl::SparseArray *this)
{
  Scaleform::GFx::AS3::Impl::SparseArray *v1; // r14
  unsigned __int64 v2; // rsi
  unsigned int v3; // er15
  unsigned __int64 v4; // rdi
  signed __int64 v5; // rcx
  int v6; // eax
  __int64 v7; // rdx
  Scaleform::GFx::AS3::Value *v8; // r8
  signed __int64 v9; // rax
  signed __int64 v10; // r8
  int v11; // ecx
  bool v12; // zf
  Scaleform::GFx::ASStringNode *v13; // rcx
  long double v14; // rcx
  int v15; // eax
  char v16; // si
  unsigned __int64 v17; // rbx
  unsigned __int64 v18; // r10
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v19; // r9
  signed __int64 v20; // rcx
  signed __int64 v21; // rdx
  unsigned __int64 v22; // r11
  signed __int64 v23; // rcx
  signed __int64 v24; // r8
  unsigned __int64 *v25; // rdx
  signed __int64 v26; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v27; // r9
  signed __int64 v28; // rcx
  signed __int64 v29; // rdx
  signed __int64 v30; // rax
  signed __int64 v31; // r8
  signed __int64 v32; // rdx
  unsigned __int64 *v33; // rcx
  signed __int64 v34; // rdx
  unsigned __int64 **v35; // r8
  signed __int64 v36; // rcx
  signed __int64 v37; // rdx
  signed __int64 v38; // rcx
  signed __int64 v39; // r8
  unsigned __int64 *v40; // rdx
  signed __int64 v41; // rdx
  signed __int64 v42; // rax
  int v43; // eax
  Scaleform::GFx::ASStringNode *v44; // rcx
  long double v45; // rcx
  int v46; // eax
  int v47; // eax
  Scaleform::GFx::ASStringNode *v48; // rcx
  long double v49; // rcx
  int v50; // eax
  Scaleform::GFx::AS3::Value v; // [rsp+20h] [rbp-79h]
  Scaleform::GFx::AS3::Value v52; // [rsp+40h] [rbp-59h]
  Scaleform::GFx::AS3::Value v53; // [rsp+60h] [rbp-39h]
  unsigned __int64 *v54; // [rsp+80h] [rbp-19h]
  Scaleform::GFx::AS3::Value *v55; // [rsp+88h] [rbp-11h]
  unsigned __int64 *v56; // [rsp+90h] [rbp-9h]
  Scaleform::GFx::AS3::Value *v57; // [rsp+98h] [rbp-1h]
  Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef v58; // [rsp+A0h] [rbp+7h]
  __int64 v59; // [rsp+B0h] [rbp+17h]
  unsigned __int64 ind; // [rsp+100h] [rbp+67h]
  unsigned __int64 key; // [rsp+108h] [rbp+6Fh]

  v59 = -2i64;
  v1 = this;
  v2 = this->ValueA.Data.Size;
  if ( this->Length == v2 )
  {
    Scaleform::Alg::ReverseArray<Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy>>(&this->ValueA);
    return;
  }
  v3 = 0;
  ind = this->Length - 1;
  if ( v2 )
  {
    v4 = 0i64;
    do
    {
      v5 = (signed __int64)&v1->ValueA.Data.Data[v4];
      v.Flags = *(_DWORD *)v5;
      v.Bonus.pWeakProxy = *(Scaleform::GFx::AS3::WeakProxy **)(v5 + 8);
      v.value = *(Scaleform::GFx::AS3::Value::VU *)(v5 + 16);
      v6 = *(_DWORD *)v5 & 0x1F;
      if ( v6 > 9 )
      {
        if ( (*(_DWORD *)v5 >> 9) & 1 )
        {
          ++**(_DWORD **)(v5 + 8);
        }
        else if ( v6 == 10 )
        {
          ++*(_DWORD *)(*(_QWORD *)(v5 + 16) + 24i64);
        }
        else if ( v6 > 10 )
        {
          if ( v6 <= 15 )
          {
            v7 = *(_QWORD *)(v5 + 16);
LABEL_14:
            if ( v7 )
              *(_DWORD *)(v7 + 32) = (*(_DWORD *)(v7 + 32) + 1) & 0x8FBFFFFF;
            goto LABEL_17;
          }
          if ( v6 <= 17 )
          {
            v7 = *(_QWORD *)(v5 + 24);
            goto LABEL_14;
          }
        }
      }
LABEL_17:
      key = ind;
      if ( ind >= v1->ValueA.Data.Size )
      {
        if ( ind < v1->ValueHLowInd
          || ind > v1->ValueHHighInd
          || (v9 = Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::findIndexAlt<unsigned __int64>(
                     (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v1->ValueH.mHash.pTable,
                     &key),
              v9 < 0)
          || (v10 = (signed __int64)&v1->ValueH.mHash.pTable[2] + 56 * v9) == 0
          || (v8 = (Scaleform::GFx::AS3::Value *)(v10 + 8)) == 0i64 )
        {
          v8 = &v1->DefaultValue;
        }
      }
      else
      {
        v8 = &v1->ValueA.Data.Data[ind];
      }
      Scaleform::GFx::AS3::Impl::SparseArray::Set(v1, v4, v8);
      Scaleform::GFx::AS3::Impl::SparseArray::Set(v1, ind, &v);
      v11 = v.Flags & 0x1F;
      if ( v11 > 9 )
      {
        if ( (v.Flags >> 9) & 1 )
        {
          v12 = v.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v12 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          v.Bonus.pWeakProxy = 0i64;
          v.value = 0ui64;
          v.Flags &= 0xFFFFFDE0;
        }
        else
        {
          switch ( v11 )
          {
            case 10:
              v13 = v.value.VS._1.VStr;
              v12 = *(_DWORD *)(*(_QWORD *)&v.value.VNumber + 24i64) == 1;
              --v13->RefCount;
              if ( v12 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v13);
              break;
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
              v14 = v.value.VNumber;
              if ( !v.value.VS._1.VBool )
                goto LABEL_37;
              --*(_QWORD *)&v.value.VNumber;
              break;
            case 16:
            case 17:
              v14 = *(double *)&v.value.VS._2.VObj;
              if ( (_QWORD)v.value.VS._2.VObj & 1 )
              {
                --v.value.VS._2.VObj;
              }
              else
              {
LABEL_37:
                if ( v14 != 0.0 )
                {
                  v15 = *(_DWORD *)(*(_QWORD *)&v14 + 32i64);
                  if ( v15 & 0x3FFFFF )
                  {
                    *(_DWORD *)(*(_QWORD *)&v14 + 32i64) = v15 - 1;
                    Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(*(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v14);
                  }
                }
              }
              break;
            default:
              break;
          }
        }
      }
      ++v3;
      --ind;
      v4 = v3;
    }
    while ( v3 < v2 );
  }
  v53.Flags = 0;
  v53.Bonus.pWeakProxy = 0i64;
  v52.Flags = 0;
  v52.Bonus.pWeakProxy = 0i64;
  v16 = 0;
  v17 = v3;
  v18 = ind;
  if ( v3 >= ind )
    goto LABEL_82;
  do
  {
    key = v17;
    v19 = v1->ValueH.mHash.pTable;
    if ( !v19 )
      goto LABEL_79;
    v20 = 5381i64;
    v21 = 8i64;
    do
      v20 = *((unsigned __int8 *)&key + --v21) + 65599 * v20;
    while ( v21 );
    v22 = v19->SizeMask;
    v23 = v22 & v20;
    v24 = v23;
    v25 = &v19[1].EntryCount + 7 * v23;
    if ( *v25 != -2i64 && v25[1] == v23 )
    {
      while ( v25[1] != v23 || v25[2] != v17 )
      {
        v24 = *v25;
        if ( *v25 == -1i64 )
          goto LABEL_66;
        v25 = &v19[1].EntryCount + 7 * v24;
      }
      if ( v24 >= 0 )
      {
        v26 = (signed __int64)&v19[2] + 56 * v24;
        if ( v26 )
        {
          Scaleform::GFx::AS3::Value::Assign(&v53, (Scaleform::GFx::AS3::Value *)(v26 + 8));
          v27 = v1->ValueH.mHash.pTable;
          if ( v27 )
          {
            v28 = 5381i64;
            v29 = 8i64;
            do
            {
              v30 = 65599 * v28 + *((unsigned __int8 *)&ind + --v29);
              v28 = 65599 * v28 + *((unsigned __int8 *)&ind + v29);
            }
            while ( v29 );
            v31 = v30 & v27->SizeMask;
            v32 = v30 & v27->SizeMask;
            v33 = &v27[1].EntryCount + 7 * (v30 & v27->SizeMask);
            if ( *v33 != -2i64 && v33[1] == v31 )
            {
              while ( v33[1] != v31 || v33[2] != ind )
              {
                v32 = *v33;
                if ( *v33 == -1i64 )
                  goto LABEL_65;
                v33 = &v27[1].EntryCount + 7 * v32;
              }
              if ( v32 >= 0 )
              {
                v34 = (signed __int64)&v27[2] + 56 * v32;
                if ( v34 )
                {
                  Scaleform::GFx::AS3::Value::Assign(&v52, (Scaleform::GFx::AS3::Value *)(v34 + 8));
                  v58.pFirst = &ind;
                  v58.pSecond = &v53;
                  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
                    (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v1->ValueH.mHash.pTable,
                    v1->ValueH.mHash.pHeap,
                    &v58);
                  v56 = &key;
                  v57 = &v52;
                  v35 = &v56;
                  goto LABEL_77;
                }
              }
            }
          }
LABEL_65:
          v16 = 1;
          key = v17;
          Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::RemoveAlt<unsigned __int64>(
            (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v1->ValueH.mHash.pTable,
            &key);
          v54 = &ind;
          v55 = &v53;
          v35 = &v54;
LABEL_78:
          Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
            (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v1->ValueH.mHash.pTable,
            v1->ValueH.mHash.pHeap,
            (Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef *)v35);
          v18 = ind;
          goto LABEL_79;
        }
      }
    }
LABEL_66:
    v36 = 5381i64;
    v37 = 8i64;
    do
      v36 = *((unsigned __int8 *)&ind + --v37) + 65599 * v36;
    while ( v37 );
    v38 = v22 & v36;
    v39 = v38;
    v40 = &v19[1].EntryCount + 7 * v38;
    if ( *v40 != -2i64 && v40[1] == v38 )
    {
      while ( v40[1] != v38 || v40[2] != v18 )
      {
        v39 = *v40;
        if ( *v40 == -1i64 )
          goto LABEL_79;
        v40 = &v19[1].EntryCount + 7 * v39;
      }
      if ( v39 >= 0 )
      {
        v41 = (signed __int64)&v19[2] + 56 * v39;
        if ( v41 )
        {
          Scaleform::GFx::AS3::Value::Assign(&v52, (Scaleform::GFx::AS3::Value *)(v41 + 8));
          v16 = 1;
          Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::RemoveAlt<unsigned __int64>(
            (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v1->ValueH.mHash.pTable,
            &ind);
          *(_QWORD *)&v.Flags = &key;
          v.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)&v52;
          v35 = (unsigned __int64 **)&v;
LABEL_77:
          key = v17;
          goto LABEL_78;
        }
      }
    }
LABEL_79:
    ++v3;
    ind = --v18;
    v17 = v3;
  }
  while ( v3 < v18 );
  if ( v16 )
  {
    v42 = Scaleform::GFx::AS3::Impl::SparseArray::GetLeftEqualInd(v1, v1->ValueHHighInd);
    v1->ValueHHighInd = v42;
    v1->ValueHLowInd = Scaleform::GFx::AS3::Impl::SparseArray::GetRightEqualInd(v1, 0i64, v42);
  }
LABEL_82:
  v43 = v52.Flags & 0x1F;
  if ( v43 > 9 )
  {
    if ( (v52.Flags >> 9) & 1 )
    {
      v12 = v52.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v12 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v52.Bonus.pWeakProxy = 0i64;
      v52.value = 0ui64;
      v52.Flags &= 0xFFFFFDE0;
    }
    else
    {
      switch ( v43 )
      {
        case 10:
          v44 = v52.value.VS._1.VStr;
          v12 = *(_DWORD *)(*(_QWORD *)&v52.value.VNumber + 24i64) == 1;
          --v44->RefCount;
          if ( v12 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v44);
          break;
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
          v45 = v52.value.VNumber;
          if ( !v52.value.VS._1.VBool )
            goto LABEL_94;
          --*(_QWORD *)&v52.value.VNumber;
          break;
        case 16:
        case 17:
          v45 = *(double *)&v52.value.VS._2.VObj;
          if ( (_QWORD)v52.value.VS._2.VObj & 1 )
          {
            --v52.value.VS._2.VObj;
          }
          else
          {
LABEL_94:
            if ( v45 != 0.0 )
            {
              v46 = *(_DWORD *)(*(_QWORD *)&v45 + 32i64);
              if ( v46 & 0x3FFFFF )
              {
                *(_DWORD *)(*(_QWORD *)&v45 + 32i64) = v46 - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(*(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v45);
              }
            }
          }
          break;
        default:
          break;
      }
    }
  }
  v47 = v53.Flags & 0x1F;
  if ( v47 > 9 )
  {
    if ( (v53.Flags >> 9) & 1 )
    {
      v12 = v53.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v12 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v53.Bonus.pWeakProxy = 0i64;
      v53.value = 0ui64;
      v53.Flags &= 0xFFFFFDE0;
    }
    else
    {
      switch ( v47 )
      {
        case 10:
          v48 = v53.value.VS._1.VStr;
          v12 = *(_DWORD *)(*(_QWORD *)&v53.value.VNumber + 24i64) == 1;
          --v48->RefCount;
          if ( v12 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v48);
          break;
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
          v49 = v53.value.VNumber;
          if ( !v53.value.VS._1.VBool )
            goto LABEL_109;
          --*(_QWORD *)&v53.value.VNumber;
          break;
        case 16:
        case 17:
          v49 = *(double *)&v53.value.VS._2.VObj;
          if ( (_QWORD)v53.value.VS._2.VObj & 1 )
          {
            --v53.value.VS._2.VObj;
          }
          else
          {
LABEL_109:
            if ( v49 != 0.0 )
            {
              v50 = *(_DWORD *)(*(_QWORD *)&v49 + 32i64);
              if ( v50 & 0x3FFFFF )
              {
                *(_DWORD *)(*(_QWORD *)&v49 + 32i64) = v50 - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(*(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v49);
              }
            }
          }
          break;
        default:
          return;
      }
    }
  }
}

// File Line: 827
// RVA: 0x7D6420
void __fastcall Scaleform::GFx::AS3::Impl::SparseArray::ForEachChild_GC(Scaleform::GFx::AS3::Impl::SparseArray *this, Scaleform::GFx::AS3::RefCountCollector<328> *prcc, void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  Scaleform::GFx::AS3::RefCountCollector<328> *v3; // rbp
  Scaleform::GFx::AS3::Impl::SparseArray *v4; // rbx
  void (__fastcall *v5)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **); // rsi
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v6; // rcx
  signed __int64 v7; // rbx
  unsigned __int64 v8; // rdx
  unsigned __int64 v9; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v10; // rcx
  __int64 v11; // rbx
  __int64 v12; // rdi
  __int64 v13; // rcx
  signed __int64 v14; // rdx
  int v15; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> **v16; // rdx
  signed __int64 v17; // rcx
  unsigned __int64 v18; // rcx
  _QWORD *v19; // rax
  __m128i v20; // [rsp+20h] [rbp-18h]

  v3 = prcc;
  v4 = this;
  v5 = op;
  Scaleform::GFx::AS3::ForEachChild_GC(prcc, &this->ValueA, op);
  v6 = v4->ValueH.mHash.pTable;
  v7 = (signed __int64)&v4->ValueH;
  if ( v6 )
  {
    v8 = v6->SizeMask;
    v9 = 0i64;
    v10 = v6 + 1;
    do
    {
      if ( v10->EntryCount != -2i64 )
        break;
      ++v9;
      v10 = (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *)((char *)v10 + 56);
    }
    while ( v9 <= v8 );
    v20.m128i_i64[0] = v7;
    v20.m128i_i64[1] = v9;
  }
  else
  {
    v20 = 0ui64;
  }
  _mm_store_si128(&v20, v20);
  v11 = v20.m128i_i64[1];
  v12 = v20.m128i_i64[0];
  while ( v12 )
  {
    v13 = *(_QWORD *)v12;
    if ( !*(_QWORD *)v12 || v11 > *(_QWORD *)(v13 + 8) )
      break;
    v14 = v13 + 56 * v11;
    v15 = *(_DWORD *)(v14 + 40) & 0x1F;
    if ( v15 <= 10 || (*(_DWORD *)(v14 + 40) >> 9) & 1 || v15 < 11 )
      goto LABEL_22;
    if ( v15 <= 15 )
    {
      v17 = v14 + 56;
      if ( !*(_QWORD *)(v14 + 56) )
        goto LABEL_22;
      v16 = 0i64;
      if ( (unsigned int)(v15 - 11) <= 4 )
        v16 = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)v17;
    }
    else
    {
      if ( v15 > 17 )
        goto LABEL_22;
      v16 = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)(v14 + 64);
      if ( !*v16 )
        goto LABEL_22;
    }
    v5(v3, v16);
LABEL_22:
    v18 = *(_QWORD *)(*(_QWORD *)v12 + 8i64);
    if ( v11 <= (signed __int64)v18 && ++v11 <= v18 )
    {
      v19 = (_QWORD *)(*(_QWORD *)v12 + 56 * v11 + 16);
      do
      {
        if ( *v19 != -2i64 )
          break;
        ++v11;
        v19 += 7;
      }
      while ( v11 <= v18 );
    }
  }
}

// File Line: 839
// RVA: 0x7EC9A0
Scaleform::GFx::AS3::AbsoluteIndex *__fastcall Scaleform::GFx::AS3::Impl::SparseArray::GetNextArrayIndex(Scaleform::GFx::AS3::Impl::SparseArray *this, Scaleform::GFx::AS3::AbsoluteIndex *result, Scaleform::GFx::AS3::AbsoluteIndex ind)
{
  Scaleform::GFx::AS3::AbsoluteIndex *v3; // r11
  Scaleform::GFx::AS3::Impl::SparseArray *v4; // r9
  Scaleform::GFx::AS3::AbsoluteIndex *v5; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v6; // rax
  unsigned __int64 v7; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v8; // rax
  unsigned __int64 v9; // rbx
  unsigned __int64 v10; // r8
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v11; // r10
  signed __int64 v12; // rcx
  signed __int64 v13; // rdx
  __int64 v14; // rax
  signed __int64 v15; // rax
  signed __int64 v16; // rdx
  signed __int64 v17; // rcx
  unsigned __int64 *v18; // rax
  char v19; // [rsp+1Fh] [rbp+1Fh]
  unsigned __int64 v20; // [rsp+20h] [rbp+20h]

  v3 = result;
  v4 = this;
  if ( ind.Index < 0 )
  {
    if ( this->ValueA.Data.Size )
    {
      result->Index = 0i64;
      return result;
    }
    v6 = this->ValueH.mHash.pTable;
    if ( v6 && v6->EntryCount )
    {
      result->Index = this->ValueHLowInd;
      return result;
    }
LABEL_29:
    v3->Index = -1i64;
    return v3;
  }
  v7 = this->ValueA.Data.Size;
  if ( ind.Index < v7 )
  {
    if ( LODWORD(ind.Index) != v7 - 1 )
    {
      v5 = result;
      result->Index = ind.Index + 1;
      return v5;
    }
    v8 = v4->ValueH.mHash.pTable;
    if ( v8 && v8->EntryCount )
    {
      result->Index = v4->ValueHLowInd;
      return result;
    }
  }
  if ( LODWORD(ind.Index) < v4->ValueHLowInd )
    goto LABEL_29;
  v9 = v4->ValueHHighInd;
  if ( LODWORD(ind.Index) > v9 )
    goto LABEL_29;
  v10 = (unsigned int)(LODWORD(ind.Index) + 1);
  v20 = v10;
  if ( v10 > v9 )
    goto LABEL_29;
  v11 = v4->ValueH.mHash.pTable;
  while ( 1 )
  {
    if ( v11 )
    {
      v12 = 5381i64;
      v13 = 8i64;
      do
      {
        v14 = (unsigned __int8)*(&v19 + v13--);
        v15 = 65599 * v12 + v14;
        v12 = v15;
      }
      while ( v13 );
      v16 = v15 & v11->SizeMask;
      v17 = v16;
      v18 = &v11[1].EntryCount + 7 * v16;
      if ( *v18 != -2i64 && v18[1] == v16 )
      {
        while ( v18[1] != v16 || v18[2] != v10 )
        {
          v17 = *v18;
          if ( *v18 == -1i64 )
            goto LABEL_28;
          v18 = &v11[1].EntryCount + 7 * v17;
        }
        if ( v17 >= 0
          && (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *)((char *)&v11[2] + 56 * v17) )
        {
          break;
        }
      }
    }
LABEL_28:
    v20 = ++v10;
    if ( v10 > v9 )
      goto LABEL_29;
  }
  v3->Index = v10;
  return v3;
}

// File Line: 882
// RVA: 0x7D7190
void __fastcall Scaleform::GFx::AS3::Impl::SparseArray::ForEachDense(Scaleform::GFx::AS3::Impl::SparseArray *this, Scaleform::GFx::AS3::Impl::ArrayFunc *f)
{
  unsigned __int64 v2; // rbp
  unsigned int v3; // ebx
  Scaleform::GFx::AS3::Impl::ArrayFunc *v4; // rdi
  Scaleform::GFx::AS3::Impl::SparseArray *v5; // rsi
  __int64 v6; // rax

  v2 = this->ValueA.Data.Size;
  v3 = 0;
  v4 = f;
  v5 = this;
  if ( v2 )
  {
    v6 = 0i64;
    do
    {
      v4->vfptr->operator()(v4, v3++, &v5->ValueA.Data.Data[v6]);
      v6 = v3;
    }
    while ( v3 < v2 );
  }
}

// File Line: 890
// RVA: 0x7D72A0
void __fastcall Scaleform::GFx::AS3::Impl::SparseArray::ForEachSparse(Scaleform::GFx::AS3::Impl::SparseArray *this, Scaleform::GFx::AS3::Impl::ArrayFunc *f)
{
  Scaleform::HashDH<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>,2,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *v2; // r8
  unsigned __int64 v3; // rax
  Scaleform::GFx::AS3::Impl::ArrayFunc *v4; // rsi
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v5; // rcx
  unsigned __int64 v6; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v7; // rcx
  __int64 v8; // rbx
  __int64 v9; // rdi
  __int64 v10; // rcx
  unsigned __int64 v11; // rcx
  _QWORD *v12; // rax
  __m128i v13; // [rsp+20h] [rbp-18h]

  v2 = &this->ValueH;
  v3 = 0i64;
  v4 = f;
  v5 = this->ValueH.mHash.pTable;
  if ( v5 )
  {
    v6 = v5->SizeMask;
    v7 = v5 + 1;
    do
    {
      if ( v7->EntryCount != -2i64 )
        break;
      ++v3;
      v7 = (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *)((char *)v7 + 56);
    }
    while ( v3 <= v6 );
    v13.m128i_i64[0] = (__int64)v2;
  }
  else
  {
    v13.m128i_i64[0] = 0i64;
  }
  v13.m128i_i64[1] = v3;
  _mm_store_si128(&v13, v13);
  v8 = v13.m128i_i64[1];
  v9 = v13.m128i_i64[0];
  while ( v9 )
  {
    v10 = *(_QWORD *)v9;
    if ( !*(_QWORD *)v9 || v8 > *(_QWORD *)(v10 + 8) )
      break;
    v4->vfptr->operator()(v4, *(_DWORD *)(56 * v8 + v10 + 32), (Scaleform::GFx::AS3::Value *)(56 * v8 + v10 + 40));
    v11 = *(_QWORD *)(*(_QWORD *)v9 + 8i64);
    if ( v8 <= (signed __int64)v11 && ++v8 <= v11 )
    {
      v12 = (_QWORD *)(*(_QWORD *)v9 + 56 * v8 + 16);
      do
      {
        if ( *v12 != -2i64 )
          break;
        ++v8;
        v12 += 7;
      }
      while ( v8 <= v11 );
    }
  }
}

// File Line: 902
// RVA: 0x7912B0
void __fastcall Scaleform::GFx::AS3::Impl::Value2StrCollector::operator()(Scaleform::GFx::AS3::Impl::Value2StrCollector *this, unsigned int ind, Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::Value *v3; // rdi
  unsigned int v4; // ebp
  Scaleform::GFx::AS3::Impl::Value2StrCollector *v5; // rsi
  Scaleform::GFx::ASStringNode *v6; // rbx
  bool v7; // zf
  Scaleform::GFx::ASStringNode *v8; // rcx
  Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const *,unsigned long> val; // [rsp+28h] [rbp-30h]
  Scaleform::GFx::AS3::CheckResult v10; // [rsp+60h] [rbp+8h]
  Scaleform::GFx::ASString result; // [rsp+78h] [rbp+20h]

  v3 = v;
  v4 = ind;
  v5 = this;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)this->Vm->StringManagerRef->Builtins,
    &result);
  if ( Scaleform::GFx::AS3::Value::Convert2String(v3, &v10, &result)->Result )
  {
    v6 = result.pNode;
    val.First = result;
    ++val.First.pNode->RefCount;
    val.Second = v3;
    val.Third = v4;
    Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
      &v5->Pairs->Data,
      &val);
    v7 = v6->RefCount-- == 1;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  }
  v8 = result.pNode;
  v7 = result.pNode->RefCount == 1;
  --v8->RefCount;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
}

// File Line: 914
// RVA: 0x791350
void __fastcall Scaleform::GFx::AS3::Impl::ValuePtrCollector::operator()(Scaleform::GFx::AS3::Impl::ValuePtrCollector *this, unsigned int ind, Scaleform::GFx::AS3::Value *v)
{
  Scaleform::ArrayDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2,Scaleform::ArrayDefaultPolicy> *v3; // rdi
  Scaleform::GFx::AS3::Value *v4; // rsi
  unsigned __int64 v5; // rbx
  unsigned __int64 v6; // r8
  Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long> *v7; // rcx
  Scaleform::GFx::AS3::Value **v8; // rcx
  Scaleform::GFx::AS3::Value *v9; // [rsp+28h] [rbp-10h]

  v3 = this->Pairs;
  LODWORD(v9) = ind;
  v4 = v;
  v5 = v3->Data.Size + 1;
  if ( v5 >= v3->Data.Size )
  {
    if ( v5 <= v3->Data.Policy.Capacity )
      goto LABEL_7;
    v6 = v5 + (v5 >> 2);
  }
  else
  {
    if ( v5 >= v3->Data.Policy.Capacity >> 1 )
      goto LABEL_7;
    v6 = v3->Data.Size + 1;
  }
  Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&v3->Data.Data,
    v3->Data.pHeap,
    v6);
LABEL_7:
  v7 = v3->Data.Data;
  v3->Data.Size = v5;
  v8 = &v7[v5 - 1].First;
  if ( v8 )
  {
    *v8 = v4;
    v8[1] = v9;
  }
}

// File Line: 920
// RVA: 0x7911E0
void __fastcall Scaleform::GFx::AS3::Impl::Value2NumberCollector::operator()(Scaleform::GFx::AS3::Impl::Value2NumberCollector *this, unsigned int ind, Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  unsigned int v4; // edi
  Scaleform::GFx::AS3::Impl::Value2NumberCollector *v5; // rsi
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *v6; // rdi
  long double v7; // xmm6_8
  unsigned __int64 v8; // rbx
  unsigned __int64 v9; // r8
  Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const *,unsigned long> *v10; // rax
  long double *v11; // rdx
  __int64 v12; // xmm0_8
  __int64 v13; // xmm1_8
  long double v14; // [rsp+20h] [rbp-38h]
  Scaleform::GFx::AS3::Value *v15; // [rsp+30h] [rbp-28h]
  __int64 v16; // [rsp+38h] [rbp-20h]
  Scaleform::GFx::AS3::CheckResult result; // [rsp+78h] [rbp+20h]

  v3 = v;
  v4 = ind;
  v5 = this;
  if ( Scaleform::GFx::AS3::Value::Convert2Number(v, &result, &v14)->Result )
  {
    v15 = v3;
    LODWORD(v16) = v4;
    v6 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)v5->Pairs;
    v7 = v14;
    v8 = v6->Size + 1;
    if ( v8 >= v6->Size )
    {
      if ( v8 <= v6->Policy.Capacity )
        goto LABEL_8;
      v9 = v8 + (v8 >> 2);
    }
    else
    {
      if ( v8 >= v6->Policy.Capacity >> 1 )
        goto LABEL_8;
      v9 = v6->Size + 1;
    }
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Impl::Triple<double,Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Impl::Triple<double,Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v6,
      v6[1].Data,
      v9);
LABEL_8:
    v10 = v6->Data;
    v6->Size = v8;
    v11 = (long double *)&v10[v8 - 1];
    if ( v11 )
    {
      v12 = (__int64)v15;
      v13 = v16;
      *v11 = v7;
      *((_QWORD *)v11 + 1) = v12;
      *((_QWORD *)v11 + 2) = v13;
    }
  }
}

// File Line: 970
// RVA: 0x76C670
Scaleform::GFx::AS3::Value *__fastcall Scaleform::GFx::AS3::Impl::GetMethodDefArg<Scaleform::GFx::AS3::Instances::fl_display::MovieClip,13,1,Scaleform::GFx::AS3::Value const &>(Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::StringManager *__formal)
{
  Scaleform::GFx::AS3::Value *v2; // rbx
  int v3; // eax
  long double v4; // rax

  v2 = result;
  if ( !(_S12_13 & 1) )
  {
    _S12_13 |= 1u;
    v_0.Flags = 12;
    v_0.Bonus.pWeakProxy = 0i64;
    v_0.value.VNumber = 0.0;
    atexit(Scaleform::GFx::AS3::Value::GetNull_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  v2->Flags = v_0.Flags;
  v2->Bonus.pWeakProxy = v_0.Bonus.pWeakProxy;
  v2->value = v_0.value;
  v3 = v_0.Flags & 0x1F;
  if ( v3 > 9 )
  {
    if ( (v_0.Flags >> 9) & 1 )
    {
      ++v_0.Bonus.pWeakProxy->RefCount;
    }
    else
    {
      if ( v3 == 10 )
      {
        ++*(_DWORD *)(*(_QWORD *)&v_0.value.VNumber + 24i64);
        return v2;
      }
      if ( v3 > 10 )
      {
        if ( v3 <= 15 )
        {
          v4 = v_0.value.VNumber;
        }
        else
        {
          if ( v3 > 17 )
            return v2;
          v4 = *(double *)&v_0.value.VS._2.VObj;
        }
        if ( v4 != 0.0 )
        {
          ++*(_DWORD *)(*(_QWORD *)&v4 + 32i64);
          *(_DWORD *)(*(_QWORD *)&v4 + 32i64) &= 0x8FBFFFFF;
        }
      }
    }
  }
  return v2;
}

// File Line: 1019
// RVA: 0x1587DC0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl::Array_0_unsigned_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AC10 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Array,0,unsigned long>::Method = Scaleform::GFx::AS3::Instances::fl_display::FrameLabel::frameGet;
  return result;
}

// File Line: 1020
// RVA: 0x158F080
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl::Array_1_Scaleform::GFx::AS3::Value_const__unsigned_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AC20 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl::Array,1,Scaleform::GFx::AS3::Value const,unsigned long>::Method = Scaleform::GFx::AS3::Instances::fl::Array::lengthSet;
  return result;
}

// File Line: 1021
// RVA: 0x15944E0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl::Array_2_Scaleform::GFx::AS3::Value_unsigned_int_Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AC30 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl::Array,2,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl::Array *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl::Array::AS3join;
  return result;
}

// File Line: 1022
// RVA: 0x1587D30
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl::Array_3_Scaleform::GFx::AS3::Value_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AC40 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Array,3,Scaleform::GFx::AS3::Value>::Method = Scaleform::GFx::AS3::Instances::fl::Array::AS3pop;
  return result;
}

// File Line: 1023
// RVA: 0x1594510
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl::Array_4_Scaleform::GFx::AS3::Value_unsigned_int_Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AC50 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl::Array,4,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl::Array *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl::Array::AS3push;
  return result;
}

// File Line: 1024
// RVA: 0x1587D60
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl::Array_5_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl::Array___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AC60 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Array,5,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array>>::Method = Scaleform::GFx::AS3::Instances::fl::Array::AS3reverse;
  return result;
}

// File Line: 1025
// RVA: 0x1594540
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl::Array_6_Scaleform::GFx::AS3::Value_unsigned_int_Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AC70 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl::Array,6,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl::Array *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl::Array::AS3concat;
  return result;
}

// File Line: 1026
// RVA: 0x1587D90
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl::Array_7_Scaleform::GFx::AS3::Value_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AC80 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Array,7,Scaleform::GFx::AS3::Value>::Method = Scaleform::GFx::AS3::Instances::fl::Array::AS3shift;
  return result;
}

// File Line: 1027
// RVA: 0x1594570
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl::Array_8_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl::Array__long_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AC90 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl::Array,8,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array>,long,long>::Method = Scaleform::GFx::AS3::Instances::fl::Array::AS3slice;
  return result;
}

// File Line: 1028
// RVA: 0x15945A0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl::Array_9_Scaleform::GFx::AS3::Value_unsigned_int_Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243ACA0 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl::Array,9,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl::Array *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl::Array::AS3unshift;
  return result;
}

// File Line: 1029
// RVA: 0x15945D0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl::Array_10_Scaleform::GFx::AS3::Value_unsigned_int_Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243ACB0 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl::Array,10,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl::Array *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl::Array::AS3splice;
  return result;
}

// File Line: 1030
// RVA: 0x15946C0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl::Array_11_Scaleform::GFx::AS3::Value_unsigned_int_Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243ACC0 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl::Array,11,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Instances::fl::Array *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl::Array::AS3sort;
  return result;
}

// File Line: 1031
// RVA: 0x15946F0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl::Array_12_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl::Array__Scaleform::GFx::AS3::Value_const_____ptr64_Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243ACD0 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl::Array,12,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array>,Scaleform::GFx::AS3::Value const &,Scaleform::GFx::AS3::Value const &>::Method = Scaleform::GFx::AS3::Instances::fl::Array::AS3sortOn;
  return result;
}

// File Line: 1032
// RVA: 0x1594720
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl::Array_13_long_Scaleform::GFx::AS3::Value_const_____ptr64_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243ACE0 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl::Array,13,long,Scaleform::GFx::AS3::Value const &,long>::Method = Scaleform::GFx::AS3::Instances::fl::Array::AS3indexOf;
  return result;
}

// File Line: 1033
// RVA: 0x1594750
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl::Array_14_long_Scaleform::GFx::AS3::Value_const_____ptr64_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243ACF0 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl::Array,14,long,Scaleform::GFx::AS3::Value const &,long>::Method = Scaleform::GFx::AS3::Instances::fl::Array::AS3lastIndexOf;
  return result;
}

// File Line: 1034
// RVA: 0x1594780
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl::Array_15_bool_Scaleform::GFx::AS3::Value_const_____ptr64_Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AD00 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl::Array,15,bool,Scaleform::GFx::AS3::Value const &,Scaleform::GFx::AS3::Value const &>::Method = Scaleform::GFx::AS3::Instances::fl::Array::AS3every;
  return result;
}

// File Line: 1035
// RVA: 0x1594600
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl::Array_16_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl::Array__Scaleform::GFx::AS3::Value_const_____ptr64_Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AD10 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl::Array,16,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array>,Scaleform::GFx::AS3::Value const &,Scaleform::GFx::AS3::Value const &>::Method = Scaleform::GFx::AS3::Instances::fl::Array::AS3filter;
  return result;
}

// File Line: 1036
// RVA: 0x1594630
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl::Array_17_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Value_const_____ptr64_Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AD20 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl::Array,17,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Value const &,Scaleform::GFx::AS3::Value const &>::Method = Scaleform::GFx::AS3::Instances::fl::Array::AS3forEach;
  return result;
}

// File Line: 1037
// RVA: 0x1594660
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl::Array_18_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl::Array__Scaleform::GFx::AS3::Value_const_____ptr64_Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AD30 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl::Array,18,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array>,Scaleform::GFx::AS3::Value const &,Scaleform::GFx::AS3::Value const &>::Method = Scaleform::GFx::AS3::Instances::fl::Array::AS3map;
  return result;
}

// File Line: 1038
// RVA: 0x1594690
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Instances::fl::Array_19_bool_Scaleform::GFx::AS3::Value_const_____ptr64_Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243AD40 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl::Array,19,bool,Scaleform::GFx::AS3::Value const &,Scaleform::GFx::AS3::Value const &>::Method = Scaleform::GFx::AS3::Instances::fl::Array::AS3some;
  return result;
}

// File Line: 1047
// RVA: 0x77ABB0
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::Array(Scaleform::GFx::AS3::Instances::fl::Array *this, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *v2; // rbx
  Scaleform::GFx::AS3::Instances::fl::Array *v3; // rdi
  Scaleform::MemoryHeap *v4; // rdx
  signed __int64 v5; // [rsp+58h] [rbp+10h]
  signed __int64 v6; // [rsp+60h] [rbp+18h]

  v2 = t;
  v3 = this;
  Scaleform::GFx::AS3::Instance::Instance((Scaleform::GFx::AS3::Instance *)&this->vfptr, t);
  v3->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable';
  v3->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Array::`vftable';
  v4 = v2->pVM->MHeap;
  v5 = (signed __int64)&v3->SA;
  *(_OWORD *)v5 = 0ui64;
  *(_QWORD *)(v5 + 16) = 0i64;
  *(_DWORD *)(v5 + 24) = 0;
  *(_QWORD *)(v5 + 32) = 0i64;
  v6 = (signed __int64)&v3->SA.ValueA;
  *(_OWORD *)v6 = 0ui64;
  *(_QWORD *)(v6 + 16) = 0i64;
  *(_QWORD *)(v5 + 80) = v4;
  v3->SA.ValueH.mHash.pTable = 0i64;
  *(_QWORD *)(v5 + 96) = v4;
}

// File Line: 1059
// RVA: 0x851810
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::lengthSet(Scaleform::GFx::AS3::Instances::fl::Array *this, Scaleform::GFx::AS3::Value *result, unsigned int newLength)
{
  Scaleform::GFx::AS3::Impl::SparseArray::Resize(&this->SA, newLength);
}

// File Line: 1066
// RVA: 0x79FCD0
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::AS3join(Scaleform::GFx::AS3::Instances::fl::Array *this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *const argv)
{
  Scaleform::GFx::AS3::Value *v4; // rdi
  Scaleform::GFx::AS3::Instances::fl::Array *v5; // rbx
  Scaleform::GFx::ASString *v6; // rax
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::GFx::ASStringNode *v9; // rcx
  Scaleform::GFx::ASString v10; // [rsp+20h] [rbp-18h]
  __int64 v11; // [rsp+28h] [rbp-10h]
  Scaleform::GFx::ASString sep; // [rsp+40h] [rbp+8h]
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+50h] [rbp+18h]

  v11 = -2i64;
  v4 = result;
  v5 = this;
  sep.pNode = this->pTraits.pObject->pVM->StringManagerRef->Builtins[14].pNode;
  ++sep.pNode->RefCount;
  if ( !argc || Scaleform::GFx::AS3::Value::Convert2String(argv, &resulta, &sep)->Result )
  {
    v6 = Scaleform::GFx::AS3::Instances::fl::Array::ToStringInternal(v5, &v10, &sep);
    Scaleform::GFx::AS3::Value::Assign(v4, v6);
    v7 = v10.pNode;
    v8 = v10.pNode->RefCount == 1;
    --v7->RefCount;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  }
  v9 = sep.pNode;
  v8 = sep.pNode->RefCount == 1;
  --v9->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
}

// File Line: 1087
// RVA: 0x7A1480
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::AS3pop(Scaleform::GFx::AS3::Instances::fl::Array *this, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Impl::SparseArray *v2; // rbx
  Scaleform::GFx::AS3::Value *v3; // rdi
  unsigned __int64 v4; // rdx
  Scaleform::GFx::AS3::Value *v5; // rax

  v2 = &this->SA;
  v3 = result;
  v4 = this->SA.Length;
  if ( v4 )
  {
    v5 = Scaleform::GFx::AS3::Impl::SparseArray::At(&this->SA, v4 - 1);
    Scaleform::GFx::AS3::Value::Assign(v3, v5);
    if ( v2->Length )
      Scaleform::GFx::AS3::Impl::SparseArray::RemoveMultipleAt(v2, v2->Length - 1, 1ui64, 0);
  }
}

// File Line: 1104
// RVA: 0x7A1D80
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::AS3push(Scaleform::GFx::AS3::Instances::fl::Array *this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *const argv)
{
  unsigned int *v4; // rbx
  Scaleform::GFx::AS3::Value *v5; // rdi

  v4 = (unsigned int *)&this->SA;
  v5 = result;
  Scaleform::GFx::AS3::Impl::SparseArray::Append(&this->SA, argc, argv);
  Scaleform::GFx::AS3::Value::SetUInt32(v5, *v4);
}

// File Line: 1118
// RVA: 0x7A25B0
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::AS3reverse(Scaleform::GFx::AS3::Instances::fl::Array *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *result)
{
  Scaleform::GFx::AS3::Instances::fl::Array *v2; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *v3; // rdi

  v2 = this;
  v3 = result;
  Scaleform::GFx::AS3::Impl::SparseArray::Reverse(&this->SA);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)v3,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)v2);
}

// File Line: 1132
// RVA: 0x79BE40
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::AS3concat(Scaleform::GFx::AS3::Instances::fl::Array *this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *const argv)
{
  Scaleform::GFx::AS3::Value *v4; // rdi
  Scaleform::GFx::AS3::Instances::fl::Array *v5; // rbp
  Scaleform::GFx::AS3::Value *v6; // rsi
  unsigned int v7; // er14
  Scaleform::GFx::AS3::Instances::fl::Array *v8; // rbx
  Scaleform::GFx::AS3::Traits *v9; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> resulta; // [rsp+40h] [rbp+8h]

  v4 = result;
  v5 = this;
  v6 = argv;
  v7 = argc;
  Scaleform::GFx::AS3::InstanceTraits::fl::Array::MakeInstance(
    &resulta,
    (Scaleform::GFx::AS3::InstanceTraits::fl::Array *)this->pTraits.pObject);
  v8 = resulta.pV;
  Scaleform::GFx::AS3::Value::Pick(v4, (Scaleform::GFx::AS3::Object *)&resulta.pV->vfptr);
  if ( v8 != v5 )
    Scaleform::GFx::AS3::Impl::SparseArray::Assign(&v8->SA, &v5->SA);
  if ( v7 == 1
    && (v9 = Scaleform::GFx::AS3::VM::GetValueTraits(v5->pTraits.pObject->pVM, v6), v9->TraitsType == 7)
    && ~(LOBYTE(v9->Flags) >> 5) & 1 )
  {
    Scaleform::GFx::AS3::Impl::SparseArray::Append(
      &v8->SA,
      (Scaleform::GFx::AS3::Impl::SparseArray *)(*(_QWORD *)&v6->value.VNumber + 56i64),
      0i64,
      *(_QWORD *)(*(_QWORD *)&v6->value.VNumber + 56i64));
  }
  else
  {
    Scaleform::GFx::AS3::Impl::SparseArray::Append(&v8->SA, v7, v6);
  }
}

// File Line: 1162
// RVA: 0x7A3CF0
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::AS3shift(Scaleform::GFx::AS3::Instances::fl::Array *this, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Impl::SparseArray *v2; // rbx
  Scaleform::GFx::AS3::Value *v3; // rdi
  Scaleform::GFx::AS3::Value *v4; // rax

  v2 = &this->SA;
  v3 = result;
  if ( this->SA.Length )
  {
    v4 = Scaleform::GFx::AS3::Impl::SparseArray::At(&this->SA, 0i64);
    Scaleform::GFx::AS3::Value::Assign(v3, v4);
    if ( v2->Length )
    {
      if ( v2->ValueA.Data.Size )
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
          (Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> > *)&v2->ValueA.Data,
          0i64);
      Scaleform::GFx::AS3::Impl::SparseArray::CutHash(v2, 0i64, 1ui64, 0i64);
      Scaleform::GFx::AS3::Impl::SparseArray::Optimize(v2);
      --v2->Length;
    }
  }
  else
  {
    Scaleform::GFx::AS3::Value::SetUndefined(result);
  }
}

// File Line: 1181
// RVA: 0x7A3D70
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::AS3slice(Scaleform::GFx::AS3::Instances::fl::Array *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *result, int startIndex, int endIndex)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *v4; // r15
  Scaleform::GFx::AS3::Instances::fl::Array *v5; // rdi
  int v6; // er14
  int v7; // esi
  Scaleform::GFx::AS3::Instances::fl::Array *v8; // rcx
  Scaleform::GFx::AS3::Instances::fl::Array *v9; // rbx
  unsigned int v10; // eax
  unsigned __int64 v11; // rax
  unsigned __int64 v12; // rbp
  signed __int64 v13; // r15
  __int64 v14; // r12
  Scaleform::GFx::AS3::Value *v15; // r14
  signed __int64 v16; // rax
  signed __int64 v17; // r14
  unsigned __int64 v18; // rcx
  Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef key; // [rsp+20h] [rbp-38h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> resulta; // [rsp+60h] [rbp+8h]

  v4 = result;
  v5 = this;
  v6 = endIndex;
  v7 = startIndex;
  Scaleform::GFx::AS3::InstanceTraits::fl::Array::MakeInstance(
    &resulta,
    (Scaleform::GFx::AS3::InstanceTraits::fl::Array *)this->pTraits.pObject);
  v8 = v4->pObject;
  v9 = resulta.pV;
  if ( resulta.pV != v4->pObject )
  {
    if ( v8 )
    {
      if ( (unsigned __int8)v8 & 1 )
      {
        v4->pObject = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)v8 - 1);
      }
      else
      {
        v10 = v8->RefCount;
        if ( v10 & 0x3FFFFF )
        {
          v8->RefCount = v10 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v8->vfptr);
        }
      }
    }
    v4->pObject = v9;
  }
  if ( v7 < 0 )
    v7 += LODWORD(v5->SA.Length);
  if ( v7 < 0 )
    v7 = 0;
  if ( v6 < 0 )
    v6 += LODWORD(v5->SA.Length);
  v11 = v5->SA.Length;
  if ( (signed int)v11 < v6 )
    v6 = v11;
  if ( v7 < v6 )
  {
    v12 = v7;
    v13 = v7;
    v14 = (unsigned int)(v6 - v7);
    do
    {
      resulta.pV = (Scaleform::GFx::AS3::Instances::fl::Array *)v12;
      if ( v12 >= v5->SA.ValueA.Data.Size )
      {
        if ( v12 < v5->SA.ValueHLowInd
          || v12 > v5->SA.ValueHHighInd
          || (v16 = Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::findIndexAlt<unsigned __int64>(
                      (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v5->SA.ValueH.mHash.pTable,
                      (const unsigned __int64 *)&resulta),
              v16 < 0)
          || (v17 = (signed __int64)&v5->SA.ValueH.mHash.pTable[2] + 56 * v16) == 0
          || (v15 = (Scaleform::GFx::AS3::Value *)(v17 + 8)) == 0i64 )
        {
          v15 = &v5->SA.DefaultValue;
        }
      }
      else
      {
        v15 = &v5->SA.ValueA.Data.Data[v13];
      }
      v18 = v9->SA.Length;
      if ( v18 == v9->SA.ValueA.Data.Size )
      {
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v9->SA.ValueA.Data.Data,
          v9->SA.ValueA.Data.pHeap,
          v9->SA.ValueA.Data.Size + 1);
        Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
          &v9->SA.ValueA.Data.Data[v9->SA.ValueA.Data.Size - 1],
          v15);
      }
      else
      {
        key.pSecond = v15;
        v9->SA.ValueHHighInd = v18;
        key.pFirst = &v9->SA.ValueHHighInd;
        Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
          (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v9->SA.ValueH.mHash.pTable,
          v9->SA.ValueH.mHash.pHeap,
          &key);
      }
      ++v9->SA.Length;
      ++v12;
      ++v13;
      --v14;
    }
    while ( v14 );
  }
}

// File Line: 1210
// RVA: 0x7A9140
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::AS3unshift(Scaleform::GFx::AS3::Instances::fl::Array *this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *const argv)
{
  unsigned int *v4; // rbx
  Scaleform::GFx::AS3::Value *v5; // rdi

  v4 = (unsigned int *)&this->SA;
  v5 = result;
  Scaleform::GFx::AS3::Impl::SparseArray::Insert(&this->SA, 0i64, argc, argv);
  Scaleform::GFx::AS3::Value::SetUInt32(v5, *v4);
}

// File Line: 1224
// RVA: 0x7A6370
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::AS3splice(Scaleform::GFx::AS3::Instances::fl::Array *this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *const argv)
{
  Scaleform::GFx::AS3::Impl::SparseArray *v4; // rdi
  Scaleform::GFx::AS3::Value *v5; // rbp
  unsigned int v6; // esi
  int v7; // eax
  Scaleform::GFx::AS3::Value *v8; // r15
  Scaleform::GFx::AS3::Instances::fl::Array *v9; // rbx
  int v10; // ecx
  Scaleform::GFx::AS3::Impl::SparseArray *v11; // r14
  Scaleform::GFx::AS3::Instances::fl::Array *v12; // rbx
  int v13; // edx
  unsigned __int64 v14; // rax
  int v15; // [rsp+20h] [rbp-28h]
  unsigned int v16; // [rsp+24h] [rbp-24h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> v17; // [rsp+28h] [rbp-20h]
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+60h] [rbp+18h]

  v4 = 0i64;
  v5 = argv;
  v6 = argc;
  v7 = 0;
  v8 = result;
  v9 = this;
  v15 = 0;
  if ( argc )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2Int32(argv, &resulta, &v15)->Result )
      return;
    v7 = v15;
    if ( v15 < 0 )
      v7 = LODWORD(v9->SA.Length) + v15;
  }
  v10 = v9->SA.Length;
  if ( v7 < 0 )
    v7 = 0;
  v11 = &v9->SA;
  v16 = v9->SA.Length;
  v15 = v7;
  if ( v6 <= 1 )
  {
    v16 = v10 - v7;
  }
  else if ( !Scaleform::GFx::AS3::Value::Convert2UInt32(v5 + 1, &resulta, &v16)->Result )
  {
    return;
  }
  Scaleform::GFx::AS3::InstanceTraits::fl::Array::MakeInstance(
    &v17,
    (Scaleform::GFx::AS3::InstanceTraits::fl::Array *)v9->pTraits.pObject);
  v12 = v17.pV;
  Scaleform::GFx::AS3::Value::Pick(v8, (Scaleform::GFx::AS3::Object *)&v17.pV->vfptr);
  if ( v12 )
    v4 = &v12->SA;
  Scaleform::GFx::AS3::Impl::SparseArray::CutMultipleAt(v11, v15, v16, v4);
  if ( v6 > 2 )
  {
    v13 = v15;
    v14 = v11->Length;
    if ( (signed int)v11->Length < v15 )
      v13 = v14;
    v15 = v13;
    Scaleform::GFx::AS3::Impl::SparseArray::Insert(v11, v13, v6 - 2, v5 + 2);
  }
}

// File Line: 1275
// RVA: 0x7A45B0
Scaleform::GFx::AS3::Instances::fl::Array::AS3sort

// File Line: 1471
// RVA: 0x7A56C0
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::AS3sortOn(Scaleform::GFx::AS3::Instances::fl::Array *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *result, Scaleform::GFx::AS3::Value *fieldName, Scaleform::GFx::AS3::Value *options)
{
  Scaleform::GFx::AS3::Value *v4; // r14
  Scaleform::GFx::AS3::Value *v5; // rdi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *v6; // r13
  Scaleform::GFx::AS3::Instances::fl::Array *v7; // r12
  Scaleform::GFx::AS3::VM *v8; // rax
  Scaleform::MemoryHeap *v9; // r15
  __int64 v10; // rbx
  Scaleform::GFx::AS3::Traits *v11; // rax
  long double v12; // r13
  unsigned __int64 v13; // r12
  Scaleform::GFx::AS3::Value *v14; // rax
  unsigned int v15; // edi
  Scaleform::GFx::ASStringNode *v16; // rsi
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v17; // r14
  Scaleform::GFx::AS3::Value *v18; // rdx
  int v19; // ecx
  unsigned int v20; // er15
  Scaleform::GFx::ASStringNode *v21; // rdi
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v22; // rsi
  Scaleform::GFx::AS3::Value *v23; // rdx
  int v24; // ecx
  unsigned __int64 v25; // rdi
  unsigned __int64 v26; // rsi
  unsigned __int64 v27; // r8
  unsigned __int64 v28; // rcx
  int v29; // ecx
  Scaleform::GFx::AS3::Traits *v30; // rax
  long double v31; // r14
  __int64 v32; // rax
  unsigned __int64 v33; // rdi
  Scaleform::GFx::AS3::Value *v34; // rax
  unsigned __int64 i; // rdx
  Scaleform::GFx::AS3::Value::V2U v36; // rax
  Scaleform::GFx::AS3::Impl::SparseArray *v37; // r15
  unsigned __int64 v38; // rsi
  unsigned int v39; // edi
  __int64 v40; // rax
  Scaleform::GFx::AS3::XMLParser::Kind v41; // er12
  Scaleform::GFx::AS3::Value::Extra v42; // r14
  unsigned int v43; // edi
  signed __int64 v44; // r8
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> v45; // rcx
  unsigned int v46; // eax
  unsigned __int64 v47; // rsi
  Scaleform::GFx::AS3::Value *j; // rdi
  int v49; // eax
  Scaleform::GFx::AS3::WeakProxy *v50; // rdx
  bool v51; // zf
  Scaleform::GFx::ASStringNode *v52; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v53; // rcx
  unsigned int v54; // eax
  int v55; // er12
  __int64 v56; // rdi
  Scaleform::GFx::AS3::Value::Extra v57; // rsi
  int v58; // ecx
  Scaleform::GFx::AS3::Value *v59; // rdx
  int v60; // eax
  long double v61; // rax
  Scaleform::GFx::AS3::Value::Extra v62; // rsi
  unsigned __int64 v63; // rcx
  Scaleform::GFx::AS3::Value *v64; // rdi
  Scaleform::GFx::AS3::Instances::fl::XMLList *v65; // rcx
  Scaleform::GFx::AS3::Instances::fl::Array *v66; // rbx
  unsigned int v67; // eax
  Scaleform::GFx::ASStringNode *v68; // rcx
  Scaleform::GFx::AS3::CheckResult v69; // [rsp+20h] [rbp-E0h]
  Scaleform::GFx::AS3::Value v70; // [rsp+28h] [rbp-D8h]
  Scaleform::GFx::AS3::Impl::ArrayFunc f; // [rsp+48h] [rbp-B8h]
  Scaleform::GFx::AS3::Value *v72; // [rsp+50h] [rbp-B0h]
  Scaleform::GFx::AS3::Value *v73; // [rsp+58h] [rbp-A8h]
  Scaleform::GFx::AS3::Value v74; // [rsp+60h] [rbp-A0h]
  Scaleform::GFx::AS3::Value *v75; // [rsp+80h] [rbp-80h]
  Scaleform::ArrayDataBase<enum Scaleform::GFx::AS3::XMLParser::Kind,Scaleform::AllocatorDH_POD<enum Scaleform::GFx::AS3::XMLParser::Kind,2>,Scaleform::ArrayDefaultPolicy> v76; // [rsp+88h] [rbp-78h]
  void *v77; // [rsp+A0h] [rbp-60h]
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> v78; // [rsp+A8h] [rbp-58h]
  void *pheapAddr; // [rsp+C0h] [rbp-40h]
  Scaleform::GFx::ASString resulta; // [rsp+C8h] [rbp-38h]
  Scaleform::GFx::AS3::Impl::SparseArray v81; // [rsp+D0h] [rbp-30h]
  Scaleform::GFx::AS3::Impl::CompareOn v82; // [rsp+140h] [rbp+40h]
  AMD_HD3D *v83; // [rsp+158h] [rbp+58h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> v84; // [rsp+1B0h] [rbp+B0h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *v85; // [rsp+1B8h] [rbp+B8h]
  Scaleform::GFx::AS3::Value *v86; // [rsp+1C8h] [rbp+C8h]

  v86 = options;
  v85 = result;
  v84.pV = this;
  v83 = (AMD_HD3D *)-2i64;
  v4 = options;
  v5 = fieldName;
  v6 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)result;
  v7 = this;
  v8 = this->pTraits.pObject->pVM;
  f.vfptr = (Scaleform::GFx::AS3::Impl::ArrayFuncVtbl *)v8->MHeap;
  v9 = (Scaleform::MemoryHeap *)f.vfptr;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v8->StringManagerRef->Builtins,
    &resulta);
  v10 = 0i64;
  v78.Data = 0i64;
  v78.Size = 0i64;
  v78.Policy.Capacity = 0i64;
  pheapAddr = f.vfptr;
  v73 = (Scaleform::GFx::AS3::Value *)&v76;
  v76.Data = 0i64;
  v76.Size = 0i64;
  v76.Policy.Capacity = 0i64;
  v77 = f.vfptr;
  v11 = Scaleform::GFx::AS3::VM::GetValueTraits(v7->pTraits.pObject->pVM, v5);
  if ( v11->TraitsType != 7 || !(~(LOBYTE(v11->Flags) >> 5) & 1) )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2String(v5, &v69, &resulta)->Result )
      goto LABEL_167;
    v20 = 10;
    v70.Flags = 10;
    v70.Bonus.pWeakProxy = 0i64;
    v21 = resulta.pNode;
    *(Scaleform::GFx::ASString *)&v70.value.VNumber = resulta;
    if ( resulta.pNode == &resulta.pNode->pManager->NullStringNode )
    {
      v21 = 0i64;
      v70.value.VNumber = 0.0;
      v22 = v82.Fields;
      v70.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v82.Fields;
      v20 = 12;
      v70.Flags = 12;
    }
    else
    {
      ++resulta.pNode->RefCount;
      v22 = (Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *)v70.value.VS._2.VObj;
    }
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &v78,
      pheapAddr,
      v78.Size + 1);
    v23 = &v78.Data[v78.Size - 1];
    v75 = &v78.Data[v78.Size - 1];
    v73 = &v78.Data[v78.Size - 1];
    if ( v23 )
    {
      v23->Flags = v20;
      v23->Bonus.pWeakProxy = 0i64;
      *(_QWORD *)&v23->value.VNumber = v21;
      v23->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v22;
      v24 = v20 & 0x1F;
      if ( v24 > 9 )
      {
        if ( (v20 >> 9) & 1 )
        {
          LODWORD(MEMORY[0]) = MEMORY[0] + 1;
        }
        else if ( v24 == 10 )
        {
          ++v21->RefCount;
        }
        else if ( v24 > 10 )
        {
          if ( v24 <= 15 )
          {
            if ( v21 )
              v21->Size = (v21->Size + 1) & 0x8FBFFFFF;
          }
          else if ( v24 <= 17 && v22 )
          {
            LODWORD(v22[1].Data.Data) = (LODWORD(v22[1].Data.Data) + 1) & 0x8FBFFFFF;
          }
        }
      }
    }
    if ( (char)(v20 & 0x1F) > 9 )
    {
      if ( !((v20 >> 9) & 1) )
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v70);
        v9 = (Scaleform::MemoryHeap *)f.vfptr;
        goto LABEL_54;
      }
      LODWORD(MEMORY[0]) = MEMORY[0] - 1;
      if ( !(_DWORD)MEMORY[0] )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
      v70.Bonus.pWeakProxy = 0i64;
      v70.value = 0ui64;
      v70.Flags = v20 & 0xFFFFFDE0;
    }
    v9 = (Scaleform::MemoryHeap *)f.vfptr;
    goto LABEL_54;
  }
  v12 = v5->value.VNumber;
  v13 = 0i64;
  if ( *(_QWORD *)(*(_QWORD *)&v12 + 56i64) > 0ui64 )
  {
    do
    {
      v14 = Scaleform::GFx::AS3::Impl::SparseArray::At(
              (Scaleform::GFx::AS3::Impl::SparseArray *)(*(_QWORD *)&v12 + 56i64),
              v13);
      if ( !Scaleform::GFx::AS3::Value::Convert2String(v14, &v69, &resulta)->Result )
        goto LABEL_167;
      v15 = 10;
      v70.Flags = 10;
      v70.Bonus.pWeakProxy = 0i64;
      v16 = resulta.pNode;
      *(Scaleform::GFx::ASString *)&v70.value.VNumber = resulta;
      if ( resulta.pNode == &resulta.pNode->pManager->NullStringNode )
      {
        v16 = 0i64;
        v70.value.VNumber = 0.0;
        v17 = v82.Fields;
        v70.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v82.Fields;
        v15 = 12;
        v70.Flags = 12;
      }
      else
      {
        ++resulta.pNode->RefCount;
        v17 = (Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *)v70.value.VS._2.VObj;
      }
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        &v78,
        pheapAddr,
        v78.Size + 1);
      v18 = &v78.Data[v78.Size - 1];
      v73 = &v78.Data[v78.Size - 1];
      v75 = &v78.Data[v78.Size - 1];
      if ( v18 )
      {
        v18->Flags = v15;
        v18->Bonus.pWeakProxy = 0i64;
        *(_QWORD *)&v18->value.VNumber = v16;
        v18->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v17;
        v19 = v15 & 0x1F;
        if ( v19 > 9 )
        {
          if ( (v15 >> 9) & 1 )
          {
            LODWORD(MEMORY[0]) = MEMORY[0] + 1;
          }
          else if ( v19 == 10 )
          {
            ++v16->RefCount;
          }
          else if ( v19 > 10 )
          {
            if ( v19 <= 15 )
            {
              if ( v16 )
                v16->Size = (v16->Size + 1) & 0x8FBFFFFF;
            }
            else if ( v19 <= 17 && v17 )
            {
              LODWORD(v17[1].Data.Data) = (LODWORD(v17[1].Data.Data) + 1) & 0x8FBFFFFF;
            }
          }
        }
      }
      if ( (char)(v15 & 0x1F) > 9 )
      {
        if ( (v15 >> 9) & 1 )
        {
          LODWORD(MEMORY[0]) = MEMORY[0] - 1;
          if ( !(_DWORD)MEMORY[0] )
            Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
          v70.Bonus.pWeakProxy = 0i64;
          v70.value = 0ui64;
          v70.Flags = v15 & 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v70);
        }
      }
      ++v13;
    }
    while ( v13 < *(_QWORD *)(*(_QWORD *)&v12 + 56i64) );
    v4 = v86;
    v9 = (Scaleform::MemoryHeap *)f.vfptr;
  }
  v7 = v84.pV;
  v6 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)v85;
LABEL_54:
  v25 = v78.Size;
  v26 = v78.Size;
  if ( v78.Size >= v76.Size )
  {
    if ( v78.Size <= v76.Policy.Capacity )
      goto LABEL_60;
    v27 = v78.Size + (v78.Size >> 2);
  }
  else
  {
    if ( v78.Size >= v76.Policy.Capacity >> 1 )
      goto LABEL_60;
    v27 = v78.Size;
  }
  Scaleform::ArrayDataBase<unsigned long,Scaleform::AllocatorDH<unsigned long,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    &v76,
    v77,
    v27);
  v25 = v78.Size;
LABEL_60:
  v76.Size = v26;
  v28 = 0i64;
  if ( v26 )
  {
    do
    {
      v76.Data[v28++] = 0;
      v26 = v76.Size;
    }
    while ( v28 < v76.Size );
    v25 = v78.Size;
  }
  v29 = v4->Flags & 0x1F;
  if ( v29 && ((unsigned int)(v29 - 12) > 3 && v29 != 10 || *(_QWORD *)&v4->value.VNumber) )
  {
    v30 = Scaleform::GFx::AS3::VM::GetValueTraits(v7->pTraits.pObject->pVM, v4);
    if ( v30->TraitsType == 7 && ~(LOBYTE(v30->Flags) >> 5) & 1 )
    {
      v31 = v4->value.VNumber;
      v32 = *(_QWORD *)(*(_QWORD *)&v31 + 56i64);
      if ( v32 == v25 )
      {
        v33 = 0i64;
        if ( v32 )
        {
          while ( v33 < v26 )
          {
            v34 = Scaleform::GFx::AS3::Impl::SparseArray::At(
                    (Scaleform::GFx::AS3::Impl::SparseArray *)(*(_QWORD *)&v31 + 56i64),
                    v33);
            if ( !Scaleform::GFx::AS3::Value::Convert2UInt32(v34, &v69, (unsigned int *)&f)->Result )
              goto LABEL_167;
            v76.Data[v33++] = (Scaleform::GFx::AS3::XMLParser::Kind)f.vfptr;
            if ( v33 >= *(_QWORD *)(*(_QWORD *)&v31 + 56i64) )
              break;
            v26 = v76.Size;
          }
        }
      }
    }
    else
    {
      if ( !Scaleform::GFx::AS3::Value::Convert2UInt32(v4, &v69, (unsigned int *)&f)->Result )
        goto LABEL_167;
      for ( i = 0i64; i < v76.Size; ++i )
        v76.Data[i] = (Scaleform::GFx::AS3::XMLParser::Kind)f.vfptr;
    }
  }
  v81.Length = 0i64;
  v81.ValueHLowInd = 0i64;
  v81.ValueHHighInd = 0i64;
  v81.DefaultValue.Flags = 0;
  v81.DefaultValue.Bonus.pWeakProxy = 0i64;
  v81.ValueA.Data.Data = 0i64;
  v81.ValueA.Data.Size = 0i64;
  v81.ValueA.Data.Policy.Capacity = 0i64;
  v81.ValueA.Data.pHeap = v9;
  v75 = (Scaleform::GFx::AS3::Value *)&v81.ValueH;
  v73 = (Scaleform::GFx::AS3::Value *)&v81.ValueH;
  v81.ValueH.mHash.pTable = 0i64;
  v81.ValueH.mHash.pHeap = v9;
  v36.VObj = (Scaleform::GFx::AS3::Object *)v7->pTraits.pObject->pVM->MHeap;
  v75 = &v70;
  *(_QWORD *)&v70.Flags = 0i64;
  v70.Bonus.pWeakProxy = 0i64;
  v70.value.VNumber = 0.0;
  v70.value.VS._2 = v36;
  f.vfptr = (Scaleform::GFx::AS3::Impl::ArrayFuncVtbl *)&Scaleform::GFx::AS3::Impl::ValuePtrCollector::`vftable';
  v72 = &v70;
  v37 = &v7->SA;
  v38 = v7->SA.ValueA.Data.Size;
  v39 = 0;
  if ( v38 )
  {
    v40 = 0i64;
    do
    {
      f.vfptr->operator()(&f, v39++, &v7->SA.ValueA.Data.Data[v40]);
      v40 = v39;
    }
    while ( v39 < v38 );
  }
  Scaleform::GFx::AS3::Impl::SparseArray::ForEachSparse(&v7->SA, &f);
  v82.Vm = v7->pTraits.pObject->pVM;
  v82.Fields = (Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *)&v78;
  v82.Flags = (Scaleform::ArrayDH<unsigned long,2,Scaleform::ArrayDefaultPolicy> *)&v76;
  *(_QWORD *)&v74.Flags = v82.Vm;
  v74.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)&v78;
  *(_QWORD *)&v74.value.VNumber = &v76;
  Scaleform::Alg::QuickSortSlicedSafe<Scaleform::ArrayDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::AS3::Impl::CompareOn>(
    (Scaleform::ArrayDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2,Scaleform::ArrayDefaultPolicy> *)&v70,
    0i64,
    (unsigned __int64)v70.Bonus.pWeakProxy,
    (Scaleform::GFx::AS3::Impl::CompareOn *)&v74);
  v41 = *v76.Data;
  v42.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v70.Bonus;
  if ( !(*v76.Data & 4) || (v43 = 1, v70.Bonus.pWeakProxy <= (Scaleform::GFx::AS3::WeakProxy *)1) )
  {
LABEL_116:
    v55 = v41 & 8;
    if ( v55 )
    {
      if ( v42.pWeakProxy )
      {
        v56 = 0i64;
        v57.pWeakProxy = v42.pWeakProxy;
        do
        {
          v58 = *(_DWORD *)(v56 + *(_QWORD *)&v70.Flags + 8);
          v74.Flags = 3;
          v74.Bonus.pWeakProxy = 0i64;
          v74.value.VS._1.VInt = v58;
          if ( v81.Length == v81.ValueA.Data.Size )
          {
            Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
              (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v81.ValueA.Data.Data,
              v81.ValueA.Data.pHeap,
              v81.ValueA.Data.Size + 1);
            v59 = &v81.ValueA.Data.Data[v81.ValueA.Data.Size - 1];
            v75 = &v81.ValueA.Data.Data[v81.ValueA.Data.Size - 1];
            v73 = &v81.ValueA.Data.Data[v81.ValueA.Data.Size - 1];
            if ( v59 )
            {
              v59->Flags = v74.Flags;
              v59->Bonus.pWeakProxy = v74.Bonus.pWeakProxy;
              v59->value = v74.value;
              v60 = v74.Flags & 0x1F;
              if ( v60 > 9 )
              {
                if ( (v74.Flags >> 9) & 1 )
                {
                  ++v74.Bonus.pWeakProxy->RefCount;
                }
                else if ( v60 == 10 )
                {
                  ++*(_DWORD *)(*(_QWORD *)&v74.value.VNumber + 24i64);
                }
                else if ( v60 > 10 )
                {
                  if ( v60 <= 15 )
                  {
                    v61 = v74.value.VNumber;
LABEL_130:
                    if ( v61 != 0.0 )
                    {
                      ++*(_DWORD *)(*(_QWORD *)&v61 + 32i64);
                      *(_DWORD *)(*(_QWORD *)&v61 + 32i64) &= 0x8FBFFFFF;
                    }
                    goto LABEL_135;
                  }
                  if ( v60 <= 17 )
                  {
                    v61 = *(double *)&v74.value.VS._2.VObj;
                    goto LABEL_130;
                  }
                }
              }
            }
          }
          else
          {
            v81.ValueHHighInd = v81.Length;
            v82.Vm = (Scaleform::GFx::AS3::VM *)&v81.ValueHHighInd;
            v82.Fields = (Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *)&v74;
            Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
              (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v81.ValueH.mHash.pTable,
              v81.ValueH.mHash.pHeap,
              (Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef *)&v82);
          }
LABEL_135:
          ++v81.Length;
          if ( (v74.Flags & 0x1F) > 9 )
          {
            if ( (v74.Flags >> 9) & 1 )
            {
              v51 = v74.Bonus.pWeakProxy->RefCount-- == 1;
              if ( v51 )
                ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
              v74.Bonus.pWeakProxy = 0i64;
              v74.value = 0ui64;
              v74.Flags &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&v74);
            }
          }
          v56 += 16i64;
          --v57.pWeakProxy;
        }
        while ( v57.pWeakProxy );
      }
    }
    else if ( v42.pWeakProxy )
    {
      v62.pWeakProxy = v42.pWeakProxy;
      v63 = v81.Length;
      do
      {
        v64 = *(Scaleform::GFx::AS3::Value **)(v10 + *(_QWORD *)&v70.Flags);
        if ( v63 == v81.ValueA.Data.Size )
        {
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
            (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v81.ValueA.Data.Data,
            v81.ValueA.Data.pHeap,
            v81.ValueA.Data.Size + 1);
          Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
            &v81.ValueA.Data.Data[v81.ValueA.Data.Size - 1],
            v64);
        }
        else
        {
          v81.ValueHHighInd = v63;
          v82.Vm = (Scaleform::GFx::AS3::VM *)&v81.ValueHHighInd;
          v82.Fields = (Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *)v64;
          Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
            (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v81.ValueH.mHash.pTable,
            v81.ValueH.mHash.pHeap,
            (Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef *)&v82);
        }
        v63 = v81.Length++ + 1;
        v10 += 16i64;
        --v62.pWeakProxy;
      }
      while ( v62.pWeakProxy );
      goto LABEL_151;
    }
    v63 = v81.Length;
LABEL_151:
    if ( v42.pWeakProxy < (Scaleform::GFx::AS3::WeakProxy *)v37->Length )
    {
      Scaleform::GFx::AS3::Impl::SparseArray::Resize(&v81, v37->Length);
      v63 = v81.Length;
    }
    if ( v55 )
    {
      Scaleform::GFx::AS3::InstanceTraits::fl::Array::MakeInstance(
        &v84,
        (Scaleform::GFx::AS3::InstanceTraits::fl::Array *)v84.pV->pTraits.pObject->pVM->TraitsArray.pObject->ITraits.pObject);
      v65 = v6->pObject;
      v66 = v84.pV;
      if ( v84.pV != (Scaleform::GFx::AS3::Instances::fl::Array *)v6->pObject )
      {
        if ( v65 )
        {
          if ( (unsigned __int8)v65 & 1 )
          {
            v6->pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v65 - 1);
          }
          else
          {
            v67 = v65->RefCount;
            if ( v67 & 0x3FFFFF )
            {
              v65->RefCount = v67 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v65->vfptr);
            }
          }
        }
        v6->pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v66;
      }
      if ( &v66->SA != &v81 )
      {
        v66->SA.Length = v81.Length;
        v66->SA.ValueHLowInd = v81.ValueHLowInd;
        v66->SA.ValueHHighInd = v81.ValueHHighInd;
        Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Assign(
          (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v66->SA.ValueH.mHash.pTable,
          v81.ValueH.mHash.pHeap,
          (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v81.ValueH.mHash.pTable);
        v66->SA.ValueH.mHash.pHeap = v81.ValueH.mHash.pHeap;
        Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy>::operator=(
          &v66->SA.ValueA,
          &v81.ValueA);
      }
    }
    else
    {
      if ( v37 != &v81 )
      {
        v37->Length = v63;
        v37->ValueHLowInd = v81.ValueHLowInd;
        v37->ValueHHighInd = v81.ValueHHighInd;
        Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Assign(
          (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v37->ValueH.mHash.pTable,
          v81.ValueH.mHash.pHeap,
          (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v81.ValueH.mHash.pTable);
        v37->ValueH.mHash.pHeap = v81.ValueH.mHash.pHeap;
        Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy>::operator=(
          &v37->ValueA,
          &v81.ValueA);
      }
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
        v6,
        (Scaleform::GFx::AS3::Instances::fl::XMLList *)v84.pV);
    }
    f.vfptr = (Scaleform::GFx::AS3::Impl::ArrayFuncVtbl *)&Scaleform::GFx::AS3::Impl::ArrayFunc::`vftable';
    v84.pV = (Scaleform::GFx::AS3::Instances::fl::Array *)&v70;
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, *(void **)&v70.Flags);
    Scaleform::GFx::AS3::Impl::SparseArray::~SparseArray(&v81);
    goto LABEL_167;
  }
  v44 = 1i64;
  while ( Scaleform::GFx::AS3::Impl::CompareOn::Compare(
            &v82,
            *(Scaleform::GFx::AS3::Value **)(*(_QWORD *)&v70.Flags + 16i64 * (v43 - 1)),
            *(Scaleform::GFx::AS3::Value **)(*(_QWORD *)&v70.Flags + 16 * v44)) != 0.0 )
  {
    v44 = ++v43;
    if ( (Scaleform::GFx::AS3::WeakProxy *)v43 >= v42.pWeakProxy )
      goto LABEL_116;
  }
  v45.pObject = v6->pObject;
  if ( v6->pObject )
  {
    if ( (_QWORD)v45.pObject & 1 )
    {
      v6->pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v45.pObject - 1);
    }
    else
    {
      v46 = v45.pObject->RefCount;
      if ( v46 & 0x3FFFFF )
      {
        v45.pObject->RefCount = v46 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v45.pObject->vfptr);
      }
    }
    v6->pObject = 0i64;
  }
  f.vfptr = (Scaleform::GFx::AS3::Impl::ArrayFuncVtbl *)&Scaleform::GFx::AS3::Impl::ArrayFunc::`vftable';
  v84.pV = (Scaleform::GFx::AS3::Instances::fl::Array *)&v70;
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, *(void **)&v70.Flags);
  v84.pV = (Scaleform::GFx::AS3::Instances::fl::Array *)&v81.ValueH;
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Clear((Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v81.ValueH.mHash.pTable);
  v84.pV = (Scaleform::GFx::AS3::Instances::fl::Array *)&v81.ValueA;
  v47 = v81.ValueA.Data.Size;
  for ( j = &v81.ValueA.Data.Data[v81.ValueA.Data.Size - 1]; v47; --v47 )
  {
    v49 = j->Flags & 0x1F;
    if ( v49 > 9 )
    {
      if ( (j->Flags >> 9) & 1 )
      {
        v50 = j->Bonus.pWeakProxy;
        v51 = v50->RefCount-- == 1;
        if ( v51 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        j->Bonus.pWeakProxy = 0i64;
        j->value.VNumber = 0.0;
        j->value.VS._2.VObj = 0i64;
        j->Flags &= 0xFFFFFDE0;
      }
      else
      {
        switch ( v49 )
        {
          case 10:
            v52 = j->value.VS._1.VStr;
            v51 = v52->RefCount-- == 1;
            if ( v51 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v52);
            break;
          case 11:
          case 12:
          case 13:
          case 14:
          case 15:
            v53 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)j->value.VS._1.VStr;
            if ( !((unsigned __int8)v53 & 1) )
              goto LABEL_106;
            *(_QWORD *)&j->value.VNumber = (char *)v53 - 1;
            break;
          case 16:
          case 17:
            v53 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)&j->value.VS._2.VObj->vfptr;
            if ( (unsigned __int8)v53 & 1 )
            {
              j->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)((char *)&v53[-1].RefCount + 7);
            }
            else
            {
LABEL_106:
              if ( v53 )
              {
                v54 = v53->RefCount;
                if ( v54 & 0x3FFFFF )
                {
                  v53->RefCount = v54 - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v53);
                }
              }
            }
            break;
          default:
            break;
        }
      }
    }
    --j;
  }
  ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  if ( (v81.DefaultValue.Flags & 0x1F) > 9 )
  {
    if ( (v81.DefaultValue.Flags >> 9) & 1 )
    {
      v51 = v81.DefaultValue.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v51 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      _mm_store_si128((__m128i *)&v81.DefaultValue.Bonus, (__m128i)0i64);
      v81.DefaultValue.value.VS._2.VObj = 0i64;
      v81.DefaultValue.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v81.DefaultValue);
    }
  }
LABEL_167:
  v84.pV = (Scaleform::GFx::AS3::Instances::fl::Array *)&v76;
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v76.Data);
  v84.pV = (Scaleform::GFx::AS3::Instances::fl::Array *)&v78;
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(v78.Data, v78.Size);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v78.Data);
  v68 = resulta.pNode;
  v51 = resulta.pNode->RefCount == 1;
  --v68->RefCount;
  if ( v51 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v68);
}== 1;
  --v68->RefCount;
  if ( v51 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v68);
}

// File Line: 1614
// RVA: 0x79FA50
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::AS3indexOf(Scaleform::GFx::AS3::Instances::fl::Array *this, int *result, Scaleform::GFx::AS3::Value *searchElement, int fromIndex)
{
  Scaleform::GFx::AS3::Value *v4; // r13
  int *v5; // r12
  Scaleform::GFx::AS3::Instances::fl::Array *v6; // rdi
  unsigned __int64 v7; // rbp
  unsigned __int64 v8; // rbx
  unsigned __int64 v9; // r15
  signed __int64 v10; // rsi
  Scaleform::GFx::AS3::Value *v11; // rcx
  signed __int64 v12; // rax
  signed __int64 v13; // rcx
  unsigned __int64 key; // [rsp+50h] [rbp+8h]

  v4 = searchElement;
  v5 = result;
  v6 = this;
  if ( fromIndex < 0 )
    fromIndex += LODWORD(this->SA.Length);
  v7 = this->SA.Length;
  v8 = fromIndex;
  if ( fromIndex >= v7 )
  {
LABEL_15:
    *v5 = -1;
  }
  else
  {
    v9 = this->SA.ValueA.Data.Size;
    v10 = fromIndex;
    while ( 1 )
    {
      key = v8;
      if ( v8 >= v9 )
      {
        if ( v8 < v6->SA.ValueHLowInd
          || v8 > v6->SA.ValueHHighInd
          || (v12 = Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::findIndexAlt<unsigned __int64>(
                      (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v6->SA.ValueH.mHash.pTable,
                      &key),
              v12 < 0)
          || (v13 = (signed __int64)&v6->SA.ValueH.mHash.pTable[2] + 56 * v12) == 0
          || (v11 = (Scaleform::GFx::AS3::Value *)(v13 + 8)) == 0i64 )
        {
          v11 = &v6->SA.DefaultValue;
        }
      }
      else
      {
        v11 = &v6->SA.ValueA.Data.Data[v10];
      }
      if ( Scaleform::GFx::AS3::StrictEqual(v11, v4) )
        break;
      ++v8;
      ++v10;
      if ( v8 >= v7 )
        goto LABEL_15;
    }
    *v5 = v8;
  }
}

// File Line: 1632
// RVA: 0x79FD70
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::AS3lastIndexOf(Scaleform::GFx::AS3::Instances::fl::Array *this, int *result, Scaleform::GFx::AS3::Value *searchElement, int fromIndex)
{
  Scaleform::GFx::AS3::Value *v4; // r12
  int *v5; // r15
  Scaleform::GFx::AS3::Instances::fl::Array *v6; // rdi
  unsigned __int64 v7; // rbx
  unsigned __int64 v8; // rbp
  signed __int64 v9; // rsi
  Scaleform::GFx::AS3::Value *v10; // rcx
  signed __int64 v11; // rax
  signed __int64 v12; // rcx
  unsigned __int64 key; // [rsp+50h] [rbp+8h]

  v4 = searchElement;
  v5 = result;
  v6 = this;
  if ( fromIndex < 0 )
    fromIndex += LODWORD(this->SA.Length);
  v7 = this->SA.Length - 1;
  if ( fromIndex < (signed __int64)v7 )
    v7 = fromIndex;
  if ( (v7 & 0x8000000000000000ui64) != 0i64 )
  {
LABEL_17:
    *v5 = -1;
  }
  else
  {
    v8 = this->SA.ValueA.Data.Size;
    v9 = v7;
    while ( 1 )
    {
      key = v7;
      if ( v7 >= v8 )
      {
        if ( v7 < v6->SA.ValueHLowInd
          || v7 > v6->SA.ValueHHighInd
          || (v11 = Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::findIndexAlt<unsigned __int64>(
                      (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v6->SA.ValueH.mHash.pTable,
                      &key),
              v11 < 0)
          || (v12 = (signed __int64)&v6->SA.ValueH.mHash.pTable[2] + 56 * v11) == 0
          || (v10 = (Scaleform::GFx::AS3::Value *)(v12 + 8)) == 0i64 )
        {
          v10 = &v6->SA.DefaultValue;
        }
      }
      else
      {
        v10 = &v6->SA.ValueA.Data.Data[v9];
      }
      if ( Scaleform::GFx::AS3::StrictEqual(v10, v4) )
        break;
      --v9;
      if ( (--v7 & 0x8000000000000000ui64) != 0i64 )
        goto LABEL_17;
    }
    *v5 = v7;
  }
}

// File Line: 1650
// RVA: 0x79D6E0
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::AS3every(Scaleform::GFx::AS3::Instances::fl::Array *this, bool *result, Scaleform::GFx::AS3::Value *callback, Scaleform::GFx::AS3::Value *thisObject)
{
  Scaleform::GFx::AS3::Value *v4; // r15
  bool *v5; // r12
  Scaleform::GFx::AS3::Instances::fl::Array *v6; // rbx
  unsigned int v7; // ecx
  unsigned int v8; // ecx
  bool v9; // al
  unsigned int v10; // ecx
  Scaleform::GFx::AS3::WeakProxy *v11; // rdx
  int v12; // eax
  long double v13; // rcx
  unsigned __int64 v14; // rdi
  __int64 v15; // r14
  signed __int64 v16; // rcx
  signed __int64 v17; // rax
  signed __int64 v18; // rcx
  int v19; // eax
  __int64 v20; // rdx
  bool v21; // zf
  int v22; // eax
  Scaleform::GFx::ASStringNode *v23; // rcx
  long double v24; // rcx
  int v25; // eax
  Scaleform::GFx::AS3::Value resulta; // [rsp+18h] [rbp-79h]
  Scaleform::GFx::AS3::Value _this; // [rsp+38h] [rbp-59h]
  Scaleform::GFx::AS3::Value argv; // [rsp+58h] [rbp-39h]
  int v29; // [rsp+78h] [rbp-19h]
  __int64 v30; // [rsp+80h] [rbp-11h]
  int v31; // [rsp+88h] [rbp-9h]
  int v32; // [rsp+98h] [rbp+7h]
  __int64 v33; // [rsp+A0h] [rbp+Fh]
  Scaleform::GFx::AS3::Instances::fl::Array *v34; // [rsp+A8h] [rbp+17h]
  __int64 v35; // [rsp+B8h] [rbp+27h]
  unsigned __int64 key; // [rsp+100h] [rbp+6Fh]

  v35 = -2i64;
  v4 = callback;
  v5 = result;
  v6 = this;
  v7 = callback->Flags & 0x1F;
  if ( !v7 || (v7 - 12 <= 3 || v7 == 10) && !*(_QWORD *)&callback->value.VNumber )
    goto LABEL_81;
  v8 = thisObject->Flags & 0x1F;
  v9 = !v8 || (v8 - 12 <= 3 || v8 == 10) && !*(_QWORD *)&thisObject->value.VNumber;
  if ( v9 )
    thisObject = callback;
  v10 = thisObject->Flags;
  _this.Flags = v10;
  v11 = thisObject->Bonus.pWeakProxy;
  _this.Bonus.pWeakProxy = thisObject->Bonus.pWeakProxy;
  _this.value = thisObject->value;
  v12 = v10 & 0x1F;
  if ( v12 <= 9 )
    goto LABEL_25;
  if ( (v10 >> 9) & 1 )
  {
    ++v11->RefCount;
  }
  else
  {
    if ( v12 == 10 )
    {
      ++*(_DWORD *)(*(_QWORD *)&thisObject->value.VNumber + 24i64);
      goto LABEL_25;
    }
    if ( v12 > 10 )
    {
      if ( v12 <= 15 )
      {
        v13 = thisObject->value.VNumber;
      }
      else
      {
        if ( v12 > 17 )
          goto LABEL_25;
        v13 = *(double *)&thisObject->value.VS._2.VObj;
      }
      if ( v13 != 0.0 )
        *(_DWORD *)(*(_QWORD *)&v13 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v13 + 32i64) + 1) & 0x8FBFFFFF;
      goto LABEL_25;
    }
  }
LABEL_25:
  v14 = 0i64;
  if ( v6->SA.Length <= 0 )
    goto LABEL_66;
  v15 = 0i64;
  while ( 1 )
  {
    key = v14;
    if ( v14 >= v6->SA.ValueA.Data.Size )
    {
      if ( v14 < v6->SA.ValueHLowInd
        || v14 > v6->SA.ValueHHighInd
        || (v17 = Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::findIndexAlt<unsigned __int64>(
                    (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v6->SA.ValueH.mHash.pTable,
                    &key),
            v17 < 0)
        || (v18 = (signed __int64)&v6->SA.ValueH.mHash.pTable[2] + 56 * v17) == 0
        || (v16 = v18 + 8) == 0 )
      {
        v16 = (signed __int64)&v6->SA.DefaultValue;
      }
    }
    else
    {
      v16 = (signed __int64)&v6->SA.ValueA.Data.Data[v15];
    }
    argv.Flags = *(_DWORD *)v16;
    argv.Bonus.pWeakProxy = *(Scaleform::GFx::AS3::WeakProxy **)(v16 + 8);
    argv.value = *(Scaleform::GFx::AS3::Value::VU *)(v16 + 16);
    v19 = *(_DWORD *)v16 & 0x1F;
    if ( v19 > 9 )
    {
      if ( (*(_DWORD *)v16 >> 9) & 1 )
      {
        ++**(_DWORD **)(v16 + 8);
        goto LABEL_47;
      }
      if ( v19 == 10 )
      {
        ++*(_DWORD *)(*(_QWORD *)(v16 + 16) + 24i64);
      }
      else
      {
        if ( v19 <= 10 )
          goto LABEL_47;
        if ( v19 <= 15 )
        {
          v20 = *(_QWORD *)(v16 + 16);
        }
        else
        {
          if ( v19 > 17 )
            goto LABEL_47;
          v20 = *(_QWORD *)(v16 + 24);
        }
        if ( v20 )
          *(_DWORD *)(v20 + 32) = (*(_DWORD *)(v20 + 32) + 1) & 0x8FBFFFFF;
      }
    }
LABEL_47:
    v29 = 3;
    v30 = 0i64;
    v31 = v14;
    v32 = 12;
    v33 = 0i64;
    v34 = v6;
    v6->RefCount = (v6->RefCount + 1) & 0x8FBFFFFF;
    if ( !Scaleform::GFx::AS3::Value::IsCallable(v4) )
      goto LABEL_65;
    resulta.Flags = 0;
    resulta.Bonus.pWeakProxy = 0i64;
    Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(v6->pTraits.pObject->pVM, v4, &_this, &resulta, 3u, &argv, 0);
    if ( v6->pTraits.pObject->pVM->HandleException || (resulta.Flags & 0x1F) != 1 || !resulta.value.VS._1.VBool )
      break;
    if ( (resulta.Flags & 0x1F) > 9 )
    {
      if ( (resulta.Flags >> 9) & 1 )
      {
        v21 = resulta.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v21 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        resulta.Bonus.pWeakProxy = 0i64;
        resulta.value = 0ui64;
        resulta.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&resulta);
      }
    }
    `eh vector destructor iterator'(&argv, 0x20ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
    ++v14;
    ++v15;
    if ( v14 >= v6->SA.Length )
      goto LABEL_66;
  }
  if ( (resulta.Flags & 0x1F) > 9 )
  {
    if ( (resulta.Flags >> 9) & 1 )
    {
      v21 = resulta.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v21 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      resulta.Flags &= 0xFFFFFDE0;
      resulta.value = 0ui64;
      resulta.Bonus.pWeakProxy = 0i64;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&resulta);
    }
  }
LABEL_65:
  `eh vector destructor iterator'(&argv, 0x20ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
LABEL_66:
  v22 = _this.Flags & 0x1F;
  if ( v22 > 9 )
  {
    if ( (_this.Flags >> 9) & 1 )
    {
      v21 = _this.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v21 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      _this.Bonus.pWeakProxy = 0i64;
      _this.value = 0ui64;
      _this.Flags &= 0xFFFFFDE0;
    }
    else
    {
      switch ( v22 )
      {
        case 10:
          v23 = _this.value.VS._1.VStr;
          v21 = *(_DWORD *)(*(_QWORD *)&_this.value.VNumber + 24i64) == 1;
          --v23->RefCount;
          if ( v21 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v23);
          break;
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
          v24 = _this.value.VNumber;
          if ( !_this.value.VS._1.VBool )
            goto LABEL_78;
          --*(_QWORD *)&_this.value.VNumber;
          break;
        case 16:
        case 17:
          v24 = *(double *)&_this.value.VS._2.VObj;
          if ( (_QWORD)_this.value.VS._2.VObj & 1 )
          {
            --_this.value.VS._2.VObj;
          }
          else
          {
LABEL_78:
            if ( v24 != 0.0 )
            {
              v25 = *(_DWORD *)(*(_QWORD *)&v24 + 32i64);
              if ( v25 & 0x3FFFFF )
              {
                *(_DWORD *)(*(_QWORD *)&v24 + 32i64) = v25 - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(*(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v24);
              }
            }
          }
          break;
        default:
          break;
      }
    }
  }
LABEL_81:
  *v5 = 0;
}

// File Line: 1678
// RVA: 0x79DBE0
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::AS3filter(Scaleform::GFx::AS3::Instances::fl::Array *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *result, Scaleform::GFx::AS3::Value *callback, Scaleform::GFx::AS3::Value *thisObject)
{
  Scaleform::GFx::AS3::Value *v4; // rdi
  Scaleform::GFx::AS3::Value *v5; // r12
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *v6; // rsi
  Scaleform::GFx::AS3::Instances::fl::Array *v7; // r13
  Scaleform::GFx::AS3::Instances::fl::Array *v8; // rcx
  Scaleform::GFx::AS3::Instances::fl::Array *v9; // rbx
  unsigned int v10; // eax
  int v11; // ecx
  int v12; // ecx
  bool v13; // al
  unsigned int v14; // ecx
  Scaleform::GFx::AS3::WeakProxy *v15; // rdx
  int v16; // eax
  long double v17; // rcx
  Scaleform::GFx::AS3::Instances::fl::Array *v18; // r14
  __int64 v19; // r15
  signed __int64 v20; // rcx
  signed __int64 v21; // rax
  signed __int64 v22; // rcx
  int v23; // eax
  __int64 v24; // rdx
  Scaleform::GFx::AS3::Value *v25; // rax
  bool v26; // zf
  int v27; // eax
  Scaleform::GFx::ASStringNode *v28; // rcx
  long double v29; // rcx
  int v30; // eax
  Scaleform::GFx::AS3::Value v31; // [rsp+18h] [rbp-79h]
  Scaleform::GFx::AS3::Value _this; // [rsp+38h] [rbp-59h]
  Scaleform::GFx::AS3::Value argv; // [rsp+58h] [rbp-39h]
  int v34; // [rsp+78h] [rbp-19h]
  __int64 v35; // [rsp+80h] [rbp-11h]
  int v36; // [rsp+88h] [rbp-9h]
  int v37; // [rsp+98h] [rbp+7h]
  __int64 v38; // [rsp+A0h] [rbp+Fh]
  Scaleform::GFx::AS3::Instances::fl::Array *v39; // [rsp+A8h] [rbp+17h]
  __int64 v40; // [rsp+B8h] [rbp+27h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> resulta; // [rsp+F8h] [rbp+67h]
  __int64 v42; // [rsp+120h] [rbp+8Fh]

  v40 = -2i64;
  v4 = thisObject;
  v5 = callback;
  v6 = result;
  v7 = this;
  Scaleform::GFx::AS3::InstanceTraits::fl::Array::MakeInstance(
    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> *)&v42,
    (Scaleform::GFx::AS3::InstanceTraits::fl::Array *)this->pTraits.pObject);
  v8 = v6->pObject;
  v9 = resulta.pV;
  if ( resulta.pV != v6->pObject )
  {
    if ( v8 )
    {
      if ( (unsigned __int8)v8 & 1 )
      {
        v6->pObject = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)v8 - 1);
      }
      else
      {
        v10 = v8->RefCount;
        if ( v10 & 0x3FFFFF )
        {
          v8->RefCount = v10 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v8->vfptr);
        }
      }
    }
    v6->pObject = v9;
  }
  v11 = v5->Flags & 0x1F;
  if ( !v11 || ((unsigned int)(v11 - 12) <= 3 || v11 == 10) && !*(_QWORD *)&v5->value.VNumber )
    return;
  v12 = v4->Flags & 0x1F;
  v13 = !v12 || ((unsigned int)(v12 - 12) <= 3 || v12 == 10) && !*(_QWORD *)&v4->value.VNumber;
  if ( v13 )
    v4 = v5;
  v14 = v4->Flags;
  _this.Flags = v14;
  v15 = v4->Bonus.pWeakProxy;
  _this.Bonus.pWeakProxy = v4->Bonus.pWeakProxy;
  _this.value = v4->value;
  v16 = v14 & 0x1F;
  if ( v16 <= 9 )
    goto LABEL_32;
  if ( (v14 >> 9) & 1 )
  {
    ++v15->RefCount;
  }
  else
  {
    if ( v16 == 10 )
    {
      ++*(_DWORD *)(*(_QWORD *)&v4->value.VNumber + 24i64);
      goto LABEL_32;
    }
    if ( v16 > 10 )
    {
      if ( v16 <= 15 )
      {
        v17 = v4->value.VNumber;
      }
      else
      {
        if ( v16 > 17 )
          goto LABEL_32;
        v17 = *(double *)&v4->value.VS._2.VObj;
      }
      if ( v17 != 0.0 )
        *(_DWORD *)(*(_QWORD *)&v17 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v17 + 32i64) + 1) & 0x8FBFFFFF;
      goto LABEL_32;
    }
  }
LABEL_32:
  v18 = 0i64;
  if ( !v7->SA.Length )
    goto LABEL_74;
  v19 = 0i64;
  while ( 1 )
  {
    resulta.pV = v18;
    if ( (unsigned __int64)v18 >= v7->SA.ValueA.Data.Size )
    {
      if ( (unsigned __int64)v18 < v7->SA.ValueHLowInd
        || (unsigned __int64)v18 > v7->SA.ValueHHighInd
        || (v21 = Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::findIndexAlt<unsigned __int64>(
                    (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v7->SA.ValueH.mHash.pTable,
                    (const unsigned __int64 *)&resulta),
            v21 < 0)
        || (v22 = (signed __int64)&v7->SA.ValueH.mHash.pTable[2] + 56 * v21) == 0
        || (v20 = v22 + 8) == 0 )
      {
        v20 = (signed __int64)&v7->SA.DefaultValue;
      }
    }
    else
    {
      v20 = (signed __int64)&v7->SA.ValueA.Data.Data[v19];
    }
    argv.Flags = *(_DWORD *)v20;
    argv.Bonus.pWeakProxy = *(Scaleform::GFx::AS3::WeakProxy **)(v20 + 8);
    argv.value = *(Scaleform::GFx::AS3::Value::VU *)(v20 + 16);
    v23 = *(_DWORD *)v20 & 0x1F;
    if ( v23 > 9 )
    {
      if ( (*(_DWORD *)v20 >> 9) & 1 )
      {
        ++**(_DWORD **)(v20 + 8);
        goto LABEL_54;
      }
      if ( v23 == 10 )
      {
        ++*(_DWORD *)(*(_QWORD *)(v20 + 16) + 24i64);
      }
      else
      {
        if ( v23 <= 10 )
          goto LABEL_54;
        if ( v23 <= 15 )
        {
          v24 = *(_QWORD *)(v20 + 16);
        }
        else
        {
          if ( v23 > 17 )
            goto LABEL_54;
          v24 = *(_QWORD *)(v20 + 24);
        }
        if ( v24 )
          *(_DWORD *)(v24 + 32) = (*(_DWORD *)(v24 + 32) + 1) & 0x8FBFFFFF;
      }
    }
LABEL_54:
    v34 = 3;
    v35 = 0i64;
    v36 = (signed int)v18;
    v37 = 12;
    v38 = 0i64;
    v39 = v7;
    v7->RefCount = (v7->RefCount + 1) & 0x8FBFFFFF;
    if ( !Scaleform::GFx::AS3::Value::IsCallable(v5) )
      goto LABEL_73;
    v31.Flags = 0;
    v31.Bonus.pWeakProxy = 0i64;
    Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(v7->pTraits.pObject->pVM, v5, &_this, &v31, 3u, &argv, 0);
    if ( v7->pTraits.pObject->pVM->HandleException )
      break;
    if ( (v31.Flags & 0x1F) == 1 && v31.value.VS._1.VBool )
    {
      v25 = Scaleform::GFx::AS3::Impl::SparseArray::At(&v7->SA, (unsigned __int64)v18);
      Scaleform::GFx::AS3::Impl::SparseArray::PushBack(&v9->SA, v25);
    }
    if ( (v31.Flags & 0x1F) > 9 )
    {
      if ( (v31.Flags >> 9) & 1 )
      {
        v26 = v31.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v26 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v31.Bonus.pWeakProxy = 0i64;
        v31.value = 0ui64;
        v31.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v31);
      }
    }
    `eh vector destructor iterator'(&argv, 0x20ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
    v18 = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)v18 + 1);
    ++v19;
    if ( (unsigned __int64)v18 >= v7->SA.Length )
      goto LABEL_74;
  }
  if ( (v31.Flags & 0x1F) > 9 )
  {
    if ( (v31.Flags >> 9) & 1 )
    {
      v26 = v31.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v26 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v31.Bonus.pWeakProxy = 0i64;
      v31.value = 0ui64;
      v31.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v31);
    }
  }
LABEL_73:
  `eh vector destructor iterator'(&argv, 0x20ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
LABEL_74:
  v27 = _this.Flags & 0x1F;
  if ( v27 > 9 )
  {
    if ( (_this.Flags >> 9) & 1 )
    {
      v26 = _this.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v26 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      _this.Bonus.pWeakProxy = 0i64;
      _this.value = 0ui64;
      _this.Flags &= 0xFFFFFDE0;
    }
    else
    {
      switch ( v27 )
      {
        case 10:
          v28 = _this.value.VS._1.VStr;
          v26 = *(_DWORD *)(*(_QWORD *)&_this.value.VNumber + 24i64) == 1;
          --v28->RefCount;
          if ( v26 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v28);
          break;
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
          v29 = _this.value.VNumber;
          if ( !_this.value.VS._1.VBool )
            goto LABEL_86;
          --*(_QWORD *)&_this.value.VNumber;
          break;
        case 16:
        case 17:
          v29 = *(double *)&_this.value.VS._2.VObj;
          if ( (_QWORD)_this.value.VS._2.VObj & 1 )
          {
            --_this.value.VS._2.VObj;
          }
          else
          {
LABEL_86:
            if ( v29 != 0.0 )
            {
              v30 = *(_DWORD *)(*(_QWORD *)&v29 + 32i64);
              if ( v30 & 0x3FFFFF )
              {
                *(_DWORD *)(*(_QWORD *)&v29 + 32i64) = v30 - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(*(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v29);
              }
            }
          }
          break;
        default:
          return;
      }
    }
  }
}

// File Line: 1711
// RVA: 0x79E080
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::AS3forEach(Scaleform::GFx::AS3::Instances::fl::Array *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::Value *callback, Scaleform::GFx::AS3::Value *thisObject)
{
  Scaleform::GFx::AS3::Value *v4; // r15
  Scaleform::GFx::AS3::Instances::fl::Array *v5; // rbx
  unsigned int v6; // ecx
  unsigned int v7; // ecx
  bool v8; // al
  unsigned int v9; // ecx
  Scaleform::GFx::AS3::WeakProxy *v10; // rdx
  int v11; // eax
  long double v12; // rcx
  unsigned __int64 v13; // rdi
  __int64 v14; // r14
  signed __int64 v15; // rcx
  signed __int64 v16; // rax
  signed __int64 v17; // rcx
  int v18; // eax
  __int64 v19; // rdx
  bool v20; // zf
  int v21; // eax
  Scaleform::GFx::ASStringNode *v22; // rcx
  long double v23; // rcx
  int v24; // eax
  Scaleform::GFx::AS3::Value _this; // [rsp+18h] [rbp-79h]
  Scaleform::GFx::AS3::Value resulta; // [rsp+38h] [rbp-59h]
  Scaleform::GFx::AS3::Value argv; // [rsp+58h] [rbp-39h]
  int v28; // [rsp+78h] [rbp-19h]
  __int64 v29; // [rsp+80h] [rbp-11h]
  int v30; // [rsp+88h] [rbp-9h]
  int v31; // [rsp+98h] [rbp+7h]
  __int64 v32; // [rsp+A0h] [rbp+Fh]
  Scaleform::GFx::AS3::Instances::fl::Array *v33; // [rsp+A8h] [rbp+17h]
  __int64 v34; // [rsp+B8h] [rbp+27h]
  unsigned __int64 key; // [rsp+108h] [rbp+77h]

  v34 = -2i64;
  v4 = callback;
  v5 = this;
  v6 = callback->Flags & 0x1F;
  if ( !v6 || (v6 - 12 <= 3 || v6 == 10) && !*(_QWORD *)&callback->value.VNumber )
    return;
  v7 = thisObject->Flags & 0x1F;
  v8 = !v7 || (v7 - 12 <= 3 || v7 == 10) && !*(_QWORD *)&thisObject->value.VNumber;
  if ( v8 )
    thisObject = callback;
  v9 = thisObject->Flags;
  _this.Flags = v9;
  v10 = thisObject->Bonus.pWeakProxy;
  _this.Bonus.pWeakProxy = thisObject->Bonus.pWeakProxy;
  _this.value = thisObject->value;
  v11 = v9 & 0x1F;
  if ( v11 <= 9 )
    goto LABEL_25;
  if ( (v9 >> 9) & 1 )
  {
    ++v10->RefCount;
  }
  else
  {
    if ( v11 == 10 )
    {
      ++*(_DWORD *)(*(_QWORD *)&thisObject->value.VNumber + 24i64);
      goto LABEL_25;
    }
    if ( v11 > 10 )
    {
      if ( v11 <= 15 )
      {
        v12 = thisObject->value.VNumber;
      }
      else
      {
        if ( v11 > 17 )
          goto LABEL_25;
        v12 = *(double *)&thisObject->value.VS._2.VObj;
      }
      if ( v12 != 0.0 )
        *(_DWORD *)(*(_QWORD *)&v12 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v12 + 32i64) + 1) & 0x8FBFFFFF;
      goto LABEL_25;
    }
  }
LABEL_25:
  v13 = 0i64;
  if ( v5->SA.Length <= 0 )
    goto LABEL_64;
  v14 = 0i64;
  while ( 1 )
  {
    key = v13;
    if ( v13 >= v5->SA.ValueA.Data.Size )
    {
      if ( v13 < v5->SA.ValueHLowInd
        || v13 > v5->SA.ValueHHighInd
        || (v16 = Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::findIndexAlt<unsigned __int64>(
                    (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v5->SA.ValueH.mHash.pTable,
                    &key),
            v16 < 0)
        || (v17 = (signed __int64)&v5->SA.ValueH.mHash.pTable[2] + 56 * v16) == 0
        || (v15 = v17 + 8) == 0 )
      {
        v15 = (signed __int64)&v5->SA.DefaultValue;
      }
    }
    else
    {
      v15 = (signed __int64)&v5->SA.ValueA.Data.Data[v14];
    }
    argv.Flags = *(_DWORD *)v15;
    argv.Bonus.pWeakProxy = *(Scaleform::GFx::AS3::WeakProxy **)(v15 + 8);
    argv.value = *(Scaleform::GFx::AS3::Value::VU *)(v15 + 16);
    v18 = *(_DWORD *)v15 & 0x1F;
    if ( v18 > 9 )
    {
      if ( (*(_DWORD *)v15 >> 9) & 1 )
      {
        ++**(_DWORD **)(v15 + 8);
        goto LABEL_47;
      }
      if ( v18 == 10 )
      {
        ++*(_DWORD *)(*(_QWORD *)(v15 + 16) + 24i64);
      }
      else
      {
        if ( v18 <= 10 )
          goto LABEL_47;
        if ( v18 <= 15 )
        {
          v19 = *(_QWORD *)(v15 + 16);
        }
        else
        {
          if ( v18 > 17 )
            goto LABEL_47;
          v19 = *(_QWORD *)(v15 + 24);
        }
        if ( v19 )
          *(_DWORD *)(v19 + 32) = (*(_DWORD *)(v19 + 32) + 1) & 0x8FBFFFFF;
      }
    }
LABEL_47:
    v28 = 3;
    v29 = 0i64;
    v30 = v13;
    v31 = 12;
    v32 = 0i64;
    v33 = v5;
    v5->RefCount = (v5->RefCount + 1) & 0x8FBFFFFF;
    if ( !Scaleform::GFx::AS3::Value::IsCallable(v4) )
      goto LABEL_63;
    resulta.Flags = 0;
    resulta.Bonus.pWeakProxy = 0i64;
    Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(v5->pTraits.pObject->pVM, v4, &_this, &resulta, 3u, &argv, 0);
    if ( v5->pTraits.pObject->pVM->HandleException )
      break;
    if ( (resulta.Flags & 0x1F) > 9 )
    {
      if ( (resulta.Flags >> 9) & 1 )
      {
        v20 = resulta.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v20 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        resulta.Bonus.pWeakProxy = 0i64;
        resulta.value = 0ui64;
        resulta.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&resulta);
      }
    }
    `eh vector destructor iterator'(&argv, 0x20ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
    ++v13;
    ++v14;
    if ( v13 >= v5->SA.Length )
      goto LABEL_64;
  }
  if ( (resulta.Flags & 0x1F) > 9 )
  {
    if ( (resulta.Flags >> 9) & 1 )
    {
      v20 = resulta.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v20 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      resulta.Bonus.pWeakProxy = 0i64;
      resulta.value = 0ui64;
      resulta.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&resulta);
    }
  }
LABEL_63:
  `eh vector destructor iterator'(&argv, 0x20ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
LABEL_64:
  v21 = _this.Flags & 0x1F;
  if ( v21 > 9 )
  {
    if ( (_this.Flags >> 9) & 1 )
    {
      v20 = _this.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v20 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      _this.Bonus.pWeakProxy = 0i64;
      _this.value = 0ui64;
      _this.Flags &= 0xFFFFFDE0;
    }
    else
    {
      switch ( v21 )
      {
        case 10:
          v22 = _this.value.VS._1.VStr;
          v20 = *(_DWORD *)(*(_QWORD *)&_this.value.VNumber + 24i64) == 1;
          --v22->RefCount;
          if ( v20 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v22);
          break;
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
          v23 = _this.value.VNumber;
          if ( !_this.value.VS._1.VBool )
            goto LABEL_76;
          --*(_QWORD *)&_this.value.VNumber;
          break;
        case 16:
        case 17:
          v23 = *(double *)&_this.value.VS._2.VObj;
          if ( (_QWORD)_this.value.VS._2.VObj & 1 )
          {
            --_this.value.VS._2.VObj;
          }
          else
          {
LABEL_76:
            if ( v23 != 0.0 )
            {
              v24 = *(_DWORD *)(*(_QWORD *)&v23 + 32i64);
              if ( v24 & 0x3FFFFF )
              {
                *(_DWORD *)(*(_QWORD *)&v23 + 32i64) = v24 - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(*(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v23);
              }
            }
          }
          break;
        default:
          return;
      }
    }
  }
}

// File Line: 1735
// RVA: 0x7A0290
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::AS3map(Scaleform::GFx::AS3::Instances::fl::Array *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *result, Scaleform::GFx::AS3::Value *callback, Scaleform::GFx::AS3::Value *thisObject)
{
  Scaleform::GFx::AS3::Value *v4; // rdi
  Scaleform::GFx::AS3::Value *v5; // r12
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *v6; // r14
  Scaleform::GFx::AS3::Instances::fl::Array *v7; // rsi
  Scaleform::GFx::AS3::Instances::fl::Array *v8; // rcx
  Scaleform::GFx::AS3::Instances::fl::Array *v9; // rbx
  unsigned int v10; // eax
  int v11; // ecx
  int v12; // ecx
  bool v13; // al
  unsigned int v14; // ecx
  Scaleform::GFx::AS3::WeakProxy *v15; // rdx
  int v16; // eax
  long double v17; // rcx
  Scaleform::GFx::AS3::Instances::fl::Array *v18; // r14
  __int64 v19; // r15
  signed __int64 v20; // rcx
  signed __int64 v21; // rax
  signed __int64 v22; // rcx
  int v23; // eax
  __int64 v24; // rdx
  unsigned __int64 v25; // rcx
  signed __int64 v26; // rcx
  signed __int64 v27; // rdx
  bool v28; // zf
  __int64 v29; // rdx
  int v30; // eax
  long double v31; // rax
  int v32; // eax
  Scaleform::GFx::ASStringNode *v33; // rcx
  long double v34; // rcx
  int v35; // eax
  Scaleform::GFx::AS3::Value v36; // [rsp+40h] [rbp-99h]
  Scaleform::GFx::AS3::Value _this; // [rsp+60h] [rbp-79h]
  Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef key; // [rsp+80h] [rbp-59h]
  Scaleform::GFx::AS3::Value ptr; // [rsp+90h] [rbp-49h]
  int v40; // [rsp+B0h] [rbp-29h]
  __int64 v41; // [rsp+B8h] [rbp-21h]
  int v42; // [rsp+C0h] [rbp-19h]
  int v43; // [rsp+D0h] [rbp-9h]
  __int64 v44; // [rsp+D8h] [rbp-1h]
  Scaleform::GFx::AS3::Instances::fl::Array *v45; // [rsp+E0h] [rbp+7h]
  __int64 v46; // [rsp+F0h] [rbp+17h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> resulta; // [rsp+140h] [rbp+67h]
  __int64 v48; // [rsp+148h] [rbp+6Fh]

  v46 = -2i64;
  v4 = thisObject;
  v5 = callback;
  v6 = result;
  v7 = this;
  Scaleform::GFx::AS3::InstanceTraits::fl::Array::MakeInstance(
    &resulta,
    (Scaleform::GFx::AS3::InstanceTraits::fl::Array *)this->pTraits.pObject);
  v8 = v6->pObject;
  v9 = resulta.pV;
  if ( resulta.pV != v6->pObject )
  {
    if ( v8 )
    {
      if ( (unsigned __int8)v8 & 1 )
      {
        v6->pObject = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)v8 - 1);
      }
      else
      {
        v10 = v8->RefCount;
        if ( v10 & 0x3FFFFF )
        {
          v8->RefCount = v10 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v8->vfptr);
        }
      }
    }
    v6->pObject = v9;
  }
  v11 = v5->Flags & 0x1F;
  if ( !v11 || ((unsigned int)(v11 - 12) <= 3 || v11 == 10) && !*(_QWORD *)&v5->value.VNumber )
    return;
  v12 = v4->Flags & 0x1F;
  v13 = !v12 || ((unsigned int)(v12 - 12) <= 3 || v12 == 10) && !*(_QWORD *)&v4->value.VNumber;
  if ( v13 )
    v4 = v5;
  v14 = v4->Flags;
  _this.Flags = v14;
  v15 = v4->Bonus.pWeakProxy;
  _this.Bonus.pWeakProxy = v4->Bonus.pWeakProxy;
  _this.value = v4->value;
  v16 = v14 & 0x1F;
  if ( v16 <= 9 )
    goto LABEL_32;
  if ( (v14 >> 9) & 1 )
  {
    ++v15->RefCount;
  }
  else
  {
    if ( v16 == 10 )
    {
      ++*(_DWORD *)(*(_QWORD *)&v4->value.VNumber + 24i64);
      goto LABEL_32;
    }
    if ( v16 > 10 )
    {
      if ( v16 <= 15 )
      {
        v17 = v4->value.VNumber;
      }
      else
      {
        if ( v16 > 17 )
          goto LABEL_32;
        v17 = *(double *)&v4->value.VS._2.VObj;
      }
      if ( v17 != 0.0 )
        *(_DWORD *)(*(_QWORD *)&v17 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v17 + 32i64) + 1) & 0x8FBFFFFF;
      goto LABEL_32;
    }
  }
LABEL_32:
  v18 = 0i64;
  if ( v7->SA.Length <= 0 )
    goto LABEL_87;
  v19 = 0i64;
  while ( 1 )
  {
    resulta.pV = v18;
    if ( (unsigned __int64)v18 >= v7->SA.ValueA.Data.Size )
    {
      if ( (unsigned __int64)v18 < v7->SA.ValueHLowInd
        || (unsigned __int64)v18 > v7->SA.ValueHHighInd
        || (v21 = Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::findIndexAlt<unsigned __int64>(
                    (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v7->SA.ValueH.mHash.pTable,
                    (const unsigned __int64 *)&resulta),
            v21 < 0)
        || (v22 = (signed __int64)&v7->SA.ValueH.mHash.pTable[2] + 56 * v21) == 0
        || (v20 = v22 + 8) == 0 )
      {
        v20 = (signed __int64)&v7->SA.DefaultValue;
      }
    }
    else
    {
      v20 = (signed __int64)&v7->SA.ValueA.Data.Data[v19];
    }
    ptr.Flags = *(_DWORD *)v20;
    ptr.Bonus.pWeakProxy = *(Scaleform::GFx::AS3::WeakProxy **)(v20 + 8);
    ptr.value = *(Scaleform::GFx::AS3::Value::VU *)(v20 + 16);
    v23 = *(_DWORD *)v20 & 0x1F;
    if ( v23 > 9 )
    {
      if ( (*(_DWORD *)v20 >> 9) & 1 )
      {
        ++**(_DWORD **)(v20 + 8);
        goto LABEL_54;
      }
      if ( v23 == 10 )
      {
        ++*(_DWORD *)(*(_QWORD *)(v20 + 16) + 24i64);
      }
      else
      {
        if ( v23 <= 10 )
          goto LABEL_54;
        if ( v23 <= 15 )
        {
          v24 = *(_QWORD *)(v20 + 16);
        }
        else
        {
          if ( v23 > 17 )
            goto LABEL_54;
          v24 = *(_QWORD *)(v20 + 24);
        }
        if ( v24 )
          *(_DWORD *)(v24 + 32) = (*(_DWORD *)(v24 + 32) + 1) & 0x8FBFFFFF;
      }
    }
LABEL_54:
    v40 = 3;
    v41 = 0i64;
    v42 = (signed int)v18;
    v43 = 12;
    v44 = 0i64;
    v45 = v7;
    v7->RefCount = (v7->RefCount + 1) & 0x8FBFFFFF;
    if ( !Scaleform::GFx::AS3::Value::IsCallable(v5) )
      goto LABEL_86;
    v36.Flags = 0;
    v36.Bonus.pWeakProxy = 0i64;
    Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(v7->pTraits.pObject->pVM, v5, &_this, &v36, 3u, &ptr, 0);
    if ( v7->pTraits.pObject->pVM->HandleException )
      break;
    v25 = v9->SA.Length;
    if ( v25 == v9->SA.ValueA.Data.Size )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v9->SA.ValueA.Data.Data,
        v9->SA.ValueA.Data.pHeap,
        v9->SA.ValueA.Data.Size + 1);
      v26 = 32 * v9->SA.ValueA.Data.Size;
      v27 = (signed __int64)&v9->SA.ValueA.Data.Data[-1];
      v28 = v26 + v27 == 0;
      v29 = v26 + v27;
      resulta.pV = (Scaleform::GFx::AS3::Instances::fl::Array *)v29;
      v48 = v29;
      if ( v28 )
        goto LABEL_72;
      *(_DWORD *)v29 = v36.Flags;
      *(_QWORD *)(v29 + 8) = v36.Bonus.pWeakProxy;
      *(Scaleform::GFx::AS3::Value::VU *)(v29 + 16) = v36.value;
      v30 = v36.Flags & 0x1F;
      if ( v30 <= 9 )
        goto LABEL_72;
      if ( (v36.Flags >> 9) & 1 )
      {
        ++v36.Bonus.pWeakProxy->RefCount;
      }
      else
      {
        if ( v30 == 10 )
        {
          ++*(_DWORD *)(*(_QWORD *)&v36.value.VNumber + 24i64);
          goto LABEL_72;
        }
        if ( v30 > 10 )
        {
          if ( v30 <= 15 )
          {
            v31 = v36.value.VNumber;
          }
          else
          {
            if ( v30 > 17 )
              goto LABEL_72;
            v31 = *(double *)&v36.value.VS._2.VObj;
          }
          if ( v31 != 0.0 )
          {
            ++*(_DWORD *)(*(_QWORD *)&v31 + 32i64);
            *(_DWORD *)(*(_QWORD *)&v31 + 32i64) &= 0x8FBFFFFF;
          }
          goto LABEL_72;
        }
      }
    }
    else
    {
      v9->SA.ValueHHighInd = v25;
      key.pFirst = &v9->SA.ValueHHighInd;
      key.pSecond = &v36;
      Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
        (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v9->SA.ValueH.mHash.pTable,
        v9->SA.ValueH.mHash.pHeap,
        &key);
    }
LABEL_72:
    ++v9->SA.Length;
    if ( (v36.Flags & 0x1F) > 9 )
    {
      if ( (v36.Flags >> 9) & 1 )
      {
        v28 = v36.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v28 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v36.Bonus.pWeakProxy = 0i64;
        v36.value = 0ui64;
        v36.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v36);
      }
    }
    `eh vector destructor iterator'(&ptr, 0x20ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
    v18 = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)v18 + 1);
    ++v19;
    if ( (unsigned __int64)v18 >= v7->SA.Length )
      goto LABEL_87;
  }
  if ( (v36.Flags & 0x1F) > 9 )
  {
    if ( (v36.Flags >> 9) & 1 )
    {
      v28 = v36.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v28 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v36.Bonus.pWeakProxy = 0i64;
      v36.value = 0ui64;
      v36.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v36);
    }
  }
LABEL_86:
  `eh vector destructor iterator'(&ptr, 0x20ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
LABEL_87:
  v32 = _this.Flags & 0x1F;
  if ( v32 > 9 )
  {
    if ( (_this.Flags >> 9) & 1 )
    {
      v28 = _this.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v28 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      _this.Bonus.pWeakProxy = 0i64;
      _this.value = 0ui64;
      _this.Flags &= 0xFFFFFDE0;
    }
    else
    {
      switch ( v32 )
      {
        case 10:
          v33 = _this.value.VS._1.VStr;
          v28 = *(_DWORD *)(*(_QWORD *)&_this.value.VNumber + 24i64) == 1;
          --v33->RefCount;
          if ( v28 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v33);
          break;
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
          v34 = _this.value.VNumber;
          if ( !_this.value.VS._1.VBool )
            goto LABEL_99;
          --*(_QWORD *)&_this.value.VNumber;
          break;
        case 16:
        case 17:
          v34 = *(double *)&_this.value.VS._2.VObj;
          if ( (_QWORD)_this.value.VS._2.VObj & 1 )
          {
            --_this.value.VS._2.VObj;
          }
          else
          {
LABEL_99:
            if ( v34 != 0.0 )
            {
              v35 = *(_DWORD *)(*(_QWORD *)&v34 + 32i64);
              if ( v35 & 0x3FFFFF )
              {
                *(_DWORD *)(*(_QWORD *)&v34 + 32i64) = v35 - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(*(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v34);
              }
            }
          }
          break;
        default:
          return;
      }
    }
  }
}

// File Line: 1765
// RVA: 0x7A40A0
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::AS3some(Scaleform::GFx::AS3::Instances::fl::Array *this, bool *result, Scaleform::GFx::AS3::Value *callback, Scaleform::GFx::AS3::Value *thisObject)
{
  Scaleform::GFx::AS3::Value *v4; // r15
  bool *v5; // r12
  Scaleform::GFx::AS3::Instances::fl::Array *v6; // rbx
  unsigned int v7; // ecx
  unsigned int v8; // ecx
  bool v9; // al
  unsigned int v10; // ecx
  Scaleform::GFx::AS3::WeakProxy *v11; // rdx
  int v12; // eax
  long double v13; // rcx
  unsigned __int64 v14; // rdi
  __int64 v15; // r14
  signed __int64 v16; // rcx
  signed __int64 v17; // rax
  signed __int64 v18; // rcx
  int v19; // eax
  __int64 v20; // rdx
  bool v21; // zf
  int v22; // eax
  Scaleform::GFx::ASStringNode *v23; // rcx
  long double v24; // rcx
  int v25; // eax
  Scaleform::GFx::AS3::Value resulta; // [rsp+18h] [rbp-79h]
  Scaleform::GFx::AS3::Value _this; // [rsp+38h] [rbp-59h]
  Scaleform::GFx::AS3::Value argv; // [rsp+58h] [rbp-39h]
  int v29; // [rsp+78h] [rbp-19h]
  __int64 v30; // [rsp+80h] [rbp-11h]
  int v31; // [rsp+88h] [rbp-9h]
  int v32; // [rsp+98h] [rbp+7h]
  __int64 v33; // [rsp+A0h] [rbp+Fh]
  Scaleform::GFx::AS3::Instances::fl::Array *v34; // [rsp+A8h] [rbp+17h]
  __int64 v35; // [rsp+B8h] [rbp+27h]
  unsigned __int64 key; // [rsp+108h] [rbp+77h]

  v35 = -2i64;
  v4 = callback;
  v5 = result;
  v6 = this;
  v7 = callback->Flags & 0x1F;
  if ( !v7 || (v7 - 12 <= 3 || v7 == 10) && !*(_QWORD *)&callback->value.VNumber )
  {
LABEL_93:
    *v5 = 0;
    return;
  }
  v8 = thisObject->Flags & 0x1F;
  v9 = !v8 || (v8 - 12 <= 3 || v8 == 10) && !*(_QWORD *)&thisObject->value.VNumber;
  if ( v9 )
    thisObject = callback;
  v10 = thisObject->Flags;
  _this.Flags = v10;
  v11 = thisObject->Bonus.pWeakProxy;
  _this.Bonus.pWeakProxy = thisObject->Bonus.pWeakProxy;
  _this.value = thisObject->value;
  v12 = v10 & 0x1F;
  if ( v12 > 9 )
  {
    if ( (v10 >> 9) & 1 )
    {
      ++v11->RefCount;
      goto LABEL_25;
    }
    if ( v12 == 10 )
    {
      ++*(_DWORD *)(*(_QWORD *)&thisObject->value.VNumber + 24i64);
    }
    else
    {
      if ( v12 <= 10 )
        goto LABEL_25;
      if ( v12 <= 15 )
      {
        v13 = thisObject->value.VNumber;
      }
      else
      {
        if ( v12 > 17 )
          goto LABEL_25;
        v13 = *(double *)&thisObject->value.VS._2.VObj;
      }
      if ( v13 != 0.0 )
        *(_DWORD *)(*(_QWORD *)&v13 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v13 + 32i64) + 1) & 0x8FBFFFFF;
    }
  }
LABEL_25:
  v14 = 0i64;
  if ( v6->SA.Length <= 0 )
  {
LABEL_78:
    v22 = _this.Flags & 0x1F;
    if ( v22 > 9 )
    {
      if ( (_this.Flags >> 9) & 1 )
      {
        v21 = _this.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v21 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        _this.Bonus.pWeakProxy = 0i64;
        _this.value = 0ui64;
        _this.Flags &= 0xFFFFFDE0;
      }
      else
      {
        switch ( v22 )
        {
          case 10:
            v23 = _this.value.VS._1.VStr;
            v21 = *(_DWORD *)(*(_QWORD *)&_this.value.VNumber + 24i64) == 1;
            --v23->RefCount;
            if ( v21 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v23);
            break;
          case 11:
          case 12:
          case 13:
          case 14:
          case 15:
            v24 = _this.value.VNumber;
            if ( !_this.value.VS._1.VBool )
              goto LABEL_90;
            --*(_QWORD *)&_this.value.VNumber;
            break;
          case 16:
          case 17:
            v24 = *(double *)&_this.value.VS._2.VObj;
            if ( (_QWORD)_this.value.VS._2.VObj & 1 )
            {
              --_this.value.VS._2.VObj;
            }
            else
            {
LABEL_90:
              if ( v24 != 0.0 )
              {
                v25 = *(_DWORD *)(*(_QWORD *)&v24 + 32i64);
                if ( v25 & 0x3FFFFF )
                {
                  *(_DWORD *)(*(_QWORD *)&v24 + 32i64) = v25 - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(*(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v24);
                }
              }
            }
            break;
          default:
            goto LABEL_93;
        }
      }
    }
    goto LABEL_93;
  }
  v15 = 0i64;
  while ( 1 )
  {
    key = v14;
    if ( v14 >= v6->SA.ValueA.Data.Size )
    {
      if ( v14 < v6->SA.ValueHLowInd
        || v14 > v6->SA.ValueHHighInd
        || (v17 = Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::findIndexAlt<unsigned __int64>(
                    (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v6->SA.ValueH.mHash.pTable,
                    &key),
            v17 < 0)
        || (v18 = (signed __int64)&v6->SA.ValueH.mHash.pTable[2] + 56 * v17) == 0
        || (v16 = v18 + 8) == 0 )
      {
        v16 = (signed __int64)&v6->SA.DefaultValue;
      }
    }
    else
    {
      v16 = (signed __int64)&v6->SA.ValueA.Data.Data[v15];
    }
    argv.Flags = *(_DWORD *)v16;
    argv.Bonus.pWeakProxy = *(Scaleform::GFx::AS3::WeakProxy **)(v16 + 8);
    argv.value = *(Scaleform::GFx::AS3::Value::VU *)(v16 + 16);
    v19 = *(_DWORD *)v16 & 0x1F;
    if ( v19 > 9 )
    {
      if ( (*(_DWORD *)v16 >> 9) & 1 )
      {
        ++**(_DWORD **)(v16 + 8);
        goto LABEL_47;
      }
      if ( v19 == 10 )
      {
        ++*(_DWORD *)(*(_QWORD *)(v16 + 16) + 24i64);
      }
      else
      {
        if ( v19 <= 10 )
          goto LABEL_47;
        if ( v19 <= 15 )
        {
          v20 = *(_QWORD *)(v16 + 16);
        }
        else
        {
          if ( v19 > 17 )
            goto LABEL_47;
          v20 = *(_QWORD *)(v16 + 24);
        }
        if ( v20 )
          *(_DWORD *)(v20 + 32) = (*(_DWORD *)(v20 + 32) + 1) & 0x8FBFFFFF;
      }
    }
LABEL_47:
    v29 = 3;
    v30 = 0i64;
    v31 = v14;
    v32 = 12;
    v33 = 0i64;
    v34 = v6;
    v6->RefCount = (v6->RefCount + 1) & 0x8FBFFFFF;
    if ( !Scaleform::GFx::AS3::Value::IsCallable(v4) )
      goto LABEL_77;
    resulta.Flags = 0;
    resulta.Bonus.pWeakProxy = 0i64;
    Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(v6->pTraits.pObject->pVM, v4, &_this, &resulta, 3u, &argv, 0);
    if ( v6->pTraits.pObject->pVM->HandleException )
    {
      if ( (resulta.Flags & 0x1F) > 9 )
      {
        if ( (resulta.Flags >> 9) & 1 )
        {
          v21 = resulta.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v21 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          resulta.Bonus.pWeakProxy = 0i64;
          resulta.value = 0ui64;
          resulta.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&resulta);
        }
      }
LABEL_77:
      `eh vector destructor iterator'(
        &argv,
        0x20ui64,
        3,
        (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
      goto LABEL_78;
    }
    if ( (resulta.Flags & 0x1F) != 1 || resulta.value.VS._1.VBool == 1 )
      break;
    if ( (resulta.Flags & 0x1F) > 9 )
    {
      if ( (resulta.Flags >> 9) & 1 )
      {
        v21 = resulta.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v21 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        resulta.Bonus.pWeakProxy = 0i64;
        resulta.value = 0ui64;
        resulta.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&resulta);
      }
    }
    `eh vector destructor iterator'(&argv, 0x20ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
    ++v14;
    ++v15;
    if ( v14 >= v6->SA.Length )
      goto LABEL_78;
  }
  *v5 = 1;
  if ( (resulta.Flags & 0x1F) > 9 )
  {
    if ( (resulta.Flags >> 9) & 1 )
    {
      v21 = resulta.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v21 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      resulta.Bonus.pWeakProxy = 0i64;
      resulta.value = 0ui64;
      resulta.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&resulta);
    }
  }
  `eh vector destructor iterator'(&argv, 0x20ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
  if ( (_this.Flags & 0x1F) > 9 )
  {
    if ( (_this.Flags >> 9) & 1 )
    {
      v21 = _this.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v21 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      _this.Bonus.pWeakProxy = 0i64;
      _this.value = 0ui64;
      _this.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
    }
  }
}

// File Line: 1798
// RVA: 0x75D840
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::toLocaleStringProto(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value *v4; // rbx
  Scaleform::GFx::ASString *v5; // rax
  Scaleform::GFx::ASStringNode *v6; // rcx
  bool v7; // zf
  Scaleform::GFx::ASString resulta; // [rsp+50h] [rbp+18h]

  v4 = result;
  v5 = Scaleform::GFx::AS3::Instances::fl::Array::ToLocaleStringInternal(
         (Scaleform::GFx::AS3::Instances::fl::Array *)_this->value.VS._1.VStr,
         &resulta);
  Scaleform::GFx::AS3::Value::Assign(v4, v5);
  v6 = resulta.pNode;
  v7 = resulta.pNode->RefCount == 1;
  --v6->RefCount;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
}

// File Line: 1810
// RVA: 0x75E670
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::toStringProto(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value *v4; // rbx
  Scaleform::GFx::ASString *v5; // rax
  Scaleform::GFx::ASStringNode *v6; // rcx
  bool v7; // zf
  Scaleform::GFx::ASString resulta; // [rsp+48h] [rbp+10h]

  v4 = result;
  v5 = Scaleform::GFx::AS3::Instances::fl::Array::ToStringInternal(
         (Scaleform::GFx::AS3::Instances::fl::Array *)_this->value.VS._1.VStr,
         &resulta,
         (Scaleform::GFx::ASString *)&vm->StringManagerRef->Builtins[14]);
  Scaleform::GFx::AS3::Value::Assign(v4, v5);
  v6 = resulta.pNode;
  v7 = resulta.pNode->RefCount == 1;
  --v6->RefCount;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
}

// File Line: 1823
// RVA: 0x7D5380
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::ForEachChild_GC(Scaleform::GFx::AS3::Instances::fl::Array *this, Scaleform::GFx::AS3::RefCountCollector<328> *prcc, void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  void (__fastcall *v3)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **); // rdi
  Scaleform::GFx::AS3::RefCountCollector<328> *v4; // rsi
  Scaleform::GFx::AS3::Instances::fl::Array *v5; // rbx

  v3 = op;
  v4 = prcc;
  v5 = this;
  Scaleform::GFx::AS3::Object::ForEachChild_GC((Scaleform::GFx::AS3::Object *)&this->vfptr, prcc, op);
  Scaleform::GFx::AS3::Impl::SparseArray::ForEachChild_GC(&v5->SA, v4, v3);
}

// File Line: 1830
// RVA: 0x794C90
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::AS3Constructor(Scaleform::GFx::AS3::Instances::fl::Array *this, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::Instances::fl::Array *v4; // rdi
  unsigned int v5; // er9
  Scaleform::GFx::AS3::VM::Error *v6; // rax
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  long double iptr; // [rsp+28h] [rbp-30h]
  Scaleform::GFx::AS3::VM::Error v11; // [rsp+30h] [rbp-28h]
  Scaleform::GFx::AS3::CheckResult result; // [rsp+68h] [rbp+10h]
  long double v13; // [rsp+78h] [rbp+20h]

  v3 = argv;
  v4 = this;
  if ( argc != 1 || (v5 = argv->Flags & 0x1F, v5 - 2 > 2) )
  {
    Scaleform::GFx::AS3::Impl::SparseArray::Append(&this->SA, argc, argv);
  }
  else
  {
    if ( v5 != 4 || modf(argv->value.VNumber, &iptr) == 0.0 )
    {
      if ( !Scaleform::GFx::AS3::Value::Convert2Number(v3, &result, &v13)->Result )
        return;
      if ( v13 >= 0.0 )
      {
        Scaleform::GFx::AS3::Impl::SparseArray::Resize(&v4->SA, (unsigned int)(signed int)v13);
        return;
      }
      Scaleform::GFx::AS3::VM::Error::Error(&v11, eArrayIndexNotIntegerError, v4->pTraits.pObject->pVM);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v4->pTraits.pObject->pVM, v9, &Scaleform::GFx::AS3::fl::RangeErrorTI);
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v11, eArrayIndexNotIntegerError, v4->pTraits.pObject->pVM);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v4->pTraits.pObject->pVM, v6, &Scaleform::GFx::AS3::fl::RangeErrorTI);
    }
    v7 = v11.Message.pNode;
    v8 = v11.Message.pNode->RefCount == 1;
    --v7->RefCount;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  }
}

// File Line: 1871
// RVA: 0x826810
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::Instances::fl::Array::ToStringInternal(Scaleform::GFx::AS3::Instances::fl::Array *this, Scaleform::GFx::ASString *result, Scaleform::GFx::ASString *sep)
{
  const char ***v3; // r15
  Scaleform::GFx::ASString *v4; // rbp
  Scaleform::GFx::AS3::Instances::fl::Array *v5; // rdi
  unsigned __int64 v6; // rbx
  __int64 v7; // r14
  Scaleform::GFx::AS3::Value *v8; // rcx
  signed __int64 v9; // rax
  signed __int64 v10; // rcx
  int v11; // edx
  char *v12; // r8
  Scaleform::StringBuffer v14; // [rsp+30h] [rbp-58h]
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+90h] [rbp+8h]
  Scaleform::GFx::ASString *v16; // [rsp+98h] [rbp+10h]
  unsigned __int64 key; // [rsp+A8h] [rbp+20h]

  v16 = result;
  v3 = (const char ***)sep;
  v4 = result;
  v5 = this;
  v6 = 0i64;
  Scaleform::StringBuffer::StringBuffer(&v14, this->pTraits.pObject->pVM->MHeap);
  if ( v5->SA.Length > 0 )
  {
    v7 = 0i64;
    do
    {
      if ( v6 )
        Scaleform::StringBuffer::AppendString(&v14, **v3, -1i64);
      key = v6;
      if ( v6 >= v5->SA.ValueA.Data.Size )
      {
        if ( v6 < v5->SA.ValueHLowInd
          || v6 > v5->SA.ValueHHighInd
          || (v9 = Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::findIndexAlt<unsigned __int64>(
                     (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v5->SA.ValueH.mHash.pTable,
                     &key),
              v9 < 0)
          || (v10 = (signed __int64)&v5->SA.ValueH.mHash.pTable[2] + 56 * v9) == 0
          || (v8 = (Scaleform::GFx::AS3::Value *)(v10 + 8)) == 0i64 )
        {
          v8 = &v5->SA.DefaultValue;
        }
      }
      else
      {
        v8 = &v5->SA.ValueA.Data.Data[v7];
      }
      v11 = v8->Flags & 0x1F;
      if ( v11
        && ((unsigned int)(v11 - 12) > 3 && v11 != 10 || *(_QWORD *)&v8->value.VNumber)
        && !Scaleform::GFx::AS3::Value::Convert2String(v8, &resulta, &v14)->Result )
      {
        break;
      }
      ++v6;
      ++v7;
    }
    while ( v6 < v5->SA.Length );
  }
  v12 = &customWorldMapCaption;
  if ( v14.pData )
    v12 = v14.pData;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v5->pTraits.pObject->pVM->StringManagerRef->Builtins,
    v4,
    v12,
    v14.Size);
  Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&v14);
  return v4;
}

// File Line: 1893
// RVA: 0x825C80
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::Instances::fl::Array::ToLocaleStringInternal(Scaleform::GFx::AS3::Instances::fl::Array *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::Instances::fl::Array *v2; // r12
  unsigned __int64 v3; // r14
  Scaleform::GFx::AS3::Value *v4; // r15
  signed __int64 v5; // rax
  signed __int64 v6; // rdx
  int v7; // ecx
  long double *v8; // rax
  unsigned int v9; // edi
  long double v10; // rbx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v11; // r13
  Scaleform::GFx::AS3::GASRefCountBase *v12; // rdx
  int v13; // esi
  __int64 v14; // rax
  Scaleform::GFx::AS3::GASRefCountBase *v15; // r14
  Scaleform::GFx::AS3::GASRefCountBase *v16; // rcx
  unsigned int v17; // eax
  Scaleform::GFx::ASString *v18; // rax
  Scaleform::GFx::ASStringNode *v19; // rcx
  bool v20; // zf
  Scaleform::GFx::ASStringNode *v21; // rcx
  int v22; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v23; // rcx
  unsigned int v24; // eax
  Scaleform::GFx::ASStringNode *v25; // rcx
  __int64 v26; // r8
  const char ***v27; // rax
  __int64 v28; // r8
  Scaleform::GFx::ASStringNode *v29; // rcx
  const char ***v30; // rax
  Scaleform::GFx::AS3::WeakProxy *v31; // rdx
  Scaleform::GFx::AS3::WeakProxy *v32; // rdx
  Scaleform::GFx::AS3::GASRefCountBase *v33; // rcx
  unsigned int v34; // eax
  Scaleform::GFx::AS3::WeakProxy *v35; // rdx
  Scaleform::GFx::AS3::WeakProxy *v36; // rdx
  Scaleform::GFx::AS3::GASRefCountBase *v37; // rcx
  unsigned int v38; // eax
  char *v39; // r8
  Scaleform::GFx::AS3::Multiname prop_name; // [rsp+40h] [rbp-C0h]
  Scaleform::GFx::AS3::Value value; // [rsp+70h] [rbp-90h]
  __int64 v43; // [rsp+90h] [rbp-70h]
  __int64 v44; // [rsp+98h] [rbp-68h]
  long double v45; // [rsp+A0h] [rbp-60h]
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v46; // [rsp+A8h] [rbp-58h]
  int v47; // [rsp+B0h] [rbp-50h]
  Scaleform::GFx::ASString resulta; // [rsp+B8h] [rbp-48h]
  unsigned __int64 key; // [rsp+C0h] [rbp-40h]
  Scaleform::GFx::ASString v50; // [rsp+C8h] [rbp-38h]
  Scaleform::GFx::ASString v51; // [rsp+D0h] [rbp-30h]
  Scaleform::GFx::ASString v52; // [rsp+D8h] [rbp-28h]
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v53; // [rsp+E0h] [rbp-20h]
  Scaleform::StringBuffer v54; // [rsp+E8h] [rbp-18h]
  __int64 v55; // [rsp+118h] [rbp+18h]
  Scaleform::GFx::AS3::CheckResult v56; // [rsp+170h] [rbp+70h]
  Scaleform::GFx::ASString *v57; // [rsp+178h] [rbp+78h]
  Scaleform::GFx::ASString v58; // [rsp+180h] [rbp+80h]
  unsigned __int64 v59; // [rsp+188h] [rbp+88h]

  v57 = result;
  v55 = -2i64;
  v2 = this;
  v47 = 0;
  Scaleform::StringBuffer::StringBuffer(&v54, this->pTraits.pObject->pVM->MHeap);
  v3 = 0i64;
  v59 = 0i64;
  if ( v2->SA.Length <= 0 )
    goto LABEL_117;
  while ( 1 )
  {
    if ( v3 )
      Scaleform::StringBuffer::AppendString(&v54, ",", -1i64);
    key = v3;
    if ( v3 >= v2->SA.ValueA.Data.Size )
    {
      if ( v3 < v2->SA.ValueHLowInd
        || v3 > v2->SA.ValueHHighInd
        || (v5 = Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::findIndexAlt<unsigned __int64>(
                   (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v2->SA.ValueH.mHash.pTable,
                   &key),
            v5 < 0)
        || (v6 = (signed __int64)&v2->SA.ValueH.mHash.pTable[2] + 56 * v5) == 0
        || (v4 = (Scaleform::GFx::AS3::Value *)(v6 + 8), v6 == -8) )
      {
        v4 = &v2->SA.DefaultValue;
      }
    }
    else
    {
      v4 = &v2->SA.ValueA.Data.Data[v3];
    }
    v7 = v4->Flags & 0x1F;
    if ( !v7 || ((unsigned int)(v7 - 12) <= 3 || v7 == 10) && !*(_QWORD *)&v4->value.VNumber )
      goto LABEL_98;
    v8 = (long double *)Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                          (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v2->pTraits.pObject->pVM->StringManagerRef->Builtins,
                          &resulta,
                          "toLocaleString");
    v9 = 10;
    LODWORD(v43) = 10;
    v44 = 0i64;
    v10 = *v8;
    v45 = v10;
    if ( *(_QWORD *)&v10 == *(_QWORD *)(*(_QWORD *)&v10 + 8i64) + 104i64 )
    {
      v10 = 0.0;
      v45 = 0.0;
      v11 = v53;
      v46 = v53;
      v9 = 12;
      LODWORD(v43) = 12;
    }
    else
    {
      ++*(_DWORD *)(*(_QWORD *)&v10 + 24i64);
      v11 = v46;
    }
    v12 = (Scaleform::GFx::AS3::GASRefCountBase *)&v2->pTraits.pObject->pVM->PublicNamespace.pObject->vfptr;
    prop_name.Kind = 0;
    prop_name.Obj.pObject = v12;
    if ( v12 )
      v12->RefCount = (v12->RefCount + 1) & 0x8FBFFFFF;
    prop_name.Name.Flags = 0;
    prop_name.Name.Bonus.pWeakProxy = 0i64;
    v13 = v9 & 0x1F;
    if ( (unsigned int)(v13 - 12) <= 3
      && v10 != 0.0
      && (v14 = *(_QWORD *)(*(_QWORD *)&v10 + 40i64), *(_DWORD *)(v14 + 120) == 17)
      && ~(*(_BYTE *)(v14 + 112) >> 5) & 1 )
    {
      Scaleform::GFx::AS3::Value::Assign(&prop_name.Name, (Scaleform::GFx::ASString *)(*(_QWORD *)&v10 + 56i64));
      v15 = *(Scaleform::GFx::AS3::GASRefCountBase **)(*(_QWORD *)&v10 + 64i64);
      v16 = prop_name.Obj.pObject;
      if ( v15 != prop_name.Obj.pObject )
      {
        if ( v15 )
        {
          v15->RefCount = (v15->RefCount + 1) & 0x8FBFFFFF;
          v16 = prop_name.Obj.pObject;
        }
        if ( v16 )
        {
          if ( (_QWORD)prop_name.Obj.pObject & 1 )
          {
            prop_name.Obj.pObject = (Scaleform::GFx::AS3::GASRefCountBase *)((char *)v16 - 1);
          }
          else
          {
            v17 = v16->RefCount;
            if ( v17 & 0x3FFFFF )
            {
              v16->RefCount = v17 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v16->vfptr);
            }
          }
        }
        prop_name.Obj.pObject = v15;
      }
      prop_name.Kind &= 0xFFFFFFF9;
      v3 = v59;
    }
    else
    {
      __asm { prefetcht1 byte ptr [rbp+60h+var_D0]; Prefetch to all cache levels }
      *(_QWORD *)&prop_name.Name.Flags = v43;
      prop_name.Name.Bonus.pWeakProxy = 0i64;
      prop_name.Name.value.VNumber = v10;
      prop_name.Name.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v11;
      if ( v13 > 9 )
      {
        if ( (v9 >> 9) & 1 )
        {
          LODWORD(MEMORY[0]) = MEMORY[0] + 1;
        }
        else if ( v13 == 10 )
        {
          ++*(_DWORD *)(*(_QWORD *)&v10 + 24i64);
        }
        else if ( v13 > 10 )
        {
          if ( v13 <= 15 )
          {
            if ( v10 != 0.0 )
              *(_DWORD *)(*(_QWORD *)&v10 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v10 + 32i64) + 1) & 0x8FBFFFFF;
          }
          else if ( v13 <= 17 && v11 )
          {
            v11->RefCount = (v11->RefCount + 1) & 0x8FBFFFFF;
          }
        }
      }
      if ( (prop_name.Name.Flags & 0x1F) == 10 )
      {
        Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&prop_name.Name, &v58);
        if ( v58.pNode->Size )
        {
          if ( *v58.pNode->pData == 64 )
          {
            prop_name.Kind |= 8u;
            v18 = Scaleform::GFx::ASString::Substring(&v58, &v50, 1, v58.pNode->Size);
            Scaleform::GFx::AS3::Value::Assign(&prop_name.Name, v18);
            v19 = v50.pNode;
            v20 = v50.pNode->RefCount == 1;
            --v19->RefCount;
            if ( v20 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v19);
          }
        }
        v21 = v58.pNode;
        v20 = v58.pNode->RefCount == 1;
        --v21->RefCount;
        if ( v20 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v21);
      }
    }
    if ( v13 > 9 )
    {
      if ( (v9 >> 9) & 1 )
      {
        LODWORD(MEMORY[0]) = MEMORY[0] - 1;
        if ( !(_DWORD)MEMORY[0] )
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
        v44 = 0i64;
        v45 = 0.0;
        v46 = 0i64;
        LODWORD(v43) = v9 & 0xFFFFFDE0;
      }
      else
      {
        switch ( v13 )
        {
          case 10:
            v20 = (*(_DWORD *)(*(_QWORD *)&v10 + 24i64))-- == 1;
            if ( v20 )
              Scaleform::GFx::ASStringNode::ReleaseNode(*(Scaleform::GFx::ASStringNode **)&v10);
            break;
          case 11:
          case 12:
          case 13:
          case 14:
          case 15:
            if ( LOBYTE(v45) & 1 )
            {
              *(_QWORD *)&v45 = *(_QWORD *)&v10 - 1i64;
            }
            else if ( v10 != 0.0 )
            {
              v22 = *(_DWORD *)(*(_QWORD *)&v10 + 32i64);
              if ( v22 & 0x3FFFFF )
              {
                *(_DWORD *)(*(_QWORD *)&v10 + 32i64) = v22 - 1;
                v23 = *(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v10;
                goto LABEL_72;
              }
            }
            break;
          case 16:
          case 17:
            if ( (unsigned __int8)v46 & 1 )
            {
              v46 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v11 - 1);
            }
            else if ( v11 )
            {
              v24 = v11->RefCount;
              if ( v24 & 0x3FFFFF )
              {
                v11->RefCount = v24 - 1;
                v23 = v11;
LABEL_72:
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v23);
              }
            }
            break;
          default:
            break;
        }
      }
    }
    v25 = resulta.pNode;
    v20 = resulta.pNode->RefCount == 1;
    --v25->RefCount;
    if ( v20 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v25);
    value.Flags = 0;
    value.Bonus.pWeakProxy = 0i64;
    if ( !Scaleform::GFx::AS3::ExecutePropertyUnsafe(&v56, v2->pTraits.pObject->pVM, &prop_name, v4)->Result )
      break;
    if ( (value.Flags & 0x1F) == 10 )
    {
      v27 = (const char ***)Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&value, &v51);
      Scaleform::StringBuffer::AppendString(&v54, **v27, -1i64);
      v29 = v51.pNode;
    }
    else
    {
      v30 = (const char ***)Scaleform::GFx::AS3::AsString(&v52, &value, v2->pTraits.pObject->pVM->StringManagerRef);
      Scaleform::StringBuffer::AppendString(&v54, **v30, -1i64);
      v29 = v52.pNode;
    }
    v20 = v29->RefCount-- == 1;
    if ( v20 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v29);
    if ( (value.Flags & 0x1F) > 9 )
    {
      if ( (value.Flags >> 9) & 1 )
      {
        v31 = value.Bonus.pWeakProxy;
        v20 = value.Bonus.pWeakProxy->RefCount == 1;
        --v31->RefCount;
        if ( v20 )
          ((void (__cdecl *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::WeakProxy *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
            Scaleform::Memory::pGlobalHeap,
            v31,
            v28);
        value.Bonus.pWeakProxy = 0i64;
        value.value = 0ui64;
        value.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
      }
    }
    if ( (prop_name.Name.Flags & 0x1F) > 9 )
    {
      if ( (prop_name.Name.Flags >> 9) & 1 )
      {
        v32 = prop_name.Name.Bonus.pWeakProxy;
        v20 = prop_name.Name.Bonus.pWeakProxy->RefCount == 1;
        --v32->RefCount;
        if ( v20 )
          ((void (__cdecl *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::WeakProxy *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
            Scaleform::Memory::pGlobalHeap,
            v32,
            v28);
        prop_name.Name.Bonus.pWeakProxy = 0i64;
        prop_name.Name.value = 0ui64;
        prop_name.Name.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&prop_name.Name);
      }
    }
    v33 = prop_name.Obj.pObject;
    if ( prop_name.Obj.pObject )
    {
      if ( (_QWORD)prop_name.Obj.pObject & 1 )
      {
        --prop_name.Obj.pObject;
      }
      else
      {
        v34 = prop_name.Obj.pObject->RefCount;
        if ( v34 & 0x3FFFFF )
        {
          prop_name.Obj.pObject->RefCount = v34 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v33->vfptr);
        }
      }
    }
LABEL_98:
    v59 = ++v3;
    if ( v3 >= v2->SA.Length )
      goto LABEL_117;
  }
  if ( (value.Flags & 0x1F) > 9 )
  {
    if ( (value.Flags >> 9) & 1 )
    {
      v35 = value.Bonus.pWeakProxy;
      v20 = value.Bonus.pWeakProxy->RefCount == 1;
      --v35->RefCount;
      if ( v20 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::WeakProxy *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v35,
          v26);
      value.Bonus.pWeakProxy = 0i64;
      value.value = 0ui64;
      value.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
    }
  }
  if ( (prop_name.Name.Flags & 0x1F) > 9 )
  {
    if ( (prop_name.Name.Flags >> 9) & 1 )
    {
      v36 = prop_name.Name.Bonus.pWeakProxy;
      v20 = prop_name.Name.Bonus.pWeakProxy->RefCount == 1;
      --v36->RefCount;
      if ( v20 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::WeakProxy *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v36,
          v26);
      prop_name.Name.Bonus.pWeakProxy = 0i64;
      prop_name.Name.value = 0ui64;
      prop_name.Name.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&prop_name.Name);
    }
  }
  v37 = prop_name.Obj.pObject;
  if ( prop_name.Obj.pObject )
  {
    if ( (_QWORD)prop_name.Obj.pObject & 1 )
    {
      --prop_name.Obj.pObject;
    }
    else
    {
      v38 = prop_name.Obj.pObject->RefCount;
      if ( v38 & 0x3FFFFF )
      {
        prop_name.Obj.pObject->RefCount = v38 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v37->vfptr);
      }
    }
  }
LABEL_117:
  v39 = &customWorldMapCaption;
  if ( v54.pData )
    v39 = v54.pData;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v2->pTraits.pObject->pVM->StringManagerRef->Builtins,
    v57,
    v39,
    v54.Size);
  v47 = 1;
  Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&v54);
  return v57;
} v54.Size);
  v47 = 1;
  Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFo

// File Line: 1923
// RVA: 0x7ECD60
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::GetNextPropertyName(Scaleform::GFx::AS3::Instances::fl::Array *this, Scaleform::GFx::AS3::Value *name, Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
  Scaleform::GFx::AS3::Value *v3; // r9
  unsigned int v4; // er8
  Scaleform::HashLH<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor,2,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *v5; // r10
  Scaleform::HashLH<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor,2,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *v6; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *v7; // rcx
  unsigned __int64 v8; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *v9; // rcx

  v3 = name;
  if ( ind.Index )
  {
    if ( ind.Index > this->SA.Length )
    {
      v4 = ind.Index - LODWORD(this->SA.Length);
      v5 = &this->DynAttrs;
      v6 = 0i64;
      v7 = this->DynAttrs.mHash.pTable;
      if ( v7 )
      {
        v8 = v7->SizeMask;
        v9 = v7 + 1;
        do
        {
          if ( v9->EntryCount != -2i64 )
            break;
          v6 = (Scaleform::HashLH<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor,2,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *)((char *)v6 + 1);
          v9 += 4;
        }
        while ( (unsigned __int64)v6 <= v8 );
        v6 = v5;
      }
      Scaleform::GFx::AS3::Value::Assign(
        v3,
        (Scaleform::GFx::ASString *)&v6->mHash.pTable[4 * (unsigned __int64)(v4 - 1) + 2].SizeMask);
    }
    else
    {
      Scaleform::GFx::AS3::Value::SetUInt32(name, ind.Index - 1);
    }
  }
  else
  {
    Scaleform::GFx::AS3::Value::SetUndefined(name);
  }
}

// File Line: 1934
// RVA: 0x7ECB30
Scaleform::GFx::AS3::GlobalSlotIndex *__fastcall Scaleform::GFx::AS3::Instances::fl::Array::GetNextDynPropIndex(Scaleform::GFx::AS3::Instances::fl::Array *this, Scaleform::GFx::AS3::GlobalSlotIndex *result, Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
  Scaleform::GFx::AS3::GlobalSlotIndex *v3; // rbx
  Scaleform::GFx::AS3::Instances::fl::Array *v4; // rsi
  Scaleform::GFx::AS3::GlobalSlotIndex *v5; // rax
  unsigned int v6; // edi
  Scaleform::GFx::AS3::GlobalSlotIndex *v7; // rax
  unsigned int v8; // ecx
  Scaleform::GFx::AS3::AbsoluteIndex resulta; // [rsp+30h] [rbp+8h]
  unsigned int v10; // [rsp+40h] [rbp+18h]

  v10 = ind.Index;
  v3 = result;
  v4 = this;
  result->Index = 0;
  if ( ind.Index <= this->SA.Length )
  {
    Scaleform::GFx::AS3::Impl::SparseArray::GetNextArrayIndex(
      &this->SA,
      &resulta,
      (Scaleform::GFx::AS3::AbsoluteIndex)(ind.Index - 1i64));
    if ( resulta.Index >= 0 )
    {
      v5 = v3;
      v3->Index = LODWORD(resulta.Index) + 1;
      return v5;
    }
    ind.Index = v10;
  }
  v6 = v4->SA.Length;
  if ( ind.Index >= v6 )
    ind.Index -= v6;
  v7 = Scaleform::GFx::AS3::Object::GetNextDynPropIndex(
         (Scaleform::GFx::AS3::Object *)&v4->vfptr,
         (Scaleform::GFx::AS3::GlobalSlotIndex *)&resulta,
         ind);
  v8 = v7->Index;
  v3->Index = v7->Index;
  if ( v8 )
    v3->Index = v8 + v6;
  return v3;
}

// File Line: 1957
// RVA: 0x7ED0A0
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::GetNextPropertyValue(Scaleform::GFx::AS3::Instances::fl::Array *this, Scaleform::GFx::AS3::Value *value, Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::Instances::fl::Array *v4; // r9
  Scaleform::GFx::AS3::Impl::SparseArray *v5; // rcx
  Scaleform::GFx::AS3::Value *v6; // rax
  unsigned int v7; // er8

  v3 = value;
  v4 = this;
  if ( ind.Index )
  {
    v5 = &this->SA;
    if ( ind.Index > v5->Length )
    {
      v7 = ind.Index - LODWORD(v5->Length);
      if ( v7 )
        ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::Array *, signed __int64, Scaleform::GFx::AS3::Value *))v4->vfptr[1].Finalize_GC)(
          v4,
          v7 - 1i64,
          value);
    }
    else
    {
      v6 = Scaleform::GFx::AS3::Impl::SparseArray::At(v5, ind.Index - 1);
      Scaleform::GFx::AS3::Value::Assign(v3, v6);
    }
  }
  else
  {
    Scaleform::GFx::AS3::Value::SetUndefined(value);
  }
}

// File Line: 1968
// RVA: 0x81AD90
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl::Array::SetProperty(Scaleform::GFx::AS3::Instances::fl::Array *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::Multiname *prop_name, Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::Multiname *v4; // rbp
  Scaleform::GFx::AS3::Instances::fl::Array *v5; // rsi
  Scaleform::GFx::AS3::CheckResult *v6; // rbx
  Scaleform::GFx::AS3::Value *v7; // rdi
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+20h] [rbp-18h]
  unsigned int ind; // [rsp+24h] [rbp-14h]

  v4 = prop_name;
  v5 = this;
  v6 = result;
  v7 = value;
  if ( Scaleform::GFx::AS3::GetArrayInd(&resulta, prop_name, &ind)->Result )
  {
    Scaleform::GFx::AS3::Impl::SparseArray::Set(&v5->SA, ind, v7);
    v6->Result = 1;
  }
  else
  {
    Scaleform::GFx::AS3::Object::SetProperty((Scaleform::GFx::AS3::Object *)&v5->vfptr, v6, v4, v7);
  }
  return v6;
}

// File Line: 1981
// RVA: 0x7EDBE0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl::Array::GetProperty(Scaleform::GFx::AS3::Instances::fl::Array *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::Multiname *prop_name, Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::Multiname *v4; // rbp
  Scaleform::GFx::AS3::Instances::fl::Array *v5; // rsi
  Scaleform::GFx::AS3::CheckResult *v6; // rbx
  Scaleform::GFx::AS3::Value *v7; // rdi
  Scaleform::GFx::AS3::Value *v8; // rax
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+20h] [rbp-18h]
  unsigned int ind; // [rsp+24h] [rbp-14h]

  v4 = prop_name;
  v5 = this;
  v6 = result;
  v7 = value;
  if ( Scaleform::GFx::AS3::GetArrayInd(&resulta, prop_name, &ind)->Result )
  {
    v8 = Scaleform::GFx::AS3::Impl::SparseArray::At(&v5->SA, ind);
    Scaleform::GFx::AS3::Value::Assign(v7, v8);
    v6->Result = 1;
  }
  else
  {
    Scaleform::GFx::AS3::Object::GetProperty((Scaleform::GFx::AS3::Object *)&v5->vfptr, v6, v4, v7);
  }
  return v6;
}

// File Line: 1994
// RVA: 0x7E9340
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::GetDynamicProperty(Scaleform::GFx::AS3::Instances::fl::Array *this, Scaleform::GFx::AS3::AbsoluteIndex ind, Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::Value *v4; // rax

  v3 = value;
  v4 = Scaleform::GFx::AS3::Impl::SparseArray::At(&this->SA, LODWORD(ind.Index));
  Scaleform::GFx::AS3::Value::Assign(v3, v4);
}

// File Line: 1999
// RVA: 0x7C0D80
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl::Array::DeleteProperty(Scaleform::GFx::AS3::Instances::fl::Array *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::Multiname *prop_name)
{
  Scaleform::GFx::AS3::Multiname *v3; // rsi
  Scaleform::GFx::AS3::Instances::fl::Array *v4; // rdi
  Scaleform::GFx::AS3::CheckResult *v5; // rbx
  Scaleform::GFx::AS3::CheckResult *v6; // rax
  unsigned int ind; // [rsp+20h] [rbp-18h]
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+58h] [rbp+20h]

  v3 = prop_name;
  v4 = this;
  v5 = result;
  if ( Scaleform::GFx::AS3::GetArrayInd(&resulta, prop_name, &ind)->Result )
  {
    if ( ind < v4->SA.Length )
    {
      Scaleform::GFx::AS3::Impl::SparseArray::RemoveMultipleAt(&v4->SA, ind, 1ui64, opRemove);
      v5->Result = 1;
    }
    else
    {
      v5->Result = 0;
    }
    v6 = v5;
  }
  else
  {
    Scaleform::GFx::AS3::Object::DeleteProperty((Scaleform::GFx::AS3::Object *)&v4->vfptr, v5, v3);
    v6 = v5;
  }
  return v6;
}

// File Line: 2016
// RVA: 0x7F2830
bool __fastcall Scaleform::GFx::AS3::Instances::fl::Array::HasProperty(Scaleform::GFx::AS3::Instances::fl::Array *this, Scaleform::GFx::AS3::Multiname *prop_name, bool check_prototype)
{
  Scaleform::GFx::AS3::Instances::fl::Array *v3; // rdi
  bool v4; // bp
  unsigned int v5; // ecx
  Scaleform::GFx::AS3::Multiname *v6; // rsi
  unsigned __int64 v7; // rax
  bool v8; // al
  long double v9; // rdx
  Scaleform::GFx::AS3::CheckResult result; // [rsp+48h] [rbp+10h]
  unsigned int ind; // [rsp+58h] [rbp+20h]

  v3 = this;
  v4 = check_prototype;
  v5 = prop_name->Name.Flags & 0x1F;
  v6 = prop_name;
  if ( v5 - 2 > 1 )
  {
    if ( v5 == 10
      && (v9 = prop_name->Name.value.VNumber,
          ind = 0,
          Scaleform::GFx::AS3::GetArrayInd(&result, *(Scaleform::GFx::ASStringNode **)&v9, &ind)->Result) )
    {
      v8 = ind < v3->SA.Length;
    }
    else
    {
      v8 = Scaleform::GFx::AS3::Object::HasProperty((Scaleform::GFx::AS3::Object *)&v3->vfptr, v6, v4);
    }
  }
  else
  {
    v7 = prop_name->Name.value.VS._1.VInt;
    v8 = (v7 & 0x80000000) == 0i64 && v7 < v3->SA.Length;
  }
  return v8;
}

// File Line: 2079
// RVA: 0x1596F20
const char *dynamic_initializer_for__Scaleform::GFx::AS3::InstanceTraits::fl::Array::ti__()
{
  const char *result; // rax

  result = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::Array::ti[2].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::Array::ti[3].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::Array::ti[4].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::Array::ti[5].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::Array::ti[6].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::Array::ti[7].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::Array::ti[8].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::Array::ti[9].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::Array::ti[10].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::Array::ti[11].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::Array::ti[12].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::Array::ti[13].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::Array::ti[14].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::Array::ti[15].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::Array::ti[16].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::Array::ti[17].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::Array::ti[18].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::Array::ti[19].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  return result;
}

// File Line: 2110
// RVA: 0x7FF160
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Array::MakeObject(Scaleform::GFx::AS3::InstanceTraits::fl::Array *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::Object **v4; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> resulta; // [rsp+48h] [rbp+20h]

  v3 = result;
  v4 = (Scaleform::GFx::AS3::Object **)Scaleform::GFx::AS3::InstanceTraits::fl::Array::MakeInstance(
                                         &resulta,
                                         (Scaleform::GFx::AS3::InstanceTraits::fl::Array *)t);
  Scaleform::GFx::AS3::Value::Pick(v3, *v4);
}

// File Line: 2134
// RVA: 0x7B2DB0
void __fastcall Scaleform::GFx::AS3::Classes::fl::RegExp::Call(Scaleform::GFx::AS3::Classes::fl::uint *this, Scaleform::GFx::AS3::Value *__formal, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *const argv)
{
  ((void (__fastcall *)(Scaleform::GFx::AS3::Classes::fl::uint *, Scaleform::GFx::AS3::Value *, _QWORD, Scaleform::GFx::AS3::Value *const ))this->vfptr[4].ForEachChild_GC)(
    this,
    result,
    argc,
    argv);
}

// File Line: 2140
// RVA: 0x8004B0
Scaleform::Pickable<Scaleform::GFx::AS3::Object> *__fastcall Scaleform::GFx::AS3::Classes::fl::Array::MakePrototype(Scaleform::GFx::AS3::Classes::fl::Array *this, Scaleform::Pickable<Scaleform::GFx::AS3::Object> *result)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Object> *v2; // rbx
  Scaleform::GFx::AS3::Instances::fl::Array *v3; // rcx
  Scaleform::Pickable<Scaleform::GFx::AS3::Object> *v4; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> resulta; // [rsp+30h] [rbp+8h]

  v2 = result;
  v3 = Scaleform::GFx::AS3::InstanceTraits::fl::Array::MakeInstance(
         &resulta,
         (Scaleform::GFx::AS3::InstanceTraits::fl::Array *)this->pTraits.pObject[1].vfptr)->pV;
  v4 = v2;
  v2->pV = (Scaleform::GFx::AS3::Object *)&v3->vfptr;
  return v4;
}

// File Line: 2146
// RVA: 0x7F3CC0
void __fastcall Scaleform::GFx::AS3::Classes::fl::Array::InitPrototype(Scaleform::GFx::AS3::Classes::fl::Array *this, Scaleform::GFx::AS3::Object *obj)
{
  Scaleform::GFx::AS3::Object *v2; // r15
  Scaleform::GFx::AS3::Classes::fl::Array *v3; // r14
  Scaleform::GFx::AS3::Class *v4; // rcx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v5; // rbx
  Scaleform::GFx::AS3::Classes::Function *v6; // r13
  const char **v7; // rbx
  Scaleform::GFx::AS3::ThunkInfo *v8; // rdi
  signed __int64 v9; // rsi
  Scaleform::GFx::ASStringNode *v10; // rcx
  Scaleform::GFx::ASString *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  bool v13; // zf
  Scaleform::GFx::ASStringNode *v14; // rcx
  int v15; // eax
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v17; // rcx
  unsigned int v18; // eax
  Scaleform::GFx::ASStringNode *v19[2]; // [rsp+30h] [rbp-40h]
  Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef key; // [rsp+40h] [rbp-30h]
  unsigned int v21; // [rsp+50h] [rbp-20h]
  _DWORD *v22; // [rsp+58h] [rbp-18h]
  Scaleform::GFx::ASStringNode *v23; // [rsp+60h] [rbp-10h]
  unsigned int *v24; // [rsp+68h] [rbp-8h]
  Scaleform::GFx::ASString v25; // [rsp+B0h] [rbp+40h]
  Scaleform::GFx::AS3::Object *obja; // [rsp+B8h] [rbp+48h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::CheckTypeTF> result; // [rsp+C0h] [rbp+50h]

  obja = obj;
  v2 = obj;
  v3 = this;
  v4 = this->ParentClass.pObject;
  if ( v4 )
    ((void (__cdecl *)(Scaleform::GFx::AS3::Class *))v4->vfptr[7].Finalize_GC)(v4);
  v19[0] = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::AS3::Class::ConvertCheckType;
  LODWORD(v19[1]) = 0;
  _mm_store_si128((__m128i *)&key, *(__m128i *)v19);
  Scaleform::GFx::AS3::Class::InitPrototypeFromVTable(
    (Scaleform::GFx::AS3::Class *)&v3->vfptr,
    v2,
    (Scaleform::GFx::AS3::Value *(__fastcall *)(Scaleform::GFx::AS3::Class *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))&key);
  v5 = v3->pTraits.pObject->pVM->TraitsFunction.pObject->ITraits.pObject;
  if ( !v5->pConstructor.pObject )
    v5->vfptr[3].~RefCountBaseGC<328>((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v5->vfptr);
  v6 = (Scaleform::GFx::AS3::Classes::Function *)v5->pConstructor.pObject;
  key.pFirst = (Scaleform::GFx::AS3::Object::DynAttrsKey *)v19;
  key.pSecond = (Scaleform::GFx::AS3::Value *)&v21;
  v7 = &Scaleform::GFx::AS3::Classes::fl::Array::ti[0].Name;
  v8 = Scaleform::GFx::AS3::Classes::fl::Array::ti;
  v9 = 2i64;
  do
  {
    v10 = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::AS3::Classes::Function::MakeCheckTypeInstance(
                                            v6,
                                            &result,
                                            (Scaleform::GFx::AS3::Class *)&v3->vfptr,
                                            v8)->pV;
    v22 = 0i64;
    v21 = 15;
    v23 = v10;
    v24 = &v21;
    v11 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
            (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v3->pTraits.pObject->pVM->StringManagerRef->Builtins,
            &v25,
            *v7);
    LODWORD(v19[0]) = 1;
    v19[1] = v11->pNode;
    ++v19[1]->RefCount;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
      (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *)&v2->DynAttrs.mHash.pTable,
      &v2->DynAttrs,
      &key);
    v12 = v19[1];
    v13 = v19[1]->RefCount == 1;
    --v12->RefCount;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
    v14 = v25.pNode;
    v13 = v25.pNode->RefCount == 1;
    --v14->RefCount;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
    v15 = v21 & 0x1F;
    if ( v15 > 9 )
    {
      if ( (v21 >> 9) & 1 )
      {
        v13 = (*v22)-- == 1;
        if ( v13 )
          ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        v22 = 0i64;
        v23 = 0i64;
        v24 = 0i64;
        v21 &= 0xFFFFFDE0;
      }
      else
      {
        switch ( v15 )
        {
          case 10:
            v16 = v23;
            v13 = v23->RefCount == 1;
            --v16->RefCount;
            if ( v13 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v16);
            break;
          case 11:
          case 12:
          case 13:
          case 14:
          case 15:
            v17 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v23;
            if ( !((unsigned __int8)v23 & 1) )
              goto LABEL_22;
            v23 = (Scaleform::GFx::ASStringNode *)((char *)v23 - 1);
            break;
          case 16:
          case 17:
            v17 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v24;
            if ( (unsigned __int8)v24 & 1 )
            {
              v24 = (unsigned int *)((char *)v24 - 1);
            }
            else
            {
LABEL_22:
              if ( v17 )
              {
                v18 = v17->RefCount;
                if ( v18 & 0x3FFFFF )
                {
                  v17->RefCount = v18 - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v17);
                }
              }
            }
            break;
          default:
            break;
        }
      }
    }
    ++v8;
    v7 += 6;
    --v9;
  }
  while ( v9 );
  Scaleform::GFx::AS3::Class::AddConstructor((Scaleform::GFx::AS3::Class *)&v3->vfptr, obja);
}

// File Line: 2209
// RVA: 0x730CE0
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl::Array::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // rbp
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v3; // rdi
  Scaleform::MemoryHeap *v4; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rbx
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> v8; // rbx
  Scaleform::GFx::AS3::Class *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rbx

  v2 = vm;
  v3 = result;
  v4 = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->vfptr->Alloc(v4, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, v2, &Scaleform::GFx::AS3::fl::ArrayCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable';
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Array::`vftable';
    v6->TraitsType = 7;
  }
  else
  {
    v6 = 0i64;
  }
  v3->pV = v6;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)v4->vfptr->Alloc(v4, 240ui64, 0i64);
  v8.pV = (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v7->vfptr;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, v2, &Scaleform::GFx::AS3::fl::ArrayCI);
    v8.pV->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable';
    v8.pV->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Array::`vftable';
    v8.pV->Flags |= 1ui64;
    v8.pV->TraitsType = 7;
  }
  else
  {
    v8.pV = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(v3->pV, v8);
  v9 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v4->vfptr->Alloc)(
                                       v4,
                                       96i64);
  v10 = v9;
  if ( v9 )
  {
    Scaleform::GFx::AS3::Class::Class(v9, v3->pV);
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl::Array::`vftable';
    LODWORD(v10[1].vfptr) = 1;
    HIDWORD(v10[1].vfptr) = 2;
    LODWORD(v10[1]._pRCC) = 4;
    HIDWORD(v10[1].pRCCRaw) = 8;
    LODWORD(v10[1].pNext) = 16;
  }
  return v3;
}

