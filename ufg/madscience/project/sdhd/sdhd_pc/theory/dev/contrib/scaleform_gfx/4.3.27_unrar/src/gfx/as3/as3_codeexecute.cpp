// File Line: 39
// RVA: 0x7AAA10
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Add(
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Value *sm,
        Scaleform::GFx::AS3::Value *a3,
        Scaleform::GFx::AS3::Value *l)
{
  Scaleform::GFx::AS3::Value *pNode; // r10
  Scaleform::GFx::AS3::Value::V1U v9; // r8
  __int64 v10; // rcx
  bool v13; // zf
  Scaleform::GFx::ASString *v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::AS3::CheckResult v20; // [rsp+1Ch] [rbp-1Dh] BYREF
  Scaleform::GFx::AS3::Value::Hint hint[2]; // [rsp+20h] [rbp-19h] BYREF
  Scaleform::GFx::ASString str; // [rsp+28h] [rbp-11h] BYREF
  Scaleform::GFx::AS3::Value la; // [rsp+30h] [rbp-9h] BYREF
  Scaleform::GFx::AS3::Value v24; // [rsp+50h] [rbp+17h] BYREF
  __int64 v25; // [rsp+70h] [rbp+37h]
  Scaleform::GFx::AS3::StringManager *sma; // [rsp+A0h] [rbp+67h]
  Scaleform::GFx::AS3::Value *retaddr; // [rsp+A8h] [rbp+6Fh]
  Scaleform::GFx::ASString resulta; // [rsp+B0h] [rbp+77h] BYREF
  Scaleform::GFx::AS3::Value *v29; // [rsp+B8h] [rbp+7Fh]
  Scaleform::GFx::AS3::Value *v30; // [rsp+C0h] [rbp+87h]
  Scaleform::GFx::AS3::Value *v31; // [rsp+C8h] [rbp+8Fh]

  v31 = l;
  v30 = a3;
  v29 = sm;
  v25 = -2i64;
  pNode = l;
  if ( (l->Flags & 0x1F) - 12 <= 3 && (v29->Flags & 0x1F) - 12 <= 3 )
  {
    v9 = l->value.VS._1;
    if ( v9.VStr )
    {
      if ( v29->value.VS._1.VStr )
      {
        v10 = *(_QWORD *)(*((_QWORD *)v9.VStr[1].pData + 16) + 56i64);
        if ( (*(unsigned __int8 (__fastcall **)(__int64, Scaleform::GFx::AS3::Value *))(*(_QWORD *)v10 + 56i64))(
               v10,
               a3) )
        {
LABEL_17:
          result->Result = 1;
          return result;
        }
        pNode = (Scaleform::GFx::AS3::Value *)resulta.pNode;
      }
    }
  }
  if ( (pNode->Flags & 0x1F) == 10 || (sm->Flags & 0x1F) == 10 )
  {
    Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
      (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)sm,
      (Scaleform::GFx::ASString *)hint);
    Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
      (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)sm,
      &str);
    if ( Scaleform::GFx::AS3::Value::Convert2String(
           (Scaleform::GFx::AS3::Value *)resulta.pNode,
           &v20,
           (Scaleform::GFx::ASString *)hint)->Result
      && Scaleform::GFx::AS3::Value::Convert2String(sm, (Scaleform::GFx::AS3::CheckResult *)&resulta, &str)->Result )
    {
      v15 = Scaleform::GFx::ASString::operator+((Scaleform::GFx::ASString *)hint, &resulta, &str);
      Scaleform::GFx::AS3::Value::Assign(retaddr, v15);
      v16 = resulta.pNode;
      v13 = resulta.pNode->RefCount-- == 1;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v16);
      result->Result = 1;
    }
    else
    {
      result->Result = 0;
    }
    v17 = str.pNode;
    v13 = str.pNode->RefCount-- == 1;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v17);
    v18 = *(Scaleform::GFx::ASStringNode **)hint;
    v13 = (*(_DWORD *)(*(_QWORD *)hint + 24i64))-- == 1;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  }
  else
  {
    if ( (pNode->Flags & 0x1F) < 5 && (sm->Flags & 0x1F) < 5 )
    {
      *(double *)&str.pNode = 0.0;
      *(double *)hint = 0.0;
      if ( !Scaleform::GFx::AS3::Value::Convert2NumberInline(
              pNode,
              (Scaleform::GFx::AS3::CheckResult *)&resulta,
              (long double *)&str)->Result
        || !Scaleform::GFx::AS3::Value::Convert2NumberInline(sm, &v20, (long double *)hint)->Result )
      {
        result->Result = 0;
        return result;
      }
      Scaleform::GFx::AS3::Value::SetNumber(retaddr, *(double *)hint + *(double *)&str.pNode);
      goto LABEL_17;
    }
    la.Flags = 0;
    la.Bonus.pWeakProxy = 0i64;
    v24.Flags = 0;
    v24.Bonus.pWeakProxy = 0i64;
    if ( Scaleform::GFx::AS3::Value::Convert2PrimitiveValueUnsafe(
           pNode,
           (Scaleform::GFx::AS3::CheckResult *)&resulta,
           *(Scaleform::GFx::ASStringManager **)&sm[16].Flags,
           &la,
           hintNone)->Result
      && (hint[0] = hintNone,
          Scaleform::GFx::AS3::Value::Convert2PrimitiveValueUnsafe(
            sm,
            &v20,
            *(Scaleform::GFx::ASStringManager **)hint,
            &v24,
            hintNone)->Result) )
    {
      Scaleform::GFx::AS3::Add(result, sma, retaddr, &la, &v24);
    }
    else
    {
      result->Result = 0;
    }
    if ( (v24.Flags & 0x1F) > 9 )
    {
      if ( (v24.Flags & 0x200) != 0 )
      {
        v13 = v24.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v13 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&v24.Bonus, 0, 24);
        v24.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v24);
      }
    }
    if ( (la.Flags & 0x1F) > 9 )
    {
      if ( (la.Flags & 0x200) != 0 )
      {
        v13 = la.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v13 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&la.Bonus, 0, 24);
        la.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&la);
      }
    }
  }
  return result;
}

