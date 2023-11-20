// File Line: 39
// RVA: 0x89E7B0
void __fastcall Scaleform::Render::Text::TextFilter::TextFilter(Scaleform::Render::Text::TextFilter *this)
{
  Scaleform::Render::BlurFilterParams *v1; // [rsp+48h] [rbp+10h]

  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImpl::`vftable';
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,74>::`vftable';
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseNTS<Scaleform::Render::Text::TextFilter,74>::`vftable';
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::Render::Text::TextFilter::`vftable';
  v1 = &this->ShadowParams;
  v1->Mode = 0;
  v1->Passes = 1;
  v1->BlurX = 100.0;
  *(_QWORD *)&v1->BlurY = 1120403456i64;
  v1->Offset.y = 0.0;
  v1->Strength = 1.0;
  v1->Gradient.pObject = 0i64;
  *(_DWORD *)&v1->Colors[0].Channels.Green = 16711680;
  v1->Colors[0].Channels.Blue = 0;
  *(_WORD *)&v1->Colors[1].Channels.Green = 0;
  v1->Colors[1].Channels.Alpha = 0;
  Scaleform::Render::Text::TextFilter::SetDefaultShadow(this);
}

