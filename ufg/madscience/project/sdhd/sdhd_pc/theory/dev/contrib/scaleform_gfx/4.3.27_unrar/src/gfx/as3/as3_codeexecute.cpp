// File Line: 39
// RVA: 0x7AAA10
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Add(Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::StringManager *sm, Scaleform::GFx::AS3::Value *a3, Scaleform::GFx::AS3::Value *l)
{
  Scaleform::GFx::AS3::Value *v4; // r10
  Scaleform::GFx::AS3::Value *v5; // r11
  Scaleform::GFx::AS3::StringManager *v6; // rbx
  Scaleform::GFx::AS3::CheckResult *v7; // rdi
  Scaleform::GFx::AS3::StringManager *v8; // rsi
  long double v9; // r8
  __int64 v10; // rcx
  int v11; // eax
  int v12; // ecx
  bool v13; // al
  bool v14; // al
  bool v15; // zf
  bool v16; // al
  Scaleform::GFx::ASString *v17; // rax
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::GFx::ASStringNode *v20; // rcx
  Scaleform::GFx::AS3::CheckResult v22; // [rsp+1Ch] [rbp-1Dh]
  Scaleform::GFx::AS3::Value::Hint hint[2]; // [rsp+20h] [rbp-19h]
  Scaleform::GFx::ASString str; // [rsp+28h] [rbp-11h]
  Scaleform::GFx::AS3::Value la; // [rsp+30h] [rbp-9h]
  Scaleform::GFx::AS3::Value v26; // [rsp+50h] [rbp+17h]
  __int64 v27; // [rsp+70h] [rbp+37h]
  Scaleform::GFx::AS3::StringManager *sma; // [rsp+A0h] [rbp+67h]
  Scaleform::GFx::AS3::Value *retaddr; // [rsp+A8h] [rbp+6Fh]
  __int64 resulta; // [rsp+B0h] [rbp+77h]
  Scaleform::GFx::AS3::Value *v31; // [rsp+B8h] [rbp+7Fh]
  Scaleform::GFx::AS3::Value *v32; // [rsp+C0h] [rbp+87h]
  Scaleform::GFx::AS3::Value *v33; // [rsp+C8h] [rbp+8Fh]

  v33 = l;
  v32 = a3;
  v31 = (Scaleform::GFx::AS3::Value *)sm;
  v27 = -2i64;
  v4 = l;
  v5 = a3;
  v6 = sm;
  v7 = result;
  v8 = sm;
  if ( (l->Flags & 0x1F) - 12 <= 3 && (v31->Flags & 0x1F) - 12 <= 3 )
  {
    v9 = l->value.VNumber;
    if ( v9 != 0.0 )
    {
      if ( *(_QWORD *)&v31->value.VNumber )
      {
        v10 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)&v9 + 40i64) + 128i64) + 56i64);
        if ( (*(unsigned __int8 (__fastcall **)(__int64, Scaleform::GFx::AS3::Value *))(*(_QWORD *)v10 + 56i64))(
               v10,
               v5) )
        {
LABEL_17:
          v7->Result = 1;
          return v7;
        }
        v4 = (Scaleform::GFx::AS3::Value *)resulta;
      }
    }
  }
  v11 = v4->Flags & 0x1F;
  if ( v11 == 10 || (v12 = (_QWORD)v8->Builtins[0].pNode & 0x1F, v12 == 10) )
  {
    Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
      (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v6->Builtins,
      (Scaleform::GFx::ASString *)hint);
    Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
      (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v6->Builtins,
      &str);
    v16 = Scaleform::GFx::AS3::Value::Convert2String(
            (Scaleform::GFx::AS3::Value *)resulta,
            &v22,
            (Scaleform::GFx::ASString *)hint)->Result
       && Scaleform::GFx::AS3::Value::Convert2String(
            (Scaleform::GFx::AS3::Value *)v8,
            (Scaleform::GFx::AS3::CheckResult *)&resulta,
            &str)->Result;
    if ( v16 )
    {
      v17 = Scaleform::GFx::ASString::operator+(
              (Scaleform::GFx::ASString *)hint,
              (Scaleform::GFx::ASString *)&resulta,
              &str);
      Scaleform::GFx::AS3::Value::Assign(retaddr, v17);
      v18 = (Scaleform::GFx::ASStringNode *)resulta;
      v15 = *(_DWORD *)(resulta + 24) == 1;
      --v18->RefCount;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v18);
      v7->Result = 1;
    }
    else
    {
      v7->Result = 0;
    }
    v19 = str.pNode;
    v15 = str.pNode->RefCount == 1;
    --v19->RefCount;
    if ( v15 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v19);
    v20 = *(Scaleform::GFx::ASStringNode **)hint;
    v15 = *(_DWORD *)(*(_QWORD *)hint + 24i64) == 1;
    --v20->RefCount;
    if ( v15 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v20);
  }
  else
  {
    if ( v11 < 5 && v12 < 5 )
    {
      *(double *)&str.pNode = 0.0;
      *(double *)hint = 0.0;
      v13 = Scaleform::GFx::AS3::Value::Convert2NumberInline(
              v4,
              (Scaleform::GFx::AS3::CheckResult *)&resulta,
              (long double *)&str)->Result
         && Scaleform::GFx::AS3::Value::Convert2NumberInline(
              (Scaleform::GFx::AS3::Value *)v8,
              &v22,
              (long double *)hint)->Result;
      if ( !v13 )
      {
        v7->Result = 0;
        return v7;
      }
      Scaleform::GFx::AS3::Value::SetNumber(retaddr, *(double *)hint + *(double *)&str.pNode);
      goto LABEL_17;
    }
    la.Flags = 0;
    la.Bonus.pWeakProxy = 0i64;
    v26.Flags = 0;
    v26.Bonus.pWeakProxy = 0i64;
    v14 = 0;
    if ( Scaleform::GFx::AS3::Value::Convert2PrimitiveValueUnsafe(
           v4,
           (Scaleform::GFx::AS3::CheckResult *)&resulta,
           v6->pStringManager,
           &la,
           0)->Result )
    {
      hint[0] = 0;
      if ( Scaleform::GFx::AS3::Value::Convert2PrimitiveValueUnsafe(
             (Scaleform::GFx::AS3::Value *)v8,
             &v22,
             *(Scaleform::GFx::ASStringManager **)hint,
             &v26,
             0)->Result )
        v14 = 1;
    }
    if ( v14 )
      Scaleform::GFx::AS3::Add(v7, sma, retaddr, &la, &v26);
    else
      v7->Result = 0;
    if ( (v26.Flags & 0x1F) > 9 )
    {
      if ( (v26.Flags >> 9) & 1 )
      {
        v15 = v26.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v15 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v26.Bonus.pWeakProxy = 0i64;
        v26.value = 0ui64;
        v26.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v26);
      }
    }
    if ( (la.Flags & 0x1F) > 9 )
    {
      if ( (la.Flags >> 9) & 1 )
      {
        v15 = la.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v15 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        la.Bonus.pWeakProxy = 0i64;
        la.value = 0ui64;
        la.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&la);
      }
    }
  }
  return v7;
}

