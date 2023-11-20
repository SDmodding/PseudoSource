// File Line: 69
// RVA: 0x14BF9B0
__int64 dynamic_initializer_for__windowUIDs__()
{
  __int64 result; // rax

  windowUIDs[0] = UFG::qStringHashUpper32("D_WinF", 0xFFFFFFFF);
  dword_1423CEED4 = UFG::qStringHashUpper32("D_WinB", 0xFFFFFFFF);
  dword_1423CEED8 = UFG::qStringHashUpper32("D_WinL01_Hijack", 0xFFFFFFFF);
  dword_1423CEEDC = UFG::qStringHashUpper32("D_WinR01_Hijack", 0xFFFFFFFF);
  dword_1423CEEE0 = UFG::qStringHashUpper32("D_WinL02", 0xFFFFFFFF);
  dword_1423CEEE4 = UFG::qStringHashUpper32("D_WinR02", 0xFFFFFFFF);
  dword_1423CEEE8 = UFG::qStringHashUpper32("D_WinL03", 0xFFFFFFFF);
  dword_1423CEEEC = UFG::qStringHashUpper32("D_WinR03", 0xFFFFFFFF);
  dword_1423CEEF0 = UFG::qStringHashUpper32("D_WinL04", 0xFFFFFFFF);
  dword_1423CEEF4 = UFG::qStringHashUpper32("D_WinR04", 0xFFFFFFFF);
  dword_1423CEEF8 = UFG::qStringHashUpper32("D_WinL05", 0xFFFFFFFF);
  dword_1423CEEFC = UFG::qStringHashUpper32("D_WinR05", 0xFFFFFFFF);
  dword_1423CEF00 = UFG::qStringHashUpper32("D_WinL06", 0xFFFFFFFF);
  dword_1423CEF04 = UFG::qStringHashUpper32("D_WinR06", 0xFFFFFFFF);
  dword_1423CEF08 = UFG::qStringHashUpper32("D_WinL07", 0xFFFFFFFF);
  dword_1423CEF0C = UFG::qStringHashUpper32("D_WinR07", 0xFFFFFFFF);
  dword_1423CEF10 = UFG::qStringHashUpper32("D_WinL08", 0xFFFFFFFF);
  dword_1423CEF14 = UFG::qStringHashUpper32("D_WinR08", 0xFFFFFFFF);
  dword_1423CEF18 = UFG::qStringHashUpper32("D_WinL09", 0xFFFFFFFF);
  result = UFG::qStringHashUpper32("D_WinR09", 0xFFFFFFFF);
  qword_1423CEF1C = (unsigned int)result;
  return result;
}

// File Line: 94
// RVA: 0x14BF7F0
__int64 dynamic_initializer_for__transferWindowUIDs__()
{
  __int64 result; // rax

  transferWindowUIDs[0] = UFG::qStringHashUpper32("D_WinB", 0xFFFFFFFF);
  dword_1423CEF34 = UFG::qStringHashUpper32("D_WinF", 0xFFFFFFFF);
  dword_1423CEF38 = UFG::qStringHashUpper32("D_WinR01_Hijack", 0xFFFFFFFF);
  dword_1423CEF3C = UFG::qStringHashUpper32("D_WinL01_Hijack", 0xFFFFFFFF);
  dword_1423CEF40 = UFG::qStringHashUpper32("D_WinR02", 0xFFFFFFFF);
  dword_1423CEF44 = UFG::qStringHashUpper32("D_WinL02", 0xFFFFFFFF);
  dword_1423CEF48 = UFG::qStringHashUpper32("D_WinR03", 0xFFFFFFFF);
  dword_1423CEF4C = UFG::qStringHashUpper32("D_WinL03", 0xFFFFFFFF);
  dword_1423CEF50 = UFG::qStringHashUpper32("D_WinR04", 0xFFFFFFFF);
  dword_1423CEF54 = UFG::qStringHashUpper32("D_WinL04", 0xFFFFFFFF);
  dword_1423CEF58 = UFG::qStringHashUpper32("D_WinR05", 0xFFFFFFFF);
  dword_1423CEF5C = UFG::qStringHashUpper32("D_WinL05", 0xFFFFFFFF);
  dword_1423CEF60 = UFG::qStringHashUpper32("D_WinR06", 0xFFFFFFFF);
  dword_1423CEF64 = UFG::qStringHashUpper32("D_WinL06", 0xFFFFFFFF);
  dword_1423CEF68 = UFG::qStringHashUpper32("D_WinR07", 0xFFFFFFFF);
  dword_1423CEF6C = UFG::qStringHashUpper32("D_WinL07", 0xFFFFFFFF);
  dword_1423CEF70 = UFG::qStringHashUpper32("D_WinR08", 0xFFFFFFFF);
  dword_1423CEF74 = UFG::qStringHashUpper32("D_WinL08", 0xFFFFFFFF);
  dword_1423CEF78 = UFG::qStringHashUpper32("D_WinR09", 0xFFFFFFFF);
  result = UFG::qStringHashUpper32("D_WinL09", 0xFFFFFFFF);
  qword_1423CEF7C = (unsigned int)result;
  return result;
}

// File Line: 118
// RVA: 0x14BCC20
__int64 dynamic_initializer_for__detachableBoneNameUIDS__()
{
  UFG::qSymbolUC::create_from_string(detachableBoneNameUIDS, "M_DoorL01");
  UFG::qSymbolUC::create_from_string(&stru_1423CEDB4, "M_DoorR01");
  UFG::qSymbolUC::create_from_string(&stru_1423CEDB8, "M_DoorL02");
  UFG::qSymbolUC::create_from_string(&stru_1423CEDBC, "M_DoorR02");
  UFG::qSymbolUC::create_from_string(&stru_1423CEDC0, "M_Hood");
  UFG::qSymbolUC::create_from_string(&stru_1423CEDC4, "M_WinR01");
  UFG::qSymbolUC::create_from_string(&stru_1423CEDC8, "M_WinL01");
  UFG::qSymbolUC::create_from_string(&stru_1423CEDCC, "M_WinR02");
  UFG::qSymbolUC::create_from_string(&stru_1423CEDD0, "M_WinL02");
  UFG::qSymbolUC::create_from_string(&stru_1423CEDD4, "M_WinR03");
  UFG::qSymbolUC::create_from_string(&stru_1423CEDD8, "M_WinL03");
  UFG::qSymbolUC::create_from_string(&stru_1423CEDDC, "M_WinR04");
  UFG::qSymbolUC::create_from_string(&stru_1423CEDE0, "M_WinL04");
  return atexit(dynamic_atexit_destructor_for__detachableBoneNameUIDS__);
}

// File Line: 138
// RVA: 0x39DD80
void __fastcall CharacterDamageRig::CharacterDamageRig(CharacterDamageRig *this)
{
  this->mVisualDamageTargets.p = 0i64;
  *(_QWORD *)&this->mVisualDamageTargets.size = 0i64;
  this->mPaintEffectApplied = 0.0;
  this->mPaintEffect.x = 1.0;
  this->mPaintEffect.y = 1.0;
  *(_QWORD *)&this->mPaintEffect.z = 1065353216i64;
  *(_QWORD *)&this->mCharredEffectInitialAmount = 0i64;
  this->mDamaged = 0;
  this->mDamageScale = 0.0;
}

// File Line: 149
// RVA: 0x39F800
void __fastcall CharacterDamageRig::~CharacterDamageRig(CharacterDamageRig *this)
{
  CharacterDamageRig *v1; // rbx
  CharacterDamageRig::VisualDamageTarget *v2; // rcx

  v1 = this;
  v2 = this->mVisualDamageTargets.p;
  if ( v2 )
    operator delete[](v2);
  v1->mVisualDamageTargets.p = 0i64;
  *(_QWORD *)&v1->mVisualDamageTargets.size = 0i64;
}

// File Line: 153
// RVA: 0x3AAE10
void __fastcall CharacterDamageRig::InitCharacterBoneNormals(CharacterDamageRig *this)
{
  char *v1; // rax
  signed __int64 v2; // rdx

  v1 = this->mCharacterMarkers[0].mValue;
  v2 = 26i64;
  do
  {
    *(_DWORD *)v1 = 0;
    *((_WORD *)v1 + 2) = 0;
    v1 += 28;
    --v2;
  }
  while ( v2 );
  this->mPaintEffectApplied = 0.0;
  this->mPaintEffect.x = 1.0;
  this->mPaintEffect.y = 1.0;
  this->mPaintEffect.z = 1.0;
  this->mDamaged = 0;
}

