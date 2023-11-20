// File Line: 90
// RVA: 0x237ED0
void __fastcall UFG::RegionRefPtr<UFG::RegionBase>::~RegionRefPtr<UFG::RegionBase>(UFG::RegionRefPtr<UFG::RegionBase> *this)
{
  UFG::RegionRefPtr<UFG::RegionBase> *v1; // rbx
  UFG::RegionBase *v2; // rcx

  v1 = this;
  v2 = this->mPtr;
  if ( v2 )
  {
    if ( --v2->mRefCount <= 0 )
      v2->vfptr->__vecDelDtor(v2, 1u);
    v1->mPtr = 0i64;
  }
}

// File Line: 143
// RVA: 0x238310
void __fastcall UFG::RegionBase::~RegionBase(UFG::RegionBase *this)
{
  this->vfptr = (UFG::RegionBaseVtbl *)&UFG::RegionBase::`vftable;
}

// File Line: 197
// RVA: 0x23C480
UFG::qVector3 *__fastcall UFG::RegionBase::GetAspectNormal(UFG::RegionBase *this, UFG::qVector3 *result, unsigned int aspect)
{
  float v3; // xmm1_4
  UFG::qVector3 *v4; // rax
  float v5; // xmm0_4

  v3 = UFG::qVector3::msDirFront.y;
  v4 = result;
  result->x = UFG::qVector3::msDirFront.x;
  v5 = UFG::qVector3::msDirFront.z;
  result->y = v3;
  result->z = v5;
  return v4;
}

// File Line: 198
// RVA: 0x23E7D0
__int64 __fastcall hkpBreakableMaterial::convertShapeKeyToSubShapeId(hkpBreakableMaterial *this, unsigned int shapeKey)
{
  return shapeKey;
}

// File Line: 264
// RVA: 0x23C410
UFG::qVector3 *__fastcall UFG::RegionSphere::GetAspectCenter(UFG::RegionSphere *this, UFG::qVector3 *result, __int64 aspect)
{
  UFG::qVector3 *v3; // rbx
  float v4; // xmm6_4
  UFG::qVector3 *v5; // rax
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm6_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  UFG::qVector3 *v11; // rax
  char v12; // [rsp+20h] [rbp-28h]

  v3 = result;
  v4 = this->mRadius;
  v5 = this->vfptr->GetAspectNormal((UFG::RegionBase *)this, (UFG::qVector3 *)&v12, aspect);
  v6 = v4;
  v7 = v4;
  v8 = v4 * v5->z;
  v9 = v6 * v5->x;
  v10 = v7 * v5->y;
  v11 = v3;
  v3->z = v8;
  v3->x = v9;
  v3->y = v10;
  return v11;
}

// File Line: 265
// RVA: 0x23F7D0
char __fastcall UFG::RegionSphere::IsHitAspect(UFG::RegionSphere *this, UFG::qVector3 *rayPos, UFG::qVector3 *rayDir, unsigned int *pHitAspect)
{
  char result; // al

  result = 1;
  if ( pHitAspect )
    *pHitAspect = 0;
  return result;
}

// File Line: 308
// RVA: 0x23C820
void __fastcall UFG::RegionBox::GetBoundingBox(UFG::RegionBox *this, UFG::qBox *pBox)
{
  float v2; // xmm0_4
  float v3; // xmm1_4
  float v4; // xmm0_4
  float v5; // xmm1_4

  v2 = this->mBox.mMin.y;
  v3 = this->mBox.mMin.z;
  pBox->mMin.x = this->mBox.mMin.x;
  pBox->mMin.y = v2;
  pBox->mMin.z = v3;
  v4 = this->mBox.mMax.y;
  v5 = this->mBox.mMax.z;
  pBox->mMax.x = this->mBox.mMax.x;
  pBox->mMax.y = v4;
  pBox->mMax.z = v5;
}

// File Line: 310
// RVA: 0x23C090
float __fastcall UFG::RegionBox::GetAreaCrossSection(UFG::RegionBox *this)
{
  return (float)(this->mBox.mMax.y - this->mBox.mMin.y) * (float)(this->mBox.mMax.x - this->mBox.mMin.x);
}

// File Line: 312
// RVA: 0x23DA80
float __fastcall UFG::RegionBox::GetRadius(UFG::RegionBox *this)
{
  __m128 v1; // xmm2
  float v2; // xmm0_4

  v1 = (__m128)LODWORD(this->mBox.mMax.y);
  v2 = this->mBox.mMax.z - this->mBox.mMin.z;
  v1.m128_f32[0] = (float)((float)((float)(v1.m128_f32[0] - this->mBox.mMin.y)
                                 * (float)(v1.m128_f32[0] - this->mBox.mMin.y))
                         + (float)((float)(this->mBox.mMax.x - this->mBox.mMin.x)
                                 * (float)(this->mBox.mMax.x - this->mBox.mMin.x)))
                 + (float)(v2 * v2);
  return COERCE_FLOAT(_mm_sqrt_ps(v1)) * 0.5;
}

// File Line: 315
// RVA: 0x245EB0
void __fastcall UFG::RegionBox::Translate(UFG::RegionBox *this, UFG::qVector3 *offset)
{
  float v2; // xmm1_4
  float v3; // xmm2_4
  float v4; // xmm2_4
  float v5; // xmm1_4

  v2 = this->mBox.mMin.z + offset->z;
  v3 = offset->y + this->mBox.mMin.y;
  this->mBox.mMin.x = offset->x + this->mBox.mMin.x;
  this->mBox.mMin.y = v3;
  this->mBox.mMin.z = v2;
  v4 = this->mBox.mMax.y + offset->y;
  v5 = this->mBox.mMax.z + offset->z;
  this->mBox.mMax.x = this->mBox.mMax.x + offset->x;
  this->mBox.mMax.y = v4;
  this->mBox.mMax.z = v5;
}

// File Line: 332
// RVA: 0x23A790
signed __int64 __fastcall UFG::RegionBox::CycleAspect(UFG::RegionBox *this, unsigned int aspect, bool forward)
{
  return UFG::qBox::CycleFaces((UFG::qBox::eFace)aspect, forward);
}

// File Line: 334
// RVA: 0x23C170
UFG::qVector3 *__fastcall UFG::RegionBox::GetAspectCenter(UFG::RegionBox *this, UFG::qVector3 *result, unsigned int aspect)
{
  UFG::qVector3 *v3; // rbx

  v3 = result;
  UFG::qBox::GetFaceCenter(&this->mBox, result, (UFG::qBox::eFace)aspect);
  return v3;
}

// File Line: 335
// RVA: 0x23C4B0
UFG::qVector3 *__fastcall UFG::RegionBox::GetAspectNormal(UFG::RegionBox *this, UFG::qVector3 *result, unsigned int aspect)
{
  UFG::qVector3 *v3; // rbx
  UFG::qVector3 *v4; // rax
  float v5; // ecx

  v3 = result;
  v4 = UFG::qBox::GetFaceNormal(&this->mBox, (UFG::qBox::eFace)aspect);
  v3->x = v4->x;
  v5 = v4->y;
  v3->z = v4->z;
  v3->y = v5;
  return v3;
}

// File Line: 336
// RVA: 0x23F3F0
char __fastcall UFG::RegionBox::IsHitAspect(UFG::RegionBox *this, UFG::qVector3 *rayPos, UFG::qVector3 *rayDir, unsigned int *pHitAspect)
{
  return UFG::qBox::IsHitRay(&this->mBox, rayPos, rayDir, (UFG::qBox::eFace *)pHitAspect, 0i64);
}

// File Line: 337
// RVA: 0x2460F0
void __fastcall UFG::RegionBox::TranslateAspect(UFG::RegionBox *this, unsigned int aspect, UFG::qVector3 *delta)
{
  UFG::qBox::TranslateFace(&this->mBox, (UFG::qBox::eFace)aspect, delta, 1);
}

// File Line: 389
// RVA: 0x23C0B0
float __fastcall UFG::RegionSphere::GetAreaCrossSection(UFG::RegionSphere *this)
{
  return (float)(this->mRadius * 3.1415927) * this->mRadius;
}

// File Line: 390
// RVA: 0x23DAC0
float __fastcall RandomCondition::GetWeight(UFG::RegionSphere *this)
{
  return this->mRadius;
}

