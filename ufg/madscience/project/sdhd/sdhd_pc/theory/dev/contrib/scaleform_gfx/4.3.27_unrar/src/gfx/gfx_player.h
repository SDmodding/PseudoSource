// File Line: 92
// RVA: 0x8A5E70
void __fastcall Scaleform::GFx::MemoryContext::~MemoryContext(Scaleform::GFx::MemoryContext *this)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::MemoryContext::`vftable;
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}

// File Line: 314
// RVA: 0x6D2570
void __fastcall Scaleform::GFx::MovieDef::ResourceVisitor::~ResourceVisitor(
        Scaleform::GFx::MovieDef::ResourceVisitor *this)
{
  this->vfptr = (Scaleform::GFx::MovieDef::ResourceVisitorVtbl *)&Scaleform::GFx::MovieDef::ResourceVisitor::`vftable;
}

// File Line: 670
// RVA: 0x6D2460
void __fastcall Scaleform::GFx::Value::ObjectInterface::~ObjectInterface(Scaleform::GFx::Value::ObjectInterface *this)
{
  this->vfptr = (Scaleform::GFx::Value::ObjectInterfaceVtbl *)&Scaleform::GFx::Value::ObjectInterface::`vftable;
}

// File Line: 806
// RVA: 0xBD2C0
void __fastcall Scaleform::GFx::Value::Value(Scaleform::GFx::Value *this)
{
  this->pObjectInterface = 0i64;
  this->Type = VT_Undefined;
}

// File Line: 835
// RVA: 0xBD920
void __fastcall Scaleform::GFx::Value::~Value(Scaleform::GFx::Value *this)
{
  if ( (this->Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&this->pObjectInterface->vfptr->gap8[8])(
      this->pObjectInterface,
      this,
      this->mValue);
    this->pObjectInterface = 0i64;
    this->Type = VT_Undefined;
  }
  else
  {
    this->Type = VT_Undefined;
  }
}

// File Line: 841
// RVA: 0x5CEE00
Scaleform::GFx::Value *__fastcall Scaleform::GFx::Value::operator=(
        Scaleform::GFx::Value *this,
        Scaleform::GFx::Value *src)
{
  Scaleform::GFx::Value::ObjectInterface *pObjectInterface; // rcx
  Scaleform::GFx::Value::ValueUnion mValue; // r8

  if ( this != src )
  {
    if ( (this->Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&this->pObjectInterface->vfptr->gap8[8])(
        this->pObjectInterface,
        this,
        this->mValue);
      this->pObjectInterface = 0i64;
    }
    this->Type = src->Type;
    this->mValue.pString = src->mValue.pString;
    this->DataAux = src->DataAux;
    if ( (src->Type & 0x40) != 0 )
    {
      pObjectInterface = src->pObjectInterface;
      mValue = this->mValue;
      this->pObjectInterface = pObjectInterface;
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))pObjectInterface->vfptr->gap8)(
        pObjectInterface,
        this,
        mValue);
    }
  }
  return this;
}

// File Line: 1538
// RVA: 0x8E1810
Scaleform::Ptr<Scaleform::GFx::VirtualKeyboardInterface> *__fastcall Scaleform::GFx::StateBag::GetVirtualKeyboardInterface(
        Scaleform::GFx::StateBag *this,
        Scaleform::Ptr<Scaleform::GFx::VirtualKeyboardInterface> *result)
{
  result->pObject = (Scaleform::GFx::VirtualKeyboardInterface *)this->vfptr->GetStateAddRef(this, 9i64);
  return result;
}

// File Line: 1549
// RVA: 0xA239A0
void __fastcall Scaleform::GFx::ExternalInterface::~ExternalInterface(Scaleform::GFx::ExternalInterface *this)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ExternalInterface::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::State::`vftable;
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}

// File Line: 1639
// RVA: 0x8DB550
Scaleform::Ptr<Scaleform::GFx::MultitouchInterface> *__fastcall Scaleform::GFx::StateBag::GetMultitouchInterface(
        Scaleform::GFx::StateBag *this,
        Scaleform::Ptr<Scaleform::GFx::MultitouchInterface> *result)
{
  result->pObject = (Scaleform::GFx::MultitouchInterface *)this->vfptr->GetStateAddRef(this, 7i64);
  return result;
}

// File Line: 1665
// RVA: 0x8D4C10
Scaleform::Ptr<Scaleform::GFx::AccelerometerInterface> *__fastcall Scaleform::GFx::StateBag::GetAccelerometerInterface(
        Scaleform::GFx::StateBag *this,
        Scaleform::Ptr<Scaleform::GFx::AccelerometerInterface> *result)
{
  result->pObject = (Scaleform::GFx::AccelerometerInterface *)this->vfptr->GetStateAddRef(this, 10i64);
  return result;
}

// File Line: 1691
// RVA: 0x8D91C0
Scaleform::Ptr<Scaleform::GFx::GeolocationInterface> *__fastcall Scaleform::GFx::StateBag::GetGeolocationInterface(
        Scaleform::GFx::StateBag *this,
        Scaleform::Ptr<Scaleform::GFx::GeolocationInterface> *result)
{
  result->pObject = (Scaleform::GFx::GeolocationInterface *)this->vfptr->GetStateAddRef(this, 11i64);
  return result;
}

// File Line: 1929
// RVA: 0x5EDE70
__int64 Scaleform::GFx::Movie::Invoke(Scaleform::GFx::Movie *this, const char *ppathToMethod, const char *pargFmt, ...)
{
  va_list va; // [rsp+58h] [rbp+20h] BYREF

  va_start(va, pargFmt);
  return Scaleform::GFx::Movie::InvokeArgs(this, ppathToMethod, 0i64, pargFmt, va);
}

// File Line: 2332
// RVA: 0x8A45A0
void __fastcall Scaleform::GFx::ExternalLibPtr::~ExternalLibPtr(Scaleform::GFx::ExternalLibPtr *this)
{
  this->vfptr = (Scaleform::GFx::ExternalLibPtrVtbl *)&Scaleform::GFx::ExternalLibPtr::`vftable;
}

