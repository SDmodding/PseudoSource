// File Line: 67
// RVA: 0x15971D0
const char *dynamic_initializer_for__Scaleform::GFx::AS3::InstanceTraits::fl::String::ti__()
{
  const char *result; // rax

  result = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::String::ti[1].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::String::ti[2].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::String::ti[3].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::String::ti[4].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::String::ti[5].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::String::ti[6].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::String::ti[7].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::String::ti[8].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::String::ti[9].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::String::ti[10].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::String::ti[11].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::String::ti[12].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::String::ti[13].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::String::ti[14].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::String::ti[15].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::String::ti[16].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::String::ti[17].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::String::ti[18].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::InstanceTraits::fl::String::ti[19].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  return result;
}

// File Line: 103
// RVA: 0x738730
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::String::lengthGet(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value *v4; // rbx
  Scaleform::GFx::ASString *v5; // rax
  int v6; // eax
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::GFx::ASString resulta; // [rsp+20h] [rbp-18h]
  __int64 v10; // [rsp+28h] [rbp-10h]

  v10 = -2i64;
  v4 = result;
  v5 = Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(_this, &resulta);
  v6 = Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&v5->pNode);
  Scaleform::GFx::AS3::Value::SetSInt32(v4, v6);
  v7 = resulta.pNode;
  v8 = resulta.pNode->RefCount == 1;
  --v7->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
}

// File Line: 112
// RVA: 0x738EB0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::String::AS3indexOf(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v6; // r14
  Scaleform::GFx::AS3::Value *v7; // rdi
  unsigned int v8; // ebx
  Scaleform::GFx::AS3::StringManager *v9; // rsi
  Scaleform::GFx::AS3::Value *v10; // rsi
  int v11; // edx
  int v12; // edi
  unsigned int v13; // esi
  unsigned int v14; // eax
  unsigned int v15; // ebx
  unsigned int v16; // eax
  Scaleform::GFx::ASStringNode *v17; // rcx
  bool v18; // zf
  Scaleform::GFx::ASStringNode *v19; // rcx
  int v20; // [rsp+20h] [rbp-40h]
  char *putf8Buffer; // [rsp+28h] [rbp-38h]
  char *v22; // [rsp+30h] [rbp-30h]
  Scaleform::GFx::ASString v23; // [rsp+38h] [rbp-28h]
  char *v24; // [rsp+40h] [rbp-20h]
  char *v25; // [rsp+48h] [rbp-18h]
  Scaleform::GFx::ASString resulta; // [rsp+50h] [rbp-10h]
  __int64 v27; // [rsp+58h] [rbp-8h]

  v27 = -2i64;
  v6 = result;
  v7 = _this;
  v8 = argc;
  if ( !argc )
  {
    Scaleform::GFx::AS3::Value::SetSInt32(result, -1);
    return;
  }
  v9 = vm->StringManagerRef;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v9->Builtins,
    &resulta);
  if ( Scaleform::GFx::AS3::Value::Convert2String(v7, (Scaleform::GFx::AS3::CheckResult *)&argc, &resulta)->Result )
  {
    Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
      (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v9->Builtins,
      &v23);
    v10 = argv;
    if ( !Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&argc, &v23)->Result )
      goto LABEL_29;
    if ( Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&v23.pNode) )
    {
      putf8Buffer = (char *)v23.pNode->pData;
      v22 = (char *)resulta.pNode->pData;
      v12 = 0;
      v20 = 0;
      if ( v8 > 1
        && !Scaleform::GFx::AS3::Value::Convert2Int32(v10 + 1, (Scaleform::GFx::AS3::CheckResult *)&argc, &v20)->Result )
      {
LABEL_29:
        v17 = v23.pNode;
        v18 = v23.pNode->RefCount == 1;
        --v17->RefCount;
        if ( v18 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v17);
        goto LABEL_31;
      }
      v13 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
      if ( !v13 )
        --putf8Buffer;
      while ( 1 )
      {
        v14 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&v22);
        if ( !v14 )
          break;
        if ( v12 >= v20 && v14 == v13 )
        {
          v24 = v22;
          v25 = putf8Buffer;
          do
          {
            v15 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&v24);
            if ( !v15 )
              --v24;
            v16 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&v25);
            if ( !v16 )
              --v25;
            if ( !v15 )
              break;
            if ( !v16 )
              goto LABEL_25;
          }
          while ( v15 == v16 );
          if ( !v16 )
          {
LABEL_25:
            v11 = v12;
            goto LABEL_28;
          }
          if ( !v15 )
            goto LABEL_27;
        }
        ++v12;
      }
      --v22;
LABEL_27:
      v11 = -1;
    }
    else
    {
      v11 = 0;
    }
LABEL_28:
    Scaleform::GFx::AS3::Value::SetSInt32(v6, v11);
    goto LABEL_29;
  }
LABEL_31:
  v19 = resulta.pNode;
  v18 = resulta.pNode->RefCount == 1;
  --v19->RefCount;
  if ( v18 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
}

// File Line: 194
// RVA: 0x79FE50
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::String::AS3lastIndexOf(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v6; // r12
  Scaleform::GFx::AS3::Value *v7; // rdi
  unsigned int v8; // ebx
  Scaleform::GFx::AS3::StringManager *v9; // rsi
  Scaleform::GFx::AS3::Value *v10; // rsi
  signed int v11; // edi
  signed int v12; // er14
  Scaleform::GFx::AS3::Value *v13; // rcx
  int v14; // edx
  unsigned int v15; // er15
  signed int v16; // esi
  unsigned int v17; // eax
  unsigned int v18; // ebx
  unsigned int v19; // eax
  Scaleform::GFx::ASStringNode *v20; // rcx
  bool v21; // zf
  Scaleform::GFx::ASStringNode *v22; // rcx
  char *v23; // [rsp+20h] [rbp-60h]
  char *v24; // [rsp+28h] [rbp-58h]
  Scaleform::GFx::ASString resulta; // [rsp+30h] [rbp-50h]
  Scaleform::GFx::ASString v26; // [rsp+38h] [rbp-48h]
  char *putf8Buffer; // [rsp+40h] [rbp-40h]
  char *v28; // [rsp+48h] [rbp-38h]
  __int64 v29; // [rsp+50h] [rbp-30h]
  int v30; // [rsp+58h] [rbp-28h]
  __int64 v31; // [rsp+60h] [rbp-20h]
  char *v32; // [rsp+68h] [rbp-18h]

  v29 = -2i64;
  v6 = result;
  v7 = _this;
  v8 = argc;
  if ( argc < 1 )
  {
    Scaleform::GFx::AS3::Value::SetSInt32(result, -1);
    return;
  }
  v9 = vm->StringManagerRef;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v9->Builtins,
    &resulta);
  if ( Scaleform::GFx::AS3::Value::Convert2String(v7, (Scaleform::GFx::AS3::CheckResult *)&argc, &resulta)->Result )
  {
    Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
      (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v9->Builtins,
      &v26);
    v10 = argv;
    if ( Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&argc, &v26)->Result )
    {
      v28 = (char *)resulta.pNode->pData;
      putf8Buffer = (char *)v26.pNode->pData;
      v11 = 0;
      v12 = 0x7FFFFFF;
      if ( v8 <= 1 )
      {
LABEL_12:
        if ( Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&v26.pNode) )
        {
          v15 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
          if ( !v15 )
            --putf8Buffer;
          v16 = -1;
          while ( 1 )
          {
            v17 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&v28);
            if ( !v17 )
              break;
            if ( v11 <= v12 && v17 == v15 )
            {
              v24 = v28;
              v23 = putf8Buffer;
              do
              {
                v18 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&v24);
                if ( !v18 )
                  --v24;
                v19 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&v23);
                if ( !v19 )
                  --v23;
                if ( !v18 )
                  break;
                if ( !v19 )
                  goto LABEL_31;
              }
              while ( v18 == v19 );
              if ( v19 )
                goto LABEL_32;
LABEL_31:
              v16 = v11;
LABEL_32:
              if ( !v18 )
                goto LABEL_35;
            }
            ++v11;
          }
          --v28;
LABEL_35:
          v14 = v16;
          v13 = v6;
        }
        else
        {
          v13 = v6;
          if ( v8 <= 1 )
            v14 = resulta.pNode->Size;
          else
            v14 = v12;
        }
        Scaleform::GFx::AS3::Value::SetSInt32(v13, v14);
        goto LABEL_37;
      }
      *(double *)&v24 = DOUBLE_1_34217727e8;
      if ( Scaleform::GFx::AS3::Value::Convert2Number(
             v10 + 1,
             (Scaleform::GFx::AS3::CheckResult *)&argc,
             (long double *)&v24)->Result )
      {
        v30 = 4;
        v31 = 0i64;
        v32 = v24;
        v23 = v24;
        if ( ((unsigned __int64)v24 & 0x7FF0000000000000i64) != 9218868437227405312i64
          || !((unsigned __int64)v24 & 0xFFFFFFFFFFFFFi64) )
        {
          v23 = v24;
          if ( *(double *)&v24 != 1.797693134862316e308/*+Inf*/ )
          {
            v23 = v24;
            v12 = 0;
            if ( *(double *)&v24 != -1.797693134862316e308/*-Inf*/ )
              v12 = (signed int)*(double *)&v24;
          }
        }
        goto LABEL_12;
      }
    }
LABEL_37:
    v20 = v26.pNode;
    v21 = v26.pNode->RefCount == 1;
    --v20->RefCount;
    if ( v21 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v20);
  }
  v22 = resulta.pNode;
  v21 = resulta.pNode->RefCount == 1;
  --v22->RefCount;
  if ( v21 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v22);
}

// File Line: 289
// RVA: 0x79B350
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::String::AS3charAt(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v6; // rsi
  Scaleform::GFx::AS3::Value *v7; // rbx
  Scaleform::GFx::AS3::StringManager *v8; // rdi
  double v9; // xmm0_8
  unsigned int v10; // ebx
  unsigned int v11; // eax
  Scaleform::GFx::ASStringNode *v12; // rbx
  Scaleform::GFx::ASStringNode *v13; // rcx
  bool v14; // zf
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::ASString v; // [rsp+20h] [rbp-28h]
  Scaleform::GFx::ASString resulta; // [rsp+28h] [rbp-20h]
  long double v20; // [rsp+30h] [rbp-18h]
  __int64 v21; // [rsp+38h] [rbp-10h]
  Scaleform::GFx::AS3::CheckResult v22; // [rsp+58h] [rbp+10h]

  v21 = -2i64;
  v6 = result;
  v7 = _this;
  v8 = vm->StringManagerRef;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v8->Builtins,
    &resulta);
  if ( !Scaleform::GFx::AS3::Value::Convert2String(v7, &v22, &resulta)->Result )
    goto LABEL_13;
  v9 = 0.0;
  v20 = 0.0;
  if ( argc )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2Number(argv, &v22, &v20)->Result )
      goto LABEL_13;
    v9 = v20;
  }
  v10 = (signed int)v9;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v8->Builtins,
    &v);
  if ( (signed int)v9 >= 0
    && v10 < Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&resulta.pNode) )
  {
    v11 = Scaleform::GFx::ASConstString::GetCharAt((Scaleform::GFx::ASConstString *)&resulta.pNode, v10);
    v12 = Scaleform::GFx::ASString::AppendChar(&v, (Scaleform::GFx::ASString *)&v22, v11)->pNode;
    ++v12->RefCount;
    v13 = v.pNode;
    v14 = v.pNode->RefCount == 1;
    --v13->RefCount;
    if ( v14 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    v.pNode = v12;
    v15 = *(Scaleform::GFx::ASStringNode **)&v22.Result;
    v14 = *(_DWORD *)(*(_QWORD *)&v22.Result + 24i64) == 1;
    --v15->RefCount;
    if ( v14 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v15);
  }
  Scaleform::GFx::AS3::Value::Assign(v6, &v);
  v16 = v.pNode;
  v14 = v.pNode->RefCount == 1;
  --v16->RefCount;
  if ( v14 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
LABEL_13:
  v17 = resulta.pNode;
  v14 = resulta.pNode->RefCount == 1;
  --v17->RefCount;
  if ( v14 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
}

// File Line: 322
// RVA: 0x79B490
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::String::AS3charCodeAt(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v6; // rdi
  Scaleform::GFx::AS3::Value *v7; // rbx
  double v8; // xmm0_8
  unsigned int v9; // ebx
  double v10; // xmm1_8
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  Scaleform::GFx::ASString resulta; // [rsp+20h] [rbp-28h]
  long double v14; // [rsp+28h] [rbp-20h]
  __int64 v15; // [rsp+30h] [rbp-18h]
  Scaleform::GFx::AS3::CheckResult v16; // [rsp+58h] [rbp+10h]

  v15 = -2i64;
  v6 = result;
  v7 = _this;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)vm->StringManagerRef->Builtins,
    &resulta);
  if ( !Scaleform::GFx::AS3::Value::Convert2String(v7, &v16, &resulta)->Result )
    goto LABEL_10;
  v8 = 0.0;
  v14 = 0.0;
  if ( argc )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2Number(argv, &v16, &v14)->Result )
      goto LABEL_10;
    v8 = v14;
  }
  v9 = (signed int)v8;
  if ( (signed int)v8 < 0
    || v9 >= Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&resulta.pNode) )
  {
    v10 = Scaleform::GFx::NumberUtil::NaN();
  }
  else
  {
    v10 = (double)(signed int)Scaleform::GFx::ASConstString::GetCharAt(
                                (Scaleform::GFx::ASConstString *)&resulta.pNode,
                                v9);
  }
  Scaleform::GFx::AS3::Value::SetNumber(v6, v10);
