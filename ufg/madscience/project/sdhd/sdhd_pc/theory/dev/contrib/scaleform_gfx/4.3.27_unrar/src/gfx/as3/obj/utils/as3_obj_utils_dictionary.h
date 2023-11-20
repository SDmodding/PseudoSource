// File Line: 144
// RVA: 0x8E9DF0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_utils::Dictionary> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_utils::Dictionary::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_utils::Dictionary> *result, Scaleform::GFx::AS3::InstanceTraits::fl_utils::Dictionary *t)
{
  Scaleform::GFx::AS3::InstanceTraits::fl_utils::Dictionary *v2; // rsi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_utils::Dictionary> *v3; // rdi
  Scaleform::GFx::AS3::Instances::fl::Object *v4; // rax
  Scaleform::GFx::AS3::Instances::fl_utils::Dictionary *v5; // rbx

  v2 = t;
  v3 = result;
  v4 = (Scaleform::GFx::AS3::Instances::fl::Object *)Scaleform::GFx::AS3::Traits::Alloc((Scaleform::GFx::AS3::Traits *)&t->vfptr);
  v5 = (Scaleform::GFx::AS3::Instances::fl_utils::Dictionary *)v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instances::fl::Object::Object(v4, (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v2->vfptr);
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_utils::Dictionary::`vftable;
    v5->WeakKeys = 0;
    v5->ValueH.mHash.pTable = 0i64;
  }
  else
  {
    v5 = 0i64;
  }
  v3->pV = v5;
  return v3;
}

// File Line: 156
// RVA: 0x8E9E70
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_utils::Dictionary> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_utils::Dictionary::MakeInstance(Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_utils::Dictionary> *result, Scaleform::GFx::AS3::InstanceTraits::fl_utils::Dictionary *t, bool weakKeys)
{
  bool v3; // bp
  Scaleform::GFx::AS3::InstanceTraits::fl_utils::Dictionary *v4; // rsi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_utils::Dictionary> *v5; // rdi
  Scaleform::GFx::AS3::Instances::fl::Object *v6; // rax
  Scaleform::GFx::AS3::Instances::fl_utils::Dictionary *v7; // rbx

  v3 = weakKeys;
  v4 = t;
  v5 = result;
  v6 = (Scaleform::GFx::AS3::Instances::fl::Object *)Scaleform::GFx::AS3::Traits::Alloc((Scaleform::GFx::AS3::Traits *)&t->vfptr);
  v7 = (Scaleform::GFx::AS3::Instances::fl_utils::Dictionary *)v6;
  if ( v6 )
  {
    Scaleform::GFx::AS3::Instances::fl::Object::Object(v6, (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v4->vfptr);
    v7->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_utils::Dictionary::`vftable;
    v7->WeakKeys = v3;
    v7->ValueH.mHash.pTable = 0i64;
  }
  else
  {
    v7 = 0i64;
  }
  v5->pV = v7;
  return v5;
}

