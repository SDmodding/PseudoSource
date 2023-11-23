// File Line: 92
// RVA: 0x1E7AC0
void __fastcall Render::EmitterParticleAttribute::SetVelocityGravityAndDrag(
        Render::EmitterParticleAttribute *this,
        UFG::qVector3 *vVel,
        float acc,
        float _drag)
{
  unsigned int v5; // r8d
  int v6; // r10d
  unsigned __int16 v7; // r10
  unsigned int v8; // r8d
  unsigned int v9; // edx
  int v10; // r8d
  unsigned __int16 v11; // r8
  unsigned int v12; // edx
  unsigned int v13; // edx
  int v14; // r8d
  unsigned __int16 v15; // r8
  unsigned int v16; // edx
  unsigned int v17; // edx
  int v18; // r8d
  unsigned int v19; // edx
  float y; // [rsp+18h] [rbp+18h]
  float z; // [rsp+18h] [rbp+18h]

  v5 = LODWORD(vVel->x) & 0x7FFFFFFF;
  v6 = HIWORD(LODWORD(vVel->x)) & 0x8000;
  if ( v5 <= 0x47FFEFFF )
  {
    if ( v5 >= 0x38800000 )
      v8 = v5 - 939524096;
    else
      v8 = (LODWORD(vVel->x) & 0x7FFFFF | 0x800000u) >> (113 - (v5 >> 23));
    v7 = ((((v8 >> 13) & 1) + v8 + 4095) >> 13) | v6;
  }
  else
  {
    v7 = v6 | 0x7FFF;
  }
  this->vVelAndDamp.x.mRep = v7;
  y = vVel->y;
  v9 = LODWORD(y) & 0x7FFFFFFF;
  v10 = HIWORD(LODWORD(y)) & 0x8000;
  if ( (LODWORD(y) & 0x7FFFFFFFu) <= 0x47FFEFFF )
  {
    if ( v9 >= 0x38800000 )
      v12 = v9 - 939524096;
    else
      v12 = (LODWORD(y) & 0x7FFFFF | 0x800000u) >> (113 - (v9 >> 23));
    v11 = ((((v12 >> 13) & 1) + v12 + 4095) >> 13) | v10;
  }
  else
  {
    v11 = v10 | 0x7FFF;
  }
  this->vVelAndDamp.y.mRep = v11;
  z = vVel->z;
  v13 = LODWORD(z) & 0x7FFFFFFF;
  v14 = HIWORD(LODWORD(z)) & 0x8000;
  if ( (LODWORD(z) & 0x7FFFFFFFu) <= 0x47FFEFFF )
  {
    if ( v13 >= 0x38800000 )
      v16 = v13 - 939524096;
    else
      v16 = (LODWORD(z) & 0x7FFFFF | 0x800000u) >> (113 - (v13 >> 23));
    v15 = ((((v16 >> 13) & 1) + v16 + 4095) >> 13) | v14;
  }
  else
  {
    v15 = v14 | 0x7FFF;
  }
  this->vVelAndDamp.z.mRep = v15;
  v17 = LODWORD(_drag) & 0x7FFFFFFF;
  v18 = HIWORD(LODWORD(_drag)) & 0x8000;
  if ( (LODWORD(_drag) & 0x7FFFFFFFu) <= 0x47FFEFFF )
  {
    if ( v17 >= 0x38800000 )
      v19 = v17 - 939524096;
    else
      v19 = (LODWORD(_drag) & 0x7FFFFF | 0x800000u) >> (113 - (v17 >> 23));
    this->vVelAndDamp.w.mRep = v18 | ((((v19 >> 13) & 1) + v19 + 4095) >> 13);
    this->vPosAndGrav.w = acc;
  }
  else
  {
    this->vVelAndDamp.w.mRep = v18 | 0x7FFF;
    this->vPosAndGrav.w = acc;
  }
}

