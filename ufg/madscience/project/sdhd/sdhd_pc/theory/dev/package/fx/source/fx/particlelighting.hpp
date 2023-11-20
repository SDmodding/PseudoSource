// File Line: 44
// RVA: 0x1E2170
void __fastcall Render::ParticleLighting::ReadLightsFromMainMemory(Render::ParticleLighting *this, UFG::qVector3 *effectPosition, Render::FXManagerLights *lights, UFG::qMemoryStreamer *memory_streamer)
{
  unsigned int v4; // er10
  Render::FXManagerLights *v5; // rdi
  UFG::qVector3 *v6; // rsi
  Render::ParticleLighting *v7; // r9
  unsigned int v8; // er11
  __int64 v9; // rbx
  unsigned __int64 v10; // r8
  __int64 v11; // rdx
  Render::Light *v12; // rcx
  float v13; // xmm1_4
  float v14; // xmm2_4

  v4 = 0;
  v5 = lights;
  v6 = effectPosition;
  v7 = this;
  if ( lights->numLights )
  {
    v8 = 0;
    do
    {
      v9 = v7->mNumLights;
      if ( (unsigned int)v9 >= 0x32 )
        break;
      v10 = (unsigned __int64)&v5->lightList[*(unsigned __int16 *)(((LODWORD(v5->culledLightInstances) + v8 * 16) & 0xF)
                                                                 + ((_QWORD)&v5->culledLightInstances[v8] & 0xFFFFFFFFFFFFFFF0ui64))];
      v7->mLightStreams[v9].mMainMemoryAddress = *(void **)((v10 & 0xF) + (v10 & 0xFFFFFFFFFFFFFFF0ui64));
      v11 = v7->mNumLights;
      v12 = (Render::Light *)v7->mLightStreams[v11].mMainMemoryAddress;
      if ( !v12->mType
        && (float)((float)(v12->mDecayRadius * v12->mDecayRadius) + 2500.0) >= (float)((float)((float)((float)(v12->mTransform.v3.y - v6->y) * (float)(v12->mTransform.v3.y - v6->y))
                                                                                             + (float)((float)(v12->mTransform.v3.x - v6->x) * (float)(v12->mTransform.v3.x - v6->x)))
                                                                                     + (float)((float)(v12->mTransform.v3.z - v6->z)
                                                                                             * (float)(v12->mTransform.v3.z - v6->z))) )
      {
        v7->mLights[v11] = v12;
        ++v7->mNumLights;
      }
      ++v4;
      ++v8;
    }
    while ( v4 < v5->numLights );
  }
  v13 = v6->y;
  v14 = v6->z;
  Render::ParticleLighting::mEffectPosition.x = v6->x;
  Render::ParticleLighting::mEffectPosition.y = v13;
  Render::ParticleLighting::mEffectPosition.z = v14;
  UFG::qQuickSortImpl<Render::Light *,bool (*)(Render::Light const *,Render::Light const *)>(
    (Render::IrradianceVolume **)v7->mLights,
    (Render::IrradianceVolume **)&v7->mLights[(signed int)v7->mNumLights - 1i64],
    (bool (__fastcall *)(Render::IrradianceVolume *, Render::IrradianceVolume *))Render::ParticleLighting::LightSortFunction);
}

// File Line: 73
// RVA: 0x1DFF80
UFG::qColour *__fastcall Render::ParticleLighting::ApplyDynamicLights(Render::ParticleLighting *this, UFG::qColour *result, UFG::qColour *unlitColour, UFG::qVector3 *particlePosition)
{
  UFG::qVector3 *v4; // r15
  UFG::qColour *v5; // r13
  UFG::qColour *v6; // rbp
  Render::ParticleLighting *v7; // r14
  float v8; // xmm10_4
  float v9; // xmm11_4
  float v10; // xmm12_4
  __int64 v11; // rsi
  int v12; // ebx
  Render::Light *v13; // rdi
  __m128 v14; // xmm1
  float v15; // xmm13_4
  float v16; // xmm6_4
  float v17; // xmm7_4
  float v18; // xmm2_4

  v4 = particlePosition;
  v5 = unlitColour;
  v6 = result;
  v7 = this;
  v8 = 0.0;
  v9 = 0.0;
  v10 = 0.0;
  v11 = 0i64;
  if ( this->mNumLights )
  {
    v12 = `Render::Light::LuminanceAndColourAtDistance'::`2'::`local static guard';
    do
    {
      v13 = v7->mLights[v11];
      v14 = (__m128)LODWORD(v4->x);
      v14.m128_f32[0] = (float)((float)((float)(v14.m128_f32[0] - v13->mTransform.v3.x)
                                      * (float)(v14.m128_f32[0] - v13->mTransform.v3.x))
                              + (float)((float)(v4->y - v13->mTransform.v3.y) * (float)(v4->y - v13->mTransform.v3.y)))
                      + (float)((float)(v4->z - v13->mTransform.v3.z) * (float)(v4->z - v13->mTransform.v3.z));
      LODWORD(v15) = (unsigned __int128)_mm_sqrt_ps(v14);
      if ( !(v12 & 1) )
      {
        `Render::Light::LuminanceAndColourAtDistance'::`2'::`local static guard' = v12 | 1;
        `Render::Light::LuminanceAndColourAtDistance'::`2'::luminance_mul = 1050253722;
        dword_142366DB4 = 1056964608;
        dword_142366DB8 = 1045220557;
        v12 |= 1u;
      }
      v16 = v13->mDecayPower;
      v17 = 1.0 / powf(v13->mDecayRadius, v13->mDecayPower + 1.0);
      v18 = (float)(1.0 / powf(v15, v16)) - (float)(v17 * v15);
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
    while ( (unsigned int)v11 < v7->mNumLights );
  }
  v6->r = v8;
  v6->g = v9;
  v6->b = v10;
  v6->a = v5->a;
  return v6;
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