LABEL_10:
  v11 = resulta.pNode;
  v12 = resulta.pNode->RefCount == 1;
  --v11->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
}

// File Line: 353
// RVA: 0x79BF00
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::String::AS3concat(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v6; // rdi
  Scaleform::GFx::AS3::Value *v7; // rbx
  Scaleform::GFx::AS3::StringManager *v8; // rsi
  int v9; // ebx
  unsigned int v10; // esi
  Scaleform::GFx::AS3::Value *v11; // rbp
  Scaleform::GFx::AS3::WeakProxy *v12; // rdx
  bool v13; // zf
  Scaleform::GFx::ASStringNode *v14; // rcx
  __int64 v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::ASString resulta; // [rsp+20h] [rbp-38h]
  Scaleform::GFx::ASString str; // [rsp+28h] [rbp-30h]
  __int64 v20; // [rsp+30h] [rbp-28h]
  __int64 v21; // [rsp+38h] [rbp-20h]
  Scaleform::GFx::AS3::CheckResult v22; // [rsp+68h] [rbp+10h]

  v21 = -2i64;
  v6 = result;
  v7 = _this;
  v8 = vm->StringManagerRef;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v8->Builtins,
    &resulta);
  if ( Scaleform::GFx::AS3::Value::Convert2String(v7, &v22, &resulta)->Result )
  {
    Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
      (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v8->Builtins,
      &str);
    v9 = 0;
    v10 = argc;
    if ( argc )
    {
      v11 = argv;
      while ( Scaleform::GFx::AS3::Value::Convert2String(&v11[v9], &v22, &str)->Result )
      {
        Scaleform::GFx::ASString::Append(&resulta, &str);
        if ( ++v9 >= v10 )
          goto LABEL_6;
      }
    }
    else
    {
LABEL_6:
      if ( (v6->Flags & 0x1F) > 9 )
      {
        if ( (v6->Flags >> 9) & 1 )
        {
          v12 = v6->Bonus.pWeakProxy;
          v13 = v12->RefCount-- == 1;
          if ( v13 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          v6->Bonus.pWeakProxy = 0i64;
          v6->value.VNumber = 0.0;
          v6->value.VS._2.VObj = 0i64;
          v6->Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(v6);
        }
      }
      v14 = resulta.pNode;
      v15 = v20;
      if ( resulta.pNode == &resulta.pNode->pManager->NullStringNode )
      {
        v6->value.VNumber = 0.0;
        v6->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v15;
        v6->Flags &= 0xFFFFFFEC;
        v6->Flags |= 0xCu;
      }
      else
      {
        v6->Flags &= 0xFFFFFFEA;
        v6->Flags |= 0xAu;
        *(_QWORD *)&v6->value.VNumber = v14;
        v6->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v15;
        ++*(_DWORD *)(*(_QWORD *)&v6->value.VNumber + 24i64);
      }
    }
    v16 = str.pNode;
    v13 = str.pNode->RefCount == 1;
    --v16->RefCount;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  }
  v17 = resulta.pNode;
  v13 = resulta.pNode->RefCount == 1;
  --v17->RefCount;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
}

// File Line: 382
// RVA: 0x7A0100
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::String::AS3localeCompare(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v6; // r14
  Scaleform::GFx::AS3::Value *v7; // rbx
  Scaleform::GFx::AS3::VM *v8; // rdi
  Scaleform::GFx::AS3::StringManager *v9; // rsi
  Scaleform::GFx::AS3::VM::Error *v10; // rax
  Scaleform::GFx::ASStringNode *v11; // rcx
  int v12; // ebx
  unsigned int v13; // edi
  unsigned int v14; // eax
  bool v15; // zf
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::AS3::VM::Error v17; // [rsp+20h] [rbp-30h]
  Scaleform::GFx::ASString resulta; // [rsp+30h] [rbp-20h]
  Scaleform::GFx::ASString v19; // [rsp+38h] [rbp-18h]
  __int64 v20; // [rsp+40h] [rbp-10h]
  Scaleform::GFx::AS3::CheckResult v21; // [rsp+78h] [rbp+28h]

  v20 = -2i64;
  v6 = result;
  v7 = _this;
  v8 = vm;
  v9 = vm->StringManagerRef;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v9->Builtins,
    &resulta);
  if ( Scaleform::GFx::AS3::Value::Convert2String(v7, &v21, &resulta)->Result )
  {
    if ( argc >= 1 )
    {
      if ( argc <= 1 )
      {
        Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
          (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v9->Builtins,
          &v19);
        if ( Scaleform::GFx::AS3::Value::Convert2String(argv, &v21, &v19)->Result )
        {
          v12 = 0;
          if ( v19.pNode != resulta.pNode )
          {
            *(_QWORD *)&v21.Result = v19.pNode->pData;
            *(_QWORD *)&v17.ID = resulta.pNode->pData;
            while ( 1 )
            {
              v13 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&v21);
              if ( !v13 )
                --*(_QWORD *)&v21.Result;
              v14 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&v17);
              if ( !v14 )
                --*(_QWORD *)&v17.ID;
              if ( !v13 || !v14 )
                break;
              v12 = v14 - v13;
              if ( v14 != v13 )
                goto LABEL_20;
            }
            if ( v13 != v14 )
            {
              v12 = 1;
              if ( !v14 )
                v12 = -1;
            }
          }
LABEL_20:
          Scaleform::GFx::AS3::Value::SetNumber(v6, (double)v12);
        }
        v11 = v19.pNode;
      }
      else
      {
        Scaleform::GFx::AS3::VM::Error::Error(&v17, eWrongArgumentCountError, v8);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(v8, v10, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
        v11 = v17.Message.pNode;
      }
      v15 = v11->RefCount-- == 1;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    }
    else
    {
      Scaleform::GFx::AS3::Value::SetNumber(v6, (double)(resulta.pNode->Size == 0));
    }
  }
  v16 = resulta.pNode;
  v15 = resulta.pNode->RefCount == 1;
  --v16->RefCount;
  if ( v15 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
}

// File Line: 416
// RVA: 0x7A07F0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::String::AS3match(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v6; // r15
  Scaleform::GFx::AS3::Value *v7; // rbx
  Scaleform::GFx::AS3::VM *v8; // rsi
  Scaleform::GFx::AS3::StringManager *v9; // r14
  Scaleform::GFx::AS3::Value *v10; // rdi
  unsigned int v11; // ecx
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *v12; // rbx
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *v13; // rcx
  Scaleform::GFx::ASStringNode *v14; // rcx
  bool v15; // zf
  Scaleform::GFx::AS3::Object **v16; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v17; // rcx
  int v18; // eax
  Scaleform::GFx::ASStringNode *v19; // rcx
  unsigned int v20; // eax
  Scaleform::GFx::ASStringNode *v21; // rcx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint> pobj; // [rsp+30h] [rbp-50h]
  Scaleform::GFx::ASString v23; // [rsp+38h] [rbp-48h]
  Scaleform::GFx::ASString resulta; // [rsp+40h] [rbp-40h]
  Scaleform::GFx::AS3::Value::V2U v25; // [rsp+48h] [rbp-38h]
  __int64 v26; // [rsp+50h] [rbp-30h]
  Scaleform::GFx::AS3::Value ptr; // [rsp+58h] [rbp-28h]
  Scaleform::GFx::AS3::CheckResult v28; // [rsp+A8h] [rbp+28h]

  v26 = -2i64;
  v6 = result;
  v7 = _this;
  v8 = vm;
  v9 = vm->StringManagerRef;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v9->Builtins,
    &resulta);
  if ( !Scaleform::GFx::AS3::Value::Convert2String(v7, &v28, &resulta)->Result )
    goto LABEL_32;
  if ( argc < 1 )
    goto LABEL_32;
  v10 = argv;
  v11 = argv->Flags & 0x1F;
  if ( !v11 )
    goto LABEL_32;
  if ( (v11 - 12 <= 3 || v11 == 10) && !*(_QWORD *)&argv->value.VNumber )
    goto LABEL_32;
  v12 = 0i64;
  pobj.pObject = 0i64;
  if ( (argv->Flags & 0x1F) - 12 > 3
    || !Scaleform::GFx::AS3::VM::IsOfType(v8, argv, "RegExp", v8->CurrentDomain.pObject) )
  {
    Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
      (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v9->Builtins,
      &v23);
    if ( Scaleform::GFx::AS3::Value::Convert2String(v10, &v28, &v23)->Result )
    {
      ptr.Flags = 10;
      ptr.Bonus.pWeakProxy = 0i64;
      *(Scaleform::GFx::ASString *)&ptr.value.VNumber = v23;
      if ( v23.pNode == &v23.pNode->pManager->NullStringNode )
      {
        ptr.value.VNumber = 0.0;
        ptr.value.VS._2 = v25;
        ptr.Flags = 12;
      }
      else
      {
        ++v23.pNode->RefCount;
      }
      if ( Scaleform::GFx::AS3::VM::ConstructBuiltinObject<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle>(
             v8,
             &v28,
             &pobj,
             "RegExp",
             1u,
             &ptr)->Result )
      {
        `eh vector destructor iterator(
          &ptr,
          0x20ui64,
          1,
          (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
        v14 = v23.pNode;
        v15 = v23.pNode->RefCount == 1;
        --v14->RefCount;
        if ( v15 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v14);
        v12 = pobj.pObject;
        goto LABEL_20;
      }
      `eh vector destructor iterator(
        &ptr,
        0x20ui64,
        1,
        (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
      v12 = pobj.pObject;
    }
    v19 = v23.pNode;
    v15 = v23.pNode->RefCount == 1;
    --v19->RefCount;
    if ( v15 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v19);
    goto LABEL_27;
  }
  v13 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *)v10->value.VS._1.VStr;
  if ( v13 )
  {
    v13->RefCount = (v13->RefCount + 1) & 0x8FBFFFFF;
    v12 = v13;
    pobj.pObject = v13;
  }
LABEL_20:
  v16 = (Scaleform::GFx::AS3::Object **)Scaleform::GFx::AS3::Instances::fl::RegExp::AS3exec(
                                          (Scaleform::GFx::AS3::Instances::fl::RegExp *)v12,
                                          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> *)&v28,
                                          &resulta);
  Scaleform::GFx::AS3::Value::Assign(v6, *v16);
  v17 = *(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v28.Result;
  if ( *(_QWORD *)&v28.Result )
  {
    if ( v28.Result )
    {
      --*(_QWORD *)&v28.Result;
    }
    else
    {
      v18 = *(_DWORD *)(*(_QWORD *)&v28.Result + 32i64);
      if ( v18 & 0x3FFFFF )
      {
        *(_DWORD *)(*(_QWORD *)&v28.Result + 32i64) = v18 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v17);
      }
    }
  }
LABEL_27:
  if ( v12 )
  {
    if ( (unsigned __int8)v12 & 1 )
    {
      pobj.pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *)((char *)v12 - 1);
    }
    else
    {
      v20 = v12->RefCount;
      if ( v20 & 0x3FFFFF )
      {
        v12->RefCount = v20 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v12->vfptr);
      }
    }
  }
LABEL_32:
  v21 = resulta.pNode;
  v15 = resulta.pNode->RefCount == 1;
  --v21->RefCount;
  if ( v15 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v21);
}

