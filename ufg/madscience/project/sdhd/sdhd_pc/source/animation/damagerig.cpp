// File Line: 69
// RVA: 0x14BF9B0
__int64 dynamic_initializer_for__windowUIDs__()
{
  __int64 result; // rax

  windowUIDs[0] = UFG::qStringHashUpper32("D_WinF", -1);
  dword_1423CEED4 = UFG::qStringHashUpper32("D_WinB", -1);
  dword_1423CEED8 = UFG::qStringHashUpper32("D_WinL01_Hijack", -1);
  dword_1423CEEDC = UFG::qStringHashUpper32("D_WinR01_Hijack", -1);
  dword_1423CEEE0 = UFG::qStringHashUpper32("D_WinL02", -1);
  dword_1423CEEE4 = UFG::qStringHashUpper32("D_WinR02", -1);
  dword_1423CEEE8 = UFG::qStringHashUpper32("D_WinL03", -1);
  dword_1423CEEEC = UFG::qStringHashUpper32("D_WinR03", -1);
  dword_1423CEEF0 = UFG::qStringHashUpper32("D_WinL04", -1);
  dword_1423CEEF4 = UFG::qStringHashUpper32("D_WinR04", -1);
  dword_1423CEEF8 = UFG::qStringHashUpper32("D_WinL05", -1);
  dword_1423CEEFC = UFG::qStringHashUpper32("D_WinR05", -1);
  dword_1423CEF00 = UFG::qStringHashUpper32("D_WinL06", -1);
  dword_1423CEF04 = UFG::qStringHashUpper32("D_WinR06", -1);
  dword_1423CEF08 = UFG::qStringHashUpper32("D_WinL07", -1);
  dword_1423CEF0C = UFG::qStringHashUpper32("D_WinR07", -1);
  dword_1423CEF10 = UFG::qStringHashUpper32("D_WinL08", -1);
  dword_1423CEF14 = UFG::qStringHashUpper32("D_WinR08", -1);
  dword_1423CEF18 = UFG::qStringHashUpper32("D_WinL09", -1);
  result = UFG::qStringHashUpper32("D_WinR09", -1);
  dword_1423CEF20 = 0;
  dword_1423CEF1C = result;
  return result;
}

// File Line: 94
// RVA: 0x14BF7F0
__int64 dynamic_initializer_for__transferWindowUIDs__()
{
  __int64 result; // rax

  transferWindowUIDs[0] = UFG::qStringHashUpper32("D_WinB", -1);
  dword_1423CEF34 = UFG::qStringHashUpper32("D_WinF", -1);
  dword_1423CEF38 = UFG::qStringHashUpper32("D_WinR01_Hijack", -1);
  dword_1423CEF3C = UFG::qStringHashUpper32("D_WinL01_Hijack", -1);
  dword_1423CEF40 = UFG::qStringHashUpper32("D_WinR02", -1);
  dword_1423CEF44 = UFG::qStringHashUpper32("D_WinL02", -1);
  dword_1423CEF48 = UFG::qStringHashUpper32("D_WinR03", -1);
  dword_1423CEF4C = UFG::qStringHashUpper32("D_WinL03", -1);
  dword_1423CEF50 = UFG::qStringHashUpper32("D_WinR04", -1);
  dword_1423CEF54 = UFG::qStringHashUpper32("D_WinL04", -1);
  dword_1423CEF58 = UFG::qStringHashUpper32("D_WinR05", -1);
  dword_1423CEF5C = UFG::qStringHashUpper32("D_WinL05", -1);
  dword_1423CEF60 = UFG::qStringHashUpper32("D_WinR06", -1);
  dword_1423CEF64 = UFG::qStringHashUpper32("D_WinL06", -1);
  dword_1423CEF68 = UFG::qStringHashUpper32("D_WinR07", -1);
  dword_1423CEF6C = UFG::qStringHashUpper32("D_WinL07", -1);
  dword_1423CEF70 = UFG::qStringHashUpper32("D_WinR08", -1);
  dword_1423CEF74 = UFG::qStringHashUpper32("D_WinL08", -1);
  dword_1423CEF78 = UFG::qStringHashUpper32("D_WinR09", -1);
  result = UFG::qStringHashUpper32("D_WinL09", -1);
  dword_1423CEF80 = 0;
  dword_1423CEF7C = result;
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
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__detachableBoneNameUIDS__);
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
  CharacterDamageRig::VisualDamageTarget *p; // rcx

  p = this->mVisualDamageTargets.p;
  if ( p )
    operator delete[](p);
  this->mVisualDamageTargets.p = 0i64;
  *(_QWORD *)&this->mVisualDamageTargets.size = 0i64;
}

