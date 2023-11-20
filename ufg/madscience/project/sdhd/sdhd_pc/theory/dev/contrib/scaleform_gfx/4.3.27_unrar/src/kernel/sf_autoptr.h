// File Line: 41
// RVA: 0x786860
void __fastcall Scaleform::AutoPtr<Scaleform::GFx::AS3::VTable>::~AutoPtr<Scaleform::GFx::AS3::VTable>(Scaleform::AutoPtr<Scaleform::GFx::AS3::VTable> *this)
{
  Scaleform::AutoPtr<Scaleform::GFx::AS3::VTable> *v1; // rbx
  Scaleform::GFx::AS3::VTable *v2; // rcx

  v1 = this;
  v2 = this->pObject;
  if ( v2 )
  {
    if ( v1->Owner )
    {
      v1->Owner = 0;
      Scaleform::GFx::AS3::VTable::`scalar deleting destructor(v2, 1u);
    }
    v1->pObject = 0i64;
  }
  v1->Owner = 0;
}

// File Line: 44
// RVA: 0x790400
Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> > *__fastcall Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy>>::operator=(Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> > *this, Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> > *p)
{
  Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> > *v2; // rbx
  bool v3; // bp
  Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> *v4; // rsi
  Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> *v5; // rdi

  v2 = this;
  if ( this != p )
  {
    v3 = p->Owner;
    p->Owner = 0;
    v4 = p->pObject;
    v5 = this->pObject;
    if ( this->pObject != p->pObject )
    {
      if ( v5 && this->Owner )
      {
        this->Owner = 0;
        Scaleform::ArrayDataBase<Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> *)&v5->Data.Data);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v5);
      }
      v2->pObject = v4;
    }
    v2->Owner = v3;
  }
  return v2;
}

// File Line: 55
// RVA: 0x790380
Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *,2,Scaleform::ArrayDefaultPolicy> > *__fastcall Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Accelerometer *,2,Scaleform::ArrayDefaultPolicy>>::operator=(Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *,2,Scaleform::ArrayDefaultPolicy> > *this, Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *,2,Scaleform::ArrayDefaultPolicy> *p)
{
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *,2,Scaleform::ArrayDefaultPolicy> *v2; // rsi
  Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *,2,Scaleform::ArrayDefaultPolicy> > *v3; // rbx
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_sensors::Geolocation *,2,Scaleform::ArrayDefaultPolicy> *v4; // rdi

  v2 = p;
  v3 = this;
  v4 = this->pObject;
  if ( this->pObject != p )
  {
    if ( v4 && this->Owner )
    {
      this->Owner = 0;
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v4->Data.Data);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v4);
    }
    v3->pObject = v2;
  }
  v3->Owner = v2 != 0i64;
  return v3;
}

// File Line: 105
// RVA: 0x6D09D0
void __fastcall Scaleform::ScopePtr<Scaleform::ArrayCC<Scaleform::GFx::ASString,323,Scaleform::ArrayDefaultPolicy>>::~ScopePtr<Scaleform::ArrayCC<Scaleform::GFx::ASString,323,Scaleform::ArrayDefaultPolicy>>(Scaleform::ScopePtr<Scaleform::ArrayCC<Scaleform::GFx::ASString,323,Scaleform::ArrayDefaultPolicy> > *this)
{
  Scaleform::ArrayCC<Scaleform::GFx::ASString,323,Scaleform::ArrayDefaultPolicy> *v1; // rbx

  v1 = this->pObject;
  if ( this->pObject )
  {
    Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::~ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>(&v1->Data);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1);
  }
}

