// File Line: 32
// RVA: 0x78EB00
void __fastcall Scaleform::GFx::AS3::Classes::UDBase::~UDBase(Scaleform::GFx::AS3::Classes::UDBase *this)
{
  Scaleform::GFx::AS3::Classes::UDBase *v1; // rbx

  v1 = this;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::UDBase::`vftable';
  Scaleform::GFx::AS3::Traits::DestructTail(
    (Scaleform::GFx::AS3::Traits *)((_QWORD)this->pTraits.pObject & 0xFFFFFFFFFFFFFFFEui64),
    (Scaleform::GFx::AS3::Object *)&this->vfptr);
  Scaleform::GFx::AS3::Class::~Class((Scaleform::GFx::AS3::Class *)&v1->vfptr);
}

// File Line: 37
// RVA: 0x807D90
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Classes::UDBase::PreInit(Scaleform::GFx::AS3::Classes::UDBase *this, Scaleform::GFx::AS3::CheckResult *result, Scaleform::GFx::AS3::Value *_this)
{
  Scaleform::GFx::AS3::CheckResult *v3; // rbx

  v3 = result;
  (*((void (__fastcall **)(Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *, Scaleform::GFx::AS3::CheckResult *, _QWORD))this->pTraits.pObject[1].vfptr->ForEachChild_GC
   + 8))(
    this->pTraits.pObject[1].vfptr,
    result,
    *(_QWORD *)&_this->value.VNumber);
  return v3;
}

// File Line: 43
// RVA: 0x7F4DA0
void __fastcall Scaleform::GFx::AS3::Classes::UDBase::InitPrototype(Scaleform::GFx::AS3::Classes::UDBase *this, Scaleform::GFx::AS3::Object *obj)
{
  Scaleform::GFx::AS3::Class::AddConstructor((Scaleform::GFx::AS3::Class *)&this->vfptr, obj);
}