// File Line: 153
// RVA: 0x3AAE10
void __fastcall CharacterDamageRig::InitCharacterBoneNormals(CharacterDamageRig *this)
{
  char *mValue; // rax
  __int64 v2; // rdx

  mValue = this->mCharacterMarkers[0].mValue;
  v2 = 26i64;
  do
  {
    *(_DWORD *)mValue = 0;
    *((_WORD *)mValue + 2) = 0;
    mValue += 28;
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
  float y; // xmm0_4
  float z; // xmm1_4
  float mDamageScale; // eax
  char *mValue; // rdx
  __int64 v7; // rcx
  char v8; // al

  this->mPaintEffectApplied = source->mPaintEffectApplied;
  v2 = (char *)source - (char *)this;
  y = source->mPaintEffect.y;
  z = source->mPaintEffect.z;
  this->mPaintEffect.x = source->mPaintEffect.x;
  this->mPaintEffect.y = y;
  this->mPaintEffect.z = z;
  this->mCharredEffectAmount = source->mCharredEffectAmount;
  this->mCharredEffectInitialAmount = source->mCharredEffectInitialAmount;
  this->mCharredEffectElapsedTime = source->mCharredEffectElapsedTime;
  this->mDamaged = source->mDamaged;
  mDamageScale = source->mDamageScale;
  mValue = this->mCharacterMarkers[0].mValue;
  this->mDamageScale = mDamageScale;
  v7 = 26i64;
  do
  {
    v8 = mValue[v2];
    mValue += 28;
    *(mValue - 28) = v8;
    *(mValue - 27) = mValue[v2 - 27];
    *(mValue - 26) = mValue[v2 - 26];
    *(mValue - 25) = mValue[v2 - 25];
    *(mValue - 24) = mValue[v2 - 24];
    *(mValue - 23) = mValue[v2 - 23];
    --v7;
  }
  while ( v7 );
}

// File Line: 201
// RVA: 0x3A7C30
void __fastcall CharacterDamageRig::GetCharacterWeightList(
        CharacterDamageRig *this,
        float *remapped_array,
        __int64 num_remapped_bones,
        const char *bone_remap_array)
{
  float *v5; // rbx
  int v6; // r10d
  __int64 v7; // rax
  unsigned int i; // edx
  __int64 v9; // rax

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
        for ( i = 0; i < 8; ++i )
        {
          v9 = v6 + i;
          remapped_array[v9] = 0.0;
        }
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
void __fastcall CharacterDamageRig::ApplyDamageVector(
        CharacterDamageRig *this,
        Creature *creature,
        UFG::qVector4 *hitPositionWS,
        UFG::qVector4 *hitNormalWS,
        float damageAmount,
        float health)
{
  float mDamageScale; // xmm0_4
  float v9; // xmm11_4
  float v10; // xmm12_4
  float v11; // xmm13_4
  int m_size; // eax
  int v13; // ebx
  __int64 v14; // r14
  SkeletalPose *p_mPose; // r12
  char *mValue; // rsi
  float v17; // xmm3_4
  float v18; // xmm9_4
  char *v19; // rdx
  float *p_z; // rcx
  float v21; // xmm9_4
  __int64 v22; // r8
  float v23; // xmm3_4
  float v24; // xmm4_4
  float v25; // xmm5_4
  float v26; // xmm8_4
  float v27; // xmm2_4
  int v28; // eax
  bool v29; // zf
  char v30; // al
  UFG::qMatrix44 d; // [rsp+20h] [rbp-E0h] BYREF
  UFG::qMatrix44 matrixWS; // [rsp+60h] [rbp-A0h] BYREF
  UFG::qMatrix44 matrixLS; // [rsp+A0h] [rbp-60h] BYREF

  if ( health > 0.40000001 )
    mDamageScale = 0.0;
  else
    mDamageScale = *(float *)&FLOAT_1_0;
  if ( mDamageScale <= this->mDamageScale )
    mDamageScale = this->mDamageScale;
  this->mDamageScale = mDamageScale;
  v9 = hitNormalWS->x * -1.0;
  v10 = hitNormalWS->y * -1.0;
  v11 = hitNormalWS->z * -1.0;
  m_size = creature->mPose.mRigHandle.mUFGSkeleton->mhkaSkeleton->m_bones.m_size;
  if ( m_size > 26 )
    m_size = 26;
  v13 = 0;
  v14 = m_size;
  if ( m_size > 0 )
  {
    p_mPose = &creature->mPose;
    mValue = this->mCharacterMarkers[0].mValue;
    do
    {
      SkeletalPose::GetPositionWS(p_mPose, v13, &matrixWS);
      v17 = (float)((float)((float)((float)(matrixWS.v3.y - hitPositionWS->y) * (float)(matrixWS.v3.y - hitPositionWS->y))
                          + (float)((float)(matrixWS.v3.x - hitPositionWS->x) * (float)(matrixWS.v3.x - hitPositionWS->x)))
                  + (float)((float)(matrixWS.v3.z - hitPositionWS->z) * (float)(matrixWS.v3.z - hitPositionWS->z)))
          + (float)((float)(matrixWS.v3.w - hitPositionWS->w) * (float)(matrixWS.v3.w - hitPositionWS->w));
      if ( v17 <= sDistanceFalloff )
      {
        v18 = 1.0 - (float)(v17 / sDistanceFalloff);
        SkeletalPose::GetPositionLS(p_mPose, v13, &matrixLS);
        UFG::qInverseAffine(&d, &matrixLS);
        v19 = mValue;
        p_z = &cBoneDamageNormals[0].z;
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
          v27 = (float)((float)((float)(v24 * *(p_z - 1)) + (float)(v23 * *(p_z - 2))) + (float)(v25 * *p_z))
              + (float)(v26 * p_z[1]);
          if ( v27 <= 0.0 )
          {
            v27 = 0.0;
          }
          else if ( v27 >= 1.0 )
          {
            v27 = *(float *)&FLOAT_1_0;
          }
          v28 = (int)(float)((float)((float)(1.0 - v27) * v21) * 255.0);
          v29 = *v19 + (_BYTE)v28 == 0;
          v30 = *v19 + v28;
          *v19 = v30;
          if ( v29 )
          {
            v30 = 0;
          }
          else if ( v30 == -1 )
          {
            v30 = -1;
          }
          *v19++ = v30;
          p_z += 4;
          --v22;
        }
        while ( v22 );
      }
      ++v13;
      mValue += 28;
      --v14;
    }
    while ( v14 );
  }
  this->mDamaged = 1;
}

// File Line: 331
// RVA: 0x3A1E40
void __fastcall CharacterDamageRig::ApplyBluntForceDamageToBone(
        CharacterDamageRig *this,
        Creature *creature,
        UFG::qVector4 *hitPositionWS,
        UFG::qVector4 *invHitNormal,
        float damage,
        float health)
{
  float y; // xmm1_4
  float z; // xmm0_4
  float w; // xmm1_4
  UFG::qVector4 v9; // [rsp+30h] [rbp-18h] BYREF

  y = hitPositionWS->y;
  v9.x = hitPositionWS->x;
  z = hitPositionWS->z;
  v9.y = y;
  w = hitPositionWS->w;
  v9.z = z;
  v9.w = w;
  CharacterDamageRig::ApplyDamageVector(this, creature, hitPositionWS, &v9, sMeleeDamageScalar * damage, health);
}

// File Line: 337
// RVA: 0x3AF920
void __fastcall CharacterDamageRig::SetVisualDamage(
        CharacterDamageRig *this,
        unsigned int bone_uid,
        const float damage,
        float duration)
{
  __int64 v4; // rbp
  int v6; // ebx
  __int64 v7; // rax
  unsigned int capacity; // edx
  __int64 size; // r15
  unsigned int v10; // esi
  unsigned int v11; // edx
  CharacterDamageRig::VisualDamageTarget *p; // rdx
  __int64 v13; // r8

  if ( bone_uid < 0x1A )
  {
    v4 = bone_uid;
    this->mDamageScale = 1.0;
    v6 = (int)(float)(damage * 255.0);
    if ( (_BYTE)v6 )
    {
      if ( (_BYTE)v6 == 0xFF )
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
      capacity = this->mVisualDamageTargets.capacity;
      size = this->mVisualDamageTargets.size;
      v10 = size + 1;
      if ( (int)size + 1 > capacity )
      {
        if ( capacity )
          v11 = 2 * capacity;
        else
          v11 = 1;
        for ( ; v11 < v10; v11 *= 2 )
          ;
        if ( v11 - v10 > 0x10000 )
          v11 = size + 65537;
        UFG::qArray<CharacterDamageRig::VisualDamageTarget,0>::Reallocate(
          &this->mVisualDamageTargets,
          v11,
          "qArray.Add");
      }
      p = this->mVisualDamageTargets.p;
      this->mVisualDamageTargets.size = v10;
      v13 = size;
      p[v13].duration = duration;
      p[v13].boneID = v4;
      p[v13].targetDamage = v6;
      p[v13].elapsedTime = 0.0;
      p[v13].initialDamage[0] = this->mCharacterMarkers[v4].mValue[0];
      p[v13].initialDamage[1] = this->mCharacterMarkers[v4].mValue[1];
      p[v13].initialDamage[2] = this->mCharacterMarkers[v4].mValue[2];
      p[v13].initialDamage[3] = this->mCharacterMarkers[v4].mValue[3];
      p[v13].initialDamage[4] = this->mCharacterMarkers[v4].mValue[4];
      p[v13].initialDamage[5] = this->mCharacterMarkers[v4].mValue[5];
    }
    if ( damage != 0.0 )
      this->mDamaged = 1;
  }
}

// File Line: 376
// RVA: 0x3B1160
void __fastcall CharacterDamageRig::Update(CharacterDamageRig *this, float delta_sec)
{
  unsigned int i; // r10d
  CharacterDamageRig::VisualDamageTarget *p; // rdx
  float v6; // xmm2_4
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm1_4
  float v10; // xmm1_4
  float v11; // xmm1_4
  float v12; // xmm1_4
  float v13; // xmm1_4
  CharacterDamageRig::VisualDamageTarget *v14; // rdx
  __int64 v15; // rcx
  unsigned int size; // eax
  float v17; // xmm5_4
  float v18; // xmm0_4

  for ( i = 0; (signed int)i < (signed int)this->mVisualDamageTargets.size; ++i )
  {
    p = this->mVisualDamageTargets.p;
    v6 = delta_sec + p[i].elapsedTime;
    p[i].elapsedTime = v6;
    v7 = v6 / p[i].duration;
    if ( v7 <= 0.0 )
    {
      v7 = 0.0;
    }
    else if ( v7 >= 1.0 )
    {
      v7 = *(float *)&FLOAT_1_0;
    }
    v8 = (float)(unsigned __int8)p[i].initialDamage[0];
    this->mCharacterMarkers[p[i].boneID].mValue[0] = (int)(float)((float)((float)((float)(unsigned __int8)p[i].targetDamage
                                                                                - v8)
                                                                        * v7)
                                                                + v8);
    v9 = (float)(unsigned __int8)p[i].initialDamage[1];
    this->mCharacterMarkers[p[i].boneID].mValue[1] = (int)(float)((float)((float)((float)(unsigned __int8)p[i].targetDamage
                                                                                - v9)
                                                                        * v7)
                                                                + v9);
    v10 = (float)(unsigned __int8)p[i].initialDamage[2];
    this->mCharacterMarkers[p[i].boneID].mValue[2] = (int)(float)((float)((float)((float)(unsigned __int8)p[i].targetDamage
                                                                                - v10)
                                                                        * v7)
                                                                + v10);
    v11 = (float)(unsigned __int8)p[i].initialDamage[3];
    this->mCharacterMarkers[p[i].boneID].mValue[3] = (int)(float)((float)((float)((float)(unsigned __int8)p[i].targetDamage
                                                                                - v11)
                                                                        * v7)
                                                                + v11);
    v12 = (float)(unsigned __int8)p[i].initialDamage[4];
    this->mCharacterMarkers[p[i].boneID].mValue[4] = (int)(float)((float)((float)((float)(unsigned __int8)p[i].targetDamage
                                                                                - v12)
                                                                        * v7)
                                                                + v12);
    v13 = (float)(unsigned __int8)p[i].initialDamage[5];
    this->mCharacterMarkers[p[i].boneID].mValue[5] = (int)(float)((float)((float)((float)(unsigned __int8)p[i].targetDamage
                                                                                - v13)
                                                                        * v7)
                                                                + v13);
    if ( p[i].duration < p[i].elapsedTime )
    {
      v14 = this->mVisualDamageTargets.p;
      v15 = this->mVisualDamageTargets.size - 1;
      v14[i].boneID = v14[this->mVisualDamageTargets.size - 1].boneID;
      v14[i].elapsedTime = v14[v15].elapsedTime;
      v14[i].duration = v14[v15].duration;
      *(_DWORD *)v14[i].initialDamage = *(_DWORD *)v14[v15].initialDamage;
      *(_DWORD *)&v14[i].initialDamage[4] = *(_DWORD *)&v14[v15].initialDamage[4];
      size = this->mVisualDamageTargets.size;
      if ( size > 1 )
        this->mVisualDamageTargets.size = size - 1;
      else
        this->mVisualDamageTargets.size = 0;
      --i;
    }
  }
  if ( this->mCharredEffectAmount > 0.0 )
  {
    v17 = delta_sec + this->mCharredEffectElapsedTime;
    this->mCharredEffectElapsedTime = v17;
    v18 = (float)(1.0 - (float)(v17 * 0.011111111)) * this->mCharredEffectInitialAmount;
    if ( v18 <= 0.0 )
    {
      v18 = 0.0;
    }
    else if ( v18 >= 1.0 )
    {
      LODWORD(this->mCharredEffectAmount) = (_DWORD)FLOAT_1_0;
      return;
    }
    this->mCharredEffectAmount = v18;
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
  __int64 v1; // rax
  CharacterDamageRig *mValue; // rcx

  v1 = 26i64;
  mValue = (CharacterDamageRig *)this->mCharacterMarkers[0].mValue;
  *(_QWORD *)&mValue->mCharacterMarkers[25].mNameUID = 0i64;
  *(_QWORD *)&mValue->mPaintEffect.x = 0i64;
  *(_QWORD *)&mValue->mPaintEffect.z = 0i64;
  mValue->mCharredEffectInitialAmount = 0.0;
  LOBYTE(mValue->mCharredEffectElapsedTime) = 0;
  *(_DWORD *)&mValue->mDamaged = 0;
  do
  {
    mValue->mCharacterMarkers[0].mBoneIndex = 0;
    *(_WORD *)mValue->mCharacterMarkers[0].mValue = 0;
    mValue = (CharacterDamageRig *)((char *)mValue + 28);
    --v1;
  }
  while ( v1 );
}

// File Line: 474
// RVA: 0x39DF50
void __fastcall DamageRig::DamageRig(DamageRig *this)
{
  float *mWeightCache; // rax
  __int64 v3; // rcx

  *(_QWORD *)&this->mGrimeFactor = 1065353216i64;
  *(_QWORD *)&this->mNumDamageMarkers = 0i64;
  this->mDamageMarkers = 0i64;
  this->mTriggeredMarkers = 0i64;
  this->mAggregateDamage = 0.0;
  mWeightCache = this->mWeightCache;
  v3 = 16i64;
  do
  {
    *(_QWORD *)mWeightCache = 0i64;
    *((_QWORD *)mWeightCache + 1) = 0i64;
    *((_QWORD *)mWeightCache + 2) = 0i64;
    mWeightCache += 16;
    *((_QWORD *)mWeightCache - 5) = 0i64;
    *((_QWORD *)mWeightCache - 4) = 0i64;
    *((_QWORD *)mWeightCache - 3) = 0i64;
    *((_QWORD *)mWeightCache - 2) = 0i64;
    *((_QWORD *)mWeightCache - 1) = 0i64;
    --v3;
  }
  while ( v3 );
  this->mDamageOverride = 0.0;
  this->mBurnedOut = 0;
}

// File Line: 508
// RVA: 0x39F980
void __fastcall DamageRig::~DamageRig(DamageRig *this)
{
  DamageRig::DamageMarker *mDamageMarkers; // rcx
  __int64 i; // rbx
  unsigned int *mTriggerIndices; // rcx

  mDamageMarkers = this->mDamageMarkers;
  if ( mDamageMarkers )
    operator delete[](mDamageMarkers);
  if ( this->mTriggeredMarkers )
  {
    for ( i = 0i64; (unsigned int)i < this->mNumTriggeredMarkers; i = (unsigned int)(i + 1) )
    {
      mTriggerIndices = this->mTriggeredMarkers[i].mTriggerIndices;
      if ( mTriggerIndices )
        operator delete[](mTriggerIndices);
    }
    operator delete[](this->mTriggeredMarkers);
  }
}

// File Line: 524
// RVA: 0x3AEDD0
void __fastcall DamageRig::SetAllDamageMarkers(
        DamageRig *this,
        UFG::VehicleEffectsComponent *const vehicle,
        float damage,
        bool triggers_only,
        bool suppress_effects)
{
  __int64 v5; // rdi
  unsigned int i; // esi
  float v10; // xmm0_4
  __int64 v11; // rcx

  v5 = 0i64;
  for ( i = 0; i < this->mNumTriggeredMarkers; ++i )
    DamageRig::ActivateTriggerMarkerByIndex(this, i, damage, vehicle, !suppress_effects);
  if ( !triggers_only && this->mNumDamageMarkers )
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
      this->mDamageMarkers[v11].mValue = v10;
    }
    while ( (unsigned int)v5 < this->mNumDamageMarkers );
  }
}

