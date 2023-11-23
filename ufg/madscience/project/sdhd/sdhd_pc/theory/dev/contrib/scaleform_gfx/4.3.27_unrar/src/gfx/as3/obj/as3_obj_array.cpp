// File Line: 37
// RVA: 0x7B78D0
int __fastcall Scaleform::GFx::AS3::Impl::CompareAsString::Compare(
        Scaleform::GFx::AS3::Impl::CompareAsString *this,
        Scaleform::GFx::ASString *a,
        Scaleform::GFx::ASString *b)
{
  const char *pData; // rbx
  bool v7; // di
  unsigned int Length; // eax
  bool v9; // r9
  const char *v10; // rdx
  Scaleform::GFx::ASString *v11; // rcx
  int result; // eax
  const char *v13; // rbx
  bool v14; // di
  const char *v15; // rax
  const char *v16; // rdx
  unsigned __int8 v17; // cl

  if ( this->UseLocale )
  {
    if ( this->Desc )
    {
      pData = a->pNode->pData;
      v7 = !this->CaseInsensitive;
      Length = Scaleform::GFx::ASConstString::GetLength(a);
      v9 = v7;
      v10 = pData;
      v11 = b;
    }
    else
    {
      v13 = b->pNode->pData;
      v14 = !this->CaseInsensitive;
      Length = Scaleform::GFx::ASConstString::GetLength(b);
      v9 = v14;
      v10 = v13;
      v11 = a;
    }
    return Scaleform::GFx::ASConstString::LocaleCompare_CaseCheck(v11, v10, Length, v9);
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
      result = v17 < (unsigned int)v16[(_QWORD)v15] ? -1 : 1;
    }
LABEL_14:
    if ( this->Desc )
      return -result;
  }
  return result;
}

// File Line: 59
// RVA: 0x7B84D0
__int64 __fastcall Scaleform::GFx::AS3::Impl::CompareValuePtr::Compare(
        Scaleform::GFx::AS3::Impl::CompareValuePtr *this,
        Scaleform::GFx::AS3::Value *a,
        Scaleform::GFx::AS3::Value *b)
{
  unsigned int Flags; // r9d
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // r10
  Scaleform::GFx::AS3::Value::V1U VObj; // rcx
  unsigned int v7; // ecx
  Scaleform::GFx::AS3::WeakProxy *v8; // rdx
  Scaleform::GFx::AS3::Value::V1U v9; // rcx
  int v10; // eax
  unsigned int v11; // ebx
  Scaleform::GFx::AS3::Value result; // [rsp+40h] [rbp-11h] BYREF
  Scaleform::GFx::AS3::Value ptr; // [rsp+68h] [rbp+17h] BYREF
  unsigned int v16; // [rsp+88h] [rbp+37h]
  Scaleform::GFx::AS3::WeakProxy *v17; // [rsp+90h] [rbp+3Fh]
  Scaleform::GFx::AS3::Value::VU value; // [rsp+98h] [rbp+47h]
  long double retaddr; // [rsp+B8h] [rbp+67h] BYREF
  long double v; // [rsp+C0h] [rbp+6Fh] BYREF

  result.Flags = 0;
  result.Bonus.pWeakProxy = 0i64;
  Flags = a->Flags;
  ptr.Flags = Flags;
  pWeakProxy = a->Bonus.pWeakProxy;
  ptr.Bonus.pWeakProxy = pWeakProxy;
  ptr.value = a->value;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
    {
      ++pWeakProxy->RefCount;
      goto LABEL_13;
    }
    if ( (Flags & 0x1F) == 10 )
    {
      ++a->value.VS._1.VStr->RefCount;
    }
    else
    {
      if ( (Flags & 0x1F) <= 0xA )
        goto LABEL_13;
      if ( (Flags & 0x1F) <= 0xF )
      {
        VObj = a->value.VS._1;
      }
      else
      {
        if ( (Flags & 0x1F) > 0x11 )
          goto LABEL_13;
        VObj = (Scaleform::GFx::AS3::Value::V1U)a->value.VS._2.VObj;
      }
      if ( VObj.VStr )
        VObj.VStr->Size = (VObj.VStr->Size + 1) & 0x8FBFFFFF;
    }
  }
LABEL_13:
  v7 = b->Flags;
  v16 = v7;
  v8 = b->Bonus.pWeakProxy;
  v17 = v8;
  value = b->value;
  if ( (v7 & 0x1F) <= 9 )
    goto LABEL_25;
  if ( (v7 & 0x200) != 0 )
  {
    ++v8->RefCount;
    goto LABEL_25;
  }
  if ( (v7 & 0x1F) == 10 )
  {
    ++b->value.VS._1.VStr->RefCount;
  }
  else
  {
    if ( (v7 & 0x1F) <= 0xA )
      goto LABEL_25;
    if ( (v7 & 0x1F) <= 0xF )
    {
      v9 = b->value.VS._1;
    }
    else
    {
      if ( (v7 & 0x1F) > 0x11 )
        goto LABEL_25;
      v9 = (Scaleform::GFx::AS3::Value::V1U)b->value.VS._2.VObj;
    }
    if ( v9.VStr )
      v9.VStr->Size = (v9.VStr->Size + 1) & 0x8FBFFFFF;
  }
