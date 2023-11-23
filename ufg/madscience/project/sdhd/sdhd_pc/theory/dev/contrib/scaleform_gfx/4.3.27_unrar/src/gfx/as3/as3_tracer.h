// File Line: 349
// RVA: 0x8077C0
Scaleform::GFx::AS3::Value *__fastcall Scaleform::GFx::AS3::TR::State::PopOpValue(
        Scaleform::GFx::AS3::TR::State *this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::Pop(
    &this->OpStack,
    result);
  return result;
}

// File Line: 357
// RVA: 0x80B600
void __fastcall Scaleform::GFx::AS3::TR::State::PushOp(
        Scaleform::GFx::AS3::TR::State *this,
        Scaleform::GFx::AS3::Value *v)
{
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *p_OpStack; // rbx

  p_OpStack = &this->OpStack;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->OpStack.Data,
    this->OpStack.Data.pHeap,
    this->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &p_OpStack->Data.Data[p_OpStack->Data.Size - 1].Flags,
    v);
}

// File Line: 361
// RVA: 0x80B530
void __fastcall Scaleform::GFx::AS3::TR::State::PushOp(
        Scaleform::GFx::AS3::TR::State *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *tr,
        Scaleform::GFx::AS3::Value::TraceNullType isNull)
{
  unsigned __int32 v3; // edi
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *p_OpStack; // rbx
  Scaleform::GFx::AS3::Value source; // [rsp+28h] [rbp-30h] BYREF

  source.Bonus.pWeakProxy = 0i64;
  source.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)tr;
  v3 = (32 * isNull) & 0xFFFFFEF7 | 8;
  source.Flags = v3;
  p_OpStack = &this->OpStack;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->OpStack.Data,
    this->OpStack.Data.pHeap,
    this->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &p_OpStack->Data.Data[p_OpStack->Data.Size - 1].Flags,
    &source);
  if ( (v3 & 0x1F) > 9 )
  {
    if ( (v3 & 0x200) != 0 )
    {
      LODWORD(MEMORY[0]) = MEMORY[0] - 1;
      if ( !(_DWORD)MEMORY[0] )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
      memset(&source.Bonus, 0, 24);
      source.Flags = v3 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&source);
    }
  }
}

// File Line: 398
// RVA: 0x81D420
void __fastcall Scaleform::GFx::AS3::TR::State::SetRegister(
        Scaleform::GFx::AS3::TR::State *this,
        Scaleform::GFx::AS3::AbsoluteIndex index,
        Scaleform::GFx::AS3::Value *v)
{
  char *v4; // r8
  unsigned int v5; // [rsp+38h] [rbp+10h]

  v5 = index.Index;
  Scaleform::GFx::AS3::Value::Assign(&this->Registers.Data.Data[LODWORD(index.Index)], v);
  v4 = &this->RegistersAlive.pData[(unsigned __int64)v5 >> 3];
  *v4 |= 1 << (v5 & 7);
}

// File Line: 1323
// RVA: 0x7F92B0
bool __fastcall Scaleform::GFx::AS3::Tracer::IsStringType(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *ITr; // rdx
  Scaleform::GFx::AS3::VM *VMRef; // rax

  if ( (v->Flags & 0x1F) != 0 )
  {
    if ( (v->Flags & 0x1F) - 8 < 2 )
      ITr = v->value.VS._1.ITr;
    else
      ITr = (Scaleform::GFx::AS3::InstanceTraits::Traits *)Scaleform::GFx::AS3::VM::GetValueTraits(
                                                             this->CF->pFile->VMRef,
                                                             v);
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
  return ITr == this->CF->pFile->VMRef->TraitsString.pObject->ITraits.pObject;
}

// File Line: 1333
// RVA: 0x7F8200
bool __fastcall Scaleform::GFx::AS3::Tracer::IsBooleanType(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *ITr; // rdx
  Scaleform::GFx::AS3::VM *VMRef; // rax

  if ( (v->Flags & 0x1F) != 0 )
  {
    if ( (v->Flags & 0x1F) - 8 < 2 )
      ITr = v->value.VS._1.ITr;
    else
      ITr = (Scaleform::GFx::AS3::InstanceTraits::Traits *)Scaleform::GFx::AS3::VM::GetValueTraits(
                                                             this->CF->pFile->VMRef,
                                                             v);
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
  return ITr == this->CF->pFile->VMRef->TraitsBoolean.pObject->ITraits.pObject;
}

// File Line: 1350
// RVA: 0x7F90A0
bool __fastcall Scaleform::GFx::AS3::Tracer::IsSIntType(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *ITr; // rdx
  Scaleform::GFx::AS3::VM *VMRef; // rax

  if ( (v->Flags & 0x1F) != 0 )
  {
    if ( (v->Flags & 0x1F) - 8 < 2 )
      ITr = v->value.VS._1.ITr;
    else
      ITr = (Scaleform::GFx::AS3::InstanceTraits::Traits *)Scaleform::GFx::AS3::VM::GetValueTraits(
                                                             this->CF->pFile->VMRef,
                                                             v);
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
  return ITr == this->CF->pFile->VMRef->TraitsInt.pObject->ITraits.pObject;
}

// File Line: 1367
// RVA: 0x7F94F0
bool __fastcall Scaleform::GFx::AS3::Tracer::IsUIntType(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *ITr; // rdx
  Scaleform::GFx::AS3::VM *VMRef; // rax

  if ( (v->Flags & 0x1F) != 0 )
  {
    if ( (v->Flags & 0x1F) - 8 < 2 )
      ITr = v->value.VS._1.ITr;
    else
      ITr = (Scaleform::GFx::AS3::InstanceTraits::Traits *)Scaleform::GFx::AS3::VM::GetValueTraits(
                                                             this->CF->pFile->VMRef,
                                                             v);
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
  return ITr == this->CF->pFile->VMRef->TraitsUint.pObject->ITraits.pObject;
}

// File Line: 1377
// RVA: 0x7F89F0
bool __fastcall Scaleform::GFx::AS3::Tracer::IsNumberType(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *ITr; // rdx
  Scaleform::GFx::AS3::VM *VMRef; // rax

  if ( (v->Flags & 0x1F) != 0 )
  {
    if ( (v->Flags & 0x1F) - 8 < 2 )
      ITr = v->value.VS._1.ITr;
    else
      ITr = (Scaleform::GFx::AS3::InstanceTraits::Traits *)Scaleform::GFx::AS3::VM::GetValueTraits(
                                                             this->CF->pFile->VMRef,
                                                             v);
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
  return ITr == this->CF->pFile->VMRef->TraitsNumber.pObject->ITraits.pObject;
}

// File Line: 1398
// RVA: 0x829660
char __fastcall Scaleform::GFx::AS3::Tracer::ValueIsOfType(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::AS3::InstanceTraits::Traits *type)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *InstanceTraits; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // rbx

  InstanceTraits = Scaleform::GFx::AS3::Tracer::GetInstanceTraits(this, value);
  pObject = InstanceTraits;
  if ( type == InstanceTraits )
    return 1;
  if ( InstanceTraits )
  {
    while ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::InstanceTraits::Traits *, Scaleform::GFx::AS3::InstanceTraits::Traits *))pObject->vfptr[4].~RefCountBaseGC<328>)(
               pObject,
               type) )
    {
      pObject = (Scaleform::GFx::AS3::InstanceTraits::Traits *)pObject->pParent.pObject;
      if ( pObject == type )
        break;
      if ( !pObject )
        return 0;
    }
    return 1;
  }
  return 0;
}

