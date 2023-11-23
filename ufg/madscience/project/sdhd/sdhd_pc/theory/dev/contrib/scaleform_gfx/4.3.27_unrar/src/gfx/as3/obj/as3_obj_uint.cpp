// File Line: 48
// RVA: 0x15974F0
const char *dynamic_initializer_for__Scaleform::GFx::AS3::InstanceTraits::fl::uint::ti__()
{
  const char *result; // rax

  result = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::uint::ti[0].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::uint::ti[1].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::uint::ti[2].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::uint::ti[3].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::uint::ti[4].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  return result;
}

// File Line: 70
// RVA: 0x75ED00
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::uint::AS3toExponential(
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
    Scaleform::DoubleFormatter::DoubleFormatter(&v21, (double)_this->value.VS._1.VInt);
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

// File Line: 90
// RVA: 0x7A7780
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::uint::AS3toFixed(
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
    Scaleform::DoubleFormatter::DoubleFormatter(&v21, (double)_this->value.VS._1.VInt);
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

// File Line: 110
// RVA: 0x7A7C70
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::uint::AS3toPrecision(
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
    Scaleform::DoubleFormatter::DoubleFormatter(&v21, (double)_this->value.VS._1.VInt);
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

// File Line: 130
// RVA: 0x7A8670
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::uint::AS3toString(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Value *argc)
{
  Scaleform::GFx::AS3::VM::Error *v8; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v10; // zf
  Scaleform::GFx::AS3::VM::Error *v11; // rax
  Scaleform::GFx::ASString *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  unsigned int v14; // [rsp+18h] [rbp-49h] BYREF
  Scaleform::GFx::AS3::VM::Error v15; // [rsp+20h] [rbp-41h] BYREF
  Scaleform::StringDataPtr v16; // [rsp+30h] [rbp-31h] BYREF
  __int64 v17; // [rsp+40h] [rbp-21h]
  Scaleform::LongFormatter v18; // [rsp+48h] [rbp-19h] BYREF
  Scaleform::GFx::ASString resulta; // [rsp+C8h] [rbp+67h] BYREF
  int v20; // [rsp+D8h] [rbp+77h]

  v17 = -2i64;
  if ( (_this->Flags & 0x1F) - 2 > 1 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v15, 1004, vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v8, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    goto LABEL_3;
  }
  v14 = 10;
  if ( v20 && (argc->Flags & 0x1F) != 0 )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2UInt32(argc, (Scaleform::GFx::AS3::CheckResult *)&resulta, &v14)->Result )
      return;
    if ( v14 - 2 > 0xE )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v15, 1003, vm);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v11, &Scaleform::GFx::AS3::fl::RangeErrorTI);
LABEL_3:
      pNode = v15.Message.pNode;
      v10 = v15.Message.pNode->RefCount-- == 1;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      return;
    }
  }
  Scaleform::LongFormatter::LongFormatter(&v18, _this->value.VS._1.VUInt);
  *((_DWORD *)&v18 + 12) ^= ((unsigned __int8)v14 ^ *((_BYTE *)&v18 + 48)) & 0x1F;
  *((_BYTE *)&v18.Scaleform::NumericBase + 6) &= ~1u;
  ((void (__fastcall *)(Scaleform::LongFormatter *))v18.Scaleform::Formatter::Scaleform::FmtResource::vfptr[1].Reflect)(&v18);
  Scaleform::LongFormatter::GetResult(&v18, &v16);
  v12 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
          vm->StringManagerRef,
          &resulta,
          v16.pStr,
          v16.Size);
  Scaleform::GFx::AS3::Value::Assign(result, v12);
  v13 = resulta.pNode;
  v10 = resulta.pNode->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  v18.Scaleform::String::InitStruct::vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable;
  Scaleform::Formatter::~Formatter(&v18);
}

