// File Line: 93
// RVA: 0x80EAC0
int __fastcall Scaleform::GFx::AS3::TR::StackReader::Read(
        Scaleform::GFx::AS3::TR::StackReader *this,
        Scaleform::GFx::AS3::Multiname *obj)
{
  bool v4; // zf
  Scaleform::GFx::AS3::Value *v6; // rax
  Scaleform::GFx::AS3::Value *v7; // rax
  Scaleform::GFx::AS3::Value v8; // [rsp+18h] [rbp-39h] BYREF
  Scaleform::GFx::AS3::Value v9; // [rsp+38h] [rbp-19h] BYREF
  Scaleform::GFx::AS3::Value v10; // [rsp+58h] [rbp+7h] BYREF
  __int64 v11; // [rsp+78h] [rbp+27h]
  Scaleform::GFx::AS3::Value result; // [rsp+80h] [rbp+2Fh] BYREF

  v11 = -2i64;
  switch ( obj->Kind )
  {
    case MN_RTQName:
    case MN_RTQNameA:
      Scaleform::GFx::AS3::TR::State::PopOpValue(this->StateRef, &result);
      if ( (result.Flags & 0x1F) > 9 )
      {
        if ( (result.Flags & 0x200) != 0 )
        {
          v4 = result.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v4 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
        }
      }
      return 1;
    case MN_RTQNameL:
    case MN_RTQNameLA:
      Scaleform::GFx::AS3::TR::State::PopOpValue(this->StateRef, &v10);
      if ( (v10.Flags & 0x1F) > 9 )
      {
        if ( (v10.Flags & 0x200) != 0 )
        {
          v4 = v10.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v4 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&v10.Bonus, 0, 24);
          v10.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
        }
      }
      v6 = Scaleform::GFx::AS3::TR::State::PopOpValue(this->StateRef, &v9);
      Scaleform::GFx::AS3::Value::Assign(&obj->Name, v6);
      if ( (v9.Flags & 0x1F) > 9 )
      {
        if ( (v9.Flags & 0x200) != 0 )
        {
          v4 = v9.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v4 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&v9.Bonus, 0, 24);
          v9.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v9);
        }
      }
      return 2;
    case MN_MultinameL:
    case MN_MultinameLA:
      v7 = Scaleform::GFx::AS3::TR::State::PopOpValue(this->StateRef, &v8);
      Scaleform::GFx::AS3::Value::Assign(&obj->Name, v7);
      if ( (v8.Flags & 0x1F) <= 9 )
        return 1;
      if ( (v8.Flags & 0x200) != 0 )
      {
        v4 = v8.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v4 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&v8.Bonus, 0, 24);
        v8.Flags &= 0xFFFFFDE0;
        return 1;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v8);
        return 1;
      }
    case MN_Typename:
      this->VMRef->UI->vfptr->Output(this->VMRef->UI, Output_Warning, "Reading chained multiname in itself.");
      return Scaleform::GFx::AS3::TR::StackReader::Read(this, obj);
    default:
      return 0;
  }
}

// File Line: 164
// RVA: 0x781960
void __fastcall Scaleform::GFx::AS3::TR::ReadArgs::ReadArgs(
        Scaleform::GFx::AS3::TR::ReadArgs *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::TR::State *s,
        unsigned int arg_count)
{
  __int64 v4; // r13
  int v6; // ebp
  Scaleform::MemoryHeap *MHeap; // rax
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *p_CallArgs; // r15
  unsigned __int64 Size; // rsi
  unsigned __int64 v10; // rdi
  unsigned __int64 v11; // rbx
  __int64 v12; // rsi
  unsigned __int64 v13; // r12
  __int64 v14; // rsi
  Scaleform::GFx::AS3::Value *v15; // rbx
  Scaleform::GFx::AS3::TR::State *StateRef; // rbx
  unsigned __int64 v17; // rsi
  __int64 v18; // rax
  unsigned __int64 i; // rdi

  v4 = arg_count;
  this->VMRef = vm;
  this->StateRef = s;
  v6 = 0;
  this->Num = 0;
  this->ArgNum = arg_count;
  MHeap = vm->MHeap;
  p_CallArgs = &this->CallArgs;
  this->CallArgs.Data.Data = 0i64;
  this->CallArgs.Data.Size = 0i64;
  this->CallArgs.Data.Policy.Capacity = 0i64;
  this->CallArgs.Data.pHeap = MHeap;
  `eh vector constructor iterator(
    this->FixedArr,
    0x20ui64,
    8,
    (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::Value);
  if ( (_DWORD)v4 )
  {
    Size = this->StateRef->OpStack.Data.Size;
    v10 = Size - v4;
    if ( (unsigned int)v4 > 8 )
    {
      if ( v10 < Size )
      {
        v13 = v10;
        v14 = v4;
        do
        {
          v15 = &this->StateRef->OpStack.Data.Data[v13];
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
            &p_CallArgs->Data,
            p_CallArgs->Data.pHeap,
            p_CallArgs->Data.Size + 1);
          Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
            &p_CallArgs->Data.Data[p_CallArgs->Data.Size - 1],
            v15);
          ++v13;
          --v14;
        }
        while ( v14 );
      }
    }
    else if ( v10 < Size )
    {
      v11 = v10;
      v12 = v4;
      do
      {
        Scaleform::GFx::AS3::Value::Assign(&this->FixedArr[v6++], &this->StateRef->OpStack.Data.Data[v11++]);
        --v12;
      }
      while ( v12 );
    }
    StateRef = this->StateRef;
    v17 = StateRef->OpStack.Data.Size;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &StateRef->OpStack.Data,
      StateRef->OpStack.Data.pHeap,
      v10);
    if ( v10 > v17 )
    {
      v18 = (__int64)&StateRef->OpStack.Data.Data[v17];
      for ( i = v10 - v17; i; --i )
      {
        if ( v18 )
        {
          *(_DWORD *)v18 = 0;
          *(_QWORD *)(v18 + 8) = 0i64;
        }
        v18 += 32i64;
      }
    }
  }
  this->Num += v4;
}

// File Line: 193
// RVA: 0x83D460
void __fastcall Scaleform::GFx::AS3::TR::State::exec_construct(
        Scaleform::GFx::AS3::TR::State *this,
        unsigned int arg_count)
{
  Scaleform::GFx::AS3::Tracer *pTracer; // r14
  int v5; // ebx
  Scaleform::GFx::AS3::Value::V1U VObj; // rsi
  Scaleform::GFx::AS3::Traits *pTraits; // rcx
  Scaleform::GFx::AS3::VM *VMRef; // rax
  int v9; // ebx
  int v10; // ebx
  int v11; // ebx
  unsigned __int64 Size; // rcx
  Scaleform::GFx::AS3::Value *v13; // rdx
  bool v14; // zf
  Scaleform::GFx::AS3::Value *v15; // rdx
  Scaleform::GFx::AS3::Value::V2U v16; // rax
  Scaleform::GFx::AS3::Value::V1U v17; // rcx
  char v18; // al
  Scaleform::GFx::AS3::Value::V1U pData; // rax
  Scaleform::GFx::AS3::Value source; // [rsp+20h] [rbp-C8h] BYREF
  __int64 v21; // [rsp+40h] [rbp-A8h]
  Scaleform::GFx::AS3::TR::ReadArgsObject v22; // [rsp+50h] [rbp-98h] BYREF
  Scaleform::GFx::AS3::Value *v23; // [rsp+1B8h] [rbp+D0h]
  Scaleform::GFx::AS3::Value *retaddr; // [rsp+1C8h] [rbp+E0h]

  v21 = -2i64;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_construct, arg_count);
  Scaleform::GFx::AS3::TR::ReadArgs::ReadArgs(&v22, this->pTracer->CF->pFile->VMRef, this, arg_count);
  Scaleform::GFx::AS3::TR::State::PopOpValue(this, (Scaleform::GFx::AS3::Value *)&v22.FixedArr[7].Bonus);
  ++v22.Num;
  pTracer = this->pTracer;
  v5 = (__int64)v22.FixedArr[7].Bonus.pWeakProxy & 0x1F;
  VObj = (Scaleform::GFx::AS3::Value::V1U)v22.FixedArr[7].value.VS._2.VObj;
  if ( ((__int64)v22.FixedArr[7].Bonus.pWeakProxy & 0x1F) != 0 )
  {
    if ( (unsigned __int64)(((__int64)v22.FixedArr[7].Bonus.pWeakProxy & 0x1F) - 8) < 2 )
      pTraits = v22.FixedArr[7].value.VS._2.pTraits;
    else
      pTraits = Scaleform::GFx::AS3::VM::GetValueTraits(
                  pTracer->CF->pFile->VMRef,
                  (Scaleform::GFx::AS3::Value *)&v22.FixedArr[7].Bonus);
  }
  else
  {
    pTraits = pTracer->CF->pFile->VMRef->TraitsVoid.pObject;
  }
  if ( pTraits )
  {
    VMRef = pTracer->CF->pFile->VMRef;
    if ( pTraits == VMRef->TraitsClassClass.pObject )
      pTraits = VMRef->TraitsObject.pObject;
  }
  v9 = v5 - 8;
  if ( v9 )
  {
    v10 = v9 - 1;
    if ( v10 )
    {
      v11 = v10 - 3;
      if ( v11 )
      {
        if ( v11 == 1 )
        {
          v17 = *(Scaleform::GFx::AS3::Value::V1U *)(VObj.VStr[1].pData + 200);
          source.Bonus.pWeakProxy = 0i64;
          source.value.VS._1 = v17;
          source.Flags = 8;
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
            &this->OpStack.Data,
            (__int64 *)this->OpStack.Data.pHeap,
            this->OpStack.Data.Size + 1);
          Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
            &this->OpStack.Data.Data[this->OpStack.Data.Size - 1].Flags,
            &source);
        }
        else
        {
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
            &this->OpStack.Data,
            (__int64 *)this->OpStack.Data.pHeap,
            this->OpStack.Data.Size + 1);
          Size = this->OpStack.Data.Size;
          v13 = this->OpStack.Data.Data - 1;
          v14 = &v13[Size] == 0i64;
          v15 = &v13[Size];
          v23 = v15;
          retaddr = v15;
          if ( !v14 )
          {
            v15->Flags = (unsigned int)v22.FixedArr[7].Bonus.pWeakProxy;
            v15->Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v22.FixedArr[7].value.VS._1.VStr;
            v15->value = *(Scaleform::GFx::AS3::Value::VU *)&v22.FixedArr[7].value.VS._2.VObj;
            if ( (unsigned __int64)((__int64)v22.FixedArr[7].Bonus.pWeakProxy & 0x1F) > 9 )
            {
              if ( ((__int64)v22.FixedArr[7].Bonus.pWeakProxy & 0x200) != 0 )
              {
                ++LODWORD(v22.FixedArr[7].value.VS._1.VStr->pData);
              }
              else
              {
                if ( ((__int64)v22.FixedArr[7].Bonus.pWeakProxy & 0x1F) == 10 )
                {
                  ++LODWORD(v22.FixedArr[7].value.VS._2.VObj->pPrev);
                  goto LABEL_34;
                }
                if ( (unsigned __int64)((__int64)v22.FixedArr[7].Bonus.pWeakProxy & 0x1F) > 0xA )
                {
                  if ( (unsigned __int64)((__int64)v22.FixedArr[7].Bonus.pWeakProxy & 0x1F) <= 0xF )
                  {
                    v16.VObj = (Scaleform::GFx::AS3::Object *)v22.FixedArr[7].value.VS._2;
                  }
                  else
                  {
                    if ( (unsigned __int64)((__int64)v22.FixedArr[7].Bonus.pWeakProxy & 0x1F) > 0x11 )
                      goto LABEL_34;
                    v16.VObj = *(Scaleform::GFx::AS3::Object **)&v22.ArgObject.Flags;
                  }
                  if ( v16.VObj )
                  {
                    ++v16.VObj->RefCount;
                    v16.VObj->RefCount &= 0x8FBFFFFF;
                  }
                }
              }
            }
          }
        }
      }
      else
      {
        v18 = ~(LOBYTE(pTraits->Flags) >> 5);
        source.Bonus.pWeakProxy = 0i64;
        source.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)pTraits;
        if ( (v18 & 1) != 0 )
          source.Flags = 8;
        else
          source.Flags = 9;
        Scaleform::GFx::AS3::TR::State::PushOp(this, &source);
      }
    }
    else
    {
      pData = (Scaleform::GFx::AS3::Value::V1U)VObj.VStr[5].pData;
      source.Bonus.pWeakProxy = 0i64;
      source.value.VS._1 = pData;
      source.Flags = 8;
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        &this->OpStack.Data,
        (__int64 *)this->OpStack.Data.pHeap,
        this->OpStack.Data.Size + 1);
      Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
        &this->OpStack.Data.Data[this->OpStack.Data.Size - 1].Flags,
        &source);
    }
  }
  else
  {
    source.Bonus.pWeakProxy = 0i64;
    source.value.VS._1 = VObj;
    source.Flags = 8;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &this->OpStack.Data,
      (__int64 *)this->OpStack.Data.pHeap,
      this->OpStack.Data.Size + 1);
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
      &this->OpStack.Data.Data[this->OpStack.Data.Size - 1].Flags,
      &source);
  }
LABEL_34:
  Scaleform::GFx::AS3::TR::ReadArgsObject::~ReadArgsObject(&v22);
}

// File Line: 266
// RVA: 0x83E320
void __fastcall Scaleform::GFx::AS3::TR::State::exec_constructsuper(
        Scaleform::GFx::AS3::TR::State *this,
        unsigned int arg_count)
{
  Scaleform::GFx::AS3::TR::ReadArgsObject v4; // [rsp+30h] [rbp-168h] BYREF

  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_constructsuper, arg_count);
  Scaleform::GFx::AS3::TR::ReadArgs::ReadArgs(&v4, this->pTracer->CF->pFile->VMRef, this, arg_count);
  Scaleform::GFx::AS3::TR::State::PopOpValue(this, &v4.ArgObject);
  ++v4.Num;
  Scaleform::GFx::AS3::TR::ReadArgsObject::~ReadArgsObject(&v4);
}

// File Line: 277
// RVA: 0x7E9DB0
Scaleform::GFx::AS3::InstanceTraits::Thunk *__fastcall Scaleform::GFx::AS3::TR::State::GetFunctType(
        Scaleform::GFx::AS3::TR::State *this,
        Scaleform::GFx::AS3::Value *value)
{
  if ( (value->Flags & 0x1F) == 5 )
    return this->pTracer->CF->pFile->VMRef->TraitsFunction.pObject->ThunkTraits.pObject;
  if ( (value->Flags & 0x1F) != 7 )
  {
    if ( (value->Flags & 0x1F) == 16 )
      return (Scaleform::GFx::AS3::InstanceTraits::Thunk *)this->pTracer->CF->pFile->VMRef->TraitsFunction.pObject->ThunkFunctionTraits.pObject;
    if ( (value->Flags & 0x1F) != 17 )
      return (Scaleform::GFx::AS3::InstanceTraits::Thunk *)this->pTracer->CF->pFile->VMRef->TraitsFunction.pObject->ITraits.pObject;
  }
  return (Scaleform::GFx::AS3::InstanceTraits::Thunk *)this->pTracer->CF->pFile->VMRef->TraitsFunction.pObject->VTableTraits.pObject;
}

// File Line: 295
// RVA: 0x7EE2E0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::TR::State::GetPropertyType(
        Scaleform::GFx::AS3::TR::State *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Traits *obj_traits,
        Scaleform::GFx::AS3::SlotInfo *si,
        Scaleform::GFx::AS3::Value *type)
{
  __int64 v8; // rcx
  int v9; // eax
  __int64 v10; // rbx
  Scaleform::GFx::AS3::VTable *VT; // rax
  Scaleform::GFx::AS3::Value *Value; // rax
  Scaleform::GFx::AS3::InstanceTraits::Thunk *FunctType; // rbx
  bool v14; // zf
  int CanBeNull; // eax
  Scaleform::GFx::AS3::VMAppDomain *pObject; // rdi
  Scaleform::GFx::AS3::VTable *v17; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *FunctReturnType; // rbx
  Scaleform::GFx::AS3::VM *VMRef; // rbx
  Scaleform::GFx::AS3::ClassTraits::Traits *DataType; // r15
  Scaleform::GFx::AS3::VM::Error *v21; // rax
  Scaleform::GFx::ASStringNode *pWeakProxy; // rcx
  Scaleform::GFx::AS3::Abc::TraitInfo *TI; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v24; // rbx
  int v25; // eax
  unsigned int Flags; // ebx
  Scaleform::GFx::AS3::Value resulta; // [rsp+28h] [rbp-28h] BYREF

  v8 = *(_DWORD *)si;
  v9 = (int)(*(_DWORD *)si << 17) >> 27;
  if ( v9 > 10 )
  {
    v10 = v8 >> 15;
    if ( v8 >> 15 >= 0 )
    {
      if ( v9 == 11 )
      {
        VT = Scaleform::GFx::AS3::Traits::GetVT(obj_traits);
        Value = Scaleform::GFx::AS3::VTable::GetValue(VT, &resulta, (Scaleform::GFx::AS3::AbsoluteIndex)v10);
        FunctType = Scaleform::GFx::AS3::TR::State::GetFunctType(this, Value);
        if ( (resulta.Flags & 0x1F) > 9 )
        {
          if ( (resulta.Flags & 0x200) != 0 )
          {
            v14 = resulta.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v14 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            memset(&resulta.Bonus, 0, 24);
            resulta.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&resulta);
          }
        }
        CanBeNull = Scaleform::GFx::AS3::TR::State::CanBeNull(this, FunctType);
        resulta.Bonus.pWeakProxy = 0i64;
        resulta.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)FunctType;
        resulta.Flags = (32 * CanBeNull) & 0xFFFFFEF7 | 8;
        Scaleform::GFx::AS3::Value::Assign(type, &resulta);
      }
      else
      {
        pObject = this->pTracer->CF->pFile->AppDomain.pObject;
        v17 = Scaleform::GFx::AS3::Traits::GetVT(obj_traits);
        FunctReturnType = Scaleform::GFx::AS3::VM::GetFunctReturnType(
                            this->pTracer->CF->pFile->VMRef,
                            &v17->VTMethods.Data.Data[(unsigned int)v10],
                            pObject);
        resulta.Bonus.pWeakProxy = 0i64;
        resulta.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)FunctReturnType;
        resulta.Flags = (32 * Scaleform::GFx::AS3::TR::State::CanBeNull(this, FunctReturnType)) & 0xFFFFFEF7 | 8;
        Scaleform::GFx::AS3::Value::Assign(type, &resulta);
      }
      goto LABEL_22;
    }
  }
  VMRef = this->pTracer->CF->pFile->VMRef;
  DataType = Scaleform::GFx::AS3::SlotInfo::GetDataType(si, VMRef);
  if ( DataType )
  {
    if ( (*(_DWORD *)si & 0x7C00) == 1024
      || (TI = si->TI) != 0i64 && (TI->kind & 0xF) == 4
      || Scaleform::GFx::AS3::SlotInfo::IsClassType(si) )
    {
      resulta.Bonus.pWeakProxy = 0i64;
      resulta.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)DataType;
      resulta.Flags = 9;
      Scaleform::GFx::AS3::Value::Assign(type, &resulta);
    }
    else
    {
      v24 = DataType->ITraits.pObject;
      v25 = Scaleform::GFx::AS3::TR::State::CanBeNull(this, v24);
      resulta.Bonus.pWeakProxy = 0i64;
      resulta.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)v24;
      resulta.Flags = (32 * v25) & 0xFFFFFEF7 | 8;
      Scaleform::GFx::AS3::Value::Assign(type, &resulta);
    }
LABEL_22:
    Flags = resulta.Flags;
    if ( (resulta.Flags & 0x1F) > 9 )
    {
      if ( (resulta.Flags & 0x200) != 0 )
      {
        v14 = resulta.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v14 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        resulta.Flags = Flags & 0xFFFFFDE0;
        memset(&resulta.Bonus, 0, 24);
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&resulta);
      }
    }
    result->Result = 1;
    return result;
  }
  Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&resulta, 1014, VMRef);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(VMRef, v21, &Scaleform::GFx::AS3::fl::VerifyErrorTI);
  pWeakProxy = (Scaleform::GFx::ASStringNode *)resulta.Bonus.pWeakProxy;
  v14 = LODWORD(resulta.Bonus.pWeakProxy[1].pObject)-- == 1;
  if ( v14 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pWeakProxy);
  result->Result = 0;
  return result;
}

// File Line: 337
// RVA: 0x839480
void __fastcall Scaleform::GFx::AS3::TR::State::exec_call(Scaleform::GFx::AS3::TR::State *this, unsigned int arg_count)
{
  Scaleform::GFx::AS3::VMAbcFile *pFile; // rcx
  Scaleform::GFx::AS3::InstanceTraits::Traits *FunctReturnType; // rax
  Scaleform::GFx::AS3::Value::V1U v6; // r8
  Scaleform::GFx::AS3::VMAbcFile *v7; // r9
  Scaleform::GFx::AS3::VM *VMRef; // rcx
  char v9; // al
  int v10; // edi
  unsigned int v11; // edi
  Scaleform::GFx::AS3::Value source; // [rsp+20h] [rbp-D8h] BYREF
  __int64 v14; // [rsp+40h] [rbp-B8h]
  Scaleform::GFx::AS3::TR::ReadArgs v15; // [rsp+50h] [rbp-A8h] BYREF
  Scaleform::GFx::AS3::Value result; // [rsp+1A8h] [rbp+B0h] BYREF

  v14 = -2i64;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_call, arg_count);
  Scaleform::GFx::AS3::TR::ReadArgs::ReadArgs(&v15, this->pTracer->CF->pFile->VMRef, this, arg_count);
  Scaleform::GFx::AS3::TR::State::PopOpValue(this, (Scaleform::GFx::AS3::Value *)&v15.FixedArr[7].value.VS._2);
  ++v15.Num;
  Scaleform::GFx::AS3::TR::State::PopOpValue(this, &result);
  ++v15.Num;
  pFile = this->pTracer->CF->pFile;
  FunctReturnType = Scaleform::GFx::AS3::VM::GetFunctReturnType(pFile->VMRef, &result, pFile->AppDomain.pObject);
  v6.VStr = (Scaleform::GFx::ASStringNode *)FunctReturnType;
  v7 = this->pTracer->CF->pFile;
  VMRef = v7->VMRef;
  if ( FunctReturnType == VMRef->TraitsInt.pObject->ITraits.pObject
    || FunctReturnType == VMRef->TraitsUint.pObject->ITraits.pObject
    || FunctReturnType == VMRef->TraitsNumber.pObject->ITraits.pObject
    || (v9 = 0, v6.VStr == (Scaleform::GFx::ASStringNode *)v7->VMRef->TraitsBoolean.pObject->ITraits.pObject) )
  {
    v9 = 1;
  }
  source.Flags = 8;
  source.Bonus.pWeakProxy = 0i64;
  source.value.VS._1 = v6;
  v10 = 2;
  if ( v9 )
    v10 = 0;
  v11 = (32 * v10) & 0xFFFFFEF7 | 8;
  source.Flags = v11;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->OpStack.Data,
    (__int64 *)this->OpStack.Data.pHeap,
    this->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &this->OpStack.Data.Data[this->OpStack.Data.Size - 1].Flags,
    &source);
  if ( (v11 & 0x1F) > 9 )
  {
    if ( (v11 & 0x200) != 0 )
    {
      LODWORD(MEMORY[0]) = MEMORY[0] - 1;
      if ( !(_DWORD)MEMORY[0] )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
      memset(&source.Bonus, 0, 24);
      source.Flags = v11 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&source);
    }
  }
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
  Scaleform::GFx::AS3::TR::ReadArgsObject::~ReadArgsObject((Scaleform::GFx::AS3::TR::ReadArgsObject *)&v15);
}

// File Line: 402
// RVA: 0x838D30
void __fastcall Scaleform::GFx::AS3::TR::State::exec_applytype(
        Scaleform::GFx::AS3::TR::State *this,
        unsigned int arg_count)
{
  Scaleform::GFx::AS3::VM *VMRef; // rdi
  Scaleform::GFx::AS3::Value *FixedArr; // rdx
  Scaleform::GFx::AS3::ClassTraits::Traits *pObject; // rbx
  Scaleform::GFx::AS3::ClassTraits::Traits *v7; // rax
  Scaleform::GFx::AS3::Classes::fl_vec::Vector **v8; // rdi
  Scaleform::GFx::AS3::Value source; // [rsp+20h] [rbp-198h] BYREF
  __int64 v10; // [rsp+40h] [rbp-178h]
  Scaleform::GFx::AS3::TR::ReadArgsObject v11; // [rsp+50h] [rbp-168h] BYREF

  v10 = -2i64;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_applytype, arg_count);
  VMRef = this->pTracer->CF->pFile->VMRef;
  Scaleform::GFx::AS3::TR::ReadArgs::ReadArgs(&v11, VMRef, this, arg_count);
  Scaleform::GFx::AS3::TR::State::PopOpValue(this, &v11.ArgObject);
  ++v11.Num;
  FixedArr = v11.FixedArr;
  if ( v11.ArgNum <= v11.CallArgs.Data.Size )
    FixedArr = v11.CallArgs.Data.Data;
  pObject = 0i64;
  switch ( FixedArr->Flags & 0x1F )
  {
    case 0u:
LABEL_11:
      pObject = VMRef->TraitsObject.pObject;
      break;
    case 9u:
      pObject = FixedArr->value.VS._1.CTr;
      break;
    case 12u:
      if ( FixedArr->value.VS._1.VStr )
        break;
      goto LABEL_11;
    case 13u:
      pObject = (Scaleform::GFx::AS3::ClassTraits::Traits *)FixedArr->value.VS._1.VStr[1].pData;
      break;
  }
  v7 = VMRef->TraitsObject.pObject;
  if ( pObject )
  {
    switch ( pObject->TraitsType )
    {
      case Traits_SInt:
        v7 = VMRef->TraitsVector_int.pObject;
        break;
      case Traits_UInt:
        v7 = VMRef->TraitsVector_uint.pObject;
        break;
      case Traits_Number:
        v7 = VMRef->TraitsVector_Number.pObject;
        break;
      case Traits_String:
        v7 = VMRef->TraitsVector_String.pObject;
        break;
      default:
        v8 = (Scaleform::GFx::AS3::Classes::fl_vec::Vector **)VMRef->TraitsVector.pObject->ITraits.pObject;
        if ( !v8[17] )
          ((void (__fastcall *)(Scaleform::GFx::AS3::Classes::fl_vec::Vector **))(*v8)[1]._pRCC)(v8);
        v7 = Scaleform::GFx::AS3::Classes::fl_vec::Vector::Resolve2Vector(v8[17], pObject);
        break;
    }
  }
  source.Bonus.pWeakProxy = 0i64;
  source.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)v7;
  source.Flags = 9;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->OpStack.Data,
    (__int64 *)this->OpStack.Data.pHeap,
    this->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &this->OpStack.Data.Data[this->OpStack.Data.Size - 1].Flags,
    &source);
  Scaleform::GFx::AS3::TR::ReadArgsObject::~ReadArgsObject(&v11);
}

// File Line: 485
// RVA: 0x843A40
void __fastcall Scaleform::GFx::AS3::TR::State::exec_newobject(
        Scaleform::GFx::AS3::TR::State *this,
        unsigned int arg_count)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // rcx
  Scaleform::GFx::AS3::Value source; // [rsp+20h] [rbp-178h] BYREF
  __int64 v6; // [rsp+40h] [rbp-158h]
  Scaleform::GFx::AS3::TR::ReadArgs ptr; // [rsp+50h] [rbp-148h] BYREF

  v6 = -2i64;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_newobject, arg_count);
  Scaleform::GFx::AS3::TR::ReadArgs::ReadArgs(&ptr, this->pTracer->CF->pFile->VMRef, this, 2 * arg_count);
  pObject = this->pTracer->CF->pFile->VMRef->TraitsObject.pObject->ITraits.pObject;
  source.Bonus.pWeakProxy = 0i64;
  source.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)pObject;
  source.Flags = 8;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->OpStack.Data,
    (__int64 *)this->OpStack.Data.pHeap,
    this->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &this->OpStack.Data.Data[this->OpStack.Data.Size - 1].Flags,
    &source);
  `eh vector destructor iterator(
    ptr.FixedArr,
    0x20ui64,
    8,
    (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(ptr.CallArgs.Data.Data, ptr.CallArgs.Data.Size);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, ptr.CallArgs.Data.Data);
}

// File Line: 506
// RVA: 0x842EF0
void __fastcall Scaleform::GFx::AS3::TR::State::exec_newarray(
        Scaleform::GFx::AS3::TR::State *this,
        unsigned int arr_size)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // rcx
  Scaleform::GFx::AS3::Value source; // [rsp+20h] [rbp-178h] BYREF
  __int64 v6; // [rsp+40h] [rbp-158h]
  Scaleform::GFx::AS3::TR::ReadArgs ptr; // [rsp+50h] [rbp-148h] BYREF

  v6 = -2i64;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_newarray, arr_size);
  Scaleform::GFx::AS3::TR::ReadArgs::ReadArgs(&ptr, this->pTracer->CF->pFile->VMRef, this, arr_size);
  pObject = this->pTracer->CF->pFile->VMRef->TraitsArray.pObject->ITraits.pObject;
  source.Bonus.pWeakProxy = 0i64;
  source.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)pObject;
  source.Flags = 8;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->OpStack.Data,
    (__int64 *)this->OpStack.Data.pHeap,
    this->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &this->OpStack.Data.Data[this->OpStack.Data.Size - 1].Flags,
    &source);
  `eh vector destructor iterator(
    ptr.FixedArr,
    0x20ui64,
    8,
    (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(ptr.CallArgs.Data.Data, ptr.CallArgs.Data.Size);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, ptr.CallArgs.Data.Data);
}

// File Line: 550
// RVA: 0x842CA0
void __fastcall Scaleform::GFx::AS3::TR::State::exec_li8(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::VM::Error *v2; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v5; // [rsp+28h] [rbp-20h] BYREF

  Scaleform::GFx::AS3::VM::Error::Error(&v5, 1001, this->pTracer->CF->pFile->VMRef);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(
    this->pTracer->CF->pFile->VMRef,
    v2,
    &Scaleform::GFx::AS3::fl::VerifyErrorTI);
  pNode = v5.Message.pNode;
  if ( v5.Message.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 606
// RVA: 0x843830
void __fastcall Scaleform::GFx::AS3::TR::State::exec_newfunction(
        Scaleform::GFx::AS3::TR::State *this,
        unsigned int method_ind)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // rdx
  Scaleform::GFx::AS3::Value source; // [rsp+28h] [rbp-30h] BYREF

  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_newfunction, method_ind);
  pObject = this->pTracer->CF->pFile->VMRef->TraitsFunction.pObject->ITraits.pObject;
  source.Bonus.pWeakProxy = 0i64;
  source.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)pObject;
  source.Flags = 8;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->OpStack.Data,
    (__int64 *)this->OpStack.Data.pHeap,
    this->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &this->OpStack.Data.Data[this->OpStack.Data.Size - 1].Flags,
    &source);
}

// File Line: 635
// RVA: 0x83FDA0
void __fastcall Scaleform::GFx::AS3::TR::State::exec_getdescendants(
        Scaleform::GFx::AS3::TR::State *this,
        unsigned int mn_index)
{
  Scaleform::GFx::AS3::Tracer *pTracer; // rcx
  Scaleform::GFx::AS3::VM::Error *v4; // rax
  Scaleform::GFx::ASStringNode *pWeakProxy; // rcx
  bool v6; // zf
  __int64 v7; // rbx
  Scaleform::GFx::AS3::VMAbcFile *pFile; // rdx
  int v9; // eax
  Scaleform::GFx::AS3::XMLSupport *pObject; // rcx
  Scaleform::GFx::AS3::Value::V1U v11; // rax
  Scaleform::GFx::AS3::Value v12; // [rsp+18h] [rbp-49h] BYREF
  Scaleform::GFx::AS3::TR::StackReader v13; // [rsp+38h] [rbp-29h] BYREF
  Scaleform::GFx::AS3::VMAbcFile *v14; // [rsp+50h] [rbp-11h]
  Scaleform::GFx::AS3::Multiname obj; // [rsp+58h] [rbp-9h] BYREF
  Scaleform::GFx::AS3::Value result; // [rsp+88h] [rbp+27h] BYREF
  __int64 v17; // [rsp+A8h] [rbp+47h]

  v17 = -2i64;
  pTracer = this->pTracer;
  if ( pTracer->CF->pFile->VMRef->XMLSupport_.pObject->Enabled )
  {
    v7 = mn_index;
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(pTracer, op_getdescendants, mn_index);
    pFile = this->pTracer->CF->pFile;
    v13.VMRef = pFile->VMRef;
    v13.StateRef = this;
    v13.Num = 0;
    v14 = pFile;
    Scaleform::GFx::AS3::Multiname::Multiname(
      &obj,
      pFile,
      &pFile->File.pObject->Const_Pool.const_multiname.Data.Data[v7]);
    v9 = Scaleform::GFx::AS3::TR::StackReader::Read(&v13, &obj);
    v13.Num += v9;
    Scaleform::GFx::AS3::TR::State::PopOpValue(this, &result);
    ++v13.Num;
    pObject = this->pTracer->CF->pFile->VMRef->XMLSupport_.pObject;
    v11.VStr = (Scaleform::GFx::ASStringNode *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::XMLSupport *))pObject->vfptr[4].~RefCountBaseGC<328>)(pObject);
    v12.Bonus.pWeakProxy = 0i64;
    v12.value.VS._1 = v11;
    v12.Flags = 8;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &this->OpStack.Data,
      (__int64 *)this->OpStack.Data.pHeap,
      this->OpStack.Data.Size + 1);
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
      &this->OpStack.Data.Data[this->OpStack.Data.Size - 1].Flags,
      &v12);
    if ( (result.Flags & 0x1F) > 9 )
    {
      if ( (result.Flags & 0x200) != 0 )
      {
        v6 = result.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v6 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&result.Bonus, 0, 24);
        result.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
      }
    }
    Scaleform::GFx::AS3::Multiname::~Multiname(&obj);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v12, 1001, pTracer->CF->pFile->VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTracer->CF->pFile->VMRef,
      v4,
      &Scaleform::GFx::AS3::fl::VerifyErrorTI);
    pWeakProxy = (Scaleform::GFx::ASStringNode *)v12.Bonus.pWeakProxy;
    v6 = LODWORD(v12.Bonus.pWeakProxy[1].pObject)-- == 1;
    if ( v6 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pWeakProxy);
  }
}

// File Line: 663
// RVA: 0x8430E0
void __fastcall Scaleform::GFx::AS3::TR::State::exec_newcatch(Scaleform::GFx::AS3::TR::State *this, unsigned int v)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // rdx
  Scaleform::GFx::AS3::Value source; // [rsp+28h] [rbp-30h] BYREF

  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_newcatch, v);
  pObject = this->pTracer->CF->pFile->VMRef->TraitsObject.pObject->ITraits.pObject;
  source.Bonus.pWeakProxy = 0i64;
  source.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)pObject;
  source.Flags = 8;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->OpStack.Data,
    (__int64 *)this->OpStack.Data.pHeap,
    this->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &this->OpStack.Data.Data[this->OpStack.Data.Size - 1].Flags,
    &source);
}

// File Line: 690
// RVA: 0x7D32B0
void __fastcall Scaleform::GFx::AS3::TR::State::FindProp(
        Scaleform::GFx::AS3::TR::State *this,
        Scaleform::GFx::AS3::PropRef *result,
        Scaleform::GFx::AS3::Multiname *mn,
        Scaleform::GFx::AS3::TR::State::ScopeType *stype,
        unsigned __int64 *scope_index)
{
  Scaleform::GFx::AS3::TR::State *v7; // r8
  Scaleform::GFx::AS3::VM *VMRef; // r14
  unsigned __int64 Size; // rsi
  __int64 v10; // rbx
  Scaleform::GFx::AS3::Value *v11; // r13
  Scaleform::GFx::AS3::Traits *v12; // rax
  Scaleform::GFx::AS3::Traits *v13; // rdi
  Scaleform::GFx::AS3::SlotInfo *v14; // rax
  Scaleform::GFx::AS3::PropRef *v15; // rax
  bool v16; // zf
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *pSavedScope; // r13
  unsigned __int64 v18; // rdi
  __int64 v19; // rbx
  Scaleform::GFx::AS3::Value *v20; // rsi
  Scaleform::GFx::AS3::Traits *ValueTraits; // rax
  Scaleform::GFx::AS3::SlotInfo *v22; // rax
  unsigned __int64 v23; // r9
  unsigned int v24; // ecx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // r8
  Scaleform::GFx::AS3::Value::V1U VObj; // rcx
  unsigned int v27; // ebx
  Scaleform::GFx::AS3::ClassTraits::Traits *ClassTraits; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v29; // rdi
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // rcx
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *obj; // rbx
  Scaleform::GFx::AS3::SlotInfo *FixedSlot; // rax
  unsigned __int64 v33; // rdx
  unsigned int Flags; // ebx
  unsigned __int64 v35[2]; // [rsp+30h] [rbp-40h] BYREF
  Scaleform::GFx::AS3::PropRef v36; // [rsp+40h] [rbp-30h] BYREF
  unsigned __int64 index; // [rsp+C0h] [rbp+50h] BYREF
  Scaleform::GFx::AS3::TR::State::ScopeType *v39; // [rsp+C8h] [rbp+58h]

  v39 = stype;
  v35[1] = -2i64;
  v7 = this;
  if ( (mn->Kind & 3) == 1 || (mn->Kind & 4) != 0 )
    return;
  VMRef = this->pTracer->CF->pFile->VMRef;
  index = 0i64;
  Size = this->ScopeStack.Data.Size;
  if ( !Size )
  {
LABEL_17:
    pSavedScope = v7->pTracer->CF->pSavedScope;
    v18 = pSavedScope->Data.Size;
    if ( !v18 )
    {
LABEL_40:
      if ( (mn->Name.Flags & 0x1F) - 8 <= 1 )
        return;
      ClassTraits = Scaleform::GFx::AS3::FindClassTraits(VMRef, mn, v7->pTracer->CF->pFile->AppDomain.pObject);
      v29 = ClassTraits;
      if ( ClassTraits
        && (pObject = ClassTraits->ITraits.pObject) != 0i64
        && ((pObject->Flags & 0x10) == 0
          ? (obj = (Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *)VMRef->GlobalObject.pObject)
          : (obj = Scaleform::GFx::AS3::InstanceTraits::UserDefined::GetGlobalObjectScript((Scaleform::GFx::AS3::InstanceTraits::UserDefined *)pObject)),
            v35[0] = 0i64,
            (FixedSlot = Scaleform::GFx::AS3::FindFixedSlot(VMRef, obj->pTraits.pObject, mn, v35, obj)) != 0i64) )
      {
        v36.pSI = FixedSlot;
        v33 = v35[0];
        v36.SlotIndex = v35[0];
        v36.This.Flags = 12;
        v36.This.Bonus.pWeakProxy = 0i64;
        v36.This.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)obj;
        obj->RefCount = (obj->RefCount + 1) & 0x8FBFFFFF;
        result->pSI = FixedSlot;
        result->SlotIndex = v33;
        Scaleform::GFx::AS3::Value::Assign(&result->This, &v36.This);
        Flags = v36.This.Flags;
        if ( (v36.This.Flags & 0x1F) > 9 )
        {
          if ( (v36.This.Flags & 0x200) != 0 )
          {
            v16 = v36.This.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v16 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            memset(&v36.This.Bonus, 0, 24);
            v36.This.Flags = Flags & 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v36.This);
          }
        }
      }
      else
      {
        Scaleform::GFx::AS3::FindGOProperty(result, VMRef, &VMRef->GlobalObjects, mn, v29);
        if ( (result->This.Flags & 0x1F) == 0
          || ((__int64)result->pSI & 1) != 0 && ((unsigned __int64)result->pSI & 0xFFFFFFFFFFFFFFFEui64) == 0
          || ((__int64)result->pSI & 2) != 0 && ((unsigned __int64)result->pSI & 0xFFFFFFFFFFFFFFFDui64) == 0 )
        {
          return;
        }
      }
      *v39 = stGlobalObject;
      return;
    }
    v19 = 32 * v18 - 32;
    while ( 1 )
    {
      *scope_index = --v18;
      v20 = (Scaleform::GFx::AS3::Value *)((char *)pSavedScope->Data.Data + v19);
      ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(VMRef, v20);
      if ( (v20->Flags & 0x100) != 0 )
        return;
      v22 = Scaleform::GFx::AS3::FindFixedSlot(VMRef, ValueTraits, mn, &index, 0i64);
      if ( v22 )
        break;
      v19 -= 32i64;
      if ( !v18 )
      {
        v7 = this;
        goto LABEL_40;
      }
    }
    *v39 = stStoredScope;
    v36.pSI = v22;
    v23 = index;
    v36.SlotIndex = index;
    v24 = v20->Flags;
    v36.This.Flags = v24;
    pWeakProxy = v20->Bonus.pWeakProxy;
    v36.This.Bonus.pWeakProxy = pWeakProxy;
    v36.This.value = v20->value;
    if ( (v24 & 0x1F) > 9 )
    {
      if ( (v24 & 0x200) != 0 )
      {
        ++pWeakProxy->RefCount;
        goto LABEL_35;
      }
      if ( (v24 & 0x1F) == 10 )
      {
        ++v20->value.VS._1.VStr->RefCount;
      }
      else
      {
        if ( (v24 & 0x1F) <= 0xA )
          goto LABEL_35;
        if ( (v24 & 0x1F) <= 0xF )
        {
          VObj = v20->value.VS._1;
        }
        else
        {
          if ( (v24 & 0x1F) > 0x11 )
            goto LABEL_35;
          VObj = (Scaleform::GFx::AS3::Value::V1U)v20->value.VS._2.VObj;
        }
        if ( VObj.VStr )
          VObj.VStr->Size = (VObj.VStr->Size + 1) & 0x8FBFFFFF;
      }
    }
LABEL_35:
    result->pSI = v22;
    result->SlotIndex = v23;
    Scaleform::GFx::AS3::Value::Assign(&result->This, &v36.This);
    v27 = v36.This.Flags;
    if ( (v36.This.Flags & 0x1F) <= 9 )
      return;
    if ( (v36.This.Flags & 0x200) != 0 )
    {
      v16 = v36.This.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v16 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v36.This.Bonus, 0, 24);
      v36.This.Flags = v27 & 0xFFFFFDE0;
      return;
    }
    goto LABEL_16;
  }
  v10 = 32 * Size - 32;
  while ( 1 )
  {
    *scope_index = --Size;
    v11 = (Scaleform::GFx::AS3::Value *)((char *)v7->ScopeStack.Data.Data + v10);
    v12 = Scaleform::GFx::AS3::TR::State::GetValueTraits(v7, v11);
    v13 = v12;
    if ( (v11->Flags & 0x100) != 0 )
      break;
    if ( v12 )
    {
      if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::Traits *))v12->vfptr[1].ForEachChild_GC)(v12) )
      {
        v14 = Scaleform::GFx::AS3::FindFixedSlot(VMRef, v13, mn, &index, 0i64);
        if ( v14 )
        {
          *v39 = stScopeStack;
          Scaleform::GFx::AS3::PropRef::PropRef(&v36, v11, v14, index);
          Scaleform::GFx::AS3::PropRef::operator=(result, v15);
          if ( (v36.This.Flags & 0x1F) > 9 )
          {
            if ( (v36.This.Flags & 0x200) != 0 )
            {
              v16 = v36.This.Bonus.pWeakProxy->RefCount-- == 1;
              if ( v16 )
                ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
              memset(&v36.This.Bonus, 0, 24);
              v36.This.Flags &= 0xFFFFFDE0;
            }
            else
            {
LABEL_16:
              Scaleform::GFx::AS3::Value::ReleaseInternal(&v36.This);
            }
          }
          return;
        }
      }
    }
    v10 -= 32i64;
    v7 = this;
    if ( !Size )
      goto LABEL_17;
  }
}

// File Line: 835
// RVA: 0x83F800
void __fastcall Scaleform::GFx::AS3::TR::State::exec_findpropstrict(
        Scaleform::GFx::AS3::TR::State *this,
        unsigned int mn_index)
{
  __int64 v3; // rbx
  Scaleform::GFx::AS3::VMAbcFile *pFile; // rdx
  int v5; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // rcx
  Scaleform::GFx::AS3::PropRef result; // [rsp+30h] [rbp-69h] BYREF
  Scaleform::GFx::AS3::Value source; // [rsp+60h] [rbp-39h] BYREF
  Scaleform::GFx::AS3::TR::StackReader v10; // [rsp+80h] [rbp-19h] BYREF
  Scaleform::GFx::AS3::VMAbcFile *v11; // [rsp+98h] [rbp-1h]
  Scaleform::GFx::AS3::Multiname obj; // [rsp+A0h] [rbp+7h] BYREF
  __int64 v13; // [rsp+D0h] [rbp+37h]
  unsigned __int64 scope_index; // [rsp+100h] [rbp+67h] BYREF
  Scaleform::GFx::AS3::TR::State::ScopeType stype; // [rsp+108h] [rbp+6Fh] BYREF

  v13 = -2i64;
  v3 = mn_index;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_findpropstrict, mn_index);
  pFile = this->pTracer->CF->pFile;
  v10.VMRef = pFile->VMRef;
  v10.StateRef = this;
  v10.Num = 0;
  v11 = pFile;
  Scaleform::GFx::AS3::Multiname::Multiname(&obj, pFile, &pFile->File.pObject->Const_Pool.const_multiname.Data.Data[v3]);
  v5 = Scaleform::GFx::AS3::TR::StackReader::Read(&v10, &obj);
  v10.Num += v5;
  memset(&result, 0, 20);
  result.This.Bonus.pWeakProxy = 0i64;
  Scaleform::GFx::AS3::TR::State::FindProp(this, &result, &obj, &stype, &scope_index);
  if ( (result.This.Flags & 0x1F) != 0
    && (((__int64)result.pSI & 1) == 0 || ((unsigned __int64)result.pSI & 0xFFFFFFFFFFFFFFFEui64) != 0)
    && (((__int64)result.pSI & 2) == 0 || ((unsigned __int64)result.pSI & 0xFFFFFFFFFFFFFFFDui64) != 0) )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &this->OpStack.Data,
      (__int64 *)this->OpStack.Data.pHeap,
      this->OpStack.Data.Size + 1);
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
      &this->OpStack.Data.Data[this->OpStack.Data.Size - 1].Flags,
      &result.This);
  }
  else
  {
    pObject = this->pTracer->CF->pFile->VMRef->TraitsObject.pObject->ITraits.pObject;
    source.Bonus.pWeakProxy = 0i64;
    source.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)pObject;
    source.Flags = 8;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &this->OpStack.Data,
      (__int64 *)this->OpStack.Data.pHeap,
      this->OpStack.Data.Size + 1);
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
      &this->OpStack.Data.Data[this->OpStack.Data.Size - 1].Flags,
      &source);
  }
  if ( (result.This.Flags & 0x1F) > 9 )
  {
    if ( (result.This.Flags & 0x200) != 0 )
    {
      if ( result.This.Bonus.pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&result.This.Bonus, 0, 24);
      result.This.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&result.This);
    }
  }
  Scaleform::GFx::AS3::Multiname::~Multiname(&obj);
}

// File Line: 870
// RVA: 0x83F3E0
void __fastcall Scaleform::GFx::AS3::TR::State::exec_findproperty(
        Scaleform::GFx::AS3::TR::State *this,
        unsigned int mn_index)
{
  __int64 v3; // rbx
  Scaleform::GFx::AS3::VMAbcFile *pFile; // rdx
  int v5; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // rcx
  Scaleform::GFx::AS3::PropRef result; // [rsp+30h] [rbp-69h] BYREF
  Scaleform::GFx::AS3::Value source; // [rsp+60h] [rbp-39h] BYREF
  Scaleform::GFx::AS3::TR::StackReader v10; // [rsp+80h] [rbp-19h] BYREF
  Scaleform::GFx::AS3::VMAbcFile *v11; // [rsp+98h] [rbp-1h]
  Scaleform::GFx::AS3::Multiname obj; // [rsp+A0h] [rbp+7h] BYREF
  __int64 v13; // [rsp+D0h] [rbp+37h]
  unsigned __int64 scope_index; // [rsp+100h] [rbp+67h] BYREF
  Scaleform::GFx::AS3::TR::State::ScopeType stype; // [rsp+108h] [rbp+6Fh] BYREF

  v13 = -2i64;
  v3 = mn_index;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_findproperty, mn_index);
  pFile = this->pTracer->CF->pFile;
  v10.VMRef = pFile->VMRef;
  v10.StateRef = this;
  v10.Num = 0;
  v11 = pFile;
  Scaleform::GFx::AS3::Multiname::Multiname(&obj, pFile, &pFile->File.pObject->Const_Pool.const_multiname.Data.Data[v3]);
  v5 = Scaleform::GFx::AS3::TR::StackReader::Read(&v10, &obj);
  v10.Num += v5;
  memset(&result, 0, 20);
  result.This.Bonus.pWeakProxy = 0i64;
  Scaleform::GFx::AS3::TR::State::FindProp(this, &result, &obj, &stype, &scope_index);
  if ( (result.This.Flags & 0x1F) != 0
    && (((__int64)result.pSI & 1) == 0 || ((unsigned __int64)result.pSI & 0xFFFFFFFFFFFFFFFEui64) != 0)
    && (((__int64)result.pSI & 2) == 0 || ((unsigned __int64)result.pSI & 0xFFFFFFFFFFFFFFFDui64) != 0) )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &this->OpStack.Data,
      (__int64 *)this->OpStack.Data.pHeap,
      this->OpStack.Data.Size + 1);
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
      &this->OpStack.Data.Data[this->OpStack.Data.Size - 1].Flags,
      &result.This);
  }
  else
  {
    pObject = this->pTracer->CF->pFile->VMRef->TraitsObject.pObject->ITraits.pObject;
    source.Bonus.pWeakProxy = 0i64;
    source.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)pObject;
    source.Flags = 72;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &this->OpStack.Data,
      (__int64 *)this->OpStack.Data.pHeap,
      this->OpStack.Data.Size + 1);
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
      &this->OpStack.Data.Data[this->OpStack.Data.Size - 1].Flags,
      &source);
  }
  if ( (result.This.Flags & 0x1F) > 9 )
  {
    if ( (result.This.Flags & 0x200) != 0 )
    {
      if ( result.This.Bonus.pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&result.This.Bonus, 0, 24);
      result.This.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&result.This);
    }
  }
  Scaleform::GFx::AS3::Multiname::~Multiname(&obj);
}

// File Line: 905
// RVA: 0x840470
void __fastcall Scaleform::GFx::AS3::TR::State::exec_getlex(
        Scaleform::GFx::AS3::TR::State *this,
        unsigned int mn_index)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // rdx
  Scaleform::GFx::AS3::Value source; // [rsp+28h] [rbp-30h] BYREF

  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_getlex, mn_index);
  pObject = this->pTracer->CF->pFile->VMRef->TraitsObject.pObject->ITraits.pObject;
  source.Bonus.pWeakProxy = 0i64;
  source.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)pObject;
  source.Flags = 8;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->OpStack.Data,
    (__int64 *)this->OpStack.Data.pHeap,
    this->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &this->OpStack.Data.Data[this->OpStack.Data.Size - 1].Flags,
    &source);
}

// File Line: 928
// RVA: 0x840930
void __fastcall Scaleform::GFx::AS3::TR::State::exec_getlocal(
        Scaleform::GFx::AS3::TR::State *this,
        unsigned int reg_ind)
{
  __int64 v3; // rdi
  Scaleform::GFx::AS3::Value *v4; // rdi

  v3 = reg_ind;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_getlocal, reg_ind);
  v4 = &this->Registers.Data.Data[v3];
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->OpStack.Data,
    (__int64 *)this->OpStack.Data.pHeap,
    this->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &this->OpStack.Data.Data[this->OpStack.Data.Size - 1].Flags,
    v4);
}

// File Line: 940
// RVA: 0x842D70
void __fastcall Scaleform::GFx::AS3::TR::State::exec_newactivation(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *ActivationInstanceTraits; // rax
  Scaleform::GFx::AS3::Value source; // [rsp+28h] [rbp-30h] BYREF

  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_newactivation);
  ActivationInstanceTraits = Scaleform::GFx::AS3::VMFile::GetActivationInstanceTraits(
                               this->pTracer->CF->pFile,
                               this->pTracer->CF->MBIIndex);
  source.Bonus.pWeakProxy = 0i64;
  source.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)ActivationInstanceTraits;
  source.Flags = 8;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->OpStack.Data,
    (__int64 *)this->OpStack.Data.pHeap,
    this->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &this->OpStack.Data.Data[this->OpStack.Data.Size - 1].Flags,
    &source);
}

// File Line: 953
// RVA: 0x8455B0
void __fastcall Scaleform::GFx::AS3::TR::State::exec_pushbyte(Scaleform::GFx::AS3::TR::State *this, int v)
{
  char v2; // bl
  Scaleform::GFx::AS3::Value source; // [rsp+28h] [rbp-30h] BYREF

  v2 = v;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_pushbyte, v);
  source.Flags = 2;
  source.Bonus.pWeakProxy = 0i64;
  source.value.VS._1.VInt = v2;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->OpStack.Data,
    (__int64 *)this->OpStack.Data.pHeap,
    this->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &this->OpStack.Data.Data[this->OpStack.Data.Size - 1].Flags,
    &source);
}

// File Line: 965
// RVA: 0x845B20
void __fastcall Scaleform::GFx::AS3::TR::State::exec_pushshort(Scaleform::GFx::AS3::TR::State *this, int v)
{
  Scaleform::GFx::AS3::Value source; // [rsp+28h] [rbp-30h] BYREF

  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_pushshort, v);
  source.Flags = 2;
  source.Bonus.pWeakProxy = 0i64;
  source.value.VS._1.VInt = v;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->OpStack.Data,
    (__int64 *)this->OpStack.Data.pHeap,
    this->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &this->OpStack.Data.Data[this->OpStack.Data.Size - 1].Flags,
    &source);
}

// File Line: 976
// RVA: 0x845BA0
void __fastcall Scaleform::GFx::AS3::TR::State::exec_pushstring(Scaleform::GFx::AS3::TR::State *this, unsigned int v)
{
  Scaleform::GFx::AS3::Tracer *pTracer; // r10
  Scaleform::GFx::AS3::VMAbcFile *pFile; // rdi
  const char *Data; // r8
  const char *v6; // r8
  unsigned __int64 v7; // r9
  char v8; // al
  unsigned int v9; // ecx
  char v10; // dl
  char v11; // di
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::Value source; // [rsp+28h] [rbp-30h] BYREF
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+8h] BYREF
  Scaleform::GFx::ASStringNode *key; // [rsp+70h] [rbp+18h] BYREF

  pTracer = this->pTracer;
  pFile = this->pTracer->CF->pFile;
  Data = pFile->File.pObject->Const_Pool.ConstStr.Data.Data[v].Data;
  if ( Data )
  {
    v8 = *Data;
    v6 = Data + 1;
    LODWORD(v7) = v8 & 0x7F;
    v9 = 7;
    if ( v8 < 0 )
    {
      do
      {
        if ( v9 >= 0x20 )
          break;
        v10 = *v6++;
        LODWORD(v7) = ((v10 & 0x7F) << v9) | v7;
        v9 += 7;
      }
      while ( v10 < 0 );
    }
    v7 = (int)v7;
  }
  else
  {
    v6 = &customCaption;
    v7 = 0i64;
  }
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
    pTracer->CF->pFile->VMRef->StringManagerRef,
    &result,
    v6,
    v7);
  key = result.pNode;
  Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::GFx::AS3::ASStringNodePtrHashFunc,Scaleform::GFx::AS3::ASStringNodePtrHashFunc,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,340>,Scaleform::HashsetEntry<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>>::Set<Scaleform::GFx::ASStringNode *>(
    &pFile->ASStringNodeSet,
    &pFile->ASStringNodeSet,
    &key);
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_pushstring, (unsigned __int64)result.pNode);
  v11 = 10;
  source.Flags = 10;
  source.Bonus.pWeakProxy = 0i64;
  *(Scaleform::GFx::ASString *)&source.value.VNumber = (Scaleform::GFx::ASString)result.pNode;
  if ( result.pNode == &result.pNode->pManager->NullStringNode )
  {
    source.value.VS._1.VStr = 0i64;
    source.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)source.Bonus.pWeakProxy;
    v11 = 12;
    source.Flags = 12;
  }
  else
  {
    ++result.pNode->RefCount;
  }
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->OpStack.Data,
    (__int64 *)this->OpStack.Data.pHeap,
    this->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &this->OpStack.Data.Data[this->OpStack.Data.Size - 1].Flags,
    &source);
  if ( (v11 & 0x1Fu) > 9 )
    Scaleform::GFx::AS3::Value::ReleaseInternal(&source);
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 1002
// RVA: 0x845730
void __fastcall Scaleform::GFx::AS3::TR::State::exec_pushint(Scaleform::GFx::AS3::TR::State *this, int v)
{
  Scaleform::GFx::AS3::Tracer *pTracer; // rcx
  unsigned __int64 v4; // rbx
  Scaleform::GFx::AS3::Value source; // [rsp+28h] [rbp-30h] BYREF

  pTracer = this->pTracer;
  v4 = pTracer->CF->pFile->File.pObject->Const_Pool.ConstInt.Data.Data[v];
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(pTracer, op_pushint, v4);
  source.Flags = 2;
  source.Bonus.pWeakProxy = 0i64;
  source.value.VS._1.VInt = v4;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->OpStack.Data,
    (__int64 *)this->OpStack.Data.pHeap,
    this->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &this->OpStack.Data.Data[this->OpStack.Data.Size - 1].Flags,
    &source);
}

// File Line: 1019
// RVA: 0x845D60
void __fastcall Scaleform::GFx::AS3::TR::State::exec_pushuint(Scaleform::GFx::AS3::TR::State *this, int v)
{
  Scaleform::GFx::AS3::Tracer *pTracer; // rcx
  unsigned int v4; // ebx
  Scaleform::GFx::AS3::Value source; // [rsp+28h] [rbp-30h] BYREF

  pTracer = this->pTracer;
  v4 = pTracer->CF->pFile->File.pObject->Const_Pool.ConstUInt.Data.Data[v];
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(pTracer, op_pushuint, v4);
  source.Flags = 3;
  source.Bonus.pWeakProxy = 0i64;
  source.value.VS._1.VInt = v4;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->OpStack.Data,
    (__int64 *)this->OpStack.Data.pHeap,
    this->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &this->OpStack.Data.Data[this->OpStack.Data.Size - 1].Flags,
    &source);
}

// File Line: 1036
// RVA: 0x845630
void __fastcall Scaleform::GFx::AS3::TR::State::exec_pushdouble(Scaleform::GFx::AS3::TR::State *this, int v)
{
  const char *Doubles; // r8
  long double v4; // xmm6_8
  Scaleform::GFx::AS3::Value source; // [rsp+28h] [rbp-40h] BYREF
  double arg1; // [rsp+70h] [rbp+8h]

  if ( v )
  {
    Doubles = this->pTracer->CF->pFile->File.pObject->Const_Pool.Doubles;
    LODWORD(arg1) = (unsigned __int8)Doubles[8 * v - 8] | (((unsigned __int8)Doubles[8 * v - 7] | (*(unsigned __int16 *)&Doubles[8 * v - 6] << 8)) << 8);
    HIDWORD(arg1) = (unsigned __int8)Doubles[8 * v - 4] | (((unsigned __int8)Doubles[8 * v - 3] | (*(unsigned __int16 *)&Doubles[8 * v - 2] << 8)) << 8);
    v4 = arg1;
  }
  else
  {
    v4 = 0.0;
  }
  Scaleform::GFx::AS3::Tracer::PushNewOpCodeNumber(this->pTracer, op_pushdouble, v4);
  source.Flags = 4;
  source.Bonus.pWeakProxy = 0i64;
  source.value.VNumber = v4;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->OpStack.Data,
    (__int64 *)this->OpStack.Data.pHeap,
    this->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &this->OpStack.Data.Data[this->OpStack.Data.Size - 1].Flags,
    &source);
}

// File Line: 1053
// RVA: 0x841610
void __fastcall Scaleform::GFx::AS3::TR::State::exec_hasnext2(
        Scaleform::GFx::AS3::TR::State *this,
        unsigned int object_reg,
        unsigned int index_reg)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // rdx
  Scaleform::GFx::AS3::Value source; // [rsp+28h] [rbp-30h] BYREF

  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_hasnext2, object_reg, index_reg);
  pObject = this->pTracer->CF->pFile->VMRef->TraitsBoolean.pObject->ITraits.pObject;
  source.Bonus.pWeakProxy = 0i64;
  source.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)pObject;
  source.Flags = 8;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->OpStack.Data,
    (__int64 *)this->OpStack.Data.pHeap,
    this->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &this->OpStack.Data.Data[this->OpStack.Data.Size - 1].Flags,
    &source);
}

// File Line: 1078
// RVA: 0x843F10
void __fastcall Scaleform::GFx::AS3::TR::State::exec_nextname(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::Tracer *pTracer; // rsi
  Scaleform::GFx::AS3::Traits *ITr; // rbx
  Scaleform::GFx::AS3::VM *VMRef; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v5; // rcx
  Scaleform::GFx::AS3::Tracer *v6; // rax
  Scaleform::GFx::AS3::VM *v7; // rcx
  Scaleform::GFx::AS3::Value::V1U pObject; // rcx
  Scaleform::GFx::AS3::Value::V1U v9; // rcx
  Scaleform::GFx::AS3::Value result; // [rsp+28h] [rbp-48h] BYREF
  Scaleform::GFx::AS3::Value source; // [rsp+48h] [rbp-28h] BYREF

  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->OpStack.Data,
    this->OpStack.Data.Size - 1);
  Scaleform::GFx::AS3::TR::State::PopOpValue(this, &result);
  pTracer = this->pTracer;
  if ( (result.Flags & 0x1F) != 0 )
  {
    if ( (result.Flags & 0x1F) - 8 < 2 )
      ITr = result.value.VS._1.ITr;
    else
      ITr = Scaleform::GFx::AS3::VM::GetValueTraits(pTracer->CF->pFile->VMRef, &result);
  }
  else
  {
    ITr = pTracer->CF->pFile->VMRef->TraitsVoid.pObject;
  }
  if ( ITr )
  {
    VMRef = pTracer->CF->pFile->VMRef;
    if ( ITr == VMRef->TraitsClassClass.pObject )
      ITr = VMRef->TraitsObject.pObject;
  }
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(pTracer, op_nextname);
  if ( ITr->TraitsType != Traits_Dictionary || (ITr->Flags & 0x20) != 0 )
  {
    v6 = this->pTracer;
    source.Flags = 8;
    v7 = v6->CF->pFile->VMRef;
    if ( (ITr->Flags & 1) != 0 )
    {
      pObject = (Scaleform::GFx::AS3::Value::V1U)v7->TraitsUint.pObject->ITraits.pObject;
      source.Bonus.pWeakProxy = 0i64;
      source.value.VS._1 = pObject;
      source.Flags = 8;
    }
    else
    {
      v9 = (Scaleform::GFx::AS3::Value::V1U)v7->TraitsString.pObject->ITraits.pObject;
      source.Bonus.pWeakProxy = 0i64;
      source.value.VS._1 = v9;
      source.Flags = 72;
    }
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &this->OpStack.Data,
      (__int64 *)this->OpStack.Data.pHeap,
      this->OpStack.Data.Size + 1);
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
      &this->OpStack.Data.Data[this->OpStack.Data.Size - 1].Flags,
      &source);
  }
  else
  {
    v5 = this->pTracer->CF->pFile->VMRef->TraitsObject.pObject->ITraits.pObject;
    source.Bonus.pWeakProxy = 0i64;
    source.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)v5;
    source.Flags = 72;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &this->OpStack.Data,
      (__int64 *)this->OpStack.Data.pHeap,
      this->OpStack.Data.Size + 1);
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
      &this->OpStack.Data.Data[this->OpStack.Data.Size - 1].Flags,
      &source);
  }
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
}

// File Line: 1120
// RVA: 0x841D00
void __fastcall Scaleform::GFx::AS3::TR::State::exec_hasnext(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_hasnext);
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->OpStack.Data,
    this->OpStack.Data.Size - 1);
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->OpStack.Data,
    this->OpStack.Data.Size - 1);
  Scaleform::GFx::AS3::TR::State::PushOp(
    this,
    this->pTracer->CF->pFile->VMRef->TraitsInt.pObject->ITraits.pObject,
    NotNull);
}

// File Line: 1134
// RVA: 0x845E00
void __fastcall Scaleform::GFx::AS3::TR::State::exec_pushundefined(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::Value *v2; // rdx
  Scaleform::GFx::AS3::Value::V1U VObj; // rax

  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_pushundefined);
  if ( (_S11_12 & 1) == 0 )
  {
    _S11_12 |= 1u;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0i64;
    atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->OpStack.Data,
    (__int64 *)this->OpStack.Data.pHeap,
    this->OpStack.Data.Size + 1);
  v2 = &this->OpStack.Data.Data[this->OpStack.Data.Size - 1];
  if ( v2 )
  {
    v2->Flags = v.Flags;
    v2->Bonus.pWeakProxy = v.Bonus.pWeakProxy;
    v2->value = v.value;
    if ( (v.Flags & 0x1F) > 9 )
    {
      if ( (v.Flags & 0x200) != 0 )
      {
        ++v.Bonus.pWeakProxy->RefCount;
        return;
      }
      if ( (v.Flags & 0x1F) == 10 )
      {
        ++v.value.VS._1.VStr->RefCount;
      }
      else
      {
        if ( (v.Flags & 0x1F) <= 0xA )
          return;
        if ( (v.Flags & 0x1F) <= 0xF )
        {
          VObj = v.value.VS._1;
        }
        else
        {
          if ( (v.Flags & 0x1F) > 0x11 )
            return;
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
}

// File Line: 1146
// RVA: 0x844270
void __fastcall Scaleform::GFx::AS3::TR::State::exec_nextvalue(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // rcx
  Scaleform::GFx::AS3::Value source; // [rsp+28h] [rbp-30h] BYREF

  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_nextvalue);
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->OpStack.Data,
    this->OpStack.Data.Size - 1);
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->OpStack.Data,
    this->OpStack.Data.Size - 1);
  pObject = this->pTracer->CF->pFile->VMRef->TraitsObject.pObject->ITraits.pObject;
  source.Bonus.pWeakProxy = 0i64;
  source.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)pObject;
  source.Flags = 8;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->OpStack.Data,
    (__int64 *)this->OpStack.Data.pHeap,
    this->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &this->OpStack.Data.Data[this->OpStack.Data.Size - 1].Flags,
    &source);
}

// File Line: 1193
// RVA: 0x83D3F0
void __fastcall Scaleform::GFx::AS3::TR::State::exec_coerce_s(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_coerce_s);
  if ( (this->OpStack.Data.Data[this->OpStack.Data.Size - 1].Flags & 0x1F) != 10 )
    Scaleform::GFx::AS3::TR::State::ConvertOpTo(
      this,
      this->pTracer->CF->pFile->VMRef->TraitsString.pObject->ITraits.pObject,
      NullOrNot);
}

// File Line: 1223
// RVA: 0x844450
void __fastcall Scaleform::GFx::AS3::TR::State::exec_not(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::TR::State::RefineOpCodeStack1(
    this,
    op_not,
    this->pTracer->CF->pFile->VMRef->TraitsBoolean.pObject->ITraits.pObject,
    op_not_tb);
}

// File Line: 1228
// RVA: 0x842D40
void __fastcall Scaleform::GFx::AS3::TR::State::exec_negate(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::TR::State::RefineOpCodeStack1(
    this,
    op_negate,
    this->pTracer->CF->pFile->VMRef->TraitsNumber.pObject->ITraits.pObject,
    op_negate_td);
}

// File Line: 1249
// RVA: 0x838D00
void __fastcall Scaleform::GFx::AS3::TR::State::exec_add_d(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::TR::State::RefineOpCodeStack2(
    this,
    op_add_d,
    this->pTracer->CF->pFile->VMRef->TraitsNumber.pObject->ITraits.pObject,
    op_add_td);
}

// File Line: 1259
// RVA: 0x847160
void __fastcall Scaleform::GFx::AS3::TR::State::exec_subtract(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::TR::State::RefineOpCodeStack2(
    this,
    op_subtract,
    this->pTracer->CF->pFile->VMRef->TraitsNumber.pObject->ITraits.pObject,
    op_subtract_td);
}

// File Line: 1269
// RVA: 0x842D10
void __fastcall Scaleform::GFx::AS3::TR::State::exec_multiply(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::TR::State::RefineOpCodeStack2(
    this,
    op_multiply,
    this->pTracer->CF->pFile->VMRef->TraitsNumber.pObject->ITraits.pObject,
    op_multiply_td);
}

// File Line: 1279
// RVA: 0x83EB40
void __fastcall Scaleform::GFx::AS3::TR::State::exec_divide(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::TR::State::RefineOpCodeStack2(
    this,
    op_divide,
    this->pTracer->CF->pFile->VMRef->TraitsNumber.pObject->ITraits.pObject,
    op_divide_td);
}

// File Line: 1316
// RVA: 0x838A10
void __fastcall Scaleform::GFx::AS3::TR::State::exec_1OpString(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::TR::State::ConvertOpTo(
    this,
    this->pTracer->CF->pFile->VMRef->TraitsString.pObject->ITraits.pObject,
    NullOrNot);
}

// File Line: 1332
// RVA: 0x838AF0
void __fastcall Scaleform::GFx::AS3::TR::State::exec_2OpNumber(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::Value result; // [rsp+28h] [rbp-30h] BYREF

  Scaleform::GFx::AS3::TR::State::PopOpValue(this, &result);
  Scaleform::GFx::AS3::TR::State::ConvertOpTo(
    this,
    this->pTracer->CF->pFile->VMRef->TraitsNumber.pObject->ITraits.pObject,
    NotNull);
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
}

// File Line: 1350
// RVA: 0x838BA0
void __fastcall Scaleform::GFx::AS3::TR::State::exec_2OpSInt(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::Value result; // [rsp+28h] [rbp-30h] BYREF

  Scaleform::GFx::AS3::TR::State::PopOpValue(this, &result);
  Scaleform::GFx::AS3::TR::State::ConvertOpTo(
    this,
    this->pTracer->CF->pFile->VMRef->TraitsInt.pObject->ITraits.pObject,
    NotNull);
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
}

// File Line: 1368
// RVA: 0x838C50
void __fastcall Scaleform::GFx::AS3::TR::State::exec_2OpUInt(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::Value result; // [rsp+28h] [rbp-30h] BYREF

  Scaleform::GFx::AS3::TR::State::PopOpValue(this, &result);
  Scaleform::GFx::AS3::TR::State::ConvertOpTo(
    this,
    this->pTracer->CF->pFile->VMRef->TraitsUint.pObject->ITraits.pObject,
    NotNull);
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
}

// File Line: 1386
// RVA: 0x838A40
void __fastcall Scaleform::GFx::AS3::TR::State::exec_2OpBoolean(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::Value result; // [rsp+28h] [rbp-30h] BYREF

  Scaleform::GFx::AS3::TR::State::PopOpValue(this, &result);
  Scaleform::GFx::AS3::TR::State::ConvertOpTo(
    this,
    this->pTracer->CF->pFile->VMRef->TraitsBoolean.pObject->ITraits.pObject,
    NotNull);
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
}

// File Line: 1404
// RVA: 0x842AE0
void __fastcall Scaleform::GFx::AS3::TR::State::exec_istype(
        Scaleform::GFx::AS3::TR::State *this,
        unsigned int mn_index)
{
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_istype, mn_index);
  Scaleform::GFx::AS3::TR::State::ConvertOpTo(
    this,
    this->pTracer->CF->pFile->VMRef->TraitsBoolean.pObject->ITraits.pObject,
    NotNull);
}

// File Line: 1413
// RVA: 0x845880
void __fastcall Scaleform::GFx::AS3::TR::State::exec_pushscope(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::Value *v2; // rdi

  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_pushscope);
  v2 = &this->OpStack.Data.Data[this->OpStack.Data.Size];
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->ScopeStack.Data,
    (__int64 *)this->ScopeStack.Data.pHeap,
    this->ScopeStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &this->ScopeStack.Data.Data[this->ScopeStack.Data.Size - 1].Flags,
    v2 - 1);
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->OpStack.Data,
    this->OpStack.Data.Size - 1);
}

// File Line: 1427
// RVA: 0x840D10
void __fastcall Scaleform::GFx::AS3::TR::State::exec_getscopeobject(
        Scaleform::GFx::AS3::TR::State *this,
        unsigned int scope_index)
{
  __int64 v3; // rdi
  Scaleform::GFx::AS3::Value *v4; // rdi

  v3 = scope_index;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_getscopeobject, scope_index);
  v4 = &this->ScopeStack.Data.Data[v3];
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->OpStack.Data,
    (__int64 *)this->OpStack.Data.pHeap,
    this->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &this->OpStack.Data.Data[this->OpStack.Data.Size - 1].Flags,
    v4);
  this->OpStack.Data.Data[this->OpStack.Data.Size - 1].Flags &= ~0x100u;
}

// File Line: 1440
// RVA: 0x83E7C0
void __fastcall Scaleform::GFx::AS3::TR::State::exec_deleteproperty(
        Scaleform::GFx::AS3::TR::State *this,
        unsigned int mn_index)
{
  __int64 v3; // rbx
  Scaleform::GFx::AS3::VMAbcFile *pFile; // rdx
  int v5; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // rcx
  Scaleform::GFx::AS3::Value source; // [rsp+18h] [rbp-49h] BYREF
  Scaleform::GFx::AS3::TR::StackReader v9; // [rsp+38h] [rbp-29h] BYREF
  Scaleform::GFx::AS3::VMAbcFile *v10; // [rsp+50h] [rbp-11h]
  Scaleform::GFx::AS3::Multiname obj; // [rsp+58h] [rbp-9h] BYREF
  Scaleform::GFx::AS3::Value result; // [rsp+88h] [rbp+27h] BYREF
  __int64 v13; // [rsp+A8h] [rbp+47h]

  v13 = -2i64;
  v3 = mn_index;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_deleteproperty, mn_index);
  pFile = this->pTracer->CF->pFile;
  v9.VMRef = pFile->VMRef;
  v9.StateRef = this;
  v9.Num = 0;
  v10 = pFile;
  Scaleform::GFx::AS3::Multiname::Multiname(&obj, pFile, &pFile->File.pObject->Const_Pool.const_multiname.Data.Data[v3]);
  v5 = Scaleform::GFx::AS3::TR::StackReader::Read(&v9, &obj);
  v9.Num += v5;
  Scaleform::GFx::AS3::TR::State::PopOpValue(this, &result);
  ++v9.Num;
  pObject = this->pTracer->CF->pFile->VMRef->TraitsBoolean.pObject->ITraits.pObject;
  source.Bonus.pWeakProxy = 0i64;
  source.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)pObject;
  source.Flags = 8;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->OpStack.Data,
    (__int64 *)this->OpStack.Data.pHeap,
    this->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &this->OpStack.Data.Data[this->OpStack.Data.Size - 1].Flags,
    &source);
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
  Scaleform::GFx::AS3::Multiname::~Multiname(&obj);
}

// File Line: 1463
// RVA: 0x840E50
void __fastcall Scaleform::GFx::AS3::TR::State::exec_getslot(
        Scaleform::GFx::AS3::TR::State *this,
        unsigned int slot_index,
        bool simulate)
{
  unsigned __int64 v3; // r15
  Scaleform::GFx::AS3::Tracer *pTracer; // rbx
  Scaleform::GFx::AS3::Traits *ITr; // rdi
  Scaleform::GFx::AS3::VM *v7; // rax
  unsigned __int64 FirstOwnSlotNum; // r14
  unsigned __int64 v9; // r12
  __int64 Index; // rbx
  __int64 v11; // rdx
  Scaleform::GFx::AS3::SlotInfo *SlotInfo; // r15
  __int64 v13; // rdx
  Scaleform::GFx::AS3::SlotInfo *p_Value; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *DataType; // rax
  Scaleform::GFx::AS3::Value::V1U v16; // rdi
  Scaleform::GFx::AS3::VM::Error *v17; // rax
  Scaleform::GFx::ASStringNode *pWeakProxy; // rcx
  bool v19; // zf
  Scaleform::GFx::AS3::InstanceTraits::Traits *v20; // r14
  Scaleform::GFx::AS3::Abc::TraitInfo *TI; // rax
  int v22; // eax
  unsigned int v23; // ebx
  int CanBeNull; // eax
  Scaleform::GFx::AS3::Value::V1U pObject; // rax
  Scaleform::GFx::AS3::Value v26; // [rsp+28h] [rbp-58h] BYREF
  Scaleform::GFx::AS3::VM *VMRef; // [rsp+48h] [rbp-38h]
  Scaleform::GFx::AS3::TR::State *v28; // [rsp+50h] [rbp-30h]
  int v29; // [rsp+58h] [rbp-28h]
  Scaleform::GFx::AS3::Value result; // [rsp+60h] [rbp-20h] BYREF

  v3 = slot_index;
  if ( !simulate )
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_getslot, slot_index);
  VMRef = this->pTracer->CF->pFile->VMRef;
  v28 = this;
  Scaleform::GFx::AS3::TR::State::PopOpValue(this, &result);
  v29 = 1;
  pTracer = this->pTracer;
  if ( (result.Flags & 0x1F) != 0 )
  {
    if ( (result.Flags & 0x1F) - 8 < 2 )
      ITr = result.value.VS._1.ITr;
    else
      ITr = Scaleform::GFx::AS3::VM::GetValueTraits(pTracer->CF->pFile->VMRef, &result);
  }
  else
  {
    ITr = pTracer->CF->pFile->VMRef->TraitsVoid.pObject;
  }
  if ( !ITr )
    goto LABEL_40;
  v7 = pTracer->CF->pFile->VMRef;
  if ( ITr == v7->TraitsClassClass.pObject )
    ITr = v7->TraitsObject.pObject;
  if ( !ITr )
  {
LABEL_40:
    v26.Flags = 0;
    v26.Bonus.pWeakProxy = 0i64;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &this->OpStack.Data,
      (__int64 *)this->OpStack.Data.pHeap,
      this->OpStack.Data.Size + 1);
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
      &this->OpStack.Data.Data[this->OpStack.Data.Size - 1].Flags,
      &v26);
    goto LABEL_41;
  }
  FirstOwnSlotNum = ITr->FirstOwnSlotNum;
  v9 = v3;
  if ( v3 > FirstOwnSlotNum + ITr->VArray.Data.Size )
  {
    pObject = (Scaleform::GFx::AS3::Value::V1U)pTracer->CF->pFile->VMRef->TraitsObject.pObject->ITraits.pObject;
    v26.Bonus.pWeakProxy = 0i64;
    v26.value.VS._1 = pObject;
    v26.Flags = 72;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &this->OpStack.Data,
      (__int64 *)this->OpStack.Data.pHeap,
      this->OpStack.Data.Size + 1);
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
      &this->OpStack.Data.Data[this->OpStack.Data.Size - 1].Flags,
      &v26);
    goto LABEL_41;
  }
  Index = ITr->FirstOwnSlotInd.Index;
  v11 = (unsigned int)Index + v3 - 1;
  if ( v11 < 0 || v11 < FirstOwnSlotNum )
    SlotInfo = Scaleform::GFx::AS3::Slots::GetSlotInfo(ITr->Parent, (Scaleform::GFx::AS3::AbsoluteIndex)v11);
  else
    SlotInfo = &ITr->VArray.Data.Data[(unsigned int)v11 - FirstOwnSlotNum].Value;
  v13 = (unsigned int)Index + v9 - 1;
  if ( v13 < 0 || v13 < FirstOwnSlotNum )
    p_Value = Scaleform::GFx::AS3::Slots::GetSlotInfo(ITr->Parent, (Scaleform::GFx::AS3::AbsoluteIndex)v13);
  else
    p_Value = &ITr->VArray.Data.Data[(unsigned int)v13 - FirstOwnSlotNum].Value;
  DataType = Scaleform::GFx::AS3::SlotInfo::GetDataType(p_Value, ITr->pVM);
  v16.VStr = (Scaleform::GFx::ASStringNode *)DataType;
  if ( DataType )
  {
    v20 = DataType->ITraits.pObject;
    if ( (*(_DWORD *)SlotInfo & 0x7C00) == 1024 || (TI = SlotInfo->TI) != 0i64 && (TI->kind & 0xF) == 4 )
    {
      CanBeNull = Scaleform::GFx::AS3::TR::State::CanBeNull(this, v20);
      v26.Bonus.pWeakProxy = 0i64;
      v26.value.VS._1 = v16;
      v23 = (32 * CanBeNull) & 0xFFFFFEF6 | 9;
      v26.Flags = v23;
      Scaleform::GFx::AS3::TR::State::PushOp(this, &v26);
      if ( (v23 & 0x1F) <= 9 )
        goto LABEL_41;
      if ( (v23 & 0x200) != 0 )
      {
        LODWORD(MEMORY[0]) = MEMORY[0] - 1;
        if ( !(_DWORD)MEMORY[0] )
        {
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
          memset(&v26.Bonus, 0, 24);
          v26.Flags = v23 & 0xFFFFFDE0;
          goto LABEL_41;
        }
LABEL_32:
        memset(&v26.Bonus, 0, 24);
        v26.Flags = v23 & 0xFFFFFDE0;
        goto LABEL_41;
      }
    }
    else
    {
      v22 = Scaleform::GFx::AS3::TR::State::CanBeNull(this, v20);
      v26.Bonus.pWeakProxy = 0i64;
      v26.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)v20;
      v23 = (32 * v22) & 0xFFFFFEF7 | 8;
      v26.Flags = v23;
      Scaleform::GFx::AS3::TR::State::PushOp(this, &v26);
      if ( (v23 & 0x1F) <= 9 )
        goto LABEL_41;
      if ( (v23 & 0x200) != 0 )
      {
        LODWORD(MEMORY[0]) = MEMORY[0] - 1;
        if ( !(_DWORD)MEMORY[0] )
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
        goto LABEL_32;
      }
    }
    Scaleform::GFx::AS3::Value::ReleaseInternal(&v26);
    goto LABEL_41;
  }
  Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v26, 1014, this->pTracer->CF->pFile->VMRef);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(
    this->pTracer->CF->pFile->VMRef,
    v17,
    &Scaleform::GFx::AS3::fl::VerifyErrorTI);
  pWeakProxy = (Scaleform::GFx::ASStringNode *)v26.Bonus.pWeakProxy;
  v19 = LODWORD(v26.Bonus.pWeakProxy[1].pObject)-- == 1;
  if ( v19 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pWeakProxy);
LABEL_41:
  if ( (result.Flags & 0x1F) > 9 )
  {
    if ( (result.Flags & 0x200) != 0 )
    {
      v19 = result.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v19 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      result.Flags &= 0xFFFFFDE0;
      memset(&result.Bonus, 0, 24);
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
    }
  }
}

// File Line: 1587
// RVA: 0x8468D0
void __fastcall Scaleform::GFx::AS3::TR::State::exec_setlocal(Scaleform::GFx::AS3::TR::State *this, unsigned int rnum)
{
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_setlocal, rnum);
  Scaleform::GFx::AS3::Value::Assign(
    &this->Registers.Data.Data[rnum],
    &this->OpStack.Data.Data[this->OpStack.Data.Size - 1]);
  this->RegistersAlive.pData[(unsigned __int64)rnum >> 3] |= 1 << (rnum & 7);
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->OpStack.Data,
    this->OpStack.Data.Size - 1);
}

// File Line: 1615
// RVA: 0x8407B0
void __fastcall Scaleform::GFx::AS3::TR::State::exec_getlocal0(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::Value *Data; // rdi

  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_getlocal0);
  Data = this->Registers.Data.Data;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->OpStack.Data,
    (__int64 *)this->OpStack.Data.pHeap,
    this->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &this->OpStack.Data.Data[this->OpStack.Data.Size - 1].Flags,
    Data);
}

// File Line: 1628
// RVA: 0x840810
void __fastcall Scaleform::GFx::AS3::TR::State::exec_getlocal1(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::Value *Data; // rdi

  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_getlocal1);
  Data = this->Registers.Data.Data;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->OpStack.Data,
    (__int64 *)this->OpStack.Data.pHeap,
    this->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &this->OpStack.Data.Data[this->OpStack.Data.Size - 1].Flags,
    Data + 1);
}

// File Line: 1641
// RVA: 0x840870
void __fastcall Scaleform::GFx::AS3::TR::State::exec_getlocal2(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::Value *Data; // rdi

  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_getlocal2);
  Data = this->Registers.Data.Data;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->OpStack.Data,
    (__int64 *)this->OpStack.Data.pHeap,
    this->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &this->OpStack.Data.Data[this->OpStack.Data.Size - 1].Flags,
    Data + 2);
}

// File Line: 1654
// RVA: 0x8408D0
void __fastcall Scaleform::GFx::AS3::TR::State::exec_getlocal3(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::Value *Data; // rdi

  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_getlocal3);
  Data = this->Registers.Data.Data;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->OpStack.Data,
    (__int64 *)this->OpStack.Data.pHeap,
    this->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &this->OpStack.Data.Data[this->OpStack.Data.Size - 1].Flags,
    Data + 3);
}

// File Line: 1667
// RVA: 0x846720
void __fastcall Scaleform::GFx::AS3::TR::State::exec_setlocal0(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::Value *v2; // rbx

  v2 = &this->OpStack.Data.Data[this->OpStack.Data.Size];
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_setlocal0);
  Scaleform::GFx::AS3::Value::Assign(this->Registers.Data.Data, v2 - 1);
  *this->RegistersAlive.pData |= 1u;
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->OpStack.Data,
    this->OpStack.Data.Size - 1);
}

// File Line: 1685
// RVA: 0x846780
void __fastcall Scaleform::GFx::AS3::TR::State::exec_setlocal1(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::Value *v2; // rbx

  v2 = &this->OpStack.Data.Data[this->OpStack.Data.Size];
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_setlocal1);
  Scaleform::GFx::AS3::Value::Assign(this->Registers.Data.Data + 1, v2 - 1);
  *this->RegistersAlive.pData |= 2u;
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->OpStack.Data,
    this->OpStack.Data.Size - 1);
}

// File Line: 1703
// RVA: 0x8467F0
void __fastcall Scaleform::GFx::AS3::TR::State::exec_setlocal2(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::Value *v2; // rbx

  v2 = &this->OpStack.Data.Data[this->OpStack.Data.Size];
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_setlocal2);
  Scaleform::GFx::AS3::Value::Assign(this->Registers.Data.Data + 2, v2 - 1);
  *this->RegistersAlive.pData |= 4u;
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->OpStack.Data,
    this->OpStack.Data.Size - 1);
}

// File Line: 1721
// RVA: 0x846860
void __fastcall Scaleform::GFx::AS3::TR::State::exec_setlocal3(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::Value *v2; // rbx

  v2 = &this->OpStack.Data.Data[this->OpStack.Data.Size];
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_setlocal3);
  Scaleform::GFx::AS3::Value::Assign(this->Registers.Data.Data + 3, v2 - 1);
  *this->RegistersAlive.pData |= 8u;
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->OpStack.Data,
    this->OpStack.Data.Size - 1);
}

// File Line: 1739
// RVA: 0x7BAEA0
void __fastcall Scaleform::GFx::AS3::TR::State::ConvertOpTo(
        Scaleform::GFx::AS3::TR::State *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *tr,
        Scaleform::GFx::AS3::Value::TraceNullType isNull)
{
  Scaleform::GFx::AS3::Value *v3; // rcx
  unsigned int Flags; // ebx
  Scaleform::GFx::AS3::Value v6; // [rsp+28h] [rbp-30h] BYREF

  v3 = &this->OpStack.Data.Data[this->OpStack.Data.Size - 1];
  v6.Bonus.pWeakProxy = 0i64;
  v6.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)tr;
  v6.Flags = (32 * isNull) & 0xFFFFFEF7 | 8;
  Scaleform::GFx::AS3::Value::Assign(v3, &v6);
  Flags = v6.Flags;
  if ( (v6.Flags & 0x1F) > 9 )
  {
    if ( (v6.Flags & 0x200) != 0 )
    {
      if ( v6.Bonus.pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v6.Bonus, 0, 24);
      v6.Flags = Flags & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v6);
    }
  }
}

// File Line: 1965
// RVA: 0x7BAF60
void __fastcall Scaleform::GFx::AS3::TR::State::ConvertRegisterTo(
        Scaleform::GFx::AS3::TR::State *this,
        Scaleform::GFx::AS3::AbsoluteIndex index,
        Scaleform::GFx::AS3::InstanceTraits::Traits *tr,
        Scaleform::GFx::AS3::Value::TraceNullType isNull)
{
  unsigned int Flags; // ebx
  Scaleform::GFx::AS3::Value v6; // [rsp+28h] [rbp-30h] BYREF

  v6.Bonus.pWeakProxy = 0i64;
  v6.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)tr;
  v6.Flags = (32 * isNull) & 0xFFFFFEF7 | 8;
  Scaleform::GFx::AS3::Value::Assign(&this->Registers.Data.Data[LODWORD(index.Index)], &v6);
  Flags = v6.Flags;
  if ( (v6.Flags & 0x1F) > 9 )
  {
    if ( (v6.Flags & 0x200) != 0 )
    {
      if ( v6.Bonus.pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v6.Bonus, 0, 24);
      v6.Flags = Flags & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v6);
    }
  }
}

// File Line: 1982
// RVA: 0x8457D0
void __fastcall Scaleform::GFx::AS3::TR::State::exec_pushnamespace(
        Scaleform::GFx::AS3::TR::State *this,
        unsigned int v)
{
  Scaleform::GFx::AS3::Instances::fl::Namespace *InternedNamespace; // rax
  Scaleform::GFx::AS3::Value source; // [rsp+28h] [rbp-30h] BYREF

  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_pushnamespace, v);
  InternedNamespace = Scaleform::GFx::AS3::VMFile::GetInternedNamespace(this->pTracer->CF->pFile, v);
  source.Flags = 11;
  source.Bonus.pWeakProxy = 0i64;
  source.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)InternedNamespace;
  if ( InternedNamespace )
    InternedNamespace->RefCount = (InternedNamespace->RefCount + 1) & 0x8FBFFFFF;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->OpStack.Data,
    (__int64 *)this->OpStack.Data.pHeap,
    this->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &this->OpStack.Data.Data[this->OpStack.Data.Size - 1].Flags,
    &source);
  Scaleform::GFx::AS3::Value::ReleaseInternal(&source);
}

// File Line: 1994
// RVA: 0x846B50
void __fastcall Scaleform::GFx::AS3::TR::State::exec_setslot(
        Scaleform::GFx::AS3::TR::State *this,
        unsigned int slot_index,
        bool simulate)
{
  bool v4; // zf
  Scaleform::GFx::AS3::Value result; // [rsp+48h] [rbp+Fh] BYREF
  Scaleform::GFx::AS3::Value v6; // [rsp+68h] [rbp+2Fh] BYREF

  if ( !simulate )
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_setslot, slot_index);
  Scaleform::GFx::AS3::TR::State::PopOpValue(this, &result);
  Scaleform::GFx::AS3::TR::State::PopOpValue(this, &v6);
  if ( (v6.Flags & 0x1F) > 9 )
  {
    if ( (v6.Flags & 0x200) != 0 )
    {
      v4 = v6.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v4 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v6.Bonus, 0, 24);
      v6.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v6);
    }
  }
  if ( (result.Flags & 0x1F) > 9 )
  {
    if ( (result.Flags & 0x200) != 0 )
    {
      v4 = result.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v4 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&result.Bonus, 0, 24);
      result.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
    }
  }
}

// File Line: 2057
// RVA: 0x839100
void __fastcall Scaleform::GFx::AS3::TR::State::exec_astype(
        Scaleform::GFx::AS3::TR::State *this,
        unsigned int mn_index)
{
  Scaleform::GFx::AS3::Value result; // [rsp+58h] [rbp-30h] BYREF

  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_astype, mn_index);
  Scaleform::GFx::AS3::TR::State::PopOpValue(this, &result);
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
}

// File Line: 2068
// RVA: 0x843260
void __fastcall Scaleform::GFx::AS3::TR::State::exec_newclass(Scaleform::GFx::AS3::TR::State *this, unsigned int v)
{
  __int64 v3; // rbx
  Scaleform::GFx::AS3::VMAbcFile *pFile; // rbp
  Scaleform::GFx::AS3::Abc::File *pObject; // rcx
  Scaleform::GFx::AS3::Abc::ClassInfo *v6; // r14
  Scaleform::GFx::AS3::Abc::Multiname *v7; // rbx
  Scaleform::GFx::AS3::Instances::fl::Namespace *InternedNamespace; // rax
  bool IsScaleformGFx; // al
  Scaleform::GFx::AS3::VM *VMRef; // rcx
  Scaleform::GFx::AS3::ClassTraits::ClassClass *UserDefinedTraits; // rax
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v12; // rdx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v13; // r8
  Scaleform::GFx::AS3::VM *v14; // rax
  Scaleform::GFx::AS3::ClassTraits::fl::Boolean *v15; // rcx
  char v16; // al
  int v17; // ebx
  unsigned int v18; // ebx
  Scaleform::GFx::AS3::Value source; // [rsp+28h] [rbp-30h] BYREF

  v3 = v;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_newclass, v);
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->OpStack.Data,
    this->OpStack.Data.Size - 1);
  pFile = this->pTracer->CF->pFile;
  pObject = pFile->File.pObject;
  v6 = pObject->AS3_Classes.Info.Data.Data[v3];
  v7 = &pObject->Const_Pool.const_multiname.Data.Data[v6->inst_info.name_ind];
  InternedNamespace = Scaleform::GFx::AS3::VMFile::GetInternedNamespace(pFile, v7->Ind);
  IsScaleformGFx = Scaleform::GFx::AS3::IsScaleformGFx(InternedNamespace);
  VMRef = this->pTracer->CF->pFile->VMRef;
  if ( IsScaleformGFx )
    UserDefinedTraits = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(VMRef, pFile, v7);
  else
    UserDefinedTraits = (Scaleform::GFx::AS3::ClassTraits::ClassClass *)Scaleform::GFx::AS3::VM::GetUserDefinedTraits(
                                                                          VMRef,
                                                                          pFile,
                                                                          v6);
  v12 = (Scaleform::GFx::AS3::ClassTraits::fl::Object *)UserDefinedTraits;
  if ( !UserDefinedTraits )
    v12 = this->pTracer->CF->pFile->VMRef->TraitsObject.pObject;
  v13 = v12->ITraits.pObject;
  v14 = this->pTracer->CF->pFile->VMRef;
  if ( v13 == v14->TraitsInt.pObject->ITraits.pObject
    || v13 == v14->TraitsUint.pObject->ITraits.pObject
    || v13 == v14->TraitsNumber.pObject->ITraits.pObject
    || (v15 = v14->TraitsBoolean.pObject, v16 = 0, v13 == v15->ITraits.pObject) )
  {
    v16 = 1;
  }
  source.Flags = 9;
  source.Bonus.pWeakProxy = 0i64;
  source.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)v12;
  v17 = 2;
  if ( v16 )
    v17 = 0;
  v18 = (32 * v17) & 0xFFFFFEF6 | 9;
  source.Flags = v18;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->OpStack.Data,
    (__int64 *)this->OpStack.Data.pHeap,
    this->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &this->OpStack.Data.Data[this->OpStack.Data.Size - 1].Flags,
    &source);
  if ( (v18 & 0x1F) > 9 )
  {
    if ( (v18 & 0x200) != 0 )
    {
      LODWORD(MEMORY[0]) = MEMORY[0] - 1;
      if ( !(_DWORD)MEMORY[0] )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
      memset(&source.Bonus, 0, 24);
      source.Flags = v18 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&source);
    }
  }
}

// File Line: 2119
// RVA: 0x782390
void __fastcall Scaleform::GFx::AS3::TR::State::State(
        Scaleform::GFx::AS3::TR::State *this,
        Scaleform::GFx::AS3::Tracer *tr,
        unsigned __int64 cp)
{
  Scaleform::MemoryHeap *Heap; // r8
  Scaleform::MemoryHeap *v5; // rcx
  Scaleform::MemoryHeap *v6; // rcx
  int local_reg_count; // eax
  Scaleform::MemoryHeap *v8; // rcx
  unsigned int v9; // ebx
  char *v10; // rax
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *p_Registers; // [rsp+58h] [rbp+10h] BYREF
  void *p_OpStack; // [rsp+60h] [rbp+18h]

  this->pTracer = tr;
  this->BCP = cp;
  this->OpcodeCP = cp;
  Heap = tr->Heap;
  p_Registers = &this->Registers;
  p_OpStack = &this->Registers;
  this->Registers.Data.Data = 0i64;
  this->Registers.Data.Size = 0i64;
  this->Registers.Data.Policy.Capacity = 0i64;
  this->Registers.Data.pHeap = Heap;
  v5 = tr->Heap;
  p_Registers = &this->OpStack;
  p_OpStack = &this->OpStack;
  this->OpStack.Data.Data = 0i64;
  this->OpStack.Data.Size = 0i64;
  this->OpStack.Data.Policy.Capacity = 0i64;
  this->OpStack.Data.pHeap = v5;
  v6 = tr->Heap;
  p_Registers = &this->ScopeStack;
  p_OpStack = &this->ScopeStack;
  this->ScopeStack.Data.Data = 0i64;
  this->ScopeStack.Data.Size = 0i64;
  this->ScopeStack.Data.Policy.Capacity = 0i64;
  this->ScopeStack.Data.pHeap = v6;
  local_reg_count = tr->CF->pFile->File.pObject->MethodBodies.Info.Data.Data[tr->CF->MBIIndex.Ind]->local_reg_count;
  v8 = tr->Heap;
  p_OpStack = &this->RegistersAlive;
  this->RegistersAlive.BitsCount = local_reg_count;
  v9 = (unsigned int)(local_reg_count + 7) >> 3;
  LODWORD(p_Registers) = 341;
  v10 = (char *)v8->vfptr->Alloc(v8, v9, (Scaleform::AllocInfo *)&p_Registers);
  this->RegistersAlive.pData = v10;
  memset(v10, 0, v9);
}

// File Line: 2163
// RVA: 0x80F7B0
void __fastcall Scaleform::GFx::AS3::TR::State::RefineOpCodeStack1(
        Scaleform::GFx::AS3::TR::State *this,
        Scaleform::GFx::AS3::Abc::Code::OpCode opcode,
        Scaleform::GFx::AS3::InstanceTraits::Traits *type,
        Scaleform::GFx::AS3::Abc::Code::OpCode op)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *ValueTraits; // rax
  Scaleform::GFx::AS3::Tracer *pTracer; // rcx
  Scaleform::GFx::AS3::VM *VMRef; // rcx
  char v11; // al
  Scaleform::GFx::AS3::Value::TraceNullType v12; // r8d

  ValueTraits = (Scaleform::GFx::AS3::InstanceTraits::Traits *)Scaleform::GFx::AS3::TR::State::GetValueTraits(
                                                                 this,
                                                                 &this->OpStack.Data.Data[this->OpStack.Data.Size - 1]);
  pTracer = this->pTracer;
  if ( ValueTraits == type )
  {
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(pTracer, op);
  }
  else
  {
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(pTracer, opcode);
    VMRef = this->pTracer->CF->pFile->VMRef;
    if ( type == VMRef->TraitsInt.pObject->ITraits.pObject
      || type == VMRef->TraitsUint.pObject->ITraits.pObject
      || type == VMRef->TraitsNumber.pObject->ITraits.pObject
      || (v11 = 0, type == VMRef->TraitsBoolean.pObject->ITraits.pObject) )
    {
      v11 = 1;
    }
    v12 = NullOrNot;
    if ( v11 )
      v12 = NotNull;
    Scaleform::GFx::AS3::TR::State::ConvertOpTo(this, type, v12);
  }
}

// File Line: 2194
// RVA: 0x80F890
void __fastcall Scaleform::GFx::AS3::TR::State::RefineOpCodeStack2(
        Scaleform::GFx::AS3::TR::State *this,
        Scaleform::GFx::AS3::Abc::Code::OpCode opcode,
        Scaleform::GFx::AS3::InstanceTraits::Traits *type,
        Scaleform::GFx::AS3::Abc::Code::OpCode op)
{
  Scaleform::GFx::AS3::Tracer *pTracer; // rdi
  Scaleform::GFx::AS3::InstanceTraits::Traits *ITr; // rcx
  Scaleform::GFx::AS3::VM *VMRef; // rax
  Scaleform::GFx::AS3::VM *v11; // rax
  Scaleform::GFx::AS3::ClassTraits::fl::Boolean *pObject; // rcx
  char v13; // al
  Scaleform::GFx::AS3::Value::TraceNullType v14; // r8d
  Scaleform::GFx::AS3::Value v; // [rsp+28h] [rbp-40h] BYREF

  Scaleform::GFx::AS3::TR::State::PopOpValue(this, &v);
  if ( Scaleform::GFx::AS3::TR::State::GetValueTraits(this, &this->OpStack.Data.Data[this->OpStack.Data.Size - 1]) != (Scaleform::GFx::AS3::ClassTraits::fl::Object *)type )
    goto LABEL_12;
  pTracer = this->pTracer;
  if ( (v.Flags & 0x1F) != 0 )
  {
    if ( (v.Flags & 0x1F) - 8 < 2 )
      ITr = v.value.VS._1.ITr;
    else
      ITr = (Scaleform::GFx::AS3::InstanceTraits::Traits *)Scaleform::GFx::AS3::VM::GetValueTraits(
                                                             pTracer->CF->pFile->VMRef,
                                                             &v);
  }
  else
  {
    ITr = pTracer->CF->pFile->VMRef->TraitsVoid.pObject;
  }
  if ( ITr )
  {
    VMRef = pTracer->CF->pFile->VMRef;
    if ( ITr == (Scaleform::GFx::AS3::InstanceTraits::Traits *)VMRef->TraitsClassClass.pObject )
      ITr = (Scaleform::GFx::AS3::InstanceTraits::Traits *)VMRef->TraitsObject.pObject;
  }
  if ( ITr == type )
  {
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(pTracer, op);
  }
  else
  {
LABEL_12:
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, opcode);
    v11 = this->pTracer->CF->pFile->VMRef;
    if ( type == v11->TraitsInt.pObject->ITraits.pObject
      || type == v11->TraitsUint.pObject->ITraits.pObject
      || type == v11->TraitsNumber.pObject->ITraits.pObject
      || (pObject = v11->TraitsBoolean.pObject, v13 = 0, type == pObject->ITraits.pObject) )
    {
      v13 = 1;
    }
    v14 = NullOrNot;
    if ( v13 )
      v14 = NotNull;
    Scaleform::GFx::AS3::TR::State::ConvertOpTo(this, type, v14);
  }
  if ( (v.Flags & 0x1F) > 9 )
  {
    if ( (v.Flags & 0x200) != 0 )
    {
      if ( v.Bonus.pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v.Bonus, 0, 24);
      v.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
    }
  }
}

// File Line: 2227
// RVA: 0x80F6C0
void __fastcall Scaleform::GFx::AS3::TR::State::RefineOpCodeReg1(
        Scaleform::GFx::AS3::TR::State *this,
        Scaleform::GFx::AS3::Abc::Code::OpCode opcode,
        Scaleform::GFx::AS3::InstanceTraits::Traits *type,
        Scaleform::GFx::AS3::Abc::Code::OpCode op,
        int reg_num)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *ValueTraits; // rax
  Scaleform::GFx::AS3::Tracer *pTracer; // rcx
  Scaleform::GFx::AS3::VM *VMRef; // rcx
  char v12; // al
  Scaleform::GFx::AS3::Value::TraceNullType v13; // r9d

  ValueTraits = (Scaleform::GFx::AS3::InstanceTraits::Traits *)Scaleform::GFx::AS3::TR::State::GetValueTraits(
                                                                 this,
                                                                 &this->Registers.Data.Data[reg_num]);
  pTracer = this->pTracer;
  if ( ValueTraits == type )
  {
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(pTracer, op, reg_num);
  }
  else
  {
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(pTracer, opcode, reg_num);
    VMRef = this->pTracer->CF->pFile->VMRef;
    if ( type == VMRef->TraitsInt.pObject->ITraits.pObject
      || type == VMRef->TraitsUint.pObject->ITraits.pObject
      || type == VMRef->TraitsNumber.pObject->ITraits.pObject
      || (v12 = 0, type == VMRef->TraitsBoolean.pObject->ITraits.pObject) )
    {
      v12 = 1;
    }
    v13 = NullOrNot;
    if ( v12 )
      v13 = NotNull;
    Scaleform::GFx::AS3::TR::State::ConvertRegisterTo(this, (Scaleform::GFx::AS3::AbsoluteIndex)reg_num, type, v13);
  }
}

// File Line: 2251
// RVA: 0x8454C0
void __fastcall Scaleform::GFx::AS3::TR::State::exec_pop(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::Tracer *pTracer; // rdi
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *p_OpStack; // rbx
  Scaleform::GFx::AS3::ClassTraits::fl::Object *ValueTraits; // rax
  Scaleform::GFx::AS3::VM *VMRef; // r9
  Scaleform::GFx::AS3::Abc::Code::OpCode v5; // edx

  pTracer = this->pTracer;
  p_OpStack = &this->OpStack;
  ValueTraits = Scaleform::GFx::AS3::TR::State::GetValueTraits(
                  this,
                  &this->OpStack.Data.Data[this->OpStack.Data.Size - 1]);
  VMRef = pTracer->CF->pFile->VMRef;
  if ( ValueTraits == (Scaleform::GFx::AS3::ClassTraits::fl::Object *)VMRef->TraitsBoolean.pObject->ITraits.pObject
    || ValueTraits == (Scaleform::GFx::AS3::ClassTraits::fl::Object *)VMRef->TraitsVoid.pObject
    || ValueTraits == (Scaleform::GFx::AS3::ClassTraits::fl::Object *)VMRef->TraitsNull.pObject
    || ValueTraits == (Scaleform::GFx::AS3::ClassTraits::fl::Object *)VMRef->TraitsInt.pObject->ITraits.pObject
    || ValueTraits == (Scaleform::GFx::AS3::ClassTraits::fl::Object *)VMRef->TraitsUint.pObject->ITraits.pObject
    || (v5 = op_pop,
        ValueTraits == (Scaleform::GFx::AS3::ClassTraits::fl::Object *)VMRef->TraitsNumber.pObject->ITraits.pObject) )
  {
    v5 = op_pop_nrc;
  }
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(pTracer, v5);
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &p_OpStack->Data,
    p_OpStack->Data.Size - 1);
}

// File Line: 2278
// RVA: 0x83EB70
void __fastcall Scaleform::GFx::AS3::TR::State::exec_dup(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::Tracer *pTracer; // rdi
  Scaleform::GFx::AS3::ClassTraits::fl::Object *ValueTraits; // rax
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v4; // r8
  Scaleform::GFx::AS3::VMAbcFile *pFile; // r9
  Scaleform::GFx::AS3::VM *VMRef; // rcx
  Scaleform::GFx::AS3::VM *v7; // rax
  Scaleform::GFx::AS3::Abc::Code::OpCode v8; // edx
  Scaleform::GFx::AS3::Value *v9; // rdx
  Scaleform::GFx::AS3::Value::V1U VObj; // rax

  pTracer = this->pTracer;
  ValueTraits = Scaleform::GFx::AS3::TR::State::GetValueTraits(
                  this,
                  &this->OpStack.Data.Data[this->OpStack.Data.Size - 1]);
  v4 = ValueTraits;
  pFile = pTracer->CF->pFile;
  VMRef = pFile->VMRef;
  if ( ValueTraits == (Scaleform::GFx::AS3::ClassTraits::fl::Object *)VMRef->TraitsBoolean.pObject->ITraits.pObject
    || ValueTraits == (Scaleform::GFx::AS3::ClassTraits::fl::Object *)VMRef->TraitsVoid.pObject
    || (v7 = pFile->VMRef, v4 == (Scaleform::GFx::AS3::ClassTraits::fl::Object *)VMRef->TraitsNull.pObject)
    || v4 == (Scaleform::GFx::AS3::ClassTraits::fl::Object *)VMRef->TraitsInt.pObject->ITraits.pObject
    || v4 == (Scaleform::GFx::AS3::ClassTraits::fl::Object *)v7->TraitsUint.pObject->ITraits.pObject
    || (v8 = op_dup, v4 == (Scaleform::GFx::AS3::ClassTraits::fl::Object *)v7->TraitsNumber.pObject->ITraits.pObject) )
  {
    v8 = op_dup_nrc;
  }
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(pTracer, v8);
  if ( (_S11_12 & 1) == 0 )
  {
    _S11_12 |= 1u;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0i64;
    atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->OpStack.Data,
    (__int64 *)this->OpStack.Data.pHeap,
    this->OpStack.Data.Size + 1);
  v9 = &this->OpStack.Data.Data[this->OpStack.Data.Size - 1];
  if ( v9 )
  {
    v9->Flags = v.Flags;
    v9->Bonus.pWeakProxy = v.Bonus.pWeakProxy;
    v9->value = v.value;
    if ( (v.Flags & 0x1F) > 9 )
    {
      if ( (v.Flags & 0x200) != 0 )
      {
        ++v.Bonus.pWeakProxy->RefCount;
      }
      else
      {
        if ( (v.Flags & 0x1F) == 10 )
        {
          ++v.value.VS._1.VStr->RefCount;
          goto LABEL_23;
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
              goto LABEL_23;
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
  }
LABEL_23:
  Scaleform::GFx::AS3::Value::AssignUnsafe(
    &this->OpStack.Data.Data[this->OpStack.Data.Size - 1],
    &this->OpStack.Data.Data[this->OpStack.Data.Size - 2]);
}

// File Line: 2339
// RVA: 0x83E740
void __fastcall Scaleform::GFx::AS3::TR::State::exec_convert_u(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::Value *v2; // rcx
  Scaleform::GFx::AS3::CheckResult result; // [rsp+30h] [rbp+8h] BYREF

  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_convert_u);
  v2 = &this->OpStack.Data.Data[this->OpStack.Data.Size - 1];
  if ( (v2->Flags & 0x1F) <= 4 || (v2->Flags & 0x1F) == 10 )
    Scaleform::GFx::AS3::Value::ToUInt32Value(v2, &result);
  else
    Scaleform::GFx::AS3::TR::State::ConvertOpTo(
      this,
      this->pTracer->CF->pFile->VMRef->TraitsUint.pObject->ITraits.pObject,
      NotNull);
}

// File Line: 2356
// RVA: 0x8402A0
void __fastcall Scaleform::GFx::AS3::TR::State::exec_getglobalslot(
        Scaleform::GFx::AS3::TR::State *this,
        unsigned int slot_index)
{
  Scaleform::GFx::AS3::Value source; // [rsp+28h] [rbp-30h] BYREF

  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_getglobalslot, slot_index);
  source.Flags = 0;
  source.Bonus.pWeakProxy = 0i64;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->OpStack.Data,
    (__int64 *)this->OpStack.Data.pHeap,
    this->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &this->OpStack.Data.Data[this->OpStack.Data.Size - 1].Flags,
    &source);
}

// File Line: 2368
// RVA: 0x8465F0
void __fastcall Scaleform::GFx::AS3::TR::State::exec_setglobalslot(
        Scaleform::GFx::AS3::TR::State *this,
        unsigned int slot_index)
{
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_setglobalslot, slot_index);
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->OpStack.Data,
    this->OpStack.Data.Size - 1);
}

// File Line: 2380
// RVA: 0x83F320
void __fastcall Scaleform::GFx::AS3::TR::State::exec_esc_xelem(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_esc_xelem);
  Scaleform::GFx::AS3::TR::State::ConvertOpTo(
    this,
    this->pTracer->CF->pFile->VMRef->TraitsString.pObject->ITraits.pObject,
    NotNull);
}

// File Line: 2392
// RVA: 0x83F200
void __fastcall Scaleform::GFx::AS3::TR::State::exec_esc_xattr(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_esc_xattr);
  Scaleform::GFx::AS3::TR::State::ConvertOpTo(
    this,
    this->pTracer->CF->pFile->VMRef->TraitsString.pObject->ITraits.pObject,
    NotNull);
}

// File Line: 2401
// RVA: 0x83E6C0
void __fastcall Scaleform::GFx::AS3::TR::State::exec_convert_i(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::Value *v2; // rcx
  Scaleform::GFx::AS3::CheckResult result; // [rsp+30h] [rbp+8h] BYREF

  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_convert_i);
  v2 = &this->OpStack.Data.Data[this->OpStack.Data.Size - 1];
  if ( (v2->Flags & 0x1F) <= 4 || (v2->Flags & 0x1F) == 10 )
    Scaleform::GFx::AS3::Value::ToInt32Value(v2, &result);
  else
    Scaleform::GFx::AS3::TR::State::ConvertOpTo(
      this,
      this->pTracer->CF->pFile->VMRef->TraitsInt.pObject->ITraits.pObject,
      NotNull);
}

// File Line: 2424
// RVA: 0x83E640
void __fastcall Scaleform::GFx::AS3::TR::State::exec_convert_d(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::Value *v2; // rcx
  Scaleform::GFx::AS3::CheckResult result; // [rsp+30h] [rbp+8h] BYREF

  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_convert_d);
  v2 = &this->OpStack.Data.Data[this->OpStack.Data.Size - 1];
  if ( (v2->Flags & 0x1F) <= 4 || (v2->Flags & 0x1F) == 10 )
    Scaleform::GFx::AS3::Value::ToNumberValue(v2, &result);
  else
    Scaleform::GFx::AS3::TR::State::ConvertOpTo(
      this,
      this->pTracer->CF->pFile->VMRef->TraitsNumber.pObject->ITraits.pObject,
      NotNull);
}

// File Line: 2447
// RVA: 0x83E5B0
void __fastcall Scaleform::GFx::AS3::TR::State::exec_convert_b(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::Value *v2; // rdi
  char v3; // al

  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_convert_b);
  v2 = &this->OpStack.Data.Data[this->OpStack.Data.Size];
  if ( (v2[-1].Flags & 0x1F) <= 4 || (v2[-1].Flags & 0x1F) == 10 )
  {
    v3 = Scaleform::GFx::AS3::Value::Convert2Boolean(v2 - 1);
    Scaleform::GFx::AS3::Value::SetBool(v2 - 1, v3);
  }
  else
  {
    Scaleform::GFx::AS3::TR::State::ConvertOpTo(
      this,
      this->pTracer->CF->pFile->VMRef->TraitsBoolean.pObject->ITraits.pObject,
      NotNull);
  }
}

// File Line: 2464
// RVA: 0x8252F0
void __fastcall Scaleform::GFx::AS3::TR::State::SwapOp(Scaleform::GFx::AS3::TR::State *this)
{
  unsigned __int64 Size; // rbx
  unsigned __int64 v3; // r10
  Scaleform::GFx::AS3::Value *v4; // rdx
  unsigned int Flags; // r8d
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // r9
  Scaleform::GFx::AS3::Value::V1U VObj; // rcx
  unsigned int v8; // ebx
  Scaleform::GFx::AS3::Value other; // [rsp+28h] [rbp-30h] BYREF

  Size = this->OpStack.Data.Size;
  v3 = Size - 1;
  v4 = &this->OpStack.Data.Data[v3];
  Flags = v4->Flags;
  other.Flags = Flags;
  pWeakProxy = v4->Bonus.pWeakProxy;
  other.Bonus.pWeakProxy = pWeakProxy;
  other.value = v4->value;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
    {
      ++pWeakProxy->RefCount;
      goto LABEL_13;
    }
    if ( (Flags & 0x1F) == 10 )
    {
      ++v4->value.VS._1.VStr->RefCount;
    }
    else
    {
      if ( (Flags & 0x1F) <= 0xA )
        goto LABEL_13;
      if ( (Flags & 0x1F) <= 0xF )
      {
        VObj = v4->value.VS._1;
      }
      else
      {
        if ( (Flags & 0x1F) > 0x11 )
          goto LABEL_13;
        VObj = (Scaleform::GFx::AS3::Value::V1U)v4->value.VS._2.VObj;
      }
      if ( VObj.VStr )
        VObj.VStr->Size = (VObj.VStr->Size + 1) & 0x8FBFFFFF;
    }
  }
LABEL_13:
  Scaleform::GFx::AS3::Value::Assign(&this->OpStack.Data.Data[v3], &this->OpStack.Data.Data[v3 - 1]);
  Scaleform::GFx::AS3::Value::Assign(&this->OpStack.Data.Data[Size - 2], &other);
  v8 = other.Flags;
  if ( (other.Flags & 0x1F) > 9 )
  {
    if ( (other.Flags & 0x200) != 0 )
    {
      if ( other.Bonus.pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&other.Bonus, 0, 24);
      other.Flags = v8 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
    }
  }
}

// File Line: 2503
// RVA: 0x83ED50
void __fastcall Scaleform::GFx::AS3::TR::State::exec_dxns(Scaleform::GFx::AS3::TR::State *this, unsigned int index)
{
  Scaleform::GFx::AS3::Tracer *pTracer; // rcx
  Scaleform::GFx::AS3::VM::Error *v4; // rax
  Scaleform::GFx::AS3::VM::Error *v5; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v8; // [rsp+28h] [rbp-20h] BYREF

  pTracer = this->pTracer;
  if ( pTracer->CF->pFile->VMRef->XMLSupport_.pObject->Enabled )
  {
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(pTracer, op_dxns, index);
    if ( (this->pTracer->CF->pFile->File.pObject->Methods.Info.Data.Data[this->pTracer->CF->pFile->File.pObject->MethodBodies.Info.Data.Data[this->pTracer->CF->MBIIndex.Ind]->method_info_ind]->Flags & 0x40) != 0 )
      return;
    Scaleform::GFx::AS3::VM::Error::Error(&v8, 1001, this->pTracer->CF->pFile->VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTracer->CF->pFile->VMRef,
      v5,
      &Scaleform::GFx::AS3::fl::VerifyErrorTI);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v8, 1001, pTracer->CF->pFile->VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTracer->CF->pFile->VMRef,
      v4,
      &Scaleform::GFx::AS3::fl::VerifyErrorTI);
  }
  pNode = v8.Message.pNode;
  if ( v8.Message.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 2529
// RVA: 0x83EE60
void __fastcall Scaleform::GFx::AS3::TR::State::exec_dxnslate(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::VM::Error *v2; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v5; // [rsp+28h] [rbp-20h] BYREF

  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_dxnslate);
  if ( !this->pTracer->CF->pFile->VMRef->XMLSupport_.pObject->Enabled
    || (Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
          &this->OpStack.Data,
          this->OpStack.Data.Size - 1),
        (this->pTracer->CF->pFile->File.pObject->Methods.Info.Data.Data[this->pTracer->CF->pFile->File.pObject->MethodBodies.Info.Data.Data[this->pTracer->CF->MBIIndex.Ind]->method_info_ind]->Flags & 0x40) == 0) )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v5, 1001, this->pTracer->CF->pFile->VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTracer->CF->pFile->VMRef,
      v2,
      &Scaleform::GFx::AS3::fl::VerifyErrorTI);
    pNode = v5.Message.pNode;
    if ( v5.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 2553
// RVA: 0x845F20
void __fastcall Scaleform::GFx::AS3::TR::State::exec_pushwith(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::Value *v2; // rdi
  Scaleform::GFx::AS3::Value result; // [rsp+28h] [rbp-30h] BYREF

  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_pushwith);
  v2 = Scaleform::GFx::AS3::TR::State::PopOpValue(this, &result);
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->ScopeStack.Data,
    (__int64 *)this->ScopeStack.Data.pHeap,
    this->ScopeStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &this->ScopeStack.Data.Data[this->ScopeStack.Data.Size - 1].Flags,
    v2);
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
  this->ScopeStack.Data.Data[this->ScopeStack.Data.Size - 1].Flags |= 0x100u;
}

// File Line: 2567
// RVA: 0x845580
void __fastcall Scaleform::GFx::AS3::TR::State::exec_popscope(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_popscope);
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->ScopeStack.Data,
    this->ScopeStack.Data.Size - 1);
}

// File Line: 2690
// RVA: 0x841E50
void __fastcall Scaleform::GFx::AS3::TR::State::exec_if(
        Scaleform::GFx::AS3::TR::State *this,
        unsigned __int64 *bcp,
        Scaleform::GFx::AS3::Abc::Code::OpCode opcode)
{
  Scaleform::GFx::AS3::Value *Data; // rsi
  Scaleform::GFx::AS3::Tracer *pTracer; // rdi
  unsigned __int64 Size; // rbp
  const char *pCode; // rax
  char v10; // r9
  int v11; // edx
  int v12; // r8d
  int v13; // ebx

  Data = this->OpStack.Data.Data;
  pTracer = this->pTracer;
  Size = this->OpStack.Data.Size;
  if ( Scaleform::GFx::AS3::Tracer::IsSIntType(this->pTracer, &Data[Size - 1])
    && Scaleform::GFx::AS3::Tracer::IsSIntType(pTracer, &Data[this->OpStack.Data.Size - 2]) )
  {
    switch ( opcode )
    {
      case op_ifnlt:
        opcode = op_ifnlt_ti;
        break;
      case op_ifnle:
        opcode = op_ifnle_ti;
        break;
      case op_ifngt:
        opcode = op_ifngt_ti;
        break;
      case op_ifnge:
        opcode = op_ifnge_ti;
        break;
      case op_ifeq:
      case op_ifstricteq:
        opcode = op_ifeq_ti;
        break;
      case op_ifne:
      case op_ifstrictne:
        opcode = op_ifne_ti;
        break;
      case op_iflt:
        opcode = op_iflt_ti;
        break;
      case op_ifle:
        opcode = op_ifle_ti;
        break;
      case op_ifgt:
        opcode = op_ifgt_ti;
        break;
      case op_ifge:
        opcode = op_ifge_ti;
        break;
      default:
        break;
    }
  }
  else if ( Scaleform::GFx::AS3::Tracer::IsNumberType(pTracer, &Data[Size - 1])
         && Scaleform::GFx::AS3::Tracer::IsNumberType(pTracer, &Data[this->OpStack.Data.Size - 2]) )
  {
    switch ( opcode )
    {
      case op_ifnlt:
        opcode = op_ifnlt_td;
        break;
      case op_ifnle:
        opcode = op_ifnle_td;
        break;
      case op_ifngt:
        opcode = op_ifngt_td;
        break;
      case op_ifnge:
        opcode = op_ifnge_td;
        break;
      case op_ifeq:
      case op_ifstricteq:
        opcode = op_ifeq_td;
        break;
      case op_ifne:
      case op_ifstrictne:
        opcode = op_ifne_td;
        break;
      case op_iflt:
        opcode = op_iflt_td;
        break;
      case op_ifle:
        opcode = op_ifle_td;
        break;
      case op_ifgt:
        opcode = op_ifgt_td;
        break;
      case op_ifge:
        opcode = op_ifge_td;
        break;
      default:
        break;
    }
  }
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(pTracer, opcode);
  pCode = pTracer->pCode;
  v10 = pCode[*bcp + 2];
  v11 = (unsigned __int8)pCode[*bcp + 1];
  v12 = (unsigned __int8)pCode[*bcp];
  *bcp += 3i64;
  v13 = v12 | ((v11 | ((unsigned __int8)v10 << 8)) << 8);
  if ( v10 < 0 )
    v13 = -1 - (v13 ^ 0xFFFFFF);
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->OpStack.Data,
    this->OpStack.Data.Size - 1);
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->OpStack.Data,
    this->OpStack.Data.Size - 1);
  Scaleform::GFx::AS3::Tracer::StoreOffset(pTracer, *bcp, this, v13, -1);
}

// File Line: 3060
// RVA: 0x8420F0
void __fastcall Scaleform::GFx::AS3::TR::State::exec_if_boolean(
        Scaleform::GFx::AS3::TR::State *this,
        unsigned __int64 *bcp,
        int opcode)
{
  Scaleform::GFx::AS3::Tracer *pTracer; // rdi
  int v7; // edx
  const char *pCode; // rax
  char v9; // r9
  int v10; // edx
  int v11; // r8d
  int v12; // ebx

  pTracer = this->pTracer;
  if ( Scaleform::GFx::AS3::Tracer::IsBooleanType(this->pTracer, &this->OpStack.Data.Data[this->OpStack.Data.Size - 1]) )
    v7 = (opcode != 17) + 51;
  else
    v7 = opcode;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(pTracer, (Scaleform::GFx::AS3::Abc::Code::OpCode)v7);
  pCode = pTracer->pCode;
  v9 = pCode[*bcp + 2];
  v10 = (unsigned __int8)pCode[*bcp + 1];
  v11 = (unsigned __int8)pCode[*bcp];
  *bcp += 3i64;
  v12 = v11 | ((v10 | ((unsigned __int8)v9 << 8)) << 8);
  if ( v9 < 0 )
    v12 = -1 - (v12 ^ 0xFFFFFF);
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->OpStack.Data,
    this->OpStack.Data.Size - 1);
  Scaleform::GFx::AS3::Tracer::StoreOffset(pTracer, *bcp, this, v12, -1);
}

// File Line: 3189
// RVA: 0x842BF0
void __fastcall Scaleform::GFx::AS3::TR::State::exec_jump(Scaleform::GFx::AS3::TR::State *this, unsigned __int64 *bcp)
{
  Scaleform::GFx::AS3::Tracer *pTracer; // rbx
  const char *pCode; // rax
  char v6; // r11
  int v7; // r10d
  int v8; // r9d
  unsigned __int64 v9; // rdx
  int v10; // r8d

  pTracer = this->pTracer;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_jump);
  pCode = pTracer->pCode;
  v6 = pCode[*bcp + 2];
  v7 = (unsigned __int8)pCode[*bcp];
  v8 = (unsigned __int8)pCode[*bcp + 1];
  v9 = *bcp + 3;
  *bcp = v9;
  v10 = v7 | ((v8 | ((unsigned __int8)v6 << 8)) << 8);
  if ( v6 < 0 )
    v10 = -1 - (v10 ^ 0xFFFFFF);
  Scaleform::GFx::AS3::Tracer::StoreOffset(pTracer, v9, this, v10, -1);
  Scaleform::GFx::AS3::Tracer::AddBlock(pTracer, this, *bcp, tDead, 1);
}

// File Line: 3376
// RVA: 0x847190
void __fastcall Scaleform::GFx::AS3::TR::State::exec_switch(
        Scaleform::GFx::AS3::TR::State *this,
        unsigned __int64 *bcp)
{
  Scaleform::GFx::AS3::Tracer *pTracer; // rbp
  const char *pCode; // rax
  char v6; // r9
  int v7; // r8d
  int v8; // edx
  unsigned __int64 CurrOffset; // r15
  unsigned __int64 v10; // r10
  int v11; // ecx
  const char *v12; // r9
  char v13; // cl
  unsigned int v14; // r8d
  int v15; // esi
  char v16; // cl
  char v17; // dl
  int i; // edi
  const char *v19; // rax
  char v20; // r10
  int v21; // edx
  int v22; // r8d
  unsigned __int64 v23; // rcx
  int v24; // r9d

  pTracer = this->pTracer;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_lookupswitch);
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->OpStack.Data,
    this->OpStack.Data.Size - 1);
  pCode = pTracer->pCode;
  v6 = pCode[*bcp + 2];
  v7 = (unsigned __int8)pCode[*bcp];
  v8 = (unsigned __int8)pCode[*bcp + 1];
  CurrOffset = pTracer->CurrOffset;
  v10 = *bcp + 3;
  *bcp = v10;
  v11 = v7 | ((v8 | ((unsigned __int8)v6 << 8)) << 8);
  if ( v6 < 0 )
    v11 = -1 - (v11 ^ 0xFFFFFF);
  Scaleform::GFx::AS3::Tracer::StoreOffset(pTracer, v10, this, CurrOffset + v11 - v10, 1);
  v12 = pTracer->pCode;
  v13 = v12[*bcp];
  v14 = 7;
  ++*bcp;
  v15 = v13 & 0x7F;
  if ( v13 < 0 )
  {
    do
    {
      if ( v14 >= 0x20 )
        break;
      v16 = v14;
      v14 += 7;
      v17 = v12[(*bcp)++];
      v15 |= (v17 & 0x7F) << v16;
    }
    while ( v17 < 0 );
  }
  Scaleform::GFx::AS3::Tracer::PushNewOpCodeArg0(pTracer, v15);
  for ( i = 0; i <= v15; ++i )
  {
    v19 = pTracer->pCode;
    v20 = v19[*bcp + 2];
    v21 = (unsigned __int8)v19[*bcp + 1];
    v22 = (unsigned __int8)v19[*bcp];
    v23 = *bcp + 3;
    *bcp = v23;
    v24 = v22 | ((v21 | ((unsigned __int8)v20 << 8)) << 8);
    if ( v20 < 0 )
      v24 = -1 - (v24 ^ 0xFFFFFF);
    Scaleform::GFx::AS3::Tracer::StoreOffset(pTracer, v23, this, CurrOffset + v24 - v23, i + 3);
  }
  Scaleform::GFx::AS3::Tracer::AddBlock(pTracer, this, *bcp, tDead, 1);
}

// File Line: 3466
// RVA: 0x844480
void __fastcall Scaleform::GFx::AS3::TR::State::exec_opcode(
        Scaleform::GFx::AS3::TR::State *this,
        Scaleform::GFx::AS3::Abc::Code::OpCode opcode,
        unsigned __int64 *bcp)
{
  __int64 v4; // r15
  Scaleform::GFx::AS3::Tracer *pTracer; // rbp
  const char *pCode; // r14
  unsigned int v8; // eax
  Scaleform::GFx::AS3::Value *Null; // rax
  int v10; // edx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // ebx
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax
  Scaleform::GFx::AS3::VM::Error *v22; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v24; // zf
  unsigned int v25; // eax
  unsigned int v26; // eax
  unsigned int v27; // eax
  unsigned int v28; // eax
  unsigned int v29; // eax
  unsigned int v30; // eax
  unsigned int v31; // eax
  unsigned int v32; // eax
  unsigned int v33; // eax
  unsigned int v34; // eax
  unsigned int v35; // eax
  unsigned int v36; // eax
  unsigned int v37; // eax
  unsigned int v38; // eax
  unsigned int v39; // eax
  unsigned int v40; // eax
  unsigned int v41; // eax
  Scaleform::GFx::AS3::Abc::Code::OpCode v42; // edx
  Scaleform::GFx::AS3::Abc::Code::OpCode v43; // edx
  unsigned int v44; // eax
  Scaleform::GFx::AS3::Abc::Code::OpCode v45; // edx
  Scaleform::GFx::AS3::InstanceTraits::Traits **pObject; // rax
  unsigned int v47; // eax
  Scaleform::GFx::AS3::Abc::Code::OpCode v48; // edx
  unsigned int v49; // ebx
  Scaleform::GFx::AS3::Abc::Code::OpCode v50; // edx
  Scaleform::GFx::AS3::Abc::Code::OpCode v51; // edx
  unsigned int v52; // eax
  int v53; // eax
  int v54; // eax
  unsigned int v55; // eax
  unsigned __int64 v56; // rdx
  int v57; // eax
  unsigned __int64 v58; // rdx
  int v59; // eax
  int v60; // ecx
  int v61; // ecx
  Scaleform::GFx::AS3::VM::Error *v62; // rax
  Scaleform::GFx::ASStringNode *v63; // rcx
  unsigned __int64 v64; // rbx
  int v65; // eax
  int v66; // eax
  Scaleform::GFx::AS3::VM::Error v67; // [rsp+38h] [rbp-90h] BYREF
  Scaleform::GFx::AS3::VM::Error v68; // [rsp+48h] [rbp-80h] BYREF
  Scaleform::GFx::AS3::Value v; // [rsp+58h] [rbp-70h] BYREF
  Scaleform::StringBuffer v70; // [rsp+78h] [rbp-50h] BYREF

  v4 = opcode;
  Scaleform::StringBuffer::StringBuffer(&v70, Scaleform::Memory::pGlobalHeap);
  pTracer = this->pTracer;
  pCode = this->pTracer->pCode;
  this->OpcodeCP = *bcp - 1;
  switch ( (int)v4 )
  {
    case 3:
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(pTracer, op_throw);
      Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        &this->OpStack.Data,
        this->OpStack.Data.Size - 1);
      break;
    case 4:
    case 5:
    case 8:
    case 69:
    case 70:
    case 74:
    case 76:
    case 78:
    case 79:
    case 97:
    case 102:
    case 104:
    case 128:
    case 130:
    case 135:
    case 160:
      break;
    case 6:
      v8 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_dxns(this, v8);
      break;
    case 7:
      Scaleform::GFx::AS3::TR::State::exec_dxnslate(this);
      break;
    case 9:
      Scaleform::GFx::AS3::Tracer::AddBlock(pTracer, this, *bcp - 1, tUnknown, 1);
      break;
    case 12:
    case 13:
    case 14:
    case 15:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
      Scaleform::GFx::AS3::TR::State::exec_if(this, bcp, (Scaleform::GFx::AS3::Abc::Code::OpCode)v4);
      break;
    case 16:
      Scaleform::GFx::AS3::TR::State::exec_jump(this, bcp);
      break;
    case 17:
    case 18:
      Scaleform::GFx::AS3::TR::State::exec_if_boolean(this, bcp, v4);
      break;
    case 27:
      Scaleform::GFx::AS3::TR::State::exec_switch(this, bcp);
      break;
    case 28:
      Scaleform::GFx::AS3::TR::State::exec_pushwith(this);
      break;
    case 29:
      Scaleform::GFx::AS3::TR::State::exec_popscope(this);
      break;
    case 30:
      Scaleform::GFx::AS3::TR::State::exec_nextname(this);
      break;
    case 31:
      Scaleform::GFx::AS3::TR::State::exec_hasnext(this);
      break;
    case 32:
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(pTracer, op_pushnull);
      Null = Scaleform::GFx::AS3::Value::GetNull();
      Scaleform::GFx::AS3::TR::State::PushOp(this, Null);
      break;
    case 33:
      Scaleform::GFx::AS3::TR::State::exec_pushundefined(this);
      break;
    case 35:
      Scaleform::GFx::AS3::TR::State::exec_nextvalue(this);
      break;
    case 36:
      v10 = (unsigned __int8)pCode[(*bcp)++];
      Scaleform::GFx::AS3::TR::State::exec_pushbyte(this, v10);
      break;
    case 37:
      v11 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_pushshort(this, v11);
      break;
    case 38:
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(pTracer, op_pushtrue);
      v.Flags = 1;
      v.Bonus.pWeakProxy = 0i64;
      v.value.VS._1.VBool = 1;
      Scaleform::GFx::AS3::TR::State::PushOp(this, &v);
      break;
    case 39:
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(pTracer, op_pushfalse);
      v.Flags = 1;
      v.Bonus.pWeakProxy = 0i64;
      v.value.VS._1.VBool = 0;
      Scaleform::GFx::AS3::TR::State::PushOp(this, &v);
      break;
    case 40:
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(pTracer, op_pushnan);
      v.Flags = 4;
      v.Bonus.pWeakProxy = 0i64;
      v.value.VS._1.VStr = COERCE_SCALEFORM_GFX_ASSTRINGNODE_(Scaleform::GFx::NumberUtil::NaN());
      Scaleform::GFx::AS3::TR::State::PushOp(this, &v);
      break;
    case 41:
      Scaleform::GFx::AS3::TR::State::exec_pop(this);
      break;
    case 42:
      Scaleform::GFx::AS3::TR::State::exec_dup(this);
      break;
    case 43:
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(pTracer, op_swap);
      Scaleform::GFx::AS3::TR::State::SwapOp(this);
      break;
    case 44:
      v12 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_pushstring(this, v12);
      break;
    case 45:
      v13 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_pushint(this, v13);
      break;
    case 46:
      v14 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_pushuint(this, v14);
      break;
    case 47:
      v15 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_pushdouble(this, v15);
      break;
    case 48:
      Scaleform::GFx::AS3::TR::State::exec_pushscope(this);
      break;
    case 49:
      v16 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_pushnamespace(this, v16);
      break;
    case 50:
      v17 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      v18 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_hasnext2(this, v17, v18);
      break;
    case 53:
    case 54:
    case 55:
    case 56:
    case 57:
    case 58:
    case 59:
    case 60:
    case 61:
    case 62:
    case 80:
    case 81:
    case 82:
      Scaleform::GFx::AS3::TR::State::exec_li8(this);
      break;
    case 64:
      v19 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_newfunction(this, v19);
      break;
    case 65:
      v20 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_call(this, v20);
      break;
    case 66:
      v21 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_construct(this, v21);
      break;
    case 67:
    case 68:
      Scaleform::GFx::AS3::VM::Error::Error(&v67, 1001, pTracer->CF->pFile->VMRef);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        this->pTracer->CF->pFile->VMRef,
        v22,
        &Scaleform::GFx::AS3::fl::VerifyErrorTI);
      pNode = v67.Message.pNode;
      v24 = v67.Message.pNode->RefCount-- == 1;
      if ( v24 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      break;
    case 71:
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(pTracer, op_returnvoid);
      Scaleform::GFx::AS3::Tracer::AddBlock(pTracer, this, *bcp, tDead, 1);
      break;
    case 72:
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(pTracer, op_returnvalue);
      Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        &this->OpStack.Data,
        this->OpStack.Data.Size - 1);
      Scaleform::GFx::AS3::Tracer::AddBlock(pTracer, this, *bcp, tDead, 1);
      break;
    case 73:
      v25 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_constructsuper(this, v25);
      break;
    case 83:
      v26 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_applytype(this, v26);
      break;
    case 85:
      v27 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_newobject(this, v27);
      break;
    case 86:
      v28 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_newarray(this, v28);
      break;
    case 87:
      Scaleform::GFx::AS3::TR::State::exec_newactivation(this);
      break;
    case 88:
      v29 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_newclass(this, v29);
      break;
    case 89:
      v30 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_getdescendants(this, v30);
      break;
    case 90:
      v31 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_newcatch(this, v31);
      break;
    case 93:
      v32 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_findpropstrict(this, v32);
      break;
    case 94:
      v33 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_findproperty(this, v33);
      break;
    case 96:
      v34 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_getlex(this, v34);
      break;
    case 98:
      v55 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_getlocal(this, v55);
      break;
    case 99:
      v35 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_setlocal(this, v35);
      break;
    case 100:
      Scaleform::GFx::AS3::TR::State::exec_getglobalscope(this, 0);
      break;
    case 101:
      v36 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_getscopeobject(this, v36);
      break;
    case 106:
      v37 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_deleteproperty(this, v37);
      break;
    case 108:
      v38 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_getslot(this, v38, 0);
      break;
    case 109:
      v39 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_setslot(this, v39, 0);
      break;
    case 110:
      v40 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_getglobalslot(this, v40);
      break;
    case 111:
      v41 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_setglobalslot(this, v41);
      break;
    case 112:
      v42 = op_convert_s;
      goto LABEL_60;
    case 113:
      Scaleform::GFx::AS3::TR::State::exec_esc_xelem(this);
      break;
    case 114:
      Scaleform::GFx::AS3::TR::State::exec_esc_xattr(this);
      break;
    case 115:
      Scaleform::GFx::AS3::TR::State::exec_convert_i(this);
      break;
    case 116:
      Scaleform::GFx::AS3::TR::State::exec_convert_u(this);
      break;
    case 117:
      Scaleform::GFx::AS3::TR::State::exec_convert_d(this);
      break;
    case 118:
      Scaleform::GFx::AS3::TR::State::exec_convert_b(this);
      break;
    case 119:
      v43 = op_convert_o;
      goto LABEL_135;
    case 120:
      v43 = op_checkfilter;
      goto LABEL_135;
    case 133:
      Scaleform::GFx::AS3::TR::State::exec_coerce_s(this);
      break;
    case 134:
      v44 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_astype(this, v44);
      break;
    case 144:
      Scaleform::GFx::AS3::TR::State::exec_negate(this);
      break;
    case 145:
      v45 = op_increment;
      goto LABEL_73;
    case 146:
      v47 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      v48 = op_inclocal;
      goto LABEL_76;
    case 147:
      v45 = op_decrement;
LABEL_73:
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(pTracer, v45);
      pObject = (Scaleform::GFx::AS3::InstanceTraits::Traits **)this->pTracer->CF->pFile->VMRef->TraitsNumber.pObject;
      goto LABEL_74;
    case 148:
      v47 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      v48 = op_declocal;
LABEL_76:
      v49 = v47;
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, v48);
      Scaleform::GFx::AS3::TR::State::ConvertRegisterTo(
        this,
        (Scaleform::GFx::AS3::AbsoluteIndex)v49,
        this->pTracer->CF->pFile->VMRef->TraitsNumber.pObject->ITraits.pObject,
        NotNull);
      break;
    case 149:
      v42 = op_typeof;
LABEL_60:
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(pTracer, v42);
      Scaleform::GFx::AS3::TR::State::exec_1OpString(this);
      break;
    case 150:
      Scaleform::GFx::AS3::TR::State::exec_not(this);
      break;
    case 151:
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(pTracer, op_bitnot);
      pObject = (Scaleform::GFx::AS3::InstanceTraits::Traits **)this->pTracer->CF->pFile->VMRef->TraitsInt.pObject;
LABEL_74:
      Scaleform::GFx::AS3::TR::State::ConvertOpTo(this, pObject[25], NotNull);
      break;
    case 155:
      Scaleform::GFx::AS3::TR::State::exec_add_d(this);
      break;
    case 161:
      Scaleform::GFx::AS3::TR::State::exec_subtract(this);
      break;
    case 162:
      Scaleform::GFx::AS3::TR::State::exec_multiply(this);
      break;
    case 163:
      Scaleform::GFx::AS3::TR::State::exec_divide(this);
      break;
    case 164:
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(pTracer, op_modulo);
      Scaleform::GFx::AS3::TR::State::exec_2OpNumber(this);
      break;
    case 165:
      v50 = op_lshift;
      goto LABEL_88;
    case 166:
      v50 = op_rshift;
      goto LABEL_88;
    case 167:
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(pTracer, op_urshift);
      Scaleform::GFx::AS3::TR::State::exec_2OpUInt(this);
      break;
    case 168:
      v50 = op_bitand;
      goto LABEL_88;
    case 169:
      v50 = op_bitor;
      goto LABEL_88;
    case 170:
      v50 = op_bitxor;
LABEL_88:
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(pTracer, v50);
      Scaleform::GFx::AS3::TR::State::exec_2OpSInt(this);
      break;
    case 171:
      v51 = op_equals;
      goto LABEL_95;
    case 172:
      v51 = op_strictequals;
      goto LABEL_95;
    case 173:
      v51 = op_lessthan;
      goto LABEL_95;
    case 174:
      v51 = op_lessequals;
      goto LABEL_95;
    case 175:
      v51 = op_greaterthan;
      goto LABEL_95;
    case 176:
      v51 = op_greaterequals;
      goto LABEL_95;
    case 177:
      v51 = op_instanceof;
      goto LABEL_95;
    case 178:
      v52 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::exec_istype(this, v52);
      break;
    case 179:
      v51 = op_istypelate;
      goto LABEL_95;
    case 180:
      v51 = op_in;
LABEL_95:
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(pTracer, v51);
      Scaleform::GFx::AS3::TR::State::exec_2OpBoolean(this);
      break;
    case 192:
      Scaleform::GFx::AS3::TR::State::RefineOpCodeStack1(
        this,
        op_increment_i,
        pTracer->CF->pFile->VMRef->TraitsInt.pObject->ITraits.pObject,
        op_increment_ti);
      break;
    case 193:
      Scaleform::GFx::AS3::TR::State::RefineOpCodeStack1(
        this,
        op_decrement_i,
        pTracer->CF->pFile->VMRef->TraitsInt.pObject->ITraits.pObject,
        op_decrement_ti);
      break;
    case 194:
      v53 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::RefineOpCodeReg1(
        this,
        op_inclocal_i,
        this->pTracer->CF->pFile->VMRef->TraitsInt.pObject->ITraits.pObject,
        op_inclocal_ti,
        v53);
      break;
    case 195:
      v54 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::TR::State::RefineOpCodeReg1(
        this,
        op_declocal_i,
        this->pTracer->CF->pFile->VMRef->TraitsInt.pObject->ITraits.pObject,
        op_declocal_ti,
        v54);
      break;
    case 196:
      Scaleform::GFx::AS3::TR::State::RefineOpCodeStack1(
        this,
        op_negate_i,
        pTracer->CF->pFile->VMRef->TraitsInt.pObject->ITraits.pObject,
        op_negate_ti);
      break;
    case 197:
      Scaleform::GFx::AS3::TR::State::RefineOpCodeStack2(
        this,
        op_add_i,
        pTracer->CF->pFile->VMRef->TraitsInt.pObject->ITraits.pObject,
        op_add_ti);
      break;
    case 198:
      Scaleform::GFx::AS3::TR::State::RefineOpCodeStack2(
        this,
        op_subtract_i,
        pTracer->CF->pFile->VMRef->TraitsInt.pObject->ITraits.pObject,
        op_subtract_ti);
      break;
    case 199:
      Scaleform::GFx::AS3::TR::State::RefineOpCodeStack2(
        this,
        op_multiply_i,
        pTracer->CF->pFile->VMRef->TraitsInt.pObject->ITraits.pObject,
        op_multiply_ti);
      break;
    case 208:
      Scaleform::GFx::AS3::TR::State::exec_getlocal0(this);
      break;
    case 209:
      Scaleform::GFx::AS3::TR::State::exec_getlocal1(this);
      break;
    case 210:
      Scaleform::GFx::AS3::TR::State::exec_getlocal2(this);
      break;
    case 211:
      Scaleform::GFx::AS3::TR::State::exec_getlocal3(this);
      break;
    case 212:
      Scaleform::GFx::AS3::TR::State::exec_setlocal0(this);
      break;
    case 213:
      Scaleform::GFx::AS3::TR::State::exec_setlocal1(this);
      break;
    case 214:
      Scaleform::GFx::AS3::TR::State::exec_setlocal2(this);
      break;
    case 215:
      Scaleform::GFx::AS3::TR::State::exec_setlocal3(this);
      break;
    case 239:
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(pTracer, op_debug);
      v56 = (unsigned __int8)pCode[(*bcp)++];
      Scaleform::GFx::AS3::Tracer::PushNewOpCodeArg0(pTracer, v56);
      v57 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::Tracer::PushNewOpCodeArg0(pTracer, v57);
      v58 = (unsigned __int8)pCode[(*bcp)++];
      Scaleform::GFx::AS3::Tracer::PushNewOpCodeArg0(pTracer, v58);
      goto LABEL_123;
    case 240:
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(pTracer, op_debugline);
      goto LABEL_123;
    case 241:
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(pTracer, op_debugfile);
LABEL_123:
      v59 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      Scaleform::GFx::AS3::Tracer::PushNewOpCodeArg0(pTracer, v59);
      break;
    case 242:
      Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
      break;
    default:
      v60 = (char)(16 * *(_BYTE *)&Scaleform::GFx::AS3::Abc::Code::opcode_info[v4]) >> 4;
      if ( v60 )
      {
        v61 = v60 - 1;
        if ( v61 )
        {
          if ( v61 == 1 )
          {
            v64 = (int)Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
            v65 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
            Scaleform::GFx::AS3::Tracer::PushNewOpCode(pTracer, (Scaleform::GFx::AS3::Abc::Code::OpCode)v4, v64, v65);
          }
          else
          {
            Scaleform::GFx::AS3::VM::Error::Error(&v68, 1001, pTracer->CF->pFile->VMRef);
            Scaleform::GFx::AS3::VM::ThrowErrorInternal(
              this->pTracer->CF->pFile->VMRef,
              v62,
              &Scaleform::GFx::AS3::fl::VerifyErrorTI);
            v63 = v68.Message.pNode;
            v24 = v68.Message.pNode->RefCount-- == 1;
            if ( v24 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v63);
          }
        }
        else
        {
          v66 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, bcp);
          Scaleform::GFx::AS3::Tracer::PushNewOpCode(pTracer, (Scaleform::GFx::AS3::Abc::Code::OpCode)v4, v66);
        }
      }
      else
      {
        v43 = (int)v4;
LABEL_135:
        Scaleform::GFx::AS3::Tracer::PushNewOpCode(pTracer, v43);
      }
      break;
  }
  Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&v70);
}

// File Line: 4201
// RVA: 0x7829D0
void __fastcall Scaleform::GFx::AS3::Tracer::Tracer(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::MemoryHeap *heap,
        Scaleform::GFx::AS3::CallFrame *cf,
        Scaleform::GFx::AS3::MethodInfo *mi)
{
  const char *Data; // r8
  const char *v7; // r8
  unsigned __int64 v8; // rax
  char v9; // al
  int v10; // r9d
  unsigned int v11; // ecx
  char v12; // dl
  unsigned __int64 Size; // rax
  Scaleform::GFx::AS3::MethodInfo *v14; // rbx
  unsigned __int64 v15; // r8
  Scaleform::MemoryHeap *v16; // rcx
  Scaleform::GFx::AS3::TR::State *v17; // rax
  Scaleform::GFx::AS3::TR::State *v18; // rax
  Scaleform::GFx::AS3::TR::State *v19; // r14
  unsigned __int64 v20; // rbx
  unsigned __int64 v21; // r8
  Scaleform::GFx::AS3::TR::State **v22; // rcx
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *p_Data; // rdi
  Scaleform::GFx::AS3::CallFrame *v24; // rcx
  Scaleform::GFx::AS3::Value::V1U OriginationTraits; // rdx
  char v26; // al
  Scaleform::GFx::AS3::Value::V1U v27; // rcx
  int v28; // eax
  unsigned int v29; // r13d
  Scaleform::GFx::AS3::CallFrame *v30; // rdx
  Scaleform::GFx::AS3::Abc::MethodInfo *v31; // r14
  int local_reg_count; // eax
  __int64 i; // rbx
  __int64 v34; // rdx
  bool v35; // zf
  Scaleform::GFx::AS3::Value::VU *v36; // rdx
  Scaleform::GFx::AS3::Value::V1U VObj; // rax
  unsigned __int64 v38; // r12
  char v39; // r15
  Scaleform::GFx::AS3::ClassTraits::Traits *v40; // rax
  Scaleform::GFx::AS3::Value::V1U v41; // r8
  Scaleform::GFx::AS3::VM *VMRef; // rax
  bool v43; // cl
  int v44; // eax
  unsigned int v45; // ebx
  unsigned int v46; // eax
  Scaleform::GFx::AS3::VM::Error *v47; // rax
  Scaleform::GFx::ASStringNode *pWeakProxy; // rcx
  Scaleform::GFx::AS3::Value::V1U pObject; // rcx
  unsigned __int64 v50; // r14
  unsigned int Flags; // ebx
  Scaleform::GFx::ASStringNode *VStr; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v53; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::TR::State *v55; // rbx
  unsigned __int8 v56; // r13
  Scaleform::GFx::AS3::Value::V1U v57; // rcx
  __int64 v58; // rax
  Scaleform::GFx::AS3::TR::Block *v59; // rcx
  unsigned __int64 v60; // [rsp+20h] [rbp-38h]
  Scaleform::GFx::AS3::Value source; // [rsp+30h] [rbp-28h] BYREF
  Scaleform::GFx::AS3::TR::State *v62; // [rsp+A8h] [rbp+50h]
  Scaleform::GFx::AS3::VM *vm; // [rsp+B0h] [rbp+58h]
  Scaleform::GFx::AS3::Abc::MethodInfo *v64; // [rsp+B8h] [rbp+60h]

  this->vfptr = (Scaleform::GFx::AS3::FlashUIVtbl *)&Scaleform::GFx::AS3::FlashUI::`vftable;
  this->State = sError;
  this->NeedToCheck = 0;
  this->vfptr = (Scaleform::GFx::AS3::FlashUIVtbl *)&Scaleform::GFx::AS3::Tracer::`vftable;
  this->Done = 0;
  this->Heap = heap;
  this->CF = cf;
  this->MI = mi;
  this->CurrOffset = 0i64;
  Data = cf->pFile->File.pObject->MethodBodies.Info.Data.Data[cf->MBIIndex.Ind]->code.code.Data;
  if ( Data )
  {
    v9 = *Data;
    v7 = Data + 1;
    v10 = v9 & 0x7F;
    v11 = 7;
    if ( v9 < 0 )
    {
      do
      {
        if ( v11 >= 0x20 )
          break;
        v12 = *v7++;
        v10 |= (v12 & 0x7F) << v11;
        v11 += 7;
      }
      while ( v12 < 0 );
    }
    v8 = v10;
  }
  else
  {
    v7 = &customCaption;
    v8 = 0i64;
  }
  this->BCode.pStr = v7;
  this->BCode.Size = v8;
  this->pCode = v7;
  this->CodeEnd = this->BCode.Size;
  this->PrintOffset = 0i64;
  this->CurrBlock = 0i64;
  this->OrigOpcodePos.Data.Data = 0i64;
  this->OrigOpcodePos.Data.Size = 0i64;
  this->OrigOpcodePos.Data.Policy.Capacity = 0i64;
  this->OrigOpcodePos.Data.pHeap = heap;
  this->NewOpcodePos.Data.Data = 0i64;
  this->NewOpcodePos.Data.Size = 0i64;
  this->NewOpcodePos.Data.Policy.Capacity = 0i64;
  this->NewOpcodePos.Data.pHeap = heap;
  this->PosToRecalculate.Data.Data = 0i64;
  this->PosToRecalculate.Data.Size = 0i64;
  this->PosToRecalculate.Data.Policy.Capacity = 0i64;
  this->PosToRecalculate.Data.pHeap = heap;
  this->Orig2newPosMap.Data.Data = 0i64;
  this->Orig2newPosMap.Data.Size = 0i64;
  this->Orig2newPosMap.Data.Policy.Capacity = 0i64;
  this->Orig2newPosMap.Data.pHeap = heap;
  this->States.Data.Data = 0i64;
  this->States.Data.Size = 0i64;
  this->States.Data.Policy.Capacity = 0i64;
  this->States.Data.pHeap = heap;
  this->Blocks.Root.pPrev = (Scaleform::GFx::AS3::TR::Block *)&this->Blocks;
  this->Blocks.Root.pNext = (Scaleform::GFx::AS3::TR::Block *)&this->Blocks;
  this->CatchTraits.Data.Data = 0i64;
  this->CatchTraits.Data.Size = 0i64;
  this->CatchTraits.Data.Policy.Capacity = 0i64;
  this->CatchTraits.Data.pHeap = heap;
  vm = this->CF->pFile->VMRef;
  this->NeedToCheck = vm->UI->NeedToCheck;
  this->State = sStep;
  Size = vm->CallStack.Size;
  this->PrintOffset = Size;
  if ( Size )
    this->PrintOffset = Size - 1;
  v14 = this->MI;
  if ( v14->OpCode.Data.Size && (v14->OpCode.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    if ( v14->OpCode.Data.Data )
    {
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v14->OpCode.Data.Data = 0i64;
    }
    v14->OpCode.Data.Policy.Capacity = 0i64;
  }
  v14->OpCode.Data.Size = 0i64;
  v15 = this->BCode.Size;
  if ( v15 > this->MI->OpCode.Data.Policy.Capacity )
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &this->MI->OpCode.Data,
      &this->MI->OpCode,
      v15);
  Scaleform::ArrayDataDH<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->Orig2newPosMap.Data,
    this->BCode.Size);
  v17 = (Scaleform::GFx::AS3::TR::State *)this->Heap->vfptr->Alloc(v16, 136i64, 0i64);
  if ( v17 )
  {
    Scaleform::GFx::AS3::TR::State::State(v17, this, 0i64);
    v19 = v18;
  }
  else
  {
    v19 = 0i64;
  }
  v62 = v19;
  v20 = this->States.Data.Size + 1;
  if ( v20 >= this->States.Data.Size )
  {
    if ( v20 <= this->States.Data.Policy.Capacity )
      goto LABEL_25;
    v21 = v20 + (v20 >> 2);
  }
  else
  {
    if ( v20 >= this->States.Data.Policy.Capacity >> 1 )
      goto LABEL_25;
    v21 = this->States.Data.Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
    (Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy> *)&this->States,
    this->States.Data.pHeap,
    v21);
LABEL_25:
  this->States.Data.Size = v20;
  v22 = &this->States.Data.Data[v20 - 1];
  if ( v22 )
    *v22 = v19;
  p_Data = &v19->Registers.Data;
  v24 = this->CF;
  OriginationTraits = (Scaleform::GFx::AS3::Value::V1U)v24->OriginationTraits;
  v26 = LOBYTE(OriginationTraits.VStr[2].Size) >> 5;
  source.Bonus.pWeakProxy = 0i64;
  if ( (v26 & 1) != 0 )
  {
    source.value.VS._1 = OriginationTraits;
    source.Flags = 9;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &v19->Registers.Data,
      v19->Registers.Data.pHeap,
      v19->Registers.Data.Size + 1);
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
      &p_Data->Data[v19->Registers.Data.Size - 1],
      &source);
  }
  else
  {
    v28 = v24->Invoker.Flags & 0x1F;
    source.Flags = 8;
    if ( (_BYTE)v28 == 14 )
      source.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)v24->pFile->VMRef->TraitsObject.pObject->ITraits.pObject;
    else
      source.value.VS._1 = OriginationTraits;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &v19->Registers.Data,
      v19->Registers.Data.pHeap,
      v19->Registers.Data.Size + 1);
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
      &p_Data->Data[v19->Registers.Data.Size - 1],
      &source);
  }
  *v19->RegistersAlive.pData |= 1u;
  v29 = 1;
  v30 = this->CF;
  v31 = v30->pFile->File.pObject->Methods.Info.Data.Data[v30->pFile->File.pObject->MethodBodies.Info.Data.Data[v30->MBIIndex.Ind]->method_info_ind];
  v64 = v31;
  local_reg_count = v30->pFile->File.pObject->MethodBodies.Info.Data.Data[v30->MBIIndex.Ind]->local_reg_count;
  if ( local_reg_count > 1 )
  {
    for ( i = (unsigned int)(local_reg_count - 1); i; --i )
    {
      if ( (_S11_12 & 1) == 0 )
      {
        _S11_12 |= 1u;
        v.Flags = 0;
        v.Bonus.pWeakProxy = 0i64;
        atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
      }
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        p_Data,
        p_Data[1].Data,
        p_Data->Size + 1);
      v27.VStr = (Scaleform::GFx::ASStringNode *)(32 * p_Data->Size);
      v34 = (__int64)&p_Data->Data[-1];
      v35 = (Scaleform::GFx::ASStringNode *)((char *)v27.VStr + v34) == 0;
      v36 = (Scaleform::GFx::AS3::Value::VU *)((char *)v27.VStr + v34);
      *(_QWORD *)&source.Flags = v36;
      if ( v35 )
        continue;
      v36->VS._1.VInt = v.Flags;
      v36->VS._2.VObj = (Scaleform::GFx::AS3::Object *)v.Bonus.pWeakProxy;
      v36[1] = v.value;
      v27.VStr = (Scaleform::GFx::ASStringNode *)v.Flags;
      if ( (v.Flags & 0x1F) <= 9 )
        continue;
      v27.VStr = (Scaleform::GFx::ASStringNode *)(v.Flags >> 9);
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
          VObj = v.value.VS._1;
LABEL_47:
          if ( VObj.VStr )
          {
            ++VObj.VStr->Size;
            VObj.VStr->Size &= 0x8FBFFFFF;
          }
          continue;
        }
        if ( (v.Flags & 0x1F) <= 0x11 )
        {
          VObj = (Scaleform::GFx::AS3::Value::V1U)v.value.VS._2.VObj;
          goto LABEL_47;
        }
      }
    }
  }
  v60 = v31->ParamTypes.Data.Size;
  v38 = 0i64;
  v39 = 2;
  if ( !v60 )
  {
LABEL_82:
    if ( (v31->Flags & 4) != 0 )
    {
      pObject = (Scaleform::GFx::AS3::Value::V1U)vm->TraitsArray.pObject->ITraits.pObject;
      source.Bonus.pWeakProxy = 0i64;
      source.value.VS._1 = pObject;
      source.Flags = 8;
      v50 = v29;
      Scaleform::GFx::AS3::Value::Assign(&p_Data->Data[v29], &source);
      Flags = source.Flags;
      if ( (source.Flags & 0x1F) > 9 )
      {
        if ( (source.Flags & 0x200) == 0 )
        {
          switch ( source.Flags & 0x1F )
          {
            case 0xA:
              goto LABEL_89;
            case 0xB:
            case 0xC:
            case 0xD:
            case 0xE:
            case 0xF:
              goto LABEL_103;
            case 0x10:
            case 0x11:
              goto LABEL_92;
            default:
              goto LABEL_98;
          }
          goto LABEL_98;
        }
        goto LABEL_85;
      }
    }
    else
    {
      if ( (v31->Flags & 1) == 0 )
      {
        v55 = v62;
        goto LABEL_106;
      }
      v57 = (Scaleform::GFx::AS3::Value::V1U)vm->TraitsArray.pObject->ITraits.pObject;
      source.Bonus.pWeakProxy = 0i64;
      source.value.VS._1 = v57;
      source.Flags = 8;
      v50 = v29;
      Scaleform::GFx::AS3::Value::Assign(&p_Data->Data[v29], &source);
      Flags = source.Flags;
      if ( (source.Flags & 0x1F) > 9 )
      {
        if ( (source.Flags & 0x200) == 0 )
        {
          switch ( source.Flags & 0x1F )
          {
            case 0xA:
LABEL_89:
              VStr = source.value.VS._1.VStr;
              v35 = source.value.VS._1.VStr->RefCount-- == 1;
              if ( v35 )
                Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
              break;
            case 0xB:
            case 0xC:
            case 0xD:
            case 0xE:
            case 0xF:
LABEL_103:
              if ( !source.value.VS._1.VBool )
              {
                v53 = source.value.VS._1.VObj;
                goto LABEL_95;
              }
              --source.value.VS._1.VStr;
              break;
            case 0x10:
            case 0x11:
LABEL_92:
              if ( ((__int64)source.value.VS._2.VObj & 1) != 0 )
              {
                --source.value.VS._2.VObj;
              }
              else
              {
                v53 = source.value.VS._2.VObj;
LABEL_95:
                if ( v53 )
                {
                  RefCount = v53->RefCount;
                  if ( (RefCount & 0x3FFFFF) != 0 )
                  {
                    v53->RefCount = RefCount - 1;
                    Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v53);
                  }
                }
              }
              break;
            default:
              goto LABEL_98;
          }
          goto LABEL_98;
        }
LABEL_85:
        v35 = source.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v35 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&source.Bonus, 0, 24);
        source.Flags = Flags & 0xFFFFFDE0;
      }
    }
LABEL_98:
    v55 = v62;
    v56 = v29 & 7;
    v27.VStr = (Scaleform::GFx::ASStringNode *)v56;
    v62->RegistersAlive.pData[v50 >> 3] |= 1 << v56;
LABEL_106:
    v58 = ((__int64 (__fastcall *)(_QWORD, _QWORD))this->Heap->vfptr->Alloc)(
            (Scaleform::GFx::AS3::Value::V1U)v27.VStr,
            48i64);
    v59 = (Scaleform::GFx::AS3::TR::Block *)v58;
    if ( v58 )
    {
      *(_DWORD *)(v58 + 16) |= 1u;
      *(_DWORD *)(v58 + 20) = 0;
      *(_QWORD *)(v58 + 24) = v55;
      *(_QWORD *)(v58 + 32) = 0i64;
      *(_QWORD *)(v58 + 40) = 0i64;
    }
    else
    {
      v59 = 0i64;
    }
    v59->pPrev = this->Blocks.Root.pPrev;
    v59->pNext = (Scaleform::GFx::AS3::TR::Block *)&this->Blocks;
    this->Blocks.Root.pPrev->pNext = v59;
    this->Blocks.Root.pPrev = v59;
    return;
  }
  while ( 1 )
  {
    v40 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
            vm,
            this->CF->pFile,
            &this->CF->pFile->File.pObject->Const_Pool.const_multiname.Data.Data[v31->ParamTypes.Data.Data[v38]]);
    if ( !v40 )
      break;
    v41 = (Scaleform::GFx::AS3::Value::V1U)v40->ITraits.pObject;
    VMRef = this->CF->pFile->VMRef;
    v43 = v41.VStr == (Scaleform::GFx::ASStringNode *)VMRef->TraitsInt.pObject->ITraits.pObject
       || v41.VStr == (Scaleform::GFx::ASStringNode *)VMRef->TraitsUint.pObject->ITraits.pObject
       || v41.VStr == (Scaleform::GFx::ASStringNode *)VMRef->TraitsNumber.pObject->ITraits.pObject
       || v41.VStr == (Scaleform::GFx::ASStringNode *)VMRef->TraitsBoolean.pObject->ITraits.pObject;
    source.Flags = 8;
    source.Bonus.pWeakProxy = 0i64;
    source.value.VS._1 = v41;
    v44 = 2;
    if ( v43 )
      v44 = 0;
    source.Flags = (32 * v44) & 0xFFFFFEF7 | 8;
    Scaleform::GFx::AS3::Value::Assign(&p_Data->Data[v29], &source);
    v45 = source.Flags;
    v27.VStr = (Scaleform::GFx::ASStringNode *)(source.Flags & 0x1F);
    if ( (source.Flags & 0x1F) > 9 )
    {
      if ( (source.Flags & 0x200) != 0 )
      {
        v35 = source.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v35 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&source.Bonus, 0, 24);
        source.Flags = v45 & 0xFFFFFDE0;
      }
      else
      {
        switch ( source.Flags & 0x1F )
        {
          case 0xA:
            v27 = source.value.VS._1;
            v35 = source.value.VS._1.VStr->RefCount-- == 1;
            if ( v35 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v27.VStr);
            break;
          case 0xB:
          case 0xC:
          case 0xD:
          case 0xE:
          case 0xF:
            if ( !source.value.VS._1.VBool )
            {
              v27 = source.value.VS._1;
              goto LABEL_75;
            }
            --source.value.VS._1.VStr;
            break;
          case 0x10:
          case 0x11:
            if ( ((__int64)source.value.VS._2.VObj & 1) != 0 )
            {
              --source.value.VS._2.VObj;
            }
            else
            {
              v27 = (Scaleform::GFx::AS3::Value::V1U)source.value.VS._2.VObj;
LABEL_75:
              if ( v27.VStr )
              {
                v46 = v27.VStr->Size;
                if ( (v46 & 0x3FFFFF) != 0 )
                {
                  v27.VStr->Size = v46 - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v27.VObj);
                }
              }
            }
            break;
          default:
            break;
        }
      }
    }
    v62->RegistersAlive.pData[(unsigned __int64)v29++ >> 3] |= v39;
    v39 = __ROL1__(v39, 1);
    ++v38;
    v31 = v64;
    if ( v38 >= v60 )
      goto LABEL_82;
  }
  Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&source, 1014, vm);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v47, &Scaleform::GFx::AS3::fl::VerifyErrorTI);
  pWeakProxy = (Scaleform::GFx::ASStringNode *)source.Bonus.pWeakProxy;
  v35 = LODWORD(source.Bonus.pWeakProxy[1].pObject)-- == 1;
  if ( v35 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pWeakProxy);
}

// File Line: 4363
// RVA: 0x78E660
void __fastcall Scaleform::GFx::AS3::Tracer::~Tracer(Scaleform::GFx::AS3::Tracer *this)
{
  Scaleform::GFx::AS3::TR::Block *pNext; // rdx
  Scaleform::List<Scaleform::GFx::AS3::TR::Block,Scaleform::GFx::AS3::TR::Block> *p_Blocks; // rdi
  Scaleform::GFx::AS3::TR::Block *v4; // rbx
  unsigned __int64 Size; // rbp
  unsigned __int64 i; // rbx
  Scaleform::GFx::AS3::TR::State **Data; // rax
  Scaleform::GFx::AS3::TR::State *v8; // rdi
  unsigned __int64 v9; // rdi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch> *j; // rbx
  Scaleform::GFx::AS3::InstanceTraits::fl::Catch *pObject; // rcx
  unsigned int RefCount; // eax

  this->vfptr = (Scaleform::GFx::AS3::FlashUIVtbl *)&Scaleform::GFx::AS3::Tracer::`vftable;
  pNext = this->Blocks.Root.pNext;
  p_Blocks = &this->Blocks;
  if ( pNext != (Scaleform::GFx::AS3::TR::Block *)&this->Blocks )
  {
    do
    {
      v4 = pNext->pNext;
      pNext->pPrev->pNext = v4;
      pNext->pNext->Scaleform::ListNode<Scaleform::GFx::AS3::TR::Block>::$9DF84E59DCC7CB7977F20654EF131B14::pPrev = pNext->pPrev;
      pNext->pPrev = (Scaleform::GFx::AS3::TR::Block *)-1i64;
      pNext->pNext = (Scaleform::GFx::AS3::TR::Block *)-1i64;
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      pNext = v4;
    }
    while ( v4 != (Scaleform::GFx::AS3::TR::Block *)p_Blocks );
  }
  p_Blocks->Root.pPrev = (Scaleform::GFx::AS3::TR::Block *)p_Blocks;
  p_Blocks->Root.pNext = (Scaleform::GFx::AS3::TR::Block *)p_Blocks;
  Size = this->States.Data.Size;
  for ( i = 0i64; i < Size; ++i )
  {
    Data = this->States.Data.Data;
    v8 = Data[i];
    if ( v8 )
    {
      Scaleform::GFx::AS3::TR::State::~State(Data[i]);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v8);
    }
  }
  v9 = this->CatchTraits.Data.Size;
  for ( j = &this->CatchTraits.Data.Data[v9 - 1]; v9; --v9 )
  {
    pObject = j->pObject;
    if ( j->pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        j->pObject = (Scaleform::GFx::AS3::InstanceTraits::fl::Catch *)((char *)pObject - 1);
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
    --j;
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->CatchTraits.Data.Data);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->States.Data.Data);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->Orig2newPosMap.Data.Data);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->PosToRecalculate.Data.Data);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->NewOpcodePos.Data.Data);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->OrigOpcodePos.Data.Data);
  this->vfptr = (Scaleform::GFx::AS3::FlashUIVtbl *)&Scaleform::GFx::AS3::FlashUI::`vftable;
}

// File Line: 4386
// RVA: 0x7C6B10
void __fastcall Scaleform::GFx::AS3::Tracer::EmitCode(Scaleform::GFx::AS3::Tracer *this)
{
  Scaleform::GFx::AS3::CallFrame *CF; // rcx
  Scaleform::GFx::AS3::VMAbcFile *pFile; // rax
  Scaleform::GFx::AS3::VM *VMRef; // rsi
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v5; // rax
  unsigned __int64 v6; // r14
  unsigned __int64 v7; // r15
  __int64 v8; // r12
  Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo *v9; // rdi
  Scaleform::GFx::AS3::TR::Block *v10; // rax
  Scaleform::GFx::AS3::TR::Block *v11; // rax
  __int64 exc_type_ind; // rcx
  Scaleform::GFx::AS3::TR::State *State; // r13
  Scaleform::GFx::AS3::CallFrame *v14; // rax
  Scaleform::GFx::AS3::Value::V1U pObject; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v16; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v17; // rdi
  int CanBeNull; // eax
  unsigned int v19; // esi
  Scaleform::GFx::AS3::VM::Error *v20; // rax
  Scaleform::GFx::ASStringNode *pWeakProxy; // rcx
  Scaleform::GFx::AS3::MethodInfo *MI; // rbx
  unsigned __int64 v24; // rdx
  __int64 v25; // r8
  Scaleform::GFx::AS3::Tracer::Recalculate *Data; // r10
  unsigned __int64 pos; // r11
  unsigned __int64 *v28; // r9
  unsigned __int64 v29; // rax
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v30; // r15
  __int64 v31; // r12
  unsigned int *p_from; // rdx
  unsigned __int64 *v33; // rcx
  unsigned int v34; // r13d
  Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception *p_Exception; // rdi
  unsigned __int64 v36; // rsi
  unsigned __int64 v37; // r8
  __int64 v38; // rcx
  Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo *v39; // rax
  Scaleform::GFx::AS3::Value v40; // [rsp+38h] [rbp-31h] BYREF
  Scaleform::GFx::AS3::Value source; // [rsp+58h] [rbp-11h] BYREF
  Scaleform::GFx::AS3::VM *v42; // [rsp+D0h] [rbp+67h]
  unsigned int v43; // [rsp+D0h] [rbp+67h]
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v44; // [rsp+D8h] [rbp+6Fh]
  unsigned int v45; // [rsp+D8h] [rbp+6Fh]
  unsigned int v46; // [rsp+E0h] [rbp+77h]
  unsigned int v47; // [rsp+E8h] [rbp+7Fh]

  if ( this->Done )
    return;
  CF = this->CF;
  pFile = CF->pFile;
  VMRef = pFile->VMRef;
  v42 = VMRef;
  v5 = pFile->File.pObject->MethodBodies.Info.Data.Data[CF->MBIIndex.Ind];
  v44 = v5;
  v6 = 0i64;
  v7 = 0i64;
  if ( !v5->exception.info.Data.Size )
  {
LABEL_21:
    Scaleform::GFx::AS3::Tracer::TraceBlock(this, 0i64, this->Blocks.Root.pNext);
    if ( VMRef->HandleException )
    {
      MI = this->MI;
      if ( MI->OpCode.Data.Size && (MI->OpCode.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 )
      {
        if ( MI->OpCode.Data.Data )
        {
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          MI->OpCode.Data.Data = 0i64;
        }
        MI->OpCode.Data.Policy.Capacity = 0i64;
      }
      MI->OpCode.Data.Size = 0i64;
      return;
    }
    v24 = 0i64;
    if ( this->PosToRecalculate.Data.Size )
    {
      v25 = 0i64;
      do
      {
        Data = this->PosToRecalculate.Data.Data;
        pos = Data[v25].pos;
        v28 = &this->MI->OpCode.Data.Data[pos];
        v29 = 0i64;
        if ( *v28 < this->Orig2newPosMap.Data.Size )
          v29 = Data[v25].base + this->Orig2newPosMap.Data.Data[*v28] - pos;
        *v28 = v29;
        ++v24;
        ++v25;
      }
      while ( v24 < this->PosToRecalculate.Data.Size );
    }
    v30 = this->CF->pFile->File.pObject->MethodBodies.Info.Data.Data[this->CF->MBIIndex.Ind];
    if ( !v30->exception.info.Data.Size )
    {
LABEL_42:
      this->Done = 1;
      return;
    }
    v31 = 0i64;
    while ( 1 )
    {
      p_from = &v30->exception.info.Data.Data[v31].from;
      v33 = this->Orig2newPosMap.Data.Data;
      v34 = v33[*p_from];
      v43 = v33[p_from[1]];
      v45 = v33[p_from[2]];
      v46 = p_from[3];
      v47 = p_from[4];
      p_Exception = &this->MI->Exception;
      v36 = this->MI->Exception.info.Data.Size + 1;
      if ( v36 >= this->MI->Exception.info.Data.Size )
      {
        if ( v36 > this->MI->Exception.info.Data.Policy.Capacity )
        {
          v37 = v36 + (v36 >> 2);
          goto LABEL_40;
        }
      }
      else if ( v36 < this->MI->Exception.info.Data.Policy.Capacity >> 1 )
      {
        v37 = this->MI->Exception.info.Data.Size + 1;
LABEL_40:
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &p_Exception->info.Data,
          p_Exception,
          v37);
      }
      p_Exception->info.Data.Size = v36;
      v38 = v36;
      v39 = p_Exception->info.Data.Data;
      v39[v38 - 1].from = v34;
      v39[v38 - 1].to = v43;
      v39[v38 - 1].target = v45;
      v39[v38 - 1].exc_type_ind = v46;
      v39[v38 - 1].var_name_ind = v47;
      ++v6;
      ++v31;
      if ( v6 >= v30->exception.info.Data.Size )
        goto LABEL_42;
    }
  }
  v8 = 0i64;
  while ( 1 )
  {
    v9 = v5->exception.info.Data.Data;
    v10 = Scaleform::GFx::AS3::Tracer::AddBlock(this, this->Blocks.Root.pNext->State, v9[v8].from, tUnknown, 0);
    if ( v10 )
    {
      *((_DWORD *)v10 + 4) &= ~1u;
      v10->Type |= 2u;
    }
    v11 = Scaleform::GFx::AS3::Tracer::AddBlock(this, this->Blocks.Root.pNext->State, v9[v8].target, tUnknown, 0);
    if ( !v11 )
      goto LABEL_17;
    exc_type_ind = (int)v9[v8].exc_type_ind;
    v11->CurOpStackSize = 1i64;
    v11->Type |= 4u;
    State = v11->State;
    v14 = this->CF;
    if ( (_DWORD)exc_type_ind )
      break;
    pObject = (Scaleform::GFx::AS3::Value::V1U)v14->pFile->VMRef->TraitsObject.pObject->ITraits.pObject;
    source.Bonus.pWeakProxy = 0i64;
    source.value.VS._1 = pObject;
    source.Flags = 72;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &State->OpStack.Data,
      State->OpStack.Data.pHeap,
      State->OpStack.Data.Size + 1);
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
      &State->OpStack.Data.Data[State->OpStack.Data.Size - 1].Flags,
      &source);
LABEL_17:
    ++v7;
    ++v8;
    v5 = v44;
    if ( v7 >= v44->exception.info.Data.Size )
      goto LABEL_21;
  }
  v16 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
          VMRef,
          v14->pFile,
          &v14->pFile->File.pObject->Const_Pool.const_multiname.Data.Data[exc_type_ind]);
  if ( v16 )
  {
    v17 = v16->ITraits.pObject;
    CanBeNull = Scaleform::GFx::AS3::Tracer::CanBeNull(this, v17);
    v40.Bonus.pWeakProxy = 0i64;
    v40.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)v17;
    v19 = (32 * CanBeNull) & 0xFFFFFEF7 | 8;
    v40.Flags = v19;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &State->OpStack.Data,
      State->OpStack.Data.pHeap,
      State->OpStack.Data.Size + 1);
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
      &State->OpStack.Data.Data[State->OpStack.Data.Size - 1].Flags,
      &v40);
    if ( (v19 & 0x1F) > 9 )
    {
      if ( (v19 & 0x200) != 0 )
      {
        LODWORD(MEMORY[0]) = MEMORY[0] - 1;
        if ( !(_DWORD)MEMORY[0] )
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
        memset(&v40.Bonus, 0, 24);
        v40.Flags = v19 & 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v40);
      }
    }
    VMRef = v42;
    goto LABEL_17;
  }
  Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v40, 1014, VMRef);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(VMRef, v20, &Scaleform::GFx::AS3::fl::VerifyErrorTI);
  pWeakProxy = (Scaleform::GFx::ASStringNode *)v40.Bonus.pWeakProxy;
  if ( LODWORD(v40.Bonus.pWeakProxy[1].pObject)-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pWeakProxy);
}orm::GFx::AS3::fl::VerifyErrorTI);
  pWeakProxy = (Scaleform::GFx::ASStringNode *)v40.Bonus.pWeakProxy;
  if ( LODWORD(v40.Bonus.pWeakProxy[1].pObjec

// File Line: 4596
// RVA: 0x829400
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Tracer::UpdateBlock(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::CheckResult *result,
        unsigned __int64 bcp)
{
  Scaleform::GFx::AS3::TR::Block *CurrBlock; // rax
  Scaleform::GFx::AS3::TR::Block *pPrev; // rdx
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+30h] [rbp+8h] BYREF

  CurrBlock = this->CurrBlock;
  pPrev = this->Blocks.Root.pPrev;
  if ( pPrev )
  {
    while ( bcp < pPrev->From )
    {
      pPrev = pPrev->pPrev;
      if ( !pPrev )
      {
        result->Result = 1;
        return result;
      }
    }
    if ( pPrev->From == bcp )
    {
      this->CurrBlock = pPrev;
      if ( (*((_BYTE *)pPrev + 16) & 1) != 0 )
      {
        if ( pPrev != CurrBlock && !Scaleform::GFx::AS3::Tracer::MergeBlock(this, &resulta, pPrev, CurrBlock)->Result )
        {
          result->Result = 0;
          return result;
        }
      }
      else
      {
        Scaleform::GFx::AS3::Tracer::InitializeBlock(this, pPrev, CurrBlock);
      }
    }
  }
  result->Result = 1;
  return result;
}

// File Line: 4846
// RVA: 0x821520
void __fastcall Scaleform::GFx::AS3::Tracer::SkipDeadCode(Scaleform::GFx::AS3::Tracer *this, unsigned __int64 *bcp)
{
  __int64 v4; // rdx
  unsigned __int64 v5; // r8
  unsigned __int64 v6; // rax
  unsigned int v7; // r8d
  const char *pCode; // r10
  char v9; // cl
  int v10; // r9d
  char v11; // cl
  char v12; // dl
  __int64 v13; // rcx
  int v14; // edx
  const char *v15; // r9
  unsigned int v16; // edx
  char v17; // cl
  char v18; // cl
  const char *v19; // r8
  unsigned int v20; // edx
  char v21; // cl
  char v22; // cl
  Scaleform::GFx::AS3::CheckResult result; // [rsp+30h] [rbp+8h] BYREF

  if ( (this->CurrBlock->Type & 1) != 0 )
  {
    do
    {
      if ( *bcp >= this->CodeEnd )
        return;
      Scaleform::GFx::AS3::Tracer::RegisterOrigOpCode(this, *bcp);
      v4 = (unsigned __int8)this->pCode[*bcp];
      v5 = *bcp + 1;
      *bcp = v5;
      if ( (int)v4 >= 12 )
      {
        if ( (int)v4 <= 26 )
        {
          *bcp = v5 + 3;
          continue;
        }
        switch ( (_DWORD)v4 )
        {
          case 0x1B:
            v6 = v5 + 3;
            v7 = 7;
            *bcp = v6;
            pCode = this->pCode;
            v9 = pCode[v6++];
            *bcp = v6;
            v10 = v9 & 0x7F;
            if ( v9 < 0 )
            {
              do
              {
                if ( v7 >= 0x20 )
                  break;
                v11 = v7;
                v7 += 7;
                v12 = pCode[(*bcp)++];
                v10 |= (v12 & 0x7F) << v11;
              }
              while ( v12 < 0 );
            }
            if ( v10 >= 0 )
            {
              v13 = (unsigned int)(v10 + 1);
              do
              {
                *bcp += 3i64;
                --v13;
              }
              while ( v13 );
            }
            continue;
          case 0x24:
            *bcp = v5 + 1;
            continue;
          case 0xEF:
            *bcp = v5 + 1;
            Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(this->pCode, bcp);
            ++*bcp;
            Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(this->pCode, bcp);
            continue;
        }
      }
      v14 = ((char)(16 * *(_BYTE *)&Scaleform::GFx::AS3::Abc::Code::opcode_info[v4]) >> 4) - 1;
      if ( !v14 )
        goto LABEL_23;
      if ( v14 == 1 )
      {
        v15 = this->pCode;
        v16 = 7;
        v17 = v15[v5];
        *bcp = v5 + 1;
        if ( v17 < 0 )
        {
          do
          {
            if ( v16 >= 0x20 )
              break;
            v16 += 7;
            v18 = v15[(*bcp)++];
          }
          while ( v18 < 0 );
        }
LABEL_23:
        v19 = this->pCode;
        v20 = 7;
        v21 = v19[(*bcp)++];
        if ( v21 < 0 )
        {
          do
          {
            if ( v20 >= 0x20 )
              break;
            v20 += 7;
            v22 = v19[(*bcp)++];
          }
          while ( v22 < 0 );
        }
      }
    }
    while ( Scaleform::GFx::AS3::Tracer::UpdateBlock(this, &result, *bcp)->Result && (this->CurrBlock->Type & 1) != 0 );
  }
}

// File Line: 5007
// RVA: 0x828610
void __fastcall Scaleform::GFx::AS3::Tracer::TraceBlock(
        Scaleform::GFx::AS3::Tracer *this,
        unsigned __int64 bcp,
        Scaleform::GFx::AS3::TR::Block *initBlock)
{
  unsigned __int64 v3; // rdi
  Scaleform::GFx::AS3::TR::Block *i; // rdx
  unsigned __int64 v6; // rdi
  unsigned __int64 v7; // rdi
  Scaleform::GFx::AS3::Abc::Code::OpCode v8; // ecx
  Scaleform::GFx::AS3::TR::Block *CurrBlock; // rax
  Scaleform::GFx::AS3::Abc::Code::OpCode v10; // edi
  Scaleform::GFx::AS3::CheckResult result; // [rsp+30h] [rbp+8h] BYREF
  unsigned __int64 bcpa; // [rsp+38h] [rbp+10h] BYREF

  bcpa = bcp;
  v3 = bcp;
  for ( i = this->Blocks.Root.pPrev; i; i = i->pPrev )
  {
    if ( v3 >= i->From )
      break;
  }
  this->CurrBlock = i;
  if ( (*((_BYTE *)i + 16) & 1) != 0 )
  {
    if ( i != initBlock && !Scaleform::GFx::AS3::Tracer::MergeBlock(this, &result, i, initBlock)->Result )
      return;
  }
  else
  {
    Scaleform::GFx::AS3::Tracer::InitializeBlock(this, i, initBlock);
  }
  if ( v3 < this->CodeEnd )
  {
    do
    {
      if ( this->CF->pFile->VMRef->HandleException )
        break;
      if ( !Scaleform::GFx::AS3::Tracer::UpdateBlock(this, &result, v3)->Result )
        break;
      Scaleform::GFx::AS3::Tracer::SkipDeadCode(this, &bcpa);
      v6 = bcpa;
      if ( bcpa >= this->CodeEnd )
        break;
      Scaleform::GFx::AS3::Tracer::RegisterOrigOpCode(this, bcpa);
      v7 = v6 + 1;
      v8 = (unsigned __int8)this->pCode[v7 - 1];
      CurrBlock = this->CurrBlock;
      bcpa = v7;
      v10 = v8;
      if ( !Scaleform::GFx::AS3::Tracer::SubstituteOpCode(this, v8, &bcpa, CurrBlock->State) )
      {
        if ( this->CF->pFile->VMRef->HandleException )
          return;
        Scaleform::GFx::AS3::TR::State::exec_opcode(this->CurrBlock->State, v10, &bcpa);
      }
      v3 = bcpa;
    }
    while ( bcpa < this->CodeEnd );
  }
}

// File Line: 5107
// RVA: 0x822490
void __fastcall Scaleform::GFx::AS3::Tracer::StoreOffset(
        Scaleform::GFx::AS3::Tracer *this,
        unsigned __int64 bcp,
        Scaleform::GFx::AS3::TR::State *st,
        int offset,
        int base)
{
  unsigned __int64 v6; // rbx
  Scaleform::GFx::AS3::MethodInfo *MI; // rax
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Tracer::Recalculate,Scaleform::AllocatorDH_POD<Scaleform::GFx::AS3::Tracer::Recalculate,328>,Scaleform::ArrayDefaultPolicy> *p_Data; // rdi
  unsigned __int64 Size; // rsi
  unsigned __int64 v10; // rax
  unsigned __int64 v11; // rsi
  unsigned __int64 v12; // rbx
  unsigned __int64 v13; // r8
  Scaleform::GFx::AS3::Tracer::Recalculate *Data; // rcx
  __int64 v15; // rbx
  __int64 v16; // [rsp+38h] [rbp-10h]

  v6 = bcp + offset;
  if ( offset < 0 )
  {
    Scaleform::GFx::AS3::Tracer::PushNewOpCodeArg0(
      this,
      base + this->Orig2newPosMap.Data.Data[v6] - this->MI->OpCode.Data.Size);
    return;
  }
  Scaleform::GFx::AS3::Tracer::AddBlock(this, st, v6, tUnknown, 1);
  Scaleform::GFx::AS3::Tracer::PushNewOpCodeArg0(this, v6);
  MI = this->MI;
  p_Data = &this->PosToRecalculate.Data;
  Size = MI->OpCode.Data.Size;
  LODWORD(v16) = base;
  v10 = p_Data->Size;
  v11 = Size - 1;
  v12 = v10 + 1;
  if ( v10 + 1 >= v10 )
  {
    if ( v12 > p_Data->Policy.Capacity )
    {
      v13 = v12 + (v12 >> 2);
      goto LABEL_8;
    }
  }
  else if ( v12 < p_Data->Policy.Capacity >> 1 )
  {
    v13 = v10 + 1;
LABEL_8:
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Tracer::Recalculate,Scaleform::AllocatorDH_POD<Scaleform::GFx::AS3::Tracer::Recalculate,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
      p_Data,
      (__int64 *)p_Data[1].Data,
      v13);
  }
  Data = p_Data->Data;
  p_Data->Size = v12;
  v15 = v12;
  Data[v15 - 1].pos = v11;
  *(_QWORD *)&Data[v15 - 1].base = v16;
}

// File Line: 5200
// RVA: 0x821710
void __fastcall Scaleform::GFx::AS3::Tracer::SkipOrigOpCode(
        Scaleform::GFx::AS3::Tracer *this,
        unsigned __int64 *opcode_cp,
        unsigned __int64 new_cp)
{
  if ( *opcode_cp >= this->CodeEnd )
  {
    *opcode_cp = new_cp;
  }
  else
  {
    Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy>>::PushBack(
      &this->OrigOpcodePos,
      opcode_cp);
    this->Orig2newPosMap.Data.Data[*opcode_cp] = this->MI->OpCode.Data.Size;
    *opcode_cp = new_cp;
  }
}

// File Line: 5216
// RVA: 0x80FBF0
void __fastcall Scaleform::GFx::AS3::Tracer::RegisterOrigOpCode(
        Scaleform::GFx::AS3::Tracer *this,
        unsigned __int64 opcode_cp)
{
  unsigned __int64 Size; // rax
  unsigned __int64 v5; // rdi
  unsigned __int64 v6; // r8
  unsigned __int64 *Data; // rax

  if ( opcode_cp < this->CodeEnd )
  {
    this->CurrOffset = opcode_cp;
    Size = this->OrigOpcodePos.Data.Size;
    v5 = Size + 1;
    if ( Size + 1 >= Size )
    {
      if ( v5 > this->OrigOpcodePos.Data.Policy.Capacity )
      {
        v6 = v5 + (v5 >> 2);
        goto LABEL_7;
      }
    }
    else if ( v5 < this->OrigOpcodePos.Data.Policy.Capacity >> 1 )
    {
      v6 = Size + 1;
LABEL_7:
      Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &this->OrigOpcodePos.Data,
        this->OrigOpcodePos.Data.pHeap,
        v6);
    }
    Data = this->OrigOpcodePos.Data.Data;
    this->OrigOpcodePos.Data.Size = v5;
    Data[v5 - 1] = opcode_cp;
    this->Orig2newPosMap.Data.Data[opcode_cp] = this->MI->OpCode.Data.Size;
  }
}

// File Line: 5256
// RVA: 0x7ED7D0
__int64 __fastcall Scaleform::GFx::AS3::Tracer::GetOrigValueConsumer(
        Scaleform::GFx::AS3::Tracer *this,
        unsigned __int64 bcp)
{
  unsigned __int64 CodeEnd; // rbp
  unsigned __int64 v3; // r8
  int v5; // esi
  const char *pCode; // rbx
  __int64 v7; // rdi
  char v8; // dl
  int v9; // eax
  int v10; // ecx
  unsigned __int64 v11; // r8
  int v12; // r9d
  __int64 v13; // r11
  unsigned __int8 v14; // r10
  int v15; // esi
  char v16; // al
  unsigned int v17; // ecx
  int v18; // r9d
  char v19; // dl
  int v20; // eax
  char v21; // al
  unsigned int v22; // ecx
  int v23; // r9d
  char v24; // dl
  int v25; // eax
  char v26; // al
  unsigned int v27; // ecx
  int v28; // r9d
  char v29; // dl
  int v30; // eax
  char v31; // al
  unsigned int v32; // ecx
  char v33; // al
  char v34; // al
  unsigned int v35; // ecx
  char v36; // al
  unsigned __int64 cp; // [rsp+48h] [rbp+10h] BYREF

  CodeEnd = this->CodeEnd;
  v3 = bcp;
  v5 = 1;
  if ( bcp < CodeEnd )
  {
    pCode = this->pCode;
    while ( 1 )
    {
      v7 = (unsigned __int8)pCode[v3++];
      if ( (_DWORD)v7 == 16 )
      {
        v8 = pCode[v3 + 2];
        v9 = (unsigned __int8)pCode[v3 + 1];
        v10 = (unsigned __int8)pCode[v3];
        v11 = v3 + 3;
        v12 = v10 | ((v9 | ((unsigned __int8)v8 << 8)) << 8);
        if ( v8 < 0 )
          v12 = -1 - (v12 ^ 0xFFFFFF);
        v3 = v12 + v11;
        goto LABEL_44;
      }
      v13 = v7;
      v14 = byte_14182DEC1[2 * v7];
      v15 = v5 - ((*(_BYTE *)&Scaleform::GFx::AS3::Abc::Code::opcode_info[v7] >> 5) & 3);
      if ( (v14 & 8) != 0 )
      {
        v16 = pCode[v3++];
        v17 = 7;
        v18 = v16 & 0x7F;
        if ( v16 < 0 )
        {
          do
          {
            if ( v17 >= 0x20 )
              break;
            v19 = pCode[v3++];
            v20 = (v19 & 0x7F) << v17;
            v17 += 7;
            v18 |= v20;
          }
          while ( v19 < 0 );
        }
        switch ( this->CF->pFile->File.pObject->Const_Pool.const_multiname.Data.Data[v18].Kind )
        {
          case MN_RTQName:
          case MN_MultinameL:
          case MN_RTQNameA:
          case MN_MultinameLA:
            --v15;
            break;
          case MN_RTQNameL:
          case MN_RTQNameLA:
            v15 -= 2;
            break;
          default:
            break;
        }
      }
      if ( (v14 & 4) != 0 )
      {
        v21 = pCode[v3++];
        v22 = 7;
        v23 = v21 & 0x7F;
        if ( v21 < 0 )
        {
          do
          {
            if ( v22 >= 0x20 )
              break;
            v24 = pCode[v3++];
            v25 = (v24 & 0x7F) << v22;
            v22 += 7;
            v23 |= v25;
          }
          while ( v24 < 0 );
        }
        if ( (_DWORD)v7 == 85 )
          v15 -= 2 * v23;
        else
          v15 -= v23;
      }
      if ( v15 <= 0 )
        return (unsigned int)v7;
      v5 = (byte_14182DEC1[v13 * 2] & 3) + v15;
      if ( ((v14 | (v14 >> 1)) & 4) == 0 )
      {
        if ( (int)v7 < 12 )
          goto LABEL_36;
        if ( (int)v7 <= 26 )
        {
          v3 += 3i64;
          goto LABEL_44;
        }
        switch ( (_DWORD)v7 )
        {
          case 0x1B:
            v26 = pCode[v3 + 3];
            v3 += 4i64;
            v27 = 7;
            v28 = v26 & 0x7F;
            if ( v26 < 0 )
            {
              do
              {
                if ( v27 >= 0x20 )
                  break;
                v29 = pCode[v3++];
                v30 = (v29 & 0x7F) << v27;
                v27 += 7;
                v28 |= v30;
              }
              while ( v29 < 0 );
            }
            if ( v28 >= 0 )
              v3 += (unsigned int)(v28 + 1) + 2i64 * (unsigned int)(v28 + 1);
            break;
          case 0x24:
            ++v3;
            break;
          case 0xEF:
            cp = v3 + 1;
            Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, &cp);
            ++cp;
            Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(pCode, &cp);
            v3 = cp;
            break;
          default:
LABEL_36:
            if ( (char)(16 * *(_BYTE *)&Scaleform::GFx::AS3::Abc::Code::opcode_info[v13]) >> 4 == 1 )
              goto LABEL_41;
            if ( (char)(16 * *(_BYTE *)&Scaleform::GFx::AS3::Abc::Code::opcode_info[v13]) >> 4 == 2 )
            {
              v31 = pCode[v3++];
              v32 = 7;
              if ( v31 < 0 )
              {
                do
                {
                  if ( v32 >= 0x20 )
                    break;
                  v33 = pCode[v3++];
                  v32 += 7;
                }
                while ( v33 < 0 );
              }
LABEL_41:
              v34 = pCode[v3++];
              v35 = 7;
              if ( v34 < 0 )
              {
                do
                {
                  if ( v35 >= 0x20 )
                    break;
                  v36 = pCode[v3++];
                  v35 += 7;
                }
                while ( v36 < 0 );
              }
            }
            break;
        }
      }
LABEL_44:
      if ( v3 >= CodeEnd )
        return (unsigned int)v7;
    }
  }
  return 2i64;
}

// File Line: 5664
// RVA: 0x7F9870
void __fastcall Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::Value *to,
        Scaleform::GFx::AS3::Value *from,
        Scaleform::GFx::AS3::InstanceTraits::Traits *result_type)
{
  Scaleform::GFx::AS3::VM *VMRef; // rax
  Scaleform::GFx::AS3::ClassTraits::fl::Boolean *pObject; // rcx
  char v7; // al
  unsigned int v8; // edx
  unsigned int Flags; // ebx
  Scaleform::GFx::AS3::Value other; // [rsp+28h] [rbp-30h] BYREF

  VMRef = this->CF->pFile->VMRef;
  if ( result_type == VMRef->TraitsInt.pObject->ITraits.pObject
    || result_type == VMRef->TraitsUint.pObject->ITraits.pObject
    || result_type == VMRef->TraitsNumber.pObject->ITraits.pObject
    || (pObject = VMRef->TraitsBoolean.pObject, v7 = 0, result_type == pObject->ITraits.pObject) )
  {
    v7 = 1;
  }
  v8 = 2;
  if ( v7 )
    v8 = 0;
  if ( v8 )
  {
    v8 = 2;
    if ( ((to->Flags >> 5) & 3) == ((from->Flags >> 5) & 3) )
      v8 = (to->Flags >> 5) & 3;
  }
  other.Bonus.pWeakProxy = 0i64;
  other.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)result_type;
  other.Flags = (32 * v8) & 0xFFFFFEF7 | 8;
  Scaleform::GFx::AS3::Value::Assign(to, &other);
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

// File Line: 5717
// RVA: 0x7F9740
void __fastcall Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::Value *to,
        Scaleform::GFx::AS3::Value *from,
        Scaleform::GFx::AS3::ClassTraits::Traits *result_type)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // r10
  Scaleform::GFx::AS3::VM *VMRef; // rax
  Scaleform::GFx::AS3::ClassTraits::fl::Boolean *v7; // rcx
  char v8; // al
  unsigned int v9; // edx
  unsigned int Flags; // ebx
  Scaleform::GFx::AS3::Value other; // [rsp+28h] [rbp-30h] BYREF

  pObject = result_type->ITraits.pObject;
  VMRef = this->CF->pFile->VMRef;
  if ( pObject == VMRef->TraitsInt.pObject->ITraits.pObject
    || pObject == VMRef->TraitsUint.pObject->ITraits.pObject
    || pObject == VMRef->TraitsNumber.pObject->ITraits.pObject
    || (v7 = VMRef->TraitsBoolean.pObject, v8 = 0, pObject == v7->ITraits.pObject) )
  {
    v8 = 1;
  }
  v9 = 2;
  if ( v8 )
    v9 = 0;
  if ( v9 )
  {
    v9 = 2;
    if ( ((to->Flags >> 5) & 3) == ((from->Flags >> 5) & 3) )
      v9 = (to->Flags >> 5) & 3;
  }
  other.Bonus.pWeakProxy = 0i64;
  other.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)result_type;
  other.Flags = (32 * v9) & 0xFFFFFEF6 | 9;
  Scaleform::GFx::AS3::Value::Assign(to, &other);
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

// File Line: 5770
// RVA: 0x8010B0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Tracer::MergeValues(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::CheckResult *result,
        unsigned __int64 ind,
        Scaleform::GFx::AS3::TR::State *to,
        Scaleform::GFx::AS3::TR::State *from,
        Scaleform::GFx::AS3::TR::MergeSet ms)
{
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *p_Registers; // r11
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *p_ScopeStack; // rbx
  Scaleform::GFx::AS3::Value *v9; // r12
  Scaleform::GFx::AS3::Value *v10; // r14
  Scaleform::GFx::AS3::InstanceTraits::Traits *ITr; // rbx
  Scaleform::GFx::AS3::VM *VMRef; // rax
  unsigned int Flags; // esi
  int v14; // ebp
  Scaleform::GFx::AS3::InstanceTraits::Traits *ValueTraits; // rdi
  Scaleform::GFx::AS3::VM *v16; // rax
  unsigned int v17; // r9d
  unsigned __int64 v18; // rdx
  int v19; // r8d
  Scaleform::GFx::AS3::TR::State *v20; // rsi
  Scaleform::GFx::AS3::VMAbcFile *pFile; // rsi
  Scaleform::GFx::AS3::VM *v22; // rax
  bool IsNumericType; // dl
  Scaleform::GFx::AS3::InstanceTraits::Traits *i; // rax
  char v25; // si
  Scaleform::GFx::AS3::VM *v26; // rax
  Scaleform::GFx::AS3::VM *v27; // rbx
  Scaleform::GFx::AS3::VM::Error *v28; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v30; // zf
  Scaleform::GFx::AS3::CheckResult *v31; // rax
  unsigned __int64 v32; // rdx
  int v33; // r8d
  bool v34; // al
  char v35; // r15
  char *pData; // rax
  bool v37; // [rsp+20h] [rbp-58h]
  int v38; // [rsp+24h] [rbp-54h]
  Scaleform::GFx::AS3::VM::Error v39; // [rsp+30h] [rbp-48h] BYREF
  unsigned int v41; // [rsp+90h] [rbp+18h]

  v41 = ind;
  p_Registers = 0i64;
  p_ScopeStack = 0i64;
  if ( ms )
  {
    if ( ms == msScopeStack )
    {
      p_ScopeStack = &to->ScopeStack;
    }
    else if ( ms == msRegisterFile )
    {
      p_ScopeStack = &to->Registers;
    }
  }
  else
  {
    p_ScopeStack = &to->OpStack;
  }
  if ( ms )
  {
    if ( ms == msScopeStack )
    {
      p_Registers = &from->ScopeStack;
    }
    else if ( ms == msRegisterFile )
    {
      p_Registers = &from->Registers;
    }
  }
  else
  {
    p_Registers = &from->OpStack;
  }
  v9 = &p_ScopeStack->Data.Data[ind];
  v10 = &p_Registers->Data.Data[ind];
  v38 = v9->Flags & 0x1F;
  if ( v38 )
  {
    if ( (v9->Flags & 0x1F) - 8 < 2 )
      ITr = v9->value.VS._1.ITr;
    else
      ITr = (Scaleform::GFx::AS3::InstanceTraits::Traits *)Scaleform::GFx::AS3::VM::GetValueTraits(
                                                             this->CF->pFile->VMRef,
                                                             v9);
  }
  else
  {
    ITr = this->CF->pFile->VMRef->TraitsVoid.pObject;
  }
  if ( ITr )
  {
    VMRef = this->CF->pFile->VMRef;
    if ( ITr == (Scaleform::GFx::AS3::InstanceTraits::Traits *)VMRef->TraitsClassClass.pObject )
      ITr = (Scaleform::GFx::AS3::InstanceTraits::Traits *)VMRef->TraitsObject.pObject;
  }
  Flags = v10->Flags;
  v14 = v10->Flags & 0x1F;
  if ( v14 )
  {
    if ( (v10->Flags & 0x1F) - 8 < 2 )
      ValueTraits = v10->value.VS._1.ITr;
    else
      ValueTraits = (Scaleform::GFx::AS3::InstanceTraits::Traits *)Scaleform::GFx::AS3::VM::GetValueTraits(
                                                                     this->CF->pFile->VMRef,
                                                                     v10);
  }
  else
  {
    ValueTraits = this->CF->pFile->VMRef->TraitsVoid.pObject;
  }
  if ( ValueTraits )
  {
    v16 = this->CF->pFile->VMRef;
    if ( ValueTraits == (Scaleform::GFx::AS3::InstanceTraits::Traits *)v16->TraitsClassClass.pObject )
      ValueTraits = (Scaleform::GFx::AS3::InstanceTraits::Traits *)v16->TraitsObject.pObject;
  }
  if ( ms == msScopeStack )
  {
    if ( (((unsigned __int8)BYTE1(v9->Flags) ^ BYTE1(Flags)) & 1) != 0 )
      goto $error;
  }
  else if ( ms == msRegisterFile )
  {
    v17 = v41;
    v18 = (unsigned __int64)v41 >> 3;
    v19 = 1 << (v41 & 7);
    v20 = to;
    if ( ((unsigned __int8)v19 & from->RegistersAlive.pData[v18]) == 0 )
      goto LABEL_84;
    if ( ((unsigned __int8)v19 & to->RegistersAlive.pData[v18]) == 0 )
    {
      Scaleform::GFx::AS3::Value::Assign(v9, v10);
LABEL_83:
      v17 = v41;
LABEL_84:
      v32 = (unsigned __int64)v17 >> 3;
      v33 = 1 << (v17 & 7);
      v34 = ((unsigned __int8)v33 & from->RegistersAlive.pData[v32]) != 0
         || ((unsigned __int8)v33 & v20->RegistersAlive.pData[v32]) != 0;
      v35 = 1 << (v17 & 7);
      v30 = !v34;
      pData = v20->RegistersAlive.pData;
      if ( v30 )
        pData[v32] &= ~v35;
      else
        pData[v32] |= v35;
      goto LABEL_91;
    }
  }
  if ( ITr == ValueTraits )
  {
$success:
    if ( ms != msRegisterFile )
    {
LABEL_91:
      v31 = result;
      result->Result = 1;
      return v31;
    }
    v20 = to;
    goto LABEL_83;
  }
  if ( !v38 )
    goto LABEL_80;
  pFile = this->CF->pFile;
  v22 = pFile->VMRef;
  if ( ITr == v22->TraitsObject.pObject->ITraits.pObject || ITr == v22->TraitsClassClass.pObject->ITraits.pObject )
    goto $success;
  if ( Scaleform::GFx::AS3::Tracer::IsAnyType(this, ValueTraits) )
  {
    Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(
      this,
      v9,
      v10,
      pFile->VMRef->TraitsObject.pObject->ITraits.pObject);
    goto $success;
  }
  IsNumericType = Scaleform::GFx::AS3::Tracer::IsNumericType(this, ITr);
  v37 = IsNumericType;
  if ( IsNumericType )
  {
    if ( Scaleform::GFx::AS3::Tracer::IsNumericType(this, ValueTraits) )
    {
      Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(
        this,
        v9,
        v10,
        pFile->VMRef->TraitsNumber.pObject->ITraits.pObject);
      goto $success;
    }
    IsNumericType = v37;
  }
  if ( ((unsigned int)(v38 - 12) <= 3 || v38 == 10) && !v9->value.VS._1.VStr || ITr == pFile->VMRef->TraitsNull.pObject )
  {
    if ( ((unsigned int)(v14 - 12) <= 3 || v14 == 10) && !v10->value.VS._1.VStr )
      goto $success;
    v26 = pFile->VMRef;
    if ( ValueTraits == v26->TraitsNull.pObject )
      goto $success;
    if ( ValueTraits != v26->TraitsString.pObject->ITraits.pObject
      && Scaleform::GFx::AS3::Tracer::IsNumericType(this, ValueTraits) )
    {
      goto $error;
    }
LABEL_80:
    Scaleform::GFx::AS3::Value::Assign(v9, v10);
    goto $success;
  }
  if ( ((unsigned int)(v14 - 12) <= 3 || v14 == 10) && !v10->value.VS._1.VStr
    || ValueTraits == pFile->VMRef->TraitsNull.pObject )
  {
    if ( ITr == pFile->VMRef->TraitsString.pObject->ITraits.pObject || !IsNumericType )
      goto $success;
  }
  else
  {
    for ( i = ITr; i; i = (Scaleform::GFx::AS3::InstanceTraits::Traits *)i->pParent.pObject )
      i->Flags |= 0x80ui64;
    if ( ValueTraits )
    {
      while ( SLOBYTE(ValueTraits->Flags) >= 0 )
      {
        ValueTraits = (Scaleform::GFx::AS3::InstanceTraits::Traits *)ValueTraits->pParent.pObject;
        if ( !ValueTraits )
          goto LABEL_63;
      }
      v25 = 1;
      if ( (ValueTraits->Flags & 0x20) != 0 )
        Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(
          this,
          v9,
          v10,
          (Scaleform::GFx::AS3::ClassTraits::Traits *)ValueTraits);
      else
        Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(this, v9, v10, ValueTraits);
    }
    else
    {
LABEL_63:
      v25 = 0;
    }
    for ( ; ITr; ITr = (Scaleform::GFx::AS3::InstanceTraits::Traits *)ITr->pParent.pObject )
      ITr->Flags &= ~0x80ui64;
    if ( v25 )
      goto $success;
  }
$error:
  v27 = this->CF->pFile->VMRef;
  Scaleform::GFx::AS3::VM::Error::Error(&v39, 1068, v27);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(v27, v28, &Scaleform::GFx::AS3::fl::VerifyErrorTI);
  pNode = v39.Message.pNode;
  v30 = v39.Message.pNode->RefCount-- == 1;
  if ( v30 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v31 = result;
  result->Result = 0;
  return v31;
}ternal(v27, v28, &Scaleform::GFx::AS3::fl::VerifyErrorTI);
  pNode = v39.Message.pNode;
  v30 = v39.Message.pNode->RefCount-- == 1;
  if ( v30 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v31 = result;
  result->Result = 0;
  re

// File Line: 5951
// RVA: 0x800F60
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Tracer::MergeLists(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::TR::State *to,
        Scaleform::GFx::AS3::TR::State *from,
        bool check_size,
        Scaleform::GFx::AS3::TR::MergeSet ms)
{
  Scaleform::GFx::AS3::TR::MergeSet v6; // r12d
  unsigned __int64 v7; // rbx
  Scaleform::GFx::AS3::Tracer *v10; // r10
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *p_ScopeStack; // rsi
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *p_Registers; // r14
  __int64 v14; // r15
  unsigned __int64 Size; // r8
  Scaleform::GFx::AS3::Value *v16; // rdi
  Scaleform::GFx::AS3::TR::State *v18; // [rsp+88h] [rbp+20h]

  v18 = from;
  v6 = ms;
  v7 = 0i64;
  v10 = this;
  p_ScopeStack = 0i64;
  if ( ms )
  {
    if ( ms == msScopeStack )
    {
      p_ScopeStack = &to->ScopeStack;
    }
    else if ( ms == msRegisterFile )
    {
      p_ScopeStack = &to->Registers;
    }
  }
  else
  {
    p_ScopeStack = &to->OpStack;
  }
  p_Registers = 0i64;
  if ( ms )
  {
    if ( ms == msScopeStack )
    {
      p_Registers = &from->ScopeStack;
    }
    else if ( ms == msRegisterFile )
    {
      p_Registers = &from->Registers;
    }
  }
  else
  {
    p_Registers = &from->OpStack;
  }
  if ( check_size && p_ScopeStack->Data.Size != p_Registers->Data.Size )
  {
    result->Result = 0;
    return result;
  }
  if ( !p_Registers->Data.Size )
  {
LABEL_22:
    result->Result = 1;
    return result;
  }
  v14 = 0i64;
  while ( 1 )
  {
    Size = p_ScopeStack->Data.Size;
    if ( v7 < Size )
      break;
    v16 = &p_Registers->Data.Data[v14];
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &p_ScopeStack->Data,
      p_ScopeStack->Data.pHeap,
      Size + 1);
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
      &p_ScopeStack->Data.Data[p_ScopeStack->Data.Size - 1].Flags,
      v16);
LABEL_21:
    from = v18;
    v10 = this;
    ++v7;
    ++v14;
    if ( v7 >= p_Registers->Data.Size )
      goto LABEL_22;
  }
  if ( Scaleform::GFx::AS3::Tracer::MergeValues(v10, (Scaleform::GFx::AS3::CheckResult *)&check_size, v7, to, from, v6)->Result )
    goto LABEL_21;
  result->Result = 0;
  return result;
}

// File Line: 5977
// RVA: 0x7F58D0
void __fastcall Scaleform::GFx::AS3::Tracer::InitializeBlock(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::TR::Block *to,
        Scaleform::GFx::AS3::TR::Block *from)
{
  Scaleform::GFx::AS3::TR::State *State; // rbx
  Scaleform::GFx::AS3::TR::State *v4; // rdi
  Scaleform::GFx::AS3::CheckResult result; // [rsp+48h] [rbp+10h] BYREF

  State = from->State;
  v4 = to->State;
  to->CurOpStackSize = from->CurOpStackSize;
  Scaleform::GFx::AS3::Tracer::MergeLists(this, &result, v4, State, 0, msOpStack);
  Scaleform::GFx::AS3::Tracer::MergeLists(this, &result, v4, State, 0, msScopeStack);
  Scaleform::GFx::AS3::Tracer::MergeLists(this, &result, v4, State, 1, msRegisterFile);
  *((_DWORD *)to + 4) |= 1u;
}

// File Line: 5992
// RVA: 0x800E40
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Tracer::MergeBlock(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::TR::Block *to,
        Scaleform::GFx::AS3::TR::Block *from)
{
  Scaleform::GFx::AS3::TR::State *State; // rsi
  Scaleform::GFx::AS3::TR::State *v7; // rbp
  unsigned __int64 CurOpStackSize; // rcx
  Scaleform::GFx::AS3::VM *VMRef; // rbx
  Scaleform::GFx::AS3::VM::Error *v10; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v14; // [rsp+38h] [rbp-20h] BYREF
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+70h] [rbp+18h] BYREF

  State = from->State;
  v7 = to->State;
  if ( (to->Type & 4) != 0 || (to->Type & 1) != 0 )
    goto LABEL_9;
  CurOpStackSize = from->CurOpStackSize;
  if ( CurOpStackSize < to->CurOpStackSize )
    CurOpStackSize = to->CurOpStackSize;
  to->CurOpStackSize = CurOpStackSize;
  Scaleform::GFx::AS3::Tracer::MergeLists(this, &resulta, v7, State, 1, msOpStack);
  if ( Scaleform::GFx::AS3::Tracer::MergeLists(this, &resulta, v7, State, 0, msScopeStack)->Result )
  {
LABEL_9:
    Scaleform::GFx::AS3::Tracer::MergeLists(this, result, v7, State, 1, msRegisterFile);
  }
  else
  {
    VMRef = this->CF->pFile->VMRef;
    Scaleform::GFx::AS3::VM::Error::Error(&v14, 1031, VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(VMRef, v10, &Scaleform::GFx::AS3::fl::VerifyErrorTI);
    pNode = v14.Message.pNode;
    if ( v14.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    result->Result = 0;
  }
  return result;
}

// File Line: 6044
// RVA: 0x823530
Scaleform::GFx::AS3::Tracer::SubstituteOpCode

// File Line: 6860
// RVA: 0x823180
char __fastcall Scaleform::GFx::AS3::Tracer::SubstituteGetlocal(
        Scaleform::GFx::AS3::Tracer *this,
        unsigned __int64 *bcp,
        unsigned __int64 ccp,
        Scaleform::GFx::AS3::TR::State *st,
        unsigned int src_reg_num)
{
  unsigned __int64 v7; // r14
  int v8; // ebp
  __int64 v9; // rcx
  unsigned __int64 Size; // rax
  unsigned __int64 v11; // rbx
  unsigned __int64 v12; // r8
  unsigned __int64 *Data; // rax
  int v14; // r10d
  const char *pCode; // r8
  unsigned __int64 v16; // r14
  int v17; // ecx
  int TraitsType; // ebx
  int v19; // r12d
  int v20; // r13d
  unsigned __int64 v21; // rax
  unsigned __int64 v22; // r13
  unsigned __int64 v23; // r8
  unsigned __int64 *v24; // rax
  int v25; // ecx
  int v26; // ecx
  int v27; // ecx
  int v28; // ecx
  char v30; // al
  unsigned int v31; // ecx
  char v32; // dl
  int v33; // eax
  int v34; // r8d
  Scaleform::GFx::AS3::Traits *ValueTraits; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *ITr; // rdx
  Scaleform::GFx::AS3::VM *VMRef; // rax
  int v38; // ebp
  int v39; // ebp
  int v40; // ebp
  int v41; // ebx
  int v42; // ebx
  Scaleform::GFx::AS3::Abc::Code::OpCode v43; // edx
  Scaleform::GFx::AS3::Abc::Code::OpCode v44; // edx
  Scaleform::GFx::AS3::Abc::Code::OpCode v45; // edx
  int v46; // ebx
  int v47; // ebx
  Scaleform::GFx::AS3::InstanceTraits::Traits **pObject; // r8
  int v49; // [rsp+60h] [rbp+8h]
  Scaleform::GFx::AS3::Value *v; // [rsp+70h] [rbp+18h]

  v7 = ccp + 1;
  v = &st->Registers.Data.Data[src_reg_num];
  v8 = (unsigned __int8)this->pCode[ccp];
  if ( (unsigned int)(v8 - 145) > 0x30 )
    return 0;
  v9 = 0x1800000000005i64;
  if ( !_bittest64(&v9, v8 - 145) )
    return 0;
  Size = this->OrigOpcodePos.Data.Size;
  v11 = Size + 1;
  if ( Size + 1 >= Size )
  {
    if ( v11 <= this->OrigOpcodePos.Data.Policy.Capacity )
      goto LABEL_9;
    v12 = v11 + (v11 >> 2);
  }
  else
  {
    if ( v11 >= this->OrigOpcodePos.Data.Policy.Capacity >> 1 )
      goto LABEL_9;
    v12 = Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
    &this->OrigOpcodePos.Data,
    (__int64 *)this->OrigOpcodePos.Data.pHeap,
    v12);
LABEL_9:
  Data = this->OrigOpcodePos.Data.Data;
  this->OrigOpcodePos.Data.Size = v11;
  v14 = 1;
  Data[v11 - 1] = v7;
  pCode = this->pCode;
  v16 = v7 + 1;
  v17 = (unsigned __int8)pCode[v16 - 1];
  TraitsType = 4;
  v19 = 3;
  if ( v17 == 115 )
  {
    v49 = 2;
  }
  else if ( pCode[v16 - 1] == 116 )
  {
    v49 = 3;
  }
  else
  {
    if ( pCode[v16 - 1] != 117 )
    {
      v20 = 4;
      if ( (unsigned int)(v8 - 192) <= 1 )
        v20 = 2;
      goto LABEL_25;
    }
    v49 = 4;
  }
  v21 = this->OrigOpcodePos.Data.Size;
  v22 = v21 + 1;
  if ( v21 + 1 >= v21 )
  {
    if ( v22 > this->OrigOpcodePos.Data.Policy.Capacity )
    {
      v23 = v22 + (v22 >> 2);
      goto LABEL_23;
    }
  }
  else if ( v22 < this->OrigOpcodePos.Data.Policy.Capacity >> 1 )
  {
    v23 = v21 + 1;
LABEL_23:
    Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &this->OrigOpcodePos.Data,
      (__int64 *)this->OrigOpcodePos.Data.pHeap,
      v23);
  }
  v24 = this->OrigOpcodePos.Data.Data;
  this->OrigOpcodePos.Data.Size = v22;
  v14 = 2;
  v24[v22 - 1] = v16;
  pCode = this->pCode;
  v20 = v49;
  v17 = (unsigned __int8)pCode[v16++];
LABEL_25:
  v25 = v17 - 99;
  if ( v25 )
  {
    v26 = v25 - 113;
    if ( v26 )
    {
      v27 = v26 - 1;
      if ( v27 )
      {
        v28 = v27 - 1;
        if ( v28 )
        {
          if ( v28 != 1 )
          {
LABEL_30:
            Scaleform::ArrayDataDH<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy>::Resize(
              &this->OrigOpcodePos.Data,
              this->OrigOpcodePos.Data.Size - v14);
            return 0;
          }
        }
        else
        {
          v19 = 2;
        }
      }
      else
      {
        v19 = 1;
      }
    }
    else
    {
      v19 = 0;
    }
  }
  else
  {
    v30 = pCode[v16++];
    v31 = 7;
    v19 = v30 & 0x7F;
    if ( v30 < 0 )
    {
      do
      {
        if ( v31 >= 0x20 )
          break;
        v32 = pCode[v16++];
        v33 = (v32 & 0x7F) << v31;
        v31 += 7;
        v19 |= v33;
      }
      while ( v32 < 0 );
    }
  }
  v34 = src_reg_num;
  if ( v19 != src_reg_num )
    goto LABEL_30;
  if ( (v->Flags & 0x1F) != 0 )
  {
    if ( (v->Flags & 0x1F) - 8 < 2 )
    {
      ITr = v->value.VS._1.ITr;
    }
    else
    {
      ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(this->CF->pFile->VMRef, v);
      v34 = src_reg_num;
      ITr = (Scaleform::GFx::AS3::InstanceTraits::Traits *)ValueTraits;
    }
  }
  else
  {
    ITr = this->CF->pFile->VMRef->TraitsVoid.pObject;
  }
  if ( ITr )
  {
    VMRef = this->CF->pFile->VMRef;
    if ( ITr == (Scaleform::GFx::AS3::InstanceTraits::Traits *)VMRef->TraitsClassClass.pObject )
      ITr = (Scaleform::GFx::AS3::InstanceTraits::Traits *)VMRef->TraitsObject.pObject;
    if ( ITr )
    {
      if ( (ITr->Flags & 0x20) == 0 )
        TraitsType = ITr->TraitsType;
    }
  }
  v38 = v8 - 145;
  if ( !v38 )
    goto LABEL_63;
  v39 = v38 - 2;
  if ( !v39 )
    goto LABEL_54;
  v40 = v39 - 45;
  if ( !v40 )
  {
LABEL_63:
    if ( TraitsType == v20 )
    {
      v46 = TraitsType - 2;
      if ( !v46 )
      {
        v45 = op_inclocal_ti;
        goto LABEL_74;
      }
      v47 = v46 - 1;
      if ( !v47 )
      {
        v44 = op_inclocal_tu;
        goto LABEL_72;
      }
      if ( v47 != 1 )
        goto LABEL_70;
    }
    else if ( v20 == 2 )
    {
      v45 = op_inclocal_i;
      goto LABEL_74;
    }
    v43 = op_inclocal;
    goto LABEL_68;
  }
  if ( v40 != 1 )
    return 0;
LABEL_54:
  if ( TraitsType != v20 )
  {
    if ( v20 != 2 )
      goto LABEL_58;
    v45 = op_declocal_i;
LABEL_74:
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, v45, v34);
    pObject = (Scaleform::GFx::AS3::InstanceTraits::Traits **)st->pTracer->CF->pFile->VMRef->TraitsInt.pObject;
    goto LABEL_69;
  }
  v41 = TraitsType - 2;
  if ( !v41 )
  {
    v45 = op_declocal_ti;
    goto LABEL_74;
  }
  v42 = v41 - 1;
  if ( !v42 )
  {
    v44 = op_declocal_tu;
LABEL_72:
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, v44, v34);
    pObject = (Scaleform::GFx::AS3::InstanceTraits::Traits **)st->pTracer->CF->pFile->VMRef->TraitsUint.pObject;
    goto LABEL_69;
  }
  if ( v42 == 1 )
  {
LABEL_58:
    v43 = op_declocal;
LABEL_68:
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, v43, v34);
    pObject = (Scaleform::GFx::AS3::InstanceTraits::Traits **)st->pTracer->CF->pFile->VMRef->TraitsNumber.pObject;
LABEL_69:
    Scaleform::GFx::AS3::TR::State::ConvertRegisterTo(
      st,
      (Scaleform::GFx::AS3::AbsoluteIndex)src_reg_num,
      pObject[25],
      NotNull);
  }
LABEL_70:
  Scaleform::GFx::AS3::Tracer::SkipOrigOpCode(this, bcp, v16);
  return 1;
}

// File Line: 7139
// RVA: 0x7C8AD0
void __fastcall Scaleform::GFx::AS3::Tracer::EmitPopPrevResult(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::TR::State *st)
{
  unsigned __int64 Size; // r8
  int v4; // eax
  Scaleform::ArrayDH_POD<unsigned __int64,328,Scaleform::ArrayDefaultPolicy> *p_NewOpcodePos; // rcx
  unsigned __int64 v6; // rdx
  unsigned __int64 v7; // rbx

  Size = this->NewOpcodePos.Data.Size;
  if ( Size )
    v4 = this->MI->OpCode.Data.Data[this->NewOpcodePos.Data.Data[Size - 1]];
  else
    v4 = 2;
  switch ( v4 )
  {
    case 32:
    case 33:
    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
    case 42:
    case 44:
    case 45:
    case 46:
    case 47:
    case 49:
    case 96:
    case 98:
    case 100:
    case 101:
    case 103:
    case 110:
    case 181:
    case 208:
    case 209:
    case 210:
    case 211:
      p_NewOpcodePos = &this->NewOpcodePos;
      v6 = this->NewOpcodePos.Data.Size;
      v7 = p_NewOpcodePos->Data.Data[v6 - 1];
      Scaleform::ArrayDataDH<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy>::Resize(
        &p_NewOpcodePos->Data,
        v6 - 1);
      Scaleform::ArrayData<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy>::Resize(
        &this->MI->OpCode.Data,
        v7);
      break;
    default:
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_pop);
      break;
  }
}

// File Line: 7201
// RVA: 0x7C7D50
char __fastcall Scaleform::GFx::AS3::Tracer::EmitGetClassTraits(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::TR::State *st,
        Scaleform::GFx::AS3::Multiname *as3_mn,
        bool objOnStack)
{
  Scaleform::GFx::AS3::ClassTraits::Traits *ClassTraits; // rax
  Scaleform::GFx::AS3::Value::V1U v8; // r14
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // rbx
  Scaleform::GFx::AS3::Value::V1U v10; // r14
  unsigned int v11; // esi
  Scaleform::GFx::AS3::TR::State *v12; // rbx
  Scaleform::GFx::AS3::VMAbcFile *pFile; // rcx
  __int64 v14; // rcx
  __int64 v15; // rdx
  bool v16; // zf
  Scaleform::GFx::AS3::Object *v17; // rdx
  Scaleform::GFx::AS3::Value::V2U v18; // r8
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *GlobalObjectScript; // r12
  unsigned int v21; // esi
  Scaleform::GFx::AS3::TR::State *v22; // rbx
  __int64 v23; // r8
  Scaleform::GFx::AS3::Value::V2U v24; // rdx
  Scaleform::GFx::AS3::Value v25; // [rsp+18h] [rbp-29h] BYREF
  Scaleform::GFx::AS3::Value value; // [rsp+38h] [rbp-9h] BYREF
  Scaleform::GFx::AS3::Object *key; // [rsp+A0h] [rbp+5Fh] BYREF
  Scaleform::GFx::AS3::TR::State *sta; // [rsp+A8h] [rbp+67h]
  char v29; // [rsp+C0h] [rbp+7Fh]

  ClassTraits = Scaleform::GFx::AS3::FindClassTraits(this->CF->pFile->VMRef, as3_mn, this->CF->pFile->AppDomain.pObject);
  v8.VStr = (Scaleform::GFx::ASStringNode *)ClassTraits;
  if ( ClassTraits )
  {
    pObject = ClassTraits->ITraits.pObject;
    if ( pObject )
    {
      if ( pObject->pConstructor.pObject )
      {
        v10 = (Scaleform::GFx::AS3::Value::V1U)pObject->pConstructor.pObject;
        v11 = 13;
        v25.Flags = 13;
        v25.Bonus.pWeakProxy = 0i64;
        v25.value.VS._1 = v10;
        if ( v10.VStr )
          v10.VStr->Size = (v10.VStr->Size + 1) & 0x8FBFFFFF;
        v12 = sta;
        if ( objOnStack )
          Scaleform::GFx::AS3::Tracer::EmitPopPrevResult(this, sta);
        Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_getabsobject, (unsigned __int64)&v10.VStr->pData + 2);
        pFile = this->CF->pFile;
        if ( v10.VStr != (Scaleform::GFx::ASStringNode *)pFile->VMRef->GlobalObject.pObject )
        {
          key = (Scaleform::GFx::AS3::Object *)v10.VStr;
          Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>>>>::Set<Scaleform::GFx::AS3::Object *>(
            &pFile->AbsObjects,
            &pFile->AbsObjects,
            (Scaleform::GFx::AS3::Instances::fl::XMLList **)&key);
        }
        if ( v29 )
          v11 = 1037;
        v25.Flags = v11;
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          &v12->OpStack.Data,
          v12->OpStack.Data.pHeap,
          v12->OpStack.Data.Size + 1);
        v14 = 32 * v12->OpStack.Data.Size;
        v15 = (__int64)&v12->OpStack.Data.Data[-1];
        v16 = v14 + v15 == 0;
        v17 = (Scaleform::GFx::AS3::Object *)(v14 + v15);
        key = v17;
        if ( !v16 )
        {
          LODWORD(v17->vfptr) = v11;
          v17->pRCCRaw = 0i64;
          v17->pNext = v10.VObj;
          v18.VObj = (Scaleform::GFx::AS3::Object *)v25.value.VS._2;
          v17->pPrev = v25.value.VS._2.VObj;
          if ( (v11 & 0x1F) > 9 )
          {
            if ( (v11 & 0x1F) == 10 )
            {
              ++v10.VStr->RefCount;
            }
            else if ( (v11 & 0x1F) > 0xA )
            {
              if ( (v11 & 0x1F) <= 0xF )
              {
                if ( v10.VStr )
                  v10.VStr->Size = (v10.VStr->Size + 1) & 0x8FBFFFFF;
              }
              else if ( (v11 & 0x1F) <= 0x11 )
              {
                if ( v18.VObj )
                  v18.VObj->RefCount = (v18.VObj->RefCount + 1) & 0x8FBFFFFF;
              }
            }
          }
        }
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v25);
LABEL_24:
        Scaleform::GFx::AS3::Multiname::~Multiname(as3_mn);
        return 1;
      }
      if ( (pObject->Flags & 0x10) != 0 )
      {
        GlobalObjectScript = Scaleform::GFx::AS3::InstanceTraits::UserDefined::GetGlobalObjectScript((Scaleform::GFx::AS3::InstanceTraits::UserDefined *)pObject);
        key = 0i64;
        if ( Scaleform::GFx::AS3::FindFixedSlot(
               this->CF->pFile->VMRef,
               GlobalObjectScript->pTraits.pObject,
               as3_mn,
               (unsigned __int64 *)&key,
               GlobalObjectScript) )
        {
          v25.Bonus.pWeakProxy = 0i64;
          v25.value.VS._1 = v8;
          v21 = 73;
          v25.Flags = 73;
          if ( v29 )
            v21 = 1097;
          v25.Flags = v21;
          v22 = sta;
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
            &sta->OpStack.Data,
            sta->OpStack.Data.pHeap,
            sta->OpStack.Data.Size + 1);
          v23 = (__int64)&v22->OpStack.Data.Data[v22->OpStack.Data.Size - 1];
          if ( v23 )
          {
            *(_DWORD *)v23 = v21;
            *(_QWORD *)(v23 + 8) = 0i64;
            *(Scaleform::GFx::AS3::Value::V1U *)(v23 + 16) = v8;
            v24.VObj = (Scaleform::GFx::AS3::Object *)v25.value.VS._2;
            *(_QWORD *)(v23 + 24) = v25.value.VS._2.VObj;
            if ( (v21 & 0x1F) > 9 )
            {
              if ( (v21 & 0x1F) == 10 )
              {
                ++v8.VStr->RefCount;
              }
              else if ( (v21 & 0x1F) > 0xA )
              {
                if ( (v21 & 0x1F) <= 0xF )
                {
                  v8.VStr->Size = (v8.VStr->Size + 1) & 0x8FBFFFFF;
                }
                else if ( (v21 & 0x1F) <= 0x11 && v24.VObj )
                {
                  v24.VObj->RefCount = (v24.VObj->RefCount + 1) & 0x8FBFFFFF;
                }
              }
            }
          }
          value.Flags = 12;
          value.Bonus.pWeakProxy = 0i64;
          value.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)GlobalObjectScript;
          GlobalObjectScript->RefCount = (GlobalObjectScript->RefCount + 1) & 0x8FBFFFFF;
          Scaleform::GFx::AS3::Tracer::EmitGetAbsObject(this, sta, &value, 0);
          Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
          Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_getabsslot, (unsigned int)((_DWORD)key + 1));
          goto LABEL_24;
        }
      }
    }
  }
  Scaleform::GFx::AS3::Multiname::~Multiname(as3_mn);
  return 0;
}

// File Line: 7281
// RVA: 0x7C6F40
_BOOL8 __fastcall Scaleform::GFx::AS3::Tracer::EmitFindProperty(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::TR::State *st,
        const int mn_index,
        bool get_prop,
        Scaleform::GFx::AS3::Abc::Code::OpCode consumer)
{
  char Flags; // r13
  int v9; // ebx
  bool v10; // di
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *VStr; // r12
  Scaleform::GFx::AS3::InstanceTraits::Traits *ITr; // r14
  Scaleform::GFx::AS3::VM *VMRef; // rax
  Scaleform::GFx::AS3::TR::State::ScopeType v14; // ebx
  Scaleform::GFx::AS3::Multiname *v15; // rax
  bool Slot; // bl
  Scaleform::GFx::AS3::SlotInfo *v17; // rbx
  unsigned int v18; // eax
  int pNode; // r13d
  const char *pData; // r12
  unsigned int v21; // ebx
  unsigned int v22; // r14d
  int v23; // edi
  __int64 v24; // rcx
  char v25; // al
  Scaleform::GFx::AS3::Abc::Code::OpCode v26; // edx
  Scaleform::GFx::AS3::Value *Undefined; // rdx
  unsigned int v28; // edi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rsi
  Scaleform::GFx::AS3::Value::V1U VObj; // rcx
  Scaleform::GFx::AS3::Value *p_v; // rdx
  Scaleform::GFx::AS3::WeakProxy *v32; // r12
  long double v33; // xmm0_8
  bool v34; // zf
  Scaleform::GFx::ASStringNode *v35; // rcx
  Scaleform::GFx::ASStringNode *v36; // rcx
  Scaleform::GFx::AS3::InstanceTraits::Traits *ValueTraits; // r8
  Scaleform::GFx::AS3::VM *v38; // rax
  unsigned int v39; // ebx
  unsigned int v40; // edi
  unsigned __int64 Size; // rcx
  Scaleform::GFx::AS3::Value *v42; // r9
  Scaleform::GFx::AS3::SlotInfo *v43; // r9
  Scaleform::GFx::AS3::WeakProxy *v44; // rdx
  Scaleform::GFx::AS3::Value::V1U v45; // r8
  Scaleform::GFx::AS3::Value::V2U v46; // r10
  Scaleform::GFx::AS3::Multiname *v47; // rax
  Scaleform::GFx::AS3::Tracer *v48; // rcx
  Scaleform::GFx::AS3::Abc::Code::OpCode v49; // edx
  Scaleform::GFx::AS3::SlotInfo *v50; // rbx
  __int64 v51; // rdx
  int v52; // ecx
  __int64 v53; // rbx
  Scaleform::GFx::AS3::VTable *VT; // rax
  Scaleform::GFx::AS3::Value *Value; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *FunctType; // rdi
  __int64 v57; // rbx
  Scaleform::GFx::AS3::VTable *v58; // rax
  Scaleform::GFx::AS3::Value *v59; // rdi
  Scaleform::GFx::AS3::VM *v60; // rbx
  Scaleform::GFx::AS3::VMAppDomain *AppDomain; // rax
  int CanBeNull; // eax
  unsigned int v63; // ebx
  unsigned int v64; // edi
  unsigned __int64 v65; // rcx
  Scaleform::GFx::AS3::Value *v66; // r9
  unsigned __int64 v67; // r9
  Scaleform::GFx::AS3::WeakProxy *v68; // rdx
  Scaleform::GFx::AS3::Value::V1U v69; // r8
  Scaleform::GFx::AS3::Value::V2U v70; // r10
  Scaleform::GFx::AS3::Multiname *v71; // rax
  Scaleform::GFx::AS3::GASRefCountBase *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Value type; // [rsp+30h] [rbp-D0h] BYREF
  Scaleform::GFx::ASString v76; // [rsp+50h] [rbp-B0h] BYREF
  unsigned int v77; // [rsp+58h] [rbp-A8h]
  Scaleform::GFx::AS3::Value v; // [rsp+60h] [rbp-A0h] BYREF
  unsigned __int64 arg1; // [rsp+80h] [rbp-80h] BYREF
  Scaleform::GFx::AS3::SlotInfo *pSI; // [rsp+88h] [rbp-78h]
  Scaleform::GFx::AS3::PropRef result; // [rsp+90h] [rbp-70h] BYREF
  Scaleform::GFx::AS3::Multiname mn; // [rsp+C0h] [rbp-40h] BYREF
  Scaleform::GFx::AS3::Value v83; // [rsp+F0h] [rbp-10h] BYREF
  Scaleform::GFx::AS3::Value v84; // [rsp+110h] [rbp+10h] BYREF
  Scaleform::GFx::AS3::Value p; // [rsp+130h] [rbp+30h] BYREF
  Scaleform::GFx::AS3::Value v86; // [rsp+160h] [rbp+60h] BYREF
  Scaleform::GFx::AS3::Value::VU *p_value; // [rsp+1E0h] [rbp+E0h] BYREF
  Scaleform::GFx::AS3::TR::State::ScopeType stype; // [rsp+1F0h] [rbp+F0h] BYREF
  bool v89; // [rsp+1F8h] [rbp+F8h]

  v89 = get_prop;
  p.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)-2i64;
  v77 = 0;
  Scaleform::GFx::AS3::Multiname::Multiname(
    &mn,
    this->CF->pFile,
    &this->CF->pFile->File.pObject->Const_Pool.const_multiname.Data.Data[mn_index]);
  arg1 = 0i64;
  if ( (mn.Kind & 3) == 1 || (mn.Kind & 4) != 0 )
  {
    Slot = 0;
    goto LABEL_190;
  }
  memset(&result, 0, 20);
  result.This.Bonus.pWeakProxy = 0i64;
  Scaleform::GFx::AS3::TR::State::FindProp(st, &result, &mn, &stype, &arg1);
  Flags = result.This.Flags;
  v9 = result.This.Flags & 0x1F;
  if ( (result.This.Flags & 0x1F) == 0
    || (pSI = result.pSI, ((__int64)result.pSI & 1) != 0)
    && ((unsigned __int64)result.pSI & 0xFFFFFFFFFFFFFFFEui64) == 0
    || ((__int64)result.pSI & 2) != 0 && ((unsigned __int64)result.pSI & 0xFFFFFFFFFFFFFFFDui64) == 0 )
  {
    if ( get_prop )
    {
      p_value = &p.value;
      Scaleform::GFx::AS3::Multiname::Multiname((Scaleform::GFx::AS3::Multiname *)&p.value, &mn);
      if ( Scaleform::GFx::AS3::Tracer::EmitGetClassTraits(this, st, v71, 0, 0) )
      {
        Slot = 1;
        goto LABEL_183;
      }
    }
    goto LABEL_182;
  }
  if ( ((__int64)result.pSI & 1) != 0 )
    goto LABEL_182;
  v76.pNode = (Scaleform::GFx::ASStringNode *)result.SlotIndex;
  v10 = consumer != op_setproperty && consumer != op_initproperty && Scaleform::GFx::AS3::SlotInfo::IsClass(result.pSI);
  VStr = (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *)result.This.value.VS._1.VStr;
  if ( v9 )
  {
    if ( (unsigned int)(v9 - 8) < 2 )
      ITr = result.This.value.VS._1.ITr;
    else
      ITr = (Scaleform::GFx::AS3::InstanceTraits::Traits *)Scaleform::GFx::AS3::VM::GetValueTraits(
                                                             this->CF->pFile->VMRef,
                                                             &result.This);
  }
  else
  {
    ITr = this->CF->pFile->VMRef->TraitsVoid.pObject;
  }
  if ( ITr )
  {
    VMRef = this->CF->pFile->VMRef;
    if ( ITr == (Scaleform::GFx::AS3::InstanceTraits::Traits *)VMRef->TraitsClassClass.pObject )
      ITr = (Scaleform::GFx::AS3::InstanceTraits::Traits *)VMRef->TraitsObject.pObject;
  }
  v14 = stype;
  if ( stype < stScopeStack )
  {
LABEL_182:
    Slot = 0;
    goto LABEL_183;
  }
  if ( stype > stStoredScope )
  {
    if ( stype != stGlobalObject )
      goto LABEL_182;
    if ( v10 )
    {
      arg1 = (unsigned __int64)&v86.value;
      Scaleform::GFx::AS3::Multiname::Multiname((Scaleform::GFx::AS3::Multiname *)&v86.value, &mn);
      if ( Scaleform::GFx::AS3::Tracer::EmitGetClassTraits(this, st, v15, 0, v10) )
      {
        Slot = 1;
        goto LABEL_183;
      }
      VStr = (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *)result.This.value.VS._1.VStr;
      Flags = result.This.Flags;
    }
    if ( !v89 )
    {
      Slot = Scaleform::GFx::AS3::Tracer::EmitGetSlot(this, st, &result.This, (const unsigned __int64)v76.pNode, 0);
      if ( Slot )
        Scaleform::GFx::AS3::TR::State::PushOp(st, &result.This);
      goto LABEL_183;
    }
    v17 = pSI;
    if ( (int)((*(_DWORD *)pSI & 0xFFFFFC00) << 17) > 1342177280 )
      goto LABEL_182;
    v18 = (Flags & 0x1F) - 12;
    pNode = (int)v76.pNode;
    if ( v18 <= 3 && VStr == this->CF->pFile->VMRef->GlobalObject.pObject )
    {
      Scaleform::GFx::AS3::Slots::GetSlotName(
        &ITr->Scaleform::GFx::AS3::Slots,
        &v76,
        (Scaleform::GFx::AS3::AbsoluteIndex)v76.pNode);
      pData = v76.pNode->pData;
      v21 = 4;
      v22 = 1;
      if ( !strcmp(v76.pNode->pData, "undefined") )
      {
        v23 = 1;
LABEL_39:
        v26 = op_pushnan;
        if ( v23 == 1 )
          v26 = op_pushundefined;
        Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, v26);
        if ( v23 != 1 )
        {
          v33 = Scaleform::GFx::NumberUtil::NaN();
          v.Flags = 4;
          v32 = 0i64;
          v.Bonus.pWeakProxy = 0i64;
          v.value.VNumber = v33;
          p_v = &v;
          v22 = 2;
          v77 = 2;
          pWeakProxy = type.Bonus.pWeakProxy;
          v28 = type.Flags;
LABEL_56:
          Scaleform::GFx::AS3::TR::State::PushOp(st, p_v);
          if ( (v22 & 2) != 0 )
          {
            v22 &= ~2u;
            v77 = v22;
            if ( (v21 & 0x1F) > 9 )
            {
              if ( (v21 & 0x200) != 0 )
              {
                v34 = v32->RefCount-- == 1;
                if ( v34 )
                  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v32);
                memset(&v.Bonus, 0, 24);
                v.Flags = v21 & 0xFFFFFDE0;
              }
              else
              {
                Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
              }
            }
          }
          if ( (v22 & 1) != 0 )
          {
            v77 = v22 & 0xFFFFFFFE;
            if ( (v28 & 0x1F) > 9 )
            {
              if ( (v28 & 0x200) != 0 )
              {
                v34 = pWeakProxy->RefCount-- == 1;
                if ( v34 )
                  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
                memset(&type.Bonus, 0, 24);
                type.Flags = v28 & 0xFFFFFDE0;
              }
              else
              {
                Scaleform::GFx::AS3::Value::ReleaseInternal(&type);
              }
            }
          }
          v35 = v76.pNode;
          v34 = v76.pNode->RefCount-- == 1;
          if ( v34 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v35);
          goto LABEL_72;
        }
        Undefined = Scaleform::GFx::AS3::Value::GetUndefined();
        v28 = Undefined->Flags;
        type.Flags = v28;
        pWeakProxy = Undefined->Bonus.pWeakProxy;
        type.Bonus.pWeakProxy = pWeakProxy;
        type.value = Undefined->value;
        if ( (v28 & 0x1F) > 9 )
        {
          if ( (v28 & 0x200) != 0 )
          {
            ++pWeakProxy->RefCount;
          }
          else
          {
            if ( (v28 & 0x1F) == 10 )
            {
              ++Undefined->value.VS._1.VStr->RefCount;
              goto LABEL_54;
            }
            if ( (v28 & 0x1F) > 0xA )
            {
              if ( (v28 & 0x1F) <= 0xF )
              {
                VObj = Undefined->value.VS._1;
              }
              else
              {
                if ( (v28 & 0x1F) > 0x11 )
                  goto LABEL_54;
                VObj = (Scaleform::GFx::AS3::Value::V1U)Undefined->value.VS._2.VObj;
              }
              if ( VObj.VStr )
                VObj.VStr->Size = (VObj.VStr->Size + 1) & 0x8FBFFFFF;
            }
          }
        }
LABEL_54:
        p_v = &type;
        v77 = 1;
        v32 = v.Bonus.pWeakProxy;
        v21 = v.Flags;
        goto LABEL_56;
      }
      v24 = 0i64;
      while ( 1 )
      {
        v25 = pData[v24++];
        if ( v25 != aNan_1[v24 - 1] )
          break;
        if ( v24 == 4 )
        {
          v23 = 2;
          goto LABEL_39;
        }
      }
      v36 = v76.pNode;
      v34 = v76.pNode->RefCount-- == 1;
      if ( v34 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v36);
      v17 = pSI;
    }
    if ( !Scaleform::GFx::AS3::Tracer::EmitGetAbsObject(this, st, &result.This, 0) )
      goto LABEL_182;
    type.Flags = 0;
    type.Bonus.pWeakProxy = 0i64;
    if ( (result.This.Flags & 0x1F) != 0 )
    {
      if ( (result.This.Flags & 0x1F) - 8 < 2 )
        ValueTraits = result.This.value.VS._1.ITr;
      else
        ValueTraits = (Scaleform::GFx::AS3::InstanceTraits::Traits *)Scaleform::GFx::AS3::VM::GetValueTraits(
                                                                       this->CF->pFile->VMRef,
                                                                       &result.This);
    }
    else
    {
      ValueTraits = this->CF->pFile->VMRef->TraitsVoid.pObject;
    }
    if ( ValueTraits )
    {
      v38 = this->CF->pFile->VMRef;
      if ( ValueTraits == (Scaleform::GFx::AS3::InstanceTraits::Traits *)v38->TraitsClassClass.pObject )
        ValueTraits = (Scaleform::GFx::AS3::InstanceTraits::Traits *)v38->TraitsObject.pObject;
    }
    if ( Scaleform::GFx::AS3::TR::State::GetPropertyType(
           st,
           (Scaleform::GFx::AS3::CheckResult *)&stype,
           ValueTraits,
           v17,
           &type)->Result )
    {
      v34 = !v10;
      v40 = type.Flags;
      if ( !v34 )
      {
        v40 = type.Flags | 0x400;
        type.Flags |= 0x400u;
      }
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        &st->OpStack.Data,
        st->OpStack.Data.pHeap,
        st->OpStack.Data.Size + 1);
      Size = st->OpStack.Data.Size;
      v42 = st->OpStack.Data.Data - 1;
      v34 = &v42[Size] == 0i64;
      v43 = (Scaleform::GFx::AS3::SlotInfo *)&v42[Size];
      arg1 = (unsigned __int64)v43;
      pSI = v43;
      v44 = type.Bonus.pWeakProxy;
      if ( !v34 )
      {
        *(_DWORD *)v43 = v40;
        v43->pNs.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)v44;
        v45 = type.value.VS._1;
        v43->CTraits.pObject = type.value.VS._1.CTr;
        v46.VObj = (Scaleform::GFx::AS3::Object *)type.value.VS._2;
        v43->File.pObject = (Scaleform::GFx::AS3::VMAbcFile *)type.value.VS._2.VObj;
        if ( (v40 & 0x1F) > 9 )
        {
          if ( (v40 & 0x200) != 0 )
          {
            ++v44->RefCount;
          }
          else if ( (v40 & 0x1F) == 10 )
          {
            ++v45.VStr->RefCount;
          }
          else if ( (v40 & 0x1F) > 0xA )
          {
            if ( (v40 & 0x1F) <= 0xF )
            {
              if ( v45.VStr )
                v45.VStr->Size = (v45.VStr->Size + 1) & 0x8FBFFFFF;
            }
            else if ( (v40 & 0x1F) <= 0x11 && v46.VObj )
            {
              v46.VObj->RefCount = (v46.VObj->RefCount + 1) & 0x8FBFFFFF;
            }
          }
        }
      }
      if ( (v40 & 0x1F) > 9 )
      {
        if ( (v40 & 0x200) != 0 )
        {
          v34 = v44->RefCount-- == 1;
          if ( v34 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&type.Bonus, 0, 24);
          type.Flags = v40 & 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&type);
        }
      }
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_getabsslot, (unsigned int)(pNode + 1));
      Slot = 1;
      goto LABEL_183;
    }
    v39 = type.Flags;
    if ( (type.Flags & 0x1F) <= 9 )
      goto LABEL_182;
    if ( (type.Flags & 0x200) != 0 )
    {
      v34 = type.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v34 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
LABEL_90:
      memset(&type.Bonus, 0, 24);
      type.Flags = v39 & 0xFFFFFDE0;
      goto LABEL_182;
    }
    goto LABEL_91;
  }
  if ( v10 )
  {
    *(_QWORD *)&p.Flags = &p.value;
    Scaleform::GFx::AS3::Multiname::Multiname((Scaleform::GFx::AS3::Multiname *)&p.value, &mn);
    if ( Scaleform::GFx::AS3::Tracer::EmitGetClassTraits(this, st, v47, 0, v10) )
    {
      Slot = 1;
      goto LABEL_183;
    }
  }
  if ( !Scaleform::GFx::AS3::Tracer::EmitGetAbsObject(this, st, &result.This, 0) )
  {
    v48 = this;
    if ( v14 )
    {
      if ( Scaleform::GFx::AS3::Tracer::EmitGetAbsObject(this, st, &result.This, 0) )
        goto LABEL_125;
      v49 = op_getouterscope;
      v48 = this;
    }
    else
    {
      v49 = op_getscopeobject;
    }
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(v48, v49, arg1);
  }
LABEL_125:
  if ( !v89 )
  {
    if ( consumer != op_constructprop )
    {
      Scaleform::GFx::AS3::TR::State::PushOp(st, &result.This);
LABEL_72:
      Slot = 1;
      goto LABEL_183;
    }
    v10 = 1;
  }
  v50 = pSI;
  v51 = *(_DWORD *)pSI;
  v52 = (int)(*(_DWORD *)pSI << 17) >> 27;
  if ( v52 <= 10 || v51 >> 15 < 0 || (ITr->Flags & 4) != 0 )
  {
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_getabsslot, (unsigned int)(LODWORD(v76.pNode) + 1));
    type.Flags = 0;
    type.Bonus.pWeakProxy = 0i64;
    if ( !Scaleform::GFx::AS3::TR::State::GetPropertyType(
            st,
            (Scaleform::GFx::AS3::CheckResult *)&p_value,
            ITr,
            v50,
            &type)->Result )
    {
      v39 = type.Flags;
      if ( (type.Flags & 0x1F) <= 9 )
        goto LABEL_182;
      if ( (type.Flags & 0x200) != 0 )
      {
        v34 = type.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v34 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        goto LABEL_90;
      }
LABEL_91:
      Scaleform::GFx::AS3::Value::ReleaseInternal(&type);
      goto LABEL_182;
    }
    v34 = !v10;
    v64 = type.Flags;
    if ( !v34 )
    {
      v64 = type.Flags | 0x400;
      type.Flags |= 0x400u;
    }
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &st->OpStack.Data,
      st->OpStack.Data.pHeap,
      st->OpStack.Data.Size + 1);
    v65 = st->OpStack.Data.Size;
    v66 = st->OpStack.Data.Data - 1;
    v34 = &v66[v65] == 0i64;
    v67 = (unsigned __int64)&v66[v65];
    *(_QWORD *)&p.Flags = v67;
    arg1 = v67;
    v68 = type.Bonus.pWeakProxy;
    if ( !v34 )
    {
      *(_DWORD *)v67 = v64;
      *(_QWORD *)(v67 + 8) = v68;
      v69 = type.value.VS._1;
      *(_QWORD *)(v67 + 16) = type.value.VS._1.VStr;
      v70.VObj = (Scaleform::GFx::AS3::Object *)type.value.VS._2;
      *(_QWORD *)(v67 + 24) = type.value.VS._2.VObj;
      if ( (v64 & 0x1F) > 9 )
      {
        if ( (v64 & 0x200) != 0 )
        {
          ++v68->RefCount;
        }
        else if ( (v64 & 0x1F) == 10 )
        {
          ++v69.VStr->RefCount;
        }
        else if ( (v64 & 0x1F) > 0xA )
        {
          if ( (v64 & 0x1F) <= 0xF )
          {
            if ( v69.VStr )
              v69.VStr->Size = (v69.VStr->Size + 1) & 0x8FBFFFFF;
          }
          else if ( (v64 & 0x1F) <= 0x11 && v70.VObj )
          {
            v70.VObj->RefCount = (v70.VObj->RefCount + 1) & 0x8FBFFFFF;
          }
        }
      }
    }
    if ( (v64 & 0x1F) <= 9 )
      goto LABEL_72;
    if ( (v64 & 0x200) != 0 )
    {
      v34 = v68->RefCount-- == 1;
      if ( v34 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&type.Bonus, 0, 24);
      type.Flags = v64 & 0xFFFFFDE0;
      goto LABEL_72;
    }
    Scaleform::GFx::AS3::Value::ReleaseInternal(&type);
    Slot = 1;
  }
  else
  {
    if ( v52 == 11 )
    {
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_getabsslot, (unsigned int)(LODWORD(v76.pNode) + 1));
      v53 = (__int64)*(_DWORD *)v50 >> 15;
      VT = Scaleform::GFx::AS3::Traits::GetVT(ITr);
      Value = Scaleform::GFx::AS3::VTable::GetValue(VT, &v83, (Scaleform::GFx::AS3::AbsoluteIndex)v53);
      FunctType = Scaleform::GFx::AS3::TR::State::GetFunctType(st, Value);
      if ( (v83.Flags & 0x1F) > 9 )
      {
        if ( (v83.Flags & 0x200) != 0 )
        {
          v34 = v83.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v34 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&v83.Bonus, 0, 24);
          v83.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v83);
        }
      }
    }
    else
    {
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_callmethod, (int)v51 >> 15, 0i64);
      v57 = (__int64)*(_DWORD *)v50 >> 15;
      v58 = Scaleform::GFx::AS3::Traits::GetVT(ITr);
      v59 = Scaleform::GFx::AS3::VTable::GetValue(v58, &v84, (Scaleform::GFx::AS3::AbsoluteIndex)v57);
      v60 = this->CF->pFile->VMRef;
      AppDomain = Scaleform::GFx::AS3::Traits::GetAppDomain(ITr);
      FunctType = Scaleform::GFx::AS3::VM::GetFunctReturnType(v60, v59, AppDomain);
      if ( (v84.Flags & 0x1F) > 9 )
      {
        if ( (v84.Flags & 0x200) != 0 )
        {
          v34 = v84.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v34 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&v84.Bonus, 0, 24);
          v84.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v84);
        }
      }
    }
    CanBeNull = Scaleform::GFx::AS3::Tracer::CanBeNull(this, FunctType);
    v.Bonus.pWeakProxy = 0i64;
    v.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)FunctType;
    v63 = (32 * CanBeNull) & 0xFFFFFEF7 | 8;
    v.Flags = v63;
    Scaleform::GFx::AS3::TR::State::PushOp(st, &v);
    if ( (v63 & 0x1F) <= 9 )
      goto LABEL_72;
    if ( (v63 & 0x200) != 0 )
    {
      LODWORD(MEMORY[0]) = MEMORY[0] - 1;
      if ( !(_DWORD)MEMORY[0] )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
      v.Flags = v63 & 0xFFFFFDE0;
      memset(&v.Bonus, 0, 24);
      goto LABEL_72;
    }
    Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
    Slot = 1;
  }
LABEL_183:
  if ( (result.This.Flags & 0x1F) > 9 )
  {
    if ( (result.This.Flags & 0x200) != 0 )
    {
      v34 = result.This.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v34 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&result.This.Bonus, 0, 24);
      result.This.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&result.This);
    }
  }
LABEL_190:
  if ( (mn.Name.Flags & 0x1F) > 9 )
  {
    if ( (mn.Name.Flags & 0x200) != 0 )
    {
      v34 = mn.Name.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v34 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&mn.Name.Bonus, 0, 24);
      mn.Name.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&mn.Name);
    }
  }
  pObject = mn.Obj.pObject;
  if ( mn.Obj.pObject )
  {
    if ( ((__int64)mn.Obj.pObject & 1) != 0 )
    {
      --mn.Obj.pObject;
    }
    else
    {
      RefCount = mn.Obj.pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        mn.Obj.pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
  return Slot;
}

// File Line: 7668
// RVA: 0x7C89C0
char __fastcall Scaleform::GFx::AS3::Tracer::EmitGetSlot(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::TR::State *st,
        Scaleform::GFx::AS3::Value *value,
        const unsigned __int64 index,
        bool objOnStack)
{
  unsigned int v7; // r10d
  unsigned int v9; // r10d
  unsigned int v10; // r10d
  Scaleform::GFx::AS3::Value::V1U v11; // rax
  int v12; // edx

  v7 = value->Flags & 0x1F;
  if ( v7 - 8 <= 1 )
  {
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_getabsslot, (unsigned int)(index + 1));
    return 1;
  }
  if ( v7 )
  {
    v9 = v7 - 1;
    if ( v9 )
    {
      v10 = v9 - 3;
      if ( v10 )
      {
        if ( v10 - 8 <= 1 )
          return Scaleform::GFx::AS3::Tracer::EmitGetAbsObject(this, st, value, objOnStack);
        return 0;
      }
      v11 = value->value.VS._1;
      if ( ((__int64)v11.VStr & 0x7FF0000000000000i64) != 0x7FF0000000000000i64
        || ((__int64)v11.VStr & 0xFFFFFFFFFFFFFi64) == 0 )
      {
        return 0;
      }
      if ( objOnStack )
        Scaleform::GFx::AS3::Tracer::EmitPopPrevResult(this, st);
      v12 = 40;
    }
    else
    {
      if ( objOnStack )
        Scaleform::GFx::AS3::Tracer::EmitPopPrevResult(this, st);
      v12 = 39 - value->value.VS._1.VBool;
    }
  }
  else
  {
    if ( objOnStack )
      Scaleform::GFx::AS3::Tracer::EmitPopPrevResult(this, st);
    v12 = 33;
  }
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, (Scaleform::GFx::AS3::Abc::Code::OpCode)v12);
  return 1;
}

// File Line: 7743
// RVA: 0x7C8120
char __fastcall Scaleform::GFx::AS3::Tracer::EmitGetProperty(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::Abc::Code::OpCode opcode,
        Scaleform::GFx::AS3::TR::State *st,
        Scaleform::GFx::AS3::TR::ReadMnObject *args,
        int mn_index)
{
  Scaleform::GFx::AS3::Multiname *p_ArgMN; // rdi
  Scaleform::GFx::AS3::Traits *ValueTraits; // rsi
  Scaleform::GFx::AS3::Abc::MultinameKind Kind; // eax
  int v11; // r8d
  Scaleform::GFx::AS3::CallFrame *CF; // r12
  Scaleform::GFx::AS3::VM *VMRef; // rbx
  Scaleform::GFx::AS3::Multiname *v14; // rax
  Scaleform::GFx::AS3::SlotInfo *FixedSlot; // rax
  Scaleform::GFx::AS3::SlotInfo *v16; // r12
  __int64 v17; // rax
  int v18; // edx
  __int64 v19; // rbx
  Scaleform::GFx::AS3::VTable *v20; // rax
  Scaleform::GFx::AS3::Value *v21; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *FunctReturnType; // rdi
  bool v23; // zf
  int CanBeNull; // eax
  unsigned int v25; // ebx
  Scaleform::GFx::AS3::Abc::Code::OpCode v26; // edx
  __int64 v27; // rbx
  Scaleform::GFx::AS3::VTable *VT; // rax
  Scaleform::GFx::AS3::Value *Value; // rdi
  Scaleform::GFx::AS3::VM *v30; // rbx
  Scaleform::GFx::AS3::VMAppDomain *AppDomain; // rax
  Scaleform::GFx::AS3::Abc::MultinameKind v32; // ebx
  unsigned __int64 Size; // rcx
  Scaleform::GFx::AS3::Value *v35; // r9
  unsigned __int64 v36; // r9
  Scaleform::GFx::AS3::GASRefCountBase *pObject; // rdx
  Scaleform::GFx::AS3::Abc::MultinameKind v38; // ebx
  __int64 v39; // r8
  Scaleform::GFx::AS3::Value::Extra v40; // r10
  unsigned __int64 v41; // r8
  Scaleform::GFx::AS3::Abc::Code::OpCode v42; // edx
  Scaleform::GFx::AS3::SlotInfo *v43; // rax
  unsigned __int64 v44; // rcx
  Scaleform::GFx::AS3::Value *v45; // r9
  __int64 v46; // r9
  Scaleform::GFx::AS3::GASRefCountBase *v47; // rdx
  Scaleform::GFx::AS3::Abc::MultinameKind v48; // ebx
  __int64 v49; // r8
  Scaleform::GFx::AS3::Value::Extra v50; // r10
  Scaleform::GFx::AS3::BuiltinTraitsType TraitsType; // edx
  void *v52; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v53; // rdi
  int v54; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v55; // rax
  unsigned __int64 v56[2]; // [rsp+30h] [rbp-50h] BYREF
  unsigned __int64 v57; // [rsp+40h] [rbp-40h]
  __int64 v58; // [rsp+48h] [rbp-38h]
  Scaleform::GFx::AS3::Multiname v59; // [rsp+50h] [rbp-30h] BYREF
  Scaleform::GFx::AS3::CheckResult result; // [rsp+C8h] [rbp+48h] BYREF
  unsigned __int64 index; // [rsp+D8h] [rbp+58h] BYREF

  v56[1] = -2i64;
  p_ArgMN = &args->ArgMN;
  ValueTraits = Scaleform::GFx::AS3::Tracer::GetValueTraits(this, &args->ArgObject, opcode == op_getsuper);
  Kind = p_ArgMN->Kind;
  v11 = p_ArgMN->Kind & 3;
  if ( v11 == 1 || (Kind & 4) != 0 || (Kind & 8) != 0 || !v11 && !p_ArgMN->Obj.pObject )
    goto $fall_back;
  if ( !ValueTraits )
    goto $fall_back;
  CF = this->CF;
  VMRef = CF->pFile->VMRef;
  index = 0i64;
  if ( (p_ArgMN->Name.Flags & 0x1F) - 8 <= 1 )
    goto $fall_back;
  if ( (ValueTraits->Flags & 4) == 0
    && !Scaleform::GFx::AS3::Tracer::IsPrimitiveType(this, ValueTraits)
    && ValueTraits != CF->pFile->VMRef->TraitsNamespace.pObject->ITraits.pObject )
  {
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::Traits *))ValueTraits->vfptr[1].ForEachChild_GC)(ValueTraits) )
    {
      v56[0] = (unsigned __int64)&v59;
      Scaleform::GFx::AS3::Multiname::Multiname(&v59, p_ArgMN);
      if ( Scaleform::GFx::AS3::Tracer::EmitGetClassTraits(this, st, v14, 1) )
        return 1;
    }
    FixedSlot = Scaleform::GFx::AS3::FindFixedSlot(VMRef, ValueTraits, p_ArgMN, &index, 0i64);
    v16 = FixedSlot;
    if ( FixedSlot )
    {
      v17 = *(_DWORD *)FixedSlot;
      v18 = (int)((_DWORD)v17 << 17) >> 27;
      if ( v18 <= 10 )
      {
        v59.Kind = MN_QName;
        v59.Obj.pObject = 0i64;
        if ( !Scaleform::GFx::AS3::TR::State::GetPropertyType(
                st,
                &result,
                ValueTraits,
                v16,
                (Scaleform::GFx::AS3::Value *)&v59)->Result )
        {
          v32 = v59.Kind;
          if ( (v59.Kind & 0x1Fu) <= 9 )
            return 0;
          if ( (v59.Kind & 0x200) != 0 )
          {
            v23 = LODWORD(v59.Obj.pObject->vfptr)-- == 1;
            if ( v23 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            goto LABEL_48;
          }
LABEL_49:
          Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v59);
          return 0;
        }
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          &st->OpStack.Data,
          st->OpStack.Data.pHeap,
          st->OpStack.Data.Size + 1);
        Size = st->OpStack.Data.Size;
        v35 = st->OpStack.Data.Data - 1;
        v23 = &v35[Size] == 0i64;
        v36 = (unsigned __int64)&v35[Size];
        v56[0] = v36;
        v57 = v36;
        pObject = v59.Obj.pObject;
        v38 = v59.Kind;
        if ( !v23 )
        {
          *(_DWORD *)v36 = v59.Kind;
          *(_QWORD *)(v36 + 8) = pObject;
          v39 = *(_QWORD *)&v59.Name.Flags;
          *(_QWORD *)(v36 + 16) = *(_QWORD *)&v59.Name.Flags;
          v40.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v59.Name.Bonus;
          *(_QWORD *)(v36 + 24) = v59.Name.Bonus.pWeakProxy;
          if ( (v38 & 0x1Fu) > 9 )
          {
            if ( (v38 & 0x200) != 0 )
            {
              ++LODWORD(pObject->vfptr);
            }
            else if ( (v38 & 0x1F) == 10 )
            {
              ++*(_DWORD *)(v39 + 24);
            }
            else if ( (v38 & 0x1Fu) > 0xA )
            {
              if ( (v38 & 0x1Fu) <= 0xF )
              {
                if ( v39 )
                  *(_DWORD *)(v39 + 32) = (*(_DWORD *)(v39 + 32) + 1) & 0x8FBFFFFF;
              }
              else if ( (v38 & 0x1Fu) <= 0x11 && v40.pWeakProxy )
              {
                v40.pWeakProxy[2].RefCount = (v40.pWeakProxy[2].RefCount + 1) & 0x8FBFFFFF;
              }
            }
          }
        }
        if ( (v38 & 0x1Fu) > 9 )
        {
          if ( (v38 & 0x200) != 0 )
          {
            v23 = LODWORD(pObject->vfptr)-- == 1;
            if ( v23 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            memset(&v59.Obj, 0, 24);
            v59.Kind = v38 & 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v59);
          }
        }
        if ( (p_ArgMN->Kind & 4) != 0 )
          Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_pop);
        v41 = (unsigned int)(index + 1);
        v42 = op_getabsslot;
        goto LABEL_117;
      }
      if ( v17 >> 15 >= 0 )
      {
        if ( v18 != 11 )
        {
          if ( (p_ArgMN->Kind & 4) != 0 )
            Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_pop);
          v26 = op_callmethod;
          if ( opcode == op_getsuper )
            v26 = op_callsupermethod;
          Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, v26, *(_DWORD *)v16 >> 15, 0i64);
          v27 = (__int64)*(_DWORD *)v16 >> 15;
          VT = Scaleform::GFx::AS3::Traits::GetVT(ValueTraits);
          Value = Scaleform::GFx::AS3::VTable::GetValue(
                    VT,
                    (Scaleform::GFx::AS3::Value *)&v59,
                    (Scaleform::GFx::AS3::AbsoluteIndex)v27);
          v30 = this->CF->pFile->VMRef;
          AppDomain = Scaleform::GFx::AS3::Traits::GetAppDomain(ValueTraits);
          FunctReturnType = Scaleform::GFx::AS3::VM::GetFunctReturnType(v30, Value, AppDomain);
          if ( (v59.Kind & 0x1Fu) <= 9 )
            goto LABEL_26;
          if ( (v59.Kind & 0x200) != 0 )
          {
            v23 = LODWORD(v59.Obj.pObject->vfptr)-- == 1;
            if ( v23 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            goto LABEL_24;
          }
          Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v59);
LABEL_26:
          CanBeNull = Scaleform::GFx::AS3::Tracer::CanBeNull(this, FunctReturnType);
          v59.Obj.pObject = 0i64;
          *(_QWORD *)&v59.Name.Flags = FunctReturnType;
          v25 = (32 * CanBeNull) & 0xFFFFFEF7 | 8;
          v59.Kind = v25;
          Scaleform::GFx::AS3::TR::State::PushOp(st, (Scaleform::GFx::AS3::Value *)&v59);
          if ( (v25 & 0x1F) > 9 )
          {
            if ( (v25 & 0x200) != 0 )
            {
              LODWORD(MEMORY[0]) = MEMORY[0] - 1;
              if ( !(_DWORD)MEMORY[0] )
                Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
              memset(&v59.Obj, 0, 24);
              v59.Kind = v25 & 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v59);
            }
          }
          return 1;
        }
        if ( opcode == op_getproperty )
        {
          if ( (p_ArgMN->Kind & 4) != 0 )
            Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_pop);
          Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_getabsslot, (unsigned int)(index + 1));
          v19 = (__int64)*(_DWORD *)v16 >> 15;
          v20 = Scaleform::GFx::AS3::Traits::GetVT(ValueTraits);
          v21 = Scaleform::GFx::AS3::VTable::GetValue(
                  v20,
                  (Scaleform::GFx::AS3::Value *)&v59,
                  (Scaleform::GFx::AS3::AbsoluteIndex)v19);
          FunctReturnType = Scaleform::GFx::AS3::TR::State::GetFunctType(st, v21);
          if ( (v59.Kind & 0x1Fu) <= 9 )
            goto LABEL_26;
          if ( (v59.Kind & 0x200) != 0 )
          {
            v23 = LODWORD(v59.Obj.pObject->vfptr)-- == 1;
            if ( v23 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
LABEL_24:
            memset(&v59.Obj, 0, 24);
            v59.Kind &= 0xFFFFFDE0;
            goto LABEL_26;
          }
          Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v59);
          goto LABEL_26;
        }
      }
    }
  }
  v56[0] = 0i64;
  v43 = Scaleform::GFx::AS3::FindFixedSlot(this->CF->pFile->VMRef, ValueTraits, p_ArgMN, v56, 0i64);
  if ( !v43 )
  {
    TraitsType = ValueTraits->TraitsType;
    if ( (ValueTraits->Flags & 0x20) == 0 )
    {
      switch ( TraitsType )
      {
        case Traits_Vector_int:
          v52 = VMRef->TraitsInt.pObject;
          break;
        case Traits_Vector_uint:
          v52 = VMRef->TraitsUint.pObject;
          break;
        case Traits_Vector_double:
          v52 = VMRef->TraitsNumber.pObject;
          break;
        case Traits_Vector_String:
          v52 = VMRef->TraitsString.pObject;
          break;
        default:
          goto LABEL_109;
      }
      v53 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)*((_QWORD *)v52 + 25);
      if ( v53 )
        goto LABEL_111;
    }
LABEL_109:
    if ( TraitsType == Traits_Vector_object )
    {
      v53 = *(Scaleform::GFx::AS3::InstanceTraits::Traits **)(Scaleform::GFx::AS3::Traits::GetConstructor(ValueTraits)->pTraits.pObject[1].pRCCRaw
                                                            + 200);
      if ( v53 )
      {
LABEL_111:
        v54 = Scaleform::GFx::AS3::Tracer::CanBeNull(this, v53);
        v59.Obj.pObject = 0i64;
        *(_QWORD *)&v59.Name.Flags = v53;
        v48 = (32 * v54) & 0xFFFFFEF7 | 8;
        v59.Kind = v48;
        Scaleform::GFx::AS3::TR::State::PushOp(st, (Scaleform::GFx::AS3::Value *)&v59);
        if ( (v48 & 0x1Fu) <= 9 )
          goto LABEL_116;
        if ( (v48 & 0x200) != 0 )
        {
          LODWORD(MEMORY[0]) = MEMORY[0] - 1;
          if ( (_DWORD)MEMORY[0] )
            goto LABEL_97;
          goto LABEL_96;
        }
LABEL_98:
        Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v59);
        goto LABEL_116;
      }
    }
$fall_back:
    v55 = this->CF->pFile->VMRef->TraitsObject.pObject->ITraits.pObject;
    v59.Obj.pObject = 0i64;
    *(_QWORD *)&v59.Name.Flags = v55;
    v59.Kind = 72;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &st->OpStack.Data,
      st->OpStack.Data.pHeap,
      st->OpStack.Data.Size + 1);
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
      &st->OpStack.Data.Data[st->OpStack.Data.Size - 1].Flags,
      (Scaleform::GFx::AS3::Value *)&v59);
    goto LABEL_116;
  }
  v59.Kind = MN_QName;
  v59.Obj.pObject = 0i64;
  if ( !Scaleform::GFx::AS3::TR::State::GetPropertyType(
          st,
          &result,
          ValueTraits,
          v43,
          (Scaleform::GFx::AS3::Value *)&v59)->Result )
  {
    v32 = v59.Kind;
    if ( (v59.Kind & 0x1Fu) <= 9 )
      return 0;
    if ( (v59.Kind & 0x200) != 0 )
    {
      v23 = LODWORD(v59.Obj.pObject->vfptr)-- == 1;
      if ( v23 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
LABEL_48:
      memset(&v59.Obj, 0, 24);
      v59.Kind = v32 & 0xFFFFFDE0;
      return 0;
    }
    goto LABEL_49;
  }
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &st->OpStack.Data,
    st->OpStack.Data.pHeap,
    st->OpStack.Data.Size + 1);
  v44 = st->OpStack.Data.Size;
  v45 = st->OpStack.Data.Data - 1;
  v23 = &v45[v44] == 0i64;
  v46 = (__int64)&v45[v44];
  v57 = v46;
  v58 = v46;
  v47 = v59.Obj.pObject;
  v48 = v59.Kind;
  if ( !v23 )
  {
    *(_DWORD *)v46 = v59.Kind;
    *(_QWORD *)(v46 + 8) = v47;
    v49 = *(_QWORD *)&v59.Name.Flags;
    *(_QWORD *)(v46 + 16) = *(_QWORD *)&v59.Name.Flags;
    v50.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v59.Name.Bonus;
    *(_QWORD *)(v46 + 24) = v59.Name.Bonus.pWeakProxy;
    if ( (v48 & 0x1Fu) > 9 )
    {
      if ( (v48 & 0x200) != 0 )
      {
        ++LODWORD(v47->vfptr);
      }
      else if ( (v48 & 0x1F) == 10 )
      {
        ++*(_DWORD *)(v49 + 24);
      }
      else if ( (v48 & 0x1Fu) > 0xA )
      {
        if ( (v48 & 0x1Fu) <= 0xF )
        {
          if ( v49 )
            *(_DWORD *)(v49 + 32) = (*(_DWORD *)(v49 + 32) + 1) & 0x8FBFFFFF;
        }
        else if ( (v48 & 0x1Fu) <= 0x11 && v50.pWeakProxy )
        {
          v50.pWeakProxy[2].RefCount = (v50.pWeakProxy[2].RefCount + 1) & 0x8FBFFFFF;
        }
      }
    }
  }
  if ( (v48 & 0x1Fu) <= 9 )
    goto LABEL_116;
  if ( (v48 & 0x200) == 0 )
    goto LABEL_98;
  v23 = LODWORD(v47->vfptr)-- == 1;
  if ( v23 )
LABEL_96:
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
LABEL_97:
  memset(&v59.Obj, 0, 24);
  v59.Kind = v48 & 0xFFFFFDE0;
LABEL_116:
  v41 = mn_index;
  v42 = opcode;
LABEL_117:
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, v42, v41);
  return 1;
}

// File Line: 8051
// RVA: 0x7C8C40
char __fastcall Scaleform::GFx::AS3::Tracer::EmitSetProperty(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::Abc::Code::OpCode opcode,
        Scaleform::GFx::AS3::TR::ReadValueMnObject *args,
        const int mn_index)
{
  bool v5; // r12
  Scaleform::GFx::AS3::Multiname *p_ArgMN; // rdi
  unsigned __int64 v7; // r15
  Scaleform::GFx::AS3::Traits *ValueTraits; // rax
  Scaleform::GFx::AS3::Abc::MultinameKind Kind; // r8d
  Scaleform::GFx::AS3::Traits *v11; // rsi
  int v12; // r10d
  Scaleform::GFx::AS3::VM *VMRef; // rcx
  Scaleform::GFx::AS3::SlotInfo *FixedSlot; // rax
  int *v15; // r14
  int v16; // ecx
  Scaleform::GFx::AS3::Abc::Code::OpCode v17; // edx
  Scaleform::GFx::AS3::Tracer *v18; // rcx
  unsigned __int64 v19; // r8
  Scaleform::GFx::AS3::Abc::Code::OpCode v20; // edx
  unsigned __int64 index; // [rsp+70h] [rbp+18h] BYREF

  v5 = opcode == op_setsuper;
  p_ArgMN = &args->ArgMN;
  v7 = mn_index;
  ValueTraits = Scaleform::GFx::AS3::Tracer::GetValueTraits(this, &args->ArgObject, opcode == op_setsuper);
  Kind = p_ArgMN->Kind;
  v11 = ValueTraits;
  v12 = p_ArgMN->Kind & 3;
  if ( v12 == 1 || (Kind & 4) != 0 || (Kind & 8) != 0 || !v12 && !p_ArgMN->Obj.pObject )
    goto LABEL_22;
  if ( !ValueTraits )
    goto LABEL_22;
  VMRef = this->CF->pFile->VMRef;
  index = 0i64;
  FixedSlot = Scaleform::GFx::AS3::FindFixedSlot(VMRef, ValueTraits, p_ArgMN, &index, 0i64);
  v15 = (int *)FixedSlot;
  if ( !FixedSlot )
    goto LABEL_22;
  v16 = (int)(*(_DWORD *)FixedSlot << 17) >> 27;
  if ( v16 <= 10 )
  {
    if ( (p_ArgMN->Kind & 4) != 0 )
    {
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_swap);
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_pop);
    }
    v18 = this;
    v19 = (unsigned int)(index + 1);
    if ( opcode == op_initproperty )
      v20 = op_initabsslot;
    else
      v20 = op_setabsslot;
    goto LABEL_23;
  }
  if ( *(_DWORD *)FixedSlot < 0 || (v11->Flags & 4) != 0 || v16 <= 12 )
  {
LABEL_22:
    v19 = v7;
    v20 = opcode;
    v18 = this;
LABEL_23:
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(v18, v20, v19);
    return 1;
  }
  if ( (p_ArgMN->Kind & 4) != 0 )
  {
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_swap);
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_pop);
  }
  v17 = op_callmethod;
  if ( v5 )
    v17 = op_callsupermethod;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, v17, (*v15 >> 15) + 1, 1ui64);
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_pop);
  return 1;
}

// File Line: 8246
// RVA: 0x7C6670
char __fastcall Scaleform::GFx::AS3::Tracer::EmitCall(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::Abc::Code::OpCode opcode,
        Scaleform::GFx::AS3::TR::State *st,
        Scaleform::GFx::AS3::TR::ReadArgsMnObject *args,
        unsigned int mn_index)
{
  bool v9; // r8
  Scaleform::GFx::AS3::Traits *ValueTraits; // r14
  Scaleform::GFx::AS3::Multiname *p_ArgMN; // r12
  unsigned __int64 ArgNum; // r15
  Scaleform::GFx::AS3::Abc::MultinameKind Kind; // edx
  Scaleform::GFx::AS3::SlotInfo *FixedSlot; // rax
  __int64 v15; // rax
  __int64 v16; // rbx
  int v17; // eax
  Scaleform::GFx::AS3::VTable *VT; // rax
  Scaleform::GFx::AS3::Value *Value; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *FunctReturnType; // rbx
  int v22; // ecx
  int v23; // eax
  Scaleform::GFx::AS3::Abc::Code::OpCode v24; // edx
  Scaleform::GFx::AS3::Tracer *v25; // rcx
  int CanBeNull; // ebx
  unsigned int v27; // ebx
  Scaleform::GFx::AS3::Abc::Code::OpCode v28; // edx
  Scaleform::GFx::AS3::ClassTraits::Traits *ClassTraits; // rbx
  Scaleform::GFx::AS3::Value::V1U v30; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // rax
  Scaleform::GFx::AS3::Value::V1U v33; // [rsp+30h] [rbp-40h]
  unsigned __int64 index; // [rsp+38h] [rbp-38h] BYREF
  int *v35; // [rsp+40h] [rbp-30h]
  __int64 v36; // [rsp+48h] [rbp-28h]
  Scaleform::GFx::AS3::Value result; // [rsp+50h] [rbp-20h] BYREF
  Scaleform::GFx::AS3::VM *vm; // [rsp+B8h] [rbp+48h]

  v36 = -2i64;
  v9 = opcode == op_callsuper || opcode == op_callsupervoid;
  ValueTraits = Scaleform::GFx::AS3::Tracer::GetValueTraits(this, &args->ArgObject, v9);
  p_ArgMN = &args->ArgMN;
  ArgNum = args->ArgNum;
  Kind = args->ArgMN.Kind;
  if ( (Kind & 3) == 1 || (Kind & 4) != 0 || (Kind & 8) != 0 || (Kind & 3) == 0 && !args->ArgMN.Obj.pObject )
    goto LABEL_47;
  index = 0i64;
  vm = this->CF->pFile->VMRef;
  if ( ValueTraits )
  {
    if ( (ValueTraits->Flags & 4) == 0 )
    {
      FixedSlot = Scaleform::GFx::AS3::FindFixedSlot(vm, ValueTraits, p_ArgMN, &index, 0i64);
      v35 = (int *)FixedSlot;
      if ( FixedSlot )
      {
        v15 = *(_DWORD *)FixedSlot;
        v16 = v15 >> 15;
        if ( v15 >> 15 >= 0 )
        {
          v17 = (int)((_DWORD)v15 << 17) >> 27;
          if ( v17 == 11 || ((v17 - 12) & 0xFFFFFFFD) == 0 )
          {
            VT = Scaleform::GFx::AS3::Traits::GetVT(ValueTraits);
            Value = Scaleform::GFx::AS3::VTable::GetValue(VT, &result, (Scaleform::GFx::AS3::AbsoluteIndex)v16);
            FunctReturnType = Scaleform::GFx::AS3::VM::GetFunctReturnType(vm, Value, this->CF->pFile->AppDomain.pObject);
            v33.VStr = (Scaleform::GFx::ASStringNode *)FunctReturnType;
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
            v22 = *v35;
            v23 = *v35 << 17 >> 27;
            if ( v23 == 11 )
            {
              if ( opcode == op_callsuper || (v24 = op_callmethod, opcode == op_callsupervoid) )
                v24 = op_callsupermethod;
              Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, v24, v22 >> 15, ArgNum);
              v25 = this;
              if ( (unsigned int)(opcode - 78) > 1 )
              {
LABEL_27:
                CanBeNull = Scaleform::GFx::AS3::Tracer::CanBeNull(v25, FunctReturnType);
                result.Bonus.pWeakProxy = 0i64;
                result.value.VS._1 = v33;
                v27 = (32 * CanBeNull) & 0xFFFFFEF7 | 8;
                result.Flags = v27;
                Scaleform::GFx::AS3::TR::State::PushOp(st, &result);
                if ( (v27 & 0x1F) > 9 )
                {
                  if ( (v27 & 0x200) != 0 )
                  {
                    LODWORD(MEMORY[0]) = MEMORY[0] - 1;
                    if ( !(_DWORD)MEMORY[0] )
                      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
                    memset(&result.Bonus, 0, 24);
                    result.Flags = v27 & 0xFFFFFDE0;
                  }
                  else
                  {
                    Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
                  }
                }
                return 1;
              }
LABEL_33:
              Scaleform::GFx::AS3::Tracer::PushNewOpCode(v25, op_pop);
              return 1;
            }
            if ( ((v23 - 12) & 0xFFFFFFFD) == 0 )
            {
              if ( opcode == op_callsuper || (v28 = op_callgetter, opcode == op_callsupervoid) )
                v28 = op_callsupergetter;
              Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, v28, v22 >> 15, ArgNum);
              v25 = this;
              if ( (unsigned int)(opcode - 78) > 1 )
                goto LABEL_27;
              goto LABEL_33;
            }
          }
        }
      }
    }
  }
  ClassTraits = Scaleform::GFx::AS3::FindClassTraits(vm, p_ArgMN, this->CF->pFile->AppDomain.pObject);
  if ( !ClassTraits )
  {
LABEL_47:
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, opcode, mn_index, ArgNum);
    if ( (unsigned int)(opcode - 78) > 1 )
    {
      pObject = this->CF->pFile->VMRef->TraitsObject.pObject->ITraits.pObject;
      result.Bonus.pWeakProxy = 0i64;
      result.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)pObject;
      result.Flags = 72;
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        &st->OpStack.Data,
        st->OpStack.Data.pHeap,
        st->OpStack.Data.Size + 1);
      Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
        &st->OpStack.Data.Data[st->OpStack.Data.Size - 1].Flags,
        &result);
    }
  }
  else
  {
    if ( (ValueTraits->Flags & 0x20) != 0 )
    {
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_callobject, ArgNum);
      if ( (unsigned int)(opcode - 78) <= 1 )
      {
        Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_pop);
        return 1;
      }
    }
    else
    {
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, opcode, mn_index, ArgNum);
      if ( (unsigned int)(opcode - 78) <= 1 )
        return 1;
    }
    v30 = (Scaleform::GFx::AS3::Value::V1U)ClassTraits->ITraits.pObject;
    result.Bonus.pWeakProxy = 0i64;
    result.value.VS._1 = v30;
    result.Flags = 8;
    Scaleform::GFx::AS3::TR::State::PushOp(st, &result);
  }
  return 1;
}

// File Line: 8817
// RVA: 0x7C7CC0
char __fastcall Scaleform::GFx::AS3::Tracer::EmitGetAbsObject(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::TR::State *st,
        Scaleform::GFx::AS3::Value *value,
        bool objOnStack)
{
  Scaleform::GFx::AS3::Traits *ValueTraits; // rax
  char result; // al

  ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(this->CF->pFile->VMRef, value);
  if ( (value->Flags & 0x1F) == 13
    || (result = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Traits *))ValueTraits->vfptr[1].ForEachChild_GC)(ValueTraits)) != 0 )
  {
    if ( objOnStack )
      Scaleform::GFx::AS3::Tracer::EmitPopPrevResult(this, st);
    Scaleform::GFx::AS3::Tracer::EmitGetAbsObject2(this, st, value);
    return 1;
  }
  return result;
}

// File Line: 8842
// RVA: 0x7C7C20
void __fastcall Scaleform::GFx::AS3::Tracer::EmitGetAbsObject2(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::TR::State *st,
        Scaleform::GFx::AS3::Value *value)
{
  int v5; // eax
  Scaleform::GFx::AS3::VMAbcFile *pFile; // rcx
  Scaleform::GFx::AS3::Object *key; // [rsp+30h] [rbp+8h] BYREF

  switch ( value->Flags & 0x1F )
  {
    case 11u:
      v5 = 6;
      break;
    case 12u:
      v5 = 0;
      break;
    case 13u:
      v5 = 2;
      break;
    case 14u:
      v5 = 4;
      break;
    default:
      v5 = -1;
      break;
  }
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_getabsobject, (unsigned __int64)value->value.VS._1.VStr + v5);
  pFile = this->CF->pFile;
  if ( value->value.VS._1.VStr != (Scaleform::GFx::ASStringNode *)pFile->VMRef->GlobalObject.pObject )
  {
    key = value->value.VS._1.VObj;
    Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>>>>::Set<Scaleform::GFx::AS3::Object *>(
      &pFile->AbsObjects,
      &pFile->AbsObjects,
      (Scaleform::GFx::AS3::Instances::fl::XMLList **)&key);
  }
}

// File Line: 8881
// RVA: 0x805C20
void __fastcall Scaleform::GFx::AS3::Tracer::Output(Scaleform::GFx::AS3::Tracer *this, __int64 type, const char *msg)
{
  Scaleform::GFx::AS3::FlashUI *UI; // rcx

  UI = this->CF->pFile->VMRef->UI;
  UI->vfptr->Output(UI, (Scaleform::GFx::AS3::FlashUI::OutputMessageType)type, msg);
}

// File Line: 8914
// RVA: 0x7AB340
Scaleform::GFx::AS3::TR::Block *__fastcall Scaleform::GFx::AS3::Tracer::AddBlock(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::TR::State *st,
        unsigned __int64 from,
        Scaleform::GFx::AS3::TR::Block::EType type,
        bool checkOpCode)
{
  Scaleform::GFx::AS3::TR::Block::EType v5; // esi
  Scaleform::GFx::AS3::TR::Block *i; // rbx
  char v11; // r13
  int v12; // eax
  Scaleform::GFx::AS3::TR::State *v13; // rax
  Scaleform::GFx::AS3::TR::State *v14; // rax
  Scaleform::GFx::AS3::TR::State *v15; // r12
  unsigned __int64 Size; // rax
  unsigned __int64 v17; // r15
  unsigned __int64 v18; // r8
  Scaleform::GFx::AS3::TR::State **v19; // rcx
  __int64 v20; // rdx
  __int64 v21; // rax
  Scaleform::GFx::AS3::TR::Block *CurrBlock; // rcx
  bool v23; // [rsp+70h] [rbp+8h]

  v5 = type;
  if ( from >= this->CodeEnd )
    return 0i64;
  v23 = type == tDead;
  for ( i = this->Blocks.Root.pPrev; i; i = i->pPrev )
  {
    if ( from >= i->From )
      break;
  }
  v11 = 0;
  if ( i && from == i->From )
  {
    if ( i->State )
      return i;
    v11 = 1;
  }
  if ( checkOpCode )
  {
    v12 = (unsigned __int8)this->pCode[from];
    if ( v12 == 9 || (unsigned int)(v12 - 239) <= 2 )
      v23 = 0;
  }
  v13 = (Scaleform::GFx::AS3::TR::State *)this->Heap->vfptr->Alloc(this, 136i64, 0i64);
  if ( v13 )
  {
    Scaleform::GFx::AS3::TR::State::State(v13, st);
    v15 = v14;
  }
  else
  {
    v15 = 0i64;
  }
  Size = this->States.Data.Size;
  v17 = Size + 1;
  if ( Size + 1 >= Size )
  {
    if ( v17 > this->States.Data.Policy.Capacity )
    {
      v18 = v17 + (v17 >> 2);
      goto LABEL_23;
    }
  }
  else if ( v17 < this->States.Data.Policy.Capacity >> 1 )
  {
    v18 = Size + 1;
LABEL_23:
    Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy> *)&this->States,
      this->States.Data.pHeap,
      v18);
  }
  this->States.Data.Size = v17;
  v19 = &this->States.Data.Data[v17 - 1];
  if ( v19 )
    *v19 = v15;
  if ( v5 == tDead )
    v5 = v23;
  if ( v11 )
  {
    v20 = (__int64)i;
    i->State = v15;
    i->Type |= v5;
  }
  else
  {
    v21 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::TR::State **, __int64))this->Heap->vfptr->Alloc)(v19, 48i64);
    v20 = v21;
    if ( v21 )
    {
      *(_DWORD *)(v21 + 16) |= 1u;
      *(_DWORD *)(v21 + 20) = v5;
      *(_QWORD *)(v21 + 24) = v15;
      *(_QWORD *)(v21 + 32) = from;
      *(_QWORD *)(v21 + 40) = 0i64;
    }
    else
    {
      v20 = 0i64;
    }
    *(_QWORD *)v20 = i->pNext->Scaleform::ListNode<Scaleform::GFx::AS3::TR::Block>::$9DF84E59DCC7CB7977F20654EF131B14::pPrev;
    *(_QWORD *)(v20 + 8) = i->pNext;
    i->pNext->Scaleform::ListNode<Scaleform::GFx::AS3::TR::Block>::$9DF84E59DCC7CB7977F20654EF131B14::pPrev = (Scaleform::GFx::AS3::TR::Block *)v20;
    i->pNext = (Scaleform::GFx::AS3::TR::Block *)v20;
    if ( v5 == tDead )
      *(_DWORD *)(v20 + 16) &= ~1u;
    CurrBlock = this->CurrBlock;
    if ( CurrBlock )
      *(_QWORD *)(v20 + 40) = CurrBlock->CurOpStackSize;
  }
  return (Scaleform::GFx::AS3::TR::Block *)v20;
}

// File Line: 9016
// RVA: 0x7F0F70
Scaleform::GFx::AS3::InstanceTraits::Traits *__fastcall Scaleform::GFx::AS3::Tracer::GetValueTraits(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::Value *v,
        const bool super_tr)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // r9
  Scaleform::GFx::AS3::VM *VMRef; // rax

  if ( !super_tr || (pObject = (Scaleform::GFx::AS3::InstanceTraits::Traits *)this->CF->OriginationTraits) == 0i64 )
  {
    if ( (v->Flags & 0x1F) != 0 )
      pObject = (v->Flags & 0x1F) - 8 < 2
              ? (Scaleform::GFx::AS3::InstanceTraits::Traits *)v->value.VS._1.VStr
              : (Scaleform::GFx::AS3::InstanceTraits::Traits *)Scaleform::GFx::AS3::VM::GetValueTraits(
                                                                 this->CF->pFile->VMRef,
                                                                 v);
    else
      pObject = this->CF->pFile->VMRef->TraitsVoid.pObject;
    if ( pObject )
    {
      VMRef = this->CF->pFile->VMRef;
      if ( pObject == (Scaleform::GFx::AS3::InstanceTraits::Traits *)VMRef->TraitsClassClass.pObject )
        pObject = (Scaleform::GFx::AS3::InstanceTraits::Traits *)VMRef->TraitsObject.pObject;
    }
  }
  if ( super_tr && pObject )
    return (Scaleform::GFx::AS3::InstanceTraits::Traits *)pObject->pParent.pObject;
  else
    return pObject;
}

// File Line: 9057
// RVA: 0x7EA3B0
Scaleform::GFx::AS3::InstanceTraits::Traits *__fastcall Scaleform::GFx::AS3::Tracer::GetInstanceTraits(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::Value *v)
{
  unsigned int v2; // r8d
  unsigned int v4; // r8d

  v2 = v->Flags & 0x1F;
  if ( (v2 - 12 <= 3 || v2 == 10) && !v->value.VS._1.VStr )
    return this->CF->pFile->VMRef->TraitsNull.pObject;
  if ( !v2 )
    return this->CF->pFile->VMRef->TraitsClassClass.pObject->ITraits.pObject;
  v4 = v2 - 8;
  if ( !v4 )
    return v->value.VS._1.ITr;
  if ( v4 == 1 )
    return (Scaleform::GFx::AS3::InstanceTraits::Traits *)v->value.VS._1.VStr[5].pData;
  return Scaleform::GFx::AS3::VM::GetInstanceTraits(this->CF->pFile->VMRef, v);
}

// File Line: 9098
// RVA: 0x7EA0A0
Scaleform::GFx::AS3::Value *__fastcall Scaleform::GFx::AS3::Tracer::GetGlobalObject(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::TR::State *st)
{
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *pSavedScope; // rcx
  Scaleform::GFx::AS3::Value *Data; // rcx
  Scaleform::GFx::AS3::Value::V2U v5; // r8
  Scaleform::GFx::AS3::Value::V1U v6; // r8
  Scaleform::GFx::AS3::Value *v7; // rcx
  Scaleform::GFx::AS3::Value::V2U v8; // r8
  Scaleform::GFx::AS3::Value::V1U v9; // r8

  pSavedScope = this->CF->pSavedScope;
  if ( pSavedScope->Data.Size )
  {
    Data = pSavedScope->Data.Data;
    result->Flags = Data->Flags;
    result->Bonus.pWeakProxy = Data->Bonus.pWeakProxy;
    result->value = Data->value;
    if ( (Data->Flags & 0x1F) > 9 )
    {
      if ( (Data->Flags & 0x200) != 0 )
      {
        ++Data->Bonus.pWeakProxy->RefCount;
      }
      else if ( (Data->Flags & 0x1F) == 10 )
      {
        ++Data->value.VS._1.VStr->RefCount;
      }
      else if ( (Data->Flags & 0x1F) > 0xA )
      {
        if ( (Data->Flags & 0x1F) <= 0xF )
        {
          v6 = Data->value.VS._1;
          if ( v6.VStr )
            v6.VStr->Size = (v6.VStr->Size + 1) & 0x8FBFFFFF;
        }
        else if ( (Data->Flags & 0x1F) <= 0x11 )
        {
          v5.VObj = (Scaleform::GFx::AS3::Object *)Data->value.VS._2;
          if ( v5.VObj )
            v5.VObj->RefCount = (v5.VObj->RefCount + 1) & 0x8FBFFFFF;
        }
      }
    }
  }
  else
  {
    v7 = st->Registers.Data.Data;
    result->Flags = v7->Flags;
    result->Bonus.pWeakProxy = v7->Bonus.pWeakProxy;
    result->value = v7->value;
    if ( (v7->Flags & 0x1F) > 9 )
    {
      if ( (v7->Flags & 0x200) != 0 )
      {
        ++v7->Bonus.pWeakProxy->RefCount;
      }
      else if ( (v7->Flags & 0x1F) == 10 )
      {
        ++v7->value.VS._1.VStr->RefCount;
      }
      else if ( (v7->Flags & 0x1F) > 0xA )
      {
        if ( (v7->Flags & 0x1F) <= 0xF )
        {
          v9 = v7->value.VS._1;
          if ( v9.VStr )
            v9.VStr->Size = (v9.VStr->Size + 1) & 0x8FBFFFFF;
        }
        else if ( (v7->Flags & 0x1F) <= 0x11 )
        {
          v8.VObj = (Scaleform::GFx::AS3::Object *)v7->value.VS._2;
          if ( v8.VObj )
            v8.VObj->RefCount = (v8.VObj->RefCount + 1) & 0x8FBFFFFF;
        }
      }
    }
  }
  return result;
}

// File Line: 9138
// RVA: 0x7F8120
bool __fastcall Scaleform::GFx::AS3::Tracer::IsAnyType(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *tr)
{
  Scaleform::GFx::AS3::VM *VMRef; // r8

  VMRef = this->CF->pFile->VMRef;
  return tr == VMRef->TraitsObject.pObject->ITraits.pObject || tr == VMRef->TraitsClassClass.pObject->ITraits.pObject;
}

// File Line: 9150
// RVA: 0x7F8FC0
bool __fastcall Scaleform::GFx::AS3::Tracer::IsPrimitiveType(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *tr)
{
  Scaleform::GFx::AS3::VM *VMRef; // r8

  VMRef = this->CF->pFile->VMRef;
  return tr == VMRef->TraitsBoolean.pObject->ITraits.pObject
      || tr == VMRef->TraitsVoid.pObject
      || tr == VMRef->TraitsNull.pObject
      || tr == VMRef->TraitsInt.pObject->ITraits.pObject
      || tr == VMRef->TraitsUint.pObject->ITraits.pObject
      || tr == VMRef->TraitsNumber.pObject->ITraits.pObject
      || tr == VMRef->TraitsString.pObject->ITraits.pObject;
}

// File Line: 9156
// RVA: 0x7F8980
bool __fastcall Scaleform::GFx::AS3::Tracer::IsNotRefCountedType(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *tr)
{
  Scaleform::GFx::AS3::VM *VMRef; // r8

  VMRef = this->CF->pFile->VMRef;
  return tr == VMRef->TraitsBoolean.pObject->ITraits.pObject
      || tr == VMRef->TraitsVoid.pObject
      || tr == VMRef->TraitsNull.pObject
      || tr == VMRef->TraitsInt.pObject->ITraits.pObject
      || tr == VMRef->TraitsUint.pObject->ITraits.pObject
      || tr == VMRef->TraitsNumber.pObject->ITraits.pObject;
}

// File Line: 9165
// RVA: 0x7F8A80
bool __fastcall Scaleform::GFx::AS3::Tracer::IsNumericType(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *tr)
{
  Scaleform::GFx::AS3::VM *VMRef; // r8

  VMRef = this->CF->pFile->VMRef;
  return tr == VMRef->TraitsInt.pObject->ITraits.pObject
      || tr == VMRef->TraitsUint.pObject->ITraits.pObject
      || tr == VMRef->TraitsNumber.pObject->ITraits.pObject;
}

// File Line: 9172
// RVA: 0x7F8910
bool __fastcall Scaleform::GFx::AS3::Tracer::IsNotObjectType(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *tr)
{
  Scaleform::GFx::AS3::VM *VMRef; // r8

  VMRef = this->CF->pFile->VMRef;
  return tr == VMRef->TraitsInt.pObject->ITraits.pObject
      || tr == VMRef->TraitsUint.pObject->ITraits.pObject
      || tr == VMRef->TraitsNumber.pObject->ITraits.pObject
      || tr == VMRef->TraitsBoolean.pObject->ITraits.pObject
      || tr == VMRef->TraitsVoid.pObject
      || tr == VMRef->TraitsString.pObject->ITraits.pObject;
}

// File Line: 9185
// RVA: 0x829600
char __fastcall Scaleform::GFx::AS3::Tracer::ValueIsOfType(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::AS3::ClassTraits::Traits *type)
{
  unsigned int v4; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *InstanceTraits; // rax

  v4 = value->Flags & 0x1F;
  if ( v4 == 9 )
    return Scaleform::GFx::AS3::ClassTraits::Traits::IsOfType(value->value.VS._1.CTr, type);
  if ( v4 == 13 )
    return Scaleform::GFx::AS3::ClassTraits::Traits::IsOfType(
             (Scaleform::GFx::AS3::ClassTraits::Traits *)value->value.VS._1.VStr[1].pData,
             type);
  InstanceTraits = Scaleform::GFx::AS3::Tracer::GetInstanceTraits(this, value);
  return Scaleform::GFx::AS3::InstanceTraits::Traits::IsOfType(InstanceTraits, type->ITraits.pObject);
}

// File Line: 9221
// RVA: 0x80AFC0
void __fastcall Scaleform::GFx::AS3::Tracer::PushNewOpCode(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::Abc::Code::OpCode opcode)
{
  unsigned __int64 v2; // rsi
  unsigned __int64 Size; // r14
  unsigned __int64 v5; // rax
  unsigned __int64 v6; // rbx
  unsigned __int64 v7; // r8
  unsigned __int64 *Data; // rax
  Scaleform::GFx::AS3::MethodInfo *MI; // rbx
  unsigned __int64 v10; // rdi
  Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *p_Data; // rbx
  unsigned __int64 v12; // rdi
  unsigned __int64 v13; // r8
  unsigned __int64 *v14; // rax

  v2 = opcode;
  Scaleform::GFx::AS3::Tracer::CalcOpStackSize(this, opcode, 0i64, 0i64);
  Size = this->MI->OpCode.Data.Size;
  v5 = this->NewOpcodePos.Data.Size;
  v6 = v5 + 1;
  if ( v5 + 1 >= v5 )
  {
    if ( v6 <= this->NewOpcodePos.Data.Policy.Capacity )
      goto LABEL_7;
    v7 = v6 + (v6 >> 2);
  }
  else
  {
    if ( v6 >= this->NewOpcodePos.Data.Policy.Capacity >> 1 )
      goto LABEL_7;
    v7 = v5 + 1;
  }
  Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
    &this->NewOpcodePos.Data,
    this->NewOpcodePos.Data.pHeap,
    v7);
LABEL_7:
  Data = this->NewOpcodePos.Data.Data;
  this->NewOpcodePos.Data.Size = v6;
  Data[v6 - 1] = Size;
  MI = this->MI;
  v10 = MI->OpCode.Data.Size;
  p_Data = &MI->OpCode.Data;
  v12 = v10 + 1;
  if ( v12 >= p_Data->Size )
  {
    if ( v12 > p_Data->Policy.Capacity )
    {
      v13 = v12 + (v12 >> 2);
      goto LABEL_12;
    }
  }
  else if ( v12 < p_Data->Policy.Capacity >> 1 )
  {
    v13 = v12;
LABEL_12:
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      p_Data,
      p_Data,
      v13);
  }
  v14 = p_Data->Data;
  p_Data->Size = v12;
  v14[v12 - 1] = v2;
}

// File Line: 9236
// RVA: 0x80B240
void __fastcall Scaleform::GFx::AS3::Tracer::PushNewOpCode(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::Abc::Code::OpCode opcode,
        unsigned __int64 arg1)
{
  unsigned __int64 v3; // rbp
  unsigned __int64 Size; // r15
  unsigned __int64 v7; // rax
  unsigned __int64 v8; // rbx
  unsigned __int64 v9; // r8
  unsigned __int64 *Data; // rax
  Scaleform::GFx::AS3::MethodInfo *MI; // rbx
  unsigned __int64 v12; // rdi
  Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *p_Data; // rbx
  unsigned __int64 v14; // rdi
  unsigned __int64 v15; // r8
  unsigned __int64 *v16; // rax
  Scaleform::GFx::AS3::MethodInfo *v17; // rbx
  unsigned __int64 v18; // rdi
  Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *v19; // rbx
  unsigned __int64 v20; // rdi
  unsigned __int64 v21; // r8
  unsigned __int64 *v22; // rax

  v3 = opcode;
  Scaleform::GFx::AS3::Tracer::CalcOpStackSize(this, opcode, arg1, 0i64);
  Size = this->MI->OpCode.Data.Size;
  v7 = this->NewOpcodePos.Data.Size;
  v8 = v7 + 1;
  if ( v7 + 1 >= v7 )
  {
    if ( v8 <= this->NewOpcodePos.Data.Policy.Capacity )
      goto LABEL_7;
    v9 = v8 + (v8 >> 2);
  }
  else
  {
    if ( v8 >= this->NewOpcodePos.Data.Policy.Capacity >> 1 )
      goto LABEL_7;
    v9 = v7 + 1;
  }
  Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
    &this->NewOpcodePos.Data,
    this->NewOpcodePos.Data.pHeap,
    v9);
LABEL_7:
  Data = this->NewOpcodePos.Data.Data;
  this->NewOpcodePos.Data.Size = v8;
  Data[v8 - 1] = Size;
  MI = this->MI;
  v12 = MI->OpCode.Data.Size;
  p_Data = &MI->OpCode.Data;
  v14 = v12 + 1;
  if ( v14 >= p_Data->Size )
  {
    if ( v14 <= p_Data->Policy.Capacity )
      goto LABEL_13;
    v15 = v14 + (v14 >> 2);
  }
  else
  {
    if ( v14 >= p_Data->Policy.Capacity >> 1 )
      goto LABEL_13;
    v15 = v14;
  }
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
    p_Data,
    p_Data,
    v15);
LABEL_13:
  v16 = p_Data->Data;
  p_Data->Size = v14;
  v16[v14 - 1] = v3;
  v17 = this->MI;
  v18 = v17->OpCode.Data.Size;
  v19 = &v17->OpCode.Data;
  v20 = v18 + 1;
  if ( v20 >= v19->Size )
  {
    if ( v20 > v19->Policy.Capacity )
    {
      v21 = v20 + (v20 >> 2);
      goto LABEL_18;
    }
  }
  else if ( v20 < v19->Policy.Capacity >> 1 )
  {
    v21 = v20;
LABEL_18:
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v19,
      v19,
      v21);
  }
  v22 = v19->Data;
  v19->Size = v20;
  v22[v20 - 1] = arg1;
}

// File Line: 9252
// RVA: 0x80B3F0
void __fastcall Scaleform::GFx::AS3::Tracer::PushNewOpCodeNumber(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::Abc::Code::OpCode opcode,
        long double arg1)
{
  unsigned __int64 v3; // rbp
  unsigned __int64 Size; // r14
  unsigned __int64 v6; // rax
  unsigned __int64 v7; // rbx
  unsigned __int64 v8; // r8
  unsigned __int64 *Data; // rax
  Scaleform::GFx::AS3::MethodInfo *MI; // rbx
  unsigned __int64 v11; // rdi
  Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *p_Data; // rbx
  unsigned __int64 v13; // rdi
  unsigned __int64 v14; // r8
  unsigned __int64 *v15; // rax
  Scaleform::GFx::AS3::MethodInfo *v16; // rbx
  unsigned __int64 v17; // rdi
  Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *v18; // rbx
  unsigned __int64 v19; // rdi
  unsigned __int64 v20; // r8
  unsigned __int64 *v21; // rcx

  v3 = opcode;
  Scaleform::GFx::AS3::Tracer::CalcOpStackSize(this, opcode, 0i64, 0i64);
  Size = this->MI->OpCode.Data.Size;
  v6 = this->NewOpcodePos.Data.Size;
  v7 = v6 + 1;
  if ( v6 + 1 >= v6 )
  {
    if ( v7 <= this->NewOpcodePos.Data.Policy.Capacity )
      goto LABEL_7;
    v8 = v7 + (v7 >> 2);
  }
  else
  {
    if ( v7 >= this->NewOpcodePos.Data.Policy.Capacity >> 1 )
      goto LABEL_7;
    v8 = v6 + 1;
  }
  Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
    &this->NewOpcodePos.Data,
    this->NewOpcodePos.Data.pHeap,
    v8);
LABEL_7:
  Data = this->NewOpcodePos.Data.Data;
  this->NewOpcodePos.Data.Size = v7;
  Data[v7 - 1] = Size;
  MI = this->MI;
  v11 = MI->OpCode.Data.Size;
  p_Data = &MI->OpCode.Data;
  v13 = v11 + 1;
  if ( v13 >= p_Data->Size )
  {
    if ( v13 <= p_Data->Policy.Capacity )
      goto LABEL_13;
    v14 = v13 + (v13 >> 2);
  }
  else
  {
    if ( v13 >= p_Data->Policy.Capacity >> 1 )
      goto LABEL_13;
    v14 = v13;
  }
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
    p_Data,
    p_Data,
    v14);
LABEL_13:
  v15 = p_Data->Data;
  p_Data->Size = v13;
  v15[v13 - 1] = v3;
  v16 = this->MI;
  v17 = v16->OpCode.Data.Size;
  v18 = &v16->OpCode.Data;
  v19 = v17 + 1;
  if ( v19 >= v18->Size )
  {
    if ( v19 > v18->Policy.Capacity )
    {
      v20 = v19 + (v19 >> 2);
      goto LABEL_18;
    }
  }
  else if ( v19 < v18->Policy.Capacity >> 1 )
  {
    v20 = v19;
LABEL_18:
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v18,
      v18,
      v20);
  }
  v21 = v18->Data;
  v18->Size = v19;
  *(long double *)&v21[v19 - 1] = arg1;
}

// File Line: 9295
// RVA: 0x80B0B0
void __fastcall Scaleform::GFx::AS3::Tracer::PushNewOpCode(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::Abc::Code::OpCode opcode,
        unsigned __int64 arg1,
        unsigned __int64 arg2)
{
  unsigned __int64 v4; // rbp
  unsigned __int64 Size; // r14
  unsigned __int64 v9; // rax
  unsigned __int64 v10; // rbx
  unsigned __int64 v11; // r8
  unsigned __int64 *Data; // rax
  Scaleform::GFx::AS3::MethodInfo *MI; // rbx
  unsigned __int64 v14; // rdi
  Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *p_Data; // rbx
  unsigned __int64 v16; // rdi
  unsigned __int64 v17; // r8
  unsigned __int64 *v18; // rax
  Scaleform::GFx::AS3::MethodInfo *v19; // rbx
  unsigned __int64 v20; // rdi
  Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *v21; // rbx
  unsigned __int64 v22; // rdi
  unsigned __int64 v23; // r8
  unsigned __int64 *v24; // rax
  Scaleform::GFx::AS3::MethodInfo *v25; // rbx
  unsigned __int64 v26; // rdi
  Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *v27; // rbx
  unsigned __int64 v28; // rdi
  unsigned __int64 v29; // r8
  unsigned __int64 *v30; // rax

  v4 = opcode;
  Scaleform::GFx::AS3::Tracer::CalcOpStackSize(this, opcode, arg1, arg2);
  Size = this->MI->OpCode.Data.Size;
  v9 = this->NewOpcodePos.Data.Size;
  v10 = v9 + 1;
  if ( v9 + 1 >= v9 )
  {
    if ( v10 <= this->NewOpcodePos.Data.Policy.Capacity )
      goto LABEL_7;
    v11 = v10 + (v10 >> 2);
  }
  else
  {
    if ( v10 >= this->NewOpcodePos.Data.Policy.Capacity >> 1 )
      goto LABEL_7;
    v11 = v9 + 1;
  }
  Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
    &this->NewOpcodePos.Data,
    this->NewOpcodePos.Data.pHeap,
    v11);
LABEL_7:
  Data = this->NewOpcodePos.Data.Data;
  this->NewOpcodePos.Data.Size = v10;
  Data[v10 - 1] = Size;
  MI = this->MI;
  v14 = MI->OpCode.Data.Size;
  p_Data = &MI->OpCode.Data;
  v16 = v14 + 1;
  if ( v16 >= p_Data->Size )
  {
    if ( v16 <= p_Data->Policy.Capacity )
      goto LABEL_13;
    v17 = v16 + (v16 >> 2);
  }
  else
  {
    if ( v16 >= p_Data->Policy.Capacity >> 1 )
      goto LABEL_13;
    v17 = v16;
  }
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
    p_Data,
    p_Data,
    v17);
LABEL_13:
  v18 = p_Data->Data;
  p_Data->Size = v16;
  v18[v16 - 1] = v4;
  v19 = this->MI;
  v20 = v19->OpCode.Data.Size;
  v21 = &v19->OpCode.Data;
  v22 = v20 + 1;
  if ( v22 >= v21->Size )
  {
    if ( v22 <= v21->Policy.Capacity )
      goto LABEL_19;
    v23 = v22 + (v22 >> 2);
  }
  else
  {
    if ( v22 >= v21->Policy.Capacity >> 1 )
      goto LABEL_19;
    v23 = v22;
  }
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
    v21,
    v21,
    v23);
LABEL_19:
  v24 = v21->Data;
  v21->Size = v22;
  v24[v22 - 1] = arg1;
  v25 = this->MI;
  v26 = v25->OpCode.Data.Size;
  v27 = &v25->OpCode.Data;
  v28 = v26 + 1;
  if ( v28 >= v27->Size )
  {
    if ( v28 > v27->Policy.Capacity )
    {
      v29 = v28 + (v28 >> 2);
      goto LABEL_24;
    }
  }
  else if ( v28 < v27->Policy.Capacity >> 1 )
  {
    v29 = v28;
LABEL_24:
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v27,
      v27,
      v29);
  }
  v30 = v27->Data;
  v27->Size = v28;
  v30[v28 - 1] = arg2;
}

// File Line: 9312
// RVA: 0x7B2320
void __fastcall Scaleform::GFx::AS3::Tracer::CalcOpStackSize(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::Abc::Code::OpCode opcode,
        unsigned __int64 arg1,
        unsigned __int64 arg2)
{
  unsigned int v6; // r10d
  char v7; // dl
  int v8; // r10d
  Scaleform::GFx::AS3::TR::Block *CurrBlock; // rcx
  unsigned __int64 CurOpStackSize; // rdx
  Scaleform::GFx::AS3::MethodInfo *MI; // rcx

  v6 = (unsigned int)Scaleform::GFx::AS3::Abc::Code::opcode_info[opcode];
  v7 = byte_14182DEC1[2 * opcode];
  v8 = -((v6 >> 5) & 3);
  if ( (v7 & 8) != 0 )
  {
    switch ( this->CF->pFile->File.pObject->Const_Pool.const_multiname.Data.Data[arg1].Kind )
    {
      case MN_RTQName:
      case MN_MultinameL:
      case MN_RTQNameA:
      case MN_MultinameLA:
        --v8;
        break;
      case MN_RTQNameL:
      case MN_RTQNameLA:
        v8 -= 2;
        break;
      default:
        break;
    }
  }
  if ( (v7 & 4) != 0 )
  {
    if ( opcode == op_newobject )
      v8 -= 2 * arg2;
    else
      v8 -= arg2;
  }
  CurrBlock = this->CurrBlock;
  CurrBlock->CurOpStackSize += v8 + (v7 & 3);
  CurOpStackSize = CurrBlock->CurOpStackSize;
  MI = this->MI;
  if ( CurOpStackSize < MI->MaxOpStackSize )
    CurOpStackSize = MI->MaxOpStackSize;
  MI->MaxOpStackSize = CurOpStackSize;
}

// File Line: 9381
// RVA: 0x80B380
void __fastcall Scaleform::GFx::AS3::Tracer::PushNewOpCodeArg0(Scaleform::GFx::AS3::Tracer *this, unsigned __int64 arg)
{
  Scaleform::GFx::AS3::MethodInfo *MI; // rbx
  unsigned __int64 Size; // rdi
  Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *p_Data; // rbx
  unsigned __int64 v6; // rdi
  unsigned __int64 v7; // r8
  unsigned __int64 *Data; // rax

  MI = this->MI;
  Size = MI->OpCode.Data.Size;
  p_Data = &MI->OpCode.Data;
  v6 = Size + 1;
  if ( v6 >= p_Data->Size )
  {
    if ( v6 > p_Data->Policy.Capacity )
    {
      v7 = v6 + (v6 >> 2);
      goto LABEL_6;
    }
  }
  else if ( v6 < p_Data->Policy.Capacity >> 1 )
  {
    v7 = v6;
LABEL_6:
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      p_Data,
      p_Data,
      v7);
  }
  Data = p_Data->Data;
  p_Data->Size = v6;
  Data[v6 - 1] = arg;
}