// File Line: 113
// RVA: 0x847330
__int64 __fastcall Scaleform::GFx::AS3::VM::exec_throw(Scaleform::GFx::AS3::VM *this, const unsigned __int64 *cp, Scaleform::GFx::AS3::CallFrame *cf)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  const unsigned __int64 *v4; // rsi
  Scaleform::GFx::AS3::CallFrame *v5; // rbp
  Scaleform::GFx::AS3::VM *v6; // rdi
  Scaleform::GFx::AS3::WeakProxy *v7; // rdx
  bool v8; // zf
  Scaleform::GFx::AS3::Value *v9; // rcx
  Scaleform::ArrayLH_POD<unsigned __int64,338,Scaleform::ArrayDefaultPolicy> *v10; // rax

  v3 = &this->ExceptionObj;
  v4 = cp;
  v5 = cf;
  v6 = this;
  if ( (this->ExceptionObj.Flags & 0x1F) > 9 )
  {
    if ( (this->ExceptionObj.Flags >> 9) & 1 )
    {
      v7 = this->ExceptionObj.Bonus.pWeakProxy;
      v8 = v7->RefCount-- == 1;
      if ( v8 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v3->Flags &= 0xFFFFFDE0;
      v3->Bonus.pWeakProxy = 0i64;
      v3->value.VNumber = 0.0;
      v3->value.VS._2.VObj = 0i64;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&this->ExceptionObj);
    }
  }
  v9 = v6->OpStack.pCurrent;
  v3->Flags = v9->Flags;
  v3->Bonus.pWeakProxy = v9->Bonus.pWeakProxy;
  v3->value.VNumber = v9->value.VNumber;
  v3->value.VS._2.VObj = v9->value.VS._2.VObj;
  --v6->OpStack.pCurrent;
  v10 = Scaleform::GFx::AS3::VMAbcFile::GetOpCode(v5->pFile, v5);
  return Scaleform::GFx::AS3::VM::OnException(v6, v4 - v10->Data.Data, v5);
}

// File Line: 135
// RVA: 0x83EF80
void __fastcall Scaleform::GFx::AS3::VM::exec_dxnslate(Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::VM *v1; // rdi
  Scaleform::GFx::AS3::Value *v2; // rsi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v3; // rbx
  Scaleform::GFx::AS3::RefCountBaseGC<328> **v4; // rsi
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v5; // rcx
  unsigned int v6; // eax
  unsigned int v7; // eax
  bool v8; // al
  Scaleform::GFx::AS3::Instances::fl::Namespace *v9; // rbx
  Scaleform::GFx::AS3::RefCountBaseGC<328> **v10; // rsi
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v11; // rcx
  unsigned int v12; // eax
  unsigned int v13; // eax
  Scaleform::GFx::ASStringNode *v14; // rcx
  bool v15; // zf
  Scaleform::GFx::AS3::Value *v16; // rbx
  Scaleform::GFx::AS3::WeakProxy *v17; // rdx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v18; // [rsp+60h] [rbp+8h]
  Scaleform::GFx::ASString result; // [rsp+68h] [rbp+10h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> v20; // [rsp+70h] [rbp+18h]

  v1 = this;
  v2 = this->OpStack.pCurrent;
  if ( (v2->Flags & 0x1F) == 11 )
  {
    v3 = v2->value.VS._1.VNs;
    v18 = v3;
    if ( v3 )
      v3->RefCount = (v3->RefCount + 1) & 0x8FBFFFFF;
    v4 = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&this->DefXMLNamespace;
    if ( &v18 != (Scaleform::GFx::AS3::Instances::fl::Namespace **)&this->DefXMLNamespace )
    {
      if ( v3 )
        v3->RefCount = (v3->RefCount + 1) & 0x8FBFFFFF;
      v5 = *v4;
      if ( *v4 )
      {
        if ( (unsigned __int8)v5 & 1 )
        {
          *v4 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v5 - 1);
        }
        else
        {
          v6 = v5->RefCount;
          if ( v6 & 0x3FFFFF )
          {
            v5->RefCount = v6 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v5);
          }
        }
      }
      *v4 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v3->vfptr;
    }
    if ( v3 )
    {
      if ( (unsigned __int8)v3 & 1 )
      {
        v18 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v3 - 1);
      }
      else
      {
        v7 = v3->RefCount;
        if ( v7 & 0x3FFFFF )
        {
          v3->RefCount = v7 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v3->vfptr);
        }
      }
    }
  }
  else
  {
    Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
      (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)this->StringManagerRef->Builtins,
      &result);
    v8 = Scaleform::GFx::AS3::Value::Convert2String(v2, (Scaleform::GFx::AS3::CheckResult *)&v18, &result)->Result
      && result.pNode->Size;
    if ( v8 )
    {
      if ( !(_S11_12 & 1) )
      {
        _S11_12 |= 1u;
        v.Flags = 0;
        v.Bonus.pWeakProxy = 0i64;
        atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
      }
      Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::MakeInstance(
        (Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *)v1->TraitsNamespace.pObject->ITraits.pObject,
        &v20,
        0,
        &result,
        &v);
      v9 = v20.pV;
      v18 = v20.pV;
      v10 = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v1->DefXMLNamespace;
      if ( &v18 != (Scaleform::GFx::AS3::Instances::fl::Namespace **)&v1->DefXMLNamespace )
      {
        if ( v20.pV )
          v20.pV->RefCount = (v20.pV->RefCount + 1) & 0x8FBFFFFF;
        v11 = *v10;
        if ( *v10 )
        {
          if ( (unsigned __int8)v11 & 1 )
          {
            *v10 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v11 - 1);
          }
          else
          {
            v12 = v11->RefCount;
            if ( v12 & 0x3FFFFF )
            {
              v11->RefCount = v12 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v11);
            }
          }
        }
        *v10 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v9->vfptr;
      }
      if ( v9 )
      {
        if ( (unsigned __int8)v9 & 1 )
        {
          v18 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v9 - 1);
        }
        else
        {
          v13 = v9->RefCount;
          if ( v13 & 0x3FFFFF )
          {
            v9->RefCount = v13 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v9->vfptr);
          }
        }
      }
    }
    v14 = result.pNode;
    v15 = result.pNode->RefCount == 1;
    --v14->RefCount;
    if ( v15 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  }
  v16 = v1->OpStack.pCurrent;
  if ( (v16->Flags & 0x1F) > 9 )
  {
    if ( (v16->Flags >> 9) & 1 )
    {
      v17 = v16->Bonus.pWeakProxy;
      v15 = v17->RefCount-- == 1;
      if ( v15 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v16->Bonus.pWeakProxy = 0i64;
      v16->value.VNumber = 0.0;
      v16->value.VS._2.VObj = 0i64;
      v16->Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(v1->OpStack.pCurrent);
    }
  }
  --v1->OpStack.pCurrent;
}

