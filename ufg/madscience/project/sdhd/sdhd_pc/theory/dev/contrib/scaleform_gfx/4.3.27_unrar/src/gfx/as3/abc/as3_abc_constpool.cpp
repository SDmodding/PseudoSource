// File Line: 158
// RVA: 0x77C2E0
void __fastcall Scaleform::GFx::AS3::Abc::ConstPool::ConstPool(Scaleform::GFx::AS3::Abc::ConstPool *this)
{
  this->ConstInt.Data.Data = 0i64;
  this->ConstInt.Data.Size = 0i64;
  this->ConstInt.Data.Policy.Capacity = 0i64;
  this->ConstUInt.Data.Data = 0i64;
  this->ConstUInt.Data.Size = 0i64;
  this->ConstUInt.Data.Policy.Capacity = 0i64;
  this->ConstStr.Data.Data = 0i64;
  this->ConstStr.Data.Size = 0i64;
  this->ConstStr.Data.Policy.Capacity = 0i64;
  this->ConstNamespace.Data.Data = 0i64;
  this->ConstNamespace.Data.Size = 0i64;
  this->ConstNamespace.Data.Policy.Capacity = 0i64;
  this->const_ns_set.Data.Data = 0i64;
  this->const_ns_set.Data.Size = 0i64;
  this->const_ns_set.Data.Policy.Capacity = 0i64;
  this->const_multiname.Data.Data = 0i64;
  this->const_multiname.Data.Size = 0i64;
  this->const_multiname.Data.Policy.Capacity = 0i64;
  this->any_namespace.Kind = NS_Public;
  this->any_namespace.NameURI.pStr = &customCaption;
  this->any_namespace.NameURI.Size = 0i64;
}

// File Line: 179
// RVA: 0x7E91E0
double __fastcall Scaleform::GFx::AS3::Abc::ConstPool::GetDouble(
        Scaleform::GFx::AS3::Abc::ConstPool *this,
        unsigned __int64 ind)
{
  const char *Doubles; // r8
  double v4; // [rsp+10h] [rbp+10h]

  if ( !ind )
    return 0.0;
  Doubles = this->Doubles;
  LODWORD(v4) = (unsigned __int8)Doubles[8 * ind - 8] | (((unsigned __int8)Doubles[8 * ind - 7] | (*(unsigned __int16 *)&Doubles[8 * ind - 6] << 8)) << 8);
  HIDWORD(v4) = (unsigned __int8)Doubles[8 * ind - 4] | (((unsigned __int8)Doubles[8 * ind - 3] | (((unsigned __int8)Doubles[8 * ind - 2] | ((unsigned __int8)Doubles[8 * ind - 1] << 8)) << 8)) << 8);
  return v4;
}

