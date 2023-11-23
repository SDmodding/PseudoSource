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
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::String::lengthGet(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::ASString *v5; // rax
  int Length; // eax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString resulta; // [rsp+20h] [rbp-18h] BYREF
  __int64 v10; // [rsp+28h] [rbp-10h]

  v10 = -2i64;
  v5 = Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(_this, &resulta);
  Length = Scaleform::GFx::ASConstString::GetLength(v5);
  Scaleform::GFx::AS3::Value::SetSInt32(result, Length);
  pNode = resulta.pNode;
  if ( resulta.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 112
// RVA: 0x738EB0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::String::AS3indexOf(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  unsigned int v8; // ebx
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // rsi
  Scaleform::GFx::AS3::Value *v10; // rsi
  int v11; // edx
  int v12; // edi
  unsigned int Char_Advance0; // esi
  unsigned int v14; // eax
  unsigned int v15; // ebx
  unsigned int v16; // eax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v18; // zf
  Scaleform::GFx::ASStringNode *v19; // rcx
  int v20; // [rsp+20h] [rbp-40h] BYREF
  char *putf8Buffer; // [rsp+28h] [rbp-38h] BYREF
  char *pData; // [rsp+30h] [rbp-30h] BYREF
  Scaleform::GFx::ASString v23; // [rsp+38h] [rbp-28h] BYREF
  char *v24; // [rsp+40h] [rbp-20h] BYREF
  char *v25; // [rsp+48h] [rbp-18h] BYREF
  Scaleform::GFx::ASString resulta; // [rsp+50h] [rbp-10h] BYREF
  __int64 v27; // [rsp+58h] [rbp-8h]

  v27 = -2i64;
  v8 = argc;
  if ( !argc )
  {
    Scaleform::GFx::AS3::Value::SetSInt32(result, -1);
    return;
  }
  StringManagerRef = vm->StringManagerRef;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    StringManagerRef,
    &resulta);
  if ( Scaleform::GFx::AS3::Value::Convert2String(_this, (Scaleform::GFx::AS3::CheckResult *)&argc, &resulta)->Result )
  {
    Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
      StringManagerRef,
      &v23);
    v10 = argv;
    if ( !Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&argc, &v23)->Result )
      goto LABEL_29;
    if ( Scaleform::GFx::ASConstString::GetLength(&v23) )
    {
      putf8Buffer = (char *)v23.pNode->pData;
      pData = (char *)resulta.pNode->pData;
      v12 = 0;
      v20 = 0;
      if ( v8 > 1
        && !Scaleform::GFx::AS3::Value::Convert2Int32(v10 + 1, (Scaleform::GFx::AS3::CheckResult *)&argc, &v20)->Result )
      {
LABEL_29:
        pNode = v23.pNode;
        v18 = v23.pNode->RefCount-- == 1;
        if ( v18 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        goto LABEL_31;
      }
      Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
      if ( !Char_Advance0 )
        --putf8Buffer;
      while ( 1 )
      {
        v14 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&pData);
        if ( !v14 )
          break;
        if ( v12 >= v20 && v14 == Char_Advance0 )
        {
          v24 = pData;
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
      --pData;
LABEL_27:
      v11 = -1;
    }
    else
    {
      v11 = 0;
    }
LABEL_28:
    Scaleform::GFx::AS3::Value::SetSInt32(result, v11);
    goto LABEL_29;
  }
LABEL_31:
  v19 = resulta.pNode;
  v18 = resulta.pNode->RefCount-- == 1;
  if ( v18 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
}

// File Line: 194
// RVA: 0x79FE50
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::String::AS3lastIndexOf(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  unsigned int v8; // ebx
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // rsi
  Scaleform::GFx::AS3::Value *v10; // rsi
  int v11; // edi
  int v12; // r14d
  Scaleform::GFx::AS3::Value *v13; // rcx
  int Size; // edx
  unsigned int Char_Advance0; // r15d
  int v16; // esi
  unsigned int v17; // eax
  unsigned int v18; // ebx
  unsigned int v19; // eax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v21; // zf
  Scaleform::GFx::ASStringNode *v22; // rcx
  char *v23; // [rsp+20h] [rbp-60h] BYREF
  char *v24; // [rsp+28h] [rbp-58h] BYREF
  Scaleform::GFx::ASString resulta; // [rsp+30h] [rbp-50h] BYREF
  Scaleform::GFx::ASString v26; // [rsp+38h] [rbp-48h] BYREF
  char *putf8Buffer; // [rsp+40h] [rbp-40h] BYREF
  char *v28[2]; // [rsp+48h] [rbp-38h] BYREF
  int v29; // [rsp+58h] [rbp-28h]
  __int64 v30; // [rsp+60h] [rbp-20h]
  char *v31; // [rsp+68h] [rbp-18h]

  v28[1] = (char *)-2i64;
  v8 = argc;
  if ( !argc )
  {
    Scaleform::GFx::AS3::Value::SetSInt32(result, -1);
    return;
  }
  StringManagerRef = vm->StringManagerRef;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    StringManagerRef,
    &resulta);
  if ( Scaleform::GFx::AS3::Value::Convert2String(_this, (Scaleform::GFx::AS3::CheckResult *)&argc, &resulta)->Result )
  {
    Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
      StringManagerRef,
      &v26);
    v10 = argv;
    if ( Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&argc, &v26)->Result )
    {
      v28[0] = (char *)resulta.pNode->pData;
      putf8Buffer = (char *)v26.pNode->pData;
      v11 = 0;
      v12 = 0x7FFFFFF;
      if ( v8 <= 1 )
      {
LABEL_12:
        if ( Scaleform::GFx::ASConstString::GetLength(&v26) )
        {
          Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
          if ( !Char_Advance0 )
            --putf8Buffer;
          v16 = -1;
          while ( 1 )
          {
            v17 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)v28);
            if ( !v17 )
              break;
            if ( v11 <= v12 && v17 == Char_Advance0 )
            {
              v24 = v28[0];
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
          --v28[0];
LABEL_35:
          Size = v16;
          v13 = result;
        }
        else
        {
          v13 = result;
          if ( v8 <= 1 )
            Size = resulta.pNode->Size;
          else
            Size = v12;
        }
        Scaleform::GFx::AS3::Value::SetSInt32(v13, Size);
        goto LABEL_37;
      }
      *(double *)&v24 = DOUBLE_1_34217727e8;
      if ( Scaleform::GFx::AS3::Value::Convert2Number(
             v10 + 1,
             (Scaleform::GFx::AS3::CheckResult *)&argc,
             (long double *)&v24)->Result )
      {
        v29 = 4;
        v30 = 0i64;
        v31 = v24;
        v23 = v24;
        if ( ((unsigned __int64)v24 & 0x7FF0000000000000i64) != 0x7FF0000000000000i64
          || ((unsigned __int64)v24 & 0xFFFFFFFFFFFFFi64) == 0 )
        {
          v23 = v24;
          if ( *(double *)&v24 != INFINITY )
          {
            v23 = v24;
            v12 = 0;
            if ( *(double *)&v24 != -INFINITY )
              v12 = (int)*(double *)&v24;
          }
        }
        goto LABEL_12;
      }
    }
LABEL_37:
    pNode = v26.pNode;
    v21 = v26.pNode->RefCount-- == 1;
    if ( v21 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  v22 = resulta.pNode;
  v21 = resulta.pNode->RefCount-- == 1;
  if ( v21 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v22);
}

