// File Line: 84
// RVA: 0x1D6DB0
void __fastcall Render::VolumetricEffect::SetVelocityGravityAndDrag(Render::VolumetricEffect *this, UFG::qVector3 *vVel, float acc, float _drag)
{
  UFG::qVector3 *v4; // rbx
  unsigned int v5; // er8
  int v6; // er10
  unsigned __int16 v7; // r10
  unsigned int v8; // er8
  unsigned int v9; // edx
  int v10; // er8
  unsigned __int16 v11; // r8
  unsigned int v12; // edx
  unsigned int v13; // edx
  int v14; // er8
  unsigned __int16 v15; // r8
  unsigned int v16; // edx
  unsigned int v17; // edx
  int v18; // er8
  unsigned int v19; // edx
  float v20; // [rsp+18h] [rbp+18h]
  float v21; // [rsp+18h] [rbp+18h]
  float v22; // [rsp+18h] [rbp+18h]

  v4 = vVel;
  v20 = vVel->x;
  v5 = LODWORD(vVel->x) & 0x7FFFFFFF;
  v6 = (LODWORD(vVel->x) >> 16) & 0x8000;
  if ( v5 <= 0x47FFEFFF )
  {
    if ( v5 >= 0x38800000 )
      v8 = v5 - 939524096;
    else
      v8 = (LODWORD(v20) & 0x7FFFFF | 0x800000u) >> (113 - (v5 >> 23));
    v7 = ((((v8 >> 13) & 1) + v8 + 4095) >> 13) | v6;
  }
  else
  {
    v7 = v6 | 0x7FFF;
  }
  this->vVelAndDamp.x.mRep = v7;
  v21 = vVel->y;
  v9 = LODWORD(v21) & 0x7FFFFFFF;
  v10 = (LODWORD(v21) >> 16) & 0x8000;
  if ( (LODWORD(v21) & 0x7FFFFFFFu) <= 0x47FFEFFF )
  {
    if ( v9 >= 0x38800000 )
      v12 = v9 - 939524096;
    else
      v12 = (LODWORD(v21) & 0x7FFFFF | 0x800000u) >> (113 - (v9 >> 23));
    v11 = ((((v12 >> 13) & 1) + v12 + 4095) >> 13) | v10;
  }
  else
  {
    v11 = v10 | 0x7FFF;
  }
  this->vVelAndDamp.y.mRep = v11;
  v22 = v4->z;
  v13 = LODWORD(v22) & 0x7FFFFFFF;
  v14 = (LODWORD(v22) >> 16) & 0x8000;
  if ( (LODWORD(v22) & 0x7FFFFFFFu) <= 0x47FFEFFF )
  {
    if ( v13 >= 0x38800000 )
      v16 = v13 - 939524096;
    else
      v16 = (LODWORD(v22) & 0x7FFFFF | 0x800000u) >> (113 - (v13 >> 23));
    v15 = ((((v16 >> 13) & 1) + v16 + 4095) >> 13) | v14;
  }
  else
  {
    v15 = v14 | 0x7FFF;
  }
  this->vVelAndDamp.z.mRep = v15;
  v17 = LODWORD(_drag) & 0x7FFFFFFF;
  v18 = (LODWORD(_drag) >> 16) & 0x8000;
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
  UFG::qVector3 *v2; // rbx
  unsigned int v3; // er8
  int v4; // er9
  unsigned __int16 v5; // r9
  unsigned int v6; // er8
  unsigned int v7; // edx
  int v8; // er8
  unsigned __int16 v9; // r8
  unsigned int v10; // edx
  unsigned int v11; // edx
  int v12; // er8
  unsigned int v13; // edx
  float v14; // [rsp+8h] [rbp+8h]
  float v15; // [rsp+8h] [rbp+8h]
  float v16; // [rsp+8h] [rbp+8h]

  v2 = vVel;
  v14 = vVel->x;
  v3 = LODWORD(vVel->x) & 0x7FFFFFFF;
  v4 = (LODWORD(vVel->x) >> 16) & 0x8000;
  if ( v3 <= 0x47FFEFFF )
  {
    if ( v3 >= 0x38800000 )
      v6 = v3 - 939524096;
    else
      v6 = (LODWORD(v14) & 0x7FFFFF | 0x800000u) >> (113 - (v3 >> 23));
    v5 = ((((v6 >> 13) & 1) + v6 + 4095) >> 13) | v4;
  }
  else
  {
    v5 = v4 | 0x7FFF;
  }
  this->vVelAndDamp.x.mRep = v5;
  v15 = vVel->y;
  v7 = LODWORD(v15) & 0x7FFFFFFF;
  v8 = (LODWORD(v15) >> 16) & 0x8000;
  if ( (LODWORD(v15) & 0x7FFFFFFFu) <= 0x47FFEFFF )
  {
    if ( v7 >= 0x38800000 )
      v10 = v7 - 939524096;
    else
      v10 = (LODWORD(v15) & 0x7FFFFF | 0x800000u) >> (113 - (v7 >> 23));
    v9 = ((((v10 >> 13) & 1) + v10 + 4095) >> 13) | v8;
  }
  else
  {
    v9 = v8 | 0x7FFF;
  }
  this->vVelAndDamp.y.mRep = v9;
  v16 = v2->z;
  v11 = LODWORD(v16) & 0x7FFFFFFF;
  v12 = (LODWORD(v16) >> 16) & 0x8000;
  if ( (LODWORD(v16) & 0x7FFFFFFFu) <= 0x47FFEFFF )
  {
    if ( v11 >= 0x38800000 )
      v13 = v11 - 939524096;
    else
      v13 = (LODWORD(v16) & 0x7FFFFF | 0x800000u) >> (113 - (v11 >> 23));
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
  UFG::qVector3 *v2; // rbx
  unsigned int v3; // er8
  int v4; // er9
  unsigned __int16 v5; // r9
  unsigned int v6; // er8
  unsigned int v7; // edx
  int v8; // er8
  unsigned __int16 v9; // r8
  unsigned int v10; // edx
  unsigned int v11; // edx
  int v12; // er8
  unsigned int v13; // edx
  float v14; // [rsp+8h] [rbp+8h]
  float v15; // [rsp+8h] [rbp+8h]
  float v16; // [rsp+8h] [rbp+8h]

  v2 = velocity;
  v14 = velocity->x;
  v3 = LODWORD(velocity->x) & 0x7FFFFFFF;
  v4 = (LODWORD(velocity->x) >> 16) & 0x8000;
  if ( v3 <= 0x47FFEFFF )
  {
    if ( v3 >= 0x38800000 )
      v6 = v3 - 939524096;
    else
      v6 = (LODWORD(v14) & 0x7FFFFF | 0x800000u) >> (113 - (v3 >> 23));
    v5 = ((((v6 >> 13) & 1) + v6 + 4095) >> 13) | v4;
  }
  else
  {
    v5 = v4 | 0x7FFF;
  }
  this->vInitialVel.x.mRep = v5;
  v15 = velocity->y;
  v7 = LODWORD(v15) & 0x7FFFFFFF;
  v8 = (LODWORD(v15) >> 16) & 0x8000;
  if ( (LODWORD(v15) & 0x7FFFFFFFu) <= 0x47FFEFFF )
  {
    if ( v7 >= 0x38800000 )
      v10 = v7 - 939524096;
    else
      v10 = (LODWORD(v15) & 0x7FFFFF | 0x800000u) >> (113 - (v7 >> 23));
    v9 = ((((v10 >> 13) & 1) + v10 + 4095) >> 13) | v8;
  }
  else
  {
    v9 = v8 | 0x7FFF;
  }
  this->vInitialVel.y.mRep = v9;
  v16 = v2->z;
  v11 = LODWORD(v16) & 0x7FFFFFFF;
  v12 = (LODWORD(v16) >> 16) & 0x8000;
  if ( (LODWORD(v16) & 0x7FFFFFFFu) <= 0x47FFEFFF )
  {
    if ( v11 >= 0x38800000 )
      v13 = v11 - 939524096;
    else
      v13 = (LODWORD(v16) & 0x7FFFFF | 0x800000u) >> (113 - (v11 >> 23));
    this->vInitialVel.z.mRep = v12 | ((((v13 >> 13) & 1) + v13 + 4095) >> 13);
  }
  else
  {
    this->vInitialVel.z.mRep = v12 | 0x7FFF;
  }
}

