// File Line: 26
// RVA: 0x1ECE20
void __fastcall UFG::PropertySetHandle::PropertySetHandle(UFG::PropertySetHandle *this)
{
  UFG::PropertySetHandle *v1; // [rsp+40h] [rbp+8h]

  v1 = this;
  BackInfo::BackInfo(&this->mName);
  v1->mpPropSet = 0i64;
}

// File Line: 30
// RVA: 0x1ECDA0
void __fastcall UFG::PropertySetHandle::PropertySetHandle(UFG::PropertySetHandle *this, UFG::qPropertySet *pPropSet)
{
  UFG::qSymbol *v2; // rax
  UFG::PropertySetHandle *v3; // [rsp+40h] [rbp+8h]
  UFG::qPropertySet *v4; // [rsp+48h] [rbp+10h]

  v4 = pPropSet;
  v3 = this;
  BackInfo::BackInfo(&this->mName);
  v3->mpPropSet = v4;
  if ( v3->mpPropSet )
  {
    v2 = UFG::qPropertySet::GetName(v3->mpPropSet);
    UFG::qSymbol::qSymbol(&v3->mName, v2);
    UFG::qPropertySet::AddRef(v3->mpPropSet);
  }
}

// File Line: 46
// RVA: 0x1ECD30
void __fastcall UFG::PropertySetHandle::PropertySetHandle(UFG::PropertySetHandle *this, UFG::PropertySetHandle *handle)
{
  UFG::PropertySetHandle *v2; // [rsp+40h] [rbp+8h]
  UFG::PropertySetHandle *source; // [rsp+48h] [rbp+10h]

  source = handle;
  v2 = this;
  UFG::qSymbol::qSymbol(&this->mName, &handle->mName);
  v2->mpPropSet = source->mpPropSet;
  if ( source->mpPropSet )
    UFG::qPropertySet::AddRef(source->mpPropSet);
}

// File Line: 54
// RVA: 0x1FA460
void __fastcall UFG::PropertySetHandle::Null(UFG::PropertySetHandle *this)
{
  UFG::PropertySetHandle *v1; // [rsp+30h] [rbp+8h]

  v1 = this;
  if ( this->mpPropSet )
    UFG::qPropertySet::ReleaseRef(this->mpPropSet);
  v1->mpPropSet = 0i64;
  UFG::qSymbol::qSymbol(&v1->mName, &UFG::gNullQSymbol);
}

// File Line: 67
// RVA: 0x1EE590
void __fastcall UFG::PropertySetHandle::~PropertySetHandle(UFG::PropertySetHandle *this)
{
  AMD_HD3D *v1; // [rsp+40h] [rbp+8h]

  v1 = (AMD_HD3D *)this;
  if ( this->mpPropSet )
    UFG::qPropertySet::ReleaseRef(this->mpPropSet);
  _(v1);
}

// File Line: 84
// RVA: 0x1F20C0
void __fastcall UFG::PropertySetHandle::Bind(UFG::PropertySetHandle *this)
{
  UFG::PropertySetHandle *propSetName; // [rsp+30h] [rbp+8h]

  propSetName = this;
  if ( !this->mpPropSet && !UFG::qSymbol::is_null(&this->mName) )
  {
    propSetName->mpPropSet = UFG::PropertySetManager::GetPropertySet(&propSetName->mName);
    if ( propSetName->mpPropSet )
      UFG::qPropertySet::AddRef(propSetName->mpPropSet);
  }
}

// File Line: 101
// RVA: 0x1F9B00
bool __fastcall UFG::PropertySetHandle::IsValid(UFG::PropertySetHandle *this)
{
  UFG::PropertySetHandle *propSetName; // [rsp+30h] [rbp+8h]

  propSetName = this;
  this->mpPropSet = UFG::PropertySetManager::FindPropertySet(&this->mName);
  return propSetName->mpPropSet != 0i64;
}

// File Line: 117
// RVA: 0x1FE300
void __fastcall UFG::PropertySetHandle::SetPropSet(UFG::PropertySetHandle *this, UFG::PropertySetHandle *handle)
{
  UFG::PropertySetHandle *v2; // [rsp+30h] [rbp+8h]
  UFG::PropertySetHandle *sym; // [rsp+38h] [rbp+10h]

  sym = handle;
  v2 = this;
  if ( UFG::qSymbol::operator!=(&this->mName, &handle->mName) )
  {
    if ( sym->mpPropSet )
      UFG::qPropertySet::AddRef(sym->mpPropSet);
    if ( v2->mpPropSet )
      UFG::qPropertySet::ReleaseRef(v2->mpPropSet);
    v2->mpPropSet = sym->mpPropSet;
    UFG::qSymbol::qSymbol(&v2->mName, &sym->mName);
  }
}

// File Line: 138
// RVA: 0x1FE390
void __fastcall UFG::PropertySetHandle::SetPropSet(UFG::PropertySetHandle *this, UFG::qPropertySet *pPropSet)
{
  UFG::qSymbol *v2; // rax
  UFG::PropertySetHandle *v3; // [rsp+30h] [rbp+8h]
  UFG::qPropertySet *v4; // [rsp+38h] [rbp+10h]

  v4 = pPropSet;
  v3 = this;
  if ( pPropSet )
  {
    if ( this->mpPropSet != pPropSet )
    {
      UFG::qPropertySet::AddRef(pPropSet);
      if ( v3->mpPropSet )
        UFG::qPropertySet::ReleaseRef(v3->mpPropSet);
      v3->mpPropSet = v4;
      v2 = UFG::qPropertySet::GetName(v4);
      UFG::qSymbol::qSymbol(&v3->mName, v2);
    }
  }
  else
  {
    if ( this->mpPropSet )
      UFG::qPropertySet::ReleaseRef(this->mpPropSet);
    v3->mpPropSet = 0i64;
    UFG::qSymbol::qSymbol(&v3->mName, &UFG::gNullQSymbol);
  }
}