// File Line: 289
// RVA: 0x79B350
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::String::AS3charAt(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // rdi
  double v9; // xmm0_8
  unsigned int v10; // ebx
  unsigned int CharAt; // eax
  Scaleform::GFx::ASString *appended; // rax
  Scaleform::GFx::ASStringNode *pNode; // rbx
  Scaleform::GFx::ASStringNode *v14; // rcx
  bool v15; // zf
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::ASString v; // [rsp+20h] [rbp-28h] BYREF
  Scaleform::GFx::ASString resulta; // [rsp+28h] [rbp-20h] BYREF
  long double v21[3]; // [rsp+30h] [rbp-18h] BYREF
  Scaleform::GFx::ASString v22; // [rsp+58h] [rbp+10h] BYREF

  v21[1] = NAN;
  StringManagerRef = vm->StringManagerRef;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    StringManagerRef,
    &resulta);
  if ( !Scaleform::GFx::AS3::Value::Convert2String(_this, (Scaleform::GFx::AS3::CheckResult *)&v22, &resulta)->Result )
    goto LABEL_13;
  v9 = 0.0;
  v21[0] = 0.0;
  if ( argc )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&v22, v21)->Result )
      goto LABEL_13;
    v9 = v21[0];
  }
  v10 = (int)v9;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    StringManagerRef,
    &v);
  if ( (int)v9 >= 0 && v10 < Scaleform::GFx::ASConstString::GetLength(&resulta) )
  {
    CharAt = Scaleform::GFx::ASConstString::GetCharAt(&resulta, v10);
    appended = Scaleform::GFx::ASString::AppendChar(&v, &v22, CharAt);
    pNode = appended->pNode;
    ++appended->pNode->RefCount;
    v14 = v.pNode;
    v15 = v.pNode->RefCount-- == 1;
    if ( v15 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
    v.pNode = pNode;
    v16 = v22.pNode;
    v15 = v22.pNode->RefCount-- == 1;
    if ( v15 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  }
  Scaleform::GFx::AS3::Value::Assign(result, &v);
  v17 = v.pNode;
  v15 = v.pNode->RefCount-- == 1;
  if ( v15 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
LABEL_13:
  v18 = resulta.pNode;
  v15 = resulta.pNode->RefCount-- == 1;
  if ( v15 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
}

// File Line: 322
// RVA: 0x79B490
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::String::AS3charCodeAt(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  double v8; // xmm0_8
  unsigned int v9; // ebx
  double CharAt; // xmm1_8
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString resulta; // [rsp+20h] [rbp-28h] BYREF
  long double v14[4]; // [rsp+28h] [rbp-20h] BYREF
  Scaleform::GFx::AS3::CheckResult v15; // [rsp+58h] [rbp+10h] BYREF

  v14[1] = NAN;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    vm->StringManagerRef,
    &resulta);
  if ( !Scaleform::GFx::AS3::Value::Convert2String(_this, &v15, &resulta)->Result )
    goto LABEL_10;
  v8 = 0.0;
  v14[0] = 0.0;
  if ( argc )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2Number(argv, &v15, v14)->Result )
      goto LABEL_10;
    v8 = v14[0];
  }
  v9 = (int)v8;
  if ( (int)v8 < 0 || v9 >= Scaleform::GFx::ASConstString::GetLength(&resulta) )
    CharAt = Scaleform::GFx::NumberUtil::NaN();
  else
    CharAt = (double)(int)Scaleform::GFx::ASConstString::GetCharAt(&resulta, v9);
  Scaleform::GFx::AS3::Value::SetNumber(result, CharAt);
LABEL_10:
  pNode = resulta.pNode;
  if ( resulta.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 353
// RVA: 0x79BF00
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::String::AS3concat(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // rsi
  int v9; // ebx
  unsigned int v10; // esi
  Scaleform::GFx::AS3::Value *v11; // rbp
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  bool v13; // zf
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::Value::V2U v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::ASString resulta; // [rsp+20h] [rbp-38h] BYREF
  Scaleform::GFx::ASString str; // [rsp+28h] [rbp-30h] BYREF
  Scaleform::GFx::AS3::Value::V2U v20; // [rsp+30h] [rbp-28h]
  __int64 v21; // [rsp+38h] [rbp-20h]
  Scaleform::GFx::AS3::CheckResult v22; // [rsp+68h] [rbp+10h] BYREF

  v21 = -2i64;
  StringManagerRef = vm->StringManagerRef;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    StringManagerRef,
    &resulta);
  if ( Scaleform::GFx::AS3::Value::Convert2String(_this, &v22, &resulta)->Result )
  {
    Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
      StringManagerRef,
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
      if ( (result->Flags & 0x1F) > 9 )
      {
        if ( (result->Flags & 0x200) != 0 )
        {
          pWeakProxy = result->Bonus.pWeakProxy;
          v13 = pWeakProxy->RefCount-- == 1;
          if ( v13 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          result->Bonus.pWeakProxy = 0i64;
          result->value.VS._1.VStr = 0i64;
          result->value.VS._2.VObj = 0i64;
          result->Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(result);
        }
      }
      pNode = resulta.pNode;
      v15.VObj = v20.VObj;
      if ( resulta.pNode == &resulta.pNode->pManager->NullStringNode )
      {
        result->value.VS._1.VStr = 0i64;
        result->value.VS._2 = v15;
        result->Flags &= 0xFFFFFFEC;
        result->Flags |= 0xCu;
      }
      else
      {
        result->Flags &= 0xFFFFFFEA;
        result->Flags |= 0xAu;
        result->value.VS._1.VStr = pNode;
        result->value.VS._2 = v15;
        ++result->value.VS._1.VStr->RefCount;
      }
    }
    v16 = str.pNode;
    v13 = str.pNode->RefCount-- == 1;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  }
  v17 = resulta.pNode;
  v13 = resulta.pNode->RefCount-- == 1;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
}

// File Line: 382
// RVA: 0x7A0100
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::String::AS3localeCompare(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // rsi
  Scaleform::GFx::AS3::VM::Error *v10; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  int v12; // ebx
  unsigned int v13; // edi
  unsigned int Char_Advance0; // eax
  bool v15; // zf
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::AS3::VM::Error v17; // [rsp+20h] [rbp-30h] BYREF
  Scaleform::GFx::ASString resulta; // [rsp+30h] [rbp-20h] BYREF
  Scaleform::GFx::ASString v19; // [rsp+38h] [rbp-18h] BYREF
  __int64 v20; // [rsp+40h] [rbp-10h]
  const char *pData; // [rsp+78h] [rbp+28h] BYREF

  v20 = -2i64;
  StringManagerRef = vm->StringManagerRef;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    StringManagerRef,
    &resulta);
  if ( Scaleform::GFx::AS3::Value::Convert2String(_this, (Scaleform::GFx::AS3::CheckResult *)&pData, &resulta)->Result )
  {
    if ( argc )
    {
      if ( argc <= 1 )
      {
        Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
          StringManagerRef,
          &v19);
        if ( Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&pData, &v19)->Result )
        {
          v12 = 0;
          if ( v19.pNode != resulta.pNode )
          {
            pData = v19.pNode->pData;
            *(_QWORD *)&v17.ID = resulta.pNode->pData;
            while ( 1 )
            {
              v13 = Scaleform::UTF8Util::DecodeNextChar_Advance0(&pData);
              if ( !v13 )
                --pData;
              Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&v17);
              if ( !Char_Advance0 )
                --*(_QWORD *)&v17.ID;
              if ( !v13 || !Char_Advance0 )
                break;
              v12 = Char_Advance0 - v13;
              if ( Char_Advance0 != v13 )
                goto LABEL_20;
            }
            if ( v13 != Char_Advance0 )
            {
              v12 = 1;
              if ( !Char_Advance0 )
                v12 = -1;
            }
          }
LABEL_20:
          Scaleform::GFx::AS3::Value::SetNumber(result, (double)v12);
        }
        pNode = v19.pNode;
      }
      else
      {
        Scaleform::GFx::AS3::VM::Error::Error(&v17, 1063, vm);
        Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v10, &Scaleform::GFx::AS3::fl::ArgumentErrorTI);
        pNode = v17.Message.pNode;
      }
      v15 = pNode->RefCount-- == 1;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
    else
    {
      Scaleform::GFx::AS3::Value::SetNumber(result, (double)(resulta.pNode->Size == 0));
    }
  }
  v16 = resulta.pNode;
  v15 = resulta.pNode->RefCount-- == 1;
  if ( v15 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
}

// File Line: 416
// RVA: 0x7A07F0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::String::AS3match(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // r14
  Scaleform::GFx::AS3::Value *v10; // rdi
  unsigned int v11; // ecx
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *pObject; // rbx
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *VStr; // rcx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v15; // zf
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> *v16; // rax
  Scaleform::GFx::AS3::Instances::fl::Object *v17; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *v19; // rcx
  unsigned int v20; // eax
  Scaleform::GFx::ASStringNode *v21; // rcx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint> pobj; // [rsp+30h] [rbp-50h] BYREF
  Scaleform::GFx::ASString v23; // [rsp+38h] [rbp-48h] BYREF
  Scaleform::GFx::ASString resulta; // [rsp+40h] [rbp-40h] BYREF
  Scaleform::GFx::AS3::Value::V2U v25; // [rsp+48h] [rbp-38h]
  __int64 v26; // [rsp+50h] [rbp-30h]
  Scaleform::GFx::AS3::Value ptr; // [rsp+58h] [rbp-28h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> v28; // [rsp+A8h] [rbp+28h] BYREF

  v26 = -2i64;
  StringManagerRef = vm->StringManagerRef;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    StringManagerRef,
    &resulta);
  if ( !Scaleform::GFx::AS3::Value::Convert2String(_this, (Scaleform::GFx::AS3::CheckResult *)&v28, &resulta)->Result )
    goto LABEL_32;
  if ( !argc )
    goto LABEL_32;
  v10 = argv;
  v11 = argv->Flags & 0x1F;
  if ( !v11 )
    goto LABEL_32;
  if ( (v11 - 12 <= 3 || v11 == 10) && !argv->value.VS._1.VStr )
    goto LABEL_32;
  pObject = 0i64;
  pobj.pObject = 0i64;
  if ( (argv->Flags & 0x1F) - 12 > 3
    || !Scaleform::GFx::AS3::VM::IsOfType(vm, argv, "RegExp", vm->CurrentDomain.pObject) )
  {
    Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
      StringManagerRef,
      &v23);
    if ( Scaleform::GFx::AS3::Value::Convert2String(v10, (Scaleform::GFx::AS3::CheckResult *)&v28, &v23)->Result )
    {
      ptr.Flags = 10;
      ptr.Bonus.pWeakProxy = 0i64;
      *(Scaleform::GFx::ASString *)&ptr.value.VNumber = (Scaleform::GFx::ASString)v23.pNode;
      if ( v23.pNode == &v23.pNode->pManager->NullStringNode )
      {
        ptr.value.VS._1.VStr = 0i64;
        ptr.value.VS._2 = v25;
        ptr.Flags = 12;
      }
      else
      {
        ++v23.pNode->RefCount;
      }
      if ( Scaleform::GFx::AS3::VM::ConstructBuiltinObject<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle>(
             vm,
             (Scaleform::GFx::AS3::CheckResult *)&v28,
             (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&pobj,
             "RegExp",
             1u,
             &ptr)->Result )
      {
        `eh vector destructor iterator(
          &ptr,
          0x20ui64,
          1,
          (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
        pNode = v23.pNode;
        v15 = v23.pNode->RefCount-- == 1;
        if ( v15 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        pObject = pobj.pObject;
        goto LABEL_20;
      }
      `eh vector destructor iterator(
        &ptr,
        0x20ui64,
        1,
        (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
      pObject = pobj.pObject;
    }
    v19 = v23.pNode;
    v15 = v23.pNode->RefCount-- == 1;
    if ( v15 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v19);
    goto LABEL_27;
  }
  VStr = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *)v10->value.VS._1.VStr;
  if ( VStr )
  {
    VStr->RefCount = (VStr->RefCount + 1) & 0x8FBFFFFF;
    pObject = VStr;
    pobj.pObject = VStr;
  }
LABEL_20:
  v16 = Scaleform::GFx::AS3::Instances::fl::RegExp::AS3exec(
          (Scaleform::GFx::AS3::Instances::fl::RegExp *)pObject,
          &v28,
          &resulta);
  Scaleform::GFx::AS3::Value::Assign(result, v16->pObject);
  v17 = v28.pObject;
  if ( v28.pObject )
  {
    if ( ((__int64)v28.pObject & 1) != 0 )
    {
      --v28.pObject;
    }
    else
    {
      RefCount = v28.pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        v28.pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v17);
      }
    }
  }
