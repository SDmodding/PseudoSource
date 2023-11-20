// File Line: 66
// RVA: 0x1E76C0
UFG::qVector3 *__fastcall Render::ParticleGenerator::GetRandomVector(Render::ParticleGenerator *this, UFG::qVector3 *result, UFG::qVector3 *minValue, UFG::qVector3 *maxValue)
{
  UFG::qVector3 *v4; // rbp
  float v5; // xmm6_4
  UFG::qVector3 *v6; // rdi
  UFG::qVector3 *v7; // rsi
  Render::ParticleGenerator *v8; // rbx
  float v9; // xmm7_4
  float v10; // xmm0_4
  int *v11; // rdx
  float v12; // xmm0_4
  float v13; // xmm6_4
  float v14; // xmm0_4
  float v15; // xmm7_4
  float v16; // xmm0_4
  int *v17; // rdx
  float v18; // xmm0_4
  float v19; // xmm6_4
  float v20; // xmm0_4
  float v21; // xmm7_4
  float v22; // xmm0_4
  UFG::qVector3 *v23; // rax

  v4 = result;
  v5 = maxValue->x;
  v6 = maxValue;
  v7 = minValue;
  v8 = this;
  v9 = minValue->x;
  v10 = UFG::qRandom(1.0, this->mParameters->seed);
  v11 = v8->mParameters->seed;
  v12 = v10 * (float)(v5 - v9);
  v13 = v6->y;
  v14 = v12 + v9;
  v15 = v7->y;
  v4->x = v14;
  v16 = UFG::qRandom(1.0, v11);
  v17 = v8->mParameters->seed;
  v18 = v16 * (float)(v13 - v15);
  v19 = v6->z;
  v20 = v18 + v15;
  v21 = v7->z;
  v4->y = v20;
  v22 = UFG::qRandom(1.0, v17);
  v23 = v4;
  v4->z = (float)(v22 * (float)(v19 - v21)) + v21;
  return v23;
}

