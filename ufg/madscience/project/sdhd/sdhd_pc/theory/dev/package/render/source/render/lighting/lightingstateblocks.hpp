// File Line: 186
// RVA: 0x2C870
void __fastcall Render::cbDeferredLightState::SetStateBlock(
        Render::cbDeferredLightState *this,
        Illusion::StateValues *state_values)
{
  float *v4; // rax
  float *v5; // rdi
  UFG::qMatrix44 *mWorldView; // rdx
  float y; // xmm3_4
  float z; // xmm4_4
  float x; // xmm2_4
  float v10; // xmm5_4
  float v11; // xmm6_4
  __int16 v12; // dx

  v4 = (float *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x40u, 0x10u);
  v5 = v4;
  if ( v4 )
  {
    mWorldView = this->mWorldView;
    y = this->mPosition.y;
    z = this->mPosition.z;
    x = this->mPosition.x;
    v10 = (float)((float)((float)(y * mWorldView->v1.x) + (float)(x * mWorldView->v0.x)) + (float)(z * mWorldView->v2.x))
        + mWorldView->v3.x;
    v11 = (float)((float)((float)(x * mWorldView->v0.z) + (float)(y * mWorldView->v1.z)) + (float)(z * mWorldView->v2.z))
        + mWorldView->v3.z;
    v4[1] = (float)((float)((float)(x * mWorldView->v0.y) + (float)(y * mWorldView->v1.y))
                  + (float)(z * mWorldView->v2.y))
          + mWorldView->v3.y;
    *v4 = v10;
    v4[2] = v11;
    v4[3] = this->mDecayPower;
    v4[4] = this->mColor.x;
    v4[5] = this->mColor.y;
    v4[6] = this->mColor.z;
    v4[7] = 1.0 / powf(this->mDecayRadius, this->mDecayPower + 1.0);
    v5[8] = this->mFovInner;
    v5[9] = this->mFovOuter;
    v5[10] = this->mShadowFade;
    v5[11] = this->mTexDistAttenV;
    v5[12] = this->mAreaLightWidthHeightNearFar.x;
    v5[13] = this->mAreaLightWidthHeightNearFar.y;
    v5[14] = this->mAreaLightWidthHeightNearFar.z;
    v5[15] = this->mAreaLightWidthHeightNearFar.w;
    v12 = Render::cbDeferredLightState::sStateParamIndex;
    if ( (unsigned int)(__int16)Render::cbDeferredLightState::sStateParamIndex >= 0x40 )
      state_values->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)Render::cbDeferredLightState::sStateParamIndex
                                                      - 64);
    else
      state_values->mSetValueMask.mFlags[0] |= 1i64 << Render::cbDeferredLightState::sStateParamIndex;
    state_values->mParamValues[v12] = v5;
  }
}

