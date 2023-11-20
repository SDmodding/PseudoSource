// File Line: 186
// RVA: 0x2C870
void __fastcall Render::cbDeferredLightState::SetStateBlock(Render::cbDeferredLightState *this, Illusion::StateValues *state_values)
{
  Illusion::StateValues *v2; // rbx
  Render::cbDeferredLightState *v3; // rsi
  char *v4; // rax
  char *v5; // rdi
  float *v6; // rdx
  float v7; // xmm3_4
  float v8; // xmm4_4
  float v9; // xmm5_4
  float v10; // xmm6_4
  __int16 v11; // dx

  v2 = state_values;
  v3 = this;
  v4 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x40u, 0x10u);
  v5 = v4;
  if ( v4 )
  {
    v6 = &v3->mWorldView->v0.x;
    v7 = v3->mPosition.y;
    v8 = v3->mPosition.z;
    v9 = (float)((float)((float)(v7 * v6[4]) + (float)(v3->mPosition.x * *v6)) + (float)(v8 * v6[8])) + v6[12];
    v10 = (float)((float)((float)(v3->mPosition.x * v6[2]) + (float)(v7 * v6[6])) + (float)(v8 * v6[10])) + v6[14];
    *((float *)v4 + 1) = (float)((float)((float)(v3->mPosition.x * v6[1]) + (float)(v7 * v6[5])) + (float)(v8 * v6[9]))
                       + v6[13];
    *(float *)v4 = v9;
    *((float *)v4 + 2) = v10;
    *((_DWORD *)v4 + 3) = LODWORD(v3->mDecayPower);
    *((_DWORD *)v4 + 4) = LODWORD(v3->mColor.x);
    *((_DWORD *)v4 + 5) = LODWORD(v3->mColor.y);
    *((_DWORD *)v4 + 6) = LODWORD(v3->mColor.z);
    *((float *)v4 + 7) = 1.0 / powf(v3->mDecayRadius, v3->mDecayPower + 1.0);
    *((_DWORD *)v5 + 8) = LODWORD(v3->mFovInner);
    *((_DWORD *)v5 + 9) = LODWORD(v3->mFovOuter);
    *((_DWORD *)v5 + 10) = LODWORD(v3->mShadowFade);
    *((_DWORD *)v5 + 11) = LODWORD(v3->mTexDistAttenV);
    *((_DWORD *)v5 + 12) = LODWORD(v3->mAreaLightWidthHeightNearFar.x);
    *((_DWORD *)v5 + 13) = LODWORD(v3->mAreaLightWidthHeightNearFar.y);
    *((_DWORD *)v5 + 14) = LODWORD(v3->mAreaLightWidthHeightNearFar.z);
    *((_DWORD *)v5 + 15) = LODWORD(v3->mAreaLightWidthHeightNearFar.w);
    v11 = Render::cbDeferredLightState::sStateParamIndex;
    if ( (unsigned int)(signed __int16)Render::cbDeferredLightState::sStateParamIndex >= 0x40 )
      v2->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)Render::cbDeferredLightState::sStateParamIndex - 64);
    else
      v2->mSetValueMask.mFlags[0] |= 1i64 << Render::cbDeferredLightState::sStateParamIndex;
    v2->mParamValues[v11] = v5;
  }
}