LABEL_27:
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      pobj.pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *)((char *)pObject - 1);
    }
    else
    {
      v20 = pObject->RefCount;
      if ( (v20 & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = v20 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
LABEL_32:
  v21 = resulta.pNode;
  v15 = resulta.pNode->RefCount-- == 1;
  if ( v15 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v21);
}

// File Line: 466
// RVA: 0x7A1E50
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::String::AS3replace(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // rsi
  int v8; // ecx
  Scaleform::GFx::AS3::Instances::fl::RegExp *v9; // rbx
  __int64 VStr; // rcx
  int v11; // ecx
  Scaleform::GFx::AS3::Instances::fl::Object *pObject; // rdi
  Scaleform::GFx::AS3::Instances::fl::Object *v13; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASString *v15; // rbx
  Scaleform::GFx::ASString *v16; // rax
  Scaleform::GFx::ASString *v17; // rax
  Scaleform::GFx::ASString *v18; // rax
  Scaleform::GFx::ASStringNode *pNode; // rbx
  Scaleform::GFx::ASStringNode *v20; // rcx
  bool v21; // zf
  Scaleform::GFx::ASStringNode *v22; // rcx
  Scaleform::GFx::ASStringNode *v23; // rcx
  Scaleform::GFx::ASStringNode *v24; // rcx
  Scaleform::GFx::ASStringNode *v25; // rcx
  char *v26; // rdi
  unsigned __int64 v27; // rdi
  unsigned __int64 v28; // rbx
  Scaleform::GFx::ASString *v29; // rbx
  Scaleform::GFx::ASString *v30; // rax
  Scaleform::GFx::ASString *v31; // rax
  Scaleform::GFx::ASString *v32; // rax
  Scaleform::GFx::ASStringNode *v33; // rbx
  Scaleform::GFx::ASStringNode *v34; // rcx
  Scaleform::GFx::ASStringNode *v35; // rcx
  Scaleform::GFx::ASStringNode *v36; // rcx
  Scaleform::GFx::ASStringNode *v37; // rcx
  Scaleform::GFx::ASStringNode *v38; // rcx
  Scaleform::GFx::ASStringNode *v39; // rcx
  Scaleform::GFx::ASStringNode *v40; // rcx
  unsigned int v41; // eax
  Scaleform::GFx::ASStringNode *v42; // rcx
  Scaleform::GFx::ASString resulta; // [rsp+8h] [rbp-69h] BYREF
  Scaleform::GFx::AS3::Instances::fl::RegExp *v44; // [rsp+10h] [rbp-61h]
  Scaleform::GFx::AS3::CheckResult v45; // [rsp+18h] [rbp-59h] BYREF
  Scaleform::GFx::AS3::CheckResult v46; // [rsp+19h] [rbp-58h] BYREF
  Scaleform::GFx::ASString v47; // [rsp+20h] [rbp-51h] BYREF
  Scaleform::GFx::ASString v48; // [rsp+28h] [rbp-49h] BYREF
  Scaleform::String v49; // [rsp+30h] [rbp-41h] BYREF
  Scaleform::String v50; // [rsp+38h] [rbp-39h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> v51; // [rsp+40h] [rbp-31h] BYREF
  Scaleform::String str; // [rsp+48h] [rbp-29h] BYREF
  Scaleform::String v53; // [rsp+50h] [rbp-21h] BYREF
  Scaleform::GFx::ASString v54; // [rsp+58h] [rbp-19h] BYREF
  Scaleform::GFx::ASString v55; // [rsp+60h] [rbp-11h] BYREF
  Scaleform::GFx::ASString v56; // [rsp+68h] [rbp-9h] BYREF
  Scaleform::GFx::ASString v57; // [rsp+70h] [rbp-1h] BYREF
  Scaleform::GFx::ASString v58; // [rsp+78h] [rbp+7h] BYREF
  Scaleform::GFx::ASString v59; // [rsp+80h] [rbp+Fh] BYREF
  Scaleform::GFx::ASString v60; // [rsp+88h] [rbp+17h] BYREF
  Scaleform::GFx::ASString v61; // [rsp+90h] [rbp+1Fh] BYREF
  __int64 v62; // [rsp+98h] [rbp+27h]
  Scaleform::GFx::AS3::CheckResult vars0; // [rsp+D0h] [rbp+5Fh] BYREF
  unsigned int v64; // [rsp+E8h] [rbp+77h]
  Scaleform::GFx::AS3::Value *v; // [rsp+F0h] [rbp+7Fh]

  v62 = -2i64;
  StringManagerRef = vm->StringManagerRef;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    StringManagerRef,
    &v47);
  if ( !Scaleform::GFx::AS3::Value::Convert2String(_this, &vars0, &resulta)->Result )
    goto LABEL_67;
  if ( !v64 )
    goto LABEL_67;
  v8 = v->Flags & 0x1F;
  if ( !v8 )
    goto LABEL_67;
  if ( ((unsigned int)(v8 - 12) <= 3 || v8 == 10) && !v->value.VS._1.VStr )
    goto LABEL_67;
  v9 = 0i64;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    StringManagerRef,
    &v48);
  if ( (v->Flags & 0x1F) - 12 <= 3 && Scaleform::GFx::AS3::VM::IsOfType(vm, v, "RegExp", vm->CurrentDomain.pObject) )
  {
    VStr = (__int64)v->value.VS._1.VStr;
    if ( VStr )
    {
      *(_DWORD *)(VStr + 32) = (*(_DWORD *)(VStr + 32) + 1) & 0x8FBFFFFF;
      v9 = (Scaleform::GFx::AS3::Instances::fl::RegExp *)VStr;
      v44 = (Scaleform::GFx::AS3::Instances::fl::RegExp *)VStr;
    }
LABEL_12:
    Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
      StringManagerRef,
      &v47);
    if ( v64 < 2
      || (v11 = v[1].Flags & 0x1F) == 0
      || ((unsigned int)(v11 - 12) <= 3 || v11 == 10) && !v[1].value.VS._1.VStr
      || Scaleform::GFx::AS3::Value::Convert2String(v + 1, &v45, &v47)->Result )
    {
      if ( v9 )
      {
        pObject = Scaleform::GFx::AS3::Instances::fl::RegExp::AS3exec(v9, &v51, &resulta)->pObject;
        v13 = v51.pObject;
        if ( v51.pObject )
        {
          if ( ((__int64)v51.pObject & 1) != 0 )
          {
            --v51.pObject;
          }
          else
          {
            RefCount = v51.pObject->RefCount;
            if ( (RefCount & 0x3FFFFF) != 0 )
            {
              v51.pObject->RefCount = RefCount - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v13);
            }
          }
        }
        if ( pObject )
        {
          Scaleform::String::String(&v50, resulta.pNode->pData, 0xFFFFFFFFFFFFFFFFui64);
          Scaleform::String::String(&str, resulta.pNode->pData - 1, resulta.pNode->Size + 1);
          v15 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                  StringManagerRef,
                  &v61,
                  &str);
          v16 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                  StringManagerRef,
                  &v54,
                  &v50);
          v17 = Scaleform::GFx::ASString::operator+(v16, &v59, &v47);
          v18 = Scaleform::GFx::ASString::operator+(v17, &v57, v15);
          pNode = v18->pNode;
          ++v18->pNode->RefCount;
          v20 = resulta.pNode;
          v21 = resulta.pNode->RefCount-- == 1;
          if ( v21 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v20);
          resulta.pNode = pNode;
          v22 = v57.pNode;
          v21 = v57.pNode->RefCount-- == 1;
          if ( v21 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v22);
          v23 = v59.pNode;
          v21 = v59.pNode->RefCount-- == 1;
          if ( v21 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v23);
          v24 = v54.pNode;
          v21 = v54.pNode->RefCount-- == 1;
          if ( v21 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v24);
          v25 = v61.pNode;
          v21 = v61.pNode->RefCount-- == 1;
          if ( v21 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v25);
          if ( !_InterlockedDecrement((volatile signed __int32 *)((str.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          if ( _InterlockedExchangeAdd(
                 (volatile signed __int32 *)((v50.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8),
                 0xFFFFFFFF) == 1 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          v9 = v44;
        }
      }
      else
      {
        v26 = strstr(resulta.pNode->pData, v48.pNode->pData);
        if ( v26 )
        {
          v27 = v26 - resulta.pNode->pData;
          v28 = v27 + Scaleform::GFx::ASConstString::GetLength(&v48);
          Scaleform::String::String(&v53, resulta.pNode->pData, v27);
          Scaleform::String::String(&v49, &resulta.pNode->pData[v28], resulta.pNode->Size - v28);
          v29 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                  StringManagerRef,
                  &v60,
                  &v49);
          v30 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                  StringManagerRef,
                  &v58,
                  &v53);
          v31 = Scaleform::GFx::ASString::operator+(v30, &v56, &v47);
          v32 = Scaleform::GFx::ASString::operator+(v31, &v55, v29);
          v33 = v32->pNode;
          ++v32->pNode->RefCount;
          v34 = resulta.pNode;
          v21 = resulta.pNode->RefCount-- == 1;
          if ( v21 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v34);
          resulta.pNode = v33;
          v35 = v55.pNode;
          v21 = v55.pNode->RefCount-- == 1;
          if ( v21 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v35);
          v36 = v56.pNode;
          v21 = v56.pNode->RefCount-- == 1;
          if ( v21 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v36);
          v37 = v58.pNode;
          v21 = v58.pNode->RefCount-- == 1;
          if ( v21 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v37);
          v38 = v60.pNode;
          v21 = v60.pNode->RefCount-- == 1;
          if ( v21 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v38);
          Scaleform::GFx::AS3::Value::Assign(result, &resulta);
          if ( !_InterlockedDecrement((volatile signed __int32 *)((v49.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          if ( _InterlockedExchangeAdd(
                 (volatile signed __int32 *)((v53.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8),
                 0xFFFFFFFF) == 1 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          v9 = v44;
          goto LABEL_58;
        }
      }
      Scaleform::GFx::AS3::Value::Assign(result, &resulta);
    }
LABEL_58:
    v39 = v47.pNode;
    v21 = v47.pNode->RefCount-- == 1;
    if ( v21 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v39);
    goto LABEL_60;
  }
  if ( Scaleform::GFx::AS3::Value::Convert2String(v, &v46, &v48)->Result )
    goto LABEL_12;
LABEL_60:
  v40 = v48.pNode;
  v21 = v48.pNode->RefCount-- == 1;
  if ( v21 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v40);
  if ( v9 )
  {
    if ( ((unsigned __int8)v9 & 1) != 0 )
    {
      v44 = (Scaleform::GFx::AS3::Instances::fl::RegExp *)((char *)v9 - 1);
    }
    else
    {
      v41 = v9->RefCount;
      if ( (v41 & 0x3FFFFF) != 0 )
      {
        v9->RefCount = v41 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v9);
      }
    }
  }
LABEL_67:
  v42 = resulta.pNode;
  v21 = resulta.pNode->RefCount-- == 1;
  if ( v21 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v42);
}

// File Line: 538
// RVA: 0x7A25E0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::String::AS3search(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // r14
  int v8; // ecx
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *pObject; // rbx
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *VStr; // rcx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v12; // zf
  Scaleform::GFx::AS3::Instances::fl::Object *v13; // rdi
  Scaleform::GFx::AS3::Instances::fl::Object *v14; // rcx
  unsigned int RefCount; // eax
  int Length; // eax
  Scaleform::GFx::ASStringNode *v17; // rcx
  unsigned int v18; // eax
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint> pobj; // [rsp+8h] [rbp-49h] BYREF
  Scaleform::GFx::AS3::CheckResult v21; // [rsp+10h] [rbp-41h] BYREF
  Scaleform::GFx::AS3::CheckResult v22; // [rsp+11h] [rbp-40h] BYREF
  Scaleform::GFx::ASString resulta; // [rsp+18h] [rbp-39h] BYREF
  Scaleform::GFx::ASString v24; // [rsp+20h] [rbp-31h] BYREF
  Scaleform::String v25; // [rsp+28h] [rbp-29h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> v26; // [rsp+30h] [rbp-21h] BYREF
  Scaleform::GFx::AS3::Value ptr; // [rsp+38h] [rbp-19h] BYREF
  __int64 v28; // [rsp+58h] [rbp+7h]
  __int64 v29; // [rsp+60h] [rbp+Fh]
  unsigned __int64 v30; // [rsp+68h] [rbp+17h]
  Scaleform::GFx::AS3::CheckResult v31; // [rsp+B0h] [rbp+5Fh] BYREF
  void *retaddr; // [rsp+C8h] [rbp+77h]
  Scaleform::GFx::AS3::Value *v; // [rsp+D0h] [rbp+7Fh]

  v28 = -2i64;
  StringManagerRef = vm->StringManagerRef;
  Scaleform::GFx::AS3::Value::SetSInt32(result, -1);
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    StringManagerRef,
    &resulta);
  if ( !Scaleform::GFx::AS3::Value::Convert2String(_this, &v31, &resulta)->Result )
    goto LABEL_36;
  if ( !(_DWORD)retaddr )
    goto LABEL_36;
  v8 = v->Flags & 0x1F;
  if ( !v8 )
    goto LABEL_36;
  if ( ((unsigned int)(v8 - 12) <= 3 || v8 == 10) && !v->value.VS._1.VStr )
    goto LABEL_36;
  pObject = 0i64;
  pobj.pObject = 0i64;
  if ( (v->Flags & 0x1F) - 12 > 3 || !Scaleform::GFx::AS3::VM::IsOfType(vm, v, "RegExp", vm->CurrentDomain.pObject) )
  {
    Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
      StringManagerRef,
      &v24);
    if ( Scaleform::GFx::AS3::Value::Convert2String(v, &v22, &v24)->Result )
    {
      ptr.Flags = 10;
      ptr.Bonus.pWeakProxy = 0i64;
      *(Scaleform::GFx::ASString *)&ptr.value.VNumber = (Scaleform::GFx::ASString)v24.pNode;
      if ( v24.pNode == &v24.pNode->pManager->NullStringNode )
      {
        v29 = 0i64;
        ptr.value = (Scaleform::GFx::AS3::Value::VU)__PAIR128__(v30, 0i64);
        ptr.Flags = 12;
      }
      else
      {
        ++v24.pNode->RefCount;
      }
      if ( Scaleform::GFx::AS3::VM::ConstructBuiltinObject<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle>(
             vm,
             &v21,
             (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&pobj,
             "RegExp",
             1u,
             &ptr)->Result )
      {
        `eh vector destructor iterator(
          &ptr,
          0x20ui64,
          1,
          (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
        pNode = v24.pNode;
        v12 = v24.pNode->RefCount-- == 1;
        if ( v12 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        pObject = pobj.pObject;
        goto LABEL_20;
      }
      `eh vector destructor iterator(
        &ptr,
        0x20ui64,
        1,
        (void (__fastcall *)(void *))Scaleform::GFx::AS3::Value::~Value);
      pObject = pobj.pObject;
    }
    v17 = v24.pNode;
    v12 = v24.pNode->RefCount-- == 1;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v17);
    goto LABEL_31;
  }
  VStr = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *)v->value.VS._1.VStr;
  if ( VStr )
  {
    VStr->RefCount = (VStr->RefCount + 1) & 0x8FBFFFFF;
    pObject = VStr;
    pobj.pObject = VStr;
  }
LABEL_20:
  v13 = Scaleform::GFx::AS3::Instances::fl::RegExp::AS3exec(
          (Scaleform::GFx::AS3::Instances::fl::RegExp *)pObject,
          &v26,
          &resulta)->pObject;
  v14 = v26.pObject;
  if ( v26.pObject )
  {
    if ( ((__int64)v26.pObject & 1) != 0 )
    {
      --v26.pObject;
    }
    else
    {
      RefCount = v26.pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        v26.pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v14);
      }
    }
  }
  if ( v13 )
  {
    Scaleform::String::String(&v25, resulta.pNode->pData, 0xFFFFFFFFFFFFFFFFui64);
    Length = Scaleform::String::GetLength(&v25);
    Scaleform::GFx::AS3::Value::SetSInt32(result, Length);
    if ( _InterlockedExchangeAdd(
           (volatile signed __int32 *)((v25.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8),
           0xFFFFFFFF) == 1 )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    pObject = pobj.pObject;
  }
LABEL_31:
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      pobj.pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint *)((char *)pObject - 1);
    }
    else
    {
      v18 = pObject->RefCount;
      if ( (v18 & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = v18 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
LABEL_36:
  v19 = resulta.pNode;
  v12 = resulta.pNode->RefCount-- == 1;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
}

// File Line: 580
// RVA: 0x7A3F00
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::String::AS3slice(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // r12
  int Length; // esi
  int v10; // edi
  int v11; // ebx
  Scaleform::GFx::AS3::Value *v12; // r14
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASString *v14; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v16; // zf
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::ASString resulta; // [rsp+20h] [rbp-38h] BYREF
  long double v19; // [rsp+28h] [rbp-30h] BYREF
  long double v20[5]; // [rsp+30h] [rbp-28h] BYREF
  Scaleform::GFx::ASString v21; // [rsp+68h] [rbp+10h] BYREF

  v20[1] = NAN;
  StringManagerRef = vm->StringManagerRef;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    StringManagerRef,
    &resulta);
  if ( !Scaleform::GFx::AS3::Value::Convert2String(_this, (Scaleform::GFx::AS3::CheckResult *)&v21, &resulta)->Result )
    goto LABEL_21;
  if ( !argc )
  {
    Scaleform::GFx::AS3::Value::Assign(result, &resulta);
    goto LABEL_21;
  }
  Length = Scaleform::GFx::ASConstString::GetLength(&resulta);
  v10 = 0;
  v11 = 0x7FFFFFFF;
  v12 = argv;
  if ( argc )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&v21, &v19)->Result )
      goto LABEL_21;
    v10 = Length;
    if ( v19 <= (double)Length )
      v10 = (int)v19;
    if ( v10 < 0 )
      v10 += Length;
  }
  if ( argc < 2 )
    goto LABEL_18;
  if ( !Scaleform::GFx::AS3::Value::Convert2Number(v12 + 1, (Scaleform::GFx::AS3::CheckResult *)&v21, v20)->Result )
    goto LABEL_21;
  v11 = Length;
  if ( v20[0] <= (double)Length )
    v11 = (int)v20[0];
  if ( v11 < 0 )
    v11 += Length;
  if ( v11 >= v10 )
  {
LABEL_18:
    v14 = Scaleform::GFx::ASString::Substring(&resulta, &v21, v10, v11);
    Scaleform::GFx::AS3::Value::Assign(result, v14);
  }
  else
  {
    v13 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
            StringManagerRef,
            &v21);
    Scaleform::GFx::AS3::Value::Assign(result, v13);
  }
  pNode = v21.pNode;
  v16 = v21.pNode->RefCount-- == 1;
  if ( v16 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
LABEL_21:
  v17 = resulta.pNode;
  v16 = resulta.pNode->RefCount-- == 1;
  if ( v16 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
}

// File Line: 635
// RVA: 0x7A6480
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::String::AS3split(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        __int64 argc,
        Scaleform::GFx::AS3::Value *argv)
{
  unsigned int v8; // r14d
  unsigned int Flags; // ebx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rsi
  Scaleform::GFx::AS3::Value *v11; // rdi
  unsigned int v12; // r15d
  unsigned int v13; // ecx
  unsigned int limit; // r12d
  int v15; // ecx
  Scaleform::GFx::AS3::Instances::fl::RegExp *VStr; // rdi
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::AS3::Instances::fl::Array *pV; // rbx
  int v19; // r12d
  unsigned int v20; // r13d
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> *v21; // rax
  int v22; // r14d
  unsigned int v23; // eax
  bool v24; // r15
  Scaleform::GFx::AS3::Instances::fl::Object *pObject; // rcx
  unsigned int v26; // eax
  Scaleform::GFx::AS3::Value::V1U *v27; // rax
  Scaleform::GFx::AS3::Value::V1U v28; // rdx
  unsigned __int64 Length; // rcx
  __int64 v30; // rcx
  __int64 v31; // rdx
  bool v32; // zf
  Scaleform::GFx::AS3::Value::VU *v33; // rdx
  Scaleform::GFx::AS3::Value::V1U VObj; // rax
  Scaleform::GFx::ASStringNode *v35; // rcx
  Scaleform::GFx::AS3::Value::V1U *v36; // rax
  Scaleform::GFx::AS3::Value::V1U v37; // rdx
  unsigned __int64 v38; // rcx
  __int64 v39; // rcx
  __int64 v40; // rdx
  Scaleform::GFx::AS3::Value::VU *v41; // rdx
  Scaleform::GFx::AS3::Value::V1U v42; // rax
  Scaleform::GFx::ASStringNode *v43; // rcx
  unsigned int v44; // eax
  Scaleform::GFx::ASStringNode *v45; // rcx
  unsigned int v46; // eax
  Scaleform::GFx::AS3::Value::V2U v47; // rax
  unsigned int v48; // ebx
  Scaleform::GFx::ASStringNode *v49; // rcx
  unsigned int RefCount; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> *v51; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASStringNode *v53; // rcx
  Scaleform::GFx::AS3::Value v; // [rsp+30h] [rbp-D0h] BYREF
  unsigned int v55; // [rsp+50h] [rbp-B0h]
  Scaleform::GFx::AS3::CheckResult v56; // [rsp+54h] [rbp-ACh] BYREF
  Scaleform::GFx::AS3::CheckResult v57; // [rsp+55h] [rbp-ABh] BYREF
  Scaleform::GFx::ASString resulta; // [rsp+58h] [rbp-A8h] BYREF
  Scaleform::GFx::AS3::Value v59; // [rsp+60h] [rbp-A0h] BYREF
  Scaleform::GFx::AS3::Value v60; // [rsp+80h] [rbp-80h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> v61; // [rsp+A0h] [rbp-60h] BYREF
  Scaleform::GFx::ASString v62; // [rsp+A8h] [rbp-58h] BYREF
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *StringManagerRef; // [rsp+B0h] [rbp-50h]
  Scaleform::GFx::ASString v64; // [rsp+B8h] [rbp-48h] BYREF
  __int64 v65; // [rsp+C0h] [rbp-40h]
  Scaleform::GFx::AS3::Value::V1U v66; // [rsp+C8h] [rbp-38h]
  Scaleform::String str; // [rsp+D0h] [rbp-30h] BYREF
  Scaleform::String v68; // [rsp+D8h] [rbp-28h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> v69; // [rsp+E0h] [rbp-20h] BYREF
  Scaleform::GFx::ASString v70; // [rsp+E8h] [rbp-18h] BYREF
  Scaleform::GFx::AS3::Value::VU *v71; // [rsp+F0h] [rbp-10h]
  Scaleform::GFx::ASString v72; // [rsp+F8h] [rbp-8h] BYREF
  Scaleform::GFx::AS3::Instances::fl::Array *v73; // [rsp+100h] [rbp+0h]
  Scaleform::GFx::AS3::Value::VU *v74; // [rsp+108h] [rbp+8h]
  long double v75; // [rsp+110h] [rbp+10h] BYREF
  Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef key; // [rsp+118h] [rbp+18h] BYREF
  Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef v77; // [rsp+128h] [rbp+28h] BYREF
  __int64 v78; // [rsp+138h] [rbp+38h]
  unsigned __int64 v79; // [rsp+140h] [rbp+40h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> v80; // [rsp+148h] [rbp+48h] BYREF
  __int64 v81; // [rsp+150h] [rbp+50h]
  unsigned __int64 v82; // [rsp+158h] [rbp+58h]
  __int64 v83; // [rsp+160h] [rbp+60h]
  Scaleform::GFx::AS3::Value::V2U v84; // [rsp+170h] [rbp+70h]
  Scaleform::GFx::AS3::Value::V2U v85; // [rsp+180h] [rbp+80h]
  Scaleform::GFx::AS3::CheckResult v86; // [rsp+1D8h] [rbp+D8h] BYREF
  Scaleform::GFx::AS3::Value *v87; // [rsp+1E8h] [rbp+E8h]

  v87 = result;
  v83 = -2i64;
  v8 = 0;
  v55 = 0;
  StringManagerRef = vm->StringManagerRef;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    StringManagerRef,
    &resulta);
  if ( !Scaleform::GFx::AS3::Value::Convert2String(_this, &v86, &resulta)->Result )
    goto LABEL_133;
  Flags = 0;
  v.Flags = 0;
  pWeakProxy = 0i64;
  v.Bonus.pWeakProxy = 0i64;
  v11 = argv;
  v12 = argc;
  if ( (_DWORD)argc )
  {
    v13 = argv->Flags & 0x1F;
    if ( v13 )
    {
      if ( v13 - 12 > 3 && v13 != 10 || argv->value.VS._1.VStr )
      {
        Scaleform::GFx::AS3::Value::Assign(&v, argv);
        pWeakProxy = v.Bonus.pWeakProxy;
        Flags = v.Flags;
      }
    }
  }
  limit = 0x7FFFFFFF;
  v65 = 0x7FFFFFFFi64;
  if ( v12 >= 2 )
  {
    v15 = v11[1].Flags & 0x1F;
    if ( v15 )
    {
      if ( (unsigned int)(v15 - 12) > 3 && v15 != 10 || v11[1].value.VS._1.VStr )
      {
        if ( !Scaleform::GFx::AS3::Value::Convert2Number(v11 + 1, &v57, &v75)->Result )
          goto LABEL_127;
        limit = (int)v75;
        v65 = (unsigned int)(int)v75;
      }
    }
  }
  if ( (Flags & 0x1F) - 12 > 3 || !Scaleform::GFx::AS3::VM::IsOfType(vm, &v, "RegExp", vm->CurrentDomain.pObject) )
  {
LABEL_122:
    Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
      StringManagerRef,
      &v64);
    if ( Scaleform::GFx::AS3::Value::Convert2String(&v, &v56, &v64)->Result )
    {
      v51 = Scaleform::GFx::AS3::InstanceTraits::fl::String::StringSplit(&v80, vm, &resulta, v64.pNode->pData, limit);
      Scaleform::GFx::AS3::Value::Pick(v87, v51->pV);
    }
    pNode = v64.pNode;
    v32 = v64.pNode->RefCount-- == 1;
    if ( v32 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    goto LABEL_126;
  }
  VStr = (Scaleform::GFx::AS3::Instances::fl::RegExp *)v.value.VS._1.VStr;
  v66 = v.value.VS._1;
  if ( v.value.VS._1.VStr )
    v.value.VS._1.VStr->Size = (v.value.VS._1.VStr->Size + 1) & 0x8FBFFFFF;
  Scaleform::GFx::AS3::Instances::fl::RegExp::sourceGet(VStr, &v62);
  v17 = v62.pNode;
  if ( !v62.pNode->Size )
  {
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
      {
        v32 = pWeakProxy->RefCount-- == 1;
        if ( v32 )
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
        memset(&v.Bonus, 0, 24);
        Flags &= 0xFFFFFDE0;
        v.Flags = Flags;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
        Flags = v.Flags;
      }
      v17 = v62.pNode;
    }
    if ( v17 == &v17->pManager->NullStringNode )
    {
      v.value.VS._1.VStr = 0i64;
      v47.VObj = v84.VObj;
      v48 = Flags & 0xFFFFFFE0 | 0xC;
    }
    else
    {
      v48 = Flags & 0xFFFFFFE0 | 0xA;
      v.value.VS._1.VStr = v17;
      v47.VObj = v85.VObj;
      ++v17->RefCount;
    }
    v.value.VS._2 = v47;
    v.Flags = v48;
    v49 = v62.pNode;
    v32 = v62.pNode->RefCount-- == 1;
    if ( v32 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v49);
    if ( VStr )
    {
      if ( ((unsigned __int8)VStr & 1) != 0 )
      {
        v66.VStr = (Scaleform::GFx::ASStringNode *)((char *)&VStr[-1].DynAttrs.mHash.pTable + 7);
      }
      else
      {
        RefCount = VStr->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          VStr->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(VStr);
        }
      }
    }
    goto LABEL_122;
  }
  Scaleform::GFx::AS3::InstanceTraits::fl::Array::MakeInstance(
    &v61,
    (Scaleform::GFx::AS3::InstanceTraits::fl::Array *)vm->TraitsArray.pObject->ITraits.pObject);
  pV = v61.pV;
  v73 = v61.pV;
  v19 = 0;
  v20 = 0;
  while ( 1 )
  {
    v21 = Scaleform::GFx::AS3::Instances::fl::RegExp::AS3exec(VStr, &v69, &resulta);
    v22 = v8 | 1;
    v55 = v22;
    v24 = 0;
    if ( v21->pObject )
    {
      v23 = v20++;
      if ( v23 < (unsigned int)v65 )
        v24 = 1;
    }
    if ( (v22 & 1) != 0 )
    {
      v55 = v22 & 0xFFFFFFFE;
      pObject = v69.pObject;
      if ( v69.pObject )
      {
        if ( ((__int64)v69.pObject & 1) != 0 )
        {
          --v69.pObject;
        }
        else
        {
          v26 = v69.pObject->RefCount;
          if ( (v26 & 0x3FFFFF) != 0 )
          {
            v69.pObject->RefCount = v26 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
          }
        }
      }
    }
    if ( !v24 )
      break;
    Scaleform::String::String(&str, &resulta.pNode->pData[v19], (unsigned int)(-1 - v19));
    v27 = (Scaleform::GFx::AS3::Value::V1U *)Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                                               StringManagerRef,
                                               &v70,
                                               &str);
    v60.Flags = 10;
    v60.Bonus.pWeakProxy = 0i64;
    v28 = *v27;
    v60.value.VS._1 = *v27;
    if ( v27->VStr == &v27->VStr->pManager->NullStringNode )
    {
      v78 = 0i64;
      v60.value = (Scaleform::GFx::AS3::Value::VU)__PAIR128__(v79, 0i64);
      v60.Flags = 12;
    }
    else
    {
      ++v28.VStr->RefCount;
    }
    Length = pV->SA.Length;
    if ( Length != pV->SA.ValueA.Data.Size )
    {
      pV->SA.ValueHHighInd = Length;
      key.pFirst = &pV->SA.ValueHHighInd;
      key.pSecond = &v60;
      Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
        &pV->SA.ValueH.mHash,
        pV->SA.ValueH.mHash.pHeap,
        &key);
      goto LABEL_51;
    }
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &pV->SA.ValueA.Data,
      pV->SA.ValueA.Data.pHeap,
      pV->SA.ValueA.Data.Size + 1);
    v30 = 32 * pV->SA.ValueA.Data.Size;
    v31 = (__int64)&pV->SA.ValueA.Data.Data[-1];
    v32 = v30 + v31 == 0;
    v33 = (Scaleform::GFx::AS3::Value::VU *)(v30 + v31);
    v74 = v33;
    v71 = v33;
    if ( !v32 )
    {
      v33->VS._1.VInt = v60.Flags;
      v33->VS._2.VObj = (Scaleform::GFx::AS3::Object *)v60.Bonus.pWeakProxy;
      v33[1] = v60.value;
      if ( (v60.Flags & 0x1F) > 9 )
      {
        if ( (v60.Flags & 0x200) != 0 )
        {
          ++v60.Bonus.pWeakProxy->RefCount;
          goto LABEL_51;
        }
        if ( (v60.Flags & 0x1F) == 10 )
        {
          ++v60.value.VS._1.VStr->RefCount;
        }
        else
        {
          if ( (v60.Flags & 0x1F) <= 0xA )
            goto LABEL_51;
          if ( (v60.Flags & 0x1F) <= 0xF )
          {
            VObj = v60.value.VS._1;
          }
          else
          {
            if ( (v60.Flags & 0x1F) > 0x11 )
              goto LABEL_51;
            VObj = (Scaleform::GFx::AS3::Value::V1U)v60.value.VS._2.VObj;
          }
          if ( VObj.VStr )
          {
            ++VObj.VStr->Size;
            VObj.VStr->Size &= 0x8FBFFFFF;
          }
        }
      }
    }