LABEL_25:
  if ( (_S11_12 & 1) == 0 )
  {
    _S11_12 |= 1u;
    ::v.Flags = 0;
    ::v.Bonus.pWeakProxy = 0i64;
    atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(this->Vm, this->Func, &::v, &result, 2u, &ptr, 0);
  if ( this->Vm->HandleException
    || !Scaleform::GFx::AS3::Value::Convert2Number(&result, (Scaleform::GFx::AS3::CheckResult *)&retaddr, &v)->Result )
  {
    v10 = 0;
    goto LABEL_43;
  }
  retaddr = v;
  if ( v == -INFINITY )
  {
    v10 = -1;
LABEL_43:
    v11 = v10;
    goto LABEL_44;
  }
  retaddr = v;
  if ( v == INFINITY )
  {
    v10 = 1;
    goto LABEL_43;
  }
  if ( Scaleform::GFx::NumberUtil::IsNEGATIVE_ZERO(v) )
  {
    v10 = -1;
    goto LABEL_43;
  }
  if ( Scaleform::GFx::NumberUtil::IsPOSITIVE_ZERO(v) )
  {
    v10 = 1;
    goto LABEL_43;
  }
  if ( v == 0.0 )
  {
    v11 = 0;
  }
  else
  {
    v11 = 1;
    if ( v < 0.0 )
      v11 = -1;
  }
LABEL_44:
  `eh vector destructor iterator(&ptr, 0x20ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
  if ( (result.Flags & 0x1F) > 9 )
  {
    if ( (result.Flags & 0x200) != 0 )
    {
      if ( result.Bonus.pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&result.Bonus, 0, 24);
      result.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
    }
  }
  return v11;
}

// File Line: 95
// RVA: 0x7B79C0
double __fastcall Scaleform::GFx::AS3::Impl::CompareOn::Compare(
        Scaleform::GFx::AS3::Impl::CompareOn *this,
        Scaleform::GFx::AS3::Value *a,
        Scaleform::GFx::AS3::Value *b)
{
  int v6; // edi
  double v7; // xmm6_8
  unsigned __int64 Size; // r13
  unsigned __int64 i; // r12
  Scaleform::GFx::AS3::Value *v10; // rdx
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // rcx
  Scaleform::GFx::ASString *VStr; // rbx
  Scaleform::GFx::ASStringNode *v13; // rax
  Scaleform::GFx::AS3::GASRefCountBase *pNode; // rbx
  Scaleform::GFx::AS3::GASRefCountBase *v15; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASString *v17; // rax
  Scaleform::GFx::ASStringNode *v18; // rcx
  bool v19; // zf
  Scaleform::GFx::ASStringNode *v20; // rcx
  int v21; // edi
  bool v22; // al
  unsigned int v23; // ebx
  bool v24; // r14
  bool v25; // al
  bool v26; // al
  bool v27; // si
  const char *pData; // rbx
  unsigned int Length; // eax
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
  Scaleform::GFx::AS3::Value value; // [rsp+38h] [rbp-88h] BYREF
  Scaleform::GFx::AS3::PropRef v43; // [rsp+58h] [rbp-68h] BYREF
  Scaleform::GFx::AS3::PropRef v44; // [rsp+88h] [rbp-38h] BYREF
  Scaleform::GFx::AS3::Multiname mn; // [rsp+B8h] [rbp-8h] BYREF
  Scaleform::GFx::ASString result; // [rsp+E8h] [rbp+28h] BYREF
  long double v47; // [rsp+F0h] [rbp+30h] BYREF
  long double v48; // [rsp+F8h] [rbp+38h] BYREF
  Scaleform::GFx::ASString v49; // [rsp+100h] [rbp+40h] BYREF
  __int64 v50; // [rsp+108h] [rbp+48h]
  Scaleform::GFx::AS3::CheckResult v51; // [rsp+190h] [rbp+D0h] BYREF
  Scaleform::GFx::AS3::Value *v52; // [rsp+198h] [rbp+D8h]
  Scaleform::GFx::AS3::Value *v53; // [rsp+1A0h] [rbp+E0h]
  Scaleform::GFx::AS3::CheckResult v54; // [rsp+1A8h] [rbp+E8h] BYREF

  v50 = -2i64;
  v6 = 0;
  v7 = 0.0;
  Size = this->Fields->Data.Size;
  for ( i = 0i64; i < Size; ++i )
  {
    if ( v7 != 0.0 )
      return v7;
    v10 = &this->Fields->Data.Data[i];
    pObject = this->Vm->PublicNamespace.pObject;
    mn.Kind = MN_QName;
    mn.Obj.pObject = pObject;
    if ( pObject )
      pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
    mn.Name.Flags = 0;
    mn.Name.Bonus.pWeakProxy = 0i64;
    if ( (v10->Flags & 0x1F) - 12 <= 3
      && (VStr = (Scaleform::GFx::ASString *)v10->value.VS._1.VStr) != 0i64
      && (v13 = VStr[5].pNode, LODWORD(v13[3].pData) == 17)
      && (v13[2].Size & 0x20) == 0 )
    {
      Scaleform::GFx::AS3::Value::Assign(&mn.Name, VStr + 7);
      pNode = (Scaleform::GFx::AS3::GASRefCountBase *)VStr[8].pNode;
      v15 = mn.Obj.pObject;
      if ( pNode != mn.Obj.pObject )
      {
        if ( pNode )
        {
          pNode->RefCount = (pNode->RefCount + 1) & 0x8FBFFFFF;
          v15 = mn.Obj.pObject;
        }
        if ( v15 )
        {
          if ( ((__int64)mn.Obj.pObject & 1) != 0 )
          {
            mn.Obj.pObject = (Scaleform::GFx::AS3::GASRefCountBase *)((char *)v15 - 1);
          }
          else
          {
            RefCount = v15->RefCount;
            if ( (RefCount & 0x3FFFFF) != 0 )
            {
              v15->RefCount = RefCount - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v15);
            }
          }
        }
        mn.Obj.pObject = pNode;
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
            v19 = v49.pNode->RefCount-- == 1;
            if ( v19 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v18);
          }
        }
        v20 = result.pNode;
        v19 = result.pNode->RefCount-- == 1;
        if ( v19 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v20);
      }
    }
    memset(&v43, 0, 20);
    v43.This.Bonus.pWeakProxy = 0i64;
    memset(&v44, 0, 20);
    v44.This.Bonus.pWeakProxy = 0i64;
    Scaleform::GFx::AS3::FindObjProperty(&v43, this->Vm, a, &mn, FindGet);
    Scaleform::GFx::AS3::FindObjProperty(&v44, this->Vm, b, &mn, FindGet);
    if ( (v43.This.Flags & 0x1F) != 0
      && (((__int64)v43.pSI & 1) == 0 || ((unsigned __int64)v43.pSI & 0xFFFFFFFFFFFFFFFEui64) != 0)
      && (((__int64)v43.pSI & 2) == 0 || ((unsigned __int64)v43.pSI & 0xFFFFFFFFFFFFFFFDui64) != 0)
      && (v44.This.Flags & 0x1F) != 0
      && (((__int64)v44.pSI & 1) == 0 || ((unsigned __int64)v44.pSI & 0xFFFFFFFFFFFFFFFEui64) != 0)
      && (((__int64)v44.pSI & 2) == 0 || ((unsigned __int64)v44.pSI & 0xFFFFFFFFFFFFFFFDui64) != 0) )
    {
      value.Flags = 0;
      value.Bonus.pWeakProxy = 0i64;
      LODWORD(v43.pSI) = 0;
      v43.SlotIndex = 0i64;
      v21 = v6 | 1;
      v22 = 1;
      if ( Scaleform::GFx::AS3::PropRef::GetSlotValueUnsafe(&v43, &v51, this->Vm, &value, valGet)->Result )
      {
        v21 |= 2u;
        if ( Scaleform::GFx::AS3::PropRef::GetSlotValueUnsafe(
               &v44,
               &v54,
               this->Vm,
               (Scaleform::GFx::AS3::Value *)&v43,
               valGet)->Result )
          v22 = 0;
      }
      if ( (v21 & 2) != 0 )
        v21 &= ~2u;
      if ( (v21 & 1) != 0 )
        v21 &= ~1u;
      if ( v22 )
      {
        if ( (unsigned __int64)((__int64)v43.pSI & 0x1F) > 9 )
        {
          if ( ((__int64)v43.pSI & 0x200) != 0 )
          {
            v19 = (*(_DWORD *)v43.SlotIndex)-- == 1;
            if ( v19 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            memset(&v43.SlotIndex, 0, 24);
            LODWORD(v43.pSI) &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v43);
          }
        }
        if ( (value.Flags & 0x1F) > 9 )
        {
          if ( (value.Flags & 0x200) != 0 )
          {
            v19 = value.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v19 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            memset(&value.Bonus, 0, 24);
            value.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
          }
        }
        if ( (v44.This.Flags & 0x1F) > 9 )
        {
          if ( (v44.This.Flags & 0x200) != 0 )
          {
            v19 = v44.This.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v19 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            memset(&v44.This.Bonus, 0, 24);
            v44.This.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v44.This);
          }
        }
        if ( (v43.This.Flags & 0x1F) <= 9 )
          goto LABEL_191;
        if ( (v43.This.Flags & 0x200) != 0 )
        {
          v19 = v43.This.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v19 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
LABEL_189:
          memset(&v43.This.Bonus, 0, 24);
          v43.This.Flags &= 0xFFFFFDE0;
LABEL_191:
          Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
          return v7;
        }
LABEL_190:
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v43.This);
        goto LABEL_191;
      }
      v23 = this->Flags->Data.Data[i];
      v24 = (v23 & 2) != 0;
      if ( (v23 & 0x10) != 0 )
      {
        v47 = 0.0;
        v48 = 0.0;
        v6 = v21 | 4;
        v25 = 1;
        if ( Scaleform::GFx::AS3::Value::Convert2Number(&value, (Scaleform::GFx::AS3::CheckResult *)&value.Bonus, &v47)->Result )
        {
          v6 |= 8u;
          if ( Scaleform::GFx::AS3::Value::Convert2Number(
                 (Scaleform::GFx::AS3::Value *)&v43,
                 (Scaleform::GFx::AS3::CheckResult *)&value.Bonus.pWeakProxy + 1,
                 &v48)->Result )
            v25 = 0;
        }
        if ( (v6 & 8) != 0 )
          v6 &= ~8u;
        if ( (v6 & 4) != 0 )
          v6 &= ~4u;
        if ( v25 )
        {
          if ( (unsigned __int64)((__int64)v43.pSI & 0x1F) > 9 )
          {
            if ( ((__int64)v43.pSI & 0x200) != 0 )
            {
              v19 = (*(_DWORD *)v43.SlotIndex)-- == 1;
              if ( v19 )
                ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
              memset(&v43.SlotIndex, 0, 24);
              LODWORD(v43.pSI) &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v43);
            }
          }
          if ( (value.Flags & 0x1F) > 9 )
          {
            if ( (value.Flags & 0x200) != 0 )
            {
              v19 = value.Bonus.pWeakProxy->RefCount-- == 1;
              if ( v19 )
                ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
              memset(&value.Bonus, 0, 24);
              value.Flags &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
            }
          }
          if ( (v44.This.Flags & 0x1F) > 9 )
          {
            if ( (v44.This.Flags & 0x200) != 0 )
            {
              v19 = v44.This.Bonus.pWeakProxy->RefCount-- == 1;
              if ( v19 )
                ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
              memset(&v44.This.Bonus, 0, 24);
              v44.This.Flags &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&v44.This);
            }
          }
          if ( (v43.This.Flags & 0x1F) <= 9 )
            goto LABEL_191;
          if ( (v43.This.Flags & 0x200) == 0 )
            goto LABEL_190;
          v19 = v43.This.Bonus.pWeakProxy->RefCount-- == 1;
          if ( !v19 )
            goto LABEL_189;
          goto LABEL_140;
        }
        v7 = v47 - v48;
      }
      else
      {
        Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
          this->Vm->StringManagerRef,
          (Scaleform::GFx::ASString *)&v43.This.value);
        value.value.VS._1.VStr = v43.This.value.VS._1.VStr;
        ++v43.This.value.VS._1.VStr->RefCount;
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
        if ( (v6 & 0x20) != 0 )
          v6 &= ~0x20u;
        if ( (v6 & 0x10) != 0 )
          v6 &= ~0x10u;
        if ( v26 )
        {
          v39 = value.value.VS._1.VStr;
          v19 = value.value.VS._1.VStr->RefCount-- == 1;
          if ( v19 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v39);
          v40 = v43.This.value.VS._1.VStr;
          v19 = v43.This.value.VS._1.VStr->RefCount-- == 1;
          if ( v19 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v40);
          if ( (unsigned __int64)((__int64)v43.pSI & 0x1F) > 9 )
          {
            if ( ((__int64)v43.pSI & 0x200) != 0 )
            {
              v19 = (*(_DWORD *)v43.SlotIndex)-- == 1;
              if ( v19 )
                ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
              memset(&v43.SlotIndex, 0, 24);
              LODWORD(v43.pSI) &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v43);
            }
          }
          if ( (value.Flags & 0x1F) > 9 )
          {
            if ( (value.Flags & 0x200) != 0 )
            {
              v19 = value.Bonus.pWeakProxy->RefCount-- == 1;
              if ( v19 )
                ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
              memset(&value.Bonus, 0, 24);
              value.Flags &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
            }
          }
          if ( (v44.This.Flags & 0x1F) > 9 )
          {
            if ( (v44.This.Flags & 0x200) != 0 )
            {
              v19 = v44.This.Bonus.pWeakProxy->RefCount-- == 1;
              if ( v19 )
                ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
              memset(&v44.This.Bonus, 0, 24);
              v44.This.Flags &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&v44.This);
            }
          }
          if ( (v43.This.Flags & 0x1F) <= 9 )
            goto LABEL_191;
          if ( (v43.This.Flags & 0x200) == 0 )
            goto LABEL_190;
          v19 = v43.This.Bonus.pWeakProxy->RefCount-- == 1;
          if ( !v19 )
            goto LABEL_189;
LABEL_140:
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&v43.This.Bonus, 0, 24);
          v43.This.Flags &= 0xFFFFFDE0;
          goto LABEL_191;
        }
        v27 = (v23 & 1) == 0;
        if ( (v23 & 0x400) != 0 )
        {
          pData = value.value.VS._1.VStr->pData;
          Length = Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&value.value);
          v30 = Scaleform::GFx::ASConstString::LocaleCompare_CaseCheck(
                  (Scaleform::GFx::ASConstString *)&v43.This.value,
                  pData,
                  Length,
                  v27);
        }
        else
        {
          v31 = value.value.VS._1.VStr->pData;
          v32 = v43.This.value.VS._1.VStr->pData;
          if ( (v23 & 1) != 0 )
          {
            v30 = Scaleform::String::CompareNoCase(v32, v31);
          }
          else
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
            v30 = v34 < (unsigned int)v32[v33] ? -1 : 1;
          }
        }
LABEL_74:
        v7 = (double)v30;
        v35 = value.value.VS._1.VStr;
        v19 = value.value.VS._1.VStr->RefCount-- == 1;
        if ( v19 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v35);
        v36 = v43.This.value.VS._1.VStr;
        v19 = v43.This.value.VS._1.VStr->RefCount-- == 1;
        if ( v19 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v36);
        b = v53;
      }
      if ( v24 )
        *(_QWORD *)&v7 ^= _xmm[0];
      if ( (unsigned __int64)((__int64)v43.pSI & 0x1F) > 9 )
      {
        if ( ((__int64)v43.pSI & 0x200) != 0 )
        {
          v19 = (*(_DWORD *)v43.SlotIndex)-- == 1;
          if ( v19 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&v43.SlotIndex, 0, 24);
          LODWORD(v43.pSI) &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v43);
        }
      }
      if ( (value.Flags & 0x1F) > 9 )
      {
        if ( (value.Flags & 0x200) != 0 )
        {
          v19 = value.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v19 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&value.Bonus, 0, 24);
          value.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
        }
      }
      a = v52;
    }
    if ( (v44.This.Flags & 0x1F) > 9 )
    {
      if ( (v44.This.Flags & 0x200) != 0 )
      {
        v19 = v44.This.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v19 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&v44.This.Bonus, 0, 24);
        v44.This.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v44.This);
      }
    }
    if ( (v43.This.Flags & 0x1F) > 9 )
    {
      if ( (v43.This.Flags & 0x200) != 0 )
      {
        v19 = v43.This.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v19 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&v43.This.Bonus, 0, 24);
        v43.This.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v43.This);
      }
    }
    if ( (mn.Name.Flags & 0x1F) > 9 )
    {
      if ( (mn.Name.Flags & 0x200) != 0 )
      {
        v19 = mn.Name.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v19 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&mn.Name.Bonus, 0, 24);
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
      if ( ((__int64)mn.Obj.pObject & 1) != 0 )
      {
        --mn.Obj.pObject;
      }
      else
      {
        v38 = mn.Obj.pObject->RefCount;
        if ( (v38 & 0x3FFFFF) != 0 )
        {
          mn.Obj.pObject->RefCount = v38 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v37);
        }
      }
    }
  }
  return v7;
}

// File Line: 181
// RVA: 0x801860
void __fastcall Scaleform::GFx::AS3::Impl::SparseArray::MoveHashRight(
        Scaleform::GFx::AS3::Impl::SparseArray *this,
        unsigned __int64 first_ind,
        unsigned __int64 offset)
{
  unsigned __int64 v5; // rbx
  Scaleform::HashDH<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>,2,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *p_ValueH; // rdi
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > v7; // r8
  __int64 v8; // rcx
  __int64 v9; // rdx
  __int64 v10; // rax
  __int64 v11; // rdx
  __int64 v12; // rcx
  unsigned __int64 *v13; // rax
  __int64 v14; // rdx
  bool v15; // zf
  Scaleform::GFx::ASStringNode *VStr; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *VObj; // rcx
  unsigned int RefCount; // eax
  Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef v19; // [rsp+28h] [rbp-38h] BYREF
  Scaleform::GFx::AS3::Value v20; // [rsp+38h] [rbp-28h] BYREF
  unsigned __int64 key; // [rsp+80h] [rbp+20h] BYREF

  v20.Flags = 0;
  v20.Bonus.pWeakProxy = 0i64;
  v5 = this->ValueHHighInd + 1;
  if ( v5 > first_ind )
  {
    p_ValueH = &this->ValueH;
    do
    {
      key = --v5;
      v7.pTable = p_ValueH->mHash.pTable;
      if ( p_ValueH->mHash.pTable )
      {
        v8 = 5381i64;
        v9 = 8i64;
        do
        {
          --v9;
          v10 = 65599 * v8 + *((unsigned __int8 *)&key + v9);
          v8 = v10;
        }
        while ( v9 );
        v11 = v10 & v7.pTable->SizeMask;
        v12 = v11;
        v13 = &v7.pTable[1].EntryCount + 7 * v11;
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
            v14 = (__int64)&v7.pTable[2] + 56 * v12;
            if ( v14 )
            {
              Scaleform::GFx::AS3::Value::Assign(&v20, (Scaleform::GFx::AS3::Value *)(v14 + 8));
              Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::RemoveAlt<unsigned __int64>(
                &p_ValueH->mHash,
                &key);
              key += offset;
              v19.pFirst = &key;
              v19.pSecond = &v20;
              Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
                &p_ValueH->mHash,
                p_ValueH->mHash.pHeap,
                &v19);
            }
          }
        }
      }
LABEL_15:
      ;
    }
    while ( v5 > first_ind );
  }
  if ( (v20.Flags & 0x1F) > 9 )
  {
    if ( (v20.Flags & 0x200) != 0 )
    {
      v15 = v20.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v15 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v20.Bonus, 0, 24);
      v20.Flags &= 0xFFFFFDE0;
    }
    else
    {
      switch ( v20.Flags & 0x1F )
      {
        case 0xA:
          VStr = v20.value.VS._1.VStr;
          v15 = v20.value.VS._1.VStr->RefCount-- == 1;
          if ( v15 )
            Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
          break;
        case 0xB:
        case 0xC:
        case 0xD:
        case 0xE:
        case 0xF:
          VObj = v20.value.VS._1.VObj;
          if ( !v20.value.VS._1.VBool )
            goto LABEL_28;
          --v20.value.VS._1.VStr;
          break;
        case 0x10:
        case 0x11:
          VObj = v20.value.VS._2.VObj;
          if ( ((__int64)v20.value.VS._2.VObj & 1) != 0 )
          {
            --v20.value.VS._2.VObj;
          }
          else
          {
LABEL_28:
            if ( VObj )
            {
              RefCount = VObj->RefCount;
              if ( (RefCount & 0x3FFFFF) != 0 )
              {
                VObj->RefCount = RefCount - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(VObj);
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
void __fastcall Scaleform::GFx::AS3::Impl::SparseArray::CutHash(
        Scaleform::GFx::AS3::Impl::SparseArray *this,
        unsigned __int64 pos,
        unsigned __int64 del_num,
        Scaleform::GFx::AS3::Impl::SparseArray *deleted)
{
  unsigned __int64 v5; // rbx
  unsigned __int64 ValueHLowInd; // r15
  unsigned __int64 ValueHHighInd; // r12
  unsigned __int64 v9; // rdi
  unsigned __int64 v10; // r12
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *pTable; // r9
  __int64 v12; // rcx
  __int64 v13; // rdx
  __int64 v14; // rax
  __int64 v15; // r8
  __int64 v16; // rdx
  unsigned __int64 *v17; // rcx
  char *v18; // rdx
  unsigned __int64 Size; // rcx
  Scaleform::GFx::AS3::Value *v20; // rdx
  bool v21; // zf
  Scaleform::GFx::AS3::Value::VU *v22; // rdx
  Scaleform::GFx::AS3::Value::V1U VObj; // rax
  unsigned __int64 v24; // r15
  unsigned __int64 v25; // r12
  Scaleform::GFx::ASStringNode *VStr; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v27; // rcx
  unsigned int RefCount; // eax
  unsigned __int64 key; // [rsp+20h] [rbp-60h] BYREF
  Scaleform::GFx::AS3::Value::VU *v30; // [rsp+28h] [rbp-58h] BYREF
  unsigned __int64 v31; // [rsp+30h] [rbp-50h]
  __int64 v32; // [rsp+38h] [rbp-48h]
  Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef v33; // [rsp+40h] [rbp-40h] BYREF
  Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef v34; // [rsp+50h] [rbp-30h] BYREF
  Scaleform::GFx::AS3::Value v35; // [rsp+60h] [rbp-20h] BYREF

  if ( del_num )
  {
    v32 = -2i64;
    v5 = del_num;
    v30 = (Scaleform::GFx::AS3::Value::VU *)(del_num + pos - 1);
    ValueHLowInd = this->ValueHLowInd;
    if ( ValueHLowInd < pos )
      ValueHLowInd = pos;
    ValueHHighInd = this->ValueHHighInd;
    if ( del_num + pos - 1 < ValueHHighInd )
      ValueHHighInd = del_num + pos - 1;
    v31 = ValueHHighInd;
    v35.Flags = 0;
    v35.Bonus.pWeakProxy = 0i64;
    v9 = ValueHLowInd;
    key = ValueHLowInd;
    if ( ValueHLowInd <= this->ValueHHighInd )
    {
      v10 = del_num + pos - 1;
      while ( 1 )
      {
        pTable = this->ValueH.mHash.pTable;
        if ( !pTable )
          goto LABEL_40;
        v12 = 5381i64;
        v13 = 8i64;
        do
        {
          --v13;
          v14 = 65599 * v12 + *((unsigned __int8 *)&key + v13);
          v12 = v14;
        }
        while ( v13 );
        v15 = v14 & pTable->SizeMask;
        v16 = v15;
        v17 = &pTable[1].EntryCount + 7 * v15;
        if ( *v17 == -2i64 || v17[1] != v15 )
          goto LABEL_40;
        while ( v17[1] != v15 || v17[2] != v9 )
        {
          v16 = *v17;
          if ( *v17 == -1i64 )
            goto LABEL_40;
          v17 = &pTable[1].EntryCount + 7 * v16;
        }
        if ( v16 < 0 )
          goto LABEL_40;
        v18 = (char *)&pTable[2] + 56 * v16;
        if ( !v18 )
          goto LABEL_40;
        Scaleform::GFx::AS3::Value::Assign(&v35, (Scaleform::GFx::AS3::Value *)(v18 + 8));
        Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::RemoveAlt<unsigned __int64>(
          &this->ValueH.mHash,
          &key);
        v9 = key;
        if ( key > v10 )
        {
          if ( (v35.Flags & 0x1F) != 0 )
          {
            v30 = (Scaleform::GFx::AS3::Value::VU *)(key - v5);
            v33.pFirst = (const unsigned __int64 *)&v30;
            v33.pSecond = &v35;
            Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
              &this->ValueH.mHash,
              this->ValueH.mHash.pHeap,
              &v33);
          }
          goto LABEL_40;
        }
        if ( deleted )
          break;
LABEL_40:
        key = ++v9;
        if ( v9 > this->ValueHHighInd )
        {
          ValueHHighInd = v31;
          goto LABEL_42;
        }
      }
      if ( deleted->Length != deleted->ValueA.Data.Size )
      {
        deleted->ValueHHighInd = deleted->Length;
        v34.pFirst = &deleted->ValueHHighInd;
        v34.pSecond = &v35;
        Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
          &deleted->ValueH.mHash,
          deleted->ValueH.mHash.pHeap,
          &v34);
        goto LABEL_39;
      }
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        &deleted->ValueA.Data,
        deleted->ValueA.Data.pHeap,
        deleted->ValueA.Data.Size + 1);
      Size = deleted->ValueA.Data.Size;
      v20 = deleted->ValueA.Data.Data - 1;
      v21 = &v20[Size] == 0i64;
      v22 = (Scaleform::GFx::AS3::Value::VU *)&v20[Size];
      v30 = v22;
      key = (unsigned __int64)v22;
      if ( !v21 )
      {
        v22->VS._1.VInt = v35.Flags;
        v22->VS._2.VObj = (Scaleform::GFx::AS3::Object *)v35.Bonus.pWeakProxy;
        v22[1] = v35.value;
        if ( (v35.Flags & 0x1F) > 9 )
        {
          if ( (v35.Flags & 0x200) != 0 )
          {
            ++v35.Bonus.pWeakProxy->RefCount;
          }
          else
          {
            if ( (v35.Flags & 0x1F) == 10 )
            {
              ++v35.value.VS._1.VStr->RefCount;
              goto LABEL_37;
            }
            if ( (v35.Flags & 0x1F) > 0xA )
            {
              if ( (v35.Flags & 0x1F) <= 0xF )
              {
                VObj = v35.value.VS._1;
              }
              else
              {
                if ( (v35.Flags & 0x1F) > 0x11 )
                  goto LABEL_37;
                VObj = (Scaleform::GFx::AS3::Value::V1U)v35.value.VS._2.VObj;
              }
              if ( VObj.VStr )
              {
                ++VObj.VStr->Size;
                VObj.VStr->Size &= 0x8FBFFFFF;
              }
            }
          }
        }
      }
LABEL_37:
      v5 = del_num;
LABEL_39:
      ++deleted->Length;
      goto LABEL_40;
    }
LABEL_42:
    if ( this->ValueHLowInd < ValueHLowInd )
      ValueHLowInd = this->ValueHLowInd;
    this->ValueHLowInd = ValueHLowInd;
    if ( ValueHLowInd <= v5 )
      v24 = 0i64;
    else
      v24 = ValueHLowInd - v5;
    this->ValueHLowInd = v24;
    if ( ValueHHighInd < this->ValueHHighInd )
      ValueHHighInd = this->ValueHHighInd;
    this->ValueHHighInd = ValueHHighInd;
    if ( ValueHHighInd <= v5 )
      v25 = 0i64;
    else
      v25 = ValueHHighInd - v5;
    this->ValueHHighInd = v25;
    if ( (v35.Flags & 0x1F) > 9 )
    {
      if ( (v35.Flags & 0x200) != 0 )
      {
        v21 = v35.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v21 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&v35.Bonus, 0, 24);
        v35.Flags &= 0xFFFFFDE0;
      }
      else
      {
        switch ( v35.Flags & 0x1F )
        {
          case 0xA:
            VStr = v35.value.VS._1.VStr;
            v21 = v35.value.VS._1.VStr->RefCount-- == 1;
            if ( v21 )
              Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
            break;
          case 0xB:
          case 0xC:
          case 0xD:
          case 0xE:
          case 0xF:
            v27 = v35.value.VS._1.VObj;
            if ( !v35.value.VS._1.VBool )
              goto LABEL_64;
            --v35.value.VS._1.VStr;
            break;
          case 0x10:
          case 0x11:
            v27 = v35.value.VS._2.VObj;
            if ( ((__int64)v35.value.VS._2.VObj & 1) != 0 )
            {
              --v35.value.VS._2.VObj;
            }
            else
            {
LABEL_64:
              if ( v27 )
              {
                RefCount = v27->RefCount;
                if ( (RefCount & 0x3FFFFF) != 0 )
                {
                  v27->RefCount = RefCount - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v27);
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
void __fastcall Scaleform::GFx::AS3::Impl::SparseArray::RemoveHash(
        Scaleform::GFx::AS3::Impl::SparseArray *this,
        unsigned __int64 first_ind,
        unsigned __int64 num)
{
  unsigned int v3; // ebx
  Scaleform::HashDH<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>,2,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *p_ValueH; // rdi
  __int64 v7; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > v8; // r8
  __int64 v9; // r9
  __int64 v10; // rcx
  __int64 v11; // rdx
  __int64 v12; // rax
  __int64 v13; // rax
  __int64 v14; // rdx
  __int64 v15; // rcx
  unsigned __int64 *v16; // rax
  __int64 v17; // [rsp+38h] [rbp+10h]
  unsigned __int64 key; // [rsp+40h] [rbp+18h] BYREF

  if ( num )
  {
    v3 = 0;
    p_ValueH = &this->ValueH;
    v7 = 0i64;
    do
    {
      v8.pTable = p_ValueH->mHash.pTable;
      v9 = v7 + first_ind;
      key = v7 + first_ind;
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
                &p_ValueH->mHash,
                &key);
          }
        }
      }
LABEL_15:
      v7 = ++v3;
    }
    while ( v3 < num );
  }
}

// File Line: 246
// RVA: 0x814510
void __fastcall Scaleform::GFx::AS3::Impl::SparseArray::Resize(
        Scaleform::GFx::AS3::Impl::SparseArray *this,
        unsigned __int64 newLength)
{
  Scaleform::HashDH<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>,2,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *p_ValueH; // rcx
  unsigned __int64 Size; // rax
  unsigned __int64 ValueHHighInd; // r8

  if ( !newLength )
  {
    Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      &this->ValueA.Data,
      0i64);
    p_ValueH = &this->ValueH;
LABEL_8:
    Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Clear(&p_ValueH->mHash);
    this->Length = newLength;
    this->ValueHLowInd = 0i64;
    this->ValueHHighInd = 0i64;
    return;
  }
  Size = this->ValueA.Data.Size;
  if ( newLength <= Size && Size )
  {
    Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      &this->ValueA.Data,
      newLength);
    p_ValueH = &this->ValueH;
    goto LABEL_8;
  }
  if ( newLength < this->ValueHLowInd )
  {
    p_ValueH = &this->ValueH;
    goto LABEL_8;
  }
  ValueHHighInd = this->ValueHHighInd;
  if ( newLength >= ValueHHighInd )
  {
    this->Length = newLength;
  }
  else
  {
    Scaleform::GFx::AS3::Impl::SparseArray::CutHash(this, newLength, ValueHHighInd - newLength + 1, 0i64);
    this->Length = newLength;
  }
}

// File Line: 289
// RVA: 0x7B1450
void __fastcall Scaleform::GFx::AS3::Impl::SparseArray::Assign(
        Scaleform::GFx::AS3::Impl::SparseArray *this,
        Scaleform::GFx::AS3::Impl::SparseArray *other)
{
  Scaleform::HashDH<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>,2,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *p_ValueH; // rcx

  if ( this != other )
  {
    this->Length = other->Length;
    this->ValueHLowInd = other->ValueHLowInd;
    p_ValueH = &this->ValueH;
    p_ValueH[-5].mHash.pHeap = (void *)other->ValueHHighInd;
    Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Assign(
      &p_ValueH->mHash,
      other->ValueH.mHash.pHeap,
      &other->ValueH.mHash);
    this->ValueH.mHash.pHeap = other->ValueH.mHash.pHeap;
    Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy>::operator=(
      &this->ValueA,
      &other->ValueA);
  }
}

// File Line: 301
// RVA: 0x80AD10
void __fastcall Scaleform::GFx::AS3::Impl::SparseArray::PushBack(
        Scaleform::GFx::AS3::Impl::SparseArray *this,
        Scaleform::GFx::AS3::Value *v)
{
  unsigned __int64 Length; // rcx
  void *pHeap; // rdx
  Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef key; // [rsp+20h] [rbp-18h] BYREF

  Length = this->Length;
  if ( Length == this->ValueA.Data.Size )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &this->ValueA.Data,
      this->ValueA.Data.pHeap,
      this->ValueA.Data.Size + 1);
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
      &this->ValueA.Data.Data[this->ValueA.Data.Size - 1].Flags,
      v);
  }
  else
  {
    key.pSecond = v;
    this->ValueHHighInd = Length;
    pHeap = this->ValueH.mHash.pHeap;
    key.pFirst = &this->ValueHHighInd;
    Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
      &this->ValueH.mHash,
      pHeap,
      &key);
  }
  ++this->Length;
}

// File Line: 364
// RVA: 0x806F10
void __fastcall Scaleform::GFx::AS3::Impl::SparseArray::Pick(
        Scaleform::GFx::AS3::Impl::SparseArray *this,
        Scaleform::GFx::AS3::ValueStack *x,
        unsigned __int64 num)
{
  unsigned __int64 Size; // r12
  unsigned __int64 v7; // rdi
  void *pHeap; // rdx
  Scaleform::GFx::AS3::Value *pCurrent; // rbx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef key; // [rsp+20h] [rbp-38h] BYREF
  __int64 v13; // [rsp+70h] [rbp+18h] BYREF

  if ( num )
  {
    Size = this->ValueA.Data.Size;
    if ( this->Length == Size )
    {
      Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        &this->ValueA.Data,
        Size + num);
      memmove(&this->ValueA.Data.Data[Size], &x->pCurrent[-(unsigned __int16)(num - 1)], 32 * num);
      x->pCurrent -= num;
      this->Length = this->ValueA.Data.Size;
    }
    else
    {
      v13 = num + this->ValueHHighInd;
      v7 = num;
      key.pFirst = (const unsigned __int64 *)&v13;
      do
      {
        pHeap = this->ValueH.mHash.pHeap;
        key.pSecond = x->pCurrent;
        Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
          &this->ValueH.mHash,
          pHeap,
          &key);
        pCurrent = x->pCurrent;
        if ( (x->pCurrent->Flags & 0x1F) > 9 )
        {
          if ( (x->pCurrent->Flags & 0x200) != 0 )
          {
            pWeakProxy = pCurrent->Bonus.pWeakProxy;
            if ( pWeakProxy->RefCount-- == 1 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            pCurrent->Flags &= 0xFFFFFDE0;
            pCurrent->Bonus.pWeakProxy = 0i64;
            pCurrent->value.VS._1.VStr = 0i64;
            pCurrent->value.VS._2.VObj = 0i64;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(x->pCurrent);
          }
        }
        --x->pCurrent;
        --v13;
        --v7;
      }
      while ( v7 );
      this->ValueHHighInd += num;
      this->Length += num;
    }
  }
}

// File Line: 391
// RVA: 0x7B0610
void __fastcall Scaleform::GFx::AS3::Impl::SparseArray::Append(
        Scaleform::GFx::AS3::Impl::SparseArray *this,
        Scaleform::GFx::AS3::Impl::SparseArray *other,
        __int64 ind,
        unsigned __int64 num)
{
  unsigned __int64 Length; // r13
  unsigned __int64 v5; // rbx
  __int64 v8; // r15
  __int64 v9; // r12
  Scaleform::GFx::AS3::Value *p_DefaultValue; // rbp
  signed __int64 Index; // rax
  char *v12; // rbp
  __int64 v13; // r15
  __int64 v14; // r12
  unsigned __int64 v15; // rax
  Scaleform::GFx::AS3::Value *v16; // rcx
  signed __int64 v17; // rax
  char *v18; // rcx
  void *pHeap; // rdx
  Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef v20; // [rsp+20h] [rbp-48h] BYREF
  unsigned __int64 key; // [rsp+70h] [rbp+8h] BYREF
  unsigned __int64 v22; // [rsp+88h] [rbp+20h]

  v22 = num;
  Length = other->Length;
  v5 = ind;
  if ( this->Length == this->ValueA.Data.Size )
  {
    if ( num )
    {
      v8 = ind;
      v9 = -ind;
      do
      {
        if ( v5 >= Length )
          break;
        key = v5;
        if ( v5 >= other->ValueA.Data.Size )
        {
          if ( v5 < other->ValueHLowInd
            || v5 > other->ValueHHighInd
            || (Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::findIndexAlt<unsigned __int64>(
                          &other->ValueH.mHash,
                          &key),
                Index < 0)
            || (v12 = (char *)&other->ValueH.mHash.pTable[2] + 56 * Index) == 0i64
            || (p_DefaultValue = (Scaleform::GFx::AS3::Value *)(v12 + 8)) == 0i64 )
          {
            p_DefaultValue = &other->DefaultValue;
          }
        }
        else
        {
          p_DefaultValue = &other->ValueA.Data.Data[v8];
        }
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          &this->ValueA.Data,
          this->ValueA.Data.pHeap,
          this->ValueA.Data.Size + 1);
        Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
          &this->ValueA.Data.Data[this->ValueA.Data.Size - 1],
          p_DefaultValue);
        ++v5;
        ++v8;
      }
      while ( v9 + v5 < v22 );
    }
    this->Length = this->ValueA.Data.Size;
  }
  else if ( num )
  {
    v13 = ind;
    v14 = -ind;
    do
    {
      if ( v5 >= Length )
        break;
      v15 = this->Length;
      key = v5;
      this->ValueHHighInd = v15;
      if ( v5 >= other->ValueA.Data.Size )
      {
        if ( v5 < other->ValueHLowInd
          || v5 > other->ValueHHighInd
          || (v17 = Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::findIndexAlt<unsigned __int64>(
                      &other->ValueH.mHash,
                      &key),
              v17 < 0)
          || (v18 = (char *)&other->ValueH.mHash.pTable[2] + 56 * v17) == 0i64
          || (v16 = (Scaleform::GFx::AS3::Value *)(v18 + 8)) == 0i64 )
        {
          v16 = &other->DefaultValue;
        }
      }
      else
      {
        v16 = &other->ValueA.Data.Data[v13];
      }
      pHeap = this->ValueH.mHash.pHeap;
      v20.pSecond = v16;
      v20.pFirst = &this->ValueHHighInd;
      Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
        &this->ValueH.mHash,
        pHeap,
        &v20);
      ++this->Length;
      ++v5;
      ++v13;
    }
    while ( v5 + v14 < v22 );
  }
}

// File Line: 414
// RVA: 0x7B07D0
void __fastcall Scaleform::GFx::AS3::Impl::SparseArray::Append(
        Scaleform::GFx::AS3::Impl::SparseArray *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  __int64 v5; // rbp
  unsigned __int64 *p_ValueHHighInd; // r14
  __int64 v7; // rbp
  void *pHeap; // rdx
  Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef key; // [rsp+20h] [rbp-18h] BYREF

  if ( this->Length == this->ValueA.Data.Size )
  {
    if ( argc )
    {
      v5 = argc;
      do
      {
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          &this->ValueA.Data,
          this->ValueA.Data.pHeap,
          this->ValueA.Data.Size + 1);
        Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
          &this->ValueA.Data.Data[this->ValueA.Data.Size - 1],
          argv++);
        --v5;
      }
      while ( v5 );
    }
    this->Length = this->ValueA.Data.Size;
  }
  else if ( argc )
  {
    p_ValueHHighInd = &this->ValueHHighInd;
    v7 = argc;
    key.pFirst = &this->ValueHHighInd;
    do
    {
      *p_ValueHHighInd = this->Length;
      pHeap = this->ValueH.mHash.pHeap;
      key.pSecond = argv;
      Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
        &this->ValueH.mHash,
        pHeap,
        &key);
      ++this->Length;
      ++argv;
      --v7;
    }
    while ( v7 );
  }
}

// File Line: 436
// RVA: 0x7F5AC0
void __fastcall Scaleform::GFx::AS3::Impl::SparseArray::Insert(
        Scaleform::GFx::AS3::Impl::SparseArray *this,
        unsigned __int64 pos,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v4; // rbp
  unsigned __int64 v5; // r12
  unsigned __int64 v6; // rdi
  Scaleform::GFx::AS3::Impl::SparseArray *v7; // rsi
  unsigned __int64 Size; // rax
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *p_ValueA; // r15
  __int64 v10; // rsi
  unsigned __int64 v11; // r12
  char *v12; // r13
  unsigned __int64 v13; // r14
  __int64 v14; // rax
  __int64 v15; // rbx
  unsigned __int64 v16; // r8
  unsigned __int64 ValueHLowInd; // rdx
  unsigned __int64 v18; // rbx
  unsigned __int64 v19; // r8
  __int64 v20; // rdi
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *pTable; // rax
  unsigned __int64 v22; // rdx
  __int64 v23; // rbx
  Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef key; // [rsp+28h] [rbp-50h] BYREF
  Scaleform::GFx::AS3::Impl::SparseArray *v25; // [rsp+80h] [rbp+8h] BYREF
  __int64 v26; // [rsp+88h] [rbp+10h]
  unsigned int v27; // [rsp+90h] [rbp+18h]

  v27 = argc;
  v25 = this;
  v4 = argv;
  v5 = argc;
  v6 = pos;
  v7 = this;
  Size = this->ValueA.Data.Size;
  if ( pos >= Size )
  {
    if ( pos == Size )
    {
      if ( argc )
      {
        v20 = argc;
        do
        {
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
            &v7->ValueA.Data,
            v7->ValueA.Data.pHeap,
            v7->ValueA.Data.Size + 1);
          Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
            &v7->ValueA.Data.Data[v7->ValueA.Data.Size - 1].Flags,
            v4++);
          --v20;
        }
        while ( v20 );
      }
      pTable = v7->ValueH.mHash.pTable;
      if ( pTable && pTable->EntryCount )
      {
        v18 = v5;
        v19 = v5;
        ValueHLowInd = v7->ValueHLowInd;
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
            &v7->ValueH.mHash,
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
      p_ValueA = &this->ValueA;
      v10 = argc;
      v11 = 32 * pos - (_QWORD)argv;
      do
      {
        v12 = (char *)v4 + v11;
        v13 = p_ValueA->Data.Size;
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          &p_ValueA->Data,
          p_ValueA->Data.pHeap,
          v13 + 1);
        if ( v13 + 1 > v13 )
        {
          v14 = (__int64)&p_ValueA->Data.Data[v13];
          v26 = v14;
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
            v26 = v14;
            --v15;
          }
          while ( v15 );
        }
        v16 = p_ValueA->Data.Size;
        if ( v6 < v16 - 1 )
          memmove(
            &v12[(unsigned __int64)p_ValueA->Data.Data + 32],
            &v12[(unsigned __int64)p_ValueA->Data.Data],
            32 * (v16 - v6 - 1));
        Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
          &v12[(unsigned __int64)p_ValueA->Data.Data],
          v4);
        ++v6;
        ++v4;
        --v10;
      }
      while ( v10 );
      v7 = v25;
      LODWORD(v5) = v27;
    }
    ValueHLowInd = v7->ValueHLowInd;
    if ( ValueHLowInd )
    {
      v18 = (unsigned int)v5;
      v19 = (unsigned int)v5;
LABEL_22:
      Scaleform::GFx::AS3::Impl::SparseArray::MoveHashRight(v7, ValueHLowInd, v19);
      v7->ValueHLowInd += v18;
      v7->ValueHHighInd += v18;
    }
  }
  v7->Length += (unsigned int)v5;
}

// File Line: 502
// RVA: 0x811F90
void __fastcall Scaleform::GFx::AS3::Impl::SparseArray::RemoveMultipleAt(
        Scaleform::GFx::AS3::Impl::SparseArray *this,
        unsigned __int64 pos,
        unsigned __int64 count,
        Scaleform::GFx::AS3::Impl::SparseArray::OP op)
{
  unsigned __int64 Size; // rsi
  unsigned __int64 v9; // rax
  unsigned __int64 v10; // r14
  void *pHeap; // rdx
  unsigned __int64 v12; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *pTable; // rax
  unsigned __int64 ValueHLowInd; // rdx
  unsigned __int64 v15; // rsi
  unsigned __int64 ValueHHighInd; // rax
  bool v17; // cf
  unsigned __int64 RightEqualInd; // rax
  Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef key; // [rsp+20h] [rbp-38h] BYREF
  unsigned __int64 v20; // [rsp+70h] [rbp+18h] BYREF

  if ( !count )
    return;
  Size = this->ValueA.Data.Size;
  if ( pos < Size )
  {
    v9 = pos + count;
    v10 = Size - pos;
    if ( pos + count < Size )
    {
      v20 = pos + count;
      key.pFirst = &v20;
      do
      {
        if ( !this->ValueHLowInd )
          this->ValueHLowInd = v9;
        pHeap = this->ValueH.mHash.pHeap;
        key.pSecond = &this->ValueA.Data.Data[v9];
        Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
          &this->ValueH.mHash,
          pHeap,
          &key);
        v12 = v20;
        if ( this->ValueHHighInd < v20 )
          this->ValueHHighInd = v20;
        v9 = v12 + 1;
        v20 = v9;
      }
      while ( v9 < Size );
    }
    Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::RemoveMultipleAt(
      &this->ValueA,
      pos,
      v10);
  }
  pTable = this->ValueH.mHash.pTable;
  if ( pTable )
  {
    if ( pTable->EntryCount )
    {
      ValueHLowInd = this->ValueHLowInd;
      v15 = pos + count;
      if ( ValueHLowInd < pos + count )
      {
        ValueHHighInd = this->ValueHHighInd;
        if ( ValueHHighInd >= pos )
        {
          v17 = ValueHLowInd < pos;
          if ( ValueHLowInd >= pos )
          {
            if ( ValueHHighInd < v15 )
            {
              Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Clear(&this->ValueH.mHash);
              RightEqualInd = 0i64;
              this->ValueHHighInd = 0i64;
LABEL_25:
              this->ValueHLowInd = RightEqualInd;
              goto LABEL_26;
            }
            v17 = ValueHLowInd < pos;
          }
          if ( v17 )
            ValueHLowInd = pos;
          Scaleform::GFx::AS3::Impl::SparseArray::RemoveHash(this, ValueHLowInd, count);
          if ( this->ValueHHighInd < v15 )
            this->ValueHHighInd = Scaleform::GFx::AS3::Impl::SparseArray::GetLeftEqualInd(this, pos);
          if ( this->ValueHLowInd < pos )
            goto LABEL_26;
          RightEqualInd = Scaleform::GFx::AS3::Impl::SparseArray::GetRightEqualInd(
                            this,
                            pos + count,
                            this->ValueHHighInd);
          goto LABEL_25;
        }
      }
    }
  }
LABEL_26:
  if ( op == opCut && this->Length <= pos + count )
    this->Length = pos;
}

// File Line: 572
// RVA: 0x7EB8E0
__int64 __fastcall Scaleform::GFx::AS3::Impl::SparseArray::GetLeftEqualInd(
        Scaleform::GFx::AS3::Impl::SparseArray *this,
        __int64 start_from)
{
  __int64 v2; // r8
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *pTable; // r9
  __int64 v4; // rcx
  __int64 v5; // rdx
  __int64 v6; // rax
  __int64 v7; // rax
  __int64 v8; // rdx
  __int64 v9; // rcx
  unsigned __int64 *v10; // rax
  char v12; // [rsp+Fh] [rbp+Fh]
  __int64 v13; // [rsp+10h] [rbp+10h]

  v2 = start_from;
  if ( start_from >= 0 )
  {
    pTable = this->ValueH.mHash.pTable;
    do
    {
      v13 = v2;
      if ( pTable )
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
        v8 = v7 & pTable->SizeMask;
        v9 = v8;
        v10 = &pTable[1].EntryCount + 7 * v8;
        if ( *v10 != -2i64 && v10[1] == v8 )
        {
          while ( v10[1] != v8 || v10[2] != v2 )
          {
            v9 = *v10;
            if ( *v10 == -1i64 )
              goto LABEL_14;
            v10 = &pTable[1].EntryCount + 7 * v9;
          }
          if ( v9 >= 0
            && (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *)((char *)&pTable[2] + 56 * v9) )
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
unsigned __int64 __fastcall Scaleform::GFx::AS3::Impl::SparseArray::GetRightEqualInd(
        Scaleform::GFx::AS3::Impl::SparseArray *this,
        unsigned __int64 start_from,
        unsigned __int64 end_ind)
{
  unsigned __int64 v3; // r9
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *pTable; // r10
  __int64 v5; // rcx
  __int64 v6; // rdx
  __int64 v7; // rax
  __int64 v8; // rax
  __int64 v9; // rdx
  __int64 v10; // rcx
  unsigned __int64 *v11; // rax
  char v13; // [rsp+Fh] [rbp+Fh]
  unsigned __int64 v14; // [rsp+10h] [rbp+10h]

  v3 = start_from;
  v14 = start_from;
  if ( start_from <= end_ind )
  {
    pTable = this->ValueH.mHash.pTable;
    do
    {
      if ( pTable )
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
        v9 = v8 & pTable->SizeMask;
        v10 = v9;
        v11 = &pTable[1].EntryCount + 7 * v9;
        if ( *v11 != -2i64 && v11[1] == v9 )
        {
          while ( v11[1] != v9 || v11[2] != v3 )
          {
            v10 = *v11;
            if ( *v11 == -1i64 )
              goto LABEL_14;
            v11 = &pTable[1].EntryCount + 7 * v10;
          }
          if ( v10 >= 0
            && (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *)((char *)&pTable[2] + 56 * v10) )
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
void __fastcall Scaleform::GFx::AS3::Impl::SparseArray::CutMultipleAt(
        Scaleform::GFx::AS3::Impl::SparseArray *this,
        unsigned __int64 pos,
        unsigned __int64 count,
        Scaleform::GFx::AS3::Impl::SparseArray *deleted)
{
  unsigned __int64 Size; // r14
  unsigned __int64 v9; // r14
  unsigned __int64 v10; // rdi
  unsigned __int64 v11; // rsi
  unsigned __int64 ValueHHighInd; // rax

  if ( count )
  {
    Size = this->ValueA.Data.Size;
    if ( pos < Size )
    {
      v9 = Size - pos;
      if ( count < v9 )
        v9 = count;
      if ( deleted && pos < v9 + pos )
      {
        v10 = pos;
        v11 = v9;
        do
        {
          Scaleform::GFx::AS3::Impl::SparseArray::PushBack(deleted, &this->ValueA.Data.Data[v10++]);
          --v11;
        }
        while ( v11 );
      }
      Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::RemoveMultipleAt(
        &this->ValueA,
        pos,
        v9);
    }
    Scaleform::GFx::AS3::Impl::SparseArray::CutHash(this, pos, count, deleted);
    ValueHHighInd = this->ValueHHighInd;
    if ( ValueHHighInd )
      this->Length = ValueHHighInd + 1;
    else
      this->Length = this->ValueA.Data.Size;
  }
}

// File Line: 624
// RVA: 0x7B1C00
Scaleform::GFx::AS3::Value *__fastcall Scaleform::GFx::AS3::Impl::SparseArray::At(
        Scaleform::GFx::AS3::Impl::SparseArray *this,
        unsigned __int64 ind)
{
  Scaleform::GFx::AS3::Value *result; // rax
  signed __int64 Index; // rax
  char *v5; // rax
  unsigned __int64 key; // [rsp+38h] [rbp+10h] BYREF

  key = ind;
  if ( ind < this->ValueA.Data.Size )
    return &this->ValueA.Data.Data[ind];
  if ( ind < this->ValueHLowInd || ind > this->ValueHHighInd )
    return &this->DefaultValue;
  Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::findIndexAlt<unsigned __int64>(
            &this->ValueH.mHash,
            &key);
  if ( Index < 0 )
    return &this->DefaultValue;
  v5 = (char *)&this->ValueH.mHash.pTable[2] + 56 * Index;
  if ( !v5 )
    return &this->DefaultValue;
  result = (Scaleform::GFx::AS3::Value *)(v5 + 8);
  if ( !result )
    return &this->DefaultValue;
  return result;
}

// File Line: 644
// RVA: 0x818030
void __fastcall Scaleform::GFx::AS3::Impl::SparseArray::Set(
        Scaleform::GFx::AS3::Impl::SparseArray *this,
        unsigned __int64 ind,
        Scaleform::GFx::AS3::Value *v)
{
  unsigned __int64 v4; // rax
  unsigned __int64 Size; // rcx
  void *pHeap; // rdx
  unsigned __int64 v8; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *pTable; // rcx
  Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef key; // [rsp+20h] [rbp-18h] BYREF
  unsigned __int64 v11; // [rsp+48h] [rbp+10h] BYREF

  v11 = ind;
  v4 = ind;
  if ( ind >= this->Length )
  {
    Scaleform::GFx::AS3::Impl::SparseArray::Resize(this, ind + 1);
    v4 = v11;
  }
  Size = this->ValueA.Data.Size;
  if ( v4 >= Size )
  {
    if ( v4 == Size )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        &this->ValueA.Data,
        (__int64 *)this->ValueA.Data.pHeap,
        Size + 1);
      Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
        &this->ValueA.Data.Data[this->ValueA.Data.Size - 1].Flags,
        v);
      Scaleform::GFx::AS3::Impl::SparseArray::Optimize(this);
    }
    else
    {
      pHeap = this->ValueH.mHash.pHeap;
      key.pFirst = &v11;
      key.pSecond = v;
      Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
        &this->ValueH.mHash,
        pHeap,
        &key);
      v8 = v11;
      if ( v11 < this->ValueHLowInd || (pTable = this->ValueH.mHash.pTable) != 0i64 && pTable->EntryCount == 1 )
        this->ValueHLowInd = v11;
      if ( v8 > this->ValueHHighInd )
        this->ValueHHighInd = v8;
    }
  }
  else
  {
    Scaleform::GFx::AS3::Value::Assign(&this->ValueA.Data.Data[v4], v);
  }
}

// File Line: 671
// RVA: 0x7AFCC0
void __fastcall Scaleform::GFx::AS3::Impl::SparseArray::AdjustValueHLowInd(
        Scaleform::GFx::AS3::Impl::SparseArray *this)
{
  unsigned int Flags; // edi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  signed __int64 Index; // rax
  char *v5; // rdx
  bool v6; // zf
  Scaleform::GFx::ASStringNode *VStr; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *VObj; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Value v10; // [rsp+28h] [rbp-30h] BYREF

  Flags = 0;
  v10.Flags = 0;
  pWeakProxy = 0i64;
  v10.Bonus.pWeakProxy = 0i64;
  if ( this->ValueHLowInd <= this->ValueHHighInd )
  {
    do
    {
      Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::findIndexAlt<unsigned __int64>(
                &this->ValueH.mHash,
                &this->ValueHLowInd);
      if ( Index >= 0 )
      {
        v5 = (char *)&this->ValueH.mHash.pTable[2] + 56 * Index;
        if ( v5 )
        {
          Scaleform::GFx::AS3::Value::Assign(&v10, (Scaleform::GFx::AS3::Value *)(v5 + 8));
          Flags = v10.Flags;
          if ( (v10.Flags & 0x1F) != 0 )
            break;
          Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::RemoveAlt<unsigned __int64>(
            &this->ValueH.mHash,
            &this->ValueHLowInd);
        }
      }
      ++this->ValueHLowInd;
    }
    while ( this->ValueHLowInd <= this->ValueHHighInd );
    pWeakProxy = v10.Bonus.pWeakProxy;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
    {
      v6 = pWeakProxy->RefCount-- == 1;
      if ( v6 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v10.Bonus, 0, 24);
      v10.Flags = Flags & 0xFFFFFDE0;
    }
    else
    {
      switch ( Flags & 0x1F )
      {
        case 0xAu:
          VStr = v10.value.VS._1.VStr;
          v6 = v10.value.VS._1.VStr->RefCount-- == 1;
          if ( v6 )
            Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
          break;
        case 0xBu:
        case 0xCu:
        case 0xDu:
        case 0xEu:
        case 0xFu:
          if ( !v10.value.VS._1.VBool )
          {
            VObj = v10.value.VS._1.VObj;
            goto LABEL_22;
          }
          --v10.value.VS._1.VStr;
          break;
        case 0x10u:
        case 0x11u:
          if ( ((__int64)v10.value.VS._2.VObj & 1) != 0 )
          {
            --v10.value.VS._2.VObj;
          }
          else
          {
            VObj = v10.value.VS._2.VObj;
LABEL_22:
            if ( VObj )
            {
              RefCount = VObj->RefCount;
              if ( (RefCount & 0x3FFFFF) != 0 )
              {
                VObj->RefCount = RefCount - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(VObj);
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
  unsigned int Flags; // r14d
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rbx
  bool i; // zf
  unsigned __int64 ValueHLowInd; // r9
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *pTable; // r8
  __int64 v7; // rdx
  __int64 v8; // rcx
  __int64 v9; // rax
  __int64 v10; // rdx
  __int64 v11; // rcx
  unsigned __int64 *v12; // rax
  __int64 v13; // rdx
  int v14; // edi
  unsigned __int64 Size; // rcx
  Scaleform::GFx::AS3::Value *v16; // rdx
  Scaleform::GFx::AS3::Value *v17; // rdx
  Scaleform::GFx::AS3::Value::V1U v18; // rcx
  Scaleform::GFx::AS3::Value::V2U v19; // r8
  Scaleform::GFx::AS3::Value v20; // [rsp+28h] [rbp-50h] BYREF

  Flags = 0;
  v20.Flags = 0;
  pWeakProxy = 0i64;
  v20.Bonus.pWeakProxy = 0i64;
  for ( i = this->ValueA.Data.Size == this->ValueHLowInd; i; i = this->ValueA.Data.Size == this->ValueHLowInd )
  {
    ValueHLowInd = this->ValueHLowInd;
    if ( ValueHLowInd > this->ValueHHighInd )
      break;
    pTable = this->ValueH.mHash.pTable;
    if ( !pTable )
      goto LABEL_29;
    v7 = 8i64;
    v8 = 5381i64;
    do
    {
      --v7;
      v9 = 65599 * v8 + *((unsigned __int8 *)&this->ValueHLowInd + v7);
      v8 = v9;
    }
    while ( v7 );
    v10 = v9 & pTable->SizeMask;
    v11 = v10;
    v12 = &pTable[1].EntryCount + 7 * v10;
    if ( *v12 == -2i64 || v12[1] != v10 )
      goto LABEL_29;
    while ( v12[1] != v10 || v12[2] != ValueHLowInd )
    {
      v11 = *v12;
      if ( *v12 == -1i64 )
        goto LABEL_29;
      v12 = &pTable[1].EntryCount + 7 * v11;
    }
    if ( v11 >= 0 && (v13 = (__int64)&pTable[2] + 56 * v11) != 0 )
    {
      Scaleform::GFx::AS3::Value::Assign(&v20, (Scaleform::GFx::AS3::Value *)(v13 + 8));
      Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::RemoveAlt<unsigned __int64>(
        &this->ValueH.mHash,
        &this->ValueHLowInd);
      ++this->ValueHLowInd;
      Flags = v20.Flags;
      v14 = v20.Flags & 0x1F;
      if ( (v20.Flags & 0x1F) == 0 )
      {
        Scaleform::GFx::AS3::Impl::SparseArray::AdjustValueHLowInd(this);
        pWeakProxy = v20.Bonus.pWeakProxy;
        break;
      }
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        &this->ValueA.Data,
        this->ValueA.Data.pHeap,
        this->ValueA.Data.Size + 1);
      Size = this->ValueA.Data.Size;
      v16 = this->ValueA.Data.Data - 1;
      i = &v16[Size] == 0i64;
      v17 = &v16[Size];
      pWeakProxy = v20.Bonus.pWeakProxy;
      if ( !i )
      {
        v17->Flags = Flags;
        v17->Bonus.pWeakProxy = pWeakProxy;
        v18 = v20.value.VS._1;
        v17->value.VS._1.VStr = v20.value.VS._1.VStr;
        v19.VObj = (Scaleform::GFx::AS3::Object *)v20.value.VS._2;
        v17->value.VS._2.VObj = v20.value.VS._2.VObj;
        if ( v14 > 9 )
        {
          if ( (Flags & 0x200) != 0 )
          {
            ++pWeakProxy->RefCount;
          }
          else if ( v14 == 10 )
          {
            ++v18.VStr->RefCount;
          }
          else if ( v14 <= 15 )
          {
            if ( v18.VStr )
              v18.VStr->Size = (v18.VStr->Size + 1) & 0x8FBFFFFF;
          }
          else if ( v14 <= 17 )
          {
            if ( v19.VObj )
              v19.VObj->RefCount = (v19.VObj->RefCount + 1) & 0x8FBFFFFF;
          }
        }
      }
    }
    else
    {
LABEL_29:
      this->ValueHLowInd = ValueHLowInd + 1;
      Scaleform::GFx::AS3::Impl::SparseArray::AdjustValueHLowInd(this);
    }
  }
  if ( this->ValueHLowInd > this->ValueHHighInd )
  {
    Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Clear(&this->ValueH.mHash);
    this->ValueHLowInd = 0i64;
    this->ValueHHighInd = 0i64;
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
    {
      i = pWeakProxy->RefCount-- == 1;
      if ( i )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
      memset(&v20.Bonus, 0, 24);
      v20.Flags = Flags & 0xFFFFFDE0;
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
  unsigned __int64 Size; // rsi
  unsigned int v3; // r15d
  unsigned __int64 v4; // rdi
  Scaleform::GFx::AS3::Value *v5; // rcx
  Scaleform::GFx::AS3::Value::V1U VObj; // rdx
  Scaleform::GFx::AS3::Value *p_DefaultValue; // r8
  signed __int64 Index; // rax
  char *v9; // r8
  bool v10; // zf
  Scaleform::GFx::ASStringNode *VStr; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v12; // rcx
  unsigned int RefCount; // eax
  char v14; // si
  unsigned __int64 v15; // rbx
  unsigned __int64 v16; // r10
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *pTable; // r9
  __int64 v18; // rcx
  __int64 v19; // rdx
  unsigned __int64 SizeMask; // r11
  __int64 v21; // rcx
  __int64 v22; // r8
  unsigned __int64 *v23; // rdx
  __int64 v24; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v25; // r9
  __int64 v26; // rcx
  __int64 v27; // rdx
  __int64 v28; // rax
  __int64 v29; // r8
  __int64 v30; // rdx
  unsigned __int64 *v31; // rcx
  char *v32; // rdx
  __int64 *p_v; // r8
  __int64 v34; // rcx
  __int64 v35; // rdx
  __int64 v36; // rcx
  __int64 v37; // r8
  unsigned __int64 *v38; // rdx
  __int64 v39; // rdx
  __int64 LeftEqualInd; // rax
  Scaleform::GFx::ASStringNode *v41; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v42; // rcx
  unsigned int v43; // eax
  Scaleform::GFx::ASStringNode *v44; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v45; // rcx
  unsigned int v46; // eax
  Scaleform::GFx::AS3::Value v; // [rsp+20h] [rbp-79h] BYREF
  Scaleform::GFx::AS3::Value v48; // [rsp+40h] [rbp-59h] BYREF
  Scaleform::GFx::AS3::Value v49; // [rsp+60h] [rbp-39h] BYREF
  __int64 v50[2]; // [rsp+80h] [rbp-19h] BYREF
  __int64 v51[2]; // [rsp+90h] [rbp-9h] BYREF
  Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef v52; // [rsp+A0h] [rbp+7h] BYREF
  __int64 v53; // [rsp+B0h] [rbp+17h]
  unsigned __int64 ind; // [rsp+100h] [rbp+67h] BYREF
  unsigned __int64 key; // [rsp+108h] [rbp+6Fh] BYREF

  v53 = -2i64;
  Size = this->ValueA.Data.Size;
  if ( this->Length == Size )
  {
    Scaleform::Alg::ReverseArray<Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy>>(&this->ValueA);
    return;
  }
  v3 = 0;
  ind = this->Length - 1;
  if ( Size )
  {
    v4 = 0i64;
    do
    {
      v5 = &this->ValueA.Data.Data[v4];
      v.Flags = v5->Flags;
      v.Bonus.pWeakProxy = v5->Bonus.pWeakProxy;
      v.value = v5->value;
      if ( (v5->Flags & 0x1F) > 9 )
      {
        if ( (v5->Flags & 0x200) != 0 )
        {
          ++v5->Bonus.pWeakProxy->RefCount;
        }
        else if ( (v5->Flags & 0x1F) == 10 )
        {
          ++v5->value.VS._1.VStr->RefCount;
        }
        else if ( (v5->Flags & 0x1F) > 0xA )
        {
          if ( (v5->Flags & 0x1F) <= 0xF )
          {
            VObj = v5->value.VS._1;
LABEL_14:
            if ( VObj.VStr )
              VObj.VStr->Size = (VObj.VStr->Size + 1) & 0x8FBFFFFF;
            goto LABEL_17;
          }
          if ( (v5->Flags & 0x1F) <= 0x11 )
          {
            VObj = (Scaleform::GFx::AS3::Value::V1U)v5->value.VS._2.VObj;
            goto LABEL_14;
          }
        }
      }
LABEL_17:
      key = ind;
      if ( ind >= this->ValueA.Data.Size )
      {
        if ( ind < this->ValueHLowInd
          || ind > this->ValueHHighInd
          || (Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::findIndexAlt<unsigned __int64>(
                        &this->ValueH.mHash,
                        &key),
              Index < 0)
          || (v9 = (char *)&this->ValueH.mHash.pTable[2] + 56 * Index) == 0i64
          || (p_DefaultValue = (Scaleform::GFx::AS3::Value *)(v9 + 8)) == 0i64 )
        {
          p_DefaultValue = &this->DefaultValue;
        }
      }
      else
      {
        p_DefaultValue = &this->ValueA.Data.Data[ind];
      }
      Scaleform::GFx::AS3::Impl::SparseArray::Set(this, v4, p_DefaultValue);
      Scaleform::GFx::AS3::Impl::SparseArray::Set(this, ind, &v);
      if ( (v.Flags & 0x1F) > 9 )
      {
        if ( (v.Flags & 0x200) != 0 )
        {
          v10 = v.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v10 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&v.Bonus, 0, 24);
          v.Flags &= 0xFFFFFDE0;
        }
        else
        {
          switch ( v.Flags & 0x1F )
          {
            case 0xA:
              VStr = v.value.VS._1.VStr;
              v10 = v.value.VS._1.VStr->RefCount-- == 1;
              if ( v10 )
                Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
              break;
            case 0xB:
            case 0xC:
            case 0xD:
            case 0xE:
            case 0xF:
              v12 = v.value.VS._1.VObj;
              if ( !v.value.VS._1.VBool )
                goto LABEL_37;
              --v.value.VS._1.VStr;
              break;
            case 0x10:
            case 0x11:
              v12 = v.value.VS._2.VObj;
              if ( ((__int64)v.value.VS._2.VObj & 1) != 0 )
              {
                --v.value.VS._2.VObj;
              }
              else
              {
LABEL_37:
                if ( v12 )
                {
                  RefCount = v12->RefCount;
                  if ( (RefCount & 0x3FFFFF) != 0 )
                  {
                    v12->RefCount = RefCount - 1;
                    Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v12);
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
    while ( v3 < Size );
  }
  v49.Flags = 0;
  v49.Bonus.pWeakProxy = 0i64;
  v48.Flags = 0;
  v48.Bonus.pWeakProxy = 0i64;
  v14 = 0;
  v15 = v3;
  v16 = ind;
  if ( v3 >= ind )
    goto LABEL_82;
  do
  {
    key = v15;
    pTable = this->ValueH.mHash.pTable;
    if ( !pTable )
      goto LABEL_79;
    v18 = 5381i64;
    v19 = 8i64;
    do
    {
      --v19;
      v18 = *((unsigned __int8 *)&key + v19) + 65599 * v18;
    }
    while ( v19 );
    SizeMask = pTable->SizeMask;
    v21 = SizeMask & v18;
    v22 = v21;
    v23 = &pTable[1].EntryCount + 7 * v21;
    if ( *v23 != -2i64 && v23[1] == v21 )
    {
      while ( v23[1] != v21 || v23[2] != v15 )
      {
        v22 = *v23;
        if ( *v23 == -1i64 )
          goto LABEL_66;
        v23 = &pTable[1].EntryCount + 7 * v22;
      }
      if ( v22 >= 0 )
      {
        v24 = (__int64)&pTable[2] + 56 * v22;
        if ( v24 )
        {
          Scaleform::GFx::AS3::Value::Assign(&v49, (Scaleform::GFx::AS3::Value *)(v24 + 8));
          v25 = this->ValueH.mHash.pTable;
          if ( v25 )
          {
            v26 = 5381i64;
            v27 = 8i64;
            do
            {
              --v27;
              v28 = 65599 * v26 + *((unsigned __int8 *)&ind + v27);
              v26 = v28;
            }
            while ( v27 );
            v29 = v28 & v25->SizeMask;
            v30 = v29;
            v31 = &v25[1].EntryCount + 7 * v29;
            if ( *v31 != -2i64 && v31[1] == v29 )
            {
              while ( v31[1] != v29 || v31[2] != ind )
              {
                v30 = *v31;
                if ( *v31 == -1i64 )
                  goto LABEL_65;
                v31 = &v25[1].EntryCount + 7 * v30;
              }
              if ( v30 >= 0 )
              {
                v32 = (char *)&v25[2] + 56 * v30;
                if ( v32 )
                {
                  Scaleform::GFx::AS3::Value::Assign(&v48, (Scaleform::GFx::AS3::Value *)(v32 + 8));
                  v52.pFirst = &ind;
                  v52.pSecond = &v49;
                  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
                    &this->ValueH.mHash,
                    this->ValueH.mHash.pHeap,
                    &v52);
                  v51[0] = (__int64)&key;
                  v51[1] = (__int64)&v48;
                  p_v = v51;
                  goto LABEL_77;
                }
              }
            }
          }
LABEL_65:
          v14 = 1;
          key = v15;
          Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::RemoveAlt<unsigned __int64>(
            &this->ValueH.mHash,
            &key);
          v50[0] = (__int64)&ind;
          v50[1] = (__int64)&v49;
          p_v = v50;
LABEL_78:
          Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
            &this->ValueH.mHash,
            this->ValueH.mHash.pHeap,
            (Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef *)p_v);
          v16 = ind;
          goto LABEL_79;
        }
      }
    }
LABEL_66:
    v34 = 5381i64;
    v35 = 8i64;
    do
    {
      --v35;
      v34 = *((unsigned __int8 *)&ind + v35) + 65599 * v34;
    }
    while ( v35 );
    v36 = SizeMask & v34;
    v37 = v36;
    v38 = &pTable[1].EntryCount + 7 * v36;
    if ( *v38 != -2i64 && v38[1] == v36 )
    {
      while ( v38[1] != v36 || v38[2] != v16 )
      {
        v37 = *v38;
        if ( *v38 == -1i64 )
          goto LABEL_79;
        v38 = &pTable[1].EntryCount + 7 * v37;
      }
      if ( v37 >= 0 )
      {
        v39 = (__int64)&pTable[2] + 56 * v37;
        if ( v39 )
        {
          Scaleform::GFx::AS3::Value::Assign(&v48, (Scaleform::GFx::AS3::Value *)(v39 + 8));
          v14 = 1;
          Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::RemoveAlt<unsigned __int64>(
            &this->ValueH.mHash,
            &ind);
          *(_QWORD *)&v.Flags = &key;
          v.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)&v48;
          p_v = (__int64 *)&v;
LABEL_77:
          key = v15;
          goto LABEL_78;
        }
      }
    }
LABEL_79:
    ++v3;
    ind = --v16;
    v15 = v3;
  }
  while ( v3 < v16 );
  if ( v14 )
  {
    LeftEqualInd = Scaleform::GFx::AS3::Impl::SparseArray::GetLeftEqualInd(this, this->ValueHHighInd);
    this->ValueHHighInd = LeftEqualInd;
    this->ValueHLowInd = Scaleform::GFx::AS3::Impl::SparseArray::GetRightEqualInd(this, 0i64, LeftEqualInd);
  }
LABEL_82:
  if ( (v48.Flags & 0x1F) > 9 )
  {
    if ( (v48.Flags & 0x200) != 0 )
    {
      v10 = v48.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v10 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v48.Bonus, 0, 24);
      v48.Flags &= 0xFFFFFDE0;
    }
    else
    {
      switch ( v48.Flags & 0x1F )
      {
        case 0xA:
          v41 = v48.value.VS._1.VStr;
          v10 = v48.value.VS._1.VStr->RefCount-- == 1;
          if ( v10 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v41);
          break;
        case 0xB:
        case 0xC:
        case 0xD:
        case 0xE:
        case 0xF:
          v42 = v48.value.VS._1.VObj;
          if ( !v48.value.VS._1.VBool )
            goto LABEL_94;
          --v48.value.VS._1.VStr;
          break;
        case 0x10:
        case 0x11:
          v42 = v48.value.VS._2.VObj;
          if ( ((__int64)v48.value.VS._2.VObj & 1) != 0 )
          {
            --v48.value.VS._2.VObj;
          }
          else
          {
LABEL_94:
            if ( v42 )
            {
              v43 = v42->RefCount;
              if ( (v43 & 0x3FFFFF) != 0 )
              {
                v42->RefCount = v43 - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v42);
              }
            }
          }
          break;
        default:
          break;
      }
    }
  }
  if ( (v49.Flags & 0x1F) > 9 )
  {
    if ( (v49.Flags & 0x200) != 0 )
    {
      v10 = v49.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v10 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v49.Bonus, 0, 24);
      v49.Flags &= 0xFFFFFDE0;
    }
    else
    {
      switch ( v49.Flags & 0x1F )
      {
        case 0xA:
          v44 = v49.value.VS._1.VStr;
          v10 = v49.value.VS._1.VStr->RefCount-- == 1;
          if ( v10 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v44);
          break;
        case 0xB:
        case 0xC:
        case 0xD:
        case 0xE:
        case 0xF:
          v45 = v49.value.VS._1.VObj;
          if ( !v49.value.VS._1.VBool )
            goto LABEL_109;
          --v49.value.VS._1.VStr;
          break;
        case 0x10:
        case 0x11:
          v45 = v49.value.VS._2.VObj;
          if ( ((__int64)v49.value.VS._2.VObj & 1) != 0 )
          {
            --v49.value.VS._2.VObj;
          }
          else
          {
LABEL_109:
            if ( v45 )
            {
              v46 = v45->RefCount;
              if ( (v46 & 0x3FFFFF) != 0 )
              {
                v45->RefCount = v46 - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v45);
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
void __fastcall Scaleform::GFx::AS3::Impl::SparseArray::ForEachChild_GC(
        Scaleform::GFx::AS3::Impl::SparseArray *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *pTable; // rcx
  Scaleform::HashDH<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>,2,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *p_ValueH; // rbx
  unsigned __int64 SizeMask; // rdx
  unsigned __int64 v9; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v10; // rcx
  signed __int64 v11; // rbx
  __int64 v12; // rcx
  __int64 v13; // rdx
  int v14; // ecx
  unsigned int v15; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> **v16; // rdx
  Scaleform::GFx::AS3::RefCountBaseGC<328> **v17; // rcx
  unsigned __int64 v18; // rcx
  _QWORD *v19; // rax
  __int128 v20; // [rsp+20h] [rbp-18h]

  Scaleform::GFx::AS3::ForEachChild_GC(prcc, &this->ValueA, op);
  pTable = this->ValueH.mHash.pTable;
  p_ValueH = &this->ValueH;
  if ( pTable )
  {
    SizeMask = pTable->SizeMask;
    v9 = 0i64;
    v10 = pTable + 1;
    do
    {
      if ( v10->EntryCount != -2i64 )
        break;
      ++v9;
      v10 = (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *)((char *)v10 + 56);
    }
    while ( v9 <= SizeMask );
    *(_QWORD *)&v20 = p_ValueH;
    *((_QWORD *)&v20 + 1) = v9;
  }
  else
  {
    v20 = 0ui64;
  }
  v11 = *((_QWORD *)&v20 + 1);
  while ( (_QWORD)v20 )
  {
    v12 = *(_QWORD *)v20;
    if ( !*(_QWORD *)v20 || v11 > *(_QWORD *)(v12 + 8) )
      break;
    v13 = v12 + 56 * v11;
    v14 = *(_DWORD *)(v13 + 40);
    v15 = v14 & 0x1F;
    if ( v15 <= 0xA || (v14 & 0x200) != 0 || (*(_DWORD *)(v13 + 40) & 0x1Fu) < 0xB )
      goto LABEL_22;
    if ( (*(_DWORD *)(v13 + 40) & 0x1Fu) <= 0xF )
    {
      v17 = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)(v13 + 56);
      if ( !*(_QWORD *)(v13 + 56) )
        goto LABEL_22;
      v16 = 0i64;
      if ( v15 - 11 <= 4 )
        v16 = v17;
    }
    else
    {
      if ( (*(_DWORD *)(v13 + 40) & 0x1Fu) > 0x11 )
        goto LABEL_22;
      v16 = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)(v13 + 64);
      if ( !*v16 )
        goto LABEL_22;
    }
    op(prcc, v16);
LABEL_22:
    v18 = *(_QWORD *)(*(_QWORD *)v20 + 8i64);
    if ( v11 <= (__int64)v18 && ++v11 <= v18 )
    {
      v19 = (_QWORD *)(*(_QWORD *)v20 + 56 * v11 + 16);
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
Scaleform::GFx::AS3::AbsoluteIndex *__fastcall Scaleform::GFx::AS3::Impl::SparseArray::GetNextArrayIndex(
        Scaleform::GFx::AS3::Impl::SparseArray *this,
        Scaleform::GFx::AS3::AbsoluteIndex *result,
        Scaleform::GFx::AS3::AbsoluteIndex ind)
{
  Scaleform::GFx::AS3::AbsoluteIndex *v5; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *pTable; // rax
  unsigned __int64 Size; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v8; // rax
  unsigned __int64 ValueHHighInd; // rbx
  unsigned __int64 v10; // r8
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v11; // r10
  __int64 v12; // rcx
  __int64 v13; // rdx
  __int64 v14; // rax
  __int64 v15; // rax
  __int64 v16; // rdx
  __int64 v17; // rcx
  unsigned __int64 *v18; // rax
  char v19; // [rsp+1Fh] [rbp+1Fh]
  unsigned __int64 v20; // [rsp+20h] [rbp+20h]

  if ( ind.Index < 0 )
  {
    if ( this->ValueA.Data.Size )
    {
      result->Index = 0i64;
      return result;
    }
    pTable = this->ValueH.mHash.pTable;
    if ( pTable && pTable->EntryCount )
    {
      result->Index = this->ValueHLowInd;
      return result;
    }
LABEL_29:
    result->Index = -1i64;
    return result;
  }
  Size = this->ValueA.Data.Size;
  if ( ind.Index < Size )
  {
    if ( LODWORD(ind.Index) != Size - 1 )
    {
      v5 = result;
      result->Index = ind.Index + 1;
      return v5;
    }
    v8 = this->ValueH.mHash.pTable;
    if ( v8 && v8->EntryCount )
    {
      result->Index = this->ValueHLowInd;
      return result;
    }
  }
  if ( LODWORD(ind.Index) < this->ValueHLowInd )
    goto LABEL_29;
  ValueHHighInd = this->ValueHHighInd;
  if ( LODWORD(ind.Index) > ValueHHighInd )
    goto LABEL_29;
  v10 = (unsigned int)(LODWORD(ind.Index) + 1);
  v20 = v10;
  if ( v10 > ValueHHighInd )
    goto LABEL_29;
  v11 = this->ValueH.mHash.pTable;
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
    if ( v10 > ValueHHighInd )
      goto LABEL_29;
  }
  result->Index = v10;
  return result;
}

// File Line: 882
// RVA: 0x7D7190
void __fastcall Scaleform::GFx::AS3::Impl::SparseArray::ForEachDense(
        Scaleform::GFx::AS3::Impl::SparseArray *this,
        Scaleform::GFx::AS3::Impl::ArrayFunc *f)
{
  unsigned __int64 Size; // rbp
  unsigned int v3; // ebx
  __int64 v6; // rax

  Size = this->ValueA.Data.Size;
  v3 = 0;
  if ( Size )
  {
    v6 = 0i64;
    do
    {
      f->vfptr->operator()(f, v3++, &this->ValueA.Data.Data[v6]);
      v6 = v3;
    }
    while ( v3 < Size );
  }
}

// File Line: 890
// RVA: 0x7D72A0
void __fastcall Scaleform::GFx::AS3::Impl::SparseArray::ForEachSparse(
        Scaleform::GFx::AS3::Impl::SparseArray *this,
        Scaleform::GFx::AS3::Impl::ArrayFunc *f)
{
  Scaleform::HashDH<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>,2,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *p_ValueH; // r8
  unsigned __int64 v3; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *pTable; // rcx
  unsigned __int64 SizeMask; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v7; // rcx
  signed __int64 v8; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *v9; // rcx
  unsigned __int64 v10; // rcx
  unsigned __int64 *v11; // rax
  Scaleform::HashDH<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>,2,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *v12; // [rsp+20h] [rbp-18h]

  p_ValueH = &this->ValueH;
  v3 = 0i64;
  pTable = this->ValueH.mHash.pTable;
  if ( pTable )
  {
    SizeMask = pTable->SizeMask;
    v7 = pTable + 1;
    do
    {
      if ( v7->EntryCount != -2i64 )
        break;
      ++v3;
      v7 = (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *)((char *)v7 + 56);
    }
    while ( v3 <= SizeMask );
    v12 = p_ValueH;
  }
  else
  {
    v12 = 0i64;
  }
  v8 = v3;
  while ( v12 )
  {
    v9 = v12->mHash.pTable;
    if ( !v12->mHash.pTable || v8 > (signed __int64)v9->SizeMask )
      break;
    f->vfptr->operator()(
      f,
      *((unsigned int *)&v9[2].EntryCount + 14 * v8),
      (Scaleform::GFx::AS3::Value *)(&v9[2].SizeMask + 7 * v8));
    v10 = v12->mHash.pTable->SizeMask;
    if ( v8 <= (__int64)v10 && ++v8 <= v10 )
    {
      v11 = &v12->mHash.pTable[1].EntryCount + 7 * v8;
      do
      {
        if ( *v11 != -2i64 )
          break;
        ++v8;
        v11 += 7;
      }
      while ( v8 <= v10 );
    }
  }
}

// File Line: 902
// RVA: 0x7912B0
void __fastcall Scaleform::GFx::AS3::Impl::Value2StrCollector::operator()(
        Scaleform::GFx::AS3::Impl::Value2StrCollector *this,
        unsigned int ind,
        Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::ASStringNode *pNode; // rbx
  bool v7; // zf
  Scaleform::GFx::ASStringNode *v8; // rcx
  Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const *,unsigned long> val; // [rsp+28h] [rbp-30h] BYREF
  Scaleform::GFx::AS3::CheckResult v10; // [rsp+60h] [rbp+8h] BYREF
  Scaleform::GFx::ASString result; // [rsp+78h] [rbp+20h] BYREF

  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    this->Vm->StringManagerRef,
    &result);
  if ( Scaleform::GFx::AS3::Value::Convert2String(v, &v10, &result)->Result )
  {
    pNode = result.pNode;
    val.First = result;
    ++result.pNode->RefCount;
    val.Second = v;
    val.Third = ind;
    Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
      &this->Pairs->Data,
      &val);
    v7 = pNode->RefCount-- == 1;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  v8 = result.pNode;
  v7 = result.pNode->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
}

// File Line: 914
// RVA: 0x791350
void __fastcall Scaleform::GFx::AS3::Impl::ValuePtrCollector::operator()(
        Scaleform::GFx::AS3::Impl::ValuePtrCollector *this,
        unsigned int ind,
        Scaleform::GFx::AS3::Value *v)
{
  Scaleform::ArrayDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2,Scaleform::ArrayDefaultPolicy> *Pairs; // rdi
  unsigned __int64 v5; // rbx
  unsigned __int64 v6; // r8
  Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long> *Data; // rcx
  Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long> *v8; // rcx
  __int64 v9; // [rsp+28h] [rbp-10h]

  Pairs = this->Pairs;
  LODWORD(v9) = ind;
  v5 = Pairs->Data.Size + 1;
  if ( v5 >= Pairs->Data.Size )
  {
    if ( v5 <= Pairs->Data.Policy.Capacity )
      goto LABEL_7;
    v6 = v5 + (v5 >> 2);
  }
  else
  {
    if ( v5 >= Pairs->Data.Policy.Capacity >> 1 )
      goto LABEL_7;
    v6 = Pairs->Data.Size + 1;
  }
  Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    &Pairs->Data,
    Pairs->Data.pHeap,
    v6);
LABEL_7:
  Data = Pairs->Data.Data;
  Pairs->Data.Size = v5;
  v8 = &Data[v5 - 1];
  if ( v8 )
  {
    v8->First = v;
    *(_QWORD *)&v8->Second = v9;
  }
}

// File Line: 920
// RVA: 0x7911E0
void __fastcall Scaleform::GFx::AS3::Impl::Value2NumberCollector::operator()(
        Scaleform::GFx::AS3::Impl::Value2NumberCollector *this,
        unsigned int ind,
        Scaleform::GFx::AS3::Value *v)
{
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *Pairs; // rdi
  long double v7; // xmm6_8
  unsigned __int64 v8; // rbx
  unsigned __int64 v9; // r8
  Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const *,unsigned long> *Data; // rax
  long double *v11; // rdx
  Scaleform::GFx::AS3::Value *v12; // xmm0_8
  __int64 v13; // xmm1_8
  long double v14[2]; // [rsp+20h] [rbp-38h] BYREF
  Scaleform::GFx::AS3::Value *v15; // [rsp+30h] [rbp-28h]
  __int64 v16; // [rsp+38h] [rbp-20h]
  Scaleform::GFx::AS3::CheckResult result; // [rsp+78h] [rbp+20h] BYREF

  if ( Scaleform::GFx::AS3::Value::Convert2Number(v, &result, v14)->Result )
  {
    v15 = v;
    LODWORD(v16) = ind;
    Pairs = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)this->Pairs;
    v7 = v14[0];
    v8 = Pairs->Size + 1;
    if ( v8 >= Pairs->Size )
    {
      if ( v8 <= Pairs->Policy.Capacity )
        goto LABEL_8;
      v9 = v8 + (v8 >> 2);
    }
    else
    {
      if ( v8 >= Pairs->Policy.Capacity >> 1 )
        goto LABEL_8;
      v9 = Pairs->Size + 1;
    }
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Impl::Triple<double,Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Impl::Triple<double,Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      Pairs,
      Pairs[1].Data,
      v9);
LABEL_8:
    Data = Pairs->Data;
    Pairs->Size = v8;
    v11 = (long double *)&Data[v8 - 1];
    if ( v11 )
    {
      v12 = v15;
      v13 = v16;
      *v11 = v7;
      *((_QWORD *)v11 + 1) = v12;
      *((_QWORD *)v11 + 2) = v13;
    }
  }
}

// File Line: 970
// RVA: 0x76C670
Scaleform::GFx::AS3::Value *__fastcall Scaleform::GFx::AS3::Impl::GetMethodDefArg<Scaleform::GFx::AS3::Instances::fl_display::MovieClip,13,1,Scaleform::GFx::AS3::Value const &>(
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::StringManager *__formal)
{
  Scaleform::GFx::AS3::Value::V1U VObj; // rax

  if ( (_S12_13 & 1) == 0 )
  {
    _S12_13 |= 1u;
    v_0.Flags = 12;
    v_0.Bonus.pWeakProxy = 0i64;
    v_0.value.VS._1.VStr = 0i64;
    atexit(Scaleform::GFx::AS3::Value::GetNull_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  result->Flags = v_0.Flags;
  result->Bonus.pWeakProxy = v_0.Bonus.pWeakProxy;
  result->value = v_0.value;
  if ( (v_0.Flags & 0x1F) > 9 )
  {
    if ( (v_0.Flags & 0x200) != 0 )
    {
      ++v_0.Bonus.pWeakProxy->RefCount;
    }
    else
    {
      if ( (v_0.Flags & 0x1F) == 10 )
      {
        ++v_0.value.VS._1.VStr->RefCount;
        return result;
      }
      if ( (v_0.Flags & 0x1F) > 0xA )
      {
        if ( (v_0.Flags & 0x1F) <= 0xF )
        {
          VObj = v_0.value.VS._1;
        }
        else
        {
          if ( (v_0.Flags & 0x1F) > 0x11 )
            return result;
          VObj = (Scaleform::GFx::AS3::Value::V1U)v_0.value.VS._2.VObj;
        }
        if ( VObj.VStr )
        {
          ++VObj.VStr->Size;
          VObj.VStr->Size &= 0x8FBFFFFF;
        }
      }
    }
  }
  return result;
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
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl::Array,2,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl::Array *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl::Array::AS3join;
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
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl::Array,4,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl::Array *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl::Array::AS3push;
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
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl::Array,5,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array>>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl::Array *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *))Scaleform::GFx::AS3::Instances::fl::Array::AS3reverse;
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
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl::Array,6,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl::Array *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl::Array::AS3concat;
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
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl::Array,9,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl::Array *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl::Array::AS3unshift;
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
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl::Array,10,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl::Array *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl::Array::AS3splice;
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
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Instances::fl::Array,11,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl::Array *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Instances::fl::Array::AS3sort;
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
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::Array(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::MemoryHeap *MHeap; // rdx

  Scaleform::GFx::AS3::Instance::Instance(this, t);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Array::`vftable;
  MHeap = t->pVM->MHeap;
  this->SA.Length = 0i64;
  this->SA.ValueHLowInd = 0i64;
  this->SA.ValueHHighInd = 0i64;
  this->SA.DefaultValue.Flags = 0;
  this->SA.DefaultValue.Bonus.pWeakProxy = 0i64;
  this->SA.ValueA.Data.Data = 0i64;
  this->SA.ValueA.Data.Size = 0i64;
  this->SA.ValueA.Data.Policy.Capacity = 0i64;
  this->SA.ValueA.Data.pHeap = MHeap;
  this->SA.ValueH.mHash.pTable = 0i64;
  this->SA.ValueH.mHash.pHeap = MHeap;
}

