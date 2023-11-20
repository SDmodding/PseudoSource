// File Line: 78
// RVA: 0x7B10A0
const char *__fastcall Scaleform::GFx::AS3::AsString(Scaleform::GFx::AS3::Abc::NamespaceKind kind)
{
  const char *result; // rax

  switch ( kind )
  {
    case 0u:
      result = "public";
      break;
    case 1u:
      result = "protected";
      break;
    case 2u:
      result = "static protected";
      break;
    case 3u:
      result = "private";
      break;
    case 4u:
      result = "explicit";
      break;
    case 5u:
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
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS3::AsString(Scaleform::GFx::ASString *result, Scaleform::GFx::AS3::Value *value, Scaleform::GFx::AS3::StringManager *sm)
{
  Scaleform::GFx::AS3::StringManager *v3; // rsi
  Scaleform::GFx::AS3::Value *v4; // rbx
  Scaleform::GFx::ASString *v5; // rdi
  Scaleform::GFx::ASStringNode *v6; // rax
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::String *v9; // rax
  Scaleform::String *v10; // rax
  long double v11; // rcx
  Scaleform::GFx::ASString *v12; // rbx
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASString *v14; // rax
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::ASStringNode *v18; // rax
  long double v19; // rcx
  Scaleform::GFx::ASString *v20; // rbx
  Scaleform::GFx::ASString *v21; // rax
  Scaleform::GFx::ASString *v22; // rax
  Scaleform::GFx::ASStringNode *v23; // rcx
  Scaleform::GFx::ASStringNode *v24; // rcx
  Scaleform::GFx::ASStringNode *v25; // rcx
  Scaleform::GFx::ASString *v26; // rbx
  const char *v27; // rax
  Scaleform::GFx::ASStringNode *v28; // rax
  Scaleform::GFx::ASStringNode *v29; // rcx
  Scaleform::GFx::ASString v31; // [rsp+28h] [rbp-58h]
  Scaleform::GFx::ASString resulta; // [rsp+30h] [rbp-50h]
  Scaleform::GFx::ASString v33; // [rsp+38h] [rbp-48h]
  Scaleform::GFx::ASStringNode *v34; // [rsp+40h] [rbp-40h]
  Scaleform::GFx::ASString v35; // [rsp+48h] [rbp-38h]
  Scaleform::String v36; // [rsp+50h] [rbp-30h]
  Scaleform::GFx::ASString v37; // [rsp+58h] [rbp-28h]
  Scaleform::String v38; // [rsp+60h] [rbp-20h]
  Scaleform::GFx::ASStringNode *v39; // [rsp+68h] [rbp-18h]
  Scaleform::GFx::ASString v40; // [rsp+70h] [rbp-10h]
  __int64 v41; // [rsp+78h] [rbp-8h]
  Scaleform::GFx::AS3::CheckResult v42; // [rsp+A8h] [rbp+28h]
  int v; // [rsp+B8h] [rbp+38h]

  v41 = -2i64;
  v3 = sm;
  v4 = value;
  v5 = result;
  switch ( value->Flags & 0x1F )
  {
    case 0u:
    case 1u:
    case 2u:
    case 3u:
    case 4u:
    case 0xAu:
      Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
        (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)sm->Builtins,
        &resulta);
      Scaleform::GFx::AS3::Value::Convert2String(v4, &v42, &resulta);
      v6 = resulta.pNode;
      v5->pNode = resulta.pNode;
      ++v6->RefCount;
      v7 = resulta.pNode;
      v8 = resulta.pNode->RefCount == 1;
      --v7->RefCount;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v7);
      break;
    case 5u:
      Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
        (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)sm->Builtins,
        result,
        "thunk");
      break;
    case 7u:
      v = value->value.VS._1.VInt;
      v9 = Scaleform::AsString<long>(&v38, &v);
      v10 = Scaleform::operator+(&v36, "VTable ind: ", v9);
      Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
        (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v3->Builtins,
        v5,
        v10);
      if ( !_InterlockedDecrement((volatile signed __int32 *)((v36.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      if ( !_InterlockedDecrement((volatile signed __int32 *)((v38.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      break;
    case 0xBu:
      v26 = (Scaleform::GFx::ASString *)value->value.VS._1.VStr;
      v27 = Scaleform::GFx::AS3::AsString((Scaleform::GFx::AS3::Abc::NamespaceKind)((_QWORD)v26[5].pNode << 60 >> 60));
      Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
        (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v3->Builtins,
        &v31,
        v27);
      if ( v26[7].pNode->Size )
      {
        Scaleform::GFx::ASString::Append(&v31, " ", 1ui64);
        Scaleform::GFx::ASString::Append(&v31, v26 + 7);
      }
      v28 = v31.pNode;
      v5->pNode = v31.pNode;
      ++v28->RefCount;
      v29 = v31.pNode;
      v8 = v31.pNode->RefCount == 1;
      --v29->RefCount;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v29);
      break;
    case 0xCu:
      v11 = value->value.VNumber;
      if ( v11 == 0.0 )
        goto LABEL_19;
      v12 = (Scaleform::GFx::ASString *)(*(__int64 (__fastcall **)(_QWORD, Scaleform::GFx::ASStringNode **))(**(_QWORD **)(*(_QWORD *)&v11 + 40i64) + 32i64))(
                                          *(_QWORD *)(*(_QWORD *)&v11 + 40i64),
                                          &v34);
      v13 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
              (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v3->Builtins,
              &v40,
              "[object ");
      v14 = Scaleform::GFx::ASString::operator+(v13, &v33, v12);
      Scaleform::GFx::ASString::operator+(v14, v5, "]");
      v15 = v33.pNode;
      v8 = v33.pNode->RefCount == 1;
      --v15->RefCount;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v15);
      v16 = v40.pNode;
      v8 = v40.pNode->RefCount == 1;
      --v16->RefCount;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v16);
      v17 = v34;
      v8 = v34->RefCount == 1;
      --v17->RefCount;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v17);
      break;
    case 0xDu:
      v19 = value->value.VNumber;
      if ( v19 == 0.0 )
      {
LABEL_19:
        v18 = sm->Builtins[2].pNode;
        v5->pNode = v18;
        ++v18->RefCount;
      }
      else
      {
        v20 = (Scaleform::GFx::ASString *)(*(__int64 (__fastcall **)(_QWORD, Scaleform::GFx::ASStringNode **))(**(_QWORD **)(*(_QWORD *)&v19 + 40i64) + 32i64))(
                                            *(_QWORD *)(*(_QWORD *)&v19 + 40i64),
                                            &v39);
        v21 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v3->Builtins,
                &v37,
                "[class ");
        v22 = Scaleform::GFx::ASString::operator+(v21, &v35, v20);
        Scaleform::GFx::ASString::operator+(v22, v5, "]");
        v23 = v35.pNode;
        v8 = v35.pNode->RefCount == 1;
        --v23->RefCount;
        if ( v8 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v23);
        v24 = v37.pNode;
        v8 = v37.pNode->RefCount == 1;
        --v24->RefCount;
        if ( v8 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v24);
        v25 = v39;
        v8 = v39->RefCount == 1;
        --v25->RefCount;
        if ( v8 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v25);
      }
      break;
    case 0xEu:
      Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
        (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)sm->Builtins,
        result,
        "function Function() {}");
      break;
    case 0xFu:
      Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
        (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)sm->Builtins,
        result,
        "thunk function");
      break;
    case 0x10u:
      Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
        (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)sm->Builtins,
        result,
        "ThunkClosure");
      break;
    case 0x11u:
      Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
        (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)sm->Builtins,
        result,
        "VTableIndClosure");
      break;
    default:
      Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
        (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)sm->Builtins,
        result);
      break;
  }
  return v5;
}