// File Line: 113
// RVA: 0x847330
__int64 __fastcall Scaleform::GFx::AS3::VM::exec_throw(
        Scaleform::GFx::AS3::VM *this,
        const unsigned __int64 *cp,
        Scaleform::GFx::AS3::CallFrame *cf)
{
  Scaleform::GFx::AS3::Value *p_ExceptionObj; // rbx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  Scaleform::GFx::AS3::Value *pCurrent; // rcx
  Scaleform::ArrayLH_POD<unsigned __int64,338,Scaleform::ArrayDefaultPolicy> *OpCode; // rax

  p_ExceptionObj = &this->ExceptionObj;
  if ( (this->ExceptionObj.Flags & 0x1F) > 9 )
  {
    if ( (this->ExceptionObj.Flags & 0x200) != 0 )
    {
      pWeakProxy = this->ExceptionObj.Bonus.pWeakProxy;
      if ( pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      p_ExceptionObj->Flags &= 0xFFFFFDE0;
      p_ExceptionObj->Bonus.pWeakProxy = 0i64;
      p_ExceptionObj->value.VS._1.VStr = 0i64;
      p_ExceptionObj->value.VS._2.VObj = 0i64;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&this->ExceptionObj);
    }
  }
  pCurrent = this->OpStack.pCurrent;
  p_ExceptionObj->Flags = pCurrent->Flags;
  p_ExceptionObj->Bonus.pWeakProxy = pCurrent->Bonus.pWeakProxy;
  p_ExceptionObj->value.VS._1.VStr = pCurrent->value.VS._1.VStr;
  p_ExceptionObj->value.VS._2.VObj = pCurrent->value.VS._2.VObj;
  --this->OpStack.pCurrent;
  OpCode = Scaleform::GFx::AS3::VMAbcFile::GetOpCode(cf->pFile, cf);
  return Scaleform::GFx::AS3::VM::OnException(this, cp - OpCode->Data.Data, cf);
}