// File Line: 179
// RVA: 0x3A4F00
void __fastcall CharacterDamageRig::Clone(CharacterDamageRig *this, CharacterDamageRig *source)
{
  signed __int64 v2; // r8
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // eax
  char *v6; // rdx
  signed __int64 v7; // rcx
  char v8; // al

  this->mPaintEffectApplied = source->mPaintEffectApplied;
  v2 = (char *)source - (char *)this;
  v3 = source->mPaintEffect.y;
  v4 = source->mPaintEffect.z;
  this->mPaintEffect.x = source->mPaintEffect.x;
  this->mPaintEffect.y = v3;
  this->mPaintEffect.z = v4;
  this->mCharredEffectAmount = source->mCharredEffectAmount;
  this->mCharredEffectInitialAmount = source->mCharredEffectInitialAmount;
  this->mCharredEffectElapsedTime = source->mCharredEffectElapsedTime;
  this->mDamaged = source->mDamaged;
  v5 = source->mDamageScale;
  v6 = this->mCharacterMarkers[0].mValue;
  this->mDamageScale = v5;
  v7 = 26i64;
  do
  {
    v8 = v6[v2];
    v6 += 28;
    *(v6 - 28) = v8;
    *(v6 - 27) = v6[v2 - 27];
    *(v6 - 26) = v6[v2 - 26];
    *(v6 - 25) = v6[v2 - 25];
    *(v6 - 24) = v6[v2 - 24];
    *(v6 - 23) = v6[v2 - 23];
    --v7;
  }
  while ( v7 );
}

// File Line: 201
// RVA: 0x3A7C30
void __fastcall CharacterDamageRig::GetCharacterWeightList(CharacterDamageRig *this, float *remapped_array, __int64 num_remapped_bones, const char *bone_remap_array)
{
  float *v4; // r11
  float *v5; // rbx
  int v6; // er10
  __int64 v7; // rax
  unsigned int v8; // edx
  __int64 v9; // rax

  v4 = remapped_array;
  if ( (_DWORD)num_remapped_bones )
  {
    v5 = remapped_array + 6;
    num_remapped_bones = (unsigned int)num_remapped_bones;
    v6 = 0;
    do
    {
      v7 = *(unsigned __int8 *)bone_remap_array;
      if ( (unsigned int)v7 < 0x1A )
      {
        *(v5 - 6) = (float)((float)(unsigned __int8)this->mCharacterMarkers[v7].mValue[0] * 0.0039215689)
                  * this->mDamageScale;
        *(v5 - 5) = (float)((float)(unsigned __int8)this->mCharacterMarkers[v7].mValue[1] * 0.0039215689)
                  * this->mDamageScale;
        *(v5 - 4) = (float)((float)(unsigned __int8)this->mCharacterMarkers[v7].mValue[2] * 0.0039215689)
                  * this->mDamageScale;
        *(v5 - 3) = 0.0;
        *(v5 - 2) = (float)((float)(unsigned __int8)this->mCharacterMarkers[v7].mValue[3] * 0.0039215689)
                  * this->mDamageScale;
        *(v5 - 1) = (float)((float)(unsigned __int8)this->mCharacterMarkers[v7].mValue[4] * 0.0039215689)
                  * this->mDamageScale;
        *v5 = (float)((float)(unsigned __int8)this->mCharacterMarkers[v7].mValue[5] * 0.0039215689) * this->mDamageScale;
        v5[1] = 0.0;
      }
      else
      {
        v8 = 0;
        do
        {
          v9 = v6 + v8++;
          v4[v9] = 0.0;
        }
        while ( v8 < 8 );
      }
      v6 += 8;
      v5 += 8;
      ++bone_remap_array;
      --num_remapped_bones;
    }
    while ( num_remapped_bones );
  }
}

// File Line: 266
// RVA: 0x3A2070
void __fastcall CharacterDamageRig::ApplyDamageVector(CharacterDamageRig *this, Creature *creature, UFG::qVector4 *hitPositionWS, UFG::qVector4 *hitNormalWS, float damageAmount, float health)
{
  UFG::qVector4 *v6; // rdi
  CharacterDamageRig *v7; // r15
  float v8; // xmm0_4
  float v9; // xmm11_4
  float v10; // xmm12_4
  float v11; // xmm13_4
  int v12; // eax
  int v13; // ebx
  __int64 v14; // r14
  SkeletalPose *v15; // r12
  char *v16; // rsi
  float v17; // xmm3_4
  float v18; // xmm9_4
  char *v19; // rdx
  float *v20; // rcx
  float v21; // xmm9_4
  signed __int64 v22; // r8
  float v23; // xmm3_4
  float v24; // xmm4_4
  float v25; // xmm5_4
  float v26; // xmm8_4
  float v27; // xmm2_4
  signed int v28; // eax
  bool v29; // zf
  char v30; // al
  UFG::qMatrix44 d; // [rsp+20h] [rbp-E0h]
  UFG::qMatrix44 matrixWS; // [rsp+60h] [rbp-A0h]
  UFG::qMatrix44 matrixLS; // [rsp+A0h] [rbp-60h]

  v6 = hitPositionWS;
  v7 = this;
  if ( health > 0.40000001 )
    v8 = 0.0;
  else
    v8 = *(float *)&FLOAT_1_0;
  if ( v8 <= this->mDamageScale )
    v8 = this->mDamageScale;
  this->mDamageScale = v8;
  v9 = hitNormalWS->x * -1.0;
  v10 = hitNormalWS->y * -1.0;
  v11 = hitNormalWS->z * -1.0;
  v12 = creature->mPose.mRigHandle.mUFGSkeleton->mhkaSkeleton->m_bones.m_size;
  if ( v12 > 26 )
    v12 = 26;
  v13 = 0;
  v14 = v12;
  if ( v12 > 0 )
  {
    v15 = &creature->mPose;
    v16 = this->mCharacterMarkers[0].mValue;
    do
    {
      SkeletalPose::GetPositionWS(v15, v13, &matrixWS);
      v17 = (float)((float)((float)((float)(matrixWS.v3.y - v6->y) * (float)(matrixWS.v3.y - v6->y))
                          + (float)((float)(matrixWS.v3.x - v6->x) * (float)(matrixWS.v3.x - v6->x)))
                  + (float)((float)(matrixWS.v3.z - v6->z) * (float)(matrixWS.v3.z - v6->z)))
          + (float)((float)(matrixWS.v3.w - v6->w) * (float)(matrixWS.v3.w - v6->w));
      if ( v17 <= sDistanceFalloff )
      {
        v18 = 1.0 - (float)(v17 / sDistanceFalloff);
        SkeletalPose::GetPositionLS(v15, v13, &matrixLS);
        UFG::qInverseAffine(&d, &matrixLS);
        v19 = v16;
        v20 = &cBoneDamageNormals[0].z;
        v21 = v18 * damageAmount;
        v22 = 6i64;
        v23 = (float)((float)((float)(d.v1.x * v10) + (float)(d.v0.x * v9)) + (float)(d.v2.x * v11))
            + (float)(d.v3.x * 0.0);
        v24 = (float)((float)((float)(d.v1.y * v10) + (float)(d.v0.y * v9)) + (float)(d.v2.y * v11))
            + (float)(d.v3.y * 0.0);
        v25 = (float)((float)((float)(d.v1.z * v10) + (float)(d.v0.z * v9)) + (float)(d.v2.z * v11))
            + (float)(d.v3.z * 0.0);
        v26 = (float)((float)((float)(d.v1.w * v10) + (float)(d.v0.w * v9)) + (float)(d.v2.w * v11))
            + (float)(d.v3.w * 0.0);
        do
        {
          v27 = (float)((float)((float)(v24 * *(v20 - 1)) + (float)(v23 * *(v20 - 2))) + (float)(v25 * *v20))
              + (float)(v26 * v20[1]);
          if ( v27 <= 0.0 )
          {
            v27 = 0.0;
          }
          else if ( v27 >= 1.0 )
          {
            v27 = *(float *)&FLOAT_1_0;
          }
          v28 = (signed int)(float)((float)((float)(1.0 - v27) * v21) * 255.0);
          v29 = *v19 + (_BYTE)v28 == 0;
          v30 = *v19 + v28;
          *v19 = v30;
          if ( v29 )
          {
            v30 = 0;
          }
          else if ( (unsigned __int8)v30 >= 0xFFu )
          {
            v30 = -1;
          }
          *v19++ = v30;
          v20 += 4;
          --v22;
        }
        while ( v22 );
      }
      ++v13;
      v16 += 28;
      --v14;
    }
    while ( v14 );
  }
  v7->mDamaged = 1;
}

// File Line: 331
// RVA: 0x3A1E40
void __fastcall CharacterDamageRig::ApplyBluntForceDamageToBone(CharacterDamageRig *this, Creature *creature, UFG::qVector4 *hitPositionWS, UFG::qVector4 *invHitNormal, float damage, float health)
{
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // [rsp+30h] [rbp-18h]
  float v10; // [rsp+34h] [rbp-14h]
  float v11; // [rsp+38h] [rbp-10h]
  float v12; // [rsp+3Ch] [rbp-Ch]

  v6 = hitPositionWS->y;
  v9 = hitPositionWS->x;
  v7 = hitPositionWS->z;
  v10 = v6;
  v8 = hitPositionWS->w;
  v11 = v7;
  v12 = v8;
  CharacterDamageRig::ApplyDamageVector(
    this,
    creature,
    hitPositionWS,
    (UFG::qVector4 *)&v9,
    sMeleeDamageScalar * damage,
    health);
}