// File Line: 466
// RVA: 0x7A1E50
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::String::AS3replace(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value *v4; // r12
  Scaleform::GFx::AS3::Value *v5; // rbx
  Scaleform::GFx::AS3::VM *v6; // r14
  Scaleform::GFx::AS3::StringManager *v7; // rsi
  int v8; // ecx
  Scaleform::GFx::AS3::Instances::fl::RegExp *v9; // rbx
  __int64 v10; // rcx
  int v11; // ecx
  Scaleform::GFx::AS3::Instances::fl::Object *v12; // rdi
  Scaleform::GFx::AS3::Instances::fl::Object *v13; // rcx
  unsigned int v14; // eax
  Scaleform::GFx::ASString *v15; // rbx
  Scaleform::GFx::ASString *v16; // rax
  Scaleform::GFx::ASString *v17; // rax
  Scaleform::GFx::ASStringNode *v18; // rbx
  Scaleform::GFx::ASStringNode *v19; // rcx
  bool v20; // zf
  Scaleform::GFx::ASStringNode *v21; // rcx
  Scaleform::GFx::ASStringNode *v22; // rcx
  Scaleform::GFx::ASStringNode *v23; // rcx
  Scaleform::GFx::ASStringNode *v24; // rcx
  char *v25; // rdi
  unsigned __int64 v26; // rdi
  unsigned __int64 v27; // rbx
  Scaleform::GFx::ASString *v28; // rbx
  Scaleform::GFx::ASString *v29; // rax
  Scaleform::GFx::ASString *v30; // rax
  Scaleform::GFx::ASStringNode *v31; // rbx
  Scaleform::GFx::ASStringNode *v32; // rcx
  Scaleform::GFx::ASStringNode *v33; // rcx
  Scaleform::GFx::ASStringNode *v34; // rcx
  Scaleform::GFx::ASStringNode *v35; // rcx
  Scaleform::GFx::ASStringNode *v36; // rcx
  Scaleform::GFx::ASStringNode *v37; // rcx
  Scaleform::GFx::ASStringNode *v38; // rcx
  unsigned int v39; // eax
  Scaleform::GFx::ASStringNode *v40; // rcx
  Scaleform::GFx::ASString resulta; // [rsp+8h] [rbp-69h]
  Scaleform::GFx::AS3::Instances::fl::RegExp *v42; // [rsp+10h] [rbp-61h]
  Scaleform::GFx::AS3::CheckResult v43; // [rsp+18h] [rbp-59h]
  Scaleform::GFx::AS3::CheckResult v44; // [rsp+19h] [rbp-58h]
  Scaleform::GFx::ASString v45; // [rsp+20h] [rbp-51h]
  Scaleform::GFx::ASString v46; // [rsp+28h] [rbp-49h]
  Scaleform::String v47; // [rsp+30h] [rbp-41h]
  Scaleform::String v48; // [rsp+38h] [rbp-39h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> v49; // [rsp+40h] [rbp-31h]
  Scaleform::String str; // [rsp+48h] [rbp-29h]
  Scaleform::String v51; // [rsp+50h] [rbp-21h]
  Scaleform::GFx::ASString v52; // [rsp+58h] [rbp-19h]
  Scaleform::GFx::ASString v53; // [rsp+60h] [rbp-11h]
  Scaleform::GFx::ASString v54; // [rsp+68h] [rbp-9h]
  Scaleform::GFx::ASString v55; // [rsp+70h] [rbp-1h]
  Scaleform::GFx::ASString v56; // [rsp+78h] [rbp+7h]
  Scaleform::GFx::ASString v57; // [rsp+80h] [rbp+Fh]
  Scaleform::GFx::ASString v58; // [rsp+88h] [rbp+17h]
  Scaleform::GFx::ASString v59; // [rsp+90h] [rbp+1Fh]
  __int64 v60; // [rsp+98h] [rbp+27h]
  Scaleform::GFx::AS3::CheckResult vars0; // [rsp+D0h] [rbp+5Fh]
  unsigned int v62; // [rsp+E8h] [rbp+77h]
  Scaleform::GFx::AS3::Value *v; // [rsp+F0h] [rbp+7Fh]

  v60 = -2i64;
  v4 = result;
  v5 = _this;
  v6 = vm;
  v7 = vm->StringManagerRef;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v7->Builtins,
    &v45);
  if ( !Scaleform::GFx::AS3::Value::Convert2String(v5, &vars0, &resulta)->Result )
    goto LABEL_67;
  if ( v62 < 1 )
    goto LABEL_67;
  v8 = v->Flags & 0x1F;
  if ( !v8 )
    goto LABEL_67;
  if ( ((unsigned int)(v8 - 12) <= 3 || v8 == 10) && !*(_QWORD *)&v->value.VNumber )
    goto LABEL_67;
  v9 = 0i64;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v7->Builtins,
    &v46);
  if ( (v->Flags & 0x1F) - 12 <= 3 && Scaleform::GFx::AS3::VM::IsOfType(v6, v, "RegExp", v6->CurrentDomain.pObject) )
  {
    v10 = (__int64)v->value.VS._1.VStr;
    if ( v10 )
    {
      *(_DWORD *)(v10 + 32) = (*(_DWORD *)(v10 + 32) + 1) & 0x8FBFFFFF;
      v9 = (Scaleform::GFx::AS3::Instances::fl::RegExp *)v10;
      v42 = (Scaleform::GFx::AS3::Instances::fl::RegExp *)v10;
    }
    goto LABEL_12;
  }
  if ( Scaleform::GFx::AS3::Value::Convert2String(v, &v44, &v46)->Result )
  {
LABEL_12:
    Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
      (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v7->Builtins,
      &v45);
    if ( v62 < 2
      || (v11 = v[1].Flags & 0x1F) == 0
      || ((unsigned int)(v11 - 12) <= 3 || v11 == 10) && !*(_QWORD *)&v[1].value.VNumber
      || Scaleform::GFx::AS3::Value::Convert2String(v + 1, &v43, &v45)->Result )
    {
      if ( v9 )
      {
        v12 = Scaleform::GFx::AS3::Instances::fl::RegExp::AS3exec(v9, &v49, &resulta)->pObject;
        v13 = v49.pObject;
        if ( v49.pObject )
        {
          if ( (_QWORD)v49.pObject & 1 )
          {
            --v49.pObject;
          }
          else
          {
            v14 = v49.pObject->RefCount;
            if ( v14 & 0x3FFFFF )
            {
              v49.pObject->RefCount = v14 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v13->vfptr);
            }
          }
        }
        if ( v12 )
        {
          Scaleform::String::String(&v48, resulta.pNode->pData, 0xFFFFFFFFFFFFFFFFui64);
          Scaleform::String::String(&str, resulta.pNode->pData - 1, resulta.pNode->Size + 1);
          v15 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                  (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v7->Builtins,
                  &v59,
                  &str);
          v16 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                  (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v7->Builtins,
                  &v52,
                  &v48);
          v17 = Scaleform::GFx::ASString::operator+(v16, &v57, &v45);
          v18 = Scaleform::GFx::ASString::operator+(v17, &v55, v15)->pNode;
          ++v18->RefCount;
          v19 = resulta.pNode;
          v20 = resulta.pNode->RefCount == 1;
          --v19->RefCount;
          if ( v20 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v19);
          resulta.pNode = v18;
          v21 = v55.pNode;
          v20 = v55.pNode->RefCount == 1;
          --v21->RefCount;
          if ( v20 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v21);
          v22 = v57.pNode;
          v20 = v57.pNode->RefCount == 1;
          --v22->RefCount;
          if ( v20 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v22);
          v23 = v52.pNode;
          v20 = v52.pNode->RefCount == 1;
          --v23->RefCount;
          if ( v20 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v23);
          v24 = v59.pNode;
          v20 = v59.pNode->RefCount == 1;
          --v24->RefCount;
          if ( v20 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v24);
          if ( !_InterlockedDecrement((volatile signed __int32 *)((str.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          if ( _InterlockedExchangeAdd(
                 (volatile signed __int32 *)((v48.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8),
                 0xFFFFFFFF) == 1 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          v9 = v42;
        }
        Scaleform::GFx::AS3::Value::Assign(v4, &resulta);
      }
      else
      {
        v25 = strstr(resulta.pNode->pData, v46.pNode->pData);
        if ( v25 )
        {
          v26 = v25 - resulta.pNode->pData;
          v27 = v26 + Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&v46.pNode);
          Scaleform::String::String(&v51, resulta.pNode->pData, v26);
          Scaleform::String::String(&v47, &resulta.pNode->pData[v27], resulta.pNode->Size - v27);
          v28 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                  (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v7->Builtins,
                  &v58,
                  &v47);
          v29 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                  (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v7->Builtins,
                  &v56,
                  &v51);
          v30 = Scaleform::GFx::ASString::operator+(v29, &v54, &v45);
          v31 = Scaleform::GFx::ASString::operator+(v30, &v53, v28)->pNode;
          ++v31->RefCount;
          v32 = resulta.pNode;
          v20 = resulta.pNode->RefCount == 1;
          --v32->RefCount;
          if ( v20 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v32);
          resulta.pNode = v31;
          v33 = v53.pNode;
          v20 = v53.pNode->RefCount == 1;
          --v33->RefCount;
          if ( v20 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v33);
          v34 = v54.pNode;
          v20 = v54.pNode->RefCount == 1;
          --v34->RefCount;
          if ( v20 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v34);
          v35 = v56.pNode;
          v20 = v56.pNode->RefCount == 1;
          --v35->RefCount;
          if ( v20 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v35);
          v36 = v58.pNode;
          v20 = v58.pNode->RefCount == 1;
          --v36->RefCount;
          if ( v20 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v36);
          Scaleform::GFx::AS3::Value::Assign(v4, &resulta);
          if ( !_InterlockedDecrement((volatile signed __int32 *)((v47.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          if ( _InterlockedExchangeAdd(
                 (volatile signed __int32 *)((v51.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8),
                 0xFFFFFFFF) == 1 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          v9 = v42;
        }
        else
        {
          Scaleform::GFx::AS3::Value::Assign(v4, &resulta);
        }
      }
    }
    v37 = v45.pNode;
    v20 = v45.pNode->RefCount == 1;
    --v37->RefCount;
    if ( v20 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v37);
  }
  v38 = v46.pNode;
  v20 = v46.pNode->RefCount == 1;
  --v38->RefCount;
  if ( v20 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v38);
  if ( v9 )
  {
    if ( (unsigned __int8)v9 & 1 )
    {
      v42 = (Scaleform::GFx::AS3::Instances::fl::RegExp *)((char *)v9 - 1);
    }
    else
    {
      v39 = v9->RefCount;
      if ( v39 & 0x3FFFFF )
      {
        v9->RefCount = v39 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v9->vfptr);
      }
    }
  }
LABEL_67:
  v40 = resulta.pNode;
  v20 = resulta.pNode->RefCount == 1;
  --v40->RefCount;
  if ( v20 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v40);
}

// File Line: 538
// RVA: 0x7A25E0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::String::AS3search(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value *v4; // r12
  Scaleform::GFx::AS3::Value *v5; // rbx
  Scaleform::GFx::AS3::VM *v6; // rsi
  Scaleform::GFx::AS3::StringManager *v7; // r14
  int v8; // ecx
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *v9; // rbx
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *v10; // rcx
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  Scaleform::GFx::AS3::Instances::fl::Object *v13; // rdi
  Scaleform::GFx::AS3::Instances::fl::Object *v14; // rcx
  unsigned int v15; // eax
  int v16; // eax
  Scaleform::GFx::ASStringNode *v17; // rcx
  unsigned int v18; // eax
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint> pobj; // [rsp+8h] [rbp-49h]
  Scaleform::GFx::AS3::CheckResult v21; // [rsp+10h] [rbp-41h]
  Scaleform::GFx::AS3::CheckResult v22; // [rsp+11h] [rbp-40h]
  Scaleform::GFx::ASString resulta; // [rsp+18h] [rbp-39h]
  Scaleform::GFx::ASString v24; // [rsp+20h] [rbp-31h]
  Scaleform::String v25; // [rsp+28h] [rbp-29h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> v26; // [rsp+30h] [rbp-21h]
  Scaleform::GFx::AS3::Value ptr; // [rsp+38h] [rbp-19h]
  __int64 v28; // [rsp+58h] [rbp+7h]
  __int64 v29; // [rsp+60h] [rbp+Fh]
  unsigned __int64 v30; // [rsp+68h] [rbp+17h]
  Scaleform::GFx::AS3::CheckResult v31; // [rsp+B0h] [rbp+5Fh]
  void *retaddr; // [rsp+C8h] [rbp+77h]
  Scaleform::GFx::AS3::Value *v; // [rsp+D0h] [rbp+7Fh]

  v28 = -2i64;
  v4 = result;
  v5 = _this;
  v6 = vm;
  v7 = vm->StringManagerRef;
  Scaleform::GFx::AS3::Value::SetSInt32(result, -1);
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v7->Builtins,
    &resulta);
  if ( !Scaleform::GFx::AS3::Value::Convert2String(v5, &v31, &resulta)->Result )
    goto LABEL_36;
  if ( (unsigned int)retaddr < 1 )
    goto LABEL_36;
  v8 = v->Flags & 0x1F;
  if ( !v8 )
    goto LABEL_36;
  if ( ((unsigned int)(v8 - 12) <= 3 || v8 == 10) && !*(_QWORD *)&v->value.VNumber )
    goto LABEL_36;
  v9 = 0i64;
  pobj.pObject = 0i64;
  if ( (v->Flags & 0x1F) - 12 > 3 || !Scaleform::GFx::AS3::VM::IsOfType(v6, v, "RegExp", v6->CurrentDomain.pObject) )
  {
    Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
      (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v7->Builtins,
      &v24);
    if ( Scaleform::GFx::AS3::Value::Convert2String(v, &v22, &v24)->Result )
    {
      ptr.Flags = 10;
      ptr.Bonus.pWeakProxy = 0i64;
      *(Scaleform::GFx::ASString *)&ptr.value.VNumber = v24;
      if ( v24.pNode == &v24.pNode->pManager->NullStringNode )
      {
        v29 = 0i64;
        ptr.value = (Scaleform::GFx::AS3::Value::VU)__PAIR__(v30, 0i64);
        ptr.Flags = 12;
      }
      else
      {
        ++v24.pNode->RefCount;
      }
      if ( Scaleform::GFx::AS3::VM::ConstructBuiltinObject<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle>(
             v6,
             &v21,
             &pobj,
             "RegExp",
             1u,
             &ptr)->Result )
      {
        `eh vector destructor iterator(
          &ptr,
          0x20ui64,
          1,
          (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
        v11 = v24.pNode;
        v12 = v24.pNode->RefCount == 1;
        --v11->RefCount;
        if ( v12 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v11);
        v9 = pobj.pObject;
        goto LABEL_20;
      }
      `eh vector destructor iterator(
        &ptr,
        0x20ui64,
        1,
        (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
      v9 = pobj.pObject;
    }
    v17 = v24.pNode;
    v12 = v24.pNode->RefCount == 1;
    --v17->RefCount;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v17);
    goto LABEL_31;
  }
  v10 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *)v->value.VS._1.VStr;
  if ( v10 )
  {
    v10->RefCount = (v10->RefCount + 1) & 0x8FBFFFFF;
    v9 = v10;
    pobj.pObject = v10;
  }
LABEL_20:
  v13 = Scaleform::GFx::AS3::Instances::fl::RegExp::AS3exec(
          (Scaleform::GFx::AS3::Instances::fl::RegExp *)v9,
          &v26,
          &resulta)->pObject;
  v14 = v26.pObject;
  if ( v26.pObject )
  {
    if ( (_QWORD)v26.pObject & 1 )
    {
      --v26.pObject;
    }
    else
    {
      v15 = v26.pObject->RefCount;
      if ( v15 & 0x3FFFFF )
      {
        v26.pObject->RefCount = v15 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v14->vfptr);
      }
    }
  }
  if ( v13 )
  {
    Scaleform::String::String(&v25, resulta.pNode->pData, 0xFFFFFFFFFFFFFFFFui64);
    v16 = Scaleform::String::GetLength(&v25);
    Scaleform::GFx::AS3::Value::SetSInt32(v4, v16);
    if ( _InterlockedExchangeAdd(
           (volatile signed __int32 *)((v25.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8),
           0xFFFFFFFF) == 1 )
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    v9 = pobj.pObject;
  }
LABEL_31:
  if ( v9 )
  {
    if ( (unsigned __int8)v9 & 1 )
    {
      pobj.pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *)((char *)v9 - 1);
    }
    else
    {
      v18 = v9->RefCount;
      if ( v18 & 0x3FFFFF )
      {
        v9->RefCount = v18 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v9->vfptr);
      }
    }
  }
LABEL_36:
  v19 = resulta.pNode;
  v12 = resulta.pNode->RefCount == 1;
  --v19->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
}

// File Line: 580
// RVA: 0x7A3F00
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::String::AS3slice(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v6; // r15
  Scaleform::GFx::AS3::Value *v7; // rbx
  Scaleform::GFx::AS3::StringManager *v8; // r12
  signed int v9; // esi
  int v10; // edi
  int v11; // ebx
  Scaleform::GFx::AS3::Value *v12; // r14
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASString *v14; // rax
  Scaleform::GFx::ASStringNode *v15; // rcx
  bool v16; // zf
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::ASString resulta; // [rsp+20h] [rbp-38h]
  long double v19; // [rsp+28h] [rbp-30h]
  long double v20; // [rsp+30h] [rbp-28h]
  __int64 v21; // [rsp+38h] [rbp-20h]
  Scaleform::GFx::AS3::CheckResult v22; // [rsp+68h] [rbp+10h]

  v21 = -2i64;
  v6 = result;
  v7 = _this;
  v8 = vm->StringManagerRef;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v8->Builtins,
    &resulta);
  if ( !Scaleform::GFx::AS3::Value::Convert2String(v7, &v22, &resulta)->Result )
    goto LABEL_21;
  if ( !argc )
  {
    Scaleform::GFx::AS3::Value::Assign(v6, &resulta);
    goto LABEL_21;
  }
  v9 = Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&resulta.pNode);
  v10 = 0;
  v11 = 0x7FFFFFFF;
  v12 = argv;
  if ( argc >= 1 )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2Number(argv, &v22, &v19)->Result )
      goto LABEL_21;
    v10 = v9;
    if ( v19 <= (double)v9 )
      v10 = (signed int)v19;
    if ( v10 < 0 )
      v10 += v9;
  }
  if ( argc < 2 )
    goto LABEL_25;
  if ( !Scaleform::GFx::AS3::Value::Convert2Number(v12 + 1, &v22, &v20)->Result )
    goto LABEL_21;
  v11 = v9;
  if ( v20 <= (double)v9 )
    v11 = (signed int)v20;
  if ( v11 < 0 )
    v11 += v9;
  if ( v11 >= v10 )
  {
LABEL_25:
    v14 = Scaleform::GFx::ASString::Substring(&resulta, (Scaleform::GFx::ASString *)&v22, v10, v11);
    Scaleform::GFx::AS3::Value::Assign(v6, v14);
  }
  else
  {
    v13 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
            (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v8->Builtins,
            (Scaleform::GFx::ASString *)&v22);
    Scaleform::GFx::AS3::Value::Assign(v6, v13);
  }
  v15 = *(Scaleform::GFx::ASStringNode **)&v22.Result;
  v16 = *(_DWORD *)(*(_QWORD *)&v22.Result + 24i64) == 1;
  --v15->RefCount;
  if ( v16 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
LABEL_21:
  v17 = resulta.pNode;
  v16 = resulta.pNode->RefCount == 1;
  --v17->RefCount;
  if ( v16 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
}

// File Line: 635
// RVA: 0x7A6480
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::String::AS3split(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v6; // rbx
  Scaleform::GFx::AS3::VM *v7; // r13
  unsigned int v8; // er14
  unsigned int v9; // ebx
  Scaleform::GFx::AS3::WeakProxy *v10; // rsi
  Scaleform::GFx::AS3::Value *v11; // rdi
  unsigned int v12; // er15
  unsigned int v13; // ecx
  unsigned int limit; // er12
  int v15; // ecx
  int v16; // er15
  Scaleform::GFx::AS3::Instances::fl::RegExp *v17; // rdi
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::AS3::Instances::fl::Array *v19; // rbx
  signed int v20; // er12
  unsigned int v21; // er13
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> *v22; // rax
  int v23; // er14
  unsigned int v24; // eax
  bool v25; // r15
  Scaleform::GFx::AS3::Instances::fl::Object *v26; // rcx
  unsigned int v27; // eax
  long double *v28; // rax
  long double v29; // rdx
  unsigned __int64 v30; // rcx
  signed __int64 v31; // rcx
  signed __int64 v32; // rdx
  bool v33; // zf
  Scaleform::GFx::AS3::Value::VU *v34; // rdx
  int v35; // eax
  long double v36; // rax
  Scaleform::GFx::ASStringNode *v37; // rcx
  long double *v38; // rax
  long double v39; // rdx
  unsigned __int64 v40; // rcx
  signed __int64 v41; // rcx
  signed __int64 v42; // rdx
  Scaleform::GFx::AS3::Value::VU *v43; // rdx
  int v44; // eax
  long double v45; // rax
  Scaleform::GFx::ASStringNode *v46; // rcx
  unsigned int v47; // eax
  Scaleform::GFx::ASStringNode *v48; // rcx
  unsigned int v49; // eax
  Scaleform::GFx::AS3::Value::V2U v50; // rax
  unsigned int v51; // ebx
  Scaleform::GFx::ASStringNode *v52; // rcx
  unsigned int v53; // eax
  Scaleform::GFx::AS3::Object **v54; // rax
  Scaleform::GFx::ASStringNode *v55; // rcx
  Scaleform::GFx::ASStringNode *v56; // rcx
  Scaleform::GFx::AS3::Value v; // [rsp+30h] [rbp-D0h]
  unsigned int v58; // [rsp+50h] [rbp-B0h]
  Scaleform::GFx::AS3::CheckResult v59; // [rsp+54h] [rbp-ACh]
  Scaleform::GFx::AS3::CheckResult v60; // [rsp+55h] [rbp-ABh]
  Scaleform::GFx::ASString resulta; // [rsp+58h] [rbp-A8h]
  Scaleform::GFx::AS3::Value v62; // [rsp+60h] [rbp-A0h]
  Scaleform::GFx::AS3::Value v63; // [rsp+80h] [rbp-80h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> v64; // [rsp+A0h] [rbp-60h]
  Scaleform::GFx::ASString v65; // [rsp+A8h] [rbp-58h]
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *v66; // [rsp+B0h] [rbp-50h]
  Scaleform::GFx::ASString v67; // [rsp+B8h] [rbp-48h]
  __int64 v68; // [rsp+C0h] [rbp-40h]
  Scaleform::GFx::AS3::Value::V1U v69; // [rsp+C8h] [rbp-38h]
  Scaleform::String str; // [rsp+D0h] [rbp-30h]
  Scaleform::String v71; // [rsp+D8h] [rbp-28h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> v72; // [rsp+E0h] [rbp-20h]
  Scaleform::GFx::ASString v73; // [rsp+E8h] [rbp-18h]
  Scaleform::GFx::AS3::Value::VU *v74; // [rsp+F0h] [rbp-10h]
  Scaleform::GFx::ASString v75; // [rsp+F8h] [rbp-8h]
  Scaleform::GFx::AS3::Instances::fl::Array *v76; // [rsp+100h] [rbp+0h]
  Scaleform::GFx::AS3::Value::VU *v77; // [rsp+108h] [rbp+8h]
  long double v78; // [rsp+110h] [rbp+10h]
  Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef key; // [rsp+118h] [rbp+18h]
  Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef v80; // [rsp+128h] [rbp+28h]
  __int64 v81; // [rsp+138h] [rbp+38h]
  unsigned __int64 v82; // [rsp+140h] [rbp+40h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> v83; // [rsp+148h] [rbp+48h]
  __int64 v84; // [rsp+150h] [rbp+50h]
  unsigned __int64 v85; // [rsp+158h] [rbp+58h]
  __int64 v86; // [rsp+160h] [rbp+60h]
  Scaleform::GFx::AS3::Value::V2U v87; // [rsp+170h] [rbp+70h]
  Scaleform::GFx::AS3::Value::V2U v88; // [rsp+180h] [rbp+80h]
  Scaleform::GFx::AS3::CheckResult v89; // [rsp+1D8h] [rbp+D8h]
  Scaleform::GFx::AS3::Value *v90; // [rsp+1E8h] [rbp+E8h]

  v90 = result;
  v86 = -2i64;
  v6 = _this;
  v7 = vm;
  v8 = 0;
  v58 = 0;
  v66 = (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)vm->StringManagerRef->Builtins;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(v66, &resulta);
  if ( !Scaleform::GFx::AS3::Value::Convert2String(v6, &v89, &resulta)->Result )
    goto LABEL_133;
  v9 = 0;
  v.Flags = 0;
  v10 = 0i64;
  v.Bonus.pWeakProxy = 0i64;
  v11 = argv;
  v12 = argc;
  if ( argc >= 1 )
  {
    v13 = argv->Flags & 0x1F;
    if ( v13 )
    {
      if ( v13 - 12 > 3 && v13 != 10 || *(_QWORD *)&argv->value.VNumber )
      {
        Scaleform::GFx::AS3::Value::Assign(&v, argv);
        v10 = v.Bonus.pWeakProxy;
        v9 = v.Flags;
      }
    }
  }
  limit = 0x7FFFFFFF;
  v68 = 0x7FFFFFFFi64;
  if ( v12 >= 2 )
  {
    v15 = v11[1].Flags & 0x1F;
    if ( v15 )
    {
      if ( (unsigned int)(v15 - 12) > 3 && v15 != 10 || *(_QWORD *)&v11[1].value.VNumber )
      {
        if ( !Scaleform::GFx::AS3::Value::Convert2Number(v11 + 1, &v60, &v78)->Result )
          goto LABEL_127;
        limit = (signed int)v78;
        v68 = (unsigned int)(signed int)v78;
      }
    }
  }
  v16 = v9 & 0x1F;
  if ( (unsigned int)(v16 - 12) > 3 || !Scaleform::GFx::AS3::VM::IsOfType(v7, &v, "RegExp", v7->CurrentDomain.pObject) )
  {
LABEL_122:
    Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(v66, &v67);
    if ( Scaleform::GFx::AS3::Value::Convert2String(&v, &v59, &v67)->Result )
    {
      v54 = (Scaleform::GFx::AS3::Object **)Scaleform::GFx::AS3::InstanceTraits::fl::String::StringSplit(
                                              &v83,
                                              v7,
                                              &resulta,
                                              v67.pNode->pData,
                                              limit);
      Scaleform::GFx::AS3::Value::Pick(v90, *v54);
    }
    v55 = v67.pNode;
    v33 = v67.pNode->RefCount == 1;
    --v55->RefCount;
    if ( v33 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v55);
    goto LABEL_126;
  }
  v17 = (Scaleform::GFx::AS3::Instances::fl::RegExp *)v.value.VS._1.VStr;
  v69 = *(Scaleform::GFx::AS3::Value::V1U *)&v.value.VNumber;
  if ( *(_QWORD *)&v.value.VNumber )
    *(_DWORD *)(*(_QWORD *)&v.value.VNumber + 32i64) = (*(_DWORD *)(*(_QWORD *)&v.value.VNumber + 32i64) + 1) & 0x8FBFFFFF;
  Scaleform::GFx::AS3::Instances::fl::RegExp::sourceGet(v17, &v65);
  v18 = v65.pNode;
  if ( !v65.pNode->Size )
  {
    if ( v16 > 9 )
    {
      if ( (v9 >> 9) & 1 )
      {
        v33 = v10->RefCount-- == 1;
        if ( v33 )
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v10);
        v.Bonus.pWeakProxy = 0i64;
        v.value = 0ui64;
        v9 &= 0xFFFFFDE0;
        v.Flags = v9;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
        v9 = v.Flags;
      }
      v18 = v65.pNode;
    }
    if ( v18 == &v18->pManager->NullStringNode )
    {
      v.value.VNumber = 0.0;
      v50.VObj = v87.VObj;
      v51 = v9 & 0xFFFFFFEC | 0xC;
    }
    else
    {
      v51 = v9 & 0xFFFFFFEA | 0xA;
      *(_QWORD *)&v.value.VNumber = v18;
      v50.VObj = v88.VObj;
      ++v18->RefCount;
    }
    v.value.VS._2 = v50;
    v.Flags = v51;
    v52 = v65.pNode;
    v33 = v65.pNode->RefCount == 1;
    --v52->RefCount;
    if ( v33 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v52);
    if ( v17 )
    {
      if ( (unsigned __int8)v17 & 1 )
      {
        v69.VStr = (Scaleform::GFx::ASStringNode *)((char *)&v17[-1].DynAttrs.mHash.pTable + 7);
      }
      else
      {
        v53 = v17->RefCount;
        if ( v53 & 0x3FFFFF )
        {
          v17->RefCount = v53 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v17->vfptr);
        }
      }
    }
    goto LABEL_122;
  }
  Scaleform::GFx::AS3::InstanceTraits::fl::Array::MakeInstance(
    &v64,
    (Scaleform::GFx::AS3::InstanceTraits::fl::Array *)v7->TraitsArray.pObject->ITraits.pObject);
  v19 = v64.pV;
  v76 = v64.pV;
  v20 = 0;
  v21 = 0;
  while ( 1 )
  {
    v22 = Scaleform::GFx::AS3::Instances::fl::RegExp::AS3exec(v17, &v72, &resulta);
    v23 = v8 | 1;
    v58 = v23;
    v25 = 0;
    if ( v22->pObject )
    {
      v24 = v21++;
      if ( v24 < (unsigned int)v68 )
        v25 = 1;
    }
    if ( v23 & 1 )
    {
      v58 = v23 & 0xFFFFFFFE;
      v26 = v72.pObject;
      if ( v72.pObject )
      {
        if ( (_QWORD)v72.pObject & 1 )
        {
          --v72.pObject;
        }
        else
        {
          v27 = v72.pObject->RefCount;
          if ( v27 & 0x3FFFFF )
          {
            v72.pObject->RefCount = v27 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v26->vfptr);
          }
        }
      }
    }
    if ( !v25 )
      break;
    Scaleform::String::String(&str, &resulta.pNode->pData[v20], (unsigned int)(-1 - v20));
    v28 = (long double *)Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                           v66,
                           &v73,
                           &str);
    v63.Flags = 10;
    v63.Bonus.pWeakProxy = 0i64;
    v29 = *v28;
    v63.value.VNumber = *v28;
    if ( *(_QWORD *)v28 == *(_QWORD *)(*(_QWORD *)v28 + 8i64) + 104i64 )
    {
      v81 = 0i64;
      v63.value = (Scaleform::GFx::AS3::Value::VU)__PAIR__(v82, 0i64);
      v63.Flags = 12;
    }
    else
    {
      ++*(_DWORD *)(*(_QWORD *)&v29 + 24i64);
    }
    v30 = v19->SA.Length;
    if ( v30 != v19->SA.ValueA.Data.Size )
    {
      v19->SA.ValueHHighInd = v30;
      key.pFirst = &v19->SA.ValueHHighInd;
      key.pSecond = &v63;
      Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
        (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v19->SA.ValueH.mHash.pTable,
        v19->SA.ValueH.mHash.pHeap,
        &key);
      goto LABEL_51;
    }
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v19->SA.ValueA.Data.Data,
      v19->SA.ValueA.Data.pHeap,
      v19->SA.ValueA.Data.Size + 1);
    v31 = 32 * v19->SA.ValueA.Data.Size;
    v32 = (signed __int64)&v19->SA.ValueA.Data.Data[-1];
    v33 = v31 + v32 == 0;
    v34 = (Scaleform::GFx::AS3::Value::VU *)(v31 + v32);
    v77 = v34;
    v74 = v34;
    if ( !v33 )
    {
      LODWORD(v34->VS._1.VStr) = v63.Flags;
      v34->VS._2.VObj = (Scaleform::GFx::AS3::Object *)v63.Bonus.pWeakProxy;
      v34[1] = v63.value;
      v35 = v63.Flags & 0x1F;
      if ( v35 > 9 )
      {
        if ( (v63.Flags >> 9) & 1 )
        {
          ++v63.Bonus.pWeakProxy->RefCount;
          goto LABEL_51;
        }
        if ( v35 == 10 )
        {
          ++*(_DWORD *)(*(_QWORD *)&v63.value.VNumber + 24i64);
        }
        else
        {
          if ( v35 <= 10 )
            goto LABEL_51;
          if ( v35 <= 15 )
          {
            v36 = v63.value.VNumber;
          }
          else
          {
            if ( v35 > 17 )
              goto LABEL_51;
            v36 = *(double *)&v63.value.VS._2.VObj;
          }
          if ( v36 != 0.0 )
          {
            ++*(_DWORD *)(*(_QWORD *)&v36 + 32i64);
            *(_DWORD *)(*(_QWORD *)&v36 + 32i64) &= 0x8FBFFFFF;
          }
        }
      }
    }
