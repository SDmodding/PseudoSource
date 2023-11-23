// File Line: 39
// RVA: 0x89E7B0
void __fastcall Scaleform::Render::Text::TextFilter::TextFilter(Scaleform::Render::Text::TextFilter *this)
{
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImpl::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,74>::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseNTS<Scaleform::Render::Text::TextFilter,74>::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::Render::Text::TextFilter::`vftable;
  this->ShadowParams.Mode = 0;
  this->ShadowParams.Passes = 1;
  this->ShadowParams.BlurX = 100.0;
  *(_QWORD *)&this->ShadowParams.BlurY = 1120403456i64;
  this->ShadowParams.Offset.y = 0.0;
  this->ShadowParams.Strength = 1.0;
  this->ShadowParams.Gradient.pObject = 0i64;
  *(_DWORD *)&this->ShadowParams.Colors[0].Channels.Green = 16711680;
  this->ShadowParams.Colors[0].Channels.Blue = 0;
  *(_WORD *)&this->ShadowParams.Colors[1].Channels.Green = 0;
  this->ShadowParams.Colors[1].Channels.Alpha = 0;
  Scaleform::Render::Text::TextFilter::SetDefaultShadow(this);
}