// File Line: 157
// RVA: 0x7A92E0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::uint::AS3valueOf(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::VM::Error *v5; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v8; // [rsp+28h] [rbp-20h] BYREF

  if ( (_this->Flags & 0x1F) - 2 <= 1 )
  {
    Scaleform::GFx::AS3::Value::SetUInt32(result, _this->value.VS._1.VUInt);
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

// File Line: 169
// RVA: 0x761A40
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::uint::toStringProto(
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
  pObject = vm->TraitsUint.pObject->ITraits.pObject;
  VObj = _this->value.VS._1.VObj;
  if ( !pObject->pConstructor.pObject )
    pObject->vfptr[3].~RefCountBaseGC<328>(pObject);
  if ( VObj == Scaleform::GFx::AS3::Class::GetPrototype(pObject->pConstructor.pObject) )
    Scaleform::GFx::AS3::Value::Assign(result, (Scaleform::GFx::ASString *)&vm->StringManagerRef->Builtins[15]);
  else
LABEL_6:
    Scaleform::GFx::AS3::InstanceTraits::fl::uint::AS3toString(ti, vm, _this, result, argc, argv);
}

// File Line: 179
// RVA: 0x761EB0
// attributes: thunk
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::uint::toLocaleStringProto(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::InstanceTraits::fl::uint::toStringProto(ti, vm, _this, result, argc, argv);
}

// File Line: 185
// RVA: 0x762770
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::uint::valueOfProto(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Object *VObj; // r14
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // rdi
  int VInt; // edx
  Scaleform::GFx::AS3::VM::Error *v10; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v13; // [rsp+28h] [rbp-20h] BYREF

  if ( (_this->Flags & 0x1F) - 12 <= 3 )
  {
    VObj = _this->value.VS._1.VObj;
    pObject = vm->TraitsUint.pObject->ITraits.pObject;
    if ( !pObject->pConstructor.pObject )
      pObject->vfptr[3].~RefCountBaseGC<328>(pObject);
    if ( VObj == Scaleform::GFx::AS3::Class::GetPrototype(pObject->pConstructor.pObject) )
    {
      VInt = 0;
LABEL_10:
      Scaleform::GFx::AS3::Value::SetUInt32(result, VInt);
      return;
    }
  }
  if ( (_this->Flags & 0x1F) - 2 <= 1 )
  {
    VInt = _this->value.VS._1.VInt;
    goto LABEL_10;
  }
  Scaleform::GFx::AS3::VM::Error::Error(&v13, eInvokeOnIncompatibleObjectError, vm);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v10, &Scaleform::GFx::AS3::fl::TypeErrorTI);
  pNode = v13.Message.pNode;
  if ( v13.Message.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 195
// RVA: 0x762EC0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::uint::toExponentialProto(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::ErrorID v12; // [rsp+30h] [rbp-48h] BYREF
  __int64 v13; // [rsp+38h] [rbp-40h]
  Scaleform::GFx::AS3::VM::Error v14; // [rsp+40h] [rbp-38h] BYREF
  Scaleform::GFx::AS3::Value _thisa; // [rsp+50h] [rbp-28h] BYREF
  Scaleform::GFx::AS3::CheckResult v16; // [rsp+88h] [rbp+10h] BYREF

  v13 = -2i64;
  _thisa.Flags = 0;
  _thisa.Bonus.pWeakProxy = 0i64;
  if ( Scaleform::GFx::AS3::Value::Convert2UInt32(_this, &v16, (unsigned int *)&v12)->Result )
  {
    _thisa.Flags = 3;
    v14.ID = v12;
    _thisa.value = (Scaleform::GFx::AS3::Value::VU)v14;
    Scaleform::GFx::AS3::InstanceTraits::fl::uint::AS3toExponential(ti, vm, &_thisa, result, argc, argv);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v14, eCheckTypeFailedError, vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v9, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v14.Message.pNode;
    if ( v14.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 211
// RVA: 0x7635A0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::uint::toFixedProto(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::ErrorID v12; // [rsp+30h] [rbp-48h] BYREF
  __int64 v13; // [rsp+38h] [rbp-40h]
  Scaleform::GFx::AS3::VM::Error v14; // [rsp+40h] [rbp-38h] BYREF
  Scaleform::GFx::AS3::Value _thisa; // [rsp+50h] [rbp-28h] BYREF
  Scaleform::GFx::AS3::CheckResult v16; // [rsp+88h] [rbp+10h] BYREF

  v13 = -2i64;
  _thisa.Flags = 0;
  _thisa.Bonus.pWeakProxy = 0i64;
  if ( Scaleform::GFx::AS3::Value::Convert2UInt32(_this, &v16, (unsigned int *)&v12)->Result )
  {
    _thisa.Flags = 3;
    v14.ID = v12;
    _thisa.value = (Scaleform::GFx::AS3::Value::VU)v14;
    Scaleform::GFx::AS3::InstanceTraits::fl::uint::AS3toFixed(ti, vm, &_thisa, result, argc, argv);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v14, eCheckTypeFailedError, vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v9, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v14.Message.pNode;
    if ( v14.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 227
// RVA: 0x763D30
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::uint::toPrecisionProto(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::ErrorID v12; // [rsp+30h] [rbp-48h] BYREF
  __int64 v13; // [rsp+38h] [rbp-40h]
  Scaleform::GFx::AS3::VM::Error v14; // [rsp+40h] [rbp-38h] BYREF
  Scaleform::GFx::AS3::Value _thisa; // [rsp+50h] [rbp-28h] BYREF
  Scaleform::GFx::AS3::CheckResult v16; // [rsp+88h] [rbp+10h] BYREF

  v13 = -2i64;
  _thisa.Flags = 0;
  _thisa.Bonus.pWeakProxy = 0i64;
  if ( Scaleform::GFx::AS3::Value::Convert2UInt32(_this, &v16, (unsigned int *)&v12)->Result )
  {
    _thisa.Flags = 3;
    v14.ID = v12;
    _thisa.value = (Scaleform::GFx::AS3::Value::VU)v14;
    Scaleform::GFx::AS3::InstanceTraits::fl::uint::AS3toPrecision(ti, vm, &_thisa, result, argc, argv);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v14, eCheckTypeFailedError, vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v9, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v14.Message.pNode;
    if ( v14.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 283
// RVA: 0x7F50F0
void __fastcall Scaleform::GFx::AS3::Classes::fl::uint::InitPrototype(
        Scaleform::GFx::AS3::Classes::fl::uint *this,
        Scaleform::GFx::AS3::Object *obj)
{
  Scaleform::GFx::AS3::Class *pObject; // rcx
  Scaleform::GFx::AS3::ThunkInfo *v5; // rbx
  __int64 v6; // rdi
  Scaleform::GFx::ASString *v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::ASStringNode *v10; // rcx
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v12; // rcx
  unsigned int RefCount; // eax
  int v14; // [rsp+28h] [rbp-48h] BYREF
  Scaleform::GFx::ASStringNode *pNode; // [rsp+30h] [rbp-40h]
  Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef key; // [rsp+38h] [rbp-38h] BYREF
  int v17; // [rsp+48h] [rbp-28h] BYREF
  _DWORD *v18; // [rsp+50h] [rbp-20h]
  Scaleform::GFx::ASStringNode *v19; // [rsp+58h] [rbp-18h]
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v20; // [rsp+60h] [rbp-10h]
  Scaleform::GFx::ASString result; // [rsp+90h] [rbp+20h] BYREF

  pObject = this->ParentClass.pObject;
  if ( pObject )
    pObject->vfptr[7].Finalize_GC(pObject);
  v5 = Scaleform::GFx::AS3::Classes::fl::uint::ti;
  v6 = 6i64;
  do
  {
    Scaleform::GFx::AS3::Object::AddDynamicFunc(obj, v5++);
    --v6;
  }
  while ( v6 );
  v17 = 13;
  v18 = 0i64;
  v19 = (Scaleform::GFx::ASStringNode *)this;
  this->RefCount = (this->RefCount + 1) & 0x8FBFFFFF;
  v7 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
         this->pTraits.pObject->pVM->StringManagerRef,
         &result,
         "constructor");
  v14 = 1;
  pNode = v7->pNode;
  ++pNode->RefCount;
  key.pFirst = (Scaleform::GFx::AS3::Object::DynAttrsKey *)&v14;
  key.pSecond = (Scaleform::GFx::AS3::Value *)&v17;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
    &obj->DynAttrs.mHash,
    &obj->DynAttrs,
    &key);
  v8 = pNode;
  v9 = pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  v10 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  if ( (v17 & 0x1Fu) > 9 )
  {
    if ( (v17 & 0x200) != 0 )
    {
      v9 = (*v18)-- == 1;
      if ( v9 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v18 = 0i64;
      v19 = 0i64;
      v20 = 0i64;
      v17 &= 0xFFFFFDE0;
    }
    else
    {
      switch ( v17 & 0x1F )
      {
        case 0xA:
          v11 = v19;
          v9 = v19->RefCount-- == 1;
          if ( v9 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v11);
          break;
        case 0xB:
        case 0xC:
        case 0xD:
        case 0xE:
        case 0xF:
          v12 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v19;
          if ( ((unsigned __int8)v19 & 1) == 0 )
            goto LABEL_21;
          v19 = (Scaleform::GFx::ASStringNode *)((char *)v19 - 1);
          break;
        case 0x10:
        case 0x11:
          v12 = v20;
          if ( ((unsigned __int8)v20 & 1) != 0 )
          {
            v20 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v20 - 1);
          }
          else
          {
LABEL_21:
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
          return;
      }
    }
  }
}

// File Line: 299
// RVA: 0x7B95F0
void __fastcall Scaleform::GFx::AS3::Classes::fl::uint::Construct(
        Scaleform::GFx::AS3::Classes::fl::uint *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  unsigned int v[6]; // [rsp+20h] [rbp-18h] BYREF
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+50h] [rbp+18h] BYREF

  if ( argc )
  {
    if ( Scaleform::GFx::AS3::Value::Convert2UInt32(argv, &resulta, v)->Result )
      Scaleform::GFx::AS3::Value::SetUInt32(result, v[0]);
  }
  else
  {
    Scaleform::GFx::AS3::Value::SetUInt32(result, 0);
  }
}

// File Line: 333
// RVA: 0x7662C0
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl::uint::MakeClassTraits(
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
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, vm, &Scaleform::GFx::AS3::fl::uintCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::uint::`vftable;
    v6->TraitsType = Traits_UInt;
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
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, vm, &Scaleform::GFx::AS3::fl::uintCI);
    v8.pV->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
    v8.pV->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::uint::`vftable;
    v8.pV->TraitsType = Traits_UInt;
  }
  else
  {
    v8.pV = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(result->pV, v8);
  v9 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))MHeap->vfptr->Alloc)(
                                       MHeap,
                                       80i64);
  v10 = v9;
  if ( v9 )
  {
    Scaleform::GFx::AS3::Class::Class(v9, result->pV);
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl::uint::`vftable;
    LODWORD(v10[1].vfptr) = 0;
    HIDWORD(v10[1].vfptr) = -1;
  }
  return result;
}

// File Line: 347
// RVA: 0x7B6B60
char __fastcall Scaleform::GFx::AS3::ClassTraits::fl::uint::Coerce(
        Scaleform::GFx::AS3::ClassTraits::fl::uint *this,
        Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::AS3::Value *result)
{
  unsigned int v[6]; // [rsp+20h] [rbp-18h] BYREF
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+58h] [rbp+20h] BYREF

  if ( !Scaleform::GFx::AS3::Value::Convert2UInt32(value, &resulta, v)->Result )
    return 0;
  Scaleform::GFx::AS3::Value::SetUInt32(result, v[0]);
  return 1;
}