LABEL_51:
    ++v19->SA.Length;
    if ( (v63.Flags & 0x1F) > 9 )
    {
      if ( (v63.Flags >> 9) & 1 )
      {
        v33 = v63.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v33 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v63.Bonus.pWeakProxy = 0i64;
        v63.value = 0ui64;
        v63.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v63);
      }
    }
    v37 = v73.pNode;
    v33 = v73.pNode->RefCount == 1;
    --v37->RefCount;
    if ( v33 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v37);
    v20 = -1;
    if ( !_InterlockedDecrement((volatile signed __int32 *)((str.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    v17 = (Scaleform::GFx::AS3::Instances::fl::RegExp *)v.value.VS._1.VStr;
    v19 = v64.pV;
    v8 = v58;
  }
  if ( v21 < (unsigned int)v68 )
  {
    Scaleform::String::String(&v71, &resulta.pNode->pData[v20], resulta.pNode->Size - v20);
    v38 = (long double *)Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                           v66,
                           &v75,
                           &v71);
    v62.Flags = 10;
    v62.Bonus.pWeakProxy = 0i64;
    v39 = *v38;
    v62.value.VNumber = *v38;
    if ( *(_QWORD *)v38 == *(_QWORD *)(*(_QWORD *)v38 + 8i64) + 104i64 )
    {
      v84 = 0i64;
      v62.value = (Scaleform::GFx::AS3::Value::VU)__PAIR__(v85, 0i64);
      v62.Flags = 12;
    }
    else
    {
      ++*(_DWORD *)(*(_QWORD *)&v39 + 24i64);
    }
    v40 = v19->SA.Length;
    if ( v40 != v19->SA.ValueA.Data.Size )
    {
      v19->SA.ValueHHighInd = v40;
      v80.pFirst = &v19->SA.ValueHHighInd;
      v80.pSecond = &v62;
      Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
        (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)&v19->SA.ValueH.mHash.pTable,
        v19->SA.ValueH.mHash.pHeap,
        &v80);
      goto LABEL_82;
    }
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)&v19->SA.ValueA.Data.Data,
      v19->SA.ValueA.Data.pHeap,
      v19->SA.ValueA.Data.Size + 1);
    v41 = 32 * v19->SA.ValueA.Data.Size;
    v42 = (signed __int64)&v19->SA.ValueA.Data.Data[-1];
    v33 = v41 + v42 == 0;
    v43 = (Scaleform::GFx::AS3::Value::VU *)(v41 + v42);
    v74 = v43;
    v77 = v43;
    if ( !v33 )
    {
      LODWORD(v43->VS._1.VStr) = v62.Flags;
      v43->VS._2.VObj = (Scaleform::GFx::AS3::Object *)v62.Bonus.pWeakProxy;
      v43[1] = v62.value;
      v44 = v62.Flags & 0x1F;
      if ( v44 > 9 )
      {
        if ( (v62.Flags >> 9) & 1 )
        {
          ++v62.Bonus.pWeakProxy->RefCount;
          goto LABEL_82;
        }
        if ( v44 == 10 )
        {
          ++*(_DWORD *)(*(_QWORD *)&v62.value.VNumber + 24i64);
        }
        else if ( v44 > 10 )
        {
          if ( v44 <= 15 )
          {
            v45 = v62.value.VNumber;
            goto LABEL_77;
          }
          if ( v44 <= 17 )
          {
            v45 = *(double *)&v62.value.VS._2.VObj;
LABEL_77:
            if ( v45 != 0.0 )
            {
              ++*(_DWORD *)(*(_QWORD *)&v45 + 32i64);
              *(_DWORD *)(*(_QWORD *)&v45 + 32i64) &= 0x8FBFFFFF;
            }
          }
        }
      }
    }
