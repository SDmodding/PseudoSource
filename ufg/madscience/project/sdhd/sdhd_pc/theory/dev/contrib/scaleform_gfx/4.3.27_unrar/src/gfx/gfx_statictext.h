// File Line: 73
// RVA: 0x8B59D0
void __fastcall Scaleform::GFx::StaticTextCharacter::AdvanceFrame(
        Scaleform::GFx::StaticTextCharacter *this,
        bool nextFrame,
        float framePos)
{
  if ( nextFrame )
    this->Flags |= 2u;
  else
    this->Flags &= ~2u;
}

// File Line: 87
// RVA: 0x90CBF0
void __fastcall Scaleform::GFx::StaticTextCharacter::SetTextFilters(
        Scaleform::GFx::StaticTextCharacter *this,
        Scaleform::Render::Text::TextFilter *f)
{
  Scaleform::Render::BlurFilterParams *p_ShadowParams; // rcx

  this->Filter.BlurX = f->BlurX;
  p_ShadowParams = &this->Filter.ShadowParams;
  p_ShadowParams[-1].Colors[2].Raw = LODWORD(f->BlurY);
  *(float *)&p_ShadowParams[-1].Gradient.pObject = f->BlurStrength;
  Scaleform::Render::BlurFilterParams::operator=(p_ShadowParams, &f->ShadowParams);
  this->Filter.ShadowFlags = f->ShadowFlags;
  this->Filter.ShadowAngle = f->ShadowAngle;
  this->Filter.ShadowDistance = f->ShadowDistance;
  this->Filter.ShadowAlpha = f->ShadowAlpha;
  Scaleform::GFx::StaticTextCharacter::RecreateVisibleTextLayout(this);
}

// File Line: 104
// RVA: 0x8D6210
Scaleform::GFx::StaticTextDef *__fastcall Scaleform::GFx::StaticTextCharacter::GetCharacterDef(
        Scaleform::GFx::StaticTextCharacter *this)
{
  return this->pDef.pObject;
}

// File Line: 112
// RVA: 0x8D53B0
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::StaticTextCharacter::GetBounds(
        Scaleform::GFx::StaticTextCharacter *this,
        Scaleform::Render::Rect<float> *result,
        Scaleform::Render::Matrix2x4<float> *transform)
{
  Scaleform::Render::Rect<float> *v5; // rax
  char v7[24]; // [rsp+20h] [rbp-18h] BYREF

  v5 = (Scaleform::Render::Rect<float> *)((__int64 (__fastcall *)(Scaleform::GFx::StaticTextDef *, char *))this->pDef.pObject->vfptr[1].GetResourceReport)(
                                           this->pDef.pObject,
                                           v7);
  Scaleform::Render::Matrix2x4<float>::EncloseTransform(transform, result, v5);
  return result;
}

// File Line: 117
// RVA: 0x8DD4A0
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::StaticTextCharacter::GetRectBounds(
        Scaleform::GFx::StaticTextCharacter *this,
        Scaleform::Render::Rect<float> *result,
        Scaleform::Render::Matrix2x4<float> *transform)
{
  Scaleform::Render::Rect<float> *v5; // rax
  char v7[24]; // [rsp+20h] [rbp-18h] BYREF

  v5 = (Scaleform::Render::Rect<float> *)this->pDef.pObject->vfptr[2].__vecDelDtor(this->pDef.pObject, v7);
  Scaleform::Render::Matrix2x4<float>::EncloseTransform(transform, result, v5);
  return result;
}

// File Line: 122
// RVA: 0x8F0840
__int64 __fastcall Scaleform::GFx::StaticTextCharacter::PointTestLocal(
        Scaleform::GFx::StaticTextCharacter *this,
        Scaleform::Render::Point<float> *pt,
        __int64 hitTestMask)
{
  LOBYTE(hitTestMask) = hitTestMask & 1;
  return ((__int64 (__fastcall *)(Scaleform::GFx::StaticTextDef *, Scaleform::Render::Point<float> *, __int64, Scaleform::GFx::StaticTextCharacter *))this->pDef.pObject->vfptr[1].GetResourceTypeCode)(
           this->pDef.pObject,
           pt,
           hitTestMask,
           this);
}

// File Line: 128
// RVA: 0x8E0570
__int64 __fastcall Scaleform::GFx::StaticTextCharacter::GetTopMostMouseEntity(
        Scaleform::GFx::StaticTextCharacter *this,
        Scaleform::Render::Point<float> *pt,
        Scaleform::GFx::DisplayObjectBase::TopMostDescr *pdescr)
{
  Scaleform::GFx::InteractiveObject *TopMostMouseEntityDef; // rax

  TopMostMouseEntityDef = Scaleform::GFx::DisplayObjectBase::GetTopMostMouseEntityDef(
                            this,
                            this->pDef.pObject,
                            pt,
                            pdescr->TestAll,
                            pdescr->pIgnoreMC);
  pdescr->pResult = TopMostMouseEntityDef;
  return 2 - (unsigned int)(TopMostMouseEntityDef != 0i64);
}