LABEL_51:
    ++pV->SA.Length;
    if ( (v60.Flags & 0x1F) > 9 )
    {
      if ( (v60.Flags & 0x200) != 0 )
      {
        v32 = v60.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v32 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&v60.Bonus, 0, 24);
        v60.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v60);
      }
    }
    v35 = v70.pNode;
    v32 = v70.pNode->RefCount-- == 1;
    if ( v32 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v35);
    v19 = -1;
    if ( !_InterlockedDecrement((volatile signed __int32 *)((str.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    VStr = (Scaleform::GFx::AS3::Instances::fl::RegExp *)v.value.VS._1.VStr;
    pV = v61.pV;
    v8 = v55;
  }
  if ( v20 < (unsigned int)v65 )
  {
    Scaleform::String::String(&v68, &resulta.pNode->pData[v19], resulta.pNode->Size - v19);
    v36 = (Scaleform::GFx::AS3::Value::V1U *)Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                                               StringManagerRef,
                                               &v72,
                                               &v68);
    v59.Flags = 10;
    v59.Bonus.pWeakProxy = 0i64;
    v37 = *v36;
    v59.value.VS._1 = *v36;
    if ( v36->VStr == &v36->VStr->pManager->NullStringNode )
    {
      v81 = 0i64;
      v59.value = (Scaleform::GFx::AS3::Value::VU)__PAIR128__(v82, 0i64);
      v59.Flags = 12;
    }
    else
    {
      ++v37.VStr->RefCount;
    }
    v38 = pV->SA.Length;
    if ( v38 == pV->SA.ValueA.Data.Size )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        &pV->SA.ValueA.Data,
        pV->SA.ValueA.Data.pHeap,
        pV->SA.ValueA.Data.Size + 1);
      v39 = 32 * pV->SA.ValueA.Data.Size;
      v40 = (__int64)&pV->SA.ValueA.Data.Data[-1];
      v32 = v39 + v40 == 0;
      v41 = (Scaleform::GFx::AS3::Value::VU *)(v39 + v40);
      v71 = v41;
      v74 = v41;
      if ( !v32 )
      {
        v41->VS._1.VInt = v59.Flags;
        v41->VS._2.VObj = (Scaleform::GFx::AS3::Object *)v59.Bonus.pWeakProxy;
        v41[1] = v59.value;
        if ( (v59.Flags & 0x1F) > 9 )
        {
          if ( (v59.Flags & 0x200) != 0 )
          {
            ++v59.Bonus.pWeakProxy->RefCount;
            goto LABEL_82;
          }
          if ( (v59.Flags & 0x1F) == 10 )
          {
            ++v59.value.VS._1.VStr->RefCount;
          }
          else if ( (v59.Flags & 0x1F) > 0xA )
          {
            if ( (v59.Flags & 0x1F) <= 0xF )
            {
              v42 = v59.value.VS._1;
              goto LABEL_77;
            }
            if ( (v59.Flags & 0x1F) <= 0x11 )
            {
              v42 = (Scaleform::GFx::AS3::Value::V1U)v59.value.VS._2.VObj;
LABEL_77:
              if ( v42.VStr )
              {
                ++v42.VStr->Size;
                v42.VStr->Size &= 0x8FBFFFFF;
              }
            }
          }
        }
      }
    }
    else
    {
      pV->SA.ValueHHighInd = v38;
      v77.pFirst = &pV->SA.ValueHHighInd;
      v77.pSecond = &v59;
      Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
        &pV->SA.ValueH.mHash,
        pV->SA.ValueH.mHash.pHeap,
        &v77);
    }