// File Line: 1059
// RVA: 0x851810
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::lengthSet(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int newLength)
{
  Scaleform::GFx::AS3::Impl::SparseArray::Resize(&this->SA, newLength);
}

// File Line: 1066
// RVA: 0x79FCD0
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::AS3join(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *const argv)
{
  Scaleform::GFx::ASString *v6; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v8; // zf
  Scaleform::GFx::ASStringNode *v9; // rcx
  Scaleform::GFx::ASString v10; // [rsp+20h] [rbp-18h] BYREF
  __int64 v11; // [rsp+28h] [rbp-10h]
  Scaleform::GFx::ASString sep; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+50h] [rbp+18h] BYREF

  v11 = -2i64;
  sep.pNode = this->pTraits.pObject->pVM->StringManagerRef->Builtins[14].pNode;
  ++sep.pNode->RefCount;
  if ( !argc || Scaleform::GFx::AS3::Value::Convert2String(argv, &resulta, &sep)->Result )
  {
    v6 = Scaleform::GFx::AS3::Instances::fl::Array::ToStringInternal(this, &v10, &sep);
    Scaleform::GFx::AS3::Value::Assign(result, v6);
    pNode = v10.pNode;
    v8 = v10.pNode->RefCount-- == 1;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  v9 = sep.pNode;
  v8 = sep.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
}

