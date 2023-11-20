// File Line: 76
// RVA: 0x77B740
void __fastcall Scaleform::Render::BlurFilterImpl::BlurFilterImpl(Scaleform::Render::BlurFilterImpl *this, Scaleform::Render::FilterType type)
{
  Scaleform::Render::BlurFilterParams *v2; // [rsp+30h] [rbp+18h]

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::Filter,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Filter::`vftable';
  this->Type = type;
  this->Frozen = 0;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::BlurFilterImpl::`vftable';
  v2 = &this->Params;
  v2->Mode = 0;
  v2->Passes = 1;
  v2->BlurX = 100.0;
  *(_QWORD *)&v2->BlurY = 1120403456i64;
  v2->Offset.y = 0.0;
  v2->Strength = 1.0;
  v2->Gradient.pObject = 0i64;
  *(_DWORD *)&this->Params.Colors[0].Channels.Green = 16711680;
  this->Params.Colors[0].Channels.Blue = 0;
  *(_WORD *)&this->Params.Colors[1].Channels.Green = 0;
  this->Params.Colors[1].Channels.Alpha = 0;
  *(_QWORD *)&this->Distance = 0i64;
  v2->Mode &= 0xFFFFFFF8;
  v2->Mode |= type;
}

// File Line: 83
// RVA: 0x894C40
void __fastcall Scaleform::Render::BlurFilterImpl::BlurFilterImpl(Scaleform::Render::BlurFilterImpl *this, Scaleform::Render::FilterType type, Scaleform::Render::BlurFilterParams *params)
{
  Scaleform::Render::BlurFilterImpl *v3; // rbx

  v3 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::Filter,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Filter::`vftable';
  this->Type = type;
  this->Frozen = 0;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::BlurFilterImpl::`vftable';
  Scaleform::Render::BlurFilterParams::BlurFilterParams(&this->Params, params);
  *(_QWORD *)&v3->Distance = 0i64;
}

// File Line: 134
// RVA: 0x77B5C0
void __fastcall Scaleform::Render::BlurFilter::BlurFilter(Scaleform::Render::BlurFilter *this, float blurx, float blury, unsigned int passes)
{
  Scaleform::Render::BlurFilterParams *v4; // ST08_8

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::Filter,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Filter::`vftable';
  this->Type = 0;
  this->Frozen = 0;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::BlurFilterImpl::`vftable';
  v4 = &this->Params;
  v4->Mode = 0;
  v4->Passes = 1;
  v4->BlurX = 100.0;
  *(_QWORD *)&v4->BlurY = 1120403456i64;
  v4->Offset.y = 0.0;
  v4->Strength = 1.0;
  v4->Gradient.pObject = 0i64;
  *(_DWORD *)&this->Params.Colors[0].Channels.Green = 16711680;
  this->Params.Colors[0].Channels.Blue = 0;
  *(_WORD *)&this->Params.Colors[1].Channels.Green = 0;
  this->Params.Colors[1].Channels.Alpha = 0;
  *(_QWORD *)&this->Distance = 0i64;
  v4->Mode &= 0xFFFFFFF8;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::BlurFilter::`vftable';
  this->Params.BlurX = blurx * 20.0;
  this->Params.BlurY = blury * 20.0;
  this->Params.Passes = passes;
}

// File Line: 162
// RVA: 0x781B90
void __fastcall Scaleform::Render::ShadowFilter::ShadowFilter(Scaleform::Render::ShadowFilter *this, float angle, float dist, float blurx, float blury, unsigned int passes)
{
  Scaleform::Render::ShadowFilter *v6; // rbx
  Scaleform::Render::BlurFilterParams *v7; // ST28_8
  float v8; // xmm6_4

  v6 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::Filter,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Filter::`vftable';
  this->Type = 1;
  this->Frozen = 0;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::BlurFilterImpl::`vftable';
  v7 = &this->Params;
  v7->Mode = 0;
  v7->Passes = 1;
  v7->BlurX = 100.0;
  *(_QWORD *)&v7->BlurY = 1120403456i64;
  v7->Offset.y = 0.0;
  v7->Strength = 1.0;
  v7->Gradient.pObject = 0i64;
  *(_DWORD *)&v7->Colors[0].Channels.Green = 16711680;
  v7->Colors[0].Channels.Blue = 0;
  *(_WORD *)&v7->Colors[1].Channels.Green = 0;
  v7->Colors[1].Channels.Alpha = 0;
  *(_QWORD *)&this->Distance = 0i64;
  v7->Mode &= 0xFFFFFFF9;
  v7->Mode |= 1u;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ShadowFilter::`vftable';
  this->Params.BlurX = blurx * 20.0;
  this->Params.BlurY = blury * 20.0;
  this->Params.Passes = passes;
  this->Angle = angle;
  this->Distance = dist * 20.0;
  v8 = sinf(angle) * (float)(dist * 20.0);
  v6->Params.Offset.x = cosf(angle) * (float)(dist * 20.0);
  v6->Params.Offset.y = v8;
  *(_WORD *)&v6->Params.Colors[0].Channels.Green = 0;
  v6->Params.Colors[0].Channels.Blue = 0;
  v6->Params.Colors[0].Channels.Alpha = -1;
}

