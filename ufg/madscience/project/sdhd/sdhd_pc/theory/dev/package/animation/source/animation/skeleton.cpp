// File Line: 30
// RVA: 0x1B9350
void __fastcall Skeleton::Skeleton(Skeleton *this, const char *name)
{
  unsigned int v3; // eax

  v3 = UFG::qStringHashUpper32(name, -1);
  this->mBoneScale = 1.0;
  this->mNameUID = v3;
  this->mhkaSkeleton = 0i64;
  this->mBoneNameHashIDs = 0i64;
  this->mWeightSetData = 0i64;
  this->mInverseModelSpace = 0i64;
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
  hkVector4f *p_m_scale; // rax

  v0.m_quad = (__m128)hkQsTransformf_identityStorage.m_translation;
  v1.m_vec.m_quad = (__m128)hkQsTransformf_identityStorage.m_rotation;
  v2.m_quad = (__m128)hkQsTransformf_identityStorage.m_scale;
  p_m_scale = &Skeleton::mIdentitySpace[0].m_scale;
  do
  {
    p_m_scale[-2] = (hkVector4f)v0.m_quad;
    p_m_scale[-1] = (hkVector4f)v1.m_vec.m_quad;
    *p_m_scale = (hkVector4f)v2.m_quad;
    p_m_scale += 3;
  }
  while ( (__int64)p_m_scale < (__int64)&s_uBip01_L_UpperArmUID_0 );
}

// File Line: 123
// RVA: 0x1B9440
char __fastcall Skeleton::IsParent(Skeleton *this, int parentID, int childID)
{
  hkaSkeleton *mhkaSkeleton; // r10

  if ( parentID < 0 )
    return 0;
  if ( childID < 0 )
    return 0;
  mhkaSkeleton = this->mhkaSkeleton;
  if ( !mhkaSkeleton || (childID & 0x8000u) != 0 )
    return 0;
  while ( (__int16)childID != parentID )
  {
    LOWORD(childID) = mhkaSkeleton->m_parentIndices.m_data[(__int16)childID];
    if ( (childID & 0x8000u) != 0 )
      return 0;
  }
  return 1;
}

// File Line: 145
// RVA: 0x1B9390
signed __int64 __fastcall Skeleton::GetBoneID(Skeleton *this, unsigned int boneUID)
{
  int v2; // r9d
  int v4; // r8d
  int v5; // eax
  UFG::RigResource::BoneLookupEntry *v6; // rdx

  v2 = 0;
  v4 = this->mhkaSkeleton->m_bones.m_size - 1;
  if ( v4 < 0 )
    return 0xFFFFFFFFi64;
  while ( 1 )
  {
    v5 = (v4 + v2) / 2;
    v6 = &this->mBoneIDLookup[v5];
    if ( boneUID <= v6->guid )
      break;
    v2 = v5 + 1;
LABEL_6:
    if ( v2 > v4 )
      return 0xFFFFFFFFi64;
  }
  if ( boneUID < v6->guid )
  {
    v4 = v5 - 1;
    goto LABEL_6;
  }
  return v6->index;
}