LABEL_82:
    ++pV->SA.Length;
    if ( (v59.Flags & 0x1F) > 9 )
    {
      if ( (v59.Flags & 0x200) != 0 )
      {
        v32 = v59.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v32 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&v59.Bonus, 0, 24);
        v59.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v59);
      }
    }
    v43 = v72.pNode;
    v32 = v72.pNode->RefCount-- == 1;
    if ( v32 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v43);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((v68.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    pV = v61.pV;
    VStr = (Scaleform::GFx::AS3::Instances::fl::RegExp *)v.value.VS._1.VStr;
  }
  Scaleform::GFx::AS3::Value::Assign(v87, pV);
  if ( pV )
  {
    if ( ((unsigned __int8)pV & 1) != 0 )
    {
      v73 = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)pV - 1);
    }
    else
    {
      v44 = pV->RefCount;
      if ( (v44 & 0x3FFFFF) != 0 )
      {
        pV->RefCount = v44 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pV);
      }
    }
  }
  v45 = v62.pNode;
  v32 = v62.pNode->RefCount-- == 1;
  if ( v32 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v45);
  if ( VStr )
  {
    if ( v.value.VS._1.VBool )
    {
      v66.VStr = (Scaleform::GFx::ASStringNode *)((char *)&VStr[-1].DynAttrs.mHash.pTable + 7);
    }
    else
    {
      v46 = VStr->RefCount;
      if ( (v46 & 0x3FFFFF) != 0 )
      {
        VStr->RefCount = v46 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(VStr);
      }
    }
  }