// File Line: 337
// RVA: 0x3AF920
void __fastcall CharacterDamageRig::SetVisualDamage(CharacterDamageRig *this, const unsigned int bone_uid, const float damage, const float duration)
{
  __int64 v4; // rbp
  CharacterDamageRig *v5; // rdi
  signed int v6; // ebx
  __int64 v7; // rax
  unsigned int v8; // edx
  signed __int64 v9; // r15
  unsigned int v10; // esi
  unsigned int v11; // edx
  CharacterDamageRig::VisualDamageTarget *v12; // rdx
  signed __int64 v13; // r8

  if ( bone_uid < 0x1A )
  {
    v4 = bone_uid;
    v5 = this;
    this->mDamageScale = 1.0;
    v6 = (signed int)(float)(damage * 255.0);
    if ( (_BYTE)v6 )
    {
      if ( (unsigned __int8)v6 >= 0xFFu )
        LOBYTE(v6) = -1;
    }
    else
    {
      LOBYTE(v6) = 0;
    }
    if ( duration == 0.0 )
    {
      v7 = bone_uid;
      this->mCharacterMarkers[v7].mValue[0] = v6;
      this->mCharacterMarkers[v7].mValue[1] = v6;
      this->mCharacterMarkers[v7].mValue[2] = v6;
      this->mCharacterMarkers[v7].mValue[3] = v6;
      this->mCharacterMarkers[v7].mValue[4] = v6;
      this->mCharacterMarkers[v7].mValue[5] = v6;
    }
    else
    {
      v8 = this->mVisualDamageTargets.capacity;
      v9 = this->mVisualDamageTargets.size;
      v10 = v9 + 1;
      if ( (signed int)v9 + 1 > v8 )
      {
        if ( v8 )
          v11 = 2 * v8;
        else
          v11 = 1;
        for ( ; v11 < v10; v11 *= 2 )
          ;
        if ( v11 - v10 > 0x10000 )
          v11 = v9 + 65537;
        UFG::qArray<CharacterDamageRig::VisualDamageTarget,0>::Reallocate(
          &this->mVisualDamageTargets,
          v11,
          "qArray.Add");
      }
      v12 = v5->mVisualDamageTargets.p;
      v5->mVisualDamageTargets.size = v10;
      v13 = v9;
      v12[v13].duration = duration;
      v12[v13].boneID = v4;
      v12[v13].targetDamage = v6;
      v12[v13].elapsedTime = 0.0;
      v12[v13].initialDamage[0] = v5->mCharacterMarkers[v4].mValue[0];
      v12[v13].initialDamage[1] = v5->mCharacterMarkers[v4].mValue[1];
      v12[v13].initialDamage[2] = v5->mCharacterMarkers[v4].mValue[2];
      v12[v13].initialDamage[3] = v5->mCharacterMarkers[v4].mValue[3];
      v12[v13].initialDamage[4] = v5->mCharacterMarkers[v4].mValue[4];
      v12[v13].initialDamage[5] = v5->mCharacterMarkers[v4].mValue[5];
    }
    if ( damage != 0.0 )
      v5->mDamaged = 1;
  }
}

// File Line: 376
// RVA: 0x3B1160
void __fastcall CharacterDamageRig::Update(CharacterDamageRig *this, float delta_sec)
{
  float v2; // xmm5_4
  CharacterDamageRig *v3; // r9
  unsigned int v4; // er10
  CharacterDamageRig::VisualDamageTarget *v5; // rdx
  float v6; // xmm2_4
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm1_4
  float v10; // xmm1_4
  float v11; // xmm1_4
  float v12; // xmm1_4
  float v13; // xmm1_4
  CharacterDamageRig::VisualDamageTarget *v14; // rdx
  signed __int64 v15; // rcx
  unsigned int v16; // eax
  float v17; // xmm5_4
  float v18; // xmm0_4

  v2 = delta_sec;
  v3 = this;
  v4 = 0;
  if ( (signed int)this->mVisualDamageTargets.size > 0 )
  {
    do
    {
      v5 = v3->mVisualDamageTargets.p;
      v6 = v2 + v5[v4].elapsedTime;
      v5[v4].elapsedTime = v6;
      v7 = v6 / v5[v4].duration;
      if ( v7 <= 0.0 )
      {
        v7 = 0.0;
      }
      else if ( v7 >= 1.0 )
      {
        v7 = *(float *)&FLOAT_1_0;
      }
      v8 = (float)(unsigned __int8)v5[v4].initialDamage[0];
      v3->mCharacterMarkers[v5[v4].boneID].mValue[0] = (signed int)(float)((float)((float)((float)(unsigned __int8)v5[v4].targetDamage
                                                                                         - v8)
                                                                                 * v7)
                                                                         + v8);
      v9 = (float)(unsigned __int8)v5[v4].initialDamage[1];
      v3->mCharacterMarkers[v5[v4].boneID].mValue[1] = (signed int)(float)((float)((float)((float)(unsigned __int8)v5[v4].targetDamage
                                                                                         - v9)
                                                                                 * v7)
                                                                         + v9);
      v10 = (float)(unsigned __int8)v5[v4].initialDamage[2];
      v3->mCharacterMarkers[v5[v4].boneID].mValue[2] = (signed int)(float)((float)((float)((float)(unsigned __int8)v5[v4].targetDamage
                                                                                         - v10)
                                                                                 * v7)
                                                                         + v10);
      v11 = (float)(unsigned __int8)v5[v4].initialDamage[3];
      v3->mCharacterMarkers[v5[v4].boneID].mValue[3] = (signed int)(float)((float)((float)((float)(unsigned __int8)v5[v4].targetDamage
                                                                                         - v11)
                                                                                 * v7)
                                                                         + v11);
      v12 = (float)(unsigned __int8)v5[v4].initialDamage[4];
      v3->mCharacterMarkers[v5[v4].boneID].mValue[4] = (signed int)(float)((float)((float)((float)(unsigned __int8)v5[v4].targetDamage
                                                                                         - v12)
                                                                                 * v7)
                                                                         + v12);
      v13 = (float)(unsigned __int8)v5[v4].initialDamage[5];
      v3->mCharacterMarkers[v5[v4].boneID].mValue[5] = (signed int)(float)((float)((float)((float)(unsigned __int8)v5[v4].targetDamage
                                                                                         - v13)
                                                                                 * v7)
                                                                         + v13);
      if ( v5[v4].duration < v5[v4].elapsedTime )
      {
        v14 = v3->mVisualDamageTargets.p;
        v15 = v3->mVisualDamageTargets.size - 1;
        v14[v4].boneID = v14[v3->mVisualDamageTargets.size - 1].boneID;
        v14[v4].elapsedTime = v14[v15].elapsedTime;
        v14[v4].duration = v14[v15].duration;
        *(_DWORD *)v14[v4].initialDamage = *(_DWORD *)v14[v15].initialDamage;
        *(_DWORD *)&v14[v4].initialDamage[4] = *(_DWORD *)&v14[v15].initialDamage[4];
        v16 = v3->mVisualDamageTargets.size;
        if ( v16 > 1 )
          v3->mVisualDamageTargets.size = v16 - 1;
        else
          v3->mVisualDamageTargets.size = 0;
        --v4;
      }
      ++v4;
    }
    while ( (signed int)v4 < (signed int)v3->mVisualDamageTargets.size );
  }
  if ( v3->mCharredEffectAmount > 0.0 )
  {
    v17 = v2 + v3->mCharredEffectElapsedTime;
    v3->mCharredEffectElapsedTime = v17;
    v18 = (float)(1.0 - (float)(v17 * 0.011111111)) * v3->mCharredEffectInitialAmount;
    if ( v18 <= 0.0 )
    {
      v18 = 0.0;
    }
    else if ( v18 >= 1.0 )
    {
      LODWORD(v3->mCharredEffectAmount) = (_DWORD)FLOAT_1_0;
      return;
    }
    v3->mCharredEffectAmount = v18;
  }
}

// File Line: 413
// RVA: 0x3A2430
void __fastcall CharacterDamageRig::ApplyPaintEffect(CharacterDamageRig *this, bool enable, float r, float g, float b)
{
  this->mPaintEffect.x = r;
  this->mPaintEffect.y = g;
  this->mPaintEffect.z = b;
  if ( enable )
    LODWORD(this->mPaintEffectApplied) = (_DWORD)FLOAT_1_0;
  else
    this->mPaintEffectApplied = 0.0;
}

// File Line: 444
// RVA: 0x3A1EA0
void __fastcall CharacterDamageRig::ApplyCharredEffect(CharacterDamageRig *this, float amount)
{
  float v2; // xmm0_4

  if ( amount <= 0.0 )
  {
    amount = 0.0;
  }
  else
  {
    v2 = *(float *)&FLOAT_1_0;
    if ( amount >= 1.0 )
      goto LABEL_6;
  }
  v2 = amount;
LABEL_6:
  this->mCharredEffectAmount = v2;
  this->mCharredEffectInitialAmount = v2;
  this->mCharredEffectElapsedTime = 0.0;
}

