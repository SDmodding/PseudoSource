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
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Number::AS3toExponential(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v6; // rsi
  Scaleform::GFx::AS3::Value *v7; // rbx
  Scaleform::GFx::AS3::VM *v8; // rdi
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  const char *v12; // rbx
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *v13; // rdi
  SSExpressionBase *v14; // rax
  Scaleform::GFx::ASString *v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rcx
  unsigned int resulta; // [rsp+20h] [rbp-1E8h]
  Scaleform::GFx::AS3::VM::Error v18; // [rsp+28h] [rbp-1E0h]
  __int64 v19; // [rsp+38h] [rbp-1D0h]
  Scaleform::StringDataPtr v20; // [rsp+40h] [rbp-1C8h]
  Scaleform::DoubleFormatter v21; // [rsp+50h] [rbp-1B8h]

  v19 = -2i64;
  v6 = result;
  v7 = _this;
  v8 = vm;
  resulta = 0;
  if ( !argc )
    goto LABEL_11;
  if ( !Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&argc, &resulta)->Result )
    return;
  if ( resulta > 0x14 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v18, eInvalidPrecisionError, v8);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v8, v9, &Scaleform::GFx::AS3::fl::RangeErrorTI);
    v10 = v18.Message.pNode;
    v11 = v18.Message.pNode->RefCount == 1;
    --v10->RefCount;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  }
  else
  {
LABEL_11:
    Scaleform::DoubleFormatter::DoubleFormatter(&v21, v7->value.VNumber);
    v21.Type = 1;
    *(_DWORD *)&v21.32 ^= ((unsigned __int8)resulta ^ *(_BYTE *)&v21.32) & 0x1F;
    ((void (__fastcall *)(Scaleform::DoubleFormatter *))v21.vfptr[1].Reflect)(&v21);
    v12 = Scaleform::LongFormatter::GetResult((Scaleform::LongFormatter *)&v21, &v20)->pStr;
    v13 = (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v8->StringManagerRef->Builtins;
    v14 = Scaleform::GFx::MovieImpl::GetHeap((SSClosureInfoMethod *)&v21);
    v15 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
            v13,
            (Scaleform::GFx::ASString *)&v18,
            v12,
            (unsigned __int64)v14);
    Scaleform::GFx::AS3::Value::Assign(v6, v15);
    v16 = *(Scaleform::GFx::ASStringNode **)&v18.ID;
    v11 = *(_DWORD *)(*(_QWORD *)&v18.ID + 24i64) == 1;
    --v16->RefCount;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v16);
    v21.vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable';
    Scaleform::Formatter::~Formatter((Scaleform::Formatter *)&v21.vfptr);
  }
}

// File Line: 94
// RVA: 0x7A74C0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Number::AS3toFixed(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v6; // rsi
  Scaleform::GFx::AS3::Value *v7; // rbx
  Scaleform::GFx::AS3::VM *v8; // rdi
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  const char *v12; // rbx
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *v13; // rdi
  SSExpressionBase *v14; // rax
  Scaleform::GFx::ASString *v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rcx
  unsigned int resulta; // [rsp+20h] [rbp-1E8h]
  Scaleform::GFx::AS3::VM::Error v18; // [rsp+28h] [rbp-1E0h]
  __int64 v19; // [rsp+38h] [rbp-1D0h]
  Scaleform::StringDataPtr v20; // [rsp+40h] [rbp-1C8h]
  Scaleform::DoubleFormatter v21; // [rsp+50h] [rbp-1B8h]

  v19 = -2i64;
  v6 = result;
  v7 = _this;
  v8 = vm;
  resulta = 0;
  if ( !argc )
    goto LABEL_11;
  if ( !Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&argc, &resulta)->Result )
    return;
  if ( resulta > 0x14 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v18, eInvalidPrecisionError, v8);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v8, v9, &Scaleform::GFx::AS3::fl::RangeErrorTI);
    v10 = v18.Message.pNode;
    v11 = v18.Message.pNode->RefCount == 1;
    --v10->RefCount;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  }
  else
  {
LABEL_11:
    Scaleform::DoubleFormatter::DoubleFormatter(&v21, v7->value.VNumber);
    v21.Type = 0;
    *(_DWORD *)&v21.32 ^= ((unsigned __int8)resulta ^ *(_BYTE *)&v21.32) & 0x1F;
    ((void (__fastcall *)(Scaleform::DoubleFormatter *))v21.vfptr[1].Reflect)(&v21);
    v12 = Scaleform::LongFormatter::GetResult((Scaleform::LongFormatter *)&v21, &v20)->pStr;
    v13 = (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v8->StringManagerRef->Builtins;
    v14 = Scaleform::GFx::MovieImpl::GetHeap((SSClosureInfoMethod *)&v21);
    v15 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
            v13,
            (Scaleform::GFx::ASString *)&v18,
            v12,
            (unsigned __int64)v14);
    Scaleform::GFx::AS3::Value::Assign(v6, v15);
    v16 = *(Scaleform::GFx::ASStringNode **)&v18.ID;
    v11 = *(_DWORD *)(*(_QWORD *)&v18.ID + 24i64) == 1;
    --v16->RefCount;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v16);
    v21.vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable';
    Scaleform::Formatter::~Formatter((Scaleform::Formatter *)&v21.vfptr);
  }
}

