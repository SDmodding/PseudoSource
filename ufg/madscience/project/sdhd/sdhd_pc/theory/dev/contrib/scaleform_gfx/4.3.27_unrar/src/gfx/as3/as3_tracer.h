// File Line: 349
// RVA: 0x8077C0
Scaleform::GFx::AS3::Value *__fastcall Scaleform::GFx::AS3::TR::State::PopOpValue(Scaleform::GFx::AS3::TR::State *this, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value *v2; // rbx

  v2 = result;
  Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::Pop(
    (Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> > *)&this->OpStack.Data,
    result);
  return v2;
}

// File Line: 357
// RVA: 0x80B600
void __fastcall Scaleform::GFx::AS3::TR::State::PushOp(Scaleform::GFx::AS3::TR::State *this, Scaleform::GFx::AS3::Value *v)
{
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v2; // rbx
  Scaleform::GFx::AS3::Value *v3; // rdi

  v2 = &this->OpStack;
  v3 = v;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&this->OpStack.Data.Data,
    this->OpStack.Data.pHeap,
    this->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(&v2->Data.Data[v2->Data.Size - 1], v3);
}

// File Line: 361
// RVA: 0x80B530
void __fastcall Scaleform::GFx::AS3::TR::State::PushOp(Scaleform::GFx::AS3::TR::State *this, Scaleform::GFx::AS3::InstanceTraits::Traits *tr, Scaleform::GFx::AS3::Value::TraceNullType isNull)
{
  unsigned __int32 v3; // edi
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v4; // rbx
  Scaleform::GFx::AS3::Value source; // [rsp+28h] [rbp-30h]

  source.Bonus.pWeakProxy = 0i64;
  *(_QWORD *)&source.value.VNumber = tr;
  v3 = (32 * isNull | 8) & 0xFFFFFEFF;
  source.Flags = (32 * isNull | 8) & 0xFFFFFEFF;
  v4 = &this->OpStack;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&this->OpStack.Data.Data,
    this->OpStack.Data.pHeap,
    this->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(&v4->Data.Data[v4->Data.Size - 1], &source);
  if ( (char)(v3 & 0x1F) > 9 )
  {
    if ( (v3 >> 9) & 1 )
    {
      LODWORD(MEMORY[0]) = MEMORY[0] - 1;
      if ( !(_DWORD)MEMORY[0] )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
      source.Bonus.pWeakProxy = 0i64;
      source.value = 0ui64;
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
void __fastcall Scaleform::GFx::AS3::TR::State::SetRegister(Scaleform::GFx::AS3::TR::State *this, Scaleform::GFx::AS3::AbsoluteIndex index, Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::TR::State *v3; // rbx
  char *v4; // r8
  __int64 v5; // [rsp+38h] [rbp+10h]

  v5 = index.Index;
  v3 = this;
  Scaleform::GFx::AS3::Value::Assign(&this->Registers.Data.Data[LODWORD(index.Index)], v);
  v4 = &v3->RegistersAlive.pData[(unsigned __int64)(unsigned int)v5 >> 3];
  *v4 |= 1 << (v5 & 7);
}

// File Line: 1323
// RVA: 0x7F92B0
bool __fastcall Scaleform::GFx::AS3::Tracer::IsStringType(Scaleform::GFx::AS3::Tracer *this, Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::Tracer *v2; // rbx
  long double v3; // rdx
  Scaleform::GFx::AS3::VM *v4; // rax

  v2 = this;
  if ( v->Flags & 0x1F )
  {
    if ( (v->Flags & 0x1F) == 8 || (v->Flags & 0x1F) == 9 )
      v3 = v->value.VNumber;
    else
      v3 = COERCE_DOUBLE(Scaleform::GFx::AS3::VM::GetValueTraits(this->CF->pFile->VMRef, v));
  }
  else
  {
    v3 = *(double *)&this->CF->pFile->VMRef->TraitsVoid.pObject;
  }
  if ( v3 != 0.0 )
  {
    v4 = v2->CF->pFile->VMRef;
    if ( *(Scaleform::GFx::AS3::ClassTraits::ClassClass **)&v3 == v4->TraitsClassClass.pObject )
      v3 = *(double *)&v4->TraitsObject.pObject;
  }
  return *(Scaleform::GFx::AS3::InstanceTraits::Traits **)&v3 == v2->CF->pFile->VMRef->TraitsString.pObject->ITraits.pObject;
}

// File Line: 1333
// RVA: 0x7F8200
bool __fastcall Scaleform::GFx::AS3::Tracer::IsBooleanType(Scaleform::GFx::AS3::Tracer *this, Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::Tracer *v2; // rbx
  long double v3; // rdx
  Scaleform::GFx::AS3::VM *v4; // rax

  v2 = this;
  if ( v->Flags & 0x1F )
  {
    if ( (v->Flags & 0x1F) == 8 || (v->Flags & 0x1F) == 9 )
      v3 = v->value.VNumber;
    else
      v3 = COERCE_DOUBLE(Scaleform::GFx::AS3::VM::GetValueTraits(this->CF->pFile->VMRef, v));
  }
  else
  {
    v3 = *(double *)&this->CF->pFile->VMRef->TraitsVoid.pObject;
  }
  if ( v3 != 0.0 )
  {
    v4 = v2->CF->pFile->VMRef;
    if ( *(Scaleform::GFx::AS3::ClassTraits::ClassClass **)&v3 == v4->TraitsClassClass.pObject )
      v3 = *(double *)&v4->TraitsObject.pObject;
  }
  return *(Scaleform::GFx::AS3::InstanceTraits::Traits **)&v3 == v2->CF->pFile->VMRef->TraitsBoolean.pObject->ITraits.pObject;
}

// File Line: 1350
// RVA: 0x7F90A0
bool __fastcall Scaleform::GFx::AS3::Tracer::IsSIntType(Scaleform::GFx::AS3::Tracer *this, Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::Tracer *v2; // rbx
  long double v3; // rdx
  Scaleform::GFx::AS3::VM *v4; // rax

  v2 = this;
  if ( v->Flags & 0x1F )
  {
    if ( (v->Flags & 0x1F) == 8 || (v->Flags & 0x1F) == 9 )
      v3 = v->value.VNumber;
    else
      v3 = COERCE_DOUBLE(Scaleform::GFx::AS3::VM::GetValueTraits(this->CF->pFile->VMRef, v));
  }
  else
  {
    v3 = *(double *)&this->CF->pFile->VMRef->TraitsVoid.pObject;
  }
  if ( v3 != 0.0 )
  {
    v4 = v2->CF->pFile->VMRef;
    if ( *(Scaleform::GFx::AS3::ClassTraits::ClassClass **)&v3 == v4->TraitsClassClass.pObject )
      v3 = *(double *)&v4->TraitsObject.pObject;
  }
  return *(Scaleform::GFx::AS3::InstanceTraits::Traits **)&v3 == v2->CF->pFile->VMRef->TraitsInt.pObject->ITraits.pObject;
}

// File Line: 1367
// RVA: 0x7F94F0
bool __fastcall Scaleform::GFx::AS3::Tracer::IsUIntType(Scaleform::GFx::AS3::Tracer *this, Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::Tracer *v2; // rbx
  long double v3; // rdx
  Scaleform::GFx::AS3::VM *v4; // rax

  v2 = this;
  if ( v->Flags & 0x1F )
  {
    if ( (v->Flags & 0x1F) == 8 || (v->Flags & 0x1F) == 9 )
      v3 = v->value.VNumber;
    else
      v3 = COERCE_DOUBLE(Scaleform::GFx::AS3::VM::GetValueTraits(this->CF->pFile->VMRef, v));
  }
  else
  {
    v3 = *(double *)&this->CF->pFile->VMRef->TraitsVoid.pObject;
  }
  if ( v3 != 0.0 )
  {
    v4 = v2->CF->pFile->VMRef;
    if ( *(Scaleform::GFx::AS3::ClassTraits::ClassClass **)&v3 == v4->TraitsClassClass.pObject )
      v3 = *(double *)&v4->TraitsObject.pObject;
  }
  return *(Scaleform::GFx::AS3::InstanceTraits::Traits **)&v3 == v2->CF->pFile->VMRef->TraitsUint.pObject->ITraits.pObject;
}

// File Line: 1377
// RVA: 0x7F89F0
bool __fastcall Scaleform::GFx::AS3::Tracer::IsNumberType(Scaleform::GFx::AS3::Tracer *this, Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::Tracer *v2; // rbx
  long double v3; // rdx
  Scaleform::GFx::AS3::VM *v4; // rax

  v2 = this;
  if ( v->Flags & 0x1F )
  {
    if ( (v->Flags & 0x1F) == 8 || (v->Flags & 0x1F) == 9 )
      v3 = v->value.VNumber;
    else
      v3 = COERCE_DOUBLE(Scaleform::GFx::AS3::VM::GetValueTraits(this->CF->pFile->VMRef, v));
  }
  else
  {
    v3 = *(double *)&this->CF->pFile->VMRef->TraitsVoid.pObject;
  }
  if ( v3 != 0.0 )
  {
    v4 = v2->CF->pFile->VMRef;
    if ( *(Scaleform::GFx::AS3::ClassTraits::ClassClass **)&v3 == v4->TraitsClassClass.pObject )
      v3 = *(double *)&v4->TraitsObject.pObject;
  }
  return *(Scaleform::GFx::AS3::InstanceTraits::Traits **)&v3 == v2->CF->pFile->VMRef->TraitsNumber.pObject->ITraits.pObject;
}

// File Line: 1398
// RVA: 0x829660
char __fastcall Scaleform::GFx::AS3::Tracer::ValueIsOfType(Scaleform::GFx::AS3::Tracer *this, Scaleform::GFx::AS3::Value *value, Scaleform::GFx::AS3::InstanceTraits::Traits *type)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *v3; // rdi
  Scaleform::GFx::AS3::InstanceTraits::Traits *v4; // rax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v5; // rbx

  v3 = type;
  v4 = Scaleform::GFx::AS3::Tracer::GetInstanceTraits(this, value);
  v5 = v4;
  if ( v3 == v4 )
    return 1;
  if ( v4 )
  {
    while ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::InstanceTraits::Traits *, Scaleform::GFx::AS3::InstanceTraits::Traits *))v5->vfptr[4].~RefCountBaseGC<328>)(
               v5,
               v3) )
    {
      v5 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)v5->pParent.pObject;
      if ( v5 == v3 )
        break;
      if ( !v5 )
        return 0;
    }
    return 1;
  }
  return 0;
}