// File Line: 684
// RVA: 0x846000
void __fastcall Scaleform::GFx::AS3::VM::exec_pushwith(Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::VM *v1; // rsi
  int v3; // edx
  Scaleform::GFx::AS3::Value::VU *v4; // rdx
  int v5; // eax
  long double v6; // rax
  signed __int64 v7; // r14
  Scaleform::GFx::AS3::Value *v8; // rdi
  Scaleform::GFx::AS3::WeakProxy *v9; // rdx
  bool v10; // zf
  bool v11; // bl
  Scaleform::GFx::AS3::VM::Error *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::AS3::VM::Error v14; // [rsp+28h] [rbp-30h]

  v1 = this;
  _RDI = this->OpStack.pCurrent;
  v3 = _RDI->Flags & 0x1F;
  if ( v3 && ((unsigned int)(v3 - 12) > 3 && v3 != 10 || *(_QWORD *)&_RDI->value.VNumber) )
  {
    if ( !(_S11_12 & 1) )
    {
      _S11_12 |= 1u;
      v.Flags = 0;
      v.Bonus.pWeakProxy = 0i64;
      atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
    }
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v1->ScopeStack.Data.Data,
      v1->ScopeStack.Data.pHeap,
      v1->ScopeStack.Data.Size + 1);
    v4 = (Scaleform::GFx::AS3::Value::VU *)&v1->ScopeStack.Data.Data[v1->ScopeStack.Data.Size - 1];
    if ( !v4 )
      goto LABEL_20;
    LODWORD(v4->VS._1.VStr) = v.Flags;
    v4->VS._2.VObj = (Scaleform::GFx::AS3::Object *)v.Bonus.pWeakProxy;
    v4[1] = v.value;
    v5 = v.Flags & 0x1F;
    if ( v5 <= 9 )
      goto LABEL_20;
    if ( (v.Flags >> 9) & 1 )
    {
      ++v.Bonus.pWeakProxy->RefCount;
    }
    else
    {
      if ( v5 == 10 )
      {
        ++*(_DWORD *)(*(_QWORD *)&v.value.VNumber + 24i64);
        goto LABEL_20;
      }
      if ( v5 > 10 )
      {
        if ( v5 <= 15 )
        {
          v6 = v.value.VNumber;
        }
        else
        {
          if ( v5 > 17 )
            goto LABEL_20;
          v6 = *(double *)&v.value.VS._2.VObj;
        }
        if ( v6 != 0.0 )
        {
          ++*(_DWORD *)(*(_QWORD *)&v6 + 32i64);
          *(_DWORD *)(*(_QWORD *)&v6 + 32i64) &= 0x8FBFFFFF;
        }
        goto LABEL_20;
      }
    }
LABEL_20:
    v7 = (signed __int64)&v1->ScopeStack.Data.Data[v1->ScopeStack.Data.Size];
    __asm { prefetcht1 byte ptr [rdi]; Prefetch to all cache levels }
    *(_QWORD *)(v7 - 32) = *(_QWORD *)&_RDI->Flags;
    *(_QWORD *)(v7 - 24) = _RDI->Bonus.pWeakProxy;
    *(long double *)(v7 - 16) = _RDI->value.VNumber;
    *(_QWORD *)(v7 - 8) = _RDI->value.VS._2.VObj;
    _RDI->Flags = 0;
    v8 = v1->OpStack.pCurrent;
    if ( (v8->Flags & 0x1F) > 9 )
    {
      if ( (v8->Flags >> 9) & 1 )
      {
        v9 = v8->Bonus.pWeakProxy;
        v10 = v9->RefCount-- == 1;
        if ( v10 )
          ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        v8->Bonus.pWeakProxy = 0i64;
        v8->value.VNumber = 0.0;
        v8->value.VS._2.VObj = 0i64;
        v8->Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(v1->OpStack.pCurrent);
      }
    }
    --v1->OpStack.pCurrent;
    *(_DWORD *)(v7 - 32) |= 0x100u;
    return;
  }
  v11 = ((unsigned int)(v3 - 12) <= 3 || v3 == 10) && !*(_QWORD *)&_RDI->value.VNumber;
  Scaleform::GFx::AS3::VM::Error::Error(&v14, (Scaleform::GFx::AS3::VM::ErrorID)(1010 - (v11 != 0)), this);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(v1, v12, &Scaleform::GFx::AS3::fl::TypeErrorTI);
  v13 = v14.Message.pNode;
  v10 = v14.Message.pNode->RefCount == 1;
  --v13->RefCount;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
}