// File Line: 114
// RVA: 0x7A79B0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Number::AS3toPrecision(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v6; // rsi
  Scaleform::GFx::AS3::Value *v7; // rbx
  Scaleform::GFx::AS3::VM *v8; // rdi
  const char *v9; // rbx
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *v10; // rdi
  SSExpressionBase *v11; // rax
  Scaleform::GFx::ASString *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  bool v14; // zf
  Scaleform::GFx::AS3::VM::Error *v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rcx
  unsigned int resulta; // [rsp+20h] [rbp-1E8h]
  Scaleform::GFx::ASString v18; // [rsp+28h] [rbp-1E0h]
  Scaleform::GFx::ASStringNode *v19; // [rsp+30h] [rbp-1D8h]
  __int64 v20; // [rsp+38h] [rbp-1D0h]
  Scaleform::StringDataPtr v21; // [rsp+40h] [rbp-1C8h]
  Scaleform::DoubleFormatter v22; // [rsp+50h] [rbp-1B8h]

  v20 = -2i64;
  v6 = result;
  v7 = _this;
  v8 = vm;
  resulta = 0;
  if ( !argc )
    goto LABEL_11;
  if ( !Scaleform::GFx::AS3::Value::Convert2UInt32(argv, (Scaleform::GFx::AS3::CheckResult *)&argc, &resulta)->Result )
    return;
  if ( resulta - 1 <= 0x14 )
  {
    Scaleform::DoubleFormatter::DoubleFormatter(&v22, v7->value.VNumber);
    v22.Type = 2;
    *(_DWORD *)&v22.32 ^= ((unsigned __int8)resulta ^ *(_BYTE *)&v22.32) & 0x1F;
    ((void (__fastcall *)(Scaleform::DoubleFormatter *))v22.vfptr[1].Reflect)(&v22);
    v9 = Scaleform::LongFormatter::GetResult((Scaleform::LongFormatter *)&v22, &v21)->pStr;
    v10 = (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v8->StringManagerRef->Builtins;
    v11 = Scaleform::GFx::MovieImpl::GetHeap((SSClosureInfoMethod *)&v22);
    v12 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
            v10,
            &v18,
            v9,
            (unsigned __int64)v11);
    Scaleform::GFx::AS3::Value::Assign(v6, v12);
    v13 = v18.pNode;
    v14 = v18.pNode->RefCount == 1;
    --v13->RefCount;
    if ( v14 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    v22.vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable';
    Scaleform::Formatter::~Formatter((Scaleform::Formatter *)&v22.vfptr);
  }
  else
  {
LABEL_11:
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v18, eInvalidPrecisionError, v8);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v8, v15, &Scaleform::GFx::AS3::fl::RangeErrorTI);
    v16 = v19;
    v14 = v19->RefCount == 1;
    --v16->RefCount;
    if ( v14 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  }
}