// File Line: 451
// RVA: 0x3AE110
void __fastcall CharacterDamageRig::ResetDamage(CharacterDamageRig *this)
{
  signed __int64 v1; // rax
  CharacterDamageRig *v2; // rcx

  v1 = 26i64;
  v2 = (CharacterDamageRig *)((char *)this + 4);
  *(_QWORD *)&v2->mCharacterMarkers[25].mNameUID = 0i64;
  *(_QWORD *)&v2->mPaintEffect.x = 0i64;
  *(_QWORD *)&v2->mPaintEffect.z = 0i64;
  v2->mCharredEffectInitialAmount = 0.0;
  LOBYTE(v2->mCharredEffectElapsedTime) = 0;
  *(_DWORD *)&v2->mDamaged = 0;
  do
  {
    v2->mCharacterMarkers[0].mBoneIndex = 0;
    *(_WORD *)v2->mCharacterMarkers[0].mValue = 0;
    v2 = (CharacterDamageRig *)((char *)v2 + 28);
    --v1;
  }
  while ( v1 );
}

// File Line: 474
// RVA: 0x39DF50
void __fastcall DamageRig::DamageRig(DamageRig *this)
{
  DamageRig *v1; // rdx
  _QWORD *v2; // rax
  signed __int64 v3; // rcx

  v1 = this;
  *(_QWORD *)&this->mGrimeFactor = 1065353216i64;
  *(_QWORD *)&this->mNumDamageMarkers = 0i64;
  this->mDamageMarkers = 0i64;
  this->mTriggeredMarkers = 0i64;
  this->mAggregateDamage = 0.0;
  v2 = (_QWORD *)this->mWeightCache;
  v3 = 16i64;
  do
  {
    *v2 = 0i64;
    v2[1] = 0i64;
    v2[2] = 0i64;
    v2 += 8;
    *(v2 - 5) = 0i64;
    *(v2 - 4) = 0i64;
    *(v2 - 3) = 0i64;
    *(v2 - 2) = 0i64;
    *(v2 - 1) = 0i64;
    --v3;
  }
  while ( v3 );
  v1->mDamageOverride = 0.0;
  v1->mBurnedOut = 0;
}

// File Line: 508
// RVA: 0x39F980
void __fastcall DamageRig::~DamageRig(DamageRig *this)
{
  DamageRig *v1; // rdi
  DamageRig::DamageMarker *v2; // rcx
  __int64 v3; // rbx
  unsigned int *v4; // rcx

  v1 = this;
  v2 = this->mDamageMarkers;
  if ( v2 )
    operator delete[](v2);
  if ( v1->mTriggeredMarkers )
  {
    v3 = 0i64;
    if ( v1->mNumTriggeredMarkers )
    {
      do
      {
        v4 = v1->mTriggeredMarkers[v3].mTriggerIndices;
        if ( v4 )
          operator delete[](v4);
        v3 = (unsigned int)(v3 + 1);
      }
      while ( (unsigned int)v3 < v1->mNumTriggeredMarkers );
    }
    operator delete[](v1->mTriggeredMarkers);
  }
}

// File Line: 524
// RVA: 0x3AEDD0
void __fastcall DamageRig::SetAllDamageMarkers(DamageRig *this, UFG::VehicleEffectsComponent *const vehicle, float damage, bool triggers_only, bool suppress_effects)
{
  signed __int64 v5; // rdi
  DamageRig *v6; // rbx
  unsigned int v7; // esi
  bool v8; // r15
  UFG::VehicleEffectsComponent *v9; // r14
  float v10; // xmm0_4
  signed __int64 v11; // rcx

  v5 = 0i64;
  v6 = this;
  v7 = 0;
  v8 = triggers_only;
  v9 = vehicle;
  if ( this->mNumTriggeredMarkers )
  {
    do
      DamageRig::ActivateTriggerMarkerByIndex(v6, v7++, damage, v9, suppress_effects == 0);
    while ( v7 < v6->mNumTriggeredMarkers );
  }
  if ( !v8 && v6->mNumDamageMarkers > 0 )
  {
    do
    {
      if ( damage <= 0.0 )
      {
        v10 = 0.0;
      }
      else
      {
        v10 = damage;
        if ( damage >= 1.0 )
          v10 = *(float *)&FLOAT_1_0;
      }
      v11 = v5;
      v5 = (unsigned int)(v5 + 1);
      v6->mDamageMarkers[v11].mValue = v10;
    }
    while ( (unsigned int)v5 < v6->mNumDamageMarkers );
  }
}

// File Line: 540
// RVA: 0x3AF020
void __fastcall DamageRig::SetDamageMarker(DamageRig *this, UFG::VehicleEffectsComponent *const vehicle, const unsigned int name_uid, float damage, bool affect_triggers, bool suppress_effects)
{
  unsigned int v6; // er10
  __int64 v7; // r9
  UFG::VehicleEffectsComponent *v8; // rbx
  DamageRig *v9; // r11
  unsigned int v10; // edx
  unsigned int *v11; // rax
  unsigned int v12; // ecx
  DamageRig::DamageMarker *v13; // rdx
  unsigned int *v14; // rax
  float v15; // xmm0_4

  v6 = this->mNumTriggeredMarkers;
  v7 = 0i64;
  v8 = vehicle;
  v9 = this;
  v10 = 0;
  if ( !v6 )
  {
LABEL_5:
    v12 = this->mNumDamageMarkers;
    if ( !v12 )
      return;
    v13 = v9->mDamageMarkers;
    v14 = &v13->mNameUID;
    while ( *v14 != name_uid )
    {
      v7 = (unsigned int)(v7 + 1);
      v14 += 9;
      if ( (unsigned int)v7 >= v12 )
        return;
    }
    if ( damage <= 0.0 )
    {
      damage = 0.0;
    }
    else
    {
      v15 = *(float *)&FLOAT_1_0;
      if ( damage >= 1.0 )
      {
LABEL_16:
        v13[v7].mValue = v15;
        if ( affect_triggers )
          DamageRig::UpdateTriggerMarkers(v9, v8, 0.0, suppress_effects);
        return;
      }
    }
    v15 = damage;
    goto LABEL_16;
  }
  v11 = &this->mTriggeredMarkers->mNameUID;
  while ( *v11 != name_uid )
  {
    ++v10;
    v11 += 12;
    if ( v10 >= v6 )
      goto LABEL_5;
  }
  DamageRig::ActivateTriggerMarkerByIndex(this, v10, damage, v8, suppress_effects == 0);
}

// File Line: 562
// RVA: 0x3B4DE0
void __fastcall DamageRig::UpdateTriggerMarkers(DamageRig *this, UFG::VehicleEffectsComponent *const vehicle, float estImpulse, bool suppressEffects)
{
  __int64 v4; // r15
  bool v5; // r14
  UFG::VehicleEffectsComponent *v6; // rbp
  DamageRig *v7; // rdi
  float v8; // xmm0_4
  DamageRig::TriggeredMarker *v9; // rbx
  unsigned int v10; // eax
  unsigned int *v11; // rdx
  __int64 v12; // r8
  __int64 v13; // rax
  float v14; // xmm1_4
  float v15; // xmm7_4
  float v16; // xmm6_4
  unsigned int v17; // edx
  UFG::qBaseTreeRB *v18; // rax
  unsigned int v19; // edx
  UFG::qBaseTreeRB *v20; // rax
  UFG::qBaseNodeRB *v21; // rbx
  signed __int64 i; // rsi
  unsigned int v23; // ecx
  unsigned int v24; // edx
  unsigned int *v25; // rax

  v4 = 0i64;
  v5 = suppressEffects;
  v6 = vehicle;
  v7 = this;
  if ( this->mNumTriggeredMarkers )
  {
    do
    {
      v8 = 0.0;
      v9 = &v7->mTriggeredMarkers[v4];
      v10 = v9->mNumTriggers;
      if ( v10 )
      {
        v11 = v9->mTriggerIndices;
        v12 = v10;
        do
        {
          v13 = *v11;
          ++v11;
          v8 = v8 + v7->mDamageMarkers[v13].mValue;
          --v12;
        }
        while ( v12 );
      }
      v14 = v9->mDamageScalar;
      v15 = v9->mValue;
      v16 = 0.0;
      if ( v14 > 0.0 )
        v16 = v8 / v14;
      if ( v16 <= v15 )
        v16 = v9->mValue;
      if ( v16 >= 1.0 )
        v16 = *(float *)&FLOAT_1_0;
      v9->mValue = v16;
      if ( v15 >= 0.66000003 || v16 < 0.66000003 )
      {
        if ( v15 < 0.33000001 && v16 >= 0.33000001 && !v5 )
          DamageRig::PlayDamageSfx(v7, v9);
      }
      else if ( v6 )
      {
        if ( !v5 )
        {
          DamageRig::PlayDamageSfx(v7, v9);
          UFG::VehicleEffectsComponent::BreakGlassFX(v6, v9->mBoneIndex, v16 - v15);
        }
        if ( estImpulse > 10.0 )
        {
          v17 = v6->mDamageTransferUID;
          if ( v17 != -1 )
          {
            if ( v17 )
            {
              v18 = UFG::qBaseTreeRB::Get(&UFG::VehicleEffectManager::m_Instance->mDamageTransferNodes.mTree, v17);
              if ( v18 )
              {
                v19 = v9->mNameUID;
                if ( v19 )
                {
                  v20 = UFG::qBaseTreeRB::Get((UFG::qBaseTreeRB *)((char *)v18 + 32), v19);
                  if ( v20 )
                  {
                    v21 = v20->mNULL.mChild[0];
                    for ( i = (signed __int64)&v20->mNULL; v21 != (UFG::qBaseNodeRB *)i; v21 = v21->mChild[0] )
                    {
                      v23 = v7->mNumTriggeredMarkers;
                      v24 = 0;
                      if ( v23 )
                      {
                        v25 = &v7->mTriggeredMarkers->mNameUID;
                        while ( *v25 != LODWORD(v21->mChild[1]) )
                        {
                          ++v24;
                          v25 += 12;
                          if ( v24 >= v23 )
                            goto LABEL_29;
                        }
                        DamageRig::ActivateTriggerMarkerByIndex(v7, v24, 1.0, v6, v5 == 0);
                      }
LABEL_29:
                      ;
                    }
                  }
                }
              }
            }
          }
        }
      }
      v4 = (unsigned int)(v4 + 1);
    }
    while ( (unsigned int)v4 < v7->mNumTriggeredMarkers );
  }
}

