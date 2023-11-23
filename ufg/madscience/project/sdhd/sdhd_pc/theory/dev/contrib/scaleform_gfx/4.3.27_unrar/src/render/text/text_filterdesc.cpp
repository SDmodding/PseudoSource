// File Line: 24
// RVA: 0x9AEF20
void __fastcall Scaleform::Render::Text::TextFilter::SetDefaultShadow(Scaleform::Render::Text::TextFilter *this)
{
  float v2; // xmm8_4
  float v3; // xmm0_4

  this->BlurStrength = 1.0;
  *(_QWORD *)&this->ShadowParams.Strength = 1065353216i64;
  *(_QWORD *)&this->BlurX = 0i64;
  this->ShadowParams.Mode = 0;
  *(_QWORD *)&this->ShadowParams.BlurX = 0i64;
  this->ShadowFlags = 128;
  this->ShadowAlpha = -1;
  this->ShadowAngle = 0.78539819;
  this->ShadowDistance = 4.0;
  v2 = cosf(0.78539819);
  v3 = sinf(0.78539819);
  this->ShadowParams.Offset.x = v2 * 4.0;
  this->ShadowParams.Offset.y = v3 * 4.0;
}

// File Line: 45
// RVA: 0x998A70
void __fastcall Scaleform::Render::Text::TextFilter::LoadFilterDesc(
        Scaleform::Render::Text::TextFilter *this,
        Scaleform::Render::Filter *filter)
{
  Scaleform::Render::FilterType Type; // eax
  float v4; // xmm8_4
  float ShadowAngle; // xmm0_4
  float v6; // xmm7_4
  float v7; // xmm0_4

  Type = filter->Type;
  if ( Type )
  {
    if ( (unsigned int)(Type - 1) <= 1 && (!this->ShadowParams.Colors[0].Raw || this->ShadowDistance == 0.0) )
    {
      this->ShadowFlags = 0;
      if ( ((__int64)filter[1].vfptr & 0x10) != 0 )
        this->ShadowFlags = 32;
      if ( ((__int64)filter[1].vfptr & 0x40) != 0 )
        this->ShadowFlags |= 0x40u;
      if ( HIDWORD(filter[1].vfptr) )
        this->ShadowFlags |= 0x80u;
      this->ShadowParams.Mode = 0;
      LODWORD(this->ShadowParams.BlurX) = filter[1].RefCount;
      this->ShadowParams.BlurY = *((float *)&filter[1].RefCount + 1);
      this->ShadowParams.Strength = *(float *)&filter[2].vfptr;
      *(_QWORD *)&this->ShadowParams.Colors[0].Channels.Blue = *(Scaleform::RefCountImplCoreVtbl **)((char *)&filter[2].vfptr + 4);
      this->ShadowAlpha = this->ShadowParams.Colors[0].Channels.Alpha;
      this->ShadowAngle = *((float *)&filter[3].vfptr + 1);
      v4 = *(float *)&filter[3].vfptr;
      ShadowAngle = this->ShadowAngle;
      this->ShadowDistance = v4;
      v6 = cosf(ShadowAngle) * v4;
      v7 = sinf(this->ShadowAngle);
      this->ShadowParams.Offset.x = v6;
      this->ShadowParams.Offset.y = v7 * v4;
    }
  }
  else
  {
    LODWORD(this->BlurX) = filter[1].RefCount;
    this->BlurY = *((float *)&filter[1].RefCount + 1);
    this->BlurStrength = *(float *)&filter[2].vfptr;
  }
}

