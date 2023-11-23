// File Line: 76
// RVA: 0x77B740
void __fastcall Scaleform::Render::BlurFilterImpl::BlurFilterImpl(
        Scaleform::Render::BlurFilterImpl *this,
        Scaleform::Render::FilterType type)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::Filter,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Filter::`vftable;
  this->Type = type;
  this->Frozen = 0;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::BlurFilterImpl::`vftable;
  this->Params.Mode = 0;
  this->Params.Passes = 1;
  this->Params.BlurX = 100.0;
  *(_QWORD *)&this->Params.BlurY = 1120403456i64;
  this->Params.Offset.y = 0.0;
  this->Params.Strength = 1.0;
  this->Params.Gradient.pObject = 0i64;
  *(_DWORD *)&this->Params.Colors[0].Channels.Green = 16711680;
  this->Params.Colors[0].Channels.Blue = 0;
  *(_WORD *)&this->Params.Colors[1].Channels.Green = 0;
  this->Params.Colors[1].Channels.Alpha = 0;
  *(_QWORD *)&this->Distance = 0i64;
  this->Params.Mode &= 0xFFFFFFF8;
  this->Params.Mode |= type;
}

// File Line: 83
// RVA: 0x894C40
void __fastcall Scaleform::Render::BlurFilterImpl::BlurFilterImpl(
        Scaleform::Render::BlurFilterImpl *this,
        Scaleform::Render::FilterType type,
        Scaleform::Render::BlurFilterParams *params)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::Filter,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Filter::`vftable;
  this->Type = type;
  this->Frozen = 0;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::BlurFilterImpl::`vftable;
  Scaleform::Render::BlurFilterParams::BlurFilterParams(&this->Params, params);
  *(_QWORD *)&this->Distance = 0i64;
}

// File Line: 134
// RVA: 0x77B5C0
void __fastcall Scaleform::Render::BlurFilter::BlurFilter(
        Scaleform::Render::BlurFilter *this,
        float blurx,
        float blury,
        unsigned int passes)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::Filter,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Filter::`vftable;
  this->Type = Filter_Blur;
  this->Frozen = 0;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::BlurFilterImpl::`vftable;
  this->Params.Mode = 0;
  this->Params.Passes = 1;
  this->Params.BlurX = 100.0;
  *(_QWORD *)&this->Params.BlurY = 1120403456i64;
  this->Params.Offset.y = 0.0;
  this->Params.Strength = 1.0;
  this->Params.Gradient.pObject = 0i64;
  *(_DWORD *)&this->Params.Colors[0].Channels.Green = 16711680;
  this->Params.Colors[0].Channels.Blue = 0;
  *(_WORD *)&this->Params.Colors[1].Channels.Green = 0;
  this->Params.Colors[1].Channels.Alpha = 0;
  *(_QWORD *)&this->Distance = 0i64;
  this->Params.Mode &= 0xFFFFFFF8;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::BlurFilter::`vftable;
  this->Params.BlurX = blurx * 20.0;
  this->Params.BlurY = blury * 20.0;
  this->Params.Passes = passes;
}

// File Line: 162
// RVA: 0x781B90
void __fastcall Scaleform::Render::ShadowFilter::ShadowFilter(
        Scaleform::Render::ShadowFilter *this,
        float angle,
        float dist,
        float blurx,
        float blury,
        unsigned int passes)
{
  float v7; // xmm6_4

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::Filter,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Filter::`vftable;
  this->Type = Filter_Shadow;
  this->Frozen = 0;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::BlurFilterImpl::`vftable;
  this->Params.Mode = 0;
  this->Params.Passes = 1;
  this->Params.BlurX = 100.0;
  *(_QWORD *)&this->Params.BlurY = 1120403456i64;
  this->Params.Offset.y = 0.0;
  this->Params.Strength = 1.0;
  this->Params.Gradient.pObject = 0i64;
  *(_DWORD *)&this->Params.Colors[0].Channels.Green = 16711680;
  this->Params.Colors[0].Channels.Blue = 0;
  *(_WORD *)&this->Params.Colors[1].Channels.Green = 0;
  this->Params.Colors[1].Channels.Alpha = 0;
  *(_QWORD *)&this->Distance = 0i64;
  this->Params.Mode &= 0xFFFFFFF9;
  this->Params.Mode |= 1u;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ShadowFilter::`vftable;
  this->Params.BlurX = blurx * 20.0;
  this->Params.BlurY = blury * 20.0;
  this->Params.Passes = passes;
  this->Angle = angle;
  this->Distance = dist * 20.0;
  v7 = sinf(angle) * (float)(dist * 20.0);
  this->Params.Offset.x = cosf(angle) * (float)(dist * 20.0);
  this->Params.Offset.y = v7;
  *(_WORD *)&this->Params.Colors[0].Channels.Green = 0;
  this->Params.Colors[0].Channels.Blue = 0;
  this->Params.Colors[0].Channels.Alpha = -1;
}