LABEL_126:
  Flags = v.Flags;
  pWeakProxy = v.Bonus.pWeakProxy;
LABEL_127:
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
    {
      v32 = pWeakProxy->RefCount-- == 1;
      if ( v32 )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
      memset(&v.Bonus, 0, 24);
      v.Flags = Flags & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
    }
  }
LABEL_133:
  v53 = resulta.pNode;
  v32 = resulta.pNode->RefCount-- == 1;
  if ( v32 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v53);
}

// File Line: 708
// RVA: 0x7A6CE0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::String::AS3substr(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // r15
  int v9; // edi
  int length; // ebx
  int v11; // esi
  Scaleform::GFx::AS3::Value *v12; // r14
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v15; // zf
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::ASString self; // [rsp+30h] [rbp-48h] BYREF
  long double v18; // [rsp+38h] [rbp-40h] BYREF
  long double v19[2]; // [rsp+40h] [rbp-38h] BYREF
  Scaleform::GFx::ASString resulta; // [rsp+88h] [rbp+10h] BYREF

  v19[1] = NAN;
  StringManagerRef = vm->StringManagerRef;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    StringManagerRef,
    &self);
  if ( !Scaleform::GFx::AS3::Value::Convert2String(_this, (Scaleform::GFx::AS3::CheckResult *)&resulta, &self)->Result )
    goto LABEL_16;
  v9 = 0;
  length = -1;
  v11 = Scaleform::GFx::ASConstString::GetLength(&self);
  v12 = argv;
  if ( argc )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2Number(argv, (Scaleform::GFx::AS3::CheckResult *)&resulta, &v18)->Result )
      goto LABEL_16;
    v9 = v11;
    if ( v18 <= (double)v11 )
      v9 = (int)v18;
    if ( v9 < 0 )
      v9 += v11;
  }
  if ( argc >= 2 )
  {
    if ( !Scaleform::GFx::AS3::Value::Convert2Number(v12 + 1, (Scaleform::GFx::AS3::CheckResult *)&resulta, v19)->Result )
      goto LABEL_16;
    length = v11;
    if ( v19[0] <= (double)v11 )
      length = (int)v19[0];
    if ( length < 0 )
      length = 0;
  }
  v13 = Scaleform::GFx::AS3::InstanceTraits::fl::String::StringSubstring(&resulta, StringManagerRef, &self, v9, length);
  Scaleform::GFx::AS3::Value::Assign(result, v13);
  pNode = resulta.pNode;
  v15 = resulta.pNode->RefCount-- == 1;
  if ( v15 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
LABEL_16:
  v16 = self.pNode;
  v15 = self.pNode->RefCount-- == 1;
  if ( v15 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
}

// File Line: 757
// RVA: 0x7A6E60
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::String::AS3substring(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // r15
  int Length; // ebx
  double v10; // xmm0_8
  Scaleform::GFx::ASString *v11; // rax
  int v12; // r9d
  int v13; // eax
  Scaleform::GFx::ASString *v14; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v16; // zf
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::ASString resulta; // [rsp+10h] [rbp-41h] BYREF
  long double v19; // [rsp+18h] [rbp-39h] BYREF
  long double v20[2]; // [rsp+20h] [rbp-31h] BYREF
  int v21; // [rsp+30h] [rbp-21h]
  Scaleform::GFx::ASString v22[3]; // [rsp+38h] [rbp-19h] BYREF
  int v23; // [rsp+50h] [rbp-1h]
  __int64 v24; // [rsp+58h] [rbp+7h]
  long double v25; // [rsp+60h] [rbp+Fh]
  Scaleform::GFx::ASString v26; // [rsp+B0h] [rbp+5Fh] BYREF
  void *retaddr; // [rsp+C8h] [rbp+77h]
  Scaleform::GFx::AS3::Value *v28; // [rsp+D0h] [rbp+7Fh]

  v20[1] = NAN;
  StringManagerRef = vm->StringManagerRef;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    StringManagerRef,
    v22);
  if ( Scaleform::GFx::AS3::Value::Convert2String(_this, (Scaleform::GFx::AS3::CheckResult *)&v26, &resulta)->Result )
  {
    Length = Scaleform::GFx::ASConstString::GetLength(&resulta);
    v19 = 0.0;
    v20[0] = DOUBLE_2_147483647e9;
    if ( (!(_DWORD)retaddr
       || Scaleform::GFx::AS3::Value::Convert2Number(v28, (Scaleform::GFx::AS3::CheckResult *)&v26, &v19)->Result)
      && ((unsigned int)retaddr < 2
       || Scaleform::GFx::AS3::Value::Convert2Number(v28 + 1, (Scaleform::GFx::AS3::CheckResult *)&v26, v20)->Result) )
    {
      v21 = 4;
      v22[0].pNode = 0i64;
      v22[1] = *(Scaleform::GFx::ASString *)&v19;
      v26.pNode = *(Scaleform::GFx::ASStringNode **)&v19;
      if ( (*(_QWORD *)&v19 & 0x7FF0000000000000i64) == 0x7FF0000000000000i64
        && (*(_QWORD *)&v19 & 0xFFFFFFFFFFFFFi64) != 0 )
      {
        v19 = Scaleform::GFx::NumberUtil::NEGATIVE_INFINITY();
      }
      v23 = 4;
      v24 = 0i64;
      v25 = v20[0];
      v26.pNode = *(Scaleform::GFx::ASStringNode **)&v20[0];
      if ( (*(_QWORD *)&v20[0] & 0x7FF0000000000000i64) == 0x7FF0000000000000i64
        && (*(_QWORD *)&v20[0] & 0xFFFFFFFFFFFFFi64) != 0 )
      {
        v10 = Scaleform::GFx::NumberUtil::NEGATIVE_INFINITY();
        v20[0] = v10;
      }
      else
      {
        v10 = v20[0];
      }
      if ( v10 == v19 )
      {
        v11 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
                StringManagerRef,
                &v26);
        Scaleform::GFx::AS3::Value::Assign(result, v11);
      }
      else
      {
        v12 = Length;
        if ( v19 <= (double)Length )
          v12 = (int)v19;
        if ( v10 <= (double)Length )
          Length = (int)v10;
        if ( Length < v12 )
        {
          v13 = v12;
          v12 = Length;
          Length = v13;
        }
        if ( v12 < 0 )
          v12 = 0;
        v14 = Scaleform::GFx::AS3::InstanceTraits::fl::String::StringSubstring(
                &v26,
                StringManagerRef,
                &resulta,
                v12,
                Length - v12);
        Scaleform::GFx::AS3::Value::Assign(result, v14);
      }
      pNode = v26.pNode;
      v16 = v26.pNode->RefCount-- == 1;
      if ( v16 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
  }
  v17 = resulta.pNode;
  v16 = resulta.pNode->RefCount-- == 1;
  if ( v16 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
}

// File Line: 824
// RVA: 0x7A78F0
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::String::AS3toLowerCase(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::ASString *v6; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v8; // zf
  Scaleform::GFx::ASStringNode *v9; // rcx
  Scaleform::GFx::ASString resulta; // [rsp+20h] [rbp-18h] BYREF
  __int64 v11; // [rsp+28h] [rbp-10h]
  Scaleform::GFx::ASString v12; // [rsp+48h] [rbp+10h] BYREF

  v11 = -2i64;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    vm->StringManagerRef,
    &resulta);
  if ( Scaleform::GFx::AS3::Value::Convert2String(_this, (Scaleform::GFx::AS3::CheckResult *)&v12, &resulta)->Result )
  {
    v6 = Scaleform::GFx::ASString::ToLower(&resulta, &v12);
    Scaleform::GFx::AS3::Value::Assign(result, v6);
    pNode = v12.pNode;
    v8 = v12.pNode->RefCount-- == 1;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  v9 = resulta.pNode;
  v8 = resulta.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
}

// File Line: 844
// RVA: 0x7A8B20
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::String::AS3toLocaleUpperCase(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::ASString *v6; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v8; // zf
  Scaleform::GFx::ASStringNode *v9; // rcx
  Scaleform::GFx::ASString resulta; // [rsp+20h] [rbp-18h] BYREF
  __int64 v11; // [rsp+28h] [rbp-10h]
  Scaleform::GFx::ASString v12; // [rsp+48h] [rbp+10h] BYREF

  v11 = -2i64;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    vm->StringManagerRef,
    &resulta);
  if ( Scaleform::GFx::AS3::Value::Convert2String(_this, (Scaleform::GFx::AS3::CheckResult *)&v12, &resulta)->Result )
  {
    v6 = Scaleform::GFx::ASString::ToUpper(&resulta, &v12);
    Scaleform::GFx::AS3::Value::Assign(result, v6);
    pNode = v12.pNode;
    v8 = v12.pNode->RefCount-- == 1;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  v9 = resulta.pNode;
  v8 = resulta.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
}

// File Line: 904
// RVA: 0x7A8270
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::String::AS3valueOf(
        Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::VM::Error *v5; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::VM::Error v8; // [rsp+28h] [rbp-20h] BYREF

  if ( (_this->Flags & 0x1F) == 10 )
  {
    Scaleform::GFx::AS3::Value::Assign(result, _this);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v8, 1058, vm);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v5, &Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v8.Message.pNode;
    if ( v8.Message.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}

// File Line: 949
// RVA: 0x741A80
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl::String::valueOfProto(
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
  pObject = vm->TraitsString.pObject->ITraits.pObject;
  if ( !pObject->pConstructor.pObject )
    pObject->vfptr[3].~RefCountBaseGC<328>(pObject);
  if ( VObj == Scaleform::GFx::AS3::Class::GetPrototype(pObject->pConstructor.pObject) )
  {
    Scaleform::GFx::AS3::Value::Assign(result, (Scaleform::GFx::ASString *)vm->StringManagerRef);
  }
  else
  {
LABEL_6:
    if ( (_this->Flags & 0x1F) == 10 )
    {
      Scaleform::GFx::AS3::Value::Assign(result, _this);
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(&v12, eIllegalOperandTypeError, vm);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(vm, v9, &Scaleform::GFx::AS3::fl::TypeErrorTI);
      pNode = v12.Message.pNode;
      if ( v12.Message.pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
  }
}

// File Line: 967
// RVA: 0x7BF7C0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl::CreateStringFromCStr(
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::AS3::StringManager *sm,
        const char *start,
        const char *end)
{
  __int64 v5; // rax

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
  if ( (int)v5 < 1 )
    Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(sm, result);
  else
    Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
      sm,
      result,
      start,
      (int)v5);
  return result;
}

// File Line: 977
// RVA: 0x822970
Scaleform::String::DataDesc *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl::String::StringSplit(
        Scaleform::String::DataDesc *result,
        Scaleform::GFx::ASStringNode *vm,
        Scaleform::GFx::ASString *str,
        Scaleform::GFx::ASStringNode *delimiters,
        unsigned int limit)
{
  char *v5; // r15
  Scaleform::String::DataDesc *v8; // r14
  Scaleform::GFx::ASStringNode *pNode; // r8
  char *pData; // rax
  bool v11; // zf
  unsigned __int64 Size; // rsi
  __int64 v13; // rcx
  __int64 v14; // rcx
  __int64 v15; // rdx
  __int64 v16; // rdx
  Scaleform::GFx::AS3::Value::V1U VObj; // rax
  Scaleform::GFx::AS3::Value::VU v18; // rdi
  unsigned int v19; // ebx
  Scaleform::GFx::AS3::Value::V1U *v20; // rax
  Scaleform::GFx::AS3::Value::V1U v21; // rdx
  Scaleform::GFx::ASStringNode *v22; // rcx
  unsigned int v23; // r12d
  const char *v24; // r13
  char *v25; // rbx
  char *v26; // r15
  unsigned int Char_Advance0; // r14d
  unsigned int v28; // esi
  char *v29; // rbx
  Scaleform::GFx::AS3::Value::V1U *v30; // rax
  Scaleform::GFx::AS3::Value::V1U v31; // rdx
  Scaleform::GFx::ASStringNode *v32; // rcx
  Scaleform::GFx::ASStringNode *pLower; // rdx
  Scaleform::GFx::AS3::Value::V1U *v34; // rax
  Scaleform::GFx::AS3::Value::V1U v35; // rdx
  Scaleform::GFx::ASStringNode *v36; // rcx
  Scaleform::GFx::AS3::Value::V1U *StringFromCStr; // rax
  Scaleform::GFx::AS3::Value::V1U v38; // rdx
  char *v39; // rcx
  Scaleform::GFx::AS3::Value v41; // [rsp+20h] [rbp-E0h] BYREF
  char *end; // [rsp+40h] [rbp-C0h] BYREF
  Scaleform::GFx::AS3::Value v43; // [rsp+48h] [rbp-B8h] BYREF
  char *v44; // [rsp+68h] [rbp-98h] BYREF
  Scaleform::GFx::AS3::Value v45; // [rsp+70h] [rbp-90h] BYREF
  Scaleform::GFx::AS3::Value v; // [rsp+90h] [rbp-70h] BYREF
  Scaleform::GFx::AS3::Value v47; // [rsp+B0h] [rbp-50h] BYREF
  Scaleform::GFx::AS3::Value v48; // [rsp+D0h] [rbp-30h] BYREF
  Scaleform::GFx::ASString v49; // [rsp+F0h] [rbp-10h] BYREF
  Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef key; // [rsp+F8h] [rbp-8h] BYREF
  Scaleform::GFx::AS3::Value::V1U v51; // [rsp+108h] [rbp+8h]
  Scaleform::GFx::AS3::Value::V2U v52; // [rsp+110h] [rbp+10h]
  __int64 v53; // [rsp+118h] [rbp+18h]
  Scaleform::GFx::AS3::Value::V2U v54; // [rsp+128h] [rbp+28h]
  Scaleform::GFx::AS3::Value::V2U v55; // [rsp+138h] [rbp+38h]
  Scaleform::GFx::AS3::Value::V2U v56; // [rsp+148h] [rbp+48h]
  Scaleform::GFx::AS3::Value::V2U v57; // [rsp+158h] [rbp+58h]
  Scaleform::GFx::AS3::Value::V2U v58; // [rsp+168h] [rbp+68h]
  Scaleform::String stra; // [rsp+1C0h] [rbp+C0h] BYREF
  Scaleform::GFx::ASString resulta; // [rsp+1C8h] [rbp+C8h] BYREF
  char *putf8Buffer; // [rsp+1D0h] [rbp+D0h] BYREF
  Scaleform::GFx::ASString v62; // [rsp+1D8h] [rbp+D8h] BYREF

  v62.pNode = delimiters;
  resulta.pNode = vm;
  stra.pData = result;
  v53 = -2i64;
  v5 = (char *)delimiters;
  v8 = result;
  Scaleform::GFx::AS3::InstanceTraits::fl::Array::MakeInstance(
    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> *)result,
    (Scaleform::GFx::AS3::InstanceTraits::fl::Array *)vm[13].pLower[5].pData);
  pNode = str->pNode;
  pData = (char *)str->pNode->pData;
  putf8Buffer = pData;
  if ( !v5 )
  {
    v.Flags = 10;
    v.Bonus.pWeakProxy = 0i64;
    v.value.VS._1.VStr = pNode;
    if ( pNode == &pNode->pManager->NullStringNode )
    {
      v.value.VS._1.VStr = 0i64;
      v.value.VS._2 = v58;
      v.Flags = 12;
    }
    else
    {
      ++pNode->RefCount;
    }
    Scaleform::GFx::AS3::Impl::SparseArray::PushBack((Scaleform::GFx::AS3::Impl::SparseArray *)(v8->Size + 56), &v);
    if ( (v.Flags & 0x1F) > 9 )
    {
      if ( (v.Flags & 0x200) != 0 )
      {
        v11 = v.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v11 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&v.Bonus, 0, 24);
        v.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
      }
    }
    return v8;
  }
  if ( *v5 )
  {
    v23 = 0;
    v24 = pData;
    while ( 2 )
    {
      v44 = v5;
      end = pData;
      v25 = 0i64;
      while ( 1 )
      {
        v26 = pData;
        Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
        if ( !Char_Advance0 )
          --putf8Buffer;
        v28 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&v44);
        if ( !v28 )
          --v44;
        pData = putf8Buffer;
        if ( !v25 )
          v25 = putf8Buffer;
        if ( !Char_Advance0 )
          break;
        if ( !v28 )
          goto LABEL_66;
        if ( Char_Advance0 != v28 )
        {
          pData = v25;
          putf8Buffer = v25;
          break;
        }
      }
      if ( v28 )
      {
        v29 = end;
      }
      else
      {
LABEL_66:
        if ( v23 >= limit )
          return stra.pData;
        v29 = end;
        v30 = (Scaleform::GFx::AS3::Value::V1U *)Scaleform::GFx::AS3::InstanceTraits::fl::CreateStringFromCStr(
                                                   &v49,
                                                   (Scaleform::GFx::AS3::StringManager *)resulta.pNode->pLower,
                                                   v24,
                                                   end);
        v45.Flags = 10;
        v45.Bonus.pWeakProxy = 0i64;
        v31 = *v30;
        v45.value.VS._1 = *v30;
        if ( v30->VStr == &v30->VStr->pManager->NullStringNode )
        {
          v45.value.VS._1.VStr = 0i64;
          v45.value.VS._2 = v54;
          v45.Flags = 12;
        }
        else
        {
          ++v31.VStr->RefCount;
        }
        Scaleform::GFx::AS3::Impl::SparseArray::PushBack(
          (Scaleform::GFx::AS3::Impl::SparseArray *)(*(_QWORD *)stra.HeapTypeBits + 56i64),
          &v45);
        if ( (v45.Flags & 0x1F) > 9 )
        {
          if ( (v45.Flags & 0x200) != 0 )
          {
            v11 = v45.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v11 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            memset(&v45.Bonus, 0, 24);
            v45.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v45);
          }
        }
        v32 = v49.pNode;
        v11 = v49.pNode->RefCount-- == 1;
        if ( v11 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v32);
        v24 = v26;
        pData = v26;
        putf8Buffer = v26;
        ++v23;
      }
      v5 = (char *)v62.pNode;
      if ( Char_Advance0 )
        continue;
      break;
    }
    if ( v23 < limit )
    {
      pLower = resulta.pNode->pLower;
      if ( v28 )
      {
        StringFromCStr = (Scaleform::GFx::AS3::Value::V1U *)Scaleform::GFx::AS3::InstanceTraits::fl::CreateStringFromCStr(
                                                              (Scaleform::GFx::ASString *)&end,
                                                              (Scaleform::GFx::AS3::StringManager *)pLower,
                                                              v24,
                                                              0i64);
        v43.Flags = 10;
        v43.Bonus.pWeakProxy = 0i64;
        v38 = *StringFromCStr;
        v43.value.VS._1 = *StringFromCStr;
        if ( StringFromCStr->VStr == &StringFromCStr->VStr->pManager->NullStringNode )
        {
          v43.value.VS._1.VStr = 0i64;
          v43.value.VS._2 = v55;
          v43.Flags = 12;
        }
        else
        {
          ++v38.VStr->RefCount;
        }
        v8 = stra.pData;
        Scaleform::GFx::AS3::Impl::SparseArray::PushBack(
          (Scaleform::GFx::AS3::Impl::SparseArray *)(*(_QWORD *)stra.HeapTypeBits + 56i64),
          &v43);
        if ( (v43.Flags & 0x1F) > 9 )
        {
          if ( (v43.Flags & 0x200) != 0 )
          {
            v11 = v43.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v11 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            memset(&v43.Bonus, 0, 24);
            v43.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v43);
          }
        }
        v39 = end;
        v11 = (*((_DWORD *)end + 6))-- == 1;
        if ( v11 )
          Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)v39);
      }
      else
      {
        v34 = (Scaleform::GFx::AS3::Value::V1U *)Scaleform::GFx::AS3::InstanceTraits::fl::CreateStringFromCStr(
                                                   &v62,
                                                   (Scaleform::GFx::AS3::StringManager *)pLower,
                                                   v24,
                                                   v29);
        v47.Flags = 10;
        v47.Bonus.pWeakProxy = 0i64;
        v35 = *v34;
        v47.value.VS._1 = *v34;
        if ( v34->VStr == &v34->VStr->pManager->NullStringNode )
        {
          v47.value.VS._1.VStr = 0i64;
          v47.value.VS._2 = v57;
          v47.Flags = 12;
        }
        else
        {
          ++v35.VStr->RefCount;
        }
        v8 = stra.pData;
        Scaleform::GFx::AS3::Impl::SparseArray::PushBack(
          (Scaleform::GFx::AS3::Impl::SparseArray *)(*(_QWORD *)stra.HeapTypeBits + 56i64),
          &v47);
        if ( (v47.Flags & 0x1F) > 9 )
        {
          if ( (v47.Flags & 0x200) != 0 )
          {
            v11 = v47.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v11 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            memset(&v47.Bonus, 0, 24);
            v47.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v47);
          }
        }
        v36 = v62.pNode;
        v11 = v62.pNode->RefCount-- == 1;
        if ( v11 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v36);
      }
      return v8;
    }
    return stra.pData;
  }
  if ( !pNode->Size )
  {
    v41.Flags = 10;
    v41.Bonus.pWeakProxy = 0i64;
    v41.value.VS._1.VStr = pNode;
    if ( pNode == &pNode->pManager->NullStringNode )
    {
      v41.value.VS._1.VStr = 0i64;
      v41.value.VS._2 = v56;
      v41.Flags = 12;
    }
    else
    {
      ++pNode->RefCount;
    }
    Size = v8->Size;
    v13 = *(_QWORD *)(v8->Size + 56);
    if ( v13 == *(_QWORD *)(v8->Size + 120) )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)(Size + 112),
        *(__int64 **)(Size + 136),
        *(_QWORD *)(Size + 120) + 1i64);
      v14 = 32i64 * *(_QWORD *)(Size + 120);
      v15 = *(_QWORD *)(Size + 112) - 32i64;
      v11 = v14 + v15 == 0;
      v16 = v14 + v15;
      stra.pData = (Scaleform::String::DataDesc *)v16;
      resulta.pNode = (Scaleform::GFx::ASStringNode *)v16;
      if ( !v11 )
      {
        *(_DWORD *)v16 = v41.Flags;
        *(_QWORD *)(v16 + 8) = v41.Bonus.pWeakProxy;
        *(Scaleform::GFx::AS3::Value::VU *)(v16 + 16) = v41.value;
        if ( (v41.Flags & 0x1F) > 9 )
        {
          if ( (v41.Flags & 0x200) != 0 )
          {
            ++v41.Bonus.pWeakProxy->RefCount;
            goto LABEL_32;
          }
          if ( (v41.Flags & 0x1F) == 10 )
          {
            ++v41.value.VS._1.VStr->RefCount;
          }
          else if ( (v41.Flags & 0x1F) > 0xA )
          {
            if ( (v41.Flags & 0x1F) <= 0xF )
            {
              VObj = v41.value.VS._1;
LABEL_27:
              if ( VObj.VStr )
              {
                ++VObj.VStr->Size;
                VObj.VStr->Size &= 0x8FBFFFFF;
              }
              goto LABEL_32;
            }
            if ( (v41.Flags & 0x1F) <= 0x11 )
            {
              VObj = (Scaleform::GFx::AS3::Value::V1U)v41.value.VS._2.VObj;
              goto LABEL_27;
            }
          }
        }
      }
    }
    else
    {
      *(_QWORD *)(Size + 72) = v13;
      key.pFirst = (const unsigned __int64 *)(Size + 72);
      key.pSecond = &v41;
      Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
        (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)(Size + 144),
        *(void **)(Size + 152),
        &key);
    }