// File Line: 134
// RVA: 0x7A7FA0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Number::AS3toString(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result, unsigned int argc)
{
  Scaleform::GFx::AS3::Value *v5; // rsi
  Scaleform::GFx::AS3::Value *v6; // rdi
  Scaleform::GFx::AS3::VM *v7; // rbx
  unsigned int v8; // ecx
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rcx
  Scaleform::GFx::AS3::VM::Error *v11; // rax
  long double v12; // xmm2_8
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  bool v15; // zf
  unsigned __int64 v16; // rax
  Scaleform::GFx::ASString *v17; // rax
  unsigned int v18; // [rsp+18h] [rbp-69h]
  int v; // [rsp+1Ch] [rbp-65h]
  Scaleform::GFx::AS3::VM::Error v20; // [rsp+20h] [rbp-61h]
  __int64 v21; // [rsp+30h] [rbp-51h]
  Scaleform::LongFormatter v22; // [rsp+38h] [rbp-49h]
  char buffer; // [rsp+98h] [rbp+17h]
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+E8h] [rbp+67h]
  int v25; // [rsp+F8h] [rbp+77h]

  v21 = -2i64;
  v5 = result;
  v6 = _this;
  v7 = vm;
  v8 = 10;
  v18 = 10;
  if ( (_this->Flags & 0x1F) != 4 )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v20, eInvokeOnIncompatibleObjectError, vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v7, v9, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v10 = v20.Message.pNode;
    goto LABEL_15;
  }
  if ( v25 && **(_BYTE **)&argc & 0x1F )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2UInt32(*(Scaleform::GFx::AS3::Value **)&argc, &resulta, &v18)->Result )
      return;
    v8 = v18;
    if ( v18 - 2 > 0x22 )
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v20, eInvalidRadixError, v7);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v7, v11, &Scaleform::GFx::AS3::fl::RangeErrorTI);
      v10 = v20.Message.pNode;
      goto LABEL_15;
    }
  }
  v12 = v6->value.VNumber;
  if ( v8 == 10
    || (*(long double *)&resulta.Result = v6->value.VNumber,
        (*(_QWORD *)&v12 & 0x7FF0000000000000i64) == 9218868437227405312i64) )
  {
    v16 = Scaleform::GFx::AS3::SF_ECMA_dtostr(&buffer, 40, v12);
    v17 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
            (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v7->StringManagerRef->Builtins,
            (Scaleform::GFx::ASString *)&resulta,
            &buffer,
            v16);
    Scaleform::GFx::AS3::Value::Assign(v5, v17);
    v10 = *(Scaleform::GFx::ASStringNode **)&resulta.Result;
LABEL_15:
    v15 = v10->RefCount-- == 1;
    if ( v15 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
    return;
  }
  if ( Scaleform::GFx::AS3::Value::Convert2Int32(v6, &resulta, &v)->Result )
  {
    Scaleform::LongFormatter::LongFormatter(&v22, v);
    *((_DWORD *)&v22 + 12) ^= ((unsigned __int8)v18 ^ *((_BYTE *)&v22 + 48)) & 0x1F;
    *((_BYTE *)&v22.32 + 6) &= 0xFEu;
    ((void (__fastcall *)(Scaleform::LongFormatter *))v22.vfptr[1].Reflect)(&v22);
    Scaleform::LongFormatter::GetResult(&v22, (Scaleform::StringDataPtr *)&v20);
    v13 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
            (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v7->StringManagerRef->Builtins,
            (Scaleform::GFx::ASString *)&resulta,
            *(const char **)&v20.ID,
            (unsigned __int64)v20.Message.pNode);
    Scaleform::GFx::AS3::Value::Assign(v5, v13);
    v14 = *(Scaleform::GFx::ASStringNode **)&resulta.Result;
    v15 = *(_DWORD *)(*(_QWORD *)&resulta.Result + 24i64) == 1;
    --v14->RefCount;
    if ( v15 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
    v22.vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable';
    Scaleform::Formatter::~Formatter((Scaleform::Formatter *)&v22.vfptr);
  }
}

// File Line: 177
// RVA: 0x7A7990
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Number::AS3toLocaleString(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::InstanceTraits::fl::Number::AS3toString(ti, vm, _this, result, argc, argv);
}

// File Line: 183
// RVA: 0x7A91F0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Number::AS3valueOf(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::VM *v4; // rbx
  Scaleform::GFx::AS3::VM::Error *v5; // rax
  Scaleform::GFx::ASStringNode *v6; // rcx
  bool v7; // zf
  Scaleform::GFx::AS3::VM::Error v8; // [rsp+28h] [rbp-20h]

  v4 = vm;
  if ( (_this->Flags & 0x1F) == 4 )
  {
    Scaleform::GFx::AS3::Value::Assign(result, _this);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v8, eInvokeOnIncompatibleObjectError, vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v4, v5, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v6 = v8.Message.pNode;
    v7 = v8.Message.pNode->RefCount == 1;
    --v6->RefCount;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  }
}