LABEL_82:
    ++v19->SA.Length;
    if ( (v62.Flags & 0x1F) > 9 )
    {
      if ( (v62.Flags >> 9) & 1 )
      {
        v33 = v62.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v33 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v62.Bonus.pWeakProxy = 0i64;
        v62.value = 0ui64;
        v62.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v62);
      }
    }
    v46 = v75.pNode;
    v33 = v75.pNode->RefCount == 1;
    --v46->RefCount;
    if ( v33 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v46);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((v71.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    v19 = v64.pV;
    v17 = (Scaleform::GFx::AS3::Instances::fl::RegExp *)v.value.VS._1.VStr;
  }
  Scaleform::GFx::AS3::Value::Assign(v90, (Scaleform::GFx::AS3::Object *)&v19->vfptr);
  if ( v19 )
  {
    if ( (unsigned __int8)v19 & 1 )
    {
      v76 = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)v19 - 1);
    }
    else
    {
      v47 = v19->RefCount;
      if ( v47 & 0x3FFFFF )
      {
        v19->RefCount = v47 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v19->vfptr);
      }
    }
  }
  v48 = v65.pNode;
  v33 = v65.pNode->RefCount == 1;
  --v48->RefCount;
  if ( v33 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v48);
  if ( v17 )
  {
    if ( v.value.VS._1.VBool )
    {
      v69.VStr = (Scaleform::GFx::ASStringNode *)((char *)&v17[-1].DynAttrs.mHash.pTable + 7);
    }
    else
    {
      v49 = v17->RefCount;
      if ( v49 & 0x3FFFFF )
      {
        v17->RefCount = v49 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v17->vfptr);
      }
    }
  }