// File Line: 1087
// RVA: 0x7A1480
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::AS3pop(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Impl::SparseArray *p_SA; // rbx
  unsigned __int64 Length; // rdx
  Scaleform::GFx::AS3::Value *v5; // rax

  p_SA = &this->SA;
  Length = this->SA.Length;
  if ( Length )
  {
    v5 = Scaleform::GFx::AS3::Impl::SparseArray::At(&this->SA, Length - 1);
    Scaleform::GFx::AS3::Value::Assign(result, v5);
    if ( p_SA->Length )
      Scaleform::GFx::AS3::Impl::SparseArray::RemoveMultipleAt(p_SA, p_SA->Length - 1, 1ui64, opCut);
  }
}

// File Line: 1104
// RVA: 0x7A1D80
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::AS3push(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *const argv)
{
  unsigned int *p_SA; // rbx

  p_SA = (unsigned int *)&this->SA;
  Scaleform::GFx::AS3::Impl::SparseArray::Append(&this->SA, argc, argv);
  Scaleform::GFx::AS3::Value::SetUInt32(result, *p_SA);
}

// File Line: 1118
// RVA: 0x7A25B0
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::AS3reverse(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result)
{
  Scaleform::GFx::AS3::Impl::SparseArray::Reverse(&this->SA);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    result,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)this);
}

// File Line: 1132
// RVA: 0x79BE40
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::AS3concat(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *const argv)
{
  Scaleform::GFx::AS3::Instances::fl::Array *pV; // rbx
  Scaleform::GFx::AS3::Traits *ValueTraits; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> resulta; // [rsp+40h] [rbp+8h] BYREF

  Scaleform::GFx::AS3::InstanceTraits::fl::Array::MakeInstance(
    &resulta,
    (Scaleform::GFx::AS3::InstanceTraits::fl::Array *)this->pTraits.pObject);
  pV = resulta.pV;
  Scaleform::GFx::AS3::Value::Pick(result, resulta.pV);
  if ( pV != this )
    Scaleform::GFx::AS3::Impl::SparseArray::Assign(&pV->SA, &this->SA);
  if ( argc == 1
    && (ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(this->pTraits.pObject->pVM, argv),
        ValueTraits->TraitsType == Traits_Array)
    && (ValueTraits->Flags & 0x20) == 0 )
  {
    Scaleform::GFx::AS3::Impl::SparseArray::Append(
      &pV->SA,
      (Scaleform::GFx::AS3::Impl::SparseArray *)&argv->value.VS._1.VStr[1].16,
      0i64,
      (unsigned __int64)argv->value.VS._1.VStr[1].pLower);
  }
  else
  {
    Scaleform::GFx::AS3::Impl::SparseArray::Append(&pV->SA, argc, argv);
  }
}

// File Line: 1162
// RVA: 0x7A3CF0
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::AS3shift(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Impl::SparseArray *p_SA; // rbx
  Scaleform::GFx::AS3::Value *v4; // rax

  p_SA = &this->SA;
  if ( this->SA.Length )
  {
    v4 = Scaleform::GFx::AS3::Impl::SparseArray::At(&this->SA, 0i64);
    Scaleform::GFx::AS3::Value::Assign(result, v4);
    if ( p_SA->Length )
    {
      if ( p_SA->ValueA.Data.Size )
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
          &p_SA->ValueA,
          0i64);
      Scaleform::GFx::AS3::Impl::SparseArray::CutHash(p_SA, 0i64, 1ui64, 0i64);
      Scaleform::GFx::AS3::Impl::SparseArray::Optimize(p_SA);
      --p_SA->Length;
    }
  }
  else
  {
    Scaleform::GFx::AS3::Value::SetUndefined(result);
  }
}

// File Line: 1181
// RVA: 0x7A3D70
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::AS3slice(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *result,
        int startIndex,
        int endIndex)
{
  Scaleform::GFx::AS3::Instances::fl::Array *pObject; // rcx
  Scaleform::GFx::AS3::Instances::fl::Array *pV; // rbx
  unsigned int RefCount; // eax
  unsigned __int64 v11; // rbp
  __int64 v12; // r15
  __int64 v13; // r12
  Scaleform::GFx::AS3::Value *p_DefaultValue; // r14
  signed __int64 Index; // rax
  char *v16; // r14
  unsigned __int64 Length; // rcx
  Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef key; // [rsp+20h] [rbp-38h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> resulta; // [rsp+60h] [rbp+8h] BYREF

  Scaleform::GFx::AS3::InstanceTraits::fl::Array::MakeInstance(
    &resulta,
    (Scaleform::GFx::AS3::InstanceTraits::fl::Array *)this->pTraits.pObject);
  pObject = result->pObject;
  pV = resulta.pV;
  if ( resulta.pV != result->pObject )
  {
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)pObject - 1);
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
    result->pObject = pV;
  }
  if ( startIndex < 0 )
    startIndex += LODWORD(this->SA.Length);
  if ( startIndex < 0 )
    startIndex = 0;
  if ( endIndex < 0 )
    endIndex += LODWORD(this->SA.Length);
  if ( (int)this->SA.Length < endIndex )
    endIndex = this->SA.Length;
  if ( startIndex < endIndex )
  {
    v11 = startIndex;
    v12 = startIndex;
    v13 = (unsigned int)(endIndex - startIndex);
    do
    {
      resulta.pV = (Scaleform::GFx::AS3::Instances::fl::Array *)v11;
      if ( v11 >= this->SA.ValueA.Data.Size )
      {
        if ( v11 < this->SA.ValueHLowInd
          || v11 > this->SA.ValueHHighInd
          || (Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::findIndexAlt<unsigned __int64>(
                        &this->SA.ValueH.mHash,
                        (const unsigned __int64 *)&resulta),
              Index < 0)
          || (v16 = (char *)&this->SA.ValueH.mHash.pTable[2] + 56 * Index) == 0i64
          || (p_DefaultValue = (Scaleform::GFx::AS3::Value *)(v16 + 8)) == 0i64 )
        {
          p_DefaultValue = &this->SA.DefaultValue;
        }
      }
      else
      {
        p_DefaultValue = &this->SA.ValueA.Data.Data[v12];
      }
      Length = pV->SA.Length;
      if ( Length == pV->SA.ValueA.Data.Size )
      {
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          &pV->SA.ValueA.Data,
          pV->SA.ValueA.Data.pHeap,
          pV->SA.ValueA.Data.Size + 1);
        Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
          &pV->SA.ValueA.Data.Data[pV->SA.ValueA.Data.Size - 1],
          p_DefaultValue);
      }
      else
      {
        key.pSecond = p_DefaultValue;
        pV->SA.ValueHHighInd = Length;
        key.pFirst = &pV->SA.ValueHHighInd;
        Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
          &pV->SA.ValueH.mHash,
          pV->SA.ValueH.mHash.pHeap,
          &key);
      }
      ++pV->SA.Length;
      ++v11;
      ++v12;
      --v13;
    }
    while ( v13 );
  }
}

// File Line: 1210
// RVA: 0x7A9140
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::AS3unshift(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *const argv)
{
  unsigned int *p_SA; // rbx

  p_SA = (unsigned int *)&this->SA;
  Scaleform::GFx::AS3::Impl::SparseArray::Insert(&this->SA, 0i64, argc, argv);
  Scaleform::GFx::AS3::Value::SetUInt32(result, *p_SA);
}

// File Line: 1224
// RVA: 0x7A6370
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::AS3splice(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *const argv)
{
  Scaleform::GFx::AS3::Impl::SparseArray *v4; // rdi
  int v7; // eax
  int Length; // ecx
  Scaleform::GFx::AS3::Impl::SparseArray *p_SA; // r14
  Scaleform::GFx::AS3::Instances::fl::Array *pV; // rbx
  int v13; // edx
  int v14; // [rsp+20h] [rbp-28h] BYREF
  unsigned int v15; // [rsp+24h] [rbp-24h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> v16; // [rsp+28h] [rbp-20h] BYREF
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+60h] [rbp+18h] BYREF

  v4 = 0i64;
  v7 = 0;
  v14 = 0;
  if ( argc )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2Int32(argv, &resulta, &v14)->Result )
      return;
    v7 = v14;
    if ( v14 < 0 )
      v7 = LODWORD(this->SA.Length) + v14;
  }
  Length = this->SA.Length;
  if ( v7 < 0 )
    v7 = 0;
  p_SA = &this->SA;
  v15 = this->SA.Length;
  v14 = v7;
  if ( argc <= 1 )
  {
    v15 = Length - v7;
  }
  else if ( !Scaleform::GFx::AS3::Value::Convert2UInt32(argv + 1, &resulta, &v15)->Result )
  {
    return;
  }
  Scaleform::GFx::AS3::InstanceTraits::fl::Array::MakeInstance(
    &v16,
    (Scaleform::GFx::AS3::InstanceTraits::fl::Array *)this->pTraits.pObject);
  pV = v16.pV;
  Scaleform::GFx::AS3::Value::Pick(result, v16.pV);
  if ( pV )
    v4 = &pV->SA;
  Scaleform::GFx::AS3::Impl::SparseArray::CutMultipleAt(p_SA, v14, v15, v4);
  if ( argc > 2 )
  {
    v13 = v14;
    if ( (int)p_SA->Length < v14 )
      v13 = p_SA->Length;
    v14 = v13;
    Scaleform::GFx::AS3::Impl::SparseArray::Insert(p_SA, v13, argc - 2, argv + 2);
  }
}

// File Line: 1275
// RVA: 0x7A45B0
Scaleform::GFx::AS3::Instances::fl::Array::AS3sort