// File Line: 1405
// RVA: 0x7B32B0
__int64 __fastcall Scaleform::GFx::AS3::Tracer::CanBeNull(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *tr)
{
  Scaleform::GFx::AS3::VM *VMRef; // r8
  char v3; // cl
  __int64 result; // rax

  VMRef = this->CF->pFile->VMRef;
  if ( tr == VMRef->TraitsInt.pObject->ITraits.pObject
    || tr == VMRef->TraitsUint.pObject->ITraits.pObject
    || tr == VMRef->TraitsNumber.pObject->ITraits.pObject
    || (v3 = 0, tr == VMRef->TraitsBoolean.pObject->ITraits.pObject) )
  {
    v3 = 1;
  }
  result = 2i64;
  if ( v3 )
    return 0i64;
  return result;
}

// File Line: 1664
// RVA: 0x8401C0
void __fastcall Scaleform::GFx::AS3::TR::State::exec_getglobalscope(
        Scaleform::GFx::AS3::TR::State *this,
        bool simulate)
{
  Scaleform::GFx::AS3::Value *GlobalObject; // rdi
  Scaleform::GFx::AS3::Value result; // [rsp+28h] [rbp-30h] BYREF

  if ( !simulate )
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_getglobalscope);
  GlobalObject = Scaleform::GFx::AS3::Tracer::GetGlobalObject(this->pTracer, &result, this);
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->OpStack.Data,
    (__int64 *)this->OpStack.Data.pHeap,
    this->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &this->OpStack.Data.Data[this->OpStack.Data.Size - 1].Flags,
    GlobalObject);
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

// File Line: 1700
// RVA: 0x7F0EF0
Scaleform::GFx::AS3::ClassTraits::fl::Object *__fastcall Scaleform::GFx::AS3::TR::State::GetValueTraits(
        Scaleform::GFx::AS3::TR::State *this,
        Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::Tracer *pTracer; // rbx
  Scaleform::GFx::AS3::Traits *ITr; // rdx
  Scaleform::GFx::AS3::VM *VMRef; // rax

  pTracer = this->pTracer;
  if ( (v->Flags & 0x1F) != 0 )
  {
    if ( (v->Flags & 0x1F) - 8 < 2 )
      ITr = v->value.VS._1.ITr;
    else
      ITr = Scaleform::GFx::AS3::VM::GetValueTraits(pTracer->CF->pFile->VMRef, v);
  }
  else
  {
    ITr = pTracer->CF->pFile->VMRef->TraitsVoid.pObject;
  }
  if ( ITr && (VMRef = pTracer->CF->pFile->VMRef, ITr == VMRef->TraitsClassClass.pObject) )
    return VMRef->TraitsObject.pObject;
  else
    return (Scaleform::GFx::AS3::ClassTraits::fl::Object *)ITr;
}

// File Line: 1730
// RVA: 0x7B3240
__int64 __fastcall Scaleform::GFx::AS3::TR::State::CanBeNull(
        Scaleform::GFx::AS3::TR::State *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *tr)
{
  Scaleform::GFx::AS3::VM *VMRef; // rcx
  Scaleform::GFx::AS3::ClassTraits::fl::Boolean *pObject; // rax
  char v4; // cl
  __int64 result; // rax

  VMRef = this->pTracer->CF->pFile->VMRef;
  if ( tr == VMRef->TraitsInt.pObject->ITraits.pObject
    || tr == VMRef->TraitsUint.pObject->ITraits.pObject
    || tr == VMRef->TraitsNumber.pObject->ITraits.pObject
    || (pObject = VMRef->TraitsBoolean.pObject, v4 = 0, tr == pObject->ITraits.pObject) )
  {
    v4 = 1;
  }
  result = 2i64;
  if ( v4 )
    return 0i64;
  return result;
}

