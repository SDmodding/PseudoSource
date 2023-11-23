// File Line: 144
// RVA: 0x8E9DF0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_utils::Dictionary> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_utils::Dictionary::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_utils::Dictionary> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_utils::Dictionary *t)
{
  Scaleform::GFx::AS3::Instances::fl::Object *v4; // rax
  Scaleform::GFx::AS3::Instances::fl_utils::Dictionary *v5; // rbx

  v4 = (Scaleform::GFx::AS3::Instances::fl::Object *)Scaleform::GFx::AS3::Traits::Alloc(t);
  v5 = (Scaleform::GFx::AS3::Instances::fl_utils::Dictionary *)v4;
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instances::fl::Object::Object(v4, t);
    v5->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_utils::Dictionary::`vftable;
    v5->WeakKeys = 0;
    v5->ValueH.mHash.pTable = 0i64;
  }
  else
  {
    v5 = 0i64;
  }
  result->pV = v5;
  return result;
}

// File Line: 156
// RVA: 0x8E9E70
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_utils::Dictionary> *__fastcall Scaleform::GFx::AS3::InstanceTraits::fl_utils::Dictionary::MakeInstance(
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_utils::Dictionary> *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_utils::Dictionary *t,
        bool weakKeys)
{
  Scaleform::GFx::AS3::Instances::fl::Object *v6; // rax
  Scaleform::GFx::AS3::Instances::fl_utils::Dictionary *v7; // rbx

  v6 = (Scaleform::GFx::AS3::Instances::fl::Object *)Scaleform::GFx::AS3::Traits::Alloc(t);
  v7 = (Scaleform::GFx::AS3::Instances::fl_utils::Dictionary *)v6;
  if ( v6 )
  {
    Scaleform::GFx::AS3::Instances::fl::Object::Object(v6, t);
    v7->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_utils::Dictionary::`vftable;
    v7->WeakKeys = weakKeys;
    v7->ValueH.mHash.pTable = 0i64;
  }
  else
  {
    v7 = 0i64;
  }
  result->pV = v7;
  return result;
}

