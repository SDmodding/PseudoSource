// File Line: 89
// RVA: 0x825BE0
Scaleform::GFx::AvmSpriteBase *__fastcall Scaleform::GFx::AS3::AvmSprite::ToAvmSpriteBase(Scaleform::GFx::AS3::AvmSprite *this)
{
  Scaleform::GFx::AvmSpriteBase *result; // rax

  if ( this )
    result = (Scaleform::GFx::AvmSpriteBase *)&this->vfptr;
  else
    result = 0i64;
  return result;
}

// File Line: 161
// RVA: 0x7E77D0
const char *__fastcall Scaleform::GFx::AS3::AvmSprite::GetDefaultASClassName(Scaleform::GFx::AS3::AvmSprite *this)
{
  return "flash.display.Sprite";
}

// File Line: 188
// RVA: 0x7F08B0
signed __int64 __fastcall Scaleform::GFx::AS3::AvmSprite::GetTopMostEntity(Scaleform::GFx::AS3::AvmSprite *this, Scaleform::Render::Point<float> *localPt, Scaleform::GFx::DisplayObjectBase::TopMostDescr *pdescr, Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *hitTest)
{
  return Scaleform::GFx::AS3::AvmDisplayObjContainer::GetTopMostEntity(
           (Scaleform::GFx::AS3::AvmDisplayObjContainer *)&this->vfptr,
           localPt,
           pdescr,
           hitTest);
}

// File Line: 192
// RVA: 0x7D1860
void __fastcall Scaleform::GFx::AS3::AvmSprite::FillTabableArray(Scaleform::GFx::AS3::AvmSprite *this, Scaleform::GFx::InteractiveObject::FillTabableParams *params)
{
  Scaleform::GFx::AS3::AvmDisplayObjContainer::FillTabableArray(
    (Scaleform::GFx::AS3::AvmDisplayObjContainer *)&this->vfptr,
    params);
}

// File Line: 267
// RVA: 0x8948E0
void __fastcall Scaleform::GFx::AS3::AvmMovieClip::AvmMovieClip(Scaleform::GFx::AS3::AvmMovieClip *this, Scaleform::GFx::Sprite *psprite)
{
  Scaleform::GFx::AS3::AvmMovieClip *v2; // rbx

  v2 = this;
  Scaleform::GFx::AS3::AvmSprite::AvmSprite((Scaleform::GFx::AS3::AvmSprite *)&this->vfptr, psprite);
  v2->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmMovieClip::`vftable{for `Scaleform::GFx::AS3::AvmDisplayObj};
  v2->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmMovieClip::`vftable{for `Scaleform::GFx::AvmInteractiveObjBase};
  v2->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmMovieClip::`vftable{for `Scaleform::GFx::AS3::AvmDisplayObjContainer};
  v2->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmMovieClip::`vftable{for `Scaleform::GFx::AvmSpriteBase};
}

// File Line: 270
// RVA: 0x7E77C0
const char *__fastcall Scaleform::GFx::AS3::AvmMovieClip::GetDefaultASClassName(Scaleform::GFx::AS3::AvmMovieClip *this)
{
  return "flash.display.MovieClip";
}

