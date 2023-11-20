// File Line: 30
// RVA: 0x1B9350
void __fastcall Skeleton::Skeleton(Skeleton *this, const char *name)
{
  Skeleton *v2; // rbx
  unsigned int v3; // eax

  v2 = this;
  v3 = UFG::qStringHashUpper32(name, 0xFFFFFFFF);
  v2->mBoneScale = 1.0;
  v2->mNameUID = v3;
  v2->mhkaSkeleton = 0i64;
  v2->mBoneNameHashIDs = 0i64;
  v2->mWeightSetData = 0i64;
  v2->mInverseModelSpace = 0i64;
}

// File Line: 40
// RVA: 0x1B9330
void __fastcall Skeleton::Skeleton(Skeleton *this, unsigned int nameUID)
{
  this->mNameUID = nameUID;
  this->mBoneScale = 1.0;
  this->mhkaSkeleton = 0i64;
  this->mBoneNameHashIDs = 0i64;
  this->mWeightSetData = 0i64;
  this->mInverseModelSpace = 0i64;
}

// File Line: 57
// RVA: 0x1B9490
void __fastcall Skeleton::setHkaSkeleton(Skeleton *this, UFG::RigResource *res)
{
  this->mhkaSkeleton = res->mSkeleton;
  this->mBoneNameHashIDs = res->mBoneNameGuids;
  this->mBoneIDLookup = res->mBoneNameToIndexLookup;
  this->mInverseModelSpace = res->mInverseModelSpace;
}

// File Line: 114
// RVA: 0x1B93F0
void Skeleton::Init(void)
{
  hkVector4f v0; // xmm0
  hkQuaternionf v1; // xmm1
  hkVector4f v2; // xmm2
  __m128 *v3; // rax

  v0.m_quad = (__m128)hkQsTransformf_identityStorage.m_translation;
  v1.m_vec.m_quad = (__m128)hkQsTransformf_identityStorage.m_rotation;
  v2.m_quad = (__m128)hkQsTransformf_identityStorage.m_scale;
  v3 = &Skeleton::mIdentitySpace[0].m_scale.m_quad;
  do
  {
    v3[-2] = v0.m_quad;
    v3[-1] = v1.m_vec.m_quad;
    *(hkVector4f *)v3 = (hkVector4f)v2.m_quad;
    v3 += 3;
  }
  while ( (signed __int64)v3 < (signed __int64)&s_uBip01_L_UpperArmUID_0 );
}

// File Line: 123
// RVA: 0x1B9440
char __fastcall Skeleton::IsParent(Skeleton *this, int parentID, int childID)
{
  hkaSkeleton *v3; // r10

  if ( parentID < 0 )
    return 0;
  if ( childID < 0 )
    return 0;
  v3 = this->mhkaSkeleton;
  if ( !v3 || (childID & 0x8000u) != 0 )
    return 0;
  while ( (signed __int16)childID != parentID )
  {
    LOWORD(childID) = v3->m_parentIndices.m_data[(signed __int16)childID];
    if ( (childID & 0x8000u) != 0 )
      return 0;
  }
  return 1;
}

// File Line: 145
// RVA: 0x1B9390
signed __int64 __fastcall Skeleton::GetBoneID(Skeleton *this, const unsigned int boneUID)
{
  int v2; // er9
  int v3; // er8
  UFG::RigResource::BoneLookupEntry *v4; // r11
  int v5; // eax
  unsigned int v6; // ecx

  v2 = 0;
  v3 = this->mhkaSkeleton->m_bones.m_size - 1;
  if ( v3 < 0 )
    return 0xFFFFFFFFi64;
  v4 = this->mBoneIDLookup;
  while ( 1 )
  {
    v5 = (v3 + v2) / 2;
    v6 = v4[v5].guid;
    if ( boneUID <= v6 )
      break;
    v2 = v5 + 1;
LABEL_7:
    if ( v2 > v3 )
      return 0xFFFFFFFFi64;
  }
  if ( boneUID < v6 )
  {
    v3 = v5 - 1;
    goto LABEL_7;
  }
  return v4[v5].index;
}