// File Line: 713
// RVA: 0x844190
void __fastcall Scaleform::GFx::AS3::VM::exec_nextname(Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::VM *v1; // rsi
  Scaleform::GFx::AS3::Value *v2; // rbx
  bool v3; // zf
  Scaleform::GFx::AS3::Value::VU *v4; // rax
  bool v5; // r14
  Scaleform::GFx::AS3::GlobalSlotIndex v6; // ebp
  Scaleform::GFx::AS3::Value *v7; // rbx
  Scaleform::GFx::AS3::WeakProxy *v8; // rdx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v9; // rcx
  Scaleform::GFx::AS3::Value *v10; // rdx
  int result; // [rsp+40h] [rbp+8h]

  v1 = this;
  result = 0;
  v2 = this->OpStack.pCurrent;
  v3 = Scaleform::GFx::AS3::Value::ToInt32Value(
         this->OpStack.pCurrent,
         (Scaleform::GFx::AS3::CheckResult *)&result,
         (__int64)this)->Result == 0;
  v4 = &v2->value;
  v5 = !v3;
  if ( v3 )
    v4 = (Scaleform::GFx::AS3::Value::VU *)&`Scaleform::GFx::AS3::ToType<long>'::`2'::tmp;
  v6.Index = (unsigned int)v4->VS._1.VStr;
  v7 = v1->OpStack.pCurrent;
  if ( (v7->Flags & 0x1F) > 9 )
  {
    if ( (v7->Flags >> 9) & 1 )
    {
      v8 = v7->Bonus.pWeakProxy;
      v3 = v8->RefCount-- == 1;
      if ( v3 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v7->Flags &= 0xFFFFFDE0;
      v7->Bonus.pWeakProxy = 0i64;
      v7->value.VNumber = 0.0;
      v7->value.VS._2.VObj = 0i64;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(v1->OpStack.pCurrent);
    }
  }
  --v1->OpStack.pCurrent;
  if ( v5 )
  {
    v9 = v7[-1].value.VS._1.VNs;
    v10 = v7 - 1;
    if ( (v7[-1].Flags & 0x1F) == 11 )
      Scaleform::GFx::AS3::Instances::fl::Namespace::GetNextPropertyName(v9, v10, v6);
    else
      v9->vfptr[5].ForEachChild_GC(
        (Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v9->vfptr,
        (Scaleform::GFx::AS3::RefCountCollector<328> *)v10,
        (void (__fastcall *)(Scaleform::GFx::AS3::RefCountCollector<328> *, Scaleform::GFx::AS3::RefCountBaseGC<328> **))v6.Index);
  }
}

// File Line: 852
// RVA: 0x845900
void __fastcall Scaleform::GFx::AS3::VM::exec_pushscope(Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::VM *v1; // rsi
  int v3; // edx
  Scaleform::GFx::AS3::Value::VU *v4; // rdx
  int v5; // eax
  long double v6; // rax
  signed __int64 v7; // rdx
  Scaleform::GFx::AS3::Value *v8; // rdi
  Scaleform::GFx::AS3::WeakProxy *v9; // rdx
  bool v10; // zf
  bool v11; // bl
  Scaleform::GFx::AS3::VM::Error *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::AS3::VM::Error v14; // [rsp+28h] [rbp-30h]

  v1 = this;
  _RDI = this->OpStack.pCurrent;
  v3 = _RDI->Flags & 0x1F;
  if ( v3 && ((unsigned int)(v3 - 12) > 3 && v3 != 10 || *(_QWORD *)&_RDI->value.VNumber) )
  {
    if ( !(_S11_12 & 1) )
    {
      _S11_12 |= 1u;
      v.Flags = 0;
      v.Bonus.pWeakProxy = 0i64;
      atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
    }
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v1->ScopeStack.Data.Data,
      v1->ScopeStack.Data.pHeap,
      v1->ScopeStack.Data.Size + 1);
    v4 = (Scaleform::GFx::AS3::Value::VU *)&v1->ScopeStack.Data.Data[v1->ScopeStack.Data.Size - 1];
    if ( !v4 )
      goto LABEL_20;
    LODWORD(v4->VS._1.VStr) = v.Flags;
    v4->VS._2.VObj = (Scaleform::GFx::AS3::Object *)v.Bonus.pWeakProxy;
    v4[1] = v.value;
    v5 = v.Flags & 0x1F;
    if ( v5 <= 9 )
      goto LABEL_20;
    if ( (v.Flags >> 9) & 1 )
    {
      ++v.Bonus.pWeakProxy->RefCount;
    }
    else
    {
      if ( v5 == 10 )
      {
        ++*(_DWORD *)(*(_QWORD *)&v.value.VNumber + 24i64);
        goto LABEL_20;
      }
      if ( v5 > 10 )
      {
        if ( v5 <= 15 )
        {
          v6 = v.value.VNumber;
        }
        else
        {
          if ( v5 > 17 )
            goto LABEL_20;
          v6 = *(double *)&v.value.VS._2.VObj;
        }
        if ( v6 != 0.0 )
        {
          ++*(_DWORD *)(*(_QWORD *)&v6 + 32i64);
          *(_DWORD *)(*(_QWORD *)&v6 + 32i64) &= 0x8FBFFFFF;
        }
        goto LABEL_20;
      }
    }
LABEL_20:
    v7 = (signed __int64)&v1->ScopeStack.Data.Data[v1->ScopeStack.Data.Size];
    __asm { prefetcht1 byte ptr [rdi]; Prefetch to all cache levels }
    *(_QWORD *)(v7 - 32) = *(_QWORD *)&_RDI->Flags;
    *(_QWORD *)(v7 - 24) = _RDI->Bonus.pWeakProxy;
    *(long double *)(v7 - 16) = _RDI->value.VNumber;
    *(_QWORD *)(v7 - 8) = _RDI->value.VS._2.VObj;
    _RDI->Flags = 0;
    v8 = v1->OpStack.pCurrent;
    if ( (v8->Flags & 0x1F) > 9 )
    {
      if ( (v8->Flags >> 9) & 1 )
      {
        v9 = v8->Bonus.pWeakProxy;
        v10 = v9->RefCount-- == 1;
        if ( v10 )
          ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        v8->Bonus.pWeakProxy = 0i64;
        v8->value.VNumber = 0.0;
        v8->value.VS._2.VObj = 0i64;
        v8->Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(v1->OpStack.pCurrent);
      }
    }
    --v1->OpStack.pCurrent;
    return;
  }
  v11 = ((unsigned int)(v3 - 12) <= 3 || v3 == 10) && !*(_QWORD *)&_RDI->value.VNumber;
  Scaleform::GFx::AS3::VM::Error::Error(&v14, (Scaleform::GFx::AS3::VM::ErrorID)(1010 - (v11 != 0)), this);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(v1, v12, &Scaleform::GFx::AS3::fl::TypeErrorTI);
  v13 = v14.Message.pNode;
  v10 = v14.Message.pNode->RefCount == 1;
  --v13->RefCount;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
}

// File Line: 999
// RVA: 0x842E00
void __fastcall Scaleform::GFx::AS3::VM::exec_newactivation(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::CallFrame *cf)
{
  Scaleform::GFx::AS3::VM *v2; // rbx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v3; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v4; // rdi
  Scaleform::GFx::AS3::Instance *v5; // rax
  unsigned __int64 v6; // rax
  unsigned __int64 v7; // rcx
  bool v8; // zf
  __int64 v9; // rax
  Scaleform::GFx::AS3::Value v10; // [rsp+28h] [rbp-30h]
  __int64 v11; // [rsp+60h] [rbp+8h]
  __int64 v12; // [rsp+68h] [rbp+10h]
  Scaleform::GFx::AS3::Instance *v13; // [rsp+70h] [rbp+18h]

  v2 = this;
  v3 = Scaleform::GFx::AS3::VMFile::GetActivationInstanceTraits(
         (Scaleform::GFx::AS3::VMFile *)&cf->pFile->vfptr,
         cf->MBIIndex);
  v4 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)v3;
  LODWORD(v11) = 337;
  v5 = (Scaleform::GFx::AS3::Instance *)(*(__int64 (__fastcall **)(_QWORD, _QWORD, __int64 *))(**(_QWORD **)(v3[3].pRCCRaw + 48)
                                                                                             + 80i64))(
                                          *(_QWORD *)(v3[3].pRCCRaw + 48),
                                          LODWORD(v3[2].pPrev),
                                          &v11);
  v12 = (__int64)v5;
  v13 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::Instance::Instance(v5, v4);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  v10.Bonus.pWeakProxy = 0i64;
  v10.Flags = 12;
  v10.value = (Scaleform::GFx::AS3::Value::VU)v7;
  v8 = v2->OpStack.pCurrent == (Scaleform::GFx::AS3::Value *)-32i64;
  ++v2->OpStack.pCurrent;
  v9 = (__int64)v2->OpStack.pCurrent;
  v11 = v9;
  v12 = v9;
  if ( !v8 )
  {
    *(_DWORD *)v9 = 12;
    *(_QWORD *)(v9 + 8) = 0i64;
    *(_QWORD *)(v9 + 16) = v7;
    *(_QWORD *)(v9 + 24) = 0i64;
    if ( v7 )
      *(_DWORD *)(v7 + 32) = (*(_DWORD *)(v7 + 32) + 1) & 0x8FBFFFFF;
  }
  Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
}

// File Line: 1082
// RVA: 0x840D90
void __fastcall Scaleform::GFx::AS3::VM::exec_getscopeobject(Scaleform::GFx::AS3::VM *this, unsigned int index)
{
  Scaleform::GFx::AS3::VM *v2; // r9
  Scaleform::GFx::AS3::Value *v3; // r8
  bool v4; // zf
  Scaleform::GFx::AS3::Value *v5; // rdx
  int v6; // eax
  long double v7; // rcx

  v2 = this;
  v3 = &this->ScopeStack.Data.Data[index];
  v4 = this->OpStack.pCurrent == (Scaleform::GFx::AS3::Value *)-32i64;
  ++this->OpStack.pCurrent;
  v5 = this->OpStack.pCurrent;
  if ( !v4 )
  {
    v5->Flags = v3->Flags;
    v5->Bonus.pWeakProxy = v3->Bonus.pWeakProxy;
    v5->value.VNumber = v3->value.VNumber;
    v5->value.VS._2.VObj = v3->value.VS._2.VObj;
    v6 = v3->Flags & 0x1F;
    if ( v6 > 9 )
    {
      if ( (v3->Flags >> 9) & 1 )
      {
        ++v3->Bonus.pWeakProxy->RefCount;
      }
      else
      {
        if ( v6 == 10 )
        {
          ++*(_DWORD *)(*(_QWORD *)&v3->value.VNumber + 24i64);
          goto LABEL_14;
        }
        if ( v6 > 10 )
        {
          if ( v6 <= 15 )
          {
            v7 = v3->value.VNumber;
          }
          else
          {
            if ( v6 > 17 )
              goto LABEL_14;
            v7 = *(double *)&v3->value.VS._2.VObj;
          }
          if ( v7 != 0.0 )
            *(_DWORD *)(*(_QWORD *)&v7 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v7 + 32i64) + 1) & 0x8FBFFFFF;
        }
      }
    }
  }
