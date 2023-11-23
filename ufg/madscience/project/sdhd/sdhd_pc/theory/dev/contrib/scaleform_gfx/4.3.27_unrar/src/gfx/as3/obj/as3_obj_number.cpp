// File Line: 51
// RVA: 0x1597120
const char *dynamic_initializer_for__Scaleform::GFx::AS3::InstanceTraits::fl::Number::ti__()
{
  const char *result; // rax

  result = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::Number::ti[0].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::Number::ti[1].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::Number::ti[2].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::Number::ti[3].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::Number::ti[4].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::Number::ti[5].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  return result;
}

// File Line: 74
// RVA: 0x76B280
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Number::AS3toExponential(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v11; // zf
  const char *pStr; // rbx
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // rdi
  SSExpressionBase *Heap; // rax
  Scaleform::GFx::ASString *String; // rax
  Scaleform::GFx::ASStringNode *v16; // rcx
  unsigned int resulta; // [rsp+20h] [rbp-1E8h] BYREF
  Scaleform::GFx::AS3::VM::Error v18; // [rsp+28h] [rbp-1E0h] BYREF
  __int64 v19; // [rsp+38h] [rbp-1D0h]
  Scaleform::StringDataPtr v20; // [rsp+40h] [rbp-1C8h] BYREF
  Scaleform::DoubleFormatter v21; // [rsp+50h] [rbp-1B8h] BYREF

  v19 = -2i64;
  resulta = 0;
  if ( !argc )
    goto LABEL_6;
  if ( !Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&argc, &resulta)->Result )
    return;
  if ( resulta > 0x14 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v18, eInvalidPrecisionError, vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v9, &Scaleform::GFx::AS3::fl::RangeErrorTI);
    pNode = v18.Message.pNode;
    v11 = v18.Message.pNode->RefCount-- == 1;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  else
  {
LABEL_6:
    Scaleform::DoubleFormatter::DoubleFormatter(&v21, _this->value.VNumber);
    v21.Type = FmtScientific;
    *(_DWORD *)&v21.Scaleform::NumericBase ^= ((unsigned __int8)resulta ^ *(_BYTE *)&v21.Scaleform::NumericBase) & 0x1F;
    ((void (__fastcall *)(Scaleform::DoubleFormatter *))v21.Scaleform::Formatter::Scaleform::FmtResource::vfptr[1].Reflect)(&v21);
    pStr = Scaleform::LongFormatter::GetResult((Scaleform::LongFormatter *)&v21, &v20)->pStr;
    StringManagerRef = vm->StringManagerRef;
    Heap = Scaleform::GFx::MovieImpl::GetHeap((SSClosureInfoMethod *)&v21);
    String = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
               StringManagerRef,
               (Scaleform::GFx::ASString *)&v18,
               pStr,
               (unsigned __int64)Heap);
    Scaleform::GFx::AS3::Value::Assign(result, String);
    v16 = *(Scaleform::GFx::ASStringNode **)&v18.ID;
    v11 = (*(_DWORD *)(*(_QWORD *)&v18.ID + 24i64))-- == 1;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v16);
    v21.Scaleform::String::InitStruct::vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable;
    Scaleform::Formatter::~Formatter(&v21);
  }
}

