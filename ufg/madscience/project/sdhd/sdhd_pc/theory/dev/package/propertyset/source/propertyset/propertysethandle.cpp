// File Line: 26
// RVA: 0x1ECE20
void __fastcall UFG::PropertySetHandle::PropertySetHandle(UFG::PropertySetHandle *this)
{
  BackInfo::BackInfo(&this->mName);
  this->mpPropSet = 0i64;
}

// File Line: 30
// RVA: 0x1ECDA0
void __fastcall UFG::PropertySetHandle::PropertySetHandle(UFG::PropertySetHandle *this, UFG::qPropertySet *pPropSet)
{
  UFG::qSymbol *Name; // rax

  BackInfo::BackInfo(&this->mName);
  this->mpPropSet = pPropSet;
  if ( this->mpPropSet )
  {
    Name = UFG::qPropertySet::GetName(this->mpPropSet);
    UFG::qSymbol::qSymbol(&this->mName, Name);
    UFG::qPropertySet::AddRef(this->mpPropSet);
  }
}

// File Line: 46
// RVA: 0x1ECD30
void __fastcall UFG::PropertySetHandle::PropertySetHandle(UFG::PropertySetHandle *this, UFG::PropertySetHandle *handle)
{
  UFG::qSymbol::qSymbol(&this->mName, &handle->mName);
  this->mpPropSet = handle->mpPropSet;
  if ( handle->mpPropSet )
    UFG::qPropertySet::AddRef(handle->mpPropSet);
}

// File Line: 54
// RVA: 0x1FA460
void __fastcall UFG::PropertySetHandle::Null(UFG::PropertySetHandle *this)
{
  if ( this->mpPropSet )
    UFG::qPropertySet::ReleaseRef(this->mpPropSet);
  this->mpPropSet = 0i64;
  UFG::qSymbol::qSymbol(&this->mName, &UFG::gNullQSymbol);
}

// File Line: 67
// RVA: 0x1EE590
void __fastcall UFG::PropertySetHandle::~PropertySetHandle(UFG::PropertySetHandle *this)
{
  if ( this->mpPropSet )
    UFG::qPropertySet::ReleaseRef(this->mpPropSet);
  _((AMD_HD3D *)this);
}

// File Line: 84
// RVA: 0x1F20C0
void __fastcall UFG::PropertySetHandle::Bind(UFG::PropertySetHandle *this)
{
  if ( !this->mpPropSet && !UFG::qSymbol::is_null(&this->mName) )
  {
    this->mpPropSet = UFG::PropertySetManager::GetPropertySet(&this->mName);
    if ( this->mpPropSet )
      UFG::qPropertySet::AddRef(this->mpPropSet);
  }
}

// File Line: 101
// RVA: 0x1F9B00
bool __fastcall UFG::PropertySetHandle::IsValid(UFG::PropertySetHandle *this)
{
  this->mpPropSet = UFG::PropertySetManager::FindPropertySet(&this->mName);
  return this->mpPropSet != 0i64;
}

// File Line: 117
// RVA: 0x1FE300
void __fastcall UFG::PropertySetHandle::SetPropSet(UFG::PropertySetHandle *this, UFG::PropertySetHandle *handle)
{
  if ( UFG::qSymbol::operator!=(&this->mName, &handle->mName) )
  {
    if ( handle->mpPropSet )
      UFG::qPropertySet::AddRef(handle->mpPropSet);
    if ( this->mpPropSet )
      UFG::qPropertySet::ReleaseRef(this->mpPropSet);
    this->mpPropSet = handle->mpPropSet;
    UFG::qSymbol::qSymbol(&this->mName, &handle->mName);
  }
}

// File Line: 138
// RVA: 0x1FE390
void __fastcall UFG::PropertySetHandle::SetPropSet(UFG::PropertySetHandle *this, UFG::qPropertySet *pPropSet)
{
  UFG::qSymbol *Name; // rax

  if ( pPropSet )
  {
    if ( this->mpPropSet != pPropSet )
    {
      UFG::qPropertySet::AddRef(pPropSet);
      if ( this->mpPropSet )
        UFG::qPropertySet::ReleaseRef(this->mpPropSet);
      this->mpPropSet = pPropSet;
      Name = UFG::qPropertySet::GetName(pPropSet);
      UFG::qSymbol::qSymbol(&this->mName, Name);
    }
  }
  else
  {
    if ( this->mpPropSet )
      UFG::qPropertySet::ReleaseRef(this->mpPropSet);
    this->mpPropSet = 0i64;
    UFG::qSymbol::qSymbol(&this->mName, &UFG::gNullQSymbol);
  }
}