// File Line: 1471
// RVA: 0x7A56C0
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::AS3sortOn(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *result,
        Scaleform::GFx::AS3::Value *fieldName,
        Scaleform::GFx::AS3::Value *options)
{
  Scaleform::GFx::AS3::Value *v4; // r14
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *v6; // r13
  Scaleform::GFx::AS3::Instances::fl::Array *pV; // r12
  Scaleform::GFx::AS3::VM *pVM; // rax
  Scaleform::MemoryHeap *vfptr; // r15
  __int64 v10; // rbx
  Scaleform::GFx::AS3::Traits *ValueTraits; // rax
  Scaleform::GFx::AS3::Value::V1U v12; // r13
  unsigned __int64 v13; // r12
  Scaleform::GFx::AS3::Value *v14; // rax
  int v15; // edi
  Scaleform::GFx::ASStringNode *v16; // rsi
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *VObj; // r14
  Scaleform::GFx::AS3::Value *v18; // rdx
  int v19; // r15d
  Scaleform::GFx::ASStringNode *pNode; // rdi
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *Fields; // rsi
  Scaleform::GFx::AS3::Value *v22; // rdx
  unsigned __int64 Size; // rdi
  unsigned __int64 v24; // rsi
  unsigned __int64 v25; // r8
  unsigned __int64 v26; // rcx
  int v27; // ecx
  Scaleform::GFx::AS3::Traits *v28; // rax
  Scaleform::GFx::AS3::Value::V1U v29; // r14
  Scaleform::GFx::ASStringNode *pLower; // rax
  unsigned __int64 v31; // rdi
  Scaleform::GFx::AS3::Value *v32; // rax
  unsigned __int64 i; // rdx
  Scaleform::GFx::AS3::Value::V2U v34; // rax
  Scaleform::GFx::AS3::Impl::SparseArray *p_SA; // r15
  unsigned __int64 v36; // rsi
  unsigned int v37; // edi
  __int64 v38; // rax
  Scaleform::GFx::AS3::XMLParser::Kind v39; // r12d
  Scaleform::GFx::AS3::Value::Extra v40; // r14
  unsigned int v41; // edi
  __int64 v42; // r8
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> v43; // rcx
  unsigned int v44; // eax
  unsigned __int64 v45; // rsi
  Scaleform::GFx::AS3::Value *j; // rdi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  bool v48; // zf
  Scaleform::GFx::ASStringNode *VStr; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v50; // rcx
  unsigned int v51; // eax
  int v52; // r12d
  __int64 v53; // rdi
  Scaleform::GFx::AS3::Value::Extra v54; // rsi
  int v55; // ecx
  Scaleform::GFx::AS3::Value *v56; // rdx
  Scaleform::GFx::AS3::Value::V1U v57; // rax
  Scaleform::GFx::AS3::Value::Extra v58; // rsi
  unsigned __int64 Length; // rcx
  Scaleform::GFx::AS3::Value *v60; // rdi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> v61; // rcx
  Scaleform::GFx::AS3::Instances::fl::Array *v62; // rbx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *v64; // rcx
  Scaleform::GFx::AS3::CheckResult v65; // [rsp+20h] [rbp-E0h] BYREF
  Scaleform::GFx::AS3::Value v66; // [rsp+28h] [rbp-D8h] BYREF
  Scaleform::GFx::AS3::Impl::ArrayFunc f; // [rsp+48h] [rbp-B8h] BYREF
  Scaleform::GFx::AS3::Value *v68; // [rsp+50h] [rbp-B0h]
  void *v69; // [rsp+58h] [rbp-A8h]
  Scaleform::GFx::AS3::Value v70; // [rsp+60h] [rbp-A0h] BYREF
  void *p_ValueH; // [rsp+80h] [rbp-80h]
  Scaleform::ArrayDataBase<enum Scaleform::GFx::AS3::XMLParser::Kind,Scaleform::AllocatorDH_POD<enum Scaleform::GFx::AS3::XMLParser::Kind,2>,Scaleform::ArrayDefaultPolicy> v72; // [rsp+88h] [rbp-78h] BYREF
  void *v73; // [rsp+A0h] [rbp-60h]
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> v74; // [rsp+A8h] [rbp-58h] BYREF
  void *pheapAddr; // [rsp+C0h] [rbp-40h]
  Scaleform::GFx::ASString resulta; // [rsp+C8h] [rbp-38h] BYREF
  Scaleform::GFx::AS3::Impl::SparseArray v77; // [rsp+D0h] [rbp-30h] BYREF
  Scaleform::GFx::AS3::Impl::CompareOn v78; // [rsp+140h] [rbp+40h] BYREF
  AMD_HD3D *v79; // [rsp+158h] [rbp+58h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> v80; // [rsp+1B0h] [rbp+B0h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *v81; // [rsp+1B8h] [rbp+B8h]
  Scaleform::GFx::AS3::Value *v82; // [rsp+1C8h] [rbp+C8h]

  v82 = options;
  v81 = result;
  v80.pV = this;
  v79 = (AMD_HD3D *)-2i64;
  v4 = options;
  v6 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)result;
  pV = this;
  pVM = this->pTraits.pObject->pVM;
  f.vfptr = (Scaleform::GFx::AS3::Impl::ArrayFuncVtbl *)pVM->MHeap;
  vfptr = (Scaleform::MemoryHeap *)f.vfptr;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    pVM->StringManagerRef,
    &resulta);
  v10 = 0i64;
  memset(&v74, 0, sizeof(v74));
  pheapAddr = f.vfptr;
  v69 = &v72;
  memset(&v72, 0, sizeof(v72));
  v73 = f.vfptr;
  ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(pV->pTraits.pObject->pVM, fieldName);
  if ( ValueTraits->TraitsType != Traits_Array || (ValueTraits->Flags & 0x20) != 0 )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2String(fieldName, &v65, &resulta)->Result )
      goto LABEL_156;
    v19 = 10;
    v66.Flags = 10;
    v66.Bonus.pWeakProxy = 0i64;
    pNode = resulta.pNode;
    *(Scaleform::GFx::ASString *)&v66.value.VNumber = (Scaleform::GFx::ASString)resulta.pNode;
    if ( resulta.pNode == &resulta.pNode->pManager->NullStringNode )
    {
      pNode = 0i64;
      v66.value.VS._1.VStr = 0i64;
      Fields = v78.Fields;
      v66.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v78.Fields;
      v19 = 12;
      v66.Flags = 12;
    }
    else
    {
      ++resulta.pNode->RefCount;
      Fields = (Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *)v66.value.VS._2.VObj;
    }
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &v74,
      pheapAddr,
      v74.Size + 1);
    v22 = &v74.Data[v74.Size - 1];
    p_ValueH = v22;
    v69 = v22;
    if ( v22 )
    {
      v22->Flags = v19;
      v22->Bonus.pWeakProxy = 0i64;
      v22->value.VS._1.VStr = pNode;
      v22->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)Fields;
      if ( (v19 & 0x1Fu) > 9 )
      {
        if ( (v19 & 0x1F) == 10 )
        {
          ++pNode->RefCount;
        }
        else if ( (v19 & 0x1Fu) > 0xA )
        {
          if ( (v19 & 0x1Fu) <= 0xF )
          {
            if ( pNode )
              pNode->Size = (pNode->Size + 1) & 0x8FBFFFFF;
          }
          else if ( (v19 & 0x1Fu) <= 0x11 && Fields )
          {
            LODWORD(Fields[1].Data.Data) = (LODWORD(Fields[1].Data.Data) + 1) & 0x8FBFFFFF;
          }
        }
      }
    }
    if ( (v19 & 0x1Fu) > 9 )
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v66);
    vfptr = (Scaleform::MemoryHeap *)f.vfptr;
  }
  else
  {
    v12 = fieldName->value.VS._1;
    v13 = 0i64;
    if ( v12.VStr[1].pLower )
    {
      do
      {
        v14 = Scaleform::GFx::AS3::Impl::SparseArray::At((Scaleform::GFx::AS3::Impl::SparseArray *)&v12.VStr[1].16, v13);
        if ( !Scaleform::GFx::AS3::Value::Convert2String(v14, &v65, &resulta)->Result )
          goto LABEL_156;
        v15 = 10;
        v66.Flags = 10;
        v66.Bonus.pWeakProxy = 0i64;
        v16 = resulta.pNode;
        *(Scaleform::GFx::ASString *)&v66.value.VNumber = (Scaleform::GFx::ASString)resulta.pNode;
        if ( resulta.pNode == &resulta.pNode->pManager->NullStringNode )
        {
          v16 = 0i64;
          v66.value.VS._1.VStr = 0i64;
          VObj = v78.Fields;
          v66.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v78.Fields;
          v15 = 12;
          v66.Flags = 12;
        }
        else
        {
          ++resulta.pNode->RefCount;
          VObj = (Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *)v66.value.VS._2.VObj;
        }
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          &v74,
          pheapAddr,
          v74.Size + 1);
        v18 = &v74.Data[v74.Size - 1];
        v69 = v18;
        p_ValueH = v18;
        if ( v18 )
        {
          v18->Flags = v15;
          v18->Bonus.pWeakProxy = 0i64;
          v18->value.VS._1.VStr = v16;
          v18->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)VObj;
          if ( (v15 & 0x1Fu) > 9 )
          {
            if ( (v15 & 0x1F) == 10 )
            {
              ++v16->RefCount;
            }
            else if ( (v15 & 0x1Fu) > 0xA )
            {
              if ( (v15 & 0x1Fu) <= 0xF )
              {
                if ( v16 )
                  v16->Size = (v16->Size + 1) & 0x8FBFFFFF;
              }
              else if ( (v15 & 0x1Fu) <= 0x11 && VObj )
              {
                LODWORD(VObj[1].Data.Data) = (LODWORD(VObj[1].Data.Data) + 1) & 0x8FBFFFFF;
              }
            }
          }
        }
        if ( (v15 & 0x1Fu) > 9 )
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v66);
        ++v13;
      }
      while ( (Scaleform::GFx::ASStringNode *)v13 < v12.VStr[1].pLower );
      v4 = v82;
      vfptr = (Scaleform::MemoryHeap *)f.vfptr;
    }
    pV = v80.pV;
    v6 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)v81;
  }
  Size = v74.Size;
  v24 = v74.Size;
  if ( v74.Size >= v72.Size )
  {
    if ( v74.Size <= v72.Policy.Capacity )
      goto LABEL_49;
    v25 = v74.Size + (v74.Size >> 2);
  }
  else
  {
    if ( v74.Size >= v72.Policy.Capacity >> 1 )
      goto LABEL_49;
    v25 = v74.Size;
  }
  Scaleform::ArrayDataBase<unsigned long,Scaleform::AllocatorDH<unsigned long,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    &v72,
    v73,
    v25);
  Size = v74.Size;
LABEL_49:
  v72.Size = v24;
  v26 = 0i64;
  if ( v24 )
  {
    do
    {
      v72.Data[v26++] = kNone;
      v24 = v72.Size;
    }
    while ( v26 < v72.Size );
    Size = v74.Size;
  }
  v27 = v4->Flags & 0x1F;
  if ( v27 && ((unsigned int)(v27 - 12) > 3 && v27 != 10 || v4->value.VS._1.VStr) )
  {
    v28 = Scaleform::GFx::AS3::VM::GetValueTraits(pV->pTraits.pObject->pVM, v4);
    if ( v28->TraitsType != Traits_Array || (v28->Flags & 0x20) != 0 )
    {
      if ( !Scaleform::GFx::AS3::Value::Convert2UInt32(v4, &v65, (unsigned int *)&f)->Result )
        goto LABEL_156;
      for ( i = 0i64; i < v72.Size; ++i )
        v72.Data[i] = (Scaleform::GFx::AS3::XMLParser::Kind)f.vfptr;
    }
    else
    {
      v29 = v4->value.VS._1;
      pLower = v29.VStr[1].pLower;
      if ( pLower == (Scaleform::GFx::ASStringNode *)Size )
      {
        v31 = 0i64;
        if ( pLower )
        {
          while ( v31 < v24 )
          {
            v32 = Scaleform::GFx::AS3::Impl::SparseArray::At(
                    (Scaleform::GFx::AS3::Impl::SparseArray *)&v29.VStr[1].16,
                    v31);
            if ( !Scaleform::GFx::AS3::Value::Convert2UInt32(v32, &v65, (unsigned int *)&f)->Result )
              goto LABEL_156;
            v72.Data[v31++] = (Scaleform::GFx::AS3::XMLParser::Kind)f.vfptr;
            if ( (Scaleform::GFx::ASStringNode *)v31 >= v29.VStr[1].pLower )
              break;
            v24 = v72.Size;
          }
        }
      }
    }
  }
  memset(&v77, 0, 28);
  v77.DefaultValue.Bonus.pWeakProxy = 0i64;
  memset(&v77.ValueA, 0, 24);
  v77.ValueA.Data.pHeap = vfptr;
  p_ValueH = &v77.ValueH;
  v69 = &v77.ValueH;
  v77.ValueH.mHash.pTable = 0i64;
  v77.ValueH.mHash.pHeap = vfptr;
  v34.VObj = (Scaleform::GFx::AS3::Object *)pV->pTraits.pObject->pVM->MHeap;
  p_ValueH = &v66;
  memset(&v66, 0, 24);
  v66.value.VS._2 = v34;
  f.vfptr = (Scaleform::GFx::AS3::Impl::ArrayFuncVtbl *)&Scaleform::GFx::AS3::Impl::ValuePtrCollector::`vftable;
  v68 = &v66;
  p_SA = &pV->SA;
  v36 = pV->SA.ValueA.Data.Size;
  v37 = 0;
  if ( v36 )
  {
    v38 = 0i64;
    do
    {
      f.vfptr->operator()(&f, v37++, &pV->SA.ValueA.Data.Data[v38]);
      v38 = v37;
    }
    while ( v37 < v36 );
  }
  Scaleform::GFx::AS3::Impl::SparseArray::ForEachSparse(&pV->SA, &f);
  v78.Vm = pV->pTraits.pObject->pVM;
  v78.Fields = (Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *)&v74;
  v78.Flags = (Scaleform::ArrayDH<unsigned long,2,Scaleform::ArrayDefaultPolicy> *)&v72;
  *(_QWORD *)&v70.Flags = v78.Vm;
  v70.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)&v74;
  v70.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)&v72;
  Scaleform::Alg::QuickSortSlicedSafe<Scaleform::ArrayDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::AS3::Impl::CompareOn>(
    (Scaleform::ArrayDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2,Scaleform::ArrayDefaultPolicy> *)&v66,
    0i64,
    (signed __int64)v66.Bonus.pWeakProxy,
    (Scaleform::GFx::AS3::Impl::CompareOn *)&v70);
  v39 = *v72.Data;
  v40.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v66.Bonus;
  if ( (*v72.Data & 4) == 0 || (v41 = 1, v66.Bonus.pWeakProxy <= (Scaleform::GFx::AS3::WeakProxy *)1) )
  {
LABEL_105:
    v52 = v39 & 8;
    if ( v52 )
    {
      if ( v40.pWeakProxy )
      {
        v53 = 0i64;
        v54.pWeakProxy = v40.pWeakProxy;
        do
        {
          v55 = *(_DWORD *)(v53 + *(_QWORD *)&v66.Flags + 8);
          v70.Flags = 3;
          v70.Bonus.pWeakProxy = 0i64;
          v70.value.VS._1.VInt = v55;
          if ( v77.Length == v77.ValueA.Data.Size )
          {
            Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
              &v77.ValueA.Data,
              v77.ValueA.Data.pHeap,
              v77.ValueA.Data.Size + 1);
            v56 = &v77.ValueA.Data.Data[v77.ValueA.Data.Size - 1];
            p_ValueH = v56;
            v69 = v56;
            if ( v56 )
            {
              v56->Flags = v70.Flags;
              v56->Bonus.pWeakProxy = v70.Bonus.pWeakProxy;
              v56->value = v70.value;
              if ( (v70.Flags & 0x1F) > 9 )
              {
                if ( (v70.Flags & 0x200) != 0 )
                {
                  ++v70.Bonus.pWeakProxy->RefCount;
                }
                else if ( (v70.Flags & 0x1F) == 10 )
                {
                  ++v70.value.VS._1.VStr->RefCount;
                }
                else if ( (v70.Flags & 0x1F) > 0xA )
                {
                  if ( (v70.Flags & 0x1F) <= 0xF )
                  {
                    v57 = v70.value.VS._1;
LABEL_119:
                    if ( v57.VStr )
                    {
                      ++v57.VStr->Size;
                      v57.VStr->Size &= 0x8FBFFFFF;
                    }
                    goto LABEL_124;
                  }
                  if ( (v70.Flags & 0x1F) <= 0x11 )
                  {
                    v57 = (Scaleform::GFx::AS3::Value::V1U)v70.value.VS._2.VObj;
                    goto LABEL_119;
                  }
                }
              }
            }
          }
          else
          {
            v77.ValueHHighInd = v77.Length;
            v78.Vm = (Scaleform::GFx::AS3::VM *)&v77.ValueHHighInd;
            v78.Fields = (Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *)&v70;
            Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
              &v77.ValueH.mHash,
              v77.ValueH.mHash.pHeap,
              (Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef *)&v78);
          }
LABEL_124:
          ++v77.Length;
          if ( (v70.Flags & 0x1F) > 9 )
          {
            if ( (v70.Flags & 0x200) != 0 )
            {
              v48 = v70.Bonus.pWeakProxy->RefCount-- == 1;
              if ( v48 )
                ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
              memset(&v70.Bonus, 0, 24);
              v70.Flags &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&v70);
            }
          }
          v53 += 16i64;
          --v54.pWeakProxy;
        }
        while ( v54.pWeakProxy );
      }
    }
    else if ( v40.pWeakProxy )
    {
      v58.pWeakProxy = v40.pWeakProxy;
      Length = v77.Length;
      do
      {
        v60 = *(Scaleform::GFx::AS3::Value **)(v10 + *(_QWORD *)&v66.Flags);
        if ( Length == v77.ValueA.Data.Size )
        {
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
            &v77.ValueA.Data,
            v77.ValueA.Data.pHeap,
            v77.ValueA.Data.Size + 1);
          Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
            &v77.ValueA.Data.Data[v77.ValueA.Data.Size - 1],
            v60);
        }
        else
        {
          v77.ValueHHighInd = Length;
          v78.Vm = (Scaleform::GFx::AS3::VM *)&v77.ValueHHighInd;
          v78.Fields = (Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *)v60;
          Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
            &v77.ValueH.mHash,
            v77.ValueH.mHash.pHeap,
            (Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef *)&v78);
        }
        Length = ++v77.Length;
        v10 += 16i64;
        --v58.pWeakProxy;
      }
      while ( v58.pWeakProxy );
      goto LABEL_140;
    }
    Length = v77.Length;
LABEL_140:
    if ( v40.pWeakProxy < (Scaleform::GFx::AS3::WeakProxy *)p_SA->Length )
    {
      Scaleform::GFx::AS3::Impl::SparseArray::Resize(&v77, p_SA->Length);
      Length = v77.Length;
    }
    if ( v52 )
    {
      Scaleform::GFx::AS3::InstanceTraits::fl::Array::MakeInstance(
        &v80,
        (Scaleform::GFx::AS3::InstanceTraits::fl::Array *)v80.pV->pTraits.pObject->pVM->TraitsArray.pObject->ITraits.pObject);
      v61.pObject = v6->pObject;
      v62 = v80.pV;
      if ( v80.pV != (Scaleform::GFx::AS3::Instances::fl::Array *)v6->pObject )
      {
        if ( v61.pObject )
        {
          if ( ((__int64)v61.pObject & 1) != 0 )
          {
            v6->pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v61.pObject - 1);
          }
          else
          {
            RefCount = v61.pObject->RefCount;
            if ( (RefCount & 0x3FFFFF) != 0 )
            {
              v61.pObject->RefCount = RefCount - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v61.pObject);
            }
          }
        }
        v6->pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v62;
      }
      if ( &v62->SA != &v77 )
      {
        v62->SA.Length = v77.Length;
        v62->SA.ValueHLowInd = v77.ValueHLowInd;
        v62->SA.ValueHHighInd = v77.ValueHHighInd;
        Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Assign(
          &v62->SA.ValueH.mHash,
          v77.ValueH.mHash.pHeap,
          &v77.ValueH.mHash);
        v62->SA.ValueH.mHash.pHeap = v77.ValueH.mHash.pHeap;
        Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy>::operator=(
          &v62->SA.ValueA,
          &v77.ValueA);
      }
    }
    else
    {
      if ( p_SA != &v77 )
      {
        p_SA->Length = Length;
        p_SA->ValueHLowInd = v77.ValueHLowInd;
        p_SA->ValueHHighInd = v77.ValueHHighInd;
        Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Assign(
          &p_SA->ValueH.mHash,
          v77.ValueH.mHash.pHeap,
          &v77.ValueH.mHash);
        p_SA->ValueH.mHash.pHeap = v77.ValueH.mHash.pHeap;
        Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy>::operator=(
          &p_SA->ValueA,
          &v77.ValueA);
      }
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
        v6,
        (Scaleform::GFx::AS3::Instances::fl::XMLList *)v80.pV);
    }
    f.vfptr = (Scaleform::GFx::AS3::Impl::ArrayFuncVtbl *)&Scaleform::GFx::AS3::Impl::ArrayFunc::`vftable;
    v80.pV = (Scaleform::GFx::AS3::Instances::fl::Array *)&v66;
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, *(void **)&v66.Flags);
    Scaleform::GFx::AS3::Impl::SparseArray::~SparseArray(&v77);
    goto LABEL_156;
  }
  v42 = 1i64;
  while ( Scaleform::GFx::AS3::Impl::CompareOn::Compare(
            &v78,
            *(Scaleform::GFx::AS3::Value **)(*(_QWORD *)&v66.Flags + 16i64 * (v41 - 1)),
            *(Scaleform::GFx::AS3::Value **)(*(_QWORD *)&v66.Flags + 16 * v42)) != 0.0 )
  {
    v42 = ++v41;
    if ( (Scaleform::GFx::AS3::WeakProxy *)v41 >= v40.pWeakProxy )
      goto LABEL_105;
  }
  v43.pObject = v6->pObject;
  if ( v6->pObject )
  {
    if ( ((__int64)v43.pObject & 1) != 0 )
    {
      v6->pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v43.pObject - 1);
    }
    else
    {
      v44 = v43.pObject->RefCount;
      if ( (v44 & 0x3FFFFF) != 0 )
      {
        v43.pObject->RefCount = v44 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v43.pObject);
      }
    }
    v6->pObject = 0i64;
  }
  f.vfptr = (Scaleform::GFx::AS3::Impl::ArrayFuncVtbl *)&Scaleform::GFx::AS3::Impl::ArrayFunc::`vftable;
  v80.pV = (Scaleform::GFx::AS3::Instances::fl::Array *)&v66;
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, *(void **)&v66.Flags);
  v80.pV = (Scaleform::GFx::AS3::Instances::fl::Array *)&v77.ValueH;
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Clear(&v77.ValueH.mHash);
  v80.pV = (Scaleform::GFx::AS3::Instances::fl::Array *)&v77.ValueA;
  v45 = v77.ValueA.Data.Size;
  for ( j = &v77.ValueA.Data.Data[v77.ValueA.Data.Size - 1]; v45; --v45 )
  {
    if ( (j->Flags & 0x1F) > 9 )
    {
      if ( (j->Flags & 0x200) != 0 )
      {
        pWeakProxy = j->Bonus.pWeakProxy;
        v48 = pWeakProxy->RefCount-- == 1;
        if ( v48 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        j->Bonus.pWeakProxy = 0i64;
        j->value.VS._1.VStr = 0i64;
        j->value.VS._2.VObj = 0i64;
        j->Flags &= 0xFFFFFDE0;
      }
      else
      {
        switch ( j->Flags & 0x1F )
        {
          case 0xAu:
            VStr = j->value.VS._1.VStr;
            v48 = VStr->RefCount-- == 1;
            if ( v48 )
              Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
            break;
          case 0xBu:
          case 0xCu:
          case 0xDu:
          case 0xEu:
          case 0xFu:
            v50 = j->value.VS._1.VObj;
            if ( ((unsigned __int8)v50 & 1) == 0 )
              goto LABEL_95;
            j->value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)((char *)&v50[-1].RefCount + 7);
            break;
          case 0x10u:
          case 0x11u:
            v50 = j->value.VS._2.VObj;
            if ( ((unsigned __int8)v50 & 1) != 0 )
            {
              j->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)((char *)&v50[-1].RefCount + 7);
            }
            else
            {
LABEL_95:
              if ( v50 )
              {
                v51 = v50->RefCount;
                if ( (v51 & 0x3FFFFF) != 0 )
                {
                  v50->RefCount = v51 - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v50);
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
  ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( (v77.DefaultValue.Flags & 0x1F) > 9 )
  {
    if ( (v77.DefaultValue.Flags & 0x200) != 0 )
    {
      v48 = v77.DefaultValue.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v48 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v77.DefaultValue.Bonus, 0, 24);
      v77.DefaultValue.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v77.DefaultValue);
    }
  }
LABEL_156:
  v80.pV = (Scaleform::GFx::AS3::Instances::fl::Array *)&v72;
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v72.Data);
  v80.pV = (Scaleform::GFx::AS3::Instances::fl::Array *)&v74;
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(v74.Data, v74.Size);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v74.Data);
  v64 = resulta.pNode;
  v48 = resulta.pNode->RefCount-- == 1;
  if ( v48 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v64);
}

// File Line: 1614
// RVA: 0x79FA50
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::AS3indexOf(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        int *result,
        Scaleform::GFx::AS3::Value *searchElement,
        int fromIndex)
{
  unsigned __int64 Length; // rbp
  unsigned __int64 v8; // rbx
  unsigned __int64 Size; // r15
  __int64 v10; // rsi
  Scaleform::GFx::AS3::Value *p_DefaultValue; // rcx
  signed __int64 Index; // rax
  char *v13; // rcx
  unsigned __int64 key; // [rsp+50h] [rbp+8h] BYREF

  if ( fromIndex < 0 )
    fromIndex += LODWORD(this->SA.Length);
  Length = this->SA.Length;
  v8 = fromIndex;
  if ( fromIndex >= Length )
  {
LABEL_15:
    *result = -1;
  }
  else
  {
    Size = this->SA.ValueA.Data.Size;
    v10 = fromIndex;
    while ( 1 )
    {
      key = v8;
      if ( v8 >= Size )
      {
        if ( v8 < this->SA.ValueHLowInd
          || v8 > this->SA.ValueHHighInd
          || (Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::findIndexAlt<unsigned __int64>(
                        &this->SA.ValueH.mHash,
                        &key),
              Index < 0)
          || (v13 = (char *)&this->SA.ValueH.mHash.pTable[2] + 56 * Index) == 0i64
          || (p_DefaultValue = (Scaleform::GFx::AS3::Value *)(v13 + 8)) == 0i64 )
        {
          p_DefaultValue = &this->SA.DefaultValue;
        }
      }
      else
      {
        p_DefaultValue = &this->SA.ValueA.Data.Data[v10];
      }
      if ( Scaleform::GFx::AS3::StrictEqual(p_DefaultValue, searchElement) )
        break;
      ++v8;
      ++v10;
      if ( v8 >= Length )
        goto LABEL_15;
    }
    *result = v8;
  }
}

// File Line: 1632
// RVA: 0x79FD70
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::AS3lastIndexOf(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        int *result,
        Scaleform::GFx::AS3::Value *searchElement,
        int fromIndex)
{
  unsigned __int64 v7; // rbx
  unsigned __int64 Size; // rbp
  unsigned __int64 v9; // rsi
  Scaleform::GFx::AS3::Value *p_DefaultValue; // rcx
  signed __int64 Index; // rax
  char *v12; // rcx
  unsigned __int64 key; // [rsp+50h] [rbp+8h] BYREF

  if ( fromIndex < 0 )
    fromIndex += LODWORD(this->SA.Length);
  v7 = this->SA.Length - 1;
  if ( fromIndex < (__int64)v7 )
    v7 = fromIndex;
  if ( (v7 & 0x8000000000000000ui64) != 0i64 )
  {
LABEL_17:
    *result = -1;
  }
  else
  {
    Size = this->SA.ValueA.Data.Size;
    v9 = v7;
    while ( 1 )
    {
      key = v7;
      if ( v7 >= Size )
      {
        if ( v7 < this->SA.ValueHLowInd
          || v7 > this->SA.ValueHHighInd
          || (Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::findIndexAlt<unsigned __int64>(
                        &this->SA.ValueH.mHash,
                        &key),
              Index < 0)
          || (v12 = (char *)&this->SA.ValueH.mHash.pTable[2] + 56 * Index) == 0i64
          || (p_DefaultValue = (Scaleform::GFx::AS3::Value *)(v12 + 8)) == 0i64 )
        {
          p_DefaultValue = &this->SA.DefaultValue;
        }
      }
      else
      {
        p_DefaultValue = &this->SA.ValueA.Data.Data[v9];
      }
      if ( Scaleform::GFx::AS3::StrictEqual(p_DefaultValue, searchElement) )
        break;
      --v9;
      if ( (--v7 & 0x8000000000000000ui64) != 0i64 )
        goto LABEL_17;
    }
    *result = v7;
  }
}

// File Line: 1650
// RVA: 0x79D6E0
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::AS3every(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        bool *result,
        Scaleform::GFx::AS3::Value *callback,
        Scaleform::GFx::AS3::Value *thisObject)
{
  unsigned int v7; // ecx
  unsigned int v8; // ecx
  unsigned int Flags; // ecx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  Scaleform::GFx::AS3::Value::V1U VObj; // rcx
  unsigned __int64 v13; // rdi
  __int64 v14; // r14
  Scaleform::GFx::AS3::Value *p_DefaultValue; // rcx
  signed __int64 Index; // rax
  char *v17; // rcx
  Scaleform::GFx::AS3::Value::V1U v18; // rdx
  bool v19; // zf
  Scaleform::GFx::ASStringNode *v20; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v21; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Value _this; // [rsp+38h] [rbp-81h] BYREF
  Scaleform::GFx::AS3::Value argv; // [rsp+58h] [rbp-61h] BYREF
  Scaleform::GFx::AS3::Value::V2U v25; // [rsp+78h] [rbp-41h]
  Scaleform::GFx::AS3::Value ptr; // [rsp+80h] [rbp-39h] BYREF
  __int64 v27; // [rsp+A0h] [rbp-19h]
  __int64 v28; // [rsp+A8h] [rbp-11h]
  int v29; // [rsp+B0h] [rbp-9h]
  int v30; // [rsp+C0h] [rbp+7h]
  __int64 v31; // [rsp+C8h] [rbp+Fh]
  Scaleform::GFx::AS3::Instances::fl::Array *v32; // [rsp+D0h] [rbp+17h]
  __int64 v33; // [rsp+E0h] [rbp+27h]
  unsigned __int64 v34; // [rsp+128h] [rbp+6Fh] BYREF

  v33 = -2i64;
  v7 = callback->Flags & 0x1F;
  if ( !v7 || (v7 - 12 <= 3 || v7 == 10) && !callback->value.VS._1.VStr )
    goto LABEL_81;
  v8 = thisObject->Flags & 0x1F;
  if ( !v8 || (v8 - 12 <= 3 || v8 == 10) && !thisObject->value.VS._1.VStr )
    thisObject = callback;
  Flags = thisObject->Flags;
  LODWORD(argv.Bonus.pWeakProxy) = Flags;
  pWeakProxy = thisObject->Bonus.pWeakProxy;
  argv.value = *(Scaleform::GFx::AS3::Value::VU *)&thisObject->Bonus.pWeakProxy;
  v25.VObj = (Scaleform::GFx::AS3::Object *)thisObject->value.VS._2;
  if ( (Flags & 0x1F) <= 9 )
    goto LABEL_25;
  if ( (Flags & 0x200) != 0 )
  {
    ++pWeakProxy->RefCount;
  }
  else
  {
    if ( (Flags & 0x1F) == 10 )
    {
      ++thisObject->value.VS._1.VStr->RefCount;
      goto LABEL_25;
    }
    if ( (Flags & 0x1F) > 0xA )
    {
      if ( (Flags & 0x1F) <= 0xF )
      {
        VObj = thisObject->value.VS._1;
      }
      else
      {
        if ( (Flags & 0x1F) > 0x11 )
          goto LABEL_25;
        VObj = (Scaleform::GFx::AS3::Value::V1U)thisObject->value.VS._2.VObj;
      }
      if ( VObj.VStr )
        VObj.VStr->Size = (VObj.VStr->Size + 1) & 0x8FBFFFFF;
    }
  }
LABEL_25:
  v13 = 0i64;
  if ( !this->SA.Length )
    goto LABEL_66;
  v14 = 0i64;
  while ( 1 )
  {
    v34 = v13;
    if ( v13 >= this->SA.ValueA.Data.Size )
    {
      if ( v13 < this->SA.ValueHLowInd
        || v13 > this->SA.ValueHHighInd
        || (Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::findIndexAlt<unsigned __int64>(
                      &this->SA.ValueH.mHash,
                      &v34),
            Index < 0)
        || (v17 = (char *)&this->SA.ValueH.mHash.pTable[2] + 56 * Index) == 0i64
        || (p_DefaultValue = (Scaleform::GFx::AS3::Value *)(v17 + 8)) == 0i64 )
      {
        p_DefaultValue = &this->SA.DefaultValue;
      }
    }
    else
    {
      p_DefaultValue = &this->SA.ValueA.Data.Data[v14];
    }
    ptr.Flags = p_DefaultValue->Flags;
    ptr.Bonus.pWeakProxy = p_DefaultValue->Bonus.pWeakProxy;
    ptr.value = p_DefaultValue->value;
    if ( (p_DefaultValue->Flags & 0x1F) > 9 )
    {
      if ( (p_DefaultValue->Flags & 0x200) != 0 )
      {
        ++p_DefaultValue->Bonus.pWeakProxy->RefCount;
        goto LABEL_47;
      }
      if ( (p_DefaultValue->Flags & 0x1F) == 10 )
      {
        ++p_DefaultValue->value.VS._1.VStr->RefCount;
      }
      else
      {
        if ( (p_DefaultValue->Flags & 0x1F) <= 0xA )
          goto LABEL_47;
        if ( (p_DefaultValue->Flags & 0x1F) <= 0xF )
        {
          v18 = p_DefaultValue->value.VS._1;
        }
        else
        {
          if ( (p_DefaultValue->Flags & 0x1F) > 0x11 )
            goto LABEL_47;
          v18 = (Scaleform::GFx::AS3::Value::V1U)p_DefaultValue->value.VS._2.VObj;
        }
        if ( v18.VStr )
          v18.VStr->Size = (v18.VStr->Size + 1) & 0x8FBFFFFF;
      }
    }
LABEL_47:
    LODWORD(v27) = 3;
    v28 = 0i64;
    v29 = v13;
    v30 = 12;
    v31 = 0i64;
    v32 = this;
    this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
    if ( !Scaleform::GFx::AS3::Value::IsCallable(callback) )
      goto LABEL_65;
    LODWORD(_this.Bonus.pWeakProxy) = 0;
    _this.value.VS._1.VStr = 0i64;
    Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(
      this->pTraits.pObject->pVM,
      callback,
      (Scaleform::GFx::AS3::Value *)&argv.Bonus,
      (Scaleform::GFx::AS3::Value *)&_this.Bonus,
      3u,
      &ptr,
      0);
    if ( this->pTraits.pObject->pVM->HandleException
      || ((__int64)_this.Bonus.pWeakProxy & 0x1F) != 1
      || !LOBYTE(_this.value.VS._2.VObj) )
    {
      break;
    }
    if ( (unsigned __int64)((__int64)_this.Bonus.pWeakProxy & 0x1F) > 9 )
    {
      if ( ((__int64)_this.Bonus.pWeakProxy & 0x200) != 0 )
      {
        v19 = LODWORD(_this.value.VS._1.VStr->pData)-- == 1;
        if ( v19 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        _this.value = 0ui64;
        *(_QWORD *)&argv.Flags = 0i64;
        LODWORD(_this.Bonus.pWeakProxy) &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&_this.Bonus);
      }
    }
    `eh vector destructor iterator(&ptr, 0x20ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
    ++v13;
    ++v14;
    if ( v13 >= this->SA.Length )
      goto LABEL_66;
  }
  if ( (unsigned __int64)((__int64)_this.Bonus.pWeakProxy & 0x1F) > 9 )
  {
    if ( ((__int64)_this.Bonus.pWeakProxy & 0x200) != 0 )
    {
      v19 = LODWORD(_this.value.VS._1.VStr->pData)-- == 1;
      if ( v19 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      LODWORD(_this.Bonus.pWeakProxy) &= 0xFFFFFDE0;
      *(_QWORD *)&argv.Flags = 0i64;
      _this.value = 0ui64;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&_this.Bonus);
    }
  }
