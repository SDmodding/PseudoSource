// File Line: 192
// RVA: 0xAB0D0
UFG::CollisionMeshData::Part *__fastcall UFG::CollisionMeshData::GetPart(UFG::CollisionMeshData *this, int index)
{
  __int64 mOffset; // rax

  mOffset = this->mParts.mOffset;
  if ( mOffset )
    return (UFG::CollisionMeshData::Part *)((char *)&this->mParts + 48 * index + mOffset);
  else
    return (UFG::CollisionMeshData::Part *)(48i64 * index);
}

// File Line: 194
// RVA: 0xAB110
UFG::CollisionMeshData::PartDetails *__fastcall UFG::CollisionMeshData::GetPartDetails(
        UFG::CollisionMeshData *this,
        int index)
{
  __int64 mOffset; // rax

  mOffset = this->mPartDetails.mOffset;
  if ( mOffset )
    return (UFG::CollisionMeshData::PartDetails *)((char *)&this->mPartDetails + 96 * index + mOffset);
  else
    return (UFG::CollisionMeshData::PartDetails *)(96i64 * index);
}