// File Line: 135
// RVA: 0x83EF80
void __fastcall Scaleform::GFx::AS3::VM::exec_dxnslate(Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::Value *pCurrent; // rsi
  Scaleform::GFx::AS3::Instances::fl::Namespace *VNs; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *p_DefXMLNamespace; // rsi
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // rcx
  unsigned int RefCount; // eax
  unsigned int v7; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *pV; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *v10; // rsi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v11; // rcx
  unsigned int v12; // eax
  unsigned int v13; // eax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v15; // zf
  Scaleform::GFx::AS3::Value *v16; // rbx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v18; // [rsp+60h] [rbp+8h] BYREF
  Scaleform::GFx::ASString result; // [rsp+68h] [rbp+10h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> v20; // [rsp+70h] [rbp+18h] BYREF

  pCurrent = this->OpStack.pCurrent;
  if ( (pCurrent->Flags & 0x1F) == 11 )
  {
    VNs = pCurrent->value.VS._1.VNs;
    v18 = VNs;
    if ( VNs )
      VNs->RefCount = (VNs->RefCount + 1) & 0x8FBFFFFF;
    p_DefXMLNamespace = &this->DefXMLNamespace;
    if ( &v18 != (Scaleform::GFx::AS3::Instances::fl::Namespace **)&this->DefXMLNamespace )
    {
      if ( VNs )
        VNs->RefCount = (VNs->RefCount + 1) & 0x8FBFFFFF;
      pObject = p_DefXMLNamespace->pObject;
      if ( p_DefXMLNamespace->pObject )
      {
        if ( ((unsigned __int8)pObject & 1) != 0 )
        {
          p_DefXMLNamespace->pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)pObject - 1);
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
      p_DefXMLNamespace->pObject = VNs;
    }
    if ( VNs )
    {
      if ( ((unsigned __int8)VNs & 1) != 0 )
      {
        v18 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)VNs - 1);
      }
      else
      {
        v7 = VNs->RefCount;
        if ( (v7 & 0x3FFFFF) != 0 )
        {
          VNs->RefCount = v7 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(VNs);
        }
      }
    }
  }
  else
  {
    Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
      this->StringManagerRef,
      &result);
    if ( Scaleform::GFx::AS3::Value::Convert2String(pCurrent, (Scaleform::GFx::AS3::CheckResult *)&v18, &result)->Result
      && result.pNode->Size )
    {
      if ( (_S11_12 & 1) == 0 )
      {
        _S11_12 |= 1u;
        v.Flags = 0;
        v.Bonus.pWeakProxy = 0i64;
        atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
      }
      Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::MakeInstance(
        (Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *)this->TraitsNamespace.pObject->ITraits.pObject,
        &v20,
        NS_Public,
        &result,
        &v);
      pV = v20.pV;
      v18 = v20.pV;
      v10 = &this->DefXMLNamespace;
      if ( &v18 != (Scaleform::GFx::AS3::Instances::fl::Namespace **)&this->DefXMLNamespace )
      {
        if ( v20.pV )
          v20.pV->RefCount = (v20.pV->RefCount + 1) & 0x8FBFFFFF;
        v11 = v10->pObject;
        if ( v10->pObject )
        {
          if ( ((unsigned __int8)v11 & 1) != 0 )
          {
            v10->pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v11 - 1);
          }
          else
          {
            v12 = v11->RefCount;
            if ( (v12 & 0x3FFFFF) != 0 )
            {
              v11->RefCount = v12 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v11);
            }
          }
        }
        v10->pObject = pV;
      }
      if ( pV )
      {
        if ( ((unsigned __int8)pV & 1) != 0 )
        {
          v18 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)pV - 1);
        }
        else
        {
          v13 = pV->RefCount;
          if ( (v13 & 0x3FFFFF) != 0 )
          {
            pV->RefCount = v13 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pV);
          }
        }
      }
    }
    pNode = result.pNode;
    v15 = result.pNode->RefCount-- == 1;
    if ( v15 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  v16 = this->OpStack.pCurrent;
  if ( (v16->Flags & 0x1F) > 9 )
  {
    if ( (v16->Flags & 0x200) != 0 )
    {
      pWeakProxy = v16->Bonus.pWeakProxy;
      v15 = pWeakProxy->RefCount-- == 1;
      if ( v15 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v16->Bonus.pWeakProxy = 0i64;
      v16->value.VS._1.VStr = 0i64;
      v16->value.VS._2.VObj = 0i64;
      v16->Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(this->OpStack.pCurrent);
    }
  }
  --this->OpStack.pCurrent;
}

// File Line: 684
// RVA: 0x846000
void __fastcall Scaleform::GFx::AS3::VM::exec_pushwith(Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::Value *pCurrent; // rdi
  int v3; // edx
  Scaleform::GFx::AS3::Value *v4; // rdx
  Scaleform::GFx::AS3::Value::V1U VObj; // rax
  Scaleform::GFx::AS3::Value *v6; // r14
  Scaleform::GFx::AS3::Value *v7; // rdi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  bool v9; // zf
  bool v10; // bl
  Scaleform::GFx::AS3::VM::Error *v11; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v13; // [rsp+28h] [rbp-30h] BYREF

  pCurrent = this->OpStack.pCurrent;
  v3 = pCurrent->Flags & 0x1F;
  if ( v3 && ((unsigned int)(v3 - 12) > 3 && v3 != 10 || pCurrent->value.VS._1.VStr) )
  {
    if ( (_S11_12 & 1) == 0 )
    {
      _S11_12 |= 1u;
      v.Flags = 0;
      v.Bonus.pWeakProxy = 0i64;
      atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
    }
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &this->ScopeStack.Data,
      (__int64 *)this->ScopeStack.Data.pHeap,
      this->ScopeStack.Data.Size + 1);
    v4 = &this->ScopeStack.Data.Data[this->ScopeStack.Data.Size - 1];
    if ( !v4 )
      goto LABEL_20;
    v4->Flags = v.Flags;
    v4->Bonus.pWeakProxy = v.Bonus.pWeakProxy;
    v4->value = v.value;
    if ( (v.Flags & 0x1F) <= 9 )
      goto LABEL_20;
    if ( (v.Flags & 0x200) != 0 )
    {
      ++v.Bonus.pWeakProxy->RefCount;
    }
    else
    {
      if ( (v.Flags & 0x1F) == 10 )
      {
        ++v.value.VS._1.VStr->RefCount;
        goto LABEL_20;
      }
      if ( (v.Flags & 0x1F) > 0xA )
      {
        if ( (v.Flags & 0x1F) <= 0xF )
        {
          VObj = v.value.VS._1;
        }
        else
        {
          if ( (v.Flags & 0x1F) > 0x11 )
            goto LABEL_20;
          VObj = (Scaleform::GFx::AS3::Value::V1U)v.value.VS._2.VObj;
        }
        if ( VObj.VStr )
        {
          ++VObj.VStr->Size;
          VObj.VStr->Size &= 0x8FBFFFFF;
        }
      }
    }
LABEL_20:
    v6 = &this->ScopeStack.Data.Data[this->ScopeStack.Data.Size];
    _mm_prefetch((const char *)pCurrent, 2);
    *(_QWORD *)&v6[-1].Flags = *(_QWORD *)&pCurrent->Flags;
    v6[-1].Bonus.pWeakProxy = pCurrent->Bonus.pWeakProxy;
    v6[-1].value.VS._1.VStr = pCurrent->value.VS._1.VStr;
    v6[-1].value.VS._2.VObj = pCurrent->value.VS._2.VObj;
    pCurrent->Flags = 0;
    v7 = this->OpStack.pCurrent;
    if ( (v7->Flags & 0x1F) > 9 )
    {
      if ( (v7->Flags & 0x200) != 0 )
      {
        pWeakProxy = v7->Bonus.pWeakProxy;
        v9 = pWeakProxy->RefCount-- == 1;
        if ( v9 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        v7->Bonus.pWeakProxy = 0i64;
        v7->value.VS._1.VStr = 0i64;
        v7->value.VS._2.VObj = 0i64;
        v7->Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(this->OpStack.pCurrent);
      }
    }
    --this->OpStack.pCurrent;
    v6[-1].Flags |= 0x100u;
    return;
  }
  v10 = ((unsigned int)(v3 - 12) <= 3 || v3 == 10) && !pCurrent->value.VS._1.VStr;
  Scaleform::GFx::AS3::VM::Error::Error(&v13, 1010 - v10, this);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v11, &Scaleform::GFx::AS3::fl::TypeErrorTI);
  pNode = v13.Message.pNode;
  v9 = v13.Message.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 713
// RVA: 0x844190
void __fastcall Scaleform::GFx::AS3::VM::exec_nextname(Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::Value *pCurrent; // rbx
  bool v3; // zf
  Scaleform::GFx::AS3::Value::VU *p_value; // rax
  bool v5; // r14
  Scaleform::GFx::AS3::GlobalSlotIndex v6; // ebp
  Scaleform::GFx::AS3::Value *v7; // rbx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  Scaleform::GFx::AS3::Instances::fl::Namespace *VNs; // rcx
  Scaleform::GFx::AS3::Value *v10; // rdx
  int result; // [rsp+40h] [rbp+8h] BYREF

  result = 0;
  pCurrent = this->OpStack.pCurrent;
  v3 = !Scaleform::GFx::AS3::Value::ToInt32Value(pCurrent, (Scaleform::GFx::AS3::CheckResult *)&result)->Result;
  p_value = &pCurrent->value;
  v5 = !v3;
  if ( v3 )
    p_value = (Scaleform::GFx::AS3::Value::VU *)&`Scaleform::GFx::AS3::ToType<long>::`2::tmp;
  v6.Index = p_value->VS._1.VInt;
  v7 = this->OpStack.pCurrent;
  if ( (v7->Flags & 0x1F) > 9 )
  {
    if ( (v7->Flags & 0x200) != 0 )
    {
      pWeakProxy = v7->Bonus.pWeakProxy;
      v3 = pWeakProxy->RefCount-- == 1;
      if ( v3 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v7->Flags &= 0xFFFFFDE0;
      v7->Bonus.pWeakProxy = 0i64;
      v7->value.VS._1.VStr = 0i64;
      v7->value.VS._2.VObj = 0i64;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(this->OpStack.pCurrent);
    }
  }
  --this->OpStack.pCurrent;
  if ( v5 )
  {
    VNs = v7[-1].value.VS._1.VNs;
    v10 = v7 - 1;
    if ( (v7[-1].Flags & 0x1F) == 11 )
      Scaleform::GFx::AS3::Instances::fl::Namespace::GetNextPropertyName(VNs, v10, v6);
    else
      VNs->vfptr[5].ForEachChild_GC(
        VNs,
        (Scaleform::GFx::AS3::RefCountCollector<328> *)v10,
        (void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))v6.Index);
  }
}

// File Line: 852
// RVA: 0x845900
void __fastcall Scaleform::GFx::AS3::VM::exec_pushscope(Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::Value *pCurrent; // rdi
  int v3; // edx
  Scaleform::GFx::AS3::Value *v4; // rdx
  Scaleform::GFx::AS3::Value::V1U VObj; // rax
  Scaleform::GFx::AS3::Value *v6; // rdx
  Scaleform::GFx::AS3::Value *v7; // rdi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  bool v9; // zf
  bool v10; // bl
  Scaleform::GFx::AS3::VM::Error *v11; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v13; // [rsp+28h] [rbp-30h] BYREF

  pCurrent = this->OpStack.pCurrent;
  v3 = pCurrent->Flags & 0x1F;
  if ( v3 && ((unsigned int)(v3 - 12) > 3 && v3 != 10 || pCurrent->value.VS._1.VStr) )
  {
    if ( (_S11_12 & 1) == 0 )
    {
      _S11_12 |= 1u;
      v.Flags = 0;
      v.Bonus.pWeakProxy = 0i64;
      atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
    }
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &this->ScopeStack.Data,
      (__int64 *)this->ScopeStack.Data.pHeap,
      this->ScopeStack.Data.Size + 1);
    v4 = &this->ScopeStack.Data.Data[this->ScopeStack.Data.Size - 1];
    if ( !v4 )
      goto LABEL_20;
    v4->Flags = v.Flags;
    v4->Bonus.pWeakProxy = v.Bonus.pWeakProxy;
    v4->value = v.value;
    if ( (v.Flags & 0x1F) <= 9 )
      goto LABEL_20;
    if ( (v.Flags & 0x200) != 0 )
    {
      ++v.Bonus.pWeakProxy->RefCount;
    }
    else
    {
      if ( (v.Flags & 0x1F) == 10 )
      {
        ++v.value.VS._1.VStr->RefCount;
        goto LABEL_20;
      }
      if ( (v.Flags & 0x1F) > 0xA )
      {
        if ( (v.Flags & 0x1F) <= 0xF )
        {
          VObj = v.value.VS._1;
        }
        else
        {
          if ( (v.Flags & 0x1F) > 0x11 )
            goto LABEL_20;
          VObj = (Scaleform::GFx::AS3::Value::V1U)v.value.VS._2.VObj;
        }
        if ( VObj.VStr )
        {
          ++VObj.VStr->Size;
          VObj.VStr->Size &= 0x8FBFFFFF;
        }
      }
    }
LABEL_20:
    v6 = &this->ScopeStack.Data.Data[this->ScopeStack.Data.Size];
    _mm_prefetch((const char *)pCurrent, 2);
    *(_QWORD *)&v6[-1].Flags = *(_QWORD *)&pCurrent->Flags;
    v6[-1].Bonus.pWeakProxy = pCurrent->Bonus.pWeakProxy;
    v6[-1].value.VS._1.VStr = pCurrent->value.VS._1.VStr;
    v6[-1].value.VS._2.VObj = pCurrent->value.VS._2.VObj;
    pCurrent->Flags = 0;
    v7 = this->OpStack.pCurrent;
    if ( (v7->Flags & 0x1F) > 9 )
    {
      if ( (v7->Flags & 0x200) != 0 )
      {
        pWeakProxy = v7->Bonus.pWeakProxy;
        v9 = pWeakProxy->RefCount-- == 1;
        if ( v9 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        v7->Bonus.pWeakProxy = 0i64;
        v7->value.VS._1.VStr = 0i64;
        v7->value.VS._2.VObj = 0i64;
        v7->Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(this->OpStack.pCurrent);
      }
    }
    --this->OpStack.pCurrent;
    return;
  }
  v10 = ((unsigned int)(v3 - 12) <= 3 || v3 == 10) && !pCurrent->value.VS._1.VStr;
  Scaleform::GFx::AS3::VM::Error::Error(&v13, 1010 - v10, this);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v11, &Scaleform::GFx::AS3::fl::TypeErrorTI);
  pNode = v13.Message.pNode;
  v9 = v13.Message.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 999
// RVA: 0x842E00
void __fastcall Scaleform::GFx::AS3::VM::exec_newactivation(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::CallFrame *cf)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *ActivationInstanceTraits; // rdi
  Scaleform::GFx::AS3::Instance *v4; // rax
  Scaleform::GFx::AS3::Value::V1U v5; // rax
  Scaleform::GFx::AS3::Value::V1U v6; // rcx
  bool v7; // zf
  Scaleform::GFx::AS3::Value *pCurrent; // rax
  Scaleform::GFx::AS3::Value v9; // [rsp+28h] [rbp-30h] BYREF
  Scaleform::GFx::AS3::Value *v10; // [rsp+60h] [rbp+8h] BYREF
  void *v11; // [rsp+68h] [rbp+10h]
  Scaleform::GFx::AS3::Instance *v12; // [rsp+70h] [rbp+18h]

  ActivationInstanceTraits = Scaleform::GFx::AS3::VMFile::GetActivationInstanceTraits(cf->pFile, cf->MBIIndex);
  LODWORD(v10) = 337;
  v4 = (Scaleform::GFx::AS3::Instance *)ActivationInstanceTraits->pVM->MHeap->vfptr->Alloc(
                                          ActivationInstanceTraits->pVM->MHeap,
                                          ActivationInstanceTraits->MemSize,
                                          (Scaleform::AllocInfo *)&v10);
  v11 = v4;
  v12 = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instance::Instance(v4, ActivationInstanceTraits);
    v6 = v5;
  }
  else
  {
    v6.VStr = 0i64;
  }
  v9.Bonus.pWeakProxy = 0i64;
  v9.Flags = 12;
  v9.value = (Scaleform::GFx::AS3::Value::VU)(unsigned __int64)v6.VStr;
  v7 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-32i64;
  pCurrent = this->OpStack.pCurrent;
  v10 = pCurrent;
  v11 = pCurrent;
  if ( !v7 )
  {
    pCurrent->Flags = 12;
    pCurrent->Bonus.pWeakProxy = 0i64;
    pCurrent->value.VS._1 = v6;
    pCurrent->value.VS._2.VObj = 0i64;
    if ( v6.VStr )
      v6.VStr->Size = (v6.VStr->Size + 1) & 0x8FBFFFFF;
  }
  Scaleform::GFx::AS3::Value::ReleaseInternal(&v9);
}

