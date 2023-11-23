// File Line: 50
// RVA: 0x8A4320
void __fastcall Scaleform::Render::Text::EditorKitBase::~EditorKitBase(Scaleform::Render::Text::EditorKitBase *this)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Text::EditorKitBase::`vftable;
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}

// File Line: 240
// RVA: 0x8C7FF0
__int64 __fastcall Scaleform::Render::Text::DocView::DocumentListener::Editor_OnCharacter(
        Scaleform::Render::Text::DocView::DocumentListener *this,
        Scaleform::Render::Text::EditorKitBase *__formal,
        wchar_t srcChar)
{
  return srcChar;
}

// File Line: 248
// RVA: 0x8D6230
Scaleform::String *__fastcall Scaleform::GFx::ResourceReport::GetResourceName(
        Scaleform::GFx::ResourceReport *this,
        Scaleform::String *result)
{
  Scaleform::String::String(result);
  return result;
}

// File Line: 543
// RVA: 0x9AEE70
void __fastcall Scaleform::Render::Text::DocView::SetDefaultShadow(Scaleform::Render::Text::DocView *this)
{
  float v2; // xmm8_4
  float v3; // xmm0_4

  this->Filter.BlurStrength = 1.0;
  *(_QWORD *)&this->Filter.ShadowParams.Strength = 1065353216i64;
  *(_QWORD *)&this->Filter.BlurX = 0i64;
  this->Filter.ShadowParams.Mode = 0;
  *(_QWORD *)&this->Filter.ShadowParams.BlurX = 0i64;
  this->Filter.ShadowFlags = 128;
  this->Filter.ShadowAlpha = -1;
  this->Filter.ShadowAngle = 0.78539819;
  this->Filter.ShadowDistance = 4.0;
  v2 = cosf(0.78539819);
  v3 = sinf(0.78539819);
  this->Filter.ShadowParams.Offset.x = v2 * 4.0;
  this->Filter.ShadowParams.Offset.y = v3 * 4.0;
}