// File Line: 94
// RVA: 0x7A74C0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Number::AS3toFixed(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v11; // zf
  const char *pStr; // rbx
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // rdi
  SSExpressionBase *Heap; // rax
  Scaleform::GFx::ASString *String; // rax
  Scaleform::GFx::ASStringNode *v16; // rcx
  unsigned int resulta; // [rsp+20h] [rbp-1E8h] BYREF
  Scaleform::GFx::AS3::VM::Error v18; // [rsp+28h] [rbp-1E0h] BYREF
  __int64 v19; // [rsp+38h] [rbp-1D0h]
  Scaleform::StringDataPtr v20; // [rsp+40h] [rbp-1C8h] BYREF
  Scaleform::DoubleFormatter v21; // [rsp+50h] [rbp-1B8h] BYREF

  v19 = -2i64;
  resulta = 0;
  if ( !argc )
    goto LABEL_6;
  if ( !Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&argc, &resulta)->Result )
    return;
  if ( resulta > 0x14 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v18, 1002, vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v9, &Scaleform::GFx::AS3::fl::RangeErrorTI);
    pNode = v18.Message.pNode;
    v11 = v18.Message.pNode->RefCount-- == 1;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  else
  {
LABEL_6:
    Scaleform::DoubleFormatter::DoubleFormatter(&v21, _this->value.VNumber);
    v21.Type = FmtDecimal;
    *(_DWORD *)&v21.Scaleform::NumericBase ^= ((unsigned __int8)resulta ^ *(_BYTE *)&v21.Scaleform::NumericBase) & 0x1F;
    ((void (__fastcall *)(Scaleform::DoubleFormatter *))v21.Scaleform::Formatter::Scaleform::FmtResource::vfptr[1].Reflect)(&v21);
    pStr = Scaleform::LongFormatter::GetResult((Scaleform::LongFormatter *)&v21, &v20)->pStr;
    StringManagerRef = vm->StringManagerRef;
    Heap = Scaleform::GFx::MovieImpl::GetHeap((SSClosureInfoMethod *)&v21);
    String = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
               StringManagerRef,
               (Scaleform::GFx::ASString *)&v18,
               pStr,
               (unsigned __int64)Heap);
    Scaleform::GFx::AS3::Value::Assign(result, String);
    v16 = *(Scaleform::GFx::ASStringNode **)&v18.ID;
    v11 = (*(_DWORD *)(*(_QWORD *)&v18.ID + 24i64))-- == 1;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v16);
    v21.Scaleform::String::InitStruct::vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable;
    Scaleform::Formatter::~Formatter(&v21);
  }
}

// File Line: 114
// RVA: 0x7A79B0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Number::AS3toPrecision(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  const char *pStr; // rbx
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // rdi
  SSExpressionBase *Heap; // rax
  Scaleform::GFx::ASString *String; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  bool v14; // zf
  Scaleform::GFx::AS3::VM::Error *v15; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  unsigned int resulta; // [rsp+20h] [rbp-1E8h] BYREF
  Scaleform::GFx::AS3::VM::Error v18; // [rsp+28h] [rbp-1E0h] BYREF
  __int64 v19; // [rsp+38h] [rbp-1D0h]
  Scaleform::StringDataPtr v20; // [rsp+40h] [rbp-1C8h] BYREF
  Scaleform::DoubleFormatter v21; // [rsp+50h] [rbp-1B8h] BYREF

  v19 = -2i64;
  resulta = 0;
  if ( !argc )
    goto LABEL_7;
  if ( !Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&argc, &resulta)->Result )
    return;
  if ( resulta - 1 <= 0x14 )
  {
    Scaleform::DoubleFormatter::DoubleFormatter(&v21, _this->value.VNumber);
    v21.Type = FmtSignificant;
    *(_DWORD *)&v21.Scaleform::NumericBase ^= ((unsigned __int8)resulta ^ *(_BYTE *)&v21.Scaleform::NumericBase) & 0x1F;
    ((void (__fastcall *)(Scaleform::DoubleFormatter *))v21.Scaleform::Formatter::Scaleform::FmtResource::vfptr[1].Reflect)(&v21);
    pStr = Scaleform::LongFormatter::GetResult((Scaleform::LongFormatter *)&v21, &v20)->pStr;
    StringManagerRef = vm->StringManagerRef;
    Heap = Scaleform::GFx::MovieImpl::GetHeap((SSClosureInfoMethod *)&v21);
    String = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
               StringManagerRef,
               (Scaleform::GFx::ASString *)&v18,
               pStr,
               (unsigned __int64)Heap);
    Scaleform::GFx::AS3::Value::Assign(result, String);
    v13 = *(Scaleform::GFx::ASStringNode **)&v18.ID;
    v14 = (*(_DWORD *)(*(_QWORD *)&v18.ID + 24i64))-- == 1;
    if ( v14 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    v21.Scaleform::String::InitStruct::vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable;
    Scaleform::Formatter::~Formatter(&v21);
  }
  else
  {
LABEL_7:
    Scaleform::GFx::AS3::VM::Error::Error(&v18, 1002, vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v15, &Scaleform::GFx::AS3::fl::RangeErrorTI);
    pNode = v18.Message.pNode;
    v14 = v18.Message.pNode->RefCount-- == 1;
    if ( v14 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 134
// RVA: 0x7A7FA0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Number::AS3toString(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Value *argc)
{
  unsigned int v8; // ecx
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error *v11; // rax
  long double VNumber; // xmm2_8
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  bool v15; // zf
  unsigned __int64 v16; // rax
  Scaleform::GFx::ASString *v17; // rax
  unsigned int v18; // [rsp+18h] [rbp-69h] BYREF
  int v; // [rsp+1Ch] [rbp-65h] BYREF
  Scaleform::GFx::AS3::VM::Error v20; // [rsp+20h] [rbp-61h] BYREF
  __int64 v21; // [rsp+30h] [rbp-51h]
  Scaleform::LongFormatter v22; // [rsp+38h] [rbp-49h] BYREF
  char buffer[56]; // [rsp+98h] [rbp+17h] BYREF
  Scaleform::GFx::ASString resulta; // [rsp+E8h] [rbp+67h] BYREF
  int v25; // [rsp+F8h] [rbp+77h]

  v21 = -2i64;
  v8 = 10;
  v18 = 10;
  if ( (_this->Flags & 0x1F) != 4 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v20, 1004, vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v9, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v20.Message.pNode;
    goto LABEL_15;
  }
  if ( v25 && (argc->Flags & 0x1F) != 0 )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2UInt32(argc, (Scaleform::GFx::AS3::CheckResult *)&resulta, &v18)->Result )
      return;
    v8 = v18;
    if ( v18 - 2 > 0x22 )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v20, 1003, vm);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v11, &Scaleform::GFx::AS3::fl::RangeErrorTI);
      pNode = v20.Message.pNode;
      goto LABEL_15;
    }
  }
  VNumber = _this->value.VNumber;
  if ( v8 == 10
    || (resulta.pNode = _this->value.VS._1.VStr, (*(_QWORD *)&VNumber & 0x7FF0000000000000i64) == 0x7FF0000000000000i64) )
  {
    v16 = Scaleform::GFx::AS3::SF_ECMA_dtostr(buffer, 40, VNumber);
    v17 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
            vm->StringManagerRef,
            &resulta,
            buffer,
            v16);
    Scaleform::GFx::AS3::Value::Assign(result, v17);
    pNode = resulta.pNode;
