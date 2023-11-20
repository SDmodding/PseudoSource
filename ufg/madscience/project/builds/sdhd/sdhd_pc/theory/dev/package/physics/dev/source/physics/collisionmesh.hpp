// File Line: 192
// RVA: 0xAB0D0
signed __int64 __fastcall UFG::CollisionMeshData::GetPart(UFG::CollisionMeshData *this, int index)
{
  __int64 v2; // rax
  signed __int64 result; // rax

  v2 = this->mParts.mOffset;
  if ( v2 )
    result = (signed __int64)&this->mParts + 48 * index + v2;
  else
    result = 48i64 * index;
  return result;
}

// File Line: 194
// RVA: 0xAB110
signed __int64 __fastcall UFG::CollisionMeshData::GetPartDetails(UFG::CollisionMeshData *this, int index)
{
  __int64 v2; // rax
  signed __int64 result; // rax

  v2 = this->mPartDetails.mOffset;
  if ( v2 )
    result = (signed __int64)&this->mPartDetails + 96 * index + v2;
  else
    result = 96i64 * index;
  return result;
}

