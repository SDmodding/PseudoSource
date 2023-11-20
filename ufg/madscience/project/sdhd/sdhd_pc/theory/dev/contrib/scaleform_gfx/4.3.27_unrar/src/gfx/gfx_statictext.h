// File Line: 73
// RVA: 0x8B59D0
void __fastcall Scaleform::GFx::StaticTextCharacter::AdvanceFrame(Scaleform::GFx::StaticTextCharacter *this, bool nextFrame, float framePos)
{
  if ( nextFrame )
    this->Flags |= 2u;
  else
    this->Flags &= 0xFDu;
}

// File Line: 87
// RVA: 0x90CBF0
void __fastcall Scaleform::GFx::StaticTextCharacter::SetTextFilters(Scaleform::GFx::StaticTextCharacter *this, Scaleform::Render::Text::TextFilter *f)
{
  Scaleform::Render::Text::TextFilter *v2; // rbx
  Scaleform::GFx::StaticTextCharacter *v3; // rdi
  Scaleform::Render::BlurFilterParams *v4; // rcx

  v2 = f;
  v3 = this;
  this->Filter.BlurX = f->BlurX;
  v4 = &this->Filter.ShadowParams;
  v4[-1].Colors[2].Raw = LODWORD(f->BlurY);
  *(float *)&v4[-1].Gradient.pObject = f->BlurStrength;
  Scaleform::Render::BlurFilterParams::operator=(v4, &f->ShadowParams);
  v3->Filter.ShadowFlags = v2->ShadowFlags;
  v3->Filter.ShadowAngle = v2->ShadowAngle;
  v3->Filter.ShadowDistance = v2->ShadowDistance;
  v3->Filter.ShadowAlpha = v2->ShadowAlpha;
  Scaleform::GFx::StaticTextCharacter::RecreateVisibleTextLayout(v3);
}

// File Line: 104
// RVA: 0x8D6210
Scaleform::GFx::StaticTextDef *__fastcall Scaleform::GFx::StaticTextCharacter::GetCharacterDef(Scaleform::GFx::StaticTextCharacter *this)
{
  return this->pDef.pObject;
}

// File Line: 112
// RVA: 0x8D53B0
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::StaticTextCharacter::GetBounds(Scaleform::GFx::StaticTextCharacter *this, Scaleform::Render::Rect<float> *result, Scaleform::Render::Matrix2x4<float> *transform)
{
  Scaleform::Render::Rect<float> *v3; // rdi
  Scaleform::Render::Matrix2x4<float> *v4; // rbx
  Scaleform::Render::Rect<float> *v5; // rax
  char v7; // [rsp+20h] [rbp-18h]

  v3 = result;
  v4 = transform;
  v5 = (Scaleform::Render::Rect<float> *)((__int64 (__fastcall *)(Scaleform::GFx::StaticTextDef *, char *))this->pDef.pObject->vfptr[1].GetResourceReport)(
                                           this->pDef.pObject,
                                           &v7);
  Scaleform::Render::Matrix2x4<float>::EncloseTransform(v4, v3, v5);
  return v3;
}

// File Line: 117
// RVA: 0x8DD4A0
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::StaticTextCharacter::GetRectBounds(Scaleform::GFx::StaticTextCharacter *this, Scaleform::Render::Rect<float> *result, Scaleform::Render::Matrix2x4<float> *transform)
{
  Scaleform::Render::Rect<float> *v3; // rdi
  Scaleform::Render::Matrix2x4<float> *v4; // rbx
  Scaleform::Render::Rect<float> *v5; // rax
  char v7; // [rsp+20h] [rbp-18h]

  v3 = result;
  v4 = transform;
  v5 = (Scaleform::Render::Rect<float> *)this->pDef.pObject->vfptr[2].__vecDelDtor(
                                           (Scaleform::GFx::Resource *)this->pDef.pObject,
                                           (unsigned int)&v7);
  Scaleform::Render::Matrix2x4<float>::EncloseTransform(v4, v3, v5);
  return v3;
}

// File Line: 122
// RVA: 0x8F0840
__int64 __fastcall Scaleform::GFx::StaticTextCharacter::PointTestLocal(Scaleform::GFx::StaticTextCharacter *this, Scaleform::Render::Point<float> *pt, __int64 hitTestMask)
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
__int64 __fastcall Scaleform::GFx::StaticTextCharacter::GetTopMostMouseEntity(Scaleform::GFx::StaticTextCharacter *this, Scaleform::Render::Point<float> *pt, Scaleform::GFx::DisplayObjectBase::TopMostDescr *pdescr)
{
  Scaleform::GFx::DisplayObjectBase::TopMostDescr *v3; // rbx
  Scaleform::GFx::InteractiveObject *v4; // rax

  v3 = pdescr;
  v4 = Scaleform::GFx::DisplayObjectBase::GetTopMostMouseEntityDef(
         (Scaleform::GFx::DisplayObjectBase *)&this->vfptr,
         (Scaleform::GFx::CharacterDef *)&this->pDef.pObject->vfptr,
         pt,
         pdescr->TestAll,
         pdescr->pIgnoreMC);
  v3->pResult = v4;
  return 2 - (unsigned int)(v4 != 0i64);
}