LABEL_15:
    v15 = pNode->RefCount-- == 1;
    if ( v15 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    return;
  }
  if ( Scaleform::GFx::AS3::Value::Convert2Int32(_this, (Scaleform::GFx::AS3::CheckResult *)&resulta, &v)->Result )
  {
    Scaleform::LongFormatter::LongFormatter(&v22, v);
    *((_DWORD *)&v22 + 12) ^= ((unsigned __int8)v18 ^ *((_BYTE *)&v22 + 48)) & 0x1F;
    *((_BYTE *)&v22.Scaleform::NumericBase + 6) &= ~1u;
    ((void (__fastcall *)(Scaleform::LongFormatter *))v22.Scaleform::Formatter::Scaleform::FmtResource::vfptr[1].Reflect)(&v22);
    Scaleform::LongFormatter::GetResult(&v22, (Scaleform::StringDataPtr *)&v20);
    v13 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
            vm->StringManagerRef,
            &resulta,
            *(const char **)&v20.ID,
            (unsigned __int64)v20.Message.pNode);
    Scaleform::GFx::AS3::Value::Assign(result, v13);
    v14 = resulta.pNode;
    v15 = resulta.pNode->RefCount-- == 1;
    if ( v15 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
    v22.Scaleform::String::InitStruct::vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable;
    Scaleform::Formatter::~Formatter(&v22);
  }
}

// File Line: 177
// RVA: 0x7A7990
// attributes: thunk
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Number::AS3toLocaleString(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::InstanceTraits::fl::Number::AS3toString(ti, vm, _this, result, argc, argv);
}