// File Line: 197
// RVA: 0x728150
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Number::toStringProto(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v6; // rbp
  Scaleform::GFx::AS3::Value *v7; // rsi
  Scaleform::GFx::AS3::VM *v8; // rdi
  Scaleform::GFx::AS3::ThunkInfo *v9; // r15
  Scaleform::GFx::AS3::InstanceTraits::Traits *v10; // rbx
  long double v11; // r14

  v6 = result;
  v7 = _this;
  v8 = vm;
  v9 = ti;
  if ( (_this->Flags & 0x1F) - 12 > 3 )
    goto LABEL_9;
  v10 = vm->TraitsNumber.pObject->ITraits.pObject;
  v11 = _this->value.VNumber;
  if ( !v10->pConstructor.pObject )
    v10->vfptr[3].~RefCountBaseGC<328>((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v10->vfptr);
  if ( *(Scaleform::GFx::AS3::Object **)&v11 != Scaleform::GFx::AS3::Class::GetPrototype(v10->pConstructor.pObject) )
LABEL_9:
    Scaleform::GFx::AS3::InstanceTraits::fl::Number::AS3toString(v9, v8, v7, v6, argc, argv);
  else
    Scaleform::GFx::AS3::Value::Assign(v6, (Scaleform::GFx::ASString *)&v8->StringManagerRef->Builtins[15]);
}

// File Line: 207
// RVA: 0x728A60
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Number::toLocaleStringProto(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::InstanceTraits::fl::Number::toStringProto(ti, vm, _this, result, argc, argv);
}

// File Line: 213
// RVA: 0x728F70
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Number::valueOfProto(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value *v4; // rsi
  Scaleform::GFx::AS3::Value *v5; // rbx
  Scaleform::GFx::AS3::VM *v6; // rbp
  long double v7; // r14
  Scaleform::GFx::AS3::InstanceTraits::Traits *v8; // rdi
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  Scaleform::GFx::AS3::VM::Error v12; // [rsp+28h] [rbp-20h]

  v4 = result;
  v5 = _this;
  v6 = vm;
  if ( (_this->Flags & 0x1F) - 12 > 3 )
    goto LABEL_12;
  v7 = _this->value.VNumber;
  v8 = vm->TraitsNumber.pObject->ITraits.pObject;
  if ( !v8->pConstructor.pObject )
    v8->vfptr[3].~RefCountBaseGC<328>((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v8->vfptr);
  if ( *(Scaleform::GFx::AS3::Object **)&v7 != Scaleform::GFx::AS3::Class::GetPrototype(v8->pConstructor.pObject) )
  {
LABEL_12:
    if ( (v5->Flags & 0x1F) == 4 )
    {
      Scaleform::GFx::AS3::Value::Assign(v4, v5);
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v12, eInvokeOnIncompatibleObjectError, v6);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(v6, v9, &Scaleform::GFx::AS3::fl::TypeErrorTI);
      v10 = v12.Message.pNode;
      v11 = v12.Message.pNode->RefCount == 1;
      --v10->RefCount;
      if ( v11 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v10);
    }
  }
  else
  {
    Scaleform::GFx::AS3::Value::SetNumber(v4, 0.0);
  }
}

// File Line: 223
// RVA: 0x729630
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Number::toExponentialProto(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v6; // rdi
  Scaleform::GFx::AS3::VM *v7; // rbx
  Scaleform::GFx::AS3::ThunkInfo *v8; // rsi
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  Scaleform::GFx::AS3::VM::Error v12; // [rsp+30h] [rbp-48h]
  __int64 v13; // [rsp+40h] [rbp-38h]
  Scaleform::GFx::AS3::Value _thisa; // [rsp+48h] [rbp-30h]
  __int64 v15; // [rsp+88h] [rbp+10h]

  v13 = -2i64;
  v6 = result;
  v7 = vm;
  v8 = ti;
  _thisa.Flags = 0;
  _thisa.Bonus.pWeakProxy = 0i64;
  if ( Scaleform::GFx::AS3::Value::Convert2Number(_this, (Scaleform::GFx::AS3::CheckResult *)&v15, (long double *)&v12)->Result )
  {
    _thisa.Flags = 4;
    _thisa.value = (Scaleform::GFx::AS3::Value::VU)v12;
    Scaleform::GFx::AS3::InstanceTraits::fl::Number::AS3toExponential(v8, v7, &_thisa, v6, argc, argv);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v12, eCheckTypeFailedError, v7);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v7, v9, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v10 = v12.Message.pNode;
    v11 = v12.Message.pNode->RefCount == 1;
    --v10->RefCount;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  }
}