LABEL_65:
  `eh vector destructor iterator(&ptr, 0x20ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
LABEL_66:
  if ( (unsigned __int64)((__int64)argv.Bonus.pWeakProxy & 0x1F) > 9 )
  {
    if ( ((__int64)argv.Bonus.pWeakProxy & 0x200) != 0 )
    {
      v19 = LODWORD(argv.value.VS._1.VStr->pData)-- == 1;
      if ( v19 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      argv.value = 0ui64;
      v25.VObj = 0i64;
      LODWORD(argv.Bonus.pWeakProxy) &= 0xFFFFFDE0;
    }
    else
    {
      switch ( (__int64)argv.Bonus.pWeakProxy & 0x1F )
      {
        case 0xAi64:
          v20 = (Scaleform::GFx::ASStringNode *)argv.value.VS._2.VObj;
          v19 = LODWORD(argv.value.VS._2.VObj->pPrev)-- == 1;
          if ( v19 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v20);
          break;
        case 0xBi64:
        case 0xCi64:
        case 0xDi64:
        case 0xEi64:
        case 0xFi64:
          v21 = argv.value.VS._2.VObj;
          if ( ((__int64)argv.value.VS._2.VObj & 1) == 0 )
            goto LABEL_78;
          --argv.value.VS._2.VObj;
          break;
        case 0x10i64:
        case 0x11i64:
          v21 = v25.VObj;
          if ( ((__int64)v25.VObj & 1) != 0 )
          {
            --v25.VObj;
          }
          else
          {
LABEL_78:
            if ( v21 )
            {
              RefCount = v21->RefCount;
              if ( (RefCount & 0x3FFFFF) != 0 )
              {
                v21->RefCount = RefCount - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v21);
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
  *result = 0;
}

// File Line: 1678
// RVA: 0x79DBE0
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::AS3filter(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *result,
        Scaleform::GFx::AS3::Value *callback,
        Scaleform::GFx::AS3::Value *thisObject)
{
  Scaleform::GFx::AS3::Instances::fl::Array *pObject; // rcx
  Scaleform::GFx::AS3::Instances::fl::Array *pV; // rbx
  unsigned int RefCount; // eax
  unsigned int v11; // ecx
  unsigned int v12; // ecx
  unsigned int Flags; // ecx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  Scaleform::GFx::AS3::Value::V1U VObj; // rcx
  Scaleform::GFx::AS3::Instances::fl::Array *v17; // r14
  __int64 v18; // r15
  Scaleform::GFx::AS3::Value *p_DefaultValue; // rcx
  signed __int64 Index; // rax
  char *v21; // rcx
  Scaleform::GFx::AS3::Value::V1U v22; // rdx
  Scaleform::GFx::AS3::Value *v23; // rax
  bool v24; // zf
  Scaleform::GFx::ASStringNode *v25; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v26; // rcx
  unsigned int v27; // eax
  Scaleform::GFx::AS3::Value _this; // [rsp+38h] [rbp-81h] BYREF
  Scaleform::GFx::AS3::Value argv; // [rsp+58h] [rbp-61h] BYREF
  Scaleform::GFx::AS3::Value::V2U v30; // [rsp+78h] [rbp-41h]
  Scaleform::GFx::AS3::Value ptr; // [rsp+80h] [rbp-39h] BYREF
  __int64 v32; // [rsp+A0h] [rbp-19h]
  __int64 v33; // [rsp+A8h] [rbp-11h]
  int v34; // [rsp+B0h] [rbp-9h]
  int v35; // [rsp+C0h] [rbp+7h]
  __int64 v36; // [rsp+C8h] [rbp+Fh]
  Scaleform::GFx::AS3::Instances::fl::Array *v37; // [rsp+D0h] [rbp+17h]
  __int64 v38; // [rsp+E0h] [rbp+27h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> v39; // [rsp+120h] [rbp+67h] BYREF

  v38 = -2i64;
  Scaleform::GFx::AS3::InstanceTraits::fl::Array::MakeInstance(
    &v39,
    (Scaleform::GFx::AS3::InstanceTraits::fl::Array *)this->pTraits.pObject);
  pObject = result->pObject;
  pV = v39.pV;
  if ( v39.pV != result->pObject )
  {
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)pObject - 1);
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
    result->pObject = pV;
  }
  v11 = callback->Flags & 0x1F;
  if ( !v11 || (v11 - 12 <= 3 || v11 == 10) && !callback->value.VS._1.VStr )
    return;
  v12 = thisObject->Flags & 0x1F;
  if ( !v12 || (v12 - 12 <= 3 || v12 == 10) && !thisObject->value.VS._1.VStr )
    thisObject = callback;
  Flags = thisObject->Flags;
  LODWORD(argv.Bonus.pWeakProxy) = Flags;
  pWeakProxy = thisObject->Bonus.pWeakProxy;
  argv.value = *(Scaleform::GFx::AS3::Value::VU *)&thisObject->Bonus.pWeakProxy;
  v30.VObj = (Scaleform::GFx::AS3::Object *)thisObject->value.VS._2;
  if ( (Flags & 0x1F) <= 9 )
    goto LABEL_32;
  if ( (Flags & 0x200) != 0 )
  {
    ++pWeakProxy->RefCount;
  }
  else
  {
    if ( (Flags & 0x1F) == 10 )
    {
      ++thisObject->value.VS._1.VStr->RefCount;
      goto LABEL_32;
    }
    if ( (Flags & 0x1F) > 0xA )
    {
      if ( (Flags & 0x1F) <= 0xF )
      {
        VObj = thisObject->value.VS._1;
      }
      else
      {
        if ( (Flags & 0x1F) > 0x11 )
          goto LABEL_32;
        VObj = (Scaleform::GFx::AS3::Value::V1U)thisObject->value.VS._2.VObj;
      }
      if ( VObj.VStr )
        VObj.VStr->Size = (VObj.VStr->Size + 1) & 0x8FBFFFFF;
    }
  }
LABEL_32:
  v17 = 0i64;
  if ( !this->SA.Length )
    goto LABEL_74;
  v18 = 0i64;
  while ( 1 )
  {
    v39.pV = v17;
    if ( (unsigned __int64)v17 >= this->SA.ValueA.Data.Size )
    {
      if ( (unsigned __int64)v17 < this->SA.ValueHLowInd
        || (unsigned __int64)v17 > this->SA.ValueHHighInd
        || (Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::findIndexAlt<unsigned __int64>(
                      &this->SA.ValueH.mHash,
                      (const unsigned __int64 *)&v39),
            Index < 0)
        || (v21 = (char *)&this->SA.ValueH.mHash.pTable[2] + 56 * Index) == 0i64
        || (p_DefaultValue = (Scaleform::GFx::AS3::Value *)(v21 + 8)) == 0i64 )
      {
        p_DefaultValue = &this->SA.DefaultValue;
      }
    }
    else
    {
      p_DefaultValue = &this->SA.ValueA.Data.Data[v18];
    }
    ptr.Flags = p_DefaultValue->Flags;
    ptr.Bonus.pWeakProxy = p_DefaultValue->Bonus.pWeakProxy;
    ptr.value = p_DefaultValue->value;
    if ( (p_DefaultValue->Flags & 0x1F) > 9 )
    {
      if ( (p_DefaultValue->Flags & 0x200) != 0 )
      {
        ++p_DefaultValue->Bonus.pWeakProxy->RefCount;
        goto LABEL_54;
      }
      if ( (p_DefaultValue->Flags & 0x1F) == 10 )
      {
        ++p_DefaultValue->value.VS._1.VStr->RefCount;
      }
      else
      {
        if ( (p_DefaultValue->Flags & 0x1F) <= 0xA )
          goto LABEL_54;
        if ( (p_DefaultValue->Flags & 0x1F) <= 0xF )
        {
          v22 = p_DefaultValue->value.VS._1;
        }
        else
        {
          if ( (p_DefaultValue->Flags & 0x1F) > 0x11 )
            goto LABEL_54;
          v22 = (Scaleform::GFx::AS3::Value::V1U)p_DefaultValue->value.VS._2.VObj;
        }
        if ( v22.VStr )
          v22.VStr->Size = (v22.VStr->Size + 1) & 0x8FBFFFFF;
      }
    }
LABEL_54:
    LODWORD(v32) = 3;
    v33 = 0i64;
    v34 = (int)v17;
    v35 = 12;
    v36 = 0i64;
    v37 = this;
    this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
    if ( !Scaleform::GFx::AS3::Value::IsCallable(callback) )
      goto LABEL_73;
    LODWORD(_this.Bonus.pWeakProxy) = 0;
    _this.value.VS._1.VStr = 0i64;
    Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(
      this->pTraits.pObject->pVM,
      callback,
      (Scaleform::GFx::AS3::Value *)&argv.Bonus,
      (Scaleform::GFx::AS3::Value *)&_this.Bonus,
      3u,
      &ptr,
      0);
    if ( this->pTraits.pObject->pVM->HandleException )
      break;
    if ( ((__int64)_this.Bonus.pWeakProxy & 0x1F) == 1 && LOBYTE(_this.value.VS._2.VObj) )
    {
      v23 = Scaleform::GFx::AS3::Impl::SparseArray::At(&this->SA, (unsigned __int64)v17);
      Scaleform::GFx::AS3::Impl::SparseArray::PushBack(&pV->SA, v23);
    }
    if ( (unsigned __int64)((__int64)_this.Bonus.pWeakProxy & 0x1F) > 9 )
    {
      if ( ((__int64)_this.Bonus.pWeakProxy & 0x200) != 0 )
      {
        v24 = LODWORD(_this.value.VS._1.VStr->pData)-- == 1;
        if ( v24 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        _this.value = 0ui64;
        *(_QWORD *)&argv.Flags = 0i64;
        LODWORD(_this.Bonus.pWeakProxy) &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&_this.Bonus);
      }
    }
    `eh vector destructor iterator(&ptr, 0x20ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
    v17 = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)v17 + 1);
    ++v18;
    if ( (unsigned __int64)v17 >= this->SA.Length )
      goto LABEL_74;
  }
  if ( (unsigned __int64)((__int64)_this.Bonus.pWeakProxy & 0x1F) > 9 )
  {
    if ( ((__int64)_this.Bonus.pWeakProxy & 0x200) != 0 )
    {
      v24 = LODWORD(_this.value.VS._1.VStr->pData)-- == 1;
      if ( v24 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      _this.value = 0ui64;
      *(_QWORD *)&argv.Flags = 0i64;
      LODWORD(_this.Bonus.pWeakProxy) &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&_this.Bonus);
    }
  }
LABEL_73:
  `eh vector destructor iterator(&ptr, 0x20ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
LABEL_74:
  if ( (unsigned __int64)((__int64)argv.Bonus.pWeakProxy & 0x1F) > 9 )
  {
    if ( ((__int64)argv.Bonus.pWeakProxy & 0x200) != 0 )
    {
      v24 = LODWORD(argv.value.VS._1.VStr->pData)-- == 1;
      if ( v24 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      argv.value = 0ui64;
      v30.VObj = 0i64;
      LODWORD(argv.Bonus.pWeakProxy) &= 0xFFFFFDE0;
    }
    else
    {
      switch ( (__int64)argv.Bonus.pWeakProxy & 0x1F )
      {
        case 0xAi64:
          v25 = (Scaleform::GFx::ASStringNode *)argv.value.VS._2.VObj;
          v24 = LODWORD(argv.value.VS._2.VObj->pPrev)-- == 1;
          if ( v24 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v25);
          break;
        case 0xBi64:
        case 0xCi64:
        case 0xDi64:
        case 0xEi64:
        case 0xFi64:
          v26 = argv.value.VS._2.VObj;
          if ( ((__int64)argv.value.VS._2.VObj & 1) == 0 )
            goto LABEL_86;
          --argv.value.VS._2.VObj;
          break;
        case 0x10i64:
        case 0x11i64:
          v26 = v30.VObj;
          if ( ((__int64)v30.VObj & 1) != 0 )
          {
            --v30.VObj;
          }
          else
          {
LABEL_86:
            if ( v26 )
            {
              v27 = v26->RefCount;
              if ( (v27 & 0x3FFFFF) != 0 )
              {
                v26->RefCount = v27 - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v26);
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
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::AS3forEach(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Value *callback,
        Scaleform::GFx::AS3::Value *thisObject)
{
  unsigned int v6; // ecx
  unsigned int v7; // ecx
  unsigned int Flags; // ecx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  Scaleform::GFx::AS3::Value::V1U VObj; // rcx
  unsigned __int64 v12; // rdi
  __int64 v13; // r14
  Scaleform::GFx::AS3::Value *p_DefaultValue; // rcx
  signed __int64 Index; // rax
  char *v16; // rcx
  Scaleform::GFx::AS3::Value::V1U v17; // rdx
  bool v18; // zf
  Scaleform::GFx::ASStringNode *VStr; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v20; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Value _this; // [rsp+18h] [rbp-79h] BYREF
  Scaleform::GFx::AS3::Value resulta; // [rsp+38h] [rbp-59h] BYREF
  Scaleform::GFx::AS3::Value argv; // [rsp+58h] [rbp-39h] BYREF
  int v25; // [rsp+78h] [rbp-19h]
  __int64 v26; // [rsp+80h] [rbp-11h]
  int v27; // [rsp+88h] [rbp-9h]
  int v28; // [rsp+98h] [rbp+7h]
  __int64 v29; // [rsp+A0h] [rbp+Fh]
  Scaleform::GFx::AS3::Instances::fl::Array *v30; // [rsp+A8h] [rbp+17h]
  __int64 v31; // [rsp+B8h] [rbp+27h]
  unsigned __int64 key; // [rsp+108h] [rbp+77h] BYREF

  v31 = -2i64;
  v6 = callback->Flags & 0x1F;
  if ( !v6 || (v6 - 12 <= 3 || v6 == 10) && !callback->value.VS._1.VStr )
    return;
  v7 = thisObject->Flags & 0x1F;
  if ( !v7 || (v7 - 12 <= 3 || v7 == 10) && !thisObject->value.VS._1.VStr )
    thisObject = callback;
  Flags = thisObject->Flags;
  _this.Flags = Flags;
  pWeakProxy = thisObject->Bonus.pWeakProxy;
  _this.Bonus.pWeakProxy = pWeakProxy;
  _this.value = thisObject->value;
  if ( (Flags & 0x1F) <= 9 )
    goto LABEL_25;
  if ( (Flags & 0x200) != 0 )
  {
    ++pWeakProxy->RefCount;
  }
  else
  {
    if ( (Flags & 0x1F) == 10 )
    {
      ++thisObject->value.VS._1.VStr->RefCount;
      goto LABEL_25;
    }
    if ( (Flags & 0x1F) > 0xA )
    {
      if ( (Flags & 0x1F) <= 0xF )
      {
        VObj = thisObject->value.VS._1;
      }
      else
      {
        if ( (Flags & 0x1F) > 0x11 )
          goto LABEL_25;
        VObj = (Scaleform::GFx::AS3::Value::V1U)thisObject->value.VS._2.VObj;
      }
      if ( VObj.VStr )
        VObj.VStr->Size = (VObj.VStr->Size + 1) & 0x8FBFFFFF;
    }
  }
LABEL_25:
  v12 = 0i64;
  if ( !this->SA.Length )
    goto LABEL_64;
  v13 = 0i64;
  while ( 1 )
  {
    key = v12;
    if ( v12 >= this->SA.ValueA.Data.Size )
    {
      if ( v12 < this->SA.ValueHLowInd
        || v12 > this->SA.ValueHHighInd
        || (Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::findIndexAlt<unsigned __int64>(
                      &this->SA.ValueH.mHash,
                      &key),
            Index < 0)
        || (v16 = (char *)&this->SA.ValueH.mHash.pTable[2] + 56 * Index) == 0i64
        || (p_DefaultValue = (Scaleform::GFx::AS3::Value *)(v16 + 8)) == 0i64 )
      {
        p_DefaultValue = &this->SA.DefaultValue;
      }
    }
    else
    {
      p_DefaultValue = &this->SA.ValueA.Data.Data[v13];
    }
    argv.Flags = p_DefaultValue->Flags;
    argv.Bonus.pWeakProxy = p_DefaultValue->Bonus.pWeakProxy;
    argv.value = p_DefaultValue->value;
    if ( (p_DefaultValue->Flags & 0x1F) > 9 )
    {
      if ( (p_DefaultValue->Flags & 0x200) != 0 )
      {
        ++p_DefaultValue->Bonus.pWeakProxy->RefCount;
        goto LABEL_47;
      }
      if ( (p_DefaultValue->Flags & 0x1F) == 10 )
      {
        ++p_DefaultValue->value.VS._1.VStr->RefCount;
      }
      else
      {
        if ( (p_DefaultValue->Flags & 0x1F) <= 0xA )
          goto LABEL_47;
        if ( (p_DefaultValue->Flags & 0x1F) <= 0xF )
        {
          v17 = p_DefaultValue->value.VS._1;
        }
        else
        {
          if ( (p_DefaultValue->Flags & 0x1F) > 0x11 )
            goto LABEL_47;
          v17 = (Scaleform::GFx::AS3::Value::V1U)p_DefaultValue->value.VS._2.VObj;
        }
        if ( v17.VStr )
          v17.VStr->Size = (v17.VStr->Size + 1) & 0x8FBFFFFF;
      }
    }
LABEL_47:
    v25 = 3;
    v26 = 0i64;
    v27 = v12;
    v28 = 12;
    v29 = 0i64;
    v30 = this;
    this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
    if ( !Scaleform::GFx::AS3::Value::IsCallable(callback) )
      goto LABEL_63;
    resulta.Flags = 0;
    resulta.Bonus.pWeakProxy = 0i64;
    Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(this->pTraits.pObject->pVM, callback, &_this, &resulta, 3u, &argv, 0);
    if ( this->pTraits.pObject->pVM->HandleException )
      break;
    if ( (resulta.Flags & 0x1F) > 9 )
    {
      if ( (resulta.Flags & 0x200) != 0 )
      {
        v18 = resulta.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v18 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&resulta.Bonus, 0, 24);
        resulta.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&resulta);
      }
    }
    `eh vector destructor iterator(&argv, 0x20ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
    ++v12;
    ++v13;
    if ( v12 >= this->SA.Length )
      goto LABEL_64;
  }
  if ( (resulta.Flags & 0x1F) > 9 )
  {
    if ( (resulta.Flags & 0x200) != 0 )
    {
      v18 = resulta.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v18 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&resulta.Bonus, 0, 24);
      resulta.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&resulta);
    }
  }