LABEL_14:
  v2->OpStack.pCurrent->Flags &= 0xFFFFFEFF;
}

// File Line: 1090
// RVA: 0x840990
void __fastcall Scaleform::GFx::AS3::VM::exec_getouterscope(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::CallFrame *cf, unsigned int scope_index)
{
  Scaleform::GFx::AS3::VM *v3; // rbx
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v4; // rax
  Scaleform::GFx::AS3::VM::Error *v5; // rax
  Scaleform::GFx::ASStringNode *v6; // rcx
  bool v7; // zf
  signed __int64 v8; // rdx
  Scaleform::GFx::AS3::Value *v9; // rcx
  int v10; // eax
  __int64 v11; // rcx
  Scaleform::GFx::AS3::VM::Error v12; // [rsp+28h] [rbp-20h]

  v3 = this;
  v4 = cf->pSavedScope;
  if ( scope_index < v4->Data.Size )
  {
    v8 = (signed __int64)&v4->Data.Data[scope_index];
    v7 = this->OpStack.pCurrent == (Scaleform::GFx::AS3::Value *)-32i64;
    ++this->OpStack.pCurrent;
    v9 = this->OpStack.pCurrent;
    if ( !v7 )
    {
      v9->Flags = *(_DWORD *)v8;
      v9->Bonus.pWeakProxy = *(Scaleform::GFx::AS3::WeakProxy **)(v8 + 8);
      v9->value.VNumber = *(long double *)(v8 + 16);
      v9->value.VS._2.VObj = *(Scaleform::GFx::AS3::Object **)(v8 + 24);
      v10 = *(_DWORD *)v8 & 0x1F;
      if ( v10 > 9 )
      {
        if ( (*(_DWORD *)v8 >> 9) & 1 )
        {
          ++**(_DWORD **)(v8 + 8);
          return;
        }
        if ( v10 == 10 )
        {
          ++*(_DWORD *)(*(_QWORD *)(v8 + 16) + 24i64);
        }
        else
        {
          if ( v10 <= 10 )
            return;
          if ( v10 <= 15 )
          {
            v11 = *(_QWORD *)(v8 + 16);
          }
          else
          {
            if ( v10 > 17 )
              return;
            v11 = *(_QWORD *)(v8 + 24);
          }
          if ( v11 )
            *(_DWORD *)(v11 + 32) = (*(_DWORD *)(v11 + 32) + 1) & 0x8FBFFFFF;
        }
      }
    }
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v12, eParamRangeError, this);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v3, v5, &Scaleform::GFx::AS3::fl::ReferenceErrorTI);
    v6 = v12.Message.pNode;
    v7 = v12.Message.pNode->RefCount == 1;
    --v6->RefCount;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  }
}

// File Line: 1107
// RVA: 0x840310
void __fastcall Scaleform::GFx::AS3::VM::exec_getglobalslot(Scaleform::GFx::AS3::VM *this, unsigned int slot_index)
{
  unsigned int v2; // esi
  Scaleform::GFx::AS3::VM *v3; // rdi
  Scaleform::GFx::AS3::Object *v4; // rbx
  bool v5; // zf
  Scaleform::GFx::AS3::Value::VU *v6; // rcx
  int v7; // eax
  long double v8; // rax
  signed __int64 v9; // rdx
  _QWORD *v10; // rax
  __int64 v11; // rcx
  Scaleform::GFx::AS3::CheckResult result; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::AS3::Value *v13; // [rsp+60h] [rbp+18h]

  v2 = slot_index;
  v3 = this;
  v4 = 0i64;
  if ( !(_S11_12 & 1) )
  {
    _S11_12 |= 1u;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0i64;
    atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  v5 = v3->OpStack.pCurrent == (Scaleform::GFx::AS3::Value *)-32i64;
  ++v3->OpStack.pCurrent;
  v6 = (Scaleform::GFx::AS3::Value::VU *)v3->OpStack.pCurrent;
  v13 = v3->OpStack.pCurrent;
  if ( !v5 )
  {
    LODWORD(v6->VS._1.VStr) = v.Flags;
    v6->VS._2.VObj = (Scaleform::GFx::AS3::Object *)v.Bonus.pWeakProxy;
    v6[1] = v.value;
    v7 = v.Flags & 0x1F;
    if ( v7 > 9 )
    {
      if ( (v.Flags >> 9) & 1 )
      {
        ++v.Bonus.pWeakProxy->RefCount;
        goto LABEL_16;
      }
      if ( v7 == 10 )
      {
        ++*(_DWORD *)(*(_QWORD *)&v.value.VNumber + 24i64);
      }
      else
      {
        if ( v7 <= 10 )
          goto LABEL_16;
        if ( v7 <= 15 )
        {
          v8 = v.value.VNumber;
        }
        else
        {
          if ( v7 > 17 )
            goto LABEL_16;
          v8 = *(double *)&v.value.VS._2.VObj;
        }
        if ( v8 != 0.0 )
        {
          ++*(_DWORD *)(*(_QWORD *)&v8 + 32i64);
          *(_DWORD *)(*(_QWORD *)&v8 + 32i64) &= 0x8FBFFFFF;
        }
      }
    }
  }
LABEL_16:
  if ( v3->CallStack.Size )
  {
    v9 = (signed __int64)&v3->CallStack.Pages[(v3->CallStack.Size - 1) >> 6][(LODWORD(v3->CallStack.Size) - 1) & 0x3F];
    v10 = *(_QWORD **)(v9 + 56);
    if ( v10[1] )
    {
      v4 = *(Scaleform::GFx::AS3::Object **)(*v10 + 16i64);
    }
    else
    {
      v11 = *(_QWORD *)(*(_QWORD *)(v9 + 24) + 8i64);
      if ( (*(_DWORD *)v11 & 0x1Fu) - 12 <= 3 )
        v4 = *(Scaleform::GFx::AS3::Object **)(v11 + 16);
    }
  }
  Scaleform::GFx::AS3::Object::GetSlotValueUnsafe(v4, &result, (Scaleform::GFx::AS3::SlotIndex)v2, v3->OpStack.pCurrent);
}

// File Line: 1116
// RVA: 0x846620
void __fastcall Scaleform::GFx::AS3::VM::exec_setglobalslot(Scaleform::GFx::AS3::VM *this, unsigned int slot_index)
{
  Scaleform::GFx::AS3::VM *v2; // rbx
  Scaleform::GFx::AS3::CallFrame *v3; // rcx
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v4; // rax
  Scaleform::GFx::AS3::Object *v5; // rcx
  Scaleform::GFx::AS3::Value *v6; // rcx
  Scaleform::GFx::AS3::Value *v7; // rdi
  Scaleform::GFx::AS3::WeakProxy *v8; // rdx
  bool v9; // zf
  Scaleform::GFx::AS3::CheckResult result; // [rsp+38h] [rbp+10h]

  v2 = this;
  if ( !this->CallStack.Size )
    goto LABEL_16;
  v3 = &this->CallStack.Pages[(this->CallStack.Size - 1) >> 6][(LODWORD(this->CallStack.Size) - 1) & 0x3F];
  v4 = v3->pSavedScope;
  if ( v4->Data.Size )
  {
    v5 = v4->Data.Data->value.VS._1.VObj;
    goto LABEL_7;
  }
  v6 = v3->pRegisterFile->pRF;
  if ( (v6->Flags & 0x1F) - 12 <= 3 )
    v5 = v6->value.VS._1.VObj;
  else
LABEL_16:
    v5 = 0i64;
LABEL_7:
  Scaleform::GFx::AS3::Object::SetSlotValue(
    v5,
    &result,
    (Scaleform::GFx::AS3::SlotIndex)slot_index,
    v2->OpStack.pCurrent);
  v7 = v2->OpStack.pCurrent;
  if ( (v7->Flags & 0x1F) <= 9 )
  {
LABEL_13:
    --v2->OpStack.pCurrent;
    return;
  }
  if ( !((v7->Flags >> 9) & 1) )
  {
    Scaleform::GFx::AS3::Value::ReleaseInternal(v2->OpStack.pCurrent);
    goto LABEL_13;
  }
  v8 = v7->Bonus.pWeakProxy;
  v9 = v8->RefCount-- == 1;
  if ( v9 )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  v7->Flags &= 0xFFFFFDE0;
  v7->Bonus.pWeakProxy = 0i64;
  v7->value.VNumber = 0.0;
  v7->value.VS._2.VObj = 0i64;
  --v2->OpStack.pCurrent;
}

// File Line: 1134
// RVA: 0x83F370
void __fastcall Scaleform::GFx::AS3::VM::exec_esc_xelem(Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::VM *v1; // rbx
  Scaleform::GFx::AS3::XMLSupport *v2; // rcx
  Scaleform::GFx::AS3::VM::Error *v3; // rax
  Scaleform::GFx::ASStringNode *v4; // rcx
  bool v5; // zf
  Scaleform::GFx::AS3::VM::Error v6; // [rsp+28h] [rbp-20h]
  char v7; // [rsp+50h] [rbp+8h]

  v1 = this;
  v2 = this->XMLSupport_.pObject;
  if ( v2->Enabled )
  {
    ((void (__fastcall *)(Scaleform::GFx::AS3::XMLSupport *, char *, Scaleform::GFx::AS3::VM *, Scaleform::GFx::AS3::Value *, signed __int64))v2->vfptr[2].Finalize_GC)(
      v2,
      &v7,
      v1,
      v1->OpStack.pCurrent,
      -2i64);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v6, eNotImplementedError, v1);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v1, v3, &Scaleform::GFx::AS3::fl::VerifyErrorTI);
    v4 = v6.Message.pNode;
    v5 = v6.Message.pNode->RefCount == 1;
    --v4->RefCount;
    if ( v5 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  }
}