LABEL_126:
  v9 = v.Flags;
  v10 = v.Bonus.pWeakProxy;
LABEL_127:
  if ( (char)(v9 & 0x1F) > 9 )
  {
    if ( (v9 >> 9) & 1 )
    {
      v33 = v10->RefCount-- == 1;
      if ( v33 )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v10);
      v.Bonus.pWeakProxy = 0i64;
      v.value = 0ui64;
      v.Flags = v9 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
    }
  }
LABEL_133:
  v56 = resulta.pNode;
  v33 = resulta.pNode->RefCount == 1;
  --v56->RefCount;
  if ( v33 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v56);
}

// File Line: 708
// RVA: 0x7A6CE0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::String::AS3substr(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v6; // r12
  Scaleform::GFx::AS3::Value *v7; // rbx
  Scaleform::GFx::AS3::StringManager *v8; // r15
  int v9; // edi
  int length; // ebx
  signed int v11; // esi
  Scaleform::GFx::AS3::Value *v12; // r14
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  bool v15; // zf
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::ASString self; // [rsp+30h] [rbp-48h]
  long double v18; // [rsp+38h] [rbp-40h]
  long double v19; // [rsp+40h] [rbp-38h]
  __int64 v20; // [rsp+48h] [rbp-30h]
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+88h] [rbp+10h]

  v20 = -2i64;
  v6 = result;
  v7 = _this;
  v8 = vm->StringManagerRef;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v8->Builtins,
    &self);
  if ( !Scaleform::GFx::AS3::Value::Convert2String(v7, &resulta, &self)->Result )
    goto LABEL_16;
  v9 = 0;
  length = -1;
  v11 = Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&self.pNode);
  v12 = argv;
  if ( argc >= 1 )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2Number(argv, &resulta, &v18)->Result )
      goto LABEL_16;
    v9 = v11;
    if ( v18 <= (double)v11 )
      v9 = (signed int)v18;
    if ( v9 < 0 )
      v9 += v11;
  }
  if ( argc >= 2 )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2Number(v12 + 1, &resulta, &v19)->Result )
      goto LABEL_16;
    length = v11;
    if ( v19 <= (double)v11 )
      length = (signed int)v19;
    if ( length < 0 )
      length = 0;
  }
  v13 = Scaleform::GFx::AS3::InstanceTraits::fl::String::StringSubstring(
          (Scaleform::GFx::ASString *)&resulta,
          v8,
          &self,
          v9,
          length);
  Scaleform::GFx::AS3::Value::Assign(v6, v13);
  v14 = *(Scaleform::GFx::ASStringNode **)&resulta.Result;
  v15 = *(_DWORD *)(*(_QWORD *)&resulta.Result + 24i64) == 1;
  --v14->RefCount;
  if ( v15 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
LABEL_16:
  v16 = self.pNode;
  v15 = self.pNode->RefCount == 1;
  --v16->RefCount;
  if ( v15 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
}

// File Line: 757
// RVA: 0x7A6E60
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::String::AS3substring(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value *v4; // r12
  Scaleform::GFx::AS3::Value *v5; // rbx
  Scaleform::GFx::AS3::StringManager *v6; // r15
  signed int v7; // ebx
  bool v8; // al
  char v9; // al
  double v10; // xmm0_8
  Scaleform::GFx::ASString *v11; // rax
  int v12; // er9
  int v13; // eax
  Scaleform::GFx::ASString *v14; // rax
  Scaleform::GFx::ASStringNode *v15; // rcx
  bool v16; // zf
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::ASString resulta; // [rsp+10h] [rbp-41h]
  long double v19; // [rsp+18h] [rbp-39h]
  long double v20; // [rsp+20h] [rbp-31h]
  __int64 v21; // [rsp+28h] [rbp-29h]
  int v22; // [rsp+30h] [rbp-21h]
  __int64 v23; // [rsp+38h] [rbp-19h]
  long double v24; // [rsp+40h] [rbp-11h]
  int v25; // [rsp+50h] [rbp-1h]
  __int64 v26; // [rsp+58h] [rbp+7h]
  long double v27; // [rsp+60h] [rbp+Fh]
  Scaleform::GFx::ASString v28; // [rsp+B0h] [rbp+5Fh]
  void *retaddr; // [rsp+C8h] [rbp+77h]
  Scaleform::GFx::AS3::Value *v30; // [rsp+D0h] [rbp+7Fh]

  v21 = -2i64;
  v4 = result;
  v5 = _this;
  v6 = vm->StringManagerRef;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v6->Builtins,
    (Scaleform::GFx::ASString *)&v23);
  if ( Scaleform::GFx::AS3::Value::Convert2String(v5, (Scaleform::GFx::AS3::CheckResult *)&v28, &resulta)->Result )
  {
    v7 = Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&resulta.pNode);
    v19 = 0.0;
    v20 = DOUBLE_2_147483647e9;
    v8 = (unsigned int)retaddr >= 1
      && !Scaleform::GFx::AS3::Value::Convert2Number(v30, (Scaleform::GFx::AS3::CheckResult *)&v28, &v19)->Result;
    if ( !v8 )
    {
      v9 = (unsigned int)retaddr < 2
        || Scaleform::GFx::AS3::Value::Convert2Number(v30 + 1, (Scaleform::GFx::AS3::CheckResult *)&v28, &v20)->Result ? 0 : 1;
      if ( !v9 )
      {
        v22 = 4;
        v23 = 0i64;
        v24 = v19;
        v28.pNode = *(Scaleform::GFx::ASStringNode **)&v19;
        if ( (*(_QWORD *)&v19 & 0x7FF0000000000000i64) == 9218868437227405312i64 && *(_QWORD *)&v19 & 0xFFFFFFFFFFFFFi64 )
          v19 = Scaleform::GFx::NumberUtil::NEGATIVE_INFINITY();
        v25 = 4;
        v26 = 0i64;
        v27 = v20;
        v28.pNode = *(Scaleform::GFx::ASStringNode **)&v20;
        if ( (*(_QWORD *)&v20 & 0x7FF0000000000000i64) == 9218868437227405312i64 && *(_QWORD *)&v20 & 0xFFFFFFFFFFFFFi64 )
        {
          v10 = Scaleform::GFx::NumberUtil::NEGATIVE_INFINITY();
          v20 = v10;
        }
        else
        {
          v10 = v20;
        }
        if ( v10 == v19 )
        {
          v11 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
                  (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v6->Builtins,
                  &v28);
          Scaleform::GFx::AS3::Value::Assign(v4, v11);
        }
        else
        {
          v12 = v7;
          if ( v19 <= (double)v7 )
            v12 = (signed int)v19;
          if ( v10 <= (double)v7 )
            v7 = (signed int)v10;
          if ( v7 < v12 )
          {
            v13 = v12;
            v12 = v7;
            v7 = v13;
          }
          if ( v12 < 0 )
            v12 = 0;
          v14 = Scaleform::GFx::AS3::InstanceTraits::fl::String::StringSubstring(&v28, v6, &resulta, v12, v7 - v12);
          Scaleform::GFx::AS3::Value::Assign(v4, v14);
        }
        v15 = v28.pNode;
        v16 = v28.pNode->RefCount == 1;
        --v15->RefCount;
        if ( v16 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v15);
      }
    }
  }
  v17 = resulta.pNode;
  v16 = resulta.pNode->RefCount == 1;
  --v17->RefCount;
  if ( v16 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
}e->RefCount =

// File Line: 824
// RVA: 0x7A78F0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::String::AS3toLowerCase(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value *v4; // rdi
  Scaleform::GFx::AS3::Value *v5; // rbx
  Scaleform::GFx::ASString *v6; // rax
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::GFx::ASStringNode *v9; // rcx
  Scaleform::GFx::ASString resulta; // [rsp+20h] [rbp-18h]
  __int64 v11; // [rsp+28h] [rbp-10h]
  Scaleform::GFx::AS3::CheckResult v12; // [rsp+48h] [rbp+10h]

  v11 = -2i64;
  v4 = result;
  v5 = _this;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)vm->StringManagerRef->Builtins,
    &resulta);
  if ( Scaleform::GFx::AS3::Value::Convert2String(v5, &v12, &resulta)->Result )
  {
    v6 = Scaleform::GFx::ASString::ToLower(&resulta, (Scaleform::GFx::ASString *)&v12);
    Scaleform::GFx::AS3::Value::Assign(v4, v6);
    v7 = *(Scaleform::GFx::ASStringNode **)&v12.Result;
    v8 = *(_DWORD *)(*(_QWORD *)&v12.Result + 24i64) == 1;
    --v7->RefCount;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  }
  v9 = resulta.pNode;
  v8 = resulta.pNode->RefCount == 1;
  --v9->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
}

// File Line: 844
// RVA: 0x7A8B20
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::String::AS3toLocaleUpperCase(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value *v4; // rdi
  Scaleform::GFx::AS3::Value *v5; // rbx
  Scaleform::GFx::ASString *v6; // rax
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::GFx::ASStringNode *v9; // rcx
  Scaleform::GFx::ASString resulta; // [rsp+20h] [rbp-18h]
  __int64 v11; // [rsp+28h] [rbp-10h]
  Scaleform::GFx::AS3::CheckResult v12; // [rsp+48h] [rbp+10h]

  v11 = -2i64;
  v4 = result;
  v5 = _this;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)vm->StringManagerRef->Builtins,
    &resulta);
  if ( Scaleform::GFx::AS3::Value::Convert2String(v5, &v12, &resulta)->Result )
  {
    v6 = Scaleform::GFx::ASString::ToUpper(&resulta, (Scaleform::GFx::ASString *)&v12);
    Scaleform::GFx::AS3::Value::Assign(v4, v6);
    v7 = *(Scaleform::GFx::ASStringNode **)&v12.Result;
    v8 = *(_DWORD *)(*(_QWORD *)&v12.Result + 24i64) == 1;
    --v7->RefCount;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  }
  v9 = resulta.pNode;
  v8 = resulta.pNode->RefCount == 1;
  --v9->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
}

// File Line: 904
// RVA: 0x7A8270
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::String::AS3valueOf(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::VM *v4; // rbx
  Scaleform::GFx::AS3::VM::Error *v5; // rax
  Scaleform::GFx::ASStringNode *v6; // rcx
  bool v7; // zf
  Scaleform::GFx::AS3::VM::Error v8; // [rsp+28h] [rbp-20h]

  v4 = vm;
  if ( (_this->Flags & 0x1F) == 10 )
  {
    Scaleform::GFx::AS3::Value::Assign(result, _this);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v8, eIllegalOperandTypeError, vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(v4, v5, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    v6 = v8.Message.pNode;
    v7 = v8.Message.pNode->RefCount == 1;
    --v6->RefCount;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  }
}

// File Line: 949
// RVA: 0x741A80
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::String::valueOfProto(Scaleform::GFx::AS3::ThunkInfo *ti, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::AS3::Value *_this, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value *v4; // rbp
  Scaleform::GFx::AS3::Value *v5; // rbx
  Scaleform::GFx::AS3::VM *v6; // rsi
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
  v8 = vm->TraitsString.pObject->ITraits.pObject;
  if ( !v8->pConstructor.pObject )
    v8->vfptr[3].~RefCountBaseGC<328>((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v8->vfptr);
  if ( *(Scaleform::GFx::AS3::Object **)&v7 != Scaleform::GFx::AS3::Class::GetPrototype(v8->pConstructor.pObject) )
  {
LABEL_12:
    if ( (v5->Flags & 0x1F) == 10 )
    {
      Scaleform::GFx::AS3::Value::Assign(v4, v5);
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v12, eIllegalOperandTypeError, v6);
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
    Scaleform::GFx::AS3::Value::Assign(v4, (Scaleform::GFx::ASString *)v6->StringManagerRef);
  }
}

// File Line: 967
// RVA: 0x7BF7C0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl::CreateStringFromCStr(Scaleform::GFx::ASString *result, Scaleform::GFx::AS3::StringManager *sm, const char *start, const char *end)
{
  Scaleform::GFx::ASString *v4; // rbx
  signed __int64 v5; // rax

  v4 = result;
  if ( end )
  {
    LODWORD(v5) = (_DWORD)end - (_DWORD)start;
  }
  else
  {
    v5 = -1i64;
    do
      ++v5;
    while ( start[v5] );
  }
  if ( (signed int)v5 < 1 )
    Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
      (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)sm->Builtins,
      result);
  else
    Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
      (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)sm->Builtins,
      result,
      start,
      (signed int)v5);
  return v4;
}

