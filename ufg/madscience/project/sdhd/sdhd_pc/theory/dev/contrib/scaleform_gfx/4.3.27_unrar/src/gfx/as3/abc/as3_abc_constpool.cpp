// File Line: 158
// RVA: 0x77C2E0
void __fastcall Scaleform::GFx::AS3::Abc::ConstPool::ConstPool(Scaleform::GFx::AS3::Abc::ConstPool *this)
{
  Scaleform::ArrayLH_POD<long,339,Scaleform::ArrayDefaultPolicy> *v1; // rax
  Scaleform::ArrayLH_POD<unsigned long,339,Scaleform::ArrayDefaultPolicy> *v2; // rax
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Abc::StringView,339,Scaleform::ArrayDefaultPolicy> *v3; // rax
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Abc::NamespaceInfo,339,Scaleform::ArrayDefaultPolicy> *v4; // rax
  Scaleform::ArrayLH_POD<Scaleform::GFx::AS3::Abc::NamespaceSetInfo,339,Scaleform::ArrayDefaultPolicy> *v5; // rax
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Abc::Multiname,339,Scaleform::ArrayDefaultPolicy> *v6; // rax

  v1 = &this->ConstInt;
  v1->Data.Data = 0i64;
  v1->Data.Size = 0i64;
  v1->Data.Policy.Capacity = 0i64;
  v2 = &this->ConstUInt;
  v2->Data.Data = 0i64;
  v2->Data.Size = 0i64;
  v2->Data.Policy.Capacity = 0i64;
  v3 = &this->ConstStr;
  v3->Data.Data = 0i64;
  v3->Data.Size = 0i64;
  v3->Data.Policy.Capacity = 0i64;
  v4 = &this->ConstNamespace;
  v4->Data.Data = 0i64;
  v4->Data.Size = 0i64;
  v4->Data.Policy.Capacity = 0i64;
  v5 = &this->const_ns_set;
  v5->Data.Data = 0i64;
  v5->Data.Size = 0i64;
  v5->Data.Policy.Capacity = 0i64;
  v6 = &this->const_multiname;
  v6->Data.Data = 0i64;
  v6->Data.Size = 0i64;
  v6->Data.Policy.Capacity = 0i64;
  this->any_namespace.Kind = 0;
  this->any_namespace.NameURI.pStr = &customWorldMapCaption;
  this->any_namespace.NameURI.Size = 0i64;
}

// File Line: 179
// RVA: 0x7E91E0
double __fastcall Scaleform::GFx::AS3::Abc::ConstPool::GetDouble(Scaleform::GFx::AS3::Abc::ConstPool *this, unsigned __int64 ind)
{
  const char *v2; // r8
  double v4; // [rsp+10h] [rbp+10h]

  if ( !ind )
    return 0.0;
  v2 = this->Doubles;
  LODWORD(v4) = (unsigned __int8)v2[8 * ind - 8] | (((unsigned __int8)v2[8 * ind - 7] | (*(unsigned __int16 *)&v2[8 * ind - 6] << 8)) << 8);
  HIDWORD(v4) = (unsigned __int8)v2[8 * ind - 4] | (((unsigned __int8)v2[8 * ind - 3] | (((unsigned __int8)v2[8 * ind - 2] | ((unsigned __int8)v2[8 * ind - 1] << 8)) << 8)) << 8);
  return v4;
}