// File Line: 1154
// RVA: 0x83F250
void __fastcall Scaleform::GFx::AS3::VM::exec_esc_xattr(Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::StringManager *v1; // rdi
  Scaleform::GFx::AS3::Value *v2; // rbx
  Scaleform::GFx::ASString *v3; // rax
  Scaleform::GFx::ASStringNode *v4; // rcx
  bool v5; // zf
  char *v6; // r8
  Scaleform::GFx::ASString *v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx
  Scaleform::StringBuffer buf; // [rsp+28h] [rbp-40h]
  Scaleform::GFx::AS3::CheckResult result; // [rsp+70h] [rbp+8h]

  v1 = this->StringManagerRef;
  v2 = this->OpStack.pCurrent;
  if ( Scaleform::GFx::AS3::Value::ToStringValue(this->OpStack.pCurrent, &result, this->StringManagerRef)->Result )
  {
    Scaleform::StringBuffer::StringBuffer(&buf, Scaleform::Memory::pGlobalHeap);
    v3 = Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(v2, (Scaleform::GFx::ASString *)&result);
    Scaleform::GFx::AS3::Instances::fl::XML::EscapeElementValue(&buf, v3);
    v4 = *(Scaleform::GFx::ASStringNode **)&result.Result;
    v5 = *(_DWORD *)(*(_QWORD *)&result.Result + 24i64) == 1;
    --v4->RefCount;
    if ( v5 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v4);
    v6 = &customWorldMapCaption;
    if ( buf.pData )
      v6 = buf.pData;
    v7 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
           (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v1->Builtins,
           (Scaleform::GFx::ASString *)&result,
           v6,
           buf.Size);
    Scaleform::GFx::AS3::Value::Assign(v2, v7);
    v8 = *(Scaleform::GFx::ASStringNode **)&result.Result;
    v5 = *(_DWORD *)(*(_QWORD *)&result.Result + 24i64) == 1;
    --v8->RefCount;
    if ( v5 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
    Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&buf);
  }
}

// File Line: 1228
// RVA: 0x83D260
void __fastcall Scaleform::GFx::AS3::VM::exec_checkfilter(Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::VM *v1; // rbx
  Scaleform::GFx::AS3::Value *v2; // r8
  int v3; // edx
  long double v4; // rax
  __int64 v5; // rcx
  long double v6; // rax
  __int64 v7; // rcx
  Scaleform::GFx::AS3::VM::Error *v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::AS3::VM::Error v11; // [rsp+28h] [rbp-20h]

  v1 = this;
  v2 = this->OpStack.pCurrent;
  v3 = v2->Flags & 0x1F;
  if ( (unsigned int)(v3 - 12) > 3
    || (v4 = v2->value.VNumber, v4 == 0.0)
    || (v5 = *(_QWORD *)(*(_QWORD *)&v4 + 40i64), *(_DWORD *)(v5 + 120) != 18)
    || !(~(*(_BYTE *)(v5 + 112) >> 5) & 1) )
  {
    if ( (unsigned int)(v3 - 12) > 3
      || (v6 = v2->value.VNumber, v6 == 0.0)
      || (v7 = *(_QWORD *)(*(_QWORD *)&v6 + 40i64), *(_DWORD *)(v7 + 120) != 19)
      || !(~(*(_BYTE *)(v7 + 112) >> 5) & 1) )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v11, eFilterError, v1);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v1, v8, &Scaleform::GFx::AS3::fl::TypeErrorTI);
      v9 = v11.Message.pNode;
      v10 = v11.Message.pNode->RefCount == 1;
      --v9->RefCount;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v9);
    }
  }
}

// File Line: 1985
// RVA: 0x847400
void __usercall Scaleform::GFx::AS3::VM::exec_typeof(Scaleform::GFx::AS3::VM *this@<rcx>, __int64 a2@<rdi>)
{
  Scaleform::GFx::AS3::VM *v2; // rdi
  Scaleform::GFx::AS3::Value *v3; // rbx
  int v4; // eax
  Scaleform::GFx::AS3::StringManager *v5; // rcx
  long double v6; // rdx
  unsigned int v7; // ebx
  bool v8; // zf
  Scaleform::GFx::AS3::Value other; // [rsp+28h] [rbp-30h]
  __int64 v10; // [rsp+50h] [rbp-8h]

  v10 = a2;
  v2 = this;
  v3 = this->OpStack.pCurrent;
  switch ( v3->Flags & 0x1F )
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
      if ( *(_QWORD *)&v3->value.VNumber )
        v4 = 8;
      break;
    case 0xBu:
    case 0xCu:
      v4 = ((unsigned int)(Scaleform::GFx::AS3::VM::GetValueTraits(this, v3)->TraitsType - 18) <= 1) + 10;
      break;
    default:
      v4 = 12;
      break;
  }
  v5 = v2->StringManagerRef;
  other.Flags = 10;
  other.Bonus.pWeakProxy = 0i64;
  v6 = *(double *)&v5->Builtins[v4].pNode;
  other.value.VNumber = v6;
  if ( *(_QWORD *)&v6 == *(_QWORD *)(*(_QWORD *)&v6 + 8i64) + 104i64 )
  {
    other.value.VNumber = 0.0;
    other.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)other.Bonus.pWeakProxy;
    other.Flags = 12;
  }
  else
  {
    ++*(_DWORD *)(*(_QWORD *)&v6 + 24i64);
  }
  Scaleform::GFx::AS3::Value::Assign(v3, &other);
  v7 = other.Flags;
  if ( (other.Flags & 0x1F) > 9 )
  {
    if ( (other.Flags >> 9) & 1 )
    {
      v8 = other.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v8 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      other.Bonus.pWeakProxy = 0i64;
      other.value = 0ui64;
      other.Flags = v7 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
    }
  }
}

