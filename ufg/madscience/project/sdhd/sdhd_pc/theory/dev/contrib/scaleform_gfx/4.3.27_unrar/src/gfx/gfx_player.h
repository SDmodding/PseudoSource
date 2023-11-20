// File Line: 92
// RVA: 0x8A5E70
void __fastcall Scaleform::GFx::MemoryContext::~MemoryContext(Scaleform::GFx::MemoryContext *this)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::MemoryContext::`vftable;
  Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)&this->vfptr);
}

// File Line: 314
// RVA: 0x6D2570
void __fastcall Scaleform::GFx::MovieDef::ResourceVisitor::~ResourceVisitor(Scaleform::GFx::MovieDef::ResourceVisitor *this)
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
  this->Type = 0;
}

// File Line: 835
// RVA: 0xBD920
void __fastcall Scaleform::GFx::Value::~Value(Scaleform::GFx::Value *this)
{
  Scaleform::GFx::Value *v1; // rbx

  v1 = this;
  if ( ((unsigned int)this->Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&this->pObjectInterface->vfptr->gap8[8])(
      this->pObjectInterface,
      this,
      *(_QWORD *)&this->mValue.NValue);
    v1->pObjectInterface = 0i64;
    v1->Type = 0;
  }
  else
  {
    this->Type = 0;
  }
}

// File Line: 841
// RVA: 0x5CEE00
Scaleform::GFx::Value *__fastcall Scaleform::GFx::Value::operator=(Scaleform::GFx::Value *this, Scaleform::GFx::Value *src)
{
  Scaleform::GFx::Value *v2; // rdi
  Scaleform::GFx::Value *v3; // rbx
  Scaleform::GFx::Value::ObjectInterface *v4; // rcx
  long double v5; // r8

  v2 = src;
  v3 = this;
  if ( this != src )
  {
    if ( ((unsigned int)this->Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&this->pObjectInterface->vfptr->gap8[8])(
        this->pObjectInterface,
        this,
        *(_QWORD *)&this->mValue.NValue);
      v3->pObjectInterface = 0i64;
    }
    v3->Type = v2->Type;
    v3->mValue.NValue = v2->mValue.NValue;
    v3->DataAux = v2->DataAux;
    if ( ((unsigned int)v2->Type >> 6) & 1 )
    {
      v4 = v2->pObjectInterface;
      v5 = v3->mValue.NValue;
      v3->pObjectInterface = v4;
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, long double))v4->vfptr->gap8)(
        v4,
        v3,
        COERCE_LONG_DOUBLE(*(_QWORD *)&v5));
    }
  }
  return v3;
}

// File Line: 1538
// RVA: 0x8E1810
Scaleform::Ptr<Scaleform::GFx::VirtualKeyboardInterface> *__fastcall Scaleform::GFx::StateBag::GetVirtualKeyboardInterface(Scaleform::GFx::StateBag *this, Scaleform::Ptr<Scaleform::GFx::VirtualKeyboardInterface> *result)
{
  Scaleform::Ptr<Scaleform::GFx::VirtualKeyboardInterface> *v2; // rbx

  v2 = result;
  result->pObject = (Scaleform::GFx::VirtualKeyboardInterface *)this->vfptr->GetStateAddRef(
                                                                  this,
                                                                  State_Internal_MaskOwner);
  return v2;
}

// File Line: 1549
// RVA: 0xA239A0
void __fastcall Scaleform::GFx::ExternalInterface::~ExternalInterface(Scaleform::GFx::ExternalInterface *this)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ExternalInterface::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::State::`vftable;
  Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)&this->vfptr);
}

// File Line: 1639
// RVA: 0x8DB550
Scaleform::Ptr<Scaleform::GFx::MultitouchInterface> *__fastcall Scaleform::GFx::StateBag::GetMultitouchInterface(Scaleform::GFx::StateBag *this, Scaleform::Ptr<Scaleform::GFx::MultitouchInterface> *result)
{
  Scaleform::Ptr<Scaleform::GFx::MultitouchInterface> *v2; // rbx

  v2 = result;
  result->pObject = (Scaleform::GFx::MultitouchInterface *)this->vfptr->GetStateAddRef(this, State_UserData);
  return v2;
}

// File Line: 1665
// RVA: 0x8D4C10
Scaleform::Ptr<Scaleform::GFx::AccelerometerInterface> *__fastcall Scaleform::GFx::StateBag::GetAccelerometerInterface(Scaleform::GFx::StateBag *this, Scaleform::Ptr<Scaleform::GFx::AccelerometerInterface> *result)
{
  Scaleform::Ptr<Scaleform::GFx::AccelerometerInterface> *v2; // rbx

  v2 = result;
  result->pObject = (Scaleform::GFx::AccelerometerInterface *)this->vfptr->GetStateAddRef(this, State_OrigNodeBounds);
  return v2;
}

// File Line: 1691
// RVA: 0x8D91C0
Scaleform::Ptr<Scaleform::GFx::GeolocationInterface> *__fastcall Scaleform::GFx::StateBag::GetGeolocationInterface(Scaleform::GFx::StateBag *this, Scaleform::Ptr<Scaleform::GFx::GeolocationInterface> *result)
{
  Scaleform::Ptr<Scaleform::GFx::GeolocationInterface> *v2; // rbx

  v2 = result;
  result->pObject = (Scaleform::GFx::GeolocationInterface *)this->vfptr->GetStateAddRef(this, State_Type_Count);
  return v2;
}

// File Line: 1929
// RVA: 0x5EDE70
__int64 Scaleform::GFx::Movie::Invoke(Scaleform::GFx::Movie *this, const char *ppathToMethod, const char *pargFmt, ...)
{
  va_list va; // [rsp+58h] [rbp+20h]

  va_start(va, pargFmt);
  return Scaleform::GFx::Movie::InvokeArgs(this, ppathToMethod, 0i64, pargFmt, va);
}

// File Line: 2332
// RVA: 0x8A45A0
void __fastcall Scaleform::GFx::ExternalLibPtr::~ExternalLibPtr(Scaleform::GFx::ExternalLibPtr *this)
{
  this->vfptr = (Scaleform::GFx::ExternalLibPtrVtbl *)&Scaleform::GFx::ExternalLibPtr::`vftable;
}

