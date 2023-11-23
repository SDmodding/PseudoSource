// File Line: 89
// RVA: 0x825BE0
Scaleform::GFx::AvmSpriteBase *__fastcall Scaleform::GFx::AS3::AvmSprite::ToAvmSpriteBase(
        Scaleform::GFx::AS3::AvmSprite *this)
{
  if ( this )
    return &this->Scaleform::GFx::AvmSpriteBase;
  else
    return 0i64;
}

// File Line: 161
// RVA: 0x7E77D0
const char *__fastcall Scaleform::GFx::AS3::AvmSprite::GetDefaultASClassName(Scaleform::GFx::AS3::AvmSprite *this)
{
  return "flash.display.Sprite";
}

// File Line: 188
// RVA: 0x7F08B0
// attributes: thunk
__int64 __fastcall Scaleform::GFx::AS3::AvmSprite::GetTopMostEntity(
        Scaleform::GFx::AS3::AvmSprite *this,
        Scaleform::Render::Point<float> *localPt,
        Scaleform::GFx::DisplayObjectBase::TopMostDescr *pdescr,
        Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *hitTest)
{
  return Scaleform::GFx::AS3::AvmDisplayObjContainer::GetTopMostEntity(this, localPt, pdescr, hitTest);
}

// File Line: 192
// RVA: 0x7D1860
// attributes: thunk
void __fastcall Scaleform::GFx::AS3::AvmSprite::FillTabableArray(
        Scaleform::GFx::AS3::AvmSprite *this,
        Scaleform::GFx::InteractiveObject::FillTabableParams *params)
{
  Scaleform::GFx::AS3::AvmDisplayObjContainer::FillTabableArray(this, params);
}

// File Line: 267
// RVA: 0x8948E0
void __fastcall Scaleform::GFx::AS3::AvmMovieClip::AvmMovieClip(
        Scaleform::GFx::AS3::AvmMovieClip *this,
        Scaleform::GFx::Sprite *psprite)
{
  Scaleform::GFx::AS3::AvmSprite::AvmSprite(this, psprite);
  this->Scaleform::GFx::AS3::AvmSprite::Scaleform::GFx::AS3::AvmDisplayObjContainer::Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AS3::AvmDisplayObj::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmMovieClip::`vftable{for `Scaleform::GFx::AS3::AvmDisplayObj};
  this->Scaleform::GFx::AS3::AvmSprite::Scaleform::GFx::AS3::AvmDisplayObjContainer::Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmMovieClip::`vftable{for `Scaleform::GFx::AvmInteractiveObjBase};
  this->Scaleform::GFx::AS3::AvmSprite::Scaleform::GFx::AS3::AvmDisplayObjContainer::Scaleform::GFx::AvmDisplayObjContainerBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmMovieClip::`vftable{for `Scaleform::GFx::AS3::AvmDisplayObjContainer};
  this->Scaleform::GFx::AS3::AvmSprite::Scaleform::GFx::AvmSpriteBase::Scaleform::GFx::AvmDisplayObjContainerBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmMovieClip::`vftable{for `Scaleform::GFx::AvmSpriteBase};
}

// File Line: 270
// RVA: 0x7E77C0
const char *__fastcall Scaleform::GFx::AS3::AvmMovieClip::GetDefaultASClassName(
        Scaleform::GFx::AS3::AvmMovieClip *this)
{
  return "flash.display.MovieClip";
}