// File Line: 1405
// RVA: 0x7B32B0
signed __int64 __fastcall Scaleform::GFx::AS3::Tracer::CanBeNull(Scaleform::GFx::AS3::Tracer *this, Scaleform::GFx::AS3::InstanceTraits::Traits *tr)
{
  Scaleform::GFx::AS3::VM *v2; // r8
  char v3; // cl
  signed __int64 result; // rax

  v2 = this->CF->pFile->VMRef;
  if ( tr == v2->TraitsInt.pObject->ITraits.pObject
    || tr == v2->TraitsUint.pObject->ITraits.pObject
    || tr == v2->TraitsNumber.pObject->ITraits.pObject
    || (v3 = 0, tr == v2->TraitsBoolean.pObject->ITraits.pObject) )
  {
    v3 = 1;
  }
  result = 2i64;
  if ( v3 )
    result = 0i64;
  return result;
}

// File Line: 1664
// RVA: 0x8401C0
void __fastcall Scaleform::GFx::AS3::TR::State::exec_getglobalscope(Scaleform::GFx::AS3::TR::State *this, bool simulate)
{
  Scaleform::GFx::AS3::TR::State *v2; // rbx
  Scaleform::GFx::AS3::Value *v3; // rdi
  bool v4; // zf
  Scaleform::GFx::AS3::Value result; // [rsp+28h] [rbp-30h]

  v2 = this;
  if ( !simulate )
    Scaleform::GFx::AS3::Tracer::PushNewOpCode(this->pTracer, op_getglobalscope);
  v3 = Scaleform::GFx::AS3::Tracer::GetGlobalObject(v2->pTracer, &result, v2);
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v2->OpStack.Data.Data,
    v2->OpStack.Data.pHeap,
    v2->OpStack.Data.Size + 1);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(
    &v2->OpStack.Data.Data[v2->OpStack.Data.Size - 1],
    v3);
  if ( (result.Flags & 0x1F) > 9 )
  {
    if ( (result.Flags >> 9) & 1 )
    {
      v4 = result.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v4 )
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

// File Line: 1700
// RVA: 0x7F0EF0
Scaleform::GFx::AS3::ClassTraits::fl::Object *__fastcall Scaleform::GFx::AS3::TR::State::GetValueTraits(Scaleform::GFx::AS3::TR::State *this, Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::Tracer *v2; // rbx
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v3; // rdx
  Scaleform::GFx::AS3::VM *v4; // rax
  Scaleform::GFx::AS3::ClassTraits::fl::Object *result; // rax

  v2 = this->pTracer;
  if ( v->Flags & 0x1F )
  {
    if ( (v->Flags & 0x1F) == 8 || (v->Flags & 0x1F) == 9 )
      v3 = (Scaleform::GFx::AS3::ClassTraits::fl::Object *)v->value.VS._1.VStr;
    else
      v3 = (Scaleform::GFx::AS3::ClassTraits::fl::Object *)Scaleform::GFx::AS3::VM::GetValueTraits(
                                                             v2->CF->pFile->VMRef,
                                                             v);
  }
  else
  {
    v3 = (Scaleform::GFx::AS3::ClassTraits::fl::Object *)v2->CF->pFile->VMRef->TraitsVoid.pObject;
  }
  if ( v3
    && (v4 = v2->CF->pFile->VMRef, v3 == (Scaleform::GFx::AS3::ClassTraits::fl::Object *)v4->TraitsClassClass.pObject) )
  {
    result = v4->TraitsObject.pObject;
  }
  else
  {
    result = v3;
  }
  return result;
}

// File Line: 1730
// RVA: 0x7B3240
signed __int64 __fastcall Scaleform::GFx::AS3::TR::State::CanBeNull(Scaleform::GFx::AS3::TR::State *this, Scaleform::GFx::AS3::InstanceTraits::Traits *tr)
{
  Scaleform::GFx::AS3::VM *v2; // rcx
  Scaleform::GFx::AS3::ClassTraits::fl::Boolean *v3; // rax
  char v4; // cl
  signed __int64 result; // rax

  v2 = this->pTracer->CF->pFile->VMRef;
  if ( tr == v2->TraitsInt.pObject->ITraits.pObject
    || tr == v2->TraitsUint.pObject->ITraits.pObject
    || tr == v2->TraitsNumber.pObject->ITraits.pObject
    || (v3 = v2->TraitsBoolean.pObject, v4 = 0, tr == v3->ITraits.pObject) )
  {
    v4 = 1;
  }
  result = 2i64;
  if ( v4 )
    result = 0i64;
  return result;
}

