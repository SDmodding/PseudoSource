// File Line: 41
// RVA: 0x786860
void __fastcall Scaleform::AutoPtr<Scaleform::GFx::AS3::VTable>::~AutoPtr<Scaleform::GFx::AS3::VTable>(
        Scaleform::AutoPtr<Scaleform::GFx::AS3::VTable> *this)
{
  Scaleform::GFx::AS3::VTable *pObject; // rcx

  pObject = this->pObject;
  if ( pObject )
  {
    if ( this->Owner )
    {
      this->Owner = 0;
      Scaleform::GFx::AS3::VTable::`scalar deleting destructor(pObject, 1u);
    }
    this->pObject = 0i64;
  }
  this->Owner = 0;
}

// File Line: 44
// RVA: 0x790400
Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> > *__fastcall Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>::operator=(
        Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> > *this,
        Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> > *p)
{
  bool Owner; // bp
  Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> *pObject; // rsi
  Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> *v5; // rdi

  if ( this != p )
  {
    Owner = p->Owner;
    p->Owner = 0;
    pObject = p->pObject;
    v5 = this->pObject;
    if ( this->pObject != p->pObject )
    {
      if ( v5 && this->Owner )
      {
        this->Owner = 0;
        Scaleform::ArrayDataBase<Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>,2>,Scaleform::ArrayDefaultPolicy>(&v5->Data);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v5);
      }
      this->pObject = pObject;
    }
    this->Owner = Owner;
  }
  return this;
}

// File Line: 55
// RVA: 0x790380
Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *,2,Scaleform::ArrayDefaultPolicy> > *__fastcall Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer *,2,Scaleform::ArrayDefaultPolicy>>::operator=(
        Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *,2,Scaleform::ArrayDefaultPolicy> > *this,
        Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *,2,Scaleform::ArrayDefaultPolicy> *p)
{
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *,2,Scaleform::ArrayDefaultPolicy> *pObject; // rdi

  pObject = this->pObject;
  if ( this->pObject != p )
  {
    if ( pObject && this->Owner )
    {
      this->Owner = 0;
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pObject->Data.Data);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pObject);
    }
    this->pObject = p;
  }
  this->Owner = p != 0i64;
  return this;
}

// File Line: 105
// RVA: 0x6D09D0
void __fastcall Scaleform::ScopePtr<Scaleform::ArrayCC<Scaleform::GFx::ASString,323,Scaleform::ArrayDefaultPolicy>>::~ScopePtr<Scaleform::ArrayCC<Scaleform::GFx::ASString,323,Scaleform::ArrayDefaultPolicy>>(
        Scaleform::ScopePtr<Scaleform::ArrayCC<Scaleform::GFx::ASString,323,Scaleform::ArrayDefaultPolicy> > *this)
{
  Scaleform::ArrayCC<Scaleform::GFx::ASString,323,Scaleform::ArrayDefaultPolicy> *pObject; // rbx

  pObject = this->pObject;
  if ( this->pObject )
  {
    Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::~ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>(&pObject->Data);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pObject);
  }
}