// File Line: 540
// RVA: 0x3AF020
void __fastcall DamageRig::SetDamageMarker(
        DamageRig *this,
        UFG::VehicleEffectsComponent *const vehicle,
        const unsigned int name_uid,
        float damage,
        bool affect_triggers,
        bool suppress_effects)
{
  unsigned int mNumTriggeredMarkers; // r10d
  __int64 v7; // r9
  unsigned int v10; // edx
  unsigned int *p_mNameUID; // rax
  unsigned int mNumDamageMarkers; // ecx
  DamageRig::DamageMarker *mDamageMarkers; // rdx
  unsigned int *i; // rax
  float v15; // xmm0_4

  mNumTriggeredMarkers = this->mNumTriggeredMarkers;
  v7 = 0i64;
  v10 = 0;
  if ( !mNumTriggeredMarkers )
  {
LABEL_5:
    mNumDamageMarkers = this->mNumDamageMarkers;
    if ( !mNumDamageMarkers )
      return;
    mDamageMarkers = this->mDamageMarkers;
    for ( i = &mDamageMarkers->mNameUID; *i != name_uid; i += 9 )
    {
      v7 = (unsigned int)(v7 + 1);
      if ( (unsigned int)v7 >= mNumDamageMarkers )
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
        mDamageMarkers[v7].mValue = v15;
        if ( affect_triggers )
          DamageRig::UpdateTriggerMarkers(this, vehicle, 0.0, suppress_effects);
        return;
      }
    }
    v15 = damage;
    goto LABEL_16;
  }
  p_mNameUID = &this->mTriggeredMarkers->mNameUID;
  while ( *p_mNameUID != name_uid )
  {
    ++v10;
    p_mNameUID += 12;
    if ( v10 >= mNumTriggeredMarkers )
      goto LABEL_5;
  }
  DamageRig::ActivateTriggerMarkerByIndex(this, v10, damage, vehicle, !suppress_effects);
}