// File Line: 977
// RVA: 0x822970
Scaleform::String::DataDesc *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl::String::StringSplit(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> *result, Scaleform::GFx::AS3::VM *vm, Scaleform::GFx::ASString *str, const char *delimiters, unsigned int limit)
{
  char *v5; // r15
  char ***v6; // rbx
  Scaleform::GFx::AS3::VM *v7; // r13
  __int64 *v8; // r14
  char **v9; // r8
  char *v10; // rax
  bool v11; // zf
  __int64 v12; // rsi
  __int64 v13; // rcx
  signed __int64 v14; // rcx
  signed __int64 v15; // rdx
  signed __int64 v16; // rdx
  int v17; // eax
  long double v18; // rax
  Scaleform::GFx::AS3::Value::VU v19; // di
  unsigned int v20; // ebx
  long double *v21; // rax
  long double v22; // rdx
  Scaleform::GFx::ASStringNode *v23; // rcx
  unsigned int v24; // er12
  const char *v25; // r13
  char *v26; // rbx
  char *v27; // r15
  unsigned int v28; // er14
  unsigned int v29; // esi
  char *v30; // rbx
  long double *v31; // rax
  long double v32; // rdx
  Scaleform::GFx::ASStringNode *v33; // rcx
  Scaleform::GFx::ASStringNode *v34; // rdx
  long double *v35; // rax
  long double v36; // rdx
  Scaleform::GFx::ASStringNode *v37; // rcx
  long double *v38; // rax
  long double v39; // rdx
  Scaleform::GFx::ASStringNode *v40; // rcx
  Scaleform::GFx::AS3::Value v42; // [rsp+20h] [rbp-E0h]
  char *end; // [rsp+40h] [rbp-C0h]
  Scaleform::GFx::AS3::Value v44; // [rsp+48h] [rbp-B8h]
  char *v45; // [rsp+68h] [rbp-98h]
  Scaleform::GFx::AS3::Value v46; // [rsp+70h] [rbp-90h]
  Scaleform::GFx::AS3::Value v; // [rsp+90h] [rbp-70h]
  Scaleform::GFx::AS3::Value v48; // [rsp+B0h] [rbp-50h]
  Scaleform::GFx::AS3::Value v49; // [rsp+D0h] [rbp-30h]
  Scaleform::GFx::ASString v50; // [rsp+F0h] [rbp-10h]
  Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef key; // [rsp+F8h] [rbp-8h]
  long double v52; // [rsp+108h] [rbp+8h]
  Scaleform::GFx::AS3::Value::V2U v53; // [rsp+110h] [rbp+10h]
  __int64 v54; // [rsp+118h] [rbp+18h]
  Scaleform::GFx::AS3::Value::V2U v55; // [rsp+128h] [rbp+28h]
  Scaleform::GFx::AS3::Value::V2U v56; // [rsp+138h] [rbp+38h]
  Scaleform::GFx::AS3::Value::V2U v57; // [rsp+148h] [rbp+48h]
  Scaleform::GFx::AS3::Value::V2U v58; // [rsp+158h] [rbp+58h]
  Scaleform::GFx::AS3::Value::V2U v59; // [rsp+168h] [rbp+68h]
  Scaleform::String stra; // [rsp+1C0h] [rbp+C0h]
  Scaleform::GFx::ASString resulta; // [rsp+1C8h] [rbp+C8h]
  char *putf8Buffer; // [rsp+1D0h] [rbp+D0h]
  Scaleform::GFx::ASString v63; // [rsp+1D8h] [rbp+D8h]

  v63.pNode = (Scaleform::GFx::ASStringNode *)delimiters;
  resulta.pNode = (Scaleform::GFx::ASStringNode *)vm;
  stra.pData = (Scaleform::String::DataDesc *)result;
  v54 = -2i64;
  v5 = (char *)delimiters;
  v6 = (char ***)str;
  v7 = vm;
  v8 = (__int64 *)result;
  Scaleform::GFx::AS3::InstanceTraits::fl::Array::MakeInstance(
    result,
    (Scaleform::GFx::AS3::InstanceTraits::fl::Array *)vm->TraitsArray.pObject->ITraits.pObject);
  v9 = *v6;
  v10 = **v6;
  putf8Buffer = **v6;
  if ( !v5 )
  {
    v.Flags = 10;
    v.Bonus.pWeakProxy = 0i64;
    *(_QWORD *)&v.value.VNumber = v9;
    if ( v9 == (char **)(v9[1] + 104) )
    {
      v.value.VNumber = 0.0;
      v.value.VS._2 = v59;
      v.Flags = 12;
    }
    else
    {
      ++*((_DWORD *)v9 + 6);
    }
    Scaleform::GFx::AS3::Impl::SparseArray::PushBack((Scaleform::GFx::AS3::Impl::SparseArray *)(*v8 + 56), &v);
    if ( (v.Flags & 0x1F) > 9 )
    {
      if ( (v.Flags >> 9) & 1 )
      {
        v11 = v.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v11 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v.Bonus.pWeakProxy = 0i64;
        v.value = 0ui64;
        v.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
      }
    }
    return (Scaleform::String::DataDesc *)v8;
  }
  if ( *v5 )
  {
    v24 = 0;
    v25 = v10;
    while ( 2 )
    {
      v45 = v5;
      end = v10;
      v26 = 0i64;
      while ( 1 )
      {
        v27 = v10;
        v28 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
        if ( !v28 )
          --putf8Buffer;
        v29 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&v45);
        if ( !v29 )
          --v45;
        v10 = putf8Buffer;
        if ( !v26 )
          v26 = putf8Buffer;
        if ( !v28 )
          break;
        if ( !v29 )
          goto LABEL_66;
        if ( v28 != v29 )
        {
          v10 = v26;
          putf8Buffer = v26;
          break;
        }
      }
      if ( v29 )
      {
        v30 = end;
      }
      else
      {
LABEL_66:
        if ( v24 >= limit )
          return stra.pData;
        v30 = end;
        v31 = (long double *)Scaleform::GFx::AS3::InstanceTraits::fl::CreateStringFromCStr(
                               &v50,
                               (Scaleform::GFx::AS3::StringManager *)resulta.pNode->pLower,
                               v25,
                               end);
        v46.Flags = 10;
        v46.Bonus.pWeakProxy = 0i64;
        v32 = *v31;
        v46.value.VNumber = *v31;
        if ( *(_QWORD *)v31 == *(_QWORD *)(*(_QWORD *)v31 + 8i64) + 104i64 )
        {
          v46.value.VNumber = 0.0;
          v46.value.VS._2 = v55;
          v46.Flags = 12;
        }
        else
        {
          ++*(_DWORD *)(*(_QWORD *)&v32 + 24i64);
        }
        Scaleform::GFx::AS3::Impl::SparseArray::PushBack(
          (Scaleform::GFx::AS3::Impl::SparseArray *)(stra.pData->Size + 56),
          &v46);
        if ( (v46.Flags & 0x1F) > 9 )
        {
          if ( (v46.Flags >> 9) & 1 )
          {
            v11 = v46.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v11 )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            v46.Bonus.pWeakProxy = 0i64;
            v46.value = 0ui64;
            v46.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v46);
          }
        }
        v33 = v50.pNode;
        v11 = v50.pNode->RefCount == 1;
        --v33->RefCount;
        if ( v11 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v33);
        v25 = v27;
        v10 = v27;
        putf8Buffer = v27;
        ++v24;
      }
      v5 = (char *)v63.pNode;
      if ( v28 )
        continue;
      break;
    }
    if ( v24 < limit )
    {
      v34 = resulta.pNode->pLower;
      if ( v29 )
      {
        v38 = (long double *)Scaleform::GFx::AS3::InstanceTraits::fl::CreateStringFromCStr(
                               (Scaleform::GFx::ASString *)&end,
                               (Scaleform::GFx::AS3::StringManager *)v34,
                               v25,
                               0i64);
        v44.Flags = 10;
        v44.Bonus.pWeakProxy = 0i64;
        v39 = *v38;
        v44.value.VNumber = *v38;
        if ( *(_QWORD *)v38 == *(_QWORD *)(*(_QWORD *)v38 + 8i64) + 104i64 )
        {
          v44.value.VNumber = 0.0;
          v44.value.VS._2 = v56;
          v44.Flags = 12;
        }
        else
        {
          ++*(_DWORD *)(*(_QWORD *)&v39 + 24i64);
        }
        v8 = (__int64 *)stra.pData;
        Scaleform::GFx::AS3::Impl::SparseArray::PushBack(
          (Scaleform::GFx::AS3::Impl::SparseArray *)(stra.pData->Size + 56),
          &v44);
        if ( (v44.Flags & 0x1F) > 9 )
        {
          if ( (v44.Flags >> 9) & 1 )
          {
            v11 = v44.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v11 )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            v44.Bonus.pWeakProxy = 0i64;
            v44.value = 0ui64;
            v44.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v44);
          }
        }
        v40 = (Scaleform::GFx::ASStringNode *)end;
        v11 = *((_DWORD *)end + 6) == 1;
        --v40->RefCount;
        if ( v11 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v40);
      }
      else
      {
        v35 = (long double *)Scaleform::GFx::AS3::InstanceTraits::fl::CreateStringFromCStr(
                               &v63,
                               (Scaleform::GFx::AS3::StringManager *)v34,
                               v25,
                               v30);
        v48.Flags = 10;
        v48.Bonus.pWeakProxy = 0i64;
        v36 = *v35;
        v48.value.VNumber = *v35;
        if ( *(_QWORD *)v35 == *(_QWORD *)(*(_QWORD *)v35 + 8i64) + 104i64 )
        {
          v48.value.VNumber = 0.0;
          v48.value.VS._2 = v58;
          v48.Flags = 12;
        }
        else
        {
          ++*(_DWORD *)(*(_QWORD *)&v36 + 24i64);
        }
        v8 = (__int64 *)stra.pData;
        Scaleform::GFx::AS3::Impl::SparseArray::PushBack(
          (Scaleform::GFx::AS3::Impl::SparseArray *)(stra.pData->Size + 56),
          &v48);
        if ( (v48.Flags & 0x1F) > 9 )
        {
          if ( (v48.Flags >> 9) & 1 )
          {
            v11 = v48.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v11 )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            v48.Bonus.pWeakProxy = 0i64;
            v48.value = 0ui64;
            v48.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v48);
          }
        }
        v37 = v63.pNode;
        v11 = v63.pNode->RefCount == 1;
        --v37->RefCount;
        if ( v11 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v37);
      }
      return (Scaleform::String::DataDesc *)v8;
    }
    return stra.pData;
  }
  if ( !*((_DWORD *)v9 + 8) )
  {
    v42.Flags = 10;
    v42.Bonus.pWeakProxy = 0i64;
    *(_QWORD *)&v42.value.VNumber = v9;
    if ( v9 == (char **)(v9[1] + 104) )
    {
      v42.value.VNumber = 0.0;
      v42.value.VS._2 = v57;
      v42.Flags = 12;
    }
    else
    {
      ++*((_DWORD *)v9 + 6);
    }
    v12 = *v8;
    v13 = *(_QWORD *)(*v8 + 56);
    if ( v13 != *(_QWORD *)(*v8 + 120) )
    {
      *(_QWORD *)(v12 + 72) = v13;
      key.pFirst = (const unsigned __int64 *)(v12 + 72);
      key.pSecond = &v42;
      Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
        (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)(v12 + 144),
        *(void **)(v12 + 152),
        &key);
      goto LABEL_32;
    }
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)(v12 + 112),
      *(const void **)(v12 + 136),
      *(_QWORD *)(v12 + 120) + 1i64);
    v14 = 32i64 * *(_QWORD *)(v12 + 120);
    v15 = *(_QWORD *)(v12 + 112) - 32i64;
    v11 = v14 + v15 == 0;
    v16 = v14 + v15;
    stra.pData = (Scaleform::String::DataDesc *)v16;
    resulta.pNode = (Scaleform::GFx::ASStringNode *)v16;
    if ( !v11 )
    {
      *(_DWORD *)v16 = v42.Flags;
      *(_QWORD *)(v16 + 8) = v42.Bonus.pWeakProxy;
      *(Scaleform::GFx::AS3::Value::VU *)(v16 + 16) = v42.value;
      v17 = v42.Flags & 0x1F;
      if ( v17 > 9 )
      {
        if ( (v42.Flags >> 9) & 1 )
        {
          ++v42.Bonus.pWeakProxy->RefCount;
          goto LABEL_32;
        }
        if ( v17 == 10 )
        {
          ++*(_DWORD *)(*(_QWORD *)&v42.value.VNumber + 24i64);
        }
        else if ( v17 > 10 )
        {
          if ( v17 <= 15 )
          {
            v18 = v42.value.VNumber;
LABEL_27:
            if ( v18 != 0.0 )
            {
              ++*(_DWORD *)(*(_QWORD *)&v18 + 32i64);
              *(_DWORD *)(*(_QWORD *)&v18 + 32i64) &= 0x8FBFFFFF;
            }
            goto LABEL_32;
          }
          if ( v17 <= 17 )
          {
            v18 = *(double *)&v42.value.VS._2.VObj;
            goto LABEL_27;
          }
        }
      }
    }