// File Line: 165
// RVA: 0x1E2720
void __fastcall Render::EmitterParticleAttribute::SetVelocity(
        Render::EmitterParticleAttribute *this,
        UFG::qVector3 *vVel)
{
  unsigned int v3; // r8d
  int v4; // r9d
  unsigned __int16 v5; // r9
  unsigned int v6; // r8d
  unsigned int v7; // edx
  int v8; // r8d
  unsigned __int16 v9; // r8
  unsigned int v10; // edx
  unsigned int v11; // edx
  int v12; // r8d
  unsigned int v13; // edx
  float y; // [rsp+8h] [rbp+8h]
  float z; // [rsp+8h] [rbp+8h]

  v3 = LODWORD(vVel->x) & 0x7FFFFFFF;
  v4 = HIWORD(LODWORD(vVel->x)) & 0x8000;
  if ( v3 <= 0x47FFEFFF )
  {
    if ( v3 >= 0x38800000 )
      v6 = v3 - 939524096;
    else
      v6 = (LODWORD(vVel->x) & 0x7FFFFF | 0x800000u) >> (113 - (v3 >> 23));
    v5 = ((((v6 >> 13) & 1) + v6 + 4095) >> 13) | v4;
  }
  else
  {
    v5 = v4 | 0x7FFF;
  }
  this->vVelAndDamp.x.mRep = v5;
  y = vVel->y;
  v7 = LODWORD(y) & 0x7FFFFFFF;
  v8 = HIWORD(LODWORD(y)) & 0x8000;
  if ( (LODWORD(y) & 0x7FFFFFFFu) <= 0x47FFEFFF )
  {
    if ( v7 >= 0x38800000 )
      v10 = v7 - 939524096;
    else
      v10 = (LODWORD(y) & 0x7FFFFF | 0x800000u) >> (113 - (v7 >> 23));
    v9 = ((((v10 >> 13) & 1) + v10 + 4095) >> 13) | v8;
  }
  else
  {
    v9 = v8 | 0x7FFF;
  }
  this->vVelAndDamp.y.mRep = v9;
  z = vVel->z;
  v11 = LODWORD(z) & 0x7FFFFFFF;
  v12 = HIWORD(LODWORD(z)) & 0x8000;
  if ( (LODWORD(z) & 0x7FFFFFFFu) <= 0x47FFEFFF )
  {
    if ( v11 >= 0x38800000 )
      v13 = v11 - 939524096;
    else
      v13 = (LODWORD(z) & 0x7FFFFF | 0x800000u) >> (113 - (v11 >> 23));
    this->vVelAndDamp.z.mRep = v12 | ((((v13 >> 13) & 1) + v13 + 4095) >> 13);
  }
  else
  {
    this->vVelAndDamp.z.mRep = v12 | 0x7FFF;
  }
}

// File Line: 172
// RVA: 0x1E78A0
void __fastcall Render::EmitterParticleAttribute::SetInitialVelocity(
        Render::EmitterParticleAttribute *this,
        UFG::qVector3 *velocity)
{
  unsigned int v3; // r8d
  int v4; // r9d
  unsigned __int16 v5; // r9
  unsigned int v6; // r8d
  unsigned int v7; // edx
  int v8; // r8d
  unsigned __int16 v9; // r8
  unsigned int v10; // edx
  unsigned int v11; // edx
  int v12; // r8d
  unsigned int v13; // edx
  float y; // [rsp+8h] [rbp+8h]
  float z; // [rsp+8h] [rbp+8h]

  v3 = LODWORD(velocity->x) & 0x7FFFFFFF;
  v4 = HIWORD(LODWORD(velocity->x)) & 0x8000;
  if ( v3 <= 0x47FFEFFF )
  {
    if ( v3 >= 0x38800000 )
      v6 = v3 - 939524096;
    else
      v6 = (LODWORD(velocity->x) & 0x7FFFFF | 0x800000u) >> (113 - (v3 >> 23));
    v5 = ((((v6 >> 13) & 1) + v6 + 4095) >> 13) | v4;
  }
  else
  {
    v5 = v4 | 0x7FFF;
  }
  this->vInitialVel.x.mRep = v5;
  y = velocity->y;
  v7 = LODWORD(y) & 0x7FFFFFFF;
  v8 = HIWORD(LODWORD(y)) & 0x8000;
  if ( (LODWORD(y) & 0x7FFFFFFFu) <= 0x47FFEFFF )
  {
    if ( v7 >= 0x38800000 )
      v10 = v7 - 939524096;
    else
      v10 = (LODWORD(y) & 0x7FFFFF | 0x800000u) >> (113 - (v7 >> 23));
    v9 = ((((v10 >> 13) & 1) + v10 + 4095) >> 13) | v8;
  }
  else
  {
    v9 = v8 | 0x7FFF;
  }
  this->vInitialVel.y.mRep = v9;
  z = velocity->z;
  v11 = LODWORD(z) & 0x7FFFFFFF;
  v12 = HIWORD(LODWORD(z)) & 0x8000;
  if ( (LODWORD(z) & 0x7FFFFFFFu) <= 0x47FFEFFF )
  {
    if ( v11 >= 0x38800000 )
      v13 = v11 - 939524096;
    else
      v13 = (LODWORD(z) & 0x7FFFFF | 0x800000u) >> (113 - (v11 >> 23));
    this->vInitialVel.z.mRep = v12 | ((((v13 >> 13) & 1) + v13 + 4095) >> 13);
  }
  else
  {
    this->vInitialVel.z.mRep = v12 | 0x7FFF;
  }
}

