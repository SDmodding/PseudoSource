// File Line: 74
// RVA: 0x94C010
void __fastcall Scaleform::Render::ProfileModifier::~ProfileModifier(Scaleform::Render::ProfileModifier *this)
{
  this->vfptr = (Scaleform::Render::ProfileModifierVtbl *)&Scaleform::Render::ProfileModifier::`vftable';
}

// File Line: 75
// RVA: 0x981600
Scaleform::Render::Color *__fastcall Scaleform::Render::ProfileModifier::GetClearColor(Scaleform::Render::ProfileModifier *this, Scaleform::Render::Color *result, Scaleform::Render::DrawModeType __formal, __int64 color)
{
  *result = *(Scaleform::Render::Color *)color;
  return result;
}

// File Line: 76
// RVA: 0x984190
__int64 __fastcall Scaleform::Render::ProfileModifier::GetBlendMode(hkLifoAllocator *this, const void *obj, int nbytes)
{
  return (unsigned int)nbytes;
}

// File Line: 80
// RVA: 0x981F60
Scaleform::Render::Cxform *__fastcall Scaleform::Render::ProfileModifier::GetCxform(Scaleform::Render::ProfileModifier *this, Scaleform::Render::Cxform *result, Scaleform::Render::DrawModeType __formal, Scaleform::Render::Cxform *cx)
{
  __int128 v4; // xmm1
  Scaleform::Render::Cxform *v5; // rax

  v4 = *(_OWORD *)&cx->M[1][0];
  v5 = result;
  *(_OWORD *)&result->M[0][0] = *(_OWORD *)&cx->M[0][0];
  *(_OWORD *)&result->M[1][0] = v4;
  return v5;
}

// File Line: 81
// RVA: 0x9AF2F0
void __fastcall Scaleform::Render::ProfileModifier::SetFillFlags(Scaleform::Render::ProfileModifier *this, Scaleform::Render::DrawModeType __formal, unsigned int flags)
{
  this->FillFlags = flags;
}

// File Line: 167
// RVA: 0x94C020
void __fastcall Scaleform::Render::ProfileViews::~ProfileViews(Scaleform::Render::ProfileViews *this)
{
  this->vfptr = (Scaleform::Render::ProfileViewsVtbl *)&Scaleform::Render::ProfileViews::`vftable';
  this->PMDefault.vfptr = (Scaleform::Render::ProfileModifierVtbl *)&Scaleform::Render::ProfileModifier::`vftable';
}

// File Line: 246
// RVA: 0x981B20
ASymbol *__fastcall Scaleform::Render::GlyphCache::GetParams(SSClass *this)
{
  return &this->i_name;
}

// File Line: 247
// RVA: 0x981610
Scaleform::Render::Color *__fastcall Scaleform::Render::ProfileViews::GetColor(Scaleform::Render::ProfileViews *this, Scaleform::Render::Color *result, __int64 color)
{
  *result = *(Scaleform::Render::Color *)color;
  return result;
}

// File Line: 252
// RVA: 0x981F80
Scaleform::Render::Cxform *__fastcall Scaleform::Render::ProfileViews::GetCxform(Scaleform::Render::ProfileViews *this, Scaleform::Render::Cxform *result, Scaleform::Render::Cxform *cx)
{
  __int128 v3; // xmm1
  Scaleform::Render::Cxform *v4; // rax

  v3 = *(_OWORD *)&cx->M[1][0];
  v4 = result;
  *(_OWORD *)&result->M[0][0] = *(_OWORD *)&cx->M[0][0];
  *(_OWORD *)&result->M[1][0] = v3;
  return v4;
}

