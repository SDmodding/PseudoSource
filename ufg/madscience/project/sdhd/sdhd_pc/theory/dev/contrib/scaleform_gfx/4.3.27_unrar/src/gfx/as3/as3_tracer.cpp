// File Line: 93
// RVA: 0x80EAC0
int __fastcall Scaleform::GFx::AS3::TR::StackReader::Read(Scaleform::GFx::AS3::TR::StackReader *this, Scaleform::GFx::AS3::Multiname *obj)
{
  Scaleform::GFx::AS3::Multiname *v2; // rsi
  Scaleform::GFx::AS3::TR::StackReader *v3; // rdi
  bool v4; // zf
  int v5; // eax
  Scaleform::GFx::AS3::Value *v6; // rax
  Scaleform::GFx::AS3::Value *v7; // rax
  Scaleform::GFx::AS3::Value v8; // [rsp+18h] [rbp-39h]
  Scaleform::GFx::AS3::Value v9; // [rsp+38h] [rbp-19h]
  Scaleform::GFx::AS3::Value v10; // [rsp+58h] [rbp+7h]
  __int64 v11; // [rsp+78h] [rbp+27h]
  Scaleform::GFx::AS3::Value result; // [rsp+80h] [rbp+2Fh]

  v11 = -2i64;
  v2 = obj;
  v3 = this;
  switch ( obj->Kind )
  {
    case 1:
    case 9:
      Scaleform::GFx::AS3::TR::State::PopOpValue(this->StateRef, &result);
      if ( (result.Flags & 0x1F) > 9 )
      {
        if ( (result.Flags >> 9) & 1 )
        {
          v4 = result.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v4 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
        }
      }
      goto LABEL_7;
    case 5:
    case 0xD:
      Scaleform::GFx::AS3::TR::State::PopOpValue(this->StateRef, &v10);
      if ( (v10.Flags & 0x1F) > 9 )
      {
        if ( (v10.Flags >> 9) & 1 )
        {
          v4 = v10.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v4 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          v10.Bonus.pWeakProxy = 0i64;
          v10.value = 0ui64;
          v10.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v10);
        }
      }
      v6 = Scaleform::GFx::AS3::TR::State::PopOpValue(v3->StateRef, &v9);
      Scaleform::GFx::AS3::Value::Assign(&v2->Name, v6);
      if ( (v9.Flags & 0x1F) > 9 )
      {
        if ( (v9.Flags >> 9) & 1 )
        {
          v4 = v9.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v4 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          v9.Bonus.pWeakProxy = 0i64;
          v9.value = 0ui64;
          v9.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v9);
        }
      }
      return 2;
    case 6:
    case 0xE:
      v7 = Scaleform::GFx::AS3::TR::State::PopOpValue(this->StateRef, &v8);
      Scaleform::GFx::AS3::Value::Assign(&v2->Name, v7);
      if ( (v8.Flags & 0x1F) <= 9 )
        goto LABEL_7;
      if ( (v8.Flags >> 9) & 1 )
      {
        v4 = v8.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v4 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v8.Bonus.pWeakProxy = 0i64;
        v8.value = 0ui64;
        v8.Flags &= 0xFFFFFDE0;
LABEL_7:
        v5 = 1;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v8);
        v5 = 1;
      }
      break;
    case 0x10:
      this->VMRef->UI->vfptr->Output(this->VMRef->UI, Output_Warning, "Reading chained multiname in itself.");
      v5 = Scaleform::GFx::AS3::TR::StackReader::Read(v3, v2);
      break;
    default:
      v5 = 0;
      break;
  }
  return v5;
}

// File Line: 164
// RVA: 0x781960
void __fastcall Scaleform::GFx::AS3::TR::ReadArgs::ReadArgs(Scaleform::GFx::AS3::TR::ReadArgs *this, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::TR::State *s, unsigned int arg_count)
{
  __int64 v4; // r13
  Scaleform::GFx::AS3::TR::ReadArgs *v5; // r14
  unsigned int v6; // ebp
  Scaleform::MemoryHeap *v7; // rax
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *v8; // r15
  unsigned __int64 v9; // rsi
  unsigned __int64 v10; // rdi
  signed __int64 v11; // rbx
  __int64 v12; // rsi
  signed __int64 v13; // r12
  __int64 v14; // rsi
  Scaleform::GFx::AS3::Value *v15; // rbx
  Scaleform::GFx::AS3::TR::State *v16; // rbx
  unsigned __int64 v17; // rsi
  signed __int64 v18; // rax
  unsigned __int64 i; // rdi

  v4 = arg_count;
  v5 = this;
  this->VMRef = vm;
  this->StateRef = s;
  v6 = 0;
  this->Num = 0;
  this->ArgNum = arg_count;
  v7 = vm->MHeap;
  v8 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&this->CallArgs.Data.Data;
  v8->Data = 0i64;
  v8->Size = 0i64;
  v8->Policy.Capacity = 0i64;
  this->CallArgs.Data.pHeap = v7;
  `eh vector constructor iterator(
    this->FixedArr,
    0x20ui64,
    8,
    (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::Value);
  if ( (_DWORD)v4 )
  {
    v9 = v5->StateRef->OpStack.Data.Size;
    v10 = v9 - v4;
    if ( (unsigned int)v4 > 8 )
    {
      if ( v10 < v9 )
      {
        v13 = v10;
        v14 = v4;
        do
        {
          v15 = &v5->StateRef->OpStack.Data.Data[v13];
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
            v8,
            v8[1].Data,
            v8->Size + 1);
          Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(&v8->Data[v8->Size - 1], v15);
          ++v13;
          --v14;
        }
        while ( v14 );
      }
    }
    else if ( v10 < v9 )
    {
      v11 = v10;
      v12 = v4;
      do
      {
        Scaleform::GFx::AS3::Value::Assign(
          (Scaleform::GFx::AS3::Value *)v5 + v6 + 2i64,
          &v5->StateRef->OpStack.Data.Data[v11]);
        ++v11;
        ++v6;
        --v12;
      }
      while ( v12 );
    }
    v16 = v5->StateRef;
    v17 = v16->OpStack.Data.Size;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v16->OpStack.Data.Data,
      v16->OpStack.Data.pHeap,
      v10);
    if ( v10 > v17 )
    {
      v18 = (signed __int64)&v16->OpStack.Data.Data[v17];
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
  v5->Num += v4;
}

// File Line: 193
// RVA: 0x83D460
void __fastcall Scaleform::GFx::AS3::TR::State::exec_construct(Scaleform::GFx::AS3::TR::State *this, unsigned int arg_count)
{
  unsigned int v2; // ebx
  Scaleform::GFx::AS3::TR::State *v3; // rdi
  Scaleform::GFx::AS3::Tracer *v4; // r14
  int v5; // ebx
  long double v6; // rsi
  Scaleform::GFx::AS3::Traits *v7; // rcx
  Scaleform::GFx::AS3::VM *v8; // rax
  int v9; // ebx
  int v10; // ebx
  int v11; // ebx
  signed __int64 v12; // rcx
  signed __int64 v13; // rdx
  bool v14; // zf
  __int64 v15; // rdx
  int v16; // eax
  Scaleform::GFx::AS3::Value::V2U v17; // rax
  long double v18; // rcx
  char v19; // al
  long double v20; // rax
  Scaleform::GFx::AS3::Value source; // [rsp+20h] [rbp-C8h]
  __int64 v22; // [rsp+40h] [rbp-A8h]
  Scaleform::GFx::AS3::TR::ReadArgs v23; // [rsp+50h] [rbp-98h]
  Scaleform::GFx::AS3::Value::V2U v24; // [rsp+190h] [rbp+A8h]
  __int64 v25; // [rsp+1B8h] [rbp+D0h]
  __int64 retaddr; // [rsp+1C8h] [rbp+E0h]

  v22 = -2i64;
  v2 = arg_count;
  v3 = this;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_construct, arg_count);
  Scaleform::GFx::AS3::TR::ReadArgs::ReadArgs(&v23, v3->pTracer->CF->pFile->VMRef, v3, v2);
  Scaleform::GFx::AS3::TR::State::PopOpValue(v3, (Scaleform::GFx::AS3::Value *)((char *)&v23.FixedArr[7] + 8));
  ++v23.Num;
  v4 = v3->pTracer;
  v5 = (_QWORD)v23.FixedArr[7].Bonus.pWeakProxy & 0x1F;
  v6 = *(double *)&v23.FixedArr[7].value.VS._2.VObj;
  if ( (_QWORD)v23.FixedArr[7].Bonus.pWeakProxy & 0x1F )
  {
    if ( ((_QWORD)v23.FixedArr[7].Bonus.pWeakProxy & 0x1F) == 8
      || ((_QWORD)v23.FixedArr[7].Bonus.pWeakProxy & 0x1F) == 9 )
    {
      v7 = v23.FixedArr[7].value.VS._2.pTraits;
    }
    else
    {
      v7 = Scaleform::GFx::AS3::VM::GetValueTraits(
             v4->CF->pFile->VMRef,
             (Scaleform::GFx::AS3::Value *)((char *)&v23.FixedArr[7] + 8));
    }
  }
  else
  {
    v7 = (Scaleform::GFx::AS3::Traits *)&v4->CF->pFile->VMRef->TraitsVoid.pObject->vfptr;
  }
  if ( v7 )
  {
    v8 = v4->CF->pFile->VMRef;
    if ( v7 == (Scaleform::GFx::AS3::Traits *)v8->TraitsClassClass.pObject )
      v7 = (Scaleform::GFx::AS3::Traits *)&v8->TraitsObject.pObject->vfptr;
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
          v18 = *(double *)(*(_QWORD *)(*(_QWORD *)&v6 + 40i64) + 200i64);
          source.Bonus.pWeakProxy = 0i64;
          source.value.VNumber = v18;
          source.Flags = 8;
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
            (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v3->OpStack.Data.Data,
            v3->OpStack.Data.pHeap,
            v3->OpStack.Data.Size + 1);
          Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
            &v3->OpStack.Data.Data[v3->OpStack.Data.Size - 1],
            &source);
        }
        else
        {
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
            (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v3->OpStack.Data.Data,
            v3->OpStack.Data.pHeap,
            v3->OpStack.Data.Size + 1);
          v12 = 32 * v3->OpStack.Data.Size;
          v13 = (signed __int64)&v3->OpStack.Data.Data[-1];
          v14 = v12 + v13 == 0;
          v15 = v12 + v13;
          v25 = v15;
          retaddr = v15;
          if ( !v14 )
          {
            *(_DWORD *)v15 = v23.FixedArr[7].Bonus.pWeakProxy;
            *(long double *)(v15 + 8) = v23.FixedArr[7].value.VNumber;
            *(_OWORD *)(v15 + 16) = *(_OWORD *)&v23.FixedArr[7].value.VS._2.VObj;
            v16 = (_QWORD)v23.FixedArr[7].Bonus.pWeakProxy & 0x1F;
            if ( v16 > 9 )
            {
              if ( (LODWORD(v23.FixedArr[7].Bonus.pWeakProxy) >> 9) & 1 )
              {
                ++v23.FixedArr[7].value.VS._1.VStr->pData;
              }
              else
              {
                if ( v16 == 10 )
                {
                  ++LODWORD(v23.FixedArr[7].value.VS._2.VObj->pPrev);
                  goto LABEL_35;
                }
                if ( v16 > 10 )
                {
                  if ( v16 <= 15 )
                  {
                    v17.VObj = (Scaleform::GFx::AS3::Object *)v23.FixedArr[7].value.VS._2;
                  }
                  else
                  {
                    if ( v16 > 17 )
                      goto LABEL_35;
                    v17.VObj = v24.VObj;
                  }
                  if ( v17.VObj )
                  {
                    ++v17.VObj->RefCount;
                    v17.VObj->RefCount &= 0x8FBFFFFF;
                  }
                }
              }
            }
          }
        }
      }
      else
      {
        v19 = ~(LOBYTE(v7->Flags) >> 5);
        source.Bonus.pWeakProxy = 0i64;
        *(_QWORD *)&source.value.VNumber = v7;
        if ( v19 & 1 )
          source.Flags = 8;
        else
          source.Flags = 9;
        Scaleform::GFx::AS3::TR::State::PushOp(v3, &source);
      }
    }
    else
    {
      v20 = *(double *)(*(_QWORD *)&v6 + 200i64);
      source.Bonus.pWeakProxy = 0i64;
      source.value.VNumber = v20;
      source.Flags = 8;
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v3->OpStack.Data.Data,
        v3->OpStack.Data.pHeap,
        v3->OpStack.Data.Size + 1);
      Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
        &v3->OpStack.Data.Data[v3->OpStack.Data.Size - 1],
        &source);
    }
  }
  else
  {
    source.Bonus.pWeakProxy = 0i64;
    source.value.VNumber = v6;
    source.Flags = 8;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v3->OpStack.Data.Data,
      v3->OpStack.Data.pHeap,
      v3->OpStack.Data.Size + 1);
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
      &v3->OpStack.Data.Data[v3->OpStack.Data.Size - 1],
      &source);
  }
LABEL_35:
  Scaleform::GFx::AS3::TR::ReadArgsObject::~ReadArgsObject((Scaleform::GFx::AS3::TR::ReadArgsObject *)&v23);
}

// File Line: 266
// RVA: 0x83E320
void __fastcall Scaleform::GFx::AS3::TR::State::exec_constructsuper(Scaleform::GFx::AS3::TR::State *this, unsigned int arg_count)
{
  unsigned int v2; // ebx
  Scaleform::GFx::AS3::TR::State *v3; // rdi
  Scaleform::GFx::AS3::TR::ReadArgs v4; // [rsp+30h] [rbp-168h]
  Scaleform::GFx::AS3::Value result; // [rsp+170h] [rbp-28h]

  v2 = arg_count;
  v3 = this;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_constructsuper, arg_count);
  Scaleform::GFx::AS3::TR::ReadArgs::ReadArgs(&v4, v3->pTracer->CF->pFile->VMRef, v3, v2);
  Scaleform::GFx::AS3::TR::State::PopOpValue(v3, &result);
  ++v4.Num;
  Scaleform::GFx::AS3::TR::ReadArgsObject::~ReadArgsObject((Scaleform::GFx::AS3::TR::ReadArgsObject *)&v4);
}

// File Line: 277
// RVA: 0x7E9DB0
Scaleform::GFx::AS3::InstanceTraits::Thunk *__fastcall Scaleform::GFx::AS3::TR::State::GetFunctType(Scaleform::GFx::AS3::TR::State *this, Scaleform::GFx::AS3::Value *value)
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
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::TR::State::GetPropertyType(Scaleform::GFx::AS3::TR::State *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::Traits *obj_traits, Scaleform::GFx::AS3::SlotInfo *si, Scaleform::GFx::AS3::Value *type)
{
  Scaleform::GFx::AS3::SlotInfo *v5; // rdi
  Scaleform::GFx::AS3::CheckResult *v6; // rsi
  Scaleform::GFx::AS3::TR::State *v7; // r14
  __int64 v8; // rcx
  signed int v9; // eax
  Scaleform::GFx::AS3::AbsoluteIndex v10; // rbx
  Scaleform::GFx::AS3::VTable *v11; // rax
  Scaleform::GFx::AS3::Value *v12; // rax
  Scaleform::GFx::AS3::InstanceTraits::Thunk *v13; // rbx
  bool v14; // zf
  int v15; // eax
  Scaleform::GFx::AS3::VMAppDomain *v16; // rdi
  Scaleform::GFx::AS3::VTable *v17; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v18; // rbx
  Scaleform::GFx::AS3::VM *v19; // rbx
  Scaleform::GFx::AS3::ClassTraits::Traits *v20; // r15
  Scaleform::GFx::AS3::VM::Error *v21; // rax
  Scaleform::GFx::ASStringNode *v22; // rcx
  Scaleform::GFx::AS3::Abc::TraitInfo *v23; // rax
  long double v24; // rbx
  int v25; // eax
  unsigned int v26; // ebx
  Scaleform::GFx::AS3::Value resulta; // [rsp+28h] [rbp-28h]

  v5 = si;
  v6 = result;
  v7 = this;
  v8 = *(_DWORD *)si;
  v9 = *(_DWORD *)si << 17 >> 27;
  if ( v9 > 10 )
  {
    v10.Index = v8 >> 15;
    if ( v8 >> 15 >= 0 )
    {
      if ( v9 == 11 )
      {
        v11 = Scaleform::GFx::AS3::Traits::GetVT(obj_traits);
        v12 = Scaleform::GFx::AS3::VTable::GetValue(v11, &resulta, v10);
        v13 = Scaleform::GFx::AS3::TR::State::GetFunctType(v7, v12);
        if ( (resulta.Flags & 0x1F) > 9 )
        {
          if ( (resulta.Flags >> 9) & 1 )
          {
            v14 = resulta.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v14 )
              ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            resulta.Bonus.pWeakProxy = 0i64;
            resulta.value = 0ui64;
            resulta.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&resulta);
          }
        }
        v15 = Scaleform::GFx::AS3::TR::State::CanBeNull(v7, (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v13->vfptr);
        resulta.Bonus.pWeakProxy = 0i64;
        *(_QWORD *)&resulta.value.VNumber = v13;
        resulta.Flags = (32 * v15 | 8) & 0xFFFFFEFF;
        Scaleform::GFx::AS3::Value::Assign(type, &resulta);
      }
      else
      {
        v16 = v7->pTracer->CF->pFile->AppDomain.pObject;
        v17 = Scaleform::GFx::AS3::Traits::GetVT(obj_traits);
        v18 = Scaleform::GFx::AS3::VM::GetFunctReturnType(
                v7->pTracer->CF->pFile->VMRef,
                &v17->VTMethods.Data.Data[LODWORD(v10.Index)],
                v16);
        resulta.Bonus.pWeakProxy = 0i64;
        *(_QWORD *)&resulta.value.VNumber = v18;
        resulta.Flags = (32 * (unsigned __int64)Scaleform::GFx::AS3::TR::State::CanBeNull(v7, v18) | 8) & 0xFFFFFEFF;
        Scaleform::GFx::AS3::Value::Assign(type, &resulta);
      }
      goto LABEL_22;
    }
  }
  v19 = v7->pTracer->CF->pFile->VMRef;
  v20 = Scaleform::GFx::AS3::SlotInfo::GetDataType(si, v19);
  if ( v20 )
  {
    if ( (*(_DWORD *)v5 & 0x7C00) == 1024
      || (v23 = v5->TI) != 0i64 && (v23->kind & 0xF) == 4
      || Scaleform::GFx::AS3::SlotInfo::IsClassType(v5) )
    {
      resulta.Bonus.pWeakProxy = 0i64;
      *(_QWORD *)&resulta.value.VNumber = v20;
      resulta.Flags = 9;
      Scaleform::GFx::AS3::Value::Assign(type, &resulta);
    }
    else
    {
      v24 = *(double *)&v20->ITraits.pObject;
      v25 = Scaleform::GFx::AS3::TR::State::CanBeNull(v7, v20->ITraits.pObject);
      resulta.Bonus.pWeakProxy = 0i64;
      resulta.value.VNumber = v24;
      resulta.Flags = (32 * v25 | 8) & 0xFFFFFEFF;
      Scaleform::GFx::AS3::Value::Assign(type, &resulta);
    }
LABEL_22:
    v26 = resulta.Flags;
    if ( (resulta.Flags & 0x1F) > 9 )
    {
      if ( (resulta.Flags >> 9) & 1 )
      {
        v14 = resulta.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v14 )
          ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        resulta.Flags = v26 & 0xFFFFFDE0;
        resulta.value = 0ui64;
        resulta.Bonus.pWeakProxy = 0i64;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&resulta);
      }
    }
    v6->Result = 1;
    return v6;
  }
  Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&resulta, eClassNotFoundError, v19);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(v19, v21, &Scaleform::GFx::AS3::fl::VerifyErrorTI);
  v22 = (Scaleform::GFx::ASStringNode *)resulta.Bonus.pWeakProxy;
  v14 = LODWORD(resulta.Bonus.pWeakProxy[1].pObject) == 1;
  --v22->RefCount;
  if ( v14 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v22);
  v6->Result = 0;
  return v6;
}

// File Line: 337
// RVA: 0x839480
void __fastcall Scaleform::GFx::AS3::TR::State::exec_call(Scaleform::GFx::AS3::TR::State *this, unsigned int arg_count)
{
  unsigned int v2; // ebx
  Scaleform::GFx::AS3::TR::State *v3; // rsi
  Scaleform::GFx::AS3::VMAbcFile *v4; // rcx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v5; // rax
  long double v6; // r8
  Scaleform::GFx::AS3::VMAbcFile *v7; // r9
  Scaleform::GFx::AS3::VM *v8; // rcx
  char v9; // al
  signed int v10; // edi
  unsigned int v11; // edi
  __int64 v12; // r8
  __int64 v13; // r9
  Scaleform::GFx::AS3::WeakProxy *v14; // rdx
  bool v15; // zf
  Scaleform::GFx::AS3::Value source; // [rsp+20h] [rbp-D8h]
  __int64 v17; // [rsp+40h] [rbp-B8h]
  Scaleform::GFx::AS3::TR::ReadArgs v18; // [rsp+50h] [rbp-A8h]
  Scaleform::GFx::AS3::Value result; // [rsp+1A8h] [rbp+B0h]

  v17 = -2i64;
  v2 = arg_count;
  v3 = this;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_call, arg_count);
  Scaleform::GFx::AS3::TR::ReadArgs::ReadArgs(&v18, v3->pTracer->CF->pFile->VMRef, v3, v2);
  Scaleform::GFx::AS3::TR::State::PopOpValue(v3, (Scaleform::GFx::AS3::Value *)((char *)&v18.FixedArr[7] + 24));
  ++v18.Num;
  Scaleform::GFx::AS3::TR::State::PopOpValue(v3, &result);
  ++v18.Num;
  v4 = v3->pTracer->CF->pFile;
  v5 = Scaleform::GFx::AS3::VM::GetFunctReturnType(v4->VMRef, &result, v4->AppDomain.pObject);
  v6 = *(double *)&v5;
  v7 = v3->pTracer->CF->pFile;
  v8 = v7->VMRef;
  if ( v5 == v8->TraitsInt.pObject->ITraits.pObject
    || v5 == v8->TraitsUint.pObject->ITraits.pObject
    || v5 == v8->TraitsNumber.pObject->ITraits.pObject
    || (v9 = 0, *(Scaleform::GFx::AS3::InstanceTraits::Traits **)&v6 == v7->VMRef->TraitsBoolean.pObject->ITraits.pObject) )
  {
    v9 = 1;
  }
  source.Flags = 8;
  source.Bonus.pWeakProxy = 0i64;
  source.value.VNumber = v6;
  v10 = 2;
  if ( v9 )
    v10 = 0;
  v11 = (32 * v10 | 8) & 0xFFFFFEFF;
  source.Flags = v11;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v3->OpStack.Data.Data,
    v3->OpStack.Data.pHeap,
    v3->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &v3->OpStack.Data.Data[v3->OpStack.Data.Size - 1],
    &source);
  if ( (char)(v11 & 0x1F) > 9 )
  {
    if ( (v11 >> 9) & 1 )
    {
      LODWORD(MEMORY[0]) = MEMORY[0] - 1;
      if ( !(_DWORD)MEMORY[0] )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
      source.Bonus.pWeakProxy = 0i64;
      source.value = 0ui64;
      source.Flags = v11 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&source);
    }
  }
  if ( (result.Flags & 0x1F) > 9 )
  {
    if ( (result.Flags >> 9) & 1 )
    {
      v14 = result.Bonus.pWeakProxy;
      v15 = result.Bonus.pWeakProxy->RefCount == 1;
      --v14->RefCount;
      if ( v15 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::WeakProxy *, __int64, __int64, _QWORD))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v14,
          v12,
          v13,
          *(_QWORD *)&source.Flags);
      result.Bonus.pWeakProxy = 0i64;
      _mm_store_si128((__m128i *)&result.value, (__m128i)0i64);
      result.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
    }
  }
  Scaleform::GFx::AS3::TR::ReadArgsObject::~ReadArgsObject((Scaleform::GFx::AS3::TR::ReadArgsObject *)&v18);
}

// File Line: 402
// RVA: 0x838D30
void __fastcall Scaleform::GFx::AS3::TR::State::exec_applytype(Scaleform::GFx::AS3::TR::State *this, unsigned int arg_count)
{
  unsigned int v2; // ebx
  Scaleform::GFx::AS3::TR::State *v3; // rsi
  Scaleform::GFx::AS3::VM *v4; // rdi
  Scaleform::GFx::AS3::Value *v5; // rdx
  long double v6; // rbx
  Scaleform::GFx::AS3::ClassTraits::Traits *v7; // rax
  Scaleform::GFx::AS3::Classes::fl_vec::Vector **v8; // rdi
  Scaleform::GFx::AS3::Value source; // [rsp+20h] [rbp-198h]
  __int64 v10; // [rsp+40h] [rbp-178h]
  Scaleform::GFx::AS3::TR::ReadArgs v11; // [rsp+50h] [rbp-168h]
  Scaleform::GFx::AS3::Value result; // [rsp+190h] [rbp-28h]

  v10 = -2i64;
  v2 = arg_count;
  v3 = this;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_applytype, arg_count);
  v4 = v3->pTracer->CF->pFile->VMRef;
  Scaleform::GFx::AS3::TR::ReadArgs::ReadArgs(&v11, v4, v3, v2);
  Scaleform::GFx::AS3::TR::State::PopOpValue(v3, &result);
  ++v11.Num;
  v5 = v11.FixedArr;
  if ( v11.ArgNum <= v11.CallArgs.Data.Size )
    v5 = v11.CallArgs.Data.Data;
  v6 = 0.0;
  switch ( v5->Flags & 0x1F )
  {
    case 0u:
LABEL_11:
      v6 = *(double *)&v4->TraitsObject.pObject;
      break;
    case 9u:
      v6 = v5->value.VNumber;
      break;
    case 12u:
      if ( *(_QWORD *)&v5->value.VNumber )
        break;
      goto LABEL_11;
    case 13u:
      v6 = *(double *)(*(_QWORD *)&v5->value.VNumber + 40i64);
      break;
  }
  v7 = (Scaleform::GFx::AS3::ClassTraits::Traits *)&v4->TraitsObject.pObject->vfptr;
  if ( v6 != 0.0 )
  {
    switch ( *(_DWORD *)(*(_QWORD *)&v6 + 120i64) )
    {
      case 2:
        v7 = (Scaleform::GFx::AS3::ClassTraits::Traits *)&v4->TraitsVector_int.pObject->vfptr;
        break;
      case 3:
        v7 = (Scaleform::GFx::AS3::ClassTraits::Traits *)&v4->TraitsVector_uint.pObject->vfptr;
        break;
      case 4:
        v7 = (Scaleform::GFx::AS3::ClassTraits::Traits *)&v4->TraitsVector_Number.pObject->vfptr;
        break;
      case 5:
        v7 = (Scaleform::GFx::AS3::ClassTraits::Traits *)&v4->TraitsVector_String.pObject->vfptr;
        break;
      default:
        v8 = (Scaleform::GFx::AS3::Classes::fl_vec::Vector **)v4->TraitsVector.pObject->ITraits.pObject;
        if ( !v8[17] )
          ((void (__fastcall *)(Scaleform::GFx::AS3::Classes::fl_vec::Vector **))(*v8)[1]._pRCC)(v8);
        v7 = Scaleform::GFx::AS3::Classes::fl_vec::Vector::Resolve2Vector(
               v8[17],
               *(Scaleform::GFx::AS3::ClassTraits::Traits **)&v6);
        break;
    }
  }
  source.Bonus.pWeakProxy = 0i64;
  *(_QWORD *)&source.value.VNumber = v7;
  source.Flags = 9;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v3->OpStack.Data.Data,
    v3->OpStack.Data.pHeap,
    v3->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &v3->OpStack.Data.Data[v3->OpStack.Data.Size - 1],
    &source);
  Scaleform::GFx::AS3::TR::ReadArgsObject::~ReadArgsObject((Scaleform::GFx::AS3::TR::ReadArgsObject *)&v11);
}

// File Line: 485
// RVA: 0x843A40
void __fastcall Scaleform::GFx::AS3::TR::State::exec_newobject(Scaleform::GFx::AS3::TR::State *this, unsigned int arg_count)
{
  unsigned int v2; // ebx
  Scaleform::GFx::AS3::TR::State *v3; // rdi
  long double v4; // rcx
  Scaleform::GFx::AS3::Value source; // [rsp+20h] [rbp-178h]
  __int64 v6; // [rsp+40h] [rbp-158h]
  Scaleform::GFx::AS3::TR::ReadArgs ptr; // [rsp+50h] [rbp-148h]

  v6 = -2i64;
  v2 = arg_count;
  v3 = this;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_newobject, arg_count);
  Scaleform::GFx::AS3::TR::ReadArgs::ReadArgs(&ptr, v3->pTracer->CF->pFile->VMRef, v3, 2 * v2);
  v4 = *(double *)&v3->pTracer->CF->pFile->VMRef->TraitsObject.pObject->ITraits.pObject;
  source.Bonus.pWeakProxy = 0i64;
  source.value.VNumber = v4;
  source.Flags = 8;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v3->OpStack.Data.Data,
    v3->OpStack.Data.pHeap,
    v3->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &v3->OpStack.Data.Data[v3->OpStack.Data.Size - 1],
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
void __fastcall Scaleform::GFx::AS3::TR::State::exec_newarray(Scaleform::GFx::AS3::TR::State *this, unsigned int arr_size)
{
  unsigned int v2; // ebx
  Scaleform::GFx::AS3::TR::State *v3; // rdi
  long double v4; // rcx
  Scaleform::GFx::AS3::Value source; // [rsp+20h] [rbp-178h]
  __int64 v6; // [rsp+40h] [rbp-158h]
  Scaleform::GFx::AS3::TR::ReadArgs ptr; // [rsp+50h] [rbp-148h]

  v6 = -2i64;
  v2 = arr_size;
  v3 = this;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_newarray, arr_size);
  Scaleform::GFx::AS3::TR::ReadArgs::ReadArgs(&ptr, v3->pTracer->CF->pFile->VMRef, v3, v2);
  v4 = *(double *)&v3->pTracer->CF->pFile->VMRef->TraitsArray.pObject->ITraits.pObject;
  source.Bonus.pWeakProxy = 0i64;
  source.value.VNumber = v4;
  source.Flags = 8;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v3->OpStack.Data.Data,
    v3->OpStack.Data.pHeap,
    v3->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &v3->OpStack.Data.Data[v3->OpStack.Data.Size - 1],
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
  Scaleform::GFx::AS3::TR::State *v1; // rbx
  Scaleform::GFx::AS3::VM::Error *v2; // rax
  Scaleform::GFx::ASStringNode *v3; // rcx
  bool v4; // zf
  Scaleform::GFx::AS3::VM::Error v5; // [rsp+28h] [rbp-20h]

  v1 = this;
  Scaleform::GFx::AS3::VM::Error::Error(&v5, eNotImplementedError, this->pTracer->CF->pFile->VMRef);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(
    v1->pTracer->CF->pFile->VMRef,
    v2,
    &Scaleform::GFx::AS3::fl::VerifyErrorTI);
  v3 = v5.Message.pNode;
  v4 = v5.Message.pNode->RefCount == 1;
  --v3->RefCount;
  if ( v4 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v3);
}

// File Line: 606
// RVA: 0x843830
void __fastcall Scaleform::GFx::AS3::TR::State::exec_newfunction(Scaleform::GFx::AS3::TR::State *this, unsigned int method_ind)
{
  Scaleform::GFx::AS3::TR::State *v2; // rbx
  long double v3; // rdx
  Scaleform::GFx::AS3::Value source; // [rsp+28h] [rbp-30h]

  v2 = this;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_newfunction, method_ind);
  v3 = *(double *)&v2->pTracer->CF->pFile->VMRef->TraitsFunction.pObject->ITraits.pObject;
  source.Bonus.pWeakProxy = 0i64;
  source.value.VNumber = v3;
  source.Flags = 8;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v2->OpStack.Data.Data,
    v2->OpStack.Data.pHeap,
    v2->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &v2->OpStack.Data.Data[v2->OpStack.Data.Size - 1],
    &source);
}

// File Line: 635
// RVA: 0x83FDA0
void __fastcall Scaleform::GFx::AS3::TR::State::exec_getdescendants(Scaleform::GFx::AS3::TR::State *this, unsigned int mn_index)
{
  Scaleform::GFx::AS3::TR::State *v2; // rdi
  Scaleform::GFx::AS3::Tracer *v3; // rcx
  Scaleform::GFx::AS3::VM::Error *v4; // rax
  Scaleform::GFx::ASStringNode *v5; // rcx
  bool v6; // zf
  __int64 v7; // rbx
  Scaleform::GFx::AS3::VMFile *v8; // rdx
  int v9; // eax
  __int64 v10; // rax
  Scaleform::GFx::AS3::WeakProxy *v11; // rdx
  Scaleform::GFx::AS3::VM::Error v12; // [rsp+18h] [rbp-49h]
  __int64 v13; // [rsp+28h] [rbp-39h]
  Scaleform::GFx::AS3::TR::StackReader v14; // [rsp+38h] [rbp-29h]
  Scaleform::GFx::AS3::VMFile *v15; // [rsp+50h] [rbp-11h]
  Scaleform::GFx::AS3::Multiname obj; // [rsp+58h] [rbp-9h]
  Scaleform::GFx::AS3::Value result; // [rsp+88h] [rbp+27h]
  __int64 v18; // [rsp+A8h] [rbp+47h]

  v18 = -2i64;
  v2 = this;
  v3 = this->pTracer;
  if ( v3->CF->pFile->VMRef->XMLSupport_.pObject->Enabled )
  {
    v7 = mn_index;
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(v3, op_getdescendants, mn_index);
    v8 = (Scaleform::GFx::AS3::VMFile *)&v2->pTracer->CF->pFile->vfptr;
    v14.VMRef = v8->VMRef;
    v14.StateRef = v2;
    v14.Num = 0;
    v15 = v8;
    Scaleform::GFx::AS3::Multiname::Multiname(
      &obj,
      v8,
      (Scaleform::GFx::AS3::Abc::Multiname *)v8[1].vfptr[7].~RefCountBaseGC<328> + v7);
    v9 = Scaleform::GFx::AS3::TR::StackReader::Read(&v14, &obj);
    v14.Num += v9;
    Scaleform::GFx::AS3::TR::State::PopOpValue(v2, &result);
    ++v14.Num;
    v10 = ((__int64 (*)(void))v2->pTracer->CF->pFile->VMRef->XMLSupport_.pObject->vfptr[4].~RefCountBaseGC<328>)();
    v12.Message.pNode = 0i64;
    v13 = v10;
    v12.ID = 8;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v2->OpStack.Data.Data,
      v2->OpStack.Data.pHeap,
      v2->OpStack.Data.Size + 1);
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
      &v2->OpStack.Data.Data[v2->OpStack.Data.Size - 1],
      (Scaleform::GFx::AS3::Value *)&v12);
    if ( (result.Flags & 0x1F) > 9 )
    {
      if ( (result.Flags >> 9) & 1 )
      {
        v11 = result.Bonus.pWeakProxy;
        v6 = result.Bonus.pWeakProxy->RefCount == 1;
        --v11->RefCount;
        if ( v6 )
          ((void (__cdecl *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::WeakProxy *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
            Scaleform::Memory::pGlobalHeap,
            v11);
        result.Bonus.pWeakProxy = 0i64;
        _mm_store_si128((__m128i *)&result.value, (__m128i)0i64);
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
    Scaleform::GFx::AS3::VM::Error::Error(&v12, eNotImplementedError, v3->CF->pFile->VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      v2->pTracer->CF->pFile->VMRef,
      v4,
      &Scaleform::GFx::AS3::fl::VerifyErrorTI);
    v5 = v12.Message.pNode;
    v6 = v12.Message.pNode->RefCount == 1;
    --v5->RefCount;
    if ( v6 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  }
}

// File Line: 663
// RVA: 0x8430E0
void __fastcall Scaleform::GFx::AS3::TR::State::exec_newcatch(Scaleform::GFx::AS3::TR::State *this, unsigned int v)
{
  Scaleform::GFx::AS3::TR::State *v2; // rbx
  long double v3; // rdx
  Scaleform::GFx::AS3::Value source; // [rsp+28h] [rbp-30h]

  v2 = this;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_newcatch, v);
  v3 = *(double *)&v2->pTracer->CF->pFile->VMRef->TraitsObject.pObject->ITraits.pObject;
  source.Bonus.pWeakProxy = 0i64;
  source.value.VNumber = v3;
  source.Flags = 8;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v2->OpStack.Data.Data,
    v2->OpStack.Data.pHeap,
    v2->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &v2->OpStack.Data.Data[v2->OpStack.Data.Size - 1],
    &source);
}

// File Line: 690
// RVA: 0x7D32B0
void __fastcall Scaleform::GFx::AS3::TR::State::FindProp(Scaleform::GFx::AS3::TR::State *this, Scaleform::GFx::AS3::PropRef *result, Scaleform::GFx::AS3::Multiname *mn, Scaleform::GFx::AS3::TR::State::ScopeType *stype, unsigned __int64 *scope_index)
{
  Scaleform::GFx::AS3::Multiname *v5; // r12
  Scaleform::GFx::AS3::PropRef *v6; // r15
  Scaleform::GFx::AS3::TR::State *v7; // r8
  Scaleform::GFx::AS3::VM *v8; // r14
  unsigned __int64 v9; // rsi
  signed __int64 v10; // rbx
  Scaleform::GFx::AS3::Value *v11; // r13
  Scaleform::GFx::AS3::Traits *v12; // rax
  Scaleform::GFx::AS3::Traits *v13; // rdi
  Scaleform::GFx::AS3::SlotInfo *v14; // rax
  Scaleform::GFx::AS3::PropRef *v15; // rax
  bool v16; // zf
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v17; // r13
  unsigned __int64 v18; // rdi
  signed __int64 v19; // rbx
  signed __int64 v20; // rsi
  Scaleform::GFx::AS3::Traits *v21; // rax
  Scaleform::GFx::AS3::SlotInfo *v22; // rax
  Scaleform::GFx::AS3::SlotInfo *v23; // rdx
  unsigned __int64 v24; // r9
  unsigned int v25; // ecx
  _DWORD *v26; // r8
  int v27; // eax
  __int64 v28; // rcx
  unsigned int v29; // ebx
  Scaleform::GFx::AS3::ClassTraits::Traits *v30; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v31; // rdi
  Scaleform::GFx::AS3::InstanceTraits::Traits *v32; // rcx
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *obj; // rbx
  Scaleform::GFx::AS3::SlotInfo *v34; // rax
  unsigned __int64 v35; // rdx
  unsigned int v36; // ebx
  unsigned __int64 v37; // [rsp+30h] [rbp-40h]
  __int64 v38; // [rsp+38h] [rbp-38h]
  Scaleform::GFx::AS3::PropRef v39; // [rsp+40h] [rbp-30h]
  Scaleform::GFx::AS3::TR::State *v40; // [rsp+B0h] [rbp+40h]
  unsigned __int64 index; // [rsp+C0h] [rbp+50h]
  Scaleform::GFx::AS3::TR::State::ScopeType *v42; // [rsp+C8h] [rbp+58h]

  v42 = stype;
  v40 = this;
  v38 = -2i64;
  v5 = mn;
  v6 = result;
  v7 = this;
  if ( (v5->Kind & 3) == 1 || ((unsigned int)v5->Kind >> 2) & 1 )
    return;
  v8 = this->pTracer->CF->pFile->VMRef;
  index = 0i64;
  v9 = this->ScopeStack.Data.Size;
  if ( !v9 )
  {
LABEL_17:
    v17 = v7->pTracer->CF->pSavedScope;
    v18 = v17->Data.Size;
    if ( !v18 )
    {
LABEL_40:
      if ( (v5->Name.Flags & 0x1F) - 8 <= 1 )
        return;
      v30 = Scaleform::GFx::AS3::FindClassTraits(v8, v5, v7->pTracer->CF->pFile->AppDomain.pObject);
      v31 = v30;
      if ( v30
        && (v32 = v30->ITraits.pObject) != 0i64
        && (!((LOBYTE(v32->Flags) >> 4) & 1) ? (obj = (Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *)v8->GlobalObject.pObject) : (obj = Scaleform::GFx::AS3::InstanceTraits::UserDefined::GetGlobalObjectScript((Scaleform::GFx::AS3::InstanceTraits::UserDefined *)v32)),
            v37 = 0i64,
            (v34 = Scaleform::GFx::AS3::FindFixedSlot(
                     v8,
                     obj->pTraits.pObject,
                     v5,
                     &v37,
                     (Scaleform::GFx::AS3::Object *)&obj->vfptr)) != 0i64) )
      {
        v39.pSI = v34;
        v35 = v37;
        v39.SlotIndex = v37;
        v39.This.Flags = 12;
        v39.This.Bonus.pWeakProxy = 0i64;
        *(_QWORD *)&v39.This.value.VNumber = obj;
        obj->RefCount = (obj->RefCount + 1) & 0x8FBFFFFF;
        v6->pSI = v34;
        v6->SlotIndex = v35;
        Scaleform::GFx::AS3::Value::Assign(&v6->This, &v39.This);
        v36 = v39.This.Flags;
        if ( (v39.This.Flags & 0x1F) > 9 )
        {
          if ( (v39.This.Flags >> 9) & 1 )
          {
            v16 = v39.This.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v16 )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            v39.This.Bonus.pWeakProxy = 0i64;
            v39.This.value = 0ui64;
            v39.This.Flags = v36 & 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v39.This);
          }
        }
      }
      else
      {
        Scaleform::GFx::AS3::FindGOProperty(v6, v8, &v8->GlobalObjects, v5, v31);
        if ( !(v6->This.Flags & 0x1F)
          || (_QWORD)v6->pSI & 1 && !((_QWORD)v6->pSI & 0xFFFFFFFFFFFFFFFEui64)
          || ((unsigned __int8)v6->pSI >> 1) & 1 && !((_QWORD)v6->pSI & 0xFFFFFFFFFFFFFFFDui64) )
        {
          return;
        }
      }
      *v42 = 2;
      return;
    }
    v19 = 32 * v18 - 32;
    while ( 1 )
    {
      *scope_index = --v18;
      v20 = (signed __int64)v17->Data.Data + v19;
      v21 = Scaleform::GFx::AS3::VM::GetValueTraits(v8, (Scaleform::GFx::AS3::Value *)((char *)v17->Data.Data + v19));
      if ( (*(_WORD *)v20 >> 8) & 1 )
        return;
      v22 = Scaleform::GFx::AS3::FindFixedSlot(v8, v21, v5, &index, 0i64);
      v23 = v22;
      if ( v22 )
        break;
      v19 -= 32i64;
      if ( !v18 )
      {
        v7 = v40;
        goto LABEL_40;
      }
    }
    *v42 = 1;
    v39.pSI = v22;
    v24 = index;
    v39.SlotIndex = index;
    v25 = *(_DWORD *)v20;
    v39.This.Flags = v25;
    v26 = *(_DWORD **)(v20 + 8);
    v39.This.Bonus.pWeakProxy = *(Scaleform::GFx::AS3::WeakProxy **)(v20 + 8);
    v39.This.value = *(Scaleform::GFx::AS3::Value::VU *)(v20 + 16);
    v27 = v25 & 0x1F;
    if ( v27 > 9 )
    {
      if ( (v25 >> 9) & 1 )
      {
        ++*v26;
        goto LABEL_35;
      }
      if ( v27 == 10 )
      {
        ++*(_DWORD *)(*(_QWORD *)(v20 + 16) + 24i64);
      }
      else
      {
        if ( v27 <= 10 )
          goto LABEL_35;
        if ( v27 <= 15 )
        {
          v28 = *(_QWORD *)(v20 + 16);
        }
        else
        {
          if ( v27 > 17 )
            goto LABEL_35;
          v28 = *(_QWORD *)(v20 + 24);
        }
        if ( v28 )
          *(_DWORD *)(v28 + 32) = (*(_DWORD *)(v28 + 32) + 1) & 0x8FBFFFFF;
      }
    }
LABEL_35:
    v6->pSI = v23;
    v6->SlotIndex = v24;
    Scaleform::GFx::AS3::Value::Assign(&v6->This, &v39.This);
    v29 = v39.This.Flags;
    if ( (v39.This.Flags & 0x1F) <= 9 )
      return;
    if ( (v39.This.Flags >> 9) & 1 )
    {
      v16 = v39.This.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v16 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v39.This.Bonus.pWeakProxy = 0i64;
      v39.This.value = 0ui64;
      v39.This.Flags = v29 & 0xFFFFFDE0;
      return;
    }
    goto LABEL_16;
  }
  v10 = 32 * v9 - 32;
  while ( 1 )
  {
    *scope_index = --v9;
    v11 = (Scaleform::GFx::AS3::Value *)((char *)v7->ScopeStack.Data.Data + v10);
    v12 = Scaleform::GFx::AS3::TR::State::GetValueTraits(
            v7,
            (Scaleform::GFx::AS3::Value *)((char *)v7->ScopeStack.Data.Data + v10));
    v13 = v12;
    if ( (LOWORD(v11->Flags) >> 8) & 1 )
      break;
    if ( v12 )
    {
      if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::Traits *))v12->vfptr[1].ForEachChild_GC)(v12) )
      {
        v14 = Scaleform::GFx::AS3::FindFixedSlot(v8, v13, v5, &index, 0i64);
        if ( v14 )
        {
          *v42 = 0;
          Scaleform::GFx::AS3::PropRef::PropRef(&v39, v11, v14, index);
          Scaleform::GFx::AS3::PropRef::operator=(v6, v15);
          if ( (v39.This.Flags & 0x1F) > 9 )
          {
            if ( (v39.This.Flags >> 9) & 1 )
            {
              v16 = v39.This.Bonus.pWeakProxy->RefCount-- == 1;
              if ( v16 )
                ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
              v39.This.Bonus.pWeakProxy = 0i64;
              v39.This.value = 0ui64;
              v39.This.Flags &= 0xFFFFFDE0;
            }
            else
            {
LABEL_16:
              Scaleform::GFx::AS3::Value::ReleaseInternal(&v39.This);
            }
          }
          return;
        }
      }
    }
    v10 -= 32i64;
    v7 = v40;
    if ( !v9 )
      goto LABEL_17;
  }
}

// File Line: 835
// RVA: 0x83F800
void __fastcall Scaleform::GFx::AS3::TR::State::exec_findpropstrict(Scaleform::GFx::AS3::TR::State *this, unsigned int mn_index)
{
  Scaleform::GFx::AS3::TR::State *v2; // rdi
  __int64 v3; // rbx
  Scaleform::GFx::AS3::VMFile *v4; // rdx
  int v5; // eax
  long double v6; // rcx
  bool v7; // zf
  Scaleform::GFx::AS3::PropRef result; // [rsp+30h] [rbp-69h]
  Scaleform::GFx::AS3::Value source; // [rsp+60h] [rbp-39h]
  Scaleform::GFx::AS3::TR::StackReader v10; // [rsp+80h] [rbp-19h]
  Scaleform::GFx::AS3::VMFile *v11; // [rsp+98h] [rbp-1h]
  Scaleform::GFx::AS3::Multiname obj; // [rsp+A0h] [rbp+7h]
  __int64 v13; // [rsp+D0h] [rbp+37h]
  unsigned __int64 scope_index; // [rsp+100h] [rbp+67h]
  Scaleform::GFx::AS3::TR::State::ScopeType stype; // [rsp+108h] [rbp+6Fh]

  v13 = -2i64;
  v2 = this;
  v3 = mn_index;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_findpropstrict, mn_index);
  v4 = (Scaleform::GFx::AS3::VMFile *)&v2->pTracer->CF->pFile->vfptr;
  v10.VMRef = v4->VMRef;
  v10.StateRef = v2;
  v10.Num = 0;
  v11 = v4;
  Scaleform::GFx::AS3::Multiname::Multiname(
    &obj,
    v4,
    (Scaleform::GFx::AS3::Abc::Multiname *)v4[1].vfptr[7].~RefCountBaseGC<328> + v3);
  v5 = Scaleform::GFx::AS3::TR::StackReader::Read(&v10, &obj);
  v10.Num += v5;
  result.pSI = 0i64;
  result.SlotIndex = 0i64;
  result.This.Flags = 0;
  result.This.Bonus.pWeakProxy = 0i64;
  Scaleform::GFx::AS3::TR::State::FindProp(v2, &result, &obj, &stype, &scope_index);
  if ( result.This.Flags & 0x1F
    && (!((_QWORD)result.pSI & 1) || (_QWORD)result.pSI & 0xFFFFFFFFFFFFFFFEui64)
    && (!((LOBYTE(result.pSI) >> 1) & 1) || (_QWORD)result.pSI & 0xFFFFFFFFFFFFFFFDui64) )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v2->OpStack.Data.Data,
      v2->OpStack.Data.pHeap,
      v2->OpStack.Data.Size + 1);
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
      &v2->OpStack.Data.Data[v2->OpStack.Data.Size - 1],
      &result.This);
  }
  else
  {
    v6 = *(double *)&v2->pTracer->CF->pFile->VMRef->TraitsObject.pObject->ITraits.pObject;
    source.Bonus.pWeakProxy = 0i64;
    source.value.VNumber = v6;
    source.Flags = 8;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v2->OpStack.Data.Data,
      v2->OpStack.Data.pHeap,
      v2->OpStack.Data.Size + 1);
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
      &v2->OpStack.Data.Data[v2->OpStack.Data.Size - 1],
      &source);
  }
  if ( (result.This.Flags & 0x1F) > 9 )
  {
    if ( (result.This.Flags >> 9) & 1 )
    {
      v7 = result.This.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v7 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      result.This.Bonus.pWeakProxy = 0i64;
      result.This.value = 0ui64;
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
void __fastcall Scaleform::GFx::AS3::TR::State::exec_findproperty(Scaleform::GFx::AS3::TR::State *this, unsigned int mn_index)
{
  Scaleform::GFx::AS3::TR::State *v2; // rdi
  __int64 v3; // rbx
  Scaleform::GFx::AS3::VMFile *v4; // rdx
  int v5; // eax
  long double v6; // rcx
  bool v7; // zf
  Scaleform::GFx::AS3::PropRef result; // [rsp+30h] [rbp-69h]
  Scaleform::GFx::AS3::Value source; // [rsp+60h] [rbp-39h]
  Scaleform::GFx::AS3::TR::StackReader v10; // [rsp+80h] [rbp-19h]
  Scaleform::GFx::AS3::VMFile *v11; // [rsp+98h] [rbp-1h]
  Scaleform::GFx::AS3::Multiname obj; // [rsp+A0h] [rbp+7h]
  __int64 v13; // [rsp+D0h] [rbp+37h]
  unsigned __int64 scope_index; // [rsp+100h] [rbp+67h]
  Scaleform::GFx::AS3::TR::State::ScopeType stype; // [rsp+108h] [rbp+6Fh]

  v13 = -2i64;
  v2 = this;
  v3 = mn_index;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_findproperty, mn_index);
  v4 = (Scaleform::GFx::AS3::VMFile *)&v2->pTracer->CF->pFile->vfptr;
  v10.VMRef = v4->VMRef;
  v10.StateRef = v2;
  v10.Num = 0;
  v11 = v4;
  Scaleform::GFx::AS3::Multiname::Multiname(
    &obj,
    v4,
    (Scaleform::GFx::AS3::Abc::Multiname *)v4[1].vfptr[7].~RefCountBaseGC<328> + v3);
  v5 = Scaleform::GFx::AS3::TR::StackReader::Read(&v10, &obj);
  v10.Num += v5;
  result.pSI = 0i64;
  result.SlotIndex = 0i64;
  result.This.Flags = 0;
  result.This.Bonus.pWeakProxy = 0i64;
  Scaleform::GFx::AS3::TR::State::FindProp(v2, &result, &obj, &stype, &scope_index);
  if ( result.This.Flags & 0x1F
    && (!((_QWORD)result.pSI & 1) || (_QWORD)result.pSI & 0xFFFFFFFFFFFFFFFEui64)
    && (!((LOBYTE(result.pSI) >> 1) & 1) || (_QWORD)result.pSI & 0xFFFFFFFFFFFFFFFDui64) )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v2->OpStack.Data.Data,
      v2->OpStack.Data.pHeap,
      v2->OpStack.Data.Size + 1);
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
      &v2->OpStack.Data.Data[v2->OpStack.Data.Size - 1],
      &result.This);
  }
  else
  {
    v6 = *(double *)&v2->pTracer->CF->pFile->VMRef->TraitsObject.pObject->ITraits.pObject;
    source.Bonus.pWeakProxy = 0i64;
    source.value.VNumber = v6;
    source.Flags = 72;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v2->OpStack.Data.Data,
      v2->OpStack.Data.pHeap,
      v2->OpStack.Data.Size + 1);
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
      &v2->OpStack.Data.Data[v2->OpStack.Data.Size - 1],
      &source);
  }
  if ( (result.This.Flags & 0x1F) > 9 )
  {
    if ( (result.This.Flags >> 9) & 1 )
    {
      v7 = result.This.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v7 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      result.This.Bonus.pWeakProxy = 0i64;
      result.This.value = 0ui64;
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
void __fastcall Scaleform::GFx::AS3::TR::State::exec_getlex(Scaleform::GFx::AS3::TR::State *this, unsigned int mn_index)
{
  Scaleform::GFx::AS3::TR::State *v2; // rbx
  long double v3; // rdx
  Scaleform::GFx::AS3::Value source; // [rsp+28h] [rbp-30h]

  v2 = this;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_getlex, mn_index);
  v3 = *(double *)&v2->pTracer->CF->pFile->VMRef->TraitsObject.pObject->ITraits.pObject;
  source.Bonus.pWeakProxy = 0i64;
  source.value.VNumber = v3;
  source.Flags = 8;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v2->OpStack.Data.Data,
    v2->OpStack.Data.pHeap,
    v2->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &v2->OpStack.Data.Data[v2->OpStack.Data.Size - 1],
    &source);
}

// File Line: 928
// RVA: 0x840930
void __fastcall Scaleform::GFx::AS3::TR::State::exec_getlocal(Scaleform::GFx::AS3::TR::State *this, unsigned int reg_ind)
{
  Scaleform::GFx::AS3::TR::State *v2; // rbx
  __int64 v3; // rdi
  Scaleform::GFx::AS3::Value *v4; // rdi

  v2 = this;
  v3 = reg_ind;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_getlocal, reg_ind);
  v4 = &v2->Registers.Data.Data[v3];
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v2->OpStack.Data.Data,
    v2->OpStack.Data.pHeap,
    v2->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &v2->OpStack.Data.Data[v2->OpStack.Data.Size - 1],
    v4);
}

// File Line: 940
// RVA: 0x842D70
void __fastcall Scaleform::GFx::AS3::TR::State::exec_newactivation(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::TR::State *v1; // rbx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v2; // rax
  Scaleform::GFx::AS3::Value source; // [rsp+28h] [rbp-30h]

  v1 = this;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_newactivation);
  v2 = Scaleform::GFx::AS3::VMFile::GetActivationInstanceTraits(
         (Scaleform::GFx::AS3::VMFile *)&v1->pTracer->CF->pFile->vfptr,
         v1->pTracer->CF->MBIIndex);
  source.Bonus.pWeakProxy = 0i64;
  *(_QWORD *)&source.value.VNumber = v2;
  source.Flags = 8;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v1->OpStack.Data.Data,
    v1->OpStack.Data.pHeap,
    v1->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &v1->OpStack.Data.Data[v1->OpStack.Data.Size - 1],
    &source);
}

// File Line: 953
// RVA: 0x8455B0
void __fastcall Scaleform::GFx::AS3::TR::State::exec_pushbyte(Scaleform::GFx::AS3::TR::State *this, int v)
{
  char v2; // bl
  Scaleform::GFx::AS3::TR::State *v3; // rdi
  Scaleform::GFx::AS3::Value source; // [rsp+28h] [rbp-30h]

  v2 = v;
  v3 = this;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_pushbyte, v);
  source.Flags = 2;
  source.Bonus.pWeakProxy = 0i64;
  source.value.VS._1.VInt = v2;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v3->OpStack.Data.Data,
    v3->OpStack.Data.pHeap,
    v3->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &v3->OpStack.Data.Data[v3->OpStack.Data.Size - 1],
    &source);
}

// File Line: 965
// RVA: 0x845B20
void __fastcall Scaleform::GFx::AS3::TR::State::exec_pushshort(Scaleform::GFx::AS3::TR::State *this, int v)
{
  int v2; // ebx
  Scaleform::GFx::AS3::TR::State *v3; // rdi
  Scaleform::GFx::AS3::Value source; // [rsp+28h] [rbp-30h]

  v2 = v;
  v3 = this;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_pushshort, v);
  source.Flags = 2;
  source.Bonus.pWeakProxy = 0i64;
  source.value.VS._1.VInt = v2;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v3->OpStack.Data.Data,
    v3->OpStack.Data.pHeap,
    v3->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &v3->OpStack.Data.Data[v3->OpStack.Data.Size - 1],
    &source);
}

// File Line: 976
// RVA: 0x845BA0
void __fastcall Scaleform::GFx::AS3::TR::State::exec_pushstring(Scaleform::GFx::AS3::TR::State *this, int v)
{
  Scaleform::GFx::AS3::TR::State *v2; // rbx
  Scaleform::GFx::AS3::Tracer *v3; // r10
  Scaleform::GFx::AS3::VMAbcFile *v4; // rdi
  const char *v5; // r8
  const char *v6; // r8
  unsigned __int64 v7; // r9
  char v8; // al
  unsigned int v9; // ecx
  char v10; // dl
  unsigned int v11; // edi
  Scaleform::GFx::ASStringNode *v12; // rcx
  bool v13; // zf
  Scaleform::GFx::AS3::Value source; // [rsp+28h] [rbp-30h]
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+8h]
  Scaleform::GFx::ASStringNode *key; // [rsp+70h] [rbp+18h]

  v2 = this;
  v3 = this->pTracer;
  v4 = this->pTracer->CF->pFile;
  v5 = v4->File.pObject->Const_Pool.ConstStr.Data.Data[v].Data;
  if ( v5 )
  {
    v8 = *v5;
    v6 = v5 + 1;
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
    v7 = (signed int)v7;
  }
  else
  {
    v6 = &customWorldMapCaption;
    v7 = 0i64;
  }
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v3->CF->pFile->VMRef->StringManagerRef->Builtins,
    &result,
    v6,
    v7);
  key = result.pNode;
  Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::GFx::AS3::ASStringNodePtrHashFunc,Scaleform::GFx::AS3::ASStringNodePtrHashFunc,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,340>,Scaleform::HashsetEntry<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>>::Set<Scaleform::GFx::ASStringNode *>(
    (Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::GFx::AS3::ASStringNodePtrHashFunc,Scaleform::GFx::AS3::ASStringNodePtrHashFunc,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,340>,Scaleform::HashsetEntry<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::GFx::AS3::ASStringNodePtrHashFunc> > *)&v4->ASStringNodeSet.pTable,
    &v4->ASStringNodeSet,
    &key);
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(v2->pTracer, op_pushstring, (unsigned __int64)result.pNode);
  v11 = 10;
  source.Flags = 10;
  source.Bonus.pWeakProxy = 0i64;
  *(Scaleform::GFx::ASString *)&source.value.VNumber = result;
  if ( result.pNode == &result.pNode->pManager->NullStringNode )
  {
    source.value.VNumber = 0.0;
    source.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)source.Bonus.pWeakProxy;
    v11 = 12;
    source.Flags = 12;
  }
  else
  {
    ++result.pNode->RefCount;
  }
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v2->OpStack.Data.Data,
    v2->OpStack.Data.pHeap,
    v2->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &v2->OpStack.Data.Data[v2->OpStack.Data.Size - 1],
    &source);
  if ( (char)(v11 & 0x1F) > 9 )
  {
    if ( (v11 >> 9) & 1 )
    {
      LODWORD(MEMORY[0]) = MEMORY[0] - 1;
      if ( !(_DWORD)MEMORY[0] )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
      source.Bonus.pWeakProxy = 0i64;
      source.value = 0ui64;
      source.Flags = v11 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&source);
    }
  }
  v12 = result.pNode;
  v13 = result.pNode->RefCount == 1;
  --v12->RefCount;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
}

// File Line: 1002
// RVA: 0x845730
void __fastcall Scaleform::GFx::AS3::TR::State::exec_pushint(Scaleform::GFx::AS3::TR::State *this, int v)
{
  Scaleform::GFx::AS3::TR::State *v2; // rdi
  Scaleform::GFx::AS3::Tracer *v3; // rcx
  unsigned __int64 v4; // rbx
  Scaleform::GFx::AS3::Value source; // [rsp+28h] [rbp-30h]

  v2 = this;
  v3 = this->pTracer;
  v4 = v3->CF->pFile->File.pObject->Const_Pool.ConstInt.Data.Data[v];
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(v3, op_pushint, v4);
  source.Flags = 2;
  source.Bonus.pWeakProxy = 0i64;
  source.value.VS._1.VInt = v4;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v2->OpStack.Data.Data,
    v2->OpStack.Data.pHeap,
    v2->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &v2->OpStack.Data.Data[v2->OpStack.Data.Size - 1],
    &source);
}

// File Line: 1019
// RVA: 0x845D60
void __fastcall Scaleform::GFx::AS3::TR::State::exec_pushuint(Scaleform::GFx::AS3::TR::State *this, int v)
{
  Scaleform::GFx::AS3::TR::State *v2; // rdi
  Scaleform::GFx::AS3::Tracer *v3; // rcx
  unsigned __int64 v4; // rbx
  Scaleform::GFx::AS3::Value source; // [rsp+28h] [rbp-30h]

  v2 = this;
  v3 = this->pTracer;
  v4 = v3->CF->pFile->File.pObject->Const_Pool.ConstUInt.Data.Data[v];
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(v3, op_pushuint, v4);
  source.Flags = 3;
  source.Bonus.pWeakProxy = 0i64;
  source.value.VS._1.VInt = v4;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v2->OpStack.Data.Data,
    v2->OpStack.Data.pHeap,
    v2->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &v2->OpStack.Data.Data[v2->OpStack.Data.Size - 1],
    &source);
}

// File Line: 1036
// RVA: 0x845630
void __fastcall Scaleform::GFx::AS3::TR::State::exec_pushdouble(Scaleform::GFx::AS3::TR::State *this, int v)
{
  Scaleform::GFx::AS3::TR::State *v2; // rbx
  const char *v3; // r8
  long double v4; // xmm6_8
  Scaleform::GFx::AS3::Value source; // [rsp+28h] [rbp-40h]
  double arg1; // [rsp+70h] [rbp+8h]

  v2 = this;
  if ( v )
  {
    v3 = this->pTracer->CF->pFile->File.pObject->Const_Pool.Doubles;
    LODWORD(arg1) = (unsigned __int8)v3[8 * v - 8] | (((unsigned __int8)v3[8 * v - 7] | (*(unsigned __int16 *)&v3[8 * v - 6] << 8)) << 8);
    HIDWORD(arg1) = (unsigned __int8)v3[8 * v - 4] | (((unsigned __int8)v3[8 * v - 3] | (*(unsigned __int16 *)&v3[8 * v - 2] << 8)) << 8);
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
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v2->OpStack.Data.Data,
    v2->OpStack.Data.pHeap,
    v2->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &v2->OpStack.Data.Data[v2->OpStack.Data.Size - 1],
    &source);
}

// File Line: 1053
// RVA: 0x841610
void __fastcall Scaleform::GFx::AS3::TR::State::exec_hasnext2(Scaleform::GFx::AS3::TR::State *this, unsigned int object_reg, unsigned int index_reg)
{
  Scaleform::GFx::AS3::TR::State *v3; // rbx
  long double v4; // rdx
  Scaleform::GFx::AS3::Value source; // [rsp+28h] [rbp-30h]

  v3 = this;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_hasnext2, object_reg, index_reg);
  v4 = *(double *)&v3->pTracer->CF->pFile->VMRef->TraitsBoolean.pObject->ITraits.pObject;
  source.Bonus.pWeakProxy = 0i64;
  source.value.VNumber = v4;
  source.Flags = 8;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v3->OpStack.Data.Data,
    v3->OpStack.Data.pHeap,
    v3->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &v3->OpStack.Data.Data[v3->OpStack.Data.Size - 1],
    &source);
}

// File Line: 1078
// RVA: 0x843F10
void __fastcall Scaleform::GFx::AS3::TR::State::exec_nextname(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::TR::State *v1; // r14
  Scaleform::GFx::AS3::Tracer *v2; // rsi
  long double v3; // rbx
  Scaleform::GFx::AS3::VM *v4; // rax
  long double v5; // rcx
  Scaleform::GFx::AS3::Tracer *v6; // rax
  Scaleform::GFx::AS3::VM *v7; // rcx
  long double v8; // rcx
  long double v9; // rcx
  bool v10; // zf
  Scaleform::GFx::AS3::Value result; // [rsp+28h] [rbp-48h]
  Scaleform::GFx::AS3::Value source; // [rsp+48h] [rbp-28h]

  v1 = this;
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->OpStack.Data,
    this->OpStack.Data.Size - 1);
  Scaleform::GFx::AS3::TR::State::PopOpValue(v1, &result);
  v2 = v1->pTracer;
  if ( result.Flags & 0x1F )
  {
    if ( (result.Flags & 0x1F) == 8 || (result.Flags & 0x1F) == 9 )
      v3 = result.value.VNumber;
    else
      v3 = COERCE_DOUBLE(Scaleform::GFx::AS3::VM::GetValueTraits(v2->CF->pFile->VMRef, &result));
  }
  else
  {
    v3 = *(double *)&v2->CF->pFile->VMRef->TraitsVoid.pObject;
  }
  if ( v3 != 0.0 )
  {
    v4 = v2->CF->pFile->VMRef;
    if ( *(Scaleform::GFx::AS3::ClassTraits::ClassClass **)&v3 == v4->TraitsClassClass.pObject )
      v3 = *(double *)&v4->TraitsObject.pObject;
  }
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(v2, op_nextname);
  if ( *(_DWORD *)(*(_QWORD *)&v3 + 120i64) == 11 && ~(*(_BYTE *)(*(_QWORD *)&v3 + 112i64) >> 5) & 1 )
  {
    v5 = *(double *)&v1->pTracer->CF->pFile->VMRef->TraitsObject.pObject->ITraits.pObject;
    source.Bonus.pWeakProxy = 0i64;
    source.value.VNumber = v5;
    source.Flags = 72;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v1->OpStack.Data.Data,
      v1->OpStack.Data.pHeap,
      v1->OpStack.Data.Size + 1);
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
      &v1->OpStack.Data.Data[v1->OpStack.Data.Size - 1],
      &source);
  }
  else
  {
    v6 = v1->pTracer;
    source.Flags = 8;
    v7 = v6->CF->pFile->VMRef;
    if ( *(_BYTE *)(*(_QWORD *)&v3 + 112i64) & 1 )
    {
      v8 = *(double *)&v7->TraitsUint.pObject->ITraits.pObject;
      source.Bonus.pWeakProxy = 0i64;
      source.value.VNumber = v8;
      source.Flags = 8;
    }
    else
    {
      v9 = *(double *)&v7->TraitsString.pObject->ITraits.pObject;
      source.Bonus.pWeakProxy = 0i64;
      source.value.VNumber = v9;
      source.Flags = 72;
    }
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v1->OpStack.Data.Data,
      v1->OpStack.Data.pHeap,
      v1->OpStack.Data.Size + 1);
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
      &v1->OpStack.Data.Data[v1->OpStack.Data.Size - 1],
      &source);
  }
  if ( (result.Flags & 0x1F) > 9 )
  {
    if ( (result.Flags >> 9) & 1 )
    {
      v10 = result.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v10 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      result.Bonus.pWeakProxy = 0i64;
      result.value = 0ui64;
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
  Scaleform::GFx::AS3::TR::State *v1; // rdi

  v1 = this;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_hasnext);
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v1->OpStack.Data,
    v1->OpStack.Data.Size - 1);
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v1->OpStack.Data,
    v1->OpStack.Data.Size - 1);
  Scaleform::GFx::AS3::TR::State::PushOp(v1, v1->pTracer->CF->pFile->VMRef->TraitsInt.pObject->ITraits.pObject, 0);
}

// File Line: 1134
// RVA: 0x845E00
void __fastcall Scaleform::GFx::AS3::TR::State::exec_pushundefined(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::TR::State *v1; // rbx
  Scaleform::GFx::AS3::Value::VU *v2; // rdx
  int v3; // eax
  long double v4; // rax

  v1 = this;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_pushundefined);
  if ( !(_S11_12 & 1) )
  {
    _S11_12 |= 1u;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0i64;
    atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v1->OpStack.Data.Data,
    v1->OpStack.Data.pHeap,
    v1->OpStack.Data.Size + 1);
  v2 = (Scaleform::GFx::AS3::Value::VU *)&v1->OpStack.Data.Data[v1->OpStack.Data.Size - 1];
  if ( v2 )
  {
    LODWORD(v2->VS._1.VStr) = v.Flags;
    v2->VS._2.VObj = (Scaleform::GFx::AS3::Object *)v.Bonus.pWeakProxy;
    v2[1] = v.value;
    v3 = v.Flags & 0x1F;
    if ( v3 > 9 )
    {
      if ( (v.Flags >> 9) & 1 )
      {
        ++v.Bonus.pWeakProxy->RefCount;
        return;
      }
      if ( v3 == 10 )
      {
        ++*(_DWORD *)(*(_QWORD *)&v.value.VNumber + 24i64);
      }
      else
      {
        if ( v3 <= 10 )
          return;
        if ( v3 <= 15 )
        {
          v4 = v.value.VNumber;
        }
        else
        {
          if ( v3 > 17 )
            return;
          v4 = *(double *)&v.value.VS._2.VObj;
        }
        if ( v4 != 0.0 )
        {
          ++*(_DWORD *)(*(_QWORD *)&v4 + 32i64);
          *(_DWORD *)(*(_QWORD *)&v4 + 32i64) &= 0x8FBFFFFF;
        }
      }
    }
  }
}

// File Line: 1146
// RVA: 0x844270
void __fastcall Scaleform::GFx::AS3::TR::State::exec_nextvalue(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::TR::State *v1; // rbx
  long double v2; // rcx
  Scaleform::GFx::AS3::Value source; // [rsp+28h] [rbp-30h]

  v1 = this;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_nextvalue);
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v1->OpStack.Data,
    v1->OpStack.Data.Size - 1);
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v1->OpStack.Data,
    v1->OpStack.Data.Size - 1);
  v2 = *(double *)&v1->pTracer->CF->pFile->VMRef->TraitsObject.pObject->ITraits.pObject;
  source.Bonus.pWeakProxy = 0i64;
  source.value.VNumber = v2;
  source.Flags = 8;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v1->OpStack.Data.Data,
    v1->OpStack.Data.pHeap,
    v1->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &v1->OpStack.Data.Data[v1->OpStack.Data.Size - 1],
    &source);
}

// File Line: 1193
// RVA: 0x83D3F0
void __fastcall Scaleform::GFx::AS3::TR::State::exec_coerce_s(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::TR::State *v1; // rbx

  v1 = this;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_coerce_s);
  if ( (v1->OpStack.Data.Data[v1->OpStack.Data.Size - 1].Flags & 0x1F) != 10 )
    Scaleform::GFx::AS3::TR::State::ConvertOpTo(
      v1,
      v1->pTracer->CF->pFile->VMRef->TraitsString.pObject->ITraits.pObject,
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
  Scaleform::GFx::AS3::TR::State *v1; // rbx
  bool v2; // zf
  Scaleform::GFx::AS3::Value result; // [rsp+28h] [rbp-30h]

  v1 = this;
  Scaleform::GFx::AS3::TR::State::PopOpValue(this, &result);
  Scaleform::GFx::AS3::TR::State::ConvertOpTo(
    v1,
    v1->pTracer->CF->pFile->VMRef->TraitsNumber.pObject->ITraits.pObject,
    0);
  if ( (result.Flags & 0x1F) > 9 )
  {
    if ( (result.Flags >> 9) & 1 )
    {
      v2 = result.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v2 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      result.Bonus.pWeakProxy = 0i64;
      result.value = 0ui64;
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
  Scaleform::GFx::AS3::TR::State *v1; // rbx
  bool v2; // zf
  Scaleform::GFx::AS3::Value result; // [rsp+28h] [rbp-30h]

  v1 = this;
  Scaleform::GFx::AS3::TR::State::PopOpValue(this, &result);
  Scaleform::GFx::AS3::TR::State::ConvertOpTo(v1, v1->pTracer->CF->pFile->VMRef->TraitsInt.pObject->ITraits.pObject, 0);
  if ( (result.Flags & 0x1F) > 9 )
  {
    if ( (result.Flags >> 9) & 1 )
    {
      v2 = result.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v2 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      result.Bonus.pWeakProxy = 0i64;
      result.value = 0ui64;
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
  Scaleform::GFx::AS3::TR::State *v1; // rbx
  bool v2; // zf
  Scaleform::GFx::AS3::Value result; // [rsp+28h] [rbp-30h]

  v1 = this;
  Scaleform::GFx::AS3::TR::State::PopOpValue(this, &result);
  Scaleform::GFx::AS3::TR::State::ConvertOpTo(v1, v1->pTracer->CF->pFile->VMRef->TraitsUint.pObject->ITraits.pObject, 0);
  if ( (result.Flags & 0x1F) > 9 )
  {
    if ( (result.Flags >> 9) & 1 )
    {
      v2 = result.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v2 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      result.Bonus.pWeakProxy = 0i64;
      result.value = 0ui64;
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
  Scaleform::GFx::AS3::TR::State *v1; // rbx
  bool v2; // zf
  Scaleform::GFx::AS3::Value result; // [rsp+28h] [rbp-30h]

  v1 = this;
  Scaleform::GFx::AS3::TR::State::PopOpValue(this, &result);
  Scaleform::GFx::AS3::TR::State::ConvertOpTo(
    v1,
    v1->pTracer->CF->pFile->VMRef->TraitsBoolean.pObject->ITraits.pObject,
    0);
  if ( (result.Flags & 0x1F) > 9 )
  {
    if ( (result.Flags >> 9) & 1 )
    {
      v2 = result.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v2 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      result.Bonus.pWeakProxy = 0i64;
      result.value = 0ui64;
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
void __fastcall Scaleform::GFx::AS3::TR::State::exec_istype(Scaleform::GFx::AS3::TR::State *this, unsigned int mn_index)
{
  Scaleform::GFx::AS3::TR::State *v2; // rbx

  v2 = this;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_istype, mn_index);
  Scaleform::GFx::AS3::TR::State::ConvertOpTo(
    v2,
    v2->pTracer->CF->pFile->VMRef->TraitsBoolean.pObject->ITraits.pObject,
    0);
}

// File Line: 1413
// RVA: 0x845880
void __fastcall Scaleform::GFx::AS3::TR::State::exec_pushscope(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::TR::State *v1; // rbx
  signed __int64 v2; // rdi

  v1 = this;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_pushscope);
  v2 = (signed __int64)&v1->OpStack.Data.Data[v1->OpStack.Data.Size];
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v1->ScopeStack.Data.Data,
    v1->ScopeStack.Data.pHeap,
    v1->ScopeStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &v1->ScopeStack.Data.Data[v1->ScopeStack.Data.Size - 1],
    (Scaleform::GFx::AS3::Value *)(v2 - 32));
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v1->OpStack.Data,
    v1->OpStack.Data.Size - 1);
}

// File Line: 1427
// RVA: 0x840D10
void __fastcall Scaleform::GFx::AS3::TR::State::exec_getscopeobject(Scaleform::GFx::AS3::TR::State *this, unsigned int scope_index)
{
  Scaleform::GFx::AS3::TR::State *v2; // rbx
  __int64 v3; // rdi
  Scaleform::GFx::AS3::Value *v4; // rdi

  v2 = this;
  v3 = scope_index;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_getscopeobject, scope_index);
  v4 = &v2->ScopeStack.Data.Data[v3];
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v2->OpStack.Data.Data,
    v2->OpStack.Data.pHeap,
    v2->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &v2->OpStack.Data.Data[v2->OpStack.Data.Size - 1],
    v4);
  v2->OpStack.Data.Data[v2->OpStack.Data.Size - 1].Flags &= 0xFFFFFEFF;
}

// File Line: 1440
// RVA: 0x83E7C0
void __fastcall Scaleform::GFx::AS3::TR::State::exec_deleteproperty(Scaleform::GFx::AS3::TR::State *this, unsigned int mn_index)
{
  Scaleform::GFx::AS3::TR::State *v2; // rdi
  __int64 v3; // rbx
  Scaleform::GFx::AS3::VMFile *v4; // rdx
  int v5; // eax
  long double v6; // rcx
  Scaleform::GFx::AS3::WeakProxy *v7; // rdx
  bool v8; // zf
  Scaleform::GFx::AS3::Value source; // [rsp+18h] [rbp-49h]
  Scaleform::GFx::AS3::TR::StackReader v10; // [rsp+38h] [rbp-29h]
  Scaleform::GFx::AS3::VMFile *v11; // [rsp+50h] [rbp-11h]
  Scaleform::GFx::AS3::Multiname obj; // [rsp+58h] [rbp-9h]
  Scaleform::GFx::AS3::Value result; // [rsp+88h] [rbp+27h]
  __int64 v14; // [rsp+A8h] [rbp+47h]

  v14 = -2i64;
  v2 = this;
  v3 = mn_index;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_deleteproperty, mn_index);
  v4 = (Scaleform::GFx::AS3::VMFile *)&v2->pTracer->CF->pFile->vfptr;
  v10.VMRef = v4->VMRef;
  v10.StateRef = v2;
  v10.Num = 0;
  v11 = v4;
  Scaleform::GFx::AS3::Multiname::Multiname(
    &obj,
    v4,
    (Scaleform::GFx::AS3::Abc::Multiname *)v4[1].vfptr[7].~RefCountBaseGC<328> + v3);
  v5 = Scaleform::GFx::AS3::TR::StackReader::Read(&v10, &obj);
  v10.Num += v5;
  Scaleform::GFx::AS3::TR::State::PopOpValue(v2, &result);
  ++v10.Num;
  v6 = *(double *)&v2->pTracer->CF->pFile->VMRef->TraitsBoolean.pObject->ITraits.pObject;
  source.Bonus.pWeakProxy = 0i64;
  source.value.VNumber = v6;
  source.Flags = 8;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v2->OpStack.Data.Data,
    v2->OpStack.Data.pHeap,
    v2->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &v2->OpStack.Data.Data[v2->OpStack.Data.Size - 1],
    &source);
  if ( (result.Flags & 0x1F) > 9 )
  {
    if ( (result.Flags >> 9) & 1 )
    {
      v7 = result.Bonus.pWeakProxy;
      v8 = result.Bonus.pWeakProxy->RefCount == 1;
      --v7->RefCount;
      if ( v8 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::WeakProxy *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v7);
      result.Bonus.pWeakProxy = 0i64;
      _mm_store_si128((__m128i *)&result.value, (__m128i)0i64);
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
void __fastcall Scaleform::GFx::AS3::TR::State::exec_getslot(Scaleform::GFx::AS3::TR::State *this, unsigned int slot_index, bool simulate)
{
  unsigned __int64 v3; // r15
  Scaleform::GFx::AS3::TR::State *v4; // rsi
  Scaleform::GFx::AS3::Tracer *v5; // rbx
  long double v6; // rdi
  Scaleform::GFx::AS3::VM *v7; // rax
  unsigned __int64 v8; // r14
  unsigned __int64 v9; // r12
  __int64 v10; // rbx
  signed __int64 v11; // rdx
  Scaleform::GFx::AS3::SlotInfo *v12; // r15
  signed __int64 v13; // rdx
  Scaleform::GFx::AS3::SlotInfo *v14; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v15; // rax
  __int64 v16; // rdi
  Scaleform::GFx::AS3::VM::Error *v17; // rax
  __int64 v18; // r8
  __int64 v19; // r9
  Scaleform::GFx::ASStringNode *v20; // rcx
  bool v21; // zf
  Scaleform::GFx::AS3::InstanceTraits::Traits *v22; // r14
  Scaleform::GFx::AS3::Abc::TraitInfo *v23; // rax
  int v24; // eax
  unsigned int v25; // ebx
  int v26; // eax
  __int64 v27; // rax
  Scaleform::GFx::AS3::WeakProxy *v28; // rdx
  Scaleform::GFx::AS3::VM::Error v29; // [rsp+28h] [rbp-58h]
  __int64 v30; // [rsp+38h] [rbp-48h]
  __int64 v31; // [rsp+40h] [rbp-40h]
  Scaleform::GFx::AS3::VM *v32; // [rsp+48h] [rbp-38h]
  Scaleform::GFx::AS3::TR::State *v33; // [rsp+50h] [rbp-30h]
  int v34; // [rsp+58h] [rbp-28h]
  Scaleform::GFx::AS3::Value result; // [rsp+60h] [rbp-20h]

  v3 = slot_index;
  v4 = this;
  if ( !simulate )
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_getslot, slot_index);
  v32 = v4->pTracer->CF->pFile->VMRef;
  v33 = v4;
  Scaleform::GFx::AS3::TR::State::PopOpValue(v4, &result);
  v34 = 1;
  v5 = v4->pTracer;
  if ( result.Flags & 0x1F )
  {
    if ( (result.Flags & 0x1F) == 8 || (result.Flags & 0x1F) == 9 )
      v6 = result.value.VNumber;
    else
      v6 = COERCE_DOUBLE(Scaleform::GFx::AS3::VM::GetValueTraits(v5->CF->pFile->VMRef, &result));
  }
  else
  {
    v6 = *(double *)&v5->CF->pFile->VMRef->TraitsVoid.pObject;
  }
  if ( v6 == 0.0 )
    goto LABEL_50;
  v7 = v5->CF->pFile->VMRef;
  if ( *(Scaleform::GFx::AS3::ClassTraits::ClassClass **)&v6 == v7->TraitsClassClass.pObject )
    v6 = *(double *)&v7->TraitsObject.pObject;
  if ( v6 == 0.0 )
  {
LABEL_50:
    v29.ID = 0;
    v29.Message.pNode = 0i64;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v4->OpStack.Data.Data,
      v4->OpStack.Data.pHeap,
      v4->OpStack.Data.Size + 1);
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
      &v4->OpStack.Data.Data[v4->OpStack.Data.Size - 1],
      (Scaleform::GFx::AS3::Value *)&v29);
    goto LABEL_42;
  }
  v8 = *(_QWORD *)(*(_QWORD *)&v6 + 40i64);
  v9 = v3;
  if ( v3 > v8 + *(_QWORD *)(*(_QWORD *)&v6 + 64i64) )
  {
    v27 = (__int64)v5->CF->pFile->VMRef->TraitsObject.pObject->ITraits.pObject;
    v29.Message.pNode = 0i64;
    v30 = v27;
    v29.ID = 72;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v4->OpStack.Data.Data,
      v4->OpStack.Data.pHeap,
      v4->OpStack.Data.Size + 1);
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
      &v4->OpStack.Data.Data[v4->OpStack.Data.Size - 1],
      (Scaleform::GFx::AS3::Value *)&v29);
    goto LABEL_42;
  }
  v10 = *(_QWORD *)(*(_QWORD *)&v6 + 88i64);
  v11 = (unsigned int)*(_QWORD *)(*(_QWORD *)&v6 + 88i64) + v3 - 1;
  if ( v11 < 0 || v11 < v8 )
    v12 = Scaleform::GFx::AS3::Slots::GetSlotInfo(
            *(Scaleform::GFx::AS3::Slots **)(*(_QWORD *)&v6 + 48i64),
            (Scaleform::GFx::AS3::AbsoluteIndex)v11);
  else
    v12 = (Scaleform::GFx::AS3::SlotInfo *)((((unsigned int)v11 - v8) << 6) + *(_QWORD *)(*(_QWORD *)&v6 + 56i64)
                                                                            + 16i64);
  v13 = (unsigned int)v10 + v9 - 1;
  if ( v13 < 0 || v13 < v8 )
    v14 = Scaleform::GFx::AS3::Slots::GetSlotInfo(
            *(Scaleform::GFx::AS3::Slots **)(*(_QWORD *)&v6 + 48i64),
            (Scaleform::GFx::AS3::AbsoluteIndex)v13);
  else
    v14 = (Scaleform::GFx::AS3::SlotInfo *)((((unsigned int)v13 - v8) << 6) + 16 + *(_QWORD *)(*(_QWORD *)&v6 + 56i64));
  v15 = Scaleform::GFx::AS3::SlotInfo::GetDataType(v14, *(Scaleform::GFx::AS3::VM **)(*(_QWORD *)&v6 + 128i64));
  v16 = (__int64)v15;
  if ( v15 )
  {
    v22 = v15->ITraits.pObject;
    if ( (*(_DWORD *)v12 & 0x7C00) == 1024 || (v23 = v12->TI) != 0i64 && (v23->kind & 0xF) == 4 )
    {
      v26 = Scaleform::GFx::AS3::TR::State::CanBeNull(v4, v22);
      v29.Message.pNode = 0i64;
      v30 = v16;
      v25 = (32 * v26 | 9) & 0xFFFFFEFF;
      v29.ID = (32 * v26 | 9) & 0xFFFFFEFF;
      Scaleform::GFx::AS3::TR::State::PushOp(v4, (Scaleform::GFx::AS3::Value *)&v29);
      if ( (char)(v25 & 0x1F) <= 9 )
        goto LABEL_42;
      if ( (v25 >> 9) & 1 )
      {
        LODWORD(MEMORY[0]) = MEMORY[0] - 1;
        if ( !(_DWORD)MEMORY[0] )
        {
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
          v29.Message.pNode = 0i64;
          v30 = 0i64;
          v31 = 0i64;
          v29.ID = v25 & 0xFFFFFDE0;
          goto LABEL_42;
        }
LABEL_33:
        v29.Message.pNode = 0i64;
        v30 = 0i64;
        v31 = 0i64;
        v29.ID = v25 & 0xFFFFFDE0;
        goto LABEL_42;
      }
    }
    else
    {
      v24 = Scaleform::GFx::AS3::TR::State::CanBeNull(v4, v22);
      v29.Message.pNode = 0i64;
      v30 = (__int64)v22;
      v25 = (32 * v24 | 8) & 0xFFFFFEFF;
      v29.ID = (32 * v24 | 8) & 0xFFFFFEFF;
      Scaleform::GFx::AS3::TR::State::PushOp(v4, (Scaleform::GFx::AS3::Value *)&v29);
      if ( (char)(v25 & 0x1F) <= 9 )
        goto LABEL_42;
      if ( (v25 >> 9) & 1 )
      {
        LODWORD(MEMORY[0]) = MEMORY[0] - 1;
        if ( !(_DWORD)MEMORY[0] )
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
        goto LABEL_33;
      }
    }
    Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v29);
    goto LABEL_42;
  }
  Scaleform::GFx::AS3::VM::Error::Error(&v29, eClassNotFoundError, v4->pTracer->CF->pFile->VMRef);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(
    v4->pTracer->CF->pFile->VMRef,
    v17,
    &Scaleform::GFx::AS3::fl::VerifyErrorTI);
  v20 = v29.Message.pNode;
  v21 = v29.Message.pNode->RefCount == 1;
  --v20->RefCount;
  if ( v21 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v20);
LABEL_42:
  if ( (result.Flags & 0x1F) > 9 )
  {
    if ( (result.Flags >> 9) & 1 )
    {
      v28 = result.Bonus.pWeakProxy;
      v21 = result.Bonus.pWeakProxy->RefCount == 1;
      --v28->RefCount;
      if ( v21 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::WeakProxy *, __int64, __int64, signed __int64, _QWORD, Scaleform::GFx::ASStringNode *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v28,
          v18,
          v19,
          -2i64,
          *(_QWORD *)&v29.ID,
          v29.Message.pNode,
          v30);
      result.Flags &= 0xFFFFFDE0;
      result.Bonus.pWeakProxy = 0i64;
      result.value = 0ui64;
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
  Scaleform::GFx::AS3::TR::State *v2; // rdi
  unsigned int v3; // esi

  v2 = this;
  v3 = rnum;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_setlocal, rnum);
  Scaleform::GFx::AS3::Value::Assign(&v2->Registers.Data.Data[v3], &v2->OpStack.Data.Data[v2->OpStack.Data.Size - 1]);
  v2->RegistersAlive.pData[(unsigned __int64)v3 >> 3] |= 1 << (v3 & 7);
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v2->OpStack.Data,
    v2->OpStack.Data.Size - 1);
}

// File Line: 1615
// RVA: 0x8407B0
void __fastcall Scaleform::GFx::AS3::TR::State::exec_getlocal0(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::TR::State *v1; // rbx
  Scaleform::GFx::AS3::Value *v2; // rdi

  v1 = this;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_getlocal0);
  v2 = v1->Registers.Data.Data;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v1->OpStack.Data.Data,
    v1->OpStack.Data.pHeap,
    v1->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &v1->OpStack.Data.Data[v1->OpStack.Data.Size - 1],
    v2);
}

// File Line: 1628
// RVA: 0x840810
void __fastcall Scaleform::GFx::AS3::TR::State::exec_getlocal1(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::TR::State *v1; // rbx
  Scaleform::GFx::AS3::Value *v2; // rdi

  v1 = this;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_getlocal1);
  v2 = v1->Registers.Data.Data;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v1->OpStack.Data.Data,
    v1->OpStack.Data.pHeap,
    v1->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &v1->OpStack.Data.Data[v1->OpStack.Data.Size - 1],
    v2 + 1);
}

// File Line: 1641
// RVA: 0x840870
void __fastcall Scaleform::GFx::AS3::TR::State::exec_getlocal2(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::TR::State *v1; // rbx
  Scaleform::GFx::AS3::Value *v2; // rdi

  v1 = this;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_getlocal2);
  v2 = v1->Registers.Data.Data;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v1->OpStack.Data.Data,
    v1->OpStack.Data.pHeap,
    v1->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &v1->OpStack.Data.Data[v1->OpStack.Data.Size - 1],
    v2 + 2);
}

// File Line: 1654
// RVA: 0x8408D0
void __fastcall Scaleform::GFx::AS3::TR::State::exec_getlocal3(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::TR::State *v1; // rbx
  Scaleform::GFx::AS3::Value *v2; // rdi

  v1 = this;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_getlocal3);
  v2 = v1->Registers.Data.Data;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v1->OpStack.Data.Data,
    v1->OpStack.Data.pHeap,
    v1->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &v1->OpStack.Data.Data[v1->OpStack.Data.Size - 1],
    v2 + 3);
}

// File Line: 1667
// RVA: 0x846720
void __fastcall Scaleform::GFx::AS3::TR::State::exec_setlocal0(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::TR::State *v1; // rdi
  Scaleform::GFx::AS3::Value *v2; // rbx

  v1 = this;
  v2 = &this->OpStack.Data.Data[this->OpStack.Data.Size];
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_setlocal0);
  Scaleform::GFx::AS3::Value::Assign(v1->Registers.Data.Data, v2 - 1);
  *v1->RegistersAlive.pData |= 1u;
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v1->OpStack.Data,
    v1->OpStack.Data.Size - 1);
}

// File Line: 1685
// RVA: 0x846780
void __fastcall Scaleform::GFx::AS3::TR::State::exec_setlocal1(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::TR::State *v1; // rdi
  Scaleform::GFx::AS3::Value *v2; // rbx

  v1 = this;
  v2 = &this->OpStack.Data.Data[this->OpStack.Data.Size];
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_setlocal1);
  Scaleform::GFx::AS3::Value::Assign(v1->Registers.Data.Data + 1, v2 - 1);
  *v1->RegistersAlive.pData |= 2u;
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v1->OpStack.Data,
    v1->OpStack.Data.Size - 1);
}

// File Line: 1703
// RVA: 0x8467F0
void __fastcall Scaleform::GFx::AS3::TR::State::exec_setlocal2(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::TR::State *v1; // rdi
  Scaleform::GFx::AS3::Value *v2; // rbx

  v1 = this;
  v2 = &this->OpStack.Data.Data[this->OpStack.Data.Size];
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_setlocal2);
  Scaleform::GFx::AS3::Value::Assign(v1->Registers.Data.Data + 2, v2 - 1);
  *v1->RegistersAlive.pData |= 4u;
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v1->OpStack.Data,
    v1->OpStack.Data.Size - 1);
}

// File Line: 1721
// RVA: 0x846860
void __fastcall Scaleform::GFx::AS3::TR::State::exec_setlocal3(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::TR::State *v1; // rdi
  Scaleform::GFx::AS3::Value *v2; // rbx

  v1 = this;
  v2 = &this->OpStack.Data.Data[this->OpStack.Data.Size];
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_setlocal3);
  Scaleform::GFx::AS3::Value::Assign(v1->Registers.Data.Data + 3, v2 - 1);
  *v1->RegistersAlive.pData |= 8u;
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v1->OpStack.Data,
    v1->OpStack.Data.Size - 1);
}

// File Line: 1739
// RVA: 0x7BAEA0
void __fastcall Scaleform::GFx::AS3::TR::State::ConvertOpTo(Scaleform::GFx::AS3::TR::State *this, Scaleform::GFx::AS3::InstanceTraits::Traits *tr, Scaleform::GFx::AS3::Value::TraceNullType isNull)
{
  Scaleform::GFx::AS3::Value *v3; // rcx
  unsigned int v4; // ebx
  bool v5; // zf
  Scaleform::GFx::AS3::Value v6; // [rsp+28h] [rbp-30h]

  v3 = &this->OpStack.Data.Data[this->OpStack.Data.Size - 1];
  v6.Bonus.pWeakProxy = 0i64;
  *(_QWORD *)&v6.value.VNumber = tr;
  v6.Flags = (32 * isNull | 8) & 0xFFFFFEFF;
  Scaleform::GFx::AS3::Value::Assign(v3, &v6);
  v4 = v6.Flags;
  if ( (v6.Flags & 0x1F) > 9 )
  {
    if ( (v6.Flags >> 9) & 1 )
    {
      v5 = v6.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v5 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v6.Bonus.pWeakProxy = 0i64;
      v6.value = 0ui64;
      v6.Flags = v4 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v6);
    }
  }
}

// File Line: 1965
// RVA: 0x7BAF60
void __fastcall Scaleform::GFx::AS3::TR::State::ConvertRegisterTo(Scaleform::GFx::AS3::TR::State *this, Scaleform::GFx::AS3::AbsoluteIndex index, Scaleform::GFx::AS3::InstanceTraits::Traits *tr, Scaleform::GFx::AS3::Value::TraceNullType isNull)
{
  unsigned int v4; // ebx
  bool v5; // zf
  Scaleform::GFx::AS3::Value v6; // [rsp+28h] [rbp-30h]

  v6.Bonus.pWeakProxy = 0i64;
  *(_QWORD *)&v6.value.VNumber = tr;
  v6.Flags = (32 * isNull | 8) & 0xFFFFFEFF;
  Scaleform::GFx::AS3::Value::Assign(&this->Registers.Data.Data[LODWORD(index.Index)], &v6);
  v4 = v6.Flags;
  if ( (v6.Flags & 0x1F) > 9 )
  {
    if ( (v6.Flags >> 9) & 1 )
    {
      v5 = v6.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v5 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v6.Bonus.pWeakProxy = 0i64;
      v6.value = 0ui64;
      v6.Flags = v4 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v6);
    }
  }
}

// File Line: 1982
// RVA: 0x8457D0
void __fastcall Scaleform::GFx::AS3::TR::State::exec_pushnamespace(Scaleform::GFx::AS3::TR::State *this, unsigned int v)
{
  Scaleform::GFx::AS3::TR::State *v2; // rdi
  unsigned int v3; // ebx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v4; // rax
  Scaleform::GFx::AS3::Value source; // [rsp+28h] [rbp-30h]

  v2 = this;
  v3 = v;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_pushnamespace, v);
  v4 = Scaleform::GFx::AS3::VMFile::GetInternedNamespace(
         (Scaleform::GFx::AS3::VMFile *)&v2->pTracer->CF->pFile->vfptr,
         v3);
  source.Flags = 11;
  source.Bonus.pWeakProxy = 0i64;
  *(_QWORD *)&source.value.VNumber = v4;
  if ( v4 )
    v4->RefCount = (v4->RefCount + 1) & 0x8FBFFFFF;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v2->OpStack.Data.Data,
    v2->OpStack.Data.pHeap,
    v2->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &v2->OpStack.Data.Data[v2->OpStack.Data.Size - 1],
    &source);
  Scaleform::GFx::AS3::Value::ReleaseInternal(&source);
}

// File Line: 1994
// RVA: 0x846B50
void __fastcall Scaleform::GFx::AS3::TR::State::exec_setslot(Scaleform::GFx::AS3::TR::State *this, unsigned int slot_index, bool simulate)
{
  Scaleform::GFx::AS3::TR::State *v3; // rbx
  Scaleform::GFx::AS3::VM *v4; // ST30_8
  bool v5; // zf
  Scaleform::GFx::AS3::TR::State *v6; // [rsp+38h] [rbp-1h]
  int v7; // [rsp+40h] [rbp+7h]
  Scaleform::GFx::AS3::Value result; // [rsp+48h] [rbp+Fh]
  Scaleform::GFx::AS3::Value v9; // [rsp+68h] [rbp+2Fh]

  v3 = this;
  if ( !simulate )
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_setslot, slot_index);
  v4 = v3->pTracer->CF->pFile->VMRef;
  v6 = v3;
  v7 = 0;
  Scaleform::GFx::AS3::TR::State::PopOpValue(v3, &result);
  ++v7;
  Scaleform::GFx::AS3::TR::State::PopOpValue(v3, &v9);
  ++v7;
  if ( (v9.Flags & 0x1F) > 9 )
  {
    if ( (v9.Flags >> 9) & 1 )
    {
      v5 = v9.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v5 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      _mm_store_si128((__m128i *)&v9.Bonus, (__m128i)0i64);
      v9.value.VS._2.VObj = 0i64;
      v9.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v9);
    }
  }
  if ( (result.Flags & 0x1F) > 9 )
  {
    if ( (result.Flags >> 9) & 1 )
    {
      v5 = result.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v5 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      _mm_store_si128((__m128i *)&result.Bonus, (__m128i)0i64);
      result.value.VS._2.VObj = 0i64;
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
void __fastcall Scaleform::GFx::AS3::TR::State::exec_astype(Scaleform::GFx::AS3::TR::State *this, unsigned int mn_index)
{
  Scaleform::GFx::AS3::TR::State *v2; // rdi
  __int64 v3; // rbx
  Scaleform::GFx::AS3::VMAbcFile *v4; // r8
  Scaleform::GFx::AS3::VM *v5; // ST30_8
  signed __int64 v6; // ST50_8
  bool v7; // zf
  Scaleform::GFx::AS3::Value result; // [rsp+58h] [rbp-30h]

  v2 = this;
  v3 = mn_index;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_astype, mn_index);
  v4 = v2->pTracer->CF->pFile;
  v5 = v4->VMRef;
  v6 = (signed __int64)&v4->File.pObject->Const_Pool.const_multiname.Data.Data[v3];
  Scaleform::GFx::AS3::TR::State::PopOpValue(v2, &result);
  if ( (result.Flags & 0x1F) > 9 )
  {
    if ( (result.Flags >> 9) & 1 )
    {
      v7 = result.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v7 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      _mm_store_si128((__m128i *)&result.Bonus, (__m128i)0i64);
      result.value.VS._2.VObj = 0i64;
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
  Scaleform::GFx::AS3::TR::State *v2; // rdi
  __int64 v3; // rbx
  Scaleform::GFx::AS3::VMFile *v4; // rbp
  Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *v5; // rcx
  Scaleform::GFx::AS3::Abc::ClassInfo *v6; // r14
  Scaleform::GFx::AS3::Abc::Multiname *v7; // rbx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v8; // rax
  bool v9; // al
  Scaleform::GFx::AS3::VM *v10; // rcx
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v11; // rax
  long double v12; // rdx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v13; // r8
  Scaleform::GFx::AS3::VM *v14; // rax
  Scaleform::GFx::AS3::ClassTraits::fl::Boolean *v15; // rcx
  char v16; // al
  signed int v17; // ebx
  unsigned int v18; // ebx
  Scaleform::GFx::AS3::Value source; // [rsp+28h] [rbp-30h]

  v2 = this;
  v3 = v;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_newclass, v);
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v2->OpStack.Data,
    v2->OpStack.Data.Size - 1);
  v4 = (Scaleform::GFx::AS3::VMFile *)&v2->pTracer->CF->pFile->vfptr;
  v5 = v4[1].vfptr;
  v6 = (Scaleform::GFx::AS3::Abc::ClassInfo *)*((_QWORD *)v5[12].~RefCountBaseGC<328> + v3);
  v7 = (Scaleform::GFx::AS3::Abc::Multiname *)((char *)v5[7].~RefCountBaseGC<328> + 16 * v6->inst_info.name_ind);
  v8 = Scaleform::GFx::AS3::VMFile::GetInternedNamespace(
         (Scaleform::GFx::AS3::VMFile *)&v2->pTracer->CF->pFile->vfptr,
         v7->Ind);
  v9 = Scaleform::GFx::AS3::IsScaleformGFx(v8);
  v10 = v2->pTracer->CF->pFile->VMRef;
  if ( v9 )
    v11 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(v10, v4, v7);
  else
    v11 = (Scaleform::GFx::AS3::ClassTraits::ClassClass *)Scaleform::GFx::AS3::VM::GetUserDefinedTraits(v10, v4, v6);
  v12 = *(double *)&v11;
  if ( !v11 )
    v12 = *(double *)&v2->pTracer->CF->pFile->VMRef->TraitsObject.pObject;
  v13 = *(Scaleform::GFx::AS3::InstanceTraits::Traits **)(*(_QWORD *)&v12 + 200i64);
  v14 = v2->pTracer->CF->pFile->VMRef;
  if ( v13 == v14->TraitsInt.pObject->ITraits.pObject
    || v13 == v14->TraitsUint.pObject->ITraits.pObject
    || v13 == v14->TraitsNumber.pObject->ITraits.pObject
    || (v15 = v14->TraitsBoolean.pObject, v16 = 0, v13 == v15->ITraits.pObject) )
  {
    v16 = 1;
  }
  source.Flags = 9;
  source.Bonus.pWeakProxy = 0i64;
  source.value.VNumber = v12;
  v17 = 2;
  if ( v16 )
    v17 = 0;
  v18 = (32 * v17 | 9) & 0xFFFFFEFF;
  source.Flags = v18;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v2->OpStack.Data.Data,
    v2->OpStack.Data.pHeap,
    v2->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &v2->OpStack.Data.Data[v2->OpStack.Data.Size - 1],
    &source);
  if ( (char)(v18 & 0x1F) > 9 )
  {
    if ( (v18 >> 9) & 1 )
    {
      LODWORD(MEMORY[0]) = MEMORY[0] - 1;
      if ( !(_DWORD)MEMORY[0] )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
      source.Bonus.pWeakProxy = 0i64;
      source.value = 0ui64;
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
void __fastcall Scaleform::GFx::AS3::TR::State::State(Scaleform::GFx::AS3::TR::State *this, Scaleform::GFx::AS3::Tracer *tr, unsigned __int64 cp)
{
  Scaleform::GFx::AS3::TR::State *v3; // rsi
  Scaleform::MemoryHeap *v4; // r8
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v5; // rax
  Scaleform::MemoryHeap *v6; // rcx
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v7; // rax
  Scaleform::MemoryHeap *v8; // rcx
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v9; // rax
  Scaleform::MemoryHeap *v10; // rcx
  unsigned int v11; // ebx
  char *v12; // rax
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v13; // [rsp+58h] [rbp+10h]
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v14; // [rsp+60h] [rbp+18h]

  v3 = this;
  this->pTracer = tr;
  this->BCP = cp;
  this->OpcodeCP = cp;
  v4 = tr->Heap;
  v5 = &this->Registers;
  v13 = &this->Registers;
  v14 = &this->Registers;
  v5->Data.Data = 0i64;
  v5->Data.Size = 0i64;
  v5->Data.Policy.Capacity = 0i64;
  this->Registers.Data.pHeap = v4;
  v6 = tr->Heap;
  v7 = &v3->OpStack;
  v13 = &v3->OpStack;
  v14 = &v3->OpStack;
  v7->Data.Data = 0i64;
  v7->Data.Size = 0i64;
  v7->Data.Policy.Capacity = 0i64;
  v3->OpStack.Data.pHeap = v6;
  v8 = tr->Heap;
  v9 = &v3->ScopeStack;
  v13 = &v3->ScopeStack;
  v14 = &v3->ScopeStack;
  v9->Data.Data = 0i64;
  v9->Data.Size = 0i64;
  v9->Data.Policy.Capacity = 0i64;
  v3->ScopeStack.Data.pHeap = v8;
  LODWORD(v9) = tr->CF->pFile->File.pObject->MethodBodies.Info.Data.Data[tr->CF->MBIIndex.Ind]->local_reg_count;
  v10 = tr->Heap;
  v14 = (Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *)&v3->RegistersAlive;
  v3->RegistersAlive.BitsCount = (unsigned int)v9;
  v11 = (unsigned int)((_DWORD)v9 + 7) >> 3;
  LODWORD(v13) = 341;
  v12 = (char *)v10->vfptr->Alloc(v10, v11, (Scaleform::AllocInfo *)&v13);
  v3->RegistersAlive.pData = v12;
  memset(v12, 0, v11);
}

// File Line: 2163
// RVA: 0x80F7B0
void __fastcall Scaleform::GFx::AS3::TR::State::RefineOpCodeStack1(Scaleform::GFx::AS3::TR::State *this, Scaleform::GFx::AS3::Abc::Code::OpCode opcode, Scaleform::GFx::AS3::InstanceTraits::Traits *type, Scaleform::GFx::AS3::Abc::Code::OpCode op)
{
  Scaleform::GFx::AS3::Abc::Code::OpCode v4; // ebp
  Scaleform::GFx::AS3::Abc::Code::OpCode v5; // esi
  Scaleform::GFx::AS3::InstanceTraits::Traits *v6; // rbx
  Scaleform::GFx::AS3::TR::State *v7; // rdi
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v8; // rax
  Scaleform::GFx::AS3::Tracer *v9; // rcx
  Scaleform::GFx::AS3::VM *v10; // rcx
  char v11; // al
  Scaleform::GFx::AS3::Value::TraceNullType v12; // er8

  v4 = opcode;
  v5 = op;
  v6 = type;
  v7 = this;
  v8 = Scaleform::GFx::AS3::TR::State::GetValueTraits(this, &this->OpStack.Data.Data[this->OpStack.Data.Size - 1]);
  v9 = v7->pTracer;
  if ( v8 == (Scaleform::GFx::AS3::ClassTraits::fl::Object *)v6 )
  {
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(v9, v5);
  }
  else
  {
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(v9, v4);
    v10 = v7->pTracer->CF->pFile->VMRef;
    if ( v6 == v10->TraitsInt.pObject->ITraits.pObject
      || v6 == v10->TraitsUint.pObject->ITraits.pObject
      || v6 == v10->TraitsNumber.pObject->ITraits.pObject
      || (v11 = 0, v6 == v10->TraitsBoolean.pObject->ITraits.pObject) )
    {
      v11 = 1;
    }
    v12 = 2;
    if ( v11 )
      v12 = 0;
    Scaleform::GFx::AS3::TR::State::ConvertOpTo(v7, v6, v12);
  }
}

// File Line: 2194
// RVA: 0x80F890
void __fastcall Scaleform::GFx::AS3::TR::State::RefineOpCodeStack2(Scaleform::GFx::AS3::TR::State *this, Scaleform::GFx::AS3::Abc::Code::OpCode opcode, Scaleform::GFx::AS3::InstanceTraits::Traits *type, Scaleform::GFx::AS3::Abc::Code::OpCode op)
{
  Scaleform::GFx::AS3::Abc::Code::OpCode v4; // ebp
  Scaleform::GFx::AS3::InstanceTraits::Traits *v5; // rbx
  Scaleform::GFx::AS3::Abc::Code::OpCode v6; // er14
  Scaleform::GFx::AS3::TR::State *v7; // rsi
  Scaleform::GFx::AS3::Tracer *v8; // rdi
  long double v9; // rcx
  Scaleform::GFx::AS3::VM *v10; // rax
  Scaleform::GFx::AS3::VM *v11; // rax
  Scaleform::GFx::AS3::ClassTraits::fl::Boolean *v12; // rcx
  char v13; // al
  Scaleform::GFx::AS3::Value::TraceNullType v14; // er8
  bool v15; // zf
  Scaleform::GFx::AS3::Value v; // [rsp+28h] [rbp-40h]

  v4 = op;
  v5 = type;
  v6 = opcode;
  v7 = this;
  Scaleform::GFx::AS3::TR::State::PopOpValue(this, &v);
  if ( Scaleform::GFx::AS3::TR::State::GetValueTraits(v7, &v7->OpStack.Data.Data[v7->OpStack.Data.Size - 1]) != (Scaleform::GFx::AS3::ClassTraits::fl::Object *)v5 )
    goto LABEL_29;
  v8 = v7->pTracer;
  if ( v.Flags & 0x1F )
  {
    if ( (v.Flags & 0x1F) == 8 || (v.Flags & 0x1F) == 9 )
      v9 = v.value.VNumber;
    else
      v9 = COERCE_DOUBLE(Scaleform::GFx::AS3::VM::GetValueTraits(v8->CF->pFile->VMRef, &v));
  }
  else
  {
    v9 = *(double *)&v8->CF->pFile->VMRef->TraitsVoid.pObject;
  }
  if ( v9 != 0.0 )
  {
    v10 = v8->CF->pFile->VMRef;
    if ( *(Scaleform::GFx::AS3::ClassTraits::ClassClass **)&v9 == v10->TraitsClassClass.pObject )
      v9 = *(double *)&v10->TraitsObject.pObject;
  }
  if ( *(Scaleform::GFx::AS3::InstanceTraits::Traits **)&v9 != v5 )
  {
LABEL_29:
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(v7->pTracer, v6);
    v11 = v7->pTracer->CF->pFile->VMRef;
    if ( v5 == v11->TraitsInt.pObject->ITraits.pObject
      || v5 == v11->TraitsUint.pObject->ITraits.pObject
      || v5 == v11->TraitsNumber.pObject->ITraits.pObject
      || (v12 = v11->TraitsBoolean.pObject, v13 = 0, v5 == v12->ITraits.pObject) )
    {
      v13 = 1;
    }
    v14 = 2;
    if ( v13 )
      v14 = 0;
    Scaleform::GFx::AS3::TR::State::ConvertOpTo(v7, v5, v14);
  }
  else
  {
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(v8, v4);
  }
  if ( (v.Flags & 0x1F) > 9 )
  {
    if ( (v.Flags >> 9) & 1 )
    {
      v15 = v.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v15 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v.Bonus.pWeakProxy = 0i64;
      v.value = 0ui64;
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
void __fastcall Scaleform::GFx::AS3::TR::State::RefineOpCodeReg1(Scaleform::GFx::AS3::TR::State *this, Scaleform::GFx::AS3::Abc::Code::OpCode opcode, Scaleform::GFx::AS3::InstanceTraits::Traits *type, Scaleform::GFx::AS3::Abc::Code::OpCode op, int reg_num)
{
  Scaleform::GFx::AS3::Abc::Code::OpCode v5; // er14
  Scaleform::GFx::AS3::Abc::Code::OpCode v6; // ebp
  Scaleform::GFx::AS3::InstanceTraits::Traits *v7; // rbx
  Scaleform::GFx::AS3::TR::State *v8; // rdi
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v9; // rax
  Scaleform::GFx::AS3::Tracer *v10; // rcx
  Scaleform::GFx::AS3::VM *v11; // rcx
  char v12; // al
  Scaleform::GFx::AS3::Value::TraceNullType v13; // er9

  v5 = opcode;
  v6 = op;
  v7 = type;
  v8 = this;
  v9 = Scaleform::GFx::AS3::TR::State::GetValueTraits(this, &this->Registers.Data.Data[reg_num]);
  v10 = v8->pTracer;
  if ( v9 == (Scaleform::GFx::AS3::ClassTraits::fl::Object *)v7 )
  {
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(v10, v6, reg_num);
  }
  else
  {
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(v10, v5, reg_num);
    v11 = v8->pTracer->CF->pFile->VMRef;
    if ( v7 == v11->TraitsInt.pObject->ITraits.pObject
      || v7 == v11->TraitsUint.pObject->ITraits.pObject
      || v7 == v11->TraitsNumber.pObject->ITraits.pObject
      || (v12 = 0, v7 == v11->TraitsBoolean.pObject->ITraits.pObject) )
    {
      v12 = 1;
    }
    v13 = 2;
    if ( v12 )
      v13 = 0;
    Scaleform::GFx::AS3::TR::State::ConvertRegisterTo(v8, (Scaleform::GFx::AS3::AbsoluteIndex)reg_num, v7, v13);
  }
}

// File Line: 2251
// RVA: 0x8454C0
void __fastcall Scaleform::GFx::AS3::TR::State::exec_pop(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::Tracer *v1; // rdi
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *v2; // rbx
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v3; // rax
  Scaleform::GFx::AS3::VM *v4; // r9
  Scaleform::GFx::AS3::Abc::Code::OpCode v5; // edx

  v1 = this->pTracer;
  v2 = &this->OpStack.Data;
  v3 = Scaleform::GFx::AS3::TR::State::GetValueTraits(this, &this->OpStack.Data.Data[this->OpStack.Data.Size - 1]);
  v4 = v1->CF->pFile->VMRef;
  if ( v3 == (Scaleform::GFx::AS3::ClassTraits::fl::Object *)v4->TraitsBoolean.pObject->ITraits.pObject
    || v3 == (Scaleform::GFx::AS3::ClassTraits::fl::Object *)v4->TraitsVoid.pObject
    || v3 == (Scaleform::GFx::AS3::ClassTraits::fl::Object *)v4->TraitsNull.pObject
    || v3 == (Scaleform::GFx::AS3::ClassTraits::fl::Object *)v4->TraitsInt.pObject->ITraits.pObject
    || v3 == (Scaleform::GFx::AS3::ClassTraits::fl::Object *)v4->TraitsUint.pObject->ITraits.pObject
    || (v5 = 41, v3 == (Scaleform::GFx::AS3::ClassTraits::fl::Object *)v4->TraitsNumber.pObject->ITraits.pObject) )
  {
    v5 = 107;
  }
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(v1, v5);
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    v2,
    v2->Size - 1);
}

// File Line: 2278
// RVA: 0x83EB70
void __fastcall Scaleform::GFx::AS3::TR::State::exec_dup(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::TR::State *v1; // rsi
  Scaleform::GFx::AS3::Tracer *v2; // rdi
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v3; // rax
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v4; // r8
  Scaleform::GFx::AS3::VMAbcFile *v5; // r9
  Scaleform::GFx::AS3::VM *v6; // rcx
  Scaleform::GFx::AS3::VM *v7; // rax
  Scaleform::GFx::AS3::Abc::Code::OpCode v8; // edx
  Scaleform::GFx::AS3::Value::VU *v9; // rdx
  int v10; // eax
  long double v11; // rax

  v1 = this;
  v2 = this->pTracer;
  v3 = Scaleform::GFx::AS3::TR::State::GetValueTraits(this, &this->OpStack.Data.Data[this->OpStack.Data.Size - 1]);
  v4 = v3;
  v5 = v2->CF->pFile;
  v6 = v5->VMRef;
  if ( v3 == (Scaleform::GFx::AS3::ClassTraits::fl::Object *)v6->TraitsBoolean.pObject->ITraits.pObject
    || v3 == (Scaleform::GFx::AS3::ClassTraits::fl::Object *)v6->TraitsVoid.pObject
    || (v7 = v5->VMRef, v4 == (Scaleform::GFx::AS3::ClassTraits::fl::Object *)v6->TraitsNull.pObject)
    || v4 == (Scaleform::GFx::AS3::ClassTraits::fl::Object *)v6->TraitsInt.pObject->ITraits.pObject
    || v4 == (Scaleform::GFx::AS3::ClassTraits::fl::Object *)v7->TraitsUint.pObject->ITraits.pObject
    || (v8 = 42, v4 == (Scaleform::GFx::AS3::ClassTraits::fl::Object *)v7->TraitsNumber.pObject->ITraits.pObject) )
  {
    v8 = 105;
  }
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(v2, v8);
  if ( !(_S11_12 & 1) )
  {
    _S11_12 |= 1u;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0i64;
    atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
  }
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v1->OpStack.Data.Data,
    v1->OpStack.Data.pHeap,
    v1->OpStack.Data.Size + 1);
  v9 = (Scaleform::GFx::AS3::Value::VU *)&v1->OpStack.Data.Data[v1->OpStack.Data.Size - 1];
  if ( v9 )
  {
    LODWORD(v9->VS._1.VStr) = v.Flags;
    v9->VS._2.VObj = (Scaleform::GFx::AS3::Object *)v.Bonus.pWeakProxy;
    v9[1] = v.value;
    v10 = v.Flags & 0x1F;
    if ( v10 > 9 )
    {
      if ( (v.Flags >> 9) & 1 )
      {
        ++v.Bonus.pWeakProxy->RefCount;
      }
      else
      {
        if ( v10 == 10 )
        {
          ++*(_DWORD *)(*(_QWORD *)&v.value.VNumber + 24i64);
          goto LABEL_23;
        }
        if ( v10 > 10 )
        {
          if ( v10 <= 15 )
          {
            v11 = v.value.VNumber;
          }
          else
          {
            if ( v10 > 17 )
              goto LABEL_23;
            v11 = *(double *)&v.value.VS._2.VObj;
          }
          if ( v11 != 0.0 )
          {
            ++*(_DWORD *)(*(_QWORD *)&v11 + 32i64);
            *(_DWORD *)(*(_QWORD *)&v11 + 32i64) &= 0x8FBFFFFF;
          }
        }
      }
    }
  }
LABEL_23:
  Scaleform::GFx::AS3::Value::AssignUnsafe(
    &v1->OpStack.Data.Data[v1->OpStack.Data.Size - 1],
    &v1->OpStack.Data.Data[v1->OpStack.Data.Size - 2]);
}

// File Line: 2339
// RVA: 0x83E740
void __fastcall Scaleform::GFx::AS3::TR::State::exec_convert_u(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::TR::State *v1; // rbx
  Scaleform::GFx::AS3::Value *v2; // rcx
  int v3; // eax
  Scaleform::GFx::AS3::CheckResult result; // [rsp+30h] [rbp+8h]

  v1 = this;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_convert_u);
  v2 = &v1->OpStack.Data.Data[v1->OpStack.Data.Size - 1];
  v3 = v2->Flags & 0x1F;
  if ( v3 <= 4 || v3 == 10 )
    Scaleform::GFx::AS3::Value::ToUInt32Value(v2, &result);
  else
    Scaleform::GFx::AS3::TR::State::ConvertOpTo(
      v1,
      v1->pTracer->CF->pFile->VMRef->TraitsUint.pObject->ITraits.pObject,
      0);
}

// File Line: 2356
// RVA: 0x8402A0
void __fastcall Scaleform::GFx::AS3::TR::State::exec_getglobalslot(Scaleform::GFx::AS3::TR::State *this, unsigned int slot_index)
{
  Scaleform::GFx::AS3::TR::State *v2; // rbx
  Scaleform::GFx::AS3::Value source; // [rsp+28h] [rbp-30h]

  v2 = this;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_getglobalslot, slot_index);
  source.Flags = 0;
  source.Bonus.pWeakProxy = 0i64;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v2->OpStack.Data.Data,
    v2->OpStack.Data.pHeap,
    v2->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &v2->OpStack.Data.Data[v2->OpStack.Data.Size - 1],
    &source);
}

// File Line: 2368
// RVA: 0x8465F0
void __fastcall Scaleform::GFx::AS3::TR::State::exec_setglobalslot(Scaleform::GFx::AS3::TR::State *this, unsigned int slot_index)
{
  Scaleform::GFx::AS3::TR::State *v2; // rbx

  v2 = this;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_setglobalslot, slot_index);
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v2->OpStack.Data,
    v2->OpStack.Data.Size - 1);
}

// File Line: 2380
// RVA: 0x83F320
void __fastcall Scaleform::GFx::AS3::TR::State::exec_esc_xelem(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::TR::State *v1; // rbx

  v1 = this;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_esc_xelem);
  Scaleform::GFx::AS3::TR::State::ConvertOpTo(
    v1,
    v1->pTracer->CF->pFile->VMRef->TraitsString.pObject->ITraits.pObject,
    0);
}

// File Line: 2392
// RVA: 0x83F200
void __fastcall Scaleform::GFx::AS3::TR::State::exec_esc_xattr(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::TR::State *v1; // rbx

  v1 = this;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_esc_xattr);
  Scaleform::GFx::AS3::TR::State::ConvertOpTo(
    v1,
    v1->pTracer->CF->pFile->VMRef->TraitsString.pObject->ITraits.pObject,
    0);
}

// File Line: 2401
// RVA: 0x83E6C0
void __usercall Scaleform::GFx::AS3::TR::State::exec_convert_i(Scaleform::GFx::AS3::TR::State *this@<rcx>, __int64 a2@<rsi>)
{
  Scaleform::GFx::AS3::TR::State *v2; // rbx
  Scaleform::GFx::AS3::Value *v3; // rcx
  int v4; // eax
  Scaleform::GFx::AS3::CheckResult result; // [rsp+30h] [rbp+8h]

  v2 = this;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_convert_i);
  v3 = &v2->OpStack.Data.Data[v2->OpStack.Data.Size - 1];
  v4 = v3->Flags & 0x1F;
  if ( v4 <= 4 || v4 == 10 )
    Scaleform::GFx::AS3::Value::ToInt32Value(v3, &result, a2);
  else
    Scaleform::GFx::AS3::TR::State::ConvertOpTo(
      v2,
      v2->pTracer->CF->pFile->VMRef->TraitsInt.pObject->ITraits.pObject,
      0);
}

// File Line: 2424
// RVA: 0x83E640
void __fastcall Scaleform::GFx::AS3::TR::State::exec_convert_d(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::TR::State *v1; // rbx
  Scaleform::GFx::AS3::Value *v2; // rcx
  int v3; // eax
  Scaleform::GFx::AS3::CheckResult result; // [rsp+30h] [rbp+8h]

  v1 = this;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_convert_d);
  v2 = &v1->OpStack.Data.Data[v1->OpStack.Data.Size - 1];
  v3 = v2->Flags & 0x1F;
  if ( v3 <= 4 || v3 == 10 )
    Scaleform::GFx::AS3::Value::ToNumberValue(v2, &result);
  else
    Scaleform::GFx::AS3::TR::State::ConvertOpTo(
      v1,
      v1->pTracer->CF->pFile->VMRef->TraitsNumber.pObject->ITraits.pObject,
      0);
}

// File Line: 2447
// RVA: 0x83E5B0
void __fastcall Scaleform::GFx::AS3::TR::State::exec_convert_b(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::TR::State *v1; // rbx
  signed __int64 v2; // rdi
  int v3; // eax
  char v4; // al

  v1 = this;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_convert_b);
  v2 = (signed __int64)&v1->OpStack.Data.Data[v1->OpStack.Data.Size];
  v3 = *(_DWORD *)(v2 - 32) & 0x1F;
  if ( v3 <= 4 || v3 == 10 )
  {
    v4 = Scaleform::GFx::AS3::Value::Convert2Boolean((Scaleform::GFx::AS3::Value *)(v2 - 32));
    Scaleform::GFx::AS3::Value::SetBool((Scaleform::GFx::AS3::Value *)(v2 - 32), v4);
  }
  else
  {
    Scaleform::GFx::AS3::TR::State::ConvertOpTo(
      v1,
      v1->pTracer->CF->pFile->VMRef->TraitsBoolean.pObject->ITraits.pObject,
      0);
  }
}

// File Line: 2464
// RVA: 0x8252F0
void __fastcall Scaleform::GFx::AS3::TR::State::SwapOp(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::TR::State *v1; // rdi
  unsigned __int64 v2; // rbx
  unsigned __int64 v3; // r10
  Scaleform::GFx::AS3::Value *v4; // rdx
  unsigned int v5; // er8
  Scaleform::GFx::AS3::WeakProxy *v6; // r9
  int v7; // eax
  long double v8; // rcx
  unsigned int v9; // ebx
  bool v10; // zf
  Scaleform::GFx::AS3::Value other; // [rsp+28h] [rbp-30h]

  v1 = this;
  v2 = this->OpStack.Data.Size;
  v3 = v2 - 1;
  v4 = &this->OpStack.Data.Data[v3];
  v5 = v4->Flags;
  other.Flags = v5;
  v6 = v4->Bonus.pWeakProxy;
  other.Bonus.pWeakProxy = v4->Bonus.pWeakProxy;
  other.value = v4->value;
  v7 = v5 & 0x1F;
  if ( v7 > 9 )
  {
    if ( (v5 >> 9) & 1 )
    {
      ++v6->RefCount;
      goto LABEL_13;
    }
    if ( v7 == 10 )
    {
      ++*(_DWORD *)(*(_QWORD *)&v4->value.VNumber + 24i64);
    }
    else
    {
      if ( v7 <= 10 )
        goto LABEL_13;
      if ( v7 <= 15 )
      {
        v8 = v4->value.VNumber;
      }
      else
      {
        if ( v7 > 17 )
          goto LABEL_13;
        v8 = *(double *)&v4->value.VS._2.VObj;
      }
      if ( v8 != 0.0 )
        *(_DWORD *)(*(_QWORD *)&v8 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v8 + 32i64) + 1) & 0x8FBFFFFF;
    }
  }
LABEL_13:
  Scaleform::GFx::AS3::Value::Assign(&v1->OpStack.Data.Data[v3], &v1->OpStack.Data.Data[v3 - 1]);
  Scaleform::GFx::AS3::Value::Assign(&v1->OpStack.Data.Data[v2 - 2], &other);
  v9 = other.Flags;
  if ( (other.Flags & 0x1F) > 9 )
  {
    if ( (other.Flags >> 9) & 1 )
    {
      v10 = other.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v10 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      other.Bonus.pWeakProxy = 0i64;
      other.value = 0ui64;
      other.Flags = v9 & 0xFFFFFDE0;
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
  Scaleform::GFx::AS3::TR::State *v2; // rbx
  Scaleform::GFx::AS3::Tracer *v3; // rcx
  Scaleform::GFx::AS3::VM::Error *v4; // rax
  Scaleform::GFx::AS3::VM::Error *v5; // rax
  Scaleform::GFx::ASStringNode *v6; // rcx
  bool v7; // zf
  Scaleform::GFx::AS3::VM::Error v8; // [rsp+28h] [rbp-20h]

  v2 = this;
  v3 = this->pTracer;
  if ( v3->CF->pFile->VMRef->XMLSupport_.pObject->Enabled )
  {
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(v3, op_dxns, index);
    if ( v2->pTracer->CF->pFile->File.pObject->Methods.Info.Data.Data[v2->pTracer->CF->pFile->File.pObject->MethodBodies.Info.Data.Data[v2->pTracer->CF->MBIIndex.Ind]->method_info_ind]->Flags & 0x40 )
      return;
    Scaleform::GFx::AS3::VM::Error::Error(&v8, eNotImplementedError, v2->pTracer->CF->pFile->VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      v2->pTracer->CF->pFile->VMRef,
      v5,
      &Scaleform::GFx::AS3::fl::VerifyErrorTI);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v8, eNotImplementedError, v3->CF->pFile->VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      v2->pTracer->CF->pFile->VMRef,
      v4,
      &Scaleform::GFx::AS3::fl::VerifyErrorTI);
  }
  v6 = v8.Message.pNode;
  v7 = v8.Message.pNode->RefCount == 1;
  --v6->RefCount;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
}

// File Line: 2529
// RVA: 0x83EE60
void __fastcall Scaleform::GFx::AS3::TR::State::exec_dxnslate(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::TR::State *v1; // rbx
  Scaleform::GFx::AS3::VM::Error *v2; // rax
  Scaleform::GFx::AS3::VM::Error *v3; // rax
  Scaleform::GFx::ASStringNode *v4; // rcx
  bool v5; // zf
  Scaleform::GFx::AS3::VM::Error v6; // [rsp+28h] [rbp-20h]

  v1 = this;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_dxnslate);
  if ( v1->pTracer->CF->pFile->VMRef->XMLSupport_.pObject->Enabled )
  {
    Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      &v1->OpStack.Data,
      v1->OpStack.Data.Size - 1);
    if ( v1->pTracer->CF->pFile->File.pObject->Methods.Info.Data.Data[v1->pTracer->CF->pFile->File.pObject->MethodBodies.Info.Data.Data[v1->pTracer->CF->MBIIndex.Ind]->method_info_ind]->Flags & 0x40 )
      return;
    Scaleform::GFx::AS3::VM::Error::Error(&v6, eNotImplementedError, v1->pTracer->CF->pFile->VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      v1->pTracer->CF->pFile->VMRef,
      v3,
      &Scaleform::GFx::AS3::fl::VerifyErrorTI);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v6, eNotImplementedError, v1->pTracer->CF->pFile->VMRef);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      v1->pTracer->CF->pFile->VMRef,
      v2,
      &Scaleform::GFx::AS3::fl::VerifyErrorTI);
  }
  v4 = v6.Message.pNode;
  v5 = v6.Message.pNode->RefCount == 1;
  --v4->RefCount;
  if ( v5 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
}

// File Line: 2553
// RVA: 0x845F20
void __fastcall Scaleform::GFx::AS3::TR::State::exec_pushwith(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::TR::State *v1; // rbx
  Scaleform::GFx::AS3::Value *v2; // rdi
  bool v3; // zf
  Scaleform::GFx::AS3::Value result; // [rsp+28h] [rbp-30h]

  v1 = this;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_pushwith);
  v2 = Scaleform::GFx::AS3::TR::State::PopOpValue(v1, &result);
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v1->ScopeStack.Data.Data,
    v1->ScopeStack.Data.pHeap,
    v1->ScopeStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &v1->ScopeStack.Data.Data[v1->ScopeStack.Data.Size - 1],
    v2);
  if ( (result.Flags & 0x1F) > 9 )
  {
    if ( (result.Flags >> 9) & 1 )
    {
      v3 = result.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v3 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      result.Bonus.pWeakProxy = 0i64;
      result.value = 0ui64;
      result.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
    }
  }
  v1->ScopeStack.Data.Data[v1->ScopeStack.Data.Size - 1].Flags |= 0x100u;
}

// File Line: 2567
// RVA: 0x845580
void __fastcall Scaleform::GFx::AS3::TR::State::exec_popscope(Scaleform::GFx::AS3::TR::State *this)
{
  Scaleform::GFx::AS3::TR::State *v1; // rbx

  v1 = this;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_popscope);
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v1->ScopeStack.Data,
    v1->ScopeStack.Data.Size - 1);
}

// File Line: 2690
// RVA: 0x841E50
void __fastcall Scaleform::GFx::AS3::TR::State::exec_if(Scaleform::GFx::AS3::TR::State *this, unsigned __int64 *bcp, Scaleform::GFx::AS3::Abc::Code::OpCode opcode)
{
  Scaleform::GFx::AS3::Value *v3; // rsi
  Scaleform::GFx::AS3::Tracer *v4; // rdi
  unsigned __int64 *v5; // r12
  Scaleform::GFx::AS3::TR::State *v6; // r14
  unsigned __int64 v7; // rbp
  Scaleform::GFx::AS3::Abc::Code::OpCode v8; // ebx
  const char *v9; // rax
  char v10; // r9
  int v11; // edx
  int v12; // er8
  int v13; // ebx
  int v14; // ebx

  v3 = this->OpStack.Data.Data;
  v4 = this->pTracer;
  v5 = bcp;
  v6 = this;
  v7 = this->OpStack.Data.Size;
  v8 = opcode;
  if ( Scaleform::GFx::AS3::Tracer::IsSIntType(this->pTracer, &v3[v7 - 1])
    && Scaleform::GFx::AS3::Tracer::IsSIntType(v4, &v3[v6->OpStack.Data.Size - 2]) )
  {
    switch ( v8 )
    {
      case 12:
        v8 = 138;
        break;
      case 13:
        v8 = 139;
        break;
      case 14:
        v8 = 140;
        break;
      case 15:
        v8 = 141;
        break;
      case 19:
      case 25:
        v8 = 142;
        break;
      case 20:
      case 26:
        v8 = 159;
        break;
      case 21:
        v8 = 158;
        break;
      case 22:
        v8 = 157;
        break;
      case 23:
        v8 = 156;
        break;
      case 24:
        v8 = 143;
        break;
      default:
        break;
    }
  }
  else if ( Scaleform::GFx::AS3::Tracer::IsNumberType(v4, &v3[v7 - 1])
         && Scaleform::GFx::AS3::Tracer::IsNumberType(v4, &v3[v6->OpStack.Data.Size - 2]) )
  {
    switch ( v8 )
    {
      case 12:
        v8 = 200;
        break;
      case 13:
        v8 = 201;
        break;
      case 14:
        v8 = 202;
        break;
      case 15:
        v8 = 203;
        break;
      case 19:
      case 25:
        v8 = 204;
        break;
      case 20:
      case 26:
        v8 = 191;
        break;
      case 21:
        v8 = 190;
        break;
      case 22:
        v8 = 189;
        break;
      case 23:
        v8 = 188;
        break;
      case 24:
        v8 = 205;
        break;
      default:
        break;
    }
  }
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(v4, v8);
  v9 = v4->pCode;
  v10 = v9[*v5 + 2];
  v11 = (unsigned __int8)v9[*v5 + 1];
  v12 = (unsigned __int8)v9[*v5];
  v13 = (unsigned __int8)v9[*v5 + 2];
  *v5 += 3i64;
  v14 = v12 | ((v11 | (v13 << 8)) << 8);
  if ( v10 < 0 )
    v14 = -1 - (v14 ^ 0xFFFFFF);
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v6->OpStack.Data,
    v6->OpStack.Data.Size - 1);
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v6->OpStack.Data,
    v6->OpStack.Data.Size - 1);
  Scaleform::GFx::AS3::Tracer::StoreOffset(v4, *v5, v6, v14, -1);
}

// File Line: 3060
// RVA: 0x8420F0
void __fastcall Scaleform::GFx::AS3::TR::State::exec_if_boolean(Scaleform::GFx::AS3::TR::State *this, unsigned __int64 *bcp, Scaleform::GFx::AS3::Abc::Code::OpCode opcode)
{
  Scaleform::GFx::AS3::Tracer *v3; // rdi
  unsigned __int64 *v4; // r15
  Scaleform::GFx::AS3::TR::State *v5; // r14
  Scaleform::GFx::AS3::Abc::Code::OpCode v6; // ebx
  int v7; // edx
  const char *v8; // rax
  char v9; // r9
  int v10; // edx
  int v11; // er8
  int v12; // ebx
  int v13; // ebx

  v3 = this->pTracer;
  v4 = bcp;
  v5 = this;
  v6 = opcode;
  if ( Scaleform::GFx::AS3::Tracer::IsBooleanType(this->pTracer, &this->OpStack.Data.Data[this->OpStack.Data.Size - 1]) )
    v7 = (v6 != 17) + 51;
  else
    v7 = v6;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(v3, (Scaleform::GFx::AS3::Abc::Code::OpCode)v7);
  v8 = v3->pCode;
  v9 = v8[*v4 + 2];
  v10 = (unsigned __int8)v8[*v4 + 1];
  v11 = (unsigned __int8)v8[*v4];
  v12 = (unsigned __int8)v8[*v4 + 2];
  *v4 += 3i64;
  v13 = v11 | ((v10 | (v12 << 8)) << 8);
  if ( v9 < 0 )
    v13 = -1 - (v13 ^ 0xFFFFFF);
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v5->OpStack.Data,
    v5->OpStack.Data.Size - 1);
  Scaleform::GFx::AS3::Tracer::StoreOffset(v3, *v4, v5, v13, -1);
}

// File Line: 3189
// RVA: 0x842BF0
void __fastcall Scaleform::GFx::AS3::TR::State::exec_jump(Scaleform::GFx::AS3::TR::State *this, unsigned __int64 *bcp)
{
  Scaleform::GFx::AS3::Tracer *v2; // rbx
  unsigned __int64 *v3; // rsi
  Scaleform::GFx::AS3::TR::State *v4; // rdi
  const char *v5; // rax
  char v6; // r11
  int v7; // er10
  int v8; // er9
  unsigned __int64 v9; // rdx
  int v10; // er8
  int v11; // er8

  v2 = this->pTracer;
  v3 = bcp;
  v4 = this;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_jump);
  v5 = v2->pCode;
  v6 = v5[*v3 + 2];
  v7 = (unsigned __int8)v5[*v3];
  v8 = (unsigned __int8)v5[*v3 + 1];
  v9 = *v3 + 3;
  v10 = (unsigned __int8)v5[*v3 + 2] << 8;
  *v3 = v9;
  v11 = v7 | ((v8 | v10) << 8);
  if ( v6 < 0 )
    v11 = -1 - (v11 ^ 0xFFFFFF);
  Scaleform::GFx::AS3::Tracer::StoreOffset(v2, v9, v4, v11, -1);
  Scaleform::GFx::AS3::Tracer::AddBlock(v2, v4, *v3, tDead, 1);
}

// File Line: 3376
// RVA: 0x847190
void __fastcall Scaleform::GFx::AS3::TR::State::exec_switch(Scaleform::GFx::AS3::TR::State *this, unsigned __int64 *bcp)
{
  Scaleform::GFx::AS3::Tracer *v2; // rbp
  unsigned __int64 *v3; // rbx
  Scaleform::GFx::AS3::TR::State *v4; // r14
  const char *v5; // rax
  char v6; // r9
  int v7; // er8
  int v8; // edx
  unsigned __int64 v9; // r15
  unsigned __int64 v10; // r10
  int v11; // ecx
  int v12; // ecx
  const char *v13; // r9
  char v14; // cl
  unsigned int v15; // er8
  char v16; // si
  int v17; // esi
  char v18; // cl
  char v19; // dl
  int i; // edi
  const char *v21; // rax
  char v22; // r10
  int v23; // edx
  int v24; // er8
  unsigned __int64 v25; // rcx
  int v26; // er9
  int v27; // er9

  v2 = this->pTracer;
  v3 = bcp;
  v4 = this;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_lookupswitch);
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v4->OpStack.Data,
    v4->OpStack.Data.Size - 1);
  v5 = v2->pCode;
  v6 = v5[*v3 + 2];
  v7 = (unsigned __int8)v5[*v3];
  v8 = (unsigned __int8)v5[*v3 + 1];
  v9 = v2->CurrOffset;
  v10 = *v3 + 3;
  v11 = (unsigned __int8)v5[*v3 + 2] << 8;
  *v3 = v10;
  v12 = v7 | ((v8 | v11) << 8);
  if ( v6 < 0 )
    v12 = -1 - (v12 ^ 0xFFFFFF);
  Scaleform::GFx::AS3::Tracer::StoreOffset(v2, v10, v4, v9 + v12 - v10, 1);
  v13 = v2->pCode;
  v14 = v13[*v3];
  v15 = 7;
  v16 = v13[(*v3)++];
  v17 = v16 & 0x7F;
  if ( v14 < 0 )
  {
    do
    {
      if ( v15 >= 0x20 )
        break;
      v18 = v15;
      v15 += 7;
      v19 = v13[(*v3)++];
      v17 |= (v19 & 0x7F) << v18;
    }
    while ( v19 < 0 );
  }
  Scaleform::GFx::AS3::Tracer::PushNewOpCodeArg0(v2, v17);
  for ( i = 0; i <= v17; ++i )
  {
    v21 = v2->pCode;
    v22 = v21[*v3 + 2];
    v23 = (unsigned __int8)v21[*v3 + 1];
    v24 = (unsigned __int8)v21[*v3];
    v25 = *v3 + 3;
    v26 = (unsigned __int8)v21[*v3 + 2] << 8;
    *v3 = v25;
    v27 = v24 | ((v23 | v26) << 8);
    if ( v22 < 0 )
      v27 = -1 - (v27 ^ 0xFFFFFF);
    Scaleform::GFx::AS3::Tracer::StoreOffset(v2, v25, v4, v9 + v27 - v25, i + 3);
  }
  Scaleform::GFx::AS3::Tracer::AddBlock(v2, v4, *v3, tDead, 1);
}

// File Line: 3466
// RVA: 0x844480
void __fastcall Scaleform::GFx::AS3::TR::State::exec_opcode(Scaleform::GFx::AS3::TR::State *this, Scaleform::GFx::AS3::Abc::Code::OpCode opcode, unsigned __int64 *bcp)
{
  unsigned __int64 *v3; // rsi
  __int64 v4; // r15
  Scaleform::GFx::AS3::TR::State *v5; // rdi
  Scaleform::GFx::AS3::Tracer *v6; // rbp
  const char *v7; // r14
  unsigned int v8; // eax
  Scaleform::GFx::AS3::Value *v9; // rax
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
  Scaleform::GFx::ASStringNode *v23; // rcx
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
  Scaleform::GFx::AS3::InstanceTraits::Traits **v46; // rax
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
  Scaleform::GFx::AS3::VM::Error v67; // [rsp+38h] [rbp-90h]
  Scaleform::GFx::AS3::VM::Error v68; // [rsp+48h] [rbp-80h]
  Scaleform::GFx::AS3::Value v; // [rsp+58h] [rbp-70h]
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> v70; // [rsp+78h] [rbp-50h]

  v3 = bcp;
  v4 = opcode;
  v5 = this;
  Scaleform::StringBuffer::StringBuffer((Scaleform::StringBuffer *)&v70, Scaleform::Memory::pGlobalHeap);
  v6 = v5->pTracer;
  v7 = v5->pTracer->pCode;
  v5->OpcodeCP = *v3 - 1;
  switch ( (_DWORD)v4 )
  {
    case 3:
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(v6, op_throw);
      Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        &v5->OpStack.Data,
        v5->OpStack.Data.Size - 1);
      break;
    case 4:
    case 5:
    case 8:
    case 0x45:
    case 0x46:
    case 0x4A:
    case 0x4C:
    case 0x4E:
    case 0x4F:
    case 0x61:
    case 0x66:
    case 0x68:
    case 0x80:
    case 0x82:
    case 0x87:
    case 0xA0:
      break;
    case 6:
      v8 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v7, v3);
      Scaleform::GFx::AS3::TR::State::exec_dxns(v5, v8);
      break;
    case 7:
      Scaleform::GFx::AS3::TR::State::exec_dxnslate(v5);
      break;
    case 9:
      Scaleform::GFx::AS3::Tracer::AddBlock(v6, v5, *v3 - 1, 0, 1);
      break;
    case 0xC:
    case 0xD:
    case 0xE:
    case 0xF:
    case 0x13:
    case 0x14:
    case 0x15:
    case 0x16:
    case 0x17:
    case 0x18:
    case 0x19:
    case 0x1A:
      Scaleform::GFx::AS3::TR::State::exec_if(v5, v3, (Scaleform::GFx::AS3::Abc::Code::OpCode)v4);
      break;
    case 0x10:
      Scaleform::GFx::AS3::TR::State::exec_jump(v5, v3);
      break;
    case 0x11:
    case 0x12:
      Scaleform::GFx::AS3::TR::State::exec_if_boolean(v5, v3, (Scaleform::GFx::AS3::Abc::Code::OpCode)v4);
      break;
    case 0x1B:
      Scaleform::GFx::AS3::TR::State::exec_switch(v5, v3);
      break;
    case 0x1C:
      Scaleform::GFx::AS3::TR::State::exec_pushwith(v5);
      break;
    case 0x1D:
      Scaleform::GFx::AS3::TR::State::exec_popscope(v5);
      break;
    case 0x1E:
      Scaleform::GFx::AS3::TR::State::exec_nextname(v5);
      break;
    case 0x1F:
      Scaleform::GFx::AS3::TR::State::exec_hasnext(v5);
      break;
    case 0x20:
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(v6, op_pushnull);
      v9 = Scaleform::GFx::AS3::Value::GetNull();
      Scaleform::GFx::AS3::TR::State::PushOp(v5, v9);
      break;
    case 0x21:
      Scaleform::GFx::AS3::TR::State::exec_pushundefined(v5);
      break;
    case 0x23:
      Scaleform::GFx::AS3::TR::State::exec_nextvalue(v5);
      break;
    case 0x24:
      v10 = (unsigned __int8)v7[(*v3)++];
      Scaleform::GFx::AS3::TR::State::exec_pushbyte(v5, v10);
      break;
    case 0x25:
      v11 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v7, v3);
      Scaleform::GFx::AS3::TR::State::exec_pushshort(v5, v11);
      break;
    case 0x26:
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(v6, op_pushtrue);
      v.Flags = 1;
      v.Bonus.pWeakProxy = 0i64;
      v.value.VS._1.VBool = 1;
      Scaleform::GFx::AS3::TR::State::PushOp(v5, &v);
      break;
    case 0x27:
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(v6, op_pushfalse);
      v.Flags = 1;
      v.Bonus.pWeakProxy = 0i64;
      v.value.VS._1.VBool = 0;
      Scaleform::GFx::AS3::TR::State::PushOp(v5, &v);
      break;
    case 0x28:
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(v6, op_pushnan);
      v.Flags = 4;
      v.Bonus.pWeakProxy = 0i64;
      v.value.VNumber = Scaleform::GFx::NumberUtil::NaN();
      Scaleform::GFx::AS3::TR::State::PushOp(v5, &v);
      break;
    case 0x29:
      Scaleform::GFx::AS3::TR::State::exec_pop(v5);
      break;
    case 0x2A:
      Scaleform::GFx::AS3::TR::State::exec_dup(v5);
      break;
    case 0x2B:
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(v6, op_swap);
      Scaleform::GFx::AS3::TR::State::SwapOp(v5);
      break;
    case 0x2C:
      v12 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v7, v3);
      Scaleform::GFx::AS3::TR::State::exec_pushstring(v5, v12);
      break;
    case 0x2D:
      v13 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v7, v3);
      Scaleform::GFx::AS3::TR::State::exec_pushint(v5, v13);
      break;
    case 0x2E:
      v14 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v7, v3);
      Scaleform::GFx::AS3::TR::State::exec_pushuint(v5, v14);
      break;
    case 0x2F:
      v15 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v7, v3);
      Scaleform::GFx::AS3::TR::State::exec_pushdouble(v5, v15);
      break;
    case 0x30:
      Scaleform::GFx::AS3::TR::State::exec_pushscope(v5);
      break;
    case 0x31:
      v16 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v7, v3);
      Scaleform::GFx::AS3::TR::State::exec_pushnamespace(v5, v16);
      break;
    case 0x32:
      v17 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v7, v3);
      v18 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v7, v3);
      Scaleform::GFx::AS3::TR::State::exec_hasnext2(v5, v17, v18);
      break;
    case 0x35:
      Scaleform::GFx::AS3::TR::State::exec_li8(v5);
      break;
    case 0x36:
      Scaleform::GFx::AS3::TR::State::exec_li8(v5);
      break;
    case 0x37:
      Scaleform::GFx::AS3::TR::State::exec_li8(v5);
      break;
    case 0x38:
      Scaleform::GFx::AS3::TR::State::exec_li8(v5);
      break;
    case 0x39:
      Scaleform::GFx::AS3::TR::State::exec_li8(v5);
      break;
    case 0x3A:
      Scaleform::GFx::AS3::TR::State::exec_li8(v5);
      break;
    case 0x3B:
      Scaleform::GFx::AS3::TR::State::exec_li8(v5);
      break;
    case 0x3C:
      Scaleform::GFx::AS3::TR::State::exec_li8(v5);
      break;
    case 0x3D:
      Scaleform::GFx::AS3::TR::State::exec_li8(v5);
      break;
    case 0x3E:
      Scaleform::GFx::AS3::TR::State::exec_li8(v5);
      break;
    case 0x40:
      v19 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v7, v3);
      Scaleform::GFx::AS3::TR::State::exec_newfunction(v5, v19);
      break;
    case 0x41:
      v20 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v7, v3);
      Scaleform::GFx::AS3::TR::State::exec_call(v5, v20);
      break;
    case 0x42:
      v21 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v7, v3);
      Scaleform::GFx::AS3::TR::State::exec_construct(v5, v21);
      break;
    case 0x43:
    case 0x44:
      Scaleform::GFx::AS3::VM::Error::Error(&v67, eNotImplementedError, v6->CF->pFile->VMRef);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        v5->pTracer->CF->pFile->VMRef,
        v22,
        &Scaleform::GFx::AS3::fl::VerifyErrorTI);
      v23 = v67.Message.pNode;
      v24 = v67.Message.pNode->RefCount == 1;
      --v23->RefCount;
      if ( v24 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v23);
      break;
    case 0x47:
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(v6, op_returnvoid);
      Scaleform::GFx::AS3::Tracer::AddBlock(v6, v5, *v3, tDead, 1);
      break;
    case 0x48:
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(v6, op_returnvalue);
      Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        &v5->OpStack.Data,
        v5->OpStack.Data.Size - 1);
      Scaleform::GFx::AS3::Tracer::AddBlock(v6, v5, *v3, tDead, 1);
      break;
    case 0x49:
      v25 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v7, v3);
      Scaleform::GFx::AS3::TR::State::exec_constructsuper(v5, v25);
      break;
    case 0x50:
      Scaleform::GFx::AS3::TR::State::exec_li8(v5);
      break;
    case 0x51:
      Scaleform::GFx::AS3::TR::State::exec_li8(v5);
      break;
    case 0x52:
      Scaleform::GFx::AS3::TR::State::exec_li8(v5);
      break;
    case 0x53:
      v26 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v7, v3);
      Scaleform::GFx::AS3::TR::State::exec_applytype(v5, v26);
      break;
    case 0x55:
      v27 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v7, v3);
      Scaleform::GFx::AS3::TR::State::exec_newobject(v5, v27);
      break;
    case 0x56:
      v28 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v7, v3);
      Scaleform::GFx::AS3::TR::State::exec_newarray(v5, v28);
      break;
    case 0x57:
      Scaleform::GFx::AS3::TR::State::exec_newactivation(v5);
      break;
    case 0x58:
      v29 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v7, v3);
      Scaleform::GFx::AS3::TR::State::exec_newclass(v5, v29);
      break;
    case 0x59:
      v30 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v7, v3);
      Scaleform::GFx::AS3::TR::State::exec_getdescendants(v5, v30);
      break;
    case 0x5A:
      v31 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v7, v3);
      Scaleform::GFx::AS3::TR::State::exec_newcatch(v5, v31);
      break;
    case 0x5D:
      v32 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v7, v3);
      Scaleform::GFx::AS3::TR::State::exec_findpropstrict(v5, v32);
      break;
    case 0x5E:
      v33 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v7, v3);
      Scaleform::GFx::AS3::TR::State::exec_findproperty(v5, v33);
      break;
    case 0x60:
      v34 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v7, v3);
      Scaleform::GFx::AS3::TR::State::exec_getlex(v5, v34);
      break;
    case 0x62:
      v55 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v7, v3);
      Scaleform::GFx::AS3::TR::State::exec_getlocal(v5, v55);
      break;
    case 0x63:
      v35 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v7, v3);
      Scaleform::GFx::AS3::TR::State::exec_setlocal(v5, v35);
      break;
    case 0x64:
      Scaleform::GFx::AS3::TR::State::exec_getglobalscope(v5, 0);
      break;
    case 0x65:
      v36 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v7, v3);
      Scaleform::GFx::AS3::TR::State::exec_getscopeobject(v5, v36);
      break;
    case 0x6A:
      v37 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v7, v3);
      Scaleform::GFx::AS3::TR::State::exec_deleteproperty(v5, v37);
      break;
    case 0x6C:
      v38 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v7, v3);
      Scaleform::GFx::AS3::TR::State::exec_getslot(v5, v38, 0);
      break;
    case 0x6D:
      v39 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v7, v3);
      Scaleform::GFx::AS3::TR::State::exec_setslot(v5, v39, 0);
      break;
    case 0x6E:
      v40 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v7, v3);
      Scaleform::GFx::AS3::TR::State::exec_getglobalslot(v5, v40);
      break;
    case 0x6F:
      v41 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v7, v3);
      Scaleform::GFx::AS3::TR::State::exec_setglobalslot(v5, v41);
      break;
    case 0x70:
      v42 = 112;
      goto LABEL_72;
    case 0x71:
      Scaleform::GFx::AS3::TR::State::exec_esc_xelem(v5);
      break;
    case 0x72:
      Scaleform::GFx::AS3::TR::State::exec_esc_xattr(v5);
      break;
    case 0x73:
      Scaleform::GFx::AS3::TR::State::exec_convert_i(v5, (__int64)v3);
      break;
    case 0x74:
      Scaleform::GFx::AS3::TR::State::exec_convert_u(v5);
      break;
    case 0x75:
      Scaleform::GFx::AS3::TR::State::exec_convert_d(v5);
      break;
    case 0x76:
      Scaleform::GFx::AS3::TR::State::exec_convert_b(v5);
      break;
    case 0x77:
      v43 = 119;
      goto LABEL_147;
    case 0x78:
      v43 = 120;
      goto LABEL_147;
    case 0x85:
      Scaleform::GFx::AS3::TR::State::exec_coerce_s(v5);
      break;
    case 0x86:
      v44 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v7, v3);
      Scaleform::GFx::AS3::TR::State::exec_astype(v5, v44);
      break;
    case 0x90:
      Scaleform::GFx::AS3::TR::State::exec_negate(v5);
      break;
    case 0x91:
      v45 = 145;
      goto LABEL_85;
    case 0x92:
      v47 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v7, v3);
      v48 = 146;
      goto LABEL_88;
    case 0x93:
      v45 = 147;
LABEL_85:
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(v6, v45);
      v46 = (Scaleform::GFx::AS3::InstanceTraits::Traits **)v5->pTracer->CF->pFile->VMRef->TraitsNumber.pObject;
      goto LABEL_86;
    case 0x94:
      v47 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v7, v3);
      v48 = 148;
LABEL_88:
      v49 = v47;
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(v5->pTracer, v48);
      Scaleform::GFx::AS3::TR::State::ConvertRegisterTo(
        v5,
        (Scaleform::GFx::AS3::AbsoluteIndex)v49,
        v5->pTracer->CF->pFile->VMRef->TraitsNumber.pObject->ITraits.pObject,
        0);
      break;
    case 0x95:
      v42 = 149;
LABEL_72:
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(v6, v42);
      Scaleform::GFx::AS3::TR::State::exec_1OpString(v5);
      break;
    case 0x96:
      Scaleform::GFx::AS3::TR::State::exec_not(v5);
      break;
    case 0x97:
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(v6, op_bitnot);
      v46 = (Scaleform::GFx::AS3::InstanceTraits::Traits **)v5->pTracer->CF->pFile->VMRef->TraitsInt.pObject;
LABEL_86:
      Scaleform::GFx::AS3::TR::State::ConvertOpTo(v5, v46[25], 0);
      break;
    case 0x9B:
      Scaleform::GFx::AS3::TR::State::exec_add_d(v5);
      break;
    case 0xA1:
      Scaleform::GFx::AS3::TR::State::exec_subtract(v5);
      break;
    case 0xA2:
      Scaleform::GFx::AS3::TR::State::exec_multiply(v5);
      break;
    case 0xA3:
      Scaleform::GFx::AS3::TR::State::exec_divide(v5);
      break;
    case 0xA4:
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(v6, op_modulo);
      Scaleform::GFx::AS3::TR::State::exec_2OpNumber(v5);
      break;
    case 0xA5:
      v50 = 165;
      goto LABEL_100;
    case 0xA6:
      v50 = 166;
      goto LABEL_100;
    case 0xA7:
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(v6, op_urshift);
      Scaleform::GFx::AS3::TR::State::exec_2OpUInt(v5);
      break;
    case 0xA8:
      v50 = 168;
      goto LABEL_100;
    case 0xA9:
      v50 = 169;
      goto LABEL_100;
    case 0xAA:
      v50 = 170;
LABEL_100:
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(v6, v50);
      Scaleform::GFx::AS3::TR::State::exec_2OpSInt(v5);
      break;
    case 0xAB:
      v51 = 171;
      goto LABEL_107;
    case 0xAC:
      v51 = 172;
      goto LABEL_107;
    case 0xAD:
      v51 = 173;
      goto LABEL_107;
    case 0xAE:
      v51 = 174;
      goto LABEL_107;
    case 0xAF:
      v51 = 175;
      goto LABEL_107;
    case 0xB0:
      v51 = 176;
      goto LABEL_107;
    case 0xB1:
      v51 = 177;
      goto LABEL_107;
    case 0xB2:
      v52 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v7, v3);
      Scaleform::GFx::AS3::TR::State::exec_istype(v5, v52);
      break;
    case 0xB3:
      v51 = 179;
      goto LABEL_107;
    case 0xB4:
      v51 = 180;
LABEL_107:
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(v6, v51);
      Scaleform::GFx::AS3::TR::State::exec_2OpBoolean(v5);
      break;
    case 0xC0:
      Scaleform::GFx::AS3::TR::State::RefineOpCodeStack1(
        v5,
        op_increment_i,
        v6->CF->pFile->VMRef->TraitsInt.pObject->ITraits.pObject,
        op_increment_ti);
      break;
    case 0xC1:
      Scaleform::GFx::AS3::TR::State::RefineOpCodeStack1(
        v5,
        op_decrement_i,
        v6->CF->pFile->VMRef->TraitsInt.pObject->ITraits.pObject,
        op_decrement_ti);
      break;
    case 0xC2:
      v53 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v7, v3);
      Scaleform::GFx::AS3::TR::State::RefineOpCodeReg1(
        v5,
        op_inclocal_i,
        v5->pTracer->CF->pFile->VMRef->TraitsInt.pObject->ITraits.pObject,
        op_inclocal_ti,
        v53);
      break;
    case 0xC3:
      v54 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v7, v3);
      Scaleform::GFx::AS3::TR::State::RefineOpCodeReg1(
        v5,
        op_declocal_i,
        v5->pTracer->CF->pFile->VMRef->TraitsInt.pObject->ITraits.pObject,
        op_declocal_ti,
        v54);
      break;
    case 0xC4:
      Scaleform::GFx::AS3::TR::State::RefineOpCodeStack1(
        v5,
        op_negate_i,
        v6->CF->pFile->VMRef->TraitsInt.pObject->ITraits.pObject,
        op_negate_ti);
      break;
    case 0xC5:
      Scaleform::GFx::AS3::TR::State::RefineOpCodeStack2(
        v5,
        op_add_i,
        v6->CF->pFile->VMRef->TraitsInt.pObject->ITraits.pObject,
        op_add_ti);
      break;
    case 0xC6:
      Scaleform::GFx::AS3::TR::State::RefineOpCodeStack2(
        v5,
        op_subtract_i,
        v6->CF->pFile->VMRef->TraitsInt.pObject->ITraits.pObject,
        op_subtract_ti);
      break;
    case 0xC7:
      Scaleform::GFx::AS3::TR::State::RefineOpCodeStack2(
        v5,
        op_multiply_i,
        v6->CF->pFile->VMRef->TraitsInt.pObject->ITraits.pObject,
        op_multiply_ti);
      break;
    case 0xD0:
      Scaleform::GFx::AS3::TR::State::exec_getlocal0(v5);
      break;
    case 0xD1:
      Scaleform::GFx::AS3::TR::State::exec_getlocal1(v5);
      break;
    case 0xD2:
      Scaleform::GFx::AS3::TR::State::exec_getlocal2(v5);
      break;
    case 0xD3:
      Scaleform::GFx::AS3::TR::State::exec_getlocal3(v5);
      break;
    case 0xD4:
      Scaleform::GFx::AS3::TR::State::exec_setlocal0(v5);
      break;
    case 0xD5:
      Scaleform::GFx::AS3::TR::State::exec_setlocal1(v5);
      break;
    case 0xD6:
      Scaleform::GFx::AS3::TR::State::exec_setlocal2(v5);
      break;
    case 0xD7:
      Scaleform::GFx::AS3::TR::State::exec_setlocal3(v5);
      break;
    case 0xEF:
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(v6, op_debug);
      v56 = (unsigned __int8)v7[(*v3)++];
      Scaleform::GFx::AS3::Tracer::PushNewOpCodeArg0(v6, v56);
      v57 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v7, v3);
      Scaleform::GFx::AS3::Tracer::PushNewOpCodeArg0(v6, v57);
      v58 = (unsigned __int8)v7[(*v3)++];
      Scaleform::GFx::AS3::Tracer::PushNewOpCodeArg0(v6, v58);
      goto LABEL_135;
    case 0xF0:
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(v6, op_debugline);
      goto LABEL_135;
    case 0xF1:
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(v6, op_debugfile);
LABEL_135:
      v59 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v7, v3);
      Scaleform::GFx::AS3::Tracer::PushNewOpCodeArg0(v6, v59);
      break;
    case 0xF2:
      Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v7, v3);
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
            v64 = (signed int)Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v7, v3);
            v65 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v7, v3);
            Scaleform::GFx::AS3::Tracer::PushNewOpCode(v6, (Scaleform::GFx::AS3::Abc::Code::OpCode)v4, v64, v65);
          }
          else
          {
            Scaleform::GFx::AS3::VM::Error::Error(&v68, eNotImplementedError, v6->CF->pFile->VMRef);
            Scaleform::GFx::AS3::VM::ThrowErrorInternal(
              v5->pTracer->CF->pFile->VMRef,
              v62,
              &Scaleform::GFx::AS3::fl::VerifyErrorTI);
            v63 = v68.Message.pNode;
            v24 = v68.Message.pNode->RefCount == 1;
            --v63->RefCount;
            if ( v24 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v63);
          }
        }
        else
        {
          v66 = Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v7, v3);
          Scaleform::GFx::AS3::Tracer::PushNewOpCode(v6, (Scaleform::GFx::AS3::Abc::Code::OpCode)v4, v66);
        }
      }
      else
      {
        v43 = (signed int)v4;
LABEL_147:
        Scaleform::GFx::AS3::Tracer::PushNewOpCode(v6, v43);
      }
      break;
  }
  Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>(&v70);
}

// File Line: 4201
// RVA: 0x7829D0
void __fastcall Scaleform::GFx::AS3::Tracer::Tracer(Scaleform::GFx::AS3::Tracer *this, Scaleform::MemoryHeap *heap, Scaleform::GFx::AS3::CallFrame *cf, Scaleform::GFx::AS3::MethodInfo *mi)
{
  Scaleform::MemoryHeap *v4; // r10
  Scaleform::GFx::AS3::Tracer *v5; // rsi
  const char *v6; // r8
  char *v7; // r8
  unsigned __int64 v8; // rax
  char v9; // al
  int v10; // er9
  unsigned int v11; // ecx
  char v12; // dl
  Scaleform::ArrayDH<Scaleform::GFx::AS3::TR::State *,328,Scaleform::ArrayDefaultPolicy> *v13; // rdi
  Scaleform::List<Scaleform::GFx::AS3::TR::Block,Scaleform::GFx::AS3::TR::Block> *v14; // rax
  unsigned __int64 v15; // rax
  Scaleform::GFx::AS3::MethodInfo *v16; // rbx
  unsigned __int64 v17; // r8
  Scaleform::MemoryHeap *v18; // rcx
  Scaleform::GFx::AS3::TR::State *v19; // rax
  Scaleform::GFx::AS3::TR::State *v20; // rax
  Scaleform::GFx::AS3::TR::State *v21; // r14
  unsigned __int64 v22; // rbx
  unsigned __int64 v23; // r8
  Scaleform::GFx::AS3::TR::State **v24; // rcx
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *v25; // rdi
  Scaleform::GFx::AS3::CallFrame *v26; // rcx
  long double v27; // rdx
  char v28; // al
  long double v29; // rcx
  int v30; // eax
  unsigned int v31; // er13
  Scaleform::GFx::AS3::CallFrame *v32; // rdx
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v33; // r9
  Scaleform::GFx::AS3::Abc::File *v34; // r8
  __int64 v35; // rdx
  Scaleform::GFx::AS3::Abc::MethodInfo *v36; // r14
  signed int v37; // eax
  __int64 v38; // rbx
  signed __int64 v39; // rdx
  bool v40; // zf
  Scaleform::GFx::AS3::Value::VU *v41; // rdx
  int v42; // eax
  long double v43; // rax
  unsigned __int64 v44; // r12
  char v45; // r15
  Scaleform::GFx::AS3::ClassTraits::Traits *v46; // rax
  long double v47; // r8
  Scaleform::GFx::AS3::VM *v48; // rax
  bool v49; // cl
  signed int v50; // eax
  unsigned int v51; // ebx
  int v52; // eax
  Scaleform::GFx::AS3::VM::Error *v53; // rax
  Scaleform::GFx::ASStringNode *v54; // rcx
  long double v55; // rcx
  unsigned __int64 v56; // r14
  unsigned int v57; // ebx
  int v58; // ecx
  Scaleform::GFx::ASStringNode *v59; // rcx
  long double v60; // rcx
  int v61; // eax
  Scaleform::GFx::AS3::TR::State *v62; // rbx
  unsigned __int8 v63; // r13
  long double v64; // rcx
  int v65; // ecx
  __int64 v66; // rax
  Scaleform::GFx::AS3::TR::Block *v67; // rcx
  unsigned __int64 v68; // [rsp+20h] [rbp-38h]
  Scaleform::GFx::AS3::Value source; // [rsp+30h] [rbp-28h]
  signed __int64 v70; // [rsp+A8h] [rbp+50h]
  signed __int64 v71; // [rsp+A8h] [rbp+50h]
  signed __int64 v72; // [rsp+A8h] [rbp+50h]
  signed __int64 v73; // [rsp+A8h] [rbp+50h]
  signed __int64 v74; // [rsp+A8h] [rbp+50h]
  Scaleform::GFx::AS3::TR::State *v75; // [rsp+A8h] [rbp+50h]
  Scaleform::GFx::AS3::VM *vm; // [rsp+B0h] [rbp+58h]
  Scaleform::GFx::AS3::Abc::MethodInfo *v77; // [rsp+B8h] [rbp+60h]

  v4 = heap;
  v5 = this;
  this->vfptr = (Scaleform::GFx::AS3::FlashUIVtbl *)&Scaleform::GFx::AS3::FlashUI::`vftable;
  this->State = 0;
  this->NeedToCheck = 0;
  this->vfptr = (Scaleform::GFx::AS3::FlashUIVtbl *)&Scaleform::GFx::AS3::Tracer::`vftable;
  this->Done = 0;
  this->Heap = heap;
  this->CF = cf;
  this->MI = mi;
  this->CurrOffset = 0i64;
  v6 = cf->pFile->File.pObject->MethodBodies.Info.Data.Data[cf->MBIIndex.Ind]->code.code.Data;
  if ( v6 )
  {
    v9 = *v6;
    v7 = (char *)(v6 + 1);
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
    v7 = &customWorldMapCaption;
    v8 = 0i64;
  }
  v5->BCode.pStr = v7;
  v5->BCode.Size = v8;
  v5->pCode = v7;
  v5->CodeEnd = v5->BCode.Size;
  v5->PrintOffset = 0i64;
  v5->CurrBlock = 0i64;
  v70 = (signed __int64)&v5->OrigOpcodePos;
  *(_OWORD *)v70 = 0ui64;
  *(_QWORD *)(v70 + 16) = 0i64;
  v5->OrigOpcodePos.Data.pHeap = v4;
  v71 = (signed __int64)&v5->NewOpcodePos;
  *(_OWORD *)v71 = 0ui64;
  *(_QWORD *)(v71 + 16) = 0i64;
  v5->NewOpcodePos.Data.pHeap = v4;
  v72 = (signed __int64)&v5->PosToRecalculate;
  *(_OWORD *)v72 = 0ui64;
  *(_QWORD *)(v72 + 16) = 0i64;
  v5->PosToRecalculate.Data.pHeap = v4;
  v73 = (signed __int64)&v5->Orig2newPosMap;
  *(_OWORD *)v73 = 0ui64;
  *(_QWORD *)(v73 + 16) = 0i64;
  v5->Orig2newPosMap.Data.pHeap = v4;
  v13 = &v5->States;
  v13->Data.Data = 0i64;
  v13->Data.Size = 0i64;
  v13->Data.Policy.Capacity = 0i64;
  v5->States.Data.pHeap = v4;
  v14 = &v5->Blocks;
  v14->Root.pPrev = (Scaleform::GFx::AS3::TR::Block *)v14;
  v14->Root.pNext = (Scaleform::GFx::AS3::TR::Block *)v14;
  v74 = (signed __int64)&v5->CatchTraits;
  *(_OWORD *)v74 = 0ui64;
  *(_QWORD *)(v74 + 16) = 0i64;
  v5->CatchTraits.Data.pHeap = v4;
  vm = v5->CF->pFile->VMRef;
  v5->NeedToCheck = vm->UI->NeedToCheck;
  v5->State = 3;
  v15 = vm->CallStack.Size;
  v5->PrintOffset = v15;
  if ( v15 )
    v5->PrintOffset = v15 - 1;
  v16 = v5->MI;
  if ( v16->OpCode.Data.Size && v16->OpCode.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64 )
  {
    if ( v16->OpCode.Data.Data )
    {
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v16->OpCode.Data.Data = 0i64;
    }
    v16->OpCode.Data.Policy.Capacity = 0i64;
  }
  v16->OpCode.Data.Size = 0i64;
  v17 = v5->BCode.Size;
  if ( v17 > v5->MI->OpCode.Data.Policy.Capacity )
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *)&v5->MI->OpCode.Data.Data,
      &v5->MI->OpCode,
      v17);
  Scaleform::ArrayDataDH<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v5->Orig2newPosMap.Data,
    v5->BCode.Size);
  v19 = (Scaleform::GFx::AS3::TR::State *)v5->Heap->vfptr->Alloc(v18, 136ui64, 0i64);
  if ( v19 )
  {
    Scaleform::GFx::AS3::TR::State::State(v19, v5, 0i64);
    v21 = v20;
  }
  else
  {
    v21 = 0i64;
  }
  v75 = v21;
  v22 = v5->States.Data.Size + 1;
  if ( v22 >= v5->States.Data.Size )
  {
    if ( v22 <= v5->States.Data.Policy.Capacity )
      goto LABEL_25;
    v23 = v22 + (v22 >> 2);
  }
  else
  {
    if ( v22 >= v5->States.Data.Policy.Capacity >> 1 )
      goto LABEL_25;
    v23 = v5->States.Data.Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
    (Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy> *)&v5->States,
    v5->States.Data.pHeap,
    v23);
LABEL_25:
  v5->States.Data.Size = v22;
  v24 = &v13->Data.Data[v22 - 1];
  if ( v24 )
    *v24 = v21;
  v25 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v21->Registers.Data.Data;
  v26 = v5->CF;
  v27 = *(double *)&v26->OriginationTraits;
  v28 = *(_BYTE *)(*(_QWORD *)&v27 + 112i64) >> 5;
  source.Bonus.pWeakProxy = 0i64;
  if ( v28 & 1 )
  {
    source.value.VNumber = v27;
    source.Flags = 9;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v21->Registers.Data.Data,
      v21->Registers.Data.pHeap,
      v21->Registers.Data.Size + 1);
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(&v25->Data[v21->Registers.Data.Size - 1], &source);
  }
  else
  {
    v30 = v26->Invoker.Flags & 0x1F;
    source.Flags = 8;
    if ( (_BYTE)v30 == 14 )
      *(_QWORD *)&source.value.VNumber = v26->pFile->VMRef->TraitsObject.pObject->ITraits.pObject;
    else
      source.value.VNumber = v27;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v21->Registers.Data.Data,
      v21->Registers.Data.pHeap,
      v21->Registers.Data.Size + 1);
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(&v25->Data[v21->Registers.Data.Size - 1], &source);
  }
  *v21->RegistersAlive.pData |= 1u;
  v31 = 1;
  v32 = v5->CF;
  v33 = v32->pFile->File.pObject->MethodBodies.Info.Data.Data[v32->MBIIndex.Ind];
  v34 = v32->pFile->File.pObject;
  v35 = v34->MethodBodies.Info.Data.Data[v32->MBIIndex.Ind]->method_info_ind;
  v36 = v34->Methods.Info.Data.Data[v35];
  v77 = v34->Methods.Info.Data.Data[v35];
  v37 = v33->local_reg_count;
  if ( v37 > 1 )
  {
    v38 = (unsigned int)(v37 - 1);
    do
    {
      if ( !(_S11_12 & 1) )
      {
        _S11_12 |= 1u;
        v.Flags = 0;
        v.Bonus.pWeakProxy = 0i64;
        atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
      }
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        v25,
        v25[1].Data,
        v25->Size + 1);
      *(_QWORD *)&v29 = 32 * v25->Size;
      v39 = (signed __int64)&v25->Data[-1];
      v40 = *(_QWORD *)&v29 + v39 == 0;
      v41 = (Scaleform::GFx::AS3::Value::VU *)(*(_QWORD *)&v29 + v39);
      *(_QWORD *)&source.Flags = v41;
      if ( v40 )
        goto LABEL_50;
      LODWORD(v41->VS._1.VStr) = v.Flags;
      v41->VS._2.VObj = (Scaleform::GFx::AS3::Object *)v.Bonus.pWeakProxy;
      v41[1] = v.value;
      *(_QWORD *)&v29 = v.Flags;
      v42 = v.Flags & 0x1F;
      if ( v42 <= 9 )
        goto LABEL_50;
      *(_QWORD *)&v29 = (unsigned int)(LODWORD(v29) >> 9);
      if ( LOBYTE(v29) & 1 )
      {
        ++v.Bonus.pWeakProxy->RefCount;
      }
      else if ( v42 == 10 )
      {
        ++*(_DWORD *)(*(_QWORD *)&v.value.VNumber + 24i64);
      }
      else if ( v42 > 10 )
      {
        if ( v42 <= 15 )
        {
          v43 = v.value.VNumber;
LABEL_47:
          if ( v43 != 0.0 )
          {
            ++*(_DWORD *)(*(_QWORD *)&v43 + 32i64);
            *(_DWORD *)(*(_QWORD *)&v43 + 32i64) &= 0x8FBFFFFF;
          }
          goto LABEL_50;
        }
        if ( v42 <= 17 )
        {
          v43 = *(double *)&v.value.VS._2.VObj;
          goto LABEL_47;
        }
      }
LABEL_50:
      --v38;
    }
    while ( v38 );
  }
  v68 = v36->ParamTypes.Data.Size;
  v44 = 0i64;
  v45 = 2;
  if ( !v68 )
  {
LABEL_82:
    if ( v36->Flags & 4 )
    {
      v55 = *(double *)&vm->TraitsArray.pObject->ITraits.pObject;
      source.Bonus.pWeakProxy = 0i64;
      source.value.VNumber = v55;
      source.Flags = 8;
      v56 = v31;
      Scaleform::GFx::AS3::Value::Assign(&v25->Data[v31], &source);
      v57 = source.Flags;
      v58 = source.Flags & 0x1F;
      if ( v58 > 9 )
      {
        if ( !((source.Flags >> 9) & 1) )
        {
          switch ( v58 )
          {
            case 10:
              goto LABEL_89;
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
              goto LABEL_103;
            case 16:
            case 17:
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
      if ( !(v36->Flags & 1) )
      {
        v62 = v75;
        goto LABEL_106;
      }
      v64 = *(double *)&vm->TraitsArray.pObject->ITraits.pObject;
      source.Bonus.pWeakProxy = 0i64;
      source.value.VNumber = v64;
      source.Flags = 8;
      v56 = v31;
      Scaleform::GFx::AS3::Value::Assign(&v25->Data[v31], &source);
      v57 = source.Flags;
      v65 = source.Flags & 0x1F;
      if ( v65 > 9 )
      {
        if ( !((source.Flags >> 9) & 1) )
        {
          switch ( v65 )
          {
            case 10:
LABEL_89:
              v59 = source.value.VS._1.VStr;
              v40 = *(_DWORD *)(*(_QWORD *)&source.value.VNumber + 24i64) == 1;
              --v59->RefCount;
              if ( v40 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v59);
              break;
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
LABEL_103:
              if ( !source.value.VS._1.VBool )
              {
                v60 = source.value.VNumber;
                goto LABEL_95;
              }
              --*(_QWORD *)&source.value.VNumber;
              break;
            case 16:
            case 17:
LABEL_92:
              if ( (_QWORD)source.value.VS._2.VObj & 1 )
              {
                --source.value.VS._2.VObj;
              }
              else
              {
                v60 = *(double *)&source.value.VS._2.VObj;
LABEL_95:
                if ( v60 != 0.0 )
                {
                  v61 = *(_DWORD *)(*(_QWORD *)&v60 + 32i64);
                  if ( v61 & 0x3FFFFF )
                  {
                    *(_DWORD *)(*(_QWORD *)&v60 + 32i64) = v61 - 1;
                    Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(*(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v60);
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
        v40 = source.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v40 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        source.Bonus.pWeakProxy = 0i64;
        source.value = 0ui64;
        source.Flags = v57 & 0xFFFFFDE0;
        goto LABEL_98;
      }
    }
LABEL_98:
    v62 = v75;
    v63 = v31 & 7;
    *(_QWORD *)&v29 = v63;
    v75->RegistersAlive.pData[v56 >> 3] |= 1 << v63;
LABEL_106:
    v66 = ((__int64 (__fastcall *)(long double, signed __int64))v5->Heap->vfptr->Alloc)(
            COERCE_LONG_DOUBLE(*(_QWORD *)&v29),
            48i64);
    v67 = (Scaleform::GFx::AS3::TR::Block *)v66;
    if ( v66 )
    {
      *(_DWORD *)(v66 + 16) |= 1u;
      *(_DWORD *)(v66 + 20) = 0;
      *(_QWORD *)(v66 + 24) = v62;
      *(_QWORD *)(v66 + 32) = 0i64;
      *(_QWORD *)(v66 + 40) = 0i64;
    }
    else
    {
      v67 = 0i64;
    }
    v67->pPrev = v5->Blocks.Root.pPrev;
    v67->pNext = (Scaleform::GFx::AS3::TR::Block *)&v5->Blocks;
    v5->Blocks.Root.pPrev->pNext = v67;
    v5->Blocks.Root.pPrev = v67;
    return;
  }
  while ( 1 )
  {
    v46 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
            vm,
            (Scaleform::GFx::AS3::VMFile *)&v5->CF->pFile->vfptr,
            &v5->CF->pFile->File.pObject->Const_Pool.const_multiname.Data.Data[v36->ParamTypes.Data.Data[v44]]);
    if ( !v46 )
      break;
    v47 = *(double *)&v46->ITraits.pObject;
    v48 = v5->CF->pFile->VMRef;
    v49 = *(Scaleform::GFx::AS3::InstanceTraits::Traits **)&v47 == v48->TraitsInt.pObject->ITraits.pObject
       || *(Scaleform::GFx::AS3::InstanceTraits::Traits **)&v47 == v48->TraitsUint.pObject->ITraits.pObject
       || *(Scaleform::GFx::AS3::InstanceTraits::Traits **)&v47 == v48->TraitsNumber.pObject->ITraits.pObject
       || *(Scaleform::GFx::AS3::InstanceTraits::Traits **)&v47 == v48->TraitsBoolean.pObject->ITraits.pObject;
    source.Flags = 8;
    source.Bonus.pWeakProxy = 0i64;
    source.value.VNumber = v47;
    v50 = 2;
    if ( v49 )
      v50 = 0;
    source.Flags = (32 * v50 | 8) & 0xFFFFFEFF;
    Scaleform::GFx::AS3::Value::Assign(&v25->Data[v31], &source);
    v51 = source.Flags;
    *(_QWORD *)&v29 = source.Flags & 0x1F;
    if ( SLODWORD(v29) > 9 )
    {
      if ( (source.Flags >> 9) & 1 )
      {
        v40 = source.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v40 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        source.Bonus.pWeakProxy = 0i64;
        source.value = 0ui64;
        source.Flags = v51 & 0xFFFFFDE0;
      }
      else
      {
        switch ( LODWORD(v29) )
        {
          case 0xA:
            v29 = source.value.VNumber;
            v40 = *(_DWORD *)(*(_QWORD *)&source.value.VNumber + 24i64) == 1;
            --*(_DWORD *)(*(_QWORD *)&v29 + 24i64);
            if ( v40 )
              Scaleform::GFx::ASStringNode::ReleaseNode(*(Scaleform::GFx::ASStringNode **)&v29);
            break;
          case 0xB:
          case 0xC:
          case 0xD:
          case 0xE:
          case 0xF:
            if ( !source.value.VS._1.VBool )
            {
              v29 = source.value.VNumber;
              goto LABEL_75;
            }
            --*(_QWORD *)&source.value.VNumber;
            break;
          case 0x10:
          case 0x11:
            if ( (_QWORD)source.value.VS._2.VObj & 1 )
            {
              --source.value.VS._2.VObj;
            }
            else
            {
              v29 = *(double *)&source.value.VS._2.VObj;
LABEL_75:
              if ( v29 != 0.0 )
              {
                v52 = *(_DWORD *)(*(_QWORD *)&v29 + 32i64);
                if ( v52 & 0x3FFFFF )
                {
                  *(_DWORD *)(*(_QWORD *)&v29 + 32i64) = v52 - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(*(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v29);
                }
              }
            }
            break;
          default:
            break;
        }
      }
    }
    v75->RegistersAlive.pData[(unsigned __int64)v31++ >> 3] |= v45;
    v45 = __ROL1__(v45, 1);
    ++v44;
    v36 = v77;
    if ( v44 >= v68 )
      goto LABEL_82;
  }
  Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&source, eClassNotFoundError, vm);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v53, &Scaleform::GFx::AS3::fl::VerifyErrorTI);
  v54 = (Scaleform::GFx::ASStringNode *)source.Bonus.pWeakProxy;
  v40 = LODWORD(source.Bonus.pWeakProxy[1].pObject) == 1;
  --v54->RefCount;
  if ( v40 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v54);
}

// File Line: 4363
// RVA: 0x78E660
void __fastcall Scaleform::GFx::AS3::Tracer::~Tracer(Scaleform::GFx::AS3::Tracer *this)
{
  Scaleform::GFx::AS3::Tracer *v1; // rsi
  Scaleform::GFx::AS3::TR::Block *v2; // rdx
  Scaleform::List<Scaleform::GFx::AS3::TR::Block,Scaleform::GFx::AS3::TR::Block> *v3; // rdi
  Scaleform::GFx::AS3::TR::Block *v4; // rbx
  unsigned __int64 v5; // rbp
  unsigned __int64 v6; // rbx
  Scaleform::GFx::AS3::TR::State **v7; // rax
  Scaleform::GFx::AS3::TR::State *v8; // rdi
  unsigned __int64 v9; // rdi
  Scaleform::GFx::AS3::RefCountBaseGC<328> **i; // rbx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v11; // rcx
  unsigned int v12; // eax

  v1 = this;
  this->vfptr = (Scaleform::GFx::AS3::FlashUIVtbl *)&Scaleform::GFx::AS3::Tracer::`vftable;
  v2 = this->Blocks.Root.pNext;
  v3 = &this->Blocks;
  if ( v2 != (Scaleform::GFx::AS3::TR::Block *)&this->Blocks )
  {
    do
    {
      v4 = v2->pNext;
      v2->pPrev->pNext = v4;
      v2->pNext->pPrev = v2->pPrev;
      v2->pPrev = (Scaleform::GFx::AS3::TR::Block *)-1i64;
      v2->pNext = (Scaleform::GFx::AS3::TR::Block *)-1i64;
      ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v2 = v4;
    }
    while ( v4 != (Scaleform::GFx::AS3::TR::Block *)v3 );
  }
  v3->Root.pPrev = (Scaleform::GFx::AS3::TR::Block *)v3;
  v3->Root.pNext = (Scaleform::GFx::AS3::TR::Block *)v3;
  v5 = v1->States.Data.Size;
  v6 = 0i64;
  if ( v5 )
  {
    do
    {
      v7 = v1->States.Data.Data;
      v8 = v7[v6];
      if ( v8 )
      {
        Scaleform::GFx::AS3::TR::State::~State(v7[v6]);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v8);
      }
      ++v6;
    }
    while ( v6 < v5 );
  }
  v9 = v1->CatchTraits.Data.Size;
  for ( i = (Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v1->CatchTraits.Data.Data[v9 - 1]; v9; --v9 )
  {
    v11 = *i;
    if ( *i )
    {
      if ( (unsigned __int8)v11 & 1 )
      {
        *i = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v11 - 1);
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
    --i;
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->CatchTraits.Data.Data);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->States.Data.Data);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->Orig2newPosMap.Data.Data);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->PosToRecalculate.Data.Data);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->NewOpcodePos.Data.Data);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->OrigOpcodePos.Data.Data);
  v1->vfptr = (Scaleform::GFx::AS3::FlashUIVtbl *)&Scaleform::GFx::AS3::FlashUI::`vftable;
}

// File Line: 4386
// RVA: 0x7C6B10
void __fastcall Scaleform::GFx::AS3::Tracer::EmitCode(Scaleform::GFx::AS3::Tracer *this)
{
  Scaleform::GFx::AS3::Tracer *v1; // rbx
  Scaleform::GFx::AS3::CallFrame *v2; // rcx
  Scaleform::GFx::AS3::VMAbcFile *v3; // rax
  Scaleform::GFx::AS3::VM *v4; // rsi
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v5; // rax
  unsigned __int64 v6; // r14
  unsigned __int64 v7; // r15
  __int64 v8; // r12
  Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo *v9; // rdi
  Scaleform::GFx::AS3::TR::Block *v10; // rax
  Scaleform::GFx::AS3::TR::Block *v11; // rax
  __int64 v12; // rcx
  Scaleform::GFx::AS3::TR::State *v13; // r13
  Scaleform::GFx::AS3::CallFrame *v14; // rax
  long double v15; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v16; // rax
  long double v17; // rdi
  int v18; // eax
  unsigned int v19; // esi
  Scaleform::GFx::AS3::VM::Error *v20; // rax
  Scaleform::GFx::ASStringNode *v21; // rcx
  bool v22; // zf
  Scaleform::GFx::AS3::MethodInfo *v23; // rbx
  unsigned __int64 v24; // rdx
  __int64 v25; // r8
  Scaleform::GFx::AS3::Tracer::Recalculate *v26; // r10
  unsigned __int64 v27; // r11
  unsigned __int64 *v28; // r9
  unsigned __int64 v29; // rax
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v30; // r15
  __int64 v31; // r12
  unsigned int *v32; // rdx
  unsigned __int64 *v33; // rcx
  unsigned int v34; // er13
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo,338>,Scaleform::ArrayDefaultPolicy> *v35; // rdi
  unsigned __int64 v36; // rsi
  unsigned __int64 v37; // r8
  signed __int64 v38; // rcx
  Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo *v39; // rax
  Scaleform::GFx::AS3::Value v40; // [rsp+38h] [rbp-31h]
  Scaleform::GFx::AS3::Value source; // [rsp+58h] [rbp-11h]
  Scaleform::GFx::AS3::VM *v42; // [rsp+D0h] [rbp+67h]
  int v43; // [rsp+D0h] [rbp+67h]
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v44; // [rsp+D8h] [rbp+6Fh]
  int v45; // [rsp+D8h] [rbp+6Fh]
  unsigned int v46; // [rsp+E0h] [rbp+77h]
  unsigned int v47; // [rsp+E8h] [rbp+7Fh]

  v1 = this;
  if ( this->Done )
    return;
  v2 = this->CF;
  v3 = v2->pFile;
  v4 = v3->VMRef;
  v42 = v3->VMRef;
  v5 = v3->File.pObject->MethodBodies.Info.Data.Data[v2->MBIIndex.Ind];
  v44 = v5;
  v6 = 0i64;
  v7 = 0i64;
  if ( !v5->exception.info.Data.Size )
  {
LABEL_21:
    Scaleform::GFx::AS3::Tracer::TraceBlock(v1, 0i64, v1->Blocks.Root.pNext);
    if ( v4->HandleException )
    {
      v23 = v1->MI;
      if ( v23->OpCode.Data.Size && v23->OpCode.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64 )
      {
        if ( v23->OpCode.Data.Data )
        {
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          v23->OpCode.Data.Data = 0i64;
        }
        v23->OpCode.Data.Policy.Capacity = 0i64;
      }
      v23->OpCode.Data.Size = 0i64;
      return;
    }
    v24 = 0i64;
    if ( v1->PosToRecalculate.Data.Size > 0 )
    {
      v25 = 0i64;
      do
      {
        v26 = v1->PosToRecalculate.Data.Data;
        v27 = v26[v25].pos;
        v28 = &v1->MI->OpCode.Data.Data[v27];
        v29 = 0i64;
        if ( *v28 < v1->Orig2newPosMap.Data.Size )
          v29 = v26[v25].base + v1->Orig2newPosMap.Data.Data[*v28] - v27;
        *v28 = v29;
        ++v24;
        ++v25;
      }
      while ( v24 < v1->PosToRecalculate.Data.Size );
    }
    v30 = v1->CF->pFile->File.pObject->MethodBodies.Info.Data.Data[v1->CF->MBIIndex.Ind];
    if ( !v30->exception.info.Data.Size )
    {
LABEL_42:
      v1->Done = 1;
      return;
    }
    v31 = 0i64;
    while ( 1 )
    {
      v32 = &v30->exception.info.Data.Data[v31].from;
      v33 = v1->Orig2newPosMap.Data.Data;
      v34 = v33[*v32];
      v43 = v33[v32[1]];
      v45 = v33[v32[2]];
      v46 = v32[3];
      v47 = v32[4];
      v35 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo,338>,Scaleform::ArrayDefaultPolicy> *)&v1->MI->Exception.info.Data.Data;
      v36 = v1->MI->Exception.info.Data.Size + 1;
      if ( v36 >= v1->MI->Exception.info.Data.Size )
      {
        if ( v36 > v1->MI->Exception.info.Data.Policy.Capacity )
        {
          v37 = v36 + (v36 >> 2);
          goto LABEL_40;
        }
      }
      else if ( v36 < v1->MI->Exception.info.Data.Policy.Capacity >> 1 )
      {
        v37 = v1->MI->Exception.info.Data.Size + 1;
LABEL_40:
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
          v35,
          v35,
          v37);
        goto LABEL_41;
      }
LABEL_41:
      v35->Size = v36;
      v38 = v36;
      v39 = v35->Data;
      v39[v38 - 1].from = v34;
      *((_DWORD *)&v39[v38] - 4) = v43;
      *((_DWORD *)&v39[v38] - 3) = v45;
      *((_DWORD *)&v39[v38] - 2) = v46;
      *((_DWORD *)&v39[v38] - 1) = v47;
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
    v10 = Scaleform::GFx::AS3::Tracer::AddBlock(v1, v1->Blocks.Root.pNext->State, v9[v8].from, 0, 0);
    if ( v10 )
    {
      *((_DWORD *)v10 + 4) &= 0xFFFFFFFE;
      v10->Type |= 2u;
    }
    v11 = Scaleform::GFx::AS3::Tracer::AddBlock(v1, v1->Blocks.Root.pNext->State, v9[v8].target, 0, 0);
    if ( !v11 )
      goto LABEL_17;
    v12 = (signed int)v9[v8].exc_type_ind;
    v11->CurOpStackSize = 1i64;
    v11->Type |= 4u;
    v13 = v11->State;
    v14 = v1->CF;
    if ( (_DWORD)v12 )
      break;
    v15 = *(double *)&v14->pFile->VMRef->TraitsObject.pObject->ITraits.pObject;
    source.Bonus.pWeakProxy = 0i64;
    source.value.VNumber = v15;
    source.Flags = 72;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v13->OpStack.Data.Data,
      v13->OpStack.Data.pHeap,
      v13->OpStack.Data.Size + 1);
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
      &v13->OpStack.Data.Data[v13->OpStack.Data.Size - 1],
      &source);
LABEL_17:
    ++v7;
    ++v8;
    v5 = v44;
    if ( v7 >= v44->exception.info.Data.Size )
      goto LABEL_21;
  }
  v16 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
          v4,
          (Scaleform::GFx::AS3::VMFile *)&v14->pFile->vfptr,
          &v14->pFile->File.pObject->Const_Pool.const_multiname.Data.Data[v12]);
  if ( v16 )
  {
    v17 = *(double *)&v16->ITraits.pObject;
    v18 = Scaleform::GFx::AS3::Tracer::CanBeNull(v1, v16->ITraits.pObject);
    v40.Bonus.pWeakProxy = 0i64;
    v40.value.VNumber = v17;
    v19 = (32 * v18 | 8) & 0xFFFFFEFF;
    v40.Flags = (32 * v18 | 8) & 0xFFFFFEFF;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v13->OpStack.Data.Data,
      v13->OpStack.Data.pHeap,
      v13->OpStack.Data.Size + 1);
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
      &v13->OpStack.Data.Data[v13->OpStack.Data.Size - 1],
      &v40);
    if ( (char)(v19 & 0x1F) > 9 )
    {
      if ( (v19 >> 9) & 1 )
      {
        LODWORD(MEMORY[0]) = MEMORY[0] - 1;
        if ( !(_DWORD)MEMORY[0] )
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
        v40.Bonus.pWeakProxy = 0i64;
        v40.value = 0ui64;
        v40.Flags = v19 & 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v40);
      }
    }
    v4 = v42;
    goto LABEL_17;
  }
  Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v40, eClassNotFoundError, v4);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(v4, v20, &Scaleform::GFx::AS3::fl::VerifyErrorTI);
  v21 = (Scaleform::GFx::ASStringNode *)v40.Bonus.pWeakProxy;
  v22 = LODWORD(v40.Bonus.pWeakProxy[1].pObject) == 1;
  --v21->RefCount;
  if ( v22 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v21);
}

// File Line: 4596
// RVA: 0x829400
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Tracer::UpdateBlock(Scaleform::GFx::AS3::Tracer *this, Scaleform::GFx::AS3::CheckResult *result, const unsigned __int64 bcp)
{
  Scaleform::GFx::AS3::TR::Block *v3; // rax
  Scaleform::GFx::AS3::CheckResult *v4; // rbx
  Scaleform::GFx::AS3::TR::Block *v5; // rdx
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+30h] [rbp+8h]

  v3 = this->CurrBlock;
  v4 = result;
  v5 = this->Blocks.Root.pPrev;
  if ( v5 )
  {
    while ( bcp < v5->From )
    {
      v5 = v5->pPrev;
      if ( !v5 )
      {
        v4->Result = 1;
        return v4;
      }
    }
    if ( v5 && v5->From == bcp )
    {
      this->CurrBlock = v5;
      if ( *((_BYTE *)v5 + 16) & 1 )
      {
        if ( v5 != v3 && !Scaleform::GFx::AS3::Tracer::MergeBlock(this, &resulta, v5, v3)->Result )
        {
          v4->Result = 0;
          return v4;
        }
      }
      else
      {
        Scaleform::GFx::AS3::Tracer::InitializeBlock(this, v5, v3);
      }
    }
  }
  v4->Result = 1;
  return v4;
}

// File Line: 4846
// RVA: 0x821520
void __fastcall Scaleform::GFx::AS3::Tracer::SkipDeadCode(Scaleform::GFx::AS3::Tracer *this, unsigned __int64 *bcp)
{
  unsigned __int64 *v2; // rbx
  Scaleform::GFx::AS3::Tracer *v3; // rdi
  __int64 v4; // rdx
  signed __int64 v5; // r8
  signed __int64 v6; // rax
  unsigned int v7; // er8
  const char *v8; // r10
  char v9; // cl
  int v10; // er9
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
  Scaleform::GFx::AS3::CheckResult result; // [rsp+30h] [rbp+8h]

  v2 = bcp;
  v3 = this;
  if ( this->CurrBlock->Type & 1 )
  {
    do
    {
      if ( *v2 >= v3->CodeEnd )
        return;
      Scaleform::GFx::AS3::Tracer::RegisterOrigOpCode(v3, *v2);
      v4 = (unsigned __int8)v3->pCode[*v2];
      v5 = *v2 + 1;
      *v2 = v5;
      if ( (signed int)v4 >= 12 )
      {
        if ( (signed int)v4 <= 26 )
        {
          *v2 = v5 + 3;
          continue;
        }
        switch ( (_DWORD)v4 )
        {
          case 0x1B:
            v6 = v5 + 3;
            v7 = 7;
            *v2 = v6;
            v8 = v3->pCode;
            v9 = v8[++v6 - 1];
            *v2 = v6;
            v10 = v9 & 0x7F;
            if ( v9 < 0 )
            {
              do
              {
                if ( v7 >= 0x20 )
                  break;
                v11 = v7;
                v7 += 7;
                v12 = v8[(*v2)++];
                v10 |= (v12 & 0x7F) << v11;
              }
              while ( v12 < 0 );
            }
            if ( v10 >= 0 )
            {
              v13 = (unsigned int)(v10 + 1);
              do
              {
                *v2 += 3i64;
                --v13;
              }
              while ( v13 );
            }
            continue;
          case 0x24:
            *v2 = v5 + 1;
            continue;
          case 0xEF:
            *v2 = v5 + 1;
            Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v3->pCode, v2);
            ++*v2;
            Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v3->pCode, v2);
            continue;
        }
      }
      v14 = ((char)(16 * *(_BYTE *)&Scaleform::GFx::AS3::Abc::Code::opcode_info[v4]) >> 4) - 1;
      if ( !v14 )
        goto LABEL_23;
      if ( v14 == 1 )
      {
        v15 = v3->pCode;
        v16 = 7;
        v17 = v15[v5];
        *v2 = v5 + 1;
        if ( v17 < 0 )
        {
          do
          {
            if ( v16 >= 0x20 )
              break;
            v16 += 7;
            v18 = v15[(*v2)++];
          }
          while ( v18 < 0 );
        }
LABEL_23:
        v19 = v3->pCode;
        v20 = 7;
        v21 = v19[(*v2)++];
        if ( v21 < 0 )
        {
          do
          {
            if ( v20 >= 0x20 )
              break;
            v20 += 7;
            v22 = v19[(*v2)++];
          }
          while ( v22 < 0 );
        }
      }
    }
    while ( Scaleform::GFx::AS3::Tracer::UpdateBlock(v3, &result, *v2)->Result && v3->CurrBlock->Type & 1 );
  }
}

// File Line: 5007
// RVA: 0x828610
void __fastcall Scaleform::GFx::AS3::Tracer::TraceBlock(Scaleform::GFx::AS3::Tracer *this, unsigned __int64 bcp, Scaleform::GFx::AS3::TR::Block *initBlock)
{
  unsigned __int64 v3; // rdi
  Scaleform::GFx::AS3::TR::Block *v4; // rdx
  Scaleform::GFx::AS3::Tracer *i; // rbx
  unsigned __int64 v6; // rdi
  unsigned __int64 v7; // rdi
  Scaleform::GFx::AS3::Abc::Code::OpCode v8; // ecx
  Scaleform::GFx::AS3::TR::Block *v9; // rax
  Scaleform::GFx::AS3::Abc::Code::OpCode v10; // edi
  Scaleform::GFx::AS3::CheckResult result; // [rsp+30h] [rbp+8h]
  unsigned __int64 bcpa; // [rsp+38h] [rbp+10h]

  bcpa = bcp;
  v3 = bcp;
  v4 = this->Blocks.Root.pPrev;
  for ( i = this; v4; v4 = v4->pPrev )
  {
    if ( v3 >= v4->From )
      break;
  }
  this->CurrBlock = v4;
  if ( *((_BYTE *)v4 + 16) & 1 )
  {
    if ( v4 != initBlock && !Scaleform::GFx::AS3::Tracer::MergeBlock(this, &result, v4, initBlock)->Result )
      return;
  }
  else
  {
    Scaleform::GFx::AS3::Tracer::InitializeBlock(this, v4, initBlock);
  }
  if ( v3 < i->CodeEnd )
  {
    do
    {
      if ( i->CF->pFile->VMRef->HandleException )
        break;
      if ( !Scaleform::GFx::AS3::Tracer::UpdateBlock(i, &result, v3)->Result )
        break;
      Scaleform::GFx::AS3::Tracer::SkipDeadCode(i, &bcpa);
      v6 = bcpa;
      if ( bcpa >= i->CodeEnd )
        break;
      Scaleform::GFx::AS3::Tracer::RegisterOrigOpCode(i, bcpa);
      v7 = v6 + 1;
      v8 = (unsigned __int8)i->pCode[v7 - 1];
      v9 = i->CurrBlock;
      bcpa = v7;
      v10 = v8;
      if ( !Scaleform::GFx::AS3::Tracer::SubstituteOpCode(i, v8, &bcpa, v9->State) )
      {
        if ( i->CF->pFile->VMRef->HandleException )
          return;
        Scaleform::GFx::AS3::TR::State::exec_opcode(i->CurrBlock->State, v10, &bcpa);
      }
      v3 = bcpa;
    }
    while ( bcpa < i->CodeEnd );
  }
}

// File Line: 5107
// RVA: 0x822490
void __fastcall Scaleform::GFx::AS3::Tracer::StoreOffset(Scaleform::GFx::AS3::Tracer *this, unsigned __int64 bcp, Scaleform::GFx::AS3::TR::State *st, int offset, int base)
{
  Scaleform::GFx::AS3::Tracer *v5; // rdi
  unsigned __int64 v6; // rbx
  Scaleform::GFx::AS3::MethodInfo *v7; // rax
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Tracer::Recalculate,Scaleform::AllocatorDH_POD<Scaleform::GFx::AS3::Tracer::Recalculate,328>,Scaleform::ArrayDefaultPolicy> *v8; // rdi
  unsigned __int64 v9; // rsi
  unsigned __int64 v10; // rax
  signed __int64 v11; // rsi
  unsigned __int64 v12; // rbx
  unsigned __int64 v13; // r8
  Scaleform::GFx::AS3::Tracer::Recalculate *v14; // rcx
  signed __int64 v15; // rbx
  __int64 v16; // [rsp+38h] [rbp-10h]

  v5 = this;
  v6 = bcp + offset;
  if ( offset < 0 )
  {
    Scaleform::GFx::AS3::Tracer::PushNewOpCodeArg0(
      this,
      base + this->Orig2newPosMap.Data.Data[v6] - this->MI->OpCode.Data.Size);
    return;
  }
  Scaleform::GFx::AS3::Tracer::AddBlock(this, st, v6, 0, 1);
  Scaleform::GFx::AS3::Tracer::PushNewOpCodeArg0(v5, v6);
  v7 = v5->MI;
  v8 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Tracer::Recalculate,Scaleform::AllocatorDH_POD<Scaleform::GFx::AS3::Tracer::Recalculate,328>,Scaleform::ArrayDefaultPolicy> *)&v5->PosToRecalculate.Data.Data;
  v9 = v7->OpCode.Data.Size;
  LODWORD(v16) = base;
  v10 = v8->Size;
  v11 = v9 - 1;
  v12 = v10 + 1;
  if ( v10 + 1 >= v10 )
  {
    if ( v12 > v8->Policy.Capacity )
    {
      v13 = v12 + (v12 >> 2);
      goto LABEL_8;
    }
  }
  else if ( v12 < v8->Policy.Capacity >> 1 )
  {
    v13 = v10 + 1;
LABEL_8:
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Tracer::Recalculate,Scaleform::AllocatorDH_POD<Scaleform::GFx::AS3::Tracer::Recalculate,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v8,
      v8[1].Data,
      v13);
    goto LABEL_9;
  }
LABEL_9:
  v14 = v8->Data;
  v8->Size = v12;
  v15 = v12;
  v14[v15 - 1].pos = v11;
  *((_QWORD *)&v14[v15] - 1) = v16;
}

// File Line: 5200
// RVA: 0x821710
void __fastcall Scaleform::GFx::AS3::Tracer::SkipOrigOpCode(Scaleform::GFx::AS3::Tracer *this, unsigned __int64 *opcode_cp, unsigned __int64 new_cp)
{
  unsigned __int64 v3; // rsi
  unsigned __int64 *v4; // rbx
  Scaleform::GFx::AS3::Tracer *v5; // rdi

  v3 = new_cp;
  v4 = opcode_cp;
  v5 = this;
  if ( *opcode_cp >= this->CodeEnd )
  {
    *opcode_cp = new_cp;
  }
  else
  {
    Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy>>::PushBack(
      (Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy> > *)&this->OrigOpcodePos.Data,
      opcode_cp);
    v5->Orig2newPosMap.Data.Data[*v4] = v5->MI->OpCode.Data.Size;
    *v4 = v3;
  }
}

// File Line: 5216
// RVA: 0x80FBF0
void __fastcall Scaleform::GFx::AS3::Tracer::RegisterOrigOpCode(Scaleform::GFx::AS3::Tracer *this, unsigned __int64 opcode_cp)
{
  unsigned __int64 v2; // rbp
  Scaleform::GFx::AS3::Tracer *v3; // rsi
  unsigned __int64 v4; // rax
  unsigned __int64 v5; // rdi
  unsigned __int64 v6; // r8
  unsigned __int64 *v7; // rax

  v2 = opcode_cp;
  v3 = this;
  if ( opcode_cp < this->CodeEnd )
  {
    this->CurrOffset = opcode_cp;
    v4 = this->OrigOpcodePos.Data.Size;
    v5 = v4 + 1;
    if ( v4 + 1 >= v4 )
    {
      if ( v5 > this->OrigOpcodePos.Data.Policy.Capacity )
      {
        v6 = v5 + (v5 >> 2);
        goto LABEL_7;
      }
    }
    else if ( v5 < this->OrigOpcodePos.Data.Policy.Capacity >> 1 )
    {
      v6 = v4 + 1;
LABEL_7:
      Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy> *)&this->OrigOpcodePos.Data.Data,
        this->OrigOpcodePos.Data.pHeap,
        v6);
      goto LABEL_8;
    }
LABEL_8:
    v7 = v3->OrigOpcodePos.Data.Data;
    v3->OrigOpcodePos.Data.Size = v5;
    v7[v5 - 1] = v2;
    v3->Orig2newPosMap.Data.Data[v2] = v3->MI->OpCode.Data.Size;
  }
}

// File Line: 5256
// RVA: 0x7ED7D0
signed __int64 __fastcall Scaleform::GFx::AS3::Tracer::GetOrigValueConsumer(Scaleform::GFx::AS3::Tracer *this, unsigned __int64 bcp)
{
  unsigned __int64 v2; // rbp
  unsigned __int64 v3; // r8
  Scaleform::GFx::AS3::Tracer *v4; // r14
  int v5; // esi
  const char *v6; // rbx
  __int64 v7; // rdi
  char v8; // dl
  int v9; // eax
  int v10; // ecx
  int v11; // er9
  signed __int64 v12; // r8
  int v13; // er9
  unsigned __int8 v14; // r10
  signed int v15; // esi
  char v16; // al
  unsigned int v17; // ecx
  int v18; // er9
  char v19; // dl
  int v20; // eax
  char v21; // al
  unsigned int v22; // ecx
  int v23; // er9
  char v24; // dl
  int v25; // eax
  char v26; // al
  unsigned int v27; // ecx
  int v28; // er9
  char v29; // dl
  int v30; // eax
  char v31; // al
  unsigned int v32; // ecx
  char v33; // al
  char v34; // al
  unsigned int v35; // ecx
  char v36; // al
  unsigned __int64 cp; // [rsp+48h] [rbp+10h]

  v2 = this->CodeEnd;
  v3 = bcp;
  v4 = this;
  v5 = 1;
  if ( bcp < v2 )
  {
    v6 = this->pCode;
    while ( 1 )
    {
      v7 = (unsigned __int8)v6[v3++];
      if ( (_DWORD)v7 == 16 )
      {
        v8 = v6[v3 + 2];
        v9 = (unsigned __int8)v6[v3 + 1];
        v10 = (unsigned __int8)v6[v3];
        v11 = (unsigned __int8)v6[v3 + 2];
        v12 = v3 + 3;
        v13 = v10 | ((v9 | (v11 << 8)) << 8);
        if ( v8 < 0 )
          v13 = -1 - (v13 ^ 0xFFFFFF);
        v3 = v13 + v12;
        goto LABEL_44;
      }
      v14 = byte_14182DEC1[2 * v7];
      v15 = v5 - (((unsigned int)*(_BYTE *)&Scaleform::GFx::AS3::Abc::Code::opcode_info[v7] >> 5) & 3);
      if ( v14 & 8 )
      {
        v16 = v6[v3++];
        v17 = 7;
        v18 = v16 & 0x7F;
        if ( v16 < 0 )
        {
          do
          {
            if ( v17 >= 0x20 )
              break;
            v19 = v6[v3++];
            v20 = (v19 & 0x7F) << v17;
            v17 += 7;
            v18 |= v20;
          }
          while ( v19 < 0 );
        }
        switch ( v4->CF->pFile->File.pObject->Const_Pool.const_multiname.Data.Data[v18].Kind )
        {
          case 1:
          case 6:
          case 9:
          case 0xE:
            --v15;
            break;
          case 5:
          case 0xD:
            v15 -= 2;
            break;
          default:
            break;
        }
      }
      if ( v14 & 4 )
      {
        v21 = v6[v3++];
        v22 = 7;
        v23 = v21 & 0x7F;
        if ( v21 < 0 )
        {
          do
          {
            if ( v22 >= 0x20 )
              break;
            v24 = v6[v3++];
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
      v5 = (byte_14182DEC1[2 * v7] & 3) + v15;
      if ( !((v14 | (v14 >> 1)) & 4) )
      {
        if ( (signed int)v7 < 12 )
          goto LABEL_49;
        if ( (signed int)v7 <= 26 )
        {
          v3 += 3i64;
          goto LABEL_44;
        }
        if ( (_DWORD)v7 == 27 )
        {
          v26 = v6[v3 + 3];
          v3 += 4i64;
          v27 = 7;
          v28 = v26 & 0x7F;
          if ( v26 < 0 )
          {
            do
            {
              if ( v27 >= 0x20 )
                break;
              v29 = v6[v3++];
              v30 = (v29 & 0x7F) << v27;
              v27 += 7;
              v28 |= v30;
            }
            while ( v29 < 0 );
          }
          if ( v28 >= 0 )
            v3 += (unsigned int)(v28 + 1) + 2i64 * (unsigned int)(v28 + 1);
          goto LABEL_44;
        }
        if ( (_DWORD)v7 == 36 )
        {
          ++v3;
          goto LABEL_44;
        }
        if ( (_DWORD)v7 != 239 )
        {
LABEL_49:
          if ( (char)(16 * *(_BYTE *)&Scaleform::GFx::AS3::Abc::Code::opcode_info[v7]) >> 4 == 1 )
            goto LABEL_41;
          if ( (char)(16 * *(_BYTE *)&Scaleform::GFx::AS3::Abc::Code::opcode_info[v7]) >> 4 == 2 )
          {
            v31 = v6[v3++];
            v32 = 7;
            if ( v31 < 0 )
            {
              do
              {
                if ( v32 >= 0x20 )
                  break;
                v33 = v6[v3++];
                v32 += 7;
              }
              while ( v33 < 0 );
            }
LABEL_41:
            v34 = v6[v3++];
            v35 = 7;
            if ( v34 < 0 )
            {
              do
              {
                if ( v35 >= 0x20 )
                  break;
                v36 = v6[v3++];
                v35 += 7;
              }
              while ( v36 < 0 );
            }
            goto LABEL_44;
          }
        }
        else
        {
          cp = v3 + 1;
          Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v6, &cp);
          ++cp;
          Scaleform::GFx::AS3::Abc::ReadU30<unsigned char>(v6, &cp);
          v3 = cp;
        }
      }
LABEL_44:
      if ( v3 >= v2 )
        return (unsigned int)v7;
    }
  }
  return 2i64;
}

// File Line: 5664
// RVA: 0x7F9870
void __fastcall Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(Scaleform::GFx::AS3::Tracer *this, Scaleform::GFx::AS3::Value *to, Scaleform::GFx::AS3::Value *from, Scaleform::GFx::AS3::InstanceTraits::Traits *result_type)
{
  Scaleform::GFx::AS3::Value *v4; // r11
  Scaleform::GFx::AS3::VM *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::fl::Boolean *v6; // rcx
  char v7; // al
  int v8; // edx
  unsigned int v9; // ebx
  bool v10; // zf
  Scaleform::GFx::AS3::Value other; // [rsp+28h] [rbp-30h]

  v4 = to;
  v5 = this->CF->pFile->VMRef;
  if ( result_type == v5->TraitsInt.pObject->ITraits.pObject
    || result_type == v5->TraitsUint.pObject->ITraits.pObject
    || result_type == v5->TraitsNumber.pObject->ITraits.pObject
    || (v6 = v5->TraitsBoolean.pObject, v7 = 0, result_type == v6->ITraits.pObject) )
  {
    v7 = 1;
  }
  v8 = 2;
  if ( v7 )
    v8 = 0;
  if ( v8 )
  {
    v8 = 2;
    if ( ((v4->Flags >> 5) & 3) == ((from->Flags >> 5) & 3) )
      v8 = (v4->Flags >> 5) & 3;
  }
  other.Bonus.pWeakProxy = 0i64;
  *(_QWORD *)&other.value.VNumber = result_type;
  other.Flags = (32 * v8 | 8) & 0xFFFFFEFF;
  Scaleform::GFx::AS3::Value::Assign(v4, &other);
  v9 = other.Flags;
  if ( (other.Flags & 0x1F) > 9 )
  {
    if ( (other.Flags >> 9) & 1 )
    {
      v10 = other.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v10 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      other.Bonus.pWeakProxy = 0i64;
      other.value = 0ui64;
      other.Flags = v9 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
    }
  }
}

// File Line: 5717
// RVA: 0x7F9740
void __fastcall Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(Scaleform::GFx::AS3::Tracer *this, Scaleform::GFx::AS3::Value *to, Scaleform::GFx::AS3::Value *from, Scaleform::GFx::AS3::ClassTraits::Traits *result_type)
{
  Scaleform::GFx::AS3::Value *v4; // rbx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v5; // r10
  Scaleform::GFx::AS3::VM *v6; // rax
  Scaleform::GFx::AS3::ClassTraits::fl::Boolean *v7; // rcx
  char v8; // al
  int v9; // edx
  unsigned int v10; // ebx
  bool v11; // zf
  Scaleform::GFx::AS3::Value other; // [rsp+28h] [rbp-30h]

  v4 = to;
  v5 = result_type->ITraits.pObject;
  v6 = this->CF->pFile->VMRef;
  if ( v5 == v6->TraitsInt.pObject->ITraits.pObject
    || v5 == v6->TraitsUint.pObject->ITraits.pObject
    || v5 == v6->TraitsNumber.pObject->ITraits.pObject
    || (v7 = v6->TraitsBoolean.pObject, v8 = 0, v5 == v7->ITraits.pObject) )
  {
    v8 = 1;
  }
  v9 = 2;
  if ( v8 )
    v9 = 0;
  if ( v9 )
  {
    v9 = 2;
    if ( ((v4->Flags >> 5) & 3) == ((from->Flags >> 5) & 3) )
      v9 = (v4->Flags >> 5) & 3;
  }
  other.Bonus.pWeakProxy = 0i64;
  *(_QWORD *)&other.value.VNumber = result_type;
  other.Flags = (32 * v9 | 9) & 0xFFFFFEFF;
  Scaleform::GFx::AS3::Value::Assign(v4, &other);
  v10 = other.Flags;
  if ( (other.Flags & 0x1F) > 9 )
  {
    if ( (other.Flags >> 9) & 1 )
    {
      v11 = other.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v11 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      other.Bonus.pWeakProxy = 0i64;
      other.value = 0ui64;
      other.Flags = v10 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
    }
  }
}

// File Line: 5770
// RVA: 0x8010B0
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Tracer::MergeValues(Scaleform::GFx::AS3::Tracer *this, Scaleform::GFx::AS3::CheckResult *result, unsigned __int64 ind, Scaleform::GFx::AS3::TR::State *to, Scaleform::GFx::AS3::TR::State *from, Scaleform::GFx::AS3::TR::MergeSet ms)
{
  Scaleform::GFx::AS3::Tracer *v6; // r13
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v7; // r11
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v8; // rbx
  Scaleform::GFx::AS3::Value *v9; // r12
  Scaleform::GFx::AS3::Value *v10; // r14
  Scaleform::GFx::AS3::InstanceTraits::Traits *v11; // rbx
  Scaleform::GFx::AS3::VM *v12; // rax
  unsigned int v13; // esi
  int v14; // ebp
  Scaleform::GFx::AS3::Traits *v15; // rdi
  Scaleform::GFx::AS3::VM *v16; // rax
  unsigned int v17; // er9
  unsigned __int64 v18; // rdx
  signed int v19; // er8
  Scaleform::GFx::AS3::TR::State *v20; // rsi
  Scaleform::GFx::AS3::VMAbcFile *v21; // rsi
  Scaleform::GFx::AS3::VM *v22; // rax
  bool v23; // dl
  Scaleform::GFx::AS3::InstanceTraits::Traits *i; // rax
  char v25; // si
  Scaleform::GFx::AS3::VM *v26; // rax
  Scaleform::GFx::AS3::VM *v27; // rbx
  Scaleform::GFx::AS3::VM::Error *v28; // rax
  Scaleform::GFx::ASStringNode *v29; // rcx
  bool v30; // zf
  Scaleform::GFx::AS3::CheckResult *v31; // rax
  unsigned __int64 v32; // rdx
  signed int v33; // er8
  bool v34; // al
  char v35; // r15
  char *v36; // rax
  bool v37; // [rsp+20h] [rbp-58h]
  int v38; // [rsp+24h] [rbp-54h]
  Scaleform::GFx::AS3::VM::Error v39; // [rsp+30h] [rbp-48h]
  Scaleform::GFx::AS3::CheckResult *v40; // [rsp+88h] [rbp+10h]
  unsigned __int64 v41; // [rsp+90h] [rbp+18h]
  Scaleform::GFx::AS3::TR::State *v42; // [rsp+98h] [rbp+20h]

  v42 = to;
  v41 = ind;
  v40 = result;
  v6 = this;
  v7 = 0i64;
  v8 = 0i64;
  if ( ms )
  {
    if ( ms == 1 )
    {
      v8 = &to->ScopeStack;
    }
    else if ( ms == 2 )
    {
      v8 = &to->Registers;
    }
  }
  else
  {
    v8 = &to->OpStack;
  }
  if ( ms )
  {
    if ( ms == 1 )
    {
      v7 = &from->ScopeStack;
    }
    else if ( ms == 2 )
    {
      v7 = &from->Registers;
    }
  }
  else
  {
    v7 = &from->OpStack;
  }
  v9 = &v8->Data.Data[ind];
  v10 = &v7->Data.Data[ind];
  v38 = v9->Flags & 0x1F;
  if ( v38 )
  {
    if ( (v9->Flags & 0x1F) == 8 || (v9->Flags & 0x1F) == 9 )
      v11 = v9->value.VS._1.ITr;
    else
      v11 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)Scaleform::GFx::AS3::VM::GetValueTraits(
                                                             this->CF->pFile->VMRef,
                                                             v9);
  }
  else
  {
    v11 = this->CF->pFile->VMRef->TraitsVoid.pObject;
  }
  if ( v11 )
  {
    v12 = v6->CF->pFile->VMRef;
    if ( v11 == (Scaleform::GFx::AS3::InstanceTraits::Traits *)v12->TraitsClassClass.pObject )
      v11 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)v12->TraitsObject.pObject;
  }
  v13 = v10->Flags;
  v14 = v10->Flags & 0x1F;
  if ( v14 )
  {
    if ( (v10->Flags & 0x1F) == 8 || (v10->Flags & 0x1F) == 9 )
      v15 = (Scaleform::GFx::AS3::Traits *)v10->value.VS._1.VStr;
    else
      v15 = Scaleform::GFx::AS3::VM::GetValueTraits(v6->CF->pFile->VMRef, v10);
  }
  else
  {
    v15 = (Scaleform::GFx::AS3::Traits *)&v6->CF->pFile->VMRef->TraitsVoid.pObject->vfptr;
  }
  if ( v15 )
  {
    v16 = v6->CF->pFile->VMRef;
    if ( v15 == (Scaleform::GFx::AS3::Traits *)v16->TraitsClassClass.pObject )
      v15 = (Scaleform::GFx::AS3::Traits *)&v16->TraitsObject.pObject->vfptr;
  }
  if ( ms == 1 )
  {
    if ( ((unsigned __int8)(LOWORD(v9->Flags) >> 8) ^ BYTE1(v13)) & 1 )
      goto $error;
  }
  else if ( ms == 2 )
  {
    v17 = v41;
    v18 = (unsigned __int64)(unsigned int)v41 >> 3;
    v19 = 1 << (v41 & 7);
    v20 = v42;
    if ( !((unsigned __int8)v19 & from->RegistersAlive.pData[v18]) )
      goto LABEL_86;
    if ( !((unsigned __int8)v19 & v42->RegistersAlive.pData[v18]) )
    {
      Scaleform::GFx::AS3::Value::Assign(v9, v10);
LABEL_85:
      v17 = v41;
LABEL_86:
      v32 = (unsigned __int64)v17 >> 3;
      v33 = 1 << (v17 & 7);
      v34 = (unsigned __int8)v33 & from->RegistersAlive.pData[v32]
         || (unsigned __int8)v33 & v20->RegistersAlive.pData[v32];
      v35 = 1 << (v17 & 7);
      v30 = v34 == 0;
      v36 = v20->RegistersAlive.pData;
      if ( v30 )
        v36[v32] &= ~v35;
      else
        v36[v32] |= v35;
      goto LABEL_93;
    }
  }
  if ( v11 == (Scaleform::GFx::AS3::InstanceTraits::Traits *)v15 )
  {
$success:
    if ( ms != 2 )
    {
LABEL_93:
      v31 = v40;
      v40->Result = 1;
      return v31;
    }
    v20 = v42;
    goto LABEL_85;
  }
  if ( !v38 )
    goto LABEL_82;
  v21 = v6->CF->pFile;
  v22 = v21->VMRef;
  if ( v11 == v22->TraitsObject.pObject->ITraits.pObject || v11 == v22->TraitsClassClass.pObject->ITraits.pObject )
    goto $success;
  if ( Scaleform::GFx::AS3::Tracer::IsAnyType(v6, v15) )
  {
    Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(v6, v9, v10, v21->VMRef->TraitsObject.pObject->ITraits.pObject);
    goto $success;
  }
  v23 = Scaleform::GFx::AS3::Tracer::IsNumericType(v6, (Scaleform::GFx::AS3::Traits *)&v11->vfptr);
  v37 = v23;
  if ( v23 )
  {
    if ( Scaleform::GFx::AS3::Tracer::IsNumericType(v6, v15) )
    {
      Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(v6, v9, v10, v21->VMRef->TraitsNumber.pObject->ITraits.pObject);
      goto $success;
    }
    v23 = v37;
  }
  if ( ((unsigned int)(v38 - 12) <= 3 || v38 == 10) && !*(_QWORD *)&v9->value.VNumber
    || v11 == v21->VMRef->TraitsNull.pObject )
  {
    if ( ((unsigned int)(v14 - 12) <= 3 || v14 == 10) && !*(_QWORD *)&v10->value.VNumber )
      goto $success;
    v26 = v21->VMRef;
    if ( v15 == (Scaleform::GFx::AS3::Traits *)v26->TraitsNull.pObject )
      goto $success;
    if ( v15 != (Scaleform::GFx::AS3::Traits *)v26->TraitsString.pObject->ITraits.pObject
      && Scaleform::GFx::AS3::Tracer::IsNumericType(v6, v15) )
    {
      goto $error;
    }
LABEL_82:
    Scaleform::GFx::AS3::Value::Assign(v9, v10);
    goto $success;
  }
  if ( ((unsigned int)(v14 - 12) > 3 && v14 != 10 || *(_QWORD *)&v10->value.VNumber)
    && v15 != (Scaleform::GFx::AS3::Traits *)v21->VMRef->TraitsNull.pObject )
  {
    for ( i = v11; i; i = (Scaleform::GFx::AS3::InstanceTraits::Traits *)i->pParent.pObject )
      i->Flags |= 0x80ui64;
    if ( v15 )
    {
      while ( SLOBYTE(v15->Flags) >= 0 )
      {
        v15 = v15->pParent.pObject;
        if ( !v15 )
          goto LABEL_65;
      }
      v25 = 1;
      if ( (LOBYTE(v15->Flags) >> 5) & 1 )
        Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(v6, v9, v10, (Scaleform::GFx::AS3::ClassTraits::Traits *)v15);
      else
        Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(
          v6,
          v9,
          v10,
          (Scaleform::GFx::AS3::InstanceTraits::Traits *)v15);
    }
    else
    {
LABEL_65:
      v25 = 0;
    }
    for ( ; v11; v11 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)v11->pParent.pObject )
      v11->Flags &= 0xFFFFFFFFFFFFFF7Fui64;
    if ( v25 )
      goto $success;
  }
  else if ( v11 == v21->VMRef->TraitsString.pObject->ITraits.pObject || !v23 )
  {
    goto $success;
  }
$error:
  v27 = v6->CF->pFile->VMRef;
  Scaleform::GFx::AS3::VM::Error::Error(&v39, eCannotMergeTypesError, v27);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(v27, v28, &Scaleform::GFx::AS3::fl::VerifyErrorTI);
  v29 = v39.Message.pNode;
  v30 = v39.Message.pNode->RefCount == 1;
  --v29->RefCount;
  if ( v30 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v29);
  v31 = v40;
  v40->Result = 0;
  return v31;
}

// File Line: 5951
// RVA: 0x800F60
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Tracer::MergeLists(Scaleform::GFx::AS3::Tracer *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::TR::State *to, Scaleform::GFx::AS3::TR::State *from, bool check_size, Scaleform::GFx::AS3::TR::MergeSet ms)
{
  Scaleform::GFx::AS3::TR::MergeSet v6; // er12
  unsigned __int64 v7; // rbx
  Scaleform::GFx::AS3::CheckResult *v8; // rbp
  Scaleform::GFx::AS3::TR::State *v9; // r13
  Scaleform::GFx::AS3::Tracer *v10; // r10
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *v11; // rsi
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v12; // r14
  __int64 v14; // r15
  unsigned __int64 v15; // r8
  Scaleform::GFx::AS3::Value *v16; // rdi
  Scaleform::GFx::AS3::Tracer *v17; // [rsp+70h] [rbp+8h]
  Scaleform::GFx::AS3::TR::State *v18; // [rsp+88h] [rbp+20h]

  v18 = from;
  v17 = this;
  v6 = ms;
  v7 = 0i64;
  v8 = result;
  v9 = to;
  v10 = this;
  v11 = 0i64;
  if ( ms )
  {
    if ( ms == 1 )
    {
      v11 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&to->ScopeStack.Data.Data;
    }
    else if ( ms == 2 )
    {
      v11 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&to->Registers.Data.Data;
    }
  }
  else
  {
    v11 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&to->OpStack.Data.Data;
  }
  v12 = 0i64;
  if ( ms )
  {
    if ( ms == 1 )
    {
      v12 = &from->ScopeStack;
    }
    else if ( ms == 2 )
    {
      v12 = &from->Registers;
    }
  }
  else
  {
    v12 = &from->OpStack;
  }
  if ( check_size && v11->Size != v12->Data.Size )
  {
    result->Result = 0;
    return result;
  }
  if ( v12->Data.Size <= 0 )
  {
LABEL_22:
    v8->Result = 1;
    return v8;
  }
  v14 = 0i64;
  while ( 1 )
  {
    v15 = v11->Size;
    if ( v7 < v15 )
      break;
    v16 = &v12->Data.Data[v14];
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      v11,
      v11[1].Data,
      v15 + 1);
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(&v11->Data[v11->Size - 1], v16);
LABEL_21:
    from = v18;
    v10 = v17;
    ++v7;
    ++v14;
    if ( v7 >= v12->Data.Size )
      goto LABEL_22;
  }
  if ( Scaleform::GFx::AS3::Tracer::MergeValues(v10, (Scaleform::GFx::AS3::CheckResult *)&check_size, v7, v9, from, v6)->Result )
    goto LABEL_21;
  v8->Result = 0;
  return v8;
}

// File Line: 5977
// RVA: 0x7F58D0
void __fastcall Scaleform::GFx::AS3::Tracer::InitializeBlock(Scaleform::GFx::AS3::Tracer *this, Scaleform::GFx::AS3::TR::Block *to, Scaleform::GFx::AS3::TR::Block *from)
{
  Scaleform::GFx::AS3::TR::State *v3; // rbx
  Scaleform::GFx::AS3::TR::State *v4; // rdi
  Scaleform::GFx::AS3::TR::Block *v5; // rbp
  Scaleform::GFx::AS3::Tracer *v6; // rsi
  Scaleform::GFx::AS3::CheckResult result; // [rsp+48h] [rbp+10h]

  v3 = from->State;
  v4 = to->State;
  to->CurOpStackSize = from->CurOpStackSize;
  v5 = to;
  v6 = this;
  Scaleform::GFx::AS3::Tracer::MergeLists(this, &result, v4, v3, 0, 0);
  Scaleform::GFx::AS3::Tracer::MergeLists(v6, &result, v4, v3, 0, msScopeStack);
  Scaleform::GFx::AS3::Tracer::MergeLists(v6, &result, v4, v3, 1, msRegisterFile);
  *((_DWORD *)v5 + 4) |= 1u;
}

// File Line: 5992
// RVA: 0x800E40
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Tracer::MergeBlock(Scaleform::GFx::AS3::Tracer *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::TR::Block *to, Scaleform::GFx::AS3::TR::Block *from)
{
  Scaleform::GFx::AS3::CheckResult *v4; // rdi
  Scaleform::GFx::AS3::Tracer *v5; // rbx
  Scaleform::GFx::AS3::TR::State *v6; // rsi
  Scaleform::GFx::AS3::TR::State *v7; // rbp
  unsigned __int64 v8; // rcx
  Scaleform::GFx::AS3::VM *v9; // rbx
  Scaleform::GFx::AS3::VM::Error *v10; // rax
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  Scaleform::GFx::AS3::VM::Error v14; // [rsp+38h] [rbp-20h]
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+70h] [rbp+18h]

  v4 = result;
  v5 = this;
  v6 = from->State;
  v7 = to->State;
  if ( (to->Type >> 2) & 1 || to->Type & 1 )
    goto LABEL_13;
  v8 = from->CurOpStackSize;
  if ( v8 < to->CurOpStackSize )
    v8 = to->CurOpStackSize;
  to->CurOpStackSize = v8;
  Scaleform::GFx::AS3::Tracer::MergeLists(v5, &resulta, v7, v6, 1, 0);
  if ( Scaleform::GFx::AS3::Tracer::MergeLists(v5, &resulta, v7, v6, 0, msScopeStack)->Result )
  {
LABEL_13:
    Scaleform::GFx::AS3::Tracer::MergeLists(v5, v4, v7, v6, 1, msRegisterFile);
  }
  else
  {
    v9 = v5->CF->pFile->VMRef;
    Scaleform::GFx::AS3::VM::Error::Error(&v14, eScopeDepthUnbalancedError, v9);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v9, v10, &Scaleform::GFx::AS3::fl::VerifyErrorTI);
    v11 = v14.Message.pNode;
    v12 = v14.Message.pNode->RefCount == 1;
    --v11->RefCount;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    v4->Result = 0;
  }
  return v4;
}

// File Line: 6044
// RVA: 0x823530
Scaleform::GFx::AS3::Tracer::SubstituteOpCode

// File Line: 6860
// RVA: 0x823180
char __fastcall Scaleform::GFx::AS3::Tracer::SubstituteGetlocal(Scaleform::GFx::AS3::Tracer *this, unsigned __int64 *bcp, unsigned __int64 ccp, Scaleform::GFx::AS3::TR::State *st, int src_reg_num)
{
  Scaleform::GFx::AS3::TR::State *v5; // r15
  Scaleform::GFx::AS3::Tracer *v6; // rsi
  unsigned __int64 v7; // r14
  int v8; // ebp
  signed __int64 v9; // rcx
  unsigned __int64 v10; // rax
  unsigned __int64 v11; // rbx
  unsigned __int64 v12; // r8
  unsigned __int64 *v13; // rax
  signed int v14; // er10
  const char *v15; // r8
  unsigned __int64 v16; // r14
  int v17; // ecx
  signed int v18; // ebx
  int v19; // er12
  signed int v20; // er13
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
  int v34; // er8
  Scaleform::GFx::AS3::Traits *v35; // rax
  long double v36; // rdx
  Scaleform::GFx::AS3::VM *v37; // rax
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
  Scaleform::GFx::AS3::InstanceTraits::Traits **v48; // r8
  signed int v49; // [rsp+60h] [rbp+8h]
  unsigned __int64 *opcode_cp; // [rsp+68h] [rbp+10h]
  Scaleform::GFx::AS3::Value *v; // [rsp+70h] [rbp+18h]

  opcode_cp = bcp;
  v5 = st;
  v6 = this;
  v7 = ccp + 1;
  v = &st->Registers.Data.Data[src_reg_num];
  v8 = (unsigned __int8)this->pCode[ccp];
  if ( (unsigned int)(v8 - 145) > 0x30 )
    return 0;
  v9 = 422212465065989i64;
  if ( !_bittest64(&v9, v8 - 145) )
    return 0;
  v10 = v6->OrigOpcodePos.Data.Size;
  v11 = v10 + 1;
  if ( v10 + 1 >= v10 )
  {
    if ( v11 <= v6->OrigOpcodePos.Data.Policy.Capacity )
      goto LABEL_9;
    v12 = v11 + (v11 >> 2);
  }
  else
  {
    if ( v11 >= v6->OrigOpcodePos.Data.Policy.Capacity >> 1 )
      goto LABEL_9;
    v12 = v10 + 1;
  }
  Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
    (Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy> *)&v6->OrigOpcodePos.Data.Data,
    v6->OrigOpcodePos.Data.pHeap,
    v12);
LABEL_9:
  v13 = v6->OrigOpcodePos.Data.Data;
  v6->OrigOpcodePos.Data.Size = v11;
  v14 = 1;
  v13[v11 - 1] = v7;
  v15 = v6->pCode;
  v16 = v7 + 1;
  v17 = (unsigned __int8)v15[v16 - 1];
  v18 = 4;
  v19 = 3;
  if ( v17 == 115 )
  {
    v49 = 2;
  }
  else if ( v15[v16 - 1] == 116 )
  {
    v49 = 3;
  }
  else
  {
    if ( v15[v16 - 1] != 117 )
    {
      v20 = 4;
      if ( (unsigned int)(v8 - 192) <= 1 )
        v20 = 2;
      goto LABEL_25;
    }
    v49 = 4;
  }
  v21 = v6->OrigOpcodePos.Data.Size;
  v22 = v21 + 1;
  if ( v21 + 1 >= v21 )
  {
    if ( v22 > v6->OrigOpcodePos.Data.Policy.Capacity )
    {
      v23 = v22 + (v22 >> 2);
      goto LABEL_23;
    }
  }
  else if ( v22 < v6->OrigOpcodePos.Data.Policy.Capacity >> 1 )
  {
    v23 = v21 + 1;
LABEL_23:
    Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy> *)&v6->OrigOpcodePos.Data.Data,
      v6->OrigOpcodePos.Data.pHeap,
      v23);
    goto LABEL_24;
  }
LABEL_24:
  v24 = v6->OrigOpcodePos.Data.Data;
  v6->OrigOpcodePos.Data.Size = v22;
  v14 = 2;
  v24[v22 - 1] = v16;
  v15 = v6->pCode;
  v20 = v49;
  v17 = (unsigned __int8)v15[v16++];
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
              &v6->OrigOpcodePos.Data,
              v6->OrigOpcodePos.Data.Size - v14);
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
    v30 = v15[v16++];
    v31 = 7;
    v19 = v30 & 0x7F;
    if ( v30 < 0 )
    {
      do
      {
        if ( v31 >= 0x20 )
          break;
        v32 = v15[v16++];
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
  if ( v->Flags & 0x1F )
  {
    if ( (v->Flags & 0x1F) == 8 || (v->Flags & 0x1F) == 9 )
    {
      v36 = v->value.VNumber;
    }
    else
    {
      v35 = Scaleform::GFx::AS3::VM::GetValueTraits(v6->CF->pFile->VMRef, v);
      v34 = src_reg_num;
      v36 = *(double *)&v35;
    }
  }
  else
  {
    v36 = *(double *)&v6->CF->pFile->VMRef->TraitsVoid.pObject;
  }
  if ( v36 != 0.0 )
  {
    v37 = v6->CF->pFile->VMRef;
    if ( *(Scaleform::GFx::AS3::ClassTraits::ClassClass **)&v36 == v37->TraitsClassClass.pObject )
      v36 = *(double *)&v37->TraitsObject.pObject;
    if ( v36 != 0.0 )
    {
      if ( ~(*(_BYTE *)(*(_QWORD *)&v36 + 112i64) >> 5) & 1 )
        v18 = *(_DWORD *)(*(_QWORD *)&v36 + 120i64);
    }
  }
  v38 = v8 - 145;
  if ( !v38 )
    goto LABEL_81;
  v39 = v38 - 2;
  if ( !v39 )
    goto LABEL_56;
  v40 = v39 - 45;
  if ( !v40 )
  {
LABEL_81:
    if ( v18 == v20 )
    {
      v46 = v18 - 2;
      if ( !v46 )
      {
        v45 = 10;
        goto LABEL_76;
      }
      v47 = v46 - 1;
      if ( !v47 )
      {
        v44 = 55;
        goto LABEL_74;
      }
      if ( v47 != 1 )
        goto LABEL_72;
    }
    else if ( v20 == 2 )
    {
      v45 = 194;
      goto LABEL_76;
    }
    v43 = 146;
    goto LABEL_70;
  }
  if ( v40 != 1 )
    return 0;
LABEL_56:
  if ( v18 != v20 )
  {
    if ( v20 != 2 )
      goto LABEL_60;
    v45 = 195;
LABEL_76:
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(v6, v45, v34);
    v48 = (Scaleform::GFx::AS3::InstanceTraits::Traits **)v5->pTracer->CF->pFile->VMRef->TraitsInt.pObject;
    goto LABEL_71;
  }
  v41 = v18 - 2;
  if ( !v41 )
  {
    v45 = 11;
    goto LABEL_76;
  }
  v42 = v41 - 1;
  if ( !v42 )
  {
    v44 = 56;
LABEL_74:
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(v6, v44, v34);
    v48 = (Scaleform::GFx::AS3::InstanceTraits::Traits **)v5->pTracer->CF->pFile->VMRef->TraitsUint.pObject;
    goto LABEL_71;
  }
  if ( v42 == 1 )
  {
LABEL_60:
    v43 = 148;
LABEL_70:
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(v6, v43, v34);
    v48 = (Scaleform::GFx::AS3::InstanceTraits::Traits **)v5->pTracer->CF->pFile->VMRef->TraitsNumber.pObject;
LABEL_71:
    Scaleform::GFx::AS3::TR::State::ConvertRegisterTo(
      v5,
      (Scaleform::GFx::AS3::AbsoluteIndex)(unsigned int)src_reg_num,
      v48[25],
      0);
  }
LABEL_72:
  Scaleform::GFx::AS3::Tracer::SkipOrigOpCode(v6, opcode_cp, v16);
  return 1;
}

// File Line: 7139
// RVA: 0x7C8AD0
void __fastcall Scaleform::GFx::AS3::Tracer::EmitPopPrevResult(Scaleform::GFx::AS3::Tracer *this, Scaleform::GFx::AS3::TR::State *st)
{
  unsigned __int64 v2; // r8
  Scaleform::GFx::AS3::Tracer *v3; // rdi
  signed int v4; // eax
  Scaleform::ArrayDataDH<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy> *v5; // rcx
  unsigned __int64 v6; // rdx
  unsigned __int64 v7; // rbx

  v2 = this->NewOpcodePos.Data.Size;
  v3 = this;
  if ( v2 )
    v4 = this->MI->OpCode.Data.Data[this->NewOpcodePos.Data.Data[v2 - 1]];
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
      v5 = &this->NewOpcodePos.Data;
      v6 = v3->NewOpcodePos.Data.Size;
      v7 = v5->Data[v6 - 1];
      Scaleform::ArrayDataDH<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy>::Resize(
        v5,
        v6 - 1);
      Scaleform::ArrayData<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy>::Resize(
        &v3->MI->OpCode.Data,
        v7);
      break;
    default:
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_pop);
      break;
  }
}

// File Line: 7201
// RVA: 0x7C7D50
char __fastcall Scaleform::GFx::AS3::Tracer::EmitGetClassTraits(Scaleform::GFx::AS3::Tracer *this, Scaleform::GFx::AS3::TR::State *st, Scaleform::GFx::AS3::Multiname *as3_mn, bool objOnStack)
{
  bool v4; // r12
  Scaleform::GFx::AS3::Multiname *v5; // r15
  Scaleform::GFx::AS3::Tracer *v6; // r13
  Scaleform::GFx::AS3::ClassTraits::Traits *v7; // rax
  long double v8; // r14
  Scaleform::GFx::AS3::InstanceTraits::Traits *v9; // rbx
  long double v10; // r14
  unsigned int v11; // esi
  Scaleform::GFx::AS3::TR::State *v12; // rbx
  Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase> >,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase> >,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase> > > > *v13; // rcx
  signed __int64 v14; // rcx
  signed __int64 v15; // rdx
  bool v16; // zf
  Scaleform::GFx::AS3::Object *v17; // rdx
  Scaleform::GFx::AS3::Value::V2U v18; // r8
  int v19; // ecx
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *v21; // r12
  Scaleform::GFx::AS3::TR::State *v22; // rbx
  signed __int64 v23; // r8
  Scaleform::GFx::AS3::Value::V2U v24; // rdx
  int v25; // ecx
  Scaleform::GFx::AS3::Value v26; // [rsp+18h] [rbp-29h]
  Scaleform::GFx::AS3::Value value; // [rsp+38h] [rbp-9h]
  Scaleform::GFx::AS3::Object *key; // [rsp+A0h] [rbp+5Fh]
  Scaleform::GFx::AS3::TR::State *sta; // [rsp+A8h] [rbp+67h]
  char v30; // [rsp+C0h] [rbp+7Fh]

  v4 = objOnStack;
  v5 = as3_mn;
  v6 = this;
  v7 = Scaleform::GFx::AS3::FindClassTraits(this->CF->pFile->VMRef, as3_mn, this->CF->pFile->AppDomain.pObject);
  v8 = *(double *)&v7;
  if ( v7 )
  {
    v9 = v7->ITraits.pObject;
    if ( v9 )
    {
      if ( v9->pConstructor.pObject )
      {
        v10 = *(double *)&v9->pConstructor.pObject;
        v11 = 13;
        v26.Flags = 13;
        v26.Bonus.pWeakProxy = 0i64;
        v26.value.VNumber = v10;
        if ( v10 != 0.0 )
          *(_DWORD *)(*(_QWORD *)&v10 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v10 + 32i64) + 1) & 0x8FBFFFFF;
        v12 = sta;
        if ( v4 )
          Scaleform::GFx::AS3::Tracer::EmitPopPrevResult(v6, sta);
        Scaleform::GFx::AS3::Tracer::PushNewOpCode(v6, op_getabsobject, *(_QWORD *)&v10 + 2i64);
        v13 = (Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase> >,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase> >,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase> > > > *)v6->CF->pFile;
        if ( *(_QWORD *)&v10 != v13[5].pTable[41].EntryCount )
        {
          key = *(Scaleform::GFx::AS3::Object **)&v10;
          Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>>>>::Set<Scaleform::GFx::AS3::Object *>(
            v13 + 20,
            &v13[20],
            &key);
        }
        if ( v30 )
          v11 = 1037;
        v26.Flags = v11;
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v12->OpStack.Data.Data,
          v12->OpStack.Data.pHeap,
          v12->OpStack.Data.Size + 1);
        v14 = 32 * v12->OpStack.Data.Size;
        v15 = (signed __int64)&v12->OpStack.Data.Data[-1];
        v16 = v14 + v15 == 0;
        v17 = (Scaleform::GFx::AS3::Object *)(v14 + v15);
        key = v17;
        if ( !v16 )
        {
          LODWORD(v17->vfptr) = v11;
          v17->pRCCRaw = 0i64;
          *(long double *)&v17->pNext = v10;
          v18.VObj = (Scaleform::GFx::AS3::Object *)v26.value.VS._2;
          v17->pPrev = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v26.value.VS._2.VObj->vfptr;
          v19 = v11 & 0x1F;
          if ( v19 > 9 )
          {
            if ( (v11 >> 9) & 1 )
            {
              LODWORD(MEMORY[0]) = MEMORY[0] + 1;
            }
            else if ( v19 == 10 )
            {
              ++*(_DWORD *)(*(_QWORD *)&v10 + 24i64);
            }
            else if ( v19 > 10 )
            {
              if ( v19 <= 15 )
              {
                if ( v10 != 0.0 )
                  *(_DWORD *)(*(_QWORD *)&v10 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v10 + 32i64) + 1) & 0x8FBFFFFF;
              }
              else if ( v19 <= 17 && v18.VObj )
              {
                v18.VObj->RefCount = (v18.VObj->RefCount + 1) & 0x8FBFFFFF;
              }
            }
          }
        }
        if ( (char)(v11 & 0x1F) <= 9 )
          goto LABEL_31;
        if ( (v11 >> 9) & 1 )
        {
          LODWORD(MEMORY[0]) = MEMORY[0] - 1;
          if ( !(_DWORD)MEMORY[0] )
            Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
LABEL_29:
          v26.Bonus.pWeakProxy = 0i64;
          v26.value = 0ui64;
          v26.Flags = v11 & 0xFFFFFDE0;
LABEL_31:
          Scaleform::GFx::AS3::Multiname::~Multiname(v5);
          return 1;
        }
        goto LABEL_30;
      }
      if ( (LOBYTE(v9->Flags) >> 4) & 1 )
      {
        v21 = Scaleform::GFx::AS3::InstanceTraits::UserDefined::GetGlobalObjectScript((Scaleform::GFx::AS3::InstanceTraits::UserDefined *)v9);
        key = 0i64;
        if ( Scaleform::GFx::AS3::FindFixedSlot(
               v6->CF->pFile->VMRef,
               v21->pTraits.pObject,
               v5,
               (unsigned __int64 *)&key,
               (Scaleform::GFx::AS3::Object *)&v21->vfptr) )
        {
          v26.Bonus.pWeakProxy = 0i64;
          v26.value.VNumber = v8;
          v11 = 73;
          v26.Flags = 73;
          if ( v30 )
            v11 = 1097;
          v26.Flags = v11;
          v22 = sta;
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
            (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&sta->OpStack.Data.Data,
            sta->OpStack.Data.pHeap,
            sta->OpStack.Data.Size + 1);
          v23 = (signed __int64)&v22->OpStack.Data.Data[v22->OpStack.Data.Size - 1];
          if ( v23 )
          {
            *(_DWORD *)v23 = v11;
            *(_QWORD *)(v23 + 8) = 0i64;
            *(long double *)(v23 + 16) = v8;
            v24.VObj = (Scaleform::GFx::AS3::Object *)v26.value.VS._2;
            *(_QWORD *)(v23 + 24) = v26.value.VS._2.VObj;
            v25 = v11 & 0x1F;
            if ( v25 > 9 )
            {
              if ( (v11 >> 9) & 1 )
              {
                LODWORD(MEMORY[0]) = MEMORY[0] + 1;
              }
              else if ( v25 == 10 )
              {
                ++*(_DWORD *)(*(_QWORD *)&v8 + 24i64);
              }
              else if ( v25 > 10 )
              {
                if ( v25 <= 15 )
                {
                  *(_DWORD *)(*(_QWORD *)&v8 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v8 + 32i64) + 1) & 0x8FBFFFFF;
                }
                else if ( v25 <= 17 && v24.VObj )
                {
                  v24.VObj->RefCount = (v24.VObj->RefCount + 1) & 0x8FBFFFFF;
                }
              }
            }
          }
          value.Flags = 12;
          value.Bonus.pWeakProxy = 0i64;
          *(_QWORD *)&value.value.VNumber = v21;
          v21->RefCount = (v21->RefCount + 1) & 0x8FBFFFFF;
          Scaleform::GFx::AS3::Tracer::EmitGetAbsObject(v6, sta, &value, 0);
          Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
          Scaleform::GFx::AS3::Tracer::PushNewOpCode(v6, op_getabsslot, (unsigned int)((_DWORD)key + 1));
          if ( (char)(v11 & 0x1F) <= 9 )
            goto LABEL_31;
          if ( (v11 >> 9) & 1 )
          {
            LODWORD(MEMORY[0]) = MEMORY[0] - 1;
            if ( !(_DWORD)MEMORY[0] )
            {
              Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
              v26.Bonus.pWeakProxy = 0i64;
              v26.value = 0ui64;
              v26.Flags = v11 & 0xFFFFFDE0;
              goto LABEL_31;
            }
            goto LABEL_29;
          }
LABEL_30:
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v26);
          goto LABEL_31;
        }
      }
    }
  }
  Scaleform::GFx::AS3::Multiname::~Multiname(v5);
  return 0;
}

// File Line: 7281
// RVA: 0x7C6F40
_BOOL8 __fastcall Scaleform::GFx::AS3::Tracer::EmitFindProperty(Scaleform::GFx::AS3::Tracer *this, Scaleform::GFx::AS3::TR::State *st, const int mn_index, bool get_prop, Scaleform::GFx::AS3::Abc::Code::OpCode consumer)
{
  bool v5; // di
  Scaleform::GFx::AS3::TR::State *v6; // r15
  Scaleform::GFx::AS3::Tracer *v7; // rsi
  char v8; // r13
  int v9; // ebx
  char v10; // di
  long double v11; // r12
  int v12; // ebx
  long double v13; // r14
  Scaleform::GFx::AS3::VM *v14; // rax
  Scaleform::GFx::AS3::TR::State::ScopeType v15; // ebx
  Scaleform::GFx::AS3::Multiname *v16; // rax
  bool v17; // bl
  Scaleform::GFx::AS3::SlotInfo *v18; // rbx
  unsigned int v19; // eax
  int v20; // er13
  const char *v21; // r12
  unsigned int v22; // ebx
  signed int v23; // er14
  signed int v24; // edi
  __int64 v25; // rcx
  char v26; // al
  Scaleform::GFx::AS3::Abc::Code::OpCode v27; // edx
  Scaleform::GFx::AS3::Value *v28; // rdx
  unsigned int v29; // edi
  Scaleform::GFx::AS3::WeakProxy *v30; // rsi
  int v31; // ecx
  long double v32; // rcx
  Scaleform::GFx::AS3::Value *v33; // rdx
  Scaleform::GFx::AS3::WeakProxy *v34; // r12
  long double v35; // xmm0_8
  bool v36; // zf
  Scaleform::GFx::ASStringNode *v37; // rcx
  Scaleform::GFx::ASStringNode *v38; // rcx
  Scaleform::GFx::AS3::Traits *v39; // r8
  Scaleform::GFx::AS3::VM *v40; // rax
  unsigned int v41; // ebx
  unsigned int v42; // edi
  signed __int64 v43; // rcx
  signed __int64 v44; // r9
  unsigned __int64 v45; // r9
  Scaleform::GFx::AS3::WeakProxy *v46; // rdx
  long double v47; // r8
  Scaleform::GFx::AS3::Value::V2U v48; // r10
  int v49; // ecx
  Scaleform::GFx::AS3::Multiname *v50; // rax
  Scaleform::GFx::AS3::Tracer *v51; // rcx
  Scaleform::GFx::AS3::Abc::Code::OpCode v52; // edx
  Scaleform::GFx::AS3::SlotInfo *v53; // rbx
  __int64 v54; // rdx
  signed int v55; // ecx
  signed __int64 v56; // rbx
  Scaleform::GFx::AS3::VTable *v57; // rax
  Scaleform::GFx::AS3::Value *v58; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v59; // rdi
  int v60; // eax
  unsigned int v61; // ebx
  signed __int64 v62; // rbx
  Scaleform::GFx::AS3::VTable *v63; // rax
  Scaleform::GFx::AS3::Value *v64; // rdi
  Scaleform::GFx::AS3::VM *v65; // rbx
  Scaleform::GFx::AS3::VMAppDomain *v66; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v67; // rdi
  int v68; // eax
  unsigned int v69; // edi
  signed __int64 v70; // rcx
  signed __int64 v71; // r9
  unsigned __int64 v72; // r9
  Scaleform::GFx::AS3::WeakProxy *v73; // rdx
  long double v74; // r8
  Scaleform::GFx::AS3::Value::V2U v75; // r10
  int v76; // ecx
  Scaleform::GFx::AS3::Multiname *v77; // rax
  Scaleform::GFx::AS3::GASRefCountBase *v78; // rcx
  unsigned int v79; // eax
  Scaleform::GFx::AS3::Value type; // [rsp+30h] [rbp-D0h]
  Scaleform::GFx::ASString v82; // [rsp+50h] [rbp-B0h]
  unsigned int v83; // [rsp+58h] [rbp-A8h]
  Scaleform::GFx::AS3::Value v; // [rsp+60h] [rbp-A0h]
  unsigned __int64 arg1; // [rsp+80h] [rbp-80h]
  Scaleform::GFx::AS3::SlotInfo *v86; // [rsp+88h] [rbp-78h]
  Scaleform::GFx::AS3::PropRef result; // [rsp+90h] [rbp-70h]
  Scaleform::GFx::AS3::Multiname mn; // [rsp+C0h] [rbp-40h]
  Scaleform::GFx::AS3::Value v89; // [rsp+F0h] [rbp-10h]
  Scaleform::GFx::AS3::Value v90; // [rsp+110h] [rbp+10h]
  Scaleform::GFx::AS3::Value p; // [rsp+130h] [rbp+30h]
  Scaleform::GFx::AS3::Value v92; // [rsp+160h] [rbp+60h]
  Scaleform::GFx::AS3::CheckResult v93; // [rsp+1E0h] [rbp+E0h]
  Scaleform::GFx::AS3::TR::State::ScopeType stype; // [rsp+1F0h] [rbp+F0h]
  bool v95; // [rsp+1F8h] [rbp+F8h]

  v95 = get_prop;
  p.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)-2i64;
  v5 = get_prop;
  v6 = st;
  v7 = this;
  v83 = 0;
  Scaleform::GFx::AS3::Multiname::Multiname(
    &mn,
    (Scaleform::GFx::AS3::VMFile *)&this->CF->pFile->vfptr,
    &this->CF->pFile->File.pObject->Const_Pool.const_multiname.Data.Data[mn_index]);
  arg1 = 0i64;
  if ( (mn.Kind & 3) == 1 || ((unsigned int)mn.Kind >> 2) & 1 )
  {
    v17 = 0;
    goto LABEL_194;
  }
  result.pSI = 0i64;
  result.SlotIndex = 0i64;
  result.This.Flags = 0;
  result.This.Bonus.pWeakProxy = 0i64;
  Scaleform::GFx::AS3::TR::State::FindProp(v6, &result, &mn, &stype, &arg1);
  v8 = result.This.Flags;
  v9 = result.This.Flags & 0x1F;
  if ( !(result.This.Flags & 0x1F)
    || (v86 = result.pSI, (_QWORD)result.pSI & 1) && !((_QWORD)result.pSI & 0xFFFFFFFFFFFFFFFEui64)
    || (LOBYTE(result.pSI) >> 1) & 1 && !((_QWORD)result.pSI & 0xFFFFFFFFFFFFFFFDui64) )
  {
    if ( v5 )
    {
      *(_QWORD *)&v93.Result = (char *)&p + 16;
      Scaleform::GFx::AS3::Multiname::Multiname((Scaleform::GFx::AS3::Multiname *)&p.value, &mn);
      if ( Scaleform::GFx::AS3::Tracer::EmitGetClassTraits(v7, v6, v77, 0, 0) )
      {
        v17 = 1;
        goto LABEL_187;
      }
    }
    goto LABEL_186;
  }
  if ( (_QWORD)result.pSI & 1 )
    goto LABEL_186;
  v82.pNode = (Scaleform::GFx::ASStringNode *)result.SlotIndex;
  v10 = consumer != 97 && consumer != 104 && Scaleform::GFx::AS3::SlotInfo::IsClass(result.pSI);
  v11 = result.This.value.VNumber;
  if ( v9 )
  {
    v12 = v9 - 8;
    if ( v12 && v12 != 1 )
      v13 = COERCE_DOUBLE(Scaleform::GFx::AS3::VM::GetValueTraits(v7->CF->pFile->VMRef, &result.This));
    else
      v13 = result.This.value.VNumber;
  }
  else
  {
    v13 = *(double *)&v7->CF->pFile->VMRef->TraitsVoid.pObject;
  }
  if ( v13 != 0.0 )
  {
    v14 = v7->CF->pFile->VMRef;
    if ( *(Scaleform::GFx::AS3::ClassTraits::ClassClass **)&v13 == v14->TraitsClassClass.pObject )
      v13 = *(double *)&v14->TraitsObject.pObject;
  }
  v15 = stype;
  if ( (signed int)stype < 0 )
  {
LABEL_186:
    v17 = 0;
    goto LABEL_187;
  }
  if ( (signed int)stype > 1 )
  {
    if ( stype != 2 )
      goto LABEL_186;
    if ( v10 )
    {
      arg1 = (unsigned __int64)&v92.value;
      Scaleform::GFx::AS3::Multiname::Multiname((Scaleform::GFx::AS3::Multiname *)&v92.value, &mn);
      if ( Scaleform::GFx::AS3::Tracer::EmitGetClassTraits(v7, v6, v16, 0, v10) )
      {
        v17 = 1;
        goto LABEL_187;
      }
      v11 = result.This.value.VNumber;
      v8 = result.This.Flags;
    }
    if ( !v95 )
    {
      v17 = Scaleform::GFx::AS3::Tracer::EmitGetSlot(v7, v6, &result.This, (const unsigned __int64)v82.pNode, 0);
      if ( v17 )
        Scaleform::GFx::AS3::TR::State::PushOp(v6, &result.This);
      goto LABEL_187;
    }
    v18 = v86;
    if ( (signed int)((*(_DWORD *)v86 & 0xFFFFFC00) << 17) > 1342177280 )
      goto LABEL_186;
    v19 = (v8 & 0x1F) - 12;
    v20 = (int)v82.pNode;
    if ( v19 <= 3
      && *(Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP **)&v11 == v7->CF->pFile->VMRef->GlobalObject.pObject )
    {
      Scaleform::GFx::AS3::Slots::GetSlotName(
        (Scaleform::GFx::AS3::Slots *)(*(_QWORD *)&v13 + 40i64),
        &v82,
        (Scaleform::GFx::AS3::AbsoluteIndex)v82.pNode);
      v21 = v82.pNode->pData;
      v22 = 4;
      v23 = 1;
      if ( !strcmp(v82.pNode->pData, "undefined") )
      {
        v24 = 1;
LABEL_40:
        v27 = 40;
        if ( v24 == 1 )
          v27 = 33;
        Scaleform::GFx::AS3::Tracer::PushNewOpCode(v7, v27);
        if ( v24 != 1 )
        {
          v35 = Scaleform::GFx::NumberUtil::NaN();
          v.Flags = 4;
          v34 = 0i64;
          v.Bonus.pWeakProxy = 0i64;
          v.value.VNumber = v35;
          v33 = &v;
          v23 = 2;
          v83 = 2;
          v30 = type.Bonus.pWeakProxy;
          v29 = type.Flags;
LABEL_57:
          Scaleform::GFx::AS3::TR::State::PushOp(v6, v33);
          if ( v23 & 2 )
          {
            v23 &= 0xFFFFFFFD;
            v83 = v23;
            if ( (char)(v22 & 0x1F) > 9 )
            {
              if ( (v22 >> 9) & 1 )
              {
                v36 = v34->RefCount-- == 1;
                if ( v36 )
                  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v34);
                v.Bonus.pWeakProxy = 0i64;
                v.value = 0ui64;
                v.Flags = v22 & 0xFFFFFDE0;
              }
              else
              {
                Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
              }
            }
          }
          if ( v23 & 1 )
          {
            v83 = v23 & 0xFFFFFFFE;
            if ( (char)(v29 & 0x1F) > 9 )
            {
              if ( (v29 >> 9) & 1 )
              {
                v36 = v30->RefCount-- == 1;
                if ( v36 )
                  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v30);
                type.Bonus.pWeakProxy = 0i64;
                type.value = 0ui64;
                type.Flags = v29 & 0xFFFFFDE0;
              }
              else
              {
                Scaleform::GFx::AS3::Value::ReleaseInternal(&type);
              }
            }
          }
          v37 = v82.pNode;
          v36 = v82.pNode->RefCount == 1;
          --v37->RefCount;
          if ( v36 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v37);
          goto LABEL_73;
        }
        v28 = Scaleform::GFx::AS3::Value::GetUndefined();
        v29 = v28->Flags;
        type.Flags = v29;
        v30 = v28->Bonus.pWeakProxy;
        type.Bonus.pWeakProxy = v28->Bonus.pWeakProxy;
        type.value = v28->value;
        v31 = v29 & 0x1F;
        if ( v31 > 9 )
        {
          if ( (v29 >> 9) & 1 )
          {
            ++v30->RefCount;
          }
          else
          {
            if ( v31 == 10 )
            {
              ++*(_DWORD *)(*(_QWORD *)&v28->value.VNumber + 24i64);
              goto LABEL_55;
            }
            if ( v31 > 10 )
            {
              if ( v31 <= 15 )
              {
                v32 = v28->value.VNumber;
              }
              else
              {
                if ( v31 > 17 )
                  goto LABEL_55;
                v32 = *(double *)&v28->value.VS._2.VObj;
              }
              if ( v32 != 0.0 )
                *(_DWORD *)(*(_QWORD *)&v32 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v32 + 32i64) + 1) & 0x8FBFFFFF;
              goto LABEL_55;
            }
          }
        }
LABEL_55:
        v33 = &type;
        v83 = 1;
        v34 = v.Bonus.pWeakProxy;
        v22 = v.Flags;
        goto LABEL_57;
      }
      v25 = 0i64;
      while ( 1 )
      {
        v26 = v21[v25++];
        if ( v26 != aNan_1[v25 - 1] )
          break;
        if ( v25 == 4 )
        {
          v24 = 2;
          goto LABEL_40;
        }
      }
      v38 = v82.pNode;
      v36 = v82.pNode->RefCount == 1;
      --v38->RefCount;
      if ( v36 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v38);
      v18 = v86;
    }
    if ( !Scaleform::GFx::AS3::Tracer::EmitGetAbsObject(v7, v6, &result.This, 0) )
      goto LABEL_186;
    type.Flags = 0;
    type.Bonus.pWeakProxy = 0i64;
    if ( result.This.Flags & 0x1F )
    {
      if ( (result.This.Flags & 0x1F) == 8 || (result.This.Flags & 0x1F) == 9 )
        v39 = (Scaleform::GFx::AS3::Traits *)result.This.value.VS._1.VStr;
      else
        v39 = Scaleform::GFx::AS3::VM::GetValueTraits(v7->CF->pFile->VMRef, &result.This);
    }
    else
    {
      v39 = (Scaleform::GFx::AS3::Traits *)&v7->CF->pFile->VMRef->TraitsVoid.pObject->vfptr;
    }
    if ( v39 )
    {
      v40 = v7->CF->pFile->VMRef;
      if ( v39 == (Scaleform::GFx::AS3::Traits *)v40->TraitsClassClass.pObject )
        v39 = (Scaleform::GFx::AS3::Traits *)&v40->TraitsObject.pObject->vfptr;
    }
    if ( Scaleform::GFx::AS3::TR::State::GetPropertyType(
           v6,
           (Scaleform::GFx::AS3::CheckResult *)&stype,
           v39,
           v18,
           &type)->Result )
    {
      v36 = v10 == 0;
      v42 = type.Flags;
      if ( !v36 )
      {
        v42 = type.Flags | 0x400;
        type.Flags |= 0x400u;
      }
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v6->OpStack.Data.Data,
        v6->OpStack.Data.pHeap,
        v6->OpStack.Data.Size + 1);
      v43 = 32 * v6->OpStack.Data.Size;
      v44 = (signed __int64)&v6->OpStack.Data.Data[-1];
      v36 = v43 + v44 == 0;
      v45 = v43 + v44;
      arg1 = v45;
      v86 = (Scaleform::GFx::AS3::SlotInfo *)v45;
      v46 = type.Bonus.pWeakProxy;
      if ( !v36 )
      {
        *(_DWORD *)v45 = v42;
        *(_QWORD *)(v45 + 8) = v46;
        v47 = type.value.VNumber;
        *(long double *)(v45 + 16) = type.value.VNumber;
        v48.VObj = (Scaleform::GFx::AS3::Object *)type.value.VS._2;
        *(_QWORD *)(v45 + 24) = type.value.VS._2.VObj;
        v49 = v42 & 0x1F;
        if ( v49 > 9 )
        {
          if ( (v42 >> 9) & 1 )
          {
            ++v46->RefCount;
          }
          else if ( v49 == 10 )
          {
            ++*(_DWORD *)(*(_QWORD *)&v47 + 24i64);
          }
          else if ( v49 > 10 )
          {
            if ( v49 <= 15 )
            {
              if ( v47 != 0.0 )
                *(_DWORD *)(*(_QWORD *)&v47 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v47 + 32i64) + 1) & 0x8FBFFFFF;
            }
            else if ( v49 <= 17 && v48.VObj )
            {
              v48.VObj->RefCount = (v48.VObj->RefCount + 1) & 0x8FBFFFFF;
            }
          }
        }
      }
      if ( (char)(v42 & 0x1F) > 9 )
      {
        if ( (v42 >> 9) & 1 )
        {
          v36 = v46->RefCount-- == 1;
          if ( v36 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          type.Bonus.pWeakProxy = 0i64;
          type.value = 0ui64;
          type.Flags = v42 & 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&type);
        }
      }
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(v7, op_getabsslot, (unsigned int)(v20 + 1));
      v17 = 1;
      goto LABEL_187;
    }
    v41 = type.Flags;
    if ( (type.Flags & 0x1F) <= 9 )
      goto LABEL_186;
    if ( (type.Flags >> 9) & 1 )
    {
      v36 = type.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v36 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      type.Bonus.pWeakProxy = 0i64;
      type.value = 0ui64;
LABEL_185:
      type.Flags = v41 & 0xFFFFFDE0;
      goto LABEL_186;
    }
LABEL_93:
    Scaleform::GFx::AS3::Value::ReleaseInternal(&type);
    goto LABEL_186;
  }
  if ( v10 )
  {
    *(_QWORD *)&p.Flags = (char *)&p + 16;
    Scaleform::GFx::AS3::Multiname::Multiname((Scaleform::GFx::AS3::Multiname *)&p.value, &mn);
    if ( Scaleform::GFx::AS3::Tracer::EmitGetClassTraits(v7, v6, v50, 0, v10) )
    {
      v17 = 1;
      goto LABEL_187;
    }
  }
  if ( !Scaleform::GFx::AS3::Tracer::EmitGetAbsObject(v7, v6, &result.This, 0) )
  {
    v51 = v7;
    if ( v15 )
    {
      if ( Scaleform::GFx::AS3::Tracer::EmitGetAbsObject(v7, v6, &result.This, 0) )
        goto LABEL_127;
      v52 = 103;
      v51 = v7;
    }
    else
    {
      v52 = 101;
    }
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(v51, v52, arg1);
  }
LABEL_127:
  if ( !v95 )
  {
    if ( consumer != 74 )
    {
      Scaleform::GFx::AS3::TR::State::PushOp(v6, &result.This);
LABEL_73:
      v17 = 1;
      goto LABEL_187;
    }
    v10 = 1;
  }
  v53 = v86;
  v54 = *(_DWORD *)v86;
  v55 = *(_DWORD *)v86 << 17 >> 27;
  if ( v55 <= 10 || v54 >> 15 < 0 || (*(_BYTE *)(*(_QWORD *)&v13 + 112i64) >> 2) & 1 )
  {
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(v7, op_getabsslot, (unsigned int)(LODWORD(v82.pNode) + 1));
    type.Flags = 0;
    type.Bonus.pWeakProxy = 0i64;
    if ( !Scaleform::GFx::AS3::TR::State::GetPropertyType(v6, &v93, *(Scaleform::GFx::AS3::Traits **)&v13, v53, &type)->Result )
    {
      v41 = type.Flags;
      if ( (type.Flags & 0x1F) <= 9 )
        goto LABEL_186;
      if ( (type.Flags >> 9) & 1 )
      {
        v36 = type.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v36 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        type.Bonus.pWeakProxy = 0i64;
        type.value = 0ui64;
        goto LABEL_185;
      }
      goto LABEL_93;
    }
    v36 = v10 == 0;
    v69 = type.Flags;
    if ( !v36 )
    {
      v69 = type.Flags | 0x400;
      type.Flags |= 0x400u;
    }
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v6->OpStack.Data.Data,
      v6->OpStack.Data.pHeap,
      v6->OpStack.Data.Size + 1);
    v70 = 32 * v6->OpStack.Data.Size;
    v71 = (signed __int64)&v6->OpStack.Data.Data[-1];
    v36 = v70 + v71 == 0;
    v72 = v70 + v71;
    *(_QWORD *)&p.Flags = v72;
    arg1 = v72;
    v73 = type.Bonus.pWeakProxy;
    if ( !v36 )
    {
      *(_DWORD *)v72 = v69;
      *(_QWORD *)(v72 + 8) = v73;
      v74 = type.value.VNumber;
      *(long double *)(v72 + 16) = type.value.VNumber;
      v75.VObj = (Scaleform::GFx::AS3::Object *)type.value.VS._2;
      *(_QWORD *)(v72 + 24) = type.value.VS._2.VObj;
      v76 = v69 & 0x1F;
      if ( v76 > 9 )
      {
        if ( (v69 >> 9) & 1 )
        {
          ++v73->RefCount;
        }
        else if ( v76 == 10 )
        {
          ++*(_DWORD *)(*(_QWORD *)&v74 + 24i64);
        }
        else if ( v76 > 10 )
        {
          if ( v76 <= 15 )
          {
            if ( v74 != 0.0 )
              *(_DWORD *)(*(_QWORD *)&v74 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v74 + 32i64) + 1) & 0x8FBFFFFF;
          }
          else if ( v76 <= 17 && v75.VObj )
          {
            v75.VObj->RefCount = (v75.VObj->RefCount + 1) & 0x8FBFFFFF;
          }
        }
      }
    }
    if ( (char)(v69 & 0x1F) <= 9 )
      goto LABEL_73;
    if ( (v69 >> 9) & 1 )
    {
      v36 = v73->RefCount-- == 1;
      if ( v36 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      type.Bonus.pWeakProxy = 0i64;
      type.value = 0ui64;
      type.Flags = v69 & 0xFFFFFDE0;
      goto LABEL_73;
    }
    Scaleform::GFx::AS3::Value::ReleaseInternal(&type);
    v17 = 1;
  }
  else
  {
    if ( *(_DWORD *)v86 << 17 >> 27 == 11 )
    {
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(v7, op_getabsslot, (unsigned int)(LODWORD(v82.pNode) + 1));
      v56 = (signed __int64)*(_DWORD *)v53 >> 15;
      v57 = Scaleform::GFx::AS3::Traits::GetVT(*(Scaleform::GFx::AS3::Traits **)&v13);
      v58 = Scaleform::GFx::AS3::VTable::GetValue(v57, &v89, (Scaleform::GFx::AS3::AbsoluteIndex)v56);
      v59 = Scaleform::GFx::AS3::TR::State::GetFunctType(v6, v58);
      if ( (v89.Flags & 0x1F) > 9 )
      {
        if ( (v89.Flags >> 9) & 1 )
        {
          v36 = v89.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v36 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          v89.Bonus.pWeakProxy = 0i64;
          v89.value = 0ui64;
          v89.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v89);
        }
      }
      v60 = Scaleform::GFx::AS3::Tracer::CanBeNull(v7, v59);
      v.Bonus.pWeakProxy = 0i64;
      *(_QWORD *)&v.value.VNumber = v59;
      v61 = (32 * v60 | 8) & 0xFFFFFEFF;
      v.Flags = (32 * v60 | 8) & 0xFFFFFEFF;
      Scaleform::GFx::AS3::TR::State::PushOp(v6, &v);
    }
    else
    {
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(v7, op_callmethod, (signed int)v54 >> 15, 0i64);
      v62 = (signed __int64)*(_DWORD *)v53 >> 15;
      v63 = Scaleform::GFx::AS3::Traits::GetVT(*(Scaleform::GFx::AS3::Traits **)&v13);
      v64 = Scaleform::GFx::AS3::VTable::GetValue(v63, &v90, (Scaleform::GFx::AS3::AbsoluteIndex)v62);
      v65 = v7->CF->pFile->VMRef;
      v66 = Scaleform::GFx::AS3::Traits::GetAppDomain(*(Scaleform::GFx::AS3::Traits **)&v13);
      v67 = Scaleform::GFx::AS3::VM::GetFunctReturnType(v65, v64, v66);
      if ( (v90.Flags & 0x1F) > 9 )
      {
        if ( (v90.Flags >> 9) & 1 )
        {
          v36 = v90.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v36 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          v90.Bonus.pWeakProxy = 0i64;
          v90.value = 0ui64;
          v90.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v90);
        }
      }
      v68 = Scaleform::GFx::AS3::Tracer::CanBeNull(v7, v67);
      v.Bonus.pWeakProxy = 0i64;
      *(_QWORD *)&v.value.VNumber = v67;
      v61 = (32 * v68 | 8) & 0xFFFFFEFF;
      v.Flags = (32 * v68 | 8) & 0xFFFFFEFF;
      Scaleform::GFx::AS3::TR::State::PushOp(v6, &v);
    }
    if ( (char)(v61 & 0x1F) <= 9 )
      goto LABEL_73;
    if ( (v61 >> 9) & 1 )
    {
      LODWORD(MEMORY[0]) = MEMORY[0] - 1;
      if ( !(_DWORD)MEMORY[0] )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
      v.Flags = v61 & 0xFFFFFDE0;
      v.value = 0ui64;
      v.Bonus.pWeakProxy = 0i64;
      goto LABEL_73;
    }
    Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
    v17 = 1;
  }
LABEL_187:
  if ( (result.This.Flags & 0x1F) > 9 )
  {
    if ( (result.This.Flags >> 9) & 1 )
    {
      v36 = result.This.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v36 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      result.This.Bonus.pWeakProxy = 0i64;
      result.This.value = 0ui64;
      result.This.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&result.This);
    }
  }
LABEL_194:
  if ( (mn.Name.Flags & 0x1F) > 9 )
  {
    if ( (mn.Name.Flags >> 9) & 1 )
    {
      v36 = mn.Name.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v36 )
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
  v78 = mn.Obj.pObject;
  if ( mn.Obj.pObject )
  {
    if ( (_QWORD)mn.Obj.pObject & 1 )
    {
      --mn.Obj.pObject;
    }
    else
    {
      v79 = mn.Obj.pObject->RefCount;
      if ( v79 & 0x3FFFFF )
      {
        mn.Obj.pObject->RefCount = v79 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v78->vfptr);
      }
    }
  }
  return v17;
}

// File Line: 7668
// RVA: 0x7C89C0
char __fastcall Scaleform::GFx::AS3::Tracer::EmitGetSlot(Scaleform::GFx::AS3::Tracer *this, Scaleform::GFx::AS3::TR::State *st, Scaleform::GFx::AS3::Value *value, const unsigned __int64 index, bool objOnStack)
{
  Scaleform::GFx::AS3::Value *v5; // rdi
  Scaleform::GFx::AS3::Tracer *v6; // rbx
  unsigned int v7; // er10
  int v9; // er10
  int v10; // er10
  int v11; // er10
  int v12; // edx

  v5 = value;
  v6 = this;
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
        v11 = v10 - 8;
        if ( !v11 || v11 == 1 )
          return Scaleform::GFx::AS3::Tracer::EmitGetAbsObject(this, st, value, objOnStack);
        return 0;
      }
      if ( (*(_QWORD *)&value->value.VNumber & 0x7FF0000000000000i64) != 9218868437227405312i64
        || !(*(_QWORD *)&value->value.VNumber & 0xFFFFFFFFFFFFFi64) )
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
      v12 = 39 - (v5->value.VS._1.VBool != 0);
    }
  }
  else
  {
    if ( objOnStack )
      Scaleform::GFx::AS3::Tracer::EmitPopPrevResult(this, st);
    v12 = 33;
  }
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(v6, (Scaleform::GFx::AS3::Abc::Code::OpCode)v12);
  return 1;
}

// File Line: 7743
// RVA: 0x7C8120
char __fastcall Scaleform::GFx::AS3::Tracer::EmitGetProperty(Scaleform::GFx::AS3::Tracer *this, Scaleform::GFx::AS3::Abc::Code::OpCode opcode, Scaleform::GFx::AS3::TR::State *st, Scaleform::GFx::AS3::TR::ReadMnObject *args, const int mn_index)
{
  Scaleform::GFx::AS3::TR::State *v5; // r15
  Scaleform::GFx::AS3::Abc::Code::OpCode v6; // er13
  Scaleform::GFx::AS3::Tracer *v7; // r14
  Scaleform::GFx::AS3::Multiname *v8; // rdi
  Scaleform::GFx::AS3::Traits *v9; // rsi
  Scaleform::GFx::AS3::Abc::MultinameKind v10; // eax
  int v11; // er8
  Scaleform::GFx::AS3::CallFrame *v12; // r12
  Scaleform::GFx::AS3::VM *v13; // rbx
  Scaleform::GFx::AS3::Multiname *v14; // rax
  Scaleform::GFx::AS3::SlotInfo *v15; // rax
  Scaleform::GFx::AS3::SlotInfo *v16; // r12
  __int64 v17; // rax
  signed int v18; // edx
  signed __int64 v19; // rbx
  Scaleform::GFx::AS3::VTable *v20; // rax
  Scaleform::GFx::AS3::Value *v21; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v22; // rdi
  bool v23; // zf
  int v24; // eax
  unsigned int v25; // ebx
  Scaleform::GFx::AS3::Abc::Code::OpCode v26; // edx
  signed __int64 v27; // rbx
  Scaleform::GFx::AS3::VTable *v28; // rax
  Scaleform::GFx::AS3::Value *v29; // rdi
  Scaleform::GFx::AS3::VM *v30; // rbx
  Scaleform::GFx::AS3::VMAppDomain *v31; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v32; // rdi
  int v33; // eax
  Scaleform::GFx::AS3::Abc::MultinameKind v34; // ebx
  signed __int64 v36; // rcx
  signed __int64 v37; // r9
  unsigned __int64 v38; // r9
  Scaleform::GFx::AS3::GASRefCountBase *v39; // rdx
  Scaleform::GFx::AS3::Abc::MultinameKind v40; // ebx
  __int64 v41; // r8
  Scaleform::GFx::AS3::Value::Extra v42; // r10
  int v43; // ecx
  unsigned __int64 v44; // r8
  Scaleform::GFx::AS3::Abc::Code::OpCode v45; // edx
  Scaleform::GFx::AS3::SlotInfo *v46; // rax
  Scaleform::GFx::AS3::Abc::MultinameKind v47; // ebx
  signed __int64 v48; // rcx
  signed __int64 v49; // r9
  __int64 v50; // r9
  Scaleform::GFx::AS3::GASRefCountBase *v51; // rdx
  unsigned __int32 v52; // ebx
  __int64 v53; // r8
  Scaleform::GFx::AS3::Value::Extra v54; // r10
  int v55; // ecx
  Scaleform::GFx::AS3::BuiltinTraitsType v56; // edx
  void *v57; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v58; // rdi
  int v59; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v60; // rax
  unsigned __int64 v61; // [rsp+30h] [rbp-50h]
  __int64 v62; // [rsp+38h] [rbp-48h]
  unsigned __int64 v63; // [rsp+40h] [rbp-40h]
  __int64 v64; // [rsp+48h] [rbp-38h]
  Scaleform::GFx::AS3::Multiname v65; // [rsp+50h] [rbp-30h]
  Scaleform::GFx::AS3::CheckResult result; // [rsp+C8h] [rbp+48h]
  unsigned __int64 index; // [rsp+D8h] [rbp+58h]

  v62 = -2i64;
  v5 = st;
  v6 = opcode;
  v7 = this;
  v8 = &args->ArgMN;
  v9 = Scaleform::GFx::AS3::Tracer::GetValueTraits(this, &args->ArgObject, opcode == 4);
  v10 = v8->Kind;
  v11 = v8->Kind & 3;
  if ( v11 == 1 || ((unsigned int)v10 >> 2) & 1 || ((unsigned int)v10 >> 3) & 1 || !v11 && !v8->Obj.pObject )
    goto $fall_back;
  if ( !v9 )
    goto $fall_back;
  v12 = v7->CF;
  v13 = v12->pFile->VMRef;
  index = 0i64;
  if ( (v8->Name.Flags & 0x1F) - 8 <= 1 )
    goto $fall_back;
  if ( !((LOBYTE(v9->Flags) >> 2) & 1)
    && !Scaleform::GFx::AS3::Tracer::IsPrimitiveType(v7, v9)
    && v9 != (Scaleform::GFx::AS3::Traits *)v12->pFile->VMRef->TraitsNamespace.pObject->ITraits.pObject )
  {
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::Traits *))v9->vfptr[1].ForEachChild_GC)(v9) )
    {
      v61 = (unsigned __int64)&v65;
      Scaleform::GFx::AS3::Multiname::Multiname(&v65, v8);
      if ( Scaleform::GFx::AS3::Tracer::EmitGetClassTraits(v7, v5, v14, 1) )
        return 1;
    }
    v15 = Scaleform::GFx::AS3::FindFixedSlot(v13, v9, v8, &index, 0i64);
    v16 = v15;
    if ( v15 )
    {
      v17 = *(_DWORD *)v15;
      v18 = (_DWORD)v17 << 17 >> 27;
      if ( v18 <= 10 )
      {
        v65.Kind = 0;
        v65.Obj.pObject = 0i64;
        if ( !Scaleform::GFx::AS3::TR::State::GetPropertyType(v5, &result, v9, v16, (Scaleform::GFx::AS3::Value *)&v65)->Result )
        {
          v34 = v65.Kind;
          if ( (v65.Kind & 0x1F) <= 9 )
            return 0;
          if ( ((unsigned int)v65.Kind >> 9) & 1 )
          {
            v23 = v65.Obj.pObject->vfptr-- == (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)1;
            if ( v23 )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            v65.Obj.pObject = 0i64;
            *(_QWORD *)&v65.Name.Flags = 0i64;
            v65.Name.Bonus.pWeakProxy = 0i64;
            v65.Kind = v34 & 0xFFFFFDE0;
            return 0;
          }
LABEL_50:
          Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v65);
          return 0;
        }
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v5->OpStack.Data.Data,
          v5->OpStack.Data.pHeap,
          v5->OpStack.Data.Size + 1);
        v36 = 32 * v5->OpStack.Data.Size;
        v37 = (signed __int64)&v5->OpStack.Data.Data[-1];
        v23 = v36 + v37 == 0;
        v38 = v36 + v37;
        v61 = v38;
        v63 = v38;
        v39 = v65.Obj.pObject;
        v40 = v65.Kind;
        if ( !v23 )
        {
          *(_DWORD *)v38 = v65.Kind;
          *(_QWORD *)(v38 + 8) = v39;
          v41 = *(_QWORD *)&v65.Name.Flags;
          *(_QWORD *)(v38 + 16) = *(_QWORD *)&v65.Name.Flags;
          v42.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v65.Name.Bonus;
          *(_QWORD *)(v38 + 24) = v65.Name.Bonus.pWeakProxy;
          v43 = v40 & 0x1F;
          if ( v43 > 9 )
          {
            if ( ((unsigned int)v40 >> 9) & 1 )
            {
              ++LODWORD(v39->vfptr);
            }
            else if ( v43 == 10 )
            {
              ++*(_DWORD *)(v41 + 24);
            }
            else if ( v43 > 10 )
            {
              if ( v43 <= 15 )
              {
                if ( v41 )
                  *(_DWORD *)(v41 + 32) = (*(_DWORD *)(v41 + 32) + 1) & 0x8FBFFFFF;
              }
              else if ( v43 <= 17 && v42.pWeakProxy )
              {
                v42.pWeakProxy[2].RefCount = (v42.pWeakProxy[2].RefCount + 1) & 0x8FBFFFFF;
              }
            }
          }
        }
        if ( (v40 & 0x1F) > 9 )
        {
          if ( ((unsigned int)v40 >> 9) & 1 )
          {
            v23 = LODWORD(v39->vfptr)-- == 1;
            if ( v23 )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            v65.Obj.pObject = 0i64;
            *(_QWORD *)&v65.Name.Flags = 0i64;
            v65.Name.Bonus.pWeakProxy = 0i64;
            v65.Kind = v40 & 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v65);
          }
        }
        if ( ((unsigned int)v8->Kind >> 2) & 1 )
          Scaleform::GFx::AS3::Tracer::PushNewOpCode(v7, op_pop);
        v44 = (unsigned int)(index + 1);
        v45 = 182;
        goto LABEL_118;
      }
      if ( v17 >> 15 >= 0 )
      {
        if ( v18 != 11 )
        {
          if ( ((unsigned int)v8->Kind >> 2) & 1 )
            Scaleform::GFx::AS3::Tracer::PushNewOpCode(v7, op_pop);
          v26 = 67;
          if ( v6 == 4 )
            v26 = 185;
          Scaleform::GFx::AS3::Tracer::PushNewOpCode(v7, v26, (signed int)(*(_DWORD *)v16 >> 15), 0i64);
          v27 = (signed __int64)*(_DWORD *)v16 >> 15;
          v28 = Scaleform::GFx::AS3::Traits::GetVT(v9);
          v29 = Scaleform::GFx::AS3::VTable::GetValue(
                  v28,
                  (Scaleform::GFx::AS3::Value *)&v65,
                  (Scaleform::GFx::AS3::AbsoluteIndex)v27);
          v30 = v7->CF->pFile->VMRef;
          v31 = Scaleform::GFx::AS3::Traits::GetAppDomain(v9);
          v32 = Scaleform::GFx::AS3::VM::GetFunctReturnType(v30, v29, v31);
          if ( (v65.Kind & 0x1F) > 9 )
          {
            if ( ((unsigned int)v65.Kind >> 9) & 1 )
            {
              v23 = v65.Obj.pObject->vfptr-- == (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)1;
              if ( v23 )
                ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
              v65.Obj.pObject = 0i64;
              *(_QWORD *)&v65.Name.Flags = 0i64;
              v65.Name.Bonus.pWeakProxy = 0i64;
              v65.Kind &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v65);
            }
          }
          v33 = Scaleform::GFx::AS3::Tracer::CanBeNull(v7, v32);
          v65.Obj.pObject = 0i64;
          *(_QWORD *)&v65.Name.Flags = v32;
          v25 = (32 * v33 | 8) & 0xFFFFFEFF;
          v65.Kind = (32 * v33 | 8) & 0xFFFFFEFF;
          Scaleform::GFx::AS3::TR::State::PushOp(v5, (Scaleform::GFx::AS3::Value *)&v65);
          goto LABEL_27;
        }
        if ( v6 == 102 )
        {
          if ( ((unsigned int)v8->Kind >> 2) & 1 )
            Scaleform::GFx::AS3::Tracer::PushNewOpCode(v7, op_pop);
          Scaleform::GFx::AS3::Tracer::PushNewOpCode(v7, op_getabsslot, (unsigned int)(index + 1));
          v19 = (signed __int64)*(_DWORD *)v16 >> 15;
          v20 = Scaleform::GFx::AS3::Traits::GetVT(v9);
          v21 = Scaleform::GFx::AS3::VTable::GetValue(
                  v20,
                  (Scaleform::GFx::AS3::Value *)&v65,
                  (Scaleform::GFx::AS3::AbsoluteIndex)v19);
          v22 = Scaleform::GFx::AS3::TR::State::GetFunctType(v5, v21);
          if ( (v65.Kind & 0x1F) > 9 )
          {
            if ( ((unsigned int)v65.Kind >> 9) & 1 )
            {
              v23 = v65.Obj.pObject->vfptr-- == (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)1;
              if ( v23 )
                ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
              v65.Obj.pObject = 0i64;
              *(_QWORD *)&v65.Name.Flags = 0i64;
              v65.Name.Bonus.pWeakProxy = 0i64;
              v65.Kind &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v65);
            }
          }
          v24 = Scaleform::GFx::AS3::Tracer::CanBeNull(v7, v22);
          v65.Obj.pObject = 0i64;
          *(_QWORD *)&v65.Name.Flags = v22;
          v25 = (32 * v24 | 8) & 0xFFFFFEFF;
          v65.Kind = (32 * v24 | 8) & 0xFFFFFEFF;
          Scaleform::GFx::AS3::TR::State::PushOp(v5, (Scaleform::GFx::AS3::Value *)&v65);
LABEL_27:
          if ( (char)(v25 & 0x1F) > 9 )
          {
            if ( (v25 >> 9) & 1 )
            {
              LODWORD(MEMORY[0]) = MEMORY[0] - 1;
              if ( !(_DWORD)MEMORY[0] )
                Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
              v65.Obj.pObject = 0i64;
              *(_QWORD *)&v65.Name.Flags = 0i64;
              v65.Name.Bonus.pWeakProxy = 0i64;
              v65.Kind = v25 & 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v65);
            }
          }
          return 1;
        }
      }
    }
  }
  v61 = 0i64;
  v46 = Scaleform::GFx::AS3::FindFixedSlot(v7->CF->pFile->VMRef, v9, v8, &v61, 0i64);
  if ( !v46 )
  {
    v56 = v9->TraitsType;
    if ( ~(LOBYTE(v9->Flags) >> 5) & 1 )
    {
      switch ( v56 )
      {
        case 12:
          v57 = v13->TraitsInt.pObject;
          break;
        case 13:
          v57 = v13->TraitsUint.pObject;
          break;
        case 14:
          v57 = v13->TraitsNumber.pObject;
          break;
        case 15:
          v57 = v13->TraitsString.pObject;
          break;
        default:
          goto LABEL_110;
      }
      v58 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)*((_QWORD *)v57 + 25);
      if ( v58 )
        goto LABEL_112;
    }
LABEL_110:
    if ( v56 == 16 )
    {
      v58 = *(Scaleform::GFx::AS3::InstanceTraits::Traits **)(Scaleform::GFx::AS3::Traits::GetConstructor(v9)->pTraits.pObject[1].pRCCRaw
                                                            + 200);
      if ( v58 )
      {
LABEL_112:
        v59 = Scaleform::GFx::AS3::Tracer::CanBeNull(v7, v58);
        v65.Obj.pObject = 0i64;
        *(_QWORD *)&v65.Name.Flags = v58;
        v52 = (32 * v59 | 8) & 0xFFFFFEFF;
        v65.Kind = (32 * v59 | 8) & 0xFFFFFEFF;
        Scaleform::GFx::AS3::TR::State::PushOp(v5, (Scaleform::GFx::AS3::Value *)&v65);
        if ( (char)(v52 & 0x1F) <= 9 )
          goto LABEL_117;
        if ( (v52 >> 9) & 1 )
        {
          LODWORD(MEMORY[0]) = MEMORY[0] - 1;
          if ( (_DWORD)MEMORY[0] )
            goto LABEL_98;
          goto LABEL_97;
        }
LABEL_99:
        Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v65);
        goto LABEL_117;
      }
    }
$fall_back:
    v60 = v7->CF->pFile->VMRef->TraitsObject.pObject->ITraits.pObject;
    v65.Obj.pObject = 0i64;
    *(_QWORD *)&v65.Name.Flags = v60;
    v65.Kind = 72;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v5->OpStack.Data.Data,
      v5->OpStack.Data.pHeap,
      v5->OpStack.Data.Size + 1);
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
      &v5->OpStack.Data.Data[v5->OpStack.Data.Size - 1],
      (Scaleform::GFx::AS3::Value *)&v65);
    goto LABEL_117;
  }
  v65.Kind = 0;
  v65.Obj.pObject = 0i64;
  if ( !Scaleform::GFx::AS3::TR::State::GetPropertyType(v5, &result, v9, v46, (Scaleform::GFx::AS3::Value *)&v65)->Result )
  {
    v47 = v65.Kind;
    if ( (v65.Kind & 0x1F) <= 9 )
      return 0;
    if ( ((unsigned int)v65.Kind >> 9) & 1 )
    {
      v23 = v65.Obj.pObject->vfptr-- == (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)1;
      if ( v23 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v65.Obj.pObject = 0i64;
      *(_QWORD *)&v65.Name.Flags = 0i64;
      v65.Name.Bonus.pWeakProxy = 0i64;
      v65.Kind = v47 & 0xFFFFFDE0;
      return 0;
    }
    goto LABEL_50;
  }
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v5->OpStack.Data.Data,
    v5->OpStack.Data.pHeap,
    v5->OpStack.Data.Size + 1);
  v48 = 32 * v5->OpStack.Data.Size;
  v49 = (signed __int64)&v5->OpStack.Data.Data[-1];
  v23 = v48 + v49 == 0;
  v50 = v48 + v49;
  v63 = v50;
  v64 = v50;
  v51 = v65.Obj.pObject;
  v52 = v65.Kind;
  if ( !v23 )
  {
    *(_DWORD *)v50 = v65.Kind;
    *(_QWORD *)(v50 + 8) = v51;
    v53 = *(_QWORD *)&v65.Name.Flags;
    *(_QWORD *)(v50 + 16) = *(_QWORD *)&v65.Name.Flags;
    v54.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v65.Name.Bonus;
    *(_QWORD *)(v50 + 24) = v65.Name.Bonus.pWeakProxy;
    v55 = v52 & 0x1F;
    if ( v55 > 9 )
    {
      if ( (v52 >> 9) & 1 )
      {
        ++LODWORD(v51->vfptr);
      }
      else if ( v55 == 10 )
      {
        ++*(_DWORD *)(v53 + 24);
      }
      else if ( v55 > 10 )
      {
        if ( v55 <= 15 )
        {
          if ( v53 )
            *(_DWORD *)(v53 + 32) = (*(_DWORD *)(v53 + 32) + 1) & 0x8FBFFFFF;
        }
        else if ( v55 <= 17 && v54.pWeakProxy )
        {
          v54.pWeakProxy[2].RefCount = (v54.pWeakProxy[2].RefCount + 1) & 0x8FBFFFFF;
        }
      }
    }
  }
  if ( (char)(v52 & 0x1F) <= 9 )
    goto LABEL_117;
  if ( !((v52 >> 9) & 1) )
    goto LABEL_99;
  v23 = LODWORD(v51->vfptr)-- == 1;
  if ( v23 )
LABEL_97:
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
LABEL_98:
  v65.Obj.pObject = 0i64;
  *(_QWORD *)&v65.Name.Flags = 0i64;
  v65.Name.Bonus.pWeakProxy = 0i64;
  v65.Kind = v52 & 0xFFFFFDE0;
LABEL_117:
  v44 = mn_index;
  v45 = v6;
LABEL_118:
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(v7, v45, v44);
  return 1;
}

// File Line: 8051
// RVA: 0x7C8C40
char __fastcall Scaleform::GFx::AS3::Tracer::EmitSetProperty(Scaleform::GFx::AS3::Tracer *this, Scaleform::GFx::AS3::Abc::Code::OpCode opcode, Scaleform::GFx::AS3::TR::ReadValueMnObject *args, const int mn_index)
{
  Scaleform::GFx::AS3::Abc::Code::OpCode v4; // ebp
  bool v5; // r12
  Scaleform::GFx::AS3::Multiname *v6; // rdi
  unsigned __int64 v7; // r15
  Scaleform::GFx::AS3::Tracer *v8; // rbx
  Scaleform::GFx::AS3::Traits *v9; // rax
  Scaleform::GFx::AS3::Abc::MultinameKind v10; // er8
  Scaleform::GFx::AS3::Traits *v11; // rsi
  int v12; // er10
  Scaleform::GFx::AS3::VM *v13; // rcx
  Scaleform::GFx::AS3::SlotInfo *v14; // rax
  Scaleform::GFx::AS3::SlotInfo *v15; // r14
  signed int v16; // ecx
  Scaleform::GFx::AS3::Abc::Code::OpCode v17; // edx
  Scaleform::GFx::AS3::Tracer *v18; // rcx
  unsigned __int64 v19; // r8
  Scaleform::GFx::AS3::Abc::Code::OpCode v20; // edx
  unsigned __int64 index; // [rsp+70h] [rbp+18h]

  v4 = opcode;
  v5 = opcode == 5;
  v6 = &args->ArgMN;
  v7 = mn_index;
  v8 = this;
  v9 = Scaleform::GFx::AS3::Tracer::GetValueTraits(this, &args->ArgObject, opcode == 5);
  v10 = v6->Kind;
  v11 = v9;
  v12 = v6->Kind & 3;
  if ( v12 == 1 || ((unsigned int)v10 >> 2) & 1 || ((unsigned int)v10 >> 3) & 1 || !v12 && !v6->Obj.pObject )
    goto LABEL_27;
  if ( !v9 )
    goto LABEL_27;
  v13 = v8->CF->pFile->VMRef;
  index = 0i64;
  v14 = Scaleform::GFx::AS3::FindFixedSlot(v13, v9, v6, &index, 0i64);
  v15 = v14;
  if ( !v14 )
    goto LABEL_27;
  v16 = *(_DWORD *)v14 << 17 >> 27;
  if ( v16 <= 10 )
  {
    if ( ((unsigned int)v6->Kind >> 2) & 1 )
    {
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(v8, op_swap);
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(v8, op_pop);
    }
    v18 = v8;
    v19 = (unsigned int)(index + 1);
    if ( v4 == 104 )
      v20 = 184;
    else
      v20 = 183;
    goto LABEL_23;
  }
  if ( (*(_DWORD *)v14 & 0xFFFF8000 & 0x80000000) != 0 || (LOBYTE(v11->Flags) >> 2) & 1 || v16 <= 12 )
  {
LABEL_27:
    v19 = v7;
    v20 = v4;
    v18 = v8;
LABEL_23:
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(v18, v20, v19);
    return 1;
  }
  if ( ((unsigned int)v6->Kind >> 2) & 1 )
  {
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(v8, op_swap);
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(v8, op_pop);
  }
  v17 = 67;
  if ( v5 )
    v17 = 185;
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(v8, v17, (*(_DWORD *)v15 >> 15) + 1, 1ui64);
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(v8, op_pop);
  return 1;
}

// File Line: 8246
// RVA: 0x7C6670
char __fastcall Scaleform::GFx::AS3::Tracer::EmitCall(Scaleform::GFx::AS3::Tracer *this, Scaleform::GFx::AS3::Abc::Code::OpCode opcode, Scaleform::GFx::AS3::TR::State *st, Scaleform::GFx::AS3::TR::ReadArgsMnObject *args, const unsigned int mn_index)
{
  Scaleform::GFx::AS3::TR::ReadArgsMnObject *v5; // rbx
  Scaleform::GFx::AS3::TR::State *v6; // r13
  Scaleform::GFx::AS3::Abc::Code::OpCode v7; // edi
  Scaleform::GFx::AS3::Tracer *v8; // rsi
  bool v9; // r8
  Scaleform::GFx::AS3::Traits *v10; // r14
  Scaleform::GFx::AS3::Multiname *v11; // r12
  unsigned __int64 v12; // r15
  Scaleform::GFx::AS3::Abc::MultinameKind v13; // edx
  int v14; // er8
  Scaleform::GFx::AS3::SlotInfo *v15; // rax
  __int64 v16; // rax
  Scaleform::GFx::AS3::AbsoluteIndex v17; // rbx
  int v18; // eax
  Scaleform::GFx::AS3::VTable *v19; // rax
  Scaleform::GFx::AS3::Value *v20; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v21; // rbx
  bool v22; // zf
  int v23; // ecx
  int v24; // eax
  Scaleform::GFx::AS3::Abc::Code::OpCode v25; // edx
  Scaleform::GFx::AS3::Tracer *v26; // rcx
  int v27; // ebx
  unsigned int v28; // ebx
  Scaleform::GFx::AS3::Abc::Code::OpCode v29; // edx
  int v30; // ebx
  Scaleform::GFx::AS3::ClassTraits::Traits *v31; // rbx
  long double v32; // rax
  long double v33; // rax
  long double v34; // rax
  long double v36; // [rsp+30h] [rbp-40h]
  unsigned __int64 index; // [rsp+38h] [rbp-38h]
  Scaleform::GFx::AS3::SlotInfo *v38; // [rsp+40h] [rbp-30h]
  __int64 v39; // [rsp+48h] [rbp-28h]
  Scaleform::GFx::AS3::Value result; // [rsp+50h] [rbp-20h]
  Scaleform::GFx::AS3::VM *vm; // [rsp+B8h] [rbp+48h]

  v39 = -2i64;
  v5 = args;
  v6 = st;
  v7 = opcode;
  v8 = this;
  v9 = opcode == 69 || opcode == 78;
  v10 = Scaleform::GFx::AS3::Tracer::GetValueTraits(this, &args->ArgObject, v9);
  v11 = &v5->ArgMN;
  v12 = v5->ArgNum;
  v13 = v5->ArgMN.Kind;
  v14 = v5->ArgMN.Kind & 3;
  if ( v14 == 1 || ((unsigned int)v13 >> 2) & 1 || ((unsigned int)v13 >> 3) & 1 || !v14 && !v5->ArgMN.Obj.pObject )
    goto LABEL_53;
  index = 0i64;
  vm = v8->CF->pFile->VMRef;
  if ( v10 )
  {
    if ( !((LOBYTE(v10->Flags) >> 2) & 1) )
    {
      v15 = Scaleform::GFx::AS3::FindFixedSlot(vm, v10, v11, &index, 0i64);
      v38 = v15;
      if ( v15 )
      {
        v16 = *(_DWORD *)v15;
        v17.Index = v16 >> 15;
        if ( v16 >> 15 >= 0 )
        {
          v18 = (_DWORD)v16 << 17 >> 27;
          if ( v18 == 11 || !((v18 - 12) & 0xFFFFFFFD) )
          {
            v19 = Scaleform::GFx::AS3::Traits::GetVT(v10);
            v20 = Scaleform::GFx::AS3::VTable::GetValue(v19, &result, v17);
            v21 = Scaleform::GFx::AS3::VM::GetFunctReturnType(vm, v20, v8->CF->pFile->AppDomain.pObject);
            v36 = *(double *)&v21;
            if ( (result.Flags & 0x1F) > 9 )
            {
              if ( (result.Flags >> 9) & 1 )
              {
                v22 = result.Bonus.pWeakProxy->RefCount-- == 1;
                if ( v22 )
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
            v23 = *(_DWORD *)v38;
            v24 = *(_DWORD *)v38 << 17 >> 27;
            if ( v24 == 11 )
            {
              if ( v7 == 69 || (v25 = 67, v7 == 78) )
                v25 = 185;
              Scaleform::GFx::AS3::Tracer::PushNewOpCode(v8, v25, v23 >> 15, v12);
              v26 = v8;
              if ( (unsigned int)(v7 - 78) > 1 )
              {
                v27 = Scaleform::GFx::AS3::Tracer::CanBeNull(v8, v21);
                result.Bonus.pWeakProxy = 0i64;
                result.value.VNumber = v36;
                v28 = (32 * v27 | 8) & 0xFFFFFEFF;
                result.Flags = v28;
                Scaleform::GFx::AS3::TR::State::PushOp(v6, &result);
                goto LABEL_28;
              }
              goto LABEL_34;
            }
            if ( !((v24 - 12) & 0xFFFFFFFD) )
            {
              if ( v7 == 69 || (v29 = 186, v7 == 78) )
                v29 = 187;
              Scaleform::GFx::AS3::Tracer::PushNewOpCode(v8, v29, v23 >> 15, v12);
              v26 = v8;
              if ( (unsigned int)(v7 - 78) > 1 )
              {
                v30 = Scaleform::GFx::AS3::Tracer::CanBeNull(v8, v21);
                result.Bonus.pWeakProxy = 0i64;
                result.value.VNumber = v36;
                v28 = (32 * v30 | 8) & 0xFFFFFEFF;
                result.Flags = v28;
                Scaleform::GFx::AS3::TR::State::PushOp(v6, &result);
LABEL_28:
                if ( (char)(v28 & 0x1F) > 9 )
                {
                  if ( (v28 >> 9) & 1 )
                  {
                    LODWORD(MEMORY[0]) = MEMORY[0] - 1;
                    if ( !(_DWORD)MEMORY[0] )
                      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
                    result.Bonus.pWeakProxy = 0i64;
                    result.value = 0ui64;
                    result.Flags = v28 & 0xFFFFFDE0;
                  }
                  else
                  {
                    Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
                  }
                }
                return 1;
              }
LABEL_34:
              Scaleform::GFx::AS3::Tracer::PushNewOpCode(v26, op_pop);
              return 1;
            }
          }
        }
      }
    }
  }
  v31 = Scaleform::GFx::AS3::FindClassTraits(vm, v11, v8->CF->pFile->AppDomain.pObject);
  if ( v31 )
  {
    if ( (LOBYTE(v10->Flags) >> 5) & 1 )
    {
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(v8, op_callobject, v12);
      if ( (unsigned int)(v7 - 78) <= 1 )
      {
        Scaleform::GFx::AS3::Tracer::PushNewOpCode(v8, op_pop);
      }
      else
      {
        v32 = *(double *)&v31->ITraits.pObject;
        result.Bonus.pWeakProxy = 0i64;
        result.value.VNumber = v32;
        result.Flags = 8;
        Scaleform::GFx::AS3::TR::State::PushOp(v6, &result);
      }
    }
    else
    {
      Scaleform::GFx::AS3::Tracer::PushNewOpCode(v8, v7, mn_index, v12);
      if ( (unsigned int)(v7 - 78) > 1 )
      {
        v33 = *(double *)&v31->ITraits.pObject;
        result.Bonus.pWeakProxy = 0i64;
        result.value.VNumber = v33;
        result.Flags = 8;
        Scaleform::GFx::AS3::TR::State::PushOp(v6, &result);
      }
    }
  }
  else
  {
LABEL_53:
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(v8, v7, mn_index, v12);
    if ( (unsigned int)(v7 - 78) > 1 )
    {
      v34 = *(double *)&v8->CF->pFile->VMRef->TraitsObject.pObject->ITraits.pObject;
      result.Bonus.pWeakProxy = 0i64;
      result.value.VNumber = v34;
      result.Flags = 72;
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v6->OpStack.Data.Data,
        v6->OpStack.Data.pHeap,
        v6->OpStack.Data.Size + 1);
      Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
        &v6->OpStack.Data.Data[v6->OpStack.Data.Size - 1],
        &result);
    }
  }
  return 1;
}

// File Line: 8817
// RVA: 0x7C7CC0
char __fastcall Scaleform::GFx::AS3::Tracer::EmitGetAbsObject(Scaleform::GFx::AS3::Tracer *this, Scaleform::GFx::AS3::TR::State *st, Scaleform::GFx::AS3::Value *value, bool objOnStack)
{
  Scaleform::GFx::AS3::Tracer *v4; // rbx
  Scaleform::GFx::AS3::TR::State *v5; // rdi
  bool v6; // bp
  Scaleform::GFx::AS3::Value *v7; // rsi
  Scaleform::GFx::AS3::Traits *v8; // rax
  char result; // al

  v4 = this;
  v5 = st;
  v6 = objOnStack;
  v7 = value;
  v8 = Scaleform::GFx::AS3::VM::GetValueTraits(this->CF->pFile->VMRef, value);
  if ( (v7->Flags & 0x1F) == 13
    || (result = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Traits *))v8->vfptr[1].ForEachChild_GC)(v8)) != 0 )
  {
    if ( v6 )
      Scaleform::GFx::AS3::Tracer::EmitPopPrevResult(v4, v5);
    Scaleform::GFx::AS3::Tracer::EmitGetAbsObject2(v4, v5, v7);
    result = 1;
  }
  return result;
}

// File Line: 8842
// RVA: 0x7C7C20
void __fastcall Scaleform::GFx::AS3::Tracer::EmitGetAbsObject2(Scaleform::GFx::AS3::Tracer *this, Scaleform::GFx::AS3::TR::State *st, Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::Tracer *v4; // rdi
  signed int v5; // eax
  Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase> >,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase> >,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase> > > > *v6; // rcx
  Scaleform::GFx::AS3::Object *key; // [rsp+30h] [rbp+8h]

  v3 = value;
  v4 = this;
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
  Scaleform::GFx::AS3::Tracer::PushNewOpCode(this, op_getabsobject, *(_QWORD *)&value->value.VNumber + v5);
  v6 = (Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase> >,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase> >,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase> > > > *)v4->CF->pFile;
  if ( *(_QWORD *)&v3->value.VNumber != v6[5].pTable[41].EntryCount )
  {
    key = v3->value.VS._1.VObj;
    Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>>>>::Set<Scaleform::GFx::AS3::Object *>(
      v6 + 20,
      &v6[20],
      &key);
  }
}

// File Line: 8881
// RVA: 0x805C20
void __fastcall Scaleform::GFx::AS3::Tracer::Output(Scaleform::GFx::AS3::Tracer *this, __int64 type, const char *msg)
{
  Scaleform::GFx::AS3::FlashUI *v3; // rcx

  v3 = this->CF->pFile->VMRef->UI;
  v3->vfptr->Output(v3, (Scaleform::GFx::AS3::FlashUI::OutputMessageType)type, msg);
}

// File Line: 8914
// RVA: 0x7AB340
Scaleform::GFx::AS3::TR::Block *__fastcall Scaleform::GFx::AS3::Tracer::AddBlock(Scaleform::GFx::AS3::Tracer *this, Scaleform::GFx::AS3::TR::State *st, unsigned __int64 from, Scaleform::GFx::AS3::TR::Block::EType type, bool checkOpCode)
{
  Scaleform::GFx::AS3::TR::Block::EType v5; // esi
  unsigned __int64 v6; // rdi
  Scaleform::GFx::AS3::TR::State *v7; // r14
  Scaleform::GFx::AS3::Tracer *v8; // rbp
  Scaleform::GFx::AS3::TR::Block *i; // rbx
  char v11; // r13
  int v12; // eax
  Scaleform::GFx::AS3::TR::State *v13; // rax
  Scaleform::GFx::AS3::TR::State *v14; // rax
  Scaleform::GFx::AS3::TR::State *v15; // r12
  unsigned __int64 v16; // rax
  unsigned __int64 v17; // r15
  unsigned __int64 v18; // r8
  Scaleform::GFx::AS3::TR::State **v19; // rcx
  __int64 v20; // rdx
  __int64 v21; // rax
  Scaleform::GFx::AS3::TR::Block *v22; // rcx
  bool v23; // [rsp+70h] [rbp+8h]

  v5 = type;
  v6 = from;
  v7 = st;
  v8 = this;
  if ( from >= this->CodeEnd )
    return 0i64;
  v23 = type == 1;
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
  v13 = (Scaleform::GFx::AS3::TR::State *)this->Heap->vfptr->Alloc((Scaleform::MemoryHeap *)this, 136ui64, 0i64);
  if ( v13 )
  {
    Scaleform::GFx::AS3::TR::State::State(v13, v7);
    v15 = v14;
  }
  else
  {
    v15 = 0i64;
  }
  v16 = v8->States.Data.Size;
  v17 = v16 + 1;
  if ( v16 + 1 >= v16 )
  {
    if ( v17 > v8->States.Data.Policy.Capacity )
    {
      v18 = v17 + (v17 >> 2);
      goto LABEL_23;
    }
  }
  else if ( v17 < v8->States.Data.Policy.Capacity >> 1 )
  {
    v18 = v16 + 1;
LABEL_23:
    Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy> *)&v8->States,
      v8->States.Data.pHeap,
      v18);
    goto LABEL_24;
  }
LABEL_24:
  v8->States.Data.Size = v17;
  v19 = &v8->States.Data.Data[v17 - 1];
  if ( v19 )
    *v19 = v15;
  if ( v5 == 1 && !v23 )
    v5 = 0;
  if ( v11 )
  {
    v20 = (__int64)i;
    i->State = v15;
    i->Type |= v5;
  }
  else
  {
    v21 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::TR::State **, signed __int64))v8->Heap->vfptr->Alloc)(
            v19,
            48i64);
    v20 = v21;
    if ( v21 )
    {
      *(_DWORD *)(v21 + 16) |= 1u;
      *(_DWORD *)(v21 + 20) = v5;
      *(_QWORD *)(v21 + 24) = v15;
      *(_QWORD *)(v21 + 32) = v6;
      *(_QWORD *)(v21 + 40) = 0i64;
    }
    else
    {
      v20 = 0i64;
    }
    *(_QWORD *)v20 = i->pNext->pPrev;
    *(_QWORD *)(v20 + 8) = i->pNext;
    i->pNext->pPrev = (Scaleform::GFx::AS3::TR::Block *)v20;
    i->pNext = (Scaleform::GFx::AS3::TR::Block *)v20;
    if ( v5 == 1 )
      *(_DWORD *)(v20 + 16) &= 0xFFFFFFFE;
    v22 = v8->CurrBlock;
    if ( v22 )
      *(_QWORD *)(v20 + 40) = v22->CurOpStackSize;
  }
  return (Scaleform::GFx::AS3::TR::Block *)v20;
}

// File Line: 9016
// RVA: 0x7F0F70
Scaleform::GFx::AS3::InstanceTraits::Traits *__fastcall Scaleform::GFx::AS3::Tracer::GetValueTraits(Scaleform::GFx::AS3::Tracer *this, Scaleform::GFx::AS3::Value *v, const bool super_tr)
{
  bool v3; // di
  Scaleform::GFx::AS3::Tracer *v4; // rbx
  Scaleform::GFx::AS3::InstanceTraits::Traits *v5; // r9
  Scaleform::GFx::AS3::VM *v6; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *result; // rax

  v3 = super_tr;
  v4 = this;
  if ( !super_tr || (v5 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)this->CF->OriginationTraits) == 0i64 )
  {
    if ( v->Flags & 0x1F )
      v5 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)((v->Flags & 0x1F) == 8 || (v->Flags & 0x1F) == 9 ? *(_QWORD *)&v->value.VNumber : Scaleform::GFx::AS3::VM::GetValueTraits(this->CF->pFile->VMRef, v));
    else
      v5 = this->CF->pFile->VMRef->TraitsVoid.pObject;
    if ( v5 )
    {
      v6 = v4->CF->pFile->VMRef;
      if ( v5 == (Scaleform::GFx::AS3::InstanceTraits::Traits *)v6->TraitsClassClass.pObject )
        v5 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)v6->TraitsObject.pObject;
    }
  }
  if ( v3 && v5 )
    result = (Scaleform::GFx::AS3::InstanceTraits::Traits *)v5->pParent.pObject;
  else
    result = v5;
  return result;
}

// File Line: 9057
// RVA: 0x7EA3B0
Scaleform::GFx::AS3::InstanceTraits::Traits *__fastcall Scaleform::GFx::AS3::Tracer::GetInstanceTraits(Scaleform::GFx::AS3::Tracer *this, Scaleform::GFx::AS3::Value *v)
{
  unsigned int v2; // er8
  int v4; // er8

  v2 = v->Flags & 0x1F;
  if ( (v2 - 12 <= 3 || v2 == 10) && !*(_QWORD *)&v->value.VNumber )
    return this->CF->pFile->VMRef->TraitsNull.pObject;
  if ( !v2 )
    return this->CF->pFile->VMRef->TraitsClassClass.pObject->ITraits.pObject;
  v4 = v2 - 8;
  if ( !v4 )
    return v->value.VS._1.ITr;
  if ( v4 == 1 )
    return *(Scaleform::GFx::AS3::InstanceTraits::Traits **)(*(_QWORD *)&v->value.VNumber + 200i64);
  return Scaleform::GFx::AS3::VM::GetInstanceTraits(this->CF->pFile->VMRef, v);
}

// File Line: 9098
// RVA: 0x7EA0A0
Scaleform::GFx::AS3::Value *__fastcall Scaleform::GFx::AS3::Tracer::GetGlobalObject(Scaleform::GFx::AS3::Tracer *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::TR::State *st)
{
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v3; // rcx
  Scaleform::GFx::AS3::Value *v4; // rcx
  int v5; // eax
  Scaleform::GFx::AS3::Value::V2U v6; // r8
  long double v7; // r8
  Scaleform::GFx::AS3::Value *v8; // rcx
  int v9; // eax
  Scaleform::GFx::AS3::Value::V2U v10; // r8
  long double v11; // r8

  v3 = this->CF->pSavedScope;
  if ( v3->Data.Size )
  {
    v4 = v3->Data.Data;
    result->Flags = v4->Flags;
    result->Bonus.pWeakProxy = v4->Bonus.pWeakProxy;
    result->value = v4->value;
    v5 = v4->Flags & 0x1F;
    if ( v5 > 9 )
    {
      if ( (v4->Flags >> 9) & 1 )
      {
        ++v4->Bonus.pWeakProxy->RefCount;
      }
      else if ( v5 == 10 )
      {
        ++*(_DWORD *)(*(_QWORD *)&v4->value.VNumber + 24i64);
      }
      else if ( v5 > 10 )
      {
        if ( v5 <= 15 )
        {
          v7 = v4->value.VNumber;
          if ( v7 != 0.0 )
            *(_DWORD *)(*(_QWORD *)&v7 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v7 + 32i64) + 1) & 0x8FBFFFFF;
        }
        else if ( v5 <= 17 )
        {
          v6.VObj = (Scaleform::GFx::AS3::Object *)v4->value.VS._2;
          if ( v6.VObj )
            v6.VObj->RefCount = (v6.VObj->RefCount + 1) & 0x8FBFFFFF;
        }
      }
    }
  }
  else
  {
    v8 = st->Registers.Data.Data;
    result->Flags = v8->Flags;
    result->Bonus.pWeakProxy = v8->Bonus.pWeakProxy;
    result->value = v8->value;
    v9 = v8->Flags & 0x1F;
    if ( v9 > 9 )
    {
      if ( (v8->Flags >> 9) & 1 )
      {
        ++v8->Bonus.pWeakProxy->RefCount;
      }
      else if ( v9 == 10 )
      {
        ++*(_DWORD *)(*(_QWORD *)&v8->value.VNumber + 24i64);
      }
      else if ( v9 > 10 )
      {
        if ( v9 <= 15 )
        {
          v11 = v8->value.VNumber;
          if ( v11 != 0.0 )
            *(_DWORD *)(*(_QWORD *)&v11 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v11 + 32i64) + 1) & 0x8FBFFFFF;
        }
        else if ( v9 <= 17 )
        {
          v10.VObj = (Scaleform::GFx::AS3::Object *)v8->value.VS._2;
          if ( v10.VObj )
            v10.VObj->RefCount = (v10.VObj->RefCount + 1) & 0x8FBFFFFF;
        }
      }
    }
  }
  return result;
}

// File Line: 9138
// RVA: 0x7F8120
bool __fastcall Scaleform::GFx::AS3::Tracer::IsAnyType(Scaleform::GFx::AS3::Tracer *this, Scaleform::GFx::AS3::Traits *tr)
{
  Scaleform::GFx::AS3::VM *v2; // r8

  v2 = this->CF->pFile->VMRef;
  return tr == (Scaleform::GFx::AS3::Traits *)v2->TraitsObject.pObject->ITraits.pObject
      || tr == (Scaleform::GFx::AS3::Traits *)v2->TraitsClassClass.pObject->ITraits.pObject;
}

// File Line: 9150
// RVA: 0x7F8FC0
bool __fastcall Scaleform::GFx::AS3::Tracer::IsPrimitiveType(Scaleform::GFx::AS3::Tracer *this, Scaleform::GFx::AS3::Traits *tr)
{
  Scaleform::GFx::AS3::VM *v2; // r8

  v2 = this->CF->pFile->VMRef;
  return tr == (Scaleform::GFx::AS3::Traits *)v2->TraitsBoolean.pObject->ITraits.pObject
      || tr == (Scaleform::GFx::AS3::Traits *)v2->TraitsVoid.pObject
      || tr == (Scaleform::GFx::AS3::Traits *)v2->TraitsNull.pObject
      || tr == (Scaleform::GFx::AS3::Traits *)v2->TraitsInt.pObject->ITraits.pObject
      || tr == (Scaleform::GFx::AS3::Traits *)v2->TraitsUint.pObject->ITraits.pObject
      || tr == (Scaleform::GFx::AS3::Traits *)v2->TraitsNumber.pObject->ITraits.pObject
      || tr == (Scaleform::GFx::AS3::Traits *)v2->TraitsString.pObject->ITraits.pObject;
}

// File Line: 9156
// RVA: 0x7F8980
bool __fastcall Scaleform::GFx::AS3::Tracer::IsNotRefCountedType(Scaleform::GFx::AS3::Tracer *this, Scaleform::GFx::AS3::Traits *tr)
{
  Scaleform::GFx::AS3::VM *v2; // r8

  v2 = this->CF->pFile->VMRef;
  return tr == (Scaleform::GFx::AS3::Traits *)v2->TraitsBoolean.pObject->ITraits.pObject
      || tr == (Scaleform::GFx::AS3::Traits *)v2->TraitsVoid.pObject
      || tr == (Scaleform::GFx::AS3::Traits *)v2->TraitsNull.pObject
      || tr == (Scaleform::GFx::AS3::Traits *)v2->TraitsInt.pObject->ITraits.pObject
      || tr == (Scaleform::GFx::AS3::Traits *)v2->TraitsUint.pObject->ITraits.pObject
      || tr == (Scaleform::GFx::AS3::Traits *)v2->TraitsNumber.pObject->ITraits.pObject;
}

// File Line: 9165
// RVA: 0x7F8A80
bool __fastcall Scaleform::GFx::AS3::Tracer::IsNumericType(Scaleform::GFx::AS3::Tracer *this, Scaleform::GFx::AS3::Traits *tr)
{
  Scaleform::GFx::AS3::VM *v2; // r8

  v2 = this->CF->pFile->VMRef;
  return tr == (Scaleform::GFx::AS3::Traits *)v2->TraitsInt.pObject->ITraits.pObject
      || tr == (Scaleform::GFx::AS3::Traits *)v2->TraitsUint.pObject->ITraits.pObject
      || tr == (Scaleform::GFx::AS3::Traits *)v2->TraitsNumber.pObject->ITraits.pObject;
}

// File Line: 9172
// RVA: 0x7F8910
bool __fastcall Scaleform::GFx::AS3::Tracer::IsNotObjectType(Scaleform::GFx::AS3::Tracer *this, Scaleform::GFx::AS3::Traits *tr)
{
  Scaleform::GFx::AS3::VM *v2; // r8

  v2 = this->CF->pFile->VMRef;
  return tr == (Scaleform::GFx::AS3::Traits *)v2->TraitsInt.pObject->ITraits.pObject
      || tr == (Scaleform::GFx::AS3::Traits *)v2->TraitsUint.pObject->ITraits.pObject
      || tr == (Scaleform::GFx::AS3::Traits *)v2->TraitsNumber.pObject->ITraits.pObject
      || tr == (Scaleform::GFx::AS3::Traits *)v2->TraitsBoolean.pObject->ITraits.pObject
      || tr == (Scaleform::GFx::AS3::Traits *)v2->TraitsVoid.pObject
      || tr == (Scaleform::GFx::AS3::Traits *)v2->TraitsString.pObject->ITraits.pObject;
}

// File Line: 9185
// RVA: 0x829600
char __fastcall Scaleform::GFx::AS3::Tracer::ValueIsOfType(Scaleform::GFx::AS3::Tracer *this, Scaleform::GFx::AS3::Value *value, Scaleform::GFx::AS3::ClassTraits::Traits *type)
{
  Scaleform::GFx::AS3::ClassTraits::Traits *v3; // rbx
  unsigned int v4; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v5; // rax

  v3 = type;
  v4 = value->Flags & 0x1F;
  if ( v4 == 9 )
    return Scaleform::GFx::AS3::ClassTraits::Traits::IsOfType(value->value.VS._1.CTr, type);
  if ( v4 == 13 )
    return Scaleform::GFx::AS3::ClassTraits::Traits::IsOfType(
             *(Scaleform::GFx::AS3::ClassTraits::Traits **)(*(_QWORD *)&value->value.VNumber + 40i64),
             type);
  v5 = Scaleform::GFx::AS3::Tracer::GetInstanceTraits(this, value);
  return Scaleform::GFx::AS3::InstanceTraits::Traits::IsOfType(v5, v3->ITraits.pObject);
}

// File Line: 9221
// RVA: 0x80AFC0
void __fastcall Scaleform::GFx::AS3::Tracer::PushNewOpCode(Scaleform::GFx::AS3::Tracer *this, Scaleform::GFx::AS3::Abc::Code::OpCode opcode)
{
  unsigned __int64 v2; // rsi
  Scaleform::GFx::AS3::Tracer *v3; // rbp
  unsigned __int64 v4; // r14
  unsigned __int64 v5; // rax
  unsigned __int64 v6; // rbx
  unsigned __int64 v7; // r8
  unsigned __int64 *v8; // rax
  Scaleform::GFx::AS3::MethodInfo *v9; // rbx
  unsigned __int64 v10; // rdi
  Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *v11; // rbx
  unsigned __int64 v12; // rdi
  unsigned __int64 v13; // r8
  unsigned __int64 *v14; // rax

  v2 = opcode;
  v3 = this;
  Scaleform::GFx::AS3::Tracer::CalcOpStackSize(this, opcode, 0i64, 0i64);
  v4 = v3->MI->OpCode.Data.Size;
  v5 = v3->NewOpcodePos.Data.Size;
  v6 = v5 + 1;
  if ( v5 + 1 >= v5 )
  {
    if ( v6 <= v3->NewOpcodePos.Data.Policy.Capacity )
      goto LABEL_7;
    v7 = v6 + (v6 >> 2);
  }
  else
  {
    if ( v6 >= v3->NewOpcodePos.Data.Policy.Capacity >> 1 )
      goto LABEL_7;
    v7 = v5 + 1;
  }
  Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
    (Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy> *)&v3->NewOpcodePos.Data.Data,
    v3->NewOpcodePos.Data.pHeap,
    v7);
LABEL_7:
  v8 = v3->NewOpcodePos.Data.Data;
  v3->NewOpcodePos.Data.Size = v6;
  v8[v6 - 1] = v4;
  v9 = v3->MI;
  v10 = v9->OpCode.Data.Size;
  v11 = (Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *)&v9->OpCode.Data.Data;
  v12 = v10 + 1;
  if ( v12 >= v11->Size )
  {
    if ( v12 > v11->Policy.Capacity )
    {
      v13 = v12 + (v12 >> 2);
      goto LABEL_12;
    }
  }
  else if ( v12 < v11->Policy.Capacity >> 1 )
  {
    v13 = v12;
LABEL_12:
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v11,
      v11,
      v13);
    goto LABEL_13;
  }
LABEL_13:
  v14 = v11->Data;
  v11->Size = v12;
  v14[v12 - 1] = v2;
}

// File Line: 9236
// RVA: 0x80B240
void __fastcall Scaleform::GFx::AS3::Tracer::PushNewOpCode(Scaleform::GFx::AS3::Tracer *this, Scaleform::GFx::AS3::Abc::Code::OpCode opcode, unsigned __int64 arg1)
{
  unsigned __int64 v3; // rbp
  unsigned __int64 v4; // r14
  Scaleform::GFx::AS3::Tracer *v5; // rsi
  unsigned __int64 v6; // r15
  unsigned __int64 v7; // rax
  unsigned __int64 v8; // rbx
  unsigned __int64 v9; // r8
  unsigned __int64 *v10; // rax
  Scaleform::GFx::AS3::MethodInfo *v11; // rbx
  unsigned __int64 v12; // rdi
  Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *v13; // rbx
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
  v4 = arg1;
  v5 = this;
  Scaleform::GFx::AS3::Tracer::CalcOpStackSize(this, opcode, arg1, 0i64);
  v6 = v5->MI->OpCode.Data.Size;
  v7 = v5->NewOpcodePos.Data.Size;
  v8 = v7 + 1;
  if ( v7 + 1 >= v7 )
  {
    if ( v8 <= v5->NewOpcodePos.Data.Policy.Capacity )
      goto LABEL_7;
    v9 = v8 + (v8 >> 2);
  }
  else
  {
    if ( v8 >= v5->NewOpcodePos.Data.Policy.Capacity >> 1 )
      goto LABEL_7;
    v9 = v7 + 1;
  }
  Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
    (Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy> *)&v5->NewOpcodePos.Data.Data,
    v5->NewOpcodePos.Data.pHeap,
    v9);
LABEL_7:
  v10 = v5->NewOpcodePos.Data.Data;
  v5->NewOpcodePos.Data.Size = v8;
  v10[v8 - 1] = v6;
  v11 = v5->MI;
  v12 = v11->OpCode.Data.Size;
  v13 = (Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *)&v11->OpCode.Data.Data;
  v14 = v12 + 1;
  if ( v14 >= v13->Size )
  {
    if ( v14 <= v13->Policy.Capacity )
      goto LABEL_13;
    v15 = v14 + (v14 >> 2);
  }
  else
  {
    if ( v14 >= v13->Policy.Capacity >> 1 )
      goto LABEL_13;
    v15 = v14;
  }
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
    v13,
    v13,
    v15);
LABEL_13:
  v16 = v13->Data;
  v13->Size = v14;
  v16[v14 - 1] = v3;
  v17 = v5->MI;
  v18 = v17->OpCode.Data.Size;
  v19 = (Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *)&v17->OpCode.Data.Data;
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
    goto LABEL_19;
  }
LABEL_19:
  v22 = v19->Data;
  v19->Size = v20;
  v22[v20 - 1] = v4;
}

// File Line: 9252
// RVA: 0x80B3F0
void __fastcall Scaleform::GFx::AS3::Tracer::PushNewOpCodeNumber(Scaleform::GFx::AS3::Tracer *this, Scaleform::GFx::AS3::Abc::Code::OpCode opcode, long double arg1)
{
  unsigned __int64 v3; // rbp
  Scaleform::GFx::AS3::Tracer *v4; // rsi
  unsigned __int64 v5; // r14
  unsigned __int64 v6; // rax
  unsigned __int64 v7; // rbx
  unsigned __int64 v8; // r8
  unsigned __int64 *v9; // rax
  Scaleform::GFx::AS3::MethodInfo *v10; // rbx
  unsigned __int64 v11; // rdi
  Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *v12; // rbx
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
  v4 = this;
  Scaleform::GFx::AS3::Tracer::CalcOpStackSize(this, opcode, 0i64, 0i64);
  v5 = v4->MI->OpCode.Data.Size;
  v6 = v4->NewOpcodePos.Data.Size;
  v7 = v6 + 1;
  if ( v6 + 1 >= v6 )
  {
    if ( v7 <= v4->NewOpcodePos.Data.Policy.Capacity )
      goto LABEL_7;
    v8 = v7 + (v7 >> 2);
  }
  else
  {
    if ( v7 >= v4->NewOpcodePos.Data.Policy.Capacity >> 1 )
      goto LABEL_7;
    v8 = v6 + 1;
  }
  Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
    (Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy> *)&v4->NewOpcodePos.Data.Data,
    v4->NewOpcodePos.Data.pHeap,
    v8);
LABEL_7:
  v9 = v4->NewOpcodePos.Data.Data;
  v4->NewOpcodePos.Data.Size = v7;
  v9[v7 - 1] = v5;
  v10 = v4->MI;
  v11 = v10->OpCode.Data.Size;
  v12 = (Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *)&v10->OpCode.Data.Data;
  v13 = v11 + 1;
  if ( v13 >= v12->Size )
  {
    if ( v13 <= v12->Policy.Capacity )
      goto LABEL_13;
    v14 = v13 + (v13 >> 2);
  }
  else
  {
    if ( v13 >= v12->Policy.Capacity >> 1 )
      goto LABEL_13;
    v14 = v13;
  }
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
    v12,
    v12,
    v14);
LABEL_13:
  v15 = v12->Data;
  v12->Size = v13;
  v15[v13 - 1] = v3;
  v16 = v4->MI;
  v17 = v16->OpCode.Data.Size;
  v18 = (Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *)&v16->OpCode.Data.Data;
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
    goto LABEL_19;
  }
LABEL_19:
  v21 = v18->Data;
  v18->Size = v19;
  *(long double *)&v21[v19 - 1] = arg1;
}

// File Line: 9295
// RVA: 0x80B0B0
void __fastcall Scaleform::GFx::AS3::Tracer::PushNewOpCode(Scaleform::GFx::AS3::Tracer *this, Scaleform::GFx::AS3::Abc::Code::OpCode opcode, unsigned __int64 arg1, unsigned __int64 arg2)
{
  unsigned __int64 v4; // rbp
  unsigned __int64 v5; // r15
  unsigned __int64 v6; // r12
  Scaleform::GFx::AS3::Tracer *v7; // rsi
  unsigned __int64 v8; // r14
  unsigned __int64 v9; // rax
  unsigned __int64 v10; // rbx
  unsigned __int64 v11; // r8
  unsigned __int64 *v12; // rax
  Scaleform::GFx::AS3::MethodInfo *v13; // rbx
  unsigned __int64 v14; // rdi
  Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *v15; // rbx
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
  v5 = arg2;
  v6 = arg1;
  v7 = this;
  Scaleform::GFx::AS3::Tracer::CalcOpStackSize(this, opcode, arg1, arg2);
  v8 = v7->MI->OpCode.Data.Size;
  v9 = v7->NewOpcodePos.Data.Size;
  v10 = v9 + 1;
  if ( v9 + 1 >= v9 )
  {
    if ( v10 <= v7->NewOpcodePos.Data.Policy.Capacity )
      goto LABEL_7;
    v11 = v10 + (v10 >> 2);
  }
  else
  {
    if ( v10 >= v7->NewOpcodePos.Data.Policy.Capacity >> 1 )
      goto LABEL_7;
    v11 = v9 + 1;
  }
  Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
    (Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy> *)&v7->NewOpcodePos.Data.Data,
    v7->NewOpcodePos.Data.pHeap,
    v11);
LABEL_7:
  v12 = v7->NewOpcodePos.Data.Data;
  v7->NewOpcodePos.Data.Size = v10;
  v12[v10 - 1] = v8;
  v13 = v7->MI;
  v14 = v13->OpCode.Data.Size;
  v15 = (Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *)&v13->OpCode.Data.Data;
  v16 = v14 + 1;
  if ( v16 >= v15->Size )
  {
    if ( v16 <= v15->Policy.Capacity )
      goto LABEL_13;
    v17 = v16 + (v16 >> 2);
  }
  else
  {
    if ( v16 >= v15->Policy.Capacity >> 1 )
      goto LABEL_13;
    v17 = v16;
  }
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
    v15,
    v15,
    v17);
LABEL_13:
  v18 = v15->Data;
  v15->Size = v16;
  v18[v16 - 1] = v4;
  v19 = v7->MI;
  v20 = v19->OpCode.Data.Size;
  v21 = (Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *)&v19->OpCode.Data.Data;
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
  v24[v22 - 1] = v6;
  v25 = v7->MI;
  v26 = v25->OpCode.Data.Size;
  v27 = (Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *)&v25->OpCode.Data.Data;
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
    goto LABEL_25;
  }
LABEL_25:
  v30 = v27->Data;
  v27->Size = v28;
  v30[v28 - 1] = v5;
}

// File Line: 9312
// RVA: 0x7B2320
void __fastcall Scaleform::GFx::AS3::Tracer::CalcOpStackSize(Scaleform::GFx::AS3::Tracer *this, Scaleform::GFx::AS3::Abc::Code::OpCode opcode, unsigned __int64 arg1, unsigned __int64 arg2)
{
  Scaleform::GFx::AS3::Abc::Code::OpCode v4; // ebx
  Scaleform::GFx::AS3::Tracer *v5; // r11
  unsigned int v6; // er10
  char v7; // dl
  int v8; // er10
  Scaleform::GFx::AS3::TR::Block *v9; // rcx
  unsigned __int64 v10; // rdx
  Scaleform::GFx::AS3::MethodInfo *v11; // rcx

  v4 = opcode;
  v5 = this;
  v6 = (unsigned int)Scaleform::GFx::AS3::Abc::Code::opcode_info[opcode];
  v7 = byte_14182DEC1[2 * opcode];
  v8 = -((v6 >> 5) & 3);
  if ( v7 & 8 )
  {
    switch ( this->CF->pFile->File.pObject->Const_Pool.const_multiname.Data.Data[arg1].Kind )
    {
      case 1:
      case 6:
      case 9:
      case 0xE:
        --v8;
        break;
      case 5:
      case 0xD:
        v8 -= 2;
        break;
      default:
        break;
    }
  }
  if ( v7 & 4 )
  {
    if ( v4 == 85 )
      v8 -= 2 * arg2;
    else
      v8 -= arg2;
  }
  v9 = this->CurrBlock;
  v9->CurOpStackSize += v8 + (v7 & 3);
  v10 = v9->CurOpStackSize;
  v11 = v5->MI;
  if ( v10 < v11->MaxOpStackSize )
    v10 = v11->MaxOpStackSize;
  v11->MaxOpStackSize = v10;
}

// File Line: 9381
// RVA: 0x80B380
void __fastcall Scaleform::GFx::AS3::Tracer::PushNewOpCodeArg0(Scaleform::GFx::AS3::Tracer *this, unsigned __int64 arg)
{
  Scaleform::GFx::AS3::MethodInfo *v2; // rbx
  unsigned __int64 v3; // rsi
  unsigned __int64 v4; // rdi
  Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *v5; // rbx
  unsigned __int64 v6; // rdi
  unsigned __int64 v7; // r8
  unsigned __int64 *v8; // rax

  v2 = this->MI;
  v3 = arg;
  v4 = v2->OpCode.Data.Size;
  v5 = (Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *)&v2->OpCode.Data.Data;
  v6 = v4 + 1;
  if ( v6 >= v5->Size )
  {
    if ( v6 > v5->Policy.Capacity )
    {
      v7 = v6 + (v6 >> 2);
      goto LABEL_6;
    }
  }
  else if ( v6 < v5->Policy.Capacity >> 1 )
  {
    v7 = v6;
LABEL_6:
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v5,
      v5,
      v7);
    goto LABEL_7;
  }
LABEL_7:
  v8 = v5->Data;
  v5->Size = v6;
  v8[v6 - 1] = v3;
}