// File Line: 644
// RVA: 0x3A1EE0
void __fastcall DamageRig::ApplyDamageForce(DamageRig *this, UFG::qVector3 *force_position, const float force, const float estImpulse, UFG::VehicleEffectsComponent *const vehicle)
{
  float v5; // xmm6_4
  __int64 v6; // r9
  float v7; // xmm7_4
  float v8; // xmm8_4
  DamageRig::DamageMarker *v9; // rax
  __m128 v10; // xmm2
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm5_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm0_4
  float v17; // xmm0_4

  v5 = force;
  if ( this->mDamageMarkers )
  {
    v6 = 0i64;
    if ( this->mNumDamageMarkers )
    {
      v7 = (float)(force * 0.10000001) + 0.2;
      v8 = 1.0 / (float)((float)((float)(force * 0.35000002) + 0.75) - v7);
      do
      {
        v9 = this->mDamageMarkers;
        v10 = (__m128)LODWORD(v9[v6].mPosition.y);
        v11 = v9[v6].mPosition.x - force_position->x;
        v10.m128_f32[0] = (float)((float)((float)(v10.m128_f32[0] - force_position->y)
                                        * (float)(v10.m128_f32[0] - force_position->y))
                                + (float)(v11 * v11))
                        + (float)((float)(v9[v6].mPosition.z - force_position->z)
                                * (float)(v9[v6].mPosition.z - force_position->z));
        v12 = (float)(COERCE_FLOAT(_mm_sqrt_ps(v10)) - v7) * v8;
        if ( v12 <= 0.0 )
        {
          v12 = 0.0;
        }
        else if ( v12 >= 1.0 )
        {
          v12 = *(float *)&FLOAT_1_0;
        }
        v13 = v9[v6].mDamageScalar;
        v14 = 1.0 - v12;
        v15 = 0.0;
        if ( v13 > 0.0 )
        {
          if ( v14 <= 0.0 )
            v16 = 0.0;
          else
            v16 = v14;
          if ( v16 >= (float)(1.0 - v9[v6].mValue) )
            v16 = 1.0 - v9[v6].mValue;
          v15 = (float)(v16 * v5) / v13;
        }
        v17 = v15 + v9[v6].mValue;
        v9[v6].mValue = v17;
        if ( v17 <= 0.0 )
        {
          v17 = 0.0;
        }
        else if ( v17 >= 1.0 )
        {
          v17 = *(float *)&FLOAT_1_0;
        }
        v9[v6].mValue = v17;
        v6 = (unsigned int)(v6 + 1);
        this->mAggregateDamage = v17 + this->mAggregateDamage;
      }
      while ( (unsigned int)v6 < this->mNumDamageMarkers );
    }
    DamageRig::UpdateTriggerMarkers(this, vehicle, estImpulse, 0);
  }
}

// File Line: 679
// RVA: 0x3A7EA0
float __fastcall DamageRig::GetDamageAtPosition(DamageRig *this, UFG::qVector3 *pos)
{
  UFG::qVector3 *v2; // r10
  DamageRig *v3; // r11
  unsigned int v5; // er9
  unsigned int v6; // ebx
  signed __int64 v7; // rax
  float v8; // xmm4_4
  DamageRig::DamageMarker *v9; // rax
  float v10; // xmm7_4
  float v11; // xmm8_4
  float v12; // xmm9_4
  signed __int64 v13; // rcx
  float *v14; // rdx
  __int64 v15; // r8
  __m128 v16; // xmm2
  float v17; // xmm2_4
  float v18; // xmm4_4
  __m128 v19; // xmm2
  float v20; // xmm2_4
  float v21; // xmm4_4
  __m128 v22; // xmm2
  float v23; // xmm2_4
  float v24; // xmm4_4
  __m128 v25; // xmm2
  float v26; // xmm2_4
  float *v27; // rdx
  __int64 v28; // rax
  __m128 v29; // xmm2
  float v30; // xmm2_4

  v2 = pos;
  v3 = this;
  if ( this->mAggregateDamage <= 0.0 )
    return 0.0;
  v5 = this->mNumDamageMarkers;
  v6 = 0;
  v7 = 0i64;
  v8 = 0.0;
  if ( (signed int)this->mNumDamageMarkers >= 4 )
  {
    v9 = this->mDamageMarkers;
    v10 = pos->x;
    v11 = pos->y;
    v12 = pos->z;
    v13 = (signed __int64)&v9[1].mPosition.z;
    v14 = &v9->mValue;
    LODWORD(v9) = ((v5 - 4) >> 2) + 1;
    v15 = (unsigned int)v9;
    v6 = 4 * (_DWORD)v9;
    v7 = 4i64 * (unsigned int)v9;
    do
    {
      v16 = (__m128)*(unsigned int *)(v13 - 40);
      v16.m128_f32[0] = (float)((float)((float)(v16.m128_f32[0] - v11) * (float)(v16.m128_f32[0] - v11))
                              + (float)((float)(v14[3] - v10) * (float)(v14[3] - v10)))
                      + (float)((float)(*(float *)(v13 - 36) - v12) * (float)(*(float *)(v13 - 36) - v12));
      if ( v16.m128_f32[0] >= 4.0 )
        v17 = 0.0;
      else
        v17 = (float)(1.0 - (float)(1.0 / (float)((float)(1.0 / COERCE_FLOAT(_mm_sqrt_ps(v16))) * 2.0))) * *v14;
      v18 = v8 + v17;
      v19 = (__m128)*(unsigned int *)(v13 - 4);
      v19.m128_f32[0] = (float)((float)((float)(v19.m128_f32[0] - v11) * (float)(v19.m128_f32[0] - v11))
                              + (float)((float)(*(float *)(v13 - 8) - v10) * (float)(*(float *)(v13 - 8) - v10)))
                      + (float)((float)(*(float *)v13 - v12) * (float)(*(float *)v13 - v12));
      if ( v19.m128_f32[0] >= 4.0 )
        v20 = 0.0;
      else
        v20 = (float)(1.0 - (float)(1.0 / (float)((float)(1.0 / COERCE_FLOAT(_mm_sqrt_ps(v19))) * 2.0)))
            * *(float *)(v13 - 20);
      v21 = v18 + v20;
      v22 = (__m128)*(unsigned int *)(v13 + 32);
      v22.m128_f32[0] = (float)((float)((float)(v22.m128_f32[0] - v11) * (float)(v22.m128_f32[0] - v11))
                              + (float)((float)(*(float *)(v13 + 28) - v10) * (float)(*(float *)(v13 + 28) - v10)))
                      + (float)((float)(*(float *)(v13 + 36) - v12) * (float)(*(float *)(v13 + 36) - v12));
      if ( v22.m128_f32[0] >= 4.0 )
        v23 = 0.0;
      else
        v23 = (float)(1.0 - (float)(1.0 / (float)((float)(1.0 / COERCE_FLOAT(_mm_sqrt_ps(v22))) * 2.0)))
            * *(float *)(v13 + 16);
      v24 = v21 + v23;
      v25 = (__m128)*(unsigned int *)(v13 + 68);
      v25.m128_f32[0] = (float)((float)((float)(v25.m128_f32[0] - v11) * (float)(v25.m128_f32[0] - v11))
                              + (float)((float)(*(float *)(v13 + 64) - v10) * (float)(*(float *)(v13 + 64) - v10)))
                      + (float)((float)(*(float *)(v13 + 72) - v12) * (float)(*(float *)(v13 + 72) - v12));
      if ( v25.m128_f32[0] >= 4.0 )
        v26 = 0.0;
      else
        v26 = (float)(1.0 - (float)(1.0 / (float)((float)(1.0 / COERCE_FLOAT(_mm_sqrt_ps(v25))) * 2.0)))
            * *(float *)(v13 + 52);
      v14 += 36;
      v13 += 144i64;
      v8 = v24 + v26;
      --v15;
    }
    while ( v15 );
  }
  if ( v6 < v5 )
  {
    v27 = (float *)(&v3->mDamageMarkers->mBoneIndex + 9 * v7 + 6);
    v28 = v5 - v6;
    do
    {
      v29 = (__m128)*((unsigned int *)v27 - 1);
      v29.m128_f32[0] = (float)((float)((float)(v29.m128_f32[0] - v2->y) * (float)(v29.m128_f32[0] - v2->y))
                              + (float)((float)(*(v27 - 2) - v2->x) * (float)(*(v27 - 2) - v2->x)))
                      + (float)((float)(*v27 - v2->z) * (float)(*v27 - v2->z));
      if ( v29.m128_f32[0] >= 4.0 )
        v30 = 0.0;
      else
        v30 = (float)(1.0 - (float)(1.0 / (float)((float)(1.0 / COERCE_FLOAT(_mm_sqrt_ps(v29))) * 2.0))) * *(v27 - 5);
      v27 += 9;
      v8 = v8 + v30;
      --v28;
    }
    while ( v28 );
  }
  return v8;
}