// File Line: 209
// RVA: 0x1E7A40
void __fastcall Render::EmitterParticleAttribute::SetRotationDamp(
        Render::EmitterParticleAttribute *this,
        const float damp)
{
  unsigned int v2; // edx
  int v3; // r8d
  unsigned int v4; // edx

  v2 = LODWORD(damp) & 0x7FFFFFFF;
  v3 = HIWORD(LODWORD(damp)) & 0x8000;
  if ( (LODWORD(damp) & 0x7FFFFFFFu) <= 0x47FFEFFF )
  {
    if ( v2 >= 0x38800000 )
      v4 = v2 - 939524096;
    else
      v4 = (LODWORD(damp) & 0x7FFFFF | 0x800000u) >> (113 - (v2 >> 23));
    this->vInitialVel.w.mRep = v3 | ((((v4 >> 13) & 1) + v4 + 4095) >> 13);
  }
  else
  {
    this->vInitialVel.w.mRep = v3 | 0x7FFF;
  }
}

// File Line: 252
// RVA: 0x1E22C0
void __fastcall Render::EmitterParticleAttribute::SetColour(
        Render::EmitterParticleAttribute *this,
        UFG::qColour *colour)
{
  unsigned int v3; // r8d
  int v4; // r9d
  unsigned __int16 v5; // r9
  unsigned int v6; // r8d
  unsigned int v7; // edx
  int v8; // r8d
  unsigned __int16 v9; // r8
  unsigned int v10; // edx
  unsigned int v11; // edx
  int v12; // r8d
  unsigned __int16 v13; // r8
  unsigned int v14; // edx
  unsigned int v15; // edx
  int v16; // r8d
  unsigned int v17; // edx
  float g; // [rsp+8h] [rbp+8h]
  float b; // [rsp+8h] [rbp+8h]
  float a; // [rsp+8h] [rbp+8h]

  v3 = LODWORD(colour->r) & 0x7FFFFFFF;
  v4 = HIWORD(LODWORD(colour->r)) & 0x8000;
  if ( v3 <= 0x47FFEFFF )
  {
    if ( v3 >= 0x38800000 )
      v6 = v3 - 939524096;
    else
      v6 = (LODWORD(colour->r) & 0x7FFFFF | 0x800000u) >> (113 - (v3 >> 23));
    v5 = ((((v6 >> 13) & 1) + v6 + 4095) >> 13) | v4;
  }
  else
  {
    v5 = v4 | 0x7FFF;
  }
  this->fColour.x.mRep = v5;
  g = colour->g;
  v7 = LODWORD(g) & 0x7FFFFFFF;
  v8 = HIWORD(LODWORD(g)) & 0x8000;
  if ( (LODWORD(g) & 0x7FFFFFFFu) <= 0x47FFEFFF )
  {
    if ( v7 >= 0x38800000 )
      v10 = v7 - 939524096;
    else
      v10 = (LODWORD(g) & 0x7FFFFF | 0x800000u) >> (113 - (v7 >> 23));
    v9 = ((((v10 >> 13) & 1) + v10 + 4095) >> 13) | v8;
  }
  else
  {
    v9 = v8 | 0x7FFF;
  }
  this->fColour.y.mRep = v9;
  b = colour->b;
  v11 = LODWORD(b) & 0x7FFFFFFF;
  v12 = HIWORD(LODWORD(b)) & 0x8000;
  if ( (LODWORD(b) & 0x7FFFFFFFu) <= 0x47FFEFFF )
  {
    if ( v11 >= 0x38800000 )
      v14 = v11 - 939524096;
    else
      v14 = (LODWORD(b) & 0x7FFFFF | 0x800000u) >> (113 - (v11 >> 23));
    v13 = ((((v14 >> 13) & 1) + v14 + 4095) >> 13) | v12;
  }
  else
  {
    v13 = v12 | 0x7FFF;
  }
  this->fColour.z.mRep = v13;
  a = colour->a;
  v15 = LODWORD(a) & 0x7FFFFFFF;
  v16 = HIWORD(LODWORD(a)) & 0x8000;
  if ( (LODWORD(a) & 0x7FFFFFFFu) <= 0x47FFEFFF )
  {
    if ( v15 >= 0x38800000 )
      v17 = v15 - 939524096;
    else
      v17 = (LODWORD(a) & 0x7FFFFF | 0x800000u) >> (113 - (v15 >> 23));
    this->fColour.w.mRep = v16 | ((((v17 >> 13) & 1) + v17 + 4095) >> 13);
  }
  else
  {
    this->fColour.w.mRep = v16 | 0x7FFF;
  }
}