// File Line: 562
// RVA: 0x3B4DE0
void __fastcall DamageRig::UpdateTriggerMarkers(
        DamageRig *this,
        UFG::VehicleEffectsComponent *const vehicle,
        float estImpulse,
        bool suppressEffects)
{
  __int64 i; // r15
  float v8; // xmm0_4
  DamageRig::TriggeredMarker *v9; // rbx
  unsigned int mNumTriggers; // eax
  unsigned int *mTriggerIndices; // rdx
  __int64 v12; // r8
  __int64 v13; // rax
  float mDamageScalar; // xmm1_4
  float mValue; // xmm7_4
  float v16; // xmm6_4
  unsigned int mDamageTransferUID; // edx
  UFG::qBaseTreeRB *v18; // rax
  unsigned int mNameUID; // edx
  UFG::qBaseTreeRB *v20; // rax
  UFG::qBaseNodeRB *v21; // rbx
  UFG::qBaseNodeRB *j; // rsi
  unsigned int mNumTriggeredMarkers; // ecx
  unsigned int v24; // edx
  unsigned int *p_mNameUID; // rax

  for ( i = 0i64; (unsigned int)i < this->mNumTriggeredMarkers; i = (unsigned int)(i + 1) )
  {
    v8 = 0.0;
    v9 = &this->mTriggeredMarkers[i];
    mNumTriggers = v9->mNumTriggers;
    if ( mNumTriggers )
    {
      mTriggerIndices = v9->mTriggerIndices;
      v12 = mNumTriggers;
      do
      {
        v13 = *mTriggerIndices++;
        v8 = v8 + this->mDamageMarkers[v13].mValue;
        --v12;
      }
      while ( v12 );
    }
    mDamageScalar = v9->mDamageScalar;
    mValue = v9->mValue;
    v16 = 0.0;
    if ( mDamageScalar > 0.0 )
      v16 = v8 / mDamageScalar;
    if ( v16 <= mValue )
      v16 = v9->mValue;
    if ( v16 >= 1.0 )
      v16 = *(float *)&FLOAT_1_0;
    v9->mValue = v16;
    if ( mValue >= 0.66000003 || v16 < 0.66000003 )
    {
      if ( mValue < 0.33000001 && v16 >= 0.33000001 && !suppressEffects )
        DamageRig::PlayDamageSfx(this, v9);
    }
    else if ( vehicle )
    {
      if ( !suppressEffects )
      {
        DamageRig::PlayDamageSfx(this, v9);
        UFG::VehicleEffectsComponent::BreakGlassFX(vehicle, v9->mBoneIndex, v16 - mValue);
      }
      if ( estImpulse > 10.0 )
      {
        mDamageTransferUID = vehicle->mDamageTransferUID;
        if ( mDamageTransferUID != -1 )
        {
          if ( mDamageTransferUID )
          {
            v18 = UFG::qBaseTreeRB::Get(
                    &UFG::VehicleEffectManager::m_Instance->mDamageTransferNodes.mTree,
                    mDamageTransferUID);
            if ( v18 )
            {
              mNameUID = v9->mNameUID;
              if ( mNameUID )
              {
                v20 = UFG::qBaseTreeRB::Get((UFG::qBaseTreeRB *)&v18->mNULL, mNameUID);
                if ( v20 )
                {
                  v21 = v20->mNULL.mChild[0];
                  for ( j = &v20->mNULL; v21 != j; v21 = v21->mChild[0] )
                  {
                    mNumTriggeredMarkers = this->mNumTriggeredMarkers;
                    v24 = 0;
                    if ( mNumTriggeredMarkers )
                    {
                      p_mNameUID = &this->mTriggeredMarkers->mNameUID;
                      while ( *p_mNameUID != LODWORD(v21->mChild[1]) )
                      {
                        ++v24;
                        p_mNameUID += 12;
                        if ( v24 >= mNumTriggeredMarkers )
                          goto LABEL_29;
                      }
                      DamageRig::ActivateTriggerMarkerByIndex(this, v24, 1.0, vehicle, !suppressEffects);
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
  }
}

// File Line: 644
// RVA: 0x3A1EE0
void __fastcall DamageRig::ApplyDamageForce(
        DamageRig *this,
        UFG::qVector3 *force_position,
        const float force,
        float estImpulse,
        UFG::VehicleEffectsComponent *const vehicle)
{
  __int64 v6; // r9
  float v7; // xmm7_4
  float v8; // xmm8_4
  DamageRig::DamageMarker *mDamageMarkers; // rax
  __m128 y_low; // xmm2
  float v11; // xmm0_4
  float v12; // xmm0_4
  float mDamageScalar; // xmm5_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm0_4
  float v17; // xmm0_4

  if ( this->mDamageMarkers )
  {
    v6 = 0i64;
    if ( this->mNumDamageMarkers )
    {
      v7 = (float)(force * 0.10000001) + 0.2;
      v8 = 1.0 / (float)((float)((float)(force * 0.35000002) + 0.75) - v7);
      do
      {
        mDamageMarkers = this->mDamageMarkers;
        y_low = (__m128)LODWORD(mDamageMarkers[v6].mPosition.y);
        v11 = mDamageMarkers[v6].mPosition.x - force_position->x;
        y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - force_position->y)
                                          * (float)(y_low.m128_f32[0] - force_position->y))
                                  + (float)(v11 * v11))
                          + (float)((float)(mDamageMarkers[v6].mPosition.z - force_position->z)
                                  * (float)(mDamageMarkers[v6].mPosition.z - force_position->z));
        v12 = (float)(_mm_sqrt_ps(y_low).m128_f32[0] - v7) * v8;
        if ( v12 <= 0.0 )
        {
          v12 = 0.0;
        }
        else if ( v12 >= 1.0 )
        {
          v12 = *(float *)&FLOAT_1_0;
        }
        mDamageScalar = mDamageMarkers[v6].mDamageScalar;
        v14 = 1.0 - v12;
        v15 = 0.0;
        if ( mDamageScalar > 0.0 )
        {
          if ( v14 <= 0.0 )
            v16 = 0.0;
          else
            v16 = v14;
          if ( v16 >= (float)(1.0 - mDamageMarkers[v6].mValue) )
            v16 = 1.0 - mDamageMarkers[v6].mValue;
          v15 = (float)(v16 * force) / mDamageScalar;
        }
        v17 = v15 + mDamageMarkers[v6].mValue;
        mDamageMarkers[v6].mValue = v17;
        if ( v17 <= 0.0 )
        {
          v17 = 0.0;
        }
        else if ( v17 >= 1.0 )
        {
          v17 = *(float *)&FLOAT_1_0;
        }
        mDamageMarkers[v6].mValue = v17;
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
  unsigned int mNumDamageMarkers; // r9d
  unsigned int v6; // ebx
  __int64 v7; // rax
  float v8; // xmm4_4
  DamageRig::DamageMarker *mDamageMarkers; // rax
  float x; // xmm7_4
  float y; // xmm8_4
  float z; // xmm9_4
  float *p_z; // rcx
  float *p_mValue; // rdx
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

  if ( this->mAggregateDamage <= 0.0 )
    return 0.0;
  mNumDamageMarkers = this->mNumDamageMarkers;
  v6 = 0;
  v7 = 0i64;
  v8 = 0.0;
  if ( (int)this->mNumDamageMarkers >= 4 )
  {
    mDamageMarkers = this->mDamageMarkers;
    x = pos->x;
    y = pos->y;
    z = pos->z;
    p_z = &mDamageMarkers[1].mPosition.z;
    p_mValue = &mDamageMarkers->mValue;
    LODWORD(mDamageMarkers) = ((mNumDamageMarkers - 4) >> 2) + 1;
    v15 = (unsigned int)mDamageMarkers;
    v6 = 4 * (_DWORD)mDamageMarkers;
    v7 = 4i64 * (unsigned int)mDamageMarkers;
    do
    {
      v16 = (__m128)*((unsigned int *)p_z - 10);
      v16.m128_f32[0] = (float)((float)((float)(v16.m128_f32[0] - y) * (float)(v16.m128_f32[0] - y))
                              + (float)((float)(p_mValue[3] - x) * (float)(p_mValue[3] - x)))
                      + (float)((float)(*(p_z - 9) - z) * (float)(*(p_z - 9) - z));
      if ( v16.m128_f32[0] >= 4.0 )
        v17 = 0.0;
      else
        v17 = (float)(1.0 - (float)(1.0 / (float)((float)(1.0 / _mm_sqrt_ps(v16).m128_f32[0]) * 2.0))) * *p_mValue;
      v18 = v8 + v17;
      v19 = (__m128)*((unsigned int *)p_z - 1);
      v19.m128_f32[0] = (float)((float)((float)(v19.m128_f32[0] - y) * (float)(v19.m128_f32[0] - y))
                              + (float)((float)(*(p_z - 2) - x) * (float)(*(p_z - 2) - x)))
                      + (float)((float)(*p_z - z) * (float)(*p_z - z));
      if ( v19.m128_f32[0] >= 4.0 )
        v20 = 0.0;
      else
        v20 = (float)(1.0 - (float)(1.0 / (float)((float)(1.0 / _mm_sqrt_ps(v19).m128_f32[0]) * 2.0))) * *(p_z - 5);
      v21 = v18 + v20;
      v22 = (__m128)*((unsigned int *)p_z + 8);
      v22.m128_f32[0] = (float)((float)((float)(v22.m128_f32[0] - y) * (float)(v22.m128_f32[0] - y))
                              + (float)((float)(p_z[7] - x) * (float)(p_z[7] - x)))
                      + (float)((float)(p_z[9] - z) * (float)(p_z[9] - z));
      if ( v22.m128_f32[0] >= 4.0 )
        v23 = 0.0;
      else
        v23 = (float)(1.0 - (float)(1.0 / (float)((float)(1.0 / _mm_sqrt_ps(v22).m128_f32[0]) * 2.0))) * p_z[4];
      v24 = v21 + v23;
      v25 = (__m128)*((unsigned int *)p_z + 17);
      v25.m128_f32[0] = (float)((float)((float)(v25.m128_f32[0] - y) * (float)(v25.m128_f32[0] - y))
                              + (float)((float)(p_z[16] - x) * (float)(p_z[16] - x)))
                      + (float)((float)(p_z[18] - z) * (float)(p_z[18] - z));
      if ( v25.m128_f32[0] >= 4.0 )
        v26 = 0.0;
      else
        v26 = (float)(1.0 - (float)(1.0 / (float)((float)(1.0 / _mm_sqrt_ps(v25).m128_f32[0]) * 2.0))) * p_z[13];
      p_mValue += 36;
      p_z += 36;
      v8 = v24 + v26;
      --v15;
    }
    while ( v15 );
  }
  if ( v6 < mNumDamageMarkers )
  {
    v27 = &this->mDamageMarkers[v7].mPosition.z;
    v28 = mNumDamageMarkers - v6;
    do
    {
      v29 = (__m128)*((unsigned int *)v27 - 1);
      v29.m128_f32[0] = (float)((float)((float)(v29.m128_f32[0] - pos->y) * (float)(v29.m128_f32[0] - pos->y))
                              + (float)((float)(*(v27 - 2) - pos->x) * (float)(*(v27 - 2) - pos->x)))
                      + (float)((float)(*v27 - pos->z) * (float)(*v27 - pos->z));
      if ( v29.m128_f32[0] >= 4.0 )
        v30 = 0.0;
      else
        v30 = (float)(1.0 - (float)(1.0 / (float)((float)(1.0 / _mm_sqrt_ps(v29).m128_f32[0]) * 2.0))) * *(v27 - 5);
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
void __fastcall DamageRig::ActivateTriggerMarker(
        DamageRig *this,
        UFG::qVector3 *position,
        UFG::VehicleEffectsComponent *const vehicle,
        bool bHighLODPlayFX)
{
  unsigned int index[6]; // [rsp+30h] [rbp-18h] BYREF

  if ( DamageRig::GetTriggerMarkerIndex(this, position, index) )
    DamageRig::ActivateTriggerMarkerByIndex(this, index[0], 1.0, vehicle, bHighLODPlayFX);
}

// File Line: 712
// RVA: 0x3A99B0
char __fastcall DamageRig::GetTriggerMarkerIndex(DamageRig *this, UFG::qVector3 *position, unsigned int *index)
{
  unsigned int mNumTriggeredMarkers; // ebx
  float v7; // xmm3_4
  unsigned int v8; // r10d
  DamageRig::TriggeredMarker *v9; // r11
  unsigned int v10; // r9d
  __int64 v11; // rax
  DamageRig::TriggeredMarker *mTriggeredMarkers; // rax
  float x; // xmm4_4
  float y; // xmm5_4
  int v15; // r8d
  float z; // xmm6_4
  DamageRig::TriggeredMarker *v17; // rcx
  float *p_z; // rdx
  __m128 v19; // xmm2
  float v20; // xmm1_4
  __m128 v21; // xmm2
  float v22; // xmm1_4
  __m128 v23; // xmm2
  float v24; // xmm1_4
  __m128 v25; // xmm2
  float v26; // xmm1_4
  DamageRig::TriggeredMarker *v27; // rdx
  float *v28; // rax
  __m128 v29; // xmm2
  float v30; // xmm1_4

  mNumTriggeredMarkers = this->mNumTriggeredMarkers;
  if ( !mNumTriggeredMarkers )
    return 0;
  v7 = FLOAT_1000000_0;
  v8 = 0;
  v9 = 0i64;
  v10 = 0;
  v11 = 0i64;
  if ( (int)mNumTriggeredMarkers >= 4 )
  {
    mTriggeredMarkers = this->mTriggeredMarkers;
    x = position->x;
    y = position->y;
    v15 = 2;
    z = position->z;
    v17 = mTriggeredMarkers + 1;
    p_z = &mTriggeredMarkers[1].mPosition.z;
    v11 = 4i64 * (((mNumTriggeredMarkers - 4) >> 2) + 1);
    do
    {
      v19 = (__m128)*((unsigned int *)p_z - 13);
      v19.m128_f32[0] = (float)((float)((float)(v19.m128_f32[0] - y) * (float)(v19.m128_f32[0] - y))
                              + (float)((float)(v17[-1].mPosition.x - x) * (float)(v17[-1].mPosition.x - x)))
                      + (float)((float)(*(p_z - 12) - z) * (float)(*(p_z - 12) - z));
      v20 = _mm_sqrt_ps(v19).m128_f32[0];
      if ( v20 < v7 )
      {
        v7 = v20;
        v8 = v10;
        v9 = v17 - 1;
      }
      v21 = (__m128)*((unsigned int *)p_z - 1);
      v21.m128_f32[0] = (float)((float)((float)(v21.m128_f32[0] - y) * (float)(v21.m128_f32[0] - y))
                              + (float)((float)(*(p_z - 2) - x) * (float)(*(p_z - 2) - x)))
                      + (float)((float)(*p_z - z) * (float)(*p_z - z));
      v22 = _mm_sqrt_ps(v21).m128_f32[0];
      if ( v22 < v7 )
      {
        v7 = v22;
        v8 = v15 - 1;
        v9 = v17;
      }
      v23 = (__m128)*((unsigned int *)p_z + 11);
      v23.m128_f32[0] = (float)((float)((float)(v23.m128_f32[0] - y) * (float)(v23.m128_f32[0] - y))
                              + (float)((float)(p_z[10] - x) * (float)(p_z[10] - x)))
                      + (float)((float)(p_z[12] - z) * (float)(p_z[12] - z));
      v24 = _mm_sqrt_ps(v23).m128_f32[0];
      if ( v24 < v7 )
      {
        v7 = v24;
        v8 = v15;
        v9 = v17 + 1;
      }
      v25 = (__m128)*((unsigned int *)p_z + 23);
      v25.m128_f32[0] = (float)((float)((float)(v25.m128_f32[0] - y) * (float)(v25.m128_f32[0] - y))
                              + (float)((float)(p_z[22] - x) * (float)(p_z[22] - x)))
                      + (float)((float)(p_z[24] - z) * (float)(p_z[24] - z));
      v26 = _mm_sqrt_ps(v25).m128_f32[0];
      if ( v26 < v7 )
      {
        v7 = v26;
        v8 = v15 + 1;
        v9 = v17 + 2;
      }
      v10 += 4;
      v17 += 4;
      p_z += 48;
      v15 += 4;
    }
    while ( v10 < mNumTriggeredMarkers - 3 );
  }
  if ( v10 < mNumTriggeredMarkers )
  {
    v27 = &this->mTriggeredMarkers[v11];
    v28 = &v27->mPosition.z;
    do
    {
      v29 = (__m128)*((unsigned int *)v28 - 1);
      v29.m128_f32[0] = (float)((float)((float)(v29.m128_f32[0] - position->y) * (float)(v29.m128_f32[0] - position->y))
                              + (float)((float)(*(v28 - 2) - position->x) * (float)(*(v28 - 2) - position->x)))
                      + (float)((float)(*v28 - position->z) * (float)(*v28 - position->z));
      v30 = _mm_sqrt_ps(v29).m128_f32[0];
      if ( v30 < v7 )
      {
        v7 = v30;
        v8 = v10;
        v9 = v27;
      }
      ++v10;
      ++v27;
      v28 += 12;
    }
    while ( v10 < mNumTriggeredMarkers );
  }
  if ( !v9 )
    return 0;
  *index = v8;
  return 1;
}v28 += 12;
    }
    while ( v10 < mNumTriggeredMarkers );
  }
  if ( !v9 

// File Line: 758
// RVA: 0x3A2470
void __fastcall DamageRig::ApplyTriggerMarkerDamageByIndex(
        DamageRig *this,
        unsigned int index,
        float damage,
        UFG::VehicleEffectsComponent *const vehicle,
        bool bHighLODPlayFX)
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
void __fastcall DamageRig::ActivateTriggerMarkerByIndex(
        DamageRig *this,
        const unsigned int index,
        float damage,
        UFG::VehicleEffectsComponent *const vehicle,
        bool bHighLODPlayFX)
{
  float v6; // xmm6_4
  DamageRig::TriggeredMarker *v7; // rbx
  float mValue; // xmm1_4

  v6 = damage;
  v7 = &this->mTriggeredMarkers[index];
  if ( bHighLODPlayFX )
  {
    mValue = v7->mValue;
    if ( mValue > 0.66000003 || damage <= 0.66000003 )
    {
      if ( mValue < 0.33000001 && damage >= 0.33000001 )
      {
        DamageRig::PlayDamageSfx(this, &this->mTriggeredMarkers[index]);
        if ( vehicle )
          UFG::VehicleEffectsComponent::ShatterGlassFX(vehicle, v7->mBoneIndex);
      }
    }
    else
    {
      DamageRig::PlayDamageSfx(this, &this->mTriggeredMarkers[index]);
      if ( vehicle )
        UFG::VehicleEffectsComponent::BreakGlassFX(vehicle, v7->mBoneIndex, damage - v7->mValue);
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
void __fastcall DamageRig::ActivateTriggerMarker(
        DamageRig *this,
        const unsigned int name_uid,
        UFG::VehicleEffectsComponent *const vehicle,
        bool bHighLODPlayFX)
{
  unsigned int mNumTriggeredMarkers; // r10d
  unsigned int v6; // edx
  unsigned int *i; // rax

  mNumTriggeredMarkers = this->mNumTriggeredMarkers;
  v6 = 0;
  if ( mNumTriggeredMarkers )
  {
    for ( i = &this->mTriggeredMarkers->mNameUID; *i != name_uid; i += 12 )
    {
      if ( ++v6 >= mNumTriggeredMarkers )
        return;
    }
    DamageRig::ActivateTriggerMarkerByIndex(this, v6, 1.0, vehicle, bHighLODPlayFX);
  }
}

// File Line: 815
// RVA: 0x3A9F20
void __fastcall DamageRig::GetWeightList(
        DamageRig *this,
        float *remapped_array,
        int num_remapped_bones,
        const char *bone_remap_array)
{
  unsigned int v4; // r11d
  unsigned int i; // ecx
  __int64 v8; // rax
  unsigned int j; // edx
  __int64 v10; // rax
  __int64 v11; // rcx
  float *v12; // rdi
  __int64 v13; // rdi
  float *v14; // rdx
  unsigned int v15; // eax
  __int64 v16; // rbx
  __int64 v17; // rax
  const char *v18; // rdx
  __int64 v19; // r8
  float *v20; // rdi
  __int64 v21; // rax
  float mDamageOverride; // [rsp+10h] [rbp+8h]

  v4 = 0;
  for ( i = 0;
        i < this->mNumDamageMarkers;
        this->mWeightCache[this->mDamageMarkers[v8].mBoneIndex] = this->mDamageMarkers[v8].mSignal
                                                                + this->mDamageMarkers[v8].mValue )
  {
    v8 = i++;
  }
  for ( j = 0;
        j < this->mNumTriggeredMarkers;
        this->mWeightCache[this->mTriggeredMarkers[v10].mBoneIndex] = this->mTriggeredMarkers[v10].mSignal
                                                                    + this->mTriggeredMarkers[v10].mValue )
  {
    v10 = j++;
  }
  mDamageOverride = this->mDamageOverride;
  if ( this->mBurnedOut )
  {
    mDamageOverride = *(float *)&FLOAT_1_0;
    goto LABEL_8;
  }
  if ( this->mDamageOverride > 0.0 )
  {
LABEL_8:
    if ( num_remapped_bones )
    {
      v11 = (unsigned int)num_remapped_bones;
      v12 = remapped_array;
      while ( v11 )
      {
        *v12++ = mDamageOverride;
        --v11;
      }
    }
    return;
  }
  v13 = 0i64;
  if ( num_remapped_bones >= 4 )
  {
    v14 = remapped_array + 2;
    v15 = ((unsigned int)(num_remapped_bones - 4) >> 2) + 1;
    v16 = v15;
    v4 = 4 * v15;
    do
    {
      v17 = (unsigned __int8)bone_remap_array[v13];
      v13 += 4i64;
      v14 += 4;
      *(v14 - 6) = this->mWeightCache[v17];
      *(v14 - 5) = this->mWeightCache[(unsigned __int8)bone_remap_array[v13 - 3]];
      *(v14 - 4) = this->mWeightCache[(unsigned __int8)bone_remap_array[v13 - 2]];
      *(v14 - 3) = this->mWeightCache[(unsigned __int8)bone_remap_array[v13 - 1]];
      --v16;
    }
    while ( v16 );
  }
  if ( v4 < num_remapped_bones )
  {
    v18 = &bone_remap_array[v13];
    v19 = num_remapped_bones - v4;
    v20 = &remapped_array[v13];
    do
    {
      v21 = *(unsigned __int8 *)v18;
      ++v20;
      ++v18;
      *(v20 - 1) = this->mWeightCache[v21];
      --v19;
    }
    while ( v19 );
  }
}

// File Line: 850
// RVA: 0x3AF1A0
void __fastcall DamageRig::SetDetachableBones(DamageRig *this, Skeleton *skeleton)
{
  UFG::qSymbolUC *v4; // rbx
  __int64 v5; // rdi
  unsigned int BoneID; // eax

  UFG::qMemSet(this->mDetachableBoneArray, 0, 0x100u);
  v4 = detachableBoneNameUIDS;
  v5 = 13i64;
  do
  {
    BoneID = Skeleton::GetBoneID(skeleton, v4->mUID);
    if ( BoneID <= 0xFF )
      this->mDetachableBoneArray[BoneID] = 1;
    ++v4;
    --v5;
  }
  while ( v5 );
}

// File Line: 878
// RVA: 0x3A81A0
char __fastcall DamageRig::GetDamageMarkerIndex(DamageRig *this, const unsigned int name_uid, unsigned int *index)
{
  unsigned int v3; // r9d
  unsigned int *i; // rax

  v3 = 0;
  if ( !this->mNumDamageMarkers )
    return 0;
  for ( i = &this->mDamageMarkers->mNameUID; *i != name_uid; i += 9 )
  {
    if ( ++v3 >= this->mNumDamageMarkers )
      return 0;
  }
  *index = v3;
  return 1;
}

// File Line: 900
// RVA: 0x3A9740
char __fastcall DamageRig::GetTriggerMarkerHealth(DamageRig *this, UFG::qVector3 *position, float *health_output)
{
  unsigned int mNumTriggeredMarkers; // r11d
  float v6; // xmm3_4
  int v7; // r10d
  unsigned int v8; // r9d
  __int64 v9; // rax
  float x; // xmm4_4
  float y; // xmm5_4
  float *p_z; // rcx
  float z; // xmm6_4
  int v14; // edx
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

  mNumTriggeredMarkers = this->mNumTriggeredMarkers;
  if ( !mNumTriggeredMarkers )
    return 0;
  v6 = FLOAT_1000000_0;
  v7 = 0;
  v8 = 0;
  v9 = 0i64;
  if ( (int)mNumTriggeredMarkers >= 4 )
  {
    x = position->x;
    y = position->y;
    p_z = &this->mTriggeredMarkers->mPosition.z;
    z = position->z;
    v14 = 2;
    v9 = 4i64 * (((mNumTriggeredMarkers - 4) >> 2) + 1);
    do
    {
      v15 = (__m128)*((unsigned int *)p_z - 1);
      v15.m128_f32[0] = (float)((float)((float)(v15.m128_f32[0] - y) * (float)(v15.m128_f32[0] - y))
                              + (float)((float)(*(p_z - 2) - x) * (float)(*(p_z - 2) - x)))
                      + (float)((float)(*p_z - z) * (float)(*p_z - z));
      v16 = _mm_sqrt_ps(v15).m128_f32[0];
      if ( v16 < v6 )
      {
        v6 = v16;
        v7 = v8;
      }
      v17 = (__m128)*((unsigned int *)p_z + 11);
      v17.m128_f32[0] = (float)((float)((float)(v17.m128_f32[0] - y) * (float)(v17.m128_f32[0] - y))
                              + (float)((float)(p_z[10] - x) * (float)(p_z[10] - x)))
                      + (float)((float)(p_z[12] - z) * (float)(p_z[12] - z));
      v18 = _mm_sqrt_ps(v17).m128_f32[0];
      if ( v18 < v6 )
      {
        v6 = v18;
        v7 = v14 - 1;
      }
      v19 = (__m128)*((unsigned int *)p_z + 23);
      v19.m128_f32[0] = (float)((float)((float)(v19.m128_f32[0] - y) * (float)(v19.m128_f32[0] - y))
                              + (float)((float)(p_z[22] - x) * (float)(p_z[22] - x)))
                      + (float)((float)(p_z[24] - z) * (float)(p_z[24] - z));
      v20 = _mm_sqrt_ps(v19).m128_f32[0];
      if ( v20 < v6 )
      {
        v6 = v20;
        v7 = v14;
      }
      v21 = (__m128)*((unsigned int *)p_z + 35);
      v21.m128_f32[0] = (float)((float)((float)(v21.m128_f32[0] - y) * (float)(v21.m128_f32[0] - y))
                              + (float)((float)(p_z[34] - x) * (float)(p_z[34] - x)))
                      + (float)((float)(p_z[36] - z) * (float)(p_z[36] - z));
      v22 = _mm_sqrt_ps(v21).m128_f32[0];
      if ( v22 < v6 )
      {
        v6 = v22;
        v7 = v14 + 1;
      }
      v8 += 4;
      p_z += 48;
      v14 += 4;
    }
    while ( v8 < mNumTriggeredMarkers - 3 );
  }
  if ( v8 < mNumTriggeredMarkers )
  {
    v23 = &this->mTriggeredMarkers[v9].mPosition.z;
    do
    {
      v24 = (__m128)*((unsigned int *)v23 - 1);
      v24.m128_f32[0] = (float)((float)((float)(v24.m128_f32[0] - position->y) * (float)(v24.m128_f32[0] - position->y))
                              + (float)((float)(*(v23 - 2) - position->x) * (float)(*(v23 - 2) - position->x)))
                      + (float)((float)(*v23 - position->z) * (float)(*v23 - position->z));
      v25 = _mm_sqrt_ps(v24).m128_f32[0];
      if ( v25 < v6 )
      {
        v6 = v25;
        v7 = v8;
      }
      ++v8;
      v23 += 12;
    }
    while ( v8 < mNumTriggeredMarkers );
  }
  result = 1;
  *health_output = this->mTriggeredMarkers[v7].mValue;
  return result;
}

// File Line: 928
// RVA: 0x3A9970
char __fastcall DamageRig::GetTriggerMarkerHealth(DamageRig *this, const unsigned int name_uid, float *health_output)
{
  unsigned int mNumTriggeredMarkers; // r9d
  __int64 v4; // rax
  DamageRig::TriggeredMarker *mTriggeredMarkers; // r10
  unsigned int *i; // rcx
  DamageRig::TriggeredMarker *v8; // rcx

  mNumTriggeredMarkers = this->mNumTriggeredMarkers;
  if ( !mNumTriggeredMarkers )
    return 0;
  v4 = 0i64;
  mTriggeredMarkers = this->mTriggeredMarkers;
  for ( i = &mTriggeredMarkers->mNameUID; *i != name_uid; i += 12 )
  {
    v4 = (unsigned int)(v4 + 1);
    if ( (unsigned int)v4 >= mNumTriggeredMarkers )
      return 0;
  }
  v8 = &mTriggeredMarkers[v4];
  if ( !v8 )
    return 0;
  *health_output = v8->mValue;
  return 1;
}

// File Line: 954
// RVA: 0x3AF7E0
void __fastcall DamageRig::SetSignal(DamageRig *this, const unsigned int name_uid, float value)
{
  unsigned int mNumTriggeredMarkers; // r8d
  __int64 v4; // rax
  DamageRig::TriggeredMarker *mTriggeredMarkers; // r9
  unsigned int *i; // rcx

  mNumTriggeredMarkers = this->mNumTriggeredMarkers;
  if ( mNumTriggeredMarkers )
  {
    v4 = 0i64;
    mTriggeredMarkers = this->mTriggeredMarkers;
    for ( i = &mTriggeredMarkers->mNameUID; *i != name_uid; i += 12 )
    {
      v4 = (unsigned int)(v4 + 1);
      if ( (unsigned int)v4 >= mNumTriggeredMarkers )
        return;
    }
    mTriggeredMarkers[v4].mSignal = value;
  }
}

// File Line: 969
// RVA: 0x3AE0A0
void __fastcall DamageRig::RemoveSignal(DamageRig *this, const unsigned int name_uid, float value)
{
  unsigned int mNumTriggeredMarkers; // r8d
  __int64 v4; // rax
  DamageRig::TriggeredMarker *mTriggeredMarkers; // r9
  unsigned int *i; // rcx
  float mSignal; // xmm0_4

  mNumTriggeredMarkers = this->mNumTriggeredMarkers;
  if ( mNumTriggeredMarkers )
  {
    v4 = 0i64;
    mTriggeredMarkers = this->mTriggeredMarkers;
    for ( i = &mTriggeredMarkers->mNameUID; *i != name_uid; i += 12 )
    {
      v4 = (unsigned int)(v4 + 1);
      if ( (unsigned int)v4 >= mNumTriggeredMarkers )
        return;
    }
    mSignal = mTriggeredMarkers[v4].mSignal;
    if ( mSignal >= value )
      mTriggeredMarkers[v4].mSignal = mSignal - value;
  }
}

// File Line: 992
// RVA: 0x3ACE10
void __fastcall DamageRig::PlayDamageSfx(DamageRig *this, DamageRig::TriggeredMarker *marker)
{
  __int64 v3; // rbx
  unsigned int v4; // eax
  char v5; // bp
  __int64 v6; // rdi
  unsigned int *v7; // rcx
  unsigned int *v8; // rcx
  UFG::OneShotHandle pHandle; // [rsp+58h] [rbp+10h] BYREF

  if ( marker )
  {
    v3 = 0i64;
    pHandle.m_pOneShot = 0i64;
    UFG::OneShotPool::GetOneShotHandle(&pHandle, &marker->mPosition);
    if ( UFG::OneShotHandle::IsValid(&pHandle) )
    {
      v4 = _S10_3;
      if ( (_S10_3 & 1) == 0 )
      {
        _S10_3 |= 1u;
        lightUIDs[0] = UFG::qStringHashUpper32("D_WinLight_L01", -1);
        dword_1423CF0EC = UFG::qStringHashUpper32("D_WinLight_R01", -1);
        dword_1423CF0F0 = UFG::qStringHashUpper32("D_WinLight_L02", -1);
        dword_1423CF0F4 = UFG::qStringHashUpper32("D_WinLight_R02", -1);
        dword_1423CF0F8 = UFG::qStringHashUpper32("D_WinLight_L03", -1);
        dword_1423CF0FC = UFG::qStringHashUpper32("D_WinLight_R03", -1);
        dword_1423CF100 = 0;
        v4 = _S10_3;
      }
      if ( (v4 & 2) == 0 )
      {
        _S10_3 = v4 | 2;
        play_glass_carwindow_break = UFG::TiDo::CalcWwiseUid("play_glass_carwindow_break");
        v4 = _S10_3;
      }
      if ( (v4 & 4) == 0 )
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
          if ( *v7 == marker->mNameUID )
          {
            UFG::OneShot::Play(pHandle.m_pOneShot, play_glass_carwindow_break);
            v5 = 1;
          }
          v7 = &windowUIDs[++v6];
        }
        while ( *v7 );
        v4 = _S10_3;
      }
      if ( (v4 & 8) == 0 )
      {
        _S10_3 = v4 | 8;
        play_veh_light_shatter = UFG::TiDo::CalcWwiseUid("play_veh_light_shatter");
      }
      if ( lightUIDs[0] )
      {
        v8 = lightUIDs;
        do
        {
          if ( *v8 == marker->mNameUID )
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