// File Line: 701
// RVA: 0x3A0870
void __fastcall DamageRig::ActivateTriggerMarker(DamageRig *this, UFG::qVector3 *position, UFG::VehicleEffectsComponent *const vehicle, bool bHighLODPlayFX)
{
  UFG::VehicleEffectsComponent *v4; // rsi
  bool v5; // di
  DamageRig *v6; // rbx
  unsigned int index; // [rsp+30h] [rbp-18h]

  v4 = vehicle;
  v5 = bHighLODPlayFX;
  v6 = this;
  if ( DamageRig::GetTriggerMarkerIndex(this, position, &index) == 1 )
    DamageRig::ActivateTriggerMarkerByIndex(v6, index, 1.0, v4, v5);
}

// File Line: 712
// RVA: 0x3A99B0
char __fastcall DamageRig::GetTriggerMarkerIndex(DamageRig *this, UFG::qVector3 *position, unsigned int *index)
{
  unsigned int v3; // ebx
  unsigned int *v4; // r14
  UFG::qVector3 *v5; // rdi
  DamageRig *v6; // rbp
  float v7; // xmm3_4
  int v8; // er10
  signed __int64 v9; // r11
  unsigned int v10; // er9
  signed __int64 v11; // rax
  DamageRig::TriggeredMarker *v12; // rax
  float v13; // xmm4_4
  float v14; // xmm5_4
  signed int v15; // er8
  float v16; // xmm6_4
  signed __int64 v17; // rcx
  signed __int64 v18; // rdx
  __m128 v19; // xmm2
  float v20; // xmm1_4
  __m128 v21; // xmm2
  float v22; // xmm1_4
  __m128 v23; // xmm2
  float v24; // xmm1_4
  __m128 v25; // xmm2
  float v26; // xmm1_4
  signed __int64 v27; // rdx
  float *v28; // rax
  __m128 v29; // xmm2
  float v30; // xmm1_4

  v3 = this->mNumTriggeredMarkers;
  v4 = index;
  v5 = position;
  v6 = this;
  if ( !v3 )
    return 0;
  v7 = FLOAT_1000000_0;
  v8 = 0;
  v9 = 0i64;
  v10 = 0;
  v11 = 0i64;
  if ( (signed int)v3 >= 4 )
  {
    v12 = this->mTriggeredMarkers;
    v13 = position->x;
    v14 = position->y;
    v15 = 2;
    v16 = position->z;
    v17 = (signed __int64)&v12[1];
    v18 = (signed __int64)&v12[1].mPosition.z;
    v11 = 4i64 * (((v3 - 4) >> 2) + 1);
    do
    {
      v19 = (__m128)*(unsigned int *)(v18 - 52);
      v19.m128_f32[0] = (float)((float)((float)(v19.m128_f32[0] - v14) * (float)(v19.m128_f32[0] - v14))
                              + (float)((float)(*(float *)(v17 - 36) - v13) * (float)(*(float *)(v17 - 36) - v13)))
                      + (float)((float)(*(float *)(v18 - 48) - v16) * (float)(*(float *)(v18 - 48) - v16));
      LODWORD(v20) = (unsigned __int128)_mm_sqrt_ps(v19);
      if ( v20 < v7 )
      {
        v7 = v20;
        v8 = v10;
        v9 = v17 - 48;
      }
      v21 = (__m128)*(unsigned int *)(v18 - 4);
      v21.m128_f32[0] = (float)((float)((float)(v21.m128_f32[0] - v14) * (float)(v21.m128_f32[0] - v14))
                              + (float)((float)(*(float *)(v18 - 8) - v13) * (float)(*(float *)(v18 - 8) - v13)))
                      + (float)((float)(*(float *)v18 - v16) * (float)(*(float *)v18 - v16));
      LODWORD(v22) = (unsigned __int128)_mm_sqrt_ps(v21);
      if ( v22 < v7 )
      {
        v7 = v22;
        v8 = v15 - 1;
        v9 = v17;
      }
      v23 = (__m128)*(unsigned int *)(v18 + 44);
      v23.m128_f32[0] = (float)((float)((float)(v23.m128_f32[0] - v14) * (float)(v23.m128_f32[0] - v14))
                              + (float)((float)(*(float *)(v18 + 40) - v13) * (float)(*(float *)(v18 + 40) - v13)))
                      + (float)((float)(*(float *)(v18 + 48) - v16) * (float)(*(float *)(v18 + 48) - v16));
      LODWORD(v24) = (unsigned __int128)_mm_sqrt_ps(v23);
      if ( v24 < v7 )
      {
        v7 = v24;
        v8 = v15;
        v9 = v17 + 48;
      }
      v25 = (__m128)*(unsigned int *)(v18 + 92);
      v25.m128_f32[0] = (float)((float)((float)(v25.m128_f32[0] - v14) * (float)(v25.m128_f32[0] - v14))
                              + (float)((float)(*(float *)(v18 + 88) - v13) * (float)(*(float *)(v18 + 88) - v13)))
                      + (float)((float)(*(float *)(v18 + 96) - v16) * (float)(*(float *)(v18 + 96) - v16));
      LODWORD(v26) = (unsigned __int128)_mm_sqrt_ps(v25);
      if ( v26 < v7 )
      {
        v7 = v26;
        v8 = v15 + 1;
        v9 = v17 + 96;
      }
      v10 += 4;
      v17 += 192i64;
      v18 += 192i64;
      v15 += 4;
    }
    while ( v10 < v3 - 3 );
  }
  if ( v10 < v3 )
  {
    v27 = (signed __int64)&v6->mTriggeredMarkers[v11];
    v28 = (float *)(v27 + 20);
    do
    {
      v29 = (__m128)*((unsigned int *)v28 - 1);
      v29.m128_f32[0] = (float)((float)((float)(v29.m128_f32[0] - v5->y) * (float)(v29.m128_f32[0] - v5->y))
                              + (float)((float)(*(v28 - 2) - v5->x) * (float)(*(v28 - 2) - v5->x)))
                      + (float)((float)(*v28 - v5->z) * (float)(*v28 - v5->z));
      LODWORD(v30) = (unsigned __int128)_mm_sqrt_ps(v29);
      if ( v30 < v7 )
      {
        v7 = v30;
        v8 = v10;
        v9 = v27;
      }
      ++v10;
      v27 += 48i64;
      v28 += 12;
    }
    while ( v10 < v3 );
  }
  if ( !v9 )
    return 0;
  *v4 = v8;
  return 1;
}

// File Line: 758
// RVA: 0x3A2470
void __fastcall DamageRig::ApplyTriggerMarkerDamageByIndex(DamageRig *this, const unsigned int index, float damage, UFG::VehicleEffectsComponent *const vehicle, bool bHighLODPlayFX)
{
  DamageRig::ActivateTriggerMarkerByIndex(
    this,
    index,
    damage + this->mTriggeredMarkers[index].mValue,
    vehicle,
    bHighLODPlayFX);
}

