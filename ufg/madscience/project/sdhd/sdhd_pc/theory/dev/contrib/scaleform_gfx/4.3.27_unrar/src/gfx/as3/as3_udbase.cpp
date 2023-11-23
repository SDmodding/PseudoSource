// File Line: 32
// RVA: 0x78EB00
void __fastcall Scaleform::GFx::AS3::Classes::UDBase::~UDBase(Scaleform::GFx::AS3::Classes::UDBase *this)
{
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::UDBase::`vftable;
  Scaleform::GFx::AS3::Traits::DestructTail(
    (Scaleform::GFx::AS3::Traits *)((unsigned __int64)this->pTraits.pObject & 0xFFFFFFFFFFFFFFFEui64),
    this);
  Scaleform::GFx::AS3::Class::~Class(this);
}

// File Line: 37
// RVA: 0x807D90
Scaleform::GFx::AS3::CheckResult *__fastcall Scaleform::GFx::AS3::Classes::UDBase::PreInit(
        Scaleform::GFx::AS3::Classes::UDBase *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Value *_this)
{
  (*((void (__fastcall **)(Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *, Scaleform::GFx::AS3::CheckResult *, Scaleform::GFx::AS3::Value::V1U))this->pTraits.pObject[1].vfptr->ForEachChild_GC
   + 8))(
    this->pTraits.pObject[1].vfptr,
    result,
    _this->value.VS._1);
  return result;
}

// File Line: 43
// RVA: 0x7F4DA0
// attributes: thunk
void __fastcall Scaleform::GFx::AS3::Classes::UDBase::InitPrototype(
        Scaleform::GFx::AS3::Classes::UDBase *this,
        Scaleform::GFx::AS3::Object *obj)
{
  Scaleform::GFx::AS3::Class::AddConstructor(this, obj);
}