LABEL_63:
  `eh vector destructor iterator(&argv, 0x20ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
LABEL_64:
  if ( (_this.Flags & 0x1F) > 9 )
  {
    if ( (_this.Flags & 0x200) != 0 )
    {
      v18 = _this.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v18 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&_this.Bonus, 0, 24);
      _this.Flags &= 0xFFFFFDE0;
    }
    else
    {
      switch ( _this.Flags & 0x1F )
      {
        case 0xA:
          VStr = _this.value.VS._1.VStr;
          v18 = _this.value.VS._1.VStr->RefCount-- == 1;
          if ( v18 )
            Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
          break;
        case 0xB:
        case 0xC:
        case 0xD:
        case 0xE:
        case 0xF:
          v20 = _this.value.VS._1.VObj;
          if ( !_this.value.VS._1.VBool )
            goto LABEL_76;
          --_this.value.VS._1.VStr;
          break;
        case 0x10:
        case 0x11:
          v20 = _this.value.VS._2.VObj;
          if ( ((__int64)_this.value.VS._2.VObj & 1) != 0 )
          {
            --_this.value.VS._2.VObj;
          }
          else
          {
LABEL_76:
            if ( v20 )
            {
              RefCount = v20->RefCount;
              if ( (RefCount & 0x3FFFFF) != 0 )
              {
                v20->RefCount = RefCount - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v20);
              }
            }
          }
          break;
        default:
          return;
      }
    }
  }
}        v20->RefCount = RefCount - 1;
                Scaleform::G

// File Line: 1735
// RVA: 0x7A0290
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::AS3map(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *result,
        Scaleform::GFx::AS3::Value *callback,
        Scaleform::GFx::AS3::Value *thisObject)
{
  Scaleform::GFx::AS3::Instances::fl::Array *pObject; // rcx
  Scaleform::GFx::AS3::Instances::fl::Array *pV; // rbx
  unsigned int RefCount; // eax
  unsigned int v11; // ecx
  unsigned int v12; // ecx
  unsigned int Flags; // ecx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  Scaleform::GFx::AS3::Value::V1U VObj; // rcx
  Scaleform::GFx::AS3::Instances::fl::Array *v17; // r14
  __int64 v18; // r15
  Scaleform::GFx::AS3::Value *p_DefaultValue; // rcx
  signed __int64 Index; // rax
  char *v21; // rcx
  Scaleform::GFx::AS3::Value::V1U v22; // rdx
  unsigned __int64 Length; // rcx
  __int64 v24; // rcx
  __int64 v25; // rdx
  bool v26; // zf
  __int64 v27; // rdx
  Scaleform::GFx::AS3::Value::V1U v28; // rax
  Scaleform::GFx::ASStringNode *VStr; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v30; // rcx
  unsigned int v31; // eax
  Scaleform::GFx::AS3::Value v32; // [rsp+40h] [rbp-99h] BYREF
  Scaleform::GFx::AS3::Value _this; // [rsp+60h] [rbp-79h] BYREF
  Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef key; // [rsp+80h] [rbp-59h] BYREF
  Scaleform::GFx::AS3::Value ptr; // [rsp+90h] [rbp-49h] BYREF
  int v36; // [rsp+B0h] [rbp-29h]
  __int64 v37; // [rsp+B8h] [rbp-21h]
  int v38; // [rsp+C0h] [rbp-19h]
  int v39; // [rsp+D0h] [rbp-9h]
  __int64 v40; // [rsp+D8h] [rbp-1h]
  Scaleform::GFx::AS3::Instances::fl::Array *v41; // [rsp+E0h] [rbp+7h]
  __int64 v42; // [rsp+F0h] [rbp+17h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> resulta; // [rsp+140h] [rbp+67h] BYREF
  __int64 v44; // [rsp+148h] [rbp+6Fh]

  v42 = -2i64;
  Scaleform::GFx::AS3::InstanceTraits::fl::Array::MakeInstance(
    &resulta,
    (Scaleform::GFx::AS3::InstanceTraits::fl::Array *)this->pTraits.pObject);
  pObject = result->pObject;
  pV = resulta.pV;
  if ( resulta.pV != result->pObject )
  {
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)pObject - 1);
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
    result->pObject = pV;
  }
  v11 = callback->Flags & 0x1F;
  if ( !v11 || (v11 - 12 <= 3 || v11 == 10) && !callback->value.VS._1.VStr )
    return;
  v12 = thisObject->Flags & 0x1F;
  if ( !v12 || (v12 - 12 <= 3 || v12 == 10) && !thisObject->value.VS._1.VStr )
    thisObject = callback;
  Flags = thisObject->Flags;
  _this.Flags = Flags;
  pWeakProxy = thisObject->Bonus.pWeakProxy;
  _this.Bonus.pWeakProxy = pWeakProxy;
  _this.value = thisObject->value;
  if ( (Flags & 0x1F) <= 9 )
    goto LABEL_32;
  if ( (Flags & 0x200) != 0 )
  {
    ++pWeakProxy->RefCount;
  }
  else
  {
    if ( (Flags & 0x1F) == 10 )
    {
      ++thisObject->value.VS._1.VStr->RefCount;
      goto LABEL_32;
    }
    if ( (Flags & 0x1F) > 0xA )
    {
      if ( (Flags & 0x1F) <= 0xF )
      {
        VObj = thisObject->value.VS._1;
      }
      else
      {
        if ( (Flags & 0x1F) > 0x11 )
          goto LABEL_32;
        VObj = (Scaleform::GFx::AS3::Value::V1U)thisObject->value.VS._2.VObj;
      }
      if ( VObj.VStr )
        VObj.VStr->Size = (VObj.VStr->Size + 1) & 0x8FBFFFFF;
    }
  }
LABEL_32:
  v17 = 0i64;
  if ( !this->SA.Length )
    goto LABEL_87;
  v18 = 0i64;
  while ( 1 )
  {
    resulta.pV = v17;
    if ( (unsigned __int64)v17 >= this->SA.ValueA.Data.Size )
    {
      if ( (unsigned __int64)v17 < this->SA.ValueHLowInd
        || (unsigned __int64)v17 > this->SA.ValueHHighInd
        || (Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::findIndexAlt<unsigned __int64>(
                      &this->SA.ValueH.mHash,
                      (const unsigned __int64 *)&resulta),
            Index < 0)
        || (v21 = (char *)&this->SA.ValueH.mHash.pTable[2] + 56 * Index) == 0i64
        || (p_DefaultValue = (Scaleform::GFx::AS3::Value *)(v21 + 8)) == 0i64 )
      {
        p_DefaultValue = &this->SA.DefaultValue;
      }
    }
    else
    {
      p_DefaultValue = &this->SA.ValueA.Data.Data[v18];
    }
    ptr.Flags = p_DefaultValue->Flags;
    ptr.Bonus.pWeakProxy = p_DefaultValue->Bonus.pWeakProxy;
    ptr.value = p_DefaultValue->value;
    if ( (p_DefaultValue->Flags & 0x1F) > 9 )
    {
      if ( (p_DefaultValue->Flags & 0x200) != 0 )
      {
        ++p_DefaultValue->Bonus.pWeakProxy->RefCount;
        goto LABEL_54;
      }
      if ( (p_DefaultValue->Flags & 0x1F) == 10 )
      {
        ++p_DefaultValue->value.VS._1.VStr->RefCount;
      }
      else
      {
        if ( (p_DefaultValue->Flags & 0x1F) <= 0xA )
          goto LABEL_54;
        if ( (p_DefaultValue->Flags & 0x1F) <= 0xF )
        {
          v22 = p_DefaultValue->value.VS._1;
        }
        else
        {
          if ( (p_DefaultValue->Flags & 0x1F) > 0x11 )
            goto LABEL_54;
          v22 = (Scaleform::GFx::AS3::Value::V1U)p_DefaultValue->value.VS._2.VObj;
        }
        if ( v22.VStr )
          v22.VStr->Size = (v22.VStr->Size + 1) & 0x8FBFFFFF;
      }
    }
LABEL_54:
    v36 = 3;
    v37 = 0i64;
    v38 = (int)v17;
    v39 = 12;
    v40 = 0i64;
    v41 = this;
    this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
    if ( !Scaleform::GFx::AS3::Value::IsCallable(callback) )
      goto LABEL_86;
    v32.Flags = 0;
    v32.Bonus.pWeakProxy = 0i64;
    Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(this->pTraits.pObject->pVM, callback, &_this, &v32, 3u, &ptr, 0);
    if ( this->pTraits.pObject->pVM->HandleException )
      break;
    Length = pV->SA.Length;
    if ( Length == pV->SA.ValueA.Data.Size )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        &pV->SA.ValueA.Data,
        pV->SA.ValueA.Data.pHeap,
        pV->SA.ValueA.Data.Size + 1);
      v24 = 32 * pV->SA.ValueA.Data.Size;
      v25 = (__int64)&pV->SA.ValueA.Data.Data[-1];
      v26 = v24 + v25 == 0;
      v27 = v24 + v25;
      resulta.pV = (Scaleform::GFx::AS3::Instances::fl::Array *)v27;
      v44 = v27;
      if ( v26 )
        goto LABEL_72;
      *(_DWORD *)v27 = v32.Flags;
      *(_QWORD *)(v27 + 8) = v32.Bonus.pWeakProxy;
      *(Scaleform::GFx::AS3::Value::VU *)(v27 + 16) = v32.value;
      if ( (v32.Flags & 0x1F) <= 9 )
        goto LABEL_72;
      if ( (v32.Flags & 0x200) != 0 )
      {
        ++v32.Bonus.pWeakProxy->RefCount;
      }
      else
      {
        if ( (v32.Flags & 0x1F) == 10 )
        {
          ++v32.value.VS._1.VStr->RefCount;
          goto LABEL_72;
        }
        if ( (v32.Flags & 0x1F) > 0xA )
        {
          if ( (v32.Flags & 0x1F) <= 0xF )
          {
            v28 = v32.value.VS._1;
          }
          else
          {
            if ( (v32.Flags & 0x1F) > 0x11 )
              goto LABEL_72;
            v28 = (Scaleform::GFx::AS3::Value::V1U)v32.value.VS._2.VObj;
          }
          if ( v28.VStr )
          {
            ++v28.VStr->Size;
            v28.VStr->Size &= 0x8FBFFFFF;
          }
        }
      }
    }
    else
    {
      pV->SA.ValueHHighInd = Length;
      key.pFirst = &pV->SA.ValueHHighInd;
      key.pSecond = &v32;
      Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
        &pV->SA.ValueH.mHash,
        pV->SA.ValueH.mHash.pHeap,
        &key);
    }
LABEL_72:
    ++pV->SA.Length;
    if ( (v32.Flags & 0x1F) > 9 )
    {
      if ( (v32.Flags & 0x200) != 0 )
      {
        v26 = v32.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v26 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&v32.Bonus, 0, 24);
        v32.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v32);
      }
    }
    `eh vector destructor iterator(&ptr, 0x20ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
    v17 = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)v17 + 1);
    ++v18;
    if ( (unsigned __int64)v17 >= this->SA.Length )
      goto LABEL_87;
  }
  if ( (v32.Flags & 0x1F) > 9 )
  {
    if ( (v32.Flags & 0x200) != 0 )
    {
      v26 = v32.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v26 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v32.Bonus, 0, 24);
      v32.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v32);
    }
  }
LABEL_86:
  `eh vector destructor iterator(&ptr, 0x20ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
LABEL_87:
  if ( (_this.Flags & 0x1F) > 9 )
  {
    if ( (_this.Flags & 0x200) != 0 )
    {
      v26 = _this.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v26 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&_this.Bonus, 0, 24);
      _this.Flags &= 0xFFFFFDE0;
    }
    else
    {
      switch ( _this.Flags & 0x1F )
      {
        case 0xA:
          VStr = _this.value.VS._1.VStr;
          v26 = _this.value.VS._1.VStr->RefCount-- == 1;
          if ( v26 )
            Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
          break;
        case 0xB:
        case 0xC:
        case 0xD:
        case 0xE:
        case 0xF:
          v30 = _this.value.VS._1.VObj;
          if ( !_this.value.VS._1.VBool )
            goto LABEL_99;
          --_this.value.VS._1.VStr;
          break;
        case 0x10:
        case 0x11:
          v30 = _this.value.VS._2.VObj;
          if ( ((__int64)_this.value.VS._2.VObj & 1) != 0 )
          {
            --_this.value.VS._2.VObj;
          }
          else
          {
LABEL_99:
            if ( v30 )
            {
              v31 = v30->RefCount;
              if ( (v31 & 0x3FFFFF) != 0 )
              {
                v30->RefCount = v31 - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v30);
              }
            }
          }
          break;
        default:
          return;
      }
    }
  }
}            v31 = v30->RefCount;
              if ( (v31 & 0x3

// File Line: 1765
// RVA: 0x7A40A0
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::AS3some(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        bool *result,
        Scaleform::GFx::AS3::Value *callback,
        Scaleform::GFx::AS3::Value *thisObject)
{
  unsigned int v7; // ecx
  unsigned int v8; // ecx
  unsigned int Flags; // ecx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  Scaleform::GFx::AS3::Value::V1U VObj; // rcx
  unsigned __int64 v13; // rdi
  __int64 v14; // r14
  Scaleform::GFx::AS3::Value *p_DefaultValue; // rcx
  signed __int64 Index; // rax
  char *v17; // rcx
  Scaleform::GFx::AS3::Value::V1U v18; // rdx
  bool v19; // zf
  Scaleform::GFx::ASStringNode *v20; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v21; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Value _this; // [rsp+38h] [rbp-81h] BYREF
  Scaleform::GFx::AS3::Value argv; // [rsp+58h] [rbp-61h] BYREF
  Scaleform::GFx::AS3::Value::V2U v25; // [rsp+78h] [rbp-41h]
  Scaleform::GFx::AS3::Value v26; // [rsp+80h] [rbp-39h] BYREF
  __int64 v27; // [rsp+A0h] [rbp-19h]
  __int64 v28; // [rsp+A8h] [rbp-11h]
  int v29; // [rsp+B0h] [rbp-9h]
  int v30; // [rsp+C0h] [rbp+7h]
  __int64 v31; // [rsp+C8h] [rbp+Fh]
  Scaleform::GFx::AS3::Instances::fl::Array *v32; // [rsp+D0h] [rbp+17h]
  __int64 v33; // [rsp+E0h] [rbp+27h]
  unsigned __int64 v34; // [rsp+130h] [rbp+77h] BYREF

  v33 = -2i64;
  v7 = callback->Flags & 0x1F;
  if ( !v7 || (v7 - 12 <= 3 || v7 == 10) && !callback->value.VS._1.VStr )
  {
LABEL_93:
    *result = 0;
    return;
  }
  v8 = thisObject->Flags & 0x1F;
  if ( !v8 || (v8 - 12 <= 3 || v8 == 10) && !thisObject->value.VS._1.VStr )
    thisObject = callback;
  Flags = thisObject->Flags;
  LODWORD(argv.Bonus.pWeakProxy) = Flags;
  pWeakProxy = thisObject->Bonus.pWeakProxy;
  argv.value = *(Scaleform::GFx::AS3::Value::VU *)&thisObject->Bonus.pWeakProxy;
  v25.VObj = (Scaleform::GFx::AS3::Object *)thisObject->value.VS._2;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
    {
      ++pWeakProxy->RefCount;
      goto LABEL_25;
    }
    if ( (Flags & 0x1F) == 10 )
    {
      ++thisObject->value.VS._1.VStr->RefCount;
    }
    else
    {
      if ( (Flags & 0x1F) <= 0xA )
        goto LABEL_25;
      if ( (Flags & 0x1F) <= 0xF )
      {
        VObj = thisObject->value.VS._1;
      }
      else
      {
        if ( (Flags & 0x1F) > 0x11 )
          goto LABEL_25;
        VObj = (Scaleform::GFx::AS3::Value::V1U)thisObject->value.VS._2.VObj;
      }
      if ( VObj.VStr )
        VObj.VStr->Size = (VObj.VStr->Size + 1) & 0x8FBFFFFF;
    }
  }
LABEL_25:
  v13 = 0i64;
  if ( !this->SA.Length )
  {
LABEL_78:
    if ( (unsigned __int64)((__int64)argv.Bonus.pWeakProxy & 0x1F) > 9 )
    {
      if ( ((__int64)argv.Bonus.pWeakProxy & 0x200) != 0 )
      {
        v19 = LODWORD(argv.value.VS._1.VStr->pData)-- == 1;
        if ( v19 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        argv.value = 0ui64;
        v25.VObj = 0i64;
        LODWORD(argv.Bonus.pWeakProxy) &= 0xFFFFFDE0;
      }
      else
      {
        switch ( (__int64)argv.Bonus.pWeakProxy & 0x1F )
        {
          case 0xAi64:
            v20 = (Scaleform::GFx::ASStringNode *)argv.value.VS._2.VObj;
            v19 = LODWORD(argv.value.VS._2.VObj->pPrev)-- == 1;
            if ( v19 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v20);
            break;
          case 0xBi64:
          case 0xCi64:
          case 0xDi64:
          case 0xEi64:
          case 0xFi64:
            v21 = argv.value.VS._2.VObj;
            if ( ((__int64)argv.value.VS._2.VObj & 1) == 0 )
              goto LABEL_90;
            --argv.value.VS._2.VObj;
            break;
          case 0x10i64:
          case 0x11i64:
            v21 = v25.VObj;
            if ( ((__int64)v25.VObj & 1) != 0 )
            {
              --v25.VObj;
            }
            else
            {
LABEL_90:
              if ( v21 )
              {
                RefCount = v21->RefCount;
                if ( (RefCount & 0x3FFFFF) != 0 )
                {
                  v21->RefCount = RefCount - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v21);
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
  v14 = 0i64;
  while ( 1 )
  {
    v34 = v13;
    if ( v13 >= this->SA.ValueA.Data.Size )
    {
      if ( v13 < this->SA.ValueHLowInd
        || v13 > this->SA.ValueHHighInd
        || (Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::findIndexAlt<unsigned __int64>(
                      &this->SA.ValueH.mHash,
                      &v34),
            Index < 0)
        || (v17 = (char *)&this->SA.ValueH.mHash.pTable[2] + 56 * Index) == 0i64
        || (p_DefaultValue = (Scaleform::GFx::AS3::Value *)(v17 + 8)) == 0i64 )
      {
        p_DefaultValue = &this->SA.DefaultValue;
      }
    }
    else
    {
      p_DefaultValue = &this->SA.ValueA.Data.Data[v14];
    }
    v26.Flags = p_DefaultValue->Flags;
    v26.Bonus.pWeakProxy = p_DefaultValue->Bonus.pWeakProxy;
    v26.value = p_DefaultValue->value;
    if ( (p_DefaultValue->Flags & 0x1F) > 9 )
    {
      if ( (p_DefaultValue->Flags & 0x200) != 0 )
      {
        ++p_DefaultValue->Bonus.pWeakProxy->RefCount;
        goto LABEL_47;
      }
      if ( (p_DefaultValue->Flags & 0x1F) == 10 )
      {
        ++p_DefaultValue->value.VS._1.VStr->RefCount;
      }
      else
      {
        if ( (p_DefaultValue->Flags & 0x1F) <= 0xA )
          goto LABEL_47;
        if ( (p_DefaultValue->Flags & 0x1F) <= 0xF )
        {
          v18 = p_DefaultValue->value.VS._1;
        }
        else
        {
          if ( (p_DefaultValue->Flags & 0x1F) > 0x11 )
            goto LABEL_47;
          v18 = (Scaleform::GFx::AS3::Value::V1U)p_DefaultValue->value.VS._2.VObj;
        }
        if ( v18.VStr )
          v18.VStr->Size = (v18.VStr->Size + 1) & 0x8FBFFFFF;
      }
    }
LABEL_47:
    LODWORD(v27) = 3;
    v28 = 0i64;
    v29 = v13;
    v30 = 12;
    v31 = 0i64;
    v32 = this;
    this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
    if ( !Scaleform::GFx::AS3::Value::IsCallable(callback) )
      goto LABEL_77;
    LODWORD(_this.Bonus.pWeakProxy) = 0;
    _this.value.VS._1.VStr = 0i64;
    Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(
      this->pTraits.pObject->pVM,
      callback,
      (Scaleform::GFx::AS3::Value *)&argv.Bonus,
      (Scaleform::GFx::AS3::Value *)&_this.Bonus,
      3u,
      &v26,
      0);
    if ( this->pTraits.pObject->pVM->HandleException )
    {
      if ( (unsigned __int64)((__int64)_this.Bonus.pWeakProxy & 0x1F) > 9 )
      {
        if ( ((__int64)_this.Bonus.pWeakProxy & 0x200) != 0 )
        {
          v19 = LODWORD(_this.value.VS._1.VStr->pData)-- == 1;
          if ( v19 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          _this.value = 0ui64;
          *(_QWORD *)&argv.Flags = 0i64;
          LODWORD(_this.Bonus.pWeakProxy) &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&_this.Bonus);
        }
      }
LABEL_77:
      `eh vector destructor iterator(
        &v26,
        0x20ui64,
        3,
        (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
      goto LABEL_78;
    }
    if ( ((__int64)_this.Bonus.pWeakProxy & 0x1F) != 1 || LOBYTE(_this.value.VS._2.VObj) == 1 )
      break;
    if ( (unsigned __int64)((__int64)_this.Bonus.pWeakProxy & 0x1F) > 9 )
    {
      if ( ((__int64)_this.Bonus.pWeakProxy & 0x200) != 0 )
      {
        v19 = LODWORD(_this.value.VS._1.VStr->pData)-- == 1;
        if ( v19 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        _this.value = 0ui64;
        *(_QWORD *)&argv.Flags = 0i64;
        LODWORD(_this.Bonus.pWeakProxy) &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&_this.Bonus);
      }
    }
    `eh vector destructor iterator(&v26, 0x20ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
    ++v13;
    ++v14;
    if ( v13 >= this->SA.Length )
      goto LABEL_78;
  }
  *result = 1;
  if ( (unsigned __int64)((__int64)_this.Bonus.pWeakProxy & 0x1F) > 9 )
  {
    if ( ((__int64)_this.Bonus.pWeakProxy & 0x200) != 0 )
    {
      v19 = LODWORD(_this.value.VS._1.VStr->pData)-- == 1;
      if ( v19 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      _this.value = 0ui64;
      *(_QWORD *)&argv.Flags = 0i64;
      LODWORD(_this.Bonus.pWeakProxy) &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&_this.Bonus);
    }
  }
  `eh vector destructor iterator(&v26, 0x20ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
  if ( (unsigned __int64)((__int64)argv.Bonus.pWeakProxy & 0x1F) > 9 )
  {
    if ( ((__int64)argv.Bonus.pWeakProxy & 0x200) != 0 )
    {
      v19 = LODWORD(argv.value.VS._1.VStr->pData)-- == 1;
      if ( v19 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      argv.value = 0ui64;
      v25.VObj = 0i64;
      LODWORD(argv.Bonus.pWeakProxy) &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&argv.Bonus);
    }
  }
}

// File Line: 1798
// RVA: 0x75D840
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::toLocaleStringProto(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::ASString *v5; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString resulta; // [rsp+50h] [rbp+18h] BYREF

  v5 = Scaleform::GFx::AS3::Instances::fl::Array::ToLocaleStringInternal(
         (Scaleform::GFx::AS3::Instances::fl::Array *)_this->value.VS._1.VStr,
         &resulta);
  Scaleform::GFx::AS3::Value::Assign(result, v5);
  pNode = resulta.pNode;
  if ( resulta.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 1810
// RVA: 0x75E670
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::toStringProto(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::ASString *v5; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString resulta; // [rsp+48h] [rbp+10h] BYREF

  v5 = Scaleform::GFx::AS3::Instances::fl::Array::ToStringInternal(
         (Scaleform::GFx::AS3::Instances::fl::Array *)_this->value.VS._1.VStr,
         &resulta,
         (Scaleform::GFx::ASString *)&vm->StringManagerRef->Builtins[14]);
  Scaleform::GFx::AS3::Value::Assign(result, v5);
  pNode = resulta.pNode;
  if ( resulta.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 1823
// RVA: 0x7D5380
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::ForEachChild_GC(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__fastcall *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  Scaleform::GFx::AS3::Object::ForEachChild_GC(this, prcc, op);
  Scaleform::GFx::AS3::Impl::SparseArray::ForEachChild_GC(&this->SA, prcc, op);
}

// File Line: 1830
// RVA: 0x794C90
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  unsigned int v5; // r9d
  Scaleform::GFx::AS3::VM::Error *v6; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  long double iptr; // [rsp+28h] [rbp-30h] BYREF
  Scaleform::GFx::AS3::VM::Error v10; // [rsp+30h] [rbp-28h] BYREF
  Scaleform::GFx::AS3::CheckResult result; // [rsp+68h] [rbp+10h] BYREF
  long double v12; // [rsp+78h] [rbp+20h] BYREF

  if ( argc == 1 && (v5 = argv->Flags & 0x1F, v5 - 2 <= 2) )
  {
    if ( v5 == 4 && modf(argv->value.VNumber, &iptr) != 0.0 )
      goto LABEL_5;
    if ( !Scaleform::GFx::AS3::Value::Convert2Number(argv, &result, &v12)->Result )
      return;
    if ( v12 < 0.0 )
    {
LABEL_5:
      Scaleform::GFx::AS3::VM::Error::Error(&v10, 1005, this->pTraits.pObject->pVM);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        this->pTraits.pObject->pVM,
        v6,
        &Scaleform::GFx::AS3::fl::RangeErrorTI);
      pNode = v10.Message.pNode;
      if ( v10.Message.pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
    else
    {
      Scaleform::GFx::AS3::Impl::SparseArray::Resize(&this->SA, (unsigned int)(int)v12);
    }
  }
  else
  {
    Scaleform::GFx::AS3::Impl::SparseArray::Append(&this->SA, argc, argv);
  }
}

// File Line: 1871
// RVA: 0x826810
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::Instances::fl::Array::ToStringInternal(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::ASString *sep)
{
  unsigned __int64 v6; // rbx
  __int64 v7; // r14
  Scaleform::GFx::AS3::Value *p_DefaultValue; // rcx
  signed __int64 Index; // rax
  char *v10; // rcx
  int v11; // edx
  char *pData; // r8
  Scaleform::StringBuffer v14; // [rsp+30h] [rbp-58h] BYREF
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+90h] [rbp+8h] BYREF
  Scaleform::GFx::ASString *v16; // [rsp+98h] [rbp+10h]
  unsigned __int64 key; // [rsp+A8h] [rbp+20h] BYREF

  v16 = result;
  v6 = 0i64;
  Scaleform::StringBuffer::StringBuffer(&v14, this->pTraits.pObject->pVM->MHeap);
  if ( this->SA.Length )
  {
    v7 = 0i64;
    do
    {
      if ( v6 )
        Scaleform::StringBuffer::AppendString(&v14, sep->pNode->pData, -1i64);
      key = v6;
      if ( v6 >= this->SA.ValueA.Data.Size )
      {
        if ( v6 < this->SA.ValueHLowInd
          || v6 > this->SA.ValueHHighInd
          || (Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::findIndexAlt<unsigned __int64>(
                        &this->SA.ValueH.mHash,
                        &key),
              Index < 0)
          || (v10 = (char *)&this->SA.ValueH.mHash.pTable[2] + 56 * Index) == 0i64
          || (p_DefaultValue = (Scaleform::GFx::AS3::Value *)(v10 + 8)) == 0i64 )
        {
          p_DefaultValue = &this->SA.DefaultValue;
        }
      }
      else
      {
        p_DefaultValue = &this->SA.ValueA.Data.Data[v7];
      }
      v11 = p_DefaultValue->Flags & 0x1F;
      if ( v11
        && ((unsigned int)(v11 - 12) > 3 && v11 != 10 || p_DefaultValue->value.VS._1.VStr)
        && !Scaleform::GFx::AS3::Value::Convert2String(p_DefaultValue, &resulta, &v14)->Result )
      {
        break;
      }
      ++v6;
      ++v7;
    }
    while ( v6 < this->SA.Length );
  }
  pData = &customCaption;
  if ( v14.pData )
    pData = v14.pData;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
    this->pTraits.pObject->pVM->StringManagerRef,
    result,
    pData,
    v14.Size);
  Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&v14);
  return result;
}

// File Line: 1893
// RVA: 0x825C80
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::Instances::fl::Array::ToLocaleStringInternal(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        Scaleform::GFx::ASString *result)
{
  unsigned __int64 v3; // r14
  Scaleform::GFx::AS3::Value *p_DefaultValue; // r15
  signed __int64 Index; // rax
  char *v6; // rdx
  int v7; // ecx
  Scaleform::GFx::AS3::Value::V1U *v8; // rax
  char v9; // di
  Scaleform::GFx::AS3::Value::V1U v10; // rbx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v11; // r13
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // rdx
  int v13; // esi
  const char *pData; // rax
  Scaleform::GFx::AS3::GASRefCountBase *v15; // r14
  Scaleform::GFx::AS3::GASRefCountBase *v16; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASString *v18; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v20; // zf
  Scaleform::GFx::ASStringNode *v21; // rcx
  unsigned int Size; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *VStr; // rcx
  unsigned int v24; // eax
  Scaleform::GFx::ASStringNode *v25; // rcx
  Scaleform::GFx::ASString *v26; // rax
  Scaleform::GFx::ASStringNode *v27; // rcx
  Scaleform::GFx::ASString *v28; // rax
  Scaleform::GFx::AS3::GASRefCountBase *v29; // rcx
  unsigned int v30; // eax
  Scaleform::GFx::AS3::GASRefCountBase *v31; // rcx
  unsigned int v32; // eax
  char *v33; // r8
  Scaleform::GFx::AS3::Multiname prop_name; // [rsp+40h] [rbp-C0h] BYREF
  Scaleform::GFx::AS3::Value value; // [rsp+70h] [rbp-90h] BYREF
  __int64 v37[2]; // [rsp+90h] [rbp-70h] BYREF
  Scaleform::GFx::AS3::Value::V1U v38; // [rsp+A0h] [rbp-60h]
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v39; // [rsp+A8h] [rbp-58h]
  int v40; // [rsp+B0h] [rbp-50h]
  Scaleform::GFx::ASString resulta; // [rsp+B8h] [rbp-48h] BYREF
  unsigned __int64 key; // [rsp+C0h] [rbp-40h] BYREF
  Scaleform::GFx::ASString v43; // [rsp+C8h] [rbp-38h] BYREF
  Scaleform::GFx::ASString v44; // [rsp+D0h] [rbp-30h] BYREF
  Scaleform::GFx::ASString v45; // [rsp+D8h] [rbp-28h] BYREF
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v46; // [rsp+E0h] [rbp-20h]
  Scaleform::StringBuffer v47; // [rsp+E8h] [rbp-18h] BYREF
  __int64 v48; // [rsp+118h] [rbp+18h]
  Scaleform::GFx::AS3::CheckResult v49; // [rsp+170h] [rbp+70h] BYREF
  Scaleform::GFx::ASString *v50; // [rsp+178h] [rbp+78h]
  Scaleform::GFx::ASString v51; // [rsp+180h] [rbp+80h] BYREF
  unsigned __int64 v52; // [rsp+188h] [rbp+88h]

  v50 = result;
  v48 = -2i64;
  v40 = 0;
  Scaleform::StringBuffer::StringBuffer(&v47, this->pTraits.pObject->pVM->MHeap);
  v3 = 0i64;
  v52 = 0i64;
  if ( !this->SA.Length )
    goto LABEL_110;
  while ( 1 )
  {
    if ( v3 )
      Scaleform::StringBuffer::AppendString(&v47, ",", -1i64);
    key = v3;
    if ( v3 >= this->SA.ValueA.Data.Size )
    {
      if ( v3 < this->SA.ValueHLowInd
        || v3 > this->SA.ValueHHighInd
        || (Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::findIndexAlt<unsigned __int64>(
                      &this->SA.ValueH.mHash,
                      &key),
            Index < 0)
        || (v6 = (char *)&this->SA.ValueH.mHash.pTable[2] + 56 * Index) == 0i64
        || (p_DefaultValue = (Scaleform::GFx::AS3::Value *)(v6 + 8), v6 == (char *)-8i64) )
      {
        p_DefaultValue = &this->SA.DefaultValue;
      }
    }
    else
    {
      p_DefaultValue = &this->SA.ValueA.Data.Data[v3];
    }
    v7 = p_DefaultValue->Flags & 0x1F;
    if ( !v7 || ((unsigned int)(v7 - 12) <= 3 || v7 == 10) && !p_DefaultValue->value.VS._1.VStr )
      goto LABEL_91;
    v8 = (Scaleform::GFx::AS3::Value::V1U *)Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                                              this->pTraits.pObject->pVM->StringManagerRef,
                                              &resulta,
                                              "toLocaleString");
    v9 = 10;
    LODWORD(v37[0]) = 10;
    v37[1] = 0i64;
    v10 = *v8;
    v38 = v10;
    if ( v10.VStr == &v10.VStr->pManager->NullStringNode )
    {
      v10.VStr = 0i64;
      v38.VStr = 0i64;
      v11 = v46;
      v39 = v46;
      v9 = 12;
      LODWORD(v37[0]) = 12;
    }
    else
    {
      ++v10.VStr->RefCount;
      v11 = v39;
    }
    pObject = this->pTraits.pObject->pVM->PublicNamespace.pObject;
    prop_name.Kind = MN_QName;
    prop_name.Obj.pObject = pObject;
    if ( pObject )
      pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
    prop_name.Name.Flags = 0;
    prop_name.Name.Bonus.pWeakProxy = 0i64;
    v13 = v9 & 0x1F;
    if ( (unsigned int)(v13 - 12) <= 3
      && v10.VStr
      && (pData = v10.VStr[1].pData, *((_DWORD *)pData + 30) == 17)
      && (pData[112] & 0x20) == 0 )
    {
      Scaleform::GFx::AS3::Value::Assign(&prop_name.Name, (Scaleform::GFx::ASString *)&v10.VStr[1].16);
      v15 = *(Scaleform::GFx::AS3::GASRefCountBase **)&v10.VStr[1].RefCount;
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
          if ( ((__int64)prop_name.Obj.pObject & 1) != 0 )
          {
            prop_name.Obj.pObject = (Scaleform::GFx::AS3::GASRefCountBase *)((char *)v16 - 1);
          }
          else
          {
            RefCount = v16->RefCount;
            if ( (RefCount & 0x3FFFFF) != 0 )
            {
              v16->RefCount = RefCount - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v16);
            }
          }
        }
        prop_name.Obj.pObject = v15;
      }
      prop_name.Kind &= 0xFFFFFFF9;
      v3 = v52;
    }
    else
    {
      _mm_prefetch((const char *)v37, 2);
      *(_QWORD *)&prop_name.Name.Flags = v37[0];
      prop_name.Name.Bonus.pWeakProxy = 0i64;
      prop_name.Name.value.VS._1 = v10;
      prop_name.Name.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v11;
      if ( (v9 & 0x1Fu) > 9 )
      {
        if ( v13 == 10 )
        {
          ++v10.VStr->RefCount;
        }
        else if ( (v9 & 0x1Fu) <= 0xF )
        {
          if ( v10.VStr )
            v10.VStr->Size = (v10.VStr->Size + 1) & 0x8FBFFFFF;
        }
        else if ( (v9 & 0x1Fu) <= 0x11 && v11 )
        {
          v11->RefCount = (v11->RefCount + 1) & 0x8FBFFFFF;
        }
      }
      if ( (prop_name.Name.Flags & 0x1F) == 10 )
      {
        Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&prop_name.Name, &v51);
        if ( v51.pNode->Size )
        {
          if ( *v51.pNode->pData == 64 )
          {
            prop_name.Kind |= 8u;
            v18 = Scaleform::GFx::ASString::Substring(&v51, &v43, 1, v51.pNode->Size);
            Scaleform::GFx::AS3::Value::Assign(&prop_name.Name, v18);
            pNode = v43.pNode;
            v20 = v43.pNode->RefCount-- == 1;
            if ( v20 )
              Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
          }
        }
        v21 = v51.pNode;
        v20 = v51.pNode->RefCount-- == 1;
        if ( v20 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v21);
      }
    }
    if ( (v9 & 0x1Fu) > 9 )
    {
      switch ( v9 & 0x1F )
      {
        case 0xA:
          v20 = v10.VStr->RefCount-- == 1;
          if ( v20 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v10.VStr);
          break;
        case 0xB:
        case 0xC:
        case 0xD:
        case 0xE:
        case 0xF:
          if ( v38.VBool )
          {
            v38.VStr = (Scaleform::GFx::ASStringNode *)((char *)v10.VStr - 1);
          }
          else if ( v10.VStr )
          {
            Size = v10.VStr->Size;
            if ( (Size & 0x3FFFFF) != 0 )
            {
              v10.VStr->Size = Size - 1;
              VStr = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v10.VStr;
              goto LABEL_65;
            }
          }
          break;
        case 0x10:
        case 0x11:
          if ( ((unsigned __int8)v39 & 1) != 0 )
          {
            v39 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v11 - 1);
          }
          else if ( v11 )
          {
            v24 = v11->RefCount;
            if ( (v24 & 0x3FFFFF) != 0 )
            {
              v11->RefCount = v24 - 1;
              VStr = v11;
LABEL_65:
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(VStr);
            }
          }
          break;
        default:
          break;
      }
    }
    v25 = resulta.pNode;
    v20 = resulta.pNode->RefCount-- == 1;
    if ( v20 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v25);
    value.Flags = 0;
    value.Bonus.pWeakProxy = 0i64;
    if ( !Scaleform::GFx::AS3::ExecutePropertyUnsafe(&v49, this->pTraits.pObject->pVM, &prop_name, p_DefaultValue)->Result )
      break;
    if ( (value.Flags & 0x1F) == 10 )
    {
      v26 = Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&value, &v44);
      Scaleform::StringBuffer::AppendString(&v47, v26->pNode->pData, -1i64);
      v27 = v44.pNode;
    }
    else
    {
      v28 = Scaleform::GFx::AS3::AsString(&v45, &value, this->pTraits.pObject->pVM->StringManagerRef);
      Scaleform::StringBuffer::AppendString(&v47, v28->pNode->pData, -1i64);
      v27 = v45.pNode;
    }
    v20 = v27->RefCount-- == 1;
    if ( v20 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v27);
    if ( (value.Flags & 0x1F) > 9 )
    {
      if ( (value.Flags & 0x200) != 0 )
      {
        v20 = value.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v20 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&value.Bonus, 0, 24);
        value.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
      }
    }
    if ( (prop_name.Name.Flags & 0x1F) > 9 )
    {
      if ( (prop_name.Name.Flags & 0x200) != 0 )
      {
        v20 = prop_name.Name.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v20 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&prop_name.Name.Bonus, 0, 24);
        prop_name.Name.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&prop_name.Name);
      }
    }
    v29 = prop_name.Obj.pObject;
    if ( prop_name.Obj.pObject )
    {
      if ( ((__int64)prop_name.Obj.pObject & 1) != 0 )
      {
        --prop_name.Obj.pObject;
      }
      else
      {
        v30 = prop_name.Obj.pObject->RefCount;
        if ( (v30 & 0x3FFFFF) != 0 )
        {
          prop_name.Obj.pObject->RefCount = v30 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v29);
        }
      }
    }