// File Line: 770
// RVA: 0x3A0920
void __fastcall DamageRig::ActivateTriggerMarkerByIndex(DamageRig *this, const unsigned int index, float damage, UFG::VehicleEffectsComponent *const vehicle, bool bHighLODPlayFX)
{
  UFG::VehicleEffectsComponent *v5; // rdi
  float v6; // xmm6_4
  DamageRig::TriggeredMarker *v7; // rbx
  float v8; // xmm1_4

  v5 = vehicle;
  v6 = damage;
  v7 = &this->mTriggeredMarkers[index];
  if ( bHighLODPlayFX )
  {
    v8 = v7->mValue;
    if ( v8 > 0.66000003 || damage <= 0.66000003 )
    {
      if ( v8 < 0.33000001 && damage >= 0.33000001 )
      {
        DamageRig::PlayDamageSfx(this, &this->mTriggeredMarkers[index]);
        if ( v5 )
          UFG::VehicleEffectsComponent::ShatterGlassFX(v5, v7->mBoneIndex);
      }
    }
    else
    {
      DamageRig::PlayDamageSfx(this, &this->mTriggeredMarkers[index]);
      if ( v5 )
        UFG::VehicleEffectsComponent::BreakGlassFX(v5, v7->mBoneIndex, damage - v7->mValue);
    }
  }
  if ( damage <= 0.0 )
  {
    v6 = 0.0;
  }
  else if ( damage >= 1.0 )
  {
    LODWORD(v7->mValue) = (_DWORD)FLOAT_1_0;
    return;
  }
  v7->mValue = v6;
}

// File Line: 803
// RVA: 0x3A08D0
void __fastcall DamageRig::ActivateTriggerMarker(DamageRig *this, const unsigned int name_uid, UFG::VehicleEffectsComponent *const vehicle, bool bHighLODPlayFX)
{
  unsigned int v4; // er10
  unsigned int v5; // er11
  unsigned int v6; // edx
  unsigned int *v7; // rax

  v4 = this->mNumTriggeredMarkers;
  v5 = name_uid;
  v6 = 0;
  if ( v4 )
  {
    v7 = &this->mTriggeredMarkers->mNameUID;
    while ( *v7 != v5 )
    {
      ++v6;
      v7 += 12;
      if ( v6 >= v4 )
        return;
    }
    DamageRig::ActivateTriggerMarkerByIndex(this, v6, 1.0, vehicle, bHighLODPlayFX);
  }
}

// File Line: 815
// RVA: 0x3A9F20
void __fastcall DamageRig::GetWeightList(DamageRig *this, float *remapped_array, const unsigned int num_remapped_bones, const char *bone_remap_array)
{
  unsigned int v4; // er11
  DamageRig *v5; // r10
  float *v6; // rsi
  unsigned int v7; // ecx
  __int64 v8; // rax
  unsigned int i; // edx
  __int64 v10; // rax
  __int64 v11; // rcx
  float *v12; // rdi
  __int64 v13; // rdi
  signed __int64 v14; // rdx
  unsigned int v15; // eax
  __int64 v16; // rbx
  __int64 v17; // rax
  const char *v18; // rdx
  __int64 v19; // r8
  signed __int64 v20; // rdi
  __int64 v21; // rax
  float v22; // [rsp+10h] [rbp+8h]

  v4 = 0;
  v5 = this;
  v6 = remapped_array;
  v7 = 0;
  if ( v5->mNumDamageMarkers )
  {
    do
    {
      v8 = v7++;
      v5->mWeightCache[v5->mDamageMarkers[v8].mBoneIndex] = v5->mDamageMarkers[v8].mSignal
                                                          + v5->mDamageMarkers[v8].mValue;
    }
    while ( v7 < v5->mNumDamageMarkers );
  }
  for ( i = 0;
        i < v5->mNumTriggeredMarkers;
        v5->mWeightCache[v5->mTriggeredMarkers[v10].mBoneIndex] = v5->mTriggeredMarkers[v10].mSignal
                                                                + v5->mTriggeredMarkers[v10].mValue )
  {
    v10 = i++;
  }
  v22 = v5->mDamageOverride;
  if ( v5->mBurnedOut )
  {
    v22 = *(float *)&FLOAT_1_0;
    goto LABEL_8;
  }
  if ( v5->mDamageOverride > 0.0 )
  {
LABEL_8:
    if ( num_remapped_bones )
    {
      v11 = num_remapped_bones;
      v12 = v6;
      while ( v11 )
      {
        *v12 = v22;
        ++v12;
        --v11;
      }
    }
    return;
  }
  v13 = 0i64;
  if ( (signed int)num_remapped_bones >= 4 )
  {
    v14 = (signed __int64)(v6 + 2);
    v15 = ((num_remapped_bones - 4) >> 2) + 1;
    v16 = v15;
    v4 = 4 * v15;
    do
    {
      v17 = (unsigned __int8)bone_remap_array[v13];
      v13 += 4i64;
      v14 += 16i64;
      *(float *)(v14 - 24) = v5->mWeightCache[v17];
      *(float *)(v14 - 20) = v5->mWeightCache[(unsigned __int8)bone_remap_array[v13 - 3]];
      *(float *)(v14 - 16) = v5->mWeightCache[(unsigned __int8)bone_remap_array[v13 - 2]];
      *(float *)(v14 - 12) = v5->mWeightCache[(unsigned __int8)bone_remap_array[v13 - 1]];
      --v16;
    }
    while ( v16 );
  }
  if ( v4 < num_remapped_bones )
  {
    v18 = &bone_remap_array[v13];
    v19 = num_remapped_bones - v4;
    v20 = (signed __int64)&v6[v13];
    do
    {
      v21 = *(unsigned __int8 *)v18;
      v20 += 4i64;
      ++v18;
      *(float *)(v20 - 4) = v5->mWeightCache[v21];
      --v19;
    }
    while ( v19 );
  }
}

// File Line: 850
// RVA: 0x3AF1A0
void __fastcall DamageRig::SetDetachableBones(DamageRig *this, Skeleton *skeleton)
{
  Skeleton *v2; // rbp
  DamageRig *v3; // rsi
  UFG::qSymbolUC *v4; // rbx
  signed __int64 v5; // rdi
  unsigned int v6; // eax

  v2 = skeleton;
  v3 = this;
  UFG::qMemSet(this->mDetachableBoneArray, 0, 0x100u);
  v4 = detachableBoneNameUIDS;
  v5 = 13i64;
  do
  {
    v6 = Skeleton::GetBoneID(v2, v4->mUID);
    if ( v6 <= 0xFF )
      v3->mDetachableBoneArray[v6] = 1;
    ++v4;
    --v5;
  }
  while ( v5 );
}

// File Line: 878
// RVA: 0x3A81A0
char __fastcall DamageRig::GetDamageMarkerIndex(DamageRig *this, const unsigned int name_uid, unsigned int *index)
{
  unsigned int v3; // er9
  unsigned int *v4; // rax

  v3 = 0;
  if ( !this->mNumDamageMarkers )
    return 0;
  v4 = &this->mDamageMarkers->mNameUID;
  while ( *v4 != name_uid )
  {
    ++v3;
    v4 += 9;
    if ( v3 >= this->mNumDamageMarkers )
      return 0;
  }
  *index = v3;
  return 1;
}