LABEL_32:
    ++*(_QWORD *)(Size + 56);
    if ( (v41.Flags & 0x1F) > 9 )
    {
      if ( (v41.Flags & 0x200) != 0 )
      {
        v11 = v41.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v11 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&v41.Bonus, 0, 24);
        v41.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v41);
      }
    }
    return v8;
  }
  Scaleform::String::String(&stra);
  v18.VS._1.VStr = 0i64;
  v18.VS._2 = v52;
  while ( 1 )
  {
    v19 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
    if ( !v19 )
      break;
    Scaleform::String::Clear(&stra);
    Scaleform::String::AppendChar(&stra, v19);
    v20 = (Scaleform::GFx::AS3::Value::V1U *)Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                                               (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)vm->pLower,
                                               &resulta,
                                               &stra);
    v48.Flags = 10;
    v48.Bonus.pWeakProxy = 0i64;
    v21 = *v20;
    v48.value.VS._1 = *v20;
    if ( v20->VStr == &v20->VStr->pManager->NullStringNode )
    {
      v51 = v18.VS._1;
      v48.value = v18;
      v48.Flags = 12;
    }
    else
    {
      ++v21.VStr->RefCount;
    }
    Scaleform::GFx::AS3::Impl::SparseArray::PushBack((Scaleform::GFx::AS3::Impl::SparseArray *)(v8->Size + 56), &v48);
    if ( (v48.Flags & 0x1F) > 9 )
    {
      if ( (v48.Flags & 0x200) != 0 )
      {
        v11 = v48.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v11 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&v48.Bonus, 0, 24);
        v48.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v48);
      }
    }
    v22 = resulta.pNode;
    v11 = resulta.pNode->RefCount-- == 1;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v22);
  }
  --putf8Buffer;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((stra.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  return v8;
}

// File Line: 1071
// RVA: 0x8230D0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl::String::StringSubstring(
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::AS3::StringManager *sm,
        Scaleform::GFx::ASString *self,
        int start,
        int length)
{
  int v5; // esi
  int v9; // ebx
  signed int v10; // ecx

  v5 = start;
  v9 = length;
  if ( length )
  {
    if ( start < 0 )
      v5 = 0;
    v10 = Scaleform::GFx::ASConstString::GetLength(self);
    if ( v5 < v10 )
    {
      if ( length < 0 || v5 + length > v10 )
        v9 = v10 - v5;
      Scaleform::GFx::ASString::Substring(self, result, v5, v5 + v9);
    }
    else
    {
      Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(sm, result);
    }
  }
  else
  {
    Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(sm, result);
  }
  return result;
}

