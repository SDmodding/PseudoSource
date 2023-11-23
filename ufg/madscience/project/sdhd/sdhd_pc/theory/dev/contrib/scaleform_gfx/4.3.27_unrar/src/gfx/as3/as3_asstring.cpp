// File Line: 78
// RVA: 0x7B10A0
const char *__fastcall Scaleform::GFx::AS3::AsString(Scaleform::GFx::AS3::Abc::NamespaceKind kind)
{
  const char *result; // rax

  switch ( kind )
  {
    case NS_Public:
      result = "public";
      break;
    case NS_Protected:
      result = "protected";
      break;
    case NS_StaticProtected:
      result = "static protected";
      break;
    case NS_Private:
      result = "private";
      break;
    case NS_Explicit:
      result = "explicit";
      break;
    case NS_PackageInternal:
      result = "package internal";
      break;
    default:
      result = "Invalid Namespace type";
      break;
  }
  return result;
}

// File Line: 105
// RVA: 0x7B0D00
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::AsString(
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::AS3::StringManager *sm)
{
  Scaleform::GFx::ASStringNode *pNode; // rax
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::String *v9; // rax
  Scaleform::String *v10; // rax
  Scaleform::GFx::AS3::Value::V1U v11; // rcx
  Scaleform::GFx::ASString *v12; // rbx
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASString *v14; // rax
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::ASStringNode *v18; // rax
  Scaleform::GFx::AS3::Value::V1U v19; // rcx
  Scaleform::GFx::ASString *v20; // rbx
  Scaleform::GFx::ASString *v21; // rax
  Scaleform::GFx::ASString *v22; // rax
  Scaleform::GFx::ASStringNode *v23; // rcx
  Scaleform::GFx::ASStringNode *v24; // rcx
  Scaleform::GFx::ASStringNode *v25; // rcx
  Scaleform::GFx::AS3::Value::V1U v26; // rbx
  const char *v27; // rax
  Scaleform::GFx::ASStringNode *v28; // rax
  Scaleform::GFx::ASStringNode *v29; // rcx
  Scaleform::GFx::ASString v31; // [rsp+28h] [rbp-58h] BYREF
  Scaleform::GFx::ASString resulta; // [rsp+30h] [rbp-50h] BYREF
  Scaleform::GFx::ASString v33; // [rsp+38h] [rbp-48h] BYREF
  Scaleform::GFx::ASStringNode *v34; // [rsp+40h] [rbp-40h] BYREF
  Scaleform::GFx::ASString v35; // [rsp+48h] [rbp-38h] BYREF
  Scaleform::String v36; // [rsp+50h] [rbp-30h] BYREF
  Scaleform::GFx::ASString v37; // [rsp+58h] [rbp-28h] BYREF
  Scaleform::String v38; // [rsp+60h] [rbp-20h] BYREF
  Scaleform::GFx::ASStringNode *v39; // [rsp+68h] [rbp-18h] BYREF
  Scaleform::GFx::ASString v40; // [rsp+70h] [rbp-10h] BYREF
  __int64 v41; // [rsp+78h] [rbp-8h]
  Scaleform::GFx::AS3::CheckResult v42; // [rsp+A8h] [rbp+28h] BYREF
  int v; // [rsp+B8h] [rbp+38h] BYREF

  v41 = -2i64;
  switch ( value->Flags & 0x1F )
  {
    case 0u:
    case 1u:
    case 2u:
    case 3u:
    case 4u:
    case 0xAu:
      Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(sm, &resulta);
      Scaleform::GFx::AS3::Value::Convert2String(value, &v42, &resulta);
      pNode = resulta.pNode;
      result->pNode = resulta.pNode;
      ++pNode->RefCount;
      v7 = resulta.pNode;
      v8 = resulta.pNode->RefCount-- == 1;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v7);
      break;
    case 5u:
      Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
        sm,
        result,
        "thunk");
      break;
    case 7u:
      v = value->value.VS._1.VInt;
      v9 = Scaleform::AsString<long>(&v38, &v);
      v10 = Scaleform::operator+(&v36, "VTable ind: ", v9);
      Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(sm, result, v10);
      if ( !_InterlockedDecrement((volatile signed __int32 *)((v36.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      if ( !_InterlockedDecrement((volatile signed __int32 *)((v38.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      break;
    case 0xBu:
      v26 = value->value.VS._1;
      v27 = Scaleform::GFx::AS3::AsString((Scaleform::GFx::AS3::Abc::NamespaceKind)((int)(LODWORD(v26.VStr[1].pData) << 28) >> 28));
      Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
        sm,
        &v31,
        v27);
      if ( v26.VStr[1].pLower->Size )
      {
        Scaleform::GFx::ASString::Append(&v31, " ", 1ui64);
        Scaleform::GFx::ASString::Append(&v31, (Scaleform::GFx::ASString *)&v26.VStr[1].16);
      }
      v28 = v31.pNode;
      result->pNode = v31.pNode;
      ++v28->RefCount;
      v29 = v31.pNode;
      v8 = v31.pNode->RefCount-- == 1;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v29);
      break;
    case 0xCu:
      v11 = value->value.VS._1;
      if ( !v11.VStr )
        goto LABEL_19;
      v12 = (Scaleform::GFx::ASString *)(*(__int64 (__fastcall **)(const char *, Scaleform::GFx::ASStringNode **))(*(_QWORD *)v11.VStr[1].pData + 32i64))(
                                          v11.VStr[1].pData,
                                          &v34);
      v13 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
              sm,
              &v40,
              "[object ");
      v14 = Scaleform::GFx::ASString::operator+(v13, &v33, v12);
      Scaleform::GFx::ASString::operator+(v14, result, "]");
      v15 = v33.pNode;
      v8 = v33.pNode->RefCount-- == 1;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v15);
      v16 = v40.pNode;
      v8 = v40.pNode->RefCount-- == 1;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v16);
      v17 = v34;
      v8 = v34->RefCount-- == 1;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v17);
      break;
    case 0xDu:
      v19 = value->value.VS._1;
      if ( v19.VStr )
      {
        v20 = (Scaleform::GFx::ASString *)(*(__int64 (__fastcall **)(const char *, Scaleform::GFx::ASStringNode **))(*(_QWORD *)v19.VStr[1].pData + 32i64))(
                                            v19.VStr[1].pData,
                                            &v39);
        v21 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                sm,
                &v37,
                "[class ");
        v22 = Scaleform::GFx::ASString::operator+(v21, &v35, v20);
        Scaleform::GFx::ASString::operator+(v22, result, "]");
        v23 = v35.pNode;
        v8 = v35.pNode->RefCount-- == 1;
        if ( v8 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v23);
        v24 = v37.pNode;
        v8 = v37.pNode->RefCount-- == 1;
        if ( v8 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v24);
        v25 = v39;
        v8 = v39->RefCount-- == 1;
        if ( v8 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v25);
      }
      else
      {
LABEL_19:
        v18 = sm->Builtins[2].pNode;
        result->pNode = v18;
        ++v18->RefCount;
      }
      break;
    case 0xEu:
      Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
        sm,
        result,
        "function Function() {}");
      break;
    case 0xFu:
      Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
        sm,
        result,
        "thunk function");
      break;
    case 0x10u:
      Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
        sm,
        result,
        "ThunkClosure");
      break;
    case 0x11u:
      Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
        sm,
        result,
        "VTableIndClosure");
      break;
    default:
      Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(sm, result);
      break;
  }
  return result;
}