// File Line: 239
// RVA: 0x72A0D0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Number::toFixedProto(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v6; // rdi
  Scaleform::GFx::AS3::VM *v7; // rbx
  Scaleform::GFx::AS3::ThunkInfo *v8; // rsi
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  Scaleform::GFx::AS3::VM::Error v12; // [rsp+30h] [rbp-48h]
  __int64 v13; // [rsp+40h] [rbp-38h]
  Scaleform::GFx::AS3::Value _thisa; // [rsp+48h] [rbp-30h]
  __int64 v15; // [rsp+88h] [rbp+10h]

  v13 = -2i64;
  v6 = result;
  v7 = vm;
  v8 = ti;
  _thisa.Flags = 0;
  _thisa.Bonus.pWeakProxy = 0i64;
  if ( Scaleform::GFx::AS3::Value::Convert2Number(_this, (Scaleform::GFx::AS3::CheckResult *)&v15, (long double *)&v12)->Result )
  {
    _thisa.Flags = 4;
    _thisa.value = (Scaleform::GFx::AS3::Value::VU)v12;
    Scaleform::GFx::AS3::InstanceTraits::fl::Number::AS3toFixed(v8, v7, &_thisa, v6, argc, argv);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v12, eCheckTypeFailedError, v7);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v7, v9, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v10 = v12.Message.pNode;
    v11 = v12.Message.pNode->RefCount == 1;
    --v10->RefCount;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  }
}

// File Line: 255
// RVA: 0x72A9F0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::Number::toPrecisionProto(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v6; // rdi
  Scaleform::GFx::AS3::VM *v7; // rbx
  Scaleform::GFx::AS3::ThunkInfo *v8; // rsi
  Scaleform::GFx::AS3::VM::Error *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  Scaleform::GFx::AS3::VM::Error v12; // [rsp+30h] [rbp-48h]
  __int64 v13; // [rsp+40h] [rbp-38h]
  Scaleform::GFx::AS3::Value _thisa; // [rsp+48h] [rbp-30h]
  __int64 v15; // [rsp+88h] [rbp+10h]

  v13 = -2i64;
  v6 = result;
  v7 = vm;
  v8 = ti;
  _thisa.Flags = 0;
  _thisa.Bonus.pWeakProxy = 0i64;
  if ( Scaleform::GFx::AS3::Value::Convert2Number(_this, (Scaleform::GFx::AS3::CheckResult *)&v15, (long double *)&v12)->Result )
  {
    _thisa.Flags = 4;
    _thisa.value = (Scaleform::GFx::AS3::Value::VU)v12;
    Scaleform::GFx::AS3::InstanceTraits::fl::Number::AS3toPrecision(v8, v7, &_thisa, v6, argc, argv);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v12, eCheckTypeFailedError, v7);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v7, v9, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v10 = v12.Message.pNode;
    v11 = v12.Message.pNode->RefCount == 1;
    --v10->RefCount;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  }
}