// File Line: 1082
// RVA: 0x840D90
void __fastcall Scaleform::GFx::AS3::VM::exec_getscopeobject(Scaleform::GFx::AS3::VM *this, unsigned int index)
{
  Scaleform::GFx::AS3::Value *v3; // r8
  bool v4; // zf
  Scaleform::GFx::AS3::Value *pCurrent; // rdx
  Scaleform::GFx::AS3::Value::V1U VObj; // rcx

  v3 = &this->ScopeStack.Data.Data[index];
  v4 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-32i64;
  pCurrent = this->OpStack.pCurrent;
  if ( !v4 )
  {
    pCurrent->Flags = v3->Flags;
    pCurrent->Bonus.pWeakProxy = v3->Bonus.pWeakProxy;
    pCurrent->value.VS._1.VStr = v3->value.VS._1.VStr;
    pCurrent->value.VS._2.VObj = v3->value.VS._2.VObj;
    if ( (v3->Flags & 0x1F) > 9 )
    {
      if ( (v3->Flags & 0x200) != 0 )
      {
        ++v3->Bonus.pWeakProxy->RefCount;
      }
      else
      {
        if ( (v3->Flags & 0x1F) == 10 )
        {
          ++v3->value.VS._1.VStr->RefCount;
          goto LABEL_14;
        }
        if ( (v3->Flags & 0x1F) > 0xA )
        {
          if ( (v3->Flags & 0x1F) <= 0xF )
          {
            VObj = v3->value.VS._1;
          }
          else
          {
            if ( (v3->Flags & 0x1F) > 0x11 )
              goto LABEL_14;
            VObj = (Scaleform::GFx::AS3::Value::V1U)v3->value.VS._2.VObj;
          }
          if ( VObj.VStr )
            VObj.VStr->Size = (VObj.VStr->Size + 1) & 0x8FBFFFFF;
        }
      }
    }
  }
LABEL_14:
  this->OpStack.pCurrent->Flags &= ~0x100u;
}