// File Line: 183
// RVA: 0x7A91F0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Number::AS3valueOf(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::VM::Error *v5; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v8; // [rsp+28h] [rbp-20h] BYREF

  if ( (_this->Flags & 0x1F) == 4 )
  {
    Scaleform::GFx::AS3::Value::Assign(result, _this);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v8, 1004, vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v5, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v8.Message.pNode;
    if ( v8.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 197
// RVA: 0x728150
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Number::toStringProto(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // rbx
  Scaleform::GFx::AS3::Object *VObj; // r14

  if ( (_this->Flags & 0x1F) - 12 > 3 )
    goto LABEL_6;
  pObject = vm->TraitsNumber.pObject->ITraits.pObject;
  VObj = _this->value.VS._1.VObj;
  if ( !pObject->pConstructor.pObject )
    pObject->vfptr[3].~RefCountBaseGC<328>(pObject);
  if ( VObj == Scaleform::GFx::AS3::Class::GetPrototype(pObject->pConstructor.pObject) )
    Scaleform::GFx::AS3::Value::Assign(result, (Scaleform::GFx::ASString *)&vm->StringManagerRef->Builtins[15]);
  else
LABEL_6:
    Scaleform::GFx::AS3::InstanceTraits::fl::Number::AS3toString(ti, vm, _this, result, argc, argv);
}

// File Line: 207
// RVA: 0x728A60
// attributes: thunk
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Number::toLocaleStringProto(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::InstanceTraits::fl::Number::toStringProto(ti, vm, _this, result, argc, argv);
}

// File Line: 213
// RVA: 0x728F70
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Number::valueOfProto(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Object *VObj; // r14
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // rdi
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v12; // [rsp+28h] [rbp-20h] BYREF

  if ( (_this->Flags & 0x1F) - 12 > 3 )
    goto LABEL_6;
  VObj = _this->value.VS._1.VObj;
  pObject = vm->TraitsNumber.pObject->ITraits.pObject;
  if ( !pObject->pConstructor.pObject )
    pObject->vfptr[3].~RefCountBaseGC<328>(pObject);
  if ( VObj == Scaleform::GFx::AS3::Class::GetPrototype(pObject->pConstructor.pObject) )
  {
    Scaleform::GFx::AS3::Value::SetNumber(result, 0.0);
  }
  else
  {
LABEL_6:
    if ( (_this->Flags & 0x1F) == 4 )
    {
      Scaleform::GFx::AS3::Value::Assign(result, _this);
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v12, eInvokeOnIncompatibleObjectError, vm);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v9, &Scaleform::GFx::AS3::fl::TypeErrorTI);
      pNode = v12.Message.pNode;
      if ( v12.Message.pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
  }
}

// File Line: 223
// RVA: 0x729630
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Number::toExponentialProto(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v12; // [rsp+30h] [rbp-48h] BYREF
  __int64 v13; // [rsp+40h] [rbp-38h]
  Scaleform::GFx::AS3::Value _thisa; // [rsp+48h] [rbp-30h] BYREF
  Scaleform::GFx::AS3::CheckResult v15; // [rsp+88h] [rbp+10h] BYREF

  v13 = -2i64;
  _thisa.Flags = 0;
  _thisa.Bonus.pWeakProxy = 0i64;
  if ( Scaleform::GFx::AS3::Value::Convert2Number(_this, &v15, (long double *)&v12)->Result )
  {
    _thisa.Flags = 4;
    _thisa.value = (Scaleform::GFx::AS3::Value::VU)v12;
    Scaleform::GFx::AS3::InstanceTraits::fl::Number::AS3toExponential(ti, vm, &_thisa, result, argc, argv);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v12, eCheckTypeFailedError, vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v9, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v12.Message.pNode;
    if ( v12.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 239
// RVA: 0x72A0D0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Number::toFixedProto(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v12; // [rsp+30h] [rbp-48h] BYREF
  __int64 v13; // [rsp+40h] [rbp-38h]
  Scaleform::GFx::AS3::Value _thisa; // [rsp+48h] [rbp-30h] BYREF
  Scaleform::GFx::AS3::CheckResult v15; // [rsp+88h] [rbp+10h] BYREF

  v13 = -2i64;
  _thisa.Flags = 0;
  _thisa.Bonus.pWeakProxy = 0i64;
  if ( Scaleform::GFx::AS3::Value::Convert2Number(_this, &v15, (long double *)&v12)->Result )
  {
    _thisa.Flags = 4;
    _thisa.value = (Scaleform::GFx::AS3::Value::VU)v12;
    Scaleform::GFx::AS3::InstanceTraits::fl::Number::AS3toFixed(ti, vm, &_thisa, result, argc, argv);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v12, eCheckTypeFailedError, vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v9, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v12.Message.pNode;
    if ( v12.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 255
// RVA: 0x72A9F0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Number::toPrecisionProto(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v12; // [rsp+30h] [rbp-48h] BYREF
  __int64 v13; // [rsp+40h] [rbp-38h]
  Scaleform::GFx::AS3::Value _thisa; // [rsp+48h] [rbp-30h] BYREF
  Scaleform::GFx::AS3::CheckResult v15; // [rsp+88h] [rbp+10h] BYREF

  v13 = -2i64;
  _thisa.Flags = 0;
  _thisa.Bonus.pWeakProxy = 0i64;
  if ( Scaleform::GFx::AS3::Value::Convert2Number(_this, &v15, (long double *)&v12)->Result )
  {
    _thisa.Flags = 4;
    _thisa.value = (Scaleform::GFx::AS3::Value::VU)v12;
    Scaleform::GFx::AS3::InstanceTraits::fl::Number::AS3toPrecision(ti, vm, &_thisa, result, argc, argv);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v12, eCheckTypeFailedError, vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v9, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v12.Message.pNode;
    if ( v12.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 308
// RVA: 0x780E60
void __fastcall Scaleform::GFx::AS3::Classes::fl::Number::Number(
        Scaleform::GFx::AS3::Classes::fl::Number *this,
        Scaleform::GFx::AS3::ClassTraits::Traits *t)
{
  Scaleform::GFx::AS3::Class::Class(this, t);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl::Number::`vftable;
  this->NaN = Scaleform::GFx::NumberUtil::NaN();
  this->NEGATIVE_INFINITY = Scaleform::GFx::NumberUtil::NEGATIVE_INFINITY();
  this->POSITIVE_INFINITY = Scaleform::GFx::NumberUtil::POSITIVE_INFINITY();
  this->MIN_VALUE = 2.225073858507201e-308;
  this->MAX_VALUE = 1.797693134862316e308;
}

// File Line: 314
// RVA: 0x7F4700
// positive sp value has been detected, the output may be wrong!
void __fastcall Scaleform::GFx::AS3::Classes::fl::Number::InitPrototype(
        Scaleform::GFx::AS3::Classes::fl::Number *this,
        Scaleform::GFx::AS3::Object *obj)
{
  __int64 v2; // rbx
  __int64 v3; // rdi
  void *v4; // rsi
  Scaleform::GFx::ASStringNode *v5; // r14
  Scaleform::GFx::AS3::Class *pObject; // rcx
  Scaleform::GFx::AS3::ThunkInfo *v9; // rbx
  __int64 v10; // rdi
  Scaleform::GFx::ASString *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  bool v13; // zf
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::ASStringNode *v16; // rcx
  unsigned int Size; // eax
  int v18; // [rsp+28h] [rbp-48h] BYREF
  Scaleform::GFx::ASStringNode *pNode; // [rsp+30h] [rbp-40h]
  Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef key; // [rsp+38h] [rbp-38h] BYREF
  int v21; // [rsp+48h] [rbp-28h] BYREF
  _DWORD *v22; // [rsp+50h] [rbp-20h]
  Scaleform::GFx::ASStringNode *v23; // [rsp+58h] [rbp-18h]
  __int64 v24; // [rsp+60h] [rbp-10h]
  char *v25; // [rsp+68h] [rbp-8h]
  char vars0; // [rsp+70h] [rbp+0h] BYREF
  __int64 anonymous1; // [rsp+80h] [rbp+10h]
  void *retaddr; // [rsp+88h] [rbp+18h]
  Scaleform::GFx::ASString result; // [rsp+90h] [rbp+20h] BYREF

  v25 = &vars0;
  v24 = v3;
  v23 = v5;
  anonymous1 = v2;
  retaddr = v4;
  pObject = this->ParentClass.pObject;
  if ( pObject )
    pObject->vfptr[7].Finalize_GC(pObject);
  v9 = Scaleform::GFx::AS3::Classes::fl::Number::ti;
  v10 = 6i64;
  do
  {
    Scaleform::GFx::AS3::Object::AddDynamicFunc(obj, v9++);
    --v10;
  }
  while ( v10 );
  v21 = 13;
  v22 = 0i64;
  v23 = (Scaleform::GFx::ASStringNode *)this;
  this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
  v11 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          this->pTraits.pObject->pVM->StringManagerRef,
          &result,
          "constructor");
  v18 = 1;
  pNode = v11->pNode;
  ++pNode->RefCount;
  key.pFirst = (Scaleform::GFx::AS3::Object::DynAttrsKey *)&v18;
  key.pSecond = (Scaleform::GFx::AS3::Value *)&v21;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
    &obj->DynAttrs.mHash,
    &obj->DynAttrs,
    &key);
  v12 = pNode;
  v13 = pNode->RefCount-- == 1;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  v14 = result.pNode;
  v13 = result.pNode->RefCount-- == 1;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  if ( (v21 & 0x1Fu) > 9 )
  {
    if ( (v21 & 0x200) != 0 )
    {
      v13 = (*v22)-- == 1;
      if ( v13 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v22 = 0i64;
      v23 = 0i64;
      v24 = 0i64;
      v21 &= 0xFFFFFDE0;
    }
    else
    {
      switch ( v21 & 0x1F )
      {
        case 0xA:
          v15 = v23;
          v13 = v23->RefCount-- == 1;
          if ( v13 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v15);
          break;
        case 0xB:
        case 0xC:
          v16 = v23;
          if ( ((unsigned __int8)v23 & 1) != 0 )
          {
            v23 = (Scaleform::GFx::ASStringNode *)((char *)v23 - 1);
          }
          else if ( v23 )
          {
            Size = v23->Size;
            if ( (Size & 0x3FFFFF) != 0 )
            {
              v23->Size = Size - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v16);
            }
          }
          break;
        default:
          return;
      }
    }
  }
}

// File Line: 330
// RVA: 0x7B8CC0
void __fastcall Scaleform::GFx::AS3::Classes::fl::Number::Construct(
        Scaleform::GFx::AS3::Classes::fl::Number *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::VM::Error *v6; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v; // [rsp+20h] [rbp-28h] BYREF
  __int64 v10; // [rsp+30h] [rbp-18h]
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+60h] [rbp+18h] BYREF

  v10 = -2i64;
  if ( argc )
  {
    if ( argc == 1 )
    {
      if ( Scaleform::GFx::AS3::Value::Convert2Number(argv, &resulta, (long double *)&v)->Result )
        Scaleform::GFx::AS3::Value::SetNumber(result, *(long double *)&v.ID);
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v, 1063, this->pTraits.pObject->pVM);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        this->pTraits.pObject->pVM,
        v6,
        &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
      pNode = v.Message.pNode;
      if ( v.Message.pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
  }
  else
  {
    Scaleform::GFx::AS3::Value::SetNumber(result, 0.0);
  }
}

// File Line: 368
// RVA: 0x72C2D0
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl::Number::MakeClassTraits(
        Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rbx
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> v8; // rbx
  Scaleform::GFx::AS3::Classes::fl::Number *v9; // rax

  MHeap = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)MHeap->vfptr->Alloc(MHeap, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, vm, &Scaleform::GFx::AS3::fl::NumberCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Number::`vftable;
    v6->TraitsType = Traits_Number;
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
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, vm, &Scaleform::GFx::AS3::fl::NumberCI);
    v8.pV->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
    v8.pV->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Number::`vftable;
    v8.pV->TraitsType = Traits_Number;
  }
  else
  {
    v8.pV = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(result->pV, v8);
  v9 = (Scaleform::GFx::AS3::Classes::fl::Number *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))MHeap->vfptr->Alloc)(
                                                     MHeap,
                                                     112i64);
  if ( v9 )
    Scaleform::GFx::AS3::Classes::fl::Number::Number(v9, result->pV);
  return result;
}

// File Line: 382
// RVA: 0x7B69C0
char __fastcall Scaleform::GFx::AS3::ClassTraits::fl::Number::Coerce(
        Scaleform::GFx::AS3::ClassTraits::fl::Number *this,
        Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::AS3::Value *result)
{
  long double v[3]; // [rsp+20h] [rbp-18h] BYREF
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+58h] [rbp+20h] BYREF

  if ( !Scaleform::GFx::AS3::Value::Convert2Number(value, &resulta, v)->Result )
    return 0;
  Scaleform::GFx::AS3::Value::SetNumber(result, v[0]);
  return 1;
}