// File Line: 172
// RVA: 0x89CBD0
void __fastcall Scaleform::Render::ShadowFilter::ShadowFilter(Scaleform::Render::ShadowFilter *this, Scaleform::Render::BlurFilterParams *params, float angle, float dist)
{
  Scaleform::Render::ShadowFilter *v4; // rbx
  float v5; // xmm6_4

  v4 = this;
  Scaleform::Render::BlurFilterImpl::BlurFilterImpl(
    (Scaleform::Render::BlurFilterImpl *)&this->vfptr,
    Filter_Shadow,
    params);
  v4->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ShadowFilter::`vftable';
  v4->Angle = angle;
  v4->Distance = dist * 20.0;
  v5 = sinf(angle) * (float)(dist * 20.0);
  v4->Params.Offset.x = cosf(angle) * (float)(dist * 20.0);
  v4->Params.Offset.y = v5;
}

// File Line: 194
// RVA: 0x77E550
void __fastcall Scaleform::Render::GlowFilter::GlowFilter(Scaleform::Render::GlowFilter *this, float blurx, float blury, unsigned int passes)
{
  Scaleform::Render::BlurFilterParams *v4; // ST08_8

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::Filter,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Filter::`vftable';
  this->Type = 2;
  this->Frozen = 0;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::BlurFilterImpl::`vftable';
  v4 = &this->Params;
  v4->Mode = 0;
  v4->Passes = 1;
  v4->BlurX = 100.0;
  *(_QWORD *)&v4->BlurY = 1120403456i64;
  v4->Offset.y = 0.0;
  v4->Strength = 1.0;
  v4->Gradient.pObject = 0i64;
  *(_DWORD *)&this->Params.Colors[0].Channels.Green = 16711680;
  this->Params.Colors[0].Channels.Blue = 0;
  *(_WORD *)&this->Params.Colors[1].Channels.Green = 0;
  this->Params.Colors[1].Channels.Alpha = 0;
  *(_QWORD *)&this->Distance = 0i64;
  v4->Mode &= 0xFFFFFFFA;
  v4->Mode |= 2u;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::GlowFilter::`vftable';
  this->Params.BlurX = blurx * 20.0;
  this->Params.BlurY = blury * 20.0;
  this->Params.Passes = passes;
  this->Params.Offset = 0i64;
  *(_WORD *)&this->Params.Colors[0].Channels.Green = -256;
  this->Params.Colors[0].Channels.Blue = 0;
  this->Params.Colors[0].Channels.Alpha = -1;
  this->Params.Strength = 2.0;
}

// File Line: 223
// RVA: 0x77B2E0
void __fastcall Scaleform::Render::BevelFilter::BevelFilter(Scaleform::Render::BevelFilter *this, float blurx, float blury, unsigned int passes)
{
  Scaleform::Render::BevelFilter *v4; // rdi
  Scaleform::Render::BlurFilterParams *v5; // ST28_8
  float v6; // xmm8_4

  v4 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::Filter,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Filter::`vftable';
  this->Type = 3;
  this->Frozen = 0;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::BlurFilterImpl::`vftable';
  v5 = &this->Params;
  v5->Mode = 0;
  v5->Passes = 1;
  v5->BlurX = 100.0;
  *(_QWORD *)&v5->BlurY = 1120403456i64;
  v5->Offset.y = 0.0;
  v5->Strength = 1.0;
  v5->Gradient.pObject = 0i64;
  *(_DWORD *)&this->Params.Colors[0].Channels.Green = 16711680;
  this->Params.Colors[0].Channels.Blue = 0;
  *(_WORD *)&this->Params.Colors[1].Channels.Green = 0;
  this->Params.Colors[1].Channels.Alpha = 0;
  *(_QWORD *)&this->Distance = 0i64;
  v5->Mode &= 0xFFFFFFFB;
  v5->Mode |= 3u;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::BevelFilter::`vftable';
  this->Params.BlurX = blurx * 20.0;
  this->Params.BlurY = blury * 20.0;
  this->Params.Passes = passes;
  this->Angle = 0.78539819;
  this->Distance = 80.0;
  v6 = sinf(0.78539819) * 80.0;
  v4->Params.Offset.x = cosf(0.78539819) * 80.0;
  v4->Params.Offset.y = v6;
  v5->Mode |= 0xA0u;
  *(_DWORD *)&v4->Params.Colors[0].Channels.Green = -65536;
  v4->Params.Colors[0].Channels.Blue = 0;
  *(_WORD *)&v4->Params.Colors[1].Channels.Green = -1;
  v4->Params.Colors[1].Channels.Alpha = -1;
}

// File Line: 235
// RVA: 0x894930
void __fastcall Scaleform::Render::BevelFilter::BevelFilter(Scaleform::Render::BevelFilter *this, Scaleform::Render::BlurFilterParams *params, float angle, float dist)
{
  Scaleform::Render::BevelFilter *v4; // rbx
  float v5; // xmm6_4

  v4 = this;
  Scaleform::Render::BlurFilterImpl::BlurFilterImpl(
    (Scaleform::Render::BlurFilterImpl *)&this->vfptr,
    Filter_Bevel,
    params);
  v4->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::BevelFilter::`vftable';
  v4->Angle = angle;
  v4->Distance = dist * 20.0;
  v5 = sinf(angle) * (float)(dist * 20.0);
  v4->Params.Offset.x = cosf(angle) * (float)(dist * 20.0);
  v4->Params.Offset.y = v5;
}