// File Line: 308
// RVA: 0x780E60
void __fastcall Scaleform::GFx::AS3::Classes::fl::Number::Number(Scaleform::GFx::AS3::Classes::fl::Number *this, Scaleform::GFx::AS3::ClassTraits::Traits *t)
{
  Scaleform::GFx::AS3::Classes::fl::Number *v2; // rbx

  v2 = this;
  Scaleform::GFx::AS3::Class::Class((Scaleform::GFx::AS3::Class *)&this->vfptr, t);
  v2->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl::Number::`vftable';
  v2->NaN = Scaleform::GFx::NumberUtil::NaN();
  v2->NEGATIVE_INFINITY = Scaleform::GFx::NumberUtil::NEGATIVE_INFINITY();
  v2->POSITIVE_INFINITY = Scaleform::GFx::NumberUtil::POSITIVE_INFINITY();
  v2->MIN_VALUE = 2.225073858507201e-308;
  v2->MAX_VALUE = 1.797693134862316e308;
}

// File Line: 314
// RVA: 0x7F4700
void __fastcall Scaleform::GFx::AS3::Classes::fl::Number::InitPrototype(Scaleform::GFx::AS3::Classes::fl::Number *this, Scaleform::GFx::AS3::Object *obj)
{
  Scaleform::GFx::AS3::Object *v2; // rsi
  Scaleform::GFx::ASStringNode *v3; // r14
  Scaleform::GFx::AS3::Class *v4; // rcx
  Scaleform::GFx::AS3::ThunkInfo *v5; // rbx
  signed __int64 v6; // rdi
  Scaleform::GFx::ASString *v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::ASStringNode *v10; // rcx
  int v11; // eax
  _DWORD *v12; // rdx
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v14; // rcx
  unsigned int v15; // eax
  int v16; // [rsp+28h] [rbp-48h]
  Scaleform::GFx::ASStringNode *v17; // [rsp+30h] [rbp-40h]
  Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef key; // [rsp+38h] [rbp-38h]
  unsigned int v19; // [rsp+48h] [rbp-28h]
  _DWORD *v20; // [rsp+50h] [rbp-20h]
  Scaleform::GFx::ASStringNode *v21; // [rsp+58h] [rbp-18h]
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v22; // [rsp+60h] [rbp-10h]
  Scaleform::GFx::ASString result; // [rsp+90h] [rbp+20h]

  v2 = obj;
  v3 = (Scaleform::GFx::ASStringNode *)this;
  v4 = this->ParentClass.pObject;
  if ( v4 )
    ((void (__cdecl *)(Scaleform::GFx::AS3::Class *))v4->vfptr[7].Finalize_GC)(v4);
  v5 = Scaleform::GFx::AS3::Classes::fl::Number::ti;
  v6 = 6i64;
  do
  {
    Scaleform::GFx::AS3::Object::AddDynamicFunc(v2, v5);
    ++v5;
    --v6;
  }
  while ( v6 );
  v19 = 13;
  v20 = 0i64;
  v21 = v3;
  v3->Size = (v3->Size + 1) & 0x8FBFFFFF;
  v7 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
         *(Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> **)(*((_QWORD *)v3[1].pData
                                                                                                 + 16)
                                                                                               + 16i64),
         &result,
         "constructor");
  v16 = 1;
  v17 = v7->pNode;
  ++v17->RefCount;
  key.pFirst = (Scaleform::GFx::AS3::Object::DynAttrsKey *)&v16;
  key.pSecond = (Scaleform::GFx::AS3::Value *)&v19;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeRef>(
    (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> > *)&v2->DynAttrs.mHash.pTable,
    &v2->DynAttrs,
    &key);
  v8 = v17;
  v9 = v17->RefCount == 1;
  --v8->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  v10 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v10->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  v11 = v19 & 0x1F;
  if ( v11 > 9 )
  {
    if ( (v19 >> 9) & 1 )
    {
      v12 = v20;
      v9 = *v20 == 1;
      --*v12;
      if ( v9 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *, _DWORD *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v12);
      v20 = 0i64;
      v21 = 0i64;
      v22 = 0i64;
      v19 &= 0xFFFFFDE0;
    }
    else
    {
      switch ( v11 )
      {
        case 10:
          v13 = v21;
          v9 = v21->RefCount == 1;
          --v13->RefCount;
          if ( v9 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v13);
          break;
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
          v14 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v21;
          if ( !((unsigned __int8)v21 & 1) )
            goto LABEL_21;
          v21 = (Scaleform::GFx::ASStringNode *)((char *)v21 - 1);
          break;
        case 16:
        case 17:
          v14 = v22;
          if ( (unsigned __int8)v22 & 1 )
          {
            v22 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v22 - 1);
          }
          else
          {
LABEL_21:
            if ( v14 )
            {
              v15 = v14->RefCount;
              if ( v15 & 0x3FFFFF )
              {
                v14->RefCount = v15 - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v14);
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

// File Line: 330
// RVA: 0x7B8CC0
void __fastcall Scaleform::GFx::AS3::Classes::fl::Number::Construct(Scaleform::GFx::AS3::Classes::fl::Number *this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v4; // rbx
  Scaleform::GFx::AS3::Classes::fl::Number *v5; // rdi
  Scaleform::GFx::AS3::VM::Error *v6; // rax
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  long double v; // [rsp+20h] [rbp-28h]
  Scaleform::GFx::ASStringNode *v10; // [rsp+28h] [rbp-20h]
  __int64 v11; // [rsp+30h] [rbp-18h]
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+60h] [rbp+18h]

  v11 = -2i64;
  v4 = result;
  v5 = this;
  if ( argc )
  {
    if ( argc == 1 )
    {
      if ( Scaleform::GFx::AS3::Value::Convert2Number(argv, &resulta, &v)->Result )
        Scaleform::GFx::AS3::Value::SetNumber(v4, v);
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(
        (Scaleform::GFx::AS3::VM::Error *)&v,
        eWrongArgumentCountError,
        this->pTraits.pObject->pVM);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        v5->pTraits.pObject->pVM,
        v6,
        &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
      v7 = v10;
      v8 = v10->RefCount == 1;
      --v7->RefCount;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v7);
    }
  }
  else
  {
    Scaleform::GFx::AS3::Value::SetNumber(result, 0.0);
  }
}

// File Line: 368
// RVA: 0x72C2D0
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl::Number::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // rbp
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v3; // rdi
  Scaleform::MemoryHeap *v4; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rbx
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> v8; // rbx
  Scaleform::GFx::AS3::Classes::fl::Number *v9; // rax

  v2 = vm;
  v3 = result;
  v4 = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->vfptr->Alloc(v4, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, v2, &Scaleform::GFx::AS3::fl::NumberCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable';
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Number::`vftable';
    v6->TraitsType = 4;
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
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, v2, &Scaleform::GFx::AS3::fl::NumberCI);
    v8.pV->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable';
    v8.pV->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Number::`vftable';
    v8.pV->TraitsType = 4;
  }
  else
  {
    v8.pV = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(v3->pV, v8);
  v9 = (Scaleform::GFx::AS3::Classes::fl::Number *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v4->vfptr->Alloc)(
                                                     v4,
                                                     112i64);
  if ( v9 )
    Scaleform::GFx::AS3::Classes::fl::Number::Number(v9, v3->pV);
  return v3;
}

// File Line: 382
// RVA: 0x7B69C0
char __fastcall Scaleform::GFx::AS3::ClassTraits::fl::Number::Coerce(Scaleform::GFx::AS3::ClassTraits::fl::Number *this, Scaleform::GFx::AS3::Value *value, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  long double v; // [rsp+20h] [rbp-18h]
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+58h] [rbp+20h]

  v3 = result;
  if ( !Scaleform::GFx::AS3::Value::Convert2Number(value, &resulta, &v)->Result )
    return 0;
  Scaleform::GFx::AS3::Value::SetNumber(v3, v);
  return 1;
}

