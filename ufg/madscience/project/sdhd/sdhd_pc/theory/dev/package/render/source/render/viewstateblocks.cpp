// File Line: 50
// RVA: 0x1A340
void __fastcall Render::ScreenProjectionStateInit::ScreenProjectionStateInit(Render::ScreenProjectionStateInit *this)
{
  __m128 v1; // xmm2
  __m128 v2; // ST20_16
  __m128 v3; // ST30_16
  __int128 v4; // ST50_16

  v1 = 0i64;
  v1.m128_f32[0] = (float)1;
  v2 = v1;
  v3 = _mm_shuffle_ps(v1, v1, 81);
  HIDWORD(v4) = *(unsigned __int128 *)&_mm_shuffle_ps(v1, v1, 21) >> 96;
  v2.m128_f32[0] = FLOAT_2_0;
  v3.m128_f32[1] = FLOAT_N2_0;
  *(_QWORD *)&v4 = __PAIR__((unsigned int)FLOAT_1_0, LODWORD(FLOAT_N1_0));
  *((float *)&v4 + 2) = FLOAT_0_001;
  UFG::qMemSet(&Render::cbScreenProjectionState::sScreenLocalTransform, 0, 0xC0u);
  *(__m128 *)&Render::cbScreenProjectionState::sScreenLocalTransform.LocalWorld[8] = _mm_shuffle_ps(v1, v1, 69);
  *(_OWORD *)&Render::cbScreenProjectionState::sScreenLocalTransform.LocalView[8] = *(_OWORD *)&Render::cbScreenProjectionState::sScreenLocalTransform.LocalWorld[8];
  *(_OWORD *)&Render::cbScreenProjectionState::sScreenLocalTransform.LocalProjection[8] = *(_OWORD *)&Render::cbScreenProjectionState::sScreenLocalTransform.LocalWorld[8];
  *(__m128 *)Render::cbScreenProjectionState::sScreenLocalTransform.LocalWorld = v2;
  *(__m128 *)&Render::cbScreenProjectionState::sScreenLocalTransform.LocalWorld[4] = v3;
  *(_OWORD *)&Render::cbScreenProjectionState::sScreenLocalTransform.LocalWorld[12] = v4;
  *(__m128 *)Render::cbScreenProjectionState::sScreenLocalTransform.LocalView = v2;
  *(__m128 *)&Render::cbScreenProjectionState::sScreenLocalTransform.LocalView[4] = v3;
  *(_OWORD *)&Render::cbScreenProjectionState::sScreenLocalTransform.LocalView[12] = v4;
  *(__m128 *)Render::cbScreenProjectionState::sScreenLocalTransform.LocalProjection = v2;
  *(__m128 *)&Render::cbScreenProjectionState::sScreenLocalTransform.LocalProjection[4] = v3;
  *(_OWORD *)&Render::cbScreenProjectionState::sScreenLocalTransform.LocalProjection[12] = v4;
}

// File Line: 72
// RVA: 0x14532E0
void Render::_dynamic_initializer_for__sScreenProjectionStateInit__()
{
  Render::ScreenProjectionStateInit::ScreenProjectionStateInit(&sScreenProjectionStateInit);
}

// File Line: 89
// RVA: 0x1A450
Render::ViewStateBlockParams *__fastcall Render::GetViewStateBlockParams()
{
  if ( !init_0 )
  {
    init_0 = 1;
    gParams.cbLocalProjectionIndex = Render::cbLocalProjectionState::sStateParamIndex;
    gParams.cbLocalTransformIndex = Render::cbLocalTransformState::sStateParamIndex;
    gParams.cbLocalTransformInverseIndex = Render::cbLocalTransformInverseState::sStateParamIndex;
    gParams.cbViewTransformIndex = Render::cbViewTransformState::sStateParamIndex;
    gParams.cbExternalViewTransformIndex = Render::cbExternalViewTransformState::sStateParamIndex;
    gParams.cbShadowTransformIndex = Render::cbShadowTransformState::sStateParamIndex;
  }
  return &gParams;
}

