// File Line: 44
// RVA: 0x1E2170
void __fastcall Render::ParticleLighting::ReadLightsFromMainMemory(
        Render::ParticleLighting *this,
        UFG::qVector3 *effectPosition,
        Render::FXManagerLights *lights,
        UFG::qMemoryStreamer *memory_streamer)
{
  unsigned int v4; // r10d
  unsigned int v7; // r11d
  __int64 mNumLights; // rbx
  __int64 v9; // rdx
  Render::Light *mMainMemoryAddress; // rcx
  float y; // xmm1_4
  float z; // xmm2_4

  v4 = 0;
  if ( lights->numLights )
  {
    v7 = 0;
    do
    {
      mNumLights = this->mNumLights;
      if ( (unsigned int)mNumLights >= 0x32 )
        break;
      this->mLightStreams[mNumLights].mMainMemoryAddress = lights->lightList[lights->culledLightInstances[v7].lightIndex];
      v9 = this->mNumLights;
      mMainMemoryAddress = (Render::Light *)this->mLightStreams[v9].mMainMemoryAddress;
      if ( !mMainMemoryAddress->mType
        && (float)((float)(mMainMemoryAddress->mDecayRadius * mMainMemoryAddress->mDecayRadius) + 2500.0) >= (float)((float)((float)((float)(mMainMemoryAddress->mTransform.v3.y - effectPosition->y) * (float)(mMainMemoryAddress->mTransform.v3.y - effectPosition->y)) + (float)((float)(mMainMemoryAddress->mTransform.v3.x - effectPosition->x) * (float)(mMainMemoryAddress->mTransform.v3.x - effectPosition->x))) + (float)((float)(mMainMemoryAddress->mTransform.v3.z - effectPosition->z) * (float)(mMainMemoryAddress->mTransform.v3.z - effectPosition->z))) )
      {
        this->mLights[v9] = mMainMemoryAddress;
        ++this->mNumLights;
      }
      ++v4;
      ++v7;
    }
    while ( v4 < lights->numLights );
  }
  y = effectPosition->y;
  z = effectPosition->z;
  Render::ParticleLighting::mEffectPosition.x = effectPosition->x;
  Render::ParticleLighting::mEffectPosition.y = y;
  Render::ParticleLighting::mEffectPosition.z = z;
  UFG::qQuickSortImpl<Render::Light *,bool (*)(Render::Light const *,Render::Light const *)>(
    (Render::IrradianceVolume **)this->mLights,
    (Render::IrradianceVolume **)&this->mLightStreams[49].mState + (int)this->mNumLights,
    (bool (__fastcall *)(Render::IrradianceVolume *, Render::IrradianceVolume *))Render::ParticleLighting::LightSortFunction);
}

// File Line: 73
// RVA: 0x1DFF80
UFG::qColour *__fastcall Render::ParticleLighting::ApplyDynamicLights(
        Render::ParticleLighting *this,
        UFG::qColour *result,
        UFG::qColour *unlitColour,
        UFG::qVector3 *particlePosition)
{
  float v8; // xmm10_4
  float v9; // xmm11_4
  float v10; // xmm12_4
  __int64 v11; // rsi
  int v12; // ebx
  Render::Light *v13; // rdi
  __m128 x_low; // xmm1
  float v15; // xmm13_4
  float mDecayPower; // xmm6_4
  float v17; // xmm7_4
  float v18; // xmm2_4

  v8 = 0.0;
  v9 = 0.0;
  v10 = 0.0;
  v11 = 0i64;
  if ( this->mNumLights )
  {
    v12 = `Render::Light::LuminanceAndColourAtDistance::`2::`local static guard;
    do
    {
      v13 = this->mLights[v11];
      x_low = (__m128)LODWORD(particlePosition->x);
      x_low.m128_f32[0] = (float)((float)((float)(x_low.m128_f32[0] - v13->mTransform.v3.x)
                                        * (float)(x_low.m128_f32[0] - v13->mTransform.v3.x))
                                + (float)((float)(particlePosition->y - v13->mTransform.v3.y)
                                        * (float)(particlePosition->y - v13->mTransform.v3.y)))
                        + (float)((float)(particlePosition->z - v13->mTransform.v3.z)
                                * (float)(particlePosition->z - v13->mTransform.v3.z));
      LODWORD(v15) = _mm_sqrt_ps(x_low).m128_u32[0];
      if ( (v12 & 1) == 0 )
      {
        `Render::Light::LuminanceAndColourAtDistance::`2::`local static guard = v12 | 1;
        `Render::Light::LuminanceAndColourAtDistance::`2::luminance_mul = 1050253722;
        dword_142366DB4 = 1056964608;
        dword_142366DB8 = 1045220557;
        v12 |= 1u;
      }
      mDecayPower = v13->mDecayPower;
      v17 = 1.0 / powf(v13->mDecayRadius, mDecayPower + 1.0);
      v18 = (float)(1.0 / powf(v15, mDecayPower)) - (float)(v17 * v15);
      if ( v18 <= 0.0 )
      {
        v18 = 0.0;
      }
      else if ( v18 >= 1.0 )
      {
        v18 = *(float *)&FLOAT_1_0;
      }
      v8 = v8 + (float)(v18 * v13->mColor.x);
      v9 = v9 + (float)(v18 * v13->mColor.y);
      v10 = v10 + (float)(v18 * v13->mColor.z);
      v11 = (unsigned int)(v11 + 1);
    }
    while ( (unsigned int)v11 < this->mNumLights );
  }
  result->r = v8;
  result->g = v9;
  result->b = v10;
  result->a = unlitColour->a;
  return result;
}

// File Line: 96
// RVA: 0x1E2040
bool __fastcall Render::ParticleLighting::LightSortFunction(Render::Light *a, Render::Light *b)
{
  return (float)((float)((float)((float)(Render::ParticleLighting::mEffectPosition.y - b->mTransform.v3.y)
                               * (float)(Render::ParticleLighting::mEffectPosition.y - b->mTransform.v3.y))
                       + (float)((float)(Render::ParticleLighting::mEffectPosition.x - b->mTransform.v3.x)
                               * (float)(Render::ParticleLighting::mEffectPosition.x - b->mTransform.v3.x)))
               + (float)((float)(Render::ParticleLighting::mEffectPosition.z - b->mTransform.v3.z)
                       * (float)(Render::ParticleLighting::mEffectPosition.z - b->mTransform.v3.z))) > (float)((float)((float)((float)(Render::ParticleLighting::mEffectPosition.x - a->mTransform.v3.x) * (float)(Render::ParticleLighting::mEffectPosition.x - a->mTransform.v3.x)) + (float)((float)(Render::ParticleLighting::mEffectPosition.y - a->mTransform.v3.y) * (float)(Render::ParticleLighting::mEffectPosition.y - a->mTransform.v3.y))) + (float)((float)(Render::ParticleLighting::mEffectPosition.z - a->mTransform.v3.z) * (float)(Render::ParticleLighting::mEffectPosition.z - a->mTransform.v3.z)));
}