// File Line: 1090
// RVA: 0x840990
void __fastcall Scaleform::GFx::AS3::VM::exec_getouterscope(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::CallFrame *cf,
        unsigned int scope_index)
{
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *pSavedScope; // rax
  Scaleform::GFx::AS3::VM::Error *v5; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v7; // zf
  __int64 v8; // rdx
  Scaleform::GFx::AS3::Value *pCurrent; // rcx
  __int64 v10; // rcx
  Scaleform::GFx::AS3::VM::Error v11; // [rsp+28h] [rbp-20h] BYREF

  pSavedScope = cf->pSavedScope;
  if ( scope_index < pSavedScope->Data.Size )
  {
    v8 = (__int64)&pSavedScope->Data.Data[scope_index];
    v7 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-32i64;
    pCurrent = this->OpStack.pCurrent;
    if ( !v7 )
    {
      pCurrent->Flags = *(_DWORD *)v8;
      pCurrent->Bonus.pWeakProxy = *(Scaleform::GFx::AS3::WeakProxy **)(v8 + 8);
      pCurrent->value.VS._1.VStr = *(Scaleform::GFx::ASStringNode **)(v8 + 16);
      pCurrent->value.VS._2.VObj = *(Scaleform::GFx::AS3::Object **)(v8 + 24);
      if ( (*(_DWORD *)v8 & 0x1Fu) > 9 )
      {
        if ( (*(_DWORD *)v8 & 0x200) != 0 )
        {
          ++**(_DWORD **)(v8 + 8);
          return;
        }
        if ( (*(_DWORD *)v8 & 0x1F) == 10 )
        {
          ++*(_DWORD *)(*(_QWORD *)(v8 + 16) + 24i64);
        }
        else
        {
          if ( (*(_DWORD *)v8 & 0x1Fu) <= 0xA )
            return;
          if ( (*(_DWORD *)v8 & 0x1Fu) <= 0xF )
          {
            v10 = *(_QWORD *)(v8 + 16);
          }
          else
          {
            if ( (*(_DWORD *)v8 & 0x1Fu) > 0x11 )
              return;
            v10 = *(_QWORD *)(v8 + 24);
          }
          if ( v10 )
            *(_DWORD *)(v10 + 32) = (*(_DWORD *)(v10 + 32) + 1) & 0x8FBFFFFF;
        }
      }
    }
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v11, 2006, this);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v5, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
    pNode = v11.Message.pNode;
    v7 = v11.Message.pNode->RefCount-- == 1;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 1107
// RVA: 0x840310
void __fastcall Scaleform::GFx::AS3::VM::exec_getglobalslot(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::SlotIndex slot_index)
{
  Scaleform::GFx::AS3::Object *v4; // rbx
  bool v5; // zf
  Scaleform::GFx::AS3::Value *pCurrent; // rcx
  Scaleform::GFx::AS3::Value::V1U VObj; // rax
  Scaleform::GFx::AS3::CallFrame *v8; // rdx
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *pSavedScope; // rax
  Scaleform::GFx::AS3::Value *pRF; // rcx
  Scaleform::GFx::AS3::CheckResult result; // [rsp+58h] [rbp+10h] BYREF
  Scaleform::GFx::AS3::Value *v12; // [rsp+60h] [rbp+18h]

  v4 = 0i64;
  if ( (_S11_12 & 1) == 0 )
  {
    _S11_12 |= 1u;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0i64;
    atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  v5 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-32i64;
  pCurrent = this->OpStack.pCurrent;
  v12 = pCurrent;
  if ( !v5 )
  {
    pCurrent->Flags = v.Flags;
    pCurrent->Bonus.pWeakProxy = v.Bonus.pWeakProxy;
    pCurrent->value = v.value;
    if ( (v.Flags & 0x1F) > 9 )
    {
      if ( (v.Flags & 0x200) != 0 )
      {
        ++v.Bonus.pWeakProxy->RefCount;
        goto LABEL_16;
      }
      if ( (v.Flags & 0x1F) == 10 )
      {
        ++v.value.VS._1.VStr->RefCount;
      }
      else
      {
        if ( (v.Flags & 0x1F) <= 0xA )
          goto LABEL_16;
        if ( (v.Flags & 0x1F) <= 0xF )
        {
          VObj = v.value.VS._1;
        }
        else
        {
          if ( (v.Flags & 0x1F) > 0x11 )
            goto LABEL_16;
          VObj = (Scaleform::GFx::AS3::Value::V1U)v.value.VS._2.VObj;
        }
        if ( VObj.VStr )
        {
          ++VObj.VStr->Size;
          VObj.VStr->Size &= 0x8FBFFFFF;
        }
      }
    }
  }
LABEL_16:
  if ( this->CallStack.Size )
  {
    v8 = &this->CallStack.Pages[(this->CallStack.Size - 1) >> 6][(LODWORD(this->CallStack.Size) - 1) & 0x3F];
    pSavedScope = v8->pSavedScope;
    if ( pSavedScope->Data.Size )
    {
      v4 = pSavedScope->Data.Data->value.VS._1.VObj;
    }
    else
    {
      pRF = v8->pRegisterFile->pRF;
      if ( (pRF->Flags & 0x1F) - 12 <= 3 )
        v4 = pRF->value.VS._1.VObj;
    }
  }
  Scaleform::GFx::AS3::Object::GetSlotValueUnsafe(v4, &result, slot_index, this->OpStack.pCurrent);
}

// File Line: 1116
// RVA: 0x846620
void __fastcall Scaleform::GFx::AS3::VM::exec_setglobalslot(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::SlotIndex slot_index)
{
  Scaleform::GFx::AS3::CallFrame *v3; // rcx
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *pSavedScope; // rax
  Scaleform::GFx::AS3::Object *VObj; // rcx
  Scaleform::GFx::AS3::Value *pRF; // rcx
  Scaleform::GFx::AS3::Value *pCurrent; // rdi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  Scaleform::GFx::AS3::CheckResult result; // [rsp+38h] [rbp+10h] BYREF

  if ( !this->CallStack.Size )
    goto LABEL_6;
  v3 = &this->CallStack.Pages[(this->CallStack.Size - 1) >> 6][(LODWORD(this->CallStack.Size) - 1) & 0x3F];
  pSavedScope = v3->pSavedScope;
  if ( pSavedScope->Data.Size )
  {
    VObj = pSavedScope->Data.Data->value.VS._1.VObj;
    goto LABEL_7;
  }
  pRF = v3->pRegisterFile->pRF;
  if ( (pRF->Flags & 0x1F) - 12 <= 3 )
    VObj = pRF->value.VS._1.VObj;
  else
LABEL_6:
    VObj = 0i64;
LABEL_7:
  Scaleform::GFx::AS3::Object::SetSlotValue(VObj, &result, slot_index, this->OpStack.pCurrent);
  pCurrent = this->OpStack.pCurrent;
  if ( (pCurrent->Flags & 0x1F) <= 9 )
  {
LABEL_13:
    --this->OpStack.pCurrent;
    return;
  }
  if ( (pCurrent->Flags & 0x200) == 0 )
  {
    Scaleform::GFx::AS3::Value::ReleaseInternal(this->OpStack.pCurrent);
    goto LABEL_13;
  }
  pWeakProxy = pCurrent->Bonus.pWeakProxy;
  if ( pWeakProxy->RefCount-- == 1 )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  pCurrent->Flags &= 0xFFFFFDE0;
  pCurrent->Bonus.pWeakProxy = 0i64;
  pCurrent->value.VS._1.VStr = 0i64;
  pCurrent->value.VS._2.VObj = 0i64;
  --this->OpStack.pCurrent;
}

// File Line: 1134
// RVA: 0x83F370
void __fastcall Scaleform::GFx::AS3::VM::exec_esc_xelem(Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::XMLSupport *pObject; // rcx
  Scaleform::GFx::AS3::VM::Error *v3; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v6; // [rsp+28h] [rbp-20h] BYREF
  char v7; // [rsp+50h] [rbp+8h] BYREF

  pObject = this->XMLSupport_.pObject;
  if ( pObject->Enabled )
  {
    ((void (__fastcall *)(Scaleform::GFx::AS3::XMLSupport *, char *, Scaleform::GFx::AS3::VM *, Scaleform::GFx::AS3::Value *, __int64))pObject->vfptr[2].Finalize_GC)(
      pObject,
      &v7,
      this,
      this->OpStack.pCurrent,
      -2i64);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v6, 1001, this);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v3, &Scaleform::GFx::AS3::fl::VerifyErrorTI);
    pNode = v6.Message.pNode;
    if ( v6.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 1154
// RVA: 0x83F250
void __fastcall Scaleform::GFx::AS3::VM::exec_esc_xattr(Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // rdi
  Scaleform::GFx::AS3::Value *pCurrent; // rbx
  Scaleform::GFx::ASString *v3; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v5; // zf
  char *pData; // r8
  Scaleform::GFx::ASString *v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx
  Scaleform::StringBuffer buf; // [rsp+28h] [rbp-40h] BYREF
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+8h] BYREF

  StringManagerRef = this->StringManagerRef;
  pCurrent = this->OpStack.pCurrent;
  if ( Scaleform::GFx::AS3::Value::ToStringValue(
         pCurrent,
         (Scaleform::GFx::AS3::CheckResult *)&result,
         StringManagerRef)->Result )
  {
    Scaleform::StringBuffer::StringBuffer(&buf, Scaleform::Memory::pGlobalHeap);
    v3 = Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(pCurrent, &result);
    Scaleform::GFx::AS3::Instances::fl::XML::EscapeElementValue(&buf, v3);
    pNode = result.pNode;
    v5 = result.pNode->RefCount-- == 1;
    if ( v5 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    pData = &customCaption;
    if ( buf.pData )
      pData = buf.pData;
    v7 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
           StringManagerRef,
           &result,
           pData,
           buf.Size);
    Scaleform::GFx::AS3::Value::Assign(pCurrent, v7);
    v8 = result.pNode;
    v5 = result.pNode->RefCount-- == 1;
    if ( v5 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
    Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&buf);
  }
}

// File Line: 1228
// RVA: 0x83D260
void __fastcall Scaleform::GFx::AS3::VM::exec_checkfilter(Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::Value *pCurrent; // r8
  int v3; // edx
  Scaleform::GFx::AS3::Value::V1U v4; // rax
  const char *v5; // rcx
  Scaleform::GFx::AS3::Value::V1U v6; // rax
  const char *pData; // rcx
  Scaleform::GFx::AS3::VM::Error *v8; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v11; // [rsp+28h] [rbp-20h] BYREF

  pCurrent = this->OpStack.pCurrent;
  v3 = pCurrent->Flags & 0x1F;
  if ( (unsigned int)(v3 - 12) > 3
    || (v4 = pCurrent->value.VS._1, !v4.VStr)
    || (v5 = v4.VStr[1].pData, *((_DWORD *)v5 + 30) != 18)
    || (v5[112] & 0x20) != 0 )
  {
    if ( (unsigned int)(v3 - 12) > 3
      || (v6 = pCurrent->value.VS._1, !v6.VStr)
      || (pData = v6.VStr[1].pData, *((_DWORD *)pData + 30) != 19)
      || (pData[112] & 0x20) != 0 )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v11, 1123, this);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v8, &Scaleform::GFx::AS3::fl::TypeErrorTI);
      pNode = v11.Message.pNode;
      if ( v11.Message.pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
  }
}

// File Line: 1985
// RVA: 0x847400
void __fastcall Scaleform::GFx::AS3::VM::exec_typeof(Scaleform::GFx::AS3::VM *this)
{
  __int64 v1; // rdi
  Scaleform::GFx::AS3::Value *pCurrent; // rbx
  int v4; // eax
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // rcx
  Scaleform::GFx::AS3::Value::V1U pNode; // rdx
  unsigned int Flags; // ebx
  Scaleform::GFx::AS3::Value other; // [rsp+28h] [rbp-30h] BYREF
  __int64 v10; // [rsp+50h] [rbp-8h]

  v10 = v1;
  pCurrent = this->OpStack.pCurrent;
  switch ( pCurrent->Flags & 0x1F )
  {
    case 0u:
      v4 = 1;
      break;
    case 1u:
      v4 = 6;
      break;
    case 2u:
    case 3u:
    case 4u:
      v4 = 7;
      break;
    case 5u:
    case 7u:
    case 0xEu:
    case 0xFu:
    case 0x10u:
    case 0x11u:
      v4 = 9;
      break;
    case 0xAu:
      v4 = 10;
      if ( pCurrent->value.VS._1.VStr )
        v4 = 8;
      break;
    case 0xBu:
    case 0xCu:
      v4 = ((unsigned int)(Scaleform::GFx::AS3::VM::GetValueTraits(this, pCurrent)->TraitsType - 18) <= 1) + 10;
      break;
    default:
      v4 = 12;
      break;
  }
  StringManagerRef = this->StringManagerRef;
  other.Flags = 10;
  other.Bonus.pWeakProxy = 0i64;
  pNode = (Scaleform::GFx::AS3::Value::V1U)StringManagerRef->Builtins[v4].pNode;
  other.value.VS._1 = pNode;
  if ( pNode.VStr == &pNode.VStr->pManager->NullStringNode )
  {
    other.value.VS._1.VStr = 0i64;
    other.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)other.Bonus.pWeakProxy;
    other.Flags = 12;
  }
  else
  {
    ++pNode.VStr->RefCount;
  }
  Scaleform::GFx::AS3::Value::Assign(pCurrent, &other);
  Flags = other.Flags;
  if ( (other.Flags & 0x1F) > 9 )
  {
    if ( (other.Flags & 0x200) != 0 )
    {
      if ( other.Bonus.pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&other.Bonus, 0, 24);
      other.Flags = Flags & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
    }
  }
}

