// File Line: 62
// RVA: 0x6C8060
void __fastcall Scaleform::GFx::AS2::ColorTransformObject::ColorTransformObject(Scaleform::GFx::AS2::ColorTransformObject *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::AS2::Object *pprototype)
{
  Scaleform::GFx::AS2::Object *v3; // rdi
  Scaleform::GFx::AS2::ASStringContext *v4; // rsi
  Scaleform::GFx::AS2::ColorTransformObject *v5; // r14

  v3 = pprototype;
  v4 = psc;
  v5 = this;
  Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)&this->vfptr, psc);
  v5->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ColorTransformObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  v5->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ColorTransformObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  Scaleform::Render::Cxform::Cxform(&v5->mColorTransform);
  Scaleform::GFx::AS2::Object::Set__proto__((Scaleform::GFx::AS2::Object *)&v5->vfptr, v4, v3);
}