// File Line: 900
// RVA: 0x3A9740
char __fastcall DamageRig::GetTriggerMarkerHealth(DamageRig *this, UFG::qVector3 *position, float *health_output)
{
  unsigned int v3; // er11
  UFG::qVector3 *v4; // rbx
  DamageRig *v5; // rdi
  float v6; // xmm3_4
  unsigned int v7; // er10
  unsigned int v8; // er9
  signed __int64 v9; // rax
  float v10; // xmm4_4
  float v11; // xmm5_4
  float *v12; // rcx
  float v13; // xmm6_4
  signed int v14; // edx
  __m128 v15; // xmm2
  float v16; // xmm1_4
  __m128 v17; // xmm2
  float v18; // xmm1_4
  __m128 v19; // xmm2
  float v20; // xmm1_4
  __m128 v21; // xmm2
  float v22; // xmm1_4
  float *v23; // rdx
  __m128 v24; // xmm2
  float v25; // xmm1_4
  char result; // al

  v3 = this->mNumTriggeredMarkers;
  v4 = position;
  v5 = this;
  if ( !v3 )
    return 0;
  v6 = FLOAT_1000000_0;
  v7 = 0;
  v8 = 0;
  v9 = 0i64;
  if ( (signed int)v3 >= 4 )
  {
    v10 = position->x;
    v11 = position->y;
    v12 = &this->mTriggeredMarkers->mPosition.z;
    v13 = position->z;
    v14 = 2;
    v9 = 4i64 * (((v3 - 4) >> 2) + 1);
    do
    {
      v15 = (__m128)*((unsigned int *)v12 - 1);
      v15.m128_f32[0] = (float)((float)((float)(v15.m128_f32[0] - v11) * (float)(v15.m128_f32[0] - v11))
                              + (float)((float)(*(v12 - 2) - v10) * (float)(*(v12 - 2) - v10)))
                      + (float)((float)(*v12 - v13) * (float)(*v12 - v13));
      LODWORD(v16) = (unsigned __int128)_mm_sqrt_ps(v15);
      if ( v16 < v6 )
      {
        v6 = v16;
        v7 = v8;
      }
      v17 = (__m128)*((unsigned int *)v12 + 11);
      v17.m128_f32[0] = (float)((float)((float)(v17.m128_f32[0] - v11) * (float)(v17.m128_f32[0] - v11))
                              + (float)((float)(v12[10] - v10) * (float)(v12[10] - v10)))
                      + (float)((float)(v12[12] - v13) * (float)(v12[12] - v13));
      LODWORD(v18) = (unsigned __int128)_mm_sqrt_ps(v17);
      if ( v18 < v6 )
      {
        v6 = v18;
        v7 = v14 - 1;
      }
      v19 = (__m128)*((unsigned int *)v12 + 23);
      v19.m128_f32[0] = (float)((float)((float)(v19.m128_f32[0] - v11) * (float)(v19.m128_f32[0] - v11))
                              + (float)((float)(v12[22] - v10) * (float)(v12[22] - v10)))
                      + (float)((float)(v12[24] - v13) * (float)(v12[24] - v13));
      LODWORD(v20) = (unsigned __int128)_mm_sqrt_ps(v19);
      if ( v20 < v6 )
      {
        v6 = v20;
        v7 = v14;
      }
      v21 = (__m128)*((unsigned int *)v12 + 35);
      v21.m128_f32[0] = (float)((float)((float)(v21.m128_f32[0] - v11) * (float)(v21.m128_f32[0] - v11))
                              + (float)((float)(v12[34] - v10) * (float)(v12[34] - v10)))
                      + (float)((float)(v12[36] - v13) * (float)(v12[36] - v13));
      LODWORD(v22) = (unsigned __int128)_mm_sqrt_ps(v21);
      if ( v22 < v6 )
      {
        v6 = v22;
        v7 = v14 + 1;
      }
      v8 += 4;
      v12 += 48;
      v14 += 4;
    }
    while ( v8 < v3 - 3 );
  }
  if ( v8 < v3 )
  {
    v23 = &v5->mTriggeredMarkers[v9].mPosition.z;
    do
    {
      v24 = (__m128)*((unsigned int *)v23 - 1);
      v24.m128_f32[0] = (float)((float)((float)(v24.m128_f32[0] - v4->y) * (float)(v24.m128_f32[0] - v4->y))
                              + (float)((float)(*(v23 - 2) - v4->x) * (float)(*(v23 - 2) - v4->x)))
                      + (float)((float)(*v23 - v4->z) * (float)(*v23 - v4->z));
      LODWORD(v25) = (unsigned __int128)_mm_sqrt_ps(v24);
      if ( v25 < v6 )
      {
        v6 = v25;
        v7 = v8;
      }
      ++v8;
      v23 += 12;
    }
    while ( v8 < v3 );
  }
  result = 1;
  *health_output = v5->mTriggeredMarkers[v7].mValue;
  return result;
}

// File Line: 928
// RVA: 0x3A9970
char __fastcall DamageRig::GetTriggerMarkerHealth(DamageRig *this, const unsigned int name_uid, float *health_output)
{
  unsigned int v3; // er9
  __int64 v4; // rax
  DamageRig::TriggeredMarker *v5; // r10
  unsigned int *v6; // rcx
  DamageRig::TriggeredMarker *v8; // rcx

  v3 = this->mNumTriggeredMarkers;
  if ( !v3 )
    return 0;
  v4 = 0i64;
  if ( !v3 )
    return 0;
  v5 = this->mTriggeredMarkers;
  v6 = &v5->mNameUID;
  while ( *v6 != name_uid )
  {
    v4 = (unsigned int)(v4 + 1);
    v6 += 12;
    if ( (unsigned int)v4 >= v3 )
      return 0;
  }
  v8 = &v5[v4];
  if ( !v8 )
    return 0;
  *health_output = v8->mValue;
  return 1;
}

// File Line: 954
// RVA: 0x3AF7E0
void __fastcall DamageRig::SetSignal(DamageRig *this, const unsigned int name_uid, float value)
{
  unsigned int v3; // er8
  __int64 v4; // rax
  DamageRig::TriggeredMarker *v5; // r9
  unsigned int *v6; // rcx

  v3 = this->mNumTriggeredMarkers;
  if ( v3 )
  {
    v4 = 0i64;
    if ( v3 )
    {
      v5 = this->mTriggeredMarkers;
      v6 = &v5->mNameUID;
      while ( *v6 != name_uid )
      {
        v4 = (unsigned int)(v4 + 1);
        v6 += 12;
        if ( (unsigned int)v4 >= v3 )
          return;
      }
      v5[v4].mSignal = value;
    }
  }
}

// File Line: 969
// RVA: 0x3AE0A0
void __fastcall DamageRig::RemoveSignal(DamageRig *this, const unsigned int name_uid, float value)
{
  unsigned int v3; // er8
  __int64 v4; // rax
  DamageRig::TriggeredMarker *v5; // r9
  unsigned int *v6; // rcx
  float v7; // xmm0_4

  v3 = this->mNumTriggeredMarkers;
  if ( v3 )
  {
    v4 = 0i64;
    if ( v3 )
    {
      v5 = this->mTriggeredMarkers;
      v6 = &v5->mNameUID;
      while ( *v6 != name_uid )
      {
        v4 = (unsigned int)(v4 + 1);
        v6 += 12;
        if ( (unsigned int)v4 >= v3 )
          return;
      }
      v7 = v5[v4].mSignal;
      if ( v7 >= value )
        v5[v4].mSignal = v7 - value;
    }
  }
}

// File Line: 992
// RVA: 0x3ACE10
void __fastcall DamageRig::PlayDamageSfx(DamageRig *this, DamageRig::TriggeredMarker *marker)
{
  DamageRig::TriggeredMarker *v2; // rsi
  __int64 v3; // rbx
  unsigned int v4; // eax
  char v5; // bp
  __int64 v6; // rdi
  unsigned int *v7; // rcx
  unsigned int *v8; // rcx
  UFG::OneShotHandle pHandle; // [rsp+58h] [rbp+10h]

  if ( marker )
  {
    v2 = marker;
    v3 = 0i64;
    pHandle.m_pOneShot = 0i64;
    UFG::OneShotPool::GetOneShotHandle(&pHandle, &marker->mPosition);
    if ( UFG::OneShotHandle::IsValid(&pHandle) )
    {
      v4 = _S10_3;
      if ( !(_S10_3 & 1) )
      {
        _S10_3 |= 1u;
        lightUIDs[0] = UFG::qStringHashUpper32("D_WinLight_L01", 0xFFFFFFFF);
        dword_1423CF0EC = UFG::qStringHashUpper32("D_WinLight_R01", 0xFFFFFFFF);
        dword_1423CF0F0 = UFG::qStringHashUpper32("D_WinLight_L02", 0xFFFFFFFF);
        dword_1423CF0F4 = UFG::qStringHashUpper32("D_WinLight_R02", 0xFFFFFFFF);
        dword_1423CF0F8 = UFG::qStringHashUpper32("D_WinLight_L03", 0xFFFFFFFF);
        dword_1423CF0FC = UFG::qStringHashUpper32("D_WinLight_R03", 0xFFFFFFFF);
        dword_1423CF100 = 0;
        v4 = _S10_3;
      }
      if ( !(v4 & 2) )
      {
        _S10_3 = v4 | 2;
        play_glass_carwindow_break = UFG::TiDo::CalcWwiseUid("play_glass_carwindow_break");
        v4 = _S10_3;
      }
      if ( !(v4 & 4) )
      {
        _S10_3 = v4 | 4;
        play_tire_iron_car = UFG::TiDo::CalcWwiseUid("play_tire_iron_car");
        v4 = _S10_3;
      }
      v5 = 0;
      v6 = 0i64;
      if ( windowUIDs[0] )
      {
        v7 = windowUIDs;
        do
        {
          if ( *v7 == v2->mNameUID )
          {
            UFG::OneShot::Play(pHandle.m_pOneShot, play_glass_carwindow_break);
            v5 = 1;
          }
          v7 = &windowUIDs[++v6];
        }
        while ( *v7 );
        v4 = _S10_3;
      }
      if ( !(v4 & 8) )
      {
        _S10_3 = v4 | 8;
        play_veh_light_shatter = UFG::TiDo::CalcWwiseUid("play_veh_light_shatter");
      }
      if ( lightUIDs[0] )
      {
        v8 = lightUIDs;
        do
        {
          if ( *v8 == v2->mNameUID )
          {
            UFG::OneShot::Play(pHandle.m_pOneShot, play_veh_light_shatter);
            v5 = 1;
          }
          v8 = &lightUIDs[++v3];
        }
        while ( *v8 );
      }
      if ( !v5 )
        UFG::OneShot::Play(pHandle.m_pOneShot, play_tire_iron_car);
    }
    UFG::OneShotHandle::Release(&pHandle);
  }
}