// File Line: 2042
// RVA: 0x841D70
void __fastcall Scaleform::GFx::AS3::VM::exec_hasnext(Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::Value *pCurrent; // rbx
  bool v3; // zf
  Scaleform::GFx::AS3::Value::VU *p_value; // rax
  bool v5; // si
  unsigned int VInt; // r14d
  Scaleform::GFx::AS3::Value *v7; // rbx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  int *v9; // rax
  int result; // [rsp+40h] [rbp+8h] BYREF

  result = 0;
  pCurrent = this->OpStack.pCurrent;
  v3 = !Scaleform::GFx::AS3::Value::ToInt32Value(pCurrent, (Scaleform::GFx::AS3::CheckResult *)&result)->Result;
  p_value = &pCurrent->value;
  v5 = !v3;
  if ( v3 )
    p_value = (Scaleform::GFx::AS3::Value::VU *)&`Scaleform::GFx::AS3::ToType<long>::`2::tmp;
  VInt = p_value->VS._1.VInt;
  v7 = this->OpStack.pCurrent;
  if ( (v7->Flags & 0x1F) > 9 )
  {
    if ( (v7->Flags & 0x200) != 0 )
    {
      pWeakProxy = v7->Bonus.pWeakProxy;
      v3 = pWeakProxy->RefCount-- == 1;
      if ( v3 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v7->Flags &= 0xFFFFFDE0;
      v7->Bonus.pWeakProxy = 0i64;
      v7->value.VS._1.VStr = 0i64;
      v7->value.VS._2.VObj = 0i64;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(this->OpStack.pCurrent);
    }
  }
  --this->OpStack.pCurrent;
  if ( v5 )
  {
    v9 = (int *)(*((__int64 (__fastcall **)(Scaleform::GFx::AS3::Value::V1U, int *, _QWORD))v7[-1].value.VS._1.VStr->pData
                 + 16))(
                  v7[-1].value.VS._1,
                  &result,
                  VInt);
    Scaleform::GFx::AS3::Value::SetUInt32(v7 - 1, *v9);
  }
}

// File Line: 2055
// RVA: 0x844340
void __fastcall Scaleform::GFx::AS3::VM::exec_nextvalue(Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::Value *pCurrent; // rbx
  bool v3; // zf
  Scaleform::GFx::AS3::Value::VU *p_value; // rax
  bool v5; // r14
  unsigned int VInt; // esi
  Scaleform::GFx::AS3::Value *v7; // rbx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  Scaleform::GFx::AS3::Value::V1U v9; // rdx
  unsigned int v10; // esi
  int result; // [rsp+40h] [rbp+8h] BYREF

  result = 0;
  pCurrent = this->OpStack.pCurrent;
  v3 = !Scaleform::GFx::AS3::Value::ToInt32Value(pCurrent, (Scaleform::GFx::AS3::CheckResult *)&result)->Result;
  p_value = &pCurrent->value;
  v5 = !v3;
  if ( v3 )
    p_value = (Scaleform::GFx::AS3::Value::VU *)&`Scaleform::GFx::AS3::ToType<long>::`2::tmp;
  VInt = p_value->VS._1.VInt;
  v7 = this->OpStack.pCurrent;
  if ( (v7->Flags & 0x1F) > 9 )
  {
    if ( (v7->Flags & 0x200) != 0 )
    {
      pWeakProxy = v7->Bonus.pWeakProxy;
      v3 = pWeakProxy->RefCount-- == 1;
      if ( v3 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v7->Flags &= 0xFFFFFDE0;
      v7->Bonus.pWeakProxy = 0i64;
      v7->value.VS._1.VStr = 0i64;
      v7->value.VS._2.VObj = 0i64;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(this->OpStack.pCurrent);
    }
  }
  --this->OpStack.pCurrent;
  if ( v5 )
  {
    if ( (v7[-1].Flags & 0x1F) == 11 )
    {
      v9 = v7[-1].value.VS._1;
      v10 = VInt - 1;
      if ( v10 )
      {
        if ( v10 == 1 )
          Scaleform::GFx::AS3::Value::Assign(v7 - 1, (Scaleform::GFx::AS3::Value *)&v9.VStr[1].Size);
      }
      else
      {
        Scaleform::GFx::AS3::Value::Assign(v7 - 1, (Scaleform::GFx::ASString *)&v9.VStr[1].16);
      }
    }
    else
    {
      (*((void (__fastcall **)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::AS3::Value *, _QWORD))v7[-1].value.VS._1.VStr->pData
       + 17))(
        v7[-1].value.VS._1,
        v7 - 1,
        VInt);
    }
  }
}

// File Line: 2073
// RVA: 0x8421D0
void __fastcall Scaleform::GFx::AS3::VM::exec_in(Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::Value *pCurrent; // rdx
  unsigned int Flags; // ebx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rsi
  Scaleform::GFx::AS3::Value::V1U v5; // rcx
  Scaleform::GFx::AS3::Value *v6; // r12
  int v7; // r14d
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // rcx
  Scaleform::GFx::AS3::Value::V1U v9; // r13
  const char *pData; // rax
  __int64 v11; // r8
  Scaleform::GFx::ASString *v12; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v14; // zf
  Scaleform::GFx::ASStringNode *v15; // rcx
  char v16; // al
  bool v17; // al
  Scaleform::GFx::AS3::VM::Error *v18; // rax
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::GFx::AS3::Value scope; // [rsp+30h] [rbp-79h] BYREF
  Scaleform::GFx::AS3::Value *v21; // [rsp+50h] [rbp-59h]
  Scaleform::GFx::AS3::Multiname mn; // [rsp+58h] [rbp-51h] BYREF
  Scaleform::GFx::AS3::PropRef v23; // [rsp+88h] [rbp-21h] BYREF
  __int64 v24; // [rsp+B8h] [rbp+Fh]
  Scaleform::GFx::AS3::VM::Error v25; // [rsp+C0h] [rbp+17h] BYREF
  Scaleform::GFx::ASString result; // [rsp+110h] [rbp+67h] BYREF
  Scaleform::GFx::ASString v27; // [rsp+118h] [rbp+6Fh] BYREF
  Scaleform::GFx::AS3::Value::V1U v28; // [rsp+120h] [rbp+77h]

  v24 = -2i64;
  pCurrent = this->OpStack.pCurrent;
  scope.Flags = pCurrent->Flags;
  Flags = scope.Flags;
  pWeakProxy = pCurrent->Bonus.pWeakProxy;
  scope.Bonus.pWeakProxy = pWeakProxy;
  v5 = pCurrent->value.VS._1;
  v28 = v5;
  scope.value.VS._1 = v5;
  scope.value.VS._2.VObj = pCurrent->value.VS._2.VObj;
  this->OpStack.pCurrent = pCurrent - 1;
  v6 = this->OpStack.pCurrent;
  v21 = v6;
  v7 = Flags & 0x1F;
  if ( (Flags & 0x1F) != 0 && ((unsigned int)(v7 - 12) > 3 && v7 != 10 || v5.VStr) )
  {
    pObject = this->PublicNamespace.pObject;
    mn.Kind = MN_QName;
    mn.Obj.pObject = pObject;
    if ( pObject )
      pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
    mn.Name.Flags = 0;
    mn.Name.Bonus.pWeakProxy = 0i64;
    if ( (v6->Flags & 0x1F) - 12 <= 3
      && (v9 = v6->value.VS._1, v9.VStr)
      && (pData = v9.VStr[1].pData, *((_DWORD *)pData + 30) == 17)
      && (pData[112] & 0x20) == 0 )
    {
      Scaleform::GFx::AS3::Value::Assign(&mn.Name, (Scaleform::GFx::ASString *)&v9.VStr[1].16);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&mn.Obj,
        *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&v9.VStr[1].RefCount);
      mn.Kind &= 0xFFFFFFF9;
    }
    else
    {
      Scaleform::GFx::AS3::Value::AssignUnsafe(&mn.Name, v6);
      if ( (mn.Name.Flags & 0x1F) == 10 )
      {
        Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&mn.Name, &result);
        if ( result.pNode->Size )
        {
          if ( *result.pNode->pData == 64 )
          {
            mn.Kind |= 8u;
            v12 = Scaleform::GFx::ASString::Substring(&result, &v27, 1, result.pNode->Size);
            Scaleform::GFx::AS3::Value::Assign(&mn.Name, v12);
            pNode = v27.pNode;
            v14 = v27.pNode->RefCount-- == 1;
            if ( v14 )
              Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
          }
        }
        v15 = result.pNode;
        v14 = result.pNode->RefCount-- == 1;
        if ( v14 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v15);
      }
    }
    if ( (unsigned int)(v7 - 12) > 3 )
    {
      memset(&v23, 0, 20);
      v23.This.Bonus.pWeakProxy = 0i64;
      Scaleform::GFx::AS3::FindObjProperty(&v23, this, &scope, &mn, FindGet);
      v17 = (v23.This.Flags & 0x1F) != 0
         && (((__int64)v23.pSI & 1) == 0 || ((unsigned __int64)v23.pSI & 0xFFFFFFFFFFFFFFFEui64) != 0)
         && (((__int64)v23.pSI & 2) == 0 || ((unsigned __int64)v23.pSI & 0xFFFFFFFFFFFFFFFDui64) != 0);
      Scaleform::GFx::AS3::Value::SetBool(v6, v17);
      if ( (v23.This.Flags & 0x1F) > 9 )
      {
        if ( (v23.This.Flags & 0x200) != 0 )
        {
          v14 = v23.This.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v14 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&v23.This.Bonus, 0, 24);
          v23.This.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v23.This);
        }
      }
      Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
    }
    else
    {
      LOBYTE(v11) = 1;
      v16 = (*((__int64 (__fastcall **)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::AS3::Multiname *, __int64))v28.VStr->pData
             + 6))(
              v28,
              &mn,
              v11);
      Scaleform::GFx::AS3::Value::SetBool(v6, v16);
      Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
    }
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
      {
        v14 = pWeakProxy->RefCount-- == 1;
        if ( v14 )
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
LABEL_45:
        scope.Flags = Flags & 0xFFFFFDE0;
        memset(&scope.Bonus, 0, 24);
        return;
      }