// File Line: 172
// RVA: 0x89CBD0
void __fastcall Scaleform::Render::ShadowFilter::ShadowFilter(
        Scaleform::Render::ShadowFilter *this,
        Scaleform::Render::BlurFilterParams *params,
        float angle,
        float dist)
{
  float v5; // xmm6_4

  Scaleform::Render::BlurFilterImpl::BlurFilterImpl(this, Filter_Shadow, params);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ShadowFilter::`vftable;
  this->Angle = angle;
  this->Distance = dist * 20.0;
  v5 = sinf(angle) * (float)(dist * 20.0);
  this->Params.Offset.x = cosf(angle) * (float)(dist * 20.0);
  this->Params.Offset.y = v5;
}

// File Line: 194
// RVA: 0x77E550
void __fastcall Scaleform::Render::GlowFilter::GlowFilter(
        Scaleform::Render::GlowFilter *this,
        float blurx,
        float blury,
        unsigned int passes)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::Filter,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Filter::`vftable;
  this->Type = Filter_Glow;
  this->Frozen = 0;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::BlurFilterImpl::`vftable;
  this->Params.Mode = 0;
  this->Params.Passes = 1;
  this->Params.BlurX = 100.0;
  *(_QWORD *)&this->Params.BlurY = 1120403456i64;
  this->Params.Offset.y = 0.0;
  this->Params.Strength = 1.0;
  this->Params.Gradient.pObject = 0i64;
  *(_DWORD *)&this->Params.Colors[0].Channels.Green = 16711680;
  this->Params.Colors[0].Channels.Blue = 0;
  *(_WORD *)&this->Params.Colors[1].Channels.Green = 0;
  this->Params.Colors[1].Channels.Alpha = 0;
  *(_QWORD *)&this->Distance = 0i64;
  this->Params.Mode &= 0xFFFFFFFA;
  this->Params.Mode |= 2u;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::GlowFilter::`vftable;
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
void __fastcall Scaleform::Render::BevelFilter::BevelFilter(
        Scaleform::Render::BevelFilter *this,
        float blurx,
        float blury,
        unsigned int passes)
{
  Scaleform::Render::BlurFilterParams *p_Params; // rbx
  float v6; // xmm8_4

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::Filter,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Filter::`vftable;
  this->Type = Filter_Bevel;
  this->Frozen = 0;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::BlurFilterImpl::`vftable;
  p_Params = &this->Params;
  this->Params.Mode = 0;
  this->Params.Passes = 1;
  this->Params.BlurX = 100.0;
  *(_QWORD *)&this->Params.BlurY = 1120403456i64;
  this->Params.Offset.y = 0.0;
  this->Params.Strength = 1.0;
  this->Params.Gradient.pObject = 0i64;
  *(_DWORD *)&this->Params.Colors[0].Channels.Green = 16711680;
  this->Params.Colors[0].Channels.Blue = 0;
  *(_WORD *)&this->Params.Colors[1].Channels.Green = 0;
  this->Params.Colors[1].Channels.Alpha = 0;
  *(_QWORD *)&this->Distance = 0i64;
  this->Params.Mode &= ~4u;
  this->Params.Mode |= 3u;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::BevelFilter::`vftable;
  this->Params.BlurX = blurx * 20.0;
  this->Params.BlurY = blury * 20.0;
  this->Params.Passes = passes;
  this->Angle = 0.78539819;
  this->Distance = 80.0;
  v6 = sinf(0.78539819) * 80.0;
  this->Params.Offset.x = cosf(0.78539819) * 80.0;
  this->Params.Offset.y = v6;
  p_Params->Mode |= 0xA0u;
  *(_DWORD *)&this->Params.Colors[0].Channels.Green = -65536;
  this->Params.Colors[0].Channels.Blue = 0;
  *(_WORD *)&this->Params.Colors[1].Channels.Green = -1;
  this->Params.Colors[1].Channels.Alpha = -1;
}

// File Line: 235
// RVA: 0x894930
void __fastcall Scaleform::Render::BevelFilter::BevelFilter(
        Scaleform::Render::BevelFilter *this,
        Scaleform::Render::BlurFilterParams *params,
        float angle,
        float dist)
{
  float v5; // xmm6_4

  Scaleform::Render::BlurFilterImpl::BlurFilterImpl(this, Filter_Bevel, params);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::BevelFilter::`vftable;
  this->Angle = angle;
  this->Distance = dist * 20.0;
  v5 = sinf(angle) * (float)(dist * 20.0);
  this->Params.Offset.x = cosf(angle) * (float)(dist * 20.0);
  this->Params.Offset.y = v5;
}

