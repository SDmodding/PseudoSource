// File Line: 51
// RVA: 0x6C9F70
void __fastcall Scaleform::GFx::AS2::LoadVarsObject::LoadVarsObject(Scaleform::GFx::AS2::LoadVarsObject *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::AS2::Object *pprototype)
{
  Scaleform::GFx::AS2::Object *v3; // rbx
  Scaleform::GFx::AS2::ASStringContext *v4; // rdi
  Scaleform::GFx::AS2::LoadVarsObject *v5; // rsi

  v3 = pprototype;
  v4 = psc;
  v5 = this;
  Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)&this->vfptr, psc);
  v5->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::LoadVarsObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v5->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::LoadVarsObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  Scaleform::GFx::AS2::Object::Set__proto__((Scaleform::GFx::AS2::Object *)&v5->vfptr, v4, v3);
  v5->BytesLoadedCurrent = -1.0;
  v5->BytesLoadedTotal = -1.0;
}

// File Line: 58
// RVA: 0x6F4680
signed __int64 __fastcall Scaleform::GFx::AS2::LoadVarsObject::GetObjectType(SSConcurrentBranch *this)
{
  return 27i64;
}