// File Line: 2042
// RVA: 0x841D70
void __usercall Scaleform::GFx::AS3::VM::exec_hasnext(Scaleform::GFx::AS3::VM *this@<rcx>, __int64 a2@<rsi>)
{
  Scaleform::GFx::AS3::VM *v2; // rdi
  Scaleform::GFx::AS3::Value *v3; // rbx
  bool v4; // zf
  Scaleform::GFx::AS3::Value::VU *v5; // rax
  bool v6; // si
  unsigned int v7; // er14
  Scaleform::GFx::AS3::Value *v8; // rbx
  Scaleform::GFx::AS3::WeakProxy *v9; // rdx
  unsigned int *v10; // rax
  int result; // [rsp+40h] [rbp+8h]

  v2 = this;
  result = 0;
  v3 = this->OpStack.pCurrent;
  v4 = Scaleform::GFx::AS3::Value::ToInt32Value(this->OpStack.pCurrent, (Scaleform::GFx::AS3::CheckResult *)&result, a2)->Result == 0;
  v5 = &v3->value;
  v6 = !v4;
  if ( v4 )
    v5 = (Scaleform::GFx::AS3::Value::VU *)&`Scaleform::GFx::AS3::ToType<long>'::`2'::tmp;
  v7 = (unsigned int)v5->VS._1.VStr;
  v8 = v2->OpStack.pCurrent;
  if ( (v8->Flags & 0x1F) > 9 )
  {
    if ( (v8->Flags >> 9) & 1 )
    {
      v9 = v8->Bonus.pWeakProxy;
      v4 = v9->RefCount-- == 1;
      if ( v4 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v8->Flags &= 0xFFFFFDE0;
      v8->Bonus.pWeakProxy = 0i64;
      v8->value.VNumber = 0.0;
      v8->value.VS._2.VObj = 0i64;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(v2->OpStack.pCurrent);
    }
  }
  --v2->OpStack.pCurrent;
  if ( v6 )
  {
    v10 = (unsigned int *)(*((__int64 (__fastcall **)(_QWORD, int *, _QWORD))v8[-1].value.VS._1.VStr->pData + 16))(
                            *(_QWORD *)&v8[-1].value.VNumber,
                            &result,
                            v7);
    Scaleform::GFx::AS3::Value::SetUInt32(v8 - 1, *v10);
  }
}

// File Line: 2055
// RVA: 0x844340
void __usercall Scaleform::GFx::AS3::VM::exec_nextvalue(Scaleform::GFx::AS3::VM *this@<rcx>, __int64 a2@<rsi>)
{
  Scaleform::GFx::AS3::VM *v2; // rbp
  Scaleform::GFx::AS3::Value *v3; // rbx
  bool v4; // zf
  Scaleform::GFx::AS3::Value::VU *v5; // rax
  bool v6; // r14
  unsigned int v7; // esi
  Scaleform::GFx::AS3::Value *v8; // rbx
  Scaleform::GFx::AS3::WeakProxy *v9; // rdx
  long double v10; // rdx
  int v11; // esi
  int result; // [rsp+40h] [rbp+8h]

  v2 = this;
  result = 0;
  v3 = this->OpStack.pCurrent;
  v4 = Scaleform::GFx::AS3::Value::ToInt32Value(this->OpStack.pCurrent, (Scaleform::GFx::AS3::CheckResult *)&result, a2)->Result == 0;
  v5 = &v3->value;
  v6 = !v4;
  if ( v4 )
    v5 = (Scaleform::GFx::AS3::Value::VU *)&`Scaleform::GFx::AS3::ToType<long>'::`2'::tmp;
  v7 = (unsigned int)v5->VS._1.VStr;
  v8 = v2->OpStack.pCurrent;
  if ( (v8->Flags & 0x1F) > 9 )
  {
    if ( (v8->Flags >> 9) & 1 )
    {
      v9 = v8->Bonus.pWeakProxy;
      v4 = v9->RefCount-- == 1;
      if ( v4 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v8->Flags &= 0xFFFFFDE0;
      v8->Bonus.pWeakProxy = 0i64;
      v8->value.VNumber = 0.0;
      v8->value.VS._2.VObj = 0i64;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(v2->OpStack.pCurrent);
    }
  }
  --v2->OpStack.pCurrent;
  if ( v6 )
  {
    if ( (v8[-1].Flags & 0x1F) == 11 )
    {
      v10 = v8[-1].value.VNumber;
      v11 = v7 - 1;
      if ( v11 )
      {
        if ( v11 == 1 )
          Scaleform::GFx::AS3::Value::Assign(v8 - 1, (Scaleform::GFx::AS3::Value *)(*(_QWORD *)&v10 + 72i64));
      }
      else
      {
        Scaleform::GFx::AS3::Value::Assign(v8 - 1, (Scaleform::GFx::ASString *)(*(_QWORD *)&v10 + 56i64));
      }
    }
    else
    {
      (*((void (__fastcall **)(_QWORD, Scaleform::GFx::AS3::Value *, _QWORD))v8[-1].value.VS._1.VStr->pData + 17))(
        *(_QWORD *)&v8[-1].value.VNumber,
        v8 - 1,
        v7);
    }
  }
}

// File Line: 2073
// RVA: 0x8421D0
void __fastcall Scaleform::GFx::AS3::VM::exec_in(Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::VM *v1; // r15
  Scaleform::GFx::AS3::Value *v2; // rdx
  unsigned int v3; // ebx
  Scaleform::GFx::AS3::WeakProxy *v4; // rsi
  long double v5; // rcx
  Scaleform::GFx::AS3::Value *v6; // r12
  int v7; // er14
  Scaleform::GFx::AS3::GASRefCountBase *v8; // rcx
  long double v9; // r13
  __int64 v10; // rax
  __int64 v11; // r8
  Scaleform::GFx::ASString *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  bool v14; // zf
  Scaleform::GFx::ASStringNode *v15; // rcx
  char v16; // al
  bool v17; // al
  Scaleform::GFx::AS3::VM::Error *v18; // rax
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::GFx::AS3::Value scope; // [rsp+30h] [rbp-79h]
  Scaleform::GFx::AS3::Value *v21; // [rsp+50h] [rbp-59h]
  Scaleform::GFx::AS3::Multiname mn; // [rsp+58h] [rbp-51h]
  Scaleform::GFx::AS3::PropRef v23; // [rsp+88h] [rbp-21h]
  __int64 v24; // [rsp+B8h] [rbp+Fh]
  Scaleform::GFx::AS3::VM::Error v25; // [rsp+C0h] [rbp+17h]
  Scaleform::GFx::ASString result; // [rsp+110h] [rbp+67h]
  Scaleform::GFx::ASString v27; // [rsp+118h] [rbp+6Fh]
  long double v28; // [rsp+120h] [rbp+77h]

  v24 = -2i64;
  v1 = this;
  v2 = this->OpStack.pCurrent;
  scope.Flags = v2->Flags;
  v3 = scope.Flags;
  v4 = v2->Bonus.pWeakProxy;
  scope.Bonus.pWeakProxy = v2->Bonus.pWeakProxy;
  v5 = v2->value.VNumber;
  v28 = v5;
  scope.value.VNumber = v5;
  scope.value.VS._2.VObj = v2->value.VS._2.VObj;
  v1->OpStack.pCurrent = v2 - 1;
  v6 = v1->OpStack.pCurrent;
  v21 = v1->OpStack.pCurrent;
  v7 = v3 & 0x1F;
  if ( v3 & 0x1F && ((unsigned int)(v7 - 12) > 3 && v7 != 10 || v5 != 0.0) )
  {
    v8 = (Scaleform::GFx::AS3::GASRefCountBase *)&v1->PublicNamespace.pObject->vfptr;
    mn.Kind = 0;
    mn.Obj.pObject = v8;
    if ( v8 )
      v8->RefCount = (v8->RefCount + 1) & 0x8FBFFFFF;
    mn.Name.Flags = 0;
    mn.Name.Bonus.pWeakProxy = 0i64;
    if ( (v6->Flags & 0x1F) - 12 <= 3
      && (v9 = v6->value.VNumber, v9 != 0.0)
      && (v10 = *(_QWORD *)(*(_QWORD *)&v9 + 40i64), *(_DWORD *)(v10 + 120) == 17)
      && ~(*(_BYTE *)(v10 + 112) >> 5) & 1 )
    {
      Scaleform::GFx::AS3::Value::Assign(&mn.Name, (Scaleform::GFx::ASString *)(*(_QWORD *)&v9 + 56i64));
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&mn.Obj,
        *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(*(_QWORD *)&v9 + 64i64));
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
            v13 = v27.pNode;
            v14 = v27.pNode->RefCount == 1;
            --v13->RefCount;
            if ( v14 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v13);
          }
        }
        v15 = result.pNode;
        v14 = result.pNode->RefCount == 1;
        --v15->RefCount;
        if ( v14 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v15);
      }
    }
    if ( (unsigned int)(v7 - 12) > 3 )
    {
      v23.pSI = 0i64;
      v23.SlotIndex = 0i64;
      v23.This.Flags = 0;
      v23.This.Bonus.pWeakProxy = 0i64;
      Scaleform::GFx::AS3::FindObjProperty(&v23, v1, &scope, &mn, 0);
      v17 = v23.This.Flags & 0x1F
         && (!((_QWORD)v23.pSI & 1) || (_QWORD)v23.pSI & 0xFFFFFFFFFFFFFFFEui64)
         && (!((LOBYTE(v23.pSI) >> 1) & 1) || (_QWORD)v23.pSI & 0xFFFFFFFFFFFFFFFDui64);
      Scaleform::GFx::AS3::Value::SetBool(v6, v17);
      if ( (v23.This.Flags & 0x1F) > 9 )
      {
        if ( (v23.This.Flags >> 9) & 1 )
        {
          v14 = v23.This.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v14 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          v23.This.Bonus.pWeakProxy = 0i64;
          v23.This.value = 0ui64;
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
      v16 = (*(__int64 (__fastcall **)(long double, Scaleform::GFx::AS3::Multiname *, __int64))(**(_QWORD **)&v28 + 48i64))(
              COERCE_LONG_DOUBLE(*(_QWORD *)&v28),
              &mn,
              v11);
      Scaleform::GFx::AS3::Value::SetBool(v6, v16);
      Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
    }
    if ( v7 > 9 )
    {
      if ( (v3 >> 9) & 1 )
      {
        v14 = v4->RefCount-- == 1;
        if ( v14 )
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v4);
LABEL_45:
        scope.Flags = v3 & 0xFFFFFDE0;
        scope.Bonus.pWeakProxy = 0i64;
        scope.value = 0ui64;
        return;
      }
LABEL_46:
      Scaleform::GFx::AS3::Value::ReleaseInternal(&scope);
      return;
    }
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v25, eConvertNullToObjectError, v1);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v1, v18, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v19 = v25.Message.pNode;
    v14 = v25.Message.pNode->RefCount == 1;
    --v19->RefCount;
    if ( v14 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v19);
    if ( v7 > 9 )
    {
      if ( (v3 >> 9) & 1 )
      {
        v14 = v4->RefCount-- == 1;
        if ( v14 )
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v4);
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
  unsigned __int64 v2; // rbp
  Scaleform::GFx::AS3::VM *v3; // rbx
  Scaleform::GFx::AS3::Value *v4; // rsi
  int v5; // er8
  char v6; // al
  Scaleform::GFx::AS3::VM::Error *v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::AS3::VM::ErrorID v10; // edi
  Scaleform::GFx::AS3::WeakProxy *v11; // rbx
  Scaleform::GFx::AS3::Object *obj; // rcx
  Scaleform::GFx::AS3::VM::Error v13; // [rsp+38h] [rbp-40h]
  Scaleform::GFx::AS3::Object *v14; // [rsp+48h] [rbp-30h]
  Scaleform::GFx::AS3::Value::V2U v15; // [rsp+50h] [rbp-28h]
  Scaleform::GFx::AS3::CheckResult result; // [rsp+80h] [rbp+8h]

  v2 = slot_ind;
  v3 = this;
  v4 = this->OpStack.pCurrent;
  v5 = v4->Flags & 0x1F;
  if ( !v5 || ((unsigned int)(v5 - 12) <= 3 || v5 == 10) && !*(_QWORD *)&v4->value.VNumber )
  {
    if ( (unsigned int)(v5 - 12) > 3 && v5 != 10 || (v6 = 1, *(_QWORD *)&v4->value.VNumber) )
      v6 = 0;
    Scaleform::GFx::AS3::VM::Error::Error(&v13, (Scaleform::GFx::AS3::VM::ErrorID)(1010 - (v6 != 0)), this);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v3, v7, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v8 = v13.Message.pNode;
    v9 = v13.Message.pNode->RefCount == 1;
    --v8->RefCount;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  }
  if ( !v3->HandleException )
  {
    v13.ID = v4->Flags;
    v10 = v13.ID;
    v11 = v4->Bonus.pWeakProxy;
    v13.Message.pNode = (Scaleform::GFx::ASStringNode *)v4->Bonus.pWeakProxy;
    v14 = v4->value.VS._1.VObj;
    obj = v14;
    v15.VObj = (Scaleform::GFx::AS3::Object *)v4->value.VS._2;
    v4->Flags = 0;
    Scaleform::GFx::AS3::Traits::GetSlotValueUnsafe(
      obj->pTraits.pObject,
      &result,
      v4,
      (Scaleform::GFx::AS3::AbsoluteIndex)(v2 - 1),
      obj);
    if ( (v10 & 0x1F) > 9 )
    {
      if ( ((unsigned int)v10 >> 9) & 1 )
      {
        v9 = v11->RefCount-- == 1;
        if ( v9 )
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v11);
        v13.Message.pNode = 0i64;
        v14 = 0i64;
        v15.VObj = 0i64;
        v13.ID = v10 & 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v13);
      }
    }
  }
}

// File Line: 2229
// RVA: 0x7CAFA0
Scaleform::GFx::AS3::VM::ExecuteCode