// File Line: 1141
// RVA: 0x79E4A0
void __fastcall Scaleform::GFx::AS3::Classes::fl::String::AS3fromCharCode(
        Scaleform::GFx::AS3::Classes::fl::String *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *const argv)
{
  int v8; // ebx
  char *pData; // r8
  Scaleform::GFx::ASString *v10; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  unsigned int v13; // [rsp+20h] [rbp-68h] BYREF
  Scaleform::GFx::ASString v14; // [rsp+28h] [rbp-60h] BYREF
  __int64 v15; // [rsp+30h] [rbp-58h]
  Scaleform::StringBuffer v16; // [rsp+38h] [rbp-50h] BYREF
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+A0h] [rbp+18h] BYREF

  v15 = -2i64;
  Scaleform::StringBuffer::StringBuffer(&v16, Scaleform::Memory::pGlobalHeap);
  v8 = 0;
  if ( argc )
  {
    while ( Scaleform::GFx::AS3::Value::Convert2UInt32(&argv[v8], &resulta, &v13)->Result )
    {
      Scaleform::StringBuffer::AppendChar(&v16, (unsigned __int16)v13);
      if ( ++v8 >= argc )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    pData = &customCaption;
    if ( v16.pData )
      pData = v16.pData;
    v10 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
            this->pTraits.pObject->pVM->StringManagerRef,
            &v14,
            pData,
            v16.Size);
    Scaleform::GFx::AS3::Value::Assign(result, v10);
    pNode = v14.pNode;
    if ( v14.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&v16);
}

// File Line: 1156
// RVA: 0x849B00
// attributes: thunk
void __fastcall Scaleform::GFx::AS3::Classes::fl::String::fromCharCode(
        Scaleform::GFx::AS3::Classes::fl::String *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *const argv)
{
  Scaleform::GFx::AS3::Classes::fl::String::AS3fromCharCode(this, result, argc, argv);
}

// File Line: 1169
// RVA: 0x7B8ED0
void __fastcall Scaleform::GFx::AS3::Classes::fl::String::Construct(
        Scaleform::GFx::AS3::Classes::fl::String *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString resulta; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::CheckResult v10; // [rsp+50h] [rbp+18h] BYREF

  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    this->pTraits.pObject->pVM->StringManagerRef,
    &resulta);
  if ( !argc || Scaleform::GFx::AS3::Value::Convert2String(argv, &v10, &resulta)->Result )
    Scaleform::GFx::AS3::Value::Assign(result, &resulta);
  pNode = resulta.pNode;
  if ( resulta.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 1194
// RVA: 0x7F4CF0
void __fastcall Scaleform::GFx::AS3::Classes::fl::String::InitPrototype(
        Scaleform::GFx::AS3::Classes::fl::String *this,
        Scaleform::GFx::AS3::Object *obj)
{
  Scaleform::GFx::AS3::Class *pObject; // rcx
  Scaleform::GFx::AS3::ThunkInfo *v5; // rbx
  __int64 v6; // rdi
  Scaleform::GFx::AS3::Value *(__fastcall *v7)(Scaleform::GFx::AS3::Class *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *); // [rsp+20h] [rbp-18h] BYREF
  int v8; // [rsp+28h] [rbp-10h]

  pObject = this->ParentClass.pObject;
  if ( pObject )
    pObject->vfptr[7].Finalize_GC(pObject);
  v8 = 0;
  v7 = Scaleform::GFx::AS3::Class::ConvertCopy;
  Scaleform::GFx::AS3::Class::InitPrototypeFromVTable(
    this,
    obj,
    (Scaleform::GFx::AS3::Value *(__fastcall *)(Scaleform::GFx::AS3::Class *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Value *))&v7);
  v5 = Scaleform::GFx::AS3::Classes::fl::String::f;
  v6 = 2i64;
  do
  {
    Scaleform::GFx::AS3::Object::AddDynamicFunc(obj, v5++);
    --v6;
  }
  while ( v6 );
  Scaleform::GFx::AS3::Class::AddConstructor(this, obj);
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
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Classes::fl::String,0,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Classes::fl::String *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Classes::fl::String::AS3fromCharCode;
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
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Classes::fl::String,1,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Classes::fl::String *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Classes::fl::String::fromCharCode;
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
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl::String::MakeClassTraits(
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
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, vm, &Scaleform::GFx::AS3::fl::StringCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::String::`vftable;
    v6->TraitsType = Traits_String;
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
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, vm, &Scaleform::GFx::AS3::fl::StringCI);
    v8.pV->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
    v8.pV->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::String::`vftable;
    v8.pV->TraitsType = Traits_String;
  }
  else
  {
    v8.pV = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(result->pV, v8);
  v9 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))MHeap->vfptr->Alloc)(
                                       MHeap,
                                       72i64);
  v10 = v9;
  if ( v9 )
  {
    Scaleform::GFx::AS3::Class::Class(v9, result->pV);
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl::String::`vftable;
  }
  return result;
}

// File Line: 1254
// RVA: 0x7B6A00
char __fastcall Scaleform::GFx::AS3::ClassTraits::fl::String::Coerce(
        Scaleform::GFx::AS3::ClassTraits::fl::String *this,
        Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::AS3::Value *result)
{
  unsigned int v5; // r8d
  Scaleform::GFx::ASStringNode *v6; // rcx
  bool v7; // zf
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  Scaleform::GFx::AS3::Value::V2U v11; // [rsp+30h] [rbp-18h]
  Scaleform::GFx::AS3::CheckResult v12; // [rsp+58h] [rbp+10h] BYREF
  Scaleform::GFx::ASString resulta; // [rsp+68h] [rbp+20h] BYREF

  v5 = value->Flags & 0x1F;
  if ( !v5 || (v5 - 12 <= 3 || v5 == 10) && !value->value.VS._1.VStr )
  {
    if ( (result->Flags & 0x1F) > 9 )
    {
      if ( (result->Flags & 0x200) != 0 )
      {
        pWeakProxy = result->Bonus.pWeakProxy;
        v7 = pWeakProxy->RefCount-- == 1;
        if ( v7 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        result->Bonus.pWeakProxy = 0i64;
        result->value.VS._1.VStr = 0i64;
        result->value.VS._2.VObj = 0i64;
        result->Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(result);
      }
    }
    result->value.VS._1.VStr = 0i64;
    result->value.VS._2 = v11;
    result->Flags &= 0xFFFFFFEC;
    result->Flags |= 0xCu;
    return 1;
  }
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    this->pVM->StringManagerRef,
    &resulta);
  if ( Scaleform::GFx::AS3::Value::Convert2String(value, &v12, &resulta)->Result )
  {
    Scaleform::GFx::AS3::Value::Assign(result, &resulta);
    pNode = resulta.pNode;
    v7 = resulta.pNode->RefCount-- == 1;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    return 1;
  }
  v6 = resulta.pNode;
  v7 = resulta.pNode->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  return 0;
}

