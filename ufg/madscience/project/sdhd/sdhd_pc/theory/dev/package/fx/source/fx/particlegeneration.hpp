// File Line: 66
// RVA: 0x1E76C0
UFG::qVector3 *__fastcall Render::ParticleGenerator::GetRandomVector(
        Render::ParticleGenerator *this,
        UFG::qVector3 *result,
        UFG::qVector3 *minValue,
        UFG::qVector3 *maxValue)
{
  float x; // xmm6_4
  float v9; // xmm7_4
  float v10; // xmm0_4
  int *seed; // rdx
  float v12; // xmm0_4
  float y; // xmm6_4
  float v14; // xmm0_4
  float v15; // xmm7_4
  float v16; // xmm0_4
  int *v17; // rdx
  float v18; // xmm0_4
  float z; // xmm6_4
  float v20; // xmm0_4
  float v21; // xmm7_4
  float v22; // xmm0_4
  UFG::qVector3 *v23; // rax

  x = maxValue->x;
  v9 = minValue->x;
  v10 = UFG::qRandom(1.0, (unsigned int *)this->mParameters->seed);
  seed = this->mParameters->seed;
  v12 = v10 * (float)(x - v9);
  y = maxValue->y;
  v14 = v12 + v9;
  v15 = minValue->y;
  result->x = v14;
  v16 = UFG::qRandom(1.0, (unsigned int *)seed);
  v17 = this->mParameters->seed;
  v18 = v16 * (float)(y - v15);
  z = maxValue->z;
  v20 = v18 + v15;
  v21 = minValue->z;
  result->y = v20;
  v22 = UFG::qRandom(1.0, (unsigned int *)v17);
  v23 = result;
  result->z = (float)(v22 * (float)(z - v21)) + v21;
  return v23;
}