LABEL_32:
    ++*(_QWORD *)(v12 + 56);
    if ( (v42.Flags & 0x1F) > 9 )
    {
      if ( (v42.Flags >> 9) & 1 )
      {
        v11 = v42.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v11 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v42.Bonus.pWeakProxy = 0i64;
        v42.value = 0ui64;
        v42.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v42);
      }
    }
    return (Scaleform::String::DataDesc *)v8;
  }
  Scaleform::String::String(&stra);
  v19.VNumber = 0.0;
  v19.VS._2 = v53;
  while ( 1 )
  {
    v20 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
    if ( !v20 )
      break;
    Scaleform::String::Clear(&stra);
    Scaleform::String::AppendChar(&stra, v20);
    v21 = (long double *)Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                           (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v7->StringManagerRef->Builtins,
                           &resulta,
                           &stra);
    v49.Flags = 10;
    v49.Bonus.pWeakProxy = 0i64;
    v22 = *v21;
    v49.value.VNumber = *v21;
    if ( *(_QWORD *)v21 == *(_QWORD *)(*(_QWORD *)v21 + 8i64) + 104i64 )
    {
      v52 = v19.VNumber;
      v49.value = v19;
      v49.Flags = 12;
    }
    else
    {
      ++*(_DWORD *)(*(_QWORD *)&v22 + 24i64);
    }
    Scaleform::GFx::AS3::Impl::SparseArray::PushBack((Scaleform::GFx::AS3::Impl::SparseArray *)(*v8 + 56), &v49);
    if ( (v49.Flags & 0x1F) > 9 )
    {
      if ( (v49.Flags >> 9) & 1 )
      {
        v11 = v49.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v11 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v49.Bonus.pWeakProxy = 0i64;
        v49.value = 0ui64;
        v49.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v49);
      }
    }
    v23 = resulta.pNode;
    v11 = resulta.pNode->RefCount == 1;
    --v23->RefCount;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v23);
  }
  --putf8Buffer;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((stra.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  return (Scaleform::String::DataDesc *)v8;
}lue::ReleaseInternal(&v49);
      }
    }
    v23 = resulta.pNode;
    v11 = resulta.pNode->RefCount == 1;
    --v23->RefCount;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v23);
  }
  --putf8Buffer;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((stra.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (*)(void))Scaleform::Memory:

// File Line: 1071
// RVA: 0x8230D0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl::String::StringSubstring(Scaleform::GFx::ASString *result, Scaleform::GFx::AS3::StringManager *sm, Scaleform::GFx::ASString *self, int start, int length)
{
  int v5; // esi
  Scaleform::GFx::ASString *v6; // r14
  Scaleform::GFx::AS3::StringManager *v7; // rbp
  Scaleform::GFx::ASString *v8; // rdi
  int v9; // ebx
  int v10; // ecx

  v5 = start;
  v6 = self;
  v7 = sm;
  v8 = result;
  v9 = length;
  if ( length )
  {
    if ( start < 0 )
      v5 = 0;
    v10 = Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&self->pNode);
    if ( v5 < v10 )
    {
      if ( length < 0 || v5 + length > v10 )
        v9 = v10 - v5;
      Scaleform::GFx::ASString::Substring(v6, v8, v5, v5 + v9);
    }
    else
    {
      Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
        (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v7->Builtins,
        v8);
    }
  }
  else
  {
    Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
      (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)sm->Builtins,
      result);
  }
  return v8;
}

// File Line: 1141
// RVA: 0x79E4A0
void __fastcall Scaleform::GFx::AS3::Classes::fl::String::AS3fromCharCode(Scaleform::GFx::AS3::Classes::fl::String *this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *const argv)
{
  Scaleform::GFx::AS3::Value *v4; // rsi
  unsigned int v5; // edi
  Scaleform::GFx::AS3::Value *v6; // rbp
  Scaleform::GFx::AS3::Classes::fl::String *v7; // r14
  int v8; // ebx
  char *v9; // r8
  Scaleform::GFx::ASString *v10; // rax
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  unsigned int v13; // [rsp+20h] [rbp-68h]
  Scaleform::GFx::ASString v14; // [rsp+28h] [rbp-60h]
  __int64 v15; // [rsp+30h] [rbp-58h]
  Scaleform::StringBuffer v16; // [rsp+38h] [rbp-50h]
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+A0h] [rbp+18h]

  v15 = -2i64;
  v4 = argv;
  v5 = argc;
  v6 = result;
  v7 = this;
  Scaleform::StringBuffer::StringBuffer(&v16, Scaleform::Memory::pGlobalHeap);
  v8 = 0;
  if ( v5 )
  {
    while ( Scaleform::GFx::AS3::Value::Convert2UInt32(&v4[v8], &resulta, &v13)->Result )
    {
      Scaleform::StringBuffer::AppendChar(&v16, (unsigned __int16)v13);
      if ( ++v8 >= v5 )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    v9 = &customWorldMapCaption;
    if ( v16.pData )
      v9 = v16.pData;
    v10 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
            (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v7->pTraits.pObject->pVM->StringManagerRef->Builtins,
            &v14,
            v9,
            v16.Size);
    Scaleform::GFx::AS3::Value::Assign(v6, v10);
    v11 = v14.pNode;
    v12 = v14.pNode->RefCount == 1;
    --v11->RefCount;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  }
  Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&v16);
}

// File Line: 1156
// RVA: 0x849B00
void __fastcall Scaleform::GFx::AS3::Classes::fl::String::fromCharCode(Scaleform::GFx::AS3::Classes::fl::String *this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *const argv)
{
  Scaleform::GFx::AS3::Classes::fl::String::AS3fromCharCode(this, result, argc, argv);
}

// File Line: 1169
// RVA: 0x7B8ED0
void __fastcall Scaleform::GFx::AS3::Classes::fl::String::Construct(Scaleform::GFx::AS3::Classes::fl::String *this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v4; // rsi
  unsigned int v5; // ebx
  Scaleform::GFx::AS3::Value *v6; // rdi
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::GFx::ASString resulta; // [rsp+40h] [rbp+8h]
  Scaleform::GFx::AS3::CheckResult v10; // [rsp+50h] [rbp+18h]

  v4 = argv;
  v5 = argc;
  v6 = result;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)this->pTraits.pObject->pVM->StringManagerRef->Builtins,
    &resulta);
  if ( !v5 || Scaleform::GFx::AS3::Value::Convert2String(v4, &v10, &resulta)->Result )
    Scaleform::GFx::AS3::Value::Assign(v6, &resulta);
  v7 = resulta.pNode;
  v8 = resulta.pNode->RefCount == 1;
  --v7->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
}

// File Line: 1194
// RVA: 0x7F4CF0
void __fastcall Scaleform::GFx::AS3::Classes::fl::String::InitPrototype(Scaleform::GFx::AS3::Classes::fl::String *this, Scaleform::GFx::AS3::Object *obj)
{
  Scaleform::GFx::AS3::Classes::fl::String *v2; // rbp
  Scaleform::GFx::AS3::Class *v3; // rcx
  Scaleform::GFx::AS3::Object *v4; // rsi
  Scaleform::GFx::AS3::ThunkInfo *v5; // rbx
  signed __int64 v6; // rdi
  __m128i v7; // [rsp+20h] [rbp-18h]

  v2 = this;
  v3 = this->ParentClass.pObject;
  v4 = obj;
  if ( v3 )
    ((void (*)(void))v3->vfptr[7].Finalize_GC)();
  v7.m128i_i32[2] = 0;
  v7.m128i_i64[0] = (__int64)Scaleform::GFx::AS3::Class::ConvertCopy;
  _mm_store_si128(&v7, v7);
  Scaleform::GFx::AS3::Class::InitPrototypeFromVTable(
    (Scaleform::GFx::AS3::Class *)&v2->vfptr,
    v4,
    (Scaleform::GFx::AS3::Value *(__fastcall *)(Scaleform::GFx::AS3::Class *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))&v7);
  v5 = Scaleform::GFx::AS3::Classes::fl::String::f;
  v6 = 2i64;
  do
  {
    Scaleform::GFx::AS3::Object::AddDynamicFunc(v4, v5);
    ++v5;
    --v6;
  }
  while ( v6 );
  Scaleform::GFx::AS3::Class::AddConstructor((Scaleform::GFx::AS3::Class *)&v2->vfptr, v4);
}

// File Line: 1213
// RVA: 0x1595BF0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Classes::fl::String_0_Scaleform::GFx::AS3::Value_unsigned_int_Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243A5C0 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Classes::fl::String,0,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Classes::fl::String *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Classes::fl::String::AS3fromCharCode;
  return result;
}

// File Line: 1214
// RVA: 0x1595BC0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Classes::fl::String_1_Scaleform::GFx::AS3::Value_unsigned_int_Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243A5D0 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Classes::fl::String,1,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Classes::fl::String *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Classes::fl::String::fromCharCode;
  return result;
}

// File Line: 1226
// RVA: 0x15971C0
const char *dynamic_initializer_for__Scaleform::GFx::AS3::ClassTraits::fl::String::ti__()
{
  const char *result; // rax

  result = Scaleform::GFx::AS3::NS_AS3;
  Scaleform::GFx::AS3::ClassTraits::fl::String::ti[0].NamespaceName = Scaleform::GFx::AS3::NS_AS3;
  return result;
}

// File Line: 1240
// RVA: 0x744290
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl::String::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // rbp
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v3; // rdi
  Scaleform::MemoryHeap *v4; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rbx
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> v8; // rbx
  Scaleform::GFx::AS3::Class *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rbx

  v2 = vm;
  v3 = result;
  v4 = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->vfptr->Alloc(v4, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, v2, &Scaleform::GFx::AS3::fl::StringCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::String::`vftable;
    v6->TraitsType = 5;
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
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, v2, &Scaleform::GFx::AS3::fl::StringCI);
    v8.pV->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
    v8.pV->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::String::`vftable;
    v8.pV->TraitsType = 5;
  }
  else
  {
    v8.pV = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(v3->pV, v8);
  v9 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v4->vfptr->Alloc)(
                                       v4,
                                       72i64);
  v10 = v9;
  if ( v9 )
  {
    Scaleform::GFx::AS3::Class::Class(v9, v3->pV);
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl::String::`vftable;
  }
  return v3;
}

// File Line: 1254
// RVA: 0x7B6A00
char __fastcall Scaleform::GFx::AS3::ClassTraits::fl::String::Coerce(Scaleform::GFx::AS3::ClassTraits::fl::String *this, Scaleform::GFx::AS3::Value *value, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::Value *v4; // rdi
  __int64 v5; // r8
  Scaleform::GFx::ASStringNode *v6; // rcx
  bool v7; // zf
  Scaleform::GFx::ASStringNode *v9; // rcx
  Scaleform::GFx::AS3::WeakProxy *v10; // rdx
  Scaleform::GFx::AS3::Value::V2U v11; // [rsp+30h] [rbp-18h]
  Scaleform::GFx::AS3::CheckResult v12; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::ASString resulta; // [rsp+68h] [rbp+20h]

  v3 = result;
  v4 = value;
  v5 = value->Flags & 0x1F;
  if ( !(value->Flags & 0x1F) || ((unsigned int)(v5 - 12) <= 3 || (_DWORD)v5 == 10) && !*(_QWORD *)&value->value.VNumber )
  {
    if ( (v3->Flags & 0x1F) > 9 )
    {
      if ( (v3->Flags >> 9) & 1 )
      {
        v10 = v3->Bonus.pWeakProxy;
        v7 = v10->RefCount-- == 1;
        if ( v7 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::WeakProxy *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
            Scaleform::Memory::pGlobalHeap,
            v10,
            v5);
        v3->Bonus.pWeakProxy = 0i64;
        v3->value.VNumber = 0.0;
        v3->value.VS._2.VObj = 0i64;
        v3->Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(v3);
      }
    }
    v3->value.VNumber = 0.0;
    v3->value.VS._2 = v11;
    v3->Flags &= 0xFFFFFFEC;
    v3->Flags |= 0xCu;
    return 1;
  }
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)this->pVM->StringManagerRef->Builtins,
    &resulta);
  if ( Scaleform::GFx::AS3::Value::Convert2String(v4, &v12, &resulta)->Result )
  {
    Scaleform::GFx::AS3::Value::Assign(v3, &resulta);
    v9 = resulta.pNode;
    v7 = resulta.pNode->RefCount == 1;
    --v9->RefCount;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
    return 1;
  }
  v6 = resulta.pNode;
  v7 = resulta.pNode->RefCount == 1;
  --v6->RefCount;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  return 0;
}

