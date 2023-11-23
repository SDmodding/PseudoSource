// File Line: 84
// RVA: 0x1D6DB0
void __fastcall Render::VolumetricEffect::SetVelocityGravityAndDrag(
        Render::VolumetricEffect *this,
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

// File Line: 95
// RVA: 0x1D6C00
void __fastcall Render::VolumetricEffect::SetVelocity(Render::VolumetricEffect *this, UFG::qVector3 *vVel)
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

// File Line: 102
// RVA: 0x1D6590
void __fastcall Render::VolumetricEffect::SetInitialVelocity(Render::VolumetricEffect *this, UFG::qVector3 *velocity)
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