LABEL_91:
    v52 = ++v3;
    if ( v3 >= this->SA.Length )
      goto LABEL_110;
  }
  if ( (value.Flags & 0x1F) > 9 )
  {
    if ( (value.Flags & 0x200) != 0 )
    {
      v20 = value.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v20 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&value.Bonus, 0, 24);
      value.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
    }
  }
  if ( (prop_name.Name.Flags & 0x1F) > 9 )
  {
    if ( (prop_name.Name.Flags & 0x200) != 0 )
    {
      v20 = prop_name.Name.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v20 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&prop_name.Name.Bonus, 0, 24);
      prop_name.Name.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&prop_name.Name);
    }
  }
  v31 = prop_name.Obj.pObject;
  if ( prop_name.Obj.pObject )
  {
    if ( ((__int64)prop_name.Obj.pObject & 1) != 0 )
    {
      --prop_name.Obj.pObject;
    }
    else
    {
      v32 = prop_name.Obj.pObject->RefCount;
      if ( (v32 & 0x3FFFFF) != 0 )
      {
        prop_name.Obj.pObject->RefCount = v32 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v31);
      }
    }
  }
LABEL_110:
  v33 = &customCaption;
  if ( v47.pData )
    v33 = v47.pData;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
    this->pTraits.pObject->pVM->StringManagerRef,
    v50,
    v33,
    v47.Size);
  v40 = 1;
  Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&v47);
  return v50;
}

// File Line: 1923
// RVA: 0x7ECD60
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::GetNextPropertyName(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        Scaleform::GFx::AS3::Value *name,
        Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
  unsigned int v4; // r8d
  Scaleform::HashLH<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor,2,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *p_DynAttrs; // r10
  Scaleform::HashLH<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor,2,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *v6; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *pTable; // rcx
  unsigned __int64 SizeMask; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *v9; // rcx

  if ( ind.Index )
  {
    if ( ind.Index > this->SA.Length )
    {
      v4 = ind.Index - LODWORD(this->SA.Length);
      p_DynAttrs = &this->DynAttrs;
      v6 = 0i64;
      pTable = this->DynAttrs.mHash.pTable;
      if ( pTable )
      {
        SizeMask = pTable->SizeMask;
        v9 = pTable + 1;
        do
        {
          if ( v9->EntryCount != -2i64 )
            break;
          v6 = (Scaleform::HashLH<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor,2,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *)((char *)v6 + 1);
          v9 += 4;
        }
        while ( (unsigned __int64)v6 <= SizeMask );
        v6 = p_DynAttrs;
      }
      Scaleform::GFx::AS3::Value::Assign(
        name,
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
Scaleform::GFx::AS3::GlobalSlotIndex *__fastcall Scaleform::GFx::AS3::Instances::fl::Array::GetNextDynPropIndex(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        Scaleform::GFx::AS3::GlobalSlotIndex *result,
        Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
  Scaleform::GFx::AS3::GlobalSlotIndex *v5; // rax
  unsigned int Length; // edi
  Scaleform::GFx::AS3::GlobalSlotIndex *NextDynPropIndex; // rax
  unsigned int v8; // ecx
  Scaleform::GFx::AS3::AbsoluteIndex resulta; // [rsp+30h] [rbp+8h] BYREF
  unsigned int Index; // [rsp+40h] [rbp+18h]

  Index = ind.Index;
  result->Index = 0;
  if ( ind.Index <= this->SA.Length )
  {
    Scaleform::GFx::AS3::Impl::SparseArray::GetNextArrayIndex(
      &this->SA,
      &resulta,
      (Scaleform::GFx::AS3::AbsoluteIndex)(ind.Index - 1i64));
    if ( resulta.Index >= 0 )
    {
      v5 = result;
      result->Index = LODWORD(resulta.Index) + 1;
      return v5;
    }
    ind.Index = Index;
  }
  Length = this->SA.Length;
  if ( ind.Index >= Length )
    ind.Index -= Length;
  NextDynPropIndex = Scaleform::GFx::AS3::Object::GetNextDynPropIndex(
                       this,
                       (Scaleform::GFx::AS3::GlobalSlotIndex *)&resulta,
                       ind);
  v8 = NextDynPropIndex->Index;
  result->Index = NextDynPropIndex->Index;
  if ( v8 )
    result->Index = v8 + Length;
  return result;
}

// File Line: 1957
// RVA: 0x7ED0A0
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::GetNextPropertyValue(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
  Scaleform::GFx::AS3::Impl::SparseArray *p_SA; // rcx
  Scaleform::GFx::AS3::Value *v6; // rax
  unsigned int v7; // r8d

  if ( ind.Index )
  {
    p_SA = &this->SA;
    if ( ind.Index > p_SA->Length )
    {
      v7 = ind.Index - LODWORD(p_SA->Length);
      if ( v7 )
        ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl::Array *, __int64, Scaleform::GFx::AS3::Value *))this->vfptr[1].Finalize_GC)(
          this,
          v7 - 1i64,
          value);
    }
    else
    {
      v6 = Scaleform::GFx::AS3::Impl::SparseArray::At(p_SA, ind.Index - 1);
      Scaleform::GFx::AS3::Value::Assign(value, v6);
    }
  }
  else
  {
    Scaleform::GFx::AS3::Value::SetUndefined(value);
  }
}

// File Line: 1968
// RVA: 0x81AD90
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl::Array::SetProperty(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Multiname *prop_name,
        Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+20h] [rbp-18h] BYREF
  unsigned int ind[5]; // [rsp+24h] [rbp-14h] BYREF

  if ( Scaleform::GFx::AS3::GetArrayInd(&resulta, prop_name, ind)->Result )
  {
    Scaleform::GFx::AS3::Impl::SparseArray::Set(&this->SA, ind[0], value);
    result->Result = 1;
  }
  else
  {
    Scaleform::GFx::AS3::Object::SetProperty(this, result, prop_name, value);
  }
  return result;
}

// File Line: 1981
// RVA: 0x7EDBE0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl::Array::GetProperty(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Multiname *prop_name,
        Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::Value *v8; // rax
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+20h] [rbp-18h] BYREF
  unsigned int ind[5]; // [rsp+24h] [rbp-14h] BYREF

  if ( Scaleform::GFx::AS3::GetArrayInd(&resulta, prop_name, ind)->Result )
  {
    v8 = Scaleform::GFx::AS3::Impl::SparseArray::At(&this->SA, ind[0]);
    Scaleform::GFx::AS3::Value::Assign(value, v8);
    result->Result = 1;
  }
  else
  {
    Scaleform::GFx::AS3::Object::GetProperty(this, result, prop_name, value);
  }
  return result;
}

// File Line: 1994
// RVA: 0x7E9340
void __fastcall Scaleform::GFx::AS3::Instances::fl::Array::GetDynamicProperty(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        Scaleform::GFx::AS3::AbsoluteIndex ind,
        Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::Value *v4; // rax

  v4 = Scaleform::GFx::AS3::Impl::SparseArray::At(&this->SA, LODWORD(ind.Index));
  Scaleform::GFx::AS3::Value::Assign(value, v4);
}

// File Line: 1999
// RVA: 0x7C0D80
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Instances::fl::Array::DeleteProperty(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Multiname *prop_name)
{
  unsigned int ind[6]; // [rsp+20h] [rbp-18h] BYREF
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+58h] [rbp+20h] BYREF

  if ( Scaleform::GFx::AS3::GetArrayInd(&resulta, prop_name, ind)->Result )
  {
    if ( ind[0] < this->SA.Length )
    {
      Scaleform::GFx::AS3::Impl::SparseArray::RemoveMultipleAt(&this->SA, ind[0], 1ui64, opRemove);
      result->Result = 1;
    }
    else
    {
      result->Result = 0;
    }
    return result;
  }
  else
  {
    Scaleform::GFx::AS3::Object::DeleteProperty(this, result, prop_name);
    return result;
  }
}

// File Line: 2016
// RVA: 0x7F2830
bool __fastcall Scaleform::GFx::AS3::Instances::fl::Array::HasProperty(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        Scaleform::GFx::AS3::Multiname *prop_name,
        bool check_prototype)
{
  unsigned int v5; // ecx
  unsigned __int64 VInt; // rax
  Scaleform::GFx::ASStringNode *VStr; // rdx
  Scaleform::GFx::AS3::CheckResult result; // [rsp+48h] [rbp+10h] BYREF
  unsigned int ind; // [rsp+58h] [rbp+20h] BYREF

  v5 = prop_name->Name.Flags & 0x1F;
  if ( v5 - 2 > 1 )
  {
    if ( v5 == 10
      && (VStr = prop_name->Name.value.VS._1.VStr, ind = 0,
                                                   Scaleform::GFx::AS3::GetArrayInd(&result, VStr, &ind)->Result) )
    {
      return ind < this->SA.Length;
    }
    else
    {
      return Scaleform::GFx::AS3::Object::HasProperty(this, prop_name, check_prototype);
    }
  }
  else
  {
    VInt = prop_name->Name.value.VS._1.VInt;
    return (VInt & 0x80000000) == 0i64 && VInt < this->SA.Length;
  }
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
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Array::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl::Array *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl::Array *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> *Instance; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> resulta; // [rsp+48h] [rbp+20h] BYREF

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl::Array::MakeInstance(&resulta, t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}

// File Line: 2134
// RVA: 0x7B2DB0
void __fastcall Scaleform::GFx::AS3::Classes::fl::RegExp::Call(
        Scaleform::GFx::AS3::Classes::fl::uint *this,
        Scaleform::GFx::AS3::Value *__formal,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *const argv)
{
  ((void (__fastcall *)(Scaleform::GFx::AS3::Classes::fl::uint *, Scaleform::GFx::AS3::Value *, _QWORD, Scaleform::GFx::AS3::Value *const))this->vfptr[4].ForEachChild_GC)(
    this,
    result,
    argc,
    argv);
}

// File Line: 2140
// RVA: 0x8004B0
Scaleform::Pickable<Scaleform::GFx::AS3::Object> *__fastcall Scaleform::GFx::AS3::Classes::fl::Array::MakePrototype(
        Scaleform::GFx::AS3::Classes::fl::Array *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Object> *result)
{
  Scaleform::GFx::AS3::Instances::fl::Array *pV; // rcx
  Scaleform::Pickable<Scaleform::GFx::AS3::Object> *v4; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> resulta; // [rsp+30h] [rbp+8h] BYREF

  pV = Scaleform::GFx::AS3::InstanceTraits::fl::Array::MakeInstance(
         &resulta,
         (Scaleform::GFx::AS3::InstanceTraits::fl::Array *)this->pTraits.pObject[1].vfptr)->pV;
  v4 = result;
  result->pV = pV;
  return v4;
}

// File Line: 2146
// RVA: 0x7F3CC0
void __fastcall Scaleform::GFx::AS3::Classes::fl::Array::InitPrototype(
        Scaleform::GFx::AS3::Classes::fl::Array *this,
        Scaleform::GFx::AS3::Object *obj)
{
  Scaleform::GFx::AS3::Class *pObject; // rcx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v5; // rbx
  Scaleform::GFx::AS3::Classes::Function *v6; // r13
  const char **p_Name; // rbx
  Scaleform::GFx::AS3::ThunkInfo *v8; // rdi
  __int64 v9; // rsi
  Scaleform::GFx::ASStringNode *pV; // rcx
  Scaleform::GFx::ASString *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  bool v13; // zf
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v16; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *v18[2]; // [rsp+30h] [rbp-40h] BYREF
  Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef key; // [rsp+40h] [rbp-30h] BYREF
  int v20; // [rsp+50h] [rbp-20h] BYREF
  _DWORD *v21; // [rsp+58h] [rbp-18h]
  Scaleform::GFx::ASStringNode *v22; // [rsp+60h] [rbp-10h]
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v23; // [rsp+68h] [rbp-8h]
  Scaleform::GFx::ASString v24; // [rsp+B0h] [rbp+40h] BYREF
  Scaleform::GFx::AS3::Object *obja; // [rsp+B8h] [rbp+48h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::CheckTypeTF> result; // [rsp+C0h] [rbp+50h] BYREF

  obja = obj;
  pObject = this->ParentClass.pObject;
  if ( pObject )
    pObject->vfptr[7].Finalize_GC(pObject);
  v18[0] = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::AS3::Class::ConvertCheckType;
  LODWORD(v18[1]) = 0;
  key = *(Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef *)v18;
  Scaleform::GFx::AS3::Class::InitPrototypeFromVTable(
    this,
    obj,
    (Scaleform::GFx::AS3::Value *(__fastcall *)(Scaleform::GFx::AS3::Class *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))&key);
  v5 = this->pTraits.pObject->pVM->TraitsFunction.pObject->ITraits.pObject;
  if ( !v5->pConstructor.pObject )
    v5->vfptr[3].~RefCountBaseGC<328>(v5);
  v6 = (Scaleform::GFx::AS3::Classes::Function *)v5->pConstructor.pObject;
  key.pFirst = (Scaleform::GFx::AS3::Object::DynAttrsKey *)v18;
  key.pSecond = (Scaleform::GFx::AS3::Value *)&v20;
  p_Name = &Scaleform::GFx::AS3::Classes::fl::Array::ti[0].Name;
  v8 = Scaleform::GFx::AS3::Classes::fl::Array::ti;
  v9 = 2i64;
  do
  {
    pV = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::AS3::Classes::Function::MakeCheckTypeInstance(
                                           v6,
                                           &result,
                                           this,
                                           v8)->pV;
    v21 = 0i64;
    v20 = 15;
    v22 = pV;
    v23 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v20;
    v11 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
            this->pTraits.pObject->pVM->StringManagerRef,
            &v24,
            *p_Name);
    LODWORD(v18[0]) = 1;
    v18[1] = v11->pNode;
    ++v18[1]->RefCount;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
      &obj->DynAttrs.mHash,
      &obj->DynAttrs,
      &key);
    v12 = v18[1];
    v13 = v18[1]->RefCount-- == 1;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
    pNode = v24.pNode;
    v13 = v24.pNode->RefCount-- == 1;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    if ( (v20 & 0x1Fu) > 9 )
    {
      if ( (v20 & 0x200) != 0 )
      {
        v13 = (*v21)-- == 1;
        if ( v13 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        v21 = 0i64;
        v22 = 0i64;
        v23 = 0i64;
        v20 &= 0xFFFFFDE0;
      }
      else
      {
        switch ( v20 & 0x1F )
        {
          case 0xA:
            v15 = v22;
            v13 = v22->RefCount-- == 1;
            if ( v13 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v15);
            break;
          case 0xB:
          case 0xC:
          case 0xD:
          case 0xE:
          case 0xF:
            v16 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v22;
            if ( ((unsigned __int8)v22 & 1) == 0 )
              goto LABEL_22;
            v22 = (Scaleform::GFx::ASStringNode *)((char *)v22 - 1);
            break;
          case 0x10:
          case 0x11:
            v16 = v23;
            if ( ((unsigned __int8)v23 & 1) != 0 )
            {
              v23 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v23 - 1);
            }
            else
            {
LABEL_22:
              if ( v16 )
              {
                RefCount = v16->RefCount;
                if ( (RefCount & 0x3FFFFF) != 0 )
                {
                  v16->RefCount = RefCount - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v16);
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
    p_Name += 6;
    --v9;
  }
  while ( v9 );
  Scaleform::GFx::AS3::Class::AddConstructor(this, obja);
}

// File Line: 2209
// RVA: 0x730CE0
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl::Array::MakeClassTraits(
        Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rbx
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> v8; // rbx
  Scaleform::GFx::AS3::Class *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rbx

  MHeap = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)MHeap->vfptr->Alloc(MHeap, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, vm, &Scaleform::GFx::AS3::fl::ArrayCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Array::`vftable;
    v6->TraitsType = Traits_Array;
  }
  else
  {
    v6 = 0i64;
  }
  result->pV = v6;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)MHeap->vfptr->Alloc(MHeap, 240ui64, 0i64);
  v8.pV = v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, vm, &Scaleform::GFx::AS3::fl::ArrayCI);
    v8.pV->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
    v8.pV->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Array::`vftable;
    v8.pV->Flags |= 1ui64;
    v8.pV->TraitsType = Traits_Array;
  }
  else
  {
    v8.pV = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(result->pV, v8);
  v9 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))MHeap->vfptr->Alloc)(
                                       MHeap,
                                       96i64);
  v10 = v9;
  if ( v9 )
  {
    Scaleform::GFx::AS3::Class::Class(v9, result->pV);
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl::Array::`vftable;
    LODWORD(v10[1].vfptr) = 1;
    HIDWORD(v10[1].vfptr) = 2;
    LODWORD(v10[1]._pRCC) = 4;
    HIDWORD(v10[1].pRCCRaw) = 8;
    LODWORD(v10[1].pNext) = 16;
  }
  return result;
}