LABEL_46:
      Scaleform::GFx::AS3::Value::ReleaseInternal(&scope);
    }
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v25, 1009, this);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v18, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v19 = v25.Message.pNode;
    v14 = v25.Message.pNode->RefCount-- == 1;
    if ( v14 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v19);
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
      {
        v14 = pWeakProxy->RefCount-- == 1;
        if ( v14 )
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
        goto LABEL_45;
      }
      goto LABEL_46;
    }
  }
}

// File Line: 2120
// RVA: 0x83FC40
void __fastcall Scaleform::GFx::AS3::VM::exec_getabsslot(Scaleform::GFx::AS3::VM *this, unsigned __int64 slot_ind)
{
  Scaleform::GFx::AS3::Value *pCurrent; // rsi
  int v5; // r8d
  char v6; // al
  Scaleform::GFx::AS3::VM::Error *v7; // rax
  Scaleform::GFx::ASStringNode *pWeakProxy; // rcx
  bool v9; // zf
  unsigned int Flags; // edi
  Scaleform::GFx::AS3::WeakProxy *v11; // rbx
  Scaleform::GFx::AS3::Object *obj; // rcx
  Scaleform::GFx::AS3::Value v13; // [rsp+38h] [rbp-40h] BYREF
  Scaleform::GFx::AS3::CheckResult result; // [rsp+80h] [rbp+8h] BYREF

  pCurrent = this->OpStack.pCurrent;
  v5 = pCurrent->Flags & 0x1F;
  if ( !v5 || ((unsigned int)(v5 - 12) <= 3 || v5 == 10) && !pCurrent->value.VS._1.VStr )
  {
    if ( (unsigned int)(v5 - 12) > 3 && v5 != 10 || (v6 = 1, pCurrent->value.VS._1.VStr) )
      v6 = 0;
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v13, 1010 - (v6 != 0), this);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(this, v7, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    pWeakProxy = (Scaleform::GFx::ASStringNode *)v13.Bonus.pWeakProxy;
    v9 = LODWORD(v13.Bonus.pWeakProxy[1].pObject)-- == 1;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pWeakProxy);
  }
  if ( !this->HandleException )
  {
    v13.Flags = pCurrent->Flags;
    Flags = v13.Flags;
    v11 = pCurrent->Bonus.pWeakProxy;
    v13.Bonus.pWeakProxy = v11;
    v13.value = pCurrent->value;
    obj = v13.value.VS._1.VObj;
    pCurrent->Flags = 0;
    Scaleform::GFx::AS3::Traits::GetSlotValueUnsafe(
      obj->pTraits.pObject,
      &result,
      pCurrent,
      (Scaleform::GFx::AS3::AbsoluteIndex)(slot_ind - 1),
      obj);
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
      {
        v9 = v11->RefCount-- == 1;
        if ( v9 )
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v11);
        memset(&v13.Bonus, 0, 24);
        v13.Flags = Flags & 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v13);
      }
    }
  }
}

// File Line: 2229
// RVA: 0x7CAFA0
Scaleform::GFx::AS3::VM::ExecuteCode

