// File Line: 97
// RVA: 0x1CC450
UFG::qVector3 *__fastcall Render::EffectEmitterSettings::GetLocalVelocity(
        Render::EffectEmitterSettings *this,
        UFG::qVector3 *result,
        float t0,
        float t1,
        float t2,
        UFG::qMatrix44 *mBasis)
{
  float v6; // xmm9_4
  float v7; // xmm7_4
  float v8; // xmm8_4
  float v9; // xmm5_4
  float v10; // xmm0_4
  UFG::qVector3 *v11; // rax
  float v12; // xmm4_4
  float v13; // xmm3_4
  float v14; // xmm0_4

  v6 = (float)((float)(this->mLocalVelocityMax.z - this->mLocalVelocityMin.z) * t2) + this->mLocalVelocityMin.z;
  v7 = v6 * mBasis->v2.x;
  v8 = v6 * mBasis->v2.y;
  v9 = (float)((float)(this->mLocalVelocityMax.y - this->mLocalVelocityMin.y) * t1) + this->mLocalVelocityMin.y;
  v10 = (float)((float)(this->mLocalVelocityMax.x - this->mLocalVelocityMin.x) * t0) + this->mLocalVelocityMin.x;
  v11 = result;
  v12 = (float)((float)(v10 * mBasis->v0.z) + (float)(v9 * mBasis->v1.z)) + (float)(v6 * mBasis->v2.z);
  v13 = (float)(v10 * mBasis->v0.x) + (float)(v9 * mBasis->v1.x);
  v14 = (float)(v10 * mBasis->v0.y) + (float)(v9 * mBasis->v1.y);
  result->z = v12;
  result->x = v13 + v7;
  result->y = v14 + v8;
  return v11;
}

